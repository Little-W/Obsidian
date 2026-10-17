# FLP / LPC：低功耗连通性形式验证完整指南

> **源码内嵌版。** 本章的完整案例以“保存为”标明文件路径，并在下方直接列出全文。代码框不带显示行号，可直接复制；`案例工程/` 只表示目录结构，不要求另找源码附件。包含占位符或保护性 `error` 的专用流程另行明确标为模板。

> **第 16 册 · 专用应用**　Formal Low Power / Low Power Connectivity Check。依据 User Guide 第 24 章（第 1040～1065 页）及 Quick Reference Guide 的 Low Power Connectivity Check 部分。

## 1. 核心问题

低功耗 SoC 通过不同电源域、电源关断、隔离单元、保持寄存器和电源控制器降低功耗。在普通 RTL 连通性检查中，信号可能看起来已经正确相连，但电源域关断后仍可能把未知或无效数据送到始终通电的逻辑；隔离控制接反，可能导致不同电源状态下的功能不符合规格。

FLP CC 将 RTL 与 UPF（Unified Power Format，IEEE 1801）电源意图结合，验证在相应电源状态及使能条件下，指定源与目的的连通性规则是否成立。它不只是检查 UPF 文件能否成功解析，还要分析电源意图对 RTL 的功能影响。

![低功耗域和隔离输出](插图/14_FLP电源域.svg)

## 2. 重要对象

- **对象：** Power domain

  **解释：** 电源控制范围

  **例子：** 可关断图像处理域

- **对象：** Supply net / set

  **解释：** 电源网络与电压状态

  **例子：**

  ```text
  VDD_CORE
  ```

- **对象：** Isolation

  **解释：** 电源关断时对跨域输出进行限制

  **例子：** 下游锁定为 0

- **对象：** Retention

  **解释：** 保存关断前需要恢复的状态

  **例子：** 睡眠前的配置位

- **对象：** Power state table

  **解释：** 组合描述电源合法状态

  **例子：** 工作、待机、关断

- **对象：** Power controller

  **解释：** 控制电源和隔离时序

  **例子：** 关断前先使能隔离

要求明确：何时隔离、生效电平是什么、钳位值为何、是否需要恢复保存状态。普通 CC 的组合连接模型不足以单独表达所有电源关闭的效果。

## 3. 该版本的工作模式

Quick Reference Guide 的低功耗流程不是直接输入 `set_fml_appmode FLP`，而是：

```tcl
set_fml_appmode CC
fvlp_instrument -type "iso pnm"
set_fml_var fvlp_enable_pst_constraint true
read_file -top lp_top -format sverilog -vcs {-f filelist.f}
read_upf power_intent.upf
create_clock clk -period 100
create_reset rst_n -sense low
```

`fvlp_instrument` 启用低功耗语义插桩，`-type` 可根据设计需要选择 `iso`、`pnm`、`ret` 等，具体支持类型参照 UG 1043 页。插入低功耗支持、读入 RTL/UPF 的顺序需要与安装版本示例一致。`read_upf` 中的路径必须指向该工程真实 UPF 文件。

### 3.1 原生低功耗检查模板完整源码

UPF、电源状态及隔离策略必须来自实际项目。本模板的省略对象属于明确的待配置输入，不是已提供的完整低功耗工程。

**保存为 `案例工程/templates/flp_low_power.tcl`：**

<!-- source-begin: 案例工程/templates/flp_low_power.tcl -->

```tcl
# 低功耗 CC：必须有 RTL、UPF、电源状态表、真正的电源域信号。
# 不支持普通 CC 的 delayed connectivity check（UG 第 1041 页）。
error "此文件是 FLP 教学模板：须先提供 UPF、电源控制与隔离策略"
# set_fml_appmode CC
# fvlp_instrument -type "iso pnm"
# set_fml_var fvlp_enable_pst_constraint true
# read_file -top lp_top -format sverilog -vcs {-f filelist.f}
# read_upf /project/upf/power_intent.upf
# create_clock clk -period 100
# create_reset rst_n -sense low
# add_cc -src ... -dest ... -lpa_type ... ;# 填写真实端点与类型
# check_fv -block
# report_fv -verbose
```

<!-- source-end -->

## 4. 最小系统案例

