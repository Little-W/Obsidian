#include "npu_single_core_cycle.h"
#include "test_util.h"

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#ifdef NPU_SINGLE_CORE_CYCLE_STANDALONE
#include <stdio.h>
#endif

#define SINGLE_TEST_DDR_BYTES (1024u * 1024u)
#define SINGLE_TEST_TRACE_ENTRIES 64u
#define SINGLE_TEST_TRACE_HASH 128u
#define SINGLE_TEST_MAX_CYCLES 30000u

#define SINGLE_TEST_DESC_ADDR UINT64_C(0x00002000)
#define SINGLE_TEST_SRC0 0x00000100u
#define SINGLE_TEST_SRC1 0x00000180u
#define SINGLE_TEST_DST 0x00000200u
#define SINGLE_TEST_SRC_SCALE 0x00000280u
#define SINGLE_TEST_DST_SCALE 0x00000288u
#define SINGLE_TEST_MASK 0x00000300u
#define SINGLE_TEST_DEBUG_ADDR 0x00000400u
#define SINGLE_TEST_COMMAND UINT16_C(0x451)
#define SINGLE_TEST_RESET_COMMAND UINT16_C(0x452)
#define SINGLE_TEST_MATRIX_COMMAND UINT16_C(0x480)
#define SINGLE_TEST_COMPLEX_COMMAND UINT16_C(0x481)
#define SINGLE_TEST_NUMERIC_COMMAND UINT16_C(0x482)

#define SINGLE_TEST_CALL(expression)          \
    do {                                      \
        int single_line = (expression);       \
        if (single_line != 0) {               \
            return single_line;               \
        }                                     \
    } while (0)

typedef struct {
    uint8_t active;
    uint8_t response_asserted;
    uint8_t delay;
    uint64_t vaddr;
    uint64_t paddr;
    uint16_t tag;
} single_test_tbu_t;

typedef struct {
    uint8_t active;
    uint8_t response_asserted;
    uint8_t delay;
    uint8_t id;
    uint8_t beats;
    uint8_t beat;
    uint64_t addr;
} single_test_axi_read_t;

typedef struct {
    single_test_tbu_t tbu;
    single_test_axi_read_t read;
    uint8_t tbu_hold;
    uint64_t tbu_hold_vaddr;
    uint8_t tbu_hold_write;
    uint16_t tbu_hold_tag;
    uint8_t ar_hold;
    uint8_t ar_hold_id;
    uint64_t ar_hold_addr;
    uint8_t ar_hold_len;
    uint32_t random_state;
    uint32_t cdc_request_cycles;
    uint32_t tbu_requests;
    uint32_t tbu_request_stalls;
    uint32_t axi_reads;
    uint32_t axi_ar_stalls;
    uint32_t axi_read_beats;
    uint32_t internal_tbu_requests;
    uint32_t internal_tbu_responses;
    uint32_t internal_tbu_response_stalls;
    uint64_t internal_tbu_first_request_tick;
    uint64_t internal_tbu_first_response_tick;
} single_test_noc_server_t;

typedef struct {
    uint8_t l1[NPU_L1_CYCLE_BYTES];
    uint8_t l1_ecc[NPU_L1_CYCLE_WORDS];
    uint8_t ddr[SINGLE_TEST_DDR_BYTES];
    npu_bus_trace_entry_t
        read_entry[NPU_TS_ENGINE_COUNT]
                  [SINGLE_TEST_TRACE_ENTRIES];
    npu_bus_trace_entry_t
        write_entry[NPU_TS_ENGINE_COUNT]
                   [SINGLE_TEST_TRACE_ENTRIES];
    uint32_t
        read_hash[NPU_TS_ENGINE_COUNT]
                 [SINGLE_TEST_TRACE_HASH];
    uint32_t
        write_hash[NPU_TS_ENGINE_COUNT]
                  [SINGLE_TEST_TRACE_HASH];
    npu_engine_data_workspace_t
        workspace[NPU_TS_ENGINE_COUNT];
    npu_model_t functional;
    npu_single_core_cycle_t top;
    single_test_noc_server_t noc_server;
    uint8_t core_rst_ni;
    uint8_t noc_rst_ni;
    uint64_t core_ticks;
    uint64_t noc_ticks;
} single_test_env_t;

typedef struct {
    npu_single_core_cycle_t top;
    uint8_t l1_ecc[NPU_L1_CYCLE_WORDS];
    npu_bus_trace_entry_t
        read_entry[NPU_TS_ENGINE_COUNT]
                  [SINGLE_TEST_TRACE_ENTRIES];
    npu_bus_trace_entry_t
        write_entry[NPU_TS_ENGINE_COUNT]
                   [SINGLE_TEST_TRACE_ENTRIES];
    uint32_t
        read_hash[NPU_TS_ENGINE_COUNT]
                 [SINGLE_TEST_TRACE_HASH];
    uint32_t
        write_hash[NPU_TS_ENGINE_COUNT]
                  [SINGLE_TEST_TRACE_HASH];
    npu_engine_data_workspace_t
        workspace[NPU_TS_ENGINE_COUNT];
} single_test_init_snapshot_t;

static single_test_env_t single_test_env;
static single_test_init_snapshot_t
    single_test_init_snapshot;

static void single_test_put_u16(uint8_t *data,
                                size_t offset,
                                uint16_t value)
{
    data[offset] = (uint8_t)value;
    data[offset + 1u] = (uint8_t)(value >> 8u);
}

static void single_test_put_u32(uint8_t *data,
                                size_t offset,
                                uint32_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 4u; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static void single_test_put_u64(uint8_t *data,
                                size_t offset,
                                uint64_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < NPU_REF_BUS_BYTES; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static uint64_t single_test_get_u64(const uint8_t *data,
                                    size_t offset)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < NPU_REF_BUS_BYTES; byte++) {
        value |= (uint64_t)data[offset + byte] <<
                 (byte * 8u);
    }
    return value;
}

static uint32_t single_test_get_u32(const uint8_t *data,
                                    size_t offset)
{
    return (uint32_t)data[offset] |
           ((uint32_t)data[offset + 1u] << 8u) |
           ((uint32_t)data[offset + 2u] << 16u) |
           ((uint32_t)data[offset + 3u] << 24u);
}

static uint32_t single_test_random(uint32_t *state)
{
    uint32_t value = *state;

    value ^= value << 13u;
    value ^= value >> 17u;
    value ^= value << 5u;
    *state = value;
    return value;
}

static uint8_t single_test_clock_active(uint8_t mask,
                                        uint8_t bit)
{
    return (uint8_t)((mask >> bit) & 1u);
}

static uint32_t single_test_external_error_info(
    uint8_t source,
    uint8_t detail,
    uint8_t aux,
    uint8_t status)
{
    return ((uint32_t)NPU_LSC_EXTERNAL_ERROR_STAGE << 28u) |
           ((uint32_t)source
            << NPU_LSC_EXTERNAL_SOURCE_SHIFT) |
           ((uint32_t)detail
            << NPU_LSC_EXTERNAL_DETAIL_SHIFT) |
           ((uint32_t)aux
            << NPU_LSC_EXTERNAL_AUX_SHIFT) |
           status;
}

static uint32_t single_test_numeric(void)
{
    return (uint32_t)NPU_DTYPE_INT8 |
           ((uint32_t)NPU_DTYPE_INT8 << 2u) |
           ((uint32_t)NPU_DTYPE_INT8 << 6u) |
           ((uint32_t)NPU_ROUND_NEAREST_EVEN << 10u) |
           (UINT32_C(1) << 12u) |
           ((uint32_t)NPU_SCALE_PER_TENSOR << 13u);
}

static uint32_t single_test_numeric_config(
    npu_dtype_t src0,
    npu_dtype_t src1,
    npu_dtype_t src2,
    npu_dtype_t dst,
    npu_round_mode_t round_mode,
    uint8_t saturate,
    npu_scale_mode_t scale_mode,
    uint8_t zero_point_enable,
    uint8_t internal_fp32)
{
    return (uint32_t)src0 |
           ((uint32_t)src1 << 2u) |
           ((uint32_t)src2 << 4u) |
           ((uint32_t)dst << 6u) |
           ((uint32_t)round_mode << 10u) |
           ((uint32_t)(saturate & 1u) << 12u) |
           ((uint32_t)scale_mode << 13u) |
           ((uint32_t)(zero_point_enable & 1u) << 15u) |
           ((uint32_t)(internal_fp32 & 1u) << 16u);
}

static void single_test_make_common_descriptor(
    uint8_t *descriptor,
    size_t descriptor_bytes,
    npu_engine_t engine,
    uint32_t op_flags,
    uint64_t src0_addr,
    uint64_t src1_addr,
    uint64_t src2_addr,
    uint64_t dst_addr,
    uint64_t aux0_addr,
    uint64_t aux1_addr,
    uint32_t numeric,
    uint32_t user_tag)
{
    (void)memset(descriptor, 0, descriptor_bytes);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = (uint8_t)engine;
    single_test_put_u16(
        descriptor, 0x02u, (uint16_t)descriptor_bytes);
    single_test_put_u32(descriptor, 0x04u, op_flags);
    single_test_put_u64(descriptor, 0x08u, src0_addr);
    single_test_put_u64(descriptor, 0x10u, src1_addr);
    single_test_put_u64(descriptor, 0x18u, src2_addr);
    single_test_put_u64(descriptor, 0x20u, dst_addr);
    single_test_put_u64(descriptor, 0x28u, aux0_addr);
    single_test_put_u64(descriptor, 0x30u, aux1_addr);
    single_test_put_u32(descriptor, 0x38u, numeric);
    single_test_put_u32(descriptor, 0x3cu, user_tag);
}

