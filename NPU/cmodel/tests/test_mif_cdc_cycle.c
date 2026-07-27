#include "npu_mif_cdc_cycle.h"
#include "test_util.h"

#include <string.h>

static void cdc_test_inputs_init(
    npu_mif_cdc_core_inputs_t *core_inputs,
    npu_mif_cdc_noc_inputs_t *noc_inputs)
{
    (void)memset(core_inputs, 0, sizeof(*core_inputs));
    (void)memset(noc_inputs, 0, sizeof(*noc_inputs));
    core_inputs->reset_n = 1u;
    noc_inputs->reset_n = 1u;
}

static int cdc_test_release(
    npu_mif_cdc_cycle_t *model,
    npu_mif_cdc_core_inputs_t *core_inputs,
    npu_mif_cdc_core_outputs_t *core_outputs,
    npu_mif_cdc_noc_inputs_t *noc_inputs,
    npu_mif_cdc_noc_outputs_t *noc_outputs)
{
    npu_mif_cdc_cycle_init(model);
    cdc_test_inputs_init(core_inputs, noc_inputs);

    npu_mif_cdc_core_tick(model, core_inputs, core_outputs);
    TEST_CHECK(core_outputs->owner[NPU_MIF_OWNER_DFU].req_ready ==
               0u);
    TEST_CHECK(core_outputs->owner[NPU_MIF_OWNER_DMA].req_ready ==
               0u);

    npu_mif_cdc_noc_tick(model, noc_inputs, noc_outputs);
    TEST_CHECK(noc_outputs->owner[NPU_MIF_OWNER_DFU].req_valid ==
               0u);
    TEST_CHECK(noc_outputs->owner[NPU_MIF_OWNER_DMA].req_valid ==
               0u);
    TEST_CHECK(npu_mif_cdc_cycle_is_active(model) != 0u);
    return 0;
}

static void cdc_test_set_request(
    npu_mif_owner_inputs_t *input,
    uint8_t write,
    uint64_t address,
    uint8_t beats,
    uint16_t tag,
    uint8_t owner,
    uint16_t task_id,
    uint8_t attr)
{
    input->req_valid = 1u;
    input->req_write = write;
    input->req_addr = address;
    input->req_beats = beats;
    input->req_tag = tag;
    input->req_owner = owner;
    input->req_task_id = task_id;
    input->req_attr = attr;
}

static int cdc_test_request_latency_and_hold(void)
{
    npu_mif_cdc_cycle_t model;
    npu_mif_cdc_core_inputs_t core_inputs;
    npu_mif_cdc_core_outputs_t core_outputs;
    npu_mif_cdc_noc_inputs_t noc_inputs;
    npu_mif_cdc_noc_outputs_t noc_outputs;
    const npu_mif_owner_inputs_t *held;
    int line;

    line = cdc_test_release(&model, &core_inputs, &core_outputs,
                            &noc_inputs, &noc_outputs);
    if (line != 0) {
        return line;
    }

    cdc_test_set_request(
        &core_inputs.owner[NPU_MIF_OWNER_DMA],
        1u, UINT64_C(0x0000abcdeff0), 7u, 0x345u,
        NPU_MIF_OWNER_DMA, 0x678u, 0xa5u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].req_ready !=
               0u);
    TEST_CHECK(npu_mif_cdc_req_level(
                   &model, NPU_MIF_OWNER_DMA) == 1u);
    core_inputs.owner[NPU_MIF_OWNER_DMA].req_valid = 0u;

    /*
     * Two receiving-domain synchronizer edges must pass before the pointer is
     * usable.  The valid payload is visible on the following API call.
     */
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid ==
               0u);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid ==
               0u);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid !=
               0u);

    held = &noc_outputs.owner[NPU_MIF_OWNER_DMA];
    TEST_CHECK(held->req_write == 1u);
    TEST_CHECK(held->req_addr == UINT64_C(0x0000abcdeff0));
    TEST_CHECK(held->req_beats == 7u);
    TEST_CHECK(held->req_tag == 0x345u);
    TEST_CHECK(held->req_owner == NPU_MIF_OWNER_DMA);
    TEST_CHECK(held->req_task_id == 0x678u);
    TEST_CHECK(held->req_attr == 0xa5u);

    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid !=
               0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_addr ==
               UINT64_C(0x0000abcdeff0));
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_tag ==
               0x345u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_attr ==
               0xa5u);

    noc_inputs.owner[NPU_MIF_OWNER_DMA].req_ready = 1u;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid !=
               0u);
    TEST_CHECK(npu_mif_cdc_req_level(
                   &model, NPU_MIF_OWNER_DMA) == 0u);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid ==
               0u);
    return 0;
}

