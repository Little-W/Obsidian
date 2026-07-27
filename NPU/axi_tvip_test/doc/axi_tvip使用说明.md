# NPU 单核与固定地址命令 FIFO：AXI TVIP 验证环境使用说明

本文说明 `axi_tvip_test` 工程的目录关系、DUT 接口、命令 FIFO 协议、
单核系统连接、TVIP 配置、用例结构、运行命令和日志检查方法。

工程保留两个独立用例：

1. `npu_cmd_fifo` 单独检查固定地址命令入口；
2. `npu_single_core` 检查 `npu_single_core_top` 的主机访问、命令执行和
   `m_axi_*` 系统总线访问。

> [!important] 当前验证状态
> 独立命令 FIFO 已通过 Icarus 定向仿真、Verilator 静态检查和 VCS 编译。
> 2026-07-26 使用 VCS W-2024.09-SP1 和随机种子 1 完成 TVIP UVM 测试：
> BMS 返回 0，`UVM_ERROR` 与 `UVM_FATAL` 均为 0。详细结果见第 13 节。
> 整核用例的源码和配置已经加入工程，正式 VCS 结果应在共享运行副本完成后
> 再写入本文，不能用 Verilator 结果代替。

## 1. 源目录与运行副本

工程有两个目录：

| 用途 | 目录 |
| --- | --- |
| 受版本管理的源目录 | `/home/yusen/Obsidian Vault/NPU/axi_tvip_test` |
| 无空格的 BMS/VCS 运行副本 | `/home/yusen/opt/axi_tvip_test` |

源目录保存需要提交和审查的 RTL、testbench、sequence、case 配置与说明文档。
运行副本用于 BMS 和 VCS。这样可避免部分 EDA 脚本把目录名中的空格误当成参数
分隔符。

修改文件时应先更新源目录，再把同一版本同步到运行副本。不要只修改运行副本，
否则下一次同步可能覆盖这些改动。

运行前至少核对以下文件在两个目录中内容一致：

```text
hdl/npu_axi_cmd_fifo_slave.sv
tb/npu_cmd_backend_if.sv
tb/npu_single_core_system_if.sv
tb/npu_axi_system_memory_model.sv
tb/axi_tvip_myip_wrapper.sv
tb/axi_tvip_tb.sv
seq_lib/axi_tvip_npu_cmd_fifo_sequence.sv
seq_lib/axi_tvip_npu_cmd_fifo_test.sv
seq_lib/axi_tvip_npu_single_core_sequence.sv
seq_lib/axi_tvip_npu_single_core_test.sv
vcs_com/rtl.f
vcs_com/verif.f
vcs_com/vcs_com
test_lib/axi/cfg
test_lib/axi/npu_cmd_fifo/npu_cmd_fifo.tc
test_lib/axi/npu_single_core/npu_single_core.tc
npu_rtl/
```

> [!note] 为什么保留两个目录
> 源目录便于使用 Git 和 Obsidian；无空格副本便于 BMS 生成编译命令。
> 仿真日志只需要保存在运行副本中，不应复制回源目录。

## 2. 工程结构

```text
axi_tvip_test/
├── hdl/
│   └── npu_axi_cmd_fifo_slave.sv
├── tb/
│   ├── npu_cmd_backend_if.sv
│   ├── npu_single_core_system_if.sv
│   ├── npu_axi_system_memory_model.sv
│   ├── axi_tvip_myip_wrapper.sv
│   └── axi_tvip_tb.sv
├── seq_lib/
│   ├── axi_tvip_npu_cmd_fifo_sequence.sv
│   ├── axi_tvip_npu_cmd_fifo_test.sv
│   ├── axi_tvip_npu_single_core_sequence.sv
│   ├── axi_tvip_npu_single_core_test.sv
│   ├── axi_tvip_smoke_sequence.sv
│   └── axi_tvip_smoke_test.sv
├── test_lib/
│   ├── cfg
│   └── axi/
│       ├── cfg
│       ├── npu_cmd_fifo/
│       │   └── npu_cmd_fifo.tc
│       └── npu_single_core/
│           └── npu_single_core.tc
├── npu_rtl/
│   └── 当前单核 RTL 的共享运行副本
├── vcs_com/
│   ├── rtl.f
│   ├── verif.f
│   └── vcs_com
├── vendor/tvip-axi/
└── doc/
    └── axi_tvip使用说明.md
```

