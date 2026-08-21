# I3C 协议学习笔记

## 1. I3C 是什么

I3C，全称 `Improved Inter Integrated Circuit`，可以理解为 I2C 的增强版两线串行总线。它仍然使用 `SDA` 和 `SCL` 两根信号线，但目标是解决传统 I2C 在传感器数量、带宽、功耗、中断线数量和地址管理上的限制。

I3C 的核心定位：

| 方向   | 说明                                       |
| ---- | ---------------------------------------- |
| 兼容性  | 向下兼容 I2C，可在同一总线上混接 I3C 设备和部分 I2C 设备      |
| 性能   | 支持更高传输速率，SDR 模式已明显高于传统 I2C，HDR 模式进一步提升带宽 |
| 功耗   | 通过推挽驱动、更高传输效率和带内事件机制降低系统功耗               |
| 设备管理 | 支持动态地址分配，减少静态地址冲突                        |
| 系统集成 | 支持带内中断、热加入、Secondary Master 等机制，减少额外引脚需求 |

I3C 特别适合传感器较多、空间紧张、低功耗要求高的系统，例如移动设备、可穿戴设备、sensor hub 和 always-on sensor 场景。

## 2. 基本术语

| 术语               | 含义                                            |
| ---------------- | --------------------------------------------- |
| SDR              | `Single Data Rate`，单数据率模式，是 I3C 默认通信模式        |
| HDR              | `High Data Rate`，高数据率模式，用于更高带宽传输              |
| Main Master      | 当前配置为 I3C 总线主设备的控制端                           |
| Current Master   | 当前这一刻真正掌控总线的主设备                               |
| Secondary Master | 具备 Master 能力，但当前作为 Slave 挂在总线上的设备             |
| CCC              | `Common Command Code`，I3C 通用命令码               |
| IBI              | `In-Band Interrupt`，带内中断，从设备可通过总线主动请求主设备关注    |
| Hot-Join         | 热加入，设备可在总线已运行后加入并请求地址分配                       |
| ENTDAA           | `Enter Dynamic Address Assignment`，进入动态地址分配流程 |
| SETDASA          | 通过静态地址分配动态地址的 CCC 命令                          |

## 3. 总线连接与电气行为

I3C 和 I2C 一样使用两根线：

| 信号 | 作用 |
| --- | --- |
| SCL | 时钟线 |
| SDA | 数据线 |

![I3C 总线拓扑](./_assets/i3c_learn/811006-20260219182746650-2085676287.png)

I3C 与 I2C 的关键差异在驱动方式：

| 阶段 | I2C | I3C |
| --- | --- | --- |
| 仲裁/起始阶段 | 开漏 | 开漏 |
| 数据传输阶段 | 开漏 | 多数场景使用推挽 |
| 上升沿 | 依赖上拉电阻，受 RC 影响 | 推挽驱动，上升沿更快 |
| 速率瓶颈 | 总线电容和上拉限制明显 | 更适合高速传输 |

I3C 在保留 I2C 兼容性的同时，引入混合驱动方式：需要兼容或仲裁时使用开漏，进入高速数据阶段后可使用推挽驱动。这是 I3C 能提升速率并降低功耗的重要原因。

## 4. I2C 设备与 I3C 设备如何共存

I3C SDR 模式和 I2C 的基本时序相似，因此 I3C 总线可以兼容 I2C 设备。共存时需要理解几类访问：

| 访问类型 | 行为 |
| --- | --- |
| Master 访问 I2C 静态地址 | 对应 I2C 设备响应 |
| Master 发送 I3C 广播地址 | I3C 设备响应，I2C 设备通常忽略 |
| Master 访问 I3C 动态地址 | 持有该动态地址的 I3C 设备响应 |
| I3C 高速传输 | I2C 设备通常不会识别高速 I3C 数据，因为其滤波/时序能力不同 |

在被分配动态地址之前，I3C Slave 可以像 I2C 设备一样使用静态地址；一旦被分配动态地址，就应以 I3C Slave 身份工作，直到复位或重新配置。

## 5. 动态地址分配

I3C 支持为从设备动态分配 7-bit 地址，解决 I2C 静态地址容易冲突的问题。动态地址分配依赖设备特征信息和主设备控制流程。

常见相关信息：

| 信息 | 作用 |
| --- | --- |
| 48-bit 临时 ID | 用于参与动态地址分配和设备识别 |
| BCR | `Bus Characteristic Register`，描述设备在总线中的角色和能力 |
| DCR | `Device Characteristic Register`，描述设备类型，例如传感器类别 |
| LVR | `Legacy Virtual Register`，传统 I2C 设备用于描述自身能力 |

![BCR 位域说明](./_assets/i3c_learn/811006-20260219183456321-898848573.png)

典型动态地址流程：

1. Current Master 发送广播 CCC，进入动态地址分配流程。
2. 总线上的 I3C Slave 根据自身 ID/能力参与仲裁。
3. Master 依次识别设备并分配动态地址。
4. Slave 获得动态地址后，后续使用动态地址响应 I3C 访问。

常见命令：

| 命令      | 作用                      |
| ------- | ----------------------- |
| ENTDAA  | 进入动态地址分配流程              |
| SETDASA | 基于静态地址设置动态地址            |
| SETAASA | 将静态地址作为动态地址使用，常用于简化配置场景 |

### 5.1 动态地址分配要解决什么问题

I2C 设备通常依赖固定 7-bit 静态地址。如果两个设备静态地址冲突，系统只能通过 strap pin、外部 mux 或软件规避。I3C 引入动态地址后，设备上电时可以先用静态地址或唯一 ID 参与发现，随后由 Current Master 分配一个运行时地址。正常 private transfer 阶段，Master 访问的是动态地址，而不是一直访问静态地址。

可以把地址分配理解成三层信息：

| 层次 | 信息 | 作用 |
| --- | --- | --- |
| 设备身份 | Provisional ID、BCR、DCR | 让 Master 识别“这是谁、有什么能力” |
| 初始可达地址 | static address | 用于 SETDASA/SETAASA 或兼容 I2C 场景 |
| 运行时地址 | dynamic address | 后续 I3C private read/write 和 directed CCC 使用 |

动态地址不是简单把寄存器里某个字段写一下。协议层需要确保：总线上每个 I3C slave 获得唯一地址；slave 知道自己被分配了哪个地址；Master 侧的 device address table 也记录了目标设备地址，后续 command queue 才能用 DAT index 找到目标。

### 5.2 标准 ENTDAA 流程

ENTDAA 是最标准的动态地址分配流程，适合总线上有多个 I3C slave、且 Master 需要根据设备 ID 逐个发现设备的场景。

典型流程如下：

```text
Bus Available
-> Current Master 发送 START
-> 发送广播地址 0x7E + Write
-> 发送 ENTDAA CCC
-> Repeated START
-> 发送广播地址 0x7E + Read
-> I3C Slave 依次输出 Provisional ID / BCR / DCR
-> Master 通过仲裁识别一个 Slave
-> Master 回写一个 dynamic address
-> 被分配地址的 Slave ACK，并退出本轮 DAA
-> 如果仍有未分配设备，继续下一轮
-> STOP，DAA 结束
```

这个流程里最关键的是“仲裁”。多个 slave 可能同时响应 DAA read 阶段，它们会按 ID bit 在 SDA 上仲裁。仲裁胜出的 slave 被 Master 识别并分配地址，其他 slave 退出当前轮，等待后续轮次。这样 Master 不需要预先知道总线上有多少设备，也能逐个分配地址。

ENTDAA 验证时要关注：

| 测试点 | 说明 |
| --- | --- |
| 广播 CCC 是否正确 | ENTDAA 必须通过广播 CCC 进入 |
| 多设备仲裁 | 多个 slave 同时参与时，只有一个设备赢得当前轮 |
| PID/BCR/DCR 采样 | Master 读取到的设备身份信息要正确 |
| dynamic address 唯一 | 每个 slave 获得唯一动态地址，不能重复 |
| 分配后退出 | 已获得地址的 slave 不应继续参与后续 DAA 轮次 |
| 后续访问 | private transfer 应使用 dynamic address 成功访问设备 |

### 5.3 SETDASA 流程

SETDASA 是 `Set Dynamic Address from Static Address`。它不走完整 ID 仲裁，而是 Master 已经知道某个 slave 的 static address，然后通过定向 CCC 给它设置 dynamic address。

适用场景：

| 场景 | 说明 |
| --- | --- |
| 板级设备固定 | Master 已知道目标设备 static address |
| 只有少量设备 | 不需要完整 ENTDAA 枚举 |
| 验证定向地址配置 | case 中常用于快速让 VIP slave 进入可访问状态 |

概念流程：

```text
Master 知道目标 static address
-> Master 在 DAT 中记录 static address 和计划分配的 dynamic address
-> Master 发送 directed CCC SETDASA
-> 目标 slave ACK 并更新自己的 dynamic address
-> Master 后续使用 dynamic address 访问该 slave
```

在本地 case 里，`i3c_set_daa_cmd(i3c_num, 1)` 走的就是这种“定向地址分配/设置”思路。该 task 会向 `COMMAND_QUEUE_PORT` 写一条 command：

| 字段 | 值 | 含义 |
| --- | --- | --- |
| `[2:0]` | `3'h3` | DAA/CCC 类 command entry |
| `[6:3]` | `4'h5` | transaction id 或命令相关字段 |
| `[14:7]` | `8'h87` | directed DAA/SETDASA 类命令 |
| `[25:21]` | `5'h1` | 传输长度/参数字段 |
| `[26]` | `1` | command 有效控制 |
| `[30]` | `1` | push/valid 类控制 |

对应地址表由 `i3c_block_init` 提前写好：

| 寄存器 | 字段 | 典型值 | 含义 |
| --- | --- | --- | --- |
| `DEVICE_ADDR` | `[22:16]` | `7'h55` | controller 自身 dynamic address |
| `DEVICE_ADDR` | `[31]` | `1` | controller dynamic address valid |
| `DEV_ADDR_TABLE_LOC1` | `[6:0]` | `7'h63` | 目标 slave static address |
| `DEV_ADDR_TABLE_LOC1` | `[23:16]` | `8'h64` 或 `8'he3` | 目标 slave dynamic address |
| `DEV_ADDR_TABLE_LOC1` | `[31]` | I2C mode 时为 `1` | legacy I2C 标志 |

所以在 `i3c0_master_setdasa_test.sv`、SDR rate case、TX FIFO case、DMA TX case 中，地址分配相关动作可以理解为：

