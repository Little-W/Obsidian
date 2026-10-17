# FuSa：功能安全形式分析完整指南

> **第 13 册 · 专用应用**　Functional Safety。依据 User Guide 第 23 章（第 1009～1039 页），Quick Reference Guide FuSa 部分。与 FTA 的目的不同：FuSa 对故障的可控性、可观察性、检测路径等进行安全分析，输出可以参与功能安全分析报告的数据。

## 1. 场景与关键概念

面向汽车、工业控制或其他要求功能安全的芯片，故障不仅要判断“是否存在”，还需分析在规定运行状态下可能带来什么影响，是否可以通过硬件检测机制观察到。FuSa 与故障数据库和 Z01X 等工具协同，可按故障可控性、可观察性、检测能力分类，为 FMEDA（失效模式、影响及诊断分析）提供支持。

**可控性**：是否可能在允许的输入/状态下触发相关故障影响；**可观察性**：故障差异是否可能传播到指定观察点；**可检测性**：预定诊断机制是否能检测到故障。三者相关但不同。不能把“故障可观察”直接写成“已经被安全机制检测”。

## 2. 前置要求和故障输入

据 UG 第 1015～1016 页，准备 FuSa 前应先具备无关键设置问题的 FPV 环境；故障定义可以来自 Standard Fault Format（SFF）或统一故障数据库（FDB），还需提供观察点、检测点及有关常量前提。工具版本和故障数据库版本应保持兼容。

典型资料包括：RTL、参数配置、故障清单、正确的时钟复位与初始化、合法运行模式的定义、观察/检测节点列表。若观察点设错，即使故障在真实系统中危险也可能被错误分类。

## 3. 四类分析

| 分析类别 | 目标 | 可能的误解 |
|---|---|---|
| 结构分析（Structural） | 初步查看故障与观察/检测点的结构关系 | 有结构路径不代表一定可传播 |
| 可控性分析（Control） | 检查是否能激活相应故障效应 | 不可控可能受环境约束影响 |
| 可观察性分析（Observe） | 研究故障效应是否到达观察端 | 到达观察端不代表诊断会报警 |
| 可检测性分析（Detection） | 判断指定检测机制是否响应 | 取决于指定检测点和时序规则 |

UG 23.1.1 给出结构、可控性、可观察性及检测分析。不同模式的输出状态不应混合汇总，尤其不能把“结构排除”当成已经对完整工作状态进行了所有逻辑分析。

## 4. 标准脚本结构

```tcl
set_fml_appmode FUSA
# 先配置故障清单，后读入设计
fusa_config -sff faults.sff
# 或者结合 FDB 设置，具体数据库名与路径按项目确定
# fusa_config -fdb_campaign my_campaign
read_file -top safety_top -format sverilog -vcs {-f filelist.f}
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
fusa_observation -add safety_output
fusa_detection -add alarm
fusa_generate
set_fml_var fusa_run_mode structural
check_fv -block
fusa_report
```

在这个教学骨架中，`faults.sff`、`safety_output`、`alarm` 是必须由实际故障清单和 RTL 替换的对象。正式项目应先在 FPV 环境完成 `check_fv_setup -block` 等准备核查，并了解 UG 关于正式 FuSa 重复执行这些检查的性能提示。

## 5. 逐步提高分析精度

```tcl
set_fml_var fusa_run_mode structural
check_fv -block
set_fml_var fusa_run_mode control
check_fv -block
set_fml_var fusa_run_mode observe
check_fv -block
```

执行不同分析阶段时，需要使用每阶段生成的故障类别并保存结果。某些版本或项目中还需专用的检测配置，不能仅凭这三条命令推断完整 FMEDA 已经生成。阅读该安装版本的 `fusa_config -help`、`fusa_generate -help`、`fusa_report -help`。

## 6. 核心命令说明

| 命令 | 功能 | 重点 |
|---|---|---|
| `fusa_config -sff ...` | 导入标准故障描述 | 故障实例路径匹配 |
| `fusa_config -fdb ...` | 配置统一故障数据库 | 项目名称与服务器路径 |
| `fusa_observation -add ...` | 指定观测节点 | 与 FMEDA 分析目标对应 |
| `fusa_detection -add ...` | 指定诊断检测节点 | 区分系统输出和安全报警 |
| `fusa_blackbox ...` | 针对分析进行适当黑盒设置 | 应评估故障排除的影响 |
| `fusa_generate` | 创建功能安全分析对象 | 输入的故障清单必须有效 |
| `set_fml_var fusa_run_mode ...` | 选择分析阶段 | 结构、控制、观察等按需运行 |
| `fusa_report_total_faults` | 汇总故障数量 | 注意分母是否包含排除故障 |
| `fusa_report -all_failure_modes` | 按模式输出故障结果 | 区分状态类别 |
| `fusa_save` / `fusa_save -sff ...` | 保存分类结果 | 供后续流程复用 |

## 7. 案例：带奇偶校验的安全寄存器

一个重要配置寄存器使用奇偶校验位，写入时更新校验；读取/使用时，如果校验与数据不一致则拉高 `alarm`。可以指定寄存器数据寄存器及校验位中的故障为分析对象，把 `alarm` 作为检测点，关键输出作为观察点。分析时区分：故障是否真正改变了数据；改变是否到达输出；奇偶校验是否在规定时延内报警。即使一个故障未影响输出，也不能把其他故障的检测结果套用在它身上。

## 8. 与 ISO 26262 / FMEDA 的关系

FuSa 分析结果可作为硬件随机故障指标评估的一部分，但不能仅凭工具中的一个百分比就认定达到某 ASIL 等级。功能安全还涉及故障模型、故障率来源、诊断间隔、残余风险、独立性、系统级失效影响和安全机制完整性。所有故障分类以及能够被排除的对象应由功能安全负责人审查。

## 9. 常见错误

- 故障数据与 RTL 层级不一致，使部分故障没有真正进入分析。
- 未先校验时钟复位及模式常量，造成大量虚假的不可控。
- 观察点或检测点过少，使报告过于乐观或不完整。
- 将可观察与已检测、未完成与不可达混同。
- 把结构分析结果视作所有故障的最终证明。

## 10. 官方资料

User Guide §23（1009～1039 页）、§4（初始化）、§6（结果控制）；如涉及数据库交互，应同时参照 Z01X / FDB 的相同软件版本文档。
