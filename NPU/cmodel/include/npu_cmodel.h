#ifndef NPU_CMODEL_H
#define NPU_CMODEL_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_CMODEL_VERSION_MAJOR 1u
#define NPU_CMODEL_VERSION_MINOR 0u

#define NPU_REF_BUS_DATA_BITS 64u
#define NPU_REF_BUS_BYTES 8u
#define NPU_REF_L1_BYTES (1024u * 1024u)
#define NPU_REF_L1_BANKS 16u
#define NPU_REF_L1_RD_LATENCY 2u
#define NPU_REF_MT 8u
#define NPU_REF_KT 16u
#define NPU_REF_NT 8u
#define NPU_REF_VLANES 8u
#define NPU_REF_CME_LANES 4u
#define NPU_REF_CME_MAX_LENGTH 65536u
#define NPU_REF_TASK_NUM 32u
#define NPU_REF_DESC_SLOTS 32u
#define NPU_REF_CFE_FIFO_DEPTH 8u
#define NPU_REF_DMA_OUTSTANDING 16u
#define NPU_REF_MIF_OUTSTANDING 16u
#define NPU_REF_DMA_MAX_BURST_BEATS 16u
#define NPU_REF_L1_STARVE_LIMIT 64u
#define NPU_REF_CME_SCRATCH_ELEMS 4096u

#define NPU_MAX_TASKS 32u
#define NPU_EVENT_NUM 255u
#define NPU_EVENT_NONE_ID 255u
#define NPU_EVENT_NONE_GENERATION 15u
#define NPU_MAX_DMA_RANK 5u
#define NPU_TIMEOUT_CLASS_NUM 16u
#define NPU_ENGINE_COUNT 5u

#define NPU_DONE_PARTIAL_DEST (1u << 0)
#define NPU_DONE_FAULT_ADDR_IS_L1 (1u << 1)
#define NPU_DONE_ABORT_DRAINED (1u << 2)

typedef enum {
    NPU_DTYPE_INT4 = 0,
    NPU_DTYPE_INT8 = 1,
    NPU_DTYPE_INT32 = 2,
    /*
     * Descriptor dtype fields are two bits wide.  Code 3 was reserved in
     * The value 3 was previously unused, so INT16 uses it without changing INT32
     * encoding.
     */
    NPU_DTYPE_INT16 = 3
} npu_dtype_t;

typedef enum {
    NPU_SPACE_L1 = 0,
    NPU_SPACE_DDR = 1
} npu_space_t;

typedef enum {
    NPU_ROUND_NEAREST_EVEN = 0,
    NPU_ROUND_TO_ZERO = 1,
    NPU_ROUND_TO_POS_INF = 2,
    NPU_ROUND_TO_NEG_INF = 3
} npu_round_mode_t;

/*
 * Observable FP32 checkpoints for Complex Engine approx_mode=0.
 * All *_bits fields contain the exact IEEE 754 binary32 bit pattern.
 * A valid flag is zero when the corresponding function took a special-case
 * path that does not execute range reduction or Newton iterations.
 */
typedef struct {
    uint8_t exp_valid;
    uint8_t reciprocal_valid;
    uint8_t rsqrt_valid;
    uint8_t f2i_valid;
    int32_t exp_k;
    uint32_t exp_r_bits;
    uint32_t reciprocal_newton_bits;
    uint32_t rsqrt_newton_bits;
    uint32_t f2i_input_bits;
} npu_mode0_trace_t;

typedef enum {
    NPU_OVERFLOW_SATURATE = 0,
    NPU_OVERFLOW_ERROR = 1,
    NPU_OVERFLOW_WRAP = 2
} npu_overflow_mode_t;

typedef enum {
    NPU_STATUS_SUCCESS = 0x00,
    NPU_STATUS_ILLEGAL_OPCODE = 0x01,
    NPU_STATUS_BAD_DESC = 0x02,
    NPU_STATUS_BAD_SHAPE = 0x03,
    NPU_STATUS_ADDR_FAULT = 0x04,
    NPU_STATUS_BUS_DECERR = 0x05,
    NPU_STATUS_BUS_SLVERR = 0x06,
    NPU_STATUS_DTYPE_UNSUPPORTED = 0x07,
    NPU_STATUS_DEPENDENCY_FAILED = 0x08,
    NPU_STATUS_TIMEOUT = 0x09,
    NPU_STATUS_ABORTED = 0x0a,
    NPU_STATUS_L1_ECC_UNCORRECTABLE = 0x0b,
    NPU_STATUS_NUMERIC_EXCEPTION = 0x0c,
    NPU_STATUS_ADDR_OVERLAP = 0x0d,
    NPU_STATUS_BUSY = 0x80,
    NPU_STATUS_NOT_FOUND = 0x81
} npu_status_t;

