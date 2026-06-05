# I2C DUT Register Document

## 2026-05-24 slave OE 调试更新

针对 “DUT 没有配置好导致 `ic_data_oe` 不响应 ACK” 的疑问，当前 `slave_smoke` 已切换为 pure target-only 默认配置：

| 项目 | 当前默认值 | 目的 |
|---|---:|---|
| `+I2C_TARGET_KEEP_MASTER` | `0` | 让 `IC_CON[0] MASTER_MODE=0`，去掉 controller/master engine 对 target ACK/OE 路径的潜在影响 |
| `IC_CON` standard mode 期望 | `0x00000022` | `SPEED=standard`、`IC_RESTART_EN=1`、`IC_10BITADDR_SLAVE=0`、`IC_SLAVE_DISABLE=0`、`MASTER_MODE=0` |
| `IC_SAR` | `0x00000055` | DUT slave 7-bit 地址，VIP master write address byte 为 `0xaa` |
| `IC_TAR` | `0x00000056` | 仅用于避免 dual-role A/B 时 `IC_TAR[6:0] == IC_SAR[6:0]`，pure target-only 下不作为 ACK 必要条件 |
| `IC_ENABLE` | 先 `0x00080000`，再 `0x00080001` | 尝试打开 multi-SAR 场景下的 `IC_SAR_EN`，再 enable DUT；若 bit19 不存在读回 0，不单独判定失败 |

判定方式：

- 如果 log 中 `I2C_TARGET_MODE_ON` 显示 `IC_CON=0x00000022`、`SLAVE_DISABLE=0`、`10BIT_SLAVE=0`、`IC_SAR=0x055`、`IC_ENABLE_STATUS[0]=1`、top-level `ic_en=1`，则基础 slave/target 配置已经成立；此时 `slave_addressed/rx_ack_valid` 已拉高但 `ic_data_oe` 仍不动，更像是 DUT 内部 ACK 到 pad/OE 输出路径、OE 极性/门控、或 wrapper 连接问题。
- 如果 `IC_CON[0]` 无法被清成 `0`，或 `IC_CON[6]` 读回为 `1`，或 `IC_CON[3]` 读回为 `1`，则才应优先归因到 DUT 配置/生成参数不支持当前 slave 访问。
- 若需要和之前 dual-role 配置对比，可在 case 中改回 `+I2C_TARGET_KEEP_MASTER=1`，standard mode 下期望 `IC_CON=0x00000023`。
- 当前 `slave_smoke.tc` 增加 `+I2C_DUT_PAD_ACK_BRIDGE_MAX=3` 和 `+I2C_DUT_PAD_ACK_BRIDGE_LOG_DATA_ACKS=3`。下一轮 log 应看到 `TB_I2C_DUT_ACK_BRIDGE data_ack index=1/2/3 byte=0x21/0x43/0x65`。如果这些 data ACK 存在且 `I2C_VIP_MASTER_RSP ack=1,1,1`，但最终仍 `RXFLR=0/RFNE=0`，说明总线侧事务已完整，DUT 内部 target receiver 没有把 data byte 推入 RX FIFO，优先查 DUT `ic_data_in_a` 数据相位采样、target RX FSM、RX FIFO push 条件，而不是 APB smoke 的读写流程。

来源：用户提供的 DW_apb_i2c Databook 截图，Version 2.04a，April 2023。

适用 DUT：`MCU_I2C_WRAPPER` 内部 I2C 控制器寄存器。  
总线：APB。  
寄存器块：`DW_apb_i2c address block` / `DW_apb_i2c_addr_block1`。  
默认存在性：截图中 register map 标注 `Exists: Always`。逐字段存在性以字段表为准。

说明：
- 本文只整理截图中可见的信息。
- 没有提供字段表的寄存器，字段细节标记为“文档未说明”。
- SMBus 相关寄存器保留在表中，但当前 I2C TB 主流程不启用 SMBus。
- `IC_CON` 写入限制：该寄存器只能在 `DW_apb_i2c` disabled 时写入，即 `IC_ENABLE[0] = 0`；在其他时间写入无效。

## 0. Top Level Parameters / 配置参数补充

来源：用户补充的 DW_apb_i2c Databook 3.2、3.3、3.4、3.5 截图。  
注意：下表是 DW_apb_i2c 可配置参数定义及 databook 默认值，不等同于 `MCU_I2C_WRAPPER` 当前 RTL 的实际生成参数。当前本地工程没有展开 `MCU_I2C_WRAPPER` 内部 RTL 参数，`vcs_com/rtl.f` 中 `mcu_i2c_wrapper.f` 仍为注释状态，因此无法仅从工程文件确认 `IC_MASTER_MODE`、`IC_SLAVE_DISABLE`、`IC_10BITADDR_SLAVE` 等生成参数的实际值；未能从 RTL parameter、生成报告或 `IC_COMP_PARAM_1` 字段解码得到的项目统一标记为“文档未说明”。如果 `IC_ADD_ENCODED_PARAMS=1`，理论上 `IC_COMP_PARAM_1` 可帮助 software 识别配置，但本次截图没有提供 `IC_COMP_PARAM_1` 的字段位定义，因此当前 TB 只打印 raw value，不能可靠 decode 每个参数。

### 0.1 与 DUT Slave/Target ACK 直接相关的参数

| 参数名 | Label | 影响寄存器/字段 | Values | Databook Default | Enabled | 对当前 slave smoke 的影响 | 当前确认方式 / DUT 实际值 |
|---|---|---|---|---|---|---|---|
| `IC_DEFAULT_SLAVE_ADDR` | Has I2C default target device address of? | `IC_SAR[9:0]` reset value | `0x000` ... `0x3ff`；默认值不能落在 reserved address `0x00` to `0x07` 或 `0x78` to `0x7f` | `0x055` | Always | DUT 作为 target/slave 时的主 target address reset 值。当前 case 会显式写 `IC_SAR=+I2C_TARGET_ADDR`，默认 `0x055`，并读回确认；7-bit 总线地址 byte 应为 write `0xaa`、read `0xab`。 | RTL reset 实际值文档未说明；运行时以 `I2C_TARGET_CFG_WRITTEN` / `I2C_TARGET_MODE_ON` 中 `IC_SAR=0x00000055`、`target_addr=0x055` 为准 |
| `IC_DEFAULT_SLAVE_ADDR2` | Has I2C default target device address 2 of? | `IC_SAR2[9:0]` reset value | `0x000` ... `0x3ff`；同样不能使用 reserved address | `0x056` | `(IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 2)` | multi-SAR enabled 时可作为第二 target address。当前 smoke 不使用。 | 文档未说明 |
| `IC_DEFAULT_SLAVE_ADDR3` | Has I2C default target device address 3 of? | `IC_SAR3[9:0]` reset value | `0x000` ... `0x3ff`；同样不能使用 reserved address | `0x057` | `(IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 3)` | multi-SAR enabled 时可作为第三 target address。当前 smoke 不使用。 | 文档未说明 |
| `IC_DEFAULT_SLAVE_ADDR4` | Has I2C default target device address 4 of? | `IC_SAR4[9:0]` reset value | `0x000` ... `0x3ff`；同样不能使用 reserved address | `0x058` | `(IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 4)` | multi-SAR enabled 时可作为第四 target address。当前 smoke 不使用。 | 文档未说明 |
| `IC_MASTER_MODE` | Is an I2C Controller? | `IC_CON[0] MASTER_MODE` reset value | false `0x0`；true `0x1` | true | Always | 该 bit 控制 controller/master engine 是否 enabled；target/slave 响应主要由 `IC_SLAVE_DISABLE=0` 控制。当前 slave smoke 默认使用 `+I2C_TARGET_KEEP_MASTER=0`，即 pure target-only；若要和 controller/master engine 同时开启的 dual-role 配置对比，可显式加 `+I2C_TARGET_KEEP_MASTER=1`。 | RTL reset 实际值文档未说明；当前 case 以 `I2C_TARGET_KEEP_MASTER` 的期望值检查 `IC_CON[0]` |
| `IC_SLAVE_DISABLE` | Disable Target after reset? | `IC_CON[6] IC_SLAVE_DISABLE` reset value | false `0x0`；true `0x1` | true | Always | 若为 `1`，reset 后 target interface disabled。要 ACK slave address，software 必须在 `IC_ENABLE[0]=0` 时写 `IC_CON[6]=0`。如果写后读回仍为 `1`，DUT target/slave 没开启，VIP master 发 `0x55` 必然 NACK。 | RTL reset 实际值文档未说明；slave mode 运行时必须看到 `IC_CON[6]=0`，否则地址 ACK 不成立 |
| `IC_10BITADDR_SLAVE` | Supports 10-bit addressing in target mode? | `IC_CON[3] IC_10BITADDR_SLAVE` reset value | false `0x0`；true `0x1` | `(IC_SMBUS == 1) ? 0 : 1` | `IC_SMBUS == 0` | 当前 VIP master 用 7-bit address `0x55`，所以 target mode 必须写并读回 `IC_CON[3]=0`。如果写后读回为 `1`，DUT 按 10-bit target address 匹配，7-bit `0x55` 不会 ACK。 | RTL reset 实际值文档未说明；slave mode 运行时必须看到 `IC_CON[3]=0` |
| `IC_DEFAULT_TAR_SLAVE_ADDR` | Has I2C default target address of? | `IC_TAR[9:0]` reset value | `0x000` ... `0x3ff`；不能使用 reserved address | `0x055` | Always | DUT 作为 controller/master 时使用的 remote target address reset 值。当前 slave smoke 默认 pure target-only，但仍显式写 `IC_TAR=+I2C_CONTROLLER_TAR_ADDR`，默认 `0x056`，便于切到 `+I2C_TARGET_KEEP_MASTER=1` 做 dual-role A/B 时避免 `IC_TAR[6:0] == IC_SAR[6:0]` 触发 controller self-address 限制。 | 文档未说明；运行时以 `I2C_TARGET_CFG` 中 `IC_TAR`、`IC_SAR`、`TAR_EQ_SAR7` 为准 |
| `IC_MULTI_SAR_EN` | 文档截图未直接给出 | `IC_ENABLE[19] IC_SAR_EN` 及 `IC_SAR2/3/4` 存在性 | 文档未说明 | 文档未说明 | 文档未说明 | 如果 multi-SAR enabled，`IC_ENABLE[19]=1` 才使 `IC_SAR` 地址参与 ACK；如果 multi-SAR disabled，该 bit 可能不存在或读 0。当前 case 先写 `IC_ENABLE=0x00080000`，再写 `0x00080001`，并在读回 `IC_ENABLE[19]=0` 时只 warning，不把它单独作为 slave mode 失败条件。 | 文档未说明；当前 log 观察到 `IC_ENABLE[19]=0`，但由于 `IC_MULTI_SAR_EN` 实际生成值未知，不能仅凭该 bit 判定 slave mode 未开启 |
| `IC_SLV_DATA_NACK_ONLY` | Generate Target Data NACK Register | target/slave 数据阶段 NACK 控制 | 字段细节文档未说明 | 文档未说明 | 文档未说明 | 该寄存器不决定地址匹配，但若配置为 data NACK，可能出现地址 ACK 后数据字节 NACK。当前 slave smoke 在 disabled 配置阶段写 `0` 并按 bit0 读回，避免软件侧主动 NACK 数据。 | 字段细节文档未说明；TB 运行时以 `I2C_REG_CHECK IC_SLV_DATA_NACK_ONLY` 的读回为准 |

### 0.2 当前 TB 对 DUT Slave/Target Mode 的判定

`seq_lib/i2c_seq/i2c_slave_smoke_seq.sv` 在发起 VIP master 访问前会做三段确认：

1. `before target config`：在 `IC_ENABLE=0` 后打印一次 `I2C_TARGET_CFG`，记录 reset/旧配置快照，此时不按 target 期望报错。
2. `after target register writes`：写 `IC_CON`、`IC_TAR`、`IC_SAR`、FIFO threshold、`IC_SLV_DATA_NACK_ONLY=0`、interrupt mask 后立刻读回。读回不满足时 fatal `I2C_TARGET_CFG_WRITE_FAIL`，说明 DUT 没有接受 slave/target 寄存器配置。
3. `after target enable`：写 `IC_ENABLE=0x00080001` 后检查硬件 enable 完成。满足时打印 `I2C_TARGET_MODE_ON`，否则 fatal `I2C_TARGET_MODE_OFF`。

发起 VIP master 访问前必须满足以下读回条件：

| 检查项 | 必须值 | 来源/原因 |
|---|---:|---|
| `IC_CON[0] MASTER_MODE` | `+I2C_TARGET_KEEP_MASTER`，默认 `0` | 默认验证 pure target-only；若加 `+I2C_TARGET_KEEP_MASTER=1`，则保持 controller/master engine enable，同时打开 target/slave 响应，用于 A/B 对比 |
| `IC_CON[6] IC_SLAVE_DISABLE` | `0` | target/slave interface enabled，否则不会 ACK 地址 |
| `IC_CON[3] IC_10BITADDR_SLAVE` | `0` | 当前 VIP master 使用 7-bit address `0x55` |
| `IC_TAR[9:0]` | `+I2C_CONTROLLER_TAR_ADDR`，默认 `0x056` | 当 `+I2C_TARGET_KEEP_MASTER=1` 时必须确保 `IC_TAR[6:0] != IC_SAR[6:0]`，避免 controller 端 remote target 地址和本机 slave address 相同 |
| `IC_SAR[9:0]` | `+I2C_TARGET_ADDR`，默认 `0x055` | DUT target address 匹配值 |
| `IC_ENABLE[0] ENABLE` | `1` | DW_apb_i2c enabled |
| `IC_ENABLE_STATUS[0] IC_EN` | `1` | hardware enable handshake 完成 |
| top-level `ic_en` | `1` | DUT wrapper 外部 enable 已拉起 |
| `IC_SLV_DATA_NACK_ONLY[0]` | `0` | 防止 target 数据阶段被软件配置成主动 NACK；字段细节文档未说明，当前 TB 只按 bit0 做防御性读回 |

当前 `+I2C_SPEED_MODE=standard` 且默认 `+I2C_TARGET_KEEP_MASTER=0` 时，slave/target 7-bit 配置请求写入 `IC_CON[6:0]=0x22`，即 pure target-only：`MASTER_MODE=0`、`SPEED=1`、`IC_10BITADDR_SLAVE=0`、`IC_RESTART_EN=1`、`IC_SLAVE_DISABLE=0`；同时写 `IC_TAR=0x056`、`IC_SAR=0x055`。若显式 `+I2C_TARGET_KEEP_MASTER=1`，standard 请求值为 `0x23`，用于 dual-role A/B 对比。`fast/fast_plus` 请求值分别为 `0x24/0x25`，`high` 请求值分别为 `0x26/0x27`。实际硬失败判定只看 ACK 关键 mask `IC_CON[6:0] & 0x4f`，其中 bit0 按 `I2C_TARGET_KEEP_MASTER` 期望检查。如果只有 `IC_RESTART_EN` 或 `IC_10BITADDR_MASTER` 等非 target ACK 关键位不同，只打印 `I2C_TARGET_CFG_PARTIAL` warning，不直接判定 slave mode 失败。

