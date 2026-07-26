#include "npu_bus_replay_cycle.h"
#include "test_util.h"

#include <string.h>

static void replay_test_idle(
    npu_bus_replay_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = 1u;
}

static int replay_expect_start_rejected_unchanged(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_trace_t *trace)
{
    unsigned char before[sizeof(*replay)];

    (void)memcpy(before, replay, sizeof(before));
    TEST_CHECK(!npu_bus_replay_cycle_start(
        replay, trace, 0x123u, 0x5au,
        NPU_STATUS_SUCCESS, 17u, 1u));
    TEST_CHECK(memcmp(before, replay, sizeof(before)) == 0);
    return 0;
}

static int replay_test_trace_validation(void)
{
    npu_bus_trace_entry_t read[2];
    npu_bus_trace_entry_t write;
    npu_bus_trace_t trace;
    npu_bus_replay_cycle_t replay;
    npu_bus_replay_cycle_inputs_t inputs;
    npu_bus_replay_cycle_outputs_t outputs;
    int line;

    (void)memset(read, 0, sizeof(read));
    (void)memset(&write, 0, sizeof(write));
    (void)memset(&trace, 0, sizeof(trace));
    read[0].space = NPU_SPACE_L1;
    read[0].addr = UINT64_C(0x100);
    read[0].strb = 0xffu;
    read[1] = read[0];
    read[1].addr = UINT64_C(0x108);
    write.space = NPU_SPACE_DDR;
    write.addr = UINT64_C(0x200);
    write.strb = 0x01u;
    trace.read = read;
    trace.read_capacity = 2u;
    trace.read_count = 1u;
    trace.write = &write;
    trace.write_capacity = 1u;
    trace.write_count = 1u;

    (void)memset(&replay, 0xa5, sizeof(replay));
    replay.state = NPU_BUS_REPLAY_IDLE;
    replay.cycle = UINT64_C(0x1122334455667788);

    trace.read_count = 3u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    trace.read_count = 1u;
    trace.write_count = 2u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    trace.write_count = 1u;

    trace.read = (npu_bus_trace_entry_t *)0;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    trace.read = read;
    trace.write = (npu_bus_trace_entry_t *)0;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    trace.write = &write;

    read[0].space = 2u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    read[0].space = NPU_SPACE_L1;
    read[0].port = NPU_BUS_REPLAY_READ_PORTS;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    read[0].port = 0u;
    read[0].addr++;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    read[0].addr--;
    read[0].strb = 0u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    read[0].strb = 0xffu;
    read[0].reserved = 1u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    read[0].reserved = 0u;
    read[0].addr = UINT64_C(0x100000000);
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    read[0].addr = UINT64_C(0x100);

    trace.read_count = 2u;
    read[0].read_pass = 1u;
    read[1].read_pass = 0u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    trace.read_count = 1u;
    read[0].read_pass = 0u;

    write.space = 2u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    write.space = NPU_SPACE_DDR;
    write.addr++;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    write.addr--;
    write.strb = 0u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    write.strb = 0x01u;
    write.reserved = 1u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    write.reserved = 0u;
    write.port = 1u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    write.port = 0u;
    write.read_pass = 1u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    write.read_pass = 0u;

    trace.active = 1u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }
    trace.active = 0u;
    trace.overflow = 1u;
    line = replay_expect_start_rejected_unchanged(
        &replay, &trace);
    if (line != 0) {
        return line;
    }

    (void)memset(&trace, 0, sizeof(trace));
    npu_bus_replay_cycle_reset(&replay);
    TEST_CHECK(npu_bus_replay_cycle_start(
        &replay, &trace, 0x124u, 0u,
        NPU_STATUS_SUCCESS, 0u, 0u));
    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid != 0u);
    TEST_CHECK(outputs.done_status == NPU_STATUS_SUCCESS);
    return 0;
}

