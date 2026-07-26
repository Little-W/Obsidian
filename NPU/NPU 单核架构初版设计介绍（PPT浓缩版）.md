# NPU 单核架构初版设计介绍

> [!info] 文档用途
> 本文是面向 PPT 的架构摘要，集中说明单核首版的设计目标、指令、硬件模块、重点算子和软件分层。详细字段、模块接口与周期时序以《NPU 指令与硬件架构设计 Spec》为准。

> [!tip] PPT 排版参数
> 页面建议采用竖版。页标题不小于 30 pt，二级标题不小于 24 pt，正文不小于 18 pt，表格文字不小于 16 pt。表格单元格的上下、左右内边距均建议保留 0.18 cm 以上，文字采用垂直居中，不能贴到表格线。图中同一行的方框尽量等高并垂直居中；模块标题、说明文字与方框四周保留明显空白。架构图按原宽高比例缩放并置于页面中央，不要拉伸；若一页内容过多，应拆页，不应缩小文字。

---

## 第 1 页：设计目标

- 面向 Transformer、RNN、LSTM、GRU 和回归模型的整数推理，兼顾自然语言处理与时序数据分析。
- 首版采用单核结构：一个 Matrix Engine、一个 Integer Vector Engine、一个 Complex Math Engine 和一个 DMA / Layout Engine。
- 模型输入、权重、中间张量和输出支持 `INT4`、`INT8`、`INT16`、`INT32`。其中 INT4/INT8 侧重吞吐与容量，INT16 为回归输入、权重和输出提供更细的数值间隔，INT32 用于矩阵累加、bias 和较大范围的中间结果。
- 外部系统总线和模块间数据接口均以 64 bit 为一个 beat；一条 128-bit 命令分成低、高两个 beat 发送。
- 通过事件、TaskScheduler 和分阶段 Matrix 流水提高执行单元利用率，使数据搬运、矩阵乘、部分和处理及复杂函数可以按数据依赖同时推进。
- 复杂函数采用 `INT → FP32 → INT`：FP32 只在 Complex Math Engine 内部出现，不作为软件可见的模型张量格式。
- 首版没有卷积硬件单元，也没有卷积指令。`Conv2D` 由编译器展开为 `im2col + GEMM`，复用 DMA 和 Matrix Engine。

> [!note] P0 与 P1
> P0 是单核首版必须实现并验证的功能；P1 是已经预留编码、可在后续版本启用的功能。软件必须先读取设备功能寄存器，不能向未启用的 P1 功能发出任务。

### C model 参考配置

| 项目 | 参考值 | 项目 | 参考值 |
| --- | ---: | --- | ---: |
| NPU Core | 1 | 在途任务 | 32 |
| L1BUF | 1 MiB、16 bank | CMD FIFO | 8 项 |
| Matrix tile | `8×16×8` | Vector lane | 8 |
| Complex FP32 lane | 4 | DMA 未完成请求 | 16 |
| 外部地址 | 48-bit GVA、40-bit PA | 事件表 | 255 项 |

这些物理数值不写入指令编码。RTL 可以调整 L1BUF 容量、bank 数、tile 和 lane 数，并通过只读功能寄存器报告；编译器读取实际配置后选择分块与任务规模。

---

## 第 2 页：单核总体结构

![[assets/npu_single_core_architecture_ppt.png]]

图中用不同颜色区分命令控制、计算、片上存储和外部访问。主要数据路径为：

```text
Generic Core → CFE → TaskScheduler / DFU → 执行单元
DDR ↔ MIF / TBU ↔ DMA ↔ L1BUF ↔ Matrix / Vector / Complex
```

- Generic Core 通过自定义指令提交 CMD128，并使用 QUERY、WAIT、FENCE 和 ACK 管理任务。
- Command Front End（CFE）接收两个 64-bit beat，检查次序、版本、操作码和命令编号，再把完整命令送入命令 FIFO。
- TaskScheduler（TS）维护任务表和事件表；Descriptor Fetch Unit（DFU）读取描述符并检查地址、shape、stride、dtype 与保留位。
- 四个执行单元通过 L1BUF 交换张量；Matrix、Vector 和 Complex 不直接访问 DDR。
- Memory Interface（MIF）和 TBU 负责 64-bit AXI 访问、地址检查及未完成请求管理。
- LSC 提供寄存器、中断、性能计数和启动停止控制；CRG 与 WDT 分别负责时钟复位和超时监视。RTL 复位信号统一使用低有效 `reset_n`。

