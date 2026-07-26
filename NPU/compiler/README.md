# NPU 模型编译器与 CMD128 汇编器

本目录包含两个层次：

- `npu_model_compiler.py` 接收 Keras、PyTorch、TFLite、ONNX 或高层 JSON 模型，完成图检查、整数张量处理、常量排布、L1 地址分配、算子拆分和任务依赖生成。
- `npu_assembler.py` 接收低层 JSON IR，把每个任务编码成一条 CMD128 inline V2 指令。

“低层 JSON IR”是保留名称。它描述已经选定执行单元、操作码、张量地址和任务事件的程序。V2 不读取外部 Descriptor；执行参数都在 128-bit 指令中。

## 1. 编译结果

默认输出可直接加入 C 工程：

| 文件 | 内容 |
|---|---|
| `<model>_model.h` | C 类型、数组声明、模型配置和尺寸宏 |
| `<model>_model.c` | CMD128 指令数组、权重/常量数组、输入输出信息和批次信息 |
| `<model>.manifest.json` | 输入摘要、文件摘要、算子列表和指令批次 |

使用 `--emit-raw` 后还会输出：

| 文件 | 内容 |
|---|---|
| `<model>.npuasm.json` | 低层 JSON IR |
| `<model>.cmd.bin` | 每条 16 byte 的 CMD128 数据 |
| `<model>.const.bin` | 权重和常量数据 |
| `<model>.runtime.json` | 运行时张量、地址、指令批次和内存计划 |

编译器不生成 `.desc.bin`，C 包也没有 Descriptor 数组、Descriptor 地址或 Descriptor 字节数字段。

生成的模型配置包含：

- `commands` 与 `command_count`；
- `weights`、`weight_bytes`、`weight_base_ddr`、`weight_base_l1`；
- 输入和输出的名称、DDR 地址、L1 地址、字节数、数据类型、维数及各维长度；
- 低层操作列表；
- 每次 FIXED burst 应提交的 command ID 列表；
- 每个批次的 `host_sync_before`、`host_sync_after` 和
  `contains_event_rearm` 标志。

## 2. CMD128 inline V2 公共字段

| bit | 字段 | 说明 |
|---:|---|---|
| 127 | `inline_v2` | 固定为 1 |
| 126:122 | `compact_opcode` | 5-bit 操作码 |
| 121:112 | `command_id` | 10-bit，范围 0～1023 |
| 111:104 | `wait_event0` | 等待事件 ID，`0xFF` 表示不等待 |
| 103:96 | `wait_event1` | 第二个等待事件 ID |
| 95:88 | `signal_event` | 完成后更新的事件 ID |
| 87 | `irq_success` | 成功时请求中断 |
| 86 | `irq_error` | 失败时请求中断 |
| 85 | `strict_numeric` | 复杂数学单元使用严格数值检查 |
| 84 | `ordered` | 要求按程序顺序处理 |
| 83:82 | `timeout_class` | 选择 4 组超时寄存器之一 |
| 81:80 | `dtype` | `0=int4`、`1=int8`、`2=int32`、`3=int16` |
| 79:0 | `payload` | 当前操作的全部执行参数 |

事件字段只保存 8-bit ID，不保存 generation。`EVENT_REARM` 把待重置的事件 ID 放在 `signal_event` 中，两个等待字段均为 `0xFF`；Event Table 在硬件内部更新 generation。

直接提交低层 JSON IR 时，软件必须先确认该 Event ID 的旧生产者和全部等待者
已经结束，再提交 `EVENT_REARM`；还要等 `EVENT_REARM` 完成后才能提交使用同一
ID 的新生产者。高层编译器会生成满足这一顺序要求的批次信息。

## 3. 5-bit 操作码

| 编码 | 名称 | 编码 | 名称 |
|---:|---|---:|---|
| 0 | NOP | 16 | VSUB |
| 1 | EVENT_SIGNAL | 17 | VMUL |
| 2 | EVENT_REARM | 18 | VFMA |
| 3 | EVENT_JOIN | 19 | VMAX |
| 4 | GLOBAL_FENCE | 20 | VMIN |
| 5 | DMA_COPY_1D | 21 | VCMP |
| 6 | DMA_COPY_ND | 22 | VSELECT |
| 7 | DMA_FILL | 23 | VCLAMP |
| 8 | DMA_TRANSPOSE_2D | 24 | VRELU |
| 9 | DMA_PACK | 25 | VACT |
| 10 | DMA_SPLIT | 26 | VSOFTMAX |
| 11 | GEMM | 27 | VNORM |
| 12 | BMM | 28 | VROPE（P1） |
| 13 | GEMM_ACCUM | 29 | VSTAT |
| 14 | GEMM_ZERO | 30 | VRECIP（P1） |
| 15 | VADD | 31 | VADD_RESCALE |

