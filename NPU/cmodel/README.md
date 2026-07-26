# 单核 NPU C model

本目录给出《NPU 指令与硬件架构设计 Spec》的 C11 参考模型。模型同时提供三层接口：

1. 基础数值函数，用于单独检查 INT4、INT8、INT16、INT32、整数舍入和 CME 函数近似；
2. DMA、Matrix、IVE、CME 的算子接口，用于定位单元内部问题；
3. 128-bit CMD、little-endian 描述符、任务表、事件表和按周期推进接口，用于检查完整任务。

模型张量只使用 INT4、INT8、INT16 和 INT32。FP32 只出现在 CME 的内部运算和只读参数中。

> [!important] 硬件范围
> Generic Core 是 NPU 外部的主控 CPU。真实 SoC 中，CPU 以 AXI Master
> 身份访问 NPU 的 AXI Slave 固定命令 FIFO、控制寄存器和 L1BUF 外部窗口；
> MIF 通过 AXI Master 接入系统总线，DDR 是系统总线上的存储目标，由 SoC
> 地址译码选择。MIF 不提供 DDR 专用端口，也不提供另一组外部存储端口。代码中保留
> `npu_issue_adapter_cycle`、`npu_gc_axi_cycle` 以及若干 `gc_*` 字段，
> 仅用于兼容已有的系统联合仿真测试。它们表示 NPU 外部的 CPU 侧测试部件，
> 不属于待实现的 NPU RTL，也不是实际主控可绕过 AXI 使用的硬件端口。

## 1. 参考配置

| 项目 | 数值 |
| --- | ---: |
| Core 数 | 1 |
| 数据接口 | 64 bit |
| L1BUF | 1 MiB |
| L1 bank 数 | 16 |
| L1 读延迟 | 2 cycles |
| `MT/KT/NT` | 8 / 16 / 8 |
| IVE lane 数 | 8 |
| CME FP32 lane 数 | 4 |
| CME 私有暂存 | 4096 个 FP32 元素 |
| Task 项数 | 32 |
| Descriptor 槽数 | 32 |
| CFE FIFO 深度参数 | 8 |
| DMA 未完成请求数 | 16 |
| MIF 未完成事务总数 | 16 |
| DMA 最大 burst | 16 个 64-bit beat |
| 系统存储读首拍参考延迟 | 20 个 NoC 存储目标 tick |
| 系统存储写响应参考延迟 | 12 个 NoC 存储目标 tick |
| CMD 宽度 | 128 bit |
| CMD 物理接口 | 64 bit，先传低 64 bit，再传高 64 bit |
| CFE 第二拍等待上限 | 32 cycles |

这些数值是 C model 的可重复参考配置，不代表最终芯片的面积、频率或性能结果。调用者可以修改 `npu_config_t`，但不能超过头文件中给出的静态数组上限。

只使用功能模型时，可在公开限制内修改 `npu_config_t`。使用控制侧单核组合
`npu_core_top_cycle_init()` 或完整单核组合 `npu_single_core_cycle_init()` 时，
`npu_config_t`、`npu_wire_limits_t` 与 `npu_lsc_cycle_config_t` 必须描述相同
能力。两种初始化都会在改动目标实例前核对 L1、任务表、FIFO、DMA、
Matrix、IVE、CME 和 timeout 相关字段；不一致时返回 `BAD_DESC`，目标实例
保持原值。完整单核组合还会核对具体 L1BUF 与 MIF 模块采用的固定数值。测试
修改 `MT/KT/NT` 等参数时，需要同步修改功能配置、线格式限制和 LSC 只读
功能字段。

检查内容还包括：`gaddr_limit` 不得大于功能模型实际提供的系统存储字节数，
`isa_feature` 不得设置当前周期模型尚未支持的功能位，LSC 各只读组合字段的
保留位必须为零。调用者没有提供 `npu_wire_limits_t` 时，组合模型会把参考
`gaddr_limit` 缩小为实际系统存储数组字节数。

完整单核组合在改动 `top`、L1 ECC 数组或访问记录数组前，会先检查四组
`npu_engine_data_workspace_t`。`npu_engine_data_workspace_valid()` 只读取
workspace 描述，不会清除哈希数组或访问记录。读写 entry 指针、哈希指针和
容量都必须有效；哈希槽数必须是 2 的幂，并且不得小于对应 entry 容量。任意
一组检查失败时，初始化返回 `BAD_DESC`，调用前的 `top`、ECC 数组、workspace
描述及其数组内容均保持不变。

## 2. 文件说明

| 文件 | 内容 |
| --- | --- |
| `include/npu_cmodel.h` | 数据类型、任务描述、公开 API、参考配置 |
| `include/npu_wire.h` | 128-bit CMD 和描述符解码 API |
| `src/npu_integer.c` | little-endian 访问、INT4、整数舍入、裁剪 |
| `src/npu_dma.c` | 1D/ND copy、fill、transpose、pack、split |
| `src/npu_matrix.c` | GEMM、BMM、部分和、bias、整数重缩放 |
| `src/npu_vector.c` | 十个 P0 整数逐元素指令 |
| `src/npu_math.c` | 不依赖 libm 的 Exp、Reciprocal、Tanh 等基础函数 |
| `src/npu_complex.c` | 激活、Softmax、Norm、Statistics、带 scale 加法 |
| `src/npu_core.c` | Task、Event、Engine 调度、超时和周期统计 |
| `src/npu_frontend.c` | CMD 低、高两拍接收、原始描述符读取和接收响应 |
| `src/npu_wire.c` | 各字段的 little-endian 解码与严格检查 |
| `include/src/npu_bus_trace.*` | 功能算子访问的 64-bit 读写记录，用于数据侧周期适配器 |
| `include/src/npu_bus_replay_cycle.*` | 把访问记录转换为 L1BUF/MIF ready/valid 传输并等待响应 |
| `include/src/npu_issue_adapter_cycle.*` | 外部 CPU 侧兼容测试适配器；把旧测试请求转换成 CMD 低高两拍和控制请求，不属于 NPU RTL |
| `include/src/npu_cfe_cycle.*` | CFE 模块级 ready/valid、两拍组装、格式检查和接收时序 |
| `include/src/npu_ts_cycle.*` | TS、DFU、Descriptor SRAM、事件和三拍完成消息 |
| `include/src/npu_engine_cycle.*` | 四类执行单元的任务、描述符和完成消息适配器 |
| `include/src/npu_engine_data_cycle.*` | Engine Adapter 与逐 beat L1BUF/MIF 数据访问的组合包装器 |
| `include/src/npu_core_top_cycle.*` | CFE、TS、四个 Engine Adapter 与 LSC 的同拍组合 |
| `include/src/npu_l1_cycle.*` | 13 个读端口、5 个写端口、bank 仲裁和 ECC 注错 |
| `include/src/npu_l1_diag_bridge.*` | System Slave 诊断请求到 L1 Debug 端口的桥 |
| `include/src/npu_tbu_cycle.*` | TBU 规则、访问权限、固定响应延迟和错误状态 |
| `include/src/npu_mif_cycle.*` | 两个内部发起者、TBU、系统总线 AXI Master 接口 |
| `include/src/npu_mif_cdc_cycle.*` | Core/NoC 独立 tick 的请求、写数据和响应异步 FIFO |
| `include/src/npu_axi_mem_target_cycle.*` | MIF 与外部 CPU 测试部件可复用的 64-bit AXI4 存储目标周期模型 |
| `include/src/npu_sys_slave_cycle.*` | 64-bit AXI4 Slave、固定命令 FIFO、命令响应 FIFO 与内部请求转换 |
| `include/src/npu_lsc_cycle.*` | CSR、首错、中断、性能计数和受控复位 |
| `include/src/npu_control_cycle.*` | CRG 复位同步、时钟控制和 WDT |
| `include/src/npu_single_core_cycle.*` | Core/NoC 双时钟单核组合接口 |
| `tools/export_keras_sequence_fixtures.py` | 建立并训练四个应用模型，生成 C fixture 和 TFLite 检查数据 |
| `tools/compile_keras_model.py` | 离线导出固定应用模型的 `.keras`、`.tflite` 和 JSON 清单 |
| `tests/test_keras_sequence_inference.c` | 四个序列网络的逐层测试及 `model_infer` 独立入口 |
| `tests/test_dtype_regression.c` | 四种整数 dtype 的系统组合检查 |
| `tests/test_matrix_pipeline.c` | Matrix 两阶段发射、地址关系、计数和超时检查 |
| `tests/` | 数值、算子、描述符、事件和时序测试 |

## 3. 构建与测试

进入本目录后，可以按需要选择下表中的 Make 目标。无参数 `make` 等同于
`make all`，只完成构建，不运行测试。

| 命令 | 作用 | 是否需要 TensorFlow |
| --- | --- | ---: |
| `make all` | 生成静态库 `build/libnpu_cmodel.a` 和主测试程序 `build/test_npu_cmodel`，不运行测试 | 否 |
| `make test` | 构建并运行全部主测试；其中已经包含 wire 端到端测试和全部整数类型组合测试 | 否 |
| `make wire-e2e` | 单独构建并运行 `build/test_wire_e2e`，便于只检查 CMD、描述符和任务提交 | 否 |
| `make model-infer MODEL=all` | 运行 fixture 中的 Transformer、SimpleRNN、GRU、LSTM C 推理；也可只选一个模型 | 否 |
| `make model-compile MODEL=all` | 在 conda 环境中训练并导出 `.keras`、`.tflite` 和 `.json` | 是 |
| `make model-compile-check MODEL=all` | 检查已经导出的模型文件；不会自动先执行导出 | 是 |
| `make keras-fixture` | 重新训练 MLP 和四个序列网络，并改写两份 `tests/generated/*.h` | 是 |
| `make keras-e2e` | 先重新生成全部 fixture，再构建并运行全部主测试 | 是 |
| `make sanitize` | 在 `build-sanitize` 中使用 AddressSanitizer 和 UndefinedBehaviorSanitizer 构建并运行主测试 | 否 |
| `make clean` | 删除 `BUILD_DIR` 与 `SAN_BUILD_DIR`；不改写模型导出文件或 fixture | 否 |

> [!note] 四种整数类型的组合回归
> 数据格式测试检查 4 组张量存储、16 组 DMA 源/目的类型、64 组 Matrix A/B/C
> 类型、42 组 Vector 类型和 16 组 Complex 源/目的类型。Matrix 输入支持
> INT4×INT4、INT8×INT8、INT8×INT4 和 INT16×INT16；每种输入可写 INT4、
> INT8、INT16 或 INT32，共 16 组有效配置。其余组合必须准确返回
> `DTYPE_UNSUPPORTED`。

