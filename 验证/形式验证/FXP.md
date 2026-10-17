# FXP：形式未知值传播验证完整指南

> **源码内嵌版。** 本章的完整案例以“保存为”标明文件路径，并在下方直接列出全文。代码框不带显示行号，可直接复制；`案例工程/` 只表示目录结构，不要求另找源码附件。包含占位符或保护性 `error` 的专用流程另行明确标为模板。

> **第 7 册 · 专用应用**　Formal X-Propagation Verification。依据 User Guide 第 12 章（第 444～457 页）、Quick Reference Guide 的 FXP 页面。原有笔记中有较多全设计信号扫描与调试命令，本版将其整理为有风险说明的进阶用法。

## 1. 为什么未知值传播值得单独验证

RTL 仿真中的 `X` 可能表示：寄存器尚未复位、未驱动、赋值了 X、模块未定义、数组越界、选择条件不确定等。真实电路并不存在一种独立的“X 电压值”；它表示形式或仿真层面对确定性的缺失。在安全控制、启动流程、电源域切换、复位释放和错误路径中，一个无法确定的控制值可能在时序上被传播或放大。

FXP 的核心目标是寻找：**指定的未知值来源是否可能影响不应该出现未知值的观察信号**。它通过生成 X 注入点与观察点、建立检查并使用形式引擎寻找违反条件的轨迹。普通 FPV 的二值断言不能自动等同于这种 X 传播分析。

![FXP 注入源和观察点](插图/07_FXP传播.svg)

## 2. 注入点与观察点的概念

**注入点**是允许引入未知值的位置，例如未初始化寄存器、显式 `X` 赋值、未驱动信号、黑盒输出或人为指定的关键节点。**观察点**是要求未知值不应到达的位置，例如顶层功能输出、关键状态机控制端、黑盒输入和被指定为需要稳定可判定值的寄存器。

形式检查回答的是：在当前复位和输入条件下，能否找到一条路径，让注入的不确定性传播到观察点？它不是统计 X 出现概率，也不等于电路可靠性故障率分析。

## 3. FXP 自动生成检查的类型

UG §12.3（第 447～451 页）介绍了下列常见类型：

- **类型名：**

  ```text
  uninit
  ```

  **来源或目标：** 未初始化寄存器

  **意义：** 未复位状态可能携带未知值

- **类型名：**

  ```text
  xassign
  ```

  **来源或目标：** 显式 X 赋值

  **意义：** 设计源代码主动产生不确定值

- **类型名：**

  ```text
  undriven
  ```

  **来源或目标：** 未驱动信号

  **意义：** 网络没有确定驱动

- **类型名：**

  ```text
  undef
  ```

  **来源或目标：** 未定义运算

  **意义：** 例如某些除零场景

- **类型名：**

  ```text
  oba
  ```

  **来源或目标：** 越界访问

  **意义：** 数组等操作超出合法范围

- **类型名：** `bbout`（按该版本帮助核对）

  **来源或目标：** 黑盒输出

  **意义：** 未知结果可能进入下游

- **类型名：**

  ```text
  bbin
  ```

  **来源或目标：** 黑盒输入

  **意义：** 观察未知值是否送入模块

- **类型名（分别列出）：**

  ```text
  in
  out
  ```

  **来源或目标：** 顶层输入/输出

  **意义：** 自定义源或观察目标

- **类型名：**

  ```text
  snip
  ```

  **来源或目标：** 经过截断的网络

  **意义：** 被抽象网络引入不确定性

- **类型名：**

  ```text
  abs
  ```

  **来源或目标：** 抽象对象

  **意义：** 抽象造成额外未知来源或观察点

- **类型名（分别列出）：**

  ```text
  unresin
  unresout
  ```

  **来源或目标：** 未解析模块输入/输出

  **意义：** 未解析实例两侧的传播

**类型字符串以具体安装版本 `help fxp_generate` 和 UG 表 19 为准**。不同来源给出的缩写有差异，不能仅凭类型名称猜测选项。`fxp_generate` 无 `-type` 时已包含若干默认类别；明确选择不同类别后，自动生成的属性数可能发生变化。

