# 高层 Transformer 编译与 C 驱动运行

本目录给出一套可以直接运行的软件流程：

```text
高层模型 JSON
    ↓ npu_model_compiler.py
C 配置 + CMD128 数组 + Descriptor 数组 + 权重数组
    ↓ npu_driver.h
单核 NPU cmodel
```

示例不是预先写好的指令文件。`transformer_model.json` 只描述逻辑张量、常量、
语义算子和模型输出，不填写设备地址、任务编号、事件、执行单元、硬件 opcode、
Descriptor、DMA、PACK 或字节步长。上层编译器负责 shape 推导、拓扑排序、
常量整理、L1 存储分配、算子拆分和任务依赖生成，然后调用独立汇编器生成
128-bit 指令，并把可部署内容写入 C 源文件和 C 头文件。

> [!important] 主控 CPU 与 NPU 的关系
> Generic Core 是 NPU 外部的主控 CPU，不是 NPU 内部模块。主控 CPU 作为
> AXI Master，主动调用驱动函数访问 NPU AXI Slave 的固定地址命令 FIFO、控制寄存器
> 和 L1BUF 外部窗口。NPU 内部的 MIF / TBU 另有 AXI Master 端口，用于主动
> 访问 DDR。这两类端口的用途不同。

## 模型结构

模型采用 INT16，输入 shape 为 `[4,8]`：

- token 数为 4；
- 特征数为 8；
- 注意力头数为 2，每个头处理 4 个特征；
- FFN 中间特征数为 16。

模型图依次包含：

1. 一个 `MultiHeadAttention`；
2. 第一次残差 `Add`；
3. 第一次 `LayerNorm`；
4. `8×16` 的 FFN `MatMul`；
5. `GELU`；
6. `16×8` 的 FFN `MatMul`；
7. 第二次残差 `Add`；
8. 第二次 `LayerNorm`。

`MultiHeadAttention` 会由编译器拆成 Q/K/V 投影、注意力头数据整理、
`QK^T`、Softmax、`AV`、头合并和输出投影。输入、常量和最终输出所需的 DMA
任务也由编译器添加。

## 默认部署包与检查文件

模型编译器默认生成以下部署文件：

| 文件 | 内容 |
| --- | --- |
| `transformer_model.h` | C 类型、数组声明、地址和数量常量 |
| `transformer_model.c` | C 配置、CMD128、Descriptor、权重和运行信息 |
| `transformer_model.manifest.json` | 文件大小与 SHA-256 |

通用命名规则是 `<stem>_model.h`、`<stem>_model.c` 和
`<stem>.manifest.json`。本例输入文件的 stem 已经是 `transformer_model`，
所以 C 文件名不会再次追加 `_model`。

裸 CMD、Descriptor、常量、运行信息和低层 JSON IR 不属于默认部署包。只有
显式传入 `--emit-raw` 时，编译器才额外生成：

| 文件 | 检查用途 |
| --- | --- |
| `transformer_model.npuasm.json` | 查看上层算子拆分后的低层 JSON IR |
| `transformer_model.cmd.bin` | 检查连续 CMD128 字节 |
| `transformer_model.desc.bin` | 检查 64B 对齐的 Descriptor 字节 |
| `transformer_model.const.bin` | 检查权重和函数参数字节 |
| `transformer_model.runtime.json` | 检查输入输出、提交组、任务和存储计划 |

本例的 `make check` 有意启用 `--emit-raw`，再把低层 JSON IR 交给
`npu_assembler.py` 单独汇编，并逐字节比较两条编译路径得到的 CMD128 和
Descriptor。应用部署只需编译 `transformer_model.c` 并包含
`transformer_model.h`，不需要读取这些裸文件。

示例把每个提交组限制为 8 条命令。这样一组最多形成 16 个 64-bit beat，
恰好符合命令 FIFO 的 FIXED burst 最大长度；该值也小于硬件任务表容量，不会
改变计算结果。

## C 运行程序做了什么

`transformer_runner.c` 不填写内部 L1 地址，也不整理权重。它直接使用生成
C 包中的：

- CMD128 数组与任务编号；
- 提交组；
- Descriptor 数组及其 DDR 基地址；
- 权重数组及其 DDR 基地址；
- 输入和输出 DDR 信息。

运行程序将生成的 Descriptor 与权重放入 cmodel DDR，把测试输入写到生成的
输入地址，然后按提交组执行以下步骤：

1. 把组内 1～8 条 CMD128 排成低、高 word 相邻的数组，再调用公开
   `npu_drv_submit_batch()` 发出一次 2～16 beat 的固定地址 FIXED burst；
2. 调用 `npu_drv_wait_task()` 等待任务结束；
3. 调用 `npu_drv_query_status()` 和 `npu_drv_query_raw()` 读取状态与进度；
4. 调用 `npu_drv_ack_task()` 释放任务项；
5. 全部提交组完成后，从生成的输出 DDR binding 读取结果。

测试参考程序独立使用 `expf`、`erff` 和 `sqrtf` 计算多头注意力、GELU 和两次
LayerNorm。它逐项比较 32 个 INT16 输出，同时显示每个 token 的输入、设备结果、
参考结果、类别、最大绝对误差和类别正确数。

## 已验证结果

| token | 输入 | NPU 输出 | 类别 |
| --- | --- | --- | --- |
| 0 | `[4,0,0,0,0,0,0,0]` | `[8,0,0,0,0,1,0,1]` | 0 |
| 1 | `[0,0,4,0,0,0,0,0]` | `[0,0,8,0,0,1,0,1]` | 2 |
| 2 | `[0,0,0,0,0,4,0,0]` | `[1,0,1,0,0,8,0,0]` | 5 |
| 3 | `[0,0,0,0,0,0,0,4]` | `[1,0,1,0,0,0,0,8]` | 7 |

当前模型生成 36 条 CMD128，分为 5 个提交组。运行时使用 5 次固定地址 FIXED
burst 发送 72 个 64-bit beat，并从命令响应 FIFO 取得 36 条成功响应。
GCC、Clang、ASan+UBSan 均已完成验证。

> [!note] 两类测试各自检查什么
> 本例的功能 backend 通过驱动平台回调执行与 FIXED burst 等价的批量提交，
> 用于检查低、高 word 次序、分组、响应处理和模型数值结果；它不实例化 AXI
> 信号级状态机。真实 `AW/W/B`、`AR/R` 握手、整体提交、错误 burst 丢弃和
> 反压由 CModel 的 `test_sys_slave_cycle` 与 `test_single_core_cycle` 检查。

## Keras Transformer 示例

[`../keras_transformer_e2e`](../keras_transformer_e2e/README.md) 从真实
`.keras` 模型开始，不需要手写高层 JSON。它依次完成 Keras 模型建立、前端
导入、C 部署包生成、驱动提交和 CModel 计算。

该示例的已测结果为 47 条 CMD128、6 个提交组、94 个 64-bit beat 和 47 条
成功响应。32 个输出全部不超过 2 LSB 误差，最大绝对误差为 2 LSB，4 个
token 的最大特征编号全部与 Keras 结果一致。

## 运行方法

```bash
cd "/home/yusen/Obsidian Vault/NPU/examples/transformer_e2e"
make clean
make test
```

分别使用 GCC、Clang 和 ASan+UBSan：

```bash
make regress
```

也可以使用脚本：

```bash
./compile_model.sh
./run_model.sh
```

成功时会看到：

```text
metrics exact_elements=32/32 max_abs_error=0 class_accuracy=4/4
PASS model=int16_transformer_encoder high_ops=8 commands=36 cmd_bits=128 batches=5 ...
```