static void single_test_make_matrix_descriptor(
    uint8_t *descriptor)
{
    uint32_t numeric = single_test_numeric_config(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8, NPU_DTYPE_INT4,
        NPU_DTYPE_INT32, NPU_ROUND_NEAREST_EVEN,
        0u, NPU_SCALE_NONE, 0u, 0u);

    single_test_make_common_descriptor(
        descriptor, NPU_WIRE_MATRIX_DESC_BYTES,
        NPU_ENGINE_MATRIX, 0u,
        SINGLE_TEST_SRC0, SINGLE_TEST_SRC1, 0u,
        SINGLE_TEST_DST, 0u, 0u, numeric,
        UINT32_C(0x4d450480));
    single_test_put_u32(descriptor, 0x40u, 1u);
    single_test_put_u32(descriptor, 0x44u, 1u);
    single_test_put_u32(descriptor, 0x48u, 2u);
    single_test_put_u32(descriptor, 0x4cu, 1u);
    single_test_put_u32(descriptor, 0x50u, 1u);
    single_test_put_u32(descriptor, 0x54u, 1u);
    single_test_put_u32(descriptor, 0x58u, 2u);
    single_test_put_u32(
        descriptor, 0x5cu, UINT32_C(1) << 7u);
    single_test_put_u32(descriptor, 0x60u, 2u);
    single_test_put_u32(descriptor, 0x68u, 4u);
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

static void single_test_make_complex_descriptor(
    uint8_t *descriptor)
{
    uint32_t numeric = single_test_numeric_config(
        NPU_DTYPE_INT32, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        1u, NPU_SCALE_PER_FEATURE, 0u, 1u);

    single_test_make_common_descriptor(
        descriptor, NPU_WIRE_COMPLEX_DESC_BYTES,
        NPU_ENGINE_COMPLEX, 0u,
        SINGLE_TEST_SRC0, 0u, 0u, SINGLE_TEST_DST,
        SINGLE_TEST_SRC_SCALE, SINGLE_TEST_DST_SCALE,
        numeric, UINT32_C(0x434d4581));
    single_test_put_u32(descriptor, 0x40u, 1u);
    single_test_put_u32(descriptor, 0x44u, 1u);
    single_test_put_u32(descriptor, 0x48u, 1u);
    single_test_put_u32(
        descriptor, 0x4cu, NPU_FUNC_SIGMOID);
    single_test_put_u32(descriptor, 0x50u, 4u);
    single_test_put_u32(descriptor, 0x5cu, 1u);
    single_test_put_u32(descriptor, 0x6cu, NPU_MASK_NONE);
    single_test_put_u32(descriptor, 0x94u, 0xc1800000u);
    single_test_put_u32(descriptor, 0x98u, 0x41800000u);
    descriptor[0x9cu] = 0u;
    descriptor[0x9du] = NPU_OVERFLOW_SATURATE;
    descriptor[0x9eu] = NPU_ALL_MASK_WRITE_ZERO;
    descriptor[0x9fu] = 0u;
}

static void single_test_make_softmax_error_descriptor(
    uint8_t *descriptor)
{
    uint32_t numeric = single_test_numeric_config(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        1u, NPU_SCALE_PER_TENSOR, 0u, 1u);

    single_test_make_common_descriptor(
        descriptor, NPU_WIRE_COMPLEX_DESC_BYTES,
        NPU_ENGINE_COMPLEX, 0u,
        SINGLE_TEST_SRC0, 0u, 0u, SINGLE_TEST_DST,
        0u, 0u, numeric, UINT32_C(0x534f4682));
    single_test_put_u32(descriptor, 0x40u, 1u);
    single_test_put_u32(descriptor, 0x44u, 4u);
    single_test_put_u32(descriptor, 0x48u, 4u);
    single_test_put_u32(
        descriptor, 0x4cu, NPU_FUNC_SOFTMAX);
    single_test_put_u32(descriptor, 0x50u, 4u);
    single_test_put_u32(descriptor, 0x5cu, 4u);
    single_test_put_u64(
        descriptor, 0x60u, SINGLE_TEST_MASK);
    single_test_put_u32(descriptor, 0x68u, 4u);
    single_test_put_u32(
        descriptor, 0x6cu, NPU_MASK_BOOLEAN);
    single_test_put_u32(descriptor, 0x70u, 0x3f800000u);
    single_test_put_u32(descriptor, 0x7cu, 0x3c000000u);
    single_test_put_u32(descriptor, 0x94u, 0xc1800000u);
    single_test_put_u32(descriptor, 0x98u, 0x41800000u);
    descriptor[0x9du] = NPU_OVERFLOW_SATURATE;
    descriptor[0x9eu] = NPU_ALL_MASK_ERROR;
    single_test_put_u32(descriptor, 0xb0u, 4u);
}

static void single_test_make_vector_descriptor(uint8_t *descriptor)
{
    (void)memset(
        descriptor, 0, NPU_WIRE_VECTOR_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_VECTOR;
    single_test_put_u16(
        descriptor, 0x02u, NPU_WIRE_VECTOR_DESC_BYTES);
    single_test_put_u64(
        descriptor, 0x08u, SINGLE_TEST_SRC0);
    single_test_put_u64(
        descriptor, 0x10u, SINGLE_TEST_SRC1);
    single_test_put_u64(
        descriptor, 0x20u, SINGLE_TEST_DST);
    single_test_put_u32(
        descriptor, 0x38u, single_test_numeric());
    single_test_put_u32(descriptor, 0x3cu, 0x53434f52u);
    single_test_put_u32(descriptor, 0x40u, 1u);
    single_test_put_u32(descriptor, 0x44u, 16u);
    single_test_put_u32(descriptor, 0x48u, 16u);
    single_test_put_u32(descriptor, 0x50u, 1u);
    single_test_put_u32(descriptor, 0x54u, 16u);
    single_test_put_u32(descriptor, 0x58u, 1u);
    single_test_put_u32(descriptor, 0x5cu, 16u);
    single_test_put_u32(descriptor, 0x68u, 1u);
    single_test_put_u32(descriptor, 0x6cu, 16u);
    descriptor[0x78u] = 0u;
    descriptor[0x79u] = NPU_COMPARE_EQ;
    descriptor[0x7au] = NPU_OVERFLOW_SATURATE;
    descriptor[0x7bu] = 0u;
    single_test_put_u32(descriptor, 0x80u, 0x3f800000u);
    single_test_put_u32(descriptor, 0x84u, 0x3f800000u);
    single_test_put_u32(descriptor, 0x88u, 0u);
    single_test_put_u32(descriptor, 0x8cu, 0x3f800000u);
}

static void single_test_make_command(uint16_t command_id,
                                     uint64_t *low_beat,
                                     uint64_t *high_beat)
{
    npu_cmd_t command;

    (void)memset(&command, 0, sizeof(command));
    command.desc_addr = SINGLE_TEST_DESC_ADDR;
    command.command_id = command_id;
    command.engine = NPU_ENGINE_VECTOR;
    command.opcode = NPU_VECTOR_ADD;
    command.header_flags = NPU_TS_FLAG_IRQ_ON_SUCCESS;
    command.wait_event[0] = npu_event_none();
    command.wait_event[1] = npu_event_none();
    command.signal_event = npu_event_none();
    command.header_version = NPU_WIRE_HEADER_VERSION;
    command.timeout_class = 0u;
    npu_cmd_encode(&command, low_beat, high_beat);
}

static void single_test_make_engine_command(
    uint16_t command_id,
    npu_engine_t engine,
    uint8_t opcode,
    uint64_t *low_beat,
    uint64_t *high_beat)
{
    npu_cmd_t command;

    (void)memset(&command, 0, sizeof(command));
    command.desc_addr = SINGLE_TEST_DESC_ADDR;
    command.command_id = command_id;
    command.engine = engine;
    command.opcode = opcode;
    command.header_flags =
        NPU_TS_FLAG_IRQ_ON_SUCCESS |
        NPU_TS_FLAG_IRQ_ON_ERROR;
    command.wait_event[0] = npu_event_none();
    command.wait_event[1] = npu_event_none();
    command.signal_event = npu_event_none();
    command.header_version = NPU_WIRE_HEADER_VERSION;
    command.timeout_class = 0u;
    npu_cmd_encode(&command, low_beat, high_beat);
}

static void single_test_core_inputs(
    const single_test_env_t *env,
    npu_single_core_cycle_core_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->core_rst_ni = env->core_rst_ni;
    inputs->noc_rst_ni = env->noc_rst_ni;
    inputs->module_clk_en_i = NPU_SINGLE_CORE_CLK_ALL;
    inputs->dsa_permission_i = 1u;
    inputs->dsa_enable_i = 1u;
}

static void single_test_noc_inputs(
    const single_test_env_t *env,
    npu_single_core_cycle_noc_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->core_rst_ni = env->core_rst_ni;
    inputs->noc_rst_ni = env->noc_rst_ni;
    inputs->module_clk_en_i = NPU_SINGLE_CORE_CLK_ALL;
}

static void single_test_server_reset(
    single_test_noc_server_t *server)
{
    (void)memset(server, 0, sizeof(*server));
    server->random_state = UINT32_C(0x4ca5b37d);
}

static uint8_t single_test_engine_quiescent(
    const npu_engine_data_cycle_t *engine)
{
    return engine->data_pending == 0u &&
                   npu_engine_cycle_quiescent(
                       &engine->engine) != 0u
               ? 1u
               : 0u;
}

static void single_test_server_drive(
    single_test_env_t *env,
    npu_single_core_cycle_noc_inputs_t *inputs)
{
    single_test_noc_server_t *server = &env->noc_server;
    uint32_t random_value =
        single_test_random(&server->random_state);

    if (env->top.tbu_mode ==
        NPU_SINGLE_CORE_TBU_EXTERNAL) {
        if (server->tbu.active == 0u) {
            inputs->tbu.req_ready =
                (uint8_t)(
                    server->tbu_request_stalls != 0u &&
                    (random_value & 3u) != 0u);
        } else if (server->tbu.delay != 0u) {
            server->tbu.delay--;
        } else {
            server->tbu.response_asserted = 1u;
        }
        if (server->tbu.response_asserted != 0u) {
            inputs->tbu.rsp_valid = 1u;
            inputs->tbu.rsp_paddr = server->tbu.paddr;
            inputs->tbu.rsp_tag = server->tbu.tag;
            inputs->tbu.rsp_status = NPU_STATUS_SUCCESS;
        }
    }

    if (server->read.active == 0u) {
        inputs->axi[NPU_MIF_AXI_DDR].arready =
            (uint8_t)(server->axi_ar_stalls != 0u &&
                      (random_value & 0x18u) != 0u);
    } else if (server->read.delay != 0u) {
        server->read.delay--;
    } else if (server->read.response_asserted == 0u &&
               (random_value & 0x60u) != 0u) {
        server->read.response_asserted = 1u;
    }
    if (server->read.response_asserted != 0u) {
        size_t offset = (size_t)server->read.addr +
                        (size_t)server->read.beat *
                            NPU_REF_BUS_BYTES;

        inputs->axi[NPU_MIF_AXI_DDR].rvalid = 1u;
        inputs->axi[NPU_MIF_AXI_DDR].rid =
            server->read.id;
        if (offset + NPU_REF_BUS_BYTES <=
            sizeof(env->ddr)) {
            inputs->axi[NPU_MIF_AXI_DDR].rdata =
                single_test_get_u64(env->ddr, offset);
        }
        inputs->axi[NPU_MIF_AXI_DDR].rresp =
            NPU_MIF_AXI_RESP_OKAY;
        inputs->axi[NPU_MIF_AXI_DDR].rlast =
            (uint8_t)(server->read.beat + 1u ==
                      server->read.beats);
    }
}

static int single_test_server_observe(
    single_test_env_t *env,
    const npu_single_core_cycle_noc_inputs_t *inputs,
    const npu_single_core_cycle_noc_outputs_t *outputs)
{
    single_test_noc_server_t *server = &env->noc_server;
    const npu_mif_tbu_outputs_t *tbu = &outputs->mif.tbu;
    const npu_mif_axi_outputs_t *axi =
        &outputs->mif.axi[NPU_MIF_AXI_DDR];

    if (outputs->cdc.owner[NPU_MIF_OWNER_DFU].req_valid != 0u) {
        server->cdc_request_cycles++;
    }

    if (env->top.tbu_mode ==
        NPU_SINGLE_CORE_TBU_EXTERNAL) {
        if (server->tbu_hold != 0u) {
            TEST_CHECK(tbu->req_valid != 0u);
            TEST_CHECK(
                tbu->req_vaddr == server->tbu_hold_vaddr);
            TEST_CHECK(
                tbu->req_write == server->tbu_hold_write);
            TEST_CHECK(tbu->req_tag ==
                       server->tbu_hold_tag);
        }
        if (tbu->req_valid != 0u &&
            inputs->tbu.req_ready == 0u) {
            server->tbu_request_stalls++;
            if (server->tbu_hold == 0u) {
                server->tbu_hold = 1u;
                server->tbu_hold_vaddr = tbu->req_vaddr;
                server->tbu_hold_write = tbu->req_write;
                server->tbu_hold_tag = tbu->req_tag;
            }
        }
        if (tbu->req_valid != 0u &&
            inputs->tbu.req_ready != 0u) {
            TEST_CHECK(server->tbu.active == 0u);
            TEST_CHECK(tbu->req_write == 0u);
            TEST_CHECK(tbu->req_stream_id == 0x1234u);
            TEST_CHECK(
                tbu->req_substream_id == 0x5678u);
            server->tbu.active = 1u;
            server->tbu.response_asserted = 0u;
            server->tbu.delay = 2u;
            server->tbu.vaddr = tbu->req_vaddr;
            server->tbu.paddr = tbu->req_vaddr;
            server->tbu.tag = tbu->req_tag;
            server->tbu_requests++;
            server->tbu_hold = 0u;
        }
        if (inputs->tbu.rsp_valid != 0u &&
            tbu->rsp_ready != 0u) {
            TEST_CHECK(server->tbu.active != 0u);
            server->tbu.active = 0u;
            server->tbu.response_asserted = 0u;
        }
    } else {
        if (tbu->req_valid != 0u &&
            outputs->tbu.req_ready != 0u) {
            server->internal_tbu_requests++;
            if (server->internal_tbu_first_request_tick ==
                0u) {
                server->internal_tbu_first_request_tick =
                    env->noc_ticks;
            }
        }
        if (outputs->tbu.rsp_valid != 0u) {
            if (tbu->rsp_ready != 0u) {
                server->internal_tbu_responses++;
                if (server->internal_tbu_first_response_tick ==
                    0u) {
                    server->internal_tbu_first_response_tick =
                        env->noc_ticks;
                }
            } else {
                server->internal_tbu_response_stalls++;
            }
        }
    }

    TEST_CHECK(outputs->mif.axi[NPU_MIF_AXI_EXT].arvalid == 0u);
    TEST_CHECK(outputs->mif.axi[NPU_MIF_AXI_EXT].awvalid == 0u);
    TEST_CHECK(axi->awvalid == 0u);
    TEST_CHECK(axi->wvalid == 0u);
    if (server->ar_hold != 0u) {
        TEST_CHECK(axi->arvalid != 0u);
        TEST_CHECK(axi->arid == server->ar_hold_id);
        TEST_CHECK(axi->araddr == server->ar_hold_addr);
        TEST_CHECK(axi->arlen == server->ar_hold_len);
    }
    if (axi->arvalid != 0u &&
        inputs->axi[NPU_MIF_AXI_DDR].arready == 0u) {
        server->axi_ar_stalls++;
        if (server->ar_hold == 0u) {
            server->ar_hold = 1u;
            server->ar_hold_id = axi->arid;
            server->ar_hold_addr = axi->araddr;
            server->ar_hold_len = axi->arlen;
        }
    }
    if (axi->arvalid != 0u &&
        inputs->axi[NPU_MIF_AXI_DDR].arready != 0u) {
        TEST_CHECK(server->read.active == 0u);
        TEST_CHECK(axi->arsize == 3u);
        TEST_CHECK(axi->arburst == 1u);
        TEST_CHECK(axi->araddr +
                       ((uint64_t)axi->arlen + 1u) *
                           NPU_REF_BUS_BYTES <=
                   sizeof(env->ddr));
        server->read.active = 1u;
        server->read.response_asserted = 0u;
        server->read.delay = 1u;
        server->read.id = axi->arid;
        server->read.beats = (uint8_t)(axi->arlen + 1u);
        server->read.beat = 0u;
        server->read.addr = axi->araddr;
        server->axi_reads++;
        server->ar_hold = 0u;
    }
    if (inputs->axi[NPU_MIF_AXI_DDR].rvalid != 0u &&
        axi->rready != 0u) {
        TEST_CHECK(server->read.active != 0u);
        server->axi_read_beats++;
        server->read.beat++;
        server->read.response_asserted = 0u;
        server->read.delay =
            (uint8_t)(single_test_random(
                          &server->random_state) &
                      1u);
        if (server->read.beat == server->read.beats) {
            server->read.active = 0u;
            server->read.delay = 0u;
        }
    }
    return 0;
}

static void single_test_core_tick(
    single_test_env_t *env,
    const npu_single_core_cycle_core_inputs_t *inputs,
    npu_single_core_cycle_core_outputs_t *outputs)
{
    npu_single_core_cycle_core_tick(
        &env->top, inputs, outputs);
    env->core_ticks++;
}

static int single_test_noc_tick_mask(
    single_test_env_t *env,
    uint8_t module_clk_en,
    npu_single_core_cycle_noc_outputs_t *outputs)
{
    npu_single_core_cycle_noc_inputs_t inputs;
    int line;

    single_test_noc_inputs(env, &inputs);
    inputs.module_clk_en_i = module_clk_en;
    if (env->noc_rst_ni != 0u) {
        single_test_server_drive(env, &inputs);
    }
    npu_single_core_cycle_noc_tick(
        &env->top, &inputs, outputs);
    env->noc_ticks++;
    if (env->noc_rst_ni == 0u) {
        return 0;
    }
    line = single_test_server_observe(env, &inputs, outputs);
    return line;
}

static int single_test_noc_tick(
    single_test_env_t *env,
    npu_single_core_cycle_noc_outputs_t *outputs)
{
    return single_test_noc_tick_mask(
        env, NPU_SINGLE_CORE_CLK_ALL, outputs);
}

static int single_test_env_init_mode(
    single_test_env_t *env,
    npu_single_core_tbu_mode_t tbu_mode)
{
    npu_config_t config;
    npu_wire_limits_t limits;
    npu_lsc_cycle_config_t lsc_config;
    npu_mif_cycle_config_t mif_config;
    uint8_t *descriptor =
        &env->ddr[(size_t)SINGLE_TEST_DESC_ADDR];
    uint32_t engine;

    (void)memset(env, 0, sizeof(*env));
    npu_config_reference(&config);
    TEST_CHECK_STATUS(
        npu_model_init(
            &env->functional, &config,
            env->l1, sizeof(env->l1),
            env->ddr, sizeof(env->ddr)),
        NPU_STATUS_SUCCESS);

    for (engine = 0u; engine < NPU_TS_ENGINE_COUNT; engine++) {
        env->workspace[engine].read_entries =
            env->read_entry[engine];
        env->workspace[engine].read_capacity =
            SINGLE_TEST_TRACE_ENTRIES;
        env->workspace[engine].read_hash =
            env->read_hash[engine];
        env->workspace[engine].read_hash_slots =
            SINGLE_TEST_TRACE_HASH;
        env->workspace[engine].write_entries =
            env->write_entry[engine];
        env->workspace[engine].write_capacity =
            SINGLE_TEST_TRACE_ENTRIES;
        env->workspace[engine].write_hash =
            env->write_hash[engine];
        env->workspace[engine].write_hash_slots =
            SINGLE_TEST_TRACE_HASH;
    }

    npu_wire_limits_reference(&limits);
    limits.l1_bytes = NPU_L1_CYCLE_BYTES;
    limits.gaddr_limit = SINGLE_TEST_DDR_BYTES;
    npu_lsc_cycle_config_reference(&lsc_config);
    npu_mif_cycle_config_default(&mif_config);
    mif_config.ddr_enable = 1u;
    mif_config.ddr_base = 0u;
    mif_config.ddr_limit = SINGLE_TEST_DDR_BYTES - 8u;
    mif_config.ext_enable = 0u;
    mif_config.bypass_enable = 0u;

    TEST_CHECK_STATUS(
        npu_single_core_cycle_init(
            &env->top, &env->functional,
            env->l1, sizeof(env->l1),
            env->l1_ecc, sizeof(env->l1_ecc),
            env->workspace, &limits, &lsc_config,
            &mif_config, tbu_mode),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(env->top.tbu_mode == (uint8_t)tbu_mode);
    single_test_make_vector_descriptor(descriptor);
    single_test_server_reset(&env->noc_server);
    env->core_rst_ni = 0u;
    env->noc_rst_ni = 0u;
    return 0;
}

static int single_test_env_init(single_test_env_t *env)
{
    return single_test_env_init_mode(
        env, NPU_SINGLE_CORE_TBU_EXTERNAL);
}

static int single_test_workspace_preflight_transaction(
    single_test_env_t *env)
{
    npu_wire_limits_t wire;
    npu_lsc_cycle_config_t lsc;
    npu_mif_cycle_config_t mif;

    SINGLE_TEST_CALL(single_test_env_init(env));
    wire = env->top.wire_limits;
    lsc = env->top.lsc.config;
    mif = env->top.mif_soc_config;
    env->top.core_cycle = UINT64_C(0x8899aabbccddeeff);
    (void)memset(env->l1_ecc, 0x5a, sizeof(env->l1_ecc));
    (void)memset(
        env->read_entry, 0x16, sizeof(env->read_entry));
    (void)memset(
        env->write_entry, 0x27, sizeof(env->write_entry));
    (void)memset(
        env->read_hash, 0x38, sizeof(env->read_hash));
    (void)memset(
        env->write_hash, 0x49, sizeof(env->write_hash));
    env->workspace[NPU_TS_ENGINE_COUNT - 1u].
        write_hash_slots = 3u;

    (void)memcpy(
        &single_test_init_snapshot.top, &env->top,
        sizeof(env->top));
    (void)memcpy(
        single_test_init_snapshot.l1_ecc, env->l1_ecc,
        sizeof(env->l1_ecc));
    (void)memcpy(
        single_test_init_snapshot.read_entry,
        env->read_entry, sizeof(env->read_entry));
    (void)memcpy(
        single_test_init_snapshot.write_entry,
        env->write_entry, sizeof(env->write_entry));
    (void)memcpy(
        single_test_init_snapshot.read_hash,
        env->read_hash, sizeof(env->read_hash));
    (void)memcpy(
        single_test_init_snapshot.write_hash,
        env->write_hash, sizeof(env->write_hash));
    (void)memcpy(
        single_test_init_snapshot.workspace,
        env->workspace, sizeof(env->workspace));

    TEST_CHECK_STATUS(
        npu_single_core_cycle_init(
            &env->top, &env->functional,
            env->l1, sizeof(env->l1),
            env->l1_ecc, sizeof(env->l1_ecc),
            env->workspace, &wire, &lsc, &mif,
            NPU_SINGLE_CORE_TBU_EXTERNAL),
        NPU_STATUS_BAD_DESC);
    TEST_CHECK(memcmp(
                   &env->top,
                   &single_test_init_snapshot.top,
                   sizeof(env->top)) == 0);
    TEST_CHECK(memcmp(
                   env->l1_ecc,
                   single_test_init_snapshot.l1_ecc,
                   sizeof(env->l1_ecc)) == 0);
    TEST_CHECK(memcmp(
                   env->read_entry,
                   single_test_init_snapshot.read_entry,
                   sizeof(env->read_entry)) == 0);
    TEST_CHECK(memcmp(
                   env->write_entry,
                   single_test_init_snapshot.write_entry,
                   sizeof(env->write_entry)) == 0);
    TEST_CHECK(memcmp(
                   env->read_hash,
                   single_test_init_snapshot.read_hash,
                   sizeof(env->read_hash)) == 0);
    TEST_CHECK(memcmp(
                   env->write_hash,
                   single_test_init_snapshot.write_hash,
                   sizeof(env->write_hash)) == 0);
    TEST_CHECK(memcmp(
                   env->workspace,
                   single_test_init_snapshot.workspace,
                   sizeof(env->workspace)) == 0);
    return 0;
}

static int single_test_default_wire_uses_ddr(
    single_test_env_t *env)
{
    npu_mif_cycle_config_t mif;

    SINGLE_TEST_CALL(single_test_env_init(env));
    mif = env->top.mif_soc_config;
    TEST_CHECK_STATUS(
        npu_single_core_cycle_init(
            &env->top, &env->functional,
            env->l1, sizeof(env->l1),
            env->l1_ecc, sizeof(env->l1_ecc),
            env->workspace,
            (const npu_wire_limits_t *)0,
            (const npu_lsc_cycle_config_t *)0,
            &mif, NPU_SINGLE_CORE_TBU_EXTERNAL),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(
        env->top.wire_limits.gaddr_limit ==
        sizeof(env->ddr));
    return 0;
}

static int single_test_capability_consistency(
    single_test_env_t *env)
{
    npu_config_t saved_functional;
    npu_wire_limits_t wire;
    npu_lsc_cycle_config_t lsc;
    npu_mif_cycle_config_t mif;
    uint64_t *lsc_packed_field[5];
    uint64_t preserved_cycle;
    uint32_t field;

    SINGLE_TEST_CALL(single_test_env_init(env));
    saved_functional = env->functional.config;
    npu_wire_limits_reference(&wire);
    wire.l1_bytes = NPU_L1_CYCLE_BYTES;
    wire.gaddr_limit = SINGLE_TEST_DDR_BYTES;
    npu_lsc_cycle_config_reference(&lsc);
    npu_mif_cycle_config_default(&mif);
    preserved_cycle = UINT64_C(0x1122334455667788);
    env->top.core_cycle = preserved_cycle;

    wire.mt++;
    TEST_CHECK_STATUS(
        npu_single_core_cycle_init(
            &env->top, &env->functional,
            env->l1, sizeof(env->l1),
            env->l1_ecc, sizeof(env->l1_ecc),
            env->workspace, &wire, &lsc, &mif,
            NPU_SINGLE_CORE_TBU_EXTERNAL),
        NPU_STATUS_BAD_DESC);
    TEST_CHECK(env->top.core_cycle == preserved_cycle);
    wire.mt--;

    lsc.vector_config ^= UINT64_C(1);
    TEST_CHECK_STATUS(
        npu_single_core_cycle_init(
            &env->top, &env->functional,
            env->l1, sizeof(env->l1),
            env->l1_ecc, sizeof(env->l1_ecc),
            env->workspace, &wire, &lsc, &mif,
            NPU_SINGLE_CORE_TBU_EXTERNAL),
        NPU_STATUS_BAD_DESC);
    TEST_CHECK(env->top.core_cycle == preserved_cycle);
    lsc.vector_config ^= UINT64_C(1);

    mif.ddr_enable = 2u;
    TEST_CHECK_STATUS(
        npu_single_core_cycle_init(
            &env->top, &env->functional,
            env->l1, sizeof(env->l1),
            env->l1_ecc, sizeof(env->l1_ecc),
            env->workspace, &wire, &lsc, &mif,
            NPU_SINGLE_CORE_TBU_EXTERNAL),
        NPU_STATUS_BAD_DESC);
    TEST_CHECK(env->top.core_cycle == preserved_cycle);
    mif.ddr_enable = 1u;

    lsc.timeout_reset[3]++;
    TEST_CHECK_STATUS(
        npu_single_core_cycle_init(
            &env->top, &env->functional,
            env->l1, sizeof(env->l1),
            env->l1_ecc, sizeof(env->l1_ecc),
            env->workspace, &wire, &lsc, &mif,
            NPU_SINGLE_CORE_TBU_EXTERNAL),
        NPU_STATUS_BAD_DESC);
    TEST_CHECK(env->top.core_cycle == preserved_cycle);
    lsc.timeout_reset[3]--;

    env->functional.config.cme_scratch_elems++;
    TEST_CHECK_STATUS(
        npu_single_core_cycle_init(
            &env->top, &env->functional,
            env->l1, sizeof(env->l1),
            env->l1_ecc, sizeof(env->l1_ecc),
            env->workspace, &wire, &lsc, &mif,
            NPU_SINGLE_CORE_TBU_EXTERNAL),
        NPU_STATUS_BAD_DESC);
    TEST_CHECK(env->top.core_cycle == preserved_cycle);
    env->functional.config = saved_functional;

    wire.gaddr_limit = SINGLE_TEST_DDR_BYTES + 1u;
    TEST_CHECK_STATUS(
        npu_single_core_cycle_init(
            &env->top, &env->functional,
            env->l1, sizeof(env->l1),
            env->l1_ecc, sizeof(env->l1_ecc),
            env->workspace, &wire, &lsc, &mif,
            NPU_SINGLE_CORE_TBU_EXTERNAL),
        NPU_STATUS_BAD_DESC);
    TEST_CHECK(env->top.core_cycle == preserved_cycle);
    wire.gaddr_limit = SINGLE_TEST_DDR_BYTES;

    lsc.isa_feature = NPU_LSC_ISA_DMA_GATHER_ND;
    TEST_CHECK_STATUS(
        npu_single_core_cycle_init(
            &env->top, &env->functional,
            env->l1, sizeof(env->l1),
            env->l1_ecc, sizeof(env->l1_ecc),
            env->workspace, &wire, &lsc, &mif,
            NPU_SINGLE_CORE_TBU_EXTERNAL),
        NPU_STATUS_BAD_DESC);
    TEST_CHECK(env->top.core_cycle == preserved_cycle);
    lsc.isa_feature = NPU_LSC_IMPLEMENTED_ISA_FEATURES;

    lsc_packed_field[0] = &lsc.bus_config;
    lsc_packed_field[1] = &lsc.l1_config;
    lsc_packed_field[2] = &lsc.matrix_config;
    lsc_packed_field[3] = &lsc.vector_config;
    lsc_packed_field[4] = &lsc.cme_config;
    for (field = 0u; field < 5u; field++) {
        *lsc_packed_field[field] |= UINT64_C(1) << 63u;
        TEST_CHECK_STATUS(
            npu_single_core_cycle_init(
                &env->top, &env->functional,
                env->l1, sizeof(env->l1),
                env->l1_ecc, sizeof(env->l1_ecc),
                env->workspace, &wire, &lsc, &mif,
                NPU_SINGLE_CORE_TBU_EXTERNAL),
            NPU_STATUS_BAD_DESC);
        TEST_CHECK(env->top.core_cycle == preserved_cycle);
        *lsc_packed_field[field] &= ~(UINT64_C(1) << 63u);
    }

    env->functional.config.mt = 4u;
    env->functional.config.kt = 8u;
    env->functional.config.nt = 4u;
    wire.mt = 4u;
    wire.kt = 8u;
    wire.nt = 4u;
    wire.gaddr_limit = SINGLE_TEST_DDR_BYTES - 8u;
    lsc.matrix_config =
        (UINT64_C(4) << NPU_LSC_MATRIX_MT_SHIFT) |
        (UINT64_C(8) << NPU_LSC_MATRIX_KT_SHIFT) |
        (UINT64_C(4) << NPU_LSC_MATRIX_NT_SHIFT) |
        (NPU_LSC_MATRIX_DTYPE_MASK <<
         NPU_LSC_MATRIX_DTYPE_MASK_SHIFT);
    TEST_CHECK_STATUS(
        npu_single_core_cycle_init(
            &env->top, &env->functional,
            env->l1, sizeof(env->l1),
            env->l1_ecc, sizeof(env->l1_ecc),
            env->workspace, &wire, &lsc, &mif,
            NPU_SINGLE_CORE_TBU_EXTERNAL),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(env->top.wire_limits.mt == 4u);
    TEST_CHECK(
        env->top.wire_limits.gaddr_limit ==
        SINGLE_TEST_DDR_BYTES - 8u);
    TEST_CHECK(
        ((env->top.lsc.config.matrix_config >>
          NPU_LSC_MATRIX_KT_SHIFT) &
         NPU_LSC_FIELD_U8_MASK) == 8u);
    return 0;
}

static int single_test_set_descriptor_rule(
    single_test_env_t *env,
    uint8_t read_enable)
{
    npu_tbu_rule_t rule;

    (void)memset(&rule, 0, sizeof(rule));
    rule.valid = 1u;
    rule.virtual_page = SINGLE_TEST_DESC_ADDR >> 12u;
    rule.physical_page =
        (uint32_t)(SINGLE_TEST_DESC_ADDR >> 12u);
    rule.stream_id = 0x1234u;
    rule.substream_id = 0x5678u;
    rule.read_enable = read_enable;
    rule.write_enable = 1u;
    TEST_CHECK(npu_tbu_cycle_set_rule(
                   &env->top.tbu, 0u, &rule) != 0);
    return 0;
}

static int single_test_reset_release(single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint8_t core_gate_bits;

    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.core_reset_n == 0u);
    TEST_CHECK(core_outputs.issue.issue_ready_o == 0u);
    SINGLE_TEST_CALL(single_test_noc_tick(env, &noc_outputs));
    TEST_CHECK(noc_outputs.noc_reset_n == 0u);

    env->core_rst_ni = 1u;
    env->noc_rst_ni = 1u;
    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.core_reset_n == 0u);
    single_test_core_tick(env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.core_reset_n != 0u);

    SINGLE_TEST_CALL(single_test_noc_tick(env, &noc_outputs));
    TEST_CHECK(noc_outputs.noc_reset_n == 0u);
    SINGLE_TEST_CALL(single_test_noc_tick(env, &noc_outputs));
    TEST_CHECK(noc_outputs.noc_reset_n != 0u);
    TEST_CHECK(env->top.crg.core_sync0 != 0u);
    TEST_CHECK(env->top.crg.core_sync1 != 0u);
    TEST_CHECK(env->top.crg.noc_sync0 != 0u);
    TEST_CHECK(env->top.crg.noc_sync1 != 0u);
    TEST_CHECK(npu_mif_cdc_cycle_is_active(&env->top.cdc) != 0u);

    core_gate_bits =
        (uint8_t)(env->top.crg.module_clk_active & 0x7fu);
    SINGLE_TEST_CALL(single_test_noc_tick_mask(
        env, 0u, &noc_outputs));
    TEST_CHECK((noc_outputs.module_clk_active_o & 0x7fu) ==
               core_gate_bits);
    TEST_CHECK((noc_outputs.module_clk_active_o & 0x80u) == 0u);

    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(env, &core_inputs, &core_outputs);
    TEST_CHECK((core_outputs.module_clk_active_o & 0x80u) ==
               0u);
    SINGLE_TEST_CALL(single_test_noc_tick(
        env, &noc_outputs));
    TEST_CHECK((noc_outputs.module_clk_active_o & 0x80u) != 0u);

    /*
     * A tick in one domain must not apply reset synchronization state for
     * the other domain, even when that other reset input is low.
     */
    single_test_core_inputs(env, &core_inputs);
    core_inputs.noc_rst_ni = 0u;
    single_test_core_tick(env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.crg.noc_reset_n != 0u);
    TEST_CHECK(env->top.crg.noc_sync0 != 0u);
    TEST_CHECK(env->top.crg.noc_sync1 != 0u);

    env->core_rst_ni = 0u;
    SINGLE_TEST_CALL(single_test_noc_tick(
        env, &noc_outputs));
    env->core_rst_ni = 1u;
    TEST_CHECK(noc_outputs.crg.core_reset_n != 0u);
    TEST_CHECK(env->top.crg.core_sync0 != 0u);
    TEST_CHECK(env->top.crg.core_sync1 != 0u);
    return 0;
}

static int single_test_wait_idle(single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint32_t cycle;

    for (cycle = 0u; cycle < 64u; cycle++) {
        SINGLE_TEST_CALL(single_test_noc_tick(
            env, &noc_outputs));
        single_test_core_inputs(env, &inputs);
        single_test_core_tick(env, &inputs, &outputs);
        if (outputs.core_idle_o != 0u) {
            return 0;
        }
    }
    return __LINE__;
}

static int single_test_system_write(
    single_test_env_t *env,
    uint32_t address,
    uint64_t data,
    uint8_t id)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint32_t cycle;
    uint8_t accepted = 0u;

    for (cycle = 0u; cycle < 64u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.system_axi.s_axi_awvalid = 1u;
        inputs.system_axi.s_axi_awid = id;
        inputs.system_axi.s_axi_awaddr = address;
        inputs.system_axi.s_axi_awlen = 0u;
        inputs.system_axi.s_axi_awsize = 3u;
        inputs.system_axi.s_axi_awburst =
            NPU_SYS_AXI_BURST_INCR;
        single_test_core_tick(env, &inputs, &outputs);
        SINGLE_TEST_CALL(single_test_noc_tick(
            env, &noc_outputs));
        if (outputs.system_axi.s_axi_awready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    accepted = 0u;
    for (cycle = 0u; cycle < 64u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.system_axi.s_axi_wvalid = 1u;
        inputs.system_axi.s_axi_wdata = data;
        inputs.system_axi.s_axi_wstrb = 0xffu;
        inputs.system_axi.s_axi_wlast = 1u;
        single_test_core_tick(env, &inputs, &outputs);
        SINGLE_TEST_CALL(single_test_noc_tick(
            env, &noc_outputs));
        if (outputs.system_axi.s_axi_wready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    for (cycle = 0u; cycle < 128u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.system_axi.s_axi_bready = 1u;
        single_test_core_tick(env, &inputs, &outputs);
        SINGLE_TEST_CALL(single_test_noc_tick(
            env, &noc_outputs));
        if (outputs.system_axi.s_axi_bvalid != 0u) {
            TEST_CHECK(outputs.system_axi.s_axi_bid == id);
            TEST_CHECK(outputs.system_axi.s_axi_bresp ==
                       NPU_SYS_AXI_RESP_OKAY);
            return 0;
        }
    }
    return __LINE__;
}

static int single_test_system_write_core_only(
    single_test_env_t *env,
    uint32_t address,
    uint64_t data,
    uint8_t id)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint32_t cycle;
    uint8_t accepted = 0u;

    for (cycle = 0u; cycle < 64u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.system_axi.s_axi_awvalid = 1u;
        inputs.system_axi.s_axi_awid = id;
        inputs.system_axi.s_axi_awaddr = address;
        inputs.system_axi.s_axi_awlen = 0u;
        inputs.system_axi.s_axi_awsize = 3u;
        inputs.system_axi.s_axi_awburst =
            NPU_SYS_AXI_BURST_INCR;
        single_test_core_tick(env, &inputs, &outputs);
        if (outputs.system_axi.s_axi_awready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    accepted = 0u;
    for (cycle = 0u; cycle < 64u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.system_axi.s_axi_wvalid = 1u;
        inputs.system_axi.s_axi_wdata = data;
        inputs.system_axi.s_axi_wstrb = 0xffu;
        inputs.system_axi.s_axi_wlast = 1u;
        single_test_core_tick(env, &inputs, &outputs);
        if (outputs.system_axi.s_axi_wready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    for (cycle = 0u; cycle < 128u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.system_axi.s_axi_bready = 1u;
        single_test_core_tick(env, &inputs, &outputs);
        if (outputs.system_axi.s_axi_bvalid != 0u) {
            TEST_CHECK(outputs.system_axi.s_axi_bid == id);
            TEST_CHECK(outputs.system_axi.s_axi_bresp ==
                       NPU_SYS_AXI_RESP_OKAY);
            return 0;
        }
    }
    return __LINE__;
}

static int single_test_system_read(
    single_test_env_t *env,
    uint32_t address,
    uint8_t id,
    uint64_t expected)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint32_t cycle;
    uint8_t accepted = 0u;
    uint64_t held_data;

    for (cycle = 0u; cycle < 64u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.system_axi.s_axi_arvalid = 1u;
        inputs.system_axi.s_axi_arid = id;
        inputs.system_axi.s_axi_araddr = address;
        inputs.system_axi.s_axi_arlen = 0u;
        inputs.system_axi.s_axi_arsize = 3u;
        inputs.system_axi.s_axi_arburst =
            NPU_SYS_AXI_BURST_INCR;
        single_test_core_tick(env, &inputs, &outputs);
        SINGLE_TEST_CALL(single_test_noc_tick(
            env, &noc_outputs));
        if (outputs.system_axi.s_axi_arready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    for (cycle = 0u; cycle < 128u; cycle++) {
        single_test_core_inputs(env, &inputs);
        single_test_core_tick(env, &inputs, &outputs);
        SINGLE_TEST_CALL(single_test_noc_tick(
            env, &noc_outputs));
        if (outputs.system_axi.s_axi_rvalid != 0u) {
            break;
        }
    }
    TEST_CHECK(outputs.system_axi.s_axi_rvalid != 0u);
    TEST_CHECK(outputs.system_axi.s_axi_rid == id);
    TEST_CHECK(outputs.system_axi.s_axi_rresp ==
               NPU_SYS_AXI_RESP_OKAY);
    TEST_CHECK(outputs.system_axi.s_axi_rlast != 0u);
    TEST_CHECK(outputs.system_axi.s_axi_rdata == expected);
    held_data = outputs.system_axi.s_axi_rdata;

    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.system_axi.s_axi_rvalid != 0u);
    TEST_CHECK(outputs.system_axi.s_axi_rdata == held_data);

    single_test_core_inputs(env, &inputs);
    inputs.system_axi.s_axi_rready = 1u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.system_axi.s_axi_rvalid != 0u);
    TEST_CHECK(outputs.system_axi.s_axi_rdata == held_data);
    return 0;
}

static int single_test_system_and_debug(single_test_env_t *env)
{
    const uint64_t debug_data =
        UINT64_C(0x8877665544332211);

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_LSC_REG_DDR_LOCAL_LIMIT,
        UINT64_C(0x00000000000ffff8), 0x11u));
    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_LSC_REG_TBU_STREAM_ID,
        UINT64_C(0x56781234), 0x12u));
    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_LSC_REG_L1_DIAG_CONTROL,
        NPU_LSC_L1_DIAG_ENABLE, 0x13u));
    TEST_CHECK(env->top.lsc.l1_diag_enable != 0u);

    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_SYS_SLAVE_L1_BASE +
                 SINGLE_TEST_DEBUG_ADDR,
        debug_data, 0x14u));
    TEST_CHECK(single_test_get_u64(
                   env->l1, SINGLE_TEST_DEBUG_ADDR) ==
               debug_data);
    SINGLE_TEST_CALL(single_test_system_read(
        env, NPU_SYS_SLAVE_L1_BASE +
                 SINGLE_TEST_DEBUG_ADDR,
        0x15u, debug_data));

    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x16u));
    TEST_CHECK(env->top.lsc.started != 0u);
    TEST_CHECK(env->top.lsc.stopped == 0u);
    return 0;
}

