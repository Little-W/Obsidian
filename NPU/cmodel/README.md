# 单核 NPU CModel

本目录提供《NPU 指令与硬件架构设计 Spec》的 C11 参考模型。当前部署协议使用
CMD128：一条 128 bit 命令包含公共字段和全部执行参数，不含
`desc_addr`，也不读取外部任务参数块。CFE/TS 在模型内部保存收到的 16 byte
Task Context，再把字段展开给 DMA、Matrix、IVE 或 CME。

模型分为三层：

1. INT4/INT8/INT16/INT32、舍入、饱和和 FP32 近似函数；
2. DMA、Matrix、Vector、Complex 功能算子；
3. CMD 两拍接收、Task/Event、执行单元、L1BUF、TBU、MIF、AXI 与单核周期模型。

软件可见张量只使用 INT4、INT8、INT16、INT32。FP32 仅存在于 Complex
算子的内部计算和私有暂存。

> [!important]
> Generic Core 是 NPU 外部的 CPU。真实 SoC 中，CPU 通过 NPU 的 64 bit
> AXI Slave 访问固定命令地址、CSR、命令响应 FIFO 和 L1BUF 窗口。MIF 是
> NPU 的 64 bit AXI Master，连接 SoC Fabric；DDR 是系统总线上的存储目标。
> MIF 请求只用于 DMA 全局张量、权重、输入输出、工作区和 KV 数据，
> 不用于读取任务参数。

## 1. 参考配置

| 项目 | 数值 |
| --- | ---: |
| Core 数 | 1 |
| 数据接口 | 64 bit |
| L1BUF | 1 MiB |
| L1 bank 数 | 16 |
| L1 读延迟 | 2 cycles |
| Matrix `MT/KT/NT` | 8 / 16 / 8 |
| IVE lane 数 | 8 |
| CME FP32 lane 数 | 4 |
| CME 私有暂存 | 4096 FP32 元素 |
| Task 项数 | 32 |
| Event 项数 | 255 |
| CFE FIFO 深度 | 8 |
| DMA 最大未完成请求 | 16 |
| MIF 最大未完成事务 | 16 |
| DMA 最大 burst | 16 个 64 bit beat |
| CMD 宽度 | 128 bit |
| CMD 物理传输 | 低 64 bit 后高 64 bit |
| CFE 第二拍等待上限 | 32 cycles |

`npu_config_reference()` 和 `npu_wire_limits_reference()` 填入参考值。调用者可在
头文件静态上限内调整功能模型参数。组合周期模型还会检查
`npu_config_t`、`npu_wire_limits_t`、`npu_lsc_cycle_config_t`、L1BUF 与
MIF 固定配置是否一致；失败返回 `NPU_STATUS_BAD_DESC`，不修改目标实例。

模型不调用 `malloc`、`calloc` 或 `realloc`。L1、系统存储、ECC 和执行单元
workspace 都由调用者提供并保持所有权。

## 2. 目录与文件

### 2.1 本目录

