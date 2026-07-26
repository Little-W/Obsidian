#include "npu_wire.h"
#include "test_util.h"

#include <stdint.h>

#define E2E_MEMORY_BYTES (64u * 1024u)

#define E2E_DDR_INPUT_ADDR 0x0800u
#define E2E_DMA_DESC_ADDR 0x1000u
#define E2E_MATRIX_DESC_ADDR 0x1200u
#define E2E_VECTOR_DESC_ADDR 0x1400u
#define E2E_COMPLEX_DESC_ADDR 0x1600u
#define E2E_CONTROL_DESC_ADDR 0x1800u

#define E2E_L1_A_ADDR 0x0100u
#define E2E_L1_B_ADDR 0x0200u
#define E2E_L1_MATRIX_DST_ADDR 0x0300u
#define E2E_L1_VECTOR_SRC1_ADDR 0x0380u
#define E2E_L1_VECTOR_DST_ADDR 0x0400u
#define E2E_L1_COMPLEX_DST_ADDR 0x0500u
#define E2E_L1_SRC_SCALE_ADDR 0x0600u
#define E2E_L1_DST_SCALE_ADDR 0x0604u

#define E2E_EVENT_NONE 0x0fffu
#define E2E_EVENT_DMA_DONE 21u
#define E2E_EVENT_MATRIX_DONE 22u
#define E2E_EVENT_VECTOR_DONE 23u

static uint8_t e2e_l1[E2E_MEMORY_BYTES];
static uint8_t e2e_ddr[E2E_MEMORY_BYTES];
static npu_model_t e2e_model;

static void e2e_zero(uint8_t *memory, size_t bytes)
{
    size_t offset;

    for (offset = 0u; offset < bytes; offset++) {
        memory[offset] = 0u;
    }
}

static void e2e_put_u16(uint8_t *memory,
                        size_t offset,
                        uint16_t value)
{
    memory[offset] = (uint8_t)value;
    memory[offset + 1u] = (uint8_t)(value >> 8);
}

