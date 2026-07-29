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

# 16. BYOC 代码生成器

> [!abstract] 本章内容
> 本章说明 `RunCodegen` 如何找到外部编译器，如何遍历组合函数、生成 JSON 或二进制产物、建立 runtime.Module，以及真实 NPU 编译器应补充的形状、常量、工作区、重定位和版本信息。

## 16.1 调用位置

分区后的外层 Relax 函数带有 `Codegen="acme_npu"`。`RunCodegen` 收集这些函数，通过全局注册表取得 `relax.ext.acme_npu`，再把函数数组、选项和常量名称传给后端。后端返回一个或多个 runtime.Module，TVM 把这些模块接入最终可执行对象。

```mermaid
sequenceDiagram
    participant P as RunCodegen
    participant R as 全局注册表
    participant C as acme_npu 编译器
    participant M as 运行时模块
    P->>R: 查找 relax.ext.acme_npu
    R-->>P: PackedFunc
    P->>C: functions, options, constant_names
    C->>C: 子图分析与命令生成
    C->>M: 创建模块
    M-->>P: Module 数组
```

## 16.2 与 v0.24.0 Example NPU 一致的函数形态

```cpp
ffi::Array<ffi::Module> AcmeNPUCompiler(
    ffi::Array<relax::Function> functions,
    ffi::Map<ffi::String, ffi::Any> options,
    ffi::Map<relax::Constant, ffi::String> constant_names) {
  ffi::Array<ffi::Module> modules;
  auto create = tvm::ffi::Function::GetGlobalRequired(
      "runtime.AcmeNPURuntimeCreate");

  for (const auto& func : functions) {
    auto symbol = relax::GetExtSymbol(func);
    auto artifact = CompileSubgraph(func, options, constant_names);
    modules.push_back(
        create(symbol, artifact.binary, artifact.metadata,
               artifact.constant_names).cast<ffi::Module>());
  }
  return modules;
}

TVM_FFI_STATIC_INIT_BLOCK() {
  namespace refl = tvm::ffi::reflection;
  refl::GlobalDef().def("relax.ext.acme_npu", AcmeNPUCompiler);
}
```

这是接口骨架，`CompileSubgraph` 是项目的核心。它应是确定性的：相同 IR、Target、常量与编译器版本产生相同产物，或至少产生功能相同且可追溯的产物。

## 16.3 JSON 还是二进制

| 格式 | 优点 | 缺点 | 推荐使用阶段 |
| --- | --- | --- | --- |
| JSON 图 | 容易查看、适合早期联调 | 体积大、解析慢、字段类型限制多 | 空壳与第一个真实运算 |
| FlatBuffer / 自定义表 | 兼顾可扩展与读取速度 | 需要格式工具与兼容策略 | 稳定的图级运行时 |
| 命令二进制 | 加载快、接近硬件 | 调试困难、重定位复杂 | 固件协议稳定后 |
| 混合包 | 元数据可读，命令段紧凑 | 打包器更复杂 | 产品阶段 |

> [!tip] 建议
> 早期先输出可读 JSON，同时生成命令反汇编文本。硬件执行稳定后再把命令段改为二进制，但保留元数据、版本、散列值和离线解析工具。

## 16.4 子图编译步骤

### 步骤 1：读取函数接口

收集每个参数和返回值的：

- 名称与顺序；
- 形状、数据类型、设备；
- 是否为常量；
- 允许的步长；
- 别名与原地写要求；
- 动态维度及其上限。

缺少必要 StructInfo 时，代码生成器应给出编译错误，不应猜测。

### 步骤 2：建立内部图

把 Relax 组合函数转换成自研内部节点。内部节点需要保存运算类型、属性、输入输出值、常量引用和源位置。转换表要版本化，并为每个运算写单测。

### 步骤 3：选择数据布局

根据运算、数据类型、分块和消费者选择布局。若生产者与消费者在同一个组合函数内，可保留 NPU 私有布局；外部函数输入输出必须遵守 ABI，或显式插入重排运算。

### 步骤 4：工作区与生命周期

