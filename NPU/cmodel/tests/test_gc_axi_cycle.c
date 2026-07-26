#include "npu_gc_axi_cycle.h"
#include "test_util.h"

#include <string.h>

#ifdef NPU_GC_AXI_CYCLE_STANDALONE
#include <stdio.h>
#endif

int test_gc_axi_cycle(void);

static void gc_test_inputs_init(
    npu_gc_axi_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = 1u;
}

static void gc_test_init(npu_gc_axi_cycle_t *model,
                         npu_gc_axi_cycle_inputs_t *inputs)
{
    npu_gc_axi_cycle_init(model);
    gc_test_inputs_init(inputs);
}

static int gc_submit_read(
    npu_gc_axi_cycle_t *model,
    npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs,
    uint8_t client,
    uint64_t addr,
    uint8_t beats_minus_one,
    uint16_t tag,
    uint8_t cache,
    uint8_t prot,
    uint8_t qos)
{
    npu_gc_axi_read_req_t *request =
        client == NPU_GC_AXI_CLIENT_ICACHE
            ? &inputs->icache_req
            : &inputs->dcache_read_req;

    request->valid = 1u;
    request->addr = addr;
    request->beats = beats_minus_one;
    request->tag = tag;
    request->cache = cache;
    request->prot = prot;
    request->qos = qos;
    npu_gc_axi_cycle_step(model, inputs, outputs);
    if (client == NPU_GC_AXI_CLIENT_ICACHE) {
        TEST_CHECK(outputs->icache_req_ready != 0u);
    } else {
        TEST_CHECK(outputs->dcache_read_req_ready != 0u);
    }
    request->valid = 0u;
    return 0;
}

static int gc_submit_write(
    npu_gc_axi_cycle_t *model,
    npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs,
    uint64_t addr,
    uint8_t beats_minus_one,
    uint16_t tag,
    uint8_t cache,
    uint8_t prot,
    uint8_t qos)
{
    inputs->dcache_write_req.valid = 1u;
    inputs->dcache_write_req.addr = addr;
    inputs->dcache_write_req.beats = beats_minus_one;
    inputs->dcache_write_req.tag = tag;
    inputs->dcache_write_req.cache = cache;
    inputs->dcache_write_req.prot = prot;
    inputs->dcache_write_req.qos = qos;
    npu_gc_axi_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->dcache_write_req_ready != 0u);
    inputs->dcache_write_req.valid = 0u;
    return 0;
}

static int gc_take_ar(
    npu_gc_axi_cycle_t *model,
    npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs,
    uint64_t expected_addr,
    uint8_t expected_len,
    uint8_t *id)
{
    inputs->axi.arready = 1u;
    npu_gc_axi_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->axi.arvalid != 0u);
    TEST_CHECK(outputs->axi.araddr == expected_addr);
    TEST_CHECK(outputs->axi.arlen == expected_len);
    TEST_CHECK(outputs->axi.arsize == 3u);
    TEST_CHECK(outputs->axi.arburst == 1u);
    TEST_CHECK(outputs->axi.arlock == 0u);
    *id = outputs->axi.arid;
    inputs->axi.arready = 0u;
    return 0;
}

static int gc_take_aw(
    npu_gc_axi_cycle_t *model,
    npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs,
    uint64_t expected_addr,
    uint8_t expected_len,
    uint8_t *id)
{
    inputs->axi.awready = 1u;
    npu_gc_axi_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->axi.awvalid != 0u);
    TEST_CHECK(outputs->axi.awaddr == expected_addr);
    TEST_CHECK(outputs->axi.awlen == expected_len);
    TEST_CHECK(outputs->axi.awsize == 3u);
    TEST_CHECK(outputs->axi.awburst == 1u);
    TEST_CHECK(outputs->axi.awlock == 0u);
    *id = outputs->axi.awid;
    inputs->axi.awready = 0u;
    return 0;
}

static int gc_send_r(
    npu_gc_axi_cycle_t *model,
    npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs,
    uint8_t id,
    uint64_t data,
    uint8_t response,
    uint8_t last)
{
    inputs->axi.rvalid = 1u;
    inputs->axi.rid = id;
    inputs->axi.rdata = data;
    inputs->axi.rresp = response;
    inputs->axi.rlast = last;
    npu_gc_axi_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->axi.rready != 0u);
    inputs->axi.rvalid = 0u;
    return 0;
}

static int gc_check_read_response(
    npu_gc_axi_cycle_t *model,
    npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs,
    uint8_t client,
    uint64_t data,
    uint16_t tag,
    uint8_t last,
    uint8_t status)
{
    const npu_gc_axi_read_rsp_t *response;

    npu_gc_axi_cycle_step(model, inputs, outputs);
    response =
        client == NPU_GC_AXI_CLIENT_ICACHE
            ? &outputs->icache_rsp
            : &outputs->dcache_read_rsp;
    TEST_CHECK(response->valid != 0u);
    TEST_CHECK(response->data == data);
    TEST_CHECK(response->tag == tag);
    TEST_CHECK(response->last == last);
    TEST_CHECK(response->status == status);

    if (client == NPU_GC_AXI_CLIENT_ICACHE) {
        inputs->icache_rsp_ready = 1u;
    } else {
        inputs->dcache_read_rsp_ready = 1u;
    }
    npu_gc_axi_cycle_step(model, inputs, outputs);
    response =
        client == NPU_GC_AXI_CLIENT_ICACHE
            ? &outputs->icache_rsp
            : &outputs->dcache_read_rsp;
    TEST_CHECK(response->valid != 0u);
    TEST_CHECK(response->data == data);
    TEST_CHECK(response->tag == tag);
    TEST_CHECK(response->last == last);
    TEST_CHECK(response->status == status);
    inputs->icache_rsp_ready = 0u;
    inputs->dcache_read_rsp_ready = 0u;
    return 0;
}

static int gc_accept_write_data(
    npu_gc_axi_cycle_t *model,
    npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs,
    uint64_t data,
    uint8_t strb,
    uint8_t last,
    uint16_t tag)
{
    uint8_t slot =
        model->write_order_count == 0u
            ? NPU_GC_AXI_INVALID_SLOT
            : model->write_order[model->write_order_head];
    uint16_t expected_tag =
        slot < NPU_GC_AXI_WRITE_OUTSTANDING
            ? model->write[slot].tag
            : 0u;

    inputs->dcache_write_data.valid = 1u;
    inputs->dcache_write_data.data = data;
    inputs->dcache_write_data.strb = strb;
    inputs->dcache_write_data.last = last;
    inputs->dcache_write_data.tag = tag;
    npu_gc_axi_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->dcache_write_data_ready != 0u);
    TEST_CHECK(outputs->dcache_write_data_tag == expected_tag);
    inputs->dcache_write_data.valid = 0u;
    return 0;
}