| 路径 | 内容 |
| --- | --- |
| `include/npu_cmodel.h` | dtype、状态码、任务结构、功能模型公开 API |
| `include/npu_wire.h` | 16 byte CMD 解码和 Descriptor 诊断 API |
| `src/npu_inline.[ch]` | CMD128 opcode 与 payload 展开 |
| `src/npu_wire.c` | CMD 公共头、little-endian 与严格字段检查 |
| `src/npu_frontend.c` | 功能模型的 CMD 低/高两拍接收 |
| `src/npu_core.c` | Task、Event、发射、timeout、查询与 ACK |
| `src/npu_integer.c` | INT4、整数读写、舍入和饱和 |
| `src/npu_dma.c` | COPY、FILL、TRANSPOSE、PACK、SPLIT |
| `src/npu_matrix.c` | GEMM、BMM、ACCUM、ZERO、bias、整数重缩放 |
| `src/npu_vector.c` | ADD、SUB、MUL、FMA、MAX、MIN、CMP、SELECT、CLAMP、RELU |
| `src/npu_math.c` | Exp、Reciprocal、Rsqrt、Sigmoid、Tanh、GELU、SiLU |
| `src/npu_complex.c` | ACT、SOFTMAX、NORM、STAT、ADD_RESCALE |
| `include/src/npu_cfe_cycle.*` | CFE ready/valid、两拍组装、ID 查询和接收响应 |
| `include/src/npu_ts_cycle.*` | Task/Event、CMD128 展开、发射、完成与 Descriptor 诊断支路 |
| `include/src/npu_engine_cycle.*` | 四类执行单元周期适配器 |
| `include/src/npu_engine_data_cycle.*` | 算子访问记录与逐 beat L1/MIF 组合 |
| `include/src/npu_l1_cycle.*` | 13 读端口、5 写端口、16 bank、ECC |
| `include/src/npu_l1_diag_bridge.*` | AXI Slave 请求到 L1 Debug 端口的桥 |
| `include/src/npu_tbu_cycle.*` | 地址规则、权限、响应延迟和错误 |
| `include/src/npu_mif_cycle.*` | TBU、未完成事务、64 bit AXI Master |
| `include/src/npu_mif_cdc_cycle.*` | Core/NoC 请求、写数据、响应异步 FIFO |
| `include/src/npu_axi_mem_target_cycle.*` | 64 bit AXI4 存储目标周期模型 |
| `include/src/npu_sys_slave_cycle.*` | 64 bit AXI4 Slave、CMD/响应 FIFO、L1 窗口 |
| `include/src/npu_lsc_cycle.*` | CSR、首错、中断、性能计数、受控复位 |
| `include/src/npu_control_cycle.*` | CRG 与 WDT |
| `include/src/npu_core_top_cycle.*` | CFE、TS、四执行单元与 LSC 的 Core 域组合 |
| `include/src/npu_single_core_cycle.*` | Core/NoC 双时钟单核组合 |
| `include/src/npu_bus_trace.*` | 功能算子的 64 bit 数据访问记录 |
| `include/src/npu_bus_replay_cycle.*` | 访问记录到 L1/MIF ready/valid 传输 |
| `include/src/npu_issue_adapter_cycle.*` | 外部 CPU 侧联合测试适配器，不是 NPU RTL 端口 |
| `include/src/npu_gc_axi_cycle.*` | 外部 CPU 的 AXI 测试部件 |
| `tests/` | 数值、CMD128、算子、事件、AXI、TBU、MIF 和模块周期测试 |
| `tools/` | 固定 Keras 应用 fixture 与 Keras/TFLite 导出工具 |
| `examples/` | RNN、GRU、LSTM、CNN 的生成、编译、驱动和 CModel 推理示例 |

模型编译器与驱动位于同级 NPU 目录：

| 路径 | 内容 |
| --- | --- |
| `../compiler/` | Keras、PyTorch、TFLite、ONNX 前端和 CMD128 汇编器 |
| `../driver/` | AXI 提交、WAIT、ACK、任务组同步和模型 C 包支持 |

### 2.2 关键测试

