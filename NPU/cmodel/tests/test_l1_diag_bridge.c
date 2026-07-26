#include "npu_l1_diag_bridge.h"
#include "test_util.h"

#include <string.h>

#ifdef NPU_L1_DIAG_BRIDGE_STANDALONE
#include <stdio.h>
#endif

#define DIAG_TEST_MAX_CYCLES 256u

static uint8_t diag_test_memory[NPU_L1_CYCLE_BYTES];
static uint8_t diag_test_ecc[NPU_L1_CYCLE_WORDS];
static npu_l1_cycle_t diag_test_l1;

static void diag_test_inputs_default(
    npu_l1_diag_bridge_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = 1u;
}

static uint32_t diag_test_random(uint32_t *state)
{
    uint32_t value = *state;

    value ^= value << 13u;
    value ^= value >> 17u;
    value ^= value << 5u;
    *state = value;
    return value;
}

static int diag_test_init_and_reset(void)
{
    npu_l1_diag_bridge_t bridge;
    npu_l1_diag_bridge_inputs_t inputs;
    npu_l1_diag_bridge_outputs_t outputs;
    uint32_t state;

    TEST_CHECK(npu_l1_diag_bridge_init(
                   (npu_l1_diag_bridge_t *)0) != 0);
    TEST_CHECK(npu_l1_diag_bridge_init(&bridge) == 0);
    TEST_CHECK(npu_l1_diag_bridge_idle(&bridge) != 0u);
    TEST_CHECK(npu_l1_diag_bridge_idle(
                   (const npu_l1_diag_bridge_t *)0) == 0u);

    for (state = (uint32_t)NPU_L1_DIAG_BRIDGE_IDLE;
         state <=
             (uint32_t)NPU_L1_DIAG_BRIDGE_UPSTREAM_RESPONSE;
         state++) {
        (void)memset(&bridge, 0xa5, sizeof(bridge));
        bridge.state = (npu_l1_diag_bridge_state_t)state;
        bridge.cycle = UINT64_C(71);
        diag_test_inputs_default(&inputs);
        inputs.reset_n = 0u;
        npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
        TEST_CHECK(bridge.state == NPU_L1_DIAG_BRIDGE_IDLE);
        TEST_CHECK(bridge.cycle == 0u);
        TEST_CHECK(bridge.next_tag == 0u);
        TEST_CHECK(outputs.req_ready_o == 0u);
        TEST_CHECK(outputs.rsp_valid_o == 0u);
        TEST_CHECK(outputs.l1_read_o.req_valid == 0u);
        TEST_CHECK(outputs.l1_read_o.rsp_ready == 0u);
        TEST_CHECK(outputs.l1_write_o.req_valid == 0u);
        TEST_CHECK(outputs.l1_write_o.data_valid == 0u);
        TEST_CHECK(outputs.l1_write_o.rsp_ready == 0u);
        TEST_CHECK(outputs.idle_o != 0u);
        TEST_CHECK(outputs.cycle_o == 0u);
    }

    diag_test_inputs_default(&inputs);
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.req_ready_o != 0u);
    TEST_CHECK(outputs.idle_o != 0u);
    TEST_CHECK(outputs.cycle_o == 0u);
    TEST_CHECK(bridge.cycle == 1u);
    return 0;
}

