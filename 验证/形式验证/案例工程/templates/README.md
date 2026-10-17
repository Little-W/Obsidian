# 专用应用配置模板（非即用工程）

这里的六个 Tcl 文件具有**防误运行的 `error` 前导语句**；默认执行会立即显示缺少输入资料的说明，不会假装分析已经通过。

| 模板 | 需要补齐的核心资料 |
|---|---|
| `frv_ralf.tcl` | 寄存器规范 RALF/IP-XACT、总线接口桥接 |
| `fta_mutation.tcl` | 已验证 FPV 环境、断言集合、变更注入策略 |
| `fusa_safety.tcl` | SFF/FDB、故障清单、检测点与观察点 |
| `fsv_secure_flow.tcl` | 安全输入/输出分级、授权规则 |
| `dpv_hector.tcl` | HECTOR C++ 包装、事务阶段、RTL 数据路径 |
| `flp_low_power.tcl` | UPF、电源状态、隔离/保持策略 |

建议先阅读同名专章，并核对本机 `vcf` 的帮助信息，再替换占位符、删除第一行 `error` 并进行首次受控运行。**不要把模板生成结果当作验证结论。**
