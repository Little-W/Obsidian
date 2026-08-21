# Alkaid多核模式设计

## 1. 设计概述

Alkaid SoC（片上系统）支持单hart与双hart两种配置。双hart模式采用私有一级存储结构、共享存储器和集中式一致性控制：每个CPU保留独立的流水线、ICache、可选DCache与LSU L0 Cache，系统层负责AXI4-Full（完整AXI4协议）仲裁、跨核失效、原子操作和共享外设访问。当前设计不包含共享L1或共享L2；未来增加共享L2时，可以保持CPU接口不变。

完整方案覆盖RTL（寄存器传输级）、BSP（板级支持包）、RT-Thread SMP（对称多处理）端口、AMP（非对称多处理）启动服务和验证环境。核心保持`轻度乱序单发射、有限乱序完成`，Zba（地址生成）、Zbb（基础位操作）、Zbs（单比特操作）与Zbc（无进位乘法）仅作为ISA（指令集架构）扩展使用，其中Zbc不作为核内微结构创新点。硬件也支持C（压缩指令）扩展，但公平性能程序保持32位定长指令。

> [!NOTE]
> 单核与双核性能测试使用完全相同的编译参数、ISA、测试源码和迭代配置。硬件可以支持C压缩指令扩展，但公平性能程序没有生成压缩指令，以排除ISA差异对比较结果的影响。

## 2. 系统结构

### 2.1 层次职责

`core_top`是单个hart的完整边界，内部包含CPU流水线、私有ICache、可选私有DCache、LSU L0 Cache接口和CLINT（Core-Local Interruptor，核心本地中断控制器）。`alkaid_soc_top`保留双hart共享功能，包括取指读仲裁、数据一致性控制、AXI4-Lite Cache与乒乓缓存、共享IMEM、共享数据存储和公共外设。

这一边界让单核配置与双核配置复用同一个`core_top`。hart编号、hart数量、Cache容量、流水线级数、RV32（32位RISC-V）或RV64（64位RISC-V）以及各ISA扩展均由参数确定。非法hart数量或不支持的组合应在硬件展开时报告错误。

```text
hart0 core_top ── 私有ICache ──┐
                               ├─ 取指读仲裁 ── 共享IMEM
hart1 core_top ── 私有ICache ──┘

hart0 core_top ── 私有DCache/LSU L0 Cache ──┐
                                             ├─ 数据一致性控制 ── 共享存储与外设
hart1 core_top ── 私有DCache/LSU L0 Cache ──┘
```

### 2.2 私有与共享资源

每个hart具有独立PC（程序计数器）、GPR（通用寄存器）、CSR（控制与状态寄存器）、流水线暂停状态、异常状态、ICache、LSU L0 Cache和栈。两个hart共享物理地址空间、IMEM、数据存储器、外设寄存器、全局时间计数与一致性控制。

双hart默认配置为每核私有2048项、2路ICache，取指侧允许4笔未完成读事务。私有DCache提供1024项、2路配置能力，但当前性能配置默认关闭；数据低延迟访问由每核独立的LSU L0 Cache承担，其配置为1024项、1路。两个CPU绝不共用同一个L1 Cache。

### 2.3 CLINT归属

每个`core_top`都包含CLINT控制功能。hart0内部的CLINT负责共享MMIO寄存器组，并输出各hart的软件中断和定时器中断；hart1接收属于自己的中断位，其CLINT MMIO请求保持无效。这样既把异常控制放在核边界内，又避免出现两套可写的共享时间寄存器。

## 3. 流水线组织

### 3.1 核心特征

CPU保持`轻度乱序单发射、有限乱序完成`。IFU（取指单元）一次提供一条指令，IDU（译码单元）产生操作信息，IRS（发射保留站）保存等待执行的操作，EXU（执行单元）完成计算，WBU（写回单元）提交结果。HDU（数据冒险检查单元）负责检查数据冒险，并依据流水线级数选择紧凑比较或近期commit id跟踪。

BPU（分支预测单元）提供预测方向与目标，BJP（分支跳转处理单元）给出已解析的控制流请求。CLINT只检查BJP的请求状态以确定可靠的下一条PC，不再增加一套臃肿的指令类型解码。

### 3.2 P3、P4与P5

下表使用IF（取指）、ID（译码）、Dispatch（发射准备）、EX（执行）和WB（写回）表示各阶段职责。

| 配置 | 阶段划分 | 主要寄存器边界 | IRS容量 | 数据冒险处理 | 适用重点 |
| --- | --- | --- | ---: | --- | --- |
| P3 | IF；ID、Dispatch与EX；WB | `ifu_pipe`；WBU结果寄存器 | 1项 | HDU执行4组紧凑比较，不使用EXU局部旁路 | 低延迟与较小面积 |
| P4 | IF；ID与Dispatch；EX；WB | `ifu_pipe`；`dispatch_pipe`；WBU结果寄存器 | 3项 | 近期commit id表与局部旁路 | 面积和频率平衡 |
| P5 | IF；ID；Dispatch；EX；WB | `ifu_pipe`；`idu_id_pipe`；`dispatch_pipe`；WBU结果寄存器 | 3项 | 近期commit id表与局部旁路 | 更清晰的时序边界 |

`ifu_pipe`和WBU结果寄存器在三种配置中始终存在。`idu_id_pipe`只用于P5数据通路；`dispatch_pipe`在P4与P5中为寄存器边界，在P3中直接通过。P3用更短的数据通路减少等待，P4与P5用更多寄存器边界改善时序收敛。

```systemverilog
if (PIPELINE_STAGES == 5) begin
    id_to_dispatch = idu_id_pipe;
end else begin
    id_to_dispatch = idu_result;
end

if (PIPELINE_STAGES >= 4) begin
    exu_request = dispatch_pipe;
end else begin
    exu_request = dispatch_result;
end
```

### 3.3 固定宽度取指

IFU在硬件支持C扩展时仍保留固定宽度快速取指。对已经确认的32位指令流，取指继续使用早期预测和普通发出条件；只有遇到16位指令或跨32位边界的指令时，才进入半字拼接处理。这样使支持C扩展的硬件不会让未使用压缩指令的软件承担明显额外等待。

### 3.4 控制流与异常进入

中断请求到达时，CLINT不能仅使用当前取指PC，因为BJP可能正在更正下一条PC。控制逻辑等待BJP请求可确认后再保存`mepc`，并在原子操作或存储操作繁忙时推迟异常进入。这能避免把中断插入LR/SC或AMO序列中间。

