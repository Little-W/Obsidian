# NPU 单核架构初版设计介绍

> [!info] 文档用途
> 本文是面向 PPT 的架构摘要，集中说明单核首版的设计目标、指令、硬件模块、重点算子和软件分层。详细字段、模块接口与周期时序以《NPU 指令与硬件架构设计 Spec》为准。

> [!tip] PPT 排版参数
> 页面建议采用竖版。页标题不小于 30 pt，二级标题不小于 24 pt，正文不小于 18 pt，表格文字不小于 16 pt。表格单元格的上下、左右内边距均建议保留 0.18 cm 以上，文字采用垂直居中，不能贴到表格线。图中同一行的方框尽量等高并垂直居中；模块标题、说明文字与方框四周保留明显空白。架构图按原宽高比例缩放并置于页面中央，不要拉伸；若一页内容过多，应拆页，不应缩小文字。

---

## 第 1 页：设计目标

- 面向 Transformer、RNN、LSTM、GRU 和回归模型的整数推理，兼顾自然语言处理与时序数据分析。
- 首版采用单核结构：一个 Matrix Engine、一个 Integer Vector Engine、一个 Complex Math Engine 和一个 DMA / Layout Engine。
- Generic Core 是 NPU 外部的主控 CPU，不计入 NPU 单核硬件。主控 CPU 运行模型调用代码与 C 驱动，以 AXI Master 身份主动访问系统总线。
- NPU 对系统总线提供 64-bit AXI Slave 接口。该接口包含命令提交、控制寄存器和 L1BUF 外部访问窗口；CFE 只接收并解析命令，不发起 AXI 访问。
- 模型输入、权重、中间张量和输出支持 `INT4`、`INT8`、`INT16`、`INT32`。其中 INT4/INT8 侧重吞吐与容量，INT16 为回归输入、权重和输出提供更细的数值间隔，INT32 用于矩阵累加、bias 和较大范围的中间结果。
- 外部系统总线和模块间数据接口均以 64 bit 为一个 beat；命令通过固定地址的 CMD FIFO 数据端口写入，一条 128-bit 命令按低、高两个 beat 连续发送。
- 通过事件、TaskScheduler 和分阶段 Matrix 流水提高执行单元利用率，使数据搬运、矩阵乘、部分和处理及复杂函数可以按数据依赖同时推进。
- 复杂函数采用 `INT → FP32 → INT`：FP32 只在 Complex Math Engine 内部出现，不作为软件可见的模型张量格式。
- 首版没有卷积硬件单元，也没有卷积指令。当前支持的 NHWC、`groups=1` Conv2D 由编译器形成 `padding / im2col / DMA FILL / COPY_ND / GEMM / bias / 输出整理`，复用 DMA 和 Matrix Engine；不支持的属性在编译阶段报告错误。

> [!note] P0 与 P1
> P0 是单核首版必须实现并验证的功能；P1 是已经预留编码、可在后续版本启用的功能。软件必须先读取设备功能寄存器，不能向未启用的 P1 功能发出任务。

### C model 参考配置

| 项目 | 参考值 | 项目 | 参考值 |
| --- | ---: | --- | ---: |
| NPU Core | 1 | 在途任务 | 32 |
| L1BUF | 1 MiB、16 bank | CMD ingress FIFO | 8 条 CMD / 16 beat |
| Matrix tile | `8×16×8` | Vector lane | 8 |
| Complex FP32 lane | 4 | DMA 未完成请求 | 16 |
| 外部地址 | 48-bit GVA、40-bit PA | 事件表 | 255 项 |

这些物理数值不写入指令编码。RTL 可以调整 L1BUF 容量、bank 数、tile 和 lane 数，并通过只读功能寄存器报告；编译器读取实际配置后选择分块与任务规模。

---

## 第 2 页：单核总体结构

![[assets/npu_single_core_architecture_ppt.png]]

图中用不同颜色区分命令控制、计算、片上存储和外部访问。主要数据路径为：

```text
外部 Generic Core（AXI Master）
  → 系统 AXI 总线
  → NPU AXI Slave
  → CFE → TaskScheduler / DFU → 执行单元
DDR ↔ MIF / TBU ↔ DMA ↔ L1BUF ↔ Matrix / Vector / Complex
```

