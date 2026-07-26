#include "npu_sys_slave_cycle.h"

#include <string.h>

#ifdef NPU_SYS_SLAVE_CYCLE_STANDALONE
#include <stdio.h>
#endif

#define SYS_TEST_CHECK(condition)   \
    do {                            \
        if (!(condition)) {         \
            return __LINE__;        \
        }                           \
    } while (0)

static void sys_test_inputs_default(
    npu_sys_slave_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->core_reset_n = 1u;
    inputs->core_idle_i = 1u;
    inputs->l1_diag_enable_i = 1u;
}

static int sys_test_init(npu_sys_slave_cycle_t *adapter)
{
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;

    SYS_TEST_CHECK(npu_sys_slave_cycle_init(
                       adapter,
                       NPU_SYS_SLAVE_DEFAULT_L1_BYTES) == 0);
    sys_test_inputs_default(&inputs);
    inputs.core_reset_n = 0u;
    inputs.s_axi_awvalid = 1u;
    inputs.s_axi_arvalid = 1u;
    npu_sys_slave_cycle_step(adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_awready == 0u);
    SYS_TEST_CHECK(outputs.s_axi_arready == 0u);
    SYS_TEST_CHECK(outputs.s_axi_wready == 0u);
    SYS_TEST_CHECK(outputs.s_axi_bvalid == 0u);
    SYS_TEST_CHECK(outputs.s_axi_rvalid == 0u);
    SYS_TEST_CHECK(outputs.reg_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.idle != 0u);
    SYS_TEST_CHECK(outputs.cycle == 0u);
    SYS_TEST_CHECK(npu_sys_slave_cycle_idle(adapter) != 0u);
    return 0;
}

static int sys_test_begin_write(
    npu_sys_slave_cycle_t *adapter,
    uint32_t addr,
    uint8_t len,
    uint8_t size,
    uint8_t id)
{
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;

    sys_test_inputs_default(&inputs);
    inputs.s_axi_awvalid = 1u;
    inputs.s_axi_awid = id;
    inputs.s_axi_awaddr = addr;
    inputs.s_axi_awlen = len;
    inputs.s_axi_awsize = size;
    inputs.s_axi_awburst =
        (uint8_t)NPU_SYS_AXI_BURST_INCR;
    npu_sys_slave_cycle_step(adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_awready != 0u);
    SYS_TEST_CHECK(outputs.s_axi_wready == 0u);
    return 0;
}

static int sys_test_begin_read(
    npu_sys_slave_cycle_t *adapter,
    uint32_t addr,
    uint8_t len,
    uint8_t size,
    uint8_t id,
    uint8_t core_idle,
    uint8_t debug_frozen,
    uint8_t diag_enable)
{
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;

    sys_test_inputs_default(&inputs);
    inputs.core_idle_i = core_idle;
    inputs.debug_frozen_i = debug_frozen;
    inputs.l1_diag_enable_i = diag_enable;
    inputs.s_axi_arvalid = 1u;
    inputs.s_axi_arid = id;
    inputs.s_axi_araddr = addr;
    inputs.s_axi_arlen = len;
    inputs.s_axi_arsize = size;
    inputs.s_axi_arburst =
        (uint8_t)NPU_SYS_AXI_BURST_INCR;
    npu_sys_slave_cycle_step(adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_arready != 0u);
    return 0;
}

static int sys_test_send_write_beat(
    npu_sys_slave_cycle_t *adapter,
    uint64_t data,
    uint8_t strb,
    uint8_t last)
{
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;

    sys_test_inputs_default(&inputs);
    inputs.s_axi_wvalid = 1u;
    inputs.s_axi_wdata = data;
    inputs.s_axi_wstrb = strb;
    inputs.s_axi_wlast = last;
    npu_sys_slave_cycle_step(adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_wready != 0u);
    SYS_TEST_CHECK(outputs.s_axi_awready == 0u);
    return 0;
}