static void e2e_put_u32(uint8_t *memory,
                        size_t offset,
                        uint32_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 4u; byte++) {
        memory[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static void e2e_put_u64(uint8_t *memory,
                        size_t offset,
                        uint64_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        memory[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static uint32_t e2e_get_u32(const uint8_t *memory, size_t offset)
{
    return (uint32_t)memory[offset] |
           ((uint32_t)memory[offset + 1u] << 8) |
           ((uint32_t)memory[offset + 2u] << 16) |
           ((uint32_t)memory[offset + 3u] << 24);
}

static uint16_t e2e_event(uint8_t id, uint8_t generation)
{
    return (uint16_t)(((uint16_t)(generation & 0x0fu) << 8) | id);
}

static uint32_t e2e_numeric(npu_dtype_t src0,
                            npu_dtype_t src1,
                            npu_dtype_t src2,
                            npu_dtype_t dst,
                            npu_round_mode_t round_mode,
                            uint8_t saturate,
                            uint8_t scale_mode,
                            uint8_t zero_point_enable,
                            uint8_t internal_fp32)
{
    return (uint32_t)src0 |
           ((uint32_t)src1 << 2) |
           ((uint32_t)src2 << 4) |
           ((uint32_t)dst << 6) |
           ((uint32_t)round_mode << 10) |
           ((uint32_t)(saturate & 1u) << 12) |
           ((uint32_t)(scale_mode & 3u) << 13) |
           ((uint32_t)(zero_point_enable & 1u) << 15) |
           ((uint32_t)(internal_fp32 & 1u) << 16);
}

static void e2e_make_common(uint8_t *descriptor,
                            size_t descriptor_bytes,
                            npu_engine_t engine,
                            uint32_t op_flags,
                            uint64_t src0_addr,
                            uint64_t src1_addr,
                            uint64_t src2_addr,
                            uint64_t dst_addr,
                            uint64_t aux0_addr,
                            uint64_t aux1_addr,
                            uint32_t numeric_cfg,
                            uint32_t user_tag)
{
    e2e_zero(descriptor, descriptor_bytes);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = (uint8_t)engine;
    e2e_put_u16(descriptor, 0x02u, (uint16_t)descriptor_bytes);
    e2e_put_u32(descriptor, 0x04u, op_flags);
    e2e_put_u64(descriptor, 0x08u, src0_addr);
    e2e_put_u64(descriptor, 0x10u, src1_addr);
    e2e_put_u64(descriptor, 0x18u, src2_addr);
    e2e_put_u64(descriptor, 0x20u, dst_addr);
    e2e_put_u64(descriptor, 0x28u, aux0_addr);
    e2e_put_u64(descriptor, 0x30u, aux1_addr);
    e2e_put_u32(descriptor, 0x38u, numeric_cfg);
    e2e_put_u32(descriptor, 0x3cu, user_tag);
}

static void e2e_make_cmd(uint64_t descriptor_addr,
                         uint16_t command_id,
                         npu_engine_t engine,
                         uint8_t opcode,
                         uint16_t header_flags,
                         uint16_t wait0,
                         uint16_t wait1,
                         uint16_t signal,
                         uint64_t *low_beat,
                         uint64_t *high_beat)
{
    *low_beat =
        (descriptor_addr & UINT64_C(0x0000ffffffffffff)) |
        ((uint64_t)(command_id & 0x0fffu) << 48u) |
        ((uint64_t)((uint8_t)engine & 0x0fu) << 60u);
    *high_beat =
        (uint64_t)opcode |
        ((uint64_t)(header_flags & 0x0fffu) << 8u) |
        ((uint64_t)(wait0 & 0x0fffu) << 20u) |
        ((uint64_t)(wait1 & 0x0fffu) << 32u) |
        ((uint64_t)(signal & 0x0fffu) << 44u) |
        ((uint64_t)NPU_WIRE_HEADER_VERSION << 56u);
}

static int e2e_init(void)
{
    npu_config_t config;

    e2e_zero(e2e_l1, sizeof(e2e_l1));
    e2e_zero(e2e_ddr, sizeof(e2e_ddr));
    npu_config_reference(&config);
    config.l1_bytes = E2E_MEMORY_BYTES;
    return npu_model_init(&e2e_model, &config,
                          e2e_l1, sizeof(e2e_l1),
                          e2e_ddr, sizeof(e2e_ddr)) ==
           NPU_STATUS_SUCCESS;
}

static const npu_task_request_t *e2e_find_request(uint16_t command_id)
{
    uint32_t slot;

    for (slot = 0u; slot < e2e_model.config.task_entries; slot++) {
        if (e2e_model.tasks[slot].state != NPU_TASK_FREE &&
            e2e_model.tasks[slot].request.cmd.command_id == command_id) {
            return &e2e_model.tasks[slot].request;
        }
    }
    return (const npu_task_request_t *)0;
}

static void e2e_idle_inputs(npu_host_inputs_t *inputs)
{
    e2e_zero((uint8_t *)inputs, sizeof(*inputs));
    inputs->core_reset_n = 1u;
    inputs->noc_reset_n = 1u;
}

static int e2e_check_response(uint16_t command_id,
                              npu_status_t expected_status,
                              uint32_t hold_cycles,
                              uint64_t *response_value)
{
    npu_host_inputs_t inputs;
    npu_host_outputs_t outputs;
    uint64_t response;
    uint32_t cycle;

    e2e_idle_inputs(&inputs);
    inputs.cmd_rsp_ready = 0u;
    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_rsp_valid == 1u);
    TEST_CHECK(outputs.cmd_ready == 0u);
    response = outputs.cmd_rsp_data;
    TEST_CHECK((response & 0x0fffu) == command_id);
    TEST_CHECK(((response >> 12) & 0xffu) ==
               (uint64_t)(uint8_t)expected_status);
    TEST_CHECK((response >> 28) == 0u);

    for (cycle = 0u; cycle < hold_cycles; cycle++) {
        npu_model_cycle_io(&e2e_model, &inputs, &outputs);
        TEST_CHECK(outputs.cmd_rsp_valid == 1u);
        TEST_CHECK(outputs.cmd_ready == 0u);
        TEST_CHECK(outputs.cmd_rsp_data == response);
    }

    inputs.cmd_rsp_ready = 1u;
    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_rsp_valid == 1u);
    TEST_CHECK(outputs.cmd_rsp_data == response);
    TEST_CHECK(outputs.cmd_ready == 0u);

    inputs.cmd_rsp_ready = 0u;
    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_rsp_valid == 0u);
    TEST_CHECK(outputs.cmd_ready == 1u);
    if (response_value != (uint64_t *)0) {
        *response_value = response;
    }
    return 0;
}

static int e2e_submit_cmd_status(
    uint64_t low_beat,
    uint64_t high_beat,
    uint16_t command_id,
    npu_status_t expected_status,
    uint32_t response_hold_cycles)
{
    npu_host_inputs_t inputs;
    npu_host_outputs_t outputs;
    int line;

    e2e_idle_inputs(&inputs);
    inputs.cmd_valid = 1u;
    inputs.cmd_data = low_beat;
    inputs.cmd_first = 1u;
    inputs.cmd_last = 0u;
    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_ready == 1u);
    TEST_CHECK(outputs.cmd_rsp_valid == 0u);

    inputs.cmd_data = high_beat;
    inputs.cmd_first = 0u;
    inputs.cmd_last = 1u;
    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_ready == 1u);
    TEST_CHECK(outputs.cmd_rsp_valid == 0u);

    line = e2e_check_response(command_id, expected_status,
                              response_hold_cycles,
                              (uint64_t *)0);
    return line;
}