static int gc_take_w(
    npu_gc_axi_cycle_t *model,
    npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs,
    uint64_t data,
    uint8_t strb,
    uint8_t last)
{
    inputs->axi.wready = 1u;
    npu_gc_axi_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->axi.wvalid != 0u);
    TEST_CHECK(outputs->axi.wdata == data);
    TEST_CHECK(outputs->axi.wstrb == strb);
    TEST_CHECK(outputs->axi.wlast == last);
    inputs->axi.wready = 0u;
    return 0;
}

static int gc_send_b(
    npu_gc_axi_cycle_t *model,
    npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs,
    uint8_t id,
    uint8_t response)
{
    inputs->axi.bvalid = 1u;
    inputs->axi.bid = id;
    inputs->axi.bresp = response;
    npu_gc_axi_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->axi.bready != 0u);
    inputs->axi.bvalid = 0u;
    return 0;
}

static int gc_check_write_response(
    npu_gc_axi_cycle_t *model,
    npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs,
    uint16_t tag,
    uint8_t status)
{
    npu_gc_axi_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->dcache_write_rsp.valid != 0u);
    TEST_CHECK(outputs->dcache_write_rsp.tag == tag);
    TEST_CHECK(outputs->dcache_write_rsp.status == status);
    inputs->dcache_write_rsp_ready = 1u;
    npu_gc_axi_cycle_step(model, inputs, outputs);
    TEST_CHECK(outputs->dcache_write_rsp.valid != 0u);
    TEST_CHECK(outputs->dcache_write_rsp.tag == tag);
    TEST_CHECK(outputs->dcache_write_rsp.status == status);
    inputs->dcache_write_rsp_ready = 0u;
    return 0;
}

static int gc_test_reset_idle_and_quiesce(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t read_id;
    int line;

    gc_test_init(&model, &inputs);
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.idle != 0u);
    TEST_CHECK(outputs.quiescent != 0u);
    TEST_CHECK(outputs.icache_req_ready != 0u);
    TEST_CHECK(outputs.dcache_read_req_ready != 0u);
    TEST_CHECK(outputs.dcache_write_req_ready != 0u);
    TEST_CHECK(outputs.axi.rready != 0u);
    TEST_CHECK(outputs.axi.bready != 0u);

    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0x100), 0u, 0x10u,
        2u, 5u, 0u);
    if (line != 0) {
        return line;
    }
    inputs.quiesce = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.icache_req_ready == 0u);
    TEST_CHECK(outputs.dcache_read_req_ready == 0u);
    TEST_CHECK(outputs.dcache_write_req_ready == 0u);
    TEST_CHECK(outputs.axi.arvalid != 0u);
    read_id = outputs.axi.arid;
    TEST_CHECK(outputs.axi.araddr == UINT64_C(0x100));

    inputs.axi.arready = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    inputs.axi.arready = 0u;
    line = gc_send_r(
        &model, &inputs, &outputs, read_id,
        UINT64_C(0x1122334455667788),
        NPU_GC_AXI_RESP_OKAY, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_check_read_response(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0x1122334455667788),
        0x10u, 1u, NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.idle != 0u);

    inputs.quiesce = 0u;
    line = gc_submit_write(
        &model, &inputs, &outputs,
        UINT64_C(0x200), 0u, 0x20u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    inputs.reset_n = 0u;
    inputs.axi.bvalid = 1u;
    inputs.axi.rvalid = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.idle != 0u);
    TEST_CHECK(outputs.quiescent != 0u);
    TEST_CHECK(outputs.axi.awvalid == 0u);
    TEST_CHECK(outputs.axi.arvalid == 0u);
    TEST_CHECK(outputs.axi.wvalid == 0u);
    TEST_CHECK(outputs.axi.bready == 0u);
    TEST_CHECK(outputs.axi.rready == 0u);
    TEST_CHECK(model.cycle_count == 0u);

    gc_test_inputs_init(&inputs);
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.idle != 0u);
    TEST_CHECK(outputs.axi.bready != 0u);
    TEST_CHECK(outputs.axi.rready != 0u);
    return 0;
}

static int gc_test_read_stalls_and_ingress(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t read_id;
    uint64_t held_addr;
    uint8_t held_len;
    int line;

    gc_test_init(&model, &inputs);
    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0x380), 1u, 0x31u,
        0xau, 5u, 0u);
    if (line != 0) {
        return line;
    }

    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.arvalid != 0u);
    TEST_CHECK(outputs.axi.arcache == 0xau);
    TEST_CHECK(outputs.axi.arprot == 5u);
    TEST_CHECK(outputs.axi.arqos == 0u);
    held_addr = outputs.axi.araddr;
    held_len = outputs.axi.arlen;
    read_id = outputs.axi.arid;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.arvalid != 0u);
    TEST_CHECK(outputs.axi.araddr == held_addr);
    TEST_CHECK(outputs.axi.arlen == held_len);
    TEST_CHECK(outputs.axi.arid == read_id);

    inputs.axi.arready = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    inputs.axi.arready = 0u;

    line = gc_send_r(
        &model, &inputs, &outputs, read_id,
        UINT64_C(0x0102030405060708),
        NPU_GC_AXI_RESP_OKAY, 0u);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.icache_rsp.valid != 0u);
    TEST_CHECK(outputs.icache_rsp.data ==
               UINT64_C(0x0102030405060708));
    TEST_CHECK(outputs.icache_rsp.last == 0u);

    inputs.axi.rvalid = 1u;
    inputs.axi.rid = read_id;
    inputs.axi.rdata = UINT64_C(0x1112131415161718);
    inputs.axi.rresp = NPU_GC_AXI_RESP_OKAY;
    inputs.axi.rlast = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.icache_rsp.valid != 0u);
    TEST_CHECK(outputs.axi.rready != 0u);
    TEST_CHECK(model.r_entry.valid != 0u);

    inputs.axi.rvalid = 0u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.icache_rsp.valid != 0u);
    TEST_CHECK(outputs.icache_rsp.data ==
               UINT64_C(0x0102030405060708));
    TEST_CHECK(outputs.axi.rready == 0u);

    inputs.icache_rsp_ready = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.icache_rsp.valid != 0u);
    TEST_CHECK(outputs.axi.rready == 0u);
    inputs.icache_rsp_ready = 0u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.icache_rsp.valid != 0u);
    TEST_CHECK(outputs.icache_rsp.data ==
               UINT64_C(0x1112131415161718));
    TEST_CHECK(outputs.icache_rsp.last != 0u);
    TEST_CHECK(outputs.icache_rsp.status ==
               NPU_STATUS_SUCCESS);
    inputs.icache_rsp_ready = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    inputs.icache_rsp_ready = 0u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.idle != 0u);
    return 0;
}

