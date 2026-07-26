#include "npu_mif_cycle.h"
#include "test_util.h"

#include <string.h>

#ifdef NPU_MIF_CYCLE_STANDALONE
#include <stdio.h>
#endif

int test_mif_cycle(void);

static void mif_test_inputs_init(npu_mif_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = 1u;
    inputs->owner[NPU_MIF_OWNER_DFU].rsp_ready = 1u;
    inputs->owner[NPU_MIF_OWNER_DMA].rsp_ready = 1u;
}

static void mif_test_model_init(npu_mif_cycle_t *model,
                                npu_mif_cycle_inputs_t *inputs)
{
    npu_mif_cycle_config_t config;

    npu_mif_cycle_config_default(&config);
    config.ddr_enable = 1u;
    config.ddr_base = 0u;
    config.ddr_limit = UINT64_C(0x000000000007fff8);
    config.ext_enable = 1u;
    config.ext_base = UINT64_C(0x0000000000080000);
    config.ext_limit = UINT64_C(0x00000000000ffff8);
    config.bypass_enable = 1u;
    config.bypass_base = 0u;
    config.bypass_limit = UINT64_C(0x00000000000ffff8);
    config.tbu_stream_id = 0x1234u;
    config.tbu_substream_id = 0x5678u;
    npu_mif_cycle_init(model, &config);
    mif_test_inputs_init(inputs);
}

static uint8_t mif_test_request_count(
    const npu_mif_cycle_t *model)
{
    uint8_t count = 0u;
    uint8_t index;

    for (index = 0u; index < NPU_MIF_MAX_REQUESTS; index++) {
        if (model->requests[index].valid != 0u) {
            count++;
        }
    }
    return count;
}

static uint8_t mif_test_find_request(
    const npu_mif_cycle_t *model,
    uint8_t owner,
    uint16_t tag)
{
    uint8_t index;

    for (index = 0u; index < NPU_MIF_MAX_REQUESTS; index++) {
        if (model->requests[index].valid != 0u &&
            model->requests[index].owner == owner &&
            model->requests[index].tag == tag) {
            return index;
        }
    }
    return NPU_MIF_INVALID_SLOT;
}

static void mif_test_set_read_request(
    npu_mif_owner_inputs_t *input,
    uint8_t owner,
    uint64_t vaddr,
    uint16_t tag,
    uint16_t task_id,
    uint8_t attr)
{
    input->req_valid = 1u;
    input->req_write = 0u;
    input->req_vaddr = vaddr;
    input->req_beats = 0u;
    input->req_tag = tag;
    input->req_owner = owner;
    input->req_task_id = task_id;
    input->req_attr = attr;
}

static int mif_submit_dma(npu_mif_cycle_t *model,
                          npu_mif_cycle_inputs_t *inputs,
                          npu_mif_cycle_outputs_t *outputs,
                          uint8_t write,
                          uint64_t vaddr,
                          uint8_t beats_minus_one,
                          uint16_t tag,
                          uint16_t task_id,
                          uint8_t attr)
{
    npu_mif_owner_inputs_t *dma =
        &inputs->owner[NPU_MIF_OWNER_DMA];

    dma->req_valid = 1u;
    dma->req_write = write;
    dma->req_vaddr = vaddr;
    dma->req_beats = beats_minus_one;
    dma->req_tag = tag;
    dma->req_owner = NPU_MIF_OWNER_DMA;
    dma->req_task_id = task_id;
    dma->req_attr = attr;
    npu_mif_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->owner[NPU_MIF_OWNER_DMA].req_ready != 0u);
    dma->req_valid = 0u;
    return 0;
}

static int mif_test_normal_read(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint8_t read_id;
    uint64_t held_addr;
    uint8_t held_len;
    uint8_t attr =
        NPU_MIF_ATTR_TBU_BYPASS |
        (2u << NPU_MIF_ATTR_CACHE_SHIFT) |
        NPU_MIF_ATTR_PRIVILEGED |
        NPU_MIF_ATTR_NONSECURE |
        (2u << NPU_MIF_ATTR_QOS_SHIFT);
    int line;

    mif_test_model_init(&model, &inputs);
    line = mif_submit_dma(&model, &inputs, &outputs, 0u,
                          UINT64_C(0x100), 1u,
                          0x12u, 0x21u, attr);
    if (line != 0) {
        return line;
    }

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].arvalid == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].araddr ==
               UINT64_C(0x100));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arlen == 1u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arsize == 3u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arburst == 1u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arlock == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arcache == 15u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arprot == 3u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arqos == 2u);
    held_addr = outputs.axi[NPU_MIF_AXI_DDR].araddr;
    held_len = outputs.axi[NPU_MIF_AXI_DDR].arlen;
    read_id = outputs.axi[NPU_MIF_AXI_DDR].arid;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].araddr == held_addr);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arlen == held_len);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arid == read_id);

    inputs.axi[NPU_MIF_AXI_DDR].arready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].arready = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].rid = read_id;
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0x1111222233334444);
    inputs.axi[NPU_MIF_AXI_DDR].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    TEST_CHECK(outputs.rd_outstanding == 1u);

    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0x5555666677778888);
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 1u;
    inputs.owner[NPU_MIF_OWNER_DMA].rsp_ready = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x1111222233334444));
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x12u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_last == 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    TEST_CHECK(model.r_entry[NPU_MIF_AXI_DDR].valid != 0u);

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x1111222233334444));
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x12u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_last == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready == 0u);

    inputs.owner[NPU_MIF_OWNER_DMA].rsp_ready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x1111222233334444));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready == 0u);
    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x5555666677778888));
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_last != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_is_write == 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_SUCCESS);

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.mif_idle != 0u);
    TEST_CHECK(outputs.rd_outstanding == 0u);
    return 0;
}

static int mif_test_normal_write(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    npu_mif_owner_inputs_t *dma;
    uint8_t write_id;
    uint64_t held_data;
    int line;

    mif_test_model_init(&model, &inputs);
    dma = &inputs.owner[NPU_MIF_OWNER_DMA];
    line = mif_submit_dma(
        &model, &inputs, &outputs, 1u,
        UINT64_C(0x200), 1u, 0x31u, 0x32u,
        NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awaddr ==
               UINT64_C(0x200));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awlen == 1u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awsize == 3u);
    write_id = outputs.axi[NPU_MIF_AXI_DDR].awid;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awid == write_id);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awaddr ==
               UINT64_C(0x200));

    inputs.axi[NPU_MIF_AXI_DDR].awready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    inputs.axi[NPU_MIF_AXI_DDR].awready = 0u;

    dma->wvalid = 1u;
    dma->wdata = UINT64_C(0x0102030405060708);
    dma->wstrb = 0x0fu;
    dma->wlast = 0u;
    dma->wtag = 0x31u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready != 0u);
    dma->wvalid = 0u;

    /* The owner beat is checked one stage before it enters AXI W hold. */
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid == 0u);

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wdata ==
               UINT64_C(0x0102030405060708));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wstrb == 0x0fu);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wlast == 0u);
    held_data = outputs.axi[NPU_MIF_AXI_DDR].wdata;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wdata == held_data);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wstrb == 0x0fu);

    inputs.axi[NPU_MIF_AXI_DDR].wready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    inputs.axi[NPU_MIF_AXI_DDR].wready = 0u;

    dma->wvalid = 1u;
    dma->wdata = UINT64_C(0x1112131415161718);
    dma->wstrb = 0xffu;
    dma->wlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready != 0u);
    dma->wvalid = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].wready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid == 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wdata ==
               UINT64_C(0x1112131415161718));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wlast != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].wready = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].bid = write_id;
    inputs.axi[NPU_MIF_AXI_DDR].bresp =
        NPU_MIF_AXI_RESP_OKAY;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].bready != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 0u;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_is_write != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_last != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x31u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_SUCCESS);

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.mif_idle != 0u);
    TEST_CHECK(outputs.wr_outstanding == 0u);
    return 0;
}

static int mif_test_dfu_ext_read(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    npu_mif_owner_inputs_t *dfu;
    uint8_t read_id;

    mif_test_model_init(&model, &inputs);
    dfu = &inputs.owner[NPU_MIF_OWNER_DFU];
    dfu->req_valid = 1u;
    dfu->req_write = 0u;
    dfu->req_vaddr = UINT64_C(0x80000);
    dfu->req_beats = 0u;
    dfu->req_tag = 0x35u;
    dfu->req_owner = NPU_MIF_OWNER_DFU;
    dfu->req_task_id = 0x36u;
    dfu->req_attr = NPU_MIF_ATTR_TBU_BYPASS;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u);
    dfu->req_valid = 0u;

    inputs.axi[NPU_MIF_AXI_EXT].arready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].araddr ==
               UINT64_C(0x80000));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].arlen == 0u);
    read_id = outputs.axi[NPU_MIF_AXI_EXT].arid;
    inputs.axi[NPU_MIF_AXI_EXT].arready = 0u;

    inputs.axi[NPU_MIF_AXI_EXT].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_EXT].rid = read_id;
    inputs.axi[NPU_MIF_AXI_EXT].rdata =
        UINT64_C(0x8877665544332211);
    inputs.axi[NPU_MIF_AXI_EXT].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    inputs.axi[NPU_MIF_AXI_EXT].rlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].rready != 0u);
    inputs.axi[NPU_MIF_AXI_EXT].rvalid = 0u;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_data ==
               UINT64_C(0x8877665544332211));
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_tag == 0x35u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_last != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_status ==
               NPU_STATUS_SUCCESS);
    return 0;
}

