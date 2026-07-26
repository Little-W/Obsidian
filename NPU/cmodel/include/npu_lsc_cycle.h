#ifndef NPU_LSC_CYCLE_H
#define NPU_LSC_CYCLE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_LSC_TIMEOUT_CLASS_COUNT 16u
#define NPU_LSC_PERF_COUNTER_COUNT 16u

#define NPU_LSC_REG_NPU_VERSION UINT16_C(0x0000)
#define NPU_LSC_REG_ISA_FEATURE UINT16_C(0x0008)
#define NPU_LSC_REG_BUS_CONFIG UINT16_C(0x0010)
#define NPU_LSC_REG_L1_CONFIG UINT16_C(0x0018)
#define NPU_LSC_REG_MATRIX_CONFIG UINT16_C(0x0020)
#define NPU_LSC_REG_VECTOR_CONFIG UINT16_C(0x0028)
#define NPU_LSC_REG_CME_CONFIG UINT16_C(0x0030)
#define NPU_LSC_REG_CORE_CONTROL UINT16_C(0x0040)
#define NPU_LSC_REG_CORE_STATUS UINT16_C(0x0048)
#define NPU_LSC_REG_PC_BASE UINT16_C(0x0050)
#define NPU_LSC_REG_INPUT_BASE UINT16_C(0x0058)
#define NPU_LSC_REG_WEIGHT_BASE UINT16_C(0x0060)
#define NPU_LSC_REG_WORK_BASE UINT16_C(0x0068)
#define NPU_LSC_REG_OUTPUT_BASE UINT16_C(0x0070)
#define NPU_LSC_REG_KV_BASE UINT16_C(0x0078)
#define NPU_LSC_REG_DDR_LOCAL_BASE UINT16_C(0x0080)
#define NPU_LSC_REG_DDR_LOCAL_LIMIT UINT16_C(0x0088)
#define NPU_LSC_REG_TBU_STREAM_ID UINT16_C(0x0090)
#define NPU_LSC_REG_IRQ_STATUS UINT16_C(0x00a0)
#define NPU_LSC_REG_IRQ_MASK UINT16_C(0x00a8)
#define NPU_LSC_REG_FAULT_CMD UINT16_C(0x00b0)
#define NPU_LSC_REG_FAULT_ADDR UINT16_C(0x00b8)
#define NPU_LSC_REG_FAULT_INFO UINT16_C(0x00c0)
#define NPU_LSC_REG_FAULT_CLEAR UINT16_C(0x00c8)
#define NPU_LSC_REG_PARAM_L1_BASE UINT16_C(0x00d0)
#define NPU_LSC_REG_PARAM_L1_LIMIT UINT16_C(0x00d8)
#define NPU_LSC_REG_PARAM_LOCK UINT16_C(0x00e0)
#define NPU_LSC_REG_RESET_REASON UINT16_C(0x00e8)
#define NPU_LSC_REG_L1_DIAG_CONTROL UINT16_C(0x00f0)
#define NPU_LSC_REG_FAULT_DETAIL UINT16_C(0x00f8)
#define NPU_LSC_REG_PERF_BASE UINT16_C(0x0100)
#define NPU_LSC_REG_PERF_CONTROL UINT16_C(0x0180)
#define NPU_LSC_REG_TIMEOUT_BASE UINT16_C(0x0200)

#define NPU_LSC_BUS_DATA_BITS_SHIFT 0u
#define NPU_LSC_BUS_GVA_BITS_SHIFT 8u
#define NPU_LSC_BUS_PA_BITS_SHIFT 16u
#define NPU_LSC_BUS_AXI_ID_BITS_SHIFT 24u

#define NPU_LSC_L1_BYTES_SHIFT 0u
#define NPU_LSC_L1_BANKS_SHIFT 32u
#define NPU_LSC_L1_READ_LATENCY_SHIFT 40u