static int gc_test_concurrent_out_of_order_reads(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t first_id;
    uint8_t second_id;
    uint8_t icache_id = NPU_GC_AXI_INVALID_SLOT;
    uint8_t dcache_id = NPU_GC_AXI_INVALID_SLOT;

    gc_test_init(&model, &inputs);
    inputs.icache_req.valid = 1u;
    inputs.icache_req.addr = UINT64_C(0x1000);
    inputs.icache_req.tag = 0x41u;
    inputs.icache_req.prot = 4u;
    inputs.dcache_read_req.valid = 1u;
    inputs.dcache_read_req.addr = UINT64_C(0x2000);
    inputs.dcache_read_req.tag = 0x42u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.icache_req_ready != 0u);
    TEST_CHECK(outputs.dcache_read_req_ready != 0u);
    inputs.icache_req.valid = 0u;
    inputs.dcache_read_req.valid = 0u;

    inputs.axi.arready = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.arvalid != 0u);
    first_id = outputs.axi.arid;
    if (outputs.axi.araddr == UINT64_C(0x1000)) {
        icache_id = first_id;
    } else {
        TEST_CHECK(outputs.axi.araddr == UINT64_C(0x2000));
        dcache_id = first_id;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.arvalid != 0u);
    second_id = outputs.axi.arid;
    TEST_CHECK(second_id != first_id);
    if (outputs.axi.araddr == UINT64_C(0x1000)) {
        icache_id = second_id;
    } else {
        TEST_CHECK(outputs.axi.araddr == UINT64_C(0x2000));
        dcache_id = second_id;
    }
    inputs.axi.arready = 0u;
    TEST_CHECK(icache_id < NPU_GC_AXI_READ_ID_LIMIT);
    TEST_CHECK(dcache_id < NPU_GC_AXI_READ_ID_LIMIT);

    inputs.axi.rvalid = 1u;
    inputs.axi.rid = dcache_id;
    inputs.axi.rdata = UINT64_C(0xd0d1d2d3d4d5d6d7);
    inputs.axi.rresp = NPU_GC_AXI_RESP_OKAY;
    inputs.axi.rlast = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.rready != 0u);
    inputs.axi.rid = icache_id;
    inputs.axi.rdata = UINT64_C(0xa0a1a2a3a4a5a6a7);
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.rready != 0u);
    inputs.axi.rvalid = 0u;

    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.dcache_read_rsp.valid != 0u);
    TEST_CHECK(outputs.dcache_read_rsp.tag == 0x42u);
    TEST_CHECK(outputs.dcache_read_rsp.data ==
               UINT64_C(0xd0d1d2d3d4d5d6d7));
    TEST_CHECK(outputs.icache_rsp.valid != 0u);
    TEST_CHECK(outputs.icache_rsp.tag == 0x41u);
    TEST_CHECK(outputs.icache_rsp.data ==
               UINT64_C(0xa0a1a2a3a4a5a6a7));
    inputs.icache_rsp_ready = 1u;
    inputs.dcache_read_rsp_ready = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    inputs.icache_rsp_ready = 0u;
    inputs.dcache_read_rsp_ready = 0u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.idle != 0u);
    return 0;
}

static int gc_test_read_splitting(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t first_id;
    uint8_t second_id;
    int line;

    gc_test_init(&model, &inputs);
    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_DCACHE,
        UINT64_C(0xff0), 3u, 0x51u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_ar(
        &model, &inputs, &outputs,
        UINT64_C(0xff0), 1u, &first_id);
    if (line != 0) {
        return line;
    }

    line = gc_send_r(
        &model, &inputs, &outputs, first_id,
        UINT64_C(0x501), NPU_GC_AXI_RESP_OKAY, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_check_read_response(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_DCACHE,
        UINT64_C(0x501), 0x51u, 0u,
        NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }
    line = gc_send_r(
        &model, &inputs, &outputs, first_id,
        UINT64_C(0x502), NPU_GC_AXI_RESP_OKAY, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_check_read_response(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_DCACHE,
        UINT64_C(0x502), 0x51u, 0u,
        NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }

    line = gc_take_ar(
        &model, &inputs, &outputs,
        UINT64_C(0x1000), 1u, &second_id);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(second_id != first_id);
    line = gc_send_r(
        &model, &inputs, &outputs, second_id,
        UINT64_C(0x503), NPU_GC_AXI_RESP_OKAY, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_check_read_response(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_DCACHE,
        UINT64_C(0x503), 0x51u, 0u,
        NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }
    line = gc_send_r(
        &model, &inputs, &outputs, second_id,
        UINT64_C(0x504), NPU_GC_AXI_RESP_OKAY, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_check_read_response(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_DCACHE,
        UINT64_C(0x504), 0x51u, 1u,
        NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }

    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0x4000), 16u, 0x52u,
        0u, 4u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_ar(
        &model, &inputs, &outputs,
        UINT64_C(0x4000), 15u, &first_id);
    if (line != 0) {
        return line;
    }
    return 0;
}

static int gc_test_write_stalls_and_completion(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t write_id;
    uint64_t held_addr;
    uint8_t held_len;
    int line;

    gc_test_init(&model, &inputs);
    line = gc_submit_write(
        &model, &inputs, &outputs,
        UINT64_C(0x800), 1u, 0x61u,
        0xbu, 3u, 0u);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.awvalid != 0u);
    TEST_CHECK(outputs.axi.awcache == 0xbu);
    TEST_CHECK(outputs.axi.awprot == 3u);
    TEST_CHECK(outputs.axi.awqos == 0u);
    write_id = outputs.axi.awid;
    held_addr = outputs.axi.awaddr;
    held_len = outputs.axi.awlen;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.awvalid != 0u);
    TEST_CHECK(outputs.axi.awid == write_id);
    TEST_CHECK(outputs.axi.awaddr == held_addr);
    TEST_CHECK(outputs.axi.awlen == held_len);

    inputs.axi.awready = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    inputs.axi.awready = 0u;
    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0x0123456789abcdef), 0xf0u,
        0u, 0x61u);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.wvalid != 0u);
    TEST_CHECK(outputs.axi.wdata ==
               UINT64_C(0x0123456789abcdef));
    TEST_CHECK(outputs.axi.wstrb == 0xf0u);
    TEST_CHECK(outputs.axi.wlast == 0u);
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.wvalid != 0u);
    TEST_CHECK(outputs.axi.wdata ==
               UINT64_C(0x0123456789abcdef));
    line = gc_take_w(
        &model, &inputs, &outputs,
        UINT64_C(0x0123456789abcdef), 0xf0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0xfedcba9876543210), 0x0fu,
        1u, 0x61u);
    if (line != 0) {
        return line;
    }
    line = gc_take_w(
        &model, &inputs, &outputs,
        UINT64_C(0xfedcba9876543210), 0x0fu, 1u);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.dcache_write_rsp.valid == 0u);
    line = gc_send_b(
        &model, &inputs, &outputs, write_id,
        NPU_GC_AXI_RESP_OKAY);
    if (line != 0) {
        return line;
    }
    line = gc_check_write_response(
        &model, &inputs, &outputs,
        0x61u, NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.idle != 0u);
    return 0;
}

