---
title: Pattern 与 Operating Sequence
type: tutorial
tags:
  - SmarTest8
  - pattern
  - operating-sequence
updated: 2026-09-01
related:
  - "[[06-时序、波形与数字比较]]"
  - "[[08-Test-Method、Test-Suite与Testflow]]"
---

# Pattern 与 Operating Sequence

本章说明 vector、pattern、sequencer 指令、action 和 Operating Sequence 的分工。完成后，读者应能审阅一个 pattern 是否与信号顺序、level/timing 和 DUT 初始化过程一致。

## 1. Pattern 表达什么

Pattern 是向量序列与执行控制信息的组合。每个 vector 为一组 signal 或 signal group 提供状态字符，字符的电气行为由当前 waveform 定义。

概念例子：

```text
Signals:  CLK  RST_N  EN  Q_BUS
Vector 0: 0    0      0   X
Vector 1: 1    0      0   X
Vector 2: 0    1      1   L
Vector 3: 1    1      1   H
```

上面的 `0/1/L/H/X` 只是概念字符。它们在真实项目中的含义必须回查 wavetable。例如 `H` 常表示期望高，`X` 常表示不比较，但具体行为不能脱离项目定义解释。

## 2. Pattern 的四层检查

| 层次 | 检查对象 | 典型问题 |
| --- | --- | --- |
| 信号层 | 名称、位序、方向、group | `Q7:Q0` 与转换顺序相反 |
| 波形层 | 字符引用的 waveform | 输入字符引用了 compare waveform |
| 时间层 | period、edge、strobe | strobe 早于 DUT 输出有效时间 |
| 执行层 | loop、call、match、stop | 初始化循环次数错误或无法退出 |

## 3. Sequencer 控制

常见控制功能包括 repeat/loop、call/jump、条件匹配、暂停点、切换 level/timing 和触发 action。不同 SmarTest 8 版本与 instrument mode 的具体指令名称需要在 TDC 中确认。

使用控制指令时记录：

- 入口和退出位置；
- 循环次数或超时；
- 哪些 signal 提供匹配结果；
- 超时后是 fail、继续还是安全退出；
- 是否在循环中切换 level/timing；
- 对多 site 是同步退出还是逐 site 处理。

> [!warning] 等待循环必须有超时
> 等待 DUT ready/busy 的 pattern 若没有有限次数或受控退出条件，可能造成测试停止响应。超时结果应明确记录为测试失败或设备异常，不能静默继续。

## 4. Operating Sequence 的作用

Operating Sequence 用来按顺序组合 setup、pattern 和 instrument action。例如：

```text
1. 应用安全初态
2. 选择 nominal level 与 timing
3. 执行 reset pattern
4. 等待 DUT 初始化
5. 执行 counter pattern
6. 读取 digital result
7. 恢复安全状态
```

如果一个 Test Suite 只需要单个 pattern，结构可以很简单；如果要在 pattern 内外切换 instrument action、读写寄存器或组合多个阶段，Operating Sequence 能把硬件执行顺序与 Testflow 的产品判断分开。

## 5. Action 的位置

Action 表示仪器操作，例如连接资源、施加条件、执行测量或改变 setup。一个 action 应说明：

| 字段 | 内容 |
| --- | --- |
| 资源 | 哪个 instrument、signal 或 signal group |
| 前提 | DUT 电源、relay、pattern 状态 |
| 操作 | force、measure、connect、disconnect 等 |
| 等待 | relay settle、DUT settle 或采样时间 |
| 结果 | 数值、状态或后续可读取对象 |
| 异常 | 超限、中止和安全恢复 |

不要在多个位置重复设置同一硬件而不规定优先级，否则调试视图看到的最终值可能与工程师预期不同。

## 6. Pattern 来源与转换

Pattern 常来自：

- 手写的小型功能向量；
- 设计仿真导出的波形；
- ATPG 工具生成的 scan pattern；
- 协议或寄存器访问工具生成的序列；
- STIL 等交换格式转换。

转换前后至少核对：

| 项目 | 输入侧 | V93000 侧 |
| --- | --- | --- |
| Signal | 设计端口和 scan channel | DUT board signal/group |
| Direction | drive/expect/mask | waveform 字符 |
| Time | 仿真时间或周期 | timing set 与 vector |
| State | `0/1/X/Z` 等 | 当前 wavetable 定义 |
| Procedure | scan load/unload、capture | sequencer/Operating Sequence |
| Result | expected response | compare 与 fail memory |

## 7. 最小离线实验

### 7.1 输入

- 已完成的 signal、level 和 timing setup；
- 一个包含复位和四个计数周期的小 pattern；
- 当前版本批准的 Operating Sequence 模板。

### 7.2 操作

1. 检查 pattern header 的 signal 顺序。
2. 为每种字符确认 waveform 行为。
3. 绑定 nominal level 与 timing。
4. 建立 reset、wait 和 count 三阶段 Operating Sequence。
5. 给 wait 设置有限超时。
6. 在 Pattern Debug 中逐周期查看驱动与期望。
7. 保存 binding report 和问题列表。

### 7.3 预期结果与通过条件

- 所有 signal 成功绑定；
- `RST_N` 低有效行为与 pattern 一致；
- `Q_BUS` 位序与预期计数一致；
- wait 有有限退出条件；
- 工具不报告未解释的 vector、waveform 或 setup 错误。

这仍是离线结构检查，不表示 DUT 功能已经得到确认。

## 8. 常见失败

| 现象 | 可能原因 | 检查 | 处理 |
| --- | --- | --- | --- |
| 每个 byte bit-reverse | signal group 位序错误 | pattern header 与 group 定义 | 统一 MSB/LSB 规则 |
| reset 后所有周期失败 | reset 极性、宽度或释放位置错误 | 首几个 vector 和波形 | 修正初始化 pattern |
| pattern 无法结束 | match/loop 没有超时 | sequencer 控制 | 增加有限次数和失败处理 |
| 只在某次转换后失败 | 状态字符或 procedure 转换不一致 | 转换报告和抽样 vector | 修正转换配置并重新生成 |
| pattern 能执行但结果无记录 | Test Method/Test Suite 未读取结果 | suite 绑定与 datalog | 补充结果访问和 test table |

## 9. 本章检查

- [ ] pattern signal 顺序与 DUT board description 一致；
- [ ] 每个状态字符的 waveform 已确认；
- [ ] sequencer 等待有超时和异常处理；
- [ ] Operating Sequence 的资源、前提、操作、结果和安全恢复明确；
- [ ] 转换报告与抽样 vector 已保留。

