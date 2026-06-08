# I3C 验证工作总结

## 工作概况

本阶段围绕 I3C0/I3C1 模块完成 Feature 与 Case 覆盖整理，验证内容覆盖寄存器读写、时钟复位、Master mode 通信、Slave mode 通信、CCC 命令传输、Private 读写传输、Secondary Master、DMA 搬运、中断处理以及 debug port 状态检查等方向。截图中可见相关覆盖项均已规划，对应 case 完成状态为 `done`，责任人为 Hury。

整体来看，I3C 验证已覆盖两个 I3C 实例的基础配置、协议速率、主从传输、I2C 兼容模式、DMA 数据搬运和调试可观测性，能够支撑 I3C 模块基础功能完成情况的阶段性评估。

## 验证内容概览

| 验证方向 | 已完成工作 | 验证结论 |
| --- | --- | --- |
| 寄存器测试 | 完成寄存器默认值读取、随机写入和回读检查 | 寄存器默认值和读写行为符合预期 |
| 时钟与复位 | 完成 I3C 配置时钟、工作时钟和复位释放后重新配置流程验证 | 模块在指定时钟下功能正常，复位后可重新配置并恢复通信 |
| Master mode 速率 | 完成 I3C SDR0~SDR4、HDR-DDR 以及 I2C FM/FM+ 速率遍历 | 多种协议速率下传输功能正常 |
| CCC 命令传输 | 完成 Broadcast CCC、Directed CCC、SETAASA、SETDASA 等命令传输验证 | CCC 命令发送、响应和数据检查符合预期 |
| Private 读写传输 | 完成 TX FIFO、RX FIFO、short data 等 private transfer 场景验证 | 主模式下不同数据路径传输正常 |
| Slave mode 通信 | 完成 I3C slave 与 I2C slave 接收、发送场景验证 | Slave 模式下收发数据功能正常 |
| Secondary Master | 完成 I3C slave 切换/协同 Secondary Master 场景验证 | 总线状态更新、请求和响应流程正常 |
| DMA 测试 | 完成 TX FIFO/RX FIFO 与 memory 间 DMA 搬运验证 | DMA 搬运后数据比对正确 |
| 中断处理 | 完成中断触发、进入中断处理函数和数据检查 | 中断响应路径正常 |
| Debug port | 完成正常通信模式下 debug port/CBB REG 状态检查 | debug 状态可观测，寄存器状态符合预期 |

## Feature 列表

