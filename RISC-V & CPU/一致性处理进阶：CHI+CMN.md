---
title: 一致性处理进阶：CHI+CMN
type: tutorial
tags:
  - CHI
  - CMN
  - Cache一致性
  - SoC互连
updated: 2026-09-02
related:
  - "[[多核CPU设计和一致性处理]]"
---

# 一致性处理进阶：CHI+CMN

本文面向已经理解 Cache 一致性、AXI4 和基本读写事务的读者，说明 AMBA CHI（Coherent Hub Interface，一致性集线器接口）如何组织一致性请求，以及 Arm CoreLink CMN（Coherent Mesh Network，一致性网格互连）如何在 SoC 中承载这些请求。读完后，读者应能识别 CHI 节点、读懂常用通道与标识字段、跟踪 `ReadShared` 和独占访问的主要过程，并理解 CMN 中地址、目录、系统级 Cache 和内存控制器各自的位置。

本文以本 Vault 中的 [[IHI0050H_amba_chi_architecture_spec.pdf|AMBA CHI Architecture Specification IHI0050H]] 为协议依据。CHI 的精确 Opcode、字段合法组合、可选特性和产品端口宽度仍以对应版本规范和 CMN 技术参考手册为准；本文提供理解和排查常用事务所需的完整起点。

## 1. 先建立正确的总体认识

CHI 是一致性协议标准，不是一组固定的地址线、数据线和握手线。它规定请求节点、Home Node、从属节点之间传送哪些分组、每类分组在什么条件下可以发送、Cache 状态如何变化，以及多个未完成事务如何被区分和完成。互连可以采用网格、环形、交叉开关或其他结构。

CMN 是 Arm 的一致性网格互连产品族。CMN 采用 CHI 组织一致性通信，并实现网格交换、目录、Home Node、系统级 Cache、地址选择、性能监测和调试等硬件。因而，CHI 回答“事务必须如何完成”，CMN 回答“在某一 SoC 中由哪些硬件模块完成、数据经过哪些网格交换节点”。

| 对象 | 关注内容 | 不能直接推断的内容 |
| --- | --- | --- |
| CHI | 节点角色、请求类型、通道、字段、Cache 状态、事务完成条件 | 网格尺寸、端口数量、寄存器地址、Cache 容量 |
| CMN | 采用 CHI 的网格组织、XP、HN-F、SLC、地址选择和具体实现资源 | 所有 CHI 可选特性一定存在，或所有 CMN 产品寄存器完全相同 |

> [!important] 先区分协议与产品
> 看到 `REQ`、`SNP`、`CompData` 或 `CompAck` 时，应按 CHI 规则分析。看到 XP、HN-F 数量、SLC 容量或配置寄存器时，应按选用的 CMN 产品和配置分析。两类问题不能混为一谈。

## 2. CHI 一致性系统的最小模型

一个一致性访问可先按四个问题理解：谁发起访问、哪个 Home Node 负责该地址、是否需要检查其他 Cache 副本、数据最终来自共享 Cache、其他请求节点还是内存控制器。Home Node 是将这四个问题串起来的中心节点。

本文中的 I/O（Input/Output，输入/输出）包含 DMA（Direct Memory Access，直接内存访问）和其他可访问内存或 MMIO 的设备。CHI 使用不同节点类型区分具有硬件一致性 Cache 的访问方与 I/O 一致性访问方。

### 2.1 请求节点、Home Node 与从属节点

| 节点 | 正式名称 | 主要职责 | Cache 与监听能力 |
| --- | --- | --- | --- |
| `RN-F` | Fully Coherent Request Node | 发起普通内存读写、原子访问和 Cache 维护请求 | 具有硬件一致性 Cache，可接收全部监听请求 |
| `RN-D` | I/O Coherent Request Node with DVM support | 发起 I/O 一致性访问，并接收 DVM（Distributed Virtual Memory，分布式虚拟内存） | 不具有硬件一致性 Cache，不接收普通监听请求 |
| `RN-I` | I/O Coherent Request Node | 发起 I/O 一致性访问 | 不具有硬件一致性 Cache，不接收 DVM 和普通监听请求 |
| `HN-F` | Fully Coherent Home Node | 接收可监听访问，查询目录，发起必要监听，汇总结果并返回单一完成响应 | 包含 PoC（Point of Coherence，一致性点）；可选目录、监听过滤器和 SLC（System Level Cache，系统级 Cache） |
| `HN-I` | Non-coherent Home Node | 处理 I/O 子系统的非监听访问 | 不包含 PoC，不处理可监听请求 |
| `SN-F` | Subordinate Node | 完成 HN-F 转发的普通内存非监听读、写和原子访问 | 常连接 DRAM 控制器或普通内存 |
| `SN-I` | Subordinate Node | 完成外设或普通内存的非监听访问 | 常连接 MMIO 外设，也可连接普通内存 |
| `MN` | Miscellaneous Node | 处理 DVM（Distributed Virtual Memory，分布式虚拟内存）事务 | 不承担普通数据读写完成 |

`RN-F` 通常位于 CPU 簇或具有一致性 Cache 的加速器侧。`RN-I` 和 `RN-D` 适合 DMA 或 I/O 一致性设备：它们能够读取 CPU 写入的数据，也能触发对 CPU Cache 副本的必要处理，但自身不保存硬件一致性 Cache 副本。

`HN-F` 不等同于 DRAM 控制器。它先处理该地址的一致性事务，再在需要时向 `SN-F` 发出内存请求。把 HN-F 当成“内存控制器入口”会遗漏目录查询和监听过程，也无法解释为什么一次读会先访问另一个 RN-F。

CMN 中的 XP（Crosspoint，交叉点）在网格内转送分组，HN-F、HN-I 等协议节点连接在 XP 附近。图 1 给出这些节点在一个典型 CMN 中的位置。

![[一致性处理进阶：CHI+CMN.assets/图01-CHI节点与CMN位置.png|1200]]

*图 1　CHI 节点与 CMN 中的典型位置。实际 CMN 配置的 XP、HN-F、SN-F 和端口数量可以不同。*

### 2.2 PoC、PoS 与目录

| 名称 | 含义 | 在初学阶段应记住的结论 |
| --- | --- | --- |
| PoC（Point of Coherence，一致性点） | 所有能够访问同一内存位置的访问方在此处具有一致的数据观察结果 | 典型 CHI 系统把 HN-F 作为 PoC |
| PoS（Point of Serialization，串行化点） | 决定不同访问方请求先后关系的位置 | HN-F 通常也是普通内存请求的 PoS |
| 目录或监听过滤器 | 记录某个 Cache 行可能出现在哪些 RN-F 中 | HN-F 据此只向可能持有副本的 RN-F 发送监听 |
| SLC（System Level Cache，系统级 Cache） | 位于 CPU 私有 Cache 与 DRAM 之间的共享 Cache | 可降低 DRAM 访问次数，但不是 CHI 必须具备的结构 |

目录记录的目标是减少不必要的监听，而不是替代一致性规则。即使目录没有命中，HN-F 仍必须以协议允许的方式完成请求。目录容量、目录项组织和溢出处理属于 CMN 的具体实现，不由 CHI 固定。

