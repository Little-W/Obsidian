# FTA：形式测试平台分析完整指南

> **源码内嵌版。** 本章的完整案例以“保存为”标明文件路径，并在下方直接列出全文。代码框不带显示行号，可直接复制；`案例工程/` 只表示目录结构，不要求另找源码附件。包含占位符或保护性 `error` 的专用流程另行明确标为模板。

> **第 12 册 · 专用应用**　Formal Testbench Analyzer。依据 User Guide 第 21 章（第 914～960 页），Quick Reference Guide FTA 部分，并参照 User Guide 第 20 章的形式验证验收流程。

## 1. FTA 解决的不是 RTL 正确性，而是属性环境的质量

形式验证通常给出很多 `Proven`，但这些证明是否足够覆盖真实设计风险？某个功能错误是否会被当前断言检测到？FTA 使用**故障/RTL 修改（mutation）注入**的方法分析形式测试平台的检错能力。如果注入一个功能变化后仍没有任何断言检测到异常，说明当前检查集合可能存在薄弱位置。它是一项验证质量评估方法，而不是再运行一次普通 FPV。

例如，RTL 中 `grant[0]` 的组合条件被修改。如果已有的互斥属性仍全部通过，但缺少“请求必须得到相应授权”的规则，那么 FTA 可能发现这一类变更不易被现有属性检测。

![FTA 故障注入与属性检出](插图/11_FTA故障.svg)

## 2. 工作过程

1. 在 FPV 模式编译 DUT 和属性，建立正确的时钟、复位与环境前提。
2. 审查现有属性状态，确认值得评估的断言范围，区分断言与覆盖目标。
3. 根据当前软件版本配置可用的故障类型和注入策略。
4. 切换到 FTA，运行激活、传播与检测分析。
5. 汇总可被检出的故障、无法检出的故障以及尚无结论的故障。
6. 对未检测区域补充有意义的设计属性，再运行 FTA 和 FPV 回归。

## 3. 不能直接从 `-fmode FTA` 启动

User Guide 第 65 页明确提醒：该版本通常从 FPV 模式建立工作区，再使用 `set_fml_appmode FTA` 切换，`vcf -fmode FTA` 不属于支持的直接启动方式。快速指南有独立的 `FTA` 命令行，但并不意味着可以跳过准备好的 FPV 环境。

## 4. 示范 Tcl：多阶段流程的轮廓

```tcl
# 第一阶段：FPV 环境和属性分析
set_fml_appmode FPV
read_file -top core -sva -format sverilog -vcs {-f filelist.f}
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
check_fv_setup
check_fv -block
report_fv -list

# 第二阶段：FTA（故障设置根据具体版本和设计调整）
set_fml_appmode FTA
fta_init
configure_fta_props
compute_fta -par_task FPV
fta_report
```

这个脚本描述学习顺序，**不是一个对任何 FTA 许可证和故障模型都立即可运行的完整正式工程**。尤其 `fta_init`、`configure_fta_props` 和 `compute_fta` 的参数需与当前会话的 FPV task、故障数据库及流程类型对应。阅读 User Guide 第 923～941 页完整流程再部署生产项目。

### 4.1 带防误执行保护的完整模板

这里完整展示模板，不要求打开附件。`error` 明确阻止把缺少已验证属性集合或故障配置的脚本当成真实 FTA 分析。

**保存为 `案例工程/templates/fta_mutation.tcl`：**

<!-- source-begin: 案例工程/templates/fta_mutation.tcl -->

```tcl
# FTA：Formal Testbench Analyzer。须基于真实的 FPV 工程与属性集合。
# 不能仅用 vcf -fmode FTA 直接启动，详见 UG §21 和手册 FTA.md。
error "此文件是 FTA 教学模板：请先完成真实 FPV 环境、属性集合和故障策略"
# set_fml_appmode FPV
# read_file -top dut -sva -format sverilog -vcs {-f filelist.f}
# create_clock clk -period 100
# create_reset rst_n -sense low
# sim_run -stable
# sim_save_reset
# check_fv -block
# set_fml_appmode FTA
# fta_init
# configure_fta_props ...     ;# 真实参数必须通过 help 确认
# compute_fta -par_task FPV
# fta_report ...             ;# 依据项目需要设置过滤与实例
```

<!-- source-end -->

## 5. 故障分类与结果含义

- **场景：** 故障被属性检出

  **工程解释：** 当前断言对该类改变敏感

  **后续建议：** 检查检出的属性是否符合预期

- **场景：** 故障未检出

  **工程解释：** 可能是死代码、影响不可达、属性缺失或环境屏蔽

  **后续建议：** 先审查可达性和影响路径

- **场景：** 注入无法激活

  **工程解释：** 故障点在现有环境下不被触发

  **后续建议：** 检查约束及故障定义

