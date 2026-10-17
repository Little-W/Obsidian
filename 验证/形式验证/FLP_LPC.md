# FLP / LPC：低功耗连通性形式验证完整指南

> **第 16 册 · 专用应用**　Formal Low Power / Low Power Connectivity Check。依据 User Guide 第 24 章（第 1040～1065 页）及 Quick Reference Guide 的 Low Power Connectivity Check 部分。

## 1. 核心问题

低功耗 SoC 通过不同电源域、电源关断、隔离单元、保持寄存器和电源控制器降低功耗。在普通 RTL 连通性检查中，信号可能看起来已经正确相连，但电源域关断后仍可能把未知或无效数据送到始终通电的逻辑；隔离控制接反，可能导致不同电源状态下的功能不符合规格。

FLP CC 将 RTL 与 UPF（Unified Power Format，IEEE 1801）电源意图结合，验证在相应电源状态及使能条件下，指定源与目的的连通性规则是否成立。它不只是检查 UPF 文件能否成功解析，还要分析电源意图对 RTL 的功能影响。

![低功耗域和隔离输出](插图/14_FLP电源域.svg)

## 2. 重要对象

| 对象 | 解释 | 例子 |
|---|---|---|
| Power domain | 电源控制范围 | 可关断图像处理域 |
| Supply net / set | 电源网络与电压状态 | `VDD_CORE` |
| Isolation | 电源关断时对跨域输出进行限制 | 下游锁定为 0 |
| Retention | 保存关断前需要恢复的状态 | 睡眠前的配置位 |
| Power state table | 组合描述电源合法状态 | 工作、待机、关断 |
| Power controller | 控制电源和隔离时序 | 关断前先使能隔离 |

要求明确：何时隔离、生效电平是什么、钳位值为何、是否需要恢复保存状态。普通 CC 的组合连接模型不足以单独表达所有电源关闭的效果。

## 3. 该版本的工作模式

Quick Reference Guide 的低功耗流程不是直接输入 `set_fml_appmode FLP`，而是：

```tcl
set_fml_appmode CC
fvlp_instrument -type "iso pnm"
set_fml_var fvlp_enable_pst_constraint true
read_file -top lp_top -format sverilog -vcs {-f filelist.f}
read_upf power_intent.upf
create_clock clk -period 100
create_reset rst_n -sense low
```

`fvlp_instrument` 启用低功耗语义插桩，`-type` 可根据设计需要选择 `iso`、`pnm`、`ret` 等，具体支持类型参照 UG 1043 页。插入低功耗支持、读入 RTL/UPF 的顺序需要与安装版本示例一致。`read_upf` 中的路径必须指向该工程真实 UPF 文件。

## 4. 最小系统案例

上游处理单元运行于可关断电源域 `PD_A`，下游控制单元在始终通电的 `PD_AON`。上游输出 `data_o` 经隔离单元到下游 `data_i`。规格：当 `PD_A` 供电正常且隔离关闭时，`data_i` 应等于 `data_o`；当 `PD_A` 关断时，`data_i` 应被钳位为零。

检查分两部分：功能连接和隔离钳位。前者可使用带电源条件的 `add_cc`；后者可使用 `flp_check_clamp_value` 等专门命令。具体命令需提供符合本版本要求的 `-lpa_type`、`-location`、`-clamp_value`、`-enable` 和层级对象。

```tcl
# 仅为表达对象的示意；根据 UPF 名称和命令帮助填写合法类型
# add_cc -src u_a.data_o -dest u_aon.data_i -lpa_type <type>
# flp_check_clamp_value -lpa_type <type> -location <self|parent> \
#    -clamp_value 0 -enable iso_en u_aon.data_i
```

以上包含 `<...>` 的两行是示例占位内容，不得未经替换直接运行。

## 5. UPF 可信性与 PMC

UPF 应由电源架构负责人确认电源域划分、电源状态、隔离和保持策略；必要时还需为真实电源管理控制器（PMC）建立环境模型。UG §24.2 提到可为不存在于形式 RTL 的 PMC 建模其外部行为，不能把这种模型误当作 RTL 自身需要被证明的功能。错误地假设所有电源域永久打开，将直接屏蔽很多低功耗缺陷。

## 6. FLP CC 和普通 CC 的重要区别

**User Guide 第 1041 页明确说明：FLP CC 不支持连通性延迟检查。** 因此不能直接把普通 CC 中的 `path_delay` 用例复制到低功耗检查环境。对于寄存器延迟、时序握手或跨时钟的低功耗交互，需要以另一套适当的功能属性或等价流程验证，而非宣称 FLP CC 已证明它们。

## 7. 主要命令与用途

| 命令 | 用途 |
|---|---|
| `set_fml_appmode CC` | 在 CC 模式启动低功耗检查 |
| `fvlp_instrument -type ...` | 启用隔离/电源网络/保持等插桩 |
| `read_upf` | 读入电源意图并建立相关模型 |
| `get_fvlp_free_supply_nets` | 查询没有充分控制的电源网络 |
| `fvlp_set_supply_aon` | 将指定电源声明为始终打开 |
| `fvlp_set_supply_onoff_net` | 连接电源控制信号与供电网络 |
| `add_cc ... -lpa_type ...` | 定义带低功耗类型的连接规则 |
| `flp_check_clamp_value` | 检查预期隔离钳位 |
| `flp_cc_vacuity_gen_split` | 辅助分析条件不可满足造成的空洞结果 |
| `flp_cc_vacuity_report` | 查看有关空洞报告 |
| `fvlp_cc_print_path` | 输出低功耗连接的追踪路径 |

## 8. 三个需要分别检查的场景

**正常通电：**隔离关闭时功能数据能够到达下游；**关断阶段：**隔离在失去电源前启动、钳位值正确并持续；**恢复阶段：**电源回到合法状态后，对隔离解除、复位和保持恢复的顺序进行验证。第三阶段常涉及跨周期时序，可能需要 FPV 与电源控制器的状态属性配合。

## 9. 调试方法

从失败的低功耗连接属性开始，检查 UPF 的源目的供电网络、`iso_en` 及电源状态，再查看波形或 Power Browser。特别注意电源状态表是否包含不实际的组合、隔离使能是否被形式环境错误固定、以及低功耗插桩是否真正参与了编译。不能仅因为正常供电情况下路径连接正确就结束验证。

## 10. 参考

User Guide §24（1040～1065 页），Quick Reference Guide Low Power Connectivity Checking 部分；涉及 UPF 语法时还应参考项目采用的 IEEE 1801 版本与电源意图开发规范。
