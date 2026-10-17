# FPV：功能属性验证应用完整指南

> **源码内嵌版。** 本章的完整案例以“保存为”标明文件路径，并在下方直接列出全文。代码框不带显示行号，可直接复制；`案例工程/` 只表示目录结构，不要求另找源码附件。包含占位符或保护性 `error` 的专用流程另行明确标为模板。

> **第 5 册 · 专用应用**　Functional Property Verification。依据 User Guide 第 17 章（第 686～713 页），并结合第 3～8、18～20 章及 Quick Reference Guide 的 FPV 部分。本章直接列出设计、断言、文件列表与 Tcl；独立源码文件只作为便于编辑的副本。

## 1. 定位、能力与不适用范围

FPV 通过数学证明验证 RTL 和 SVA 所描述的设计规则。输入包括：待验证 RTL、用户断言、Assertion IP（AIP）断言、环境假设、时钟复位和初始化状态；输出为证明状态、反例、覆盖轨迹和分析报告。它适合局部协议、状态机、控制面、缓冲区、寄存器副作用、异常控制等，可在传统 testbench 完成前投入使用。

FPV 不会自动理解芯片规格，也不自动生成所有应该证明的规则。只有对**已经编写并启用**的属性进行了证明才有相应结论，且环境约束必须可信。若设计缺少软件配置顺序或外部协议模型，可能出现不实际的反例；若过度约束，则可能出现空洞证明。

## 2. 标准流程与输入输出

![FPV 工作流程](插图/06_FPV工作流程.svg)

| 阶段 | 任务 | 命令或文件 | 核查点 |
|---|---|---|---|
| 选择应用 | 设置 FPV | `set_fml_appmode FPV` | 模式是否正确 |
| 编译 | 读入 RTL、属性和 bind 文件 | `read_file` 或 `analyze/elaborate` | 顶层、参数、属性数量 |
| 初始化 | 时钟、复位、常量、初始状态 | `create_clock`、`create_reset`、`sim_save_reset` | 与真实启动一致 |
| 环境审查 | 检查黑盒和模型问题 | `report_blackbox`、`check_fv_setup` | 不存在关键环境缺陷 |
| 运行 | 执行验证 | `check_fv -block` | 任务真正结束 |
| 分析 | 输出证明状态和反例 | `report_fv`、`view_trace` | 性质与前提一致 |
| 回归 | 保存可复现结果 | `save_session`、日志/manifest | 版本与运行资源可追踪 |

## 3. 单时钟计数器：完整 RTL、SVA 与运行流程

本节直接给出全部依赖文件。按“保存为”的路径建立目录并保存代码，就能准备对应教学工程，不必再到附件寻找 RTL、断言或脚本。

### 3.1 被验证的计数器 RTL

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


### 3.2 完整断言与绑定文件

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


### 3.3 编译文件列表

先列 RTL，再列包含 `bind` 的属性文件；路径相对于运行 VC Formal 的 `案例工程/` 目录，而不是 Tcl 文件所在目录。

**保存为 `案例工程/filelist_counter.f`：**

<!-- source-begin: 案例工程/filelist_counter.f -->

```text
./rtl/counter.sv
./formal/counter_props.sv
```

<!-- source-end -->


### 3.4 完整运行脚本

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


### 3.5 故意错误的 RTL

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


### 3.6 错误版编译文件列表

只读入错误设计及同一份检查器，不同时包含两个同名设计。

**保存为 `案例工程/filelist_counter_bad.f`：**

<!-- source-begin: 案例工程/filelist_counter_bad.f -->

```text
./rtl/counter_bad.sv
./formal/counter_props.sv
```

<!-- source-end -->


### 3.7 错误版完整运行脚本

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

## 4. 如何组织断言

建议把每条属性归入四个类别：初始化（复位值和复位后输出）；协议（有效应答、授权、稳定性）；内部安全性（计数范围、状态合法、资源互斥）；进展性（最大等待时间、错误响应）。每个类别不仅包含断言，还要有能触发关键规则的覆盖目标。可将大型属性拆成“输入合法 → 请求被接受 → 内部状态变化 → 输出响应”的小性质，降低定位和求解难度。

### 4.1 它真正验证了什么

