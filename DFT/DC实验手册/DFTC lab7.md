---
title: 实验 7：自顶向下扫描插入
type: lab-guide
tags:
  - DFT
  - 扫描插入
  - scan configuration
  - lock-up latch
  - 实验
updated: 2026-08-12
---

# 实验 7：自顶向下扫描插入

术语参照：[[术语与翻译规范]]。

## 实验目标

完成本实验后，应能够：

- 使用 preview_dft 比较不同扫描规格，迭代得到平衡的顶层扫描架构。
- 使用 preview_dft 确认扫描信号规格是否被正确应用。

**实验时长**：约 45 分钟。

## 扫描前流程（Unmapped Flow）与门级流程（Mapped Flow）

### 扫描前流程（Unmapped Flow）

1. 将 RTL 读入 DFTC。
2. 创建并保存测试协议，验证设计与协议兼容。
3. 编译并保存门级设计，退出工具。

### 门级流程（Mapped Flow）

4. 将门级设计和测试协议读入 DFTC。
5. 指定扫描约束，并预览应用后的扫描架构。
6. 插入扫描链。
7. 将设计及相关文件交给下游工具。

## 工程目录

```
lab7_topdown/        当前工作目录
├── analyzed/         中间分析文件
├── logs/             会话日志
├── unmapped/         扫描前协议
├── mapped/           门级网表
├── mapped_scan/      扫描门级网表
├── reports/          DFTC 报告
├── tmax/             下游工具文件
├── scripts/          约束和运行脚本
├── ref/rtl/ORCA/     ORCA 设计文件
└── ref/lib/          工艺库
```

## 任务 1：读入门级设计和测试协议

Mapped Flow 使用以下脚本：

```
4read_gate_and_protocol.tcl
5preview_dft.tcl
6insert_dft.tcl
7handoff.tcl
```

运行：

```
cd lab7_topdown
dc_shell | tee logs/lab7.log
exec cat scripts/4read_gate_and_protocol.tcl
source scripts/4read_gate_and_protocol.tcl
```

## 扫描状态与 DRC

### 1. 查看扫描状态

```
report_scan_state
```

### 问题 1

**问题**：如果 Unmapped Flow 以 `compile -scan` 结束，刚读入的设计应该是什么扫描状态？这是否是设计当前的扫描状态？

**答案**：示例为 `scan cells replaced with loops`；是，这就是当前设计记录的扫描状态。这里的 “replaced with loops” 是 DFTC 对已被扫描替换/扫描感知综合设计的状态描述。

> [!note] 提示
> 该状态表示扫描单元已替换为环回结构。

![图：扫描状态图](../.assets/figures/lab7-p06-scan-state.png)

### 问题 2

**问题**：总触发器中有多少比例是有效扫描单元？

**答案**：示例为 2,926 / 2,958：

```
2926 / 2958 = 98.918%
```

![图：顺序单元统计图](../.assets/figures/lab7-p06-sequential-summary.png)

### 问题 3

**问题**：只考虑这个比例，预计测试覆盖率范围是多少？

**答案**：约 98.9% 上下。这个只是基于有效扫描单元比例的粗略预测，实际覆盖率还受到组合可控性、时钟、复位、黑盒和 ATPG 约束影响。

### 问题 4

**问题**：增强版 DFT DRC 报告中的顺序单元统计是否符合预期？

**答案**：符合。报告仍应显示约 2,926 个有效扫描单元、2,958 个顺序单元，总体比例约 98.9%。

### 2. 打开增强报告并查看 DFT 信号

```
set_test_disable_enhanced_dft_drc_reporting false
dft_drc
report_dft_signal
```

## 任务 2：预览扫描架构

### 问题 5

**问题**：报告了多少个 ScanClock 和 Reset？

**答案**：3 个扫描时钟：sys_clk、sdr_clk、pclk；1 个复位：prst_n。

> [!note] 提示
> `3 个 scanclocks (sys_clk, sdr_clk, pclk); 1 个 resets (prst_n)`。

![图： report_dft_signal 图](../.assets/figures/lab7-p07-dft-signals.png)

![图：扫描时钟与默认扫描链预览](../.assets/lab7-p07.png)

### 1. 查看默认扫描架构

```
preview_dft
```

示例默认信息：

```
Scan methodology: full_scan
Scan style: multiplexed_flip_flop
```

### 问题 6

**问题**：默认会插入多少条扫描链？链名是什么？是否平衡？

**答案**：示例预览 5 条链，链名类似 test_si1→test_so1、test_si2→test_so2、test_si3→test_so3、test_si4→test_so4、test_si5→test_so5。长度约为 1,074:1，极不平衡。

> [!note] 提示
> 本例的预览结果为 5 条扫描链，最长链与最短链长度约为 `1074:1`，差异很大。

