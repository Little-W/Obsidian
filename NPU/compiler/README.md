# NPU 模型编译器与汇编器

本目录包含两个工具和一个职责独立的产物生成模块：

- `npu_model_compiler.py` 读取高层模型图，完成图检查、形状推导、算子展开、
  张量布局、存储分配、Matrix-B 数据整理、任务依赖分析和设备任务生成；
- `model_artifacts.py` 默认生成可直接加入 C 工程的模型头文件、模型源文件和
  manifest，并负责命令行参数、JSON 文件读取、文件写入和 `--check`
  逐字节检查；
- `npu_assembler.py` 读取低层 JSON IR，把已经确定的任务字段编码成 CMD128 和
  Descriptor。

简而言之，模型编译器决定“计算什么、数据放在哪里、先后关系是什么”，汇编器
负责“把已经确定的设备任务编码成二进制”。`npu_model_compiler.py` 仍是高层
编译的命令行与 Python API 主入口；产物相关代码放在独立模块中。低层 JSON IR
是两个阶段之间可以检查、保存和重复汇编的中间文件。

模型编译器的默认交付物不是若干裸二进制文件，而是一组 C 模型包：
`<stem>_model.h` 声明配置结构体和数组，`<stem>_model.c` 定义 CMD128、
Descriptor、权重以及运行元数据。主控程序把这两个文件和 NPU 驱动一起编译，
再按模型配置装载数据、分组提交命令和读取输出。需要检查编码细节时，可以使用
`--emit-raw` 额外生成低层 JSON IR 与裸数据文件。

## 1. 高层模型图

高层输入只描述模型语义。以下示例表示一次 INT16 矩阵乘法：

```json
{
  "schema_version": 1,
  "model": {"name": "linear_demo"},
  "inputs": [
    {"name": "x", "shape": [2, 4], "dtype": "int16"}
  ],
  "constants": [
    {
      "name": "weight",
      "shape": [4, 3],
      "dtype": "int16",
      "data": [1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1]
    }
  ],
  "tensors": [
    {"name": "y", "shape": [2, 3], "dtype": "int16"}
  ],
  "operators": [
    {
      "name": "projection",
      "type": "MatMul",
      "inputs": ["x", "weight"],
      "outputs": ["y"]
    }
  ],
  "outputs": ["y"]
}
```

模型文件不填写下列设备细节：

- DDR 或 L1 地址；
- Descriptor 地址；
- `command_id`；
- 等待事件和完成事件；
- 执行单元、opcode 和 Descriptor 字段；
- DMA、PACK、SPLIT 或 stride 等低层搬运任务。

这些内容均由模型编译器生成。这样，模型作者可以围绕张量和模型算子编写文件，
而不需要手工维护地址和任务编号。

模型张量支持 INT4、INT8、INT16 和 INT32。常量的 `data` 使用普通行主序，
Matrix 权重无需由用户提前整理。

## 2. 直接读取 Keras、PyTorch、TFLite 与 ONNX

`npu_model_compiler.py` 可以直接读取以下文件：

| 文件 | 读取方式 |
|---|---|
| `.keras`、`.h5`、`.hdf5` | Keras 3 安全加载；普通模型先在内存中转为 TFLite，标准 Transformer Encoder 直接保留多头注意力等高层节点 |
| `.tflite` | 读取 FlatBuffer、常量、张量形状、scale 和 zero point |
| `.onnx` | 检查模型并执行静态形状推导，再生成编译器高层图 |
| `.pt`、`.pth`、`.ts`、`.torchscript` | 只接受 TorchScript；先导出 ONNX，再使用同一 ONNX 前端 |
| `.pt2` | 读取 `torch.export` 的 ExportedProgram，导出 ONNX 后继续编译 |
| `.json` | 读取本目录定义的高层模型图 |

文件后缀不明确时可用 `--input-format` 指定类型。动态首维默认取
`--batch-size 1`；其他动态维度必须用可重复的
`--input-shape NAME=D0,D1,...` 提供静态数值。

框架通常保存 FP32 参数，而 NPU 张量只使用整数。前端按

```text
integer = round(real_value / 2^(-fraction_bits))
```

把参数编码成 `--model-dtype` 指定的 INT4、INT8 或 INT16，并检查每个数是否
能由目标整数类型保存。建议默认使用 INT8；小数位数由模型的数值范围确定。
例如设置 6 个小数位时，scale 为 `2^-6 = 1/64`。INT16 可使用
`--model-dtype int16 --fraction-bits 8`，对应 scale `1/256`。超出整数范围、
NaN 或无穷值都会得到明确错误，不会静默截断。INT32 用于 Matrix 累加、bias
及需要较大数值范围的中间张量，不作为框架 FP32 参数的直接编码目标。

当前框架前端采用“明确支持集合”：