static int cdc_test_request_full_and_order(void)
{
    npu_mif_cdc_cycle_t model;
    npu_mif_cdc_core_inputs_t core_inputs;
    npu_mif_cdc_core_outputs_t core_outputs;
    npu_mif_cdc_noc_inputs_t noc_inputs;
    npu_mif_cdc_noc_outputs_t noc_outputs;
    uint8_t index;
    int line;

    line = cdc_test_release(&model, &core_inputs, &core_outputs,
                            &noc_inputs, &noc_outputs);
    if (line != 0) {
        return line;
    }

    for (index = 0u; index < NPU_MIF_CDC_REQ_FIFO_DEPTH;
         index++) {
        cdc_test_set_request(
            &core_inputs.owner[NPU_MIF_OWNER_DMA],
            0u, UINT64_C(0x1000) + (uint64_t)index * 8u,
            index, (uint16_t)(0x100u + index),
            NPU_MIF_OWNER_DMA, (uint16_t)(0x200u + index),
            (uint8_t)(0x10u + index));
        npu_mif_cdc_core_tick(&model, &core_inputs,
                              &core_outputs);
        TEST_CHECK(
            core_outputs.owner[NPU_MIF_OWNER_DMA].req_ready !=
            0u);
    }
    TEST_CHECK(npu_mif_cdc_req_level(
                   &model, NPU_MIF_OWNER_DMA) ==
               NPU_MIF_CDC_REQ_FIFO_DEPTH);

    cdc_test_set_request(
        &core_inputs.owner[NPU_MIF_OWNER_DMA],
        0u, UINT64_C(0x2000), 0u, 0x1ffu,
        NPU_MIF_OWNER_DMA, 0x2ffu, 0x7fu);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].req_ready ==
               0u);
    TEST_CHECK(npu_mif_cdc_req_level(
                   &model, NPU_MIF_OWNER_DMA) ==
               NPU_MIF_CDC_REQ_FIFO_DEPTH);

    noc_inputs.owner[NPU_MIF_OWNER_DMA].req_ready = 1u;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid ==
               0u);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid ==
               0u);

    for (index = 0u; index < NPU_MIF_CDC_REQ_FIFO_DEPTH;
         index++) {
        npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
        TEST_CHECK(
            noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid !=
            0u);
        TEST_CHECK(
            noc_outputs.owner[NPU_MIF_OWNER_DMA].req_tag ==
            (uint16_t)(0x100u + index));
        TEST_CHECK(
            noc_outputs.owner[NPU_MIF_OWNER_DMA].req_addr ==
            UINT64_C(0x1000) + (uint64_t)index * 8u);
    }
    TEST_CHECK(npu_mif_cdc_req_level(
                   &model, NPU_MIF_OWNER_DMA) == 0u);

    /*
     * The writer sees released space only after the read pointer has crossed
     * its own two receiving stages.
     */
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].req_ready ==
               0u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].req_ready ==
               0u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].req_ready !=
               0u);
    TEST_CHECK(npu_mif_cdc_req_level(
                   &model, NPU_MIF_OWNER_DMA) == 1u);
    return 0;
}

