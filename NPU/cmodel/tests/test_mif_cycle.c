#include "npu_axi_mem_target_cycle.h"
#include "npu_mif_cycle.h"
#include "test_util.h"

#include <stdint.h>
#include <string.h>

#define MIF_TEST_MEMORY_BYTES 16384u
#define MIF_TEST_MAX_CYCLES 2000u
#define MIF_TEST_BASE UINT64_C(0)

typedef struct {
    npu_mif_cycle_t mif;
    npu_axi_mem_target_cycle_t memory;
    npu_mif_cycle_inputs_t mif_inputs;
    npu_axi_mem_target_cycle_inputs_t memory_inputs;
    npu_axi_mem_target_cycle_outputs_t memory_outputs;
} mif_test_env_t;

static uint8_t mif_test_memory[MIF_TEST_MEMORY_BYTES];

static void mif_test_put_u64(uint64_t addr, uint64_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        mif_test_memory[(size_t)addr + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static uint64_t mif_test_get_u64(uint64_t addr)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        value |=
            (uint64_t)mif_test_memory[(size_t)addr + byte] <<
            (byte * 8u);
    }
    return value;
}

static int mif_test_init(mif_test_env_t *env)
{
    npu_mif_cycle_config_t mif_config;
    npu_axi_mem_target_config_t memory_config;

    (void)memset(env, 0, sizeof(*env));
    (void)memset(mif_test_memory, 0, sizeof(mif_test_memory));

    npu_mif_cycle_config_default(&mif_config);
    mif_config.system_addr_base = MIF_TEST_BASE;
    mif_config.system_addr_limit =
        MIF_TEST_BASE + MIF_TEST_MEMORY_BYTES - 8u;
    if (npu_mif_cycle_init(&env->mif, &mif_config) != 0) {
        return 0;
    }

    npu_axi_mem_target_config_reference(&memory_config);
    memory_config.read_latency_cycles = 2u;
    memory_config.write_latency_cycles = 2u;
    if (npu_axi_mem_target_cycle_init(
            &env->memory, mif_test_memory,
            sizeof(mif_test_memory), MIF_TEST_BASE,
            &memory_config) == 0) {
        return 0;
    }

    env->mif_inputs.reset_n = 1u;
    env->mif_inputs.owner[NPU_MIF_OWNER_DFU].rsp_ready = 1u;
    env->mif_inputs.owner[NPU_MIF_OWNER_DMA].rsp_ready = 1u;
    env->memory_inputs.reset_n = 1u;
    return 1;
}

static void mif_test_tick(
    mif_test_env_t *env,
    npu_mif_cycle_outputs_t *outputs)
{
    npu_mif_cycle_step(&env->mif, &env->mif_inputs, outputs);

    (void)memset(&env->memory_inputs, 0,
                 sizeof(env->memory_inputs));
    env->memory_inputs.reset_n = 1u;
    npu_axi_mem_master_from_mif(
        &env->memory_inputs.master, &outputs->axi);
    npu_axi_mem_target_cycle_step(
        &env->memory, &env->memory_inputs,
        &env->memory_outputs);
    npu_axi_mem_target_to_mif(
        &env->mif_inputs.axi,
        &env->memory_outputs.target);
}

static void mif_test_set_request(
    npu_mif_owner_inputs_t *request,
    uint8_t owner,
    uint8_t write,
    uint64_t addr,
    uint8_t beats,
    uint16_t tag,
    uint16_t task_id,
    uint8_t attr)
{
    (void)memset(request, 0, sizeof(*request));
    request->req_valid = 1u;
    request->req_write = write;
    request->req_addr = addr;
    request->req_beats = (uint8_t)(beats - 1u);
    request->req_tag = tag;
    request->req_owner = owner;
    request->req_task_id = task_id;
    request->req_attr = attr;
    request->rsp_ready = 1u;
}

static int mif_test_config(void)
{
    npu_mif_cycle_config_t config;
    npu_mif_cycle_t model;

    npu_mif_cycle_config_default(&config);
    TEST_CHECK(config.system_addr_enable == 1u);
    TEST_CHECK(config.system_addr_base == 0u);
    TEST_CHECK(config.system_addr_limit ==
               (NPU_MIF_ADDR_MASK & ~UINT64_C(7)));
    TEST_CHECK(npu_mif_cycle_config_valid(&config) != 0u);
    TEST_CHECK(npu_mif_cycle_init(&model, &config) == 0);

    config.system_addr_limit = NPU_MIF_ADDR_MASK + 1u;
    TEST_CHECK(npu_mif_cycle_config_valid(&config) == 0u);
    TEST_CHECK(npu_mif_cycle_init(&model, &config) != 0);

    npu_mif_cycle_config_default(&config);
    config.system_addr_base = 8u;
    config.system_addr_limit = 0u;
    TEST_CHECK(npu_mif_cycle_config_valid(&config) == 0u);

    npu_mif_cycle_config_default(&config);
    config.system_addr_base = 1u;
    TEST_CHECK(npu_mif_cycle_config_valid(&config) == 0u);
    return 0;
}