上游处理单元运行于可关断电源域 `PD_A`，下游控制单元在始终通电的 `PD_AON`。上游输出 `data_o` 经隔离单元到下游 `data_i`。规格：当 `PD_A` 供电正常且隔离关闭时，`data_i` 应等于 `data_o`；当 `PD_A` 关断时，`data_i` 应被钳位为零。

检查分两部分：功能连接和隔离钳位。前者可使用带电源条件的 `add_cc`；后者可使用 `flp_check_clamp_value` 等专门命令。具体命令需提供符合本版本要求的 `-lpa_type`、`-location`、`-clamp_value`、`-enable` 和层级对象。

```tcl
# 仅为表达对象的示意；根据 UPF 名称和命令帮助填写合法类型
# add_cc -src u_a.data_o -dest u_aon.data_i -lpa_type <type>
# flp_check_clamp_value -lpa_type <type> -location <self|parent> \
#    -clamp_value 0 -enable iso_en u_aon.data_i
```

以上包含 `<...>` 的两行是示例占位内容，不得未经替换直接运行。

### 4.1 完整源码：先理解逻辑隔离关系

为了不把 UPF 环境和普通逻辑混在一起，以下单独给出理想隔离控制的 RTL 与 SVA。这里的 `source_power_good` 只是布尔输入，不会使仿真器或形式工具真的把某个电源域关断，也没有建立掉电后的未知值模型。

#### 4.1.1 完整逻辑模型

源电源不正常时，理想控制模型立即使能隔离；真实系统的电源控制时序、跨时钟处理和故障行为必须另行验证。

**保存为 `案例工程/rtl/lp_isolation_demo.sv`：**

<!-- source-begin: 案例工程/rtl/lp_isolation_demo.sv -->

```systemverilog
// 仅表示理想的逻辑隔离关系，不模拟电源关断产生的未知值。
module lp_isolation_demo (
  input  logic       clk, rst_n,
  input  logic       source_power_good, isolation_request,
  input  logic [7:0] source_data,
  output logic       isolation_enable,
  output logic [7:0] destination_data
);
  // 理想控制模型：源电源不正常时强制隔离；真实 PMC 必须另行验证。
  assign isolation_enable = !source_power_good || isolation_request;
  assign destination_data = isolation_enable ? 8'h00 : source_data;
endmodule
```

<!-- source-end -->

#### 4.1.2 完整 SVA



**保存为 `案例工程/formal/lp_isolation_demo_props.sv`：**

<!-- source-begin: 案例工程/formal/lp_isolation_demo_props.sv -->

```systemverilog
module lp_isolation_demo_props (
  input logic clk, rst_n,
  input logic source_power_good, isolation_request, isolation_enable,
  input logic [7:0] source_data, destination_data
);
  ap_isolation_clamp: assert property (@(posedge clk) disable iff (!rst_n)
    isolation_enable |-> destination_data == 8'h00);
  ap_power_off_clamp: assert property (@(posedge clk) disable iff (!rst_n)
    !source_power_good |-> destination_data == 8'h00);
  ap_normal_connection: assert property (@(posedge clk) disable iff (!rst_n)
    source_power_good && !isolation_request
      |-> destination_data == source_data);
  cp_off_on_sequence: cover property (@(posedge clk) disable iff (!rst_n)
    !source_power_good ##1 source_power_good && !isolation_request);
endmodule

bind lp_isolation_demo lp_isolation_demo_props u_lp_props (.*);
```

<!-- source-end -->

#### 4.1.3 文件列表



**保存为 `案例工程/filelist_fpv_lp_logic_demo.f`：**

<!-- source-begin: 案例工程/filelist_fpv_lp_logic_demo.f -->

```text
./rtl/lp_isolation_demo.sv
./formal/lp_isolation_demo_props.sv
```

<!-- source-end -->

#### 4.1.4 普通 FPV 练习脚本



**保存为 `案例工程/scripts/fpv_lp_logic_demo.tcl`：**

<!-- source-begin: 案例工程/scripts/fpv_lp_logic_demo.tcl -->

```tcl
# 从案例工程目录执行；结果必须以本机 VC Formal 日志为准。
set_fml_appmode FPV
read_file -top lp_isolation_demo -sva -format sverilog -vcs {-f filelist_fpv_lp_logic_demo.f}
create_clock clk -period 100
create_reset rst_n -sense low
# 先核验实际复位状态，再保存初始状态。
sim_run -stable
sim_save_reset
check_fv_setup
report_fv -list
check_fv -block
report_fv -verbose
```

