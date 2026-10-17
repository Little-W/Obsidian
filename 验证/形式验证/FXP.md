# VC Formal FXP 使用手册与脚本用例

本文整理 VC Formal 中 FXP 的常用用法。重点放在 X 传播验证的基本流程、常用命令、根因分析，以及可以直接参考的 Tcl 脚本用例。

说明：下文里的 `<name>`、`<type>`、`<signal_name>`、`<scope_name>`、`<options*>` 是模板占位符，具体参数名请以你当前版本的 VC Formal 文档和项目脚本约定为准。`-nox` 里的 `condition` 是关键字写法，不要写成 `-condition`。

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

如果你想先从当前 `filelist` 里找某个模块的顶层名称，可以用下面这类命令：

```powershell
Get-Content .\filelist | ForEach-Object { rg -n "^\s*module\s+TOP_NAME\b" $_ }
```

如果你还不知道顶层模块名，可以先把 `filelist` 里的源文件展开，再批量看每个文件里的 `module` 声明：

```powershell
Get-Content .\filelist | ForEach-Object { rg -n "^\s*module\s+" $_ }
```

把 `TOP_NAME` 换成你要找的模块名即可。这个做法适合先确认 `elaborate` 里应该用哪个 top 名字，再回填到 `read_file -top` 或 `elaborate` 里。

如果你已经在 Verdi 里把设计加载好了，那就直接在 Verdi 的 Tcl Console 里查数据库，不用再回到 filelist 里搜。常见写法是先列出顶层实例，再按名字过滤：

```tcl
get_db insts -if {.is_top == true}
get_db insts -if {.name =~ *TOP_NAME*}
get_db nets  -if {.name =~ *SIG_NAME*}
```

如果你想先看当前已经加载了哪些设计，也可以先查设计列表：

```tcl
get_db designs
```

这里的 `TOP_NAME` 和 `SIG_NAME` 换成你要找的模块名或信号名即可。不同 Verdi 版本的对象字段可能略有差异，如果 `-if` 报错，先在 Tcl Console 里执行 `help get_db` 看当前版本支持的参数。

### 5.3 时钟、复位和初始化

```tcl
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
sim_run -stable
sim_save_reset
```

FXP 也需要稳定、可重复的起始状态。复位、时钟和初始状态定义得越清晰，X 传播分析越可靠。

如果你看到类似 `FML_RESET_SNIP` 或 `SIM_FORCE_RESET` 的警告，通常说明你现在绑定的复位网本身还有上游驱动，或者你把 `sim_force` 直接打在了复位信号上。修复思路有两个：

- 如果这个复位网本来就应该由更上游的信号生成，先在 `create_reset` 之前打开 `fv_config -enable_reset_find_driver`，让工具去找真实的上游驱动，再把 `create_reset` 绑定到那个更合适的复位源上。
- 如果你只是想在仿真里制造复位状态，不要直接对复位网本身 `sim_force`，而是驱动它的上游输入，或者用 `sim_set_state` / `sim_save_reset` 这类方式保存稳定状态。

简化说就是：复位网最好是“输入型”而不是“内部逻辑型”。如果它已经是内部逻辑生成的，就先找源头，再做 `create_reset`。

如果你说的“内部逻辑的复位和时钟”是指层次内部的中间网，那要分开处理：

- 复位：可以在确认层次路径正确后，用层次名去驱动真正的复位源，或者在调试时对内部复位网做 `sim_force`，但这会剪掉原始驱动，容易引入 `SIM_FORCE_RESET` 一类警告。更稳妥的做法还是先找上游驱动，再让 `create_reset` 绑定到上游源。
- 时钟：不要把内部时钟当成普通静态信号去 force 成 0 或 1。时钟应该通过 `create_clock <clock_name> -period <...>` 来定义，或者让它的上游分频/门控源正常运行。只有在你明确知道自己在做什么时，才对层次内部的 clock net 做临时强制。

一个实用原则是：

```tcl
# 推荐：定义时钟对象，而不是 force 时钟网
create_clock clk -period 100

# 调试时如果必须看内部复位，优先找上游驱动
fv_config -enable_reset_find_driver
```

如果你只是想让内部寄存器进入某个固定状态，通常比起 force 复位/时钟，更适合用 `sim_set_state`、`sim_save_reset`，或者直接 force 控制数据和使能信号。

如果你想把仿真波形拉长一点，可以在稳定之后继续跑固定拍数，例如：

```tcl
sim_run 3 -clk clk
```

这里的 `3` 表示再按 `clk` 跑 3 个时钟周期，适合用来观察更长时间窗内的 X 传播。

