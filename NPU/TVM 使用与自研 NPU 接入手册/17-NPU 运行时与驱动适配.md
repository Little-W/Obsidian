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

# 17. NPU 运行时与驱动适配

> [!abstract] 本章内容
> 本章从 runtime.Module 的角度说明模块创建、常量初始化、输入输出绑定、设备内存、命令提交、事件同步、序列化和错误处理。BYOC 首版通常不需要实现完整 DeviceAPI，但仍需一个可靠的 NPU Runtime Module。

## 17.1 运行时的责任

运行时接收已经编译的外部函数产物，不再决定复杂图优化。它主要负责：

1. 检查产物格式与设备兼容性；
2. 加载常量与命令；
3. 为每次调用绑定实际 Tensor；
4. 分配或复用设备工作区；
5. 处理主机与设备的数据复制；
6. 进行地址重定位；
7. 提交命令并取得事件；
8. 等待、查询或回收事件；
9. 把设备错误转换成 TVM 可见错误；
10. 保存与恢复模块状态。

> [!important] 编译期与运行期分工
> tile、组合运算、静态工作区布局和命令结构尽量在编译期决定；实际地址、设备编号、队列、事件与本次输入尺寸在运行期决定。若运行时重新做大型图优化，产物将难以复现。

## 17.2 Module 骨架

```cpp
class AcmeNPURuntimeNode final : public tvm::runtime::ModuleNode {
 public:
  const char* type_key() const final { return "acme_npu"; }

  ffi::Function GetFunction(
      const ffi::String& name,
      const ffi::ObjectPtr<ffi::Object>& self) final {
    if (name == symbol_) {
      return ffi::Function::FromPacked(
          [sptr_to_self = ffi::GetRef<ffi::Module>(this)]
          (ffi::PackedArgs args, ffi::Any* rv) {
            auto* node =
                static_cast<AcmeNPURuntimeNode*>(sptr_to_self.operator->());
            node->Run(args);
          });
    }
    return nullptr;
  }

  void SaveToBinary(dmlc::Stream* stream) final {
    stream->Write(symbol_);
    stream->Write(artifact_);
    stream->Write(metadata_);
  }

 private:
  void Run(ffi::PackedArgs args);
  ffi::String symbol_;
  std::string artifact_;
  std::string metadata_;
};
```

具体基类与签名应以 v0.24.0 当前头文件和相邻模块为准。若采用 JSON 图，可继承 `JSONRuntimeBase`；若产物已经是设备命令，直接实现 ModuleNode 往往更清楚。

## 17.3 初始化

初始化分为模块级与设备级：

- 模块级：解析元数据、校验 magic、版本、函数目录、常量目录和命令段；
- 设备级：打开设备、取得能力、创建上下文、队列或流；
- 常量级：分配设备内存、执行预重排或上传已重排权重；
- 缓存级：建立权重与命令缓存，记录引用计数。

初始化应支持重复调用或明确拒绝重复调用。失败后必须释放已经取得的资源，不能留下半初始化对象。

## 17.4 Tensor 绑定

每次调用先核对：

| 检查项 | 说明 |
| --- | --- |
| 参数数量 | 与外部函数 ABI 一致 |
| dtype | 与编译产物一致，或允许的动态集合 |
| ndim | 与描述一致 |
| shape | 静态值一致，动态值在范围内 |
| strides | 连续要求或明确支持的非连续步长 |
| byte_offset | 设备是否支持带偏移 Tensor |
| device | 主机、NPU 或共享内存 |
| alignment | 基地址与每行步长 |
| 可写性 | 输出与原地写约束 |

若输入在主机内存，运行时可以分配设备缓冲区并复制；若输入已经在 NPU 内存，直接绑定可避免往返复制。两种情况必须在日志与性能统计中区分。

## 17.5 设备内存

推荐把内存分成四类：

1. 常量内存：模块生命周期内保持；
2. 输入输出内存：调用方拥有或运行时暂时创建；
3. 工作区：外部函数调用期间使用，可由内存池复用；
4. 命令与描述符内存：通常只读，可跨调用复用。

