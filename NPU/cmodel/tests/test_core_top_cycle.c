#include "npu_core_top_cycle.h"
#include "test_util.h"

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define TOP_TEST_MEMORY_BYTES (64u * 1024u)
#define TOP_TEST_DESC_ADDR UINT64_C(0x1000)
#define TOP_TEST_SRC0 0x0100u
#define TOP_TEST_SRC1 0x0200u
#define TOP_TEST_DST 0x0300u
#define TOP_TEST_COMMAND 0x321u
#define TOP_TEST_TIMEOUT_COMMAND 0x322u
#define TOP_TEST_RESET_COMMAND 0x323u
#define TOP_TEST_VECTOR_PORT NPU_TS_PORT_VECTOR
#define TOP_TEST_MAX_CYCLES 10000u

#define TOP_TEST_CALL(expression)       \
    do {                                \
        int top_test_line = (expression); \
        if (top_test_line != 0) {       \
            return top_test_line;       \
        }                               \
    } while (0)

typedef struct {
    const uint8_t *descriptor;
    size_t descriptor_bytes;
    uint64_t descriptor_addr;

    uint8_t active;
    uint64_t active_addr;
    uint16_t active_tag;
    uint16_t active_beats;
    uint16_t active_beat;

    uint8_t held_request;
    uint64_t held_addr;
    uint8_t held_beats;
    uint16_t held_tag;
    uint16_t held_task_id;
    uint8_t held_attr;

    uint32_t request_count;
    uint32_t response_count;
    uint32_t request_stalls;
    uint32_t response_stalls;
    uint64_t cycle;
} top_test_dfu_t;

typedef struct {
    uint8_t l1[TOP_TEST_MEMORY_BYTES];
    uint8_t ddr[TOP_TEST_MEMORY_BYTES];
    uint8_t descriptor[NPU_WIRE_VECTOR_DESC_BYTES];
    npu_model_t functional;
    npu_core_top_cycle_t top;
    top_test_dfu_t dfu;
} top_test_env_t;

static top_test_env_t top_test_env;
static uint8_t
    top_test_top_snapshot[sizeof(npu_core_top_cycle_t)];

static void top_test_put_u16(uint8_t *data,
                             size_t offset,
                             uint16_t value)
{
    data[offset] = (uint8_t)value;
    data[offset + 1u] = (uint8_t)(value >> 8);
}

