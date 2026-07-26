#include "npu_issue_adapter_cycle.h"
#include "test_util.h"

#include <string.h>

static void issue_test_inputs_default(
    npu_issue_adapter_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = 1u;
    inputs->issue_opcode_i = NPU_ISSUE_CUSTOM0_OPCODE;
    inputs->issue_funct7_i = 0u;
    inputs->dsa_permission_i = 1u;
    inputs->dsa_enable_i = 1u;
}

static int issue_test_accept(
    npu_issue_adapter_cycle_t *model,
    npu_issue_adapter_cycle_inputs_t *inputs,
    npu_issue_adapter_cycle_outputs_t *outputs,
    uint8_t funct3,
    uint64_t rs1,
    uint64_t rs2,
    uint8_t rd)
{
    inputs->issue_valid_i = 1u;
    inputs->issue_funct3_i = funct3;
    inputs->issue_rs1_i = rs1;
    inputs->issue_rs2_i = rs2;
    inputs->issue_rd_i = rd;
    npu_issue_adapter_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->issue_ready_o != 0u);
    inputs->issue_valid_i = 0u;
    return 0;
}

static int issue_test_complete_core_response(
    npu_issue_adapter_cycle_t *model,
    npu_issue_adapter_cycle_inputs_t *inputs,
    npu_issue_adapter_cycle_outputs_t *outputs,
    uint64_t expected_data,
    uint8_t expected_rd)
{
    uint64_t held_data;
    uint8_t held_rd;

    inputs->issue_rsp_ready_i = 0u;
    npu_issue_adapter_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->issue_rsp_valid_o != 0u);
    TEST_CHECK(outputs->issue_rsp_exception_o == 0u);
    TEST_CHECK(outputs->issue_rsp_data_o == expected_data);
    TEST_CHECK(outputs->issue_rsp_rd_o == expected_rd);
    TEST_CHECK(outputs->issue_rsp_cause_o == 0u);
    TEST_CHECK(outputs->issue_ready_o == 0u);
    held_data = outputs->issue_rsp_data_o;
    held_rd = outputs->issue_rsp_rd_o;

    inputs->gc_rsp_data_i ^= UINT64_C(0xffff);
    inputs->gc_ctl_rsp_data_i ^= UINT64_C(0xffff);
    npu_issue_adapter_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->issue_rsp_valid_o != 0u);
    TEST_CHECK(outputs->issue_rsp_data_o == held_data);
    TEST_CHECK(outputs->issue_rsp_rd_o == held_rd);
    TEST_CHECK(model->state == NPU_ISSUE_STATE_CORE_RESPONSE);

    inputs->issue_rsp_ready_i = 1u;
    npu_issue_adapter_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->issue_rsp_valid_o != 0u);
    TEST_CHECK(model->state == NPU_ISSUE_STATE_IDLE);
    inputs->issue_rsp_ready_i = 0u;
    return 0;
}

static int issue_test_reset(void)
{
    npu_issue_adapter_cycle_t model;
    npu_issue_adapter_cycle_inputs_t inputs;
    npu_issue_adapter_cycle_outputs_t outputs;
    int result;

    npu_issue_adapter_cycle_reset(&model);
    issue_test_inputs_default(&inputs);
    inputs.reset_n = 0u;
    inputs.issue_valid_i = 1u;
    inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_SUBMIT;
    inputs.gc_cmd_ready_i = 1u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o == 0u);
    TEST_CHECK(outputs.issue_rsp_valid_o == 0u);
    TEST_CHECK(outputs.gc_cmd_valid_o == 0u);
    TEST_CHECK(outputs.gc_ctl_valid_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_IDLE);
    TEST_CHECK(model.cycle == 0u);

    issue_test_inputs_default(&inputs);
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o != 0u);
    TEST_CHECK(outputs.issue_busy_o == 0u);

    result = issue_test_accept(
        &model, &inputs, &outputs,
        NPU_ISSUE_FUNCT3_SUBMIT,
        UINT64_C(0x1122334455667788),
        UINT64_C(0x99aabbccddeeff00), 4u);
    TEST_CHECK(result == 0);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_SUBMIT_LOW);

    inputs.reset_n = 0u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_cmd_valid_o == 0u);
    TEST_CHECK(outputs.issue_rsp_valid_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_IDLE);
    TEST_CHECK(model.rs1 == 0u);
    TEST_CHECK(model.rs2 == 0u);
    TEST_CHECK(model.cycle == 0u);

    issue_test_inputs_default(&inputs);
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o != 0u);
    TEST_CHECK(outputs.gc_cmd_valid_o == 0u);
    return 0;
}