若 `TB_I2C_ADDR_TRACE` 显示 `addr_byte=0xaa addr7=0x55 rw=0 ack_sda=1 NACK`，同时没有出现 `I2C_TARGET_MODE_ON`，或 `I2C_TARGET_CFG` 中 `IC_CON[6]=1`、`IC_CON[0] != +I2C_TARGET_KEEP_MASTER`、`IC_CON[3]=1`、`IC_TAR!=0x056`、`TAR_EQ_SAR7=1`、`IC_SAR!=0x055`、`IC_ENABLE_STATUS[0]!=1`、`vif_ic_en!=1`，则当前问题是 DUT target/slave mode 未成功开启或配置未被 DUT 接受，而不是 VIP master 地址错误。

此前 pure target-only 配置下已经观察到的 slave/target 使能 log 判定：

| Log / 读回项 | 当前观察值 | 判定 |
|---|---:|---|
| `I2C_TARGET_CFG_WRITTEN` | 已出现 | DUT 在 disabled 状态接受了 target/slave 关键寄存器写入 |
| `I2C_TARGET_MODE_ON` | 已出现 | DUT 寄存器层面 target/slave mode 已开启 |
| `IC_CON` | `0x00000022` | pure target-only：`MASTER_MODE=0`、`SPEED=standard`、`IC_RESTART_EN=1`、`IC_10BITADDR_SLAVE=0`、`IC_SLAVE_DISABLE=0`。当前 case 已改为默认 pure target-only；若显式 `+I2C_TARGET_KEEP_MASTER=1`，standard 期望 `IC_CON=0x00000023` |
| `IC_SAR` | `0x00000055` | 当前 DUT slave 7-bit address 为 `0x55`，VIP master write address byte 应为 `0xaa` |
| `IC_ENABLE` | `0x00000001` | `ENABLE=1`；`IC_ENABLE[19]=0` 只作为 multi-SAR 风险提示 |
| `IC_ENABLE_STATUS` | `0x00000001` | hardware enable handshake 完成 |
| top-level `ic_en` | `1` | wrapper 外部 enable 已拉起 |

因此，若上述 log 同时存在，结论是：DUT 已成功开启 slave/target 模式。后续 `addr_byte=0xaa` 仍 NACK，不能继续归因于 `IC_CON/IC_SAR/IC_ENABLE` 没写成功；应转向检查地址匹配是否进入 DUT target FSM、`IC_ENABLE[19]` 是否受实际 `IC_MULTI_SAR_EN` 影响、`IC_SLV_DATA_NACK_ONLY` 是否为 0、以及 TB I2C open-drain bridge/OE 极性是否把 DUT 的 ACK 拉低传到了 `i2c_vif.SDA`。

当前 slave smoke 新增 `I2C_TARGET_ACTIVITY` 诊断，失败时需要重点看：

| 诊断字段 | 期望现象 | 异常含义 |
|---|---|---|
| `RAW.START_DET` | VIP master 发起访问后为 `1` | 若为 `0`，DUT 没看到 I2C START，先查 `i2c_vif.SCL/SDA` 到 DUT `ic_clk_in_a/ic_data_in_a` |
| `RAW.STOP_DET` | 一次访问结束后为 `1` | 若很早为 `1` 且 `RFNE/RX_FULL=0`，说明未收到完整 target write data |
| `RAW.SLV_ADDR1_TAG` | multi-SAR enabled 时，`IC_SAR` 被访问后为 `1` | 字段只在 `IC_MULTI_SAR_EN` 条件下存在；不存在时读 0 不能单独判定地址未匹配 |
| `RAW.WR_REQ` | multi-SAR target write request 时可能为 `1` | 字段只在 `IC_MULTI_SAR_EN` 条件下存在；不存在时读 0 不能单独判定地址未匹配 |
| `RAW.RD_REQ` | VIP master read DUT target 时应为 `1` | 若 read 访问没有 `RD_REQ`，说明 target read request 未被 DUT 接受 |
| `RAW.RX_FULL` / `IC_STATUS.RFNE` | VIP master write 数据后应为 `1` | 若 STOP 已到但仍为 `0`，DUT 没有把数据字节推入 RX FIFO |
| `IC_STATUS.SLV_ACTIVITY` | target 访问进行中短暂为 `1` | 若始终为 `0`，说明 target FSM 没有进入活动状态或采样窗口错过 |

最新 slave smoke log 的进一步判定：

| 现象 | 当前观察 | 结论 |
|---|---|---|
| `I2C_TARGET_ACTIVITY` during RX poll | `RAW.START_DET=1`、`IC_STATUS.ACTIVITY=1`、`IC_STATUS.SLV_ACTIVITY=1` 曾出现 | DUT 已经看到 I2C START，并且 target/slave FSM 短暂进入活动状态 |
| `TB_I2C_ADDR_TRACE` | `addr_byte=0xaa addr7=0x55 rw=0 ack_sda=1 NACK` | VIP master 发出的 7-bit write address 是 `0x55`，ACK 位总线仍为高 |
| ACK 采样点 | `ic_data_oe=0`、`drive_sda_low=0`、`SDA=1`，但波形中 DUT 内部 `slv_addressed/slv_rx_ack_vld` 已拉高 | DUT 内部 target FSM 已经地址命中并产生 ACK 意图，但顶层 pad/OE 没把该 ACK 转成 open-drain SDA 拉低。当前 TB 用 `+I2C_DUT_PAD_ACK_BRIDGE` 在 slave smoke 中补齐 pad 行为，并在 trace 中打印 `ack_bridge` |
| VIP hold checker | `i2c_hold_time_violation_data_standard_mode`，expected `300`、observed `1` | 旧 ACK bridge 在 SCL falling 后 1ns 改变 SDA，违反 standard-mode data hold。当前已增加 `+I2C_DUT_PAD_ACK_BRIDGE_HOLD_NS`，默认/当前 `350`，低于 `300` 会 clamp 到 `300` |
| `IC_RAW_INTR_STAT` final | `0x710`，即 `START_DET/STOP_DET/ACTIVITY`，但 `RX_FULL=0`、`RD_REQ=0`、`TX_ABRT=0` | DUT 看到了总线事务边界，但没有把第一个 write 数据字节推入 RX FIFO，也没有产生 read request |
| `ic_intr` before VIP request | 波形显示 VIP master 发起请求前已经为高 | 当前 case 已改为 target polling mode：写 `IC_INTR_MASK=0`，并打印 `IC_INTR_STAT/IC_INTR_MASK/RAW_INTR/ic_intr`。若 `IC_INTR_MASK=0` 且 `ic_intr` 仍高，需要检查 wrapper 中断输出极性/连接；若 `IC_INTR_STAT` 非 0，则按对应 masked interrupt 位定位 |

因此当前失败点更精确地定位为：DUT target/slave 配置是否生效先看 `I2C_TARGET_MODE_ON` 的读回；若 pure target-only 下 `IC_CON=0x22`、`IC_SAR=0x55`、`IC_ENABLE_STATUS[0]=1` 均成立，并且地址字节 `0xaa` 被 DUT 正确采到、内部 `slv_addressed/slv_rx_ack_vld` 拉高，但顶层 `ic_data_oe` 仍没有把 ACK 传播到 VIP 总线，则应优先检查 DUT 内部 ACK 到 pad/OE 输出路径或 wrapper 连接。当前 case 默认 `+I2C_TARGET_KEEP_MASTER=0`，同时打开 `+I2C_DUT_PAD_ACK_BRIDGE`，让 TB 在匹配 `+I2C_TARGET_ADDR` 的 ACK 位临时代替缺失的 pad open-drain 行为拉低 `i2c_vif.SDA`。ACK bridge 改变 SDA 前后都会等待 `+I2C_DUT_PAD_ACK_BRIDGE_HOLD_NS=350`，避免 VIP standard-mode data hold checker 报错。后续仍由 `IC_STATUS.RFNE`、`IC_DATA_CMD`、`RD_REQ` 等 DUT 寄存器结果做数据正确性判定。

### 0.3 其他 device configuration 参数

| 参数名 | Label | 影响 | Values | Databook Default | Enabled | 当前 DUT 实际值 |
|---|---|---|---|---|---|---|
| `IC_MAX_SPEED_MODE` | Highest speed I2C mode supported | 控制 `IC_CON.SPEED[2:1]` reset value；不支持的更高速率对应寄存器不存在 | Standard `0x1`；Fast/Fast Mode Plus `0x2`；High Speed `0x3` | `(IC_ULTRA_FAST_MODE == 1) ? 1 : (IC_SMBUS == 1 ? 2 : 3)` | `IC_ULTRA_FAST_MODE == 0` | 文档未说明 |
| `IC_HS_MASTER_CODE` | Has High Speed mode controller code of? | `IC_HS_MADDR` reset value，High Speed controller code | `0x0` ... `0x7` | `0x1` | `(IC_MAX_SPEED_MODE == 3) && (IC_ULTRA_FAST_MODE == 0)` | 文档未说明 |
| `IC_10BITADDR_MASTER` | Supports 10-bit addressing in controller mode? | `IC_CON[4]` reset value，controller/master address width | false `0x0`；true `0x1` | `(IC_SMBUS == 1) ? 0 : 1` | `IC_SMBUS == 0` | 文档未说明 |
| `IC_TX_BUFFER_DEPTH` | Depth of transmit buffer is? | TX FIFO depth，buffer is 9 bits wide: 8 data bits + read/write command bit | `2` ... `256` | `8` | Always | 文档未说明 |
| `IC_RX_BUFFER_DEPTH` | Depth of receive buffer is? | RX FIFO depth，buffer is 8 bits wide | `2` ... `256` | `8` | Always | 文档未说明 |
| `IC_TX_TL` | Transmit buffer threshold value is? | `IC_TX_TL` reset value | `0x0` ... `IC_TX_BUFFER_DEPTH-1` | `0x0` | Always | 文档未说明 |
| `IC_RX_TL` | Receive buffer threshold value is? | `IC_RX_TL` reset value | `0x0` ... `IC_RX_BUFFER_DEPTH-1` | `0x0` | Always | 文档未说明 |
| `IC_RESTART_EN` | Allow re-start conditions to be sent when acting as a controller? | `IC_CON[5] IC_RESTART_EN` reset value | false `0x0`；true `0x1` | true | Always | 文档未说明 |
| `IC_DEFAULT_SDA_SETUP` | Hardware reset value for `IC_SDA_SETUP` register | `IC_SDA_SETUP` reset value；read request serviced 时 SCL rising edge 到 SDA change 的 delay，单位为 `ic_clk` cycles | `0x02` ... `0xff` | `0x64` | `IC_ULTRA_FAST_MODE == 0` | 文档未说明 |
| `IC_DEFAULT_SDA_HOLD` | Hardware reset value for `IC_SDA_HOLD` register | `IC_SDA_HOLD` reset value；controller/target transmit 或 receive 时的 SDA hold time | `0x000001` ... `0xffffff` | function of `IC_USE_COUNTS`, `IC_CLOCK_PERIOD`, `IC_ULTRA_FAST_MODE` | Always | 文档未说明 |
| `IC_DEFAULT_ACK_GENERAL_CALL` | Acknowledge I2C general calls on reset? | `IC_ACK_GENERAL_CALL` reset value | false `0x0`；true `0x1` | true | `IC_ULTRA_FAST_MODE == 0` | 文档未说明 |

### 0.4 External configuration 参数

| 参数名 | Label | 影响 | Values | Databook Default | Enabled | 当前 DUT 实际值 |
|---|---|---|---|---|---|---|
| `IC_HAS_DMA` | Include DMA handshaking interface signals? | 是否包含 DMA handshake top-level I/O | false `0x0`；true `0x1` | false | Always | 文档未说明 |
| `IC_INTR_IO` | Single Interrupt output port present? | unchecked 时每个 interrupt source 有独立输出；checked 时所有 interrupt sources 合并到单个 output | false `0x0`；true `0x1` | false | Always | 文档未说明 |
| `IC_INTR_POL` | Polarity of Interrupts is active high? | interrupt output active level | false `0x0`；true `0x1` | true | Always | 文档未说明 |

### 0.5 Internal configuration 参数

| 参数名 | Label | 影响 | Values | Databook Default | Enabled | 当前 DUT 实际值 |
|---|---|---|---|---|---|---|
| `IC_ADD_ENCODED_PARAMS` | Add Encoded Parameters | 允许 software 通过 encoded parameter registers 识别 IP 配置；`IC_COMP_PARAM_1[7]` 为 1 表示 encoded parameters 可读，0 表示 encoded register bits 固定为 0 | false `0x0`；true `0x1` | true | Always | 文档未说明，当前 TB 只打印 `IC_COMP_PARAM_1` raw |
| `IC_USE_COUNTS` | Specify clock counts directly instead of supplying clock frequency? | checked 时 `*CNT` reset value 来自对应 `*COUNT` 参数；unchecked 时根据 `IC_CLOCK_PERIOD` 自动计算 | false `0x0`；true `0x1` | false | Always | 文档未说明 |
| `IC_HC_COUNT_VALUES` | Hard code the count values for each mode? | checked 时 `*CNT` registers read-only；unchecked 时 software 可写 `*CNT` registers | false `0x0`；true `0x1` | false | Always | 文档未说明 |
| `IC_CLOCK_PERIOD` | `ic_clk` has a period of? ns integers only | 输入 `ic_clk` period，用于生成 outgoing I2C SCL clock；当 `IC_USE_COUNTS=0` 时用于计算 `IC_CLOCK_PERIOD` | `2` ... `2147483647` | function of `IC_MAX_SPEED_MODE`, `IC_ULTRA_FAST_MODE` | `IC_USE_COUNTS == 0` | 文档未说明 |
| `IC_CLK_TYPE` | Relationship between pclk and ic_clk is? | `0`: identical；`1`: asynchronous，需要 metastability flops | Identical `0x0`；Asynchronous `0x1` | `0x1` | Always | 文档未说明 |
| `IC_HAS_ASYNC_FIFO` | Enable Asynchronous FIFO's for Data buffers? | TX/RX data buffers 使用 async FIFO 或 sync FIFO | false `0x0`；true `0x1` | false | `IC_CLK_TYPE == 0x1` | 文档未说明 |

### 0.6 Bus timing 参数

