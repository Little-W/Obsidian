# VC Formal 快速参考指南（中文整理版）

- 来源：VC_Formal_Quick_Reference_Guide.pdf
- 版本：X-2025.06-SP1，2025-09
- 说明：本文保留命令名与参数格式，中文部分为整理和翻译，方便直接对照 Tcl 使用。

## 1. VC Formal 简介

VC Formal 是面向 RTL 和网表的形式验证平台。它不依赖随机仿真，而是把设计、约束和属性转成可求解的逻辑问题，在更大的状态空间里发现潜在缺陷。

它特别适合发现以下问题：
- 边界条件错误
- 协议违规
- 死锁和活锁
- 漏连、错连、位宽不匹配
- 时钟/复位假设错误
- 深层角落场景

### 1.1 常见应用

- FPV：功能属性验证，验证用户定义属性和 Assertion IP 属性。
- FRV：寄存器验证，根据 IP-XACT 或 RALF 自动生成并验证检查。
- FCA：形式覆盖率分析，辅助仿真覆盖收敛与形式证明收敛。
- FSV：形式安全验证，确保安全域与非安全域之间不会发生意外数据传播。
- CC：连通性检查，检查源和目的之间是否存在结构和功能上的连接。
- FXP：X 传播验证，检查未知值 X 是否会传播到危险位置。
- AEP：自动提取属性，自动从设计中抽取属性并证明。
- DPV：数据路径验证，使用 HECTOR 技术验证 C/C++ 与 RTL 之间的数据变换块。
- SEQ：顺序等价检查，比较两个 RTL 设计并验证功能等价性。
- FuSa：功能安全分析，分析 Z01X fault 的可控性和可观测性并计算 FMEDA 指标。
- FTA：形式测试平台分析，检查注入故障是否能被形式测试平台检测到。
- FLP：低功耗验证，检查带电源意图的设计是否符合功能规格，可与 CC 和 SEQ 配合使用。

### 1.2 本手册的使用方式

- 这是一份快速参考，展示常见流程、命令和变量。
- 命令后面的选项通常只是示例，不是唯一写法。
- 更详细的说明可查 Synopsys 文档中心的 SolvNet 页面。

### 1.3 通用运行方式

```tcl
# 带 Verdi 交互式运行
vcf -f run.tcl -verdi

# 不带 Verdi 的交互式运行
vcf -f run.tcl

# 批处理 / 回归模式
vcf -f run.tcl -batch

# Elite 授权模式
vcf -f run.tcl -verdi -fml_elite

# Token 授权模式
vcf -f run.tcl -verdi -fml_token
```

### 1.4 通用帮助命令

```tcl
vcf -help
vcf> help
vcf> help report*
vcf> report_fv -help
vcf> man report_fv
vcf> view_help report_fv
vcf> report_fml_var fml_max_*
vcf> report_app_var *fml*
```

## 2. FPV：功能属性验证应用

### 2.1 流程

- Set Up App
- Compile Design
- Add Clock/Reset Info
- Finish
- Generate Reset State
- Debug & Fix
- Run Verification

### 2.2 设计搭建与初始化

#### 设置应用模式

```tcl
set_fml_appmode FPV
```

#### 设定黑盒

```tcl
set_blackbox -designs module
set_blackbox -cells hier_instance
report_blackbox
```

#### 加载 Assertion IP

```tcl
aip_load -protocol "AHB AXI5"
```

#### 读取并展开设计

```tcl
read_file -top top -sva -format verilog -vcs {-f filelist}
analyze -format verilog -vcs {-f filelist}
elaborate top -sva
```

#### 时钟、复位与常量

```tcl
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
set_change_at -clock clk -default
```

#### 推断 formal setup

```tcl
infer_formal_setup -type clock
formal_setup_config
report_formal_setup
```

#### 通过仿真初始化设计

```tcl
sim_run -stable
sim_force signal -apply 3'b000
sim_run 3 -clk clk
sim_set_state -uninitialized -user_only -apply 0
sim_save_reset
view_trace -reset
sim_get -signals {control_reg*}
```

#### 设计复杂度与 setup 检查

```tcl
report_fv_complexity
check_fv_setup
fv_setup_config
report_fv_setup -list
```

### 2.3 输入格式

- RTL 文件：Verilog、SystemVerilog、VHDL
- SVA 文件
- Tcl 文件

### 2.4 验证与调试

#### 属性管理

```tcl
fvassume <name> -expr {<expression>}
fvassert <name> -expr {<expression>}
fvcover <name> -expr {<expression>}
fvdisable property
fvenable property
fvassert property
fvassume property
fvcover property
```

