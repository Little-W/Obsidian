#include "npu_issue_adapter_cycle.h"

#include <string.h>

static uint8_t npu_issue_adapter_encoding_valid(
    const npu_issue_adapter_cycle_inputs_t *inputs)
{
    if (inputs->issue_opcode_i != NPU_ISSUE_CUSTOM0_OPCODE ||
        inputs->issue_funct7_i != 0u ||
        inputs->issue_funct3_i >
            (uint8_t)NPU_ISSUE_FUNCT3_FENCE) {
        return 0u;
    }
    if (inputs->dsa_enable_i == 0u ||
        inputs->dsa_permission_i == 0u) {
        return 0u;
    }
    return 1u;
}

static uint8_t npu_issue_adapter_cancelable(uint8_t funct3)
{
    return funct3 == (uint8_t)NPU_ISSUE_FUNCT3_WAIT ||
                   funct3 == (uint8_t)NPU_ISSUE_FUNCT3_FENCE
               ? 1u
               : 0u;
}

static uint8_t npu_issue_adapter_control_op(uint8_t funct3)
{
    if (funct3 == (uint8_t)NPU_ISSUE_FUNCT3_WAIT) {
        return (uint8_t)NPU_ISSUE_CTL_WAIT;
    }
    if (funct3 == (uint8_t)NPU_ISSUE_FUNCT3_QUERY) {
        return (uint8_t)NPU_ISSUE_CTL_QUERY;
    }
    return (uint8_t)NPU_ISSUE_CTL_FENCE;
}

uint8_t npu_issue_adapter_cycle_idle(
    const npu_issue_adapter_cycle_t *model)
{
    if (model == (const npu_issue_adapter_cycle_t *)0) {
        return 0u;
    }
    return model->state == NPU_ISSUE_STATE_IDLE ? 1u : 0u;
}

void npu_issue_adapter_cycle_reset(
    npu_issue_adapter_cycle_t *model)
{
    if (model == (npu_issue_adapter_cycle_t *)0) {
        return;
    }
    (void)memset(model, 0, sizeof(*model));
    model->state = NPU_ISSUE_STATE_IDLE;
}

static void npu_issue_adapter_fill_outputs(
    const npu_issue_adapter_cycle_t *model,
    const npu_issue_adapter_cycle_inputs_t *inputs,
    npu_issue_adapter_cycle_outputs_t *outputs)
{
    uint8_t cancelable =
        npu_issue_adapter_cancelable(model->funct3);

    (void)memset(outputs, 0, sizeof(*outputs));
    outputs->issue_busy_o =
        model->state == NPU_ISSUE_STATE_IDLE ? 0u : 1u;

    switch (model->state) {
    case NPU_ISSUE_STATE_IDLE:
        outputs->issue_ready_o =
            inputs->issue_quiesce_i == 0u ? 1u : 0u;
        if (inputs->issue_valid_i != 0u &&
            outputs->issue_ready_o != 0u &&
            npu_issue_adapter_encoding_valid(inputs) != 0u &&
            npu_issue_adapter_cancelable(
                inputs->issue_funct3_i) != 0u &&
            inputs->cpu_cancel_i != 0u) {
            outputs->issue_canceled_o = 1u;
        }
        break;

    case NPU_ISSUE_STATE_SUBMIT_LOW:
        outputs->gc_cmd_valid_o = 1u;
        outputs->gc_cmd_data_o = model->rs1;
        outputs->gc_cmd_first_o = 1u;
        outputs->gc_cmd_last_o = 0u;
        break;

    case NPU_ISSUE_STATE_SUBMIT_HIGH:
        outputs->gc_cmd_valid_o = 1u;
        outputs->gc_cmd_data_o = model->rs2;
        outputs->gc_cmd_first_o = 0u;
        outputs->gc_cmd_last_o = 1u;
        break;

    case NPU_ISSUE_STATE_SUBMIT_RESPONSE:
        outputs->gc_rsp_ready_o = 1u;
        break;

    case NPU_ISSUE_STATE_CONTROL_REQUEST:
        if (cancelable != 0u &&
            inputs->cpu_cancel_i != 0u) {
            outputs->issue_canceled_o = 1u;
        } else {
            outputs->gc_ctl_valid_o = 1u;
            outputs->gc_ctl_op_o =
                npu_issue_adapter_control_op(model->funct3);
            outputs->gc_ctl_rs1_o = model->rs1;
            outputs->gc_ctl_rs2_o = model->rs2;
        }
        break;

    case NPU_ISSUE_STATE_CONTROL_RESPONSE:
        outputs->gc_ctl_rsp_ready_o = 1u;
        if (cancelable != 0u &&
            inputs->cpu_cancel_i != 0u &&
            inputs->gc_ctl_rsp_valid_i == 0u) {
            outputs->gc_ctl_cancel_o = 1u;
            outputs->issue_canceled_o = 1u;
        }
        break;

    case NPU_ISSUE_STATE_CORE_RESPONSE:
        outputs->issue_rsp_valid_o = 1u;
        outputs->issue_rsp_rd_o = model->rd;
        outputs->issue_rsp_data_o = model->response_data;
        outputs->issue_rsp_exception_o =
            model->response_exception;
        outputs->issue_rsp_cause_o = model->response_cause;
        break;

    default:
        break;
    }
}