static int issue_test_illegal_requests(void)
{
    npu_issue_adapter_cycle_t model;
    npu_issue_adapter_cycle_inputs_t inputs;
    npu_issue_adapter_cycle_outputs_t outputs;
    uint8_t test_index;

    for (test_index = 0u; test_index < 5u; test_index++) {
        npu_issue_adapter_cycle_reset(&model);
        issue_test_inputs_default(&inputs);
        inputs.issue_valid_i = 1u;
        inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_SUBMIT;
        inputs.issue_rd_i = 31u;
        if (test_index == 0u) {
            inputs.issue_opcode_i = 0x33u;
        } else if (test_index == 1u) {
            inputs.issue_funct7_i = 1u;
        } else if (test_index == 2u) {
            inputs.issue_funct3_i = 4u;
        } else if (test_index == 3u) {
            inputs.dsa_permission_i = 0u;
        } else {
            inputs.dsa_enable_i = 0u;
        }

        npu_issue_adapter_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.issue_ready_o != 0u);
        TEST_CHECK(outputs.gc_cmd_valid_o == 0u);
        TEST_CHECK(outputs.gc_ctl_valid_o == 0u);
        TEST_CHECK(model.state ==
                   NPU_ISSUE_STATE_CORE_RESPONSE);

        inputs.issue_valid_i = 0u;
        inputs.issue_rsp_ready_i = 0u;
        npu_issue_adapter_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.issue_rsp_valid_o != 0u);
        TEST_CHECK(outputs.issue_rsp_exception_o != 0u);
        TEST_CHECK(outputs.issue_rsp_cause_o ==
                   NPU_ISSUE_ILLEGAL_INSTRUCTION_CAUSE);
        TEST_CHECK(outputs.issue_rsp_rd_o == 31u);
        TEST_CHECK(outputs.issue_rsp_data_o == 0u);
        TEST_CHECK(outputs.gc_cmd_valid_o == 0u);
        TEST_CHECK(outputs.gc_ctl_valid_o == 0u);

        inputs.issue_rsp_ready_i = 1u;
        npu_issue_adapter_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.issue_rsp_valid_o != 0u);
        TEST_CHECK(model.state == NPU_ISSUE_STATE_IDLE);
    }
    return 0;
}

