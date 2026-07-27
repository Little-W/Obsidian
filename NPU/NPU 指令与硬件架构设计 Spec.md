# NPU 指令与硬件架构设计 Spec

状态：CMD128 内联指令集

目标：单核整数推理 NPU

外部数据总线：64 bit AXI4

命令宽度：128 bit

本文定义部署软件与硬件共同遵守的 CMD128 内联指令集。所有执行参数都在
128 bit 命令内；指令不含 `desc_addr`，不读取外部任务参数块，也不要求软件在
DDR 中生成此类数组。CFE 与 Task Scheduler（TS）保存收到的 16 byte
Task Context，执行单元可以读取内部展开字段；这些内部字段不是软件可见数组。

本文中的“命令”“任务”“部署”均指本章定义的 CMD128 指令。

## 1. 设计范围与基准配置

### 1.1 设计目标

- 单核；同一条命令只在一个 NPU Core 内执行。
- 软件可见张量仅为 INT4、INT8、INT16、INT32。
- Matrix Engine 完成整数矩阵乘、累加与清零。
- Integer Vector Engine（IVE）完成逐元素整数运算。
- Complex Math Engine（CME）允许内部 `INT -> FP32 -> INT`，但不得把
  FP32 中间张量暴露给软件。
- DMA/Layout Engine 在 L1BUF 与系统存储间搬运和重排数据。
- Generic Core 是 NPU 外部的 CPU，通过 NPU 64 bit AXI Slave 提交命令、
  访问 CSR 与 L1BUF 窗口。
- MIF 是 NPU 的 64 bit AXI Master，通过 SoC Fabric 访问系统存储；DDR 是
  系统总线上的存储目标，不是 NPU 的专用端口。

### 1.2 参考参数

| 项目 | 参考值 |
| --- | ---: |
| Core 数 | 1 |
| AXI 数据宽度 | 64 bit |
| L1BUF 容量 | 1 MiB |
| L1 bank 数 | 16 |
| L1 读延迟 | 2 cycles |
| Matrix `MT/KT/NT` | 8 / 16 / 8 |
| IVE lane 数 | 8 |
| CME FP32 lane 数 | 4 |
| CME 私有暂存 | 4096 FP32 元素 |
| Task 表项 | CModel 参考值 32；当前 RTL 默认值 16，可参数化 |
| Event 表项 | 255，有效 ID 为 0..254 |
| CFE FIFO 深度 | 8 |
| DMA 最大 burst | 16 个 64 bit beat |
| MIF 最大未完成事务 | 16 |
| CFE 第二拍等待上限 | 32 cycles |

参数可以在实现中配置，但 CMD 位宽、字段位置、地址引用算法和软件可见结果
必须保持本文定义。

## 2. 整数数据格式

### 2.1 dtype 编码

| `dtype[1:0]` | 数据类型 | 每元素位数 | 有符号范围 |
| ---: | --- | ---: | --- |
| 0 | INT4 | 4 | -8..7 |
| 1 | INT8 | 8 | -128..127 |
| 2 | INT32 | 32 | -2147483648..2147483647 |
| 3 | INT16 | 16 | -32768..32767 |

INT8、INT16、INT32 使用二进制补码和 little-endian 字节序。INT4 每字节保存
两个元素：偶数元素在低半字节，奇数元素在高半字节；读取后先做 4 bit
符号扩展。二维张量按行优先保存，除非某条指令明确要求 Matrix B 的 tiled
排列。

### 2.2 scale 与整数重缩放

软件以整数 `q` 和正数 scale `S` 表示实数：

```text
x_real = q * S
```

Matrix 的乘加先在足够宽的内部整数中形成结果，再按指令的
`requant_shift` 执行右移和最近偶数舍入，最后饱和写入目标 dtype。Matrix
指令的整数倍数固定为 1，所以 `requant_shift` 是直接移位值，不是表
索引。目标为 INT32 时必须令 `requant_shift=0`。

IVE 的 ADD、SUB、MAX、MIN、SELECT 与 RELU 保持输入 dtype；MUL 和 FMA
写 INT32；CMP 写 INT8 mask。CLAMP 的上下限是命令中的 signed16 常数。

CME 先把输入整数乘输入 scale 转为 FP32，完成函数计算，再除以目标 scale，
用最近偶数方式转为整数并饱和。软件、DMA、L1BUF、MIF 和 AXI 上均不传输
CME 的 FP32 中间值。

### 2.3 Matrix 数学定义

GEMM 的结果位置为：

```text
acc[i,j] = sum(k=0..K-1, A[i,k] * B[k,j])
out[i,j] = acc[i,j] + bias[j]                 // bias_enable
```

Bias 是长度为 `N` 的 INT32 向量。第 `j` 个值 `bias[j]` 加到 C 的第 `j`
列全部 `M` 行，不能按行解释。BMM 对每个 batch 分别执行同一公式，A、B、C
各自使用连续 batch stride；BMM inline 没有 bias 字段。

支持的输入组合是 INT4×INT4、INT8×INT8、INT8×INT4、INT16×INT16；
A 为 INT8 且 `b_int4=1` 时 B 为 INT4，否则 B 与 A 同 dtype。允许的常用
算子组合包括 4×4、8×8、8×4、16×16。C 可以是 INT4、INT8、INT16 或
INT32；非 INT32 输出执行上述整数重缩放。

## 3. 系统结构

### 3.1 模块组成

```text
Generic Core
    |
    | 64-bit AXI Slave: CSR / CMD FIFO / response FIFO / L1 window
    v
System Slave Front End ---- LSC / CRG / WDT
    |
    v
CFE -> Task Scheduler + Event Table + 16-byte Task Context
             |          |          |          |
             v          v          v          v
            DMA       Matrix      IVE        CME
             |          |          |          |
             +----------+----------+----------+
                        |
                  L1BUF Controller
                        |
                 16-bank 1 MiB L1BUF

DMA <-> TBU <-> MIF <-> 64-bit AXI Master <-> SoC Fabric <-> DDR/other memory
```

### 3.2 模块职责

| 模块 | 职责 |
| --- | --- |
| System Slave Front End | AXI Slave 协议、固定命令地址、响应 FIFO、CSR 与 L1 窗口访问 |
| CFE | 两个 64 bit beat 组装、公共头检查、command_id 查询、接收响应 |
| TS | Task Context、事件依赖、发射、timeout、完成与 ACK |
| DMA | 系统存储/L1 数据搬运、填充、转置、PACK、SPLIT |
| Matrix | GEMM、BMM、ACCUM、ZERO、bias、整数重缩放 |
| IVE | ADD 至 RELU 的逐元素运算与 broadcast |
| CME | ACT、SOFTMAX、NORM、STAT、ADD_RESCALE |
| L1BUF Controller | 64 bit 多端口仲裁、bank 冲突处理、ECC |
| TBU | 地址规则查询、读写权限、属性与错误状态 |
| MIF | burst 拆分、未完成事务表、AXI Master 请求和响应 |
| LSC | CSR、首错记录、中断、性能计数、停止接收与软复位控制 |
| CRG/WDT | 复位同步、时钟控制、看门狗 |

MIF 请求只来自 DMA 对全局张量、权重、输入、工作区、输出和 KV
数据的访问。CFE、TS、Matrix、IVE、CME 不通过 MIF读取任务参数。