P1 功能位关闭时，VROPE 和 VRECIP 可以被编码和提交，但设备返回 `ILLEGAL_OPCODE`。保留这两个编码可使指令文件在启用 P1 后继续使用。

## 4. 地址压缩

### 4.1 AREF28

DMA 使用 28-bit 地址引用：

```text
[27]       space       0=L1，1=系统地址
[26:24]   base_select
[23:0]    byte_offset
```

L1 地址要求 `base_select=0`。系统地址的基地址编号为：

| 编号 | 基地址 |
|---:|---|
| 0 | zero |
| 1 | input |
| 2 | weight |
| 3 | work |
| 4 | output |
| 5 | kv |

实际地址等于所选基地址加 `byte_offset`。当前高层编译器在默认 2 MiB DDR 配置中使用 zero 基地址，因此无需额外修正地址。

### 4.2 LREF12、LREF14 与 LREF16

- 矩阵单元使用 LREF14，数值单位为 64 byte，可表示约 1 MiB L1 地址范围。
- 矩阵偏置使用 LREF12，数值单位为 64 byte，可表示 256 KiB L1 地址范围。
- 向量和复杂数学单元使用 LREF16，数值单位为 16 byte，也可表示约 1 MiB L1 地址范围。
- 矩阵偏置引用值 0 表示没有偏置；L1 分配器从非零地址开始。

## 5. 各类 payload

### 5.1 DMA

COPY 指令：

```text
[79:52] src_aref
[51:24] dst_aref
[23:4]  element_count
[3:2]   dst_dtype
[1]     src_nibble
[0]     dst_nibble
```

`DMA_COPY_ND` 在 V2 中表示连续张量的扁平复制。高层编译器遇到带行间隔的数据时，会按行生成多条 `DMA_COPY_1D`；汇编器若直接收到不连续的 COPY_ND，会给出错误。

FILL 指令使用 `[79:52]` 保存目标地址、`[51:32]` 保存元素数、`[31:0]` 保存填充值。

TRANSPOSE 指令使用两个 AREF28，并在低 24 bit 保存 8-bit 行数、8-bit 列数、目标数据类型和 INT4 nibble 信息。行数和列数均为 1～255。

PACK/SPLIT 使用两个 AREF28，并保存 8-bit `segment_count`、`segment_bytes` 和 `segment_stride`。

### 5.2 矩阵

GEMM、GEMM_ACCUM 和 GEMM_ZERO：

```text
[79:66] A_lref14
[65:52] B_lref14
[51:38] C_lref14
[37:26] bias_lref12
[25:20] M-1
[19:14] N-1
[13:8]  K-1
[7]     b_int4
[6:5]   C dtype
[4:0]   requant_shift
```

BMM：

```text
[79:66] A_lref14
[65:52] B_lref14
[51:38] C_lref14
[37:32] batch-1
[31:26] M-1
[25:20] N-1
[19:14] K-1
[13]    b_int4
[12:11] C dtype
[10:6] requant_shift
[5:0]  保留为 0
```

三个矩阵地址使用 64-byte 单位。偏置也使用 64-byte 单位，但字段宽度为
12 bit，因此偏置必须位于 L1 的非零地址且低于 256 KiB；偏置引用值 0
明确表示“不加偏置”。偏置元素的数据类型为 INT32。对输出通道
$o=0,1,\ldots,N-1$，`bias[o]` 会加到该通道在全部 M 行中的结果上。
例如 `M=2、N=3` 时，偏置形状是 `[3]`，计算结果分别为
`C[0,0..2] += bias[0..2]` 和 `C[1,0..2] += bias[0..2]`。

M、N、K 以及 BMM batch 的范围均为 1～64。B 矩阵必须按
`KT × NT` tile 排列。`requant_shift` 直接保存 0～31，不再使用少数几个
预设值；例如 Q5 模型可直接保存 5。C 为 INT32 时该字段必须为 0。

`b_int4=1` 只表示“A 为 INT8、B 为 INT4”。其他组合要求 A、B 数据类型
相同，并把该位写成 0。GEMM_ZERO 的 A、B、bias、K、`b_int4` 和
`requant_shift` 字段均为 0。

### 5.3 向量

```text
[79:64] src0_lref16
[63:48] src1_lref16
[47:32] src2_lref16 / compare / clamp
[31:16] dst_lref16
[15:11] rows-1
[10:6]  length-1
[5:4]   broadcast0
[3:2]   broadcast1
[1:0]   broadcast2
```

