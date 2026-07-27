#ifndef NPU_DRIVER_H
#define NPU_DRIVER_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_DRV_CMD128_BYTES 16u
#define NPU_DRV_CMD128_BEATS 2u
#define NPU_DRV_EVENT_NONE UINT8_C(0xff)
#define NPU_DRV_MAX_EVENT_ID UINT8_C(0xfe)
#define NPU_DRV_MAX_COMMAND_ID UINT16_C(0x07ff)
#define NPU_DRV_FULL_WSTRB UINT8_C(0xff)
#define NPU_DRV_PAYLOAD_HI_MASK UINT16_C(0xffff)

#define NPU_DRV_HEADER_IRQ_SUCCESS UINT8_C(0x08)
#define NPU_DRV_HEADER_IRQ_ERROR UINT8_C(0x04)
#define NPU_DRV_HEADER_STRICT_NUMERIC UINT8_C(0x02)
#define NPU_DRV_HEADER_ORDERED UINT8_C(0x01)
#define NPU_DRV_HEADER_FLAGS_MASK UINT8_C(0x0f)

/*
 * Offsets are relative to the NPU AXI Slave base address. Command FIFO
 * writes use AWSIZE=3, AWBURST=FIXED, and WSTRB=0xff. AWADDR remains at
 * NPU_DRV_CMD_FIFO_DATA for all beats in one burst.
 */
#define NPU_DRV_CMD_FIFO_DATA UINT32_C(0x020000)
#define NPU_DRV_CMD_RSP_FIFO UINT32_C(0x020008)
#define NPU_DRV_CMD_FIFO_STATUS UINT32_C(0x020010)
#define NPU_DRV_CMD_FIFO_MIN_BURST_BEATS 2u
#define NPU_DRV_CMD_FIFO_MAX_BURST_BEATS 16u
#define NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS 8u
#define NPU_DRV_NO_FAILED_COMMAND SIZE_MAX

/* Local System Controller register offsets on the 64-bit system bus. */
#define NPU_DRV_REG_NPU_VERSION UINT32_C(0x0000)
#define NPU_DRV_REG_ISA_FEATURE UINT32_C(0x0008)
#define NPU_DRV_REG_BUS_CONFIG UINT32_C(0x0010)
#define NPU_DRV_REG_L1_CONFIG UINT32_C(0x0018)
#define NPU_DRV_REG_MATRIX_CONFIG UINT32_C(0x0020)
#define NPU_DRV_REG_VECTOR_CONFIG UINT32_C(0x0028)
#define NPU_DRV_REG_CME_CONFIG UINT32_C(0x0030)
#define NPU_DRV_REG_CORE_CONTROL UINT32_C(0x0040)
#define NPU_DRV_REG_CORE_STATUS UINT32_C(0x0048)
#define NPU_DRV_REG_PC_BASE UINT32_C(0x0050)
#define NPU_DRV_REG_INPUT_BASE UINT32_C(0x0058)
#define NPU_DRV_REG_WEIGHT_BASE UINT32_C(0x0060)
#define NPU_DRV_REG_WORK_BASE UINT32_C(0x0068)
#define NPU_DRV_REG_OUTPUT_BASE UINT32_C(0x0070)
#define NPU_DRV_REG_KV_BASE UINT32_C(0x0078)
#define NPU_DRV_REG_DDR_LOCAL_BASE UINT32_C(0x0080)
#define NPU_DRV_REG_DDR_LOCAL_LIMIT UINT32_C(0x0088)
#define NPU_DRV_REG_TBU_STREAM_ID UINT32_C(0x0090)
#define NPU_DRV_REG_IRQ_STATUS UINT32_C(0x00a0)
#define NPU_DRV_REG_IRQ_MASK UINT32_C(0x00a8)
#define NPU_DRV_REG_FAULT_CMD UINT32_C(0x00b0)
#define NPU_DRV_REG_FAULT_ADDR UINT32_C(0x00b8)
#define NPU_DRV_REG_FAULT_INFO UINT32_C(0x00c0)
#define NPU_DRV_REG_FAULT_CLEAR UINT32_C(0x00c8)
#define NPU_DRV_REG_PARAM_L1_BASE UINT32_C(0x00d0)
#define NPU_DRV_REG_PARAM_L1_LIMIT UINT32_C(0x00d8)
#define NPU_DRV_REG_PARAM_LOCK UINT32_C(0x00e0)
#define NPU_DRV_REG_RESET_REASON UINT32_C(0x00e8)
#define NPU_DRV_REG_FAULT_DETAIL UINT32_C(0x00f8)
#define NPU_DRV_REG_PERF_BASE UINT32_C(0x0100)
#define NPU_DRV_REG_PERF_CONTROL UINT32_C(0x0180)
#define NPU_DRV_REG_TIMEOUT_BASE UINT32_C(0x0200)