static int sys_test_csr_write_and_stalls(void)
{
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    npu_sys_slave_outputs_t held;
    int rc;

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }

    sys_test_inputs_default(&inputs);
    inputs.s_axi_wvalid = 1u;
    inputs.s_axi_wdata = UINT64_C(0xffffffffffffffff);
    inputs.s_axi_wstrb = 0xffu;
    inputs.s_axi_wlast = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_wready == 0u);
    SYS_TEST_CHECK(adapter.write.received_beats == 0u);

    rc = sys_test_begin_write(
        &adapter, 0x000040u, 0u, 3u, 0x31u);
    if (rc != 0) {
        return rc;
    }

    sys_test_inputs_default(&inputs);
    inputs.s_axi_wvalid = 1u;
    inputs.s_axi_wdata = UINT64_C(0x8877665544332211);
    inputs.s_axi_wstrb = 0xffu;
    inputs.s_axi_wlast = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_wready != 0u);

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o != 0u);
    SYS_TEST_CHECK(outputs.reg_req_write_o != 0u);
    SYS_TEST_CHECK(outputs.reg_req_space_o == 0u);
    SYS_TEST_CHECK(outputs.reg_req_addr_o == 0x0040u);
    SYS_TEST_CHECK(outputs.reg_req_wdata_o ==
                   UINT64_C(0x8877665544332211));
    SYS_TEST_CHECK(outputs.reg_req_wstrb_o == 0xffu);
    held = outputs;

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o ==
                   held.reg_req_valid_o);
    SYS_TEST_CHECK(outputs.reg_req_write_o ==
                   held.reg_req_write_o);
    SYS_TEST_CHECK(outputs.reg_req_space_o ==
                   held.reg_req_space_o);
    SYS_TEST_CHECK(outputs.reg_req_addr_o ==
                   held.reg_req_addr_o);
    SYS_TEST_CHECK(outputs.reg_req_wdata_o ==
                   held.reg_req_wdata_o);
    SYS_TEST_CHECK(outputs.reg_req_wstrb_o ==
                   held.reg_req_wstrb_o);

    sys_test_inputs_default(&inputs);
    inputs.reg_req_ready_i = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o != 0u);

    sys_test_inputs_default(&inputs);
    inputs.reg_rsp_valid_i = 1u;
    inputs.reg_rsp_status_i =
        (uint8_t)NPU_SYS_AXI_RESP_OKAY;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_rsp_ready_o != 0u);
    SYS_TEST_CHECK(outputs.reg_req_space_o == 0u);
    SYS_TEST_CHECK(outputs.reg_req_addr_o == 0x0040u);

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_bvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_bid == 0x31u);
    SYS_TEST_CHECK(outputs.s_axi_bresp ==
                   NPU_SYS_AXI_RESP_OKAY);
    held = outputs;

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_bvalid ==
                   held.s_axi_bvalid);
    SYS_TEST_CHECK(outputs.s_axi_bid == held.s_axi_bid);
    SYS_TEST_CHECK(outputs.s_axi_bresp ==
                   held.s_axi_bresp);

    sys_test_inputs_default(&inputs);
    inputs.s_axi_bready = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_bvalid != 0u);

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_bvalid == 0u);
    SYS_TEST_CHECK(outputs.idle != 0u);
    return 0;
}

static int sys_test_debug_read_space_and_stalls(void)
{
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    npu_sys_slave_outputs_t held;
    int rc;

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_read(
        &adapter, 0x010120u, 0u, 3u, 0x52u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o == 0u);

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o != 0u);
    SYS_TEST_CHECK(outputs.reg_req_write_o == 0u);
    SYS_TEST_CHECK(outputs.s_axi_arready == 0u);
    SYS_TEST_CHECK(outputs.reg_req_space_o == 1u);
    SYS_TEST_CHECK(outputs.reg_req_addr_o == 0x0120u);
    held = outputs;

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o != 0u);
    SYS_TEST_CHECK(outputs.reg_req_space_o ==
                   held.reg_req_space_o);
    SYS_TEST_CHECK(outputs.reg_req_addr_o ==
                   held.reg_req_addr_o);

    sys_test_inputs_default(&inputs);
    inputs.reg_req_ready_i = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o != 0u);

    sys_test_inputs_default(&inputs);
    inputs.reg_rsp_valid_i = 1u;
    inputs.reg_rsp_rdata_i =
        UINT64_C(0xfedcba9876543210);
    inputs.reg_rsp_status_i =
        (uint8_t)NPU_SYS_AXI_RESP_OKAY;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_rsp_ready_o != 0u);
    SYS_TEST_CHECK(outputs.reg_req_space_o == 1u);
    SYS_TEST_CHECK(outputs.reg_req_addr_o == 0x0120u);

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_rvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_rid == 0x52u);
    SYS_TEST_CHECK(outputs.s_axi_rdata ==
                   UINT64_C(0xfedcba9876543210));
    SYS_TEST_CHECK(outputs.s_axi_rresp ==
                   NPU_SYS_AXI_RESP_OKAY);
    SYS_TEST_CHECK(outputs.s_axi_rlast != 0u);
    held = outputs;

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_rvalid ==
                   held.s_axi_rvalid);
    SYS_TEST_CHECK(outputs.s_axi_rid == held.s_axi_rid);
    SYS_TEST_CHECK(outputs.s_axi_rdata ==
                   held.s_axi_rdata);
    SYS_TEST_CHECK(outputs.s_axi_rresp ==
                   held.s_axi_rresp);
    SYS_TEST_CHECK(outputs.s_axi_rlast ==
                   held.s_axi_rlast);

    sys_test_inputs_default(&inputs);
    inputs.s_axi_rready = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_rvalid != 0u);

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_rvalid == 0u);
    SYS_TEST_CHECK(outputs.idle != 0u);
    return 0;
}

