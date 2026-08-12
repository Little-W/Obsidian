---
title: DC常用指令参考
aliases:
  - Design Compiler 常用命令
tags:
  - 后端学习
  - synthesis
  - dc_shell
---

# DC 常用指令参考

本页按工业级综合流程的执行顺序整理常用 `dc_shell` 指令。示例中的单元名、端口名、数值和库名仅用于说明，必须替换为项目实际输入。完整流程说明见 [工业级DC综合流程教学](工业级DC综合流程教学.md)。

> [!tip]
> 在所安装的 DC 版本中，以 `help <command>`、`man <command>` 和 `help -verbose <command>` 的输出为准。不同版本对选项、默认行为和许可功能可能不同。

## 1. 启动与基本检查

| 指令 | 用途 | 示例 |
| --- | --- | --- |
| `version` | 输出 DC 版本与构建信息 | `puts [version]` |
| `set_host_options -max_cores N` | 设置 DC 可用 CPU 核数 | `set_host_options -max_cores 8` |
| `help <cmd>` | 查看简要帮助 | `help compile_ultra` |
| `man <cmd>` | 查看完整手册页 | `man report_timing` |
| `printvar <var>` | 查看应用变量或 Tcl 变量 | `printvar target_library` |
| `getenv <name>` | 读取环境变量 | `set top [getenv TOP]` |
| `quit` | 退出批处理会话 | `quit` |

批处理脚本开始时，建议输出顶层模块、RTL 文件列表、SDC 文件、库文件、运行目录和 DC 版本；脚本结束时显式执行 `quit`。

## 2. 库和工艺条件

### 2.1 基本设置

```tcl
set search_path [list ./lib/stdcell ./lib/macro ./rtl]
set target_library [list stdcell_ss_0p72v_125c.db]
set synthetic_library [list dw_foundation.sldb]
set link_library [concat * $target_library $synthetic_library macro_ss.db]
set_operating_conditions ss_0p72v_125c -library stdcell_ss_0p72v_125c
```

| 指令或变量 | 用途 | 审阅重点 |
| --- | --- | --- |
| `search_path` | 指定查找 `.db`、`.sldb` 与 include 文件的目录 | 使用固定路径；避免依赖启动位置。 |
| `target_library` | 指定 DC 用来实现标准单元的 `.db` | 文件、工艺条件和项目要求一致。 |
| `link_library` | 指定链接时可引用的标准单元、宏和综合库 | 含 `*`、目标库、宏时序模型与所需 `.sldb`。 |
| `synthetic_library` | 指定 DesignWare 等综合库 | 需要 DesignWare 时加入。 |
| `set_operating_conditions` | 选择库中的工艺、电压、温度条件 | 与当前模式和目标条件一致。 |
| `report_lib` | 输出库内容和属性 | 确认时序单元、时钟单元、组合单元可见。 |
| `list_libs` | 列出已加载库 | 排查库文件未读入。 |
| `get_lib_cells` | 查询库单元集合 | `get_lib_cells */DFF*` |

参考工程使用 FreePDK45 的 `gscl45nm.db` 和 `typical` 条件。真实项目常有多个 PVT（process/voltage/temperature）条件，宏模型也必须与当前条件匹配。

## 3. 读取 RTL、展开设计与链接

```tcl
define_design_lib WORK -path $RUN_DIR/WORK
analyze -format sverilog -vcs \
    "+define+SYNTHESIS -f $FILELIST"
elaborate $TOP
current_design $TOP
link
check_design
```