`rtl.f` 编译独立命令 FIFO 和完整单核 RTL。关键顶层为：

```text
/home/yusen/opt/axi_tvip_test/hdl/npu_axi_cmd_fifo_slave.sv
/home/yusen/opt/axi_tvip_test/npu_rtl/top/npu_single_core_top.sv
```

`vcs_com` 的 RTL elaboration top 为：

```text
npu_axi_cmd_fifo_slave
npu_single_core_top
```

旧的 `myip.v` 和 `myip_slave_full_v1_0_S00_AXI.v` 不再参加本用例编译。

## 3. DUT 的 AXI 配置

TVIP 和 DUT 使用同一组参数：

| 参数 | 数值 | 说明 |
| --- | ---: | --- |
| AXI protocol | AXI4 | 支持 burst |
| AXI ID width | 8 bit | `AWID/BID/ARID/RID` |
| AXI address width | 24 bit | NPU 本地地址 |
| AXI data width | 64 bit | 每拍 8 Byte |
| 最大 burst 长度 | 16 beat | 最多携带 8 条 128-bit 指令 |
| ingress FIFO 深度 | 16 beat | 至少保存一次最大命令 burst |
| 命令响应 FIFO 深度 | 8 项 | 至少保存一次最大 burst 的全部响应 |
| 同方向未完成事务数 | 1 | 第一版串行处理 |
| reset | `reset_n` | 低电平有效 |

AXI 写地址先完成握手，DUT 随后才接收对应的 W 数据。写响应使用锁存的
`AWID`。读返回使用锁存的 `ARID`。用例使用多个不同 ID 检查 `BID` 和
`RID` 是否正确保留。

## 4. 独立命令 FIFO 地址定义

`npu_cmd_fifo` 用例中的精简 DUT 实现三个 64-bit 地址：

| 本地地址 | 名称 | 属性 | 功能 |
| ---: | --- | --- | --- |
| `0x020000` | `CMD_FIFO_DATA` | WO | 接收固定地址命令 burst |
| `0x020008` | `CMD_RSP_FIFO` | RO | 每次成功读出并删除一项命令接收响应 |
| `0x020010` | `CMD_FIFO_STATUS` | RO | 返回 FIFO 数量和错误状态 |

其它地址在精简 DUT 中返回 `SLVERR`。LSC、调试寄存器、控制请求和
L1BUF 外部访问由 `npu_single_core` 用例检查，不属于精简 DUT 的功能。

### 4.1 状态寄存器

`CMD_FIFO_STATUS` 的字段如下：

| bit | 名称 | 说明 |
| ---: | --- | --- |
| `[7:0]` | ingress free beats | 当前还能预留的 64-bit beat 数 |
| `[15:8]` | response count | 响应 FIFO 中已有项数 |
| `[16]` | high word pending | 暂存区已收到一条命令的 low word，正在等待相邻 high word |
| `[17]` | ingress full | ingress 已无可用 beat |
| `[18]` | response full | 响应 FIFO 已满 |
| `[19]` | protocol error | 已保存一次命令 burst 格式错误 |
| `[63:20]` | reserved | 固定为 0 |

状态中的 ingress 可用数会扣除已经为当前写 burst 预留的位置。这样软件在
W 数据尚未全部到达时读取状态，也不会把预留位置误认为仍可使用。

bit 16 描述 AXI 写入暂存区，而不是 CFE 的发送状态。合法命令 burst 已接收
奇数个 beat 时该位为 1；收到相邻 high word 后清 0。暂存期间
`cmd_valid_o` 仍为 0，只有整个 burst 通过检查并提交后，CFE 才能看到数据。

## 5. 命令写入规则

写入 `CMD_FIFO_DATA` 时必须同时满足：