static int sys_test_l1_narrow_access(void)
{
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    int rc;

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_write(
        &adapter, NPU_SYS_SLAVE_L1_BASE + 0x24u,
        0u, 2u, 0x61u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_send_write_beat(
        &adapter, UINT64_C(0xaabbccdd00000000),
        0xf0u, 1u);
    if (rc != 0) {
        return rc;
    }

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o != 0u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_write_o != 0u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_addr_o == 0x20u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_wdata_o ==
                   UINT64_C(0xaabbccdd00000000));
    SYS_TEST_CHECK(outputs.ssa_l1_req_wstrb_o == 0xf0u);

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o != 0u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_write_o != 0u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_addr_o == 0x20u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_wdata_o ==
                   UINT64_C(0xaabbccdd00000000));
    SYS_TEST_CHECK(outputs.ssa_l1_req_wstrb_o == 0xf0u);

    sys_test_inputs_default(&inputs);
    inputs.ssa_l1_req_ready_i = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o != 0u);

    sys_test_inputs_default(&inputs);
    inputs.ssa_l1_rsp_valid_i = 1u;
    inputs.ssa_l1_rsp_status_i =
        (uint8_t)NPU_SYS_L1_STATUS_OK;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_rsp_ready_o != 0u);

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_bvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_bresp ==
                   NPU_SYS_AXI_RESP_OKAY);
    inputs.s_axi_bready = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);

    rc = sys_test_begin_read(
        &adapter, NPU_SYS_SLAVE_L1_BASE + 0x24u,
        0u, 2u, 0x62u, 1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    sys_test_inputs_default(&inputs);
    inputs.ssa_l1_req_ready_i = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o != 0u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_write_o == 0u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_addr_o == 0x20u);

    sys_test_inputs_default(&inputs);
    inputs.ssa_l1_rsp_valid_i = 1u;
    inputs.ssa_l1_rsp_rdata_i =
        UINT64_C(0xaabbccdd44332211);
    inputs.ssa_l1_rsp_status_i =
        (uint8_t)NPU_SYS_L1_STATUS_ECC_CORRECTED;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_rsp_ready_o != 0u);

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_rvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_rdata ==
                   UINT64_C(0xaabbccdd00000000));
    SYS_TEST_CHECK(outputs.s_axi_rresp ==
                   NPU_SYS_AXI_RESP_OKAY);
    SYS_TEST_CHECK(outputs.s_axi_rlast != 0u);
    return 0;
}

