# FTA：形式测试平台分析完整指南

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

## 5. 故障分类与结果含义

| 场景 | 工程解释 | 后续建议 |
|---|---|---|
| 故障被属性检出 | 当前断言对该类改变敏感 | 检查检出的属性是否符合预期 |
| 故障未检出 | 可能是死代码、影响不可达、属性缺失或环境屏蔽 | 先审查可达性和影响路径 |
| 注入无法激活 | 故障点在现有环境下不被触发 | 检查约束及故障定义 |
| 结果未完成 | 当前证明资源不足 | 提升策略或缩小任务 |
| 被审查豁免 | 有外部充分证据认定不需要该项 | 记录依据并保留原结果 |

检出率与业务规格覆盖完整程度相关，但不能直接等同于“芯片功能正确的百分比”。

## 6. 关键命令及用途

| 命令 | 用途 |
|---|---|
| `fta_init` | 初始化 FTA 所需数据结构和分析 |
| `configure_fta_props` | 选择待评估的属性集合和条件 |
| `compute_fta -par_task FPV` | 基于已准备的 FPV task 开展 FTA 分析 |
| `fta_report -instance ...` | 按实例报告 FTA 状态 |
| `get_fta_faults` | 查询所考虑的注入故障 |
| `get_activated_props` | 对故障查询有激活关系的属性 |
| `cluster_fta_faults` | 将故障进行分组以方便分析 |
| `report_fta_fault_clusters` | 输出故障分组结果 |
| `export_fault` | 导出选中的故障信息 |
| `debug_fta` | 启动或准备专用调试 |
| `read_fta_waiver` | 导入经过审查的豁免 |

## 7. 两个评估示例

**例一：FIFO 缺少溢出断言。** 只写了 FIFO 空闲和复位属性，注入“满时仍接受写入”的 RTL 改变，可能不被检出。补充 `occupancy <= DEPTH`、接受写入时机等断言，重新比较检测结果。**例二：状态机错误状态转换。** 只检查状态编码合法性，状态从 `WAIT` 错误跳到 `IDLE` 仍可能保持编码合法，却违反协议。FTA 可以促使增加状态转移规则与完成覆盖。

## 8. FTA 与故障仿真的区别

FTA 使用形式分析寻找能够触发和传播注入差异的逻辑证据；故障仿真通常依赖已准备的激励序列。两者都可用来研究测试平台质量，但对状态空间、收敛条件、故障模型和资源需求的依赖不同。FTA 的故障并不等同于制造测试的 stuck-at / transition ATPG 故障模型。

## 9. 参考

User Guide 第 21 章，尤其多阶段运行、故障注入、结果调试与性能部分；User Guide 第 20 章的最终验证质量评估方法。