### 2.3 先掌握五个常用 Cache 状态

CHI 定义的状态比入门阶段常见的五个更多，完整状态还包括与部分 Cache 行等情况相关的编码。阅读普通读写事务时，先掌握下表即可。

| 状态 | 名称 | 直观含义 |
| --- | --- | --- |
| `I` | Invalid | 当前 Cache 不保存该行 |
| `UC` | Unique Clean | 仅当前 Cache 保存副本，数据未修改 |
| `UD` | Unique Dirty | 仅当前 Cache 保存副本，数据已修改；需要时由该 Cache 提供更新后的数据 |
| `SC` | Shared Clean | 当前 Cache 保存共享副本，可能还有其他共享副本 |
| `SD` | Shared Dirty | 当前 Cache 保存共享的已修改副本，系统仍需保留能够提供更新数据的路径 |

`Clean` 只说明当前 Cache 不承担把修改数据写回内存的责任，不能单独推出 DRAM 一定保存最新值。判断数据来源时必须结合 HN-F 目录、监听响应和 `Resp` 字段，而不能只看请求名称。

CHI 采用写入后使其他副本失效的处理方式。请求方要修改某个 Cache 行前，HN-F 必须先让其他可能保存该行的 RN-F 交出数据或使副本失效，再允许请求方取得独占权限。因此，`ReadUnique` 和 `MakeReadUnique` 不只是“读得更多”的请求，而是取得独占访问权的协议操作；第 5.2 节将用完整过程说明这一点。

## 3. CHI 的消息、分组与通道

### 3.1 消息、分组、Flit 与 Phit

CHI 用分层单位描述一次传送。消息表示协议动作，例如读请求、数据响应或监听请求。分组表示端点之间可独立发送的单位，携带源节点和目标节点等信息。Flit（Flow Control Unit，流量控制单元）是流量控制的最小单位，Phit（Physical Transfer Unit，物理传送单元）是相邻网络设备之间的一次物理传送。

IHI0050H 的 CHI 定义中，每个分组包含一个 Flit，每个 Flit 包含一个 Phit。读一条 Cache 行时仍可能看到多个数据分组；这些数据分组由 `DataID` 等字段区分。因此，“一个请求对应一个数据分组”通常不成立。

### 3.2 RN 侧的六类通道

下表采用 IHI0050H 对 RN 端口的简称。`TX` 表示由 RN 发出，`RX` 表示由 RN 接收。HN-F 位于互连内部，图中通道名称仍用于说明传送方向。

| 逻辑通道 | RN 端口方向 | 主要内容 | 常见消息 |
| --- | --- | --- | --- |
| `REQ`（Request，请求） | `TXREQ` | 访问请求控制信息 | `ReadShared`、`ReadUnique`、`WriteUnique` |
| `WDAT`（Write Data，写数据） | `TXDAT` | 写数据、原子访问数据或转发数据 | `WriteData`、原子写数据 |
| `SRSP`（Snoop Response，监听响应） | `TXRSP` | 对监听的响应，或对完成消息的确认 | `SnpResp`、`SnpRespData`、`CompAck` |
| `CRSP`（Completion Response，完成响应） | `RXRSP` | 来自完成方的响应 | `Comp`、`DBIDResp`、`RetryAck`、`PCrdGrant` |
| `RDAT`（Read Data，读数据） | `RXDAT` | 读数据或原子访问返回数据 | `CompData`、原子数据响应 |
| `SNP`（Snoop，监听） | `RXSNP` | HN-F 发给 RN-F 的监听请求 | `SnpShared`、`SnpMakeInvalid` |

`SRSP` 与 `CRSP` 很容易混淆。`SRSP` 是 RN 向 HN-F 返回的监听响应或 `CompAck`；`CRSP` 是 HN-F 或其他完成方返回给 RN 的完成、重试或写数据关联响应。验证时应同时检查通道方向和消息类型，不能只按“RSP”三个字母判断。

### 3.3 从端口信号认识一个 Flit 的发送

CHI 的端口按通道分别提供 Flit 有效标志、Flit 内容和反向的信用返回信号。以下以 RN-F 发出 `REQ` 为例：`TXREQFLITV` 为高表示 `TXREQFLIT` 中包含待发送的请求 Flit；HN-F 一侧接收该 Flit 后，在有可用接收空间时，通过反向的 `RXREQLCRDV` 向 RN-F 归还一个 `REQ` 通道的 `Link layer` credit。接收端在一个时钟周期内把相应 `LCRDV` 位置为高，即归还一个 credit。

| RN-F 观察的方向 | Flit 有效标志与内容 | 反向信用返回 | 含义 |
| --- | --- | --- | --- |
| 发出 `REQ` | `TXREQFLITV`、`TXREQFLIT` | `RXREQLCRDV` | RN-F 向 HN-F 发送访问请求；HN-F 向 RN-F 返回接收空间 credit |
| 发出 `WDAT` | `TXDATFLITV`、`TXDATFLIT` | `RXDATLCRDV` | RN-F 发送写数据或原子访问数据；完成方返回接收空间 credit |
| 发出 `SRSP` | `TXRSPFLITV`、`TXRSPFLIT` | `RXRSPLCRDV` | RN-F 返回监听响应或 `CompAck`；HN-F 返回接收空间 credit |
| 接收 `CRSP` | `RXRSPFLITV`、`RXRSPFLIT` | `TXRSPLCRDV` | RN-F 接收完成、重试或数据关联响应，并向发送方返回接收空间 credit |
| 接收 `RDAT` | `RXDATFLITV`、`RXDATFLIT` | `TXDATLCRDV` | RN-F 接收读数据，并向发送方返回接收空间 credit |
| 接收 `SNP` | `RXSNPFLITV`、`RXSNPFLIT` | `TXSNPLCRDV` | RN-F 接收监听请求，并向 HN-F 返回接收空间 credit |

`TX` 和 `RX` 以 RN 端口为参照，因此同一条物理连接两侧的命名相反。`LCRDV` 只保证该通道可再接收一个 Flit；它不保证目录、数据缓冲或监听处理资源已经可用。后者由 `RetryAck` 和 `PCrdGrant` 所涉及的 Protocol Credit 控制。

#### 3.3.1 <code>REQ</code> 通道的完整端口定义

设 <code>R</code> 为 <code>REQFLIT</code> 位宽，<code>Num_RP_REQ</code> 为请求资源平面数量。RP（Resource Plane，资源平面）仅在配置多资源平面时存在，用于使不同类别的 <code>REQ</code> 传送各自获得接收空间。下表均以 RN-F 为观察点。

