#include "npu_ts_cycle.h"
#include "test_util.h"

#include <stdint.h>
#include <string.h>

#define TC_NONE 0x0fffu
#define TC_DESC_ADDR 0x1000u

#define TC_CALL(expression)       \
    do {                          \
        int tc_line = (expression); \
        if (tc_line != 0) {       \
            return tc_line;       \
        }                         \
    } while (0)

static void tc_put_u16(uint8_t *data, size_t offset,
                       uint16_t value)
{
    data[offset] = (uint8_t)value;
    data[offset + 1u] = (uint8_t)(value >> 8);
}

static void tc_put_u32(uint8_t *data, size_t offset,
                       uint32_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 4u; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static void tc_put_u64(uint8_t *data, size_t offset,
                       uint64_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static uint64_t tc_get_u64(const uint8_t *data, size_t offset)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        value |= (uint64_t)data[offset + byte] <<
                 (byte * 8u);
    }
    return value;
}

static uint16_t tc_event(uint8_t id, uint8_t generation)
{
    return (uint16_t)(((uint16_t)(generation & 0x0fu) << 8) |
                      id);
}

static uint32_t tc_error_info(uint8_t stage,
                              uint8_t status,
                              uint8_t opcode)
{
    return ((uint32_t)(stage & 0x0fu) << 28) |
           ((uint32_t)status << 16) |
           (UINT32_C(0xff) << 8) |
           opcode;
}

static void tc_idle_inputs(npu_ts_cycle_inputs_t *inputs)
{
    uint32_t port;

    memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = 1u;
    for (port = 0u; port < NPU_TS_ENGINE_COUNT; port++) {
        inputs->engine[port].quiescent = 1u;
    }
}

static void tc_step(npu_ts_cycle_t *model,
                    npu_ts_cycle_inputs_t *inputs,
                    npu_ts_cycle_outputs_t *outputs)
{
    model->descriptor_diagnostic_mode = 1u;
    npu_ts_cycle_step(model, inputs, outputs);
}

static int tc_query(npu_ts_cycle_t *model,
                    uint16_t task_id,
                    uint8_t selector,
                    uint64_t *result)
{
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;

    tc_idle_inputs(&inputs);
    inputs.ctl.valid = 1u;
    inputs.ctl.op = NPU_TS_CTL_QUERY;
    inputs.ctl.rs1 = task_id;
    inputs.ctl.rs2 = selector;
    tc_step(model, &inputs, &outputs);
    TEST_CHECK(outputs.ctl.ready == 1u);

    tc_idle_inputs(&inputs);
    tc_step(model, &inputs, &outputs);
    TEST_CHECK(outputs.ctl.rsp_valid == 1u);
    *result = outputs.ctl.rsp_data;

    tc_idle_inputs(&inputs);
    inputs.ctl.rsp_ready = 1u;
    tc_step(model, &inputs, &outputs);
    TEST_CHECK(outputs.ctl.rsp_valid == 1u);
    return 0;
}

static uint8_t tc_find_slot(const npu_ts_cycle_t *model,
                            uint16_t command_id)
{
    uint32_t slot;

    for (slot = 0u; slot < NPU_TS_TASK_COUNT; slot++) {
        if (model->task[slot].valid != 0u &&
            model->task[slot].cmd.command_id == command_id) {
            return (uint8_t)slot;
        }
    }
    return NPU_TS_INVALID_INDEX;
}

static uint8_t tc_task_count(const npu_ts_cycle_t *model)
{
    uint32_t slot;
    uint8_t count = 0u;

    for (slot = 0u; slot < NPU_TS_TASK_COUNT; slot++) {
        count = (uint8_t)(count +
                          (model->task[slot].valid != 0u
                               ? 1u
                               : 0u));
    }
    return count;
}

static uint8_t tc_desc_count(const npu_ts_cycle_t *model)
{
    uint32_t slot;
    uint8_t count = 0u;

    for (slot = 0u; slot < NPU_TS_DESC_SLOT_COUNT; slot++) {
        count = (uint8_t)(count +
                          (model->desc_slot[slot].allocated != 0u
                               ? 1u
                               : 0u));
    }
    return count;
}

