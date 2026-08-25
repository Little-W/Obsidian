# DM 的设计与实现

> [!summary]
> 本文给出一套可与 OpenOCD 协同工作的 RISC-V DM（Debug Module，调试模块）设计方案。重点不是复述寄存器定义，而是说明每项能力由谁完成、RTL 应如何组织、为何需要 Debug ROM 与 Program Buffer，以及怎样从最小实现逐步扩展到可用于 SoC 的版本。

## 1. 设计目标与适用范围

本文面向 RV32/RV64 SoC 的片上调试单元设计。建议将 <code>RISC-V Debug Specification 0.13</code> 作为 OpenOCD 兼容基线；当前 OpenOCD 的 RISC-V 目标驱动仍以 0.13 为主要支持对象。较新的规范字段可以按需增加，但不应假设调试器会自动使用每一项新能力。

本文推荐的基础方案是<strong>执行式调试</strong>：

- DM 通过 <code>haltreq</code> 使 hart 进入 Debug Mode。
- hart 跳入片内 Debug ROM 的暂停程序。
- DM 用抽象命令和 Program Buffer 请求 hart 执行短指令序列。
- Program Buffer 借助 hart 自身的取指、寄存器和 LSU 访问 GPR、CSR 与内存。
- 可选的 SBA（System Bus Access，系统总线访问）作为独立 AXI 主设备，直接访问物理地址。

这种方案只需要 CPU 提供少量调试控制信号，不要求 DM 直接读取通用寄存器堆，因此特别适合已有的顺序 CPU、简单流水 CPU 和中等复杂度 SoC。

> [!tip]
> 如果目标是“先让 GDB 能 halt、读写寄存器、下载程序和单步”，不要一开始实现所有可选寄存器。先完成 DTM、单 hart 运行控制、抽象寄存器访问和 Program Buffer，再增加 SBA、多 hart、trigger 与认证。

### 1.1 推荐的能力分级

| 级别 | 建议能力 | 能解决的问题 | 适用阶段 |
| --- | --- | --- | --- |
| P0 | JTAG DTM、单 hart、<code>dmcontrol</code>/<code>dmstatus</code>、抽象寄存器访问、2 个以上 <code>data</code>、8 个 Program Buffer 字、Debug ROM | halt/resume、GPR/CSR 访问、通过 Program Buffer 访问内存 | 首次接入 OpenOCD |
| P1 | SBA、8/16/32/64 位访问能力、总线错误上报、自动递增 | 快速下载镜像、访问 MMIO、读取大片内存 | SoC 调试 |
| P2 | 多 hart 选择、<code>hasel</code>、hart reset、halt group、trigger | SMP 调试、断点和观察点 | 多核或复杂软件 |
| P3 | 认证、调试禁用、调试事件审计、低功耗唤醒策略 | 量产安全与平台管理 | 产品化芯片 |

<code>progbufsize=4</code> 能覆盖一部分简单操作，但余量很小。OpenOCD 在访问内存时还可能插入 <code>fence</code>，硬件地址转换场景也会占用额外指令。因此，执行式方案建议从 <code>progbufsize=8</code> 起步；资源允许时选择 16 个字，可减少工具侧退化和后续扩展限制。

### 1.2 常用设计方案

| 方案 | 核心配置 | 内存访问方式 | 适合的目标 | 主要限制 |
| --- | --- | --- | --- | --- |
| E1：极简执行式 DM | 单 hart、<code>data=2</code>、<code>progbuf=4</code>、无 SBA、无 Abstract Memory Command | 仅通过已暂停 hart 执行 load/store | 裸机 RV32、早期 FPGA、功能验证 | 调试速度低；复杂操作可能受 4 字限制 |
| E2：均衡执行式 DM | 单 hart、<code>data=2</code>、<code>progbuf=8</code>、无 SBA | Program Buffer；可选 Abstract Memory Command | 小型 SoC 与软件联调 | 下载镜像仍慢；不能直接由 DM 访问物理地址 |
| E3：SoC 调试 DM | <code>progbuf=8/16</code>、SBA AXI 主设备、总线错误上报 | Program Buffer 与 SBA | RAM/Flash 下载、MMIO 与系统软件调试 | 需要 AXI 仲裁、权限和 cache 维护策略 |
| E4：直接寄存器访问 DM | 专用 GPR/CSR 调试端口、SBA、较小或无 Program Buffer | 专用寄存器端口与 SBA | 高性能 CPU、缩短寄存器访问延迟 | CPU 内部仲裁复杂；必须完整处理提交、异常和单步 |

E1 是“能用”的最小方案，E2 是较稳妥的首次 OpenOCD 接入方案，E3 是大多数可下载固件的 SoC 的推荐方案。E4 并不天然更容易：它减少了 Program Buffer 指令，却把复杂度放进寄存器堆、CSR 和流水线控制。

## 2. 系统组成与地址空间

### 2.1 从 GDB 到 hart 的数据路径

~~~text
GDB
 │  Remote Serial Protocol
 ▼
OpenOCD
 │  JTAG 扫描事务
 ▼
JTAG 适配器 ── TCK / TMS / TDI / TDO ──► DTM
                                           │ DMI 请求与响应
                                           ▼
                                          DM
                         ┌─────────────────┼─────────────────┐
                         │                 │                 │
                         ▼                 ▼                 ▼
                  hart 调试控制       Debug Memory          SBA
                  halt/resume         ROM / Data /          AXI 主设备
                         │             Program Buffer         │
                         ▼                 │                 ▼
                        hart ◄─────────────┘            AXI 从设备
                                                          RAM / Flash / MMIO
~~~

- JTAG 只规定 TAP（Test Access Port，测试访问端口）的扫描行为；它不规定 DM 寄存器。
- DTM（Debug Transport Module，调试传输模块）将 JTAG 扫描数据转换为 DMI（Debug Module Interface，调试模块接口）读写请求。
- DMI 的一个地址指向一个 32 位调试寄存器。DMI 地址不是 CPU 的指令地址，也不是 AXI 地址。
- Debug Memory 是 hart 在 Debug Mode 中看到的一段专用存储空间，通常包括 Debug ROM、控制状态寄存器、Program Buffer 和抽象数据区。
- SBA 发出的地址是系统总线物理地址，通常用于 RAM、Flash 和 MMIO。

### 2.2 三类地址必须分开理解

