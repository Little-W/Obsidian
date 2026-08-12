---
title: Synopsys DC/DFT 常用命令详解（整理版）
type: reference
tags:
  - Design Compiler
  - DFT
  - Tcl
source_pdf: 常用synopsys--dc命令详解.pdf
source_pages: 40
updated: 2026-08-12
---

# Synopsys DC/DFT 常用命令详解

## 1. 命令使用原则

DC/DFT 命令本质上是 Tcl 命令。推荐把流程拆成“读入—链接—约束—综合/扫描—检查—报告—输出”七个阶段，并为每个阶段保存日志和报告。

```tcl
redirect -file reports/compile.log { compile -scan }
```

## 2. 设计读入与层次管理

| 命令 | 用途 | 示例 |
| --- | --- | --- |
| `read_verilog` | 读入 Verilog 网表/RTL | `read_verilog {rtl/top.v}` |
| `read_vhdl` | 读入 VHDL | `read_vhdl {rtl/top.vhd}` |
| `analyze` | 分析源文件，不建立完整设计 | `analyze -format verilog {rtl/*.v}` |
| `elaborate` | 从分析结果展开顶层 | `elaborate top` |
| `current_design` | 切换当前设计 | `current_design top` |
| `link` | 解析实例与库单元引用 | `link` |
| `uniquify` | 为层次实例生成唯一副本 | `uniquify` |
| `get_designs` | 获取设计对象集合 | `get_designs *` |
| `get_cells` | 获取层次单元 | `get_cells -hier *` |
| `get_ports` | 获取端口 | `get_ports *` |
| `get_pins` | 获取引脚 | `get_pins -hier *` |
| `get_nets` | 获取网络 | `get_nets -hier *` |

常用集合过滤：

```tcl
get_cells -hier -filter "is_sequential == true"
get_ports -filter "direction == in"
get_cells -hier -of_objects [get_nets scan_enable]
```

## 3. 工艺库与设计环境

```tcl
set_app_var search_path [list ./lib ./rtl]
set_app_var target_library {slow_scan.db}
set_app_var link_library "* slow_scan.db"

set_operating_conditions -analysis_type on_chip_variation \
    -max slow -min fast
set_wire_load_mode top
```

注意：`target_library` 决定综合映射目标；`link_library` 用于解析设计中引用的单元。扫描触发器若被设置为 `dont_use`，扫描插入会失败或退化为普通触发器。

## 4. 时钟、输入输出和时序约束

```tcl
create_clock -name clk -period 10 -waveform {0 5} [get_ports clk]
set_clock_uncertainty -setup 0.10 [get_clocks clk]
set_clock_uncertainty -hold  0.10 [get_clocks clk]

set_input_delay  -max 2.0 -clock clk [remove_from_collection [all_inputs] [get_ports clk]]
set_input_delay  -min 0.1 -clock clk [remove_from_collection [all_inputs] [get_ports clk]]
set_output_delay -max 2.0 -clock clk [all_outputs]

set_input_transition 0.1 [all_inputs]
set_load 0.2 [all_outputs]
set_drive 0 [get_ports clk]
```

检查约束：

```tcl
check_timing
report_clocks
report_constraint -all_violators
report_timing -max_paths 20
```

## 5. 综合与优化

| 命令 | 作用 |
| --- | --- |
| `compile` | 综合和优化当前设计 |
| `compile -scan` | 综合时考虑扫描触发器 |
| `compile_ultra` | 更激进的综合优化，需确认授权和流程兼容性 |
| `set_dont_touch` | 防止对象被优化或重写 |
| `set_dont_use` | 禁止使用指定库单元 |
| `remove_attribute` | 删除对象属性 |
| `set_max_area` | 设置面积目标 |
| `set_max_transition` | 设置最大转换时间 |
| `set_max_fanout` | 设置最大扇出 |
| `ungroup` | 展平层次以便优化 |

建议在综合后至少检查面积、时序、组合环路和未连接端口：

```tcl
report_area
report_power
report_qor
report_timing -delay_type max
report_timing -delay_type min
check_design
```

## 6. DFT/扫描相关命令

```tcl
set_test_default_scan_style multiplexed_flip_flop
set_test_default_period 100
set_test_default_strobe 90

check_scan
preview_dft
compile -scan
insert_scan
report_test -scan_path
report_test -type dft_drc
estimate_test_coverage
```

命令作用：

- `check_scan`：检查扫描库、扫描风格和基本扫描可行性。
- `preview_dft`：预览工具计划插入的测试结构。
- `compile -scan`：综合时将扫描结构纳入优化。
- `insert_scan`：执行扫描替换和链连接。
- `report_test -scan_path`：报告扫描链拓扑、长度和时钟。
- `estimate_test_coverage`：根据当前设计估算故障覆盖率。

## 7. 报告、保存和输出

```tcl
file mkdir reports netlist
redirect -file reports/scan_path.rpt { report_test -scan_path }
redirect -file reports/timing.rpt    { report_timing -max_paths 50 }
redirect -file reports/dft_drc.rpt   { report_test -type dft_drc }

write -format verilog -hier -output netlist/top_scan.v
write_sdc netlist/top_scan.sdc
write_test_protocol -format stil -output netlist/top.stil
write -format ddc -hier -output netlist/top.ddc
```

## 8. 常见问题定位

| 现象 | 优先检查 |
| --- | --- |
| 扫描单元没有被替换 | 工艺库是否有 Scan FF；单元是否 `dont_use`；扫描风格是否匹配 |
| 扫描链长度为 0 | 扫描触发器识别、层次当前设计、`link` 和库设置 |
| DFT DRC 报时钟不可控 | 测试时钟端口、时钟复位关系、clock mux 和测试模式 |
| ATPG 覆盖率低 | 不可控/不可观测节点、黑盒、异步复位、时钟域 crossing |
| 时序突然恶化 | 扫描 MUX 延迟、链路重连、扫描使能约束和端口负载 |
