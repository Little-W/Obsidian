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

# 53. TensorIR 表达式、语句与 PrimFunc 参数手册

> [!abstract] 本章用途
> 本章严格区分产生值的 `PrimExpr`、描述执行顺序的 `Stmt`、符号存储视图 `Buffer`、可调度块 `SBlock` 与函数容器 `PrimFunc`。自研 NPU 若直接接纳 TensorIR，本章字段就是调度、指令选择和代码生成读取的主要输入。

## 层次和组合关系

```text
PrimFunc
├── params: Var 或 Buffer
├── buffer_map: 句柄变量与 Buffer 的对应关系
└── body: Stmt
    ├── For / While / IfThenElse / SeqStmt
    ├── BufferStore / Evaluate
    └── SBlockRealize
        └── SBlock
            ├── reads / writes: BufferRegion
            ├── init: Stmt
            └── body: Stmt

PrimExpr
├── Var / IntImm / FloatImm
├── Add / Sub / Mul / Div / Compare
├── Cast / Select / Let
├── BufferLoad
└── Call / Ramp / Broadcast
```

> [!important] `min`、`extent` 与 `Range`
> `For(min=4, extent=8, ...)` 执行八次，默认循环变量依次为 4 到 11。`Range.from_min_extent(4, 8)` 也表示起点四、长度八。不要把 `extent` 解释成结束下标。

## `tirx.Var`

**规范定义**：TensorIR 基础变量，用于循环索引、符号尺寸、标量形参和句柄形参。每个变量具有独立身份和确定的数据类型。

**Python 构造签名**

```text
tvm.tirx.Var(name: str, dtype: str | tvm.ir.Type, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `name` | `str` | 无 | 名称提示，用于打印和诊断。 |
| `dtype` | `str | tvm.ir.Type` | 无 | 基础数据类型或句柄类型。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `tirx.Var`。主要字段为 `name`、`dtype` 和 `span`。

### 必须满足的条件

- 整数索引的位宽应与所属程序约定一致。
- 两个同名新变量不是同一个符号。

### 产生位置与使用位置

- 常见产生位置：TVMScript 参数与循环、调度、`PrimFunc` 构造和符号形状处理。
- 常见使用位置：算术表达式、循环、缓冲区索引、PrimFunc 参数和整数分析。

### 最小例子

```python
from tvm import tirx

i = tirx.Var("i", "int64")
n = tirx.Var("n", "int64")
expr = i + n
assert expr.dtype == "int64"
```

### 常见错误

- 混用 `int32` 与 `int64` 索引，依赖隐式转换。
- 按显示名称替换变量。
- 将 `relax.Var` 传给 TensorIR 构造器。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/expr.py)

## `tirx.IntImm`

**规范定义**：数据类型与数值都在编译阶段已知的整数基础表达式。

**Python 构造签名**

```text
tvm.tirx.IntImm(dtype: str, value: int, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `dtype` | `str` | 无 | 整数或布尔数据类型，例如 `int32`、`int64`、`bool`。 |
| `value` | `int` | 无 | 立即数数值。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `IntImm`，可读取 `dtype` 与 `value`。

### 必须满足的条件

- 数值必须可由目标数据类型表示。
- 布尔类型通常使用零或一。

### 产生位置与使用位置

- 常见产生位置：Python 整数转换、TVMScript 常量、化简器和调度。
- 常见使用位置：所有整数基础运算、尺寸、循环范围和属性。

### 最小例子

```python
from tvm import tirx

four = tirx.IntImm("int64", 4)
assert four.value == 4
```

### 常见错误

- 只看 Python 值而忽略 `dtype`。
- 用 `int32` 常量和 `int64` 符号尺寸混合构造后端专有调用。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/expr.py)

## `tirx.FloatImm`

**规范定义**：数据类型与数值都在编译阶段已知的浮点基础表达式。

**Python 构造签名**