typedef enum {
    NPU_ENGINE_CONTROL = 0,
    NPU_ENGINE_DMA = 1,
    NPU_ENGINE_MATRIX = 2,
    NPU_ENGINE_VECTOR = 3,
    NPU_ENGINE_COMPLEX = 4
} npu_engine_t;

typedef enum {
    NPU_CTRL_NOP = 0x00,
    NPU_CTRL_EVENT_SIGNAL = 0x01,
    NPU_CTRL_EVENT_REARM = 0x02,
    NPU_CTRL_EVENT_JOIN = 0x03,
    NPU_CTRL_GLOBAL_FENCE = 0x04
} npu_control_opcode_t;

typedef enum {
    NPU_DMA_COPY_1D = 0x20,
    NPU_DMA_COPY_ND = 0x21,
    NPU_DMA_FILL = 0x22,
    NPU_DMA_TRANSPOSE_2D = 0x23,
    NPU_DMA_PACK = 0x24,
    NPU_DMA_SPLIT = 0x25,
    NPU_DMA_GATHER_ND = 0x28
} npu_dma_opcode_t;

typedef enum {
    NPU_MATRIX_GEMM = 0x40,
    NPU_MATRIX_BMM = 0x41,
    NPU_MATRIX_GEMM_ACCUM = 0x42,
    NPU_MATRIX_GEMM_ZERO = 0x43
} npu_matrix_opcode_t;

typedef enum {
    NPU_VECTOR_ADD = 0x60,
    NPU_VECTOR_SUB = 0x61,
    NPU_VECTOR_MUL = 0x62,
    NPU_VECTOR_FMA = 0x63,
    NPU_VECTOR_MAX = 0x64,
    NPU_VECTOR_MIN = 0x65,
    NPU_VECTOR_CMP = 0x66,
    NPU_VECTOR_SELECT = 0x67,
    NPU_VECTOR_CLAMP = 0x68,
    NPU_VECTOR_RELU = 0x69
} npu_vector_opcode_t;

typedef enum {
    NPU_COMPLEX_ACT = 0x80,
    NPU_COMPLEX_SOFTMAX = 0x81,
    NPU_COMPLEX_NORM = 0x82,
    NPU_COMPLEX_ROPE = 0x83,
    NPU_COMPLEX_STAT = 0x84,
    NPU_COMPLEX_RECIP = 0x85,
    NPU_COMPLEX_ADD_RESCALE = 0x86
} npu_complex_opcode_t;

typedef enum {
    NPU_DMA_CONVERT_NONE = 0,
    NPU_DMA_SIGN_EXTEND = 1,
    NPU_DMA_SATURATE_NARROW = 2,
    NPU_DMA_PACK_INT4 = 3
} npu_dma_convert_t;

typedef enum {
    NPU_BROADCAST_NONE = 0,
    NPU_BROADCAST_SCALAR = 1,
    NPU_BROADCAST_ROW = 2,
    NPU_BROADCAST_FEATURE = 3
} npu_broadcast_t;

typedef enum {
    NPU_COMPARE_EQ = 0,
    NPU_COMPARE_NE = 1,
    NPU_COMPARE_LT = 2,
    NPU_COMPARE_LE = 3,
    NPU_COMPARE_GT = 4,
    NPU_COMPARE_GE = 5
} npu_compare_t;

typedef enum {
    NPU_FUNC_SIGMOID = 0,
    NPU_FUNC_TANH = 1,
    NPU_FUNC_GELU = 2,
    NPU_FUNC_SILU = 3,
    NPU_FUNC_SOFTMAX = 4,
    NPU_FUNC_LAYERNORM = 5,
    NPU_FUNC_RMSNORM = 6,
    NPU_FUNC_STAT_SUM = 7,
    NPU_FUNC_STAT_MAX = 8,
    NPU_FUNC_STAT_SUMSQ = 9,
    NPU_FUNC_RECIPROCAL = 10,
    NPU_FUNC_RECIPROCAL_SQRT = 11,
    NPU_FUNC_ADD_RESCALE = 12
} npu_function_t;

