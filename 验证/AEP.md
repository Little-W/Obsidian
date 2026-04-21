# VC Formal 手册中的 AEP 用法整理

本文根据《VC Formal User Guide》里与 AEP 相关的章节整理而成，重点覆盖属性分类、快速配置、VHDL 场景、设计检查与 trace check 的用法。对应内容主要分布在手册第 107-108、116-119、165-169 页附近。

## 1. AEP 是什么

从手册上下文看，AEP 是 VC Formal 中的一类属性和检查分类。它既可以出现在属性管理命令里，也可以出现在 quick start、设计检查和 trace check 相关配置中。

手册里最直接的信号是：

- `get_props` 的 `-class` 选项支持 `aep`
- `fvassert -class aep *` 可以只启用 AEP class 的属性
- `fv_quickstart` 里包含若干 AEP 相关默认项
- `check_fv_setup` 会检查 AEP 类结构问题
- `fvtrace_config` 支持 `aepnode` 这类 trace check

## 2. 属性层面的 AEP 用法

手册在“Managing Constraints and Properties”这一章里强调：

- `usage` 属性只取 `cover`、`assert`、`assume` 三种值
- `check_fv` 系列命令只作用于 enabled 的属性
- 被禁用的属性仍会保留状态信息，并出现在 `report_fv` 的 Unused 类别中

与 AEP 相关的典型操作是：先关掉不需要的检查，再只保留 AEP class 属性。

```tcl
fvdisable -usage {assert cover}
fvassert -class aep *
```

这组命令的含义是：

- 先禁用普通 assert / cover 检查
- 再把 AEP class 的属性重新打开
- 适用于只想聚焦 AEP 相关约束或属性的场景

如果你只是想查看当前设计里有哪些 AEP 属性，可以用：

```tcl
get_props -class aep
```

## 3. Quick Start 里的 AEP 选项

手册在 `fv_quickstart` 章节列出了几个 AEP 相关的默认配置项：

- `aep_unique_name`
- `aep_vhdl`
- `aep_vhdl_bus_check`

其中，`fv_quickstart -enable default` 默认就会打开一组推荐配置，AEP 相关项也包含在内。

### 3.1 什么时候用

建议在新设计初次接入 VC Formal 时先开 quick start，再根据结果决定是否保留默认设置或手工关闭部分项。手册也说明了：

- quick start 会自动处理 inferencing、black box、abstraction、clock edge、compile option 等设置
- 它适合初次导入设计，或者收敛变差时用来缩小剩余问题范围

### 3.2 一个要注意的点

手册特别提醒：`fv_quickstart` 和 `set_fml_appmode` 的调用顺序会影响实际应用的设置。

简化理解就是：

- 先调用 `fv_quickstart`，再切 application mode，会应用 FPV 侧设置
- 先切 `set_fml_appmode SEQ`，再调用 `fv_quickstart`，会应用 SEQ 侧设置

## 4. VHDL 场景下的 AEP 运行方式

手册给出的结论很直接：AEP 支持 VHDL。

推荐流程是：

1. 将 application mode 切到 AEP
2. 通过 `set_app_var` 打开 AEP checks
3. 使用 `-aep all` 跑完整的 AEP 检查

手册原意是：在 VHDL 场景中，AEP 检查可以和普通的 `read_file` / `analyze` / `elaborate` 流程结合使用。

如果你在做单步编译，手册同时提到：

- Verilog / SVA 可以用 `read_file -format sverilog -sva ...`
- VHDL 也可以用 `read_file -format vhdl ...`
- AEP、FPV、COV 都可以挂在这条流程上

## 5. 设计检查里的 AEP

在 `check_fv_setup` 相关章节里，手册说明了 VC Formal 会检查一些结构类问题，其中就包括 AEPs。

这里最值得关注的是“Feedback Loop AEPs”：

- 工具会自动切断反馈环并赋予符号值
- 然后将组合环展开若干次
- 如果环路真正收敛，切点的符号值不会影响环内网表值
- 如果环路不收敛，通常会在 counter-example 里看到切点与输入值发散

这类 AEP 更像是设计建模阶段的结构告警，不是业务属性本身。

### 5.1 这类问题怎么理解

一个典型例子是组合环路：

- 如果展开后输入已经收敛，但输出仍然异常，就说明这个环路可能不稳定
- 这类结果通常值得回到 RTL 或约束里进一步检查

## 6. Trace check 里的 AEP

手册在 trace check 章节里列出了若干 trace 类型，其中有 `aepnode`。

`aepnode` 的含义是：

- 数组边界越界导致的未定义
- 工具可以把这类问题作为 trace check 来追踪

配置示例：

```tcl
fvtrace_config -check aepnode -autorun viewtrace -severity high
```

再配合：

```tcl
fvtrace_check <property_name>
```

你就可以在 Debug mode 里看到 property trace、波形和状态图标，定位具体问题。

## 7. 一个实用的 AEP 工作流

如果目标是“只看 AEP 相关内容”，可以按下面的顺序做：

1. 读入设计并完成 `read_file`、`analyze` 或 `elaborate`
2. 用 `fv_quickstart` 保留 AEP 相关默认配置
3. 用 `fvdisable -usage {assert cover}` 清掉不相关检查
4. 用 `fvassert -class aep *` 只保留 AEP class
5. 用 `get_props -class aep` 检查当前属性集合
6. 跑 `check_fv_setup` 看结构类 AEP
7. 必要时用 `fvtrace_config -check aepnode ...` 做 trace 定位