| 地址类别 | 示例 | 谁使用它 | 作用 |
| --- | --- | --- | --- |
| DMI 寄存器地址 | <code>0x10</code> 为 <code>dmcontrol</code>，<code>0x20</code> 为 <code>progbuf0</code> | DTM、OpenOCD、DM | 管理调试模块本身 |
| hart 调试存储地址 | <code>DEBUG_BASE + 0x800</code> 的 Debug ROM，<code>DEBUG_BASE + 0x380</code> 的 <code>data0</code> | Debug Mode 中的 hart | 执行暂停程序、交换数据、取 Program Buffer 指令 |
| 系统总线物理地址 | <code>0x8000_0000</code> 的 RAM 或 MMIO | SBA 或 hart 的 LSU | 访问 SoC 内存与外设 |

同一份 Program Buffer 存储内容可以同时被 DMI 写入，也可在 Debug Mode 下被 hart 取指；两者使用的地址类别不同。调试器通过标准 DMI 寄存器写入指令，具体的 hart 取指位置由硬件决定，不能要求 OpenOCD 知道某个固定的 AXI 地址。

### 2.3 建议的顶层接口

下表是单 hart 执行式 DM 的关键接口。命名仅作说明，项目可以使用自身端口名，但行为应保持一致。

| 信号 | 方向 | 位宽 | 功能 | 有效条件 | 暂停、错误与复位行为 |
| --- | --- | ---: | --- | --- | --- |
| <code>debug_req_o</code> | 模块输出 | 1 | 请求 hart 进入 Debug Mode | 选中 hart 且 <code>haltreq</code> 为 1，或单步完成后需要再次暂停 | <code>dmactive=0</code> 时清零；请求应保持到 hart 确认暂停 |
| <code>hart_halted_i</code> | 模块输入 | 1 | 指示 hart 已停在 Debug Mode 暂停程序中 | hart 已完成调试入口处理 | 复位或不可用时为 0；用于更新 <code>dmstatus</code> |
| <code>resume_req_o</code> | 模块输出 | 1 | 请求 hart 离开 Debug Mode 并恢复普通执行 | 对已暂停 hart 写入 <code>resumereq</code> | 由 DM 保持到 hart 的恢复确认到达 |
| <code>hart_resuming_i</code> | 模块输入 | 1 | 指示 hart 已接受恢复请求 | hart 从 Debug ROM 的恢复入口执行 | 用于清除恢复请求并更新状态 |
| <code>hart_unavailable_i</code> | 模块输入 | 1 | 指示 hart 因复位、掉电或时钟关闭而不能调试 | 平台控制逻辑给出 | 为 1 时抽象命令返回 halt/resume 错误 |
| <code>debug_rom_addr_o</code> | 模块输出 | <code>XLEN</code> | 提供调试存储窗口的访问地址 | hart 在 Debug Mode 发起取指或读写 | 非 Debug Mode 访问应拒绝或返回总线错误 |
| <code>debug_rom_rdata_i</code> | 模块输入 | <code>XLEN</code> | 返回 Debug ROM、Data、Program Buffer 或状态寄存器数据 | 读事务完成 | 不支持的地址应有确定返回值或确定错误响应 |
| <code>sba_axi_*</code> | 模块输出/输入 | 依 AXI 配置 | SBA 的 AXI 主设备接口 | <code>sbaddress</code>/<code>sbdata</code> 启动访问 | 总线错误必须写入 <code>sberror</code>；复位取消未完成事务 |

多 hart 设计只需将前三类 hart 信号扩展成数组，并使 <code>hartsel</code>/<code>hasel</code> 选择生效对象。不要把 DMI 地址直接译成某个 hart 的编号或 CPU 地址。

## 3. 软硬件分工

调试器能决定“做什么”，但不能决定 CPU 的时序细节和 Debug ROM 的地址。DM 硬件必须把标准寄存器行为转换成可重复的控制动作。

| 事项 | OpenOCD / GDB 负责 | DTM / DM 硬件负责 | hart / SoC 硬件负责 |
| --- | --- | --- | --- |
| JTAG 扫描 | 生成 TAP 状态转换与 IR/DR 扫描 | 解释 DTMCS、DMIACCESS 和 DMI 返回状态 | 提供 TCK 时钟域以外的系统时钟 |
| DM 探测 | 读 <code>dmstatus</code>、<code>hartinfo</code>、<code>abstractcs</code> | 返回实现能力、地址位数和错误码 | 给出可用、暂停、复位状态 |
| 暂停与恢复 | 写 <code>dmcontrol</code> 的 <code>haltreq</code>/<code>resumereq</code> | 维持请求、等待确认、更新 <code>dmstatus</code> | 在合法指令提交点进入 Debug Mode；保存 <code>dpc</code>、设置 <code>dcsr</code> |
| 寄存器访问 | 发出 Access Register 抽象命令；读取或写入 <code>data</code> | 检查 <code>busy</code> 与 <code>cmderr</code>，启动执行 | 直接提供寄存器端口，或执行 Program Buffer 指令 |
| Program Buffer | 写入指令字、发出 <code>postexec</code> | 保存指令、使暂停程序转入执行入口 | 从调试存储取指，完成后以 <code>ebreak</code> 返回暂停程序 |
| 内存访问 | 选择 <code>progbuf</code>、<code>sysbus</code> 或 <code>abstract</code> 方法 | 实现 SBA 控制寄存器或准备 Program Buffer 操作 | hart 的 LSU 访问内存；SoC 对 SBA 提供 AXI 仲裁与从设备响应 |
| 调试存储保护 | 无 | 可提供访问许可控制 | 普通软件不能把 Debug ROM、Data 与 Program Buffer 当成一般 RAM 使用 |

> [!warning]
> 不能把“OpenOCD 会写 <code>progbuf0</code>”误解为“OpenOCD 会替硬件解决取指”。Program Buffer 如何被 hart 取到、<code>ebreak</code> 如何回到暂停程序、异常如何回报，全部属于 CPU、Debug ROM 和 DM 的职责。

## 4. 推荐的硬件组织

### 4.1 DTM：JTAG 与 DMI

JTAG DTM 至少需要实现以下内容：

1. IEEE 1149.1 TAP 状态机与 Instruction Register。
2. <code>IDCODE</code>、<code>DTMCS</code> 和 <code>DMIACCESS</code> 指令。
3. DMI 请求寄存器、响应寄存器和 <code>busy</code>/<code>failed</code> 状态。
4. TCK 时钟域与系统时钟域之间的可靠请求、响应传递。