static int issue_test_quiesce(void)
{
    npu_issue_adapter_cycle_t model;
    npu_issue_adapter_cycle_inputs_t inputs;
    npu_issue_adapter_cycle_outputs_t outputs;

    npu_issue_adapter_cycle_reset(&model);
    issue_test_inputs_default(&inputs);
    inputs.issue_quiesce_i = 1u;
    inputs.issue_valid_i = 1u;
    inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_SUBMIT;
    inputs.issue_rs1_i = UINT64_C(0x1122);
    inputs.issue_rs2_i = UINT64_C(0x3344);
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_IDLE);

    inputs.issue_quiesce_i = 0u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o != 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_SUBMIT_LOW);

    inputs.issue_quiesce_i = 1u;
    inputs.issue_valid_i = 0u;
    inputs.gc_cmd_ready_i = 1u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_cmd_valid_o != 0u);
    TEST_CHECK(outputs.gc_cmd_data_o == UINT64_C(0x1122));
    TEST_CHECK(outputs.gc_cmd_first_o != 0u);
    TEST_CHECK(outputs.gc_cmd_last_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_SUBMIT_HIGH);

    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_cmd_valid_o != 0u);
    TEST_CHECK(outputs.gc_cmd_data_o == UINT64_C(0x3344));
    TEST_CHECK(outputs.gc_cmd_first_o == 0u);
    TEST_CHECK(outputs.gc_cmd_last_o != 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_SUBMIT_RESPONSE);

    npu_issue_adapter_cycle_reset(&model);
    issue_test_inputs_default(&inputs);
    inputs.issue_quiesce_i = 1u;
    inputs.issue_valid_i = 1u;
    inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_WAIT;
    inputs.cpu_cancel_i = 1u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o == 0u);
    TEST_CHECK(outputs.issue_canceled_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_IDLE);
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_canceled_o == 0u);

    inputs.issue_quiesce_i = 0u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o != 0u);
    TEST_CHECK(outputs.issue_canceled_o != 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_IDLE);
    return 0;
}

static int issue_test_submit_command_and_response(void)
{
    const uint64_t command_low = UINT64_C(0x0123456789abcdef);
    const uint64_t command_high =
        UINT64_C(0xfedcba9876543210);
    const uint64_t response = UINT64_C(0x0000000007a55123);
    npu_issue_adapter_cycle_t model;
    npu_issue_adapter_cycle_inputs_t inputs;
    npu_issue_adapter_cycle_outputs_t outputs;
    uint64_t held_data;
    int result;

    npu_issue_adapter_cycle_reset(&model);
    issue_test_inputs_default(&inputs);
    result = issue_test_accept(
        &model, &inputs, &outputs,
        NPU_ISSUE_FUNCT3_SUBMIT,
        command_low, command_high, 17u);
    TEST_CHECK(result == 0);

    inputs.issue_valid_i = 1u;
    inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_QUERY;
    inputs.issue_rs1_i = UINT64_C(0xaaaaaaaaaaaaaaaa);
    inputs.issue_rs2_i = UINT64_C(0xbbbbbbbbbbbbbbbb);
    inputs.issue_rd_i = 2u;
    inputs.gc_cmd_ready_i = 0u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o == 0u);
    TEST_CHECK(outputs.issue_busy_o != 0u);
    TEST_CHECK(outputs.gc_cmd_valid_o != 0u);
    TEST_CHECK(outputs.gc_cmd_data_o == command_low);
    TEST_CHECK(outputs.gc_cmd_first_o != 0u);
    TEST_CHECK(outputs.gc_cmd_last_o == 0u);
    held_data = outputs.gc_cmd_data_o;

    inputs.issue_rs1_i = 0u;
    inputs.issue_rs2_i = 0u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_cmd_valid_o != 0u);
    TEST_CHECK(outputs.gc_cmd_data_o == held_data);
    TEST_CHECK(outputs.gc_cmd_first_o != 0u);
    TEST_CHECK(outputs.gc_cmd_last_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_SUBMIT_LOW);

    inputs.gc_cmd_ready_i = 1u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_cmd_data_o == command_low);
    TEST_CHECK(outputs.gc_cmd_first_o != 0u);
    TEST_CHECK(outputs.gc_cmd_last_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_SUBMIT_HIGH);

    inputs.gc_cmd_ready_i = 0u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_cmd_valid_o != 0u);
    TEST_CHECK(outputs.gc_cmd_data_o == command_high);
    TEST_CHECK(outputs.gc_cmd_first_o == 0u);
    TEST_CHECK(outputs.gc_cmd_last_o != 0u);
    held_data = outputs.gc_cmd_data_o;

    inputs.issue_rs1_i = UINT64_MAX;
    inputs.issue_rs2_i = 0u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_cmd_valid_o != 0u);
    TEST_CHECK(outputs.gc_cmd_data_o == held_data);
    TEST_CHECK(outputs.gc_cmd_first_o == 0u);
    TEST_CHECK(outputs.gc_cmd_last_o != 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_SUBMIT_HIGH);

    inputs.gc_cmd_ready_i = 1u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_cmd_data_o == command_high);
    TEST_CHECK(outputs.gc_cmd_first_o == 0u);
    TEST_CHECK(outputs.gc_cmd_last_o != 0u);
    TEST_CHECK(model.state ==
               NPU_ISSUE_STATE_SUBMIT_RESPONSE);

    inputs.gc_cmd_ready_i = 0u;
    inputs.gc_rsp_valid_i = 0u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_cmd_valid_o == 0u);
    TEST_CHECK(outputs.gc_rsp_ready_o != 0u);
    TEST_CHECK(model.state ==
               NPU_ISSUE_STATE_SUBMIT_RESPONSE);

    inputs.gc_rsp_valid_i = 1u;
    inputs.gc_rsp_data_i = response;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_rsp_ready_o != 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_CORE_RESPONSE);
    inputs.gc_rsp_valid_i = 0u;

    result = issue_test_complete_core_response(
        &model, &inputs, &outputs, response, 17u);
    TEST_CHECK(result == 0);

    inputs.issue_valid_i = 0u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o != 0u);
    TEST_CHECK(outputs.gc_cmd_valid_o == 0u);
    TEST_CHECK(outputs.gc_ctl_valid_o == 0u);
    return 0;
}