| 信号 | 方向 | 位宽 | 功能 | 有效条件 | 复位与暂停行为 |
| --- | --- | ---: | --- | --- | --- |
| <code>TXREQFLITPEND</code> | 输出 | 1 | 提前指出下一个周期可能有 <code>REQ</code> Flit 待发送，供时钟门控使用 | 仅为预告；即使为高也不代表当前周期已经传送 Flit | 不构成传送条件；规范不要求其在复位期间保持特定值 |
| <code>TXREQFLITV</code> | 输出 | 1 | 指示 <code>TXREQFLIT</code> 在当前周期有效并发送一个请求 Flit | 发送方在当前周期开始前已持有对应 <code>REQ</code> L-Credit 时才允许置高 | 复位期间必须为 0；<code>RESETn</code> 为高后的第一个时钟上升沿起才允许置高 |
| <code>TXREQFLIT[(R-1):0]</code> | 输出 | <code>R</code> | 承载 <code>REQ</code> 分组，包括 <code>Opcode</code>、地址、ID 和属性字段 | 仅在 <code>TXREQFLITV=1</code> 时读取 | <code>TXREQFLITV=0</code> 时其数值不具有传送含义，复位期间不应读取 |
| <code>TXREQFLITRP</code> | 输出 | <code>clog2(Num_RP_REQ)</code> | 指定当前 <code>REQ</code> Flit 使用的 RP | 仅当 <code>Num_RP_REQ>1</code> 且 <code>TXREQFLITV=1</code> 时存在并有效 | <code>TXREQFLITV=0</code> 时忽略；复位期间不具有传送含义 |
| <code>TXREQSHAREDCRD</code> | 输出 | 1 | 表示当前 <code>REQ</code> Flit 使用共享 L-Credit，而非指定 RP 的专用 L-Credit | 仅当实现启用 <code>Shared_Credits_REQ</code> 且 <code>TXREQFLITV=1</code> 时存在并有效 | 未启用共享 credit 时端口不存在；<code>TXREQFLITV=0</code> 时忽略 |
| <code>RXREQLCRDV[Num_RP_REQ-1:0]</code> | 输入 | <code>Num_RP_REQ</code> | 对端对每个 RP 归还专用 <code>REQ</code> L-Credit；置高的每一位归还一个 credit | 连接处于活动状态时，每个置高位在该周期归还相应 RP 的一个 credit | 复位期间 RN-F 不得依赖输入值；收到复位后的有效脉冲后才增加本地可用 credit 计数 |
| <code>RXREQLCRDSHV</code> | 输入 | 1 | 对端归还一个可供任意 RP 使用的共享 <code>REQ</code> L-Credit | 仅当实现启用 <code>Shared_Credits_REQ</code> 时存在；高一个周期归还一个共享 credit | 未启用共享 credit 时端口不存在；复位后按有效脉冲累计 |

对不使用 RP 的端口，<code>LCRDV</code> 是 1 位信号。使用 RP 时，<code>LCRDV</code> 的每一位对应一个 RP；同一周期可以为多个 RP 分别归还 credit，但每个方向仍只发送一个 Flit。发送端即使在当前周期同时看到 <code>RXREQLCRDV</code>，也不能使用刚收到的 credit 在这个周期发送 <code>TXREQFLIT</code>。

#### 3.3.2 RSP、DAT 与 SNP 端口信号

RSP 和 DAT 通道不使用 RP 扩展。SNP 的 <code>FLITRP</code>、<code>SHAREDCRD</code>、<code>LCRDV</code> 扩展方式与 REQ 相同，参数名分别为 <code>Num_RP_SNP</code> 和 <code>Shared_Credits_SNP</code>。下表按信号逐项说明；所有输出方向的 <code>***FLITV</code> 与 <code>***LCRDV</code> 在复位期间必须为 0，所有 <code>***FLIT</code> 只在相应 <code>***FLITV=1</code> 时读取。

| 信号 | 方向 | 位宽 | 功能 | 有效条件 | 复位与暂停行为 |
| --- | --- | ---: | --- | --- | --- |
| <code>TXRSPFLITPEND</code> | 输出 | 1 | 预告下一个周期可能发送 <code>SRSP</code> Flit | 不表示当前周期已经发送 | 仅用于时钟门控，复位期间无传送含义 |
| <code>TXRSPFLITV</code> | 输出 | 1 | 发送 <code>SnpResp</code>、<code>SnpRespData</code> 或 <code>CompAck</code> | 已持有一个 RSP L-Credit | 复位期间为 0；无 credit 时暂停发送 |
| <code>TXRSPFLIT[(T-1):0]</code> | 输出 | <code>T</code> | 承载 <code>SRSP</code> 的响应字段 | <code>TXRSPFLITV=1</code> | <code>TXRSPFLITV=0</code> 时忽略 |
| <code>RXRSPLCRDV</code> | 输入 | 1 | 对端归还一个发送 <code>SRSP</code> 所需的 RSP L-Credit | 高一个周期归还一个 credit | 复位后按有效脉冲累计 |
| <code>RXRSPFLITPEND</code> | 输入 | 1 | 预告下一个周期可能收到 <code>CRSP</code> Flit | 不表示响应已经到达 | 不作为事务完成条件 |
| <code>RXRSPFLITV</code> | 输入 | 1 | 指示收到 <code>Comp</code>、<code>RetryAck</code>、<code>PCrdGrant</code> 或 <code>DBIDResp</code> | 高时读取 <code>RXRSPFLIT</code> | 复位后才允许接收有效 Flit |
| <code>RXRSPFLIT[(T-1):0]</code> | 输入 | <code>T</code> | 承载 <code>CRSP</code> 的响应字段 | <code>RXRSPFLITV=1</code> | <code>RXRSPFLITV=0</code> 时忽略 |
| <code>TXRSPLCRDV</code> | 输出 | 1 | RN-F 对收到的 <code>CRSP</code> 归还一个 RSP L-Credit | 高一个周期归还一个 credit | 复位期间为 0；本地接收空间不足时暂停归还 |
| <code>TXDATFLITPEND</code> | 输出 | 1 | 预告下一个周期可能发送 <code>WDAT</code> Flit | 不表示当前周期已经发送 | 仅用于时钟门控，复位期间无传送含义 |
| <code>TXDATFLITV</code> | 输出 | 1 | 发送 <code>WriteData</code> 或原子访问写数据 | 已持有一个 DAT L-Credit | 复位期间为 0；无 credit 时暂停发送 |
| <code>TXDATFLIT[(D-1):0]</code> | 输出 | <code>D</code> | 承载 <code>WDAT</code> 的数据、字节使能和关联字段 | <code>TXDATFLITV=1</code> | <code>TXDATFLITV=0</code> 时忽略 |
| <code>RXDATLCRDV</code> | 输入 | 1 | 对端归还一个发送 <code>WDAT</code> 所需的 DAT L-Credit | 高一个周期归还一个 credit | 复位后按有效脉冲累计 |
| <code>RXDATFLITPEND</code> | 输入 | 1 | 预告下一个周期可能收到 <code>RDAT</code> Flit | 不表示读数据已经到达 | 不作为读数据有效条件 |
| <code>RXDATFLITV</code> | 输入 | 1 | 指示收到 <code>CompData</code> 或原子访问返回数据 | 高时读取 <code>RXDATFLIT</code> | 复位后才允许接收有效 Flit |
| <code>RXDATFLIT[(D-1):0]</code> | 输入 | <code>D</code> | 承载 <code>RDAT</code> 的数据、响应和关联字段 | <code>RXDATFLITV=1</code> | <code>RXDATFLITV=0</code> 时忽略 |
| <code>TXDATLCRDV</code> | 输出 | 1 | RN-F 对收到的 <code>RDAT</code> 归还一个 DAT L-Credit | 高一个周期归还一个 credit | 复位期间为 0；本地接收空间不足时暂停归还 |
| <code>RXSNPFLITPEND</code> | 输入 | 1 | 预告下一个周期可能收到监听 Flit | 不表示监听已经到达 | 不作为监听有效条件 |
| <code>RXSNPFLITV</code> | 输入 | 1 | 指示收到 <code>SnpShared</code>、<code>SnpMakeInvalid</code> 等监听请求 | 高时读取 <code>RXSNPFLIT</code> | 复位后才允许接收有效 Flit |
| <code>RXSNPFLIT[(S-1):0]</code> | 输入 | <code>S</code> | 承载监听 Opcode、地址和转发字段 | <code>RXSNPFLITV=1</code> | <code>RXSNPFLITV=0</code> 时忽略 |
| <code>RXSNPFLITRP</code> | 输入 | <code>clog2(Num_RP_SNP)</code> | 指出收到的监听 Flit 所属 RP | 仅当 <code>Num_RP_SNP>1</code> 且 <code>RXSNPFLITV=1</code> 时存在并有效 | <code>RXSNPFLITV=0</code> 时忽略 |
| <code>RXSNPSHAREDCRD</code> | 输入 | 1 | 指出收到的监听 Flit 使用共享 L-Credit | 仅在启用 <code>Shared_Credits_SNP</code> 且 <code>RXSNPFLITV=1</code> 时存在并有效 | 未启用共享 credit 时端口不存在 |
| <code>TXSNPLCRDV[Num_RP_SNP-1:0]</code> | 输出 | <code>Num_RP_SNP</code> | RN-F 对收到的监听按 RP 归还专用 SNP L-Credit | 每个置高位归还一个对应 RP 的 credit | 复位期间为 0；接收空间不足时暂停归还 |
| <code>TXSNPLCRDSHV</code> | 输出 | 1 | RN-F 对收到的监听归还共享 SNP L-Credit | 仅在启用 <code>Shared_Credits_SNP</code> 时存在 | 复位期间为 0；未启用时端口不存在 |