最常用的纯 C 检查顺序是：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel"
make clean
make all
make test
make wire-e2e
make sanitize
```

`make all` 与 `make test` 分开列出，是为了明确区分“只编译”和“编译后运行”。
若只想快速执行全部主测试，直接运行 `make test` 即可。

Makefile 常用可覆盖变量如下：

| 变量 | 默认值 | 用途 |
| --- | --- | --- |
| `CC` | `cc` | C 编译器 |
| `AR` | `ar` | 静态库工具 |
| `BUILD_DIR` | `build` | 普通构建目录；模型导出目录未单独指定时也随之改变 |
| `SAN_BUILD_DIR` | `build-sanitize` | Sanitizer 构建目录 |
| `MODEL` | `all` | `transformer`、`simple_rnn`、`rnn`、`gru`、`lstm` 或 `all` |
| `CONDA` | `conda` | conda 命令 |
| `KERAS_CONDA_ENV` | `tf_2_18` | Keras 与 TensorFlow 所在环境 |
| `MODEL_COMPILER_OUTPUT_DIR` | `$(BUILD_DIR)/model-compiler` | 离线模型导出目录 |

例如：

```bash
make BUILD_DIR=/tmp/npu-cmodel-build test
make model-infer MODEL=gru
make model-compile MODEL=gru
make model-compile-check MODEL=gru
```

### 3.1 通用模型编译器加 C 驱动的独立示例

[`examples/README.md`](examples/README.md) 另行提供四个从 Keras 训练到
CModel 推理的独立示例。它们调用 `compiler/npu_model_compiler.py` 生成
C 配置、CMD128、Descriptor、权重和输入输出信息，再由 C 驱动通过固定地址
命令 FIFO 提交。四个示例的模型张量只使用 INT8，矩阵累加使用 INT32；
复杂函数和 GRU/LSTM 的软件状态更新可以暂时使用 FP32。

| 示例 | 应用目标 | 单独运行 |
| --- | --- | --- |
| RNN | 设备遥测序列状态估计 | `make -C examples/rnn test` |
| GRU | 带更新门和重置门的设备遥测序列状态估计 | `make -C examples/gru test` |
| LSTM | 带单元状态的设备遥测序列状态估计 | `make -C examples/lstm test` |
| CNN | 6×6 灰度图划痕方向分类 | `make -C examples/cnn test` |

一次运行四个示例：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel/examples"
make clean
make test
```

每个程序都会逐样本打印详细输入、Keras 参考结果、CModel 结果、误差或分类
正确率，以及命令组数、64-bit beat 数、响应数和周期数。CNN 的 `.keras`
模型直接进入编译器；Conv2D 会被拆成 im2col 的 DMA 操作和 GEMM。RNN、
GRU、LSTM 会从训练后的 Keras 权重生成单时刻高层 JSON 模型，再交给同一
编译器。

清理四个示例的生成目录：

```bash
make -C examples clean
```

> [!note] 生成文件与清理范围
> `make keras-fixture` 会改写仓库中的两个 fixture 头文件，不是只在构建目录中
> 生成临时文件。`make sanitize` 结束后保留 `build-sanitize`，统一运行
> `make clean` 会删除普通构建目录与 Sanitizer 构建目录。

默认编译参数包含：

```text
-std=c11
-Wall -Wextra -Wpedantic -Werror
-fno-fast-math
-ffp-contract=off
-fexcess-precision=standard
```

`libnpu_cmodel.a` 不需要链接 `libm`。

## 4. 内存与张量

### 4.1 存储数组和张量地址

初始化时由调用者提供 L1BUF 和系统存储字节数组。当前公开结构中的
`ddr` 字段保存该系统存储数组，名称不表示 MIF 存在 DDR 专用接口。模型不调用
`malloc`、`calloc` 或 `realloc`，也不取得这些数组的所有权。

```c
npu_config_t config;
npu_model_t model;

npu_config_reference(&config);
status = npu_model_init(
    &model,
    &config,
    l1_memory,
    l1_bytes,
    ddr_memory,
    ddr_bytes);
```

INT4 的偶数号元素位于低 4 bit，奇数号元素位于高 4 bit。模型通过 shift、mask 和显式符号扩展读写，不依赖 C 位域排列。INT16 和 INT32 始终按 little-endian 字节次序保存。

`npu_tensor_t` 中：

- `addr` 是所在存储区中的字节偏移；
- `region_bytes` 限制允许访问的字节数；
- `row_stride_bytes` 是相邻行起点的字节间隔；
- `batch_stride_bytes` 是相邻 Batch 起点的字节间隔；
- INT4 连续元素使用 `start_nibble` 选择起始半字节。

### 4.2 支持的数据格式

dtype 编码固定为 `0=INT4`、`1=INT8`、`2=INT32`、`3=INT16`。

四种整数 dtype 的主要支持情况如下：

| 执行单元 | 支持情况 |
| --- | --- |
| DMA | INT4、INT8、INT16、INT32 的 16 组源/目的组合 |
| Matrix 输入 | INT4×INT4、INT8×INT8、INT8×INT4、INT16×INT16 |
| Matrix 输出 | 上述每种输入可写 INT4、INT8、INT16 或 INT32，共 16 组有效配置 |
| Vector | 按各 opcode 的输入数和广播规则检查合法组合 |
| Complex | 四种整数输入可分别写为四种整数输出；FP32 只用于函数内部 |

Matrix bias 和 `ACCUM_FROM_SRC2` 的旧部分和使用 INT32。INT4、INT8 或 INT16
乘法结果先累加到 INT32 或更宽的内部临时值，最终按整数重缩放参数写回目标 dtype。
模型不允许把 FP32 作为普通输入、权重、中间张量或输出的 dtype。

## 5. 128-bit CMD、两拍传送与描述符

### 5.1 CMD 字段

CMD 用两个 64-bit word 保存。低 word 主要保存描述符地址和任务编号，高
word 保存操作、事件、任务选项和版本：

| CMD bit | 字段 | 说明 |
| ---: | --- | --- |
| `[47:0]` | `desc_addr` | 48-bit 描述符字节地址，必须按 64B 对齐 |
| `[59:48]` | `command_id` | 12-bit 软件命令编号 |
| `[63:60]` | `engine` | `0～4` 分别选择 Control、DMA、Matrix、Integer Vector、Complex Math |
| `[71:64]` | `opcode` | 当前执行单元的完整 8-bit 操作编号 |
| `[83:72]` | `header_flags` | 中断、严格数值、跟踪、顺序、CRC 和超时类别 |
| `[95:84]` | `wait_event_0` | 第一个等待事件 |
| `[107:96]` | `wait_event_1` | 第二个等待事件 |
| `[119:108]` | `signal_event` | 任务终态写入的事件 |
| `[127:120]` | `header_version` | 当前固定为 `1` |

一个事件引用的低 8 bit 是事件编号，高 4 bit 是 generation：

$$
\operatorname{event\_ref}
=
(\operatorname{generation}\ll 8)
\mathbin{|}
\operatorname{id}.
$$

`0xFFF` 表示没有事件。`header_flags[5:0]` 依次表示成功中断、错误中断、
严格数值、跟踪、按序执行和描述符 CRC；`header_flags[9:6]` 是超时类别；
`header_flags[11:10]` 必须为 0。

> [!note] 为什么不使用 64 bit 加一组提交 CSR
> 48-bit 地址、12-bit 任务编号已经占满一个 64-bit word，操作、事件和任务
> 选项只能另找位置。若把这些信息放在共享 CSR 中，每次提交前都要写寄存器并
> 等待写响应；多个软件提交者还要保护同一组寄存器。CMD128 把一条任务需要的
> 信息放在同一命令中，物理接口仍保持 64 bit。

### 5.2 功能接口示例

下面的例子建立 DMA `COPY_1D` 命令。`npu_cmd_encode()` 生成低、高两个
word，`npu_model_submit_wire()` 按同一顺序接收它们：

```c
npu_cmd_t cmd = {0};
uint64_t low_beat;
uint64_t high_beat;
npu_status_t status;

cmd.desc_addr = 0x4000;  /* 必须按 64B 对齐 */
cmd.command_id = 7;
cmd.engine = NPU_ENGINE_DMA;
cmd.opcode = NPU_DMA_COPY_1D;
cmd.wait_event[0] = npu_event_none();
cmd.wait_event[1] = npu_event_none();
cmd.signal_event = npu_event_none();
cmd.header_version = 1;
cmd.timeout_class = 0;

npu_cmd_encode(&cmd, &low_beat, &high_beat);
status = npu_model_submit_wire(&model, low_beat, high_beat);
```

该函数先解码完整 CMD，再从系统存储字节数组的 `desc_addr` 读取当前执行单元规定
的描述符长度，随后逐字段检查描述符并建立任务。

### 5.3 64-bit ready/valid 接口上的两拍时序

需要观察 CFE 时序时，使用 `npu_model_cycle_io()`。低 word 的控制值必须是
`first=1,last=0`，高 word 必须是 `first=0,last=1`：

```c
npu_host_inputs_t in = {0};
npu_host_outputs_t out;

in.core_reset_n = 1;
in.noc_reset_n = 1;
in.cmd_valid = 1;
in.cmd_rsp_ready = 1;

in.cmd_data = low_beat;
in.cmd_first = 1;
in.cmd_last = 0;
do {
    npu_model_cycle_io(&model, &in, &out);
} while (out.cmd_ready == 0);

in.cmd_data = high_beat;
in.cmd_first = 0;
in.cmd_last = 1;
do {
    npu_model_cycle_io(&model, &in, &out);
} while (out.cmd_ready == 0);

in.cmd_valid = 0;
do {
    npu_model_cycle_io(&model, &in, &out);
} while (out.cmd_rsp_valid == 0);
```

当 `cmd_valid=1,cmd_ready=0` 时，调用者必须同时保持 `cmd_data`、`cmd_first`
和 `cmd_last`。CFE 接收低 word 后进入等待高 word 的状态；参考配置在 32 个
周期内没有收到合法高 word 时返回 `TIMEOUT`，并丢弃已经保存的低 word。

真实主控 CPU 不使用这里的 `rs1/rs2` 接口。正式部署入口是 NPU 的 64-bit
AXI Slave 固定命令 FIFO：

- 命令数据写入地址为 `0x020000`。AW 通道使用
  `AWSIZE=3`、`AWBURST=FIXED`，一个 burst 包含 2～16 个偶数 beat；
- W 通道按“低 64 bit、高 64 bit”组成一条 CMD128，所有 beat 均要求
  `WSTRB=0xff`，`WLAST` 只在 burst 最后一拍有效；
- Slave 在 AW 握手前为整个 burst 保留入口空间。W 数据先放入事务暂存区，
  最后一拍检查通过后才把该 burst 的全部 CMD128 一次放入入口 FIFO；
- `BRESP` 只报告 AXI 格式与整 burst 接收结果。每条命令的 CFE 结果进入
  `0x020008` 响应 FIFO，软件每完成一次 64-bit 读取就取走一项；
- `0x020010` 返回入口可用 beat 数、响应项数、半条命令状态、两个满状态和
  协议错误保持位。响应 FIFO 暂时为空时，已经接收的 AR 会等待新结果，
  不会返回伪造数据。协议错误保持位在 Core reset、内部 soft reset 或
  LSC `FAULT_CLEAR.bit0` 清错脉冲到来时清零。

`npu_issue_adapter_cycle` 仍可从旧式 `rs1/rs2` 输入产生相同的两个 CMD
beat，但它只供模块级回归注入使用。它不是 NPU 顶层硬件端口，真实 CPU
不能用该接口绕过 AXI Slave。

## 6. 周期模型

`npu_model_cycle_io()` 是完整任务的功能级调度接口。它适合快速运行指令，
但不代表各硬件模块之间的全部端口。需要检查模块信号时，应使用
`*_cycle_step()` 接口。除 CRG 的时钟电平模型外，一次调用表示一个上升沿；
输出给出该周期可见信号，输入与输出同时为 valid/ready 时在调用结束时更新
模块状态。

模块级周期模型已经包含：

- NPU AXI Slave、CFE、TS、执行单元、L1BUF、MIF/TBU、LSC、CRG 和 WDT；
- 供旧回归使用的外部 CPU 侧适配器，可产生 CMD 两拍与
  `WAIT/QUERY/FENCE` 请求；
- CFE 与 TS 的 CMD、编号查询和暂停；
- DFU 到 MIF 的描述符请求、Descriptor SRAM 四个读取端口；
- TS 到四个 Engine 的任务接口和固定三拍完成消息；
- CFE、TS、四个 Engine Adapter 与 LSC 的单次提交组合接口；
- L1BUF 全部参考读写端口、bank 仲裁、写字节使能和 ECC 状态；
- MIF 的 TBU、页拆分、AXI Master 访问和按 AXI ID 返回；
- MIF 两侧独立 tick、两级位置同步和双向异步 FIFO；
- TBU 的命中、权限错误、固定延迟以及与 MIF 的组合运行；
- System Slave、LSC、L1BUF 诊断桥、CRG 与 WDT；
- NPU 模块与外部 CPU 测试部件的双时钟系统联合仿真接口。