| 测试 | 检查内容 |
| --- | --- |
| `tests/test_inline.c` | 33 个操作码、CMD128 公共字段、DMA/Matrix/Vector/Complex payload、TS 不读取外部任务参数 |
| `tests/test_wire.c` | CMD 与诊断格式字段检查 |
| `tests/test_wire_e2e.c` | Descriptor 诊断端到端测试 |
| `tests/test_ops.c` | 功能算子基本结果 |
| `tests/test_dma_acceptance.c` | DMA 合法/非法组合 |
| `tests/test_matrix_acceptance.c` | Matrix dtype、shape、bias 和错误 |
| `tests/test_vector_acceptance.c` | Vector broadcast、CMP、SELECT、CLAMP |
| `tests/test_complex_acceptance.c` | Complex 函数、mask、scale 和 strict numeric |
| `tests/test_dtype_regression.c` | 四种整数 dtype 的系统组合 |
| `tests/test_matrix_tiles.c` | Matrix tile 与尾部有效元素 |
| `tests/test_matrix_pipeline.c` | Matrix 两阶段执行、地址检查和计数 |
| `tests/test_math_accuracy.c` | FP32 近似函数精度与特殊值 |
| `tests/test_properties.c` | 随机性质与不变量 |
| `tests/test_cfe_cycle.c` | 两拍 CFE、反压、第二拍 timeout、ID 查询 |
| `tests/test_ts_cycle.c` | Task/Event、取消、完成消息、查询与 ACK |
| `tests/test_engine_cycle.c` | 执行单元适配器、Context/诊断 SRAM 读取和 DONE |
| `tests/test_l1_cycle.c` | bank 仲裁、2-cycle 读、写响应和 ECC |
| `tests/test_tbu_cycle.c` | 地址规则、权限和错误 |
| `tests/test_mif_cycle.c` | MIF burst、AXI ID、错误及 Descriptor 诊断 owner |
| `tests/test_mif_cdc_cycle.c` | Core/NoC 异步 FIFO |
| `tests/test_sys_slave_cycle.c` | AXI Slave、CMD FIFO、响应 FIFO 和 L1 窗口 |
| `tests/test_single_core_cycle.c` | 双时钟单核组合 |
| `tests/test_single_core_axi_target.c` | 单核连接 AXI 存储目标 |

`test_main.c` 注册全部主测试，其中包含 `test_inline`。因此 `make test` 会执行
CMD128 字段和 payload 检查。

## 3. 构建与测试

无参数 `make` 等同于 `make all`，只构建，不运行测试。

| 命令 | 作用 | TensorFlow |
| --- | --- | ---: |
| `make all` | 构建 `build/libnpu_cmodel.a` 和 `build/test_npu_cmodel` | 否 |
| `make test` | 构建并运行全部主测试，包含 CMD128 | 否 |
| `make wire-e2e` | 单独运行 Descriptor 诊断测试 | 否 |
| `make model-infer MODEL=all` | 运行已有 Transformer、SimpleRNN、GRU、LSTM fixture | 否 |
| `make model-compile MODEL=all` | 导出固定应用的 `.keras`、`.tflite`、JSON | 是 |
| `make model-compile-check MODEL=all` | 核对已有固定应用导出文件 | 是 |
| `make keras-fixture` | 重新训练并改写 `tests/generated/*.h` | 是 |
| `make keras-e2e` | 重新生成 fixture 后运行主测试 | 是 |
| `make sanitize` | 在 `build-sanitize` 中运行 ASan 与 UBSan | 否 |
| `make clean` | 删除普通和 sanitizer 构建目录 | 否 |

常用命令：

```bash
cd "/home/yusen/Obsidian Vault/NPU/cmodel"
make all
make test
make sanitize
```

`make clean` 会删除构建目录；`make keras-fixture` 会改写仓库内的两个 generated
头文件，因此只在确实需要重新生成 fixture 时执行。

Makefile 当前可用的主要变量：

| 变量 | 默认值 | 用途 |
| --- | --- | --- |
| `CC` | `cc` | C 编译器 |
| `AR` | `ar` | 静态库工具 |
| `BUILD_DIR` | `build` | 普通构建目录 |
| `SAN_BUILD_DIR` | `build-sanitize` | sanitizer 构建目录 |
| `MODEL` | `all` | `transformer`、`simple_rnn`、`rnn`、`gru`、`lstm`、`all` |
| `CONDA` | `conda` | conda 命令 |
| `KERAS_CONDA_ENV` | `tf_2_18` | TensorFlow 环境 |
| `MODEL_COMPILER_OUTPUT_DIR` | `$(BUILD_DIR)/model-compiler` | 固定应用导出目录 |

默认编译选项包括：

```text
-std=c11
-Wall -Wextra -Wpedantic -Werror
-fno-fast-math
-ffp-contract=off
-fexcess-precision=standard
```

主测试和固定模型推理链接 `libm`；静态库本身的公开近似函数实现不依赖调用者
启用 fast-math。

## 4. CMD128

### 4.1 公共头

