#include "npu_l1_cycle.h"

#include <string.h>

#ifdef NPU_L1_CYCLE_STANDALONE
#include <stdio.h>
#endif

#define L1_TEST_CHECK(condition)    \
    do {                            \
        if (!(condition)) {         \
            return __LINE__;        \
        }                           \
    } while (0)

static uint8_t l1_test_memory[NPU_L1_CYCLE_BYTES];
static uint8_t l1_test_ecc[NPU_L1_CYCLE_WORDS];
static npu_l1_cycle_t l1_test_controller;
static uint32_t l1_test_param_base;
static uint32_t l1_test_param_limit;
static uint8_t l1_test_param_lock;
static uint8_t l1_test_param_write_allow_mask;

static void l1_test_set_param_signals(uint32_t base,
                                      uint32_t limit,
                                      uint8_t lock)
{
    l1_test_param_base = base;
    l1_test_param_limit = limit;
    l1_test_param_lock = lock;
    l1_test_param_write_allow_mask = 0u;
}

static void l1_test_reset_controller(void)
{
    npu_l1_cycle_reset(&l1_test_controller);
    l1_test_set_param_signals(0u, 0u, 0u);
}

static void l1_test_inputs_default(npu_l1_cycle_inputs_t *inputs)
{
    uint32_t port;

    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = 1u;
    inputs->param_l1_base = l1_test_param_base;
    inputs->param_l1_limit = l1_test_param_limit;
    inputs->param_lock = l1_test_param_lock;
    inputs->param_write_allow_mask =
        l1_test_param_write_allow_mask;
    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        inputs->read[port].rsp_ready = 1u;
    }
    for (port = 0u; port < NPU_L1_WRITE_PORT_COUNT; port++) {
        inputs->write[port].rsp_ready = 1u;
    }
}

static void l1_test_put_word(uint32_t addr, uint64_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < NPU_L1_CYCLE_WORD_BYTES; byte++) {
        l1_test_memory[addr + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static uint64_t l1_test_get_word(uint32_t addr)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < NPU_L1_CYCLE_WORD_BYTES; byte++) {
        value |=
            (uint64_t)l1_test_memory[addr + byte] <<
            (byte * 8u);
    }
    return value;
}

static int l1_test_single_write(uint32_t port,
                                uint32_t addr,
                                uint16_t tag,
                                uint64_t data,
                                uint8_t expected_status)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;

    l1_test_inputs_default(&inputs);
    inputs.write[port].req_valid = 1u;
    inputs.write[port].req_addr = addr;
    inputs.write[port].req_tag = tag;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[port].req_ready != 0u);

    l1_test_inputs_default(&inputs);
    inputs.write[port].data_valid = 1u;
    inputs.write[port].data = data;
    inputs.write[port].strb = 0xffu;
    inputs.write[port].last = 1u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[port].data_ready != 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[port].rsp_valid == 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[port].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.write[port].rsp_tag == tag);
    L1_TEST_CHECK(outputs.write[port].rsp_status ==
                  expected_status);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[port].rsp_valid == 0u);
    L1_TEST_CHECK(outputs.write_idle != 0u);
    return 0;
}

static int l1_test_single_read(uint32_t port,
                               uint32_t addr,
                               uint16_t tag,
                               uint64_t expected_data)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;

    l1_test_inputs_default(&inputs);
    inputs.read[port].req_valid = 1u;
    inputs.read[port].req_addr = addr;
    inputs.read[port].req_tag = tag;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[port].req_ready != 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[port].rsp_valid == 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[port].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.read[port].rsp_data == expected_data);
    L1_TEST_CHECK(outputs.read[port].rsp_tag == tag);
    L1_TEST_CHECK(outputs.read[port].rsp_status ==
                  NPU_L1_STATUS_OK);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[port].rsp_valid == 0u);
    return 0;
}

static int l1_test_init_reset(void)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;

    (void)memset(l1_test_memory, 0, sizeof(l1_test_memory));
    l1_test_memory[7] = 0x5au;
    L1_TEST_CHECK(npu_l1_cycle_init(
                      &l1_test_controller,
                      l1_test_memory,
                      sizeof(l1_test_memory),
                      l1_test_ecc,
                      sizeof(l1_test_ecc)) == 0);
    l1_test_set_param_signals(0u, 0u, 0u);
    L1_TEST_CHECK(l1_test_memory[7] == 0x5au);
    L1_TEST_CHECK(npu_l1_cycle_idle(&l1_test_controller) != 0u);
    L1_TEST_CHECK(l1_test_controller.cycle == 0u);
    L1_TEST_CHECK(npu_l1_cycle_inject_ecc(
                      &l1_test_controller, 1u,
                      NPU_L1_STATUS_ECC_CORRECTED) != 0);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.idle != 0u);
    L1_TEST_CHECK(outputs.write_idle != 0u);
    L1_TEST_CHECK(outputs.cycle == 0u);
    L1_TEST_CHECK(l1_test_controller.cycle == 1u);

    l1_test_reset_controller();
    L1_TEST_CHECK(npu_l1_cycle_idle(&l1_test_controller) != 0u);
    L1_TEST_CHECK(l1_test_controller.cycle == 0u);
    L1_TEST_CHECK(l1_test_memory[7] == 0x5au);
    return 0;
}