static int sys_test_l1_all_narrow_sizes(void)
{
    static const uint8_t size[3] = {0u, 1u, 2u};
    static const uint32_t offset[3] = {
        0x17u, 0x16u, 0x14u
    };
    static const uint64_t expected[3] = {
        UINT64_C(0x8000000000000000),
        UINT64_C(0x8070000000000000),
        UINT64_C(0x8070605000000000)
    };
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    uint32_t index;
    int rc;

    for (index = 0u; index < 3u; index++) {
        rc = sys_test_init(&adapter);
        if (rc != 0) {
            return rc;
        }
        rc = sys_test_begin_read(
            &adapter,
            NPU_SYS_SLAVE_L1_BASE + offset[index],
            0u, size[index], (uint8_t)(0x64u + index),
            1u, 0u, 1u);
        if (rc != 0) {
            return rc;
        }

        sys_test_inputs_default(&inputs);
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(
            outputs.ssa_l1_req_valid_o == 0u);

        sys_test_inputs_default(&inputs);
        inputs.ssa_l1_req_ready_i = 1u;
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(
            outputs.ssa_l1_req_valid_o != 0u);
        SYS_TEST_CHECK(
            outputs.ssa_l1_req_addr_o == 0x10u);

        sys_test_inputs_default(&inputs);
        inputs.ssa_l1_rsp_valid_i = 1u;
        inputs.ssa_l1_rsp_rdata_i =
            UINT64_C(0x8070605040302010);
        inputs.ssa_l1_rsp_status_i =
            (uint8_t)NPU_SYS_L1_STATUS_OK;
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(
            outputs.ssa_l1_rsp_ready_o != 0u);

        sys_test_inputs_default(&inputs);
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(outputs.s_axi_rvalid != 0u);
        SYS_TEST_CHECK(
            outputs.s_axi_rdata ==
            expected[index]);
        SYS_TEST_CHECK(
            outputs.s_axi_rresp ==
            NPU_SYS_AXI_RESP_OKAY);
        SYS_TEST_CHECK(outputs.s_axi_rlast != 0u);
    }
    return 0;
}

static int sys_test_csr_32bit_lanes(void)
{
    static const uint32_t address[2] = {
        0x000040u, 0x000044u
    };
    static const uint64_t write_data[2] = {
        UINT64_C(0x00000000deadbeef),
        UINT64_C(0xcafebabe00000000)
    };
    static const uint8_t write_strobe[2] = {
        0x0fu, 0xf0u
    };
    static const uint64_t read_data[2] = {
        UINT64_C(0x0000000044332211),
        UINT64_C(0xaabbccdd00000000)
    };
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    uint32_t index;
    int rc;

    for (index = 0u; index < 2u; index++) {
        rc = sys_test_init(&adapter);
        if (rc != 0) {
            return rc;
        }
        rc = sys_test_begin_write(
            &adapter, address[index], 0u, 2u,
            (uint8_t)(0x66u + index));
        if (rc != 0) {
            return rc;
        }
        rc = sys_test_send_write_beat(
            &adapter, write_data[index],
            write_strobe[index], 1u);
        if (rc != 0) {
            return rc;
        }

        sys_test_inputs_default(&inputs);
        inputs.reg_req_ready_i = 1u;
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(outputs.reg_req_valid_o != 0u);
        SYS_TEST_CHECK(outputs.reg_req_write_o != 0u);
        SYS_TEST_CHECK(outputs.reg_req_space_o == 0u);
        SYS_TEST_CHECK(outputs.reg_req_addr_o == 0x0040u);
        SYS_TEST_CHECK(
            outputs.reg_req_wdata_o == write_data[index]);
        SYS_TEST_CHECK(
            outputs.reg_req_wstrb_o ==
            write_strobe[index]);

        sys_test_inputs_default(&inputs);
        inputs.reg_rsp_valid_i = 1u;
        inputs.reg_rsp_status_i =
            (uint8_t)NPU_SYS_AXI_RESP_OKAY;
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(outputs.reg_rsp_ready_o != 0u);

        sys_test_inputs_default(&inputs);
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(outputs.s_axi_bvalid != 0u);
        SYS_TEST_CHECK(
            outputs.s_axi_bresp ==
            NPU_SYS_AXI_RESP_OKAY);
    }

    for (index = 0u; index < 2u; index++) {
        rc = sys_test_init(&adapter);
        if (rc != 0) {
            return rc;
        }
        rc = sys_test_begin_read(
            &adapter, address[index], 0u, 2u,
            (uint8_t)(0x68u + index),
            1u, 0u, 1u);
        if (rc != 0) {
            return rc;
        }

        sys_test_inputs_default(&inputs);
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);

        sys_test_inputs_default(&inputs);
        inputs.reg_req_ready_i = 1u;
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(outputs.reg_req_valid_o != 0u);
        SYS_TEST_CHECK(outputs.reg_req_write_o == 0u);
        SYS_TEST_CHECK(outputs.reg_req_space_o == 0u);
        SYS_TEST_CHECK(outputs.reg_req_addr_o == 0x0040u);

        sys_test_inputs_default(&inputs);
        inputs.reg_rsp_valid_i = 1u;
        inputs.reg_rsp_rdata_i =
            UINT64_C(0xaabbccdd44332211);
        inputs.reg_rsp_status_i =
            (uint8_t)NPU_SYS_AXI_RESP_OKAY;
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(outputs.reg_rsp_ready_o != 0u);

        sys_test_inputs_default(&inputs);
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(outputs.s_axi_rvalid != 0u);
        SYS_TEST_CHECK(
            outputs.s_axi_rid ==
            (uint8_t)(0x68u + index));
        SYS_TEST_CHECK(
            outputs.s_axi_rdata == read_data[index]);
        SYS_TEST_CHECK(
            outputs.s_axi_rresp ==
            NPU_SYS_AXI_RESP_OKAY);
        SYS_TEST_CHECK(outputs.s_axi_rlast != 0u);
    }
    return 0;
}