| 模块        | 一级 Feature                   | 二级 Feature 描述                                   | 覆盖说明                                                                              |
| --------- | ---------------------------- | ----------------------------------------------- | --------------------------------------------------------------------------------- |
| I3C0/I3C1 | 寄存器测试                        | 寄存器默认值检查、寄存器读写回读检查                              | 读取寄存器默认值，并写入多组典型数据后回读比对，确认寄存器访问路径正确                                               |
| I3C0/I3C1 | 时钟与复位                        | I3C 系统时钟、I3C 系统复位                               | 配置时钟和工作时钟为 APB 时钟，检查指定频率下功能正常；复位 release 后重新执行配置流程并确认通信恢复                         |
| I3C0/I3C1 | Master mode 通信               | I3C SDR0、SDR1、SDR2、SDR3、SDR4、HDR-DDR 速率测试       | 覆盖 I3C mode 下多种速率传输，检查 transfer command、response queue、data port 和数据比对结果          |
| I3C0/I3C1 | Master mode 通信               | I2C FM、I2C FM+ 兼容传输测试                           | 将 I3C 控制器配置为 I2C mode，覆盖 FM/FM+ 速率下与 I2C slave 的兼容传输                              |
| I3C0/I3C1 | CCC read/write transfers     | Broadcast CCC command transfer                  | 通过广播 CCC 命令进行通信，检查广播命令发送、响应状态和传输数据                                                |
| I3C0/I3C1 | CCC read/write transfers     | Directed CCC command transfer、SETAASA、SETDASA   | 通过定向 CCC 及地址相关命令完成目标设备配置，确认命令流程和动态地址配置行为正常                                        |
| I3C0/I3C1 | Private read/write transfers | TX FIFO transmit transfer                       | 通过 TX FIFO 发送数据，检查命令队列、TX data port 和传输完成状态                                       |
| I3C0/I3C1 | Private read/write transfers | RX FIFO receive transfer                        | 通过 RX FIFO 接收数据，检查 RX FIFO 状态、RX data port 和接收数据正确性                               |
| I3C0/I3C1 | Private read/write transfers | short data transmit transfer                    | 通过 short data/short argument 方式发送数据，确认短数据路径可正常传输                                  |
| I3C0/I3C1 | Slave mode receive           | I3C slave mode receive、I2C slave mode receive   | 作为 I3C/I2C slave 接收数据，检查 slave 静态地址、模式配置、FIFO 状态和接收数据                             |
| I3C0/I3C1 | Slave mode transmit          | I3C slave mode transmit、I2C slave mode transmit | 作为 I3C/I2C slave 发送数据，检查 slave 模式、TX FIFO 写入、发送命令和数据比对                            |
| I3C0/I3C1 | Secondary Master             | I3C slave to Secondary Master 场景                | 在 I3C slave 与 I3C master/I2C slave 组合场景下，验证 master request、bus owner 更新和总线控制权获取流程 |
| I3C0/I3C1 | DMA 测试                       | TX FIFO to memory、RX FIFO to memory             | 通过 DMA 搬运 TX FIFO/RX FIFO 与 memory 间数据，检查 DMA 配置、搬运完成和数据一致性                       |
| I3C0/I3C1 | 中断与错误处理                      | INT 中断处理、C code test                            | 触发中断后进入中断处理函数，读取 RX data port 或状态信息，并检查中断路径和传输数据                                  |
| I3C0/I3C1 | Debug port                   | Debug port/CBB REG 状态检查                         | 在正常通信模式下检查 CBB REG 各状态值，确认 debug port 可观测性和状态更新正确                                 |

## Case 列表

| 模块   | 验证方向           | Case                                                                                                                                                                                                                                                                                                                  |
| ---- | -------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| I3C0 | 寄存器测试          | i3c0_register_test                                                                                                                                                                                                                                                                                                    |
| I3C0 | 时钟与复位          | i3c0_clk_test、i3c0_rstn_test                                                                                                                                                                                                                                                                                          |
| I3C0 | Master mode 速率 | i3c0_master_mode_sdr0_rate_test、i3c0_master_mode_sdr1_rate_test、i3c0_master_mode_sdr2_rate_test、i3c0_master_mode_sdr3_rate_test、i3c0_master_mode_sdr4_rate_test、i3c0_master_mode_hdr_ddr_rate_test、i3c0_master_mode_i2c_fm_rate_test、i2c0_slave_i2c_fm_transmit_trans_test、i2c0_slave_i2c_fm_plus_transmit_trans_test |
| I3C0 | CCC 命令传输       | i3c0_master_broadcast_ccc_trans_test、i3c0_master_directed_ccc_trans_test、i3c0_master_setaasa_test、i3c0_master_setdasa_test                                                                                                                                                                                            |
| I3C0 | Private 传输     | i3c0_master_transmit_withtxfifo_test、i3c0_master_receive_withrxfifo_test、i3c0_master_transmit_withshortdata_test                                                                                                                                                                                                      |
| I3C0 | Slave mode 通信  | i3c0_slave_receive_trans_test、i3c0_slave_transmit_trans_test、i2c0_slave_receive_trans_test、i2c0_slave_transmit_trans_test、i3c0_slave_to_secmaster_test                                                                                                                                                                |
| I3C0 | DMA 测试         | i3c0_trans_txfifo_to_mem_withdma_test、i3c0_trans_rxfifo_to_mem_withdma_test                                                                                                                                                                                                                                           |
| I3C0 | 中断与 debug      | i3c0_intr_test、i3c0_debug_port_test                                                                                                                                                                                                                                                                                   |
| I3C1 | 寄存器测试          | i3c1_register_test                                                                                                                                                                                                                                                                                                    |
| I3C1 | 时钟与复位          | i3c1_clk_test、i3c1_rstn_test                                                                                                                                                                                                                                                                                          |
| I3C1 | Master mode 速率 | i3c1_master_mode_sdr0_rate_test、i3c1_master_mode_sdr1_rate_test、i3c1_master_mode_sdr2_rate_test、i3c1_master_mode_sdr3_rate_test、i3c1_master_mode_sdr4_rate_test、i3c1_master_mode_hdr_ddr_rate_test、i3c1_master_mode_i2c_fm_rate_test、i2c1_slave_i2c_fm_transmit_trans_test、i2c1_slave_i2c_fm_plus_transmit_trans_test |
| I3C1 | CCC 命令传输       | i3c1_master_broadcast_ccc_trans_test、i3c1_master_directed_ccc_trans_test、i3c1_master_setaasa_test、i3c1_master_setdasa_test                                                                                                                                                                                            |
| I3C1 | Private 传输     | i3c1_master_transmit_withtxfifo_test、i3c1_master_receive_withrxfifo_test、i3c1_master_transmit_withshortdata_test                                                                                                                                                                                                      |
| I3C1 | Slave mode 通信  | i3c1_slave_receive_trans_test、i3c1_slave_transmit_trans_test、i2c1_slave_receive_trans_test、i2c1_slave_transmit_trans_test、i3c1_slave_to_secmaster_test                                                                                                                                                                |
| I3C1 | DMA 测试         | i3c1_trans_txfifo_to_mem_withdma_test、i3c1_trans_rxfifo_to_mem_withdma_test                                                                                                                                                                                                                                           |
| I3C1 | 中断与 debug      | i3c1_intr_test、i3c1_debug_port_test                                                                                                                                                                                                                                                                                   |