static void tc_make_common(uint8_t *desc,
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
    memset(desc, 0, bytes);
    desc[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    desc[0x01u] = (uint8_t)engine;
    tc_put_u16(desc, 0x02u, (uint16_t)bytes);
    tc_put_u32(desc, 0x04u, op_flags);
    tc_put_u64(desc, 0x08u, src0);
    tc_put_u64(desc, 0x10u, src1);
    tc_put_u64(desc, 0x18u, src2);
    tc_put_u64(desc, 0x20u, dst);
    tc_put_u64(desc, 0x28u, aux0);
    tc_put_u64(desc, 0x30u, aux1);
    tc_put_u32(desc, 0x38u, numeric);
    tc_put_u32(desc, 0x3cu, user_tag);
}

static void tc_make_dma_desc(uint8_t desc[NPU_WIRE_DMA_DESC_BYTES],
                             uint32_t user_tag)
{
    uint32_t numeric =
        (uint32_t)NPU_DTYPE_INT8 |
        ((uint32_t)NPU_DTYPE_INT8 << 6);

    tc_make_common(desc, NPU_WIRE_DMA_DESC_BYTES,
                   NPU_ENGINE_DMA, 1u,
                   0x0800u, 0u, 0u, 0x0100u,
                   0u, 0u, numeric, user_tag);
    desc[0x40u] = 1u;
    desc[0x41u] = NPU_SPACE_DDR;
    desc[0x42u] = NPU_SPACE_L1;
    desc[0x43u] = NPU_DMA_CONVERT_NONE;
    desc[0x44u] = NPU_REF_DMA_MAX_BURST_BEATS - 1u;
    desc[0x45u] = NPU_REF_DMA_OUTSTANDING;
    tc_put_u32(desc, 0x48u, 8u);
    tc_put_u64(desc, 0x98u, 8u);
    tc_put_u64(desc, 0xa0u, 8u);
}

static void tc_make_matrix_desc(
    uint8_t desc[NPU_WIRE_MATRIX_DESC_BYTES])
{
    uint32_t numeric =
        (uint32_t)NPU_DTYPE_INT8 |
        ((uint32_t)NPU_DTYPE_INT8 << 2) |
        ((uint32_t)NPU_DTYPE_INT32 << 6);

    tc_make_common(desc, NPU_WIRE_MATRIX_DESC_BYTES,
                   NPU_ENGINE_MATRIX, 0u,
                   0x100u, 0x200u, 0u, 0x300u,
                   0u, 0u, numeric, 0x4d450001u);
    tc_put_u32(desc, 0x40u, 1u);
    tc_put_u32(desc, 0x44u, 1u);
    tc_put_u32(desc, 0x48u, 2u);
    tc_put_u32(desc, 0x4cu, 1u);
    tc_put_u32(desc, 0x50u, 1u);
    tc_put_u32(desc, 0x54u, 1u);
    tc_put_u32(desc, 0x58u, 2u);
    tc_put_u32(desc, 0x5cu, 1u << 7);
    tc_put_u32(desc, 0x60u, 2u);
    tc_put_u32(desc, 0x68u, 4u);
    desc[0x90u] = 0u;
    desc[0x91u] = 2u;
    desc[0x92u] = 4u;
    desc[0x93u] = 0u;
    desc[0x94u] = NPU_OVERFLOW_SATURATE;
    desc[0xa6u] = 8u;
}

static void tc_make_vector_desc(
    uint8_t desc[NPU_WIRE_VECTOR_DESC_BYTES])
{
    uint32_t numeric =
        (uint32_t)NPU_DTYPE_INT8 |
        ((uint32_t)NPU_DTYPE_INT8 << 2) |
        ((uint32_t)NPU_DTYPE_INT8 << 6) |
        (1u << 12) | (1u << 13);

    tc_make_common(desc, NPU_WIRE_VECTOR_DESC_BYTES,
                   NPU_ENGINE_VECTOR, 0u,
                   0x400u, 0x500u, 0u, 0x600u,
                   0u, 0u, numeric, 0x49564501u);
    tc_put_u32(desc, 0x40u, 1u);
    tc_put_u32(desc, 0x44u, 4u);
    tc_put_u32(desc, 0x48u, 4u);
    tc_put_u32(desc, 0x50u, 1u);
    tc_put_u32(desc, 0x54u, 4u);
    tc_put_u32(desc, 0x58u, 1u);
    tc_put_u32(desc, 0x5cu, 4u);
    tc_put_u32(desc, 0x68u, 1u);
    tc_put_u32(desc, 0x6cu, 4u);
    desc[0x79u] = NPU_COMPARE_EQ;
    desc[0x7au] = NPU_OVERFLOW_SATURATE;
    tc_put_u32(desc, 0x80u, 0x3f800000u);
    tc_put_u32(desc, 0x84u, 0x3f800000u);
    tc_put_u32(desc, 0x8cu, 0x3f800000u);
}

static void tc_make_complex_desc(
    uint8_t desc[NPU_WIRE_COMPLEX_DESC_BYTES])
{
    uint32_t numeric =
        (uint32_t)NPU_DTYPE_INT8 |
        ((uint32_t)NPU_DTYPE_INT8 << 6) |
        (1u << 12) | (1u << 13) | (1u << 16);

    tc_make_common(desc, NPU_WIRE_COMPLEX_DESC_BYTES,
                   NPU_ENGINE_COMPLEX, 0u,
                   0x700u, 0u, 0u, 0x800u,
                   0u, 0u, numeric, 0x434d4501u);
    tc_put_u32(desc, 0x40u, 1u);
    tc_put_u32(desc, 0x44u, 4u);
    tc_put_u32(desc, 0x48u, 4u);
    tc_put_u32(desc, 0x4cu, NPU_FUNC_SIGMOID);
    tc_put_u32(desc, 0x50u, 4u);
    tc_put_u32(desc, 0x5cu, 4u);
    tc_put_u32(desc, 0x6cu, NPU_MASK_NONE);
    tc_put_u32(desc, 0x70u, 0x3f800000u);
    tc_put_u32(desc, 0x7cu, 0x3f800000u);
    tc_put_u32(desc, 0x94u, 0xc1800000u);
    tc_put_u32(desc, 0x98u, 0x41800000u);
    desc[0x9du] = NPU_OVERFLOW_SATURATE;
    desc[0x9eu] = NPU_ALL_MASK_WRITE_ZERO;
}

static void tc_make_control_desc(
    uint8_t desc[NPU_WIRE_CONTROL_DESC_BYTES],
    uint8_t opcode,
    uint16_t event_a,
    uint16_t event_b,
    uint16_t event_out,
    uint8_t engine_mask,
    uint8_t join_mode,
    uint32_t user_tag)
{
    uint64_t src0 = 0u;
    uint64_t src1 = 0u;
    uint64_t dst = 0u;
    uint64_t aux0 = 0u;
    uint32_t op_flags = 0u;

    if (opcode == NPU_CTRL_EVENT_REARM ||
        opcode == NPU_CTRL_EVENT_JOIN) {
        src0 = event_a;
    }
    if (opcode == NPU_CTRL_EVENT_JOIN) {
        src1 = event_b;
        op_flags = (uint32_t)join_mode << 8;
    }
    if (opcode == NPU_CTRL_EVENT_SIGNAL ||
        opcode == NPU_CTRL_EVENT_REARM ||
        opcode == NPU_CTRL_EVENT_JOIN) {
        dst = event_out;
    }
    if (opcode == NPU_CTRL_GLOBAL_FENCE) {
        aux0 = engine_mask;
    }
    tc_make_common(desc, NPU_WIRE_CONTROL_DESC_BYTES,
                   NPU_ENGINE_CONTROL, op_flags,
                   src0, src1, 0u, dst, aux0, 0u,
                   0u, user_tag);
}

static void tc_make_cmd(uint64_t desc_addr,
                        uint16_t command_id,
                        npu_engine_t engine,
                        uint8_t opcode,
                        uint16_t header_flags,
                        uint16_t wait0,
                        uint16_t wait1,
                        uint16_t signal,
                        uint64_t *low,
                        uint64_t *high)
{
    *low = (desc_addr & UINT64_C(0x0000ffffffffffff)) |
           ((uint64_t)(command_id & 0x0fffu) << 48u) |
           ((uint64_t)((uint8_t)engine & 0x0fu) << 60u);
    *high = (uint64_t)opcode |
            ((uint64_t)(header_flags & 0x0fffu) << 8u) |
            ((uint64_t)(wait0 & 0x0fffu) << 20u) |
            ((uint64_t)(wait1 & 0x0fffu) << 32u) |
            ((uint64_t)(signal & 0x0fffu) << 44u) |
            (UINT64_C(1) << 56u);
}

static int tc_submit(npu_ts_cycle_t *model,
                     uint64_t low,
                     uint64_t high)
{
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;

    tc_idle_inputs(&inputs);
    inputs.cfe.valid = 1u;
    inputs.cfe.data = low;
    inputs.cfe.first = 1u;
    inputs.cfe.last = 0u;
    tc_step(model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 1u);

    tc_idle_inputs(&inputs);
    inputs.cfe.valid = 1u;
    inputs.cfe.data = high;
    inputs.cfe.first = 0u;
    inputs.cfe.last = 1u;
    tc_step(model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 1u);
    return 0;
}

static int tc_accept_dfu_request(npu_ts_cycle_t *model,
                                 uint64_t expected_addr,
                                 uint8_t expected_beats,
                                 uint16_t expected_tag)
{
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;

    tc_idle_inputs(&inputs);
    tc_step(model, &inputs, &outputs);
    TEST_CHECK(outputs.dfu.req_valid == 1u);
    TEST_CHECK(outputs.dfu.req_addr == expected_addr);
    TEST_CHECK(outputs.dfu.req_beats == expected_beats);
    TEST_CHECK(outputs.dfu.req_tag == expected_tag);
    TEST_CHECK(outputs.dfu.req_task_id == expected_tag);

    inputs.dfu.req_ready = 1u;
    tc_step(model, &inputs, &outputs);
    TEST_CHECK(outputs.dfu.req_valid == 1u);
    return 0;
}

static int tc_feed_dfu_words(npu_ts_cycle_t *model,
                             const uint8_t *desc,
                             uint8_t first_word,
                             uint8_t words,
                             uint16_t tag,
                             uint8_t first_status)
{
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint32_t word;

    for (word = 0u; word < words; word++) {
        tc_idle_inputs(&inputs);
        inputs.dfu.rsp_valid = 1u;
        inputs.dfu.rsp_data =
            tc_get_u64(desc,
                       (size_t)(first_word + word) * 8u);
        inputs.dfu.rsp_tag = tag;
        inputs.dfu.rsp_last =
            (uint8_t)(word + 1u == words);
        inputs.dfu.rsp_status =
            word == 0u ? first_status
                       : NPU_STATUS_SUCCESS;
        tc_step(model, &inputs, &outputs);
        TEST_CHECK(outputs.dfu.rsp_ready == 1u);
    }
    return 0;
}

static int tc_fetch(npu_ts_cycle_t *model,
                    const uint8_t *desc,
                    size_t bytes,
                    uint64_t desc_addr,
                    uint16_t tag)
{
    uint8_t remaining =
        (uint8_t)((bytes - NPU_WIRE_CONTROL_DESC_BYTES) / 8u);

    TC_CALL(tc_accept_dfu_request(model, desc_addr, 7u, tag));
    TC_CALL(tc_feed_dfu_words(model, desc, 0u, 8u, tag,
                              NPU_STATUS_SUCCESS));
    if (remaining != 0u) {
        TC_CALL(tc_accept_dfu_request(
            model, desc_addr + NPU_WIRE_CONTROL_DESC_BYTES,
            (uint8_t)(remaining - 1u), tag));
        TC_CALL(tc_feed_dfu_words(model, desc, 8u,
                                  remaining, tag,
                                  NPU_STATUS_SUCCESS));
    }
    return 0;
}

static int tc_wait_engine_request(
    npu_ts_cycle_t *model,
    uint8_t port,
    uint64_t *metadata)
{
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint32_t cycle;

    for (cycle = 0u; cycle < 12u; cycle++) {
        tc_idle_inputs(&inputs);
        tc_step(model, &inputs, &outputs);
        if (outputs.engine[port].req_valid != 0u) {
            *metadata = outputs.engine[port].req_data;
            return 0;
        }
    }
    return __LINE__;
}

static int tc_handshake_engine_request(
    npu_ts_cycle_t *model,
    uint8_t port,
    uint64_t expected_metadata)
{
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;

    tc_idle_inputs(&inputs);
    inputs.engine[port].req_ready = 1u;
    tc_step(model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[port].req_valid == 1u);
    TEST_CHECK(outputs.engine[port].req_data ==
               expected_metadata);
    return 0;
}

static int tc_send_done(npu_ts_cycle_t *model,
                        uint8_t port,
                        uint16_t task_id,
                        uint8_t engine,
                        uint8_t opcode,
                        uint8_t status,
                        uint32_t error_info,
                        uint16_t done_flags,
                        uint64_t fault_addr,
                        uint64_t progress)
{
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint64_t beat0 =
        (uint64_t)(task_id & 0x0fffu) |
        ((uint64_t)status << 12) |
        ((uint64_t)error_info << 20) |
        ((uint64_t)(done_flags & 0x0fffu) << 52);
    uint64_t beat1 =
        (fault_addr & UINT64_C(0x0000ffffffffffff)) |
        ((uint64_t)(engine & 0x0fu) << 48) |
        ((uint64_t)opcode << 52);

    tc_idle_inputs(&inputs);
    inputs.engine[port].done_valid = 1u;
    inputs.engine[port].done_first = 1u;
    inputs.engine[port].done_data = beat0;
    tc_step(model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[port].done_ready == 1u);

    tc_idle_inputs(&inputs);
    inputs.engine[port].done_valid = 1u;
    inputs.engine[port].done_data = beat1;
    tc_step(model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[port].done_ready == 1u);

    tc_idle_inputs(&inputs);
    inputs.engine[port].done_valid = 1u;
    inputs.engine[port].done_last = 1u;
    inputs.engine[port].done_data = progress;
    tc_step(model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[port].done_ready == 1u);
    return 0;
}

static int tc_wait_terminal(npu_ts_cycle_t *model,
                            uint16_t command_id,
                            uint8_t expected_status)
{
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint32_t cycle;

    for (cycle = 0u; cycle < 16u; cycle++) {
        tc_idle_inputs(&inputs);
        tc_step(model, &inputs, &outputs);
        if (outputs.terminal_valid != 0u &&
            outputs.terminal_task_id == command_id) {
            TEST_CHECK(outputs.terminal_status ==
                       expected_status);
            return 0;
        }
    }
    return __LINE__;
}

static int tc_wait_terminal_fault(npu_ts_cycle_t *model,
                                  uint16_t command_id,
                                  uint8_t expected_status,
                                  uint64_t expected_fault_addr,
                                  uint16_t expected_done_flags)
{
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint32_t cycle;

    for (cycle = 0u; cycle < 16u; cycle++) {
        tc_idle_inputs(&inputs);
        tc_step(model, &inputs, &outputs);
        if (outputs.terminal_valid != 0u &&
            outputs.terminal_task_id == command_id) {
            TEST_CHECK(outputs.terminal_status ==
                       expected_status);
            TEST_CHECK(outputs.terminal_fault_addr ==
                       expected_fault_addr);
            TEST_CHECK(outputs.terminal_done_flags ==
                       expected_done_flags);
            return 0;
        }
    }
    return __LINE__;
}

static int tc_test_resource_lookup_dfu(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint8_t desc[NPU_WIRE_DMA_DESC_BYTES];
    uint64_t low;
    uint64_t high;

    npu_ts_cycle_init(&model);
    tc_make_dma_desc(desc, 0x11223344u);
    tc_make_cmd(TC_DESC_ADDR, 0x123u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);

    TC_CALL(tc_submit(&model, low, high));
    TEST_CHECK(tc_task_count(&model) == 1u);
    TEST_CHECK(tc_desc_count(&model) == 1u);

    tc_idle_inputs(&inputs);
    inputs.cfe.lookup_valid = 1u;
    inputs.cfe.lookup_id = 0x123u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.lookup_ready == 1u);

    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.lookup_rsp_valid == 1u);
    TEST_CHECK(outputs.cfe.lookup_busy == 1u);
    TEST_CHECK(outputs.cfe.ready == 1u);

    TC_CALL(tc_fetch(&model, desc, sizeof(desc),
                     TC_DESC_ADDR, 0x123u));
    TEST_CHECK(model.desc_slot[
                   model.task[tc_find_slot(&model, 0x123u)]
                       .desc_slot]
                   .full == 1u);
    return 0;
}