| bit | 字段 |
| ---: | --- |
| 127:122 | opcode |
| 121:112 | command_id |
| 111:104 | wait0 |
| 103:96 | wait1 |
| 95:88 | signal |
| 87 | irq_success |
| 86 | irq_error |
| 85 | strict_numeric |
| 84 | ordered |
| 83:82 | timeout_class |
| 81:80 | dtype：0 INT4、1 INT8、2 INT32、3 INT16 |
| 79:0 | payload |

Event ID 0xff 表示 none。Event 字段只携带 ID；TS 在接收命令时从 Event
Table 取得 generation 并写入内部 Task Context。

`opcode` 字段宽度为 6 bit。当前定义的数值 0～32 依次为：

```text
NOP SIGNAL REARM JOIN FENCE
COPY1D COPYND FILL TRANSPOSE PACK SPLIT GATHER_ND
GEMM BMM ACCUM ZERO
ADD SUB MUL FMA MAX MIN CMP SELECT CLAMP RELU
ACT SOFTMAX NORM ROPE STAT RECIP ADD_RESCALE
```

数值 33～63 尚未定义，解码时返回
`NPU_STATUS_ILLEGAL_OPCODE`。

GATHER_ND、ROPE 和 RECIP 的功能位为 0，任务解码时返回
`NPU_STATUS_ILLEGAL_OPCODE`。

### 4.2 地址引用

- DMA AREF28：bit27 选择 L1/全局，bits26:24 选择
  zero/input/weight/work/output/kv 基址，bits23:0 是字节 offset。
- Matrix A/B/C：LREF14，字节地址为 `ref<<6`。
- Matrix bias：LREF12，字节地址为 `ref<<6`，ref=0 表示不用。
- Vector/Complex：LREF16，字节地址为 `ref<<4`。

Matrix bias 是 `[N]` INT32。`bias[j]` 加到输出第 `j` 列的全部 M 行。

### 4.3 CMD128 不访问外部任务参数

`npu_wire_decode_cmd*()` 按 CMD128 公共字段解码。
`npu_inline_decode_task()` 随后直接从 80 bit payload 建立内部
`npu_task_request_t`。TS 把收到的两个 64 bit word 放入内部
16 byte Context 存储，不进入外部任务参数读取状态。

这意味着：

- `npu_model_submit_wire()` 提交 CMD128 时不需要额外字节数组；
- `npu_wire_validate_cmd_address()` 不检查外部任务参数地址；
- `tests/test_inline.c` 的 `inline_test_ts_without_dfu` 检查 TS 不产生参数
  读取请求；
- 系统存储数组只承载 DMA 数据。

## 5. 功能模型 API

公开声明以 `include/npu_cmodel.h` 和 `include/npu_wire.h` 为准。

### 5.1 初始化

```c
npu_config_t config;
npu_model_t model;

npu_config_reference(&config);
npu_status_t status = npu_model_init(
    &model,
    &config,
    l1_memory,
    l1_bytes,
    system_memory,
    system_memory_bytes);
```

公开结构字段名仍为 `ddr`，它在 CModel 中表示调用者提供的系统存储数组，
不表示硬件有 DDR 专用端口。`npu_model_reset()` 清除调度状态和计数，不取得
或释放调用者内存。

### 5.2 CMD 编码与提交

`npu_cmd_t` 同时承载已解码 CMD128 和 Descriptor 诊断字段。构造 CMD128 时设置：

```c
npu_cmd_t cmd = {0};
uint64_t low;
uint64_t high;

cmd.inline_format = 1u;
cmd.engine = NPU_ENGINE_VECTOR;
cmd.opcode = NPU_VECTOR_ADD;
cmd.command_id = 7u;
cmd.wait_event[0] = npu_event_none();
cmd.wait_event[1] = npu_event_none();
cmd.signal_event = npu_event_none();
cmd.inline_dtype = NPU_DTYPE_INT8;
cmd.inline_payload_lo = payload_low_64;
cmd.inline_payload_hi = payload_high_16;

npu_cmd_encode(&cmd, &low, &high);
status = npu_model_submit_wire(&model, low, high);
```

