# I3C Case 解析

> 代码来源：`C:\Users\yusen\Documents\Obsidian Vault\test_case\i3c_test`

## 1. 目录结构理解

I3C case 目录是一套基于 UVM/SystemVerilog 的模块级或子系统级验证 case 集合。整体组织方式是：公共逻辑集中在 `i3c_base_test.sv`，具体 case 只负责选择场景、配置角色、调用公共 task 完成传输和检查。

| 文件/目录                               | 作用                                                                       |
| ----------------------------------- | ------------------------------------------------------------------------ |
| `i3c_test_pkg.svh`                  | I3C test package 入口，统一 include base test、define、reg struct 和各类 case      |
| `i3c_define.svh`                    | I3C0/I3C1 base address、寄存器 offset、SCU debug/status 寄存器宏定义                |
| `i3c_reg_struct.sv`                 | 寄存器 reset value、RW mask、寄存器列表，用于 reg test                                |
| `i3c_base_test.sv`                  | 所有 I3C case 的公共基类，封装 VIP 配置、IOMUX、寄存器访问、I3C 初始化、FIFO、DMA 和 scoreboard 对接 |
| `i3c0_*.sv`                         | I3C0 相关 case                                                             |
| `i3c1_*.sv`                         | I3C1 相关 case，整体逻辑与 I3C0 对称                                               |
| `i3c0_intr_test/`、`i3c1_intr_test/` | 中断类 case 的 C 程序和 Makefile，用于 CPU 侧中断处理流程                                 |

## 2. Package 组织逻辑

`i3c_test_pkg.svh` 只有在 `I3C_TEST` 宏打开时才定义 package。它导入 UVM、SoC env、DMA sequence、Synopsys I3C/I2C VIP package 和本地 I3C package，然后按顺序 include：

1. 公共宏定义：`i3c_define.svh`
2. 寄存器结构：`i3c_reg_struct.sv`
3. 公共基类：`i3c_base_test.sv`
4. I3C0 case
5. I3C1 case
6. CPU_TEST 下的中断 case

这种写法的好处是所有 case 都在同一个 package 中编译，case 之间共享同一套 base task、寄存器宏、VIP 类型和 sequence 类型。

## 3. Base Test 的职责

所有 case 都继承自 `i3c_base_test`：

```systemverilog
class xxx_test extends i3c_base_test;
```

`i3c_base_test` 是 TB 编写的核心，它承担以下职责：

| 职责               | 说明                                                                                                     |
| ---------------- | ------------------------------------------------------------------------------------------------------ |
| 环境对接             | 从 `chip_noc_base_test` 继承，拿到 SoC env、AXI master、I3C env 和 virtual sequencer                            |
| VIP 配置           | 创建 `cust_svt_mipi_i3c_system_configuration`，配置 main master、secondary master、I2C legacy slave、I3C slave |
| Factory override | 将默认 VIP transaction 替换为自定义 transaction                                                                 |
| BCR/DCR 配置       | 配置 master/slave 的 BCR、DCR、dynamic address、static address、HDR 能力                                        |
| Timing 配置        | 配置 open-drain、push-pull、start/stop、SCL high/low 等时序参数                                                  |
| config_db 分发     | 把 I3C cfg、env handle、virtual interface 分发给 sequencer 和 env                                             |
| IOMUX 配置         | 在 base `main_phase` 中根据 `m_i3c_intf.i3c_num_ctrl` 配置 I3C0/I3C1 pad                                     |
| 寄存器访问            | 封装 `noc_reg_write`，通过 AXI master sequence 访问寄存器                                                        |
| 协议配置             | 封装 block init、enable、DAA、transfer arg、transfer command、SCL timing                                      |
| 数据通路             | 封装 TX FIFO 写入、RX FIFO 读取、DMA 配置、memory 填充                                                              |
| 数据检查             | 把 DUT 侧观测数据转换为 VIP transaction，写入 scoreboard observed port                                             |

可以把 `i3c_base_test` 理解成“测试基础设施层”：它把底层寄存器位拼接、AXI 写寄存器、VIP transaction 构造这些重复工作全部收敛起来。

## 4. Base Build Phase 逻辑

`build_phase` 的典型流程如下：

```text
super.build_phase
cast SoC env
读取 plusarg，判断是否 disable VIP
factory override VIP transaction
创建并 randomize I3C system cfg
配置 master/slave 类型和地址
配置 BCR/DCR/HDR/coverage/timing
把 cfg 放到 uvm_config_db
获取 virtual i3c_intf
把 vif/cfg/env handle 分发给 I3C env 和 sequencer
创建 error catcher
```

默认 I3C VIP 结构为：

| VIP 对象 | 默认角色 |
| --- | --- |
| `master_cfg[0]` | Main Master |
| `master_cfg[1]` | Secondary Master |
| `slave_cfg[0]` | I2C Legacy Slave |
| `slave_cfg[1]` | I3C Slave |

具体 case 会在自己的 `build_phase` 中覆盖 `is_active`、静态地址使能、`i3c_scb_ctrl` 和 `i3c_num_ctrl`，从而切换当前验证拓扑。

## 5. Base Main Phase 逻辑

base `main_phase` 做的事情不直接发起传输，而是完成公共准备：

1. raise objection。
2. 根据 `m_i3c_intf.i3c_num_ctrl` 配置 IOMUX。
3. 设置 drain time。
4. drop objection。

具体 case 的 `main_phase` 通常会：

```systemverilog
phase.raise_objection(this);
super.main_phase(phase);
// case-specific register configuration and transfer
phase.drop_objection(this);
```

注意这里 case 自己也 raise/drop objection，base main 也 raise/drop。case 里调用 `super.main_phase` 的主要目的是复用 IOMUX 和 drain time 设置。

## 6. 公共 Task 解析

### 6.0 地址与寄存器速查

I3C test 中寄存器地址由 `i3c_define.svh` 统一定义。I3C0/I3C1 的选择主要由 `i3c_num` 决定：

| 选择值           | Base 宏      | 含义          |
| ------------- | ----------- | ----------- |
| `i3c_num = 0` | `I3C0_BASE` | 访问 I3C0 寄存器 |
| `i3c_num = 1` | `I3C1_BASE` | 访问 I3C1 寄存器 |

常用寄存器 offset：

| 寄存器 | Offset | 代码用途 |
| --- | ---: | --- |
| `DEVICE_CTRL` | `0x00` | 使能 controller、设置 master/slave 相关控制位、resume 等 |
| `DEVICE_ADDR` | `0x04` | 配置本机 static/dynamic address 及使能位 |
| `COMMAND_QUEUE_PORT` | `0x0c` | 写入 DAA、transfer arg、CCC、transfer command |
| `RESPONSE_QUEUE_PORT` | `0x10` | 读取 response queue 返回状态 |
| `RX_DATA_PORT` | `0x14` | 从 RX FIFO 读数据 |
| `TX_DATA_PORT` | `0x14` | 向 TX FIFO 写数据，和 RX data port 共用 offset |
| `QUEUE_THLD_CTRL` | `0x1c` | 配置 response queue threshold |
| `DATA_BUFFER_THLD_CTRL` | `0x20` | 配置 TX/RX data buffer threshold |
| `SLV_EVENT_STATUS` | `0x38` | Slave event 状态，例如 master request 使能状态 |
| `INTR_STATUS` | `0x3c` | 轮询 TX/RX/command/response/DAA 等状态 |
| `INTR_STATUS_EN` | `0x40` | 使能中断状态 |
| `INTR_SIGNAL_EN` | `0x44` | 使能中断信号输出 |
| `DEVICE_CTRL_EXTENDED` | `0xb0` | 选择 master/slave 模式，`0` 为 master，`1` 为 slave |
| `SCL_I3C_OD_TIMING` | `0xb4` | I3C open-drain SCL timing |
| `SCL_I3C_PP_TIMING` | `0xb8` | I3C push-pull SCL timing |
| `SCL_EXT_LCNT_TIMING` | `0xc8` | SDR1~SDR4 扩展 low count timing |
| `SLV_INTR_REQ` | `0x8c` | Slave 发起 master request/IBI 相关请求 |
| `DEV_ADDR_TABLE_LOC1` | `0x280` | Device Address Table 第 1 项 |