typedef enum {
    NPU_MASK_NONE = 0,
    NPU_MASK_BOOLEAN = 1,
    NPU_MASK_CAUSAL = 2,
    NPU_MASK_VALID_LENGTH = 3
} npu_mask_mode_t;

typedef enum {
    NPU_ALL_MASK_WRITE_ZERO = 0,
    NPU_ALL_MASK_ERROR = 1
} npu_all_mask_mode_t;

typedef enum {
    NPU_SCALE_NONE = 0,
    NPU_SCALE_PER_TENSOR = 1,
    NPU_SCALE_PER_ROW = 2,
    NPU_SCALE_PER_FEATURE = 3
} npu_scale_mode_t;

typedef enum {
    NPU_EVENT_FREE = 0,
    NPU_EVENT_RESERVED = 1,
    NPU_EVENT_SUCCESS = 2,
    NPU_EVENT_FAILED = 3,
    NPU_EVENT_UNUSED = NPU_EVENT_FREE,
    NPU_EVENT_PENDING = NPU_EVENT_RESERVED
} npu_event_state_t;

typedef enum {
    NPU_TASK_FREE = 0,
    NPU_TASK_WAITING = 1,
    NPU_TASK_RUNNING = 2,
    NPU_TASK_TERMINAL = 3
} npu_task_state_t;

typedef struct {
    uint8_t id;
    uint8_t generation;
} npu_event_ref_t;

typedef struct {
    npu_space_t space;
    npu_dtype_t dtype;
    uint64_t addr;
    uint64_t region_bytes;
    uint32_t row_stride_bytes;
    uint32_t elem_stride_bytes;
    uint32_t batch_stride_bytes;
    uint8_t start_nibble;
} npu_tensor_t;

typedef struct {
    uint32_t multiplier;
    int8_t shift;
} npu_requant_t;

typedef struct {
    uint64_t desc_addr;
    uint16_t command_id;
    npu_engine_t engine;
    uint8_t opcode;
    uint16_t header_flags;
    npu_event_ref_t wait_event[2];
    npu_event_ref_t signal_event;
    uint8_t header_version;
    uint8_t timeout_class;
    uint32_t user_tag;
    uint64_t inline_payload_lo;
    uint16_t inline_payload_hi;
    uint8_t inline_format;
    npu_dtype_t inline_dtype;
} npu_cmd_t;

typedef struct {
    npu_event_ref_t event0;
    npu_event_ref_t event1;
    npu_event_ref_t target;
    uint8_t join_mode;
    uint8_t engine_mask;
} npu_control_desc_t;

typedef struct {
    uint8_t rank;
    npu_space_t src_space;
    npu_space_t dst_space;
    npu_dtype_t src_dtype;
    npu_dtype_t dst_dtype;
    npu_dma_convert_t convert_mode;
    uint64_t src_addr;
    uint64_t dst_addr;
    uint64_t src_region_bytes;
    uint64_t dst_region_bytes;
    uint32_t shape[NPU_MAX_DMA_RANK];
    uint32_t src_stride_bytes[NPU_MAX_DMA_RANK];
    uint32_t dst_stride_bytes[NPU_MAX_DMA_RANK];
    uint64_t fill_value;
    uint32_t segment_count;
    uint32_t segment_bytes;
    uint32_t segment_stride;
    uint8_t src_nibble;
    uint8_t dst_nibble;
    uint8_t burst_beats;
    uint8_t max_outstanding;
} npu_dma_desc_t;