这种写法通常不需要再额外配一个 reset 命令；如果你的目的只是延长波形，直接继续 `sim_run` 就可以。真正常见的配套动作是 `sim_save_reset`，它负责把当前稳定的 reset 状态保存下来，供后续验证反复复用。

这里的 `clk` 是时钟对象名，必须和前面 `create_clock clk -period 100` 里定义的名字一致；`sim_run` 不是自己去猜时钟，而是按你指定的 clock 对象推进周期。若设计里有多个时钟，就用你想观察的那个 clock 名称。

如果你在执行 `sim_run` 时看到 `SIM_MODEL_OUTDATED`，说明当前 reset 仿真模型已经过期，通常是因为前面改过 reset 相关设置、重新展开过设计，或者当前模型还没有同步到最新状态。这时不要直接重复 `sim_run`，而是先执行 `sim_reset` 清掉当前模型，再重新 `sim_run`。

如果你的设计复位信号叫 `presetn` 这类名字，要把命令里的复位对象名写成设计里真实存在的那个信号，并且 `-sense` 要和它的极性一致。例如，低有效复位通常写成 `create_reset presetn -sense low`。如果报 `TCL_OBJECT_NOT_FOUND`，优先检查 `analyze` / `elaborate` 的 top 和 filelist 是否把这个复位网包含进来了。

### 5.4 X 传播对象生成

```tcl
fxp_generate [<list-of-scopes>] -name <my_name> -type {<list-of-types>}
```

这个命令用于生成 FXP 相关的检查对象。`<list-of-scopes>` 写实例层次名，不写模块名；`-name` 是生成属性的前缀；`-type` 用来选择要生成的注入/观测类型。当前脚本模板里不要把属性名直接写成第一个位置参数，否则它会被当成 scope 去匹配。

另外，`create_reset` 使用的复位信号名必须是设计中真实存在、并且已经被正确展开到当前 top 的对象。如果报 `TCL_OBJECT_NOT_FOUND`，通常要先检查 top、filelist 和复位信号名是否一致。

### 5.5 X 注入和 X 屏蔽

```tcl
fxp_assume -injectx [-name <name>] [-reset] [-oba] [-xassign] [-undef] [-condition <expr>] [-scope <scope_name>] <signal_name>
fxp_assume -nox [-name <name>] [-reset] [condition <condition> [<signal_name>]]
```

- `-injectx`：告诉工具在指定信号上注入 X。
- `-nox`：告诉工具在指定信号上抑制 X。
- `signal_name`：这里是最后一个位置参数，不要写成 `-signal`，也不要用通配符代替真实信号名。

### 5.6 X 传播检查

```tcl
fxp_assert [-name <name>] [-condition <expr>] <signal_name>
```

这个命令用于把 X 传播检查真正挂到验证流程里。`signal_name` 是最后一个位置参数，表示要观察 X 不能传播到的点。

### 5.7 根因分析

```tcl
fxp_compute_rootcause property
fxp_report_rootcause
```

当某个 FXP 属性失败时，根因分析可以帮助你找出最小的可疑路径和最关键的传播点。

如果属性状态是 `pass` / `proven`，而 `rootcause_type` 显示 `not_computed`，这通常是正常现象。根因分析主要是给 `falsified` 的 FXP 属性用的；对于已经证明没有 X 传播的属性，工具不会再计算根因。

如果你想看失败路径的根因，可以先确认该属性确实是 `falsified`，再对该 property 执行 `fxp_compute_rootcause` 和 `fxp_report_rootcause`。如果现在是 `pass`，一般不需要处理 `not_computed`，只要把它当成“无需根因”的结果即可。

在脚本里要特别注意执行顺序：`fxp_compute_rootcause` 只能在 `check_fv` 已经结束之后调用，不能放在一个仍在运行的 `check_fv` 过程中，也不要嵌套在会再次触发 `check_fv` 的流程里。否则就会看到类似 `check_fv[0] is already running, you can not nest the command` 的报错。

推荐写法是先跑完检查，再单独算根因：

```tcl
check_fv
fxp_compute_rootcause rootcause_probe
fxp_report_rootcause
```

如果你用的是自动根因模式，也仍然要把它放在 `check_fv` 完成之后：

```tcl
set_fml_var fxp_compute_rootcause_auto true
check_fv
report_fv -list
```

简单说就是：`check_fv` 先结束，`fxp_compute_rootcause` 再执行；不要反过来，也不要并行嵌套。

### 5.8 自动检测所有顶层模块中的信号

