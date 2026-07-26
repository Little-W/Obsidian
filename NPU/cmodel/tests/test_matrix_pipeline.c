#include "test_util.h"

#include <limits.h>

#define PIPELINE_L1_BYTES NPU_REF_L1_BYTES
#define PIPELINE_DDR_BYTES 4096u
#define PIPELINE_B_TILE_BYTES \
    (NPU_REF_KT * NPU_REF_NT)

static uint8_t pipeline_l1[PIPELINE_L1_BYTES];
static uint8_t pipeline_ddr[PIPELINE_DDR_BYTES];
static npu_model_t pipeline_model;

static int pipeline_init(void)
{
    npu_config_t config;

    npu_config_reference(&config);
    test_clear_bytes(pipeline_l1, sizeof(pipeline_l1));
    test_clear_bytes(pipeline_ddr, sizeof(pipeline_ddr));
    return npu_model_init(
               &pipeline_model, &config,
               pipeline_l1, sizeof(pipeline_l1),
               pipeline_ddr, sizeof(pipeline_ddr)) ==
           NPU_STATUS_SUCCESS;
}

static void pipeline_write_i32(uint64_t address, int32_t value)
{
    uint32_t raw = (uint32_t)value;

    pipeline_l1[address] = (uint8_t)(raw & 0xffu);
    pipeline_l1[address + 1u] =
        (uint8_t)((raw >> 8u) & 0xffu);
    pipeline_l1[address + 2u] =
        (uint8_t)((raw >> 16u) & 0xffu);
    pipeline_l1[address + 3u] =
        (uint8_t)((raw >> 24u) & 0xffu);
}

static int32_t pipeline_read_i32(uint64_t address)
{
    uint32_t raw =
        (uint32_t)pipeline_l1[address] |
        ((uint32_t)pipeline_l1[address + 1u] << 8u) |
        ((uint32_t)pipeline_l1[address + 2u] << 16u) |
        ((uint32_t)pipeline_l1[address + 3u] << 24u);

    if ((raw & 0x80000000u) != 0u) {
        return -1 - (int32_t)(UINT32_MAX - raw);
    }
    return (int32_t)raw;
}

static void pipeline_write_matrix_i8(
    uint64_t address,
    const int8_t values[4])
{
    uint32_t index;

    for (index = 0u; index < 4u; index++) {
        pipeline_l1[address + index] =
            (uint8_t)values[index];
    }
}

static void pipeline_write_b_tile_i8(
    uint64_t address,
    const int8_t values[4])
{
    uint32_t k;
    uint32_t n;

    test_clear_bytes(
        &pipeline_l1[address], PIPELINE_B_TILE_BYTES);
    for (k = 0u; k < 2u; k++) {
        for (n = 0u; n < 2u; n++) {
            pipeline_l1[
                address + (uint64_t)k * NPU_REF_NT + n] =
                (uint8_t)values[k * 2u + n];
        }
    }
}

static npu_task_request_t pipeline_matrix_request(
    uint16_t command_id,
    uint64_t a_address,
    uint64_t b_address,
    uint64_t c_address)
{
    npu_task_request_t request =
        test_base_request(
            NPU_ENGINE_MATRIX, NPU_MATRIX_GEMM,
            command_id);
    npu_matrix_desc_t *desc = &request.desc.matrix;

    desc->m = 2u;
    desc->n = 2u;
    desc->k = 2u;
    desc->batch_count = 1u;
    desc->a = test_tensor(
        NPU_DTYPE_INT8, a_address, 4u, 2u);
    desc->b = test_tensor(
        NPU_DTYPE_INT8, b_address,
        PIPELINE_B_TILE_BYTES, 0u);
    desc->b.batch_stride_bytes =
        PIPELINE_B_TILE_BYTES;
    desc->c = test_tensor(
        NPU_DTYPE_INT32, c_address, 16u, 8u);
    desc->b_tiled = 1u;
    desc->final_output = 1u;
    desc->round_mode = NPU_ROUND_NEAREST_EVEN;
    desc->overflow_mode = NPU_OVERFLOW_SATURATE;
    return request;
}

static int pipeline_check_i32_matrix(
    uint64_t address,
    const int32_t expected[4])
{
    uint32_t index;

    for (index = 0u; index < 4u; index++) {
        if (pipeline_read_i32(
                address + (uint64_t)index * 4u) !=
            expected[index]) {
            return 0;
        }
    }
    return 1;
}