```text
tvm.tirx.FloatImm(dtype: str, value: float, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `dtype` | `str` | 无 | 浮点数据类型，例如 `float16` 或 `float32`。 |
| `value` | `float` | 无 | 立即数数值。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `FloatImm`，可读取 `dtype` 与 `value`。

### 必须满足的条件

- 目标类型的舍入和特殊值行为由数据类型及目标后端决定。

### 产生位置与使用位置

- 常见产生位置：TVMScript、`tirx.const`、常量折叠和算术化简。
- 常见使用位置：浮点基础运算、比较、选择和目标代码生成。

### 最小例子

```python
from tvm import tirx

scale = tirx.FloatImm("float32", 0.5)
assert scale.dtype == "float32"
```

### 常见错误

- 假定 Python `float` 自动保持 `float64`。
- 比较打印文本而不是结构和数值。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/expr.py)

## `tirx.Cast`

**规范定义**：显式把一个基础表达式转换到目标数据类型。

**Python 构造签名**

```text
tvm.tirx.Cast(dtype: str, value: PrimExpr, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `dtype` | `str` | 无 | 结果数据类型。 |
| `value` | `PrimExpr` | 无 | 待转换的基础表达式。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `Cast`，结果 `dtype` 等于目标类型，`value` 保留输入表达式。

### 必须满足的条件

- 转换必须是目标后端可实现的数值转换。
- 窄化转换可能丢失高位或精度。

### 产生位置与使用位置

- 常见产生位置：TVMScript 类型转换、合法化 Pass、向低比特整数化和后端转换。
- 常见使用位置：化简、数据类型分析、指令选择和代码生成。

### 最小例子

```python
from tvm import tirx

x = tirx.Var("x", "int32")
y = tirx.Cast("float32", x)
assert y.dtype == "float32"
```

### 常见错误

- 把 `Cast` 当成无代价的标注。
- 未定义 NPU 对溢出、饱和与舍入的处理方式。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/expr.py)

## `tirx.Select`

**规范定义**：按基础布尔条件选择一个值的表达式。它产生值，不等同于带语句体的 `IfThenElse`。

**Python 构造签名**

```text
tvm.tirx.Select(condition: PrimExpr, true_value: PrimExpr, false_value: PrimExpr, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `condition` | `PrimExpr` | 无 | 标量或相应向量形式的布尔条件。 |
| `true_value` | `PrimExpr` | 无 | 条件为真时的结果。 |
| `false_value` | `PrimExpr` | 无 | 条件为假时的结果。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `Select`。结果数据类型由两个候选值确定。

### 必须满足的条件

- 两个候选值的数据类型必须兼容。
- 不能用它包裹 `Stmt`。

### 产生位置与使用位置

- 常见产生位置：TVMScript 条件值、化简器、向量掩码处理。
- 常见使用位置：算术化简、向低比特整数化、指令选择和代码生成。

### 最小例子

```python
from tvm import tirx

x = tirx.Var("x", "int32")
value = tirx.Select(x > 0, x, tirx.IntImm("int32", 0))
```

### 常见错误

- 与 `IfThenElse` 混用。
- 认为目标后端一定只计算被选中的候选值。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/expr.py)

## `tirx.BufferLoad`

**规范定义**：从符号缓冲区指定位置读取元素或向量的基础表达式。

**Python 构造签名**

```text
tvm.tirx.BufferLoad(buffer: Buffer, indices: list[PrimExpr], predicate: PrimExpr | None = None, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `buffer` | `tirx.Buffer` | 无 | 被读取的符号缓冲区。 |
| `indices` | `list[PrimExpr]` | 无 | 每个逻辑维度对应一个索引表达式。 |
| `predicate` | `PrimExpr | None` | `None` | 可选向量掩码。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `BufferLoad`。结果数据类型来自缓冲区元素类型及向量通道数。

### 必须满足的条件

- 索引数量必须符合缓冲区逻辑维数。
- 索引应为整数类型。
- 向量掩码通道数应与向量读取一致。
- 访问范围必须由循环与条件保证合法。

### 产生位置与使用位置

- 常见产生位置：TVMScript `A[i, j]`、缓冲区下标操作和调度变换。
- 常见使用位置：块读区域分析、向低比特整数化、内存访问优化和目标代码生成。

### 最小例子

```python
from tvm import tirx

A = tirx.decl_buffer((16,), "float32", name="A")
i = tirx.Var("i", "int32")
value = tirx.BufferLoad(A, [i])
assert value.buffer.same_as(A)
```

### 常见错误

- 索引数与缓冲区维数不一致。
- 只检查逻辑索引而忽略 `strides`、`elem_offset` 与存储范围。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/expr.py)