static int mif_test_cross_4k(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint16_t first_tbu_tag;
    uint8_t first_id;
    uint8_t second_id;
    int line;

    mif_test_model_init(&model, &inputs);
    line = mif_submit_dma(&model, &inputs, &outputs, 0u,
                          UINT64_C(0x0ff0), 3u,
                          0x42u, 0x43u, 0u);
    if (line != 0) {
        return line;
    }

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.req_valid != 0u);
    TEST_CHECK(outputs.tbu.req_vaddr == UINT64_C(0x0ff0));
    TEST_CHECK(outputs.tbu.req_write == 0u);
    TEST_CHECK(outputs.tbu.req_stream_id == 0x1234u);
    TEST_CHECK(outputs.tbu.req_substream_id == 0x5678u);
    TEST_CHECK((outputs.tbu.req_tag >> 12) ==
               NPU_MIF_OWNER_DMA);
    first_tbu_tag = outputs.tbu.req_tag;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.req_valid != 0u);
    TEST_CHECK(outputs.tbu.req_vaddr == UINT64_C(0x0ff0));
    TEST_CHECK(outputs.tbu.req_tag == first_tbu_tag);

    inputs.tbu.req_ready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    inputs.tbu.req_ready = 0u;

    inputs.tbu.rsp_valid = 1u;
    inputs.tbu.rsp_tag = first_tbu_tag;
    inputs.tbu.rsp_paddr = UINT64_C(0x2ff0);
    inputs.tbu.rsp_status = NPU_STATUS_SUCCESS;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.rsp_ready != 0u);
    inputs.tbu.rsp_valid = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].arready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].araddr ==
               UINT64_C(0x2ff0));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arlen == 1u);
    first_id = outputs.axi[NPU_MIF_AXI_DDR].arid;
    inputs.axi[NPU_MIF_AXI_DDR].arready = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].rid = first_id;
    inputs.axi[NPU_MIF_AXI_DDR].rdata = UINT64_C(0xa0);
    inputs.axi[NPU_MIF_AXI_DDR].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);

    inputs.axi[NPU_MIF_AXI_DDR].rdata = UINT64_C(0xa1);
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_last == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0xa1));
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_last == 0u);
    TEST_CHECK(outputs.tbu.req_valid != 0u);
    TEST_CHECK(outputs.tbu.req_vaddr == UINT64_C(0x1000));
    TEST_CHECK(outputs.tbu.req_tag == first_tbu_tag);

    inputs.tbu.req_ready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    inputs.tbu.req_ready = 0u;
    inputs.tbu.rsp_valid = 1u;
    inputs.tbu.rsp_tag = first_tbu_tag;
    inputs.tbu.rsp_paddr = UINT64_C(0x9000);
    inputs.tbu.rsp_status = NPU_STATUS_SUCCESS;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.rsp_ready != 0u);
    inputs.tbu.rsp_valid = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].arready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].araddr ==
               UINT64_C(0x9000));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arlen == 1u);
    second_id = outputs.axi[NPU_MIF_AXI_DDR].arid;
    TEST_CHECK(second_id != first_id);
    inputs.axi[NPU_MIF_AXI_DDR].arready = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].rid = second_id;
    inputs.axi[NPU_MIF_AXI_DDR].rdata = UINT64_C(0xb0);
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].rdata = UINT64_C(0xb1);
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_last == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0xb1));
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_last != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x42u);
    return 0;
}

static int mif_test_burst_limit(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint8_t first_id;
    uint8_t next_id = 0u;
    uint16_t beat;
    int line;

    mif_test_model_init(&model, &inputs);
    line = mif_submit_dma(
        &model, &inputs, &outputs, 0u,
        UINT64_C(0x4000), 16u, 0x51u, 0x52u,
        NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }

    inputs.axi[NPU_MIF_AXI_DDR].arready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arlen == 15u);
    first_id = outputs.axi[NPU_MIF_AXI_DDR].arid;
    inputs.axi[NPU_MIF_AXI_DDR].arready = 0u;

    for (beat = 0u; beat < 16u; beat++) {
        inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
        inputs.axi[NPU_MIF_AXI_DDR].rid = first_id;
        inputs.axi[NPU_MIF_AXI_DDR].rdata = beat;
        inputs.axi[NPU_MIF_AXI_DDR].rresp =
            NPU_MIF_AXI_RESP_OKAY;
        inputs.axi[NPU_MIF_AXI_DDR].rlast =
            beat == 15u ? 1u : 0u;
        npu_mif_cycle_step(&model, &inputs, &outputs);
        TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
        if (outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u) {
            TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_last ==
                       0u);
        }
    }
    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].arready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].araddr ==
               UINT64_C(0x4080));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arlen == 0u);
    next_id = outputs.axi[NPU_MIF_AXI_DDR].arid;
    TEST_CHECK(next_id != first_id);
    return 0;
}

static int mif_test_out_of_order_ids(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint8_t first_id;
    uint8_t second_id;
    int line;

    mif_test_model_init(&model, &inputs);
    line = mif_submit_dma(
        &model, &inputs, &outputs, 0u,
        UINT64_C(0x5000), 0u, 0x61u, 0x71u,
        NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }

    inputs.axi[NPU_MIF_AXI_DDR].arready = 1u;
    line = mif_submit_dma(
        &model, &inputs, &outputs, 0u,
        UINT64_C(0x6000), 0u, 0x62u, 0x72u,
        NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].araddr ==
               UINT64_C(0x5000));
    first_id = outputs.axi[NPU_MIF_AXI_DDR].arid;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].araddr ==
               UINT64_C(0x6000));
    second_id = outputs.axi[NPU_MIF_AXI_DDR].arid;
    TEST_CHECK(second_id != first_id);
    inputs.axi[NPU_MIF_AXI_DDR].arready = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].rid = second_id;
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0x2222222222222222);
    inputs.axi[NPU_MIF_AXI_DDR].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);

    inputs.axi[NPU_MIF_AXI_DDR].rid = first_id;
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0x1111111111111111);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x62u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x2222222222222222));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);

    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x61u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x1111111111111111));
    return 0;
}

static int mif_test_write_slverr(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    npu_mif_owner_inputs_t *dma;
    uint8_t write_id;
    int line;

    mif_test_model_init(&model, &inputs);
    dma = &inputs.owner[NPU_MIF_OWNER_DMA];
    line = mif_submit_dma(
        &model, &inputs, &outputs, 1u,
        UINT64_C(0x7000), 0u, 0x73u, 0x74u,
        NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }

    inputs.axi[NPU_MIF_AXI_DDR].awready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awvalid != 0u);
    write_id = outputs.axi[NPU_MIF_AXI_DDR].awid;
    inputs.axi[NPU_MIF_AXI_DDR].awready = 0u;

    dma->wvalid = 1u;
    dma->wdata = UINT64_C(0xdeadbeefcafef00d);
    dma->wstrb = 0xffu;
    dma->wlast = 1u;
    dma->wtag = 0x73u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready != 0u);
    dma->wvalid = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].wready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid == 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wlast != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].wready = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].bid = write_id;
    inputs.axi[NPU_MIF_AXI_DDR].bresp =
        NPU_MIF_AXI_RESP_SLVERR;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].bready != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 0u;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_is_write != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(outputs.first_error_valid != 0u);
    TEST_CHECK(outputs.first_error_status ==
               NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(outputs.first_error_owner == NPU_MIF_OWNER_DMA);
    TEST_CHECK(outputs.first_error_tag == 0x73u);
    TEST_CHECK(outputs.first_error_task_id == 0x74u);
    TEST_CHECK(outputs.first_error_vaddr == UINT64_C(0x7000));
    TEST_CHECK(outputs.first_error_paddr == UINT64_C(0x7000));
    TEST_CHECK(outputs.first_error_axi_id == write_id);
    TEST_CHECK(outputs.first_error_axi_resp ==
               NPU_MIF_AXI_RESP_SLVERR);
    return 0;
}

static int mif_test_request_ready_and_tag_errors(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint8_t index;
    uint8_t slot;

    mif_test_model_init(&model, &inputs);

    /*
     * With at least two free slots, both ready outputs stay asserted even
     * while valid is low and every payload field changes.
     */
    inputs.owner[NPU_MIF_OWNER_DFU].req_tag = 0xffffu;
    inputs.owner[NPU_MIF_OWNER_DFU].req_vaddr = UINT64_MAX;
    inputs.owner[NPU_MIF_OWNER_DMA].req_tag = 0x1000u;
    inputs.owner[NPU_MIF_OWNER_DMA].req_owner =
        NPU_MIF_OWNER_DFU;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);

    inputs.owner[NPU_MIF_OWNER_DFU].req_tag = 1u;
    inputs.owner[NPU_MIF_OWNER_DFU].req_vaddr = 0u;
    inputs.owner[NPU_MIF_OWNER_DMA].req_tag = 2u;
    inputs.owner[NPU_MIF_OWNER_DMA].req_owner =
        NPU_MIF_OWNER_DMA;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);

    /* Two asserted ready signals accept and allocate both handshakes. */
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DFU],
        NPU_MIF_OWNER_DFU, UINT64_C(0x1000),
        0x101u, 0x201u, 0u);
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DMA],
        NPU_MIF_OWNER_DMA, UINT64_C(0x2000),
        0x102u, 0x202u, 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);
    TEST_CHECK(mif_test_request_count(&model) == 2u);
    TEST_CHECK(mif_test_find_request(
                   &model, NPU_MIF_OWNER_DFU,
                   0x101u) != NPU_MIF_INVALID_SLOT);
    TEST_CHECK(mif_test_find_request(
                   &model, NPU_MIF_OWNER_DMA,
                   0x102u) != NPU_MIF_INVALID_SLOT);
    inputs.owner[NPU_MIF_OWNER_DFU].req_valid = 0u;

    /*
     * A duplicate tag is still handshaken. It creates a normal held error
     * response instead of using ready as a payload-dependent rejection.
     */
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DMA],
        NPU_MIF_OWNER_DMA, UINT64_C(0x2800),
        0x102u, 0x203u, 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_owner ==
               NPU_MIF_OWNER_DMA);
    TEST_CHECK(model.protocol_error_tag == 0x102u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_REQUEST_TAG_DUPLICATE);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0x2800));
    TEST_CHECK(model.protocol_error_has_task_identity != 0u);
    TEST_CHECK(model.protocol_error_task_id == 0x203u);
    inputs.owner[NPU_MIF_OWNER_DMA].req_valid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x102u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_last != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_BAD_DESC);

    /*
     * Exercise an illegal 13-bit owner tag in a fresh model so its raw tag
     * is observable in the sticky protocol-error report.
     */
    mif_test_model_init(&model, &inputs);
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DFU],
        NPU_MIF_OWNER_DFU, UINT64_C(0x3000),
        0x1000u, 0x204u, 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_owner ==
               NPU_MIF_OWNER_DFU);
    TEST_CHECK(model.protocol_error_tag == 0x1000u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_REQUEST_TAG_RANGE);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0x3000));
    TEST_CHECK(model.protocol_error_has_task_identity != 0u);
    TEST_CHECK(model.protocol_error_task_id == 0x204u);
    inputs.owner[NPU_MIF_OWNER_DFU].req_valid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_tag == 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_status ==
               NPU_STATUS_BAD_DESC);

    /*
     * With one free slot, arbitration is independent of valid. Owner 0 is
     * selected first. Although it is idle, the selection advances and lets
     * owner 1 handshake on the next cycle.
     */
    mif_test_model_init(&model, &inputs);
    for (index = 0u; index < NPU_MIF_MAX_REQUESTS - 1u;
         index++) {
        model.requests[index].valid = 1u;
        model.requests[index].phase = NPU_MIF_REQ_AXI;
        model.requests[index].owner =
            (uint8_t)(index % NPU_MIF_OWNER_COUNT);
        model.requests[index].tag = index;
    }
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DMA],
        NPU_MIF_OWNER_DMA, UINT64_C(0x4000),
        0x345u, 0x205u, 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready == 0u);
    TEST_CHECK(mif_test_request_count(&model) ==
               NPU_MIF_MAX_REQUESTS - 1u);

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready == 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);
    TEST_CHECK(mif_test_request_count(&model) ==
               NPU_MIF_MAX_REQUESTS);
    slot = mif_test_find_request(
        &model, NPU_MIF_OWNER_DMA, 0x345u);
    TEST_CHECK(slot != NPU_MIF_INVALID_SLOT);
    return 0;
}