## 4. 通用接口规则

### 4.1 时钟与复位

Core 域模块使用 `clk` 和低有效同步观察信号 `reset_n`。端口名保留
`reset_n` 写法。异步外部复位先由 CRG 做同步释放；模块在有效时钟上升沿
看到 `reset_n=0` 时清除 valid、状态机、未完成事务和粘滞错误。L1 SRAM
内容与外部系统存储内容不由普通模块复位清零。

NoC 域可使用独立 `noc_clk` 与 `noc_reset_n`。Core/NoC 之间通过请求、
写数据和响应异步 FIFO；任一域非受控复位导致未完成 DMA 任务以 ABORTED
结束，不等待已丢失的响应。

### 4.2 ready/valid

- 传输只在同一上升沿 `valid && ready` 时发生。
- 发送者在 `valid=1 && ready=0` 时保持数据、tag、last、strb 和属性不变。
- 接收者可组合产生 ready；不能把 ready 当作已接收脉冲。
- 多 beat 事务的 `last` 只在最后一个 beat 为 1。
- `req_beats` 使用 `beat_count-1` 编码时，字段 0 表示一个 beat。
- 复位后所有输出 valid 为 0。

### 4.3 状态码

| 值 | 名称 | 含义 |
| ---: | --- | --- |
| 0x00 | SUCCESS | 完成 |
| 0x01 | ILLEGAL_OPCODE | 操作码未实现或功能关闭 |
| 0x02 | BAD_DESC | 保留位、字段组合或协议错误 |
| 0x03 | BAD_SHAPE | 尺寸或 stride 无效 |
| 0x04 | ADDR_FAULT | 地址超出允许范围 |
| 0x05 | BUS_DECERR | AXI DECERR |
| 0x06 | BUS_SLVERR | AXI SLVERR |
| 0x07 | DTYPE_UNSUPPORTED | dtype 组合不支持 |
| 0x08 | DEPENDENCY_FAILED | 等待事件失败 |
| 0x09 | TIMEOUT | 超过 timeout class |
| 0x0a | ABORTED | 软件或复位终止 |
| 0x0b | L1_ECC_UNCORRECTABLE | L1 不可纠正错误 |
| 0x0c | NUMERIC_EXCEPTION | strict numeric 发现数值异常 |
| 0x0d | ADDR_OVERLAP | 不允许的读写区域重叠 |
| 0x80 | BUSY | 查询对象尚未完成 |
| 0x81 | NOT_FOUND | command_id 不存在 |

## 5. 顶层 64 bit AXI 接口

### 5.1 NPU AXI Slave

Generic Core 作为 AXI Master，NPU 作为 AXI Slave。接口包含标准
AW/W/B、AR/R 五通道，`WDATA/RDATA=64 bit`，`WSTRB=8 bit`。支持区域：

1. CSR：单 beat 读写，访问 LSC、控制、状态、性能计数和错误记录。
2. CMD 固定地址：使用 `AWBURST=FIXED`，一次 burst 接收 2、4、6、……
   16 个 64 bit W beat，也就是 1～8 条 CMD128。每条命令先发送
   CMD[63:0]，再发送 CMD[127:64]；`AWLEN` 分别为 1、3、5、……15。
3. 命令接收响应 FIFO：CPU 读取 command_id、接收状态与可用 FIFO 项数。
4. L1BUF 外部窗口：调试、权重装载、输入写入和输出读取；经 L1 Host
   端口进入正常 bank 仲裁。

参考地址表：

| 地址 | 访问对象 |
| ---: | --- |
| `0x00000000..0x0000ffff` | LSC/控制 CSR |
| `0x00010000..0x0001ffff` | 预留的 CSR 地址段 |
| `0x00020000` | CMD FIFO 固定地址 |
| `0x00020008` | 命令接收响应 FIFO |
| `0x00020010` | CMD FIFO 状态 |
| `0x00020020` | 控制参数 0 |
| `0x00020028` | 控制参数 1 |
| `0x00020030` | 启动 QUERY、WAIT 或 FENCE |
| `0x00020038` | 控制状态 |
| `0x00020040` | 控制结果 |
| `0x00020048` | 取消正在等待的控制操作 |
| `0x00100000..0x001fffff` | L1BUF 外部窗口 |

CMD 地址不随 beat 增加。WSTRB 必须为 `0xff`，同一条命令的低、高两个
beat 不得交换。接收端只在整个 burst 完整通过检查后提交其中的命令。高
beat 等待超时、AW 属性错误、W beat 数不是非零偶数或 FIFO 空间不足时，
AXI/命令响应报告错误，且该 burst 不得创建可执行任务。

### 5.2 MIF AXI Master

MIF 是 64 bit AXI4 Master，连接 SoC Fabric。关键要求：

- 独立 AR/R 与 AW/W/B 通道，AXI ID 标识未完成事务。
- INCR burst，最大 16 个 64 bit beat；请求不得跨越实现规定的页范围。
- 非对齐首尾由 DMA 的字节使能处理；W 通道顺序与 AW 分配顺序一致。
- R/B 返回的 SLVERR、DECERR转换为任务状态并记录首错地址。
- 反压期间保持全部有效载荷稳定。
- AXI ID 只有在对应 RLAST 或 B 响应完成后才能复用。

MIF 不接收 Task Context 地址，也不读取外部任务参数块。

## 6. 指令集设计

### 6.1 位定义

|     bit | 名称               | 说明                          |
| ------: | ---------------- | --------------------------- |
| 127:122 | `opcode`         | 6 bit，见 6.3                 |
| 121:112 | `command_id`     | 10 bit，0..1023              |
| 111:104 | `wait0`          | 8 bit Event ID，0xff 表示 none |
|  103:96 | `wait1`          | 8 bit Event ID，0xff 表示 none |
|   95:88 | `signal`         | 8 bit Event ID，0xff 表示 none |
|      87 | `irq_success`    | 成功完成时产生中断                   |
|      86 | `irq_error`      | 错误完成时产生中断                   |
|      85 | `strict_numeric` | CME 数值异常转为任务错误              |
|      84 | `ordered`        | 与同执行单元的先前任务保持提交顺序           |
|   83:82 | `timeout_class`  | 4 个 timeout 配置之一            |
|   81:80 | `dtype`          | 公共输入 dtype                  |
|    79:0 | `payload`        | 操作专有字段                      |


`opcode` 占用最高 6 bit。数值 0..32 的含义见 6.3；33..63 返回
ILLEGAL_OPCODE。

各操作的保留位必须为 0。命令以 little-endian 字节保存并先发送低 64 bit。
`command_id` 在未 ACK 的 Task 表项中必须唯一。CFE 在接收前查询占用状态；
重复 ID 返回 BAD_DESC。

`wait0`、`wait1` 和 `signal` 只携带 8 bit ID。事件代次由 TS 在接收命令的
那个周期从 Event Table 取得并写入 Task Context 的内部信息，因此之后的
REARM 不会改变已经接收任务所等待的代次。

### 6.2 头标志语义

