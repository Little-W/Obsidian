---
title: V93000 DUT 板、校准与安全
type: tutorial
tags:
  - ATE
  - V93000
  - DUT-board
  - safety
updated: 2026-09-01
related:
  - "[[02-测试机硬件架构与信号路径]]"
  - "[[12-PS1600硬件参数与配置]]"
  - "[[13-DPS128与供电资源配置]]"
---

# V93000 DUT 板、校准与安全

本章说明 tester 资源离开测试头后，怎样通过 pogo、DUT board、socket/probe card 到达 DUT。完成后，读者应能审查板级连接、延迟、电源完整性、校准状态和初次上机安全条件。

## 1. 物理路径

```mermaid
flowchart LR
    A[Instrument channel] --> B[Test-head interface]
    B --> C[Pogo / connector]
    C --> D[DUT board trace]
    D --> E[Socket or probe]
    E --> F[DUT pin]
```

软件中的 channel 正确，不代表 DUT 引脚一定得到正确波形。中间任何连接错误、开路、短路、反射或压降都会改变结果。

## 2. DUT Board 审查清单

### 数字信号

- pin 名称、方向和通道编号一致；
- 受控阻抗与端接方案明确；
- 高速组内长度差满足接口要求；
- 双向 pin 有安全 turnaround；
- 高压 pin 与普通 pin 的间距、器件和通道资源匹配；
- 测试点不会形成过长支路。

### 电源与地

- Force/Sense、回流路径和连接器额定电流明确；
- 每个 site 的电源没有意外相连；
- 去耦器件的位置、容值和耐压合适；
- 电源走线压降、瞬态和温升已经评估；
- DUT ground 与仪器参考的连接方式明确。

### 外部器件

- relay、level shifter、开关和放大器有默认安全状态；
- 外部电源和 tester 电源不会互相反向灌电；
- utility line 的上电初态已定义；
- 外部仪器断开或超时时能安全退出。

## 3. 校准层次

| 层次 | 目的 | 不能证明的内容 |
| --- | --- | --- |
| 系统校准 | 校正测试机内部资源 | DUT board 和 socket 状态 |
| 板级校正/补偿 | 补偿板上路径或 RF 网络 | DUT 本身的规格符合性 |
| 接触检查 | 识别明显开路、短路 | 高速波形质量 |
| 相关性复测 | 与参考设备或方法比较 | 所有未来批次都相同 |

运行前确认校准文件、日期、适用 hardware configuration 和失败记录。不能用一颗“能 pass 的样品”替代校准。

## 4. 首次上机的分阶段方法

1. 断电检查 DUT board 电阻和明显短路；
2. 不放 DUT，确认 relay 和外部电源初态；
3. 放入批准样品，数字 pin 保持安全状态；
4. 先做低电流 continuity；
5. 只开启一个电源域，限制电流并观测；
6. 运行复位和极短低速 pattern；
7. 检查波形后再提高速度；
8. 最后才扩大到多 site、Shmoo 或长时间运行。

## 5. 必须立即停止的现象

- 异常温升、气味、声音或变色；
- 电源电流快速上升或反复触发保护；
- DUT 未上电时数字 pin 有明显注入电流；
- tester 报告校准、interlock、温度或硬件错误；
- 不清楚某个 relay、utility line 或外部电源的状态；
- 结果与接线图、通道表或预期极性矛盾。

停止后先保存日志和状态，再按批准步骤断电。不要通过增大 current limit 继续尝试。

## 6. Direct Probe 与接口空间

Advantest 官方 Direct Probe 资料说明了测试头到 probe/DUT board 的接口方案及可用板面空间。该方案与具体实验室的传统 DUT board 结构可能不同，应按实际测试头和接口文档设计。

![[界面与设备截图.assets/img-common11.gif|700]]

*图 1：Advantest 官方 DUT Scale Duo 动图。来源：[V93000 产品页](https://www.advantest.com/en/products/semiconductor-test-system/soc/v93000/)。另见 [[参考资料/官方公开资料/V93000_Direct_Probe_Solution_Overview.pdf|Direct Probe 官方说明]]。*

## 7. 故障定位表

| 现象 | 优先检查 | 独立确认方法 |
| --- | --- | --- |
| 所有 pin continuity 开路 | socket 未压合、公共回路断开 | 显微检查和万用表 |
| 固定几个 pin 高频失败 | 局部走线、端接或接触 | 示波器和 TDR |
| 电源值正确但 DUT 端偏低 | Force/Sense 或铜阻 | 分别测源端与 DUT 端 |
| 只在某 site 失败 | site 路径和机械接触 | 交换样品或重复接触 |
| 更换程序版本后全部失败 | 设置选择或 pin 表变化 | 比较展开值和版本差异 |

## 8. 本章检查

- [ ] 已从 channel 追踪到 DUT pin；
- [ ] DUT board 电源、地、relay 和外部仪器已审查；
- [ ] 校准文件与当前硬件配置匹配；
- [ ] 首次上机按低风险步骤逐项增加功能；
- [ ] 停止条件与安全下电动作已经写入程序和操作说明。