- **场景：** 结果未完成

  **工程解释：** 当前证明资源不足

  **后续建议：** 提升策略或缩小任务

- **场景：** 被审查豁免

  **工程解释：** 有外部充分证据认定不需要该项

  **后续建议：** 记录依据并保留原结果

检出率与业务规格覆盖完整程度相关，但不能直接等同于“芯片功能正确的百分比”。

## 6. 关键命令及用途

- **命令：**

  ```tcl
  fta_init
  ```

  **用途：** 初始化 FTA 所需数据结构和分析

- **命令：**

  ```tcl
  configure_fta_props
  ```

  **用途：** 选择待评估的属性集合和条件

- **命令：**

  ```tcl
  compute_fta -par_task FPV
  ```

  **用途：** 基于已准备的 FPV task 开展 FTA 分析

- **命令：**

  ```tcl
  fta_report -instance ...
  ```

  **用途：** 按实例报告 FTA 状态

- **命令：**

  ```tcl
  get_fta_faults
  ```

  **用途：** 查询所考虑的注入故障

- **命令：**

  ```tcl
  get_activated_props
  ```

  **用途：** 对故障查询有激活关系的属性

- **命令：**

  ```tcl
  cluster_fta_faults
  ```

  **用途：** 将故障进行分组以方便分析

- **命令：**

  ```tcl
  report_fta_fault_clusters
  ```

  **用途：** 输出故障分组结果

- **命令：**

  ```tcl
  export_fault
  ```

  **用途：** 导出选中的故障信息

- **命令：**

  ```tcl
  debug_fta
  ```

  **用途：** 启动或准备专用调试

- **命令：**

  ```tcl
  read_fta_waiver
  ```

  **用途：** 导入经过审查的豁免

## 7. 两个评估示例

**例一：FIFO 缺少溢出断言。** 只写了 FIFO 空闲和复位属性，注入“满时仍接受写入”的 RTL 改变，可能不被检出。补充 `occupancy <= DEPTH`、接受写入时机等断言，重新比较检测结果。**例二：状态机错误状态转换。** 只检查状态编码合法性，状态从 `WAIT` 错误跳到 `IDLE` 仍可能保持编码合法，却违反协议。FTA 可以促使增加状态转移规则与完成覆盖。

### 7.1 用完整源码观察断言是否能发现设计变化

下面采用计数器的正确版与错误版进行手工对照，帮助理解“改变设计后，原有属性是否敏感”。这一练习使用 FPV；它不是 FTA 自动生成故障或计算检出率的替代品。为便于单独阅读本章，相关文件再次全文列出。

### 7.1.1 被验证的计数器 RTL

规格：复位后计数为零；使能时从 0 计到 9 后回到 0；没有使能时保持。RTL 文件只包含设计，不把待验证结论写成环境假设。

**保存为 `案例工程/rtl/counter.sv`：**

<!-- source-begin: 案例工程/rtl/counter.sv -->

```systemverilog
module counter (
    input  logic       clk,
    input  logic       rst_n,
    input  logic       enable,
    output logic [3:0] count
);
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n)             count <= 4'd0;
    else if (enable) begin
      if (count == 4'd9)    count <= 4'd0;
      else                  count <= count + 4'd1;
    end
  end
endmodule
```

<!-- source-end -->


### 7.1.2 完整断言与绑定文件

`history_valid` 在复位后建立历史有效标志。`ap_range` 检查范围，`ap_hold` 检查保持，`ap_wrap` 检查回绕；两条 `cover` 检查最高计数值及回绕场景是否能够出现。末尾 `bind` 将检查器接入同名设计信号，不需要修改 RTL。

**保存为 `案例工程/formal/counter_props.sv`：**

<!-- source-begin: 案例工程/formal/counter_props.sv -->

```systemverilog
module counter_props (
    input logic       clk, rst_n, enable,
    input logic [3:0] count
);
  logic history_valid;
  always_ff @(posedge clk or negedge rst_n)
    if (!rst_n) history_valid <= 1'b0;
    else        history_valid <= 1'b1;

  ap_range: assert property (@(posedge clk) disable iff (!rst_n)
      count <= 4'd9);

  ap_hold: assert property (@(posedge clk) disable iff (!rst_n)
      history_valid && $past(!enable) |-> count == $past(count));

  ap_wrap: assert property (@(posedge clk) disable iff (!rst_n)
      history_valid && $past(enable && count == 4'd9)
      |-> count == 4'd0);

  cp_reaches_nine: cover property (@(posedge clk) disable iff (!rst_n)
      count == 4'd9);
  cp_wrap: cover property (@(posedge clk) disable iff (!rst_n)
      count == 4'd9 ##1 count == 4'd0);
endmodule

bind counter counter_props u_counter_props (.*);
```