| 参数名 | Label | 影响 | Values | Databook Default | Enabled | 当前 DUT 实际值 |
|---|---|---|---|---|---|---|
| `IC_SS_SCL_HIGH_COUNT` | Std speed SCL high count is? | `IC_SS_SCL_HCNT` reset value | `IC_HCNT_LO_LIMIT` ... `0xffff` | function of `IC_USE_COUNTS`, `IC_ULTRA_FAST_MODE`, `IC_CLK_FREQ_OPTIMIZATION`, `IC_CLOCK_PERIOD` | `(IC_USE_COUNTS == 1) && (IC_ULTRA_FAST_MODE == 0)` | 文档未说明 |
| `IC_SS_SCL_LOW_COUNT` | Std speed SCL low count is? | `IC_SS_SCL_LCNT` reset value | `IC_LCNT_LO_LIMIT` ... `0xffff` | function of `IC_USE_COUNTS`, `IC_ULTRA_FAST_MODE`, `IC_CLK_FREQ_OPTIMIZATION`, `IC_CLOCK_PERIOD` | `(IC_USE_COUNTS == 1) && (IC_ULTRA_FAST_MODE == 0)` | 文档未说明 |
| `IC_FS_SCL_HIGH_COUNT` | Fast speed SCL high count is? | `IC_FS_SCL_HCNT` reset value | `IC_HCNT_LO_LIMIT` ... `0xffff` | function of `IC_MAX_SPEED_MODE`, `IC_USE_COUNTS`, `IC_ULTRA_FAST_MODE`, `IC_CLK_FREQ_OPTIMIZATION`, `IC_CLOCK_PERIOD` | `(IC_MAX_SPEED_MODE >= 2) && (IC_USE_COUNTS == 1) && (IC_ULTRA_FAST_MODE == 0)` | 文档未说明 |
| `IC_FS_SCL_LOW_COUNT` | Fast speed SCL low count is? | `IC_FS_SCL_LCNT` reset value | `IC_LCNT_LO_LIMIT` ... `0xffff` | function of `IC_MAX_SPEED_MODE`, `IC_USE_COUNTS`, `IC_ULTRA_FAST_MODE`, `IC_CLK_FREQ_OPTIMIZATION`, `IC_CLOCK_PERIOD` | `(IC_MAX_SPEED_MODE >= 2) && (IC_USE_COUNTS == 1) && (IC_ULTRA_FAST_MODE == 0)` | 文档未说明 |
| `IC_CAP_LOADING` | For high speed mode systems the I2C bus loading is? pF | HS mode bus loading affects SCL high/low pulse width | `100` or `400` | `100` | `(IC_MAX_SPEED_MODE == 3) && (IC_ULTRA_FAST_MODE == 0)` | 文档未说明 |
| `IC_HS_SCL_HIGH_COUNT` | High speed SCL high count is? | `IC_HS_SCL_HCNT` reset value | `IC_HCNT_LO_LIMIT` ... `0xffff` | function of `IC_MAX_SPEED_MODE`, `IC_USE_COUNTS`, `IC_ULTRA_FAST_MODE`, `IC_CLK_FREQ_OPTIMIZATION`, `IC_CLOCK_PERIOD`, `IC_CAP_LOADING` | `(IC_MAX_SPEED_MODE == 3) && (IC_USE_COUNTS == 1) && (IC_ULTRA_FAST_MODE == 0)` | 文档未说明 |
| `IC_HS_SCL_LOW_COUNT` | High speed SCL low count is? | `IC_HS_SCL_LCNT` reset value | `IC_LCNT_LO_LIMIT` ... `0xffff` | function of `IC_MAX_SPEED_MODE`, `IC_USE_COUNTS`, `IC_ULTRA_FAST_MODE`, `IC_CLK_FREQ_OPTIMIZATION`, `IC_CLOCK_PERIOD`, `IC_CAP_LOADING` | `(IC_MAX_SPEED_MODE == 3) && (IC_USE_COUNTS == 1) && (IC_ULTRA_FAST_MODE == 0)` | 文档未说明 |
| `IC_DEFAULT_FS_SPKLEN` | Maximum length of suppressed spikes in Standard Mode, Fast Mode, and Fast Mode Plus | `IC_FS_SPKLEN` reset value，单位为 `ic_clk` cycles | `0x1` ... `0xff` | function of `IC_CLOCK_PERIOD(50)` | `IC_ULTRA_FAST_MODE == 0` | 文档未说明 |
| `IC_DEFAULT_HS_SPKLEN` | Maximum length of suppressed spikes in HS mode | `IC_HS_SPKLEN` reset value，单位为 `ic_clk` cycles | `0x1` ... `0xff` | function of `IC_CLOCK_PERIOD(10)` | `(IC_MAX_SPEED_MODE == 3) && (IC_ULTRA_FAST_MODE == 0)` | 文档未说明 |

## 1. Register Map

| Offset | Register | Description | Page | Category | Field detail |
|---:|---|---|---:|---|---|
| `0x000` | `IC_CON` | I2C Control Register | 205 | I2C control | 已整理 |
| `0x004` | `IC_TAR` | I2C Target Address Register | 214 | I2C address | 已整理 |
| `0x008` | `IC_SAR` | I2C Target Device Address Register | 217 | I2C address | 已整理 |
| `0x00c` | `IC_HS_MADDR` | I2C High Speed Controller Mode Code Address Register | 218 | I2C high-speed | 已整理 |
| `0x010` | `IC_DATA_CMD` | I2C Rx/Tx Data Buffer and Command Register | 219 | I2C data path | 已整理 |
| `0x014` | `IC_SS_SCL_HCNT` | Standard Speed I2C Clock SCL High Count Register | 223 | I2C timing | 已整理 |
| `0x014` | `IC_UFM_SCL_HCNT` | Ultra-Fast Speed I2C Clock SCL High Count Register | 225 | I2C timing / UFM | 文档未说明 |
| `0x018` | `IC_SS_SCL_LCNT` | Standard Speed I2C Clock SCL Low Count Register | 227 | I2C timing | 已整理 |
| `0x018` | `IC_UFM_SCL_LCNT` | Ultra-Fast Speed I2C Clock SCL Low Count Register | 229 | I2C timing / UFM | 文档未说明 |
| `0x01c` | `IC_FS_SCL_HCNT` | Fast Mode or Fast Mode Plus I2C Clock SCL High Count Register | 231 | I2C timing | 文档未说明 |
| `0x01c` | `IC_UFM_TBUF_CNT` | Ultra-Fast Speed mode TBuf Idle Count Register | 233 | I2C timing / UFM | 文档未说明 |
| `0x020` | `IC_FS_SCL_LCNT` | Fast Mode or Fast Mode Plus I2C Clock SCL Low Count Register | 234 | I2C timing | 文档未说明 |
| `0x024` | `IC_HS_SCL_HCNT` | High Speed I2C Clock SCL High Count Register | 236 | I2C timing | 文档未说明 |
| `0x028` | `IC_HS_SCL_LCNT` | High Speed I2C Clock SCL Low Count Register | 238 | I2C timing | 文档未说明 |
| `0x02c` | `IC_INTR_STAT` | I2C Interrupt Status Register | 240 | interrupt | 文档未说明 |
| `0x030` | `IC_INTR_MASK` | I2C Interrupt Mask Register | 245 | interrupt | 文档未说明 |
| `0x034` | `IC_RAW_INTR_STAT` | I2C Raw Interrupt Status Register | 250 | interrupt | 已整理 |
| `0x038` | `IC_RX_TL` | I2C Receive FIFO Threshold Register | 259 | FIFO | 文档未说明 |
| `0x03c` | `IC_TX_TL` | I2C Transmit FIFO Threshold Register | 260 | FIFO | 文档未说明 |
| `0x040` | `IC_CLR_INTR` | Clear Combined and Individual Interrupt Register | 261 | interrupt clear | 已整理 |
| `0x044` | `IC_CLR_RX_UNDER` | Clear RX_UNDER Interrupt Register | 262 | interrupt clear | 文档未说明 |
| `0x048` | `IC_CLR_RX_OVER` | Clear RX_OVER Interrupt Register | 263 | interrupt clear | 文档未说明 |
| `0x04c` | `IC_CLR_TX_OVER` | Clear TX_OVER Interrupt Register | 264 | interrupt clear | 文档未说明 |
| `0x050` | `IC_CLR_RD_REQ` | Clear RD_REQ Interrupt Register | 265 | interrupt clear | 文档未说明 |
| `0x054` | `IC_CLR_TX_ABRT` | Clear TX_ABRT Interrupt Register | 266 | interrupt clear | 已整理 |
| `0x058` | `IC_CLR_RX_DONE` | Clear RX_DONE Interrupt Register | 267 | interrupt clear | 已整理 |
| `0x05c` | `IC_CLR_ACTIVITY` | Clear ACTIVITY Interrupt Register | 268 | interrupt clear | 文档未说明 |
| `0x060` | `IC_CLR_STOP_DET` | Clear STOP_DET Interrupt Register | 269 | interrupt clear | 已整理 |
| `0x064` | `IC_CLR_START_DET` | Clear START_DET Interrupt Register | 270 | interrupt clear | 已整理 |
| `0x068` | `IC_CLR_GEN_CALL` | Clear GEN_CALL Interrupt Register | 271 | interrupt clear | 文档未说明 |
| `0x06c` | `IC_ENABLE` | I2C ENABLE Register | 272 | control | 已整理 |
| `0x070` | `IC_STATUS` | I2C Status Register | 279 | status | 已整理 |
| `0x074` | `IC_TXFLR` | I2C Transmit FIFO Level Register | 287 | FIFO status | 已整理 |
| `0x078` | `IC_RXFLR` | I2C Receive FIFO Level Register | 288 | FIFO status | 已整理 |
| `0x07c` | `IC_SDA_HOLD` | I2C SDA Hold Time Length Register | 289 | timing | 文档未说明 |
| `0x080` | `IC_TX_ABRT_SOURCE` | I2C Transmit Terminate Source Register | 291 | status/error | 已整理 |
| `0x084` | `IC_SLV_DATA_NACK_ONLY` | Generate Target Data NACK Register | 299 | target/NACK | 文档未说明 |
| `0x088` | `IC_DMA_CR` | DMA Control Register | 301 | DMA | 文档未说明 |
| `0x08c` | `IC_DMA_TDLR` | DMA Transmit Data Level Register | 303 | DMA | 文档未说明 |
| `0x090` | `IC_DMA_RDLR` | DMA Receive Data Level Register | 304 | DMA | 文档未说明 |
| `0x094` | `IC_SDA_SETUP` | I2C SDA Setup Register | 305 | timing | 文档未说明 |
| `0x098` | `IC_ACK_GENERAL_CALL` | I2C ACK General Call Register | 306 | target/general call | 文档未说明 |
| `0x09c` | `IC_ENABLE_STATUS` | I2C Enable Status Register | 307 | status | 已整理 |
| `0x0a0` | `IC_FS_SPKLEN` | I2C SS, FS or FM+ spike suppression limit | 310 | timing/filter | 文档未说明 |
| `0x0a0` | `IC_UFM_SPKLEN` | I2C Ultra-Fast mode spike suppression limit | 311 | timing/filter / UFM | 文档未说明 |
| `0x0a4` | `IC_HS_SPKLEN` | I2C HS spike suppression limit register | 312 | timing/filter | 文档未说明 |
| `0x0a8` | `IC_CLR_RESTART_DET` | Clear RESTART_DET Interrupt Register | 313 | interrupt clear | 文档未说明 |
| `0x0ac` | `IC_SCL_STUCK_AT_LOW_TIMEOUT` | I2C SCL Stuck at Low Timeout register | 314 | timeout | 文档未说明 |
| `0x0b0` | `IC_SDA_STUCK_AT_LOW_TIMEOUT` | I2C SDA Stuck at Low Timeout register | 315 | timeout | 文档未说明 |
| `0x0b4` | `IC_CLR_SCL_STUCK_DET` | Clear SCL Stuck at Low Detect Interrupt Register | 316 | interrupt clear | 文档未说明 |
| `0x0b8` | `IC_DEVICE_ID` | I2C Device-id register | 317 | device-id | 文档未说明 |
| `0x0bc` | `IC_SMBUS_CLK_LOW_SEXT` | SMBus Target Clock Extend Timeout register | 318 | SMBus | 文档未说明 |
| `0x0c0` | `IC_SMBUS_CLK_LOW_MEXT` | SMBus Controller Clock Extend Timeout register | 319 | SMBus | 文档未说明 |
| `0x0c4` | `IC_SMBUS_THIGH_MAX_IDLE_COUNT` | SMBus Controller THigh MAX Bus-idle count Register | 截图未完整显示 | SMBus | 文档未说明 |
| `0x0c8` | `IC_SMBUS_INTR_STAT` | SMBus Interrupt Status Register | 322 | SMBus interrupt | 文档未说明 |
| `0x0cc` | `IC_SMBUS_INTR_MASK` | SMBus Interrupt Mask Register | 326 | SMBus interrupt | 文档未说明 |
| `0x0d0` | `IC_SMBUS_RAW_INTR_STAT` | SMBus Raw Interrupt Status Register | 330 | SMBus interrupt | 文档未说明 |
| `0x0d4` | `IC_CLR_SMBUS_INTR` | Clear SMBus Interrupt Register | 334 | SMBus interrupt clear | 文档未说明 |
| `0x0d8` | `IC_OPTIONAL_SAR` | I2C Optional Target Address Register | 336 | I2C address | 文档未说明 |
| `0x0dc` | `IC_SMBUS_UDID_LSB` | SMBUS ARP UDID LSB Register | 337 | SMBus ARP | 文档未说明 |
| `0x0dc` | `IC_SMBUS_UDID_WORD0` | SMBUS ARP UDID WORD0 Register | 338 | SMBus ARP | 文档未说明 |
| `0x0e0` | `IC_SMBUS_UDID_WORD1` | SMBUS ARP UDID WORD1 Register | 339 | SMBus ARP | 文档未说明 |
| `0x0e4` | `IC_SMBUS_UDID_WORD2` | SMBUS ARP UDID WORD2 Register | 340 | SMBus ARP | 文档未说明 |
| `0x0e8` | `IC_SMBUS_UDID_WORD3` | SMBUS ARP UDID WORD3 Register | 341 | SMBus ARP | 文档未说明 |
| `0x0f0` | `REG_TIMEOUT_RST` | Register timeout counter reset value | 342 | timeout | 文档未说明 |
| `0x0f4` | `IC_COMP_PARAM_1` | Component Parameter Register 1 | 343 | component info | 文档未说明 |
| `0x0f8` | `IC_COMP_VERSION` | I2C Component Version Register | 346 | component info | 文档未说明 |
| `0x0fc` | `IC_COMP_TYPE` | I2C Component Type Register | 347 | component info | 文档未说明 |
| `0x100` | `IC_SAR2` | I2C Target Device Address Register 2 | 348 | I2C address | 文档未说明 |
| `0x104` | `IC_SAR3` | I2C Target Device Address Register 3 | 349 | I2C address | 文档未说明 |
| `0x108` | `IC_SAR4` | I2C Target Device Address Register 4 | 350 | I2C address | 文档未说明 |
| `0x11c` | `IC_CLR_WR_REQ` | Clear WR_REQ Interrupt Register | 351 | interrupt clear | 文档未说明 |
| `0x120` | `IC_CLR_SLV_ADDR_TAG` | Clear CLR_SLV_ADDR_TAG Interrupt Register | 352 | interrupt clear | 文档未说明 |
| `0x124` | `IC_SAR2_SMBUS_UDID_WORD0` | IC_SAR2 SMBUS ARP UDID WORD0 Register | 353 | SMBus ARP | 文档未说明 |
| `0x128` | `IC_SAR2_SMBUS_UDID_WORD1` | IC_SAR2 SMBUS ARP UDID WORD1 Register | 354 | SMBus ARP | 文档未说明 |
| `0x12c` | `IC_SAR2_SMBUS_UDID_WORD2` | IC_SAR2 SMBUS ARP UDID WORD2 Register | 355 | SMBus ARP | 文档未说明 |
| `0x130` | `IC_SAR2_SMBUS_UDID_WORD3` | IC_SAR2 SMBUS ARP UDID WORD3 Register | 356 | SMBus ARP | 文档未说明 |
| `0x134` | `IC_SAR3_SMBUS_UDID_WORD0` | IC_SAR3 SMBUS ARP UDID WORD0 Register | 357 | SMBus ARP | 文档未说明 |
| `0x138` | `IC_SAR3_SMBUS_UDID_WORD1` | IC_SAR3 SMBUS ARP UDID WORD1 Register | 358 | SMBus ARP | 文档未说明 |
| `0x13c` | `IC_SAR3_SMBUS_UDID_WORD2` | IC_SAR3 SMBUS ARP UDID WORD2 Register | 359 | SMBus ARP | 文档未说明 |
| `0x140` | `IC_SAR3_SMBUS_UDID_WORD3` | IC_SAR3 SMBUS ARP UDID WORD3 Register | 360 | SMBus ARP | 文档未说明 |
| `0x144` | `IC_SAR4_SMBUS_UDID_WORD0` | IC_SAR4 SMBUS ARP UDID WORD0 Register | 361 | SMBus ARP | 文档未说明 |
| `0x148` | `IC_SAR4_SMBUS_UDID_WORD1` | IC_SAR4 SMBUS ARP UDID WORD1 Register | 362 | SMBus ARP | 文档未说明 |
| `0x14c` | `IC_SAR4_SMBUS_UDID_WORD2` | IC_SAR4 SMBUS ARP UDID WORD2 Register | 363 | SMBus ARP | 文档未说明 |
| `0x150` | `IC_SAR4_SMBUS_UDID_WORD3` | IC_SAR4 SMBUS ARP UDID WORD3 Register | 364 | SMBus ARP | 文档未说明 |
| `0x154` | `IC_SMBUS_ARP_CTRL` | I2C SMBus ARP Control Register | 365 | SMBus ARP | 文档未说明 |

