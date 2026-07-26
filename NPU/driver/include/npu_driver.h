#ifndef NPU_DRIVER_H
#define NPU_DRIVER_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_DRV_CMD128_BYTES 16u
#define NPU_DRV_CMD128_BEATS 2u
#define NPU_DRV_CMD_HEADER_VERSION 1u
#define NPU_DRV_EVENT_NONE UINT16_C(0x0fff)
#define NPU_DRV_MAX_COMMAND_ID UINT16_C(0x0fff)
#define NPU_DRV_FULL_WSTRB UINT8_C(0xff)

/*
 * Offsets are relative to the NPU AXI Slave base address. CMD FIFO writes use
 * AWSIZE=3, AWBURST=FIXED and WSTRB=0xff. AWADDR remains
 * NPU_DRV_CMD_FIFO_DATA for every beat in the burst.
 */
#define NPU_DRV_CMD_FIFO_DATA UINT32_C(0x020000)
#define NPU_DRV_CMD_RSP_FIFO UINT32_C(0x020008)
#define NPU_DRV_CMD_FIFO_STATUS UINT32_C(0x020010)
#define NPU_DRV_CMD_FIFO_MIN_BURST_BEATS 2u
#define NPU_DRV_CMD_FIFO_MAX_BURST_BEATS 16u
#define NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS 8u
#define NPU_DRV_NO_FAILED_COMMAND SIZE_MAX

#define NPU_DRV_CONTROL_DESC_BYTES 64u
#define NPU_DRV_DMA_DESC_BYTES 256u
#define NPU_DRV_MATRIX_DESC_BYTES 256u
#define NPU_DRV_VECTOR_DESC_BYTES 192u
#define NPU_DRV_COMPLEX_DESC_BYTES 256u
#define NPU_DRV_DESC_ALIGNMENT 64u

#define NPU_DRV_PACK_LINEAR_INT8 UINT8_C(0)
#define NPU_DRV_PACK_LINEAR_INT4 UINT8_C(1)
#define NPU_DRV_PACK_TILED_INT8 UINT8_C(2)
#define NPU_DRV_PACK_TILED_INT4 UINT8_C(3)
#define NPU_DRV_PACK_LINEAR_INT32 UINT8_C(4)
#define NPU_DRV_PACK_LINEAR_INT16 UINT8_C(5)
#define NPU_DRV_PACK_TILED_INT16 UINT8_C(6)

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

/*
 * Control requests issued by an external host CPU. On hardware, the platform
 * adapter implements these operations with accesses to the NPU AXI Slave
 * control window. A cycle-model adapter may provide an equivalent callback.
 */
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
    NPU_DRV_ENGINE_CONTROL = 0,
    NPU_DRV_ENGINE_DMA = 1,
    NPU_DRV_ENGINE_MATRIX = 2,
    NPU_DRV_ENGINE_VECTOR = 3,
    NPU_DRV_ENGINE_COMPLEX = 4
} npu_drv_engine_t;

typedef enum {
    NPU_DRV_DTYPE_INT4 = 0,
    NPU_DRV_DTYPE_INT8 = 1,
    NPU_DRV_DTYPE_INT32 = 2,
    NPU_DRV_DTYPE_INT16 = 3
} npu_drv_dtype_t;

typedef enum {
    NPU_DRV_DESC_CONTROL = 0,
    NPU_DRV_DESC_DMA = 1,
    NPU_DRV_DESC_MATRIX = 2,
    NPU_DRV_DESC_VECTOR = 3,
    NPU_DRV_DESC_COMPLEX = 4
} npu_drv_desc_type_t;

typedef enum {
    NPU_DRV_TASK_FREE = 0,
    NPU_DRV_TASK_WAITING = 1,
    NPU_DRV_TASK_RUNNING = 2,
    NPU_DRV_TASK_TERMINAL = 3
} npu_drv_task_state_t;

typedef struct {
    uint8_t id;
    uint8_t generation;
} npu_drv_event_t;

typedef struct {
    uint64_t lo;
    uint64_t hi;
} npu_drv_cmd128_t;

