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

# 09. PackedFunc、Module 与运行时

> [!abstract] 本章内容
> 本章直接定义 PackedFunc、Device、运行时 Tensor 和运行时 Module，说明它们的字段、查询方式、参数转换和生命周期。这里的 Module 是可执行代码与资源容器，不是保存 Relax Function 和 PrimFunc 的 IRModule。

## 从编译对象到运行时对象

| 对象 | 严格定义 | 主要使用阶段 |
| --- | --- | --- |
| `IRModule` | 保存全局 IR 函数及模块属性的编译阶段容器 | 导入、变换、编译 |
| `PackedFunc` | 通过 TVM FFI 统一调用约定暴露的动态可调用函数 | 编译扩展与运行阶段 |
| `runtime.Module` | 按名称提供 PackedFunc，并可导入子模块的代码或资源容器 | 加载、执行、导出 |
| `Device` | 由设备种类和设备编号组成的运行阶段设备标识 | 分配、复制、同步 |
| `runtime.Tensor` | 持有或引用实际张量存储的运行时容器 | 函数输入、输出与设备数据 |

## PackedFunc

PackedFunc 是 TVM 跨 Python、C++、运行时模块和设备后端使用的统一可调用接口。它把参数装入 TVM 的通用参数表示，由被调用函数按约定读取，再把返回值转换回调用方。PackedFunc 不是 Relax Function，也不保存 Relax 函数体。

### 全局 PackedFunc 与模块 PackedFunc

| 种类 | 注册或产生位置 | 查询方式 | 典型用途 |
| --- | --- | --- | --- |
| 全局函数 | `register_global_func` 或 C++ 全局注册 | `tvm.get_global_func(name)` | Pass 入口、外部代码生成构造函数、工具函数 |
| 模块函数 | 某个 `runtime.Module` 的实现 | `mod.get_function(name, query_imports=True)` | 已编译内核、外部子图、VM 入口 |

```python
import tvm

def require_global(name):
    func = tvm.get_global_func(name, allow_missing=True)
    if func is None:
        raise RuntimeError(f"global function is not registered: {name}")
    return func

def require_module_function(mod, name):
    func = mod.get_function(name, query_imports=True)
    if func is None:
        raise RuntimeError(f"module function is missing: {name}")
    return func
```

### 参数转换

Python 标量、字符串、TVM Object、运行时 Tensor、Device、数组和字典能否作为参数，取决于 FFI 转换规则和被调用函数的签名。外部 NPU 函数应明确列出参数数量、顺序、数据类型、所有权和错误返回方式，不能只依赖一次成功调用推断接口。

## 运行时核心对象

### `tvm.runtime.Device`

**规范定义**：运行阶段的设备标识，包含 DLPack 设备种类和设备编号，并通过 DeviceAPI 查询能力、分配内存和同步。

**Python 构造签名**

```text
tvm.runtime.device(device_type: str | int | DLDeviceType, index: int | None = None) -> Device
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `device_type` | `str | int | DLDeviceType` | 无 | 设备种类名称或编号，例如 `cpu`、`cuda` 或已注册自研设备。 |
| `index` | `int | None` | `None` | 设备编号；省略时通常为零。 |

### 返回对象与可观察字段

返回 `Device`。常用字段或属性包括 `device_type`、`index`、`exist`；可用能力属性取决于 DeviceAPI 实现。

### 必须满足的条件

- 设备种类必须已注册。
- `exist` 同时受到构建支持、物理设备、驱动和访问权限影响。
- 自研 NPU 的设备编号含义必须稳定。

### 产生位置与使用位置

- 常见产生位置：应用、VM 初始化、RPC 会话和运行时测试。
- 常见使用位置：Tensor 分配、函数调用、VM 内存分配器、性能测量和 DeviceAPI。

### 最小例子

```python
import tvm

cpu0 = tvm.device("cpu", 0)
assert cpu0.index == 0
assert cpu0.exist
```

### 常见错误

- 只因设备对象能构造就认为驱动和硬件可用。
- 把 Target 名称与运行时设备种类视为自动相同。
- 多设备程序忽略设备编号。

**固定版本源码**：[device.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/runtime/device.py)

### `tvm.runtime.Tensor`

**规范定义**：运行阶段的轻量张量容器，保存数据指针、形状、数据类型、设备和可选存储区域。它不提供 NumPy 式算术运算。

**Python 构造签名**

```text
tvm.runtime.tensor(arr, device=None, mem_scope=None) -> tvm.runtime.Tensor
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |
| `arr` | `array-like | DLPack compatible` | 无 | 源数组或可转换数据。 |
| `device` | `Device | None` | `None` | 目标设备；省略时通常使用 CPU。 |
| `mem_scope` | `str | None` | `None` | 可选存储区域。 |

### 返回对象与可观察字段