typedef struct {
    uint32_t m;
    uint32_t n;
    uint32_t k;
    uint32_t batch_count;
    npu_tensor_t a;
    npu_tensor_t b;
    npu_tensor_t c;
    npu_tensor_t src2;
    uint64_t bias_addr;
    uint32_t bias_count;
    uint32_t bias_stride_bytes;
    uint64_t requant_addr;
    uint32_t requant_count;
    uint32_t requant_region_bytes;
    uint8_t b_tiled;
    uint8_t transpose_a;
    uint8_t transpose_b;
    uint8_t bias_enable;
    uint8_t residual_enable;
    uint8_t accum_from_src2;
    uint8_t final_output;
    uint8_t relu_enable;
    uint8_t requant_enable;
    uint8_t inline_requant_enable;
    uint32_t inline_requant_multiplier;
    int8_t inline_requant_shift;
    npu_round_mode_t round_mode;
    npu_overflow_mode_t overflow_mode;
    int32_t output_zero_point;
} npu_matrix_desc_t;

typedef struct {
    uint32_t rows;
    uint32_t length;
    uint32_t valid_length;
    npu_tensor_t src0;
    npu_tensor_t src1;
    npu_tensor_t src2;
    npu_tensor_t dst;
    npu_tensor_t mask;
    npu_broadcast_t broadcast0;
    npu_broadcast_t broadcast1;
    npu_broadcast_t broadcast2;
    npu_compare_t compare_mode;
    npu_overflow_mode_t overflow_mode;
    int32_t scalar0;
    int32_t scalar1;
    int32_t clamp_min;
    int32_t clamp_max;
    uint32_t src0_scale_bits;
    uint32_t src1_scale_bits;
    uint32_t src2_scale_bits;
    uint32_t dst_scale_bits;
    uint8_t src1_from_scalar0;
    uint8_t src2_from_scalar1;
    uint8_t mask_enable;
    uint8_t mask_false_keep_dst;
} npu_vector_desc_t;

typedef struct {
    uint32_t rows;
    uint32_t length;
    uint32_t valid_length;
    npu_function_t function;
    npu_tensor_t src0;
    npu_tensor_t src1;
    npu_tensor_t src2;
    npu_tensor_t dst;
    npu_tensor_t mask;
    npu_tensor_t valid_lengths;
    float src0_scale;
    float src1_scale;
    float src2_scale;
    float dst_scale;
    int32_t src0_zero_point;
    int32_t src1_zero_point;
    int32_t src2_zero_point;
    int32_t dst_zero_point;
    float epsilon;
    float input_clip_min;
    float input_clip_max;
    npu_round_mode_t round_mode;
    npu_overflow_mode_t overflow_mode;
    npu_scale_mode_t scale_mode;
    npu_mask_mode_t mask_mode;
    npu_all_mask_mode_t all_mask_mode;
    uint64_t src0_scale_table_addr;
    uint64_t dst_scale_table_addr;
    uint32_t query_position_base;
    uint32_t key_position_base;
    uint32_t query_position_step;
    uint32_t scratch_request_elems;
    uint8_t approx_mode;
    uint8_t stats_mode;
    uint8_t beta_enable;
    uint8_t strict_numeric;
} npu_complex_desc_t;

typedef union {
    npu_control_desc_t control;
    npu_dma_desc_t dma;
    npu_matrix_desc_t matrix;
    npu_vector_desc_t vector;
    npu_complex_desc_t complex;
} npu_desc_u;

typedef struct {
    npu_cmd_t cmd;
    npu_desc_u desc;
    uint16_t desc_bytes;
    uint8_t desc_version;
    uint8_t allow_inplace;
    uint8_t allow_partial_dest;
} npu_task_request_t;

typedef struct {
    uint32_t l1_bytes;
    uint16_t l1_banks;
    uint8_t l1_read_latency;
    uint8_t mt;
    uint8_t kt;
    uint8_t nt;
    uint8_t vector_lanes;
    uint8_t cme_lanes;
    uint8_t task_entries;
    uint8_t descriptor_slots;
    uint8_t cfe_fifo_depth;
    uint8_t dma_outstanding;
    uint8_t mif_outstanding;
    uint8_t dma_max_burst_beats;
    uint16_t l1_starve_limit;
    uint16_t cme_scratch_elems;
    uint32_t timeout_cycles[NPU_TIMEOUT_CLASS_NUM];
    uint16_t ddr_read_latency;
    uint16_t ddr_write_latency;
    uint16_t cfe_beat_timeout;
} npu_config_t;

typedef struct {
    uint8_t core_reset_n;
    uint8_t noc_reset_n;
    uint8_t cmd_valid;
    uint64_t cmd_data;
    uint8_t cmd_first;
    uint8_t cmd_last;
    uint8_t cmd_rsp_ready;
} npu_host_inputs_t;