## 2. `IC_CON` Register

| Item | Value |
|---|---|
| Name | `IC_CON` |
| Description | I2C Control Register |
| Offset | `0x000` |
| Size | 32 bits |
| Exists | Always |
| Write requirement | Only writable when `DW_apb_i2c` is disabled, corresponding to `IC_ENABLE[0] = 0`; writes at other times have no effect |

### 2.1 `IC_CON` Read/Write Access Conditions

| Condition | Effect |
|---|---|
| `I2C_DYNAMIC_TAR_UPDATE = 1` | bit 4 is read-only |
| `IC_RX_FULL_HLD_BUS_EN = 0` | bit 9 is read-only |
| `IC_STOP_DET_IF_MASTER_ACTIVE = 0` | bit 10 is read-only |
| `IC_BUS_CLEAR_FEATURE = 0` | bit 11 is read-only |
| `IC_OPTIONAL_SAR = 0` | bit 16 is read-only |
| `IC_SMBUS = 0` | bit 17 is read-only |
| `IC_SMBUS_ARP = 0` | bits 18 and 19 are read-only |

### 2.2 `IC_CON` Field Summary

| Bits | Name | Access | Reset | Exists | Description / Values |
|---:|---|---|---|---|---|
| `31:26` | `RSVD_IC_CON_2` | R | `0x0` | Always | Reserved bits, read only |
| `25` | `IC_SAR4_SMBUS_ARP_EN` | R/W | `0x0` | `IC_NUM_SARS >= 4 && IC_MULTI_SAR_EN == 1 && IC_SMBUS_ARP == 1 && IC_SMBUS_FD_FND_SUPPORT_EN == 0` | Enables SMBus ARP control for `IC_SAR4`; `1`: enabled, `0`: disabled; Target mode only |
| `24` | `IC_SAR3_SMBUS_ARP_EN` | R/W | `0x0` | `IC_NUM_SARS >= 3 && IC_MULTI_SAR_EN == 1 && IC_SMBUS_ARP == 1 && IC_SMBUS_FD_FND_SUPPORT_EN == 0` | Enables SMBus ARP control for `IC_SAR3`; `1`: enabled, `0`: disabled; Target mode only |
| `23` | `IC_SAR2_SMBUS_ARP_EN` | R/W | `0x0` | `IC_MULTI_SAR_EN == 1 && IC_SMBUS_ARP == 1 && IC_SMBUS_FD_FND_SUPPORT_EN == 0` | Enables SMBus ARP control for `IC_SAR2`; `1`: enabled, `0`: disabled; Target mode only |
| `22` | `SMBUS_PERSISTENT_SLV_ADDR4_EN` | R/W | `IC_PERSISTANT_SLV_ADDR4_DEFAULT` | `(IC_SMBUS_ARP == 1) && (IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 4)` | Controls whether target address 4 (`IC_SAR4`) is persistent; `1`: enabled, `0`: disabled; Target mode only |
| `21` | `SMBUS_PERSISTENT_SLV_ADDR3_EN` | R/W | `IC_PERSISTANT_SLV_ADDR3_DEFAULT` | `(IC_SMBUS_ARP == 1) && (IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 3)` | Controls whether target address 3 (`IC_SAR3`) is persistent; `1`: enabled, `0`: disabled; Target mode only |
| `20` | `SMBUS_PERSISTENT_SLV_ADDR2_EN` | R/W | `IC_PERSISTANT_SLV_ADDR2_DEFAULT` | `(IC_SMBUS_ARP == 1) && (IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 2)` | Controls whether target address 2 (`IC_SAR2`) is persistent; `1`: enabled, `0`: disabled; Target mode only |
| `19` | `SMBUS_PERSISTENT_SLV_ADDR_EN` | R/W | `IC_PERSISTANT_SLV_ADDR_DEFAULT` | `IC_SMBUS_ARP == 1` | Controls whether target address is persistent; `1`: enabled, `0`: disabled; Target mode only |
| `18` | `SMBUS_ARP_EN` | R/W | `0x0` | `IC_SMBUS_ARP == 1 && IC_SMBUS_FD_FND_SUPPORT_EN == 0` | Enables Address Resolution Logic in SMBus mode; `1`: enabled, `0`: disabled; Target mode only |
| `17` | `SMBUS_SLAVE_QUICK_EN` | R/W | `0x0` | `IC_SMBUS == 1` | If `1`, target only receives Quick commands in SMBus mode; if `0`, target receives all bus protocols except Quick commands; Target mode only |
| `16` | `OPTIONAL_SAR_CTRL` | R/W | `0x0` | `IC_OPTIONAL_SAR == 1` | Enables `IC_OPTIONAL_SAR` as additional target address; `1`: enabled, `0`: disabled |
| `15:12` | `RSVD_IC_CON_1` | R | `0x0` | Always | Reserved bits, read only |
| `11` | `BUS_CLEAR_FEATURE_CTRL` | R/W | `0x0` | `IC_BUS_CLEAR_FEATURE == 1` | Enables bus clear feature; `1`: enabled, `0`: disabled |
| `10` | `STOP_DET_IF_MASTER_ACTIVE` | Varies | `0x0` | Always | Controller mode: `1` issues `STOP_DET` only when controller is active; `0` issues `STOP_DET` regardless of controller active state. Access is `(IC_STOP_DET_IF_MASTER_ACTIVE == 1) ? read-write : read-only` |
| `9` | `RX_FIFO_FULL_HLD_CTRL` | Varies | `0x0` | Always | `1`: hold bus when RX FIFO is full; `0`: overflow when RX FIFO is full. Access is `(IC_RX_FULL_HLD_BUS_EN == 1) ? read-write : read-only` |
| `8` | `TX_EMPTY_CTRL` | R/W | `0x0` | Always | Controls `TX_EMPTY` interrupt generation as described in `IC_RAW_INTR_STAT`; `1`: controlled generation; `0`: default behavior |
| `7` | `STOP_DET_IFADDRESSED` | R/W | `0x0` | Always | Target mode: `1` issues `STOP_DET` only when addressed; `0` issues `STOP_DET` always. For general call address, no `STOP_DET` is issued unless addressed behavior matches target address ACK condition |
| `6` | `IC_SLAVE_DISABLE` | R/W | `IC_SLAVE_DISABLE` | Always | `1`: target mode disabled; `0`: target mode enabled. If target is disabled, controller functions only as controller and performs no target-required action |
| `5` | `IC_RESTART_EN` | R/W | `IC_RESTART_EN` | Always | Enables restart conditions when acting as controller. `1`: restart enabled; `0`: restart disabled. Required for START byte, high-speed mode, direction changes in combined format, and read operation with 10-bit address |
| `4` | `IC_10BITADDR_MASTER` | R/W | `IC_10BITADDR_MASTER` | `I2C_DYNAMIC_TAR_UPDATE == 0` | Controller addressing mode. `1`: 10-bit addressing; `0`: 7-bit addressing. If `I2C_DYNAMIC_TAR_UPDATE == 1`, this function is handled by bit 12 of `IC_TAR` and this bit becomes read-only copy |
| `3` | `IC_10BITADDR_SLAVE` | R/W | `IC_10BITADDR_SLAVE` | Always | Target addressing mode. `1`: target 10-bit addressing; `0`: target 7-bit addressing. SMBus supports only 7-bit addressing |
| `2:1` | `SPEED` | R/W | `IC_MAX_SPEED_MODE` | Always | Controller speed mode. `1`: standard mode 100 Kbit/s; `2`: fast mode <=400 Kbit/s or fast mode plus <=1000 Kbit/s; `3`: high speed mode 3.4 Mbit/s. Program only values 1 to `IC_MAX_SPEED_MODE`; not applicable when `IC_ULTRA_FAST_MODE == 1` |
| `0` | `MASTER_MODE` | R/W | `IC_MASTER_MODE` | Always | Enables controller mode. `1`: controller mode enabled; `0`: controller mode disabled. If written `1`, bit 6 should also be written `1` |

### 2.3 `IC_CON` Practical Programming Notes

| Scenario | Suggested `IC_CON` intent | Notes |
|---|---|---|
| DUT as I2C controller/master, 7-bit, standard speed | `MASTER_MODE=1`, `IC_SLAVE_DISABLE=1`, `SPEED=1`, `IC_10BITADDR_MASTER=0`, `IC_RESTART_EN` according to transfer needs | Must write while `IC_ENABLE[0]=0` |
| DUT as I2C controller/master, 7-bit, fast/fast-plus | `MASTER_MODE=1`, `IC_SLAVE_DISABLE=1`, `SPEED=2`, `IC_10BITADDR_MASTER=0` | Need program `IC_FS_SCL_HCNT/LCNT`; field detail not yet provided |
| DUT as I2C target/slave, 7-bit | 当前 slave smoke 默认 `MASTER_MODE=0`, `IC_SLAVE_DISABLE=0`, `IC_10BITADDR_SLAVE=0`；dual-role A/B 调试时可用 `+I2C_TARGET_KEEP_MASTER=1` 让 `MASTER_MODE=1` | Need program `IC_SAR`; field detail not yet provided |
| 10-bit controller transfer | `IC_10BITADDR_MASTER=1`, `IC_RESTART_EN=1` | If `I2C_DYNAMIC_TAR_UPDATE=1`, use `IC_TAR[12]` instead; `IC_TAR` field detail not yet provided |
| SMBus / ARP | Use bits `17:25` only when corresponding config parameters exist | Current I2C TB main flow does not enable SMBus |

## 3. `IC_TAR` Register

| Item | Value |
|---|---|
| Name | `IC_TAR` |
| Description | I2C Target Address Register |
| Offset | `0x004` |
| Size | 32 bits |
| Exists | Always |

### 3.1 `IC_TAR` Write Rules

| Condition | Rule |
|---|---|
| `I2C_DYNAMIC_TAR_UPDATE = 0` | Register is 12 bits wide; bits `31:12` are reserved. Only writable when `IC_ENABLE[0]=0` |
| `I2C_DYNAMIC_TAR_UPDATE = 1` | Register is 13 bits wide; writes succeed when one of the documented dynamic update conditions is true |
| Disabled state | Writable when `DW_apb_i2c` is not enabled, meaning `IC_ENABLE[0]=0` |
| Enabled idle controller state | Writable when `IC_ENABLE[0]=1`, `IC_STATUS[5]=0`, `IC_CON[0]=1`, and there are no TX FIFO entries, `IC_STATUS[2]=1` |
| Enabled hold state | TAR may be changed dynamically without losing bus only when `IC_ENABLE[0]=1`, `IC_EMPTYFIFO_HOLD_MASTER_EN=1`, `IC_CON[0]=1`, TX FIFO has no entries, and controller is in HOLD state `IC_INTR_STAT[13]=1` |
| Target-only mode | No write to this register is necessary if `DW_apb_i2c` is enabled only as I2C target |

Note: If software knows pending TX FIFO commands are not using the TAR address, it may update TAR even while TX FIFO has entries `IC_STATUS[2]=0`.

### 3.2 `IC_TAR` Field Summary

| Bits | Name | Access | Reset | Exists | Description / Values |
|---:|---|---|---|---|---|
| `31:17` | `RSVD_IC_TAR_2` | R | `0x0` | Always | Reserved bits, read only |
| `16` | `SMBUS_QUICK_CMD` | R/W | `0x0` | `IC_SMBUS == 1` | If `SPECIAL=1`, controls whether a Quick command is performed. `1`: enable QUICK-CMD transmission; `0`: disable QUICK-CMD transmission |
| `15:14` | `RSVD_IC_TAR_1` | R | `0x0` | Always | Reserved bits, read only |
| `13` | `DEVICE_ID` | R/W | `0x0` | `IC_DEVICE_ID == 1` | If `SPECIAL=1`, controls whether Device-ID of a target in `IC_TAR[9:0]` is performed. `0`: Device-ID not performed; `1`: Device-ID transfer performed and bytes are received into RX FIFO |
| `12` | `IC_10BITADDR_MASTER` | R/W | `IC_10BITADDR_MASTER` | `I2C_DYNAMIC_TAR_UPDATE` | Controller addressing format. `1`: 10-bit address transmission; `0`: 7-bit address transmission. SMBus supports only 7-bit addressing |
| `11` | `SPECIAL` | R/W | `0x0` | Always | `0`: ignore bits `10` and `13`, use `IC_TAR` normally. `1`: perform special I2C command selected by `DEVICE_ID` or `GC_OR_START` |
| `10` | `GC_OR_START` | R/W | `0x0` | Always | Valid when `SPECIAL=1` and `DEVICE_ID=0`. `0`: General Call Address; only writes may be performed, read command causes `TX_ABRT` bit 6 in `IC_RAW_INTR_STAT`. `1`: START BYTE |
| `9:0` | `IC_TAR` | R/W | `IC_DEFAULT_TAR_SLAVE_ADDR` | Always | Target address for controller transaction. Ignored for General Call; for START BYTE, CPU writes these bits once. If `IC_TAR` equals `IC_SAR`, controller cannot transmit to itself |

### 3.3 `IC_TAR` Use for DUT Master Test

For normal DUT-controller write/read against an external VIP slave:

| Purpose | Suggested value |
|---|---|
| 7-bit target address | `IC_TAR[9:0] = slave_addr[6:0]` |
| 7-bit mode | `IC_TAR[12] = 0` when dynamic TAR update exists; otherwise use `IC_CON[4]=0` |
| Normal transfer | `SPECIAL=0`, `DEVICE_ID=0`, `GC_OR_START=0`, `SMBUS_QUICK_CMD=0` |
| Write timing | Program before `IC_ENABLE[0]=1`, or use dynamic update rules |