<code>LCRDV</code> 只保证该通道还可接收一个 Flit，不保证 HN-F 已经具备目录、监听或数据处理资源。完成方是否接受一笔完整请求由 <code>RetryAck</code> 和 <code>PCrdGrant</code> 所对应的 Protocol Credit 决定。

#### 3.3.3 连接启动、停止与复位

每个单方向通道组都使用 <code>LINKACTIVEREQ</code> 和 <code>LINKACTIVEACK</code> 完成四相启动或停止过程。RN-F 发出 REQ、SRSP、WDAT 的方向使用 <code>TXLINKACTIVEREQ</code> 与 <code>TXLINKACTIVEACK</code>；RN-F 接收 CRSP、RDAT、SNP 的方向使用 <code>RXLINKACTIVEREQ</code> 与 <code>RXLINKACTIVEACK</code>。请求信号由该方向的发送端驱动，确认信号由该方向的接收端驱动。

| 信号 | 相对 RN-F 的方向 | 位宽 | 功能 | 有效条件 | 复位与暂停行为 |
| --- | --- | ---: | --- | --- | --- |
| <code>TXLINKACTIVEREQ</code> | 输出 | 1 | 请求启动 RN-F 发出 REQ、SRSP、WDAT 的通道组，或请求退出 RUN 状态 | RN-F 需要发送 Flit 时置为 1；请求停止时置为 0 | 复位期间必须为 0；复位释放后的时钟上升沿起才允许置高 |
| <code>TXLINKACTIVEACK</code> | 输入 | 1 | 表示对端已经确认 RN-F 发出方向的通道组可进入 RUN 状态 | 与 <code>TXLINKACTIVEREQ=1</code> 共同为 1 时，该方向处于 RUN 状态 | 复位期间 RN-F 不得依赖输入值；为 0 时不得按 RUN 状态发送 Flit |
| <code>RXLINKACTIVEREQ</code> | 输入 | 1 | 表示对端请求启动或停止发送到 RN-F 的通道组 | 与 <code>RXLINKACTIVEACK</code> 一起决定 RN-F 接收方向的状态 | 复位期间 RN-F 不得依赖输入值 |
| <code>RXLINKACTIVEACK</code> | 输出 | 1 | RN-F 确认接收方向的通道组能够进入 RUN 状态 | 对端请求启动且 RN-F 已准备接收时置为 1；停止完成后置为 0 | 复位期间必须为 0；本地接收资源未准备好时保持为 0 |

| 状态 | <code>LINKACTIVEREQ</code> | <code>LINKACTIVEACK</code> | 发送端与接收端的行为 |
| --- | ---: | ---: | --- |
| STOP | 0 | 0 | 发送端没有可用 L-Credit，不发送 Flit；接收端不接收 Flit，也不归还 credit |
| ACTIVATE | 1 | 0 | 启动过程；发送端不得发送 Flit，接收端不得接收 Flit。即使出现 credit，发送端也不得使用 |
| RUN | 1 | 1 | 允许按 L-Credit 规则发送和接收 Flit |
| DEACTIVATE | 0 | 1 | 停止过程；发送端停止普通协议 Flit，并归还尚未使用的 L-Credit；接收端等待全部 credit 返回后再撤销确认 |

复位退出时，接口从 STOP 状态开始。只有完成启动过程并完成所需 L-Credit 的交换后，才能发送第一个 Flit。<code>TXSACTIVE</code> 和 <code>RXSACTIVE</code> 还用于指示协议层是否存在需要继续处理的事务；它们不替代 <code>LINKACTIVEREQ</code>、<code>LINKACTIVEACK</code> 和 L-Credit 的发送条件。

### 3.4 必须读懂的字段

不同 Opcode 使用的字段组合不同，下表只列出快速分析常用事务时最重要的字段。字段取值范围、保留编码和每种 Opcode 的必选字段应查 IHI0050H 对应表格。