<code>DMIACCESS</code> 的扫描数据由地址、32 位数据和 2 位操作码组成。读请求的结果常在随后的扫描事务中返回，因此 DTM 必须明确保存“上一笔请求的响应”。当系统侧尚未完成请求时，DTM 返回 <code>busy</code>；请求失败时返回 <code>failed</code>。调试器会依据 <code>DTMCS.idle</code> 插入 Run-Test/Idle 周期，设计不能假定每个 DMI 请求都在一个 TCK 周期内完成。

建议采用“一笔未完成请求”的 DTM 起步：

~~~text
TCK 域：DMIACCESS Update-DR
        ├─ 若无未完成请求：锁存地址、数据、op；发送请求
        └─ 若已有未完成请求：返回 busy

系统时钟域：接收请求
        ├─ 访问 DM 寄存器或启动执行器
        └─ 产生 rdata / success / failed

TCK 域：下次 Capture-DR / Shift-DR
        └─ 返回上一笔响应
~~~

对于异步 TCK，单比特握手可使用双触发器同步与请求翻转位；多位地址和数据应在源域保持稳定到接收确认，或使用异步 FIFO。只对状态位做同步、却让多位数据直接跨时钟域，会产生难以复现的错误。

### 4.2 DM 寄存器与命令执行器

P0 实现应优先完成下列标准寄存器：

|              DMI 地址 | 寄存器                       | RTL 要点                                                                                                                  |
| ------------------: | ------------------------- | ----------------------------------------------------------------------------------------------------------------------- |
| <code>0x04</code> 起 | <code>data0...</code>     | 至少实现 <code>data0</code>；建议 RV32 实现两个 32 位字，便于 64 位数据与临时保存                                                               |
|   <code>0x10</code> | <code>dmcontrol</code>    | <code>dmactive</code>、hart 选择、<code>haltreq</code>、<code>resumereq</code>、<code>ackhavereset</code> 必须有确定行为             |
|   <code>0x11</code> | <code>dmstatus</code>     | 正确反映选中 hart 的 <code>all/anyrunning</code>、<code>all/anyhalted</code>、<code>all/anyunavail</code>、<code>havereset</code> |
|   <code>0x12</code> | <code>hartinfo</code>     | 报告 <code>dataaccess</code>、<code>datasize</code>、<code>dataaddr</code> 与 <code>nscratch</code>                          |
|   <code>0x16</code> | <code>abstractcs</code>   | 报告 <code>datacount</code>、<code>progbufsize</code>、<code>busy</code>；<code>cmderr</code> 采用写 1 清除                       |
|   <code>0x17</code> | <code>command</code>      | 支持 Access Register；不支持的 commandtype 或尺寸返回 not supported                                                                 |
|   <code>0x18</code> | <code>abstractauto</code> | P0 可以先把自动执行位固定为 0；P1 再实现                                                                                                |
| <code>0x20</code> 起 | <code>progbuf0...</code>  | 写入可执行指令字；读取能力按实现报告                                                                                                      |

命令执行器需要将两个不同的忙状态分开：

- <code>DTM busy</code>：上一笔 DMI 事务尚未完成。
- <code>abstractcs.busy</code>：DM 已接受抽象命令，正在等待 hart 执行或等待总线访问结束。

抽象命令执行期间，向 <code>command</code>、<code>data</code>、<code>progbuf</code> 或 <code>abstractauto</code> 的不合规访问必须按规范处理，通常写入 <code>cmderr=busy</code>。完成时要么清除 <code>busy</code>，要么先记录异常、总线错误或 halt/resume 错误，再让调试器读取并清除 <code>cmderr</code>。

### 4.3 运行控制状态机

建议在 DM 内部使用显式状态机，而不是仅依靠几个寄存器位推测当前状态。

~~~text
RUNNING
  │ haltreq
  ▼
HALT_REQUESTED ── hart_unavailable ──► UNAVAILABLE
  │ hart_halted
  ▼
HALTED
  │ 抽象命令 / postexec
  ▼
EXECUTING
  │ done                 │ exception
  └────────► HALTED ◄────┘
  │ resumereq
  ▼
RESUME_REQUESTED
  │ hart_resuming
  ▼
RUNNING
~~~

实现要点如下。

- <code>haltreq</code> 是电平请求，不应只脉冲一个系统周期。hart 可能因为流水线清空、总线等待或低功耗唤醒而稍后才确认。
- <code>resumereq</code> 只作用于已暂停 hart。hart 从恢复入口写出确认后，DM 再撤销该请求。
- <code>dmstatus</code> 应由 hart 的真实状态反馈产生，不应以“DM 已发请求”代替“hart 已暂停”。
- <code>dmactive=0</code> 是 DM 的初始化条件。它应清除内部命令状态、请求状态和粘滞错误；不要把它当作 SoC 全局复位。
- <code>ndmreset</code> 可以复位 hart 和平台大部分逻辑，但 DM、DTM 与必要调试访问逻辑必须仍能工作。复位期间只保证规范明确允许的少数 DMI 访问。

### 4.4 hart 需要提供的 Debug Mode 行为

CPU 并非在收到 <code>debug_req</code> 的瞬间任意截断执行。它应在实现定义的、符合 RISC-V Debug 规范的安全位置进入 Debug Mode。典型处理包括：

1. 停止普通取指与提交，处理已开始且必须完成的总线事务。
2. 将恢复地址写入 <code>dpc</code>，并在 <code>dcsr.cause</code> 中记录进入原因。
3. 设置 Debug Mode 状态，禁止普通异常返回路径把调试状态破坏。
4. 将 PC 指向调试入口地址，执行 Debug ROM。
5. Debug ROM 在暂停循环中通知 DM “hart 已暂停”，并读取后续动作。

hart 还需要区分普通程序的 <code>ebreak</code> 与调试程序的 <code>ebreak</code>。后者通常表示 Program Buffer 或抽象程序已结束，应返回 Debug ROM 的暂停循环；若调试执行发生其他异常，则应通知 DM 并使 <code>cmderr</code> 记录 exception。

### 4.5 Debug ROM 与 Debug Memory

Debug ROM 的指令内容和所在地址是硬件设计的一部分，不是 OpenOCD 配置项。一个便于实现的 Debug Memory 可以按下列相对偏移组织：

