# FCA：形式覆盖率分析完整指南

> **源码内嵌版。** 本章的完整案例以“保存为”标明文件路径，并在下方直接列出全文。代码框不带显示行号，可直接复制；`案例工程/` 只表示目录结构，不要求另找源码附件。包含占位符或保护性 `error` 的专用流程另行明确标为模板。

> **第 9 册 · 专用应用**　Formal Coverage Analyzer。依据 User Guide 第 11 章（第 386～443 页），Quick Reference Guide FCA 部分。**重要：该版本 User Guide 使用 Tcl 模式 `COV`，而应用名称缩写为 FCA。**

## 1. FCA 与 FPV 的区别

FPV 证明某一条属性是否成立；FCA 侧重理解覆盖目标的可达性，帮助分析仿真中未覆盖的代码和功能点是否在现有约束下真正不可能触发。典型情况：随机回归得到某分支从未执行，是因为测试不够、环境限制过严，还是这个分支从设计初始状态根本不可到达？FCA 可以在适当的逻辑模型中研究可达性，并为覆盖率排除提出依据。

FCA 的结果与 VCS 的覆盖数据通常相配合，常涉及 `simv.vdb`、排除文件 `.el` 和 `save_covdb` 产生的覆盖数据库。**不是所有未覆盖都应该豁免**，覆盖目标在形式模型下不可到达，也不代表目标一定不对应产品真实行为；模型和假设可能过度限制。

## 2. 支持的主要覆盖对象

| 覆盖类型 | 检查内容 | 典型缺陷或用途 |
|---|---|---|
| Line | 行覆盖目标是否可能执行 | 死代码或条件永不满足 |
| Branch | if/case 分支是否可能发生 | 分支遗漏、错误优先级 |
| Condition | 布尔条件组合是否可到达 | 测试缺失或过度约束 |
| Toggle | 位信号 0↔1 翻转可达性 | 模式控制/死信号 |
| FSM | 状态及状态转移是否可达 | 死状态和隐藏转移 |
| Functional coverage（视版本与模型） | 覆盖组定义的目标 | 需确认模型、绑定与有效条件 |

不同覆盖目标的生成与排除规则并不完全相同。某些类型还需要额外变量启用，例如 `set_fml_var fml_cov_enable_branch_cov true`。

## 3. 第一个 FCA 用例：输入条件与代码分支可达性

### 3.1 完整设计源码

本例没有限制 `mode`，因此四种输入组合都允许出现。分析其可达性不是预先宣布某个分支不可到达。

**保存为 `案例工程/rtl/coverage_demo.sv`：**

<!-- source-begin: 案例工程/rtl/coverage_demo.sv -->

```systemverilog
// FCA exercise: branch conditions and reachability.
// mode is intentionally unconstrained, unless the verification environment
// supplies an explicitly reviewed operating-mode assumption.
module coverage_demo (
  input  logic       clk,
  input  logic       rst_n,
  input  logic [1:0] mode,
  output logic [1:0] result
);
  always_comb begin
    result = 2'd0;
    case (mode)
      2'd0: result = 2'd1;
      2'd1: result = 2'd2;
      2'd2: result = 2'd3;
      default: result = 2'd0;
    endcase
  end
endmodule
```

<!-- source-end -->

如果真实系统规范要求 `mode[1]` 恒为零，另外两个模式在该约束下才不可达；必须记录约束出处，并区分真实限制与为了提高覆盖数字而新增的假设。组合分支能否保留并产生检查，还受编译优化和覆盖类型配置影响。

### 3.2 完整文件列表



**保存为 `案例工程/filelist_fca.f`：**

<!-- source-begin: 案例工程/filelist_fca.f -->

```text
./rtl/coverage_demo.sv
```

<!-- source-end -->

## 4. 主要流程：完整 Tcl

### 4.1 完整运行脚本

此版本按 User Guide 使用 `COV` 模式。脚本保留检查设置和结果报告；没有在未审查结果时自动把所有未完成目标导出为排除项。

**保存为 `案例工程/scripts/fca_coverage.tcl`：**

<!-- source-begin: 案例工程/scripts/fca_coverage.tcl -->

```tcl
# Formal Coverage Analyzer uses COV appmode in X-2025.06-SP1 User Guide.
# Run from example project root; treat result as tool-dependent.
set_fml_appmode COV
read_file -top coverage_demo -format sverilog -cov all -vcs {-f filelist_fca.f}
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
vcf -f scripts/fca_coverage.tcl -batch 2>&1 | tee logs/fca_coverage.log
```