static int single_test_idle_module_clocks(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint64_t cfe_cycle;
    uint64_t ts_cycle;
    uint64_t l1_cycle;
    uint64_t issue_cycle;
    uint64_t system_cycle;
    uint64_t gc_cycle;
    uint64_t diag_cycle;
    uint64_t cdc_cycle;
    uint64_t engine_cycle[NPU_TS_ENGINE_COUNT];
    uint32_t tick;
    uint32_t engine;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    cfe_cycle = env->top.cfe.cycle;
    ts_cycle = env->top.ts.cycle;
    l1_cycle = env->top.l1.cycle;
    issue_cycle = env->top.issue.cycle;
    system_cycle = env->top.system_axi.cycle;
    gc_cycle = env->top.gc_axi.cycle_count;
    diag_cycle = env->top.l1_diag.cycle;
    cdc_cycle = env->top.cdc.core_tick_count;
    for (engine = 0u; engine < NPU_TS_ENGINE_COUNT; engine++) {
        engine_cycle[engine] = env->top.engine[engine].cycle;
    }

    for (tick = 0u; tick < 4u; tick++) {
        single_test_core_inputs(env, &inputs);
        inputs.module_clk_en_i = 0u;
        inputs.wdt_enable_i = 1u;
        inputs.wdt_timeout_cycles_i = 100u;
        single_test_core_tick(env, &inputs, &outputs);
        TEST_CHECK(
            (outputs.module_clk_active_o & 0x7fu) == 0u);
        TEST_CHECK(env->top.cfe.cycle == cfe_cycle);
        TEST_CHECK(env->top.ts.cycle == ts_cycle);
        TEST_CHECK(env->top.l1.cycle == l1_cycle);
        for (engine = 0u;
             engine < NPU_TS_ENGINE_COUNT; engine++) {
            TEST_CHECK(env->top.engine[engine].cycle ==
                       engine_cycle[engine]);
        }
        TEST_CHECK(outputs.progress_pulse_o == 0u);
        TEST_CHECK(outputs.wdt.count == tick + 1u);
    }
    TEST_CHECK(env->top.issue.cycle == issue_cycle + 4u);
    TEST_CHECK(env->top.system_axi.cycle ==
               system_cycle + 4u);
    TEST_CHECK(env->top.gc_axi.cycle_count == gc_cycle + 4u);
    TEST_CHECK(env->top.l1_diag.cycle == diag_cycle + 4u);
    TEST_CHECK(env->top.cdc.core_tick_count == cdc_cycle + 4u);

    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(
        (outputs.module_clk_active_o & 0x7fu) == 0x7fu);
    return 0;
}

static int single_test_top_control_signals(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint32_t tick;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x2au));

    single_test_core_inputs(env, &inputs);
    inputs.module_clk_en_i = 0u;
    inputs.scan_mode_i = 1u;
    inputs.stop_fetch_i = 1u;
    inputs.issue_valid_i = 1u;
    inputs.issue_opcode_i = NPU_ISSUE_CUSTOM0_OPCODE;
    inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_QUERY;
    inputs.issue_funct7_i = 0u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK((outputs.module_clk_active_o & 0x7fu) == 0x7fu);
    TEST_CHECK(outputs.effective_stop_fetch_o != 0u);
    TEST_CHECK(outputs.issue.issue_ready_o == 0u);
    TEST_CHECK(outputs.clk_req_o != 0u);
    TEST_CHECK(outputs.soft_reset_done_o ==
               outputs.lsc.soft_reset_done);
    TEST_CHECK(outputs.power_down_ack_o ==
               outputs.lsc.power_down_ack);
    TEST_CHECK(outputs.wdt_reset_req_o ==
               outputs.wdt.reset_req);

    single_test_core_inputs(env, &inputs);
    inputs.clk_ack_i = 1u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.effective_stop_fetch_o == 0u);
    TEST_CHECK(outputs.issue.issue_ready_o != 0u);
    TEST_CHECK(outputs.clk_req_o != 0u);

    for (tick = 0u; tick < 8u; tick++) {
        single_test_core_inputs(env, &inputs);
        inputs.power_down_req_i = 1u;
        inputs.issue_valid_i = 1u;
        inputs.issue_opcode_i = NPU_ISSUE_CUSTOM0_OPCODE;
        inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_QUERY;
        inputs.issue_funct7_i = 0u;
        single_test_core_tick(env, &inputs, &outputs);
        TEST_CHECK(outputs.issue.issue_ready_o == 0u);
        TEST_CHECK(env->top.issue.state ==
                   NPU_ISSUE_STATE_IDLE);
        if (outputs.power_down_ack_o != 0u) {
            break;
        }
    }
    TEST_CHECK(outputs.power_down_ack_o != 0u);
    TEST_CHECK(outputs.effective_stop_fetch_o != 0u);
    TEST_CHECK(outputs.clk_req_o == 0u);

    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.power_down_ack_o == 0u);
    TEST_CHECK(outputs.clk_req_o != 0u);
    return 0;
}

static int single_test_dvfs_quiesce(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x2du));
    SINGLE_TEST_CALL(single_test_wait_idle(env));

    env->top.last_lsc.core_idle = 0u;
    single_test_core_inputs(env, &inputs);
    inputs.dvfs_prepare_req_i = 1u;
    inputs.issue_valid_i = 1u;
    inputs.issue_opcode_i = NPU_ISSUE_CUSTOM0_OPCODE;
    inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_QUERY;
    inputs.gc_axi.icache_req.valid = 1u;
    inputs.gc_axi.icache_req.addr = 0x80u;
    inputs.gc_axi.icache_req.beats = 1u;
    inputs.gc_axi.icache_req.tag = 0x31u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.crg.dvfs_prepare_ack_o != 0u);
    TEST_CHECK(outputs.effective_stop_fetch_o != 0u);
    TEST_CHECK(outputs.issue.issue_ready_o == 0u);
    TEST_CHECK(outputs.gc_axi.icache_req_ready == 0u);
    TEST_CHECK(env->top.issue.state ==
               NPU_ISSUE_STATE_IDLE);
    TEST_CHECK(npu_gc_axi_cycle_is_idle(
                   &env->top.gc_axi) != 0u);

    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.crg.dvfs_prepare_ack_o != 0u);
    TEST_CHECK(outputs.issue.issue_ready_o == 0u);
    TEST_CHECK(outputs.gc_axi.icache_req_ready == 0u);

    inputs.dvfs_prepare_req_i = 0u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.crg.dvfs_prepare_ack_o == 0u);
    TEST_CHECK(outputs.effective_stop_fetch_o == 0u);
    TEST_CHECK(outputs.issue.issue_ready_o != 0u);
    TEST_CHECK(outputs.gc_axi.icache_req_ready != 0u);
    TEST_CHECK(env->top.issue.state !=
               NPU_ISSUE_STATE_IDLE);
    TEST_CHECK(npu_gc_axi_cycle_is_idle(
                   &env->top.gc_axi) == 0u);
    return 0;
}

static int single_test_current_idle_access(
    single_test_env_t *env)
{
    const uint64_t expected =
        UINT64_C(0x76543210fedcba98);
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint32_t cycle;
    uint8_t response_seen = 0u;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_LSC_REG_L1_DIAG_CONTROL,
        NPU_LSC_L1_DIAG_ENABLE, 0x32u));
    single_test_put_u64(
        env->l1, SINGLE_TEST_DEBUG_ADDR, expected);

    env->top.last_lsc.core_idle = 0u;
    SINGLE_TEST_CALL(single_test_system_read(
        env, NPU_SYS_SLAVE_L1_BASE +
                 SINGLE_TEST_DEBUG_ADDR,
        0x33u, expected));
    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x35u));
    SINGLE_TEST_CALL(single_test_wait_idle(env));

    single_test_core_inputs(env, &inputs);
    inputs.issue_valid_i = 1u;
    inputs.issue_opcode_i = NPU_ISSUE_CUSTOM0_OPCODE;
    inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_QUERY;
    inputs.system_axi.s_axi_arvalid = 1u;
    inputs.system_axi.s_axi_arid = 0x34u;
    inputs.system_axi.s_axi_araddr =
        NPU_SYS_SLAVE_L1_BASE + SINGLE_TEST_DEBUG_ADDR;
    inputs.system_axi.s_axi_arlen = 0u;
    inputs.system_axi.s_axi_arsize = 3u;
    inputs.system_axi.s_axi_arburst =
        NPU_SYS_AXI_BURST_INCR;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.issue.issue_ready_o != 0u);
    TEST_CHECK(outputs.system_axi.s_axi_arready != 0u);

    for (cycle = 0u; cycle < 16u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.system_axi.s_axi_rready = 1u;
        single_test_core_tick(env, &inputs, &outputs);
        if (outputs.system_axi.s_axi_rvalid != 0u) {
            TEST_CHECK(outputs.system_axi.s_axi_rid == 0x34u);
            TEST_CHECK(outputs.system_axi.s_axi_rresp ==
                       NPU_SYS_AXI_RESP_SLVERR);
            response_seen = 1u;
            break;
        }
    }
    TEST_CHECK(response_seen != 0u);
    return 0;
}

static int single_test_functional_perf_bridge(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    TEST_CHECK(env->top.lsc.perf_counter[13] == 0u);
    TEST_CHECK(env->top.lsc.perf_counter[14] == 0u);

    env->functional.perf.int_saturate_count++;
    env->functional.perf.all_mask_row_count += 2u;
    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(env->top.lsc.perf_counter[13] == 0u);
    TEST_CHECK(env->top.lsc.perf_counter[14] == 0u);
    TEST_CHECK(env->top.pending_int_saturate_count == 1u);
    TEST_CHECK(env->top.pending_all_mask_row_count == 2u);

    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(env->top.lsc.perf_counter[13] == 1u);
    TEST_CHECK(env->top.lsc.perf_counter[14] == 2u);
    TEST_CHECK(env->top.pending_int_saturate_count == 0u);
    TEST_CHECK(env->top.pending_all_mask_row_count == 0u);

    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_SYS_SLAVE_DEBUG_BASE +
                 NPU_LSC_REG_PERF_CONTROL,
        NPU_LSC_PERF_FREEZE, 0x2bu));
    env->functional.perf.int_saturate_count += 3u;
    env->functional.perf.all_mask_row_count += 4u;
    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(env->top.lsc.perf_counter[13] == 1u);
    TEST_CHECK(env->top.lsc.perf_counter[14] == 2u);
    TEST_CHECK(env->top.pending_int_saturate_count == 0u);
    TEST_CHECK(env->top.pending_all_mask_row_count == 0u);

    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_SYS_SLAVE_DEBUG_BASE +
                 NPU_LSC_REG_PERF_CONTROL,
        0u, 0x2cu));
    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(env->top.lsc.perf_counter[13] == 1u);
    TEST_CHECK(env->top.lsc.perf_counter[14] == 2u);
    return 0;
}

static int single_test_ts_terminal_keeps_clock(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint64_t before;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    env->top.ts.task[0].valid = 1u;
    env->top.ts.task[0].state = NPU_TS_TASK_SUCCESS;
    env->top.ts.task[0].cmd.command_id = 0x5a1u;
    before = env->top.ts.cycle;

    single_test_core_inputs(env, &inputs);
    inputs.module_clk_en_i =
        (uint8_t)(NPU_SINGLE_CORE_CLK_ALL &
                  ~(uint8_t)(1u <<
                      NPU_SINGLE_CORE_CLK_TS));
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(single_test_clock_active(
                   outputs.module_clk_active_o,
                   NPU_SINGLE_CORE_CLK_TS) != 0u);
    TEST_CHECK(env->top.ts.cycle == before + 1u);
    TEST_CHECK(outputs.ts.idle == 0u);

    env->top.ts.task[0].valid = 0u;
    env->top.ts.task[0].state = NPU_TS_TASK_FREE;
    single_test_core_inputs(env, &inputs);
    inputs.module_clk_en_i =
        (uint8_t)(NPU_SINGLE_CORE_CLK_ALL &
                  ~(uint8_t)(1u <<
                      NPU_SINGLE_CORE_CLK_TS));
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(single_test_clock_active(
                   outputs.module_clk_active_o,
                   NPU_SINGLE_CORE_CLK_TS) == 0u);
    TEST_CHECK(outputs.ts.idle != 0u);
    return 0;
}

static int single_test_idle_cfe_clock(single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint64_t low_beat;
    uint64_t high_beat;
    uint64_t held_cycle;
    uint32_t cycle;
    npu_single_core_cycle_noc_outputs_t noc_outputs;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x21u));
    single_test_make_command(
        SINGLE_TEST_COMMAND, &low_beat, &high_beat);
    held_cycle = env->top.cfe.cycle;

    single_test_core_inputs(env, &inputs);
    inputs.module_clk_en_i =
        (uint8_t)(NPU_SINGLE_CORE_CLK_ALL &
                  ~(uint8_t)(1u <<
                      NPU_SINGLE_CORE_CLK_CFE));
    inputs.issue_valid_i = 1u;
    inputs.issue_opcode_i = NPU_ISSUE_CUSTOM0_OPCODE;
    inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_SUBMIT;
    inputs.issue_rs1_i = low_beat;
    inputs.issue_rs2_i = high_beat;
    inputs.issue_rd_i = 7u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(single_test_clock_active(
                   outputs.module_clk_active_o,
                   NPU_SINGLE_CORE_CLK_CFE) == 0u);
    TEST_CHECK(outputs.cfe.gc_cmd_ready_o == 0u);
    TEST_CHECK(env->top.cfe.state == NPU_CFE_STATE_IDLE);
    TEST_CHECK(env->top.cfe.cycle == held_cycle);
    TEST_CHECK(outputs.issue.issue_ready_o != 0u);
    SINGLE_TEST_CALL(single_test_noc_tick(
        env, &noc_outputs));
    TEST_CHECK(single_test_clock_active(
                   noc_outputs.module_clk_active_o,
                   NPU_SINGLE_CORE_CLK_CFE) == 0u);

    for (cycle = 0u; cycle < 5u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.module_clk_en_i =
            (uint8_t)(NPU_SINGLE_CORE_CLK_ALL &
                      ~(uint8_t)(1u <<
                          NPU_SINGLE_CORE_CLK_CFE));
        single_test_core_tick(env, &inputs, &outputs);
        TEST_CHECK(outputs.cfe.gc_cmd_ready_o == 0u);
        TEST_CHECK(outputs.issue.gc_cmd_valid_o != 0u);
        TEST_CHECK(env->top.cfe.state ==
                   NPU_CFE_STATE_IDLE);
        TEST_CHECK(env->top.cfe.cycle == held_cycle);
    }

    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(single_test_clock_active(
                   outputs.module_clk_active_o,
                   NPU_SINGLE_CORE_CLK_CFE) != 0u);
    TEST_CHECK(outputs.cfe.gc_cmd_ready_o != 0u);
    TEST_CHECK(outputs.issue.gc_cmd_valid_o != 0u);
    TEST_CHECK(outputs.issue.gc_cmd_first_o != 0u);
    TEST_CHECK(outputs.issue.gc_cmd_last_o == 0u);
    TEST_CHECK(outputs.issue.gc_cmd_data_o == low_beat);
    TEST_CHECK(env->top.issue.state ==
               NPU_ISSUE_STATE_SUBMIT_HIGH);
    TEST_CHECK(env->top.cfe.state ==
               NPU_CFE_STATE_WAIT_HI);
    TEST_CHECK(env->top.cfe.low_beat == low_beat);
    TEST_CHECK(env->top.cfe.cycle == held_cycle + 1u);

    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.gc_cmd_ready_o != 0u);
    TEST_CHECK(outputs.issue.gc_cmd_valid_o != 0u);
    TEST_CHECK(outputs.issue.gc_cmd_first_o == 0u);
    TEST_CHECK(outputs.issue.gc_cmd_last_o != 0u);
    TEST_CHECK(outputs.issue.gc_cmd_data_o == high_beat);
    TEST_CHECK(env->top.issue.state ==
               NPU_ISSUE_STATE_SUBMIT_RESPONSE);
    TEST_CHECK(env->top.cfe.state == NPU_CFE_STATE_CHECK);
    TEST_CHECK(env->top.cfe.high_beat == high_beat);
    TEST_CHECK(env->top.cfe.cycle == held_cycle + 2u);
    return 0;
}

