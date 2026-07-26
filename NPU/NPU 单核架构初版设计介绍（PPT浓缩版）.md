# NPU 单核架构初版设计介绍

> [!summary]
> 本设计从单核开始。外部 Generic Core 负责模型调度，NPU 通过 64-bit AXI
> Slave 接收控制访问和 CMD128，通过 64-bit AXI Master 访问系统内存。
> CMD128 V2 把任务参数直接放入指令，不再从外部内存读取 Descriptor。

## 1. 设计目标

- 面向 Transformer、RNN、GRU、LSTM 和常见全连接网络。
- 软件可见张量支持 INT4、INT8、INT16、INT32；Matrix 使用 INT32 保存乘加结果。
- Sigmoid、Tanh、GELU、SiLU、Softmax 和 Norm 在 Complex Engine 内部执行
  `INT → FP32 → INT`，FP32 中间值不写入软件可见张量。
- 总线数据宽度为 64 bit；一条 128-bit 指令使用相邻的 low、high 两个 beat。
- 第一版不设置卷积执行单元。Conv2D 由编译器拆成数据整理、im2col、GEMM、
  bias 和输出整理；CPU 可处理硬件指令不适合承担的步骤。
- Matrix 的分块乘加与 INT32 部分和处理可同时推进，减少执行单元等待。

## 2. 单核总体结构

![[assets/npu_single_core_architecture_ppt.png]]

图中的 Generic Core 是 NPU 外部的主控 CPU。CPU 运行模型函数和 C 驱动，以
AXI Master 身份访问 NPU 的 AXI Slave。NPU 内的 MIF 以 AXI Master 身份接入
同一个 SoC AXI Fabric。图中上下两个总线框只是同一系统互连的两处视图。

> [!note]
> DDR Controller 位于 NPU 外部，也接在系统 AXI Fabric 上。MIF 发出的地址由
> 系统互连送往 DDR Controller、共享存储或其他允许访问的设备。

## 3. 外部 CPU 如何提交指令

NPU AXI Slave 提供三类访问入口：

| 入口 | 访问方式 | 用途 |
| --- | --- | --- |
| `CMD_FIFO_DATA` | 固定地址、`AWBURST=FIXED` | 提交 CMD128 |
| LSC 控制寄存器 | 普通 AXI 读写 | 启动、停止、状态、中断、基地址和计数器 |
| L1BUF 外部窗口 | 普通 AXI 读写 | 调试或软件准备少量片上数据 |

驱动把每条 CMD128 排成 low word、high word。一次 FIXED burst 包含 2～16 个
偶数 beat，可提交 1～8 条完整指令。NPU 先检查 burst 长度、beat 次序和写响应，
再把完整指令交给 Command Front End。

> [!warning]
> low word 与 high word 不得被另一条指令插入。外部 CPU 不直接连接
> Task Scheduler，也不能绕过 Command Front End 写任务表。

## 4. CMD128 V2

### 4.1 公共头部

| 位段 | 字段 | 说明 |
| ---: | --- | --- |
| `[127]` | `inline_v2` | 固定为 1，表示 80-bit 内联参数格式 |
| `[126:122]` | `compact_opcode` | 5-bit 紧凑操作码 |
| `[121:112]` | `command_id` | 10-bit 在途任务编号，范围 0～1023 |
| `[111:104]` | `wait_event0` | 第一个前置 Event ID，`0xFF` 表示不用 |
| `[103:96]` | `wait_event1` | 第二个前置 Event ID，`0xFF` 表示不用 |
| `[95:88]` | `signal_event` | 完成后更新的 Event ID，`0xFF` 表示不用 |
| `[87]` | `irq_success` | 任务成功时请求中断 |
| `[86]` | `irq_error` | 任务失败时请求中断 |
| `[85]` | `strict_numeric` | 复杂函数出现非法数值时返回错误 |
| `[84]` | `ordered` | 要求按提交次序检查发射条件 |
| `[83:82]` | `timeout_class` | 选择四档超时配置 |
| `[81:80]` | `dtype` | `0=INT4`、`1=INT8`、`2=INT32`、`3=INT16` |
| `[79:0]` | `payload` | 按操作类型解释的任务参数 |

