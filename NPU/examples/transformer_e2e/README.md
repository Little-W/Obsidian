# 高层 Transformer 编译与 C 驱动运行

本目录给出一条可执行的软件流程：

```text
高层模型 JSON
    ↓ npu_model_compiler.py
低层 NPU 汇编 JSON
    ↓ npu_assembler.py
CMD128 + Descriptor + 常量镜像 + 运行元数据
    ↓ npu_driver.h
单核 NPU cmodel
```

示例不是预先写好的指令文件。`transformer_model.json` 只描述逻辑张量、常量、
语义算子和模型输出，不填写设备地址、任务编号、事件、执行单元、硬件 opcode、
Descriptor、DMA、PACK 或字节步长。上层编译器负责 shape 推导、拓扑排序、
常量整理、L1 存储分配、算子拆分和任务依赖生成，然后调用独立汇编器生成
128-bit 指令。

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

## 生成文件

执行编译后，`build/generated` 包含：

| 文件 | 内容 |
| --- | --- |
| `transformer_model.npuasm.json` | 上层编译器生成的低层汇编输入 |
| `transformer_model.cmd.bin` | 连续 CMD128 指令 |
| `transformer_model.desc.bin` | 64B 对齐的 Descriptor |
| `transformer_model.const.bin` | 已按设备读取顺序整理的权重和函数参数 |
| `transformer_model.runtime.json` | 输入输出信息、提交组、任务和存储计划 |
| `transformer_model.manifest.json` | 文件大小与 SHA-256 |
| `transformer_model.npu.h` | C 运行程序使用的全部数组和元数据 |

`make check` 还会把生成的 `transformer_model.npuasm.json` 交给
`npu_assembler.py` 单独汇编，并逐字节比较两种调用方式生成的 CMD128 和
Descriptor。

示例把每个提交组限制为 8 条命令，以验证多组提交。该值小于硬件任务表容量，
不会改变计算结果。

## C 运行程序做了什么

`transformer_runner.c` 不填写内部 L1 地址，也不整理权重。它只读取生成头文件
中的：

- CMD128 数组与任务编号；
- 提交组；
- Descriptor 数组及其 DDR 基地址；
- 常量镜像及其 DDR 基地址；
- 输入和输出 DDR binding。

运行程序将生成的 Descriptor 与常量镜像放入 cmodel DDR，把测试输入写到生成的
输入地址，然后按提交组执行以下步骤：

1. 调用公开 `npu_drv_submit()` 提交组内全部 CMD128；
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

当前模型生成 36 条 CMD128，分为 5 个提交组。运行时发送 72 个 64-bit beat，
36 条任务全部返回成功。GCC、Clang、ASan+UBSan 均已完成验证。

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
