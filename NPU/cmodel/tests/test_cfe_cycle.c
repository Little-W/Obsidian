#include "npu_cfe_cycle.h"

#include <string.h>

#ifdef NPU_CFE_CYCLE_STANDALONE
#include <stdio.h>
#endif

#define CFE_TEST_CHECK(condition)   \
    do {                            \
        if (!(condition)) {         \
            return __LINE__;        \
        }                           \
    } while (0)

#define CFE_TEST_EVENT_NONE UINT64_C(0x0fff)

static void cfe_test_command(uint16_t command_id,
                             uint64_t *low,
                             uint64_t *high)
{
    const uint64_t desc_addr = UINT64_C(0x400);
    const uint8_t engine = (uint8_t)NPU_ENGINE_CONTROL;
    const uint8_t opcode = (uint8_t)NPU_CTRL_NOP;

    *low = (desc_addr & UINT64_C(0x0000ffffffffffff)) |
           ((uint64_t)(command_id & UINT16_C(0x0fff))
            << 48u) |
           ((uint64_t)(engine & UINT8_C(0x0f)) << 60u);
    *high = (uint64_t)opcode |
            (CFE_TEST_EVENT_NONE << 20u) |
            (CFE_TEST_EVENT_NONE << 32u) |
            (CFE_TEST_EVENT_NONE << 44u) |
            (UINT64_C(1) << 56u);
}

static void cfe_test_inputs_default(
    npu_cfe_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = 1u;
    inputs->gc_rsp_ready_i = 1u;
    inputs->ts_cmd_ready_i = 1u;
    inputs->cmd_id_lookup_ready_i = 1u;
}

static uint16_t cfe_test_response_id(uint64_t response)
{
    return (uint16_t)(response & UINT64_C(0x0fff));
}

static uint8_t cfe_test_response_status(uint64_t response)
{
    return (uint8_t)((response >> 12u) & UINT64_C(0xff));
}

static uint8_t cfe_test_response_free(uint64_t response)
{
    return (uint8_t)((response >> 20u) & UINT64_C(0xff));
}

static int cfe_test_submit(
    npu_cfe_cycle_t *model,
    uint64_t low,
    uint64_t high,
    uint8_t scheduler_busy,
    uint8_t ts_ready,
    uint64_t *response)
{
    npu_cfe_cycle_inputs_t inputs;
    npu_cfe_cycle_outputs_t outputs;

    CFE_TEST_CHECK(model->state == NPU_CFE_STATE_IDLE);
    cfe_test_inputs_default(&inputs);
    inputs.ts_cmd_ready_i = ts_ready;
    inputs.gc_cmd_valid_i = 1u;
    inputs.gc_cmd_data_i = low;
    inputs.gc_cmd_first_i = 1u;
    inputs.gc_cmd_last_i = 0u;
    npu_cfe_cycle_step(model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_cmd_ready_o != 0u);
    CFE_TEST_CHECK(model->state == NPU_CFE_STATE_WAIT_HI);
    CFE_TEST_CHECK(model->low_beat == low);

    inputs.gc_cmd_data_i = high;
    inputs.gc_cmd_first_i = 0u;
    inputs.gc_cmd_last_i = 1u;
    npu_cfe_cycle_step(model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_cmd_ready_o != 0u);
    CFE_TEST_CHECK(model->state == NPU_CFE_STATE_CHECK);
    CFE_TEST_CHECK(model->high_beat == high);

    inputs.gc_cmd_valid_i = 0u;
    npu_cfe_cycle_step(model, &inputs, &outputs);
    CFE_TEST_CHECK(model->state == NPU_CFE_STATE_LOOKUP_ID);

    npu_cfe_cycle_step(model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.cmd_id_lookup_valid_o != 0u);
    CFE_TEST_CHECK(outputs.cmd_id_lookup_id_o ==
                   (uint16_t)((low >> 48u) & 0x0fffu));
    CFE_TEST_CHECK(model->lookup_request_sent != 0u);

    inputs.cmd_id_lookup_rsp_valid_i = 1u;
    inputs.cmd_id_busy_i = scheduler_busy;
    npu_cfe_cycle_step(model, &inputs, &outputs);
    inputs.cmd_id_lookup_rsp_valid_i = 0u;

    if (scheduler_busy != 0u ||
        model->local_duplicate != 0u) {
        CFE_TEST_CHECK(model->state == NPU_CFE_STATE_RESP_ERR);
    } else {
        CFE_TEST_CHECK(model->state == NPU_CFE_STATE_ENQUEUE);
        npu_cfe_cycle_step(model, &inputs, &outputs);
        CFE_TEST_CHECK(model->state == NPU_CFE_STATE_RESP_OK);
    }

    npu_cfe_cycle_step(model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_rsp_valid_o != 0u);
    if (response != (uint64_t *)0) {
        *response = outputs.gc_rsp_data_o;
    }
    CFE_TEST_CHECK(model->state == NPU_CFE_STATE_IDLE);
    return 0;
}