static int issue_test_control_requests(void)
{
    static const uint8_t funct3[] = {
        NPU_ISSUE_FUNCT3_WAIT,
        NPU_ISSUE_FUNCT3_QUERY,
        NPU_ISSUE_FUNCT3_FENCE
    };
    static const uint8_t op[] = {
        NPU_ISSUE_CTL_WAIT,
        NPU_ISSUE_CTL_QUERY,
        NPU_ISSUE_CTL_FENCE
    };
    npu_issue_adapter_cycle_t model;
    npu_issue_adapter_cycle_inputs_t inputs;
    npu_issue_adapter_cycle_outputs_t outputs;
    uint64_t rs1;
    uint64_t rs2;
    uint64_t response;
    uint8_t index;
    int result;

    for (index = 0u; index < 3u; index++) {
        rs1 = UINT64_C(0x1000) + index;
        rs2 = UINT64_C(0x2000) + index;
        response = UINT64_C(0x3000) + index;
        npu_issue_adapter_cycle_reset(&model);
        issue_test_inputs_default(&inputs);
        result = issue_test_accept(
            &model, &inputs, &outputs,
            funct3[index], rs1, rs2,
            (uint8_t)(8u + index));
        TEST_CHECK(result == 0);

        inputs.gc_ctl_ready_i = 0u;
        npu_issue_adapter_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.issue_ready_o == 0u);
        TEST_CHECK(outputs.gc_ctl_valid_o != 0u);
        TEST_CHECK(outputs.gc_ctl_op_o == op[index]);
        TEST_CHECK(outputs.gc_ctl_rs1_o == rs1);
        TEST_CHECK(outputs.gc_ctl_rs2_o == rs2);
        TEST_CHECK(outputs.gc_cmd_valid_o == 0u);

        inputs.issue_rs1_i ^= UINT64_MAX;
        inputs.issue_rs2_i ^= UINT64_MAX;
        npu_issue_adapter_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.gc_ctl_valid_o != 0u);
        TEST_CHECK(outputs.gc_ctl_op_o == op[index]);
        TEST_CHECK(outputs.gc_ctl_rs1_o == rs1);
        TEST_CHECK(outputs.gc_ctl_rs2_o == rs2);

        inputs.gc_ctl_ready_i = 1u;
        npu_issue_adapter_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.gc_ctl_valid_o != 0u);
        TEST_CHECK(model.state ==
                   NPU_ISSUE_STATE_CONTROL_RESPONSE);

        inputs.gc_ctl_rsp_valid_i = 0u;
        npu_issue_adapter_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.gc_ctl_rsp_ready_o != 0u);
        TEST_CHECK(model.state ==
                   NPU_ISSUE_STATE_CONTROL_RESPONSE);

        inputs.gc_ctl_rsp_valid_i = 1u;
        inputs.gc_ctl_rsp_data_i = response;
        npu_issue_adapter_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.gc_ctl_rsp_ready_o != 0u);
        TEST_CHECK(model.state ==
                   NPU_ISSUE_STATE_CORE_RESPONSE);
        inputs.gc_ctl_rsp_valid_i = 0u;

        result = issue_test_complete_core_response(
            &model, &inputs, &outputs, response,
            (uint8_t)(8u + index));
        TEST_CHECK(result == 0);
    }
    return 0;
}