V2 指令没有 `desc_addr`。CFE 和 TS 保存收到的 16 字节 CMD128，内联解码器从
`payload` 直接得到地址引用、尺寸、数据格式和函数选项。MIF 不再产生任务参数
读取事务。

### 4.2 紧凑操作码

5-bit 编码的 32 个值均有明确用途：

| 紧凑值 | 执行单元 | 完整指令 |
| --- | --- | --- |
| 0～4 | Control | NOP、EVENT_SIGNAL、EVENT_REARM、EVENT_JOIN、GLOBAL_FENCE |
| 5～10 | DMA | COPY_1D、COPY_ND、FILL、TRANSPOSE_2D、PACK、SPLIT |
| 11～14 | Matrix | GEMM、BMM、GEMM_ACCUM、GEMM_ZERO |
| 15～24 | Vector | ADD、SUB、MUL、FMA、MAX、MIN、CMP、SELECT、CLAMP、RELU |
| 25～31 | Complex | ACT、SOFTMAX、NORM、ROPE、STAT、RECIP、ADD_RESCALE |

ROPE 和 RECIP 的编码供后续功能使用。第一版功能寄存器未声明支持时，硬件返回
`ILLEGAL_OPCODE`；其他表项属于第一版实现内容。

### 4.3 地址引用

DMA 使用 28-bit `AREF`：

```text
[27]      space：0=L1BUF，1=全局地址
[26:24]   base_select
[23:0]    byte_offset
```

L1BUF 使用 `base_select=0`，地址就是 24-bit 字节偏移。全局地址按
`base_register[base_select] + byte_offset` 计算。基地址编号为
`0=0`、`1=input`、`2=weight`、`3=work`、`4=output`、`5=kv`。

Matrix 使用 14-bit `LREF14`，实际 L1BUF 字节地址为 `LREF14 × 64`；Vector 和
Complex 使用 16-bit `LREF16`，实际地址为 `LREF16 × 16`。Matrix bias 使用
12-bit `LREF12`，实际地址为 `LREF12 × 64`，因此 bias 参数放在 L1BUF
低 256 KiB 内。引用值 0 在 Matrix bias 字段中表示“不使用 bias”。

### 4.4 DMA payload

| 指令 | `[79:0]` |
| --- | --- |
| COPY_1D / COPY_ND | `src AREF28`、`dst AREF28`、`count[19:0]`、目的 dtype、INT4 起始半字节 |
| FILL | `dst AREF28`、`count[19:0]`、`fill_value[31:0]` |
| TRANSPOSE_2D | `src AREF28`、`dst AREF28`、`rows[7:0]`、`cols[7:0]`、目的 dtype |
| PACK / SPLIT | `src AREF28`、`dst AREF28`、段数、每段字节数、段间隔，各 8 bit |

内联 COPY_ND 表示连续多维数组。带跨步的 COPY_ND 由编译器展开成多条
COPY_1D，或在适用时改用 PACK、SPLIT。这样保留多维复制能力，又不需要外部
参数块。

### 4.5 Matrix payload

GEMM、GEMM_ACCUM 和 GEMM_ZERO：

| 位段 | 字段 |
| ---: | --- |
| `[79:66]`、`[65:52]`、`[51:38]` | A、B、C 的 `LREF14` |
| `[37:26]` | bias 的 `LREF12`，0 表示不用 |
| `[25:20]`、`[19:14]`、`[13:8]` | `M-1`、`N-1`、`K-1` |
| `[7]` | `b_int4` |
| `[6:5]` | C 的 dtype |
| `[4:0]` | 直接给出 0～31 的右移位数 |