static int cfe_test_reset_and_two_beat_forward(void)
{
    npu_cfe_cycle_t model;
    npu_cfe_cycle_inputs_t inputs;
    npu_cfe_cycle_outputs_t outputs;
    uint64_t low;
    uint64_t high;
    uint64_t response = 0u;
    int result;

    cfe_test_command(0x123u, &low, &high);
    npu_cfe_cycle_reset(&model);
    cfe_test_inputs_default(&inputs);
    inputs.reset_n = 0u;
    inputs.gc_cmd_valid_i = 1u;
    inputs.gc_cmd_data_i = low;
    inputs.gc_cmd_first_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_cmd_ready_o == 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_valid_o == 0u);
    CFE_TEST_CHECK(outputs.cfe_idle_o != 0u);
    CFE_TEST_CHECK(model.cycle == 0u);

    result = cfe_test_submit(
        &model, low, high, 0u, 0u, &response);
    CFE_TEST_CHECK(result == 0);
    CFE_TEST_CHECK(cfe_test_response_id(response) == 0x123u);
    CFE_TEST_CHECK(cfe_test_response_status(response) ==
                   NPU_STATUS_SUCCESS);
    CFE_TEST_CHECK(cfe_test_response_free(response) == 7u);
    CFE_TEST_CHECK(model.fifo_count == 1u);

    cfe_test_inputs_default(&inputs);
    inputs.ts_cmd_ready_i = 0u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.ts_cmd_valid_o != 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_data_o == low);
    CFE_TEST_CHECK(outputs.ts_cmd_first_o != 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_last_o == 0u);

    inputs.ts_cmd_ready_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.ts_cmd_valid_o != 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_data_o == low);
    CFE_TEST_CHECK(outputs.ts_cmd_first_o != 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_last_o == 0u);
    CFE_TEST_CHECK(model.fifo_count == 1u);

    inputs.ts_cmd_ready_i = 0u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.ts_cmd_valid_o != 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_data_o == high);
    CFE_TEST_CHECK(outputs.ts_cmd_first_o == 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_last_o != 0u);

    inputs.ts_cmd_ready_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.ts_cmd_valid_o != 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_data_o == high);
    CFE_TEST_CHECK(outputs.ts_cmd_first_o == 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_last_o != 0u);
    CFE_TEST_CHECK(model.fifo_count == 0u);

    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.ts_cmd_valid_o == 0u);
    CFE_TEST_CHECK(outputs.cfe_idle_o != 0u);
    return 0;
}

static int cfe_test_fifo_full_and_local_duplicate(void)
{
    npu_cfe_cycle_t model;
    npu_cfe_cycle_inputs_t inputs;
    npu_cfe_cycle_outputs_t outputs;
    uint64_t lows[NPU_CFE_CYCLE_FIFO_DEPTH];
    uint64_t highs[NPU_CFE_CYCLE_FIFO_DEPTH];
    uint64_t extra_low;
    uint64_t extra_high;
    uint64_t response = 0u;
    uint8_t index;
    int result;

    npu_cfe_cycle_reset(&model);
    for (index = 0u;
         index < NPU_CFE_CYCLE_FIFO_DEPTH;
         index++) {
        cfe_test_command(
            (uint16_t)(0x200u + index),
            &lows[index], &highs[index]);
        result = cfe_test_submit(
            &model, lows[index], highs[index],
            0u, 0u, &response);
        CFE_TEST_CHECK(result == 0);
        CFE_TEST_CHECK(cfe_test_response_status(response) ==
                       NPU_STATUS_SUCCESS);
    }
    CFE_TEST_CHECK(model.fifo_count ==
                   NPU_CFE_CYCLE_FIFO_DEPTH);

    cfe_test_command(0x300u, &extra_low, &extra_high);
    cfe_test_inputs_default(&inputs);
    inputs.ts_cmd_ready_i = 0u;
    inputs.gc_cmd_valid_i = 1u;
    inputs.gc_cmd_data_i = extra_low;
    inputs.gc_cmd_first_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_cmd_ready_o == 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_valid_o != 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_data_o == lows[0]);
    CFE_TEST_CHECK(outputs.ts_cmd_first_o != 0u);

    inputs.gc_cmd_valid_i = 0u;
    inputs.ts_cmd_ready_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(model.fifo_count ==
                   NPU_CFE_CYCLE_FIFO_DEPTH);
    CFE_TEST_CHECK(model.ts_output_beat == 1u);

    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.ts_cmd_data_o == highs[0]);
    CFE_TEST_CHECK(outputs.ts_cmd_first_o == 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_last_o != 0u);
    CFE_TEST_CHECK(model.fifo_count ==
                   NPU_CFE_CYCLE_FIFO_DEPTH - 1u);

    inputs.ts_cmd_ready_i = 0u;
    result = cfe_test_submit(
        &model, lows[1], highs[1],
        0u, 0u, &response);
    CFE_TEST_CHECK(result == 0);
    CFE_TEST_CHECK(cfe_test_response_status(response) ==
                   NPU_STATUS_BUSY);
    CFE_TEST_CHECK(model.fifo_count ==
                   NPU_CFE_CYCLE_FIFO_DEPTH - 1u);
    return 0;
}