- Generic Core 位于 NPU 框外。示例 runner 读取 C 模型包中的配置、描述符、权重和 CMD128，并通过 C 驱动准备缓冲区、提交命令；CPU 以 AXI Master 身份主动发起写事务。
- NPU AXI Slave 把地址访问分送到固定地址 CMD FIFO 数据端口、LSC 控制寄存器或 L1BUF 外部访问桥。CPU 使用 `AWBURST=FIXED` 向 CMD FIFO 连续写入 2～16 个 64-bit beat；每条 CMD128 固定采用 low beat、high beat 的次序，同一 burst 可以依次携带 1～8 条完整命令。外部访问桥把 AXI Slave 的单项请求与 L1BUF 外部端口的读写通道相互转换。
- Command Front End（CFE）接收来自 NPU AXI Slave 的两个命令 beat，检查次序、版本、操作码和命令编号，再把完整命令送入命令 FIFO。CFE 不具有 AXI Master 端口。
- TaskScheduler（TS）维护任务表和事件表；Descriptor Fetch Unit（DFU）读取描述符并检查地址、shape、stride、dtype 与保留位。
- 四个执行单元通过 L1BUF 交换张量；Matrix、Vector 和 Complex 不直接访问 DDR。
- L1BUF 的计算端口供 DMA、Matrix、Vector 和 Complex 使用；外部 CPU 还可通过独立的 AXI Slave 地址窗口读写允许访问的片上区域。仲裁器必须保证外部访问与计算访问的数据一致性。
- Memory Interface（MIF）和 TBU 是 NPU 的 AXI Master 访存出口，负责主动读取 Descriptor、权重和输入数据，或写回输出。
- LSC 提供可由 AXI Slave 访问的寄存器、中断、性能计数和启动停止控制；CRG 与 WDT 分别负责时钟复位和超时监视。RTL 复位信号统一使用低有效 `reset_n`。

> [!important] 主设备与从设备的方向
> Generic Core 是系统总线主设备；NPU 命令端口、控制寄存器端口和 L1BUF 外部窗口都是系统总线从设备。只有 MIF / TBU 代表 NPU 主动访问 DDR。CFE 是 NPU 内部命令接收模块，不是总线主设备。

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

外部 CPU 不发送 `first/last` 标记。驱动把每条 CMD128 排成相邻的低、高
word，并向固定地址 `CMD_FIFO_DATA` 发出 2～16 beat 的偶数长度 FIXED
burst，一次可提交 1～8 条命令。Front End 先暂存完整 burst；只有 beat 数、
`WSTRB` 和 `WLAST` 全部正确时，才把整个 burst 放入 ingress FIFO，否则
整体拒绝。进入 NPU 内部后，Front End 再根据低、高 word 的位置产生
`first/last` 信号。

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
| NPU AXI Slave Front End | 接收外部 CPU 的 64-bit AXI 访问；固定地址 CMD FIFO 使用 FIXED burst，LSC 寄存器和 L1BUF 外部窗口保持各自的地址访问方式 |
| Command Front End | 从 CMD FIFO 取得相邻的低、高两个 64-bit beat，拼接并检查 CMD128；不主动访问 DDR |
| DMA / Layout Engine | DDR 与 L1BUF 双向搬运；完成多维复制、填充、转置、拼接和拆分 |
| Matrix Engine | 执行 GEMM/BMM；支持 INT4、INT8、INT16 输入和权重，使用 INT32 累加并按需要写出 INT4/8/16/32 |
| Integer Vector Engine | 执行逐元素整数运算，适合 residual、门控乘法、比较、选择和 ReLU |
| Complex Math Engine | 完成激活、Softmax、LayerNorm、RMSNorm、统计与不同 scale 的相加 |
| L1BUF Controller | 管理多 bank 片上 SRAM，为四个执行单元和外部访问窗口仲裁读写请求 |
| L1BUF 外部访问桥 | 在 AXI Slave 窗口请求与 L1BUF 外部客户端读写通道之间转换请求和响应 |
| MIF / TBU | 作为 64-bit AXI Master 连接系统总线，主动发出 DDR 请求并处理响应 |
| CFE / TS / DFU | 接收命令、管理事件、读取描述符、选择可发射任务并收集完成状态 |
| LSC / CRG / WDT | 提供 AXI Slave 控制寄存器与中断、时钟复位、性能计数和任务超时保护 |

L1BUF 是计算单元之间的数据交换中心。编译器负责安排输入、权重、临时张量和输出的位置；硬件按描述符给出的地址和 stride 访问，不解析模型文件，也不推测 Kernel 的排列方式。外部 CPU 只在访问许可满足时使用 L1BUF 外部窗口；正常执行期间优先由 DMA 负责 DDR 与 L1BUF 之间的数据传送。

### 一条任务如何流过硬件