static int diag_test_local_protocol_errors(void)
{
    static const uint32_t bad_addr[] = {
        UINT32_C(0x000001),
        UINT32_C(0x1000000)
    };
    npu_l1_diag_bridge_t bridge;
    npu_l1_diag_bridge_inputs_t inputs;
    npu_l1_diag_bridge_outputs_t outputs;
    uint32_t index;

    for (index = 0u;
         index < (uint32_t)(sizeof(bad_addr) /
                            sizeof(bad_addr[0]));
         index++) {
        TEST_CHECK(npu_l1_diag_bridge_init(&bridge) == 0);
        diag_test_inputs_default(&inputs);
        inputs.req_valid_i = 1u;
        inputs.req_write_i = (uint8_t)(index & 1u);
        inputs.req_addr_i = bad_addr[index];
        inputs.req_wdata_i =
            UINT64_C(0xfedcba9876543210);
        inputs.req_wstrb_i = 0xa5u;
        npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
        TEST_CHECK(outputs.req_ready_o != 0u);
        TEST_CHECK(bridge.state ==
                   NPU_L1_DIAG_BRIDGE_UPSTREAM_RESPONSE);
        TEST_CHECK(bridge.next_tag == 0u);

        diag_test_inputs_default(&inputs);
        inputs.req_valid_i = 1u;
        inputs.req_addr_i = 0x80u;
        inputs.rsp_ready_i = 0u;
        npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
        TEST_CHECK(outputs.req_ready_o == 0u);
        TEST_CHECK(outputs.rsp_valid_o != 0u);
        TEST_CHECK(outputs.rsp_rdata_o == 0u);
        TEST_CHECK(outputs.rsp_status_o ==
                   NPU_L1_STATUS_PORT_PROTOCOL_ERROR);
        TEST_CHECK(outputs.l1_read_o.req_valid == 0u);
        TEST_CHECK(outputs.l1_read_o.rsp_ready == 0u);
        TEST_CHECK(outputs.l1_write_o.req_valid == 0u);
        TEST_CHECK(outputs.l1_write_o.data_valid == 0u);
        TEST_CHECK(outputs.l1_write_o.rsp_ready == 0u);

        diag_test_inputs_default(&inputs);
        inputs.rsp_ready_i = 1u;
        npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
        TEST_CHECK(outputs.rsp_valid_o != 0u);
        TEST_CHECK(bridge.state == NPU_L1_DIAG_BRIDGE_IDLE);
    }

    TEST_CHECK(npu_l1_diag_bridge_init(&bridge) == 0);
    diag_test_inputs_default(&inputs);
    inputs.req_valid_i = 1u;
    inputs.req_write_i = 2u;
    inputs.req_addr_i = 0x80u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(bridge.state ==
               NPU_L1_DIAG_BRIDGE_UPSTREAM_RESPONSE);
    TEST_CHECK(bridge.response_status ==
               NPU_L1_STATUS_PORT_PROTOCOL_ERROR);
    return 0;
}

static int diag_test_read_random_stalls(void)
{
    npu_l1_diag_bridge_t bridge;
    npu_l1_diag_bridge_inputs_t inputs;
    npu_l1_diag_bridge_outputs_t outputs;
    const uint32_t addr = UINT32_C(0x00abc8);
    const uint64_t data = UINT64_C(0x0123456789abcdef);
    uint32_t random_state = UINT32_C(0x7d38e91b);
    uint16_t tag;
    uint32_t cycle;
    uint8_t accepted = 0u;

    TEST_CHECK(npu_l1_diag_bridge_init(&bridge) == 0);
    diag_test_inputs_default(&inputs);
    inputs.req_valid_i = 1u;
    inputs.req_write_i = 0u;
    inputs.req_addr_i = addr;
    inputs.req_wdata_i = UINT64_MAX;
    inputs.req_wstrb_i = 0xffu;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.req_ready_o != 0u);
    TEST_CHECK(bridge.state ==
               NPU_L1_DIAG_BRIDGE_READ_REQUEST);
    tag = bridge.request_tag;

    for (cycle = 0u; cycle < DIAG_TEST_MAX_CYCLES; cycle++) {
        diag_test_inputs_default(&inputs);
        inputs.l1_read_i.req_ready =
            (uint8_t)(diag_test_random(&random_state) & 1u);
        npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
        TEST_CHECK(outputs.l1_read_o.req_valid != 0u);
        TEST_CHECK(outputs.l1_read_o.req_addr == addr);
        TEST_CHECK(outputs.l1_read_o.req_beats == 0u);
        TEST_CHECK(outputs.l1_read_o.req_tag == tag);
        TEST_CHECK(outputs.l1_read_o.rsp_ready == 0u);
        TEST_CHECK(outputs.l1_write_o.req_valid == 0u);
        if (inputs.l1_read_i.req_ready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);
    TEST_CHECK(bridge.state ==
               NPU_L1_DIAG_BRIDGE_READ_RESPONSE);

    for (cycle = 0u; cycle < 23u; cycle++) {
        diag_test_inputs_default(&inputs);
        inputs.l1_read_i.rsp_valid = 0u;
        npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
        TEST_CHECK(outputs.l1_read_o.req_valid == 0u);
        TEST_CHECK(outputs.l1_read_o.rsp_ready != 0u);
        TEST_CHECK(outputs.rsp_valid_o == 0u);
    }

    diag_test_inputs_default(&inputs);
    inputs.l1_read_i.rsp_valid = 1u;
    inputs.l1_read_i.rsp_data = data;
    inputs.l1_read_i.rsp_tag = tag;
    inputs.l1_read_i.rsp_last = 1u;
    inputs.l1_read_i.rsp_status = NPU_L1_STATUS_ECC_CORRECTED;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read_o.rsp_ready != 0u);
    TEST_CHECK(bridge.state ==
               NPU_L1_DIAG_BRIDGE_UPSTREAM_RESPONSE);

    for (cycle = 0u; cycle < 31u; cycle++) {
        uint64_t held_data;
        uint8_t held_status;

        diag_test_inputs_default(&inputs);
        inputs.req_valid_i = 1u;
        inputs.req_addr_i = 0x100u;
        inputs.rsp_ready_i = 0u;
        npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
        held_data = outputs.rsp_rdata_o;
        held_status = outputs.rsp_status_o;
        TEST_CHECK(outputs.req_ready_o == 0u);
        TEST_CHECK(outputs.rsp_valid_o != 0u);
        TEST_CHECK(held_data == data);
        TEST_CHECK(held_status ==
                   NPU_L1_STATUS_ECC_CORRECTED);
        TEST_CHECK(outputs.l1_read_o.req_valid == 0u);
        TEST_CHECK(outputs.l1_read_o.rsp_ready == 0u);
    }

    diag_test_inputs_default(&inputs);
    inputs.rsp_ready_i = 1u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.rsp_valid_o != 0u);
    TEST_CHECK(outputs.rsp_rdata_o == data);
    TEST_CHECK(bridge.state == NPU_L1_DIAG_BRIDGE_IDLE);
    return 0;
}