static int cdc_test_write_owner_and_tag_association(void)
{
    npu_mif_cdc_cycle_t model;
    npu_mif_cdc_core_inputs_t core_inputs;
    npu_mif_cdc_core_outputs_t core_outputs;
    npu_mif_cdc_noc_inputs_t noc_inputs;
    npu_mif_cdc_noc_outputs_t noc_outputs;
    int line;

    line = cdc_test_release(&model, &core_inputs, &core_outputs,
                            &noc_inputs, &noc_outputs);
    if (line != 0) {
        return line;
    }

    cdc_test_set_request(
        &core_inputs.owner[NPU_MIF_OWNER_DFU],
        1u, UINT64_C(0x4000), 0u, 0x55u,
        NPU_MIF_OWNER_DFU, 0x101u, 0x11u);
    core_inputs.owner[NPU_MIF_OWNER_DFU].wvalid = 1u;
    core_inputs.owner[NPU_MIF_OWNER_DFU].wdata =
        UINT64_C(0x1111222233334444);
    core_inputs.owner[NPU_MIF_OWNER_DFU].wstrb = 0x0fu;
    core_inputs.owner[NPU_MIF_OWNER_DFU].wlast = 1u;
    core_inputs.owner[NPU_MIF_OWNER_DFU].wtag = 0x55u;

    cdc_test_set_request(
        &core_inputs.owner[NPU_MIF_OWNER_DMA],
        1u, UINT64_C(0x8000), 0u, 0x55u,
        NPU_MIF_OWNER_DMA, 0x202u, 0x22u);
    core_inputs.owner[NPU_MIF_OWNER_DMA].wvalid = 1u;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wdata =
        UINT64_C(0xaaaabbbbccccdddd);
    core_inputs.owner[NPU_MIF_OWNER_DMA].wstrb = 0xf0u;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wlast = 1u;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wtag = 0x55u;

    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DFU].req_ready !=
               0u);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DFU].wready !=
               0u);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].req_ready !=
               0u);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].wready !=
               0u);
    TEST_CHECK(model.w_fifo[NPU_MIF_OWNER_DFU].entry[0].owner ==
               NPU_MIF_OWNER_DFU);
    TEST_CHECK(model.w_fifo[NPU_MIF_OWNER_DMA].entry[0].owner ==
               NPU_MIF_OWNER_DMA);
    (void)memset(core_inputs.owner, 0,
                 sizeof(core_inputs.owner));

    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DFU].req_valid !=
               0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DFU].wvalid !=
               0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid !=
               0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].wvalid !=
               0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DFU].req_addr ==
               UINT64_C(0x4000));
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DFU].wdata ==
               UINT64_C(0x1111222233334444));
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DFU].wtag ==
               0x55u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_addr ==
               UINT64_C(0x8000));
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].wdata ==
               UINT64_C(0xaaaabbbbccccdddd));
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].wtag ==
               0x55u);

    noc_inputs.owner[NPU_MIF_OWNER_DMA].req_ready = 1u;
    noc_inputs.owner[NPU_MIF_OWNER_DMA].wready = 1u;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DFU].req_addr ==
               UINT64_C(0x4000));
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DFU].wdata ==
               UINT64_C(0x1111222233334444));
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid !=
               0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].wvalid !=
               0u);

    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid ==
               0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].wvalid == 0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DFU].req_valid !=
               0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DFU].wvalid !=
               0u);

    noc_inputs.owner[NPU_MIF_OWNER_DFU].req_ready = 1u;
    noc_inputs.owner[NPU_MIF_OWNER_DFU].wready = 1u;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(npu_mif_cdc_req_level(
                   &model, NPU_MIF_OWNER_DFU) == 0u);
    TEST_CHECK(npu_mif_cdc_w_level(
                   &model, NPU_MIF_OWNER_DFU) == 0u);
    return 0;
}