typedef struct {
    uint8_t cmd_ready;
    uint8_t cmd_rsp_valid;
    uint64_t cmd_rsp_data;
    uint64_t cycle;
} npu_host_outputs_t;

typedef struct {
    uint8_t have_low_beat;
    uint8_t response_valid;
    uint64_t low_beat;
    uint64_t response_data;
    uint32_t wait_cycles;
} npu_cfe_model_t;

typedef struct {
    uint64_t core_active_cycles;
    uint64_t cmd_accepted;
    uint64_t task_success;
    uint64_t task_failed;
    uint64_t dma_read_bytes;
    uint64_t dma_write_bytes;
    uint64_t dma_stall_cycles;
    uint64_t l1_bank_stall_cycles;
    uint64_t matrix_mac_active_cycles;
    uint64_t matrix_accum_active_cycles;
    uint64_t matrix_overlap_cycles;
    uint64_t matrix_hazard_stall_cycles;
    uint64_t matrix_operand_stall_cycles;
    uint64_t ive_active_cycles;
    uint64_t cme_fp_active_cycles;
    uint64_t cme_l1_stall_cycles;
    uint64_t int_saturate_count;
    uint64_t all_mask_row_count;
    uint64_t ecc_corrected_count;
} npu_perf_t;

typedef struct {
    npu_event_state_t state;
    uint8_t generation;
    npu_status_t status;
    uint16_t waiter_count;
    uint16_t producer_task_id;
} npu_event_entry_t;

typedef struct {
    uint16_t command_id;
    npu_status_t status;
    uint32_t user_tag;
    uint64_t submit_cycle;
    uint64_t start_cycle;
    uint64_t end_cycle;
    uint64_t progress;
    uint64_t fault_addr;
    uint32_t error_info;
    uint16_t done_flags;
} npu_task_result_t;

typedef struct {
    npu_task_state_t state;
    npu_task_request_t request;
    npu_task_result_t result;
    uint64_t submit_seq;
    uint64_t estimated_cycles;
    uint64_t remaining_cycles;
    uint64_t matrix_accum_cycles;
    uint64_t fence_error_seq;
    npu_status_t fence_error_status;
    uint8_t matrix_in_accum;
    uint8_t waiters_released;
} npu_task_slot_t;

typedef struct {
    npu_config_t config;
    uint8_t *l1;
    size_t l1_size;
    uint8_t *ddr;
    size_t ddr_size;
    uint64_t cycle;
    uint64_t next_submit_seq;
    int16_t active_slot[NPU_ENGINE_COUNT];
    int16_t matrix_accum_slot;
    npu_task_slot_t tasks[NPU_MAX_TASKS];
    npu_event_entry_t events[NPU_EVENT_NUM];
    npu_perf_t perf;
    npu_cfe_model_t cfe;
    uint8_t descriptor_diagnostic_mode;

    /*
     * Private, temporary fault recorder used by the cycle adapters. Public
     * callers must leave this field untouched.
     */
    void *internal_fault_capture;

    /*
     * Private, temporary 64-bit access recorder used by data-side cycle
     * adapters. Public callers must leave this field untouched.
     */
    void *internal_bus_trace;
} npu_model_t;

void npu_config_reference(npu_config_t *config);
npu_status_t npu_model_init(npu_model_t *model,
                            const npu_config_t *config,
                            uint8_t *l1,
                            size_t l1_size,
                            uint8_t *ddr,
                            size_t ddr_size);
void npu_model_reset(npu_model_t *model);

npu_event_ref_t npu_event_none(void);
/*
 * producer_task_id is the 12-bit value stored by the Event Table.  Invalid
 * arguments return NPU_STATUS_BAD_DESC without changing the selected entry.
 */
npu_status_t npu_event_reserve(npu_model_t *model,
                               uint8_t event_id,
                               uint8_t generation,
                               uint16_t producer_task_id);
npu_status_t npu_event_rearm(npu_model_t *model,
                             uint8_t event_id,
                             uint8_t generation);
/*
 * status must be one of the terminal status codes from NPU_STATUS_SUCCESS
 * through NPU_STATUS_ADDR_OVERLAP.  Invalid status values leave the reserved
 * event unchanged.
 */