static void npu_issue_adapter_latch_request(
    npu_issue_adapter_cycle_t *model,
    const npu_issue_adapter_cycle_inputs_t *inputs)
{
    model->funct3 = inputs->issue_funct3_i;
    model->rs1 = inputs->issue_rs1_i;
    model->rs2 = inputs->issue_rs2_i;
    model->rd = (uint8_t)(inputs->issue_rd_i & 0x1fu);
    model->response_data = 0u;
    model->response_cause = 0u;
    model->response_exception = 0u;
}

static void npu_issue_adapter_finish_response(
    npu_issue_adapter_cycle_t *model,
    uint64_t data)
{
    model->response_data = data;
    model->response_cause = 0u;
    model->response_exception = 0u;
    model->state = NPU_ISSUE_STATE_CORE_RESPONSE;
}

void npu_issue_adapter_cycle_step(
    npu_issue_adapter_cycle_t *model,
    const npu_issue_adapter_cycle_inputs_t *inputs,
    npu_issue_adapter_cycle_outputs_t *outputs)
{
    uint8_t issue_handshake;
    uint8_t command_handshake;
    uint8_t control_handshake;
    uint8_t response_handshake;
    uint8_t cancelable;

    if (model == (npu_issue_adapter_cycle_t *)0 ||
        inputs == (const npu_issue_adapter_cycle_inputs_t *)0 ||
        outputs == (npu_issue_adapter_cycle_outputs_t *)0) {
        return;
    }

    if (inputs->reset_n == 0u) {
        npu_issue_adapter_cycle_reset(model);
        (void)memset(outputs, 0, sizeof(*outputs));
        return;
    }

    npu_issue_adapter_fill_outputs(model, inputs, outputs);
    issue_handshake =
        inputs->issue_valid_i != 0u &&
                outputs->issue_ready_o != 0u
            ? 1u
            : 0u;
    command_handshake =
        outputs->gc_cmd_valid_o != 0u &&
                inputs->gc_cmd_ready_i != 0u
            ? 1u
            : 0u;
    control_handshake =
        outputs->gc_ctl_valid_o != 0u &&
                inputs->gc_ctl_ready_i != 0u
            ? 1u
            : 0u;
    response_handshake =
        outputs->issue_rsp_valid_o != 0u &&
                inputs->issue_rsp_ready_i != 0u
            ? 1u
            : 0u;
    cancelable = npu_issue_adapter_cancelable(model->funct3);

    switch (model->state) {
    case NPU_ISSUE_STATE_IDLE:
        if (issue_handshake != 0u) {
            npu_issue_adapter_latch_request(model, inputs);
            if (npu_issue_adapter_encoding_valid(inputs) == 0u) {
                model->response_data = 0u;
                model->response_cause =
                    NPU_ISSUE_ILLEGAL_INSTRUCTION_CAUSE;
                model->response_exception = 1u;
                model->state = NPU_ISSUE_STATE_CORE_RESPONSE;
            } else if (
                npu_issue_adapter_cancelable(
                    inputs->issue_funct3_i) != 0u &&
                inputs->cpu_cancel_i != 0u) {
                model->state = NPU_ISSUE_STATE_IDLE;
            } else if (
                inputs->issue_funct3_i ==
                (uint8_t)NPU_ISSUE_FUNCT3_SUBMIT) {
                model->state = NPU_ISSUE_STATE_SUBMIT_LOW;
            } else {
                model->state =
                    NPU_ISSUE_STATE_CONTROL_REQUEST;
            }
        }
        break;

    case NPU_ISSUE_STATE_SUBMIT_LOW:
        if (command_handshake != 0u) {
            model->state = NPU_ISSUE_STATE_SUBMIT_HIGH;
        }
        break;

    case NPU_ISSUE_STATE_SUBMIT_HIGH:
        if (command_handshake != 0u) {
            model->state =
                NPU_ISSUE_STATE_SUBMIT_RESPONSE;
        }
        break;

    case NPU_ISSUE_STATE_SUBMIT_RESPONSE:
        if (inputs->gc_rsp_valid_i != 0u &&
            outputs->gc_rsp_ready_o != 0u) {
            npu_issue_adapter_finish_response(
                model, inputs->gc_rsp_data_i);
        }
        break;

    case NPU_ISSUE_STATE_CONTROL_REQUEST:
        if (cancelable != 0u &&
            inputs->cpu_cancel_i != 0u) {
            model->state = NPU_ISSUE_STATE_IDLE;
        } else if (control_handshake != 0u) {
            model->state =
                NPU_ISSUE_STATE_CONTROL_RESPONSE;
        }
        break;

    case NPU_ISSUE_STATE_CONTROL_RESPONSE:
        if (inputs->gc_ctl_rsp_valid_i != 0u &&
            outputs->gc_ctl_rsp_ready_o != 0u) {
            npu_issue_adapter_finish_response(
                model, inputs->gc_ctl_rsp_data_i);
        } else if (cancelable != 0u &&
                   inputs->cpu_cancel_i != 0u) {
            model->state = NPU_ISSUE_STATE_IDLE;
        }
        break;

    case NPU_ISSUE_STATE_CORE_RESPONSE:
        if (response_handshake != 0u) {
            model->state = NPU_ISSUE_STATE_IDLE;
        }
        break;

    default:
        npu_issue_adapter_cycle_reset(model);
        break;
    }

    model->cycle++;
}