| 相对偏移 | 内容 | 访问者 | 说明 |
| ---: | --- | --- | --- |
| <code>0x100</code> | Halted 确认寄存器 | hart 写 | 通知 DM 已进入暂停循环 |
| <code>0x108</code> | Going 确认寄存器 | hart 写 | 通知 DM 将执行抽象程序或 Program Buffer |
| <code>0x110</code> | Resuming 确认寄存器 | hart 写 | 通知 DM 即将恢复普通执行 |
| <code>0x118</code> | Exception 确认寄存器 | hart 写 | 通知 DM 调试执行发生异常 |
| <code>0x300</code> | WhereTo 控制字 | hart 读、DM 写 | 指出暂停循环下一步应转向的入口 |
| <code>0x338</code> 起 | Abstract Program | hart 取指、DM 组织 | 存放 DM 自动生成的寄存器传输指令 |
| <code>0x360</code> 起 | Program Buffer | hart 取指、DMI 写 | 存放调试器给出的短程序 |
| <code>0x380</code> 起 | Data 区 | hart 与 DMI | 传递抽象命令结果 |
| <code>0x400</code> 起 | Flags | hart 读、DM 写 | 每个 hart 的暂停、恢复和执行标志 |
| <code>0x800</code> 起 | Debug ROM | hart 取指 | 调试入口、恢复入口、异常入口和暂停循环 |

这是 PULP <code>riscv-dbg</code> 使用的一种布局，其偏移可作为很好的起点，但 SoC 的 <code>DEBUG_BASE</code> 不必相同。普通软件访问这段区域应被阻止，至少不得允许普通程序执行 Program Buffer 或伪造确认写入。

一个最小暂停循环可表达为：

~~~text
halt_entry:
    写 Halted 确认

park_loop:
    读取本 hart 的 Flags 或 WhereTo
    若请求执行抽象程序：跳入 Abstract Program
    若请求执行 Program Buffer：跳入 Program Buffer
    若请求恢复：跳入 resume_entry
    否则继续 park_loop

resume_entry:
    写 Resuming 确认
    离开 Debug Mode，从 dpc 恢复

exception_entry:
    写 Exception 确认
    回到 park_loop
~~~

### 4.6 Program Buffer 的实现选择

Program Buffer 是调试器可写、hart 可执行的小型指令存储。它至少需要有以下保证：

- 命令执行前，DM 已写完全部指令字。
- hart 执行期间，不接受会改写正在执行内容的 DMI 写操作。
- 末尾有确定终止方式：调试器显式写入 <code>ebreak</code>，或 <code>impebreak=1</code> 时由硬件在末尾提供隐含 <code>ebreak</code>。
- 程序访问 Data 区的地址与 <code>hartinfo.dataaddr</code> 一致。
- 异常、非法指令和访问错误能够回到 DM 的错误记录路径。

常见实现有三种。

| 方式 | 做法 | 优点 | 代价与限制 |
| --- | --- | --- | --- |
| 调试存储取指 | 将 Program Buffer 作为 Debug Memory 的 RAM；hart 在 Debug Mode 通过正常取指接口读取 | 结构直观，适合通用 CPU；便于执行多条指令 | 需给取指端和总线提供调试存储窗口 |
| 调试指令注入 | DM 将少量指令直接送入暂停 CPU 的取指或译码入口 | 占用存储少，<code>progbufsize=1</code> 也可有用 | CPU 修改较多；长程序和异常处理更难 |
| Debug ROM 间接执行 | ROM 根据控制字跳转到 Program Buffer 或自动生成的指令区 | 与暂停循环衔接清晰；适合执行式设计 | 需要 Debug ROM、Flags 与确认寄存器配合 |

对于首次实现，建议选择“调试存储取指 + Debug ROM 间接执行”。它最接近 PULP 和 Rocket Chip 的公开设计思路，问题定位也更直接。

### 4.7 Program Buffer 的物理实现对照

“Program Buffer 有几个 DMI 寄存器”与“hart 怎样取到这些指令”是两个独立问题。前者由 <code>progbuf0...</code> 的标准寄存器行为规定；后者可按 CPU 结构选择。只要调试器写入的指令能按顺序执行、终止后回到暂停循环，OpenOCD 不需要知道内部做法。

| 方案 | hart 的取指方式 | Program Buffer 与 Data 区 | 对 CPU 的改动 | 特别要处理的事项 |
| --- | --- | --- | --- | --- |
| 调试存储窗口 | hart 的 PC 指向 Debug Memory，常规取指端经地址译码读出 ROM 或 Program Buffer | 两者处在同一片可寻址调试存储中 | 较小；增加调试存储从设备和 Debug Mode 访问许可 | ICache 旁路或失效、地址对齐、正常软件访问禁止 |
| IF 选择器 | <code>debug_mode</code> 且 PC 落在 Program Buffer 范围时，IF 直接从 <code>progbuf[]</code> 选择指令 | Data 区仍需要单独的 hart 可访问窗口 | 中等；IF 需要多路选择与地址计算 | 取指流水清空、压缩指令半字位置、异常 PC、末尾 <code>ebreak</code> |
| 调试指令注入 | DM/调试控制器把指令逐条送入取指或译码入口，不依赖连续指令地址 | Data 区可用专用数据端口或较小调试窗口 | 较大；调试逻辑深入 CPU 流水线 | 指令提交确认、异常恢复、单步、与普通取指仲裁 |
| 独立微程序执行器 | DM 自己执行固定的寄存器搬运和访存微操作 | Program Buffer 可只服务调试器自定义短程序 | 最大；需要复制部分寄存器与 LSU 功能 | 很难完整复现 RISC-V 指令、地址转换和异常行为 |

第一种方案最通用：Debug ROM、Abstract Program、Program Buffer 和 Data 区都由一段 Debug Memory 提供，hart 在 Debug Mode 下像读取普通存储一样读取它。第二种方案可省去对系统总线的调试存储读访问，但仍必须为 Data 区提供 hart 可访问的位置，或另行增加数据交换端口。第三种方案适用于极小 CPU，却最容易在异常、压缩指令和流水线停顿处出现与普通执行不一致的行为。

> [!tip]
> 对 OpenOCD 而言，Program Buffer 是 DMI 中的标准接口，不是某个固定地址。即使采用 IF 选择器或直接指令注入，也应如实报告 <code>progbufsize</code>、<code>impebreak</code> 和 <code>hartinfo.dataaddr</code>，并保证 <code>postexec</code> 的可观察结果与规范一致。