#### 计算资源

```tcl
set_fml_var fml_max_time 24H
set_fml_var fml_max_memory 32GB
set_fml_var fml_progress_time_limit 2H
set_grid_usage -type RSH=12
set_grid_usage -file hostfile
```

#### 空洞性与 witness

```tcl
set_fml_var fml_vacuity_on true
set_fml_var fml_witness_on false
```

#### 结果加速

```tcl
fvlearn_config -local_dir rma_db
```

#### 运行验证

```tcl
check_fv
check_fv -stop
check_fv -block
check_fv -run_finish {report_fv -list}
```

#### 报告结果

```tcl
report_fv
report_fv -list
report_fv -verbose
```

#### 保存和恢复会话

```tcl
save_session -session session
restore_session -session session
vcf -restore -session session
```

#### 查看 trace

```tcl
view_trace -property property
fvtrace -property property
```

#### 验证摘要

```tcl
compute_verification_summary
set_verification_summary
waive_verification_summary
report_verification_summary
```

### 2.5 性能与收敛

#### proof 资源倾向

```tcl
set_fml_var fml_effort default
set_fml_var fml_effort high
set_fml_var fml_effort bug_hunting
set_fml_var fml_effort discovery
```

#### 进度查询

```tcl
report_fml_engines
report_fml_jobs
report_fml_hosts
```

#### 抽象与约束优化

```tcl
snip_driver net
set_abstractions -construct {mult=16 count=4}
report_abstractions
compute_reduced_constraints -property property
report_reduced_constraints
get_reduced_constraints
compute_formal_core -property property
report_formal_core
get_formal_core
compute_proof_assist -property property
report_proof_assist
```

#### 任务管理

```tcl
fvtask -create task
fvtask new_task -copy task
fvtask new_task -copy task [-assumes <list>] [-asserts <list>] [-covers <list>] [-constants <list>] [-snips <list>] [-changeats<list>] [-keep_status] [-keep_task]
fvtask task
get_fvtask
```

#### 退出

```tcl
quit
```

## 3. AEP：自动提取属性应用

### 3.1 作用

AEP 会自动从设计里提取属性，并进行验证，适合用来快速覆盖常见状态机、死锁和约束类检查。

### 3.2 设计搭建与初始化

#### 设置应用模式

```tcl
set_fml_appmode AEP
```

#### 打开 VHDL 和特定检查

```tcl
set_app_var fml_enable_vhdl_aep true
set_app_var fml_enable_vhdl_bus_check true
set_app_var fml_enable_vhdl_cov true
set_fml_var fml_aep_unique_name true
```

#### 读取和展开设计

```tcl
read_file -top top -aep AEP_type -format RTL_format -vcs {-f filelist}
read_file -top top -aep fsm_deadlock+fsm_livelock -format RTL_format -vcs {-f filelist}
analyze -format RTL_format -vcs {-f filelist}
elaborate top -aep AEP_type
```

#### 时钟、复位与初始化

```tcl
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
sim_run -stable
sim_force signal -apply 3'b000
sim_run 3 -clk clk
sim_set_state -uninitialized -user_only -apply 0
sim_save_reset
view_trace -reset
sim_get -signals {control_reg*}
```

#### Setup 检查

```tcl
check_fv_setup
fv_check_config
report_fv_setup -list
```

### 3.3 AEP 专属配置

#### FSM fairness

```tcl
aep_generate -type fsm_fairness
aep_generate -type fsm_fairness -tcl fairness.tcl
```

#### 控制某些状态不生成属性

```tcl
aep_config -dont_generate -type fsm_livelock {state_reg::state_name}
```

### 3.4 验证与调试

#### 属性管理

```tcl
fvdisable property
fvenable property
fvwaive property
fvunwaive property
```

#### 资源配置与运行

```tcl
set_fml_var fml_max_time 24H
set_fml_var fml_max_memory 32GB
set_fml_var fml_progress_time_limit 2H
set_grid_usage -type RSH=12
set_grid_usage -file hostfile
check_fv
check_fv -stop
check_fv -block
check_fv -run_finish {report_fv -list}
```

#### 报告与 waiver

```tcl
report_fv
report_fv -list
report_fv -verbose
save_waiver_file -file aep.el
read_waiver_file -elfiles aep.el
```

#### 会话与 trace

```tcl
save_session -session session
restore_session -session session
vcf -restore -session session
view_trace -property property
fvtrace -property property
```