```systemverilog
ap_range: assert property (@(posedge clk) disable iff(!rst_n)
  count <= 4'd9);

cp_wrap: cover property (@(posedge clk) disable iff(!rst_n)
  count == 4'd9 ##1 count == 4'd0);
```

`ap_range` 证明占用值不超过上界；`cp_wrap` 搜索一次从 9 到 0 的回绕。两者不能互相替代。若设计从未能到达 9，`ap_range` 仍可能通过，但回绕规则并未真正被验证。对错误 RTL，前者应给出反例，后者是否能够覆盖取决于更新条件。

### 4.2 使用 `bind` 与外部属性模块

推荐把待验证 RTL 与检查器分离，方便调试和提交代码：

```systemverilog
module interface_checker (
  input logic clk, rst_n,
  input logic valid, ready,
  input logic [7:0] data
);
  ap_stable: assert property (@(posedge clk) disable iff(!rst_n)
     valid && !ready |=> valid && $stable(data));
  cp_transfer: cover property (@(posedge clk) disable iff(!rst_n)
     valid && ready);
endmodule
```

在 `formal/bind.sv` 内写 `bind <DUT_type> interface_checker ...`，然后使绑定文件编译进入 `-sva` 的设计。必须确认属性端口与 DUT 的实际时序一致，不要仅凭属性能被编译就认为建模正确。

## 5. 常用 Tcl 命令逐项讲解

| 命令 | 作用 | 使用时机及注意事项 |
|---|---|---|
| `set_fml_appmode FPV` | 选择 FPV | 在编译前执行；可用 `get_fml_appmode` 核对 |
| `read_file -top ... -sva ...` | 编译并展开含断言设计 | 源文件列表和模块顶层必须正确 |
| `analyze ...; elaborate ... -sva` | 将编译与展开拆开 | 不与 `read_file` 任意重复 |
| `aip_load -protocol "AHB AXI5"` | 加载受支持的协议断言 IP | 需要协议适配及正确的 AIP 连接配置 |
| `create_clock` | 定义逻辑时钟 | 多域设计要分别核查 |
| `create_reset` | 定义复位极性 | 必须与实际 RTL 相符 |
| `set_constant` | 将稳定控制输入限制为给定值 | 确保该假设对目标应用合理 |
| `sim_run` / `sim_save_reset` | 建立并保存初始状态 | 应审查复位波形和寄存器值 |
| `check_fv_setup` | 检查形式模型和环境 | 在长时间证明前运行 |
| `fvassert` | 在 Tcl 创建或设定断言属性 | 复杂时序属性推荐 SVA 源文件 |
| `fvassume` | 添加或调整形式假设 | 必须给出规格来源 |
| `fvcover` | 添加覆盖目标 | 应覆盖关键协议触发条件 |
| `fvdisable` / `fvenable` | 关闭 / 启用属性 | 禁用不能隐瞒，需报告 |
| `set_fml_var fml_vacuity_on true` | 配置空洞性分析 | 仍需结合触发覆盖审查 |
| `check_fv -block` | 阻塞执行求解 | 适合批处理脚本 |
| `report_fv -list/-verbose` | 列表和详细报告 | 根据状态区分已证明、失败和未完成 |
| `view_trace -property ...` | 打开特定属性反例 | 对照 SVA 触发周期观察 |
| `save_session -session ...` | 保存工具工作会话 | 保留关联数据库以便恢复 |

`fvassert <name> -expr {<expression>}`、`fvassume <name> -expr {...}` 和 `fvcover <name> -expr {...}` 适合短属性或自动生成规则。Tcl 的 `{}`、`""` 会影响转义与 `$` 替换，例如使用 `$past` 时推荐外层花括号包围语句或直接写到 SV 中。

## 6. 四个逐步进阶的用例

### 用例 A：复位后状态正确

规格：复位退出后，状态机应进入空闲状态。首先明确同步或异步复位和断言采样时刻：

```systemverilog
ap_reset_release: assert property (
  @(posedge clk) $rose(rst_n) |-> state == IDLE);
```

这段规则只适用于状态在第一次采样到复位高电平的时刻应该已经是 `IDLE` 的实现。若模块采用同步释放后的一个周期才进入有效状态，则必须调整响应周期。为复位前提单独建立初始化流程，不能只靠 `disable iff` 回避复位检查。

