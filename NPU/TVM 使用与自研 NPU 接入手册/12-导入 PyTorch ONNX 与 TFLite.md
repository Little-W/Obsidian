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

## 功能概述

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

## 详细说明

### 1. PyTorch 推荐使用 `torch.export.export` 与 `from_exported_program`。

PyTorch 推荐使用 `torch.export.export` 与 `from_exported_program`。

检查时先定位产生该信息的函数，再查找使用它的下一阶段。把两处代码和中间 IR 放在一起核对，可以确定字段的来源和用途。

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

## 验证项目

> [!important] 验证要求
> 分别保存一个两层 MLP 在本章处理前后的 IR，检查函数数量、调用形式、张量类型和模块属性。若当前环境无法执行，应先记录预期结构，环境可用后再以实际输出校正。

## 参考资料

| 资料 | 类型 |
| --- | --- |
| [模型导入教程](https://tvm.apache.org/docs/how_to/tutorials/import_model.html) | 官方资料 |
| [端到端优化](https://tvm.apache.org/docs/how_to/tutorials/e2e_opt_model.html) | 官方资料 |
| [Relax 前端 API](https://tvm.apache.org/docs/reference/api/python/relax/frontend.html) | 官方资料 |

## 本章要点

本章的重点不是记住所有类名，而是明确输入状态、处理动作、输出状态和失败处理。接入自研 NPU 时，每一层都应保留可检查的中间结果，使图分区、代码生成、设备提交和数值对照可以分别验证。

## 实现说明与验证步骤

> [!note] 依据与适用范围
> 本节依据所列 Apache TVM 官方资料和 v0.24.0 源码整理，给出输入条件、操作步骤、预期结果、异常处理和自研 NPU 适配要求。接口细节以固定版本源码与测试为准，在线页面用于补充说明。

### 12.A 目标与适用范围

从 PyTorch `ExportedProgram` 导入一个小网络，保留参数为输入，并在 TVM 与 PyTorch 之间比较结果。

参考样本保持输入规模较小，以便直接检查对象、字段和输出。首次执行时不要同时加入图改写、外部代码生成和真实设备执行；应先确认当前阶段的输入与输出，再增加后续处理。建议为该项验证建立独立目录，保存命令、标准输出、IR、编译产物摘要和环境信息。

### 12.B 参考实现

**官方依据：** [导入模型](https://tvm.apache.org/docs/how_to/tutorials/import_model.html) 与 [IRModule 入门](https://tvm.apache.org/docs/get_started/tutorials/ir_module.html)。

**v0.24.0 源码位置：** `docs/how_to/tutorials/import_model.py`、`python/tvm/relax/frontend/torch/`、`python/tvm/relax/frontend/onnx/`。

```python
import numpy as np
import torch
from tvm import relax
from tvm.relax.frontend.torch import from_exported_program

class Net(torch.nn.Module):
    def forward(self, x, w):
        return torch.relu(x @ w)

model = Net().eval()
x = torch.randn(2, 4)
w = torch.randn(4, 8)
exported = torch.export.export(model, (x, w))
mod = from_exported_program(
    exported,
    keep_params_as_input=True,
    unwrap_unit_return_tuple=True,
)
mod, params = relax.frontend.detach_params(mod)
print(mod.script())
print(params.keys())
```

按以下顺序执行：

1. 在新进程中确认 `tvm.__file__`、动态库路径和 TVM 提交，避免受到旧进程注册状态影响；
2. 将参考实现保存到单独文件，只补充本节明确要求的输入对象，不先加入额外优化；
3. 执行后保存完整输出；若生成 IR，同时保存 `script(show_meta=True)` 的文本；
4. 把输出与下面的预期现象逐项比较，不以“没有抛出异常”代替功能检查；
5. 重复执行一次并比较主要产物，确认结果没有依赖临时全局状态或未固定的遍历顺序。

> [!success] 预期现象
> IRModule 的 `main` 参数顺序应能与导入器返回的参数集合对应；输入形状、数据类型和算子结构应与导出程序一致。导入成功只是第一步，还要编译运行并与源框架结果比较。

> [!tip] 输出检查顺序
> 先看对象类型和函数数量，再看属性、调用形式、形状与数据类型，最后看运行结果或编译产物。若前一项不符合预期，先停止后续步骤。这样能把问题限定在最早出现差异的阶段。

### 12.C 单项条件验证

在模型中加入导入器不支持的操作，先保存完整错误名称，再用 `custom_convert_map` 添加最小转换。转换函数还要分别测试属性、动态尺寸和多输出，不能只验证一个样本。

执行条件变化样本时，复制参考实现的输入与环境，只修改上文指出的一项。对两个输出进行结构比较，并记录以下四项：

1. 第一次出现差异的是哪一个阶段？
2. 差异表现为函数、属性、形状、数据类型、编译产物还是运行结果？
3. 当前行为是明确拒绝、交给其他后端执行，还是编译错误？
4. 日志是否足以让另一位开发者不查看本次进程状态也能复现？

如果同时观察到多个变化，应继续缩小条件变化样本。参考实现用于确认正常处理，单项条件验证用于确认系统为何接受、拒绝或转交当前输入。

### 12.D 自研 NPU 适配要求

把导入后的算子清单与 NPU 支持表比较，生成三类列表：可直接接纳、需要图改写、暂由主机执行。前端转换不要偷偷改变数值规则来迎合硬件。

改造时建议保留三份相互独立的输入：最小 Relax 或 TensorIR、设备编译器输入、运行时调用输入。三份输入使用同一个样本编号，并记录转换前后的关键字段。这样可以分别测试 TVM 变换、NPU 编译器和驱动，不需要每次都运行完整模型。

至少补充以下样本：

- 一个完全满足能力要求的正向样本；
- 一个只改变数据类型的反向样本；
- 一个只改变形状或属性的反向样本；
- 一个包含主机与 NPU 混合执行的样本；
- 一个导出后在新进程加载的样本；
- 若支持动态尺寸，再增加最小值、常用值和最大值附近的样本。

### 12.E 源码定位

从上文列出的源码位置选择一个公开 API，依次找到 Python 调用、FFI 注册、C++ 实现和测试。记录函数签名、主要输入、主要输出、会写入的模块属性以及失败方式。若名称只在文档出现而源码中找不到，继续搜索注册字符串、属性键或错误文本。

> [!important] 验证项目
> 1. 执行前记录参考实现的对象关系；2. 执行后用实际输出修正记录；3. 增加一个会被明确拒绝的输入；4. 标明自研 NPU 接入需要修改的层次与保持不变的层次；5. 把结果整理成可由自动测试检查的断言。

### 12.F 检查清单

- [ ] 示例可在固定 v0.24.0 环境重复执行，或已明确列出所需可选依赖；
- [ ] 预期现象包含可检查的结构、字段或数值，不只是“运行成功”；
- [ ] 单条件变化能触发预期的拒绝、转交或结构差异；
- [ ] 能从官方页面定位到固定版本源码和测试；
- [ ] NPU 改造说明包含编译阶段、运行阶段与部署阶段；
- [ ] 失败时保留最小输入、环境、阶段输出和第一个错误。
