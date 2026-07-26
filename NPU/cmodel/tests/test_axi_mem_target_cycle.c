#include "npu_axi_mem_target_cycle.h"
#include "test_util.h"

#include <stdint.h>
#include <string.h>

#define AXI_TEST_MEMORY_BYTES 16384u
#define AXI_TEST_MAX_CYCLES 20000u

static uint8_t axi_test_memory[AXI_TEST_MEMORY_BYTES];

static void axi_test_idle(
    npu_axi_mem_target_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = 1u;
}

static void axi_test_put_u64(size_t offset,
                             uint64_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        axi_test_memory[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static uint64_t axi_test_get_u64(const uint8_t *memory,
                                 size_t offset)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        value |= (uint64_t)memory[offset + byte] <<
                 (byte * 8u);
    }
    return value;
}

static int axi_test_init(
    npu_axi_mem_target_cycle_t *model,
    uint64_t base,
    uint32_t read_latency,
    uint32_t write_latency)
{
    npu_axi_mem_target_config_t config;

    npu_axi_mem_target_config_reference(&config);
    config.read_latency_cycles = read_latency;
    config.write_latency_cycles = write_latency;
    return npu_axi_mem_target_cycle_init(
        model, axi_test_memory, sizeof(axi_test_memory),
        base, &config);
}

static void axi_test_read_request(
    npu_axi_mem_target_cycle_inputs_t *inputs,
    uint8_t id,
    uint64_t addr,
    uint8_t beats)
{
    inputs->master.arvalid = 1u;
    inputs->master.arid = id;
    inputs->master.araddr = addr;
    inputs->master.arlen = (uint8_t)(beats - 1u);
    inputs->master.arsize = 3u;
    inputs->master.arburst = 1u;
}

static void axi_test_write_request(
    npu_axi_mem_target_cycle_inputs_t *inputs,
    uint8_t id,
    uint64_t addr,
    uint8_t beats)
{
    inputs->master.awvalid = 1u;
    inputs->master.awid = id;
    inputs->master.awaddr = addr;
    inputs->master.awlen = (uint8_t)(beats - 1u);
    inputs->master.awsize = 3u;
    inputs->master.awburst = 1u;
}