## 4. 标准脚本与运行顺序

```tcl
set_fml_appmode FXP
read_file -top soc_top -format sverilog -vcs {-f filelist.f}
create_clock clk -period 100
create_reset rst_n -sense low
set_constant test_mode -value 1'b0
sim_run -stable
sim_save_reset
check_fv_setup
fxp_generate
report_fv -list
check_fv -block
report_fv -verbose
```

`fxp_generate` 使用默认类型自动提取检查。若没有复位的原型模块，应删除不适用的 `create_reset`，不能输入一个不存在的复位信号。任何被 `set_constant` 固定的控制输入都应有真实工程依据，否则可能人为切断未知值传播路径。

### 4.1 显式选择未初始化寄存器类型

```tcl
fxp_generate -name uninitialized_checks -type {uninit}
```

只关注某类来源有利于快速建立第一批可解释的结果。UG 中还给出了将某个范围及若干类型一起配置的方式；例如只针对某个子模块，可传入对应的 scope 列表（需要真实实例路径）。

## 5. 自定义 X 注入、去除与断言

- **命令：**

  ```tcl
  fxp_generate ...
  ```

  **作用：** 自动生成 X 检查

  **工程注意：** 分类范围与默认类型需确认

- **命令：**

  ```tcl
  fxp_assume -injectx <signal>
  ```

  **作用：** 指定信号作为 X 注入来源

  **工程注意：** 时钟与复位不允许当作该命令的注入源

- **命令：**

  ```tcl
  fxp_assume -nox <signal>
  ```

  **作用：** 在指定条件下认为目标不携带未知值

  **工程注意：** 必须有硬件/协议依据

- **命令：**

  ```tcl
  fxp_assert <signal>
  ```

  **作用：** 指定目标信号不允许发生 X 传播

  **工程注意：** 首先明确哪些运行状态必须已知

- **命令：**

  ```tcl
  fxp_compute_rootcause <property>
  ```

  **作用：** 尝试计算属性的未知来源原因

  **工程注意：** 需要存在可用的分析结果

- **命令：**

  ```tcl
  fxp_report_rootcause
  ```

  **作用：** 报告来源与传播信息

  **工程注意：** 按报告定位 RTL/层级

```tcl
# 假设 input_data 确实是不受控外部输入，调试时人为注入 X
fxp_assume -injectx input_data

# 关键控制输出不允许成为未知
fxp_assert -name no_x_on_commit commit_valid
```

`fxp_assume -injectx` 的 `-reset`、`-oba`、`-xassign`、`-undef`、`-condition`、`-scope` 有类型与范围限制。例如 UG §12.3.2 提到 `-oba`、`-xassign` 和 `-undef` 需要相应 scope，并且对时钟/复位注入有限制。`fxp_assume -nox` 的条件参数在 PDF 的语法行存在排印不严谨之处，实际脚本应在本机通过 `fxp_assume -help` 校验，不能机械复制不完整的占位语法。

### 5.1 什么时候允许 `-nox`

只有当硬件结构、外部协议或正式初始化流程**保证该信号在指定阶段已知**时，才允许消除其 X 来源。例如某寄存器由上电复位明确赋值，且复位时序确实执行；或者某输入在完成训练后才被采样，且存在可证明的有效标志。如果将所有未知数据都用 `-nox` 约束掉，FXP 就失去实际作用。

## 6. 教学用例 A：未复位的数据寄存器

```systemverilog
module uninit_demo (
  input  logic clk, rst_n, write,
  input  logic [7:0] in_data,
  output logic [7:0] out_data
);
  logic [7:0] cache;
  always_ff @(posedge clk) begin
    if (write)
      cache <= in_data;
  end
  always_comb out_data = cache;
endmodule
```