### 6.1 外部 CPU 兼容测试适配器

本小节只说明旧回归使用的 CPU 侧测试适配器，不定义 NPU 顶层端口。NPU
硬件的正式部署入口是 `0x020000` AXI Slave 固定命令 FIFO。这里的
`issue/rs1/rs2` 字段只用于模块级回归注入，不能作为 SoC 集成端口。

`issue_quiesce_i` 只控制测试适配器能否从 `IDLE` 状态接收一条新请求。
该信号为 1 时，空闲适配器把 `issue_ready_o` 置为 0，因而新的
`issue_valid_i` 不会完成握手。它不是取消信号，也不会中止已经接收的指令。

例如，适配器已经接收一条 `NPU_SUBMIT`，并进入 `SUBMIT_LOW` 状态后，即使
`issue_quiesce_i` 变为 1，它仍会依次发送 `rs1` 中的低 64 bit 和 `rs2`
中的高 64 bit，等待 CFE 响应，再向外部 CPU 测试端返回执行结果。已经进入控制请求或
Core 响应状态的 `WAIT`、`QUERY`、`FENCE` 也采用相同规则。需要取消允许取消
的指令时，应使用 `cpu_cancel_i`，不能把 `issue_quiesce_i` 当作取消输入。
如果 `issue_ready_o=0`，请求尚未被 Adapter 接收；此时同时给出
`issue_valid_i` 与 `cpu_cancel_i` 不会产生取消事件。只有先前已经完成
Issue 请求握手的 `WAIT` 或 `FENCE` 才能由该输入取消。

兼容联合仿真外壳在 `stop_fetch_i`、`dvfs_prepare_req_i`、软复位请求、
电源关闭请求或 LSC 内部 `stop_fetch` 任一项有效时，把
`issue_quiesce_i` 置为 1。LSC 的普通空闲检查
和复位排空检查都包含 `issue_idle`：只有 Issue Adapter 回到 `IDLE`，LSC
才会把单核视为空闲。这样，已经接收的 CMD 或控制请求可以先完成，
电源关闭确认也不会在 Issue Adapter 仍有未完成指令时提前给出。

### 6.2 单核控制信号与 tick 调用约定

`npu_single_core_cycle_core_inputs_t` 和
`npu_single_core_cycle_core_outputs_t` 中新增的顶层控制信号含义如下：

这些结构把 NPU 与外部 CPU 侧测试部件放在同一个联合仿真外壳中，因此包含
部分只用于兼容测试的字段。RTL 的 NPU 顶层不包含 CPU 取指、CPU Cache 或
自定义指令端口。

| 信号 | 方向 | 含义 |
| --- | --- | --- |
| `stop_fetch_i` | 输入 | 兼容测试字段；阻止外部 CPU 测试适配器接收下一条请求，但不会取消已经接收的请求 |
| `scan_mode_i` | 输入 | 扫描测试模式。Core 与 NoC 两类输入结构都提供该字段；为 1 时，相应 tick 使用全开的模块时钟请求掩码，Core 侧同时保持 `clk_req_o=1`。 |
| `clk_ack_i` | 输入 | SoC 时钟控制单元确认所请求的 Core 时钟已经可用。该输入用于保留顶层握手定义；周期模型的状态推进规则见下文。 |
| `effective_stop_fetch_o` | 输出 | 兼容测试字段；表示外部 CPU 测试适配器当前停止接收新请求 |
| `clk_req_o` | 输出 | 请求 SoC 保持 Core 时钟可用。正常运行和扫描测试时为 1；完成电源关闭排空并给出确认后可以变为 0。 |
| `soft_reset_done_o` | 输出 | 直接反映 LSC 的软复位完成状态。它不是内部复位脉冲。 |
| `power_down_ack_o` | 输出 | 直接反映 LSC 的电源关闭确认；联合仿真外壳还会等待外部 CPU 测试适配器空闲 |
| `wdt_reset_req_o` | 输出 | WDT 超时请求电平。超时保持期间，该输出保持为 1，直到 WDT 被复位、关闭、kick 或观察到 Core 进展。 |

`clk_req_o/clk_ack_i` 是顶层与 SoC 时钟控制单元之间的调用约定。硬件中，
SoC 在看到 `clk_req_o=1` 后提供时钟，并用 `clk_ack_i=1` 确认时钟可用。
C model 不会自行产生时钟：调用一次
`npu_single_core_cycle_core_tick()` 就明确表示调用者提供了一个 Core
上升沿，调用一次 `npu_single_core_cycle_noc_tick()` 就表示提供了一个 NoC
上升沿。因此，已经调用的 tick 总会推进对应时钟域，`clk_ack_i` 不会撤销、
跳过或重复该次调用。若测试环境需要模拟 SoC 暂停 Core 时钟，应暂停调用
`npu_single_core_cycle_core_tick()`，而不是继续调用并只把 `clk_ack_i` 置为
0。

`scan_mode_i=1` 时，Core 与 NoC 两侧都不采用 `module_clk_en_i` 关闭对应模块，
而是把模块时钟请求强制为全开；Core 侧还让 `clk_req_o` 保持为 1。这个规则用于扫描测试，
不表示周期模型会在调用者没有调用 tick 时自行推进。

`module_clk_active_o[7:0]` 表示八个本地 ICG 的实际 enable。
`core_clk_gated_o` 和 `noc_clk_gated_o` 只是域级汇总观测值。LSC、System
Slave、L1 Diagnostic Bridge、WDT 和 CRG 属于 NPU Core 常开控制区。
联合仿真外壳中的 CPU 侧测试适配器也随 Core tick 更新，但它不计入 NPU
时钟门控模块。

`dvfs_prepare_req_i=1` 时，NPU AXI Slave 停止接收新任务；兼容联合仿真
外壳也会暂停 CPU 侧测试适配器。已经接收的工作继续完成。CRG 直接读取当前模块状态，不使用上一拍
保存的 LSC idle 值；只有当前单核空闲且两类 AXI 都没有未完成事务时，
`dvfs_prepare_ack_o` 才为 1。请求撤销后，两个入口才重新给出 ready。
System Slave 的受限制调试访问也使用当前状态；若同拍接收新 Issue 或缓存请求，
该调试访问按忙状态处理。

### 6.3 软复位、WDT 与性能计数的时序

软复位不是只在 Core 域内完成。LSC 等待 AXI Slave、CFE、TS、四个
Engine、L1 和 MIF 满足排空要求后，产生内部软复位脉冲。兼容联合仿真
外壳还会等待外部 CPU 测试部件结束已接收的请求。
单核顶层随后把复位请求传到 NoC 域；NoC 域复位 MIF 和内部 TBU，并返回
MIF reset ack。该确认经过同步后回到 Core 域，LSC 才进入软复位确认状态并
使 `soft_reset_done_o=1`。因此，在 NoC tick 没有继续推进，或 MIF reset ack
尚未返回时，`soft_reset_done_o` 必须保持为 0。

WDT 的 `timeout` 和 `wdt_reset_req_o` 是保持型电平，LSC 接收的
`wdt_timeout` 则是单周期事件。单核顶层对 WDT 超时电平做上升沿检测：
WDT 第一次从 0 变为 1 后，下一次 Core tick 向 LSC 提交一次
`wdt_timeout=1`；超时电平持续为 1 时不会重复提交。WDT 回到 0 后若再次
超时，才会产生下一次事件。这样可以避免一个保持数十拍的 WDT 请求在 LSC
中被重复记录。

顶层把真实推进事件送入 WDT：Issue 请求与返回握手、CFE 编号查询、描述符
请求与返回、其他控制与数据接口握手、ME 的有效 MAC、IVE 的有效整数运算、
CME 的 I2F/FP32/F2I 活动以及 NPU AXI Slave 和 MIF 的有效握手均会清除
计数。兼容联合仿真外壳还把外部 CPU 测试部件的有效握手计作系统推进。
只保持 busy、valid 被 ready 暂停，或读取返回被客户端
暂停接收，都不会被当作新推进。

性能计数器 13 表示整数饱和次数，性能计数器 14 表示全 mask 行数。这两个
值来自功能算子在 Engine 提交阶段产生的增量，而该提交发生在当前 Core tick
的 LSC 更新之后。单核顶层先把增量保存一拍，再在下一个 Core tick 送给
LSC。因此，测试应在功能任务提交后的下一拍读取这两个计数器。增量送达 LSC
时如果 `PERF_FREEZE` 有效，LSC 不累计该增量，顶层也不会在解除暂停后补记；
暂停期间的事件按丢弃处理，不形成待补记队列。

### 6.4 非受控跨时钟复位与旧返回隔离

`npu_mif_cdc_cycle` 使用 32-bit `reset_epoch` 记录任一时钟域造成的 FIFO
状态丢失。Core 和 NoC 各自经过两级寄存器观察该值，再各用一个本域 tick
完成释放。`npu_mif_cdc_core_outputs_t` 和
`npu_mif_cdc_noc_outputs_t` 都提供本域可见的 `reset_epoch` 与
`transport_active`。只有两侧都处理当前 epoch 后，`transport_active` 才为
1，FIFO 才重新产生 ready/valid。

NoC 复位中断活跃 DFU 或 DMA 请求时，Core 可以在 NoC 不再推进的情况下继续
调用 `npu_single_core_cycle_core_tick()`。Core 侧观察到新 epoch 后，顶层向
TS 提交一个周期的 `mif_reset_abort`。TS 直接使受影响任务进入 `ABORTED`
终态，设置 `NPU_DONE_ABORT_DRAINED`，并立即清除 DFU 等待状态或 DMA active
状态；DMA 数据适配器在同一 Core tick 复位。该处理不等待已经被 CDC/MIF
复位清除的 response。

Core-only 复位不会要求外部 AXI 存储目标随 Core 一起复位。NoC 侧观察到新
epoch 时，单核顶层先保存旧 MIF 中已经发出的 AXI ID 和外部 TBU tag，再复位
MIF。旧 ID 或 tag 处理完成前不能用于新请求。随后到达的旧 R、B 或外部 TBU
返回在单核顶层完成握手并被丢弃，不进入新的 MIF 表项。以下计数器可用于测试
和诊断：

| 字段 | 含义 |
| --- | --- |
| `stale_axi_read_drop_count` | 已接收并丢弃的旧 AXI R beat 数 |
| `stale_axi_write_drop_count` | 已接收并丢弃的旧 AXI B 数 |
| `stale_tbu_drop_count` | 已接收并丢弃的旧外部 TBU 返回数 |

已发出 AW 但尚未发送完整 W 数据的事务不能由 AXI Master 取消。单核顶层按
原 AW 顺序补发剩余 W beat；补发数据和字节使能均为 0，只在每笔事务最后
一拍置 `WLAST=1`。该事务的 ID 会继续保留，直到目标给出 B，或者测试环境
复位对应存储目标。测试环境若只复位 Core，必须继续推进 NoC 和目标 tick，
才能观察补发 W 与旧返回丢弃过程。

NoC 本地复位和 `npu_single_core_cycle_reset()` 表示目标也随复位清除旧事务，
因此会直接清空旧 ID/tag 记录；只有 Core 单侧复位传播出的新 epoch 才保存旧
返回信息。

相关回归分别位于：