如果你的目标是先对整个设计或多个顶层模块做一轮 X 风险扫描，通常不需要把每个信号都手写出来。更常见的做法是让 `fxp_generate` 按默认类型直接覆盖整个设计，或者把多个顶层实例一次性传给它，让工具自动生成对应的 X 注入和观测点。

最简写法通常是：

```tcl
fxp_generate -name all_x_scan -type {auto}
```

如果你只想扫某几个顶层实例，就把 scope 一次性传进去：

```tcl
fxp_generate {top0 top1 top2} -name top_scan -type {auto}
```

这里的要点是：

- `fxp_generate` 负责批量生成检查点。
- `-type {auto}` 会使用默认的 X 注入和观测类型。
- 如果你不传 scope，工具会按默认类型扫当前设计上下文；如果你传多个 scope，就可以一次覆盖多个顶层实例。
- `fxp_assume` 和 `fxp_assert` 仍然更适合显式信号名；如果你确实要批量加规则，建议再用 Tcl 的 `foreach` 去循环信号列表。

一个更实用的批量脚本范例如下：

```tcl
set_fml_appmode FXP

analyze -format sverilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset

fxp_generate -name all_x_scan -type {auto}

set critical_signals {top.u_core.req top.u_core.ack top.u_periph.valid top.u_periph.ready}
foreach sig $critical_signals {
	fxp_assert $sig
}

check_fv
fxp_compute_rootcause
fxp_report_rootcause -list
```

这个写法适合“先一口气扫全局，再对少量关键点补精确检查”的场景。

### 顶层全信号扫描脚本示例

如果你只想先把顶层实例中的所有信号扫一遍，可以直接把顶层实例名作为 scope 传给 `fxp_generate`，然后让工具自动生成默认的 X 注入和观测点。

```tcl
set_fml_appmode FXP

analyze -format sverilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset

fxp_generate {top} -name top_all_scan -type {auto}

check_fv
fxp_compute_rootcause
fxp_report_rootcause -list
```

这个脚本的特点是：

- `top` 必须是你实际展开后的顶层实例名，不是模块名。
- `-type {auto}` 会使用默认的 FXP 类型集合，适合先做全局扫描。
- 如果你有多个顶层实例，可以把它们一次写进 scope 列表里。

### 公司常用完整脚本模板

下面是一版更完整的 FXP 测试脚本，适合做成项目里的标准入口。它把设计读入、顶层扫描、关键点检查、自动根因收集和结果报告串成一条完整链路。

```tcl
set_fml_appmode FXP
set_fml_var fxp_compute_rootcause_auto true

set top_scope top
set top_scopes [list $top_scope]
set critical_signals [list \
	$top_scope.u_core.req \
	$top_scope.u_core.ack \
	$top_scope.u_periph.valid \
	$top_scope.u_periph.ready]

analyze -format sverilog -vcs {-f filelist}
elaborate $top_scope -sva

create_clock clk -period 100
create_reset rst -sense high

sim_run -stable
sim_save_reset

fxp_generate $top_scopes -name company_fxp -type {auto}

foreach sig $critical_signals {
	fxp_assert $sig
}

check_fv
report_fv -list
fxp_report_rootcause -list
```

这份模板的特点是：

- `top_scope` 集中管理顶层实例名，换工程时只改一处。
- `fxp_generate $top_scopes -name company_fxp -type {auto}` 会一次覆盖当前顶层实例。
- `critical_signals` 只放少量真正关心的控制点，便于后续做精确检查。
- `set_fml_var fxp_compute_rootcause_auto true` 会在失败时自动准备根因信息，适合回归脚本。

如果你要扫多个顶层实例，把 `top_scopes` 改成多个实例名即可，例如：

```tcl
set top_scopes [list top0 top1 top2]
```

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

analyze -format sverilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset

fxp_generate -name xprop_root -type {uninit out}
fxp_assert -name xprop_root_check <signal_name>

check_fv
report_fv -list
```

你可以把这个内容保存为 `fxp_run.tcl`，再用上面的 `vcf -f .\fxp_run.tcl` 直接启动。

### 6.5 网格调度配置：`set_grid_usage`

如果你的 VC Formal 运行环境接了 LSF 这类作业调度系统，可以用 `set_grid_usage` 指定工具如何提交网格作业。它通常放在脚本开头、正式跑 `check_fv` 之前，用来告诉工具“把哪些阶段交给集群执行，以及用什么提交命令”。

你的写法：

```tcl
set_grid_usage -type lsf=5 -control {bsub -Is -q merm -R "rusage[mem=8000]"}
```

可以拆开理解成：

- `-type lsf=5`：使用 LSF 网格类型，并按当前环境约定启用对应的并行/作业级别配置。
- `-control { ... }`：指定实际提交命令模板。
- `bsub`：LSF 的提交命令。
- `-Is`：以交互方式启动作业。
- `-q merm`：提交到 `merm` 队列。
- `-R "rusage[mem=8000]"`：向调度器申请 8000 MB 内存资源。

一个常见用法是把它和主脚本放在一起：

```tcl
set_fml_appmode FXP
set_grid_usage -type lsf=5 -control {bsub -Is -q merm -R "rusage[mem=8000]"}