示例 runner 读取生成的配置结构体、Descriptor、权重、输入输出信息和命令分组，再调用通用 C 驱动。驱动完成缓存维护与设备写屏障，然后向固定地址 CMD FIFO 发起 `AWBURST=FIXED` 写事务，按 low word、high word 的次序连续发送命令 beat。CFE 返回 `ACCEPTED` 后，TS 保存任务并等待两个前置事件。事件满足时，DFU 取得并检查 Descriptor，随后 TS 向目标执行单元发射任务。执行单元的最后一个写响应返回后，TS 才记录终态、更新完成事件并按命令选项产生中断。runner 通过驱动的查询、等待接口或中断取得结果，读取输出后调用 ACK 接口，释放任务表项和 `command_id`。

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

## 第 11 页：模型编译结果与 C 驱动

```text
Keras / PyTorch / TFLite / ONNX 模型
  ↓ npu_model_compiler.py
高层图检查与算子拆分
  ↓
低层 JSON IR（编译过程中的中间表示）
  ↓ npu_assembler.py
C 模型包（.c / .h）
  ├─ 模型配置结构体
  ├─ CMD128 指令数组
  ├─ Descriptor 数组
  ├─ 权重与常量数组
  ├─ 输入输出与操作信息
  └─ 命令分组
  ↓ C 驱动
外部 Generic Core 经系统 AXI 互连访问 NPU AXI Slave → NPU / C model
```

- 上层编译器负责图检查、shape 推导、算子拆分、张量布局、L1/DDR 存储分配、Matrix-B tile 整理、事件依赖和任务调度；`MultiHeadAttention` 与 `Conv2D` 在这一阶段拆成可以执行的步骤。
- 低层汇编器读取已经确定硬件字段的低层 JSON IR，编码 CMD128 与各类 Descriptor。它产生的字节内容随后写入 C 数组，不作为最终部署接口单独交给应用。
- 编译器的最终部署产物是模型专用 `.c` 与 `.h`：配置结构体说明输入输出、工作区、数组长度和所需设备功能；指令数组保存 CMD128；Descriptor 数组保存任务参数；权重数组保存离线整理后的整数权重和常量。
- 当前 C 模型包只提供配置结构体和静态数组，不生成模型初始化函数、模型运行函数或 CPU 辅助函数。示例 runner 读取配置、输入输出、操作信息和命令分组，再调用通用 C 驱动完成缓冲区准备、CMD128 提交、等待、查询、中断处理和 ACK。
- C 驱动分为 device、command、runtime、descriptor 和 memory 五个源文件，公共 API 不依赖特定操作系统。平台通过回调提供 64-bit AXI/MMIO 访问、缓存维护和内存屏障。

> [!important] Conv2D 不是硬件原生指令
> 首版没有 `CONV` opcode。对于当前支持的 NHWC、`groups=1` Conv2D，编译器形成 `padding / im2col / DMA FILL / COPY_ND / GEMM / bias / 输出整理` 的低层操作，并把对应的 CMD128、Descriptor、操作信息和命令分组写入 C 模型包。不支持的数据格式、分组或属性在编译阶段报告错误，不生成 CPU im2col 函数。

主要部署文件是 `<stem>_model.c` 与 `<stem>_model.h`。低层 JSON IR、清单和反汇编文本可作为检查文件保留，但应用不需要在运行时解析模型文件，也不需要装载多个独立二进制镜像。

---

## 第 12 页：首版实现重点

1. 先完成 CMD128、CFE、TS、DFU、事件表和错误状态，使任务提交与依赖管理可验证。
2. 完成 DMA、L1BUF 和 MIF，再接入 Matrix 基本 GEMM，建立稳定的数据供给。
3. 加入 `MAC_CTX + ACCUM_CTX`，验证安全并行、部分和次序、最终事件时刻与性能计数。
4. 完成 Vector 和 Complex，覆盖 residual、门控、激活、Softmax 与 Norm。
5. 用 INT4/8/16/32 回归测试覆盖合法数据组合、溢出处理、不同 shape 和存储次序。
6. 使用同一套上层编译器、低层汇编器和 C 驱动生成可直接编译的 C 模型包，完成 Transformer、RNN、LSTM、GRU 与 `Conv2D(im2col)` 的端到端运行。
7. 验证外部 Generic Core 的 AXI Master 访问、NPU AXI Slave 命令提交、控制寄存器访问、L1BUF 外部窗口访问，以及 MIF / TBU 的 AXI Master DDR 请求。

首版优先证明单核功能、指令语义、软件生成结果与硬件执行结果一致；后续再依据性能计数调整 Matrix tile、L1BUF bank 数、Complex lane 数和 DMA 未完成请求数。