| 所在分组 | 字段 | 作用 | 阅读事务时的检查重点 |
| --- | --- | --- | --- |
| `REQ` | `Opcode` | 指定读、写、原子、Cache 维护或其他请求类型 | 先由它决定可能出现的后续消息 |
| `REQ` | `Addr`、`Size` | 指定访问地址和访问大小 | 由地址选择目标 HN-F；检查访问大小与属性是否匹配 |
| `REQ` | `SrcID`、`TgtID` | 分别标识发出端口和目标端口 | 返回数据和响应不能送错节点 |
| `REQ` | `TxnID` | 在同一 `SrcID` 下标识未完成事务 | 同一源端口的活动事务不能复用同一 `TxnID` |
| `REQ` | `ReturnNID` | 指定某些事务中数据或响应的返回目标 | 直接数据传送时尤其重要 |
| `REQ` | `Order`、`ExpCompAck` | 说明访问次序限制和是否期待完成确认 | 不把 `Comp` 当成全部资源已经释放的唯一依据 |
| `REQ` | `QoS`、`MemAttr` | 指定服务优先级和内存属性 | 与系统地址属性和 CMN 配置保持一致 |
| `SNP` | `SnpOpcode`、`Addr` | 指定监听动作和目标 Cache 行 | 确认请求的是共享、失效、清理还是其他动作 |
| `SNP` | `FwdNID`、`FwdTxnID` | 支持由被监听 RN-F 向指定请求方直接发送数据 | 只在支持直接 Cache 数据传送的流程中使用 |
| `RSP` 或 `DAT` | `Resp` | 报告完成结果与 Cache 状态信息 | 用于决定请求方可获得的 Cache 权限 |
| `RSP` 或 `DAT` | `DBID` | 由完成方分配的数据关联号 | 写数据和完成确认必须带回正确的 `DBID` |
| `DAT` | `DataID`、`BE`、`Data` | 分别标识数据段、有效字节和数据内容 | 多个数据分组必须按 `DataID` 组合成完整访问结果 |
| `DAT` | `HomeNID` | 告知请求方 `CompAck` 的目标 HN-F | 需要 `CompAck` 时不能只使用原始 `TgtID` 猜测目标 |

> [!note] `TxnID` 与 `DBID` 的区别
> `TxnID` 由请求方在发出请求时选择，用于区分该源端口的访问。`DBID` 由完成方在需要数据分离或完成确认的流程中分配，用于把后续 `WriteData` 或 `CompAck` 与该事务关联。两者来源不同，不能互换。

## 4. 为什么 CHI 能同时处理大量请求

### 4.1 两层信用控制

CHI 同时使用 `Link layer` credit 和 Protocol Credit。两者都被称为 credit，但处理的位置和目的不同。

| 类型 | 作用位置 | 解决的问题 | 典型消息或字段 |
| --- | --- | --- | --- |
| `Link layer` credit | 每一跳连接两端 | 接收端缓冲不足时，不允许继续送入 Flit | 相应通道的 `LCRDV` |
| Protocol Credit | 请求方与完成方之间 | 完成方暂时没有协议处理资源时，规定何时允许请求重新发送 | `RetryAck`、`PCrdGrant`、`PCrdReturn` |

`Link layer` credit 是局部流量控制：发送端只在对端确认有空间时发送一个 Flit。它不表示 HN-F 已经具备完成整笔请求的目录、监听或数据缓冲资源。

Protocol Credit 是端到端的处理资源保证。常用的重试过程如下：

1. 请求方先发出不带 Protocol Credit 的请求。
2. 完成方暂时无法接受时返回 `RetryAck`，表示该请求没有被接受。
3. 完成方在资源可用时返回 `PCrdGrant`。
4. 请求方同时收到 `RetryAck` 与 `PCrdGrant` 后，可以携带该 credit 重发原请求；这次请求保证被接受。
5. 请求方不再需要重发时，发送 `PCrdReturn` 归还 credit。

这套过程避免请求方持续盲目重发，也使完成方能够按自身资源情况安排接收时机。验证中应分别统计各通道的 `LCRDV` 与 `PCrdGrant`，它们不是同一种资源。

#### 4.1.1 L-Credit 的时钟周期规则

L-Credit 只用于一个通道在相邻连接两端之间传送 Flit。接收端高一个周期驱动相应 <code>LCRDV</code>，向发送端归还一个 L-Credit；发送端每发送一个 <code>FLITV=1</code> 的 Flit，就消耗一个已经持有的 L-Credit。没有 RP 时，每个通道独立使用 1 位 <code>LCRDV</code>；规范规定接收端至少能够提供 1 个、最多能够提供 15 个 L-Credit。

发送方不得把当前周期刚收到的 <code>LCRDV</code> 用于当前周期的 <code>FLITV</code>。换言之，某周期是否允许发送，由该周期开始前的可用 credit 数量决定。接收端一旦归还 credit，就必须能够接收该 credit 所允许的 Flit；因此，接收端在本地缓冲空间不足时必须暂停归还 <code>LCRDV</code>，而不是先归还再拒收 Flit。

> [!note] <code>LCRDV</code> 与 <code>LCrdReturn</code> 的区别
> 正常运行时，接收端使用 <code>LCRDV</code> 脉冲归还接收空间。<code>LCrdReturn</code> 则是连接停止过程中发送的维护 Flit，用于把尚未使用的 L-Credit 归还给原接收端。<code>LCrdReturn</code> 的 <code>Opcode</code> 为 0，<code>TxnID</code> 必须为 0；它不能当作正常运行时的 <code>LCRDV</code> 脉冲统计。

![[一致性处理进阶：CHI+CMN.assets/图03-REQ通道L-Credit时序.png|1200]]

*图 3　无 RP 的 <code>REQ</code> 通道 L-Credit 时序。图中的 T0 至 T7 是示例周期，不是 CHI 对事务延迟的规定。*

图 3 中，T1 的 <code>RXREQLCRDV</code> 归还一个 credit，因此 RN-F 可在 T2 发送 <code>REQ A</code>。T3、T4 和 T5 连续归还三个 credit；RN-F 在 T5 发送 <code>REQ B</code> 时使用的是 T4 及以前持有的 credit，T5 同时收到的 credit 最早只能由 T6 使用。<code>TXREQFLITPEND</code> 可以在发送前一周期预告可能出现 Flit，但它不是传送和事务完成的依据。

RP 只用于 REQ 和 SNP 通道。多个 RP 让不同 RP 的 Flit 分别使用专用 credit；接收端还可以配置共享 credit 以提高缓冲空间利用率。<code>FLITRP</code> 仅在 <code>FLITV=1</code> 时有效，<code>SHAREDCRD</code> 为高表示当前 Flit 使用共享 credit。即使使用多个 RP，一个方向每个周期仍只传送一个 Flit。

#### 4.1.2 Protocol Credit 的事务时序

Protocol Credit 不是端口上的单拍握手，而是完成方作出的“带此 credit 重发后会接受请求”的事务保证。第一次请求把 <code>AllowRetry</code> 置为 1，且 <code>PCrdType</code> 必须为 <code>0b0000</code>。完成方暂时无法接受请求时，以 <code>RetryAck</code> 返回未接受结果，并给出该请求所需的 <code>PCrdType</code>；资源可用时，再以 <code>PCrdGrant</code> 授予这个类型的 P-Credit。

<code>RetryAck</code> 和 <code>PCrdGrant</code> 不具有固定到达先后。通常先收到 <code>RetryAck</code>，但互连中响应的先后不同也可能让 <code>PCrdGrant</code> 先到达。请求方必须保存先到达的消息，只有同时获得 <code>RetryAck</code> 和相同 <code>PCrdType</code> 的 <code>PCrdGrant</code> 后，才能重发原请求。重发时 <code>AllowRetry</code> 置为 0，<code>PCrdType</code> 改为该 credit 类型；完成方保证接受这次重发。

![[一致性处理进阶：CHI+CMN.assets/图04-请求重试事务时序.png|1200]]

*图 4　请求重试的两种有效事务时序。两侧均在收到 <code>RetryAck</code> 与匹配的 <code>PCrdGrant</code> 后才重发请求。*

