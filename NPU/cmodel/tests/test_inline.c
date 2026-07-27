#include "test_util.h"

#include "npu_engine_cycle.h"
#include "npu_inline.h"
#include "npu_ts_cycle.h"
#include "npu_wire.h"

#include <string.h>

#define INLINE_L1_BYTES NPU_REF_L1_BYTES
#define INLINE_DDR_BYTES 8192u

static uint8_t inline_l1[INLINE_L1_BYTES];
static uint8_t inline_ddr[INLINE_DDR_BYTES];

static void inline_payload_set(uint8_t payload[10],
                               uint32_t lsb,
                               uint32_t width,
                               uint64_t value)
{
    uint32_t bit;

    for (bit = 0u; bit < width; bit++) {
        uint32_t payload_bit = lsb + bit;
        uint8_t mask =
            (uint8_t)(1u << (payload_bit & 7u));

        if (((value >> bit) & UINT64_C(1)) != 0u) {
            payload[payload_bit >> 3u] |= mask;
        } else {
            payload[payload_bit >> 3u] &= (uint8_t)~mask;
        }
    }
}

static uint64_t inline_load_u64(const uint8_t *bytes)
{
    uint64_t value = 0u;
    uint32_t index;

    for (index = 0u; index < 8u; index++) {
        value |= (uint64_t)bytes[index] << (index * 8u);
    }
    return value;
}

static void inline_store_u64(uint8_t *bytes, uint64_t value)
{
    uint32_t index;

    for (index = 0u; index < 8u; index++) {
        bytes[index] = (uint8_t)(value >> (index * 8u));
    }
}

static npu_cmd_t inline_command(const uint8_t payload[10],
                                uint16_t command_id,
                                npu_engine_t engine,
                                uint8_t opcode,
                                npu_dtype_t dtype)
{
    npu_cmd_t cmd;

    (void)memset(&cmd, 0, sizeof(cmd));
    cmd.command_id = command_id;
    cmd.engine = engine;
    cmd.opcode = opcode;
    cmd.wait_event[0] = npu_event_none();
    cmd.wait_event[1] = npu_event_none();
    cmd.signal_event = npu_event_none();
    cmd.inline_payload_lo = inline_load_u64(payload);
    cmd.inline_payload_hi =
        (uint16_t)payload[8] |
        (uint16_t)((uint16_t)payload[9] << 8u);
    cmd.inline_format = 1u;
    cmd.inline_dtype = dtype;
    return cmd;
}

static void inline_wire(const npu_cmd_t *cmd,
                        uint8_t wire[NPU_WIRE_CMD_BYTES],
                        uint64_t *low,
                        uint64_t *high)
{
    npu_cmd_encode(cmd, low, high);
    inline_store_u64(&wire[0], *low);
    inline_store_u64(&wire[8], *high);
}