SCU 侧和 debug 相关寄存器：

| 寄存器 | Offset | 用途 |
| --- | ---: | --- |
| `MCUSS_I3C0_STAT` | `0x400` | I3C0 静态地址、状态、pad/模式相关控制 |
| `MCUSS_I3C0_SVL_DBG_PORT_H/L` | `0x410/0x414` | I3C0 debug port 高/低位 |
| `MCUSS_I3C1_STAT` | `0x418` | I3C1 静态地址、状态、pad/模式相关控制 |
| `MCUSS_I3C1_SVL_DBG_PORT_H/L` | `0x428/0x42c` | I3C1 debug port 高/低位 |

常用状态位在代码中的含义：

| 状态位 | 使用位置 | 代码含义 |
| --- | --- | --- |
| `INTR_STATUS[0]` | `i3c_wirte_data_to_txfifo` | TX FIFO 可写或 TX threshold 事件 |
| `INTR_STATUS[1]` | `i3c_read_data_from_rxfifo` | RX FIFO 有数据或 RX threshold 事件 |
| `INTR_STATUS[3]` | 多数 case 写 command 前轮询 | command queue 可继续写入 |
| `INTR_STATUS[4]` | `i3c_check_resp_status` | response queue 有响应 |
| `INTR_STATUS[8]` | Secondary Master case | dynamic address done |
| `INTR_STATUS[12]` | Secondary Master case | IBI update status |
| `INTR_STATUS[13]` | Secondary Master case | bus owner update status |

### 6.1 寄存器访问

`noc_reg_write(addr, reg_data)` 通过 `axi_master_directed_write_sequence` 发 AXI 写操作：

```text
创建 AXI write sequence
设置 waddr/wdata
启动到 axi_system[0].master[0].sequencer
```

读操作在 case 中直接调用继承来的 `noc_reg_read`。

### 6.2 I3C 初始化

`i3c_block_init(i3c_num, isi2c_mode, static_addr, dynamic_addr, resp_buf_thld, tx_empty_buf_thld, tx_start_thld, rx_buf_thld)` 是 Master 类 case 最常用的入口。

它的逻辑：

| 步骤 | 寄存器/动作 | 目的 |
| --- | --- | --- |
| 选择 base | `I3C0_BASE` 或 `I3C1_BASE` | 根据 `i3c_num` 选择实例 |
| 配置 queue threshold | `QUEUE_THLD_CTRL` | 设置 response buffer threshold |
| 配置 data buffer threshold | `DATA_BUFFER_THLD_CTRL` | 设置 TX empty、TX start、RX threshold |
| 设置 master mode | `DEVICE_CTRL_EXTENDED = 0` | DUT 作为 master |
| 打开中断 | `INTR_STATUS_EN`、`INTR_SIGNAL_EN` | 使能状态/信号中断 |
| 设置本机动态地址 | `DEVICE_ADDR` | 配置 controller 自身 dynamic address |
| 配置 DAT | `DEV_ADDR_TABLE_LOC1` | 配置目标设备 static/dynamic address，I2C mode 时置 legacy 标志 |

参数和寄存器位设置展开：

| 参数 | 典型值 | 写入位置 | 含义 |
| --- | --- | --- | --- |
| `i3c_num` | `0`/`1` | 选择 `I3C0_BASE` 或 `I3C1_BASE` | 选择 I3C 实例 |
| `isi2c_mode` | `0`/`1` | `DEV_ADDR_TABLE_LOC1[31]` | `1` 表示目标设备按 legacy I2C 设备处理 |
| `static_addr` | 常见 `7'h63`、`7'h31` | `DEV_ADDR_TABLE_LOC1[6:0]` | 目标设备静态地址 |
| `dynamic_addr` | 常见 `8'h64`、`8'he3` | `DEV_ADDR_TABLE_LOC1[23:16]` | 目标设备动态地址 |
| `resp_buf_thld` | 常见 `0` | `QUEUE_THLD_CTRL[15:8]` | response buffer threshold |
| `tx_empty_buf_thld` | 常见 `0`/`1` | `DATA_BUFFER_THLD_CTRL[2:0]` | TX empty threshold |
| `rx_buf_thld` | 常见 `0` | `DATA_BUFFER_THLD_CTRL[10:8]` | RX buffer threshold |
| `tx_start_thld` | 常见 `0`/`1` | `DATA_BUFFER_THLD_CTRL[18:16]` | TX start threshold |

`DEVICE_ADDR` 在 base task 里写入 `wdata[22:16] = 'h55`，并置 `wdata[31] = 1`。这表示配置 controller 自身 dynamic address 为 `0x55` 并使能 dynamic address 字段。目标设备地址则通过 DAT，即 `DEV_ADDR_TABLE_LOC1` 设置。

### 6.3 使能 I3C

`i3c_block_enable(i3c_num)` 读取 `DEVICE_CTRL`，将 bit31 置 1 后写回，用于使能 I3C controller。

### 6.4 设置 DAA/SETDASA

`i3c_set_daa_cmd(i3c_num, isdirect)` 向 `COMMAND_QUEUE_PORT` 写入 CCC command。`isdirect` 为 1 时使用 `0x87`，否则使用 `0x07`。从 case 使用方式看，它主要用于动态地址相关流程。

该 task 对 `COMMAND_QUEUE_PORT` 的字段拼接如下：

| 字段 | 赋值 | 含义 |
| --- | --- | --- |
| `[2:0]` | `3'h3` | command queue entry 类型，当前用于 DAA/CCC 类命令 |
| `[6:3]` | `4'h5` | transaction id/command id 类字段 |
| `[14:7]` | `0x87` 或 `0x07` | DAA/SETDASA 相关 CCC command |
| `[20:16]` | `0` | device index/参数字段 |
| `[25:21]` | `1` | transfer length/参数字段 |
| `[26]` | `1` | 使能类控制位 |
| `[30]` | `1` | command 有效/ready 类控制位 |

### 6.5 设置传输参数

`i3c_set_transfer_arg(i3c_num, data_len)` 向 command queue 写入 argument 类型命令，`data_len` 放在高 16 bit，用于指定后续 transfer 的数据长度。

字段拼接：

| 字段 | 赋值 | 含义 |
| --- | --- | --- |
| `[2:0]` | `3'h1` | command queue entry 类型，表示 transfer argument |
| `[15:8]` | `0` | argument 低字段，当前未使用 |
| `[31:16]` | `data_len` | 传输数据长度，单位按 controller 设计解释，case 中常用 `4`、`8`、`16` |

### 6.6 设置传输命令

`i3c_set_transfer_cmd(i3c_num, speed, iscp, cmd, isshortarg, isread, tr_id, isstop)` 是传输启动的关键 task。

主要字段含义：

| 参数 | 含义 |
| --- | --- |
| `speed` | 传输速率或模式，SDR0~SDR4/HDR 等 case 会改变该值 |
| `iscp` | 是否为 CCC command |
| `cmd` | CCC command code |
| `isshortarg` | 是否使用 short argument |
| `isread` | 读/写方向 |
| `tr_id` | transaction id |
| `isstop` | 是否 stop |

该 task 本质是在拼 `COMMAND_QUEUE_PORT` 的 transfer command，并通过寄存器写入触发 controller 执行。

字段拼接：

