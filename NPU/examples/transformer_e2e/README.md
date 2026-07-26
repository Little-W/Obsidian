# Transformer CMD128 端到端运行

本目录保存一个由结构化 JSON IR 描述的 Transformer Block。模型宽度为 8，
序列长度为 2，注意力头数为 2，FFN 中间宽度为 16，张量和权重采用 INT16。
它由仓库中处理低层 JSON IR 的汇编器 `NPU/compiler/npu_assembler.py`
生成 CMD128、
Descriptor、清单和 C 头文件。本目录把它作为可执行指令输入，不把它描述为
高层模型前端。

模型包含以下计算：

- 从 DDR 把输入、六组权重和整数转换参数送入 L1；
- Q、K、V 三个投影；
- 两头 `QK^T`、Softmax 和 `AV`；
- 注意力输出投影；
- 两次残差加法和两次 LayerNorm；
- `8 -> 16 -> 8` 的两层 FFN，以及中间 GELU。

`depends_on` 会生成事件等待和完成事件。Q、K、V 投影等待各自的输入数据和
参数，后续数据整理可在其他执行单元工作时推进；`QK^T` 等待 Q 和 K 的准备
任务，`AV` 同时等待 Softmax 与 V 的准备任务。运行程序会列出每条指令的名称、
command_id、等待事件、完成事件、接收状态、结束状态和处理元素数。

## 目录内容

- `transformer_block.json`：模型、地址、算子和事件依赖；
- `compile_model.sh`：调用低层 JSON IR 工具并逐字节复查生成文件；
- `cmodel_driver_backend.[ch]`：公开驱动平台回调到 cmodel 的软件后端；
- `transformer_runner.c`：参数准备、CMD128 提交、状态检查和数值比对；
- `run_model.sh`：编译后运行。

软件后端通过 `npu_model_cycle_io` 接收 CMD128 的两个 64-bit beat，并把生成的
Descriptor、输入和参数放入 cmodel DDR。由生成指令中的 DMA 任务把数据送入
L1。C 程序只通过 `npu_driver.h` 中的公开驱动函数提交、等待、查询、同步和
确认任务。它不会跳过指令执行去直接写最终输出。

参考计算独立使用标准 `expf`、`erff` 和 `sqrtf` 完成多头注意力、GELU 与两次
LayerNorm，然后与 cmodel 的 16 个 INT16 输出逐项比较。输入中的两个 token
应分别得到类别 0 和类别 5。

## 运行

```bash
cd "/home/yusen/Obsidian Vault/NPU/examples/transformer_e2e"
./compile_model.sh
./run_model.sh
```

也可以直接执行：

```bash
make test
```

成功时最后一行以 `PASS commands=30 cmd_bits=128` 开头。
