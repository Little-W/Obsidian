---
title: Test Method、Test Suite 与 Testflow
type: tutorial
tags:
  - SmarTest8
  - Java
  - testflow
updated: 2026-09-01
related:
  - "[[03-SmarTest-8项目与测试程序结构]]"
  - "[[09-DC测试方法]]"
  - "[[10-调试、Datalog、Shmoo与Margin]]"
---

# Test Method、Test Suite 与 Testflow

本章说明 Java Test Method、Test Suite、Testflow、test table 和 binning 如何协作。完成后，读者应能把“如何测”“用什么设置测”“何时测及失败后去哪”分开设计。

## 1. 三个对象的职责

| 对象 | 核心职责 | 不应承担的内容 |
| --- | --- | --- |
| Test Method | 准备仪器、执行测量、读取 per-site 结果、提交结果 | 产品级测试顺序和所有 bin 决策 |
| Test Suite | 绑定一个 method 实例、setup 和输入参数 | 大量重复 Java 逻辑 |
| Testflow | 安排 suite、条件、分支、停止和 binning | 直接编码所有仪器细节 |

官方基础培训把 Test Suite 描述为 Testflow 中执行特定数字或 DC 测试的元素，并说明 setup file 与 Java Test Method 共同构成 suite。[V93000 SmarTest 8 Basic User Training](https://www.advantest.com/en/customer-services/customer-training/onsite-training-na/application-training/v93000-st8-digital-user/)

## 2. Test Method 生命周期

具体 API 由当前 SmarTest 8 版本和公司框架决定，但一个 method 通常包含以下阶段：

```text
参数定义
  -> setup 检查或生成
  -> 仪器连接与初始化
  -> 执行 pattern/action/measure
  -> 读取 per-site 结果
  -> 与 test table 规则关联
  -> datalog
  -> 释放或恢复资源
```

> [!note] 下例是结构示意，不是可编译 API
> 真实类名、注解、方法名和结果对象必须从当前版本 TDC、已安装 Test Method Library 或批准项目模板取得。

```java
// 结构示意；不能直接编译
class CounterFunctionalMethod {
    void setup() {
        // 检查 operating sequence、signal group 和输入参数
    }

    void execute() {
        // 执行已配置的数字测试
    }

    void processResults() {
        // 按 site 读取结果并交给 datalog/test table
    }
}
```

## 3. 输入与输出参数

Test Method 参数应具有明确类型、单位、默认值和合法范围：

| 参数 | 类型 | 单位 | 合法范围 | 来源 |
| --- | --- | --- | --- | --- |
| `signalGroup` | signal group reference | — | 必须存在 | DUT board description |
| `waitTime` | duration | µs | `>= 0` 且有上限 | DUT 时序要求 |
| `sampleCount` | integer | count | `<approved range>` | 测量稳定性方案 |
| `testName` | string | — | 唯一且可追溯 | test table |

若参数可由 setup 或 Test Suite 两处设置，应规定谁优先，并在调试视图中查看最终解析值。

## 4. 多 Site 结果

多 site 方法必须保持 site 独立：

```text
execute hardware once or in parallel
  -> result[site1]
  -> result[site2]
  -> ...
  -> 每个 site 分别记录与判断
```

常见错误包括：

- 只读取第一个 site 的值并复制给全部 site；
- 任一 site 失败就丢弃其他 site 的有效测量；
- 使用共享 Java 变量覆盖 per-site 数据；
- 在 site disabled 后仍访问旧结果；
- 总电源电流被错误解释成每颗 DUT 电流。

## 5. Test Suite 的绑定检查

| 绑定项 | 检查问题 |
| --- | --- |
| Method class | 是否来自批准库或当前项目？ |
| Inputs | 名称、类型、单位和范围是否正确？ |
| Level/Timing | 与 DUT 条件和 pattern 是否一致？ |
| Pattern/Operating Sequence | 是否为预期版本？ |
| Test table row | test name、number、unit 和 limits 是否一致？ |
| Site behavior | disabled site 和 per-site result 如何处理？ |

同一个 method 可以由多个 suite 复用，例如 nominal、VDD-min 和 VDD-max；差异应通过清楚的参数和 specification 表达。

## 6. Testflow 设计

一个稳健的 Testflow 通常按成本和风险排序：

1. 初始化和安全状态；
2. contact/continuity；
3. 上电与基础电流检查；
4. 低成本数字基础测试；
5. 详细功能、scan、模拟或 RF 测试；
6. characterization 仅在工程模式执行；
7. datalog、binning 和安全下电。

失败处理需要明确：

- 失败后立即停止该 site 还是继续收集诊断数据；
- 哪些错误属于设备异常，哪些属于 DUT fail；
- soft bin 与 hard bin 的关系；
- retest 条件和最大次数；
- 中止后是否一定执行安全下电。

## 7. Test Table 与数据记录

每个记录项至少包含：

| 字段 | 要求 |
| --- | --- |
| Test number | 在发布范围内唯一 |
| Test name | 稳定、可读、能定位对象 |
| Units | 与数值一致，例如 V、A、µA、ns |
| Low/High limit | 开闭区间规则明确 |
| Soft bin / Hard bin | 与产品分类表一致 |
| Site | 能区分每颗 DUT |
| Program revision | 能定位执行版本 |

数值型测量不应只记录 pass/fail。保存测量值有助于相关性、漂移和良率分析。

## 8. 最小离线实验

### 8.1 操作

1. 从批准的数字功能 Test Method Library 选择一个 method；若无权限，只阅读官方示例。
2. 建立 `ts_reset_func` 和 `ts_count_func` 两个 suite。
3. 分别绑定 reset 与 count Operating Sequence。
4. 在 test table 中分配唯一 test number 和名称。
5. 在 Testflow 中先执行 reset，pass 后执行 count。
6. 为每个 suite 设置明确 fail 分支，并在末尾加入安全下电。
7. 运行构建和离线 flow 检查。

### 8.2 预期结果与通过条件

- Test Method 编译完成；
- 两个 suite 的 setup 和参数引用完整；
- test number 不重复；
- flow 的 pass/fail 分支可达；
- 安全下电在正常、失败和中止路径均可执行。

## 9. 常见失败

| 现象 | 可能原因 | 检查 | 处理 |
| --- | --- | --- | --- |
| Java 编译完成但 suite 无法执行 | setup 或输入参数未绑定 | suite properties | 补齐引用并检查类型 |
| 所有 site 得到同一数值 | per-site 结果访问错误 | method 结果数组与 site 循环 | 使用当前 API 的 multisite 类型 |
| datalog 单位错误 | test table 与 method 数值单位不同 | 输出值、limits 和 units | 统一单位并加自动检查 |
| fail 后 DUT 仍带电 | flow 异常路径没有 cleanup | 中止和异常分支 | 将安全恢复放入保证执行的结构 |
| 修改 suite 后量产未生效 | 运行的是旧 release | program revision 与 release 包 | 走受控发布流程 |

## 10. 本章检查

- [ ] Test Method、Test Suite 和 Testflow 职责分开；
- [ ] method 参数具有类型、单位和合法范围；
- [ ] 多 site 结果逐 site 保存；
- [ ] test number 唯一且 limits 单位一致；
- [ ] 所有退出路径都能安全下电。