![图：默认 preview_dft 图](../.assets/figures/lab7-p07-preview-default.png)

### 问题 7

**问题**：扫描插入使用已有功能引脚作为 scan in、scan out，还是创建专用的新引脚？

**答案**：因为当前没有指定扫描信号，工具会创建新的扫描端口/连接。若要复用功能引脚，必须用 set_dft_signal 或 set_scan_path 显式指定。

### 2. 查看时钟域

```
preview_dft -show scan_clocks
```

### 问题 8

**问题**：为什么默认预览 5 条扫描链？

**答案**：这是当前工具/实验设置下的默认链数或默认扫描分配策略；工具会按时钟域、扫描段和默认 chain_count 生成多条候选链。不要把 5 当作所有设计的通用默认值，应以 preview_dft 报告和当前版本设置为准。

> [!note] 提示
> 若报告中给出的时钟域数量与 `pclk`、`sys_clk`、`sdr_clk` 三类测试时钟不一致，应以当前 `preview_dft` 报告中的扫描分区结果为准。

## 比较 clock mixing

### 问题 9

**问题**：scan_clocks 预览中是否有 scan_summary 没有的信息？什么时候使用 scan_summary？

**答案**：有。scan_clocks 会显示每条链涉及的时钟、边沿、代表性单元和时钟域；scan_summary 更紧凑，适合快速查看链数、端点、长度和整体平衡。需要分析多时钟/多边沿问题时使用 scan_clocks，需要快速汇总时使用 scan_summary。

> [!note] 提示
> `scan_clocks` 输出时钟信息更完整；当扫描链较多时，`scan_summary` 更适合快速查看链数、端点、长度和均衡程度。

```
preview_dft -show scan_summary
```

### 1. 允许同一时钟的不同边沿混合

```
set_scan_configuration -clock_mixing mix_edges
preview_dft -show scan_clocks
```

### 问题 10

**问题**：现在预览多少条链？是否平衡？

**答案**：示例显示 3 条链，相比默认结果相对平衡，但仍不够理想。

> [!note] 提示
> `3. 相对较平衡了，但不够。`

![图： mix_edges 扫描链图](../.assets/figures/lab7-p08-mix-edges.png)

### 2. 允许不同测试时钟混合

```
set_scan_configuration -clock_mixing mix_clocks
preview_dft -show scan_clocks
```

### 问题 11

**问题**：现在预览多少条链？如何理解默认 chain_count？

**答案**：示例显示 1 条链，包含 2,926 个扫描单元。允许不同测试时钟混合后，工具可以把多个时钟域放入同一链；这也说明仅改变 clock_mixing 会显著改变链数，默认 chain_count 不能脱离时钟混合策略解释。

![图： mix_clocks 扫描链图](../.assets/figures/lab7-p08-mix-clocks.png)

### 问题 12

**问题**：什么规格可以得到 6 条相对平衡的扫描链？

**答案**：设置 chain_count 为 6，并选择适合的 clock_mixing 策略：

```
set_scan_configuration -chain_count 6
preview_dft -show scan_clocks
```

`clock_mixing` 的含义如下：

| 值 | 含义 |
| --- | --- |
| no_mix | 同一条链只能使用同一时钟、同一边沿 |
| mix_edges | 时钟相同，但允许不同边沿 |
| mix_clocks_not_edges | 边沿相同，但允许不同测试时钟 |
| mix_clocks | 允许不同的时钟和边沿 |

## lock-up latch 与链平衡

### 1. 为什么需要 lock-up latch

当一条扫描链跨越不同的时钟边沿或时钟域时，前一级扫描单元的输出可能在后一级采样窗口附近变化。lock-up latch 用于隔离时钟相位/偏斜，保证扫描移位稳定。

### 问题 13

**问题**：当前 6 条链中最长和最短链相差多少？

**答案**：示例为几乎没有差异；多数链为 488 个单元，最短链为 487 个单元，差异约 1 个扫描单元。

> [!note] 提示
> 最长链与最短链的长度仅相差 1 个扫描单元。

![图：平衡扫描链图](../.assets/figures/lab7-p09-balanced-chains.png)

### 问题 14

**问题**：DFTC 是否会插入 lock-up latch？哪些链会包含？

**答案**：会。提示答案写的是：`yes. 2, 4, 5.`，即链 2、4、5 可能包含 lock-up latch；正文曾只列链 4、5，这里按说明补全。最终以 scan_clocks 和插入后网表报告为准。

### 2. 指定功能引脚和链名

```
source scripts/settings_insert_dft.tcl
preview_dft
```

### 问题 15

**问题**：新的扫描链叫什么？什么命令定义了这些名字？为什么要显式命名？

**答案**：示例链名为 chain0、chain1、chain2、chain3、chain4、chain5。由 set_scan_path 定义：