返回 `runtime.Tensor`。常用属性与方法为 `shape`、`dtype`、`device`、`numpy()`、`copyfrom()` 和 `copyto()`。

### 必须满足的条件

- 复制时形状必须一致。
- 非连续 NumPy 数据可能先被转换为连续存储。
- 设备数据转为 NumPy 通常会触发同步复制。

### 产生位置与使用位置

- 常见产生位置：`runtime.tensor`、`runtime.empty`、DLPack 导入和 VM 输出。
- 常见使用位置：PackedFunc、VM、DeviceAPI、RPC 与应用接口。

### 最小例子

```python
import numpy as np
import tvm

x = tvm.runtime.tensor(
    np.arange(8, dtype="float32").reshape(2, 4),
    device=tvm.cpu(),
)
assert x.shape == (2, 4)
np.testing.assert_array_equal(x.numpy(), np.arange(8).reshape(2, 4))
```

### 常见错误

- 对 `runtime.Tensor` 直接执行 `x + y`。
- 在计时范围内调用 `numpy()`，把设备同步和回传时间混入设备内核时间。
- 忽略外部张量的连续存储和对齐要求。

**固定版本源码**：[_tensor.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/runtime/_tensor.py)

### `tvm.runtime.Module`

**规范定义**：运行阶段的代码与资源容器。模块按名称提供 PackedFunc，可以导入子模块，也可以支持保存、导出或二进制序列化。

**Python 构造签名**

```text
通常由 tvm.runtime.load_module(path)、Executable.jit() 或后端构造函数产生
```

### 参数

| 参数 | 接受的类型 | 默认值 | 功能与要求 |
| --- | --- | --- | --- |

### 返回对象与可观察字段

模块常用接口为 `get_function(name, query_imports=False)`、`__getitem__(name)`、`imports`、`import_module()`、`export_library()`、`kind` 和 `time_evaluator()`。

### 必须满足的条件

- 函数名称必须与编译端导出的全局符号一致。
- 需要随主库发布的外部模块必须可序列化或被正确打包。
- 模块导入树不能依赖仅在编译进程存在的 Python 对象。

### 产生位置与使用位置

- 常见产生位置：LLVM/CUDA 等代码生成、BYOC 外部运行时构造函数、`load_module` 和 `Executable.jit()`。
- 常见使用位置：VirtualMachine、应用、RPC、模块导出与函数查询。

### 最小例子

```python
import tvm

def require_func(mod, name):
    func = mod.get_function(name, query_imports=True)
    if func is None:
        raise RuntimeError(f"missing runtime function: {name}")
    return func
```

### 常见错误

- 只在根模块查询函数，忽略导入模块。
- 外部模块能在当前进程运行，却不能导出后重新加载。
- 把模块 `kind` 当作 Target 字符串。

**固定版本源码**：[module.py](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/runtime/module.py)

## Module 导入关系

根模块可以导入主机模块、设备模块和外部 BYOC 模块。`query_imports=True` 会在导入关系中继续查找函数。导出时，每个子模块必须能够编译进主库或采用稳定格式保存和重新加载。

```python
def list_module_tree(root):
    visited = set()

    def visit(mod, depth):
        if mod in visited:
            return
        visited.add(mod)
        print("  " * depth, mod.kind)
        for child in mod.imports:
            visit(child, depth + 1)

    visit(root, 0)
```

## 自研 NPU 运行时必须明确的内容

1. 模块类型键、全局函数名和序列化版本；
2. Tensor 的设备、形状、数据类型、步幅和对齐检查；
3. 设备内存的申请、释放和所有权；
4. 命令提交、事件等待、超时和错误转换；
5. 模块导出后在新进程中的加载行为；
6. 多设备编号和并发调用规则；
7. 驱动与固件最低版本。

## 本章参考资料