内存池按设备、对齐和用途分组。异步调用完成之前，不得回收仍被设备使用的缓冲区。若运行时允许并发，同一模块的可变工作区不能被两个调用同时覆盖。

## 17.6 提交与事件

```mermaid
sequenceDiagram
    participant VM as Relax VM
    participant RT as NPU Runtime
    participant D as Driver
    participant F as Firmware
    VM->>RT: external_func(inputs, outputs)
    RT->>RT: 校验与重定位
    RT->>D: submit(queue, commands)
    D->>F: doorbell
    F-->>D: event complete / error
    D-->>RT: wait or query
    RT-->>VM: return
```

同步调用可以在函数返回前等待事件。异步调用应把事件与输入输出生命周期绑定，并提供后续同步点。不要仅依赖全设备同步，这会破坏不同队列间的并行。

## 17.7 缓存一致性

非一致性 SoC 需要明确：

- CPU 写入输入后由谁 clean；
- NPU 写入输出后由谁 invalidate；
- 命令缓冲区何时可见；
- 设备写完成与中断到达的先后保证；
- 地址是物理地址、IOVA 还是设备虚拟地址；
- scatter-gather 是否被硬件支持。

这些规则属于驱动 ABI，不能由每个算子自行处理。错误的缓存维护常表现为输入相关的偶发数值错误。

## 17.8 错误与恢复

推荐错误对象包含：

```text
stage           = submit | execute | wait | copy | load
host_code       = 统一软件错误码
driver_code     = ioctl 或 SDK 返回码
device_code     = 固件错误码
function        = 外部函数符号
submission_id   = 提交序号
command_index   = 首个失败命令
engine          = DMA | Matrix | Vector | CME
detail          = 可读说明
recoverable     = true | false
```

可恢复错误可以终止当前调用并保留设备；不可恢复错误应停止新提交、收集状态、复位设备、清空失效事件与内存，再允许上层重新加载模块。复位后不能继续使用复位前的设备地址和事件。

## 17.9 模块保存与加载

`export_library` 会把被导入模块一并打包。自定义 Module 若需要在加载后恢复命令和元数据，必须实现二进制保存，并注册：

```cpp
TVM_FFI_STATIC_INIT_BLOCK() {
  namespace refl = tvm::ffi::reflection;
  refl::GlobalDef()
      .def("runtime.AcmeNPURuntimeCreate", AcmeNPURuntimeCreate)
      .def("ffi.Module.load_from_bytes.acme_npu",
           AcmeNPURuntimeLoadFromBytes);
}
```

type key、加载注册名与模块返回值必须一致。测试应在另一个进程加载共享库，防止全局对象残留掩盖缺失注册。

## 17.10 多线程与多设备

- 设备上下文按 device id 区分；
- 模块不可变部分可共享；
- 每次调用状态独立；
- 队列选择有明确策略；
- 常量缓存使用线程安全引用计数；
- 设备复位只影响对应设备；
- 错误日志包含线程、队列和提交序号。

## 17.11 运行时最小测试

1. 创建与销毁模块一万次无泄漏；
2. 常量初始化成功与失败均可清理；
3. 零长度、最小尺寸、最大允许尺寸；
4. 输入输出地址未对齐；
5. 驱动返回忙、超时、非法命令和设备复位；
6. 两线程调用同一模块；
7. 两个设备并行；
8. 导出、进程退出、重新加载；
9. 连续运行后结果不受上一次工作区残留影响；
10. 运行时仅构建配置可以独立链接。

## 17.12 官方依据

- [TVM Runtime System](https://tvm.apache.org/docs/arch/runtime.html)
- [Module Serialization](https://tvm.apache.org/docs/arch/introduction_to_module_serialization.html)
- [Example NPU runtime](https://github.com/apache/tvm/blob/v0.24.0/src/runtime/contrib/example_npu/example_npu_runtime.cc)
- [Relax VM](https://tvm.apache.org/docs/arch/relax_vm.html)