static int sys_test_l1_write_burst(void)
{
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    uint16_t beat;
    int rc;

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_write(
        &adapter, NPU_SYS_SLAVE_L1_BASE + 0x100u,
        2u, 3u, 0x70u);
    if (rc != 0) {
        return rc;
    }

    for (beat = 0u; beat < 3u; beat++) {
        uint64_t data =
            UINT64_C(0x1010101010101010) + beat;

        rc = sys_test_send_write_beat(
            &adapter, data, 0xffu,
            (uint8_t)(beat == 2u));
        if (rc != 0) {
            return rc;
        }

        sys_test_inputs_default(&inputs);
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(
            outputs.ssa_l1_req_valid_o != 0u);
        SYS_TEST_CHECK(
            outputs.ssa_l1_req_write_o != 0u);
        SYS_TEST_CHECK(
            outputs.ssa_l1_req_addr_o ==
            0x100u + (uint32_t)beat * 8u);
        SYS_TEST_CHECK(
            outputs.ssa_l1_req_wdata_o == data);
        SYS_TEST_CHECK(
            outputs.ssa_l1_req_wstrb_o == 0xffu);

        sys_test_inputs_default(&inputs);
        inputs.ssa_l1_req_ready_i = 1u;
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(
            outputs.ssa_l1_req_valid_o != 0u);

        sys_test_inputs_default(&inputs);
        inputs.ssa_l1_rsp_valid_i = 1u;
        inputs.ssa_l1_rsp_status_i =
            (uint8_t)NPU_SYS_L1_STATUS_OK;
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(
            outputs.ssa_l1_rsp_ready_o != 0u);
    }

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_bvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_bid == 0x70u);
    SYS_TEST_CHECK(outputs.s_axi_bresp ==
                   NPU_SYS_AXI_RESP_OKAY);
    return 0;
}

static int sys_test_l1_read_burst_and_error_stop(void)
{
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    uint16_t beat;
    int rc;

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_read(
        &adapter, NPU_SYS_SLAVE_L1_BASE + 0x180u,
        2u, 3u, 0x71u, 1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);

    for (beat = 0u; beat < 2u; beat++) {
        uint64_t data =
            UINT64_C(0x8899aabbccdd0000) + beat;

        sys_test_inputs_default(&inputs);
        inputs.ssa_l1_req_ready_i = 1u;
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(
            outputs.ssa_l1_req_valid_o != 0u);
        SYS_TEST_CHECK(
            outputs.ssa_l1_req_write_o == 0u);
        SYS_TEST_CHECK(
            outputs.ssa_l1_req_addr_o ==
            0x180u + (uint32_t)beat * 8u);

        sys_test_inputs_default(&inputs);
        inputs.ssa_l1_rsp_valid_i = 1u;
        inputs.ssa_l1_rsp_rdata_i = data;
        inputs.ssa_l1_rsp_status_i =
            beat == 0u ?
                (uint8_t)NPU_SYS_L1_STATUS_OK :
                (uint8_t)
                    NPU_SYS_L1_STATUS_ECC_UNCORRECTABLE;
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(
            outputs.ssa_l1_rsp_ready_o != 0u);

        sys_test_inputs_default(&inputs);
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(outputs.s_axi_rvalid != 0u);
        SYS_TEST_CHECK(outputs.s_axi_rid == 0x71u);
        SYS_TEST_CHECK(outputs.s_axi_rdata == data);
        SYS_TEST_CHECK(
            outputs.s_axi_rresp ==
            (beat == 0u ?
                 NPU_SYS_AXI_RESP_OKAY :
                 NPU_SYS_AXI_RESP_SLVERR));
        SYS_TEST_CHECK(outputs.s_axi_rlast == 0u);

        sys_test_inputs_default(&inputs);
        inputs.s_axi_rready = 1u;
        npu_sys_slave_cycle_step(
            &adapter, &inputs, &outputs);
        SYS_TEST_CHECK(outputs.s_axi_rvalid != 0u);
    }

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.s_axi_rvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_rdata == 0u);
    SYS_TEST_CHECK(outputs.s_axi_rresp ==
                   NPU_SYS_AXI_RESP_SLVERR);
    SYS_TEST_CHECK(outputs.s_axi_rlast != 0u);
    return 0;
}

