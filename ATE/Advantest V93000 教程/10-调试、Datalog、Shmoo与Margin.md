---
title: V93000 调试、Datalog、Shmoo 与 Margin
type: tutorial
tags:
  - ATE
  - V93000
  - debug
updated: 2026-09-01
related:
  - "[[08-Test-Method、Test-Suite与Testflow]]"
  - "[[19-SmarTest-7-Testflow表达式与Test-Suite覆盖项]]"
  - "[[20-界面操作图解与截图索引]]"
---

# V93000 调试、Datalog、Shmoo 与 Margin

本章建立从“某个 Test Suite 失败”到“能重复、能解释、能复测”的调试方法。完成后，读者应能分清配置错误、功能错误、时序错误、电平错误和接触问题，并能设计不会破坏 DUT 的 Shmoo。

## 1. 调试的证据顺序

每次失败按由低风险到高成本的顺序检查：

1. 项目是否正确解析，Eqnset、Specset、Levelset、Timingset、Pattern 是否选对；
2. 实际展开值是否与预期一致；
3. first-fail cycle、失败信号和预期字符是什么；
4. 单 site、低速、额定电压条件下是否重复；
5. 实测电压、电流和波形是否支持软件结论；
6. 更换 DUT、site 或板位后现象是否随对象移动。

不要在同一次尝试中同时改 level、timing、pattern 和 limits。否则即使结果由 fail 变为 pass，也无法知道是哪项改变起作用。

## 2. Datalog 最低字段

| 字段 | 作用 | 缺失后的问题 |
| --- | --- | --- |
| lot、wafer、x/y 或器件编号 | 识别 DUT | 无法复测同一颗器件 |
| tester、test head、site | 识别硬件位置 | 无法发现 site 差异 |
| 程序版本与配置版本 | 识别软件条件 | 结果不可复现 |
| test number、suite、test name | 识别测试项 | 分析工具难以归类 |
| 结果值、单位、上下限 | 判断测量状态 | 只剩 pass/fail |
| bin、停止原因 | 描述流程结果 | 难以区分首次失败与最终分档 |
| 温度、电源条件、关键模式 | 描述测试条件 | 不同条件被混在一起 |

数据记录应保留原始测量值。只记录 `pass` 或 `fail` 会丢失漂移、site 偏移和接近限值的信息。

## 3. First Fail 使用方法

数字功能失败时，先记录：

- 失败 pattern/label；
- 第一个失败 cycle；
- 失败 pin 或 pin group；
- 期望低、期望高还是不比较；
- 当时使用的 level、timing 和 operating sequence；
- 是否在所有 site 同一周期失败。

若所有 site 在完全相同的逻辑周期失败，优先检查 pattern、复位、协议和 compare 字符。若只有固定 site 失败，优先检查接触、DUT board 路径、校准和物理通道。

## 4. Shmoo 设计

Shmoo 用两项变量扫描 pass/fail 区域。常见组合有：

| X 轴 | Y 轴 | 要回答的问题 |
| --- | --- | --- |
| timing spec | VDD | 速度随电源如何变化 |
| strobe | VDD | 输出有效区是否移动 |
| `VIH` | `VIL` | 输入识别余量是否合理 |
| `VOH` | `VOL` | 输出比较窗口在哪里 |

安全 Shmoo 必须同时写明：起点、终点、步长、停机条件、恢复值和最大执行时间。电压扫描不能越过 DUT 绝对最大值、测试板限制或当前硬件模式范围。

### 4.1 推荐扫描顺序

1. 在 nominal 条件运行一次，确认基准 pass；
2. 缩小到单 site 和短 pattern；
3. 先做一维扫描，确认方向和停止条件；
4. 再做二维扫描；
5. 保存轴变量、实际展开值、site 和温度；
6. 扫描结束后显式恢复 nominal 值，再执行一次基准测试。

> [!warning] 必须恢复规格值
> SmarTest 7 的 Testflow 可以临时改变 Level 或 Timing spec。公开培训手册提醒，如果不显式恢复，后面的 Test Suite 可能继续使用改变后的值，而编辑器图标未必能直观看出这种变化。

## 5. Margin 与 Shmoo 的区别

- Margin 常用于寻找单项参数的通过到失败转折位置；
- Shmoo 同时扫描两项参数，观察通过区域形状；
- 两者都只能说明被测样品、当时温度和当时硬件条件下的现象；
- 找到宽通过区不等于已经证明量产条件充分。

## 6. 常见图形解释

| 现象 | 初步解释 | 下一步 |
| --- | --- | --- |
| 通过区整体随 site 平移 | 路径延迟、门限或接触差异 | 对比 per-site 波形和校准 |
| 通过区有孤立 fail 点 | 重试、噪声、pattern 状态或不稳定接触 | 增加重复次数并保留原始记录 |
| 低压高速角落失败 | DUT 性能或时序余量不足 | 分离 VDD、输入 edge 与 strobe |
| nominal 点也失败 | 基本配置尚未正确 | 停止扫描，返回 first fail |
| 扫描后后续测试改变 | 规格值没有恢复 | 在退出路径恢复并复测基准 |

## 7. 最小调试实验

### 输入

- 一个稳定通过的数字 Test Suite；
- 一个只改变 strobe 的测试副本；
- 单 site、额定电压、室温条件。

### 操作

1. 记录 nominal strobe 与实际展开值；
2. 向早、向晚各扫描 5 个点；
3. 每点至少重复 3 次；
4. 保存 first-fail、pass/fail 和执行时间；
5. 恢复 nominal strobe 并再次运行。

### 预期结果与通过条件

- nominal 点在扫描前后均通过；
- 数据文件包含轴值、单位、site 和 suite；
- 失败区可以在同一条件重复；
- 未出现电流保护、异常温升或 DUT 状态无法恢复。

## 8. 本章检查

- [ ] 失败时先保存条件再修改设置；
- [ ] datalog 保留数值、单位和限值；
- [ ] Shmoo 有安全范围、步长、停止条件和恢复动作；
- [ ] 已区分共同逻辑失败与固定 site 失败；
- [ ] 扫描结束后重新验证 nominal 点。