行数和每行元素数均为 1～32。`VCMP` 在 src2 字段的高 3 bit 保存比较方式，并输出 INT8 mask。`VSELECT` 的 src2 字段保存 mask 地址。`VCLAMP` 把 src1/src2 字段解释为两个 signed 16-bit 立即数。

标量加法由高层编译器改写为“L1 标量张量 + scalar broadcast”，因此不需要把标量数值塞入额外参数区。

### 5.4 复杂数学

```text
[79:64] src0_lref16
[63:48] aux_lref16
[47:32] dst_lref16
[31:27] rows-1
[26:19] length-1
[18:0]  function metadata
```

行数为 1～32，每行元素数为 1～256。ACT、SOFTMAX、NORM 和 ADD_RESCALE 的比例参数必须是 `2^e`，其中 `e` 为 -8～7。NORM 的 epsilon 可选 `1e-5`、`1e-6`、`1e-3`、`1e-4`。

LayerNorm 的 gamma 地址按 16 byte 保存。beta 必须位于 gamma 数据之后的下一个 64-byte 对齐地址。例如 gamma 是 16 个 INT16，共 32 byte，gamma 位于 `0x2000` 时，beta 应位于 `0x2040`。

## 6. 高层编译器处理规则

- 连续 COPY_ND 可直接编码；带行间隔的复制按最内层连续行拆为 COPY_1D。
- 矩阵尺寸超过 64 时当前版本报告清晰错误。后续可增加 M/N/K 分块，其中 K 分块还需要 GEMM_ZERO、GEMM_ACCUM 和最终输出阶段。
- 向量行数或每行元素数超过 32 时当前版本报告限制条件。
- SOFTMAX、NORM 等操作不能沿每行元素方向任意拆开；每行元素数超过 256 时报告限制条件。
- INT4 的行首和输出 nibble 必须满足硬件字段要求。
- 复杂数学单元的比例字段保存 `2^e`，其中 `e` 为 -8～7。注意力分数若
  需要 $1/\sqrt{d}$ 这类非 2 的整数次幂，编译器会显式生成
  `FILL → VMUL → VADD_RESCALE → VSOFTMAX`。整数系数和 SOFTMAX 比例的
  组合误差必须低于 1%，否则编译停止。例如
  $1/\sqrt{8}\approx0.353553$ 使用 `91/128` 预缩放和 `1/2` 的
  SOFTMAX 比例，合成比例为 `91/256≈0.355469`。
- 前端默认 `fraction_bits=6`。矩阵的 5-bit `requant_shift` 可直接保存
  0～31，因此 Q5、Q6 和 Q8 模型都不需要改成其他小数位数。
- 同时处于使用期的依赖事件最多为 255 个。任务数超过 255 时，编译器按
  事件的最后一个使用者释放 Event ID，并在再次使用前插入
  `EVENT_REARM`。
- 含 `EVENT_REARM` 的指令被放入独立批次。该批次的
  `host_sync_before=1` 和 `host_sync_after=1`，运行时必须先等上一批任务
  完成并确认，再提交重置事件的批次；完成该批次后才能提交新的生产者。

这些检查的目的，是避免生成字段齐全但计算含义已经改变的指令。

## 7. 使用方法

### 7.1 编译框架模型

```bash
conda run -n tf_2_18 python NPU/compiler/npu_model_compiler.py \
  model.keras \
  --output-dir build/model \
  --model-dtype int8 \
  --fraction-bits 5
```

PyTorch 文件需要显式确认文件可信：

```bash
conda run -n tf_2_18 python NPU/compiler/npu_model_compiler.py \
  model.torchscript \
  --output-dir build/model \
  --trust-model \
  --pytorch-format torchscript \
  --input-shape 0=1,16
```

支持的输入格式选项为 `json`、`keras`、`pytorch`、`tflite` 和 `onnx`。`auto` 根据文件后缀选择。

### 7.2 汇编低层 JSON IR

```bash
python3 NPU/compiler/npu_assembler.py \
  NPU/compiler/examples/int8_regression.json \
  --output-dir /tmp/npu-int8 \
  --emit-c-header
```

### 7.3 检查已有结果

```bash
python3 NPU/compiler/npu_model_compiler.py \
  model.json \
  --output-dir build/model \
  --check
```

`--check` 重新编译并逐字节比较，不修改已有文件。

## 8. 测试

普通环境：

```bash
python3 -m unittest discover -s NPU/compiler/tests -v
```

Keras、TFLite、PyTorch 和 ONNX 全部前端：

```bash
conda run -n tf_2_18 python -m unittest discover \
  -s NPU/compiler/tests -v
```

测试包含 INT4、INT8、INT16、INT32 张量检查、各 payload 位段逐位检查、事件 ID、P1 操作码保留、COPY_ND 拆分、生成 C 文件编译、文件稳定性和真实框架模型导入。