static int axi_test_latency_strobe_and_stability(void)
{
    const uint64_t base = UINT64_C(0x100000);
    const uint64_t read0 = UINT64_C(0x1122334455667788);
    const uint64_t read1 = UINT64_C(0x8877665544332211);
    npu_axi_mem_target_cycle_t model;
    npu_axi_mem_target_cycle_inputs_t inputs;
    npu_axi_mem_target_cycle_outputs_t outputs;
    npu_axi_mem_target_outputs_t held;
    uint64_t last_w_cycle;
    uint32_t cycle;
    uint32_t byte;

    (void)memset(
        axi_test_memory, 0, sizeof(axi_test_memory));
    axi_test_put_u64(0x100u, read0);
    axi_test_put_u64(0x108u, read1);
    TEST_CHECK(axi_test_init(
        &model, base, 20u, 12u));

    axi_test_idle(&inputs);
    axi_test_read_request(
        &inputs, 0x5au, base + 0x100u, 2u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.arready != 0u);
    TEST_CHECK(outputs.target.rvalid == 0u);
    TEST_CHECK(outputs.cycle == 0u);

    for (cycle = 0u; cycle < 20u; cycle++) {
        axi_test_idle(&inputs);
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.target.rvalid == 0u);
        TEST_CHECK(outputs.cycle == (uint64_t)cycle + 1u);
    }

    axi_test_idle(&inputs);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.cycle == 21u);
    TEST_CHECK(outputs.target.rvalid != 0u);
    TEST_CHECK(outputs.target.rid == 0x5au);
    TEST_CHECK(outputs.target.rdata == read0);
    TEST_CHECK(outputs.target.rresp ==
               NPU_AXI_MEM_RESP_OKAY);
    TEST_CHECK(outputs.target.rlast == 0u);
    held = outputs.target;

    for (cycle = 0u; cycle < 2u; cycle++) {
        axi_test_idle(&inputs);
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.target.rvalid != 0u);
        TEST_CHECK(outputs.target.rid == held.rid);
        TEST_CHECK(outputs.target.rdata == held.rdata);
        TEST_CHECK(outputs.target.rresp == held.rresp);
        TEST_CHECK(outputs.target.rlast == held.rlast);
    }

    axi_test_idle(&inputs);
    inputs.master.rready = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.rdata == read0);
    TEST_CHECK(outputs.target.rlast == 0u);

    axi_test_idle(&inputs);
    inputs.master.rready = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.rvalid != 0u);
    TEST_CHECK(outputs.target.rdata == read1);
    TEST_CHECK(outputs.target.rlast != 0u);

    axi_test_idle(&inputs);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.read_outstanding == 0u);
    TEST_CHECK(outputs.idle != 0u);

    npu_axi_mem_target_cycle_reset(&model);
    for (byte = 0u; byte < 16u; byte++) {
        axi_test_memory[0x200u + byte] = 0xaau;
    }

    axi_test_idle(&inputs);
    inputs.pause_aw = 1u;
    axi_test_write_request(
        &inputs, 0x31u, base + 0x200u, 2u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.awready == 0u);

    inputs.pause_aw = 0u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.awready != 0u);

    axi_test_idle(&inputs);
    inputs.pause_w = 1u;
    inputs.master.wvalid = 1u;
    inputs.master.wdata =
        UINT64_C(0x0102030405060708);
    inputs.master.wstrb = 0x0fu;
    inputs.master.wlast = 0u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.wready == 0u);
    for (byte = 0u; byte < 16u; byte++) {
        TEST_CHECK(
            axi_test_memory[0x200u + byte] == 0xaau);
    }

    inputs.pause_w = 0u;
    npu_axi_mem_target_cycle_eval(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.wready != 0u);
    for (byte = 0u; byte < 16u; byte++) {
        TEST_CHECK(
            axi_test_memory[0x200u + byte] == 0xaau);
    }
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.wready != 0u);
    TEST_CHECK(axi_test_memory[0x200u] == 0x08u);
    TEST_CHECK(axi_test_memory[0x201u] == 0x07u);
    TEST_CHECK(axi_test_memory[0x202u] == 0x06u);
    TEST_CHECK(axi_test_memory[0x203u] == 0x05u);
    for (byte = 4u; byte < 8u; byte++) {
        TEST_CHECK(
            axi_test_memory[0x200u + byte] == 0xaau);
    }

    axi_test_idle(&inputs);
    inputs.master.wvalid = 1u;
    inputs.master.wdata =
        UINT64_C(0x1112131415161718);
    inputs.master.wstrb = 0xf0u;
    inputs.master.wlast = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.wready != 0u);
    last_w_cycle = outputs.cycle;
    for (byte = 0u; byte < 4u; byte++) {
        TEST_CHECK(
            axi_test_memory[0x208u + byte] == 0xaau);
    }
    TEST_CHECK(axi_test_memory[0x20cu] == 0x14u);
    TEST_CHECK(axi_test_memory[0x20du] == 0x13u);
    TEST_CHECK(axi_test_memory[0x20eu] == 0x12u);
    TEST_CHECK(axi_test_memory[0x20fu] == 0x11u);

    for (cycle = 0u; cycle < 12u; cycle++) {
        axi_test_idle(&inputs);
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.target.bvalid == 0u);
        TEST_CHECK(
            outputs.cycle ==
            last_w_cycle + (uint64_t)cycle + 1u);
    }

    axi_test_idle(&inputs);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.bvalid != 0u);
    TEST_CHECK(outputs.target.bid == 0x31u);
    TEST_CHECK(outputs.target.bresp ==
               NPU_AXI_MEM_RESP_OKAY);
    held = outputs.target;

    for (cycle = 0u; cycle < 2u; cycle++) {
        axi_test_idle(&inputs);
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.target.bvalid != 0u);
        TEST_CHECK(outputs.target.bid == held.bid);
        TEST_CHECK(outputs.target.bresp == held.bresp);
    }
    axi_test_idle(&inputs);
    inputs.master.bready = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.bvalid != 0u);
    axi_test_idle(&inputs);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.write_outstanding == 0u);
    TEST_CHECK(outputs.idle != 0u);
    return 0;
}

static int axi_test_wait_for_r(
    npu_axi_mem_target_cycle_t *model,
    npu_axi_mem_target_cycle_inputs_t *inputs,
    npu_axi_mem_target_cycle_outputs_t *outputs,
    uint8_t expected_id,
    uint8_t expected_resp,
    uint16_t beats)
{
    uint32_t cycle;
    uint16_t beat = 0u;

    for (cycle = 0u; cycle < AXI_TEST_MAX_CYCLES;
         cycle++) {
        axi_test_idle(inputs);
        inputs->master.rready = 1u;
        npu_axi_mem_target_cycle_step(
            model, inputs, outputs);
        if (outputs->target.rvalid == 0u) {
            continue;
        }
        TEST_CHECK(outputs->target.rid == expected_id);
        TEST_CHECK(outputs->target.rresp ==
                   expected_resp);
        TEST_CHECK(outputs->target.rlast ==
                   (uint8_t)(beat + 1u == beats));
        beat++;
        if (beat == beats) {
            return 0;
        }
    }
    return __LINE__;
}