- `irq_success` 只在 SUCCESS 终态产生一个脉冲。
- `irq_error` 在任何非 SUCCESS 终态产生一个脉冲。
- `strict_numeric` 对 CME 有效；NaN、Inf、非法倒数等按 NUMERIC_EXCEPTION
  处理。其他执行单元保存该标志但不改变整数数学。
- `ordered=1` 时，任务不能越过同执行单元更早且未到终态的命令。
- `timeout_class` 从任务进入 RUNNING 开始计数；0 值配置表示该类不启用
  timeout。TIMEOUT 后 TS 发取消请求，执行单元排空已接收的数据响应再完成。

### 6.3 操作码

本表的“CMD128 值”是 `opcode[127:122]` 的 6 bit 线上编码，不是 DMA、
Matrix、IVE 或 CME 内部使用的操作码。每条任务的地址引用、尺寸、数据格式和
操作选项均由命令头与 `payload` 直接给出；“直接字段”仅作索引，精确位段见第
8～12 节。

| CMD128 值 | 接口名称 | 单元 | 状态 | 直接字段 | 定义与当前限制 |
| ---: | --- | --- | --- | --- | --- |
| 0 | `NOP` | Control | P0，已实现 | `payload=0`；三个 Event 字段均为 none | 创建占位任务，不读写数据。 |
| 1 | `EVENT_SIGNAL` | Control | P0，已实现 | `signal`；`payload=0` | 主动把指定 Event 置为成功，不启动执行单元。 |
| 2 | `EVENT_REARM` | Control | P0，已实现 | `signal`；`payload=0` | 将已完成且没有等待者的 Event 进入新代次。 |
| 3 | `EVENT_JOIN` | Control | P0，已实现 | `wait0`、`wait1`、`signal`、`join_mode` | 合并两个前置 Event 的结果；`join_mode` 选择“均成功”或“任一成功”。 |
| 4 | `GLOBAL_FENCE` | Control | P0，已实现 | `engine_mask` | 等待所选 DMA、Matrix、IVE、CME 中更早提交的任务结束。 |
| 5 | `DMA_COPY_1D` | DMA | P0，已实现 | `src_aref`、`dst_aref`、`count`、源/目标 dtype、INT4 半字节选择 | 连续复制元素，可做整数位宽转换和饱和写回。 |
| 6 | `DMA_COPY_ND` | DMA | P0，已实现 | 与 `DMA_COPY_1D` 相同 | 复制连续保存的张量区域；不含 rank、shape 或 src/dst stride。带间隔访问由编译器拆成多条复制或使用布局指令。 |
| 7 | `DMA_FILL` | DMA | P0，已实现 | `dst_aref`、`count`、`fill_value`、目标 dtype | 以一个立即数连续填充目标元素。 |
| 8 | `DMA_TRANSPOSE_2D` | DMA | P0，已实现 | `src_aref`、`dst_aref`、`rows`、`columns`、dtype、INT4 半字节选择 | 对连续行优先二维数组转置；不含行间隔字段。 |
| 9 | `DMA_PACK` | DMA | P0，已实现 | `src_aref`、`dst_aref`、`segment_count`、`segment_bytes`、`segment_stride` | 从等间隔数据段读取并连续写入；后三项均为 8 bit。 |
| 10 | `DMA_SPLIT` | DMA | P0，已实现 | `src_aref`、`dst_aref`、`segment_count`、`segment_bytes`、`segment_stride` | 从连续数据区读取并按固定间隔写入；后三项均为 8 bit。 |
| 11 | `DMA_GATHER_ND` | DMA | P1，功能位关闭 | `src_aref`、索引表 `LREF16`、目标 `LREF16`、`block_count`、`block_bytes` | 根据 L1 中的 UINT32 索引表，从全局内存读取多个数据块并连续写入 L1。当前提交返回 `ILLEGAL_OPCODE`。 |
| 12 | `GEMM` | Matrix | P0，已实现 | A/B/C `LREF14`、bias `LREF12`、M/N/K、`b_int4`、C dtype、右移位数 | 矩阵乘法后可加 INT32 bias 并写回。无 residual、ReLU 或逐输出通道重缩放字段。 |
| 13 | `BMM` | Matrix | P0，已实现 | A/B/C `LREF14`、batch、M/N/K、`b_int4`、C dtype、右移位数 | 连续保存的 batch 矩阵乘法；不带 bias。 |
| 14 | `GEMM_ACCUM` | Matrix | P0，已实现 | A/B/C `LREF14`、M/N/K、`b_int4` | 将新的乘加结果加入原 C；C 必须为 INT32，bias 和右移位数必须为 0。 |
| 15 | `GEMM_ZERO` | Matrix | P0，已实现 | C `LREF14`、M/N | 清零 C 指向的 INT32 矩阵区域，为后续 `GEMM_ACCUM` 准备部分和。 |
| 16 | `VECTOR_ADD` | IVE | P0，已实现 | `src0`、`src1`、`dst`、`rows`、`length`、广播方式 | 逐元素相加；输出保持公共输入 dtype。 |
| 17 | `VECTOR_SUB` | IVE | P0，已实现 | `src0`、`src1`、`dst`、`rows`、`length`、广播方式 | 逐元素相减；输出保持公共输入 dtype。 |
| 18 | `VECTOR_MUL` | IVE | P0，已实现 | `src0`、`src1`、`dst`、`rows`、`length`、广播方式 | 逐元素相乘，结果写为 INT32。 |
| 19 | `VECTOR_FMA` | IVE | P0，已实现 | `src0`、`src1`、`src2`、`dst`、`rows`、`length`、三路广播方式 | 计算 `src0*src1+src2`，结果写为 INT32。 |
| 20 | `VECTOR_MAX` | IVE | P0，已实现 | `src0`、`src1`、`dst`、`rows`、`length`、广播方式 | 写入逐元素较大值，输出保持公共输入 dtype。 |
| 21 | `VECTOR_MIN` | IVE | P0，已实现 | `src0`、`src1`、`dst`、`rows`、`length`、广播方式 | 写入逐元素较小值，输出保持公共输入 dtype。 |
| 22 | `VECTOR_CMP`（`VCMP_I`） | IVE | P0，已实现 | `src0`、`src1`、`src2[15:13]`、`dst`、`rows`、`length`、前两路广播方式 | 按公共输入 dtype 比较。`src2[15:13]` 依次编码 EQ、NE、LT、LE、GT、GE，低 13 bit 必须为 0；每个结果写为 INT8 mask，真值为 1、假值为 0。 |
| 23 | `VECTOR_SELECT` | IVE | P0，已实现 | `src0`、`src1`、`src2` mask、`dst`、`rows`、`length`、前两路广播方式 | `src2` 指向 `VECTOR_CMP` 产生的 INT8 mask；mask 非零选 `src0`，零选 `src1`。 |
| 24 | `VECTOR_CLAMP` | IVE | P0，已实现 | `src0`、`src1` 下限、`src2` 上限、`dst`、`rows`、`length` | `src1`、`src2` 是 signed16 立即数而非地址；输出保持公共输入 dtype。 |
| 25 | `VECTOR_RELU` | IVE | P0，已实现 | `src0`、`dst`、`rows`、`length` | 计算 `max(src0,0)`；未使用输入字段和对应广播字段必须为 0。 |
| 26 | `COMPLEX_ACT` | CME | P0，已实现 | `src0`、`dst`、`rows`、`length`、函数、输入/输出 scale 指数、目标 dtype、截断区间 | 执行 Sigmoid、Tanh、GELU 或 SiLU；内部使用 FP32。 |
| 27 | `COMPLEX_SOFTMAX` | CME | P0，已实现 | `src0`、可选 `aux`、`dst`、`rows`、`length`、mask 模式、scale 指数、目标 dtype | 逐行 Softmax，支持 boolean mask 和 valid length；causal 模式当前返回命令字段错误。 |
| 28 | `COMPLEX_NORM` | CME | P0，已实现 | `src0`、gamma/beta `aux`、`dst`、`rows`、`length`、Norm 类型、epsilon、scale 指数、目标 dtype | 执行 LayerNorm 或 RMSNorm；参数按连续 L1 区域读取。 |
| 29 | `COMPLEX_ROPE` | CME | P1，功能位关闭 | 操作码与命令位置已分配 | 当前提交返回 `ILLEGAL_OPCODE`，不得启动 CME 或写目标张量。 |
| 30 | `COMPLEX_STAT` | CME | P0，已实现 | `src0`、`dst`、`rows`、`length`、统计模式 | 按行求 SUM、MAX 或 SUMSQ，每行写一个 INT32 结果。 |
| 31 | `COMPLEX_RECIP` | CME | P1，功能位关闭 | 操作码与命令位置已分配 | 当前提交返回 `ILLEGAL_OPCODE`，不得启动 CME 或写目标张量。 |
| 32 | `COMPLEX_ADD_RESCALE` | CME | P0，已实现 | `src0`、`aux`、`dst`、`rows`、`length`、三个 scale 指数、目标 dtype | 按两个输入 scale 相加，再按目标 scale 写回整数结果。 |