1. `AWADDR=0x020000`；
2. `AWSIZE=3`，表示每拍 8 Byte；
3. `AWBURST=FIXED`；
4. `AWLOCK=0`；
5. `AWLEN+1` 为 2、4、6、…、16；
6. 每拍 `WSTRB=0xFF`；
7. 只有第 `AWLEN+1` 拍设置 `WLAST=1`。

相邻两拍组成一条 128-bit 命令：

```text
beat 0 = cmd0.low
beat 1 = cmd0.high
beat 2 = cmd1.low
beat 3 = cmd1.high
...
```

同一个 burst 的每拍都写到 `0x020000`。地址保持不变是 FIXED burst 的正常
行为，不是重复写同一寄存器。

### 5.1 容量预留

DUT 收到合法 AW 时，先计算 `AWLEN+1`。只有 ingress 可用位置不少于该数值
时，`AWREADY` 才能完成握手。AW 握手后，这些位置立即被当前事务预留。

例如 ingress 还剩 10 个 beat：

- 10-beat 命令 burst 可以接收；
- 12-beat 命令 burst 必须等待；
- 正在接收的 10 个 beat 不会被另一个事务占用。

第一版每个写方向只保存一项事务，因此前一个 B response 未完成握手时不会接收
下一项 AW。

### 5.2 暂存和一次提交

W 阶段先把数据写入 16 项暂存区，不立即送给 CFE。最后一拍到达后，DUT 检查
地址属性、beat 数、每拍 strobe 和 `WLAST`。

若全部正确：

```text
暂存区中的全部 beat 一次写入 ingress FIFO
→ 返回 BRESP=OKAY
→ CFE 可以看到第一条命令
```

若任一项错误：

```text
丢弃本次暂存区内容
→ ingress FIFO 保持原有内容
→ 返回 BRESP=SLVERR
→ 设置 CMD_FIFO_STATUS[19]
```

因此 CFE 不会看到错误 burst 的前几拍。

### 5.3 `WLAST` 检查

DUT 按 `AWLEN+1` 接收 W 数据，并逐拍比较 `WLAST`：

- 较早的 beat 设置 `WLAST=1`：记录错误；
- 最后一拍没有设置 `WLAST=1`：记录错误；
- 最后一拍之前均为 0，最后一拍为 1：格式正确。

检测到较早的 `WLAST` 后，DUT仍按 AW 声明的长度接收剩余 beat，随后返回
`SLVERR`。这样 DUT 的 W 通道计数仍以已经接受的 AW 为依据。

## 6. CFE 后端接口

`npu_axi_cmd_fifo_slave` 使用以下端口连接 Command Front End。方向以 DUT 为
参照：

| 端口 | 方向 | 位宽 | 说明 |
| --- | --- | ---: | --- |
| `cmd_valid_o` | Output | 1 | 当前 64-bit 命令 beat 有效 |
| `cmd_ready_i` | Input | 1 | CFE 可以接收当前 beat |
| `cmd_data_o` | Output | 64 | 当前 low 或 high word |
| `cmd_first_o` | Output | 1 | 当前为 low word |
| `cmd_last_o` | Output | 1 | 当前为 high word |
| `cmd_rsp_valid_i` | Input | 1 | CFE 的命令接收响应有效 |
| `cmd_rsp_ready_o` | Output | 1 | DUT 可以保存响应 |
| `cmd_rsp_data_i` | Input | 64 | 命令接收响应数据 |
| `protocol_error_clear_i` | Input | 1 | 清除状态寄存器 bit 19 |
| `cmd_ingress_idle_o` | Output | 1 | 暂存区、ingress 和待响应命令均空 |

发送一条命令的顺序是：

```text
low word：cmd_valid_o=1，cmd_first_o=1，cmd_last_o=0
→ 等待 cmd_ready_i
→ high word：cmd_valid_o=1，cmd_first_o=0，cmd_last_o=1
→ 等待 cmd_ready_i
→ 等待 CFE 返回一项 cmd_rsp
→ 删除当前命令并处理下一条
```

high word 完成握手后，当前命令仍占用 ingress 的两个 beat。只有
`cmd_rsp_valid_i && cmd_rsp_ready_o` 成立后，DUT才删除这两个 beat。