#define NPU_DRV_CORE_START UINT64_C(0x1)
#define NPU_DRV_CORE_STOP UINT64_C(0x2)
#define NPU_DRV_CORE_SOFT_RESET UINT64_C(0x4)
#define NPU_DRV_IRQ_DONE UINT64_C(0x1)
#define NPU_DRV_IRQ_EXCEPTION UINT64_C(0x2)
#define NPU_DRV_IRQ_ERROR UINT64_C(0x4)
#define NPU_DRV_IRQ_ALL UINT64_C(0x7)

#define NPU_DRV_CTL_WAIT UINT8_C(0x01)
#define NPU_DRV_CTL_QUERY UINT8_C(0x02)
#define NPU_DRV_CTL_FENCE UINT8_C(0x03)
#define NPU_DRV_FENCE_DMA UINT8_C(0x01)
#define NPU_DRV_FENCE_MATRIX UINT8_C(0x02)
#define NPU_DRV_FENCE_VECTOR UINT8_C(0x04)
#define NPU_DRV_FENCE_COMPLEX UINT8_C(0x08)
#define NPU_DRV_FENCE_ALL_ENGINES UINT8_C(0x0f)
#define NPU_DRV_QUERY_STATUS UINT8_C(0)
#define NPU_DRV_QUERY_TAG_EVENT UINT8_C(1)
#define NPU_DRV_QUERY_FAULT_ADDR UINT8_C(2)
#define NPU_DRV_QUERY_PROGRESS UINT8_C(3)
#define NPU_DRV_QUERY_ACK UINT8_C(4)
#define NPU_DRV_QUERY_ERROR_INFO UINT8_C(5)
#define NPU_DRV_QUERY_DONE_FLAGS UINT8_C(6)

typedef enum {
    NPU_DRV_OK = 0,
    NPU_DRV_EINVAL = -1,
    NPU_DRV_ERANGE = -2,
    NPU_DRV_ENOMEM = -3,
    NPU_DRV_EIO = -4,
    NPU_DRV_ETIMEOUT = -5,
    NPU_DRV_EDEVICE = -6,
    NPU_DRV_ENOTSUP = -7
} npu_drv_rc_t;

typedef enum {
    NPU_DRV_DTYPE_INT4 = 0,
    NPU_DRV_DTYPE_INT8 = 1,
    NPU_DRV_DTYPE_INT32 = 2,
    NPU_DRV_DTYPE_INT16 = 3
} npu_drv_dtype_t;