npu_status_t npu_event_signal(npu_model_t *model,
                              npu_event_ref_t event,
                              npu_status_t status);

npu_status_t npu_cmd_decode(uint64_t low_beat,
                            uint64_t high_beat,
                            npu_cmd_t *cmd);
/*
 * Explicit decoder for descriptor-based diagnostic tests.  Runtime command
 * submission always uses npu_cmd_decode() and the current 128-bit instruction format.
 */
npu_status_t npu_cmd_decode_descriptor(uint64_t low_beat,
                                       uint64_t high_beat,
                                       npu_cmd_t *cmd);
void npu_cmd_encode(const npu_cmd_t *cmd,
                    uint64_t *low_beat,
                    uint64_t *high_beat);

npu_status_t npu_model_submit(npu_model_t *model,
                              const npu_task_request_t *request);
npu_status_t npu_model_submit_wire(npu_model_t *model,
                                   uint64_t low_beat,
                                   uint64_t high_beat);
void npu_model_cycle_io(npu_model_t *model,
                        const npu_host_inputs_t *inputs,
                        npu_host_outputs_t *outputs);
void npu_model_step(npu_model_t *model, uint64_t cycles);
npu_status_t npu_model_run(npu_model_t *model, uint64_t max_cycles);
int npu_model_idle(const npu_model_t *model);
npu_status_t npu_model_query(npu_model_t *model,
                             uint16_t command_id,
                             int acknowledge,
                             npu_task_result_t *result);
/*
 * Return the functional scheduler's reference cycle count.  Intermediate
 * addition and multiplication saturate at UINT64_MAX instead of wrapping.
 */
uint64_t npu_estimate_task_cycles(const npu_model_t *model,
                                  const npu_task_request_t *request);

npu_status_t npu_dma_execute(npu_model_t *model,
                             uint8_t opcode,
                             const npu_dma_desc_t *desc,
                             uint64_t *progress);
npu_status_t npu_matrix_execute(npu_model_t *model,
                                uint8_t opcode,
                                const npu_matrix_desc_t *desc,
                                uint64_t *progress);
npu_status_t npu_vector_execute(npu_model_t *model,
                                uint8_t opcode,
                                const npu_vector_desc_t *desc,
                                uint64_t *progress);
npu_status_t npu_complex_execute(npu_model_t *model,
                                 uint8_t opcode,
                                 const npu_complex_desc_t *desc,
                                 uint64_t *progress);

npu_status_t npu_tensor_read(const npu_model_t *model,
                             const npu_tensor_t *tensor,
                             uint32_t batch,
                             uint32_t row,
                             uint32_t element,
                             int32_t *value);
npu_status_t npu_tensor_write(npu_model_t *model,
                              const npu_tensor_t *tensor,
                              uint32_t batch,
                              uint32_t row,
                              uint32_t element,
                              int32_t value);

int8_t npu_int4_unpack(uint8_t packed, uint8_t high_nibble);
uint8_t npu_int4_insert(uint8_t packed, uint8_t high_nibble, int32_t value);
int64_t npu_round_shift(int64_t value,
                        int32_t shift,
                        npu_round_mode_t mode);
npu_status_t npu_cast_integer(npu_model_t *model,
                              int64_t value,
                              npu_dtype_t dtype,
                              npu_overflow_mode_t mode,
                              int32_t *result);

float npu_exp_approx(float x);
float npu_reciprocal_approx(float x);
float npu_rsqrt_approx(float x);
void npu_mode0_trace_clear(npu_mode0_trace_t *trace);
float npu_exp_approx_traced(float x,
                            npu_mode0_trace_t *trace);
float npu_reciprocal_approx_traced(
    float x, npu_mode0_trace_t *trace);
float npu_rsqrt_approx_traced(float x,
                              npu_mode0_trace_t *trace);
float npu_sigmoid_approx(float x);
float npu_tanh_approx(float x);
float npu_gelu_approx(float x);
float npu_silu_approx(float x);
int npu_float_is_finite_positive(float x);
int32_t npu_float_to_int(float x, npu_round_mode_t mode);
int32_t npu_float_to_int_traced(
    float x, npu_round_mode_t mode,
    npu_mode0_trace_t *trace);

#ifdef __cplusplus
}
#endif

#endif