static int tc_test_cfe_atomic_accept_and_abort(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint64_t low;
    uint64_t high;
    const npu_ts_task_entry_t *task;
    uint32_t slot;

    /* Both command beats carry explicit first/last framing. */
    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 60u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    tc_idle_inputs(&inputs);
    inputs.cfe.valid = 1u;
    inputs.cfe.data = low;
    inputs.cfe.first = 0u;
    inputs.cfe.last = 0u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 1u);
    TEST_CHECK(model.cfe_half_valid == 1u);

    tc_idle_inputs(&inputs);
    inputs.cfe.valid = 1u;
    inputs.cfe.data = high;
    inputs.cfe.first = 0u;
    inputs.cfe.last = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 1u);
    task = npu_ts_cycle_find_task(&model, 60u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_BAD_DESC);

    /* A command consumes one Task entry and one Descriptor slot atomically. */
    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 61u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TEST_CHECK(tc_task_count(&model) == 1u);
    TEST_CHECK(tc_desc_count(&model) == 1u);
    task = npu_ts_cycle_find_task(&model, 61u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->status == NPU_STATUS_BUSY);

    /* No command transfer is accepted without both free resource types. */
    npu_ts_cycle_init(&model);
    for (slot = 0u; slot < NPU_TS_TASK_COUNT; slot++) {
        model.task[slot].valid = 1u;
        model.task[slot].state = NPU_TS_TASK_RUNNING;
    }
    tc_idle_inputs(&inputs);
    inputs.cfe.valid = 1u;
    inputs.cfe.data = low;
    inputs.cfe.first = 1u;
    inputs.cfe.last = 0u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 0u);

    npu_ts_cycle_init(&model);
    for (slot = 0u; slot < NPU_TS_DESC_SLOT_COUNT; slot++) {
        model.desc_slot[slot].allocated = 1u;
    }
    tc_idle_inputs(&inputs);
    inputs.cfe.valid = 1u;
    inputs.cfe.data = low;
    inputs.cfe.first = 1u;
    inputs.cfe.last = 0u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 0u);

    /*
     * A complete command retained by CFE can arrive after controlled reset
     * starts. TS consumes it once and records ABORTED, including its output
     * event, so CFE can become idle without losing task identity.
     */
    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 63u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, tc_event(31u, 0u),
                &low, &high);
    tc_idle_inputs(&inputs);
    inputs.stop_accept = 1u;
    inputs.quiesce_req = 1u;
    inputs.abort_req = 1u;
    inputs.cfe.valid = 1u;
    inputs.cfe.data = low;
    inputs.cfe.first = 1u;
    inputs.cfe.last = 0u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 1u);
    TEST_CHECK(model.cfe_half_valid == 1u);

    tc_idle_inputs(&inputs);
    inputs.stop_accept = 1u;
    inputs.quiesce_req = 1u;
    inputs.abort_req = 1u;
    inputs.cfe.valid = 1u;
    inputs.cfe.data = high;
    inputs.cfe.first = 0u;
    inputs.cfe.last = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 1u);
    task = npu_ts_cycle_find_task(&model, 63u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_ABORTED);
    TEST_CHECK(model.event[31u].state == NPU_TS_EVENT_RESERVED);

    tc_idle_inputs(&inputs);
    inputs.stop_accept = 1u;
    inputs.quiesce_req = 1u;
    inputs.abort_req = 1u;
    tc_step(&model, &inputs, &outputs);
    task = npu_ts_cycle_find_task(&model, 63u);
    TEST_CHECK(task->state == NPU_TS_TASK_ABORTED);
    TEST_CHECK(model.event[31u].state == NPU_TS_EVENT_ERROR);

    tc_idle_inputs(&inputs);
    inputs.stop_accept = 1u;
    inputs.quiesce_req = 1u;
    inputs.abort_req = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.terminal_valid == 1u);
    TEST_CHECK(outputs.terminal_task_id == 63u);
    TEST_CHECK(outputs.terminal_status == NPU_STATUS_ABORTED);
    TEST_CHECK(outputs.terminal_done_flags ==
               NPU_DONE_ABORT_DRAINED);

    /* Quiesce terminates a command whose second beat is still pending. */
    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 62u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    tc_idle_inputs(&inputs);
    inputs.cfe.valid = 1u;
    inputs.cfe.data = low;
    inputs.cfe.first = 1u;
    inputs.cfe.last = 0u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 1u);
    TEST_CHECK(model.cfe_half_valid == 1u);

    tc_idle_inputs(&inputs);
    inputs.quiesce_req = 1u;
    inputs.cfe.valid = 1u;
    inputs.cfe.data = high;
    inputs.cfe.first = 0u;
    inputs.cfe.last = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 1u);
    task = npu_ts_cycle_find_task(&model, 62u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_ABORTED);

    /*
     * ready is independent of a duplicate command_id carried on the
     * current payload. The duplicate is checked only after transfer.
     */
    npu_ts_cycle_init(&model);
    TC_CALL(tc_submit(&model, low, high));
    tc_idle_inputs(&inputs);
    inputs.cfe.valid = 1u;
    inputs.cfe.data = low;
    inputs.cfe.first = 1u;
    inputs.cfe.last = 0u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 1u);
    inputs.cfe.data = high;
    inputs.cfe.first = 0u;
    inputs.cfe.last = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe.ready == 1u);
    TEST_CHECK(tc_task_count(&model) == 2u);
    return 0;
}

static int tc_test_engine_desc_done_ack(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint8_t desc[NPU_WIRE_DMA_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    uint64_t metadata;
    uint64_t held_data;
    uint8_t task_slot;
    uint8_t desc_slot;
    const npu_ts_task_entry_t *task;
    uint32_t cycle;

    npu_ts_cycle_init(&model);
    tc_make_dma_desc(desc, 0xa1b2c3d4u);
    tc_make_cmd(TC_DESC_ADDR, 7u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D,
                NPU_TS_FLAG_IRQ_ON_SUCCESS |
                    NPU_TS_FLAG_IRQ_ON_ERROR,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, desc, sizeof(desc),
                     TC_DESC_ADDR, 7u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TEST_CHECK((metadata & 0x0fffu) == 7u);
    TEST_CHECK(((metadata >> 12) & 0xffu) ==
               NPU_DMA_COPY_1D);
    TEST_CHECK((metadata >> 44) == 0u);

    for (cycle = 0u; cycle < 3u; cycle++) {
        tc_idle_inputs(&inputs);
        tc_step(&model, &inputs, &outputs);
        TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].req_valid ==
                   1u);
        TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].req_data ==
                   metadata);
    }
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));
    task_slot = tc_find_slot(&model, 7u);
    TEST_CHECK(task_slot != NPU_TS_INVALID_INDEX);
    desc_slot = model.task[task_slot].desc_slot;

    tc_idle_inputs(&inputs);
    inputs.desc[NPU_TS_PORT_DMA].req_valid = 1u;
    inputs.desc[NPU_TS_PORT_DMA].req_slot = desc_slot;
    inputs.desc[NPU_TS_PORT_DMA].req_word = 0u;
    inputs.desc[NPU_TS_PORT_DMA].req_tag = 3u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].req_ready == 1u);

    tc_idle_inputs(&inputs);
    inputs.desc[NPU_TS_PORT_DMA].req_valid = 1u;
    inputs.desc[NPU_TS_PORT_DMA].req_slot = desc_slot;
    inputs.desc[NPU_TS_PORT_DMA].req_word = 1u;
    inputs.desc[NPU_TS_PORT_DMA].req_tag = 3u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_valid == 1u);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_tag == 3u);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_data ==
               tc_get_u64(desc, 0u));
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].req_ready == 1u);
    held_data = outputs.desc[NPU_TS_PORT_DMA].rsp_data;

    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_valid == 1u);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_data ==
               held_data);

    tc_idle_inputs(&inputs);
    inputs.desc[NPU_TS_PORT_DMA].rsp_ready = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_valid == 1u);

    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_valid == 1u);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_tag == 3u);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_status == 3u);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_data == 0u);
    tc_idle_inputs(&inputs);
    inputs.desc[NPU_TS_PORT_DMA].rsp_ready = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_valid == 1u);

    TEST_CHECK(npu_ts_cycle_inject_desc_ecc(
                   &model, desc_slot, 1u, 2u) == 1);
    tc_idle_inputs(&inputs);
    inputs.desc[NPU_TS_PORT_DMA].req_valid = 1u;
    inputs.desc[NPU_TS_PORT_DMA].req_slot = desc_slot;
    inputs.desc[NPU_TS_PORT_DMA].req_word = 1u;
    inputs.desc[NPU_TS_PORT_DMA].req_tag = 4u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].req_ready == 1u);
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_valid == 1u);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_status == 2u);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_data == 0u);
    tc_idle_inputs(&inputs);
    inputs.desc[NPU_TS_PORT_DMA].rsp_ready = 1u;
    tc_step(&model, &inputs, &outputs);

    TC_CALL(tc_send_done(&model, NPU_TS_PORT_DMA, 7u,
                         NPU_ENGINE_DMA, NPU_DMA_COPY_1D,
                         NPU_STATUS_SUCCESS, 0u, 0u, 0u,
                         8u));
    task = npu_ts_cycle_find_task(&model, 7u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);

    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    task = npu_ts_cycle_find_task(&model, 7u);
    TEST_CHECK(task->state == NPU_TS_TASK_SUCCESS);
    TEST_CHECK(outputs.terminal_valid == 0u);

    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.terminal_valid == 1u);
    TEST_CHECK(outputs.terminal_task_id == 7u);
    TEST_CHECK(outputs.terminal_status == NPU_STATUS_SUCCESS);
    TEST_CHECK(outputs.terminal_engine == NPU_ENGINE_DMA);
    TEST_CHECK(outputs.terminal_opcode == NPU_DMA_COPY_1D);
    TEST_CHECK(outputs.terminal_fault_addr == 0u);
    TEST_CHECK(outputs.terminal_error_info == 0u);
    TEST_CHECK(outputs.terminal_done_flags == 0u);
    TEST_CHECK(outputs.terminal_irq_on_success == 1u);
    TEST_CHECK(outputs.terminal_irq_on_error == 1u);
    TEST_CHECK(outputs.irq_success_pulse == 1u);
    TEST_CHECK(outputs.irq_error_pulse == 0u);

    tc_idle_inputs(&inputs);
    inputs.ctl.valid = 1u;
    inputs.ctl.op = NPU_TS_CTL_QUERY;
    inputs.ctl.rs1 = 7u;
    inputs.ctl.rs2 = NPU_TS_QUERY_ACK;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.ctl.ready == 1u);

    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.ctl.rsp_valid == 1u);
    TEST_CHECK(outputs.ctl.rsp_data == 0u);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 7u) !=
               (const npu_ts_task_entry_t *)0);
    held_data = outputs.ctl.rsp_data;

    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.ctl.rsp_valid == 1u);
    TEST_CHECK(outputs.ctl.rsp_data == held_data);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 7u) !=
               (const npu_ts_task_entry_t *)0);

    tc_idle_inputs(&inputs);
    inputs.ctl.rsp_ready = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.ctl.rsp_valid == 1u);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 7u) ==
               (const npu_ts_task_entry_t *)0);
    return 0;
}

static int tc_test_dfu_error(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint8_t desc[NPU_WIRE_DMA_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    const npu_ts_task_entry_t *task;

    npu_ts_cycle_init(&model);
    tc_make_dma_desc(desc, 0u);
    tc_make_cmd(TC_DESC_ADDR, 8u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, NPU_TS_FLAG_IRQ_ON_ERROR,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_accept_dfu_request(&model, TC_DESC_ADDR, 7u, 8u));
    TC_CALL(tc_feed_dfu_words(
        &model, desc, 0u, 8u, 8u, NPU_STATUS_BUS_DECERR));
    TEST_CHECK(model.dfu.valid == 0u);
    task = npu_ts_cycle_find_task(&model, 8u);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);

    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    task = npu_ts_cycle_find_task(&model, 8u);
    TEST_CHECK(task->state == NPU_TS_TASK_ERROR);
    TEST_CHECK(task->status == NPU_STATUS_BUS_DECERR);
    TEST_CHECK(task->error_info ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_BUS_DECERR,
                   NPU_DMA_COPY_1D));
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.terminal_valid == 1u);
    TEST_CHECK(outputs.terminal_status == NPU_STATUS_BUS_DECERR);
    TEST_CHECK(outputs.terminal_error_info ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_BUS_DECERR,
                   NPU_DMA_COPY_1D));
    TEST_CHECK(outputs.terminal_irq_on_error == 1u);
    TEST_CHECK(outputs.irq_error_pulse == 1u);
    TEST_CHECK(outputs.dfu.req_valid == 0u);
    return 0;
}