static int e2e_submit_cmd(uint64_t low_beat,
                          uint64_t high_beat,
                          uint16_t command_id,
                          uint32_t response_hold_cycles)
{
    return e2e_submit_cmd_status(
        low_beat, high_beat, command_id,
        NPU_STATUS_SUCCESS, response_hold_cycles);
}

static void e2e_make_dma_descriptor(void)
{
    uint8_t *descriptor = &e2e_ddr[E2E_DMA_DESC_ADDR];
    uint32_t numeric = e2e_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        0u, 0u, 0u, 0u);

    e2e_make_common(descriptor, NPU_WIRE_DMA_DESC_BYTES,
                    NPU_ENGINE_DMA, 1u,
                    E2E_DDR_INPUT_ADDR, 0u, 0u, E2E_L1_A_ADDR,
                    0u, 0u, numeric, 0x444d4101u);
    descriptor[0x40u] = 1u;
    descriptor[0x41u] = NPU_SPACE_DDR;
    descriptor[0x42u] = NPU_SPACE_L1;
    descriptor[0x43u] = NPU_DMA_CONVERT_NONE;
    descriptor[0x44u] = NPU_REF_DMA_MAX_BURST_BEATS - 1u;
    descriptor[0x45u] = NPU_REF_DMA_OUTSTANDING;
    e2e_put_u32(descriptor, 0x48u, 2u);
    e2e_put_u64(descriptor, 0x98u, 2u);
    e2e_put_u64(descriptor, 0xa0u, 2u);
}

static void e2e_make_matrix_descriptor(void)
{
    uint8_t *descriptor = &e2e_ddr[E2E_MATRIX_DESC_ADDR];
    uint32_t numeric = e2e_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8, NPU_DTYPE_INT4,
        NPU_DTYPE_INT32, NPU_ROUND_NEAREST_EVEN,
        0u, 0u, 0u, 0u);

    e2e_make_common(descriptor, NPU_WIRE_MATRIX_DESC_BYTES,
                    NPU_ENGINE_MATRIX, 0u,
                    E2E_L1_A_ADDR, E2E_L1_B_ADDR, 0u,
                    E2E_L1_MATRIX_DST_ADDR, 0u, 0u,
                    numeric, 0x4d450002u);
    e2e_put_u32(descriptor, 0x40u, 1u);
    e2e_put_u32(descriptor, 0x44u, 1u);
    e2e_put_u32(descriptor, 0x48u, 2u);
    e2e_put_u32(descriptor, 0x4cu, 1u);
    e2e_put_u32(descriptor, 0x50u, 1u);
    e2e_put_u32(descriptor, 0x54u, 1u);
    e2e_put_u32(descriptor, 0x58u, 2u);
    e2e_put_u32(descriptor, 0x5cu, 1u << 7);
    e2e_put_u32(descriptor, 0x60u, 2u);
    e2e_put_u32(descriptor, 0x68u, 4u);
    descriptor[0x90u] = 0u;
    descriptor[0x91u] = 2u;
    descriptor[0x92u] = 4u;
    descriptor[0x93u] = 0u;
    descriptor[0x94u] = NPU_OVERFLOW_SATURATE;
    descriptor[0x95u] = 0u;
    descriptor[0xa4u] = 0u;
    descriptor[0xa5u] = 0u;
    descriptor[0xa6u] = 8u;
}