### 用例 B：握手停止期间数据不变

```systemverilog
ap_stall_hold: assert property (@(posedge clk) disable iff(!rst_n)
  valid && !ready |=> valid && $stable(data));
cp_backpressure: cover property (@(posedge clk) disable iff(!rst_n)
  valid && !ready ##1 ready);
```

如 `ready` 为外部驱动，禁止假设 `ready` 始终为 1；否则背压规则可能很容易被证明，却没有真正触发的测试场景。

### 用例 C：深层计数器溢出

使用参数化深度为 10 的计数器，故意把最大值条件写错。预期安全性 `count <= 9` 会失败；反例提供每拍 `enable`，可从逐周期变化找到第一次非法值。修复后重新运行，与更早的报告比较应以 RTL 的校验值为前提。

### 用例 D：多端口仲裁

```systemverilog
ap_mutex: assert property (@(posedge clk) disable iff(!rst_n)
  $onehot0(grant));
cp_contend: cover property (@(posedge clk) disable iff(!rst_n)
  req == 2'b11);
```

这是最基础的安全性和触发覆盖。若想证明“等待不超过 8 拍”，必须明确持续请求和仲裁器能否接收新请求，并对每一个端口分别写属性。状态空间复杂时，可先证明互斥与请求合法，再证明有界公平性。

### 6.5 FIFO 控制器：完整代码

这个例子只验证 FIFO 的占用计数、空满标志和请求接受规则，不包含存储阵列，因此不能据此宣称已经证明数据顺序正确。满状态允许同时读写；空状态不能读出，且本例没有空 FIFO 直通功能。

#### 6.5.1 控制器 RTL

`pop_accept` 先排除空读；`push_accept` 在未满或本拍成功读出的条件下接受写入。实际更新依据接受信号，而不是原始 `push/pop` 请求。

**保存为 `案例工程/rtl/fifo_ctrl.sv`：**

<!-- source-begin: 案例工程/rtl/fifo_ctrl.sv -->

```systemverilog
module fifo_ctrl #(
    parameter int DEPTH = 4,
    parameter int CW = $clog2(DEPTH + 1)
) (
    input logic clk, rst_n,
    input logic push, pop,
    output logic full, empty,
    output logic push_accept, pop_accept,
    output logic [CW-1:0] occupancy
);
  assign full       = (occupancy == DEPTH);
  assign empty      = (occupancy == 0);
  assign pop_accept  = pop && !empty;
  assign push_accept = push && (!full || pop_accept);

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) occupancy <= '0;
    else case ({push_accept, pop_accept})
      2'b10: occupancy <= occupancy + 1'b1;
      2'b01: occupancy <= occupancy - 1'b1;
      default: occupancy <= occupancy;
    endcase
  end
endmodule
```

<!-- source-end -->

#### 6.5.2 完整 SVA 与参数绑定

属性参数与 RTL 的 `DEPTH/CW` 对应；检查范围、标志一致性以及禁止空读、禁止无空间写入。覆盖目标辅助确认满状态与使用后回到空状态可达。

**保存为 `案例工程/formal/fifo_ctrl_props.sv`：**

<!-- source-begin: 案例工程/formal/fifo_ctrl_props.sv -->

```systemverilog
module fifo_ctrl_props #(
  parameter int DEPTH = 4,
  parameter int CW = $clog2(DEPTH + 1)
) (
  input logic clk, rst_n, push, pop,
  input logic full, empty, push_accept, pop_accept,
  input logic [CW-1:0] occupancy
);
  ap_safe_count: assert property (@(posedge clk) disable iff (!rst_n)
    occupancy <= DEPTH);
  ap_flag_full: assert property (@(posedge clk) disable iff (!rst_n)
    full == (occupancy == DEPTH));
  ap_flag_empty: assert property (@(posedge clk) disable iff (!rst_n)
    empty == (occupancy == 0));
  ap_no_empty_pop: assert property (@(posedge clk) disable iff (!rst_n)
    pop_accept |-> !empty);
  ap_no_overflow_push: assert property (@(posedge clk) disable iff (!rst_n)
    push_accept |-> (!full || pop_accept));
  cp_full: cover property (@(posedge clk) disable iff (!rst_n)
    full);
  cp_empty_after_use: cover property (@(posedge clk) disable iff (!rst_n)
    !empty ##[1:5] empty);
endmodule

bind fifo_ctrl fifo_ctrl_props #(.DEPTH(DEPTH), .CW(CW)) u_fifo_ctrl_props (.*);
```