static int single_test_cfe_accept_perf_once(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint64_t low_beat;
    uint64_t high_beat;
    uint64_t before;
    uint8_t issue_accepted = 0u;
    uint8_t reached_enqueue = 0u;
    uint32_t cycle;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x25u));
    single_test_make_command(
        0x470u, &low_beat, &high_beat);
    for (cycle = 0u; cycle < 128u; cycle++) {
        single_test_core_inputs(env, &inputs);
        if (issue_accepted == 0u) {
            inputs.issue_valid_i = 1u;
            inputs.issue_opcode_i = NPU_ISSUE_CUSTOM0_OPCODE;
            inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_SUBMIT;
            inputs.issue_rs1_i = low_beat;
            inputs.issue_rs2_i = high_beat;
            inputs.issue_rd_i = 8u;
        }
        single_test_core_tick(env, &inputs, &outputs);
        if (inputs.issue_valid_i != 0u &&
            outputs.issue.issue_ready_o != 0u) {
            issue_accepted = 1u;
        }
        if (env->top.cfe.state == NPU_CFE_STATE_ENQUEUE) {
            reached_enqueue = 1u;
            break;
        }
    }
    TEST_CHECK(issue_accepted != 0u);
    TEST_CHECK(reached_enqueue != 0u);

    before = env->top.lsc.perf_counter[1];
    for (cycle = 0u; cycle < 8u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.module_clk_en_i =
            (uint8_t)(NPU_SINGLE_CORE_CLK_ALL &
                      ~(uint8_t)(1u <<
                          NPU_SINGLE_CORE_CLK_TS));
        single_test_core_tick(env, &inputs, &outputs);
        TEST_CHECK(single_test_clock_active(
                       outputs.module_clk_active_o,
                       NPU_SINGLE_CORE_CLK_TS) == 0u);
        if (cycle == 1u) {
            TEST_CHECK(outputs.cfe.cmd_accepted_o != 0u);
        } else {
            TEST_CHECK(outputs.cfe.cmd_accepted_o == 0u);
        }
    }
    TEST_CHECK(outputs.cfe.ts_cmd_valid_o != 0u);
    TEST_CHECK(env->top.lsc.perf_counter[1] ==
               before + 1u);
    return 0;
}

static int single_test_wdt_held_l1_response(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_l1_cycle_read_pipe_t *held =
        &env->top.l1.read_pipe[NPU_L1_RD_IVE_SRC0][0];
    uint32_t cycle;
    uint8_t timeout_seen = 0u;

    held->valid = 1u;
    held->data = UINT64_C(0x0123456789abcdef);
    held->tag = 0x31u;
    held->last = 1u;
    held->status = NPU_L1_STATUS_OK;
    for (cycle = 0u; cycle < 8u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.wdt_enable_i = 1u;
        inputs.wdt_timeout_cycles_i = 3u;
        single_test_core_tick(env, &inputs, &outputs);
        TEST_CHECK(outputs.l1.read[NPU_L1_RD_IVE_SRC0]
                       .rsp_valid != 0u);
        TEST_CHECK(outputs.engine[NPU_TS_PORT_VECTOR]
                       .l1_read[0].rsp_ready == 0u);
        TEST_CHECK(outputs.progress_pulse_o == 0u);
        if (outputs.wdt.timeout != 0u) {
            timeout_seen = 1u;
            break;
        }
    }
    TEST_CHECK(timeout_seen != 0u);
    TEST_CHECK(outputs.wdt.count == 3u);
    return 0;
}

static void single_test_prepare_compute_activity(
    npu_engine_data_cycle_t *engine,
    npu_engine_data_compute_stage_t stage)
{
    engine->data_pending = 1u;
    engine->engine.state = NPU_ENGINE_CYCLE_EXECUTE;
    engine->engine.execute_remaining = 32u;
    engine->replay.trace = &engine->trace;
    engine->replay.state = NPU_BUS_REPLAY_COMPUTE_HOLD;
    engine->replay.compute_required = 1u;
    engine->compute_stage = stage;
    engine->compute_groups = 16u;
    engine->compute_groups_issued = 0u;
    engine->compute_stage_remaining = 16u;
    engine->compute_total_cycles = 16u;
    engine->compute_elapsed = 0u;
    if (stage == NPU_ENGINE_DATA_COMPUTE_CME_PIPELINE) {
        engine->cme_i2f_start = 0u;
        engine->cme_i2f_cycles = 16u;
        engine->cme_fp_start = 0u;
        engine->cme_fp_cycles = 16u;
        engine->cme_f2i_start = 0u;
        engine->cme_f2i_cycles = 16u;
    }
}

static int single_test_wdt_compute_activity(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint64_t active_before;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x41u));
    SINGLE_TEST_CALL(single_test_wait_idle(env));

    active_before = env->top.lsc.perf_counter[0];
    single_test_prepare_compute_activity(
        &env->top.engine[NPU_TS_PORT_MATRIX],
        NPU_ENGINE_DATA_COMPUTE_ME);
    single_test_core_inputs(env, &inputs);
    inputs.wdt_enable_i = 1u;
    inputs.wdt_timeout_cycles_i = 1u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_MATRIX]
                   .me_mac_active != 0u);
    TEST_CHECK(outputs.progress_pulse_o != 0u);
    TEST_CHECK(outputs.wdt.timeout == 0u);
    TEST_CHECK(outputs.wdt.count == 0u);
    TEST_CHECK(env->top.lsc.perf_counter[0] ==
               active_before + 1u);
    npu_engine_data_cycle_reset(
        &env->top.engine[NPU_TS_PORT_MATRIX]);

    single_test_prepare_compute_activity(
        &env->top.engine[NPU_TS_PORT_VECTOR],
        NPU_ENGINE_DATA_COMPUTE_IVE);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_VECTOR]
                   .ive_alu_active != 0u);
    TEST_CHECK(outputs.progress_pulse_o != 0u);
    TEST_CHECK(outputs.wdt.timeout == 0u);
    TEST_CHECK(outputs.wdt.count == 0u);
    npu_engine_data_cycle_reset(
        &env->top.engine[NPU_TS_PORT_VECTOR]);

    single_test_prepare_compute_activity(
        &env->top.engine[NPU_TS_PORT_COMPLEX],
        NPU_ENGINE_DATA_COMPUTE_CME_PIPELINE);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_COMPLEX]
                   .cme_i2f_active != 0u);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_COMPLEX]
                   .cme_fp_active != 0u);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_COMPLEX]
                   .cme_f2i_active != 0u);
    TEST_CHECK(outputs.progress_pulse_o != 0u);
    TEST_CHECK(outputs.wdt.timeout == 0u);
    TEST_CHECK(outputs.wdt.count == 0u);

    return 0;
}

static int single_test_wdt_issue_progress(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x43u));
    SINGLE_TEST_CALL(single_test_wait_idle(env));

    single_test_core_inputs(env, &inputs);
    inputs.issue_valid_i = 1u;
    inputs.issue_opcode_i = NPU_ISSUE_CUSTOM0_OPCODE;
    inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_QUERY;
    inputs.issue_funct7_i = 0u;
    inputs.issue_rs1_i = 0u;
    inputs.issue_rs2_i = 0u;
    inputs.issue_rd_i = 1u;
    inputs.wdt_enable_i = 1u;
    inputs.wdt_timeout_cycles_i = 1u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.issue.issue_ready_o != 0u);
    TEST_CHECK(outputs.progress_pulse_o != 0u);
    TEST_CHECK(outputs.wdt.timeout == 0u);
    TEST_CHECK(outputs.wdt.count == 0u);

    npu_issue_adapter_cycle_reset(&env->top.issue);
    npu_cfe_cycle_reset(&env->top.cfe);
    npu_ts_cycle_reset(&env->top.ts);
    env->top.issue.state = NPU_ISSUE_STATE_CORE_RESPONSE;
    env->top.issue.rd = 7u;
    env->top.issue.response_data =
        UINT64_C(0x1122334455667788);
    single_test_core_inputs(env, &inputs);
    inputs.issue_rsp_ready_i = 1u;
    inputs.wdt_enable_i = 1u;
    inputs.wdt_timeout_cycles_i = 1u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.issue.issue_rsp_valid_o != 0u);
    TEST_CHECK(outputs.issue.issue_rsp_rd_o == 7u);
    TEST_CHECK(outputs.progress_pulse_o != 0u);
    TEST_CHECK(outputs.wdt.timeout == 0u);
    TEST_CHECK(outputs.wdt.count == 0u);
    return 0;
}

static int single_test_wdt_lookup_progress(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;

    env->top.cfe.state = NPU_CFE_STATE_LOOKUP_ID;
    env->top.cfe.response_command_id = 0x5a3u;
    env->top.cfe.lookup_request_sent = 0u;

    single_test_core_inputs(env, &inputs);
    inputs.wdt_enable_i = 1u;
    inputs.wdt_timeout_cycles_i = 1u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.cmd_id_lookup_valid_o != 0u);
    TEST_CHECK(outputs.ts.cfe.lookup_ready != 0u);
    TEST_CHECK(outputs.progress_pulse_o != 0u);
    TEST_CHECK(outputs.wdt.timeout == 0u);
    TEST_CHECK(outputs.wdt.count == 0u);

    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.ts.cfe.lookup_rsp_valid != 0u);
    TEST_CHECK(outputs.progress_pulse_o != 0u);
    TEST_CHECK(outputs.wdt.timeout == 0u);
    TEST_CHECK(outputs.wdt.count == 0u);
    return 0;
}

static int single_test_wdt_desc_progress(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_engine_cycle_t *engine =
        &env->top.engine[NPU_TS_PORT_MATRIX].engine;
    npu_ts_desc_slot_t *slot = &env->top.ts.desc_slot[0];

    engine->state = NPU_ENGINE_CYCLE_FETCH_DESC;
    engine->desc_slot = 0u;
    engine->descriptor_bytes = NPU_REF_BUS_BYTES;
    engine->descriptor_words = 1u;
    engine->next_desc_word = 0u;
    slot->allocated = 1u;
    slot->full = 1u;
    slot->owner_engine = NPU_ENGINE_MATRIX;
    slot->bytes = NPU_REF_BUS_BYTES;
    single_test_put_u64(
        slot->data, 0u, UINT64_C(0x8877665544332211));

    single_test_core_inputs(env, &inputs);
    inputs.wdt_enable_i = 1u;
    inputs.wdt_timeout_cycles_i = 1u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_MATRIX]
                   .engine.desc_rd_req_valid_o != 0u);
    TEST_CHECK(outputs.ts.desc[NPU_TS_PORT_MATRIX]
                   .req_ready != 0u);
    TEST_CHECK(outputs.progress_pulse_o != 0u);
    TEST_CHECK(outputs.wdt.timeout == 0u);
    TEST_CHECK(outputs.wdt.count == 0u);

    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.ts.desc[NPU_TS_PORT_MATRIX]
                   .rsp_valid != 0u);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_MATRIX]
                   .engine.desc_rd_rsp_ready_o != 0u);
    TEST_CHECK(outputs.progress_pulse_o != 0u);
    TEST_CHECK(outputs.wdt.timeout == 0u);
    TEST_CHECK(outputs.wdt.count == 0u);
    return 0;
}

static int single_test_wdt_gc_axi_progress(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint8_t axi_id = 0u;
    uint8_t address_seen = 0u;
    uint8_t response_seen = 0u;
    uint32_t cycle;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x42u));
    SINGLE_TEST_CALL(single_test_wait_idle(env));

    single_test_core_inputs(env, &inputs);
    inputs.gc_axi.icache_req.valid = 1u;
    inputs.gc_axi.icache_req.addr = 0x100u;
    inputs.gc_axi.icache_req.beats = 1u;
    inputs.gc_axi.icache_req.tag = 0x123u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.gc_axi.icache_req_ready != 0u);

    for (cycle = 0u; cycle < 16u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.gc_axi.axi.arready = 1u;
        single_test_core_tick(env, &inputs, &outputs);
        if (outputs.gc_axi.axi.arvalid != 0u) {
            axi_id = outputs.gc_axi.axi.arid;
            address_seen = 1u;
            break;
        }
    }
    TEST_CHECK(address_seen != 0u);

    single_test_core_inputs(env, &inputs);
    inputs.gc_axi.axi.rvalid = 1u;
    inputs.gc_axi.axi.rid = axi_id;
    inputs.gc_axi.axi.rdata =
        UINT64_C(0x8877665544332211);
    inputs.gc_axi.axi.rresp = NPU_GC_AXI_RESP_OKAY;
    inputs.gc_axi.axi.rlast = 1u;
    inputs.wdt_enable_i = 1u;
    inputs.wdt_timeout_cycles_i = 1u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.gc_axi.axi.rready != 0u);
    TEST_CHECK(outputs.progress_pulse_o != 0u);
    TEST_CHECK(outputs.wdt.timeout == 0u);
    TEST_CHECK(outputs.wdt.count == 0u);

    for (cycle = 0u; cycle < 8u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.gc_axi.icache_rsp_ready = 1u;
        inputs.wdt_enable_i = 1u;
        inputs.wdt_timeout_cycles_i = 1u;
        single_test_core_tick(env, &inputs, &outputs);
        if (outputs.gc_axi.icache_rsp.valid != 0u) {
            TEST_CHECK(outputs.gc_axi.icache_rsp.tag ==
                       0x123u);
            TEST_CHECK(outputs.progress_pulse_o != 0u);
            TEST_CHECK(outputs.wdt.timeout == 0u);
            TEST_CHECK(outputs.wdt.count == 0u);
            response_seen = 1u;
            break;
        }
    }
    TEST_CHECK(response_seen != 0u);
    return 0;
}

static int single_test_l1_ecc_event_count(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_l1_cycle_read_pipe_t *first =
        &env->top.l1.read_pipe[NPU_L1_RD_ME_A][0];
    npu_l1_cycle_read_pipe_t *second =
        &env->top.l1.read_pipe[NPU_L1_RD_ME_B][0];
    uint64_t before;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    before = env->top.lsc.perf_counter[15];
    (void)memset(first, 0, sizeof(*first));
    (void)memset(second, 0, sizeof(*second));
    first->valid = 1u;
    first->tag = 0x161u;
    first->last = 1u;
    first->status = NPU_L1_STATUS_ECC_CORRECTED;
    first->ecc_event_pending = 1u;
    second->valid = 1u;
    second->tag = 0x162u;
    second->last = 1u;
    second->status = NPU_L1_STATUS_ECC_CORRECTED;
    second->ecc_event_pending = 1u;

    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.l1.ecc_corrected_pulse != 0u);
    TEST_CHECK(outputs.l1.ecc_corrected_events == 2u);
    TEST_CHECK(env->top.lsc.perf_counter[15] ==
               before + 2u);
    return 0;
}

static int single_test_wdt_event_not_repeated(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    env->top.wdt.count = 3u;
    env->top.wdt.timeout = 1u;
    env->top.last_wdt.count = 3u;
    env->top.last_wdt.timeout = 1u;
    env->top.last_wdt.reset_req = 1u;
    env->top.last_wdt_timeout_level = 0u;

    single_test_core_inputs(env, &inputs);
    inputs.wdt_enable_i = 1u;
    inputs.wdt_timeout_cycles_i = 3u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(env->top.lsc.fault_valid != 0u);
    TEST_CHECK(env->top.lsc.fault_source ==
               NPU_LSC_FAULT_SOURCE_WDT);
    TEST_CHECK(outputs.wdt_reset_req_o != 0u);

    /*
     * This is the state immediately after a completed FAULT_CLEAR write.
     * Keep the WDT output high to prove that the old level is not turned
     * into another LSC event.
     */
    env->top.lsc.fault_valid = 0u;
    env->top.lsc.fault_command_id = 0u;
    env->top.lsc.fault_source = NPU_LSC_FAULT_SOURCE_TASK;
    single_test_core_tick(env, &inputs, &outputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.wdt.timeout != 0u);
    TEST_CHECK(env->top.lsc.fault_valid == 0u);

    (void)memset(
        &env->top.l1_ecc_record, 0,
        sizeof(env->top.l1_ecc_record));
    env->top.l1_ecc_record.valid = 1u;
    env->top.l1_ecc_record.status =
        NPU_STATUS_L1_ECC_UNCORRECTABLE;
    env->top.l1_ecc_record.addr = UINT64_C(0x880);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(env->top.lsc.fault_valid != 0u);
    TEST_CHECK(env->top.lsc.fault_source ==
               NPU_LSC_FAULT_SOURCE_L1_ECC);
    TEST_CHECK(env->top.lsc.fault_addr == UINT64_C(0x880));
    return 0;
}

static int single_test_complete_mif_clear(
    single_test_env_t *env,
    uint8_t id,
    uint8_t repeat_before_noc)
{
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint8_t old_toggle =
        env->top.mif_error_clear_toggle_core;
    uint8_t new_toggle;
    uint32_t tick;

    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_LSC_REG_FAULT_CLEAR, 1u, id));
    new_toggle = env->top.mif_error_clear_toggle_core;
    TEST_CHECK(new_toggle != old_toggle);
    TEST_CHECK(env->top.mif_error_clear_pending_core != 0u);

    if (repeat_before_noc != 0u) {
        SINGLE_TEST_CALL(single_test_system_write_core_only(
            env, NPU_LSC_REG_FAULT_CLEAR, 1u,
            (uint8_t)(id + 1u)));
        TEST_CHECK(env->top.mif_error_clear_toggle_core ==
                   new_toggle);
        TEST_CHECK(
            env->top.mif_error_clear_pending_core != 0u);
    }

    for (tick = 0u; tick < 3u; tick++) {
        SINGLE_TEST_CALL(single_test_noc_tick(
            env, &noc_outputs));
        if (tick < 2u) {
            TEST_CHECK(env->top.mif_error_clear_seen_noc !=
                       new_toggle);
        }
    }
    TEST_CHECK(env->top.mif_error_clear_seen_noc ==
               new_toggle);
    TEST_CHECK(env->top.mif_error_clear_ack_noc ==
               new_toggle);
    TEST_CHECK(env->top.mif.first_error_valid == 0u);
    TEST_CHECK(env->top.mif.protocol_error_valid == 0u);
    TEST_CHECK(env->top.mif_diag_source.first_valid == 0u);
    TEST_CHECK(
        env->top.mif_diag_source.protocol_valid == 0u);

    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(env->top.mif_error_clear_pending_core != 0u);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(env->top.mif_error_clear_pending_core == 0u);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(env->top.lsc.fault_valid == 0u);
    TEST_CHECK(env->top.mif_diag_sync1.first_valid == 0u);
    TEST_CHECK(
        env->top.mif_diag_sync1.protocol_valid == 0u);
    return 0;
}