- [Python 运行时 API](https://tvm.apache.org/docs/reference/api/python/runtime/runtime.html)
- [TVM 运行时系统](https://tvm.apache.org/docs/arch/runtime.html)
- [模块序列化](https://tvm.apache.org/docs/arch/introduction_to_module_serialization.html)
- [`python/tvm/runtime/module.py`](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/runtime/module.py)
- [`python/tvm/runtime/_tensor.py`](https://github.com/apache/tvm/blob/v0.24.0/python/tvm/runtime/_tensor.py)

## 实现说明与验证步骤

> [!note] 依据与适用范围
> 本节依据所列 Apache TVM 官方资料和 v0.24.0 源码整理，给出输入条件、操作步骤、预期结果、异常处理和自研 NPU 适配要求。接口细节以固定版本源码与测试为准，在线页面用于补充说明。

### 09.A 目标与适用范围

在 Python 侧注册一个 PackedFunc，再通过全局注册表取回并调用。随后把它与 `runtime.Module.GetFunction` 的模块内查询作比较。

参考样本保持输入规模较小，以便直接检查对象、字段和输出。首次执行时不要同时加入图改写、外部代码生成和真实设备执行；应先确认当前阶段的输入与输出，再增加后续处理。建议为该项验证建立独立目录，保存命令、标准输出、IR、编译产物摘要和环境信息。

### 09.B 参考实现

**官方依据：** [TVM 运行时系统](https://tvm.apache.org/docs/arch/runtime.html) 与 [模块序列化](https://tvm.apache.org/docs/arch/introduction_to_module_serialization.html)。

**v0.24.0 源码位置：** `docs/arch/runtime.rst`、`src/runtime/module.cc`、`3rdparty/tvm-ffi/include/tvm/ffi/function.h`、`3rdparty/tvm-ffi/include/tvm/ffi/extra/module.h`。

```python
import tvm

@tvm.register_func("acme_npu.demo.add", override=True)
def add(a, b):
    return a + b

packed = tvm.get_global_func("acme_npu.demo.add")
assert packed(7, 5) == 12
print(type(packed), packed(7, 5))
```

按以下顺序执行：

1. 在新进程中确认 `tvm.__file__`、动态库路径和 TVM 提交，避免受到旧进程注册状态影响；
2. 将参考实现保存到单独文件，只补充本节明确要求的输入对象，不先加入额外优化；
3. 执行后保存完整输出；若生成 IR，同时保存 `script(show_meta=True)` 的文本；
4. 把输出与下面的预期现象逐项比较，不以“没有抛出异常”代替功能检查；
5. 重复执行一次并比较主要产物，确认结果没有依赖临时全局状态或未固定的遍历顺序。

> [!success] 预期现象
> Python 函数经 TVM FFI 包装后，可由统一调用接口接收和返回受支持对象。全局函数名属于进程级注册表；模块函数名属于某个 `runtime.Module`，两者的所有权和生命周期不同。

> [!tip] 输出检查顺序
> 先看对象类型和函数数量，再看属性、调用形式、形状与数据类型，最后看运行结果或编译产物。若前一项不符合预期，先停止后续步骤。这样能把问题限定在最早出现差异的阶段。

### 09.C 单项条件验证

删除或改写注册模块的导入语句后，在新进程查询同一名称。若当前进程仍能查询，说明测试受到了已有注册状态影响，应把注册类测试放在独立进程。

执行条件变化样本时，复制参考实现的输入与环境，只修改上文指出的一项。对两个输出进行结构比较，并记录以下四项：

1. 第一次出现差异的是哪一个阶段？
2. 差异表现为函数、属性、形状、数据类型、编译产物还是运行结果？
3. 当前行为是明确拒绝、交给其他后端执行，还是编译错误？
4. 日志是否足以让另一位开发者不查看本次进程状态也能复现？

如果同时观察到多个变化，应继续缩小条件变化样本。参考实现用于确认正常处理，单项条件验证用于确认系统为何接受、拒绝或转交当前输入。

### 09.D 自研 NPU 适配要求

自研运行时模块至少提供外部函数查询、模块类型标识、序列化和加载。不要把所有设备状态放进全局注册函数；会话、队列和设备内存应归属于明确的模块或运行时对象。

改造时建议保留三份相互独立的输入：最小 Relax 或 TensorIR、设备编译器输入、运行时调用输入。三份输入使用同一个样本编号，并记录转换前后的关键字段。这样可以分别测试 TVM 变换、NPU 编译器和驱动，不需要每次都运行完整模型。

至少补充以下样本：

- 一个完全满足能力要求的正向样本；
- 一个只改变数据类型的反向样本；
- 一个只改变形状或属性的反向样本；
- 一个包含主机与 NPU 混合执行的样本；
- 一个导出后在新进程加载的样本；
- 若支持动态尺寸，再增加最小值、常用值和最大值附近的样本。

### 09.E 源码定位

从上文列出的源码位置选择一个公开 API，依次找到 Python 调用、FFI 注册、C++ 实现和测试。记录函数签名、主要输入、主要输出、会写入的模块属性以及失败方式。若名称只在文档出现而源码中找不到，继续搜索注册字符串、属性键或错误文本。

> [!important] 验证项目
> 1. 执行前记录参考实现的对象关系；2. 执行后用实际输出修正记录；3. 增加一个会被明确拒绝的输入；4. 标明自研 NPU 接入需要修改的层次与保持不变的层次；5. 把结果整理成可由自动测试检查的断言。

### 09.F 检查清单

- [ ] 示例可在固定 v0.24.0 环境重复执行，或已明确列出所需可选依赖；
- [ ] 预期现象包含可检查的结构、字段或数值，不只是“运行成功”；
- [ ] 单条件变化能触发预期的拒绝、转交或结构差异；
- [ ] 能从官方页面定位到固定版本源码和测试；
- [ ] NPU 改造说明包含编译阶段、运行阶段与部署阶段；
- [ ] 失败时保留最小输入、环境、阶段输出和第一个错误。