数值 33..63 当前没有定义，必须返回 `ILLEGAL_OPCODE`。`DMA_GATHER_ND`、
`COMPLEX_ROPE` 与 `COMPLEX_RECIP` 只有在功能寄存器声明支持后才能执行，
且已有位格式不得改变。

### 6.4 为什么不使用 64 bit 指令加共享 CSR

单条 64 bit 指令无法同时容纳地址、shape、两个等待事件、一个完成事件、
dtype、执行选项和足够的操作专有参数。把超出的字段放入共享 CSR 会引入以下
问题：

- 每条任务提交前要先写多组配置寄存器，增加 AXI 事务和驱动开销。
- 多个线程、进程或虚拟机提交时需要互斥，否则命令可能看到其他提交者刚写的
  配置。
- CFE 必须在接收点复制全部相关 CSR，形成配置快照；只保存 64 bit 指令会让
  后续 CSR 写入改变队列中旧任务的含义。
- 允许乱序发射和多个执行单元并行时，每条未完成任务都要关联自己的 CSR
  快照，任务表存储和一致性控制并未减少。
- 配置写与命令写之间还需要严格排序；错误恢复时也要判断哪些配置已经生效。

128 bit 恰好由两个 64 bit FIXED beat 传输。CFE 只有在两拍完整且字段检查
通过后才创建一条任务，因此可把它们原子组成一个自包含 Task Context。任务
队列不依赖随后变化的共享寄存器，多个提交者可只围绕命令 FIFO 分配
command_id，调度器也能直接比较 Event 与执行单元条件。相对“多次 CSR 写加
一次命令写”，两个连续 beat 还能减少控制总线事务，提高流水发射利用率。

## 7. 地址引用

### 7.1 DMA AREF28

DMA 源和目标使用 28 bit `AREF28`：

```text
bit 27      global
bits 26:24 base
bits 23:0  offset24
```

`global=0` 表示 L1 地址，此时 `base` 必须为 0，字节地址等于 `offset24`。
`global=1` 表示系统存储虚拟地址，字节地址为 `GADDR_BASE[base]+offset24`。

| `base` | 全局基址 |
| ---: | --- |
| 0 | zero |
| 1 | input |
| 2 | weight |
| 3 | work |
| 4 | output |
| 5 | kv |
| 6..7 | 保留 |

基址 0 的值固定为 0。其余基址由驱动在提交任务组前写 CSR，并在任务组执行
期间保持不变。所有引用都要检查首地址、末地址和整数溢出。

### 7.2 Matrix LREF

- A、B、C 使用 `LREF14`，L1 字节地址为 `ref << 6`，即 64 byte 对齐。
- bias 使用 `LREF12`，L1 字节地址为 `ref << 6`；值 0 表示不使用 bias。
- 因 bias 的 0 有特殊含义，需要 bias 时不能把它放在 L1 地址 0。

### 7.3 Vector/Complex LREF

IVE 与 CME 使用 `LREF16`，L1 字节地址为 `ref << 4`，即 16 byte 对齐。
CLAMP 的 `src1/src2` 和 CMP 的 `src2` 是立即数或模式字段，不按 LREF
解释。

## 8. Control payload 与事件

### 8.1 payload

| bit | 字段 |
| ---: | --- |
| 79:76 | `engine_mask` |
| 75 | `join_mode` |
| 74:0 | 保留，必须为 0 |

`engine_mask[3:0]` 依次选择 DMA、Matrix、IVE、CME，仅 FENCE 使用且至少
一位为 1。`join_mode` 仅 JOIN 使用：0 表示两个等待事件都成功才成功，1
表示任一事件成功即成功，只有两个事件都失败才失败。NOP 要求三个事件字段
都是 0xff。SIGNAL 和 REARM 要求 `signal!=0xff`。JOIN 要求 wait0、
wait1、signal 都有效。

### 8.2 Event Table

每个 Event 表项至少保存：

```text
state: FREE / RESERVED / SUCCESS / ERROR
generation
producer_command_id
error_status
waiter_count
```

任务接收时，TS 读取 wait0、wait1、signal 对应表项的 generation，并把
`{id,generation}` 写入内部 Task Context。等待事件 ERROR 时，任务进入
DEPENDENCY_FAILED，且不能启动执行单元。

REARM 只有在旧事件已到 SUCCESS 或 ERROR 且 `waiter_count=0` 时才允许；
它将 generation 加 1，并把新一代状态改为 FREE，之后的任务才可以把该
Event ID 作为 signal。旧事件仍处于 RESERVED、存在等待者或 ID 为 0xff
时返回 BAD_DESC。

Event ID 数量小于模型任务总数时，编译器负责安排复用。REARM 必须放在隔离
的任务组之间：主机等待前一组全部到终态，读取结果并 ACK，提交 REARM，
等待其到终态并 ACK，之后才提交下一组。不能在仍有旧任务接收或等待时重用
同一 ID。

### 8.3 完成与 ACK

任务到终态后保留 command_id、状态、时间戳、进度、错误地址和中断标志，
直到主机 ACK。ACK 释放 Task 表项和 command_id。仅仅读取状态不能释放
表项。主机在切换全局基址、复位 Event ID 或回收输入输出区前，必须完成相应
等待与 ACK。

## 9. DMA/Layout payload

### 9.1 COPY1D 与 COPYND

| bit | 字段 |
| ---: | --- |
| 79:52 | `src_aref` |
| 51:24 | `dst_aref` |
| 23:4 | `count` |
| 3:2 | `dst_dtype` |
| 1 | `src_nibble` |
| 0 | `dst_nibble` |

