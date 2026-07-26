#include "npu_engine_cycle.h"
#include "test_util.h"

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define ENGINE_TEST_MEMORY_BYTES (64u * 1024u)
#define ENGINE_TEST_MAX_CYCLES 20000u

#define ENGINE_TEST_DDR_SRC 0x0800u
#define ENGINE_TEST_L1_A 0x0100u
#define ENGINE_TEST_L1_B 0x0200u
#define ENGINE_TEST_L1_MATRIX_DST 0x0300u
#define ENGINE_TEST_L1_VECTOR_SRC1 0x0380u
#define ENGINE_TEST_L1_VECTOR_DST 0x0400u
#define ENGINE_TEST_L1_COMPLEX_DST 0x0500u

typedef struct {
    const uint8_t *descriptor;
    uint8_t valid[NPU_ENGINE_DESC_TAGS];
    uint8_t word[NPU_ENGINE_DESC_TAGS];
    uint64_t issue_cycle[NPU_ENGINE_DESC_TAGS];
    uint8_t count;
    uint8_t max_count;
    uint8_t delay_until_full;
    uint8_t release;
    uint8_t reverse_response;
    uint8_t corrected_word;
    uint8_t uncorrectable_word;
    uint8_t corrected_enable;
    uint8_t uncorrectable_enable;
    uint8_t response_seen;
    uint8_t previous_response_word;
    uint8_t reordered;
    uint64_t cycle;
} engine_desc_server_t;

typedef struct {
    uint64_t beat[3];
} engine_done_message_t;

static uint8_t engine_test_l1[ENGINE_TEST_MEMORY_BYTES];
static uint8_t engine_test_ddr[ENGINE_TEST_MEMORY_BYTES];
static npu_model_t engine_test_model;

static void engine_test_put_u16(uint8_t *data,
                                size_t offset,
                                uint16_t value)
{
    data[offset] = (uint8_t)value;
    data[offset + 1u] = (uint8_t)(value >> 8);
}