static int diag_test_read_bad_l1_response(void)
{
    npu_l1_diag_bridge_t bridge;
    npu_l1_diag_bridge_inputs_t inputs;
    npu_l1_diag_bridge_outputs_t outputs;
    uint16_t tag;

    TEST_CHECK(npu_l1_diag_bridge_init(&bridge) == 0);
    diag_test_inputs_default(&inputs);
    inputs.req_valid_i = 1u;
    inputs.req_addr_i = 0x200u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    tag = bridge.request_tag;

    diag_test_inputs_default(&inputs);
    inputs.l1_read_i.req_ready = 1u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);

    diag_test_inputs_default(&inputs);
    inputs.l1_read_i.rsp_valid = 1u;
    inputs.l1_read_i.rsp_data = UINT64_MAX;
    inputs.l1_read_i.rsp_tag = (uint16_t)(tag ^ 1u);
    inputs.l1_read_i.rsp_last = 1u;
    inputs.l1_read_i.rsp_status = NPU_L1_STATUS_OK;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(bridge.response_status ==
               NPU_L1_STATUS_PORT_PROTOCOL_ERROR);
    TEST_CHECK(bridge.response_rdata == 0u);

    npu_l1_diag_bridge_reset(&bridge);
    diag_test_inputs_default(&inputs);
    inputs.req_valid_i = 1u;
    inputs.req_addr_i = 0x208u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    tag = bridge.request_tag;
    diag_test_inputs_default(&inputs);
    inputs.l1_read_i.req_ready = 1u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    diag_test_inputs_default(&inputs);
    inputs.l1_read_i.rsp_valid = 1u;
    inputs.l1_read_i.rsp_tag = tag;
    inputs.l1_read_i.rsp_last = 0u;
    inputs.l1_read_i.rsp_status = 7u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(bridge.response_status ==
               NPU_L1_STATUS_PORT_PROTOCOL_ERROR);
    return 0;
}