### 3.5 性能与任务

- 进度查询同 FPV。
- 任务管理同 FPV。
- 退出命令：`quit`

## 4. CC：连通性检查应用

### 4.1 作用

CC 用来检查源和目的之间是否存在结构和功能上的连接，特别适合总线、端口和路径连通性确认。

### 4.2 设计搭建与初始化

#### 设置应用模式

```tcl
set_fml_appmode CC
```

#### 黑盒设置

```tcl
set_blackbox -designs module
set_blackbox -cells hier_instance
report_blackbox
set_fml_var fml_cc_autobbox false
```

#### 读取设计

```tcl
read_file -top top -format verilog -vcs {-f filelist}
analyze -format verilog -vcs {-f filelist}
elaborate top
```

#### 时钟、复位和常量

```tcl
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
```

#### 信号别名

```tcl
set_cc_alias <alias name> <RTL signal name>
report_cc_alias
delete_cc_alias <alias name>
```

#### 指定连接

```tcl
add_cc -src signal -dest signal
load_cc_set_param param_name "%<value>%"
load_cc -format csv csv file
```

#### 保存初始状态

```tcl
sim_save_reset
```

#### Setup 与复杂度查询

```tcl
check_fv_setup
fv_setup_config
report_fv_setup -list
report_fv_complexity
```

### 4.3 结果与调试

```tcl
fvdisable prop_name
fvenable prop_name
set_fml_var fml_max_time 24H
set_fml_var fml_max_memory 32GB
set_fml_var fml_progress_time_limit 2H
set_grid_usage -type RSH=10
set_grid_usage -file hostfile
set_fml_var fml_vacuity_on true
fvlearn_config -local_dir rma_db
check_fv
check_fv -stop
check_fv -block
check_fv -run_finish {report_fv -list}
report_load_cc
report_fv
report_fv -list
report_fv -verbose
report_fv -formatCC csv|tcl|path
save_session -session session
restore_session -session session
vcf -restore -session session
view_trace -property prop_name
view_schematic -prop prop_name
list_path -src signal -dest signal
list_path -cc_prop prop_name
```

### 4.4 连通性提取与覆盖

```tcl
generate_cc -src signal -dest signal -run
set_fml_var fml_enable_cc_extraction_latency true
generate_cc -src signal -dest signal
generate_cc -run -seq_depth <depth>
set_app_var fml_cc_coverage_analyzer true
set_app_var fml_cov_tgl_input_port true
read_file -top top -cov tgl
compute_cc_cov
save_cc_cov_results
```

### 4.5 其它

- 进度查询同 FPV。
- 任务管理同 FPV。
- 退出命令：`quit`

## 5. FCA：形式覆盖率分析应用

### 5.1 作用

FCA 主要用于把仿真覆盖与形式证明结合起来，帮助判断哪些地方已经覆盖到、哪些地方仍然存在验证盲区。

### 5.2 设计搭建与初始化

#### 设置应用模式

```tcl
set_fml_appmode FCA
```

#### 覆盖相关配置

```tcl
set_app_var fml_enable_vhdl_cov true
set_fml_var fml_reset_property_check true
set_fml_var fml_cov_enable_branch_cov true
set_app_var fml_cov_tgl_input_port true
```

#### 覆盖数据库

```tcl
read_covdb -cov_input simv.vdb -cov_dut Testbench.Dut_instance [-elfile elfile] [-check_el]
save_covdb -status covered -name cov.db
view_coverage -cov_input cov.db -elfiles elfiles
```

#### 黑盒与编译

```tcl
set_blackbox -designs module
set_blackbox -cells hier_instance
report_blackbox
read_file -top my_top [-sva] -cov Coverage_Metric -format RTL_format -vcs {-f my_filelist}
analyze -format RTL_format -vcs {-f my_filelist}
elaborate my_top [-sva] -cov Coverage_Metric
```

#### 时钟、复位、常量

```tcl
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
```

### 5.3 结果与调试

```tcl
check_fv_setup
fv_setup_config
report_fv_setup -list
sim_run -stable
sim_save_reset
fvdisable prop_name
fvdisable -type toggle
fvenable prop_name
set_fml_var fml_max_time 24H
set_fml_var fml_max_memory 16GB
set_fml_var fml_progress_time_limit 2H
set_grid_usage -type LSF=100 -control {bsub -q ...}
report_fv
report_fv -list > list_report.txt
report_fv -verbose > verbose_report.txt
save_cov_exclusion -file exclusion.el
save_session -session session
restore_session -session session
vcf -restore -session session
```