static int mif_test_request_owner_protocol_error(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;

    mif_test_model_init(&model, &inputs);
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DMA],
        NPU_MIF_OWNER_DFU, UINT64_C(0x3800),
        0x222u, 0x345u, NPU_MIF_ATTR_TBU_BYPASS);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_REQUEST_OWNER);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0x3800));
    TEST_CHECK(model.protocol_error_owner ==
               NPU_MIF_OWNER_DMA);
    TEST_CHECK(model.protocol_error_tag == 0x222u);
    TEST_CHECK(model.protocol_error_has_task_identity != 0u);
    TEST_CHECK(model.protocol_error_task_id == 0x345u);

    inputs.owner[NPU_MIF_OWNER_DMA].req_valid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_BAD_DESC);
    return 0;
}

static int mif_test_tbu_response_ready_and_bad_tag(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint16_t correct_tag;
    uint8_t request_slot;
    int line;

    mif_test_model_init(&model, &inputs);
    line = mif_submit_dma(
        &model, &inputs, &outputs, 0u,
        UINT64_C(0x5000), 0u, 0x456u, 0x567u, 0u);
    if (line != 0) {
        return line;
    }

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.req_valid != 0u);
    correct_tag = outputs.tbu.req_tag;
    inputs.tbu.req_ready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    inputs.tbu.req_ready = 0u;
    TEST_CHECK(model.tbu_count == 1u);
    request_slot = mif_test_find_request(
        &model, NPU_MIF_OWNER_DMA, 0x456u);
    TEST_CHECK(request_slot != NPU_MIF_INVALID_SLOT);
    TEST_CHECK(model.requests[request_slot].phase ==
               NPU_MIF_REQ_TBU_WAIT);

    /* ready is high without valid and does not inspect the tag payload. */
    inputs.tbu.rsp_valid = 0u;
    inputs.tbu.rsp_tag = 0xffffu;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.rsp_ready != 0u);

    inputs.tbu.rsp_valid = 1u;
    inputs.tbu.rsp_tag = 0xfabcu;
    inputs.tbu.rsp_paddr = UINT64_MAX;
    inputs.tbu.rsp_status = NPU_STATUS_SUCCESS;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.rsp_ready != 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_owner == 0x03u);
    TEST_CHECK(model.protocol_error_tag == 0xabcu);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_TBU_TAG);
    TEST_CHECK(model.protocol_error_addr == 0u);
    TEST_CHECK(model.protocol_error_has_task_identity == 0u);
    TEST_CHECK(model.protocol_error_task_id == 0u);
    TEST_CHECK(model.tbu_count == 1u);
    TEST_CHECK(model.requests[request_slot].phase ==
               NPU_MIF_REQ_TBU_WAIT);

    /*
     * The invalid response did not consume the real transaction. Its valid
     * response is accepted afterward and proceeds to AXI.
     */
    inputs.tbu.rsp_tag = correct_tag;
    inputs.tbu.rsp_paddr = UINT64_C(0x5000);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.rsp_ready != 0u);
    TEST_CHECK(model.tbu_count == 0u);
    inputs.tbu.rsp_valid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].araddr ==
               UINT64_C(0x5000));

    /* An unknown return is also accepted with no translation outstanding. */
    mif_test_model_init(&model, &inputs);
    inputs.tbu.rsp_tag = 0xf123u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.rsp_ready != 0u);
    inputs.tbu.rsp_valid = 1u;
    inputs.tbu.rsp_paddr = UINT64_MAX;
    inputs.tbu.rsp_status = NPU_STATUS_SUCCESS;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.rsp_ready != 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_owner == 0x03u);
    TEST_CHECK(model.protocol_error_tag == 0x123u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_TBU_TAG);
    TEST_CHECK(model.protocol_error_addr == 0u);
    TEST_CHECK(model.protocol_error_has_task_identity == 0u);
    return 0;
}

static int mif_test_tbu_status_encodings(void)
{
    uint16_t status_value;

    for (status_value = 0u; status_value <= UINT8_MAX;
         status_value++) {
        npu_mif_cycle_t model;
        npu_mif_cycle_inputs_t inputs;
        npu_mif_cycle_outputs_t outputs;
        uint16_t tbu_tag;
        uint8_t request_slot;
        uint8_t status = (uint8_t)status_value;
        uint8_t legal =
            status <= NPU_STATUS_ADDR_OVERLAP ? 1u : 0u;
        uint8_t expected =
            legal != 0u ? status : NPU_STATUS_BAD_DESC;
        int line;

        mif_test_model_init(&model, &inputs);
        line = mif_submit_dma(
            &model, &inputs, &outputs, 0u,
            UINT64_C(0x7000), 0u, 0x4a5u, 0x5a6u, 0u);
        if (line != 0) {
            return line;
        }

        npu_mif_cycle_step(&model, &inputs, &outputs);
        TEST_CHECK(outputs.tbu.req_valid != 0u);
        tbu_tag = outputs.tbu.req_tag;
        inputs.tbu.req_ready = 1u;
        npu_mif_cycle_step(&model, &inputs, &outputs);
        inputs.tbu.req_ready = 0u;
        request_slot = mif_test_find_request(
            &model, NPU_MIF_OWNER_DMA, 0x4a5u);
        TEST_CHECK(request_slot != NPU_MIF_INVALID_SLOT);

        inputs.owner[NPU_MIF_OWNER_DMA].rsp_ready = 0u;
        inputs.tbu.rsp_valid = 1u;
        inputs.tbu.rsp_tag = tbu_tag;
        inputs.tbu.rsp_paddr = UINT64_C(0x7000);
        inputs.tbu.rsp_status = status;
        npu_mif_cycle_step(&model, &inputs, &outputs);
        TEST_CHECK(outputs.tbu.rsp_ready != 0u);
        TEST_CHECK(model.tbu_count == 0u);
        TEST_CHECK(model.requests[request_slot].status == expected);
        TEST_CHECK(model.protocol_error_valid ==
                   (uint8_t)(legal == 0u));
        if (legal == 0u) {
            TEST_CHECK(model.protocol_error_kind ==
                       NPU_MIF_PROTOCOL_TBU_STATUS);
            TEST_CHECK(model.protocol_error_addr ==
                       UINT64_C(0x7000));
            TEST_CHECK(model.protocol_error_owner ==
                       NPU_MIF_OWNER_DMA);
            TEST_CHECK(model.protocol_error_tag == 0x4a5u);
            TEST_CHECK(
                model.protocol_error_has_task_identity != 0u);
            TEST_CHECK(model.protocol_error_task_id == 0x5a6u);
        }

        inputs.tbu.rsp_valid = 0u;
        if (status == NPU_STATUS_SUCCESS) {
            TEST_CHECK(model.first_error_valid == 0u);
        } else {
            npu_mif_cycle_step(&model, &inputs, &outputs);
            TEST_CHECK(
                outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
            TEST_CHECK(
                outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
                expected);
            TEST_CHECK(outputs.first_error_valid != 0u);
            TEST_CHECK(outputs.first_error_status == expected);
            TEST_CHECK(
                outputs.protocol_error_valid ==
                (uint8_t)(legal == 0u));
        }
    }
    return 0;
}

static void mif_test_drive_dynamic_config(
    npu_mif_cycle_inputs_t *inputs)
{
    inputs->config_valid = 1u;
    inputs->ddr_enable = 0u;
    inputs->ddr_base = UINT64_C(0x010000);
    inputs->ddr_limit = UINT64_C(0x01fff8);
    inputs->ext_enable = 1u;
    inputs->ext_base = UINT64_C(0x020000);
    inputs->ext_limit = UINT64_C(0x02fff8);
    inputs->bypass_enable = 1u;
    inputs->bypass_base = UINT64_C(0x020000);
    inputs->bypass_limit = UINT64_C(0x02fff8);
    inputs->tbu_stream_id = 0xabcdu;
    inputs->tbu_substream_id = 0xef01u;
}

static int mif_test_config_validation(void)
{
    npu_mif_cycle_config_t config;
    npu_mif_cycle_config_t invalid;
    npu_mif_cycle_t model;
    npu_mif_cycle_t preserved;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;

    npu_mif_cycle_config_default(&config);
    TEST_CHECK(npu_mif_cycle_config_valid(&config) != 0u);
    TEST_CHECK((config.ddr_limit & UINT64_C(7)) == 0u);
    TEST_CHECK(npu_mif_cycle_config_valid(NULL) == 0u);
    TEST_CHECK(npu_mif_cycle_init(&model, NULL) == 0);
    TEST_CHECK(npu_mif_cycle_config_valid(&model.config) != 0u);

    (void)memset(&model, 0xa5, sizeof(model));
    preserved = model;
    invalid = config;
    invalid.ddr_enable = 2u;
    TEST_CHECK(npu_mif_cycle_config_valid(&invalid) == 0u);
    TEST_CHECK(npu_mif_cycle_init(&model, &invalid) == -1);
    TEST_CHECK(memcmp(&model, &preserved, sizeof(model)) == 0);

    invalid = config;
    invalid.ext_enable = 2u;
    TEST_CHECK(npu_mif_cycle_config_valid(&invalid) == 0u);
    invalid = config;
    invalid.bypass_enable = 2u;
    TEST_CHECK(npu_mif_cycle_config_valid(&invalid) == 0u);

    invalid = config;
    invalid.ddr_base = NPU_MIF_PA_MASK + UINT64_C(1);
    TEST_CHECK(npu_mif_cycle_config_valid(&invalid) == 0u);
    invalid = config;
    invalid.ddr_base = UINT64_C(1);
    TEST_CHECK(npu_mif_cycle_config_valid(&invalid) == 0u);
    invalid = config;
    invalid.ddr_base = UINT64_C(0x1000);
    invalid.ddr_limit = UINT64_C(0x0ff8);
    TEST_CHECK(npu_mif_cycle_config_valid(&invalid) == 0u);

    invalid = config;
    invalid.ext_enable = 1u;
    invalid.ext_base = UINT64_C(0x1000);
    invalid.ext_limit = UINT64_C(0x1ff8);
    invalid.ddr_limit = UINT64_C(0x1000);
    TEST_CHECK(npu_mif_cycle_config_valid(&invalid) == 0u);
    invalid.ddr_limit = UINT64_C(0x0ff8);
    TEST_CHECK(npu_mif_cycle_config_valid(&invalid) != 0u);

    invalid = config;
    invalid.bypass_enable = 1u;
    invalid.bypass_base = UINT64_C(0x2000);
    invalid.bypass_limit = UINT64_C(0x1ff8);
    TEST_CHECK(npu_mif_cycle_config_valid(&invalid) == 0u);

    invalid = config;
    invalid.axi_cache_device = 0x10u;
    TEST_CHECK(npu_mif_cycle_config_valid(&invalid) == 0u);
    invalid = config;
    invalid.axi_cache_normal_noncache = 0x10u;
    TEST_CHECK(npu_mif_cycle_config_valid(&invalid) == 0u);
    invalid = config;
    invalid.axi_cache_normal_cacheable = 0x10u;
    TEST_CHECK(npu_mif_cycle_config_valid(&invalid) == 0u);

    /*
     * A malformed dynamic update is rejected as one complete configuration.
     * Existing state is retained and no owner request can sample the bad
     * values in that cycle.
     */
    mif_test_model_init(&model, &inputs);
    config = model.config;
    mif_test_drive_dynamic_config(&inputs);
    inputs.ddr_enable = 2u;
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DFU],
        NPU_MIF_OWNER_DFU, UINT64_C(0x2000),
        0x5f0u, 0x6f0u, 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready == 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready == 0u);
    TEST_CHECK(memcmp(&model.config, &config, sizeof(config)) == 0);
    TEST_CHECK(mif_test_request_count(&model) == 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_CONFIG);
    TEST_CHECK(model.protocol_error_owner ==
               NPU_MIF_INVALID_OWNER);
    TEST_CHECK(model.protocol_error_has_task_identity == 0u);

    inputs.config_valid = 0u;
    inputs.owner[NPU_MIF_OWNER_DFU].req_valid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_MIF_PROTOCOL_CONFIG);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);
    return 0;
}