### 4.8 抽象寄存器访问

Access Register 抽象命令是 OpenOCD 读写 GPR、CSR、<code>dcsr</code> 等寄存器的主要入口。实现有两条路线。

| 路线 | DM 行为 | hart 修改 | 适用情况 |
| --- | --- | --- | --- |
| 直接访问 | DM 通过专用寄存器读写端口访问 GPR/CSR | 需给寄存器堆、CSR 单元增加调试端口与仲裁 | 高性能 CPU，或需要最短调试延迟 |
| 执行式访问 | DM 生成保存、读写和恢复寄存器的指令；由 hart 执行 | 只需 Debug Mode、Debug ROM 与调试存储取指 | 大多数开源 CPU 与首次 RTL 设计 |

执行式访问的典型读 GPR 过程是：

1. OpenOCD 选择 hart，确认 <code>dmstatus.allhalted=1</code>。
2. OpenOCD 清除旧 <code>cmderr</code>，向 <code>command</code> 写入 Access Register 命令。
3. DM 将命令翻译为调试指令，例如把目标 GPR 写入 Data 区。
4. DM 置 <code>abstractcs.busy</code>，使暂停循环进入 Abstract Program。
5. hart 完成指令并写出 Going/Halted 或 Exception 确认。
6. DM 清除 <code>busy</code>；OpenOCD 读取 <code>data0</code> 得到结果。

此过程中的寄存器保存必须明确设计。若自动生成的程序借用 <code>s0</code>、<code>s1</code> 或 <code>t0</code>，它必须在返回暂停循环前恢复这些寄存器，除非该寄存器正是命令指定的写入对象。否则一次“读内存”会暗中修改被调试程序状态。

## 5. 内存访问设计

### 5.1 没有 SBA 时：Program Buffer 访问

没有 SBA 并不等于不能访问内存。DM 可以让已暂停 hart 在 Debug Mode 中执行 load/store 指令，再通过 Data 区与调试器交换结果。

下面是读取一个 32 位字的示意程序，不表示某个 OpenOCD 版本的精确指令序列：

~~~assembly
# 前提：地址已写入 Data 区，并经抽象命令送入 s0。
# 前提：调试程序会保存并恢复实际借用的寄存器。
lw   s1, 0(s0)                  # 从目标地址读取
sw   s1, DATA_ADDR(x0)          # 写回 hart 可访问的 Data 区
ebreak                          # 返回暂停循环
~~~

其数据流为：

~~~text
目标内存 ── hart 的 lw ──► s1 ── hart 的 sw ──► Data 区
                                                   │
                                              DMI 读取 data0
                                                   ▼
                                                OpenOCD
~~~

这种方式有三个重要限制。

1. hart 必须先暂停，访问会改变 CPU 的执行现场，因此保存和恢复寄存器不可省略。
2. 访问经过 hart 的 LSU、地址转换与权限检查。调试器看到的地址效果可能与 SBA 不同。
3. 若 ICache、DCache 或外部 DMA 存在未完成数据，读取结果取决于 SoC 的一致性设计。OpenOCD 默认会在 Program Buffer 读写前后执行必要的 <code>fence</code>；硬件应保证这些指令在 Debug Mode 可正常完成。

### 5.2 极简配置：4 字 Program Buffer、无 SBA、无抽象访存

这是资源最少、但仍可做基本 GDB/OpenOCD 调试的一种执行式方案。其“无抽象访存”是指不实现 Abstract Memory Command；它<strong>不等于</strong>不实现 Access Register。后者仍是把地址、数据和暂存 GPR 在调试器与 hart 之间交换的必要手段。

| 项目 | 极简配置 | 设计理由 |
| --- | --- | --- |
| hart 数量 | 1 | 不实现 <code>hasel</code>、halt group 和 hart array window |
| <code>datacount</code> | 2 | 用于地址、读回数据及临时保存 |
| <code>progbufsize</code> | 4 | 每次放入一段很短的 load/store 程序 |
| <code>impebreak</code> | 建议为 1 | 可省去显式终止指令占用 |
| Access Register | 支持 GPR 和必要 CSR | 用于准备地址、交换数据、保存和恢复暂存寄存器 |
| Abstract Memory Command | 不支持 | 读到该命令时置 <code>cmderr=not supported</code> |
| SBA | 不支持 | <code>sbcs</code> 只报告实际能力；不启动 AXI 主设备 |
| <code>hartinfo.dataaccess</code> | 1 | 让调试指令通过 <code>dataaddr</code> 读写 Data 区 |
| Debug Memory | ROM + Data + Program Buffer | 提供暂停循环和 hart 指令取数位置 |

4 字 Program Buffer 的一笔读操作可以只包含以下三条指令：

~~~assembly
lw   s1, 0(s0)                  # s0 保存目标地址
sw   s1, DATA_ADDR(x0)          # Data 区由 hartinfo.dataaddr 给出
ebreak                          # 或由 impebreak 隐含提供
~~~

写操作相应为：

~~~assembly
lw   s1, DATA_ADDR(x0)          # 取调试器预先写入的待写数据
sw   s1, 0(s0)                  # 写入目标地址
ebreak
~~~

这里的 <code>s0</code> 与 <code>s1</code> 只是示例。DM 可以用独立的 Abstract Program 保存和恢复它们，再通过 Access Register 将地址送入 <code>s0</code>、将数据从 <code>s1</code> 取回。也可以让 CPU 提供直接 GPR 调试端口，减少这部分自动生成的指令。不能为了凑进 4 个字而省略现场恢复。

极简配置的完整读流程如下：

1. OpenOCD 使 hart 暂停。
2. Access Register 将 <code>s0</code>、<code>s1</code> 的旧值保存到 Data 区。
3. Access Register 把目标地址送入 <code>s0</code>。
4. DM 通过 DMI 写入上述 3 条 Program Buffer 指令，并用 <code>postexec</code> 触发。
5. hart 将读取结果写入 Data 区，以 <code>ebreak</code> 回到暂停循环。
6. OpenOCD 读取 <code>data0</code>，DM 再恢复 <code>s0</code> 与 <code>s1</code>。

这个方案的能力下限应明确写入板级 OpenOCD 配置：

~~~tcl
# 目标没有 SBA，也不支持 Abstract Memory Command。
# 所有内存访问都由已暂停 hart 执行 Program Buffer 完成。
riscv set_mem_access progbuf
~~~