static int gc_test_write_splitting_and_concurrency(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t write_id_0;
    uint8_t write_id_1;
    uint8_t read_id;
    uint8_t beat;
    int line;

    gc_test_init(&model, &inputs);
    inputs.dcache_write_req.valid = 1u;
    inputs.dcache_write_req.addr = UINT64_C(0xff0);
    inputs.dcache_write_req.beats = 3u;
    inputs.dcache_write_req.tag = 0x71u;
    inputs.icache_req.valid = 1u;
    inputs.icache_req.addr = UINT64_C(0x7000);
    inputs.icache_req.tag = 0x72u;
    inputs.icache_req.prot = 4u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.dcache_write_req_ready != 0u);
    TEST_CHECK(outputs.icache_req_ready != 0u);
    inputs.dcache_write_req.valid = 0u;
    inputs.icache_req.valid = 0u;

    line = gc_take_aw(
        &model, &inputs, &outputs,
        UINT64_C(0xff0), 1u, &write_id_0);
    if (line != 0) {
        return line;
    }
    line = gc_take_ar(
        &model, &inputs, &outputs,
        UINT64_C(0x7000), 0u, &read_id);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(write_id_0 >= NPU_GC_AXI_WRITE_ID_BASE);
    TEST_CHECK(read_id < NPU_GC_AXI_READ_ID_LIMIT);

    for (beat = 0u; beat < 2u; beat++) {
        line = gc_accept_write_data(
            &model, &inputs, &outputs,
            UINT64_C(0x7100) + beat, 0xffu,
            0u, 0x71u);
        if (line != 0) {
            return line;
        }
        line = gc_take_w(
            &model, &inputs, &outputs,
            UINT64_C(0x7100) + beat, 0xffu,
            beat == 1u ? 1u : 0u);
        if (line != 0) {
            return line;
        }
    }

    line = gc_send_r(
        &model, &inputs, &outputs, read_id,
        UINT64_C(0x7272727272727272),
        NPU_GC_AXI_RESP_OKAY, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_send_b(
        &model, &inputs, &outputs, write_id_0,
        NPU_GC_AXI_RESP_OKAY);
    if (line != 0) {
        return line;
    }
    line = gc_check_read_response(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0x7272727272727272),
        0x72u, 1u, NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }

    line = gc_take_aw(
        &model, &inputs, &outputs,
        UINT64_C(0x1000), 1u, &write_id_1);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(write_id_1 != write_id_0);
    for (beat = 0u; beat < 2u; beat++) {
        line = gc_accept_write_data(
            &model, &inputs, &outputs,
            UINT64_C(0x7102) + beat, 0xffu,
            beat == 1u ? 1u : 0u, 0x71u);
        if (line != 0) {
            return line;
        }
        line = gc_take_w(
            &model, &inputs, &outputs,
            UINT64_C(0x7102) + beat, 0xffu,
            beat == 1u ? 1u : 0u);
        if (line != 0) {
            return line;
        }
    }
    line = gc_send_b(
        &model, &inputs, &outputs, write_id_1,
        NPU_GC_AXI_RESP_OKAY);
    if (line != 0) {
        return line;
    }
    line = gc_check_write_response(
        &model, &inputs, &outputs,
        0x71u, NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }
    return 0;
}

static int gc_test_illegal_ids_and_bus_errors(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t read_id;
    uint8_t write_id;
    int line;

    gc_test_init(&model, &inputs);
    inputs.axi.rvalid = 1u;
    inputs.axi.rid = 0x55u;
    inputs.axi.rlast = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.rready != 0u);
    inputs.axi.rvalid = 0u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_RID);
    TEST_CHECK(outputs.protocol_error_addr == 0u);
    TEST_CHECK(outputs.protocol_error_axi_id == 0x55u);

    gc_test_init(&model, &inputs);
    inputs.axi.bvalid = 1u;
    inputs.axi.bid = 0xa5u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.bready != 0u);
    inputs.axi.bvalid = 0u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_BID);
    TEST_CHECK(outputs.protocol_error_addr == 0u);
    TEST_CHECK(outputs.protocol_error_axi_id == 0xa5u);

    gc_test_init(&model, &inputs);
    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_DCACHE,
        UINT64_C(0x9000), 0u, 0x81u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_ar(
        &model, &inputs, &outputs,
        UINT64_C(0x9000), 0u, &read_id);
    if (line != 0) {
        return line;
    }
    line = gc_submit_write(
        &model, &inputs, &outputs,
        UINT64_C(0xa000), 0u, 0x82u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_aw(
        &model, &inputs, &outputs,
        UINT64_C(0xa000), 0u, &write_id);
    if (line != 0) {
        return line;
    }

    inputs.axi.rvalid = 1u;
    inputs.axi.rid = write_id;
    inputs.axi.rlast = 1u;
    inputs.axi.bvalid = 1u;
    inputs.axi.bid = read_id;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.rready != 0u);
    TEST_CHECK(outputs.axi.bready != 0u);
    inputs.axi.rvalid = 0u;
    inputs.axi.bvalid = 0u;
    TEST_CHECK(model.read[0].child_active != 0u);
    TEST_CHECK(model.write[0].child_active != 0u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_RID);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0xa000));
    TEST_CHECK(model.protocol_error_client ==
               NPU_GC_AXI_CLIENT_DCACHE);
    TEST_CHECK(model.protocol_error_tag == 0x82u);

    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0x8282828282828282),
        0xffu, 1u, 0x82u);
    if (line != 0) {
        return line;
    }
    line = gc_take_w(
        &model, &inputs, &outputs,
        UINT64_C(0x8282828282828282),
        0xffu, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_send_r(
        &model, &inputs, &outputs, read_id,
        UINT64_C(0x8181818181818181),
        NPU_GC_AXI_RESP_DECERR, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_send_b(
        &model, &inputs, &outputs, write_id,
        NPU_GC_AXI_RESP_SLVERR);
    if (line != 0) {
        return line;
    }
    line = gc_check_read_response(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_DCACHE,
        UINT64_C(0x8181818181818181),
        0x81u, 1u, NPU_STATUS_BUS_DECERR);
    if (line != 0) {
        return line;
    }
    line = gc_check_write_response(
        &model, &inputs, &outputs,
        0x82u, NPU_STATUS_BUS_SLVERR);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.first_error_valid != 0u);
    TEST_CHECK(model.first_error_status ==
               NPU_STATUS_BUS_DECERR);
    TEST_CHECK(model.first_error_axi_id == read_id);
    TEST_CHECK(model.first_error_axi_resp ==
               NPU_GC_AXI_RESP_DECERR);
    return 0;
}