```
for {set i 0} {$i < 6} {incr i} {
    set_scan_path chain$i -view spec \
        -scan_data_in pad[$i] \
        -scan_data_out sd_A[$i]
}
```

显式命名可以将逻辑链名与实际 `pad`/`scan-out` 端口固定关联，便于交付、SCANDEF、ATE 和后端流程使用。

> [!note] 提示
> 预览报告中的链名被显式设为 `chain0` 至 `chain5`，而不是仅使用数字。

![图： scan path 端口工艺实现图](../.assets/figures/lab7-p09-pad-mapping.png)

### 问题 16

**问题**：scan in、scan out、scan enable 使用哪些引脚？

**答案**：

- scan in：pad[0] 到 pad[5]。
- scan out：sd_A[0] 到 sd_A[5]。
- scan enable：scan_en。
- 扫描主时钟：sys_clk、sdr_clk、pclk。
- 复位：prst_n。

## 任务 3：插入扫描链并估算覆盖率

### 问题 17

**问题**：哪个命令可以避免插入扫描时所有子设计被重命名？

**答案**：set_dft_insertion_configuration，并设置 preserve_design_name：

```
set_dft_insertion_configuration -preserve_design_name true
```

![图： preserve_design_name 选项图](../.assets/figures/lab7-p10-preserve-design-name.png)

### 问题 18

**问题**：该命令的哪个选项可以关闭插入末期的门级优化？

**答案**：synthesis_optimization none：

```
set_dft_insertion_configuration -synthesis_optimization none
```

![图： synthesis_optimization 选项图](../.assets/figures/lab7-p10-synthesis-optimization.png)

这可以减少 insert_dft 阶段的运行时间和对既有门级设计的改动。

### 2. 插入和覆盖率

```
source scripts/6insert_dft.tcl
dft_drc -coverage_estimate
```

### 问题 19

**问题**：ORCA 扫描设计的估算覆盖率是多少？

**答案**：示例为 95.28%。

![图： 95.28% 覆盖率图](../.assets/figures/lab7-p10-coverage.png)

### 问题 20

**问题**：这个估算与前面仅根据有效扫描单元比例的预测相比如何？

**答案**：明显低于约 99% 的早期预测，只有 95.28%。原因是覆盖率还受到 DFT DRC、时钟混合、三态、总线驱动、扫描链结构和 ATPG 可解性的影响。

> [!note] 提示
> 多测试时钟、lock-up latch 和 DRC 违规都会降低覆盖率，因此有效扫描单元比例不能单独决定最终 ATPG 覆盖率。

## DFT 设计规则检查（DFT DRC）与扫描规则

示例报告了会影响 ATPG 覆盖率的违规，例如：

- C17：时钟连接到 primary output。
- S22：一条扫描链由多个时钟移位。
- 与扫描单元 gate 连接的总线驱动器违规。

![图： DRC coverage 违规汇总图](../.assets/figures/lab7-p11-drc-summary.png)

![图： DRC coverage 详细图](../.assets/figures/lab7-p11-drc-details.png)

### 问题 21

**问题**：为什么 S 类/扫描链类别违规不能在 Pre-DFT 检查中报告？

**答案**：扫描插入前阶段（Pre-DFT）尚未真正插入扫描链，工具没有扫描链结构、链名和单元顺序，因此只能检查扫描前的时钟、复位、模型和结构连接问题；扫描链规则必须在扫描插入后阶段（Post-DFT）检查。

### 问题 22

**问题**：S22 违规是什么意思？它是否解释了 Sequential Cells Without Violations 中的 synchronization elements？

**答案**：S22 表示同一条扫描链使用多个移位时钟，或使用同一时钟的不同边沿。这个条件可能在移位时产生时钟偏斜/竞争，因此工具会建议或插入 lock-up latch 作为同步隔离。示例在 chain1 上出现一个 S22，并提示还有其他同类单元；需要逐条确认是否缺少 lock-up latch，而不能只看 warning 数量。

> [!note] 提示
> S22 表示同一条扫描链使用多个时钟，或使用同一时钟的不同边沿。应检查相应位置是否需要 lock-up latch。

## 实验检查清单

- [ ] 能用 report_scan_state 验证扫描状态。
- [ ] 能解释 2,926/2,958 的有效扫描单元比例。
- [ ] 能比较 scan_clocks 和 scan_summary。
- [ ] 能解释 no_mix、mix_edges、mix_clocks。
- [ ] 能用 chain_count 6 获得平衡链。
- [ ] 能解释 lock-up latch 和 S22。
- [ ] 能固定 scan path、scan in/out、scan enable 和设计名。
- [ ] 能解释为什么实际估算覆盖率低于简单的扫描单元比例预测。