typedef struct {
    uint64_t descriptor_addr;
    uint16_t command_id;
    uint8_t engine;
    uint8_t opcode;
    uint16_t header_flags;
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
    /* Number of responses copied to the caller's results array. */
    size_t responses_received;
    /*
     * First device failure, response mismatch, or unconfirmed command.
     * Equals NPU_DRV_NO_FAILED_COMMAND when every command succeeds.
     */
    size_t first_failed_index;
    /* One means the AXI write response reported a successful burst. */
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
 * Every int-returning callback returns zero on success. The external host CPU
 * is the AXI Master; NPU command, control-register, and L1BUF windows are AXI
 * Slave targets. submit_fixed_burst writes 2..16 64-bit beats to one fixed
 * FIFO address. The beat count is even, and each adjacent pair is one CMD128
 * in low-word then high-word order. The callback must hold each W beat until
 * its ready/valid transfer completes, assert WLAST only on the final beat,
 * wait for the write response, and return zero only for a successful
 * response. submit_response reads and removes one entry from
 * NPU_DRV_CMD_RSP_FIFO. A cycle-model adapter may implement equivalent
 * behavior on a test port.
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

typedef struct {
    uint8_t *cpu_base;
    uint64_t device_base;
    size_t bytes;
    size_t used;
} npu_drv_desc_pool_t;

typedef struct {
    void *cpu_address;
    uint64_t device_address;
    size_t bytes;
} npu_drv_desc_allocation_t;

typedef struct {
    uint8_t desc_version;
    npu_drv_desc_type_t desc_type;
    uint32_t op_flags;
    uint64_t src0_addr;
    uint64_t src1_addr;
    uint64_t src2_addr;
    uint64_t dst_addr;
    uint64_t aux0_addr;
    uint64_t aux1_addr;
    npu_drv_dtype_t src0_dtype;
    npu_drv_dtype_t src1_dtype;
    npu_drv_dtype_t src2_dtype;
    npu_drv_dtype_t dst_dtype;
    uint8_t round_mode;
    uint8_t saturate_enable;
    uint8_t scale_mode;
    uint8_t zero_point_enable;
    uint8_t internal_fp32_enable;
    uint32_t user_tag;
} npu_drv_desc_common_t;

typedef struct {
    uint8_t rank;
    uint8_t src_space;
    uint8_t dst_space;
    uint8_t convert_mode;
    uint8_t burst_beats;
    uint8_t max_outstanding;
    uint8_t src_nibble;
    uint8_t dst_nibble;
    uint32_t shape[5];
    uint32_t src_stride_bytes[5];
    uint32_t dst_stride_bytes[5];
    uint64_t fill_value;
    uint64_t src_region_bytes;
    uint64_t dst_region_bytes;
    uint16_t segment_count;
    uint16_t segment_bytes;
    uint32_t segment_stride;
} npu_drv_dma_fields_t;

typedef struct {
    uint32_t m;
    uint32_t n;
    uint32_t k;
    uint32_t batch_count;
    uint32_t last_tile_valid_m;
    uint32_t last_tile_valid_n;
    uint32_t last_tile_valid_k;
    uint32_t flags;
    uint32_t lda_bytes;
    uint32_t ldb_bytes;
    uint32_t ldc_bytes;
    uint32_t bias_stride_bytes;
    uint64_t a_batch_stride_bytes;
    uint64_t b_batch_stride_bytes;
    uint64_t c_batch_stride_bytes;
    uint64_t src2_batch_stride_bytes;
    uint8_t a_pack_format;
    uint8_t b_pack_format;
    uint8_t c_pack_format;
    uint8_t pack_version;
    uint8_t overflow_mode;
    uint8_t activation_mode;
    int32_t output_zero_point;
    uint32_t requant_count;
    uint32_t bias_count;
    uint8_t requant_mode;
    uint8_t residual_mode;
    uint8_t requant_entry_bytes;
    uint32_t requant_region_bytes;
} npu_drv_matrix_fields_t;

int npu_drv_event_pack(npu_drv_event_t event, uint16_t *packed);
int npu_drv_event_unpack(uint16_t packed, npu_drv_event_t *event);
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
                   const void *descriptor_cpu_address,
                   size_t descriptor_bytes,
                   npu_drv_submit_result_t *result);
int npu_drv_submit_batch(
    npu_driver_t *driver,
    const npu_drv_cmd128_t *commands,
    size_t command_count,
    const void *descriptor_cpu_address,
    size_t descriptor_bytes,
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

int npu_drv_desc_pool_init(npu_drv_desc_pool_t *pool,
                           void *cpu_base,
                           uint64_t device_base,
                           size_t bytes);
void npu_drv_desc_pool_reset(npu_drv_desc_pool_t *pool);
int npu_drv_desc_alloc(npu_drv_desc_pool_t *pool,
                       npu_drv_desc_type_t type,
                       npu_drv_desc_allocation_t *allocation);
size_t npu_drv_desc_type_bytes(npu_drv_desc_type_t type);

int npu_drv_desc_common_encode(void *descriptor,
                               size_t descriptor_bytes,
                               const npu_drv_desc_common_t *fields);
int npu_drv_desc_dma_encode(void *descriptor,
                            size_t descriptor_bytes,
                            const npu_drv_desc_common_t *common,
                            const npu_drv_dma_fields_t *fields);
int npu_drv_desc_matrix_encode(void *descriptor,
                               size_t descriptor_bytes,
                               const npu_drv_desc_common_t *common,
                               const npu_drv_matrix_fields_t *fields);

int npu_drv_desc_write_u8(void *descriptor,
                          size_t descriptor_bytes,
                          size_t offset,
                          uint8_t value);
int npu_drv_desc_write_u16(void *descriptor,
                           size_t descriptor_bytes,
                           size_t offset,
                           uint16_t value);
int npu_drv_desc_write_u32(void *descriptor,
                           size_t descriptor_bytes,
                           size_t offset,
                           uint32_t value);
int npu_drv_desc_write_u64(void *descriptor,
                           size_t descriptor_bytes,
                           size_t offset,
                           uint64_t value);

#ifdef __cplusplus
}
#endif

#endif /* NPU_DRIVER_H */