```text
i3c_block_init(0, 0, 7'h63, 8'h64 或 8'he3)
-> 写 DEVICE_ADDR，配置 Master 自身 dynamic address
-> 写 DEV_ADDR_TABLE_LOC1，配置目标 static/dynamic address
-> i3c_block_enable
-> i3c_set_daa_cmd(0, 1)，发送 8'h87
-> 后续 private transfer 使用 DAT 中的目标地址
```

这里验证的重点不是多设备 ENTDAA 仲裁，而是“已知 static address 的目标 slave 能否被设置 dynamic address，并基于 DAT 完成后续访问”。

### 5.4 SETAASA 流程

SETAASA 是 `Set All Addresses to Static Address`。它的意思是让设备把 static address 当作 dynamic address 使用，常用于简化系统配置或验证环境。它不需要 Master 给每个设备重新挑选 dynamic address，但前提是总线上 static address 不能冲突。

本地 case 中 `i3c0_master_setaasa_test.sv`、`i3c0_master_transmit_withrxfifo_test.sv`、`i3c0_trans_rxfifo_to_mem_withdma_test.sv` 等会使用：

```systemverilog
i3c_set_transfer_cmd(0, 0, 1, 8'h29, 0, 0, 1, 1);
```

这里的关键参数是：

| 参数 | 值 | 说明 |
| --- | --- | --- |
| `speed` | `0` | SDR0 |
| `iscp` | `1` | 当前 command 是 CCC |
| `cmd` | `8'h29` | SETAASA 类命令 |
| `isread` | `0` | 写方向 CCC |
| `tr_id` | `1` | transaction id |
| `isstop` | `1` | command 后产生 stop 类控制 |

SETAASA case 的一个典型写法是：先发 `8'h29`，再读取 response queue 和 DAT，然后手动把 DAT 中的 dynamic address 字段改成 `8'he3`，再继续做 read/private transfer：

```text
i3c_set_transfer_cmd(... cmd=8'h29)
-> i3c_check_resp_status
-> 读取 DEV_ADDR_TABLE_LOC1
-> 修改 rdata[23:16] = 8'he3
-> 写回 DEV_ADDR_TABLE_LOC1
-> i3c_set_transfer_arg
-> i3c_set_transfer_cmd(... isread=1 或 isread=0)
```

这说明这些 case 关注的是“SETAASA/地址状态切换后，DAT 更新和后续读写是否能继续跑通”，并不是完整验证所有设备的 SETAASA 广播响应。

### 5.5 本地 Case 中动态地址相关覆盖点

| case | 地址分配方式 | 关键命令/地址 | 主要验证点 |
| --- | --- | --- | --- |
| `i3c0_master_setdasa_test.sv` | SETDASA/定向 DAA | `i3c_set_daa_cmd(0,1)`，`cmd=8'h87` | static `7'h63` 被配置为 dynamic `8'h64` 后可继续传输 |
| `i3c0_master_setaasa_test.sv` | SETAASA | `cmd=8'h29`，DAT dynamic 后续改 `8'he3` | SETAASA response、DAT 更新、后续 private write |
| `i3c0_master_mode_sdr*_rate_test.sv` | DAA 前置 | static `7'h63`，dynamic `8'h64` | 地址流程完成后，各 SDR 速率传输正确 |
| `i3c0_master_transmit_withrxfifo_test.sv` | SETAASA 前置 | `cmd=8'h29`，DAT dynamic `8'he3` | 地址状态准备好后，master read 能读 RX FIFO |
| `i3c0_trans_rxfifo_to_mem_withdma_test.sv` | SETAASA 前置 | `cmd=8'h29`，DAT dynamic `8'he3` | 地址状态准备好后，RX DMA 数据搬运正确 |
| `i3c0_slave_to_secmaster_test.sv` | 外部 master 地址流程 | 等 `INTR_STATUS[8]` | DUT slave 获得 dynamic address 后发起 master request |

I3C1 对应 case 与 I3C0 基本对称，只是 `i3c_num=1`，寄存器 base 换成 `I3C1_BASE`。

### 5.6 动态地址相关寄存器观察点

| 寄存器/状态 | 字段 | 观察意义 |
| --- | --- | --- |
| `DEVICE_ADDR` | `[6:0]` | slave 模式下本机 static address |
| `DEVICE_ADDR` | `[15]` | static address valid |
| `DEVICE_ADDR` | `[22:16]` | master/controller 自身 dynamic address |
| `DEVICE_ADDR` | `[31]` | dynamic address valid |
| `DEV_ADDR_TABLE_LOC1` | `[6:0]` | 目标设备 static address |
| `DEV_ADDR_TABLE_LOC1` | `[23:16]` | 目标设备 dynamic address |
| `DEV_ADDR_TABLE_LOC1` | `[31]` | legacy I2C device 标志 |
| `COMMAND_QUEUE_PORT` | `[14:7]` | CCC command code，例如 `8'h87`、`8'h29` |
| `COMMAND_QUEUE_PORT` | `[15]` | `iscp`，表示 command present/CCC |
| `INTR_STATUS[3]` | command queue ready | 写下一条 command 前需要等待 |
| `INTR_STATUS[4]` | response ready | CCC/地址命令完成后可读 response |
| `RESPONSE_QUEUE_PORT` | response data | 检查命令是否完成、有无错误 |
| `INTR_STATUS[8]` | dynamic address done | secondary master/slave 场景中用于判断地址分配完成 |

### 5.7 验证时怎么判断动态地址流程是正常的

建议按下面顺序查：

1. `DEV_ADDR_TABLE_LOC1[6:0]` 是否等于目标 static address，例如 `7'h63`。
2. `DEV_ADDR_TABLE_LOC1[23:16]` 是否写入预期 dynamic address，例如 `8'h64` 或 `8'he3`。
3. `COMMAND_QUEUE_PORT` 中 CCC command 是否正确，SETDASA 类看 `8'h87`，SETAASA 看 `8'h29`。
4. 写 command 前是否等待 `INTR_STATUS[3]`，避免 command queue 未 ready。
5. CCC 后是否通过 `INTR_STATUS[4]` 和 `RESPONSE_QUEUE_PORT` 看到响应。
6. 后续 private transfer 是否能用同一个 DAT entry 正常访问 VIP slave。
7. 如果是 secondary master/slave 场景，额外看 `INTR_STATUS[8]` 是否置位。

如果地址分配失败，常见现象是：response queue 返回错误、后续 private transfer NACK、RX/TX FIFO 没有预期状态、scoreboard 收不到对应 transaction。调试时优先看 DAT 和 command queue，其次看 VIP slave 的 static/dynamic address 配置是否和 DUT 写入一致。

## 6. I3C 地址类型

I3C 总线上常见三类地址：

| 地址类型 | 说明 |
| --- | --- |
| 静态地址 | 传统 I2C 或未分配动态地址前的 I3C 设备使用 |
| 广播地址 | I3C 广播命令使用，常见为 `0x7E` |
| 动态地址 | I3C Master 分配给 Slave 的运行时地址 |

![I3C/I2C 地址头对比](./_assets/i3c_learn/811006-20260219183609062-492957670.png)

其中广播地址用于 CCC、动态地址分配、设备发现等流程；动态地址用于正常 I3C 设备访问。

## 7. Slave 的基本职责

I3C Slave 在总线上需要根据地址头和总线状态决定响应方式：

| 场景 | Slave 行为 |
| --- | --- |
| 地址匹配自身动态地址 | 可 ACK 并按 SDR 消息处理，也可 NACK 放弃本次传输 |
| 广播写消息 | 至少需要解析首个字节，判断是否为 CCC |
| CCC 命令适用于本设备 | 按命令要求执行，例如参与地址分配、进入/退出模式 |
| HDR 模式切换 | 支持 HDR 的设备可进入 HDR，不支持的设备需要监听 HDR Exit |
| 地址不匹配 | 等待 Repeated START 或 STOP，不驱动总线 |

简单说，Slave 需要能识别广播、动态地址、CCC 和模式切换，并在不属于自己的传输中保持安静。

## 8. 传输格式

I3C 的公共传输格式和 I2C 有相似的起止条件：

```text
START + 7-bit Address + RnW + ACK/NACK + Data ... + STOP
```

但 I3C 在具体传输类型上更丰富，主要包括：

| 类型                       | 用途                                  |
| ------------------------ | ----------------------------------- |
| SDR                      | 默认模式，常用于 private read/write 和普通控制传输 |
| HDR                      | 高速模式，包括 DDR、TSP、TSF 等变体             |
| CCC                      | 通用命令，用于广播控制、动态地址分配、事件管理等            |
| IBI                      | 从设备主动发起带内中断请求                       |
| Hot-Join                 | 新设备加入总线并请求地址分配                      |
| Secondary Master Request | 具备 Master 能力的 Slave 请求成为主控          |

### 8.1 速度模式整体理解

I3C 的速度模式可以分成三层理解：I2C 兼容模式、I3C SDR 模式、I3C HDR 模式。case 里的 `speed` 参数就是把这几类模式编码进 controller 的 command queue。

| 模式 | case 中 `speed` | 协议含义 | 当前 case 覆盖 |
| --- | ---: | --- | --- |
| SDR0 | `0` | I3C 默认 SDR 模式，最常用的 private transfer 速率档 | SDR0 rate、CCC、TX/RX FIFO、DMA、Secondary Master |
| SDR1 | `1` | SDR 扩展速率档，低电平计数与 SDR0 不同 | `i3c*_master_mode_sdr1_rate_test` |
| SDR2 | `2` | SDR 扩展速率档 | `i3c*_master_mode_sdr2_rate_test` |
| SDR3 | `3` | SDR 扩展速率档 | `i3c*_master_mode_sdr3_rate_test` |
| SDR4 | `4` | SDR 扩展速率档，case 中设置最大扩展 low count | `i3c*_master_mode_sdr4_rate_test` |
| HDR-DDR | `6` | High Data Rate DDR 模式，数据在双沿或 HDR 规则下传输 | `i3c*_master_mode_hdr_ddr_rate_test` |
| I2C FM | `7` | I2C Fast Mode 兼容访问 | `i3c*_master_mode_i2c_fm_rate_test` |

这里的 `speed` 并不是单独决定 SCL 频率的唯一因素。真正影响波形的有两部分：

| 配置来源 | 作用 |
| --- | --- |
| timing register | 决定 SCL open-drain、push-pull、扩展 low count 等计数 |
| transfer command `speed[23:21]` | 告诉 controller 本次 command 按哪个速度/模式解释 |

因此一个完整速度 case 一般要同时做两件事：先通过 `i3c_set_scl_timing` 写 timing，再通过 `i3c_set_transfer_cmd` 写 command queue 的 `speed` 字段。