static void e2e_make_vector_descriptor(void)
{
    uint8_t *descriptor = &e2e_ddr[E2E_VECTOR_DESC_ADDR];
    uint32_t numeric = e2e_numeric(
        NPU_DTYPE_INT32, NPU_DTYPE_INT32, NPU_DTYPE_INT4,
        NPU_DTYPE_INT32, NPU_ROUND_NEAREST_EVEN,
        1u, 1u, 0u, 0u);

    e2e_make_common(descriptor, NPU_WIRE_VECTOR_DESC_BYTES,
                    NPU_ENGINE_VECTOR, 0u,
                    E2E_L1_MATRIX_DST_ADDR,
                    E2E_L1_VECTOR_SRC1_ADDR, 0u,
                    E2E_L1_VECTOR_DST_ADDR, 0u, 0u,
                    numeric, 0x49564503u);
    e2e_put_u32(descriptor, 0x40u, 1u);
    e2e_put_u32(descriptor, 0x44u, 1u);
    e2e_put_u32(descriptor, 0x48u, 1u);
    e2e_put_u32(descriptor, 0x50u, 4u);
    e2e_put_u32(descriptor, 0x54u, 4u);
    e2e_put_u32(descriptor, 0x58u, 4u);
    e2e_put_u32(descriptor, 0x5cu, 4u);
    e2e_put_u32(descriptor, 0x68u, 4u);
    e2e_put_u32(descriptor, 0x6cu, 4u);
    descriptor[0x78u] = 0u;
    descriptor[0x79u] = NPU_COMPARE_EQ;
    descriptor[0x7au] = NPU_OVERFLOW_SATURATE;
    descriptor[0x7bu] = 0u;
    e2e_put_u32(descriptor, 0x80u, 0x3f800000u);
    e2e_put_u32(descriptor, 0x84u, 0x3f800000u);
    e2e_put_u32(descriptor, 0x88u, 0u);
    e2e_put_u32(descriptor, 0x8cu, 0x3f800000u);
}

static void e2e_make_complex_descriptor(void)
{
    uint8_t *descriptor = &e2e_ddr[E2E_COMPLEX_DESC_ADDR];
    uint32_t numeric = e2e_numeric(
        NPU_DTYPE_INT32, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        1u, 3u, 0u, 1u);

    e2e_make_common(descriptor, NPU_WIRE_COMPLEX_DESC_BYTES,
                    NPU_ENGINE_COMPLEX, 0u,
                    E2E_L1_VECTOR_DST_ADDR, 0u, 0u,
                    E2E_L1_COMPLEX_DST_ADDR,
                    E2E_L1_SRC_SCALE_ADDR,
                    E2E_L1_DST_SCALE_ADDR,
                    numeric, 0x434d4504u);
    e2e_put_u32(descriptor, 0x40u, 1u);
    e2e_put_u32(descriptor, 0x44u, 1u);
    e2e_put_u32(descriptor, 0x48u, 1u);
    e2e_put_u32(descriptor, 0x4cu, NPU_FUNC_SIGMOID);
    e2e_put_u32(descriptor, 0x50u, 4u);
    e2e_put_u32(descriptor, 0x5cu, 1u);
    e2e_put_u32(descriptor, 0x6cu, NPU_MASK_NONE);
    e2e_put_u32(descriptor, 0x94u, 0xc1800000u);
    e2e_put_u32(descriptor, 0x98u, 0x41800000u);
    descriptor[0x9cu] = 0u;
    descriptor[0x9du] = NPU_OVERFLOW_SATURATE;
    descriptor[0x9eu] = NPU_ALL_MASK_WRITE_ZERO;
    descriptor[0x9fu] = 0u;
}