static int replay_test_success(void)
{
    npu_bus_trace_entry_t read[2];
    npu_bus_trace_entry_t write[2];
    npu_bus_trace_t trace;
    npu_bus_replay_cycle_t replay;
    npu_bus_replay_cycle_inputs_t inputs;
    npu_bus_replay_cycle_outputs_t outputs;
    uint64_t held_data;

    (void)memset(&trace, 0, sizeof(trace));
    (void)memset(read, 0, sizeof(read));
    (void)memset(write, 0, sizeof(write));
    read[0].space = NPU_SPACE_L1;
    read[0].port = 1u;
    read[0].addr = UINT64_C(0x100);
    read[0].data = UINT64_C(0x8877665544332211);
    read[0].strb = 0xffu;
    read[1].space = NPU_SPACE_DDR;
    read[1].addr = UINT64_C(0x200);
    read[1].data = UINT64_C(0xaabbccddeeff0011);
    read[1].strb = 0x0fu;
    write[0].space = NPU_SPACE_L1;
    write[0].addr = UINT64_C(0x300);
    write[0].data = UINT64_C(0x12345678);
    write[0].strb = 0x0fu;
    write[1].space = NPU_SPACE_DDR;
    write[1].addr = UINT64_C(0x400);
    write[1].data = UINT64_C(0xabcdef);
    write[1].strb = 0x07u;
    trace.read = read;
    trace.read_capacity = 2u;
    trace.read_count = 2u;
    trace.write = write;
    trace.write_capacity = 2u;
    trace.write_count = 2u;

    npu_bus_replay_cycle_reset(&replay);
    TEST_CHECK(npu_bus_replay_cycle_start(
        &replay, &trace, 5u, 0u,
        NPU_STATUS_SUCCESS, 7u, 0u));

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read[1].req_valid == 1u);
    TEST_CHECK(outputs.l1_read[1].req_addr == 0x100u);
    TEST_CHECK(outputs.l1_read[1].req_tag == 5u);

    inputs.l1_read[1].req_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read[1].req_valid == 1u);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read[1].rsp_ready == 1u);
    inputs.l1_read[1].rsp_valid = 1u;
    inputs.l1_read[1].rsp_data = read[0].data;
    inputs.l1_read[1].rsp_tag = 5u;
    inputs.l1_read[1].rsp_last = 1u;
    inputs.l1_read[1].rsp_status = NPU_L1_STATUS_OK;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.req_valid == 1u);
    TEST_CHECK(outputs.mif.req_write == 0u);
    TEST_CHECK(outputs.mif.req_vaddr == UINT64_C(0x200));
    TEST_CHECK(outputs.mif.req_tag == 6u);
    inputs.mif.req_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.rsp_ready == 1u);
    inputs.mif.rsp_valid = 1u;
    inputs.mif.rsp_data = read[1].data;
    inputs.mif.rsp_tag = 6u;
    inputs.mif.rsp_last = 1u;
    inputs.mif.rsp_status = NPU_STATUS_SUCCESS;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_write.req_valid == 1u);
    TEST_CHECK(outputs.l1_write.data_valid == 1u);
    TEST_CHECK(outputs.l1_write.req_tag == 0x805u);
    held_data = outputs.l1_write.data;
    inputs.l1_write.req_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_write.req_valid == 0u);
    TEST_CHECK(outputs.l1_write.data_valid == 1u);
    TEST_CHECK(outputs.l1_write.data == held_data);
    inputs.l1_write.data_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_write.rsp_ready == 1u);
    inputs.l1_write.rsp_valid = 1u;
    inputs.l1_write.rsp_tag = 0x805u;
    inputs.l1_write.rsp_status = NPU_L1_STATUS_OK;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.req_valid == 1u);
    TEST_CHECK(outputs.mif.req_write == 1u);
    TEST_CHECK(outputs.mif.wvalid == 1u);
    TEST_CHECK(outputs.mif.req_tag == 0x806u);
    TEST_CHECK(outputs.mif.wtag == 0x806u);
    inputs.mif.req_ready = 1u;
    inputs.mif.wready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.rsp_ready == 1u);
    inputs.mif.rsp_valid = 1u;
    inputs.mif.rsp_tag = 0x806u;
    inputs.mif.rsp_is_write = 1u;
    inputs.mif.rsp_last = 1u;
    inputs.mif.rsp_status = NPU_STATUS_SUCCESS;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid == 1u);
    TEST_CHECK(outputs.done_status == NPU_STATUS_SUCCESS);
    TEST_CHECK(outputs.done_progress == 7u);
    TEST_CHECK(outputs.confirmed_write_bytes == 7u);
    inputs.done_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid == 1u);
    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.quiescent == 1u);
    TEST_CHECK(outputs.busy == 0u);
    return 0;
}