static int tc_test_dfu_status_encodings(void)
{
    uint8_t desc[NPU_WIRE_DMA_DESC_BYTES];
    uint16_t status_value;

    tc_make_dma_desc(desc, 0u);
    for (status_value = 0u; status_value <= UINT8_MAX;
         status_value++) {
        npu_ts_cycle_t model;
        npu_ts_cycle_inputs_t inputs;
        npu_ts_cycle_outputs_t outputs;
        const npu_ts_task_entry_t *task;
        uint64_t low;
        uint64_t high;
        uint32_t word;
        uint8_t status = (uint8_t)status_value;
        uint8_t legal =
            status <= NPU_STATUS_ADDR_OVERLAP ? 1u : 0u;

        npu_ts_cycle_init(&model);
        tc_make_cmd(TC_DESC_ADDR, 0x5au, NPU_ENGINE_DMA,
                    NPU_DMA_COPY_1D, 0u,
                    TC_NONE, TC_NONE, TC_NONE, &low, &high);
        TC_CALL(tc_submit(&model, low, high));
        TC_CALL(tc_accept_dfu_request(
            &model, TC_DESC_ADDR, 7u, 0x5au));

        for (word = 0u; word < 8u; word++) {
            tc_idle_inputs(&inputs);
            inputs.dfu.rsp_valid = 1u;
            inputs.dfu.rsp_data =
                tc_get_u64(desc, (size_t)word * 8u);
            inputs.dfu.rsp_tag = 0x5au;
            inputs.dfu.rsp_last =
                (uint8_t)(word == 7u);
            inputs.dfu.rsp_status =
                word == 0u ? status : NPU_STATUS_SUCCESS;
            tc_step(&model, &inputs, &outputs);
            TEST_CHECK(outputs.dfu.rsp_ready == 1u);
            if (word == 0u && legal == 0u) {
                TEST_CHECK(model.dfu.first_status ==
                           NPU_STATUS_BAD_DESC);
                TEST_CHECK(
                    model.dfu.first_error_info ==
                    tc_error_info(
                        NPU_TS_ERROR_STAGE_DESC_PORT,
                        status, NPU_DMA_COPY_1D));
            }
        }

        task = npu_ts_cycle_find_task(&model, 0x5au);
        TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
        if (status == NPU_STATUS_SUCCESS) {
            TEST_CHECK(task->state == NPU_TS_TASK_FETCH_DESC);
            TEST_CHECK(model.dfu.valid != 0u);
            TEST_CHECK(model.dfu.first_status ==
                       NPU_STATUS_SUCCESS);
        } else {
            uint8_t expected =
                legal != 0u ? status : NPU_STATUS_BAD_DESC;

            TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
            TEST_CHECK(task->status == expected);
            if (legal != 0u) {
                TEST_CHECK(
                    task->error_info ==
                    tc_error_info(
                        NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                        expected, NPU_DMA_COPY_1D));
            } else {
                TEST_CHECK(
                    task->error_info ==
                    tc_error_info(
                        NPU_TS_ERROR_STAGE_DESC_PORT,
                        status, NPU_DMA_COPY_1D));
            }
        }
    }
    return 0;
}

static int tc_test_decode_fault_addresses(void)
{
    npu_ts_cycle_t model;
    uint8_t desc[NPU_WIRE_VECTOR_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    const npu_ts_task_entry_t *task;
    uint64_t gaddr_limit =
        (uint64_t)TC_DESC_ADDR + 0x80u;

    npu_ts_cycle_init(&model);
    model.wire_limits.gaddr_limit = gaddr_limit;
    tc_make_cmd(TC_DESC_ADDR, 0x321u, NPU_ENGINE_VECTOR,
                NPU_VECTOR_ADD, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    task = npu_ts_cycle_find_task(&model, 0x321u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(task->fault_addr == gaddr_limit);
    TEST_CHECK(task->done_flags == 0u);
    TEST_CHECK(task->meta.fault_valid == 1u);
    TEST_CHECK(task->meta.fault_space == NPU_SPACE_DDR);
    TC_CALL(tc_wait_terminal_fault(
        &model, 0x321u, NPU_STATUS_ADDR_FAULT,
        gaddr_limit, 0u));

    npu_ts_cycle_init(&model);
    model.wire_limits.l1_bytes = 0x1000u;
    tc_make_vector_desc(desc);
    tc_put_u32(desc, 0x40u, 2u);
    tc_put_u64(desc, 0x20u, 0x0ffcu);
    tc_make_cmd(TC_DESC_ADDR, 0x322u, NPU_ENGINE_VECTOR,
                NPU_VECTOR_ADD, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, desc, sizeof(desc),
                     TC_DESC_ADDR, 0x322u));
    task = npu_ts_cycle_find_task(&model, 0x322u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(task->fault_addr == 0x1000u);
    TEST_CHECK(task->done_flags ==
               NPU_DONE_FAULT_ADDR_IS_L1);
    TEST_CHECK(task->meta.fault_valid == 1u);
    TEST_CHECK(task->meta.fault_space == NPU_SPACE_L1);
    TC_CALL(tc_wait_terminal_fault(
        &model, 0x322u, NPU_STATUS_ADDR_FAULT,
        0x1000u, NPU_DONE_FAULT_ADDR_IS_L1));
    return 0;
}

static int tc_test_all_engine_ports(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint8_t matrix_desc[NPU_WIRE_MATRIX_DESC_BYTES];
    uint8_t vector_desc[NPU_WIRE_VECTOR_DESC_BYTES];
    uint8_t complex_desc[NPU_WIRE_COMPLEX_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    uint64_t metadata;

    npu_ts_cycle_init(&model);
    tc_make_matrix_desc(matrix_desc);
    tc_make_vector_desc(vector_desc);
    tc_make_complex_desc(complex_desc);

    tc_make_cmd(0x2000u, 40u, NPU_ENGINE_MATRIX,
                NPU_MATRIX_GEMM, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, matrix_desc, sizeof(matrix_desc),
                     0x2000u, 40u));

    tc_make_cmd(0x2200u, 41u, NPU_ENGINE_VECTOR,
                NPU_VECTOR_ADD, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, vector_desc, sizeof(vector_desc),
                     0x2200u, 41u));

    tc_make_cmd(0x2400u, 42u, NPU_ENGINE_COMPLEX,
                NPU_COMPLEX_ACT, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, complex_desc,
                     sizeof(complex_desc), 0x2400u, 42u));

    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_MATRIX, &metadata));
    TEST_CHECK((metadata & 0x0fffu) == 40u);
    TEST_CHECK(((metadata >> 12) & 0xffu) ==
               NPU_MATRIX_GEMM);
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_VECTOR, &metadata));
    TEST_CHECK((metadata & 0x0fffu) == 41u);
    TEST_CHECK(((metadata >> 12) & 0xffu) ==
               NPU_VECTOR_ADD);
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_COMPLEX, &metadata));
    TEST_CHECK((metadata & 0x0fffu) == 42u);
    TEST_CHECK(((metadata >> 12) & 0xffu) ==
               NPU_COMPLEX_ACT);

    tc_idle_inputs(&inputs);
    inputs.desc[NPU_TS_PORT_DMA].req_valid = 1u;
    inputs.desc[NPU_TS_PORT_DMA].req_slot =
        model.task[tc_find_slot(&model, 40u)].desc_slot;
    inputs.desc[NPU_TS_PORT_DMA].req_word = 0u;
    inputs.desc[NPU_TS_PORT_DMA].req_tag = 0u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].req_ready == 1u);
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_valid == 1u);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_status == 3u);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_data == 0u);
    tc_idle_inputs(&inputs);
    inputs.desc[NPU_TS_PORT_DMA].rsp_ready = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_valid == 1u);

    tc_idle_inputs(&inputs);
    inputs.desc[NPU_TS_PORT_DMA].req_valid = 1u;
    inputs.desc[NPU_TS_PORT_DMA].req_slot = 0xffu;
    inputs.desc[NPU_TS_PORT_DMA].req_word = 0x3fu;
    inputs.desc[NPU_TS_PORT_DMA].req_tag = 0x1fu;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].req_ready == 1u);
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_valid == 1u);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_tag == 0x0fu);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_status == 3u);
    TEST_CHECK(outputs.desc[NPU_TS_PORT_DMA].rsp_data == 0u);

    tc_idle_inputs(&inputs);
    inputs.abort_req = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_MATRIX].abort == 1u);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_VECTOR].abort == 1u);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_COMPLEX].abort == 1u);
    return 0;
}