static int axi_test_reorder_errors_and_reset(void)
{
    npu_axi_mem_target_cycle_t model;
    npu_axi_mem_target_cycle_inputs_t inputs;
    npu_axi_mem_target_cycle_outputs_t outputs;
    npu_axi_mem_target_injection_t injection;
    npu_axi_mem_target_outputs_t held;
    uint32_t cycle;
    int line;

    (void)memset(
        axi_test_memory, 0, sizeof(axi_test_memory));
    axi_test_put_u64(0x300u, UINT64_C(0xaaaa));
    axi_test_put_u64(0x400u, UINT64_C(0xbbbb));
    TEST_CHECK(axi_test_init(&model, 0u, 2u, 2u));

    (void)memset(&injection, 0, sizeof(injection));
    injection.valid = 1u;
    injection.match_id = 1u;
    injection.id = 1u;
    injection.addr = 0x300u;
    injection.resp = NPU_AXI_MEM_RESP_OKAY;
    injection.extra_delay_cycles = 8u;
    TEST_CHECK(npu_axi_mem_target_set_injection(
        &model, 0u, &injection));
    injection.id = 2u;
    injection.addr = 0x400u;
    injection.resp = NPU_AXI_MEM_RESP_SLVERR;
    injection.extra_delay_cycles = 0u;
    TEST_CHECK(npu_axi_mem_target_set_injection(
        &model, 1u, &injection));

    axi_test_idle(&inputs);
    axi_test_read_request(&inputs, 1u, 0x300u, 1u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.arready != 0u);
    axi_test_idle(&inputs);
    axi_test_read_request(&inputs, 2u, 0x400u, 1u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.arready != 0u);

    for (cycle = 0u; cycle < 2u; cycle++) {
        axi_test_idle(&inputs);
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.target.rvalid == 0u);
    }
    axi_test_idle(&inputs);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.cycle == 4u);
    TEST_CHECK(outputs.target.rvalid != 0u);
    TEST_CHECK(outputs.target.rid == 2u);
    TEST_CHECK(outputs.target.rresp ==
               NPU_AXI_MEM_RESP_SLVERR);
    TEST_CHECK(outputs.target.rdata == 0u);
    held = outputs.target;
    axi_test_idle(&inputs);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.rid == held.rid);
    TEST_CHECK(outputs.target.rdata == held.rdata);
    TEST_CHECK(outputs.target.rresp == held.rresp);
    TEST_CHECK(outputs.target.rlast == held.rlast);
    axi_test_idle(&inputs);
    inputs.master.rready = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);

    line = axi_test_wait_for_r(
        &model, &inputs, &outputs, 1u,
        NPU_AXI_MEM_RESP_OKAY, 1u);
    if (line != 0) {
        return line;
    }

    axi_test_idle(&inputs);
    axi_test_read_request(&inputs, 3u, 0xff8u, 2u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.arready != 0u);
    axi_test_idle(&inputs);
    axi_test_read_request(&inputs, 4u, 0x101u, 1u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.arready != 0u);
    axi_test_idle(&inputs);
    axi_test_read_request(
        &inputs, 5u, AXI_TEST_MEMORY_BYTES, 1u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.arready != 0u);

    line = axi_test_wait_for_r(
        &model, &inputs, &outputs, 3u,
        NPU_AXI_MEM_RESP_DECERR, 2u);
    if (line != 0) {
        return line;
    }
    line = axi_test_wait_for_r(
        &model, &inputs, &outputs, 4u,
        NPU_AXI_MEM_RESP_DECERR, 1u);
    if (line != 0) {
        return line;
    }
    line = axi_test_wait_for_r(
        &model, &inputs, &outputs, 5u,
        NPU_AXI_MEM_RESP_DECERR, 1u);
    if (line != 0) {
        return line;
    }

    npu_axi_mem_target_cycle_reset(&model);
    npu_axi_mem_target_clear_injections(&model);
    (void)memset(&injection, 0, sizeof(injection));
    injection.valid = 1u;
    injection.write = 1u;
    injection.match_id = 1u;
    injection.id = 0x11u;
    injection.addr = 0x500u;
    injection.resp = NPU_AXI_MEM_RESP_OKAY;
    injection.extra_delay_cycles = 8u;
    TEST_CHECK(npu_axi_mem_target_set_injection(
        &model, 2u, &injection));
    injection.id = 0x22u;
    injection.addr = 0x600u;
    injection.resp = NPU_AXI_MEM_RESP_SLVERR;
    injection.extra_delay_cycles = 0u;
    TEST_CHECK(npu_axi_mem_target_set_injection(
        &model, 3u, &injection));

    axi_test_idle(&inputs);
    axi_test_write_request(
        &inputs, 0x11u, 0x500u, 1u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.awready != 0u);
    axi_test_idle(&inputs);
    axi_test_write_request(
        &inputs, 0x22u, 0x600u, 1u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.awready != 0u);

    axi_test_idle(&inputs);
    inputs.master.wvalid = 1u;
    inputs.master.wdata = UINT64_C(0x1111);
    inputs.master.wstrb = 0xffu;
    inputs.master.wlast = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.wready != 0u);
    axi_test_idle(&inputs);
    inputs.master.wvalid = 1u;
    inputs.master.wdata = UINT64_C(0x2222);
    inputs.master.wstrb = 0xffu;
    inputs.master.wlast = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.wready != 0u);
    TEST_CHECK(axi_test_get_u64(
                   axi_test_memory, 0x500u) ==
               UINT64_C(0x1111));
    TEST_CHECK(axi_test_get_u64(
                   axi_test_memory, 0x600u) == 0u);

    for (cycle = 0u; cycle < AXI_TEST_MAX_CYCLES;
         cycle++) {
        axi_test_idle(&inputs);
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);
        if (outputs.target.bvalid != 0u) {
            break;
        }
    }
    TEST_CHECK(cycle < AXI_TEST_MAX_CYCLES);
    TEST_CHECK(outputs.target.bid == 0x22u);
    TEST_CHECK(outputs.target.bresp ==
               NPU_AXI_MEM_RESP_SLVERR);
    axi_test_idle(&inputs);
    inputs.master.bready = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);

    for (cycle = 0u; cycle < AXI_TEST_MAX_CYCLES;
         cycle++) {
        axi_test_idle(&inputs);
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);
        if (outputs.target.bvalid != 0u) {
            break;
        }
    }
    TEST_CHECK(cycle < AXI_TEST_MAX_CYCLES);
    TEST_CHECK(outputs.target.bid == 0x11u);
    TEST_CHECK(outputs.target.bresp ==
               NPU_AXI_MEM_RESP_OKAY);
    axi_test_idle(&inputs);
    inputs.master.bready = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);

    npu_axi_mem_target_cycle_reset(&model);
    npu_axi_mem_target_clear_injections(&model);
    axi_test_memory[0x700u] = 0x5au;
    axi_test_idle(&inputs);
    axi_test_write_request(
        &inputs, 0x33u, 0x700u, 2u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    axi_test_idle(&inputs);
    inputs.master.wvalid = 1u;
    inputs.master.wdata = UINT64_C(0xdeadbeef);
    inputs.master.wstrb = 0xffu;
    inputs.master.wlast = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.wready != 0u);
    TEST_CHECK(axi_test_memory[0x700u] == 0x5au);
    axi_test_idle(&inputs);
    inputs.master.wvalid = 1u;
    inputs.master.wdata = UINT64_C(0xcafebabe);
    inputs.master.wstrb = 0xffu;
    inputs.master.wlast = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.wready != 0u);
    TEST_CHECK(axi_test_memory[0x700u] == 0x5au);
    axi_test_idle(&inputs);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_AXI_MEM_PROTOCOL_WLAST);
    TEST_CHECK(outputs.protocol_error_id == 0x33u);

    for (cycle = 0u; cycle < AXI_TEST_MAX_CYCLES;
         cycle++) {
        axi_test_idle(&inputs);
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);
        if (outputs.target.bvalid != 0u) {
            break;
        }
    }
    TEST_CHECK(cycle < AXI_TEST_MAX_CYCLES);
    TEST_CHECK(outputs.target.bresp ==
               NPU_AXI_MEM_RESP_SLVERR);

    axi_test_idle(&inputs);
    inputs.reset_n = 0u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.idle != 0u);
    TEST_CHECK(outputs.read_outstanding == 0u);
    TEST_CHECK(outputs.write_outstanding == 0u);
    TEST_CHECK(axi_test_memory[0x700u] == 0x5au);
    TEST_CHECK(model.injection[0].valid == 0u);
    return 0;
}