static int l1_test_signal_reset_and_write_idle(void)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;
    const uint32_t read_addr = 0x500u;
    const uint32_t write_addr = 0x600u;
    const uint64_t preserved =
        UINT64_C(0x0123456789abcdef);

    l1_test_reset_controller();
    l1_test_put_word(read_addr, preserved);
    l1_test_put_word(write_addr, 0u);
    l1_test_set_param_signals(0x700u, 0x780u, 1u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.idle != 0u);
    L1_TEST_CHECK(outputs.write_idle != 0u);

    /*
     * A read makes the whole controller busy but does not make the
     * write-only idle indication false.
     */
    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_DMA].req_valid = 1u;
    inputs.read[NPU_L1_RD_DMA].req_addr = read_addr;
    inputs.read[NPU_L1_RD_DMA].req_tag = 0x101u;
    inputs.read[NPU_L1_RD_DMA].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_DMA].req_ready != 0u);
    L1_TEST_CHECK(outputs.write_idle != 0u);

    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_DMA].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.idle == 0u);
    L1_TEST_CHECK(outputs.write_idle != 0u);

    /*
     * reset_n synchronously clears accepted requests, responses, counters,
     * and cycle state while retaining SRAM contents. Parameter control
     * remains an external input.
     */
    l1_test_inputs_default(&inputs);
    inputs.reset_n = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.idle != 0u);
    L1_TEST_CHECK(outputs.write_idle != 0u);
    L1_TEST_CHECK(outputs.cycle == 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_DMA].req_ready == 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_DMA].rsp_valid == 0u);
    L1_TEST_CHECK(outputs.ecc_corrected_pulse == 0u);
    L1_TEST_CHECK(outputs.ecc_uncorrectable_pulse == 0u);
    L1_TEST_CHECK(l1_test_controller.cycle == 0u);
    L1_TEST_CHECK(l1_test_get_word(read_addr) == preserved);

    /*
     * write_idle remains false through request data, completion delay,
     * a held response, and the response handshake. It becomes true on the
     * following cycle.
     */
    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].req_valid = 1u;
    inputs.write[NPU_L1_WR_DMA].req_addr = write_addr;
    inputs.write[NPU_L1_WR_DMA].req_tag = 0x102u;
    inputs.write[NPU_L1_WR_DMA].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].req_ready != 0u);
    L1_TEST_CHECK(outputs.write_idle != 0u);

    /*
     * data_ready describes receiver capacity and therefore remains high
     * while data_valid is low and the one-beat input slot is empty.
     */
    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(inputs.write[NPU_L1_WR_DMA].data_valid == 0u);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].data_ready != 0u);
    L1_TEST_CHECK(outputs.write_idle == 0u);
    L1_TEST_CHECK(l1_test_get_word(write_addr) != preserved);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].data_valid = 1u;
    inputs.write[NPU_L1_WR_DMA].data = preserved;
    inputs.write[NPU_L1_WR_DMA].strb = 0xffu;
    inputs.write[NPU_L1_WR_DMA].last = 1u;
    inputs.write[NPU_L1_WR_DMA].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].data_ready != 0u);
    L1_TEST_CHECK(outputs.write_idle == 0u);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_valid == 0u);
    L1_TEST_CHECK(outputs.write_idle == 0u);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.write_idle == 0u);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.write_idle == 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.write_idle == 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_valid == 0u);
    L1_TEST_CHECK(outputs.write_idle != 0u);
    L1_TEST_CHECK(outputs.idle != 0u);
    return 0;
}

static int l1_test_read_latency_and_stall(void)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;
    npu_l1_cycle_read_output_t held;
    const uint32_t addr = 0x080u;

    l1_test_reset_controller();
    l1_test_put_word(addr + 0u, UINT64_C(0x0123456789abcdef));
    l1_test_put_word(addr + 8u, UINT64_C(0x1111222233334444));
    l1_test_put_word(addr + 16u, UINT64_C(0xaabbccddeeff0011));

    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_ME_A].req_valid = 1u;
    inputs.read[NPU_L1_RD_ME_A].req_addr = addr;
    inputs.read[NPU_L1_RD_ME_A].req_beats = 2u;
    inputs.read[NPU_L1_RD_ME_A].req_tag = 0x123u;
    inputs.read[NPU_L1_RD_ME_A].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].req_ready != 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_valid == 0u);
    L1_TEST_CHECK(npu_l1_cycle_idle(&l1_test_controller) == 0u);

    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_ME_A].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_valid == 0u);

    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_ME_A].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_data ==
                  UINT64_C(0x0123456789abcdef));
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_tag == 0x123u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_last == 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_status ==
                  NPU_L1_STATUS_OK);
    held = outputs.read[NPU_L1_RD_ME_A];

    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_ME_A].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_valid ==
                  held.rsp_valid);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_data ==
                  held.rsp_data);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_tag ==
                  held.rsp_tag);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_last ==
                  held.rsp_last);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_status ==
                  held.rsp_status);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_data ==
                  UINT64_C(0x0123456789abcdef));

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_data ==
                  UINT64_C(0x1111222233334444));
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_last == 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_data ==
                  UINT64_C(0xaabbccddeeff0011));
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_last != 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_valid == 0u);
    L1_TEST_CHECK(outputs.idle != 0u);
    return 0;
}