OpenOCD 手册中的 <code>abstract</code> 内存访问方法，指的是 Abstract Memory Command；它与用于 GPR/CSR 传输的 Access Register 抽象命令不同。若只禁用前者，却保留后者，极简方案仍能完成标准寄存器访问和基于指令的内存访问。

极简方案适合裸机 RV32、片内 RAM 和早期 FPGA 调试，但有明显限制：

- 下载大片镜像较慢，因为每次内存读写都要经过暂停 hart 和 DMI。
- 无法在 hart 运行时用 DM 直接读写系统物理地址。
- MMIO 读取可能带副作用，且访问权限、地址转换和 cache 行为完全取决于 hart 的调试执行环境。
- 4 个字不足以覆盖某些带地址转换、额外 <code>fence</code> 或复杂保存恢复的工具操作；遇到此类情况应升级到 8 或 16 个字，而不是报告虚假的 <code>progbufsize</code>。

### 5.3 SBA：作为独立 AXI 主设备

SBA 应被设计为 DM 的 AXI 主设备，而不是 AXI 从设备。它由 <code>sbcs</code>、<code>sbaddress0...</code>、<code>sbdata0...</code> 等 DMI 寄存器驱动，发出标准的 AXI 读写事务。

P1 的稳妥方案是：

- 只支持一个未完成的 SBA 事务。
- 先支持 32 位访问，并只把 <code>sbaccess32</code> 报告为 1；字节与半字能力完成后再置 <code>sbaccess8</code>/<code>sbaccess16</code>。
- 读地址或读数据时按 <code>sbreadonaddr</code>/<code>sbreadondata</code> 启动读取。
- 写 <code>sbdata0</code> 时启动写入。
- <code>sbautoincrement</code> 按本次访问字节数递增地址。
- AXI <code>DECERR</code>、<code>SLVERR</code>、超时或非对齐请求必须记录在 <code>sberror</code>，并按规定写 1 清除。

~~~text
OpenOCD
  │ DMI 写 sbaddress0 / sbdata0
  ▼
SBA 控制寄存器 ──► SBA 事务状态机 ──► AXI AW/W/B 或 AR/R
  ▲                                           │
  └────────── sbdata0、sbbusy、sberror ◄──────┘
~~~

调试存储窗口则相反：它通常是 SoC 总线的从设备，供 Debug Mode 下的 hart 读取 ROM、Data 和 Program Buffer。一个 DM 可以同时包含“Debug Memory 的从设备接口”和“SBA 的主设备接口”；两者功能完全不同，不能合并处理。

### 5.4 选择 Program Buffer 还是 SBA

| 比较项 | Program Buffer | SBA |
| --- | --- | --- |
| 是否要求 hart 暂停 | 是 | 规范允许在 hart 运行时访问，但结果受系统一致性影响 |
| 访问执行者 | hart 的 LSU | DM 内的总线主设备 |
| 可见的地址与权限 | 接近 hart 当前调试执行环境 | 系统总线物理地址与 SoC 访问许可 |
| 适合的用途 | GPR/CSR 相关访问、无 SBA 的基本内存读写 | 下载程序、大片内存、MMIO、启动前内存初始化 |
| 硬件成本 | Debug ROM、Program Buffer、少量控制 | 额外 AXI 主设备、错误处理与仲裁 |

OpenOCD 的 <code>riscv set_mem_access</code> 可指定 <code>progbuf</code>、<code>sysbus</code>、<code>abstract</code> 的优先顺序，默认顺序为 <code>progbuf sysbus abstract</code>。这意味着即使实现 SBA，也不能因此省略一个健壮的 Program Buffer；相反，应在调试脚本中明确选择最适合平台的顺序。

## 6. 与 OpenOCD 协同工作的必要条件

### 6.1 探测、暂停和寄存器访问

OpenOCD 会先扫描 JTAG，读取 DTMCS 和 DMI，再通过 <code>dmstatus</code> 识别 DM 版本与 hart 状态。下列行为必须稳定：

| 检查项目 | DM 的正确行为 | 常见错误现象 |
| --- | --- | --- |
| DTMCS 的 <code>abits</code> 与 <code>idle</code> | 与实际 DMI 地址宽度和所需空闲周期一致 | DMI 地址错位、偶发 <code>busy</code> |
| DMI 响应时序 | 返回上一笔请求的响应；未完成时返回 <code>busy</code> | 读寄存器总是得到前一次的错误数据 |
| <code>dmactive</code> | 写 1 后 DM 可用；写 0 后内部状态回到初始化状态 | 首次连接成功，复位后无法再次连接 |
| <code>dmstatus</code> | 反映真实 hart 状态，不可用 hart 要置相应位 | OpenOCD 永久等待 halt 或 resume |
| <code>abstractcs.busy</code> | 命令期间为 1，结束后为 0 | OpenOCD 超时或命令重叠 |
| <code>cmderr</code> | 粘滞记录，写 1 清除 | 发生一次错误后所有后续命令失败 |
| <code>progbufsize</code>/<code>impebreak</code> | 只报告实际支持能力 | 调试器写越界指令或 Program Buffer 不返回 |

建议先让 OpenOCD 的低层命令可用，再启动 GDB：

~~~tcl
# 适配器类型、JTAG 引脚与时钟频率依板级设计填写。
adapter speed 1000
transport select jtag

jtag newtap riscv cpu -irlen 5 -expected-id 0x00000001
target create riscv.cpu riscv -chain-position riscv.cpu

# P0 阶段优先验证 Program Buffer；SBA 完成后可加入 sysbus。
riscv set_mem_access progbuf sysbus abstract

init
halt
riscv info
~~~

<code>-expected-id</code> 是示例值，量产设计应填写实际 JTAG IDCODE。首次上板建议使用较低 TCK 频率；待跨时钟域、DMI 空闲周期和复位行为均通过验证后再提高频率。

### 6.2 用 OpenOCD 区分硬件问题

~~~text
OpenOCD -d3 -f board.cfg

riscv dmi_read 0x11          # dmstatus
riscv dmi_read 0x16          # abstractcs
riscv dmi_write 0x10 0x00000001
halt
reg
mdw 0x80000000 4
~~~

可按以下顺序缩小问题范围：