<!-- source-end -->


### 7.1.3 编译文件列表

先列 RTL，再列包含 `bind` 的属性文件；路径相对于运行 VC Formal 的 `案例工程/` 目录，而不是 Tcl 文件所在目录。

**保存为 `案例工程/filelist_counter.f`：**

<!-- source-begin: 案例工程/filelist_counter.f -->

```text
./rtl/counter.sv
./formal/counter_props.sv
```

<!-- source-end -->


### 7.1.4 完整运行脚本

依次选择应用、读入设计与 SVA、定义时钟复位、保存初始状态、检查设置、列出属性并开始证明。初始化步骤需要在实际安装环境核对复位状态，不能把声明复位等同于已经完成复位。

**保存为 `案例工程/scripts/fpv_counter.tcl`：**

<!-- source-begin: 案例工程/scripts/fpv_counter.tcl -->

```tcl
# Run from the example project root with: vcf -f scripts/fpv_counter.tcl -batch
set_fml_appmode FPV
read_file -top counter -sva -format sverilog -vcs {-f filelist_counter.f}
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
check_fv_setup
report_fv_setup -list
report_fv -list
set_fml_var fml_max_time 1H
set_fml_var fml_max_memory 8GB
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
vcf -f scripts/fpv_counter.tcl -batch 2>&1 | tee logs/fpv_counter.log
```

这些命令应在本机具备相应 VC Formal 版本和许可证时执行。日志中的属性状态才是证明结论；命令退出、脚本结束或没有打印错误都不能代替属性结果检查。

**结果阅读。** 在初始状态正确的前提下，正确版预期满足这些断言，并存在到达 9 和回绕的覆盖轨迹。这不是本次 VC Formal 的实际运行结果。该属性集合也不是全部计数器规格：例如每次普通递增的精确关系仍可另加属性，不能仅凭范围成立就认定全部功能正确。


### 7.1.5 故意错误的 RTL

错误只在回绕阈值：把 9 改为 10。模块名仍为 `counter`，所以此文件与正确版必须分别编译。属性文件沿用本节已经完整列出的 `counter_props.sv`。

**保存为 `案例工程/rtl/counter_bad.sv`：**

<!-- source-begin: 案例工程/rtl/counter_bad.sv -->

```systemverilog
// Intentionally buggy teaching variant: roll-over condition is 10 instead of 9.
// Do NOT include with rtl/counter.sv in the same compilation.
module counter (
    input  logic       clk,
    input  logic       rst_n,
    input  logic       enable,
    output logic [3:0] count
);
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n)             count <= 4'd0;
    else if (enable) begin
      if (count == 4'd10)   count <= 4'd0;
      else                  count <= count + 4'd1;
    end
  end
endmodule
```

<!-- source-end -->


### 7.1.6 错误版编译文件列表

只读入错误设计及同一份检查器，不同时包含两个同名设计。

**保存为 `案例工程/filelist_counter_bad.f`：**

<!-- source-begin: 案例工程/filelist_counter_bad.f -->

```text
./rtl/counter_bad.sv
./formal/counter_props.sv
```

<!-- source-end -->


### 7.1.7 错误版完整运行脚本

与正确版采用相同接口和初始化方法，不为了让错误版通过而增加输入限制。

**保存为 `案例工程/scripts/fpv_counter_bad.tcl`：**

<!-- source-begin: 案例工程/scripts/fpv_counter_bad.tcl -->

```tcl
# Intentionally failing counter example. Do not include the good counter at once.
set_fml_appmode FPV
read_file -top counter -sva -format sverilog -vcs {-f filelist_counter_bad.f}
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
check_fv_setup
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
vcf -f scripts/fpv_counter_bad.tcl -batch 2>&1 | tee logs/fpv_counter_bad.log
```

这些命令应在本机具备相应 VC Formal 版本和许可证时执行。日志中的属性状态才是证明结论；命令退出、脚本结束或没有打印错误都不能代替属性结果检查。

错误版的预期反例是：在允许连续使能的输入下，计数从 9 进入 10，违反范围与回绕规则。查看反例时应区分时钟沿的采样值与非阻塞赋值后的寄存器值；不能把这里描述的预期现象伪装成工具日志。

## 8. FTA 与故障仿真的区别

FTA 使用形式分析寻找能够触发和传播注入差异的逻辑证据；故障仿真通常依赖已准备的激励序列。两者都可用来研究测试平台质量，但对状态空间、收敛条件、故障模型和资源需求的依赖不同。FTA 的故障并不等同于制造测试的 stuck-at / transition ATPG 故障模型。

## 9. 参考

User Guide 第 21 章，尤其多阶段运行、故障注入、结果调试与性能部分；User Guide 第 20 章的最终验证质量评估方法。