### 8.2 Open-Drain 与 Push-Pull 时序

I3C 保留 I2C 风格的 open-drain 阶段，同时在数据传输阶段大量使用 push-pull。两者的时序寄存器分开配置：

| 寄存器 | Offset | 用途 |
| --- | ---: | --- |
| `SCL_I3C_OD_TIMING` | `0xb4` | 配置 I3C open-drain SCL low/high 相关计数 |
| `SCL_I3C_PP_TIMING` | `0xb8` | 配置 I3C push-pull SCL low/high 相关计数 |
| `SCL_EXT_LCNT_TIMING` | `0xc8` | 配置 SDR1~SDR4 的扩展 low count |
| `SCL_EXT_TERMN_LCNT_TIMING` | `0xcc` | 扩展模式终止 low count，当前 base task 中预留但未实际启用 |

open-drain 阶段常用于 START、仲裁、地址/CCC 早期阶段等需要多设备共享总线的场景；push-pull 阶段用于提高数据传输速率。验证时如果看到同一个 transaction 中 SCL/SDA 行为分段变化，这是 I3C 混合驱动模型的正常表现。

### 8.3 本地 `i3c_set_scl_timing` 的实际配置

当前 base task 的实现集中在 `i3c_base_test::i3c_set_scl_timing(i3c_num, speed)`。`i3c_num=0` 选择 `I3C0_BASE`，`i3c_num=1` 选择 `I3C1_BASE`。

| speed | 写寄存器 | 写入字段 | 等价写入值 | 含义 |
| ---: | --- | --- | --- | --- |
| `0` | `SCL_I3C_OD_TIMING` | `[23:16]=8'ha`，`[7:0]=8'h9` | `0x000a0009` | SDR0 open-drain timing |
| `0` | `SCL_I3C_PP_TIMING` | `[23:16]=8'h9`，`[7:0]=8'h7` | `0x00090007` | SDR0 push-pull timing |
| `1` | `SCL_EXT_LCNT_TIMING` | `[7:0]=8'h0d` | `0x0000000d` | SDR1 扩展 low count |
| `2` | `SCL_EXT_LCNT_TIMING` | `[15:8]=8'h11` | `0x00001100` | SDR2 扩展 low count |
| `3` | `SCL_EXT_LCNT_TIMING` | `[23:16]=8'h19` | `0x00190000` | SDR3 扩展 low count |
| `4` | `SCL_EXT_LCNT_TIMING` | `[31:24]=8'h32` | `0x32000000` | SDR4 扩展 low count |

需要注意一个细节：SDR1~SDR4 case 当前是直接写整个 `SCL_EXT_LCNT_TIMING`，不是 read-modify-write。因此单个 case 只保证当前 speed 对应 byte 有效，其他 byte 会被写成 0。由于每个 rate case 只验证一种速度，这种写法是可以接受的；如果将来一个 case 内连续切换 SDR1~SDR4，就应该改成 read-modify-write，避免前一个速度的配置被清掉。

### 8.4 不同阶段的时钟频率

I3C 总线上的 SCL 频率不是一个固定值。一次传输里可能先经历 open-drain 阶段，再进入 push-pull 数据阶段；如果是 SDR1~SDR4、HDR-DDR 或 I2C 兼容模式，还会使用不同的 speed/timing 规则。

在没有明确 `core_clk` 频率时，可以先按下面的方式理解：

```text
SCL 频率 ≈ I3C core clock / (SCL high count + SCL low count)
```

实际芯片中计数器是否包含额外 offset，要以设计手册和波形量测为准；但对 case debug 来说，下面这个近似关系足够判断“哪个阶段由哪个寄存器控制”。

| 阶段 | 使用场景 | 主要寄存器/字段 | 频率理解 |
| --- | --- | --- | --- |
| Bus idle/free | 总线空闲、等待 START | `BUS_FREE_AVAIL_TIMING`、`BUS_IDLE_TIMING` 等 | 不产生连续 SCL，只检查空闲时间是否满足要求 |
| Open-drain 阶段 | START、地址、仲裁、CCC/DAA 早期阶段 | `SCL_I3C_OD_TIMING` | 频率由 OD high/low count 决定，通常慢于 push-pull |
| Push-pull SDR0 阶段 | SDR0 private data、常规数据传输 | `SCL_I3C_PP_TIMING` | 频率由 PP high/low count 决定，是 SDR0 数据阶段的主要 SCL |
| SDR1~SDR4 扩展阶段 | SDR 低速档或扩展速率档 | `SCL_EXT_LCNT_TIMING` + 当前 PP high count | 主要通过增加 low count 拉低有效 SCL 频率 |
| HDR-DDR 阶段 | HDR-DDR 数据传输 | HDR 相关 command/timing，case 中用 `speed=6`、`cmd=8'h20` | 不能只按 SDR high/low count 看，数据边沿和 HDR 规则也要一起看 |
| I2C FM/FM+ 阶段 | legacy I2C 兼容访问 | I2C FM/FMP timing 或设计默认 timing，case 中 master FM 用 `speed=7` | 更接近 I2C open-drain 频率模型 |

结合当前 `i3c_set_scl_timing` 的配置，可以得到这些近似关系：

| 阶段/模式 | case 配置 | 近似周期计数 | 近似频率公式 |
| --- | --- | ---: | --- |
| SDR0 OD | OD low `0x09`，OD high `0x0a` | `9 + 10 = 19` | `Fcore / 19` |
| SDR0 PP | PP low `0x07`，PP high `0x09` | `7 + 9 = 16` | `Fcore / 16` |
| SDR1 | EXT low `0x0d`，PP high 通常取当前值 | `13 + PP_HCNT` | `Fcore / (13 + PP_HCNT)` |
| SDR2 | EXT low `0x11`，PP high 通常取当前值 | `17 + PP_HCNT` | `Fcore / (17 + PP_HCNT)` |
| SDR3 | EXT low `0x19`，PP high 通常取当前值 | `25 + PP_HCNT` | `Fcore / (25 + PP_HCNT)` |
| SDR4 | EXT low `0x32`，PP high 通常取当前值 | `50 + PP_HCNT` | `Fcore / (50 + PP_HCNT)` |

如果假设 `I3C core clock = 100 MHz`，并且 SDR1~SDR4 使用 reset/default PP high count `0x0a`，可以得到一个便于估算的表：

| 阶段/模式 | 近似 SCL 频率 | 说明 |
| --- | ---: | --- |
| SDR0 OD | `100 MHz / 19 ≈ 5.26 MHz` | 地址/CCC/仲裁类 open-drain 阶段 |
| SDR0 PP | `100 MHz / 16 = 6.25 MHz` | SDR0 数据 push-pull 阶段 |
| SDR1 | `100 MHz / (13+10) ≈ 4.35 MHz` | 扩展 low count 后比 SDR0 慢 |
| SDR2 | `100 MHz / (17+10) ≈ 3.70 MHz` | low count 继续增加 |
| SDR3 | `100 MHz / (25+10) ≈ 2.86 MHz` | 更低的 SDR 档 |
| SDR4 | `100 MHz / (50+10) ≈ 1.67 MHz` | 当前配置中最低的 SDR 扩展档 |

这里容易误解的一点是：`SDR1~SDR4` 在很多控制器里不是“数字越大越快”，而是通过扩展 low count 得到更低的有效速率，用来兼容能力较弱或需要降速的设备。当前 case 里的配置也符合这个趋势：`0x0d -> 0x11 -> 0x19 -> 0x32`，low count 越来越大，SCL 频率越来越低。

调波形时可以按阶段量测：

| 量测位置          | 期望                                |
| ------------- | --------------------------------- |
| 地址/CCC 前半段    | 更接近 OD timing                     |
| 普通 SDR0 数据段   | 更接近 PP timing                     |
| SDR1~SDR4 数据段 | low time 明显变长                     |
| HDR-DDR 数据段   | 不能只按普通 SDR 周期判断，要结合 HDR 进入命令和双沿数据 |
| I2C FM/FM+    | 更接近 legacy I2C 的开漏传输节奏            |

### 8.5 Transfer Command 中的速度字段

时序寄存器配置好以后，真正发起传输时还要通过 `i3c_set_transfer_cmd` 写 `COMMAND_QUEUE_PORT`。速度字段位于 command queue entry 的 `[23:21]`。

```systemverilog
i3c_set_transfer_cmd(i3c_num, speed, iscp, cmd, isshortarg, isread, tr_id, isstop);
```

关键字段：

| 字段                          | 来源            | 说明                                         |
| --------------------------- | ------------- | ------------------------------------------ |
| `COMMAND_QUEUE_PORT[23:21]` | `speed`       | 当前传输的速度/模式编码                               |
| `[15]`                      | `iscp`        | 是否为 CCC command                            |
| `[14:7]`                    | `cmd`         | CCC command code，例如 HDR-DDR case 用 `8'h20` |
| `[27]`                      | `isshortarg`  | SDR0~SDR4 下可用于 short data                  |
| `[28]`                      | `isread`      | `0` 为 write，`1` 为 read                     |
| `[31]`                      | `isstop` 相关控制 | 当前 task 中仅 `speed<=4` 时置 1                 |


典型调用如下：

| case 类型 | 调用 | 说明 |
| --- | --- | --- |
| SDR0 write | `i3c_set_transfer_cmd(0,0,0,0,0,0,2,1)` | 普通 SDR0 private write |
| SDR1 write | `i3c_set_transfer_cmd(0,1,0,0,0,0,2,1)` | SDR1 private write |
| SDR4 write | `i3c_set_transfer_cmd(0,4,0,0,0,0,2,1)` | SDR4 private write |
| HDR-DDR | `i3c_set_transfer_cmd(0,6,1,8'h20,0,0,2,1)` | 通过 CCC/command 进入 HDR-DDR 相关传输 |
| I2C FM | `i3c_set_transfer_cmd(0,7,0,0,0,0,2,1)` | I2C FM 兼容模式访问 |
| RX FIFO read | `i3c_set_transfer_cmd(0,0,0,0,0,1,2,1)` | SDR0 read，数据进入 RX FIFO |

### 8.6 SDR0~SDR4 的验证重点

SDR0~SDR4 case 的共同主线是：DUT 作为 master，VIP I3C slave 作为目标设备，完成地址配置后发起 private write。