## 4. `IC_SAR` Register

| Item | Value |
|---|---|
| Name | `IC_SAR` |
| Description | I2C Target Device Address Register |
| Offset | `0x008` |
| Size | 32 bits |
| Exists | Always |

### 4.1 `IC_SAR` Field Summary

| Bits | Name | Access | Reset | Exists | Volatile | Description / Values |
|---:|---|---|---|---|---|---|
| `31:10` | `RSVD_IC_SAR` | R | `0x0` | Always | true | Reserved bits, read only |
| `9:0` | `IC_SAR` | R/W | `IC_DEFAULT_SLAVE_ADDR` | Always | true | Holds target device address when I2C operates as target. For 7-bit addressing or SMBus `IC_SMBUS=1`, only `IC_SAR[6:0]` is used. Writable only when I2C interface is disabled, `IC_ENABLE[0]=0`; writes at other times have no effect |

Note: Default hardware does not prevent programming reserved addresses `0x00` to `0x07`, or `0x78` to `0x7f`; correct operation is not guaranteed for reserved values.

## 5. `IC_HS_MADDR` Register

| Item | Value |
|---|---|
| Name | `IC_HS_MADDR` |
| Description | I2C High Speed Controller Mode Code Address Register |
| Offset | `0x00c` |
| Size | 32 bits |
| Exists | `IC_MAX_SPEED_MODE == 3` |

### 5.1 `IC_HS_MADDR` Field Summary

| Bits | Name | Access | Reset | Exists | Description / Values |
|---:|---|---|---|---|---|
| `31:3` | `RSVD_IC_HS_MAR` | R | `0x0` | Always | Reserved bits, read only |
| `2:0` | `IC_HS_MAR` | R/W | `IC_HS_MASTER_CODE` | Always | High-speed controller code value. Valid values are `0` to `7`. HS controller codes are reserved 8-bit codes `00001xxx`, not used for target addressing. Writable only when I2C interface is disabled, `IC_ENABLE[0]=0`; writes at other times have no effect |

Note: Register disappears and becomes read-only returning `0` if `IC_MAX_SPEED_MODE` is set to Standard `1` or Fast `2`.

## 6. `IC_DATA_CMD` Register

| Item | Value |
|---|---|
| Name | `IC_DATA_CMD` |
| Description | I2C Rx/Tx Data Buffer and Command Register |
| Offset | `0x010` |
| Size | 32 bits |
| Exists | Always |

This is the register CPU writes when filling TX FIFO and reads when retrieving bytes from RX FIFO.

### 6.1 Active Bits by Access

| Access | Active bits |
|---|---|
| Write, `IC_EMPTYFIFO_HOLD_MASTER_EN=1` | `10:0` |
| Write, `IC_EMPTYFIFO_HOLD_MASTER_EN=0` | `8:0` |
| Read, `IC_FIRST_DATA_BYTE_STATUS=1` | `11:0` |
| Read, `IC_FIRST_DATA_BYTE_STATUS=0` | `7:0` |

Note: To continue acknowledging reads, software must write one read command for every byte to be received. Otherwise `DW_apb_i2c` stops acknowledging.

### 6.2 `IC_DATA_CMD` Field Summary

| Bits | Name | Access | Reset | Exists | Volatile | Description / Values |
|---:|---|---|---|---|---|---|
| `31:12` | `RSVD_IC_DATA_CMD` | R | `0x0` | Always | true | Reserved bits, read only |
| `11` | `FIRST_DATA_BYTE` | R | `0x0` | `IC_FIRST_DATA_BYTE_STATUS == 1` | true | Indicates first data byte received after address phase for controller receiver or target receiver mode. For APB data width 8, two reads are needed to observe bit 11. `1`: non-sequential first data byte received; `0`: sequential data byte received |
| `10` | `RESTART` | W | `0x0` | `IC_EMPTYFIFO_HOLD_MASTER_EN` | true | Controls whether RESTART is issued before the byte. `1`: issue RESTART before this command; `0`: do not issue RESTART before this command. If `IC_RESTART_EN=0`, STOP followed by START is issued instead |
| `9` | `STOP` | W | `0x0` | `IC_EMPTYFIFO_HOLD_MASTER_EN` | true | Controls whether STOP is issued after byte. `1`: issue STOP after this command; `0`: do not issue STOP after this command. If TX FIFO is not empty, controller continues with next command; if empty, controller holds SCL low and stalls bus until new command is available |
| `8` | `CMD` | W | `0x0` | Always | true | Direction command when acting as controller. `1`: controller read command; `0`: controller write command. For target receiver mode this bit is don't-care. Read after General Call causes `TX_ABRT`; writing `1` after `RD_REQ` interrupt causes `TX_ABRT` |
| `7:0` | `DAT` | R/W | `0x0` | Always | true | Data byte transmitted or received. For write command, `DAT[7:0]` is transmit data. For read command, written `DAT[7:0]` is ignored; reading returns received data |

### 6.3 `IC_DATA_CMD` Command Encoding

| Operation | APB write to `IC_DATA_CMD` |
|---|---|
| Write one byte, no STOP/RESTART | `{CMD=0, DAT=data}` |
| Write final byte with STOP | `{STOP=1, CMD=0, DAT=data}` when bit 9 exists |
| Request one read byte, no STOP/RESTART | `{CMD=1}`; `DAT` ignored |
| Request final read byte with STOP | `{STOP=1, CMD=1}` when bit 9 exists |
| Repeated-start read after write | write command(s), then read command with `RESTART=1`; final read command with `STOP=1` |

For 7-bit DUT master + VIP slave smoke:

1. Disable controller via `IC_ENABLE`.
2. Program `IC_CON` for controller mode and speed.
3. Program `IC_TAR` with VIP slave address.
4. Program timing registers.
5. Enable controller.
6. For write: wait TX FIFO not full, write `IC_DATA_CMD = data`.
7. For read: wait TX FIFO not full, write `IC_DATA_CMD[8]=1` once per byte, then poll RX FIFO and read `IC_DATA_CMD[7:0]`.

## 7. TB Integration TODO

## 7. `IC_ENABLE` Register

| Item | Value |
|---|---|
| Name | `IC_ENABLE` |
| Description | I2C Enable Register |
| Offset | `0x06c` |
| Size | 32 bits |
| Exists | Always |

### 7.1 `IC_ENABLE` Field Summary

| Bits | Name | Access | Reset | Exists | Description / Values |
|---:|---|---|---|---|---|
| `31:26` | `RSVD_IC_ENABLE_2` | R | `0x0` | Always | Reserved bits, read only |
| `25` | `IC_SAR4_SMBUS_ALERT_EN` | R/W | `0x0` | `(IC_MSAR_SMBUS_ALERT_EN == 1) && (IC_NUM_SARS >= 4)` | Controls SMBALERT assertion for `IC_SAR4`. Auto-cleared after controller acknowledgment for Alert Response address. `1`: `IC_SAR4` target initiates Alert signal; `0`: does not initiate Alert signal |
| `24` | `IC_SAR3_SMBUS_ALERT_EN` | R/W | `0x0` | `(IC_MSAR_SMBUS_ALERT_EN == 1) && (IC_NUM_SARS >= 3)` | Controls SMBALERT assertion for `IC_SAR3`. Auto-cleared after controller acknowledgment for Alert Response address. `1`: `IC_SAR3` target initiates Alert signal; `0`: does not initiate Alert signal |
| `23` | `IC_SAR2_SMBUS_ALERT_EN` | R/W | `0x0` | `(IC_MSAR_SMBUS_ALERT_EN == 1) && (IC_NUM_SARS >= 2)` | Controls SMBALERT assertion for `IC_SAR2`. Auto-cleared after controller acknowledgment for Alert Response address. `1`: `IC_SAR2` target initiates Alert signal; `0`: does not initiate Alert signal |
| `22` | `IC_SAR4_EN` | R/W | `0x0` | `(IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 4)` | Enables target device address `IC_SAR4`. Must be updated only when `IC_ENABLE[0]=0`. `1`: `IC_SAR4` enabled and matching address is acknowledged; `0`: `IC_SAR4` disabled and matching address is NACKed |
| `21` | `IC_SAR3_EN` | R/W | `0x0` | `(IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 3)` | Enables target device address `IC_SAR3`. Must be updated only when `IC_ENABLE[0]=0`. `1`: enabled; `0`: disabled |
| `20` | `IC_SAR2_EN` | R/W | `0x0` | `(IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 2)` | Enables target device address `IC_SAR2`. Must be updated only when `IC_ENABLE[0]=0`. `1`: enabled; `0`: disabled |
| `19` | `IC_SAR_EN` | R/W | `0x1` | `IC_MULTI_SAR_EN == 1` | Enables target device address `IC_SAR`. Must be updated only when `IC_ENABLE[0]=0`. `1`: `IC_SAR` enabled; `0`: `IC_SAR` disabled |
| `18` | `SMBUS_ALERT_EN` | R/W | `0x0` | `IC_SMBUS_SUSPEND_ALERT == 1` | Controls SMBALERT assertion for `IC_SAR`. Auto-cleared after controller acknowledgment for Alert Response address. `1`: `IC_SAR` target initiates Alert signal; `0`: does not initiate Alert signal |
| `17` | `SMBUS_SUSPEND_EN` | R/W | `0x0` | `IC_SMBUS_SUSPEND_ALERT == 1` | Controls SMBUS signal assertion/deassertion. `1`: host/controller initiates SMBus suspend mode; `0`: does not initiate suspend mode |
| `16` | `SMBUS_CLK_RESET` | R/W | `0x0` | `IC_SMBUS == 1` | SMBus host mode clock reset. Only enabled when controller is idle. When enabled, SMBCLK is held low for `IC_SCL_STUCK_TIMEOUT` `ic_clk` cycles to reset SMBus target devices. `1`: initiate reset mechanism; `0`: do not initiate |
| `15:4` | `RSVD_IC_ENABLE_1` | R | `0x0` | Always | Reserved bits, read only |
| `3` | `SDA_STUCK_RECOVERY_ENABLE` | R/W | `0x0` | `IC_BUS_CLEAR_FEATURE == 1` | Initiates SDA stuck-at-low recovery mechanism when `IC_TX_ABRT_SOURCE[17]` indicates SDA stuck low. Sends at most 9 SCL clocks and STOP to release SDA, then auto-clears. `1`: recovery enabled; `0`: disabled |
| `2` | `TX_CMD_BLOCK` | R/W | `IC_TX_CMD_BLOCK_DEFAULT` | `IC_TX_CMD_BLOCK == 1` | Controller mode command block. `1`: block I2C data transmission even if TX FIFO has data; `0`: start transmission automatically when first data is available. To block command execution, set only when TX FIFO empty `IC_STATUS[2]=1` and controller idle `IC_STATUS[5]=0` |
| `1` | `ABORT` | R/W | `0x0` | Always | Terminates controller transfer. Can only be set when `ENABLE=1`; otherwise ignored. Software cannot clear this bit after setting it. Controller issues STOP and flushes TX FIFO after current transfer, then sets `TX_ABRT` interrupt and auto-clears `ABORT`. `1`: terminate in progress; `0`: no terminate |
| `0` | `ENABLE` | R/W | `0x0` | Always | Enables/disables `DW_apb_i2c`. `1`: enabled; `0`: disabled. When disabled, TX/RX FIFOs are flushed and held erased. Interrupt status remains active until the block reaches IDLE. With async `pclk` and `ic_clk`, enable/disable has a two `ic_clk` delay |

### 7.2 `IC_ENABLE` Programming Notes

| Purpose | Procedure / condition |
|---|---|
| Configure registers | Write `IC_ENABLE[0]=0`, wait until disabled/idle status is observed, then program `IC_CON`, `IC_TAR`, timing, thresholds |
| Enable controller for transfer | Write `IC_ENABLE[0]=1`; for async `pclk/ic_clk`, wait at least documented synchronization delay or poll `IC_ENABLE_STATUS` once available |
| Disable controller | Write `IC_ENABLE[0]=0`; TX/RX FIFOs flush; interrupt status may remain active until IDLE |
| Abort active controller transfer | If `ENABLE=1`, write `ABORT=1`; wait for transfer termination and `ABORT` auto-clear / `TX_ABRT` status |
| Block queued controller commands | Set `TX_CMD_BLOCK=1` only when `IC_STATUS.TFE=1` and `IC_STATUS.MST_ACTIVITY=0`; queued TX FIFO commands are not executed until bit is unset |
| Target multi-address enables | Update `IC_SAR_EN`, `IC_SAR2_EN`, `IC_SAR3_EN`, `IC_SAR4_EN` only when `IC_ENABLE[0]=0` |

### 7.3 Minimal Enable Flow for DUT Master Test

```text
disable:
  write IC_ENABLE = 0
  poll IC_STATUS[1] TFNF == 1
  poll IC_STATUS[2] TFE == 1
  poll IC_STATUS[3] RFNE == 0
  poll IC_STATUS[5] MST_ACTIVITY == 0

configure:
  write IC_CON
  write IC_TAR
  write timing registers

enable:
  write IC_ENABLE[0] = 1
  poll IC_ENABLE_STATUS once fields are available
```

## 8. `IC_ENABLE_STATUS` Register

| Item | Value |
|---|---|
| Name | `IC_ENABLE_STATUS` |
| Description | I2C Enable Status Register |
| Offset | `0x09c` |
| Size | 32 bits |
| Exists | Always |
| Access | Read-only |

This register reports `DW_apb_i2c` hardware enable/disable status after software writes `IC_ENABLE[0]`.

Rules from the document:
- If `IC_ENABLE[0]` has been set to `1`, bits `2:1` are forced to `0`, and bit `0` is forced to `1`.
- If `IC_ENABLE[0]` has been set to `0`, bits `2:1` are valid as soon as bit `0` is read as `0`.
- After writing `IC_ENABLE[0]=0`, there can be a delay before bit `0` reads `0`, because disabling depends on I2C bus activities.

### 8.1 `IC_ENABLE_STATUS` Field Summary

| Bits | Name | Access | Reset | Exists | Volatile | Description / Values |
|---:|---|---|---|---|---|---|
| `31:3` | `RSVD_IC_ENABLE_STATUS` | R | `0x0` | Always | true | Reserved bits, read only |
| `2` | `SLV_RX_DATA_LOST` | R | `0x0` | Always | true | Target received data lost. Set when target-receiver is terminated with at least one byte received because `IC_ENABLE[0]` changed from `1` to `0`. `1`: target RX data lost; `0`: not lost. CPU can safely read this bit when `IC_EN` bit 0 reads `0` |
| `1` | `SLV_DISABLED_WHILE_BUSY` | R | `0x0` | Always | true | Target disabled while busy. Set when target operation is terminated by changing `IC_ENABLE[0]` from `1` to `0` while receiving address/data or while transfer has not taken effect. `1`: target disabled while active; `0`: target disabled while idle. CPU can safely read this bit when `IC_EN` bit 0 reads `0` |
| `0` | `IC_EN` | R | `0x0` | Always | true | I2C enable status reflecting output port `ic_en`. `1`: I2C enabled; `0`: I2C disabled. When this bit reads `0`, CPU can safely read bits `2:1` |