### 5.4 Auto Scale

```tcl
cov_config -auto_scale
compute_cov
cov_config -line_task <number>
cov_config -branch_task <number>
cov_config -cond_task <number>
cov_config -fsm_task <number>
cov_config -tgl_task <number>
cov_config -line_limit <number>
cov_config -branch_limit <number>
cov_config -cond_limit <number>
cov_config -fsm_limit <number>
cov_config -tgl_limit <number>
cov_config -auto_scale -end_task_cmd "save_covdb -name cc_tgl.vdb -update"
```

### 5.5 其它

- 进度查询同 FPV。
- 任务管理同 FPV。
- 退出命令：`quit`

## 6. FXP：形式 X 传播验证应用

### 6.1 作用

FXP 用于检查未知值 X 是否会传播到危险位置，帮助发现 X 传播带来的潜在功能风险。

### 6.2 设计搭建与初始化

```tcl
set_fml_appmode FXP
set_blackbox -design module
set_blackbox -cells hier_instance
report_blackbox
read_file -top top -sva -format sverilog -vcs {-f filelist}
analyze -format sverilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
sim_run -stable
sim_force signal -apply 3'b000
sim_run 3 -clk clk
sim_set_state -uninitialized -user_only -apply 0
sim_save_reset
view_trace -reset
sim_get -signals {control_reg*}
check_fv_setup
fv_check_config
report_fv_setup -list
```

### 6.3 FXP 专属配置

```tcl
fxp_generate <name> <type>
fxp_assume -injectx <options*>
fxp_assume -nox <options*>
fxp_assert <options*>
```

### 6.4 验证与调试

```tcl
fvdisable property
fvenable property
set_fml_var fml_max_time 24H
set_fml_var fml_max_memory 32GB
set_fml_var fml_progress_time_limit 2H
set_grid_usage -type RSH=12
set_grid_usage -file hostfile
check_fv
check_fv -stop
check_fv -block
check_fv -run_finish {report_fv -list}
report_fv
report_fv -list
report_fv -verbose
fxp_compute_rootcause property
fxp_report_rootcause
save_session -session session
restore_session -session session
vcf -restore -session session
view_trace -property property
fvtrace -property property
```

### 6.5 性能与任务

- 进度查询同 FPV。
- 任务管理同 FPV。
- 退出命令：`quit`

## 7. SEQ：顺序等价检查应用

### 7.1 作用

SEQ 用于比较两个 RTL 设计，确认在映射关系已知的前提下它们在功能上等价。

### 7.2 设计搭建与初始化

#### 设置应用模式

```tcl
set_fml_appmode SEQ
seq_config -recipe orch_generic_medium
seq_config -map_uninit -map_x zero
```

#### 黑盒与编译

```tcl
set_blackbox -designs module
set_blackbox -cells hier_instance
report_blackbox
analyze -format verilog -library spec -vcs {-f sfilelist}
analyze -format verilog -library impl -vcs {-f ifilelist}
elaborate_seq -spectop <DUT_top> -impltop impl
analyze -format verilog -vcs {-f filelist}
elaborate_seq -spectop top -same_design
```

#### 时钟、复位、常量与初始化

```tcl
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
sim_run -stable
sim_force signal -apply 3'b000
sim_run 3 -clk clk
sim_set_state -uninitialized -user_only -apply 0
sim_save_reset
view_trace -reset
sim_get -signals {control_reg*}
```

#### 映射设计

```tcl
map_by_name
seqmap
sequnmap
seq_read_mapping_file mappings.tcl
report_seq_mappings
```

### 7.3 验证与调试

```tcl
check_fv_setup
fv_setup_config
report_fv_setup -list
report_fv_complexity
fvassume <name> -expr {<expression>}
fvassert <name> -expr {<expression>}
fvcover <name> -expr {<expression>}
fvdisable property
fvenable property
fvassert property
fvassume property
fvcover property
set_fml_var fml_max_time 24H
set_fml_var fml_max_memory 32GB
set_fml_var fml_progress_time_limit 2H
set_grid_usage -type RSH=10
set_grid_usage -file hostfile
set_backup_grid_usage -file hostfile
set_fml_var fml_vacuity_on true
set_fml_var fml_witness_on true
check_fv
check_fv -stop
check_fv -block
check_fv -run_finish {report_fv -list}
resume_seq
report_fv
report_fv -list
report_fv -verbose
report_proofs
save_session -session session
restore_session -session session
vcf -restore -session session
view_trace -property property
fvtrace -property property
set_debug property
seq_debug_report property
```

