---
tags:
  - TVM
  - NPU
  - 编译器
  - Relax
  - TensorIR
status: maintained
baseline: Apache TVM v0.24.0
updated: 2026-07-29
---

# 27. 从旧版 Relay 迁移到 Relax

> [!abstract] 本章内容
> 帮助读者识别 Relay 时代文档与 v0.24.0 Relax 主线的对应概念，避免机械替换 API。

## 一句话理解

迁移不是改导入语句，而是重新确认前端、IR、分区属性、代码生成入口和执行器的完整流程。

## 核心要点

1. 旧 BYOC 文档常以 Relay Function、AnnotateTarget 和 PartitionGraph 为中心。
2. 当前教程使用 Relax DPL、FuseOpsByPattern、MergeCompositeFunctions 和 RunCodegen。
3. 旧 Graph Executor 示例与当前 Relax VM 的打包和调用方式不同。
4. 旧 `tir` 名称在 v0.24.0 源码组织中拆为 `tirx` 与 `s_tir`。
5. 已有 Relay 后端可保留一段兼容期，但新功能应在 Relax 路线实现。

```mermaid
flowchart LR
    A["输入程序状态"] --> B["分析信息"]
    B --> C["本章所述处理"]
    C --> D["输出程序状态"]
    D --> E["日志与可复现记录"]
```

## 逐项解析

### 1. 旧 BYOC 文档常以 Relay Function、AnnotateTarget 和 PartitionGraph 为中心。

旧 BYOC 文档常以 Relay Function、AnnotateTarget 和 PartitionGraph 为中心。 这一点之所以重要，是因为 TVM 的信息会在多个 IR 层次之间逐步变得具体。上一层没有保留下来的信息，下一层通常无法可靠恢复；下一层过早写死的选择，也会限制后续优化。初学时应在每次变换前后打印模块，找出函数、调用、属性、形状和 dtype 的变化。

实现时可执行的动作是：先为旧后端建立现有行为测试，再逐项替换。 建议同时保存输入 IR、输出 IR、Pass 配置、Target 和日志。若出现结果差异，先找到第一次发生结构变化的阶段，再向下检查，而不是从最终设备结果反推全部过程。

> [!warning] 本小节常见问题
> 把 Relay Pass 名直接替换成相似 Relax 名，可能改变处理次序。

### 2. 当前教程使用 Relax DPL、FuseOpsByPattern、MergeCompositeFunctions 和 RunCodegen。

当前教程使用 Relax DPL、FuseOpsByPattern、MergeCompositeFunctions 和 RunCodegen。 这一点之所以重要，是因为 TVM 的信息会在多个 IR 层次之间逐步变得具体。上一层没有保留下来的信息，下一层通常无法可靠恢复；下一层过早写死的选择，也会限制后续优化。初学时应在每次变换前后打印模块，找出函数、调用、属性、形状和 dtype 的变化。

实现时可执行的动作是：把旧算子白名单改写成带形状、dtype 和属性检查的 FusionPattern。 建议同时保存输入 IR、输出 IR、Pass 配置、Target 和日志。若出现结果差异，先找到第一次发生结构变化的阶段，再向下检查，而不是从最终设备结果反推全部过程。

> [!warning] 本小节常见问题
> 旧运行时函数注册名若继续保留，容易与新模块同时加载时冲突。

### 3. 旧 Graph Executor 示例与当前 Relax VM 的打包和调用方式不同。

旧 Graph Executor 示例与当前 Relax VM 的打包和调用方式不同。 这一点之所以重要，是因为 TVM 的信息会在多个 IR 层次之间逐步变得具体。上一层没有保留下来的信息，下一层通常无法可靠恢复；下一层过早写死的选择，也会限制后续优化。初学时应在每次变换前后打印模块，找出函数、调用、属性、形状和 dtype 的变化。

实现时可执行的动作是：把旧 JSON Runtime 所需字段与新序列化器输出逐项对照。 建议同时保存输入 IR、输出 IR、Pass 配置、Target 和日志。若出现结果差异，先找到第一次发生结构变化的阶段，再向下检查，而不是从最终设备结果反推全部过程。