static void e2e_make_control_descriptor(uint32_t user_tag)
{
    uint8_t *descriptor = &e2e_ddr[E2E_CONTROL_DESC_ADDR];

    e2e_make_common(descriptor, NPU_WIRE_CONTROL_DESC_BYTES,
                    NPU_ENGINE_CONTROL, 0u,
                    0u, 0u, 0u, 0u, 0u, 0u, 0u, user_tag);
}

static int e2e_test_pipeline(void)
{
    npu_task_result_t dma_result;
    npu_task_result_t matrix_result;
    npu_task_result_t vector_result;
    npu_task_result_t complex_result;
    const npu_task_request_t *complex_request;
    uint64_t low_beat;
    uint64_t high_beat;
    int line;

    TEST_CHECK(e2e_init());
    e2e_ddr[E2E_DDR_INPUT_ADDR] = 2u;
    e2e_ddr[E2E_DDR_INPUT_ADDR + 1u] = 3u;
    e2e_l1[E2E_L1_B_ADDR] = 4u;
    e2e_l1[E2E_L1_B_ADDR + 8u] = 5u;
    e2e_put_u32(e2e_l1, E2E_L1_VECTOR_SRC1_ADDR,
                UINT32_C(0xffffffe9));
    e2e_put_u32(e2e_l1, E2E_L1_SRC_SCALE_ADDR, 0x3f800000u);
    e2e_put_u32(e2e_l1, E2E_L1_DST_SCALE_ADDR, 0x3c000000u);

    e2e_make_dma_descriptor();
    e2e_make_matrix_descriptor();
    e2e_make_vector_descriptor();
    e2e_make_complex_descriptor();

    e2e_make_cmd(E2E_DMA_DESC_ADDR, 0x101u,
                 NPU_ENGINE_DMA, NPU_DMA_COPY_1D, 0u,
                 E2E_EVENT_NONE, E2E_EVENT_NONE,
                 e2e_event(E2E_EVENT_DMA_DONE, 0u),
                 &low_beat, &high_beat);
    line = e2e_submit_cmd(low_beat, high_beat, 0x101u, 3u);
    if (line != 0) {
        return line;
    }

    e2e_make_cmd(E2E_MATRIX_DESC_ADDR, 0x102u,
                 NPU_ENGINE_MATRIX, NPU_MATRIX_GEMM, 0u,
                 e2e_event(E2E_EVENT_DMA_DONE, 0u),
                 E2E_EVENT_NONE,
                 e2e_event(E2E_EVENT_MATRIX_DONE, 0u),
                 &low_beat, &high_beat);
    line = e2e_submit_cmd(low_beat, high_beat, 0x102u, 0u);
    if (line != 0) {
        return line;
    }

    e2e_make_cmd(E2E_VECTOR_DESC_ADDR, 0x103u,
                 NPU_ENGINE_VECTOR, NPU_VECTOR_ADD, 0u,
                 e2e_event(E2E_EVENT_MATRIX_DONE, 0u),
                 E2E_EVENT_NONE,
                 e2e_event(E2E_EVENT_VECTOR_DONE, 0u),
                 &low_beat, &high_beat);
    line = e2e_submit_cmd(low_beat, high_beat, 0x103u, 0u);
    if (line != 0) {
        return line;
    }

    e2e_make_cmd(E2E_COMPLEX_DESC_ADDR, 0x104u,
                 NPU_ENGINE_COMPLEX, NPU_COMPLEX_ACT, 0u,
                 e2e_event(E2E_EVENT_VECTOR_DONE, 0u),
                 E2E_EVENT_NONE, E2E_EVENT_NONE,
                 &low_beat, &high_beat);
    line = e2e_submit_cmd(low_beat, high_beat, 0x104u, 0u);
    if (line != 0) {
        return line;
    }

    TEST_CHECK_STATUS(npu_model_run(&e2e_model, 10000u),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&e2e_model, 0x101u, 0,
                                      &dma_result),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&e2e_model, 0x102u, 0,
                                      &matrix_result),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&e2e_model, 0x103u, 0,
                                      &vector_result),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&e2e_model, 0x104u, 0,
                                      &complex_result),
                      NPU_STATUS_SUCCESS);

    TEST_CHECK(matrix_result.start_cycle > dma_result.end_cycle);
    TEST_CHECK(vector_result.start_cycle > matrix_result.end_cycle);
    TEST_CHECK(complex_result.start_cycle > vector_result.end_cycle);
    TEST_CHECK(dma_result.user_tag == 0x444d4101u);
    TEST_CHECK(matrix_result.user_tag == 0x4d450002u);
    TEST_CHECK(vector_result.user_tag == 0x49564503u);
    TEST_CHECK(complex_result.user_tag == 0x434d4504u);

    complex_request = e2e_find_request(0x104u);
    TEST_CHECK(complex_request != (const npu_task_request_t *)0);
    TEST_CHECK(complex_request->desc_bytes ==
               NPU_WIRE_COMPLEX_DESC_BYTES);
    TEST_CHECK(complex_request->desc_version ==
               NPU_WIRE_DEFAULT_DESC_VERSION);
    TEST_CHECK(complex_request->allow_inplace == 0u);
    TEST_CHECK(complex_request->allow_partial_dest == 0u);
    TEST_CHECK(complex_request->desc.complex.scale_mode ==
               NPU_SCALE_PER_FEATURE);
    TEST_CHECK(complex_request->desc.complex.src0_scale_table_addr ==
               E2E_L1_SRC_SCALE_ADDR);
    TEST_CHECK(complex_request->desc.complex.dst_scale_table_addr ==
               E2E_L1_DST_SCALE_ADDR);
    TEST_CHECK(complex_request->desc.complex.approx_mode == 0u);
    TEST_CHECK(complex_request->desc.complex.stats_mode == 0u);

    TEST_CHECK(e2e_l1[E2E_L1_A_ADDR] == 2u);
    TEST_CHECK(e2e_l1[E2E_L1_A_ADDR + 1u] == 3u);
    TEST_CHECK(e2e_get_u32(e2e_l1,
                           E2E_L1_MATRIX_DST_ADDR) == 23u);
    TEST_CHECK(e2e_get_u32(e2e_l1,
                           E2E_L1_VECTOR_DST_ADDR) == 0u);
    TEST_CHECK(e2e_l1[E2E_L1_COMPLEX_DST_ADDR] == 64u);

    TEST_CHECK(e2e_model.events[E2E_EVENT_DMA_DONE].state ==
               NPU_EVENT_SUCCESS);
    TEST_CHECK(e2e_model.events[E2E_EVENT_MATRIX_DONE].state ==
               NPU_EVENT_SUCCESS);
    TEST_CHECK(e2e_model.events[E2E_EVENT_VECTOR_DONE].state ==
               NPU_EVENT_SUCCESS);
    TEST_CHECK(e2e_model.events[E2E_EVENT_DMA_DONE].waiter_count == 0u);
    TEST_CHECK(e2e_model.events[E2E_EVENT_MATRIX_DONE].waiter_count == 0u);
    TEST_CHECK(e2e_model.events[E2E_EVENT_VECTOR_DONE].waiter_count == 0u);
    TEST_CHECK(e2e_model.perf.cmd_accepted == 4u);
    TEST_CHECK(e2e_model.perf.task_success == 4u);
    TEST_CHECK(e2e_model.perf.task_failed == 0u);
    return 0;
}