- TFLite：FullyConnected、Add、ReLU、GELU、Logistic、Tanh、Softmax、
  Reshape、二维 Transpose、末维 Concat 和 NHWC Conv2D；
- ONNX：MatMul、Gemm、Add、ReLU、GELU、Sigmoid、Tanh、SiLU、Softmax、
  常用形状调整节点、二维 Transpose、末维 Concat 和最后一维
  LayerNormalization；
- Keras：上述可经 TFLite 表达的普通模型，以及 Batch=1、静态
  `[1, token 数, 特征数]` 的标准 Transformer Encoder；
- PyTorch：能够导出到上述 ONNX 支持集合的 TorchScript 或 ExportedProgram。

标准 Keras Transformer 路径支持 MultiHeadAttention、残差 Add、
LayerNormalization、Dense、GELU 和推理阶段的 Dropout。当前要求自注意力、
`num_heads × key_dim = 特征数`、`num_heads × value_dim = 特征数`，并且注意力
投影不含 bias。未满足这些限制时，编译器会指出具体层和不受支持的属性。

> [!warning] PyTorch 文件安全
> PyTorch 反序列化可能执行文件中的代码，因此必须显式传入
> `--trust-model`，并且只能读取来源可信的模型。只包含参数的 `state_dict`
> 没有可执行计算图，不能直接编译；应先用模型类恢复网络，再导出
> TorchScript 或 `.pt2`。

`tf_2_18` 环境使用 PyTorch 2.5.1 的 CUDA 12.4 构建。该构建既可在 CPU 上
完成模型导出，也可在 NVIDIA 驱动可用时使用 GPU。编译器本身把示例输入放在
CPU 上执行 ONNX 导出，所以模型编译不依赖 GPU 是否当前可见。

## 3. 编译流程

一次高层编译包含以下步骤：

1. 检查字段、名字、整数类型和常量元素个数；
2. 根据张量生产关系计算稳定的拓扑顺序，并拒绝带环的图；
3. 推导每个输出张量的形状和类型，并检查用户给出的声明；
4. 展开复合算子；
5. 为输入、输出、常量、临时张量及 Matrix-B tile 数据安排存储；
6. 把行主序常量整理成设备读取格式；
7. 生成输入 DDR→L1 和输出 L1→DDR 任务；
8. 根据数据读写关系生成事件；直接前驱超过两个时自动生成事件合并任务；
9. 生成低层 JSON IR，并调用 `npu_assembler.py`；
10. 检查 Descriptor 区、常量区和运行时 DDR 数据区互不重叠。
11. 把 CMD128、Descriptor、权重、输入输出信息和命令分组写入 C 模型包。

模型输出是 DDR binding。C 程序从生成的运行元数据读取输入和输出地址、形状、
类型和字节数，不需要知道内部 L1 地址。

这里的软件与硬件有明确分工：

- 编译器软件负责识别高层算子、推导形状、整理权重、拆分复合计算、安排 DMA
  与 Matrix/Vector/Complex 任务，并生成 C 模型包；
- 主控软件负责调用驱动函数、装载 Descriptor 与权重、写入输入、按命令分组
  提交任务、等待完成并读取输出；
- NPU 硬件只执行已经定义的 CMD128 操作，不直接理解 Keras、PyTorch 或
  `Conv2D` 这类高层节点；
- 某个高层节点无法用现有设备任务表达时，编译器应给出清晰错误，或由上层部署
  软件安排 CPU 函数。不能把未知节点当作已经由 NPU 支持。

## 4. 支持的模型算子

高层编译器支持以下节点：

- `MatMul`；
- `Add`；
- `Softmax`；
- `LayerNorm`；
- `GELU`；
- `Reshape`；
- `Transpose`；
- `Concat`；
- `MultiHeadAttention`；
- `Conv2D`。

`BMM` 是低层 Matrix opcode，仅由 `MultiHeadAttention` 展开时生成；当前高层
模型输入不接受 `BatchedMatMul` 节点。

Matrix-B 使用硬件要求的 tile 存储顺序。常量权重在编译时直接整理；运行时产生
的 Matrix-B 张量由编译器生成填零和分 tile 搬运任务。Descriptor 中的
`m`、`n`、`k`、tile 尾部有效元素数、批处理步长及整数重缩放表均由编译器填写。

## 5. MultiHeadAttention

一个高层 `MultiHeadAttention` 节点的输入为：

```json
{
  "name": "self_attention",
  "type": "MultiHeadAttention",
  "inputs": ["x", "wq", "wk", "wv", "wo"],
  "outputs": ["attention_output"],
  "attributes": {
    "num_heads": 2,
    "softmax_output_scale": 0.25
  }
}
```

模型文件只给出输入、四组普通行主序权重和头数。编译器自动生成：