static int mif_test_dynamic_config_snapshot_and_reset(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint16_t old_tbu_tag;
    uint16_t new_tbu_tag;
    uint8_t index;
    int line;

    mif_test_model_init(&model, &inputs);

    /* Request A samples the init configuration and waits for translation. */
    line = mif_submit_dma(
        &model, &inputs, &outputs, 0u,
        UINT64_C(0x3000), 0u, 0x601u, 0x701u, 0u);
    if (line != 0) {
        return line;
    }
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.req_valid != 0u);
    TEST_CHECK(outputs.tbu.req_stream_id == 0x1234u);
    TEST_CHECK(outputs.tbu.req_substream_id == 0x5678u);
    old_tbu_tag = outputs.tbu.req_tag;
    inputs.tbu.req_ready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    inputs.tbu.req_ready = 0u;

    /*
     * Request B handshakes in the same cycle as config_valid. It must sample
     * the input configuration, while A retains the init configuration.
     */
    mif_test_drive_dynamic_config(&inputs);
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DFU],
        NPU_MIF_OWNER_DFU, UINT64_C(0x20000),
        0x602u, 0x702u, 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u);
    TEST_CHECK(model.config.ddr_enable == 0u);
    TEST_CHECK(model.config.ddr_base == UINT64_C(0x010000));
    TEST_CHECK(model.config.ddr_limit == UINT64_C(0x01fff8));
    TEST_CHECK(model.config.ext_enable != 0u);
    TEST_CHECK(model.config.ext_base == UINT64_C(0x020000));
    TEST_CHECK(model.config.ext_limit == UINT64_C(0x02fff8));
    TEST_CHECK(model.config.bypass_enable != 0u);
    TEST_CHECK(model.config.bypass_base == UINT64_C(0x020000));
    TEST_CHECK(model.config.bypass_limit == UINT64_C(0x02fff8));
    TEST_CHECK(model.config.tbu_stream_id == 0xabcdu);
    TEST_CHECK(model.config.tbu_substream_id == 0xef01u);
    inputs.config_valid = 0u;
    inputs.owner[NPU_MIF_OWNER_DFU].req_valid = 0u;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.req_valid != 0u);
    TEST_CHECK(outputs.tbu.req_stream_id == 0xabcdu);
    TEST_CHECK(outputs.tbu.req_substream_id == 0xef01u);
    new_tbu_tag = outputs.tbu.req_tag;

    /* A completes under its old DDR region snapshot. */
    inputs.tbu.rsp_valid = 1u;
    inputs.tbu.rsp_tag = old_tbu_tag;
    inputs.tbu.rsp_paddr = UINT64_C(0x3000);
    inputs.tbu.rsp_status = NPU_STATUS_SUCCESS;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.rsp_ready != 0u);
    inputs.tbu.rsp_valid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].araddr ==
               UINT64_C(0x3000));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].arvalid == 0u);

    /* B's TBU request and physical region both use the new snapshot. */
    inputs.tbu.req_ready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.req_valid != 0u);
    TEST_CHECK(outputs.tbu.req_tag == new_tbu_tag);
    inputs.tbu.req_ready = 0u;
    inputs.tbu.rsp_valid = 1u;
    inputs.tbu.rsp_tag = new_tbu_tag;
    inputs.tbu.rsp_paddr = UINT64_C(0x20000);
    inputs.tbu.rsp_status = NPU_STATUS_SUCCESS;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.rsp_ready != 0u);
    inputs.tbu.rsp_valid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].araddr ==
               UINT64_C(0x20000));

    /*
     * Clear both held AXI addresses, then accept bypass request C with
     * config_valid low. The retained bypass and EXT ranges select EXT.
     */
    inputs.axi[NPU_MIF_AXI_DDR].arready = 1u;
    inputs.axi[NPU_MIF_AXI_EXT].arready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    inputs.axi[NPU_MIF_AXI_DDR].arready = 0u;
    inputs.axi[NPU_MIF_AXI_EXT].arready = 0u;
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DMA],
        NPU_MIF_OWNER_DMA, UINT64_C(0x20008),
        0x603u, 0x703u, NPU_MIF_ATTR_TBU_BYPASS);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);
    inputs.owner[NPU_MIF_OWNER_DMA].req_valid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].araddr ==
               UINT64_C(0x20008));

    /*
     * reset_n clears every transaction and ready/valid hold. The retained
     * configuration survives just as the init configuration did before any
     * dynamic update; config_valid is ignored while reset is asserted.
     */
    mif_test_drive_dynamic_config(&inputs);
    inputs.ddr_enable = 1u;
    inputs.ddr_base = 0u;
    inputs.ddr_limit = UINT64_MAX;
    inputs.reset_n = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.mif_idle != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready == 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready == 0u);
    TEST_CHECK(outputs.tbu.req_valid == 0u);
    TEST_CHECK(outputs.tbu.rsp_ready == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].arvalid == 0u);
    TEST_CHECK(model.cycle_count == 0u);
    TEST_CHECK(model.config.ddr_enable == 0u);
    TEST_CHECK(model.config.ext_base == UINT64_C(0x020000));
    for (index = 0u; index < NPU_MIF_MAX_REQUESTS; index++) {
        TEST_CHECK(model.requests[index].valid == 0u);
    }

    mif_test_inputs_init(&inputs);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.mif_idle != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);
    TEST_CHECK(outputs.tbu.rsp_ready != 0u);
    TEST_CHECK(outputs.cycle_count == 0u);
    return 0;
}

static int mif_test_start_dma_read(
    npu_mif_cycle_t *model,
    npu_mif_cycle_inputs_t *inputs,
    npu_mif_cycle_outputs_t *outputs,
    uint64_t address,
    uint8_t beats_minus_one,
    uint16_t tag,
    uint8_t port,
    uint8_t *axi_id)
{
    int line = mif_submit_dma(
        model, inputs, outputs, 0u, address,
        beats_minus_one, tag, (uint16_t)(tag + 0x100u),
        NPU_MIF_ATTR_TBU_BYPASS);

    if (line != 0) {
        return line;
    }
    inputs->axi[port].arready = 1u;
    npu_mif_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->axi[port].arvalid != 0u);
    *axi_id = outputs->axi[port].arid;
    inputs->axi[port].arready = 0u;
    return 0;
}

