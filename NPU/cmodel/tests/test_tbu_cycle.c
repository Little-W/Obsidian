#include "npu_tbu_cycle.h"
#include "test_util.h"

static npu_tbu_rule_t tbu_test_rule(uint64_t vaddr,
                                    uint64_t paddr,
                                    uint16_t stream_id,
                                    uint16_t substream_id,
                                    uint8_t read_enable,
                                    uint8_t write_enable)
{
    npu_tbu_rule_t rule = {0};

    rule.valid = 1u;
    rule.virtual_page = vaddr >> 12u;
    rule.physical_page = (uint32_t)(paddr >> 12u);
    rule.stream_id = stream_id;
    rule.substream_id = substream_id;
    rule.read_enable = read_enable;
    rule.write_enable = write_enable;
    return rule;
}

static npu_tbu_cycle_inputs_t tbu_test_inputs(void)
{
    npu_tbu_cycle_inputs_t inputs = {0};

    inputs.reset_n = 1u;
    return inputs;
}

static int tbu_test_wait_response(npu_tbu_cycle_t *model,
                                  npu_tbu_cycle_inputs_t *inputs,
                                  uint32_t cycles,
                                  npu_tbu_cycle_outputs_t *outputs)
{
    uint32_t cycle;


    for (cycle = 0u; cycle < cycles; cycle++) {
        npu_tbu_cycle_step(model, inputs, outputs);
        TEST_CHECK(outputs->rsp_valid == 0u);
    }
    npu_tbu_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->rsp_valid != 0u);
    return 0;
}

static int tbu_test_hit_and_hold(void)
{
    npu_tbu_cycle_t model;
    npu_tbu_cycle_inputs_t inputs = tbu_test_inputs();
    npu_tbu_cycle_outputs_t outputs;
    npu_tbu_rule_t rule =
        tbu_test_rule(
            UINT64_C(0x12345000),
            UINT64_C(0x0abcde000), 7u, 9u, 1u, 1u);
    uint64_t held_paddr;
    uint16_t held_tag;
    uint8_t held_status;
    uint32_t cycle;
    int line;

    npu_tbu_cycle_init(&model);
    TEST_CHECK(npu_tbu_cycle_set_rule(&model, 0u, &rule));
    npu_tbu_cycle_eval(&model, &inputs, &outputs);
    TEST_CHECK(outputs.req_ready != 0u);
    TEST_CHECK(outputs.idle != 0u);

    inputs.req_valid = 1u;
    inputs.req_vaddr = UINT64_C(0x12345678);
    inputs.req_stream_id = 7u;
    inputs.req_substream_id = 9u;
    inputs.req_tag = 0x1234u;
    npu_tbu_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.req_ready != 0u);
    TEST_CHECK(outputs.rsp_valid == 0u);
    inputs.req_valid = 0u;

    line = tbu_test_wait_response(
        &model, &inputs, NPU_TBU_HIT_LATENCY, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(outputs.rsp_paddr == UINT64_C(0x0abcde678));
    TEST_CHECK(outputs.rsp_tag == 0x1234u);
    TEST_CHECK(outputs.rsp_status == NPU_STATUS_SUCCESS);
    held_paddr = outputs.rsp_paddr;
    held_tag = outputs.rsp_tag;
    held_status = outputs.rsp_status;

    for (cycle = 0u; cycle < 5u; cycle++) {
        npu_tbu_cycle_step(&model, &inputs, &outputs);
        TEST_CHECK(outputs.rsp_valid != 0u);
        TEST_CHECK(outputs.rsp_paddr == held_paddr);
        TEST_CHECK(outputs.rsp_tag == held_tag);
        TEST_CHECK(outputs.rsp_status == held_status);
    }
    inputs.rsp_ready = 1u;
    npu_tbu_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.rsp_valid != 0u);
    inputs.rsp_ready = 0u;
    npu_tbu_cycle_eval(&model, &inputs, &outputs);
    TEST_CHECK(outputs.rsp_valid == 0u);
    TEST_CHECK(outputs.idle != 0u);
    return 0;
}

