# FRV：形式寄存器验证完整指南

> **第 11 册 · 专用应用**　Formal Register Verification。依据 User Guide 第 16 章（第 619～685 页）、Quick Reference Guide FRV 部分。

## 1. 典型目标和输入资料

SoC 中寄存器字段数量多，容易出现复位值错误、读写权限错误、写一清零行为错误、保留位处理错误、地址别名或总线包装接口问题。FRV 通过寄存器说明文件（IP-XACT XML、RALF 等）提取字段规则，产生并运行形式检查；其价值在于减少重复手工编写针对每个寄存器位的测试与断言。

输入至少包括真实 RTL、寄存器规格文件、总线协议适配及形式环境。特别注意：寄存器文件包含的**理想行为**必须与设计真实的事务接口含义一致；仅有 XML 不会使工具自动猜到哪一条总线读写应对应哪个寄存器。

## 2. 核心概念

| 寄存器属性 | 预期行为 | 应验证的例子 |
|---|---|---|
| Reset value | 复位后默认值 | 配置字段复位为零 |
| RW | 可读可写 | 写入已接受后读回一致 |
| RO | 只读 | 总线写入不能改变状态 |
| WO | 只写 | 读取行为应符合规格定义 |
| W1C | 写 1 清零 | 写 1 清对应位，写 0 不清 |
| W1S | 写 1 置位 | 写 1 置位，其他位不变 |
| Reserved | 保留位 | 写入是否被忽略、读取返回什么 |
| Volatile | 硬件可以自主更新 | 不要求所有周期保持软件写入值 |
| Side effect | 读取或写入有副作用 | 读清除、中断状态操作 |

字段策略由寄存器规范决定。不要把没有发生读写握手的周期当作已接受事务，也不能把硬件会自动变化的计数器字段视作永远保持的软件配置值。

## 3. 寄存器规格与 RTL 的对照

例如有 `CTRL`（地址 0x00，位 0 使能，RW）、`STATUS`（地址 0x04，位 0 完成，W1C）。典型教学实现是：接受对 `CTRL` 地址的写入后更新使能位；`STATUS.done` 由硬件事件置位、软件向对应位写 1 清除；异步复位全部清零。对应检查至少覆盖默认值、RW 正常写入、W1C 保持和清零，以及无效地址的处理。

FRV 的自动检查可以缩小手工工作量，但对多写入源冲突、硬件置位和软件清零同周期优先级等复杂语义，通常仍需要补充明确的 SVA。假定硬件事件优先级高于 W1C，需要实现与规格一致的条件判断。

## 4. 一个最小脚本模板

```tcl
set_fml_appmode FRV
# 二选一：实际工程提供寄存器描述文件
frv_load -ral registers.ralf -top block:REG_BLOCK -auto_load
# frv_load -ipxact registers.xml -auto_load
read_file -top reg_block -sva -format sverilog \
  -vcs {-f filelist_reg.f} bind_frv.sv
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
check_fv_setup
report_fv -class register -list
check_fv -block
frv_report
report_fv -class register -verbose
```

`bind_frv.sv` 必须实现与实际总线的接口对应关系，不能把此占位文件视作工具自动生成的所有环境组件。在上述 `-top block:REG_BLOCK` 中，`REG_BLOCK` 是 RALF 定义的地址块名称，**不是随意从 RTL 顶层抄来的实例名**；如果使用其他层级，可指定 `comp:`、`mmap:` 或 `block:`，详见 UG 第 626～630 页。IP-XACT 和 RALF 的可支持字段、命名空间及访问类型以该版本 User Guide 16.4～16.11 为准。

## 5. `frv_load` 与检查器配置

```tcl
frv_load -ipxact chip_regs.xml -auto_load
frv_load -ral chip_regs.ralf -top block:REG_BLOCK -auto_load
frv_load -parameter {VOLATILE=1}
frv_load -parameter {COVER_READ=1}
```

这些示例展示输入和参数能力，并不表示一个工程同时加载两份描述文件后能自动完成去重。UG 第 630 页给出若干用于检查器的参数示例；对易变字段、读写覆盖目标的启用与禁用，应由规格责任人决定。`frv_config` 可调整行为，`frv_report` 用于生成专用报告。使用前通过帮助确认 `frv_load` 所支持的实际格式和字段。


### 5.1 FRV 检查器和总线桥接的实际组成

UG 第 627 页说明，`frv_load` 可以生成专用的 SVA 检查器文件（默认 `frv.sv`），并可用 `-auto_load` 自动装入生成的检查器、绑定文件及库文件。对于常见的 AMBA 总线，安装目录 `$VC_STATIC_HOME/packages/Frv/` 还包含 APB、AHB、AXI 的预制适配模块，以及用于简单非 AMBA 接口的通用适配模块。

| 典型路径（以实际安装为准） | 用途 |
|---|---|
| `snps_frv_apb_wrapper.sv` | APB 总线寄存器访问抽象 |
| `snps_frv_ahb_wrapper.sv` | AHB 总线寄存器访问抽象 |
| `snps_frv_axi_wrapper.sv` | AXI 总线寄存器访问抽象 |
| `snps_frv_gen_wrapper.sv` | 一般寄存器读写接口示例 |

桥接模块主要负责把总线请求、响应、地址和有效数据准确提供给属性检查器。**提供预制适配模块并不意味着可以免除总线配置检查**：例如 AXI 的 `ready/valid` 接受时刻、超时和响应对应关系仍需核实。若 IP 自定义了特殊握手，需要编写自己的适配器并检查覆盖目标是否生成。

### 5.2 关于 `-parameter` / `-parameters` 的说明

同一版 UG 第 626 页的语法框将选项写成 `-parameters`，随后第 630 页示例写成 `frv_load -parameter {...}`。本手册保留第 630 页的示例，不推断两者均被 Tcl 接受；工程中务必使用 `frv_load -help` 确认版本可用拼写。

## 6. 结果分析的方法

如果复位值属性失败：检查该寄存器是不是在真实复位域内、复位序列是否正确、字段是否含上电未知值。若读回失败：先确定读请求是否被接受以及返回数据何时有效，再检查寄存器地址、字节使能与读数据对齐。若 W1C 失败：检查写入掩码、硬件事件与软件写清除的优先级。若很多属性都没被生成：核对寄存器描述路径与映射，不要直接把“没有失败”理解为“寄存器全部正确”。

## 7. 与 UVM RAL、仿真和 FPGA/SoC 寄存器校验的配合

软件寄存器模型适合生成仿真激励和软件驱动期望值；FRV 可以对寄存器行为进行更系统的逻辑证明。两者应复用同一权威寄存器描述，避免手工维护两份不一致的默认值。对异步硬件更新、跨时钟寄存器和只在某个模式下可写的寄存器，还应有专用接口前提和 SVA 约束。

## 8. 工程清单

- 确认 IP-XACT/RALF 字段地址、宽度、复位和访问类型均与规格一致。
- 确认总线读写接受点、字节使能、错误响应、超时与复位行为。
- 确认已经报告并审查 FRV 自动生成属性的数量及类别。
- 对 W1C/W1S/volatile/自清除等字段增加必要的手工检查。
- 对无法证明、豁免和未支持的字段单独汇总，而不是将其遗漏。

## 9. 参考资料

User Guide §16（619～685 页）及附录中的相关设计查询命令；工具安装目录 `<VC_STATIC_INSTALL>/doc/vcst/examples/FRV` 可寻找官方示例（若随本机安装）。