static int mif_test_limit_names_final_beat(void)
{
    npu_mif_cycle_config_t config;
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint8_t axi_id;
    int line;

    npu_mif_cycle_config_default(&config);
    config.ddr_base = UINT64_C(0x1000);
    config.ddr_limit = UINT64_C(0x1000);
    config.ext_enable = 0u;
    config.bypass_enable = 1u;
    config.bypass_base = UINT64_C(0x1000);
    config.bypass_limit = UINT64_C(0x1000);
    TEST_CHECK(npu_mif_cycle_config_valid(&config) != 0u);
    TEST_CHECK(npu_mif_cycle_init(&model, &config) == 0);
    mif_test_inputs_init(&inputs);

    line = mif_test_start_dma_read(
        &model, &inputs, &outputs, UINT64_C(0x1000),
        0u, 0x60au, NPU_MIF_AXI_DDR, &axi_id);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].araddr ==
               UINT64_C(0x1000));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arlen == 0u);
    TEST_CHECK(axi_id != NPU_MIF_INVALID_AXI_ID);
    return 0;
}

static int mif_test_gva_last_beat_range(void)
{
    const uint64_t max_aligned_gva =
        NPU_MIF_GVA_MASK & ~UINT64_C(7);
    const uint64_t max_aligned_pa =
        NPU_MIF_PA_MASK & ~UINT64_C(7);
    npu_mif_cycle_config_t config;
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;

    /*
     * A translated one-beat request may start at the highest aligned
     * 48-bit GVA. A bypass request may start at the highest aligned 40-bit
     * PA. Exercise both owners and both translation modes together.
     */
    npu_mif_cycle_config_default(&config);
    config.bypass_enable = 1u;
    config.bypass_base = 0u;
    config.bypass_limit = max_aligned_pa;
    TEST_CHECK(npu_mif_cycle_init(&model, &config) == 0);
    mif_test_inputs_init(&inputs);
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DFU],
        NPU_MIF_OWNER_DFU, max_aligned_gva,
        0x60bu, 0x70bu, 0u);
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DMA],
        NPU_MIF_OWNER_DMA, max_aligned_pa,
        0x60cu, 0x70cu, NPU_MIF_ATTR_TBU_BYPASS);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);
    inputs.owner[NPU_MIF_OWNER_DFU].req_valid = 0u;
    inputs.owner[NPU_MIF_OWNER_DMA].req_valid = 0u;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.tbu.req_valid != 0u);
    TEST_CHECK(outputs.tbu.req_vaddr == max_aligned_gva);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].araddr ==
               max_aligned_pa);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arlen == 0u);
    TEST_CHECK(outputs.first_error_valid == 0u);
    TEST_CHECK(outputs.protocol_error_valid == 0u);

    /*
     * Two beats starting at the same address would place the second beat
     * above the 48-bit GVA range. Reject both requests before either a TBU
     * request or an AXI address can be emitted.
     */
    TEST_CHECK(npu_mif_cycle_init(&model, &config) == 0);
    mif_test_inputs_init(&inputs);
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DFU],
        NPU_MIF_OWNER_DFU, max_aligned_gva,
        0x60du, 0x70du, 0u);
    inputs.owner[NPU_MIF_OWNER_DFU].req_beats = 1u;
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DMA],
        NPU_MIF_OWNER_DMA, max_aligned_gva,
        0x60eu, 0x70eu, NPU_MIF_ATTR_TBU_BYPASS);
    inputs.owner[NPU_MIF_OWNER_DMA].req_beats = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].req_ready != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].req_ready != 0u);
    TEST_CHECK(model.first_error_valid != 0u);
    TEST_CHECK(model.first_error_status == NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(model.first_error_owner == NPU_MIF_OWNER_DFU);
    TEST_CHECK(model.first_error_vaddr == max_aligned_gva);
    TEST_CHECK(model.tbu_hold.valid == 0u);
    TEST_CHECK(model.ar_hold[NPU_MIF_AXI_DDR] ==
               NPU_MIF_INVALID_SLOT);
    TEST_CHECK(model.ar_hold[NPU_MIF_AXI_EXT] ==
               NPU_MIF_INVALID_SLOT);
    inputs.owner[NPU_MIF_OWNER_DFU].req_valid = 0u;
    inputs.owner[NPU_MIF_OWNER_DMA].req_valid = 0u;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_status ==
               NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DFU].rsp_tag == 0x60du);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x60eu);
    TEST_CHECK(outputs.tbu.req_valid == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awvalid == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].arvalid == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].awvalid == 0u);
    TEST_CHECK(outputs.axi_slots_used == 0u);
    TEST_CHECK(outputs.first_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_valid == 0u);
    return 0;
}

static int mif_test_axi_ingress_illegal_then_recovery(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint8_t read_id;
    uint8_t invalid_id;
    int line;

    mif_test_model_init(&model, &inputs);

    /*
     * Empty ingress entries advertise capacity without inspecting valid, ID,
     * or any other response payload field.
     */
    inputs.axi[NPU_MIF_AXI_DDR].bid = 0xfeu;
    inputs.axi[NPU_MIF_AXI_DDR].rid = 0xfdu;
    inputs.axi[NPU_MIF_AXI_EXT].bid = 0xfcu;
    inputs.axi[NPU_MIF_AXI_EXT].rid = 0xfbu;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].bready != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].bready != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].rready != 0u);

    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].bresp =
        NPU_MIF_AXI_RESP_OKAY;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].bready != 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_owner ==
               NPU_MIF_INVALID_OWNER);
    TEST_CHECK(model.protocol_error_tag == 0xfeu);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_AXI_BID);
    TEST_CHECK(model.protocol_error_addr == 0u);
    TEST_CHECK(model.protocol_error_has_task_identity == 0u);
    TEST_CHECK(npu_mif_cycle_is_idle(&model) != 0u);

    mif_test_model_init(&model, &inputs);
    line = mif_test_start_dma_read(
        &model, &inputs, &outputs, UINT64_C(0x1100),
        0u, 0x710u, NPU_MIF_AXI_DDR, &read_id);
    if (line != 0) {
        return line;
    }
    inputs.axi[NPU_MIF_AXI_EXT].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_EXT].rid = read_id;
    inputs.axi[NPU_MIF_AXI_EXT].rdata =
        UINT64_C(0x1010101010101010);
    inputs.axi[NPU_MIF_AXI_EXT].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    inputs.axi[NPU_MIF_AXI_EXT].rlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].rready != 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_AXI_RID);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0x1100));
    TEST_CHECK(model.protocol_error_owner ==
               NPU_MIF_OWNER_DMA);
    TEST_CHECK(model.protocol_error_tag == 0x710u);
    TEST_CHECK(model.protocol_error_has_task_identity != 0u);
    TEST_CHECK(model.protocol_error_task_id == 0x810u);

    mif_test_model_init(&model, &inputs);
    line = mif_test_start_dma_read(
        &model, &inputs, &outputs, UINT64_C(0x1200),
        0u, 0x711u, NPU_MIF_AXI_DDR, &read_id);
    if (line != 0) {
        return line;
    }

    /* B using an active read ID is consumed but leaves the read intact. */
    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].bid = read_id;
    inputs.axi[NPU_MIF_AXI_DDR].bresp =
        NPU_MIF_AXI_RESP_OKAY;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].bready != 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_owner ==
               NPU_MIF_OWNER_DMA);
    TEST_CHECK(model.protocol_error_tag == 0x711u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_AXI_BID);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0x1200));
    TEST_CHECK(model.protocol_error_has_task_identity != 0u);
    TEST_CHECK(model.protocol_error_task_id == 0x811u);
    TEST_CHECK(outputs.rd_outstanding == 1u);
    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 0u;

    /* An unmatched read ID also handshakes and cannot release the real ID. */
    invalid_id = (uint8_t)(read_id + 0x80u);
    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].rid = invalid_id;
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0xdead000000000001);
    inputs.axi[NPU_MIF_AXI_DDR].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    TEST_CHECK(outputs.rd_outstanding == 1u);
    TEST_CHECK(model.r_entry[NPU_MIF_AXI_DDR].valid == 0u);

    /* The valid response after malformed traffic still completes normally. */
    inputs.owner[NPU_MIF_OWNER_DMA].rsp_ready = 0u;
    inputs.axi[NPU_MIF_AXI_DDR].rid = read_id;
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0x123456789abcdef0);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    TEST_CHECK(outputs.rd_outstanding == 1u);

    /*
     * A duplicate response after the real AXI entry was retired is accepted
     * and discarded. It must not replace the held owner response.
     */
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0xbad0bad0bad0bad0);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x123456789abcdef0));
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);

    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;
    inputs.owner[NPU_MIF_OWNER_DMA].rsp_ready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x123456789abcdef0));
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.mif_idle != 0u);
    return 0;
}

static int mif_test_premature_responses_keep_transaction(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    npu_mif_owner_inputs_t *dma;
    uint8_t read_id;
    uint8_t write_id;
    int line;

    /*
     * R before AR handshake is malformed. The AR entry remains active and a
     * later response after AR completion succeeds.
     */
    mif_test_model_init(&model, &inputs);
    line = mif_submit_dma(
        &model, &inputs, &outputs, 0u, UINT64_C(0x1800),
        0u, 0x721u, 0x821u, NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    read_id = outputs.axi[NPU_MIF_AXI_DDR].arid;

    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].rid = read_id;
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0xaaaaaaaaaaaaaaaa);
    inputs.axi[NPU_MIF_AXI_DDR].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.ar_hold[NPU_MIF_AXI_DDR] !=
               NPU_MIF_INVALID_SLOT);

    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;
    inputs.axi[NPU_MIF_AXI_DDR].arready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].arready = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0x1111222233334444);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x1111222233334444));
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_SUCCESS);

    /*
     * B before AW handshake follows the same rule. Once AW and the final W
     * beat complete, the subsequent legal B finishes with SUCCESS.
     */
    mif_test_model_init(&model, &inputs);
    dma = &inputs.owner[NPU_MIF_OWNER_DMA];
    line = mif_submit_dma(
        &model, &inputs, &outputs, 1u, UINT64_C(0x2000),
        0u, 0x722u, 0x822u, NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awvalid != 0u);
    write_id = outputs.axi[NPU_MIF_AXI_DDR].awid;

    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].bid = write_id;
    inputs.axi[NPU_MIF_AXI_DDR].bresp =
        NPU_MIF_AXI_RESP_OKAY;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].bready != 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.aw_hold[NPU_MIF_AXI_DDR] !=
               NPU_MIF_INVALID_SLOT);
    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].awready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awvalid != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].awready = 0u;

    /* R using the active write ID is also discarded without retiring it. */
    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].rid = write_id;
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0x9999999999999999);
    inputs.axi[NPU_MIF_AXI_DDR].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    TEST_CHECK(outputs.wr_outstanding == 1u);
    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;

    dma->wvalid = 1u;
    dma->wdata = UINT64_C(0x5555666677778888);
    dma->wstrb = 0xffu;
    dma->wlast = 1u;
    dma->wtag = 0x722u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready != 0u);
    dma->wvalid = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].wready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid == 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].wready = 0u;

    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].bready != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_SUCCESS);
    return 0;
}