static void engine_test_put_u32(uint8_t *data,
                                size_t offset,
                                uint32_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 4u; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static void engine_test_put_u64(uint8_t *data,
                                size_t offset,
                                uint64_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static uint32_t engine_test_get_u32(const uint8_t *data,
                                    size_t offset)
{
    return (uint32_t)data[offset] |
           ((uint32_t)data[offset + 1u] << 8) |
           ((uint32_t)data[offset + 2u] << 16) |
           ((uint32_t)data[offset + 3u] << 24);
}

static uint64_t engine_test_get_word(const uint8_t *data,
                                     uint8_t word)
{
    uint64_t value = 0u;
    size_t offset = (size_t)word * NPU_REF_BUS_BYTES;
    uint32_t byte;

    for (byte = 0u; byte < NPU_REF_BUS_BYTES; byte++) {
        value |= (uint64_t)data[offset + byte] << (byte * 8u);
    }
    return value;
}

static uint32_t engine_test_numeric(
    npu_dtype_t src0,
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

static void engine_test_common(uint8_t *descriptor,
                               size_t bytes,
                               npu_engine_t engine,
                               uint32_t op_flags,
                               uint64_t src0,
                               uint64_t src1,
                               uint64_t src2,
                               uint64_t dst,
                               uint64_t aux0,
                               uint64_t aux1,
                               uint32_t numeric,
                               uint32_t user_tag)
{
    (void)memset(descriptor, 0, bytes);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = (uint8_t)engine;
    engine_test_put_u16(descriptor, 0x02u, (uint16_t)bytes);
    engine_test_put_u32(descriptor, 0x04u, op_flags);
    engine_test_put_u64(descriptor, 0x08u, src0);
    engine_test_put_u64(descriptor, 0x10u, src1);
    engine_test_put_u64(descriptor, 0x18u, src2);
    engine_test_put_u64(descriptor, 0x20u, dst);
    engine_test_put_u64(descriptor, 0x28u, aux0);
    engine_test_put_u64(descriptor, 0x30u, aux1);
    engine_test_put_u32(descriptor, 0x38u, numeric);
    engine_test_put_u32(descriptor, 0x3cu, user_tag);
}

static void engine_test_dma_descriptor(uint8_t *descriptor)
{
    uint32_t numeric = engine_test_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        0u, NPU_SCALE_NONE, 0u, 0u);

    engine_test_common(
        descriptor, NPU_WIRE_DMA_DESC_BYTES,
        NPU_ENGINE_DMA, 1u,
        ENGINE_TEST_DDR_SRC, 0u, 0u, ENGINE_TEST_L1_A,
        0u, 0u, numeric, 0x444d4101u);
    descriptor[0x40u] = 1u;
    descriptor[0x41u] = NPU_SPACE_DDR;
    descriptor[0x42u] = NPU_SPACE_L1;
    descriptor[0x43u] = NPU_DMA_CONVERT_NONE;
    descriptor[0x44u] = NPU_REF_DMA_MAX_BURST_BEATS - 1u;
    descriptor[0x45u] = NPU_REF_DMA_OUTSTANDING;
    engine_test_put_u32(descriptor, 0x48u, 2u);
    engine_test_put_u64(descriptor, 0x98u, 2u);
    engine_test_put_u64(descriptor, 0xa0u, 2u);
}

static void engine_test_matrix_descriptor(uint8_t *descriptor)
{
    uint32_t numeric = engine_test_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8, NPU_DTYPE_INT4,
        NPU_DTYPE_INT32, NPU_ROUND_NEAREST_EVEN,
        0u, NPU_SCALE_NONE, 0u, 0u);

    engine_test_common(
        descriptor, NPU_WIRE_MATRIX_DESC_BYTES,
        NPU_ENGINE_MATRIX, 0u,
        ENGINE_TEST_L1_A, ENGINE_TEST_L1_B, 0u,
        ENGINE_TEST_L1_MATRIX_DST, 0u, 0u,
        numeric, 0x4d450002u);
    engine_test_put_u32(descriptor, 0x40u, 1u);
    engine_test_put_u32(descriptor, 0x44u, 1u);
    engine_test_put_u32(descriptor, 0x48u, 2u);
    engine_test_put_u32(descriptor, 0x4cu, 1u);
    engine_test_put_u32(descriptor, 0x50u, 1u);
    engine_test_put_u32(descriptor, 0x54u, 1u);
    engine_test_put_u32(descriptor, 0x58u, 2u);
    engine_test_put_u32(descriptor, 0x5cu, 1u << 7);
    engine_test_put_u32(descriptor, 0x60u, 2u);
    engine_test_put_u32(descriptor, 0x68u, 4u);
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

static void engine_test_vector_descriptor(uint8_t *descriptor)
{
    uint32_t numeric = engine_test_numeric(
        NPU_DTYPE_INT32, NPU_DTYPE_INT32, NPU_DTYPE_INT4,
        NPU_DTYPE_INT32, NPU_ROUND_NEAREST_EVEN,
        1u, NPU_SCALE_PER_TENSOR, 0u, 0u);

    engine_test_common(
        descriptor, NPU_WIRE_VECTOR_DESC_BYTES,
        NPU_ENGINE_VECTOR, 0u,
        ENGINE_TEST_L1_MATRIX_DST,
        ENGINE_TEST_L1_VECTOR_SRC1, 0u,
        ENGINE_TEST_L1_VECTOR_DST, 0u, 0u,
        numeric, 0x49564503u);
    engine_test_put_u32(descriptor, 0x40u, 1u);
    engine_test_put_u32(descriptor, 0x44u, 1u);
    engine_test_put_u32(descriptor, 0x48u, 1u);
    engine_test_put_u32(descriptor, 0x50u, 4u);
    engine_test_put_u32(descriptor, 0x54u, 4u);
    engine_test_put_u32(descriptor, 0x58u, 4u);
    engine_test_put_u32(descriptor, 0x5cu, 4u);
    engine_test_put_u32(descriptor, 0x68u, 4u);
    engine_test_put_u32(descriptor, 0x6cu, 4u);
    descriptor[0x78u] = 0u;
    descriptor[0x79u] = NPU_COMPARE_EQ;
    descriptor[0x7au] = NPU_OVERFLOW_SATURATE;
    descriptor[0x7bu] = 0u;
    engine_test_put_u32(descriptor, 0x80u, 0x3f800000u);
    engine_test_put_u32(descriptor, 0x84u, 0x3f800000u);
    engine_test_put_u32(descriptor, 0x88u, 0u);
    engine_test_put_u32(descriptor, 0x8cu, 0x3f800000u);
}

static void engine_test_vector_partial_descriptor(
    uint8_t *descriptor)
{
    uint32_t numeric = engine_test_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        0u, NPU_SCALE_PER_TENSOR, 0u, 0u);

    engine_test_common(
        descriptor, NPU_WIRE_VECTOR_DESC_BYTES,
        NPU_ENGINE_VECTOR, 0u,
        0x0600u, 0x0610u, 0u, 0x0620u,
        0u, 0u, numeric, 0x45525231u);
    engine_test_put_u32(descriptor, 0x40u, 1u);
    engine_test_put_u32(descriptor, 0x44u, 9u);
    engine_test_put_u32(descriptor, 0x48u, 9u);
    engine_test_put_u32(descriptor, 0x50u, 1u);
    engine_test_put_u32(descriptor, 0x54u, 9u);
    engine_test_put_u32(descriptor, 0x58u, 1u);
    engine_test_put_u32(descriptor, 0x5cu, 9u);
    engine_test_put_u32(descriptor, 0x68u, 1u);
    engine_test_put_u32(descriptor, 0x6cu, 9u);
    descriptor[0x78u] = 0u;
    descriptor[0x79u] = NPU_COMPARE_EQ;
    descriptor[0x7au] = NPU_OVERFLOW_ERROR;
    descriptor[0x7bu] = 0u;
    engine_test_put_u32(descriptor, 0x80u, 0x3f800000u);
    engine_test_put_u32(descriptor, 0x84u, 0x3f800000u);
    engine_test_put_u32(descriptor, 0x88u, 0u);
    engine_test_put_u32(descriptor, 0x8cu, 0x3f800000u);
}

static void engine_test_complex_descriptor(uint8_t *descriptor)
{
    uint32_t numeric = engine_test_numeric(
        NPU_DTYPE_INT32, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        1u, NPU_SCALE_PER_TENSOR, 0u, 1u);

    engine_test_common(
        descriptor, NPU_WIRE_COMPLEX_DESC_BYTES,
        NPU_ENGINE_COMPLEX, 0u,
        ENGINE_TEST_L1_VECTOR_DST, 0u, 0u,
        ENGINE_TEST_L1_COMPLEX_DST, 0u, 0u,
        numeric, 0x434d4504u);
    engine_test_put_u32(descriptor, 0x40u, 1u);
    engine_test_put_u32(descriptor, 0x44u, 1u);
    engine_test_put_u32(descriptor, 0x48u, 1u);
    engine_test_put_u32(descriptor, 0x4cu, NPU_FUNC_SIGMOID);
    engine_test_put_u32(descriptor, 0x50u, 4u);
    engine_test_put_u32(descriptor, 0x5cu, 1u);
    engine_test_put_u32(descriptor, 0x6cu, NPU_MASK_NONE);
    engine_test_put_u32(descriptor, 0x70u, 0x3f800000u);
    engine_test_put_u32(descriptor, 0x7cu, 0x3c000000u);
    engine_test_put_u32(descriptor, 0x94u, 0xc1800000u);
    engine_test_put_u32(descriptor, 0x98u, 0x41800000u);
    descriptor[0x9cu] = 0u;
    descriptor[0x9du] = NPU_OVERFLOW_SATURATE;
    descriptor[0x9eu] = NPU_ALL_MASK_WRITE_ZERO;
    descriptor[0x9fu] = 0u;
}

static uint64_t engine_test_metadata(uint16_t task_id,
                                     uint8_t opcode,
                                     uint8_t desc_slot,
                                     uint16_t task_flags,
                                     uint8_t timeout_class)
{
    return (uint64_t)(task_id & 0x0fffu) |
           ((uint64_t)opcode << 12) |
           ((uint64_t)desc_slot << 20) |
           ((uint64_t)(task_flags & 0x0fffu) << 28) |
           ((uint64_t)(timeout_class & 0x0fu) << 40);
}

static int engine_test_model_init(npu_wire_limits_t *limits)
{
    npu_config_t config;

    (void)memset(engine_test_l1, 0, sizeof(engine_test_l1));
    (void)memset(engine_test_ddr, 0, sizeof(engine_test_ddr));
    npu_config_reference(&config);
    config.l1_bytes = ENGINE_TEST_MEMORY_BYTES;
    if (npu_model_init(&engine_test_model, &config,
                       engine_test_l1, sizeof(engine_test_l1),
                       engine_test_ddr, sizeof(engine_test_ddr)) !=
        NPU_STATUS_SUCCESS) {
        return 0;
    }
    npu_wire_limits_reference(limits);
    limits->l1_bytes = ENGINE_TEST_MEMORY_BYTES;
    limits->gaddr_limit = ENGINE_TEST_MEMORY_BYTES;
    return 1;
}

static void engine_test_idle_inputs(
    npu_engine_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = 1u;
    inputs->desc_rd_req_ready_i = 1u;
}

static void engine_server_init(engine_desc_server_t *server,
                               const uint8_t *descriptor)
{
    (void)memset(server, 0, sizeof(*server));
    server->descriptor = descriptor;
}

static int engine_server_select(
    const engine_desc_server_t *server)
{
    int selected = -1;
    uint8_t tag;

    if (server->delay_until_full != 0u &&
        server->release == 0u) {
        return -1;
    }
    for (tag = 0u; tag < NPU_ENGINE_DESC_TAGS; tag++) {
        if (server->valid[tag] == 0u ||
            server->issue_cycle[tag] >= server->cycle) {
            continue;
        }
        if (selected < 0) {
            selected = tag;
        } else if (server->reverse_response != 0u &&
                   server->word[tag] >
                       server->word[(uint8_t)selected]) {
            selected = tag;
        } else if (server->reverse_response == 0u &&
                   server->issue_cycle[tag] <
                       server->issue_cycle[(uint8_t)selected]) {
            selected = tag;
        }
    }
    return selected;
}

static void engine_server_drive(engine_desc_server_t *server,
                                npu_engine_cycle_inputs_t *inputs)
{
    int selected;
    uint8_t word;

    inputs->desc_rd_rsp_valid_i = 0u;
    inputs->desc_rd_rsp_data_i = 0u;
    inputs->desc_rd_rsp_tag_i = 0u;
    inputs->desc_rd_rsp_status_i = NPU_ENGINE_DESC_OK;
    if (server->delay_until_full != 0u &&
        server->count == NPU_ENGINE_DESC_TAGS) {
        server->release = 1u;
    }
    selected = engine_server_select(server);
    if (selected < 0) {
        return;
    }
    word = server->word[(uint8_t)selected];
    inputs->desc_rd_rsp_valid_i = 1u;
    inputs->desc_rd_rsp_tag_i = (uint8_t)selected;
    inputs->desc_rd_rsp_data_i =
        engine_test_get_word(server->descriptor, word);
    if (server->uncorrectable_enable != 0u &&
        word == server->uncorrectable_word) {
        inputs->desc_rd_rsp_status_i =
            NPU_ENGINE_DESC_ECC_UNCORRECTABLE;
    } else if (server->corrected_enable != 0u &&
               word == server->corrected_word) {
        inputs->desc_rd_rsp_status_i =
            NPU_ENGINE_DESC_ECC_CORRECTED;
    }
}

static int engine_server_observe(
    engine_desc_server_t *server,
    const npu_engine_cycle_inputs_t *inputs,
    const npu_engine_cycle_outputs_t *outputs)
{
    uint8_t tag;
    uint8_t word;

    if (inputs->desc_rd_rsp_valid_i != 0u &&
        outputs->desc_rd_rsp_ready_o != 0u) {
        tag = inputs->desc_rd_rsp_tag_i;
        TEST_CHECK(tag < NPU_ENGINE_DESC_TAGS);
        TEST_CHECK(server->valid[tag] != 0u);
        word = server->word[tag];
        if (server->response_seen != 0u &&
            word < server->previous_response_word) {
            server->reordered = 1u;
        }
        server->previous_response_word = word;
        server->response_seen = 1u;
        server->valid[tag] = 0u;
        TEST_CHECK(server->count != 0u);
        server->count--;
    }

    if (outputs->desc_rd_req_valid_o != 0u &&
        inputs->desc_rd_req_ready_i != 0u) {
        tag = outputs->desc_rd_req_tag_o;
        TEST_CHECK(tag < NPU_ENGINE_DESC_TAGS);
        TEST_CHECK(server->valid[tag] == 0u);
        server->valid[tag] = 1u;
        server->word[tag] = outputs->desc_rd_word_o;
        server->issue_cycle[tag] = server->cycle;
        server->count++;
        if (server->count > server->max_count) {
            server->max_count = server->count;
        }
    }
    server->cycle++;
    return 0;
}

static int engine_test_submit(npu_engine_cycle_t *adapter,
                              npu_engine_cycle_inputs_t *inputs,
                              uint64_t metadata)
{
    npu_engine_cycle_outputs_t outputs;

    inputs->eng_req_valid_i = 1u;
    inputs->eng_req_data_i = metadata;
    npu_engine_cycle_step(adapter, inputs, &outputs);
    TEST_CHECK(outputs.eng_req_ready_o == 1u);
    TEST_CHECK(outputs.eng_busy_o == 0u);
    inputs->eng_req_valid_i = 0u;
    inputs->eng_req_data_i = 0u;
    return 0;
}

static int engine_test_run_until_done(
    npu_engine_cycle_t *adapter,
    npu_engine_cycle_inputs_t *inputs,
    engine_desc_server_t *server,
    uint8_t *watched_byte,
    uint8_t initial_value,
    uint8_t expected_value,
    uint8_t check_write_point,
    uint32_t *corrected_pulses)
{
    npu_engine_cycle_outputs_t outputs;
    uint32_t cycle;
    int line;

    *corrected_pulses = 0u;
    for (cycle = 0u; cycle < ENGINE_TEST_MAX_CYCLES; cycle++) {
        npu_engine_cycle_state_t old_state = adapter->state;
        uint64_t old_remaining = adapter->execute_remaining;

        engine_server_drive(server, inputs);
        npu_engine_cycle_step(adapter, inputs, &outputs);
        line = engine_server_observe(server, inputs, &outputs);
        if (line != 0) {
            return line;
        }
        if (outputs.ecc_corrected_o != 0u) {
            (*corrected_pulses)++;
        }
        if (check_write_point != 0u &&
            old_state == NPU_ENGINE_CYCLE_EXECUTE) {
            if (old_remaining > 1u) {
                TEST_CHECK(*watched_byte == initial_value);
            } else {
                TEST_CHECK(*watched_byte == expected_value);
            }
        }
        if (adapter->state == NPU_ENGINE_CYCLE_DONE) {
            TEST_CHECK(server->count == 0u);
            return 0;
        }
    }
    return __LINE__;
}

static int engine_test_collect_done(
    npu_engine_cycle_t *adapter,
    npu_engine_cycle_inputs_t *inputs,
    engine_done_message_t *message,
    uint32_t hold_cycles)
{
    npu_engine_cycle_outputs_t outputs;
    uint8_t beat;
    uint32_t hold;
    uint64_t stable_data;
    uint8_t stable_first;
    uint8_t stable_last;

    inputs->desc_rd_rsp_valid_i = 0u;
    for (beat = 0u; beat < 3u; beat++) {
        inputs->eng_done_ready_i = 0u;
        npu_engine_cycle_step(adapter, inputs, &outputs);
        TEST_CHECK(outputs.eng_done_valid_o == 1u);
        TEST_CHECK(outputs.eng_done_first_o ==
                   (uint8_t)(beat == 0u));
        TEST_CHECK(outputs.eng_done_last_o ==
                   (uint8_t)(beat == 2u));
        TEST_CHECK(outputs.done_stall_o == 1u);
        stable_data = outputs.eng_done_data_o;
        stable_first = outputs.eng_done_first_o;
        stable_last = outputs.eng_done_last_o;
        for (hold = 0u; hold < hold_cycles; hold++) {
            npu_engine_cycle_step(adapter, inputs, &outputs);
            TEST_CHECK(outputs.eng_done_valid_o == 1u);
            TEST_CHECK(outputs.eng_done_data_o == stable_data);
            TEST_CHECK(outputs.eng_done_first_o == stable_first);
            TEST_CHECK(outputs.eng_done_last_o == stable_last);
        }
        message->beat[beat] = stable_data;
        inputs->eng_done_ready_i = 1u;
        npu_engine_cycle_step(adapter, inputs, &outputs);
        TEST_CHECK(outputs.eng_done_valid_o == 1u);
        TEST_CHECK(outputs.eng_done_data_o == stable_data);
        TEST_CHECK(outputs.eng_done_first_o == stable_first);
        TEST_CHECK(outputs.eng_done_last_o == stable_last);
    }
    inputs->eng_done_ready_i = 0u;
    npu_engine_cycle_step(adapter, inputs, &outputs);
    TEST_CHECK(outputs.eng_done_valid_o == 0u);
    TEST_CHECK(outputs.eng_busy_o == 0u);
    TEST_CHECK(outputs.eng_quiescent_o == 1u);
    return 0;
}

static int engine_test_check_done(
    const engine_done_message_t *message,
    uint16_t task_id,
    npu_status_t status,
    npu_engine_t engine,
    uint8_t opcode,
    uint64_t progress)
{
    TEST_CHECK((message->beat[0] & 0x0fffu) == task_id);
    TEST_CHECK(((message->beat[0] >> 12) & 0xffu) ==
               (uint64_t)(uint8_t)status);
    TEST_CHECK(((message->beat[1] >> 48) & 0x0fu) ==
               (uint64_t)engine);
    TEST_CHECK(((message->beat[1] >> 52) & 0xffu) == opcode);
    TEST_CHECK((message->beat[1] >> 60) == 0u);
    TEST_CHECK(message->beat[2] == progress);
    return 0;
}

static int engine_test_run_real_task(
    npu_engine_t engine,
    uint8_t opcode,
    uint16_t task_id,
    uint8_t *descriptor,
    uint8_t *watched_byte,
    uint8_t initial_value,
    uint8_t expected_value,
    uint64_t expected_progress,
    const npu_wire_limits_t *limits)
{
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    engine_desc_server_t server;
    engine_done_message_t message;
    uint32_t corrected_pulses;
    int line;

    TEST_CHECK_STATUS(npu_engine_cycle_init(
                          &adapter, &engine_test_model,
                          engine, limits),
                      NPU_STATUS_SUCCESS);
    engine_test_idle_inputs(&inputs);
    engine_server_init(&server, descriptor);
    line = engine_test_submit(
        &adapter, &inputs,
        engine_test_metadata(task_id, opcode, 3u, 0u, 0u));
    if (line != 0) {
        return line;
    }
    line = engine_test_run_until_done(
        &adapter, &inputs, &server,
        watched_byte, initial_value, expected_value,
        1u, &corrected_pulses);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(corrected_pulses == 0u);
    TEST_CHECK(adapter.estimated_total_cycles >
               adapter.descriptor_phase_cycles);
    TEST_CHECK(adapter.descriptor_phase_cycles ==
               (uint64_t)adapter.descriptor_words +
                   NPU_ENGINE_DESC_OVERHEAD_CYCLES);
    TEST_CHECK(*watched_byte == expected_value);
    line = engine_test_collect_done(
        &adapter, &inputs, &message, 2u);
    if (line != 0) {
        return line;
    }
    return engine_test_check_done(
        &message, task_id, NPU_STATUS_SUCCESS,
        engine, opcode, expected_progress);
}

static int engine_test_four_real_tasks(void)
{
    uint8_t dma_desc[NPU_WIRE_DMA_DESC_BYTES];
    uint8_t matrix_desc[NPU_WIRE_MATRIX_DESC_BYTES];
    uint8_t vector_desc[NPU_WIRE_VECTOR_DESC_BYTES];
    uint8_t complex_desc[NPU_WIRE_COMPLEX_DESC_BYTES];
    npu_wire_limits_t limits;
    int line;

    TEST_CHECK(engine_test_model_init(&limits));
    engine_test_ddr[ENGINE_TEST_DDR_SRC] = 2u;
    engine_test_ddr[ENGINE_TEST_DDR_SRC + 1u] = 3u;
    engine_test_l1[ENGINE_TEST_L1_B] = 4u;
    engine_test_l1[ENGINE_TEST_L1_B + 8u] = 5u;
    engine_test_put_u32(engine_test_l1,
                        ENGINE_TEST_L1_VECTOR_SRC1,
                        UINT32_C(0xffffffe9));
    engine_test_dma_descriptor(dma_desc);
    engine_test_matrix_descriptor(matrix_desc);
    engine_test_vector_descriptor(vector_desc);
    engine_test_complex_descriptor(complex_desc);

    line = engine_test_run_real_task(
        NPU_ENGINE_DMA, NPU_DMA_COPY_1D, 0x101u,
        dma_desc, &engine_test_l1[ENGINE_TEST_L1_A],
        0u, 2u, 2u, &limits);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(engine_test_l1[ENGINE_TEST_L1_A + 1u] == 3u);

    line = engine_test_run_real_task(
        NPU_ENGINE_MATRIX, NPU_MATRIX_GEMM, 0x102u,
        matrix_desc, &engine_test_l1[ENGINE_TEST_L1_MATRIX_DST],
        0u, 23u, 1u, &limits);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(engine_test_get_u32(
                   engine_test_l1,
                   ENGINE_TEST_L1_MATRIX_DST) == 23u);

    line = engine_test_run_real_task(
        NPU_ENGINE_VECTOR, NPU_VECTOR_ADD, 0x103u,
        vector_desc, &engine_test_l1[ENGINE_TEST_L1_VECTOR_DST],
        0u, 0u, 1u, &limits);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(engine_test_get_u32(
                   engine_test_l1,
                   ENGINE_TEST_L1_VECTOR_DST) == 0u);

    line = engine_test_run_real_task(
        NPU_ENGINE_COMPLEX, NPU_COMPLEX_ACT, 0x104u,
        complex_desc,
        &engine_test_l1[ENGINE_TEST_L1_COMPLEX_DST],
        0u, 64u, 1u, &limits);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(engine_test_l1[
                   ENGINE_TEST_L1_COMPLEX_DST] == 64u);
    return 0;
}

static int engine_test_pause_out_of_order_ecc(void)
{
    uint8_t descriptor[NPU_WIRE_VECTOR_DESC_BYTES];
    npu_wire_limits_t limits;
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    npu_engine_cycle_outputs_t outputs;
    engine_desc_server_t server;
    engine_done_message_t message;
    uint64_t stable_slot_word_tag;
    uint32_t corrected_pulses;
    uint32_t hold;
    int line;

    TEST_CHECK(engine_test_model_init(&limits));
    engine_test_put_u32(engine_test_l1,
                        ENGINE_TEST_L1_MATRIX_DST, 7u);
    engine_test_put_u32(engine_test_l1,
                        ENGINE_TEST_L1_VECTOR_SRC1, 9u);
    engine_test_vector_descriptor(descriptor);
    TEST_CHECK_STATUS(npu_engine_cycle_init(
                          &adapter, &engine_test_model,
                          NPU_ENGINE_VECTOR, &limits),
                      NPU_STATUS_SUCCESS);
    engine_test_idle_inputs(&inputs);
    engine_server_init(&server, descriptor);
    server.delay_until_full = 1u;
    server.reverse_response = 1u;
    server.corrected_enable = 1u;
    server.corrected_word = 5u;

    line = engine_test_submit(
        &adapter, &inputs,
        engine_test_metadata(0x211u, NPU_VECTOR_ADD,
                             9u, 0u, 0u));
    if (line != 0) {
        return line;
    }

    inputs.desc_rd_req_ready_i = 0u;
    npu_engine_cycle_step(&adapter, &inputs, &outputs);
    TEST_CHECK(outputs.desc_rd_req_valid_o == 1u);
    TEST_CHECK(outputs.desc_stall_o == 1u);
    stable_slot_word_tag =
        (uint64_t)outputs.desc_rd_slot_o |
        ((uint64_t)outputs.desc_rd_word_o << 8) |
        ((uint64_t)outputs.desc_rd_req_tag_o << 16);
    for (hold = 0u; hold < 3u; hold++) {
        npu_engine_cycle_step(&adapter, &inputs, &outputs);
        TEST_CHECK(outputs.desc_rd_req_valid_o == 1u);
        TEST_CHECK(((uint64_t)outputs.desc_rd_slot_o |
                    ((uint64_t)outputs.desc_rd_word_o << 8) |
                    ((uint64_t)outputs.desc_rd_req_tag_o << 16)) ==
                   stable_slot_word_tag);
    }
    inputs.desc_rd_req_ready_i = 1u;

    line = engine_test_run_until_done(
        &adapter, &inputs, &server,
        &engine_test_l1[ENGINE_TEST_L1_VECTOR_DST],
        0u, 16u, 1u, &corrected_pulses);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(server.max_count == NPU_ENGINE_DESC_TAGS);
    TEST_CHECK(server.reordered != 0u);
    TEST_CHECK(corrected_pulses == 1u);
    TEST_CHECK(adapter.ecc_corrected_count == 1u);
    TEST_CHECK(engine_test_model.perf.ecc_corrected_count == 1u);
    TEST_CHECK(engine_test_get_u32(
                   engine_test_l1,
                   ENGINE_TEST_L1_VECTOR_DST) == 16u);
    line = engine_test_collect_done(
        &adapter, &inputs, &message, 4u);
    if (line != 0) {
        return line;
    }
    return engine_test_check_done(
        &message, 0x211u, NPU_STATUS_SUCCESS,
        NPU_ENGINE_VECTOR, NPU_VECTOR_ADD, 1u);
}

static int engine_test_uncorrectable_ecc(void)
{
    uint8_t descriptor[NPU_WIRE_DMA_DESC_BYTES];
    npu_wire_limits_t limits;
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    engine_desc_server_t server;
    engine_done_message_t message;
    uint32_t corrected_pulses;
    uint32_t error_info;
    int line;

    TEST_CHECK(engine_test_model_init(&limits));
    engine_test_dma_descriptor(descriptor);
    engine_test_ddr[ENGINE_TEST_DDR_SRC] = 0x55u;
    TEST_CHECK_STATUS(npu_engine_cycle_init(
                          &adapter, &engine_test_model,
                          NPU_ENGINE_DMA, &limits),
                      NPU_STATUS_SUCCESS);
    engine_test_idle_inputs(&inputs);
    engine_server_init(&server, descriptor);
    server.uncorrectable_enable = 1u;
    server.uncorrectable_word = 4u;
    line = engine_test_submit(
        &adapter, &inputs,
        engine_test_metadata(0x221u, NPU_DMA_COPY_1D,
                             1u, 0u, 0u));
    if (line != 0) {
        return line;
    }
    line = engine_test_run_until_done(
        &adapter, &inputs, &server,
        &engine_test_l1[ENGINE_TEST_L1_A],
        0u, 0u, 0u, &corrected_pulses);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(engine_test_l1[ENGINE_TEST_L1_A] == 0u);
    line = engine_test_collect_done(
        &adapter, &inputs, &message, 1u);
    if (line != 0) {
        return line;
    }
    line = engine_test_check_done(
        &message, 0x221u, NPU_STATUS_BAD_DESC,
        NPU_ENGINE_DMA, NPU_DMA_COPY_1D, 0u);
    if (line != 0) {
        return line;
    }
    error_info = (uint32_t)(message.beat[0] >> 20);
    TEST_CHECK((error_info >> NPU_ENGINE_ERROR_STAGE_SHIFT) ==
               NPU_ENGINE_ERROR_DESC_PORT);
    TEST_CHECK(((error_info >> NPU_ENGINE_ERROR_WORD_SHIFT) & 0xffu) ==
               4u);
    TEST_CHECK(((message.beat[0] >> 52) & 0x0fffu) == 0u);
    return 0;
}

static int engine_test_operator_error(void)
{
    uint8_t descriptor[NPU_WIRE_VECTOR_DESC_BYTES];
    npu_wire_limits_t limits;
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    engine_desc_server_t server;
    engine_done_message_t message;
    uint32_t corrected_pulses;
    uint32_t error_info;
    int line;

    TEST_CHECK(engine_test_model_init(&limits));
    engine_test_vector_partial_descriptor(descriptor);
    for (line = 0; line < 9; line++) {
        engine_test_l1[0x0600u + (uint32_t)line] =
            line == 8 ? 127u : 1u;
        engine_test_l1[0x0610u + (uint32_t)line] = 1u;
    }
    TEST_CHECK_STATUS(npu_engine_cycle_init(
                          &adapter, &engine_test_model,
                          NPU_ENGINE_VECTOR, &limits),
                      NPU_STATUS_SUCCESS);
    engine_test_idle_inputs(&inputs);
    engine_server_init(&server, descriptor);
    line = engine_test_submit(
        &adapter, &inputs,
        engine_test_metadata(0x225u, NPU_VECTOR_ADD,
                             4u, 0u, 0u));
    if (line != 0) {
        return line;
    }
    line = engine_test_run_until_done(
        &adapter, &inputs, &server,
        &engine_test_l1[0x0620u],
        0u, 2u, 1u, &corrected_pulses);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(engine_test_l1[0x0620u] == 2u);
    for (line = 0; line < 8; line++) {
        TEST_CHECK(engine_test_l1[0x0620u + (uint32_t)line] == 2u);
    }
    TEST_CHECK(engine_test_l1[0x0628u] == 0u);
    line = engine_test_collect_done(
        &adapter, &inputs, &message, 1u);
    if (line != 0) {
        return line;
    }
    line = engine_test_check_done(
        &message, 0x225u, NPU_STATUS_NUMERIC_EXCEPTION,
        NPU_ENGINE_VECTOR, NPU_VECTOR_ADD, 8u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((message.beat[0] >> 52) & 0x0fffu) ==
               NPU_DONE_PARTIAL_DEST);
    error_info = (uint32_t)(message.beat[0] >> 20);
    TEST_CHECK((error_info >> NPU_ENGINE_ERROR_STAGE_SHIFT) ==
               NPU_ENGINE_ERROR_EXECUTE);
    TEST_CHECK(((error_info >> NPU_ENGINE_ERROR_DETAIL_SHIFT) &
                NPU_ENGINE_ERROR_DETAIL_MASK) ==
               NPU_STATUS_NUMERIC_EXCEPTION);
    return 0;
}

static int engine_test_decode_fault(void)
{
    uint8_t descriptor[NPU_WIRE_VECTOR_DESC_BYTES];
    npu_wire_limits_t limits;
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    engine_desc_server_t server;
    engine_done_message_t message;
    uint32_t corrected_pulses;
    uint32_t error_info;
    int line;

    TEST_CHECK(engine_test_model_init(&limits));
    engine_test_vector_descriptor(descriptor);
    engine_test_put_u64(descriptor, 0x20u,
                        ENGINE_TEST_MEMORY_BYTES);
    TEST_CHECK_STATUS(npu_engine_cycle_init(
                          &adapter, &engine_test_model,
                          NPU_ENGINE_VECTOR, &limits),
                      NPU_STATUS_SUCCESS);
    engine_test_idle_inputs(&inputs);
    engine_server_init(&server, descriptor);
    line = engine_test_submit(
        &adapter, &inputs,
        engine_test_metadata(0x226u, NPU_VECTOR_ADD,
                             5u, 0u, 0u));
    if (line != 0) {
        return line;
    }
    line = engine_test_run_until_done(
        &adapter, &inputs, &server,
        &engine_test_l1[ENGINE_TEST_L1_VECTOR_DST],
        0u, 0u, 0u, &corrected_pulses);
    if (line != 0) {
        return line;
    }
    line = engine_test_collect_done(
        &adapter, &inputs, &message, 1u);
    if (line != 0) {
        return line;
    }
    line = engine_test_check_done(
        &message, 0x226u, NPU_STATUS_ADDR_FAULT,
        NPU_ENGINE_VECTOR, NPU_VECTOR_ADD, 0u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK((message.beat[1] & UINT64_C(0x0000ffffffffffff)) ==
               ENGINE_TEST_MEMORY_BYTES);
    TEST_CHECK(((message.beat[0] >> 52) & 0x0fffu) ==
               NPU_DONE_FAULT_ADDR_IS_L1);
    error_info = (uint32_t)(message.beat[0] >> 20);
    TEST_CHECK((error_info >> NPU_ENGINE_ERROR_STAGE_SHIFT) ==
               NPU_ENGINE_ERROR_DESC_DECODE);
    return 0;
}

static int engine_test_decode_span_fault(void)
{
    uint8_t descriptor[NPU_WIRE_VECTOR_DESC_BYTES];
    npu_wire_limits_t limits;
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    engine_desc_server_t server;
    engine_done_message_t message;
    uint32_t corrected_pulses;
    int line;

    TEST_CHECK(engine_test_model_init(&limits));
    engine_test_vector_descriptor(descriptor);
    engine_test_put_u32(descriptor, 0x40u, 2u);
    engine_test_put_u64(descriptor, 0x20u,
                        ENGINE_TEST_MEMORY_BYTES - 4u);
    TEST_CHECK_STATUS(npu_engine_cycle_init(
                          &adapter, &engine_test_model,
                          NPU_ENGINE_VECTOR, &limits),
                      NPU_STATUS_SUCCESS);
    engine_test_idle_inputs(&inputs);
    engine_server_init(&server, descriptor);
    line = engine_test_submit(
        &adapter, &inputs,
        engine_test_metadata(0x228u, NPU_VECTOR_ADD,
                             5u, 0u, 0u));
    if (line != 0) {
        return line;
    }
    line = engine_test_run_until_done(
        &adapter, &inputs, &server,
        &engine_test_l1[ENGINE_TEST_L1_VECTOR_DST],
        0u, 0u, 0u, &corrected_pulses);
    if (line != 0) {
        return line;
    }
    line = engine_test_collect_done(
        &adapter, &inputs, &message, 1u);
    if (line != 0) {
        return line;
    }
    line = engine_test_check_done(
        &message, 0x228u, NPU_STATUS_ADDR_FAULT,
        NPU_ENGINE_VECTOR, NPU_VECTOR_ADD, 0u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK((message.beat[1] &
                UINT64_C(0x0000ffffffffffff)) ==
               ENGINE_TEST_MEMORY_BYTES);
    TEST_CHECK(((message.beat[0] >> 52) & 0x0fffu) ==
               NPU_DONE_FAULT_ADDR_IS_L1);
    return 0;
}

static int engine_test_execute_fault_exact_address(void)
{
    uint8_t descriptor[NPU_WIRE_DMA_DESC_BYTES];
    npu_wire_limits_t limits;
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    engine_desc_server_t server;
    engine_done_message_t message;
    uint32_t corrected_pulses;
    uint32_t error_info;
    int line;

    TEST_CHECK(engine_test_model_init(&limits));
    engine_test_dma_descriptor(descriptor);

    /*
     * The descriptor address range is legal according to the engine's
     * configured system-address limit, but the backing test memory ends
     * after the first source byte. This reaches the functional access check
     * and proves that Beat 1 reports the first invalid byte rather than the
     * descriptor base address.
     */
    limits.gaddr_limit = ENGINE_TEST_MEMORY_BYTES + 0x100u;
    engine_test_put_u64(descriptor, 0x08u,
                        ENGINE_TEST_MEMORY_BYTES - 1u);
    engine_test_ddr[ENGINE_TEST_MEMORY_BYTES - 1u] = 0x5au;
    engine_test_l1[ENGINE_TEST_L1_A] = 0xa5u;

    TEST_CHECK_STATUS(npu_engine_cycle_init(
                          &adapter, &engine_test_model,
                          NPU_ENGINE_DMA, &limits),
                      NPU_STATUS_SUCCESS);
    engine_test_idle_inputs(&inputs);
    engine_server_init(&server, descriptor);
    line = engine_test_submit(
        &adapter, &inputs,
        engine_test_metadata(0x227u, NPU_DMA_COPY_1D,
                             6u, 0u, 0u));
    if (line != 0) {
        return line;
    }
    line = engine_test_run_until_done(
        &adapter, &inputs, &server,
        &engine_test_l1[ENGINE_TEST_L1_A],
        0xa5u, 0xa5u, 1u, &corrected_pulses);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(corrected_pulses == 0u);
    TEST_CHECK(engine_test_l1[ENGINE_TEST_L1_A] == 0xa5u);
    line = engine_test_collect_done(
        &adapter, &inputs, &message, 1u);
    if (line != 0) {
        return line;
    }
    line = engine_test_check_done(
        &message, 0x227u, NPU_STATUS_ADDR_FAULT,
        NPU_ENGINE_DMA, NPU_DMA_COPY_1D, 0u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK((message.beat[1] &
                UINT64_C(0x0000ffffffffffff)) ==
               ENGINE_TEST_MEMORY_BYTES);
    TEST_CHECK(((message.beat[0] >> 52) & 0x0fffu) == 0u);
    error_info = (uint32_t)(message.beat[0] >> 20);
    TEST_CHECK((error_info >> NPU_ENGINE_ERROR_STAGE_SHIFT) ==
               NPU_ENGINE_ERROR_EXECUTE);
    return 0;
}

static int engine_test_metadata_errors(void)
{
    npu_wire_limits_t limits;
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    engine_done_message_t message;
    uint64_t metadata;
    int line;

    TEST_CHECK(engine_test_model_init(&limits));
    TEST_CHECK_STATUS(npu_engine_cycle_init(
                          &adapter, &engine_test_model,
                          NPU_ENGINE_VECTOR, &limits),
                      NPU_STATUS_SUCCESS);
    engine_test_idle_inputs(&inputs);
    metadata = engine_test_metadata(
        0x231u, NPU_VECTOR_ADD, 0u, 0u, 0u) |
        (UINT64_C(1) << 45);
    line = engine_test_submit(&adapter, &inputs, metadata);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(adapter.state == NPU_ENGINE_CYCLE_DONE);
    line = engine_test_collect_done(
        &adapter, &inputs, &message, 1u);
    if (line != 0) {
        return line;
    }
    line = engine_test_check_done(
        &message, 0x231u, NPU_STATUS_BAD_DESC,
        NPU_ENGINE_VECTOR, NPU_VECTOR_ADD, 0u);
    if (line != 0) {
        return line;
    }

    metadata = engine_test_metadata(
        0x232u, NPU_DMA_COPY_1D, 0u, 0u, 0u);
    line = engine_test_submit(&adapter, &inputs, metadata);
    if (line != 0) {
        return line;
    }
    line = engine_test_collect_done(
        &adapter, &inputs, &message, 1u);
    if (line != 0) {
        return line;
    }
    return engine_test_check_done(
        &message, 0x232u, NPU_STATUS_ILLEGAL_OPCODE,
        NPU_ENGINE_VECTOR, NPU_DMA_COPY_1D, 0u);
}

static int engine_test_abort_drain(void)
{
    uint8_t descriptor[NPU_WIRE_DMA_DESC_BYTES];
    npu_wire_limits_t limits;
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    npu_engine_cycle_outputs_t outputs;
    engine_desc_server_t server;
    engine_done_message_t message;
    uint32_t corrected_pulses;
    uint8_t words_after_abort;
    uint32_t cycle;
    int line;

    TEST_CHECK(engine_test_model_init(&limits));
    engine_test_dma_descriptor(descriptor);
    engine_test_ddr[ENGINE_TEST_DDR_SRC] = 0x5au;
    TEST_CHECK_STATUS(npu_engine_cycle_init(
                          &adapter, &engine_test_model,
                          NPU_ENGINE_DMA, &limits),
                      NPU_STATUS_SUCCESS);
    engine_test_idle_inputs(&inputs);
    engine_server_init(&server, descriptor);
    server.delay_until_full = 1u;
    line = engine_test_submit(
        &adapter, &inputs,
        engine_test_metadata(0x241u, NPU_DMA_COPY_1D,
                             2u, 0u, 0u));
    if (line != 0) {
        return line;
    }

    while (server.count < 5u) {
        npu_engine_cycle_step(&adapter, &inputs, &outputs);
        line = engine_server_observe(&server, &inputs, &outputs);
        if (line != 0) {
            return line;
        }
        TEST_CHECK(outputs.eng_done_valid_o == 0u);
    }
    inputs.eng_abort_i = 1u;
    npu_engine_cycle_step(&adapter, &inputs, &outputs);
    line = engine_server_observe(&server, &inputs, &outputs);
    if (line != 0) {
        return line;
    }
    words_after_abort = adapter.next_desc_word;
    TEST_CHECK(adapter.aborting != 0u);
    TEST_CHECK(outputs.eng_done_valid_o == 0u);

    for (cycle = 0u; cycle < 3u; cycle++) {
        npu_engine_cycle_step(&adapter, &inputs, &outputs);
        line = engine_server_observe(&server, &inputs, &outputs);
        if (line != 0) {
            return line;
        }
        TEST_CHECK(adapter.next_desc_word == words_after_abort);
        TEST_CHECK(outputs.eng_done_valid_o == 0u);
        TEST_CHECK(outputs.eng_quiescent_o == 0u);
    }
    server.release = 1u;
    server.delay_until_full = 0u;
    line = engine_test_run_until_done(
        &adapter, &inputs, &server,
        &engine_test_l1[ENGINE_TEST_L1_A],
        0u, 0u, 0u, &corrected_pulses);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(engine_test_l1[ENGINE_TEST_L1_A] == 0u);
    line = engine_test_collect_done(
        &adapter, &inputs, &message, 2u);
    if (line != 0) {
        return line;
    }
    line = engine_test_check_done(
        &message, 0x241u, NPU_STATUS_ABORTED,
        NPU_ENGINE_DMA, NPU_DMA_COPY_1D, 0u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((message.beat[0] >> 52) & 0x0fffu) ==
               NPU_DONE_ABORT_DRAINED);
    TEST_CHECK(adapter.state == NPU_ENGINE_CYCLE_IDLE);
    npu_engine_cycle_step(&adapter, &inputs, &outputs);
    TEST_CHECK(outputs.eng_quiescent_o == 1u);
    TEST_CHECK(outputs.eng_req_ready_o == 0u);
    inputs.eng_abort_i = 0u;
    npu_engine_cycle_step(&adapter, &inputs, &outputs);
    TEST_CHECK(outputs.eng_req_ready_o == 1u);
    return 0;
}

static int engine_test_cancel_timeout_drain(void)
{
    uint8_t descriptor[NPU_WIRE_DMA_DESC_BYTES];
    npu_wire_limits_t limits;
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    npu_engine_cycle_outputs_t outputs;
    engine_desc_server_t server;
    engine_done_message_t message;
    uint32_t corrected_pulses;
    uint32_t error_info;
    uint8_t words_after_cancel;
    uint8_t outstanding_after_cancel;
    uint8_t words_before_cancel;
    uint8_t requests_before_cancel;
    uint32_t cycle;
    int line;

    TEST_CHECK(engine_test_model_init(&limits));
    engine_test_dma_descriptor(descriptor);
    engine_test_ddr[ENGINE_TEST_DDR_SRC] = 0x6bu;
    TEST_CHECK_STATUS(npu_engine_cycle_init(
                          &adapter, &engine_test_model,
                          NPU_ENGINE_DMA, &limits),
                      NPU_STATUS_SUCCESS);
    engine_test_idle_inputs(&inputs);
    engine_server_init(&server, descriptor);
    server.delay_until_full = 1u;
    line = engine_test_submit(
        &adapter, &inputs,
        engine_test_metadata(0x261u, NPU_DMA_COPY_1D,
                             2u, 0u, 0u));
    if (line != 0) {
        return line;
    }

    while (server.count < 5u) {
        npu_engine_cycle_step(&adapter, &inputs, &outputs);
        line = engine_server_observe(
            &server, &inputs, &outputs);
        if (line != 0) {
            return line;
        }
    }

    /*
     * An unsupported status keeps the cancellation producer paused. The
     * active descriptor fetch continues because no cancellation handshake
     * has occurred.
     */
    inputs.eng_cancel_valid_i = 1u;
    inputs.eng_cancel_status_i =
        (uint8_t)NPU_STATUS_SUCCESS;
    words_after_cancel = adapter.next_desc_word;
    npu_engine_cycle_step(&adapter, &inputs, &outputs);
    line = engine_server_observe(&server, &inputs, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(outputs.eng_cancel_ready_o == 0u);
    TEST_CHECK(adapter.canceling == 0u);
    TEST_CHECK(adapter.next_desc_word >
               words_after_cancel);

    inputs.eng_cancel_status_i =
        (uint8_t)NPU_STATUS_TIMEOUT;
    inputs.desc_rd_req_ready_i = 0u;
    words_before_cancel = adapter.next_desc_word;
    requests_before_cancel = server.count;
    npu_engine_cycle_step(&adapter, &inputs, &outputs);
    line = engine_server_observe(&server, &inputs, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(outputs.eng_cancel_ready_o == 1u);
    TEST_CHECK(outputs.desc_rd_req_valid_o == 1u);
    TEST_CHECK(outputs.desc_stall_o == 1u);
    TEST_CHECK(adapter.canceling != 0u);
    TEST_CHECK(adapter.pending_status ==
               NPU_STATUS_TIMEOUT);
    TEST_CHECK(adapter.desc_req_hold_valid == 0u);
    TEST_CHECK(adapter.next_desc_word ==
               words_before_cancel);
    TEST_CHECK(server.count == requests_before_cancel);
    words_after_cancel = adapter.next_desc_word;
    outstanding_after_cancel = adapter.desc_outstanding;
    TEST_CHECK(outstanding_after_cancel != 0u);
    inputs.eng_cancel_valid_i = 0u;
    inputs.eng_cancel_status_i = 0u;
    inputs.desc_rd_req_ready_i = 1u;

    for (cycle = 0u; cycle < 3u; cycle++) {
        npu_engine_cycle_step(&adapter, &inputs, &outputs);
        line = engine_server_observe(
            &server, &inputs, &outputs);
        if (line != 0) {
            return line;
        }
        TEST_CHECK(outputs.desc_rd_req_valid_o == 0u);
        TEST_CHECK(adapter.next_desc_word ==
                   words_after_cancel);
        TEST_CHECK(adapter.desc_outstanding ==
                   outstanding_after_cancel);
        TEST_CHECK(outputs.eng_done_valid_o == 0u);
    }

    server.release = 1u;
    server.delay_until_full = 0u;
    line = engine_test_run_until_done(
        &adapter, &inputs, &server,
        &engine_test_l1[ENGINE_TEST_L1_A],
        0u, 0u, 0u, &corrected_pulses);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(server.count == 0u);
    TEST_CHECK(adapter.desc_outstanding == 0u);
    TEST_CHECK(engine_test_l1[ENGINE_TEST_L1_A] == 0u);
    line = engine_test_collect_done(
        &adapter, &inputs, &message, 3u);
    if (line != 0) {
        return line;
    }
    line = engine_test_check_done(
        &message, 0x261u, NPU_STATUS_TIMEOUT,
        NPU_ENGINE_DMA, NPU_DMA_COPY_1D, 0u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((message.beat[0] >> 52) & 0x0fffu) ==
               0u);
    error_info = (uint32_t)(message.beat[0] >> 20);
    TEST_CHECK((error_info >> NPU_ENGINE_ERROR_STAGE_SHIFT) ==
               NPU_ENGINE_ERROR_EXECUTE);
    TEST_CHECK(((error_info >>
                 NPU_ENGINE_ERROR_DETAIL_SHIFT) &
                NPU_ENGINE_ERROR_DETAIL_MASK) ==
               NPU_STATUS_TIMEOUT);
    TEST_CHECK(((error_info >>
                 NPU_ENGINE_ERROR_WORD_SHIFT) & 0xffu) ==
               NPU_ENGINE_INVALID_DESC_WORD);
    TEST_CHECK((error_info & 0xffu) ==
               NPU_DMA_COPY_1D);
    return 0;
}

static int engine_test_cancel_aborted_reuse(void)
{
    uint8_t descriptor[NPU_WIRE_DMA_DESC_BYTES];
    npu_wire_limits_t limits;
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    npu_engine_cycle_outputs_t outputs;
    engine_desc_server_t server;
    engine_done_message_t message;
    uint32_t error_info;
    uint32_t cycle;
    uint64_t metadata;
    int line;

    TEST_CHECK(engine_test_model_init(&limits));
    engine_test_dma_descriptor(descriptor);
    engine_test_ddr[ENGINE_TEST_DDR_SRC] = 0x7cu;
    TEST_CHECK_STATUS(npu_engine_cycle_init(
                          &adapter, &engine_test_model,
                          NPU_ENGINE_DMA, &limits),
                      NPU_STATUS_SUCCESS);
    engine_test_idle_inputs(&inputs);
    engine_server_init(&server, descriptor);
    line = engine_test_submit(
        &adapter, &inputs,
        engine_test_metadata(0x262u, NPU_DMA_COPY_1D,
                             2u, 0u, 0u));
    if (line != 0) {
        return line;
    }

    for (cycle = 0u;
         cycle < ENGINE_TEST_MAX_CYCLES &&
             adapter.state != NPU_ENGINE_CYCLE_EXECUTE;
         cycle++) {
        engine_server_drive(&server, &inputs);
        npu_engine_cycle_step(&adapter, &inputs, &outputs);
        line = engine_server_observe(
            &server, &inputs, &outputs);
        if (line != 0) {
            return line;
        }
    }
    TEST_CHECK(adapter.state == NPU_ENGINE_CYCLE_EXECUTE);
    TEST_CHECK(server.count == 0u);

    inputs.eng_cancel_valid_i = 1u;
    inputs.eng_cancel_status_i =
        (uint8_t)NPU_STATUS_ABORTED;
    npu_engine_cycle_step(&adapter, &inputs, &outputs);
    TEST_CHECK(outputs.eng_cancel_ready_o == 1u);
    TEST_CHECK(adapter.state == NPU_ENGINE_CYCLE_DONE);
    TEST_CHECK(engine_test_l1[ENGINE_TEST_L1_A] == 0u);
    inputs.eng_cancel_valid_i = 0u;
    inputs.eng_cancel_status_i = 0u;

    line = engine_test_collect_done(
        &adapter, &inputs, &message, 2u);
    if (line != 0) {
        return line;
    }
    line = engine_test_check_done(
        &message, 0x262u, NPU_STATUS_ABORTED,
        NPU_ENGINE_DMA, NPU_DMA_COPY_1D, 0u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((message.beat[0] >> 52) & 0x0fffu) ==
               NPU_DONE_ABORT_DRAINED);
    error_info = (uint32_t)(message.beat[0] >> 20);
    TEST_CHECK((error_info >> NPU_ENGINE_ERROR_STAGE_SHIFT) ==
               NPU_ENGINE_ERROR_ABORT);

    /*
     * Reclaiming Beat 2 returns the adapter to IDLE. A new task can be
     * accepted immediately; use a metadata error so this reuse check does
     * not need a second descriptor transaction.
     */
    metadata = engine_test_metadata(
        0x263u, NPU_DMA_COPY_1D, 2u, 0u, 0u) |
        (UINT64_C(1) << 45);
    line = engine_test_submit(&adapter, &inputs, metadata);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(adapter.state == NPU_ENGINE_CYCLE_DONE);
    line = engine_test_collect_done(
        &adapter, &inputs, &message, 1u);
    if (line != 0) {
        return line;
    }
    return engine_test_check_done(
        &message, 0x263u, NPU_STATUS_BAD_DESC,
        NPU_ENGINE_DMA, NPU_DMA_COPY_1D, 0u);
}

static int engine_test_reset(void)
{
    uint8_t descriptor[NPU_WIRE_VECTOR_DESC_BYTES];
    npu_wire_limits_t limits;
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    npu_engine_cycle_outputs_t outputs;
    engine_desc_server_t server;
    int line;

    TEST_CHECK(engine_test_model_init(&limits));
    engine_test_vector_descriptor(descriptor);
    TEST_CHECK_STATUS(npu_engine_cycle_init(
                          &adapter, &engine_test_model,
                          NPU_ENGINE_VECTOR, &limits),
                      NPU_STATUS_SUCCESS);
    engine_test_idle_inputs(&inputs);
    engine_server_init(&server, descriptor);
    server.delay_until_full = 1u;
    line = engine_test_submit(
        &adapter, &inputs,
        engine_test_metadata(0x251u, NPU_VECTOR_ADD,
                             1u, 0u, 0u));
    if (line != 0) {
        return line;
    }
    npu_engine_cycle_step(&adapter, &inputs, &outputs);
    line = engine_server_observe(&server, &inputs, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(adapter.desc_outstanding != 0u);

    inputs.reset_n = 0u;
    npu_engine_cycle_step(&adapter, &inputs, &outputs);
    TEST_CHECK(outputs.eng_quiescent_o == 1u);
    TEST_CHECK(outputs.eng_busy_o == 0u);
    TEST_CHECK(outputs.desc_rd_req_valid_o == 0u);
    TEST_CHECK(outputs.desc_rd_rsp_ready_o == 0u);
    TEST_CHECK(outputs.eng_done_valid_o == 0u);
    TEST_CHECK(adapter.desc_outstanding == 0u);
    TEST_CHECK(adapter.state == NPU_ENGINE_CYCLE_IDLE);
    TEST_CHECK(adapter.cycle == 0u);

    inputs.reset_n = 1u;
    inputs.eng_req_valid_i = 0u;
    npu_engine_cycle_step(&adapter, &inputs, &outputs);
    TEST_CHECK(outputs.eng_req_ready_o == 1u);
    TEST_CHECK(outputs.eng_quiescent_o == 1u);
    return 0;
}

int test_engine_cycle(void)
{
    int line;

    line = engine_test_four_real_tasks();
    if (line != 0) {
        return line;
    }
    line = engine_test_pause_out_of_order_ecc();
    if (line != 0) {
        return line;
    }
    line = engine_test_uncorrectable_ecc();
    if (line != 0) {
        return line;
    }
    line = engine_test_operator_error();
    if (line != 0) {
        return line;
    }
    line = engine_test_decode_fault();
    if (line != 0) {
        return line;
    }
    line = engine_test_decode_span_fault();
    if (line != 0) {
        return line;
    }
    line = engine_test_execute_fault_exact_address();
    if (line != 0) {
        return line;
    }
    line = engine_test_metadata_errors();
    if (line != 0) {
        return line;
    }
    line = engine_test_abort_drain();
    if (line != 0) {
        return line;
    }
    line = engine_test_cancel_timeout_drain();
    if (line != 0) {
        return line;
    }
    line = engine_test_cancel_aborted_reuse();
    if (line != 0) {
        return line;
    }
    return engine_test_reset();
}

#if defined(NPU_ENGINE_CYCLE_STANDALONE)
int main(void)
{
    return test_engine_cycle();
}
#endif