- `test_mif_cdc_cycle.c`：检查 epoch 的两级观察和双域释放；
- `test_ts_cycle.c`：检查 DFU、DMA 的直接 `ABORTED` 终态；
- `test_single_core_cycle.c`：检查 Core tick 快于 NoC tick、NoC 复位中断活跃请求；
- `test_single_core_axi_target.c`：检查旧 AXI ID 保留、旧 R/B 丢弃、未完成 W
  的零字节使能补发，以及相同 `command_id` 的新任务仍能成功完成。

### 6.5 AXI 存储目标

`npu_axi_mem_target_cycle` 是可复用的 64-bit AXI 存储目标。NPU 的 MIF
AXI Master 使用它检查系统存储访问；兼容测试也可把外部 CPU 的 AXI Master
接到另一实例。`npu_mif_cycle_inputs_t::axi` 和
`npu_mif_cycle_outputs_t::axi` 表示 MIF 的 AXI Master 接口。配置字段
`system_addr_enable`、`system_addr_base` 和 `system_addr_limit` 定义允许
发出的物理地址范围，范围内的请求均从 `axi` 发出。DDR 模型应作为系统总线
的存储目标连接，目标选择由总线地址译码完成。

参考配置允许读、写各 16 个未完成事务，支持 1～16 beat
INCR burst、8-bit ID、逐字节 `WSTRB` 和不同 ID 之间的响应换序；同一 ID
的事务保持请求次序。AR 握手后完整等待 20 个存储目标 tick，第一个 R beat
才能出现；最后一个 W beat 握手后完整等待 12 个存储目标 tick，B response
才能出现。MIF 目标随 NoC tick 推进，外部 CPU 测试目标随 Core tick 推进。R 或 B
被暂停接收时，ID、数据、response 和 `RLAST` 保持不变。

该存储目标不分配内存，初始化时接收调用者提供的字节数组和 AXI 基地址。
复位会清除已接收事务、响应保持寄存器和协议错误记录，但不会改写存储数组、
配置或注错规则。模型检查 8B 对齐、64-bit beat、INCR burst、1～16 beat、
4KiB 地址段和存储地址范围；无效请求返回 `DECERR`。`WLAST` 与 AWLEN 不一致
时记录协议错误并返回 `SLVERR`。注错规则可按起始地址和可选 ID 指定 response
及附加延迟。`npu_axi_mem_master_from_mif()`、`npu_axi_mem_target_to_mif()`、
`npu_axi_mem_master_from_gc()` 和 `npu_axi_mem_target_to_gc()` 用于连接两类
AXI Master 信号。

功能级调度器的周期计数是结构级参考值。每个 Engine 同时执行一个任务，
DMA、ME、IVE、CME 可以并行。一个任务的参考周期包括：

- 描述符 64-bit beat 数；
- 固定字段检查；
- 输入与输出 64-bit beat 数；
- L1 或系统存储参考延迟；
- tile、lane 或 CME 函数流水周期；
- 最后一次写响应等待。

`npu_estimate_task_cycles()` 的加法和乘法使用有上限的无符号计算。若 shape
或 tile 数使中间结果超过 64 bit，返回值固定为 `UINT64_MAX`，不会从 0
重新计数。该数值表示“超出参考计数可表示范围”，不是任务真实执行周期。

单独使用 `npu_engine_cycle` 时，模型仍在最后一个 EXECUTE 周期调用功能算子，
功能结果在该周期一次写入调用者提供的存储数组。需要检查数据端口时使用
`npu_engine_data_cycle`：它临时记录功能算子的 64-bit 源、目的访问，不直接
改写存储数组，再通过 L1BUF 或 DMA 的 MIF 端口逐 beat 发送，并在全部写响应
返回后才放行三拍完成消息。调用者必须提供访问记录工作区，并把数据端口接到
共享同一存储数组的 L1BUF/MIF/AXI 存储模型。

访问记录按读取阶段保存。Softmax 对同一输入行生成三组独立读请求；
LayerNorm 根据 `stats_mode` 生成两组或三组输入读取，RMSNorm 生成两组。
同一 64-bit word 只在单个阶段内合并，跨阶段重读会占用新的工作区条目并由
数据端口再次发送。功能算子的预检查读取不计为硬件数据请求，预检查期间仍会
查询目的写日志，因此不会改变任务内部“先写后读”看到的值。

每个 Engine Data 输入还带有 `param_l1_base`、`param_l1_limit` 和
`param_lock`。包装器取得完整目的写记录后，会在对外发出第一笔数据请求前
检查全部 L1BUF 目的 word。锁定状态下的任意相交写入都会返回
`ADDR_FAULT`；未锁定时只允许 `DMA_COPY_1D`、`DMA_COPY_ND` 且
`convert_mode=NONE` 的原始字节复制。其他 DMA 方式及 ME、IVE、CME 写入均被
拒绝。失败完成消息设置 `FAULT_ADDR_IS_L1`，`progress=0`，不设置
`PARTIAL_DEST`，并且不会发出源数据请求、目的写请求或提交暂存的性能增量。
L1BUF Controller 仍在每个写请求到达时执行一次独立保护检查。

同一个读取阶段内，四个 L1 读端口和 MIF 读接口各自保存一个未完成请求，
互不依赖的端口可以在同一周期提交。当前阶段的全部响应返回后，模型才会开始
下一阶段。连续地址的 L1 访问合并为最多 256 beat 的 burst，连续地址的 MIF
访问合并为最多 16 beat 的 burst；写请求采用相同的合并上限。

功能算子在数据端口发送前已经计算出预期结果，并把目的数据保存在写日志中。
端口返回的 `rdata` 只用于逐字节一致性检查：模型按照读取记录中的 `strb`
比较有效字节，不会把 `rdata` 再送入功能算子执行第二次计算。如果记录生成后
存储内容被其他请求改动，返回值与记录不一致，当前任务报告
`BUS_SLVERR`。目的存储只在外部存储模型接受写数据后改变，完成消息还要等待
对应写响应。

Engine Data 为每个读端口统计已经成功接收并完成数据核对的 64-bit word。
ME、IVE 和单遍 CME 按 Spec 第 13.9 节的响应额度公式判断完整算术组是否具备
启动条件。因此 `me_mac_active`、`ive_alu_active` 和单遍 CME 的流水 active
可以与后续源读响应同时出现，不再统一等待最后一个源读响应。Matrix 按有效的
`(Batch,M tile,N tile,K tile)` 组合给出 `me_mac_active`；IVE 按 lane 组给出
`ive_alu_active`，`ive_lane_valid` 精确指出当前组的 shape 有效 lane，最后一组
可以只置部分低位。

单遍 CME 使用逐组 token 推进 I2F、FP 和 F2I。I2F 延迟为 3 周期，F2I 延迟为
4 周期；直接函数使用 Spec 第 13.10.5 节的函数延迟。不同元素组可同时位于
I2F、FP 和 F2I，因此三个 active 信号允许同周期重叠。读响应暂停时只停止新组
进入 I2F，已经进入流水的组继续前进。Softmax、LayerNorm 和 RMSNorm 具有多次
输入读取，仍在全部读取遍次完成后使用 Spec 第 13.9 节的组合调度公式；
`ADD_RESCALE` 使用单遍 token 流水。调度不根据 mask 内容缩短。`VSTAT_I` 是
整数统计，三个 CME 流水 active 信号均为 0。

当前写重放仍在全部源读和算术活动完成后开始，因此模型已经覆盖
“读与计算重叠”，尚未逐组覆盖“计算与写回重叠”。精确到 tile 或元素组的写回
还需要访问记录保存组编号、各 Engine 保存输入就绪状态和输出 FIFO，并把读、
计算、写三个控制器分别推进。当前周期结果适合接口检查和可重复回归，不应替代
后续 RTL 的吞吐测量。

当前写记录只保存每个 64-bit word 的最终数据和字节写使能；同一 word 的多次写
已经合并，无法再判断各字节由哪个元素组产生。INT4 的两个半字节可能来自不同组，
原地任务的目的 word 也可能仍是后续组的源数据。Matrix 输出还要等待相应输出
tile 的最后一个 K tile。缺少产生组、输入消费组和输出 FIFO 状态时提前发送写
请求，会得到无法由现有记录证明的周期，并使取消后的部分目的数据不确定，因此
本版保持先排空全部读和算术活动、再开始写重放。

`l1_stall` 表示包装器正在等待某个 L1 ready 或 response valid。它不能区分
bank 冲突、仲裁等待和固定读延迟，所以不能当作算术单元内部某一级的精确暂停
原因。`cme_numeric_flag` 的 bit 0 表示功能算子报告通用数值异常，bit 1 表示
出现全 mask 行，bit 2 表示输入裁剪、输出超出 dtype 范围或最大有限值替代；
bit 3、4、5 分别表示 FP32 Inf、FP32 NaN 和除零事件，bit 7:6 为 0。
bit 1～5 在当前任务期间保持，下一条任务握手时清零，任务成功但曾出现相应
事件时也可以观察。

Engine Data 在功能状态与数据端口最终状态相同时提交性能增量。DMA 的 GADDR
读写有效字节数由访问记录中每个 64-bit word 的 `strb` 位数相加得到，不把
未选中的对齐字节计入。若数据端口错误或取消改变了任务最终状态，当前包装器
不会提交功能阶段暂存的性能增量；传输失败前已经返回的部分读字节尚未单独
累计。

`TIMEOUT_CLASS[0]=0` 表示不启用任务超时。其他类别的复位值在 `npu_config_reference()` 中给出。

### 6.6 功能级 Matrix 两阶段调度

功能级调度器把一条 Matrix 任务拆成两个驻留阶段：

- `active_slot[NPU_ENGINE_MATRIX]` 保存 MAC 前段；
- `matrix_accum_slot` 保存部分和、Epilogue 和写回后段。

MAC 前段结束后，只要后段槽空闲，任务就移入后段，并立即释放 MAC 槽。下一条
Matrix 任务因此可以在前一条任务写回期间读取 A/B 并执行乘累加。任务结果、
完成事件和 `end_cycle` 仍在后段结束时产生。

调度器按存储区和半开地址区段检查前一任务与候选任务。活动后段的写区段若与
候选 A/B、bias、旧部分和或整数重缩放表的读区段相交，候选 MAC 暂停。候选
任务未来的写区段与活动任务读区段或写区段相交时，可以先执行候选 MAC；后段
槽的占用规则会保证候选写回晚于活动任务完成。无法可靠计算地址跨度时采用保守暂停。

事件等待、`ORDERED` 和 Fence 的限制仍先于 Matrix 发射。超时从任务
`start_cycle` 连续计数，任务位于任一阶段或等待后段槽时都不会停止计时。

`npu_perf_t` 提供以下调试计数：

| 字段 | 增加条件 |
| --- | --- |
| `matrix_mac_active_cycles` | MAC 前段本周期确实有剩余工作 |
| `matrix_accum_active_cycles` | 后段本周期处于活动状态 |
| `matrix_overlap_cycles` | 上述两个阶段同周期活动 |
| `matrix_hazard_stall_cycles` | 可发射候选因活动写区段与其读取区段相交而暂停 |
| `matrix_operand_stall_cycles` | Matrix 数据端口等待 A/B |

`tests/test_matrix_pipeline.c` 检查安全并行、RAW 暂停、WAR/WAW 的先算后写、
事件、`ORDERED`、后段超时、计数和两组 GEMM 最终结果。该功能级调度与前文
Engine Data 的逐 beat 重放属于两个观察层次；后者仍按访问记录阶段推进，不能
用功能级计数替代 RTL 吞吐数据。

## 7. 数学函数实现

CME 基础函数不调用 `expf`、`tanhf`、`sqrtf`、`powf`、`roundf` 或 `lrintf`：