static int replay_test_error_and_abort(void)
{
    npu_bus_trace_entry_t read;
    npu_bus_trace_entry_t dummy_write;
    npu_bus_trace_t trace;
    npu_bus_replay_cycle_t replay;
    npu_bus_replay_cycle_inputs_t inputs;
    npu_bus_replay_cycle_outputs_t outputs;

    (void)memset(&trace, 0, sizeof(trace));
    (void)memset(&read, 0, sizeof(read));
    (void)memset(&dummy_write, 0, sizeof(dummy_write));
    read.space = NPU_SPACE_L1;
    read.port = 0u;
    read.addr = UINT64_C(0x7f8);
    read.strb = 0xffu;
    trace.read = &read;
    trace.read_capacity = 1u;
    trace.read_count = 1u;
    trace.write = &dummy_write;
    trace.write_capacity = 1u;

    npu_bus_replay_cycle_reset(&replay);
    TEST_CHECK(npu_bus_replay_cycle_start(
        &replay, &trace, 9u, 0u,
        NPU_STATUS_SUCCESS, 0u, 0u));
    replay_test_idle(&inputs);
    inputs.l1_read[0].req_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    replay_test_idle(&inputs);
    inputs.l1_read[0].rsp_valid = 1u;
    inputs.l1_read[0].rsp_tag = 9u;
    inputs.l1_read[0].rsp_last = 1u;
    inputs.l1_read[0].rsp_status =
        NPU_L1_STATUS_ECC_UNCORRECTABLE;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid == 1u);
    TEST_CHECK(outputs.done_status ==
               NPU_STATUS_L1_ECC_UNCORRECTABLE);
    TEST_CHECK(outputs.done_fault_addr == UINT64_C(0x7f8));
    TEST_CHECK((outputs.done_flags &
                NPU_DONE_FAULT_ADDR_IS_L1) != 0u);

    npu_bus_replay_cycle_reset(&replay);
    read.space = NPU_SPACE_DDR;
    read.addr = UINT64_C(0x1000);
    read.data = UINT64_C(0x55);
    read.strb = 0x01u;
    TEST_CHECK(npu_bus_replay_cycle_start(
        &replay, &trace, 10u, 0u,
        NPU_STATUS_SUCCESS, 0u, 0u));
    replay_test_idle(&inputs);
    inputs.mif.req_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    replay_test_idle(&inputs);
    inputs.abort = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.rsp_ready == 1u);
    replay_test_idle(&inputs);
    inputs.mif.rsp_valid = 1u;
    inputs.mif.rsp_data = UINT64_C(0x55);
    inputs.mif.rsp_tag = 10u;
    inputs.mif.rsp_last = 1u;
    inputs.mif.rsp_status = NPU_STATUS_SUCCESS;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid == 1u);
    TEST_CHECK(outputs.done_status == NPU_STATUS_ABORTED);
    TEST_CHECK((outputs.done_flags &
                NPU_DONE_ABORT_DRAINED) != 0u);
    return 0;
}

static int replay_test_protocol_and_reset(void)
{
    npu_bus_trace_entry_t read;
    npu_bus_trace_entry_t dummy_write;
    npu_bus_trace_t trace;
    npu_bus_replay_cycle_t replay;
    npu_bus_replay_cycle_inputs_t inputs;
    npu_bus_replay_cycle_outputs_t outputs;

    (void)memset(&trace, 0, sizeof(trace));
    (void)memset(&read, 0, sizeof(read));
    (void)memset(&dummy_write, 0, sizeof(dummy_write));
    read.space = NPU_SPACE_DDR;
    read.addr = UINT64_C(0x2000);
    read.data = UINT64_C(0xa5);
    read.strb = 0x01u;
    trace.read = &read;
    trace.read_capacity = 1u;
    trace.read_count = 1u;
    trace.write = &dummy_write;
    trace.write_capacity = 1u;

    npu_bus_replay_cycle_reset(&replay);
    TEST_CHECK(npu_bus_replay_cycle_start(
        &replay, &trace, 11u, 0u,
        NPU_STATUS_SUCCESS, 0u, 0u));
    replay_test_idle(&inputs);
    inputs.mif.req_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    replay_test_idle(&inputs);
    inputs.mif.rsp_valid = 1u;
    inputs.mif.rsp_data = UINT64_C(0xa5);
    inputs.mif.rsp_tag = 12u;
    inputs.mif.rsp_last = 1u;
    inputs.mif.rsp_status = NPU_STATUS_SUCCESS;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid == 1u);
    TEST_CHECK(outputs.done_status == NPU_STATUS_BAD_DESC);
    TEST_CHECK(outputs.protocol_error == 1u);

    inputs.reset_n = 0u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid == 0u);
    TEST_CHECK(outputs.quiescent == 1u);
    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.busy == 0u);
    return 0;
}