### 7.4 性能与收敛

```tcl
set_fml_var fml_effort default
set_fml_var fml_effort high
set_fml_var fml_effort bug_hunting
set_fml_var fml_effort bitlevel_hard
set_fml_var fml_effort no_decompose_expensive
fvlearn_config -local_dir rma_db
report_fml_engines
report_fml_jobs
report_fml_hosts
snip_driver net
set_seq_abstractions -construct {mult=16 add=4}
report_abstractions
compute_reduced_constraints -property property
report_reduced_constraints
get_reduced_constraints
compute_formal_core -property property
report_formal_core
get_formal_core
```

### 7.5 任务与退出

```tcl
fvtask -create task
fvtask new_task -copy task
fvtask new_task -copy task [-assumes <list>] [-asserts <list>] [-covers <list>] [-constants <list>] [-snips <list>] [-changeats<list>]
fvtask task
get_fvtask
quit
```

## 8. FRV：形式寄存器验证应用

### 8.1 作用

FRV 会基于 IP-XACT 或 RALF 中的寄存器定义自动创建检查，并对寄存器行为进行形式验证。

### 8.2 设计搭建与初始化

```tcl
set_fml_appmode FRV
set_blackbox -designs module
set_blackbox -cells hier_instance
report_blackbox
frv_load -ipxact axi4lite_dmac.xml -auto_load
frv_load -ral axi4lite_dmac.ralf -auto_load
read_file -top top -sva -format verilog -vcs {-f filelist} bind_frv.sv
analyze -format verilog -vcs {-f filelist} bind_frv.sv
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
set_change_at -clock clk -default
sim_run -stable
sim_force signal -apply 3'b000
sim_run 3 -clk clk
sim_set_state -uninitialized -user_only -apply 0
sim_save_reset
view_trace -reset
sim_get -signals {control_reg*}
check_fv_setup
fv_setup_config
report_fv_setup -list
report_fv_complexity
```

### 8.3 输入格式

- RTL 文件：Verilog、SystemVerilog、VHDL
- SVA 文件
- Tcl 文件
- IPXACT 文件：寄存器定义 XML
- RALF 文件：寄存器定义文件

### 8.4 验证与调试

```tcl
fvassume <name> -expr {<expression>}
fvassert <name> -expr {<expression>}
fvcover <name> -expr {<expression>}
fvdisable property
fvenable property
fvassert property
fvassume property
fvcover property
set_fml_var fml_max_time 24H
set_fml_var fml_max_memory 32GB
set_fml_var fml_progress_time_limit 2H
set_grid_usage -type RSH=10
set_grid_usage -file hostfile
set_fml_var fml_vacuity_on true
set_fml_var fml_witness_on false
check_fv
check_fv -stop
check_fv -block
check_fv -run_finish {report_fv -list}
report_fv -class register
report_fv -class register -list
report_fv -class register -verbose
frv_report
save_session -session session
restore_session -session session
vcf -restore -session session
view_trace -property property
view_trace -vacuity property
view_trace -witness property
fvtrace -property property
set_fml_var fml_effort default
set_fml_var fml_effort high
set_fml_var fml_effort bug_hunting
set_fml_var fml_effort discovery
fvlearn_config -local_dir rma_db
report_fml_engines
report_fml_jobs
report_fml_hosts
snip_driver net
set_abstractions -construct {mult=16 count=4}
report_abstractions
compute_reduced_constraints -property property
report_reduced_constraints
get_reduced_constraints
compute_formal_core -property property
report_formal_core
get_formal_core
fvtask -create task
fvtask new_task -copy task
fvtask new_task -copy task [-assumes <list>] [-asserts <list>] [-covers <list>] [-constants <list>] [-snips <list>] [-changeats<list>] [-keep_status] [-keep_task]
fvtask task
get_fvtask
quit
```

## 9. FTA：形式测试平台分析应用

### 9.1 作用

FTA 用于判断注入的故障能否被形式测试平台检测到，用来衡量测试平台质量。

### 9.2 设计搭建与初始化

```tcl
set_fml_appmode FTA
set_blackbox -designs module
set_blackbox -cells hier_instance
report_blackbox
fta_init
configure_fta_props
read_file -top top -sva -format verilog -vcs {-f filelist} -inject_fault all
set_app_var fml_multi_step_fta_flow true
analyze -format verilog -vcs {-f filelist}
elaborate top -sva -inject_fault all
read_faultdb -name certitude_db
save_faultdb -name certitude_db
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
set_change_at -clock clk -default
sim_run -stable
sim_force signal -apply 3'b000
sim_run 3 -clk clk
sim_set_state -uninitialized -user_only -apply 0
sim_save_reset
view_trace -reset
sim_get -signals {control_reg*}
report_fv_complexity
check_fv_setup
fv_setup_config
report_fv_setup -list
```