<!-- source-end -->

#### 6.5.3 文件列表



**保存为 `案例工程/filelist_fifo.f`：**

<!-- source-begin: 案例工程/filelist_fifo.f -->

```text
./rtl/fifo_ctrl.sv
./formal/fifo_ctrl_props.sv
```

<!-- source-end -->

#### 6.5.4 完整脚本



**保存为 `案例工程/scripts/fpv_fifo.tcl`：**

<!-- source-begin: 案例工程/scripts/fpv_fifo.tcl -->

```tcl
set_fml_appmode FPV
read_file -top fifo_ctrl -sva -format sverilog -vcs {-f filelist_fifo.f}
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
vcf -f scripts/fpv_fifo.tcl -batch 2>&1 | tee logs/fpv_fifo.log
```

这些命令应在本机具备相应 VC Formal 版本和许可证时执行。日志中的属性状态才是证明结论；命令退出、脚本结束或没有打印错误都不能代替属性结果检查。

## 7. 如何分析结果

`Proven`：属性在该模型和假设下成立。需要查触发是否可达与约束是否合理。`Falsified`：工具给出违反路径，首先检查输入是否符合环境规格与时钟复位是否正确。`Inconclusive`：目前未完成，不能当作通过。`Covered`：存在一条满足覆盖目标的路径。`Uncoverable`：该目标在当前模型不可达，需要区分真实死逻辑与过度约束。详见 [验证工程与结果判读](验证工程与结果判读.md)。

## 8. 优化证明效率而不损害结论

1. 缩小模块验证范围，必要时划分不同 `fvtask`；不要先大面积假设内部值。
2. 将复杂的一条断言拆成可解释的若干不变量与阶段性结果。
3. 分析影响锥，确认算术、RAM、时钟域和不必要的外围逻辑是否进入证明。
4. 再考虑 `set_fml_var fml_effort high`、资源限制、`set_abstractions`、`snip_driver` 等进阶优化；新抽象可能引入虚假反例。
5. 对长期回归使用符合条件的 `fvlearn_config -local_dir ...`，并区分继承的缓存与新运行获得的真实结果。
6. 使用 `report_fml_engines`、`report_fml_jobs`、`report_fml_hosts` 定位瓶颈。

## 9. 常见故障与排查

| 现象 | 优先检查 | 不应做的事 |
|---|---|---|
| 所有断言都轻松通过 | 触发覆盖、空洞性和假设 | 直接宣布完整验证通过 |
| 许多断言在第 0 拍失败 | 初始化状态与 `$past` | 假设所有寄存器为预期值 |
| 证明几乎没有进展 | 影响锥、参数和 RAM | 无审查地增加内部假设 |
| 只有有界深度结论 | 是否真正 `Proven` | 把展开深度当作无限证明 |
| Verdi 中找不到信号 | 优化、层级、会话版本 | 在不知影响的情况下关掉全部优化 |
| 频繁得到非法请求反例 | 环境模型与协议规范 | 把所有 DUT 失败行为都排除 |

## 10. 进阶主题

FPV 可以与 AIP、覆盖质量评估（FCA）、FTA 的形式测试平台突变分析、Proof Architect 的组合式证明方法等配合。有关无法快速证明的属性，阅读 [调试与证明性能](调试与证明性能.md)；有关交付报告，阅读 [覆盖与验证验收](覆盖与验证验收.md)。FPV 的物理规模限制随属性影响锥、状态空间及引擎而变化，没有一个对所有设计都有效的固定门数门槛。

## 11. 参考定位

User Guide §17（FPV，686 页起），§3（SVA/属性，66 页起），§4（初始化，115 页起），§6～7（运行与调试，183～312 页），§18～20（性能、组合式证明与验收）。Quick Reference Guide 的 FPV 页面提供命令速览，但不是全部参数说明。