`dtype` 是源 dtype。`count` 是元素数且必须非零。相同 dtype 原样复制；
变宽做符号扩展，变窄做饱和，目标 INT4 做半字节打包。`dst_nibble` 必须
为 0；源 INT4 可用 `src_nibble` 选择首元素所在半字节。

COPYND 采用与 COPY1D 相同的连续元素字段。高层多层
stride 操作由编译器拆成多条 COPYND/COPY1D，或结合 PACK、SPLIT、
TRANSPOSE。硬件不得再读取 stride 参数块。

### 9.2 FILL

| bit | 字段 |
| ---: | --- |
| 79:52 | `dst_aref` |
| 51:32 | `count` |
| 31:0 | `fill_value` |

`dtype` 是目标 dtype。按目标元素宽度截取 `fill_value` 的低位并重复写入。

### 9.3 TRANSPOSE

| bit | 字段 |
| ---: | --- |
| 79:52 | `src_aref` |
| 51:24 | `dst_aref` |
| 23:16 | `rows` |
| 15:8 | `columns` |
| 7:6 | `dst_dtype` |
| 5 | `src_nibble` |
| 4 | `dst_nibble` |
| 3:0 | 保留 |

行列值必须非零，源/目标 dtype 必须相同，`dst_nibble=0`，保留位为 0。
输入是 `[rows][columns]`，输出是 `[columns][rows]`。

### 9.4 PACK 与 SPLIT

| bit | 字段 |
| ---: | --- |
| 79:52 | `src_aref` |
| 51:24 | `dst_aref` |
| 23:16 | `segment_count` |
| 15:8 | `segment_bytes` |
| 7:0 | `segment_stride` |

三项都必须非零，且 `segment_stride>=segment_bytes`。PACK 从带间隔的
segments 读出并连续写入；SPLIT 从连续区域读出并按 stride 写入。所有 DMA
操作先检查完整源/目标区域；失败时不得留下部分目标写入。

### 9.5 GATHER_ND

`DMA_GATHER_ND` 使用以下 P1 payload：

| bit | 字段 |
| ---: | --- |
| 79:52 | `src_aref`，全局数据区起始地址 |
| 51:36 | `index_lref`，L1 中的 UINT32 索引表 |
| 35:20 | `dst_lref`，L1 连续目标区 |
| 19:12 | `block_count-1` |
| 11:0 | `block_bytes-1` |

`index_lref` 和 `dst_lref` 均按 `LREF16` 解释，实际地址为字段值乘 16。
`block_count` 范围为 1～256，`block_bytes` 范围为 1～4096。索引表包含
`block_count` 个 UINT32 元素。第 $i$ 个数据块的全局起始地址与 L1 目标
地址分别为：

$$
\begin{aligned}
\mathrm{src}_i
  &= \mathrm{src\_base}
     + \mathrm{index}[i]\times\mathrm{block\_bytes},\\
\mathrm{dst}_i
  &= \mathrm{dst\_base}
     + i\times\mathrm{block\_bytes}.
\end{aligned}
$$

因此，数据块可以位于全局内存中不相邻的位置，写入 L1 后则连续保存。索引表
本身必须先由软件或 DMA 放入 L1。INT4 数据按字节块读取，单个块必须从完整
字节开始，`block_bytes` 已包含打包后的实际字节数。

该指令的 opcode 和 payload 已分配，但当前功能位为 0。CFE 收到该指令时返回
`ILLEGAL_OPCODE`，不得读取索引表、访问全局内存或修改 L1。启用功能位后，
硬件还必须先检查索引表和完整目标区域，再开始提交目标写入。

## 10. Matrix payload

### 10.1 GEMM、ACCUM、ZERO

| bit | 字段 |
| ---: | --- |
| 79:66 | `A` LREF14 |
| 65:52 | `B` LREF14 |
| 51:38 | `C` LREF14 |
| 37:26 | `bias` LREF12，0 表示不用 |
| 25:20 | `M-1` |
| 19:14 | `N-1` |
| 13:8 | `K-1` |
| 7 | `b_int4` |
| 6:5 | `C_dtype` |
| 4:0 | `requant_shift` |

`dtype` 是 A dtype。B 的选择规则见 2.3。A 为行优先 `[M][K]`；B 为
按 `KT×NT` tile 保存的 `[K][N]`；C 为行优先 `[M][N]`。

GEMM 可使用 bias，且 bias 必须是 `N` 个 INT32。ACCUM 要求 C_dtype=INT32、
bias=0、shift=0，把新的乘加值加入原 C。ZERO 是特殊形式：

- A=0、B=0、bias=0、`b_int4=0`；
- C_dtype=INT32、`requant_shift=0`；
- 编码的 `K-1` 必须为 0，解码后 ZERO 不执行 K 运算；
- 只清零 C 指向的 `[M][N]` INT32 区域。

### 10.2 BMM

| bit | 字段 |
| ---: | --- |
| 79:66 | `A` LREF14 |
| 65:52 | `B` LREF14 |
| 51:38 | `C` LREF14 |
| 37:32 | `batch-1` |
| 31:26 | `M-1` |
| 25:20 | `N-1` |
| 19:14 | `K-1` |
| 13 | `b_int4` |
| 12:11 | `C_dtype` |
| 10:6 | `requant_shift` |
| 5:0 | 保留，必须为 0 |

各 batch 的 A、B、C 紧邻保存。B 的每个 batch 都使用同样的 tiled 排列。
BMM 不带 bias。

### 10.3 Matrix 执行

Matrix 前端按 `MT=8, KT=16, NT=8` 形成 tile。尾部 tile 只对有效 M/N/K
位置读写，填充位置视为 0。乘法器结果进入宽累加器；最终写 C 前执行 bias、
shift、最近偶数舍入和饱和。INT32 结果不执行 shift。

引擎状态可描述为 `IDLE -> LOAD_A/B -> MAC -> POST -> WRITE_C -> DONE`。
实现允许 A/B 预取与当前 tile 的 MAC 并行，但必须满足：

- 数据读取错误发生后不再提交新的目标写；
- DONE 只能在所有 C 写响应完成后发送；
- ACCUM 在读旧 C 后才能覆盖对应位置；
- 同一任务的进度按已提交目标元素数单调增加。

## 11. Vector payload

### 11.1 公共格式

| bit | 字段 |
| ---: | --- |
| 79:64 | `src0` LREF16 |
| 63:48 | `src1` LREF16 或 signed16 |
| 47:32 | `src2` LREF16、mask 或模式 |
| 31:16 | `dst` LREF16 |
| 15:11 | `rows-1` |
| 10:6 | `length-1` |
| 5:4 | `broadcast0` |
| 3:2 | `broadcast1` |
| 1:0 | `broadcast2` |

Broadcast 编码：

| 值 | 说明 |
| ---: | --- |
| 0 | 无，输入形状 `[rows][length]` |
| 1 | scalar，单元素用于全部位置 |
| 2 | row，形状 `[rows][1]` |
| 3 | feature，形状 `[1][length]` |

### 11.2 操作语义