static int l1_test_parallel_banks_and_priority(void)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;
    const uint64_t new_value = UINT64_C(0x8877665544332211);

    l1_test_reset_controller();
    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_ME_A].req_valid = 1u;
    inputs.read[NPU_L1_RD_ME_A].req_addr = 0x000u;
    inputs.read[NPU_L1_RD_ME_A].req_tag = 1u;
    inputs.read[NPU_L1_RD_DMA].req_valid = 1u;
    inputs.read[NPU_L1_RD_DMA].req_addr = 0x008u;
    inputs.read[NPU_L1_RD_DMA].req_tag = 2u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].req_ready != 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_DMA].req_ready != 0u);
    L1_TEST_CHECK(outputs.bank_stall == 0u);
    L1_TEST_CHECK(outputs.read_bank_stall_mask == 0u);
    L1_TEST_CHECK(outputs.write_bank_stall_mask == 0u);

    l1_test_reset_controller();
    l1_test_put_word(0x000u, UINT64_C(0x0101010101010101));
    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].req_valid = 1u;
    inputs.write[NPU_L1_WR_DMA].req_addr = 0x000u;
    inputs.write[NPU_L1_WR_DMA].req_tag = 0x22u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].req_ready != 0u);

    /*
     * A lower normal-priority DMA write still wins over a Matrix read of
     * the same word.
     */
    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].data_valid = 1u;
    inputs.write[NPU_L1_WR_DMA].data = new_value;
    inputs.write[NPU_L1_WR_DMA].strb = 0xffu;
    inputs.write[NPU_L1_WR_DMA].last = 1u;
    inputs.read[NPU_L1_RD_ME_A].req_valid = 1u;
    inputs.read[NPU_L1_RD_ME_A].req_addr = 0x000u;
    inputs.read[NPU_L1_RD_ME_A].req_tag = 0x33u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].data_ready != 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].req_ready != 0u);
    L1_TEST_CHECK(outputs.bank_stall != 0u);
    L1_TEST_CHECK(
        outputs.read_bank_stall_mask ==
        (uint16_t)(1u << NPU_L1_RD_ME_A));
    L1_TEST_CHECK(outputs.write_bank_stall_mask == 0u);
    L1_TEST_CHECK(l1_test_get_word(0x000u) == new_value);

    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_ME_A].req_valid = 1u;
    inputs.read[NPU_L1_RD_ME_A].req_addr = 0x000u;
    inputs.read[NPU_L1_RD_ME_A].req_tag = 0x33u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].req_ready == 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].rsp_data ==
                  new_value);

    /*
     * For different words in the same bank, the documented fixed priority
     * applies: Matrix operand read precedes DMA write data.
     */
    l1_test_reset_controller();
    l1_test_put_word(0x080u, UINT64_C(0x1234));
    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].req_valid = 1u;
    inputs.write[NPU_L1_WR_DMA].req_addr = 0x000u;
    inputs.write[NPU_L1_WR_DMA].req_tag = 0x44u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].data_valid = 1u;
    inputs.write[NPU_L1_WR_DMA].data = UINT64_C(0xabcdef);
    inputs.write[NPU_L1_WR_DMA].strb = 0xffu;
    inputs.write[NPU_L1_WR_DMA].last = 1u;
    inputs.read[NPU_L1_RD_ME_A].req_valid = 1u;
    inputs.read[NPU_L1_RD_ME_A].req_addr = 0x080u;
    inputs.read[NPU_L1_RD_ME_A].req_tag = 0x55u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_ME_A].req_ready != 0u);
    /*
     * The empty write-data slot remains ready even though the SRAM bank is
     * busy. The accepted beat is retained inside the controller.
     */
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].data_ready != 0u);
    L1_TEST_CHECK(outputs.bank_stall != 0u);
    L1_TEST_CHECK(outputs.read_bank_stall_mask == 0u);
    L1_TEST_CHECK(
        outputs.write_bank_stall_mask ==
        (uint8_t)(1u << NPU_L1_WR_DMA));

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].data_ready == 0u);
    L1_TEST_CHECK(outputs.bank_stall == 0u);
    L1_TEST_CHECK(l1_test_get_word(0x000u) ==
                  UINT64_C(0xabcdef));
    return 0;
}

static int l1_test_starvation_promotion(void)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;
    uint8_t response_seen[NPU_L1_READ_PORT_COUNT] = {0};
    uint32_t port;
    uint32_t cycle;

    l1_test_reset_controller();
    l1_test_put_word(0x400u, UINT64_C(0x123456789abcdef0));
    l1_test_inputs_default(&inputs);
    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        inputs.read[port].req_valid = 1u;
        inputs.read[port].req_addr = 0x400u;
        inputs.read[port].req_tag = (uint16_t)(port + 1u);
    }
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        L1_TEST_CHECK(outputs.read[port].req_ready != 0u);
        inputs.read[port].req_valid = 0u;
    }

    /*
     * A request that has reached the wait limit wins its next bank access,
     * even though DMA has lower normal priority than the remaining clients.
     */
    l1_test_controller.read_state[NPU_L1_RD_DMA].wait_cycles =
        NPU_L1_CYCLE_STARVE_LIMIT;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(
        l1_test_controller.read_state[NPU_L1_RD_DMA].issued_beats ==
        1u);

    for (cycle = 0u; cycle < 64u; cycle++) {
        npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
        for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
            if (outputs.read[port].rsp_valid != 0u) {
                L1_TEST_CHECK(response_seen[port] == 0u);
                L1_TEST_CHECK(outputs.read[port].rsp_data ==
                              UINT64_C(0x123456789abcdef0));
                L1_TEST_CHECK(outputs.read[port].rsp_tag ==
                              port + 1u);
                L1_TEST_CHECK(outputs.read[port].rsp_last != 0u);
                response_seen[port] = 1u;
            }
        }
        if (npu_l1_cycle_idle(&l1_test_controller) != 0u) {
            break;
        }
    }
    L1_TEST_CHECK(cycle < 64u);
    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        L1_TEST_CHECK(response_seen[port] != 0u);
    }
    return 0;
}