当 `cmd_valid_o=1` 且 `cmd_ready_i=0` 时，`cmd_data_o`、`cmd_first_o` 和
`cmd_last_o` 必须保持不变。

## 7. 命令响应 FIFO

CFE 每接受一条完整 128-bit 指令，返回一项 64-bit 响应。DUT按收到顺序把响应写入
8 项 FIFO。

主控读取 `0x020008` 时：

- FIFO 非空：返回头部数据，`RRESP=OKAY`；
- `RVALID && RREADY` 成立后删除头部项；
- FIFO 为空：保存 AR 请求并等待 CFE 产生响应；
- 等待期间不会返回虚构数据。

响应 FIFO 满时，`cmd_rsp_ready_o` 拉低，CFE 必须保持
`cmd_rsp_valid_i` 和 `cmd_rsp_data_i`。若同一周期 AXI 读走一项响应，DUT
可以在该周期接收一项新的 CFE 响应。

已经写入响应 FIFO 的数据不影响 `cmd_ingress_idle_o`。该信号只描述命令接收
和 CFE 提交是否空闲。

## 8. 读事务规则

`CMD_RSP_FIFO` 和 `CMD_FIFO_STATUS` 只接受：

```text
ARLEN=0
ARSIZE=3
ARBURST=INCR
ARLOCK=0
ARADDR[2:0]=0
```

格式不符合要求或地址不受支持时，DUT返回单拍 `SLVERR`，`RDATA=0`，
`RLAST=1`。合法读返回使用原始 `ARID`。

当 `RVALID=1` 且 `RREADY=0` 时，`RID`、`RDATA`、`RRESP` 和 `RLAST` 保持
不变。

## 9. reset 行为

`reset_n=0` 时，DUT清除：

- 未完成的 AW/W 事务；
- burst 暂存信息；
- ingress FIFO 读写位置和数量；
- CFE low/high 发送状态；
- 响应 FIFO 读写位置和数量；
- 等待中的响应读请求；
- B/R channel valid；
- 已保存的协议错误。

复位释放后，状态寄存器应显示：

```text
ingress free beats = 16
response count     = 0
high word pending  = 0
ingress full       = 0
response full      = 0
protocol error     = 0
cmd_ingress_idle_o = 1
```

## 10. Testbench 连接

### 10.1 TVIP AXI interface

`axi_tvip_tb.sv` 实例化：

```systemverilog
tvip_axi_if axi_if(clk, reset_n);
npu_cmd_backend_if backend_if(clk, reset_n);
npu_single_core_system_if system_if(clk, reset_n);
axi_tvip_myip_wrapper dut_wrapper(axi_if, backend_if, system_if);
```

`axi_tvip_myip_wrapper.sv` 完成两类连接：

1. 把 TVIP 的低 8-bit ID、低 24-bit 地址和低 64-bit 数据接到 DUT；
2. 把精简命令 FIFO 的 CFE 端口接到 `npu_cmd_backend_if`；
3. 把单核 `m_axi_*` 接到系统总线存储目标，并把单核状态接到
   `npu_single_core_system_if`。

### 10.2 后端虚接口

`npu_cmd_backend_if` 提供 `driver_cb` 和 `monitor_cb`：

- `driver_cb` 驱动 `cmd_ready`、`cmd_rsp_valid`、`cmd_rsp_data` 和错误清除；
- `driver_cb` 同时采样 DUT 产生的命令和响应 ready；
- `monitor_cb` 采样双方握手与 idle 状态。

top 通过以下名称把虚接口交给 UVM test：

```text
vif
backend_vif
single_core_system_vif
```

`npu_cmd_fifo` 使用前两个名称；`npu_single_core` 使用 `vif` 和
`single_core_system_vif`。

### 10.3 编译次序

`verif.f` 中的关键次序必须是：

```text
tvip_axi_pkg.sv
tvip_axi_if.sv
npu_cmd_backend_if.sv
axi_tvip_myip_wrapper.sv
axi_tvip_tb.sv
```

`npu_cmd_backend_if.sv` 必须位于 wrapper 和 top 之前。

整核用例还要求以下次序：

