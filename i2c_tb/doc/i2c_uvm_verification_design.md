# I2C UVM 验证环境设计说明

本文档用于学习当前 `i2c_tb` UVM 验证环境的结构、设计思路和代码组织。目标不是泛泛介绍 UVM，而是结合工程 `D:\bms\i2c_tb` 中真实存在的源码，说明一个 case 如何从 `test_lib` 进入 UVM test，再进入 virtual sequence，最后通过 APB VIP 配置 DUT，并通过 I2C SVT VIP 与 DUT 发生总线交互。

当前 DUT module 名为 `MCU_I2C_WRAPPER`。验证环境的核心思路是：

1. `tb/i2c_tb.sv` 负责例化 DUT、interface、AMBA VIP interface、I2C VIP interface，并通过 `uvm_config_db` 把 virtual interface 和 VIP sequencer 句柄传给 UVM 层。
2. `seq_lib/i2c_base_test.sv` 负责创建 UVM component 层次，配置 AMBA VIP 和 I2C VIP。
3. `seq_lib/i2c_smoke_test.sv` 只保留一个固定 test 类，通过 `+SEQ=<seq_name>` 在运行时选择不同 sequence。
4. `seq_lib/common/base_virt_seq.sv` 是所有 I2C case 的 base virtual sequence，封装复位等待、时钟速率设置、APB VIP 读写、I2C VIP sequence 启动等公共动作。
5. `seq_lib/i2c_seq/*.sv` 承载主要测试流程，包含 DUT 寄存器配置、数据写读、错误场景、随机场景、slave 模式场景。
6. `env/agent` 保留轻量 UVM component 骨架，当前不在 driver、monitor、scoreboard 中实现复杂主流程。

## 一、工程目录和职责

当前工程与 UVM 验证相关的主要目录如下：

```text
i2c_tb/
  tb/
    i2c_tb.sv                      顶层 testbench，例化 DUT/VIP/interface
    i2c_if.sv                      DUT 侧 APB 和 I2C pad 信号 interface
    bind/
      i2c_bind.sv                  bind 到 MCU_I2C_WRAPPER
      i2c_bind_if_checker.sv       基础 SVA checker
  env/
    i2c_env_pkg.sv                 本地 UVM env package
    i2c_vir_sqr.sv                 本地 virtual sequencer
    agent/
      i2c_agt_pkg.sv               agent package
      i2c_agent.sv                 agent
      i2c_driver.sv                driver 骨架
      i2c_monitor.sv               monitor 骨架
      i2c_item.sv                  sequence item
      i2c_sequencer.sv             local sequencer
    vip/
      vip_stub_pkg.sv              AMBA VIP 和 I2C VIP 包装 include 入口
      apb_vip/env/                 APB VIP 示例和 directed sequence
      axi_vip/env/                 AXI VIP 示例环境
      ahb_vip/env/                 AHB VIP 示例环境
      i2c_vip/env/                 I2C VIP 示例 sequence、env、reg model
  seq_lib/
    base_test_pkg.sv               test package，include base_test 和 smoke_test
    i2c_base_test.sv               base test，创建 env 和 VIP env
    i2c_smoke_test.sv              固定 test，按 +SEQ 启动 sequence
    common/
      common_seq_pkg.sv            common sequence package
      base_virt_seq.sv             base virtual sequence
    i2c_seq/
      i2c_seq_pkg.sv               I2C sequence package
      i2c_basic_sequence.sv        master 模式基础写后读 sequence
      i2c_slave_smoke_seq.sv       slave 模式基础 sequence
      i2c_*_seq.sv                 speed、boundary、random、error 等扩展 case
  test_lib/
    i2c/
      smoke/smoke.tc               smoke case 运行参数
      basic/basic.tc               basic case 运行参数
      slave_smoke/slave_smoke.tc   DUT slave mode case
      error/error.tc               address NACK error case
      data_nack/data_nack.tc       data NACK error case
      boundary/boundary.tc         边界地址 case
      random/random.tc             随机寄存器 case
      speed_fast/speed_fast.tc     fast mode case
      speed_high/speed_high.tc     high speed mode case
  vcs_com/
    vcs_com                        VCS 编译/ elaboration 参数
    vip.f                          Synopsys SVT VIP 编译入口
    verif.f                        TB/env/seq/top 编译入口
    rtl.f                          外部 RTL filelist 入口
```

学习 UVM 时建议先按这条顺序读代码：

```text
tb/i2c_tb.sv
  -> seq_lib/base_test_pkg.sv
  -> seq_lib/i2c_base_test.sv
  -> env/i2c_env_pkg.sv
  -> seq_lib/i2c_smoke_test.sv
  -> seq_lib/common/base_virt_seq.sv
  -> seq_lib/i2c_seq/i2c_basic_sequence.sv
  -> env/vip/i2c_vip/env/i2c_vip_basic_env.sv
```

原因是：`i2c_tb.sv` 是硬件层入口，`i2c_base_test.sv` 是 UVM component 层入口，`i2c_smoke_test.sv` 是运行期 sequence 选择入口，`base_virt_seq.sv` 和 `i2c_basic_sequence.sv` 是实际测试动作入口。

## 二、编译入口和运行入口

### 2.1 VCS 编译入口

`vcs_com/vcs_com` 中定义了两个 top：

```text
[VCS_RTL_ELAB]
-top MCU_I2C_WRAPPER

[VCS_TEST_ELAB]
-top i2c_tb
```

这说明工程把 DUT elaboration top 和 testbench elaboration top 分开处理。`MCU_I2C_WRAPPER` 是真实 DUT 名称，`i2c_tb` 是验证顶层。

`vcs_com/vip.f` 负责引入 UVM 和 Synopsys SVT VIP：

```systemverilog
+incdir+/library/techlib/vip/vip1/vip/svt/common/W-2024.09/sverilog/include
+incdir+/library/techlib/vip/vip1/vip/svt/amba_svt/W-2024.09/sverilog/include
+incdir+/library/techlib/vip/vip1/vip/svt/i2c_svt/W-2024.09/sverilog/include
+incdir+/library/techlib/vip/vip1/vip/svt/i2c_svt/W-2024.09/sverilog/src/vcs
+incdir+/library/techlib/vip/vip1/vip/svt/i2c_svt/W-2024.09/sverilog/src/com

/App/synopsys/vcs/T-2022.06-SP2/etc/uvm-1.2/uvm_pkg.sv
/library/techlib/vip/vip1/vip/svt/common/W-2024.09/sverilog/include/svt.uvm.pkg
/library/techlib/vip/vip1/vip/svt/common/W-2024.09/sverilog/include/svt_mem.uvm.pkg
/library/techlib/vip/vip1/vip/svt/amba_svt/W-2024.09/sverilog/include/svt_axi.uvm.pkg
/library/techlib/vip/vip1/vip/svt/amba_svt/W-2024.09/sverilog/include/svt_ahb.uvm.pkg
/library/techlib/vip/vip1/vip/svt/amba_svt/W-2024.09/sverilog/include/svt_apb.uvm.pkg
/library/techlib/vip/vip1/vip/svt/i2c_svt/W-2024.09/sverilog/include/svt_i2c.uvm.pkg
```

`vcs_com/verif.f` 负责编译本地验证代码：

```systemverilog
+incdir+$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/env/vip/i2c_vip/env
+incdir+$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/env/vip
$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/env/vip/vip_stub_pkg.sv

+incdir+$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/env
+incdir+$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/env/agent
$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/env/agent/i2c_agt_pkg.sv
$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/env/i2c_env_pkg.sv

+incdir+$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/seq_lib/common
$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/seq_lib/common/common_seq_pkg.sv

+incdir+$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/seq_lib
+incdir+$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/seq_lib/i2c_seq
$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/seq_lib/i2c_seq/i2c_seq_pkg.sv
$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/seq_lib/base_test_pkg.sv
$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/seq_lib/i2c_test_pkg.sv

$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/tb/i2c_if.sv
$ZC_NPU_VERIF_ROOT/2_verf/it/i2c_tb/tb/i2c_tb.sv
```

这里有一个重要的学习点：package 编译顺序是有依赖关系的。`vip_stub_pkg` 先于本地 env 编译，因为 `i2c_env_pkg` 和 `base_test_pkg` 需要 import VIP 相关类型。`i2c_agt_pkg` 先于 `i2c_env_pkg`，因为 env 内部创建了 `i2c_agent`。

### 2.2 Case 运行入口

当前所有 case 都使用同一个 UVM test：

```text
+UVM_TESTNAME=i2c_smoke_test
```

差异通过 `+SEQ=<sequence class name>` 指定。例如 `test_lib/i2c/smoke/smoke.tc`：

```text
+SIM+ +UVM_TESTNAME=i2c_smoke_test +SEQ=i2c_smoke_seq +I2C_TARGET_ADDR=55 +I2C_SLAVE_TYPE=generic +I2C_SPEED_MODE=standard +I2C_VIP_WAIT_FIRST_WRITE
```

`test_lib/i2c/slave_smoke/slave_smoke.tc`：

```text
+SIM+ +UVM_TESTNAME=i2c_smoke_test +SEQ=i2c_slave_smoke_seq +I2C_DUT_MODE=slave +I2C_TARGET_KEEP_MASTER=0 +I2C_TARGET_ADDR=55 +I2C_CONTROLLER_TAR_ADDR=56 +I2C_SPEED_MODE=standard +I2C_TIMEOUT_SCALE=6 +I2C_START_DELAY_CYCLES=100 +I2C_VIP_REG_QUIET +I2C_ADDR_TRACE +I2C_ADDR_TRACE_DETAIL +I2C_ADDR_TRACE_MAX=4 +I2C_ACK_TRACE_EVENTS=16
```

这种设计的好处是 test 类数量少，case 扩展主要靠 sequence。对于初学 UVM，这是一个很清晰的模式：

```text
一个 test 管环境
多个 sequence 管场景
每个 .tc 管运行参数
```

## 三、顶层 testbench：`tb/i2c_tb.sv`

### 3.1 顶层职责

`i2c_tb` 是硬件世界和 UVM 世界的连接点。它做几件事：