static int mif_test_b_before_write_data_is_terminal(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint8_t write_id;
    int line;

    mif_test_model_init(&model, &inputs);
    line = mif_submit_dma(
        &model, &inputs, &outputs, 1u, UINT64_C(0x2800),
        1u, 0x731u, 0x831u, NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }
    inputs.axi[NPU_MIF_AXI_DDR].awready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awvalid != 0u);
    write_id = outputs.axi[NPU_MIF_AXI_DDR].awid;
    inputs.axi[NPU_MIF_AXI_DDR].awready = 0u;
    TEST_CHECK(model.write_fifo_count == 1u);

    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].bid = write_id;
    inputs.axi[NPU_MIF_AXI_DDR].bresp =
        NPU_MIF_AXI_RESP_OKAY;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].bready != 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_owner ==
               NPU_MIF_OWNER_DMA);
    TEST_CHECK(model.protocol_error_tag == 0x731u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_AXI_EARLY_B);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0x2800));
    TEST_CHECK(model.protocol_error_has_task_identity != 0u);
    TEST_CHECK(model.protocol_error_task_id == 0x831u);
    TEST_CHECK(model.write_fifo_count == 0u);
    TEST_CHECK(outputs.wr_outstanding == 1u);
    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 0u;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_is_write !=
               0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(outputs.first_error_valid != 0u);
    TEST_CHECK(outputs.first_error_axi_id == write_id);
    TEST_CHECK(outputs.first_error_axi_resp ==
               NPU_MIF_AXI_RESP_OKAY);
    TEST_CHECK(outputs.wr_outstanding == 0u);
    return 0;
}

static int mif_test_write_ready_and_input_buffer(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_t valid_model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_inputs_t valid_inputs;
    npu_mif_cycle_outputs_t outputs;
    npu_mif_cycle_outputs_t valid_outputs;
    npu_mif_owner_inputs_t *dma;
    npu_mif_owner_inputs_t *valid_dma;
    int line;

    mif_test_model_init(&model, &inputs);
    line = mif_submit_dma(
        &model, &inputs, &outputs, 1u, UINT64_C(0x4000),
        2u, 0x511u, 0x611u, NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }
    inputs.axi[NPU_MIF_AXI_DDR].awready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awvalid != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].awready = 0u;

    /*
     * Start from identical receiver state. Changing only owner WVALID and
     * its payload, including a bad tag, must not change WREADY.
     */
    valid_model = model;
    valid_inputs = inputs;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    valid_dma = &valid_inputs.owner[NPU_MIF_OWNER_DMA];
    valid_dma->wvalid = 1u;
    valid_dma->wdata = UINT64_C(0xf1f2f3f4f5f6f7f8);
    valid_dma->wstrb = 0x3cu;
    valid_dma->wlast = 0u;
    valid_dma->wtag = 0x5feu;
    npu_mif_cycle_step(
        &valid_model, &valid_inputs, &valid_outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready != 0u);
    TEST_CHECK(valid_outputs.owner[NPU_MIF_OWNER_DMA].wready ==
               outputs.owner[NPU_MIF_OWNER_DMA].wready);
    TEST_CHECK(model.w_input.valid == 0u);
    TEST_CHECK(valid_model.w_input.valid != 0u);
    TEST_CHECK(valid_model.w_input.data ==
               UINT64_C(0xf1f2f3f4f5f6f7f8));
    TEST_CHECK(valid_model.w_input.strb == 0x3cu);
    TEST_CHECK(valid_model.w_input.tag == 0x5feu);

    /*
     * The bad tag is checked after capture. It occupies and blocks the
     * buffer, cannot enter AXI W hold, and applies backpressure.
     */
    valid_dma->wvalid = 0u;
    valid_inputs.axi[NPU_MIF_AXI_DDR].wready = 1u;
    npu_mif_cycle_step(
        &valid_model, &valid_inputs, &valid_outputs);
    TEST_CHECK(valid_outputs.owner[NPU_MIF_OWNER_DMA].wready ==
               0u);
    TEST_CHECK(valid_outputs.axi[NPU_MIF_AXI_DDR].wvalid == 0u);
    TEST_CHECK(valid_model.w_input.valid != 0u);
    TEST_CHECK(valid_model.w_input.blocked != 0u);
    TEST_CHECK(valid_model.w_hold.valid == 0u);
    TEST_CHECK(valid_model.protocol_error_valid != 0u);
    TEST_CHECK(valid_model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_WRITE_TAG);
    TEST_CHECK(valid_model.protocol_error_tag == 0x5feu);
    TEST_CHECK(
        valid_model.requests[
            valid_model.axi_entries[
                valid_model.w_input.out_slot].req_slot]
            .write_beats_accepted == 0u);
    TEST_CHECK(
        valid_model.axi_entries[
            valid_model.w_input.out_slot].beats_done == 0u);
    npu_mif_cycle_step(
        &valid_model, &valid_inputs, &valid_outputs);
    TEST_CHECK(valid_outputs.owner[NPU_MIF_OWNER_DMA].wready ==
               0u);
    TEST_CHECK(valid_outputs.axi[NPU_MIF_AXI_DDR].wvalid == 0u);
    TEST_CHECK(valid_outputs.protocol_error_valid != 0u);
    TEST_CHECK(valid_outputs.protocol_error_kind ==
               NPU_MIF_PROTOCOL_WRITE_TAG);

    /*
     * A correct first beat advances into W hold on the next stage. While W
     * hold is stalled, the input buffer accepts one more beat and then keeps
     * that beat unchanged while deasserting owner WREADY.
     */
    dma = &inputs.owner[NPU_MIF_OWNER_DMA];
    dma->wvalid = 1u;
    dma->wdata = UINT64_C(0x0102030405060708);
    dma->wstrb = 0xffu;
    dma->wlast = 0u;
    dma->wtag = 0x511u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready != 0u);
    TEST_CHECK(model.w_input.valid != 0u);

    dma->wvalid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid == 0u);
    TEST_CHECK(model.w_input.valid == 0u);
    TEST_CHECK(model.w_hold.valid != 0u);

    dma->wvalid = 1u;
    dma->wdata = UINT64_C(0x1112131415161718);
    dma->wstrb = 0x0fu;
    dma->wlast = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wdata ==
               UINT64_C(0x0102030405060708));
    TEST_CHECK(model.w_input.valid != 0u);

    dma->wdata = UINT64_C(0x2122232425262728);
    dma->wstrb = 0xf0u;
    dma->wlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wdata ==
               UINT64_C(0x0102030405060708));
    TEST_CHECK(model.w_input.data ==
               UINT64_C(0x1112131415161718));
    TEST_CHECK(model.w_input.strb == 0x0fu);
    TEST_CHECK(model.w_input.last == 0u);

    inputs.reset_n = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.mif_idle != 0u);
    TEST_CHECK(model.w_input.valid == 0u);
    TEST_CHECK(model.w_hold.valid == 0u);
    return 0;
}

static int mif_test_write_data_protocol_errors(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    npu_mif_owner_inputs_t *dma;
    int line;

    mif_test_model_init(&model, &inputs);
    dma = &inputs.owner[NPU_MIF_OWNER_DMA];
    line = mif_submit_dma(
        &model, &inputs, &outputs, 1u, UINT64_C(0x4400),
        0u, 0x512u, 0x612u, NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }
    inputs.axi[NPU_MIF_AXI_DDR].awready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awvalid != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].awready = 0u;

    dma->wvalid = 1u;
    dma->wdata = UINT64_C(0x0102030405060708);
    dma->wstrb = 0xffu;
    dma->wlast = 0u;
    dma->wtag = 0x512u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready != 0u);
    TEST_CHECK(model.protocol_error_valid == 0u);
    dma->wvalid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_WRITE_LAST);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0x4400));
    TEST_CHECK(model.protocol_error_owner ==
               NPU_MIF_OWNER_DMA);
    TEST_CHECK(model.protocol_error_tag == 0x512u);
    TEST_CHECK(model.protocol_error_has_task_identity != 0u);
    TEST_CHECK(model.protocol_error_task_id == 0x612u);

    mif_test_model_init(&model, &inputs);
    dma = &inputs.owner[NPU_MIF_OWNER_DMA];
    line = mif_submit_dma(
        &model, &inputs, &outputs, 1u, UINT64_C(0x4800),
        0u, 0x513u, 0x613u, NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }
    inputs.axi[NPU_MIF_AXI_DDR].awready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].awvalid != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].awready = 0u;

    dma->wvalid = 1u;
    dma->wdata = UINT64_C(0x1112131415161718);
    dma->wstrb = 0xffu;
    dma->wlast = 1u;
    dma->wtag = 0x5ffu;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready != 0u);
    TEST_CHECK(model.protocol_error_valid == 0u);
    dma->wvalid = 0u;
    inputs.axi[NPU_MIF_AXI_DDR].wready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid == 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_WRITE_TAG);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0x4800));
    TEST_CHECK(model.protocol_error_owner ==
               NPU_MIF_OWNER_DMA);
    TEST_CHECK(model.protocol_error_tag == 0x5ffu);
    TEST_CHECK(model.protocol_error_has_task_identity != 0u);
    TEST_CHECK(model.protocol_error_task_id == 0x613u);
    TEST_CHECK(model.w_input.valid != 0u);
    TEST_CHECK(model.w_input.blocked != 0u);
    TEST_CHECK(model.w_hold.valid == 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].wready == 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].wvalid == 0u);
    return 0;
}

