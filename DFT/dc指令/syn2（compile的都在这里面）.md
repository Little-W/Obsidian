---
title: Design Compiler 编译与 DFT 相关命令（整理版）
type: command-reference
tags:
  - Design Compiler
  - compile
  - DFT
source_pdf: syn2（compile的都在这里面）.pdf
source_pages: 3370
updated: 2026-08-12
---

# Design Compiler 编译与 DFT 相关命令

## 说明

原始资料是大型 Design Compiler 命令/参考手册，内容远超 DFT。本页按“能直接用于 DFT 综合脚本的部分”重新整理，避免把几千页命令文本混成一篇无法检索的逐页堆叠文档。

## 1. 编译流程骨架

```tcl
############################################################
# 0. 环境
############################################################
set_app_var search_path [list ./rtl ./lib ./scripts]
set_app_var target_library {slow_scan.db}
set_app_var link_library "* slow_scan.db"

############################################################
# 1. 读入和展开
############################################################
analyze -format verilog [glob ./rtl/*.v]
elaborate top
current_design top
link
check_design

############################################################
# 2. 时序约束
############################################################
create_clock -name clk -period 10 -waveform {0 5} [get_ports clk]
set_clock_uncertainty -setup 0.1 [get_clocks clk]
set_clock_uncertainty -hold  0.1 [get_clocks clk]
set_input_delay  -max 2.0 -clock clk [all_inputs]
set_output_delay -max 2.0 -clock clk [all_outputs]
set_max_transition 0.2 [current_design]

############################################################
# 3. DFT 约束和扫描综合
############################################################
set_test_default_scan_style multiplexed_flip_flop
set_test_default_period 100
set_test_default_strobe 90
check_scan
compile -scan
insert_scan

############################################################
# 4. 检查和交付
############################################################
check_design
check_timing
report_test -scan_path
report_test -type dft_drc
report_qor
write -format verilog -hier -output ./out/top_scan.v
write_test_protocol -format stil -output ./out/top.stil
```

## 2. `compile`、`compile -scan` 与 `insert_scan`

| 命令 | 适用阶段 | 作用 |
| --- | --- | --- |
| `compile` | 普通综合 | 优化功能网表并映射到目标库 |
| `compile -scan` | 扫描感知综合 | 在优化时考虑扫描触发器和测试约束 |
| `insert_scan` | 扫描插入 | 执行扫描替换、链连接和相关结构生成 |
| `preview_dft` | 插入前 | 预览工具将采用的 DFT 结构 |
| `check_scan` | 插入前/后 | 检查扫描设置、库和结构 |

映射前/扫描感知综合通常能让工具更早考虑扫描开销；映射后插入流程更直观，便于对比功能网表，但需要重新核对时序和面积。

## 3. 集合操作是脚本的核心

```tcl
set seq_cells [get_cells -hier -filter "is_sequential == true"]
set input_ports [get_ports -filter "direction == in"]
set clocks [get_clocks *]

foreach_in_collection cell $seq_cells {
    puts "SEQ: [get_object_name $cell]"
}

set scan_cells [get_cells -hier -filter "is_scan_cell == true"]
sizeof_collection $scan_cells
```

使用 `get_*` 集合而不是硬编码层次路径，脚本更容易适配不同顶层和层次结构。

## 4. 约束与 DFT 的交互

DFT 约束不能替代功能时序约束，二者要分开管理：

- 功能时钟约束描述正常工作模式。
- 测试时钟约束描述移位/捕获模式。
- 扫描使能应在功能时序分析中作为稳定控制信号处理。
- 测试模式下的 clock mux、门控和复位必须有明确的模式约束。
- 不要用过宽的 `false_path` 掩盖真正不可测的路径。

## 5. 常用属性与例外

```tcl
set_dont_touch [get_cells u_debug]
set_dont_use [get_lib_cells */BAD_SCAN_FF]
remove_attribute [get_cells *] dont_use
set_case_analysis 0 [get_ports test_mode]
set_false_path -from [get_ports scan_enable]
```

例外约束必须写明原因和作用模式。尤其是 `set_false_path`、`set_case_analysis` 与 `dont_touch`，使用不当会同时降低时序分析和 DFT 检查的可信度。

## 6. 报告驱动的调试

```tcl
redirect -file ./reports/design.rpt { check_design }
redirect -file ./reports/timing_max.rpt { report_timing -delay_type max -max_paths 50 }
redirect -file ./reports/timing_min.rpt { report_timing -delay_type min -max_paths 50 }
redirect -file ./reports/scan.rpt { report_test -scan_path }
redirect -file ./reports/dft_drc.rpt { report_test -type dft_drc }
```

每次修改后至少比较：

1. 扫描触发器数量和扫描链数量。
2. 最长/最短扫描链差异。
3. DFT DRC 违规数及类型。
4. 功能模式 setup/hold 违例。
5. ATPG 覆盖率、向量数量和估算测试时间。

## 7. 输出与复现

```tcl
file mkdir ./out ./reports ./logs
write -format ddc -hier -output ./out/top_scan.ddc
write -format verilog -hier -output ./out/top_scan.v
write_sdc ./out/top_scan.sdc
write_test_protocol -format stil -output ./out/top.stil
```

建议在日志开头记录：

```tcl
puts "DATE    = [clock format [clock seconds]]"
puts "DESIGN  = [current_design]"
puts "VERSION = [version]"
puts "LIBRARY = $target_library"
```

## 8. 编译阶段故障速查

| 问题 | 可能原因 | 处理 |
| --- | --- | --- |
| `link` 失败 | 库未找到、单元名不匹配、搜索路径错误 | 检查 `search_path`、`link_library` 和库单元名 |
| `compile -scan` 后无扫描单元 | 扫描库缺失或扫描单元被禁用 | 检查库、`dont_use` 和扫描风格 |
| 约束数量异常 | 端口集合包含时钟/复位或层次不完整 | 先打印集合，再施加约束 |
| DRC 违规增多 | 测试协议与结构不匹配 | 先检查测试时钟/复位/模式，再看路径 |
| 输出网表不可复现 | 脚本依赖隐含变量或交互状态 | 清理环境，显式设置变量并保存日志 |