```text
npu_single_core_system_if.sv
npu_axi_system_memory_model.sv
axi_tvip_myip_wrapper.sv
axi_tvip_tb.sv
```

### 10.4 单核的两组 AXI 接口

主机 TVIP agent 是 AXI Master，经 `s_axi_*` 访问 NPU 的寄存器、固定地址命令
FIFO 和 L1 外部窗口。NPU 只有一组对外 AXI Master，即顶层的 `m_axi_*`。
该接口接入 SoC 系统总线，用于读取描述符和模型数据，也用于 DMA 写回。

测试平台中的 `npu_axi_system_memory_model` 是系统总线上的一个存储目标。
模型端口使用 `s_axi_*`，因为它在这组事务中是 AXI Slave。它不是 NPU 内部
存储，也不表示 NPU 具有专用 DDR 接口。wrapper 中不存在第二组对外 Master。

> [!note] 为什么模型仍保存一组字节数组
> UVM sequence 需要在命令提交前放入描述符和输入数据，并在 DMA 完成后检查
> 写回内容。字节数组只用于仿真存储目标，不改变 NPU 的单 `m_axi_*` 接口设计。

## 11. TVIP 用例

### 11.1 独立命令 FIFO

case 名称：

```text
npu_cmd_fifo
```

tc 文件：

```text
/home/yusen/opt/axi_tvip_test/test_lib/axi/npu_cmd_fifo/npu_cmd_fifo.tc
```

指定的 UVM test：

```text
+UVM_TESTNAME=axi_tvip_npu_cmd_fifo_test
```

TVIP test 配置：

```text
protocol             = TVIP_AXI4
id_width             = 8
address_width        = 24
data_width           = 64
max_burst_length     = 16
response_ordering    = TVIP_AXI_IN_ORDER
outstanding_responses = 0
```

用例已编写以下检查项目：

1. 复位后的状态值；
2. 2、4、6、8、10、12、14、16 beat 合法 FIXED burst；
3. `BID` 和 `RID` 保存，包含多个不同 ID；
4. W channel 中间暂停；
5. burst 接收期间的状态值；
6. CFE `cmd_ready` 暂停；
7. 响应 FIFO 满时的暂停；
8. 空响应 FIFO 读等待；
9. 奇数 beat、错误 burst 类型和错误 strobe；
10. 较早或缺少 `WLAST`；
11. 错误 burst 整组丢弃；
12. 错误状态清除；
13. reset 清理 ingress、响应 FIFO 和未完成状态。

上述项目均已在 2026-07-26 的 seed 1 测试中执行并通过，运行记录见第 13 节。

### 11.2 完整单核

case 名称：

```text
npu_single_core
```

tc 文件：

```text
/home/yusen/opt/axi_tvip_test/test_lib/axi/npu_single_core/npu_single_core.tc
```

该 tc 设置：

```text
+UVM_TESTNAME=axi_tvip_npu_single_core_test
+NPU_SINGLE_CORE
```

`+NPU_SINGLE_CORE` 让 wrapper 选择完整单核。没有该参数时，wrapper 继续选择
独立命令 FIFO，因此原用例不需要改名或删除。

整核 sequence 包含以下项目：

1. 写 `CORE_CONTROL`，允许 NPU 接收命令；
2. 通过主机 `s_axi_*` 启用并访问 L1 外部窗口；
3. 使用 FIXED burst 提交 128-bit 指令；
4. Matrix 产生 Event，Vector 等待同一 Event 后执行；
5. `WAIT` 读取 Event 状态和生产者命令编号；
6. `QUERY` 读取任务状态与进度，`ACK` 释放任务项；
7. `FENCE` 分别等待 DMA、Matrix、Vector 和 Complex；
8. DMA 从系统存储读取数据到 L1；
9. DMA 从 L1 写回系统存储，并逐字节检查结果；
10. Complex 激活计算；
11. INT16 Vector，验证 dtype code 3；
12. INT16 Matrix，验证 pack 5 和 pack 6；
13. pack 7 返回 `BAD_DESC`，并保持目标区内容不变；
14. `CANCEL` 取消正在等待的 `FENCE`。

## 12. 运行方法

进入无空格运行副本：