| 速度 | 关键 timing | 关键 command | 主要验证点 |
| --- | --- | --- | --- |
| SDR0 | 写 OD/PP timing | `speed=0` | 基础 SDR 模式能完成 DAA、arg、cmd、TX FIFO、scoreboard |
| SDR1 | `SCL_EXT_LCNT_TIMING[7:0]=8'h0d` | `speed=1` | 扩展 low count 生效后，传输仍能完成 |
| SDR2 | `SCL_EXT_LCNT_TIMING[15:8]=8'h11` | `speed=2` | SDR2 编码和数据一致性 |
| SDR3 | `SCL_EXT_LCNT_TIMING[23:16]=8'h19` | `speed=3` | SDR3 编码和数据一致性 |
| SDR4 | `SCL_EXT_LCNT_TIMING[31:24]=8'h32` | `speed=4` | SDR4 编码和数据一致性 |

这些 case 的 pass/fail 不应只看 SCL 波形，还要看：

| 观察点 | 说明 |
| --- | --- |
| `COMMAND_QUEUE_PORT[23:21]` | 是否写入预期 speed |
| `INTR_STATUS[3]` | command queue 是否 ready |
| `TX_DATA_PORT` | TX FIFO 是否按预期写入 |
| VIP slave observed transaction | slave 侧是否收到一致 byte queue |
| scoreboard | DUT 与 VIP 的 transaction 是否匹配 |

#### SDR 线上时序拆解

SDR 是 I3C 的默认数据传输格式。无论是 SDR0 还是 SDR1~SDR4，线上帧顺序基本一致，差别主要在 SCL timing 和 command queue 的 `speed` 编码。

从 APB 配置视角，本地 SDR write case 的顺序是：

```text
1. 写 SCU/IOMUX 或状态寄存器，准备 I3C0/I3C1 运行环境
2. i3c_set_scl_timing(i3c_num, speed)
3. i3c_block_init(i3c_num, mode, static_addr, dynamic_addr, ...)
4. i3c_block_enable(i3c_num)
5. 地址准备：i3c_set_daa_cmd / SETAASA / SETDASA
6. 等 INTR_STATUS[3] = 1，command queue ready
7. i3c_set_transfer_arg(i3c_num, data_len)
8. 再等 INTR_STATUS[3] = 1
9. i3c_set_transfer_cmd(i3c_num, speed, 0, 0, 0, isread, tr_id, isstop)
10. write case 写 TX_DATA_PORT，read case 等 RX_DATA_PORT
```

从总线波形视角，普通 SDR private write 可以按下面理解：

```text
Bus idle
-> START
-> Target Dynamic Address + W
-> ACK / T-bit 阶段
-> Data byte 0
-> ACK / T-bit 阶段
-> Data byte 1
-> ACK / T-bit 阶段
-> ...
-> Last data byte
-> 结束响应 / T-bit
-> STOP
```

普通 SDR private read 的顺序是：

```text
Bus idle
-> START
-> Target Dynamic Address + R
-> ACK / T-bit 阶段
-> Target 驱动 Data byte 0
-> Controller 继续/结束响应
-> Target 驱动 Data byte 1
-> Controller 继续/结束响应
-> ...
-> Last data byte
-> Controller 结束读
-> STOP
```

这里的 `ACK / T-bit` 不要简单等同于 I2C 的 ACK。I3C SDR 数据阶段有自己的 turnaround/transition 规则，VIP 波形中可能看到 SDA 驱动方在 byte 边界发生切换。验证时更实用的判断方式是：地址方向、byte 数量、最后结束条件、scoreboard 数据是否一致。

SDR0 和 SDR1~SDR4 的差异：

| 项目 | SDR0 | SDR1~SDR4 |
| --- | --- | --- |
| 线上帧顺序 | `START -> Addr -> Data -> STOP` | 与 SDR0 基本一致 |
| command `speed` | `0` | `1/2/3/4` |
| timing 来源 | `SCL_I3C_OD_TIMING` + `SCL_I3C_PP_TIMING` | `SCL_EXT_LCNT_TIMING` 对应 byte + PP high count |
| 波形变化 | 默认 OD/PP 切换 | data 阶段 low time 会变长 |
| case 目的 | 基础 SDR 通路 | 验证不同 low count/speed 编码下仍能正常传输 |

所以看 SDR 波形时，先确认“帧顺序对不对”，再量“每个阶段的 high/low 宽度”。如果帧顺序错了，通常是地址、DAT、command queue 或 FIFO 逻辑问题；如果帧顺序对但频率不对，再回头查 timing 寄存器。

### 8.7 HDR-DDR 模式

HDR-DDR 属于 I3C 的高速扩展模式。和 SDR0~SDR4 不同，HDR-DDR case 不只是把 `speed` 改成 6，还会设置 `iscp=1` 和 `cmd=8'h20`，表示当前 command 带有模式切换/CCC 类含义。

典型调用：

```systemverilog
i3c_set_transfer_cmd(0, 6, 1, 8'h20, 0, 0, 2, 1);
```

解读：

| 参数       | 值       | 含义                                        |
| -------- | ------- | ----------------------------------------- |
| `speed`  | `6`     | HDR-DDR 模式编码                              |
| `iscp`   | `1`     | command present，当前命令不是普通 private transfer |
| `cmd`    | `8'h20` | HDR-DDR 相关进入/控制命令                         |
| `isread` | `0`     | 当前 case 走写方向                              |

更准确地说，`8'h20` 是 Broadcast CCC `ENTHDR0`。它不是普通 private write 的目标地址命令，而是告诉总线上的 HDR-capable target：接下来进入 HDR Mode 0，也就是 HDR-DDR。

#### HDR-DDR 的先后顺序

HDR-DDR 可以拆成三个阶段：SDR 入口阶段、HDR-DDR 数据阶段、HDR 退出/回到 SDR 阶段。

```text
阶段 1：仍处于 SDR 模式
Bus idle
-> START
-> Broadcast Address 7'h7e + W
-> ENTHDR0 CCC，code = 8'h20
-> controller/VIP 预期目标支持 HDR-DDR，支持的 target 进入 HDR-DDR 解释规则

阶段 2：进入 HDR-DDR 模式
-> HDR restart / HDR-DDR 起始序列，具体形态由 controller/VIP 实现
-> HDR-DDR command word，携带目标、方向、长度或控制信息
-> HDR-DDR data word 0
-> HDR-DDR data word 1
-> ...
-> CRC / parity / token / turnaround 等 HDR-DDR 规则相关字段

阶段 3：退出 HDR 或结束本次传输
-> HDR exit pattern 或 controller 内部结束序列
-> 总线回到 SDR 可管理状态
-> 后续才能继续发普通 CCC、SDR private transfer 或 STOP/START 类控制
```

因此 HDR-DDR 的关键点是：**入口 CCC 是 SDR 规则，真正的数据阶段才是 HDR-DDR 规则**。如果波形上先看到 `7'h7e + W` 和 `0x20`，这是正常的；不能因为入口阶段看起来像普通 CCC，就认为 HDR 没有进入。

#### 本地 HDR-DDR case 的 APB 顺序

本地 `i3c0_master_mode_hdr_ddr_rate_test.sv` 的实际顺序是：

```text
1. 清 I3C0 SCU 状态
2. i3c_block_init(0, 0, 7'h63, 8'he3)
3. i3c_block_enable(0)
4. 等 INTR_STATUS[3] = 1
5. i3c_set_transfer_arg(0, 4)
6. 再等 INTR_STATUS[3] = 1
7. i3c_set_transfer_cmd(0, 6, 1, 8'h20, 0, 0, 2, 1)
8. i3c_wirte_data_to_txfifo(0, 1, 1, tx_data_q)
9. VIP slave 侧构造预期 transaction
```

对应 command queue 字段是：

| 字段 | 值 | 作用 |
| --- | --- | --- |
| `[23:21] speed` | `3'b110` | 选择 HDR-DDR |
| `[15] iscp` | `1` | 当前 entry 带 command/CCC |
| `[14:7] cmd` | `8'h20` | `ENTHDR0` |
| `[28] isread` | `0` | 本地 case 是 HDR write |
| `[31] stop` | task 中 `speed>4` 不置位 | HDR 结束不按普通 SDR STOP 字段理解 |

这一点对看波形很重要：SDR0~SDR4 的 `isstop` 会写到 `[31]`，但 HDR-DDR 因为 `speed=6`，当前 task 不会置 `[31]`。所以 HDR case 里不要只用 command queue 的 STOP bit 判断结束，要看 HDR exit/总线恢复状态以及 scoreboard 是否闭环。

#### HDR-DDR 波形关注点

| 阶段 | 先看什么 | 期望现象 |
| --- | --- | --- |
| SDR 入口 | Broadcast address | 出现 `7'h7e + W` |
| SDR 入口 | CCC code | 出现 `ENTHDR0 = 8'h20` |
| 模式切换 | SCL/SDA 规则 | 入口后不再按普通 SDR byte + ACK 逐拍理解 |
| HDR 数据 | 数据边沿 | HDR-DDR 数据阶段要按双沿/word 规则看，而不是只看单沿 byte |
| HDR 数据 | 数据量 | 本地 `transfer_arg=4`，TX FIFO task 写入 1 个 32-bit word，对应 4 byte 数据 |
| 退出阶段 | 总线恢复 | 后续能回到 SDR/CCC 可管理状态 |
| scoreboard | VIP observed data | VIP 侧预期与 DUT 发出的数据一致 |

#### HDR-DDR 与 SDR 的核心差别

| 对比项 | SDR | HDR-DDR |
| --- | --- | --- |
| 入口方式 | 直接 private transfer 或 CCC | 先通过 SDR CCC `ENTHDR0=0x20` 进入 |
| 地址阶段 | `Target Dynamic Address + R/W` | 入口先广播 `7'h7e + W`，HDR 数据阶段再按 HDR command word 描述目标/方向 |
| 数据单位 | byte + ACK/T-bit/turnaround | HDR-DDR word/双沿规则，带额外校验或 token 机制 |
| command queue | `speed=0~4`，通常 `iscp=0` | `speed=6`，`iscp=1`，`cmd=8'h20` |
| STOP/结束 | 普通 STOP 或 repeated START | HDR exit pattern/控制器内部结束序列，之后回 SDR |
| 调试重点 | 地址、ACK/T-bit、FIFO byte 数、STOP | ENTHDR0 是否发出、是否进入 HDR 数据阶段、HDR exit 是否正常 |

HDR-DDR 验证时要重点看三件事：模式进入命令是否被正确编码，slave/VIP 是否按 HDR-DDR 模式响应，传输结束后总线是否能回到可继续工作的状态。当前 case 主要覆盖 HDR-DDR 命令路径和写传输通路，不等价于覆盖所有 HDR 子模式。

### 8.8 I2C FM/FM+ 兼容模式

I3C 支持和 I2C legacy device 共存，因此 controller 需要能以 I2C 风格访问目标设备。case 中常见两类：