- ADD：`dst=src0+src1`。
- SUB：`dst=src0-src1`。
- MUL：`dst(INT32)=src0*src1`。
- FMA：`dst(INT32)=src0*src1+src2(INT32)`。
- MAX/MIN：逐元素较大值/较小值。
- RELU：`dst=max(src0,0)`；`src1=src2=0` 且 broadcast1/2=0。
- CMP：`src2[15:13]` 是比较模式，`src2[12:0]` 必须为 0；模式
  0..5 依次是 EQ、NE、LT、LE、GT、GE。输出为 INT8 mask，真写 1，假写 0；
  `broadcast2=0`。
- SELECT：`src2` 指向 INT8 mask；mask 非零选择 src0，否则选择 src1；
  `broadcast2=0`。
- CLAMP：`src1` 与 `src2` 分别是 signed16 下限和上限，不是地址；
  `broadcast1=0`、`broadcast2=0`，且下限不得大于上限。

ADD、SUB、MAX、MIN 以及未使用第三输入的指令要求 `src2=0`。每条指令先
检查参与输入和完整目标区域。IVE 按 lane 顺序处理，最后一个向量不足 lane
数的位置不写。

## 12. Complex payload

### 12.1 公共格式

| bit | 字段 |
| ---: | --- |
| 79:64 | `src0` LREF16 |
| 63:48 | `aux` LREF16 |
| 47:32 | `dst` LREF16 |
| 31:27 | `rows-1` |
| 26:19 | `length-1` |
| 18:0 | `meta19` |

`dtype` 是 src0 和常规 aux 的输入 dtype。scale 指数字段都是 signed4，
实际 scale 为 `2^e`。CME 内部使用 FP32；写回时目标仍是 INT4、INT8、
INT16 或 INT32。

### 12.2 ACT

```text
meta19[18:17] function: 0 sigmoid, 1 tanh, 2 GELU, 3 SiLU
meta19[16:13] src_scale_exp
meta19[12:9]  dst_scale_exp
meta19[8:7]   dst_dtype
meta19[6:5]   clip_profile: ±16, ±8, ±4, ±2
meta19[4:0]   0
```

函数定义：

```text
sigmoid(x) = 1 / (1 + exp(-x))
tanh(x)    = (exp(2x)-1) / (exp(2x)+1)
GELU(x)    = 0.5*x*(1+tanh(sqrt(2/pi)*(x+0.044715*x^3)))
SiLU(x)    = x*sigmoid(x)
```

输入先限制到 clip profile 的区间，再计算函数。

### 12.3 SOFTMAX

```text
meta19[18:17] mask_mode: 0 none, 1 boolean, 2 causal, 3 valid_length
meta19[16]    all_mask_mode: 0 写零, 1 报错
meta19[15:12] src_scale_exp
meta19[11:8]  dst_scale_exp
meta19[7:6]   dst_dtype
meta19[5:0]   0
```

本设计不支持 causal，编码 2 返回 BAD_DESC。boolean 模式下 aux 指向与输入同
形状的 INT8 mask；valid_length 模式下 aux 指向每行一个 INT32 有效长度。
每行先求最大值 `m`，再计算 `exp(x_i-m)`，求总和后相除。全部被遮住时按
`all_mask_mode` 写零或报告 NUMERIC_EXCEPTION。私有暂存需求为 `length`
个 FP32 元素。

### 12.4 NORM

```text
meta19[18]    0 LayerNorm, 1 RMSNorm
meta19[17:16] epsilon profile: 1e-5, 1e-6, 1e-3, 1e-4
meta19[15:12] src_scale_exp
meta19[11:8]  parameter_scale_exp
meta19[7:4]   dst_scale_exp
meta19[3:2]   dst_dtype
meta19[1:0]   0
```

aux 指向长度为 `length` 的 gamma。LayerNorm 的 beta 紧随 gamma 区，
其起始地址是 `aux + align_up(gamma_bytes,64)`；RMSNorm 不读 beta。

```text
LayerNorm: y_i = (x_i-mean)/sqrt(var+epsilon)*gamma_i+beta_i
RMSNorm:   y_i = x_i/sqrt(mean(x_i*x_i)+epsilon)*gamma_i
```

### 12.5 STAT

```text
meta19[18:17] mode: 0 SUM, 1 MAX, 2 SUMSQ
meta19[16:0]  0
```

每行写一个 INT32。SUM 是元素和，MAX 是最大元素，SUMSQ 是平方和；内部
采用足够宽的整数或 FP32 暂存，最终按 INT32 饱和。模式 3 非法。

### 12.6 ADD_RESCALE

```text
meta19[18:15] src0_scale_exp
meta19[14:11] src1_scale_exp
meta19[10:7]  dst_scale_exp
meta19[6:5]   dst_dtype
meta19[4:0]   0
```

aux 是与 src0 同形状的第二输入：

```text
real = src0 * src0_scale + aux * src1_scale
dst  = saturate(round_nearest_even(real / dst_scale))
```

### 12.7 ROPE 与 RECIP

操作码和命令位置已经分配，但 feature 位为 0。CFE/TS 解码后返回
ILLEGAL_OPCODE；不得把它们解释成 ACT 或其他函数。

## 13. CFE 与 Task Scheduler

### 13.1 CFE 模块接口

外部命令侧为 64 bit：

```text
gc_cmd_valid_i, gc_cmd_ready_o
gc_cmd_data_i[63:0]
gc_cmd_first_i, gc_cmd_last_i
gc_rsp_valid_o, gc_rsp_ready_i, gc_rsp_data_o[63:0]
```

TS 侧同样采用 64 bit 两拍：

```text
ts_cmd_valid_o, ts_cmd_ready_i
ts_cmd_data_o[63:0]
ts_cmd_first_o, ts_cmd_last_o
```

command_id 查询接口：

```text
cmd_id_lookup_valid_o
cmd_id_lookup_ready_i
cmd_id_lookup_id_o[9:0]
cmd_id_lookup_rsp_valid_i
cmd_id_busy_i
```

CFE 状态为 `IDLE -> WAIT_HI -> CHECK -> LOOKUP_ID -> ENQUEUE ->
RESP_OK/RESP_ERR`。低拍握手后只接受带 `last=1` 的高拍；最多等待 32 cycles。
检查成功且 ID 空闲时，两拍进入 FIFO，并在接收响应中返回 SUCCESS。该响应
只表示命令已接收，不表示任务已执行。

### 13.2 Task Context

TS 为每个任务保存原始 16 byte CMD128，以及接收时取得的三个事件代次。
内部展开器从 payload 产生：

- 执行单元与完整 opcode；
- 地址引用解析结果；
- dtype、形状、broadcast、scale、bias 和模式；
- timeout、ordered、中断与 strict numeric；
- 目标区域大小及错误检查信息。

展开字段可放在 Task 表或执行单元本地寄存器中。它们只能从 16 byte CMD128
产生，不能触发 MIF 任务参数读取。Task Context 读端口可以采用两拍
64 bit ready/valid：

```text
ctx_req_valid, ctx_req_ready, ctx_task_slot, ctx_word
ctx_rsp_valid, ctx_rsp_ready, ctx_data[63:0], ctx_status
```

### 13.3 TS 到执行单元

四个端口分别服务 DMA、Matrix、IVE、CME：