| 字段 | 来源 | 含义 |
| --- | --- | --- |
| `[2:0]` | `0` | transfer command entry 类型 |
| `[6:3]` | `tr_id` | transaction id |
| `[14:7]` | `cmd`，仅 `iscp=1` 时写入 | CCC command code |
| `[15]` | `iscp` | 是否 CCC/command present |
| `[20:16]` | `0` | DAT index，当前固定第 0 项 |
| `[23:21]` | `speed` | 速率/模式 |
| `[25]` | `0` | 保留或控制位，当前固定 0 |
| `[26]` | `1` | command 有效控制位 |
| `[27]` | `isshortarg`，仅 `speed<=4` 时设置 | 是否使用 short argument |
| `[28]` | `isread` | `0` 写传输，`1` 读传输 |
| `[30]` | `1` | command 有效/queue push |
| `[31]` | `1`，仅 `speed<=4` 时设置 | stop/terminate 类控制位 |

case 中常见 speed 编码：

| speed | 代码注释/用途 |
| ---: | --- |
| `0` | SDR0 |
| `1` | SDR1，或部分 I2C FM+ slave transmit case 中使用 |
| `2` | SDR2 |
| `3` | SDR3 |
| `4` | SDR4 |
| `6` | HDR-DDR |
| `7` | I2C FM |

case 中常见 CCC command：

| command | 出现场景 | 说明 |
| --- | --- | --- |
| `8'h02` | Broadcast CCC case | 广播 CCC，代码注释为 `entas0 cmd` |
| `8'h82` | Directed CCC case | 定向 CCC |
| `8'h87` | DAA/SETDASA 相关、I2C slave transmit 场景 | 地址分配/设置类 CCC |
| `8'h29` | SETAASA、master read 前置命令 | 地址配置/状态切换类 CCC |
| `8'h20` | HDR-DDR case | 进入 HDR-DDR 相关 command |

### 6.7 FIFO 读写

`i3c_wirte_data_to_txfifo` 的逻辑：

1. 根据 `data_lenth` 生成 `32'h5a5a5a5a + i` 测试数据。
2. 等待 `INTR_STATUS[0]`，表示 TX FIFO 可写。
3. 按 threshold 写 `TX_DATA_PORT`。
4. 将每个 32-bit word 拆成 byte，push 到 `tx_data_q`。

`i3c_read_data_from_rxfifo` 的逻辑：

1. 等待 `INTR_STATUS[1]`，表示 RX FIFO 有数据。
2. 按 threshold 读 `RX_DATA_PORT`。
3. 将读到的 32-bit word 拆成 byte，push 到 `rx_data_q`。

这里的 byte queue 是后续 scoreboard 对比的桥梁。

### 6.8 Scoreboard 对接

base test 中有几类 `*_to_vip_*_tr` task，会把 DUT 侧收发的数据封装成 VIP transaction，再写入 scoreboard observed port。

| Task                                        | 使用场景                                               |
| ------------------------------------------- | -------------------------------------------------- |
| `i3c_master_txdata_to_vip_slave_pre_tr`     | DUT master 写 slave，预期 slave 侧收到这些数据                |
| `i3c_master_rxdata_to_vip_slave_post_tr`    | DUT master 读 slave 后，对 slave 侧 observed 数据         |
| `i3c_slave_rxdata_to_vip_master_post_tr`    | DUT slave 收到 VIP master 写入数据后，对 master observed 数据 |
| `i3c_slave_txdata_to_vip_master_pre_tr`     | DUT slave 发送数据前，构造 master 侧预期 transaction          |
| `i3c_secmaster_txdata_to_vip_master_pre_tr` | Secondary Master 场景下构造一组 CCC/读写 transaction        |

典型模式是：

```text
DUT 通过寄存器/FIFO 产生真实传输
TB 将同一份 byte queue 构造成 VIP transaction
写入 scoreboard observed port
scoreboard 比对 VIP 期望和 DUT 实际行为
```

### 6.9 DMA 配置

DMA 相关 task 使用 `mcu_dma_transfer_virt_sequence`：

| Task | 方向 | 关键配置 |
| --- | --- | --- |
| `i3c_dma_write_config` | memory -> I3C TX FIFO | `tt_fc = 1`，目标外设号 `dst_per` |
| `i3c_dma_read_config` | I3C RX FIFO -> memory | `tt_fc = 2`，源外设号 `src_per` |
| `i3c_fill_memory` | 初始化 memory 数据 | 用 `sram_wr32_bd` 写 SRAM |

DMA case 的核心就是先准备 memory 数据，再配置 DMA handshake，最后启动 I3C transfer，用 VIP 对比总线上实际数据。

DMA 参数设置：

| Task | 参数 | 典型值 | 含义 |
| --- | --- | --- | --- |
| `i3c_dma_write_config` | `src_addr` | `MCU_SUB_SRAM_BASE_ADDR + 0x4000` | SRAM 源地址 |
| `i3c_dma_write_config` | `dst_addr` | `I3C0_BASE/I3C1_BASE + TX_DATA_PORT` | I3C TX FIFO 目标地址 |
| `i3c_dma_write_config` | `dst_per_num` | I3C0 常见 `7'h1e`，I3C1 常见 `7'h0` | 目标外设 DMA request number |
| `i3c_dma_read_config` | `src_addr` | `I3C0_BASE/I3C1_BASE + RX_DATA_PORT` | I3C RX FIFO 源地址 |
| `i3c_dma_read_config` | `dst_addr` | `MCU_SUB_SRAM_BASE_ADDR + 0x4000` | SRAM 目标地址 |
| `i3c_dma_read_config` | `src_per_num` | 常见 `7'h1f` | 源外设 DMA request number |
| `arlengh/awlengh` | `0`/`1` | burst 长度配置 |

DMA sequence 内部关键字段：

| 字段 | write config | read config | 含义 |
| --- | --- | --- | --- |
| `tt_fc` | `3'h1` | `3'h2` | `1` 表示 memory to peripheral，`2` 表示 peripheral to memory |
| `sinc` | `0` | `1` | 源地址增量/固定策略 |
| `dinc` | `1` | `0` | 目标地址增量/固定策略 |
| `src_tr_width/dst_tr_width` | `3'h2` | `3'h2` | 32-bit 传输宽度 |

## 7. Case 配置信息矩阵

这一节把各类 case 的配置项集中列出来。阅读单个 case 时可以先看 `build_phase`，确认 VIP 拓扑、DUT 角色和 I3C 实例；再看 `main_phase`，确认寄存器地址、命令参数、数据方向和 scoreboard 接口。

### 7.1 接口控制变量

`m_i3c_intf` 里的两个控制量是 case 拓扑选择的核心：

| 控制项 | 常见值 | 说明 |
| --- | --- | --- |
| `i3c_num_ctrl = 0` | I3C0 普通 case | base `main_phase` 配置 I3C0 pad，寄存器一般访问 `I3C0_BASE` |
| `i3c_num_ctrl = 1` | I3C1 普通 case | base `main_phase` 配置 I3C1 pad，寄存器一般访问 `I3C1_BASE` |
| `i3c_num_ctrl = 2` | I3C0 特殊 TXFIFO case | 用在 `i3c0_master_transmit_withtxfifo_test`，寄存器仍访问 `I3C0_BASE`，但 IOMUX/scoreboard 控制走特殊分支 |
| `i3c_num_ctrl = 'h3` | I3C0 interrupt case | CPU 中断场景，SV 侧等待 C 程序 label |
| `i3c_num_ctrl = 'h4` | I3C1 interrupt case | I3C1 CPU 中断场景 |
| `i3c_num_ctrl = 5` | 部分特殊/扩展场景 | base 里预留了对应 IOMUX 分支，需要结合具体 case 确认 |

`i3c_scb_ctrl` 主要用于告诉 scoreboard 当前要按哪种方向解释 transaction：

