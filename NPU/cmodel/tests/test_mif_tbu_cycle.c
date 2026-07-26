#include "npu_mif_cycle.h"
#include "npu_tbu_cycle.h"
#include "test_util.h"

#include <string.h>

#ifdef NPU_MIF_TBU_CYCLE_STANDALONE
#include <stdio.h>
#endif

typedef struct {
    npu_mif_cycle_t mif;
    npu_tbu_cycle_t tbu;
    npu_mif_cycle_inputs_t mif_inputs;
    npu_mif_cycle_outputs_t mif_outputs;
    npu_tbu_cycle_outputs_t tbu_outputs;
} mif_tbu_test_env_t;

static void mif_tbu_test_init(mif_tbu_test_env_t *env)
{
    npu_mif_cycle_config_t config;

    (void)memset(env, 0, sizeof(*env));
    npu_mif_cycle_config_default(&config);
    config.ddr_enable = 1u;
    config.ddr_base = 0u;
    config.ddr_limit = UINT64_C(0xffff8);
    config.ext_enable = 0u;
    config.bypass_enable = 0u;
    config.tbu_stream_id = 0x31u;
    config.tbu_substream_id = 0x42u;
    npu_mif_cycle_init(&env->mif, &config);
    npu_tbu_cycle_init(&env->tbu);
    env->mif_inputs.reset_n = 1u;
    env->mif_inputs.owner[NPU_MIF_OWNER_DFU].rsp_ready = 1u;
    env->mif_inputs.owner[NPU_MIF_OWNER_DMA].rsp_ready = 1u;
}

static void mif_tbu_test_tick(mif_tbu_test_env_t *env)
{
    npu_tbu_cycle_inputs_t tbu_inputs = {0};

    tbu_inputs.reset_n = env->mif_inputs.reset_n;
    tbu_inputs.req_valid = env->mif_outputs.tbu.req_valid;
    tbu_inputs.req_vaddr = env->mif_outputs.tbu.req_vaddr;
    tbu_inputs.req_write = env->mif_outputs.tbu.req_write;
    tbu_inputs.req_stream_id =
        env->mif_outputs.tbu.req_stream_id;
    tbu_inputs.req_substream_id =
        env->mif_outputs.tbu.req_substream_id;
    tbu_inputs.req_tag = env->mif_outputs.tbu.req_tag;
    tbu_inputs.rsp_ready = env->mif_outputs.tbu.rsp_ready;
    npu_tbu_cycle_eval(
        &env->tbu, &tbu_inputs, &env->tbu_outputs);

    env->mif_inputs.tbu.req_ready =
        env->tbu_outputs.req_ready;
    env->mif_inputs.tbu.rsp_valid =
        env->tbu_outputs.rsp_valid;
    env->mif_inputs.tbu.rsp_paddr =
        env->tbu_outputs.rsp_paddr;
    env->mif_inputs.tbu.rsp_tag =
        env->tbu_outputs.rsp_tag;
    env->mif_inputs.tbu.rsp_status =
        env->tbu_outputs.rsp_status;
    npu_mif_cycle_step(
        &env->mif, &env->mif_inputs, &env->mif_outputs);

    tbu_inputs.req_valid = env->mif_outputs.tbu.req_valid;
    tbu_inputs.req_vaddr = env->mif_outputs.tbu.req_vaddr;
    tbu_inputs.req_write = env->mif_outputs.tbu.req_write;
    tbu_inputs.req_stream_id =
        env->mif_outputs.tbu.req_stream_id;
    tbu_inputs.req_substream_id =
        env->mif_outputs.tbu.req_substream_id;
    tbu_inputs.req_tag = env->mif_outputs.tbu.req_tag;
    tbu_inputs.rsp_ready = env->mif_outputs.tbu.rsp_ready;
    npu_tbu_cycle_step(
        &env->tbu, &tbu_inputs, &env->tbu_outputs);
}

static int mif_tbu_test_submit_read(mif_tbu_test_env_t *env,
                                    uint64_t vaddr,
                                    uint16_t tag,
                                    uint16_t task_id)
{
    npu_mif_owner_inputs_t *dma =
        &env->mif_inputs.owner[NPU_MIF_OWNER_DMA];
    uint32_t cycle;

    dma->req_valid = 1u;
    dma->req_write = 0u;
    dma->req_vaddr = vaddr;
    dma->req_beats = 0u;
    dma->req_tag = tag;
    dma->req_owner = NPU_MIF_OWNER_DMA;
    dma->req_task_id = task_id;
    dma->req_attr = 0u;
    for (cycle = 0u; cycle < 8u; cycle++) {
        mif_tbu_test_tick(env);
        if (env->mif_outputs
                .owner[NPU_MIF_OWNER_DMA]
                .req_ready != 0u) {
            dma->req_valid = 0u;
            return 0;
        }
    }
    dma->req_valid = 0u;
    return __LINE__;
}