当 A 为 INT8 且 `b_int4=1` 时，B 为 INT4；否则 B 与 A 使用相同格式。允许的
乘法组合是 INT4×INT4、INT8×INT8、INT8×INT4 和 INT16×INT16。

BMM 使用 A、B、C 三个 `LREF14`，随后是 6-bit `batch-1`、`M-1`、`N-1`、
`K-1`、1-bit `b_int4`、2-bit C dtype 和 5-bit 右移位数，最低 6 bit 写 0。

> [!example]
> 设 A 的形状是 `[M,K]`，B 的形状是 `[K,N]`，bias 的形状必须是 `[N]`
> 且元素为 INT32。对输出元素 $C_{i,j}$，硬件计算：
>
> $$
> C_{i,j}=\operatorname{cast}\left(
> \operatorname{round}\left(
> \frac{\sum_{k=0}^{K-1}A_{i,k}B_{k,j}+b_j}{2^s}
> \right)\right).
> $$
>
> 同一个 $b_j$ 会加到输出矩阵第 $j$ 列的每一行，即
> $C_{0,j},C_{1,j},\ldots,C_{M-1,j}$。这里不是把一个 bias 数值加到全部
> 输出元素，而是每个输出列使用自己对应的 bias。

### 4.6 Vector 与 Complex payload

Vector 公共格式为四个 `LREF16`：`src0`、`src1`、`src2`、`dst`，再保存
`rows-1`、`length-1` 和三个 2-bit 广播方式。CMP 把 `src2` 字段的高 3 bit
解释为 EQ、NE、LT、LE、GT、GE 选择，输出为 INT8 0/1 mask；SELECT 把
`src2` 解释为 INT8 mask，0 选择 `src0`，非 0 选择 `src1`。Vector 不读取
Matrix bias 字段。

Complex 公共格式为 `src0 LREF16`、`aux LREF16`、`dst LREF16`、
`rows-1`、`length-1` 和 19-bit 函数参数。函数参数保存激活类型、指数形式的
scale、目的 dtype、Softmax mask 类型、Norm 模式和 epsilon 档位。LayerNorm
的 `aux` 指向 gamma，beta 位于对齐后的 gamma 数据之后；gamma、beta 的形状
均为 `[length]`，供全部 `rows` 行使用。

## 5. Event 是什么

Event 是硬件任务之间的完成状态记录，不是数据缓冲区，也不是中断编号。每个
Event Table 表项保存状态、当前代次、生产者和等待者数量。CMD128 V2 只写
8-bit Event ID；TS 在接收指令时读取该表项的当前代次。

- `signal_event=x`：任务被接收后保留 Event x；任务结束时写入成功或失败。
- `wait_event0/1=x`：任务只有在 Event x 成功后才能发射。
- 前置 Event 失败：等待任务返回 `DEPENDENCY_FAILED`，不启动执行单元。
- `EVENT_JOIN`：把两个前置 Event 的结果合成一个输出 Event。
- `EVENT_REARM`：旧代次已结束且等待者数量为 0 时，使同一 ID 进入下一代次。
- `0xFF`：该 Event 字段不用。

> [!example]
> GEMM 的 `signal_event=7`，GELU 的 `wait_event0=7`。CPU 可以连续提交两条
> 指令。GELU 会留在等待状态；GEMM 写完最后一项输出并报告成功后，TS 才把
> GELU 发给 Complex Engine。CPU 不需要在两条指令之间轮询。

Event ID 可以复用。编译器只有在旧生产者及全部消费者完成后才插入
EVENT_REARM，并在生成的命令批次信息中要求主机先完成前一批任务，再提交含
EVENT_REARM 的批次。

## 6. 模块分工与功能时序