static int mif_test_read_and_4k_split(void)
{
    static const uint64_t expected[4] = {
        UINT64_C(0x1111222233334444),
        UINT64_C(0x5555666677778888),
        UINT64_C(0x9999aaaabbbbcccc),
        UINT64_C(0xddddeeeeffff0001)
    };
    mif_test_env_t env;
    npu_mif_cycle_outputs_t outputs;
    uint64_t ar_addr[2] = {0u, 0u};
    uint8_t ar_len[2] = {0u, 0u};
    uint32_t ar_count = 0u;
    uint32_t rsp_count = 0u;
    uint32_t cycle;
    uint32_t index;

    TEST_CHECK(mif_test_init(&env));
    for (index = 0u; index < 4u; index++) {
        mif_test_put_u64(UINT64_C(0x0ff0) + index * 8u,
                         expected[index]);
    }
    mif_test_set_request(
        &env.mif_inputs.owner[NPU_MIF_OWNER_DFU],
        NPU_MIF_OWNER_DFU, 0u, UINT64_C(0x0ff0),
        4u, 0x123u, 0x456u,
        (uint8_t)(1u << NPU_MIF_ATTR_CACHE_SHIFT));

    for (cycle = 0u; cycle < MIF_TEST_MAX_CYCLES; cycle++) {
        npu_mif_owner_inputs_t *request =
            &env.mif_inputs.owner[NPU_MIF_OWNER_DFU];

        mif_test_tick(&env, &outputs);
        if (request->req_valid != 0u &&
            outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u) {
            request->req_valid = 0u;
        }
        if (outputs.axi.arvalid != 0u &&
            env.mif_inputs.axi.arready != 0u) {
            TEST_CHECK(ar_count < 2u);
            ar_addr[ar_count] = outputs.axi.araddr;
            ar_len[ar_count] = outputs.axi.arlen;
            ar_count++;
        }
        if (outputs.owner[NPU_MIF_OWNER_DFU].rsp_valid != 0u) {
            const npu_mif_owner_outputs_t *response =
                &outputs.owner[NPU_MIF_OWNER_DFU];
            TEST_CHECK(rsp_count < 4u);
            TEST_CHECK(response->rsp_data == expected[rsp_count]);
            TEST_CHECK(response->rsp_tag == 0x123u);
            TEST_CHECK(response->rsp_is_write == 0u);
            TEST_CHECK(response->rsp_status ==
                       NPU_STATUS_SUCCESS);
            TEST_CHECK(response->rsp_last ==
                       (rsp_count == 3u ? 1u : 0u));
            rsp_count++;
        }
        if (rsp_count == 4u &&
            npu_mif_cycle_is_idle(&env.mif) != 0u) {
            break;
        }
    }

    TEST_CHECK(cycle < MIF_TEST_MAX_CYCLES);
    TEST_CHECK(ar_count == 2u);
    TEST_CHECK(ar_addr[0] == UINT64_C(0x0ff0));
    TEST_CHECK(ar_len[0] == 1u);
    TEST_CHECK(ar_addr[1] == UINT64_C(0x1000));
    TEST_CHECK(ar_len[1] == 1u);
    TEST_CHECK(outputs.first_error_valid == 0u);
    TEST_CHECK(outputs.protocol_error_valid == 0u);
    return 0;
}

