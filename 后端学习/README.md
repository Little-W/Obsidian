---
title: 工业级综合流程学习
---

# 工业级综合流程学习

本目录以 `/media/6/Projects/xinyuan/xinyuan-syn` 中的 `matrix_processor` 综合工程为参考，说明如何从 RTL、时序约束和工艺库出发，建立可重复运行、可检查、可交接给物理实现团队的 Design Compiler（DC）综合流程。

参考工程只用于阅读和分析；本目录中的文档不修改该工程。

## 阅读顺序

1. [工业级DC综合流程教学](工业级DC综合流程教学.md)：目录设计、脚本分层、约束、检查、结果交接及对参考工程的改进建议。
2. [DC常用指令参考](DC常用指令参考.md)：按工作阶段整理的常用 `dc_shell` 指令、示例和检查重点。

## 参考工程的已知范围

- 顶层模块：`matrix_processor`
- RTL 文件列表：`filelist/matrix_processor.f`
- 功能模式 SDC：`sdc/matrix_processor_func.sdc`
- 综合入口：`syn/Makefile` 与 `syn/scr/dc.tcl`
- 标准单元库：FreePDK45 的 `gscl45nm.db`
- 当前时钟：`vsi_clk`，周期为 `3.33 ns`（300 MHz）

这些设置适合教学和流程原型。实际芯片项目还应由工艺库、IO 预算、低功耗描述、物理规划和多个 PVT 条件共同确定。