```bash
cd /home/yusen/opt/axi_tvip_test
```

编译并运行：

```bash
BMS_USE_DTL=0 \
  bms /home/yusen/opt/axi_tvip_test/test_lib/axi/npu_cmd_fifo/npu_cmd_fifo \
  --lxc-run -c -s 1
```

运行完整单核：

```bash
BMS_USE_DTL=0 \
  bms /home/yusen/opt/axi_tvip_test/test_lib/axi/npu_single_core/npu_single_core \
  --lxc-run -w npu_single_core_tvip -c -s 1
```

只重新运行已有的编译结果：

```bash
BMS_USE_DTL=0 \
  bms /home/yusen/opt/axi_tvip_test/test_lib/axi/npu_cmd_fifo/npu_cmd_fifo \
  --lxc-run -s 1
```

指定运行目录名：

```bash
BMS_USE_DTL=0 \
  bms /home/yusen/opt/axi_tvip_test/test_lib/axi/npu_cmd_fifo/npu_cmd_fifo \
  --lxc-run -w npu_cmd_fifo_tvip -c -s 1
```

运行 AXI case 列表：

```bash
BMS_USE_DTL=0 bms -regr /home/yusen/opt/axi_tvip_test/test_lib/axi \
  --lxc-run -c -s 1
```

带代码覆盖率：

```bash
BMS_USE_DTL=0 \
  bms /home/yusen/opt/axi_tvip_test/test_lib/axi/npu_cmd_fifo/npu_cmd_fifo \
  --lxc-run -c -s 1 -cov
```

清理 BMS 生成内容：

```bash
cd /home/yusen/opt/axi_tvip_test
bms clean
```

## 13. 日志检查

默认运行目录通常位于：

```text
/home/yusen/opt/axi_tvip_test/test_lib/debug/npu_cmd_fifo
```

重点文件：

| 文件 | 内容 |
| --- | --- |
| `vlogan.log` | SystemVerilog 编译信息 |
| `vcs_rtl_elb.log` | RTL elaboration 信息 |
| `vcs_test_elb.log` | Testbench elaboration 信息 |
| `npu_cmd_fifo.log` | UVM 仿真日志；具体名称以 BMS 输出为准 |
| `inter.fsdb` | 波形数据库；仅在配置启用时生成 |

先检查编译和 elaboration：

```bash
rg -n "Error-|Syntax error|Undefined|Unresolved|FAILED|Fatal" \
  /home/yusen/opt/axi_tvip_test/test_lib/debug/npu_cmd_fifo/vlogan.log \
  /home/yusen/opt/axi_tvip_test/test_lib/debug/npu_cmd_fifo/vcs_rtl_elb.log \
  /home/yusen/opt/axi_tvip_test/test_lib/debug/npu_cmd_fifo/vcs_test_elb.log
```

再检查 UVM 摘要和本用例结束标志：

```bash
rg -n "NpuAxiCmdFifoEpilog|TvipAxiTestEpilog|UVM_ERROR|UVM_FATAL|TEST_" \
  /home/yusen/opt/axi_tvip_test/test_lib/debug/npu_cmd_fifo
```

只有同时满足以下条件，才能记录本次 TVIP 用例通过：

1. `NpuAxiCmdFifoEpilog: Passed` 出现；
2. `TvipAxiTestEpilog: Passed` 出现；
3. `UVM_ERROR : 0`；
4. `UVM_FATAL : 0`；
5. BMS 进程返回 0。

### 13.1 本轮结果记录

> [!success] TVIP UVM 测试通过
>
> - 运行日期：2026-07-26
> - 仿真器：VCS W-2024.09-SP1
> - 随机种子：1
> - BMS 返回值：0
> - `UVM_WARNING`：0
> - `UVM_ERROR`：0
> - `UVM_FATAL`：0
> - 命令数据拍数：96
> - 完整 128-bit 指令数：48
> - 后端响应数：48
> - 结束标志：`NpuAxiCmdFifoEpilog: Passed`、
>   `TvipAxiTestEpilog: Passed`
> - 日志目录：
>   `/home/yusen/opt/axi_tvip_test/test_lib/debug/root_tvip`
> - 仿真结束时间：5,935,000 ps
>
> 本轮测试包含 1～8 条 128-bit 指令的合法 FIXED burst、不同 AXI ID、写数据暂停、
> low/high 暂存状态、命令入口暂停、响应 FIFO 满与空读等待、非法 burst、
> `WSTRB` 错误、较早或缺少 `WLAST`、错误状态清除以及 reset 清理。