1. <code>idcode</code> 读取失败：先检查 JTAG 引脚、TAP 状态机、IR 长度和采样边沿。
2. DTMCS 正常但 DMI 总是 <code>busy</code>：检查 TCK 与系统时钟域握手、<code>idle</code> 周期和 DMI 请求确认。
3. 能读 <code>dmstatus</code> 但 <code>halt</code> 超时：检查 <code>debug_req_o</code> 是否持续、hart 是否真的进入 Debug Mode、Halted 确认是否到达 DM。
4. <code>reg</code> 失败且 <code>cmderr=2</code>：Access Register 的命令类型、寄存器编号或尺寸未实现。
5. <code>reg</code> 失败且 <code>cmderr=3</code>：检查 Debug ROM、Abstract Program、Data 区地址和调试执行中的异常入口。
6. <code>mdw</code> 失败而 <code>reg</code> 正常：分别用 <code>riscv set_mem_access progbuf</code> 与 <code>riscv set_mem_access sysbus</code> 测试，以区分 Program Buffer、SBA 和 SoC AXI 问题。

### 6.3 单步、断点和 cache

单步主要由 hart 的 <code>dcsr.step</code> 和 Debug Mode 进入逻辑完成，DM 不应只通过“执行一条 Program Buffer 指令”冒充普通程序单步。普通程序的硬件断点和观察点由 trigger CSR 及 hart 比较逻辑完成；若暂不支持，应明确报告对应 trigger 不存在，而不是返回看似成功的无效配置。

经 Program Buffer 修改代码后，应确保 ICache 可观察到新指令；经 SBA 修改内存时，也要考虑 DCache、DMA 和外设写缓冲。调试模块不能凭空保证整个 SoC 的数据一致性。应由调试脚本、Debug ROM 可执行的 <code>fence</code>/<code>fence.i</code>，以及 SoC 的 cache 维护机制共同处理。

## 7. 一个可落地的 RV32 单 hart方案

### 7.1 参数建议

| 参数 | 建议值 | 原因 |
| --- | --- | --- |
| <code>XLEN</code> | 32 | 适合典型 MCU 与小型 SoC |
| DMI 地址宽度 | 7 位 | 覆盖标准 DM 寄存器和常用扩展空间 |
| <code>datacount</code> | 2 | 足以处理 RV32 常用数据交换，也为双字结果留出空间 |
| <code>progbufsize</code> | 8 | 可容纳保存、访存、恢复、<code>fence</code> 与 <code>ebreak</code> |
| <code>impebreak</code> | 1 | 减少调试器对末尾终止指令的占用 |
| <code>dataaccess</code> | 1 | 允许 Debug Mode 中的程序直接访问 Data 区 |
| <code>datasize</code> | 2（4 字节） | 与 RV32 Data 字一致 |
| SBA | 第一阶段关闭，第二阶段打开 | 先缩小 CPU 与 Debug ROM 调试范围，再处理 AXI 主设备 |
| 最大 SBA 访问 | 32 位起步 | 最容易完成对齐、选通与错误处理 |

### 7.2 推荐模块划分

~~~text
dm_top
├── dmi_jtag_tap        JTAG TAP、IR、DR 扫描
├── dmi_cdc             TCK 与系统时钟域的请求/响应传递
├── dm_csrs             DMI 寄存器、hart 选择、状态汇总
├── abstract_engine     Access Register 命令、busy、cmderr
├── run_control         halt/resume 与 hart 确认状态机
├── debug_mem           ROM、Data、Program Buffer、确认寄存器
├── debug_rom           暂停、恢复、异常和执行入口指令
└── sba_axi_master      可选 AXI 主设备
~~~

其中 <code>dm_csrs</code> 只负责寄存器读写和状态保存；不要把跨时钟域、AXI 事务、Debug ROM 跳转和抽象命令全部塞入同一个过程。模块分开后，DMI 级验证、hart 接口验证和 SBA 验证可以独立进行。

### 7.3 首条 Program Buffer 读写流程

在 SBA 尚未实现时，可用下面的流程验证 Program Buffer：

1. 让 hart 运行一段已知程序，确认普通 UART 或 RAM 行为正常。
2. OpenOCD 发送 <code>halt</code>，检查 <code>dmstatus.allhalted</code>。
3. 用 Access Register 写入一个已知 GPR，再读回比较。
4. 将目标 RAM 地址送入临时 GPR。
5. 写入“load + 写 Data 区 + <code>ebreak</code>”的 Program Buffer。
6. 以 <code>postexec=1</code> 触发程序，轮询 <code>abstractcs.busy</code>。
7. 从 <code>data0</code> 读回结果，与仿真 RAM 内容比较。
8. 写入“从 Data 区取值 + store + <code>ebreak</code>”并复测。
9. 恢复 hart，确认被借用的 GPR、<code>dpc</code> 与普通程序结果均未改变。

最后一项比“读到正确数据”更重要。若调试操作破坏了暂停前的寄存器，GDB 的一次内存查看就可能让程序恢复后崩溃。

## 8. 开源实现对照

### 8.1 PULP <code>riscv-dbg</code>

PULP 的 <code>riscv-dbg</code> 是执行式 DM 的直接参考。它提供 JTAG DTM、Program Buffer、SBA 和 Debug ROM；CPU 进入 Debug Mode 后在暂停循环中执行，DM 根据调试请求改变待执行的控制字或程序。其公开文档说明：Debug Memory 同时作为总线从设备暴露给 CPU，而 SBA 作为总线主设备访问系统。

可借鉴的设计点：

- Debug ROM、Data、Program Buffer 与 hart 确认寄存器被组织在同一调试存储窗口中。
- 暂停、执行、恢复和异常均通过明确的确认写入完成。
- 采用执行式调试，降低了对 CPU GPR/CSR 内部端口的要求。
- 文档列出已支持和未支持的可选能力，便于调试器按真实能力退化。

应注意的限制：

- PULP 文档提到其 JTAG 时钟需要低于系统时钟。这不是 RISC-V 规范要求，而是该实现的具体限制；新设计应通过可靠跨时钟域逻辑消除不必要的频率耦合。
- 其 Debug Memory 偏移适合作为参考，不是所有 SoC 的固定地址。

### 8.2 Rocket Chip Debug Module

Rocket Chip 的调试模块采用参数化设计，具有 DMI 时钟侧与系统总线时钟侧分离的结构。公开代码将 Program Buffer 放在 Data 区之前，并为隐含 <code>ebreak</code> 预留位置；同时支持把 SBA 接到 TileLink 系统总线。