static int diag_test_write_independent_stalls(void)
{
    npu_l1_diag_bridge_t bridge;
    npu_l1_diag_bridge_inputs_t inputs;
    npu_l1_diag_bridge_outputs_t outputs;
    const uint32_t addr = 0x1f8u;
    const uint64_t data = UINT64_C(0x8f7e6d5c4b3a2918);
    const uint8_t strb = 0x5au;
    uint32_t random_state = UINT32_C(0xc07d65e3);
    uint32_t cycle;
    uint16_t tag;
    uint8_t accepted = 0u;

    TEST_CHECK(npu_l1_diag_bridge_init(&bridge) == 0);
    diag_test_inputs_default(&inputs);
    inputs.req_valid_i = 1u;
    inputs.req_write_i = 1u;
    inputs.req_addr_i = addr;
    inputs.req_wdata_i = data;
    inputs.req_wstrb_i = strb;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.req_ready_o != 0u);
    tag = bridge.request_tag;

    for (cycle = 0u; cycle < DIAG_TEST_MAX_CYCLES; cycle++) {
        diag_test_inputs_default(&inputs);
        inputs.l1_write_i.req_ready =
            (uint8_t)(diag_test_random(&random_state) & 1u);
        inputs.l1_write_i.data_ready = 1u;
        npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
        TEST_CHECK(outputs.l1_write_o.req_valid != 0u);
        TEST_CHECK(outputs.l1_write_o.req_addr == addr);
        TEST_CHECK(outputs.l1_write_o.req_beats == 0u);
        TEST_CHECK(outputs.l1_write_o.req_tag == tag);
        TEST_CHECK(outputs.l1_write_o.data_valid == 0u);
        if (inputs.l1_write_i.req_ready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);
    TEST_CHECK(bridge.state ==
               NPU_L1_DIAG_BRIDGE_WRITE_DATA);

    accepted = 0u;
    for (cycle = 0u; cycle < DIAG_TEST_MAX_CYCLES; cycle++) {
        diag_test_inputs_default(&inputs);
        inputs.l1_write_i.req_ready = 1u;
        inputs.l1_write_i.data_ready =
            (uint8_t)(diag_test_random(&random_state) & 1u);
        npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
        TEST_CHECK(outputs.l1_write_o.req_valid == 0u);
        TEST_CHECK(outputs.l1_write_o.data_valid != 0u);
        TEST_CHECK(outputs.l1_write_o.data == data);
        TEST_CHECK(outputs.l1_write_o.strb == strb);
        TEST_CHECK(outputs.l1_write_o.last != 0u);
        if (inputs.l1_write_i.data_ready != 0u) {
            accepted = 1u;
            break;
        }
    }
    TEST_CHECK(accepted != 0u);
    TEST_CHECK(bridge.state ==
               NPU_L1_DIAG_BRIDGE_WRITE_RESPONSE);

    for (cycle = 0u; cycle < 19u; cycle++) {
        diag_test_inputs_default(&inputs);
        inputs.l1_write_i.rsp_valid = 0u;
        npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
        TEST_CHECK(outputs.l1_write_o.rsp_ready != 0u);
        TEST_CHECK(outputs.rsp_valid_o == 0u);
    }

    diag_test_inputs_default(&inputs);
    inputs.l1_write_i.rsp_valid = 1u;
    inputs.l1_write_i.rsp_tag = tag;
    inputs.l1_write_i.rsp_status = NPU_L1_STATUS_ADDR_FAULT;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.l1_write_o.rsp_ready != 0u);

    diag_test_inputs_default(&inputs);
    inputs.rsp_ready_i = 0u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.rsp_valid_o != 0u);
    TEST_CHECK(outputs.rsp_rdata_o == 0u);
    TEST_CHECK(outputs.rsp_status_o == NPU_L1_STATUS_ADDR_FAULT);
    TEST_CHECK(outputs.error_valid_o != 0u);
    TEST_CHECK(outputs.error_status_o == NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(outputs.error_addr_o == addr);
    TEST_CHECK(outputs.error_detail_o == NPU_L1_STATUS_ADDR_FAULT);
    TEST_CHECK(outputs.error_write_o != 0u);

    diag_test_inputs_default(&inputs);
    inputs.rsp_ready_i = 1u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(bridge.state == NPU_L1_DIAG_BRIDGE_IDLE);
    return 0;
}