## 14. RTL 单独检查

以下命令不运行 TVIP UVM，只检查 DUT 本身。

### 14.1 Icarus 编译

```bash
cd "/home/yusen/Obsidian Vault"
iverilog -g2012 \
  -s npu_axi_cmd_fifo_slave \
  -o /tmp/npu_axi_cmd_fifo_slave.vvp \
  NPU/axi_tvip_test/hdl/npu_axi_cmd_fifo_slave.sv
```

### 14.2 Verilator 静态检查

```bash
cd "/home/yusen/Obsidian Vault"
verilator --lint-only --Wall -Wno-fatal \
  NPU/axi_tvip_test/hdl/npu_axi_cmd_fifo_slave.sv
```

### 14.3 VCS 编译检查

BMS 使用 `vcs_com/rtl.f` 和 `vcs_com/verif.f`。若只检查 RTL，可在运行副本中
执行与工程配置一致的 `vlogan` 命令；正式回归仍应通过 BMS 启动，以确保 UVM、
TVIP package 和 elaboration 参数一致。

## 15. 常见问题

### 15.1 AW 一直没有握手

检查：

1. 前一个 B response 是否仍未完成；
2. `AWLEN+1` 是否为 2～16 的偶数；
3. ingress 可用 beat 是否足够；
4. 地址是否为 `0x020000`；
5. `AWSIZE` 是否为 3；
6. `AWBURST` 是否为 FIXED。

合法 burst 在容量不足时会等待，而不是立即返回错误。

### 15.2 W 一直没有握手

DUT 必须先接收 AW，随后才设置 `WREADY`。若 master 只发 W 而没有完成 AW，
这是不符合本 DUT 接收顺序的事务。

### 15.3 BRESP 为 SLVERR

检查所有 W beat：

- `WSTRB` 必须全部为 `0xFF`；
- `WLAST` 只在最后一拍为 1；
- 实际 beat 数必须与 `AWLEN+1` 相同。

错误 burst 不会向 CFE 输出部分命令。

### 15.4 读取响应 FIFO 后一直没有 RVALID

空响应 FIFO 读采用等待行为。检查：

1. CFE 是否已经接收 low 和 high；
2. `cmd_rsp_valid` 是否产生；
3. `cmd_rsp_ready` 是否为 1；
4. backend 响应是否保持到握手；
5. reset 是否在等待期间出现。

### 15.5 interface 多驱动

DUT 输出先接到 wrapper 内的 `logic`，再由 wrapper 驱动 `tvip_axi_if` 或
`npu_cmd_backend_if`。不要在 sequence 中直接驱动 DUT 输出字段。

### 15.6 找不到后端虚接口

确认：

1. `npu_cmd_backend_if.sv` 在 wrapper 之前编译；
2. top 已实例化 `backend_if`；
3. top 使用名称 `backend_vif` 写入 `uvm_config_db`；
4. test 使用相同类型和名称读取。

### 15.7 BMS 仍在编译旧 myip

检查运行副本中的 `vcs_com/rtl.f`。开头应包含独立命令 FIFO，后续应列出
`npu_rtl` 中的单核 RTL：

```text
/home/yusen/opt/axi_tvip_test/hdl/npu_axi_cmd_fifo_slave.sv
/home/yusen/opt/axi_tvip_test/npu_rtl/npu_rtl_pkg.sv
/home/yusen/opt/axi_tvip_test/npu_rtl/top/npu_single_core_top.sv
```

同时检查 `vcs_com/vcs_com` 的 `[VCS_RTL_ELAB]` 部分：

```text
-top npu_axi_cmd_fifo_slave
-top npu_single_core_top
```

若仍看到旧 top，说明源目录与运行副本尚未同步。