1. 例化本地 `i2c_if tb_if(clk)`。
2. 例化 SVT I2C VIP interface 和 wrapper。
3. 例化 SVT APB/AXI/AHB interface。
4. 例化 DUT `MCU_I2C_WRAPPER u_dut`。
5. 产生 `clk`、`pclk`、`ic_clk`、`i2c_ref_clk`。
6. 做 reset 初始化。
7. 将 virtual interface 放入 `uvm_config_db`。
8. 调用 `run_test()` 进入 UVM。

真实代码片段：

```systemverilog
module i2c_tb;
  import uvm_pkg::*;
`include "uvm_macros.svh"
`ifdef BMS_USE_SVT_VIP
  import svt_uvm_pkg::*;
  import svt_mem_uvm_pkg::*;
  import svt_axi_uvm_pkg::*;
  import svt_ahb_uvm_pkg::*;
  import svt_apb_uvm_pkg::*;
`endif
  import base_test_pkg::*;
`ifdef BMS_USE_SVT_VIP
  import svt_i2c_uvm_pkg::*;
  import svt_i2c_enum_pkg::*;
`endif

  logic clk;
  logic pclk;
  logic ic_clk;
  bit i2c_ref_clk;
  i2c_if tb_if(clk);
```

从教学角度看，`i2c_tb` 不应该写复杂的测试流程。它更像“插线板”和“系统启动器”：把 DUT、interface、VIP 和 UVM 连接起来，然后把控制权交给 UVM sequence。

### 3.2 DUT interface：`tb/i2c_if.sv`

`i2c_if` 把 DUT 端口分成两组：

1. APB 寄存器访问接口，例如 `psel`、`penable`、`paddr`、`pwdata`、`prdata`。
2. I2C pad 接口，例如 `ic_clk_in_a`、`ic_clk_oe`、`ic_data_in_a`、`ic_data_oe`、`ic_intr`、`ic_en`。

真实代码：

```systemverilog
interface i2c_if(input logic clk);
  int unsigned pclk_half_period_ns = 5;
  int unsigned ic_clk_half_period_ns = 50;

  logic rst_n;
  logic pclk;
  logic presetn;
  logic psel;
  logic penable;
  logic [2:0] pprot;
  logic [3:0] pstrb;
  logic pready;
  logic pslverr;
  logic [31:0] prdata;
  logic pwrite;
  logic [31:0] paddr;
  logic [31:0] pwdata;
  logic ic_clk;
  logic ic_rst_n;
  logic ic_current_src_en;
  logic ic_clk_in_a;
  logic ic_clk_oe;
  logic ic_data_in_a;
  logic ic_data_oe;
  logic ic_intr;
  logic ic_en;