#define NPU_LSC_MATRIX_MT_SHIFT 0u
#define NPU_LSC_MATRIX_KT_SHIFT 8u
#define NPU_LSC_MATRIX_NT_SHIFT 16u
#define NPU_LSC_MATRIX_DTYPE_MASK_SHIFT 24u

#define NPU_LSC_VECTOR_LANES_SHIFT 0u
#define NPU_LSC_VECTOR_OPCODE_MASK_SHIFT 8u

#define NPU_LSC_CME_FP32_LANES_SHIFT 0u
#define NPU_LSC_CME_FUNCTION_MASK_SHIFT 8u
#define NPU_LSC_CME_APPROX_MASK_SHIFT 21u
#define NPU_LSC_CME_SCRATCH_ELEMS_SHIFT 32u

#define NPU_LSC_FIELD_U8_MASK UINT64_C(0xff)
#define NPU_LSC_FIELD_U16_MASK UINT64_C(0xffff)
#define NPU_LSC_FIELD_U32_MASK UINT64_C(0xffffffff)
#define NPU_LSC_MATRIX_DTYPE_MASK UINT64_C(0xf)
#define NPU_LSC_VECTOR_OPCODE_MASK UINT64_C(0x3ff)
#define NPU_LSC_CME_FUNCTION_MASK UINT64_C(0x1fff)
#define NPU_LSC_CME_APPROX_MASK UINT64_C(0xf)

#define NPU_LSC_CORE_CONTROL_START UINT64_C(0x1)
#define NPU_LSC_CORE_CONTROL_STOP UINT64_C(0x2)
#define NPU_LSC_CORE_CONTROL_SOFT_RESET UINT64_C(0x4)
#define NPU_LSC_CORE_CONTROL_SINGLE_STEP UINT64_C(0x8)

#define NPU_LSC_CORE_STATUS_IDLE UINT64_C(0x1)
#define NPU_LSC_CORE_STATUS_BUSY UINT64_C(0x2)
#define NPU_LSC_CORE_STATUS_WFI UINT64_C(0x4)
#define NPU_LSC_CORE_STATUS_ERROR UINT64_C(0x8)
#define NPU_LSC_CORE_STATUS_POWER_READY UINT64_C(0x10)
#define NPU_LSC_CORE_STATUS_SOFT_RESET_BUSY UINT64_C(0x20)

#define NPU_LSC_IRQ_DONE UINT64_C(0x1)
#define NPU_LSC_IRQ_EXCEPTION UINT64_C(0x2)
#define NPU_LSC_IRQ_ERROR UINT64_C(0x4)
#define NPU_LSC_IRQ_ALL UINT64_C(0x7)

#define NPU_LSC_PERF_FREEZE UINT64_C(0x1)
#define NPU_LSC_PERF_CLEAR UINT64_C(0x2)

#define NPU_LSC_RESET_EXTERNAL UINT64_C(0x1)
#define NPU_LSC_RESET_SOFTWARE UINT64_C(0x2)
#define NPU_LSC_RESET_WATCHDOG UINT64_C(0x4)

#define NPU_LSC_L1_DIAG_ENABLE UINT64_C(0x1)

#define NPU_LSC_ISA_DMA_GATHER_ND UINT64_C(0x1)
#define NPU_LSC_ISA_VROPE_I UINT64_C(0x2)
#define NPU_LSC_ISA_VRECIP_I UINT64_C(0x4)
#define NPU_LSC_ISA_CAUSAL_SOFTMAX UINT64_C(0x8)
#define NPU_LSC_ISA_DESCRIPTOR_CRC UINT64_C(0x10)
#define NPU_LSC_ISA_OPTIONAL_MASK UINT64_C(0x1f)
#define NPU_LSC_IMPLEMENTED_ISA_FEATURES UINT64_C(0)

#define NPU_LSC_EXTERNAL_ERROR_STAGE 7u
#define NPU_LSC_EXTERNAL_SOURCE_SHIFT 24u
#define NPU_LSC_EXTERNAL_DETAIL_SHIFT 16u
#define NPU_LSC_EXTERNAL_AUX_SHIFT 8u

