---
title: V93000 多 Site 与量产导入
type: tutorial
tags:
  - ATE
  - V93000
  - multisite
updated: 2026-09-01
related:
  - "[[04-DUT板描述与引脚配置]]"
  - "[[10-调试、Datalog、Shmoo与Margin]]"
  - "[[14-DUT板、校准与安全]]"
---

# V93000 多 Site 与量产导入

本章说明怎样把单 site 工程扩展为多 site，并把工程调试条件转换为受控的量产运行条件。多 site 的目标不是简单复制 pin，而是在相同测试意图下让每个 site 的资源、结果与异常处理均可追踪。

## 1. 多 Site 增加了什么

单 site 中一个信号通常对应一个 tester channel；多 site 中，同一逻辑信号会对应每个 site 的物理通道。需要同时检查：

- 每个 site 的 pin 对应关系；
- 电源资源是独立还是共用；
- 有源电流、PMU 和外部仪器能否同时服务所有 site；
- pattern 与 Test Method 是否按 site 保存结果；
- 某个 site 失败时，其余 site 是否继续；
- handler/prober 的 site 编号是否与测试程序一致。

## 2. 扩展步骤

1. 冻结已经通过相关性检查的单 site 版本；
2. 建立 site-to-channel 表，不手工复制未复核的编号；
3. 运行 pin 配置与资源冲突检查；
4. 先只连接一个 site，确认多 site 工程的 site 0 行为；
5. 逐个增加 site，记录电流、功能结果和执行时间；
6. 比较每个 site 的 continuity、leakage、IDD 和 timing margin；
7. 检查 fail-site disable、分档和下一颗 DUT 的状态清理；
8. 再接入 handler/prober。

## 3. 资源共享检查表

| 资源 | 需要确认 | 常见风险 |
| --- | --- | --- |
| PS1600 pin electronics | 每 site 通道与宽范围 driver 位置 | 某 site 缺少特殊资源 |
| DPS128 | 每通道电流、并联通道数与总功率 | 多 site 同时上电触发保护 |
| HPPMU/外部仪器 | 是否可并发或需要串行切换 | 读到错误 site 或测量时间过长 |
| utility line/relay | 是每 site 独立还是共用 | 一个 site 的动作影响其他 site |
| DUT board | 电源回路、地回路与热分布 | site 间压降或温升不一致 |

## 4. Per-site 结果

Test Method 必须把每个 site 的测量值与 site 编号一起交给结果系统。重点检查：

- 结果数组长度与 active site 数一致；
- disable site 后，数组索引没有错位；
- limits 对所有 site 相同还是由已批准的配置选择；
- 总体 suite 结果与每个 site 结果一致；
- soft bin 与 hard bin 能区分测试失败、接触失败和系统异常。

不要把多 site 平均值作为单颗 DUT 的结果。平均值可能掩盖某个 site 的异常。

## 5. 量产前的状态测试

至少执行以下场景：

| 场景 | 要确认的结果 |
| --- | --- |
| 全部 site pass | 正常分档、数据完整、执行时间稳定 |
| 只有一个 site fail | 该 site 正确分档，其余 site 行为符合策略 |
| 某 site 接触失败 | 能与器件电气失败区分 |
| 用户 abort | 电源关闭、relay 回到安全状态 |
| Test Method 异常 | 不遗留强制电压、电流或运行中的 pattern |
| handler 超时 | 软件与设备均能恢复到可重新开始的状态 |

## 6. 相关性

相关性样本应覆盖 pass、接近限值和已知 fail 器件。对每个数值测试比较：均值差、离散程度、site 差异和重复性。对功能测试比较 first-fail 是否一致，而不仅比较最终 bin。

若某个 site 的结果持续偏移，应先检查硬件路径、校准、接触和温度，不应直接建立 site 专用宽限值。

## 7. 量产发布包

- 测试程序与 Test Method 库版本；
- tester class、板卡型号、许可和最低 SmarTest 版本；
- DUT board、socket/probe card 与 handler/prober 配置；
- limits、bin 表和数据格式；
- 上电、下电、abort 与异常恢复说明；
- golden unit 或相关性样本清单；
- 已知限制与禁止操作；
- 回退到上一版本的方法。

## 8. 常见失败

| 现象 | 可能原因 | 检查 | 处理 |
| --- | --- | --- | --- |
| 只在满 site 时电源失败 | 总电流、功率或压降增加 | 逐 site 增加并记录 V/I | 修正电源分配或测试并发方式 |
| fail site 与 handler site 不一致 | site 编号定义不同 | 用已知器件逐 site 验证 | 统一设备与程序编号 |
| disable 一个 site 后结果错位 | 数组按 active site 次序处理错误 | 打印 site ID 与结果索引 | 按 API 的 site 标识取值 |
| 首颗正常，下一颗异常 | 状态未清理 | 检查 abort/结束动作 | 显式恢复 relay、level、timing 和电源 |

## 9. 本章检查

- [ ] 单 site 基准版本已经冻结；
- [ ] 每个 site 的物理通道和共享资源已复核；
- [ ] per-site 结果与 handler/prober 编号一致；
- [ ] pass、fail、abort、超时场景均完成状态检查；
- [ ] 发布包包含版本、硬件条件和回退方法。