endinterface
```

`pclk_half_period_ns` 和 `ic_clk_half_period_ns` 是可被 sequence 修改的时钟半周期参数。`base_virt_seq::set_i2c_speed_mode()` 会根据 standard、fast、high 等模式修改 `ic_clk_half_period_ns`，从而让验证 case 与不同 I2C 速率匹配。

### 3.3 DUT 例化

当前 DUT 例化真实存在于 `tb/i2c_tb.sv`：

```systemverilog
MCU_I2C_WRAPPER u_dut (
`ifdef BMS_USE_SVT_VIP
  .pclk             (apb_dut_master_if.pclk),
  .presetn          (apb_dut_master_if.presetn),
  .psel             (apb_dut_master_if.psel),
  .penable          (apb_dut_master_if.penable),
  .pprot            (apb_dut_master_if.pprot),
  .pstrb            (apb_dut_master_if.pstrb),
  .pready           (apb_dut_master_if.pready[0]),
  .pslverr          (apb_dut_master_if.pslverr[0]),
  .prdata           (apb_dut_master_if.prdata[0]),
  .pwrite           (apb_dut_master_if.pwrite),
  .paddr            (apb_dut_master_if.paddr),
  .pwdata           (apb_dut_master_if.pwdata),
`else
  .pclk             (tb_if.pclk),
  .presetn          (tb_if.presetn),
  .psel             (tb_if.psel),
  .penable          (tb_if.penable),
  .pprot            (tb_if.pprot),
  .pstrb            (tb_if.pstrb),
  .pready           (tb_if.pready),
  .pslverr          (tb_if.pslverr),
  .prdata           (tb_if.prdata),
  .pwrite           (tb_if.pwrite),
  .paddr            (tb_if.paddr),
  .pwdata           (tb_if.pwdata),
`endif
  .ic_clk           (tb_if.ic_clk),
  .ic_rst_n         (tb_if.ic_rst_n),
  .ic_current_src_en(tb_if.ic_current_src_en),
  .ic_clk_in_a      (tb_if.ic_clk_in_a),
  .ic_clk_oe        (tb_if.ic_clk_oe),
  .ic_data_in_a     (tb_if.ic_data_in_a),
  .ic_data_oe       (tb_if.ic_data_oe),
  .ic_intr          (tb_if.ic_intr),
  .ic_en            (tb_if.ic_en)
);
```

注意 APB 接口在 `BMS_USE_SVT_VIP` 打开时连接到 `svt_apb_if apb_dut_master_if()`，这符合“DUT 存在 AMBA 接口时使用 AMBA VIP interface”的设计要求。sequence 不手写 `apb_write`、`apb_read` task，而是通过 APB VIP sequence 访问寄存器。

### 3.4 I2C open-drain 总线连接

I2C 是 open-drain/open-collector 风格，总线由上拉保持为 1，设备只能主动拉低。当前 TB 中，DUT 的 `ic_clk_oe`、`ic_data_oe` 被解释成“是否拉低 SCL/SDA”的控制信号，然后驱动 SVT I2C VIP interface：

```systemverilog
assign i2c_vif.RST = ~tb_if.ic_rst_n;
assign tb_if.ic_clk_in_a  = (i2c_vif.SCL === 1'b0) ? 1'b0 : 1'b1;
assign tb_if.ic_data_in_a = (i2c_vif.SDA === 1'b0) ? 1'b0 : 1'b1;
assign i2c_vif.SCL = i2c_dut_scl_drive_low ? 1'b0 : 1'bz;
assign i2c_vif.SDA = i2c_dut_sda_drive_low ? 1'b0 : 1'bz;
```

这里不要把 `1'bz` 理解成错误。对 I2C 总线来说，释放总线就是高阻，由 pullup 让线保持高电平。SVT I2C interface 中还打开了 pullup：

```systemverilog
i2c_vif.enable_pullup_resistor = 1'b1;
```

当前版本没有用 TB 代替 DUT 拉 ACK。`i2c_dut_pad_ack_bridge_drive_low` 是固定 `1'b0`，只保留在 trace 打印中帮助确认没有 TB ACK 代拉：

```systemverilog
localparam bit i2c_dut_pad_ack_bridge_drive_low = 1'b0;
```

因此如果 slave 模式下没有 ACK，应优先检查 DUT 的配置、`ic_en`、`ic_data_oe`、`ic_data_in_a`、`IC_SAR`、`IC_CON`、`IC_ENABLE` 等真实 DUT 路径，而不是依赖 testbench 代 ACK。

### 3.5 config_db 入口

`i2c_tb.sv` 最后通过 `uvm_config_db` 把 interface 和 sequencer 句柄交给 UVM：

```systemverilog
initial begin
  uvm_config_db#(virtual i2c_if)::set(null, "uvm_test_top", "vif", tb_if);
`ifdef BMS_USE_SVT_VIP
  apb_dut_master_vif = apb_dut_master_if;
  apb_dut_slave_vif = apb_dut_slave_if;
  ahb_dut_vif = ahb_dut_if;
  axi_dut_vif = axi_dut_if;

  uvm_config_db#(svt_ahb_vif)::set(uvm_root::get(), "uvm_test_top.ahb_env.ahb_system_env", "vif", ahb_dut_vif);
  uvm_config_db#(svt_apb_vif)::set(uvm_root::get(), "uvm_test_top.apb_env.apb_master_env", "vif", apb_dut_master_vif);
  uvm_config_db#(svt_apb_vif)::set(uvm_root::get(), "uvm_test_top.apb_env.apb_slave_env", "vif", apb_dut_slave_vif);
  uvm_config_db#(svt_axi_vif)::set(uvm_root::get(), "uvm_test_top.axi_env.axi_system_env", "vif", axi_dut_vif);

  uvm_config_db#(virtual svt_i2c_if)::set(uvm_root::get(), "uvm_test_top.i2c_vip_env", "vif", i2c_vif);
  uvm_config_db#(uvm_sequencer_base)::set(null, "uvm_test_top", "apb_vip_sqr_m0", apb_vip_sqr_m0);
  uvm_config_db#(uvm_sequencer_base)::set(null, "uvm_test_top", "i2c_vip_slv_sqr0", i2c_vip_slv_sqr0);
  uvm_config_db#(uvm_sequencer_base)::set(null, "uvm_test_top", "i2c_vip_mst_sqr0", i2c_vip_mst_sqr0);
`endif
  run_test();
end
```

学习点：`uvm_config_db` 的路径要和 UVM component 实例名对应。例如 `uvm_test_top.i2c_vip_env` 对应 `i2c_base_test` 中创建的 `i2c_vip_basic_env i2c_vip_env`。

## 四、UVM component 层次

当前 UVM 层次可以简化理解为：

```text
uvm_test_top: i2c_smoke_test
  extends i2c_base_test
  m_env: i2c_env
    agt: i2c_agent
      sqr: i2c_sequencer
      drv: i2c_driver
      mon: i2c_monitor
    virt_sqr: i2c_virtual_sequencer
  apb_env: apb_basic_env
  ahb_env: ahb_ral_env
  axi_env: axi_basic_env
  i2c_vip_env: i2c_vip_basic_env
    i2c_system_env: svt_i2c_system_env
    reg_model: i2c_vip_reg_model
```

其中 `apb_env`、`ahb_env`、`axi_env`、`i2c_vip_env` 只在 `BMS_USE_SVT_VIP` 打开时创建。

### 4.1 本地 env：`i2c_env`

`env/i2c_env_pkg.sv` 中定义了本地 env：

```systemverilog
class i2c_env extends uvm_env;
  `uvm_component_utils(i2c_env)

  i2c_agent agt;
  i2c_virtual_sequencer virt_sqr;

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    agt = i2c_agent::type_id::create("agt", this);
    virt_sqr = i2c_virtual_sequencer::type_id::create("virt_sqr", this);
  endfunction

  function void connect_phase(uvm_phase phase);
    super.connect_phase(phase);
    virt_sqr.i2c_sqr = agt.sqr;
  endfunction
endclass
```

这是一种很常见的 env 写法：

1. `build_phase` 创建子 component。
2. `connect_phase` 连接子 component 之间的句柄。
3. env 不直接跑测试动作。

`virt_sqr.i2c_sqr = agt.sqr` 的作用是让 virtual sequence 能通过 virtual sequencer 找到 local sequencer。当前主要测试动作走 APB VIP 和 I2C VIP，所以 local `i2c_sqr` 使用较少，但这个结构保留了后续扩展空间。

### 4.2 local agent

`i2c_agent` 是标准 UVM agent 骨架：

```systemverilog
class i2c_agent extends uvm_agent;
  `uvm_component_utils(i2c_agent)
  i2c_sequencer sqr;
  i2c_driver drv;
  i2c_monitor mon;

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    mon = i2c_monitor::type_id::create("mon", this);
    if (is_active == UVM_ACTIVE) begin
      sqr = i2c_sequencer::type_id::create("sqr", this);
      drv = i2c_driver::type_id::create("drv", this);
    end
  endfunction

  function void connect_phase(uvm_phase phase);
    super.connect_phase(phase);
    if (is_active == UVM_ACTIVE) begin
      drv.seq_item_port.connect(sqr.seq_item_export);
    end
  endfunction
endclass
```

这个 agent 的教学意义很直接：UVM agent 通常包含 sequencer、driver、monitor。active agent 会创建 sequencer 和 driver，passive agent 通常只保留 monitor。

当前 `i2c_driver` 只消费 item，不实现复杂驱动：

```systemverilog
task run_phase(uvm_phase phase);
  i2c_item req;
  forever begin
    seq_item_port.get_next_item(req);
    @(posedge vif.clk);
    seq_item_port.item_done();
  end
endtask
```

这说明当前环境的主要激励不是 local driver，而是在 virtual sequence 中通过 APB VIP 配 DUT，通过 I2C VIP 产生从设备或主设备行为。

当前 `i2c_monitor` 做轻量采样：

```systemverilog
task run_phase(uvm_phase phase);
  i2c_item tr;
  forever begin
    @(posedge vif.clk);
    if (vif.rst_n) begin
      tr = i2c_item::type_id::create("tr");
      tr.data = {6'h0, vif.ic_clk_in_a, vif.ic_data_in_a};
      ap.write(tr);
    end
  end
endtask
```

这里的 `ap` 是 `uvm_analysis_port#(i2c_item)`。当前源码中未看到本地 scoreboard 连接这个 analysis port，因此本地 monitor 主要是骨架和扩展点。数据检查主要在 sequence 和 I2C VIP reg model 中完成。

## 五、base test：`i2c_base_test`

`i2c_base_test` 是 UVM component 层最关键的类。它负责：

1. 从 `uvm_config_db` 获取 `virtual i2c_if`。
2. 创建 `i2c_env m_env`。
3. 创建 APB、AHB、AXI、I2C VIP env。
4. 根据 plusarg 配置 I2C VIP active/passive 角色。
5. 在 `connect_phase` 中把 VIP sequencer 句柄接入本地 virtual sequencer。

### 5.1 获取 virtual interface

```systemverilog
if (!uvm_config_db#(virtual i2c_if)::get(this, "", "vif", vif)) begin
  `uvm_fatal("NOVIF", "virtual interface i2c_if is not set")
end
uvm_config_db#(virtual i2c_if)::set(this, "m_env*", "vif", vif);
m_env = i2c_env::type_id::create("m_env", this);
```

这里有两个方向：

1. `get`：从 `i2c_tb.sv` 放入的 config_db 中拿到 `tb_if`。
2. `set`：把同一个 `vif` 继续传给 `m_env`、agent、driver、monitor、virtual sequencer。

如果路径不对，就会触发 `NOVIF` fatal，这是 UVM 初学中最常见的问题之一。

### 5.2 I2C VIP 配置

`i2c_base_test` 中通过 plusarg 配置 I2C VIP：

```systemverilog
i2c_vip_cfg = cust_svt_i2c_system_configuration::type_id::create("i2c_vip_cfg", this);
if ($value$plusargs("I2C_TARGET_ADDR=%h", i2c_plusarg_value)) begin
  i2c_vip_cfg.slave_cfg[0].slave_address = i2c_plusarg_value[9:0];
end
if (!$value$plusargs("I2C_DUT_MODE=%s", i2c_dut_mode)) begin
  i2c_dut_mode = "master";
end
```

当 DUT 作为 master 时，VIP slave active：

```systemverilog
i2c_vip_cfg.master_cfg[0].is_active = 0;
i2c_vip_cfg.master_cfg[0].enable_put_response = 0;
i2c_vip_cfg.slave_cfg[0].is_active = 1;
```

当 DUT 作为 slave 时，VIP master active：

```systemverilog
i2c_vip_cfg.master_cfg[0].is_active = 1;
i2c_vip_cfg.master_cfg[0].enable_put_response = 1;
i2c_vip_cfg.slave_cfg[0].is_active = 0;
i2c_vip_cfg.slave_cfg[0].enable_put_response = 0;
```

这就是 I2C master/slave 测试最核心的角色切换：

```text
DUT master mode:
  DUT 主动发起 I2C 访问
  I2C VIP slave 响应地址、数据、读返回

DUT slave mode:
  I2C VIP master 主动发起访问
  DUT 作为目标设备响应地址、接收写数据、提供读数据
```

### 5.3 speed mode 配置

I2C VIP speed 由 `+I2C_SPEED_MODE` 控制：

```systemverilog
if (i2c_speed_mode == "standard") begin
  i2c_vip_cfg.set_bus_speed(STANDARD_MODE);
end else if (i2c_speed_mode == "fast") begin
  i2c_vip_cfg.set_bus_speed(FAST_MODE);
end else if (i2c_speed_mode == "fast_plus") begin
  i2c_vip_cfg.set_bus_speed(FAST_MODE_PLUS);
end else if (i2c_speed_mode == "high") begin
  i2c_vip_cfg.set_bus_speed(HIGHSPEED_MODE);
end
```

这只配置 VIP 的总线速度。DUT 自身的 SCL 计数寄存器在 `i2c_basic_sequence::program_scl_counts()` 中配置。

### 5.4 connect_phase 连接 sequencer

```systemverilog
m_env.virt_sqr.ahb_vip_sqr = ahb_env.ahb_system_env.sequencer;
m_env.virt_sqr.apb_vip_sqr = apb_env.apb_master_env.sequencer;
m_env.virt_sqr.axi_vip_sqr = axi_env.axi_system_env.sequencer;
i2c_vip_mst_sqr0 = i2c_vip_env.i2c_system_env.sequencer.master_sequencer[0];
i2c_vip_slv_sqr0 = i2c_vip_env.i2c_system_env.sequencer.slave_sequencer[0];
```

sequencer 是 sequence 的启动目标。没有 sequencer，sequence 只是一个对象，不能和 driver/VIP 发生交互。这里把 APB/I2C VIP sequencer 句柄保存下来，后面 `base_virt_seq` 就可以启动对应 VIP sequence。

## 六、fixed test + runtime sequence

当前工程没有为每个 case 创建一个 test class，而是固定使用 `i2c_smoke_test`：

```systemverilog
class i2c_smoke_test extends i2c_base_test;
  `uvm_component_utils(i2c_smoke_test)
```

`run_phase` 中读取 `+SEQ`：

```systemverilog
if (!$value$plusargs("SEQ=%s", seq_name)) begin
  seq_name = "i2c_smoke_seq";
end

seq_obj = uvm_factory::get().create_object_by_name(seq_name, get_full_name(), "seq_obj");
if (seq_obj == null) begin
  `uvm_fatal("BAD_SEQ", $sformatf("Unknown +SEQ=%s", seq_name))
end
```

如果创建出来的是 `base_virt_seq` 派生类，就给它补齐环境句柄和 VIP sequencer 句柄：

```systemverilog
if ($cast(virt_seq, seq_base)) begin
  virt_seq.vif = vif;
  virt_seq.env = m_env;
`ifdef BMS_USE_SVT_VIP
  virt_seq.apb_vip_sqr_m0 = apb_vip_sqr_m0;
  virt_seq.i2c_vip_slv_sqr0 = i2c_vip_slv_sqr0;
  virt_seq.i2c_vip_mst_sqr0 = i2c_vip_mst_sqr0;
  virt_seq.apb_vip_sqr = m_env.virt_sqr.apb_vip_sqr;
`endif
  seq_base.start(null);
end else begin
  seq_base.start(m_env.agt.sqr);
end
```

这段非常适合学习 virtual sequence。普通 sequence 通常 start 在某个 sequencer 上，而 virtual sequence 是“编排者”，它可能同时控制多个 sequencer，所以这里用 `seq_base.start(null)`，并通过对象成员句柄去访问 APB VIP 和 I2C VIP sequencer。

## 七、base virtual sequence：`base_virt_seq`

`base_virt_seq` 是所有主要 I2C case 的公共父类：

```systemverilog
class base_virt_seq extends uvm_sequence;
  `uvm_object_utils(base_virt_seq)

  virtual i2c_if vif;
  i2c_env env;
`ifdef BMS_USE_SVT_VIP
  uvm_sequencer_base apb_vip_sqr_m0;
  uvm_sequencer_base i2c_vip_slv_sqr0;
  uvm_sequencer_base i2c_vip_mst_sqr0;
  svt_apb_system_sequencer apb_vip_sqr;
`endif
```

### 7.1 pre_body 检查

```systemverilog
task pre_body();
  if (vif == null) begin
    `uvm_fatal("NOVIF", "base_virt_seq requires vif")
  end
  if (env == null) begin
    `uvm_fatal("NOENV", "base_virt_seq requires env")
  end
endtask
```

这是一个很好的习惯：virtual sequence 运行前先检查关键句柄是否为空。否则后面访问 `vif` 或 sequencer 时，报错位置会更深、更难定位。

### 7.2 复位等待

```systemverilog
task wait_reset_done();
  wait (vif.rst_n === 1'b1);
  wait (vif.presetn === 1'b1);
  wait (vif.ic_rst_n === 1'b1);
  repeat (2) @(posedge vif.clk);
endtask
```

这个 task 把 testbench reset、APB reset、I2C reset 都等待完成，保证 sequence 不会在 DUT 未释放复位时访问寄存器。

### 7.3 根据速率设置时钟

```systemverilog
task set_i2c_speed_mode(string mode);
  int unsigned pclk_half_ns;
  int unsigned ic_clk_half_ns;

  pclk_half_ns = 5;
  if (mode == "standard") begin
    ic_clk_half_ns = 50;
  end else if ((mode == "fast") || (mode == "fast_plus")) begin
    ic_clk_half_ns = 10;
  end else if (mode == "high") begin
    ic_clk_half_ns = 2;
  end else begin
    ic_clk_half_ns = 50;
  end

  vif.pclk_half_period_ns = pclk_half_ns;
  vif.ic_clk_half_period_ns = ic_clk_half_ns;
endtask
```

这里体现了“时钟由验证 case 自动生成设置”的设计。`i2c_tb.sv` 的 clock generator 使用 interface 中的半周期参数：

```systemverilog
initial begin
  pclk = 1'b0;
  forever #(tb_if.pclk_half_period_ns) pclk = ~pclk;
end

initial begin
  ic_clk = 1'b0;
  forever #(tb_if.ic_clk_half_period_ns) ic_clk = ~ic_clk;
end
```

### 7.4 APB VIP 寄存器访问

`base_virt_seq` 没有手写 APB task，而是启动 APB VIP sequence：

```systemverilog
task apb_vip_write32(bit [31:0] addr, bit [31:0] data);
  apb_master_directed_write_sequence seq;
  uvm_sequencer_base target_sqr;

  target_sqr = apb_vip_sqr_m0;
  if ((target_sqr == null) && (apb_vip_sqr != null)) begin
    target_sqr = apb_vip_sqr.master_sequencer;
  end
  if (target_sqr == null) begin
    `uvm_fatal("APB_VIP_SQR_NULL", "apb_vip_sqr_m0 is null; cannot access DUT registers")
  end
  seq = apb_master_directed_write_sequence::type_id::create("apb_vip_write32_seq");
  seq.apb_w_addr = addr;
  seq.apb_w_data = data;
  seq.start(target_sqr);
endtask
```

读寄存器同理：

```systemverilog
task apb_vip_read32(bit [31:0] addr, output bit [31:0] data);
  apb_master_directed_read_sequence seq;
  uvm_sequencer_base target_sqr;

  target_sqr = apb_vip_sqr_m0;
  if ((target_sqr == null) && (apb_vip_sqr != null)) begin
    target_sqr = apb_vip_sqr.master_sequencer;
  end
  if (target_sqr == null) begin
    `uvm_fatal("APB_VIP_SQR_NULL", "apb_vip_sqr_m0 is null; cannot access DUT registers")
  end
  seq = apb_master_directed_read_sequence::type_id::create("apb_vip_read32_seq");
  seq.apb_r_addr = addr;
  seq.start(target_sqr);
  data = seq.apb_r_data;
endtask
```

这段代码是本环境很重要的设计原则：DUT 寄存器访问统一通过 APB VIP，不在 I2C sequence 中复制或自创 `apb_write`、`apb_read`。

### 7.5 启动 I2C VIP sequence

DUT master mode 需要 VIP slave 响应，启动 slave sequencer：

```systemverilog
task start_i2c_vip_slave_sequence(string seq_name);
`ifdef BMS_USE_SVT_VIP
  uvm_object seq_obj;
  uvm_sequence_base seq_base;
  if (i2c_vip_slv_sqr0 == null) begin
    `uvm_fatal("I2C_VIP_SQR_NULL", "i2c_vip_slv_sqr0 is null; cannot start I2C VIP slave sequence")
  end
  seq_obj = uvm_factory::get().create_object_by_name(seq_name, get_full_name(), "i2c_vip_slave_seq");
  if (seq_obj == null) begin
    `uvm_fatal("I2C_VIP_SEQ_NF", $sformatf("Cannot create I2C VIP sequence: %s", seq_name))
  end
  if (!$cast(seq_base, seq_obj)) begin
    `uvm_fatal("I2C_VIP_SEQ_BAD", $sformatf("Not a uvm_sequence: %s", seq_name))
  end
  seq_base.start(i2c_vip_slv_sqr0);
`endif
endtask
```

DUT slave mode 需要 VIP master 主动访问，启动 master sequencer：

```systemverilog
task start_i2c_vip_master_sequence(string seq_name);
`ifdef BMS_USE_SVT_VIP
  uvm_object seq_obj;
  uvm_sequence_base seq_base;
  if (i2c_vip_mst_sqr0 == null) begin
    `uvm_fatal("I2C_VIP_SQR_NULL", "i2c_vip_mst_sqr0 is null; cannot start I2C VIP master sequence")
  end
  seq_obj = uvm_factory::get().create_object_by_name(seq_name, get_full_name(), "i2c_vip_master_seq");
  if (seq_obj == null) begin
    `uvm_fatal("I2C_VIP_SEQ_NF", $sformatf("Cannot create I2C VIP sequence: %s", seq_name))
  end
  if (!$cast(seq_base, seq_obj)) begin
    `uvm_fatal("I2C_VIP_SEQ_BAD", $sformatf("Not a uvm_sequence: %s", seq_name))
  end
  seq_base.start(i2c_vip_mst_sqr0);
`endif
endtask
```

## 八、I2C VIP 包装层

### 8.1 `vip_stub_pkg.sv`

`env/vip/vip_stub_pkg.sv` 是本地 VIP 示例代码的统一 include 入口：

```systemverilog
package vip_stub_pkg;
`ifdef BMS_USE_SVT_VIP
  import uvm_pkg::*;
  `include "uvm_macros.svh"
  import svt_uvm_pkg::*;
  import svt_mem_uvm_pkg::*;
  import svt_axi_uvm_pkg::*;
  import svt_ahb_uvm_pkg::*;
  import svt_apb_uvm_pkg::*;
  import svt_i2c_uvm_pkg::*;
  import svt_i2c_enum_pkg::*;

  `include "axi_vip/env/axi_basic_env.sv"
  `include "ahb_vip/env/ahb_ral_env.sv"
  `include "apb_vip/env/cust_svt_apb_master_transaction.sv"
  `include "apb_vip/env/apb_basic_env.sv"
  `include "apb_vip/env/apb_master_directed_sequence.sv"

  `include "i2c_vip/env/i2c_mst_dut_slave_smoke_sequence.sv"
  `include "i2c_vip/env/cust_svt_i2c_slave_transaction.sv"
  `include "i2c_vip/env/cust_svt_i2c_system_configuration.sv"
  `include "i2c_vip/env/i2c_vip_reg_model.sv"
  `include "i2c_vip/env/i2c_vip_basic_env.sv"
  `include "i2c_vip/env/i2c_default_slv_sequence.sv"
  `include "i2c_vip/env/i2c_slave_user_conf_sequence.sv"
  `include "i2c_vip/env/i2c_slv_directed_sequence.sv"
  `include "i2c_vip/env/i2c_slv_nack_sequence.sv"
  `include "i2c_vip/env/i2c_slv_nack_address_sequence.sv"
  `include "i2c_vip/env/i2c_slv_nack_data_sequence.sv"
  `include "i2c_vip/env/i2c_slv_random_sequence.sv"
`endif
endpackage
```

这个 package 的作用不是自创 VIP，而是把从 SVT examples 裁剪来的 env、sequence、transaction、configuration 集成到本地编译环境。

### 8.2 I2C VIP env

`i2c_vip_basic_env` 包装 `svt_i2c_system_env`：

```systemverilog
class i2c_vip_basic_env extends uvm_env;
  `uvm_component_utils(i2c_vip_basic_env)

  svt_i2c_system_env i2c_system_env;
  cust_svt_i2c_system_configuration i2c_system_cfg;
  svt_i2c_vif vif;
  i2c_vip_reg_model reg_model;
```

它在 build_phase 中拿配置和 vif：

```systemverilog
if (!uvm_config_db#(cust_svt_i2c_system_configuration)::get(this, "", "i2c_system_cfg", i2c_system_cfg) ||
    (i2c_system_cfg == null)) begin
  `uvm_fatal("I2C_VIP_CFG", "i2c_system_cfg is not set")
end

if (uvm_config_db#(svt_i2c_vif)::get(this, "", "vif", vif)) begin
  i2c_system_cfg.set_if(vif);
end else if (i2c_system_cfg.i2c_if == null) begin
  `uvm_fatal("I2C_VIP_VIF", "svt_i2c_vif is not set")
end

uvm_config_db#(svt_i2c_system_configuration)::set(this, "i2c_system_env", "cfg", i2c_system_cfg);
i2c_system_env = svt_i2c_system_env::type_id::create("i2c_system_env", this);
reg_model = i2c_vip_reg_model::type_id::create("reg_model", this);
```

它在 connect_phase 中把 slave monitor 的 transaction 送到寄存器模型：

```systemverilog
i2c_system_env.slave[0].monitor.xact_observed_port.connect(reg_model.slave_obs_export);
```

这条连接是 master smoke 数据验证的关键。

### 8.3 I2C VIP configuration

`cust_svt_i2c_system_configuration` 设置 1 master、1 slave：

```systemverilog
class cust_svt_i2c_system_configuration extends svt_i2c_system_configuration;
  `uvm_object_utils(cust_svt_i2c_system_configuration)

  function new (string str="cust_svt_i2c_system_configuration");
    super.new(str);
    this.num_masters = 1;
    this.num_slaves  = 1;
    this.create_sub_cfgs(this.num_masters, this.num_slaves);

    this.master_cfg[0].is_active = 0;
    this.slave_cfg[0].is_active = 1;
    this.slave_cfg[0].slave_address = 10'h055;
    this.slave_cfg[0].enable_10bit_addr = 0;
    this.slave_cfg[0].slave_type = `SVT_I2C_GENERIC;
    this.slave_cfg[0].enable_cci_8bit = 0;
    this.slave_cfg[0].enable_eeprom_32bit = 0;
    this.enable_chk_for_xz_sda_at_time0 = 1'b0;
    this.enable_chk_for_xz_scl_at_time0 = 1'b0;
  endfunction
endclass
```

默认配置是 DUT master、VIP slave。`i2c_base_test` 会根据 `+I2C_DUT_MODE=slave` 改成 VIP master active。

## 九、DUT master smoke 测试设计

### 9.1 基础 sequence

`i2c_basic_sequence` 继承 `base_virt_seq`：

```systemverilog
class i2c_basic_sequence extends base_virt_seq;
  `uvm_object_utils(i2c_basic_sequence)
```

它声明了一组 DUT 寄存器偏移：

```systemverilog
localparam bit [31:0] IC_CON            = 32'h000;
localparam bit [31:0] IC_TAR            = 32'h004;
localparam bit [31:0] IC_DATA_CMD       = 32'h010;
localparam bit [31:0] IC_SS_SCL_HCNT    = 32'h014;
localparam bit [31:0] IC_SS_SCL_LCNT    = 32'h018;
localparam bit [31:0] IC_FS_SCL_HCNT    = 32'h01c;
localparam bit [31:0] IC_FS_SCL_LCNT    = 32'h020;
localparam bit [31:0] IC_HS_SCL_HCNT    = 32'h024;
localparam bit [31:0] IC_HS_SCL_LCNT    = 32'h028;
localparam bit [31:0] IC_RAW_INTR_STAT  = 32'h034;
localparam bit [31:0] IC_RX_TL          = 32'h038;
localparam bit [31:0] IC_TX_TL          = 32'h03c;
localparam bit [31:0] IC_CLR_INTR       = 32'h040;
localparam bit [31:0] IC_CLR_TX_ABRT    = 32'h054;
localparam bit [31:0] IC_CLR_STOP_DET   = 32'h060;
localparam bit [31:0] IC_ENABLE         = 32'h06c;
localparam bit [31:0] IC_STATUS         = 32'h070;
localparam bit [31:0] IC_TX_ABRT_SOURCE = 32'h080;
localparam bit [31:0] IC_ENABLE_STATUS  = 32'h09c;
```

这些寄存器用于配置 DUT master 模式、设置目标地址、设置 SCL 高低计数、写入 `IC_DATA_CMD`，并检查状态和中断。

### 9.2 payload 和约束

```systemverilog
rand bit [9:0]  i2c_target_addr = 10'h055;
rand byte unsigned write_data[$];
rand byte unsigned expected_read_data[$];
string i2c_speed_mode = "standard";
int unsigned i2c_timeout_scale = 4;
int unsigned i2c_start_delay_cycles = 100;

constraint basic_payload_c {
  write_data.size() == 4;
  expected_read_data.size() == 3;
  foreach (write_data[i]) write_data[i] inside {[8'h00:8'hff]};
}
```

默认写入数据是：

```systemverilog
write_data = '{8'h12, 8'h34, 8'ha5, 8'h5a};
expected_read_data = '{8'h34, 8'ha5, 8'h5a};
```

这里的语义是：`0x12` 作为 VIP 寄存器模型的寄存器地址，后面的 `0x34,0xa5,0x5a` 是写入数据。后续读操作希望从 `0x12` 开始读回这 3 个数据。

### 9.3 body 流程

```systemverilog
virtual task body();
  wait_reset_done();
  configure_from_plusargs();
  set_i2c_speed_mode(i2c_speed_mode);

`ifdef BMS_USE_SVT_VIP
  fork
    start_i2c_vip_slave_sequence("i2c_slv_directed_sequence");
  join_none

  i2c_dut_init_controller();
  i2c_dut_write_bytes(write_data);
  i2c_dut_read_and_check(expected_read_data);
  i2c_dut_check_no_abort();
  wait_i2c_observation_window(100);
`else
  `uvm_fatal("I2C_SVT_REQUIRED", "DUT register smoke requires BMS_USE_SVT_VIP APB/I2C VIP sequences")
`endif
endtask
```

这段可以拆成五步理解：

1. 等待复位完成。
2. 读取 plusarg，例如 `I2C_TARGET_ADDR`、`I2C_SPEED_MODE`。
3. 配置 TB 侧 `ic_clk` 速度。
4. 后台启动 I2C VIP slave sequence，准备响应 DUT master。
5. 通过 APB VIP 配置 DUT，然后写数据、读数据、比较数据。

### 9.4 配置 DUT controller

```systemverilog
virtual task i2c_dut_init_controller();
  bit [31:0] con;

  apb_vip_write32(IC_ENABLE, 32'h0);
  poll_reg_bit(IC_ENABLE_STATUS, 0, 1'b0, 2000, "IC_ENABLE_STATUS.IC_EN disable");
  poll_reg_bit(IC_STATUS, 2, 1'b1, 2000, "IC_STATUS.TFE after disable");
  read_clear(IC_CLR_INTR);

  con = build_ic_con_value(i2c_speed_mode);
  apb_vip_write32(IC_CON, con);
  check_reg_value(IC_CON, con, 32'h0000_007f, "IC_CON");
  apb_vip_write32(IC_TAR, {22'h0, i2c_target_addr});
  check_reg_value(IC_TAR, {22'h0, i2c_target_addr}, 32'h0000_03ff, "IC_TAR");
  apb_vip_write32(IC_RX_TL, 32'h0);
  apb_vip_write32(IC_TX_TL, 32'h0);
  program_scl_counts(i2c_speed_mode);

  apb_vip_write32(IC_ENABLE, 32'h1);
  check_reg_value(IC_ENABLE, 32'h1, 32'h0000_0001, "IC_ENABLE");
  poll_reg_bit(IC_ENABLE_STATUS, 0, 1'b1, 2000, "IC_ENABLE_STATUS.IC_EN enable");
endtask
```

这个 task 体现了寄存器配置的基本原则：配置前 disable，确认 idle，清中断，写配置，读回检查，再 enable。

### 9.5 IC_CON 构造

```systemverilog
virtual function bit [31:0] build_ic_con_value(string mode);
  bit [1:0] speed;

  if (mode == "standard") begin
    speed = 2'd1;
  end else if ((mode == "fast") || (mode == "fast_plus")) begin
    speed = 2'd2;
  end else if (mode == "high") begin
    speed = 2'd3;
  end else begin
    speed = 2'd1;
  end

  return (32'h1 << 0) | ({30'h0, speed} << 1) | (32'h1 << 5) | (32'h1 << 6);
endfunction
```

按照当前 sequence 的使用方式：

1. bit0 `MASTER_MODE` 置 1。
2. bit[2:1] 写入 speed。
3. bit5 `RESTART_EN` 置 1。
4. bit6 `IC_SLAVE_DISABLE` 置 1。

寄存器字段含义来自当前 sequence 的写法和打印语义；如果 DUT 官方文档未提供，则不能额外推断更多位定义。

### 9.6 SCL 计数配置

```systemverilog
virtual task program_scl_counts(string mode);
  if (mode == "standard") begin
    apb_vip_write32(IC_SS_SCL_HCNT, 32'd400);
    apb_vip_write32(IC_SS_SCL_LCNT, 32'd470);
  end else if ((mode == "fast") || (mode == "fast_plus")) begin
    apb_vip_write32(IC_FS_SCL_HCNT, 32'd60);
    apb_vip_write32(IC_FS_SCL_LCNT, 32'd130);
  end else if (mode == "high") begin
    apb_vip_write32(IC_HS_SCL_HCNT, 32'd8);
    apb_vip_write32(IC_HS_SCL_LCNT, 32'd16);
  end
endtask
```

这和 `base_virt_seq::set_i2c_speed_mode()` 是两套配置：

1. `set_i2c_speed_mode()` 控制 TB/DUT 输入时钟 `ic_clk` 的半周期。
2. `program_scl_counts()` 控制 DUT 内部 I2C SCL 发生器的高低计数。

### 9.7 数据写入

```systemverilog
virtual task i2c_dut_write_bytes(input byte unsigned data_q[$]);
  foreach (data_q[i]) begin
    bit [31:0] cmd;
    poll_reg_bit(IC_STATUS, 1, 1'b1, 2000, "IC_STATUS.TFNF before write");
    cmd = {21'h0, 1'b0, (i == data_q.size() - 1), 1'b0, data_q[i]};
    apb_vip_write32(IC_DATA_CMD, cmd);
  end
  wait_transfer_done("write", data_q.size());
endtask
```

这里每写一个 byte 前先等 `IC_STATUS.TFNF`，说明 TX FIFO 未满。最后一个 byte 会设置 stop 位。具体 bit 拼接含义以当前源码为准。

### 9.8 数据读回和比较

```systemverilog
virtual task i2c_dut_read_and_check(input byte unsigned exp_q[$]);
  foreach (exp_q[i]) begin
    bit [31:0] cmd;
    bit [31:0] actual;

    poll_reg_bit(IC_STATUS, 1, 1'b1, 2000, "IC_STATUS.TFNF before read command");
    cmd = {21'h0, (i == 0), (i == exp_q.size() - 1), 1'b1, 8'h00};
    apb_vip_write32(IC_DATA_CMD, cmd);
    wait_rx_data_or_intr(i2c_timeout_ic_cycles(2),
                         $sformatf("read[%0d] IC_STATUS.RFNE before reading IC_DATA_CMD", i));
    apb_vip_read32(IC_DATA_CMD, actual);
    if (actual[7:0] !== exp_q[i]) begin
      `uvm_error("I2C_DATA_MISMATCH", $sformatf("read[%0d] expected=0x%02h actual=0x%02h raw=0x%08h", i, exp_q[i], actual[7:0], actual))
    end else begin
      `uvm_info("I2C_DATA_CHECK", $sformatf("read[%0d] matched 0x%02h", i, actual[7:0]), UVM_LOW)
    end
  end
  wait_transfer_done("read", exp_q.size() + 1);
endtask
```

这是 smoke case 的主要检查点。它不是只看 I2C 总线有没有波形，而是通过 DUT RX FIFO 读回数据并逐 byte 比较。

### 9.9 超时按 I2C 速率计算

```systemverilog
virtual function int unsigned scl_period_ic_clk_cycles(string mode);
  if (mode == "standard") begin
    return 400 + 470;
  end else if ((mode == "fast") || (mode == "fast_plus")) begin
    return 60 + 130;
  end else if (mode == "high") begin
    return 8 + 16;
  end
  return 400 + 470;
endfunction

virtual function int unsigned i2c_timeout_ic_cycles(int unsigned transfer_bytes);
  int unsigned bits_on_bus;
  int unsigned scl_cycles;
  int unsigned timeout_cycles;

  bits_on_bus = (transfer_bytes * 9) + 4;
  scl_cycles = bits_on_bus * scl_period_ic_clk_cycles(i2c_speed_mode);
  timeout_cycles = scl_cycles * i2c_timeout_scale;

  if (timeout_cycles < 2000) begin
    timeout_cycles = 2000;
  end
  return timeout_cycles;
endfunction
```

这里的思路是：一次 I2C byte 包含 8 bit 数据加 1 bit ACK，所以用 `transfer_bytes * 9` 估算总线 bit 数，再乘以当前 mode 的 SCL 周期，得到按 `ic_clk` 计数的 timeout。这样 standard、fast、high speed 的等待尺度不会混用。

## 十、VIP 寄存器模型和数据验证

`i2c_vip_reg_model` 是当前 DUT master 写后读验证的关键组件。它连接在 I2C VIP slave monitor 上，观察 DUT 发出的 I2C write transaction。

核心变量：

```systemverilog
static byte unsigned reg_mem[256];
static bit           reg_valid[256];
static byte unsigned read_ptr;
static bit           write_seen;
```

当 VIP slave monitor 观察到写事务时：

```systemverilog
virtual function void write_i2c_vip_reg_slave(svt_i2c_slave_transaction tr);
  if (tr == null) begin
    return;
  end

  if (tr.cmd == I2C_WRITE) begin
    update_from_write(tr);
  end
endfunction
```

写事务的第一个 byte 被当作 register address，后续 byte 写入 `reg_mem`：

```systemverilog
static function void update_from_write(svt_i2c_slave_transaction tr);
  byte unsigned reg_addr;

  if ((tr == null) || (tr.data.size() == 0)) begin
    return;
  end

  reg_addr = tr.data[0];
  read_ptr = reg_addr;
  write_seen = 1'b1;

  if (tr.data.size() == 1) begin
    uvm_root::get().uvm_report_info("I2C_VIP_REG_PTR",
                                    $sformatf("set read_ptr=0x%02h by address-only write", read_ptr),
                                    UVM_LOW, `__FILE__, `__LINE__);
    return;
  end

  for (int i = 1; i < tr.data.size(); i++) begin
    byte unsigned wr_addr;

    wr_addr = byte'(reg_addr + i - 1);
    reg_mem[wr_addr] = tr.data[i];
    reg_valid[wr_addr] = 1'b1;
  end
endfunction
```

读返回数据由 `read_next()` 提供：

```systemverilog
static function byte unsigned read_next();
  byte unsigned data;

  data = reg_valid[read_ptr] ? reg_mem[read_ptr] : 8'h00;
  read_ptr++;
  return data;
endfunction
```

I2C VIP slave directed sequence 会在响应 DUT read 时从这个模型取数据：

```systemverilog
foreach (tx_xacts_s.data[i]) begin
  tx_xacts_s.data[i] = (rsp_idx == 0) ? 8'h00 : i2c_vip_reg_model::read_next();
end
```

因此 smoke 的闭环是：

```text
DUT 通过 APB 写 IC_DATA_CMD
  -> DUT master 在 I2C 总线上写 0x12,0x34,0xa5,0x5a
  -> I2C VIP slave monitor 观察到写事务
  -> i2c_vip_reg_model 保存 reg[0x12]=0x34, reg[0x13]=0xa5, reg[0x14]=0x5a
  -> DUT 通过 APB 下发 I2C read command
  -> I2C VIP slave sequence 从 reg_model 取数返回
  -> DUT RX FIFO 收到数据
  -> sequence 通过 APB 读 IC_DATA_CMD 并比较 expected_read_data
```

这是一种 sequence 侧 scoreboard/check 的设计。当前本地 environment 中未看到独立复杂 scoreboard，数据一致性检查主要由 `i2c_basic_sequence` 和 `i2c_vip_reg_model` 完成。

## 十一、DUT slave smoke 测试设计

`i2c_slave_smoke_seq` 用于验证 DUT 作为 I2C slave/target。

### 11.1 slave mode 寄存器

该 sequence 声明了 slave 模式使用的寄存器：

```systemverilog
localparam bit [31:0] SLV_IC_CON           = 32'h000;
localparam bit [31:0] SLV_IC_TAR           = 32'h004;
localparam bit [31:0] SLV_IC_SAR           = 32'h008;
localparam bit [31:0] SLV_IC_DATA_CMD      = 32'h010;
localparam bit [31:0] SLV_IC_INTR_STAT     = 32'h02c;
localparam bit [31:0] SLV_IC_INTR_MASK     = 32'h030;
localparam bit [31:0] SLV_IC_RAW_INTR_STAT = 32'h034;
localparam bit [31:0] SLV_IC_RX_TL         = 32'h038;
localparam bit [31:0] SLV_IC_TX_TL         = 32'h03c;
localparam bit [31:0] SLV_IC_CLR_INTR      = 32'h040;
localparam bit [31:0] SLV_IC_CLR_RD_REQ    = 32'h050;
localparam bit [31:0] SLV_IC_CLR_STOP_DET  = 32'h060;
localparam bit [31:0] SLV_IC_CLR_START_DET = 32'h064;
localparam bit [31:0] SLV_IC_ENABLE        = 32'h06c;
localparam bit [31:0] SLV_IC_STATUS        = 32'h070;
localparam bit [31:0] SLV_IC_TXFLR         = 32'h074;
localparam bit [31:0] SLV_IC_RXFLR         = 32'h078;
localparam bit [31:0] SLV_IC_SLV_DATA_NACK_ONLY = 32'h084;
localparam bit [31:0] SLV_IC_ENABLE_STATUS = 32'h09c;
localparam bit [31:0] SLV_IC_COMP_PARAM_1  = 32'h0f4;
```

`i2c_target_addr` 默认来自父类，默认值为 `10'h055`，也可由 `+I2C_TARGET_ADDR=55` 设置。`i2c_controller_tar_addr` 默认选择非自身地址，当前 slave smoke `.tc` 中显式传入 `+I2C_CONTROLLER_TAR_ADDR=56`。

### 11.2 body 流程

```systemverilog
virtual task body();
  wait_reset_done();
  configure_from_plusargs();
  set_i2c_speed_mode(i2c_speed_mode);

`ifdef BMS_USE_SVT_VIP
  i2c_dut_init_target();
  fork
    begin
      start_i2c_vip_master_sequence("i2c_mst_dut_slave_write_sequence");
    end
    begin
      i2c_dut_target_receive_and_check(slave_rx_expected);
      wait_target_stop("VIP master write to DUT target",
                       i2c_timeout_ic_cycles(slave_rx_expected.size() + 1));
      read_clear(SLV_IC_CLR_STOP_DET);
    end
  join
  i2c_dut_check_no_abort();

  fork
    begin
      start_i2c_vip_master_sequence("i2c_mst_dut_slave_read_sequence");
    end
    begin
      i2c_dut_target_service_read(slave_tx_payload);
      wait_target_stop("VIP master read from DUT target",
                       i2c_timeout_ic_cycles(slave_tx_payload.size() + 1));
      read_clear(SLV_IC_CLR_STOP_DET);
    end
  join
  i2c_dut_check_no_abort();
`endif
endtask
```

这里的两个 fork/join 很重要：

1. 第一个 fork：VIP master 写 DUT slave，同时 sequence 轮询 DUT RX FIFO 并检查收到的数据。
2. 第二个 fork：VIP master 读 DUT slave，同时 sequence 发现 `RD_REQ` 后往 DUT TX FIFO 填充要返回的数据。

这就是 DUT slave 模式的验证闭环。

### 11.3 配置 DUT target

`build_ic_con_target_value()` 当前写法：

```systemverilog
virtual function bit [31:0] build_ic_con_target_value(string mode);
  bit [1:0] speed;

  if (mode == "standard") begin
    speed = 2'd1;
  end else if ((mode == "fast") || (mode == "fast_plus")) begin
    speed = 2'd2;
  end else if (mode == "high") begin
    speed = 2'd3;
  end else begin
    speed = 2'd1;
  end

  return {31'h0, i2c_target_keep_master} | ({30'h0, speed} << 1) |
         (32'h1 << 5);
endfunction
```

当 `+I2C_TARGET_KEEP_MASTER=0` 时，`MASTER_MODE=0`，sequence 期望 DUT 进入纯 target-only 模式。`i2c_dut_init_target()` 会写：

```systemverilog
apb_vip_write32(SLV_IC_CON, con);
apb_vip_write32(SLV_IC_TAR, {22'h0, i2c_controller_tar_addr});
apb_vip_write32(SLV_IC_SAR, {22'h0, i2c_target_addr});
apb_vip_write32(SLV_IC_RX_TL, 32'h0);
apb_vip_write32(SLV_IC_TX_TL, 32'h0);
apb_vip_write32(SLV_IC_SLV_DATA_NACK_ONLY, 32'h0);
apb_vip_write32(SLV_IC_INTR_MASK, 32'h0);
```

再 enable：

```systemverilog
apb_vip_write32(SLV_IC_ENABLE, SLV_IC_ENABLE_SAR_EN);
apb_vip_write32(SLV_IC_ENABLE, SLV_IC_ENABLE_SAR_EN | SLV_IC_ENABLE_EN);
poll_reg_bit(SLV_IC_ENABLE_STATUS, 0, 1'b1, 2000, "IC_ENABLE_STATUS.IC_EN enable for target mode");
wait_target_external_enable();
```

当前 sequence 会检查 `vif.ic_en` 是否拉高：

```systemverilog
if (!done) begin
  report_target_config("ic_en timeout");
  `uvm_fatal("I2C_TARGET_IC_EN",
             $sformatf("DUT ic_en did not assert after IC_ENABLE_STATUS.IC_EN=1, ic_en=%b", vif.ic_en))
end
```

这对 debug 很重要：寄存器读回显示 enable 不一定代表 top-level pad 控制已经进入可响应状态，所以 sequence 同时检查 `vif.ic_en`。

### 11.4 slave mode 观测打印

`report_target_activity()` 会打印关键状态：

```systemverilog
`uvm_info("I2C_TARGET_ACTIVITY",
          $sformatf("%s STATUS.ACTIVITY=%0b MST_ACTIVITY=%0b SLV_ACTIVITY=%0b RFNE=%0b TFE=%0b TFNF=%0b RAW.SLV_ADDR1_TAG=%0b WR_REQ=%0b START_DET=%0b STOP_DET=%0b RX_DONE=%0b TX_ABRT=%0b RD_REQ=%0b RX_FULL=%0b ic_intr=%b sda_oe=%b scl_oe=%b",
                    tag, status[0], status[5], status[6], status[3],
                    status[2], status[1], raw_intr[16], raw_intr[15],
                    raw_intr[10], raw_intr[9], raw_intr[7], raw_intr[6],
                    raw_intr[5], raw_intr[2], vif.ic_intr,
                    vif.ic_data_oe, vif.ic_clk_oe),
          verbosity)
```

如果从波形看 DUT 内部 `slave_addressed` 拉高，但总线没有 ACK，应该重点结合这些信号判断：

```text
i2c_tb.i2c_vif.SCL/SDA         I2C VIP 看到的真实总线
tb_if.ic_clk_in_a/data_in_a    DUT pad 输入
tb_if.ic_clk_oe/data_oe        DUT pad 输出使能
i2c_dut_scl_drive_low          TB 根据 DUT OE 推导的 SCL 拉低
i2c_dut_sda_drive_low          TB 根据 DUT OE 推导的 SDA 拉低
tb_if.ic_en                    DUT I2C enable 输出
tb_if.ic_intr                  DUT interrupt 输出
IC_CON                         master/slave/restart/speed 配置
IC_SAR                         slave address
IC_ENABLE                      enable 和 SAR enable
IC_ENABLE_STATUS               enable 状态
IC_RAW_INTR_STAT               START/STOP/RD_REQ/TX_ABRT 等原始中断
IC_STATUS                      ACTIVITY/RFNE/TFE/TFNF 等状态
```

## 十二、约束、随机化和 randomize failed 风险

### 12.1 基础约束

`i2c_basic_sequence` 的 `basic_payload_c` 固定了默认 payload 形状：

```systemverilog
constraint basic_payload_c {
  write_data.size() == 4;
  expected_read_data.size() == 3;
  foreach (write_data[i]) write_data[i] inside {[8'h00:8'hff]};
}
```

这让 smoke case 非随机、稳定、易 debug。

### 12.2 随机寄存器 case

`i2c_random_reg_seq` 覆盖基础约束：

```systemverilog
class i2c_random_reg_seq extends i2c_basic_sequence;
  `uvm_object_utils(i2c_random_reg_seq)

  constraint random_reg_payload_c {
    write_data.size() inside {[2:8]};
    expected_read_data.size() == write_data.size() - 1;
  }
```

在 `body()` 中先关掉基础约束，再 randomize：

```systemverilog
task body();
  basic_payload_c.constraint_mode(0);
  expected_read_data.delete();
  if (!randomize()) begin
    `uvm_fatal("I2C_RANDOMIZE_FAILED", "i2c_random_reg_seq randomize failed")
  end
  expected_read_data.delete();
  for (int i = 1; i < write_data.size(); i++) begin
    expected_read_data.push_back(write_data[i]);
  end
  super.body();
endtask
```

这里有一个重要学习点：如果不关闭 `basic_payload_c`，它会强制 `write_data.size()==4`，随机 case 的 `[2:8]` 仍可能合法但随机空间被限制。如果以后新增约束与父类约束冲突，就会出现 `randomize failed`。所以扩展 sequence 时要明确哪些父类约束保留，哪些需要 `constraint_mode(0)`。

### 12.3 VIP master transaction 的 directed randomize

DUT slave mode 使用 SVT I2C master transaction。为了让事务完全受控，`i2c_mst_dut_slave_base_sequence` 会关闭一些 VIP transaction 内建合理性约束：

```systemverilog
virtual function void relax_directed_constraints(svt_i2c_master_transaction req);
  req.reasonable_data.constraint_mode(0);
  req.reasonable_addr.constraint_mode(0);
  req.reasonable_send_start_byte.constraint_mode(0);
  req.reasonable_addr_10bit.constraint_mode(0);
  req.reasonable_arbitrate.constraint_mode(0);
  req.reasonable_abort_if_arb_lost.constraint_mode(0);
  req.reasonable_sr_or_p_gen.constraint_mode(0);
  req.reasonable_retry_if_nack.constraint_mode(0);
endfunction
```

然后用 inline constraint 指定 I2C write：

```systemverilog
if (!req.randomize() with {
  req.cmd == I2C_WRITE;
  req.addr == local::vip_target_addr;
  req.addr_10bit == 0;
  req.data.size() == local::payload_size;
  req.sr_or_p_gen == 0;
  req.send_start_byte == 0;
  req.arbitrate == 0;
  req.abort_if_arb_lost == 0;
  req.retry_if_nack == 0;
  req.do_insert_error == 0;
}) begin
  `uvm_fatal("I2C_MST_RAND", "Failed to randomize DUT-slave write transaction")
end
```

这里的学习点是：VIP transaction 自带很多约束。如果你要做 directed case，最好明确关闭不需要的约束，再用 inline constraint 指定目标事务，否则容易出现随机失败或生成不符合 case 目的的事务。

## 十三、当前 case 集合

所有 case 当前都直接位于 `test_lib/i2c/<case>/` 下。

| case | tc 文件 | sequence | 目的 |
|---|---|---|---|
| smoke | `test_lib/i2c/smoke/smoke.tc` | `i2c_smoke_seq` | DUT master standard mode，写后读闭环 |
| basic | `test_lib/i2c/basic/basic.tc` | `i2c_basic_sequence` | 与 smoke 类似，作为 basic bucket |
| speed_fast | `test_lib/i2c/speed_fast/speed_fast.tc` | `i2c_speed_fast_seq` | DUT master fast mode |
| speed_high | `test_lib/i2c/speed_high/speed_high.tc` | `i2c_speed_high_seq` | DUT master high speed mode |
| boundary | `test_lib/i2c/boundary/boundary.tc` | `i2c_boundary_seq` | VIP reg model 地址边界 |
| reg_boundary | `test_lib/i2c/reg_boundary/reg_boundary.tc` | `i2c_reg_boundary_seq` | 显式 register boundary feature case |
| random | `test_lib/i2c/random/random.tc` | `i2c_random_seq` | 随机 payload 写后读 |
| random_reg | `test_lib/i2c/random_reg/random_reg.tc` | `i2c_random_reg_seq` | fast mode 随机寄存器写后读 |
| error | `test_lib/i2c/error/error.tc` | `i2c_error_seq` | address NACK 后检查 TX_ABRT |
| data_nack | `test_lib/i2c/data_nack/data_nack.tc` | `i2c_data_nack_seq` | data NACK 后检查 TX_ABRT |
| slave_smoke | `test_lib/i2c/slave_smoke/slave_smoke.tc` | `i2c_slave_smoke_seq` | DUT slave mode，VIP master 写/读 DUT |

### 13.1 speed case

`i2c_speed_fast_seq` 只覆盖构造函数中的默认数据和 mode：

```systemverilog
class i2c_speed_fast_seq extends i2c_basic_sequence;
  `uvm_object_utils(i2c_speed_fast_seq)

  function new(string name = "i2c_speed_fast_seq");
    super.new(name);
    i2c_speed_mode = "fast";
    write_data = '{8'h22, 8'hc3, 8'h3c, 8'h5e};
    expected_read_data = '{8'hc3, 8'h3c, 8'h5e};
  endfunction
endclass
```

`i2c_speed_high_seq` 增大 timeout scale：

```systemverilog
class i2c_speed_high_seq extends i2c_basic_sequence;
  `uvm_object_utils(i2c_speed_high_seq)

  function new(string name = "i2c_speed_high_seq");
    super.new(name);
    i2c_speed_mode = "high";
    write_data = '{8'h33, 8'h96, 8'h69, 8'hf0};
    expected_read_data = '{8'h96, 8'h69, 8'hf0};
    i2c_timeout_scale = 8;
  endfunction