### 8.2 Enable/Disable Polling Usage

| Purpose | Polling condition |
|---|---|
| Wait enable complete | `IC_ENABLE_STATUS.IC_EN == 1` |
| Wait disable complete | `IC_ENABLE_STATUS.IC_EN == 0` |
| Check disable side effects | After `IC_EN == 0`, check `SLV_RX_DATA_LOST` and `SLV_DISABLED_WHILE_BUSY` |

For DUT master smoke, this register gives a cleaner enable/disable handshake than using `IC_STATUS` alone.

## 9. `IC_RAW_INTR_STAT` Register

| Item | Value |
|---|---|
| Name | `IC_RAW_INTR_STAT` |
| Description | I2C Raw Interrupt Status Register |
| Offset | `0x034` |
| Size | 32 bits |
| Exists | Always |
| Access | Read-only |

Unlike `IC_INTR_STAT`, these bits are not masked, so they always show the true raw interrupt status of `DW_apb_i2c`.

### 9.1 `IC_RAW_INTR_STAT` Field Summary

| Bits | Name | Access | Reset | Exists | Volatile | Description / Values |
|---:|---|---|---|---|---|---|
| `31:20` | `RSVD_IC_RAW_INTR_STAT` | R | `0x0` | Always | true | Reserved bits, read only |
| `19` | `SLV_ADDR4_TAG` | R | `0x0` | `(IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 4)` | true | Target address `IC_SAR4` has been addressed while acting as target. Used with `WR_REQ/RD_REQ`. `1`: interrupt active; `0`: inactive |
| `18` | `SLV_ADDR3_TAG` | R | `0x0` | `(IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 3)` | true | Target address `IC_SAR3` has been addressed while acting as target. Used with `WR_REQ/RD_REQ`. `1`: interrupt active; `0`: inactive |
| `17` | `SLV_ADDR2_TAG` | R | `0x0` | `(IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 2)` | true | Target address `IC_SAR2` has been addressed while acting as target. Used with `WR_REQ/RD_REQ`. `1`: interrupt active; `0`: inactive |
| `16` | `SLV_ADDR1_TAG` | R | `0x0` | `(IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 1)` | true | Target address `IC_SAR` has been addressed while acting as target. Used with `WR_REQ/RD_REQ`. `1`: interrupt active; `0`: inactive |
| `15` | `WR_REQ` | R | `0x0` | `IC_MULTI_SAR_EN == 1` | true | Set when acting as target and another controller attempts to write data into `DW_apb_i2c`. Can be used with address tag bits to determine which target address received transfer. `1`: active; `0`: inactive |
| `14` | `SCL_STUCK_AT_LOW` | R | `0x0` | `IC_BUS_CLEAR_FEATURE == 1` | true | SCL line stuck low for `IC_SCL_STUCK_LOW_TIMEOUT` `ic_clk` periods. Enabled only when `IC_BUS_CLEAR_FEATURE=1` and `IC_ULTRA_FAST_MODE=0`. `1`: active; `0`: inactive |
| `13` | `MASTER_ON_HOLD` | R | `0x0` | Always | true | Controller is holding bus and TX FIFO is empty. Enabled only when `I2C_DYNAMIC_TAR_UPDATE=1` and `IC_EMPTYFIFO_HOLD_MASTER_EN=1`. `1`: active; `0`: inactive |
| `12` | `RESTART_DET` | R | `0x0` | Always | true | RESTART condition occurred while operating in target mode and target is addressed. Enabled only when `IC_SLV_RESTART_DET_EN=1`. In high-speed mode during START BYTE, target is not addressed and this interrupt is not generated. `1`: active; `0`: inactive |
| `11` | `GEN_CALL` | R | `0x0` | Always | true | General Call address received and acknowledged. Stays set until disabled or `IC_CLR_GEN_CALL` is read. Stores received data in RX buffer. `1`: active; `0`: inactive |
| `10` | `START_DET` | R | `0x0` | Always | true | START or RESTART condition occurred on I2C interface, target or controller mode. `1`: active; `0`: inactive |
| `9` | `STOP_DET` | R | `0x0` | Always | true | STOP condition occurred on I2C interface. Target behavior depends on `IC_CON[7]`; controller behavior depends on `IC_CON[10]`. `1`: active; `0`: inactive |
| `8` | `ACTIVITY` | R | `0x0` | Always | true | Captures I2C activity and stays set until cleared. Cleared by disabling block, reading `IC_CLR_ACTIVITY`, reading `IC_CLR_INTR`, or system reset. `1`: active; `0`: inactive |
| `7` | `RX_DONE` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Target-transmitter did not receive ACK from controller for a transmitted byte, normally last byte. `1`: active; `0`: inactive |
| `6` | `TX_ABRT` | R | `0x0` | Always | true | Transmit abort. `IC_TX_ABRT_SOURCE` gives cause. TX FIFO is flushed/emptied for abort events. Cleared by reading `IC_CLR_TX_ABRT`; after clear, TX FIFO can accept APB data. `1`: active; `0`: inactive |
| `5` | `RD_REQ` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Target mode read request from another controller. Block holds bus `SCL=0` until serviced. Processor responds by writing requested data to `IC_DATA_CMD`; cleared after reading `IC_CLR_RD_REQ`. `1`: active; `0`: inactive |
| `4` | `TX_EMPTY` | R | `0x0` | Always | true | TX empty interrupt. Behavior depends on `IC_CON.TX_EMPTY_CTRL`. With `TX_EMPTY_CTRL=0`, set when TX buffer is at/below threshold. With `TX_EMPTY_CTRL=1`, set when at/below threshold and address/data command transmission for most recent popped command is complete |
| `3` | `TX_OVER` | R | `0x0` | Always | true | TX overflow. Set when TX buffer is full and processor writes another command to `IC_DATA_CMD`. If disabled, kept until state machines idle and `ic_en` goes 0. `1`: active; `0`: inactive |
| `2` | `RX_FULL` | R | `0x0` | Always | true | RX FIFO reaches or exceeds `IC_RX_TL`. Auto-cleared when FIFO level goes below threshold. If disabled, RX FIFO is flushed and bit cleared once `IC_ENABLE[0]=0`. `1`: active; `0`: inactive |
| `1` | `RX_OVER` | R | `0x0` | Always | true | RX overflow. RX FIFO full and additional byte received. If `IC_RX_FULL_HLD_BUS_EN` and `IC_CON[9]` are high, RX_OVER never occurs because RX FIFO never overflows. `1`: active; `0`: inactive |
| `0` | `RX_UNDER` | R | `0x0` | Always | true | RX underflow. Processor attempts to read receive buffer while empty by reading `IC_DATA_CMD`. If disabled, kept until idle and `ic_en` goes 0. `1`: active; `0`: inactive |

### 9.2 Raw Interrupt Usage for DUT Master Data Check

| Check | Usage |
|---|---|
| Normal transfer done | Poll `STOP_DET == 1` after final command with STOP, then clear via `IC_CLR_STOP_DET` or `IC_CLR_INTR` once clear register fields are known |
| Fatal write/read failure | If `TX_ABRT == 1`, read `IC_TX_ABRT_SOURCE` and clear via `IC_CLR_TX_ABRT` |
| RX data ready by interrupt | `RX_FULL == 1` indicates RX FIFO level reached threshold; for byte polling, `IC_STATUS.RFNE` is still simpler |
| TX FIFO service | `TX_EMPTY == 1` can be used with `IC_TX_TL`, but first smoke can use `IC_STATUS.TFNF/TFE` |
| Avoid under/overflow | `RX_UNDER`, `RX_OVER`, `TX_OVER` should remain 0 in passing smoke |

## 10. `IC_TX_ABRT_SOURCE` Register

| Item | Value |
|---|---|
| Name | `IC_TX_ABRT_SOURCE` |
| Description | I2C Transmit Terminate Source Register |
| Offset | `0x080` |
| Size | 32 bits |
| Exists | Always |
| Access | Read-only |

This register has 32 bits indicating the source of `TX_ABRT`. Except for bit 9, the register is cleared when reading `IC_CLR_TX_ABRT` or `IC_CLR_INTR`.

Special bit 9 clear rule:
- To clear `ABRT_SBYTE_NORSTRT`, first fix its source.
- Either enable RESTART `IC_CON[5]=1`, clear `SPECIAL` bit `IC_TAR[11]`, or clear `GC_OR_START` bit `IC_TAR[10]`.
- If the source is not fixed before clear, bit 9 clears for one cycle and is then reasserted.

### 10.1 `IC_TX_ABRT_SOURCE` Field Summary

| Bits | Name | Access | Reset | Exists | Volatile | Role | Description / Values |
|---:|---|---|---|---|---|---|---|
| `31:23` | `TX_FLUSH_CNT` | R | `0x0` | Always | true | Controller-Transmitter or Target-Transmitter | Number of TX FIFO data commands flushed due to `TX_ABRT`. Cleared whenever I2C is disabled |
| `22:21` | `RSVD_IC_TX_ABRT_SOURCE` | R | `0x0` | Always | true | N/A | Reserved bits, read only |
| `20` | `ABRT_DEVICE_WRITE` | R | `0x0` | `IC_DEVICE_ID == 1` | true | Controller | Device-ID transfer used write commands in TX FIFO. `1`: abort generated due to NACK for target device address; `0`: not generated |
| `19` | `ABRT_DEVICE_SLVADDR_NOACK` | R | `0x0` | `IC_DEVICE_ID == 1` | true | Controller | Device-ID transfer target address was not ACKed. `1`: abort due to NOACK for target device address; `0`: not generated |
| `18` | `ABRT_DEVICE_NOACK` | R | `0x0` | `IC_DEVICE_ID == 1` | true | Controller | Device-ID transfer device-id sent was not ACKed. `1`: abort due to NOACK for Device-ID; `0`: not generated |
| `17` | `ABRT_SDA_STUCK_AT_LOW` | R | `0x0` | `IC_BUS_CLEAR_FEATURE == 1` | true | Controller | SDA stuck at low for `IC_SDA_STUCK_AT_LOW_TIMEOUT` `ic_clk` cycles. `1`: abort generated; `0`: not generated |
| `16` | `ABRT_USER_ABRT` | R | `0x0` | Always | true | Controller-Transmitter | Controller detected transfer terminate `IC_ENABLE[1]`. `1`: terminated by controller; `0`: not present |
| `15` | `ABRT_SLVRD_INTX` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Target-Transmitter | Processor responded to target-mode read request by writing `1` in `IC_DATA_CMD.CMD`. `1`: target trying to transmit to remote controller in read mode; `0`: not present |
| `14` | `ABRT_SLV_ARBLOST` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Target-Transmitter | Target lost bus while transmitting data to remote controller. If set, `IC_TX_ABRT_SOURCE[12]` is set at same time. `1`: target lost arbitration; `0`: not present |
| `13` | `ABRT_SLVFLUSH_TXFIFO` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Target-Transmitter | Target received read command while old data exists in TX FIFO, causing TX FIFO flush. `1`: generated; `0`: not present |
| `12` | `ARB_LOST` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Controller-Transmitter or Target-Transmitter | Controller lost arbitration; or if bit 14 also set, target-transmitter lost arbitration. `1`: arbitration lost; `0`: not present |
| `11` | `ABRT_MASTER_DIS` | R | `0x0` | Always | true | Controller-Transmitter or Controller-Receiver | User tries to initiate controller operation when controller is disabled. `1`: generated; `0`: not present |
| `10` | `ABRT_10B_RD_NORSTRT` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Controller-Receiver | RESTART disabled `IC_RESTART_EN=0` and controller sends read command in 10-bit addressing mode. `1`: generated; `0`: not present |
| `9` | `ABRT_SBYTE_NORSTRT` | R | `0x0` | Always | true | Controller | START BYTE requested while RESTART is disabled `IC_RESTART_EN=0`. Requires fixing source before clear. `1`: generated; `0`: not present |
| `8` | `ABRT_HS_NORSTRT` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Controller-Transmitter or Controller-Receiver | RESTART disabled and user attempts high-speed mode transfer. `1`: generated; `0`: not present |
| `7` | `ABRT_SBYTE_ACKDET` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Controller | Controller sent START Byte and START Byte was ACKed, which is wrong behavior. `1`: ACK detected; `0`: not present |
| `6` | `ABRT_HS_ACKDET` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Controller | High-speed controller code was ACKed, which is wrong behavior. `1`: ACK generated; `0`: not present |
| `5` | `ABRT_GCALL_READ` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Controller-Transmitter | General Call was followed by a read from bus by programming `IC_DATA_CMD[9]=1`. `1`: generated; `0`: not present |
| `4` | `ABRT_GCALL_NOACK` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Controller-Transmitter | General Call sent and no target ACKed it. `1`: generated; `0`: not present |
| `3` | `ABRT_TXDATA_NOACK` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Controller-Transmitter | Address ACKed but transmitted data byte(s) were not ACKed. `1`: data NOACK; `0`: not present |
| `2` | `ABRT_10ADDR2_NOACK` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Controller-Transmitter or Controller-Receiver | 10-bit addressing mode second address byte not ACKed. `1`: active; `0`: not generated |
| `1` | `ABRT_10ADDR1_NOACK` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Controller-Transmitter or Controller-Receiver | 10-bit addressing mode first address byte not ACKed. `1`: active; `0`: not generated |
| `0` | `ABRT_7B_ADDR_NOACK` | R | `0x0` | `IC_ULTRA_FAST_MODE == 0` | true | Controller-Transmitter or Controller-Receiver | 7-bit address was not ACKed by any target. `1`: address NOACK; `0`: not generated |

### 10.2 Abort Debug Priority for DUT Master Smoke

| Symptom | Check bits | Likely meaning |
|---|---|---|
| No VIP slave ACK / wrong address | `ABRT_7B_ADDR_NOACK`, `ABRT_10ADDR1_NOACK`, `ABRT_10ADDR2_NOACK` | `IC_TAR` address mismatch, VIP slave not started, I2C bus not connected, or 7/10-bit mode mismatch |
| Write data not ACKed | `ABRT_TXDATA_NOACK` | VIP slave NACKed data or slave sequence configured for NACK |
| Controller not configured | `ABRT_MASTER_DIS` | `IC_CON.MASTER_MODE` not enabled or controller mode disabled |
| Manual abort happened | `ABRT_USER_ABRT` | Software wrote `IC_ENABLE.ABORT=1` |
| Arbitration problem | `ARB_LOST` | Multi-master or line contention |
| RESTART-related setup error | `ABRT_10B_RD_NORSTRT`, `ABRT_SBYTE_NORSTRT`, `ABRT_HS_NORSTRT` | `IC_CON.IC_RESTART_EN=0` but transfer needs restart/high-speed/start-byte behavior |
| Stuck SDA | `ABRT_SDA_STUCK_AT_LOW` | Bus clear/recovery path needed |
| Device-ID/general-call misuse | `ABRT_DEVICE_*`, `ABRT_GCALL_*` | Special command mode issue |

Passing basic 7-bit write/read smoke should have:

```text
IC_RAW_INTR_STAT.TX_ABRT == 0
IC_TX_ABRT_SOURCE[20:0] == 0
```