## 8. AEP 使用用例

下面这些用例更贴近实际使用场景，适合把 AEP 当成一套工作流来用，而不是只记单条命令。

### 用例 1：只筛选 AEP class 属性

适用场景：你想暂时屏蔽普通 assert / cover，只看 AEP 相关属性是否存在、是否启用。

```tcl
fvdisable -usage {assert cover}
fvassert -class aep *
get_props -class aep
```

这个用例的目的很明确：把关注点收缩到 AEP class，便于排查约束是否加载正确，或者验证 AEP 相关属性是否被误关。

### 用例 2：VHDL 设计的 AEP 快速检查

适用场景：你的设计是 VHDL，希望快速确认 AEP 相关检查是否能正常跑通。

```tcl
fv_quickstart -enable default
set_fml_appmode AEP
read_file -format vhdl -top <top> -vcs "<files>"
```

这个用例的关键不是某一条命令，而是把 AEP 相关默认配置、VHDL 读入和 application mode 对齐。实际工程里，AEP checks 通常由项目脚本或现有环境变量开启，手册明确说明 AEP 支持 VHDL。

### 用例 3：检查反馈环类 AEP 问题

适用场景：`check_fv_setup` 报了反馈环或类似结构问题，你需要判断这是可接受的收敛环，还是不收敛的设计缺陷。

```tcl
check_fv_setup
```

观察重点：

- 如果反馈环收敛，切点符号值一般不会污染环内网表值
- 如果不收敛，counter-example 往往能看到切点与输入值发散

这个用例更适合在接入新 RTL、修改组合逻辑、或者做结构健康检查时使用。

### 用例 4：追踪 aepnode 类型问题

适用场景：你怀疑存在数组越界、边界非法访问或者相关的 undefined 问题，需要进一步定位到 property trace。

```tcl
fvtrace_config -check aepnode -autorun viewtrace -severity high
fvtrace_check <property_name>
```

这个用例的价值在于把问题从“报错”推进到“定位”：先让 trace check 自动运行，再在 Debug mode 里看波形和状态信息。

### 用例 5：把 AEP 用作一条最小验证链路

适用场景：你只想快速搭出一条最小闭环，确认 AEP 相关能力是否可用。

```tcl
fv_quickstart -enable default
fvdisable -usage {assert cover}
fvassert -class aep *
get_props -class aep
check_fv_setup
fvtrace_config -check aepnode -autorun viewtrace -severity high
```

这条链路的顺序是有意义的：先收窄属性，再做结构检查，最后用 trace 定位。

## 9. AEP 示例脚本

下面给出 3 个常用的 AEP 脚本模板，分别对应属性筛选、VHDL 场景和 trace 定位。

### 脚本 1：最小 AEP 属性筛选脚本

适用场景：你想先确认当前设计里是否已经正确加载 AEP class 属性，并且只看 AEP 相关目标。

```tcl
set_fml_appmode AEP

read_file -top top -format sverilog -sva -vcs {-f filelist}

fvdisable -usage {assert cover}
fvassert -class aep *
get_props -class aep

check_fv_setup
report_fv -list
```

这个脚本的重点是先把普通 assert / cover 收窄掉，只保留 AEP class，然后用 `get_props` 和 `check_fv_setup` 看结果。

### 脚本 2：VHDL AEP 初始化脚本

适用场景：你的 DUT 是 VHDL，希望快速把 AEP 的运行链路跑通。

```tcl
set_fml_appmode AEP

read_file -top top -format vhdl -vcs {-f filelist}
analyze -format vhdl -vcs {-f filelist}
elaborate top

fvdisable -usage {assert cover}
fvassert -class aep *

check_fv_setup
report_fv -verbose
```

这个脚本适合先验证 VHDL 读入、展开和 AEP class 是否能正常工作。实际工程里，AEP 的额外开关通常由项目脚本统一配置。

### 脚本 3：AEP trace 定位脚本

适用场景：`check_fv_setup` 或 AEP 相关检查报出了 `aepnode` 一类问题，你希望进一步定位到具体 trace。

```tcl
set_fml_appmode AEP

read_file -top top -format sverilog -sva -vcs {-f filelist}

fvtrace_config -check aepnode -autorun viewtrace -severity high
check_fv_setup
fvtrace_check <property_name>
view_trace -property <property_name>
```

这个脚本把 `aepnode` 的 trace 检查、property trace 和波形查看串在一起，适合做问题定位。

## 10. 命令速查

```tcl
get_props -class aep
fvdisable -usage {assert cover}
fvassert -class aep *
fv_quickstart -enable default
fvtrace_config -check aepnode -autorun viewtrace -severity high
fvtrace_check <property_name>
```

## 11. 结论

AEP 在 VC Formal 里不是单一命令，而是一组围绕属性、编译配置、设计检查和 trace 定位展开的能力集合。真正落地时，最常用的切入点是：

- 用 `get_props` / `fvassert -class aep *` 管属性
- 用 `fv_quickstart` 管默认编译和 AEP 相关开关
- 用 `check_fv_setup` 看结构类 AEP
- 用 `fvtrace_config` / `fvtrace_check` 定位问题

如果后面你希望，我可以继续把这份笔记扩展成“VC Formal 常用命令速查版”，或者把 AEP 相关章节再整理成更偏“中文翻译”的逐段对照版。