static int single_test_external_error_sync(
    single_test_env_t *env)
{
    const uint16_t task_id = UINT16_C(0x345);
    const uint64_t vaddr = UINT64_C(0x0000000012340);
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    npu_single_core_mif_diag_t source_snapshot;
    uint32_t expected_info;

    TEST_CHECK(npu_mif_cycle_is_idle(&env->top.mif) != 0u);
    env->top.mif.first_error_valid = 1u;
    env->top.mif.first_error_status =
        NPU_STATUS_BUS_SLVERR;
    env->top.mif.first_error_owner = NPU_MIF_OWNER_DMA;
    env->top.mif.first_error_tag = 0x62au;
    env->top.mif.first_error_task_id = task_id;
    env->top.mif.first_error_vaddr = vaddr;
    env->top.mif.first_error_paddr =
        UINT64_C(0x0000000022340);
    env->top.mif.first_error_axi_id = 0x2du;
    env->top.mif.first_error_axi_id_valid = 1u;
    env->top.mif.first_error_axi_resp =
        NPU_MIF_AXI_RESP_DECERR;
    SINGLE_TEST_CALL(single_test_noc_tick(
        env, &noc_outputs));
    TEST_CHECK(env->top.mif_diag_source.first_valid != 0u);
    source_snapshot = env->top.mif_diag_source;

    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(env->top.mif_diag_sync0.first_valid != 0u);
    TEST_CHECK(env->top.mif_diag_sync1.first_valid == 0u);
    TEST_CHECK(env->top.lsc.fault_valid == 0u);
    TEST_CHECK(memcmp(
                   &env->top.mif_diag_source,
                   &source_snapshot,
                   sizeof(source_snapshot)) == 0);

    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(env->top.mif_diag_sync1.first_valid != 0u);
    TEST_CHECK(env->top.lsc.fault_valid == 0u);
    TEST_CHECK(memcmp(
                   &env->top.mif_diag_source,
                   &source_snapshot,
                   sizeof(source_snapshot)) == 0);

    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    expected_info = single_test_external_error_info(
        NPU_LSC_FAULT_SOURCE_MIF_FIRST,
        NPU_MIF_OWNER_DMA, NPU_MIF_AXI_RESP_DECERR,
        NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(env->top.lsc.fault_valid != 0u);
    TEST_CHECK(env->top.lsc.fault_source ==
               NPU_LSC_FAULT_SOURCE_MIF_FIRST);
    TEST_CHECK(env->top.lsc.fault_status ==
               NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(env->top.lsc.fault_addr == vaddr);
    TEST_CHECK(env->top.lsc.fault_command_id == task_id);
    TEST_CHECK(env->top.lsc.fault_engine == NPU_ENGINE_DMA);
    TEST_CHECK(env->top.lsc.fault_error_info ==
               expected_info);

    env->top.gc_axi.first_error_valid = 1u;
    env->top.gc_axi.first_error_status =
        NPU_STATUS_BUS_DECERR;
    env->top.gc_axi.first_error_client =
        NPU_GC_AXI_CLIENT_DCACHE;
    env->top.gc_axi.first_error_addr =
        UINT64_C(0x0000000008800);
    env->top.gc_axi.first_error_axi_resp =
        NPU_GC_AXI_RESP_SLVERR;
    SINGLE_TEST_CALL(single_test_complete_mif_clear(
        env, 0x41u, 1u));
    TEST_CHECK(env->top.gc_axi.first_error_valid == 0u);

    env->top.mif.protocol_error_valid = 1u;
    env->top.mif.protocol_error_kind =
        NPU_MIF_PROTOCOL_TBU_STATUS;
    env->top.mif.protocol_error_addr =
        UINT64_C(0x0000000034560);
    env->top.mif.protocol_error_owner = NPU_MIF_OWNER_DFU;
    env->top.mif.protocol_error_tag = 0x177u;
    env->top.mif.protocol_error_has_task_identity = 1u;
    env->top.mif.protocol_error_task_id = 0x246u;
    SINGLE_TEST_CALL(single_test_noc_tick(
        env, &noc_outputs));
    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(env->top.lsc.fault_valid == 0u);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    expected_info = single_test_external_error_info(
        NPU_LSC_FAULT_SOURCE_MIF_PROTOCOL,
        NPU_MIF_PROTOCOL_TBU_STATUS,
        NPU_MIF_OWNER_DFU, NPU_STATUS_BAD_DESC);
    TEST_CHECK(env->top.lsc.fault_source ==
               NPU_LSC_FAULT_SOURCE_MIF_PROTOCOL);
    TEST_CHECK(env->top.lsc.fault_error_info ==
               expected_info);
    TEST_CHECK(env->top.lsc.fault_addr ==
               UINT64_C(0x0000000034560));
    TEST_CHECK(env->top.lsc.fault_command_id == 0x246u);
    TEST_CHECK(env->top.lsc.fault_engine ==
               NPU_ENGINE_CONTROL);
    TEST_CHECK(env->top.lsc.fault_opcode == 0u);
    SINGLE_TEST_CALL(single_test_complete_mif_clear(
        env, 0x43u, 0u));

    env->top.gc_axi.first_error_valid = 1u;
    env->top.gc_axi.first_error_status =
        NPU_STATUS_BUS_DECERR;
    env->top.gc_axi.first_error_client =
        NPU_GC_AXI_CLIENT_DCACHE;
    env->top.gc_axi.first_error_tag = 0x2e1u;
    env->top.gc_axi.first_error_addr =
        UINT64_C(0x0000000009900);
    env->top.gc_axi.first_error_axi_id = 0x39u;
    env->top.gc_axi.first_error_axi_id_valid = 1u;
    env->top.gc_axi.first_error_axi_resp =
        NPU_GC_AXI_RESP_SLVERR;
    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    expected_info = single_test_external_error_info(
        NPU_LSC_FAULT_SOURCE_GC_AXI_FIRST,
        NPU_GC_AXI_CLIENT_DCACHE, NPU_GC_AXI_RESP_SLVERR,
        NPU_STATUS_BUS_DECERR);
    TEST_CHECK(env->top.lsc.fault_source ==
               NPU_LSC_FAULT_SOURCE_GC_AXI_FIRST);
    TEST_CHECK(env->top.lsc.fault_addr ==
               UINT64_C(0x0000000009900));
    TEST_CHECK(env->top.lsc.fault_error_info ==
               expected_info);
    SINGLE_TEST_CALL(single_test_complete_mif_clear(
        env, 0x44u, 0u));
    TEST_CHECK(env->top.gc_axi.first_error_valid == 0u);

    env->top.gc_axi.protocol_error_valid = 1u;
    env->top.gc_axi.protocol_error_kind =
        NPU_GC_AXI_PROTOCOL_RLAST;
    env->top.gc_axi.protocol_error_addr =
        UINT64_C(0x000000000aa00);
    env->top.gc_axi.protocol_error_client =
        NPU_GC_AXI_CLIENT_ICACHE;
    env->top.gc_axi.protocol_error_tag = 0x315u;
    env->top.gc_axi.protocol_error_axi_id = 0x27u;
    env->top.gc_axi.protocol_error_axi_id_valid = 1u;
    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    expected_info = single_test_external_error_info(
        NPU_LSC_FAULT_SOURCE_GC_AXI_PROTOCOL,
        NPU_GC_AXI_PROTOCOL_RLAST,
        NPU_GC_AXI_CLIENT_ICACHE, NPU_STATUS_BAD_DESC);
    TEST_CHECK(env->top.lsc.fault_source ==
               NPU_LSC_FAULT_SOURCE_GC_AXI_PROTOCOL);
    TEST_CHECK(env->top.lsc.fault_addr ==
               UINT64_C(0x000000000aa00));
    TEST_CHECK(env->top.lsc.fault_error_info ==
               expected_info);
    return 0;
}

static int single_test_local_error_records(
    single_test_env_t *env)
{
    const uint16_t task_id = UINT16_C(0x2ab);
    const uint32_t ecc_addr = UINT32_C(0x00000128);
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    uint32_t expected_info;

    env->top.engine[NPU_TS_PORT_VECTOR].engine.task_id =
        task_id;
    env->top.engine[NPU_TS_PORT_VECTOR].engine.opcode =
        NPU_VECTOR_MUL;
    env->top.l1.ecc_error_valid = 1u;
    env->top.l1.ecc_error_status =
        NPU_L1_STATUS_ECC_UNCORRECTABLE;
    env->top.l1.ecc_error_addr = ecc_addr;
    env->top.l1.ecc_error_port = NPU_L1_RD_IVE_SRC1;
    env->top.l1.ecc_error_bank = 5u;
    env->top.l1.ecc_error_write = 0u;

    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    expected_info = single_test_external_error_info(
        NPU_LSC_FAULT_SOURCE_L1_ECC,
        NPU_L1_RD_IVE_SRC1, 10u,
        NPU_STATUS_L1_ECC_UNCORRECTABLE);
    TEST_CHECK(env->top.l1_ecc_record.valid != 0u);
    TEST_CHECK(env->top.l1_ecc_record.addr == ecc_addr);
    TEST_CHECK(env->top.l1_ecc_record.detail ==
               NPU_L1_RD_IVE_SRC1);
    TEST_CHECK(env->top.l1_ecc_record.aux == 10u);
    TEST_CHECK(
        env->top.l1_ecc_record.has_task_identity != 0u);
    TEST_CHECK(env->top.l1_ecc_record.command_id == task_id);
    TEST_CHECK(env->top.l1_ecc_record.engine ==
               NPU_ENGINE_VECTOR);
    TEST_CHECK(env->top.l1_ecc_record.opcode ==
               NPU_VECTOR_MUL);
    TEST_CHECK(env->top.lsc.fault_valid != 0u);
    TEST_CHECK(env->top.lsc.fault_source ==
               NPU_LSC_FAULT_SOURCE_L1_ECC);
    TEST_CHECK(env->top.lsc.fault_status ==
               NPU_STATUS_L1_ECC_UNCORRECTABLE);
    TEST_CHECK(env->top.lsc.fault_command_id == task_id);
    TEST_CHECK(env->top.lsc.fault_addr == ecc_addr);
    TEST_CHECK(env->top.lsc.fault_engine ==
               NPU_ENGINE_VECTOR);
    TEST_CHECK(env->top.lsc.fault_opcode == NPU_VECTOR_MUL);
    TEST_CHECK(env->top.lsc.fault_error_info ==
               expected_info);

    env->top.l1.ecc_error_addr = UINT32_C(0x00000200);
    env->top.l1.ecc_error_port = NPU_L1_RD_DMA;
    env->top.engine[NPU_TS_PORT_VECTOR].engine.task_id = 1u;
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(env->top.l1_ecc_record.addr == ecc_addr);
    TEST_CHECK(env->top.l1_ecc_record.command_id == task_id);
    TEST_CHECK(env->top.lsc.fault_addr == ecc_addr);
    TEST_CHECK(env->top.lsc.fault_error_info ==
               expected_info);

    SINGLE_TEST_CALL(single_test_complete_mif_clear(
        env, 0x45u, 0u));
    TEST_CHECK(env->top.l1.ecc_error_valid == 0u);
    TEST_CHECK(env->top.l1_ecc_record.valid == 0u);

    env->top.l1_diag.error_valid = 1u;
    env->top.l1_diag.error_status = NPU_STATUS_ADDR_FAULT;
    env->top.l1_diag.error_addr = UINT32_C(0x00000340);
    env->top.l1_diag.error_detail = NPU_L1_STATUS_ADDR_FAULT;
    env->top.l1_diag.error_write = 1u;
    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    expected_info = single_test_external_error_info(
        NPU_LSC_FAULT_SOURCE_SYS_L1_DIAG,
        NPU_L1_STATUS_ADDR_FAULT, 1u,
        NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(env->top.lsc.fault_valid != 0u);
    TEST_CHECK(env->top.lsc.fault_source ==
               NPU_LSC_FAULT_SOURCE_SYS_L1_DIAG);
    TEST_CHECK(env->top.lsc.fault_status ==
               NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(env->top.lsc.fault_addr ==
               UINT32_C(0x00000340));
    TEST_CHECK(env->top.lsc.fault_command_id == 0x0fffu);
    TEST_CHECK(env->top.lsc.fault_error_info ==
               expected_info);

    SINGLE_TEST_CALL(single_test_complete_mif_clear(
        env, 0x46u, 0u));
    TEST_CHECK(env->top.l1_diag.error_valid == 0u);
    TEST_CHECK(env->top.lsc.fault_valid == 0u);
    return 0;
}

static int single_test_l1_bank_stall_perf(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    npu_l1_cycle_read_state_t *matrix =
        &env->top.l1.read_state[NPU_L1_RD_ME_A];
    npu_l1_cycle_read_state_t *dma =
        &env->top.l1.read_state[NPU_L1_RD_DMA];
    uint64_t before = env->top.lsc.perf_counter[7];

    matrix->active = 1u;
    matrix->request_status = NPU_L1_STATUS_OK;
    matrix->tag = 0x121u;
    matrix->total_beats = 1u;
    matrix->issued_beats = 0u;
    matrix->retired_beats = 0u;
    matrix->base_addr = UINT32_C(0x00000000);

    dma->active = 1u;
    dma->request_status = NPU_L1_STATUS_OK;
    dma->tag = 0x122u;
    dma->total_beats = 1u;
    dma->issued_beats = 0u;
    dma->retired_beats = 0u;
    dma->base_addr = UINT32_C(0x00000080);

    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.l1.bank_stall != 0u);
    TEST_CHECK(
        core_outputs.l1.read_bank_stall_mask ==
        (uint16_t)(1u << NPU_L1_RD_DMA));
    TEST_CHECK(
        core_outputs.l1.write_bank_stall_mask == 0u);
    TEST_CHECK(env->top.lsc.perf_counter[7] == before + 1u);

    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.l1.bank_stall == 0u);
    TEST_CHECK(core_outputs.l1.read_bank_stall_mask == 0u);
    TEST_CHECK(env->top.lsc.perf_counter[7] == before + 1u);
    return 0;
}

static int single_test_mif_idle_sync(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    TEST_CHECK(env->top.mif_idle_source_noc != 0u);
    TEST_CHECK(env->top.mif_idle_sync0_core != 0u);
    TEST_CHECK(env->top.mif_idle_sync1_core != 0u);

    /*
     * This intentionally impossible request phase is a white-box marker
     * that keeps MIF non-idle without generating external traffic.
     */
    env->top.mif.requests[0].valid = 1u;
    env->top.mif.requests[0].phase = NPU_MIF_REQ_FREE;
    SINGLE_TEST_CALL(single_test_noc_tick_mask(
        env,
        (uint8_t)(NPU_SINGLE_CORE_CLK_ALL &
                  ~(uint8_t)(1u <<
                      NPU_SINGLE_CORE_CLK_MIF)),
        &noc_outputs));
    TEST_CHECK(env->top.mif_idle_source_noc == 0u);
    TEST_CHECK(single_test_clock_active(
                   noc_outputs.module_clk_active_o,
                   NPU_SINGLE_CORE_CLK_MIF) != 0u);

    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(env->top.mif_idle_sync0_core == 0u);
    TEST_CHECK(env->top.mif_idle_sync1_core != 0u);
    TEST_CHECK(core_outputs.core_idle_o != 0u);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(env->top.mif_idle_sync1_core == 0u);
    TEST_CHECK(core_outputs.core_idle_o != 0u);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.core_idle_o == 0u);

    env->top.mif.requests[0].valid = 0u;
    SINGLE_TEST_CALL(single_test_noc_tick_mask(
        env,
        (uint8_t)(NPU_SINGLE_CORE_CLK_ALL &
                  ~(uint8_t)(1u <<
                      NPU_SINGLE_CORE_CLK_MIF)),
        &noc_outputs));
    TEST_CHECK(env->top.mif_idle_source_noc != 0u);
    TEST_CHECK(single_test_clock_active(
                   noc_outputs.module_clk_active_o,
                   NPU_SINGLE_CORE_CLK_MIF) == 0u);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(env->top.mif_idle_sync1_core == 0u);
    TEST_CHECK(core_outputs.core_idle_o == 0u);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(env->top.mif_idle_sync1_core != 0u);
    TEST_CHECK(core_outputs.core_idle_o == 0u);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.core_idle_o != 0u);
    return 0;
}

static int single_test_cdc_local_idle(
    single_test_env_t *env)
{
    npu_mif_cdc_fifo_control_t *control =
        &env->top.cdc.req_fifo[NPU_MIF_OWNER_DFU].control;
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    control->write_seq = 1u;
    control->read_seq = 1u;
    control->read_seq_at_writer[0] = 0u;
    control->read_seq_at_writer[1] = 0u;
    TEST_CHECK(npu_mif_cdc_req_level(
                   &env->top.cdc,
                   NPU_MIF_OWNER_DFU) == 0u);

    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(control->read_seq_at_writer[1] == 0u);
    TEST_CHECK(core_outputs.core_idle_o == 0u);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(control->read_seq_at_writer[1] == 1u);
    TEST_CHECK(core_outputs.core_idle_o != 0u);
    return 0;
}

static int single_test_soft_reset_cross_domain(
    single_test_env_t *env)
{
    const uint64_t ddr_limit = UINT64_C(0x0000000007fff8);
    const uint64_t tbu_ids = UINT64_C(0x24681357);
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint8_t old_toggle;
    uint8_t pulse_seen = 0u;
    uint8_t saved_fault_source;
    uint8_t saved_fault_status;
    uint16_t saved_fault_command;
    uint64_t saved_fault_addr;
    uint32_t saved_fault_info;
    uint32_t tick;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_LSC_REG_DDR_LOCAL_LIMIT,
        ddr_limit, 0x51u));
    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_LSC_REG_TBU_STREAM_ID,
        tbu_ids, 0x52u));

    env->top.mif.first_error_valid = 1u;
    env->top.mif.first_error_status =
        NPU_STATUS_BUS_DECERR;
    env->top.mif.first_error_owner = NPU_MIF_OWNER_DMA;
    env->top.mif.first_error_tag = 0x4a1u;
    env->top.mif.first_error_task_id = 0x5a1u;
    env->top.mif.first_error_vaddr =
        UINT64_C(0x0000000004560);
    env->top.mif.first_error_axi_resp =
        NPU_MIF_AXI_RESP_DECERR;
    SINGLE_TEST_CALL(single_test_noc_tick(
        env, &noc_outputs));
    single_test_core_inputs(env, &core_inputs);
    for (tick = 0u; tick < 3u; tick++) {
        single_test_core_tick(
            env, &core_inputs, &core_outputs);
    }
    TEST_CHECK(env->top.lsc.fault_valid != 0u);
    saved_fault_source = env->top.lsc.fault_source;
    saved_fault_status = env->top.lsc.fault_status;
    saved_fault_command = env->top.lsc.fault_command_id;
    saved_fault_addr = env->top.lsc.fault_addr;
    saved_fault_info = env->top.lsc.fault_error_info;

    TEST_CHECK(npu_mif_cycle_is_idle(&env->top.mif) != 0u);
    env->top.mif.next_axi_id = 0x5au;
    env->top.mif.request_rr_owner = 1u;
    env->top.mif.schedule_rr = 7u;
    env->top.mif.r_entry_rr_port = 1u;
    env->top.mif.tbu_hold.tag = 0x4a2u;
    env->top.mif.rsp_hold[0].tag = 0x4a3u;
    env->top.mif.w_hold.out_slot = 3u;
    env->top.mif.b_entry[0].id = 0x2au;
    env->top.mif.r_entry[0].id = 0x2bu;
    env->top.wdt.count = 7u;
    env->top.wdt.timeout = 0u;
    old_toggle = env->top.mif_soft_reset_toggle_core;

    for (tick = 0u; tick < 16u; tick++) {
        single_test_core_inputs(env, &core_inputs);
        core_inputs.soft_reset_req_i = 1u;
        core_inputs.wdt_enable_i = 1u;
        core_inputs.wdt_timeout_cycles_i = 1000u;
        single_test_core_tick(
            env, &core_inputs, &core_outputs);
        if (core_outputs.lsc.internal_soft_reset_pulse != 0u) {
            pulse_seen = 1u;
            TEST_CHECK(core_outputs.wdt.count == 0u);
            TEST_CHECK(env->top.wdt.count == 0u);
            TEST_CHECK(core_outputs.lsc.soft_reset_done == 0u);
            break;
        }
    }
    TEST_CHECK(pulse_seen != 0u);
    TEST_CHECK(env->top.mif_soft_reset_toggle_core !=
               old_toggle);
    TEST_CHECK(env->top.mif_soft_reset_pending_core != 0u);
    TEST_CHECK(env->top.lsc.fault_valid != 0u);
    TEST_CHECK(env->top.lsc.fault_source == saved_fault_source);
    TEST_CHECK(env->top.lsc.fault_status == saved_fault_status);
    TEST_CHECK(
        env->top.lsc.fault_command_id == saved_fault_command);
    TEST_CHECK(env->top.lsc.fault_addr == saved_fault_addr);
    TEST_CHECK(env->top.lsc.fault_error_info ==
               saved_fault_info);
    TEST_CHECK(env->top.lsc.ddr_local_limit == ddr_limit);
    TEST_CHECK(
        ((uint64_t)env->top.lsc.tbu_substream_id << 16u |
         env->top.lsc.tbu_stream_id) == tbu_ids);

    for (tick = 0u; tick < 3u; tick++) {
        single_test_core_inputs(env, &core_inputs);
        core_inputs.soft_reset_req_i = 1u;
        single_test_core_tick(
            env, &core_inputs, &core_outputs);
        TEST_CHECK(core_outputs.lsc.soft_reset_done == 0u);
        TEST_CHECK(env->top.mif_soft_reset_pending_core != 0u);
    }

    for (tick = 0u; tick < 3u; tick++) {
        SINGLE_TEST_CALL(single_test_noc_tick(
            env, &noc_outputs));
        if (tick < 2u) {
            TEST_CHECK(env->top.mif_soft_reset_seen_noc ==
                       old_toggle);
            TEST_CHECK(env->top.mif.first_error_valid != 0u);
            TEST_CHECK(env->top.mif.next_axi_id == 0x5au);
        }
    }
    TEST_CHECK(env->top.mif_soft_reset_seen_noc ==
               env->top.mif_soft_reset_toggle_core);
    TEST_CHECK(env->top.mif_soft_reset_ack_noc ==
               env->top.mif_soft_reset_toggle_core);
    TEST_CHECK(npu_mif_cycle_is_idle(&env->top.mif) != 0u);
    TEST_CHECK(env->top.mif.first_error_valid == 0u);
    TEST_CHECK(env->top.mif.protocol_error_valid == 0u);
    TEST_CHECK(env->top.mif.next_axi_id == 0u);
    TEST_CHECK(env->top.mif.request_rr_owner == 0u);
    TEST_CHECK(env->top.mif.schedule_rr == 0u);
    TEST_CHECK(env->top.mif.r_entry_rr_port == 0u);
    TEST_CHECK(env->top.mif.tbu_hold.tag == 0u);
    TEST_CHECK(env->top.mif.rsp_hold[0].tag == 0u);
    TEST_CHECK(env->top.mif.w_hold.out_slot == 0u);
    TEST_CHECK(env->top.mif.b_entry[0].id == 0u);
    TEST_CHECK(env->top.mif.r_entry[0].id == 0u);
    TEST_CHECK(env->top.mif.config.ddr_limit == ddr_limit);
    TEST_CHECK(
        ((uint64_t)env->top.mif.config.tbu_substream_id << 16u |
         env->top.mif.config.tbu_stream_id) == tbu_ids);
    TEST_CHECK(env->top.mif_diag_source.first_valid == 0u);

    for (tick = 0u; tick < 8u; tick++) {
        single_test_core_inputs(env, &core_inputs);
        core_inputs.soft_reset_req_i = 1u;
        single_test_core_tick(
            env, &core_inputs, &core_outputs);
        if (core_outputs.lsc.soft_reset_done != 0u) {
            break;
        }
    }
    TEST_CHECK(core_outputs.lsc.soft_reset_done != 0u);
    TEST_CHECK(env->top.mif_soft_reset_pending_core == 0u);
    TEST_CHECK(env->top.mif_diag_sync1.first_valid == 0u);
    TEST_CHECK(env->top.lsc.soft_state == NPU_LSC_SOFT_ACK);
    single_test_core_inputs(env, &core_inputs);
    core_inputs.soft_reset_req_i = 1u;
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.lsc.soft_reset_done != 0u);
    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.lsc.soft_reset_done == 0u);
    TEST_CHECK(env->top.lsc.soft_state == NPU_LSC_SOFT_IDLE);
    TEST_CHECK((env->top.lsc.reset_reason &
                NPU_LSC_RESET_SOFTWARE) != 0u);
    TEST_CHECK(env->top.lsc.fault_valid != 0u);
    TEST_CHECK(env->top.lsc.fault_source == saved_fault_source);
    TEST_CHECK(env->top.lsc.fault_status == saved_fault_status);
    TEST_CHECK(
        env->top.lsc.fault_command_id == saved_fault_command);
    TEST_CHECK(env->top.lsc.fault_addr == saved_fault_addr);
    TEST_CHECK(env->top.lsc.fault_error_info ==
               saved_fault_info);
    TEST_CHECK(env->top.lsc.ddr_local_limit == ddr_limit);
    TEST_CHECK(
        ((uint64_t)env->top.lsc.tbu_substream_id << 16u |
         env->top.lsc.tbu_stream_id) == tbu_ids);
    return 0;
}

static void single_test_insert_dma_response(
    single_test_env_t *env,
    uint64_t data,
    uint16_t tag,
    uint8_t is_write,
    uint8_t last)
{
    npu_mif_cdc_rsp_fifo_t *fifo =
        &env->top.cdc.rsp_fifo[NPU_MIF_OWNER_DMA];

    (void)memset(fifo, 0, sizeof(*fifo));
    fifo->entry[0].data = data;
    fifo->entry[0].tag = tag;
    fifo->entry[0].is_write = is_write;
    fifo->entry[0].last = last;
    fifo->entry[0].status = NPU_STATUS_SUCCESS;
    fifo->entry[0].owner = NPU_MIF_OWNER_DMA;
    fifo->control.write_seq = 1u;
    fifo->control.write_seq_at_reader[0] = 1u;
    fifo->control.write_seq_at_reader[1] = 1u;
}

