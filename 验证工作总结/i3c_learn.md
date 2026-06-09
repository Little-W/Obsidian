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

![I3C 总线拓扑](assets/i3c_learn/811006-20260219182746650-2085676287.png)

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

![BCR 位域说明](assets/i3c_learn/811006-20260219183456321-898848573.png)

典型动态地址流程：

1. Current Master 发送广播 CCC，进入动态地址分配流程。
2. 总线上的 I3C Slave 根据自身 ID/能力参与仲裁。
3. Master 依次识别设备并分配动态地址。
4. Slave 获得动态地址后，后续使用动态地址响应 I3C 访问。

常见命令：

| 命令 | 作用 |
| --- | --- |
| ENTDAA | 进入动态地址分配流程 |
| SETDASA | 基于静态地址设置动态地址 |
| SETAASA | 将静态地址作为动态地址使用，常用于简化配置场景 |

## 6. I3C 地址类型

I3C 总线上常见三类地址：

| 地址类型 | 说明 |
| --- | --- |
| 静态地址 | 传统 I2C 或未分配动态地址前的 I3C 设备使用 |
| 广播地址 | I3C 广播命令使用，常见为 `0x7E` |
| 动态地址 | I3C Master 分配给 Slave 的运行时地址 |

![I3C/I2C 地址头对比](assets/i3c_learn/811006-20260219183609062-492957670.png)

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

| 类型 | 用途 |
| --- | --- |
| SDR | 默认模式，常用于 private read/write 和普通控制传输 |
| HDR | 高速模式，包括 DDR、TSP、TSF 等变体 |
| CCC | 通用命令，用于广播控制、动态地址分配、事件管理等 |
| IBI | 从设备主动发起带内中断请求 |
| Hot-Join | 新设备加入总线并请求地址分配 |
| Secondary Master Request | 具备 Master 能力的 Slave 请求成为主控 |

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

![Broadcast CCC 传输格式](assets/i3c_learn/811006-20260219183805323-1473190710.png)

定向 CCC 会在广播或寻址之后指定目标设备，只让目标设备执行对应命令。

## 10. IBI、Hot-Join 与 Secondary Master

这三类机制是 I3C 相比 I2C 更“系统化”的地方。

| 机制 | 说明 | 价值 |
| --- | --- | --- |
| IBI | 从设备通过总线主动通知 Master | 不需要额外 interrupt 引脚 |
| Hot-Join | 设备在总线运行后加入并申请地址 | 支持动态上电、按需唤醒 |
| Secondary Master | 当前 Slave 请求成为 Master | 支持更复杂的总线控制模型 |

IBI 常用于传感器数据就绪、阈值触发、状态变化等场景。相比 I2C 中“主机轮询从机”，IBI 能减少无意义访问，降低功耗并提升响应效率。

## 11. I3C 与 I2C 的关键区别

| 对比项 | I2C | I3C |
| --- | --- | --- |
| 标准来源 | Philips/NXP 传统总线 | MIPI Alliance |
| 信号线 | SDA + SCL | SDA + SCL |
| 驱动方式 | 全程开漏 | 开漏 + 推挽 |
| 地址方式 | 固定静态地址 | 支持动态地址 |
| 从设备主动通知 | 通常需要额外中断线 | 支持 IBI |
| 热加入 | 非标准核心能力 | 支持 Hot-Join |
| 速率 | 常见 100 kHz/400 kHz/1 MHz，HS 可到 3.4 MHz | SDR 可到 12.5 MHz，HDR 更高 |
| 功耗 | 上拉和较慢边沿带来额外消耗 | 传输效率更高，功耗更低 |
| 兼容性 | 原生 I2C | 向下兼容 I2C |

一句话理解：I3C 保留 I2C 的两线和兼容性，但通过动态地址、推挽传输、带内中断和高速模式，把它扩展成更适合现代传感器系统的总线。

## 12. 与 UART/SPI/I2C 的简要对比

| 总线 | 通信方式 | 信号线 | 主从关系 | 典型特点 |
| --- | --- | --- | --- | --- |
| UART | 异步串行 | RX、TX、GND | 无固定主从 | 简单、点对点常见 |
| SPI | 同步串行 | SDO、SDI、SCLK、SS | 主从结构 | 速度高，但线多 |
| I2C | 同步串行 | SDA、SCL | 主从结构 | 线少、地址静态、速度有限 |
| I3C | 同步串行 | SDA、SCL | 主从结构 | 线少、动态地址、高速、低功耗 |

![I3C、I2C、SPI 对比](assets/i3c_learn/811006-20260219183926228-1641370385.png)

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