## 4. 存储接口

### 4.1 AXI4-Full接口

取指接口和一致性控制之后的共享数据接口采用AXI4-Full，地址宽度为32位，数据宽度跟随XLEN（整数寄存器宽度），当前性能配置为32位，ID（标识号）宽度为2位。标准接口保留`ID`、`LEN`、`SIZE`、`BURST`、`LOCK`、`CACHE`、`PROT`、`QOS`与`LAST`。CPU与一致性控制之间的数据接口还带有第4.2节说明的内部扩展字段，因此该段接口应称为“AXI4-Full加Alkaid内部扩展”，不能作为纯AXI4-Full接口直接连接通用AXI模块。

AXI4-Lite Cache与乒乓缓存仍可优化普通单拍访问，并完整保留AXI4-Full控制字段。突发访问和排他访问从Cache查找旁路通过，错误响应保持原值返回CPU。内部原子扩展的旁路行为在第4.2节单独说明。

AXI4-Full的五个独立通道分别为AW（写地址）、W（写数据）、B（写响应）、AR（读地址）和R（读响应）。各通道只在自身`VALID`与`READY`同时为1时完成一次握手。

`AWLOCK`、`ARLOCK`、`EXOKAY`和`OKAY`均属于标准AXI4排他访问机制。AXI4中的`AWLOCK`或`ARLOCK`置1表示排他访问，不表示锁住总线，也不禁止其他hart访问所有地址。排他读成功时返回`EXOKAY`；排他写只有在排他监视检查成功并实际完成写入时返回`EXOKAY`，检查失败时返回`OKAY`且不得更新目标地址。

### 4.2 Alkaid内部扩展

#### 4.2.1 接口分类

CPU数据接口增加`AWATOP`和`ARATOP`两个4位原子操作字段。`AWATOP`沿用AW Atomic Operation（AW通道原子操作）的名称，`ARATOP`按项目内部AR Atomic Operation（AR通道原子操作）命名。这两个字段与相应地址通道同时传递，但不属于AXI4-Full信号。