typedef enum {
    NPU_LSC_REG_OKAY = 0,
    NPU_LSC_REG_SLVERR = 2
} npu_lsc_reg_status_t;

typedef enum {
    NPU_LSC_SOFT_IDLE = 0,
    NPU_LSC_SOFT_DRAIN = 1,
    NPU_LSC_SOFT_WAIT_RESET = 2,
    NPU_LSC_SOFT_ACK = 3
} npu_lsc_soft_state_t;

typedef enum {
    NPU_LSC_POWER_IDLE = 0,
    NPU_LSC_POWER_DRAIN = 1,
    NPU_LSC_POWER_ACK = 2
} npu_lsc_power_state_t;

/*
 * Source zero is retained for task-terminal records, whose error_info keeps
 * the task format from Spec section 8.5. Sources one through seven use the
 * external-error format documented in Spec section 15.2.3.
 */
typedef enum {
    NPU_LSC_FAULT_SOURCE_TASK = 0,
    NPU_LSC_FAULT_SOURCE_SYS_L1_DIAG = 1,
    NPU_LSC_FAULT_SOURCE_L1_ECC = 2,
    NPU_LSC_FAULT_SOURCE_MIF_FIRST = 3,
    NPU_LSC_FAULT_SOURCE_MIF_PROTOCOL = 4,
    NPU_LSC_FAULT_SOURCE_GC_AXI_FIRST = 5,
    NPU_LSC_FAULT_SOURCE_GC_AXI_PROTOCOL = 6,
    NPU_LSC_FAULT_SOURCE_WDT = 7
} npu_lsc_fault_source_t;

/*
 * valid is a sticky level. The source holds every payload field stable until
 * external_error_clear_o is observed. A new event coincident with clear is
 * set-dominant at the source and remains valid for later capture.
 */
typedef struct {
    uint8_t valid;
    uint8_t status;
    uint64_t addr;
    uint8_t detail;
    uint8_t aux;
    uint8_t has_task_identity;
    uint16_t command_id;
    uint8_t engine;
    uint8_t opcode;
} npu_lsc_external_error_input_t;

typedef struct {
    uint32_t version_major;
    uint32_t version_minor;
    uint32_t build;
    uint64_t isa_feature;
    uint64_t bus_config;
    uint64_t l1_config;
    uint64_t matrix_config;
    uint64_t vector_config;
    uint64_t cme_config;
    uint32_t l1_bytes;
    uint32_t timeout_reset[NPU_LSC_TIMEOUT_CLASS_COUNT];
} npu_lsc_cycle_config_t;

typedef struct {
    uint8_t reset_n;

    uint8_t reg_req_valid;
    uint8_t reg_req_write;
    uint8_t reg_req_space;
    uint16_t reg_req_addr;
    uint64_t reg_req_wdata;
    uint8_t reg_req_wstrb;
    uint8_t reg_rsp_ready;

    uint8_t soft_reset_req;
    uint8_t internal_soft_reset_done;
    uint8_t power_down_req;
    uint8_t core_wfi;

    uint8_t issue_idle;
    uint8_t cfe_idle;
    uint8_t ts_idle;
    uint8_t ts_quiescent;
    uint8_t eng_quiescent;
    uint8_t l1_idle;
    uint8_t l1_write_idle;
    uint8_t mif_idle;
    uint8_t gc_axi_idle;

    uint8_t task_terminal_valid;
    uint8_t task_irq_on_success;
    uint8_t task_irq_on_error;
    uint16_t task_command_id;
    uint8_t task_status;
    uint8_t task_engine;
    uint8_t task_opcode;
    uint64_t task_fault_addr;
    uint32_t task_error_info;
    uint16_t task_done_flags;

    npu_lsc_external_error_input_t sys_l1_diag_error;
    npu_lsc_external_error_input_t l1_ecc_error;
    npu_lsc_external_error_input_t mif_first_error;
    npu_lsc_external_error_input_t mif_protocol_error;
    npu_lsc_external_error_input_t gc_axi_first_error;
    npu_lsc_external_error_input_t gc_axi_protocol_error;

    uint8_t wdt_timeout;
    uint64_t perf_increment[NPU_LSC_PERF_COUNTER_COUNT];
} npu_lsc_cycle_inputs_t;