| case | 协议点 | 关键配置 | 主要测试点 |
| --- | --- | --- | --- |
| `i3c0_master_mode_sdr0_rate_test.sv` | SDR0 private write | `dev_addr=7'h63`，dynamic `8'h64`，`speed=0`，`transfer_arg=16` | DUT 作为 master 完成 SDR0 写传输，TX FIFO 数据能被 VIP slave 正确接收 |
| `i3c0_master_mode_sdr1_rate_test.sv` | SDR1 private write | `speed=1`，`i3c_set_scl_timing(0,1)` | SDR1 timing 配置后，command queue 和数据发送路径正常 |
| `i3c0_master_mode_sdr2_rate_test.sv` | SDR2 private write | `speed=2` | SDR2 模式下数据一致性 |
| `i3c0_master_mode_sdr3_rate_test.sv` | SDR3 private write | `speed=3` | SDR3 模式下 SCL 扩展 timing 与传输正确性 |
| `i3c0_master_mode_sdr4_rate_test.sv` | SDR4 private write | `speed=4` | SDR4 模式下高速 SDR 传输正确性 |
| `i3c0_master_mode_hdr_ddr_rate_test.sv` | HDR-DDR | `speed=6`，`iscp=1`，`cmd=8'h20` | 进入 HDR-DDR 相关命令后，HDR 模式传输可执行 |
| `i3c0_master_mode_i2c_fm_rate_test.sv` | I2C FM 兼容 | `speed=7` | I3C controller 以 I2C FM 兼容方式访问目标设备 |

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
| `i3c1_trans_txfifo_to_mem_withdma_test.sv` | I3C1 TX DMA | `dst=I3C1_BASE+TX_DATA_PORT`，`dst_per=7'h0` | I3C1 对称流程 | I3C1 DMA request mapping 是否正确 |
| `i3c1_trans_rxfifo_to_mem_withdma_test.sv` | I3C1 RX DMA | `src=I3C1_BASE+RX_DATA_PORT` | I3C1 read | I3C1 RX DMA 搬运正确 |

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

| 配置点 | 典型值 | 测试意义 |
| --- | --- | --- |
| `i3c_scb_ctrl` | `3'h6` | scoreboard 按中断场景解释 |
| `i3c_num_ctrl` | I3C0 为 `'h3`，I3C1 为 `'h4` | 区分 I3C0/I3C1 CPU interrupt case |
| `INTR_STATUS_EN` | `0xffff` | 打开 I3C 状态中断 |
| `INTR_SIGNAL_EN` | `0x2` | 打开 RX 相关中断信号 |
| `DEVICE_ADDR` | `0x8031` | static address `0x31` + valid |
| handler 读取 | `RX_DATA_PORT` | CPU handler 从 RX FIFO 取数据 |
| 期望数据 | `0x998855aa`、`0xaa558899` | 软件侧最终 pass/fail 判断 |

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

| 协议机制 | 目标行为 | 对应 case | 关键观察点 |
| --- | --- | --- | --- |
| 动态地址 | static address 转 dynamic address，DAT 正确生效 | `master_setdasa`、`master_setaasa`、SDR rate case | `DEV_ADDR_TABLE_LOC1`、`INTR_STATUS[4]`、后续传输地址 |
| CCC | Broadcast/Directed CCC 被正确编码和响应 | `master_broadcast_ccc_trans`、`master_directed_ccc_trans` | `COMMAND_QUEUE_PORT[15]`、`cmd[14:7]`、response queue |
| SDR private write | Master 写数据到 slave | SDR0~SDR4、TXFIFO、DMA TX | `TX_DATA_PORT`、`INTR_STATUS[0]`、VIP slave observed |
| SDR private read | Master 从 slave 读数据 | RXFIFO、DMA RX | `RX_DATA_PORT`、`INTR_STATUS[1]`、VIP slave/source data |
| HDR-DDR | 进入 HDR 相关传输模式 | `master_mode_hdr_ddr_rate` | `speed=6`、`cmd=8'h20` |
| I2C 兼容 | I3C controller 访问 legacy I2C | I2C FM/FM+、I2C slave case | `isi2c_mode`、legacy address、`speed=7` |
| Slave 模式 | DUT 被 VIP master 访问 | slave receive/transmit | `DEVICE_CTRL_EXTENDED=1`、`DEVICE_ADDR=0x8031` |
| Secondary Master | slave 请求并获得 bus owner | `slave_to_secmaster` | `SLV_INTR_REQ`、`INTR_STATUS[12/13]` |
| 中断 | I3C RX 事件触发 CPU handler | `intr_test` + `main.c` | `INTR_SIGNAL_EN`、PLIC handler、RX FIFO 数据 |
| DMA | FIFO 与 SRAM 数据一致 | DMA TX/RX case | DMA src/dst address、peripheral number、SRAM readback |
| Debug | 内部状态映射到 SCU debug port | debug port case | debug high/low register |
| Reset/Clock | reset/clock 后功能可恢复 | rstn/clk case | reset 后寄存器、clock 后访问路径 |

## 16. 学习抓手

理解 I3C 可以按下面这条线走：

1. 先把它看成“兼容 I2C 的两线总线”。
2. 再抓住三个增强点：动态地址、推挽高速传输、带内事件。
3. 然后理解三类核心消息：SDR 普通传输、HDR 高速传输、CCC 控制命令。
4. 最后把 IBI、Hot-Join、Secondary Master 放到系统场景里理解。

如果用于验证工作，最重要的是把“配置路径、地址路径、数据路径、事件路径、异常路径”拆开验证：配置路径看寄存器和 reset，地址路径看 DAA/CCC，数据路径看 FIFO/DMA/速率，事件路径看 IBI/中断，异常路径看 NACK、错误状态和 debug 可观测性。