---

## 第 3 页：为什么采用 CMD128

一条任务需要同时携带描述符地址、命令编号、执行单元、完整操作码、两个等待事件、一个完成事件以及任务选项。若压缩成 64 bit，就需要额外写共享配置寄存器，增加寄存器访问、设备写屏障和多提交者互斥处理。CMD128 把一次提交所需信息放在同一条命令中，同时保持物理接口为 64 bit。

### 低 64 bit

| CMD bit | 字段 | 说明 |
| --- | --- | --- |
| `[47:0]` | `desc_addr` | 48-bit 描述符字节地址，要求 64B 对齐 |
| `[59:48]` | `command_id` | 12-bit 软件命令编号 |
| `[63:60]` | `engine` | Control、DMA、Matrix、Vector 或 Complex |

### 高 64 bit

| CMD bit | 字段 | 说明 |
| --- | --- | --- |
| `[71:64]` | `opcode` | 完整 8-bit 操作码 |
| `[83:72]` | `header_flags` | 中断、严格数值、跟踪、有序执行、超时类别等 |
| `[95:84]` | `wait_event_0` | 第一个等待事件 |
| `[107:96]` | `wait_event_1` | 第二个等待事件 |
| `[119:108]` | `signal_event` | 任务进入终态时更新的事件 |
| `[127:120]` | `header_version` | V1.1 写 `0x01` |

低 word 使用 `first=1,last=0`，高 word 使用 `first=0,last=1`。两个 beat 不得与另一条命令交错；CFE 等待第二拍超时后拒绝本次提交。

---

## 第 4 页：指令集合

| 单元 | Opcode | P0 指令 | 主要用途 |
| --- | --- | --- | --- |
| Control | `0x00～0x04` | `NOP`、`EVENT_SIGNAL`、`EVENT_REARM`、`EVENT_JOIN`、`GLOBAL_FENCE` | 事件管理和任务同步 |
| DMA | `0x20～0x25` | `DMA_COPY_1D`、`DMA_COPY_ND`、`DMA_FILL`、`DMA_TRANSPOSE_2D`、`DMA_PACK`、`DMA_SPLIT` | DDR/L1 搬运、多维步长访问、补零、转置和数据整理 |
| Matrix | `0x40～0x43` | `GEMM`、`BMM`、`GEMM_ACCUM`、`GEMM_ZERO` | 矩阵乘、带外层计数的矩阵乘、跨 K tile 累加和部分和清零 |
| Vector | `0x60～0x69` | `VADD_I`、`VSUB_I`、`VMUL_I`、`VFMA_I`、`VMAX_I`、`VMIN_I`、`VCMP_I`、`VSEL_I`、`VCLAMP_I`、`VRELU_I` | 逐元素整数运算、比较、选择与 ReLU |
| Complex | `0x80～0x82`、`0x84`、`0x86` | `VACT_I`、`VSOFTMAX_I`、`VNORM_I`、`VSTAT_I`、`VADD_RESCALE_I` | Sigmoid、Tanh、GELU、SiLU、Softmax、Norm、逐行统计和不同 scale 的加法 |

P1 预留 `DMA_GATHER_ND(0x28)`、`VROPE_I(0x83)` 和 `VRECIP_I(0x85)`。Complex 的 `0x83`、`0x85` 因此不会作为 P0 启用。未启用的 P1 指令返回 `ILLEGAL_OPCODE`，软件可用 P0 指令组合得到对应功能。

每条 CMD 指向一个固定版本 Descriptor。公共 64B 前缀保存输入输出地址、bias 或 scale 地址、dtype、舍入方式和软件标记；DMA、Matrix、Vector、Complex 再使用各自的专有字段保存 shape、stride、tile 及函数参数。

---

## 第 5 页：计算与存储模块

| 模块 | 主要职责 |
| --- | --- |
| DMA / Layout Engine | DDR 与 L1BUF 双向搬运；完成多维复制、填充、转置、拼接和拆分 |
| Matrix Engine | 执行 GEMM/BMM；支持 INT4、INT8、INT16 输入和权重，使用 INT32 累加并按需要写出 INT4/8/16/32 |
| Integer Vector Engine | 执行逐元素整数运算，适合 residual、门控乘法、比较、选择和 ReLU |
| Complex Math Engine | 完成激活、Softmax、LayerNorm、RMSNorm、统计与不同 scale 的相加 |
| L1BUF Controller | 管理多 bank 片上 SRAM，为四个执行单元仲裁读写请求 |
| MIF / TBU | 连接 64-bit AXI，处理 DDR 请求、地址检查、响应和错误 |
| CFE / TS / DFU | 接收命令、管理事件、读取描述符、选择可发射任务并收集完成状态 |
| LSC / CRG / WDT | 提供寄存器与中断、时钟复位、性能计数和任务超时保护 |