static int diag_test_error_record(void)
{
    npu_l1_diag_bridge_t bridge;
    npu_l1_diag_bridge_inputs_t inputs;
    npu_l1_diag_bridge_outputs_t outputs;

    TEST_CHECK(npu_l1_diag_bridge_init(&bridge) == 0);
    diag_test_inputs_default(&inputs);
    inputs.req_valid_i = 1u;
    inputs.req_addr_i = 1u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.error_valid_o == 0u);

    diag_test_inputs_default(&inputs);
    inputs.rsp_ready_i = 0u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.error_valid_o != 0u);
    TEST_CHECK(outputs.error_status_o == NPU_STATUS_BAD_DESC);
    TEST_CHECK(outputs.error_addr_o == 1u);
    TEST_CHECK(
        outputs.error_detail_o ==
        NPU_L1_STATUS_PORT_PROTOCOL_ERROR);
    TEST_CHECK(outputs.error_write_o == 0u);

    diag_test_inputs_default(&inputs);
    inputs.rsp_ready_i = 0u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.error_valid_o != 0u);
    TEST_CHECK(outputs.error_status_o == NPU_STATUS_BAD_DESC);
    TEST_CHECK(outputs.error_addr_o == 1u);
    TEST_CHECK(outputs.error_write_o == 0u);

    diag_test_inputs_default(&inputs);
    inputs.rsp_ready_i = 1u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(bridge.state == NPU_L1_DIAG_BRIDGE_IDLE);

    diag_test_inputs_default(&inputs);
    inputs.error_clear_i = 1u;
    inputs.req_valid_i = 1u;
    inputs.req_write_i = 1u;
    inputs.req_addr_i = UINT32_C(0x1000000);
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.error_valid_o != 0u);
    TEST_CHECK(outputs.error_addr_o == 1u);

    diag_test_inputs_default(&inputs);
    inputs.rsp_ready_i = 0u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.error_valid_o != 0u);
    TEST_CHECK(outputs.error_status_o == NPU_STATUS_BAD_DESC);
    TEST_CHECK(outputs.error_addr_o == UINT32_C(0x1000000));
    TEST_CHECK(
        outputs.error_detail_o ==
        NPU_L1_STATUS_PORT_PROTOCOL_ERROR);
    TEST_CHECK(outputs.error_write_o != 0u);

    diag_test_inputs_default(&inputs);
    inputs.rsp_ready_i = 1u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    diag_test_inputs_default(&inputs);
    inputs.error_clear_i = 1u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.error_valid_o != 0u);
    diag_test_inputs_default(&inputs);
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.error_valid_o == 0u);

    npu_l1_diag_bridge_reset(&bridge);
    diag_test_inputs_default(&inputs);
    inputs.req_valid_i = 1u;
    inputs.req_addr_i = UINT32_C(0x300);
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    diag_test_inputs_default(&inputs);
    inputs.l1_read_i.req_ready = 1u;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    diag_test_inputs_default(&inputs);
    inputs.l1_read_i.rsp_valid = 1u;
    inputs.l1_read_i.rsp_tag = bridge.request_tag;
    inputs.l1_read_i.rsp_last = 1u;
    inputs.l1_read_i.rsp_status =
        NPU_L1_STATUS_ECC_UNCORRECTABLE;
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    diag_test_inputs_default(&inputs);
    npu_l1_diag_bridge_step(&bridge, &inputs, &outputs);
    TEST_CHECK(outputs.error_valid_o != 0u);
    TEST_CHECK(outputs.error_status_o ==
               NPU_STATUS_L1_ECC_UNCORRECTABLE);
    TEST_CHECK(outputs.error_addr_o == UINT32_C(0x300));
    TEST_CHECK(
        outputs.error_detail_o ==
        NPU_L1_STATUS_ECC_UNCORRECTABLE);
    TEST_CHECK(outputs.error_write_o == 0u);
    return 0;
}

static void diag_test_l1_inputs_from_bridge(
    const npu_l1_diag_bridge_t *bridge,
    npu_l1_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = 1u;

    switch (bridge->state) {
    case NPU_L1_DIAG_BRIDGE_READ_REQUEST:
        inputs->read[NPU_L1_RD_DEBUG].req_valid = 1u;
        inputs->read[NPU_L1_RD_DEBUG].req_addr =
            bridge->request_addr;
        inputs->read[NPU_L1_RD_DEBUG].req_beats = 0u;
        inputs->read[NPU_L1_RD_DEBUG].req_tag =
            bridge->request_tag;
        break;
    case NPU_L1_DIAG_BRIDGE_READ_RESPONSE:
        inputs->read[NPU_L1_RD_DEBUG].rsp_ready = 1u;
        break;
    case NPU_L1_DIAG_BRIDGE_WRITE_REQUEST:
        inputs->write[NPU_L1_WR_DEBUG].req_valid = 1u;
        inputs->write[NPU_L1_WR_DEBUG].req_addr =
            bridge->request_addr;
        inputs->write[NPU_L1_WR_DEBUG].req_beats = 0u;
        inputs->write[NPU_L1_WR_DEBUG].req_tag =
            bridge->request_tag;
        break;
    case NPU_L1_DIAG_BRIDGE_WRITE_DATA:
        inputs->write[NPU_L1_WR_DEBUG].data_valid = 1u;
        inputs->write[NPU_L1_WR_DEBUG].data =
            bridge->request_wdata;
        inputs->write[NPU_L1_WR_DEBUG].strb =
            bridge->request_wstrb;
        inputs->write[NPU_L1_WR_DEBUG].last = 1u;
        break;
    case NPU_L1_DIAG_BRIDGE_WRITE_RESPONSE:
        inputs->write[NPU_L1_WR_DEBUG].rsp_ready = 1u;
        break;
    default:
        break;
    }
}