static int pipeline_test_safe_overlap(void)
{
    static const int8_t a0[4] = {1, 2, 3, 4};
    static const int8_t b0[4] = {5, 6, 7, 8};
    static const int8_t a1[4] = {2, 0, 1, 3};
    static const int8_t b1[4] = {4, 1, 2, 5};
    static const int32_t expected0[4] = {19, 22, 43, 50};
    static const int32_t expected1[4] = {8, 2, 10, 16};
    npu_task_request_t first;
    npu_task_request_t second;
    npu_task_result_t first_result;
    npu_task_result_t second_result;

    TEST_CHECK(pipeline_init());
    pipeline_write_matrix_i8(0x000u, a0);
    pipeline_write_b_tile_i8(0x100u, b0);
    pipeline_write_matrix_i8(0x400u, a1);
    pipeline_write_b_tile_i8(0x500u, b1);
    first = pipeline_matrix_request(
        0x101u, 0x000u, 0x100u, 0x300u);
    second = pipeline_matrix_request(
        0x102u, 0x400u, 0x500u, 0x700u);

    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &first),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &second),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_run(&pipeline_model, 1000u),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x101u, 0, &first_result),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x102u, 0, &second_result),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(second_result.start_cycle <
               first_result.end_cycle);
    TEST_CHECK(
        pipeline_model.perf.matrix_overlap_cycles > 0u);
    TEST_CHECK(
        pipeline_model.perf.matrix_accum_active_cycles >=
        pipeline_model.perf.matrix_overlap_cycles);
    TEST_CHECK(
        pipeline_model.perf.matrix_mac_active_cycles >=
        pipeline_model.perf.matrix_overlap_cycles);
    TEST_CHECK(pipeline_check_i32_matrix(
        0x300u, expected0));
    TEST_CHECK(pipeline_check_i32_matrix(
        0x700u, expected1));
    return 0;
}

static int pipeline_test_raw_hazard(void)
{
    static const int8_t a0[4] = {1, 2, 3, 4};
    static const int8_t b0[4] = {5, 6, 7, 8};
    static const int8_t identity[4] = {1, 0, 0, 1};
    static const int32_t expected[4] = {19, 22, 43, 50};
    npu_task_request_t first;
    npu_task_request_t second;
    npu_task_result_t first_result;
    npu_task_result_t second_result;

    TEST_CHECK(pipeline_init());
    pipeline_write_matrix_i8(0x000u, a0);
    pipeline_write_b_tile_i8(0x100u, b0);
    pipeline_write_b_tile_i8(0x500u, identity);
    pipeline_write_i32(0x900u, 1);
    first = pipeline_matrix_request(
        0x201u, 0x000u, 0x100u, 0x300u);
    first.desc.matrix.c = test_tensor(
        NPU_DTYPE_INT8, 0x300u, 4u, 2u);
    first.desc.matrix.requant_enable = 1u;
    first.desc.matrix.requant_addr = 0x900u;
    first.desc.matrix.requant_count = 1u;
    first.desc.matrix.requant_region_bytes = 8u;
    second = pipeline_matrix_request(
        0x202u, 0x300u, 0x500u, 0x700u);

    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &first),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &second),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_run(&pipeline_model, 1000u),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x201u, 0, &first_result),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x202u, 0, &second_result),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(second_result.start_cycle >
               first_result.end_cycle);
    TEST_CHECK(
        pipeline_model.perf.matrix_hazard_stall_cycles >
        0u);
    TEST_CHECK(
        pipeline_l1[0x300u] == 19u &&
        pipeline_l1[0x301u] == 22u &&
        pipeline_l1[0x302u] == 43u &&
        pipeline_l1[0x303u] == 50u);
    TEST_CHECK(pipeline_check_i32_matrix(
        0x700u, expected));
    return 0;
}

static int pipeline_test_war_hazard(void)
{
    static const int8_t a0[4] = {1, 2, 3, 4};
    static const int8_t b0[4] = {5, 6, 7, 8};
    static const int8_t a1[4] = {1, 0, 0, 1};
    static const int8_t b1[4] = {2, 0, 0, 2};
    static const int32_t expected_first[4] = {19, 22, 43, 50};
    static const int32_t expected_second[4] = {2, 0, 0, 2};
    npu_task_request_t first;
    npu_task_request_t second;
    npu_task_result_t first_result;
    npu_task_result_t second_result;

    TEST_CHECK(pipeline_init());
    pipeline_write_matrix_i8(0x000u, a0);
    pipeline_write_b_tile_i8(0x100u, b0);
    pipeline_write_matrix_i8(0x400u, a1);
    pipeline_write_b_tile_i8(0x500u, b1);
    first = pipeline_matrix_request(
        0x211u, 0x000u, 0x100u, 0x300u);
    second = pipeline_matrix_request(
        0x212u, 0x400u, 0x500u, 0x000u);

    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &first),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &second),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_run(&pipeline_model, 1000u),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x211u, 0, &first_result),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x212u, 0, &second_result),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(second_result.start_cycle <
               first_result.end_cycle);
    TEST_CHECK(
        pipeline_model.perf.matrix_overlap_cycles > 0u);
    TEST_CHECK(
        pipeline_model.perf.matrix_hazard_stall_cycles ==
        0u);
    TEST_CHECK(pipeline_check_i32_matrix(
        0x300u, expected_first));
    TEST_CHECK(pipeline_check_i32_matrix(
        0x000u, expected_second));
    return 0;
}