`npu_cmd_encode()` 根据 `engine/opcode` 写入 6 bit `opcode` 字段；
`npu_cmd_decode()` 从两个 beat 恢复字段。若需要从 16 byte 数组解码并取得
更详细的地址错误信息，使用：

```c
npu_wire_limits_t limits;
npu_wire_meta_t meta;
npu_cmd_t decoded;

npu_wire_limits_reference(&limits);
status = npu_wire_decode_cmd_with_meta(
    command_bytes, NPU_WIRE_CMD_BYTES,
    &limits, &decoded, &meta);
```

`src/npu_inline.h` 是 CModel 内部头文件；部署程序通常使用编译器生成的
CMD128 数组，不应直接依赖内部展开函数。

### 5.3 推进、查询与 ACK

```c
npu_model_step(&model, cycles);
status = npu_model_run(&model, max_cycles);
int idle = npu_model_idle(&model);

npu_task_result_t result;
status = npu_model_query(
    &model, command_id, acknowledge, &result);
```

`acknowledge=0` 只读取结果；`acknowledge!=0` 在任务已到终态时释放 Task
项和 command_id。Event ID 复用前，主机要等待旧任务到终态并 ACK，然后
提交 REARM，等待其成功并 ACK，再提交使用新代次的任务组。

需要逐拍模拟 CPU 命令接口时使用 `npu_model_cycle_io()`；输入和输出结构是
`npu_host_inputs_t`、`npu_host_outputs_t`。

### 5.4 算子与数值 API

可单独调用：

```text
npu_dma_execute
npu_matrix_execute
npu_vector_execute
npu_complex_execute
npu_tensor_read
npu_tensor_write
npu_int4_unpack
npu_int4_insert
npu_round_shift
npu_cast_integer
npu_exp_approx
npu_reciprocal_approx
npu_rsqrt_approx
npu_sigmoid_approx
npu_tanh_approx
npu_gelu_approx
npu_silu_approx
npu_float_to_int
```

带 `_traced` 的 FP32 近似 API 还会返回 mode-0 检查点。算子 API 会先检查
dtype、形状、地址区域和不允许的重叠，再修改目标。

## 6. 模块周期 API

每个周期模型采用：

- 一个状态结构 `npu_*_cycle_t`；
- 一个 inputs 结构和一个 outputs 结构；
- `*_init()`/`*_reset()`；
- 每个上升沿调用一次 `*_step()` 或命名域的 `*_tick()`。

所有模块端口保持 64 bit 数据宽度，ready/valid 只有在同一调用表示的上升沿
同时为 1 才传输。发送方在反压时保持 data/tag/last/strb 不变。输入复位字段
统一写作 `reset_n`；单核顶层使用 `core_reset_n` 与 `noc_reset_n`。

### 6.1 CFE、TS、执行单元

```text
npu_cfe_cycle_reset / npu_cfe_cycle_step
npu_ts_cycle_init / npu_ts_cycle_reset / npu_ts_cycle_step
npu_engine_cycle_init / npu_engine_cycle_reset
npu_engine_cycle_eval / npu_engine_cycle_step
```

CFE 收低拍、高拍，检查 CMD128 公共字段并查询 command_id。TS 直接
展开 Context、登记事件、等待、发射和收三拍 DONE。执行单元适配器按
DMA/Matrix/Vector/Complex 绑定功能模型。

`npu_engine_cycle_eval()` 只计算当前组合输出，不提交状态，也不调用功能算子；
`npu_engine_cycle_step()` 才推进一个周期。

### 6.2 L1、TBU、MIF、AXI

```text
npu_l1_cycle_init / npu_l1_cycle_step
npu_tbu_cycle_init / npu_tbu_cycle_set_rule / npu_tbu_cycle_step
npu_mif_cycle_config_default / npu_mif_cycle_init / npu_mif_cycle_step
npu_axi_mem_target_cycle_init / npu_axi_mem_target_cycle_step
npu_sys_slave_cycle_init / npu_sys_slave_cycle_step
```