static int e2e_test_command_header(void)
{
    const npu_task_request_t *request;
    uint64_t low_beat;
    uint64_t high_beat;
    uint64_t invalid_high;
    uint16_t event0 = e2e_event(7u, 2u);
    uint16_t event1 = e2e_event(8u, 3u);
    uint16_t signal = e2e_event(9u, 4u);
    int line;

    TEST_CHECK(e2e_init());
    e2e_make_control_descriptor(0x50524f54u);

    e2e_make_cmd(E2E_CONTROL_DESC_ADDR, 0x201u,
                 NPU_ENGINE_CONTROL, NPU_CTRL_NOP,
                 (uint16_t)(0x01u | (3u << 6u)),
                 event0, event1, signal,
                 &low_beat, &high_beat);
    TEST_CHECK((high_beat & 0xffu) == NPU_CTRL_NOP);
    TEST_CHECK(((high_beat >> 8u) & 0x0fffu) ==
               (uint16_t)(0x01u | (3u << 6u)));
    TEST_CHECK(((high_beat >> 20u) & 0x0fffu) == event0);
    TEST_CHECK(((high_beat >> 32u) & 0x0fffu) == event1);
    TEST_CHECK(((high_beat >> 44u) & 0x0fffu) == signal);
    TEST_CHECK((high_beat >> 56u) == NPU_WIRE_HEADER_VERSION);

    e2e_make_cmd(E2E_CONTROL_DESC_ADDR, 0x201u,
                 NPU_ENGINE_CONTROL, NPU_CTRL_NOP, 0u,
                 E2E_EVENT_NONE, E2E_EVENT_NONE, E2E_EVENT_NONE,
                 &low_beat, &high_beat);
    invalid_high =
        (high_beat & ~UINT64_C(0xff)) | UINT64_C(0x0f);
    line = e2e_submit_cmd_status(
        low_beat, invalid_high, 0x201u,
        NPU_STATUS_ILLEGAL_OPCODE, 0u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(e2e_model.perf.cmd_accepted == 0u);
    TEST_CHECK(npu_model_idle(&e2e_model));

    invalid_high =
        (high_beat & UINT64_C(0x00ffffffffffffff)) |
        (UINT64_C(2) << 56u);
    line = e2e_submit_cmd_status(
        low_beat, invalid_high, 0x201u,
        NPU_STATUS_BAD_DESC, 0u);
    if (line != 0) {
        return line;
    }

    invalid_high =
        high_beat | (UINT64_C(1) << (8u + 10u));
    line = e2e_submit_cmd_status(
        low_beat, invalid_high, 0x201u,
        NPU_STATUS_BAD_DESC, 0u);
    if (line != 0) {
        return line;
    }

    invalid_high =
        (high_beat & ~(UINT64_C(0x0fff) << 20u)) |
        (UINT64_C(0x00ff) << 20u);
    line = e2e_submit_cmd_status(
        low_beat, invalid_high, 0x201u,
        NPU_STATUS_BAD_DESC, 0u);
    if (line != 0) {
        return line;
    }

    e2e_make_cmd(E2E_CONTROL_DESC_ADDR, 0x201u,
                 NPU_ENGINE_CONTROL, NPU_CTRL_NOP, 0u,
                 event0, E2E_EVENT_NONE, event0,
                 &low_beat, &high_beat);
    line = e2e_submit_cmd_status(
        low_beat, high_beat, 0x201u,
        NPU_STATUS_BAD_DESC, 0u);
    if (line != 0) {
        return line;
    }

    e2e_make_cmd(E2E_CONTROL_DESC_ADDR, 0x202u,
                 NPU_ENGINE_CONTROL, NPU_CTRL_NOP,
                 (uint16_t)(1u | (3u << 6u)),
                 E2E_EVENT_NONE, E2E_EVENT_NONE, E2E_EVENT_NONE,
                 &low_beat, &high_beat);
    line = e2e_submit_cmd(low_beat, high_beat, 0x202u, 0u);
    if (line != 0) {
        return line;
    }
    request = e2e_find_request(0x202u);
    TEST_CHECK(request != (const npu_task_request_t *)0);
    TEST_CHECK(request->cmd.header_version ==
               NPU_WIRE_HEADER_VERSION);
    TEST_CHECK((request->cmd.header_flags & 1u) != 0u);
    TEST_CHECK(request->cmd.timeout_class == 3u);
    return 0;
}

static int e2e_test_reset_n(void)
{
    npu_host_inputs_t inputs;
    npu_host_outputs_t outputs;
    npu_task_result_t result;
    uint64_t low_beat;
    uint64_t high_beat;

    TEST_CHECK(e2e_init());
    e2e_make_control_descriptor(0x52535400u);
    e2e_l1[0x20u] = 0xa5u;
    e2e_ddr[0x20u] = 0x5au;
    e2e_make_cmd(E2E_CONTROL_DESC_ADDR, 0x301u,
                 NPU_ENGINE_CONTROL, NPU_CTRL_NOP, 1u,
                 E2E_EVENT_NONE, E2E_EVENT_NONE, E2E_EVENT_NONE,
                 &low_beat, &high_beat);

    e2e_idle_inputs(&inputs);
    inputs.cmd_valid = 1u;
    inputs.cmd_data = low_beat;
    inputs.cmd_first = 1u;
    inputs.cmd_last = 0u;
    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_ready == 1u);
    TEST_CHECK(e2e_model.cfe.have_low_beat == 1u);
    TEST_CHECK(e2e_model.cfe.response_valid == 0u);
    TEST_CHECK(e2e_model.perf.cmd_accepted == 0u);

    inputs.cmd_data = high_beat;
    inputs.cmd_first = 0u;
    inputs.cmd_last = 1u;
    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_ready == 1u);
    TEST_CHECK(e2e_model.cfe.response_valid == 1u);
    TEST_CHECK(e2e_model.perf.cmd_accepted == 1u);
    TEST_CHECK(e2e_model.cycle != 0u);

    e2e_idle_inputs(&inputs);
    inputs.core_reset_n = 0u;
    inputs.noc_reset_n = 1u;
    inputs.cmd_valid = 1u;
    inputs.cmd_data = low_beat;
    inputs.cmd_first = 1u;
    inputs.cmd_last = 0u;
    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_ready == 0u);
    TEST_CHECK(outputs.cmd_rsp_valid == 0u);
    TEST_CHECK(outputs.cmd_rsp_data == 0u);
    TEST_CHECK(outputs.cycle == 0u);
    TEST_CHECK(e2e_model.cycle == 0u);
    TEST_CHECK(e2e_model.cfe.response_valid == 0u);
    TEST_CHECK(e2e_model.perf.cmd_accepted == 0u);
    TEST_CHECK(e2e_l1[0x20u] == 0xa5u);
    TEST_CHECK(e2e_ddr[0x20u] == 0x5au);

    e2e_idle_inputs(&inputs);
    inputs.cmd_valid = 1u;
    inputs.cmd_data = low_beat;
    inputs.cmd_first = 1u;
    inputs.cmd_last = 0u;
    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cycle == 0u);
    TEST_CHECK(outputs.cmd_ready == 1u);
    TEST_CHECK(e2e_model.cfe.have_low_beat == 1u);
    TEST_CHECK(e2e_model.cfe.response_valid == 0u);
    TEST_CHECK(e2e_model.perf.cmd_accepted == 0u);

    inputs.cmd_data = high_beat;
    inputs.cmd_first = 0u;
    inputs.cmd_last = 1u;
    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_ready == 1u);
    TEST_CHECK(e2e_model.cfe.response_valid == 1u);
    TEST_CHECK(e2e_model.perf.cmd_accepted == 1u);

    e2e_idle_inputs(&inputs);
    inputs.core_reset_n = 1u;
    inputs.noc_reset_n = 0u;
    inputs.cmd_rsp_ready = 0u;
    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_ready == 0u);
    TEST_CHECK(outputs.cmd_rsp_valid == 0u);
    TEST_CHECK(outputs.cmd_rsp_data == 0u);
    TEST_CHECK(outputs.cycle == 0u);
    TEST_CHECK(e2e_model.cycle == 0u);
    TEST_CHECK(e2e_model.cfe.response_valid == 0u);
    TEST_CHECK(e2e_model.perf.cmd_accepted == 0u);
    TEST_CHECK_STATUS(npu_model_query(&e2e_model, 0x301u, 0,
                                      &result),
                      NPU_STATUS_NOT_FOUND);

    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cycle == 0u);
    TEST_CHECK(e2e_model.cycle == 0u);

    e2e_idle_inputs(&inputs);
    npu_model_cycle_io(&e2e_model, &inputs, &outputs);
    TEST_CHECK(outputs.cycle == 0u);
    TEST_CHECK(outputs.cmd_ready == 1u);
    TEST_CHECK(e2e_model.cycle == 1u);
    TEST_CHECK(e2e_l1[0x20u] == 0xa5u);
    TEST_CHECK(e2e_ddr[0x20u] == 0x5au);
    return 0;
}

int test_wire_e2e(void)
{
    int line;

    line = e2e_test_pipeline();
    if (line != 0) {
        return line;
    }
    line = e2e_test_command_header();
    if (line != 0) {
        return line;
    }
    return e2e_test_reset_n();
}

#if defined(NPU_WIRE_E2E_STANDALONE)
int main(void)
{
    return test_wire_e2e();
}
#endif