static int pipeline_test_waw_hazard(void)
{
    static const int8_t a1[4] = {1, 0, 0, 1};
    static const int8_t b1[4] = {2, 0, 0, 2};
    static const int32_t expected[4] = {2, 0, 0, 2};
    npu_task_request_t first;
    npu_task_request_t second;
    npu_task_result_t first_result;
    npu_task_result_t second_result;
    npu_task_slot_t *mac_slot;
    npu_task_slot_t *accum_slot;
    uint64_t mac_before;
    uint64_t overlap_before;
    uint32_t index;
    int saw_accum_wait = 0;

    TEST_CHECK(pipeline_init());
    pipeline_write_matrix_i8(0x400u, a1);
    pipeline_write_b_tile_i8(0x500u, b1);
    first = pipeline_matrix_request(
        0x221u, 0x000u, 0x100u, 0x1000u);
    first.cmd.opcode = NPU_MATRIX_GEMM_ZERO;
    first.desc.matrix.m = 16u;
    first.desc.matrix.n = 16u;
    first.desc.matrix.k = 0u;
    first.desc.matrix.c = test_tensor(
        NPU_DTYPE_INT32, 0x1000u, 1024u, 64u);
    first.desc.matrix.final_output = 0u;
    second = pipeline_matrix_request(
        0x222u, 0x400u, 0x500u, 0x1000u);
    for (index = 0u; index < 1024u; index++) {
        pipeline_l1[0x1000u + index] = 0x5au;
    }

    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &first),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &second),
        NPU_STATUS_SUCCESS);
    for (index = 0u; index < 1000u; index++) {
        if (pipeline_model.matrix_accum_slot >= 0 &&
            pipeline_model.active_slot[NPU_ENGINE_MATRIX] >= 0) {
            accum_slot = &pipeline_model.tasks[
                (uint32_t)pipeline_model.matrix_accum_slot];
            mac_slot = &pipeline_model.tasks[
                (uint32_t)pipeline_model
                    .active_slot[NPU_ENGINE_MATRIX]];
            if (accum_slot->request.cmd.command_id == 0x221u &&
                mac_slot->request.cmd.command_id == 0x222u &&
                mac_slot->remaining_cycles == 0u) {
                mac_before =
                    pipeline_model.perf
                        .matrix_mac_active_cycles;
                overlap_before =
                    pipeline_model.perf
                        .matrix_overlap_cycles;
                npu_model_step(&pipeline_model, 1u);
                TEST_CHECK(
                    pipeline_model.perf
                        .matrix_mac_active_cycles ==
                    mac_before);
                TEST_CHECK(
                    pipeline_model.perf
                        .matrix_overlap_cycles ==
                    overlap_before);
                saw_accum_wait = 1;
                break;
            }
        }
        npu_model_step(&pipeline_model, 1u);
    }
    TEST_CHECK(saw_accum_wait != 0);
    TEST_CHECK_STATUS(
        npu_model_run(&pipeline_model, 1000u),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x221u, 0, &first_result),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x222u, 0, &second_result),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(second_result.start_cycle <
               first_result.end_cycle);
    TEST_CHECK(
        pipeline_model.perf.matrix_overlap_cycles > 0u);
    TEST_CHECK(
        pipeline_model.perf.matrix_hazard_stall_cycles ==
        0u);
    TEST_CHECK(pipeline_check_i32_matrix(
        0x1000u, expected));
    TEST_CHECK(pipeline_read_i32(0x1010u) == 0);
    return 0;
}