```text
eng_req_valid, eng_req_ready, eng_req_data[63:0]
eng_cancel_valid, eng_cancel_ready, eng_cancel_status[7:0]
eng_done_valid, eng_done_ready, eng_done_data[63:0]
eng_done_first, eng_done_last
eng_abort
eng_quiescent
```

请求 beat 至少标识 task slot、command_id、opcode、flags 和 Context 选择值。
执行单元读取两个 64 bit Context word 或已展开字段后执行。完成消息使用三拍：

1. command_id、status、opcode、done flags；
2. fault address；
3. progress 与 error info。

完成发送者在反压时保持 beat 和 first/last。TS 核对 command_id、执行单元
和 opcode；协议错误写首错记录，不能误完成其他任务。

### 13.4 TS 功能时序

1. 接收 CFE 两拍并保存 16 byte Task Context。
2. 检查 opcode、保留位、dtype、command_id 和事件资源。
3. 从 Event Table 取得代次并登记等待者/生产者。
4. inline 展开；任何错误直接进入终态，不发执行单元请求。
5. 等待 wait0/wait1；失败事件产生 DEPENDENCY_FAILED。
6. 检查 ordered、执行单元空闲和前序任务。
7. 与执行单元完成请求握手，状态变为 RUNNING，启动 timeout。
8. 接收三拍完成消息，更新 signal Event、终态记录和中断。
9. 主机查询并 ACK 后释放 Task 表项。

## 14. 执行单元数据接口与时序

### 14.1 L1BUF 端口

L1 每个端口都是独立 64 bit ready/valid。参考配置有 13 个读端口：
DMA；Matrix A/B/AUX；IVE src0/src1/src2/mask；CME src0/src1/src2/mask；
Debug。5 个写端口：DMA、Matrix C、IVE dst、CME dst、Debug。

读请求：

```text
rd_req_valid, rd_req_ready
rd_req_addr[19:0], rd_req_beats[7:0], rd_req_tag[11:0]
rd_rsp_valid, rd_rsp_ready
rd_rsp_data[63:0], rd_rsp_tag[11:0], rd_rsp_last, rd_rsp_status
```

写请求和数据：

```text
wr_req_valid, wr_req_ready
wr_req_addr[19:0], wr_req_beats[7:0], wr_req_tag[11:0]
wr_data_valid, wr_data_ready
wr_data[63:0], wr_strb[7:0], wr_last
wr_rsp_valid, wr_rsp_ready, wr_rsp_tag[11:0], wr_rsp_status
```

16 个 bank 由 64 bit word address 的低 4 bit 选择。同一周期同一 bank 只
接受一个 SRAM 操作；仲裁器轮转服务并对等待超过参考阈值的请求提高优先级。
读响应在请求真正取得 bank 后两周期出现。写数据可通过一个输入缓冲保持，
写响应只在最后 beat 落入 SRAM 后产生。

### 14.2 DMA 时序

全局到 L1：

1. DMA 解析 AREF 并向 TBU/MIF 发读请求。
2. MIF 接收 R beat，按 tag 放入返回队列。
3. DMA 处理 dtype、半字节和排列。
4. DMA 通过 L1 写端口提交 beat。
5. 所有 L1 写响应完成后发送 DONE。

L1 到全局：

1. DMA 从 L1 读端口取数据。
2. 完成 dtype/排列处理并形成 WDATA/WSTRB。
3. MIF 接收请求和写数据。
4. 收到全部 B 响应后发送 DONE。

ADDR_FAULT 或总线错误后停止新请求，排空已经接收的响应，目标是否部分写入由
done flags 报告。

### 14.3 Matrix 时序

Matrix 为 A、B 和可选 bias/旧 C 发读请求。A/B tile 就绪后进入 MAC；
下一 tile 的读取可以和当前 MAC 重叠。POST 完成 bias 与重缩放，WRITE_C
通过单独写端口提交。最后一个 C 写响应返回后才发送 DONE。

### 14.4 IVE 时序

IVE 依据 broadcast 只读取所需元素：scalar 读一次，row 每行读一次，
feature 每列复用，无 broadcast 则逐元素读取。输入对齐后 lane 执行，结果
经饱和器和 WSTRB 写 L1。CMP mask 与 SELECT mask 都以 INT8 读取/写入。

### 14.5 CME 时序

CME 每行分阶段运行：

- ACT、ADD_RESCALE：读入、FP32 函数、整数写回，可按 lane 流动执行。
- SOFTMAX：读整行并求最大值，计算 exp 与总和，再读私有暂存完成除法和写回。
- NORM：读整行形成 mean/variance 或 mean-square，再结合 gamma/beta 写回。
- STAT：扫描一行后写一个 INT32。

CME 私有 FP32 暂存不可由 AXI Slave 或其他执行单元寻址。任务取消时丢弃未
提交结果并排空已握手的 L1 响应。

## 15. MIF 与 TBU

### 15.1 DMA 到 MIF 内部请求

内部数据接口为 64 bit：

```text
req_valid, req_ready
req_write
req_vaddr[63:0]
req_beats
req_tag
req_task_id
req_attr

wvalid, wready
wdata[63:0], wstrb[7:0], wlast, wtag

rsp_valid, rsp_ready
rsp_data[63:0], rsp_tag, rsp_last, rsp_status
```

部署配置只启用 DMA owner。诊断测试使用的第二 owner 不得在部署任务中产生
请求。

### 15.2 TBU

TBU 最多保存 64 条页规则和 8 个查询中的请求。每条规则定义
`vaddr[47:12]`、`paddr[39:12]`、stream ID、substream ID、读权限和写
权限。页内低 12 bit 保持不变。请求处理：

1. 用虚拟页号及 stream/substream ID 选择有效规则。
2. 检查读写权限和地址加法溢出。
3. 形成物理地址及 AXI 属性。
4. 未找到规则返回 DECERR；权限失败返回 SLVERR/ADDR_FAULT。

软件在停止接收新任务并等待 DMA 空闲后才能修改 TBU 规则或全局基址。

### 15.3 MIF 未完成事务

每项保存 AXI ID、DMA tag、task ID、方向、起始地址、beat 数、已返回 beat
数和首个错误。MIF 可以让多个读 burst 并行；写地址与写数据的配对必须固定。
跨页或超过最大 burst 的请求拆成多个子请求，DMA 看到的 tag 和完成语义保持
不变。复位、abort 和总线错误都必须释放 AXI ID，不能把迟到响应交给新任务。

## 16. LSC、CRG、WDT 与中断

### 16.1 LSC

LSC 至少提供：

- 能力寄存器：opcode feature、L1 大小、tile 参数、lane 数。
- `GADDR_BASE[0..5]` 与 TBU 控制。
- 4 个 timeout class 周期值。
- CMD FIFO 状态与接收响应。
- Task 查询、WAIT、ACK、FENCE。
- 首错状态、fault address、error info、ECC 记录。
- 成功/错误中断使能、状态和清除。
- DMA、Matrix、IVE、CME active/stall 周期与完成计数。
- stop_accept、quiesce、abort、受控软复位。

参考 CSR 偏移：