static uint32_t l1_test_next_random(uint32_t *state)
{
    uint32_t value = *state;

    value ^= value << 13;
    value ^= value >> 17;
    value ^= value << 5;
    *state = value;
    return value;
}

static int l1_test_read_ready_and_random_pause(void)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;
    npu_l1_cycle_read_output_t
        held[NPU_L1_READ_PORT_COUNT];
    uint8_t held_valid[NPU_L1_READ_PORT_COUNT] = {0};
    uint8_t received[NPU_L1_READ_PORT_COUNT] = {0};
    uint32_t random_state = UINT32_C(0x2468ace1);
    uint32_t port;
    uint32_t beat;
    uint32_t cycle;

    l1_test_reset_controller();

    /*
     * No producer asserts valid until it has observed ready. Payload changes
     * while valid is zero must not change request admission.
     */
    l1_test_inputs_default(&inputs);
    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        inputs.read[port].req_addr = 3u + port;
        inputs.read[port].req_tag = 0xffffu;
    }
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        L1_TEST_CHECK(outputs.read[port].req_ready != 0u);
    }

    l1_test_inputs_default(&inputs);
    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        uint32_t base = 0x1000u + port * 0x200u;

        for (beat = 0u; beat < 4u; beat++) {
            l1_test_put_word(
                base + beat * NPU_L1_CYCLE_WORD_BYTES,
                (UINT64_C(0x5000) + port) *
                    UINT64_C(0x100) + beat);
        }
        inputs.read[port].req_valid = 1u;
        inputs.read[port].req_addr = base;
        inputs.read[port].req_beats = 3u;
        inputs.read[port].req_tag =
            (uint16_t)(0x100u + port);
    }
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        L1_TEST_CHECK(outputs.read[port].req_ready != 0u);
        inputs.read[port].req_valid = 0u;
    }

    for (cycle = 0u; cycle < 1024u; cycle++) {
        uint32_t random_value =
            l1_test_next_random(&random_state);
        uint8_t complete = 1u;

        for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
            inputs.read[port].rsp_ready =
                (uint8_t)((random_value >> (port % 31u)) & 1u);
        }
        npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);

        for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
            const npu_l1_cycle_read_output_t *response =
                &outputs.read[port];

            if (held_valid[port] != 0u) {
                L1_TEST_CHECK(response->rsp_valid != 0u);
                L1_TEST_CHECK(response->rsp_data ==
                              held[port].rsp_data);
                L1_TEST_CHECK(response->rsp_tag ==
                              held[port].rsp_tag);
                L1_TEST_CHECK(response->rsp_last ==
                              held[port].rsp_last);
                L1_TEST_CHECK(response->rsp_status ==
                              held[port].rsp_status);
            }
            held_valid[port] = 0u;
            if (response->rsp_valid != 0u) {
                uint32_t base = 0x1000u + port * 0x200u;

                L1_TEST_CHECK(received[port] < 4u);
                L1_TEST_CHECK(response->rsp_data ==
                              l1_test_get_word(
                                  base +
                                  (uint32_t)received[port] *
                                      NPU_L1_CYCLE_WORD_BYTES));
                L1_TEST_CHECK(response->rsp_tag ==
                              0x100u + port);
                L1_TEST_CHECK(response->rsp_status ==
                              NPU_L1_STATUS_OK);
                L1_TEST_CHECK(
                    response->rsp_last ==
                    (uint8_t)(received[port] == 3u));
                if (inputs.read[port].rsp_ready != 0u) {
                    received[port]++;
                } else {
                    held[port] = *response;
                    held_valid[port] = 1u;
                }
            }
            if (received[port] != 4u) {
                complete = 0u;
            }
        }
        if (complete != 0u) {
            break;
        }
    }

    L1_TEST_CHECK(cycle < 1024u);
    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        L1_TEST_CHECK(received[port] == 4u);
    }
    return 0;
}