static int tc_test_protocol_errors(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint8_t desc[NPU_WIRE_DMA_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    uint64_t metadata;
    uint64_t query_result;
    const npu_ts_task_entry_t *task;

    npu_ts_cycle_init(&model);
    tc_make_dma_desc(desc, 0u);
    tc_make_cmd(TC_DESC_ADDR, 43u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, desc, sizeof(desc),
                     TC_DESC_ADDR, 43u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));

    tc_idle_inputs(&inputs);
    inputs.engine[NPU_TS_PORT_DMA].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_first = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_data =
        43u |
        ((uint64_t)NPU_STATUS_BUS_SLVERR << 12) |
        (UINT64_C(0x55) << 20) |
        ((uint64_t)NPU_DONE_PARTIAL_DEST << 52);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].done_ready == 1u);
    task = npu_ts_cycle_find_task(&model, 43u);
    TEST_CHECK(task->state == NPU_TS_TASK_RUNNING);
    TEST_CHECK(model.done_rx[NPU_TS_PORT_DMA].status ==
               NPU_STATUS_BUS_SLVERR);

    tc_idle_inputs(&inputs);
    inputs.engine[NPU_TS_PORT_DMA].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_first = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_last = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_data =
        UINT64_C(0x123450) |
        ((uint64_t)NPU_ENGINE_VECTOR << 48) |
        ((uint64_t)NPU_VECTOR_ADD << 52) |
        (UINT64_C(0xf) << 60);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].done_ready == 1u);
    task = npu_ts_cycle_find_task(&model, 43u);
    TEST_CHECK(task->state == NPU_TS_TASK_RUNNING);
    TEST_CHECK(model.engine_active_task[NPU_TS_PORT_DMA] !=
               NPU_TS_INVALID_INDEX);
    TEST_CHECK(model.done_rx[NPU_TS_PORT_DMA].beat == 2u);
    TEST_CHECK(model.done_rx[NPU_TS_PORT_DMA].status ==
               NPU_STATUS_BUS_SLVERR);

    tc_idle_inputs(&inputs);
    inputs.engine[NPU_TS_PORT_DMA].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_data = 4u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].done_ready == 1u);
    TEST_CHECK((outputs.done_protocol_error_mask &
                (1u << NPU_TS_PORT_DMA)) != 0u);
    TEST_CHECK(outputs.done_protocol_error_count[
                   NPU_TS_PORT_DMA] == 1u);
    task = npu_ts_cycle_find_task(&model, 43u);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(task->error_info == 0x55u);
    TEST_CHECK(task->done_flags == NPU_DONE_PARTIAL_DEST);
    TEST_CHECK(task->fault_addr == 0x123450u);
    TEST_CHECK(model.engine_active_task[NPU_TS_PORT_DMA] ==
               NPU_TS_INVALID_INDEX);

    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK((outputs.done_protocol_error_mask &
                (1u << NPU_TS_PORT_DMA)) != 0u);
    TEST_CHECK(outputs.done_protocol_error_count[
                   NPU_TS_PORT_DMA] == 2u);
    task = npu_ts_cycle_find_task(&model, 43u);
    TEST_CHECK(task->state == NPU_TS_TASK_ERROR);
    TEST_CHECK(task->status == NPU_STATUS_BUS_SLVERR);

    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 44u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_accept_dfu_request(
        &model, TC_DESC_ADDR, 7u, 44u));
    tc_idle_inputs(&inputs);
    inputs.dfu.rsp_valid = 1u;
    inputs.dfu.rsp_data = tc_get_u64(desc, 0u);
    inputs.dfu.rsp_tag = 44u;
    inputs.dfu.rsp_last = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.dfu.rsp_ready == 1u);
    task = npu_ts_cycle_find_task(&model, 44u);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_BAD_DESC);
    TEST_CHECK(task->error_info ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_BAD_DESC,
                   NPU_DMA_COPY_1D));
    TEST_CHECK(model.dfu.valid == 0u);

    /*
     * A legal non-success status with a zero error_info is retained, but
     * the port reports a protocol error and TS supplies its own record.
     */
    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 45u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, desc, sizeof(desc),
                     TC_DESC_ADDR, 45u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));

    tc_idle_inputs(&inputs);
    inputs.engine[NPU_TS_PORT_DMA].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_first = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_data =
        45u |
        ((uint64_t)NPU_STATUS_BUS_SLVERR << 12) |
        ((uint64_t)NPU_DONE_PARTIAL_DEST << 52);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].done_ready == 1u);
    TEST_CHECK(outputs.done_protocol_error_mask == 0u);
    TEST_CHECK(model.done_rx[NPU_TS_PORT_DMA].status ==
               NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(model.done_rx[NPU_TS_PORT_DMA].error_info ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_BUS_SLVERR,
                   NPU_DMA_COPY_1D));

    tc_idle_inputs(&inputs);
    inputs.engine[NPU_TS_PORT_DMA].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_data =
        ((uint64_t)NPU_ENGINE_DMA << 48) |
        ((uint64_t)NPU_DMA_COPY_1D << 52);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK((outputs.done_protocol_error_mask &
                (1u << NPU_TS_PORT_DMA)) != 0u);
    TEST_CHECK(outputs.done_protocol_error_count[
                   NPU_TS_PORT_DMA] == 1u);

    tc_idle_inputs(&inputs);
    inputs.engine[NPU_TS_PORT_DMA].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_last = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_data = 5u;
    tc_step(&model, &inputs, &outputs);
    task = npu_ts_cycle_find_task(&model, 45u);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(task->error_info ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_BUS_SLVERR,
                   NPU_DMA_COPY_1D));
    TEST_CHECK(task->done_flags == NPU_DONE_PARTIAL_DEST);

    TC_CALL(tc_query(&model, 45u, NPU_TS_QUERY_ERROR_INFO,
                     &query_result));
    TEST_CHECK(query_result ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_BUS_SLVERR,
                   NPU_DMA_COPY_1D));
    TC_CALL(tc_query(&model, 45u, NPU_TS_QUERY_DONE_FLAGS,
                     &query_result));
    TEST_CHECK(query_result == NPU_DONE_PARTIAL_DEST);
    TC_CALL(tc_query(&model, 45u, NPU_TS_QUERY_RESERVED,
                     &query_result));
    TEST_CHECK(query_result == NPU_STATUS_BAD_DESC);
    TC_CALL(tc_query(&model, 0x0ffeu,
                     NPU_TS_QUERY_RESERVED, &query_result));
    TEST_CHECK(query_result == NPU_STATUS_BAD_DESC);
    return 0;
}

static int tc_test_scheduler_generated_error_info(void)
{
    npu_ts_cycle_t model;
    uint8_t control_desc[NPU_WIRE_CONTROL_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    const npu_ts_task_entry_t *task;
    uint16_t missing_event = tc_event(99u, 0u);
    uint16_t rearm_old = tc_event(5u, 0u);
    uint16_t rearm_new = tc_event(5u, 1u);

    /* A command with an unsupported header version is rejected. */
    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 50u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(
        &model, low, high | (UINT64_C(2) << 56u)));
    task = npu_ts_cycle_find_task(&model, 50u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_BAD_DESC);
    TEST_CHECK(task->error_info ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_BAD_DESC,
                   NPU_DMA_COPY_1D));

    /* Opcode validation is owned by TS before descriptor fetch starts. */
    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 51u, NPU_ENGINE_DMA,
                0xffu, 0u, TC_NONE, TC_NONE, TC_NONE,
                &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    task = npu_ts_cycle_find_task(&model, 51u);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_ILLEGAL_OPCODE);
    TEST_CHECK(task->error_info ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_ILLEGAL_OPCODE, 0xffu));

    /* Waiting on an unreserved event is a CMD resource error. */
    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 52u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                missing_event, TC_NONE, TC_NONE,
                &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    task = npu_ts_cycle_find_task(&model, 52u);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_BAD_DESC);
    TEST_CHECK(task->error_info ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_BAD_DESC,
                   NPU_DMA_COPY_1D));

    /*
     * EVENT_REARM reaches the Control executor, then fails because the old
     * event is free instead of terminal.
     */
    npu_ts_cycle_init(&model);
    tc_make_control_desc(
        control_desc, NPU_CTRL_EVENT_REARM,
        rearm_old, 0u, rearm_new, 0u, 0u, 0u);
    tc_make_cmd(TC_DESC_ADDR, 53u, NPU_ENGINE_CONTROL,
                NPU_CTRL_EVENT_REARM, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, control_desc,
                     sizeof(control_desc), TC_DESC_ADDR, 53u));
    TC_CALL(tc_wait_terminal(&model, 53u,
                             NPU_STATUS_BAD_DESC));
    task = npu_ts_cycle_find_task(&model, 53u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_ERROR);
    TEST_CHECK(task->error_info ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_BAD_DESC,
                   NPU_CTRL_EVENT_REARM));
    return 0;
}

static int tc_test_internal_event_rearm(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint8_t desc[NPU_WIRE_CONTROL_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    uint16_t event0 = tc_event(5u, 0u);
    uint16_t event1 = tc_event(5u, 1u);

    npu_ts_cycle_init(&model);
    tc_make_control_desc(desc, NPU_CTRL_EVENT_SIGNAL,
                         0u, 0u, event0, 0u, 0u,
                         0x55667788u);
    tc_make_cmd(TC_DESC_ADDR, 9u, NPU_ENGINE_CONTROL,
                NPU_CTRL_EVENT_SIGNAL, 0u,
                TC_NONE, TC_NONE, event0, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TEST_CHECK(model.event[5u].state ==
               NPU_TS_EVENT_RESERVED);
    TC_CALL(tc_fetch(&model, desc, sizeof(desc),
                     TC_DESC_ADDR, 9u));
    TC_CALL(tc_wait_terminal(&model, 9u,
                             NPU_STATUS_SUCCESS));
    TEST_CHECK(model.event[5u].state ==
               NPU_TS_EVENT_SUCCESS);

    tc_make_control_desc(desc, NPU_CTRL_EVENT_REARM,
                         event0, 0u, event1, 0u, 0u, 0u);
    tc_make_cmd(TC_DESC_ADDR + 0x40u, 10u,
                NPU_ENGINE_CONTROL, NPU_CTRL_EVENT_REARM,
                0u, TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, desc, sizeof(desc),
                     TC_DESC_ADDR + 0x40u, 10u));
    TC_CALL(tc_wait_terminal(&model, 10u,
                             NPU_STATUS_SUCCESS));
    TEST_CHECK(model.event[5u].state == NPU_TS_EVENT_FREE);
    TEST_CHECK(model.event[5u].generation == 1u);

    /*
     * The software control interface supplies an 8-bit Event ID.  TS
     * captures the event's current generation when WAIT is accepted.
     */
    model.event[5u].state = NPU_TS_EVENT_RESERVED;
    model.event[5u].producer_task_id = 77u;
    tc_idle_inputs(&inputs);
    inputs.ctl.valid = 1u;
    inputs.ctl.op = NPU_TS_CTL_WAIT;
    inputs.ctl.rs1 = 5u;
    inputs.ctl.rs2 = 10u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.ctl.ready == 1u);
    TEST_CHECK(model.ctl.active == 1u);
    TEST_CHECK(model.ctl.wait_event == event1);
    TEST_CHECK(model.event[5u].waiter_count == 1u);

    tc_idle_inputs(&inputs);
    inputs.ctl.cancel = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(model.ctl.active == 0u);
    TEST_CHECK(model.event[5u].waiter_count == 0u);
    return 0;
}

static int tc_test_event_failure_and_ordered(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint8_t dma_desc[NPU_WIRE_DMA_DESC_BYTES];
    uint8_t ctl_desc[NPU_WIRE_CONTROL_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    uint64_t metadata;
    uint16_t event0 = tc_event(20u, 0u);
    uint16_t event1 = tc_event(21u, 0u);
    const npu_ts_task_entry_t *task;

    npu_ts_cycle_init(&model);
    tc_make_dma_desc(dma_desc, 0u);
    tc_make_cmd(TC_DESC_ADDR, 11u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, event0, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, dma_desc, sizeof(dma_desc),
                     TC_DESC_ADDR, 11u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));

    tc_make_cmd(TC_DESC_ADDR + 0x100u, 12u,
                NPU_ENGINE_DMA, NPU_DMA_COPY_1D, 0u,
                event0, TC_NONE, event1, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TEST_CHECK(model.event[20u].waiter_count == 1u);
    TEST_CHECK(model.event[21u].state ==
               NPU_TS_EVENT_RESERVED);
    TC_CALL(tc_fetch(&model, dma_desc, sizeof(dma_desc),
                     TC_DESC_ADDR + 0x100u, 12u));

    TC_CALL(tc_send_done(
        &model, NPU_TS_PORT_DMA, 11u,
        NPU_ENGINE_DMA, NPU_DMA_COPY_1D,
        NPU_STATUS_BUS_SLVERR, 0x1234u,
        NPU_DONE_PARTIAL_DEST, 0x123450u, 4u));
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(model.event[20u].state ==
               NPU_TS_EVENT_ERROR);
    task = npu_ts_cycle_find_task(&model, 12u);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    task = npu_ts_cycle_find_task(&model, 12u);
    TEST_CHECK(task->state ==
               NPU_TS_TASK_DEPENDENCY_FAILED);
    TEST_CHECK(task->status == NPU_STATUS_DEPENDENCY_FAILED);
    TEST_CHECK(task->error_info ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_DEPENDENCY_FAILED,
                   NPU_DMA_COPY_1D));
    TEST_CHECK(model.event[21u].state ==
               NPU_TS_EVENT_ERROR);
    TEST_CHECK(model.event[20u].waiter_count == 0u);

    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 13u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, dma_desc, sizeof(dma_desc),
                     TC_DESC_ADDR, 13u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));

    tc_make_control_desc(ctl_desc, NPU_CTRL_NOP,
                         0u, 0u, 0u, 0u, 0u, 0u);
    tc_make_cmd(TC_DESC_ADDR + 0x100u, 14u,
                NPU_ENGINE_CONTROL, NPU_CTRL_NOP,
                NPU_TS_FLAG_ORDERED,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, ctl_desc, sizeof(ctl_desc),
                     TC_DESC_ADDR + 0x100u, 14u));
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    task = npu_ts_cycle_find_task(&model, 14u);
    TEST_CHECK(task->state == NPU_TS_TASK_READY);

    tc_make_cmd(TC_DESC_ADDR + 0x140u, 15u,
                NPU_ENGINE_CONTROL, NPU_CTRL_NOP, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, ctl_desc, sizeof(ctl_desc),
                     TC_DESC_ADDR + 0x140u, 15u));
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 14u)->state ==
               NPU_TS_TASK_READY);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 15u)->state ==
               NPU_TS_TASK_READY);

    TC_CALL(tc_send_done(&model, NPU_TS_PORT_DMA, 13u,
                         NPU_ENGINE_DMA, NPU_DMA_COPY_1D,
                         NPU_STATUS_SUCCESS, 0u, 0u, 0u, 8u));
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 14u)->state ==
               NPU_TS_TASK_COMMIT);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 15u)->state ==
               NPU_TS_TASK_READY);
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 14u)->state ==
               NPU_TS_TASK_SUCCESS);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 15u)->state ==
               NPU_TS_TASK_COMMIT);
    return 0;
}