| `i3c_scb_ctrl` | 代表场景 | 典型 case |
| --- | --- | --- |
| `3'h1` | DUT slave receive，VIP master write | `i3c0_slave_receive_trans_test`、`i2c0_slave_receive_trans_test` |
| `3'h2` | DUT slave transmit / secondary master | `i3c0_slave_transmit_trans_test`、`i3c0_slave_to_secmaster_test` |
| `3'h3` | DUT master read，RX FIFO 或 RX DMA | `i3c0_master_transmit_withrxfifo_test`、`i3c0_trans_rxfifo_to_mem_withdma_test` |
| `3'h4` | I2C legacy master write | `i2c0_master_transmit_withtxfifo_test` |
| `3'h5` | DUT master write，TX FIFO/CCC/速率/DMA TX | `i3c0_master_mode_sdr0_rate_test`、`i3c0_master_broadcast_ccc_trans_test` |
| `3'h6` | CPU interrupt case | `i3c0_intr_test`、`i3c1_intr_test` |

### 7.2 默认 VIP 地址配置

base test 默认先建立一套 VIP 地址，具体 case 再按场景打开或关闭 active：

| VIP 对象 | 类型 | 默认地址/能力 | 常见用途 |
| --- | --- | --- | --- |
| `master_cfg[0]` | Main Master | dynamic address `0x30` | DUT 做 slave 时，由 VIP main master 发起访问 |
| `master_cfg[1]` | Secondary Master | static address `0x31`，dynamic address `0x34` | secondary master 相关流程 |
| `slave_cfg[0]` | I2C Legacy Slave | 默认 legacy static address | I2C FM/FM+ case |
| `slave_cfg[1]` | I3C Slave | static address `0x63`，dynamic address `0x64` | DUT 做 master 时的目标 I3C slave |

最常见的 DUT master + VIP I3C slave 配置如下：

| 配置项 | 值 | 含义 |
| --- | --- | --- |
| `cfg.master_cfg[0].is_active` | `0` | 关闭 VIP main master，避免和 DUT master 抢总线 |
| `cfg.master_cfg[1].is_active` | `0` | 关闭 VIP secondary master |
| `cfg.slave_cfg[0].is_active` | `0` | 不启用 I2C legacy slave |
| `cfg.slave_cfg[1].is_active` | `1` | 启用 VIP I3C slave 作为 DUT master 的访问目标 |
| `cfg.slave_cfg[1].device_static_addr_en` | `1` | 允许目标 slave 使用 static address 参与地址流程 |
| `dev_addr` | `7'h63` | 目标 slave static address |
| `dynamic_addr` | `8'h64` 或 `8'he3` | 目标 slave dynamic address，写入 DAT `[23:16]` |

最常见的 DUT slave 配置如下：

| 配置项 | 值 | 含义 |
| --- | --- | --- |
| `m_i3c_intf.i3c_scb_ctrl` | `3'h1` 或 `3'h2` | receive 用 `1`，transmit 用 `2` |
| `m_i3c_intf.i3c_num_ctrl` | `0` 或 `1` | 选择 I3C0/I3C1 |
| `MCUSS_I3C*_STAT[18]` | `1` | 使能静态地址相关配置 |
| `MCUSS_I3C*_STAT[17:11]` | `7'h31` | DUT slave static address |
| `DEVICE_CTRL_EXTENDED` | `32'h1` | DUT controller 进入 slave mode |
| `DEVICE_ADDR[6:0]` | `7'h31` | DUT slave static address |
| `DEVICE_ADDR[15]` | `1` | static address valid/enable |
| `DEVICE_CTRL[27]` | `1` | slave 相关控制位，case 中作为进入可响应状态的必要配置 |
| `DEVICE_CTRL[31]` | `1` | enable controller |

### 7.3 Master 速率类 case 配置

I3C0/I3C1 的 SDR0~SDR4 case 基本对称，差异主要是 `i3c_num`、`i3c_num_ctrl`、`speed` 和 SCL timing。

| case 类型 | I3C 实例 | 目标地址 | `i3c_block_init` | timing/cmd 参数 | 数据配置 |
| --- | --- | --- | --- | --- | --- |
| SDR0 | I3C0/1 | static `7'h63`，dynamic `8'h64` | `(i3c_num, 0, dev_addr, 8'h64, 0, 1, 1)` | `i3c_set_scl_timing(i3c_num, 0)`，`i3c_set_transfer_cmd(... speed=0, isread=0, tr_id=2, isstop=1)` | `i3c_set_transfer_arg(...,16)`，TX FIFO 写 4 word |
| SDR1 | I3C0/1 | static `7'h63`，dynamic `8'h64` | 同 SDR0 | `speed=1`，`SCL_EXT_LCNT_TIMING` 配 SDR1 | 通常传 16 byte |
| SDR2 | I3C0/1 | static `7'h63`，dynamic `8'h64` | 同 SDR0 | `speed=2`，`i3c_set_scl_timing(...,2)` | 通常传 16 byte |
| SDR3 | I3C0/1 | static `7'h63`，dynamic `8'h64` | 同 SDR0 | `speed=3`，`i3c_set_scl_timing(...,3)` | 通常传 16 byte |
| SDR4 | I3C0/1 | static `7'h63`，dynamic `8'h64` | 同 SDR0 | `speed=4`，`i3c_set_scl_timing(...,4)` | 通常传 16 byte |
| HDR-DDR | I3C0/1 | static `7'h63`，dynamic 常用 `8'he3` | `(i3c_num, 0, dev_addr, 8'he3)` | `i3c_set_transfer_cmd(... speed=6, iscp=1, cmd=8'h20, isread=0)` | `i3c_set_transfer_arg(...,4)` |
| I2C FM | I3C0/1 | static `7'h63`，dynamic 常用 `8'he3` | `(i3c_num, 0, dev_addr, 8'he3)` | `i3c_set_transfer_cmd(... speed=7, isread=0)` | `i3c_set_transfer_arg(...,4)` |

以 `i3c0_master_mode_sdr0_rate_test` 为例，实际寄存器访问顺序是：

| 顺序 | 操作 | 地址/寄存器 | 参数或写入值 | 目的 |
| --- | --- | --- | --- | --- |
| 清状态 | `noc_reg_write` | `MCU_SUB_SCU_BASE_ADDR + MCUSS_I3C0_STAT` | `0` | 清 I3C0 SCU 状态 |
| 配 timing | `i3c_set_scl_timing(0,0)` | `I3C0_BASE + SCL_I3C_OD_TIMING/PP_TIMING/EXT_LCNT` | speed `0` | 配置 SDR0 SCL timing |
| 初始化 | `i3c_block_init(0,0,7'h63,8'h64,0,1,1)` | `I3C0_BASE + QUEUE_THLD_CTRL` | `resp_buf_thld=0` -> `[15:8]` | 设置 response threshold |
| 初始化 | 同上 | `I3C0_BASE + DATA_BUFFER_THLD_CTRL` | `tx_empty=1` -> `[2:0]`，`tx_start=1` -> `[18:16]`，`rx=0` -> `[10:8]` | 设置 FIFO threshold |
| 初始化 | 同上 | `I3C0_BASE + DEVICE_CTRL_EXTENDED` | `0` | DUT 为 master |
| 初始化 | 同上 | `I3C0_BASE + INTR_STATUS_EN/SIGNAL_EN` | `32'hffff` | 打开状态和信号中断 |
| 初始化 | 同上 | `I3C0_BASE + DEVICE_ADDR` | `[22:16]=7'h55`，`[31]=1` | 设置 controller 自身 dynamic address |
| 初始化 | 同上 | `I3C0_BASE + DEV_ADDR_TABLE_LOC1` | `[6:0]=7'h63`，`[23:16]=8'h64` | 设置目标 slave DAT |
| 使能 | `i3c_block_enable(0)` | `I3C0_BASE + DEVICE_CTRL` | 读改写 `[31]=1` | enable controller |
| 地址流程 | `i3c_set_daa_cmd(0,1)` | `I3C0_BASE + COMMAND_QUEUE_PORT` | `[14:7]=8'h87`，`[2:0]=3'h3` | 发 directed DAA/SETDASA 类命令 |
| 参数 | `i3c_set_transfer_arg(0,16)` | `I3C0_BASE + COMMAND_QUEUE_PORT` | `[31:16]=16`，`[2:0]=3'h1` | 设置传输长度 |
| 命令 | `i3c_set_transfer_cmd(0,0,0,0,0,0,2,1)` | `I3C0_BASE + COMMAND_QUEUE_PORT` | speed `0`，write，tr_id `2`，stop `1` | 发起 SDR0 write |
| 数据 | `i3c_wirte_data_to_txfifo(0,4,4,tx_data_q)` | `I3C0_BASE + TX_DATA_PORT` | 4 个 word：`32'h5a5a5a5a + i` | 写 TX FIFO 并生成 byte queue |
| 检查 | `i3c_master_txdata_to_vip_slave_pre_tr(1,dev_addr,tx_data_q)` | scoreboard | slave index `1`，addr `7'h63` | 构造 VIP slave 预期 transaction |