1. Q、K、V 三次投影；
2. Q 的 Head 分离；
3. K 的 Head 分离与转置；
4. V 的 Head 分离；
5. `QK^T` 批矩阵乘法；
6. Softmax；
7. `Attention × V` 批矩阵乘法；
8. Head 合并；
9. 输出投影。

每个内部张量的地址、每条任务的编号和事件都保存在生成结果中，不写入高层模型
文件。

## 6. Conv2D：编译时软件展开为 im2col + GEMM

硬件没有单独的卷积 opcode，因此不能把一个 `Conv2D` 节点原样交给 NPU。
高层 `Conv2D` 使用 NHWC 输入，kernel 使用 `[KH, KW, Cin, Cout]`，当前支持
`groups=1`。stride、dilation、`VALID`、`SAME` 和显式 padding 均由编译器
软件计算。

编译器先推导：

```text
M = N × OH × OW
K = KH × KW × Cin
```

然后生成形状为 `[M, K]` 的 im2col 张量。存在 padding 时，编译器先生成一条
DMA FILL 任务，用于把 im2col 清零；随后针对每个 kernel tap 生成 COPY_ND
任务，把有效的 `[N, OH, OW, Cin]` 数据写入对应列。kernel 常量在编译时从
`[KH, KW, Cin, Cout]` 重新解释为 `[K, Cout]`，再整理为 Matrix-B tile
存储顺序。最后生成 GEMM 任务，产生按 NHWC 线性保存的输出。

因此，生成的低层 JSON IR 中不会出现不存在的卷积 opcode，只包含 DMA 和
Matrix 任务。这个例子也说明了为什么模型编译结果需要包含 C 配置，而不能只有
一串孤立指令：高层节点的拆分、数据地址、权重格式、任务分组和主控调用方式都
由软件生成并交给驱动使用。

## 7. 生成文件

假设高层输入名为 `model.json`，默认生成以下部署文件：

| 文件 | 内容 |
|---|---|
| `model_model.h` | C 类型、尺寸宏、配置结构体和所有数组的 `extern` 声明 |
| `model_model.c` | CMD128、Descriptor、权重、输入输出、命令信息和配置实例 |
| `model.manifest.json` | 源文件摘要、C 文件摘要、命令数量、数据长度和命令分组 |

`model_model.h` 声明以下主要内容：

- `model_model_cmd128_t`：一条 128-bit 指令，由 `low` 和 `high` 两个
  `uint64_t` 组成；
- `model_model_binding_t`：一个输入或输出的名字、DDR 地址、L1 地址、字节数、
  整数类型和形状；
- `model_model_command_batch_t`：一组命令在命令编号表中的起始位置和数量；
- `model_model_config_t`：模型名、指令、Descriptor、权重、输入、输出、
  设备任务和命令分组的统一入口；
- `model_model_commands`、`model_model_descriptors`、
  `model_model_weights`：分别保存指令、Descriptor 和权重数据；
- `model_model_inputs`、`model_model_outputs`：主控软件需要读写的模型接口；
- `model_model_command_batches`、`model_model_batch_command_ids`：驱动提交顺序。

CMD128 数组按 16 字节对齐，Descriptor 按 64 字节对齐，权重按 256 字节对齐。
头文件同时给出逻辑长度和存储长度。例如某个模型没有权重时，
`WEIGHT_BYTES` 为 0，但 C 数组仍保留一个占位字节。这样不会生成非标准的
零长度数组，主控程序只使用逻辑长度，不会装载占位字节。

使用 `--emit-raw` 后，还会额外生成调试文件：

| 文件 | 内容 |
|---|---|
| `model.npuasm.json` | 自动生成的低层 JSON IR |
| `model.cmd.bin` | CMD128 原始字节，每条 16 字节 |
| `model.desc.bin` | Descriptor 原始连续数据 |
| `model.const.bin` | 已整理的权重和编译器常量数据 |
| `model.runtime.json` | 输入、输出、地址和运行时装载信息 |

裸数据用于编译器检查、汇编结果比对和问题定位，不是默认部署接口。

### 7.1 主控程序如何使用 C 模型包

下列伪代码说明调用顺序。具体函数名以驱动库为准：

```c
#include "model_model.h"
#include "npu_driver.h"

const model_model_config_t *model = &model_model_config;

npu_load_descriptors(model->descriptor_base,
                     model->descriptors,
                     model->descriptor_bytes);
npu_load_weights(model->weight_base_ddr,
                 model->weights,
                 model->weight_bytes);
npu_write_tensor(&model->inputs[0], input_data);

for (uint32_t group = 0; group < model->command_batch_count; ++group) {
    const model_model_command_batch_t *batch =
        &model->command_batches[group];
    npu_drv_cmd128_t
        commands[NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    npu_drv_submit_result_t
        results[NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    npu_drv_submit_batch_result_t batch_result;

    for (uint32_t i = 0; i < batch->command_count; ++i) {
        uint16_t command_id =
            model->batch_command_ids[batch->command_id_offset + i];
        commands[i].lo = model->commands[command_id].lo;
        commands[i].hi = model->commands[command_id].hi;
    }
    if (npu_drv_submit_batch(
            &driver, commands, batch->command_count,
            model->descriptors, model->descriptor_bytes,
            results, &batch_result) != NPU_DRV_OK) {
        handle_submit_error(&batch_result, results);
        break;
    }
    npu_wait_group();
}

npu_read_tensor(&model->outputs[0], output_data);
```