static int diag_test_integrated_tick(
    npu_l1_diag_bridge_t *bridge,
    uint8_t req_valid,
    uint8_t req_write,
    uint32_t req_addr,
    uint64_t req_wdata,
    uint8_t req_wstrb,
    uint8_t rsp_ready,
    npu_l1_diag_bridge_outputs_t *bridge_outputs)
{
    npu_l1_cycle_inputs_t l1_inputs;
    npu_l1_cycle_outputs_t l1_outputs;
    npu_l1_diag_bridge_inputs_t bridge_inputs;

    diag_test_l1_inputs_from_bridge(bridge, &l1_inputs);
    npu_l1_cycle_step(&diag_test_l1, &l1_inputs, &l1_outputs);

    diag_test_inputs_default(&bridge_inputs);
    bridge_inputs.req_valid_i = req_valid;
    bridge_inputs.req_write_i = req_write;
    bridge_inputs.req_addr_i = req_addr;
    bridge_inputs.req_wdata_i = req_wdata;
    bridge_inputs.req_wstrb_i = req_wstrb;
    bridge_inputs.rsp_ready_i = rsp_ready;
    bridge_inputs.l1_read_i =
        l1_outputs.read[NPU_L1_RD_DEBUG];
    bridge_inputs.l1_write_i =
        l1_outputs.write[NPU_L1_WR_DEBUG];
    npu_l1_diag_bridge_step(
        bridge, &bridge_inputs, bridge_outputs);

    TEST_CHECK(bridge_outputs->l1_read_o.req_valid ==
               l1_inputs.read[NPU_L1_RD_DEBUG].req_valid);
    TEST_CHECK(bridge_outputs->l1_read_o.rsp_ready ==
               l1_inputs.read[NPU_L1_RD_DEBUG].rsp_ready);
    TEST_CHECK(bridge_outputs->l1_write_o.req_valid ==
               l1_inputs.write[NPU_L1_WR_DEBUG].req_valid);
    TEST_CHECK(bridge_outputs->l1_write_o.data_valid ==
               l1_inputs.write[NPU_L1_WR_DEBUG].data_valid);
    TEST_CHECK(bridge_outputs->l1_write_o.rsp_ready ==
               l1_inputs.write[NPU_L1_WR_DEBUG].rsp_ready);
    return 0;
}

static uint64_t diag_test_load_word(uint32_t addr)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < NPU_L1_CYCLE_WORD_BYTES; byte++) {
        value |=
            (uint64_t)diag_test_memory[addr + byte] <<
            (byte * 8u);
    }
    return value;
}