static int gc_test_out_of_order_writes_and_duplicates(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t write_id_0;
    uint8_t write_id_1;
    uint8_t read_id;
    int line;

    gc_test_init(&model, &inputs);
    line = gc_submit_write(
        &model, &inputs, &outputs,
        UINT64_C(0xa800), 0u, 0x84u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_aw(
        &model, &inputs, &outputs,
        UINT64_C(0xa800), 0u, &write_id_0);
    if (line != 0) {
        return line;
    }
    line = gc_submit_write(
        &model, &inputs, &outputs,
        UINT64_C(0xa808), 0u, 0x85u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_aw(
        &model, &inputs, &outputs,
        UINT64_C(0xa808), 0u, &write_id_1);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(write_id_0 != write_id_1);

    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0x8400), 0xffu, 1u, 0x84u);
    if (line != 0) {
        return line;
    }
    line = gc_take_w(
        &model, &inputs, &outputs,
        UINT64_C(0x8400), 0xffu, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0x8500), 0xffu, 1u, 0x85u);
    if (line != 0) {
        return line;
    }
    line = gc_take_w(
        &model, &inputs, &outputs,
        UINT64_C(0x8500), 0xffu, 1u);
    if (line != 0) {
        return line;
    }

    line = gc_send_b(
        &model, &inputs, &outputs, write_id_1,
        NPU_GC_AXI_RESP_OKAY);
    if (line != 0) {
        return line;
    }
    line = gc_send_b(
        &model, &inputs, &outputs, write_id_0,
        NPU_GC_AXI_RESP_OKAY);
    if (line != 0) {
        return line;
    }
    line = gc_check_write_response(
        &model, &inputs, &outputs,
        0x85u, NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }
    line = gc_check_write_response(
        &model, &inputs, &outputs,
        0x84u, NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }

    line = gc_send_b(
        &model, &inputs, &outputs, write_id_0,
        NPU_GC_AXI_RESP_OKAY);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_BID);
    TEST_CHECK(outputs.protocol_error_addr == 0u);
    TEST_CHECK(outputs.protocol_error_axi_id_valid != 0u);
    TEST_CHECK(outputs.protocol_error_axi_id == write_id_0);

    gc_test_init(&model, &inputs);
    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0xa900), 0u, 0x86u,
        0u, 4u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_ar(
        &model, &inputs, &outputs,
        UINT64_C(0xa900), 0u, &read_id);
    if (line != 0) {
        return line;
    }
    line = gc_send_r(
        &model, &inputs, &outputs, read_id,
        UINT64_C(0x8600), NPU_GC_AXI_RESP_OKAY, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_check_read_response(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0x8600), 0x86u, 1u,
        NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }
    line = gc_send_r(
        &model, &inputs, &outputs, read_id,
        UINT64_C(0x86ff), NPU_GC_AXI_RESP_OKAY, 1u);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_RID);
    TEST_CHECK(outputs.protocol_error_addr == 0u);
    TEST_CHECK(outputs.protocol_error_axi_id_valid != 0u);
    TEST_CHECK(outputs.protocol_error_axi_id == read_id);
    return 0;
}

static int gc_test_exokay_qos_and_id_valid(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t read_id;
    uint8_t write_id;
    int line;

    gc_test_init(&model, &inputs);
    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_DCACHE,
        UINT64_C(0xaa00), 0u, 0x87u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_ar(
        &model, &inputs, &outputs,
        UINT64_C(0xaa00), 0u, &read_id);
    if (line != 0) {
        return line;
    }
    line = gc_send_r(
        &model, &inputs, &outputs, read_id,
        UINT64_C(0x8700), NPU_GC_AXI_RESP_EXOKAY, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_check_read_response(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_DCACHE,
        UINT64_C(0x8700), 0x87u, 1u,
        NPU_STATUS_BUS_SLVERR);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_RRESP);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0xaa00));
    TEST_CHECK(model.protocol_error_axi_id_valid != 0u);
    TEST_CHECK(model.first_error_axi_id_valid != 0u);

    gc_test_init(&model, &inputs);
    model.next_write_id = 0xffu;
    line = gc_submit_write(
        &model, &inputs, &outputs,
        UINT64_C(0xab00), 0u, 0x88u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_aw(
        &model, &inputs, &outputs,
        UINT64_C(0xab00), 0u, &write_id);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(write_id == 0xffu);
    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0x8800), 0xffu, 1u, 0x88u);
    if (line != 0) {
        return line;
    }
    line = gc_take_w(
        &model, &inputs, &outputs,
        UINT64_C(0x8800), 0xffu, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_send_b(
        &model, &inputs, &outputs, write_id,
        NPU_GC_AXI_RESP_EXOKAY);
    if (line != 0) {
        return line;
    }
    line = gc_check_write_response(
        &model, &inputs, &outputs,
        0x88u, NPU_STATUS_BUS_SLVERR);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_BRESP);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0xab00));
    TEST_CHECK(model.protocol_error_axi_id_valid != 0u);
    TEST_CHECK(model.protocol_error_axi_id == 0xffu);
    TEST_CHECK(model.first_error_axi_id_valid != 0u);
    TEST_CHECK(model.first_error_axi_id == 0xffu);

    gc_test_init(&model, &inputs);
    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0xac00), 0u, 0x89u,
        0u, 4u, 1u);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.arvalid == 0u);
    TEST_CHECK(outputs.icache_rsp.valid != 0u);
    TEST_CHECK(outputs.icache_rsp.status ==
               NPU_STATUS_BAD_DESC);
    TEST_CHECK(outputs.first_error_axi_id_valid == 0u);
    return 0;
}