对内部值做存活区间分析，复用不重叠的缓冲区。片上存储不足时选择更小分块、分阶段执行或使用片外工作区。工作区大小应是输入尺寸的确定函数，并写入元数据。

### 步骤 5：命令生成

生成 DMA、矩阵、向量、复杂函数和同步命令。每条命令引用逻辑缓冲区或重定位项，不直接写入编译主机虚拟地址。命令序号与源节点保持关联，便于设备错误反查。

### 步骤 6：静态检查

检查命令字段、地址范围、对齐、缓冲区越界、依赖事件、工作区上限、命令数和固件 ABI。静态检查失败必须阻止产物输出。

### 步骤 7：模块构造

创建 runtime.Module，保存外部符号、命令、元数据、常量名称和所需版本。模块必须支持导出与重新加载。

## 16.5 常量处理

`constant_names` 让代码生成器用稳定名称引用 Relax Constant。常见选择：

1. 常量仍由 TVM 保存，运行时 `Init` 时传入；
2. 编译器预重排后把常量嵌入 NPU 模块；
3. 常量单独保存为权重包，多个模型函数共享。

预重排可以减少每次启动工作，但必须把源常量散列值、目标布局、数据类型、编译器版本和硬件型号写入缓存键。常量内容变化后不得复用旧结果。

## 16.6 选项与 Target

编译选项不应散落在环境变量。建议统一成：

```python
npu_options = {
    "arch": "npu_v1",
    "firmware_abi": 3,
    "opt_level": 2,
    "sram_bytes": 1048576,
    "enable_fused_activation": True,
    "debug_artifacts": "/tmp/acme_npu_debug",
}
```

硬件固定限制来自 Target 或能力文件；用户可选策略来自 PassContext 或后端 options。两类信息发生冲突时，固定限制优先，并报告具体字段。

## 16.7 JSONSerializer 起点

若后端接受图结构，可继承 TVM 的 `JSONSerializer`。v0.24.0 Example NPU 的访问器取得组合函数 `Composite` 属性，把调用参数变为 JSON 节点输入，再以 `runtime.ExampleNPUJSONRuntimeCreate` 建立模块。这条路线适合快速搭建，但真实项目通常还要写入：

- 完整运算属性；
- 每个输入输出的形状与数据类型；
- 常量索引；
- 数据布局；
- 工作区；
- 设备版本；
- 编译选项；
- 错误定位信息。

## 16.8 构建开关

```cmake
if(USE_ACME_NPU_CODEGEN)
  tvm_file_glob(
    GLOB COMPILER_ACME_NPU_SRCS
    src/relax/backend/contrib/acme_npu/*.cc
  )
  list(APPEND COMPILER_SRCS ${COMPILER_ACME_NPU_SRCS})
endif()

if(USE_ACME_NPU_RUNTIME)
  tvm_file_glob(
    GLOB RUNTIME_ACME_NPU_SRCS
    src/runtime/contrib/acme_npu/*.cc
  )
  list(APPEND RUNTIME_SRCS ${RUNTIME_ACME_NPU_SRCS})
endif()
```

编译器版通常同时需要代码生成与运行时创建函数；仅部署版只带运行时。CI 应分别构建两种配置。

## 16.9 测试

1. 注册函数存在性：`tvm.get_global_func("relax.ext.acme_npu", True)`；
2. 一个组合函数生成一个带预期 type key 的 Module；
3. 同一输入多次编译产物散列值稳定；
4. 属性和常量正确进入产物；
5. 非法尺寸、数据类型、对齐和 ABI 得到明确错误；
6. 导出后在新进程加载；
7. 调试产物能从命令序号回到 Relax 节点；
8. 仅运行时构建不包含编译器依赖。

## 16.10 官方依据

- [External Library Dispatch](https://tvm.apache.org/docs/arch/external_library_dispatch.html)
- [Code Generation](https://tvm.apache.org/docs/arch/codegen.html)
- [Example NPU 代码生成](https://github.com/apache/tvm/blob/v0.24.0/src/relax/backend/contrib/example_npu/codegen.cc)
- [Example NPU CMake](https://github.com/apache/tvm/blob/v0.24.0/cmake/modules/contrib/ExampleNPU.cmake)