请求方若不再需要某个已授予的 P-Credit，必须发出 <code>PCrdReturn</code>。该请求的 <code>TgtID</code> 与授予该 credit 的完成方 <code>SrcID</code> 相同，<code>TxnID</code> 置为 0，<code>PCrdType</code> 与原 <code>PCrdGrant</code> 相同；<code>PCrdReturn</code> 不需要响应，也不使用 <code>DBID</code>。这使完成方能够把不用的处理资源交给其他重试请求。

| 观察到的消息或信号 | 可得出的结论 | 不能据此得出的结论 |
| --- | --- | --- |
| <code>RXREQLCRDV=1</code> | RN-F 在下一周期起多出一个 REQ L-Credit | HN-F 已经接受某笔完整请求 |
| <code>RetryAck</code> | 原请求未被接受，需等待匹配的 P-Credit | 可以立即重发原请求 |
| <code>PCrdGrant</code> | 已获得某类型的 P-Credit | 已经收到对应原请求的 <code>RetryAck</code> |
| <code>RetryAck</code> 与匹配 <code>PCrdGrant</code> | 可以以 <code>AllowRetry=0</code> 重发 | 原请求已经完成 |

### 4.2 分离请求、响应和数据

AXI4 的一个读事务常让读数据和读响应在同一 R 通道出现。CHI 则把请求控制、完成响应和数据放在独立通道中。一次请求可能先收到 `DBIDResp`，后收到数据；也可能先收到 `Comp`，再完成另一个数据阶段。读写代码或验证器不能用“先收到哪个分组”代替协议规定的完成条件。

`CompAck` 的含义也应单独理解：当请求的 `ExpCompAck` 指出需要完成确认时，请求方在收到规定的完成消息后向 `HomeNID` 发送 `CompAck`。HN-F 据此知道请求方已经接收了该阶段的结果，可以释放与这笔事务相关的资源。`CompAck` 不是 `DAT` 通道上一次传送的普通握手信号。

## 5. 两个必须会跟踪的事务

### 5.1 `ReadShared`：读取另一 RN-F 的脏副本

设 RN-F A 要读取地址 `X`，HN-F 的目录表明 RN-F B 保存 `X` 的脏副本。简化流程如下图所示。

![[一致性处理进阶：CHI+CMN.assets/图02-ReadShared事务流程.png|1200]]

*图 2　RN-F A 通过 `ReadShared` 读取 RN-F B 的脏副本的因果时序。箭头仅保留理解主过程所需的消息，不表示固定时钟周期。*

#### 5.1.1 <code>ReadShared</code> 的时序定义

图 2 的纵向位置表示必须满足的因果先后，而不是“每一步只占一个时钟周期”。从 RN-F A 送出请求到 HN-F 发出监听之间，HN-F 需要完成地址选择和目录查询；RN-F B 收到监听后，还需要读取本地 Cache 状态。网格跳数、目录命中、SLC 命中、RN-F B 的 Cache 状态以及同一地址的其他活动事务都会改变实际等待周期。因此，验证时应检查每一步的前置条件是否成立，而不应把图中的上下距离当作周期数。

| 阶段 | RN-F 端口上的有效信号 | 必须先满足的条件 | 本阶段完成后可进行的动作 |
| --- | --- | --- | --- |
| 发送共享读 | <code>TXREQFLITV=1</code>，<code>TXREQFLIT</code> 为 <code>ReadShared</code> | RN-F A 已有 REQ L-Credit，且请求的 <code>SrcID</code> 与 <code>TxnID</code> 未被活动事务使用 | HN-F 接收请求并查询目录 |
| 发送监听 | RN-F B 看到 <code>RXSNPFLITV=1</code>，<code>RXSNPFLIT</code> 为 <code>SnpShared</code> | HN-F 已确定 RN-F B 需要被监听，并已持有 SNP 通道所需的 L-Credit | RN-F B 查找本地 Cache 行并准备响应 |
| 返回脏数据 | <code>TXRSPFLITV=1</code>，<code>TXRSPFLIT</code> 为 <code>SnpRespData</code> | RN-F B 已完成对该监听的 Cache 查找 | HN-F 获得数据和监听结果，判断请求方可取得的权限 |
| 返回完成数据 | RN-F A 看到 <code>RXDATFLITV=1</code>，<code>RXDATFLIT</code> 为 <code>CompData</code> | HN-F 已收齐本流程所需的监听结果，并已确定数据来源和 <code>Resp</code> | RN-F A 接收数据和共享权限 |
| 完成确认 | <code>TXRSPFLITV=1</code>，<code>TXRSPFLIT</code> 为 <code>CompAck</code> | 原请求 <code>ExpCompAck=1</code>，且 RN-F A 至少已收到一个 <code>CompData</code> | HN-F 可以结束该完成确认阶段并释放相应事务资源 |

在图 2 所示的读数据返回方式中，<code>CompData</code> 中的 <code>HomeNID</code> 指出完成确认应送往的 HN-F；当需要 <code>CompAck</code> 时，请求方以该 <code>HomeNID</code> 作为 <code>CompAck</code> 的 <code>TgtID</code>，并用读数据的 <code>DBID</code> 填写 <code>TxnID</code>。这也是波形中不应仅根据原请求 <code>TgtID</code> 推断 <code>CompAck</code> 目的地的原因。

1. RN-F A 通过 `REQ` 发送 `ReadShared`，其中含有 `Addr`、`SrcID`、`TxnID` 和请求属性。
2. HN-F 根据地址确定自己负责该行，查询目录后发现 RN-F B 可能保存更新数据，因而通过 `SNP` 发送 `SnpShared`。
3. RN-F B 检查本地 Cache 行并返回 `SnpRespData`。该响应同时说明监听结果并携带数据。
4. HN-F 汇总监听结果后，通过 `DAT` 向 RN-F A 发送 `CompData`。请求方据 `Resp` 获得允许的共享访问状态。
5. 当该流程要求完成确认时，RN-F A 通过 `SRSP` 向 `HomeNID` 发送 `CompAck`。

这个例子说明了三点。第一，读数据不一定来自 DRAM。第二，HN-F 必须先完成必要的监听处理，才能给请求方返回正确的数据和权限。第三，`CompData` 与 `CompAck` 分别表示“请求方收到完成数据”和“请求方确认该阶段结束”，二者不能合并理解。

> [!note] 图 2 的适用范围
> 实际 `ReadShared` 还可能包含 `ReadReceipt`、直接 Cache 数据传送、数据与响应分离等情况。图中选择“数据先回 HN-F、再由 HN-F 回给请求方”的常见学习路径。查看波形时，应先确认 `Opcode`、`ExpCompAck`、`DCT` 和相关响应字段，再判断哪些可选消息应出现。

### 5.2 `ReadUnique` 与 `MakeReadUnique`：取得独占访问权

CPU 想修改一个当前未独占的 Cache 行时，常需要取得独占权限。`ReadUnique` 既请求数据又请求独占权限；`MakeReadUnique` 适合请求方已有数据但仍需把共享权限升级为独占权限的情况。

