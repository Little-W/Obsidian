# VC Formal FPV 使用手册与例子

本文整理 VC Formal 中 FPV 的常用用法。重点不是单条命令，而是把一个可复用的 FPV 工作流串起来：读设计、加断言、定时钟复位、生成 reset state、运行 check_fv、看报告和调试反例。

## 1. FPV 是什么

FPV 是功能属性验证，主要用于证明用户定义的属性、SVA 断言以及和设计行为相关的关键约束。它适合验证接口协议、状态机跳转、异常响应、复位行为和控制逻辑正确性。

从使用方式上看，FPV 是 VC Formal 的基础应用模式。很多其它分析能力都以它为起点，因此通常先把 FPV 环境搭好，再往上叠加 AEP、COV、FXP、CC 之类的检查。

## 2. 什么时候用 FPV

FPV 适合下面这些场景：

- 证明某条协议规则是否永远成立。
- 验证状态机不会进入非法状态。
- 检查复位后关键寄存器和控制信号是否满足预期。
- 对异常路径、边界条件和罕见时序组合做证明。
- 在修改 RTL 后确认行为没有被破坏。

如果你的问题是“这个设计是否满足某条明确的功能规则”，优先考虑 FPV。

## 3. 标准工作流

FPV 的典型流程可以拆成以下几步：

1. 设置 application mode 为 FPV。
2. 读入 RTL 和 SVA。
3. 定义时钟、复位和必要常量。
4. 如果需要，设定 blackbox 或 Assertion IP。
5. 通过仿真或初始化流程生成 reset state。
6. 执行 check_fv 运行验证。
7. 使用 report_fv、view_trace、fvtrace 进行结果分析。

这条链路的关键不是“先跑起来”，而是“先把验证起点定义对”。时钟、复位和初始状态不对，后面得到的证明结果通常也不可靠。

## 4. 最小可用脚本

下面是一段常见的 FPV 起步脚本，适合新设计第一次接入 VC Formal 时使用。

```tcl
set_fml_appmode FPV

set design traffic

read_file -top $design -format sverilog -sva \
    -vcs {-f ../design/filelist +define+INLINE_SVA ../sva/traffic.sva}

create_clock clk -period 100
create_reset rst -sense high

sim_run -stable
sim_save_reset

check_fv
report_fv -list
```

这段脚本的作用是：

- 把工具切到 FPV 模式。
- 读入设计和断言。
- 明确时钟和复位。
- 保存 reset state。
- 直接开始正式验证。

## 5. 常用命令说明

### 5.1 设置模式

```tcl
set_fml_appmode FPV
```

把 VC Formal 切到功能属性验证模式。FPV 的很多默认行为、变量和流程都以此为前提。

### 5.2 读入设计

```tcl
read_file -top top -sva -format verilog -vcs {-f filelist}
analyze -format verilog -vcs {-f filelist}
elaborate top -sva
```

这三种方式里，`read_file` 是最常用的一站式入口，`analyze` 和 `elaborate` 更适合你想把编译和展开步骤拆开控制的场景。

### 5.3 定义时钟和复位

```tcl
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
```

时钟和复位是 FPV 的基础。没有定义清楚它们，很多属性会因为初始状态不完整而出现误判。

### 5.4 生成 reset state

```tcl
sim_run -stable
sim_force SCAN_EN -apply 1'b1
sim_run 3 -clk clk
sim_set_state -uninitialized -user_only -apply 0
sim_save_reset
```

这一步的目的，是让设计进入一个稳定且可重复的起始状态，方便后续证明和反例复现。

### 5.5 运行和报告

```tcl
check_fv
check_fv -stop
check_fv -block
report_fv
report_fv -list
report_fv -verbose
```

`check_fv` 是实际跑验证的入口，`report_fv` 用来查看属性结果、失败原因和状态分类。

### 5.6 调试

```tcl
view_trace -property property
fvtrace -property property
```

反例出来后，优先看触发路径、约束是否过弱、属性是否过强，以及设计是否存在真实 bug。

## 6. 使用例子

### 例子 1：Verilog + SVA 的最小 FPV

适用场景：你已经有 RTL 和 SVA，想快速验证某个模块。

```tcl
set_fml_appmode FPV

read_file -top arb -sva -format sverilog -vcs {
    arb.v
    arb.sva
    arb_bind.v
}

create_clock clk -period 10
create_reset rst -sense high

sim_run -stable
sim_save_reset

check_fv
report_fv -list
```

这个例子的重点是把设计、断言、时钟和复位一次性接起来，然后直接看属性结果。

### 例子 2：只验证一条关键属性

适用场景：你不想先跑整个属性集，只想确认某条属性是否可证。

```tcl
set_fml_appmode FPV

read_file -top top -sva -format sverilog -vcs {-f filelist}
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset

fvdisable -usage {assert cover}
fvenable my_protocol_property
check_fv
report_fv -list
```

这个例子适合单属性调试。先把范围缩小，再排查属性本身和约束是否正确。

### 例子 3：检查复位后行为

适用场景：你关心的不是运行中路径，而是复位后关键寄存器和状态是否满足要求。

```tcl
set_fml_appmode FPV

read_file -top top -sva -format verilog -vcs {-f filelist}
create_clock clk -period 100
create_reset rst -sense high

sim_run -stable
sim_save_reset

check_fv -run_finish {report_fv -verbose}
```

这个例子常用于启动流程、复位释放流程和初始化行为检查。

### 例子 4：失败属性的调试流程

适用场景：`check_fv` 失败了，你想快速判断是设计 bug、环境假设缺失还是属性写法不合适。

```tcl
report_fv -list
view_trace -property my_failed_property
fvtrace -property my_failed_property
```

看反例时优先问三个问题：

- 属性前提是否写全了。
- 约束是否太弱，导致工具走到了不该走的路径。
- 设计本身是否真的违背了规格。

### 例子 5：结合 Assertion IP

适用场景：项目里已经有现成协议包或 Assertion IP，可以直接复用。

```tcl
set_fml_appmode FPV

aip_load -protocol "AHB AXI5"
read_file -top top -sva -format verilog -vcs {-f filelist}
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset
check_fv
```

这个例子适合总线协议、标准接口和可复用断言库的场景。

## 7. 常见问题

### 7.1 证明结果不稳定

优先检查时钟、复位、初始状态和约束。很多“不稳定”的结果，其实是初始化条件没有定义完整。

### 7.2 一直出现反例

先区分三种情况：设计 bug、约束缺失、属性过强。如果不先分清，修错方向会偏掉。

### 7.3 属性太多，跑得慢

先从关键属性开始，再逐步扩大范围。必要时用更精确的属性管理命令把验证范围收窄。

### 7.4 只想看流程是否搭对

先确认 `set_fml_appmode FPV`、`read_file`、`create_clock`、`create_reset` 和 `sim_save_reset` 这五步是否完整。

## 8. 命令速查

```tcl
set_fml_appmode FPV
read_file -top top -sva -format verilog -vcs {-f filelist}
analyze -format verilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
sim_run -stable
sim_save_reset
check_fv
report_fv -list
view_trace -property property
fvtrace -property property
```

## 9. 小结

FPV 的核心不是某一个命令，而是一条固定的验证链路：把设计和断言读进来，把时钟和复位定义清楚，把 reset state 建好，再运行 check_fv 并用 report_fv 和 trace 工具调试结果。

如果你已经有 AEP、COV 或其它应用的笔记，这份 FPV 笔记可以作为基础入口，后续所有应用都能沿着这条初始化链路扩展。