static int cfe_test_lookup_pause_and_scheduler_busy(void)
{
    npu_cfe_cycle_t model;
    npu_cfe_cycle_inputs_t inputs;
    npu_cfe_cycle_outputs_t outputs;
    uint64_t low;
    uint64_t high;
    uint64_t response;

    cfe_test_command(0x345u, &low, &high);
    npu_cfe_cycle_reset(&model);
    cfe_test_inputs_default(&inputs);
    inputs.ts_cmd_ready_i = 0u;
    inputs.gc_cmd_valid_i = 1u;
    inputs.gc_cmd_data_i = low;
    inputs.gc_cmd_first_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    inputs.gc_cmd_data_i = high;
    inputs.gc_cmd_first_i = 0u;
    inputs.gc_cmd_last_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    inputs.gc_cmd_valid_i = 0u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_LOOKUP_ID);

    inputs.cmd_id_lookup_ready_i = 0u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.cmd_id_lookup_valid_o != 0u);
    CFE_TEST_CHECK(model.lookup_request_sent == 0u);
    inputs.cmd_id_lookup_ready_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(model.lookup_request_sent != 0u);

    inputs.cmd_id_lookup_rsp_valid_i = 1u;
    inputs.cmd_id_busy_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_RESP_ERR);
    inputs.cmd_id_lookup_rsp_valid_i = 0u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_rsp_valid_o != 0u);
    response = outputs.gc_rsp_data_o;
    CFE_TEST_CHECK(cfe_test_response_id(response) == 0x345u);
    CFE_TEST_CHECK(cfe_test_response_status(response) ==
                   NPU_STATUS_BUSY);
    CFE_TEST_CHECK(model.fifo_count == 0u);
    return 0;
}

static int cfe_test_bad_header_and_response_hold(void)
{
    npu_cfe_cycle_t model;
    npu_cfe_cycle_inputs_t inputs;
    npu_cfe_cycle_outputs_t outputs;
    uint64_t low;
    uint64_t high;
    uint64_t held_response;

    cfe_test_command(0x456u, &low, &high);
    high &= UINT64_C(0x00ffffffffffffff);
    high |= UINT64_C(2) << 56u;
    npu_cfe_cycle_reset(&model);
    cfe_test_inputs_default(&inputs);
    inputs.gc_rsp_ready_i = 0u;
    inputs.gc_cmd_valid_i = 1u;
    inputs.gc_cmd_data_i = low;
    inputs.gc_cmd_first_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    inputs.gc_cmd_data_i = high;
    inputs.gc_cmd_first_i = 0u;
    inputs.gc_cmd_last_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    inputs.gc_cmd_valid_i = 0u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_RESP_ERR);

    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_rsp_valid_o != 0u);
    CFE_TEST_CHECK(outputs.cfe_error_o != 0u);
    CFE_TEST_CHECK(cfe_test_response_status(
                       outputs.gc_rsp_data_o) ==
                   NPU_STATUS_BAD_DESC);
    held_response = outputs.gc_rsp_data_o;

    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_rsp_valid_o != 0u);
    CFE_TEST_CHECK(outputs.gc_rsp_data_o == held_response);
    CFE_TEST_CHECK(outputs.cfe_error_o == 0u);

    inputs.gc_rsp_ready_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_IDLE);
    return 0;
}