static int mif_test_rlast_protocol_errors(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint8_t read_id;
    int line;

    /* Early RLAST ends the request with BUS_SLVERR. */
    mif_test_model_init(&model, &inputs);
    line = mif_test_start_dma_read(
        &model, &inputs, &outputs, UINT64_C(0x3000),
        1u, 0x741u, NPU_MIF_AXI_DDR, &read_id);
    if (line != 0) {
        return line;
    }
    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].rid = read_id;
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0x1000000000000001);
    inputs.axi[NPU_MIF_AXI_DDR].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_last != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_MIF_PROTOCOL_AXI_RLAST);
    TEST_CHECK(outputs.protocol_error_addr == UINT64_C(0x3000));
    TEST_CHECK(outputs.protocol_error_owner ==
               NPU_MIF_OWNER_DMA);
    TEST_CHECK(outputs.protocol_error_tag == 0x741u);
    TEST_CHECK(outputs.protocol_error_has_task_identity != 0u);
    TEST_CHECK(outputs.protocol_error_task_id == 0x841u);

    /* Missing RLAST on the expected final beat has the same terminal result. */
    mif_test_model_init(&model, &inputs);
    line = mif_test_start_dma_read(
        &model, &inputs, &outputs, UINT64_C(0x3800),
        0u, 0x742u, NPU_MIF_AXI_DDR, &read_id);
    if (line != 0) {
        return line;
    }
    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].rid = read_id;
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0x2000000000000001);
    inputs.axi[NPU_MIF_AXI_DDR].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);

    inputs.owner[NPU_MIF_OWNER_DMA].rsp_ready = 0u;
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0x2000000000000002);
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x2000000000000001));
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
               NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);

    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0x2000000000000001));
    return 0;
}

static int mif_test_two_ports_same_owner_r_arbitration(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint8_t ddr_id;
    uint8_t ext_id;
    uint64_t held_ext_data;
    int line;

    mif_test_model_init(&model, &inputs);
    line = mif_submit_dma(
        &model, &inputs, &outputs, 0u, UINT64_C(0x4000),
        0u, 0x751u, 0x851u, NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }
    line = mif_submit_dma(
        &model, &inputs, &outputs, 0u, UINT64_C(0x80000),
        0u, 0x752u, 0x852u, NPU_MIF_ATTR_TBU_BYPASS);
    if (line != 0) {
        return line;
    }

    inputs.axi[NPU_MIF_AXI_DDR].arready = 1u;
    inputs.axi[NPU_MIF_AXI_EXT].arready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].arvalid != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].arvalid != 0u);
    ddr_id = outputs.axi[NPU_MIF_AXI_DDR].arid;
    ext_id = outputs.axi[NPU_MIF_AXI_EXT].arid;
    inputs.axi[NPU_MIF_AXI_DDR].arready = 0u;
    inputs.axi[NPU_MIF_AXI_EXT].arready = 0u;

    inputs.owner[NPU_MIF_OWNER_DMA].rsp_ready = 0u;
    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_DDR].rid = ddr_id;
    inputs.axi[NPU_MIF_AXI_DDR].rdata =
        UINT64_C(0xdddddddddddddddd);
    inputs.axi[NPU_MIF_AXI_DDR].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    inputs.axi[NPU_MIF_AXI_DDR].rlast = 1u;
    inputs.axi[NPU_MIF_AXI_EXT].rvalid = 1u;
    inputs.axi[NPU_MIF_AXI_EXT].rid = ext_id;
    inputs.axi[NPU_MIF_AXI_EXT].rdata =
        UINT64_C(0xeeeeeeeeeeeeeeee);
    inputs.axi[NPU_MIF_AXI_EXT].rresp =
        NPU_MIF_AXI_RESP_OKAY;
    inputs.axi[NPU_MIF_AXI_EXT].rlast = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].rready != 0u);
    TEST_CHECK(model.r_entry[NPU_MIF_AXI_DDR].valid == 0u);
    TEST_CHECK(model.r_entry[NPU_MIF_AXI_EXT].valid != 0u);
    held_ext_data =
        model.r_entry[NPU_MIF_AXI_EXT].data;

    inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;
    inputs.axi[NPU_MIF_AXI_EXT].rdata =
        UINT64_C(0xffffffffffffffff);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x751u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0xdddddddddddddddd));
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].rready == 0u);
    TEST_CHECK(model.r_entry[NPU_MIF_AXI_EXT].data ==
               held_ext_data);

    inputs.axi[NPU_MIF_AXI_EXT].rvalid = 0u;
    inputs.owner[NPU_MIF_OWNER_DMA].rsp_ready = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x751u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].rready == 0u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x752u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
               UINT64_C(0xeeeeeeeeeeeeeeee));
    return 0;
}

static int mif_test_two_ports_same_owner_b_completion(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint8_t port;

    mif_test_model_init(&model, &inputs);
    for (port = 0u; port < NPU_MIF_AXI_PORT_COUNT; port++) {
        npu_mif_request_entry_t *request =
            &model.requests[port];
        npu_mif_axi_entry_t *entry =
            &model.axi_entries[port];

        request->valid = 1u;
        request->phase = NPU_MIF_REQ_AXI;
        request->owner = NPU_MIF_OWNER_DMA;
        request->write = 1u;
        request->tag = (uint16_t)(0x753u + port);
        request->task_id = (uint16_t)(0x853u + port);
        request->status = NPU_STATUS_SUCCESS;
        request->total_beats = 1u;
        request->remaining_beats = 1u;
        request->page_beats = 1u;

        entry->valid = 1u;
        entry->addr_sent = 1u;
        entry->write = 1u;
        entry->port = port;
        entry->axi_id = (uint8_t)(0x30u + port);
        entry->req_slot = port;
        entry->w_done = 1u;
        entry->beats = 1u;
        entry->beats_done = 1u;
        entry->vaddr =
            UINT64_C(0x6000) + (uint64_t)port * 8u;
        entry->paddr = entry->vaddr;

        inputs.axi[port].bvalid = 1u;
        inputs.axi[port].bid = entry->axi_id;
        inputs.axi[port].bresp = NPU_MIF_AXI_RESP_OKAY;
    }

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].bready != 0u);
    TEST_CHECK(outputs.axi[NPU_MIF_AXI_EXT].bready != 0u);
    TEST_CHECK(model.rsp_hold[NPU_MIF_OWNER_DMA].valid != 0u);
    TEST_CHECK(model.requests[0].phase ==
               NPU_MIF_REQ_RESPONSE_HELD);
    TEST_CHECK(model.requests[1].phase ==
               NPU_MIF_REQ_RESPONSE_PENDING);
    inputs.axi[NPU_MIF_AXI_DDR].bvalid = 0u;
    inputs.axi[NPU_MIF_AXI_EXT].bvalid = 0u;

    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x753u);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
    TEST_CHECK(outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag == 0x754u);
    return 0;
}

static int mif_test_read_response_statuses(void)
{
    static const uint8_t axi_response[] = {
        NPU_MIF_AXI_RESP_EXOKAY,
        NPU_MIF_AXI_RESP_SLVERR,
        NPU_MIF_AXI_RESP_DECERR,
        0xffu
    };
    static const uint8_t expected_status[] = {
        NPU_STATUS_BUS_SLVERR,
        NPU_STATUS_BUS_SLVERR,
        NPU_STATUS_BUS_DECERR,
        NPU_STATUS_BUS_SLVERR
    };
    uint8_t index;

    for (index = 0u;
         index < (uint8_t)(sizeof(axi_response) /
                           sizeof(axi_response[0]));
         index++) {
        npu_mif_cycle_t model;
        npu_mif_cycle_inputs_t inputs;
        npu_mif_cycle_outputs_t outputs;
        uint8_t read_id;
        int line;

        mif_test_model_init(&model, &inputs);
        line = mif_test_start_dma_read(
            &model, &inputs, &outputs,
            UINT64_C(0x6800) + (uint64_t)index * 8u,
            0u, (uint16_t)(0x755u + index),
            NPU_MIF_AXI_DDR, &read_id);
        if (line != 0) {
            return line;
        }

        inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
        inputs.axi[NPU_MIF_AXI_DDR].rid = read_id;
        inputs.axi[NPU_MIF_AXI_DDR].rdata =
            UINT64_C(0x7000000000000000) + index;
        inputs.axi[NPU_MIF_AXI_DDR].rresp =
            axi_response[index];
        inputs.axi[NPU_MIF_AXI_DDR].rlast = 1u;
        npu_mif_cycle_step(&model, &inputs, &outputs);
        TEST_CHECK(outputs.axi[NPU_MIF_AXI_DDR].rready != 0u);
        inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;

        npu_mif_cycle_step(&model, &inputs, &outputs);
        TEST_CHECK(
            outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u);
        TEST_CHECK(
            outputs.owner[NPU_MIF_OWNER_DMA].rsp_status ==
            expected_status[index]);
        TEST_CHECK(outputs.first_error_valid != 0u);
        TEST_CHECK(outputs.first_error_status ==
                   expected_status[index]);
        TEST_CHECK(outputs.first_error_axi_resp ==
                   axi_response[index]);
        TEST_CHECK(
            outputs.protocol_error_valid ==
            (uint8_t)(axi_response[index] >
                      NPU_MIF_AXI_RESP_DECERR));
        if (axi_response[index] > NPU_MIF_AXI_RESP_DECERR) {
            TEST_CHECK(outputs.protocol_error_kind ==
                       NPU_MIF_PROTOCOL_AXI_RRESP);
            TEST_CHECK(
                outputs.protocol_error_addr ==
                UINT64_C(0x6800) + (uint64_t)index * 8u);
            TEST_CHECK(outputs.protocol_error_owner ==
                       NPU_MIF_OWNER_DMA);
            TEST_CHECK(
                outputs.protocol_error_tag ==
                (uint16_t)(0x755u + index));
            TEST_CHECK(
                outputs.protocol_error_has_task_identity != 0u);
            TEST_CHECK(
                outputs.protocol_error_task_id ==
                (uint16_t)(0x855u + index));
        }
    }
    return 0;
}