L1BUF 是计算单元之间的数据交换中心。编译器负责安排输入、权重、临时张量和输出的位置；硬件按描述符给出的地址和 stride 访问，不解析模型文件，也不推测 Kernel 的排列方式。

### 一条任务如何流过硬件

驱动先写入 Descriptor 和输入数据，完成缓存清理与设备写屏障，再依次发送 CMD 的低、高 word。CFE 返回 `ACCEPTED` 后，TS 保存任务并等待两个前置事件。事件满足时，DFU 取得并检查 Descriptor，随后 TS 向目标执行单元发射任务。执行单元的最后一个写响应返回后，TS 才记录终态、更新完成事件并按命令选项产生中断。软件通过 QUERY、WAIT 或中断取得结果，读取输出后执行 ACK，释放任务表项和 `command_id`。

---

## 第 6 页：Matrix 两阶段并行

分块 GEMM 经常重复执行“新 tile 乘累加”和“旧 tile 部分和相加、后处理、写回”。若把二者放在同一不可分状态中，阵列会在旧结果写回期间闲置。首版把 Matrix 任务拆成两个可独立推进的上下文：

- `MAC_CTX`：读取 A/B tile，执行乘累加，产生当前块结果。
- `ACCUM_CTX`：读取旧部分和，完成相加、bias、residual、整数重缩放、裁剪和写回。

当旧任务进入 `ACCUM_CTX` 后，Matrix 乘法槽可以接收下一任务。若旧任务即将写入的 C 地址与新任务的 A、B、bias 或 residual 读取地址重叠，调度器暂停新 `MAC_CTX`，避免新任务读到被修改的数据。写后读关系消失后继续发射；其他写入关系由单一 `ACCUM_CTX` 按次序处理。

任务的完成事件只能在最终写响应返回后更新，不能在乘法结束时提前更新。性能计数分别记录 MAC 活动周期、部分和活动周期、二者同时工作的周期以及地址等待周期，便于分析阵列利用率。

---

## 第 7 页：面向 Transformer 的算子组合

1. Matrix 执行 Q、K、V 投影，或执行一次融合 QKV GEMM。
2. DMA 使用 COPY_ND、SPLIT、PACK 和 TRANSPOSE 整理 Head，并生成 $K^{\mathsf T}$。
3. Matrix 使用 BMM 计算 $QK^{\mathsf T}$。
4. Complex 完成 scale、mask 和逐行 Softmax。
5. Matrix 计算 `Attention × V`，DMA 合并 Head，Matrix 完成输出投影。
6. Vector 完成 residual add；Complex 完成 LayerNorm 或 RMSNorm。
7. FFN 使用两次 GEMM，中间由 Complex 执行 GELU 或 SiLU。

注意力、FFN 和投影的大部分计算量由 Matrix Engine 承担；DMA 负责张量形状与存储次序调整；Vector 处理低成本逐元素运算；Complex 处理需要指数、平方根或除法的函数。

---

## 第 8 页：面向 RNN、LSTM 与 GRU 的算子组合

- SimpleRNN：Matrix 分别计算输入项和隐藏状态项，Vector 相加，Complex 执行 Tanh；ReLU 版本可直接使用 Vector。
- LSTM：Matrix 一次生成输入门、遗忘门、候选值和输出门的仿射结果；Complex 执行 Sigmoid/Tanh；Vector 完成门值乘法、cell 更新与 hidden 更新。
- GRU：Matrix 生成 reset、update 和 candidate 的三组仿射结果；Complex 执行 Sigmoid/Tanh；Vector 完成门控乘法与状态组合。
- 时间步 $t+1$ 必须等待 $h_t$，LSTM 还要等待 $c_t$ 的最终写入完成。与此同时，DMA 可以把下一时间步输入和权重 tile 预取到另一片 L1BUF 区域。

门控模型中，同一长度为 $H$ 的 bias 会加到全部输入行：第 $j$ 个 bias 只加到每一行第 $j$ 个隐藏 Feature，而不是加到该行的其他位置。

---

## 第 9 页：Conv2D 使用 im2col + GEMM