- Exp 使用 `ln(2)` 范围缩小、六次多项式和 FP32 指数字段组装；
- Reciprocal 使用初值和 Newton 更新；
- ReciprocalSqrt 使用指数初值和 Newton 更新；
- Sigmoid、Tanh、SiLU、GELU 由上述基础单元组合；
- Softmax 固定为三遍整数读取；
- LayerNorm 使用分开的均值与方差读取；
- RMSNorm 使用平方和与 ReciprocalSqrt。

测试首先检查内部 FP32 近似误差，再检查 `INT → FP32 → INT` 的最终整数结果。
`npu_mode0_trace_t` 还提供逐 bit 检查点：
`npu_exp_approx_traced()` 保存范围缩小后的 `k` 和 `r`，
`npu_reciprocal_approx_traced()` 与 `npu_rsqrt_approx_traced()` 保存第三轮
Newton 更新结果，`npu_float_to_int_traced()` 保存 F2I 输入位模式。普通函数
与带检查点函数共用计算实现，测试也检查两者的返回值完全相同。

## 8. 任务与事件

任务终态在 `npu_model_query(..., acknowledge=1, ...)` 前一直保留，`command_id` 也不能提前复用。输出事件进入成功或失败状态后，等待它的任务才会继续处理。生产者失败时，普通消费者返回 `DEPENDENCY_FAILED`。

`GLOBAL_FENCE` 在完整 CMD 完成握手时保存所有较早的 Engine 任务，描述符检查完成后再按 Engine mask 选择等待项。mask 为 0 时立即成功；mask 只选部分 Engine 时，其他 Engine 的活动任务不会延迟 Fence。随后提交的任务不属于已保存的任务集合。每个目标任务必须完整发送三拍完成消息并进入终态，才会被 Fence 视为已经结束。

多个目标失败时，Fence 固定返回最小 `submit_seq` 对应的失败状态，不受完成次序影响。Fence 的输出事件在 CMD 接收时为 RESERVED，Fence 成功后变为 SUCCESS，失败或超时后变为 ERROR，并保存相同的失败状态。

`npu_model_idle()` 只有在全部任务项已释放时返回 1。若任务已经计算完成但软件尚未 ACK，计算单元已经停止，函数仍返回 0，以便暴露终态记录占用问题。

## 9. 当前 P0 与可选功能

模型实现全部 P0 DMA、Matrix、IVE 和 CME 指令。下列可选指令默认返回 `ILLEGAL_OPCODE`：

- `DMA_GATHER_ND`
- `VROPE_I`
- 软件可见的 `VRECIP_I`
- CAUSAL Softmax

Softmax 和 Norm 内部仍使用 Reciprocal 或 ReciprocalSqrt 基础单元。CAUSAL Softmax 可先由软件生成 INT8 BOOLEAN mask。

## 10. Keras 训练与 layer 级推理

### 10.1 两层 MLP

`tools/train_export_keras_mlp.py` 使用 `tf_2_18` conda 环境训练一个
`4→8→3` 的 Keras MLP。第一层是带 bias 的 Dense + ReLU，第二层是带 bias
的 Dense。训练数据是固定随机种子生成的三分类数据，因此不需要下载数据集。
脚本完成训练后，把测试输入、两层权重、bias 和期望结果写入
`tests/generated/keras_mlp_fixture.h`。

