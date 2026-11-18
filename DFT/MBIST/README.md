# MBIST 设计架构与方法

本手册将存储器故障、March 测试序列、算法生成和系统实现放在同一套文档中介绍。正文包括 **1 份总览、12 份专题与 3 份附录**，附带可编辑 SVG、PNG、离线网页和可运行算例。

**开始阅读：[MBIST总体架构与阅读导航](00_MBIST总体架构与阅读导航.md)**

**浏览器阅读：[阅读入口.html](阅读入口.html)**。公式已经转换为数学矢量图，页面与插图均可离线查看。Markdown 是可编辑正文。

## 故障与算法阅读路线

| 阅读目标 | 章节 | 主要内容 |
|---|---|---|
| 理解一次操作怎样激活并检出故障 | [02_故障模型与检测原理](02_故障模型与检测原理.md) | 故障原型、单元状态、局部序列、逐次读取结果和近期故障模型 |
| 理解地址方向与 March 元素 | [03_March基础与经典算法](03_March基础与经典算法.md) | 完整序列、逐阶段作用、地址关系与长度计算 |
| 学习增强与多背景测试 | [04_增强March与复杂故障测试](04_增强March与复杂故障测试.md) | SS、AB、AZ、Dynamic-RAWC，以及三、四、五单元测试的完整生成规则 |
| 学习自动生成测试序列 | [05_测试算法生成与选择](05_测试算法生成与选择.md) | 欧拉回路、历史状态、集合覆盖、元启发算法、MarchGen和互补测试学习 |
| 学习透明测试与数据恢复 | [08_自适应与运行期间测试](08_自适应与运行期间测试.md) | 双地址序列、局部互补比较、初末签名与数据恢复 |
| 扩展至其他存储技术 | [11_多端口与新型存储器扩展](11_多端口与新型存储器扩展.md) | 多端口、DRAM、FeRAM、STT-MRAM、RRAM及存储器内部计算 |
| 按故障查找完整序列 | [14_故障模型与测试序列索引](14_故障模型与测试序列索引.md) | 前置状态、激活、观察、算法长度、地址与背景要求 |
| 运行与核对算例 | [13_算例与源码说明](13_算例与源码说明.md) | 故障注入、背景遍历、搜索结果、程序入口和检查范围 |

各算法分别给出方向、初始化、操作顺序、期望读值、适用故障与操作次数。论文算法和本手册的教学构造分别标明来源；表述为覆盖率的数字同时给出故障集合或实验范围。

## 完整目录

| 编号 | 文档 |
|---|---|
| 00 | [MBIST总体架构与阅读导航](00_MBIST总体架构与阅读导航.md) |
| 01 | [存储器接口与测试控制器](01_存储器接口与测试控制器.md) |
| 02 | [故障模型与检测原理](02_故障模型与检测原理.md) |
| 03 | [March基础与经典算法](03_March基础与经典算法.md) |
| 04 | [增强March与复杂故障测试](04_增强March与复杂故障测试.md) |
| 05 | [测试算法生成与选择](05_测试算法生成与选择.md) |
| 06 | [存储器分组与功耗分析](06_存储器分组与功耗分析.md) |
| 07 | [并发调度与联合优化](07_并发调度与联合优化.md) |
| 08 | [自适应与运行期间测试](08_自适应与运行期间测试.md) |
| 09 | [故障诊断与结果记录](09_故障诊断与结果记录.md) |
| 10 | [冗余分析自修复与纠错码](10_冗余分析自修复与纠错码.md) |
| 11 | [多端口与新型存储器扩展](11_多端口与新型存储器扩展.md) |
| 12 | [设计验证与工具接入](12_设计验证与工具接入.md) |
| 13 | [算例与源码说明](13_算例与源码说明.md) |
| 14 | [故障模型与测试序列索引](14_故障模型与测试序列索引.md) |
| 90 | [参考文献与研究进展索引](90_参考文献与研究进展索引.md) |

## Obsidian 与插图

将整个目录作为 Obsidian 仓库打开，或复制到已有仓库。保留 `assets/` 的相对位置。公式使用 `$...$` 与 `$$...$$`，章节目录使用 Obsidian 标题链接。

插图包括 10 张 March 图、15 张系统图、26 张分组专题图，以及 3 张故障观测与序列生成图。全部提供原生 SVG 与 PNG；文字保持可编辑。新绘图使用明确的连接点、水平或垂直线段与箭头，绘图源码位于 `src/generate_research_figures.py`。

[查看插图索引](插图索引.html)。基础图的连接点辅助页面为 [精确绘图检查.html](精确绘图检查.html)。

## 运行核心算例

以下命令在本目录执行，算法算例只需要 Python 3.10 或更新版本。

运行全部数字模型算例、逐访问表导出和文档静态检查：

```bash
python src/run_checks.py
```

各程序也可以单独运行：

```bash
python src/validate_march_sequences.py
python src/fault_detection_examples.py
python src/validate_static_fault_models.py
python src/validate_multirun_sequences.py
python src/validate_multirun_faults.py
python src/sequence_generation_examples.py
python src/port_imc_examples.py
python src/validate_march_ic.py
python src/transparent_march_examples.py
python src/validate_read_disturb_and_pause.py
python src/export_march_traces.py --examples
python src/teaching_examples.py
python src/validate_handbook.py
```

逐次访问 CSV 保存在 `examples/traces/`，算法及示例清单见 [march_trace_catalog.json](examples/march_trace_catalog.json)。统一检查结果见 [run_checks_results.json](checks/run_checks_results.json)。

结果写入 `examples/` 和 `checks/`。每份结果说明使用的故障定义、初始状态、地址数量和检查类型。插图生成、网页生成与可选依赖见第 13 章。

## 文献范围

故障模型、增强算法与序列生成专题的文献检索截止 **2026-11-18**。参考文献列出标题、作者、发表时间和原文地址，并标明全文、摘要或预印本的使用范围。系统分组、调度与修复专题沿用各章列出的研究范围。
