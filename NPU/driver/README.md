# NPU C 软件驱动库

该目录提供不依赖操作系统的 C11 驱动库。上层 Runtime 负责准备模型数据，
平台适配层负责寄存器访问、Generic Core 指令请求和缓存维护，驱动库负责统一
CMD128、Descriptor、提交、查询、等待和事件处理。

## 文件

| 文件 | 说明 |
|---|---|
| `include/npu_driver.h` | 稳定的公共 API、寄存器地址、CMD128 和 Descriptor 类型 |
| `src/npu_driver_command.c` | Event/CMD128 编解码和两拍提交 |
| `src/npu_driver_descriptor.c` | Descriptor 公共/DMA/Matrix 编码和 Descriptor 池 |
| `src/npu_driver_device.c` | 驱动初始化、MMIO、Core、IRQ 和故障控制 |
| `src/npu_driver_runtime.c` | QUERY、WAIT、轮询、ACK 和 FENCE |
| `src/npu_driver_memory.c` | 缓存同步、内存屏障和小端字段写入 |
| `src/npu_driver_internal.h` | 仅供上述实现共享的私有定义，不属于公共 API |
| `tests/test_npu_driver.c` | 无设备依赖的假平台测试 |
| `examples/build_int16_gemm.c` | 创建 INT16 GEMM Descriptor 和 CMD128 |
| `Makefile` | 静态库、测试和示例构建 |

实现按职责分为独立编译单元，静态库中不会再链接旧的单文件实现。
现有应用仍只需包含 `npu_driver.h`，函数名、类型和常量保持兼容；应用不应包含
`src/npu_driver_internal.h`。

## 构建与测试

```bash
cd "/home/yusen/Obsidian Vault/NPU/driver"
make clean
make test
make example
make regress
```

输出静态库为 `build/libnpu_driver.a`。应用程序包含
`include/npu_driver.h` 并链接该静态库即可。

`make regress` 分别用 GCC 和 Clang 运行普通测试，并分别用两种编译器运行
ASan+UBSan 测试。回归覆盖 CMD128、Descriptor 池和编码、INT4/INT8/INT32/
INT16 及其线性/分块打包配置、MMIO、提交、QUERY/WAIT/ACK/FENCE、缓存同步和
小端写入。单独的目标为 `test-gcc`、`test-clang`、
`test-sanitize-gcc` 和 `test-sanitize-clang`。

## 平台适配接口

`npu_drv_platform_ops_t` 不假定 Linux、裸机或某一种 Generic Core：

- `mmio_read64/mmio_write64`：64-bit LSC 寄存器访问；
- `submit_beat`：完成一拍 CMD ready/valid 传送；
- `submit_response`：取得 CFE 接收结果；
- `control_request`：执行 WAIT、QUERY 或 FENCE；
- `write_barrier/read_barrier`：设备内存次序控制；
- `cache_clean/cache_invalidate`：非一致缓存系统的数据维护；
- `relax`：轮询时给平台提供等待、让出 CPU 或低功耗提示。

`npu_drv_submit()` 固定先调用：

```text
submit_beat(command.lo,  first=1, last=0)
submit_beat(command.hi,  first=0, last=1)
submit_response(...)
```

平台回调只有在对应 ready/valid 传送结束后才能返回 0。第二拍失败会使 CFE 留在
等待高拍的状态，平台适配层此时应执行设备规定的恢复流程。

输入、权重和 Descriptor 交给设备前可调用 `npu_drv_sync_for_device()`；任务结束
后，CPU 读取输出前调用 `npu_drv_sync_for_cpu()`。在一致缓存系统中，平台可把
缓存回调留空，但仍应提供适合本平台的内存次序函数。

## 常用调用次序

```c
npu_drv_platform_ops_t ops = platform_operations();
npu_driver_t driver;
npu_drv_init(&driver, &ops);

npu_drv_set_base(&driver, NPU_DRV_REG_INPUT_BASE, input_base);
npu_drv_set_base(&driver, NPU_DRV_REG_WEIGHT_BASE, weight_base);
npu_drv_set_timeout(&driver, 1, 100000);
npu_drv_irq_enable(&driver, NPU_DRV_IRQ_DONE | NPU_DRV_IRQ_ERROR);
npu_drv_start(&driver);
```

然后建立 Descriptor：

```c
_Alignas(64) unsigned char memory[4096];
npu_drv_desc_pool_t pool;
npu_drv_desc_allocation_t allocation;

npu_drv_desc_pool_init(&pool, memory, descriptor_device_base, sizeof(memory));
npu_drv_desc_alloc(&pool, NPU_DRV_DESC_MATRIX, &allocation);
npu_drv_desc_matrix_encode(
    allocation.cpu_address, allocation.bytes, &common, &matrix);
```

Descriptor 池同时保存 CPU 地址和设备地址。每次分配按照 64B 对齐，并根据类型
返回 64B、192B 或 256B。`npu_drv_desc_common_encode()` 写入公共 64B 前缀；
DMA 和 Matrix 具有专用编码函数。Vector、Complex 或后续字段可使用
`npu_drv_desc_write_u8/u16/u32/u64()` 写入，它们采用小端字节序并检查写入范围。

提交与等待：

```c
npu_drv_submit_result_t accepted;
npu_drv_task_status_t terminal;

npu_drv_submit(
    &driver, &command, allocation.cpu_address, allocation.bytes, &accepted);
npu_drv_wait_task(&driver, command_id, 100000, &terminal);
if (terminal.status == 0) {
    /* output is ready */
}
npu_drv_ack_task(&driver, command_id);
```

`wait_task` 的第三个参数是最大轮询次数，不是硬件周期数。若希望由硬件等待事件，
使用 `npu_drv_wait_event()` 并填写 `max_cycles`。

## INT16 说明

`NPU_DRV_DTYPE_INT16` 的编码值为 3。驱动会把四个张量数据类型写入
Descriptor 的 `numeric_cfg`。INT16 输入和权重适合对数值误差较敏感的回归
模型；偏置和乘加中间值仍建议使用 INT32 或更宽的内部保存形式，最后再按缩放
参数、舍入模式和饱和模式写回 INT16。

驱动只负责字段生成和设备访问，不会自行改变权重数值。权重缩放参数应由模型
编译器生成，并与运行时加载的权重文件保持一致。