static int cfe_test_frame_errors_and_second_beat_timeout(void)
{
    npu_cfe_cycle_t model;
    npu_cfe_cycle_inputs_t inputs;
    npu_cfe_cycle_outputs_t outputs;
    uint64_t low;
    uint64_t high;
    uint32_t cycle;

    cfe_test_command(0x678u, &low, &high);
    npu_cfe_cycle_reset(&model);
    cfe_test_inputs_default(&inputs);

    inputs.gc_cmd_valid_i = 1u;
    inputs.gc_cmd_data_i = low;
    inputs.gc_cmd_first_i = 0u;
    inputs.gc_cmd_last_i = 0u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_RESP_ERR);
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_rsp_valid_o != 0u);
    CFE_TEST_CHECK(cfe_test_response_status(
                       outputs.gc_rsp_data_o) ==
                   NPU_STATUS_BAD_DESC);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_IDLE);

    inputs.gc_cmd_data_i = low;
    inputs.gc_cmd_first_i = 1u;
    inputs.gc_cmd_last_i = 0u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_WAIT_HI);
    inputs.gc_cmd_data_i = high;
    inputs.gc_cmd_first_i = 1u;
    inputs.gc_cmd_last_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_RESP_ERR);
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(cfe_test_response_status(
                       outputs.gc_rsp_data_o) ==
                   NPU_STATUS_BAD_DESC);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_IDLE);

    inputs.gc_cmd_data_i = low;
    inputs.gc_cmd_first_i = 1u;
    inputs.gc_cmd_last_i = 0u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_WAIT_HI);
    inputs.gc_cmd_valid_i = 0u;
    for (cycle = 0u;
         cycle < NPU_CFE_CYCLE_BEAT_TIMEOUT;
         cycle++) {
        npu_cfe_cycle_step(&model, &inputs, &outputs);
        CFE_TEST_CHECK(model.state == NPU_CFE_STATE_WAIT_HI);
        CFE_TEST_CHECK(outputs.gc_cmd_ready_o != 0u);
    }
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_cmd_ready_o == 0u);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_RESP_ERR);
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_rsp_valid_o != 0u);
    CFE_TEST_CHECK(outputs.cfe_error_o != 0u);
    CFE_TEST_CHECK(cfe_test_response_id(
                       outputs.gc_rsp_data_o) == 0x678u);
    CFE_TEST_CHECK(cfe_test_response_status(
                       outputs.gc_rsp_data_o) ==
                   NPU_STATUS_TIMEOUT);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_IDLE);
    return 0;
}

static int cfe_test_quiesce_and_reset(void)
{
    npu_cfe_cycle_t model;
    npu_cfe_cycle_inputs_t inputs;
    npu_cfe_cycle_outputs_t outputs;
    uint64_t low;
    uint64_t high;

    cfe_test_command(0x567u, &low, &high);
    npu_cfe_cycle_reset(&model);
    cfe_test_inputs_default(&inputs);
    inputs.cfe_quiesce_i = 1u;
    inputs.gc_cmd_valid_i = 1u;
    inputs.gc_cmd_data_i = low;
    inputs.gc_cmd_first_i = 1u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_cmd_ready_o == 0u);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_IDLE);

    inputs.cfe_quiesce_i = 0u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_cmd_ready_o != 0u);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_WAIT_HI);

    inputs.reset_n = 0u;
    npu_cfe_cycle_step(&model, &inputs, &outputs);
    CFE_TEST_CHECK(outputs.gc_cmd_ready_o == 0u);
    CFE_TEST_CHECK(outputs.gc_rsp_valid_o == 0u);
    CFE_TEST_CHECK(outputs.ts_cmd_valid_o == 0u);
    CFE_TEST_CHECK(outputs.cfe_idle_o != 0u);
    CFE_TEST_CHECK(model.state == NPU_CFE_STATE_IDLE);
    CFE_TEST_CHECK(model.low_beat == 0u);
    CFE_TEST_CHECK(model.high_beat == 0u);
    CFE_TEST_CHECK(model.fifo_count == 0u);
    CFE_TEST_CHECK(model.cycle == 0u);
    return 0;
}

int test_cfe_cycle(void)
{
    int result;

    result = cfe_test_reset_and_two_beat_forward();
    if (result != 0) {
        return result;
    }
    result = cfe_test_fifo_full_and_local_duplicate();
    if (result != 0) {
        return result;
    }
    result = cfe_test_lookup_pause_and_scheduler_busy();
    if (result != 0) {
        return result;
    }
    result = cfe_test_bad_header_and_response_hold();
    if (result != 0) {
        return result;
    }
    result = cfe_test_frame_errors_and_second_beat_timeout();
    if (result != 0) {
        return result;
    }
    return cfe_test_quiesce_and_reset();
}

#ifdef NPU_CFE_CYCLE_STANDALONE
int main(void)
{
    int result = test_cfe_cycle();

    if (result != 0) {
        (void)fprintf(stderr,
                      "test_cfe_cycle failed at line %d\n",
                      result);
        return 1;
    }
    (void)puts("test_cfe_cycle passed");
    return 0;
}
#endif
