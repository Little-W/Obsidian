# NPU 模型编译器与汇编器

本目录包含两个工具和一个职责独立的产物生成模块：

- `npu_model_compiler.py` 读取高层模型图，完成图检查、形状推导、算子展开、
  张量布局、存储分配、Matrix-B 数据整理、任务依赖分析和设备任务生成；
- `model_artifacts.py` 负责生成 C 头文件、manifest、各类输出文件，以及处理
  命令行参数、JSON 文件读取、文件写入和 `--check` 逐字节检查；
- `npu_assembler.py` 读取低层 JSON IR，把已经确定的任务字段编码成 CMD128 和
  Descriptor。

简而言之，模型编译器决定“计算什么、数据放在哪里、先后关系是什么”，汇编器
负责“把已经确定的设备任务编码成二进制”。`npu_model_compiler.py` 仍是高层
编译的命令行与 Python API 主入口；产物相关代码放在独立模块中。低层 JSON IR
是两个阶段之间可以检查、保存和重复汇编的中间文件。

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

当前整数类型包括 INT4、INT8、INT16 和 INT32。常量的 `data` 使用普通行主序，
Matrix 权重无需由用户提前整理。

## 2. 编译流程

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

模型输出是 DDR binding。C 程序从生成的运行元数据读取输入和输出地址、形状、
类型和字节数，不需要知道内部 L1 地址。

## 3. 支持的模型算子

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

## 4. MultiHeadAttention

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

## 5. Conv2D：im2col + GEMM

硬件没有单独的卷积 opcode。高层 `Conv2D` 使用 NHWC 输入，kernel 使用
`[KH, KW, Cin, Cout]`，当前支持 `groups=1`。stride、dilation、`VALID`、
`SAME` 和显式 padding 均由编译器计算。

编译器先推导：

```text
M = N × OH × OW
K = KH × KW × Cin
```

然后生成形状为 `[M, K]` 的 im2col 张量。存在 padding 时，先用 DMA FILL
把 im2col 清零；随后针对每个 kernel tap 生成 COPY_ND，把有效的
`[N, OH, OW, Cin]` 数据写入对应列。kernel 常量在编译时从
`[KH, KW, Cin, Cout]` 重新解释为 `[K, Cout]`，再整理为 Matrix-B tile
存储顺序。最后一条 GEMM 直接产生按 NHWC 线性保存的输出。

因此，生成的低层 JSON IR 中不会出现不存在的卷积 opcode，只包含 DMA 和
Matrix 任务。

## 6. 生成文件

假设高层输入名为 `model.json`，模型编译阶段生成：

| 文件 | 内容 |
|---|---|
| `model.npuasm.json` | 自动生成的低层 JSON IR |
| `model.cmd.bin` | CMD128 数组，每条 16 字节 |
| `model.desc.bin` | 64 字节对齐的 Descriptor 连续区 |
| `model.manifest.json` | 命令、事件、地址、文件摘要和内存计划 |
| `model.runtime.json` | 输入、输出、常量和运行时装载信息 |
| `model.const.bin` | 已整理的常量 DDR 镜像 |
| `model.npu.h` | 可选 C 头文件，包含二进制数据和运行元数据 |

`model.npu.h` 至少提供 Descriptor 起始地址、命令数量、每条命令的
`command_id`、输入和输出 binding、常量镜像及所需 DDR/L1 大小。C runner
应读取这些生成内容，不应再次写死模型内部地址或事件。

## 7. 运行命令

高层模型编译：

```bash
cd "/home/yusen/Obsidian Vault/NPU/compiler"
python3 npu_model_compiler.py model.json \
  --output-dir build/model \
  --emit-c-header
```

只使用低层汇编器：

```bash
python3 npu_assembler.py examples/int16_regression.json \
  --output-dir build/int16-regression \
  --emit-c-header
python3 npu_assembler.py examples/int16_regression.json \
  --output-dir build/int16-regression \
  --emit-c-header \
  --check
```

运行全部测试：

```bash
python3 -m unittest discover -s tests -v
```

`--check` 不写文件，而是重新生成内容并逐字节检查已有结果。

## 8. 低层 JSON IR 与 CMD128

低层 JSON IR 可以填写执行单元、opcode、张量地址、Descriptor 字段和任务依赖。
它面向模型编译器后端、测试程序以及需要精确控制设备任务的开发者，不是普通
模型输入格式。

汇编器生成的 CMD128 由两个 64-bit beat 组成。主总线先发送 low，随后发送
high：

- `low[47:0]`：Descriptor 地址；
- `low[59:48]`：`command_id`；
- `low[63:60]`：执行单元；
- `high[7:0]`：opcode；
- `high[19:8]`：任务属性；
- `high[31:20]`、`high[43:32]`：两个等待事件；
- `high[55:44]`：完成事件；
- `high[63:56]`：格式版本。

低层示例 `examples/int16_regression.json` 展示 INT16 输入搬运和 INT16 权重
GEMM。它用于汇编器字段测试，不是高层模型示例。

## 9. Transformer 端到端测试

`../examples/transformer_e2e/transformer_model.json` 给出一个完整的 INT16
Transformer Encoder。高层图包括多头注意力、两次残差加法、两次
LayerNorm，以及带 GELU 的两层 FFN。它不填写设备地址、事件或低层指令。

```bash
cd "/home/yusen/Obsidian Vault/NPU/examples/transformer_e2e"
make clean
make test
```

该命令依次完成高层编译、低层独立汇编结果比较、C 驱动构建和 C model 推理。
当前模型由 8 个高层节点生成 36 条 CMD128，并按 8 条任务一组拆成 5 个提交组。
C 程序对每条命令执行 submit、wait、query 和 ACK，最后从生成的 DDR 输出
binding 读取 4×8 个 INT16 结果。

独立浮点参考程序计算相同的多头注意力、GELU 和 LayerNorm。当前结果为 32/32
个输出元素相同，最大绝对误差为 0，4 个 token 的最大值位置均相同。运行
GCC、Clang 和 ASan+UBSan 的完整测试：

```bash
make regress
```