static int sys_test_l1_write_error_stops_requests(void)
{
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    uint16_t beat;
    int rc;

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_write(
        &adapter, NPU_SYS_SLAVE_L1_BASE + 0x280u,
        2u, 3u, 0x72u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_send_write_beat(
        &adapter, UINT64_C(0x1111222233334444),
        0xffu, 0u);
    if (rc != 0) {
        return rc;
    }

    sys_test_inputs_default(&inputs);
    inputs.ssa_l1_req_ready_i = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o != 0u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_addr_o == 0x280u);

    sys_test_inputs_default(&inputs);
    inputs.ssa_l1_rsp_valid_i = 1u;
    inputs.ssa_l1_rsp_status_i =
        (uint8_t)NPU_SYS_L1_STATUS_ADDR_FAULT;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_rsp_ready_o != 0u);

    for (beat = 1u; beat < 3u; beat++) {
        rc = sys_test_send_write_beat(
            &adapter,
            UINT64_C(0x5555666677770000) + beat,
            0xffu, (uint8_t)(beat == 2u));
        if (rc != 0) {
            return rc;
        }
        SYS_TEST_CHECK(
            adapter.l1_request.valid == 0u);
        SYS_TEST_CHECK(
            adapter.l1_response_owner ==
            (uint8_t)NPU_SYS_OWNER_NONE);
    }

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.s_axi_bvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_bid == 0x72u);
    SYS_TEST_CHECK(outputs.s_axi_bresp ==
                   NPU_SYS_AXI_RESP_SLVERR);
    return 0;
}

static int sys_test_expect_read_error(
    uint32_t addr,
    uint8_t len,
    uint8_t size,
    uint8_t burst,
    uint8_t lock,
    uint8_t core_idle,
    uint8_t debug_frozen,
    uint8_t diag_enable)
{
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    int rc;

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }

    sys_test_inputs_default(&inputs);
    inputs.core_idle_i = core_idle;
    inputs.debug_frozen_i = debug_frozen;
    inputs.l1_diag_enable_i = diag_enable;
    inputs.s_axi_arvalid = 1u;
    inputs.s_axi_arid = 0x91u;
    inputs.s_axi_araddr = addr;
    inputs.s_axi_arlen = len;
    inputs.s_axi_arsize = size;
    inputs.s_axi_arburst = burst;
    inputs.s_axi_arlock = lock;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_arready != 0u);

    sys_test_inputs_default(&inputs);
    inputs.core_idle_i = core_idle;
    inputs.debug_frozen_i = debug_frozen;
    inputs.l1_diag_enable_i = diag_enable;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o == 0u);

    sys_test_inputs_default(&inputs);
    inputs.core_idle_i = core_idle;
    inputs.debug_frozen_i = debug_frozen;
    inputs.l1_diag_enable_i = diag_enable;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.s_axi_rvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_rid == 0x91u);
    SYS_TEST_CHECK(outputs.s_axi_rresp ==
                   NPU_SYS_AXI_RESP_SLVERR);
    return 0;
}