static int mif_tbu_test_translated_read(void)
{
    mif_tbu_test_env_t env;
    npu_tbu_rule_t rule = {0};
    uint8_t axi_id = 0u;
    uint8_t saw_tbu_request = 0u;
    uint8_t saw_ar = 0u;
    uint32_t cycle;
    int line;

    mif_tbu_test_init(&env);
    rule.valid = 1u;
    rule.virtual_page = UINT64_C(0x40);
    rule.physical_page = 0x80u;
    rule.stream_id = 0x31u;
    rule.substream_id = 0x42u;
    rule.read_enable = 1u;
    rule.write_enable = 1u;
    TEST_CHECK(npu_tbu_cycle_set_rule(
        &env.tbu, 0u, &rule));

    line = mif_tbu_test_submit_read(
        &env, UINT64_C(0x40128), 0x155u, 0x266u);
    if (line != 0) {
        return line;
    }

    for (cycle = 0u; cycle < 24u; cycle++) {
        mif_tbu_test_tick(&env);
        if (env.mif_outputs.tbu.req_valid != 0u &&
            env.tbu_outputs.req_ready != 0u) {
            saw_tbu_request = 1u;
        }
        if (env.mif_outputs
                .axi[NPU_MIF_AXI_DDR]
                .arvalid != 0u) {
            TEST_CHECK(saw_tbu_request != 0u);
            TEST_CHECK(
                env.mif_outputs
                    .axi[NPU_MIF_AXI_DDR]
                    .araddr == UINT64_C(0x80128));
            TEST_CHECK(
                env.mif_outputs
                    .axi[NPU_MIF_AXI_DDR]
                    .arlen == 0u);
            axi_id =
                env.mif_outputs
                    .axi[NPU_MIF_AXI_DDR]
                    .arid;
            saw_ar = 1u;
            break;
        }
    }
    TEST_CHECK(saw_ar != 0u);

    env.mif_inputs.axi[NPU_MIF_AXI_DDR].arready = 1u;
    mif_tbu_test_tick(&env);
    TEST_CHECK(
        env.mif_outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    env.mif_inputs.axi[NPU_MIF_AXI_DDR].arready = 0u;

    env.mif_inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
    env.mif_inputs.axi[NPU_MIF_AXI_DDR].rid = axi_id;
    env.mif_inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0x1122334455667788);
    env.mif_inputs.axi[NPU_MIF_AXI_DDR].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    env.mif_inputs.axi[NPU_MIF_AXI_DDR].rlast = 1u;
    mif_tbu_test_tick(&env);
    TEST_CHECK(
        env.mif_outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    env.mif_inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;

    for (cycle = 0u; cycle < 8u; cycle++) {
        mif_tbu_test_tick(&env);
        if (env.mif_outputs
                .owner[NPU_MIF_OWNER_DMA]
                .rsp_valid != 0u) {
            TEST_CHECK(
                env.mif_outputs
                    .owner[NPU_MIF_OWNER_DMA]
                    .rsp_data ==
                UINT64_C(0x1122334455667788));
            TEST_CHECK(
                env.mif_outputs
                    .owner[NPU_MIF_OWNER_DMA]
                    .rsp_tag == 0x155u);
            TEST_CHECK(
                env.mif_outputs
                    .owner[NPU_MIF_OWNER_DMA]
                    .rsp_last != 0u);
            TEST_CHECK(
                env.mif_outputs
                    .owner[NPU_MIF_OWNER_DMA]
                    .rsp_status == NPU_STATUS_SUCCESS);
            return 0;
        }
    }
    return __LINE__;
}

static int mif_tbu_test_permission_error(void)
{
    mif_tbu_test_env_t env;
    npu_tbu_rule_t rule = {0};
    uint8_t saw_axi = 0u;
    uint32_t cycle;
    int line;

    mif_tbu_test_init(&env);
    rule.valid = 1u;
    rule.virtual_page = UINT64_C(0x50);
    rule.physical_page = 0x90u;
    rule.stream_id = 0x31u;
    rule.substream_id = 0x42u;
    rule.read_enable = 0u;
    rule.write_enable = 1u;
    TEST_CHECK(npu_tbu_cycle_set_rule(
        &env.tbu, 0u, &rule));
    line = mif_tbu_test_submit_read(
        &env, UINT64_C(0x50008), 0x177u, 0x288u);
    if (line != 0) {
        return line;
    }

    for (cycle = 0u;
         cycle < NPU_TBU_HIT_LATENCY + 16u;
         cycle++) {
        mif_tbu_test_tick(&env);
        if (env.mif_outputs
                    .axi[NPU_MIF_AXI_DDR]
                    .arvalid != 0u ||
            env.mif_outputs
                    .axi[NPU_MIF_AXI_EXT]
                    .arvalid != 0u) {
            saw_axi = 1u;
        }
        if (env.mif_outputs
                .owner[NPU_MIF_OWNER_DMA]
                .rsp_valid != 0u) {
            TEST_CHECK(saw_axi == 0u);
            TEST_CHECK(
                env.mif_outputs
                    .owner[NPU_MIF_OWNER_DMA]
                    .rsp_tag == 0x177u);
            TEST_CHECK(
                env.mif_outputs
                    .owner[NPU_MIF_OWNER_DMA]
                    .rsp_status == NPU_STATUS_ADDR_FAULT);
            return 0;
        }
    }
    return __LINE__;
}

int test_mif_tbu_cycle(void)
{
    int line;

    line = mif_tbu_test_translated_read();
    if (line != 0) {
        return line;
    }
    line = mif_tbu_test_permission_error();
    if (line != 0) {
        return line;
    }
    return 0;
}

#ifdef NPU_MIF_TBU_CYCLE_STANDALONE
int main(void)
{
    int line = test_mif_tbu_cycle();

    if (line == 0) {
        (void)printf("[PASS] mif_tbu_cycle\n");
        return 0;
    }
    (void)printf(
        "[FAIL] mif_tbu_cycle at test line %d\n", line);
    return 1;
}
#endif
