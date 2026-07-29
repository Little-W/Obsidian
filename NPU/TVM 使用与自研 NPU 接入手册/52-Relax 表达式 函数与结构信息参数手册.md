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

# 52. Relax 表达式、函数与结构信息参数手册

> [!abstract] 查阅方式
> 本章给出 v0.24.0 Relax 核心对象的规范定义和准确构造签名。第一次阅读建议先看 `Var`、`Call`、`VarBinding`、`DataflowBlock`、`SeqExpr`、`Function` 与 `TensorStructInfo`，再看常量、元组、控制流和外部函数。

> [!note] 字段名称保持源码拼写
> 参数表中的 `name_hint`、`struct_info`、`sinfo_args`、`ret_struct_info` 等名称必须按 Python API 原样使用。中文说明只解释功能，不改写源码标识符。

## 对象关系

```mermaid
flowchart TD
    A["tvm.ir.RelaxExpr"] --> B["Var / DataflowVar / GlobalVar"]
    A --> C["Constant / PrimValue / ShapeExpr"]
    A --> D["Call / If / Tuple / SeqExpr"]
    A --> E["BaseFunc"]
    E --> F["relax.Function"]
    E --> G["relax.ExternFunc"]
    H["Binding"] --> I["VarBinding"]
    H --> J["MatchCast"]
    K["BindingBlock"] --> L["DataflowBlock"]
    M["StructInfo"] --> N["Tensor / Shape / Prim / Tuple / Func"]
```

## `tvm.ir.GlobalVar`

**规范定义**：IRModule 中全局函数的稳定引用。它本身不是函数实现，而是用来查找或调用模块内函数的全局标识。

**Python 构造签名**

```text
tvm.ir.GlobalVar(name_hint: str)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `name_hint` | `str` | 无 | 供阅读和全局查找使用的名称。模块内同名全局变量必须保持唯一。 |

### 返回对象与可观察字段

返回 `GlobalVar`。主要字段是 `name_hint`；作为被调用对象时会产生 `relax.Call`，以基础表达式实参调用时也可生成 TensorIR 调用。

### 必须满足的条件

- 必须提供字符串名称。
- 调用时全部实参应同属 Relax 表达式，或全部属于基础表达式；混合传入会失败。

### 产生位置与使用位置

- 常见产生位置：TVMScript 解析、`IRModule` 用字符串键构造、`BlockBuilder.add_func`。
- 常见使用位置：`IRModule.__getitem__`、`relax.Call`、`call_tir`、函数重命名与外部代码生成 Pass。

### 最小例子

```python
import tvm
from tvm import relax

