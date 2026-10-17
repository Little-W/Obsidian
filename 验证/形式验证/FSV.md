# FSV：形式安全信息流验证完整指南

> **源码内嵌版。** 本章的完整案例以“保存为”标明文件路径，并在下方直接列出全文。代码框不带显示行号，可直接复制；`案例工程/` 只表示目录结构，不要求另找源码附件。包含占位符或保护性 `error` 的专用流程另行明确标为模板。

> **第 14 册 · 专用应用**　Formal Security Verification。依据 User Guide 第 22 章（第 961～1008 页）及 Quick Reference Guide FSV 部分。

## 1. 目标：检查本不应出现的信息传播

数字系统可能包含安全域与普通域。安全域中的密钥、认证状态、受保护计数器等信息不能在未授权条件下影响普通域输出；普通域输入也不能未经允许改变关键安全状态。FSV 用形式化的来源、目的及传播条件描述这些安全信息流要求。

与一般 CC 不同，FSV 不只是检查“需要的连接是否存在”，还要检查**禁止的信息传播是否可能发生**。示例：安全密钥不允许直接或间接影响公开的调试端口；普通外设不能未经权限检查更新可信启动状态。可见信息流分析并不自动涵盖时间侧信道、功耗侧信道以及模拟泄漏。

![FSV 安全域隔离](插图/12_FSV信息流.svg)

## 2. 什么是信息流与非干扰

假设存在高安全级输入 `secret` 和低安全级输出 `public_out`。一种非干扰（noninterference）性质要求：当普通级输入和合法初态相同时，改变 `secret` 不得改变 `public_out`，除非系统允许某种已定义的解密或公开处理。它是一种关于两种输入情况的关系，而不只是单条波形上某个值等于零。

FSV 通过源和目的定义生成信息流属性，并在形式环境中检查合法传播范围。对于含授权条件、故障检测条件或某些模式允许公开的数据，必须建模对应条件，不能只无条件禁止全部传播。

## 3. 典型命令结构

```tcl
set_fml_appmode FSV
read_file -top security_top -format sverilog -vcs {-f filelist.f}
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
check_fv_setup
fsv_generate -src secret_key -dest debug_out
check_fv -block
fsv_report
report_fv -list
```

脚本中信号名和复位过程是教学占位，真正的形式模型必须包含完整的普通输入、授权模式及初态。`fsv_generate` 的实际语法支持一个或多个源、一个或多个目的，以及 `-src_condition`、`-dest_condition`、`-exclude`、`-name`、`-zone` 等选项（见 User Guide 第 966 页）。

### 3.1 面向真实系统的完整模板

此模板用于替换成真实安全域层级；第 5 节另有完整的小型设计与运行脚本。这里保留保护性 `error`，不会把尚未审查的系统安全策略自动启用。

**保存为 `案例工程/templates/fsv_secure_flow.tcl`：**

<!-- source-begin: 案例工程/templates/fsv_secure_flow.tcl -->

```tcl
# FSV：信息流安全。请先完成 source、destination 与授权策略审查。
error "此文件是 FSV 教学模板：必须指定真正的安全源与公开输出"
# set_fml_appmode FSV
# read_file -top secure_top -format sverilog -vcs {-f filelist.f}
# create_clock clk -period 100
# create_reset rst_n -sense low
# sim_run -stable
# sim_save_reset
# fsv_generate -src u_core.secret -dest u_dbg.out
# check_fv -block
# fsv_report
```

<!-- source-end -->

## 4. 可控的允许传播

有些设计需要在合法授权后输出秘密信息的某种变换结果，例如密钥派生操作的授权输出。此时不能简单禁止所有相关数据依赖，而应制定允许传播的安全策略。FSV 的 `-src_condition`、`-dest_condition` 等选项可帮助表达仅对特定工作条件分析的信息传播。任何白名单范围都需要安全审查，避免授权信号可由不可信输入随意置位。

## 5. 案例：保护调试输出的完整工程

策略是：无论调试是否开启，公开输出都不得依赖 `secret_key`。允许调试输出普通状态，但不允许输出秘密数据。本节不用“调试永久关闭”这样的假设掩盖泄漏。

### 5.1 正确版本 RTL



**保存为 `案例工程/rtl/debug_guard.sv`：**

<!-- source-begin: 案例工程/rtl/debug_guard.sv -->

```systemverilog
// 安全策略：公开调试输出永远不得依赖 secret_key。
module debug_guard (
  input  logic       clk, rst_n, debug_enable,
  input  logic [7:0] secret_key, normal_status,
  output logic [7:0] debug_out
);
  always_comb begin
    if (debug_enable) debug_out = normal_status;
    else              debug_out = 8'h00;
  end
endmodule
```

<!-- source-end -->

### 5.2 故意泄漏的完整 RTL

两份文件模块名相同，必须分别读入。坏版只把普通状态替换为秘密数据，让读者能看清被检查的差异。

**保存为 `案例工程/rtl/debug_guard_bad.sv`：**

<!-- source-begin: 案例工程/rtl/debug_guard_bad.sv -->