static void top_test_put_u32(uint8_t *data,
                             size_t offset,
                             uint32_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 4u; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static void top_test_put_u64(uint8_t *data,
                             size_t offset,
                             uint64_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < NPU_REF_BUS_BYTES; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static uint64_t top_test_get_u64(const uint8_t *data,
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

static uint32_t top_test_numeric(void)
{
    return (uint32_t)NPU_DTYPE_INT8 |
           ((uint32_t)NPU_DTYPE_INT8 << 2u) |
           ((uint32_t)NPU_DTYPE_INT8 << 6u) |
           (UINT32_C(1) << 12u) |
           ((uint32_t)NPU_SCALE_PER_TENSOR << 13u);
}

static void top_test_make_vector_descriptor(
    uint8_t descriptor[NPU_WIRE_VECTOR_DESC_BYTES])
{
    (void)memset(descriptor, 0, NPU_WIRE_VECTOR_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_VECTOR;
    top_test_put_u16(descriptor, 0x02u,
                     NPU_WIRE_VECTOR_DESC_BYTES);
    top_test_put_u32(descriptor, 0x04u, 0u);
    top_test_put_u64(descriptor, 0x08u, TOP_TEST_SRC0);
    top_test_put_u64(descriptor, 0x10u, TOP_TEST_SRC1);
    top_test_put_u64(descriptor, 0x20u, TOP_TEST_DST);
    top_test_put_u32(descriptor, 0x38u, top_test_numeric());
    top_test_put_u32(descriptor, 0x3cu, 0x544f5031u);

    top_test_put_u32(descriptor, 0x40u, 1u);
    top_test_put_u32(descriptor, 0x44u, 4u);
    top_test_put_u32(descriptor, 0x48u, 4u);
    top_test_put_u32(descriptor, 0x50u, 1u);
    top_test_put_u32(descriptor, 0x54u, 4u);
    top_test_put_u32(descriptor, 0x58u, 1u);
    top_test_put_u32(descriptor, 0x5cu, 4u);
    top_test_put_u32(descriptor, 0x68u, 1u);
    top_test_put_u32(descriptor, 0x6cu, 4u);
    descriptor[0x78u] = 0u;
    descriptor[0x79u] = NPU_COMPARE_EQ;
    descriptor[0x7au] = NPU_OVERFLOW_SATURATE;
    descriptor[0x7bu] = 0u;
    top_test_put_u32(descriptor, 0x80u, 0x3f800000u);
    top_test_put_u32(descriptor, 0x84u, 0x3f800000u);
    top_test_put_u32(descriptor, 0x88u, 0u);
    top_test_put_u32(descriptor, 0x8cu, 0x3f800000u);
}

static void top_test_idle_inputs(
    npu_core_top_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = 1u;
    inputs->l1_idle_i = 1u;
    inputs->l1_write_idle_i = 1u;
    inputs->mif_idle_i = 1u;
    inputs->gc_axi_idle_i = 1u;
}

static int top_test_env_init(uint32_t timeout_class_1)
{
    npu_config_t config;
    npu_wire_limits_t limits;
    npu_lsc_cycle_config_t lsc_config;

    (void)memset(&top_test_env, 0, sizeof(top_test_env));
    npu_config_reference(&config);
    config.l1_bytes = TOP_TEST_MEMORY_BYTES;
    config.timeout_cycles[1u] = timeout_class_1;
    TEST_CHECK_STATUS(
        npu_model_init(
            &top_test_env.functional, &config,
            top_test_env.l1, sizeof(top_test_env.l1),
            top_test_env.ddr, sizeof(top_test_env.ddr)),
        NPU_STATUS_SUCCESS);

    npu_wire_limits_reference(&limits);
    limits.l1_bytes = TOP_TEST_MEMORY_BYTES;
    limits.gaddr_limit = TOP_TEST_MEMORY_BYTES;
    npu_lsc_cycle_config_reference(&lsc_config);
    lsc_config.l1_bytes = TOP_TEST_MEMORY_BYTES;
    lsc_config.l1_config =
        (lsc_config.l1_config & ~NPU_LSC_FIELD_U32_MASK) |
        TOP_TEST_MEMORY_BYTES;
    lsc_config.timeout_reset[1u] = timeout_class_1;
    TEST_CHECK_STATUS(
        npu_core_top_cycle_init(
            &top_test_env.top, &top_test_env.functional,
            &limits, &lsc_config),
        NPU_STATUS_SUCCESS);

    top_test_make_vector_descriptor(top_test_env.descriptor);
    top_test_env.dfu.descriptor = top_test_env.descriptor;
    top_test_env.dfu.descriptor_bytes =
        sizeof(top_test_env.descriptor);
    top_test_env.dfu.descriptor_addr =
        TOP_TEST_DESC_ADDR;
    return 0;
}

static int top_test_rejects_inconsistent_capabilities(void)
{
    npu_config_t config;
    npu_wire_limits_t limits;
    npu_lsc_cycle_config_t lsc_config;

    (void)memset(&top_test_env, 0, sizeof(top_test_env));
    npu_config_reference(&config);
    config.l1_bytes = TOP_TEST_MEMORY_BYTES;
    TEST_CHECK_STATUS(
        npu_model_init(
            &top_test_env.functional, &config,
            top_test_env.l1, sizeof(top_test_env.l1),
            top_test_env.ddr, sizeof(top_test_env.ddr)),
        NPU_STATUS_SUCCESS);
    npu_wire_limits_reference(&limits);
    limits.l1_bytes = TOP_TEST_MEMORY_BYTES;
    limits.gaddr_limit = TOP_TEST_MEMORY_BYTES;
    npu_lsc_cycle_config_reference(&lsc_config);
    lsc_config.l1_bytes = TOP_TEST_MEMORY_BYTES;
    lsc_config.l1_config =
        (lsc_config.l1_config & ~NPU_LSC_FIELD_U32_MASK) |
        TOP_TEST_MEMORY_BYTES;

    (void)memset(&top_test_env.top, 0xa5,
                 sizeof(top_test_env.top));
    (void)memcpy(top_test_top_snapshot, &top_test_env.top,
                 sizeof(top_test_env.top));
    limits.mt++;
    TEST_CHECK_STATUS(
        npu_core_top_cycle_init(
            &top_test_env.top, &top_test_env.functional,
            &limits, &lsc_config),
        NPU_STATUS_BAD_DESC);
    TEST_CHECK(memcmp(
                   top_test_top_snapshot, &top_test_env.top,
                   sizeof(top_test_env.top)) == 0);

    limits.mt--;
    limits.gaddr_limit = TOP_TEST_MEMORY_BYTES + 1u;
    TEST_CHECK_STATUS(
        npu_core_top_cycle_init(
            &top_test_env.top, &top_test_env.functional,
            &limits, &lsc_config),
        NPU_STATUS_BAD_DESC);
    TEST_CHECK(memcmp(
                   top_test_top_snapshot, &top_test_env.top,
                   sizeof(top_test_env.top)) == 0);

    limits.gaddr_limit = (UINT64_C(1) << 48) + 1u;
    TEST_CHECK_STATUS(
        npu_core_top_cycle_init(
            &top_test_env.top, &top_test_env.functional,
            &limits, &lsc_config),
        NPU_STATUS_BAD_DESC);
    TEST_CHECK(memcmp(
                   top_test_top_snapshot, &top_test_env.top,
                   sizeof(top_test_env.top)) == 0);
    return 0;
}

static int top_test_dfu_drive(
    top_test_dfu_t *server,
    npu_core_top_cycle_inputs_t *inputs)
{
    uint64_t offset;
    uint8_t allow_request =
        (uint8_t)(server->held_request != 0u &&
                  (server->cycle % 3u) != 1u);
    uint8_t allow_response =
        (uint8_t)((server->cycle % 4u) != 2u);

    inputs->df_mem_req_ready_i = allow_request;
    if (server->active == 0u || allow_response == 0u) {
        return 0;
    }
    offset = server->active_addr - server->descriptor_addr +
             (uint64_t)server->active_beat *
                 NPU_REF_BUS_BYTES;
    TEST_CHECK(offset + NPU_REF_BUS_BYTES <=
               server->descriptor_bytes);
    inputs->df_mem_rsp_valid_i = 1u;
    inputs->df_mem_rsp_data_i =
        top_test_get_u64(server->descriptor, (size_t)offset);
    inputs->df_mem_rsp_tag_i = server->active_tag;
    inputs->df_mem_rsp_last_i =
        (uint8_t)(server->active_beat + 1u ==
                  server->active_beats);
    inputs->df_mem_rsp_status_i = NPU_STATUS_SUCCESS;
    return 0;
}

static int top_test_dfu_observe(
    top_test_dfu_t *server,
    const npu_core_top_cycle_inputs_t *inputs,
    const npu_core_top_cycle_outputs_t *outputs)
{
    uint8_t request_handshake =
        (uint8_t)(outputs->df_mem_req_valid_o != 0u &&
                  inputs->df_mem_req_ready_i != 0u);
    uint8_t response_handshake =
        (uint8_t)(inputs->df_mem_rsp_valid_i != 0u &&
                  outputs->df_mem_rsp_ready_o != 0u);

    if (outputs->df_mem_req_valid_o != 0u) {
        if (server->held_request != 0u) {
            TEST_CHECK(outputs->df_mem_req_addr_o ==
                       server->held_addr);
            TEST_CHECK(outputs->df_mem_req_beats_o ==
                       server->held_beats);
            TEST_CHECK(outputs->df_mem_req_tag_o ==
                       server->held_tag);
            TEST_CHECK(outputs->df_mem_req_task_id_o ==
                       server->held_task_id);
            TEST_CHECK(outputs->df_mem_req_attr_o ==
                       server->held_attr);
        } else if (inputs->df_mem_req_ready_i == 0u) {
            server->held_request = 1u;
            server->held_addr = outputs->df_mem_req_addr_o;
            server->held_beats = outputs->df_mem_req_beats_o;
            server->held_tag = outputs->df_mem_req_tag_o;
            server->held_task_id =
                outputs->df_mem_req_task_id_o;
            server->held_attr = outputs->df_mem_req_attr_o;
        }
    } else {
        TEST_CHECK(server->held_request == 0u);
    }
    if (outputs->df_mem_req_valid_o != 0u &&
        inputs->df_mem_req_ready_i == 0u) {
        server->request_stalls++;
    }
    if (request_handshake != 0u) {
        TEST_CHECK(server->active == 0u);
        server->active = 1u;
        server->active_addr = outputs->df_mem_req_addr_o;
        server->active_tag = outputs->df_mem_req_tag_o;
        server->active_beats =
            (uint16_t)outputs->df_mem_req_beats_o + 1u;
        server->active_beat = 0u;
        server->request_count++;
        server->held_request = 0u;
    }

    if (inputs->df_mem_rsp_valid_i != 0u &&
        outputs->df_mem_rsp_ready_o == 0u) {
        server->response_stalls++;
    }
    if (response_handshake != 0u) {
        TEST_CHECK(server->active != 0u);
        server->response_count++;
        server->active_beat++;
        if (server->active_beat == server->active_beats) {
            server->active = 0u;
            server->active_addr = 0u;
            server->active_tag = 0u;
            server->active_beats = 0u;
            server->active_beat = 0u;
        }
    }
    server->cycle++;
    return 0;
}

static int top_test_tick(
    top_test_env_t *env,
    npu_core_top_cycle_inputs_t *inputs,
    npu_core_top_cycle_outputs_t *outputs)
{
    int line = top_test_dfu_drive(&env->dfu, inputs);

    if (line != 0) {
        return line;
    }
    npu_core_top_cycle_step(&env->top, inputs, outputs);
    return top_test_dfu_observe(&env->dfu, inputs, outputs);
}

static int top_test_external_reset(top_test_env_t *env)
{
    npu_core_top_cycle_inputs_t inputs;
    npu_core_top_cycle_outputs_t outputs;

    top_test_idle_inputs(&inputs);
    inputs.reset_n = 0u;
    TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    TEST_CHECK(outputs.gc_cmd_ready_o == 0u);
    TEST_CHECK(outputs.stop_fetch_o == 1u);
    TEST_CHECK(env->top.cycle == 0u);

    top_test_idle_inputs(&inputs);
    TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    TEST_CHECK(outputs.cfe_idle_o == 1u);
    TEST_CHECK(outputs.ts_idle_o == 1u);
    TEST_CHECK(outputs.eng_quiescent_o == 0x0fu);
    return 0;
}

static int top_test_csr_write(top_test_env_t *env,
                              uint16_t address,
                              uint64_t data)
{
    npu_core_top_cycle_inputs_t inputs;
    npu_core_top_cycle_outputs_t outputs;
    uint64_t held_data;
    uint8_t held_status;
    uint32_t cycle;

    top_test_idle_inputs(&inputs);
    inputs.reg_req_valid_i = 1u;
    inputs.reg_req_write_i = 1u;
    inputs.reg_req_addr_i = address;
    inputs.reg_req_wdata_i = data;
    inputs.reg_req_wstrb_i = 0xffu;
    TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    TEST_CHECK(outputs.reg_req_ready_o == 1u);

    for (cycle = 0u; cycle < 8u; cycle++) {
        top_test_idle_inputs(&inputs);
        TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
        if (outputs.reg_rsp_valid_o != 0u) {
            break;
        }
    }
    TEST_CHECK(outputs.reg_rsp_valid_o == 1u);
    held_data = outputs.reg_rsp_rdata_o;
    held_status = outputs.reg_rsp_status_o;
    TEST_CHECK(held_status == NPU_LSC_REG_OKAY);

    top_test_idle_inputs(&inputs);
    TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    TEST_CHECK(outputs.reg_rsp_valid_o == 1u);
    TEST_CHECK(outputs.reg_rsp_rdata_o == held_data);
    TEST_CHECK(outputs.reg_rsp_status_o == held_status);
    TEST_CHECK(outputs.reg_req_ready_o == 0u);

    top_test_idle_inputs(&inputs);
    inputs.reg_rsp_ready_i = 1u;
    TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    TEST_CHECK(outputs.reg_rsp_valid_o == 1u);
    TEST_CHECK(outputs.reg_rsp_rdata_o == held_data);
    TEST_CHECK(outputs.reg_rsp_status_o == held_status);
    return 0;
}

static int top_test_start(top_test_env_t *env)
{
    TOP_TEST_CALL(top_test_csr_write(
        env, NPU_LSC_REG_IRQ_MASK, 0u));
    TOP_TEST_CALL(top_test_csr_write(
        env, NPU_LSC_REG_CORE_CONTROL,
        NPU_LSC_CORE_CONTROL_START));
    TEST_CHECK(env->top.lsc.started == 1u);
    TEST_CHECK(env->top.lsc.stopped == 0u);
    return 0;
}

static void top_test_make_cmd(uint16_t command_id,
                              uint16_t flags,
                              uint8_t timeout_class,
                              npu_event_ref_t signal,
                              uint64_t *low,
                              uint64_t *high)
{
    npu_event_ref_t none = npu_event_none();
    uint16_t wait_none =
        (uint16_t)(((uint16_t)none.generation << 8u) | none.id);
    uint16_t signal_raw =
        (uint16_t)(((uint16_t)signal.generation << 8u) |
                   signal.id);
    uint16_t encoded_flags =
        (uint16_t)(flags & (uint16_t)~0x03c0u);

    encoded_flags |=
        (uint16_t)(timeout_class & 0x0fu) << 6u;
    *low =
        (TOP_TEST_DESC_ADDR &
         UINT64_C(0x0000ffffffffffff)) |
        ((uint64_t)(command_id & 0x0fffu) << 48u) |
        ((uint64_t)NPU_ENGINE_VECTOR << 60u);
    *high =
        (uint64_t)NPU_VECTOR_ADD |
        ((uint64_t)(encoded_flags & 0x0fffu) << 8u) |
        ((uint64_t)wait_none << 20u) |
        ((uint64_t)wait_none << 32u) |
        ((uint64_t)signal_raw << 44u) |
        (UINT64_C(1) << 56u);
}

static int top_test_submit_cmd(top_test_env_t *env,
                               uint64_t low,
                               uint64_t high)
{
    npu_core_top_cycle_inputs_t inputs;
    npu_core_top_cycle_outputs_t outputs;
    uint32_t cycle;
    uint8_t low_accepted = 0u;
    uint8_t high_accepted = 0u;

    for (cycle = 0u; cycle < 32u; cycle++) {
        top_test_idle_inputs(&inputs);
        inputs.gc_cmd_valid_i = 1u;
        inputs.gc_cmd_data_i = low;
        inputs.gc_cmd_first_i = 1u;
        inputs.gc_cmd_last_i = 0u;
        inputs.gc_rsp_ready_i =
            (uint8_t)((cycle % 3u) == 0u);
        TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
        if (outputs.gc_cmd_ready_o != 0u) {
            low_accepted = 1u;
            break;
        }
    }
    TEST_CHECK(low_accepted != 0u);

    for (cycle = 0u; cycle < 32u; cycle++) {
        top_test_idle_inputs(&inputs);
        inputs.gc_cmd_valid_i = 1u;
        inputs.gc_cmd_data_i = high;
        inputs.gc_cmd_first_i = 0u;
        inputs.gc_cmd_last_i = 1u;
        inputs.gc_rsp_ready_i =
            (uint8_t)((cycle % 3u) == 0u);
        TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
        if (outputs.gc_cmd_ready_o != 0u) {
            high_accepted = 1u;
            break;
        }
    }
    TEST_CHECK(high_accepted != 0u);
    return 0;
}

static int top_test_query(top_test_env_t *env,
                          uint16_t command_id,
                          uint8_t selector,
                          uint64_t *result)
{
    npu_core_top_cycle_inputs_t inputs;
    npu_core_top_cycle_outputs_t outputs;
    uint32_t cycle;
    uint8_t accepted = 0u;
    uint64_t held;

    for (cycle = 0u; cycle < 32u; cycle++) {
        top_test_idle_inputs(&inputs);
        inputs.gc_ctl_valid_i = 1u;
        inputs.gc_ctl_op_i = NPU_TS_CTL_QUERY;
        inputs.gc_ctl_rs1_i = command_id;
        inputs.gc_ctl_rs2_i = selector;
        TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
        if (outputs.gc_ctl_ready_o != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);

    for (cycle = 0u; cycle < 32u; cycle++) {
        top_test_idle_inputs(&inputs);
        TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
        if (outputs.gc_ctl_rsp_valid_o != 0u) {
            break;
        }
    }
    TEST_CHECK(outputs.gc_ctl_rsp_valid_o != 0u);
    held = outputs.gc_ctl_rsp_data_o;

    top_test_idle_inputs(&inputs);
    TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    TEST_CHECK(outputs.gc_ctl_rsp_valid_o != 0u);
    TEST_CHECK(outputs.gc_ctl_rsp_data_o == held);

    top_test_idle_inputs(&inputs);
    inputs.gc_ctl_rsp_ready_i = 1u;
    TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    TEST_CHECK(outputs.gc_ctl_rsp_valid_o != 0u);
    TEST_CHECK(outputs.gc_ctl_rsp_data_o == held);
    *result = held;
    return 0;
}

static int top_test_real_task_and_queries(void)
{
    top_test_env_t *env = &top_test_env;
    npu_core_top_cycle_inputs_t inputs;
    npu_core_top_cycle_outputs_t outputs;
    uint64_t low;
    uint64_t high;
    uint64_t result;
    uint64_t held_host_rsp = 0u;
    uint32_t cycle;
    uint8_t host_rsp_seen = 0u;
    uint8_t host_rsp_held = 0u;
    uint8_t engine_request_seen = 0u;
    uint8_t desc_request_seen = 0u;
    uint8_t done_beats = 0u;
    uint8_t terminal_seen = 0u;

    TOP_TEST_CALL(top_test_env_init(2u));
    TOP_TEST_CALL(top_test_external_reset(env));
    TOP_TEST_CALL(top_test_start(env));
    env->l1[TOP_TEST_SRC0 + 0u] = 1u;
    env->l1[TOP_TEST_SRC0 + 1u] = 2u;
    env->l1[TOP_TEST_SRC0 + 2u] = 3u;
    env->l1[TOP_TEST_SRC0 + 3u] = 100u;
    env->l1[TOP_TEST_SRC1 + 0u] = 10u;
    env->l1[TOP_TEST_SRC1 + 1u] = 20u;
    env->l1[TOP_TEST_SRC1 + 2u] = 30u;
    env->l1[TOP_TEST_SRC1 + 3u] = 100u;

    top_test_make_cmd(
        TOP_TEST_COMMAND, NPU_TS_FLAG_IRQ_ON_SUCCESS, 0u,
        npu_event_none(), &low, &high);
    TOP_TEST_CALL(top_test_submit_cmd(env, low, high));

    for (cycle = 0u;
         cycle < TOP_TEST_MAX_CYCLES && terminal_seen == 0u;
         cycle++) {
        uint8_t host_ready =
            (uint8_t)((cycle % 5u) == 3u);

        top_test_idle_inputs(&inputs);
        inputs.gc_rsp_ready_i = host_ready;
        TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
        TEST_CHECK(env->top.cycle == outputs.cycle + 1u);
        TEST_CHECK(env->top.ts.cycle ==
                   outputs.ts.cycle + 1u);
        TEST_CHECK(env->top.engine[
                       TOP_TEST_VECTOR_PORT]
                       .cycle ==
                   outputs.engine[
                       TOP_TEST_VECTOR_PORT]
                       .cycle +
                       1u);

        if (outputs.gc_rsp_valid_o != 0u) {
            if (host_rsp_held != 0u) {
                TEST_CHECK(outputs.gc_rsp_data_o ==
                           held_host_rsp);
            } else {
                held_host_rsp = outputs.gc_rsp_data_o;
                host_rsp_held = 1u;
            }
            if (host_ready != 0u) {
                host_rsp_seen = 1u;
                host_rsp_held = 0u;
                TEST_CHECK(
                    ((outputs.gc_rsp_data_o >> 12u) & 0xffu) ==
                    NPU_STATUS_SUCCESS);
            }
        } else {
            TEST_CHECK(host_rsp_held == 0u);
        }

        if (outputs.ts.engine[TOP_TEST_VECTOR_PORT].req_valid != 0u &&
            outputs.engine[TOP_TEST_VECTOR_PORT]
                    .eng_req_ready_o != 0u) {
            engine_request_seen = 1u;
            TEST_CHECK(env->top.ts.req_hold[
                           TOP_TEST_VECTOR_PORT]
                           .valid == 0u);
            TEST_CHECK(env->top.ts.engine_active_task[
                           TOP_TEST_VECTOR_PORT] !=
                       NPU_TS_INVALID_INDEX);
            TEST_CHECK(env->top.engine[
                           TOP_TEST_VECTOR_PORT]
                           .state != NPU_ENGINE_CYCLE_IDLE);
        }
        if (outputs.engine[TOP_TEST_VECTOR_PORT]
                    .desc_rd_req_valid_o != 0u &&
            outputs.ts.desc[TOP_TEST_VECTOR_PORT].req_ready != 0u &&
            desc_request_seen == 0u) {
            desc_request_seen = 1u;
            TEST_CHECK(env->top.engine[
                           TOP_TEST_VECTOR_PORT]
                           .desc_outstanding != 0u);
            TEST_CHECK(env->top.ts.desc_port[
                           TOP_TEST_VECTOR_PORT]
                           .count != 0u);
        }
        if (outputs.engine[TOP_TEST_VECTOR_PORT]
                    .eng_done_valid_o != 0u &&
            outputs.ts.engine[TOP_TEST_VECTOR_PORT]
                    .done_ready != 0u) {
            done_beats++;
            if (done_beats == 1u) {
                TEST_CHECK(outputs.engine[
                               TOP_TEST_VECTOR_PORT]
                               .eng_done_first_o == 1u);
                TEST_CHECK(env->top.ts.done_rx[
                               TOP_TEST_VECTOR_PORT]
                               .beat == 1u);
                TEST_CHECK(env->top.engine[
                               TOP_TEST_VECTOR_PORT]
                               .done_beat == 1u);
            } else if (done_beats == 2u) {
                TEST_CHECK(env->top.ts.done_rx[
                               TOP_TEST_VECTOR_PORT]
                               .beat == 2u);
                TEST_CHECK(env->top.engine[
                               TOP_TEST_VECTOR_PORT]
                               .done_beat == 2u);
            } else if (done_beats == 3u) {
                TEST_CHECK(outputs.engine[
                               TOP_TEST_VECTOR_PORT]
                               .eng_done_last_o == 1u);
                TEST_CHECK(env->top.engine[
                               TOP_TEST_VECTOR_PORT]
                               .state == NPU_ENGINE_CYCLE_IDLE);
            }
        }
        if (outputs.ts.terminal_valid != 0u) {
            TEST_CHECK(outputs.ts.terminal_task_id ==
                       TOP_TEST_COMMAND);
            TEST_CHECK(outputs.ts.terminal_status ==
                       NPU_STATUS_SUCCESS);
            TEST_CHECK(env->top.lsc.irq_status ==
                       NPU_LSC_IRQ_DONE);
            terminal_seen = 1u;
        }
    }

    TEST_CHECK(terminal_seen != 0u);
    TEST_CHECK(host_rsp_seen != 0u);
    TEST_CHECK(engine_request_seen != 0u);
    TEST_CHECK(desc_request_seen != 0u);
    TEST_CHECK(done_beats == 3u);
    TEST_CHECK(env->dfu.request_count == 2u);
    TEST_CHECK(env->dfu.response_count ==
               NPU_WIRE_VECTOR_DESC_BYTES /
                   NPU_REF_BUS_BYTES);
    TEST_CHECK(env->dfu.request_stalls != 0u);
    TEST_CHECK(env->l1[TOP_TEST_DST + 0u] == 11u);
    TEST_CHECK(env->l1[TOP_TEST_DST + 1u] == 22u);
    TEST_CHECK(env->l1[TOP_TEST_DST + 2u] == 33u);
    TEST_CHECK(env->l1[TOP_TEST_DST + 3u] == 127u);
    TEST_CHECK(env->functional.perf.int_saturate_count == 1u);

    top_test_idle_inputs(&inputs);
    TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    TEST_CHECK(outputs.irq_done_o == 1u);

    TOP_TEST_CALL(top_test_query(
        env, TOP_TEST_COMMAND, NPU_TS_QUERY_ERROR_INFO,
        &result));
    TEST_CHECK(result == 0u);
    TOP_TEST_CALL(top_test_query(
        env, TOP_TEST_COMMAND, NPU_TS_QUERY_DONE_FLAGS,
        &result));
    TEST_CHECK(result == 0u);
    TOP_TEST_CALL(top_test_query(
        env, TOP_TEST_COMMAND, NPU_TS_QUERY_ACK, &result));
    TEST_CHECK(result == 0u);
    TEST_CHECK(npu_ts_cycle_find_task(
                   &env->top.ts, TOP_TEST_COMMAND) ==
               (const npu_ts_task_entry_t *)0);
    return 0;
}

static int top_test_timeout_cancel(void)
{
    top_test_env_t *env = &top_test_env;
    npu_core_top_cycle_inputs_t inputs;
    npu_core_top_cycle_outputs_t outputs;
    uint64_t low;
    uint64_t high;
    uint64_t error_info;
    uint64_t done_flags;
    uint32_t cycle;
    uint8_t cancel_seen = 0u;
    uint8_t done_beats = 0u;
    uint8_t terminal_seen = 0u;

    TOP_TEST_CALL(top_test_env_init(2u));
    TOP_TEST_CALL(top_test_external_reset(env));
    TOP_TEST_CALL(top_test_start(env));
    top_test_make_cmd(
        TOP_TEST_TIMEOUT_COMMAND,
        NPU_TS_FLAG_IRQ_ON_ERROR, 1u,
        npu_event_none(), &low, &high);
    TOP_TEST_CALL(top_test_submit_cmd(env, low, high));

    for (cycle = 0u;
         cycle < TOP_TEST_MAX_CYCLES && terminal_seen == 0u;
         cycle++) {
        top_test_idle_inputs(&inputs);
        inputs.gc_rsp_ready_i =
            (uint8_t)((cycle % 3u) != 0u);
        TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));

        if (outputs.ts.engine[TOP_TEST_VECTOR_PORT]
                    .cancel_valid != 0u &&
            outputs.engine[TOP_TEST_VECTOR_PORT]
                    .eng_cancel_ready_o != 0u) {
            cancel_seen = 1u;
            TEST_CHECK(outputs.ts.engine[
                           TOP_TEST_VECTOR_PORT]
                           .cancel_status ==
                       NPU_STATUS_TIMEOUT);
            TEST_CHECK(env->top.ts.cancel[
                           TOP_TEST_VECTOR_PORT]
                           .phase ==
                       NPU_TS_CANCEL_WAIT_DONE);
            TEST_CHECK(env->top.engine[
                           TOP_TEST_VECTOR_PORT]
                           .canceling == 1u);
        }
        if (outputs.engine[TOP_TEST_VECTOR_PORT]
                    .eng_done_valid_o != 0u &&
            outputs.ts.engine[TOP_TEST_VECTOR_PORT]
                    .done_ready != 0u) {
            done_beats++;
        }
        if (outputs.ts.terminal_valid != 0u) {
            TEST_CHECK(outputs.ts.terminal_task_id ==
                       TOP_TEST_TIMEOUT_COMMAND);
            TEST_CHECK(outputs.ts.terminal_status ==
                       NPU_STATUS_TIMEOUT);
            TEST_CHECK(outputs.ts.terminal_error_info != 0u);
            TEST_CHECK(env->top.lsc.fault_valid == 1u);
            TEST_CHECK(env->top.lsc.fault_command_id ==
                       TOP_TEST_TIMEOUT_COMMAND);
            TEST_CHECK(env->top.lsc.fault_error_info ==
                       outputs.ts.terminal_error_info);
            TEST_CHECK((env->top.lsc.irq_status &
                        NPU_LSC_IRQ_EXCEPTION) != 0u);
            terminal_seen = 1u;
        }
    }

    TEST_CHECK(cancel_seen != 0u);
    TEST_CHECK(done_beats == 3u);
    TEST_CHECK(terminal_seen != 0u);
    TEST_CHECK(env->l1[TOP_TEST_DST + 0u] == 0u);
    TEST_CHECK(env->l1[TOP_TEST_DST + 1u] == 0u);
    TEST_CHECK(env->l1[TOP_TEST_DST + 2u] == 0u);
    TEST_CHECK(env->l1[TOP_TEST_DST + 3u] == 0u);

    TOP_TEST_CALL(top_test_query(
        env, TOP_TEST_TIMEOUT_COMMAND,
        NPU_TS_QUERY_ERROR_INFO, &error_info));
    TEST_CHECK(error_info != 0u);
    TEST_CHECK((error_info >> 28u) ==
               NPU_ENGINE_ERROR_EXECUTE);
    TOP_TEST_CALL(top_test_query(
        env, TOP_TEST_TIMEOUT_COMMAND,
        NPU_TS_QUERY_DONE_FLAGS, &done_flags));
    TEST_CHECK(done_flags == 0u);
    TOP_TEST_CALL(top_test_query(
        env, TOP_TEST_TIMEOUT_COMMAND,
        NPU_TS_QUERY_ACK, &done_flags));
    TEST_CHECK(done_flags == 0u);
    return 0;
}

static int top_test_controlled_reset_drains_cfe(void)
{
    top_test_env_t *env = &top_test_env;
    npu_core_top_cycle_inputs_t inputs;
    npu_core_top_cycle_outputs_t outputs;
    npu_event_ref_t signal;
    uint64_t low;
    uint64_t high;
    uint32_t cycle;
    uint8_t transfer_seen = 0u;
    uint8_t first_transfer_seen = 0u;
    uint8_t terminal_seen = 0u;
    uint8_t event_error_seen = 0u;
    uint8_t reset_pulse_seen = 0u;
    uint8_t done_seen = 0u;

    TOP_TEST_CALL(top_test_env_init(2u));
    TOP_TEST_CALL(top_test_external_reset(env));
    TOP_TEST_CALL(top_test_start(env));
    signal.id = 20u;
    signal.generation = 0u;
    top_test_make_cmd(
        TOP_TEST_RESET_COMMAND,
        NPU_TS_FLAG_IRQ_ON_ERROR, 0u,
        signal, &low, &high);
    TOP_TEST_CALL(top_test_submit_cmd(env, low, high));

    for (cycle = 0u; cycle < 32u; cycle++) {
        if (env->top.cfe.state == NPU_CFE_STATE_ENQUEUE) {
            break;
        }
        top_test_idle_inputs(&inputs);
        TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    }
    TEST_CHECK(env->top.cfe.state == NPU_CFE_STATE_ENQUEUE);
    TEST_CHECK(env->top.cfe.fifo_count == 0u);

    top_test_idle_inputs(&inputs);
    inputs.soft_reset_req_i = 1u;
    TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    TEST_CHECK(env->top.cfe.fifo_count == 1u);
    TEST_CHECK(env->top.lsc.soft_state ==
               NPU_LSC_SOFT_DRAIN);

    for (cycle = 0u; cycle < TOP_TEST_MAX_CYCLES; cycle++) {
        top_test_idle_inputs(&inputs);
        inputs.soft_reset_req_i = 1u;
        inputs.gc_rsp_ready_i =
            (uint8_t)((cycle % 3u) != 0u);
        TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));

        if (outputs.cfe.ts_cmd_valid_o != 0u &&
            outputs.ts.cfe.ready != 0u) {
            if (outputs.cfe.ts_cmd_first_o != 0u) {
                TEST_CHECK(outputs.cfe.ts_cmd_last_o == 0u);
                TEST_CHECK(outputs.cfe.ts_cmd_data_o == low);
                TEST_CHECK(env->top.cfe.fifo_count == 1u);
                TEST_CHECK(env->top.ts.cfe_half_valid == 1u);
                first_transfer_seen = 1u;
            } else {
                TEST_CHECK(first_transfer_seen != 0u);
                TEST_CHECK(outputs.cfe.ts_cmd_last_o != 0u);
                TEST_CHECK(outputs.cfe.ts_cmd_data_o == high);
                transfer_seen = 1u;
                TEST_CHECK(env->top.cfe.fifo_count == 0u);
                TEST_CHECK(
                    npu_ts_cycle_find_task(
                        &env->top.ts,
                        TOP_TEST_RESET_COMMAND)->state ==
                    NPU_TS_TASK_COMMIT);
            }
        }
        if (env->top.ts.event[signal.id].state ==
            NPU_TS_EVENT_ERROR) {
            event_error_seen = 1u;
        }
        if (outputs.ts.terminal_valid != 0u) {
            TEST_CHECK(outputs.ts.terminal_task_id ==
                       TOP_TEST_RESET_COMMAND);
            TEST_CHECK(outputs.ts.terminal_status ==
                       NPU_STATUS_ABORTED);
            TEST_CHECK(outputs.ts.terminal_done_flags ==
                       NPU_DONE_ABORT_DRAINED);
            TEST_CHECK(env->top.lsc.fault_valid == 1u);
            terminal_seen = 1u;
        }
        if (outputs.internal_soft_reset_pulse_o != 0u) {
            reset_pulse_seen = 1u;
            TEST_CHECK(outputs.soft_reset_done_o == 0u);
            TEST_CHECK(npu_ts_cycle_find_task(
                           &env->top.ts,
                           TOP_TEST_RESET_COMMAND) ==
                       (const npu_ts_task_entry_t *)0);
            TEST_CHECK(env->top.cfe.fifo_count == 0u);
            TEST_CHECK(env->top.engine[
                           TOP_TEST_VECTOR_PORT]
                           .state == NPU_ENGINE_CYCLE_IDLE);
        }
        if (outputs.soft_reset_done_o != 0u) {
            done_seen = 1u;
        }
        if (done_seen != 0u && reset_pulse_seen != 0u) {
            break;
        }
    }

    TEST_CHECK(first_transfer_seen != 0u);
    TEST_CHECK(transfer_seen != 0u);
    TEST_CHECK(terminal_seen != 0u);
    TEST_CHECK(event_error_seen != 0u);
    TEST_CHECK(reset_pulse_seen != 0u);
    TEST_CHECK(done_seen != 0u);
    TEST_CHECK(env->dfu.request_count == 0u);

    top_test_idle_inputs(&inputs);
    inputs.soft_reset_req_i = 1u;
    TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    TEST_CHECK(outputs.soft_reset_done_o == 1u);
    TEST_CHECK(outputs.internal_soft_reset_pulse_o == 0u);

    top_test_idle_inputs(&inputs);
    TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    TEST_CHECK(outputs.soft_reset_done_o == 1u);
    top_test_idle_inputs(&inputs);
    TOP_TEST_CALL(top_test_tick(env, &inputs, &outputs));
    TEST_CHECK(outputs.soft_reset_done_o == 0u);
    TEST_CHECK(outputs.stop_fetch_o == 1u);
    return 0;
}

int test_core_top_cycle(void)
{
    TOP_TEST_CALL(top_test_rejects_inconsistent_capabilities());
    TOP_TEST_CALL(top_test_real_task_and_queries());
    TOP_TEST_CALL(top_test_timeout_cancel());
    TOP_TEST_CALL(top_test_controlled_reset_drains_cfe());
    return 0;
}

#ifdef NPU_CORE_TOP_CYCLE_STANDALONE
int main(void)
{
    return test_core_top_cycle();
}
#endif