| 指令 | 用途 | 常见问题 |
| --- | --- | --- |
| `define_design_lib` | 指定编译后设计库的位置 | `WORK` 应在运行目录，不要写入 RTL 目录。 |
| `analyze` | 分析并编译 Verilog、SystemVerilog 或 VHDL | package 顺序、include 路径、宏定义不正确。 |
| `elaborate` | 以顶层模块展开设计 | 顶层名、参数或生成块不正确。 |
| `current_design` | 设定当前操作的设计 | 多个设计同时存在时必须明确。 |
| `link` | 解析层级模块、标准单元和宏引用 | 宏 `.db` 缺失、模块缺失或库名错误。 |
| `uniquify` | 为重复引用的模块建立独立副本 | 影响层级名称和形式等价检查设置。 |
| `check_design` | 检查结构问题 | 未连接端口、多驱动、常量端口、三态结构。 |
| `report_design` | 输出设计概要 | 单元数量、端口、层级和设计属性。 |
| `report_reference` | 查看被引用的模块和库单元 | 检查黑盒和未解析引用。 |

参考工程采用 `analyze -vcs` 读取 `filelist/matrix_processor.f`，然后执行 `elaborate`、`uniquify -force`、`link` 和 `check_design`。每个命令后的日志都应保存。

## 4. 时序与环境约束

### 4.1 时钟

```tcl
create_clock -name CLK -period 3.33 \
    -waveform {0 1.665} [get_ports vsi_clk]

create_generated_clock -name CLK_DIV2 \
    -source [get_ports vsi_clk] -divide_by 2 \
    [get_pins u_div/clk_out]

set_clock_uncertainty -setup 0.10 [get_clocks CLK]
set_clock_uncertainty -hold  0.05 [get_clocks CLK]
set_clock_latency -source 0.20 [get_clocks CLK]
```

| 指令 | 用途 | 审阅重点 |
| --- | --- | --- |
| `create_clock` | 在端口或引脚建立主时钟 | 周期、波形、名称和时钟位置正确。 |
| `create_generated_clock` | 描述分频、倍频、门控后的时钟 | 必须指定真实来源和分频/倍频关系。 |
| `set_clock_uncertainty` | 设置 setup、hold 时钟不确定度 | 区分 setup 与 hold；数值来自时钟预算。 |
| `set_clock_latency` | 设置时钟源延迟或网络延迟 | 分清 `-source` 与网络延迟的使用时机。 |
| `set_propagated_clock` | 使用已知时钟网络延迟 | 通常在物理实现后的时序分析使用。 |
| `set_clock_transition` | 设置时钟转换时间 | 仅在项目要求并具备合理依据时设置。 |
| `report_clock` | 输出时钟属性和端点 | 时钟数量、周期、波形、传播状态。 |

### 4.2 输入输出预算

```tcl
set in_ports  [remove_from_collection [all_inputs] [get_ports "vsi_clk vsi_rst_n"]]
set out_ports [all_outputs]

set_input_delay  -clock CLK -max 1.20 $in_ports
set_input_delay  -clock CLK -min 0.20 $in_ports
set_output_delay -clock CLK -max 0.80 $out_ports
set_output_delay -clock CLK -min 0.10 $out_ports

set_driving_cell -lib_cell BUF_X4 -pin Y $in_ports
set_input_transition 0.08 $in_ports
set_load 0.020 $out_ports
```

| 指令 | 用途 | 审阅重点 |
| --- | --- | --- |
| `set_input_delay` | 约束外部数据到输入端口的到达时间 | 同步接口通常同时设置 `-min` 和 `-max`。 |
| `set_output_delay` | 约束端口到外部接收寄存器的要求时间 | 同步接口通常同时设置 `-min` 和 `-max`。 |
| `set_driving_cell` | 用库单元描述输入端口驱动能力 | 单元、引脚和库条件正确。 |
| `set_input_transition` | 直接设置输入转换时间 | 与 `set_driving_cell` 的使用方式保持一致。 |
| `set_load` | 设置输出端口看到的电容 | 数值来自 IO 或顶层预算。 |
| `set_max_capacitance` | 限制网络电容 | 只使用库和项目允许的限制。 |
| `set_max_transition` | 限制转换时间 | 分别关注数据和时钟网络。 |
| `set_max_fanout` | 限制单个驱动端连接的数量 | 高扇出控制信号需重点查看。 |
| `report_port -verbose` | 查看端口约束 | 检查延迟、驱动、转换时间和电容。 |