static int sys_test_permissions_and_address_errors(void)
{
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    int rc;

    rc = sys_test_expect_read_error(
        NPU_SYS_SLAVE_L1_BASE, 0u, 3u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 0u,
        1u, 0u, 0u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        NPU_SYS_SLAVE_L1_BASE, 0u, 3u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 0u,
        0u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        NPU_SYS_SLAVE_DEBUG_BASE, 0u, 3u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 0u,
        0u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        NPU_SYS_SLAVE_L1_BASE + 0xff8u, 1u, 3u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 0u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        NPU_SYS_SLAVE_L1_BASE +
            NPU_SYS_SLAVE_DEFAULT_L1_BYTES - 8u,
        1u, 3u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 0u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        0x000000u, 1u, 3u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 0u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        0x000000u, 0u, 1u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 0u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        NPU_SYS_SLAVE_DEBUG_BASE, 0u, 2u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 0u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        NPU_SYS_SLAVE_L1_BASE, 1u, 2u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 0u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        NPU_SYS_SLAVE_L1_BASE + 3u, 0u, 1u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 0u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        NPU_SYS_SLAVE_L1_BASE, 0u, 4u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 0u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        NPU_SYS_SLAVE_L1_BASE, 0u, 3u,
        (uint8_t)NPU_SYS_AXI_BURST_FIXED, 0u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        NPU_SYS_SLAVE_L1_BASE, 0u, 3u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 1u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_expect_read_error(
        0x01000000u, 0u, 3u,
        (uint8_t)NPU_SYS_AXI_BURST_INCR, 0u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_read(
        &adapter, NPU_SYS_SLAVE_DEBUG_BASE,
        0u, 3u, 0x92u, 0u, 1u, 1u);
    if (rc != 0) {
        return rc;
    }
    sys_test_inputs_default(&inputs);
    inputs.core_idle_i = 0u;
    inputs.debug_frozen_i = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    sys_test_inputs_default(&inputs);
    inputs.core_idle_i = 0u;
    inputs.debug_frozen_i = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o != 0u);
    SYS_TEST_CHECK(outputs.reg_req_space_o == 1u);
    return 0;
}

static int sys_test_reserved_and_internal_errors(void)
{
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    int rc;

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_read(
        &adapter, 0x020004u, 0u, 2u, 0xa1u,
        1u, 0u, 1u);
    if (rc != 0) {
        return rc;
    }
    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_rvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_rdata == 0u);
    SYS_TEST_CHECK(outputs.s_axi_rresp ==
                   NPU_SYS_AXI_RESP_OKAY);
    inputs.s_axi_rready = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);

    rc = sys_test_begin_write(
        &adapter, 0x020004u, 0u, 2u, 0xa2u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_send_write_beat(
        &adapter, UINT64_C(0x1234567800000000),
        0xf0u, 1u);
    if (rc != 0) {
        return rc;
    }
    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.s_axi_bvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_bresp ==
                   NPU_SYS_AXI_RESP_OKAY);

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_write(
        &adapter, 0x000048u, 0u, 3u, 0xa3u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_send_write_beat(
        &adapter, UINT64_C(0x55aa55aa55aa55aa),
        0xffu, 1u);
    if (rc != 0) {
        return rc;
    }
    sys_test_inputs_default(&inputs);
    inputs.reg_req_ready_i = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o != 0u);
    sys_test_inputs_default(&inputs);
    inputs.reg_rsp_valid_i = 1u;
    inputs.reg_rsp_status_i =
        (uint8_t)NPU_SYS_AXI_RESP_SLVERR;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_rsp_ready_o != 0u);
    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_bvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_bresp ==
                   NPU_SYS_AXI_RESP_SLVERR);
    return 0;
}

