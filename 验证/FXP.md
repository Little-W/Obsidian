# VC Formal FXP 使用手册与脚本用例

本文整理 VC Formal 中 FXP 的常用用法。重点放在 X 传播验证的基本流程、常用命令、根因分析，以及可以直接参考的 Tcl 脚本用例。

说明：下文里的 `<name>`、`<type>`、`<options*>` 是模板占位符，具体参数名请以你当前版本的 VC Formal 文档和项目脚本约定为准。

## 1. FXP 是什么

FXP 是 X-Propagation Verification，也就是形式 X 传播验证。它的目标不是证明协议或功能本身，而是检查未知值 X 是否会沿着设计传播到危险位置，从而暴露隐藏的功能风险。

FXP 通常关注这些问题：

- 复位后是否仍存在未初始化信号。
- 某些控制路径是否会把 X 传播到关键寄存器或输出。
- 组合逻辑、选择器、mux、状态编码是否会放大 X。
- 设计在 X 输入下是否有足够的保护、屏蔽或隔离。

如果你的问题是“这个 X 会不会最终影响到功能输出”，优先考虑 FXP。

## 2. FXP 的核心思路

FXP 的基本思路是：先把设计和环境搭起来，再通过 X 注入、X 去除和属性检查来观察未知值的传播路径。最后再用根因分析定位到底是哪里把 X 放进来的、哪里没有挡住、哪里是可接受传播，哪里是实际缺陷。

这和 FPV 不同。FPV 更关注“功能规则是否成立”，FXP 更关注“未知值是否会污染关键路径”。

## 3. 什么时候用 FXP

FXP 适合这些场景：

- 复位后设计里存在潜在未初始化状态。
- 总线、mux、状态机或数据通路对 X 很敏感。
- 你想确认 X 是否会传播到输出、寄存器、控制信号或安全关键路径。
- 你怀疑某些断言失败其实是由 X 传播引起，而不是功能逻辑本身有错。
- 你想在正式验证前先做 X 风险扫描。

## 4. 标准工作流

FXP 的典型流程可以拆成以下几步：

1. 设置 application mode 为 FXP。
2. 读入 RTL 和必要的断言/约束。
3. 定义时钟、复位和初始化方式。
4. 使用 `fxp_generate` 生成需要的 X 传播对象。
5. 使用 `fxp_assume -injectx` 或 `fxp_assume -nox` 建立 X 注入与 X 抑制条件。
6. 使用 `fxp_assert` 检查 X 传播目标。
7. 执行 `check_fv`。
8. 使用 `report_fv`、`view_trace`、`fxp_compute_rootcause` 做调试和根因定位。

## 5. 常用命令说明

### 5.1 设置模式

```tcl
set_fml_appmode FXP
```

把 VC Formal 切到 FXP 模式。这样后面的 X 传播相关命令、变量和分析流程才会按 FXP 语义工作。

### 5.2 读入设计

```tcl
read_file -top top -sva -format sverilog -vcs {-f filelist}
analyze -format sverilog -vcs {-f filelist}
elaborate top -sva
```

读取设计和断言的方式和 FPV 类似。你也可以按项目需要先编译，再展开，再进入 FXP。

### 5.3 时钟、复位和初始化

```tcl
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
sim_run -stable
sim_save_reset
```

FXP 也需要稳定、可重复的起始状态。复位、时钟和初始状态定义得越清晰，X 传播分析越可靠。

### 5.4 X 传播对象生成

```tcl
fxp_generate <name> <type>
```

这个命令用于生成 FXP 相关的检查对象。`<name>` 一般是你自己命名的检查目标，`<type>` 则描述检查类型。

### 5.5 X 注入和 X 屏蔽

```tcl
fxp_assume -injectx <options*>
fxp_assume -nox <options*>
```

- `-injectx`：告诉工具从指定位置注入 X。
- `-nox`：告诉工具某些对象不允许出现 X，或者把它们当作受控区域。

### 5.6 X 传播检查

```tcl
fxp_assert <options*>
```

这个命令用于把 X 传播检查真正挂到验证流程里。你可以把它理解为 FXP 场景下的断言构造入口。

### 5.7 根因分析

```tcl
fxp_compute_rootcause property
fxp_report_rootcause
```

当某个 FXP 属性失败时，根因分析可以帮助你找出最小的可疑路径和最关键的传播点。

## 6. 从终端启动

如果你想直接从终端启动 FXP，最常见的方式是先准备一个 Tcl 脚本，然后用 `vcf` 读取脚本运行。

### 6.1 PowerShell 启动命令

```powershell
vcf -f .\fxp_run.tcl
```

如果当前目录下已经有 `fxp_run.tcl`，这条命令会直接启动 VC Formal 并按脚本执行 FXP 流程。

### 6.2 带 Verdi 的启动命令

```powershell
vcf -f .\fxp_run.tcl -verdi
```