static int tbu_test_permission_and_miss(void)
{
    npu_tbu_cycle_t model;
    npu_tbu_cycle_inputs_t inputs = tbu_test_inputs();
    npu_tbu_cycle_outputs_t outputs;
    npu_tbu_rule_t rule =
        tbu_test_rule(
            UINT64_C(0x2000), UINT64_C(0x8000),
            1u, 2u, 1u, 0u);
    int line;

    npu_tbu_cycle_init(&model);
    TEST_CHECK(npu_tbu_cycle_set_rule(&model, 0u, &rule));

    inputs.req_valid = 1u;
    inputs.req_vaddr = UINT64_C(0x2345);
    inputs.req_write = 1u;
    inputs.req_stream_id = 1u;
    inputs.req_substream_id = 2u;
    inputs.req_tag = 3u;
    npu_tbu_cycle_step(&model, &inputs, &outputs);
    inputs.req_valid = 0u;
    line = tbu_test_wait_response(
        &model, &inputs, NPU_TBU_HIT_LATENCY, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(outputs.rsp_status == NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(outputs.rsp_paddr == 0u);
    inputs.rsp_ready = 1u;
    npu_tbu_cycle_step(&model, &inputs, &outputs);
    inputs.rsp_ready = 0u;

    inputs.req_valid = 1u;
    inputs.req_vaddr = UINT64_C(0x3000);
    inputs.req_write = 0u;
    inputs.req_stream_id = 1u;
    inputs.req_substream_id = 2u;
    inputs.req_tag = 4u;
    npu_tbu_cycle_step(&model, &inputs, &outputs);
    inputs.req_valid = 0u;
    line = tbu_test_wait_response(
        &model, &inputs, NPU_TBU_MISS_LATENCY, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(outputs.rsp_status == NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(outputs.rsp_tag == 4u);
    return 0;
}

static int tbu_test_capacity_order_and_reset(void)
{
    npu_tbu_cycle_t model;
    npu_tbu_cycle_inputs_t inputs = tbu_test_inputs();
    npu_tbu_cycle_outputs_t outputs;
    npu_tbu_rule_t rule;
    uint32_t request;

    npu_tbu_cycle_init(&model);
    for (request = 0u; request < NPU_TBU_OUTSTANDING;
         request++) {
        rule = tbu_test_rule(
            UINT64_C(0x100000) +
                (uint64_t)request * UINT64_C(0x1000),
            UINT64_C(0x200000) +
                (uint64_t)request * UINT64_C(0x1000),
            5u, 6u, 1u, 1u);
        TEST_CHECK(npu_tbu_cycle_set_rule(
            &model, (uint8_t)request, &rule));
    }

    for (request = 0u; request < NPU_TBU_OUTSTANDING;
         request++) {
        inputs.req_valid = 1u;
        inputs.req_vaddr =
            UINT64_C(0x100000) +
            (uint64_t)request * UINT64_C(0x1000);
        inputs.req_stream_id = 5u;
        inputs.req_substream_id = 6u;
        inputs.req_tag = (uint16_t)(0x100u + request);
        npu_tbu_cycle_step(&model, &inputs, &outputs);
        TEST_CHECK(outputs.req_ready != 0u);
    }
    npu_tbu_cycle_eval(&model, &inputs, &outputs);
    TEST_CHECK(outputs.outstanding == NPU_TBU_OUTSTANDING);
    TEST_CHECK(outputs.req_ready == 0u);
    TEST_CHECK(!npu_tbu_cycle_set_rule(&model, 10u, &rule));
    inputs.req_valid = 0u;

    inputs.rsp_ready = 1u;
    for (request = 0u; request < NPU_TBU_OUTSTANDING;
         request++) {
        npu_tbu_cycle_step(&model, &inputs, &outputs);
        TEST_CHECK(outputs.rsp_valid != 0u);
        TEST_CHECK(outputs.rsp_tag ==
                   (uint16_t)(0x100u + request));
    }
    inputs.rsp_ready = 0u;
    npu_tbu_cycle_eval(&model, &inputs, &outputs);
    TEST_CHECK(outputs.idle != 0u);

    inputs.req_valid = 1u;
    inputs.req_vaddr = UINT64_C(0x100000);
    inputs.req_stream_id = 5u;
    inputs.req_substream_id = 6u;
    inputs.req_tag = 0x222u;
    npu_tbu_cycle_step(&model, &inputs, &outputs);
    inputs.req_valid = 0u;
    inputs.reset_n = 0u;
    npu_tbu_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.req_ready == 0u);
    TEST_CHECK(outputs.idle != 0u);
    inputs.reset_n = 1u;
    npu_tbu_cycle_eval(&model, &inputs, &outputs);
    TEST_CHECK(outputs.req_ready != 0u);

    inputs.req_valid = 1u;
    npu_tbu_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.req_ready != 0u);
    return 0;
}

static int tbu_test_invalid_fields(void)
{
    npu_tbu_cycle_t model;
    npu_tbu_cycle_inputs_t inputs = tbu_test_inputs();
    npu_tbu_cycle_outputs_t outputs;
    int line;

    npu_tbu_cycle_init(&model);
    inputs.req_valid = 1u;
    inputs.req_vaddr = UINT64_C(0x1000000000000);
    inputs.req_tag = 0xc001u;
    npu_tbu_cycle_step(&model, &inputs, &outputs);
    inputs.req_valid = 0u;
    line = tbu_test_wait_response(
        &model, &inputs, NPU_TBU_HIT_LATENCY, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(outputs.rsp_status == NPU_STATUS_BAD_DESC);
    TEST_CHECK(outputs.rsp_tag == 1u);
    return 0;
}

int test_tbu_cycle(void)
{
    int line;

    line = tbu_test_hit_and_hold();
    if (line != 0) {
        return line;
    }
    line = tbu_test_permission_and_miss();
    if (line != 0) {
        return line;
    }
    line = tbu_test_capacity_order_and_reset();
    if (line != 0) {
        return line;
    }
    line = tbu_test_invalid_fields();
    if (line != 0) {
        return line;
    }
    return 0;
}