static int issue_test_cancel(void)
{
    npu_issue_adapter_cycle_t model;
    npu_issue_adapter_cycle_inputs_t inputs;
    npu_issue_adapter_cycle_outputs_t outputs;
    int result;

    npu_issue_adapter_cycle_reset(&model);
    issue_test_inputs_default(&inputs);
    inputs.cpu_cancel_i = 1u;
    result = issue_test_accept(
        &model, &inputs, &outputs,
        NPU_ISSUE_FUNCT3_WAIT, 1u, 20u, 3u);
    TEST_CHECK(result == 0);
    TEST_CHECK(outputs.issue_canceled_o != 0u);
    TEST_CHECK(outputs.gc_ctl_valid_o == 0u);
    TEST_CHECK(outputs.gc_ctl_cancel_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_IDLE);

    inputs.cpu_cancel_i = 0u;
    result = issue_test_accept(
        &model, &inputs, &outputs,
        NPU_ISSUE_FUNCT3_WAIT, 2u, 21u, 4u);
    TEST_CHECK(result == 0);
    TEST_CHECK(model.state ==
               NPU_ISSUE_STATE_CONTROL_REQUEST);
    inputs.cpu_cancel_i = 1u;
    inputs.gc_ctl_ready_i = 1u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_canceled_o != 0u);
    TEST_CHECK(outputs.gc_ctl_valid_o == 0u);
    TEST_CHECK(outputs.gc_ctl_cancel_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_IDLE);

    inputs.cpu_cancel_i = 0u;
    result = issue_test_accept(
        &model, &inputs, &outputs,
        NPU_ISSUE_FUNCT3_FENCE, 0x0fu, 22u, 5u);
    TEST_CHECK(result == 0);
    inputs.gc_ctl_ready_i = 1u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_ctl_valid_o != 0u);
    TEST_CHECK(model.state ==
               NPU_ISSUE_STATE_CONTROL_RESPONSE);

    inputs.cpu_cancel_i = 1u;
    inputs.gc_ctl_rsp_valid_i = 0u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_ctl_rsp_ready_o != 0u);
    TEST_CHECK(outputs.gc_ctl_cancel_o != 0u);
    TEST_CHECK(outputs.issue_canceled_o != 0u);
    TEST_CHECK(outputs.issue_rsp_valid_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_IDLE);

    inputs.cpu_cancel_i = 0u;
    result = issue_test_accept(
        &model, &inputs, &outputs,
        NPU_ISSUE_FUNCT3_QUERY, 0x123u, 0u, 6u);
    TEST_CHECK(result == 0);
    inputs.gc_ctl_ready_i = 1u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.state ==
               NPU_ISSUE_STATE_CONTROL_RESPONSE);
    inputs.cpu_cancel_i = 1u;
    inputs.gc_ctl_rsp_valid_i = 0u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_ctl_cancel_o == 0u);
    TEST_CHECK(outputs.issue_canceled_o == 0u);
    TEST_CHECK(model.state ==
               NPU_ISSUE_STATE_CONTROL_RESPONSE);
    inputs.gc_ctl_rsp_valid_i = 1u;
    inputs.gc_ctl_rsp_data_i = UINT64_C(0x12345678);
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_ctl_cancel_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_CORE_RESPONSE);
    inputs.gc_ctl_rsp_valid_i = 0u;
    inputs.cpu_cancel_i = 0u;
    result = issue_test_complete_core_response(
        &model, &inputs, &outputs,
        UINT64_C(0x12345678), 6u);
    TEST_CHECK(result == 0);

    result = issue_test_accept(
        &model, &inputs, &outputs,
        NPU_ISSUE_FUNCT3_WAIT, 3u, 30u, 7u);
    TEST_CHECK(result == 0);
    inputs.gc_ctl_ready_i = 1u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.state ==
               NPU_ISSUE_STATE_CONTROL_RESPONSE);
    inputs.cpu_cancel_i = 1u;
    inputs.gc_ctl_rsp_valid_i = 1u;
    inputs.gc_ctl_rsp_data_i = UINT64_C(0xa5a5);
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.gc_ctl_cancel_o == 0u);
    TEST_CHECK(outputs.issue_canceled_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_CORE_RESPONSE);
    inputs.cpu_cancel_i = 0u;
    inputs.gc_ctl_rsp_valid_i = 0u;
    result = issue_test_complete_core_response(
        &model, &inputs, &outputs, UINT64_C(0xa5a5), 7u);
    TEST_CHECK(result == 0);
    return 0;
}