### 7.4 CCC 与地址分配类 case 配置

CCC case 和普通 master write 的底层流程相同，主要差异在 `i3c_set_transfer_cmd` 的 `iscp/cmd` 字段，以及是否显式调用 `i3c_set_daa_cmd`。

| case | 关键配置 | CCC 参数 | 地址配置 | 数据/检查 |
| --- | --- | --- | --- | --- |
| `master_broadcast_ccc_trans` | DUT master，VIP I3C slave active，`i3c_scb_ctrl=3'h5` | 先 `i3c_set_transfer_cmd(... iscp=1, cmd=8'h02, tr_id=1)`，再普通 write cmd | `dev_addr=7'h63`，DAT dynamic `8'he3` | `transfer_arg=4`，TX FIFO 1 word，scoreboard 用 slave `1` |
| `master_directed_ccc_trans` | 同 broadcast | `i3c_set_transfer_cmd(... iscp=1, cmd=8'h82, tr_id=2)` | `dev_addr=7'h63`，DAT dynamic `8'he3` | `transfer_arg=4`，TX FIFO 1 word |
| `master_setaasa` | DUT master，VIP I3C slave active | `i3c_set_transfer_cmd(... iscp=1, cmd=8'h29)` | SETAASA 后读取/更新 DAT | 用于静态地址转动态地址类流程 |
| `master_setdasa` | DUT master，VIP I3C slave active | `i3c_set_daa_cmd(...,1)` 或 `cmd=8'h87` | static `7'h63`，dynamic `8'h64/8'he3` | 验证 directed address assignment |

`iscp=1` 时，`COMMAND_QUEUE_PORT[15]` 置位，`cmd` 写入 `[14:7]`；`iscp=0` 时这 8 bit 不作为 CCC 解释，case 就退回普通 private transfer。

### 7.5 FIFO 与短数据 case 配置

| case | build 配置 | transfer 参数 | FIFO/数据路径 | 关键检查 |
| --- | --- | --- | --- | --- |
| `master_transmit_withtxfifo` | `i3c_scb_ctrl=3'h5`，I3C0 特例 `i3c_num_ctrl=2` | `i3c_block_init(0,0,7'h63,8'h64)`，`transfer_arg=4`，`isread=0` | `i3c_wirte_data_to_txfifo(0,1,1,tx_data_q)` 写 1 word 到 `TX_DATA_PORT` | `i3c_master_txdata_to_vip_slave_pre_tr(1,7'h63,tx_data_q)` |
| `master_transmit_withrxfifo` | `i3c_scb_ctrl=3'h3`，VIP slave active | 先发 `cmd=8'h29`，更新 DAT `[23:16]=8'he3`，`transfer_arg=4`，`isread=1` | VIP slave sequence 提供数据，DUT 从 `RX_DATA_PORT` 读 1 word | `i3c_master_rxdata_to_vip_slave_post_tr(7'h63,rx_data_q)` |
| `master_transmit_withshortdata` | `i3c_scb_ctrl=3'h5`，VIP slave active | `i3c_set_short_data_arg` 后 `i3c_set_transfer_cmd(... isshortarg=1,isread=0)` | short data 直接写 command queue，不走普通 TX FIFO | short data 为 `0x55,0xaa,0xff` 三个 byte |

短数据 task 的命令队列字段比较特殊：

| 字段 | 值 | 含义 |
| --- | --- | --- |
| `COMMAND_QUEUE_PORT[2:0]` | `3'h2` | short data argument entry |
| `[5:3]` | `3'h7` | short data 长度/控制字段 |
| `[15:8]` | `8'h55` | 第 1 个 byte |
| `[23:16]` | `8'haa` | 第 2 个 byte |
| `[31:24]` | `8'hff` | 第 3 个 byte |

### 7.6 Slave receive/transmit case 配置

以 `i3c0_slave_receive_trans_test` 为例，DUT 被配置成 I3C0 slave，VIP `master_sequencer[0]` 在另一个 fork 分支发起 write：

| 顺序 | 操作 | 地址/寄存器 | 参数或写入值 | 目的 |
| --- | --- | --- | --- | --- |
| SCU 地址 | `noc_reg_write` | `MCU_SUB_SCU_BASE_ADDR + MCUSS_I3C0_STAT` | `[18]=1`，`[17:11]=7'h31` | 配置 DUT slave static address |
| RX threshold | 读改写 | `I3C0_BASE + DATA_BUFFER_THLD_CTRL` | `[10:8]=0` | RX FIFO threshold |
| slave mode | 写 | `I3C0_BASE + DEVICE_CTRL_EXTENDED` | `32'h1` | 进入 slave mode |
| 中断状态 | 写 | `I3C0_BASE + INTR_STATUS_EN` | `32'hffff` | 使能状态位 |
| dev ctrl | 写 | `I3C0_BASE + DEVICE_CTRL` | `[27]=1` | slave 侧控制配置 |
| 地址 | 写 | `I3C0_BASE + DEVICE_ADDR` | `[6:0]=7'h31`，`[15]=1` | DUT slave static address valid |
| enable | 读改写 | `I3C0_BASE + DEVICE_CTRL` | `[31]=1` | enable controller |
| 接收 | `i3c_read_data_from_rxfifo(0,2,1,rx_data_q)` | `I3C0_BASE + RX_DATA_PORT` | 读 2 word，threshold 1 | 接收 VIP master 写入的数据 |
| 检查 | `i3c_slave_rxdata_to_vip_master_post_tr(0,rx_data_q)` | scoreboard | master index `0` | 构造 VIP master observed transaction |

`i3c0_slave_transmit_trans_test` 和 receive 的前半段配置基本一致，差异如下：

| 配置/动作 | receive | transmit |
| --- | --- | --- |
| `i3c_scb_ctrl` | `3'h1` | `3'h2` |
| FIFO threshold | 设置 RX threshold `[10:8]` | 设置 TX empty `[2:0]` 和 TX start `[18:16]` |
| VIP sequence | `i3c_vip_mst_write_sequence` | `i3c_vip_mst_read_sequence` |
| DUT 数据方向 | 从 `RX_DATA_PORT` 读 | 向 `TX_DATA_PORT` 写 |
| 前置命令 | 无显式 transfer cmd | 等 `INTR_STATUS[3]` 后发 `i3c_set_transfer_cmd(0,0,1,8'h87,0,0,1,1)` |
| scoreboard | `i3c_slave_rxdata_to_vip_master_post_tr` | `i3c_slave_txdata_to_vip_master_pre_tr` |

### 7.7 DMA case 配置