static int mif_test_out_of_order_axi_ids(void)
{
    npu_mif_cycle_config_t config;
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    npu_mif_owner_inputs_t *dma;
    uint8_t first_id;
    uint8_t second_id;

    npu_mif_cycle_config_default(&config);
    TEST_CHECK(npu_mif_cycle_init(&model, &config) == 0);
    (void)memset(&inputs, 0, sizeof(inputs));
    inputs.reset_n = 1u;
    dma = &inputs.owner[NPU_MIF_OWNER_DMA];

    mif_test_set_request(
        dma, NPU_MIF_OWNER_DMA, 0u, UINT64_C(0x5000),
        1u, 0x061u, 0x071u, 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);
    dma->req_valid = 0u;

    inputs.axi.arready = 1u;
    mif_test_set_request(
        dma, NPU_MIF_OWNER_DMA, 0u, UINT64_C(0x6000),
        1u, 0x062u, 0x072u, 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);
    TEST_CHECK(outputs.axi.arvalid != 0u);
    TEST_CHECK(outputs.axi.araddr == UINT64_C(0x5000));
    first_id = outputs.axi.arid;
    dma->req_valid = 0u;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.arvalid != 0u);
    TEST_CHECK(outputs.axi.araddr == UINT64_C(0x6000));
    second_id = outputs.axi.arid;
    TEST_CHECK(second_id != first_id);
    inputs.axi.arready = 0u;

    inputs.axi.rvalid = 1u;
    inputs.axi.rid = second_id;
    inputs.axi.rdata = UINT64_C(0x2222222222222222);
    inputs.axi.rresp = NPU_MIF_AXI_RESP_OKAY;
    inputs.axi.rlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.rready != 0u);

    inputs.axi.rid = first_id;
    inputs.axi.rdata = UINT64_C(0x1111111111111111);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.rready != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x062u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x2222222222222222));

    inputs.axi.rvalid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x061u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x1111111111111111));
    TEST_CHECK(npu_mif_cycle_is_idle(&model) != 0u);
    return 0;
}

static int mif_test_write(void)
{
    static const uint64_t values[3] = {
        UINT64_C(0x0102030405060708),
        UINT64_C(0x1112131415161718),
        UINT64_C(0x2122232425262728)
    };
    mif_test_env_t env;
    npu_mif_cycle_outputs_t outputs;
    npu_mif_owner_inputs_t *dma;
    uint32_t write_index = 0u;
    uint32_t response_count = 0u;
    uint32_t cycle;

    TEST_CHECK(mif_test_init(&env));
    dma = &env.mif_inputs.owner[NPU_MIF_OWNER_DMA];
    mif_test_set_request(
        dma, NPU_MIF_OWNER_DMA, 1u, UINT64_C(0x0200),
        3u, 0x234u, 0x345u, 0u);

    for (cycle = 0u; cycle < MIF_TEST_MAX_CYCLES; cycle++) {
        if (write_index < 3u) {
            dma->wvalid = 1u;
            dma->wdata = values[write_index];
            dma->wstrb = 0xffu;
            dma->wlast = write_index == 2u ? 1u : 0u;
            dma->wtag = 0x234u;
        } else {
            dma->wvalid = 0u;
        }

        mif_test_tick(&env, &outputs);
        if (dma->req_valid != 0u &&
            outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u) {
            dma->req_valid = 0u;
        }
        if (dma->wvalid != 0u &&
            outputs.owner[NPU_MIF_OWNER_DMA].wready != 0u) {
            write_index++;
        }
        if (outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u) {
            const npu_mif_owner_outputs_t *response =
                &outputs.owner[NPU_MIF_OWNER_DMA];
            TEST_CHECK(response->rsp_tag == 0x234u);
            TEST_CHECK(response->rsp_is_write != 0u);
            TEST_CHECK(response->rsp_last != 0u);
            TEST_CHECK(response->rsp_status ==
                       NPU_STATUS_SUCCESS);
            response_count++;
        }
        if (response_count == 1u &&
            npu_mif_cycle_is_idle(&env.mif) != 0u) {
            break;
        }
    }

    TEST_CHECK(cycle < MIF_TEST_MAX_CYCLES);
    TEST_CHECK(write_index == 3u);
    TEST_CHECK(response_count == 1u);
    TEST_CHECK(mif_test_get_u64(UINT64_C(0x0200)) == values[0]);
    TEST_CHECK(mif_test_get_u64(UINT64_C(0x0208)) == values[1]);
    TEST_CHECK(mif_test_get_u64(UINT64_C(0x0210)) == values[2]);
    return 0;
}

static int mif_test_request_checks(void)
{
    mif_test_env_t env;
    npu_mif_cycle_outputs_t outputs;
    npu_mif_owner_inputs_t *dfu;
    uint32_t cycle;

    TEST_CHECK(mif_test_init(&env));
    dfu = &env.mif_inputs.owner[NPU_MIF_OWNER_DFU];
    mif_test_set_request(
        dfu, NPU_MIF_OWNER_DMA, 0u, UINT64_C(0x0101),
        1u, 0x123u, 0x456u, 0u);

    for (cycle = 0u; cycle < 32u; cycle++) {
        mif_test_tick(&env, &outputs);
        if (dfu->req_valid != 0u &&
            outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u) {
            dfu->req_valid = 0u;
        }
        if (outputs.owner[NPU_MIF_OWNER_DFU].rsp_valid != 0u) {
            TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_status ==
                       NPU_STATUS_BAD_DESC);
            break;
        }
    }
    TEST_CHECK(cycle < 32u);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_MIF_PROTOCOL_REQUEST_OWNER);
    TEST_CHECK(outputs.protocol_error_addr == UINT64_C(0x0101));
    TEST_CHECK(outputs.first_error_valid != 0u);
    TEST_CHECK(outputs.first_error_addr == UINT64_C(0x0101));

    env.mif_inputs.error_clear = 1u;
    mif_test_tick(&env, &outputs);
    env.mif_inputs.error_clear = 0u;
    mif_test_tick(&env, &outputs);
    TEST_CHECK(outputs.first_error_valid == 0u);
    TEST_CHECK(outputs.protocol_error_valid == 0u);
    return 0;
}