static int axi_test_same_id_response_order(void)
{
    npu_axi_mem_target_cycle_t model;
    npu_axi_mem_target_cycle_inputs_t inputs;
    npu_axi_mem_target_cycle_outputs_t outputs;
    npu_axi_mem_target_injection_t injection;
    uint32_t cycle;

    (void)memset(
        axi_test_memory, 0, sizeof(axi_test_memory));
    axi_test_put_u64(
        0x100u, UINT64_C(0x1111222233334444));
    axi_test_put_u64(
        0x200u, UINT64_C(0xaaaabbbbccccdddd));
    TEST_CHECK(axi_test_init(&model, 0u, 0u, 0u));

    (void)memset(&injection, 0, sizeof(injection));
    injection.valid = 1u;
    injection.match_id = 1u;
    injection.id = 0x44u;
    injection.addr = 0x100u;
    injection.resp = NPU_AXI_MEM_RESP_EXOKAY;
    injection.extra_delay_cycles = 5u;
    TEST_CHECK(npu_axi_mem_target_set_injection(
        &model, 0u, &injection));

    axi_test_idle(&inputs);
    axi_test_read_request(&inputs, 0x44u, 0x100u, 1u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.arready != 0u);
    axi_test_idle(&inputs);
    axi_test_read_request(&inputs, 0x44u, 0x200u, 1u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.arready != 0u);

    for (cycle = 0u; cycle < AXI_TEST_MAX_CYCLES;
         cycle++) {
        axi_test_idle(&inputs);
        inputs.master.rready = 1u;
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);
        if (outputs.target.rvalid != 0u) {
            break;
        }
    }
    TEST_CHECK(cycle < AXI_TEST_MAX_CYCLES);
    TEST_CHECK(outputs.target.rid == 0x44u);
    TEST_CHECK(outputs.target.rresp ==
               NPU_AXI_MEM_RESP_EXOKAY);
    TEST_CHECK(outputs.target.rdata ==
               UINT64_C(0x1111222233334444));

    axi_test_idle(&inputs);
    inputs.master.rready = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.rvalid != 0u);
    TEST_CHECK(outputs.target.rid == 0x44u);
    TEST_CHECK(outputs.target.rresp ==
               NPU_AXI_MEM_RESP_OKAY);
    TEST_CHECK(outputs.target.rdata ==
               UINT64_C(0xaaaabbbbccccdddd));

    npu_axi_mem_target_cycle_reset(&model);
    npu_axi_mem_target_clear_injections(&model);
    (void)memset(&injection, 0, sizeof(injection));
    injection.valid = 1u;
    injection.write = 1u;
    injection.match_id = 1u;
    injection.id = 0x55u;
    injection.addr = 0x300u;
    injection.resp = NPU_AXI_MEM_RESP_EXOKAY;
    injection.extra_delay_cycles = 5u;
    TEST_CHECK(npu_axi_mem_target_set_injection(
        &model, 0u, &injection));

    axi_test_idle(&inputs);
    axi_test_write_request(&inputs, 0x55u, 0x300u, 1u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.awready != 0u);
    axi_test_idle(&inputs);
    axi_test_write_request(&inputs, 0x55u, 0x400u, 1u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.awready != 0u);

    axi_test_idle(&inputs);
    inputs.master.wvalid = 1u;
    inputs.master.wdata = UINT64_C(0x3030);
    inputs.master.wstrb = 0xffu;
    inputs.master.wlast = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.wready != 0u);
    axi_test_idle(&inputs);
    inputs.master.wvalid = 1u;
    inputs.master.wdata = UINT64_C(0x4040);
    inputs.master.wstrb = 0xffu;
    inputs.master.wlast = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.wready != 0u);

    for (cycle = 0u; cycle < AXI_TEST_MAX_CYCLES;
         cycle++) {
        axi_test_idle(&inputs);
        inputs.master.bready = 1u;
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);
        if (outputs.target.bvalid != 0u) {
            break;
        }
    }
    TEST_CHECK(cycle < AXI_TEST_MAX_CYCLES);
    TEST_CHECK(outputs.target.bid == 0x55u);
    TEST_CHECK(outputs.target.bresp ==
               NPU_AXI_MEM_RESP_EXOKAY);

    axi_test_idle(&inputs);
    inputs.master.bready = 1u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.bvalid != 0u);
    TEST_CHECK(outputs.target.bid == 0x55u);
    TEST_CHECK(outputs.target.bresp ==
               NPU_AXI_MEM_RESP_OKAY);
    return 0;
}