主控 CPU 发起这些驱动调用。NPU 的命令接收端和控制寄存器是总线从设备接口；
需要读取 DDR 时，NPU 的内存访问单元再作为总线主设备发起请求。C 模型包保存
部署所需的静态数据，驱动负责实际的寄存器访问和数据传输。

编译器保证每个 `command_batch` 最多包含 8 条 CMD128。驱动把它们排成
`low0, high0, low1, high1, ...`，向固定地址 `0x020000` 发出 2～16 beat
的 AXI FIXED burst。burst 的写响应成功后，驱动还要从 `0x020008` 逐项读取
命令接收响应；只检查 AXI 写响应不足以确认每条 CMD 已被 CFE 接受。

## 8. 运行命令

高层模型编译：

```bash
cd "/home/yusen/Obsidian Vault/NPU/compiler"
conda run -n tf_2_18 python npu_model_compiler.py model.json \
  --output-dir build/model
```

直接编译 Keras：

```bash
conda run -n tf_2_18 python npu_model_compiler.py encoder.keras \
  --output-dir build/keras-encoder \
  --model-dtype int16 \
  --fraction-bits 8
```

直接编译 TFLite 或 ONNX：

```bash
conda run -n tf_2_18 python npu_model_compiler.py model.tflite \
  --output-dir build/tflite-model \
  --model-dtype int8 \
  --fraction-bits 6

conda run -n tf_2_18 python npu_model_compiler.py model.onnx \
  --output-dir build/onnx-model \
  --model-dtype int16 \
  --fraction-bits 8
```

直接编译来源可信的 PyTorch TorchScript：

```bash
conda run -n tf_2_18 python npu_model_compiler.py model.torchscript \
  --output-dir build/torch-model \
  --trust-model \
  --pytorch-format torchscript \
  --input-shape 0=1,3 \
  --model-dtype int8 \
  --fraction-bits 6
```

同时生成调试文件：

```bash
conda run -n tf_2_18 python npu_model_compiler.py model.json \
  --output-dir build/model \
  --emit-raw
```

只使用低层汇编器：

```bash
conda run -n tf_2_18 python npu_assembler.py examples/int16_regression.json \
  --output-dir build/int16-regression \
  --emit-c-header
conda run -n tf_2_18 python npu_assembler.py examples/int16_regression.json \
  --output-dir build/int16-regression \
  --emit-c-header \
  --check
```

运行全部测试：

```bash
conda run -n tf_2_18 python -m unittest discover -s tests -v
```

`--check` 不写文件，而是重新生成内容并逐字节检查已有结果。默认检查 C 模型包
与 manifest；和 `--emit-raw` 同时使用时，也检查全部调试文件。

## 9. 低层 JSON IR 与 CMD128

低层 JSON IR 可以填写执行单元、opcode、张量地址、Descriptor 字段和任务依赖。
它面向模型编译器后端、测试程序以及需要精确控制设备任务的开发者，不是普通
模型输入格式。

汇编器生成的 CMD128 由两个 64-bit beat 组成。主控 CPU 是命令发起方，NPU
命令端口是总线从设备接口；传输时先写入 low，随后写入 high：

- `low[47:0]`：Descriptor 地址；
- `low[59:48]`：`command_id`；
- `low[63:60]`：执行单元；
- `high[7:0]`：opcode；
- `high[19:8]`：任务属性；
- `high[31:20]`、`high[43:32]`：两个等待事件；
- `high[55:44]`：完成事件；
- `high[63:56]`：格式版本。

dtype 子字段的有效编码为 `0=INT4`、`1=INT8`、`2=INT32`、`3=INT16`。
INT16 按小端序保存；Matrix 的 INT16 线性布局使用 pack code 5，
KT×NT 的 Matrix-B tile 布局使用 pack code 6。汇编器会检查这两个 layout
code 是否与张量 dtype 一致。

## 10. Transformer 端到端测试

`examples/int16_regression.json` 用于检查 INT16 的 DMA、GEMM、dtype code 与
Matrix pack code。`../cmodel/examples/transformer` 是独立的 INT8 端到端示例；
它采用 INT8，不影响编译器对 INT16 的支持。