static int l1_test_parameter_protection_and_response_hold(void)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;
    npu_l1_cycle_write_output_t held;
    uint64_t before0;
    uint64_t before1;

    l1_test_reset_controller();
    l1_test_put_word(0x0f8u, UINT64_C(0x1111111111111111));
    l1_test_put_word(0x100u, UINT64_C(0x2222222222222222));
    before0 = l1_test_get_word(0x0f8u);
    before1 = l1_test_get_word(0x100u);
    l1_test_set_param_signals(0x100u, 0x180u, 1u);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].req_valid = 1u;
    inputs.write[NPU_L1_WR_DMA].req_addr = 0x0f8u;
    inputs.write[NPU_L1_WR_DMA].req_beats = 1u;
    inputs.write[NPU_L1_WR_DMA].req_tag = 0x66u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].req_ready != 0u);
    L1_TEST_CHECK(outputs.write_idle != 0u);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].data_valid = 1u;
    inputs.write[NPU_L1_WR_DMA].data = UINT64_MAX;
    inputs.write[NPU_L1_WR_DMA].strb = 0xffu;
    inputs.write[NPU_L1_WR_DMA].last = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].data_ready != 0u);
    L1_TEST_CHECK(outputs.write_idle == 0u);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].data_valid = 1u;
    inputs.write[NPU_L1_WR_DMA].data = 0u;
    inputs.write[NPU_L1_WR_DMA].strb = 0xffu;
    inputs.write[NPU_L1_WR_DMA].last = 1u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].data_ready != 0u);
    L1_TEST_CHECK(l1_test_get_word(0x0f8u) == before0);
    L1_TEST_CHECK(l1_test_get_word(0x100u) == before1);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_valid == 0u);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_status ==
                  NPU_L1_STATUS_ADDR_FAULT);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_tag == 0x66u);
    held = outputs.write[NPU_L1_WR_DMA];

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_valid ==
                  held.rsp_valid);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_status ==
                  held.rsp_status);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_tag ==
                  held.rsp_tag);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_valid != 0u);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_DMA].rsp_valid == 0u);
    L1_TEST_CHECK(outputs.write_idle != 0u);

    /*
     * LSC changes the continuous parameter signals only after write_idle.
     * Moving the locked region now makes 0x100 writable by an IVE client.
     */
    l1_test_set_param_signals(0x180u, 0x200u, 1u);
    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_IVE_DST].req_valid = 1u;
    inputs.write[NPU_L1_WR_IVE_DST].req_addr = 0x100u;
    inputs.write[NPU_L1_WR_IVE_DST].req_tag = 0x67u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].req_ready != 0u);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_IVE_DST].data_valid = 1u;
    inputs.write[NPU_L1_WR_IVE_DST].data =
        UINT64_C(0x3333333333333333);
    inputs.write[NPU_L1_WR_IVE_DST].strb = 0xffu;
    inputs.write[NPU_L1_WR_IVE_DST].last = 1u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].data_ready != 0u);
    L1_TEST_CHECK(l1_test_get_word(0x100u) ==
                  UINT64_C(0x3333333333333333));
    return 0;
}

static int l1_test_write_protocol_and_strobes(void)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;

    l1_test_reset_controller();
    l1_test_put_word(0x200u, UINT64_C(0xffffffffffffffff));
    l1_test_put_word(0x208u, UINT64_C(0xffffffffffffffff));

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_IVE_DST].req_valid = 1u;
    inputs.write[NPU_L1_WR_IVE_DST].req_addr = 0x200u;
    inputs.write[NPU_L1_WR_IVE_DST].req_beats = 1u;
    inputs.write[NPU_L1_WR_IVE_DST].req_tag = 0x77u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_IVE_DST].data_valid = 1u;
    inputs.write[NPU_L1_WR_IVE_DST].data =
        UINT64_C(0x1122334455667788);
    inputs.write[NPU_L1_WR_IVE_DST].strb = 0x0fu;
    inputs.write[NPU_L1_WR_IVE_DST].last = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].data_ready != 0u);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_IVE_DST].data_valid = 1u;
    inputs.write[NPU_L1_WR_IVE_DST].data =
        UINT64_C(0x0102030405060708);
    inputs.write[NPU_L1_WR_IVE_DST].strb = 0xf0u;
    inputs.write[NPU_L1_WR_IVE_DST].last = 1u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].data_ready != 0u);
    L1_TEST_CHECK(l1_test_get_word(0x200u) ==
                  UINT64_C(0xffffffff55667788));
    L1_TEST_CHECK(l1_test_get_word(0x208u) ==
                  UINT64_C(0x01020304ffffffff));

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].rsp_valid == 0u);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].rsp_status ==
                  NPU_L1_STATUS_OK);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);

    /* Early wr_last. */
    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_IVE_DST].req_valid = 1u;
    inputs.write[NPU_L1_WR_IVE_DST].req_addr = 0x220u;
    inputs.write[NPU_L1_WR_IVE_DST].req_beats = 1u;
    inputs.write[NPU_L1_WR_IVE_DST].req_tag = 0x78u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].req_ready != 0u);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_IVE_DST].data_valid = 1u;
    inputs.write[NPU_L1_WR_IVE_DST].strb = 0xffu;
    inputs.write[NPU_L1_WR_IVE_DST].last = 1u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].rsp_status ==
                  NPU_L1_STATUS_PORT_PROTOCOL_ERROR);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);

    /* Missing wr_last on the declared final beat. */
    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_IVE_DST].req_valid = 1u;
    inputs.write[NPU_L1_WR_IVE_DST].req_addr = 0x228u;
    inputs.write[NPU_L1_WR_IVE_DST].req_beats = 0u;
    inputs.write[NPU_L1_WR_IVE_DST].req_tag = 0x79u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].req_ready != 0u);

    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_IVE_DST].data_valid = 1u;
    inputs.write[NPU_L1_WR_IVE_DST].strb = 0xffu;
    inputs.write[NPU_L1_WR_IVE_DST].last = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.write[NPU_L1_WR_IVE_DST].rsp_status ==
                  NPU_L1_STATUS_PORT_PROTOCOL_ERROR);
    return 0;
}