static int axi_test_capacity_and_reset(void)
{
    npu_axi_mem_target_cycle_t model;
    npu_axi_mem_target_cycle_inputs_t inputs;
    npu_axi_mem_target_cycle_outputs_t outputs;
    npu_axi_mem_target_injection_t injection;
    uint32_t index;

    (void)memset(
        axi_test_memory, 0, sizeof(axi_test_memory));
    axi_test_memory[0] = 0xa5u;
    TEST_CHECK(axi_test_init(&model, 0u, 100u, 100u));
    (void)memset(&injection, 0, sizeof(injection));
    injection.valid = 1u;
    injection.addr = 0x100u;
    injection.resp = NPU_AXI_MEM_RESP_SLVERR;
    TEST_CHECK(npu_axi_mem_target_set_injection(
        &model, 0u, &injection));

    for (index = 0u;
         index < NPU_AXI_MEM_TARGET_MAX_READS; index++) {
        axi_test_idle(&inputs);
        axi_test_read_request(
            &inputs, (uint8_t)index,
            0x100u + (uint64_t)index * 8u, 1u);
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.target.arready != 0u);
    }
    axi_test_idle(&inputs);
    axi_test_read_request(&inputs, 0xeeu, 0x800u, 1u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.arready == 0u);
    TEST_CHECK(model.read_count ==
               NPU_AXI_MEM_TARGET_MAX_READS);

    for (index = 0u;
         index < NPU_AXI_MEM_TARGET_MAX_WRITES; index++) {
        axi_test_idle(&inputs);
        axi_test_write_request(
            &inputs, (uint8_t)(0x80u + index),
            0x1000u + (uint64_t)index * 8u, 1u);
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.target.awready != 0u);
    }
    axi_test_idle(&inputs);
    axi_test_write_request(
        &inputs, 0xffu, 0x1800u, 1u);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.awready == 0u);
    TEST_CHECK(model.write_count ==
               NPU_AXI_MEM_TARGET_MAX_WRITES);

    axi_test_idle(&inputs);
    inputs.reset_n = 0u;
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.idle != 0u);
    TEST_CHECK(model.read_count == 0u);
    TEST_CHECK(model.write_count == 0u);
    TEST_CHECK(axi_test_memory[0] == 0xa5u);
    TEST_CHECK(model.injection[0].valid != 0u);

    axi_test_idle(&inputs);
    npu_axi_mem_target_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.target.arready != 0u);
    TEST_CHECK(outputs.target.awready != 0u);
    return 0;
}

