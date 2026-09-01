---
title: DUT 板描述与引脚配置
type: tutorial
tags:
  - SmarTest8
  - DBD
  - pin-configuration
updated: 2026-09-01
related:
  - "[[02-测试机硬件架构与信号路径]]"
  - "[[05-电平配置与保护策略]]"
---

# DUT 板描述与引脚配置

本章说明如何从 DUT 数据手册和 DUT board 原理图建立信号、信号组、site 与 tester channel 的一致关系。完成后，读者应能审阅 pin configuration，识别方向错误、资源冲突和多 site 不对称。

## 1. 输入资料

开始配置前至少需要：

- DUT 数据手册与封装 pinout；
- 原理图、PCB 版本和 socket/probe card 图纸；
- tester configuration 与板卡通道清单；
- site 数量和 site 编号规则；
- 电源域、地、参考电压、模拟/RF/高速差分信号清单；
- 上电、下电和 relay 初态要求。

若任何资料仍是草案，应在表格中标为 `<TBD>`，不能先用猜测值填满再进入下一步。

## 2. 信号分类

| 类别 | 例子 | 配置重点 |
| --- | --- | --- |
| 数字输入 | `CLK`、`RST_N`、`EN` | tester 驱动、DUT 门限、上电初态 |
| 数字输出 | `Q[7:0]` | comparator 门限、strobe、上电高阻 |
| 双向 I/O | `SDA`、`DQ` | 方向切换、三态时间、总线外部器件 |
| 电源 | `VDD`、`VDDIO` | DPS、force/sense、限流、顺序 |
| 地 | `VSS` | 回流电流、多个接点、参考关系 |
| 模拟 | `VREF`、`AIN` | 仪器类型、屏蔽、采样和保护 |
| 差分 | `RX_P/N` | 匹配通道、共模、终端、极性 |
| Utility | relay、enable、外部控制 | 初态、动作时机、异常恢复 |

## 3. Pin 配置主表

推荐使用一张主表生成或审阅 DUT board description：

| DUT pin | Signal | 类型 | Site | Tester instrument | Channel/Pogo | 初态 | 备注 |
| --- | --- | --- | ---: | --- | --- | --- | --- |
| `<A1>` | `VDD` | power | 1 | DPS128 | `<F/S pair>` | 0 V / disabled | Kelvin |
| `<B2>` | `CLK` | digital input | 1 | PS1600 | `<channel>` | low or Hi-Z | 时钟 |
| `<C3>` | `Q0` | digital output | 1 | PS1600 | `<channel>` | receive/Hi-Z | comparator |

表内至少执行以下检查：

- 同一 site 内 DUT pin 不重复；
- 同一 tester channel 不被互斥信号重复占用；
- 差分对使用支持的通道组合，P/N 极性明确；
- 电源 force/sense 成对且接到正确电源域；
- 高压 driver、HPPMU 或特殊仪器落在具备该资源的通道；
- 所有未使用 pogo 有明确状态；
- 所有 site 的资源数量和类型一致，或差异已获批准。

## 4. Signal Group 的使用

Signal Group 适合表示总线或同类信号，例如：

```text
DATA = {Q7, Q6, Q5, Q4, Q3, Q2, Q1, Q0}
CTRL = {CLK, RST_N, EN}
```

组内顺序会影响 pattern 列和数值阅读。必须规定 MSB/LSB 顺序，并与 pattern 转换输入保持一致。

不建议把以下信号放进同一组：

- 输入与输出方向不同的信号；
- 不同电压域；
- 单端与差分资源；
- 模拟信号与数字信号；
- 不同 site 的同名信号，除非框架明确支持 site 抽象。

## 5. 多 Site 设计

以 2-site 为例，每个逻辑信号应有两个物理资源实例。逻辑测试内容可以复用，但结果必须保持 per-site 可见。