1. RN-F 发出 `ReadUnique` 或 `MakeReadUnique`。
2. HN-F 查询目录，向可能保存该行的其他 RN-F 发出使其交出或失效副本的监听，例如 `SnpMakeInvalid`。
3. HN-F 收到全部必要监听响应后，确认不存在会与新独占权限冲突的有效副本。
4. `ReadUnique` 通过 `CompData` 返回数据和独占权限；`MakeReadUnique` 已有本地数据时可以只收到 `Comp`。
5. 若原请求要求完成确认，请求方在规定时机发送 `CompAck`。

独占权限的关键不在“请求名称中含有 Unique”，而在 HN-F 已经完成对其他副本的必要处理。若验证波形中 `CompData` 已经使请求方得到独占权限，但其他 RN-F 仍能以有效副本命中同一行，则目录、监听发送或监听响应汇总存在错误。

### 5.3 `WriteUnique`：直接写入而不保留 Cache 副本

`WriteUnique` 适合 I/O 一致性设备或不需要在请求方 Cache 中保留该行的写入。它与 CPU 取得独占 Cache 行后再局部写入的过程不同。

1. 请求方以 `REQ` 发送 `WriteUnique` 变体。
2. HN-F 处理可能存在的 Cache 副本，并在需要写数据分离时以 `DBIDResp` 返回 `DBID`。
3. 请求方通过 `WDAT` 发送 `WriteData`，并在其中带上匹配的 `DBID`。
4. HN-F 在数据和一致性处理达到该 Opcode 的完成条件后返回 `Comp` 或协议允许的组合响应。
5. 需要 `CompAck` 的流程由请求方按收到的完成消息和 `ExpCompAck` 要求发送确认。

`WriteUniquePtl`、`WriteUniqueFull`、`WriteBack` 和 `WriteClean` 的字段及 Cache 状态要求不同。初学者排查写事务时，先核对四项：写入长度、`DBID` 是否匹配、其他 RN-F 的副本是否已按要求处理、`Comp` 与 `CompAck` 的先后是否满足该 Opcode 的规则。

## 6. CMN 如何落实 CHI

### 6.1 XP、HN-F 与 SN-F 的分工

XP（Crosspoint，交叉点）是 CMN 网格中的交换节点。它按分组的目标信息在网格中转送分组；XP 不决定某个 Cache 行是否应监听。HN-F 才负责该地址的目录查询、PoC 处理、监听发起和响应汇总。SN-F 完成 HN-F 送来的普通内存访问，通常接在 DRAM 控制器一侧。

一次常见的 RN-F 读访问在 CMN 中经过以下位置：

1. RN-F 根据地址选择目标 HN-F，并在 `REQ` 中带上对应 `TgtID`。
2. 本地 XP 接收请求，并沿网格把分组送到目标 HN-F。
3. HN-F 查询目录和可选 SLC。若数据不在本地可用位置，HN-F 发起监听或向 SN-F 请求数据。
4. HN-F 汇总数据和监听响应，向原 RN-F 返回 `CRSP`、`RDAT` 或两者。
5. 返回分组通过网格回到原 RN-F；若需要完成确认，RN-F 再以 `SRSP` 发送 `CompAck`。

读写数据经过多个 XP 不改变 CHI 事务规则。软件只需访问内存；硬件设计与验证必须保证每个分组的目标、信用、ID 和返回路径均正确。

### 6.2 系统地址表：同一地址必须找到同一 HN-F

CMN 的 SAM（System Address Map，系统地址表）规定不同物理地址范围应由哪个 HN-F 和哪个 SN-F 处理。请求侧的地址选择把访问送到相应 HN-F；HN-F 再按自身地址表把需要访问内存或外设的请求送到相应 SN-F。具体寄存器名称和位域随 CMN 产品变化。

| 配置问题 | 必须满足的条件 | 配置错误时的现象 |
| --- | --- | --- |
| 某个 Cache 行由哪个 HN-F 处理 | 同一物理 Cache 行在系统运行期间只能由一个 HN-F 作为 PoC 处理 | 两个 HN-F 各自记录副本，可能出现不一致数据 |
| 多个 HN-F 如何分担连续内存区域 | 地址分布粒度与系统 Cache 行大小、DRAM 控制器组织和性能目标一致 | 地址集中到少量 HN-F，访问延迟和请求数量分布不均 |
| HN-F 向哪个 SN-F 发请求 | 普通内存、MMIO 和保留地址范围具有明确目标 | 请求被送到错误存储器或外设，出现访问故障或数据错误 |
| I/O 一致性设备访问什么范围 | `MemAttr`、地址属性和 HN-I/HN-F 选择一致 | DMA 读取旧数据，或不必要地触发一致性处理 |

> [!warning] 地址表不是软件虚拟地址转换
> CMN 的 SAM 处理的是 SoC 内的物理地址选择关系。它不替代 CPU 的页表、IOMMU 地址转换或 RISC-V 的地址转换机制。排查一致性问题时，先确认进入 CMN 的物理地址，再检查该物理地址的 HN-F 与 SN-F 选择。

### 6.3 目录、监听过滤器与 SLC 的关系

目录或监听过滤器回答“可能有哪些 RN-F 保存这个行”；SLC 回答“共享 Cache 中是否已有可用数据”。二者可放在同一个 HN-F 附近，但职责不同。

| 结构 | 记录或保存的内容 | 对监听数量的作用 |
| --- | --- | --- |
| 目录或监听过滤器 | Cache 行可能出现的 RN-F 信息 | 只向可能命中的 RN-F 发送监听，减少无关请求 |
| SLC | Cache 行的数据和状态 | 命中时可能不必访问 DRAM，但仍需遵守一致性处理 |
| SN-F 与 DRAM | 系统内存数据 | 当 HN-F 无法从 SLC 或 RN-F 获得所需数据时提供数据 |

不能把“目录命中”理解为“数据一定在该 RN-F”，也不能把“SLC 命中”理解为“可以跳过所有一致性处理”。HN-F 必须结合目录状态、请求类型和已有事务决定是否监听、从哪里取数以及如何返回权限。

### 6.4 CMN 配置时先确认的项目

1. 确认每个 CPU 簇、加速器和 DMA 的 CHI 节点类型，尤其是 `RN-F`、`RN-D` 和 `RN-I` 的选择。
2. 确认 HN-F、HN-I、SN-F 和 SN-I 的地址范围，以及普通内存与 MMIO 的属性。
3. 确认同一物理 Cache 行只会进入一个 HN-F 的一致性处理范围。
4. 确认目录、监听过滤器和 SLC 的容量与可选特性，并定义容量不足时的协议处理。
5. 确认每个端口的 `TxnID` 数量、`DBID` 资源、`Link layer` credit 深度与 Protocol Credit 资源能够覆盖预期并发访问。
6. 确认错误响应、低功耗状态、DVM、原子访问和调试接口是否在选用的产品配置中启用。