首版不增加卷积数据通路。编译器接收 NHWC 输入
$[N,H,W,C_{in}]$ 和 Kernel $[K_H,K_W,C_{in},C_{out}]$，将每个输出位置对应的输入窗口展开成一行：

$$
X_{\mathrm{col}}\in\mathbb Z^{(N H_o W_o)\times(K_HK_WC_{in})}.
$$

Kernel 在编译期整理为：

$$
W_{\mathrm{col}}\in\mathbb Z^{(K_HK_WC_{in})\times C_{out}}.
$$

随后执行：

$$
Y_{\mathrm{col}}=X_{\mathrm{col}}W_{\mathrm{col}}+b.
$$

DMA FILL 生成 padding 的零值，DMA COPY_ND 把各 Kernel 位置对应的输入片段写入 `im2col` 张量，Matrix GEMM 产生按 NHWC 线性次序保存的输出。这样无需新增卷积 opcode，代价是额外的 L1BUF 容量和搬运次数；编译器需要按可用容量对输出位置分块。

---

## 第 10 页：复杂函数与整数精度

Complex Math Engine 对输入整数 $q_x$ 执行：

$$
x=(q_x-z_x)s_x
\quad\rightarrow\quad
r=f(x)
\quad\rightarrow\quad
q_y=\operatorname{sat}\!\left(\operatorname{round}\left(\frac{r}{s_y}+z_y\right)\right).
$$

$s_x,s_y$ 是输入和输出 scale，$z_x,z_y$ 是 zero point，$f$ 可以是 Sigmoid、Tanh、GELU、SiLU、Exp 或平方根倒数，`round` 表示指定舍入方式，`sat` 表示限制到目标整数格式的可表示范围。Softmax 与 Norm 也遵循相同的整数输入、内部 FP32 计算、整数输出次序。

FP32 scale、$\epsilon$、函数系数和查找表属于只读元数据。FP32 中间值只保存在 Complex 内部寄存器或私有暂存区，不能写成模型输入、权重、中间张量或输出。

---

## 第 11 页：软件工具和 C 驱动

```text
高层模型图
  ↓ npu_model_compiler.py
低层 JSON IR（.npuasm.json）
  ↓ npu_assembler.py
CMD128 + Descriptor + 常量镜像 + Runtime 元数据
  ↓ NPU C 驱动
硬件或 C model
```

- 上层编译器负责图检查、shape 推导、算子拆分、张量布局、L1/DDR 存储分配、Matrix-B tile 整理、事件依赖和任务调度；`MultiHeadAttention` 与 `Conv2D` 在这一阶段拆成底层任务。
- 低层汇编器只读取已经确定硬件字段的低层 JSON IR，编码 CMD128 和各类 Descriptor，并生成二进制文件、清单与 C 头文件。
- C 驱动分为 device、command、runtime、descriptor 和 memory 五个源文件，公共 API 不依赖特定操作系统。平台通过回调提供 MMIO、提交 beat、缓存维护和内存屏障。
- Runtime 装载 `.const.bin` 与 `.desc.bin`，依次提交 `.cmd.bin`，等待任务终态，读取输出后 ACK 命令编号。

主要产物包括 `.npuasm.json`、`.cmd.bin`、`.desc.bin`、`.const.bin`、`.runtime.json`、`.manifest.json` 和 `.npu.h`。从高层图直接生成的结果必须与“先生成低层 JSON IR、再单独汇编”的结果逐字节一致。

---

## 第 12 页：首版实现重点

1. 先完成 CMD128、CFE、TS、DFU、事件表和错误状态，使任务提交与依赖管理可验证。
2. 完成 DMA、L1BUF 和 MIF，再接入 Matrix 基本 GEMM，建立稳定的数据供给。
3. 加入 `MAC_CTX + ACCUM_CTX`，验证安全并行、部分和次序、最终事件时刻与性能计数。
4. 完成 Vector 和 Complex，覆盖 residual、门控、激活、Softmax 与 Norm。
5. 用 INT4/8/16/32 回归测试覆盖合法数据组合、溢出处理、不同 shape 和存储次序。
6. 使用同一套上层编译器、低层汇编器和 C 驱动完成 Transformer、RNN、LSTM、GRU 与 `Conv2D(im2col)` 的端到端运行。

首版优先证明单核功能、指令语义、软件生成结果与硬件执行结果一致；后续再依据性能计数调整 Matrix tile、L1BUF bank 数、Complex lane 数和 DMA 未完成请求数。