endclass
```

这说明如果一个新 case 只是改数据或速率，可以只继承 `i2c_basic_sequence` 并覆盖构造函数，不必复制完整 body。

### 13.2 boundary case

`i2c_reg_boundary_seq` 复用父类 task，测试 `0x00` 和 `0xff`：

```systemverilog
wr0 = '{8'h00, 8'h11, 8'h22};
rd0 = '{8'h11, 8'h22};
wrff = '{8'hff, 8'hee};
rdff = '{8'hee};

i2c_dut_init_controller();
i2c_dut_write_bytes(wr0);
i2c_dut_read_and_check(rd0);
i2c_dut_write_bytes(wrff);
i2c_dut_read_and_check(rdff);
i2c_dut_check_no_abort();
```

### 13.3 error case

`i2c_addr_nack_seq` 启动 `i2c_slv_nack_sequence`：

```systemverilog
fork
  start_i2c_vip_slave_sequence("i2c_slv_nack_sequence");
join_none

i2c_dut_init_controller();
i2c_dut_write_bytes_expect_abort(write_data, "address NACK feature case");
```

`i2c_data_nack_seq` 启动 `i2c_slv_nack_data_sequence`：

```systemverilog
fork
  start_i2c_vip_slave_sequence("i2c_slv_nack_data_sequence");