| case 类型 | 配置方式 | 说明 |
| --- | --- | --- |
| `i3c*_master_mode_i2c_fm_rate_test` | transfer command `speed=7` | DUT master 以 I2C FM 兼容方式访问 |
| `i2c*_slave_i2c_fm_transmit_trans_test` | slave transmit 中 `speed=0` | I2C slave FM 发送场景 |
| `i2c*_slave_i2c_fm_plus_transmit_trans_test` | slave transmit 中 `speed=1` | I2C FM+ 类发送场景 |

在 `i3c_block_init` 中，`isi2c_mode=1` 时会设置 `DEV_ADDR_TABLE_LOC1[31]`，表示 DAT 里的目标设备按 legacy I2C 设备处理；如果是 I3C slave，则该 bit 不应置位。

I2C 兼容模式的验证重点：

| 测试点 | 说明 |
| --- | --- |
| legacy 标志 | `DEV_ADDR_TABLE_LOC1[31]` 是否按 I2C 目标设置 |
| 地址阶段 | 使用 static address，而不是 I3C dynamic address 流程 |
| 速度编码 | master FM case 使用 `speed=7` |
| open-drain 行为 | I2C 兼容传输更接近开漏行为 |
| scoreboard | VIP legacy I2C slave/master transaction 是否匹配 |

### 8.9 时序相关 debug 方法

速度或时序类 case fail 时，建议按下面顺序查：

1. 确认是否调用了 `i3c_set_scl_timing(i3c_num, speed)`，且 `i3c_num` 与 case 实例一致。
2. 读回 `SCL_I3C_OD_TIMING`、`SCL_I3C_PP_TIMING`、`SCL_EXT_LCNT_TIMING`，确认写入值是否正确。
3. 检查 `COMMAND_QUEUE_PORT[23:21]` 是否等于本 case 预期 speed。
4. 看 `INTR_STATUS[3]`，确认 command queue ready 后再写下一条 command。
5. 对 SDR1~SDR4，特别确认 `SCL_EXT_LCNT_TIMING` 的目标 byte 是否被其他写操作清掉。
6. 对 HDR-DDR，确认 `iscp=1` 和 `cmd=8'h20` 是否同时存在。
7. 对 I2C FM，确认 DAT legacy 标志和目标 VIP 类型是否匹配。
8. 最后再看波形上的 SCL high/low 宽度、START/STOP、ACK/NACK 和数据采样点。

## 9. CCC 通用命令

CCC 是 I3C 的重要控制机制，可以广播给所有设备，也可以定向发送给某个设备。

CCC 常见用途：

| 用途 | 说明 |
| --- | --- |
| 动态地址分配 | 例如 ENTDAA、SETDASA、SETAASA |
| 设备发现 | 获取设备能力、类型、ID 等信息 |
| 中断控制 | 使能或禁止 IBI 等事件 |
| 功耗管理 | 控制设备进入或退出特定状态 |
| 模式管理 | 进入 HDR、退出 HDR、配置总线行为 |

典型 CCC 传输可理解为：

```text
START + Broadcast Address + CCC + Data + STOP
```

![Broadcast CCC 传输格式](./_assets/i3c_learn/811006-20260219183805323-1473190710.png)

定向 CCC 会在广播或寻址之后指定目标设备，只让目标设备执行对应命令。

### 9.1 CCC 编码规则

CCC 是 8-bit command code。一般可以先用 bit7 区分广播和定向：

| 类型 | bit7 | 编码范围 | 说明 |
| --- | --- | --- | --- |
| Broadcast CCC | `0` | `0x00~0x7f` | 对总线上所有支持该 CCC 的 target 生效 |
| Direct CCC | `1` | `0x80~0xfe` | 对指定 target 或 group 生效 |
| Vendor/Standard Extension | broadcast 常见 `0x61~0x7f`，direct 常见 `0xe0~0xfe` | 扩展命令 | 由厂商或标准组织定义，验证时要看具体设备规范 |

很多 CCC 同时有 broadcast 和 direct 两种形式，direct 形式通常是在 broadcast code 上加 `0x80`。例如：

```text
ENEC broadcast = 0x00
ENEC direct    = 0x80

DISEC broadcast = 0x01
DISEC direct    = 0x81
```

也有一些命令只允许 broadcast，例如 `ENTDAA`、`SETAASA`、`ENTHDRx`；还有一些只允许 direct，例如 `SETDASA`、`GETPID`、`GETBCR`。

### 9.2 Broadcast CCC 指令表

下面按公开 I3C/Zephyr/Linux 头文件中常见命名整理。不同 I3C 版本中命名可能略有变化，例如 `DEFSLVS` 在新术语中也写作 `DEFTGTS`。
验证时要以 IP spec 和 VIP 支持列表为准：下表是协议命令全集视角，不等于当前 case 已经覆盖了每条命令。

|        Code | 命令                            | 方向            | 作用                                                                                    |
| ----------: | ----------------------------- | ------------- | ------------------------------------------------------------------------------------- |
|      `0x00` | `ENEC`                        | Broadcast Set | Enable Events，允许 target 发起 IBI、Controller Role Request、Hot-Join 等事件                   |
|      `0x01` | `DISEC`                       | Broadcast Set | Disable Events，禁止对应事件                                                                 |
|      `0x02` | `ENTAS0`                      | Broadcast Set | 进入 Activity State 0，正常工作态                                                             |
|      `0x03` | `ENTAS1`                      | Broadcast Set | 进入 Activity State 1                                                                   |
|      `0x04` | `ENTAS2`                      | Broadcast Set | 进入 Activity State 2                                                                   |
|      `0x05` | `ENTAS3`                      | Broadcast Set | 进入 Activity State 3                                                                   |
|      `0x06` | `RSTDAA`                      | Broadcast Set | Reset Dynamic Address Assignment，清除动态地址                                               |
|      `0x07` | `ENTDAA`                      | Broadcast Set | Enter Dynamic Address Assignment，进入动态地址分配流程                                           |
|      `0x08` | `DEFTGTS` / `DEFSLVS`         | Broadcast Set | Define List of Targets，广播已知 target 列表                                                 |
|      `0x09` | `SETMWL`                      | Broadcast Set | Set Max Write Length，设置最大写长度                                                          |
|      `0x0a` | `SETMRL`                      | Broadcast Set | Set Max Read Length，设置最大读长度，也可关联 IBI payload 长度                                       |
|      `0x0b` | `ENTTM`                       | Broadcast Set | Enter Test Mode                                                                       |
|      `0x0c` | `SETBUSCON`                   | Broadcast Set | Set Bus Context，声明总线/规范上下文                                                            |
|      `0x12` | `ENDXFER`                     | Broadcast Set | Data Transfer Ending Procedure Control                                                |
|      `0x20` | `ENTHDR0`                     | Broadcast Set | Enter HDR Mode 0，HDR-DDR                                                              |
|      `0x21` | `ENTHDR1`                     | Broadcast Set | Enter HDR Mode 1，HDR-TSP                                                              |
|      `0x22` | `ENTHDR2`                     | Broadcast Set | Enter HDR Mode 2，HDR-TSL                                                              |
|      `0x23` | `ENTHDR3`                     | Broadcast Set | Enter HDR Mode 3，HDR-BT                                                               |
|      `0x24` | `ENTHDR4`                     | Broadcast Set | Enter HDR Mode 4，版本/实现相关                                                              |
|      `0x25` | `ENTHDR5`                     | Broadcast Set | Enter HDR Mode 5，版本/实现相关                                                              |
|      `0x26` | `ENTHDR6`                     | Broadcast Set | Enter HDR Mode 6，版本/实现相关                                                              |
|      `0x27` | `ENTHDR7`                     | Broadcast Set | Enter HDR Mode 7，版本/实现相关                                                              |
|      `0x28` | `SETXTIME`                    | Broadcast Set | Exchange Timing Information，交换/配置时序相关信息                                               |
|      `0x29` | `SETAASA`                     | Broadcast Set | Set All Addresses to Static Addresses，让所有 target 使用 static address 作为 dynamic address |
|      `0x2a` | `RSTACT`                      | Broadcast Set | Target Reset Action，配置 target 对 reset pattern 的响应                                     |
|      `0x2b` | `DEFGRPA`                     | Broadcast Set | Define List of Group Address，定义 group address 列表                                      |
|      `0x2c` | `RSTGRPA`                     | Broadcast Set | Reset Group Address，清除 group address                                                  |
|      `0x2d` | `MLANE`                       | Broadcast Set | Multi-Lane Data Transfer Control                                                      |
| `0x61~0x7f` | `VENDOR` / Standard Extension | Broadcast     | 厂商或标准扩展 CCC                                                                           |

常见保留区间：

| Code 范围 | 说明 |
| --- | --- |
| `0x0d~0x11` | 当前公开头文件中未作为常用基础 CCC 展开，按保留/版本相关处理 |
| `0x13~0x1f` | 多数场景按保留处理；HDR-DDR 中 `0x1f` 可作为特殊 dummy command code 出现 |
| `0x2e~0x60` | 保留或版本相关扩展 |

### 9.3 Direct CCC 指令表