typedef enum {
    NPU_DRV_OPCODE_NOP = 0,
    NPU_DRV_OPCODE_EVENT_SIGNAL = 1,
    NPU_DRV_OPCODE_EVENT_REARM = 2,
    NPU_DRV_OPCODE_EVENT_JOIN = 3,
    NPU_DRV_OPCODE_GLOBAL_FENCE = 4,
    NPU_DRV_OPCODE_DMA_COPY_1D = 5,
    NPU_DRV_OPCODE_DMA_COPY_ND = 6,
    NPU_DRV_OPCODE_DMA_FILL = 7,
    NPU_DRV_OPCODE_DMA_TRANSPOSE_2D = 8,
    NPU_DRV_OPCODE_DMA_PACK = 9,
    NPU_DRV_OPCODE_DMA_SPLIT = 10,
    NPU_DRV_OPCODE_MATRIX_GEMM = 11,
    NPU_DRV_OPCODE_MATRIX_BMM = 12,
    NPU_DRV_OPCODE_MATRIX_GEMM_ACCUM = 13,
    NPU_DRV_OPCODE_MATRIX_GEMM_ZERO = 14,
    NPU_DRV_OPCODE_VECTOR_ADD = 15,
    NPU_DRV_OPCODE_VECTOR_SUB = 16,
    NPU_DRV_OPCODE_VECTOR_MUL = 17,
    NPU_DRV_OPCODE_VECTOR_FMA = 18,
    NPU_DRV_OPCODE_VECTOR_MAX = 19,
    NPU_DRV_OPCODE_VECTOR_MIN = 20,
    NPU_DRV_OPCODE_VECTOR_CMP = 21,
    NPU_DRV_OPCODE_VECTOR_SELECT = 22,
    NPU_DRV_OPCODE_VECTOR_CLAMP = 23,
    NPU_DRV_OPCODE_VECTOR_RELU = 24,
    NPU_DRV_OPCODE_COMPLEX_ACT = 25,
    NPU_DRV_OPCODE_COMPLEX_SOFTMAX = 26,
    NPU_DRV_OPCODE_COMPLEX_NORM = 27,
    NPU_DRV_OPCODE_COMPLEX_ROPE = 28,
    NPU_DRV_OPCODE_COMPLEX_STAT = 29,
    NPU_DRV_OPCODE_COMPLEX_RECIP = 30,
    NPU_DRV_OPCODE_COMPLEX_ADD_RESCALE = 31
} npu_drv_opcode_t;

typedef enum {
    NPU_DRV_TASK_FREE = 0,
    NPU_DRV_TASK_WAITING = 1,
    NPU_DRV_TASK_RUNNING = 2,
    NPU_DRV_TASK_TERMINAL = 3
} npu_drv_task_state_t;

typedef struct {
    uint8_t id;
} npu_drv_event_t;

typedef struct {
    uint64_t lo;
    uint16_t hi;
} npu_drv_payload80_t;

typedef struct {
    uint64_t lo;
    uint64_t hi;
} npu_drv_cmd128_t;

typedef struct {
    npu_drv_payload80_t payload;
    uint16_t command_id;
    npu_drv_opcode_t opcode;
    npu_drv_dtype_t dtype;
    uint8_t timeout_class;
    uint8_t header_flags;
    npu_drv_event_t wait_event[2];
    npu_drv_event_t signal_event;
} npu_drv_cmd_fields_t;

typedef struct {
    uint16_t command_id;
    uint8_t status;
    uint8_t fifo_free;
    uint64_t raw;
} npu_drv_submit_result_t;

typedef struct {
    size_t responses_received;
    size_t first_failed_index;
    uint8_t burst_completed;
} npu_drv_submit_batch_result_t;

typedef struct {
    uint8_t state;
    uint8_t status;
    uint16_t command_id;
    uint64_t raw;
} npu_drv_task_status_t;

typedef struct {
    uint8_t state;
    uint16_t producer_command_id;
    uint64_t raw;
} npu_drv_event_result_t;

/*
 * The external host CPU is the AXI Master. Command FIFO, control registers,
 * and L1BUF are AXI Slave targets. Each command uses two adjacent 64-bit
 * beats in low-word then high-word order.
 */
typedef struct {
    void *context;
    int (*mmio_read64)(void *context, uint32_t offset, uint64_t *value);
    int (*mmio_write64)(void *context,
                        uint32_t offset,
                        uint64_t value,
                        uint8_t strobe);
    int (*submit_fixed_burst)(void *context,
                              uint32_t fifo_offset,
                              const uint64_t *beats,
                              size_t beat_count);
    int (*submit_response)(void *context, uint64_t *value);
    int (*control_request)(void *context,
                           uint8_t operation,
                           uint64_t rs1,
                           uint64_t rs2,
                           uint64_t *rd);
    void (*write_barrier)(void *context);
    void (*read_barrier)(void *context);
    void (*cache_clean)(void *context, const void *address, size_t bytes);
    void (*cache_invalidate)(void *context, void *address, size_t bytes);
    void (*relax)(void *context);
} npu_drv_platform_ops_t;

typedef struct {
    npu_drv_platform_ops_t ops;
} npu_driver_t;

int npu_drv_event_encode(npu_drv_event_t event, uint8_t *encoded);
int npu_drv_event_decode(uint8_t encoded, npu_drv_event_t *event);
int npu_drv_payload_field_set(npu_drv_payload80_t *payload,
                              uint8_t lsb,
                              uint8_t width,
                              uint64_t value);