static int cdc_test_write_full_and_order(void)
{
    npu_mif_cdc_cycle_t model;
    npu_mif_cdc_core_inputs_t core_inputs;
    npu_mif_cdc_core_outputs_t core_outputs;
    npu_mif_cdc_noc_inputs_t noc_inputs;
    npu_mif_cdc_noc_outputs_t noc_outputs;
    uint8_t index;
    int line;

    line = cdc_test_release(&model, &core_inputs, &core_outputs,
                            &noc_inputs, &noc_outputs);
    if (line != 0) {
        return line;
    }

    for (index = 0u; index < NPU_MIF_CDC_W_FIFO_DEPTH;
         index++) {
        npu_mif_owner_inputs_t *write =
            &core_inputs.owner[NPU_MIF_OWNER_DMA];
        write->wvalid = 1u;
        write->wdata =
            UINT64_C(0x7000000000000000) + index;
        write->wstrb = (uint8_t)(0x80u | index);
        write->wlast =
            (uint8_t)(index ==
                      NPU_MIF_CDC_W_FIFO_DEPTH - 1u);
        write->wtag = (uint16_t)(0x500u + index);
        npu_mif_cdc_core_tick(&model, &core_inputs,
                              &core_outputs);
        TEST_CHECK(
            core_outputs.owner[NPU_MIF_OWNER_DMA].wready !=
            0u);
    }
    TEST_CHECK(npu_mif_cdc_w_level(
                   &model, NPU_MIF_OWNER_DMA) ==
               NPU_MIF_CDC_W_FIFO_DEPTH);

    core_inputs.owner[NPU_MIF_OWNER_DMA].wdata =
        UINT64_C(0x7fffffffffffffff);
    core_inputs.owner[NPU_MIF_OWNER_DMA].wstrb = 0xffu;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wlast = 1u;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wtag = 0x5ffu;
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].wready ==
               0u);

    noc_inputs.owner[NPU_MIF_OWNER_DMA].wready = 1u;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].wvalid == 0u);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].wvalid == 0u);
    for (index = 0u; index < NPU_MIF_CDC_W_FIFO_DEPTH;
         index++) {
        npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
        TEST_CHECK(
            noc_outputs.owner[NPU_MIF_OWNER_DMA].wvalid != 0u);
        TEST_CHECK(
            noc_outputs.owner[NPU_MIF_OWNER_DMA].wdata ==
            UINT64_C(0x7000000000000000) + index);
        TEST_CHECK(
            noc_outputs.owner[NPU_MIF_OWNER_DMA].wstrb ==
            (uint8_t)(0x80u | index));
        TEST_CHECK(
            noc_outputs.owner[NPU_MIF_OWNER_DMA].wtag ==
            (uint16_t)(0x500u + index));
        TEST_CHECK(
            noc_outputs.owner[NPU_MIF_OWNER_DMA].wlast ==
            (uint8_t)(index ==
                      NPU_MIF_CDC_W_FIFO_DEPTH - 1u));
    }
    TEST_CHECK(npu_mif_cdc_w_level(
                   &model, NPU_MIF_OWNER_DMA) == 0u);

    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].wready ==
               0u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].wready ==
               0u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].wready !=
               0u);
    TEST_CHECK(npu_mif_cdc_w_level(
                   &model, NPU_MIF_OWNER_DMA) == 1u);
    return 0;
}