`cache` 不受 `rst_n` 复位，且复位后在第一次写入之前可以作为任意初值输出。若 `out_data` 必须始终有效，FXP 应提示风险。修复方式有两类：一是复位 `cache`，二是在 `cache` 内容有效前通过 `valid` 等硬件逻辑阻止下游采样，或输出一个确定值。**仅添加形式假设让 `write` 在第一拍发生，不一定等同于真实硬件有此保证。**

### 6.1 更合理的有效性控制

```systemverilog
logic initialized;
always_ff @(posedge clk or negedge rst_n) begin
  if (!rst_n) initialized <= 1'b0;
  else if (write) initialized <= 1'b1;
end
assign out_data = initialized ? cache : 8'h00;
```

当 `cache` 尚未被写入时，输出为确定值；写入后使用缓存数据。FXP 仍要检查选择条件以及其他传播分支是否可能携带未知值。

### 6.2 本节完整工程文件

上面的片段展示问题原理。以下是同一类未初始化缓存案例的完整文件，故意保留复位端口却不复位缓存，用来说明“端口存在”并不意味着缓存有已知初值。

#### 6.2.1 被验证的完整 RTL



**保存为 `案例工程/rtl/uninit_demo.sv`：**

<!-- source-begin: 案例工程/rtl/uninit_demo.sv -->

```systemverilog
// Purposefully uninitialized cache to illustrate FXP, not recommended RTL.
module uninit_demo (
  input logic clk, rst_n, write,
  input logic [7:0] in_data,
  output logic [7:0] out_data
);
  logic [7:0] cache;
  always_ff @(posedge clk)
    if (write) cache <= in_data;
  assign out_data = cache;
endmodule
```

<!-- source-end -->

#### 6.2.2 完整文件列表



**保存为 `案例工程/filelist_fxp.f`：**

<!-- source-begin: 案例工程/filelist_fxp.f -->

```text
./rtl/uninit_demo.sv
```

<!-- source-end -->

#### 6.2.3 完整 FXP 脚本

`fxp_generate` 选择未初始化对象，`fxp_assert` 将输出作为必须已知的观察位置。输入 `write` 没有被假设为始终有效，因此必须考虑尚未写入的路径。

**保存为 `案例工程/scripts/fxp_uninit.tcl`：**

<!-- source-begin: 案例工程/scripts/fxp_uninit.tcl -->

```tcl
set_fml_appmode FXP
read_file -top uninit_demo -format sverilog -vcs {-f filelist_fxp.f}
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
fxp_generate -name uninitialized_checks -type {uninit}
fxp_assert -name output_must_be_known out_data
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
vcf -f scripts/fxp_uninit.tcl -batch 2>&1 | tee logs/fxp_uninit.log
```

这些命令应在本机具备相应 VC Formal 版本和许可证时执行。日志中的属性状态才是证明结论；命令退出、脚本结束或没有打印错误都不能代替属性结果检查。

预期观察是：未发生有效写入时，缓存的不确定性可能到达输出。分析失败应查看工具实际选择的注入点和反例，不应通过把 `write` 固定为 1 来掩盖初始化缺陷。这里没有真实 FXP 运行报告。

## 7. 教学用例 B：显式 X 赋值与越界

```systemverilog
always_comb begin
  unique case (opcode)
    2'b00: result = a + b;
    2'b01: result = a ^ b;
    default: result = 'x;
  endcase
end
```

对未定义操作码，显式 X 可能被后级直接使用；`-type {xassign}` 可以帮助定位。若协议规定未支持操作码必须返回错误码或忽略写入，则直接赋 X 不是完整实现，应修改 RTL 和相应 SVA。如果设计规则明确规定非法操作码永远不会输入，则需要有可审查的上游保证，不能只对当前检查添加无限制输入假设。

对数组 `mem[index]` 的非法访问则属于 `oba` 等相关检查。在一些 RTL 里，越界索引导致的 X 传播既可被 AEP 发现，也可通过 FXP 分析其实际影响的观察点，两者结论不同、相互补充。

## 8. 教学用例 C：有意屏蔽不确定数据

```systemverilog
assign packet_out = valid ? raw_packet : '0;
```