| 模块 | 主要功能 |
| --- | --- |
| AXI Slave Front End | 接收命令 burst、控制寄存器和 L1BUF 窗口访问 |
| CFE | 将两个 64-bit beat 组成 CMD128，检查格式和重复 command_id |
| Task Scheduler | 保存 CMD128、检查 Event、选择可发射任务、记录终态 |
| Task Context | 每项保存 16 字节 CMD128，供内联解码与执行单元读取 |
| DMA Engine | 全局内存与 L1BUF 搬运、填充、转置、PACK、SPLIT |
| Matrix Engine | GEMM/BMM、INT32 部分和、bias 和整数写回 |
| Vector Engine | 整数逐元素运算、比较、mask 选择和广播 |
| Complex Engine | 激活、Softmax、Norm、统计和不同 scale 的加法 |
| L1BUF | 多 Bank 片上张量存储，连接四个执行单元和外部窗口 |
| MIF / TBU | DMA 全局访问、地址转换服务、AXI burst 与响应处理 |
| LSC / CRG / WDT | 状态、中断、错误、时钟复位和超时控制 |

一条 V2 任务按以下次序推进：

1. AXI Slave 接收 low、high 两个 beat。
2. CFE 组成 CMD128，检查 V2 标记、操作码和 command_id。
3. TS 分配任务项和 16 字节 Task Context，当拍不产生参数读取请求。
4. 内联解码器检查 payload、地址范围、尺寸和数据格式。
5. 前置 Event 成功且执行单元可接收时，TS 发射任务。
6. 执行单元从 L1BUF 取数；只有 DMA 需要访问全局内存时才使用 MIF。
7. 最后一项写响应完成后，执行单元提交终态。
8. TS 更新 Event、任务状态和中断；CPU 查询、等待并 ACK 任务。

## 7. 软件与硬件分工

模型编译器接收 Keras、PyTorch、TFLite 或 ONNX 模型，执行图检查、常量整理、
算子拆分、L1BUF 分配、Event 安排和 CMD128 编码。部署结果是可参加 C/C++
构建的模型专用 `.c`、`.h`：

```text
模型专用 C 源码包
├─ 配置结构体
├─ CMD128 指令数组
├─ 权重与常量数组
├─ 输入输出和操作信息
├─ 命令批次与主机等待要求
└─ CPU 辅助操作信息
```

生成结果不含外部 Descriptor 数组，也不把裸二进制作为应用的主要入口。C 驱动
负责寄存器访问、缓存维护、FIXED burst 提交、等待、查询、中断和 ACK。模型中
不适合由现有指令完成的步骤由生成的操作信息交给 CPU 运行；例如 Conv2D 的
数据整理可能由软件和 DMA 共同完成，乘加部分交给 Matrix Engine。

## 8. 面向模型的算子组合

| 模型 | 主要硬件操作 |
| --- | --- |
| Transformer | Q/K/V GEMM、BMM、Softmax、残差加法、LayerNorm、GELU |
| SimpleRNN | 输入 GEMM、循环 GEMM、bias 加法、Tanh |
| GRU | 六组 GEMM、Sigmoid、Tanh、逐元素乘法和状态组合 |
| LSTM | 八组 GEMM、四个门函数、逐元素乘法和状态组合 |
| CNN | im2col、DMA 搬运、GEMM、bias、激活和输出整理 |

## 9. 第一版与后续功能

“第一版”表示单核首次实现和回归必须覆盖的内容；“后续功能”表示已经保留编码，
但只有功能寄存器声明支持后才能使用。第一版包括 Control、DMA、Matrix、
Vector，以及 ACT、SOFTMAX、NORM、STAT、ADD_RESCALE。ROPE、RECIP 和更复杂
的索引搬运属于后续功能。

第一版完成条件包括：

- CMD128 V2 的 32 个紧凑操作码可正确解码，未启用功能返回明确错误；
- V2 执行期间没有外部任务参数读取；
- INT4、INT8、INT16、INT32 组合测试通过；
- RNN、GRU、LSTM、CNN、Transformer 端到端示例分别通过；
- CModel、RTL、Verilator 和 AXI 验证环境的结果一致；
- 编译和静态检查没有警告。
