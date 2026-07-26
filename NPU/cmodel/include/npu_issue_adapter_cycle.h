#ifndef NPU_ISSUE_ADAPTER_CYCLE_H
#define NPU_ISSUE_ADAPTER_CYCLE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_ISSUE_CUSTOM0_OPCODE 0x0bu
#define NPU_ISSUE_ILLEGAL_INSTRUCTION_CAUSE UINT64_C(2)

typedef enum {
    NPU_ISSUE_FUNCT3_SUBMIT = 0,
    NPU_ISSUE_FUNCT3_WAIT = 1,
    NPU_ISSUE_FUNCT3_QUERY = 2,
    NPU_ISSUE_FUNCT3_FENCE = 3
} npu_issue_funct3_t;

typedef enum {
    NPU_ISSUE_CTL_WAIT = 0,
    NPU_ISSUE_CTL_QUERY = 1,
    NPU_ISSUE_CTL_FENCE = 2
} npu_issue_ctl_op_t;

typedef enum {
    NPU_ISSUE_STATE_IDLE = 0,
    NPU_ISSUE_STATE_SUBMIT_LOW = 1,
    NPU_ISSUE_STATE_SUBMIT_HIGH = 2,
    NPU_ISSUE_STATE_SUBMIT_RESPONSE = 3,
    NPU_ISSUE_STATE_CONTROL_REQUEST = 4,
    NPU_ISSUE_STATE_CONTROL_RESPONSE = 5,
    NPU_ISSUE_STATE_CORE_RESPONSE = 6
} npu_issue_adapter_state_t;

typedef struct {
    uint8_t reset_n;
    uint8_t issue_quiesce_i;

    uint8_t issue_valid_i;
    uint8_t issue_opcode_i;
    uint8_t issue_funct3_i;
    uint8_t issue_funct7_i;
    uint64_t issue_rs1_i;
    uint64_t issue_rs2_i;
    uint8_t issue_rd_i;
    uint8_t dsa_permission_i;
    uint8_t dsa_enable_i;
    uint8_t cpu_cancel_i;
    uint8_t issue_rsp_ready_i;

    uint8_t gc_cmd_ready_i;
    uint8_t gc_rsp_valid_i;
    uint64_t gc_rsp_data_i;

    uint8_t gc_ctl_ready_i;
    uint8_t gc_ctl_rsp_valid_i;
    uint64_t gc_ctl_rsp_data_i;
} npu_issue_adapter_cycle_inputs_t;

typedef struct {
    uint8_t issue_ready_o;
    uint8_t issue_rsp_valid_o;
    uint8_t issue_rsp_rd_o;
    uint64_t issue_rsp_data_o;
    uint8_t issue_rsp_exception_o;
    uint64_t issue_rsp_cause_o;
    uint8_t issue_canceled_o;
    uint8_t issue_busy_o;

    uint8_t gc_cmd_valid_o;
    uint64_t gc_cmd_data_o;
    uint8_t gc_cmd_first_o;
    uint8_t gc_cmd_last_o;
    uint8_t gc_rsp_ready_o;

    uint8_t gc_ctl_valid_o;
    uint8_t gc_ctl_op_o;
    uint64_t gc_ctl_rs1_o;
    uint64_t gc_ctl_rs2_o;
    uint8_t gc_ctl_cancel_o;
    uint8_t gc_ctl_rsp_ready_o;
} npu_issue_adapter_cycle_outputs_t;

typedef struct {
    npu_issue_adapter_state_t state;

    uint8_t funct3;
    uint64_t rs1;
    uint64_t rs2;
    uint8_t rd;

    uint64_t response_data;
    uint64_t response_cause;
    uint8_t response_exception;

    uint64_t cycle;
} npu_issue_adapter_cycle_t;

void npu_issue_adapter_cycle_reset(
    npu_issue_adapter_cycle_t *model);

void npu_issue_adapter_cycle_step(
    npu_issue_adapter_cycle_t *model,
    const npu_issue_adapter_cycle_inputs_t *inputs,
    npu_issue_adapter_cycle_outputs_t *outputs);

uint8_t npu_issue_adapter_cycle_idle(
    const npu_issue_adapter_cycle_t *model);

#ifdef __cplusplus
}
#endif

#endif