L1 参考模型有 13 个读端口和 5 个写端口，读延迟 2 cycles。MIF 接 TBU 并
作为 64 bit AXI Master；AXI 存储目标为测试提供可重复延迟和错误注入。
System Slave 模型实现固定 CMD 地址、响应 FIFO、CSR 请求和 L1 外部窗口。

### 6.3 单核双时钟组合

```text
npu_single_core_cycle_init
npu_single_core_cycle_reset
npu_single_core_cycle_core_tick
npu_single_core_cycle_noc_tick
```

Core 与 NoC 时钟独立推进。异步 FIFO 指针需要两个目标域 tick 才可见。
`npu_single_core_cycle_init()` 要求调用者提供 L1、ECC、四组 engine
workspace、wire limits、LSC 配置、MIF SoC 配置和 TBU 模式。

## 7. 模型编译器与示例

`../compiler/npu_model_compiler.py` 接收 Keras、PyTorch、TFLite、ONNX 或
高层 JSON；`../compiler/npu_assembler.py` 把低层 JSON IR 编成 CMD128。
默认生成：

```text
<model>_model.h
<model>_model.c
<model>.manifest.json
```

C 文件包含配置、CMD128 数组、权重/常量、输入输出/操作信息和任务组同步
信息。默认部署产物没有外部任务参数数组，也不默认生成裸二进制。编译器的
可选 raw 输出仍只包含 CMD、常量和运行信息，不生成任务参数文件。

Conv2D 会降低为 im2col/数据准备、DMA 排列和 GEMM；必要时允许 CPU 辅助。
RNN、GRU、LSTM 与 Transformer 由 Matrix、Vector、Complex 和 DMA 组合。

### 7.1 四个驱动示例

| 示例 | 目录 | 运行 |
| --- | --- | --- |
| RNN | `examples/rnn` | `make -C examples/rnn test` |
| GRU | `examples/gru` | `make -C examples/gru test` |
| LSTM | `examples/lstm` | `make -C examples/lstm test` |
| CNN | `examples/cnn` | `make -C examples/cnn test` |

一次运行：

```bash
make -C examples test
```

这些示例依赖 TensorFlow 环境、`../compiler/` 和 `../driver/`。各自的
`example.mk` 先生成 Keras/JSON 输入，再生成模型专用 `.c/.h` 和 manifest，
构建驱动后通过固定 CMD 地址提交 CMD128。CNN 直接输入 `.keras`；循环网络先生成
单时间步高层 JSON。当前 GRU/LSTM 的部分状态乘法可由主机辅助，因为 Vector
MUL 写 INT32，而后续状态输入为 INT8。

## 8. Descriptor 诊断支持

源码和测试保留外部任务参数块、Descriptor Fetch Unit（DFU）、参数 SRAM
及相关 MIF owner，用于 ECC、仲裁和错误注入测试。这些结构只在测试显式打开
`descriptor_diagnostic_mode` 时使用，不属于模型部署输入。

- `tests/test_inline.c` 检查 CMD128，其中包含 TS 不发任务参数读取请求的测试。
- `tests/test_wire_e2e.c` 与 `make wire-e2e` 检查 Descriptor 诊断功能。
- 编译器、驱动和 examples 的产物使用 `cmd128`，不生成外部任务参数数组。

部署功能以 `make test` 中的 CMD128 测试和各模型 example 为主；运行
`make wire-e2e` 可额外检查 Descriptor 诊断功能。

## 9. 提交问题时的最小信息

建议附上：

- 失败命令的两个 64 bit beat 和 command_id；
- `npu_task_result_t` 的 status、fault_addr、error_info、done_flags；
- 参考配置与改动过的 limits；
- 失败测试名和编译器；
- 若为周期问题，附 ready/valid、tag、last 的相邻周期记录；
- 若为数值问题，附 dtype、shape、scale、输入和期望整数结果。

不要只提供系统存储快照并假定存在任务参数数组；执行参数就在
CMD128 中。
