#include "npu_gc_axi_cycle.h"

#include <stddef.h>
#include <string.h>

static uint16_t gc_min_u16(uint16_t left, uint16_t right)
{
    return left < right ? left : right;
}

static uint8_t gc_count_free_reads(
    const npu_gc_axi_cycle_t *model)
{
    uint8_t count = 0u;
    uint8_t index;

    for (index = 0u; index < NPU_GC_AXI_READ_OUTSTANDING;
         index++) {
        if (model->read[index].valid == 0u) {
            count++;
        }
    }
    return count;
}

static uint8_t gc_count_free_writes(
    const npu_gc_axi_cycle_t *model)
{
    uint8_t count = 0u;
    uint8_t index;

    for (index = 0u; index < NPU_GC_AXI_WRITE_OUTSTANDING;
         index++) {
        if (model->write[index].valid == 0u) {
            count++;
        }
    }
    return count;
}

static uint8_t gc_find_free_read(
    const npu_gc_axi_cycle_t *model)
{
    uint8_t index;

    for (index = 0u; index < NPU_GC_AXI_READ_OUTSTANDING;
         index++) {
        if (model->read[index].valid == 0u) {
            return index;
        }
    }
    return NPU_GC_AXI_INVALID_SLOT;
}

static uint8_t gc_find_free_write(
    const npu_gc_axi_cycle_t *model)
{
    uint8_t index;

    for (index = 0u; index < NPU_GC_AXI_WRITE_OUTSTANDING;
         index++) {
        if (model->write[index].valid == 0u) {
            return index;
        }
    }
    return NPU_GC_AXI_INVALID_SLOT;
}

static uint8_t gc_read_tag_active(
    const npu_gc_axi_cycle_t *model,
    uint8_t client,
    uint16_t tag)
{
    uint8_t index;

    for (index = 0u; index < NPU_GC_AXI_READ_OUTSTANDING;
         index++) {
        const npu_gc_axi_read_entry_t *entry =
            &model->read[index];
        if (entry->valid != 0u &&
            entry->client == client &&
            entry->tag == tag) {
            return 1u;
        }
    }
    return 0u;
}

static uint8_t gc_write_tag_active(
    const npu_gc_axi_cycle_t *model,
    uint16_t tag)
{
    uint8_t index;

    for (index = 0u; index < NPU_GC_AXI_WRITE_OUTSTANDING;
         index++) {
        if (model->write[index].valid != 0u &&
            model->write[index].tag == tag) {
            return 1u;
        }
    }
    return 0u;
}

static uint8_t gc_find_read_id(
    const npu_gc_axi_cycle_t *model,
    uint8_t axi_id)
{
    uint8_t index;

    for (index = 0u; index < NPU_GC_AXI_READ_OUTSTANDING;
         index++) {
        const npu_gc_axi_read_entry_t *entry =
            &model->read[index];
        if (entry->valid != 0u &&
            entry->child_active != 0u &&
            entry->axi_id == axi_id) {
            return index;
        }
    }
    return NPU_GC_AXI_INVALID_SLOT;
}

static uint8_t gc_find_write_id(
    const npu_gc_axi_cycle_t *model,
    uint8_t axi_id)
{
    uint8_t index;

    for (index = 0u; index < NPU_GC_AXI_WRITE_OUTSTANDING;
         index++) {
        const npu_gc_axi_write_entry_t *entry =
            &model->write[index];
        if (entry->valid != 0u &&
            entry->child_active != 0u &&
            entry->axi_id == axi_id) {
            return index;
        }
    }
    return NPU_GC_AXI_INVALID_SLOT;
}

static uint8_t gc_read_id_used(
    const npu_gc_axi_cycle_t *model,
    uint8_t axi_id)
{
    return gc_find_read_id(model, axi_id) !=
                   NPU_GC_AXI_INVALID_SLOT
               ? 1u
               : 0u;
}

static uint8_t gc_write_id_used(
    const npu_gc_axi_cycle_t *model,
    uint8_t axi_id)
{
    return gc_find_write_id(model, axi_id) !=
                   NPU_GC_AXI_INVALID_SLOT
               ? 1u
               : 0u;
}

static uint8_t gc_allocate_read_id(
    npu_gc_axi_cycle_t *model,
    uint8_t *axi_id)
{
    uint16_t offset;

    for (offset = 0u; offset < NPU_GC_AXI_READ_ID_LIMIT;
         offset++) {
        uint8_t candidate =
            (uint8_t)(((uint16_t)model->next_read_id + offset) &
                      0x7fu);
        if (gc_read_id_used(model, candidate) == 0u) {
            *axi_id = candidate;
            model->next_read_id =
                (uint8_t)((candidate + 1u) & 0x7fu);
            return 1u;
        }
    }
    return 0u;
}

static uint8_t gc_allocate_write_id(
    npu_gc_axi_cycle_t *model,
    uint8_t *axi_id)
{
    uint16_t offset;
    uint16_t start =
        (uint16_t)(model->next_write_id -
                   NPU_GC_AXI_WRITE_ID_BASE);

    for (offset = 0u;
         offset <
             NPU_GC_AXI_WRITE_ID_LIMIT -
                 NPU_GC_AXI_WRITE_ID_BASE;
         offset++) {
        uint8_t candidate =
            (uint8_t)(NPU_GC_AXI_WRITE_ID_BASE +
                      ((start + offset) & 0x7fu));
        if (gc_write_id_used(model, candidate) == 0u) {
            *axi_id = candidate;
            model->next_write_id =
                (uint8_t)(NPU_GC_AXI_WRITE_ID_BASE +
                          ((candidate -
                            NPU_GC_AXI_WRITE_ID_BASE + 1u) &
                           0x7fu));
            return 1u;
        }
    }
    return 0u;
}