static int replay_test_invalid_mif_status(void)
{
    npu_bus_trace_entry_t read;
    npu_bus_trace_entry_t write;
    npu_bus_trace_t trace;
    npu_bus_replay_cycle_t replay;
    npu_bus_replay_cycle_inputs_t inputs;
    npu_bus_replay_cycle_outputs_t outputs;
    npu_mif_owner_inputs_t held_request;
    uint8_t held_done_status;
    uint64_t held_done_fault_addr;
    uint16_t held_done_flags;
    uint64_t held_done_progress;

    (void)memset(&read, 0, sizeof(read));
    (void)memset(&trace, 0, sizeof(trace));
    read.space = NPU_SPACE_DDR;
    read.addr = UINT64_C(0x2400);
    read.data = UINT64_C(0x0123456789abcdef);
    read.strb = 0xffu;
    trace.read = &read;
    trace.read_capacity = 1u;
    trace.read_count = 1u;

    npu_bus_replay_cycle_reset(&replay);
    TEST_CHECK(npu_bus_replay_cycle_start(
        &replay, &trace, 0x41u, 0u,
        NPU_STATUS_SUCCESS, 0u, 0u));

    replay_test_idle(&inputs);
    inputs.mif.rsp_valid = 1u;
    inputs.mif.rsp_data = read.data;
    inputs.mif.rsp_tag = 0x41u;
    inputs.mif.rsp_last = 1u;
    inputs.mif.rsp_status = UINT8_MAX;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.req_valid != 0u);
    TEST_CHECK(outputs.mif.rsp_ready == 0u);
    TEST_CHECK(outputs.protocol_error == 0u);
    held_request = outputs.mif;

    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(memcmp(
                   &held_request, &outputs.mif,
                   sizeof(held_request)) == 0);
    TEST_CHECK(outputs.protocol_error == 0u);

    inputs.mif.req_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.req_valid != 0u);
    TEST_CHECK(outputs.mif.rsp_ready == 0u);
    TEST_CHECK(outputs.protocol_error == 0u);

    inputs.mif.req_ready = 0u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.req_valid == 0u);
    TEST_CHECK(outputs.mif.rsp_ready != 0u);
    TEST_CHECK(outputs.protocol_error == 0u);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid != 0u);
    TEST_CHECK(outputs.done_status == NPU_STATUS_BAD_DESC);
    TEST_CHECK(outputs.done_status != UINT8_MAX);
    TEST_CHECK(outputs.protocol_error != 0u);
    TEST_CHECK(outputs.accepted_read_words == 0u);
    held_done_status = outputs.done_status;
    held_done_fault_addr = outputs.done_fault_addr;
    held_done_flags = outputs.done_flags;
    held_done_progress = outputs.done_progress;

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid != 0u);
    TEST_CHECK(outputs.protocol_error == 0u);
    TEST_CHECK(outputs.done_status == held_done_status);
    TEST_CHECK(outputs.done_fault_addr ==
               held_done_fault_addr);
    TEST_CHECK(outputs.done_flags == held_done_flags);
    TEST_CHECK(outputs.done_progress == held_done_progress);

    (void)memset(&write, 0, sizeof(write));
    (void)memset(&trace, 0, sizeof(trace));
    write.space = NPU_SPACE_DDR;
    write.addr = UINT64_C(0x2500);
    write.data = UINT64_C(0xfedcba9876543210);
    write.strb = 0xffu;
    trace.write = &write;
    trace.write_capacity = 1u;
    trace.write_count = 1u;

    npu_bus_replay_cycle_reset(&replay);
    TEST_CHECK(npu_bus_replay_cycle_start(
        &replay, &trace, 0x42u, 0u,
        NPU_STATUS_SUCCESS, 8u, 0u));

    replay_test_idle(&inputs);
    inputs.mif.rsp_valid = 1u;
    inputs.mif.rsp_tag = 0x842u;
    inputs.mif.rsp_is_write = 1u;
    inputs.mif.rsp_last = 1u;
    inputs.mif.rsp_status = NPU_STATUS_BUSY;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.req_valid != 0u);
    TEST_CHECK(outputs.mif.wvalid != 0u);
    TEST_CHECK(outputs.mif.rsp_ready == 0u);
    TEST_CHECK(outputs.protocol_error == 0u);
    held_request = outputs.mif;

    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(memcmp(
                   &held_request, &outputs.mif,
                   sizeof(held_request)) == 0);
    TEST_CHECK(outputs.protocol_error == 0u);

    inputs.mif.req_ready = 1u;
    inputs.mif.wready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.req_valid != 0u);
    TEST_CHECK(outputs.mif.wvalid != 0u);
    TEST_CHECK(outputs.mif.rsp_ready == 0u);

    inputs.mif.req_ready = 0u;
    inputs.mif.wready = 0u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.req_valid == 0u);
    TEST_CHECK(outputs.mif.wvalid == 0u);
    TEST_CHECK(outputs.mif.rsp_ready != 0u);
    TEST_CHECK(outputs.protocol_error == 0u);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid != 0u);
    TEST_CHECK(outputs.done_status == NPU_STATUS_BAD_DESC);
    TEST_CHECK(outputs.done_status != NPU_STATUS_BUSY);
    TEST_CHECK(outputs.protocol_error != 0u);
    TEST_CHECK(outputs.confirmed_write_bytes == 0u);
    TEST_CHECK(outputs.done_progress == 0u);
    held_done_status = outputs.done_status;
    held_done_fault_addr = outputs.done_fault_addr;
    held_done_flags = outputs.done_flags;
    held_done_progress = outputs.done_progress;

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid != 0u);
    TEST_CHECK(outputs.protocol_error == 0u);
    TEST_CHECK(outputs.done_status == held_done_status);
    TEST_CHECK(outputs.done_fault_addr ==
               held_done_fault_addr);
    TEST_CHECK(outputs.done_flags == held_done_flags);
    TEST_CHECK(outputs.done_progress == held_done_progress);
    return 0;
}