### 4.3 路径关系与例外

```tcl
set_clock_groups -asynchronous \
    -group [get_clocks CLK_A] \
    -group [get_clocks CLK_B]

set_false_path -from [get_ports rst_n]
set_multicycle_path 2 -setup -from [get_registers src_reg*] -to [get_registers dst_reg*]
set_multicycle_path 1 -hold  -from [get_registers src_reg*] -to [get_registers dst_reg*]
set_max_delay 1.50 -from [get_ports req] -to [get_ports ack]
set_min_delay 0.10 -from [get_ports req] -to [get_ports ack]
```

| 指令 | 用途 | 审阅重点 |
| --- | --- | --- |
| `set_clock_groups` | 设置异步或互斥时钟组 | 仅对架构确认的时钟关系使用。 |
| `set_false_path` | 排除不需要常规时序分析的路径 | 起点、终点和功能原因必须具体。 |
| `set_multicycle_path` | 修改多周期数据路径的要求周期数 | `-setup` 与 `-hold` 必须成对审阅。 |
| `set_max_delay` | 限制指定起点到终点的最大延迟 | 适合接口或自定义路径要求。 |
| `set_min_delay` | 限制指定起点到终点的最小延迟 | 用于最小延迟要求。 |
| `group_path` | 给路径分类并设定权重 | 便于在 QoR 中分别观察输入、输出和寄存器路径。 |
| `report_exceptions` | 输出时序例外 | 检查例外是否覆盖了不应排除的路径。 |

> [!warning]
> 例外命令能显著改变报告结论。每条例外应有路径端点、时钟、功能原因和审阅记录；不能用它来隐藏设计问题。

## 5. 编译、结构控制与名称处理

```tcl
set_fix_multiple_port_nets -all -exclude_clock_network
compile -map_effort medium -area_effort medium
# 或：compile_ultra
change_names -rules verilog -hierarchy
```

| 指令 | 用途 | 使用提醒 |
| --- | --- | --- |
| `compile` | 执行基础综合与优化 | 使用明确的 effort 选项并记录。 |
| `compile -incremental` | 在已有结果上做增量优化 | 输入、约束和库不应发生未经说明的变化。 |
| `compile_ultra` | 使用更强的优化策略 | 比较运行时间、面积、时序和层级变化。 |
| `set_fix_multiple_port_nets` | 处理多端口连接网络 | 通常排除时钟网络。 |
| `set_dont_touch` | 禁止 DC 修改对象 | 只保护确有需要的模块、网络或单元。 |
| `set_dont_use` | 禁止使用指定库单元 | 例如工艺文件指定不可用的单元。 |
| `set_ungroup` | 控制是否展开某层级 | 同时考虑调试、形式等价检查和物理实现需求。 |
| `ungroup` | 立即展开指定层级 | 操作前确认范围。 |
| `group` | 将对象组织为层级或分组 | 用于特定结构控制场景。 |
| `change_names -rules verilog` | 把名称处理为 Verilog 合法形式 | 在输出网表前执行并保存名称变化信息。 |
| `set_max_area` | 设置面积目标 | `0` 表示尽量减小面积，不应被当作明确面积上限。 |

时钟门控、扫描替换和低功耗优化通常需要专门阶段、测试模式约束和形式等价检查设置。不要仅打开一个开关就把结果用于项目交接。

## 6. 质量报告与问题定位

```tcl
check_design > report/check_design.rpt
check_timing -verbose > report/check_timing.rpt
report_qor > report/qor.rpt
report_area -hierarchy > report/area.rpt
report_timing -delay max -max_paths 50 -path_type full_clock_expanded \
    > report/timing_setup.rpt
report_timing -delay min -max_paths 50 -path_type full_clock_expanded \
    > report/timing_hold.rpt
report_constraint -all_violators > report/constraint.rpt
report_power > report/power.rpt
report_reference > report/reference.rpt
report_clock_gating > report/clock_gating.rpt
```