static int single_test_prepare_dma_trace(
    npu_engine_data_cycle_t *dma)
{
    TEST_CHECK(npu_bus_trace_begin(
                   &dma->trace,
                   dma->workspace.read_entries,
                   dma->workspace.read_capacity,
                   dma->workspace.read_hash,
                   dma->workspace.read_hash_slots,
                   dma->workspace.write_entries,
                   dma->workspace.write_capacity,
                   dma->workspace.write_hash,
                   dma->workspace.write_hash_slots,
                   NPU_ENGINE_DATA_READ_PORTS,
                   (npu_bus_trace_port_fn)0,
                   (const void *)0) != 0);
    npu_bus_trace_end(&dma->trace);
    return 0;
}

static int single_test_dma_read_perf_bytes(
    single_test_env_t *env)
{
    npu_engine_data_cycle_t *dma = &env->top.engine[0];
    npu_bus_trace_t *trace = &dma->trace;
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    uint64_t before;
    const uint16_t tag = 0x321u;

    SINGLE_TEST_CALL(single_test_prepare_dma_trace(dma));
    trace->read_count = 2u;
    trace->write_count = 0u;
    trace->read_pass_count = 1u;
    trace->active = 0u;
    trace->overflow = 0u;
    trace->read[0].addr = UINT64_C(0x0000000001000);
    trace->read[0].data = UINT64_C(0x8877665544332211);
    trace->read[0].strb = 0xffu;
    trace->read[0].space = NPU_SPACE_DDR;
    trace->read[0].read_pass = 0u;
    trace->read[1].addr = UINT64_C(0x0000000001008);
    trace->read[1].data = UINT64_C(0x000000ccbbaa9988);
    trace->read[1].strb = 0x1fu;
    trace->read[1].space = NPU_SPACE_DDR;
    trace->read[1].read_pass = 0u;

    npu_bus_replay_cycle_reset(&dma->replay);
    dma->replay.trace = trace;
    dma->replay.state = NPU_BUS_REPLAY_READ_RESPONSE;
    dma->replay.functional_status = NPU_STATUS_SUCCESS;
    dma->replay.read_pass_end = 2u;
    dma->replay.mif_read_lane.state =
        NPU_BUS_REPLAY_LANE_RESPONSE;
    dma->replay.mif_read_lane.group_first_index = 0u;
    dma->replay.mif_read_lane.group_last_index = 1u;
    dma->replay.mif_read_lane.entry_index = 1u;
    dma->replay.mif_read_lane.beats = 2u;
    dma->replay.mif_read_lane.response_beat = 1u;
    dma->replay.mif_read_lane.tag = tag;
    dma->data_pending = 1u;
    single_test_insert_dma_response(
        env, trace->read[1].data, tag, 0u, 1u);
    TEST_CHECK(npu_mif_cdc_rsp_level(
                   &env->top.cdc,
                   NPU_MIF_OWNER_DMA) == 1u);

    before = env->top.lsc.perf_counter[4];
    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.engine[0].mif.rsp_ready != 0u);
    TEST_CHECK(
        core_outputs.cdc.owner[NPU_MIF_OWNER_DMA]
            .rsp_valid != 0u);
    TEST_CHECK(core_outputs.progress_pulse_o != 0u);
    TEST_CHECK(env->top.lsc.perf_counter[4] ==
               before + 5u);
    return 0;
}

static int single_test_dma_write_perf_bytes(
    single_test_env_t *env)
{
    npu_engine_data_cycle_t *dma = &env->top.engine[0];
    npu_bus_trace_t *trace = &dma->trace;
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    uint64_t before;
    const uint16_t tag = 0x322u;

    SINGLE_TEST_CALL(single_test_prepare_dma_trace(dma));
    trace->read_count = 0u;
    trace->write_count = 3u;
    trace->active = 0u;
    trace->overflow = 0u;
    trace->write[0].addr = UINT64_C(0x0000000002000);
    trace->write[0].strb = 0xffu;
    trace->write[0].space = NPU_SPACE_DDR;
    trace->write[1].addr = UINT64_C(0x0000000002008);
    trace->write[1].strb = 0x0fu;
    trace->write[1].space = NPU_SPACE_DDR;
    trace->write[2].addr = UINT64_C(0x0000000002010);
    trace->write[2].strb = 0x03u;
    trace->write[2].space = NPU_SPACE_DDR;

    npu_bus_replay_cycle_reset(&dma->replay);
    dma->replay.trace = trace;
    dma->replay.state = NPU_BUS_REPLAY_WRITE_RESPONSE;
    dma->replay.functional_status = NPU_STATUS_SUCCESS;
    dma->replay.write_index = 0u;
    dma->replay.write_group_beats = 3u;
    dma->replay.current_tag = tag;
    dma->replay.write_request_sent = 1u;
    dma->replay.write_data_sent = 1u;
    dma->replay.write_data_beat = 3u;
    dma->data_pending = 1u;
    single_test_insert_dma_response(
        env, 0u, tag, 1u, 1u);
    TEST_CHECK(npu_mif_cdc_rsp_level(
                   &env->top.cdc,
                   NPU_MIF_OWNER_DMA) == 1u);

    before = env->top.lsc.perf_counter[5];
    single_test_core_inputs(env, &core_inputs);
    single_test_core_tick(
        env, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.engine[0].mif.rsp_ready != 0u);
    TEST_CHECK(
        core_outputs.cdc.owner[NPU_MIF_OWNER_DMA]
            .rsp_valid != 0u);
    TEST_CHECK(core_outputs.progress_pulse_o != 0u);
    TEST_CHECK(env->top.lsc.perf_counter[5] ==
               before + 14u);
    return 0;
}

static int single_test_gc_axi_read(single_test_env_t *env)
{
    const uint64_t address = UINT64_C(0x00012340);
    const uint64_t data = UINT64_C(0xfedcba9876543210);
    const uint16_t tag = UINT16_C(0x2a5);
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint8_t id = 0u;
    uint8_t accepted = 0u;
    uint32_t cycle;

    for (cycle = 0u; cycle < 64u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.gc_axi.icache_req.valid = 1u;
        inputs.gc_axi.icache_req.addr = address;
        inputs.gc_axi.icache_req.beats = 0u;
        inputs.gc_axi.icache_req.tag = tag;
        inputs.gc_axi.icache_req.cache = 0xau;
        inputs.gc_axi.icache_req.prot = 4u;
        single_test_core_tick(env, &inputs, &outputs);
        if ((cycle & 1u) == 0u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
        }
        if (outputs.gc_axi.icache_req_ready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    accepted = 0u;
    for (cycle = 0u; cycle < 64u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.gc_axi.axi.arready =
            (uint8_t)((cycle % 3u) == 2u);
        single_test_core_tick(env, &inputs, &outputs);
        if (outputs.gc_axi.axi.arvalid != 0u) {
            TEST_CHECK(outputs.gc_axi.axi.araddr == address);
            TEST_CHECK(outputs.gc_axi.axi.arlen == 0u);
            TEST_CHECK(outputs.gc_axi.axi.arsize == 3u);
            TEST_CHECK(outputs.gc_axi.axi.arcache == 0xau);
            TEST_CHECK(outputs.gc_axi.axi.arprot == 4u);
            TEST_CHECK(outputs.gc_axi.axi.arqos == 0u);
            id = outputs.gc_axi.axi.arid;
            if (inputs.gc_axi.axi.arready != 0u) {
                accepted = 1u;
                break;
            }
        }
    }
    TEST_CHECK(accepted != 0u);

    accepted = 0u;
    for (cycle = 0u; cycle < 16u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.gc_axi.axi.rvalid = 1u;
        inputs.gc_axi.axi.rid = id;
        inputs.gc_axi.axi.rdata = data;
        inputs.gc_axi.axi.rresp = NPU_GC_AXI_RESP_OKAY;
        inputs.gc_axi.axi.rlast = 1u;
        single_test_core_tick(env, &inputs, &outputs);
        if (outputs.gc_axi.axi.rready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    for (cycle = 0u; cycle < 64u; cycle++) {
        single_test_core_inputs(env, &inputs);
        single_test_core_tick(env, &inputs, &outputs);
        if (outputs.gc_axi.icache_rsp.valid != 0u) {
            break;
        }
    }
    TEST_CHECK(outputs.gc_axi.icache_rsp.valid != 0u);
    TEST_CHECK(outputs.gc_axi.icache_rsp.data == data);
    TEST_CHECK(outputs.gc_axi.icache_rsp.tag == tag);
    TEST_CHECK(outputs.gc_axi.icache_rsp.last != 0u);
    TEST_CHECK(outputs.gc_axi.icache_rsp.status ==
               NPU_STATUS_SUCCESS);

    single_test_core_inputs(env, &inputs);
    inputs.gc_axi.icache_rsp_ready = 1u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.gc_axi.icache_rsp.valid != 0u);
    TEST_CHECK(outputs.gc_axi.icache_rsp.data == data);
    return 0;
}

static int single_test_gc_reset_stale_read_wait_rlast(
    single_test_env_t *env)
{
    const uint64_t old_address = UINT64_C(0x00012400);
    const uint64_t new_address = UINT64_C(0x00012500);
    const uint64_t old_data = UINT64_C(0xdeadbeefbad0c0de);
    const uint16_t old_tag = UINT16_C(0x2b1);
    const uint16_t new_tag = UINT16_C(0x2b2);
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint8_t old_id = 0u;
    uint8_t accepted = 0u;
    uint32_t cycle;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x2eu));
    SINGLE_TEST_CALL(single_test_wait_idle(env));

    for (cycle = 0u; cycle < 32u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.gc_axi.icache_req.valid = 1u;
        inputs.gc_axi.icache_req.addr = old_address;
        inputs.gc_axi.icache_req.beats = 0u;
        inputs.gc_axi.icache_req.tag = old_tag;
        inputs.gc_axi.icache_req.cache = 0xau;
        inputs.gc_axi.icache_req.prot = 4u;
        single_test_core_tick(env, &inputs, &outputs);
        if (outputs.gc_axi.icache_req_ready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    accepted = 0u;
    for (cycle = 0u; cycle < 32u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.gc_axi.axi.arready = 1u;
        single_test_core_tick(env, &inputs, &outputs);
        if (outputs.gc_axi.axi.arvalid != 0u) {
            TEST_CHECK(outputs.gc_axi.axi.araddr ==
                       old_address);
            TEST_CHECK(outputs.gc_axi.axi.arlen == 0u);
            old_id = outputs.gc_axi.axi.arid;
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    env->core_rst_ni = 0u;
    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.core_reset_n == 0u);
    TEST_CHECK(
        env->top.stale_gc_axi_read_beats[old_id] == 1u);
    TEST_CHECK(
        env->top.stale_gc_axi_read_wait_rlast[old_id] == 0u);

    env->core_rst_ni = 1u;
    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.core_reset_n == 0u);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.core_reset_n != 0u);
    env->top.lsc.started = 1u;
    env->top.lsc.stopped = 0u;

    single_test_core_inputs(env, &inputs);
    inputs.gc_axi.dcache_read_req.valid = 1u;
    inputs.gc_axi.dcache_read_req.addr = new_address;
    inputs.gc_axi.dcache_read_req.beats = 0u;
    inputs.gc_axi.dcache_read_req.tag = new_tag;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.gc_axi.dcache_read_req_ready == 0u);
    TEST_CHECK(outputs.gc_axi.axi.arvalid == 0u);

    single_test_core_inputs(env, &inputs);
    inputs.dvfs_prepare_req_i = 1u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.core_idle_o == 0u);
    TEST_CHECK(outputs.crg.dvfs_prepare_ack_o == 0u);

    single_test_core_inputs(env, &inputs);
    inputs.gc_axi.dcache_read_req.valid = 1u;
    inputs.gc_axi.dcache_read_req.addr = new_address;
    inputs.gc_axi.dcache_read_req.beats = 0u;
    inputs.gc_axi.dcache_read_req.tag = new_tag;
    inputs.gc_axi.axi.rvalid = 1u;
    inputs.gc_axi.axi.rid = old_id;
    inputs.gc_axi.axi.rdata = old_data;
    inputs.gc_axi.axi.rresp = NPU_GC_AXI_RESP_OKAY;
    inputs.gc_axi.axi.rlast = 0u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.gc_axi.axi.rready != 0u);
    TEST_CHECK(outputs.gc_axi.dcache_read_req_ready == 0u);
    TEST_CHECK(outputs.gc_axi.icache_rsp.valid == 0u);
    TEST_CHECK(outputs.gc_axi.dcache_read_rsp.valid == 0u);
    TEST_CHECK(
        env->top.stale_gc_axi_read_beats[old_id] == 0u);
    TEST_CHECK(
        env->top.stale_gc_axi_read_wait_rlast[old_id] != 0u);
    TEST_CHECK(env->top.stale_gc_axi_read_drop_count == 1u);

    single_test_core_inputs(env, &inputs);
    inputs.dvfs_prepare_req_i = 1u;
    inputs.gc_axi.dcache_read_req.valid = 1u;
    inputs.gc_axi.dcache_read_req.addr = new_address;
    inputs.gc_axi.dcache_read_req.beats = 0u;
    inputs.gc_axi.dcache_read_req.tag = new_tag;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.gc_axi.dcache_read_req_ready == 0u);
    TEST_CHECK(outputs.core_idle_o == 0u);
    TEST_CHECK(outputs.crg.dvfs_prepare_ack_o == 0u);
    TEST_CHECK(
        env->top.stale_gc_axi_read_wait_rlast[old_id] != 0u);

    single_test_core_inputs(env, &inputs);
    inputs.gc_axi.axi.rvalid = 1u;
    inputs.gc_axi.axi.rid = old_id;
    inputs.gc_axi.axi.rdata = old_data + 1u;
    inputs.gc_axi.axi.rresp = NPU_GC_AXI_RESP_OKAY;
    inputs.gc_axi.axi.rlast = 1u;
    inputs.gc_axi.dcache_read_req.valid = 1u;
    inputs.gc_axi.dcache_read_req.addr = new_address;
    inputs.gc_axi.dcache_read_req.beats = 0u;
    inputs.gc_axi.dcache_read_req.tag = new_tag;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.gc_axi.axi.rready != 0u);
    TEST_CHECK(outputs.gc_axi.dcache_read_req_ready == 0u);
    TEST_CHECK(outputs.gc_axi.icache_rsp.valid == 0u);
    TEST_CHECK(outputs.gc_axi.dcache_read_rsp.valid == 0u);
    TEST_CHECK(
        env->top.stale_gc_axi_read_wait_rlast[old_id] == 0u);
    TEST_CHECK(env->top.stale_gc_axi_read_drop_count == 2u);

    single_test_core_inputs(env, &inputs);
    inputs.dvfs_prepare_req_i = 1u;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.core_idle_o != 0u);
    TEST_CHECK(outputs.crg.dvfs_prepare_ack_o != 0u);

    single_test_core_inputs(env, &inputs);
    inputs.gc_axi.dcache_read_req.valid = 1u;
    inputs.gc_axi.dcache_read_req.addr = new_address;
    inputs.gc_axi.dcache_read_req.beats = 0u;
    inputs.gc_axi.dcache_read_req.tag = new_tag;
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.gc_axi.dcache_read_req_ready != 0u);
    return 0;
}

static int single_test_gc_reset_stale_write_drain(
    single_test_env_t *env)
{
    const uint64_t address[2] = {
        UINT64_C(0x00012600),
        UINT64_C(0x00012700)
    };
    const uint16_t tag[2] = {
        UINT16_C(0x2c1),
        UINT16_C(0x2c2)
    };
    const uint8_t beats[2] = {2u, 1u};
    const uint8_t expected_wlast[5] = {
        0u, 0u, 1u, 0u, 1u
    };
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    uint8_t aw_id[2] = {0u, 0u};
    uint8_t request_count = 0u;
    uint8_t aw_count = 0u;
    uint32_t cycle;
    uint32_t beat;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write_core_only(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x2fu));
    SINGLE_TEST_CALL(single_test_wait_idle(env));

    for (cycle = 0u;
         cycle < 64u && aw_count < 2u;
         cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.gc_axi.axi.awready = 1u;
        if (request_count < 2u) {
            inputs.gc_axi.dcache_write_req.valid = 1u;
            inputs.gc_axi.dcache_write_req.addr =
                address[request_count];
            inputs.gc_axi.dcache_write_req.beats =
                beats[request_count];
            inputs.gc_axi.dcache_write_req.tag =
                tag[request_count];
            inputs.gc_axi.dcache_write_req.cache = 0xau;
            inputs.gc_axi.dcache_write_req.prot = 1u;
        }
        single_test_core_tick(env, &inputs, &outputs);
        if (inputs.gc_axi.dcache_write_req.valid != 0u &&
            outputs.gc_axi.dcache_write_req_ready != 0u) {
            request_count++;
        }
        if (outputs.gc_axi.axi.awvalid != 0u) {
            TEST_CHECK(outputs.gc_axi.axi.awaddr ==
                       address[aw_count]);
            TEST_CHECK(outputs.gc_axi.axi.awlen ==
                       beats[aw_count]);
            TEST_CHECK(outputs.gc_axi.axi.awsize == 3u);
            aw_id[aw_count] = outputs.gc_axi.axi.awid;
            aw_count++;
        }
    }
    TEST_CHECK(request_count == 2u);
    TEST_CHECK(aw_count == 2u);
    TEST_CHECK(aw_id[0] != aw_id[1]);
    TEST_CHECK(env->top.gc_axi.write_order_count == 2u);

    env->core_rst_ni = 0u;
    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.core_reset_n == 0u);
    TEST_CHECK(
        env->top.stale_gc_axi_write_pending[aw_id[0]] != 0u);
    TEST_CHECK(
        env->top.stale_gc_axi_write_pending[aw_id[1]] != 0u);
    TEST_CHECK(
        env->top.stale_gc_axi_write_drain_count == 2u);
    TEST_CHECK(
        env->top.stale_gc_axi_write_drain[0].axi_id ==
        aw_id[0]);
    TEST_CHECK(
        env->top.stale_gc_axi_write_drain[0].beats_remaining ==
        3u);
    TEST_CHECK(
        env->top.stale_gc_axi_write_drain[1].axi_id ==
        aw_id[1]);
    TEST_CHECK(
        env->top.stale_gc_axi_write_drain[1].beats_remaining ==
        2u);

    env->core_rst_ni = 1u;
    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.core_reset_n == 0u);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.core_reset_n != 0u);
    env->top.lsc.started = 1u;
    env->top.lsc.stopped = 0u;

    for (beat = 0u; beat < 5u; beat++) {
        single_test_core_inputs(env, &inputs);
        inputs.gc_axi.axi.wready = 1u;
        inputs.gc_axi.dcache_write_req.valid = 1u;
        inputs.gc_axi.dcache_write_req.addr =
            UINT64_C(0x00012800);
        inputs.gc_axi.dcache_write_req.beats = 0u;
        inputs.gc_axi.dcache_write_req.tag =
            UINT16_C(0x2c3);
        single_test_core_tick(env, &inputs, &outputs);
        TEST_CHECK(outputs.gc_axi.dcache_write_req_ready == 0u);
        TEST_CHECK(outputs.gc_axi.axi.wvalid != 0u);
        TEST_CHECK(outputs.gc_axi.axi.wdata == 0u);
        TEST_CHECK(outputs.gc_axi.axi.wstrb == 0u);
        TEST_CHECK(outputs.gc_axi.axi.wlast ==
                   expected_wlast[beat]);
    }
    TEST_CHECK(
        env->top.stale_gc_axi_write_drain_count == 0u);
    TEST_CHECK(env->top.stale_gc_axi_w_drain_count == 5u);

    single_test_core_inputs(env, &inputs);
    inputs.gc_axi.dcache_write_req.valid = 1u;
    inputs.gc_axi.dcache_write_req.addr =
        UINT64_C(0x00012800);
    inputs.gc_axi.dcache_write_req.beats = 0u;
    inputs.gc_axi.dcache_write_req.tag =
        UINT16_C(0x2c3);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.gc_axi.dcache_write_req_ready == 0u);

    single_test_core_inputs(env, &inputs);
    inputs.gc_axi.axi.bvalid = 1u;
    inputs.gc_axi.axi.bid = aw_id[0];
    inputs.gc_axi.axi.bresp = NPU_GC_AXI_RESP_OKAY;
    inputs.gc_axi.dcache_write_req.valid = 1u;
    inputs.gc_axi.dcache_write_req.addr =
        UINT64_C(0x00012800);
    inputs.gc_axi.dcache_write_req.beats = 0u;
    inputs.gc_axi.dcache_write_req.tag =
        UINT16_C(0x2c3);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.gc_axi.axi.bready != 0u);
    TEST_CHECK(outputs.gc_axi.dcache_write_req_ready == 0u);
    TEST_CHECK(outputs.gc_axi.dcache_write_rsp.valid == 0u);
    TEST_CHECK(
        env->top.stale_gc_axi_write_pending[aw_id[0]] == 0u);
    TEST_CHECK(
        env->top.stale_gc_axi_write_pending[aw_id[1]] != 0u);

    single_test_core_inputs(env, &inputs);
    inputs.gc_axi.axi.bvalid = 1u;
    inputs.gc_axi.axi.bid = aw_id[1];
    inputs.gc_axi.axi.bresp = NPU_GC_AXI_RESP_OKAY;
    inputs.gc_axi.dcache_write_req.valid = 1u;
    inputs.gc_axi.dcache_write_req.addr =
        UINT64_C(0x00012800);
    inputs.gc_axi.dcache_write_req.beats = 0u;
    inputs.gc_axi.dcache_write_req.tag =
        UINT16_C(0x2c3);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.gc_axi.axi.bready != 0u);
    TEST_CHECK(outputs.gc_axi.dcache_write_req_ready == 0u);
    TEST_CHECK(outputs.gc_axi.dcache_write_rsp.valid == 0u);
    TEST_CHECK(
        env->top.stale_gc_axi_write_pending[aw_id[1]] == 0u);
    TEST_CHECK(env->top.stale_gc_axi_write_drop_count == 2u);

    single_test_core_inputs(env, &inputs);
    inputs.gc_axi.dcache_write_req.valid = 1u;
    inputs.gc_axi.dcache_write_req.addr =
        UINT64_C(0x00012800);
    inputs.gc_axi.dcache_write_req.beats = 0u;
    inputs.gc_axi.dcache_write_req.tag =
        UINT16_C(0x2c3);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.gc_axi.dcache_write_req_ready != 0u);
    return 0;
}