int npu_drv_aref_encode(uint8_t ddr_space,
                        uint8_t base_select,
                        uint32_t byte_offset,
                        uint32_t *encoded);
int npu_drv_lref_encode(uint32_t byte_address,
                        uint8_t unit_shift,
                        uint8_t width,
                        uint16_t *encoded);
int npu_drv_matrix_gemm_payload_encode(
    uint16_t a_ref,
    npu_drv_dtype_t a_dtype,
    uint16_t b_ref,
    npu_drv_dtype_t b_dtype,
    uint16_t c_ref,
    npu_drv_dtype_t c_dtype,
    uint16_t bias_ref,
    uint8_t m,
    uint8_t n,
    uint8_t k,
    uint8_t requant_shift,
    npu_drv_payload80_t *payload);
int npu_drv_matrix_bmm_payload_encode(
    uint16_t a_ref,
    npu_drv_dtype_t a_dtype,
    uint16_t b_ref,
    npu_drv_dtype_t b_dtype,
    uint16_t c_ref,
    npu_drv_dtype_t c_dtype,
    uint8_t batch_count,
    uint8_t m,
    uint8_t n,
    uint8_t k,
    uint8_t requant_shift,
    npu_drv_payload80_t *payload);
int npu_drv_cmd128_encode(const npu_drv_cmd_fields_t *fields,
                          npu_drv_cmd128_t *command);
int npu_drv_cmd128_decode(const npu_drv_cmd128_t *command,
                          npu_drv_cmd_fields_t *fields);

int npu_drv_init(npu_driver_t *driver,
                 const npu_drv_platform_ops_t *operations);
int npu_drv_reg_read(npu_driver_t *driver,
                     uint32_t offset,
                     uint64_t *value);
int npu_drv_reg_write(npu_driver_t *driver,
                      uint32_t offset,
                      uint64_t value);
int npu_drv_set_timeout(npu_driver_t *driver,
                        uint8_t timeout_class,
                        uint32_t cycles);
int npu_drv_set_base(npu_driver_t *driver,
                     uint32_t register_offset,
                     uint64_t address);
int npu_drv_start(npu_driver_t *driver);
int npu_drv_stop(npu_driver_t *driver);
int npu_drv_soft_reset(npu_driver_t *driver);
int npu_drv_irq_enable(npu_driver_t *driver, uint64_t mask);
int npu_drv_irq_ack(npu_driver_t *driver, uint64_t mask);
int npu_drv_fault_clear(npu_driver_t *driver);
int npu_drv_sync_for_device(npu_driver_t *driver,
                            const void *address,
                            size_t bytes);
int npu_drv_sync_for_cpu(npu_driver_t *driver,
                         void *address,
                         size_t bytes);

int npu_drv_submit(npu_driver_t *driver,
                   const npu_drv_cmd128_t *command,
                   npu_drv_submit_result_t *result);
int npu_drv_submit_batch(
    npu_driver_t *driver,
    const npu_drv_cmd128_t *commands,
    size_t command_count,
    npu_drv_submit_result_t *results,
    npu_drv_submit_batch_result_t *batch_result);
int npu_drv_query_raw(npu_driver_t *driver,
                      uint16_t command_id,
                      uint8_t selector,
                      uint64_t *value);
int npu_drv_query_status(npu_driver_t *driver,
                         uint16_t command_id,
                         npu_drv_task_status_t *status);
int npu_drv_wait_task(npu_driver_t *driver,
                      uint16_t command_id,
                      uint32_t poll_limit,
                      npu_drv_task_status_t *status);
int npu_drv_ack_task(npu_driver_t *driver, uint16_t command_id);
int npu_drv_wait_event(npu_driver_t *driver,
                       npu_drv_event_t event,
                       uint32_t max_cycles,
                       npu_drv_event_result_t *result);
int npu_drv_fence_mask(npu_driver_t *driver,
                       uint8_t engine_mask,
                       uint32_t max_cycles,
                       uint64_t *raw);
int npu_drv_fence(npu_driver_t *driver, uint32_t max_cycles, uint64_t *raw);

#ifdef __cplusplus
}
#endif

#endif /* NPU_DRIVER_H */