static int replay_test_compute_hold(void)
{
    npu_bus_trace_entry_t read;
    npu_bus_trace_entry_t write;
    npu_bus_trace_t trace;
    npu_bus_replay_cycle_t replay;
    npu_bus_replay_cycle_inputs_t inputs;
    npu_bus_replay_cycle_outputs_t outputs;

    (void)memset(&trace, 0, sizeof(trace));
    (void)memset(&read, 0, sizeof(read));
    (void)memset(&write, 0, sizeof(write));
    read.space = NPU_SPACE_L1;
    read.port = 0u;
    read.addr = UINT64_C(0x2800);
    read.data = UINT64_C(0x1122334455667788);
    read.strb = 0xffu;
    write.space = NPU_SPACE_L1;
    write.addr = UINT64_C(0x2900);
    write.data = UINT64_C(0x8877665544332211);
    write.strb = 0xffu;
    trace.read = &read;
    trace.read_capacity = 1u;
    trace.read_count = 1u;
    trace.write = &write;
    trace.write_capacity = 1u;
    trace.write_count = 1u;

    npu_bus_replay_cycle_reset(&replay);
    TEST_CHECK(npu_bus_replay_cycle_start(
        &replay, &trace, 0x31u, 0u,
        NPU_STATUS_SUCCESS, 8u, 1u));

    replay_test_idle(&inputs);
    inputs.l1_read[0].req_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read[0].req_valid != 0u);

    replay_test_idle(&inputs);
    inputs.l1_read[0].rsp_valid = 1u;
    inputs.l1_read[0].rsp_data = read.data;
    inputs.l1_read[0].rsp_tag = 0x31u;
    inputs.l1_read[0].rsp_last = 1u;
    inputs.l1_read[0].rsp_status = NPU_L1_STATUS_OK;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read[0].rsp_ready != 0u);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.compute_valid != 0u);
    TEST_CHECK(outputs.l1_write.req_valid == 0u);
    TEST_CHECK(outputs.l1_write.data_valid == 0u);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_eval(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.compute_valid != 0u);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.compute_valid != 0u);

    replay_test_idle(&inputs);
    inputs.compute_done = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.compute_valid != 0u);
    TEST_CHECK(outputs.l1_write.req_valid == 0u);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.compute_valid == 0u);
    TEST_CHECK(outputs.l1_write.req_valid != 0u);
    TEST_CHECK(outputs.l1_write.data_valid != 0u);

    npu_bus_replay_cycle_reset(&replay);
    trace.read_count = 0u;
    TEST_CHECK(npu_bus_replay_cycle_start(
        &replay, &trace, 0x32u, 0u,
        NPU_STATUS_SUCCESS, 8u, 1u));
    replay_test_idle(&inputs);
    inputs.abort = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.compute_valid != 0u);
    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid != 0u);
    TEST_CHECK(outputs.done_status == NPU_STATUS_ABORTED);
    TEST_CHECK(outputs.l1_write.req_valid == 0u);
    return 0;
}

