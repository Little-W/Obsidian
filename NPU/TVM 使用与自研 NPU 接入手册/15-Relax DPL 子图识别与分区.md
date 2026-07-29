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

# 15. Relax DPL 子图识别与分区

> [!abstract] 本章内容
> 本章以 `matmul + bias + relu` 为例，说明如何用 Relax DPL 描述结构、用检查函数核对硬件条件、注册 FusionPattern、完成分区，并解释每个子图为何被接纳或保留在主机。

## 15.1 为什么不能只做算子白名单

同一个 `relax.matmul` 可能具有不同秩、dtype、转置形式、K 维、批次维度广播与动态尺寸。硬件也可能要求 K 是 32 的倍数、输入连续、权重使用特定布局、输出最后一维对齐。只检查运算名会把无法执行的实例交给 NPU，错误要到很后面才出现。

一个可靠的接纳函数应按以下次序检查：

1. 运算结构是否匹配；
2. 输入输出 StructInfo 是否完整；
3. dtype 是否被硬件接受；
4. 秩、维度和广播形式是否可处理；
5. 属性是否在允许集合内；
6. 常量要求是否满足；
7. 片上容量或分块方案是否存在；
8. 预期收益是否覆盖提交与数据搬运开销。

## 15.2 最小 DPL 结构

```python
from tvm.relax.dpl import wildcard, is_op
from tvm.relax.transform import FusionPattern

x = wildcard()
w = wildcard()
bias = wildcard()
mm = is_op("relax.matmul")(x, w)
add = is_op("relax.add")(mm, bias)
root = is_op("relax.nn.relu")(add)

pattern = FusionPattern(
    name="acme_npu.matmul_bias_relu",
    pattern=root,
    annotation_patterns={
        "x": x,
        "w": w,
        "bias": bias,
        "matmul": mm,
        "root": root,
    },
    check=check_matmul_bias_relu,
)
```

`wildcard()` 接受任意表达式；`is_op()` 限定调用的 Relax 运算。`annotation_patterns` 给子表达式命名，检查函数通过这些名称取得实际节点。组合名称应包含后端前缀，`RunCodegen` 使用前缀找到 `relax.ext.acme_npu`。

## 15.3 检查函数骨架

```python
from tvm import relax

SUPPORTED = {"int8", "int16"}

def tensor_info(expr):
    info = expr.struct_info
    if not isinstance(info, relax.TensorStructInfo):
        return None
    return info

def check_matmul_bias_relu(ctx):
    x_info = tensor_info(ctx.annotated_expr["x"])
    w_info = tensor_info(ctx.annotated_expr["w"])
    out_info = tensor_info(ctx.annotated_expr["root"])
    if x_info is None or w_info is None or out_info is None:
        return False
    if str(x_info.dtype) not in SUPPORTED:
        return False
    if x_info.ndim != 2 or w_info.ndim != 2:
        return False
    if x_info.shape is None or w_info.shape is None:
        return False
    # 示例只接收静态二维尺寸；正式实现应输出拒绝原因。
    x_shape = x_info.shape.values
    w_shape = w_info.shape.values
    if not all(hasattr(v, "value") for v in [*x_shape, *w_shape]):
        return False
    m, k = [int(v.value) for v in x_shape]
    wk, n = [int(v.value) for v in w_shape]
    if k != wk or k % 32 != 0 or n % 16 != 0:
        return False
    return m > 0 and k > 0 and n > 0
```

> [!warning] 示例不是最终规则
> 上面代码为了教学只接收静态二维输入。正式项目应检查 bias 形状、广播、对齐、内存占用、累加类型和固件能力；还应返回结构化拒绝原因，而不是只给 `False`。

## 15.4 让拒绝原因可观察

FusionPattern 的 `check` 返回布尔值。为了保存原因，可以把纯检查逻辑写成返回结果对象的函数，DPL 包装层只取 `accepted`：

```python
from dataclasses import dataclass

@dataclass(frozen=True)
class CheckResult:
    accepted: bool
    code: str
    detail: str

def inspect_matmul(spec) -> CheckResult:
    if spec.dtype not in SUPPORTED:
        return CheckResult(False, "dtype", f"unsupported dtype: {spec.dtype}")
    if spec.k % 32:
        return CheckResult(False, "k_tail", f"K={spec.k} is not divisible by 32")
    return CheckResult(True, "ok", "accepted")
```