可借鉴的设计点：

- 将跨时钟域的“外部 DMI 部分”和“内部系统总线部分”明确切开。
- 以参数控制 <code>nProgramBufferWords</code>、<code>nAbstractDataWords</code>、SBA、hart reset 和 halt group。
- Program Buffer、抽象指令区和 Data 区紧邻排列，便于自动生成短程序使用相对地址。

### 8.3 Ibex Demo System

Ibex Demo System 集成了 PULP 调试模块，并给出通过 OpenOCD 与 GDB 调试 FPGA 系统的完整示例。这证明“标准 DTM + 执行式 DM + Debug ROM + OpenOCD”是一条可在小型 RV32 核上实际使用的路线。

可借鉴的设计点：

- 不必先实现高性能 CPU 才能获得可用调试。
- 板级配置、JTAG IDCODE、复位接法和 OpenOCD 脚本同样属于可用性的组成部分。
- 仿真与 FPGA 都应使用同一套基本调试动作：探测、halt、寄存器读写、内存读写、下载和单步。

### 8.4 VexRiscv 的两类调试接口

VexRiscv 同时保留了项目自定义调试扩展与官方 RISC-V Debug 规范接口的实现。其官方接口配置使用标准 JTAG DTM 参数，并可由 OpenOCD 的 <code>target create ... riscv</code> 接入。这说明内部调试接口可以服务于早期开发，但若目标是通用 GDB/OpenOCD 兼容，仍应提供标准 DTM/DMI/DM 行为。

## 9. 验证顺序与检查清单

### 9.1 分层验证

| 层次 | 验证内容 | 通过条件 |
| --- | --- | --- |
| TAP | TMS 状态转换、IR/DR Capture/Shift/Update、IDCODE | 标准 JTAG 扫描器稳定读取 IDCODE |
| DTM | DTMCS、DMI 请求、响应延迟、<code>busy</code>/<code>failed</code>、<code>dmireset</code> | 随机间隔扫描不丢请求、不串响应 |
| DM 寄存器 | <code>dmactive</code>、hart 选择、<code>dmstatus</code>、W1C 错误位 | 复位、不可用、暂停和恢复状态均正确 |
| 运行控制 | <code>haltreq</code>、<code>resumereq</code>、<code>ndmreset</code> | hart 不会卡在请求中间状态 |
| Debug ROM | Halted/Going/Resuming/Exception 确认，暂停循环 | 所有入口都能回到确定状态 |
| 抽象命令 | GPR、CSR、错误码、超时 | 命令前后非目标寄存器保持不变 |
| Program Buffer | 取指、<code>impebreak</code>、非法指令、load/store | 可读写 RAM，异常能写入 <code>cmderr</code> |
| SBA | AXI 读写、字节选通、自动递增、错误响应 | 错误地址不会挂死 DMI 或 AXI |
| OpenOCD/GDB | <code>halt</code>、<code>reg</code>、<code>mdw</code>、<code>load</code>、<code>step</code> | 长时间重复操作无状态残留 |

### 9.2 最容易遗漏的设计项

- DMI 读响应通常不是当前扫描请求的即时返回值，必须保存上一笔响应。
- <code>cmderr</code> 与 <code>sberror</code> 都是粘滞错误；若不能正确写 1 清除，工具会长期拒绝发送新命令。
- <code>haltreq</code> 与 <code>resumereq</code> 需要确认握手，不能依靠固定延迟。
- Debug ROM 的异常入口不能省略。调试程序的非法指令、Data 区访问错误和 Program Buffer 错误都需要有确定结果。
- Program Buffer 运行时必须禁止竞争写入。
- 普通软件不应访问 Debug Memory；否则软件可以伪造 halted/resuming 确认或执行调试缓冲区。
- SBA 访问 MMIO 可能有读清除、写触发等副作用。调试器访问并不天然无副作用。
- 在 reset、掉电或时钟关闭期间，<code>dmstatus.anyunavail</code> 与 DMI 可访问寄存器必须有明确规定。

## 10. 实现决策建议

对于一个新 RV32 SoC，建议按以下顺序冻结设计：

1. 选定 Debug Memory 基地址、调试入口地址、恢复入口地址和异常入口地址，并把这些地址作为 hart 的正式参数。
2. 完成单 hart Debug Mode：<code>debug_req</code>、<code>dpc</code>、<code>dcsr</code>、调试 PC 跳转和恢复。
3. 完成 DTM、DMI、<code>dmcontrol</code>、<code>dmstatus</code> 和停止/恢复确认。
4. 加入 Data 区、8 字 Program Buffer、<code>impebreak</code>、Debug ROM 暂停循环和 Access Register。
5. 用 OpenOCD 验证 halt、<code>reg</code>、<code>mdw</code>、<code>mww</code>、<code>resume</code> 与 <code>step</code>。
6. 再增加 SBA AXI 主设备，并分别覆盖 RAM、Flash、MMIO、错误地址和连续访问。
7. 最后按产品需求增加多 hart、trigger、认证和调试禁用。

> [!note]
> “规范兼容”不是只有寄存器地址相同。真正决定 OpenOCD 是否稳定工作的，是 DTM 响应时序、<code>busy</code>/<code>cmderr</code>、hart 状态确认、Debug ROM 的返回路径、Program Buffer 终止方式以及总线错误处理是否完整。

## 参考资料

- [RISC-V 调试规范中文学习版](RISC-V调试规范v1.0-中文学习版.md)
- [RISC-V Debug Specification 源码与发布资料](https://github.com/riscv/riscv-debug-spec)
- [OpenOCD User’s Guide：RISC-V 架构命令](https://openocd.org/doc/pdf/openocd.pdf)
- [OpenOCD 的 RISC-V 0.13 驱动源码](https://github.com/openocd-org/openocd/blob/master/src/target/riscv/riscv-013.c)
- [PULP riscv-dbg：Debug System 文档](https://github.com/pulp-platform/riscv-dbg/blob/master/doc/debug-system.md)
- [Rocket Chip Debug Module 源码](https://github.com/chipsalliance/rocket-chip/blob/master/src/main/scala/devices/debug/Debug.scala)
- [Ibex Demo System](https://github.com/lowRISC/ibex-demo-system)
- [VexRiscv 官方 RISC-V 调试接口说明](https://github.com/SpinalHDL/VexRiscv)