typedef struct {
    uint8_t reg_req_ready;
    uint8_t reg_rsp_valid;
    uint64_t reg_rsp_rdata;
    uint8_t reg_rsp_status;

    uint8_t cfe_quiesce;
    uint8_t ts_quiesce;
    uint8_t eng_abort;
    uint8_t stop_fetch;
    uint8_t single_step_pulse;
    uint8_t internal_soft_reset_pulse;

    uint8_t soft_reset_done;
    uint8_t power_down_ack;
    uint8_t core_idle;

    uint8_t irq_done;
    uint8_t irq_exception;
    uint8_t irq_error;
    uint8_t external_error_clear_o;

    uint32_t param_l1_base;
    uint32_t param_l1_limit;
    uint8_t param_lock;
    uint8_t l1_diag_enable;
    uint8_t debug_frozen;

    uint64_t pc_base;
    uint64_t input_base;
    uint64_t weight_base;
    uint64_t work_base;
    uint64_t output_base;
    uint64_t kv_base;
    uint64_t ddr_local_base;
    uint64_t ddr_local_limit;
    uint16_t tbu_stream_id;
    uint16_t tbu_substream_id;
    uint32_t timeout_cycles[NPU_LSC_TIMEOUT_CLASS_COUNT];
} npu_lsc_cycle_outputs_t;

typedef struct {
    npu_lsc_cycle_config_t config;

    uint8_t response_valid;
    uint64_t response_data;
    uint8_t response_status;

    uint8_t started;
    uint8_t stopped;
    uint8_t single_step_pulse;
    uint8_t internal_soft_reset_pulse;

    uint8_t soft_state;
    uint8_t soft_external_request;
    uint8_t power_state;
    uint8_t power_request_held;

    uint64_t pc_base;
    uint64_t input_base;
    uint64_t weight_base;
    uint64_t work_base;
    uint64_t output_base;
    uint64_t kv_base;
    uint64_t ddr_local_base;
    uint64_t ddr_local_limit;
    uint16_t tbu_stream_id;
    uint16_t tbu_substream_id;

    uint64_t irq_status;
    uint64_t irq_mask;
    uint8_t fault_valid;
    uint16_t fault_command_id;
    uint64_t fault_addr;
    uint8_t fault_status;
    uint8_t fault_engine;
    uint8_t fault_opcode;
    uint8_t fault_source;
    uint32_t fault_error_info;
    uint16_t fault_done_flags;
    uint8_t external_error_clear_pulse;

    uint32_t param_l1_base;
    uint32_t param_l1_limit;
    uint8_t param_lock;
    uint8_t l1_diag_enable;
    uint64_t reset_reason;

    uint64_t perf_counter[NPU_LSC_PERF_COUNTER_COUNT];
    uint8_t perf_frozen;
    uint32_t timeout_cycles[NPU_LSC_TIMEOUT_CLASS_COUNT];
} npu_lsc_cycle_t;

void npu_lsc_cycle_config_reference(npu_lsc_cycle_config_t *config);

void npu_lsc_cycle_init(npu_lsc_cycle_t *model,
                        const npu_lsc_cycle_config_t *config);

void npu_lsc_cycle_reset(npu_lsc_cycle_t *model);

void npu_lsc_cycle_step(npu_lsc_cycle_t *model,
                        const npu_lsc_cycle_inputs_t *inputs,
                        npu_lsc_cycle_outputs_t *outputs);

#ifdef __cplusplus
}
#endif

#endif