### 9.3 验证与调试

```tcl
fvassume <name> -expr {<expression>}
fvassert <name> -expr {<expression>}
fvcover <name> -expr {<expression>}
fvdisable property
fvenable property
fvassert property
fvassume property
fvcover property
set_fml_var fml_max_time 24H
set_fml_var fml_max_memory 32GB
set_fml_var fml_progress_time_limit 2H
set_grid_usage -type RSH=12
set_grid_usage -file hostfile
set_fml_var fml_vacuity_on true
set_fml_var fml_witness_on false
compute_fta -par_task FPV
check_fv
check_fv -stop
check_fv -block
check_fv -run_finish {report_fv -list}
report_fv -list
report_fv -verbose
fta_report -instance instance
get_fta_faults instance
get_activated_props fault_id
read_fta_waiver -elfiles filelist
remove_fta_waiver -elfiles filelist
save_session -session session
restore_session -session session
vcf -restore -session session
view_trace -property property
fvtrace -property property
compute_verification_summary
set_verification_summary
waive_verification_summary
report_verification_summary
cluster_fta_faults
report_fta_fault_clusters
export_fault
set_fml_var fml_fta_seq_debug true
debug_fta
debug_fta -dump_setup
debug_fta -run_user_setup
set_fml_var fml_effort default
set_fml_var fml_fta_high_effort true
set_fml_var fml_qual_fault_in_fcore true
set_fml_var fml_fta_enable_cover true
report_fml_engines
report_fml_jobs
report_fml_hosts
```

### 9.4 任务与退出

```tcl
fvtask -create task
fvtask -delete task
fvtask task
quit
```

## 10. FuSa：功能安全应用

### 10.1 作用

FuSa 用于分析 controllability 和 observability，辅助计算 FMEDA 指标。

### 10.2 设计搭建与初始化

```tcl
set_fml_appmode FUSA
set_blackbox -designs module
set_blackbox -cells hier_instance
report_blackbox
fusa_config -fdb_campaign fdbname
fusa_config -sff input.sff
read_file -top top -sva -format verilog -vcs {-f filelist}
analyze -format verilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
sim_run -stable
sim_force signal -apply 3'b000
sim_run 3 -clk clk
sim_set_state -uninitialized -user_only -apply 0
sim_save_reset
view_trace -reset
sim_get -signals {control_reg*}
check_fv_setup
fv_setup_config
report_fv_setup -list
report_fv_complexity
fusa_observation -add obs_point
fusa_detection -add det_point
```

### 10.3 额外黑盒与检查生成

```tcl
fusa_blackbox -all -all_auto_path -seq_path
fusa_generate
```

### 10.4 验证与报告

```tcl
fvassume <name> -expr {<expression>}
fvassert <name> -expr {<expression>}
fvcover <name> -expr {<expression>}
fvdisable property
fvenable property
set_fml_var fml_max_time 24H
set_fml_var fml_max_memory 32GB
set_fml_var fml_progress_time_limit 2H
set_grid_usage -type RSH=10
set_grid_usage -file hostfile
set_fml_var fusa_run_mode structural
check_fv
set_fml_var fusa_run_mode control
check_fv
set_fml_var fusa_run_mode observe
check_fv
check_fv -stop
check_fv -block
report_fv
report_fv -list
report_fv -verbose
fusa_report_total_faults
fusa_report
fusa_report -list
fusa_report -fdb_version
fusa_report -all_failure_modes
fusa_save
fusa_save -sff sff
save_session -session session
restore_session -session session
vcf -restore -session session
set_fml_var fml_effort default
set_fml_var fml_effort easy
set_fml_var fml_effort high
set_fml_var fml_effort bounded
set_fml_var fml_effort bug_hunting
set_fml_var fml_effort no_decompose_expensive
report_fml_engines
report_fml_jobs
report_fml_hosts
quit
```

## 11. FSV：形式安全验证应用

### 11.1 作用

FSV 用于确认安全域和非安全域之间不会发生意外数据传播，也用于发现后门和非法路径风险。

### 11.2 设计搭建与初始化