analyze -format sverilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset

fxp_generate -name grid_x_scan -type {auto}
check_fv
report_fv -list
```

几点经验：

- 如果你的环境已经由平台统一封装了提交模板，`-control` 里一般只需要保留调度器必需参数。
- 如果作业提交失败，优先检查队列名、内存申请和是否允许交互作业。
- 如果你们内部对 `lsf=5` 的含义有固定约定，就以你们的项目模板为准；不同版本或封装层可能会把这个值解释成不同的运行级别。

## 7. FXP 常见脚本用例

### 用例 1：最小 FXP 初始化脚本

适用场景：你第一次把一个 RTL 放进 FXP，想先确认环境、复位和基本流程是否能跑通。

```tcl
set_fml_appmode FXP

analyze -format sverilog -vcs {-f filelist}
elaborate top -sva

create_clock clk -period 100
create_reset rst -sense high

sim_run -stable
sim_save_reset

fxp_generate -name xprop_root -type {uninit out}
fxp_assert -name xprop_root_check {top.out*}

check_fv
report_fv -list
```

这个脚本的目的不是一次性把问题找完，而是先把 FXP 工作链路跑起来。

### 用例 2：从复位后 X 传播开始检查

适用场景：你担心复位解除后某些寄存器仍然带着未知值，并且会进一步污染输出。

```tcl
set_fml_appmode FXP

analyze -format sverilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high

sim_run -stable
fxp_generate -name reset_x_check -type {uninit}
fxp_assume -injectx -name reset_x_check <signal_name>
fxp_assert -name reset_x_check <signal_name>

check_fv
fxp_compute_rootcause reset_x_check
fxp_report_rootcause
```

这个用例适合定位复位域里最容易出现的 X 残留问题。

### 用例 3：对关键输出做 no-X 约束

适用场景：你只关心关键输出是否绝对不能带 X，例如控制输出、协议有效位、关键使能信号。

```tcl
set_fml_appmode FXP

analyze -format sverilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset

fxp_generate -name nox_control_out -type {out}
fxp_assume -nox -name nox_control_out <signal_name>
fxp_assert -name nox_control_out <signal_name>

check_fv
report_fv -verbose
```

这个用例的重点是把“不能出现 X”的区域显式标出来，适合关键控制面检查。

### 用例 4：X 根因定位流程

适用场景：某条 FXP 属性失败了，你已经知道有 X 传播，但还不知道是哪一级逻辑放大的。

```tcl
set_fml_appmode FXP

analyze -format sverilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset

fxp_generate -name rootcause_probe -type {out}
fxp_assert -name rootcause_probe <signal_name>

check_fv
fxp_compute_rootcause rootcause_probe
fxp_report_rootcause
view_trace -property rootcause_probe
```

这个流程适合在你已经拿到失败结果后做深入分析。

## 8. 一个实用的 FXP 工作流

如果目标是快速做一次 X 风险扫描，可以按下面的顺序做：

1. 读入设计并完成 `analyze` 和 `elaborate`。
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
analyze -format sverilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset
fxp_generate [<list-of-scopes>] -name <my_name> -type {<list-of-types>}
fxp_assume -injectx [-name <name>] [-reset] [-oba] [-xassign] [-undef] [-condition <expr>] [-scope <scope_name>] <signal_name>
fxp_assume -nox [-name <name>] [-reset] [condition <condition> [<signal_name>]]
fxp_assert [-name <name>] [-condition <expr>] <signal_name>
check_fv
report_fv -list
fxp_compute_rootcause property
fxp_report_rootcause
view_trace -property property
```

## 11. 小结

FXP 的核心是把未知值 X 的传播路径显式化，然后通过注入、抑制、检查和根因分析，把“可能有风险”变成“哪里有风险、为什么有风险”。它特别适合复位、控制面、选择器、状态机和关键输出路径。

如果你愿意，我可以下一步继续把这份 FXP 手册补成“中文翻译版速查”，或者再单独给你写一版和 FPV 联合使用的 FXP 启动脚本。