static int tc_test_global_fence_zero_mask(void)
{
    npu_ts_cycle_t model;
    uint8_t dma_desc[NPU_WIRE_DMA_DESC_BYTES];
    uint8_t fence_desc[NPU_WIRE_CONTROL_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    uint64_t metadata;
    uint16_t fence_event = tc_event(40u, 0u);
    const npu_ts_task_entry_t *dma_task;
    const npu_ts_task_entry_t *fence_task;

    /*
     * Keep an older DMA task active. A zero Engine mask must still make
     * GLOBAL_FENCE complete immediately.
     */
    npu_ts_cycle_init(&model);
    tc_make_dma_desc(dma_desc, 0u);
    tc_make_cmd(TC_DESC_ADDR, 70u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, dma_desc, sizeof(dma_desc),
                     TC_DESC_ADDR, 70u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));

    tc_make_control_desc(
        fence_desc, NPU_CTRL_GLOBAL_FENCE,
        0u, 0u, 0u, 0u, 0u, 0x46454e30u);
    tc_make_cmd(TC_DESC_ADDR + 0x100u, 71u,
                NPU_ENGINE_CONTROL, NPU_CTRL_GLOBAL_FENCE,
                0u, TC_NONE, TC_NONE, fence_event,
                &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    fence_task = npu_ts_cycle_find_task(&model, 71u);
    TEST_CHECK(fence_task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(fence_task->fence_target_count == 1u);
    TEST_CHECK(model.event[40u].state ==
               NPU_TS_EVENT_RESERVED);

    TC_CALL(tc_fetch(&model, fence_desc, sizeof(fence_desc),
                     TC_DESC_ADDR + 0x100u, 71u));
    TC_CALL(tc_wait_terminal(&model, 71u,
                             NPU_STATUS_SUCCESS));

    dma_task = npu_ts_cycle_find_task(&model, 70u);
    fence_task = npu_ts_cycle_find_task(&model, 71u);
    TEST_CHECK(dma_task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(dma_task->state == NPU_TS_TASK_RUNNING);
    TEST_CHECK(fence_task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(fence_task->state == NPU_TS_TASK_SUCCESS);
    TEST_CHECK(fence_task->status == NPU_STATUS_SUCCESS);
    TEST_CHECK(model.event[40u].state ==
               NPU_TS_EVENT_SUCCESS);
    TEST_CHECK(model.event[40u].error_status ==
               NPU_STATUS_SUCCESS);
    return 0;
}

static int tc_test_global_fence_subset_snapshot(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint8_t dma_desc[NPU_WIRE_DMA_DESC_BYTES];
    uint8_t matrix_desc[NPU_WIRE_MATRIX_DESC_BYTES];
    uint8_t fence_desc[NPU_WIRE_CONTROL_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    uint64_t metadata;
    uint16_t fence_event = tc_event(41u, 0u);
    const npu_ts_task_entry_t *task;

    npu_ts_cycle_init(&model);
    tc_make_dma_desc(dma_desc, 0u);
    tc_make_matrix_desc(matrix_desc);

    tc_make_cmd(TC_DESC_ADDR, 72u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, dma_desc, sizeof(dma_desc),
                     TC_DESC_ADDR, 72u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));

    tc_make_cmd(TC_DESC_ADDR + 0x100u, 73u,
                NPU_ENGINE_MATRIX, NPU_MATRIX_GEMM, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, matrix_desc, sizeof(matrix_desc),
                     TC_DESC_ADDR + 0x100u, 73u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_MATRIX, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_MATRIX, metadata));

    /*
     * Select Matrix only. The older DMA task is intentionally left active
     * and must not delay this Fence.
     */
    tc_make_control_desc(
        fence_desc, NPU_CTRL_GLOBAL_FENCE,
        0u, 0u, 0u, 1u << NPU_TS_PORT_MATRIX,
        0u, 0x46454e31u);
    tc_make_cmd(TC_DESC_ADDR + 0x200u, 74u,
                NPU_ENGINE_CONTROL, NPU_CTRL_GLOBAL_FENCE,
                0u, TC_NONE, TC_NONE, fence_event,
                &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    task = npu_ts_cycle_find_task(&model, 74u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->fence_target_count == 2u);
    TC_CALL(tc_fetch(&model, fence_desc, sizeof(fence_desc),
                     TC_DESC_ADDR + 0x200u, 74u));
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 74u)->state ==
               NPU_TS_TASK_RUNNING);

    /*
     * Submit another Matrix task after the Fence CMD. It uses a selected
     * engine, but its greater submit_seq is outside the saved task set.
     */
    tc_make_cmd(TC_DESC_ADDR + 0x300u, 75u,
                NPU_ENGINE_MATRIX, NPU_MATRIX_GEMM, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, matrix_desc, sizeof(matrix_desc),
                     TC_DESC_ADDR + 0x300u, 75u));
    TEST_CHECK(npu_ts_cycle_find_task(&model, 75u)->state ==
               NPU_TS_TASK_CHECK_DESC);

    /*
     * The older Matrix completion is a three-beat message. Beat 0 and
     * Beat 1 do not make the saved target terminal.
     */
    tc_idle_inputs(&inputs);
    inputs.engine[NPU_TS_PORT_MATRIX].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_MATRIX].done_first = 1u;
    inputs.engine[NPU_TS_PORT_MATRIX].done_data = 73u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_MATRIX].done_ready ==
               1u);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 74u)->state ==
               NPU_TS_TASK_RUNNING);
    TEST_CHECK(model.event[41u].state ==
               NPU_TS_EVENT_RESERVED);

    tc_idle_inputs(&inputs);
    inputs.engine[NPU_TS_PORT_MATRIX].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_MATRIX].done_data =
        ((uint64_t)NPU_ENGINE_MATRIX << 48) |
        ((uint64_t)NPU_MATRIX_GEMM << 52);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_MATRIX].done_ready ==
               1u);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 74u)->state ==
               NPU_TS_TASK_RUNNING);

    tc_idle_inputs(&inputs);
    inputs.engine[NPU_TS_PORT_MATRIX].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_MATRIX].done_last = 1u;
    inputs.engine[NPU_TS_PORT_MATRIX].done_data = 2u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_MATRIX].done_ready ==
               1u);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 73u)->state ==
               NPU_TS_TASK_COMMIT);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 74u)->state ==
               NPU_TS_TASK_RUNNING);

    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 74u)->state ==
               NPU_TS_TASK_COMMIT);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 72u)->state ==
               NPU_TS_TASK_RUNNING);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 75u)->state ==
               NPU_TS_TASK_READY);
    TEST_CHECK(model.event[41u].state ==
               NPU_TS_EVENT_RESERVED);

    TC_CALL(tc_wait_terminal(&model, 74u,
                             NPU_STATUS_SUCCESS));
    TEST_CHECK(model.event[41u].state ==
               NPU_TS_EVENT_SUCCESS);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 72u)->state ==
               NPU_TS_TASK_RUNNING);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 75u)->state ==
               NPU_TS_TASK_READY);
    return 0;
}