| 逻辑信号 | Site 1 | Site 2 | 对称性检查 |
| --- | --- | --- | --- |
| `CLK` | `PS1600:<ch-a>` | `PS1600:<ch-b>` | 同型号、相近路径长度 |
| `VDD` | `DPS128:<ch-c>` | `DPS128:<ch-d>` | 同电流能力、同 sense 结构 |
| `Q[7:0]` | `<8 channels>` | `<8 channels>` | 通道组和差分约束一致 |

若多个 site 共享电源通道，一个 site 的短路会影响其他 site，测得的电流也无法天然分离。只有在测试计划允许、硬件保护充分且结果解释明确时才考虑共享。

## 6. 初态与安全状态

pin configuration 不只描述“正常运行”。还应规定：

- 程序加载前，数字引脚是 Hi-Z、低电平还是其他批准状态；
- DPS 输出是否 disabled，force 值和电流限制初值是什么；
- utility relay 初始断开还是闭合；
- DUT 未上电时，哪些数字引脚禁止驱动高电平；
- 中止、超时或异常退出时如何安全下电。

> [!important] 避免反向供电
> DUT 电源关闭时，如果数字输入仍被驱动为高，电流可能经 I/O 保护结构进入内部电源域。先根据 DUT 手册确定允许状态，再安排数字驱动和 DPS 的先后顺序。

## 7. 最小离线实验

### 7.1 输入

- 已批准的离线 SmarTest 8 环境；
- 假想计数器 pin 表；
- 当前 tester configuration 的虚拟或真实资源描述。

### 7.2 操作

1. 创建一个新的教学项目或复制批准的官方示例项目。
2. 建立 `VDD`、`VSS`、`CLK`、`RST_N`、`EN` 和 `Q[7:0]`。
3. 建立 `Q_BUS` signal group，明确 `Q7` 到 `Q0` 的顺序。
4. 为单 site 分配数字通道与一对 DPS force/sense 资源。
5. 运行 DUT board description 的语法和资源检查。
6. 保存问题视图与资源分配表。

### 7.3 预期结果与通过条件

- 所有 signal 名称唯一；
- `Q_BUS` 顺序与测试计划一致；
- 没有重复通道占用；
- 电源和地没有被配置成普通数字引脚；
- 工具不报告未解释的资源错误。

这只能证明离线描述一致，不能证明实际 DUT board 连接正确。

## 8. 故障处理

| 现象 | 可能原因 | 检查 | 处理 |
| --- | --- | --- | --- |
| 全部 pattern 在某一 bit 失败 | bit 顺序或 channel 对应错误 | 比较 pinout、DBD、pattern header | 修正唯一事实来源并重新生成 |
| 只有某个 site 的总线反序 | site 复制时通道顺序改变 | 导出 per-site 表逐列比较 | 恢复一致的 MSB/LSB 规则 |
| 工具提示 resource conflict | 同一 channel 被重复使用 | 按 pogo/channel 排序主表 | 重新分配资源 |
| 上电即限流 | VDD 与 VSS、force/sense 或 relay 错接 | 断电后做连通和阻值检查 | 修复硬件，不提高限流掩盖问题 |
| 差分输入无数据 | P/N 反接或通道不支持配对 | 查看板卡通道约束和示波测量 | 调整 pin plan 或 DUT board |

## 9. 练习

> [!question] 多 Site 电源
> 两个 site 共用一个 DPS 通道，测试结果只记录总电流。能否用总电流除以 2 得到每颗 DUT 的 IDD？

> [!note]- 参考答案
> 不能直接这样做。两颗 DUT 的电流通常不同，其中一颗失效时还会改变总电流和供电电压。若测试要求 per-site IDD，应提供可分离的电源测量资源或经过论证的切换方案。

## 10. 本章检查

- [ ] pin 主表包含 DUT pin、signal、site、仪器、channel/pogo 和初态；
- [ ] signal group 的位序已有书面规则；
- [ ] 多 site 对称性逐项检查完成；
- [ ] 中止和异常退出有安全状态；
- [ ] 离线结果没有被写成真实连接确认。