完整流程使用以下命令：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel"
make keras-e2e
```

该命令会执行以下工作：

1. 在 `tf_2_18` 中训练 Keras 网络；
2. 把输入和权重转换为对称 INT8，把 bias 转换为 INT32；
3. 按参考 `KT=16`、`NT=8` 排列 Matrix 的 B 张量，并把 tile 中未使用的位置补
   0；
4. 生成 72 个均衡测试样本的逐元素期望值；
5. 重新编译并运行全部 C 测试。

设浮点输入、第一层权重和第一层输出的 scale 分别为
$s_x,s_{w1},s_h$。脚本使用：

$$
x_q=\operatorname{clip}\left(\operatorname{RNE}
\left(\frac{x}{s_x}\right),-127,127\right)
$$

$$
b_{1q}=\operatorname{RNE}
\left(\frac{b_1}{s_xs_{w1}}\right)
$$

第一层整数累加值为：

$$
a_1=x_qW_{1q}+b_{1q}
$$

脚本寻找 31-bit 正整数 $M$ 和非负右移量 $R$，近似表示
$s_xs_{w1}/s_h$。C model 使用最近偶数舍入计算：

$$
h_q=\operatorname{clip}
\left(\operatorname{RNE}
\left(\frac{\max(a_1,0)M}{2^R}\right),-128,127\right)
$$

第二层把 $h_q$ 与 INT8 权重相乘，加入 INT32 bias，保留 INT32 logits。该层
不需要再次缩放，三个输出使用同一个权重 scale，所以可以直接比较三个 logits
并选择最大值所在类别。

`test_keras_mlp_inference.c` 先单独执行第一层并逐个核对 576 个 INT8 隐藏层
结果，再执行第二层并逐个核对 216 个 INT32 logits，最后核对全部 72 个分类
结果。当前固定训练结果为：

| 项目 | 结果 |
| --- | ---: |
| Keras 完整测试集准确率 | 99.0885% |
| 72 个固定样本的 Keras 正确数 | 71 |
| 72 个固定样本的整数网络正确数 | 72 |
| Keras 与整数网络分类相同数 | 71 |
| 第一层 multiplier / shift | `6520393 / 31` |
| 生成头文件 SHA-256 | `c2512ef16ac349b4af6e52cba4784f53e644a8b8cbc33c6c050e09103c0317d4` |

生成头文件保存在仓库中，因此普通 `make test` 不依赖 TensorFlow。重新运行
训练脚本会用同一随机种子生成相同头文件；若训练参数或整数转换方法改变，
SHA-256 和逐元素期望值会一起改变。layer 测试直接使用
`npu_matrix_execute()` 检查两层数值；`test_single_core_cycle.c` 另行检查
Matrix 描述符经 Issue、CFE、TS、Engine Data、L1BUF 和 MIF 推进时的模块
信号与周期行为。

### 10.2 Transformer、SimpleRNN、GRU 和 LSTM

`tools/export_keras_sequence_fixtures.py` 在同一个 `tf_2_18` 环境中建立并
训练四个具有明确用途的小型 Keras 网络。Transformer 用于客户短文本分类；
SimpleRNN、GRU 和 LSTM 用于根据设备历史遥测数据估计下一时刻状态。每个网络
先使用固定种子设置初始权重，再通过 Keras `compile()` 和
`train_on_batch()` 执行 240 次全数据 SGD 更新。数据、目标值、更新次数和
学习率均固定，因此每次生成都能得到相同的检查数据。

#### 10.2.1 Transformer：客户短文本三分类

这个模型接收最多 4 个 token，把文本分成以下三类：

| 类别编号 | 类别名称 | 含义 |
| ---: | --- | --- |
| 0 | `positive_review` | 客户给出正面评价 |
| 1 | `negative_review` | 客户给出负面评价 |
| 2 | `information_request` | 客户询问状态或其他信息 |

词表包含 `pad`、`good`、`great`、`bad`、`awful`、`what`、`status` 和
`now`。`pad` 用于补足未占用的位置。例如，`good great` 会写成
`[good, great, pad, pad]`，所以每条输入都具有固定的 4 个 token 位置。

> [!note] `pad` 在这个简化模型中的真实作用
> 模型没有使用 padding mask。编号 0 的 `pad` 只是固定长度占位符，它的
> embedding 仍会参与自注意力和全序列平均池化，并不会被自动忽略。正式文本
> 模型若要排除占位位置，需要显式生成并传入相应的 mask。

训练语料共 12 条，每类各 4 条：

| 类别 | 训练文本 |
| --- | --- |
| `positive_review` | `good great`、`great good`、`good good great`、`great great good now` |
| `negative_review` | `bad awful`、`awful bad`、`bad bad awful`、`awful awful bad now` |
| `information_request` | `what status`、`what status now`、`status what now`、`what what status now` |

网络结构为 token embedding、position embedding、单头自注意力、两次残差
相加、两层 FFN、全序列平均池化和三分类 Dense。分类 Dense 输出
$C=3$ 个 logits。logit 是 Softmax 之前的原始分数，数值最大的分量就是模型
选择的类别。

训练使用 sparse categorical cross-entropy。先由 logits 计算第 $i$ 条文本
属于类别 $c$ 的概率：

$$
p_{i,c}=
\frac{\exp(z_{i,c})}
{\displaystyle\sum_{k=0}^{C-1}\exp(z_{i,k})}
$$

再计算全部训练文本的平均损失：

$$
\mathcal{L}_{\mathrm{CE}}
=-\frac{1}{N}\sum_{i=0}^{N-1}\log\left(p_{i,y_i}\right)
$$

式中：

- $N=12$ 是训练文本数量；
- $C=3$ 是类别数量；
- $z_{i,c}$ 是第 $i$ 条文本对类别 $c$ 的 logit；
- $\exp(x)$ 是指数函数；
- $p_{i,c}$ 是 Softmax 得到的类别概率；
- $y_i$ 是第 $i$ 条文本的正确类别编号，取值为 0、1 或 2；
- $\log(x)$ 是自然对数；
- $\mathcal{L}_{\mathrm{CE}}$ 越小，表示正确类别获得的概率通常越高。

这里的 `sparse` 表示标签直接保存为一个整数类别编号。例如
`positive_review` 的标签是 `0`，不需要把它写成 one-hot 向量
`[1, 0, 0]`。`from_logits=True` 表示损失函数接收原始 logits，并在内部完成
Softmax 计算。

脚本还保留两个训练语料中未出现过的固定样本，每个样本是一条短文本，用来
检查模型能否识别新的词序和重复词：

| 固定样本 | token 编号 | 正确类别 | Keras 预测类别 |
| --- | --- | ---: | ---: |
| `great good good` | `[2, 1, 1, 0]` | 0 | 0 |
| `status status what now` | `[6, 6, 5, 7]` | 2 | 2 |

这两个固定样本只检查类别 0 和类别 2。类别 1 会在 12 条训练文本的准确率
检查中出现，但当前 C 固定输入没有同时包含三个类别。

训练完成后，12 条训练文本的准确率为 1.0，两个固定样本的准确率也为 1.0。
交叉熵从 1.10277689 降至 0.32323018。固定样本没有出现在训练语料中，但词表
仍然只包含上述 8 个词；这项检查关注已知词组成的新短句，不代表模型已经具备
处理任意自然语言的能力。

#### 10.2.2 循环网络：设备遥测的带时间依赖回归

SimpleRNN、GRU 和 LSTM 使用相同的数据与目标值。每条样本包含 4 个时间步，
每步输入 3 个数：

| 符号 | 输入含义 | 数值解释 |
| --- | --- | --- |
| $T_t$ | 当前归一化温度 | 实际摄氏温度为 $60+20T_t$ |
| $L_t$ | 当前归一化负载 | 实际负载百分比为 $50+50L_t$ |
| $P_t$ | 当日运行周期的正弦值 | 取值通常在 $[-1,1]$，用于表达周期位置 |

例如，$T_t=0.30$ 表示 $66^\circ\mathrm{C}$，$L_t=0.20$ 表示 60% 负载。
$P_t$ 不是温度或负载，它表示设备处于日运行周期的哪个阶段。

网络在每个时间步输出 3 个连续值：

| 符号 | 输出含义 |
| --- | --- |
| $\widetilde{T}_t$ | 下一时刻的平滑归一化温度 |
| $\widetilde{L}_t$ | 下一时刻的平滑归一化负载 |
| $D_t$ | 下一时刻的归一化温度变化趋势 |

目标值不是只根据当前输入直接计算，而是同时使用上一时间步的目标状态：

$$
\widetilde{T}_t
=0.52\widetilde{T}_{t-1}
+0.30T_t
+0.12L_t
+0.06P_t
$$

$$
\widetilde{L}_t
=0.48\widetilde{L}_{t-1}
+0.38L_t
+0.14P_t
$$

$$
D_t
=0.55D_{t-1}
+0.45\left(\widetilde{T}_t-\widetilde{T}_{t-1}\right)
$$

第一个时间步之前取
$\widetilde{T}_{-1}=\widetilde{L}_{-1}=D_{-1}=0$。公式中的 $t$ 是当前
时间步，$t-1$ 是前一个时间步。$\widetilde{T}_{t-1}$、
$\widetilde{L}_{t-1}$ 和 $D_{t-1}$ 把早先的数据带入当前计算，因此即使两个
样本的当前输入相同，只要之前的记录不同，目标输出也可以不同。

温度和负载输出仍采用与输入相同的归一化尺度：

$$
\text{温度}\ (^\circ\mathrm{C})=60+20\widetilde{T}_t
$$

$$
\text{负载}\ (\%)=50+50\widetilde{L}_t
$$

若只把 $D_t$ 看作归一化温度差，则 $20D_t$ 表示相应的摄氏温度变化量。

训练只使用 32 条公式生成的遥测序列。下面两条固定序列完全不参加训练，专门
作为独立测试数据。脚本还会确认它们没有出现在训练数据中。两条序列的最后一个
时间步都为 `[0.30, 0.20, 0.25]`，也就是相同的当前温度、当前负载和周期值，
但前三个时间步不同：

| 固定序列 | $t=0$ | $t=1$ | $t=2$ | $t=3$ |
| ---: | --- | --- | --- | --- |
| 0 | `[0.53, 0.31, 0.24]` | `[0.00, -0.19, -0.45]` | `[-0.53, -0.57, -0.92]` | `[0.30, 0.20, 0.25]` |
| 1 | `[-0.44, -0.04, -0.70]` | `[0.11, 0.45, -0.06]` | `[0.63, 0.76, 0.60]` | `[0.30, 0.20, 0.25]` |

每个方括号中的三个数依次是 $(T_t,L_t,P_t)$。由上述递推式得到的最后一步
目标为：

| 固定序列 | $\widetilde{T}_3$ | $\widetilde{L}_3$ | $D_3$ |
| ---: | ---: | ---: | ---: |
| 0 | -0.00180586148 | -0.0691984445 | 0.0305751935 |
| 1 | 0.2908346355 | 0.3148880005 | 0.0798725784 |

这个例子直接说明了为什么循环状态有用：只查看最后一个输入，无法区分这两个
样本；读取此前记录后，模型才有机会给出不同的温度与趋势估计。

训练和独立测试都使用均方误差：

$$
\operatorname{MSE}
=\frac{1}{B S U}
\sum_{b=0}^{B-1}
\sum_{t=0}^{S-1}
\sum_{u=0}^{U-1}
\left(\widehat{y}_{b,t,u}-y_{b,t,u}\right)^2
$$

其中 $B$ 是样本数，$S=4$ 是时间步数，$U=3$ 是每步输出数，
$\widehat{y}_{b,t,u}$ 是网络预测，$y_{b,t,u}$ 是目标值。平方会让正误差和
负误差都变成非负数；MSE 越小，表示预测通常越接近目标值。

为了避免只看一个孤立数值，脚本先计算“沿用上一目标值”的完整序列基准。第一
个时间步预测全 0，之后直接把上一个时间步的目标当作当前预测：

$$
\widehat{\boldsymbol{y}}^{\,\mathrm{history}}_0=\boldsymbol{0},
\qquad
\widehat{\boldsymbol{y}}^{\,\mathrm{history}}_t
=\boldsymbol{y}_{t-1}\quad(t\ge 1)
$$

两条独立测试序列上的完整序列基准 MSE 为 0.0391055681，三个循环网络的完整
测试 MSE 都小于该值。

完整序列基准仍不足以证明网络区分了两段历史，因为两个样本最后的当前输入
完全相同。为此，脚本再构造“同当前输入的最佳共享末步输出”。假设一个模型
忽略前三个时间步，那么它看到相同的 $[0.30,0.20,0.25]$ 后，只能对两个样本
给出同一个末步输出向量。均方误差意义下，最好的共享向量是两个末步目标的
逐分量平均值：

$$
\overline{\boldsymbol{y}}_3
=\frac{
\boldsymbol{y}_{0,3}+\boldsymbol{y}_{1,3}
}{2}
$$

相应的共享输出基准为：

$$
\operatorname{MSE}_{\mathrm{shared}}
=\frac{1}{2U}
\sum_{b=0}^{1}
\sum_{u=0}^{U-1}
\left(
\overline{y}_{3,u}-y_{b,3,u}
\right)^2
$$

式中，$\boldsymbol{y}_{0,3}$ 和 $\boldsymbol{y}_{1,3}$ 是两条独立测试序列
各自的末步目标，$U=3$ 是末步输出数，
$\overline{\boldsymbol{y}}_3$ 是只能给两个样本共用的输出。这个基准的 MSE
为 0.0196325909。SimpleRNN、GRU 和 LSTM 的末步测试 MSE 均小于该值。

Keras、TFLite Interpreter 和 C model 还分别检查以下三项：

1. 两个末步预测向量逐分量差的最大绝对值大于 0.005，防止模型对不同历史
   给出几乎相同的结果；
2. 预测与各自历史目标配对时的误差，小于交换两个目标后的配对误差，确认每个
   预测确实对应自己的历史；
3. 末步测试 MSE 小于 0.0196325909 的共享输出基准，确认结果优于忽略历史时
   能取得的最佳共同输出。

这两条序列没有参与训练，所以本文把其完整 MSE 和末步 MSE 都称为独立测试
指标。独立测试样本只有两条，适合检查时间依赖计算是否生效，但不能代替更大
规模的数据集评估。

三个循环层直接把 3 个 hidden 分量作为
$(\widetilde{T}_t,\widetilde{L}_t,D_t)$，没有再接一个 Dense 输出层。这样既
保留实际的回归目标，又能直接检查循环层的底层计算：

| 网络 | 每个时间步的主要计算 |
| --- | --- |
| SimpleRNN | `tanh(xW_x+hW_h+b)` |
| GRU | update、reset 和 candidate 三组门，`reset_after=True` |
| LSTM | input、forget、candidate 和 output 四组门，同时更新 cell 与 hidden |

#### 10.2.3 训练与独立测试结果

四个网络都执行 240 次全数据更新。Transformer 的损失是交叉熵，三个循环
网络的损失是 MSE，二者含义不同，不应直接比较数值大小。

| 网络 | 训练样本 | 损失类型 | 训练前损失 | 训练后损失 | 完整独立测试 MSE | 末步独立测试 MSE |
| --- | ---: | --- | ---: | ---: | ---: | ---: |
| Transformer | 12 | 交叉熵 | 1.10277689 | 0.32323018 | 不适用 | 不适用 |
| SimpleRNN | 32 | MSE | 0.0414074771 | 0.00277871406 | 0.00415767729 | 0.00645086681 |
| GRU | 32 | MSE | 0.0943286568 | 0.00495296204 | 0.00498581165 | 0.00178855180 |
| LSTM | 32 | MSE | 0.100128189 | 0.0320885554 | 0.0179846659 | 0.0135771688 |

完整序列历史基准为 0.0391055681，共享末步输出基准为 0.0196325909。表中三个
完整独立测试 MSE 均小于前者，三个末步独立测试 MSE 均小于后者。

头文件保存训练前后损失、Transformer 准确率、循环网络完整独立测试 MSE、
末步独立测试 MSE、完整序列历史基准和共享末步输出基准的精确 FP32 bit。
头文件记录的训练次数为 240；C 测试会检查次数非零、循环网络训练样本数为
32、独立测试样本数为 2、训练后损失更小、Transformer 的两项准确率均为
1.0，以及各项独立测试指标优于相应基准。

#### 10.2.4 TFLite 与 C model 检查

脚本把训练后的权重、bias、每层 FP32 参考值、对称 INT8 张量、INT32 累加值
和整数重缩放参数写入
`tests/generated/keras_sequence_fixtures.h`。循环网络还单独保存输入投影与
循环投影的 INT32 累加结果及 INT8 结果，便于区分矩阵乘法错误和后续门函数
错误。普通 `make test` 只读取该头文件，不需要安装 TensorFlow。

脚本也调用 TensorFlow Lite 转换器。状态 `1` 表示使用内置整数算子完成严格
转换；状态 `2` 表示使用框架允许的后备方式。Keras 的 SimpleRNN、GRU 和
LSTM 导出图包含 TensorList，TensorFlow 2.18 无法把这些节点全部改写成内置
整数算子，所以三个循环网络使用 Select TF Ops，状态均为 `2`。

转换成功后，脚本会建立 TFLite Interpreter，按照模型声明的输入 dtype、
scale 和 zero point 准备完整输入并实际执行推理。随后把输出还原为 FP32，
与训练后的 Keras 输出逐项比较。当前结果如下：

| 网络 | TFLite 状态 | 使用方式 | 最大绝对误差 | 允许上限 |
| --- | ---: | --- | ---: | ---: |
| Transformer | 1 | 内置整数算子 | 0.0135588646 | 0.0149999997 |
| SimpleRNN | 2 | Select TF Ops | 0.00579634309 | 0.00609999988 |
| GRU | 2 | Select TF Ops | 0.00422267057 | 0.00449999981 |
| LSTM | 2 | Select TF Ops | 0.00316065270 | 0.00340000005 |

任一误差超过上限时，生成脚本立即失败，不会写入新的测试头文件。Transformer
转换后的输出还必须对两个固定样本给出正确类别。三个循环网络的 TFLite 输出
还必须通过末步分量差、正确历史配对和共享末步输出基准三项检查。循环网络的
C model 测试按 `INT → FP32 → INT` 方式检查 sigmoid、tanh、门控和状态更新；
Transformer 测试以同样方式检查 Softmax、残差和最终输出。

生成与检查命令为：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel"
conda run -n tf_2_18 python \
  tools/export_keras_sequence_fixtures.py \
  --output tests/generated/keras_sequence_fixtures.h
conda run -n tf_2_18 python \
  tools/export_keras_sequence_fixtures.py \
  --check \
  --output tests/generated/keras_sequence_fixtures.h
make test
```

当前序列头文件 SHA-256 为
`f93790bf9b901b5c8c2ee9eecfd5f60fde490242f6f739a840e1ec740357b3d8`。
`make keras-e2e` 会依次重新训练 MLP 与四个序列网络、生成两份头文件，然后
编译并运行全部 C 回归。

`test_keras_sequence_inference.c` 不只比较最终输出。Transformer 会逐项核对
Q、K、V、注意力输出、两层 FFN 和分类层共 7 个 Dense 投影的 INT32
累加值与 INT8 输出，并检查 BMM 注意力分数、Softmax、上下文、两次残差、
平均池化和最终 logits。测试还会对 C model 的三分类 logits 执行 `argmax`，
并确认两个固定样本的结果既等于正确类别 `[0, 2]`，也等于 Keras 的预测。

SimpleRNN、GRU 与 LSTM 会分别核对每个时间步的输入投影和循环投影，然后检查
`tanh`、`sigmoid`、门乘法、状态更新及最终 hidden。测试把 C model 的 INT8
输出按 scale 还原为浮点数，计算它们相对于独立测试目标的完整序列 MSE，并
要求该值小于 0.0391055681 的历史基准。C model 的末步输出也必须至少有一个
分量之差大于 0.005，正确配对误差必须小于交换配对误差，末步误差还必须小于
0.0196325909 的共享输出基准。这样既检查逐层数值，也检查整数推理是否确实
使用了各自的历史信息。

### 10.3 本次模型检查结果