static int replay_test_stream_compute_credit(void)
{
    npu_bus_trace_entry_t read[2];
    npu_bus_trace_entry_t write;
    npu_bus_trace_t trace;
    npu_bus_replay_cycle_t replay;
    npu_bus_replay_cycle_inputs_t inputs;
    npu_bus_replay_cycle_outputs_t outputs;

    (void)memset(&trace, 0, sizeof(trace));
    (void)memset(read, 0, sizeof(read));
    (void)memset(&write, 0, sizeof(write));
    read[0].space = NPU_SPACE_L1;
    read[0].port = 0u;
    read[0].addr = UINT64_C(0x3000);
    read[0].data = UINT64_C(0x0102030405060708);
    read[0].strb = 0xffu;
    read[1].space = NPU_SPACE_L1;
    read[1].port = 0u;
    read[1].addr = UINT64_C(0x3008);
    read[1].data = UINT64_C(0x1112131415161718);
    read[1].strb = 0xffu;
    write.space = NPU_SPACE_L1;
    write.addr = UINT64_C(0x3100);
    write.data = UINT64_C(0x2122232425262728);
    write.strb = 0xffu;
    trace.read = read;
    trace.read_capacity = 2u;
    trace.read_count = 2u;
    trace.write = &write;
    trace.write_capacity = 1u;
    trace.write_count = 1u;

    npu_bus_replay_cycle_reset(&replay);
    TEST_CHECK(npu_bus_replay_cycle_start_stream(
        &replay, &trace, 0x33u, 0u,
        NPU_STATUS_SUCCESS, 8u, 1u, 1u));

    replay_test_idle(&inputs);
    inputs.l1_read[0].req_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read[0].req_valid != 0u);
    TEST_CHECK(outputs.l1_read[0].req_beats == 1u);
    TEST_CHECK(outputs.compute_valid == 0u);

    replay_test_idle(&inputs);
    inputs.l1_read[0].rsp_valid = 1u;
    inputs.l1_read[0].rsp_data = read[0].data;
    inputs.l1_read[0].rsp_tag = 0x33u;
    inputs.l1_read[0].rsp_status = NPU_L1_STATUS_OK;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read[0].rsp_ready != 0u);
    TEST_CHECK(outputs.compute_valid == 0u);

    replay_test_idle(&inputs);
    inputs.l1_read[0].rsp_valid = 1u;
    inputs.l1_read[0].rsp_data = read[1].data;
    inputs.l1_read[0].rsp_tag = 0x33u;
    inputs.l1_read[0].rsp_last = 1u;
    inputs.l1_read[0].rsp_status = NPU_L1_STATUS_OK;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.compute_valid != 0u);
    TEST_CHECK(outputs.l1_read[0].rsp_ready != 0u);
    TEST_CHECK(outputs.accepted_read_words == 1u);
    TEST_CHECK(
        outputs.accepted_read_words_by_port[0] == 1u);
    TEST_CHECK(outputs.l1_write.req_valid == 0u);

    replay_test_idle(&inputs);
    inputs.compute_done = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.compute_valid != 0u);
    TEST_CHECK(outputs.accepted_read_words == 2u);
    TEST_CHECK(
        outputs.accepted_read_words_by_port[0] == 2u);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.compute_valid == 0u);
    TEST_CHECK(outputs.l1_write.req_valid != 0u);
    TEST_CHECK(outputs.l1_write.data_valid != 0u);
    return 0;
}