| Code | 命令 | 方向 | 作用 |
| ---: | --- | --- | --- |
| `0x80` | `ENEC` | Direct Set | 对单个 target 使能事件 |
| `0x81` | `DISEC` | Direct Set | 对单个 target 禁止事件 |
| `0x82` | `ENTAS0` | Direct Set | 指定 target 进入 Activity State 0 |
| `0x83` | `ENTAS1` | Direct Set | 指定 target 进入 Activity State 1 |
| `0x84` | `ENTAS2` | Direct Set | 指定 target 进入 Activity State 2 |
| `0x85` | `ENTAS3` | Direct Set | 指定 target 进入 Activity State 3 |
| `0x86` | `RSTDAA_DC` | Direct Set | Direct Reset Dynamic Address，版本相关/部分规范中不推荐使用 |
| `0x87` | `SETDASA` | Direct Set | Set Dynamic Address from Static Address，按静态地址设置动态地址 |
| `0x88` | `SETNEWDA` | Direct Set | Set New Dynamic Address，重设已有动态地址 |
| `0x89` | `SETMWL` | Direct Set | 对单个 target 设置最大写长度 |
| `0x8a` | `SETMRL` | Direct Set | 对单个 target 设置最大读长度 |
| `0x8b` | `GETMWL` | Direct Get | 获取最大写长度 |
| `0x8c` | `GETMRL` | Direct Get | 获取最大读长度 |
| `0x8d` | `GETPID` | Direct Get | 获取 48-bit Provisioned ID |
| `0x8e` | `GETBCR` | Direct Get | 获取 Bus Characteristic Register |
| `0x8f` | `GETDCR` | Direct Get | 获取 Device Characteristic Register |
| `0x90` | `GETSTATUS` | Direct Get | 获取 target 状态 |
| `0x91` | `GETACCCR` / `GETACCMST` | Direct Get | 获取是否接受 controller/master role 相关能力，命名随版本变化 |
| `0x92` | `ENDXFER` | Direct Set | Data Transfer Ending Procedure Control，部分版本中也可能标为保留/版本相关 |
| `0x93` | `SETBRGTGT` | Direct Set | Set Bridge Targets，桥接目标配置 |
| `0x94` | `GETMXDS` | Direct Get | Get Max Data Speed，获取最大数据速率能力 |
| `0x95` | `GETCAPS` / `GETHDRCAP` | Direct Get | 获取可选能力或 HDR capability，命名随版本变化 |
| `0x96` | `SETROUTE` | Direct Set | Set Route，路由相关配置 |
| `0x97` | `D2DXFER` | Direct Set | Device-to-Device tunneling/data transfer control |
| `0x98` | `SETXTIME` | Direct Set | Exchange Timing Information，定向设置 timing 信息 |
| `0x99` | `GETXTIME` | Direct Get | 获取 exchange timing 信息 |
| `0x9a` | `RSTACT` | Direct Set/Get | Target Reset Action |
| `0x9b` | `SETGRPA` | Direct Set | Set Group Address |
| `0x9c` | `RSTGRPA` | Direct Set | Reset Group Address |
| `0x9d` | `MLANE` | Direct Set | Multi-Lane Data Transfer Control |
| `0xe0~0xfe` | `VENDOR` / Standard Extension | Direct | 厂商或标准扩展 CCC |

常见保留区间：

| Code 范围 | 说明 |
| --- | --- |
| `0x9e~0xdf` | 多数公开基础头文件中未定义为常用 CCC，按保留/版本相关处理 |
| `0xff` | 不作为普通 CCC 使用 |

### 9.4 CCC 通用传输帧

Broadcast CCC 的基本帧：

```text
START
-> Broadcast Address 7'h7e + W
-> CCC code
-> Defining Byte，可选
-> Data，可选
-> STOP 或 Repeated START
```

Direct CCC 的基本帧：

```text
START
-> Broadcast Address 7'h7e + W
-> Direct CCC code
-> Repeated START
-> Target Dynamic Address + R/W
-> Defining Byte / Sub-command / Data，按 CCC 定义
-> STOP
```

Direct CCC 不是直接用目标地址作为第一拍地址，而是先用 `7'h7e` 广播地址通知“我要发 CCC”，再通过 repeated START 指向具体 target。

Direct CCC 还常见 Direct Write/Read 组合形式：先用同一个 Direct CCC 对目标写入参数，再紧接着读取返回数据。典型例子是能力、状态、timing 信息查询类命令，验证时要同时看写入阶段的 CCC code 和读取阶段的目标动态地址。

### 9.5 不同速率的传输流程

不同速率模式的差异可以归纳为：先准备地址和 timing，再通过 command queue 的 `speed` 字段启动对应模式。

#### SDR0 private write

```text
配置 IOMUX 和 VIP 拓扑
-> i3c_set_scl_timing(i3c_num, 0)
-> i3c_block_init(i3c_num, 0, static_addr, dynamic_addr)
-> i3c_block_enable
-> i3c_set_daa_cmd 或 SETAASA/SETDASA 前置地址流程
-> 等 INTR_STATUS[3]，command queue ready
-> i3c_set_transfer_arg(i3c_num, data_len)
-> 等 INTR_STATUS[3]
-> i3c_set_transfer_cmd(i3c_num, 0, 0, 0, 0, 0, tr_id, 1)
-> 写 TX_DATA_PORT
-> scoreboard 比对 VIP slave observed data
```

本地典型调用：

```systemverilog
i3c_set_scl_timing(0, 0);
i3c_block_init(0, 0, 7'h63, 8'h64, 0, 1, 1);
i3c_block_enable(0);
i3c_set_daa_cmd(0, 1);
i3c_set_transfer_arg(0, 16);
i3c_set_transfer_cmd(0, 0, 0, 0, 0, 0, 2, 1);
```

#### SDR1~SDR4 private write

```text
配置对应 SCL_EXT_LCNT_TIMING
-> 其余地址流程与 SDR0 类似
-> transfer command 的 speed 改为 1/2/3/4
-> TX FIFO 写数据
-> scoreboard 比对
```

对应关系：

| 模式 | timing 配置 | transfer command |
| --- | --- | --- |
| SDR1 | `i3c_set_scl_timing(i3c_num, 1)` | `speed=1` |
| SDR2 | `i3c_set_scl_timing(i3c_num, 2)` | `speed=2` |
| SDR3 | `i3c_set_scl_timing(i3c_num, 3)` | `speed=3` |
| SDR4 | `i3c_set_scl_timing(i3c_num, 4)` | `speed=4` |

#### SDR read / RX FIFO

```text
完成地址流程
-> 可先发 SETAASA，更新 DAT dynamic address
-> i3c_set_transfer_arg(i3c_num, read_len)
-> i3c_set_transfer_cmd(i3c_num, speed, 0, 0, 0, 1, tr_id, 1)
-> VIP slave 提供数据
-> DUT 从 RX_DATA_PORT 读数据
-> scoreboard 比对
```

关键区别是 `isread=1`：

```systemverilog
i3c_set_transfer_cmd(0, 0, 0, 0, 0, 1, 2, 1);
```

#### I2C FM 兼容传输

```text
配置 DAT legacy I2C 标志
-> 使用 static address
-> 不依赖 I3C DAA 后的 dynamic address
-> transfer command 设置 speed=7
-> 通过 TX/RX FIFO 完成数据传输
```

本地 master FM case 的关键命令：

```systemverilog
i3c_block_init(0, 0, dev_addr, 8'he3);
i3c_set_transfer_arg(0, 4);
i3c_set_transfer_cmd(0, 7, 0, 0, 0, 0, 2, 1);
```

如果是真正访问 legacy I2C target，通常还要确认 `DEV_ADDR_TABLE_LOC1[31]` 被设置为 legacy 标志。

### 9.6 如何进入 HDR-DDR 模式

HDR-DDR 的入口是 Broadcast CCC `ENTHDR0`，命令码为 `0x20`。本地 case 用 `i3c_set_transfer_cmd` 把它编码成 command queue entry：

```systemverilog
i3c_set_transfer_cmd(i3c_num, 6, 1, 8'h20, 0, 0, 2, 1);
```

参数含义：

| 参数       | 值       | 说明                                          |
| -------- | ------- | ------------------------------------------- |
| `speed`  | `6`     | controller 按 HDR-DDR 模式执行                   |
| `iscp`   | `1`     | command present，当前 entry 带 CCC/command code |
| `cmd`    | `8'h20` | `ENTHDR0`，进入 HDR-DDR                        |
| `isread` | `0`     | 当前本地 case 走 write                           |
| `tr_id`  | `2`     | transaction id                              |
| `isstop` | `1`     | 当前 task 参数保留，但 task 中 `speed>4` 时不会置 `[31]` |

概念流程：

```text
Bus 处于 SDR 模式
-> Current Master 发送 Broadcast Address 7'h7e + W
-> 发送 ENTHDR0 CCC，code = 0x20
-> 支持 HDR-DDR 的 target 进入 HDR-DDR 模式
-> controller 按 HDR-DDR 规则发送/接收 HDR data word
-> HDR transfer 结束后通过 HDR exit/结束过程回到 SDR 可管理状态
```

本地 HDR-DDR case 的简化流程：

```text
i3c_block_init(i3c_num, 0, 7'h63, 8'he3)
-> i3c_block_enable
-> 等 command queue ready
-> i3c_set_transfer_arg(i3c_num, 4)
-> 等 command queue ready
-> i3c_set_transfer_cmd(i3c_num, 6, 1, 8'h20, 0, 0, 2, 1)
-> 写 TX FIFO
-> 构造 VIP slave transaction
```

验证 HDR-DDR 时要重点看：

| 观察点 | 说明 |
| --- | --- |
| CCC code | `COMMAND_QUEUE_PORT[14:7]` 应为 `8'h20` |
| `iscp` | `COMMAND_QUEUE_PORT[15]` 应为 `1` |
| speed | `COMMAND_QUEUE_PORT[23:21]` 应为 `3'b110` |
| target 能力 | VIP/target 需要支持 HDR-DDR，否则应 NACK 或保持监听 |
| 数据阶段 | 不能按普通 SDR 单沿采样理解，要按 HDR-DDR 规则看 |
| 退出过程 | 结束后总线应能回到 SDR/CCC 可管理状态 |

### 9.7 本地 case 的 CCC 覆盖映射

本地 case 并没有逐条遍历所有 CCC，而是选了几类关键控制路径：活动状态、地址分配、能力/状态类 direct CCC、HDR 入口。

| Case | CCC | Command Queue 参数 | 测试点 |
| --- | --- | --- | --- |
| `i3c0_master_broadcast_ccc_trans_test.sv` | `ENTAS0 = 0x02` | `i3c_set_transfer_cmd(0,0,1,8'h02,0,0,1,1)` | Broadcast CCC 能从 command queue 发出，之后继续 SDR0 private write |
| `i3c0_master_directed_ccc_trans_test.sv` | `ENTAS0 direct = 0x82` | `i3c_set_transfer_cmd(0,0,1,8'h82,0,0,2,1)` | Directed CCC 带 `iscp=1` 和 direct command code，后续数据传输不被破坏 |
| `i3c0_master_setdasa_test.sv` | `SETDASA = 0x87` | `i3c_set_daa_cmd(0,1)` 内部写 `[14:7]=8'h87` | static address 已知时设置 dynamic address，DAT/response queue 状态正确 |
| `i3c0_master_setaasa_test.sv` | `SETAASA = 0x29` | `i3c_set_transfer_cmd(0,0,1,8'h29,0,0,1,1)` | 所有 target 用 static address 作为 dynamic address，后续 DAT 更新和 private transfer 正常 |
| `i3c0_master_mode_hdr_ddr_rate_test.sv` | `ENTHDR0 = 0x20` | `i3c_set_transfer_cmd(0,6,1,8'h20,0,0,2,1)` | 通过 Broadcast CCC 进入 HDR-DDR，`speed=6` 触发 HDR-DDR 数据阶段 |
| Secondary master 预期流 | `GETACCCR = 0x91` | VIP scoreboard 中 `set_ccc=1, ccc='h91` | 检查 controller role request/accept 相关 direct CCC 交互 |
| Timing 信息预期流 | `GETXTIME = 0x99` | VIP 预期中出现 `ccc='h99` | 检查 exchange timing 信息相关 direct CCC/普通事务预期 |