static int sys_test_write_protocol_errors(void)
{
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    int rc;

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_write(
        &adapter, 0x000000u, 1u, 3u, 0xb0u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_send_write_beat(
        &adapter, UINT64_C(0x0102030405060708),
        0xffu, 0u);
    if (rc != 0) {
        return rc;
    }
    SYS_TEST_CHECK(adapter.reg_request.valid == 0u);
    rc = sys_test_send_write_beat(
        &adapter, UINT64_C(0x1112131415161718),
        0xffu, 1u);
    if (rc != 0) {
        return rc;
    }
    SYS_TEST_CHECK(adapter.reg_request.valid == 0u);
    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.reg_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.s_axi_bvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_bresp ==
                   NPU_SYS_AXI_RESP_SLVERR);

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_write(
        &adapter, NPU_SYS_SLAVE_L1_BASE + 0x200u,
        1u, 3u, 0xb1u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_send_write_beat(
        &adapter, UINT64_C(0x1111111111111111),
        0xffu, 1u);
    if (rc != 0) {
        return rc;
    }
    sys_test_inputs_default(&inputs);
    inputs.s_axi_wvalid = 1u;
    inputs.s_axi_wdata = UINT64_C(0x2222222222222222);
    inputs.s_axi_wstrb = 0xffu;
    inputs.s_axi_wlast = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_wready != 0u);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o == 0u);
    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.s_axi_bvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_bresp ==
                   NPU_SYS_AXI_RESP_SLVERR);

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_write(
        &adapter, NPU_SYS_SLAVE_L1_BASE + 0x240u,
        0u, 3u, 0xb2u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_send_write_beat(
        &adapter, UINT64_C(0x3333333333333333),
        0xffu, 0u);
    if (rc != 0) {
        return rc;
    }
    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.s_axi_bvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_bresp ==
                   NPU_SYS_AXI_RESP_SLVERR);

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_write(
        &adapter, NPU_SYS_SLAVE_L1_BASE + 0x244u,
        0u, 2u, 0xb3u);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_send_write_beat(
        &adapter, UINT64_C(0x00000000deadbeef),
        0x0fu, 1u);
    if (rc != 0) {
        return rc;
    }
    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.ssa_l1_req_valid_o == 0u);
    SYS_TEST_CHECK(outputs.s_axi_bvalid != 0u);
    SYS_TEST_CHECK(outputs.s_axi_bresp ==
                   NPU_SYS_AXI_RESP_SLVERR);
    return 0;
}

static int sys_test_reset_aborts_transactions(void)
{
    npu_sys_slave_cycle_t adapter;
    npu_sys_slave_inputs_t inputs;
    npu_sys_slave_outputs_t outputs;
    int rc;

    rc = sys_test_init(&adapter);
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_begin_write(
        &adapter, 0x000040u, 0u, 3u, 0xc1u);
    if (rc != 0) {
        return rc;
    }
    SYS_TEST_CHECK(npu_sys_slave_cycle_idle(&adapter) == 0u);

    sys_test_inputs_default(&inputs);
    inputs.core_reset_n = 0u;
    inputs.s_axi_wvalid = 1u;
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_wready == 0u);
    SYS_TEST_CHECK(outputs.s_axi_bvalid == 0u);
    SYS_TEST_CHECK(outputs.idle != 0u);
    SYS_TEST_CHECK(adapter.l1_bytes ==
                   NPU_SYS_SLAVE_DEFAULT_L1_BYTES);

    sys_test_inputs_default(&inputs);
    npu_sys_slave_cycle_step(&adapter, &inputs, &outputs);
    SYS_TEST_CHECK(outputs.s_axi_awready != 0u);
    SYS_TEST_CHECK(outputs.s_axi_arready != 0u);
    SYS_TEST_CHECK(outputs.idle != 0u);

    SYS_TEST_CHECK(npu_sys_slave_cycle_init(
                       &adapter, 0u) != 0);
    SYS_TEST_CHECK(npu_sys_slave_cycle_init(
                       &adapter,
                       NPU_SYS_SLAVE_L1_WINDOW_BYTES + 8u) !=
                   0);
    SYS_TEST_CHECK(npu_sys_slave_cycle_init(
                       &adapter,
                       NPU_SYS_SLAVE_DEFAULT_L1_BYTES + 1u) !=
                   0);
    return 0;
}

int test_sys_slave_cycle(void)
{
    int rc;

    rc = sys_test_csr_write_and_stalls();
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_debug_read_space_and_stalls();
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_l1_narrow_access();
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_l1_all_narrow_sizes();
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_csr_32bit_lanes();
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_l1_write_burst();
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_l1_read_burst_and_error_stop();
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_l1_write_error_stops_requests();
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_permissions_and_address_errors();
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_reserved_and_internal_errors();
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_write_protocol_errors();
    if (rc != 0) {
        return rc;
    }
    rc = sys_test_reset_aborts_transactions();
    if (rc != 0) {
        return rc;
    }
    return 0;
}

#ifdef NPU_SYS_SLAVE_CYCLE_STANDALONE
int main(void)
{
    int result = test_sys_slave_cycle();

    if (result != 0) {
        (void)printf(
            "test_sys_slave_cycle failed at line %d\n",
            result);
        return 1;
    }
    (void)printf("test_sys_slave_cycle passed\n");
    return 0;
}
#endif