If `TX_ABRT` is set:

```text
read IC_TX_ABRT_SOURCE
read IC_CLR_TX_ABRT or IC_CLR_INTR
re-check IC_RAW_INTR_STAT.TX_ABRT == 0
```

## 11. FIFO Level Registers

### 11.1 `IC_TXFLR` Register

| Item | Value |
|---|---|
| Name | `IC_TXFLR` |
| Description | I2C Transmit FIFO Level Register |
| Offset | `0x074` |
| Size | 32 bits |
| Exists | Always |
| Access | Read-only |

This register contains the number of valid data entries in the transmit FIFO. It increments whenever data is placed into TX FIFO and decrements when data is taken from TX FIFO.

It is cleared when:
- I2C is disabled
- transmit terminate occurs, meaning `TX_ABRT` is set in `IC_RAW_INTR_STAT`
- target bulk transmit mode is terminated

| Bits | Name | Access | Reset | Exists | Volatile | Range variable | Description |
|---:|---|---|---|---|---|---|---|
| `31:y` | `RSVD_TXFLR` | R | `0x0` | Always | true | `TX_ABW_P1` | Reserved bits, read only |
| `x:0` | `TXFLR` | R | `0x0` | Always | true | `TX_ABW_P1 - 1` | Transmit FIFO level, number of valid data entries in TX FIFO |

Note: The exact field width is parameterized by `TX_ABW_P1`; the screenshots do not provide the numeric FIFO address-width parameter.

### 11.2 `IC_RXFLR` Register

| Item | Value |
|---|---|
| Name | `IC_RXFLR` |
| Description | I2C Receive FIFO Level Register |
| Offset | `0x078` |
| Size | 32 bits |
| Exists | Always |
| Access | Read-only |

This register contains the number of valid data entries in the receive FIFO. It increments whenever data is placed into RX FIFO and decrements when data is taken from RX FIFO.

It is cleared when:
- I2C is disabled
- transmit terminate occurs due to any event tracked in `IC_TX_ABRT_SOURCE`

| Bits | Name | Access | Reset | Exists | Volatile | Range variable | Description |
|---:|---|---|---|---|---|---|---|
| `31:y` | `RSVD_RXFLR` | R | `0x0` | Always | true | `RX_ABW_P1` | Reserved bits, read only |
| `x:0` | `RXFLR` | R | `0x0` | Always | true | `RX_ABW_P1 - 1` | Receive FIFO level, number of valid data entries in RX FIFO |

Note: The exact field width is parameterized by `RX_ABW_P1`; the screenshots do not provide the numeric FIFO address-width parameter.

### 11.3 FIFO Level Usage

| Purpose | Preferred check |
|---|---|
| Wait TX FIFO completely empty | `IC_STATUS.TFE == 1`; optional cross-check `IC_TXFLR.TXFLR == 0` |
| Wait RX data available | `IC_STATUS.RFNE == 1`; optional cross-check `IC_RXFLR.RXFLR > 0` |
| Avoid TX overflow | Poll `IC_STATUS.TFNF == 1`; optional check `IC_TXFLR` below depth |
| Avoid RX underflow | Poll `IC_STATUS.RFNE == 1` or `IC_RXFLR > 0` before reading `IC_DATA_CMD` |

## 12. Interrupt Clear Registers

### 12.1 `IC_CLR_INTR` Register

| Item | Value |
|---|---|
| Name | `IC_CLR_INTR` |
| Description | Clear Combined and Individual Interrupt Register |
| Offset | `0x040` |
| Size | 32 bits |
| Exists | Always |
| Access | Read-only, read-to-clear |

| Bits | Name | Access | Reset | Exists | Volatile | Description |
|---:|---|---|---|---|---|---|
| `31:1` | `RSVD_IC_CLR_INTR` | R | `0x0` | Always | true | Reserved bits, read only |
| `0` | `CLR_INTR` | R | `0x0` | Always | true | Read this register to clear the combined interrupt, all individual interrupts, and `IC_TX_ABRT_SOURCE`. This bit does not clear hardware-clearable interrupts, but software-clearable interrupts. Bit 9 of `IC_TX_ABRT_SOURCE` is an exception to normal clear behavior |

### 12.2 Clear Strategy for Smoke Sequence

| Situation | Clear action |
|---|---|
| Start of test | Read `IC_CLR_INTR` once after disable/configure to clear stale software-clearable status |
| Normal final STOP observed | Read `IC_CLR_STOP_DET` to clear `IC_RAW_INTR_STAT.STOP_DET` |
| START/RESTART observed and needs clear | Read `IC_CLR_START_DET` to clear `IC_RAW_INTR_STAT.START_DET` |
| TX abort observed | Read `IC_CLR_TX_ABRT` to clear `IC_RAW_INTR_STAT.TX_ABRT` and `IC_TX_ABRT_SOURCE`; bit 9 of `IC_TX_ABRT_SOURCE` still has special source-fix requirement |
| Target-transmitter RX_DONE observed | Read `IC_CLR_RX_DONE` to clear `IC_RAW_INTR_STAT.RX_DONE` |
| Need preserve unrelated interrupt causes | Use individual clear registers instead of `IC_CLR_INTR` once their field pages are available |

### 12.3 `IC_CLR_TX_ABRT` Register

| Item | Value |
|---|---|
| Name | `IC_CLR_TX_ABRT` |
| Description | Clear TX_ABRT Interrupt Register |
| Offset | `0x054` |
| Size | 32 bits |
| Exists | Always |
| Access | Read-only, read-to-clear |

| Bits | Name | Access | Reset | Exists | Volatile | Description |
|---:|---|---|---|---|---|---|
| `31:1` | `RSVD_IC_CLR_TX_ABRT` | R | `0x0` | Always | true | Reserved bits, read only |
| `0` | `CLR_TX_ABRT` | R | `0x0` | Always | true | Read this register to clear `TX_ABRT` interrupt bit 6 of `IC_RAW_INTR_STAT` and the `IC_TX_ABRT_SOURCE` register. It also releases TX FIFO from flushed/reset state, allowing more writes to TX FIFO. Bit 9 of `IC_TX_ABRT_SOURCE` is an exception to normal clear behavior |

### 12.4 `IC_CLR_RX_DONE` Register

| Item | Value |
|---|---|
| Name | `IC_CLR_RX_DONE` |
| Description | Clear RX_DONE Interrupt Register |
| Offset | `0x058` |
| Size | 32 bits |
| Exists | `IC_ULTRA_FAST_MODE == 0` |
| Access | Read-only, read-to-clear |

| Bits | Name | Access | Reset | Exists | Volatile | Description |
|---:|---|---|---|---|---|---|
| `31:1` | `RSVD_IC_CLR_RX_DONE` | R | `0x0` | Always | true | Reserved bits, read only |
| `0` | `CLR_RX_DONE` | R | `0x0` | Always | true | Read this register to clear `RX_DONE` interrupt bit 7 of `IC_RAW_INTR_STAT` |

### 12.5 `IC_CLR_STOP_DET` Register

| Item | Value |
|---|---|
| Name | `IC_CLR_STOP_DET` |
| Description | Clear STOP_DET Interrupt Register |
| Offset | `0x060` |
| Size | 32 bits |
| Exists | Always |
| Access | Read-only, read-to-clear |

| Bits | Name | Access | Reset | Exists | Volatile | Description |
|---:|---|---|---|---|---|---|
| `31:1` | `RSVD_IC_CLR_STOP_DET` | R | `0x0` | Always | true | Reserved bits, read only |
| `0` | `CLR_STOP_DET` | R | `0x0` | Always | true | Read this register to clear `STOP_DET` interrupt bit 9 of `IC_RAW_INTR_STAT` |

### 12.6 `IC_CLR_START_DET` Register

| Item | Value |
|---|---|
| Name | `IC_CLR_START_DET` |
| Description | Clear START_DET Interrupt Register |
| Offset | `0x064` |
| Size | 32 bits |
| Exists | Always |
| Access | Read-only, read-to-clear |

| Bits | Name | Access | Reset | Exists | Volatile | Description |
|---:|---|---|---|---|---|---|
| `31:1` | `RSVD_IC_CLR_START_DET` | R | `0x0` | Always | true | Reserved bits, read only |
| `0` | `CLR_START_DET` | R | `0x0` | Always | true | Read this register to clear `START_DET` interrupt bit 10 of `IC_RAW_INTR_STAT` |

## 13. Standard Speed Timing Registers

### 13.1 `IC_SS_SCL_HCNT` Register

| Item | Value |
|---|---|
| Name | `IC_SS_SCL_HCNT` |
| Description | Standard Speed I2C Clock SCL High Count Register |
| Offset | `0x014` |
| Size | 32 bits |
| Exists | `IC_ULTRA_FAST_MODE == 0` |

This register must be set before any I2C bus transaction to ensure proper I/O timing. It sets the SCL clock high-period count for standard speed.

| Bits | Name | Access | Reset | Exists | Description |
|---:|---|---|---|---|---|
| `31:16` | `RSVD_IC_SS_SCL_HIGH_COUNT` | R | `0x0` | Always | Reserved bits, read only |
| `15:0` | `IC_SS_SCL_HCNT` | Varies | `IC_SS_SCL_HIGH_COUNT` | Always | Standard speed SCL high count. Writable only when I2C interface is disabled, `IC_ENABLE[0]=0`; writes at other times have no effect. If `IC_HC_COUNT_VALUES==1`, read-only; otherwise read-write |

Minimum valid value:

```text
(IC_ULTRA_FAST_MODE == 1) ? 3 :
((IC_CLK_FREQ_OPTIMIZATION == 1) ? 1 : 6)
```

Notes:
- Hardware prevents values below minimum; attempted lower writes result in minimum valid value being set.
- For APB data width 8, program lower byte first, then upper byte.
- Do not program above `65525`, because the block uses a 16-bit counter to flag bus idle when this counter reaches `IC_SS_SCL_HCNT + 10`.

### 13.2 `IC_SS_SCL_LCNT` Register

| Item | Value |
|---|---|
| Name | `IC_SS_SCL_LCNT` |
| Description | Standard Speed I2C Clock SCL Low Count Register |
| Offset | `0x018` |
| Size | 32 bits |
| Exists | `IC_ULTRA_FAST_MODE == 0` |

This register must be set before any I2C bus transaction to ensure proper I/O timing. It sets the SCL clock low-period count for standard speed.

| Bits | Name | Access | Reset | Exists | Description |
|---:|---|---|---|---|---|
| `31:16` | `RSVD_IC_SS_SCL_LOW_COUNT` | R | `0x0` | Always | Reserved bits, read only |
| `15:0` | `IC_SS_SCL_LCNT` | Varies | `IC_SS_SCL_LOW_COUNT` | Always | Standard speed SCL low count. Writable only when I2C interface is disabled, `IC_ENABLE[0]=0`; writes at other times have no effect. If `IC_HC_COUNT_VALUES==1`, read-only; otherwise read-write |

Minimum valid value:

```text
(IC_ULTRA_FAST_MODE == 1) ? 5 :
((IC_CLK_FREQ_OPTIMIZATION == 1) ? 6 : 8)
```

Notes:
- Hardware prevents values below minimum; attempted lower writes result in minimum valid value being set.
- For APB data width 8, program lower byte first, then upper byte.

### 13.3 Minimal Standard-Speed Timing Setup

For first smoke, use standard speed by setting `IC_CON.SPEED = 1`, then program:

```text
IC_SS_SCL_HCNT[15:0] = project-selected high count
IC_SS_SCL_LCNT[15:0] = project-selected low count
```

The actual numeric count depends on `ic_clk` frequency and timing target. The screenshot references “IC_CLK Frequency Configuration” but does not include the formula table for deriving project values.

## 14. `IC_STATUS` Register

| Item | Value |
|---|---|
| Name | `IC_STATUS` |
| Description | I2C Status Register |
| Offset | `0x070` |
| Size | 32 bits |
| Exists | Always |
| Access | Read-only |

This read-only register indicates current transfer status and FIFO status. It can be read at any time. No bit in this register requests an interrupt.

When I2C is disabled by writing `0` to `IC_ENABLE[0]`:
- bits `1` and `2` are set to `1`
- bits `3` and `10` are set to `0`

When controller or target state machines go idle and `ic_en=0`:
- bits `5` and `6` are set to `0`

### 8.1 `IC_STATUS` Field Summary