join_none

i2c_dut_init_controller();
i2c_dut_write_bytes_expect_abort(write_data, "data NACK feature case");
```

这两个 case 的目标不是读回数据一致，而是验证 DUT 在 NACK 后能产生 `TX_ABRT`。

## 十四、checker、coverage 和可观测性

### 14.1 SVA checker

当前工程中有基础 bind checker：

```systemverilog
module i2c_bind_if_checker (
  input logic pclk,
  input logic presetn,
  input logic ic_clk,
  input logic ic_rst_n,
  input logic ic_intr,
  input logic ic_en
);
  property p_i2c_status_known;
    @(posedge ic_clk) ic_rst_n |-> !$isunknown({ic_intr, ic_en});
  endproperty

  property p_apb_reset_known;
    @(posedge pclk) !$isunknown(presetn);
  endproperty

  a_i2c_status_known: assert property (p_i2c_status_known);
  a_apb_reset_known: assert property (p_apb_reset_known);
endmodule
```

bind 到 DUT：

```systemverilog
bind MCU_I2C_WRAPPER i2c_bind_if_checker u_i2c_bind_if_checker (
  .pclk(pclk),
  .presetn(presetn),
  .ic_clk(ic_clk),
  .ic_rst_n(ic_rst_n),
  .ic_intr(ic_intr),
  .ic_en(ic_en)
);
```

当前 checker 关注基础 unknown 检查。源码中未看到更复杂的协议断言或专用 functional coverage covergroup。

### 14.2 覆盖率

当前源码中未看到自定义 `covergroup`。可观测覆盖主要来自：

1. VCS 编译/仿真覆盖开关，具体是否打开取决于运行 cfg。
2. UVM log 中的检查点，例如 `I2C_DATA_CHECK`、`I2C_TARGET_RX_CHECK`、`I2C_EXPECTED_ABORT`。
3. I2C VIP 内部自带 monitor/checker/coverage，具体 coverage 内容由 SVT VIP 文档和配置决定，本工程源码未展开定义。

如果要补 functional coverage，建议先补在 sequence 侧或轻量 subscriber 中，例如覆盖：

```text
I2C speed mode: standard/fast/high
target address: 0x55、边界地址、随机地址
transfer direction: write/read
payload length: 1、2、3、4、随机 2 到 8
error type: addr NACK、data NACK、TX_ABRT
DUT role: master、slave
```

## 十五、log 和波形 debug 方法

### 15.1 判断 VIP 是否接收到 DUT master 请求

DUT master smoke 下，重点看这些 log：

```text
I2C_VIP_CFG
I2C_SLV_RSP
I2C_VIP_REG_OBS
I2C_VIP_REG_WRITE
I2C_VIP_REG_READ
I2C_DATA_CHECK
I2C_TX_ABRT
TB_I2C_ADDR_TRACE
```

如果看到 `I2C_VIP_REG_OBS`，说明 I2C VIP slave monitor 已经观察到 transaction。若随后看到 `I2C_VIP_REG_WRITE reg[0x..] <= 0x..`，说明 VIP reg model 已经把 DUT 写入的数据记录下来。

如果 `I2C_DATA_CHECK` mismatch，常见原因是：

1. 写事务的第一个 byte 被当成 register pointer，不是普通 payload。
2. DUT read 之前没有正确设置 read pointer。
3. I2C VIP read response 比 DUT 读命令早或晚。
4. `+I2C_VIP_WAIT_FIRST_WRITE` 未打开，VIP 在写入发生前就开始供读数据。
5. DUT 的 RX FIFO 读出顺序或 stop/restart 行为与预期不同。

### 15.2 判断 DUT slave 是否 ACK

DUT slave mode 下，要同时看 log 和波形：

```text
I2C_TARGET_CFG
I2C_TARGET_MODE_ON
I2C_TARGET_ACTIVITY
I2C_TARGET_RX_POLL
I2C_VIP_MASTER_RSP
TB_I2C_ADDR_TRACE
```

波形建议观察：

```text
i2c_tb.i2c_vif.SCL
i2c_tb.i2c_vif.SDA
i2c_tb.tb_if.ic_clk_in_a
i2c_tb.tb_if.ic_data_in_a
i2c_tb.tb_if.ic_clk_oe
i2c_tb.tb_if.ic_data_oe
i2c_tb.tb_if.ic_en
i2c_tb.tb_if.ic_intr
i2c_tb.i2c_dut_scl_drive_low
i2c_tb.i2c_dut_sda_drive_low
```

如果 DUT 内部已经识别地址，但 `i2c_vif.SDA` 在 ACK bit 仍为高，说明 DUT 没有通过 pad/OE 真正拉低 SDA。此时应优先检查：

1. `IC_CON.MASTER_MODE` 是否符合 slave mode 预期。
2. `IC_CON.IC_SLAVE_DISABLE` 是否为 0。
3. `IC_SAR` 是否等于 VIP master 访问地址。
4. `IC_ENABLE` 和 `IC_ENABLE_STATUS` 是否有效。
5. `ic_en` 是否在 VIP 发起访问前已经有效。
6. `ic_data_oe` 的极性是否被 TB 正确学习或通过 `+I2C_OE_ACTIVE_LOW` 指定。
7. DUT 是否需要 `IC_ENABLE[19]` 这类 SAR enable 位。

## 十六、如何新增一个测试用例

新增测试时建议沿用当前工程已经验证过的组织方式。这里不虚构新的 class 名，而是用真实存在的 `i2c_speed_fast_seq` 和 `i2c_reg_boundary_seq` 说明两类扩展方法。

1. 在 `seq_lib/i2c_seq/` 下新增与实际 case 对应的 sequence 文件。
2. 让它继承 `i2c_basic_sequence` 或 `base_virt_seq`。
3. 如果只是改数据、速度、timeout，继承 `i2c_basic_sequence` 并覆盖构造函数。
4. 如果要改完整流程，重写 `body()`，但复用父类 task，例如 `i2c_dut_init_controller()`、`i2c_dut_write_bytes()`、`i2c_dut_read_and_check()`。
5. 在 `seq_lib/i2c_seq/i2c_seq_pkg.sv` 增加 include。
6. 在 `test_lib/i2c/<case>/<case>.tc` 中设置真实 sequence 名。

如果只修改数据和速率，可以参考真实存在的 `i2c_speed_fast_seq`：

```systemverilog
class i2c_speed_fast_seq extends i2c_basic_sequence;
  `uvm_object_utils(i2c_speed_fast_seq)

  function new(string name = "i2c_speed_fast_seq");
    super.new(name);
    i2c_speed_mode = "fast";
    write_data = '{8'h22, 8'hc3, 8'h3c, 8'h5e};
    expected_read_data = '{8'hc3, 8'h3c, 8'h5e};
  endfunction
endclass
```