static int l1_test_unlocked_parameter_permissions(void)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;
    uint32_t port;
    int line;

    l1_test_reset_controller();
    l1_test_set_param_signals(0x800u, 0x900u, 0u);
    l1_test_param_write_allow_mask =
        (uint8_t)(1u << NPU_L1_WR_DMA);

    /*
     * While unlocked, only DMA may write the parameter region. The DMA
     * decoder separately limits this permission to raw copy operations.
     */
    for (port = 0u; port < NPU_L1_WRITE_PORT_COUNT; port++) {
        uint32_t addr = 0x800u + port * 8u;
        uint64_t original =
            UINT64_C(0x1111000000000000) + port;
        uint64_t requested =
            UINT64_C(0xaaaa000000000000) + port;
        uint8_t expected_status =
            port == NPU_L1_WR_DMA
                ? NPU_L1_STATUS_OK
                : NPU_L1_STATUS_ADDR_FAULT;

        l1_test_put_word(addr, original);
        line = l1_test_single_write(
            port, addr, (uint16_t)(0x200u + port),
            requested, expected_status);
        if (line != 0) {
            return line;
        }
        L1_TEST_CHECK(
            l1_test_get_word(addr) ==
            (port == NPU_L1_WR_DMA ? requested : original));
    }

    l1_test_param_write_allow_mask = 0u;
    l1_test_put_word(
        0x838u, UINT64_C(0x123456789abcdef0));
    line = l1_test_single_write(
        NPU_L1_WR_DMA, 0x838u, 0x21fu,
        UINT64_MAX, NPU_L1_STATUS_ADDR_FAULT);
    if (line != 0) {
        return line;
    }
    L1_TEST_CHECK(
        l1_test_get_word(0x838u) ==
        UINT64_C(0x123456789abcdef0));

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.write_idle != 0u);

    /*
     * LSC changes lock only while write_idle is true. Once locked, all
     * five write clients are rejected.
     */
    l1_test_set_param_signals(0x800u, 0x900u, 1u);
    for (port = 0u; port < NPU_L1_WRITE_PORT_COUNT; port++) {
        uint32_t addr = 0x840u + port * 8u;
        uint64_t original =
            UINT64_C(0x2222000000000000) + port;

        l1_test_put_word(addr, original);
        line = l1_test_single_write(
            port, addr, (uint16_t)(0x220u + port),
            UINT64_MAX, NPU_L1_STATUS_ADDR_FAULT);
        if (line != 0) {
            return line;
        }
        L1_TEST_CHECK(l1_test_get_word(addr) == original);
    }

    /*
     * Parameter locking never blocks reads. Exercise every read client,
     * including the diagnostic port.
     */
    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        uint32_t addr = 0x880u + port * 8u;
        uint64_t value =
            UINT64_C(0x3333000000000000) + port;

        l1_test_put_word(addr, value);
        line = l1_test_single_read(
            port, addr, (uint16_t)(0x240u + port), value);
        if (line != 0) {
            return line;
        }
    }
    return 0;
}