```tcl
set_fml_appmode FSV
set_blackbox -designs module
set_blackbox -cells hier_instance
fsv_blackbox instance
report_blackbox
read_file -top top -sva -format verilog -vcs {-f filelist}
analyze -format verilog -vcs {-f filelist}
elaborate top -sva
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
sim_run -stable
sim_force signal -apply 3'b000
sim_run 3 -clk clk
sim_set_state -uninitialized -user_only -apply 0
sim_save_reset
view_trace -reset
sim_get -signals {control_reg*}
check_fv_setup
fv_setup_config
report_fv_setup -list
report_fv_complexity
```

### 11.3 验证与调试

```tcl
fsv_generate -src src_sig -dest dest_sig
fvassume <name> -expr {<expression>}
fvassert <name> -expr {<expression>}
fvcover <name> -expr {<expression>}
fvdisable property
fvenable property
fvassert property
fvassume property
fvcover property
set_fml_var fml_max_time 24H
set_fml_var fml_max_memory 32GB
set_fml_var fml_progress_time_limit 2H
set_grid_usage -type RSH=10
set_grid_usage -file hostfile
set_backup_grid_usage -file hostfile
set_fml_var fml_vacuity_on true
set_fml_var fml_witness_on false
check_fv
check_fv -stop
check_fv -block
check_fv -run_finish {report_fv -list}
fsv_report
report_fv
report_fv -list
report_fv -verbose
save_session -session session
restore_session -session session
vcf -restore -session session
view_trace -property property
view_trace -vacuity property
view_trace -witness property
set_fml_var fml_effort default
set_fml_var fml_effort high
set_fml_var fml_effort bounded
set_fml_var fml_effort bug_hunting
set_fml_var fml_effort easy
set_fml_var fml_effort no_decompose_expensive
set_fml_var fml_enable_resume true
report_fml_engines
report_fml_jobs
report_fml_hosts
snip_driver net
set_abstractions -construct {mult=16 count=4}
report_abstractions
fvtask -create task
fvtask new_task -copy task
fvtask new_task -copy task [-assumes <list>] [-asserts <list>] [-covers <list>] [-constants <list>] [-snips <list>] [-changeats<list>] [-keep_status] [-keep_task]
fvtask task
get_fvtask
quit
```

## 12. DPV：数据路径验证应用

### 12.1 作用

DPV 使用 HECTOR 技术验证数据变换块，适合在 untimed C/C++ 与 RTL 模型之间做一致性验证。

### 12.2 设计搭建与初始化

```tcl
set_fml_appmode DPV
get_fml_appmode
set_hector_comp_use_new_flow true
set_aep_selection default
list_aep_selection
set_blackbox module
set_blackbox hier_instance
ignore_functions "list_of_functions"
get_blackbox
create_design -name spec|impl -top spectop|impltop -clock clk -reset resetN -negReset -options "compilation_options" -lang "c|c++|verilog|sverilog"
cppan -D<defines> -I <include_directories> <C/C++ filenames>
scdtan -D<defines> -I <include_directories> <C/C++ filenames>
vcs -sverilog -pvalue+<> -f filelist
vlogan <options> <filelist>
vhdlan <options> <filelist>
compile_design spec|impl
fvassume -always -expr (impl.testmode==1'b0)
map_by_name -specphase <phase> -implphase <phase> -inputs|-outputs
report_dpv_mappings
report_fv_complexity
```

### 12.3 证明流程

```tcl
set_user_assumes_lemmas_procedure "ual"
set_hector_case_splitting_procedure "case_split_strategy"
fvassume -expr "spec.opcode(1)==3'd3"
fvassert -expr "impl.vld(7) |-> (spec.out(1)==impl.res(7))"
fvcover -expr "impl.res(3)==4'd6"
fvdelete <propName>
caseAssume (spec.mult(1)==2'd0)
set_hector_rew_use_dps_engine true
set_hector_rew_dps_solve_script __hector_orch_custom_dps2
set_hector_rew_dps_resource_limit 1200
run_all_hdps_options
set_app_var fml_vacuity_on true
set_app_var fml_witness_on true
set_resource_limit 200
set_hector_task_timeout 1000
set_host_file hostfile
check_fv
solveNB proofName
solveNB_init proofName
check_fv -stop
check_fv -block
proofwait
```

### 12.4 报告与调试

