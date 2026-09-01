---
title: SmarTest 7 Eqnset 与 Level 语法详解
type: tutorial
tags:
  - ATE
  - V93000
  - SmarTest7
  - Eqnset
updated: 2026-09-01
related:
  - "[[05-电平配置与保护策略]]"
  - "[[18-SmarTest-7-Timing-Eqnset与Wavetable语法]]"
  - "[[20-界面操作图解与截图索引]]"
---

# SmarTest 7 Eqnset 与 Level 语法详解

这里把日常简称“eqn”统一写成正式对象名 **Eqnset**。代码入口是 `EQNSET`。本章讲 Level Eqnset；下一章讲 Timing Eqnset 与 Wavetable。

本章语法以 2004 年 Agilent 93000 SOC Series User Training Part 1 的公开原厂培训材料为主要依据。该资料属于 SmarTest 7 的历史版本，当前机台可能增加字段、改变资源名或限制，因此每段代码都要在本机 TDC、项目模板和 parser 中复核。[Training Manual](https://vantwillert.net/training/93K%20Part%20I/part1_manual_4.2.1.pdf) · [Lab Exercises](https://www.vantwillert.net/training/93K%20Part%20I/part1_lab_exercises_4.2.1.pdf)

## 1. 四层选择关系

```mermaid
flowchart LR
    A[Level Eqnset] --> B[Specset]
    B --> C[Levelset]
    C --> D[PINS / DPSPINS 物理资源]
```

| 层次 | 代码或工具对象 | 负责什么 |
| --- | --- | --- |
| Eqnset | `EQNSET` | 声明可用规格、公式和一个或多个 Levelset |
| Specset | Spec Tool / 规格文件 | 给 `SPECS` 变量填 actual、min、max 和单位 |
| Levelset | `LEVELSET` | 选择一组 driver、comparator、DPS 设置 |
| pin block | `PINS` / `DPSPINS` | 把算出的值写到具体资源字段 |

Test Suite 必须选择兼容的 Eqnset、Specset 和 Levelset。只写了 `SPECS` 不会产生实际数值；只选 Levelset 也不能替代 Eqnset 和 Specset。

## 2. 基本语法骨架

```text
EQNSET <整数编号> "<说明>"
  SPECS
    <规格名> [<单位>]

  EQUATIONS
    <中间变量> = <表达式>

  DPSPINS <电源 pin 或 group>
    <电源资源字段> = <值或表达式>

  LEVELSET <整数编号> "<说明>"
    PINS <pin 或 group 列表>
      <数字资源字段> = <值或表达式>
```

缩进用于阅读。为了减少版本差异，关键字统一大写、一个字段写一行、变量名大小写保持一致、说明使用英文半角双引号。

## 3. 每个关键字的含义

### 3.1 `EQNSET`

```text
EQNSET 1 "counter_levels"
```

- `1` 是 Eqnset 编号，供编辑器和 Test Suite 选择；
- 引号中是便于工程师识别的说明；
- Level Eqnset 和 Timing Eqnset 是不同设置对象，即使编号相同也不能互换。

### 3.2 `SPECS`

```text
SPECS
  VDDIO    [V]
  VOL_OUT  [V]
  VOH_OUT  [V]
```

`SPECS` 只声明外部可调变量和单位。值在 Spec Tool 中设置。方括号是单位写法，公开培训示例使用 `[V]`、`[ns]` 和 `[MHz]`。

适合放进 `SPECS` 的内容：

- 来自 DUT 规格的电压或时序；
- 需要 nominal/min/max 多条件切换的值；
- Shmoo 或 Margin 要扫描的值。

不适合放入 `SPECS` 的内容：只在公式内部使用、不会单独调整的中间量。

### 3.3 `EQUATIONS`

```text
EQUATIONS
  VIL_DRV = 0
  VIH_DRV = VDDIO
  VT_OUT  = (VOL_OUT + VOH_OUT) / 2
```

历史原厂示例明确使用了 `+`、`-`、`*`、`/` 和括号。变量右侧只能引用已声明 spec、此前可用变量或数字常数。不要假定当前 parser 支持未在 TDC 中说明的函数、幂运算或条件表达式。

### 3.4 `DPSPINS`

公开培训示例：

```text
DPSPINS Vcc
  vout    = VCC
  ilimit  = 1000
  t_ms    = 4
  offcurr = act
```

常见字段角色：

| 字段 | 角色 | 注意 |
| --- | --- | --- |
| `vout` | DPS 输出电压 | 必须来自电源规格或公式 |
| `ilimit` | 电流保护 | 默认单位与允许范围查当前 TDC |
| `t_ms` | 与电源动作相关的时间字段 | 具体定义查板卡文档 |
| `offcurr` | 关闭状态相关模式 | `act` 是旧培训示例中的值，不能盲目套用 |

上面四行是历史语法说明，不是 1.8 V DUT 的安全配置。真实 current limit 必须根据 DUT、DPS 板卡和 DUT board 计算。

### 3.5 `LEVELSET`

```text
LEVELSET 1 "nominal"
```

一个 Eqnset 可包含多个 `LEVELSET`。常见做法是在相同公式下建立不同终端、driver mode 或测试目的的 set；若只是 VDD 数值变化，优先用不同 Specset，避免复制重复 Levelset。

### 3.6 `PINS`

```text
PINS CLK RST_N EN
  vil = VIL_DRV
  vih = VIH_DRV

PINS Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7
  vol = VOL_OUT
  voh = VOH_OUT
```

`PINS` 后面可以列单 pin 或项目中已经定义的 pin group。名称必须与 pin configuration 完全一致。

## 4. 常用 Level 资源字段

| 字段 | 含义 | 用在哪类 pin |
| --- | --- | --- |
| `vil` | tester 驱动逻辑低的电压 | DUT 输入或双向 pin |
| `vih` | tester 驱动逻辑高的电压 | DUT 输入或双向 pin |
| `vol` | DUT 输出被判断为低的门限 | DUT 输出或双向 pin |
| `voh` | DUT 输出被判断为高的门限 | DUT 输出或双向 pin |
| `vcl` / `vch` | 低/高 clamp 相关值 | 需 clamp 的 pin；行为查当前 instrument 文档 |
| `vt` | 有源电流单元的换向电压 | 输出电流测试 |
| `iol` / `ioh` | 低/高状态电流设置 | 输出驱动能力测试 |

方向是最常见的错误：`vil/vih` 是 tester 向 DUT 驱动，`vol/voh` 是 tester 对 DUT 输出作比较。

## 5. Specset 的内容

Eqnset 中只有声明，Spec Tool 才给值。历史系统生成的规格内容概念如下：

```text
EQNSET 1 "counter_levels"
SPECSET 1 "nominal_1p8V"
VDDIO    1.80 [V]
VOL_OUT  0.40 [V]
VOH_OUT  1.40 [V]
```

带 actual/min/max 的行可写成：

```text
<SPECNAME> <ACTUAL> <MINIMUM> <MAXIMUM> [<UNIT>]
```

例如公开 Timing 规格示例中的 `ts_Sx_CP 7 3 10 [ns]` 表示 actual 7 ns、minimum 3 ns、maximum 10 ns。应通过 Spec Tool 生成和维护这类内容，不要手工改内部文件头、对象 ID 或缓存文件。

> [!important] 空 Specset
> 历史原厂培训手册说明：即使 Eqnset 不使用 `SPECS`，仍需为它建立一个空 Specset。否则后续选择或下载可能不完整。

## 6. 完整教学例子

下面代码是依据公开语法重新编写的 1.8 V 计数器例子，不是从某个量产程序复制而来：

```text
EQNSET 1 "counter_levels"
  SPECS
    VDDIO    [V]
    VOL_OUT  [V]
    VOH_OUT  [V]

  EQUATIONS
    VIL_DRV = 0
    VIH_DRV = VDDIO

  DPSPINS VDD
    vout   = VDDIO
    ilimit = 50

  LEVELSET 1 "nominal"
    PINS CLK RST_N EN
      vil = VIL_DRV
      vih = VIH_DRV

    PINS Q0 Q1 Q2 Q3 Q4 Q5 Q6 Q7
      vol = VOL_OUT
      voh = VOH_OUT
```

对应 Specset 教学值：

```text
EQNSET 1 "counter_levels"
SPECSET 1 "nominal_1p8V"
VDDIO    1.80 [V]
VOL_OUT  0.40 [V]
VOH_OUT  1.40 [V]
```

### 6.1 解析结果

| 变量/资源 | 展开值 |
| --- | ---: |
| `VIL_DRV` | 0 V |
| `VIH_DRV` | 1.8 V |
| `VDD.vout` | 1.8 V |
| `CLK/RST_N/EN.vil` | 0 V |
| `CLK/RST_N/EN.vih` | 1.8 V |
| `Q0..Q7.vol` | 0.4 V |
| `Q0..Q7.voh` | 1.4 V |

### 6.2 必须替换的内容

- `ilimit=50` 只是教学占位值，单位和安全值查当前 DPS 资源；
- 若 `VDD` 不由这个 Level Eqnset 管理，应按项目模板移除 `DPSPINS`；
- comparator 门限要来自真实 DUT 的 `VOL/VOH` 条件；
- pin 名称、group 和特殊字段要与本机 pin configuration 一致。

## 7. 三种组织方法

### 固定值

```text
vil = 0
vih = 1.8
```

适合最小 parser 测试，不适合需要多个电压条件的正式项目。

### 公式变量

```text
EQUATIONS
  VDDIO = 1.8
  VIH_DRV = VDDIO
```

适合只在 Eqnset 内部复用，但改变值仍需编辑代码。

### Spec + Equation

```text
SPECS
  VDDIO [V]
EQUATIONS
  VIH_DRV = VDDIO
```

适合 nominal/min/max、characterization 和受控扫描，是最容易追踪的组织方法。

## 8. 编辑、下载和选择顺序

历史 Level Setup Editor 的公开培训步骤是：

1. 打开 Level Setup Editor；
2. `Select > Edit Equations`；
3. 建立或修改 Eqnset；
4. 点击 `Download`，先检查 Report/Error 窗口；
5. `Select > Edit Specifications`；
6. 为所选 Eqnset 创建 Specset 并填写值；
7. 保存 Level setup；
8. 在 Test Suite 中选择 Level Eqnset、Specset 与 Levelset；
9. 查看展开后的实际值，再运行低风险测试。

原厂手册特别说明，先 Download Eqnset 后，Spec Tool 才知道 `SPECS` 中有哪些变量。

## 9. 错误定位

| 报错或现象 | 常见原因 | 检查顺序 |
| --- | --- | --- |
| unknown spec | 名称未在 `SPECS` 声明或大小写不同 | 声明、拼写、Specset 列 |
| unknown variable | 公式引用了不存在的变量 | `EQUATIONS` 定义次序与拼写 |
| unknown pin/group | pin configuration 中没有该名称 | pin 表与 group 定义 |
| Spec Tool 没有变量 | Eqnset 未成功 Download | Report 窗口、parser 错误 |
| 下载成功但值不对 | 选错 Specset 或 Eqnset | Test Suite 选择与展开值 |
| 输入功能全错 | `vil/vih`、方向或 pattern 错 | driver 值、pin 方向、Wavetable |
| 输出全 fail | `vol/voh` 或 compare 字符错 | comparator 值与 first fail |
| 某个 Levelset 找不到 | 编号重复、未保存或选错 Eqnset | Eqnset 内 set 列表 |

## 10. 练习

> [!question] 练习 1
> 增加 `SPECSET 2 "vdd_min"`，令 `VDDIO=1.71 V`，其他输出门限不变。需要修改 Eqnset 吗？

> [!note]- 参考答案
> 不需要。Eqnset 已声明 `VDDIO`，只需在同一个 Eqnset 下创建新的 Specset 并选择它。是否允许输出门限保持不变，还要由 DUT 规格决定。

> [!question] 练习 2
> 为什么不把 `VOL_OUT` 与 `VOH_OUT` 写成 0 V 和 1.8 V？

> [!note]- 参考答案
> 它们是 comparator 门限，应依据 DUT 输出规格及规定电流条件，而不是理想逻辑电源轨。

## 11. 本章检查

- [ ] 正式术语使用 Eqnset，代码入口使用 `EQNSET`；
- [ ] 能解释 Eqnset、Specset 与 Levelset 的选择关系；
- [ ] `SPECS` 与 `EQUATIONS` 的角色没有混淆；
- [ ] `vil/vih` 与 `vol/voh` 的方向正确；
- [ ] 代码成功 Download 后才创建或更新 Specset；
- [ ] 所有展开值已对照 DUT、PS1600/DPS 和 DUT board 限制。

