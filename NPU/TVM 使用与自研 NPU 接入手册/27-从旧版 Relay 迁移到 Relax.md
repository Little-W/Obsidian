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

旧 BYOC 文档常以 Relay Function、AnnotateTarget 和 PartitionGraph 为中心。

阅读时先定位产生该信息的函数，再查找消费它的下一阶段。把两处代码和中间 IR 放在一起观察，比单独记忆类名更容易理解。

**实现建议：** 先为旧后端建立现有行为测试，再逐项替换。

> [!warning] 本小节常见问题
> 把 Relay Pass 名直接替换成相似 Relax 名，可能改变处理次序。

### 2. 当前教程使用 Relax DPL、FuseOpsByPattern、MergeCompositeFunctions 和 RunCodegen。

当前教程使用 Relax DPL、FuseOpsByPattern、MergeCompositeFunctions 和 RunCodegen。

把变换前后的 IR 并排比较，重点查看函数参数、调用、属性、StructInfo 和返回值。只记录最终 IR 会丢失变化发生的位置。

**实现建议：** 把旧算子白名单改写成带形状、数据类型和属性检查的 FusionPattern。

> [!warning] 本小节常见问题
> 旧运行时函数注册名若继续保留，容易与新模块同时加载时冲突。

### 3. 旧 Graph Executor 示例与当前 Relax VM 的打包和调用方式不同。

旧 Graph Executor 示例与当前 Relax VM 的打包和调用方式不同。

实现时将硬件固定限制放入 Target 或能力文件，把用户可选策略放入编译配置；二者发生冲突时应报告具体字段。

**实现建议：** 把旧JSON 运行时所需字段与新序列化器输出逐项对照。

> [!warning] 本小节常见问题
> 只迁移编译器而不迁移导出加载测试，会遗漏模块保存问题。

### 4. 旧 `tir` 名称在 v0.24.0 源码组织中拆为 `tirx` 与 `s_tir`。

旧 `tir` 名称在 v0.24.0 源码组织中拆为 `tirx` 与 `s_tir`。

测试至少包含一个正常样本和一个只改变单一条件的反向样本。这样，结构或结果变化时能直接找到对应规则。

**实现建议：** 用同一模型比较旧后端与 Relax 后端的子图数量和结果。

> [!warning] 本小节常见问题
> 把 Relay Pass 名直接替换成相似 Relax 名，可能改变处理次序。

### 5. 已有 Relay 后端可保留一段兼容期

已有 Relay 后端可保留一段兼容期，但新功能应在 Relax 路线实现。

保存可由工具读取的阶段报告，其中包含输入摘要、输出摘要、Pass 配置、Target、耗时和错误；文本日志用于辅助阅读。

**实现建议：** 文档明确标注支持的 TVM tag。

> [!warning] 本小节常见问题
> 旧运行时函数注册名若继续保留，容易与新模块同时加载时冲突。

## 实施清单

- [ ] 先为旧后端建立现有行为测试，再逐项替换。
- [ ] 把旧算子白名单改写成带形状、数据类型和属性检查的 FusionPattern。
- [ ] 把旧JSON 运行时所需字段与新序列化器输出逐项对照。
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