```tcl
listproofs
listtask
listassumes
listlemmas
listcovers
save_session
restore_session
vcf -restore -session session
view_trace -property propertyname
simcex propertyname -print -joint_compile
simcex propertyname -gdb -print
view_trace -vacuity property
view_trace -witness property
set_app_var dpv_dynamic_orch true
set_app_var dpv_do_parallel_proof_size 4
set_app_var dpv_do_ignore_script true
set_custom_solve_script "orch_abo_sat"
set_hector_multiple_solve_scripts true
set_hector_multiple_solve_scripts true
set_hector_multiple_solve_scripts_list [list scripts]
show_all_solve_scripts
get_all_solve_scripts
report_fml_engines
report_fml_jobs
set_cutpoint impltop.partial
cutpoint cutname = impl.partial(3)
conflictcore
fvtask -create task
fvtask -delete task
fvtask task
quit
```

### 12.5 输入格式

- C/C++/SystemC 文件
- RTL 文件
- SVA 文件
- Tcl 文件

## 13. LPC：低功耗连通性检查应用

### 13.1 作用

LPC 用于检查电源意图和低功耗连接是否符合功能要求，常与 CC 和 SEQ 配合使用。

### 13.2 设计搭建与初始化

```tcl
set_fml_appmode CC
fvlp_instrument -type "iso pnm"
set_fml_var fvlp_enable_pst_constraint true
set_blackbox -designs module
set_blackbox -cells hier_instance
report_blackbox
set_fml_var fml_cc_autobbox false
read_file -top top -format verilog -vcs {-f filelist}
analyze -format verilog -vcs {-f filelist}
elaborate top
read_upf <upf file>
create_clock clk -period 100
create_reset rst -sense high
set_constant testmode -value 1'b0
get_fvlp_free_supply_nets
fvlp_set_supply_aon <supply name>
fvlp_set_supply_onoff_net -netname <ctrl sig> <supply name>
flp_cc_vacuity_gen_split <default for all vacuous property/property name>
flp_cc_vacuity_report <default for all vacuous properties/property name>
```

### 13.3 验证与调试

```tcl
fvdisable prop_name
fvenable prop_name
set_fml_var fml_max_time 24H
set_fml_var fml_max_memory 32GB
set_fml_var fml_progress_time_limit 2H
set_grid_usage -type RSH=10
set_grid_usage -file hostfile
set_fml_var fvlp_enable_vacuity_creation true
set_fml_var fvlp_enable_witness_creation true
check_fv
check_fv -stop
check_fv -block
check_fv -run_finish {report_fv -list}
report_load_cc
report_fv
report_fv -list
report_fv -verbose
report_fv -formatCC csv|tcl|path
save_session -session session
restore_session -session session
vcf -restore -session session
view_trace -property prop_name
view_schematic -prop prop_name
fvlp_cc_print_path prop_name
report_trace_paths [get_trace_paths -from <src sig> -to <dest sig>]
fvlp_cc_trace_fanin -dest <dest signal> -prop <prop_name>
set_cc_alias <alias name> <RTL signal name>
report_cc_alias
delete_cc_alias <alias name>
report_fv_setup -list
add_cc -src signal -dest signal -lpa_type <type>
load_cc_set_param param_name "%<value>%"
load_cc -format csv csv file
flp_check_clamp_value -lpa_type <type> -location <self/parent> -clamp_value <0/1/latch> -enable <enable signal> <port/pin name>
report_fv_complexity
sim_save_reset
check_fv_setup
fv_setup_config
report_fml_engines
report_fml_jobs
report_fml_hosts
fvtask -create task
fvtask new_task -copy task
fvtask new_task -copy task [-assumes <list>] [-asserts <list>] [-covers <list>] [-constants <list>] [-snips <list>] [-changeats<list>] [-keep_status] [-keep_task]
fvtask task
get_fvtask
quit
```

## 14. 一页版速查

如果你只想快速记住核心差异，可以按下面的方式理解：

- FPV 是基础模式，其他多数应用都继承它的属性管理、资源配置、任务、trace、session 和退出流程。
- AEP 重点在属性自动提取和 FSM fairness。
- CC 重点在别名、连接定义和连通性提取。
- FCA 重点在 coverage DB、覆盖签收和 Auto Scale。
- FXP 重点在 X 注入、X 去除和根因分析。
- SEQ 重点在双设计映射和等价收敛。
- FRV 重点在寄存器描述文件和 register-class 报告。
- FTA 重点在故障注入、fault DB、fault clustering 和 advanced debugging。
- FuSa 重点在 fault list、检测点和安全度量报告。
- FSV 重点在源/目的路径上的安全传播检查。
- DPV 重点在 proof procedure、lemmas、HDPS 和动态编排。
- LPC 重点在 UPF、电源供给和低功耗连通性。