static int pipeline_test_event_and_ordered(void)
{
    static const int8_t a0[4] = {1, 2, 3, 4};
    static const int8_t b0[4] = {5, 6, 7, 8};
    static const int8_t a1[4] = {1, 0, 0, 1};
    static const int8_t b1[4] = {2, 0, 0, 2};
    npu_task_request_t first;
    npu_task_request_t second;
    npu_task_result_t first_result;
    npu_task_result_t second_result;
    npu_event_ref_t event;

    TEST_CHECK(pipeline_init());
    pipeline_write_matrix_i8(0x000u, a0);
    pipeline_write_b_tile_i8(0x100u, b0);
    pipeline_write_matrix_i8(0x400u, a1);
    pipeline_write_b_tile_i8(0x500u, b1);
    first = pipeline_matrix_request(
        0x231u, 0x000u, 0x100u, 0x300u);
    second = pipeline_matrix_request(
        0x232u, 0x400u, 0x500u, 0x700u);
    event.id = 7u;
    event.generation = 0u;
    first.cmd.signal_event = event;
    second.cmd.wait_event[0] = event;

    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &first),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &second),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_run(&pipeline_model, 1000u),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x231u, 0, &first_result),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x232u, 0, &second_result),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(second_result.start_cycle >
               first_result.end_cycle);

    TEST_CHECK(pipeline_init());
    pipeline_write_matrix_i8(0x000u, a0);
    pipeline_write_b_tile_i8(0x100u, b0);
    pipeline_write_matrix_i8(0x400u, a1);
    pipeline_write_b_tile_i8(0x500u, b1);
    first = pipeline_matrix_request(
        0x241u, 0x000u, 0x100u, 0x300u);
    second = pipeline_matrix_request(
        0x242u, 0x400u, 0x500u, 0x700u);
    second.cmd.header_flags |= (uint16_t)(1u << 4u);

    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &first),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &second),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_run(&pipeline_model, 1000u),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x241u, 0, &first_result),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x242u, 0, &second_result),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(second_result.start_cycle >
               first_result.end_cycle);
    TEST_CHECK(
        pipeline_model.perf.matrix_overlap_cycles == 0u);
    return 0;
}

static int pipeline_test_accum_timeout(void)
{
    static const int8_t a[4] = {1, 2, 3, 4};
    static const int8_t b[4] = {5, 6, 7, 8};
    npu_task_request_t request;
    npu_task_result_t result;
    npu_task_slot_t *slot;
    uint64_t elapsed;
    uint32_t steps;

    TEST_CHECK(pipeline_init());
    pipeline_write_matrix_i8(0x000u, a);
    pipeline_write_b_tile_i8(0x100u, b);
    request = pipeline_matrix_request(
        0x301u, 0x000u, 0x100u, 0x300u);
    request.cmd.timeout_class = 1u;
    pipeline_model.config.timeout_cycles[1] =
        UINT32_MAX;
    TEST_CHECK_STATUS(
        npu_model_submit(&pipeline_model, &request),
        NPU_STATUS_SUCCESS);

    for (steps = 0u;
         steps < 1000u &&
         pipeline_model.matrix_accum_slot < 0;
         steps++) {
        npu_model_step(&pipeline_model, 1u);
    }
    TEST_CHECK(pipeline_model.matrix_accum_slot >= 0);
    slot = &pipeline_model.tasks[
        (uint32_t)pipeline_model.matrix_accum_slot];
    TEST_CHECK(slot->matrix_in_accum != 0u);
    TEST_CHECK(slot->remaining_cycles > 1u);
    elapsed =
        pipeline_model.cycle - slot->result.start_cycle;
    TEST_CHECK(elapsed <= UINT32_MAX);
    pipeline_model.config.timeout_cycles[1] =
        (uint32_t)elapsed;

    npu_model_step(&pipeline_model, 1u);
    TEST_CHECK_STATUS(
        npu_model_query(
            &pipeline_model, 0x301u, 0, &result),
        NPU_STATUS_TIMEOUT);
    TEST_CHECK(pipeline_model.matrix_accum_slot < 0);
    TEST_CHECK(
        pipeline_model.active_slot[NPU_ENGINE_MATRIX] < 0);
    TEST_CHECK(
        pipeline_model.perf.matrix_accum_active_cycles >
        0u);
    TEST_CHECK(
        pipeline_read_i32(0x300u) == 0);
    return 0;
}

int test_matrix_pipeline(void)
{
    int line;

    line = pipeline_test_safe_overlap();
    if (line != 0) {
        return line;
    }
    line = pipeline_test_raw_hazard();
    if (line != 0) {
        return line;
    }
    line = pipeline_test_war_hazard();
    if (line != 0) {
        return line;
    }
    line = pipeline_test_waw_hazard();
    if (line != 0) {
        return line;
    }
    line = pipeline_test_event_and_ordered();
    if (line != 0) {
        return line;
    }
    return pipeline_test_accum_timeout();
}