static int tc_test_global_fence_failure_order(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint8_t dma_desc[NPU_WIRE_DMA_DESC_BYTES];
    uint8_t matrix_desc[NPU_WIRE_MATRIX_DESC_BYTES];
    uint8_t fence_desc[NPU_WIRE_CONTROL_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    uint64_t metadata;
    uint64_t beat0;
    uint64_t query_result;
    uint16_t fence_event = tc_event(42u, 0u);
    uint8_t dma_slot;
    uint8_t matrix_slot;
    const npu_ts_task_entry_t *fence_task;

    npu_ts_cycle_init(&model);
    tc_make_dma_desc(dma_desc, 0u);
    tc_make_matrix_desc(matrix_desc);

    /*
     * Retain a finished task in slot 0 while the older DMA task takes
     * slot 1. Releasing slot 0 before submitting Matrix makes task-table
     * order differ from submit_seq order.
     */
    tc_make_control_desc(
        fence_desc, NPU_CTRL_NOP,
        0u, 0u, 0u, 0u, 0u, 0x534c4f54u);
    tc_make_cmd(TC_DESC_ADDR + 0x400u, 68u,
                NPU_ENGINE_CONTROL, NPU_CTRL_NOP, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, fence_desc, sizeof(fence_desc),
                     TC_DESC_ADDR + 0x400u, 68u));
    TC_CALL(tc_wait_terminal(&model, 68u,
                             NPU_STATUS_SUCCESS));

    tc_make_cmd(TC_DESC_ADDR, 76u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    dma_slot = tc_find_slot(&model, 76u);
    TEST_CHECK(dma_slot == 1u);
    TC_CALL(tc_fetch(&model, dma_desc, sizeof(dma_desc),
                     TC_DESC_ADDR, 76u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));

    TC_CALL(tc_query(&model, 68u, NPU_TS_QUERY_ACK,
                     &query_result));
    TEST_CHECK(query_result == 0u);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 68u) ==
               (const npu_ts_task_entry_t *)0);

    tc_make_cmd(TC_DESC_ADDR + 0x100u, 77u,
                NPU_ENGINE_MATRIX, NPU_MATRIX_GEMM, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    matrix_slot = tc_find_slot(&model, 77u);
    TEST_CHECK(matrix_slot == 0u);
    TEST_CHECK(matrix_slot < dma_slot);
    TC_CALL(tc_fetch(&model, matrix_desc, sizeof(matrix_desc),
                     TC_DESC_ADDR + 0x100u, 77u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_MATRIX, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_MATRIX, metadata));

    tc_make_control_desc(
        fence_desc, NPU_CTRL_GLOBAL_FENCE,
        0u, 0u, 0u,
        (1u << NPU_TS_PORT_DMA) |
            (1u << NPU_TS_PORT_MATRIX),
        0u, 0x46454e32u);
    tc_make_cmd(TC_DESC_ADDR + 0x200u, 78u,
                NPU_ENGINE_CONTROL, NPU_CTRL_GLOBAL_FENCE,
                0u, TC_NONE, TC_NONE, fence_event,
                &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    fence_task = npu_ts_cycle_find_task(&model, 78u);
    TEST_CHECK(fence_task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(fence_task->fence_target_count == 2u);
    TEST_CHECK(fence_task->fence_target[0].submit_seq >
               fence_task->fence_target[1].submit_seq);
    TC_CALL(tc_fetch(&model, fence_desc, sizeof(fence_desc),
                     TC_DESC_ADDR + 0x200u, 78u));
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 78u)->state ==
               NPU_TS_TASK_RUNNING);

    /*
     * Finish the later Matrix task first with ADDR_FAULT. The Fence must
     * continue to wait for the earlier DMA task.
     */
    TC_CALL(tc_send_done(
        &model, NPU_TS_PORT_MATRIX, 77u,
        NPU_ENGINE_MATRIX, NPU_MATRIX_GEMM,
        NPU_STATUS_ADDR_FAULT, 0x770004u,
        NPU_DONE_FAULT_ADDR_IS_L1, 0x2a0u, 2u));
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 78u)->state ==
               NPU_TS_TASK_RUNNING);
    TEST_CHECK(model.event[42u].state ==
               NPU_TS_EVENT_RESERVED);

    /*
     * Check every beat of the earlier DMA failure. The status is visible
     * to GLOBAL_FENCE only after all three beats have been received and
     * the DMA task has entered its final state.
     */
    beat0 = 76u |
            ((uint64_t)NPU_STATUS_BUS_SLVERR << 12) |
            ((uint64_t)0x760006u << 20) |
            ((uint64_t)NPU_DONE_PARTIAL_DEST << 52);
    tc_idle_inputs(&inputs);
    inputs.engine[NPU_TS_PORT_DMA].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_first = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_data = beat0;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].done_ready == 1u);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 78u)->state ==
               NPU_TS_TASK_RUNNING);
    TEST_CHECK(model.event[42u].state ==
               NPU_TS_EVENT_RESERVED);

    tc_idle_inputs(&inputs);
    inputs.engine[NPU_TS_PORT_DMA].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_data =
        UINT64_C(0x0000000000000340) |
        ((uint64_t)NPU_ENGINE_DMA << 48) |
        ((uint64_t)NPU_DMA_COPY_1D << 52);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].done_ready == 1u);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 78u)->state ==
               NPU_TS_TASK_RUNNING);

    tc_idle_inputs(&inputs);
    inputs.engine[NPU_TS_PORT_DMA].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_last = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_data = 4u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].done_ready == 1u);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 76u)->state ==
               NPU_TS_TASK_COMMIT);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 78u)->state ==
               NPU_TS_TASK_RUNNING);

    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    fence_task = npu_ts_cycle_find_task(&model, 78u);
    TEST_CHECK(fence_task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(fence_task->status == NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(fence_task->error_info ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_BUS_SLVERR,
                   NPU_CTRL_GLOBAL_FENCE));
    TEST_CHECK(model.event[42u].state ==
               NPU_TS_EVENT_RESERVED);

    TC_CALL(tc_wait_terminal(&model, 78u,
                             NPU_STATUS_BUS_SLVERR));
    fence_task = npu_ts_cycle_find_task(&model, 78u);
    TEST_CHECK(fence_task->state == NPU_TS_TASK_ERROR);
    TEST_CHECK(fence_task->status == NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(model.event[42u].state == NPU_TS_EVENT_ERROR);
    TEST_CHECK(model.event[42u].error_status ==
               NPU_STATUS_BUS_SLVERR);
    return 0;
}

static int tc_test_global_fence_timeout(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint8_t dma_desc[NPU_WIRE_DMA_DESC_BYTES];
    uint8_t fence_desc[NPU_WIRE_CONTROL_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    uint64_t metadata;
    uint16_t fence_event = tc_event(43u, 0u);
    const npu_ts_task_entry_t *fence_task;
    uint32_t cycle;

    npu_ts_cycle_init(&model);
    tc_make_dma_desc(dma_desc, 0u);
    tc_make_cmd(TC_DESC_ADDR, 79u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, 0u,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, dma_desc, sizeof(dma_desc),
                     TC_DESC_ADDR, 79u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));

    tc_make_control_desc(
        fence_desc, NPU_CTRL_GLOBAL_FENCE,
        0u, 0u, 0u, 1u << NPU_TS_PORT_DMA,
        0u, 0x46454e33u);
    tc_make_cmd(TC_DESC_ADDR + 0x100u, 80u,
                NPU_ENGINE_CONTROL, NPU_CTRL_GLOBAL_FENCE,
                (uint16_t)(1u << 6),
                TC_NONE, TC_NONE, fence_event,
                &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, fence_desc, sizeof(fence_desc),
                     TC_DESC_ADDR + 0x100u, 80u));

    tc_idle_inputs(&inputs);
    inputs.timeout_cycles[1u] = 2u;
    tc_step(&model, &inputs, &outputs);
    fence_task = npu_ts_cycle_find_task(&model, 80u);
    TEST_CHECK(fence_task->state == NPU_TS_TASK_RUNNING);

    for (cycle = 0u; cycle < 2u; cycle++) {
        tc_idle_inputs(&inputs);
        inputs.timeout_cycles[1u] = 2u;
        tc_step(&model, &inputs, &outputs);
        TEST_CHECK(npu_ts_cycle_find_task(&model, 80u)->state ==
                   NPU_TS_TASK_RUNNING);
        TEST_CHECK(model.event[43u].state ==
                   NPU_TS_EVENT_RESERVED);
    }

    tc_idle_inputs(&inputs);
    inputs.timeout_cycles[1u] = 2u;
    tc_step(&model, &inputs, &outputs);
    fence_task = npu_ts_cycle_find_task(&model, 80u);
    TEST_CHECK(fence_task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(fence_task->status == NPU_STATUS_TIMEOUT);
    TEST_CHECK(fence_task->error_info ==
               tc_error_info(
                   NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                   NPU_STATUS_TIMEOUT,
                   NPU_CTRL_GLOBAL_FENCE));
    TEST_CHECK(model.event[43u].state ==
               NPU_TS_EVENT_RESERVED);

    TC_CALL(tc_wait_terminal(&model, 80u,
                             NPU_STATUS_TIMEOUT));
    fence_task = npu_ts_cycle_find_task(&model, 80u);
    TEST_CHECK(fence_task->state == NPU_TS_TASK_TIMEOUT);
    TEST_CHECK(model.event[43u].state == NPU_TS_EVENT_ERROR);
    TEST_CHECK(model.event[43u].error_status ==
               NPU_STATUS_TIMEOUT);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 79u)->state ==
               NPU_TS_TASK_RUNNING);
    return 0;
}