static int diag_test_l1_integration(void)
{
    npu_l1_diag_bridge_t bridge;
    npu_l1_diag_bridge_outputs_t outputs;
    const uint32_t addr = 0x358u;
    const uint64_t initial =
        UINT64_C(0x1122334455667788);
    const uint64_t write_data =
        UINT64_C(0xfedcba9876543210);
    const uint64_t expected =
        UINT64_C(0x11dc339876663288);
    uint32_t cycle;
    int line;

    (void)memset(diag_test_memory, 0,
                 sizeof(diag_test_memory));
    TEST_CHECK(npu_l1_cycle_init(
                   &diag_test_l1,
                   diag_test_memory,
                   sizeof(diag_test_memory),
                   diag_test_ecc,
                   sizeof(diag_test_ecc)) == 0);
    TEST_CHECK(npu_l1_diag_bridge_init(&bridge) == 0);
    for (cycle = 0u; cycle < NPU_L1_CYCLE_WORD_BYTES; cycle++) {
        diag_test_memory[addr + cycle] =
            (uint8_t)(initial >> (cycle * 8u));
    }

    line = diag_test_integrated_tick(
        &bridge, 1u, 0u, addr, 0u, 0u, 0u, &outputs);
    TEST_CHECK(line == 0);
    TEST_CHECK(outputs.req_ready_o != 0u);
    for (cycle = 0u; cycle < DIAG_TEST_MAX_CYCLES; cycle++) {
        line = diag_test_integrated_tick(
            &bridge, 0u, 0u, 0u, 0u, 0u, 0u, &outputs);
        TEST_CHECK(line == 0);
        if (outputs.rsp_valid_o != 0u) {
            break;
        }
    }
    TEST_CHECK(cycle < DIAG_TEST_MAX_CYCLES);
    TEST_CHECK(outputs.rsp_status_o == NPU_L1_STATUS_OK);
    TEST_CHECK(outputs.rsp_rdata_o == initial);
    line = diag_test_integrated_tick(
        &bridge, 0u, 0u, 0u, 0u, 0u, 1u, &outputs);
    TEST_CHECK(line == 0);

    line = diag_test_integrated_tick(
        &bridge, 1u, 1u, addr, write_data, 0x5au,
        0u, &outputs);
    TEST_CHECK(line == 0);
    TEST_CHECK(outputs.req_ready_o != 0u);
    for (cycle = 0u; cycle < DIAG_TEST_MAX_CYCLES; cycle++) {
        line = diag_test_integrated_tick(
            &bridge, 0u, 0u, 0u, 0u, 0u, 0u, &outputs);
        TEST_CHECK(line == 0);
        if (outputs.rsp_valid_o != 0u) {
            break;
        }
    }
    TEST_CHECK(cycle < DIAG_TEST_MAX_CYCLES);
    TEST_CHECK(outputs.rsp_status_o == NPU_L1_STATUS_OK);
    TEST_CHECK(diag_test_load_word(addr) == expected);
    line = diag_test_integrated_tick(
        &bridge, 0u, 0u, 0u, 0u, 0u, 1u, &outputs);
    TEST_CHECK(line == 0);

    /*
     * 0x100000 is aligned and fits the 24-bit bridge address signal, but it
     * is one byte past this test L1 SRAM. L1, rather than the bridge,
     * supplies ADDR_FAULT.
     */
    line = diag_test_integrated_tick(
        &bridge, 1u, 0u, NPU_L1_CYCLE_BYTES,
        0u, 0u, 0u, &outputs);
    TEST_CHECK(line == 0);
    for (cycle = 0u; cycle < DIAG_TEST_MAX_CYCLES; cycle++) {
        line = diag_test_integrated_tick(
            &bridge, 0u, 0u, 0u, 0u, 0u, 0u, &outputs);
        TEST_CHECK(line == 0);
        if (outputs.rsp_valid_o != 0u) {
            break;
        }
    }
    TEST_CHECK(cycle < DIAG_TEST_MAX_CYCLES);
    TEST_CHECK(outputs.rsp_status_o == NPU_L1_STATUS_ADDR_FAULT);
    TEST_CHECK(outputs.rsp_rdata_o == 0u);
    return 0;
}

int test_l1_diag_bridge(void)
{
    int line;

    line = diag_test_init_and_reset();
    if (line != 0) {
        return line;
    }
    line = diag_test_local_protocol_errors();
    if (line != 0) {
        return line;
    }
    line = diag_test_read_random_stalls();
    if (line != 0) {
        return line;
    }
    line = diag_test_read_bad_l1_response();
    if (line != 0) {
        return line;
    }
    line = diag_test_write_independent_stalls();
    if (line != 0) {
        return line;
    }
    line = diag_test_error_record();
    if (line != 0) {
        return line;
    }
    return diag_test_l1_integration();
}

#ifdef NPU_L1_DIAG_BRIDGE_STANDALONE
int main(void)
{
    int line = test_l1_diag_bridge();

    if (line == 0) {
        (void)printf("[PASS] l1_diag_bridge\n");
        return 0;
    }
    (void)printf(
        "[FAIL] l1_diag_bridge at test line %d\n", line);
    return 1;
}
#endif