static int gc_test_rlast_errors_and_duplicates(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t read_id;
    int line;

    gc_test_init(&model, &inputs);
    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0xb000), 1u, 0x91u,
        0u, 4u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_ar(
        &model, &inputs, &outputs,
        UINT64_C(0xb000), 1u, &read_id);
    if (line != 0) {
        return line;
    }
    line = gc_send_r(
        &model, &inputs, &outputs, read_id,
        UINT64_C(0x91), NPU_GC_AXI_RESP_OKAY, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_check_read_response(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0x91), 0x91u, 1u,
        NPU_STATUS_BUS_SLVERR);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_RLAST);
    TEST_CHECK(outputs.protocol_error_addr == UINT64_C(0xb000));

    inputs.axi.rvalid = 1u;
    inputs.axi.rid = read_id;
    inputs.axi.rdata = UINT64_C(0xdead);
    inputs.axi.rlast = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.rready != 0u);
    inputs.axi.rvalid = 0u;
    TEST_CHECK(model.read[0].valid == 0u);

    gc_test_init(&model, &inputs);
    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_DCACHE,
        UINT64_C(0xc000), 0u, 0x92u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_ar(
        &model, &inputs, &outputs,
        UINT64_C(0xc000), 0u, &read_id);
    if (line != 0) {
        return line;
    }
    line = gc_send_r(
        &model, &inputs, &outputs, read_id,
        UINT64_C(0x92), NPU_GC_AXI_RESP_OKAY, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_check_read_response(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_DCACHE,
        UINT64_C(0x92), 0x92u, 1u,
        NPU_STATUS_BUS_SLVERR);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_RLAST);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0xc000));
    TEST_CHECK(model.read[0].drain_rlast != 0u);
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.idle == 0u);
    line = gc_send_r(
        &model, &inputs, &outputs, read_id,
        UINT64_C(0x9201), NPU_GC_AXI_RESP_OKAY, 1u);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.idle != 0u);
    return 0;
}

static int gc_test_write_protocol_errors(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t write_id;
    int line;

    gc_test_init(&model, &inputs);
    line = gc_submit_write(
        &model, &inputs, &outputs,
        UINT64_C(0xd000), 1u, 0xa1u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_aw(
        &model, &inputs, &outputs,
        UINT64_C(0xd000), 1u, &write_id);
    if (line != 0) {
        return line;
    }
    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0xa100), 0xffu, 1u, 0xa1u);
    if (line != 0) {
        return line;
    }
    line = gc_take_w(
        &model, &inputs, &outputs,
        UINT64_C(0xa100), 0xffu, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0xa101), 0xffu, 1u, 0xa1u);
    if (line != 0) {
        return line;
    }
    line = gc_take_w(
        &model, &inputs, &outputs,
        UINT64_C(0xa101), 0xffu, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_send_b(
        &model, &inputs, &outputs, write_id,
        NPU_GC_AXI_RESP_OKAY);
    if (line != 0) {
        return line;
    }
    line = gc_check_write_response(
        &model, &inputs, &outputs,
        0xa1u, NPU_STATUS_BUS_SLVERR);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_WLAST);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0xd000));

    gc_test_init(&model, &inputs);
    line = gc_submit_write(
        &model, &inputs, &outputs,
        UINT64_C(0xe000), 0u, 0xa2u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_aw(
        &model, &inputs, &outputs,
        UINT64_C(0xe000), 0u, &write_id);
    if (line != 0) {
        return line;
    }
    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0xa2), 0xffu, 1u, 0xffffu);
    if (line != 0) {
        return line;
    }
    line = gc_take_w(
        &model, &inputs, &outputs,
        UINT64_C(0xa2), 0xffu, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_send_b(
        &model, &inputs, &outputs, write_id,
        NPU_GC_AXI_RESP_OKAY);
    if (line != 0) {
        return line;
    }
    line = gc_check_write_response(
        &model, &inputs, &outputs,
        0xa2u, NPU_STATUS_BUS_SLVERR);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_WTAG);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0xe000));

    gc_test_init(&model, &inputs);
    line = gc_submit_write(
        &model, &inputs, &outputs,
        UINT64_C(0xe800), 0u, 0xa5u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_aw(
        &model, &inputs, &outputs,
        UINT64_C(0xe800), 0u, &write_id);
    if (line != 0) {
        return line;
    }
    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0xa5), 0xffu, 0u, 0xa5u);
    if (line != 0) {
        return line;
    }
    line = gc_take_w(
        &model, &inputs, &outputs,
        UINT64_C(0xa5), 0xffu, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_send_b(
        &model, &inputs, &outputs, write_id,
        NPU_GC_AXI_RESP_OKAY);
    if (line != 0) {
        return line;
    }
    line = gc_check_write_response(
        &model, &inputs, &outputs,
        0xa5u, NPU_STATUS_BUS_SLVERR);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_WLAST);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0xe800));

    gc_test_init(&model, &inputs);
    line = gc_submit_write(
        &model, &inputs, &outputs,
        UINT64_C(0xf000), 0u, 0xa3u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.awvalid != 0u);
    write_id = outputs.axi.awid;
    inputs.axi.bvalid = 1u;
    inputs.axi.bid = write_id;
    inputs.axi.bresp = NPU_GC_AXI_RESP_OKAY;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.bready != 0u);
    inputs.axi.bvalid = 0u;
    TEST_CHECK(model.write[0].child_active != 0u);
    TEST_CHECK(model.write[0].addr_sent == 0u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_BID);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0xf000));

    inputs.axi.awready = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    inputs.axi.awready = 0u;
    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0xa3), 0xffu, 1u, 0xa3u);
    if (line != 0) {
        return line;
    }
    line = gc_take_w(
        &model, &inputs, &outputs,
        UINT64_C(0xa3), 0xffu, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_send_b(
        &model, &inputs, &outputs, write_id,
        NPU_GC_AXI_RESP_OKAY);
    if (line != 0) {
        return line;
    }
    line = gc_check_write_response(
        &model, &inputs, &outputs,
        0xa3u, NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }

    gc_test_init(&model, &inputs);
    line = gc_submit_write(
        &model, &inputs, &outputs,
        UINT64_C(0x11000), 1u, 0xa4u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_take_aw(
        &model, &inputs, &outputs,
        UINT64_C(0x11000), 1u, &write_id);
    if (line != 0) {
        return line;
    }
    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0xa400), 0xffu, 0u, 0xa4u);
    if (line != 0) {
        return line;
    }
    line = gc_send_b(
        &model, &inputs, &outputs, write_id,
        NPU_GC_AXI_RESP_OKAY);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.wvalid != 0u);
    TEST_CHECK(outputs.axi.wdata == UINT64_C(0xa400));
    TEST_CHECK(outputs.axi.wlast == 0u);
    line = gc_take_w(
        &model, &inputs, &outputs,
        UINT64_C(0xa400), 0xffu, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_accept_write_data(
        &model, &inputs, &outputs,
        UINT64_C(0xa401), 0xffu, 1u, 0xa4u);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.wvalid == 0u);
    line = gc_check_write_response(
        &model, &inputs, &outputs,
        0xa4u, NPU_STATUS_BUS_SLVERR);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_BID);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0x11000));
    return 0;
}