| Bits | Name | Access | Reset | Exists | Volatile | Description / Values |
|---:|---|---|---|---|---|---|
| `31:27` | `RSVD_IC_STATUS_2` | R | `0x0` | Always | true | Reserved bits, read only |
| `26` | `SMBUS_SLAVE_ADDR4_RESOLVED` | R | `0x0` | `(IC_SMBUS_ARP == 1) && (IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 4)` | true | Indicates whether target address 4 `IC_SAR4` is resolved by ARP controller. `1`: resolved; `0`: not resolved |
| `25` | `SMBUS_SLAVE_ADDR4_VALID` | R | `IC_PERSISTANT_SLV_ADDR4_DEFAULT` | `(IC_SMBUS_ARP == 1) && (IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 4)` | true | Indicates whether target address 4 `IC_SAR4` is valid. `1`: valid; `0`: not valid |
| `24` | `SMBUS_SLAVE_ADDR3_RESOLVED` | R | `0x0` | `(IC_SMBUS_ARP == 1) && (IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 3)` | true | Indicates whether target address 3 `IC_SAR3` is resolved by ARP controller. `1`: resolved; `0`: not resolved |
| `23` | `SMBUS_SLAVE_ADDR3_VALID` | R | `IC_PERSISTANT_SLV_ADDR3_DEFAULT` | `(IC_SMBUS_ARP == 1) && (IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 3)` | true | Indicates whether target address 3 `IC_SAR3` is valid. `1`: valid; `0`: not valid |
| `22` | `SMBUS_SLAVE_ADDR2_RESOLVED` | R | `0x0` | `(IC_SMBUS_ARP == 1) && (IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 2)` | true | Indicates whether target address 2 `IC_SAR2` is resolved by ARP controller. `1`: resolved; `0`: not resolved |
| `21` | `SMBUS_SLAVE_ADDR2_VALID` | R | `IC_PERSISTANT_SLV_ADDR2_DEFAULT` | `(IC_SMBUS_ARP == 1) && (IC_MULTI_SAR_EN == 1) && (IC_NUM_SARS >= 2)` | true | Indicates whether target address 2 `IC_SAR2` is valid. `1`: valid; `0`: not valid |
| `20` | `SMBUS_ALERT_STATUS` | R | `0x0` | `IC_SMBUS_SUSPEND_ALERT == 1` | true | Indicates SMBus Alert signal status `ic_smbalert_in_n`. `1`: SMBus Alert asserted; `0`: not asserted |
| `19` | `SMBUS_SUSPEND_STATUS` | R | `0x0` | `IC_SMBUS_SUSPEND_ALERT == 1` | true | Indicates SMBus Suspend signal status `ic_smbus_in_n`. `1`: SMBus system is in suspended mode; `0`: not suspended |
| `18` | `SMBUS_SLAVE_ADDR_RESOLVED` | R | `0x0` | `IC_SMBUS_ARP == 1` | true | Indicates whether target address `ic_sar` is resolved by ARP controller. `1`: resolved; `0`: not resolved |
| `17` | `SMBUS_SLAVE_ADDR_VALID` | R | `IC_PERSISTANT_SLV_ADDR_DEFAULT` | `IC_SMBUS_ARP == 1` | true | Indicates whether target address `ic_sar` is valid. `1`: valid; `0`: not valid |
| `16` | `SMBUS_QUICK_CMD_BIT` | R | `0x0` | `IC_SMBUS == 1` | true | Indicates R/W bit of Quick command received; cleared after software reads this bit. `1`: Quick command read/write set to 1; `0`: set to 0 |
| `15:13` | `RSVD_IC_STATUS_1` | R | `0x0` | Always | true | Reserved bits, read only |
| `12` | `SLV_ISO_SAR_DATA_CLK_STRETCH` | R | `0x0` | `(IC_MULTI_SAR_EN == 1) && (IC_STAT_FOR_CLK_STRETCH == 1)` | true | Target mode bus hold for isolating write-transfer data for one target address from another. `1`: holding bus; `0`: not holding bus |
| `11` | `SDA_STUCK_NOT_RECOVERED` | R | `0x0` | `IC_BUS_CLEAR_FEATURE == 1` | true | Indicates SDA stuck at low is not recovered after recovery mechanism. Target mode not applicable. `1`: not recovered; `0`: recovered |
| `10` | `SLV_HOLD_RX_FIFO_FULL` | R | `0x0` | `IC_STAT_FOR_CLK_STRETCH == 1` | true | Target mode bus hold due to RX FIFO full and one additional byte received. Applies when `IC_RX_FULL_HLD_BUS_EN=1` and `IC_CON[9]` is high. `1`: target holds bus; `0`: not holding bus or not due to RX FIFO full |
| `9` | `SLV_HOLD_TX_FIFO_EMPTY` | R | `0x0` | `IC_STAT_FOR_CLK_STRETCH == 1` | true | Target mode bus hold for read request when TX FIFO is empty. `1`: target holds bus; `0`: not holding bus or not due to TX FIFO empty |
| `8` | `MST_HOLD_RX_FIFO_FULL` | R | `0x0` | `IC_STAT_FOR_CLK_STRETCH == 1` | true | Controller mode bus hold due to RX FIFO full and one additional byte received. Applies when `IC_RX_FULL_HLD_BUS_EN=1` and `IC_CON[9]` is high. `1`: controller holds bus; `0`: not holding bus or not due to RX FIFO full |
| `7` | `MST_HOLD_TX_FIFO_EMPTY` | R | `0x0` | `IC_STAT_FOR_CLK_STRETCH == 1` | true | Controller mode hold because TX FIFO is empty and previous command does not have STOP. Applies when `IC_EMPTYFIFO_HOLD_MASTER_EN=1`. `1`: controller holds bus; `0`: not holding bus or not due to TX FIFO empty |
| `6` | `SLV_ACTIVITY` | R | `0x0` | Always | true | Target FSM activity. `1`: target not idle; `0`: target idle |
| `5` | `MST_ACTIVITY` | R | `0x0` | Always | true | Controller FSM activity. `1`: controller not idle; `0`: controller idle. `IC_STATUS[0]` `ACTIVITY` is OR of `SLV_ACTIVITY` and `MST_ACTIVITY` |
| `4` | `RFF` | R | `0x0` | Always | true | Receive FIFO completely full. `1`: RX FIFO full; `0`: RX FIFO not full |
| `3` | `RFNE` | R | `0x0` | Always | true | Receive FIFO not empty. `1`: RX FIFO not empty; `0`: RX FIFO empty |
| `2` | `TFE` | R | `0x1` | Always | true | Transmit FIFO completely empty. `1`: TX FIFO empty; `0`: TX FIFO not empty |
| `1` | `TFNF` | R | `0x1` | Always | true | Transmit FIFO not full. `1`: TX FIFO not full; `0`: TX FIFO full |
| `0` | `ACTIVITY` | R | `0x0` | Always | true | I2C activity. `1`: I2C active; `0`: I2C idle |

### 8.2 `IC_STATUS` Polling Usage for I2C Read/Write

| Polling purpose | Condition |
|---|---|
| Can push a byte/command to TX FIFO | `IC_STATUS.TFNF == 1` |
| TX FIFO drained | `IC_STATUS.TFE == 1` |
| RX data available | `IC_STATUS.RFNE == 1` |
| I2C transfer idle | `IC_STATUS.ACTIVITY == 0` and, for controller mode, `IC_STATUS.MST_ACTIVITY == 0` |
| RX FIFO overflow prevention | Ensure `IC_STATUS.RFF == 0` before issuing too many read commands if RX servicing is slow |
| Disabled/idle sanity after `IC_ENABLE=0` | `TFNF == 1`, `TFE == 1`, `RFNE == 0`, `SLV_HOLD_RX_FIFO_FULL == 0`; then wait `MST_ACTIVITY == 0` and `SLV_ACTIVITY == 0` |

For DUT master + VIP slave data check, the first APB sequence can use:

```text
write byte:
  poll IC_STATUS[1] TFNF == 1
  write IC_DATA_CMD = {STOP?, CMD=0, DAT}
  poll IC_STATUS[2] TFE == 1
  poll IC_STATUS[0] ACTIVITY == 0

read byte:
  poll IC_STATUS[1] TFNF == 1
  write IC_DATA_CMD = {STOP?, CMD=1}
  poll IC_STATUS[3] RFNE == 1
  read IC_DATA_CMD[7:0]
```

## 15. TB Integration TODO

| Item | Status |
|---|---|
| Build APB register access sequence | 已在 `seq_lib/common/base_virt_seq.sv` 增加 `apb_vip_write32` / `apb_vip_read32`，复用 `apb_master_directed_write_sequence` / `apb_master_directed_read_sequence`，不手写 `apb_write` / `apb_read` bus task |
| Add I2C init sequence for controller/master mode | 已在 `seq_lib/i2c_seq/i2c_basic_sequence.sv` 编写 disable-config-enable-write-read-check smoke 主流程 |
| Add I2C init sequence for target/slave mode | 已在 `seq_lib/i2c_seq/i2c_slave_smoke_seq.sv` 增加 target/slave 配置、读回确认、VIP master write/read 访问、RX/TX FIFO 检查和 `I2C_TARGET_ACTIVITY` 诊断 |
| Add register model/RAL | 待补；需要完整字段 reset/access/exists |
| Add smoke register programming sequence | 已完成最小版本；`+I2C_SPEED_MODE=standard/fast/fast_plus/high` 会设置验证侧 `ic_clk` half period，并写入对应 SCL count 寄存器 |

## 16. Current Smoke Register Flow

### 16.1 DUT Master + VIP Slave Smoke

| Step | Register/API | Detail |
|---|---|---|
| 1 | `IC_ENABLE` | 写 `0` disable 控制器 |
| 2 | `IC_ENABLE_STATUS.IC_EN` | 轮询为 `0` |
| 3 | `IC_STATUS.TFE` | 轮询 TX FIFO empty |
| 4 | `IC_CLR_INTR` | read-to-clear 历史中断 |
| 5 | `IC_CON` | 写 controller/master, 7-bit, `IC_RESTART_EN=1`, `IC_SLAVE_DISABLE=1`, speed 根据 `+I2C_SPEED_MODE` |
| 6 | `IC_TAR` | 写 `+I2C_TARGET_ADDR`，默认 `0x55` |
| 7 | timing registers | standard 写 `IC_SS_SCL_HCNT/LCNT`；fast/fast_plus 写 `IC_FS_SCL_HCNT/LCNT`；high 写 `IC_HS_SCL_HCNT/LCNT` |
| 8 | `IC_ENABLE` | 写 `1` enable 控制器 |
| 9 | `IC_DATA_CMD` write | 写 `0x12, 0x34, 0xa5, 0x5a`，末字节带 `STOP` |
| 10 | `IC_DATA_CMD` read command | 发 5 个 read command，末命令带 `STOP` |
| 11 | `IC_STATUS.RFNE` | 每个读命令后等待 RX FIFO 非空 |
| 12 | `IC_DATA_CMD[7:0]` | 比较预期 `{0xff, 0x00, 0x00, 0x00, 0x00}`，该预期来自当前 `i2c_slv_directed_sequence` 的 `data = new[5]; data[0] = 'hff` |
| 13 | `IC_RAW_INTR_STAT.TX_ABRT` / `IC_TX_ABRT_SOURCE` | 检查无 abort；若 abort，读 `IC_CLR_TX_ABRT` 清除并报错 |

### 16.2 DUT Slave/Target + VIP Master Smoke

| Step | Register/API | Detail |
|---|---|---|
| 1 | `IC_ENABLE` | 写 `0` disable 控制器/target block |
| 2 | `IC_ENABLE_STATUS.IC_EN` | 轮询为 `0`，确认 disable handshake 完成 |
| 3 | `IC_STATUS.ACTIVITY` / `IC_STATUS.TFE` | 轮询 `ACTIVITY=0`、`TFE=1`，确认配置窗口安全 |
| 4 | `IC_CLR_INTR` | read-to-clear 历史中断 |
| 5 | `I2C_TARGET_CFG before target config` | 打印旧 `IC_CON/IC_TAR/IC_SAR/IC_ENABLE/IC_STATUS/RAW_INTR/FIFO/IC_COMP_PARAM_1`，此阶段不按 target 期望 fatal |
| 6 | `IC_CON` | 写 target/slave：默认 pure target-only `MASTER_MODE=0`、`IC_SLAVE_DISABLE=0`、`IC_10BITADDR_SLAVE=0`、`IC_RESTART_EN=1`、speed 根据 `+I2C_SPEED_MODE`；若加 `+I2C_TARGET_KEEP_MASTER=1`，则写 dual-role `MASTER_MODE=1` 做 A/B 对比 |
| 7 | `IC_TAR` | 写 `+I2C_CONTROLLER_TAR_ADDR`，默认 `0x56`；当保留 `MASTER_MODE=1` 时用于避开 `IC_TAR == IC_SAR` 的 controller self-address 限制 |
| 8 | `IC_SAR` | 写 `+I2C_TARGET_ADDR`，默认 `0x55` |
| 9 | `IC_RX_TL` / `IC_TX_TL` | 写 `0`，让 1 byte 即可触发 RX/TX 阈值相关状态 |
| 10 | `IC_SLV_DATA_NACK_ONLY` | 写 `0` 并按 bit0 读回，避免 target 数据阶段被软件配置成主动 NACK；字段细节文档未说明 |
| 11 | `IC_INTR_MASK` | 写 `0`，slave smoke 使用 raw/status polling，不依赖外部 `ic_intr`；这样可以避免 `TX_EMPTY` 或历史 masked interrupt 在 VIP 访问前把 `ic_intr` 拉高 |
| 12 | `I2C_TARGET_CFG_WRITTEN` | disabled 状态下读回 `IC_CON/IC_TAR/IC_SAR/IC_ENABLE/IC_ENABLE_STATUS`，确认 DUT 接受 target/slave 关键配置，且 `TAR_EQ_SAR7=0` |
| 13 | `IC_ENABLE` | 先写 `0x00080000`，再写 `0x00080001`；bit19 是 multi-SAR `IC_SAR_EN`，若实际不存在可能读回 0 |
| 14 | `IC_ENABLE_STATUS.IC_EN` / top-level `ic_en` | 轮询 `IC_ENABLE_STATUS[0]=1` 并等待 `vif.ic_en=1` |
| 15 | `I2C_TARGET_MODE_ON` | 再次读回确认 `MASTER_MODE=+I2C_TARGET_KEEP_MASTER`、`SLAVE_DISABLE=0`、`10BIT_SLAVE=0`、`IC_TAR=0x56`、`IC_SAR=0x55`、`ENABLE=1`、`IC_EN=1` |
| 16 | `+I2C_DUT_PAD_ACK_BRIDGE` | slave smoke 打开 TB pad ACK bridge；当 VIP master 访问 `+I2C_TARGET_ADDR` 时，在 address ACK 和 write data ACK 位拉低 `i2c_vif.SDA`，补齐当前 DUT 顶层 `ic_data_oe` 未传播内部 ACK 的问题 |
| 17 | `+I2C_DUT_PAD_ACK_BRIDGE_HOLD_NS` | 当前为 `350`。ACK bridge 在 SCL falling 后等待该时间再改变 SDA，满足 standard-mode `300ns` data hold；若配置小于 `300`，TB 自动 clamp 到 `300` |
| 18 | VIP master write DUT target | 启动 `i2c_mst_dut_slave_write_sequence`，向 address `0x55` 写 `{0x21,0x43,0x65}` |
| 19 | DUT target RX check | 轮询 `IC_STATUS.RFNE` / `IC_RAW_INTR_STAT.RX_FULL`，从 `IC_DATA_CMD[7:0]` 读出并比较 `{0x21,0x43,0x65}` |
| 20 | VIP master read DUT target | 启动 `i2c_mst_dut_slave_read_sequence`，等待 `IC_RAW_INTR_STAT.RD_REQ` |
| 21 | DUT target TX service | software 向 `IC_DATA_CMD` 写 `{0xa1,0xb2,0xc3}`，然后读 `IC_CLR_RD_REQ` |
| 22 | `IC_RAW_INTR_STAT.STOP_DET` | write/read 两段均等待 STOP，并读 `IC_CLR_STOP_DET` 清除 |
| 23 | `I2C_TARGET_ACTIVITY` | 当 RX/STOP poll 状态变化或失败时打印 `SLV_ADDR1_TAG/WR_REQ/RD_REQ/RX_FULL/SLV_ACTIVITY` 等字段，用于定位是否真正识别了地址和请求 |

## 17. Remaining Integration Gap

| Item | Current state | Required before simulation pass |
|---|---|---|
| APB VIP physical interface | 当前基线模板只有 `apb_vip_sqr_m0` 句柄占位，`tb/i2c_tb.sv` 的 DUT APB 端口仍连接 `i2c_if` 普通信号；本地未找到外部 AMBA SVT `svt_apb_if` 源文件，`vcs_com/vip.f` 指向 `/projects/platform/temp/vip/.../amba_svt` | 需要在可用 AMBA SVT 环境中按项目标准例化 APB VIP interface，并把 `MCU_I2C_WRAPPER` 的 `psel/penable/pprot/pstrb/pready/pslverr/prdata/pwrite/paddr/pwdata` 接到 APB VIP master interface，同时将真实 master sequencer 注入 `uvm_config_db` 路径 `uvm_test_top.apb_vip_sqr_m0` |
| I2C VIP slave sequencer | 当前 `tb/i2c_tb.sv` 例化了 `svt_i2c_if`，但没有创建 SVT I2C system env/agent，`i2c_vip_slv_sqr0` 仍是占位句柄 | 需要按 I2C VIP example 创建 slave agent/env，将 `svt_i2c_slave_transaction_sequencer` 注入 `uvm_config_db` 路径 `uvm_test_top.i2c_vip_slv_sqr0` |
| DUT register base address | 当前 smoke 使用 offset 作为 APB address，即 base `0x0` | 若 SoC map 非零，需要通过现有 APB VIP address mapping 或新增 plusarg/base offset 配置；文档未说明 |