static int inline_test_opcode_table(void)
{
    static const uint8_t opcode[33] = {
        NPU_CTRL_NOP,
        NPU_CTRL_EVENT_SIGNAL,
        NPU_CTRL_EVENT_REARM,
        NPU_CTRL_EVENT_JOIN,
        NPU_CTRL_GLOBAL_FENCE,
        NPU_DMA_COPY_1D,
        NPU_DMA_COPY_ND,
        NPU_DMA_FILL,
        NPU_DMA_TRANSPOSE_2D,
        NPU_DMA_PACK,
        NPU_DMA_SPLIT,
        NPU_DMA_GATHER_ND,
        NPU_MATRIX_GEMM,
        NPU_MATRIX_BMM,
        NPU_MATRIX_GEMM_ACCUM,
        NPU_MATRIX_GEMM_ZERO,
        NPU_VECTOR_ADD,
        NPU_VECTOR_SUB,
        NPU_VECTOR_MUL,
        NPU_VECTOR_FMA,
        NPU_VECTOR_MAX,
        NPU_VECTOR_MIN,
        NPU_VECTOR_CMP,
        NPU_VECTOR_SELECT,
        NPU_VECTOR_CLAMP,
        NPU_VECTOR_RELU,
        NPU_COMPLEX_ACT,
        NPU_COMPLEX_SOFTMAX,
        NPU_COMPLEX_NORM,
        NPU_COMPLEX_ROPE,
        NPU_COMPLEX_STAT,
        NPU_COMPLEX_RECIP,
        NPU_COMPLEX_ADD_RESCALE
    };
    static const npu_engine_t engine[33] = {
        NPU_ENGINE_CONTROL,
        NPU_ENGINE_CONTROL,
        NPU_ENGINE_CONTROL,
        NPU_ENGINE_CONTROL,
        NPU_ENGINE_CONTROL,
        NPU_ENGINE_DMA,
        NPU_ENGINE_DMA,
        NPU_ENGINE_DMA,
        NPU_ENGINE_DMA,
        NPU_ENGINE_DMA,
        NPU_ENGINE_DMA,
        NPU_ENGINE_DMA,
        NPU_ENGINE_MATRIX,
        NPU_ENGINE_MATRIX,
        NPU_ENGINE_MATRIX,
        NPU_ENGINE_MATRIX,
        NPU_ENGINE_VECTOR,
        NPU_ENGINE_VECTOR,
        NPU_ENGINE_VECTOR,
        NPU_ENGINE_VECTOR,
        NPU_ENGINE_VECTOR,
        NPU_ENGINE_VECTOR,
        NPU_ENGINE_VECTOR,
        NPU_ENGINE_VECTOR,
        NPU_ENGINE_VECTOR,
        NPU_ENGINE_VECTOR,
        NPU_ENGINE_COMPLEX,
        NPU_ENGINE_COMPLEX,
        NPU_ENGINE_COMPLEX,
        NPU_ENGINE_COMPLEX,
        NPU_ENGINE_COMPLEX,
        NPU_ENGINE_COMPLEX,
        NPU_ENGINE_COMPLEX
    };
    uint32_t index;

    for (index = 0u; index < 33u; index++) {
        npu_engine_t decoded_engine = NPU_ENGINE_CONTROL;
        uint8_t decoded_opcode = 0u;
        uint8_t encoded_opcode = 0xffu;

        TEST_CHECK(
            npu_inline_opcode_decode(
                (uint8_t)index, &decoded_engine,
                &decoded_opcode) != 0);
        TEST_CHECK(decoded_engine == engine[index]);
        TEST_CHECK(decoded_opcode == opcode[index]);
        TEST_CHECK(
            npu_inline_opcode_encode(
                decoded_engine, decoded_opcode,
                &encoded_opcode) != 0);
        TEST_CHECK(encoded_opcode == index);
    }
    return 0;
}