这个写法适合你希望在启动后直接联动波形或调试界面。

### 6.3 批处理启动命令

```powershell
vcf -f .\fxp_run.tcl -batch
```

这个写法适合回归或自动化执行，不依赖交互界面。

### 6.4 最小 FXP 启动脚本模板

```tcl
set_fml_appmode FXP

read_file -top top -sva -format sverilog -vcs {-f filelist}
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset

fxp_generate xprop_root logic
fxp_assert -name xprop_root_check

check_fv
report_fv -list
```

你可以把这个内容保存为 `fxp_run.tcl`，再用上面的 `vcf -f .\fxp_run.tcl` 直接启动。

## 7. FXP 常见脚本用例

### 用例 1：最小 FXP 初始化脚本

适用场景：你第一次把一个 RTL 放进 FXP，想先确认环境、复位和基本流程是否能跑通。

```tcl
set_fml_appmode FXP

read_file -top top -sva -format sverilog -vcs {-f filelist}

create_clock clk -period 100
create_reset rst -sense high

sim_run -stable
sim_save_reset

fxp_generate xprop_root logic
fxp_assert -name xprop_root_check

check_fv
report_fv -list
```

这个脚本的目的不是一次性把问题找完，而是先把 FXP 工作链路跑起来。

### 用例 2：从复位后 X 传播开始检查

适用场景：你担心复位解除后某些寄存器仍然带着未知值，并且会进一步污染输出。

```tcl
set_fml_appmode FXP

read_file -top top -sva -format sverilog -vcs {-f filelist}
create_clock clk -period 100
create_reset rst -sense high

sim_run -stable
sim_save_reset

fxp_generate reset_x_check logic
fxp_assume -injectx -signal {rst_domain_reg*}
fxp_assert -name reset_x_check

check_fv
fxp_compute_rootcause reset_x_check
fxp_report_rootcause
```

这个用例适合定位复位域里最容易出现的 X 残留问题。

### 用例 3：对关键输出做 no-X 约束

适用场景：你只关心关键输出是否绝对不能带 X，例如控制输出、协议有效位、关键使能信号。

```tcl
set_fml_appmode FXP

read_file -top top -sva -format sverilog -vcs {-f filelist}
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset

fxp_assume -nox -signal {control_out*}
fxp_generate nox_control_out logic
fxp_assert -name nox_control_out

check_fv
report_fv -verbose
```

这个用例的重点是把“不能出现 X”的区域显式标出来，适合关键控制面检查。

### 用例 4：X 根因定位流程

适用场景：某条 FXP 属性失败了，你已经知道有 X 传播，但还不知道是哪一级逻辑放大的。

```tcl
set_fml_appmode FXP

read_file -top top -sva -format sverilog -vcs {-f filelist}
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset

fxp_generate rootcause_probe logic
fxp_assert -name rootcause_probe

check_fv
fxp_compute_rootcause rootcause_probe
fxp_report_rootcause
view_trace -property rootcause_probe
```

这个流程适合在你已经拿到失败结果后做深入分析。

## 8. 一个实用的 FXP 工作流

如果目标是快速做一次 X 风险扫描，可以按下面的顺序做：

1. 读入设计并完成 `read_file`、`analyze` 或 `elaborate`。
2. 定义时钟、复位和稳定的 reset state。
3. 用 `fxp_generate` 定义检查目标。
4. 用 `fxp_assume -injectx` 选择 X 注入口。
5. 用 `fxp_assume -nox` 定义不允许传播 X 的关键区域。
6. 用 `fxp_assert` 绑定检查。
7. 跑 `check_fv`。
8. 失败后用 `fxp_compute_rootcause` 和 `fxp_report_rootcause` 收敛根因。

## 9. 调试建议

- 如果 FXP 结果太多，先缩小 X 注入口，再扩范围。
- 如果你不确定 X 是不是设计缺陷，先看复位路径和初始化路径。
- 如果输出只在极少路径上出现 X，优先确认该路径是否真的可达。
- 如果多个检查都失败，先看根因分析，而不是先改断言。

## 10. 常用命令速查

```tcl
set_fml_appmode FXP
read_file -top top -sva -format sverilog -vcs {-f filelist}
analyze -format sverilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset
fxp_generate <name> <type>
fxp_assume -injectx <options*>
fxp_assume -nox <options*>
fxp_assert <options*>
check_fv
report_fv -list
fxp_compute_rootcause property
fxp_report_rootcause
view_trace -property property
```

## 11. 小结

FXP 的核心是把未知值 X 的传播路径显式化，然后通过注入、抑制、检查和根因分析，把“可能有风险”变成“哪里有风险、为什么有风险”。它特别适合复位、控制面、选择器、状态机和关键输出路径。

如果你愿意，我可以下一步继续把这份 FXP 手册补成“中文翻译版速查”，或者再单独给你写一版和 FPV 联合使用的 FXP 启动脚本。