static int tc_test_timeout_ctl_abort_reset(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint8_t desc[NPU_WIRE_DMA_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    uint64_t metadata;
    uint16_t event0 = tc_event(30u, 0u);
    const npu_ts_task_entry_t *task;
    uint32_t cycle;

    npu_ts_cycle_init(&model);
    tc_make_dma_desc(desc, 0u);
    tc_make_cmd(TC_DESC_ADDR, 16u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, (uint16_t)(1u << 6),
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, desc, sizeof(desc),
                     TC_DESC_ADDR, 16u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));

    for (cycle = 0u; cycle < 2u; cycle++) {
        tc_idle_inputs(&inputs);
        inputs.timeout_cycles[1u] = 2u;
        tc_step(&model, &inputs, &outputs);
        TEST_CHECK(npu_ts_cycle_find_task(&model, 16u)->state ==
                   NPU_TS_TASK_RUNNING);
        TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].cancel_valid ==
                   0u);
    }
    tc_idle_inputs(&inputs);
    inputs.timeout_cycles[1u] = 2u;
    inputs.engine[NPU_TS_PORT_DMA].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_first = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_data = 16u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].done_ready == 1u);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].cancel_valid == 0u);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 16u)->state ==
               NPU_TS_TASK_RUNNING);
    TEST_CHECK(model.cancel[NPU_TS_PORT_DMA].phase ==
               NPU_TS_CANCEL_IDLE);

    tc_idle_inputs(&inputs);
    inputs.timeout_cycles[1u] = 2u;
    inputs.engine[NPU_TS_PORT_DMA].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_data =
        ((uint64_t)NPU_ENGINE_DMA << 48) |
        ((uint64_t)NPU_DMA_COPY_1D << 52);
    tc_step(&model, &inputs, &outputs);
    tc_idle_inputs(&inputs);
    inputs.timeout_cycles[1u] = 2u;
    inputs.engine[NPU_TS_PORT_DMA].done_valid = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_last = 1u;
    inputs.engine[NPU_TS_PORT_DMA].done_data = 8u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 16u)->state ==
               NPU_TS_TASK_COMMIT);
    TC_CALL(tc_wait_terminal(&model, 16u,
                             NPU_STATUS_SUCCESS));

    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 17u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, (uint16_t)(1u << 6),
                TC_NONE, TC_NONE, event0, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, desc, sizeof(desc),
                     TC_DESC_ADDR, 17u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));

    tc_idle_inputs(&inputs);
    inputs.ctl.valid = 1u;
    inputs.ctl.op = NPU_TS_CTL_WAIT;
    inputs.ctl.rs1 = event0;
    inputs.ctl.rs2 = 10u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.ctl.ready == 1u);
    TEST_CHECK(model.ctl.active == 1u);
    TEST_CHECK(model.event[30u].waiter_count == 1u);
    tc_idle_inputs(&inputs);
    inputs.ctl.cancel = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(model.ctl.active == 0u);
    TEST_CHECK(model.event[30u].waiter_count == 0u);

    tc_idle_inputs(&inputs);
    inputs.ctl.valid = 1u;
    inputs.ctl.op = NPU_TS_CTL_FENCE;
    inputs.ctl.rs1 = 1u;
    inputs.ctl.rs2 = 10u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(model.ctl.active == 1u);
    tc_idle_inputs(&inputs);
    inputs.ctl.cancel = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(model.ctl.active == 0u);

    /*
     * TIMEOUT_CLASS is a live input. It was zero during the control
     * interface checks above, so no timeout could be retained inside TS.
     * Enabling class 1 now must be observed directly on this edge.
     */
    tc_idle_inputs(&inputs);
    inputs.timeout_cycles[1u] = 2u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].cancel_valid == 0u);
    TEST_CHECK(model.cancel[NPU_TS_PORT_DMA].phase ==
               NPU_TS_CANCEL_REQUEST);
    task = npu_ts_cycle_find_task(&model, 17u);
    TEST_CHECK(task->state == NPU_TS_TASK_RUNNING);
    TEST_CHECK(model.engine_active_task[NPU_TS_PORT_DMA] !=
               NPU_TS_INVALID_INDEX);

    /* Backpressure must hold the cancel request and its status stable. */
    for (cycle = 0u; cycle < 2u; cycle++) {
        tc_idle_inputs(&inputs);
        inputs.timeout_cycles[1u] = 2u;
        tc_step(&model, &inputs, &outputs);
        TEST_CHECK(
            outputs.engine[NPU_TS_PORT_DMA].cancel_valid == 1u);
        TEST_CHECK(
            outputs.engine[NPU_TS_PORT_DMA].cancel_status ==
            NPU_STATUS_TIMEOUT);
        TEST_CHECK(
            outputs.engine[NPU_TS_PORT_DMA].done_ready == 1u);
        TEST_CHECK(npu_ts_cycle_find_task(&model, 17u)->state ==
                   NPU_TS_TASK_RUNNING);
        TEST_CHECK(model.engine_active_task[NPU_TS_PORT_DMA] !=
                   NPU_TS_INVALID_INDEX);
    }

    tc_idle_inputs(&inputs);
    inputs.timeout_cycles[1u] = 2u;
    inputs.engine[NPU_TS_PORT_DMA].cancel_ready = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].cancel_valid == 1u);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].cancel_status ==
               NPU_STATUS_TIMEOUT);
    TEST_CHECK(model.cancel[NPU_TS_PORT_DMA].phase ==
               NPU_TS_CANCEL_WAIT_DONE);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 17u)->state ==
               NPU_TS_TASK_RUNNING);

    tc_idle_inputs(&inputs);
    inputs.timeout_cycles[1u] = 2u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].cancel_valid == 0u);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].done_ready == 1u);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 17u)->state ==
               NPU_TS_TASK_RUNNING);

    TC_CALL(tc_send_done(
        &model, NPU_TS_PORT_DMA, 17u, NPU_ENGINE_DMA,
        NPU_DMA_COPY_1D, NPU_STATUS_TIMEOUT, 0x4009ff01u,
        0u, 0u, 0u));
    task = npu_ts_cycle_find_task(&model, 17u);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_TIMEOUT);
    TEST_CHECK(model.engine_active_task[NPU_TS_PORT_DMA] ==
               NPU_TS_INVALID_INDEX);
    TEST_CHECK(model.cancel[NPU_TS_PORT_DMA].phase ==
               NPU_TS_CANCEL_IDLE);
    TC_CALL(tc_wait_terminal(&model, 17u,
                             NPU_STATUS_TIMEOUT));
    TEST_CHECK(model.event[30u].state ==
               NPU_TS_EVENT_ERROR);

    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 18u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, NPU_TS_FLAG_IRQ_ON_ERROR,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, desc, sizeof(desc),
                     TC_DESC_ADDR, 18u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));

    tc_idle_inputs(&inputs);
    inputs.abort_req = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].abort == 1u);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 18u)->state ==
               NPU_TS_TASK_COMMIT);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 18u)->error_info ==
               tc_error_info(NPU_TS_ERROR_STAGE_ABORT,
                             NPU_STATUS_ABORTED,
                             NPU_DMA_COPY_1D));
    tc_idle_inputs(&inputs);
    inputs.abort_req = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(npu_ts_cycle_find_task(&model, 18u)->state ==
               NPU_TS_TASK_ABORTED);
    tc_idle_inputs(&inputs);
    inputs.abort_req = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.quiescent == 0u);
    TEST_CHECK(outputs.idle == 0u);
    TEST_CHECK(outputs.terminal_valid == 1u);
    TEST_CHECK(outputs.terminal_status == NPU_STATUS_ABORTED);
    TEST_CHECK(outputs.terminal_error_info ==
               tc_error_info(NPU_TS_ERROR_STAGE_ABORT,
                             NPU_STATUS_ABORTED,
                             NPU_DMA_COPY_1D));
    TEST_CHECK(outputs.terminal_done_flags ==
               NPU_DONE_ABORT_DRAINED);
    tc_idle_inputs(&inputs);
    inputs.abort_req = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.quiescent == 1u);

    tc_idle_inputs(&inputs);
    inputs.reset_n = 0u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.idle == 0u);
    tc_idle_inputs(&inputs);
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.idle == 1u);
    TEST_CHECK(outputs.task_slots_used == 0u);
    TEST_CHECK(outputs.desc_slots_used == 0u);
    return 0;
}

static int tc_test_mif_reset_abort(void)
{
    npu_ts_cycle_t model;
    npu_ts_cycle_inputs_t inputs;
    npu_ts_cycle_outputs_t outputs;
    uint8_t desc[NPU_WIRE_DMA_DESC_BYTES];
    uint64_t low;
    uint64_t high;
    uint64_t metadata;
    const npu_ts_task_entry_t *task;

    /*
     * Interrupt descriptor fetch after the request handshake. The missing
     * response must not leave DFU in drain mode because the transport reset
     * has already discarded it.
     */
    npu_ts_cycle_init(&model);
    tc_make_dma_desc(desc, 0u);
    tc_make_cmd(TC_DESC_ADDR, 0x221u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, NPU_TS_FLAG_IRQ_ON_ERROR,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_accept_dfu_request(
        &model, TC_DESC_ADDR, 7u, 0x221u));
    TEST_CHECK(model.dfu.valid != 0u);
    TEST_CHECK(model.dfu.waiting_response != 0u);

    tc_idle_inputs(&inputs);
    inputs.mif_reset_abort = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.dfu.req_valid == 0u);
    TEST_CHECK(outputs.dfu.rsp_ready == 0u);
    TEST_CHECK(model.dfu.valid == 0u);
    task = npu_ts_cycle_find_task(&model, 0x221u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_ABORTED);
    TEST_CHECK(task->error_info ==
               tc_error_info(NPU_TS_ERROR_STAGE_ABORT,
                             NPU_STATUS_ABORTED,
                             NPU_DMA_COPY_1D));
    TEST_CHECK(task->done_flags == NPU_DONE_ABORT_DRAINED);
    TC_CALL(tc_wait_terminal_fault(
        &model, 0x221u, NPU_STATUS_ABORTED, 0u,
        NPU_DONE_ABORT_DRAINED));

    /*
     * Interrupt a DMA task after dispatch. The emergency event clears TS's
     * active-owner state immediately and asserts the DMA abort output on the
     * same call; no cancel or done handshake is required.
     */
    npu_ts_cycle_init(&model);
    tc_make_cmd(TC_DESC_ADDR, 0x222u, NPU_ENGINE_DMA,
                NPU_DMA_COPY_1D, NPU_TS_FLAG_IRQ_ON_ERROR,
                TC_NONE, TC_NONE, TC_NONE, &low, &high);
    TC_CALL(tc_submit(&model, low, high));
    TC_CALL(tc_fetch(&model, desc, sizeof(desc),
                     TC_DESC_ADDR, 0x222u));
    TC_CALL(tc_wait_engine_request(
        &model, NPU_TS_PORT_DMA, &metadata));
    TC_CALL(tc_handshake_engine_request(
        &model, NPU_TS_PORT_DMA, metadata));
    TEST_CHECK(model.engine_active_task[NPU_TS_PORT_DMA] !=
               NPU_TS_INVALID_INDEX);

    tc_idle_inputs(&inputs);
    inputs.mif_reset_abort = 1u;
    tc_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].abort == 1u);
    TEST_CHECK(outputs.engine[NPU_TS_PORT_DMA].req_valid == 0u);
    TEST_CHECK(model.engine_active_task[NPU_TS_PORT_DMA] ==
               NPU_TS_INVALID_INDEX);
    TEST_CHECK(model.cancel[NPU_TS_PORT_DMA].phase ==
               NPU_TS_CANCEL_IDLE);
    task = npu_ts_cycle_find_task(&model, 0x222u);
    TEST_CHECK(task != (const npu_ts_task_entry_t *)0);
    TEST_CHECK(task->state == NPU_TS_TASK_COMMIT);
    TEST_CHECK(task->status == NPU_STATUS_ABORTED);
    TEST_CHECK(task->error_info ==
               tc_error_info(NPU_TS_ERROR_STAGE_ABORT,
                             NPU_STATUS_ABORTED,
                             NPU_DMA_COPY_1D));
    TEST_CHECK(task->done_flags == NPU_DONE_ABORT_DRAINED);
    TC_CALL(tc_wait_terminal_fault(
        &model, 0x222u, NPU_STATUS_ABORTED, 0u,
        NPU_DONE_ABORT_DRAINED));
    return 0;
}

static int tc_test_complete_idle_query(void)
{
    npu_ts_cycle_t model;

    npu_ts_cycle_init(&model);
    TEST_CHECK(npu_ts_cycle_idle(&model) != 0);

    model.task[0].valid = 1u;
    model.task[0].state = NPU_TS_TASK_WAIT_EVENT;
    TEST_CHECK(npu_ts_cycle_idle(&model) == 0);
    model.task[0].state = NPU_TS_TASK_SUCCESS;
    TEST_CHECK(npu_ts_cycle_idle(&model) == 0);
    model.task[0].valid = 0u;

    model.dfu.valid = 1u;
    TEST_CHECK(npu_ts_cycle_idle(&model) == 0);
    model.dfu.valid = 0u;
    model.ctl.active = 1u;
    TEST_CHECK(npu_ts_cycle_idle(&model) == 0);
    model.ctl.active = 0u;
    model.desc_port[0].count = 1u;
    TEST_CHECK(npu_ts_cycle_idle(&model) == 0);
    model.desc_port[0].count = 0u;
    model.terminal_notice_count = 1u;
    TEST_CHECK(npu_ts_cycle_idle(&model) == 0);
    model.terminal_notice_count = 0u;

    TEST_CHECK(npu_ts_cycle_idle(&model) != 0);
    TEST_CHECK(npu_ts_cycle_idle(
                   (const npu_ts_cycle_t *)0) == 0);
    return 0;
}

int test_ts_cycle(void)
{
    TC_CALL(tc_test_resource_lookup_dfu());
    TC_CALL(tc_test_cfe_atomic_accept_and_abort());
    TC_CALL(tc_test_engine_desc_done_ack());
    TC_CALL(tc_test_dfu_error());
    TC_CALL(tc_test_dfu_status_encodings());
    TC_CALL(tc_test_decode_fault_addresses());
    TC_CALL(tc_test_all_engine_ports());
    TC_CALL(tc_test_protocol_errors());
    TC_CALL(tc_test_scheduler_generated_error_info());
    TC_CALL(tc_test_internal_event_rearm());
    TC_CALL(tc_test_event_failure_and_ordered());
    TC_CALL(tc_test_global_fence_zero_mask());
    TC_CALL(tc_test_global_fence_subset_snapshot());
    TC_CALL(tc_test_global_fence_failure_order());
    TC_CALL(tc_test_global_fence_timeout());
    TC_CALL(tc_test_timeout_ctl_abort_reset());
    TC_CALL(tc_test_mif_reset_abort());
    TC_CALL(tc_test_complete_idle_query());
    return 0;
}

#ifdef NPU_TS_CYCLE_STANDALONE
int main(void)
{
    return test_ts_cycle();
}
#endif