如果要改完整流程，可以参考真实存在的 `i2c_reg_boundary_seq`。它重写 `body()`，但仍复用父类公共 task：

```systemverilog
class i2c_reg_boundary_seq extends i2c_basic_sequence;
  `uvm_object_utils(i2c_reg_boundary_seq)

  task body();
    byte unsigned wr0[$];
    byte unsigned rd0[$];
    byte unsigned wrff[$];
    byte unsigned rdff[$];

    wait_reset_done();
    configure_from_plusargs();
    set_i2c_speed_mode(i2c_speed_mode);

`ifdef BMS_USE_SVT_VIP
    fork
      start_i2c_vip_slave_sequence("i2c_slv_directed_sequence");
    join_none

    wr0 = '{8'h00, 8'h11, 8'h22};
    rd0 = '{8'h11, 8'h22};
    wrff = '{8'hff, 8'hee};
    rdff = '{8'hee};

    i2c_dut_init_controller();
    i2c_dut_write_bytes(wr0);
    i2c_dut_read_and_check(rd0);
    i2c_dut_write_bytes(wrff);
    i2c_dut_read_and_check(rdff);
    i2c_dut_check_no_abort();
`else
    `uvm_fatal("I2C_SVT_REQUIRED", "Register boundary test requires BMS_USE_SVT_VIP")
`endif
  endtask