static int cdc_test_response_full_order_and_hold(void)
{
    npu_mif_cdc_cycle_t model;
    npu_mif_cdc_core_inputs_t core_inputs;
    npu_mif_cdc_core_outputs_t core_outputs;
    npu_mif_cdc_noc_inputs_t noc_inputs;
    npu_mif_cdc_noc_outputs_t noc_outputs;
    uint8_t index;
    int line;

    line = cdc_test_release(&model, &core_inputs, &core_outputs,
                            &noc_inputs, &noc_outputs);
    if (line != 0) {
        return line;
    }

    for (index = 0u; index < NPU_MIF_CDC_RSP_FIFO_DEPTH;
         index++) {
        npu_mif_owner_outputs_t *response =
            &noc_inputs.owner[NPU_MIF_OWNER_DMA];
        response->rsp_valid = 1u;
        response->rsp_data =
            UINT64_C(0x1000000000000000) + index;
        response->rsp_tag = (uint16_t)(0x300u + index);
        response->rsp_is_write = (uint8_t)(index == 7u);
        response->rsp_last = (uint8_t)(index == 7u);
        response->rsp_status = index;
        npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
        TEST_CHECK(
            noc_outputs.owner[NPU_MIF_OWNER_DMA].rsp_ready !=
            0u);
    }
    TEST_CHECK(npu_mif_cdc_rsp_level(
                   &model, NPU_MIF_OWNER_DMA) ==
               NPU_MIF_CDC_RSP_FIFO_DEPTH);

    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_data =
        UINT64_C(0xffffffffffffffff);
    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_tag = 0x3ffu;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].rsp_ready ==
               0u);
    TEST_CHECK(npu_mif_cdc_rsp_level(
                   &model, NPU_MIF_OWNER_DMA) ==
               NPU_MIF_CDC_RSP_FIFO_DEPTH);
    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_valid = 0u;

    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid ==
               0u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid ==
               0u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid !=
               0u);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x1000000000000000));
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag ==
               0x300u);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               0u);

    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid !=
               0u);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x1000000000000000));
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag ==
               0x300u);

    core_inputs.owner[NPU_MIF_OWNER_DMA].rsp_ready = 1u;
    for (index = 0u; index < NPU_MIF_CDC_RSP_FIFO_DEPTH;
         index++) {
        npu_mif_cdc_core_tick(&model, &core_inputs,
                              &core_outputs);
        TEST_CHECK(
            core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid !=
            0u);
        TEST_CHECK(
            core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
            UINT64_C(0x1000000000000000) + index);
        TEST_CHECK(
            core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag ==
            (uint16_t)(0x300u + index));
        TEST_CHECK(
            core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
            index);
    }
    TEST_CHECK(npu_mif_cdc_rsp_level(
                   &model, NPU_MIF_OWNER_DMA) == 0u);

    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_valid = 1u;
    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_data =
        UINT64_C(0xfeedfacecafebeef);
    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_tag = 0x3ffu;
    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_is_write = 1u;
    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_last = 1u;
    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_status = 0x5au;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].rsp_ready ==
               0u);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].rsp_ready ==
               0u);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].rsp_ready !=
               0u);
    TEST_CHECK(npu_mif_cdc_rsp_level(
                   &model, NPU_MIF_OWNER_DMA) == 1u);
    return 0;
}