| case | 方向 | build 配置 | DMA 配置 | I3C transfer 配置 |
| --- | --- | --- | --- | --- |
| `trans_txfifo_to_mem_withdma` | SRAM -> I3C TX FIFO -> bus | `i3c_scb_ctrl=3'h5`，VIP slave active | `i3c_dma_write_config(SRAM+0x4000, I3C0_BASE+TX_DATA_PORT, 7'h1e, 1, 1)` | `block_init(0,0,7'h63,8'h64)`，DMA enable，DAA，`transfer_arg=8`，write cmd |
| `trans_rxfifo_to_mem_withdma` | bus -> I3C RX FIFO -> SRAM | `i3c_scb_ctrl=3'h3`，VIP slave active | `i3c_dma_read_config(I3C0_BASE+RX_DATA_PORT, SRAM+0x4000, 7'h1f, 1, 1)` | `block_init(0,1,7'h63)`，DMA enable，SETAASA `8'h29`，DAT dynamic 改 `8'he3`，`transfer_arg=4`，read cmd |

TX DMA case 的 memory 初始化也要看：

| 数据源 | 地址 | 初始值 | byte queue 顺序 |
| --- | --- | --- | --- |
| `wdata_arr[0]` | `MCU_SUB_SRAM_BASE_ADDR + 0x4000` | `32'haa5599ff` | `ff,99,55,aa` |
| `wdata_arr[1]` | `MCU_SUB_SRAM_BASE_ADDR + 0x4004` | `32'h5a5a5a5a` | `5a,5a,5a,5a` |

所以 `transfer_arg=8` 对应 8 byte，scoreboard 期望数据来自同一份 `tx_data_q`，不是再次从总线采样生成。

### 7.8 Secondary Master case 配置

`i3c0_slave_to_secmaster_test` 的关键点是 DUT 先按 slave 配好，然后通过 master request/IBI 申请总线控制权：

| 阶段 | 寄存器/配置 | 参数 | 含义 |
| --- | --- | --- | --- |
| build | `cfg.master_cfg[0].is_active=1` | VIP main master active | 让 VIP main master 主导前置流程 |
| build | `cfg.master_cfg[1].device_static_address='h31`，`dynamic='h34` | secondary master 地址 | 配置 secondary master 地址模型 |
| slave 初始化 | `MCUSS_I3C0_STAT[18]=1`，`[17:11]=7'h31` | static address | DUT 初始作为 slave |
| slave 初始化 | `DEVICE_CTRL_EXTENDED=1`，`DEVICE_ADDR=0x8031` | static valid | 进入 slave 可响应状态 |
| 等地址完成 | `INTR_STATUS[8]` | 等于 1 | dynamic address done |
| MR 能力 | `SLV_EVENT_STATUS[1]` | 等于 1 | 当前 master 已允许 master request |
| 发 MR | `SLV_INTR_REQ[3]=1` | 写 1 | DUT slave 发起 master request |
| 等 IBI | `INTR_STATUS[12]` | 等于 1 | IBI update status |
| ACK 检查 | `SLV_INTR_REQ[9:8]` | `2'b01` | MR ACK，否则报错 |
| bus owner | `INTR_STATUS[13]` | 等于 1 | bus owner update |
| resume | `DEVICE_CTRL[30]=1` | 写 1 | controller resume，准备后续 master 行为 |
| DAT | `DEV_ADDR_TABLE_LOC1[23:16]=8'hb0` | dynamic addr | 设置后续访问目标 |
| 传输 | `transfer_arg=4`，`speed=0`，`isread=0` | SDR0 write | DUT 以新角色发起传输 |

### 7.9 中断 case 配置

中断 case 由 SV 和 C 配合。SV 侧只负责等软件准备完成后启动 VIP master；真正的 I3C slave 和中断寄存器配置在 `main.c`。

| 项目 | I3C0 | I3C1 | 说明 |
| --- | --- | --- | --- |
| SV `i3c_scb_ctrl` | `3'h6` | `3'h6` | interrupt scoreboard 场景 |
| SV `i3c_num_ctrl` | `'h3` | `'h4` | 区分 I3C0/I3C1 中断场景 |
| CPU 中断号 | `Ext_MCU_I3C0_INTR_IRQn` | `Ext_MCU_I3C1_INTR_IRQn` | PLIC 注册的 IRQ |
| label | `0x12345678` | 通常同模式 | C 配置完成后通知 SV |
| RX 检查 | `0x998855aa`、`0xaa558899` | 同类期望 | handler 从 `RX_DATA_PORT` 读两次 |

`i3c0_intr_test/main.c` 的关键寄存器配置：

| 顺序 | C 操作 | 地址/寄存器 | 写入值 | 说明 |
| --- | --- | --- | --- | --- |
| PLIC | `PLIC_Register_IRQ` | `Ext_MCU_I3C0_INTR_IRQn` | priority `1`，handler `mcu_i3c0_intr_handler` | 注册 I3C0 中断 |
| SCU | `write32` | `MCU_SUB_SCU_BASE_ADDR + MCUSS_I3C0_STAT` | `0x58800` | 配置 I3C0 slave static address/status |
| threshold | read/modify/write | `MCU_SUB_I3C0_BASE_ADDR + DATA_BUFFER_THLD_CTRL` | `rdata & 0xfffff8ff` | 清 RX threshold 字段 `[10:8]` |
| slave mode | `write32` | `DEVICE_CTRL_EXTENDED` | `0x1` | DUT 为 slave |
| 状态中断 | `write32` | `INTR_STATUS_EN` | `0xffff` | 打开状态位 |
| 信号中断 | `write32` | `INTR_SIGNAL_EN` | `0x2` | 只打开 RX 相关中断信号 |
| dev ctrl | `write32` | `DEVICE_CTRL` | `0x08000000` | 设置 `[27]` |
| 地址 | `write32` | `DEVICE_ADDR` | `0x8031` | static addr `0x31` + static valid |
| enable | read/modify/write | `DEVICE_CTRL` | `rdata | 0x80000000` | enable controller |
| handler 读数 | `read32` | `RX_DATA_PORT` | 两次读取 | 期望 `0x998855aa`、`0xaa558899` |

### 7.10 Debug、Reg、Reset、Clock case 配置

| case 类型 | 关键配置 | 主要检查点 |
| --- | --- | --- |
| `i3c0_debug_port_test` | `i3c_num_ctrl=0`，读 `MCUSS_I3C0_SVL_DBG_PORT_H/L` | force wrapper 内部 debug 信号为 0/1，检查 SCU debug port 映射 |
| `i3c1_debug_port_test` | `i3c_num_ctrl=1`，读 `MCUSS_I3C1_SVL_DBG_PORT_H/L` | 同 I3C0，对称检查 I3C1 |
| `i3c0_reg_test`/`i3c1_reg_test` | 遍历 `i3c_reg_struct.sv` 寄存器表 | reset value、RW mask、写读一致性 |
| `i3c0_rstn_test`/`i3c1_rstn_test` | force/reset wrapper reset 信号 | reset 后寄存器和状态恢复 |
| `i3c0_clk_test`/`i3c1_clk_test` | 配置 clock/reset gating 相关路径 | clock 使能、关闭、恢复后的可访问性 |

### 7.11 典型 case 索引速查

下面这张表适合在写新 case 或 debug fail 时快速定位配置差异。I3C1 对应 case 通常把 `i3c_num` 从 `0` 换成 `1`，寄存器 base 从 `I3C0_BASE` 换成 `I3C1_BASE`，`i3c_num_ctrl` 从 `0` 换成 `1`。

