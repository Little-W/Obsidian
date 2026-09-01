---
title: SmarTest 8 项目与测试程序结构
type: tutorial
tags:
  - SmarTest8
  - test-program
updated: 2026-09-01
related:
  - "[[04-DUT板描述与引脚配置]]"
  - "[[08-Test-Method、Test-Suite与Testflow]]"
---

# SmarTest 8 项目与测试程序结构

本章说明 SmarTest 8 中 project、test program、setup、Test Method、Test Suite 和 Testflow 的关系。完成后，读者应能打开一个项目并判断每类文件负责什么，而不是把所有内容都当作“测试代码”。

## 1. 软件环境

Advantest 将 SmarTest 8 描述为基于 Red Hat Linux、Eclipse IDE 和 Java 编程接口的 V93000 核心软件。开发环境支持从 test flow 到 operating sequence 和单次测量的交互式调试。[Advantest V93000 SmarTest 8](https://www.advantest.com/en/products/semiconductor-test-system/soc/v93000/)

官方基础培训的主要对象包括：

- SmarTest project；
- test program file；
- DUT board description；
- signals、levels、timing 和 vectors；
- operating sequence；
- Test Method、Test Suite 和 Testflow；
- test table、datalog、binning 和 debug tools。

本地保存的官方五天议程可以作为核对目录：[[参考资料/官方公开资料/ATK_V93000_SOC_SMT8_Digital_User_Training.pdf]]。

## 2. 最小对象模型

| 对象 | 回答的问题 | 典型内容 |
| --- | --- | --- |
| Project / Workspace | 源文件在哪里、如何构建？ | Java 源码、setup、flow、构建配置 |
| Test Program | 哪些对象组成一个可运行程序？ | 入口、资源引用、flow 和部署信息 |
| DUT Board Description | DUT 信号连接到哪些 tester 资源？ | signal、group、site、pogo 对应关系 |
| Setup | 仪器如何配置？ | level、timing、specification、action |
| Pattern | 每个周期驱动什么、比较什么？ | vector、波形字符、sequencer 指令 |
| Operating Sequence | pattern 与 action 按什么顺序执行？ | 初始化、执行、等待、切换设置 |
| Test Method | 如何准备、执行和读取某类测量？ | Java 类、参数、结果处理 |
| Test Suite | 用哪组 setup 和 method 做一个测试？ | method 实例、输入参数、setup 绑定 |
| Testflow | 测试项按什么条件执行和分档？ | suite 调用、条件、分支、bin |
| Test Table | 限值、测试号和记录字段是什么？ | test name、test number、limits、units |

## 3. 从需求到结果的依赖顺序

建立测试程序时，推荐依赖顺序如下：

1. 从 DUT 数据手册和 test plan 提取信号、电源、限值和顺序。
2. 建立 DUT board description 和 site 对应关系。
3. 建立规格变量，再建立 level 与 timing setup。
4. 导入或创建 pattern，并检查信号名和波形字符。
5. 建立 operating sequence，定义 pattern 与 action 的先后关系。
6. 选择或编写 Test Method。
7. 用 Test Suite 绑定 method、setup 和参数。
8. 在 Testflow 中安排执行、条件、datalog 和 binning。
9. 先做构建和离线检查，再申请在线机台运行。

如果顺序反过来，最常见的结果是 Testflow 已经很复杂，但底层 signal、level、timing 或资源仍未确定，调试时难以分层定位。

## 4. 推荐目录模型

下面是教学用逻辑结构，不代表所有 SmarTest 8 版本都使用完全相同的物理文件夹名称：

```text
counter_demo/
├── dut-board/          # DUT board description 与 site/pogo 信息
├── setups/             # levels、timing、specification、actions
├── patterns/           # pattern 与转换输入
├── src/                # Java Test Method
├── testflows/          # Testflow
├── testtables/         # test number、limits、units、bin
└── release/            # 受控发布信息，不在源码目录手工改写
```

> [!note] 物理文件名以当前版本为准
> SmarTest 8 不同发行版、模板和客户框架可能采用不同后缀和目录。先在 TDC 中查找当前版本的 “Recommended Setup Structure” 和示例项目，再建立工程规范。

## 5. 最小测试程序工作表

在 GUI 中操作前，先填完下面的表。它能暴露缺失输入。

| 对象 | 示例名称 | 必需输入 | 通过条件 |
| --- | --- | --- | --- |
| DUT board | `counter_demo_board` | pin、site、pogo | 无重复占用，方向正确 |
| Level | `lvl_1v8_nom` | `VIL/VIH/VOL/VOH` | 在 DUT 与 PS1600 合法范围内 |
| Timing | `tim_10mhz_nom` | period、drive edge、strobe | 满足 DUT AC 规格 |
| Pattern | `pat_reset_count` | signal order、vectors | 能绑定全部信号 |
| Operating Sequence | `ops_reset_count` | setup、pattern、action | 顺序无未定义对象 |
| Test Method | `<approved-digital-method>` | method 参数 | 编译无错误 |
| Test Suite | `ts_func_count` | method + setup | 离线可加载 |
| Testflow | `main` | suite、条件、bin | 路径和失败处理明确 |
| Test Table | `limits_prod` | number、limits、unit | 编号唯一、单位正确 |

## 6. 离线检查步骤

不同 SmarTest 8 版本的按钮名称可能变化，下面只给出任务顺序：

1. 在批准的 workspace 中导入或创建项目。
2. 选择当前项目要求的软件 target 和 tester configuration。
3. 构建项目，处理 Java 与 setup 的语法错误。
4. 打开问题视图，处理未定义 signal、specification 和资源引用。
5. 对目标 Test Suite 做离线加载或验证。
6. 打开 Testflow，检查条件、bin 和不可达分支。
7. 保存构建日志、问题列表和程序版本标识。

预期结果不是“DUT pass”，而是：项目构建完成，离线工具没有未解释错误，目标 Test Suite 的对象引用完整。

## 7. 常见错误

| 现象 | 可能原因 | 检查 | 处理 |
| --- | --- | --- | --- |
| Project 可见但无法构建 | target、依赖或 JDK 设置不匹配 | 查看 Problems 与 build log | 使用批准模板和版本 |
| Test Suite 无法加载 setup | 名称、路径或 specification 缺失 | 从 suite 向下追踪引用 | 统一命名并补齐引用 |
| Pattern 绑定失败 | signal 名、方向或 signal group 不一致 | 比较 pattern header 与 DUT board description | 修正信号表或受控转换规则 |
| 离线执行显示结果但无电气值 | 使用了模拟或占位结果 | 确认 online/offline 状态 | 不把离线输出写成硬件测量 |
| 修改 limits 后结果未变化 | 运行的 test table 不是编辑对象 | 查看 active test table 和 release | 激活正确版本并记录变更 |

## 8. 练习

> [!question] 对象定位
> 某功能测试在低频和高频都执行了同一个 pattern，但高频失败。你会先修改 Testflow 还是检查 timing setup？为什么？

> [!note]- 参考答案
> 先检查 timing setup、实际 period、edge/strobe 和对应的 specification 变量。Testflow 主要负责执行条件和顺序，不能解释同一 pattern 的速度差异。还应确认两个 suite 是否真的引用同一 pattern 和不同 timing，而不是被其他 setup 覆盖。

## 9. 本章检查

- [ ] 能说出 Test Method、Test Suite 和 Testflow 的差异；
- [ ] 能按依赖顺序从 DUT board description 追踪到 test table；
- [ ] 知道离线构建完成不代表已测量 DUT；
- [ ] 在创建 GUI 对象前已填写最小测试程序工作表。