<!-- source-end -->

**运行命令（Bash）：**

```bash
# 从包含“案例工程”目录的上一级目录开始。
cd 案例工程
mkdir -p logs
set -o pipefail
vcf -f scripts/fpv_lp_logic_demo.tcl -batch 2>&1 | tee logs/fpv_lp_logic_demo.log
```

这些命令应在本机具备相应 VC Formal 版本和许可证时执行。日志中的属性状态才是证明结论；命令退出、脚本结束或没有打印错误都不能代替属性结果检查。

**与原生 FLP 的区别。** 上述练习说明隔离钳位和正常连接的布尔关系，并不验证 UPF 插入位置、电源网络、保持单元或电源关断行为。真正的 FLP 检查还需要第 3 节列出的 UPF 和工具低功耗配置，不能用本节 FPV 结果替代。

## 5. UPF 可信性与 PMC

UPF 应由电源架构负责人确认电源域划分、电源状态、隔离和保持策略；必要时还需为真实电源管理控制器（PMC）建立环境模型。UG §24.2 提到可为不存在于形式 RTL 的 PMC 建模其外部行为，不能把这种模型误当作 RTL 自身需要被证明的功能。错误地假设所有电源域永久打开，将直接屏蔽很多低功耗缺陷。

## 6. FLP CC 和普通 CC 的重要区别

**User Guide 第 1041 页明确说明：FLP CC 不支持连通性延迟检查。** 因此不能直接把普通 CC 中的 `path_delay` 用例复制到低功耗检查环境。对于寄存器延迟、时序握手或跨时钟的低功耗交互，需要以另一套适当的功能属性或等价流程验证，而非宣称 FLP CC 已证明它们。

## 7. 主要命令与用途

- **命令：**

  ```tcl
  set_fml_appmode CC
  ```

  **用途：** 在 CC 模式启动低功耗检查

- **命令：**

  ```tcl
  fvlp_instrument -type ...
  ```

  **用途：** 启用隔离/电源网络/保持等插桩

- **命令：**

  ```tcl
  read_upf
  ```

  **用途：** 读入电源意图并建立相关模型

- **命令：**

  ```tcl
  get_fvlp_free_supply_nets
  ```

  **用途：** 查询没有充分控制的电源网络

- **命令：**

  ```tcl
  fvlp_set_supply_aon
  ```

  **用途：** 将指定电源声明为始终打开

- **命令：**

  ```tcl
  fvlp_set_supply_onoff_net
  ```

  **用途：** 连接电源控制信号与供电网络

- **命令：**

  ```tcl
  add_cc ... -lpa_type ...
  ```

  **用途：** 定义带低功耗类型的连接规则

- **命令：**

  ```tcl
  flp_check_clamp_value
  ```

  **用途：** 检查预期隔离钳位

- **命令：**

  ```tcl
  flp_cc_vacuity_gen_split
  ```

  **用途：** 辅助分析条件不可满足造成的空洞结果

- **命令：**

  ```tcl
  flp_cc_vacuity_report
  ```

  **用途：** 查看有关空洞报告

- **命令：**

  ```tcl
  fvlp_cc_print_path
  ```

  **用途：** 输出低功耗连接的追踪路径

## 8. 三个需要分别检查的场景

**正常通电：**隔离关闭时功能数据能够到达下游；**关断阶段：**隔离在失去电源前启动、钳位值正确并持续；**恢复阶段：**电源回到合法状态后，对隔离解除、复位和保持恢复的顺序进行验证。第三阶段常涉及跨周期时序，可能需要 FPV 与电源控制器的状态属性配合。

## 9. 调试方法

从失败的低功耗连接属性开始，检查 UPF 的源目的供电网络、`iso_en` 及电源状态，再查看波形或 Power Browser。特别注意电源状态表是否包含不实际的组合、隔离使能是否被形式环境错误固定、以及低功耗插桩是否真正参与了编译。不能仅因为正常供电情况下路径连接正确就结束验证。

## 10. 参考

User Guide §24（1040～1065 页），Quick Reference Guide Low Power Connectivity Checking 部分；涉及 UPF 语法时还应参考项目采用的 IEEE 1801 版本与电源意图开发规范。