static int l1_test_ecc_injection_and_reset(void)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;
    const uint64_t value0 = UINT64_C(0x0badc0de12345678);
    const uint64_t value1 = UINT64_C(0xfeedface87654321);

    l1_test_reset_controller();
    l1_test_put_word(0x300u, value0);
    l1_test_put_word(0x308u, value1);
    L1_TEST_CHECK(npu_l1_cycle_inject_ecc(
                      &l1_test_controller, 0x300u,
                      NPU_L1_STATUS_ECC_CORRECTED) == 0);
    L1_TEST_CHECK(npu_l1_cycle_inject_ecc(
                      &l1_test_controller, 0x308u,
                      NPU_L1_STATUS_ECC_UNCORRECTABLE) == 0);

    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_CME_SRC0].req_valid = 1u;
    inputs.read[NPU_L1_RD_CME_SRC0].req_addr = 0x300u;
    inputs.read[NPU_L1_RD_CME_SRC0].req_tag = 0x80u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_corrected_pulse == 0u);
    L1_TEST_CHECK(outputs.ecc_uncorrectable_pulse == 0u);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_corrected_pulse == 0u);
    L1_TEST_CHECK(outputs.ecc_uncorrectable_pulse == 0u);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_CME_SRC0].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_CME_SRC0].rsp_data ==
                  value0);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_CME_SRC0].rsp_status ==
                  NPU_L1_STATUS_ECC_CORRECTED);
    L1_TEST_CHECK(outputs.ecc_corrected_pulse != 0u);
    L1_TEST_CHECK(outputs.ecc_uncorrectable_pulse == 0u);
    L1_TEST_CHECK(l1_test_controller.ecc_corrected_count == 1u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_corrected_pulse == 0u);
    L1_TEST_CHECK(outputs.ecc_uncorrectable_pulse == 0u);
    L1_TEST_CHECK(l1_test_controller.ecc_corrected_count == 1u);
    inputs.read[NPU_L1_RD_CME_SRC0].req_valid = 1u;
    inputs.read[NPU_L1_RD_CME_SRC0].req_addr = 0x308u;
    inputs.read[NPU_L1_RD_CME_SRC0].req_tag = 0x81u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_CME_SRC0].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_CME_SRC0].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_CME_SRC0].rsp_status ==
                  NPU_L1_STATUS_ECC_UNCORRECTABLE);
    L1_TEST_CHECK(outputs.ecc_corrected_pulse == 0u);
    L1_TEST_CHECK(outputs.ecc_uncorrectable_pulse != 0u);
    L1_TEST_CHECK(l1_test_controller.ecc_uncorrectable_count == 1u);

    /*
     * A held ECC response does not repeat its pulse or increment. Signal
     * reset then removes the response and active request while preserving
     * SRAM bytes and the caller-owned ECC injection state.
     */
    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_CME_SRC0].rsp_ready = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_CME_SRC0].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.ecc_corrected_pulse == 0u);
    L1_TEST_CHECK(outputs.ecc_uncorrectable_pulse == 0u);
    L1_TEST_CHECK(l1_test_controller.ecc_uncorrectable_count == 1u);

    l1_test_inputs_default(&inputs);
    inputs.reset_n = 0u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_corrected_pulse == 0u);
    L1_TEST_CHECK(outputs.ecc_uncorrectable_pulse == 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_CME_SRC0].rsp_valid == 0u);
    L1_TEST_CHECK(npu_l1_cycle_idle(&l1_test_controller) != 0u);
    L1_TEST_CHECK(l1_test_get_word(0x308u) == value1);
    L1_TEST_CHECK(l1_test_ecc[0x308u / 8u] ==
                  NPU_L1_STATUS_ECC_UNCORRECTABLE);
    L1_TEST_CHECK(l1_test_controller.ecc_corrected_count == 0u);
    L1_TEST_CHECK(l1_test_controller.ecc_uncorrectable_count == 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_CME_SRC0].rsp_valid == 0u);

    /*
     * A successful byte write recomputes ECC for the complete word and
     * therefore clears a prior injected fault indication.
     */
    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].req_valid = 1u;
    inputs.write[NPU_L1_WR_DMA].req_addr = 0x308u;
    inputs.write[NPU_L1_WR_DMA].req_tag = 0x82u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    inputs.write[NPU_L1_WR_DMA].data_valid = 1u;
    inputs.write[NPU_L1_WR_DMA].data = value0;
    inputs.write[NPU_L1_WR_DMA].strb = 0xffu;
    inputs.write[NPU_L1_WR_DMA].last = 1u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(l1_test_ecc[0x308u / 8u] ==
                  NPU_L1_STATUS_OK);
    L1_TEST_CHECK(l1_test_get_word(0x308u) == value0);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_CME_SRC0].req_valid = 1u;
    inputs.read[NPU_L1_RD_CME_SRC0].req_addr = 0x308u;
    inputs.read[NPU_L1_RD_CME_SRC0].req_tag = 0x83u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_CME_SRC0].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_CME_SRC0].rsp_status ==
                  NPU_L1_STATUS_OK);
    return 0;
}