看覆盖时可以这样拆：

```text
协议全集覆盖：看 9.2/9.3 表中每条 CCC 是否有正向/异常/不支持响应。
当前 case 覆盖：看本节映射，主要覆盖地址、活动态、HDR 入口和部分 direct read/write 预期。
```

## 10. IBI、Hot-Join 与 Secondary Master

这三类机制是 I3C 相比 I2C 更“系统化”的地方。

| 机制 | 说明 | 价值 |
| --- | --- | --- |
| IBI | 从设备通过总线主动通知 Master | 不需要额外 interrupt 引脚 |
| Hot-Join | 设备在总线运行后加入并申请地址 | 支持动态上电、按需唤醒 |
| Secondary Master | 当前 Slave 请求成为 Master | 支持更复杂的总线控制模型 |

IBI 常用于传感器数据就绪、阈值触发、状态变化等场景。相比 I2C 中“主机轮询从机”，IBI 能减少无意义访问，降低功耗并提升响应效率。

## 11. I3C 与 I2C 的关键区别

| 对比项     | I2C                                    | I3C                    |
| ------- | -------------------------------------- | ---------------------- |
| 标准来源    | Philips/NXP 传统总线                       | MIPI Alliance          |
| 信号线     | SDA + SCL                              | SDA + SCL              |
| 驱动方式    | 全程开漏                                   | 开漏 + 推挽                |
| 地址方式    | 固定静态地址                                 | 支持动态地址                 |
| 从设备主动通知 | 通常需要额外中断线                              | 支持 IBI                 |
| 热加入     | 非标准核心能力                                | 支持 Hot-Join            |
| 速率      | 常见 100 kHz/400 kHz/1 MHz，HS 可到 3.4 MHz | SDR 可到 12.5 MHz，HDR 更高 |
| 功耗      | 上拉和较慢边沿带来额外消耗                          | 传输效率更高，功耗更低            |
| 兼容性     | 原生 I2C                                 | 向下兼容 I2C               |

一句话理解：I3C 保留 I2C 的两线和兼容性，但通过动态地址、推挽传输、带内中断和高速模式，把它扩展成更适合现代传感器系统的总线。

## 12. 与 UART/SPI/I2C 的简要对比

| 总线 | 通信方式 | 信号线 | 主从关系 | 典型特点 |
| --- | --- | --- | --- | --- |
| UART | 异步串行 | RX、TX、GND | 无固定主从 | 简单、点对点常见 |
| SPI | 同步串行 | SDO、SDI、SCLK、SS | 主从结构 | 速度高，但线多 |
| I2C | 同步串行 | SDA、SCL | 主从结构 | 线少、地址静态、速度有限 |
| I3C | 同步串行 | SDA、SCL | 主从结构 | 线少、动态地址、高速、低功耗 |

![I3C、I2C、SPI 对比](./_assets/i3c_learn/811006-20260219183926228-1641370385.png)

## 13. 验证关注点

结合协议机制，I3C 验证时建议重点关注以下方面：

| 验证方向 | 关注点 |
| --- | --- |
| 寄存器 | 默认值、读写属性、只读寄存器保护、状态位更新 |
| 时钟复位 | APB/功能时钟配置、reset 后重新初始化、通信恢复 |
| 动态地址 | ENTDAA、SETDASA、SETAASA、地址冲突、重复分配 |
| Master 传输 | SDR0~SDR4、HDR-DDR、I2C FM/FM+ 兼容模式 |
| CCC | Broadcast CCC、Directed CCC、命令参数、响应状态 |
| Private Transfer | TX FIFO、RX FIFO、short data、队列状态、数据比对 |
| Slave 模式 | I3C slave/I2C slave 接收与发送、ACK/NACK 行为 |
| IBI | 从设备请求、仲裁、Master ACK/NACK、payload 处理 |
| Hot-Join | 设备加入时机、地址分配、对已有设备无干扰 |
| Secondary Master | 请求、授权、总线所有权切换、状态更新 |
| DMA | FIFO 与 memory 间搬运、方向、长度、完成中断、数据一致性 |
| Debug port | CBB REG 状态、总线状态、异常场景下可观测性 |

## 14. 结合 Case 的测试点拆解

协议学习最终要落到 case 里，需要把每个协议机制对应到“配置了什么、触发了什么、检查了什么”。当前 `test_case/i3c_test` 里的 case 可以按下面几条验证主线理解。

### 14.1 Master 传输与速率模式

| case                                    | 协议点                | 关键配置                                                         | 主要测试点                                                 |
| --------------------------------------- | ------------------ | ------------------------------------------------------------ | ----------------------------------------------------- |
| `i3c0_master_mode_sdr0_rate_test.sv`    | SDR0 private write | `dev_addr=7'h63`，dynamic `8'h64`，`speed=0`，`transfer_arg=16` | DUT 作为 master 完成 SDR0 写传输，TX FIFO 数据能被 VIP slave 正确接收 |
| `i3c0_master_mode_sdr1_rate_test.sv`    | SDR1 private write | `speed=1`，`i3c_set_scl_timing(0,1)`                          | SDR1 timing 配置后，command queue 和数据发送路径正常               |
| `i3c0_master_mode_sdr2_rate_test.sv`    | SDR2 private write | `speed=2`                                                    | SDR2 模式下数据一致性                                         |
| `i3c0_master_mode_sdr3_rate_test.sv`    | SDR3 private write | `speed=3`                                                    | SDR3 模式下 SCL 扩展 timing 与传输正确性                         |
| `i3c0_master_mode_sdr4_rate_test.sv`    | SDR4 private write | `speed=4`                                                    | SDR4 模式下高速 SDR 传输正确性                                  |
| `i3c0_master_mode_hdr_ddr_rate_test.sv` | HDR-DDR            | `speed=6`，`iscp=1`，`cmd=8'h20`                               | 进入 HDR-DDR 相关命令后，HDR 模式传输可执行                          |
| `i3c0_master_mode_i2c_fm_rate_test.sv`  | I2C FM 兼容          | `speed=7`                                                    | I3C controller 以 I2C FM 兼容方式访问目标设备                    |

这组 case 的学习重点是：I3C 的“速率/模式”不是只改 VIP timing，而是通过 `i3c_set_scl_timing` 和 `i3c_set_transfer_cmd` 的 `speed` 字段共同驱动。真正启动传输的是写 `COMMAND_QUEUE_PORT`，数据通路则由 `TX_DATA_PORT/RX_DATA_PORT` 承载。

典型配置路径：

```text
i3c_set_scl_timing
-> i3c_block_init
-> i3c_block_enable
-> i3c_set_daa_cmd 或 CCC 前置命令
-> 等 INTR_STATUS[3] command queue ready
-> i3c_set_transfer_arg
-> i3c_set_transfer_cmd
-> FIFO/DMA 数据搬运
-> scoreboard 比对
```

### 14.2 地址分配与 CCC 命令

I3C 相比 I2C 的一个核心增强是动态地址和 CCC。对应 case 主要覆盖 SETDASA、SETAASA、broadcast CCC 和 directed CCC。

| case | CCC/地址机制 | 命令参数 | 检查点 |
| --- | --- | --- | --- |
| `i3c0_master_setdasa_test.sv` | SETDASA/DAA 类流程 | `i3c_set_daa_cmd(0,1)`，内部 `cmd=8'h87` | DAT 中目标 static/dynamic address 配置后，slave 能按动态地址参与后续传输 |
| `i3c0_master_setaasa_test.sv` | SETAASA | `cmd=8'h29` | response queue 有响应，DAT 更新后继续 private transfer |
| `i3c0_master_broadcast_ccc_trans_test.sv` | Broadcast CCC | `iscp=1`，`cmd=8'h02` | 广播 CCC 后仍能继续普通 write 数据传输 |
| `i3c0_master_directed_ccc_trans_test.sv` | Directed CCC | `iscp=1`，`cmd=8'h82` | 定向 CCC 只针对目标设备生效，后续数据通路正确 |

从 case 角度看，CCC 的关键测试点有三个：

| 测试点 | 观察方式 |
| --- | --- |
| command queue 字段拼接正确 | `COMMAND_QUEUE_PORT[15]=iscp`，`[14:7]=cmd`，`[23:21]=speed` |
| response queue 有有效响应 | 轮询 `INTR_STATUS[4]` 后读 `RESPONSE_QUEUE_PORT` |
| 地址表被正确用于后续访问 | 读写 `DEV_ADDR_TABLE_LOC1`，重点看 `[6:0]` static address 和 `[23:16]` dynamic address |

### 14.3 FIFO、Short Data 与数据一致性

I3C 数据通路验证不只是看总线波形，还要看 FIFO 阈值、状态位和 scoreboard 数据是否一致。

| case | 数据路径 | 关键参数 | 测试点 |
| --- | --- | --- | --- |
| `i3c0_master_transmit_withtxfifo_test.sv` | DUT master -> TX FIFO -> VIP slave | `transfer_arg=4`，`i3c_wirte_data_to_txfifo(0,1,1,tx_data_q)` | TX FIFO 可写状态、1 word 数据发送、VIP slave observed 数据一致 |
| `i3c0_master_transmit_withrxfifo_test.sv` | VIP slave -> RX FIFO -> DUT master | `isread=1`，`transfer_arg=4` | RX FIFO 有数据后，DUT 读出的 byte queue 与 VIP 数据一致 |
| `i3c0_master_transmit_withshortdata_test.sv` | command queue short data | `isshortarg=1`，short data `55 aa ff` | 不经过普通 TX FIFO，短数据直接随 command queue 发出 |

FIFO 类 case 的共同检查方法：

| 状态/接口 | 含义 |
| --- | --- |
| `INTR_STATUS[0]` | TX FIFO 可写，case 才继续写 `TX_DATA_PORT` |
| `INTR_STATUS[1]` | RX FIFO 有数据，case 才读 `RX_DATA_PORT` |
| `DATA_BUFFER_THLD_CTRL[2:0]` | TX empty threshold |
| `DATA_BUFFER_THLD_CTRL[10:8]` | RX buffer threshold |
| `DATA_BUFFER_THLD_CTRL[18:16]` | TX start threshold |
| `tx_data_q/rx_data_q` | TB 保存的 byte 级期望数据，最终送 scoreboard |

### 14.4 Slave 模式与主从方向切换