## `tirx.Call`

**规范定义**：TensorIR 中对内建运算、外部符号或低层调用目标的调用表达式。

**Python 构造签名**

```text
tvm.tirx.Call(dtype: str, op: tvm.ir.Op | str, args: list[PrimExpr], span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `dtype` | `str` | 无 | 调用结果的数据类型。无返回值调用通常以特定约定表示并置于 `Evaluate`。 |
| `op` | `tvm.ir.Op | str` | 无 | 被调用的内建运算或外部名称。 |
| `args` | `list[PrimExpr]` | 无 | 基础表达式实参。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 TensorIR `Call`，字段是 `dtype`、`op`、`args` 和 `span`。

### 必须满足的条件

- 结果类型必须符合被调用实现。
- 实参顺序、指针、尺寸和标量类型必须遵循外部调用约定。

### 产生位置与使用位置

- 常见产生位置：`tirx.call_packed`、内建函数辅助接口、目标专有 Intrin 和 Pass。
- 常见使用位置：低层 Pass、目标代码生成与运行时调用转换。

### 最小例子

```python
from tvm import tirx

x = tirx.Var("x", "int32")
call = tirx.Call("int32", "acme_npu.scalar_op", [x])
assert call.dtype == "int32"
```

### 常见错误

- 与 `relax.Call` 混淆。
- 遗漏外部函数结果数据类型。
- 手工拼接指针参数而未核对 PackedFunc 约定。

**固定版本源码**：[expr.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/expr.py)

## `tirx.BufferStore`

**规范定义**：把基础表达式结果写入符号缓冲区指定位置的语句。

**Python 构造签名**

```text
tvm.tirx.BufferStore(buffer: Buffer, value: PrimExpr, indices: list[PrimExpr], predicate: PrimExpr | None = None, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `buffer` | `tirx.Buffer` | 无 | 目标缓冲区。 |
| `value` | `PrimExpr` | 无 | 要写入的值。 |
| `indices` | `list[PrimExpr]` | 无 | 每个逻辑维度的索引。 |
| `predicate` | `PrimExpr | None` | `None` | 可选向量掩码。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `BufferStore` 语句，不产生可参与算术运算的值。

### 必须满足的条件

- 值的数据类型必须与缓冲区元素类型兼容。
- 索引数和掩码通道数必须一致。
- 并行写入不得产生未处理的写冲突。

### 产生位置与使用位置

- 常见产生位置：TVMScript 缓冲区赋值、张量表达式降低和调度。
- 常见使用位置：块写区域分析、存储规划、并行检查和目标代码生成。

### 最小例子

```python
from tvm import tirx

B = tirx.decl_buffer((16,), "float32", name="B")
i = tirx.Var("i", "int32")
stmt = tirx.BufferStore(B, tirx.FloatImm("float32", 0.0), [i])
```

### 常见错误

- 把返回对象当作表达式继续相加。
- 向同一位置并行写入却没有归约或同步设计。

**固定版本源码**：[stmt.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/stmt.py)

## `tirx.For`

**规范定义**：按起始值、迭代次数和步长重复执行语句体的 TensorIR 循环。

**Python 构造签名**

```text
tvm.tirx.For(loop_var: Var, min: PrimExpr, extent: PrimExpr, kind: ForKind, body: Stmt, thread_binding: IterVar | None = None, annotations: Mapping[str, Object] | None = None, step: PrimExpr | None = None, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `loop_var` | `tirx.Var` | 无 | 循环变量。 |
| `min` | `PrimExpr` | 无 | 第一次迭代的值。 |
| `extent` | `PrimExpr` | 无 | 迭代次数，不是结束下标。 |
| `kind` | `ForKind` | 无 | `SERIAL`、`PARALLEL`、`VECTORIZED`、`UNROLLED` 或 `THREAD_BINDING`。 |
| `body` | `Stmt` | 无 | 每次迭代执行的语句。 |
| `thread_binding` | `IterVar | None` | `None` | 仅线程绑定循环使用。 |
| `annotations` | `Mapping[str, Object] | None` | `None` | 供调度或后端读取的附加信息。 |
| `step` | `PrimExpr | None` | `None` | 步长；省略表示一。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `For` 语句。常用字段包括 `loop_var`、`min`、`extent`、`kind`、`body`、`thread_binding`、`annotations` 和 `step`。

### 必须满足的条件

- `extent` 表示次数，应为非负整数表达式。
- `THREAD_BINDING` 必须提供适当线程说明。
- 向低比特整数化或并行类型必须满足数据依赖要求。

### 产生位置与使用位置

- 常见产生位置：TVMScript `for`、调度和低层转换。
- 常见使用位置：调度分析、并行化、向低比特整数化、循环变换和目标代码生成。

### 最小例子

```python
from tvm import tirx

B = tirx.decl_buffer((16,), "float32")
i = tirx.Var("i", "int32")
body = tirx.BufferStore(B, tirx.FloatImm("float32", 0.0), [i])
loop = tirx.For(i, 0, 16, tirx.ForKind.SERIAL, body)
```

### 常见错误

- 把 `extent` 当成闭区间结束值。
- 只修改 `kind` 就假定循环可以安全并行。
- 为 NPU 分块循环使用动态步长却未确认指令支持。

**固定版本源码**：[stmt.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/stmt.py)

## `tirx.IfThenElse`

**规范定义**：按基础布尔条件选择语句体的控制结构。

**Python 构造签名**

```text
tvm.tirx.IfThenElse(condition: PrimExpr, then_case: Stmt, else_case: Stmt | None, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `condition` | `PrimExpr` | 无 | 布尔条件。 |
| `then_case` | `Stmt` | 无 | 条件为真时执行的语句。 |
| `else_case` | `Stmt | None` | 无 | 条件为假时执行的语句，可为 `None`。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `IfThenElse` 语句。

### 必须满足的条件

- 两个分支必须是 `Stmt`，不能直接传普通 Python 语句。
- 并行和向量环境中的条件应满足后端控制流能力。

### 产生位置与使用位置

- 常见产生位置：TVMScript 条件语句、合法化 Pass 和尾部尺寸处理。
- 常见使用位置：控制流化简、向低比特整数化、线程分析和代码生成。

### 最小例子

```python
from tvm import tirx

B = tirx.decl_buffer((16,), "float32")
i = tirx.Var("i", "int32")
store = tirx.BufferStore(B, tirx.FloatImm("float32", 1.0), [i])
stmt = tirx.IfThenElse(i < 16, store, None)
```

### 常见错误

- 与产生值的 `Select` 混淆。
- 忽略 NPU 对分支或掩码执行的实际支持。

**固定版本源码**：[stmt.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/stmt.py)

## `tirx.SeqStmt`

**规范定义**：按顺序组合多个 TensorIR 语句。

**Python 构造签名**

```text
tvm.tirx.SeqStmt(seq: list[Stmt], span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `seq` | `list[Stmt]` | 无 | 依次执行的语句列表。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `SeqStmt`；支持 `len` 和整数下标。

### 必须满足的条件

- 列表元素必须是 TensorIR 语句。
- 存在存储或外部副作用时必须保持必要顺序。

### 产生位置与使用位置

- 常见产生位置：TVMScript、多语句构造和低层 Pass。
- 常见使用位置：所有语句访问器、控制流变换和代码生成。

### 最小例子

```python
from tvm import tirx

first = tirx.Evaluate(tirx.IntImm("int32", 0))
second = tirx.Evaluate(tirx.IntImm("int32", 1))
seq = tirx.SeqStmt([first, second])
assert len(seq) == 2
```

### 常见错误

- 用空列表表示空程序却未确认构造器是否接纳。
- 为了打印整齐而重排设备提交与等待调用。

**固定版本源码**：[stmt.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/stmt.py)

## `tirx.SBlock`

**规范定义**：TensorIR 可调度块，明确记录迭代变量、读写区域、主体、可选归约初始化和局部缓冲区。

**Python 构造签名**

```text
tvm.tirx.SBlock(iter_vars: list[IterVar], reads: list[BufferRegion], writes: list[BufferRegion], name_hint: str, body: Stmt, init: Stmt | None = None, alloc_buffers: list[Buffer] | None = None, match_buffers: list[MatchBufferRegion] | None = None, annotations: Mapping[str, Object] | None = None, span: Span | None = None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `iter_vars` | `list[IterVar]` | 无 | 块迭代变量及其种类。 |
| `reads` | `list[BufferRegion]` | 无 | 块可能读取的缓冲区区域。 |
| `writes` | `list[BufferRegion]` | 无 | 块可能写入的缓冲区区域。 |
| `name_hint` | `str` | 无 | 块名称提示。 |
| `body` | `Stmt` | 无 | 块主体。 |
| `init` | `Stmt | None` | `None` | 归约块初始化。 |
| `alloc_buffers` | `list[Buffer] | None` | `None` | 块内分配的缓冲区。 |
| `match_buffers` | `list[MatchBufferRegion] | None` | `None` | 块内子区域缓冲区说明。 |
| `annotations` | `Mapping[str, Object] | None` | `None` | 调度或后端附加信息。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `SBlock` 语句。调度主要通过块名称和块引用定位，但正确性依赖读写区域及迭代变量。

### 必须满足的条件

- `reads` 与 `writes` 应覆盖主体实际访问。
- 归约块应提供正确初始化和归约迭代种类。
- 块内缓冲区的作用范围不得越出块。

### 产生位置与使用位置

- 常见产生位置：TVMScript `T.sblock()`、张量表达式降低和 TensorIR Pass。
- 常见使用位置：Schedule、依赖分析、内存规划、Tensor Intrin 替换和代码生成。

### 最小例子

```python
from tvm import tirx

evaluate = tirx.Evaluate(tirx.IntImm("int32", 0))
block = tirx.SBlock([], [], [], "root", evaluate)
realize = tirx.SBlockRealize([], True, block)
```

### 常见错误

- 只靠块名理解数据访问。
- 手工改写主体后不更新读写区域。
- 把普通循环变量直接当作块迭代变量列表。

**固定版本源码**：[stmt.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/stmt.py)

## `tirx.BufferRegion`

**规范定义**：描述符号缓冲区的一个多维矩形区域，常用于块的读写集合。

**Python 构造签名**

```text
tvm.tirx.BufferRegion(buffer: Buffer, region: list[tvm.ir.Range])
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `buffer` | `tirx.Buffer` | 无 | 区域所属缓冲区。 |
| `region` | `list[tvm.ir.Range]` | 无 | 每个逻辑维度的起点和长度。 |

### 返回对象与可观察字段

返回 `BufferRegion`，字段为 `buffer` 和 `region`。

### 必须满足的条件

- 区域项数应与缓冲区逻辑维数一致。
- `Range.extent` 表示长度。

### 产生位置与使用位置

- 常见产生位置：TVMScript 块读写说明、缓冲区切片和区域分析。
- 常见使用位置：依赖分析、缓存读写、分块、并行安全检查和后端内存计划。

### 最小例子

```python
import tvm
from tvm import tirx

A = tirx.decl_buffer((16, 16), "float32")
region = tirx.BufferRegion(
    A,
    [tvm.ir.Range.from_min_extent(0, 4),
     tvm.ir.Range.from_min_extent(0, 8)],
)
```

### 常见错误

- 把 `Range` 第二项当结束下标。
- 数据布局变换后继续使用旧的逻辑区域。

**固定版本源码**：[stmt.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/stmt.py)

## `tirx.PrimFunc`

**规范定义**：以 TensorIR 语句为主体的基础函数，描述缓冲区、标量和句柄上的低层计算。

**Python 构造签名**

```text
tvm.tirx.PrimFunc(params, body, ret_type=None, buffer_map=None, attrs=None, span=None)
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `params` | `list[tirx.Var | tirx.Buffer]` | 无 | 函数形参。传入 Buffer 时构造器会创建句柄变量并写入 `buffer_map`。 |
| `body` | `tirx.Stmt` | 无 | 函数主体。 |
| `ret_type` | `tvm.ir.Type | None` | `None` | 返回类型；典型目标传递内核不直接返回张量。 |
| `buffer_map` | `dict[Var, Buffer] | None` | `None` | 句柄形参与逻辑缓冲区的对应关系。 |
| `attrs` | `tvm.ir.Attrs | dict | None` | `None` | 函数属性，例如 `global_symbol`、`tir.noalias`、目标属性。 |
| `span` | `Span | None` | `None` | 可选源码位置。 |

### 返回对象与可观察字段

返回 `PrimFunc`。主要字段是 `params`、`body`、`ret_type`、`buffer_map`、`attrs` 和 `span`。

### 必须满足的条件

- 参数只能是 `Var` 或 `Buffer`。
- `body` 必须是 TensorIR 语句。
- 缓冲区形参顺序与 `call_tir` 输入输出准备必须一致。
- 函数属性必须与目标代码生成要求一致。

### 产生位置与使用位置

- 常见产生位置：TVMScript `@T.prim_func`、张量表达式降低、Relax 运算合法化和调度。
- 常见使用位置：Schedule、TensorIR Pass、Target 代码生成、`call_tir` 和外部编译器。

### 最小例子

```python
from tvm import tirx

A = tirx.decl_buffer((16,), "float32", name="A")
B = tirx.decl_buffer((16,), "float32", name="B")
i = tirx.Var("i", "int32")
body = tirx.For(
    i,
    0,
    16,
    tirx.ForKind.SERIAL,
    tirx.BufferStore(B, tirx.BufferLoad(A, [i]), [i]),
)
func = tirx.PrimFunc([A, B], body)
assert len(func.params) == 2
```

### 常见错误

- 把 Buffer 对象与生成后的句柄形参视为同一字段。
- 修改形参顺序后未同步调用端。
- 将 Relax 表达式作为函数体。

**固定版本源码**：[function.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/function.py)

## `tirx.decl_buffer`

```text
tvm.tirx.decl_buffer(
    shape,
    dtype=None,
    name="buffer",
    data=None,
    strides=None,
    elem_offset=None,
    scope="",
    data_alignment=-1,
    offset_factor=0,
    buffer_type="",
    axis_separators=None,
    span=None,
) -> tvm.tirx.Buffer
```

`Buffer` 是符号存储视图，不负责分配实际设备内存。重要参数如下：

| 参数 | 功能与要求 |
| --- | --- |
| `shape` | 每个逻辑维度的长度 |
| `dtype` | 元素数据类型；不应依赖项目外部的隐式默认值 |
| `name` | 名称提示 |
| `data` | 可选数据指针变量 |
| `strides` | 可选显式步幅；省略时按紧凑布局理解 |
| `elem_offset` | 相对数据指针的元素偏移，不是字节偏移 |
| `scope` | 存储区域名称，空字符串通常表示全局内存 |
| `data_alignment` | 数据指针字节对齐，`-1` 使用 TVM 默认值 |
| `offset_factor` | `elem_offset` 必须满足的倍数要求，零表示不增加倍数要求 |
| `buffer_type` | 空字符串或 `auto_broadcast` |
| `axis_separators` | 逻辑维度分组后形成物理维度的位置列表 |
| `span` | 可选源码位置 |

> [!warning] Buffer 不等于运行时 Tensor
> `Buffer` 记录形状、步幅、偏移、数据类型和存储区域，是编译阶段对象；`runtime.Tensor` 持有或引用运行阶段真实存储。NPU 代码生成器需要把 Buffer 的逻辑访问转换为设备地址计算，但不能把 Python `Buffer` 对象交给驱动执行。

## 表达式与语句的选择

| 要表达的动作 | 对象 |
| --- | --- |
| 读取 `A[i]` 并参与加法 | `BufferLoad` |
| 把值写入 `B[i]` | `BufferStore` |
| 根据条件选择两个标量中的一个 | `Select` |
| 根据条件执行两个语句体之一 | `IfThenElse` |
| 调用有返回值的低层内建函数 | `tirx.Call` |
| 调用只产生副作用的低层函数 | `Evaluate(tirx.Call(...))` |
| 按顺序执行多个写入或调用 | `SeqStmt` |

## 一个可调度 PrimFunc 的逐字段例子

```python
from tvm.script import ir as I
from tvm.script import tir as T

@I.ir_module
class CopyModule:
    @T.prim_func
    def copy(
        A: T.Buffer((16,), "float32"),
        B: T.Buffer((16,), "float32"),
    ):
        T.func_attr({"global_symbol": "copy", "tir.noalias": True})
        for i in range(16):
            with T.sblock("copy"):
                vi = T.axis.spatial(16, i)
                T.reads(A[vi])
                T.writes(B[vi])
                B[vi] = A[vi]
```

检查对象：

```python
import tvm

func = CopyModule["copy"]
assert isinstance(func, tvm.tirx.PrimFunc)
assert len(func.params) == 2
assert len(func.buffer_map) == 2
assert func.attrs["global_symbol"] == "copy"
```

本例中 `params` 保存两个句柄变量，`buffer_map` 说明每个句柄对应哪个 `Buffer`。循环主体最终包含块实现节点，块的读写区域分别覆盖 `A[vi]` 与 `B[vi]`。调度根据块结构改变循环，但仍需保持相同计算结果和合法访问。

## NPU 后端必须明确的字段

| 对象 | 至少检查的字段 | 原因 |
| --- | --- | --- |
| `PrimFunc` | 参数顺序、`buffer_map`、函数属性 | 决定入口函数和参数准备 |
| `Buffer` | 形状、数据类型、步幅、元素偏移、存储区域、对齐 | 决定设备地址和 DMA 要求 |
| `For` | 起点、次数、步长、循环种类 | 决定指令循环与尾部处理 |
| `SBlock` | 读写区域、归约初始化、块注解 | 决定数据搬运与指令选择 |
| `BufferLoad/Store` | 索引、掩码、向量通道数 | 决定访问是否合法 |
| `tirx.Call` | 调用名、返回类型、参数顺序 | 决定专有指令或运行时函数 |

## 固定版本源码与在线参考

- [TensorIR Python API](https://tvm.apache.org/docs/tirx/api/tirx.html)
- [Tensor Expression API](https://tvm.apache.org/docs/reference/api/python/te.html)
- [`python/tvm/tirx/expr.py`](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/expr.py)
- [`python/tvm/tirx/stmt.py`](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/stmt.py)
- [`python/tvm/tirx/buffer.py`](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/buffer.py)
- [`python/tvm/tirx/function.py`](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/tirx/function.py)
- [`include/tvm/tirx/expr.h`](https://github.com/apache/tvm/blob/v0.24.0/include/tvm/tirx/expr.h)
- [`include/tvm/tirx/stmt.h`](https://github.com/apache/tvm/blob/v0.24.0/include/tvm/tirx/stmt.h)
- [`include/tvm/tirx/function.h`](https://github.com/apache/tvm/blob/v0.24.0/include/tvm/tirx/function.h)