static int replay_test_parallel_pass_and_bursts(void)
{
    npu_bus_trace_entry_t read[20];
    npu_bus_trace_entry_t write[19];
    npu_bus_trace_t trace;
    npu_bus_replay_cycle_t replay;
    npu_bus_replay_cycle_inputs_t inputs;
    npu_bus_replay_cycle_outputs_t outputs;
    npu_l1_cycle_read_input_t held_l1_port0;
    npu_mif_owner_inputs_t held_mif;
    uint32_t index;

    (void)memset(&trace, 0, sizeof(trace));
    (void)memset(read, 0, sizeof(read));
    (void)memset(write, 0, sizeof(write));

    read[0].space = NPU_SPACE_L1;
    read[0].port = 0u;
    read[0].addr = UINT64_C(0x1000);
    read[0].data = UINT64_C(0x100);
    read[0].strb = 0xffu;
    read[1].space = NPU_SPACE_L1;
    read[1].port = 1u;
    read[1].addr = UINT64_C(0x2000);
    read[1].data = UINT64_C(0x200);
    read[1].strb = 0xffu;
    read[2].space = NPU_SPACE_L1;
    read[2].port = 0u;
    read[2].addr = UINT64_C(0x1008);
    read[2].data = UINT64_C(0x108);
    read[2].strb = 0xffu;
    for (index = 0u; index < 16u; index++) {
        read[3u + index].space = NPU_SPACE_DDR;
        read[3u + index].addr =
            UINT64_C(0x3000) + (uint64_t)index * 8u;
        read[3u + index].data =
            UINT64_C(0x300) + index;
        read[3u + index].strb = 0xffu;
    }
    read[19].space = NPU_SPACE_L1;
    read[19].port = 2u;
    read[19].addr = UINT64_C(0x4000);
    read[19].data = UINT64_C(0x400);
    read[19].strb = 0xffu;
    read[19].read_pass = 1u;

    for (index = 0u; index < 3u; index++) {
        write[index].space = NPU_SPACE_L1;
        write[index].addr =
            UINT64_C(0x5000) + (uint64_t)index * 8u;
        write[index].data =
            UINT64_C(0x500) + index;
        write[index].strb = 0xffu;
    }
    for (index = 0u; index < 16u; index++) {
        write[3u + index].space = NPU_SPACE_DDR;
        write[3u + index].addr =
            UINT64_C(0x6000) + (uint64_t)index * 8u;
        write[3u + index].data =
            UINT64_C(0x600) + index;
        write[3u + index].strb = 0xffu;
    }
    trace.read = read;
    trace.read_capacity = 20u;
    trace.read_count = 20u;
    trace.write = write;
    trace.write_capacity = 19u;
    trace.write_count = 19u;

    npu_bus_replay_cycle_reset(&replay);
    TEST_CHECK(npu_bus_replay_cycle_start(
        &replay, &trace, 0x21u, 0u,
        NPU_STATUS_SUCCESS, 152u, 0u));

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read[0].req_valid == 1u);
    TEST_CHECK(outputs.l1_read[0].req_beats == 1u);
    TEST_CHECK(outputs.l1_read[1].req_valid == 1u);
    TEST_CHECK(outputs.l1_read[1].req_beats == 0u);
    TEST_CHECK(outputs.mif.req_valid == 1u);
    TEST_CHECK(outputs.mif.req_beats == 15u);
    held_l1_port0 = outputs.l1_read[0];
    held_mif = outputs.mif;

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(memcmp(
                   &held_l1_port0, &outputs.l1_read[0],
                   sizeof(held_l1_port0)) == 0);
    TEST_CHECK(memcmp(
                   &held_mif, &outputs.mif,
                   sizeof(held_mif)) == 0);

    replay_test_idle(&inputs);
    inputs.l1_read[0].req_ready = 1u;
    inputs.l1_read[1].req_ready = 1u;
    inputs.mif.req_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    replay_test_idle(&inputs);
    inputs.l1_read[0].rsp_valid = 1u;
    inputs.l1_read[0].rsp_data = read[0].data;
    inputs.l1_read[0].rsp_tag = 0x21u;
    inputs.l1_read[0].rsp_status = NPU_L1_STATUS_OK;
    inputs.l1_read[1].rsp_valid = 1u;
    inputs.l1_read[1].rsp_data = read[1].data;
    inputs.l1_read[1].rsp_tag = 0x22u;
    inputs.l1_read[1].rsp_last = 1u;
    inputs.l1_read[1].rsp_status = NPU_L1_STATUS_OK;
    inputs.mif.rsp_valid = 1u;
    inputs.mif.rsp_data = read[3].data;
    inputs.mif.rsp_tag = 0x24u;
    inputs.mif.rsp_status = NPU_STATUS_SUCCESS;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read[0].rsp_ready == 1u);
    TEST_CHECK(outputs.l1_read[1].rsp_ready == 1u);
    TEST_CHECK(outputs.mif.rsp_ready == 1u);

    replay_test_idle(&inputs);
    inputs.l1_read[0].rsp_valid = 1u;
    inputs.l1_read[0].rsp_data = read[2].data;
    inputs.l1_read[0].rsp_tag = 0x21u;
    inputs.l1_read[0].rsp_last = 1u;
    inputs.l1_read[0].rsp_status = NPU_L1_STATUS_OK;
    inputs.mif.rsp_valid = 1u;
    inputs.mif.rsp_data = read[4].data;
    inputs.mif.rsp_tag = 0x24u;
    inputs.mif.rsp_status = NPU_STATUS_SUCCESS;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    for (index = 2u; index < 16u; index++) {
        replay_test_idle(&inputs);
        inputs.mif.rsp_valid = 1u;
        inputs.mif.rsp_data = read[3u + index].data;
        inputs.mif.rsp_tag = 0x24u;
        inputs.mif.rsp_last =
            (uint8_t)(index == 15u);
        inputs.mif.rsp_status = NPU_STATUS_SUCCESS;
        npu_bus_replay_cycle_step(
            &replay, &inputs, &outputs);
        TEST_CHECK(outputs.l1_read[2].req_valid == 0u);
    }

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read[2].req_valid == 1u);
    TEST_CHECK(outputs.l1_read[2].req_addr == 0x4000u);
    TEST_CHECK(outputs.l1_read[2].req_tag == 0x34u);
    inputs.l1_read[2].req_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    replay_test_idle(&inputs);
    inputs.l1_read[2].rsp_valid = 1u;
    inputs.l1_read[2].rsp_data = read[19].data;
    inputs.l1_read[2].rsp_tag = 0x34u;
    inputs.l1_read[2].rsp_last = 1u;
    inputs.l1_read[2].rsp_status = NPU_L1_STATUS_OK;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_write.req_valid == 1u);
    TEST_CHECK(outputs.l1_write.req_beats == 2u);
    TEST_CHECK(outputs.l1_write.data_valid == 1u);
    TEST_CHECK(outputs.l1_write.data == write[0].data);
    TEST_CHECK(outputs.l1_write.last == 0u);
    inputs.l1_write.req_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_write.req_valid == 0u);
    TEST_CHECK(outputs.l1_write.data == write[0].data);
    inputs.l1_write.data_ready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    for (index = 1u; index < 3u; index++) {
        replay_test_idle(&inputs);
        npu_bus_replay_cycle_step(
            &replay, &inputs, &outputs);
        TEST_CHECK(outputs.l1_write.data_valid == 1u);
        TEST_CHECK(outputs.l1_write.data ==
                   write[index].data);
        TEST_CHECK(outputs.l1_write.last ==
                   (uint8_t)(index == 2u));
        inputs.l1_write.data_ready = 1u;
        npu_bus_replay_cycle_step(
            &replay, &inputs, &outputs);
    }

    replay_test_idle(&inputs);
    inputs.l1_write.rsp_valid = 1u;
    inputs.l1_write.rsp_tag = 0x821u;
    inputs.l1_write.rsp_status = NPU_L1_STATUS_OK;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.l1_write.rsp_ready == 1u);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.req_valid == 1u);
    TEST_CHECK(outputs.mif.req_write == 1u);
    TEST_CHECK(outputs.mif.req_beats == 15u);
    TEST_CHECK(outputs.mif.wvalid == 1u);
    TEST_CHECK(outputs.mif.wdata == write[3].data);
    TEST_CHECK(outputs.mif.wlast == 0u);
    inputs.mif.req_ready = 1u;
    inputs.mif.wready = 1u;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    for (index = 1u; index < 16u; index++) {
        replay_test_idle(&inputs);
        npu_bus_replay_cycle_step(
            &replay, &inputs, &outputs);
        TEST_CHECK(outputs.mif.wvalid == 1u);
        TEST_CHECK(outputs.mif.wdata ==
                   write[3u + index].data);
        TEST_CHECK(outputs.mif.wlast ==
                   (uint8_t)(index == 15u));
        inputs.mif.wready = 1u;
        npu_bus_replay_cycle_step(
            &replay, &inputs, &outputs);
    }

    replay_test_idle(&inputs);
    inputs.mif.rsp_valid = 1u;
    inputs.mif.rsp_tag = 0x824u;
    inputs.mif.rsp_is_write = 1u;
    inputs.mif.rsp_last = 1u;
    inputs.mif.rsp_status = NPU_STATUS_SUCCESS;
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.mif.rsp_ready == 1u);

    replay_test_idle(&inputs);
    npu_bus_replay_cycle_step(&replay, &inputs, &outputs);
    TEST_CHECK(outputs.done_valid == 1u);
    TEST_CHECK(outputs.done_status == NPU_STATUS_SUCCESS);
    TEST_CHECK(outputs.done_progress == 152u);
    TEST_CHECK(outputs.done_flags == 0u);
    TEST_CHECK(outputs.confirmed_write_bytes == 152u);
    return 0;
}

int test_bus_replay_cycle(void)
{
    int line;

    line = replay_test_trace_validation();
    if (line != 0) {
        return line;
    }
    line = replay_test_success();
    if (line != 0) {
        return line;
    }
    line = replay_test_error_and_abort();
    if (line != 0) {
        return line;
    }
    line = replay_test_protocol_and_reset();
    if (line != 0) {
        return line;
    }
    line = replay_test_invalid_mif_status();
    if (line != 0) {
        return line;
    }
    line = replay_test_compute_hold();
    if (line != 0) {
        return line;
    }
    line = replay_test_stream_compute_credit();
    if (line != 0) {
        return line;
    }
    return replay_test_parallel_pass_and_bursts();
}

#ifdef NPU_BUS_REPLAY_CYCLE_STANDALONE
int main(void)
{
    return test_bus_replay_cycle();
}
#endif