Slave 类 case 的重点是 DUT 不再通过 `i3c_block_init` 进入 master mode，而是直接写寄存器进入 slave mode。

| case | DUT 角色 | VIP 行为 | 关键配置 | 测试点 |
| --- | --- | --- | --- | --- |
| `i3c0_slave_receive_trans_test.sv` | I3C slave receive | VIP master write | `DEVICE_CTRL_EXTENDED=1`，`DEVICE_ADDR=0x8031` | DUT slave 能接收 VIP master 写入数据 |
| `i3c0_slave_transmit_trans_test.sv` | I3C slave transmit | VIP master read | `cmd=8'h87`，TX FIFO 写 1 word | DUT slave 能响应 master read 并发送数据 |
| `i2c0_slave_receive_trans_test.sv` | I2C slave receive | VIP I2C/master write | I2C legacy 兼容配置 | I2C 模式下 slave 接收路径可用 |
| `i2c0_slave_transmit_trans_test.sv` | I2C slave transmit | VIP I2C/master read | I2C FM/FM+ 相关 speed | I2C 兼容发送路径可用 |

Slave 初始化测试点：

| 寄存器/字段 | 典型值 | 作用 |
| --- | --- | --- |
| `MCUSS_I3C0_STAT[18]` | `1` | 使能 SCU 侧 static address 配置 |
| `MCUSS_I3C0_STAT[17:11]` | `7'h31` | DUT slave static address |
| `DEVICE_CTRL_EXTENDED` | `1` | 选择 slave mode |
| `DEVICE_ADDR[6:0]` | `7'h31` | slave static address |
| `DEVICE_ADDR[15]` | `1` | static address valid |
| `DEVICE_CTRL[31]` | `1` | enable controller |

### 14.5 DMA 数据搬运

DMA case 验证的是 I3C FIFO 与 SRAM 之间的数据通路，不只是 I3C 协议本身。

| case | DMA 方向 | DMA 配置 | I3C 配置 | 检查点 |
| --- | --- | --- | --- | --- |
| `i3c0_trans_txfifo_to_mem_withdma_test.sv` | SRAM -> I3C TX FIFO | `src=SRAM+0x4000`，`dst=I3C0_BASE+TX_DATA_PORT`，`dst_per=7'h1e` | `transfer_arg=8`，write | SRAM 中 8 byte 经 DMA 进入 TX FIFO，VIP slave 收到一致数据 |
| `i3c0_trans_rxfifo_to_mem_withdma_test.sv` | I3C RX FIFO -> SRAM | `src=I3C0_BASE+RX_DATA_PORT`，`dst=SRAM+0x4000`，`src_per=7'h1f` | `isread=1`，`transfer_arg=4` | VIP slave 提供的数据经 RX FIFO 和 DMA 写入 SRAM |
| `i3c1_trans_txfifo_to_mem_withdma_test.sv` | I3C1 TX DMA | `dst=I3C1_BASE+TX_DATA_PORT`，`dst_per=7'h0` | I3C1 TX request 编号为 0 | SRAM 数据经 DMA 写入 I3C1 TX FIFO |
| `i3c1_trans_rxfifo_to_mem_withdma_test.sv` | I3C1 RX DMA | `src=I3C1_BASE+RX_DATA_PORT`，`src_per=7'h1` | I3C1 RX request 编号为 1 | I3C1 RX FIFO 数据经 DMA 写入 SRAM |

DMA 的学习重点是区分两套长度：`transfer_arg` 描述 I3C 传输字节数，DMA sequence 的 burst/width 描述 AXI/DMA 搬运方式。两者不一致时，容易出现总线传输完成但 memory 数据不完整，或 DMA 搬运多余数据的问题。

### 14.6 Secondary Master、IBI 与事件状态

`i3c0_slave_to_secmaster_test.sv` 是最能体现 I3C 系统特性的 case。DUT 初始是 slave，随后通过 master request/IBI 相关流程请求总线控制权。

| 阶段 | 关键寄存器/状态 | 测试点 |
| --- | --- | --- |
| slave 初始化 | `DEVICE_CTRL_EXTENDED=1`，`DEVICE_ADDR=0x8031` | DUT 先作为 slave 挂在总线上 |
| 动态地址完成 | `INTR_STATUS[8]` | 确认地址分配或 SETDASA 流程完成 |
| Master Request 能力 | `SLV_EVENT_STATUS[1]` | 当前 master 是否允许 slave 发起 MR |
| 发起 MR | `SLV_INTR_REQ[3]=1` | DUT slave 主动请求成为 master |
| IBI 更新 | `INTR_STATUS[12]` | IBI/MR 请求流程被硬件处理 |
| ACK/NACK | `SLV_INTR_REQ[9:8]` | `2'b01` 表示 MR ACK |
| bus owner 切换 | `INTR_STATUS[13]` | 总线所有权切换完成 |
| resume | `DEVICE_CTRL[30]=1` | DUT 以新状态继续发起传输 |

这个 case 对学习 I3C 很有价值：它把 IBI、Secondary Master、bus ownership、普通 private transfer 串成了一条完整链路。

### 14.7 CPU 中断链路

`i3c0_intr_test.sv` 和 `i3c0_intr_test/main.c` 是软硬件协同验证。SV 侧负责启动 VIP master，C 侧负责配置 I3C slave 和 PLIC 中断。

| 配置点              | 典型值                       | 测试意义                            |
| ---------------- | ------------------------- | ------------------------------- |
| `i3c_scb_ctrl`   | `3'h6`                    | scoreboard 按中断场景解释              |
| `i3c_num_ctrl`   | I3C0 为 `'h3`，I3C1 为 `'h4` | 区分 I3C0/I3C1 CPU interrupt case |
| `INTR_STATUS_EN` | `0xffff`                  | 打开 I3C 状态中断                     |
| `INTR_SIGNAL_EN` | `0x2`                     | 打开 RX 相关中断信号                    |
| `DEVICE_ADDR`    | `0x8031`                  | static address `0x31` + valid   |
| handler 读取       | `RX_DATA_PORT`            | CPU handler 从 RX FIFO 取数据       |
| 期望数据             | `0x998855aa`、`0xaa558899` | 软件侧最终 pass/fail 判断              |

这类 case 的测试点可以总结为：VIP master 写数据后，I3C RX 事件要能变成 PLIC 中断，CPU handler 要能读到 FIFO 数据，软件最终要能判断数据正确。

### 14.8 Reg、Reset、Clock、Debug 可观测性

协议数据 case 能证明功能路径，但调试和量产验证还需要寄存器、复位、时钟和 debug port。

| case | 测试点 | 学习价值 |
| --- | --- | --- |
| `i3c0_reg_test.sv`、`i3c1_reg_test.sv` | reset value、RW mask、只读/保留位保护 | 判断寄存器模型和 RTL 实现是否一致 |
| `i3c0_rstn_test.sv`、`i3c1_rstn_test.sv` | reset 后状态恢复、重新初始化 | 验证异常恢复和复位清理能力 |
| `i3c0_clk_test.sv`、`i3c1_clk_test.sv` | clock gating/ungating 后访问和传输 | 验证低功耗或时钟控制路径 |
| `i3c0_debug_port_test.sv`、`i3c1_debug_port_test.sv` | SCU debug port 映射内部信号 | debug fail 时确认内部状态是否可观测 |

这些 case 不一定直接覆盖 I3C 总线波形，但它们决定了真实项目里“出问题时能不能定位”和“复位/低功耗后能不能恢复”。

## 15. Case 测试点与协议机制对应表

| 协议机制              | 目标行为                                      | 对应 case                                                  | 关键观察点                                                 |
| ----------------- | ----------------------------------------- | -------------------------------------------------------- | ----------------------------------------------------- |
| 动态地址              | static address 转 dynamic address，DAT 正确生效 | `master_setdasa`、`master_setaasa`、SDR rate case          | `DEV_ADDR_TABLE_LOC1`、`INTR_STATUS[4]`、后续传输地址         |
| CCC               | Broadcast/Directed CCC 被正确编码和响应           | `master_broadcast_ccc_trans`、`master_directed_ccc_trans` | `COMMAND_QUEUE_PORT[15]`、`cmd[14:7]`、response queue   |
| SDR private write | Master 写数据到 slave                         | SDR0~SDR4、TXFIFO、DMA TX                                  | `TX_DATA_PORT`、`INTR_STATUS[0]`、VIP slave observed    |
| SDR private read  | Master 从 slave 读数据                        | RXFIFO、DMA RX                                            | `RX_DATA_PORT`、`INTR_STATUS[1]`、VIP slave/source data |
| HDR-DDR           | 进入 HDR 相关传输模式                             | `master_mode_hdr_ddr_rate`                               | `speed=6`、`cmd=8'h20`                                 |
| I2C 兼容            | I3C controller 访问 legacy I2C              | I2C FM/FM+、I2C slave case                                | `isi2c_mode`、legacy address、`speed=7`                 |
| Slave 模式          | DUT 被 VIP master 访问                       | slave receive/transmit                                   | `DEVICE_CTRL_EXTENDED=1`、`DEVICE_ADDR=0x8031`         |
| Secondary Master  | slave 请求并获得 bus owner                     | `slave_to_secmaster`                                     | `SLV_INTR_REQ`、`INTR_STATUS[12/13]`                   |
| 中断                | I3C RX 事件触发 CPU handler                   | `intr_test` + `main.c`                                   | `INTR_SIGNAL_EN`、PLIC handler、RX FIFO 数据              |
| DMA               | FIFO 与 SRAM 数据一致                          | DMA TX/RX case                                           | DMA src/dst address、peripheral number、SRAM readback   |
| Debug             | 内部状态映射到 SCU debug port                    | debug port case                                          | debug high/low register                               |
| Reset/Clock       | reset/clock 后功能可恢复                        | rstn/clk case                                            | reset 后寄存器、clock 后访问路径                                |

## 16. 学习抓手

理解 I3C 可以按下面这条线走：

1. 先把它看成“兼容 I2C 的两线总线”。
2. 再抓住三个增强点：动态地址、推挽高速传输、带内事件。
3. 然后理解三类核心消息：SDR 普通传输、HDR 高速传输、CCC 控制命令。
4. 最后把 IBI、Hot-Join、Secondary Master 放到系统场景里理解。

如果用于验证工作，最重要的是把“配置路径、地址路径、数据路径、事件路径、异常路径”拆开验证：配置路径看寄存器和 reset，地址路径看 DAA/CCC，数据路径看 FIFO/DMA/速率，事件路径看 IBI/中断，异常路径看 NACK、错误状态和 debug 可观测性。