static uint32_t mif_test_next_random(uint32_t *state)
{
    uint32_t value = *state;

    value ^= value << 13;
    value ^= value >> 17;
    value ^= value << 5;
    *state = value;
    return value;
}

static int mif_test_random_read_backpressure(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;
    uint8_t read_id;
    uint16_t axi_beat = 0u;
    uint16_t owner_beat = 0u;
    uint16_t cycle;
    uint32_t random_state = UINT32_C(0x13579bdf);
    int line;

    mif_test_model_init(&model, &inputs);
    line = mif_test_start_dma_read(
        &model, &inputs, &outputs, UINT64_C(0x5000),
        15u, 0x761u, NPU_MIF_AXI_DDR, &read_id);
    if (line != 0) {
        return line;
    }

    for (cycle = 0u; cycle < 512u; cycle++) {
        uint32_t random_value =
            mif_test_next_random(&random_state);
        uint8_t owner_ready =
            (uint8_t)((random_value >> 3) & 1u);

        inputs.owner[NPU_MIF_OWNER_DMA].rsp_ready =
            owner_ready;
        if (axi_beat < 16u) {
            inputs.axi[NPU_MIF_AXI_DDR].rvalid = 1u;
            inputs.axi[NPU_MIF_AXI_DDR].rid = read_id;
            inputs.axi[NPU_MIF_AXI_DDR].rdata =
                UINT64_C(0x6000000000000000) + axi_beat;
            inputs.axi[NPU_MIF_AXI_DDR].rresp =
                NPU_MIF_AXI_RESP_OKAY;
            inputs.axi[NPU_MIF_AXI_DDR].rlast =
                axi_beat == 15u ? 1u : 0u;
        } else {
            inputs.axi[NPU_MIF_AXI_DDR].rvalid = 0u;
        }

        npu_mif_cycle_step(&model, &inputs, &outputs);

        if (outputs.owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u) {
            TEST_CHECK(owner_beat < 16u);
            TEST_CHECK(
                outputs.owner[NPU_MIF_OWNER_DMA].rsp_data ==
                UINT64_C(0x6000000000000000) + owner_beat);
            TEST_CHECK(
                outputs.owner[NPU_MIF_OWNER_DMA].rsp_tag ==
                0x761u);
            TEST_CHECK(
                outputs.owner[NPU_MIF_OWNER_DMA].rsp_last ==
                (uint8_t)(owner_beat == 15u));
            if (owner_ready != 0u) {
                owner_beat++;
            }
        }
        if (inputs.axi[NPU_MIF_AXI_DDR].rvalid != 0u &&
            outputs.axi[NPU_MIF_AXI_DDR].rready != 0u) {
            axi_beat++;
        }

        if (axi_beat == 16u && owner_beat == 16u &&
            npu_mif_cycle_is_idle(&model) != 0u) {
            break;
        }
    }

    TEST_CHECK(cycle < 512u);
    TEST_CHECK(axi_beat == 16u);
    TEST_CHECK(owner_beat == 16u);
    TEST_CHECK(model.protocol_error_valid == 0u);
    return 0;
}

static int mif_test_diagnostic_clear_and_axi_id_valid(void)
{
    npu_mif_cycle_t model;
    npu_mif_cycle_inputs_t inputs;
    npu_mif_cycle_outputs_t outputs;

    mif_test_model_init(&model, &inputs);
    model.first_error_valid = 1u;
    model.first_error_status = NPU_STATUS_BUS_SLVERR;
    model.first_error_axi_id = 0xffu;
    model.first_error_axi_id_valid = 1u;
    model.protocol_error_valid = 1u;
    model.protocol_error_kind = NPU_MIF_PROTOCOL_AXI_RID;
    model.protocol_error_addr = UINT64_C(0xabcdef00);
    model.protocol_error_owner = NPU_MIF_OWNER_DMA;
    model.protocol_error_tag = 0x055u;
    model.protocol_error_has_task_identity = 1u;
    model.protocol_error_task_id = 0x456u;

    inputs.error_clear = 1u;
    mif_test_set_read_request(
        &inputs.owner[NPU_MIF_OWNER_DFU],
        NPU_MIF_OWNER_DFU, UINT64_C(0x1000),
        0x1000u, 0x123u, NPU_MIF_ATTR_TBU_BYPASS);
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.first_error_valid != 0u);
    TEST_CHECK(outputs.first_error_axi_id_valid != 0u);
    TEST_CHECK(outputs.first_error_axi_id == 0xffu);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_MIF_PROTOCOL_AXI_RID);
    TEST_CHECK(outputs.protocol_error_addr ==
               UINT64_C(0xabcdef00));
    TEST_CHECK(outputs.protocol_error_owner ==
               NPU_MIF_OWNER_DMA);
    TEST_CHECK(outputs.protocol_error_tag == 0x055u);
    TEST_CHECK(outputs.protocol_error_has_task_identity != 0u);
    TEST_CHECK(outputs.protocol_error_task_id == 0x456u);
    TEST_CHECK(model.first_error_valid != 0u);
    TEST_CHECK(model.first_error_status == NPU_STATUS_BAD_DESC);
    TEST_CHECK(model.first_error_tag == 0u);
    TEST_CHECK(model.first_error_axi_id_valid == 0u);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_owner == NPU_MIF_OWNER_DFU);
    TEST_CHECK(model.protocol_error_tag == 0x1000u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_REQUEST_TAG_RANGE);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0x1000));
    TEST_CHECK(model.protocol_error_has_task_identity != 0u);
    TEST_CHECK(model.protocol_error_task_id == 0x123u);

    inputs.error_clear = 0u;
    inputs.owner[NPU_MIF_OWNER_DFU].req_valid = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.first_error_status == NPU_STATUS_BAD_DESC);
    TEST_CHECK(outputs.first_error_axi_id_valid == 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_MIF_PROTOCOL_REQUEST_TAG_RANGE);
    TEST_CHECK(outputs.protocol_error_addr == UINT64_C(0x1000));
    TEST_CHECK(outputs.protocol_error_owner == NPU_MIF_OWNER_DFU);
    TEST_CHECK(outputs.protocol_error_tag == 0x1000u);
    TEST_CHECK(outputs.protocol_error_has_task_identity != 0u);
    TEST_CHECK(outputs.protocol_error_task_id == 0x123u);

    inputs.tbu.rsp_valid = 1u;
    inputs.tbu.rsp_tag = 0xfaaau;
    inputs.tbu.rsp_status = NPU_STATUS_SUCCESS;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_MIF_PROTOCOL_REQUEST_TAG_RANGE);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0x1000));
    TEST_CHECK(model.protocol_error_owner == NPU_MIF_OWNER_DFU);
    TEST_CHECK(model.protocol_error_tag == 0x1000u);
    TEST_CHECK(model.protocol_error_has_task_identity != 0u);
    TEST_CHECK(model.protocol_error_task_id == 0x123u);
    inputs.tbu.rsp_valid = 0u;

    inputs.error_clear = 1u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    inputs.error_clear = 0u;
    npu_mif_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.first_error_valid == 0u);
    TEST_CHECK(outputs.protocol_error_valid == 0u);
    TEST_CHECK(outputs.first_error_axi_id_valid == 0u);
    return 0;
}

int test_mif_cycle(void)
{
    int line;

    line = mif_test_normal_read();
    if (line != 0) {
        return line;
    }
    line = mif_test_normal_write();
    if (line != 0) {
        return line;
    }
    line = mif_test_dfu_ext_read();
    if (line != 0) {
        return line;
    }
    line = mif_test_cross_4k();
    if (line != 0) {
        return line;
    }
    line = mif_test_burst_limit();
    if (line != 0) {
        return line;
    }
    line = mif_test_out_of_order_ids();
    if (line != 0) {
        return line;
    }
    line = mif_test_write_slverr();
    if (line != 0) {
        return line;
    }
    line = mif_test_request_ready_and_tag_errors();
    if (line != 0) {
        return line;
    }
    line = mif_test_request_owner_protocol_error();
    if (line != 0) {
        return line;
    }
    line = mif_test_tbu_response_ready_and_bad_tag();
    if (line != 0) {
        return line;
    }
    line = mif_test_tbu_status_encodings();
    if (line != 0) {
        return line;
    }
    line = mif_test_config_validation();
    if (line != 0) {
        return line;
    }
    line = mif_test_dynamic_config_snapshot_and_reset();
    if (line != 0) {
        return line;
    }
    line = mif_test_limit_names_final_beat();
    if (line != 0) {
        return line;
    }
    line = mif_test_gva_last_beat_range();
    if (line != 0) {
        return line;
    }
    line = mif_test_axi_ingress_illegal_then_recovery();
    if (line != 0) {
        return line;
    }
    line = mif_test_premature_responses_keep_transaction();
    if (line != 0) {
        return line;
    }
    line = mif_test_b_before_write_data_is_terminal();
    if (line != 0) {
        return line;
    }
    line = mif_test_write_ready_and_input_buffer();
    if (line != 0) {
        return line;
    }
    line = mif_test_write_data_protocol_errors();
    if (line != 0) {
        return line;
    }
    line = mif_test_rlast_protocol_errors();
    if (line != 0) {
        return line;
    }
    line = mif_test_two_ports_same_owner_r_arbitration();
    if (line != 0) {
        return line;
    }
    line = mif_test_two_ports_same_owner_b_completion();
    if (line != 0) {
        return line;
    }
    line = mif_test_read_response_statuses();
    if (line != 0) {
        return line;
    }
    line = mif_test_random_read_backpressure();
    if (line != 0) {
        return line;
    }
    line = mif_test_diagnostic_clear_and_axi_id_valid();
    if (line != 0) {
        return line;
    }
    return 0;
}

#ifdef NPU_MIF_CYCLE_STANDALONE
int main(void)
{
    int line = test_mif_cycle();

    if (line == 0) {
        (void)printf("[PASS] mif_cycle\n");
        return 0;
    }
    (void)printf("[FAIL] mif_cycle at test line %d\n", line);
    return 1;
}
#endif