static int gc_test_invalid_and_duplicate_requests(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t read_id;
    int line;

    gc_test_init(&model, &inputs);
    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0x123), 0u, 0xb1u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.arvalid == 0u);
    TEST_CHECK(outputs.icache_rsp.valid != 0u);
    TEST_CHECK(outputs.icache_rsp.status ==
               NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(outputs.icache_rsp.last != 0u);
    inputs.icache_rsp_ready = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);

    gc_test_init(&model, &inputs);
    line = gc_submit_write(
        &model, &inputs, &outputs,
        UINT64_C(0x10000000000), 0u, 0xb2u,
        0u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.awvalid == 0u);
    TEST_CHECK(outputs.dcache_write_rsp.valid != 0u);
    TEST_CHECK(outputs.dcache_write_rsp.status ==
               NPU_STATUS_ADDR_FAULT);

    gc_test_init(&model, &inputs);
    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_DCACHE,
        UINT64_C(0x12000), 0u, 0xb3u,
        0x10u, 0u, 0u);
    if (line != 0) {
        return line;
    }
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.arvalid == 0u);
    TEST_CHECK(outputs.dcache_read_rsp.valid != 0u);
    TEST_CHECK(outputs.dcache_read_rsp.status ==
               NPU_STATUS_BAD_DESC);

    gc_test_init(&model, &inputs);
    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0x13000), 0u, 0xb4u,
        0u, 4u, 0u);
    if (line != 0) {
        return line;
    }
    line = gc_submit_read(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0x14000), 0u, 0xb4u,
        0u, 4u, 0u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_DUPLICATE_TAG);
    TEST_CHECK(model.protocol_error_addr == UINT64_C(0x14000));
    TEST_CHECK(model.read[0].status == NPU_STATUS_SUCCESS);
    TEST_CHECK(model.read[1].status == NPU_STATUS_BAD_DESC);
    TEST_CHECK(model.read[1].response_pending == 0u ||
               model.read[1].response_held != 0u);

    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.axi.arvalid != 0u);
    TEST_CHECK(outputs.axi.araddr == UINT64_C(0x13000));
    read_id = outputs.axi.arid;
    TEST_CHECK(outputs.icache_rsp.valid != 0u);
    TEST_CHECK(outputs.icache_rsp.tag == 0xb4u);
    TEST_CHECK(outputs.icache_rsp.status ==
               NPU_STATUS_BAD_DESC);
    inputs.icache_rsp_ready = 1u;
    inputs.axi.arready = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    inputs.icache_rsp_ready = 0u;
    inputs.axi.arready = 0u;
    line = gc_send_r(
        &model, &inputs, &outputs, read_id,
        UINT64_C(0xb4), NPU_GC_AXI_RESP_OKAY, 1u);
    if (line != 0) {
        return line;
    }
    line = gc_check_read_response(
        &model, &inputs, &outputs,
        NPU_GC_AXI_CLIENT_ICACHE,
        UINT64_C(0xb4), 0xb4u, 1u,
        NPU_STATUS_SUCCESS);
    if (line != 0) {
        return line;
    }
    return 0;
}

static int gc_test_independent_tables_and_random_stalls(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;
    uint8_t index;
    uint8_t accepted_reads = 0u;
    uint8_t accepted_writes = 0u;
    uint32_t random_state = UINT32_C(0x13579bdf);

    gc_test_init(&model, &inputs);
    for (index = 0u; index < NPU_GC_AXI_READ_OUTSTANDING;
         index++) {
        inputs.icache_req.valid = 1u;
        inputs.icache_req.addr =
            UINT64_C(0x20000) + (uint64_t)index * 8u;
        inputs.icache_req.tag = (uint16_t)(0xc0u + index);
        npu_gc_axi_cycle_step(&model, &inputs, &outputs);
        if (outputs.icache_req_ready != 0u) {
            accepted_reads++;
        }
    }
    inputs.icache_req.valid = 0u;
    TEST_CHECK(accepted_reads ==
               NPU_GC_AXI_READ_OUTSTANDING);
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.icache_req_ready == 0u);
    TEST_CHECK(outputs.dcache_read_req_ready == 0u);
    TEST_CHECK(outputs.dcache_write_req_ready != 0u);

    for (index = 0u; index < NPU_GC_AXI_WRITE_OUTSTANDING;
         index++) {
        inputs.dcache_write_req.valid = 1u;
        inputs.dcache_write_req.addr =
            UINT64_C(0x30000) + (uint64_t)index * 8u;
        inputs.dcache_write_req.tag =
            (uint16_t)(0xd0u + index);
        npu_gc_axi_cycle_step(&model, &inputs, &outputs);
        if (outputs.dcache_write_req_ready != 0u) {
            accepted_writes++;
        }
    }
    inputs.dcache_write_req.valid = 0u;
    TEST_CHECK(accepted_writes ==
               NPU_GC_AXI_WRITE_OUTSTANDING);
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.dcache_write_req_ready == 0u);
    TEST_CHECK(outputs.read_requests_used ==
               NPU_GC_AXI_READ_OUTSTANDING);
    TEST_CHECK(outputs.write_requests_used ==
               NPU_GC_AXI_WRITE_OUTSTANDING);

    for (index = 0u; index < 32u; index++) {
        uint8_t old_arvalid = outputs.axi.arvalid;
        uint8_t old_awvalid = outputs.axi.awvalid;
        uint64_t old_araddr = outputs.axi.araddr;
        uint64_t old_awaddr = outputs.axi.awaddr;
        uint8_t old_arid = outputs.axi.arid;
        uint8_t old_awid = outputs.axi.awid;
        uint8_t old_arready = inputs.axi.arready;
        uint8_t old_awready = inputs.axi.awready;

        random_state =
            random_state * UINT32_C(1664525) +
            UINT32_C(1013904223);
        inputs.axi.arready =
            (uint8_t)((random_state >> 31) & 1u);
        inputs.axi.awready =
            (uint8_t)((random_state >> 30) & 1u);
        npu_gc_axi_cycle_step(&model, &inputs, &outputs);
        if (old_arvalid != 0u && old_arready == 0u) {
            TEST_CHECK(outputs.axi.arvalid != 0u);
            TEST_CHECK(outputs.axi.araddr == old_araddr);
            TEST_CHECK(outputs.axi.arid == old_arid);
        }
        if (old_awvalid != 0u && old_awready == 0u) {
            TEST_CHECK(outputs.axi.awvalid != 0u);
            TEST_CHECK(outputs.axi.awaddr == old_awaddr);
            TEST_CHECK(outputs.axi.awid == old_awid);
        }
    }
    return 0;
}

