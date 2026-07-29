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

# 12. 导入 PyTorch ONNX 与 TFLite

> [!abstract] 本章内容
> 说明三类常见前端、参数处理、动态尺寸、未被支持的运算和导入后核对。

## 一句话理解

前端导入不是文件格式转换结束点，而是建立可信 Relax 程序的第一步；导入后必须检查结构和数值。

## 核心要点

1. PyTorch 推荐使用 `torch.export.export` 与 `from_exported_program`。
2. ONNX 使用 `from_onnx`，可用 `shape_dict` 固定所需输入尺寸。
3. TFLite 适合已有移动端模型，但需要关注布局与内置算子版本。
4. 参数可嵌入模块，也可保留为函数参数后用 `detach_params` 分离。
5. 未被支持的 PyTorch 运算可通过 `custom_convert_map` 增加转换函数。

```mermaid
flowchart LR
    A["输入程序状态"] --> B["分析信息"]
    B --> C["本章所述处理"]
    C --> D["输出程序状态"]
    D --> E["日志与可复现记录"]
```

## 逐项解析

### 1. PyTorch 推荐使用 `torch.export.export` 与 `from_exported_program`。

PyTorch 推荐使用 `torch.export.export` 与 `from_exported_program`。

阅读时先定位产生该信息的函数，再查找消费它的下一阶段。把两处代码和中间 IR 放在一起观察，比单独记忆类名更容易理解。

**实现建议：** 在源框架 `.eval()` 状态下导出推理模型。

> [!warning] 本小节常见问题
> 训练状态的 BatchNorm 与 Dropout 会使对照结果不稳定。

### 2. ONNX 使用 `from_onnx`

ONNX 使用 `from_onnx`，可用 `shape_dict` 固定所需输入尺寸。

把变换前后的 IR 并排比较，重点查看函数参数、调用、属性、StructInfo 和返回值。只记录最终 IR 会丢失变化发生的位置。

**实现建议：** 保存输入名称、形状、数据类型、动态范围和 opset。

> [!warning] 本小节常见问题
> ONNX 输入名与实际模型输入名不一致时，尺寸覆盖不会生效。

### 3. TFLite 适合已有移动端模型

TFLite 适合已有移动端模型，但需要关注布局与内置算子版本。

实现时将硬件固定限制放入 Target 或能力文件，把用户可选策略放入编译配置；二者发生冲突时应报告具体字段。

**实现建议：** 导入后先用最小编译流程在 CPU 对照结果。

> [!warning] 本小节常见问题
> 把所有参数嵌入常量会增加 IR 打印体积，也可能妨碍权重复用。

### 4. 参数可嵌入模块

参数可嵌入模块，也可保留为函数参数后用 `detach_params` 分离。

测试至少包含一个正常样本和一个只改变单一条件的反向样本。这样，结构或结果变化时能直接找到对应规则。

**实现建议：** 列出 Relax 算子集合，再与 NPU 能力表逐项比较。

> [!warning] 本小节常见问题
> 训练状态的 BatchNorm 与 Dropout 会使对照结果不稳定。

### 5. 未被支持的 PyTorch 运算可通过 `custom_convert_map` 增加转换函数。

未被支持的 PyTorch 运算可通过 `custom_convert_map` 增加转换函数。

保存可由工具读取的阶段报告，其中包含输入摘要、输出摘要、Pass 配置、Target、耗时和错误；文本日志用于辅助阅读。

**实现建议：** 为每个自定义前端转换编写单算子测试。

> [!warning] 本小节常见问题
> ONNX 输入名与实际模型输入名不一致时，尺寸覆盖不会生效。

## 实施清单

- [ ] 在源框架 `.eval()` 状态下导出推理模型。
- [ ] 保存输入名称、形状、数据类型、动态范围和 opset。
- [ ] 导入后先用最小编译流程在 CPU 对照结果。
- [ ] 列出 Relax 算子集合，再与 NPU 能力表逐项比较。
- [ ] 为每个自定义前端转换编写单算子测试。

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
| [模型导入教程](https://tvm.apache.org/docs/how_to/tutorials/import_model.html) | 官方资料 |
| [端到端优化](https://tvm.apache.org/docs/how_to/tutorials/e2e_opt_model.html) | 官方资料 |
| [Relax 前端 API](https://tvm.apache.org/docs/reference/api/python/relax/frontend.html) | 官方资料 |

## 章末小结

本章的重点不是记住所有类名，而是明确输入状态、处理动作、输出状态和失败处理。接入自研 NPU 时，每一层都应保留可检查的中间结果，使图分区、代码生成、设备提交和数值对照可以分别验证。
