#include "npu_control_cycle.h"
#include "test_util.h"

int test_control_cycle(void)
{
    npu_crg_model_t crg;
    npu_crg_inputs_t crg_in = {0};
    npu_crg_outputs_t crg_out = {0};
    npu_wdt_model_t wdt;
    npu_wdt_inputs_t wdt_in = {0};
    npu_wdt_outputs_t wdt_out = {0};

    npu_crg_reset(&crg);
    crg_in.core_clk_i = 1u;
    crg_in.noc_clk_i = 1u;
    crg_in.core_rst_ni = 0u;
    crg_in.noc_rst_ni = 0u;
    crg_in.module_clk_en_i = 0xffu;
    crg_in.module_idle_i = 0xffu;
    npu_crg_cycle(&crg, &crg_in, &crg_out);
    TEST_CHECK(crg_out.core_reset_n == 0u);
    TEST_CHECK(crg_out.noc_reset_n == 0u);
    TEST_CHECK(crg_out.core_clk_gated_o == 0u);

    crg_in.core_rst_ni = 1u;
    crg_in.noc_rst_ni = 1u;
    npu_crg_cycle(&crg, &crg_in, &crg_out);
    TEST_CHECK(crg_out.core_reset_n == 0u);
    TEST_CHECK(crg_out.noc_reset_n == 0u);
    npu_crg_cycle(&crg, &crg_in, &crg_out);
    TEST_CHECK(crg_out.core_reset_n == 1u);
    TEST_CHECK(crg_out.noc_reset_n == 1u);

    crg_in.module_clk_en_i = 0u;
    crg_in.core_clk_i = 0u;
    crg_in.noc_clk_i = 0u;
    crg_in.module_idle_i = 0xfeu;
    npu_crg_cycle(&crg, &crg_in, &crg_out);
    TEST_CHECK((crg_out.module_clk_active_o & 1u) != 0u);
    crg_in.core_clk_i = 1u;
    crg_in.noc_clk_i = 1u;
    npu_crg_cycle(&crg, &crg_in, &crg_out);
    TEST_CHECK(crg_out.core_clk_gated_o == 1u);
    crg_in.module_idle_i = 0xffu;
    npu_crg_cycle(&crg, &crg_in, &crg_out);
    TEST_CHECK(crg_out.core_clk_gated_o == 1u);
    crg_in.core_clk_i = 0u;
    crg_in.noc_clk_i = 0u;
    npu_crg_cycle(&crg, &crg_in, &crg_out);
    crg_in.core_clk_i = 1u;
    crg_in.noc_clk_i = 1u;
    npu_crg_cycle(&crg, &crg_in, &crg_out);
    TEST_CHECK(crg_out.core_clk_gated_o == 0u);

    crg_in.dvfs_prepare_req_i = 1u;
    crg_in.core_idle_i = 1u;
    crg_in.axi_idle_i = 0u;
    npu_crg_cycle(&crg, &crg_in, &crg_out);
    TEST_CHECK(crg_out.dvfs_prepare_ack_o == 0u);
    crg_in.axi_idle_i = 1u;
    npu_crg_cycle(&crg, &crg_in, &crg_out);
    TEST_CHECK(crg_out.dvfs_prepare_ack_o == 1u);

    npu_wdt_reset(&wdt);
    wdt_in.reset_n = 1u;
    wdt_in.enable = 1u;
    wdt_in.timeout_cycles = 3u;
    npu_wdt_cycle(&wdt, &wdt_in, &wdt_out);
    TEST_CHECK(wdt_out.count == 1u && wdt_out.timeout == 0u);
    npu_wdt_cycle(&wdt, &wdt_in, &wdt_out);
    TEST_CHECK(wdt_out.count == 2u && wdt_out.timeout == 0u);
    wdt_in.core_progress = 1u;
    npu_wdt_cycle(&wdt, &wdt_in, &wdt_out);
    TEST_CHECK(wdt_out.count == 0u && wdt_out.timeout == 0u);
    wdt_in.core_progress = 0u;
    npu_wdt_cycle(&wdt, &wdt_in, &wdt_out);
    npu_wdt_cycle(&wdt, &wdt_in, &wdt_out);
    npu_wdt_cycle(&wdt, &wdt_in, &wdt_out);
    TEST_CHECK(wdt_out.timeout == 1u && wdt_out.reset_req == 1u);
    wdt_in.kick = 1u;
    npu_wdt_cycle(&wdt, &wdt_in, &wdt_out);
    TEST_CHECK(wdt_out.timeout == 0u && wdt_out.count == 0u);
    wdt_in.kick = 0u;
    wdt_in.reset_n = 0u;
    npu_wdt_cycle(&wdt, &wdt_in, &wdt_out);
    TEST_CHECK(wdt_out.timeout == 0u);
    return 0;
}