static int single_test_issue_submit(
    single_test_env_t *env,
    uint16_t command_id)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint64_t low_beat;
    uint64_t high_beat;
    uint32_t cycle;
    uint8_t accepted = 0u;
    uint8_t response_seen = 0u;

    single_test_make_command(
        command_id, &low_beat, &high_beat);
    for (cycle = 0u; cycle < 64u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.issue_valid_i = 1u;
        inputs.issue_opcode_i = NPU_ISSUE_CUSTOM0_OPCODE;
        inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_SUBMIT;
        inputs.issue_funct7_i = 0u;
        inputs.issue_rs1_i = low_beat;
        inputs.issue_rs2_i = high_beat;
        inputs.issue_rd_i = 9u;
        single_test_core_tick(env, &inputs, &outputs);
        if ((cycle % 3u) != 1u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
        }
        if (outputs.issue.issue_ready_o != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    for (cycle = 0u; cycle < 128u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.issue_rsp_ready_i = response_seen;
        single_test_core_tick(env, &inputs, &outputs);
        if ((cycle % 3u) != 1u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
        }
        if (outputs.issue.issue_rsp_valid_o != 0u) {
            TEST_CHECK(outputs.issue.issue_rsp_exception_o == 0u);
            TEST_CHECK(outputs.issue.issue_rsp_rd_o == 9u);
            TEST_CHECK(
                ((outputs.issue.issue_rsp_data_o >> 12u) &
                 0xffu) == NPU_STATUS_SUCCESS);
            if (response_seen != 0u) {
                return 0;
            }
            response_seen = 1u;
        }
    }
    return __LINE__;
}

static int single_test_start_descriptor_task(
    single_test_env_t *env,
    uint16_t command_id)
{
    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_LSC_REG_DDR_LOCAL_LIMIT,
        UINT64_C(0x00000000000ffff8), 0x61u));
    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_LSC_REG_TBU_STREAM_ID,
        UINT64_C(0x56781234), 0x62u));
    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x63u));
    SINGLE_TEST_CALL(single_test_issue_submit(
        env, command_id));
    return 0;
}

static int single_test_issue_engine(
    single_test_env_t *env,
    uint16_t command_id,
    npu_engine_t engine,
    uint8_t opcode)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint64_t low_beat;
    uint64_t high_beat;
    uint32_t cycle;
    uint8_t accepted = 0u;
    uint8_t response_seen = 0u;

    single_test_make_engine_command(
        command_id, engine, opcode, &low_beat,
        &high_beat);
    for (cycle = 0u; cycle < 64u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.issue_valid_i = 1u;
        inputs.issue_opcode_i = NPU_ISSUE_CUSTOM0_OPCODE;
        inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_SUBMIT;
        inputs.issue_rs1_i = low_beat;
        inputs.issue_rs2_i = high_beat;
        inputs.issue_rd_i = 11u;
        single_test_core_tick(env, &inputs, &outputs);
        if ((cycle & 1u) == 0u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
        }
        if (outputs.issue.issue_ready_o != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    for (cycle = 0u; cycle < 128u; cycle++) {
        single_test_core_inputs(env, &inputs);
        inputs.issue_rsp_ready_i = response_seen;
        single_test_core_tick(env, &inputs, &outputs);
        if ((cycle & 1u) == 0u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
        }
        if (outputs.issue.issue_rsp_valid_o != 0u) {
            TEST_CHECK(
                outputs.issue.issue_rsp_exception_o == 0u);
            TEST_CHECK(outputs.issue.issue_rsp_rd_o == 11u);
            TEST_CHECK(
                ((outputs.issue.issue_rsp_data_o >> 12u) &
                 0xffu) == NPU_STATUS_SUCCESS);
            if (response_seen != 0u) {
                return 0;
            }
            response_seen = 1u;
        }
    }
    return __LINE__;
}

static int single_test_start_engine_task(
    single_test_env_t *env,
    uint16_t command_id,
    npu_engine_t engine,
    uint8_t opcode)
{
    SINGLE_TEST_CALL(single_test_wait_idle(env));
    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_LSC_REG_DDR_LOCAL_LIMIT,
        UINT64_C(0x00000000000ffff8), 0x64u));
    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_LSC_REG_TBU_STREAM_ID,
        UINT64_C(0x56781234), 0x65u));
    SINGLE_TEST_CALL(single_test_system_write(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START, 0x66u));
    SINGLE_TEST_CALL(single_test_issue_engine(
        env, command_id, engine, opcode));
    return 0;
}

static int single_test_internal_tbu_permission(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint64_t core_before = env->core_ticks;
    uint64_t noc_before = env->noc_ticks;
    uint8_t terminal_seen = 0u;
    uint32_t cycle;

    SINGLE_TEST_CALL(single_test_start_descriptor_task(
        env, 0x461u));
    for (cycle = 0u; cycle < 2048u; cycle++) {
        single_test_core_inputs(env, &core_inputs);
        core_inputs.issue_rsp_ready_i = 1u;
        single_test_core_tick(
            env, &core_inputs, &core_outputs);
        if ((cycle % 5u) == 0u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
            TEST_CHECK(
                noc_outputs.mif
                    .axi[NPU_MIF_AXI_DDR].arvalid == 0u);
        }
        if (core_outputs.ts.terminal_valid != 0u) {
            TEST_CHECK(core_outputs.ts.terminal_task_id ==
                       0x461u);
            TEST_CHECK(core_outputs.ts.terminal_status !=
                       NPU_STATUS_SUCCESS);
            terminal_seen = 1u;
            break;
        }
    }
    TEST_CHECK(terminal_seen != 0u);
    TEST_CHECK(env->noc_server.axi_reads == 0u);
    TEST_CHECK(env->noc_server.internal_tbu_requests == 1u);
    TEST_CHECK(env->noc_server.internal_tbu_responses == 1u);
    TEST_CHECK(env->top.mif.first_error_status ==
               NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(env->core_ticks - core_before !=
               env->noc_ticks - noc_before);
    return 0;
}

static uint8_t single_test_tbu_ready_slot(
    const npu_tbu_cycle_t *tbu)
{
    uint8_t slot;

    for (slot = 0u; slot < NPU_TBU_OUTSTANDING; slot++) {
        if (tbu->requests[slot].valid != 0u &&
            tbu->requests[slot].remaining_cycles == 0u) {
            return slot;
        }
    }
    return NPU_TBU_INVALID_SLOT;
}

static int single_test_internal_tbu_hold_reset(
    single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t core_inputs;
    npu_single_core_cycle_core_outputs_t core_outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    npu_tbu_cycle_inputs_t tbu_inputs;
    npu_tbu_cycle_outputs_t tbu_outputs;
    npu_tbu_request_entry_t held;
    npu_tbu_rule_t changed_rule;
    uint64_t held_cycle;
    uint32_t old_epoch;
    const npu_ts_task_entry_t *task;
    uint8_t slot = NPU_TBU_INVALID_SLOT;
    uint8_t terminal_seen = 0u;
    uint32_t cycle;

    SINGLE_TEST_CALL(single_test_start_descriptor_task(
        env, 0x462u));
    for (cycle = 0u; cycle < 512u; cycle++) {
        SINGLE_TEST_CALL(single_test_noc_tick_mask(
            env,
            (uint8_t)(NPU_SINGLE_CORE_CLK_ALL &
                      ~(uint8_t)(1u <<
                          NPU_SINGLE_CORE_CLK_MIF)),
            &noc_outputs));
        if (single_test_tbu_ready_slot(&env->top.tbu) !=
                NPU_TBU_INVALID_SLOT ||
            noc_outputs.tbu.outstanding != 0u) {
            TEST_CHECK(single_test_clock_active(
                           noc_outputs.module_clk_active_o,
                           NPU_SINGLE_CORE_CLK_MIF) != 0u);
        }
        slot = single_test_tbu_ready_slot(&env->top.tbu);
        if (slot != NPU_TBU_INVALID_SLOT) {
            break;
        }
        single_test_core_inputs(env, &core_inputs);
        single_test_core_tick(
            env, &core_inputs, &core_outputs);
    }
    TEST_CHECK(slot != NPU_TBU_INVALID_SLOT);
    TEST_CHECK(env->top.mif.tbu_count != 0u);
    TEST_CHECK(env->noc_server.axi_reads == 0u);
    held = env->top.tbu.requests[slot];

    (void)memset(&tbu_inputs, 0, sizeof(tbu_inputs));
    tbu_inputs.reset_n = 1u;
    tbu_inputs.rsp_ready = 0u;
    for (cycle = 0u; cycle < 3u; cycle++) {
        npu_tbu_cycle_step(
            &env->top.tbu, &tbu_inputs, &tbu_outputs);
        TEST_CHECK(tbu_outputs.rsp_valid != 0u);
        TEST_CHECK(tbu_outputs.rsp_tag == held.tag);
        TEST_CHECK(tbu_outputs.rsp_paddr == held.paddr);
        TEST_CHECK(memcmp(
                       &env->top.tbu.requests[slot],
                       &held, sizeof(held)) == 0);
    }
    held_cycle = env->top.tbu.cycle_count;

    changed_rule = env->top.tbu.rules[0];
    changed_rule.physical_page++;
    TEST_CHECK(npu_tbu_cycle_set_rule(
                   &env->top.tbu, 0u,
                   &changed_rule) == 0);
    for (cycle = 0u; cycle < 7u; cycle++) {
        single_test_core_inputs(env, &core_inputs);
        single_test_core_tick(
            env, &core_inputs, &core_outputs);
        TEST_CHECK(env->top.tbu.cycle_count == held_cycle);
        TEST_CHECK(memcmp(
                       &env->top.tbu.requests[slot],
                       &held, sizeof(held)) == 0);
    }

    old_epoch = env->top.cdc.reset_epoch;
    env->noc_rst_ni = 0u;
    SINGLE_TEST_CALL(single_test_noc_tick(
        env, &noc_outputs));
    TEST_CHECK(noc_outputs.noc_reset_n == 0u);
    TEST_CHECK(env->top.cdc.reset_epoch == old_epoch + 1u);
    TEST_CHECK(noc_outputs.tbu.idle != 0u);
    TEST_CHECK(env->top.tbu.rules[0].valid != 0u);
    TEST_CHECK(single_test_tbu_ready_slot(&env->top.tbu) ==
               NPU_TBU_INVALID_SLOT);
    TEST_CHECK(npu_mif_cycle_is_idle(&env->top.mif) != 0u);

    /*
     * Do not advance NoC while Core observes the reset epoch. The active DFU
     * request lost its response when the CDC FIFO and MIF were reset, so TS
     * must produce ABORTED without waiting for another NoC edge.
     */
    for (cycle = 0u; cycle < 16u; cycle++) {
        single_test_core_inputs(env, &core_inputs);
        single_test_core_tick(
            env, &core_inputs, &core_outputs);
        if (core_outputs.ts.terminal_valid != 0u) {
            TEST_CHECK(core_outputs.ts.terminal_task_id ==
                       0x462u);
            TEST_CHECK(core_outputs.ts.terminal_status ==
                       NPU_STATUS_ABORTED);
            TEST_CHECK(core_outputs.ts.terminal_done_flags ==
                       NPU_DONE_ABORT_DRAINED);
            terminal_seen = 1u;
            break;
        }
    }
    TEST_CHECK(terminal_seen != 0u);
    TEST_CHECK(env->top.ts.dfu.valid == 0u);
    task = npu_ts_cycle_find_task(&env->top.ts, 0x462u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_ABORTED);
    TEST_CHECK(task->status == NPU_STATUS_ABORTED);
    TEST_CHECK(task->done_flags == NPU_DONE_ABORT_DRAINED);

    env->noc_rst_ni = 1u;
    SINGLE_TEST_CALL(single_test_noc_tick(
        env, &noc_outputs));
    TEST_CHECK(noc_outputs.noc_reset_n == 0u);
    SINGLE_TEST_CALL(single_test_noc_tick(
        env, &noc_outputs));
    TEST_CHECK(noc_outputs.noc_reset_n != 0u);
    TEST_CHECK(env->top.tbu.rules[0].valid != 0u);
    return 0;
}

static int single_test_matrix_task(single_test_env_t *env)
{
    uint8_t *descriptor =
        &env->ddr[(size_t)SINGLE_TEST_DESC_ADDR];
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    const npu_ts_task_entry_t *task;
    uint32_t cycle;
    uint32_t port;
    uint32_t command_handshakes = 0u;
    uint32_t descriptor_requests = 0u;
    uint32_t l1_read_requests = 0u;
    uint32_t l1_write_requests = 0u;
    uint32_t l1_write_responses = 0u;
    uint32_t mac_active_cycles = 0u;
    uint8_t terminal_seen = 0u;

    single_test_make_matrix_descriptor(descriptor);
    (void)memset(
        &env->l1[SINGLE_TEST_SRC0], 0, 16u);
    (void)memset(
        &env->l1[SINGLE_TEST_SRC1], 0, 32u);
    (void)memset(
        &env->l1[SINGLE_TEST_DST], 0xa5, 8u);
    env->l1[SINGLE_TEST_SRC0] = 2u;
    env->l1[SINGLE_TEST_SRC0 + 1u] = 3u;
    env->l1[SINGLE_TEST_SRC1] = 4u;
    env->l1[SINGLE_TEST_SRC1 + 8u] = 5u;

    SINGLE_TEST_CALL(single_test_start_engine_task(
        env, SINGLE_TEST_MATRIX_COMMAND,
        NPU_ENGINE_MATRIX, NPU_MATRIX_GEMM));
    for (cycle = 0u;
         cycle < SINGLE_TEST_MAX_CYCLES &&
         terminal_seen == 0u;
         cycle++) {
        if ((cycle % 3u) != 1u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
        }
        single_test_core_inputs(env, &inputs);
        inputs.issue_rsp_ready_i = 1u;
        single_test_core_tick(env, &inputs, &outputs);
        if ((cycle % 3u) == 1u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
        }

        if (outputs.ts.engine[NPU_TS_PORT_MATRIX]
                    .req_valid != 0u &&
            outputs.engine[NPU_TS_PORT_MATRIX]
                    .engine.eng_req_ready_o != 0u) {
            command_handshakes++;
        }
        if (outputs.engine[NPU_TS_PORT_MATRIX]
                    .engine.desc_rd_req_valid_o != 0u &&
            outputs.ts.desc[NPU_TS_PORT_MATRIX]
                    .req_ready != 0u) {
            descriptor_requests++;
        }
        for (port = 0u; port < 3u; port++) {
            if (outputs.engine[NPU_TS_PORT_MATRIX]
                        .l1_read[port].req_valid != 0u &&
                outputs.l1.read[NPU_L1_RD_ME_A + port]
                        .req_ready != 0u) {
                l1_read_requests++;
            }
        }
        if (outputs.engine[NPU_TS_PORT_MATRIX]
                    .l1_write.req_valid != 0u &&
            outputs.l1.write[NPU_L1_WR_ME_C]
                    .req_ready != 0u) {
            l1_write_requests++;
        }
        if (outputs.engine[NPU_TS_PORT_MATRIX]
                    .l1_write.rsp_ready != 0u &&
            outputs.l1.write[NPU_L1_WR_ME_C]
                    .rsp_valid != 0u) {
            l1_write_responses++;
        }
        if (outputs.engine[NPU_TS_PORT_MATRIX]
                    .me_mac_active != 0u) {
            mac_active_cycles++;
        }
        if (outputs.ts.terminal_valid != 0u) {
            TEST_CHECK(outputs.ts.terminal_task_id ==
                       SINGLE_TEST_MATRIX_COMMAND);
            TEST_CHECK(outputs.ts.terminal_status ==
                       NPU_STATUS_SUCCESS);
            TEST_CHECK(outputs.ts.terminal_engine ==
                       NPU_ENGINE_MATRIX);
            TEST_CHECK(outputs.ts.terminal_opcode ==
                       NPU_MATRIX_GEMM);
            TEST_CHECK(outputs.ts.terminal_done_flags == 0u);
            TEST_CHECK(outputs.ts.terminal_error_info == 0u);
            TEST_CHECK(
                outputs.ts.terminal_irq_on_success != 0u);
            terminal_seen = 1u;
        }
    }

    TEST_CHECK(terminal_seen != 0u);
    TEST_CHECK(command_handshakes == 1u);
    TEST_CHECK(descriptor_requests ==
               NPU_WIRE_MATRIX_DESC_BYTES /
                   NPU_REF_BUS_BYTES);
    TEST_CHECK(l1_read_requests == 2u);
    TEST_CHECK(l1_write_requests == 1u);
    TEST_CHECK(l1_write_responses == 1u);
    TEST_CHECK(mac_active_cycles == 1u);
    TEST_CHECK(env->top.engine[NPU_TS_PORT_MATRIX]
                   .trace.read_count == 3u);
    TEST_CHECK(env->top.engine[NPU_TS_PORT_MATRIX]
                   .trace.write_count == 1u);
    TEST_CHECK(
        single_test_get_u32(env->l1, SINGLE_TEST_DST) == 23u);
    TEST_CHECK(env->noc_server.axi_reads == 3u);
    TEST_CHECK(env->noc_server.axi_read_beats ==
               NPU_WIRE_MATRIX_DESC_BYTES /
                   NPU_REF_BUS_BYTES);
    task = npu_ts_cycle_find_task(
        &env->top.ts, SINGLE_TEST_MATRIX_COMMAND);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_SUCCESS);
    TEST_CHECK(task->status == NPU_STATUS_SUCCESS);
    TEST_CHECK(task->user_tag == UINT32_C(0x4d450480));
    TEST_CHECK(task->progress == 1u);
    return 0;
}

static int single_test_complex_task(single_test_env_t *env)
{
    uint8_t *descriptor =
        &env->ddr[(size_t)SINGLE_TEST_DESC_ADDR];
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    const npu_ts_task_entry_t *task;
    uint32_t cycle;
    uint32_t port;
    uint32_t command_handshakes = 0u;
    uint32_t descriptor_requests = 0u;
    uint32_t l1_read_requests = 0u;
    uint32_t l1_write_requests = 0u;
    uint32_t l1_write_responses = 0u;
    uint8_t i2f_seen = 0u;
    uint8_t fp_seen = 0u;
    uint8_t f2i_seen = 0u;
    uint8_t terminal_seen = 0u;

    single_test_make_complex_descriptor(descriptor);
    single_test_put_u32(env->l1, SINGLE_TEST_SRC0, 0u);
    single_test_put_u32(
        env->l1, SINGLE_TEST_SRC_SCALE, 0x3f800000u);
    single_test_put_u32(
        env->l1, SINGLE_TEST_DST_SCALE, 0x3c000000u);
    (void)memset(
        &env->l1[SINGLE_TEST_DST], 0xa5, 8u);

    SINGLE_TEST_CALL(single_test_start_engine_task(
        env, SINGLE_TEST_COMPLEX_COMMAND,
        NPU_ENGINE_COMPLEX, NPU_COMPLEX_ACT));
    for (cycle = 0u;
         cycle < SINGLE_TEST_MAX_CYCLES &&
         terminal_seen == 0u;
         cycle++) {
        if ((cycle & 1u) == 0u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
        }
        single_test_core_inputs(env, &inputs);
        inputs.issue_rsp_ready_i = 1u;
        single_test_core_tick(env, &inputs, &outputs);
        if ((cycle & 1u) != 0u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
        }

        if (outputs.ts.engine[NPU_TS_PORT_COMPLEX]
                    .req_valid != 0u &&
            outputs.engine[NPU_TS_PORT_COMPLEX]
                    .engine.eng_req_ready_o != 0u) {
            command_handshakes++;
        }
        if (outputs.engine[NPU_TS_PORT_COMPLEX]
                    .engine.desc_rd_req_valid_o != 0u &&
            outputs.ts.desc[NPU_TS_PORT_COMPLEX]
                    .req_ready != 0u) {
            descriptor_requests++;
        }
        for (port = 0u;
             port < NPU_ENGINE_DATA_READ_PORTS;
             port++) {
            if (outputs.engine[NPU_TS_PORT_COMPLEX]
                        .l1_read[port].req_valid != 0u &&
                outputs.l1.read[NPU_L1_RD_CME_SRC0 + port]
                        .req_ready != 0u) {
                l1_read_requests++;
            }
        }
        if (outputs.engine[NPU_TS_PORT_COMPLEX]
                    .l1_write.req_valid != 0u &&
            outputs.l1.write[NPU_L1_WR_CME_DST]
                    .req_ready != 0u) {
            l1_write_requests++;
        }
        if (outputs.engine[NPU_TS_PORT_COMPLEX]
                    .l1_write.rsp_ready != 0u &&
            outputs.l1.write[NPU_L1_WR_CME_DST]
                    .rsp_valid != 0u) {
            l1_write_responses++;
        }
        if (outputs.engine[NPU_TS_PORT_COMPLEX]
                    .cme_i2f_active != 0u) {
            i2f_seen = 1u;
        }
        if (outputs.engine[NPU_TS_PORT_COMPLEX]
                    .cme_fp_active != 0u) {
            fp_seen = 1u;
        }
        if (outputs.engine[NPU_TS_PORT_COMPLEX]
                    .cme_f2i_active != 0u) {
            f2i_seen = 1u;
        }
        if (outputs.ts.terminal_valid != 0u) {
            TEST_CHECK(outputs.ts.terminal_task_id ==
                       SINGLE_TEST_COMPLEX_COMMAND);
            TEST_CHECK(outputs.ts.terminal_status ==
                       NPU_STATUS_SUCCESS);
            TEST_CHECK(outputs.ts.terminal_engine ==
                       NPU_ENGINE_COMPLEX);
            TEST_CHECK(outputs.ts.terminal_opcode ==
                       NPU_COMPLEX_ACT);
            TEST_CHECK(outputs.ts.terminal_done_flags == 0u);
            TEST_CHECK(outputs.ts.terminal_error_info == 0u);
            TEST_CHECK(
                outputs.ts.terminal_irq_on_success != 0u);
            terminal_seen = 1u;
        }
    }

    TEST_CHECK(terminal_seen != 0u);
    TEST_CHECK(command_handshakes == 1u);
    TEST_CHECK(descriptor_requests ==
               NPU_WIRE_COMPLEX_DESC_BYTES /
                   NPU_REF_BUS_BYTES);
    TEST_CHECK(l1_read_requests == 2u);
    TEST_CHECK(l1_write_requests == 1u);
    TEST_CHECK(l1_write_responses == 1u);
    TEST_CHECK(i2f_seen != 0u);
    TEST_CHECK(fp_seen != 0u);
    TEST_CHECK(f2i_seen != 0u);
    TEST_CHECK(env->top.engine[NPU_TS_PORT_COMPLEX]
                   .trace.read_count == 3u);
    TEST_CHECK(env->top.engine[NPU_TS_PORT_COMPLEX]
                   .trace.write_count == 1u);
    TEST_CHECK(env->l1[SINGLE_TEST_DST] == 64u);
    TEST_CHECK(env->noc_server.axi_reads == 3u);
    TEST_CHECK(env->noc_server.axi_read_beats ==
               NPU_WIRE_COMPLEX_DESC_BYTES /
                   NPU_REF_BUS_BYTES);
    task = npu_ts_cycle_find_task(
        &env->top.ts, SINGLE_TEST_COMPLEX_COMMAND);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_SUCCESS);
    TEST_CHECK(task->status == NPU_STATUS_SUCCESS);
    TEST_CHECK(task->user_tag == UINT32_C(0x434d4581));
    TEST_CHECK(task->progress == 1u);
    return 0;
}