static int l1_test_multiple_ecc_events(void)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;
    const uint32_t addr0 = 0x500u;
    const uint32_t addr1 = 0x508u;

    l1_test_reset_controller();
    L1_TEST_CHECK(
        npu_l1_cycle_inject_ecc(
            &l1_test_controller, addr0,
            NPU_L1_STATUS_ECC_CORRECTED) == 0);
    L1_TEST_CHECK(
        npu_l1_cycle_inject_ecc(
            &l1_test_controller, addr1,
            NPU_L1_STATUS_ECC_CORRECTED) == 0);

    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_ME_A].req_valid = 1u;
    inputs.read[NPU_L1_RD_ME_A].req_addr = addr0;
    inputs.read[NPU_L1_RD_ME_A].req_tag = 0x120u;
    inputs.read[NPU_L1_RD_ME_B].req_valid = 1u;
    inputs.read[NPU_L1_RD_ME_B].req_addr = addr1;
    inputs.read[NPU_L1_RD_ME_B].req_tag = 0x121u;
    npu_l1_cycle_step(
        &l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_corrected_events == 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(
        &l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_corrected_events == 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(
        &l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(
        outputs.read[NPU_L1_RD_ME_A].rsp_valid != 0u);
    L1_TEST_CHECK(
        outputs.read[NPU_L1_RD_ME_B].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.ecc_corrected_pulse != 0u);
    L1_TEST_CHECK(outputs.ecc_corrected_events == 2u);
    L1_TEST_CHECK(outputs.ecc_uncorrectable_events == 0u);
    L1_TEST_CHECK(
        l1_test_controller.ecc_corrected_count == 2u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(
        &l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_corrected_pulse == 0u);
    L1_TEST_CHECK(outputs.ecc_corrected_events == 0u);
    return 0;
}

static int l1_test_ecc_error_record(void)
{
    const uint32_t first_addr = 0x400u;
    const uint32_t second_addr = 0x448u;
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;

    l1_test_reset_controller();
    L1_TEST_CHECK(
        npu_l1_cycle_inject_ecc(
            &l1_test_controller, first_addr,
            NPU_L1_STATUS_ECC_UNCORRECTABLE) == 0);
    L1_TEST_CHECK(
        npu_l1_cycle_inject_ecc(
            &l1_test_controller, second_addr,
            NPU_L1_STATUS_ECC_UNCORRECTABLE) == 0);

    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_ME_A].req_valid = 1u;
    inputs.read[NPU_L1_RD_ME_A].req_addr = first_addr;
    inputs.read[NPU_L1_RD_ME_A].req_tag = 0x101u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_error_valid == 0u);

    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_ME_B].req_valid = 1u;
    inputs.read[NPU_L1_RD_ME_B].req_addr = second_addr;
    inputs.read[NPU_L1_RD_ME_B].req_tag = 0x102u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_error_valid != 0u);
    L1_TEST_CHECK(
        outputs.ecc_error_status ==
        NPU_L1_STATUS_ECC_UNCORRECTABLE);
    L1_TEST_CHECK(outputs.ecc_error_addr == first_addr);
    L1_TEST_CHECK(outputs.ecc_error_port == NPU_L1_RD_ME_A);
    L1_TEST_CHECK(
        outputs.ecc_error_bank ==
        (uint8_t)((first_addr / NPU_L1_CYCLE_WORD_BYTES) %
                  NPU_L1_CYCLE_BANKS));
    L1_TEST_CHECK(outputs.ecc_error_write == 0u);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_error_valid != 0u);
    L1_TEST_CHECK(outputs.ecc_error_addr == first_addr);
    L1_TEST_CHECK(outputs.ecc_error_port == NPU_L1_RD_ME_A);

    l1_test_inputs_default(&inputs);
    inputs.error_clear = 1u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_error_valid != 0u);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_error_valid == 0u);

    l1_test_reset_controller();
    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_ME_A].req_valid = 1u;
    inputs.read[NPU_L1_RD_ME_A].req_addr = first_addr;
    inputs.read[NPU_L1_RD_ME_A].req_tag = 0x103u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_error_addr == first_addr);

    l1_test_inputs_default(&inputs);
    inputs.error_clear = 1u;
    inputs.read[NPU_L1_RD_CME_SRC0].req_valid = 1u;
    inputs.read[NPU_L1_RD_CME_SRC0].req_addr = second_addr;
    inputs.read[NPU_L1_RD_CME_SRC0].req_tag = 0x104u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_error_addr == first_addr);

    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_error_valid != 0u);
    L1_TEST_CHECK(outputs.ecc_error_addr == second_addr);
    L1_TEST_CHECK(
        outputs.ecc_error_port == NPU_L1_RD_CME_SRC0);
    L1_TEST_CHECK(
        outputs.ecc_error_bank ==
        (uint8_t)((second_addr / NPU_L1_CYCLE_WORD_BYTES) %
                  NPU_L1_CYCLE_BANKS));

    l1_test_reset_controller();
    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_ME_A].req_valid = 1u;
    inputs.read[NPU_L1_RD_ME_A].req_addr = first_addr;
    inputs.read[NPU_L1_RD_ME_A].req_tag = 0x105u;
    inputs.read[NPU_L1_RD_ME_B].req_valid = 1u;
    inputs.read[NPU_L1_RD_ME_B].req_addr = second_addr;
    inputs.read[NPU_L1_RD_ME_B].req_tag = 0x106u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.ecc_error_valid != 0u);
    L1_TEST_CHECK(outputs.ecc_error_addr == first_addr);
    L1_TEST_CHECK(outputs.ecc_error_port == NPU_L1_RD_ME_A);
    return 0;
}

static int l1_test_bad_read_request(void)
{
    npu_l1_cycle_inputs_t inputs;
    npu_l1_cycle_outputs_t outputs;

    l1_test_reset_controller();
    l1_test_inputs_default(&inputs);
    inputs.read[NPU_L1_RD_DEBUG].req_valid = 1u;
    inputs.read[NPU_L1_RD_DEBUG].req_addr = 3u;
    inputs.read[NPU_L1_RD_DEBUG].req_tag = 0x90u;
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_DEBUG].req_ready != 0u);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    l1_test_inputs_default(&inputs);
    npu_l1_cycle_step(&l1_test_controller, &inputs, &outputs);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_DEBUG].rsp_valid != 0u);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_DEBUG].rsp_status ==
                  NPU_L1_STATUS_PORT_PROTOCOL_ERROR);
    L1_TEST_CHECK(outputs.read[NPU_L1_RD_DEBUG].rsp_data == 0u);
    return 0;
}

int test_l1_cycle(void)
{
    int line;

    line = l1_test_init_reset();
    if (line != 0) {
        return line;
    }
    line = l1_test_signal_reset_and_write_idle();
    if (line != 0) {
        return line;
    }
    line = l1_test_read_latency_and_stall();
    if (line != 0) {
        return line;
    }
    line = l1_test_parallel_banks_and_priority();
    if (line != 0) {
        return line;
    }
    line = l1_test_starvation_promotion();
    if (line != 0) {
        return line;
    }
    line = l1_test_read_ready_and_random_pause();
    if (line != 0) {
        return line;
    }
    line = l1_test_parameter_protection_and_response_hold();
    if (line != 0) {
        return line;
    }
    line = l1_test_write_protocol_and_strobes();
    if (line != 0) {
        return line;
    }
    line = l1_test_unlocked_parameter_permissions();
    if (line != 0) {
        return line;
    }
    line = l1_test_ecc_injection_and_reset();
    if (line != 0) {
        return line;
    }
    line = l1_test_multiple_ecc_events();
    if (line != 0) {
        return line;
    }
    line = l1_test_ecc_error_record();
    if (line != 0) {
        return line;
    }
    return l1_test_bad_read_request();
}

#ifdef NPU_L1_CYCLE_STANDALONE
int main(void)
{
    int line = test_l1_cycle();

    if (line == 0) {
        (void)printf("[PASS] l1_cycle\n");
        return 0;
    }
    (void)printf("[FAIL] l1_cycle at test line %d\n", line);
    return 1;
}
#endif