这些命令应在本机具备相应 VC Formal 版本和许可证时执行。日志中的属性状态才是证明结论；命令退出、脚本结束或没有打印错误都不能代替属性结果检查。

需要导出经过审查的不可达候选时，再按实际会话执行：

```tcl
save_cov_exclusion -file formal_unreachable.el
```

`-cov all` 的覆盖类型仍须核对版本，某些类型有单独的启用变量。应先确认生成了哪些目标、目标数量以及实际完成状态，再解释覆盖率或排除文件。

## 5. 从仿真数据库开始

```tcl
set_fml_appmode COV
read_covdb -cov_input simv.vdb -cov_dut tb.dut
read_file -top dut -format sverilog -cov all -vcs {-f filelist.f}
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
check_fv -block
save_covdb -status covered -name formal_result.vdb
save_cov_exclusion -file candidate_exclusion.el
```

`-cov_dut` 必须是仿真数据库中的真实 DUT 实例路径。若层级不匹配，生成的排除记录可能关联错误。UG 第 395 页说明，无仿真数据库时的排除对象与有仿真数据库时的层级来源不同；最终在覆盖可视化工具中导入 `.el` 之前需要确认层级。

## 6. 命令分类

| 命令 | 作用 |
|---|---|
| `set_fml_appmode COV` | 选择 User Guide 认可的覆盖应用 Tcl 模式 |
| `read_covdb -cov_input ...` | 导入仿真覆盖数据库 |
| `read_file ... -cov ...` | 为指定类型创建覆盖目标 |
| `check_fv` | 对目标做形式检查 |
| `report_fv -verbose` | 显示覆盖检查状态 |
| `save_cov_exclusion -file ...` | 导出候选不可达排除说明 |
| `save_covdb -status covered -name ...` | 保存覆盖状态结果 |
| `view_coverage` | 打开覆盖查看界面 |
| `cov_config -auto_scale` | 配置自动分配覆盖分析任务 |
| `compute_cov` | 启动有关覆盖计算流程 |
| `cov_config -line_task/-tgl_task ...` | 调整各类型任务比例 |

## 7. Auto Scale 及资源策略

当覆盖目标数量巨大时，FCA 可自动划分多个覆盖类型和模块任务。先运行一个小范围测试估计内存与每类目标的数量，再考虑 `cov_config -auto_scale`、`-line_task`、`-fsm_task`、`-tgl_task` 等参数。不要在不了解网格队列和许可证预算的情况下照搬快速指南中几十或上百个 worker 的示例。汇总结果时，应说明每一类型完成、不可达和未完成的数量。

## 8. 排除文件需要审查

“不可达”至少可能来自三种情形：设计逻辑确实使其不可达；复位/环境约束使其不可达；模型存在缺失使其无法触发。前者可能是冗余 RTL，也可能是特定配置下合法不可达；后两者则不能简单纳入永久覆盖排除。建议每条排除记录带上规格版本、环境限制和审批人。

一个完整的报告应区分仿真原始覆盖率、形式分析发现的不可达目标、审查后允许排除的目标、仍需增加激励的可达目标。不能把形式分析结果当成单纯提高覆盖率百分比的手段。

## 9. 常见排查

| 现象 | 检查事项 |
|---|---|
| 无覆盖属性 | `-cov` 类型、模式、文件展开、分支额外开关 |
| 导出的排除文件和仿真层级不一致 | `-cov_dut`、顶层名、编译优化 |
| 许多目标显示不可达 | 复位、环境常量、黑盒与约束 |
| 计算耗时非常长 | 按模块、覆盖类型拆分任务；使用 Auto Scale |
| `.el` 无法被查看器识别 | 数据库版本和导入路径 |

## 10. 命名差异和官方参考

X-2025.06-SP1 版本的 Quick Reference Guide 使用 `set_fml_appmode FCA`，但 User Guide §2（65 页）及 §11.2.2（395 页）使用 `set_fml_appmode COV`。本手册选择 User Guide 的 `COV` 作为示例；安装环境如存在别名或不同版本行为，以 `set_fml_appmode -help` 和 `get_fml_appmode` 确认为准。资料：User Guide 第 11 章及 Quick Reference Guide FCA 页。