## 工作总结

本阶段完成了 I3C0 和 I3C1 两个模块的 Feature 与 Case 覆盖关系整理，并按一级 Feature 和二级 Feature 描述对功能点进行了补充归类。两个实例的验证结构基本一致，均覆盖寄存器、时钟复位、主模式速率遍历、CCC 命令、private transfer、slave mode 收发、Secondary Master、DMA、中断和 debug port 等关键功能面。

在基础配置方面，已完成寄存器默认值和读写检查，并验证 I3C 配置时钟、工作时钟以及复位 release 后重新初始化流程。相关 case 表明模块在指定频率下能够正常工作，复位后重新配置和通信流程符合预期。

在 Master mode 通信方面，已覆盖 I3C SDR0 到 SDR4、HDR-DDR 以及 I2C FM/FM+ 兼容模式。验证流程包括配置参数、设置 queue/data buffer 阈值、选择 master 模式、配置动态地址、发送地址分配命令、配置 transfer command，并通过响应队列和数据比对确认传输结果。该部分覆盖了 I3C 主控通信的主要速率和协议兼容场景。

在 CCC 与 private transfer 方面，已验证 Broadcast CCC、Directed CCC、SETAASA、SETDASA 等命令传输，并覆盖 TX FIFO、RX FIFO 和 short data 三类 private 数据路径。验证结果说明命令发送、数据传输、响应等待和最终数据检查流程可正常闭环。

在 Slave mode 与 Secondary Master 场景方面，已覆盖 I3C slave 和 I2C slave 的接收、发送测试，并验证 I3C slave 在指定场景下与 I3C master/I2C slave 配合完成 Secondary Master 相关流程。该部分补充了模块在非主控角色下的数据收发能力和总线协同能力。

在 DMA、中断和 debug 方面，已完成 TX FIFO/RX FIFO 与 memory 间 DMA 搬运测试，中断触发及处理函数进入测试，以及 debug port 状态检查。相关验证表明 DMA 数据搬运后比对正确，中断响应路径正常，debug port/CBB REG 状态可用于通信状态观测。

综合来看，本阶段 I3C 验证已覆盖 I3C0/I3C1 的主从通信、速率模式、兼容模式、数据搬运、控制命令、中断和调试观测等核心功能。当前截图中可见 case 均为 `done`，可作为 I3C 模块基础功能验证完成情况的阶段性总结。