static int issue_test_serial_requests(void)
{
    npu_issue_adapter_cycle_t model;
    npu_issue_adapter_cycle_inputs_t inputs;
    npu_issue_adapter_cycle_outputs_t outputs;
    int result;

    npu_issue_adapter_cycle_reset(&model);
    issue_test_inputs_default(&inputs);
    result = issue_test_accept(
        &model, &inputs, &outputs,
        NPU_ISSUE_FUNCT3_QUERY, 0x100u, 0u, 10u);
    TEST_CHECK(result == 0);

    inputs.issue_valid_i = 1u;
    inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_FENCE;
    inputs.issue_rs1_i = 0x0fu;
    inputs.issue_rs2_i = 100u;
    inputs.issue_rd_i = 11u;
    inputs.gc_ctl_ready_i = 1u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o == 0u);
    TEST_CHECK(outputs.gc_ctl_op_o == NPU_ISSUE_CTL_QUERY);
    TEST_CHECK(model.funct3 == NPU_ISSUE_FUNCT3_QUERY);

    inputs.gc_ctl_rsp_valid_i = 1u;
    inputs.gc_ctl_rsp_data_i = UINT64_C(0x1111);
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o == 0u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_CORE_RESPONSE);

    inputs.gc_ctl_rsp_valid_i = 0u;
    inputs.issue_rsp_ready_i = 1u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o == 0u);
    TEST_CHECK(outputs.issue_rsp_valid_o != 0u);
    TEST_CHECK(outputs.issue_rsp_rd_o == 10u);
    TEST_CHECK(model.state == NPU_ISSUE_STATE_IDLE);

    inputs.issue_rsp_ready_i = 0u;
    npu_issue_adapter_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.issue_ready_o != 0u);
    TEST_CHECK(model.state ==
               NPU_ISSUE_STATE_CONTROL_REQUEST);
    TEST_CHECK(model.funct3 == NPU_ISSUE_FUNCT3_FENCE);
    TEST_CHECK(model.rd == 11u);
    return 0;
}

int test_issue_adapter_cycle(void)
{
    int result;

    result = issue_test_reset();
    if (result != 0) {
        return result;
    }
    result = issue_test_illegal_requests();
    if (result != 0) {
        return result;
    }
    result = issue_test_quiesce();
    if (result != 0) {
        return result;
    }
    result = issue_test_submit_command_and_response();
    if (result != 0) {
        return result;
    }
    result = issue_test_control_requests();
    if (result != 0) {
        return result;
    }
    result = issue_test_cancel();
    if (result != 0) {
        return result;
    }
    return issue_test_serial_requests();
}