static uint8_t gc_request_status(uint64_t addr,
                                 uint8_t beats_minus_one,
                                 uint8_t cache,
                                 uint8_t prot,
                                 uint8_t qos)
{
    uint64_t beats = (uint64_t)beats_minus_one + UINT64_C(1);
    uint64_t bytes = beats * UINT64_C(8);

    if ((addr & ~NPU_GC_AXI_PA_MASK) != 0u ||
        (addr & UINT64_C(7)) != 0u ||
        addr > NPU_GC_AXI_PA_MASK - (bytes - UINT64_C(1))) {
        return NPU_STATUS_ADDR_FAULT;
    }
    if ((cache & 0xf0u) != 0u ||
        (prot & 0xf8u) != 0u ||
        qos != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    return NPU_STATUS_SUCCESS;
}

static uint16_t gc_child_beats(uint64_t addr,
                               uint16_t remaining)
{
    uint16_t page_beats =
        (uint16_t)((UINT64_C(4096) -
                    (addr & UINT64_C(4095))) /
                   UINT64_C(8));
    uint16_t beats =
        gc_min_u16(remaining,
                   NPU_GC_AXI_MAX_BURST_BEATS);

    return gc_min_u16(beats, page_beats);
}

static uint8_t gc_axi_status(uint8_t response)
{
    if (response == NPU_GC_AXI_RESP_OKAY) {
        return NPU_STATUS_SUCCESS;
    }
    if (response == NPU_GC_AXI_RESP_DECERR) {
        return NPU_STATUS_BUS_DECERR;
    }
    return NPU_STATUS_BUS_SLVERR;
}

static void gc_record_first_error(
    npu_gc_axi_cycle_t *model,
    uint8_t status,
    uint8_t client,
    uint16_t tag,
    uint64_t addr,
    uint8_t axi_id_valid,
    uint8_t axi_id,
    uint8_t axi_response)
{
    if (model->first_error_valid != 0u) {
        return;
    }
    model->first_error_valid = 1u;
    model->first_error_status = status;
    model->first_error_client = client;
    model->first_error_tag = tag;
    model->first_error_addr = addr;
    model->first_error_axi_id_valid = axi_id_valid;
    model->first_error_axi_id = axi_id;
    model->first_error_axi_resp = axi_response;
}

static void gc_mark_protocol_error(
    npu_gc_axi_cycle_t *model,
    uint8_t kind,
    uint64_t addr,
    uint8_t client,
    uint16_t tag,
    uint8_t axi_id_valid,
    uint8_t axi_id)
{
    if (model->protocol_error_valid != 0u) {
        return;
    }
    model->protocol_error_valid = 1u;
    model->protocol_error_kind = kind;
    model->protocol_error_addr = addr;
    model->protocol_error_client = client;
    model->protocol_error_tag = tag;
    model->protocol_error_axi_id_valid = axi_id_valid;
    model->protocol_error_axi_id = axi_id;
}

static void gc_clear_diagnostics(npu_gc_axi_cycle_t *model)
{
    model->first_error_valid = 0u;
    model->first_error_status = 0u;
    model->first_error_client = 0u;
    model->first_error_tag = 0u;
    model->first_error_addr = 0u;
    model->first_error_axi_id = NPU_GC_AXI_INVALID_SLOT;
    model->first_error_axi_id_valid = 0u;
    model->first_error_axi_resp = 0u;
    model->protocol_error_valid = 0u;
    model->protocol_error_kind = NPU_GC_AXI_PROTOCOL_NONE;
    model->protocol_error_addr = 0u;
    model->protocol_error_client = 0u;
    model->protocol_error_tag = 0u;
    model->protocol_error_axi_id = NPU_GC_AXI_INVALID_SLOT;
    model->protocol_error_axi_id_valid = 0u;
}

static void gc_mark_bus_protocol(
    npu_gc_axi_cycle_t *model,
    uint8_t kind,
    uint8_t axi_id)
{
    uint8_t read_slot = gc_find_read_id(model, axi_id);
    uint8_t write_slot = gc_find_write_id(model, axi_id);
    uint8_t client = NPU_GC_AXI_INVALID_CLIENT;
    uint16_t tag = axi_id;
    uint64_t addr = 0u;

    if (read_slot != NPU_GC_AXI_INVALID_SLOT) {
        const npu_gc_axi_read_entry_t *request =
            &model->read[read_slot];

        client = request->client;
        tag = request->tag;
        addr =
            request->next_addr +
            (uint64_t)request->child_beats_done * UINT64_C(8);
    } else if (write_slot != NPU_GC_AXI_INVALID_SLOT) {
        client = NPU_GC_AXI_CLIENT_DCACHE;
        tag = model->write[write_slot].tag;
        addr = model->write[write_slot].next_addr;
    }
    gc_mark_protocol_error(
        model, kind, addr, client, tag, 1u, axi_id);
}

static npu_gc_axi_read_rsp_hold_t *gc_read_hold(
    npu_gc_axi_cycle_t *model,
    uint8_t client)
{
    return client == NPU_GC_AXI_CLIENT_ICACHE
               ? &model->icache_rsp_hold
               : &model->dcache_read_rsp_hold;
}

static uint8_t gc_write_order_head(
    const npu_gc_axi_cycle_t *model)
{
    if (model->write_order_count == 0u) {
        return NPU_GC_AXI_INVALID_SLOT;
    }
    return model->write_order[model->write_order_head];
}

static void gc_write_order_push(npu_gc_axi_cycle_t *model,
                                uint8_t slot)
{
    if (model->write_order_count >=
        NPU_GC_AXI_WRITE_ORDER_DEPTH) {
        return;
    }
    model->write_order[model->write_order_tail] = slot;
    model->write_order_tail =
        (uint8_t)((model->write_order_tail + 1u) %
                  NPU_GC_AXI_WRITE_ORDER_DEPTH);
    model->write_order_count++;
}

static void gc_write_order_pop(npu_gc_axi_cycle_t *model)
{
    if (model->write_order_count == 0u) {
        return;
    }
    model->write_order_head =
        (uint8_t)((model->write_order_head + 1u) %
                  NPU_GC_AXI_WRITE_ORDER_DEPTH);
    model->write_order_count--;
}

static uint8_t gc_write_order_remove(
    npu_gc_axi_cycle_t *model,
    uint8_t slot)
{
    uint8_t retained[NPU_GC_AXI_WRITE_ORDER_DEPTH];
    uint8_t retained_count = 0u;
    uint8_t offset;
    uint8_t removed_head =
        gc_write_order_head(model) == slot ? 1u : 0u;

    for (offset = 0u; offset < model->write_order_count;
         offset++) {
        uint8_t index =
            (uint8_t)((model->write_order_head + offset) %
                      NPU_GC_AXI_WRITE_ORDER_DEPTH);
        uint8_t candidate = model->write_order[index];
        if (candidate != slot) {
            retained[retained_count] = candidate;
            retained_count++;
        }
    }
    (void)memset(model->write_order, 0,
                 sizeof(model->write_order));
    for (offset = 0u; offset < retained_count; offset++) {
        model->write_order[offset] = retained[offset];
    }
    model->write_order_head = 0u;
    model->write_order_tail =
        (uint8_t)(retained_count %
                  NPU_GC_AXI_WRITE_ORDER_DEPTH);
    model->write_order_count = retained_count;
    return removed_head;
}

static void gc_finish_discarded_write(
    npu_gc_axi_cycle_t *model,
    uint8_t slot)
{
    npu_gc_axi_write_entry_t *request;

    if (slot >= NPU_GC_AXI_WRITE_OUTSTANDING) {
        return;
    }
    request = &model->write[slot];
    if (request->valid == 0u ||
        request->discard_write_data == 0u ||
        request->total_write_beats_accepted <
            request->total_beats ||
        (model->w_hold.valid != 0u &&
         model->w_hold.request_slot == slot)) {
        return;
    }

    (void)gc_write_order_remove(model, slot);
    request->discard_write_data = 0u;
    request->child_active = 0u;
    request->addr_sent = 0u;
    request->w_done = 0u;
    request->response_pending = 1u;
}

static uint8_t gc_count_read_requests(
    const npu_gc_axi_cycle_t *model)
{
    return (uint8_t)(NPU_GC_AXI_READ_OUTSTANDING -
                     gc_count_free_reads(model));
}

static uint8_t gc_count_write_requests(
    const npu_gc_axi_cycle_t *model)
{
    return (uint8_t)(NPU_GC_AXI_WRITE_OUTSTANDING -
                     gc_count_free_writes(model));
}

static uint8_t gc_count_read_axi(
    const npu_gc_axi_cycle_t *model)
{
    uint8_t count = 0u;
    uint8_t index;

    for (index = 0u; index < NPU_GC_AXI_READ_OUTSTANDING;
         index++) {
        if (model->read[index].valid != 0u &&
            model->read[index].child_active != 0u &&
            model->read[index].addr_sent != 0u) {
            count++;
        }
    }
    return count;
}

static uint8_t gc_count_write_axi(
    const npu_gc_axi_cycle_t *model)
{
    uint8_t count = 0u;
    uint8_t index;

    for (index = 0u; index < NPU_GC_AXI_WRITE_OUTSTANDING;
         index++) {
        if (model->write[index].valid != 0u &&
            model->write[index].child_active != 0u &&
            model->write[index].addr_sent != 0u) {
            count++;
        }
    }
    return count;
}

uint8_t npu_gc_axi_cycle_is_idle(
    const npu_gc_axi_cycle_t *model)
{
    if (model == NULL ||
        model->icache_rsp_hold.valid != 0u ||
        model->dcache_read_rsp_hold.valid != 0u ||
        model->dcache_write_rsp_hold.valid != 0u ||
        model->ar_hold != NPU_GC_AXI_INVALID_SLOT ||
        model->aw_hold != NPU_GC_AXI_INVALID_SLOT ||
        model->w_hold.valid != 0u ||
        model->b_entry.valid != 0u ||
        model->r_entry.valid != 0u ||
        model->write_order_count != 0u) {
        return 0u;
    }
    return gc_count_read_requests(model) == 0u &&
                   gc_count_write_requests(model) == 0u
               ? 1u
               : 0u;
}

void npu_gc_axi_cycle_reset(npu_gc_axi_cycle_t *model)
{
    if (model == NULL) {
        return;
    }
    (void)memset(model, 0, sizeof(*model));
    model->ar_hold = NPU_GC_AXI_INVALID_SLOT;
    model->aw_hold = NPU_GC_AXI_INVALID_SLOT;
    model->next_write_id = NPU_GC_AXI_WRITE_ID_BASE;
    gc_clear_diagnostics(model);
}

void npu_gc_axi_cycle_init(npu_gc_axi_cycle_t *model)
{
    npu_gc_axi_cycle_reset(model);
}

static void gc_fill_read_response(
    const npu_gc_axi_read_rsp_hold_t *hold,
    npu_gc_axi_read_rsp_t *response)
{
    if (hold->valid == 0u) {
        return;
    }
    response->valid = 1u;
    response->data = hold->data;
    response->tag = hold->tag;
    response->last = hold->last;
    response->status = hold->status;
}

static void gc_fill_request_ready(
    const npu_gc_axi_cycle_t *model,
    const npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs)
{
    uint8_t free_reads;

    if (inputs->quiesce != 0u) {
        return;
    }
    free_reads = gc_count_free_reads(model);
    if (free_reads >= NPU_GC_AXI_CLIENT_COUNT) {
        outputs->icache_req_ready = 1u;
        outputs->dcache_read_req_ready = 1u;
    } else if (free_reads == 1u) {
        if (model->read_req_rr_client ==
            NPU_GC_AXI_CLIENT_ICACHE) {
            outputs->icache_req_ready = 1u;
        } else {
            outputs->dcache_read_req_ready = 1u;
        }
    }
    if (gc_count_free_writes(model) != 0u) {
        outputs->dcache_write_req_ready = 1u;
    }
}

static void gc_fill_write_data_ready(
    const npu_gc_axi_cycle_t *model,
    npu_gc_axi_cycle_outputs_t *outputs)
{
    uint8_t slot = gc_write_order_head(model);
    const npu_gc_axi_write_entry_t *request;

    if (slot == NPU_GC_AXI_INVALID_SLOT ||
        slot >= NPU_GC_AXI_WRITE_OUTSTANDING) {
        return;
    }
    request = &model->write[slot];
    if (request->valid == 0u) {
        return;
    }
    outputs->dcache_write_data_tag = request->tag;
    if (model->w_hold.valid != 0u) {
        return;
    }
    if (request->discard_write_data != 0u) {
        if (request->total_write_beats_accepted <
            request->total_beats) {
            outputs->dcache_write_data_ready = 1u;
        }
        return;
    }
    if (request->child_active != 0u &&
        request->addr_sent != 0u &&
        request->w_done == 0u &&
        request->child_write_beats_accepted <
            request->child_beats) {
        outputs->dcache_write_data_ready = 1u;
    }
}

static void gc_fill_axi_outputs(
    const npu_gc_axi_cycle_t *model,
    npu_gc_axi_bus_outputs_t *axi)
{
    if (model->aw_hold != NPU_GC_AXI_INVALID_SLOT) {
        const npu_gc_axi_write_entry_t *entry =
            &model->write[model->aw_hold];
        axi->awid = entry->axi_id;
        axi->awaddr = entry->next_addr;
        axi->awlen = (uint8_t)(entry->child_beats - 1u);
        axi->awsize = 3u;
        axi->awburst = 1u;
        axi->awlock = 0u;
        axi->awcache = (uint8_t)(entry->cache & 0x0fu);
        axi->awprot = (uint8_t)(entry->prot & 0x07u);
        axi->awqos = 0u;
        axi->awvalid = 1u;
    }

    if (model->w_hold.valid != 0u) {
        axi->wdata = model->w_hold.data;
        axi->wstrb = model->w_hold.strb;
        axi->wlast = model->w_hold.last;
        axi->wvalid = 1u;
    }
    axi->bready = model->b_entry.valid == 0u ? 1u : 0u;

    if (model->ar_hold != NPU_GC_AXI_INVALID_SLOT) {
        const npu_gc_axi_read_entry_t *entry =
            &model->read[model->ar_hold];
        axi->arid = entry->axi_id;
        axi->araddr = entry->next_addr;
        axi->arlen = (uint8_t)(entry->child_beats - 1u);
        axi->arsize = 3u;
        axi->arburst = 1u;
        axi->arlock = 0u;
        axi->arcache = (uint8_t)(entry->cache & 0x0fu);
        axi->arprot = (uint8_t)(entry->prot & 0x07u);
        axi->arqos = 0u;
        axi->arvalid = 1u;
    }
    axi->rready = model->r_entry.valid == 0u ? 1u : 0u;
}

static void gc_fill_outputs(
    const npu_gc_axi_cycle_t *model,
    const npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs)
{
    (void)memset(outputs, 0, sizeof(*outputs));
    gc_fill_request_ready(model, inputs, outputs);
    gc_fill_write_data_ready(model, outputs);
    gc_fill_read_response(&model->icache_rsp_hold,
                          &outputs->icache_rsp);
    gc_fill_read_response(&model->dcache_read_rsp_hold,
                          &outputs->dcache_read_rsp);
    if (model->dcache_write_rsp_hold.valid != 0u) {
        outputs->dcache_write_rsp.valid = 1u;
        outputs->dcache_write_rsp.tag =
            model->dcache_write_rsp_hold.tag;
        outputs->dcache_write_rsp.status =
            model->dcache_write_rsp_hold.status;
    }
    gc_fill_axi_outputs(model, &outputs->axi);

    outputs->idle = npu_gc_axi_cycle_is_idle(model);
    outputs->quiescent = outputs->idle;
    outputs->read_requests_used =
        gc_count_read_requests(model);
    outputs->write_requests_used =
        gc_count_write_requests(model);
    outputs->read_axi_outstanding =
        gc_count_read_axi(model);
    outputs->write_axi_outstanding =
        gc_count_write_axi(model);

    outputs->first_error_valid = model->first_error_valid;
    outputs->first_error_status = model->first_error_status;
    outputs->first_error_client = model->first_error_client;
    outputs->first_error_tag = model->first_error_tag;
    outputs->first_error_addr = model->first_error_addr;
    outputs->first_error_axi_id =
        model->first_error_axi_id;
    outputs->first_error_axi_id_valid =
        model->first_error_axi_id_valid;
    outputs->first_error_axi_resp =
        model->first_error_axi_resp;
    outputs->protocol_error_valid =
        model->protocol_error_valid;
    outputs->protocol_error_kind =
        model->protocol_error_kind;
    outputs->protocol_error_addr =
        model->protocol_error_addr;
    outputs->protocol_error_client =
        model->protocol_error_client;
    outputs->protocol_error_tag =
        model->protocol_error_tag;
    outputs->protocol_error_axi_id =
        model->protocol_error_axi_id;
    outputs->protocol_error_axi_id_valid =
        model->protocol_error_axi_id_valid;
    outputs->cycle_count = model->cycle_count;
}

static void gc_consume_read_hold(
    npu_gc_axi_cycle_t *model,
    npu_gc_axi_read_rsp_hold_t *hold,
    uint8_t ready)
{
    if (hold->valid != 0u && ready != 0u) {
        uint8_t slot = hold->request_slot;
        uint8_t final = hold->final;
        (void)memset(hold, 0, sizeof(*hold));
        if (final != 0u &&
            slot < NPU_GC_AXI_READ_OUTSTANDING) {
            if (model->read[slot].drain_rlast != 0u) {
                model->read[slot].response_held = 0u;
            } else {
                (void)memset(&model->read[slot], 0,
                             sizeof(model->read[slot]));
            }
        }
    }
}

static void gc_consume_internal_responses(
    npu_gc_axi_cycle_t *model,
    const npu_gc_axi_cycle_inputs_t *inputs)
{
    gc_consume_read_hold(model, &model->icache_rsp_hold,
                         inputs->icache_rsp_ready);
    gc_consume_read_hold(model,
                         &model->dcache_read_rsp_hold,
                         inputs->dcache_read_rsp_ready);

    if (model->dcache_write_rsp_hold.valid != 0u &&
        inputs->dcache_write_rsp_ready != 0u) {
        uint8_t slot =
            model->dcache_write_rsp_hold.request_slot;
        (void)memset(&model->dcache_write_rsp_hold, 0,
                     sizeof(model->dcache_write_rsp_hold));
        if (slot < NPU_GC_AXI_WRITE_OUTSTANDING) {
            (void)memset(&model->write[slot], 0,
                         sizeof(model->write[slot]));
        }
    }
}

static void gc_capture_axi_responses(
    npu_gc_axi_cycle_t *model,
    const npu_gc_axi_cycle_inputs_t *inputs,
    const npu_gc_axi_cycle_outputs_t *outputs)
{
    if (inputs->axi.bvalid != 0u &&
        outputs->axi.bready != 0u) {
        model->b_entry.valid = 1u;
        model->b_entry.id = inputs->axi.bid;
        model->b_entry.resp = inputs->axi.bresp;
    }
    if (inputs->axi.rvalid != 0u &&
        outputs->axi.rready != 0u) {
        model->r_entry.valid = 1u;
        model->r_entry.id = inputs->axi.rid;
        model->r_entry.data = inputs->axi.rdata;
        model->r_entry.resp = inputs->axi.rresp;
        model->r_entry.last =
            inputs->axi.rlast != 0u ? 1u : 0u;
    }
}

static void gc_process_r_entry(npu_gc_axi_cycle_t *model)
{
    npu_gc_axi_r_entry_t *incoming = &model->r_entry;
    uint8_t slot;
    npu_gc_axi_read_entry_t *request;
    npu_gc_axi_read_rsp_hold_t *hold;
    uint8_t expected_last;
    uint8_t actual_last;
    uint8_t burst_end;
    uint8_t final;
    uint8_t exact_success;
    uint8_t missing_rlast;
    uint64_t beat_addr;

    if (incoming->valid == 0u) {
        return;
    }
    slot = gc_find_read_id(model, incoming->id);
    if (slot == NPU_GC_AXI_INVALID_SLOT) {
        gc_mark_bus_protocol(
            model, NPU_GC_AXI_PROTOCOL_RID, incoming->id);
        (void)memset(incoming, 0, sizeof(*incoming));
        return;
    }
    request = &model->read[slot];
    if (request->addr_sent == 0u) {
        gc_mark_bus_protocol(
            model, NPU_GC_AXI_PROTOCOL_RID, incoming->id);
        (void)memset(incoming, 0, sizeof(*incoming));
        return;
    }
    if (request->drain_rlast != 0u) {
        if (incoming->last != 0u) {
            request->drain_rlast = 0u;
            request->child_active = 0u;
            request->addr_sent = 0u;
            if (request->response_held == 0u) {
                (void)memset(request, 0, sizeof(*request));
            }
        }
        (void)memset(incoming, 0, sizeof(*incoming));
        return;
    }
    hold = gc_read_hold(model, request->client);
    if (hold->valid != 0u) {
        return;
    }

    expected_last =
        (uint16_t)(request->child_beats_done + 1u) ==
                request->child_beats
            ? 1u
            : 0u;
    actual_last = incoming->last;
    missing_rlast =
        expected_last != 0u && actual_last == 0u ? 1u : 0u;
    beat_addr =
        request->next_addr +
        (uint64_t)request->child_beats_done * UINT64_C(8);

    if (incoming->resp == NPU_GC_AXI_RESP_EXOKAY ||
        incoming->resp > NPU_GC_AXI_RESP_DECERR) {
        gc_mark_protocol_error(
            model, NPU_GC_AXI_PROTOCOL_RRESP,
            beat_addr, request->client, request->tag, 1u,
            incoming->id);
    }
    if (incoming->resp != NPU_GC_AXI_RESP_OKAY &&
        request->status == NPU_STATUS_SUCCESS) {
        request->status = gc_axi_status(incoming->resp);
        gc_record_first_error(
            model, request->status, request->client,
            request->tag, beat_addr, 1u, incoming->id,
            incoming->resp);
    }
    if (actual_last != expected_last) {
        gc_mark_protocol_error(
            model, NPU_GC_AXI_PROTOCOL_RLAST,
            beat_addr, request->client, request->tag, 1u,
            incoming->id);
        if (request->status == NPU_STATUS_SUCCESS) {
            request->status = NPU_STATUS_BUS_SLVERR;
            gc_record_first_error(
                model, request->status, request->client,
                request->tag, beat_addr, 1u, incoming->id,
                incoming->resp);
        }
    }

    burst_end =
        actual_last != 0u || expected_last != 0u ? 1u : 0u;
    final =
        burst_end != 0u &&
                (request->status != NPU_STATUS_SUCCESS ||
                 request->remaining_beats ==
                     request->child_beats)
            ? 1u
            : 0u;

    hold->valid = 1u;
    hold->request_slot = slot;
    hold->final = final;
    hold->data = incoming->data;
    hold->tag = request->tag;
    hold->last = final;
    hold->status = request->status;

    request->child_beats_done++;
    if (burst_end != 0u) {
        exact_success =
            request->status == NPU_STATUS_SUCCESS &&
                    actual_last != 0u &&
                    expected_last != 0u
                ? 1u
                : 0u;
        if (missing_rlast != 0u) {
            request->drain_rlast = 1u;
            request->response_held = 1u;
        } else if (exact_success != 0u) {
            uint16_t completed = request->child_beats;
            request->remaining_beats =
                (uint16_t)(request->remaining_beats -
                           completed);
            request->next_addr +=
                (uint64_t)completed * UINT64_C(8);
            request->child_active = 0u;
            request->addr_sent = 0u;
            request->child_beats = 0u;
            request->child_beats_done = 0u;
            if (request->remaining_beats == 0u) {
                request->response_held = 1u;
            }
        } else {
            request->child_active = 0u;
            request->response_held = 1u;
        }
    }
    (void)memset(incoming, 0, sizeof(*incoming));
}

static void gc_fail_early_b(
    npu_gc_axi_cycle_t *model,
    uint8_t slot,
    uint8_t axi_response)
{
    npu_gc_axi_write_entry_t *request =
        &model->write[slot];

    gc_mark_protocol_error(
        model, NPU_GC_AXI_PROTOCOL_BID,
        request->next_addr,
        NPU_GC_AXI_CLIENT_DCACHE, request->tag,
        1u, request->axi_id);
    if (request->status == NPU_STATUS_SUCCESS) {
        request->status = NPU_STATUS_BUS_SLVERR;
        gc_record_first_error(
            model, request->status,
            NPU_GC_AXI_CLIENT_DCACHE, request->tag,
            request->next_addr, 1u, request->axi_id,
            axi_response);
    }
    request->discard_write_data = 1u;
    request->child_active = 0u;
    request->addr_sent = 0u;
    request->w_done = 0u;
    gc_finish_discarded_write(model, slot);
}

static void gc_process_b_entry(npu_gc_axi_cycle_t *model)
{
    npu_gc_axi_b_entry_t *incoming = &model->b_entry;
    uint8_t slot;
    npu_gc_axi_write_entry_t *request;
    uint16_t completed;

    if (incoming->valid == 0u) {
        return;
    }
    slot = gc_find_write_id(model, incoming->id);
    if (slot == NPU_GC_AXI_INVALID_SLOT) {
        gc_mark_bus_protocol(
            model, NPU_GC_AXI_PROTOCOL_BID, incoming->id);
        (void)memset(incoming, 0, sizeof(*incoming));
        return;
    }
    request = &model->write[slot];
    if (request->addr_sent == 0u) {
        gc_mark_bus_protocol(
            model, NPU_GC_AXI_PROTOCOL_BID, incoming->id);
        (void)memset(incoming, 0, sizeof(*incoming));
        return;
    }
    if (request->w_done == 0u) {
        gc_fail_early_b(model, slot, incoming->resp);
        (void)memset(incoming, 0, sizeof(*incoming));
        return;
    }

    if (incoming->resp == NPU_GC_AXI_RESP_EXOKAY ||
        incoming->resp > NPU_GC_AXI_RESP_DECERR) {
        gc_mark_protocol_error(
            model, NPU_GC_AXI_PROTOCOL_BRESP,
            request->next_addr,
            NPU_GC_AXI_CLIENT_DCACHE, request->tag,
            1u, incoming->id);
    }
    if (incoming->resp != NPU_GC_AXI_RESP_OKAY &&
        request->status == NPU_STATUS_SUCCESS) {
        request->status = gc_axi_status(incoming->resp);
        gc_record_first_error(
            model, request->status,
            NPU_GC_AXI_CLIENT_DCACHE, request->tag,
            request->next_addr, 1u, incoming->id,
            incoming->resp);
    }

    completed = request->child_beats;
    request->child_active = 0u;
    request->addr_sent = 0u;
    request->w_done = 0u;
    request->child_beats = 0u;
    request->child_write_beats_accepted = 0u;
    request->child_write_beats_sent = 0u;
    if (request->status == NPU_STATUS_SUCCESS) {
        request->remaining_beats =
            (uint16_t)(request->remaining_beats - completed);
        request->next_addr +=
            (uint64_t)completed * UINT64_C(8);
        if (request->remaining_beats == 0u) {
            request->response_pending = 1u;
        }
    } else {
        request->response_pending = 1u;
    }
    (void)memset(incoming, 0, sizeof(*incoming));
}

static void gc_process_axi_addresses(
    npu_gc_axi_cycle_t *model,
    const npu_gc_axi_cycle_inputs_t *inputs,
    const npu_gc_axi_cycle_outputs_t *outputs)
{
    if (outputs->axi.arvalid != 0u &&
        inputs->axi.arready != 0u) {
        uint8_t slot = model->ar_hold;
        model->read[slot].addr_sent = 1u;
        model->ar_hold = NPU_GC_AXI_INVALID_SLOT;
    }
    if (outputs->axi.awvalid != 0u &&
        inputs->axi.awready != 0u) {
        uint8_t slot = model->aw_hold;
        model->write[slot].addr_sent = 1u;
        gc_write_order_push(model, slot);
        model->aw_hold = NPU_GC_AXI_INVALID_SLOT;
    }
}

static void gc_process_axi_write_data(
    npu_gc_axi_cycle_t *model,
    const npu_gc_axi_cycle_inputs_t *inputs,
    const npu_gc_axi_cycle_outputs_t *outputs)
{
    if (outputs->axi.wvalid != 0u &&
        inputs->axi.wready != 0u &&
        model->w_hold.valid != 0u) {
        uint8_t slot = model->w_hold.request_slot;
        npu_gc_axi_write_entry_t *request =
            &model->write[slot];
        if (request->discard_write_data == 0u) {
            request->child_write_beats_sent++;
            if (model->w_hold.last != 0u) {
                request->w_done = 1u;
                if (gc_write_order_head(model) == slot) {
                    gc_write_order_pop(model);
                }
            }
        }
        (void)memset(&model->w_hold, 0,
                     sizeof(model->w_hold));
        gc_finish_discarded_write(model, slot);
    }
}

static void gc_accept_internal_write_data(
    npu_gc_axi_cycle_t *model,
    const npu_gc_axi_cycle_inputs_t *inputs,
    const npu_gc_axi_cycle_outputs_t *outputs)
{
    uint8_t slot;
    npu_gc_axi_write_entry_t *request;
    uint8_t expected_last;
    uint8_t child_last;
    uint64_t beat_addr;

    if (inputs->dcache_write_data.valid == 0u ||
        outputs->dcache_write_data_ready == 0u) {
        return;
    }
    slot = gc_write_order_head(model);
    if (slot >= NPU_GC_AXI_WRITE_OUTSTANDING) {
        return;
    }
    request = &model->write[slot];
    beat_addr =
        request->first_addr +
        (uint64_t)request->total_write_beats_accepted *
            UINT64_C(8);
    expected_last =
        (uint16_t)(request->total_write_beats_accepted + 1u) ==
                request->total_beats
            ? 1u
            : 0u;
    child_last =
        (uint16_t)(request->child_write_beats_accepted + 1u) ==
                request->child_beats
            ? 1u
            : 0u;

    if (inputs->dcache_write_data.tag != request->tag) {
        gc_mark_protocol_error(
            model, NPU_GC_AXI_PROTOCOL_WTAG,
            beat_addr,
            NPU_GC_AXI_CLIENT_DCACHE,
            inputs->dcache_write_data.tag,
            1u, request->axi_id);
        if (request->status == NPU_STATUS_SUCCESS) {
            request->status = NPU_STATUS_BUS_SLVERR;
            gc_record_first_error(
                model, request->status,
                NPU_GC_AXI_CLIENT_DCACHE, request->tag,
                request->next_addr, 1u,
                request->axi_id, 0u);
        }
    }
    if ((inputs->dcache_write_data.last != 0u ? 1u : 0u) !=
        expected_last) {
        gc_mark_protocol_error(
            model, NPU_GC_AXI_PROTOCOL_WLAST,
            beat_addr,
            NPU_GC_AXI_CLIENT_DCACHE, request->tag,
            1u, request->axi_id);
        if (request->status == NPU_STATUS_SUCCESS) {
            request->status = NPU_STATUS_BUS_SLVERR;
            gc_record_first_error(
                model, request->status,
                NPU_GC_AXI_CLIENT_DCACHE, request->tag,
                request->next_addr, 1u,
                request->axi_id, 0u);
        }
    }

    if (request->discard_write_data != 0u) {
        request->total_write_beats_accepted++;
        gc_finish_discarded_write(model, slot);
        return;
    }

    model->w_hold.valid = 1u;
    model->w_hold.request_slot = slot;
    model->w_hold.data = inputs->dcache_write_data.data;
    model->w_hold.strb = inputs->dcache_write_data.strb;
    model->w_hold.last = child_last;
    request->child_write_beats_accepted++;
    request->total_write_beats_accepted++;
}

static void gc_fail_read_request(
    npu_gc_axi_cycle_t *model,
    npu_gc_axi_read_entry_t *entry,
    uint8_t status)
{
    entry->status = status;
    entry->response_pending = 1u;
    gc_record_first_error(
        model, status, entry->client, entry->tag,
        entry->first_addr, 0u,
        NPU_GC_AXI_INVALID_SLOT, 0u);
}

static void gc_accept_read_request(
    npu_gc_axi_cycle_t *model,
    const npu_gc_axi_read_req_t *input,
    uint8_t client)
{
    uint8_t slot = gc_find_free_read(model);
    uint8_t duplicate =
        gc_read_tag_active(model, client, input->tag);
    uint8_t request_status =
        gc_request_status(input->addr, input->beats,
                          input->cache, input->prot,
                          input->qos);
    npu_gc_axi_read_entry_t *entry;

    if (slot == NPU_GC_AXI_INVALID_SLOT) {
        return;
    }
    entry = &model->read[slot];
    (void)memset(entry, 0, sizeof(*entry));
    entry->valid = 1u;
    entry->client = client;
    entry->tag = input->tag;
    entry->status = NPU_STATUS_SUCCESS;
    entry->first_addr = input->addr;
    entry->next_addr = input->addr;
    entry->total_beats = (uint16_t)input->beats + 1u;
    entry->remaining_beats = entry->total_beats;
    entry->cache = input->cache;
    entry->prot = input->prot;
    entry->qos = input->qos;

    if (duplicate != 0u) {
        gc_mark_protocol_error(
            model, NPU_GC_AXI_PROTOCOL_DUPLICATE_TAG,
            input->addr, client, input->tag, 0u,
            NPU_GC_AXI_INVALID_SLOT);
        gc_fail_read_request(model, entry, NPU_STATUS_BAD_DESC);
    } else if (request_status != NPU_STATUS_SUCCESS) {
        gc_fail_read_request(model, entry, request_status);
    }
}

static void gc_accept_write_request(
    npu_gc_axi_cycle_t *model,
    const npu_gc_axi_write_req_t *input)
{
    uint8_t slot = gc_find_free_write(model);
    uint8_t duplicate =
        gc_write_tag_active(model, input->tag);
    uint8_t request_status =
        gc_request_status(input->addr, input->beats,
                          input->cache, input->prot,
                          input->qos);
    npu_gc_axi_write_entry_t *entry;

    if (slot == NPU_GC_AXI_INVALID_SLOT) {
        return;
    }
    entry = &model->write[slot];
    (void)memset(entry, 0, sizeof(*entry));
    entry->valid = 1u;
    entry->tag = input->tag;
    entry->status = NPU_STATUS_SUCCESS;
    entry->first_addr = input->addr;
    entry->next_addr = input->addr;
    entry->total_beats = (uint16_t)input->beats + 1u;
    entry->remaining_beats = entry->total_beats;
    entry->cache = input->cache;
    entry->prot = input->prot;
    entry->qos = input->qos;

    if (duplicate != 0u) {
        gc_mark_protocol_error(
            model, NPU_GC_AXI_PROTOCOL_DUPLICATE_TAG,
            input->addr,
            NPU_GC_AXI_CLIENT_DCACHE, input->tag,
            0u, NPU_GC_AXI_INVALID_SLOT);
        entry->status = NPU_STATUS_BAD_DESC;
        entry->response_pending = 1u;
        gc_record_first_error(
            model, entry->status,
            NPU_GC_AXI_CLIENT_DCACHE, entry->tag,
            entry->first_addr, 0u,
            NPU_GC_AXI_INVALID_SLOT, 0u);
    } else if (request_status != NPU_STATUS_SUCCESS) {
        entry->status = request_status;
        entry->response_pending = 1u;
        gc_record_first_error(
            model, entry->status,
            NPU_GC_AXI_CLIENT_DCACHE, entry->tag,
            entry->first_addr, 0u,
            NPU_GC_AXI_INVALID_SLOT, 0u);
    }
}

static void gc_accept_internal_requests(
    npu_gc_axi_cycle_t *model,
    const npu_gc_axi_cycle_inputs_t *inputs,
    const npu_gc_axi_cycle_outputs_t *outputs)
{
    if (inputs->icache_req.valid != 0u &&
        outputs->icache_req_ready != 0u) {
        gc_accept_read_request(
            model, &inputs->icache_req,
            NPU_GC_AXI_CLIENT_ICACHE);
    }
    if (inputs->dcache_read_req.valid != 0u &&
        outputs->dcache_read_req_ready != 0u) {
        gc_accept_read_request(
            model, &inputs->dcache_read_req,
            NPU_GC_AXI_CLIENT_DCACHE);
    }
    if (inputs->dcache_write_req.valid != 0u &&
        outputs->dcache_write_req_ready != 0u) {
        gc_accept_write_request(
            model, &inputs->dcache_write_req);
    }

    if ((outputs->icache_req_ready != 0u) !=
        (outputs->dcache_read_req_ready != 0u)) {
        model->read_req_rr_client ^= 1u;
    }
}

static void gc_schedule_local_responses(
    npu_gc_axi_cycle_t *model)
{
    uint8_t index;

    for (index = 0u; index < NPU_GC_AXI_READ_OUTSTANDING;
         index++) {
        npu_gc_axi_read_entry_t *entry =
            &model->read[index];
        npu_gc_axi_read_rsp_hold_t *hold;

        if (entry->valid == 0u ||
            entry->response_pending == 0u) {
            continue;
        }
        hold = gc_read_hold(model, entry->client);
        if (hold->valid != 0u) {
            continue;
        }
        hold->valid = 1u;
        hold->request_slot = index;
        hold->final = 1u;
        hold->data = 0u;
        hold->tag = entry->tag;
        hold->last = 1u;
        hold->status = entry->status;
        entry->response_pending = 0u;
        entry->response_held = 1u;
    }

    if (model->dcache_write_rsp_hold.valid == 0u) {
        for (index = 0u;
             index < NPU_GC_AXI_WRITE_OUTSTANDING;
             index++) {
            npu_gc_axi_write_entry_t *entry =
                &model->write[index];
            if (entry->valid == 0u ||
                entry->response_pending == 0u) {
                continue;
            }
            model->dcache_write_rsp_hold.valid = 1u;
            model->dcache_write_rsp_hold.request_slot = index;
            model->dcache_write_rsp_hold.tag = entry->tag;
            model->dcache_write_rsp_hold.status =
                entry->status;
            entry->response_pending = 0u;
            entry->response_held = 1u;
            break;
        }
    }
}

static void gc_schedule_read_child(
    npu_gc_axi_cycle_t *model)
{
    uint8_t offset;

    if (model->ar_hold != NPU_GC_AXI_INVALID_SLOT) {
        return;
    }
    for (offset = 0u; offset < NPU_GC_AXI_READ_OUTSTANDING;
         offset++) {
        uint8_t slot =
            (uint8_t)((model->read_schedule_rr + offset) %
                      NPU_GC_AXI_READ_OUTSTANDING);
        npu_gc_axi_read_entry_t *entry =
            &model->read[slot];
        uint8_t axi_id;

        if (entry->valid == 0u ||
            entry->status != NPU_STATUS_SUCCESS ||
            entry->response_pending != 0u ||
            entry->response_held != 0u ||
            entry->child_active != 0u ||
            entry->remaining_beats == 0u) {
            continue;
        }
        if (gc_allocate_read_id(model, &axi_id) == 0u) {
            return;
        }
        entry->child_active = 1u;
        entry->addr_sent = 0u;
        entry->axi_id = axi_id;
        entry->child_beats =
            gc_child_beats(entry->next_addr,
                           entry->remaining_beats);
        entry->child_beats_done = 0u;
        model->ar_hold = slot;
        model->read_schedule_rr =
            (uint8_t)((slot + 1u) %
                      NPU_GC_AXI_READ_OUTSTANDING);
        return;
    }
}

static void gc_schedule_write_child(
    npu_gc_axi_cycle_t *model)
{
    uint8_t offset;

    if (model->aw_hold != NPU_GC_AXI_INVALID_SLOT) {
        return;
    }
    for (offset = 0u; offset < NPU_GC_AXI_WRITE_OUTSTANDING;
         offset++) {
        uint8_t slot =
            (uint8_t)((model->write_schedule_rr + offset) %
                      NPU_GC_AXI_WRITE_OUTSTANDING);
        npu_gc_axi_write_entry_t *entry =
            &model->write[slot];
        uint8_t axi_id;

        if (entry->valid == 0u ||
            entry->status != NPU_STATUS_SUCCESS ||
            entry->response_pending != 0u ||
            entry->response_held != 0u ||
            entry->child_active != 0u ||
            entry->remaining_beats == 0u) {
            continue;
        }
        if (gc_allocate_write_id(model, &axi_id) == 0u) {
            return;
        }
        entry->child_active = 1u;
        entry->addr_sent = 0u;
        entry->axi_id = axi_id;
        entry->child_beats =
            gc_child_beats(entry->next_addr,
                           entry->remaining_beats);
        entry->child_write_beats_accepted = 0u;
        entry->child_write_beats_sent = 0u;
        entry->w_done = 0u;
        model->aw_hold = slot;
        model->write_schedule_rr =
            (uint8_t)((slot + 1u) %
                      NPU_GC_AXI_WRITE_OUTSTANDING);
        return;
    }
}

void npu_gc_axi_cycle_step(
    npu_gc_axi_cycle_t *model,
    const npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs)
{
    if (outputs == NULL) {
        return;
    }
    (void)memset(outputs, 0, sizeof(*outputs));
    if (model == NULL || inputs == NULL) {
        return;
    }
    if (inputs->reset_n == 0u) {
        npu_gc_axi_cycle_reset(model);
        outputs->idle = 1u;
        outputs->quiescent = 1u;
        return;
    }

    gc_fill_outputs(model, inputs, outputs);
    if (inputs->error_clear != 0u) {
        gc_clear_diagnostics(model);
    }
    gc_consume_internal_responses(model, inputs);
    gc_capture_axi_responses(model, inputs, outputs);
    gc_process_r_entry(model);
    gc_process_b_entry(model);
    gc_process_axi_addresses(model, inputs, outputs);
    gc_process_axi_write_data(model, inputs, outputs);
    gc_accept_internal_write_data(model, inputs, outputs);
    gc_accept_internal_requests(model, inputs, outputs);
    gc_schedule_local_responses(model);
    gc_schedule_read_child(model);
    gc_schedule_write_child(model);
    model->cycle_count++;
}
