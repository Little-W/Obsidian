# AEP：自动提取属性应用完整指南

> **第 6 册 · 专用应用**　Automatically Extracted Properties。依据 User Guide 第 10 章（第 362～385 页）与 Quick Reference Guide 的 AEP 部分。

## 1. AEP 的角色与应用价值

AEP 不需要用户先手工写出每一条 SVA，就能从 RTL 结构和编码方式中自动推导一批易引发功能问题的条件，并将其交给形式引擎检查。适用于新接入 IP、第三方 RTL、复杂状态机、溢出与数组访问风险排查，以及验证项目启动阶段的快速质量筛查。

AEP **不等于自动证明全部功能规格**。它擅长发现通用的实现错误（越界、算术溢出、状态机问题、三态冲突、一些不完整分支等），但不会知道客户要求某个控制寄存器在第几个周期复位，也不会自动理解外部协议的最终响应期限。经 AEP 筛查后仍需补充 FPV 业务属性。

## 2. AEP 的典型检查项目

| AEP 类型 | `-aep` 选择值（按 User Guide） | 要检查的危险行为 | 例子 |
|---|---|---|---|
| 数组越界 | `bounds_check` | 索引超出声明范围 | 深度为 2 的数组访问索引 3 |
| 算术溢出 | `arith_oflow` | 运算结果超过目标表达能力 | 较窄寄存器接收宽加法结果 |
| 移位溢出 | `shift_oflow` | 移位导致有效位全部移出 | 1 位左操作数移位 2 位 |
| 类型转换溢出 | `cast_oflow` | 转换后的有效位损失 | 带符号操作转换到窄寄存器 |
| 悬空三态总线 | `floating_bus` | 所有三态驱动均未启用 | 所有 `oe` 均为 0 |
| 多驱动三态总线 | `multi_driver` | 多个驱动同时有效 | `oe0` 与 `oe1` 同时为 1 |
| 分支覆盖完整性 | `full_case` | case/if 组合未完整覆盖 | 没有 default 的分支遗漏 |
| 并行分支互斥 | `parallel_case` | 多分支同时匹配 | 重叠编码引起优先级问题 |
| 置位/复位问题 | `set_reset` | 相关控制状态及赋值组合危险 | 置位与复位同时发生 |
| 未知值赋值 | `x_assign` | 显式 X 进入逻辑 | `assign out = 1'bx` |
| FSM 死锁 | `fsm_deadlock` | 状态无法继续转移 | 没有离开等待状态的路径 |
| FSM 活锁 | `fsm_livelock` | 在循环中反复转移却不完成 | 两状态无限循环 |
| FSM 相关额外检查 | `fsm_unionlock` | 与 FSM 联合锁定相关的规则 | 详见版本帮助 |

表格中的实际生成条件、适用语言和局限需以 UG §10.1.1（第 363～375 页）为准，不是所有检查都支持全部 Verilog、SystemVerilog 与 VHDL 语法。例如 User Guide 对 `cast_oflow` 的 VHDL 支持有单独限制。

## 3. 初学者第一个 AEP 案例：数组越界

```systemverilog
module array_demo (
  input logic clk,
  input logic [1:0] index,
  output logic [7:0] data_out
);
  logic [7:0] mem [0:1];
  always_ff @(posedge clk)
    data_out <= mem[index];
endmodule
```

数组合法索引只有 0 和 1，但 `index` 可以为 2 或 3。若没有真实协议前提禁止非法索引，`bounds_check` 应能够为这样的访问生成检查并可能给出反例。若该端口来自外部用户，设计究竟要“拒绝非法索引”还是“输入协议禁止非法索引”，必须首先由规格明确，然后决定是修 RTL 还是增加**有出处的**环境约束。

## 4. 标准运行步骤

```tcl
set_fml_appmode AEP
read_file -top array_demo -aep bounds_check -format sverilog \
  -vcs {-f filelist_aep.f}
create_clock clk -period 100
check_fv_setup
report_fv -list
check_fv -block
report_fv -verbose
```

真实工程有复位的，应加上 `create_reset` 和必要的初始化序列；上述 `array_demo` 刻意只有时钟，突出数组检查的概念。若工具对该语言、数组形式或优化方式没有生成相应属性，先检查 `-aep` 语法与对象是否符合其抽取前提。

### 4.1 多种 AEP 组合

```tcl
read_file -top my_top -aep fsm_deadlock+fsm_livelock \
  -format sverilog -vcs {-f filelist.f}
```

这里的 `+` 表示组合多个检查选择值，是指南中提供的一种常见写法；`-aep all` 并不意味着对每个设计都推荐一开始就开启所有检查。建议先对高优先级逻辑运行小集合，再逐步扩展，以便降低误报排查成本。

### 4.2 VHDL 的相关配置