static int cdc_test_reset_flushes_all_channels(void)
{
    npu_mif_cdc_cycle_t model;
    npu_mif_cdc_core_inputs_t core_inputs;
    npu_mif_cdc_core_outputs_t core_outputs;
    npu_mif_cdc_noc_inputs_t noc_inputs;
    npu_mif_cdc_noc_outputs_t noc_outputs;
    uint32_t old_epoch;
    uint8_t index;
    int line;

    line = cdc_test_release(&model, &core_inputs, &core_outputs,
                            &noc_inputs, &noc_outputs);
    if (line != 0) {
        return line;
    }

    cdc_test_set_request(
        &core_inputs.owner[NPU_MIF_OWNER_DMA],
        1u, UINT64_C(0x9000), 1u, 0x77u,
        NPU_MIF_OWNER_DMA, 0x88u, 0x44u);
    core_inputs.owner[NPU_MIF_OWNER_DMA].wvalid = 1u;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wdata =
        UINT64_C(0x123456789abcdef0);
    core_inputs.owner[NPU_MIF_OWNER_DMA].wstrb = 0xffu;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wlast = 0u;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wtag = 0x77u;
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);

    noc_inputs.owner[NPU_MIF_OWNER_DFU].rsp_valid = 1u;
    noc_inputs.owner[NPU_MIF_OWNER_DFU].rsp_data =
        UINT64_C(0x8877665544332211);
    noc_inputs.owner[NPU_MIF_OWNER_DFU].rsp_tag = 0x66u;
    noc_inputs.owner[NPU_MIF_OWNER_DFU].rsp_last = 1u;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(npu_mif_cdc_req_level(
                   &model, NPU_MIF_OWNER_DMA) == 1u);
    TEST_CHECK(npu_mif_cdc_w_level(
                   &model, NPU_MIF_OWNER_DMA) == 1u);
    TEST_CHECK(npu_mif_cdc_rsp_level(
                   &model, NPU_MIF_OWNER_DFU) == 1u);

    old_epoch = model.reset_epoch;
    core_inputs.reset_n = 0u;
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(model.reset_epoch == old_epoch + 1u);
    TEST_CHECK(npu_mif_cdc_cycle_is_active(&model) == 0u);
    TEST_CHECK(npu_mif_cdc_req_level(
                   &model, NPU_MIF_OWNER_DMA) == 0u);
    TEST_CHECK(npu_mif_cdc_w_level(
                   &model, NPU_MIF_OWNER_DMA) == 0u);
    TEST_CHECK(npu_mif_cdc_rsp_level(
                   &model, NPU_MIF_OWNER_DFU) == 0u);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].req_ready ==
               0u);

    core_inputs.reset_n = 1u;
    core_inputs.owner[NPU_MIF_OWNER_DMA].req_valid = 0u;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wvalid = 0u;
    noc_inputs.owner[NPU_MIF_OWNER_DFU].rsp_valid = 0u;

    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid ==
               0u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    for (index = 0u; index < 4u; index++) {
        npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
        TEST_CHECK(
            noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid ==
            0u);
        TEST_CHECK(
            noc_outputs.owner[NPU_MIF_OWNER_DMA].wvalid == 0u);
        npu_mif_cdc_core_tick(&model, &core_inputs,
                              &core_outputs);
        TEST_CHECK(
            core_outputs.owner[NPU_MIF_OWNER_DFU].rsp_valid ==
            0u);
    }

    cdc_test_set_request(
        &core_inputs.owner[NPU_MIF_OWNER_DMA],
        0u, UINT64_C(0xa000), 0u, 0x77u,
        NPU_MIF_OWNER_DMA, 0x99u, 0u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].req_ready !=
               0u);
    core_inputs.owner[NPU_MIF_OWNER_DMA].req_valid = 0u;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid !=
               0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_addr ==
               UINT64_C(0xa000));

    noc_inputs.reset_n = 0u;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(npu_mif_cdc_cycle_is_active(&model) == 0u);
    TEST_CHECK(npu_mif_cdc_req_level(
                   &model, NPU_MIF_OWNER_DMA) == 0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid ==
               0u);
    return 0;
}

static int cdc_test_epoch_release_gate(void)
{
    npu_mif_cdc_cycle_t model;
    npu_mif_cdc_core_inputs_t core_inputs;
    npu_mif_cdc_core_outputs_t core_outputs;
    npu_mif_cdc_noc_inputs_t noc_inputs;
    npu_mif_cdc_noc_outputs_t noc_outputs;
    uint32_t old_epoch;
    int line;

    line = cdc_test_release(&model, &core_inputs, &core_outputs,
                            &noc_inputs, &noc_outputs);
    if (line != 0) {
        return line;
    }

    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.transport_active != 0u);
    old_epoch = core_outputs.reset_epoch;

    noc_inputs.reset_n = 0u;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.reset_epoch == old_epoch + 1u);
    TEST_CHECK(noc_outputs.transport_active == 0u);
    TEST_CHECK(npu_mif_cdc_cycle_is_active(&model) == 0u);

    noc_inputs.reset_n = 1u;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.reset_epoch == old_epoch + 1u);
    TEST_CHECK(noc_outputs.transport_active == 0u);

    /*
     * The Core-side copy changes only after two receiving-domain stages.
     * A separate release edge follows the epoch observation, so no payload
     * can move on the same API call that first exposes the new value.
     */
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.reset_epoch == old_epoch);
    TEST_CHECK(core_outputs.transport_active == 0u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.reset_epoch == old_epoch);
    TEST_CHECK(core_outputs.transport_active == 0u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.reset_epoch == old_epoch + 1u);
    TEST_CHECK(core_outputs.transport_active == 0u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.reset_epoch == old_epoch + 1u);
    TEST_CHECK(core_outputs.transport_active != 0u);
    return 0;
}