static int single_test_complex_numeric_error(
    single_test_env_t *env)
{
    uint8_t *descriptor =
        &env->ddr[(size_t)SINGLE_TEST_DESC_ADDR];
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    const npu_ts_task_entry_t *task;
    uint32_t cycle;
    uint32_t port;
    uint32_t command_handshakes = 0u;
    uint32_t descriptor_requests = 0u;
    uint32_t l1_read_requests = 0u;
    uint32_t l1_write_requests = 0u;
    uint8_t numeric_flag_seen = 0u;
    uint8_t terminal_seen = 0u;

    single_test_make_softmax_error_descriptor(descriptor);
    env->l1[SINGLE_TEST_SRC0] = 1u;
    env->l1[SINGLE_TEST_SRC0 + 1u] = 2u;
    env->l1[SINGLE_TEST_SRC0 + 2u] = 3u;
    env->l1[SINGLE_TEST_SRC0 + 3u] = 4u;
    (void)memset(&env->l1[SINGLE_TEST_MASK], 0, 4u);
    (void)memset(&env->l1[SINGLE_TEST_DST], 0xa5, 4u);

    SINGLE_TEST_CALL(single_test_start_engine_task(
        env, SINGLE_TEST_NUMERIC_COMMAND,
        NPU_ENGINE_COMPLEX, NPU_COMPLEX_SOFTMAX));
    for (cycle = 0u;
         cycle < SINGLE_TEST_MAX_CYCLES &&
         terminal_seen == 0u;
         cycle++) {
        SINGLE_TEST_CALL(single_test_noc_tick(
            env, &noc_outputs));
        single_test_core_inputs(env, &inputs);
        inputs.issue_rsp_ready_i = 1u;
        single_test_core_tick(env, &inputs, &outputs);

        if (outputs.ts.engine[NPU_TS_PORT_COMPLEX]
                    .req_valid != 0u &&
            outputs.engine[NPU_TS_PORT_COMPLEX]
                    .engine.eng_req_ready_o != 0u) {
            command_handshakes++;
        }
        if (outputs.engine[NPU_TS_PORT_COMPLEX]
                    .engine.desc_rd_req_valid_o != 0u &&
            outputs.ts.desc[NPU_TS_PORT_COMPLEX]
                    .req_ready != 0u) {
            descriptor_requests++;
        }
        for (port = 0u;
             port < NPU_ENGINE_DATA_READ_PORTS;
             port++) {
            if (outputs.engine[NPU_TS_PORT_COMPLEX]
                        .l1_read[port].req_valid != 0u) {
                l1_read_requests++;
            }
        }
        if (outputs.engine[NPU_TS_PORT_COMPLEX]
                    .l1_write.req_valid != 0u ||
            outputs.engine[NPU_TS_PORT_COMPLEX]
                    .l1_write.data_valid != 0u) {
            l1_write_requests++;
        }
        if ((outputs.engine[NPU_TS_PORT_COMPLEX]
                      .cme_numeric_flag &
             NPU_ENGINE_DATA_CME_NUMERIC_EXCEPTION) != 0u) {
            numeric_flag_seen = 1u;
        }
        if (outputs.ts.terminal_valid != 0u) {
            TEST_CHECK(outputs.ts.terminal_task_id ==
                       SINGLE_TEST_NUMERIC_COMMAND);
            TEST_CHECK(outputs.ts.terminal_status ==
                       NPU_STATUS_NUMERIC_EXCEPTION);
            TEST_CHECK(outputs.ts.terminal_engine ==
                       NPU_ENGINE_COMPLEX);
            TEST_CHECK(outputs.ts.terminal_opcode ==
                       NPU_COMPLEX_SOFTMAX);
            TEST_CHECK(outputs.ts.terminal_done_flags == 0u);
            TEST_CHECK(
                (outputs.ts.terminal_error_info >> 28u) ==
                NPU_ENGINE_ERROR_EXECUTE);
            TEST_CHECK(outputs.ts.terminal_irq_on_error != 0u);
            terminal_seen = 1u;
        }
    }

    TEST_CHECK(terminal_seen != 0u);
    TEST_CHECK(command_handshakes == 1u);
    TEST_CHECK(descriptor_requests ==
               NPU_WIRE_COMPLEX_DESC_BYTES /
                   NPU_REF_BUS_BYTES);
    TEST_CHECK(l1_read_requests == 1u);
    TEST_CHECK(l1_write_requests == 0u);
    TEST_CHECK(numeric_flag_seen != 0u);
    TEST_CHECK(env->top.engine[NPU_TS_PORT_COMPLEX]
                   .trace.read_count == 1u);
    TEST_CHECK(env->top.engine[NPU_TS_PORT_COMPLEX]
                   .trace.write_count == 0u);
    TEST_CHECK(env->l1[SINGLE_TEST_DST] == 0xa5u);
    TEST_CHECK(env->l1[SINGLE_TEST_DST + 1u] == 0xa5u);
    TEST_CHECK(env->l1[SINGLE_TEST_DST + 2u] == 0xa5u);
    TEST_CHECK(env->l1[SINGLE_TEST_DST + 3u] == 0xa5u);
    TEST_CHECK(env->noc_server.axi_reads == 3u);
    TEST_CHECK(env->noc_server.axi_read_beats ==
               NPU_WIRE_COMPLEX_DESC_BYTES /
                   NPU_REF_BUS_BYTES);
    task = npu_ts_cycle_find_task(
        &env->top.ts, SINGLE_TEST_NUMERIC_COMMAND);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_ERROR);
    TEST_CHECK(task->status == NPU_STATUS_NUMERIC_EXCEPTION);
    TEST_CHECK(task->user_tag == UINT32_C(0x534f4682));
    TEST_CHECK(task->progress == 0u);
    return 0;
}

static int single_test_vector_task(single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint8_t expected[16];
    uint8_t original[16];
    uint8_t write_data_seen = 0u;
    uint8_t write_response_seen = 0u;
    uint8_t terminal_seen = 0u;
    uint8_t l1_stall_seen = 0u;
    uint8_t engine_clock_disable_seen = 0u;
    uint8_t engine_forced_clock_seen = 0u;
    uint32_t read_requests = 0u;
    uint32_t write_requests = 0u;
    uint32_t write_responses = 0u;
    uint32_t cycle;
    uint32_t index;
    uint64_t core_before;
    uint64_t noc_before;

    for (index = 0u; index < 16u; index++) {
        env->l1[SINGLE_TEST_SRC0 + index] =
            (uint8_t)(index + 1u);
        env->l1[SINGLE_TEST_SRC1 + index] =
            (uint8_t)(index + 10u);
        original[index] = 0xa5u;
        env->l1[SINGLE_TEST_DST + index] = original[index];
        expected[index] =
            (uint8_t)((index + 1u) + (index + 10u));
    }
    env->l1[SINGLE_TEST_SRC0 + 15u] = 120u;
    env->l1[SINGLE_TEST_SRC1 + 15u] = 20u;
    expected[15u] = 127u;

    core_before = env->core_ticks;
    noc_before = env->noc_ticks;
    SINGLE_TEST_CALL(single_test_issue_submit(
        env, SINGLE_TEST_COMMAND));

    for (cycle = 0u;
         cycle < SINGLE_TEST_MAX_CYCLES &&
         terminal_seen == 0u;
         cycle++) {
        if ((cycle & 1u) == 0u &&
            (cycle % 4u) != 1u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
        }

        single_test_core_inputs(env, &inputs);
        inputs.issue_rsp_ready_i = 1u;
        if (single_test_engine_quiescent(
                &env->top.engine[
                    NPU_TS_PORT_VECTOR]) == 0u) {
            inputs.module_clk_en_i =
                (uint8_t)(NPU_SINGLE_CORE_CLK_ALL &
                          ~(uint8_t)(1u <<
                              NPU_SINGLE_CORE_CLK_IVE));
            engine_clock_disable_seen = 1u;
        }
        single_test_core_tick(env, &inputs, &outputs);
        if (engine_clock_disable_seen != 0u &&
            single_test_clock_active(
                outputs.module_clk_active_o,
                NPU_SINGLE_CORE_CLK_IVE) != 0u) {
            engine_forced_clock_seen = 1u;
        }

        if ((cycle & 1u) != 0u &&
            (cycle % 4u) != 1u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
        }
        if ((cycle % 11u) == 0u) {
            SINGLE_TEST_CALL(single_test_noc_tick(
                env, &noc_outputs));
        }

        for (index = 0u;
             index < NPU_ENGINE_DATA_READ_PORTS;
             index++) {
            if (outputs.engine[NPU_TS_PORT_VECTOR]
                        .l1_read[index].req_valid != 0u &&
                outputs.l1.read[
                    NPU_L1_RD_IVE_SRC0 + index]
                        .req_ready != 0u) {
                read_requests++;
            }
        }
        if (outputs.engine[NPU_TS_PORT_VECTOR]
                    .l1_write.req_valid != 0u &&
            outputs.l1.write[NPU_L1_WR_IVE_DST]
                    .req_ready != 0u) {
            write_requests++;
        }
        if (outputs.engine[NPU_TS_PORT_VECTOR]
                    .l1_write.data_valid != 0u &&
            outputs.l1.write[NPU_L1_WR_IVE_DST]
                    .data_ready != 0u) {
            write_data_seen = 1u;
        }
        if (outputs.engine[NPU_TS_PORT_VECTOR]
                    .l1_write.rsp_ready != 0u &&
            outputs.l1.write[NPU_L1_WR_IVE_DST]
                    .rsp_valid != 0u) {
            write_response_seen = 1u;
            write_responses++;
        }
        if (outputs.engine[NPU_TS_PORT_VECTOR]
                    .l1_stall != 0u) {
            l1_stall_seen = 1u;
        }
        if (write_data_seen == 0u) {
            TEST_CHECK(memcmp(
                           &env->l1[SINGLE_TEST_DST],
                           original, sizeof(original)) == 0);
        }
        if (outputs.engine[NPU_TS_PORT_VECTOR]
                    .engine.eng_done_valid_o != 0u) {
            TEST_CHECK(write_response_seen != 0u);
        }
        if (outputs.ts.terminal_valid != 0u) {
            TEST_CHECK(write_response_seen != 0u);
            TEST_CHECK(outputs.ts.terminal_task_id ==
                       SINGLE_TEST_COMMAND);
            TEST_CHECK(outputs.ts.terminal_status ==
                       NPU_STATUS_SUCCESS);
            terminal_seen = 1u;
        }
    }

    TEST_CHECK(terminal_seen != 0u);
    TEST_CHECK(write_data_seen != 0u);
    TEST_CHECK(write_response_seen != 0u);
    TEST_CHECK(l1_stall_seen != 0u);
    TEST_CHECK(engine_clock_disable_seen != 0u);
    TEST_CHECK(engine_forced_clock_seen != 0u);
    TEST_CHECK(read_requests == 2u);
    TEST_CHECK(write_requests == 1u);
    TEST_CHECK(write_responses == 1u);
    TEST_CHECK(env->top.engine[NPU_TS_PORT_VECTOR]
                   .trace.read_count == 4u);
    TEST_CHECK(env->top.engine[NPU_TS_PORT_VECTOR]
                   .trace.write_count == 2u);
    TEST_CHECK(env->noc_server.cdc_request_cycles != 0u);
    if (env->top.tbu_mode ==
        NPU_SINGLE_CORE_TBU_INTERNAL) {
        TEST_CHECK(env->noc_server.tbu_requests == 0u);
        TEST_CHECK(
            env->noc_server.internal_tbu_requests == 2u);
        TEST_CHECK(
            env->noc_server.internal_tbu_responses == 2u);
        TEST_CHECK(
            env->noc_server.internal_tbu_first_response_tick -
                    env->noc_server
                        .internal_tbu_first_request_tick -
                    1u ==
                NPU_TBU_HIT_LATENCY);
    } else {
        TEST_CHECK(env->noc_server.tbu_requests == 2u);
    }
    TEST_CHECK(env->noc_server.axi_reads == 2u);
    TEST_CHECK(env->noc_server.axi_read_beats ==
               NPU_WIRE_VECTOR_DESC_BYTES /
                   NPU_REF_BUS_BYTES);
    if (env->top.tbu_mode ==
        NPU_SINGLE_CORE_TBU_EXTERNAL) {
        TEST_CHECK(
            env->noc_server.tbu_request_stalls != 0u);
    }
    TEST_CHECK(env->noc_server.axi_ar_stalls != 0u);
    TEST_CHECK(env->core_ticks - core_before !=
               env->noc_ticks - noc_before);
    TEST_CHECK(memcmp(
                   &env->l1[SINGLE_TEST_DST],
                   expected, sizeof(expected)) == 0);
    TEST_CHECK(env->functional.perf.int_saturate_count == 1u);
    TEST_CHECK(env->top.lsc.perf_counter[13] == 1u);
    return 0;
}

static int single_test_reset_flush(single_test_env_t *env)
{
    npu_single_core_cycle_core_inputs_t inputs;
    npu_single_core_cycle_core_outputs_t outputs;
    npu_single_core_cycle_noc_outputs_t noc_outputs;
    uint64_t low_beat;
    uint64_t high_beat;
    uint64_t preserved;
    uint32_t cycle;
    uint32_t engine;
    uint8_t issue_accepted = 0u;
    uint8_t gc_accepted = 0u;

    single_test_make_command(
        SINGLE_TEST_RESET_COMMAND, &low_beat,
        &high_beat);
    preserved = single_test_get_u64(
        env->l1, SINGLE_TEST_DST);
    for (cycle = 0u; cycle < 128u; cycle++) {
        single_test_core_inputs(env, &inputs);
        if (issue_accepted == 0u) {
            inputs.issue_valid_i = 1u;
            inputs.issue_opcode_i = NPU_ISSUE_CUSTOM0_OPCODE;
            inputs.issue_funct3_i = NPU_ISSUE_FUNCT3_SUBMIT;
            inputs.issue_rs1_i = low_beat;
            inputs.issue_rs2_i = high_beat;
            inputs.issue_rd_i = 10u;
        }
        if (gc_accepted == 0u) {
            inputs.gc_axi.dcache_read_req.valid = 1u;
            inputs.gc_axi.dcache_read_req.addr =
                UINT64_C(0x00022000);
            inputs.gc_axi.dcache_read_req.tag = 0x3b0u;
        }
        single_test_core_tick(env, &inputs, &outputs);
        if (inputs.issue_valid_i != 0u &&
            outputs.issue.issue_ready_o != 0u) {
            issue_accepted = 1u;
        }
        if (inputs.gc_axi.dcache_read_req.valid != 0u &&
            outputs.gc_axi.dcache_read_req_ready != 0u) {
            gc_accepted = 1u;
        }
        if (issue_accepted != 0u &&
            gc_accepted != 0u &&
            npu_mif_cdc_req_level(
                &env->top.cdc, NPU_MIF_OWNER_DFU) != 0u &&
            outputs.gc_axi.axi.arvalid != 0u) {
            break;
        }
    }
    TEST_CHECK(issue_accepted != 0u);
    TEST_CHECK(gc_accepted != 0u);
    TEST_CHECK(npu_mif_cdc_req_level(
                   &env->top.cdc,
                   NPU_MIF_OWNER_DFU) != 0u);
    TEST_CHECK(outputs.gc_axi.axi.arvalid != 0u);

    env->core_rst_ni = 0u;
    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.core_reset_n == 0u);
    TEST_CHECK(outputs.issue.issue_rsp_valid_o == 0u);
    TEST_CHECK(outputs.gc_axi.axi.arvalid == 0u);
    TEST_CHECK(env->top.core_cycle == 0u);
    TEST_CHECK(npu_mif_cdc_req_level(
                   &env->top.cdc,
                   NPU_MIF_OWNER_DFU) == 0u);

    env->noc_rst_ni = 0u;
    SINGLE_TEST_CALL(single_test_noc_tick(
        env, &noc_outputs));
    TEST_CHECK(noc_outputs.noc_reset_n == 0u);
    TEST_CHECK(env->top.noc_cycle == 0u);
    TEST_CHECK(npu_mif_cycle_is_idle(&env->top.mif) != 0u);
    TEST_CHECK(npu_gc_axi_cycle_is_idle(
                   &env->top.gc_axi) != 0u);
    TEST_CHECK(env->top.issue.state ==
               NPU_ISSUE_STATE_IDLE);
    TEST_CHECK(npu_cfe_cycle_idle(&env->top.cfe) != 0u);
    TEST_CHECK(env->top.ts.dfu.valid == 0u);
    TEST_CHECK(single_test_get_u64(
                   env->l1, SINGLE_TEST_DST) == preserved);
    for (engine = 0u; engine < NPU_TS_ENGINE_COUNT; engine++) {
        TEST_CHECK(
            single_test_engine_quiescent(
                &env->top.engine[engine]) != 0u);
        TEST_CHECK(env->top.engine[engine].workspace_bound != 0u);
    }

    single_test_server_reset(&env->noc_server);
    env->core_rst_ni = 1u;
    env->noc_rst_ni = 1u;
    single_test_core_inputs(env, &inputs);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.core_reset_n == 0u);
    single_test_core_tick(env, &inputs, &outputs);
    TEST_CHECK(outputs.core_reset_n != 0u);
    SINGLE_TEST_CALL(single_test_noc_tick(
        env, &noc_outputs));
    TEST_CHECK(noc_outputs.noc_reset_n == 0u);
    SINGLE_TEST_CALL(single_test_noc_tick(
        env, &noc_outputs));
    TEST_CHECK(noc_outputs.noc_reset_n != 0u);
    return 0;
}

static int single_test_explicit_reset_clears_stale(
    single_test_env_t *env)
{
    env->top.stale_axi_read_beats[0][0x21u] = 3u;
    env->top.stale_axi_write_pending[1][0x22u] = 1u;
    env->top.stale_tbu_tag[0] = 0x123u;
    env->top.stale_tbu_tag_valid[0] = 1u;
    env->top.stale_axi_read_drop_count = 4u;
    env->top.stale_axi_write_drop_count = 5u;
    env->top.stale_tbu_drop_count = 6u;

    npu_single_core_cycle_reset(&env->top);
    TEST_CHECK(
        env->top.stale_axi_read_beats[0][0x21u] == 0u);
    TEST_CHECK(
        env->top.stale_axi_write_pending[1][0x22u] == 0u);
    TEST_CHECK(env->top.stale_tbu_tag_valid[0] == 0u);
    TEST_CHECK(env->top.stale_axi_read_drop_count == 0u);
    TEST_CHECK(env->top.stale_axi_write_drop_count == 0u);
    TEST_CHECK(env->top.stale_tbu_drop_count == 0u);
    TEST_CHECK(env->top.initialized != 0u);
    TEST_CHECK(env->top.engine[0].workspace_bound != 0u);
    return 0;
}

static int single_test_noc_reset_clears_stale(
    single_test_env_t *env)
{
    npu_single_core_cycle_noc_outputs_t outputs;

    SINGLE_TEST_CALL(single_test_wait_idle(env));
    env->top.stale_axi_read_beats[0][0x31u] = 1u;
    env->top.stale_axi_write_pending[0][0x32u] = 1u;
    env->top.stale_tbu_tag[0] = 0x321u;
    env->top.stale_tbu_tag_valid[0] = 1u;
    env->noc_rst_ni = 0u;
    SINGLE_TEST_CALL(single_test_noc_tick(env, &outputs));
    TEST_CHECK(outputs.noc_reset_n == 0u);
    TEST_CHECK(
        env->top.stale_axi_read_beats[0][0x31u] == 0u);
    TEST_CHECK(
        env->top.stale_axi_write_pending[0][0x32u] == 0u);
    TEST_CHECK(env->top.stale_tbu_tag_valid[0] == 0u);
    return 0;
}

int test_single_core_cycle(void)
{
    single_test_env_t *env = &single_test_env;

    SINGLE_TEST_CALL(
        single_test_workspace_preflight_transaction(env));
    SINGLE_TEST_CALL(single_test_default_wire_uses_ddr(env));
    SINGLE_TEST_CALL(single_test_capability_consistency(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_idle_module_clocks(env));
    SINGLE_TEST_CALL(single_test_ts_terminal_keeps_clock(env));
    SINGLE_TEST_CALL(single_test_idle_cfe_clock(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_top_control_signals(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_dvfs_quiesce(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_current_idle_access(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_functional_perf_bridge(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_cfe_accept_perf_once(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_wdt_held_l1_response(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_wdt_compute_activity(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_wdt_issue_progress(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_wdt_lookup_progress(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_wdt_desc_progress(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_wdt_gc_axi_progress(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_wdt_event_not_repeated(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_l1_ecc_event_count(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_external_error_sync(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_local_error_records(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_l1_bank_stall_perf(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_mif_idle_sync(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_cdc_local_idle(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_soft_reset_cross_domain(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(
        single_test_explicit_reset_clears_stale(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_noc_reset_clears_stale(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(
        single_test_gc_reset_stale_read_wait_rlast(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(
        single_test_gc_reset_stale_write_drain(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_dma_read_perf_bytes(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_dma_write_perf_bytes(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_matrix_task(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_complex_task(env));

    SINGLE_TEST_CALL(single_test_env_init(env));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_complex_numeric_error(env));

    SINGLE_TEST_CALL(single_test_env_init_mode(
        env, NPU_SINGLE_CORE_TBU_INTERNAL));
    SINGLE_TEST_CALL(single_test_set_descriptor_rule(env, 0u));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_internal_tbu_permission(env));

    SINGLE_TEST_CALL(single_test_env_init_mode(
        env, NPU_SINGLE_CORE_TBU_INTERNAL));
    SINGLE_TEST_CALL(single_test_set_descriptor_rule(env, 1u));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_internal_tbu_hold_reset(env));

    SINGLE_TEST_CALL(single_test_env_init_mode(
        env, NPU_SINGLE_CORE_TBU_INTERNAL));
    SINGLE_TEST_CALL(single_test_set_descriptor_rule(env, 1u));
    SINGLE_TEST_CALL(single_test_reset_release(env));
    SINGLE_TEST_CALL(single_test_system_and_debug(env));
    SINGLE_TEST_CALL(single_test_gc_axi_read(env));
    SINGLE_TEST_CALL(single_test_vector_task(env));
    SINGLE_TEST_CALL(single_test_reset_flush(env));
    return 0;
}

#ifdef NPU_SINGLE_CORE_CYCLE_STANDALONE
int main(void)
{
    int line = test_single_core_cycle();

    if (line != 0) {
        (void)printf(
            "single core cycle test failed at line %d\n",
            line);
        return 1;
    }
    (void)printf("single core cycle test passed\n");
    return 0;
}
#endif