static uint32_t axi_test_random_next(uint32_t *state)
{
    *state = *state * UINT32_C(1664525) +
             UINT32_C(1013904223);
    return *state;
}

static int axi_test_find_id(const uint8_t ids[4],
                            uint8_t id)
{
    uint32_t index;

    for (index = 0u; index < 4u; index++) {
        if (ids[index] == id) {
            return (int)index;
        }
    }
    return -1;
}

static int axi_test_random_pauses(void)
{
    static const uint8_t beats[4] = {1u, 4u, 2u, 3u};
    static const uint8_t ids[4] = {
        0x41u, 0x52u, 0x63u, 0x74u
    };
    static const uint64_t addr[4] = {
        0x1000u, 0x1100u, 0x1200u, 0x1300u
    };
    uint64_t data[4][4];
    uint8_t strb[4][4];
    uint8_t expected[AXI_TEST_MEMORY_BYTES];
    npu_axi_mem_target_cycle_t model;
    npu_axi_mem_target_cycle_inputs_t inputs;
    npu_axi_mem_target_cycle_outputs_t outputs;
    npu_axi_mem_target_outputs_t held_b = {0};
    npu_axi_mem_target_outputs_t held_r = {0};
    uint8_t b_seen[4] = {0u, 0u, 0u, 0u};
    uint8_t read_beat[4] = {0u, 0u, 0u, 0u};
    uint8_t held_b_valid = 0u;
    uint8_t held_r_valid = 0u;
    uint32_t random_state = UINT32_C(0x1234abcd);
    uint32_t random_value;
    uint32_t aw_index = 0u;
    uint32_t aw_accepted = 0u;
    uint32_t w_transaction = 0u;
    uint32_t w_beat = 0u;
    uint32_t b_count = 0u;
    uint32_t ar_index = 0u;
    uint32_t r_count = 0u;
    uint32_t cycle;
    uint32_t transaction;
    uint32_t beat;
    uint32_t byte;

    (void)memset(
        axi_test_memory, 0xa5, sizeof(axi_test_memory));
    (void)memcpy(
        expected, axi_test_memory, sizeof(expected));
    for (transaction = 0u; transaction < 4u;
         transaction++) {
        for (beat = 0u; beat < beats[transaction];
             beat++) {
            data[transaction][beat] =
                ((uint64_t)ids[transaction] << 56u) |
                ((uint64_t)beat << 48u) |
                UINT64_C(0x0011223344556677);
            strb[transaction][beat] =
                transaction == 3u &&
                        beat + 1u == beats[transaction]
                    ? 0x17u
                    : 0xffu;
        }
    }
    TEST_CHECK(axi_test_init(&model, 0u, 3u, 2u));

    for (cycle = 0u; cycle < AXI_TEST_MAX_CYCLES;
         cycle++) {
        int b_index;

        axi_test_idle(&inputs);
        random_value = axi_test_random_next(
            &random_state);
        inputs.pause_aw =
            (uint8_t)(random_value & 1u);
        inputs.pause_w =
            (uint8_t)((random_value >> 1u) & 1u);
        inputs.master.bready =
            (uint8_t)((random_value >> 2u) & 1u);
        if (aw_index < 4u) {
            axi_test_write_request(
                &inputs, ids[aw_index],
                addr[aw_index], beats[aw_index]);
        }
        if (w_transaction < 4u &&
            w_transaction < aw_accepted) {
            inputs.master.wvalid = 1u;
            inputs.master.wdata =
                data[w_transaction][w_beat];
            inputs.master.wstrb =
                strb[w_transaction][w_beat];
            inputs.master.wlast =
                (uint8_t)(
                    w_beat + 1u ==
                    beats[w_transaction]);
        }
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);

        if (held_b_valid != 0u) {
            TEST_CHECK(outputs.target.bvalid != 0u);
            TEST_CHECK(outputs.target.bid == held_b.bid);
            TEST_CHECK(outputs.target.bresp ==
                       held_b.bresp);
        }
        held_b_valid =
            outputs.target.bvalid != 0u &&
                    inputs.master.bready == 0u
                ? 1u
                : 0u;
        held_b = outputs.target;

        if (inputs.master.awvalid != 0u &&
            outputs.target.awready != 0u) {
            aw_index++;
            aw_accepted++;
        }
        if (inputs.master.wvalid != 0u &&
            outputs.target.wready != 0u) {
            size_t offset =
                (size_t)addr[w_transaction] +
                (size_t)w_beat * 8u;

            for (byte = 0u; byte < 8u; byte++) {
                if ((strb[w_transaction][w_beat] &
                     (uint8_t)(1u << byte)) != 0u) {
                    expected[offset + byte] =
                        (uint8_t)(
                            data[w_transaction][w_beat] >>
                            (byte * 8u));
                }
            }
            w_beat++;
            if (w_beat == beats[w_transaction]) {
                w_transaction++;
                w_beat = 0u;
            }
        }
        if (outputs.target.bvalid != 0u &&
            inputs.master.bready != 0u) {
            b_index = axi_test_find_id(
                ids, outputs.target.bid);
            TEST_CHECK(b_index >= 0);
            TEST_CHECK(outputs.target.bresp ==
                       NPU_AXI_MEM_RESP_OKAY);
            TEST_CHECK(b_seen[b_index] == 0u);
            b_seen[b_index] = 1u;
            b_count++;
        }
        if (b_count == 4u) {
            break;
        }
    }
    TEST_CHECK(cycle < AXI_TEST_MAX_CYCLES);
    TEST_CHECK(aw_index == 4u);
    TEST_CHECK(w_transaction == 4u);
    TEST_CHECK(memcmp(
                   axi_test_memory, expected,
                   sizeof(expected)) == 0);

    npu_axi_mem_target_cycle_reset(&model);
    held_r_valid = 0u;
    random_state = UINT32_C(0x89abcdef);
    for (cycle = 0u; cycle < AXI_TEST_MAX_CYCLES;
         cycle++) {
        int r_index;

        axi_test_idle(&inputs);
        random_value = axi_test_random_next(
            &random_state);
        inputs.pause_ar =
            (uint8_t)(random_value & 1u);
        inputs.master.rready =
            (uint8_t)((random_value >> 1u) & 1u);
        if (ar_index < 4u) {
            axi_test_read_request(
                &inputs, ids[ar_index],
                addr[ar_index], beats[ar_index]);
        }
        npu_axi_mem_target_cycle_step(
            &model, &inputs, &outputs);

        if (held_r_valid != 0u) {
            TEST_CHECK(outputs.target.rvalid != 0u);
            TEST_CHECK(outputs.target.rid == held_r.rid);
            TEST_CHECK(outputs.target.rdata ==
                       held_r.rdata);
            TEST_CHECK(outputs.target.rresp ==
                       held_r.rresp);
            TEST_CHECK(outputs.target.rlast ==
                       held_r.rlast);
        }
        held_r_valid =
            outputs.target.rvalid != 0u &&
                    inputs.master.rready == 0u
                ? 1u
                : 0u;
        held_r = outputs.target;

        if (inputs.master.arvalid != 0u &&
            outputs.target.arready != 0u) {
            ar_index++;
        }
        if (outputs.target.rvalid != 0u &&
            inputs.master.rready != 0u) {
            size_t offset;

            r_index = axi_test_find_id(
                ids, outputs.target.rid);
            TEST_CHECK(r_index >= 0);
            offset = (size_t)addr[r_index] +
                     (size_t)read_beat[r_index] * 8u;
            TEST_CHECK(outputs.target.rresp ==
                       NPU_AXI_MEM_RESP_OKAY);
            TEST_CHECK(
                outputs.target.rdata ==
                axi_test_get_u64(expected, offset));
            TEST_CHECK(
                outputs.target.rlast ==
                (uint8_t)(
                    read_beat[r_index] + 1u ==
                    beats[r_index]));
            read_beat[r_index]++;
            r_count++;
        }
        if (r_count == 10u) {
            break;
        }
    }
    TEST_CHECK(cycle < AXI_TEST_MAX_CYCLES);
    TEST_CHECK(ar_index == 4u);
    for (transaction = 0u; transaction < 4u;
         transaction++) {
        TEST_CHECK(
            read_beat[transaction] == beats[transaction]);
    }
    return 0;
}