endclass
```

注意：新增 case 时不要凭空假设 DUT 不存在的配置。应该先从 DUT RTL、已有寄存器访问 sequence、波形和已有 case 中确认可验证行为，再决定新增 sequence 的字段、约束和检查点。

## 十七、学习总结

当前 `i2c_tb` 的 UVM 结构可以用一句话概括：

```text
top 负责硬件连接，base_test 负责环境和 VIP 配置，smoke_test 负责按 +SEQ 选择 sequence，base_virt_seq 负责公共操作，具体 i2c_seq 负责 DUT 行为和检查。
```

这套结构对学习 UVM 很有价值，因为它把各层职责分得比较清楚：

1. `i2c_tb.sv` 不写复杂测试，只做例化、连接、config_db 和 `run_test()`。
2. `i2c_base_test` 不写具体 case，只做 env/VIP 构建和配置。
3. `i2c_smoke_test` 不关心具体 I2C 流程，只根据 `+SEQ` 启动对应 sequence。
4. `base_virt_seq` 提供公共能力，比如 reset、APB 读写、I2C VIP sequence 启动、timeout 计算。
5. `i2c_basic_sequence` 和派生 sequence 负责真实测试意图。
6. 数据验证不是凭波形主观判断，而是通过 VIP reg model 和 APB 读回进行 byte-level check。

如果后续要增强环境，优先考虑三个方向：

1. 为 `i2c_monitor.ap` 增加 subscriber 或 scoreboard，沉淀更多自动检查。
2. 增加 functional coverage，覆盖 speed、方向、长度、错误类型、DUT role。
3. 将 DUT 寄存器表整理成统一 RAL model，让 APB VIP 访问从 raw address 逐步过渡到 register abstraction。