| 指令 | 回答的问题 | 首先查看什么 |
| --- | --- | --- |
| `check_design` | 设计结构是否可综合、可链接？ | 未连接、多驱动、常量端口、三态与黑盒。 |
| `check_timing -verbose` | 时序分析是否完整？ | 未约束端点、I/O 延迟缺项、缺失时钟。 |
| `report_qor` | 顶层 QoR 摘要如何？ | setup/hold 裕量、面积、违例数量、单元数量。 |
| `report_area -hierarchy` | 面积主要集中在哪里？ | 异常层级、重复逻辑和宏单元面积。 |
| `report_timing -delay max` | 最慢路径是什么？ | 起终点、时钟、逻辑深度、单元和走线估计。 |
| `report_timing -delay min` | 最短路径是否满足？ | hold 违例路径和时钟关系。 |
| `report_constraint -all_violators` | 约束与设计规则有哪些违例？ | 最大转换时间、最大电容、最大扇出、时序。 |
| `report_power` | 功耗估算如何？ | 活动率、开关概率、时钟功耗和工艺条件。 |
| `report_reference` | 使用了哪些模块、宏和单元？ | 黑盒、意外单元和宏模型。 |
| `report_clock_gating` | 时钟门控识别情况如何？ | 门控单元、覆盖率和检查信息。 |

`report_constraints` 不是建议在新脚本中使用的标准写法；使用并验证 `report_constraint -all_violators` 更清楚。报告文件名应包含阶段，例如 `constraint_pre.rpt` 与 `constraint_post.rpt`，以便区分综合前后。

## 7. 输出、交接与形式等价检查

```tcl
set_svf $RUN_DIR/formal/$TOP.svf

write -format ddc -hierarchy \
    -output $RUN_DIR/netlist/$TOP.ddc
write -format verilog -hierarchy \
    -output $RUN_DIR/netlist/$TOP.vg
write_sdc $RUN_DIR/constraint/$TOP.sdc
```

| 指令 | 输出 | 用途 |
| --- | --- | --- |
| `set_svf` | `.svf` | 记录综合变换，供 Formality 等形式等价检查工具使用。 |
| `write -format ddc` | `.ddc` | DC 的二进制设计数据库。 |
| `write -format verilog` | `.v` 或 `.vg` | 物理实现、门级仿真或其他工具读取的门级网表。 |
| `write_sdc` | `.sdc` | 本轮综合后保存的时序约束。 |
| `write -format ddc -hierarchy` | 保留层级的 DDC | 便于后续 DC 读取与检查。 |
| `write -format verilog -hierarchy` | 保留层级的门级网表 | 便于物理实现和层级调试。 |

门级网表、SDC、SVF、报告、日志、库文件版本和运行记录应来自同一运行目录。将不同日期的网表和 SDC 混用会使时序与形式等价检查难以解释。

## 8. 对象查询的常用写法

DC 命令以 collection（对象集合）作为输入。先用查询命令确认对象是否选中，再施加约束，能避免端口名拼错却不自知。

```tcl
get_ports *
get_ports {vsi_clk vsi_rst_n}
get_cells -hier *reg*
get_pins -of_objects [get_cells u_core/*]
get_nets -of_objects [get_ports data_in*]
get_clocks *
all_inputs
all_outputs
all_registers
sizeof_collection [get_ports *]
query_objects [get_ports vsi_*]
```