| case 文件 | DUT 角色/方向 | `i3c_scb_ctrl` | `i3c_num_ctrl` | 关键地址/参数 |
| --- | --- | --- | --- | --- |
| `i3c0_master_mode_sdr0_rate_test.sv` | master write，SDR0 | `3'h5` | `0` | target static `7'h63`，dynamic `8'h64`，`speed=0`，`transfer_arg=16` |
| `i3c0_master_mode_sdr1_rate_test.sv` | master write，SDR1 | `3'h5` | `0` | target static `7'h63`，dynamic `8'h64`，`speed=1`，`transfer_arg=16` |
| `i3c0_master_mode_sdr2_rate_test.sv` | master write，SDR2 | `3'h5` | `0` | target static `7'h63`，dynamic `8'h64`，`speed=2`，`transfer_arg=16` |
| `i3c0_master_mode_sdr3_rate_test.sv` | master write，SDR3 | `3'h5` | `0` | target static `7'h63`，dynamic `8'h64`，`speed=3`，`transfer_arg=16` |
| `i3c0_master_mode_sdr4_rate_test.sv` | master write，SDR4 | `3'h5` | `0` | target static `7'h63`，dynamic `8'h64`，`speed=4`，`transfer_arg=16` |
| `i3c0_master_mode_hdr_ddr_rate_test.sv` | master HDR-DDR write | `3'h5` | `0` | dynamic `8'he3`，`speed=6`，`iscp=1`，`cmd=8'h20`，`transfer_arg=4` |
| `i3c0_master_mode_i2c_fm_rate_test.sv` | master I2C FM write | `3'h5` | `0` | dynamic `8'he3`，`speed=7`，`transfer_arg=4` |
| `i3c0_master_broadcast_ccc_trans_test.sv` | broadcast CCC + write | `3'h5` | `0` | `cmd=8'h02`，dynamic `8'he3`，后续普通 write |
| `i3c0_master_directed_ccc_trans_test.sv` | directed CCC + write | `3'h5` | `0` | `cmd=8'h82`，dynamic `8'he3`，后续普通 write |
| `i3c0_master_setaasa_test.sv` | SETAASA 地址流程 | `3'h5` | `0` | `cmd=8'h29`，读取 response 后更新 DAT |
| `i3c0_master_setdasa_test.sv` | SETDASA/DAA 地址流程 | `3'h5` | `0` | `i3c_set_daa_cmd(0,1)` -> `cmd=8'h87`，target dynamic `8'h64` |
| `i3c0_master_transmit_withtxfifo_test.sv` | master write，普通 TX FIFO | `3'h5` | `2` | `transfer_arg=4`，TX FIFO 写 1 word，case 末尾 force reset |
| `i3c0_master_transmit_withrxfifo_test.sv` | master read，普通 RX FIFO | `3'h3` | `0` | `cmd=8'h29`，DAT dynamic 改 `8'he3`，`isread=1` |
| `i3c0_master_transmit_withshortdata_test.sv` | master write，short data | `3'h5` | `0` | short data `55 aa ff`，`isshortarg=1` |
| `i3c0_slave_receive_trans_test.sv` | slave receive | `3'h1` | `0` | DUT static `7'h31`，`DEVICE_CTRL_EXTENDED=1`，VIP master write |
| `i3c0_slave_transmit_trans_test.sv` | slave transmit | `3'h2` | `0` | DUT static `7'h31`，`cmd=8'h87`，VIP master read |
| `i3c0_slave_to_secmaster_test.sv` | slave -> secondary master | `3'h2` | `0` | DUT static `7'h31`，等 `INTR_STATUS[8/12/13]`，DAT dynamic `8'hb0` |
| `i3c0_trans_txfifo_to_mem_withdma_test.sv` | DMA TX，SRAM -> TX FIFO | `3'h5` | `0` | `SRAM+0x4000` -> `I3C0_BASE+TX_DATA_PORT`，`dst_per=7'h1e`，`transfer_arg=8` |
| `i3c0_trans_rxfifo_to_mem_withdma_test.sv` | DMA RX，RX FIFO -> SRAM | `3'h3` | `0` | `I3C0_BASE+RX_DATA_PORT` -> `SRAM+0x4000`，`src_per=7'h1f`，`isread=1` |
| `i3c0_intr_test.sv` + `main.c` | CPU interrupt slave receive | `3'h6` | `'h3` | C 侧 static `0x31`，`INTR_SIGNAL_EN=0x2`，期望 `0x998855aa/0xaa558899` |
| `i3c0_reg_test.sv` | register test | 不依赖传输方向 | 通常 I3C0 | 遍历 reset value 和 RW mask |
| `i3c0_debug_port_test.sv` | debug port map | 不依赖传输方向 | `0` | force debug signal，读 `MCUSS_I3C0_SVL_DBG_PORT_H/L` |

## 8. 典型 Case 编写模板

一个 I3C SV case 基本都遵循这个结构：

```systemverilog
class my_i3c_case extends i3c_base_test;
  `uvm_component_utils(my_i3c_case)

  extern function new(string name = "my_i3c_case", uvm_component parent = null);
  extern virtual function void build_phase(uvm_phase phase);
  extern virtual task main_phase(uvm_phase phase);
endclass

function void my_i3c_case::build_phase(uvm_phase phase);
  super.build_phase(phase);
  // 配置 VIP active/passive 角色
  // 配置 i3c_scb_ctrl / i3c_num_ctrl
endfunction

task my_i3c_case::main_phase(uvm_phase phase);
  phase.raise_objection(this);
  super.main_phase(phase);
  // 配置 DUT 寄存器
  // 启动 transfer / VIP sequence / DMA / 中断
  // 检查结果
  phase.drop_objection(this);
endtask
```

这套模板里最重要的是：`build_phase` 决定 TB 拓扑，`main_phase` 决定真实验证流程。

## 9. Master Mode 传输类 Case

代表文件：`i3c0_master_mode_sdr0_rate_test.sv`、`i3c0_master_transmit_withtxfifo_test.sv`

这类 case 验证 DUT 作为 I3C master，通过 command queue 和 TX/RX FIFO 发起传输。

典型流程：

```text
build_phase:
  关闭 VIP master active
  使能 VIP I3C slave
  开启 slave static address
  设置 i3c_scb_ctrl / i3c_num_ctrl

main_phase:
  清 SCU I3C status
  配置 SCL timing
  i3c_block_init
  i3c_block_enable
  i3c_set_daa_cmd
  等待 command queue ready
  i3c_set_transfer_arg
  再次等待 command queue ready
  i3c_set_transfer_cmd
  写 TX FIFO 或读 RX FIFO
  构造 VIP slave transaction，送 scoreboard 对比