static int mif_test_address_fault(void)
{
    mif_test_env_t env;
    npu_mif_cycle_outputs_t outputs;
    npu_mif_owner_inputs_t *dfu;
    uint32_t cycle;

    TEST_CHECK(mif_test_init(&env));
    dfu = &env.mif_inputs.owner[NPU_MIF_OWNER_DFU];
    mif_test_set_request(
        dfu, NPU_MIF_OWNER_DFU, 0u,
        MIF_TEST_MEMORY_BYTES, 1u, 0x321u, 0x654u, 0u);

    for (cycle = 0u; cycle < 32u; cycle++) {
        mif_test_tick(&env, &outputs);
        if (dfu->req_valid != 0u &&
            outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u) {
            dfu->req_valid = 0u;
        }
        if (outputs.owner[NPU_MIF_OWNER_DFU].rsp_valid != 0u) {
            TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_status ==
                       NPU_STATUS_ADDR_FAULT);
            break;
        }
    }
    TEST_CHECK(cycle < 32u);
    TEST_CHECK(outputs.first_error_valid != 0u);
    TEST_CHECK(outputs.first_error_status ==
               NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(outputs.first_error_owner == NPU_MIF_OWNER_DFU);
    TEST_CHECK(outputs.first_error_tag == 0x321u);
    TEST_CHECK(outputs.first_error_task_id == 0x654u);
    TEST_CHECK(outputs.first_error_addr ==
               MIF_TEST_MEMORY_BYTES);
    return 0;
}

static int mif_test_axi_error(void)
{
    mif_test_env_t env;
    npu_mif_cycle_outputs_t outputs;
    npu_mif_owner_inputs_t *dfu;
    npu_axi_mem_target_injection_t injection;
    uint32_t cycle;

    TEST_CHECK(mif_test_init(&env));
    (void)memset(&injection, 0, sizeof(injection));
    injection.valid = 1u;
    injection.addr = UINT64_C(0x0300);
    injection.resp = NPU_AXI_MEM_RESP_DECERR;
    TEST_CHECK(npu_axi_mem_target_set_injection(
        &env.memory, 0u, &injection));

    dfu = &env.mif_inputs.owner[NPU_MIF_OWNER_DFU];
    mif_test_set_request(
        dfu, NPU_MIF_OWNER_DFU, 0u, UINT64_C(0x0300),
        1u, 0x111u, 0x222u, 0u);

    for (cycle = 0u; cycle < MIF_TEST_MAX_CYCLES; cycle++) {
        mif_test_tick(&env, &outputs);
        if (dfu->req_valid != 0u &&
            outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u) {
            dfu->req_valid = 0u;
        }
        if (outputs.owner[NPU_MIF_OWNER_DFU].rsp_valid != 0u) {
            TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_status ==
                       NPU_STATUS_BUS_DECERR);
            break;
        }
    }
    TEST_CHECK(cycle < MIF_TEST_MAX_CYCLES);
    TEST_CHECK(outputs.first_error_valid != 0u);
    TEST_CHECK(outputs.first_error_status ==
               NPU_STATUS_BUS_DECERR);
    TEST_CHECK(outputs.first_error_addr == UINT64_C(0x0300));
    TEST_CHECK(outputs.first_error_axi_id_valid != 0u);
    TEST_CHECK(outputs.first_error_axi_resp ==
               NPU_MIF_AXI_RESP_DECERR);
    return 0;
}

int test_mif_cycle(void)
{
    int line;

    line = mif_test_config();
    if (line != 0) {
        return line;
    }
    line = mif_test_read_and_4k_split();
    if (line != 0) {
        return line;
    }
    line = mif_test_out_of_order_axi_ids();
    if (line != 0) {
        return line;
    }
    line = mif_test_write();
    if (line != 0) {
        return line;
    }
    line = mif_test_request_checks();
    if (line != 0) {
        return line;
    }
    line = mif_test_address_fault();
    if (line != 0) {
        return line;
    }
    return mif_test_axi_error();
}