```tcl
set_app_var fml_enable_vhdl_aep true
set_app_var fml_enable_vhdl_bus_check true
set_app_var fml_enable_vhdl_cov true
```

这些应用变量来自该版本的快速参考，启用前确认当前分析模式确实为 VHDL 且变量在安装版本可用。VHDL 的语言结构与 SystemVerilog 不同，不能假定每一种 AEP 的覆盖条件完全相同。

## 5. 状态机检查：死锁、活锁与公平性

FSM 死锁一般指在给定约束下进入无法合理继续的状态；活锁指能够不停转移却始终不进入完成或期望状态。是否一定算设计缺陷，取决于环境前提：一个等待读取外设的状态如果允许外设永远不响应，可能是系统规格缺失，而非状态机 RTL 必然有错。

```tcl
read_file -top controller -aep fsm_deadlock+fsm_livelock \
  -format sverilog -vcs {-f controller.f}
aep_generate -type fsm_fairness
# 可把候选公平性配置保存为脚本后审查
aep_generate -type fsm_fairness -tcl fairness.tcl
```

生成公平性相关条件时应由系统工程师审查其物理可实现性。例如“不停请求外部总线”并不能保证对方必然授权，除非系统规格明确了调度公平性。

### 5.1 控制某种状态的自动生成

```tcl
aep_config -dont_generate -type fsm_livelock {state_reg::state_name}
```

该指令适用于已确认特定状态的自动生成规则不适当的情况；必须给出关闭原因和关联设计评审。示例 `state_reg::state_name` 只是占位对象，实际名称应从生成属性和设计状态列表取得。不要以大量关闭属性的方式解决真问题。

## 6. AEP 的命令作用与注意事项

| 指令 | 功能 | 注意 |
|---|---|---|
| `set_fml_appmode AEP` | 进入自动属性应用 | 编译前设置 |
| `read_file ... -aep ...` | 指定要从设计抽取的检查类型 | 类型和语言需要对应 |
| `elaborate top -aep ...` | 分步编译流程中生成 AEP | 与 `analyze` 配对 |
| `aep_generate -type fsm_fairness` | 为 FSM 相关检查生成候选公平性设置 | 必须人工审查合理性 |
| `aep_config -dont_generate ...` | 对指定状态或检查关闭自动生成 | 需保存关闭理由 |
| `fvdisable` / `fvenable` | 调整已生成属性是否参加求解 | 不等同于修改 RTL |
| `fvwaive` / `fvunwaive` | 将属性纳入/移出豁免 | 保留变更依据 |
| `check_fv` | 求解启用的自动属性 | 按 `-block` 或报告确认运行完成 |
| `report_fv -verbose` | 检查详细结果 | 分析反例与真正危险性 |
| `save_waiver_file -file aep.el` | 保存豁免清单 | 提交审查版本 |
| `read_waiver_file -elfiles aep.el` | 导入豁免 | 注意 RTL 或属性名变化 |

## 7. 常见问题与处理方案

**问题 A：数组越界属性失败。** 查索引值、数组实际维度、索引来源、是否为非法但允许输入；若设计应该防御非法访问，则修复输入检查和返回行为。**问题 B：`full_case` 告警。** 检查组合分支是否覆盖所有合法编码；若某些编码应视为非法，先明确可达性，不能仅靠注释 `full_case` 掩盖。**问题 C：状态机活锁告警。** 查看反例循环，确认是否需要外设公平假设。**问题 D：属性数为零。** 检查 AEP 开关、RTL 类型和提取范围，不应推断“RTL 不存在问题”。

### 用例：审查豁免

```tcl
fvwaive <property_name>
save_waiver_file -file reviewed_aep.el
```

建议豁免记录独立写明编号、原始现象、为何不是设计缺陷、所依据的系统规格、最后审查日期与责任人。`fvwaive` 只是结果管理，不会使设计行为变正确。

## 8. 推荐的 AEP + FPV 双阶段工作方法

先在整段 RTL 范围运行 AEP 发现基础实现风险；其次针对关键模块编写 FPV 属性以覆盖具体的时序与功能规格。AEP 发现的真缺陷，应补充成可长期回归的手工断言（如果合适）。AEP 发现的假阳性，应检查真实前提并保留说明；不可简单添加 `assume` 让它消失。

对于大型 SoC，可以先针对地址解码、寄存器文件索引、FIFO 状态机、宽窄运算及三态总线使用 AEP。对于自动生成属性无法证明的情况，可单独分组并提升资源，而不是影响所有检查的分析时间。

## 9. 官方参考

User Guide §10：第 362～385 页；§3.5 属性 class 与 type；§7 反例与状态；Quick Reference Guide 的 AEP 章节。本文检查类型的简述为独立归纳，并非逐页复制官方表格。