```

SDR0~SDR4 的差异主要体现在：

| 速率 case | 主要变化点 |
| --- | --- |
| SDR0 | `i3c_set_scl_timing(0, 0)`，transfer command speed 为 0 |
| SDR1~SDR4 | 修改 `speed` 和 `SCL_EXT_LCNT_TIMING` 对应字段 |
| HDR-DDR | 使用 HDR 相关 speed/transfer 配置 |
| I2C FM/FM+ | `i3c_block_init` 中 `isi2c_mode` 置位，DAT 标记 legacy I2C |

## 10. CCC 命令类 Case

代表文件：`i3c0_master_broadcast_ccc_trans_test.sv`、`i3c0_master_directed_ccc_trans_test.sv`、`i3c0_master_setaasa_test.sv`、`i3c0_master_setdasa_test.sv`

CCC case 的核心是通过 `i3c_set_transfer_cmd` 设置 `iscp = 1` 并填入 `cmd`。

Broadcast CCC 的典型流程：

```text
配置 DUT 为 master，VIP slave 为目标
设置 SCL timing
初始化 I3C block
enable controller
发送 CCC command，例如 0x02
等待 command queue ready
设置 transfer arg
发送普通 transfer command
写 TX FIFO
构造 VIP slave transaction 对比
```

从代码看，CCC 命令和普通 private transfer 的差异主要是 command queue 中 `iscp/cmd` 字段不同。其他流程仍然复用同一套 `block_init -> enable -> arg -> cmd -> FIFO -> scoreboard` 模板。

## 11. Slave Mode 类 Case

代表文件：`i3c0_slave_receive_trans_test.sv`、`i3c0_slave_transmit_trans_test.sv`、`i2c0_slave_receive_trans_test.sv`

这类 case 验证 DUT 作为 slave，由 VIP master 发起总线传输。典型写法是 `fork...join`：

| 分支 | 行为 |
| --- | --- |
| DUT 分支 | 配置 DUT slave 寄存器，等待 RX/TX FIFO 事件，读/写数据 |
| VIP 分支 | 延时后启动 `i3c_vip_mst_write_sequence` 或相关 master sequence |

DUT slave receive 的典型流程：

```text
配置 SCU static address
设置 RX buffer threshold
DEVICE_CTRL_EXTENDED = 1，进入 slave mode
使能 INTR_STATUS_EN
配置 DEVICE_CTRL/DEVICE_ADDR
使能 controller
读取 RX FIFO
把 rx_data_q 写入 VIP master observed port
```

这里要注意：Slave 类 case 不调用 `i3c_block_init`，因为 `i3c_block_init` 默认把 DUT 配成 master。Slave 模式下 case 直接写 `DEVICE_CTRL_EXTENDED`、`DEVICE_ADDR`、`DEVICE_CTRL`。

## 12. Secondary Master Case

代表文件：`i3c0_slave_to_secmaster_test.sv`

该 case 的目标是验证 DUT 从 slave 角色参与 Secondary Master 流程，并在获得总线控制权后继续发起传输。

典型流程：

```text
build_phase:
  VIP main master active
  VIP secondary master 配置静态/动态地址
  设置 i3c_scb_ctrl 和 i3c_num_ctrl

main_phase:
  DUT 配置为 slave
  配置 static address 和中断
  等待 dynamic address done
  检查 SLV_EVENT_STATUS 中 MR 能力/使能状态
  设置 SLV_INTR_REQ 发起 master request
  等待 IBI update status
  检查 ACK/NACK
  等待 bus owner update
  设置 DEVICE_CTRL resume
  配置 DAT
  按 master transfer 流程继续发送数据
  构造 Secondary Master 场景下的 scoreboard transaction
```

这类 case 是最能体现 I3C 特性的场景之一：DUT 先是 slave，随后通过 master request/IBI 相关流程切换到能够发起传输的状态。

## 13. DMA Case

代表文件：`i3c0_trans_txfifo_to_mem_withdma_test.sv`、`i3c0_trans_rxfifo_to_mem_withdma_test.sv`

TX FIFO with DMA 的典型流程：

```text
准备 memory 数据，并同步生成 tx_data_q
i3c_fill_memory 写 SRAM
清 SCU status
设置 SCL timing
i3c_block_init
i3c_dma_enable
i3c_block_enable
i3c_set_daa_cmd
配置 DMA memory -> TX_DATA_PORT
等待 command queue ready
i3c_set_transfer_arg
i3c_set_transfer_cmd
用 tx_data_q 构造 VIP slave 预期 transaction
```

DMA case 和普通 FIFO case 的差异是：普通 case 由 TB task 直接写 `TX_DATA_PORT`，DMA case 则由 DMA sequence 把 SRAM 数据搬到 `TX_DATA_PORT` 或把 `RX_DATA_PORT` 搬到 memory。

## 14. Reg Test

代表文件：`i3c0_reg_test.sv`

Reg test 的逻辑很清晰：

| Task | 作用 |
| --- | --- |
| `default_val_chk` | 遍历寄存器表，检查 reset value |
| `reset_dev_regs` | 对 no-init 类寄存器写 0 |
| `write_reg_chk` | 对每个寄存器写入测试值，根据 RW mask 计算期望值并回读比较 |

期望值计算方式：

```text
expected = (write_value & RW_MASK) | (old_value & ~RW_MASK)
```

这种写法可以避免只读位、保留位导致误判，是寄存器测试里很典型的 TB 写法。

## 15. Debug Port Case

代表文件：`i3c0_debug_port_test.sv`

Debug port case 的主要逻辑不是跑协议传输，而是用 `uvm_hdl_force` 直接 force I3C wrapper 内部 debug 信号，然后读取 SCU 中映射出来的 debug port 寄存器。

典型流程：

```text
force 所有 debug 信号为 0
读取 debug port high/low
检查是否为 0
force 所有 debug 信号为 1
读取 debug port high/low
检查 high/low 是否为全 1 期望值
再次 force 0 并检查
写 PID/DCR 等 SCU 寄存器做补充检查
```

这个 case 的价值在于验证 debug 信号汇聚和寄存器映射，而不是验证 I3C 协议本身。

## 16. 中断 Case

中断 case 由 SV 和 C 两部分配合：

| 文件 | 作用 |
| --- | --- |
| `i3c0_intr_test.sv` | SV 侧等待 CPU 程序发 label，然后启动 VIP master sequence |
| `i3c0_intr_test/main.c` | CPU 侧配置 I3C slave、中断、PLIC handler，并读取 RX FIFO 数据 |

整体流程：

```text
C 程序启动
配置 PLIC 和 I3C slave
send_label(0x12345678) 通知 SV 侧准备好了
SV wait_label 后启动 VIP master 写传输
I3C 中断触发 CPU handler
handler 读取 RX_DATA_PORT
C 程序检查两笔 RX 数据是否等于期望值
simend
SV check_simend
```

这类 case 的关注点是硬件中断链路：I3C 中断源、PLIC 注册、CPU handler 进入、RX FIFO 读取和软件侧结果判断。

## 17. 新增 Case 的推荐写法

如果要新增一个 I3C case，建议按下面顺序写：

1. 确认 DUT 角色：master、slave、secondary master、DMA、CPU 中断。
2. 选择参考 case：Master 传输参考 SDR0/TXFIFO，Slave 参考 receive/transmit，DMA 参考 txfifo/rxfifo with dma。
3. 新建 class 并继承 `i3c_base_test`。
4. 在 `build_phase` 中配置 VIP active/passive：
   - DUT master：VIP slave active。
   - DUT slave：VIP master active，并用 fork 启动 VIP sequence。
   - Secondary Master：VIP main master active，并配置 secondary master。
5. 设置 `m_i3c_intf.i3c_scb_ctrl` 和 `m_i3c_intf.i3c_num_ctrl`，确保 base main 能配置正确 IOMUX。
6. 在 `main_phase` 中按流程配置寄存器。
7. 每次写 command queue 前，最好等待 `INTR_STATUS[3]` 确认可写。
8. 数据通路统一用 byte queue 保存期望数据。
9. 调用对应 `*_to_vip_*_tr` task，把期望 transaction 送入 scoreboard。
10. 结束前留出足够仿真时间，再 drop objection。

## 18. 典型 TB 编写套路总结

I3C case 的 TB 编写可以归纳为一句话：

> case 负责搭场景，base task 负责做动作，VIP/scoreboard 负责判结果。

具体拆开就是：

| 层次 | 编写重点 |
| --- | --- |
| package 层 | include 所有 case 和公共定义 |
| base test 层 | 封装环境配置、寄存器访问、协议动作、数据对比 |
| case build_phase | 选择 DUT/VIP 角色和 pad/topology 控制 |
| case main_phase | 执行寄存器配置、传输启动、FIFO/DMA/中断流程 |
| scoreboard 层 | 将 DUT 侧数据转换成 VIP transaction，与 VIP 行为比对 |
| C 程序层 | CPU 参与场景下配置中断和外设寄存器，完成软件侧检查 |

这套代码的可复用性主要来自 `i3c_base_test`。多数 case 的差异不是 TB 框架差异，而是寄存器配置参数、传输方向、速度、CCC command、FIFO/DMA 数据路径以及 VIP sequence 的选择不同。