编译服务可在预检查阶段遍历候选并记录结果；真正的 DPL check 再调用同一纯函数。这样不会把日志副作用塞入模式匹配器，也便于单测。

## 15.5 注册与优先级

```python
from tvm.relax.backend.pattern_registry import register_patterns

register_patterns([
    standalone_matmul,
    matmul_bias,
    matmul_bias_relu,
])
```

Apache TVM v0.24.0 的 Example NPU 源码注明：列表中越靠后的模式优先级越高。因此一般运算先放，具体组合后放。需要为优先级写测试，不能依赖读者记忆。

## 15.6 分区流水

```python
import tvm.relax.backend.contrib.acme_npu
from tvm.relax.backend.pattern_registry import get_patterns_with_prefix
from tvm.relax.transform import (
    FuseOpsByPattern,
    MergeCompositeFunctions,
    RunCodegen,
)

patterns = get_patterns_with_prefix("acme_npu")
mod = FuseOpsByPattern(
    patterns,
    bind_constants=False,
    annotate_codegen=True,
)(mod)
mod = MergeCompositeFunctions()(mod)
mod = RunCodegen()(mod)
```

关键参数：

- `bind_constants=False`：权重仍作为外部函数参数，便于主机管理、共享和单独打包；
- `annotate_codegen=True`：增加 `Codegen` 与外部符号信息，否则 `RunCodegen` 不知道调用哪个后端；
- `MergeCompositeFunctions`：把相邻且属于同一外部后端的组合函数整理成外部调用单元；
- `RunCodegen`：调用 `relax.ext.acme_npu`，把外部函数替换为 `ExternFunc` 调用并附加运行时模块。

## 15.7 Pass 次序

推荐的简化次序：

```text
导入 Relax
  → 基础规范化
  → 常量折叠与与硬件无关的图改写
  → NPU FuseOpsByPattern
  → MergeCompositeFunctions
  → RunCodegen
  → 剩余运算 LegalizeOps
  → 普通 FuseOps / FuseTIR
  → VM 与本地代码构建
```

若在 NPU 分区之前执行会改变所需结构的通用融合，DPL 可能看不到原始组合。反过来，若在必要的规范化之前分区，同一数学计算可能呈现多种写法，模式数量会快速膨胀。

## 15.8 分区测试

结构测试至少覆盖：

| 测试 | 预期 |
| --- | --- |
| 完整 `matmul+bias+relu` | 一个组合函数 |
| K 不满足硬件步长 | 不进入 NPU |
| dtype 不被接受 | 不进入 NPU |
| bias 广播不被接受 | 不进入 NPU |
| MatMul 结果有两个使用者 | 按组合规则决定是否拆分 |
| 更具体组合与普通 MatMul 同时注册 | 更具体组合优先 |
| 连续两个可接纳子图 | 外部函数数量符合设计 |
| 重复执行分区 Pass | 结构不继续变化 |

```python
assert any(
    f.attrs and f.attrs.get("Codegen") == "acme_npu"
    for _, f in mod.functions.items()
    if isinstance(f, relax.Function)
)
```

不要只用字符串包含检查。更稳妥的方式是构造期望 IRModule，使用 `tvm.ir.assert_structural_equal` 比较结构。

## 15.9 Example NPU 的价值与限制

v0.24.0 自带 Example NPU，包含 `patterns.py`、C++ JSON 序列化器、JSON Runtime、CMake 和测试。它是教学空壳，运行时主要记录分派信息，并不产生真实数值。复制目录后必须替换：

- 返回固定 `True` 的内存与 dtype 检查；
- 仅记录日志的执行函数；
- 示例 SRAM、阵列和向量宽度；
- 模糊的字符串运算分派；
- 没有真实设备内存与同步的部分。

## 15.10 官方依据

- [Relax DPL](https://tvm.apache.org/docs/deep_dive/relax/dpl.html)
- [Operator Fusion](https://tvm.apache.org/docs/arch/fusion.html)
- [External Library Dispatch](https://tvm.apache.org/docs/arch/external_library_dispatch.html)
- [Example NPU patterns](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/relax/backend/contrib/example_npu/patterns.py)
- [Example NPU tests](https://github.com/apache/tvm/blob/v0.24.0/tests/python/contrib/test_example_npu.py)