> [!success] 检查结论
> 2026-07-26 在 `tf_2_18` conda 环境中重新训练并检查全部模型。TensorFlow
> 版本为 2.18.0，Keras 版本为 3.6.0。MLP、Transformer、SimpleRNN、GRU
> 和 LSTM 的训练、测试数据生成、TFLite 推理及 C model 推理均通过。

| 检查对象 | 实际执行内容 | 结果 |
| --- | --- | --- |
| 两层 MLP | Keras 训练、72 个固定样本、两层 Matrix 推理、INT8 隐藏层和 INT32 logits 逐项比较 | PASS |
| Transformer | 12 条客户文本训练、两个新词序固定样本、TFLite Interpreter、逐层整数结果及 C logits `argmax=[0,2]` | PASS |
| SimpleRNN | 32 条遥测序列训练、2 条独立测试、TFLite Interpreter、4 个时间步的投影、`tanh`、hidden 更新及 C 测试 MSE | PASS |
| GRU | 32 条遥测序列训练、2 条独立测试、TFLite Interpreter、三组门、hidden 更新及 C 测试 MSE | PASS |
| LSTM | 32 条遥测序列训练、2 条独立测试、TFLite Interpreter、四组门、cell、hidden 更新及 C 测试 MSE | PASS |
| 时间依赖检查 | 两条独立测试序列末步输入相同；检查输出差异、历史配对和共享输出基准 | PASS |
| 测试数据重复生成 | 使用固定种子重新训练并执行 `--check` | PASS |

四个序列网络的结果摘要如下：

| 网络 | 训练结果 | 独立测试结果 | TFLite 状态 | TFLite 最大绝对误差 | C model |
| --- | --- | --- | ---: | ---: | --- |
| Transformer | 交叉熵 1.10277689 → 0.32323018 | 训练准确率 1.0；固定样本准确率 1.0 | 1 | 0.0135588646 | PASS |
| SimpleRNN | MSE 0.0414074771 → 0.00277871406 | 完整 0.00415767729；末步 0.00645086681 | 2 | 0.00579634309 | PASS |
| GRU | MSE 0.0943286568 → 0.00495296204 | 完整 0.00498581165；末步 0.00178855180 | 2 | 0.00422267057 | PASS |
| LSTM | MSE 0.100128189 → 0.0320885554 | 完整 0.0179846659；末步 0.0135771688 | 2 | 0.00316065270 | PASS |

SimpleRNN、GRU 和 LSTM 使用 Select TF Ops，是因为 TensorFlow 2.18 导出的
循环层图中含有 TensorList，严格的内置整数算子转换无法处理这些节点。后备
模型已经由 TFLite Interpreter 实际执行，表中的误差来自其输出与训练后
Keras 输出的逐项比较，因此该状态不是“只完成文件转换但没有运行模型”。

最终 C 回归结果：

| 检查方式 | 结果 |
| --- | ---: |
| GCC C11，`-Wall -Wextra -Wpedantic -Werror` | 40 / 40 PASS |
| Clang C11，`-Wall -Wextra -Wpedantic -Werror` | 40 / 40 PASS |
| AddressSanitizer + UndefinedBehaviorSanitizer | 40 / 40 PASS |
| 独立 wire 端到端测试 | PASS |
| 序列测试头文件 SHA-256 | `f93790bf9b901b5c8c2ee9eecfd5f60fde490242f6f739a840e1ec740357b3d8` |

检查结束后已经删除测试产生的 `build*` 目录，并再次执行 `make clean`。

### 10.4 如何运行 C model 推理

#### 10.4.1 使用 `model-infer` 查看逐样本推理结果

`Makefile` 提供 `model-infer` 入口。它会编译独立的 C 推理查看程序，并根据
`MODEL` 选择要运行的网络：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel"

make model-infer MODEL=transformer
make model-infer MODEL=simple_rnn
make model-infer MODEL=rnn
make model-infer MODEL=gru
make model-infer MODEL=lstm
make model-infer MODEL=all
```

`MODEL=simple_rnn` 和 `MODEL=rnn` 是同一个 SimpleRNN 的两个名称。
`MODEL=all` 会依次运行 Transformer、SimpleRNN、GRU 和 LSTM。由于
`MODEL` 的默认值就是 `all`，下面的短命令具有相同效果：

```bash
make model-infer
```

默认生成的可执行文件是 `build/model_infer`。编译过一次后，也可以绕过
Makefile 直接传入模型名称：

```bash
./build/model_infer transformer
./build/model_infer simple_rnn
./build/model_infer rnn
./build/model_infer gru
./build/model_infer lstm
./build/model_infer all
```

程序只接受
`transformer|simple_rnn|rnn|gru|lstm|all` 中的一个名称。名称无效或缺少
参数时，程序打印使用说明并以非零状态退出。若通过
`make BUILD_DIR=其他目录 model-infer MODEL=gru` 指定了构建目录，可执行文件
也会放到该目录下，而不是默认的 `build/`。

> [!note] 这不是只打印头文件中的参考值
> 程序会先调用 C model 执行选定网络的完整推理。模型张量使用整数；激活函数
> 等复杂计算按照 `INT → FP → INT` 处理。只有完整网络检查通过，才会打印 C
> 输出、Keras 参考值和统计结果；失败时会报告对应的 C 源码行号并返回非零
> 状态。

#### 10.4.2 `model-infer` 输出字段

Transformer 会为每个固定样本打印：

| 字段 | 含义 |
| --- | --- |
| `text` | 固定短文本 |
| `token_ids` | 4 个 token 编号，未占用位置以编号 0 的 `pad` 补足 |
| `INT8` | C model 得到的三类原始 INT8 logits |
| `de-scaled` | 使用输出 scale 和 zero point 还原后的 C logits |
| `Keras` | 训练后 Keras 网络的 FP32 logits |
| `true_class` | 正确类别编号和类别名称 |
| `C_predicted` | C logits 最大分量对应的类别 |
| `Keras_pred` | Keras logits 最大分量对应的类别 |

所有样本之后还会打印 C 固定样本准确率、Keras 固定样本准确率、Keras 训练
准确率、TFLite 状态、TFLite 相对 Keras 的最大绝对误差及允许上限。当前只有
两个 Transformer 固定样本，分别属于类别 0 和类别 2，所以
`C_fixed_accuracy: 2/2` 只说明这两个样本分类正确，不表示 C 固定输入已经
检查全部三个类别。

循环网络会为每个样本的每个时间步打印：

| 字段 | 含义 |
| --- | --- |
| `input_features` | 当前归一化温度、归一化负载和当日运行周期正弦值 |
| `target` | 由带历史状态的递推式生成的三个回归目标 |
| `C_prediction_INT8` | C model 的三个原始 INT8 输出 |
| `C_prediction` | 按输出 scale 和 zero point 还原后的三个 C 预测值 |
| `Keras_reference` | Keras 对同一个样本和时间步给出的 FP32 结果 |
| `sample_MSE` | 当前样本全部 4 个时间步、每步 3 个输出的 C 均方误差 |

全部时间步打印完成后，`C_regression_metrics` 给出：

| 指标 | 计算含义 |
| --- | --- |
| `MSE` | 24 个 C 预测值与目标值之差平方的平均值 |
| `RMSE` | $\sqrt{\mathrm{MSE}}$，与回归目标采用相同数值尺度 |
| `MAE` | 24 个绝对误差的平均值 |
| `max_abs_error` | 24 个绝对误差中的最大值 |
| `R_squared` | $1-\frac{\sum(\widehat y-y)^2}{\sum(y-\overline y)^2}$；1 表示完全一致，也可能小于 0 |
| `final_step_MSE` | 两个独立测试样本最后一个时间步的 6 个输出所对应的 MSE |

`Keras_fixed_metrics` 给出 Keras 在两条独立测试序列上的完整 MSE 与末步 MSE。
`baselines` 给出沿用上一目标的完整序列基准和相同当前输入的共享末步输出基准。
`Keras_training_MSE` 给出训练前后 MSE、更新次数和 32 条训练样本。
`TFLite` 行记录 TFLite 相对 Keras 的最大绝对误差及允许上限。逐时间步的
`Keras_reference` 用于比较 C 与 Keras；TFLite 行是离线导出脚本实际执行
TFLite Interpreter 后保存的整体结果，并不是把 C 输出与 TFLite 输出直接
相减。

分类准确率不适用于 SimpleRNN、GRU 和 LSTM。它们输出的是温度、负载和趋势等
连续数值，没有离散类别标签，也没有把连续值转成类别的阈值。对这类回归任务，
应查看 MSE、RMSE、MAE、最大绝对误差、$R^2$、末步 MSE 以及两项基准。

下面是实际输出的紧凑节选：

```text
sample[0]
  text: "great good good"
  token_ids: [2, 1, 1, 0]
  class[0] positive_review: INT8=49, de-scaled=2.0094234, Keras=2.0167394
  true_class:  0 (positive_review)
  C_predicted: 0 (positive_review)
C_fixed_accuracy: 2/2 = 1.0000000

=== simple_rnn: device telemetry sequence regression ===
sample[0]
  time_step[3]
    input_features:    [0.3000000, 0.2000000, 0.2500000]
    target:            [-0.0018059, -0.0691984, 0.0305752]
    C_prediction:      [0.0779177, 0.0440404, 0.1287336]
    Keras_reference:   [0.0809900, 0.0405704, 0.1313513]
C_regression_metrics
  MSE:            0.00411100923
  RMSE:           0.0641171524
  MAE:            0.0543156669
  max_abs_error:  0.113238893
  R_squared:      0.881847053
  final_step_MSE: 0.0064508203
classification_accuracy: not applicable (state-dependent regression)
```

上面只保留少量行以说明格式；命令实际会打印 Transformer 的每个固定样本，或
循环网络的每个独立测试样本和全部时间步。使用 `MODEL=all` 时，四个网络的
完整内容会连续输出。

#### 10.4.3 运行仓库中保存的全部测试

这种方式不需要安装 TensorFlow，也不会重新训练网络。进入 `cmodel` 目录后
执行：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel"
make test
```

`make test` 会编译 C model、生成 `build/test_npu_cmodel`，然后运行全部
主测试。模型推理对应以下两行：

```text
[PASS] keras_mlp_inference
[PASS] keras_sequence_inference
```

其中：

- `keras_mlp_inference` 运行两层 MLP；
- `keras_sequence_inference` 依次运行 Transformer、SimpleRNN、GRU 和
  LSTM，并检查逐层结果、分类结果、回归误差和时间依赖结果；
- 最后一行的失败数为 0，表示全部 C model 测试通过；测试总数会随新增检查项
  增加。

编译完成后，如果源文件和测试头文件都没有改变，可以直接再次运行可执行文件：

```bash
./build/test_npu_cmodel
```

> [!note] 固定输入保存在哪里
> C 可执行文件不是交互式文本程序，不从命令行读取句子或遥测数值。Transformer
> 和循环网络的输入、权重及期望结果已经写入
> `tests/generated/keras_sequence_fixtures.h`。因此，直接运行测试程序得到的
> 是当前固定样本的推理结果检查。

#### 10.4.4 重新训练并运行 C model