gv = tvm.ir.GlobalVar("main")
x = relax.Var("x", relax.TensorStructInfo([2, 4], "float32"))
call = gv(x)
assert call.op.same_as(gv)
```

### 常见错误

- 把 `name_hint` 当作局部变量身份。
- 创建新的同名 `GlobalVar` 后，直接假定它与模块中原对象是同一个对象。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/ir/expr.py)

## `relax.Var`

**规范定义**：Relax 局部变量或函数形参。变量用内部 `Id` 保持身份，`name_hint` 只负责可读显示。

**Python 构造签名**

```text
relax.Var(name_hint: str | Id, struct_info: StructInfo | None = None, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `name_hint` | `str | relax.Id` | 无 | 变量名称提示，通常传字符串。`Id` 由现有变量内部提供，不能直接构造。 |
| `struct_info` | `StructInfo | None` | `None` | 该变量的结构说明；函数形参通常应显式提供。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `Var`。常用字段或属性为 `vid`、`name_hint`、`struct_info_`、`span`。

### 必须满足的条件

- `struct_info` 若非空，必须已经是 `StructInfo`；形状列表不能直接当成此参数。
- 同名变量仍可具有不同身份。

### 产生位置与使用位置

- 常见产生位置：前端导入器、TVMScript 参数解析、BlockBuilder 和手写 Pass。
- 常见使用位置：`Function.params`、`VarBinding`、`Call.args`、自由变量分析和数据流分析。

### 最小例子

```python
from tvm import relax

sinfo = relax.TensorStructInfo([1, 16], "float16")
x = relax.Var("x", sinfo)
assert x.name_hint == "x"
assert x.struct_info_.dtype == "float16"
```

### 常见错误

- 把 `[1, 16]` 直接传给 `struct_info`。
- 按变量显示名称维护替换表，导致同名变量被错误替换。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.DataflowVar`

**规范定义**：仅供 `DataflowBlock` 内部使用的局部中间变量。它标记该值不应直接从数据流块外部引用。

**Python 构造签名**

```text
relax.DataflowVar(name_hint: str | Id, struct_info: StructInfo | None = None, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `name_hint` | `str | relax.Id` | 无 | 变量名称提示。 |
| `struct_info` | `StructInfo | None` | `None` | 中间值的结构说明。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `DataflowVar`，它是 `relax.Var` 的子类，具有相同主要字段。

### 必须满足的条件

- 定义与使用应位于同一个数据流块有效范围内。
- 需要从数据流块输出的值应绑定到普通 `Var`。

### 产生位置与使用位置

- 常见产生位置：TVMScript `R.dataflow()`、`BlockBuilder.emit`。
- 常见使用位置：数据流分析、融合、消除无用绑定和 `BlockBuilder.emit_output`。

### 最小例子

```python
from tvm import relax

sinfo = relax.TensorStructInfo([2, 8], "float32")
lv = relax.DataflowVar("lv", sinfo)
assert isinstance(lv, relax.Var)
```

### 常见错误

- 把它用作函数公开返回变量后仍在块外直接引用。
- 认为它与普通 `Var` 只在打印名称上不同。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.Constant`

**规范定义**：保存不可改变张量数据的 Relax 表达式。标量张量以零维张量表示，不能把它与 `PrimValue` 混为一类。

**Python 构造签名**

```text
relax.Constant(data: tvm.runtime.Tensor, struct_info: StructInfo | None = None, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `data` | `tvm.runtime.Tensor` | 无 | 常量实际数据。 |
| `struct_info` | `StructInfo | None` | `None` | 可选结构说明；省略时从数据推导。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `Constant`。`data` 保存运行时张量；结构信息通常包含数据形状与数据类型。

### 必须满足的条件

- 直接构造时 `data` 必须是 TVM 运行时张量。
- 提供的结构信息必须与实际数据一致。

### 产生位置与使用位置

- 常见产生位置：模型导入器、参数绑定、常量折叠和 `relax.const`。
- 常见使用位置：常量折叠、BYOC 常量收集、代码生成与运行时参数准备。

### 最小例子

```python
import numpy as np
from tvm import relax

c = relax.const(np.array([[1, 2]], dtype="float32"))
assert c.data.shape == (1, 2)
```

### 常见错误

- 直接调用类构造器却传入 NumPy 数组；此时应优先使用 `relax.const`。
- 把 Python 整数常量默认推断的数据类型想当然地视为 `int64`。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.const`

**规范定义**：把 Python 标量、NumPy 数组或 TVM 运行时张量转换为 `relax.Constant` 的辅助函数。

**Python 构造签名**

```text
relax.const(value: bool | int | float | numpy.ndarray | tvm.runtime.Tensor, dtype: str | None = None) -> relax.Constant
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `value` | `bool | int | float | numpy.ndarray | runtime.Tensor` | 无 | 要写入 IR 的常量值。 |
| `dtype` | `str | None` | `None` | 目标数据类型；省略时整数默认 `int32`，浮点数默认 `float32`，布尔值默认 `bool`。 |

### 返回对象与可观察字段

返回 `relax.Constant`，数据位于 CPU 运行时张量中。

### 必须满足的条件

- 显式数据类型必须能表示输入数据。
- 大型模型权重会增加 IR 与导出产物体积，应按编译流程的参数策略处理。

### 产生位置与使用位置

- 常见产生位置：用户代码、前端导入器和 `Function.bind_params`。
- 常见使用位置：所有接受张量表达式的 Relax 运算，以及参数提取和外部代码生成。

### 最小例子

```python
from tvm import relax

one = relax.const(1)
half = relax.const(0.5, "float16")
assert one.struct_info_.dtype == "int32"
assert half.struct_info_.dtype == "float16"
```

### 常见错误

- 省略 `dtype` 后假定 Python 整数保留 Python 的任意精度。
- 把 `relax.const(3)` 当作 `PrimValue(3)`；前者是零维张量。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.PrimValue`

**规范定义**：把一个基础表达式包装为 Relax 值，常用于动态尺寸、标量配置和运行时张量字段。

**Python 构造签名**

```text
relax.PrimValue(value: tvm.tirx.PrimExpr | int, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `value` | `tirx.PrimExpr | int` | 无 | 要包装的基础值；Python 整数转换为 `int64` 的 `IntImm`。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `PrimValue`，`value` 字段保存基础表达式。

### 必须满足的条件

- 不接受普通浮点数作为该构造器的自动输入。
- 它描述基础值，不保存张量存储。

### 产生位置与使用位置

- 常见产生位置：动态尺寸处理、`Expr.shape[i]` 相关构造、手写 Relax IR。
- 常见使用位置：形状相关内建运算、`tir_vars`、标量运算与运行时检查。

### 最小例子

```python
from tvm import relax

n = relax.PrimValue(16)
assert n.value.dtype == "int64"
```

### 常见错误

- 与零维 `Constant` 混用。
- 把它直接当 Python 整数参与宿主语言分支。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.ShapeExpr`

**规范定义**：保存一组基础整数表达式的 Relax 形状值。每个元素表示对应维度的长度。

**Python 构造签名**

```text
relax.ShapeExpr(values: list[tvm.tirx.PrimExpr] | tuple[tvm.tirx.PrimExpr, ...] | tvm_ffi.Array, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `values` | `list[PrimExpr] | tuple[PrimExpr, ...] | tvm_ffi.Array` | 无 | 按张量维度顺序排列的长度表达式。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `ShapeExpr`。`values` 可按下标读取，`len(obj)` 返回维数。

### 必须满足的条件

- 元素应是可用于尺寸的整数基础表达式。
- 维度次序必须与张量布局及算子定义一致。

### 产生位置与使用位置

- 常见产生位置：TensorStructInfo 构造、TVMScript 解析、形状推导和 `call_tir` 参数准备。
- 常见使用位置：结构信息、动态尺寸计算、`MatchCast` 和 TensorIR 调用。

### 最小例子

```python
from tvm import relax, tirx

n = tirx.Var("n", "int64")
shape = relax.ShapeExpr([n, 64])
assert len(shape) == 2
```

### 常见错误

- 把形状值和张量值当成同一对象。
- 将排列顺序不一致的尺寸直接传给后端。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.Tuple`

**规范定义**：按固定顺序组合多个 Relax 表达式的值。字段可具有不同结构信息。

**Python 构造签名**

```text
relax.Tuple(fields: list[Expr] | tuple[Expr, ...], span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `fields` | `list[Expr] | tuple[Expr, ...]` | 无 | 元组字段，顺序属于程序定义的一部分。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `Tuple`。可读取 `fields`，也可使用 `len` 与整数下标。

### 必须满足的条件

- 每个字段都必须能转换为 Relax 表达式。
- 下标范围为 `[-len, len-1]`。

### 产生位置与使用位置

- 常见产生位置：多返回值算子、`call_tir` 实参包装、前端导入器和数据流块输出。
- 常见使用位置：`TupleGetItem`、调用参数拆分、结构推导和虚拟机。

### 最小例子

```python
from tvm import relax

x = relax.Var("x", relax.TensorStructInfo([2], "float32"))
y = relax.Var("y", relax.TensorStructInfo([2], "float32"))
pair = relax.Tuple([x, y])
assert pair[1].same_as(y)
```

### 常见错误

- 假定元组中的张量必须具有相同形状。
- 改变字段顺序后未同步修改运行时参数读取。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.TupleGetItem`

**规范定义**：从元组表达式中选取一个固定位置的字段。

**Python 构造签名**

```text
relax.TupleGetItem(tuple_value: Expr, index: int, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `tuple_value` | `Expr` | 无 | 产生元组值的表达式。 |
| `index` | `int` | 无 | 编译阶段已知的字段编号。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `TupleGetItem`。字段为 `tuple_value`、`index` 和 `span`。

### 必须满足的条件

- 输入的结构信息应为 `TupleStructInfo`。
- 下标必须在字段范围内。

### 产生位置与使用位置

- 常见产生位置：Python 下标操作、TVMScript、规范化和多返回值处理。
- 常见使用位置：融合、死代码删除、结构推导和运行时指令生成。

### 最小例子

```python
from tvm import relax

x = relax.Var("x", relax.TensorStructInfo([1], "float32"))
item = relax.TupleGetItem(relax.Tuple([x]), 0)
assert item.index == 0
```

### 常见错误

- 用动态 Relax 值作为 `index`；此参数必须是 Python 整数。
- 输入不是元组却等待运行时再报错。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.Call`

**规范定义**：表示一次 Relax 调用。被调用对象可以是已注册 `Op`、全局函数、本地函数值、函数变量或外部函数。

**Python 构造签名**

```text
relax.Call(op: Expr | tvm.ir.Op, args: list[Expr] | tuple[Expr, ...], attrs: tvm.ir.Attrs | None = None, sinfo_args: list[StructInfo] | tuple[StructInfo, ...] | None = None, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `op` | `Expr | tvm.ir.Op` | 无 | 被调用对象。 |
| `args` | `list[Expr] | tuple[Expr, ...]` | 无 | 按函数签名顺序传入的实参。 |
| `attrs` | `tvm.ir.Attrs | None` | `None` | 该次调用的命名属性；普通函数参数不放在这里。 |
| `sinfo_args` | `list[StructInfo] | tuple[StructInfo, ...] | None` | `None` | 仅特定内建调用和外部函数需要的输出结构说明。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `Call`。主要字段是 `op`、`args`、`attrs`、`sinfo_args`、`struct_info_` 和 `span`。

### 必须满足的条件

- 实参数量与结构必须符合被调用对象的定义。
- `sinfo_args` 通常不应为普通 Relax 运算手工填写。
- 直接构造后可能需要规范化才能得到结果结构信息。

### 产生位置与使用位置

- 常见产生位置：Relax 运算辅助函数、函数对象调用、前端导入器和 Pass。
- 常见使用位置：结构推导、融合、BYOC 模式检查、低层转换和 VM 编译。

### 最小例子

```python
import tvm
from tvm import relax

x = relax.Var("x", relax.TensorStructInfo([2], "float32"))
y = relax.Var("y", relax.TensorStructInfo([2], "float32"))
add_op = tvm.ir.Op.get("relax.add")
call = relax.Call(add_op, [x, y])
normalized = relax.BlockBuilder().normalize(call)
assert normalized.struct_info_.dtype == "float32"
```

### 常见错误

- 把输出形状放进普通运算的 `attrs`。
- 把 `op` 的名称字符串直接当作 `tvm.ir.Op`。
- 未规范化就假定 `struct_info_` 已填写。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.If`

**规范定义**：有返回值的条件表达式。运行时只选择并执行一个分支，整个节点产生被选分支的结果。

**Python 构造签名**

```text
relax.If(cond: Expr, true_branch: Expr, false_branch: Expr, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `cond` | `Expr` | 无 | 标量布尔条件。 |
| `true_branch` | `Expr` | 无 | 条件为真时计算的表达式。 |
| `false_branch` | `Expr` | 无 | 条件为假时计算的表达式。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `If`。规范化后结果结构信息应能同时接纳两个分支的结果。

### 必须满足的条件

- 条件必须能解释为标量布尔值。
- 两个分支的结果结构必须兼容。
- 分支内变量的有效范围不能泄漏到节点外。

### 产生位置与使用位置

- 常见产生位置：前端控制流导入、TVMScript 条件表达式和控制流 Pass。
- 常见使用位置：合法性检查、控制流变换、VM 编译和 BYOC 分区。

### 最小例子

```python
from tvm import relax

cond = relax.Var("cond", relax.PrimStructInfo("bool"))
x = relax.PrimValue(1)
y = relax.PrimValue(2)
expr = relax.If(cond, x, y)
```

### 常见错误

- 把 Python `if` 与 Relax `If` 混为一类。
- 两个分支返回字段数量不同的元组。
- 假定 BYOC 后端一定能接纳控制流。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.VarBinding`

**规范定义**：把右侧表达式结果赋给一个 Relax 变量的绑定记录。它是 IR 结构，不等同于执行时的可变赋值。

**Python 构造签名**

```text
relax.VarBinding(var: relax.Var, value: Expr, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `var` | `relax.Var` | 无 | 接收结果的变量。 |
| `value` | `Expr` | 无 | 用于定义该变量的表达式。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `VarBinding`，字段是 `var`、`value` 和 `span`。

### 必须满足的条件

- 变量在所属函数范围内通常只定义一次。
- 变量结构信息必须能接纳右侧结果。

### 产生位置与使用位置

- 常见产生位置：TVMScript 赋值、`BlockBuilder.emit`、A-normal form 规范化。
- 常见使用位置：数据流分析、表达式访问器、融合、常量折叠和代码生成。

### 最小例子

```python
from tvm import relax

sinfo = relax.TensorStructInfo([2], "float32")
x = relax.Var("x", sinfo)
y = relax.Var("y", sinfo)
z = relax.Var("z", sinfo)
binding = relax.VarBinding(z, relax.op.add(x, y))
assert binding.var.same_as(z)
```

### 常见错误

- 把绑定理解为可重复改写同一变量的命令。
- 在变量定义之前读取它。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.MatchCast`

**规范定义**：建立变量绑定，同时要求运行时值符合给定结构说明，并可确定其中尚未给定的符号尺寸。

**Python 构造签名**

```text
relax.MatchCast(var: relax.Var, value: Expr, struct_info: StructInfo, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `var` | `relax.Var` | 无 | 检查成功后接收值的变量。 |
| `value` | `Expr` | 无 | 被检查的输入值。 |
| `struct_info` | `StructInfo` | 无 | 期望结构。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `MatchCast`，字段包括 `var`、`value`、`struct_info` 和 `span`。

### 必须满足的条件

- 目标变量的说明应与 `struct_info` 一致。
- 重复出现的符号尺寸必须相等，否则运行时检查失败。

### 产生位置与使用位置

- 常见产生位置：动态形状导入器、TVMScript `R.match_cast` 和形状处理 Pass。
- 常见使用位置：合法性检查、动态形状转换和 VM 编译。

### 最小例子

```python
from tvm import relax, tirx

n = tirx.Var("n", "int64")
x = relax.Var("x", relax.TensorStructInfo(ndim=2, dtype="float32"))
y = relax.Var("y", relax.TensorStructInfo([n, 16], "float32"))
binding = relax.MatchCast(y, x, y.struct_info_)
```

### 常见错误

- 把它当成只改变显示类型而不做运行时检查。
- 在不同位置用同一个符号名称表达本应独立的尺寸。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.BindingBlock`

**规范定义**：按顺序保存一组 Relax 绑定的普通块。块内允许包含具有可观察副作用或控制流的绑定。

**Python 构造签名**

```text
relax.BindingBlock(bindings: list[Binding], span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `bindings` | `list[Binding]` | 无 | 按定义顺序排列的绑定。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `BindingBlock`，`bindings` 字段保存绑定列表。

### 必须满足的条件

- 每个绑定只能使用已经有效的变量。
- 绑定顺序对于有副作用的调用不可任意调整。

### 产生位置与使用位置

- 常见产生位置：TVMScript、BlockBuilder 和规范化 Pass。
- 常见使用位置：`SeqExpr`、表达式访问器、VM 编译和各种图级 Pass。

### 最小例子

```python
from tvm import relax

sinfo = relax.TensorStructInfo([2], "float32")
x = relax.Var("x", sinfo)
y = relax.Var("y", sinfo)
block = relax.BindingBlock([relax.VarBinding(y, x)])
```

### 常见错误

- 把普通块当作所有绑定都可自由换序的数据流块。
- 手工重排具有副作用的调用。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.DataflowBlock`

**规范定义**：只包含纯计算绑定的数据流块。编译器可以在依赖关系允许时对内部绑定执行融合、删除或调整顺序。

**Python 构造签名**

```text
relax.DataflowBlock(bindings: list[Binding], span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `bindings` | `list[Binding]` | 无 | 纯计算绑定列表。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `DataflowBlock`，它是 `BindingBlock` 的子类。

### 必须满足的条件

- 块内不应包含可观察副作用或控制流。
- 内部 `DataflowVar` 不能直接在块外使用；输出应由普通 `Var` 承接。

### 产生位置与使用位置

- 常见产生位置：TVMScript `R.dataflow()`、BlockBuilder 和图规范化。
- 常见使用位置：算子融合、BYOC、死代码删除、数据流重写和 VM 编译。

### 最小例子

```python
from tvm import relax

sinfo = relax.TensorStructInfo([2], "float32")
x = relax.Var("x", sinfo)
lv = relax.DataflowVar("lv", sinfo)
out = relax.Var("out", sinfo)
block = relax.DataflowBlock([
    relax.VarBinding(lv, relax.op.negative(x)),
    relax.VarBinding(out, lv),
])
```

### 常见错误

- 将随机数、设备提交或文件操作放入数据流块。
- 让 `DataflowVar` 直接成为块后表达式的引用。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.SeqExpr`

**规范定义**：由零个或多个绑定块和一个最终结果表达式组成的 Relax 顺序表达式。函数体常被规范化为该形式。

**Python 构造签名**

```text
relax.SeqExpr(blocks: list[BindingBlock], body: Expr, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `blocks` | `list[BindingBlock]` | 无 | 按程序顺序排列的绑定块。 |
| `body` | `Expr` | 无 | 整个顺序表达式的返回值。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `SeqExpr`。主要字段为 `blocks`、`body`、`struct_info_` 和 `span`。

### 必须满足的条件

- `body` 只能引用参数或此前块中已输出的变量。
- 块之间的变量有效范围必须满足 Relax 规则。

### 产生位置与使用位置

- 常见产生位置：BlockBuilder 完成函数、Normalize Pass、TVMScript 解析。
- 常见使用位置：几乎所有 Relax 函数级 Pass、BYOC 与 VM 编译。

### 最小例子

```python
from tvm import relax

sinfo = relax.TensorStructInfo([2], "float32")
x = relax.Var("x", sinfo)
y = relax.Var("y", sinfo)
block = relax.BindingBlock([relax.VarBinding(y, x)])
seq = relax.SeqExpr([block], y)
```

### 常见错误

- 把 `body` 理解为最后一个绑定本身；它必须是表达式。
- 在 `body` 中读取未从数据流块输出的内部变量。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.Function`

**规范定义**：以 Relax 表达式为函数体的可调用函数，是图级程序、组合函数和外部子图包装的主要单位。

**Python 构造签名**

```text
relax.Function(params: list[Var], body: Expr, ret_struct_info: StructInfo | None = None, is_pure: bool | None = True, attrs: tvm.ir.DictAttrs | None = None, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `params` | `list[relax.Var]` | 无 | 按调用顺序排列的形参。 |
| `body` | `Expr` | 无 | 函数返回结果的表达式，常为 `SeqExpr`。 |
| `ret_struct_info` | `StructInfo | None` | `None` | 显式返回说明；省略时由函数体推导。 |
| `is_pure` | `bool | None` | `True` | 函数是否没有可观察副作用。 |
| `attrs` | `tvm.ir.DictAttrs | None` | `None` | 函数属性，例如 `global_symbol`、`Codegen`、`Composite`。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `Function`。主要字段为 `params`、`body`、`ret_struct_info`、`is_pure`、`attrs` 和 `span`。

### 必须满足的条件

- 参数必须是 `relax.Var`。
- 函数体中的自由变量应来自参数或合法外部引用。
- 显式返回说明必须能接纳函数体结果。
- `is_pure=True` 时不得隐藏外部可观察副作用。

### 产生位置与使用位置

- 常见产生位置：模型前端、TVMScript、BlockBuilder、融合与外部函数分组 Pass。
- 常见使用位置：IRModule、函数级 Pass、BYOC 代码生成、Relax 编译和 VM。

### 最小例子

```python
from tvm import relax

sinfo = relax.TensorStructInfo([2, 4], "float32")
x = relax.Var("x", sinfo)
func = relax.Function([x], relax.op.negative(x), sinfo)
assert len(func.params) == 1
assert func.is_pure
```

### 常见错误

- 把函数属性与 `Call.attrs` 混在一起。
- 标记为纯函数却调用具有外部副作用的 PackedFunc。
- 仅按参数名称而非参数顺序准备运行时输入。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## `relax.ExternFunc`

**规范定义**：对运行时 PackedFunc 名称的 IR 引用。它不保存函数体，执行时必须能从注册表或运行时模块中找到对应实现。

**Python 构造签名**

```text
relax.ExternFunc(global_symbol: str, struct_info: StructInfo | None = None, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `global_symbol` | `str` | 无 | 运行时查询使用的全局函数名。 |
| `struct_info` | `StructInfo | None` | `None` | 可选函数结构说明。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `ExternFunc`。主要字段是 `global_symbol`、`struct_info_` 和 `span`。

### 必须满足的条件

- 名称必须与运行时注册名完全一致。
- 调用参数和返回说明必须符合外部实现。

### 产生位置与使用位置

- 常见产生位置：`relax.extern`、外部函数调用构造、后端转换。
- 常见使用位置：`relax.Call`、`call_dps_packed`、VM 编译和运行时函数查询。

### 最小例子

```python
from tvm import relax

sinfo = relax.FuncStructInfo(
    [relax.TensorStructInfo([2], "float32")],
    relax.TensorStructInfo([2], "float32"),
)
ext = relax.ExternFunc("acme_npu.relu", sinfo)
assert str(ext.global_symbol) == "acme_npu.relu"
```

### 常见错误

- 只创建 `ExternFunc`，却没有注册或导入对应运行时函数。
- 名称大小写或命名空间不一致。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)

## 结构信息

结构信息不是可执行表达式，而是表达式在编译阶段的结构说明。以下条目使用与表达式相同的参数格式。

## `relax.ObjectStructInfo`

**规范定义**：只说明值是一个运行时对象，不进一步限定张量、形状或函数结构。

**Python 构造签名**

```text
relax.ObjectStructInfo(span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `ObjectStructInfo`。

### 必须满足的条件

- 仅在更具体的结构信息不可用或对象确实是通用运行时对象时使用。

### 产生位置与使用位置

- 常见产生位置：前端、外部调用和对象容器相关运算。
- 常见使用位置：结构检查、VM 编译和运行时对象传递。

### 最小例子

```python
from tvm import relax
sinfo = relax.ObjectStructInfo()
```

### 常见错误

- 把已知张量退化为通用对象，导致形状和数据类型检查丢失。

**固定版本源码**：[struct_info.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/struct_info.py)

## `relax.PrimStructInfo`

**规范定义**：描述基础标量值的数据类型，并可进一步记录一个编译阶段已知的具体基础表达式。

**Python 构造签名**

```text
relax.PrimStructInfo(dtype: str | DataType | None = None, value: int | float | PrimExpr | None = None, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `dtype` | `str | DataType | None` | `None` | 基础值数据类型；`dtype` 与 `value` 至少提供一个。 |
| `value` | `int | float | PrimExpr | None` | `None` | 可选已知值。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `PrimStructInfo`。字段 `dtype` 表示数据类型，`value` 在已知具体值时非空。

### 必须满足的条件

- 不能同时省略 `dtype` 和 `value`。
- 第一个位置参数必须是数据类型，不得把基础表达式放在该位置。
- 同时提供时二者数据类型必须一致。

### 产生位置与使用位置

- 常见产生位置：`PrimValue` 规范化、函数签名、形状运算和标量调用。
- 常见使用位置：结构推导、条件检查、动态尺寸和 VM 编译。

### 最小例子

```python
from tvm import relax, tirx

any_i64 = relax.PrimStructInfo("int64")
known = relax.PrimStructInfo(value=tirx.IntImm("int64", 16))
assert known.value.value == 16
```

### 常见错误

- 写成 `PrimStructInfo(16)`；应使用 `value=16`。
- 把它当成零维张量结构说明。

**固定版本源码**：[struct_info.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/struct_info.py)

## `relax.ShapeStructInfo`

**规范定义**：描述一个形状值本身，而不是描述某个张量。可记录完整尺寸列表，或只记录形状包含多少个维度。

**Python 构造签名**

```text
relax.ShapeStructInfo(values: list[PrimExpr] | None = None, ndim: int = -1, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `values` | `list[PrimExpr] | None` | `None` | 已知的各维度长度。 |
| `ndim` | `int` | `-1` | 维数；`-1` 表示未知。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `ShapeStructInfo`。`values` 可能为空，`ndim` 在未知时为 `-1`。

### 必须满足的条件

- 不要同时用 `values` 和非默认 `ndim` 描述同一对象。
- 若给出 `values`，维数由其长度确定。

### 产生位置与使用位置

- 常见产生位置：`ShapeExpr` 规范化、函数参数和形状推导。
- 常见使用位置：动态尺寸 Pass、`MatchCast`、结构检查和 VM。

### 最小例子

```python
from tvm import relax, tirx

n = tirx.Var("n", "int64")
known = relax.ShapeStructInfo([n, 64])
rank_only = relax.ShapeStructInfo(ndim=2)
```

### 常见错误

- 误以为它描述 `Tensor`；张量应使用 `TensorStructInfo`。
- 给出 `values` 后又给出冲突的 `ndim`。

**固定版本源码**：[struct_info.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/struct_info.py)

## `relax.TensorStructInfo`

**规范定义**：描述 Relax 张量的形状、数据类型、虚拟设备和维数。它是算子检查与 NPU 能力检查最常读取的结构节点。

**Python 构造签名**

```text
relax.TensorStructInfo(shape: Expr | list[PrimExpr] | None = None, dtype: str = "float32", vdevice: VDevice | str | None = None, ndim: int = -1, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `shape` | `Expr | list[PrimExpr] | None` | `None` | 形状表达式或尺寸列表；列表会自动转换为 `ShapeExpr`。 |
| `dtype` | `str` | `"float32"` | 元素数据类型。 |
| `vdevice` | `VDevice | str | None` | `None` | 可选虚拟设备。 |
| `ndim` | `int` | `-1` | 只知道维数时使用；`-1` 表示未知。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `TensorStructInfo`。主要字段是 `shape`、`dtype`、`vdevice`、`ndim` 和 `span`。

### 必须满足的条件

- 不要同时提供具体 `shape` 和非默认 `ndim`。
- 数据类型字符串必须是 TVM 可识别类型。
- NPU 检查不能在 `shape` 未知时直接读取固定整数。

### 产生位置与使用位置

- 常见产生位置：函数签名、前端导入器、算子结构推导和 `call_tir` 输出说明。
- 常见使用位置：运算检查、BYOC 模式检查、内存规划、低层转换和 VM。

### 最小例子

```python
from tvm import relax, tirx

n = tirx.Var("n", "int64")
exact = relax.TensorStructInfo([n, 128], "float16")
rank_only = relax.TensorStructInfo(dtype="float16", ndim=2)
assert exact.ndim == 2
```

### 常见错误

- 依赖默认 `float32`，忘记实际模型使用 `float16`。
- 把 `shape=None` 解释成任意维数均已验证可执行。
- 直接用 Python `len(sinfo.shape)` 处理未知形状。

**固定版本源码**：[struct_info.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/struct_info.py)

## `relax.TupleStructInfo`

**规范定义**：按固定顺序描述 Relax 元组各字段的结构。

**Python 构造签名**

```text
relax.TupleStructInfo(fields: list[StructInfo], span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `fields` | `list[StructInfo]` | 无 | 每个元组字段对应一个结构说明。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `TupleStructInfo`，`fields` 与元组字段一一对应。

### 必须满足的条件

- 字段数量和顺序必须与实际元组一致。

### 产生位置与使用位置

- 常见产生位置：`Tuple` 规范化、多输出运算和函数返回推导。
- 常见使用位置：`TupleGetItem` 推导、调用检查、VM 与外部代码生成。

### 最小例子

```python
from tvm import relax

pair = relax.TupleStructInfo([
    relax.TensorStructInfo([2], "float32"),
    relax.PrimStructInfo("int64"),
])
assert len(pair.fields) == 2
```

### 常见错误

- 改变返回元组顺序但未同步外部运行时。
- 用一个张量结构说明代替只有一个字段的元组结构说明。

**固定版本源码**：[struct_info.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/struct_info.py)

## `relax.FuncStructInfo`

**规范定义**：描述函数值的参数结构、返回结构和纯函数属性。

**Python 构造签名**

```text
relax.FuncStructInfo(params: list[StructInfo], ret: StructInfo, purity: bool = True, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `params` | `list[StructInfo]` | 无 | 按调用顺序排列的形参结构。 |
| `ret` | `StructInfo` | 无 | 返回值结构。 |
| `purity` | `bool` | `True` | 是否没有可观察副作用。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `FuncStructInfo`。字段为 `params`、`ret`、`purity`；不透明函数还可能使用 `derive_func`。

### 必须满足的条件

- 参数顺序必须与实际调用约定一致。
- 纯函数说明必须与实现行为一致。

### 产生位置与使用位置

- 常见产生位置：Relax Function、ExternFunc 类型说明、结构推导。
- 常见使用位置：`Call` 检查、函数变量调用、优化和 VM。

### 最小例子

```python
from tvm import relax

tensor = relax.TensorStructInfo([2], "float32")
sinfo = relax.FuncStructInfo([tensor], tensor, purity=True)
```

### 常见错误

- 只检查返回数据类型，忽略参数数量和顺序。
- 对外部有状态函数使用默认 `purity=True`。

**固定版本源码**：[struct_info.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/struct_info.py)

## 调用辅助函数的参数说明

### `relax.call_tir`

```text
relax.call_tir(
    gvar: GlobalVar,
    args: Expr,
    out_sinfo: TensorStructInfo | list[TensorStructInfo],
    tir_vars: ShapeExpr | tuple[PrimExpr] | list[PrimExpr] | None = None,
) -> relax.Call
```

| 参数 | 功能 |
| --- | --- |
| `gvar` | 指向同一 `IRModule` 内 `tirx.PrimFunc` 的全局变量 |
| `args` | 输入张量表达式；单个非元组表达式会自动包成 Relax 元组 |
| `out_sinfo` | 每个输出张量的结构说明；多个输出用列表 |
| `tir_vars` | 额外传给 PrimFunc 的基础整数参数，常用于动态尺寸 |

`call_tir` 采用目标传递方式：运行时先准备输出张量，再调用 PrimFunc 写入这些输出。`out_sinfo` 决定输出对象准备方式，因此不能用猜测的形状代替真实推导。

### `relax.call_dps_packed`

```text
relax.call_dps_packed(
    func: str | Expr,
    args: Expr,
    out_sinfo: TensorStructInfo | list[TensorStructInfo],
) -> relax.Call
```

`func` 可以是运行时注册名或 `ExternFunc`。外部函数接收输入和已经准备好的输出。该接口按纯函数处理指定输出以外的行为；若实现还修改全局状态、隐藏缓冲区或设备队列，编译器的删除、调整顺序或重复调用可能造成错误。

### 普通 `Call`、`call_tir` 与 `call_dps_packed`

| 形式 | 被调用对象 | 输出如何确定 | NPU 常见用途 |
| --- | --- | --- | --- |
| `relax.Call(Op, ...)` | Relax 已注册运算 | 运算结构推导函数 | 分区前的图 |
| `relax.Call(GlobalVar, ...)` | Relax Function | 函数返回说明 | 调用组合函数或外部子图 |
| `relax.call_tir(...)` | PrimFunc | `out_sinfo` | TVM 生成的低层内核 |
| `relax.call_dps_packed(...)` | PackedFunc | `out_sinfo` | 手写运行时函数或设备库 |
| `relax.Call(ExternFunc, ...)` | 外部 PackedFunc | 函数结构或 `sinfo_args` | 特定外部调用 |

## 一个完整的逐对象例子

下面的 TVMScript 与对象关系图同时展示函数、形参、调用、绑定、数据流块、顺序表达式与结构信息。

```python
import tvm
from tvm.script import ir as I
from tvm.script import relax as R

@I.ir_module
class Module:
    @R.function
    def main(
        x: R.Tensor((2, 4), "float32"),
        y: R.Tensor((2, 4), "float32"),
    ) -> R.Tensor((2, 4), "float32"):
        with R.dataflow():
            lv0 = R.add(x, y)
            lv1 = R.nn.relu(lv0)
            out = lv1
            R.output(out)
        return out

func = Module["main"]
assert isinstance(func, tvm.relax.Function)
assert len(func.params) == 2
assert isinstance(func.body, tvm.relax.SeqExpr)

block = func.body.blocks[0]
assert isinstance(block, tvm.relax.DataflowBlock)
assert len(block.bindings) == 3

first_binding = block.bindings[0]
assert isinstance(first_binding, tvm.relax.VarBinding)
assert isinstance(first_binding.value, tvm.relax.Call)
assert first_binding.value.op.name == "relax.add"
```

对象关系可写成：

```text
IRModule
└── GlobalVar("main") -> relax.Function
    ├── params[0] -> Var("x") : TensorStructInfo((2, 4), float32)
    ├── params[1] -> Var("y") : TensorStructInfo((2, 4), float32)
    └── body -> SeqExpr
        ├── blocks[0] -> DataflowBlock
        │   ├── VarBinding(lv0, Call(relax.add, [x, y]))
        │   ├── VarBinding(lv1, Call(relax.nn.relu, [lv0]))
        │   └── VarBinding(out, lv1)
        └── body -> out
```

## 为 NPU 编写检查代码时读取哪些字段

```python
from tvm import relax

def inspect_tensor(expr, role):
    sinfo = expr.struct_info_
    if not isinstance(sinfo, relax.TensorStructInfo):
        return False, f"{role}: expected TensorStructInfo"
    if sinfo.dtype != "float16":
        return False, f"{role}: dtype={sinfo.dtype}"
    if sinfo.ndim != 2:
        return False, f"{role}: ndim={sinfo.ndim}"
    if sinfo.shape is None:
        return False, f"{role}: static shape required"
    return True, "accepted"
```

检查顺序应从对象种类开始，再到数据类型、维数、形状值、布局属性和设备容量。若形状未知，检查代码应返回明确原因，不能直接把 `shape.values` 当作始终存在。

## 结构检查 API

| API | 输入 | 输出 | 用途 |
| --- | --- | --- | --- |
| `relax.analysis.bound_vars(expr)` | 表达式或函数 | 在对象内部定义的变量列表 | 检查绑定范围 |
| `relax.analysis.all_vars(expr)` | 表达式或函数 | 所有 Relax 变量列表 | 编写访问器和诊断工具 |
| `relax.analysis.all_global_vars(expr)` | 表达式或函数 | 所有全局变量引用 | 查找被调用函数 |
| `relax.analysis.check_well_formed(mod)` | IRModule | 布尔值，失败时可报告诊断 | 模块合法性检查 |
| `BlockBuilder.normalize(expr)` | Relax 表达式 | 补全结构后的表达式 | 调用结果推导 |

## 固定版本源码与在线 API

- [Relax Python API](https://tvm.apache.org/docs/reference/api/python/relax/relax.html)
- [Relax 运算 API](https://tvm.apache.org/docs/reference/api/python/relax/op.html)
- [Relax 分析 API](https://tvm.apache.org/docs/reference/api/python/relax/analysis.html)
- [`python/tvm/relax/expr.py`](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/expr.py)
- [`python/tvm/relax/struct_info.py`](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/struct_info.py)
- [`python/tvm/relax/op/base.py`](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/op/base.py)
- [`include/tvm/relax/expr.h`](https://github.com/apache/tvm/blob/v0.24.0/include/tvm/relax/expr.h)
- [`include/tvm/relax/struct_info.h`](https://github.com/apache/tvm/blob/v0.24.0/include/tvm/relax/struct_info.h)