static int gc_test_diagnostic_clear_and_new_error(void)
{
    npu_gc_axi_cycle_t model;
    npu_gc_axi_cycle_inputs_t inputs;
    npu_gc_axi_cycle_outputs_t outputs;

    gc_test_init(&model, &inputs);
    model.first_error_valid = 1u;
    model.first_error_status = NPU_STATUS_BUS_SLVERR;
    model.first_error_axi_id = 0xffu;
    model.first_error_axi_id_valid = 1u;
    model.protocol_error_valid = 1u;
    model.protocol_error_kind = NPU_GC_AXI_PROTOCOL_BID;
    model.protocol_error_addr = UINT64_C(0xabcdef00);
    model.protocol_error_client = NPU_GC_AXI_CLIENT_DCACHE;
    model.protocol_error_tag = 0x456u;
    model.protocol_error_axi_id = 0xffu;
    model.protocol_error_axi_id_valid = 1u;

    inputs.error_clear = 1u;
    inputs.icache_req.valid = 1u;
    inputs.icache_req.addr = UINT64_C(3);
    inputs.icache_req.tag = 0x1234u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.first_error_valid != 0u);
    TEST_CHECK(outputs.first_error_axi_id_valid != 0u);
    TEST_CHECK(outputs.first_error_axi_id == 0xffu);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_BID);
    TEST_CHECK(outputs.protocol_error_addr ==
               UINT64_C(0xabcdef00));
    TEST_CHECK(outputs.protocol_error_client ==
               NPU_GC_AXI_CLIENT_DCACHE);
    TEST_CHECK(outputs.protocol_error_tag == 0x456u);
    TEST_CHECK(outputs.protocol_error_axi_id_valid != 0u);
    TEST_CHECK(outputs.protocol_error_axi_id == 0xffu);
    TEST_CHECK(model.first_error_valid != 0u);
    TEST_CHECK(model.first_error_status == NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(model.first_error_tag == 0x1234u);
    TEST_CHECK(model.first_error_axi_id_valid == 0u);
    TEST_CHECK(model.protocol_error_valid == 0u);

    inputs.error_clear = 0u;
    inputs.icache_req.valid = 0u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.first_error_valid != 0u);
    TEST_CHECK(outputs.first_error_status == NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(outputs.first_error_axi_id_valid == 0u);
    TEST_CHECK(outputs.protocol_error_valid == 0u);

    inputs.error_clear = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    inputs.error_clear = 0u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.first_error_valid == 0u);
    TEST_CHECK(outputs.protocol_error_valid == 0u);
    TEST_CHECK(outputs.first_error_axi_id_valid == 0u);

    gc_test_init(&model, &inputs);
    model.protocol_error_valid = 1u;
    model.protocol_error_kind = NPU_GC_AXI_PROTOCOL_BRESP;
    model.protocol_error_addr = UINT64_C(0x12345678);
    model.protocol_error_client = NPU_GC_AXI_CLIENT_DCACHE;
    model.protocol_error_tag = 0x789u;
    model.protocol_error_axi_id = 0x9au;
    model.protocol_error_axi_id_valid = 1u;

    inputs.error_clear = 1u;
    inputs.axi.rvalid = 1u;
    inputs.axi.rid = 0x55u;
    inputs.axi.rlast = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_BRESP);
    TEST_CHECK(outputs.protocol_error_addr ==
               UINT64_C(0x12345678));
    TEST_CHECK(outputs.protocol_error_client ==
               NPU_GC_AXI_CLIENT_DCACHE);
    TEST_CHECK(outputs.protocol_error_tag == 0x789u);
    TEST_CHECK(outputs.protocol_error_axi_id == 0x9au);
    TEST_CHECK(model.protocol_error_valid != 0u);
    TEST_CHECK(model.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_RID);
    TEST_CHECK(model.protocol_error_addr == 0u);
    TEST_CHECK(model.protocol_error_client ==
               NPU_GC_AXI_INVALID_CLIENT);
    TEST_CHECK(model.protocol_error_tag == 0x55u);
    TEST_CHECK(model.protocol_error_axi_id == 0x55u);

    inputs.error_clear = 0u;
    inputs.axi.rvalid = 0u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.protocol_error_valid != 0u);
    TEST_CHECK(outputs.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_RID);
    TEST_CHECK(outputs.protocol_error_addr == 0u);
    TEST_CHECK(outputs.protocol_error_client ==
               NPU_GC_AXI_INVALID_CLIENT);
    TEST_CHECK(outputs.protocol_error_tag == 0x55u);

    inputs.axi.bvalid = 1u;
    inputs.axi.bid = 0xa5u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    inputs.axi.bvalid = 0u;
    TEST_CHECK(model.protocol_error_kind ==
               NPU_GC_AXI_PROTOCOL_RID);
    TEST_CHECK(model.protocol_error_addr == 0u);
    TEST_CHECK(model.protocol_error_tag == 0x55u);

    inputs.error_clear = 1u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    inputs.error_clear = 0u;
    npu_gc_axi_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.protocol_error_valid == 0u);
    return 0;
}

int test_gc_axi_cycle(void)
{
    int line;

    line = gc_test_reset_idle_and_quiesce();
    if (line != 0) {
        return line;
    }
    line = gc_test_read_stalls_and_ingress();
    if (line != 0) {
        return line;
    }
    line = gc_test_concurrent_out_of_order_reads();
    if (line != 0) {
        return line;
    }
    line = gc_test_read_splitting();
    if (line != 0) {
        return line;
    }
    line = gc_test_write_stalls_and_completion();
    if (line != 0) {
        return line;
    }
    line = gc_test_write_splitting_and_concurrency();
    if (line != 0) {
        return line;
    }
    line = gc_test_illegal_ids_and_bus_errors();
    if (line != 0) {
        return line;
    }
    line = gc_test_out_of_order_writes_and_duplicates();
    if (line != 0) {
        return line;
    }
    line = gc_test_exokay_qos_and_id_valid();
    if (line != 0) {
        return line;
    }
    line = gc_test_rlast_errors_and_duplicates();
    if (line != 0) {
        return line;
    }
    line = gc_test_write_protocol_errors();
    if (line != 0) {
        return line;
    }
    line = gc_test_invalid_and_duplicate_requests();
    if (line != 0) {
        return line;
    }
    line = gc_test_independent_tables_and_random_stalls();
    if (line != 0) {
        return line;
    }
    line = gc_test_diagnostic_clear_and_new_error();
    if (line != 0) {
        return line;
    }
    return 0;
}

#ifdef NPU_GC_AXI_CYCLE_STANDALONE
int main(void)
{
    int line = test_gc_axi_cycle();

    if (line == 0) {
        (void)printf("[PASS] gc_axi_cycle\n");
        return 0;
    }
    (void)printf("[FAIL] gc_axi_cycle at test line %d\n",
                 line);
    return 1;
}
#endif
