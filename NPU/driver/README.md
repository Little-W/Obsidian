# NPU C 驱动库

本目录提供单核 NPU 的 C11 驱动。主控 CPU 作为 AXI Master，通过 NPU 的 AXI Slave 寄存器窗口配置设备，并把 CMD128 写入固定地址的命令 FIFO。NPU 发起 AXI Master 请求访问系统内存。

CMD128 inline V2 已把执行参数放入指令本身。驱动不再分配、填写、同步或提交外部 Descriptor。

## 1. 文件划分

| 文件 | 作用 |
|---|---|
| `include/npu_driver.h` | 公共类型、寄存器、指令字段和函数声明 |
| `src/npu_driver_command.c` | 80-bit payload、CMD128 编解码和 FIFO 提交 |
| `src/npu_driver_device.c` | 初始化、寄存器、启动、停止、中断和故障处理 |
| `src/npu_driver_memory.c` | 权重、输入和输出的 cache 同步 |
| `src/npu_driver_runtime.c` | 查询、等待、确认任务和 engine fence |

## 2. 指令提交接口

单条指令：

```c
npu_drv_submit_result_t result;
int rc = npu_drv_submit(&driver, &command, &result);
```

批量指令：

```c
npu_drv_submit_result_t results[8];
npu_drv_submit_batch_result_t summary;

int rc = npu_drv_submit_batch(
    &driver,
    commands,
    command_count,
    results,
    &summary);
```

一次批量提交包含 1～8 条 CMD128，对应 2～16 个 64-bit beat。平台回调必须满足：

- `AWADDR` 保持为 `NPU_DRV_CMD_FIFO_DATA`；
- `AWBURST=FIXED`；
- `AWSIZE=3`；
- 每条指令先写 low word，再写 high word；
- 只在本次 burst 的最后一个 beat 置 `WLAST`；
- 每个 beat 保持有效，直到 ready/valid 传输完成；
- 等待并检查 AXI 写响应。

驱动在发送命令前调用 `write_barrier`，但不会清理 Descriptor cache。权重和输入仍需在 CPU 修改后调用 `npu_drv_sync_for_device()`；输出由 NPU 写回后，CPU 读取前调用 `npu_drv_sync_for_cpu()`。

## 3. CMD128 字段

`npu_drv_cmd_fields_t` 包含：

```c
typedef struct {
    npu_drv_payload80_t payload;
    uint16_t command_id;
    npu_drv_compact_opcode_t compact_opcode;
    npu_drv_dtype_t dtype;
    uint8_t timeout_class;
    uint8_t header_flags;
    npu_drv_event_t wait_event[2];
    npu_drv_event_t signal_event;
} npu_drv_cmd_fields_t;
```

公共 bit 分配为：

| bit | C 字段 |
|---:|---|
| 127 | 编码函数固定写 1 |
| 126:122 | `compact_opcode` |
| 121:112 | `command_id` |
| 111:104 | `wait_event[0].id` |
| 103:96 | `wait_event[1].id` |
| 95:88 | `signal_event.id` |
| 87:84 | `header_flags` |
| 83:82 | `timeout_class` |
| 81:80 | `dtype` |
| 79:0 | `payload` |

header flag 宏如下：

```c
NPU_DRV_HEADER_IRQ_SUCCESS
NPU_DRV_HEADER_IRQ_ERROR
NPU_DRV_HEADER_STRICT_NUMERIC
NPU_DRV_HEADER_ORDERED
```

`npu_drv_cmd128_encode()` 检查 command ID、操作码、数据类型、超时组、事件 ID 和 signal/wait 冲突。`npu_drv_cmd128_decode()` 进行反向检查，并允许 0～31 的完整 5-bit 操作码范围。

## 4. 事件

V2 事件字段只有 ID：

```c
npu_drv_event_t event = {.id = 7u};
```

`0x00～0xFE` 是有效 ID，`NPU_DRV_EVENT_NONE` 等于 `0xFF`。

`EVENT_REARM` 的待重置 ID 放在 `signal_event.id` 中，两个 wait event 都使用 `NPU_DRV_EVENT_NONE`。generation 由 Event Table 在 NPU 内部记录并更新，软件不把 generation 写进指令。

## 5. payload 辅助函数

### 5.1 写入位段

```c
npu_drv_payload80_t payload = {0u, 0u};

int rc = npu_drv_payload_field_set(
    &payload,
    66u,   /* lsb */
    14u,   /* width */
    a_ref);
```

函数检查 80-bit 范围、数值宽度和重复写入。模型部署通常直接使用编译器生成的 CMD128 数组；手写测试可用此函数逐段构造 payload。

### 5.2 AREF28

```c
uint32_t src;
npu_drv_aref_encode(
    1u,        /* 系统内存 */
    2u,        /* weight base */
    0x400u,    /* byte offset */
    &src);
```

系统地址的 `base_select` 允许 0～5；L1 地址必须使用 0。byte offset 为 24 bit。

### 5.3 LREF

矩阵地址：