如果 `valid` 的生成完全可靠且只有 `valid=1` 时 `raw_packet` 才被使用，则未初始化的 `raw_packet` 未必造成危险输出。FXP 应在考虑 `valid` 的实际来源和复位行为后判断其是否能够影响 `packet_out`；不要只凭 `raw_packet` 未复位就断定必须增加复位网络。对于大面积数据寄存器，**有效位优先**的方案往往比强行复位所有触发器更合理，但前提是证明有效位本身可靠，且其控制可完全屏蔽未知数据。

## 9. 调试：由下游症状回溯到上游来源

```tcl
check_fv -block
report_fv -list
view_trace -property <failed_property>
fxp_compute_rootcause <failed_property>
fxp_report_rootcause
```

定位时先找观察点在何时受影响，然后从该周期往前追踪经过的条件选择、多路复用器、寄存器和复位逻辑。重点确认是否存在：复位未覆盖、输出在有效位之前被采样、黑盒建模不当、未知模式输入未处理、未驱动网络或隐含时钟门控。必须把“真正产生不确定性”和“最终使不确定性可见”分开分析。

![FXP 调试排查流程](插图/08_FXP排查.svg)

## 10. 设计规模很大时怎么做

先针对关键输出与重要控制节点建立一批观察点；其次根据报告只针对相关模块开启额外的注入类型；最后扩大到全模块或全芯片。全信号扫描往往生成大量属性，可能包含没有工程意义的中间节点和普通数据寄存器，因此不推荐把 `get_signals` 的全部对象直接无差别传给 `fxp_assert`，尤其不推荐在没有容量预算和报告分类时执行。若需批量生成对象列表，应该过滤时钟、复位、扫描测试、非功能占位和已知允许变化的信号，并在最终报告中清晰列出排除规则。

### 10.1 与复位覆盖工作的关系

FXP 可帮助识别“实际运行时需要已知，但没有完整初始化”的重要状态，但**不能单独替代复位规格验证**。建议同时使用 FPV 证明复位之后关键控制寄存器为规定的常量。这样发现的 X 传播问题可以分成：状态未初始化、控制路径泄漏、协议保护失效、或仿真 X 语义不同。

## 11. 常见问题

- **现象：** 复位后一拍输出为 X

  **可能原因：** 数据寄存器未复位或有效位错误

  **改进方向：** 修改 RTL 或协议保护

- **现象：** 某黑盒输出引起所有下游失败

  **可能原因：** 模型过于自由

  **改进方向：** 提供正确的黑盒约束或可综合模型

- **现象：** 所有属性都通过但已知存在 X 问题

  **可能原因：** 未将关键输出列为观察点或注入范围不足

  **改进方向：** 核对 `fxp_generate` 类型及属性数量

- **现象：** 生成属性太多，内存不足

  **可能原因：** 扫描范围过宽

  **改进方向：** 按重要模块、输出和原因分批

- **现象：** `-injectx` 报错

  **可能原因：** 选中时钟/复位或不支持对象

  **改进方向：** 查该命令对象与 scope 限制

- **现象：** 人工 `-nox` 后全部通过

  **可能原因：** 可能屏蔽真实传播

  **改进方向：** 审查硬件依据，保留原始对照结果

## 12. FXP 与 AEP、FPV 的分工

- AEP 可自动检查“数组是否越界、表达式是否存在潜在不安全结构”；
- FXP 检查“潜在未知值是否影响重要观察点”；
- FPV 检查“满足输入规范时，关键输出值或控制状态是否符合功能规格”。

例如越界读导致数据可能不确定，三个应用依次能够定位越界原因、传播风险、以及实际功能规则失败。联合使用更全面，但三者仍依赖正确的模型和约束。

## 13. 官方依据与版本提醒

User Guide 第 12 章（444～457 页），Quick Reference Guide FXP 部分。`set_blackbox` 的开关应以安装版本帮助为准，部分旧笔记中存在 `-design` 与 `-designs` 混用；不要把未核对的选项直接写入生产脚本。源码形式验证与真实芯片的亚稳态、模拟电压和物理故障不是同一个模型。