需要特别区分Alkaid的4位`AWATOP`与AMBA 5（Advanced Microcontroller Bus Architecture 5，第五代高级微控制器总线架构）定义的`AWATOP[5:0]`。AMBA 5原子事务只增加6位`AWATOP`，原子请求从AW通道发出；Alkaid使用自定义4位编码，并额外增加`ARATOP`以标记本地读改写过程的读阶段。两者的位宽、编码和事务组织均不兼容，不能把当前接口声明为AXI5（Advanced eXtensible Interface 5，第五代高级可扩展接口）原子事务接口。标准分类参考[AMBA AXI and ACE Protocol Specification](https://developer.arm.com/-/media/Arm%20Developer%20Community/PDF/IHI0022H_amba_axi_protocol_spec.pdf)。

| 类别 | 信号 | 是否属于AXI4-Full | 使用范围 |
| --- | --- | --- | --- |
| 标准排他访问 | `AWLOCK`、`ARLOCK`、`BRESP`、`RRESP` | 是 | CPU接口、仲裁器和共享侧接口 |
| Alkaid原子操作扩展 | `AWATOP`、`ARATOP` | 否 | CPU、AXI4-Lite Cache与一致性控制 |
| 写地址选择扩展 | `S_AXI_AWROUTE`、`M_AXI_AWROUTE` | 否 | AXI4-Lite Cache之后的乒乓缓存内部 |
| Cache旁路控制 | `S_AXI_AW_BYPASS`、`S_AXI_AR_BYPASS` | 否 | AXI4-Lite Cache内部 |
| Alkaid监听失效接口 | `SNOOP_INVALIDATE_VALID`、`SNOOP_INVALIDATE_OWNER`、`SNOOP_INVALIDATE_ADDR` | 否 | 一致性控制与私有Cache之间 |

双hart模式下，一致性控制读取`AWATOP`和`ARATOP`，完成LR/SC保留检查、AMO互斥和失败SC响应生成。处理完成后，共享侧不再输出这两个字段，共享存储器只接收标准AXI4-Full请求。因此，通用AXI从设备不需要识别Alkaid原子操作编码。

单hart模式不经过双hart一致性控制，LR/SC保留检查和AMO读改写由LSU本地完成。`AWATOP`和`ARATOP`仍可在CPU内部数据接口与私有Cache之间传递，但不会出现在共享存储器接口。由此，两种hart配置面向共享存储器的一侧都保持标准AXI4-Full端口集合。

#### 4.2.2 原子操作编码

`AWATOP`仅在`AWVALID=1`时有效，`ARATOP`仅在`ARVALID=1`时有效。普通访问将对应字段置0；字段非零时，AXI4-Lite Cache不使用普通访问的Cache命中结果，请求携带原始AXI4控制字段进入一致性控制。

| 编码 | 操作 | 有效通道 | 一致性控制处理 |
| ---: | --- | --- | --- |
| 0 | 普通访问 | AW或AR | 不启动原子控制 |
| 1 | LR | AR | 保存来源hart和8字节粒度保留地址 |
| 2 | SC | AW | 检查本hart保留状态；成功时发出写请求，失败时禁止共享侧写入并在CPU侧产生B响应 |
| 3 | AMOSWAP | 先AR、后AW | 从读请求被接受起保持AMO互斥，写响应结束后解除 |
| 4 | AMOADD | 先AR、后AW | 同上 |
| 5 | AMOXOR | 先AR、后AW | 同上 |
| 6 | AMOAND | 先AR、后AW | 同上 |
| 7 | AMOOR | 先AR、后AW | 同上 |
| 8 | AMOMIN | 先AR、后AW | 同上 |
| 9 | AMOMAX | 先AR、后AW | 同上 |
| 10 | AMOMINU | 先AR、后AW | 同上 |
| 11 | AMOMAXU | 先AR、后AW | 同上 |
| 12至15 | 未分配 | 无 | CPU正常执行过程不会产生；接口连接时不得使用 |

AMO由LSU先发出带`ARATOP`的读请求，取得旧值并计算新值，再发出带同一操作编码的`AWATOP`写请求。一致性控制不要求共享存储器直接执行AMO，而是在读阶段开始后阻止另一hart进入冲突的原子过程，并在对应写响应完成后结束AMO互斥。LR只使用`ARATOP=1`，SC只使用`AWATOP=2`。`AWLOCK`和`ARLOCK`仍传递标准排他属性，但仅凭这两个标准字段不能区分LR、SC和各类AMO，具体类型必须由内部扩展字段给出。

#### 4.2.3 写地址选择字段

`S_AXI_AWROUTE`和`M_AXI_AWROUTE`是乒乓缓存内部使用的6位写地址选择字段，不属于AXI4-Full。互连在AW进入乒乓缓存前根据`AWADDR`生成该字段，位0至位5依次代表IMEM、DMEM（Data Memory，数据存储器）、调试模块、APB（Advanced Peripheral Bus，高级外设总线）、CLINT和PLIC（Platform-Level Interrupt Controller，平台级中断控制器）。正常情况下该字段为独热值，与同一笔AW请求一起保存在弹性寄存器中；AW暂停时保持不变。

乒乓缓存输出端使用`M_AXI_AWROUTE`恢复这6位选择结果。开启写通道寄存级后，AW地址和选择结果始终属于同一笔请求，即使乒乓缓存中同时保存两笔写地址，也不会把较早请求的B响应送到错误从端。该字段只在互连内部使用，不送入IMEM、DMEM或外设，也不出现在CPU接口和SoC外部接口。未开启写通道寄存级时，互连直接使用当前选择状态，不依赖该字段。

设计没有增加`ARROUTE`或`WROUTE`。读响应根据各从端的未完成读事务数和R通道有效状态选择；W通道的目标在AW握手后由互连保存。B通道不带地址，而AW可能在弹性寄存器中等待，因此只有写地址通道需要携带`AWROUTE`，用于保持首次写请求与从端选择结果同步。

#### 4.2.4 Cache旁路字段

`S_AXI_AW_BYPASS`和`S_AXI_AR_BYPASS`是AXI4-Lite Cache内部控制信号，不属于CPU接口，也不属于共享侧接口。写请求满足`AWLOCK=1`、`AWLEN`非零或`AWATOP`非零中的任一条件时，`S_AXI_AW_BYPASS`置1；读请求满足`ARLOCK=1`、`ARLEN`非零或`ARATOP`非零中的任一条件时，`S_AXI_AR_BYPASS`置1。Cache控制逻辑据此跳过普通单拍Cache处理，并保持原请求字段不变地发出访问。

#### 4.2.5 监听失效接口

监听失效接口独立于AXI五个通道，没有`READY`信号，也不参与AXI握手。共享侧AW完成握手时，一致性控制在同一周期将`SNOOP_INVALIDATE_VALID`置1，`SNOOP_INVALIDATE_OWNER`给出写请求来源hart，`SNOOP_INVALIDATE_ADDR`给出已接受的写地址。系统根据来源hart只向另一个hart发出本地失效有效信号，接收hart清除私有ICache、私有DCache和LSU L0 Cache中的相关状态。

该接口以共享侧`AWVALID && AWREADY`为触发条件。只有CPU侧AW被选择但尚未被共享侧接受时，不产生失效请求；只有W通道握手时也不产生失效请求。由于接口没有反压能力，接收端必须与一致性控制使用同一时钟，并在有效周期完成失效状态更新。

### 4.3 取指读仲裁

`axi_dual_read_arbiter`合并两个hart的AR与R通道。当前`ID_WIDTH=2`，因此共享侧ID取值为0至3，对应4项读事务记录。共享侧ID直接作为记录表下标，不是将hart编号与CPU侧本地ID拼接。每项有效记录保存来源hart和该hart发出请求时的本地`ARID`，使两个hart即使使用相同本地ID，也能通过不同的共享侧ID同时保留请求。

#### 4.3.1 请求选择

仲裁器先检查两个hart的`ARVALID`。只有一个hart请求时直接选择该hart；两个hart同时请求时选择上一次成功获得服务的另一个hart。复位后保存的上次选择值为hart1，因此复位后的第一次双请求选择hart0。只有共享侧AR通道完成`ARVALID && ARREADY`握手后，仲裁器才更新上次选择值，未被共享侧接受的请求不会改变下一次双请求的优先次序。

仲裁器每周期最多向共享侧发送一笔AR请求。存在空闲记录且至少一个hart提出请求时，共享侧`ARVALID`才为1；只有被选hart能够看到`ARREADY=1`。共享侧未准备好或4项记录全部有效时，两个hart的`ARREADY`都保持为0，请求hart必须继续保持`ARID`、地址和其他AR控制字段。

#### 4.3.2 ID分配

空闲记录选择采用从0到3的固定顺序扫描，选择编号最小的无效项。共享侧`ARID`等于该记录编号。记录只在共享侧AR握手时写入，保存内容为有效位、来源hart和原始本地`ARID`；仅出现`ARVALID`而没有完成握手时，不占用记录。

| 步骤 | CPU侧请求或共享侧响应 | 使用的共享侧ID | 记录内容或处理结果 |
| ---: | --- | ---: | --- |
| 1 | hart0以本地`ARID=2`发出请求 | 0 | 记录0保存hart0和本地ID 2 |
| 2 | hart1也以本地`ARID=2`发出请求 | 1 | 记录1保存hart1和本地ID 2 |
| 3 | 共享侧先返回`RID=1` | 1 | 查记录1，将响应送给hart1，并恢复`RID=2` |
| 4 | 共享侧随后返回`RID=0` | 0 | 查记录0，将响应送给hart0，并恢复`RID=2` |

该例说明，共享侧ID的作用是唯一标识当前仍未结束的共享读事务；CPU侧ID只在请求进入时保存，在响应回送时恢复。两个ID字段宽度虽然相同，但请求经过仲裁后数值不必相同。

#### 4.3.3 响应回送

共享侧返回`RVALID`时，仲裁器以`RID`读取对应记录。记录有效时，来源hart决定哪一路CPU侧`RVALID`置1，原始本地ID作为该路CPU侧`RID`，`RDATA`、`RRESP`和`RLAST`保持共享侧返回值。另一个hart的`RVALID`保持为0，因此不会接收不属于自己的响应。

共享侧`RREADY`取自响应所属hart的`RREADY`。如果该hart暂停接收，仲裁器同时阻止共享侧完成R握手，响应字段按照AXI4规则保持不变。若共享侧给出的`RID`没有对应有效记录，仲裁器不会向任一hart给出`RVALID`，同时保持共享侧`RREADY=0`，避免错误响应被送入CPU；验证环境应将这种情况报告为AXI协议错误。

突发读的所有返回拍使用同一个共享侧`RID`。中间拍完成握手后仍保留记录，只有最后一拍完成`RVALID && RREADY && RLAST`握手时才释放记录，因此每一拍都使用同一来源hart和本地ID。

#### 4.3.4 未完成事务

4项记录允许两个hart合计保留4笔未完成事务（outstanding）。只要仍有空闲记录且共享侧能够接收，仲裁器就可以继续接受新AR请求，不需要等待较早请求返回。不同共享侧ID的响应可以采用不同于请求发出次序的返回次序，记录表仍能恢复正确的来源hart和本地ID。

同一hart对同一本地ID连续发出的多笔请求仍须遵守AXI4的同ID顺序规则。当前记录表负责来源hart和本地ID的恢复，不对同一hart、同一本地ID的多笔响应再次排序。因此，任意次序返回能力适用于不同的“来源hart与本地ID”组合；若从设备可能打乱同一组合的返回次序，系统还需要在共享侧保证该组合按请求次序返回。

### 4.4 数据一致性控制

`axi_dual_coherency_manager`合并两个hart的数据读写请求，并分别设置4项读事务记录和4项写事务记录。读表与写表相互独立，因此数值相同的共享侧读ID和写ID可以同时有效；R通道只查询读表，B通道只查询写表，不会相互混淆。

#### 4.4.1 读请求仲裁

数据读请求使用与取指读相同的双hart轮换方法和共享侧ID分配方法。共享侧AR握手时，读表在`ARID`指定的记录中保存来源hart和原始本地`ARID`；共享侧R响应通过`RID`查询读表，恢复来源hart和本地ID；最后一拍R响应握手后释放记录。

进入轮换选择前，控制逻辑先判断请求是否允许读取。每笔读请求根据`ARADDR`、`ARLEN`和`ARSIZE`计算起始与结束的8字节区域，并与两个hart当前有效的AW请求以及全部未结束写记录进行比较。范围重叠的读请求暂不参加本周期仲裁，无重叠的读请求仍可发出。LR和AMO还需满足第6章所述的写事务与原子互斥条件。

#### 4.4.2 写请求仲裁

写仲裁以`AWVALID`判断两个hart是否提出写请求。只有一个hart请求时直接选择该hart；两个hart同时请求时选择上一次写选择的另一个hart。开始选择新写请求还要求当前没有正在补齐AW或W握手的写请求、没有等待CPU接收的内部写响应，并且写表存在空闲记录。

写表的空闲记录同样按照编号0至3的顺序选择，编号最小的无效项作为下一笔写请求的共享侧ID，共享侧`AWID`等于该编号。AXI4的AW与W通道相互独立，W通道没有事务ID。控制逻辑选定hart后，保存来源hart、拟使用的共享侧ID、原始本地`AWID`以及AW和W各自是否已经握手。在当前写请求的AW与W均完成握手前，选择结果保持不变，另一个hart不能插入W数据。AW先完成时继续等待当前hart的W；W先完成时继续等待当前hart的AW；两个通道同周期完成时无需增加等待周期。即使W早于AW完成握手，当前选择也会独占拟使用的共享侧ID，其他写请求不能重复使用该编号。

共享侧AW握手时，共享侧`AWID`指定的写记录变为有效。该记录保存来源hart、原始本地`AWID`、是否为成功SC、是否属于AMO，以及根据`AWADDR`、`AWLEN`和`AWSIZE`计算出的起始与结束8字节区域。写记录一直保留到B响应完成握手。在当前请求的AW与W都已被接受后，即使较早请求的B响应尚未返回，仲裁器也可以选择下一笔写请求，因此普通写可以连续发出并形成多笔未完成写事务。

#### 4.4.3 写响应回送

共享侧返回`BVALID`时，控制逻辑以`BID`查询写表，得到来源hart和原始本地`AWID`。只有来源hart的CPU侧`BVALID`置1，CPU侧`BID`恢复为原始本地ID，`BRESP`保持共享侧结果；成功SC按照第6章的规则返回`EXOKAY`。共享侧`BREADY`取自来源hart的`BREADY`，所以CPU暂停接收时不会提前释放写记录。只有`BVALID && BREADY`握手完成后，`BID`对应的写记录才变为空闲。

SC条件不成立时，请求不会发送到共享侧。控制逻辑在CPU侧产生内部B响应，直接使用已保存的来源hart和本地`AWID`，不占用共享侧写记录。该响应同样等待对应hart给出`BREADY`后结束。

共享侧AW握手同时产生监听失效请求，携带来源hart和写地址。系统只把失效请求送给另一个hart，接收方清除私有ICache、私有DCache和LSU L0 Cache中的相关状态。监听失效以共享侧真正接受写地址为准，不会因仅选择了写请求或仅完成W握手而提前发生。

#### 4.4.4 未完成事务容量

| 通道 | 记录数量 | 分配时机 | 释放时机 | 允许的返回次序 |
| --- | ---: | --- | --- | --- |
| 取指读 | 4项 | 共享侧AR握手 | 最后一拍R握手 | 不同来源hart与本地ID组合之间可以改变次序 |
| 数据读 | 4项 | 共享侧AR握手 | 最后一拍R握手 | 不同来源hart与本地ID组合之间可以改变次序 |
| 数据写 | 4项 | 共享侧AW握手 | B握手 | 不同来源hart与本地ID组合之间可以改变次序 |
| 失败SC | 不占用共享记录 | CPU侧AW与W均被接受 | 内部B握手 | 只返回发起SC的hart |

普通访问最多可以同时保留4笔数据读事务和4笔数据写事务。读写表使用独立有效位，即使读表和写表都使用共享侧ID 0，也能分别通过`RID`和`BID`找到正确记录。写请求处理中只允许一笔请求处于AW或W尚未完成的状态，这是因为AXI4的W通道不携带ID；已经完成AW与W握手、仅等待B响应的写请求可以有多笔。

### 4.5 标准AXI4关键端口

下表以CPU侧面向一致性控制的接口为准。每个信号单独一行；数组形式信号的位宽还需乘以hart数量。

| 信号 | 方向 | 位宽 | 功能 | 有效条件 | 暂停、错误与复位行为 |
| --- | --- | ---: | --- | --- | --- |
| `AWID` | CPU输出 | 2位 | 写事务本地ID | `AWVALID=1` | `AWREADY=0`时保持；复位后无待处理请求 |
| `AWADDR` | CPU输出 | 32位 | 写起始地址 | `AWVALID=1` | 暂停时保持；地址错误由`BRESP`报告 |
| `AWLEN` | CPU输出 | 8位 | 写突发拍数减一 | `AWVALID=1` | 暂停时保持；与`WLAST`不一致时报告协议错误 |
| `AWSIZE` | CPU输出 | 3位 | 每拍字节数 | `AWVALID=1` | 暂停时保持；不支持的大小返回错误 |
| `AWBURST` | CPU输出 | 2位 | 写突发类型 | `AWVALID=1` | 暂停时保持；不支持的类型返回错误 |
| `AWLOCK` | CPU输出 | 1位 | 标记排他写 | `AWVALID=1` | 暂停时保持，并穿过仲裁与Cache旁路 |
| `AWCACHE` | CPU输出 | 4位 | 写Cache属性 | `AWVALID=1` | 暂停时保持；复位后清零 |
| `AWPROT` | CPU输出 | 3位 | 写保护属性 | `AWVALID=1` | 暂停时保持；从设备按属性检查访问 |
| `AWQOS` | CPU输出 | 4位 | 写服务等级 | `AWVALID=1` | 暂停时保持；不参与响应成功判断 |
| `AWVALID` | CPU输出 | 1位 | 指示写地址有效 | 高电平有效 | 等待`AWREADY`期间保持为1；复位后清零 |
| `AWREADY` | CPU输入 | 1位 | 接受被选hart的写地址 | 与`AWVALID`同时为1时握手 | 写表已满、另一笔写请求正在等待AW或W、原子互斥或共享侧暂停时拉低；复位期间拉低 |
| `WDATA` | CPU输出 | XLEN位 | 写数据 | `WVALID=1` | `WREADY=0`时保持；错误由写响应报告 |
| `WSTRB` | CPU输出 | XLEN/8位 | 写字节使能 | `WVALID=1` | 暂停时保持；无效组合不更改未选字节 |
| `WLAST` | CPU输出 | 1位 | 标记写突发最后一拍 | `WVALID=1` | 暂停时保持；最后一拍握手后结束写数据 |
| `WVALID` | CPU输出 | 1位 | 指示写数据有效 | 高电平有效 | 等待`WREADY`期间保持为1；复位后清零 |
| `WREADY` | CPU输入 | 1位 | 接受被选hart的写数据 | 与`WVALID`同时为1时握手 | 仅向当前写请求所属hart开放；当前W已握手、无已选写请求或共享侧暂停时拉低；复位期间拉低 |
| `BID` | CPU输入 | 2位 | 返回原始写事务ID | `BVALID=1` | `BREADY=0`时保持；共享侧ID无有效记录时不回送CPU并阻止共享侧握手 |
| `BRESP` | CPU输入 | 2位 | 返回写结果 | `BVALID=1` | `SLVERR`与`DECERR`保持为错误；条件写成功可返回`EXOKAY` |
| `BVALID` | CPU输入 | 1位 | 指示写响应有效 | 高电平有效 | 等待`BREADY`期间保持响应；复位后清零 |
| `BREADY` | CPU输出 | 1位 | 接受写响应 | 与`BVALID`同时为1时握手 | CPU暂停时可拉低；复位后清零 |
| `ARID` | CPU输出 | 2位 | 读事务本地ID | `ARVALID=1` | `ARREADY=0`时保持；复位后无待处理请求 |
| `ARADDR` | CPU输出 | 32位 | 读起始地址 | `ARVALID=1` | 暂停时保持；地址错误由`RRESP`报告 |
| `ARLEN` | CPU输出 | 8位 | 读突发拍数减一 | `ARVALID=1` | 暂停时保持；返回拍数与`RLAST`一致 |
| `ARSIZE` | CPU输出 | 3位 | 每拍字节数 | `ARVALID=1` | 暂停时保持；不支持的大小返回错误 |
| `ARBURST` | CPU输出 | 2位 | 读突发类型 | `ARVALID=1` | 暂停时保持；不支持的类型返回错误 |
| `ARLOCK` | CPU输出 | 1位 | 标记排他读 | `ARVALID=1` | 暂停时保持，并穿过仲裁与Cache旁路 |
| `ARCACHE` | CPU输出 | 4位 | 读Cache属性 | `ARVALID=1` | 暂停时保持；复位后清零 |
| `ARPROT` | CPU输出 | 3位 | 读保护属性 | `ARVALID=1` | 暂停时保持；从设备按属性检查访问 |
| `ARQOS` | CPU输出 | 4位 | 读服务等级 | `ARVALID=1` | 暂停时保持；不参与响应成功判断 |
| `ARVALID` | CPU输出 | 1位 | 指示读地址有效 | 高电平有效 | 等待`ARREADY`期间保持为1；复位后清零 |
| `ARREADY` | CPU输入 | 1位 | 接受被选hart的读地址 | 与`ARVALID`同时为1时握手 | 读表已满、共享侧暂停、写范围重叠或原子互斥时拉低；未被选择的hart保持为0 |
| `RID` | CPU输入 | 2位 | 返回原始读事务ID | `RVALID=1` | `RREADY=0`时保持；共享侧ID无有效记录时不回送CPU并阻止共享侧握手 |
| `RDATA` | CPU输入 | XLEN位 | 返回读数据 | `RVALID=1` | `RREADY=0`时保持；错误数据被阻止提交到GPR |
| `RRESP` | CPU输入 | 2位 | 返回读结果 | `RVALID=1` | 错误状态保持；保留读成功可返回`EXOKAY` |
| `RLAST` | CPU输入 | 1位 | 标记读突发最后一拍 | `RVALID=1` | 暂停时保持；握手后释放读事务记录 |
| `RVALID` | CPU输入 | 1位 | 指示读响应有效 | 高电平有效 | 等待`RREADY`期间保持全部响应字段；复位后清零 |
| `RREADY` | CPU输出 | 1位 | 接受读响应 | 与`RVALID`同时为1时握手 | CPU暂停时可拉低；复位后清零 |

### 4.6 内部扩展端口

下表中的信号均不属于AXI4-Full。`AWATOP`和`ARATOP`附加在CPU侧数据接口，`AWROUTE`和旁路字段只在内部模块之间使用，监听失效信号构成独立接口。集成时不得把这些字段作为标准AXI端口连接到通用AXI模块。

| 信号 | 方向 | 位宽 | 功能 | 有效条件 | 暂停、错误与复位行为 |
| --- | --- | ---: | --- | --- | --- |
| `AWATOP` | CPU输出 | 4位 | 指示写阶段的Alkaid原子操作类型 | `AWVALID=1` | `AWREADY=0`时与AW字段一起保持；非零时旁路普通Cache处理；复位后清零 |
| `ARATOP` | CPU输出 | 4位 | 指示读阶段的Alkaid原子操作类型 | `ARVALID=1` | `ARREADY=0`时与AR字段一起保持；非零时旁路普通Cache处理；复位后清零 |
| `S_AXI_AWROUTE` | 乒乓缓存输入 | 6位 | 携带写地址对应的从端选择结果 | `S_AXI_AWVALID=1` | `S_AXI_AWREADY=0`时与其他AW字段一起保持；复位期间有效信号为0时不使用本字段 |
| `M_AXI_AWROUTE` | 乒乓缓存输出 | 6位 | 输出与当前AW请求同步的从端选择结果 | `M_AXI_AWVALID=1` | `M_AXI_AWREADY=0`时保持；复位清除缓存内有效状态后不使用本字段 |
| `S_AXI_AW_BYPASS` | Cache控制输入 | 1位 | 指示写请求跳过普通Cache处理 | `S_AXI_AWVALID=1` | 随AW标准字段和`AWATOP`组合产生；AW暂停时保持；复位期间请求无效 |
| `S_AXI_AR_BYPASS` | Cache控制输入 | 1位 | 指示读请求跳过普通Cache处理 | `S_AXI_ARVALID=1` | 随AR标准字段和`ARATOP`组合产生；AR暂停时保持；复位期间请求无效 |
| `SNOOP_INVALIDATE_VALID` | 一致性控制输出 | 1位 | 指示跨hart失效请求有效 | 共享侧AW完成握手的周期 | 没有暂停和重试能力；接收端当拍处理；复位期间没有有效AW请求时为0 |
| `SNOOP_INVALIDATE_OWNER` | 一致性控制输出 | 1位 | 给出写请求来源hart | `SNOOP_INVALIDATE_VALID=1` | 与有效信号同周期使用；系统不向来源hart发出本地失效请求；复位期间有效信号为0时不使用本字段 |
| `SNOOP_INVALIDATE_ADDR` | 一致性控制输出 | 32位 | 给出已被共享侧接受的写地址 | `SNOOP_INVALIDATE_VALID=1` | 与有效信号同周期使用；接收端清除相应Cache状态；复位期间有效信号为0时不使用本字段 |

> [!WARNING]
> AXI4的AW与W相互独立。控制逻辑分别记住两个通道是否握手，不限定它们在同一周期完成，也不会在只收到其中一个通道后提前产生B响应。

## 5. Cache结构

### 5.1 私有ICache

每个hart拥有独立只读ICache。双hart默认每核2048项、2路，并允许4笔取指读事务。共享侧写IMEM时，写地址会使两个hart中相关ICache项失效，防止自修改代码或程序下载完成后仍然执行旧指令。

### 5.2 私有DCache

私有DCache采用写穿透方式，提供1024项、2路配置能力，CPU侧默认只保留1笔未完成数据事务。普通单拍访问可使用Cache，突发、排他和原子访问直接旁路。当前双核CoreMark性能配置关闭DCache，因此性能结果主要反映LSU L0 Cache与共享总线行为。

### 5.3 LSU L0 Cache

两个CPU各自使用独立LSU L0 Cache，深度允许1至1024项，组相联度允许1路或2路。当前性能配置使用1024项、1路，只缓存DTCM（数据紧耦合存储器）区域。其他hart写入相关地址时，本hart清除命中项；本地写可以更新或清除对应项。原子操作期间禁止使用相关命中或填充，避免普通缓存状态干扰原子指令。

```systemverilog
l0_hit = l0_valid[index] &&
         l0_tag[index] == request_tag &&
         request_in_dtcm &&
         !atomic_busy;

if (peer_snoop_valid && peer_snoop_match) begin
    l0_valid[peer_index] <= 1'b0;
end
```

### 5.4 AXI4-Lite Cache与乒乓缓存

`axi_lite_cache`保留其正式模块名，但标准端口已经携带完整AXI4-Full字段。旁路模式逐项传递全部标准控制字段；只读模式按ID跟踪多笔响应；读写模式仅优化普通单拍请求。CPU侧数据接口还单独传递`AWATOP`和`ARATOP`，任一有效地址请求携带非零原子操作编码时均旁路普通Cache处理。一致性控制处理并移除原子操作字段后，乒乓缓存只接收标准AXI4-Full字段和内部`AWROUTE`，利用弹性寄存器降低普通访问的等待周期，并保持突发信息、排他属性、响应ID和错误状态不变。

## 6. 原子操作

### 6.1 支持范围

Alkaid实现RISC-V A（原子操作）扩展的LR/SC（保留读/条件写），并支持AMO（原子存储器操作）交换、加、异或、与、或、有符号最小值、有符号最大值、无符号最小值和无符号最大值。LSU用`AWLOCK`与`ARLOCK`传递标准AXI4排他属性，并用第4.2节定义的4位`AWATOP`与`ARATOP`指出具体操作。

### 6.2 保留监视

每个hart保存独立的保留有效位与8字节粒度地址。任意hart成功写入同一8字节范围时，两个hart中匹配的保留都被清除。SC仅在当前hart保留有效且地址相同时向存储器发出写请求。

SC成功时一致性控制返回`EXOKAY`，LSU向目的寄存器写0；SC失败时不发出共享写请求，由控制逻辑产生成功完成形式的内部响应，LSU向目的寄存器写1。无论成功或失败，本hart保留都会清除。

```systemverilog
sc_success = reservation_valid[hart] &&
             reservation_addr[hart] == request_addr[ADDR_WIDTH-1:3];

if (is_sc && !sc_success) begin
    suppress_shared_write = 1'b1;
    cpu_sc_result = 1'b1;
end
```

### 6.3 AMO互斥

AMO从原子读开始到对应写响应结束期间占用全局原子互斥状态。存在普通写事务时暂缓新的AMO，AMO进行期间也不接受可能破坏原子读改写的冲突请求。原子读返回旧值，LSU计算新值，原子写完成后将旧值提交到目的寄存器。

> [!NOTE]
> `AWLOCK`和`ARLOCK`用于传递排他属性，但仅有lock信号不足以实现RISC-V原子操作。保留监视、SC失败处理、冲突写清除、Cache失效和软件存储顺序缺一不可。

## 7. CLINT与多hart异常

### 7.1 寄存器组织

| 寄存器 | 地址偏移 | hart步长 | 功能 |
| --- | ---: | ---: | --- |
| `MSIP` | `0x0000` | 4字节 | 对应hart的软件中断位 |
| `MTIMECMP`低32位 | `0x4000` | 8字节 | 对应hart定时器比较值低半部分 |
| `MTIMECMP`高32位 | `0x4004` | 8字节 | 对应hart定时器比较值高半部分 |
| `MTIME`低32位 | `0xBFF8` | 共享 | 全局时间低半部分 |
| `MTIME`高32位 | `0xBFFC` | 共享 | 全局时间高半部分 |

RV32读取64位时间时使用“高、低、高”次序并在两个高值不同后重读。写`MTIMECMP`时先写高32位全1，再写低32位，最后写目标高32位，以免更新中途提前触发定时器中断。

### 7.2 异常控制

CLINT异常控制依次更新`mepc`、`mstatus`、可选`mtval`和`mcause`，`mret`时恢复`mstatus`。BJP请求用于确认控制流已经解析出的下一条PC。原子操作或存储尚未结束时，异常请求保持等待，直至当前操作可以安全结束。

### 7.3 软件中断

`MSIP`用于IPI（核间中断）。主hart写目标hart的`MSIP`后，从hart进入软件中断处理；处理程序完成本地动作并清除自己的`MSIP`。每个hart的定时器比较值独立，因此RT-Thread可以为两个CPU分别维护调度节拍。

## 8. 启动与AMP

### 8.1 汇编启动

所有hart首先读取`mhartid`并选择独立且按ABI（应用二进制接口）对齐的栈，同时初始化保存寄存器。hart0清零全局未初始化数据区、设置异常入口并完成全局初始化；hart1在等待区检查启动标志，不重复清零全局状态。

hart0发布启动参数前执行`fence rw, rw`。hart1观察到启动标志后执行`fence r, rw`，设置异常入口并进入从hart函数。双hart各预留8 KiB栈空间，总栈空间为16 KiB。

### 8.2 AMP服务

AMP服务为每个hart保存离线、等待、运行和完成四种状态，以及函数地址、参数和返回值。主hart填写函数与参数，执行发布栅栏，更新启动状态并发送IPI；从hart执行获取栅栏后调用函数，保存返回值，发布完成状态，然后回到等待区。

AMP双启动测试是SMP调试的前置步骤。如果CoreMark SMP未通过，应先确认双hart独立栈、IPI、函数调用、返回值、LR/SC与AMO均在AMP测试中正确工作。

## 9. RT-Thread SMP移植

### 9.1 配置生成

RT-Thread使用专用Env配置工具处理Kconfig依赖。平台配置启用`RT_USING_SMP`、设置`RT_CPUS_NR=2`并选择`RT_USING_HW_ATOMIC`。构建描述通过Env生成的配置结果决定是否加入硬件原子端口，不依赖人工修改普通编译命令。

> [!NOTE]
> 修改RT-Thread功能选项后，应先运行Env配置工具并保存配置，再执行构建。这样可以让SMP、CPU数量与硬件原子端口保持一致。

### 9.2 CPU端口

CPU端口读取`mhartid`作为当前CPU编号。自旋锁使用`amoswap.w.aq`循环获取，释放前执行`fence rw, w`再清零锁值。IPI函数遍历目标CPU位集合并写对应CLINT `MSIP`。从CPU启动时先调用AMP服务进入本地初始化，再进入调度器；空闲线程执行WFI（等待中断）。

```asm
1:
    li          t0, 1
    amoswap.w.aq t1, t0, (a0)
    bnez        t1, 1b

    # 临界区结束后释放
    fence       rw, w
    sw          zero, 0(a0)
```

### 9.3 原子接口

RT-Thread硬件原子API（应用程序接口）为RV32与RV64分别实现交换、加、减、异或、与、或、读取、写入、标志测试设置、标志清除和比较交换。交换使用`amoswap`，加减使用`amoadd`，读取可使用零值`amoxor`，比较交换使用带`aq`与`rl`属性的LR/SC循环。

```c
do {
    old = lr_aq(ptr);
    if (old != expected) {
        break;
    }
    failed = sc_rl(ptr, desired);
} while (failed);
```

API实现同时加入编译器内存约束，避免编译器把临界区读写移动到原子操作之外。上层内核统一调用RT-Thread原子API，不直接依赖某个应用中的内联汇编。

### 9.4 CoreMark并行执行

CoreMark的单核与双核程序采用相同并行构建设置，运行上下文数均由`RT_CPUS_NR`确定。主上下文固定在hart0，工作线程固定在hart1；hart0直接执行本地上下文，hart1执行第二上下文。启动、就绪与完成状态使用原子变量，避免高优先级主线程迁移后持续占用hart1。

## 10. 验证环境

### 10.1 注册方式

AXI用例已经注册到Python调度与配置文件驱动的统一验证环境，不使用独立运行脚本。配置项选择测试平台、AXI参数、激励类型、超时和覆盖率统计；调度程序依据配置完成编译、运行与结果归档。

TVIP-AXI VIP配置为AXI4、2位ID、32位地址、32位数据、最大16拍突发、同一ID内顺序返回以及4笔未完成响应。测试序列先发出4笔写突发，再发出4笔读突发；地址从`0x40`开始，每笔相隔32字节，每拍4字节，每个突发4拍。`LOCK`由地址位6确定，使0与1两种属性都出现在真实握手中。

计分器配置为检查4次AW、4次B、4次AR、16次R和4次`RLAST`，同时检查4笔未完成事务以及lock为0和1的握手。从设备存储模型可保留8笔未完成事务，为主设备产生并发返回条件。

### 10.2 RTL模块结果

下表结果均由Verilator环境完成，包含模块测试、BSP双hart启动、RT-Thread SMP基础测试和公平性能测试。

| 测试项 | 通过数 | 总数 | 结果 |
| --- | ---: | ---: | --- |
| 双hart取指读仲裁 | 31 | 31 | 通过 |
| 双hart数据一致性与原子处理 | 125 | 125 | 通过 |
| 缓冲与Cache | 158 | 158 | 通过 |
| CLINT多hart功能 | 32 | 32 | 通过 |
| CLINT MMIO | 209 | 209 | 通过 |
| IFU AXI主设备 | 15 | 15 | 通过 |
| 异常恢复接口 | 117 | 117 | 通过 |
| BSP双hart启动 | 1 | 1 | 通过 |
| RT-Thread SMP基础测试 | 1 | 1 | 通过 |
| CoreMark公平性能测试 | 1 | 1 | 通过 |

当前环境尚未得到TVIP UVM（通用验证方法学）运行结果。VCS（硬件仿真器）启动包装程序需要进入受限容器，但当前容器禁止该权限提升。用例注册、配置、激励与计分器已经完成；正式回归环境恢复VCS运行条件后，应把该用例纳入常规回归并保存覆盖率统计。

> [!WARNING]
> 上表中的RTL模块结果不代表尚未执行完成的TVIP UVM结果。文档分别记录两类结果，并明确区分“已注册”与“已通过”。

### 10.3 重点场景

- 两个hart使用相同本地ID发出读写请求，并以不同次序返回。
- 读写各达到4笔未完成事务，AW与W在不同周期握手。
- B与R通道施加暂停，全部控制字段在暂停期间保持。
- 普通、突发和排他请求保持正确旁路行为，`AWATOP`或`ARATOP`非零的内部原子请求不进入普通Cache处理。
- LR后无冲突写时SC成功，LR后有冲突写时SC失败且不写存储器。
- 各类AMO返回旧值并写入正确新值。
- 其他hart写入后，ICache、DCache与LSU L0 Cache相关项失效。
- 复位清除事务记录、原子互斥状态、保留状态和有效响应。

## 11. 性能结果

### 11.1 公平比较

性能测试固定使用相同源码、相同优化参数、相同并行构建设置和相同ISA。ELF（可执行与可链接格式）属性均为`rv32i2p1_m2p0_a2p1_b1p0_zicsr2p0_zmmul1p0_zaamo1p0_zalrsc1p0_zba1p0_zbb1p0_zbc1p0_zbs1p0`。硬件虽然支持C扩展，但两组ELF都不含C扩展，因而压缩指令不会造成单核和双核差异。

| 模式 | CoreMark分数 | 周期数 | 相对单核 |
| --- | ---: | ---: | ---: |
| 单hart | 392.0661 | 255059 | 100.00% |
| 双hart | 776.2408 | 257652 | 197.99% |

双hart提升为1.979872倍，即197.99%，超过170%目标；双hart利用效率为98.99%，周期增加1.0166%。结果说明两个上下文基本并行执行，共享总线、原子同步和Cache失效没有形成主要瓶颈。

### 11.2 历史分数差异

已验证裸机单hart性能为411分，加入Cache与乒乓缓存后的参考结果为385分。当前单hart为392.0661分，比411低约4.61%，比385高约1.84%。当前比较使用多线程运行框架，即使只运行一个hart，也保留线程创建、原子状态与RT-Thread调度成本；因此不能把411分的纯裸机结果直接当作当前SMP框架下单hart应达到的数值。

编译参数与ISA检查已经确认单hart和双hart完全一致，因此该差异不是由O3优化或C压缩指令造成。测试程序采用经验证的O3编译参数，硬件同时保留M（整数乘除法）、A与B（位操作）子扩展，测试程序没有启用C。C扩展本身通常不会显著降低每周期工作量，但改变代码排列后可能影响取指与分支行为，所以公平比较仍应保持两组ELF属性一致。

### 11.3 瓶颈分析

双hart周期仅增加约1.02%，说明hart1已经得到充分执行时间。剩余损耗主要来自线程启动与完成同步、调度器固定成本、共享总线短暂仲裁以及跨hart写导致的私有Cache失效。后续若应用的共享数据写比例明显增加，可继续检查以下项目：

- 将频繁更新的独立变量放入不同Cache行，减少无关失效。
- 保持工作线程CPU亲和性，避免主线程迁移到hart1。
- 缩短全局自旋锁临界区，优先使用每hart局部计数。
- 使用未完成事务记录隐藏共享存储等待，不把总线退化为逐笔串行。
- 评估共享L2的收益，但继续保留两个CPU各自的L1 Cache。

## 12. 设计要点

- `core_top`包含单hart的私有ICache、可选私有DCache、LSU L0 Cache接口和CLINT控制。
- 两个CPU各自使用私有L1，系统不使用共享L1。
- 取指接口和一致性控制之后的共享数据接口使用标准AXI4-Full字段，并支持排他访问和多笔未完成事务。
- CPU侧数据接口在AXI4-Full字段之外增加4位`AWATOP`和`ARATOP`，内部模块明确区分标准字段与Alkaid扩展字段。
- AXI4-Lite Cache处理`AWATOP`和`ARATOP`的旁路控制，一致性控制移除原子操作字段后，乒乓缓存只附加内部`AWROUTE`并完整保留标准AXI4-Full请求与响应字段。
- LR/SC与AMO经过集中式一致性控制，不依赖单个Cache的局部状态。
- CLINT按hart提供独立`MSIP`与`MTIMECMP`，两个hart共享`MTIME`。
- CLINT控制流检查只使用BJP请求，不增加重复的指令控制流解码。
- RT-Thread配置由Env工具处理依赖，并启用硬件原子模式。
- CoreMark单hart与双hart保持编译参数、ISA和测试配置相同。
- CoreMark SMP调试以BSP双hart启动和AMP原子测试通过为前提。
- TVIP-AXI用例通过Python与配置文件注册到统一验证环境。
- 覆盖率统计包含并发、暂停、错误、复位、lock、原子操作和跨hart Cache失效。

## 13. 总结

Alkaid双hart模式已经形成完整的硬件与软件配合：`core_top`包含私有L1和CLINT，系统层在标准AXI4-Full共享接口之外提供独立的内部原子操作字段和跨hart失效接口，并完成LR/SC保留与AMO互斥；RT-Thread通过Env配置启用SMP和硬件原子端口，统一验证环境通过Python与配置文件注册AXI用例。Verilator环境下双hart CoreMark达到776.2408分，相对单hart提升197.99%，在ISA与编译参数完全相同的条件下满足性能目标。