```c
uint16_t a_ref;
npu_drv_lref_encode(
    0x1000u,   /* L1 byte address */
    6u,        /* 64-byte unit */
    14u,
    &a_ref);
```

向量和复杂数学单元把 `unit_shift` 设为 4，字段宽度设为 16。函数检查地址对齐和字段容量。

## 6. GEMM 构造示例

`examples/build_int8_gemm.c` 和 `examples/build_int16_gemm.c` 展示以下过程：

1. 将 A、B、C 的 L1 地址压缩为 LREF14；
2. 调用 `npu_drv_matrix_gemm_payload_encode()` 写入三个地址、M、N、K、
   偏置引用、C 数据类型和 5-bit `requant_shift`；
3. 设置 command ID、GEMM 操作码、A 数据类型和事件 ID；
4. 编码为 low/high 两个 64-bit word。

GEMM 的低 42 bit 为：

```text
[37:26] bias_lref12
[25:20] M-1
[19:14] N-1
[13:8]  K-1
[7]     b_int4
[6:5]   C dtype
[4:0]   requant_shift
```

`npu_drv_matrix_bmm_payload_encode()` 使用 BMM 的 batch 和尺寸位段。两个
函数都会检查 1～64 的尺寸、0～31 的 shift、INT32 输出必须使用 shift 0，
以及 B 的数据类型。A 为 INT8 时可以配合 INT4 B，此时函数自动写入
`b_int4=1`；其余情况要求 A 与 B 的数据类型相同。偏置引用使用 LREF12，
数值 0 表示没有偏置。

INT8 示例使用 `requant_shift=5`，可以直接处理 Q5 数据；INT16 示例使用
`requant_shift=8`。

## 7. 编译器生成 C 包的使用

以 `demo_model_config` 为例：

```c
#include "demo_model.h"
#include "npu_driver.h"

int submit_model(npu_driver_t *driver)
{
    npu_drv_submit_result_t results[8];
    npu_drv_submit_batch_result_t summary;
    npu_drv_task_status_t task_status;
    uint32_t batch_index;

    npu_drv_sync_for_device(
        driver,
        demo_model_config.weights,
        demo_model_config.weight_bytes);

    for (batch_index = 0;
         batch_index < demo_model_config.command_batch_count;
         ++batch_index) {
        const demo_model_command_batch_t *batch =
            &demo_model_config.command_batches[batch_index];
        const demo_model_cmd128_t *commands =
            &demo_model_config.commands[batch->command_id_offset];
        int rc = npu_drv_submit_batch(
            driver,
            (const npu_drv_cmd128_t *)commands,
            batch->command_count,
            results,
            &summary);
        if (rc != NPU_DRV_OK) {
            return rc;
        }
        if (batch->host_sync_after != 0u) {
            uint32_t command_index;
            for (command_index = 0u;
                 command_index < batch->command_count;
                 ++command_index) {
                uint16_t command_id =
                    demo_model_config.batch_command_ids[
                        batch->command_id_offset + command_index];
                rc = npu_drv_wait_task(
                    driver, command_id, 1000000u, &task_status);
                if (rc != NPU_DRV_OK) {
                    return rc;
                }
                rc = npu_drv_ack_task(driver, command_id);
                if (rc != NPU_DRV_OK) {
                    return rc;
                }
            }
        }
    }
    return NPU_DRV_OK;
}
```

生成配置还提供每个输入和输出的 DDR/L1 地址。应用应把输入写到对应 DDR 地址，完成 cache clean 后提交任务；最后一组任务完成后，对输出区域做 cache invalidate 再读取。

批次中的 command ID 当前按编译顺序连续生成，因此 `command_id_offset` 可直接作为指令数组下标。若后续编译器允许非连续 ID，应按 `batch_command_ids` 查找；应用可在构建时增加一致性检查。

`host_sync_before` 表示提交当前批次前，上一批必须已完成并确认；
`host_sync_after` 表示提交后必须等待并确认该批次。编译器为当前所有批次写入
`host_sync_after=1`，并为第一批之后的批次写入
`host_sync_before=1`。`contains_event_rearm=1` 的批次只包含
`EVENT_REARM`，前后两次主机同步用于保证旧事件已经结束、等待者数量为 0，
并保证后续生产者看到已经重置的 Event ID。

## 8. P1 操作码

驱动枚举保留：

```c
NPU_DRV_COMPACT_COMPLEX_ROPE   /* 28 */
NPU_DRV_COMPACT_COMPLEX_RECIP  /* 30 */
```

P1 功能位关闭时，设备会对这两类指令返回 `ILLEGAL_OPCODE`。驱动仍能编码、解码并提交它们。`VSTAT=29`，`VADD_RESCALE=31`。

## 9. 构建与测试

```bash
cd NPU/driver
make clean
make test
make example
```

完整编译器组合：

```bash
make clean
make regress
```

`make regress` 使用 GCC、Clang、AddressSanitizer 和 UndefinedBehaviorSanitizer。编译选项包含 `-Wall -Wextra -Werror -Wpedantic`，警告会使测试失败。