| 偏移 | 寄存器 |
| ---: | --- |
| `0x0000` | NPU_VERSION |
| `0x0008` | ISA_FEATURE |
| `0x0010` | BUS_CONFIG |
| `0x0018` | L1_CONFIG |
| `0x0020` | MATRIX_CONFIG |
| `0x0028` | VECTOR_CONFIG |
| `0x0030` | CME_CONFIG |
| `0x0040` | CORE_CONTROL |
| `0x0048` | CORE_STATUS |
| `0x0050..0x0078` | zero/input/weight/work/output/kv 全局基址 |
| `0x0080` | M_AXI_ADDR_BASE |
| `0x0088` | M_AXI_ADDR_LIMIT |
| `0x0090` | TBU_STREAM_ID |
| `0x00a0` | IRQ_STATUS |
| `0x00a8` | IRQ_MASK |
| `0x00b0` | FAULT_CMD |
| `0x00b8` | FAULT_ADDR |
| `0x00c0` | FAULT_INFO |
| `0x00c8` | FAULT_CLEAR |
| `0x00e8` | RESET_REASON |
| `0x00f0` | L1_DIAG_CONTROL |
| `0x00f8` | FAULT_DETAIL |
| `0x0100..0x0178` | PERF[0..15] |
| `0x0180` | PERF_CONTROL |
| `0x0200..` | TIMEOUT_CLASS |

CSR 是 64 bit little-endian 寄存器。CMD128 只选择 timeout class 0..3；实现可以
保留更多诊断类，但不能由 CMD128 选择。`ISA_FEATURE` 的 ROPE、RECIP 与
causal softmax 位为 0。

配置寄存器在 Task 或 DMA 活动时写入应返回 BUSY。首错寄存器保持第一次错误，
直到软件明确清除。

### 16.2 中断

TS 在任务进入终态的周期，根据 CMD bit87/86 产生 success/error 事件。
LSC 将事件置入中断状态寄存器；顶层 `irq_success`、`irq_error` 可为电平
输出，直到软件清除。清除中断不等于 ACK 任务。

### 16.3 受控复位

1. 软件置 stop_accept，CFE 不再接收新 CMD。
2. TS 等待正常完成；若达到控制超时则向执行单元发 cancel/abort。
3. MIF 排空已发 AXI 请求，L1 写端口空闲。
4. CRG 让各模块在有效时钟上观察 `reset_n=0`。
5. 清除 Task/Event/队列/错误状态，保留 L1 SRAM 内容。
6. `reset_n=1` 同步释放，软件重新写全局基址、TBU 和 timeout。

WDT 超时走同一受控过程；若 NoC 域独立复位丢失传输状态，活动 DMA 直接以
ABORTED 终止。

## 17. 软件编译与驱动

### 17.1 编译器输入与降低

模型编译器接收 Keras、PyTorch、TFLite 或 ONNX。前端统一张量形状、整数
dtype 和 scale，进行常量折叠、L1 生命周期分配、操作选择、Event ID 安排与
任务组划分。

Conv2D 降低为 im2col/数据准备、PACK/TRANSPOSE 和 GEMM；数据形状或算子
不适合 NPU 时允许 CPU 辅助。循环网络和 Transformer 由 GEMM、IVE、CME
与 DMA 组合。未启用的 ROPE/RECIP 必须由其他可用指令或 CPU 实现。

### 17.2 生成文件

默认输出模型专用 `.c/.h`，至少包含：

- NPU 配置与要求的 feature；
- CMD128 指令数组；
- 权重和常量数组；
- 输入、输出及操作信息；
- 全局基址和 L1 区域信息；
- 任务组、WAIT、Event REARM、ACK 的同步信息。

部署输出不包含外部任务参数数组，也不默认输出裸二进制。若工具另行提供诊断
导出，文件名和 manifest 必须明确标为 diagnostic，驱动不得把它当作部署
产物。

### 17.3 驱动提交次序

1. 读取能力并确认所需 opcode 与数据类型均受支持。
2. 配置 TBU、全局基址、timeout 和中断。
3. 通过 L1 窗口或 DMA 装载权重、常量和输入。
4. 逐条以 FIXED burst 写 CMD 固定地址，读取接收响应。
5. 按生成的任务组信息 WAIT/FENCE。
6. 读取输出和每个任务终态；处理 fault address/error info。
7. ACK 已完成 command_id。
8. 在隔离点执行 Event REARM，等待并 ACK REARM 后提交下一任务组。

## 18. 验证要求

### 18.1 指令检查

- 对 33 个已分配 opcode 做编码/解码互反测试。
- 对公共头每个字段做 bit-accurate little-endian 测试。
- 对所有保留位、非法 dtype、重复 command_id、同一 signal/wait ID 做负例。
- 明确检查 GATHER_ND、ROPE、RECIP 在功能位关闭时返回
  ILLEGAL_OPCODE，且目标数据保持不变。
- 检查提交过程中 MIF 没有任务参数读取。

### 18.2 数值检查

- INT4 半字节顺序、符号扩展、奇数元素数。
- INT8/INT16/INT32 最近偶数舍入和饱和。
- 四种 Matrix 输入组合、四种 C dtype、bias 的列位置。
- ZERO 特殊保留字段、ACCUM 旧 C、BMM 多 batch stride。
- Vector 三个 broadcast、CMP 六种模式、SELECT mask、CLAMP signed16。
- ACT 四函数、SOFTMAX 支持的三种 mask 输入、LayerNorm、RMSNorm、
  STAT 三模式、ADD_RESCALE。
- strict numeric 的 NaN/Inf/全 mask/除零错误。

### 18.3 模块时序检查

- 每个 ready/valid 接口在反压时数据稳定。
- CMD 两拍顺序、FIXED burst、第二拍 timeout。
- Event 代次在命令接收时固定，REARM 不改变旧等待者。
- L1 同 bank 竞争、2-cycle 读延迟、ECC corrected/uncorrectable。
- MIF 多事务、AXI ID 复用、页拆分、SLVERR/DECERR、Core/NoC 异步复位。
- cancel 后响应排空，DONE 在最终写响应之后。
- 中断清除与 Task ACK 相互独立。

## 19. 完整任务示例

### 19.1 GEMM 后接激活

1. DMA COPY1D 把输入与已排列权重搬入 L1，分别 signal E1/E2。
2. GEMM 等待 E1/E2，写 INT32 或目标整数 C，signal E3。
3. ACT 等待 E3，从 C 读入并写输出区，signal E4。
4. DMA 等待 E4，把结果复制到 output 全局区，signal E5。
5. 主机 WAIT E5，查询并 ACK 以上 command_id。

每条任务的全部参数均在自己的 CMD128 内，执行过程中只有 DMA 访问系统存储。

### 19.2 Conv2D

编译器先用 DMA/PACK/TRANSPOSE 或 CPU 辅助形成 im2col，再发 GEMM；bias 的
第 `j` 个 INT32 值加到输出矩阵第 `j` 列全部行。后续 RELU/ACT 和输出 DMA
依靠 Event ID 串接。

### 19.3 Event ID 复用

任务组 A 使用 E7，主机等待组 A 全部到终态并 ACK；随后单独提交 REARM E7，
等待 REARM 成功并 ACK，再提交任务组 B。组 B 接收时取得新的 generation。
主机不能把 REARM 与组 A 最后一批仍在 CFE FIFO 的命令同时提交。