| 查询 | 返回对象 | 典型用途 |
| --- | --- | --- |
| `get_ports` | 顶层端口 | 建立时钟、I/O 延迟和复位例外。 |
| `get_cells -hier` | 层级实例 | 查找寄存器、宏、时钟门控实例。 |
| `get_pins` | 单元引脚 | 生成时钟、关键路径或约束内部引脚。 |
| `get_nets` | 网络 | 分析高扇出、最大电容或特定控制网络。 |
| `get_clocks` | 时钟对象 | 设置时钟不确定度、时钟组与报告。 |
| `all_inputs` / `all_outputs` | 顶层输入/输出集合 | 批量设置 I/O 约束。 |
| `all_registers` | 时序单元集合 | 查询寄存器起终点。 |
| `sizeof_collection` | 集合对象数量 | 防止查询为空。 |
| `query_objects` | 打印集合对象名 | 在约束前确认匹配范围。 |

> [!note]
> 在对集合执行 `set_false_path`、`set_dont_touch`、`set_load` 等命令前，先执行一次 `query_objects` 或 `sizeof_collection`。空集合或过宽的通配符都可能产生难以发现的约束错误。

## 9. DFT 相关常用指令

以下指令仅列出入口。DFT 设置会影响时钟、测试模式、门级网表和形式等价检查，应使用项目专门的 DFT 规范及 ATPG 环境。

| 指令 | 用途 |
| --- | --- |
| `set_dft_signal` | 定义 scan clock、reset、scan enable、test mode 等 DFT 信号。 |
| `set_scan_configuration` | 设置扫描链配置。 |
| `create_test_protocol` | 创建测试协议。 |
| `dft_drc` | 检查 DFT 规则。 |
| `preview_dft` | 在插入前预览 DFT 结构。 |
| `insert_dft` | 插入扫描和相关测试结构。 |
| `compile_ultra -scan` | 在 scan 模式下执行综合。 |
| `report_scan_path` | 查看扫描链。 |

如果参考工程的 `enableDFT` 开关被启用，应将 DFT SDC、测试端口、模式约束、DFT DRC 报告和形式等价检查一并纳入运行目录。

## 10. 一个最小可用的排错顺序

当 `make syn` 或 `dc_shell -f run_dc.tcl` 失败时，按以下顺序排查通常最快：

1. 读取 `dc.log` 中第一个 error，而不是最后一个错误。
2. 确认 `TOP`、`FILELIST`、`SDC_FILE`、库路径和运行目录已经打印且正确。
3. 对库问题执行 `list_libs`、`report_lib`，对对象问题执行 `query_objects`。
4. 在 `analyze` 失败时检查 RTL 顺序、include 目录和宏定义。
5. 在 `link` 失败时检查缺失模块、SRAM/IO 宏模型和 `link_library`。
6. 在 `check_timing` 出现缺项时，先补全时钟与 I/O 最小、最大延迟，再看综合 QoR。
7. 在 `compile` 后出现结构或时序异常时，对比综合前后的 `check_design`、`check_timing` 和约束报告。
8. 在网表交接前确认 `.vg`、`.ddc`、`.sdc`、`.svf` 与本轮日志都在同一个运行目录。

## 11. 与 xinyuan-syn 对照时优先掌握的命令

| 参考脚本 | 应重点理解的指令 |
| --- | --- |
| `1_common_setup.tcl` | `getenv`、`set_host_options`、`set_app_var` |
| `2_dc_setup.tcl` | `search_path`、`target_library`、`synthetic_library`、`link_library` |
| `3_read_design.tcl` | `define_design_lib`、`set_svf`、`analyze`、`elaborate`、`link`、`check_design` |
| `matrix_processor_func.sdc` | `create_clock`、`set_input_delay`、`set_output_delay`、`set_false_path`、`set_clock_uncertainty` |
| `4_design_environment.tcl` | `group_path`、`set_operating_conditions` |
| `5_compile_design.tcl` | `set_fix_multiple_port_nets`、`compile`、`compile_ultra`、`change_names`、`write_sdc` |
| `6_timing_report.tcl` | `report_qor`、`report_area`、`report_timing`、`report_power`、`report_reference` |

掌握这些指令后，再扩展到多模式多 PVT、物理信息驱动的综合、低功耗和 DFT，能更容易理解每个阶段为什么需要独立脚本和固定报告。