```systemverilog
// 故意泄漏版本；模块名与正确版相同，必须分开编译。
module debug_guard (
  input  logic       clk, rst_n, debug_enable,
  input  logic [7:0] secret_key, normal_status,
  output logic [7:0] debug_out
);
  always_comb begin
    if (debug_enable) debug_out = secret_key;
    else              debug_out = 8'h00;
  end
endmodule
```

<!-- source-end -->

### 5.3 正确版文件列表



**保存为 `案例工程/filelist_fsv_good.f`：**

<!-- source-begin: 案例工程/filelist_fsv_good.f -->

```text
./rtl/debug_guard.sv
```

<!-- source-end -->

### 5.4 正确版完整 FSV 脚本

本例有明确的源、目的与实际 RTL，不再只使用 `security_top/filelist.f` 占位名称。仍须核对本机 `fsv_generate` 的接口及对象解析结果。

**保存为 `案例工程/scripts/fsv_debug_good.tcl`：**

<!-- source-begin: 案例工程/scripts/fsv_debug_good.tcl -->

```tcl
# 读取一个版本；先检查源/目的是否成功解析，不能把零属性当作通过。
set_fml_appmode FSV
read_file -top debug_guard -format sverilog -vcs {-f filelist_fsv_good.f}
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
check_fv_setup
fsv_generate -src secret_key -dest debug_out
report_fv -list
check_fv -block
fsv_report
report_fv -verbose
```

<!-- source-end -->

### 5.5 错误版文件列表



**保存为 `案例工程/filelist_fsv_bad.f`：**

<!-- source-begin: 案例工程/filelist_fsv_bad.f -->

```text
./rtl/debug_guard_bad.sv
```

<!-- source-end -->

### 5.6 错误版完整 FSV 脚本



**保存为 `案例工程/scripts/fsv_debug_bad.tcl`：**

<!-- source-begin: 案例工程/scripts/fsv_debug_bad.tcl -->

```tcl
# 读取一个版本；先检查源/目的是否成功解析，不能把零属性当作通过。
set_fml_appmode FSV
read_file -top debug_guard -format sverilog -vcs {-f filelist_fsv_bad.f}
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
check_fv_setup
fsv_generate -src secret_key -dest debug_out
report_fv -list
check_fv -block
fsv_report
report_fv -verbose
```

<!-- source-end -->

**运行命令（Bash）：**

```bash
# 从包含“案例工程”目录的上一级目录开始。
cd 案例工程
mkdir -p logs
set -o pipefail
vcf -f scripts/fsv_debug_good.tcl -batch 2>&1 | tee logs/fsv_debug_good.log
vcf -f scripts/fsv_debug_bad.tcl -batch 2>&1 | tee logs/fsv_debug_bad.log
```

这些命令应在本机具备相应 VC Formal 版本和许可证时执行。日志中的属性状态才是证明结论；命令退出、脚本结束或没有打印错误都不能代替属性结果检查。

**结果核查。** 正确版源端不参与输出计算，错误版在调试开启时有明确依赖。工具可能对未使用的源做优化，必须先确认属性生成、源目的解析及报告分类；零属性或对象找不到不能当作通过。示例结果仍待本机 VC Formal 执行确认。

## 6. 信息流安全与普通功能断言相互补充

FPV 可证明 `debug_enable==0` 时 `debug_out==0`，但这不一定足以证明“只要安全源变化，任何普通输出都不发生可识别的变化”。尤其如果信息通过状态机控制、地址、错误响应或其他共享资源间接传播，普通值检查可能漏掉依赖关系。FSV 帮助发现这些关联，但它也需要明确的观察范围和安全模型。

## 7. 黑盒与抽象的风险

`fsv_blackbox <instance>` 用于安全验证中指定特殊黑盒对象；它的抽象行为会影响信息流路径和可证明性。把加密模块全部黑盒化后，若未正确描述安全输出与普通输出的可见关系，结果可能既不保守也不完整。建议先建立最小原型，比较带/不带黑盒的属性数量与失效情况，再决定大型 SoC 的建模策略。

## 8. 重要命令

| 命令 | 作用 |
|---|---|
| `set_fml_appmode FSV` | 选择安全信息流应用 |
| `fsv_generate -src ... -dest ...` | 生成保护指定路径的属性 |
| `fsv_generate ... -src_condition ...` | 限定源侧条件 |
| `fsv_generate ... -dest_condition ...` | 限定目的侧条件 |
| `fsv_blackbox` | 为安全分析提供特殊黑盒配置 |
| `fsv_report` | 专门输出安全分析结果 |
| `report_fv` | 查询底层形式检查状态 |
| `view_trace -property ...` | 查看不应出现传播的反例 |

## 9. 常见错误及处理

- 忽略普通域的间接数据依赖，只检查显式赋值。
- 未考虑复位或切换安全模式期间的合法输入，导致假阳性。
- 把未知授权条件设置为恒真，从而屏蔽真实泄漏。
- 把“没有找到信息传播反例”当成“已经没有所有侧信道风险”。
- 将安全策略与实现混在同一套强制约束中，无法审查真正的安全责任。

## 10. 官方参考

User Guide §22（961～1008 页），尤其 §22.2 的源目的定义和 `fsv_generate`；Quick Reference Guide FSV 部分。