static int axi_test_conversion_helpers(void)
{
    npu_mif_axi_outputs_t mif_master;
    npu_gc_axi_bus_outputs_t gc_master;
    npu_axi_mem_master_outputs_t common_master;
    npu_axi_mem_target_outputs_t common_target;
    npu_mif_axi_inputs_t mif_target;
    npu_gc_axi_bus_inputs_t gc_target;

    (void)memset(&mif_master, 0, sizeof(mif_master));
    mif_master.awid = 0x12u;
    mif_master.awaddr = UINT64_C(0x12345678);
    mif_master.awlen = 15u;
    mif_master.wdata = UINT64_C(0x8877665544332211);
    mif_master.wstrb = 0xa5u;
    mif_master.wlast = 1u;
    mif_master.arid = 0x34u;
    mif_master.araddr = UINT64_C(0xabcdef00);
    mif_master.rready = 1u;
    npu_axi_mem_master_from_mif(
        &common_master, &mif_master);
    TEST_CHECK(common_master.awid == mif_master.awid);
    TEST_CHECK(common_master.awaddr ==
               mif_master.awaddr);
    TEST_CHECK(common_master.awlen == mif_master.awlen);
    TEST_CHECK(common_master.wdata == mif_master.wdata);
    TEST_CHECK(common_master.wstrb == mif_master.wstrb);
    TEST_CHECK(common_master.wlast == mif_master.wlast);
    TEST_CHECK(common_master.arid == mif_master.arid);
    TEST_CHECK(common_master.araddr ==
               mif_master.araddr);
    TEST_CHECK(common_master.rready ==
               mif_master.rready);

    gc_master = (npu_gc_axi_bus_outputs_t){0};
    gc_master.awid = 0x56u;
    gc_master.awaddr = UINT64_C(0x10203040);
    gc_master.wdata = UINT64_C(0x1020304050607080);
    gc_master.arid = 0x78u;
    gc_master.araddr = UINT64_C(0x50607080);
    gc_master.bready = 1u;
    npu_axi_mem_master_from_gc(
        &common_master, &gc_master);
    TEST_CHECK(common_master.awid == gc_master.awid);
    TEST_CHECK(common_master.awaddr ==
               gc_master.awaddr);
    TEST_CHECK(common_master.wdata == gc_master.wdata);
    TEST_CHECK(common_master.arid == gc_master.arid);
    TEST_CHECK(common_master.araddr ==
               gc_master.araddr);
    TEST_CHECK(common_master.bready ==
               gc_master.bready);

    common_target =
        (npu_axi_mem_target_outputs_t){0};
    common_target.awready = 1u;
    common_target.wready = 1u;
    common_target.bvalid = 1u;
    common_target.bid = 0x91u;
    common_target.bresp = NPU_AXI_MEM_RESP_SLVERR;
    common_target.arready = 1u;
    common_target.rvalid = 1u;
    common_target.rid = 0x92u;
    common_target.rdata =
        UINT64_C(0xfedcba9876543210);
    common_target.rresp = NPU_AXI_MEM_RESP_DECERR;
    common_target.rlast = 1u;
    npu_axi_mem_target_to_mif(
        &mif_target, &common_target);
    npu_axi_mem_target_to_gc(
        &gc_target, &common_target);
    TEST_CHECK(mif_target.awready ==
               common_target.awready);
    TEST_CHECK(mif_target.bid == common_target.bid);
    TEST_CHECK(mif_target.bresp ==
               common_target.bresp);
    TEST_CHECK(mif_target.rid == common_target.rid);
    TEST_CHECK(mif_target.rdata ==
               common_target.rdata);
    TEST_CHECK(mif_target.rresp ==
               common_target.rresp);
    TEST_CHECK(mif_target.rlast ==
               common_target.rlast);
    TEST_CHECK(gc_target.awready ==
               common_target.awready);
    TEST_CHECK(gc_target.bid == common_target.bid);
    TEST_CHECK(gc_target.bresp ==
               common_target.bresp);
    TEST_CHECK(gc_target.rid == common_target.rid);
    TEST_CHECK(gc_target.rdata ==
               common_target.rdata);
    TEST_CHECK(gc_target.rresp ==
               common_target.rresp);
    TEST_CHECK(gc_target.rlast ==
               common_target.rlast);
    return 0;
}

int test_axi_mem_target_cycle(void)
{
    int line;

    line = axi_test_latency_strobe_and_stability();
    if (line != 0) {
        return line;
    }
    line = axi_test_reorder_errors_and_reset();
    if (line != 0) {
        return line;
    }
    line = axi_test_same_id_response_order();
    if (line != 0) {
        return line;
    }
    line = axi_test_capacity_and_reset();
    if (line != 0) {
        return line;
    }
    line = axi_test_random_pauses();
    if (line != 0) {
        return line;
    }
    return axi_test_conversion_helpers();
}

#ifdef NPU_AXI_MEM_TARGET_CYCLE_STANDALONE
int main(void)
{
    return test_axi_mem_target_cycle();
}
#endif