static int inline_test_vector_and_header(npu_model_t *model,
                                         npu_wire_limits_t *limits)
{
    uint8_t payload[10] = {0};
    uint8_t wire[NPU_WIRE_CMD_BYTES];
    npu_cmd_t encoded;
    npu_cmd_t decoded;
    npu_task_request_t request;
    npu_wire_meta_t meta;
    uint64_t low;
    uint64_t high;
    uint64_t progress;
    uint32_t index;

    inline_payload_set(payload, 64u, 16u, 0x100u);
    inline_payload_set(payload, 48u, 16u, 0x110u);
    inline_payload_set(payload, 32u, 16u, 0u);
    inline_payload_set(payload, 16u, 16u, 0x120u);
    inline_payload_set(payload, 11u, 5u, 1u);
    inline_payload_set(payload, 6u, 5u, 3u);
    encoded = inline_command(
        payload, 0x155u, NPU_ENGINE_VECTOR,
        NPU_VECTOR_ADD, NPU_DTYPE_INT8);
    encoded.header_flags = (1u << 0) | (1u << 2) | (1u << 4);
    encoded.timeout_class = 2u;
    encoded.wait_event[0].id = 2u;
    encoded.wait_event[0].generation = 0u;
    encoded.signal_event.id = 7u;
    encoded.signal_event.generation = 0u;
    inline_wire(&encoded, wire, &low, &high);

    TEST_CHECK((high >> 63u) == 0u);
    TEST_CHECK(((high >> 58u) & 0x3fu) == 16u);
    TEST_CHECK(((high >> 48u) & 0x3ffu) == 0x155u);
    TEST_CHECK(((high >> 40u) & 0xffu) == 2u);
    TEST_CHECK(((high >> 32u) & 0xffu) == 0xffu);
    TEST_CHECK(((high >> 24u) & 0xffu) == 7u);
    TEST_CHECK(((high >> 20u) & 0x0fu) == 0x0bu);
    TEST_CHECK(((high >> 18u) & 0x03u) == 2u);
    TEST_CHECK(((high >> 16u) & 0x03u) == NPU_DTYPE_INT8);

    TEST_CHECK_STATUS(
        npu_cmd_decode(low, high, &decoded), NPU_STATUS_SUCCESS);
    TEST_CHECK(decoded.inline_format == 1u);
    TEST_CHECK(decoded.header_version == 0u);
    TEST_CHECK(decoded.engine == NPU_ENGINE_VECTOR);
    TEST_CHECK(decoded.opcode == NPU_VECTOR_ADD);
    TEST_CHECK(decoded.command_id == 0x155u);
    TEST_CHECK(decoded.wait_event[0].id == 2u);
    TEST_CHECK(decoded.wait_event[0].generation == 0u);
    TEST_CHECK(decoded.wait_event[1].id == NPU_EVENT_NONE_ID);
    TEST_CHECK(decoded.wait_event[1].generation ==
               NPU_EVENT_NONE_GENERATION);
    TEST_CHECK_STATUS(
        npu_cmd_decode(
            low,
            (high & ~(UINT64_C(0x3f) << 58u)) |
                (UINT64_C(33) << 58u),
            &decoded),
        NPU_STATUS_ILLEGAL_OPCODE);

    TEST_CHECK_STATUS(
        npu_wire_decode_task(
            wire, sizeof(wire), (const uint8_t *)0, 0u,
            limits, &request, &meta),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(request.desc_bytes == NPU_WIRE_CMD_BYTES);
    TEST_CHECK(request.desc_version == NPU_INLINE_DESC_VERSION);
    TEST_CHECK(request.desc.vector.rows == 2u);
    TEST_CHECK(request.desc.vector.length == 4u);
    TEST_CHECK(request.desc.vector.src0.addr == 0x1000u);
    TEST_CHECK(request.desc.vector.src1.addr == 0x1100u);
    TEST_CHECK(request.desc.vector.dst.addr == 0x1200u);
    for (index = 0u; index < 8u; index++) {
        inline_l1[0x1000u + index] = (uint8_t)(index + 1u);
        inline_l1[0x1100u + index] = (uint8_t)(10u + index);
    }
    TEST_CHECK_STATUS(
        npu_vector_execute(
            model, request.cmd.opcode,
            &request.desc.vector, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 8u);
    for (index = 0u; index < 8u; index++) {
        TEST_CHECK(inline_l1[0x1200u + index] ==
                   (uint8_t)(11u + index * 2u));
    }
    return 0;
}

static int inline_test_control(npu_model_t *model,
                               npu_wire_limits_t *limits)
{
    uint8_t payload[10] = {0};
    uint8_t wire[NPU_WIRE_CMD_BYTES];
    npu_cmd_t cmd;
    npu_task_request_t request;
    npu_wire_meta_t meta;
    uint64_t low;
    uint64_t high;

    inline_payload_set(payload, 76u, 4u, 0x0fu);
    cmd = inline_command(
        payload, 1u, NPU_ENGINE_CONTROL,
        NPU_CTRL_GLOBAL_FENCE, NPU_DTYPE_INT8);
    inline_wire(&cmd, wire, &low, &high);
    TEST_CHECK_STATUS(
        npu_wire_decode_task(
            wire, sizeof(wire), (const uint8_t *)0, 0u,
            limits, &request, &meta),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(request.cmd.engine == NPU_ENGINE_CONTROL);
    TEST_CHECK(request.desc.control.engine_mask == 0x0fu);
    TEST_CHECK(request.desc.control.join_mode == 0u);

    (void)memset(payload, 0, sizeof(payload));
    cmd = inline_command(
        payload, 5u, NPU_ENGINE_CONTROL,
        NPU_CTRL_EVENT_REARM, NPU_DTYPE_INT8);
    cmd.signal_event.id = 5u;
    cmd.signal_event.generation = 0u;
    inline_wire(&cmd, wire, &low, &high);
    TEST_CHECK_STATUS(
        npu_event_reserve(model, 5u, 0u, 99u),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_event_signal(
            model, (npu_event_ref_t){5u, 0u},
            NPU_STATUS_SUCCESS),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_submit_wire(model, low, high),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_run(model, 100u), NPU_STATUS_SUCCESS);
    TEST_CHECK(model->events[5u].state == NPU_EVENT_FREE);
    TEST_CHECK(model->events[5u].generation == 1u);

    TEST_CHECK_STATUS(
        npu_event_reserve(model, 6u, 0u, 100u),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_event_signal(
            model, (npu_event_ref_t){6u, 0u},
            NPU_STATUS_SUCCESS),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_event_reserve(model, 7u, 0u, 101u),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_event_signal(
            model, (npu_event_ref_t){7u, 0u},
            NPU_STATUS_SUCCESS),
        NPU_STATUS_SUCCESS);
    cmd = inline_command(
        payload, 6u, NPU_ENGINE_CONTROL,
        NPU_CTRL_EVENT_JOIN, NPU_DTYPE_INT8);
    cmd.wait_event[0].id = 6u;
    cmd.wait_event[0].generation = 0u;
    cmd.wait_event[1].id = 7u;
    cmd.wait_event[1].generation = 0u;
    cmd.signal_event.id = 5u;
    cmd.signal_event.generation = 0u;
    inline_wire(&cmd, wire, &low, &high);
    TEST_CHECK_STATUS(
        npu_model_submit_wire(model, low, high),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_model_run(model, 100u), NPU_STATUS_SUCCESS);
    TEST_CHECK(model->events[5u].state == NPU_EVENT_SUCCESS);
    TEST_CHECK(model->events[5u].generation == 1u);
    return 0;
}

static int inline_test_frontend_response_id(npu_model_t *model)
{
    uint8_t payload[10] = {0};
    uint8_t wire[NPU_WIRE_CMD_BYTES];
    npu_host_inputs_t inputs;
    npu_host_outputs_t outputs;
    npu_cmd_t cmd = inline_command(
        payload, 0x2aau, NPU_ENGINE_CONTROL,
        NPU_CTRL_NOP, NPU_DTYPE_INT8);
    uint64_t low;
    uint64_t high;

    inline_wire(&cmd, wire, &low, &high);
    (void)memset(&inputs, 0, sizeof(inputs));
    inputs.core_reset_n = 1u;
    inputs.noc_reset_n = 1u;
    inputs.cmd_valid = 1u;
    inputs.cmd_data = low;
    inputs.cmd_first = 1u;
    npu_model_cycle_io(model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_ready != 0u);

    inputs.cmd_data = high;
    inputs.cmd_first = 0u;
    inputs.cmd_last = 1u;
    npu_model_cycle_io(model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_ready != 0u);

    (void)memset(&inputs, 0, sizeof(inputs));
    inputs.core_reset_n = 1u;
    inputs.noc_reset_n = 1u;
    npu_model_cycle_io(model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_rsp_valid != 0u);
    TEST_CHECK((outputs.cmd_rsp_data & UINT64_C(0x0fff)) ==
               UINT64_C(0x02aa));
    TEST_CHECK(((outputs.cmd_rsp_data >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);

    inputs.cmd_rsp_ready = 1u;
    npu_model_cycle_io(model, &inputs, &outputs);
    TEST_CHECK_STATUS(
        npu_model_run(model, 100u), NPU_STATUS_SUCCESS);
    return 0;
}

static int inline_test_dma(npu_model_t *model,
                           npu_wire_limits_t *limits)
{
    uint8_t payload[10] = {0};
    uint8_t wire[NPU_WIRE_CMD_BYTES];
    npu_cmd_t cmd;
    npu_task_request_t request;
    npu_wire_meta_t meta;
    uint64_t low;
    uint64_t high;
    uint64_t progress;
    uint32_t source_ref =
        UINT32_C(0x08000000) |
        UINT32_C(0x01000000) |
        UINT32_C(0x20);

    limits->gaddr_base[1] = 0x1000u;
    inline_ddr[0x1020u] = 0x11u;
    inline_ddr[0x1021u] = 0x22u;
    inline_ddr[0x1022u] = 0x33u;
    inline_ddr[0x1023u] = 0x44u;
    inline_payload_set(payload, 52u, 28u, source_ref);
    inline_payload_set(payload, 24u, 28u, 0x300u);
    inline_payload_set(payload, 4u, 20u, 4u);
    inline_payload_set(payload, 2u, 2u, NPU_DTYPE_INT8);
    cmd = inline_command(
        payload, 2u, NPU_ENGINE_DMA,
        NPU_DMA_COPY_1D, NPU_DTYPE_INT8);
    inline_wire(&cmd, wire, &low, &high);
    TEST_CHECK_STATUS(
        npu_wire_decode_task(
            wire, sizeof(wire), (const uint8_t *)0, 0u,
            limits, &request, &meta),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(request.desc.dma.src_space == NPU_SPACE_DDR);
    TEST_CHECK(request.desc.dma.src_addr == 0x1020u);
    TEST_CHECK(request.desc.dma.dst_addr == 0x300u);
    TEST_CHECK_STATUS(
        npu_dma_execute(
            model, request.cmd.opcode,
            &request.desc.dma, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 4u);
    TEST_CHECK(inline_l1[0x300u] == 0x11u);
    TEST_CHECK(inline_l1[0x301u] == 0x22u);
    TEST_CHECK(inline_l1[0x302u] == 0x33u);
    TEST_CHECK(inline_l1[0x303u] == 0x44u);

    (void)memset(payload, 0, sizeof(payload));
    cmd = inline_command(
        payload, 11u, NPU_ENGINE_DMA,
        NPU_DMA_GATHER_ND, NPU_DTYPE_INT8);
    inline_wire(&cmd, wire, &low, &high);
    TEST_CHECK_STATUS(
        npu_wire_decode_task(
            wire, sizeof(wire), (const uint8_t *)0, 0u,
            limits, &request, &meta),
        NPU_STATUS_ILLEGAL_OPCODE);

    limits->gaddr_base[1] = 0u;
    return 0;
}

static int inline_test_matrix(npu_model_t *model,
                              npu_wire_limits_t *limits)
{
    uint8_t payload[10] = {0};
    uint8_t wire[NPU_WIRE_CMD_BYTES];
    npu_cmd_t cmd;
    npu_task_request_t request;
    npu_wire_meta_t meta;
    uint64_t low;
    uint64_t high;
    uint64_t progress;

    inline_payload_set(payload, 66u, 14u, 0x10u);
    inline_payload_set(payload, 52u, 14u, 0x20u);
    inline_payload_set(payload, 38u, 14u, 0x30u);
    inline_payload_set(payload, 20u, 6u, 0u);
    inline_payload_set(payload, 14u, 6u, 0u);
    inline_payload_set(payload, 8u, 6u, 0u);
    inline_payload_set(payload, 5u, 2u, NPU_DTYPE_INT8);
    inline_payload_set(payload, 0u, 5u, 5u);
    cmd = inline_command(
        payload, 3u, NPU_ENGINE_MATRIX,
        NPU_MATRIX_GEMM, NPU_DTYPE_INT8);
    inline_wire(&cmd, wire, &low, &high);
    TEST_CHECK_STATUS(
        npu_wire_decode_task(
            wire, sizeof(wire), (const uint8_t *)0, 0u,
            limits, &request, &meta),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(request.desc.matrix.inline_requant_enable == 1u);
    TEST_CHECK(request.desc.matrix.inline_requant_shift == 5);
    TEST_CHECK(request.desc.matrix.requant_addr == 0u);
    TEST_CHECK(request.desc.matrix.requant_count == 0u);
    inline_l1[0x400u] = 3u;
    inline_l1[0x800u] = 64u;
    TEST_CHECK_STATUS(
        npu_matrix_execute(
            model, request.cmd.opcode,
            &request.desc.matrix, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 1u);
    TEST_CHECK(inline_l1[0xc00u] == 6u);

    inline_payload_set(payload, 7u, 1u, 1u);
    cmd = inline_command(
        payload, 30u, NPU_ENGINE_MATRIX,
        NPU_MATRIX_GEMM, NPU_DTYPE_INT8);
    inline_wire(&cmd, wire, &low, &high);
    TEST_CHECK_STATUS(
        npu_wire_decode_task(
            wire, sizeof(wire), (const uint8_t *)0, 0u,
            limits, &request, &meta),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(request.desc.matrix.b.dtype == NPU_DTYPE_INT4);

    cmd.inline_dtype = NPU_DTYPE_INT16;
    inline_wire(&cmd, wire, &low, &high);
    TEST_CHECK_STATUS(
        npu_wire_decode_task(
            wire, sizeof(wire), (const uint8_t *)0, 0u,
            limits, &request, &meta),
        NPU_STATUS_DTYPE_UNSUPPORTED);
    return 0;
}

static int inline_test_complex(npu_model_t *model,
                               npu_wire_limits_t *limits)
{
    uint8_t payload[10] = {0};
    uint8_t wire[NPU_WIRE_CMD_BYTES];
    npu_cmd_t cmd;
    npu_task_request_t request;
    npu_wire_meta_t meta;
    uint64_t low;
    uint64_t high;
    uint64_t progress;
    uint32_t act_meta =
        (1u << 17u) |
        ((uint32_t)NPU_DTYPE_INT8 << 7u);

    inline_payload_set(payload, 64u, 16u, 0x140u);
    inline_payload_set(payload, 48u, 16u, 0u);
    inline_payload_set(payload, 32u, 16u, 0x150u);
    inline_payload_set(payload, 27u, 5u, 0u);
    inline_payload_set(payload, 19u, 8u, 3u);
    inline_payload_set(payload, 0u, 19u, act_meta);
    cmd = inline_command(
        payload, 4u, NPU_ENGINE_COMPLEX,
        NPU_COMPLEX_ACT, NPU_DTYPE_INT8);
    inline_wire(&cmd, wire, &low, &high);
    TEST_CHECK_STATUS(
        npu_wire_decode_task(
            wire, sizeof(wire), (const uint8_t *)0, 0u,
            limits, &request, &meta),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(request.desc.complex.function == NPU_FUNC_TANH);
    inline_l1[0x1400u] = 0u;
    inline_l1[0x1401u] = 1u;
    inline_l1[0x1402u] = (uint8_t)-1;
    inline_l1[0x1403u] = 2u;
    TEST_CHECK_STATUS(
        npu_complex_execute(
            model, request.cmd.opcode,
            &request.desc.complex, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 4u);
    return 0;
}

static int inline_test_engine_adapter(
    npu_model_t *functional_model,
    npu_wire_limits_t *limits)
{
    uint8_t payload[10] = {0};
    uint8_t wire[NPU_WIRE_CMD_BYTES];
    npu_cmd_t cmd;
    npu_engine_cycle_t adapter;
    npu_engine_cycle_inputs_t inputs;
    npu_engine_cycle_outputs_t outputs;
    uint64_t low;
    uint64_t high;
    uint64_t metadata;
    uint64_t response_data = 0u;
    uint64_t done_first = 0u;
    uint8_t response_pending = 0u;
    uint8_t response_tag = 0u;
    uint8_t request_count = 0u;
    uint8_t saw_last = 0u;
    uint32_t cycle;

    inline_payload_set(payload, 64u, 16u, 0x160u);
    inline_payload_set(payload, 48u, 16u, 0x161u);
    inline_payload_set(payload, 16u, 16u, 0x162u);
    inline_payload_set(payload, 6u, 5u, 3u);
    cmd = inline_command(
        payload, 10u, NPU_ENGINE_VECTOR,
        NPU_VECTOR_ADD, NPU_DTYPE_INT8);
    inline_wire(&cmd, wire, &low, &high);
    inline_l1[0x1600u] = 1u;
    inline_l1[0x1601u] = 2u;
    inline_l1[0x1602u] = 3u;
    inline_l1[0x1603u] = 4u;
    inline_l1[0x1610u] = 10u;
    inline_l1[0x1611u] = 20u;
    inline_l1[0x1612u] = 30u;
    inline_l1[0x1613u] = 40u;

    TEST_CHECK_STATUS(
        npu_engine_cycle_init(
            &adapter, functional_model,
            NPU_ENGINE_VECTOR, limits),
        NPU_STATUS_SUCCESS);
    (void)memset(&inputs, 0, sizeof(inputs));
    inputs.reset_n = 1u;
    inputs.eng_req_valid_i = 1u;
    metadata =
        UINT64_C(10) |
        ((uint64_t)NPU_VECTOR_ADD << 12u) |
        (UINT64_C(1) << 44u);
    inputs.eng_req_data_i = metadata;
    npu_engine_cycle_step(&adapter, &inputs, &outputs);
    TEST_CHECK(outputs.eng_req_ready_o == 1u);

    for (cycle = 0u; cycle < 128u; cycle++) {
        (void)memset(&inputs, 0, sizeof(inputs));
        inputs.reset_n = 1u;
        inputs.desc_rd_req_ready_i = 1u;
        inputs.eng_done_ready_i = 1u;
        if (response_pending != 0u) {
            inputs.desc_rd_rsp_valid_i = 1u;
            inputs.desc_rd_rsp_data_i = response_data;
            inputs.desc_rd_rsp_tag_i = response_tag;
            inputs.desc_rd_rsp_status_i = NPU_ENGINE_DESC_OK;
        }
        npu_engine_cycle_step(&adapter, &inputs, &outputs);
        response_pending = 0u;
        if (outputs.desc_rd_req_valid_o != 0u) {
            TEST_CHECK(outputs.desc_rd_word_o < 2u);
            response_data =
                outputs.desc_rd_word_o == 0u ? low : high;
            response_tag = outputs.desc_rd_req_tag_o;
            response_pending = 1u;
            request_count++;
        }
        if (outputs.eng_done_valid_o != 0u) {
            if (outputs.eng_done_first_o != 0u) {
                done_first = outputs.eng_done_data_o;
            }
            if (outputs.eng_done_last_o != 0u) {
                saw_last = 1u;
                break;
            }
        }
    }
    TEST_CHECK(request_count == 2u);
    TEST_CHECK(saw_last != 0u);
    TEST_CHECK(((done_first >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(inline_l1[0x1620u] == 11u);
    TEST_CHECK(inline_l1[0x1621u] == 22u);
    TEST_CHECK(inline_l1[0x1622u] == 33u);
    TEST_CHECK(inline_l1[0x1623u] == 44u);
    return 0;
}

static int inline_test_ts_without_dfu(void)
{
    uint8_t payload[10] = {0};
    npu_cmd_t cmd;
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    const npu_ts_task_entry_t *task;
    uint64_t low;
    uint64_t high;
    uint32_t index;

    inline_payload_set(payload, 64u, 16u, 0x100u);
    inline_payload_set(payload, 48u, 16u, 0x110u);
    inline_payload_set(payload, 16u, 16u, 0x120u);
    cmd = inline_command(
        payload, 9u, NPU_ENGINE_VECTOR,
        NPU_VECTOR_ADD, NPU_DTYPE_INT8);
    npu_cmd_encode(&cmd, &low, &high);
    npu_ts_cycle_init(&model);

    (void)memset(&inputs, 0, sizeof(inputs));
    inputs.reset_n = 1u;
    inputs.cfe.valid = 1u;
    inputs.cfe.data = low;
    inputs.cfe.first = 1u;
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        inputs.engine[index].quiescent = 1u;
    }
    npu_ts_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 1u);

    (void)memset(&inputs, 0, sizeof(inputs));
    inputs.reset_n = 1u;
    inputs.cfe.valid = 1u;
    inputs.cfe.data = high;
    inputs.cfe.last = 1u;
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        inputs.engine[index].quiescent = 1u;
    }
    npu_ts_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 1u);
    TEST_CHECK(model.dfu.valid == 0u);
    task = npu_ts_cycle_find_task(&model, 9u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->cmd.inline_format == 1u);
    TEST_CHECK(task->fetch_started == 1u);
    TEST_CHECK(task->state == NPU_TS_TASK_CHECK_DESC);
    TEST_CHECK(model.desc_slot[task->desc_slot].bytes ==
               NPU_WIRE_CMD_BYTES);
    TEST_CHECK(inline_load_u64(
                   &model.desc_slot[task->desc_slot].data[0]) ==
               low);
    TEST_CHECK(inline_load_u64(
                   &model.desc_slot[task->desc_slot].data[8]) ==
               high);
    for (index = 0u; index < 4u; index++) {
        (void)memset(&inputs, 0, sizeof(inputs));
        inputs.reset_n = 1u;
        npu_ts_cycle_step(&model, &inputs, &outputs);
        TEST_CHECK(outputs.dfu.req_valid == 0u);
        if (outputs.engine[
                NPU_ENGINE_VECTOR - NPU_ENGINE_DMA].req_valid != 0u) {
            TEST_CHECK(
                ((outputs.engine[
                      NPU_ENGINE_VECTOR - NPU_ENGINE_DMA].req_data >>
                  44u) &
                 1u) == 1u);
            return 0;
        }
    }
    TEST_CHECK(0);
    return 0;
}

int test_inline(void)
{
    npu_config_t config;
    npu_model_t model;
    npu_wire_limits_t limits;
    int line;

    test_clear_bytes(inline_l1, sizeof(inline_l1));
    test_clear_bytes(inline_ddr, sizeof(inline_ddr));
    npu_config_reference(&config);
    TEST_CHECK_STATUS(
        npu_model_init(
            &model, &config, inline_l1, sizeof(inline_l1),
            inline_ddr, sizeof(inline_ddr)),
        NPU_STATUS_SUCCESS);
    npu_wire_limits_reference(&limits);
    limits.gaddr_limit = sizeof(inline_ddr);

    line = inline_test_opcode_table();
    if (line != 0) {
        return line;
    }
    line = inline_test_vector_and_header(&model, &limits);
    if (line != 0) {
        return line;
    }
    line = inline_test_control(&model, &limits);
    if (line != 0) {
        return line;
    }
    line = inline_test_frontend_response_id(&model);
    if (line != 0) {
        return line;
    }
    line = inline_test_dma(&model, &limits);
    if (line != 0) {
        return line;
    }
    line = inline_test_matrix(&model, &limits);
    if (line != 0) {
        return line;
    }
    line = inline_test_complex(&model, &limits);
    if (line != 0) {
        return line;
    }
    line = inline_test_engine_adapter(&model, &limits);
    if (line != 0) {
        return line;
    }
    return inline_test_ts_without_dfu();
}