static int cdc_test_unusual_values_and_null_safety(void)
{
    npu_mif_cdc_cycle_t model;
    npu_mif_cdc_core_inputs_t core_inputs;
    npu_mif_cdc_core_outputs_t core_outputs;
    npu_mif_cdc_noc_inputs_t noc_inputs;
    npu_mif_cdc_noc_outputs_t noc_outputs;
    int line;

    (void)memset(&core_outputs, 0xff, sizeof(core_outputs));
    npu_mif_cdc_core_tick(NULL, NULL, &core_outputs);
    TEST_CHECK(core_outputs.owner[0].req_ready == 0u);
    (void)memset(&noc_outputs, 0xff, sizeof(noc_outputs));
    npu_mif_cdc_noc_tick(NULL, NULL, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[0].req_valid == 0u);
    npu_mif_cdc_cycle_init(NULL);
    npu_mif_cdc_cycle_reset(NULL);
    npu_mif_cdc_core_tick(NULL, NULL, NULL);
    npu_mif_cdc_noc_tick(NULL, NULL, NULL);

    line = cdc_test_release(&model, &core_inputs, &core_outputs,
                            &noc_inputs, &noc_outputs);
    if (line != 0) {
        return line;
    }

    cdc_test_set_request(
        &core_inputs.owner[NPU_MIF_OWNER_DMA],
        0xffu, UINT64_MAX, UINT8_MAX, UINT16_MAX,
        UINT8_MAX, UINT16_MAX, UINT8_MAX);
    core_inputs.owner[NPU_MIF_OWNER_DMA].wvalid = 0xffu;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wdata = UINT64_MAX;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wstrb = UINT8_MAX;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wlast = UINT8_MAX;
    core_inputs.owner[NPU_MIF_OWNER_DMA].wtag = UINT16_MAX;
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].req_ready !=
               0u);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].wready !=
               0u);
    (void)memset(core_inputs.owner, 0,
                 sizeof(core_inputs.owner));

    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_valid !=
               0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_owner ==
               UINT8_MAX);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_addr ==
               UINT64_MAX);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].req_tag ==
               UINT16_MAX);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].wvalid != 0u);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].wdata ==
               UINT64_MAX);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].wtag ==
               UINT16_MAX);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DFU].req_valid ==
               0u);

    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_valid = UINT8_MAX;
    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_data = UINT64_MAX;
    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_tag = UINT16_MAX;
    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_is_write =
        UINT8_MAX;
    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_last = UINT8_MAX;
    noc_inputs.owner[NPU_MIF_OWNER_DMA].rsp_status = UINT8_MAX;
    npu_mif_cdc_noc_tick(&model, &noc_inputs, &noc_outputs);
    TEST_CHECK(noc_outputs.owner[NPU_MIF_OWNER_DMA].rsp_ready !=
               0u);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    npu_mif_cdc_core_tick(&model, &core_inputs, &core_outputs);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid !=
               0u);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_MAX);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag ==
               UINT16_MAX);
    TEST_CHECK(core_outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               UINT8_MAX);

    TEST_CHECK(npu_mif_cdc_req_level(&model, UINT8_MAX) == 0u);
    TEST_CHECK(npu_mif_cdc_w_level(&model, UINT8_MAX) == 0u);
    TEST_CHECK(npu_mif_cdc_rsp_level(&model, UINT8_MAX) == 0u);
    TEST_CHECK(npu_mif_cdc_req_level(NULL,
                                     NPU_MIF_OWNER_DMA) == 0u);
    return 0;
}

int test_mif_cdc_cycle(void)
{
    int line;

    line = cdc_test_request_latency_and_hold();
    if (line != 0) {
        return line;
    }
    line = cdc_test_request_full_and_order();
    if (line != 0) {
        return line;
    }
    line = cdc_test_write_owner_and_tag_association();
    if (line != 0) {
        return line;
    }
    line = cdc_test_write_full_and_order();
    if (line != 0) {
        return line;
    }
    line = cdc_test_response_full_order_and_hold();
    if (line != 0) {
        return line;
    }
    line = cdc_test_reset_flushes_all_channels();
    if (line != 0) {
        return line;
    }
    line = cdc_test_epoch_release_gate();
    if (line != 0) {
        return line;
    }
    return cdc_test_unusual_values_and_null_safety();
}