> [!warning] 本小节常见问题
> 只迁移编译器而不迁移导出加载测试，会遗漏模块保存问题。

### 4. 旧 `tir` 名称在 v0.24.0 源码组织中拆为 `tirx` 与 `s_tir`。

旧 `tir` 名称在 v0.24.0 源码组织中拆为 `tirx` 与 `s_tir`。 这一点之所以重要，是因为 TVM 的信息会在多个 IR 层次之间逐步变得具体。上一层没有保留下来的信息，下一层通常无法可靠恢复；下一层过早写死的选择，也会限制后续优化。初学时应在每次变换前后打印模块，找出函数、调用、属性、形状和 dtype 的变化。

实现时可执行的动作是：用同一模型比较旧后端与 Relax 后端的子图数量和结果。 建议同时保存输入 IR、输出 IR、Pass 配置、Target 和日志。若出现结果差异，先找到第一次发生结构变化的阶段，再向下检查，而不是从最终设备结果反推全部过程。

> [!warning] 本小节常见问题
> 把 Relay Pass 名直接替换成相似 Relax 名，可能改变处理次序。

### 5. 已有 Relay 后端可保留一段兼容期

已有 Relay 后端可保留一段兼容期，但新功能应在 Relax 路线实现。 这一点之所以重要，是因为 TVM 的信息会在多个 IR 层次之间逐步变得具体。上一层没有保留下来的信息，下一层通常无法可靠恢复；下一层过早写死的选择，也会限制后续优化。初学时应在每次变换前后打印模块，找出函数、调用、属性、形状和 dtype 的变化。

实现时可执行的动作是：文档明确标注支持的 TVM tag。 建议同时保存输入 IR、输出 IR、Pass 配置、Target 和日志。若出现结果差异，先找到第一次发生结构变化的阶段，再向下检查，而不是从最终设备结果反推全部过程。

> [!warning] 本小节常见问题
> 旧运行时函数注册名若继续保留，容易与新模块同时加载时冲突。

## 实施清单

- [ ] 先为旧后端建立现有行为测试，再逐项替换。
- [ ] 把旧算子白名单改写成带形状、dtype 和属性检查的 FusionPattern。
- [ ] 把旧 JSON Runtime 所需字段与新序列化器输出逐项对照。
- [ ] 用同一模型比较旧后端与 Relax 后端的子图数量和结果。
- [ ] 文档明确标注支持的 TVM tag。

## 设计评审问题

1. 本阶段接收哪一种 IR，要求哪些属性已经存在？
2. 本阶段产生哪些新函数、属性、常量或模块？
3. 遇到不被支持的输入时，是保留给其他后端、报告编译错误，还是插入转换？
4. 哪些配置属于硬件固定限制，哪些配置允许自动搜索？
5. 如何证明重复执行本阶段不会产生额外变化？
6. 如何在日志中解释每个重要决定？

## 自测

> [!question] 请先独立回答
> 把一个两层 MLP 的 IR 在本章处理前后分别打印出来，指出函数数量、调用形式、张量类型和模块属性发生了什么变化。如果无法运行代码，可先画出预期结构，再与实际输出比较。

## 参考资料

| 资料 | 类型 |
| --- | --- |
| [当前 BYOC 教程](https://tvm.apache.org/docs/how_to/tutorials/bring_your_own_codegen.html) | 官方资料 |
| [外部库分派](https://tvm.apache.org/docs/arch/external_library_dispatch.html) | 官方资料 |
| [旧 BYOC 博文](https://tvm.apache.org/2020/07/15/how-to-bring-your-own-codegen-to-tvm) | 官方资料 |

## 章末小结

本章的重点不是记住所有类名，而是明确输入状态、处理动作、输出状态和失败处理。接入自研 NPU 时，每一层都应保留可检查的中间结果，使图分区、代码生成、设备提交和数值对照可以分别验证。