Arm 的 CMN 培训材料将 CHI 事务、系统地址表、初始化、错误处理、调试、性能监测和服务质量列为 CMN 集成的重要主题。[Arm CoreLink CMN and AMBA](https://developer.arm.com/support/training/-/media/B51E4B89029847979F879CFFEB07EEC9.ashx?hash=7970DD424A1CB2656D4CA2230DF07D3ACD71A3C8&revision=785f19f0-ace4-4528-8cec-1de25331c683)

## 7. 验证与波形排查

### 7.1 每笔事务的最小检查记录

验证器应至少为每笔 CHI 事务保存下列具体字段，而不是只记录“收到一个读请求”。

| 类别 | 建议记录的字段 | 用途 |
| --- | --- | --- |
| 请求身份 | `SrcID`、`TxnID`、`TgtID`、`Opcode` | 将返回的响应和数据关联到正确请求 |
| 地址属性 | `Addr`、`Size`、`MemAttr`、`Order` | 检查地址选择、一致性属性和访问次序 |
| 数据阶段 | `DBID`、`DataID`、`BE`、数据内容 | 组合多段数据，检查写数据是否属于正确事务 |
| 监听阶段 | `SnpOpcode`、被监听 RN-F、`SnpResp` 或 `SnpRespData` | 检查 HN-F 是否向正确节点发出监听并收齐结果 |
| 完成阶段 | `Resp`、`HomeNID`、`ExpCompAck`、`CompAck` | 检查权限、完成条件和资源释放条件 |
| 流量控制 | 各通道的 `LCRDV`、`RetryAck`、`PCrdGrant`、`PCrdReturn` | 检查没有在缺少相应 L-Credit 或 P-Credit 时发送分组 |

### 7.2 推荐的最小测试集合

| 测试 | 初始条件 | 预期关键消息 | 通过条件 |
| --- | --- | --- | --- |
| 无副本共享读 | 所有 RN-F 中该行均为 `I` | `ReadShared`，随后从 SLC 或 SN-F 返回 `CompData` | 请求方获得共享读数据，不出现无理由监听 |
| 脏副本共享读 | 一个 RN-F 持有 `UD` 或 `SD` 副本 | `ReadShared`、`SnpShared`、`SnpRespData`、`CompData` | 请求方数据等于修改后的值，目录记录与实际副本一致 |
| 独占读 | 两个 RN-F 均保存共享副本 | `ReadUnique` 与必要的失效类监听 | 请求方获得独占权限，其他副本按要求失效 |
| 分离写数据 | 请求要求通过 `WDAT` 传数据 | `DBIDResp`、携带匹配 `DBID` 的 `WriteData`、`Comp` | 数据不会被错误事务接收，完成条件满足后才释放记录 |
| Protocol Credit 重试 | 完成方暂时没有可用资源 | `RetryAck`、`PCrdGrant`、带 credit 的重发或 `PCrdReturn` | 重发前同时收到两项消息，带 credit 的重发被接受 |
| I/O 一致性 DMA | CPU Cache 中有已修改数据，DMA 通过 `RN-I` 或 `RN-D` 读取 | HN-F 发起必要监听并返回更新数据 | DMA 不读取旧值，RN-I/RN-D 不被当作可监听 Cache 节点 |

覆盖率统计应至少包含请求 Opcode、Cache 初始状态、数据来源、监听类型、是否需要 `CompAck`、是否重试、`DBID` 数据阶段、错误响应和暂停组合。只统计 REQ 数量无法说明目录、监听和完成确认是否被充分覆盖。

### 7.3 常见问题

| 现象 | 可能原因 | 检查方法 | 处理方法 |
| --- | --- | --- | --- |
| 请求方读到旧值 | HN-F 未监听保存脏副本的 RN-F，或未采用监听返回的数据 | 比较目录记录、`SnpShared` 目标与 `CompData` 内容 | 修正目录更新、监听选择或数据来源选择 |
| `CompAck` 到达错误 HN-F | 使用原始请求目标猜测确认目标 | 检查 `CompData` 或相关响应中的 `HomeNID` | 按 `HomeNID` 生成 `CompAck` 的 `TgtID` |
| 写数据没有被接受 | `DBID` 错误，或在未收到 `DBIDResp` 时发送分离写数据 | 检查 `DBIDResp`、`WriteData` 和事务记录 | 保存完成方返回的 `DBID`，只在对应事务数据阶段使用 |
| 请求反复重试 | 将 `RetryAck` 当作可立即重发，或遗漏 `PCrdGrant` | 检查是否同时接收到 `RetryAck` 与 `PCrdGrant` | 在两项消息均到达后重发，或发送 `PCrdReturn` |
| 两个 HN-F 都处理同一 Cache 行 | 系统地址表的范围或分布粒度错误 | 记录同一物理地址到达的 `TgtID` 与 HN-F | 修正地址范围和 HN-F 选择关系 |
| 监听数量异常大 | 目录未命中处理错误，或目录状态没有随 Cache 维护更新 | 比较目录记录与实际 Cache 状态 | 修正目录更新和目录容量不足时的处理 |

## 8. 快速检查表

- [ ] 先判断访问方是 `RN-F`、`RN-D` 还是 `RN-I`。
- [ ] 由物理地址确认目标 HN-F，而不是把 DRAM 控制器直接当作一致性处理点。
- [ ] 用 `SrcID` 加 `TxnID` 跟踪原始请求，用 `DBID` 跟踪数据阶段。
- [ ] 分别检查 `REQ`、`WDAT`、`SRSP`、`CRSP`、`RDAT` 和 `SNP` 的方向与消息类型。
- [ ] 对共享读确认数据来自 SLC、被监听 RN-F 或 SN-F 中的正确位置。
- [ ] 对独占请求确认所有必要副本已经处理后才授予独占权限。
- [ ] 对 `RetryAck` 等待匹配的 `PCrdGrant`，不要把通道 `LCRDV` 当作 Protocol Credit。
- [ ] 对需要完成确认的事务，使用 `HomeNID` 把 `CompAck` 送到正确 HN-F。
- [ ] 把 CHI 协议规则与 CMN 产品配置分开检查。

## 9. 参考资料

- [[IHI0050H_amba_chi_architecture_spec.pdf|AMBA CHI Architecture Specification IHI0050H]]：本文的主要协议依据，覆盖节点类型、分组字段、事务流程、Cache 状态和信用控制。
- [Arm CoreLink CMN and AMBA](https://developer.arm.com/support/training/-/media/B51E4B89029847979F879CFFEB07EEC9.ashx?hash=7970DD424A1CB2656D4CA2230DF07D3ACD71A3C8&revision=785f19f0-ace4-4528-8cec-1de25331c683)：Arm 的 CMN 培训主题，列出 CHI 事务、CMN 地址表、初始化、调试和性能监测内容。
- [Arm 对 CHI 增强功能的介绍](https://developer.arm.com/community/arm-community-blogs/b/soc-design-and-simulation-blog/posts/introducing-new-amba-5-chi-protocol-enhancements?pifragment-27083=2%3Fpifragment-27083%3D2)：说明 HN 作为一致性点，以及目录、监听过滤器和系统级 Cache 的关系。
- [[多核CPU设计和一致性处理#5.11 CHI|多核CPU设计和一致性处理中的 CHI 概览]]：适合在学习本章前回顾 AXI4、ACE、Cache 一致性和 RVWMO 的基础概念。