如果需要从 Keras 训练开始，重新生成整数测试数据，再运行 C model，请确认
`tf_2_18` conda 环境可用，然后执行：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel"
make keras-e2e
```

该命令依次完成：

1. 在 `tf_2_18` 中训练两层 MLP；
2. 训练 Transformer、SimpleRNN、GRU 和 LSTM；
3. 运行 TFLite Interpreter；
4. 重新生成 `tests/generated/keras_mlp_fixture.h` 和
   `tests/generated/keras_sequence_fixtures.h`；
5. 编译并运行全部 C model 测试。

控制台出现 `[PASS] keras_sequence_inference`，且末行失败数为 0，表示四个
序列网络的 C model 推理及其他测试均已通过。测试总数会随新增检查项增加。

#### 10.4.5 使用自己的固定输入

要更换输入，需要先修改生成脚本，再重新生成测试头文件：

- Transformer 固定文本在
  `tools/export_keras_sequence_fixtures.py` 的 `build_transformer()` 中定义；
- 设备遥测固定序列在同一文件的 `recurrent_input()` 中定义；
- 回归目标由 `recurrent_forecast_targets()` 按递推公式计算；
- C 端的完整推理检查位于 `tests/test_keras_sequence_inference.c`。

修改后执行：

```bash
make keras-e2e
```

如果只想确认现有头文件能由脚本完全重复生成，可以执行：

```bash
conda run -n tf_2_18 python \
  tools/export_keras_sequence_fixtures.py \
  --check \
  --output tests/generated/keras_sequence_fixtures.h
```

`--check` 不会改写头文件；脚本计算出的内容与现有文件不同，或模型结果不满足
误差限制和应用检查时，命令会返回失败。

### 10.5 离线导出 Keras 与 TFLite 模型

`tools/compile_keras_model.py` 是单独的离线导出入口。它重新建立并训练仓库中
定义好的应用模型，为每个选中模型写出 Keras archive、可由 TFLite
Interpreter 运行的 `.tflite` 文件和一份 JSON 清单。该脚本需要 TensorFlow，
建议使用本文已经检查过的 `tf_2_18` 环境。

#### 10.5.1 命令格式

最短的调用方式是使用 Makefile：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel"

make model-compile MODEL=transformer
make model-compile MODEL=simple_rnn
make model-compile MODEL=rnn
make model-compile MODEL=gru
make model-compile MODEL=lstm
make model-compile MODEL=all
```

`MODEL` 默认是 `all`，所以 `make model-compile` 会导出全部四个模型。Makefile
默认调用 `tf_2_18` conda 环境，并把文件写入 `build/model-compiler`。可以用
`MODEL_COMPILER_OUTPUT_DIR` 更换目录：

```bash
make model-compile \
  MODEL=gru \
  MODEL_COMPILER_OUTPUT_DIR=/tmp/gru-export
```

导出成功后，使用相同的 `MODEL` 和输出目录执行检查：

```bash
make model-compile-check MODEL=transformer

make model-compile-check \
  MODEL=gru \
  MODEL_COMPILER_OUTPUT_DIR=/tmp/gru-export
```

如果 conda 命令或环境名称不同，可以通过 `CONDA` 和 `KERAS_CONDA_ENV` 覆盖
Makefile 的默认值。

直接运行脚本时，实际命令格式为：

```text
python tools/compile_keras_model.py \
  --model {transformer,simple_rnn,rnn,gru,lstm,all} \
  [--output FILE.json | --output-dir DIR] \
  [--check]
```

直接脚本方式额外支持 `--output`，适合明确指定 JSON 清单文件名。例如：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel"

conda run -n tf_2_18 python tools/compile_keras_model.py \
  --model transformer

conda run -n tf_2_18 python tools/compile_keras_model.py \
  --model rnn \
  --output-dir build/rnn-export

conda run -n tf_2_18 python tools/compile_keras_model.py \
  --model gru \
  --output build/device-gru.json

conda run -n tf_2_18 python tools/compile_keras_model.py \
  --model all
```

`rnn` 是 `simple_rnn` 的别名。`all` 按 Transformer、SimpleRNN、GRU、LSTM
的次序导出全部四个模型。`--output` 和 `--output-dir` 互斥；
`--output` 必须以 `.json` 结尾，因为它指定的是 JSON 清单路径，不是 Keras
文件或 TFLite 文件路径。

#### 10.5.2 产物名称与内容

不指定输出位置时，单模型文件写入 `build/model-compiler/`：

| 命令中的模型 | 默认产物 |
| --- | --- |
| `transformer` | `transformer.json`、`transformer.keras`、`transformer.tflite` |
| `simple_rnn` 或 `rnn` | `simple_rnn.json`、`simple_rnn.keras`、`simple_rnn.tflite` |
| `gru` | `gru.json`、`gru.keras`、`gru.tflite` |
| `lstm` | `lstm.json`、`lstm.keras`、`lstm.tflite` |
| `all` | `all.json`，以及 `all_transformer.*`、`all_simple_rnn.*`、`all_gru.*`、`all_lstm.*` 四组 `.keras` 和 `.tflite` 文件 |

例如，`--model gru --output /tmp/device-gru.json` 会在 `/tmp` 中生成
`device-gru.json`、`device-gru.keras` 和 `device-gru.tflite`。对
`--model all --output /tmp/device-models.json`，四组模型文件分别以
`device-models_transformer`、`device-models_simple_rnn`、
`device-models_gru` 和 `device-models_lstm` 开头。

三类产物的用途如下：

| 产物 | 内容与用途 |
| --- | --- |
| `.keras` | 训练后的 Keras 模型结构与权重，可由 Keras 重新载入并执行 |
| `.tflite` | 已实际通过 TFLite Interpreter 检查的运行文件 |
| `.json` | 导出环境、模型名称、随机种子、文件 SHA-256、输入输出形状与 dtype、TFLite 转换方式、scale、zero point、误差上限及任务指标 |

Transformer 的 JSON 指标还包含类别名、词表、固定文本、token 编号、真实类别、
预测类别和 Keras logits。循环网络的 JSON 指标包含输入与输出名称、两条独立
测试序列、目标、Keras 预测、训练 MSE、完整与末步测试 MSE、两项基准，并把
`accuracy` 写为 `null`，同时说明分类准确率不适用于回归。

脚本结束时会打印 TensorFlow 与 Keras 版本、实际导出的模型、每个文件的
SHA-256，以及各 TFLite 文件的状态、最大绝对误差和允许上限。

#### 10.5.3 使用 `--check` 检查现有产物

先执行一次正常导出，再使用完全相同的模型名称和输出位置追加 `--check`：

```bash
conda run -n tf_2_18 python tools/compile_keras_model.py \
  --model transformer

conda run -n tf_2_18 python tools/compile_keras_model.py \
  --model transformer \
  --check
```

`--check` 不写文件。它会重新建立确定性的内存参考模型，逐个检查现有 Keras
文件的权重和输出，实际运行现有 TFLite 文件，核对误差、输入输出元数据和
JSON 清单。缺少任何一个产物、权重或输出不同、TFLite 误差超限，或者 JSON
内容不同，命令都会返回失败。使用自定义目录或 JSON 路径时，检查命令也必须
再次给出相同的 `--output-dir` 或 `--output`。

#### 10.5.4 离线导出与 C 推理是两个独立步骤

`compile_keras_model.py` 只生成 `.keras`、`.tflite` 和 `.json`，不会生成或
改写 `tests/generated/keras_sequence_fixtures.h`。JSON 中也会明确记录：
C 推理程序使用仓库中另行生成并保存的 fixture 头文件。

`make model-infer` 不读取 `.keras` 或 `.tflite` 文件。它编译
`tests/test_keras_sequence_inference.c`，使用
`tests/generated/keras_sequence_fixtures.h` 中的固定输入、权重、scale、
zero point 和参考值执行 C 推理。因此：

1. 需要给 Keras 或 TFLite 运行环境交付模型时，使用
   `compile_keras_model.py`；
2. 需要查看当前 fixture 对应的 C 推理时，使用 `make model-infer`；
3. 需要重新生成 C fixture 并重新检查 C model 时，使用 `make keras-e2e`。

> [!warning] 当前脚本不是通用 Keras 图编译器
> 它只支持仓库中已经写好的 Transformer、SimpleRNN、GRU 和 LSTM 四种固定
> 结构，也不包含两层 MLP。脚本没有“输入任意 `.keras` 文件”的参数，不能把
> 用户提供的任意 Keras 网络自动变成 C model 可执行数据。若增加新网络结构，
> 还需要为其补充模型建立函数、整数算子处理、fixture 生成、C 执行代码和数值
> 检查。

#### 10.5.5 通用高层编译器与 Transformer 部署

上面的限制只针对 `tools/compile_keras_model.py`。真正负责高层模型图编译的
程序是 `../compiler/npu_model_compiler.py`；低层编码程序是
`../compiler/npu_assembler.py`。前者从张量和语义算子生成存储计划、任务依赖、
DMA、Matrix、Vector 与 Complex 任务，后者把低层 JSON IR 编码为 CMD128 和
Descriptor。

模型编译器的默认部署结果不是一组裸二进制文件，而是：

- `<stem>_model.h`：C 类型、数组声明、设备地址和数量常量；
- `<stem>_model.c`：C 配置、CMD128、Descriptor、权重和运行信息；
- `<stem>.manifest.json`：文件摘要与编译信息。

主机程序编译生成的 `.c` 文件并包含对应 `.h` 文件，即可取得提交所需的全部
内容。裸 `.cmd.bin`、`.desc.bin`、`.const.bin`、`.runtime.json` 和低层
JSON IR 只在显式传入 `--emit-raw` 时额外生成，用于分析编译结果或单独检查
汇编器，不是默认部署输入。

当前采用 INT8 的可执行入口位于
[`examples`](examples/README.md)，包含 RNN、GRU、LSTM 和 CNN 四个独立
模型。每个示例都由 Keras 模型开始，调用通用高层编译器生成 C 配置、CMD128、
Descriptor、权重和输入输出信息，再由分文件 C 驱动提交到本 CModel。

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel/examples"
make clean
make test
```

这些示例中的驱动调用都表示外部主控 CPU 主动操作 NPU。主控 CPU 是 AXI
Master；NPU 的固定地址命令 FIFO、控制寄存器和 L1BUF 外部窗口是 AXI Slave 目标。
Generic Core 不属于 NPU，C model 中的 CPU 侧测试部件也不应当被理解为 NPU
内部硬件。

完整的多编译器和内存检查运行方式为：

```bash
make regress
```

## 11. 模型用途限制

当前 MIF 与 System Slave 模型会生成并检查逐信号 AXI 波形；L1BUF 和
Descriptor SRAM 支持按 word 注入已修正或不可修正 ECC 状态。测试覆盖
ready/valid 随机暂停、响应乱序、错误状态和复位。

`npu_single_core_cycle_core_tick()` 和 `npu_single_core_cycle_noc_tick()` 已经
提供 NPU 与外部 CPU 测试部件的双时钟联合仿真接口。当前测试覆盖 NPU AXI
Slave 与 L1BUF 外部窗口访问、外部 CPU AXI 读取、CFE 接收、向量任务、
Engine Data 的 MIF 读写、Core/NoC
异步 FIFO、内部 TBU 权限检查、MIF 错误同步、受控复位、CRG 和 WDT。另有
`test_mif_tbu_cycle.c` 单独检查 TBU 地址转换、权限错误及 MIF 发出 AXI 请求
的先后次序。`test_single_core_axi_target.c` 使用不同的 Core/NoC tick 节奏，
把外部 CPU 测试部件和 MIF 的 AXI Master 接到测试环境，检查外部 CPU 单拍读取，
以及 Descriptor Fetch 经内部 TBU、MIF 和 8+16 beat AXI burst 取得 192B
描述符后完成 Vector 任务。

联合仿真接口把 NPU MIF 和外部 CPU 测试部件的 AXI Master 信号交给调用者。
`npu_axi_mem_target_cycle` 不作为 NPU 的内部成员；测试环境可在系统总线模型
中连接这些 Master 与存储目标，也可接入自定义 NoC 模型。
`npu_engine_cycle` 仍应视为“信号级控制接口加功能级数据执行”的
组合模型；需要观察逐 beat 数据请求时应使用 `npu_engine_data_cycle`，并结合
L1BUF、MIF 和 AXI 存储目标判断各端口的周期行为。
