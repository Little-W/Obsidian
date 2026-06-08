# I3C Case 解析

> 代码来源：`C:\Users\yusen\Documents\Obsidian Vault\test_case\i3c_test`

## 1. 目录结构理解

I3C case 目录是一套基于 UVM/SystemVerilog 的模块级或子系统级验证 case 集合。整体组织方式是：公共逻辑集中在 `i3c_base_test.sv`，具体 case 只负责选择场景、配置角色、调用公共 task 完成传输和检查。

| 文件/目录 | 作用 |
| --- | --- |
| `i3c_test_pkg.svh` | I3C test package 入口，统一 include base test、define、reg struct 和各类 case |
| `i3c_define.svh` | I3C0/I3C1 base address、寄存器 offset、SCU debug/status 寄存器宏定义 |
| `i3c_reg_struct.sv` | 寄存器 reset value、RW mask、寄存器列表，用于 reg test |
| `i3c_base_test.sv` | 所有 I3C case 的公共基类，封装 VIP 配置、IOMUX、寄存器访问、I3C 初始化、FIFO、DMA 和 scoreboard 对接 |
| `i3c0_*.sv` | I3C0 相关 case |
| `i3c1_*.sv` | I3C1 相关 case，整体逻辑与 I3C0 对称 |
| `i3c0_intr_test/`、`i3c1_intr_test/` | 中断类 case 的 C 程序和 Makefile，用于 CPU 侧中断处理流程 |

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

| 职责 | 说明 |
| --- | --- |
| 环境对接 | 从 `chip_noc_base_test` 继承，拿到 SoC env、AXI master、I3C env 和 virtual sequencer |
| VIP 配置 | 创建 `cust_svt_mipi_i3c_system_configuration`，配置 main master、secondary master、I2C legacy slave、I3C slave |
| Factory override | 将默认 VIP transaction 替换为自定义 transaction |
| BCR/DCR 配置 | 配置 master/slave 的 BCR、DCR、dynamic address、static address、HDR 能力 |
| Timing 配置 | 配置 open-drain、push-pull、start/stop、SCL high/low 等时序参数 |
| config_db 分发 | 把 I3C cfg、env handle、virtual interface 分发给 sequencer 和 env |
| IOMUX 配置 | 在 base `main_phase` 中根据 `m_i3c_intf.i3c_num_ctrl` 配置 I3C0/I3C1 pad |
| 寄存器访问 | 封装 `noc_reg_write`，通过 AXI master sequence 访问寄存器 |
| 协议配置 | 封装 block init、enable、DAA、transfer arg、transfer command、SCL timing |
| 数据通路 | 封装 TX FIFO 写入、RX FIFO 读取、DMA 配置、memory 填充 |
| 数据检查 | 把 DUT 侧观测数据转换为 VIP transaction，写入 scoreboard observed port |

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

### 6.3 使能 I3C

`i3c_block_enable(i3c_num)` 读取 `DEVICE_CTRL`，将 bit31 置 1 后写回，用于使能 I3C controller。

### 6.4 设置 DAA/SETDASA

`i3c_set_daa_cmd(i3c_num, isdirect)` 向 `COMMAND_QUEUE_PORT` 写入 CCC command。`isdirect` 为 1 时使用 `0x87`，否则使用 `0x07`。从 case 使用方式看，它主要用于动态地址相关流程。

### 6.5 设置传输参数

`i3c_set_transfer_arg(i3c_num, data_len)` 向 command queue 写入 argument 类型命令，`data_len` 放在高 16 bit，用于指定后续 transfer 的数据长度。

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

| Task | 使用场景 |
| --- | --- |
| `i3c_master_txdata_to_vip_slave_pre_tr` | DUT master 写 slave，预期 slave 侧收到这些数据 |
| `i3c_master_rxdata_to_vip_slave_post_tr` | DUT master 读 slave 后，对 slave 侧 observed 数据 |
| `i3c_slave_rxdata_to_vip_master_post_tr` | DUT slave 收到 VIP master 写入数据后，对 master observed 数据 |
| `i3c_slave_txdata_to_vip_master_pre_tr` | DUT slave 发送数据前，构造 master 侧预期 transaction |
| `i3c_secmaster_txdata_to_vip_master_pre_tr` | Secondary Master 场景下构造一组 CCC/读写 transaction |

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

## 7. 典型 Case 编写模板

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

## 8. Master Mode 传输类 Case

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

## 9. CCC 命令类 Case

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

## 10. Slave Mode 类 Case

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

## 11. Secondary Master Case

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

## 12. DMA Case

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

## 13. Reg Test

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

## 14. Debug Port Case

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

## 15. 中断 Case

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

## 16. 新增 Case 的推荐写法

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

## 17. 典型 TB 编写套路总结

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
