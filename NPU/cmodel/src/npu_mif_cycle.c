#include "npu_mif_cycle.h"

#include <stddef.h>
#include <string.h>

static uint16_t mif_min_u16(uint16_t left, uint16_t right)
{
    return left < right ? left : right;
}

static uint8_t mif_request_addr_valid(uint64_t addr,
                                      uint8_t beats_minus_one)
{
    const uint64_t max_aligned_addr =
        NPU_MIF_ADDR_MASK & ~UINT64_C(7);
    const uint64_t last_beat_offset =
        (uint64_t)beats_minus_one * UINT64_C(8);

    return (addr & UINT64_C(7)) == 0u &&
                   addr <= max_aligned_addr - last_beat_offset
               ? 1u
               : 0u;
}

static npu_mif_cycle_config_t mif_effective_config(
    const npu_mif_cycle_t *model,
    const npu_mif_cycle_inputs_t *inputs)
{
    npu_mif_cycle_config_t config = model->config;

    if (inputs->config_valid != 0u) {
        config.system_addr_enable = inputs->system_addr_enable;
        config.system_addr_base = inputs->system_addr_base;
        config.system_addr_limit = inputs->system_addr_limit;
    }
    return config;
}

uint8_t npu_mif_cycle_config_valid(
    const npu_mif_cycle_config_t *config)
{
    if (config == NULL ||
        config->system_addr_enable > 1u ||
        (config->system_addr_base & ~NPU_MIF_ADDR_MASK) != 0u ||
        (config->system_addr_limit & ~NPU_MIF_ADDR_MASK) != 0u ||
        ((config->system_addr_base | config->system_addr_limit) &
         UINT64_C(7)) != 0u ||
        (config->system_addr_enable != 0u &&
         config->system_addr_base > config->system_addr_limit) ||
        config->axi_cache_device > 0x0fu ||
        config->axi_cache_normal_noncache > 0x0fu ||
        config->axi_cache_normal_cacheable > 0x0fu) {
        return 0u;
    }
    return 1u;
}

static uint8_t mif_request_tag_active(const npu_mif_cycle_t *model,
                                      uint8_t owner,
                                      uint16_t tag)
{
    uint8_t index;

    for (index = 0u; index < NPU_MIF_MAX_REQUESTS; index++) {
        const npu_mif_request_entry_t *request =
            &model->requests[index];
        if (request->valid != 0u &&
            request->owner == owner &&
            request->tag == tag) {
            return 1u;
        }
    }
    return 0u;
}

static uint8_t mif_count_free_requests(const npu_mif_cycle_t *model)
{
    uint8_t count = 0u;
    uint8_t index;

    for (index = 0u; index < NPU_MIF_MAX_REQUESTS; index++) {
        if (model->requests[index].valid == 0u) {
            count++;
        }
    }
    return count;
}

static uint8_t mif_find_free_request(const npu_mif_cycle_t *model)
{
    uint8_t index;

    for (index = 0u; index < NPU_MIF_MAX_REQUESTS; index++) {
        if (model->requests[index].valid == 0u) {
            return index;
        }
    }
    return NPU_MIF_INVALID_SLOT;
}

static uint8_t mif_find_free_axi_entry(const npu_mif_cycle_t *model)
{
    uint8_t index;

    for (index = 0u; index < NPU_MIF_MAX_AXI_OUTSTANDING; index++) {
        if (model->axi_entries[index].valid == 0u) {
            return index;
        }
    }
    return NPU_MIF_INVALID_SLOT;
}

static uint8_t mif_axi_id_used(const npu_mif_cycle_t *model,
                               uint8_t axi_id)
{
    uint8_t index;

    for (index = 0u; index < NPU_MIF_MAX_AXI_OUTSTANDING; index++) {
        if (model->axi_entries[index].valid != 0u &&
            model->axi_entries[index].axi_id == axi_id) {
            return 1u;
        }
    }
    return 0u;
}

static uint8_t mif_allocate_axi_id(npu_mif_cycle_t *model,
                                   uint8_t *axi_id)
{
    uint16_t offset;

    for (offset = 0u; offset < 256u; offset++) {
        uint8_t candidate =
            (uint8_t)((uint16_t)model->next_axi_id + offset);
        if (mif_axi_id_used(model, candidate) == 0u) {
            *axi_id = candidate;
            model->next_axi_id = (uint8_t)(candidate + 1u);
            return 1u;
        }
    }
    return 0u;
}

static uint8_t mif_find_axi_id_entry(
    const npu_mif_cycle_t *model,
    uint8_t axi_id)
{
    uint8_t index;

    for (index = 0u; index < NPU_MIF_MAX_AXI_OUTSTANDING;
         index++) {
        const npu_mif_axi_entry_t *entry =
            &model->axi_entries[index];
        if (entry->valid != 0u &&
            entry->axi_id == axi_id) {
            return index;
        }
    }
    return NPU_MIF_INVALID_SLOT;
}

static uint8_t mif_cache_value(
                               const npu_mif_cycle_config_t *config,
                               uint8_t attr)
{
    uint8_t mode =
        (uint8_t)((attr & NPU_MIF_ATTR_CACHE_MASK) >>
                  NPU_MIF_ATTR_CACHE_SHIFT);

    if (mode == 0u) {
        return config->axi_cache_device;
    }
    if (mode == 1u) {
        return config->axi_cache_normal_noncache;
    }
    return config->axi_cache_normal_cacheable;
}

static uint8_t mif_prot_value(uint8_t attr)
{
    return (uint8_t)((attr >> 3) & 0x7u);
}

static uint8_t mif_qos_value(uint8_t attr)
{
    return (uint8_t)((attr & NPU_MIF_ATTR_QOS_MASK) >>
                     NPU_MIF_ATTR_QOS_SHIFT);
}

static uint8_t mif_axi_status(uint8_t response)
{
    if (response == NPU_MIF_AXI_RESP_OKAY) {
        return NPU_STATUS_SUCCESS;
    }
    if (response == NPU_MIF_AXI_RESP_DECERR) {
        return NPU_STATUS_BUS_DECERR;
    }
    return NPU_STATUS_BUS_SLVERR;
}

static void mif_record_first_error(npu_mif_cycle_t *model,
                                   const npu_mif_request_entry_t *request,
                                   uint8_t status,
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
    model->first_error_owner = request->owner;
    model->first_error_tag = request->tag;
    model->first_error_task_id = request->task_id;
    model->first_error_addr = addr;
    model->first_error_axi_id_valid = axi_id_valid;
    model->first_error_axi_id = axi_id;
    model->first_error_axi_resp = axi_response;
}

static void mif_mark_protocol_error(npu_mif_cycle_t *model,
                                    uint8_t kind,
                                    uint64_t addr,
                                    uint8_t owner,
                                    uint16_t tag,
                                    uint8_t has_task_identity,
                                    uint16_t task_id)
{
    if (model->protocol_error_valid == 0u) {
        model->protocol_error_valid = 1u;
        model->protocol_error_kind = kind;
        model->protocol_error_addr = addr;
        model->protocol_error_owner = owner;
        model->protocol_error_tag = tag;
        model->protocol_error_has_task_identity =
            has_task_identity;
        model->protocol_error_task_id =
            has_task_identity != 0u
                ? (uint16_t)(task_id & 0x0fffu)
                : 0u;
    }
}

static void mif_mark_request_protocol_error(
    npu_mif_cycle_t *model,
    uint8_t kind,
    const npu_mif_request_entry_t *request,
    uint64_t addr)
{
    mif_mark_protocol_error(
        model, kind, addr, request->owner, request->tag,
        1u, request->task_id);
}

static void mif_clear_diagnostics(npu_mif_cycle_t *model)
{
    model->first_error_valid = 0u;
    model->first_error_status = 0u;
    model->first_error_owner = 0u;
    model->first_error_tag = 0u;
    model->first_error_task_id = 0u;
    model->first_error_addr = 0u;
    model->first_error_axi_id = NPU_MIF_INVALID_AXI_ID;
    model->first_error_axi_id_valid = 0u;
    model->first_error_axi_resp = 0u;
    model->protocol_error_valid = 0u;
    model->protocol_error_kind = NPU_MIF_PROTOCOL_NONE;
    model->protocol_error_addr = 0u;
    model->protocol_error_owner = 0u;
    model->protocol_error_tag = 0u;
    model->protocol_error_has_task_identity = 0u;
    model->protocol_error_task_id = 0u;
}

static uint8_t mif_axi_request_identity(
    const npu_mif_cycle_t *model,
    uint8_t out_slot,
    uint8_t *owner,
    uint16_t *tag)
{
    const npu_mif_axi_entry_t *entry;
    const npu_mif_request_entry_t *request;

    if (out_slot >= NPU_MIF_MAX_AXI_OUTSTANDING) {
        return 0u;
    }
    entry = &model->axi_entries[out_slot];
    if (entry->valid == 0u ||
        entry->req_slot >= NPU_MIF_MAX_REQUESTS) {
        return 0u;
    }
    request = &model->requests[entry->req_slot];
    if (request->valid == 0u ||
        request->owner >= NPU_MIF_OWNER_COUNT) {
        return 0u;
    }
    *owner = request->owner;
    *tag = request->tag;
    return 1u;
}

/*
 * AXI supplies only an 8-bit ID. For an unmatched response there is no safe
 * way to infer an internal owner or tag, so the diagnostic uses owner 0xff
 * and zero-extends the AXI ID into the tag field. If an active entry with
 * that ID exists, its checked request identity is used instead.
 */
static void mif_mark_axi_protocol_error(
    npu_mif_cycle_t *model,
    uint8_t kind,
    uint8_t axi_id,
    uint64_t addr)
{
    uint8_t out_slot =
        mif_find_axi_id_entry(model, axi_id);
    uint8_t owner = NPU_MIF_INVALID_OWNER;
    uint16_t tag = axi_id;
    uint8_t has_task_identity = 0u;
    uint16_t task_id = 0u;

    if (mif_axi_request_identity(model, out_slot,
                                 &owner, &tag) != 0u) {
        const npu_mif_axi_entry_t *entry =
            &model->axi_entries[out_slot];
        const npu_mif_request_entry_t *request =
            &model->requests[entry->req_slot];

        has_task_identity = 1u;
        task_id = request->task_id;
        if (addr == 0u) {
            addr = entry->addr;
        }
    }
    mif_mark_protocol_error(
        model, kind, addr, owner, tag,
        has_task_identity, task_id);
}

static void mif_fail_request(npu_mif_cycle_t *model,
                             uint8_t request_slot,
                             uint8_t status,
                             uint64_t addr,
                             uint8_t axi_id_valid,
                             uint8_t axi_id,
                             uint8_t axi_response)
{
    npu_mif_request_entry_t *request =
        &model->requests[request_slot];

    if (request->status == NPU_STATUS_SUCCESS) {
        request->status = status;
        mif_record_first_error(
            model, request, status, addr,
            axi_id_valid, axi_id, axi_response);
    }
    request->phase = NPU_MIF_REQ_RESPONSE_PENDING;
}

static uint8_t mif_system_region_beats(
    const npu_mif_cycle_config_t *config,
    uint64_t addr,
    uint16_t *region_beats)
{
    uint64_t bytes;

    if ((addr & ~NPU_MIF_ADDR_MASK) != 0u ||
        (addr & UINT64_C(7)) != 0u) {
        return 0u;
    }

    if (config->system_addr_enable != 0u &&
        addr >= config->system_addr_base &&
        addr <= config->system_addr_limit) {
        bytes =
            config->system_addr_limit - addr + UINT64_C(8);
        *region_beats =
            bytes / UINT64_C(8) > UINT16_MAX
                ? UINT16_MAX
                : (uint16_t)(bytes / UINT64_C(8));
        return 1u;
    }

    return 0u;
}

static void mif_advance_request(npu_mif_request_entry_t *request,
                                uint16_t beats)
{
    uint64_t bytes = (uint64_t)beats * UINT64_C(8);

    request->next_addr += bytes;
    request->remaining_beats =
        (uint16_t)(request->remaining_beats - beats);

    if (request->remaining_beats != 0u) {
        request->phase = NPU_MIF_REQ_READY_BURST;
    }
}

static void mif_release_request(npu_mif_cycle_t *model,
                                uint8_t request_slot)
{
    (void)memset(&model->requests[request_slot], 0,
                 sizeof(model->requests[request_slot]));
}

static void mif_clear_axi_entry(npu_mif_cycle_t *model,
                                uint8_t out_slot)
{
    (void)memset(&model->axi_entries[out_slot], 0,
                 sizeof(model->axi_entries[out_slot]));
}

static uint8_t mif_write_fifo_head(const npu_mif_cycle_t *model)
{
    if (model->write_fifo_count == 0u) {
        return NPU_MIF_INVALID_SLOT;
    }
    return model->write_fifo[model->write_fifo_head];
}

static void mif_write_fifo_push(npu_mif_cycle_t *model,
                                uint8_t out_slot)
{
    if (model->write_fifo_count >=
        NPU_MIF_MAX_AXI_OUTSTANDING) {
        return;
    }
    model->write_fifo[model->write_fifo_tail] = out_slot;
    model->write_fifo_tail =
        (uint8_t)((model->write_fifo_tail + 1u) %
                  NPU_MIF_MAX_AXI_OUTSTANDING);
    model->write_fifo_count++;
}

static void mif_write_fifo_pop(npu_mif_cycle_t *model)
{
    if (model->write_fifo_count == 0u) {
        return;
    }
    model->write_fifo_head =
        (uint8_t)((model->write_fifo_head + 1u) %
                  NPU_MIF_MAX_AXI_OUTSTANDING);
    model->write_fifo_count--;
}

static void mif_write_fifo_remove(npu_mif_cycle_t *model,
                                  uint8_t out_slot)
{
    uint8_t retained[NPU_MIF_MAX_AXI_OUTSTANDING];
    uint8_t retained_count = 0u;
    uint8_t offset;

    for (offset = 0u; offset < model->write_fifo_count;
         offset++) {
        uint8_t index =
            (uint8_t)((model->write_fifo_head + offset) %
                      NPU_MIF_MAX_AXI_OUTSTANDING);
        uint8_t candidate = model->write_fifo[index];
        if (candidate != out_slot) {
            retained[retained_count] = candidate;
            retained_count++;
        }
    }

    (void)memset(model->write_fifo, 0,
                 sizeof(model->write_fifo));
    for (offset = 0u; offset < retained_count; offset++) {
        model->write_fifo[offset] = retained[offset];
    }
    model->write_fifo_head = 0u;
    model->write_fifo_tail =
        (uint8_t)(retained_count %
                  NPU_MIF_MAX_AXI_OUTSTANDING);
    model->write_fifo_count = retained_count;
}

static void mif_accept_request(npu_mif_cycle_t *model,
                               uint8_t owner,
                               const npu_mif_owner_inputs_t *input,
                               const npu_mif_cycle_config_t *config)
{
    uint8_t request_slot = mif_find_free_request(model);
    npu_mif_request_entry_t *request;
    uint8_t cache_mode;
    uint8_t tag_invalid;
    uint8_t tag_duplicate;

    if (request_slot == NPU_MIF_INVALID_SLOT) {
        return;
    }

    tag_invalid = input->req_tag > 0x0fffu ? 1u : 0u;
    tag_duplicate =
        tag_invalid == 0u &&
                mif_request_tag_active(model, owner,
                                       input->req_tag) != 0u
            ? 1u
            : 0u;

    request = &model->requests[request_slot];
    (void)memset(request, 0, sizeof(*request));
    request->valid = 1u;
    request->phase = NPU_MIF_REQ_READY_BURST;
    request->owner = owner;
    request->write = input->req_write != 0u ? 1u : 0u;
    request->tag = (uint16_t)(input->req_tag & 0x0fffu);
    request->task_id =
        (uint16_t)(input->req_task_id & 0x0fffu);
    request->attr = input->req_attr;
    request->status = NPU_STATUS_SUCCESS;
    request->first_addr = input->req_addr;
    request->next_addr = input->req_addr;
    request->total_beats = (uint16_t)input->req_beats + 1u;
    request->remaining_beats = request->total_beats;
    request->request_config = *config;

    cache_mode =
        (uint8_t)((input->req_attr & NPU_MIF_ATTR_CACHE_MASK) >>
                  NPU_MIF_ATTR_CACHE_SHIFT);

    if (tag_invalid != 0u || tag_duplicate != 0u) {
        mif_mark_protocol_error(
            model,
            tag_invalid != 0u
                ? NPU_MIF_PROTOCOL_REQUEST_TAG_RANGE
                : NPU_MIF_PROTOCOL_REQUEST_TAG_DUPLICATE,
            input->req_addr, owner, input->req_tag,
            input->req_task_id <= 0x0fffu ? 1u : 0u,
            input->req_task_id);
        mif_fail_request(model, request_slot, NPU_STATUS_BAD_DESC,
                         input->req_addr,
                         0u,
                         NPU_MIF_INVALID_AXI_ID, 0u);
        return;
    }

    if (input->req_owner != owner) {
        mif_mark_protocol_error(
            model, NPU_MIF_PROTOCOL_REQUEST_OWNER,
            input->req_addr, owner, input->req_tag,
            input->req_task_id <= 0x0fffu ? 1u : 0u,
            input->req_task_id);
        mif_fail_request(model, request_slot, NPU_STATUS_BAD_DESC,
                         input->req_addr,
                         0u,
                         NPU_MIF_INVALID_AXI_ID, 0u);
        return;
    }

    if (input->req_task_id > 0x0fffu ||
        (input->req_attr & NPU_MIF_ATTR_INSTRUCTION) != 0u ||
        cache_mode == 3u ||
        (owner == NPU_MIF_OWNER_DFU &&
         input->req_write != 0u)) {
        mif_fail_request(model, request_slot, NPU_STATUS_BAD_DESC,
                         input->req_addr,
                         0u,
                         NPU_MIF_INVALID_AXI_ID, 0u);
        return;
    }

    if (mif_request_addr_valid(
            input->req_addr, input->req_beats) == 0u) {
        mif_fail_request(model, request_slot, NPU_STATUS_ADDR_FAULT,
                         input->req_addr,
                         0u,
                         NPU_MIF_INVALID_AXI_ID, 0u);
    }
}

static void mif_schedule_axi(npu_mif_cycle_t *model)
{
    uint8_t offset;

    for (offset = 0u; offset < NPU_MIF_MAX_REQUESTS; offset++) {
        uint8_t request_slot =
            (uint8_t)((model->schedule_rr + offset) %
                      NPU_MIF_MAX_REQUESTS);
        npu_mif_request_entry_t *request =
            &model->requests[request_slot];
        uint16_t region_beats;
        uint16_t page_beats;
        uint16_t burst_beats;
        uint8_t out_slot;
        uint8_t axi_id;
        uint8_t *address_hold;
        npu_mif_axi_entry_t *entry;

        if (request->valid == 0u ||
            request->phase != NPU_MIF_REQ_READY_BURST) {
            continue;
        }

        if (mif_system_region_beats(
                &request->request_config,
                request->next_addr,
                &region_beats) == 0u) {
            mif_fail_request(model, request_slot,
                             NPU_STATUS_ADDR_FAULT,
                             request->next_addr,
                             0u,
                             NPU_MIF_INVALID_AXI_ID, 0u);
            continue;
        }

        address_hold = request->write != 0u
                           ? &model->aw_hold
                           : &model->ar_hold;
        if (*address_hold != NPU_MIF_INVALID_SLOT) {
            continue;
        }

        out_slot = mif_find_free_axi_entry(model);
        if (out_slot == NPU_MIF_INVALID_SLOT ||
            mif_allocate_axi_id(model, &axi_id) == 0u) {
            break;
        }

        page_beats =
            (uint16_t)((UINT64_C(4096) -
                        (request->next_addr &
                         UINT64_C(4095))) /
                       UINT64_C(8));
        burst_beats = mif_min_u16(
            request->remaining_beats,
            NPU_MIF_AXI_MAX_BURST_BEATS);
        burst_beats = mif_min_u16(burst_beats, region_beats);
        burst_beats =
            mif_min_u16(burst_beats, page_beats);

        if (burst_beats == 0u) {
            mif_fail_request(model, request_slot,
                             NPU_STATUS_ADDR_FAULT,
                             request->next_addr,
                             0u,
                             NPU_MIF_INVALID_AXI_ID, 0u);
            continue;
        }

        entry = &model->axi_entries[out_slot];
        (void)memset(entry, 0, sizeof(*entry));
        entry->valid = 1u;
        entry->write = request->write;
        entry->axi_id = axi_id;
        entry->req_slot = request_slot;
        entry->beats = burst_beats;
        entry->addr = request->next_addr;
        entry->attr = request->attr;

        *address_hold = out_slot;
        request->phase = NPU_MIF_REQ_AXI;
    }

    model->schedule_rr =
        (uint8_t)((model->schedule_rr + 1u) %
                  NPU_MIF_MAX_REQUESTS);
}

static void mif_schedule_responses(npu_mif_cycle_t *model)
{
    uint8_t owner;

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        uint8_t index;

        if (model->rsp_hold[owner].valid != 0u) {
            continue;
        }

        for (index = 0u; index < NPU_MIF_MAX_REQUESTS;
             index++) {
            npu_mif_request_entry_t *request =
                &model->requests[index];
            npu_mif_response_hold_t *hold =
                &model->rsp_hold[owner];

            if (request->valid == 0u ||
                request->owner != owner ||
                request->phase !=
                    NPU_MIF_REQ_RESPONSE_PENDING) {
                continue;
            }

            hold->valid = 1u;
            hold->req_slot = index;
            hold->final = 1u;
            hold->data = 0u;
            hold->tag = request->tag;
            hold->is_write = request->write;
            hold->last = 1u;
            hold->status = request->status;
            request->phase = NPU_MIF_REQ_RESPONSE_HELD;
            break;
        }
    }
}

static uint16_t mif_count_axi_outstanding(
    const npu_mif_cycle_t *model,
    uint8_t write)
{
    uint16_t count = 0u;
    uint8_t index;

    for (index = 0u; index < NPU_MIF_MAX_AXI_OUTSTANDING; index++) {
        const npu_mif_axi_entry_t *entry =
            &model->axi_entries[index];
        if (entry->valid != 0u &&
            entry->addr_sent != 0u &&
            entry->write == write) {
            count++;
        }
    }
    return count;
}

static uint8_t mif_count_axi_slots(const npu_mif_cycle_t *model)
{
    uint8_t count = 0u;
    uint8_t index;

    for (index = 0u; index < NPU_MIF_MAX_AXI_OUTSTANDING; index++) {
        if (model->axi_entries[index].valid != 0u) {
            count++;
        }
    }
    return count;
}

uint8_t npu_mif_cycle_is_idle(const npu_mif_cycle_t *model)
{
    uint8_t index;

    if (model == NULL ||
        model->w_input.valid != 0u ||
        model->w_hold.valid != 0u ||
        model->write_fifo_count != 0u) {
        return 0u;
    }

    for (index = 0u; index < NPU_MIF_OWNER_COUNT; index++) {
        if (model->rsp_hold[index].valid != 0u) {
            return 0u;
        }
    }
    if (model->aw_hold != NPU_MIF_INVALID_SLOT ||
        model->ar_hold != NPU_MIF_INVALID_SLOT ||
        model->b_entry.valid != 0u ||
        model->r_entry.valid != 0u) {
        return 0u;
    }
    for (index = 0u; index < NPU_MIF_MAX_REQUESTS; index++) {
        if (model->requests[index].valid != 0u) {
            return 0u;
        }
    }
    for (index = 0u; index < NPU_MIF_MAX_AXI_OUTSTANDING; index++) {
        if (model->axi_entries[index].valid != 0u) {
            return 0u;
        }
    }
    return 1u;
}

static uint8_t mif_response_capacity(
    const npu_mif_cycle_t *model,
    const npu_mif_cycle_inputs_t *inputs,
    uint8_t owner)
{
    return model->rsp_hold[owner].valid == 0u ||
                   inputs->owner[owner].rsp_ready != 0u
               ? 1u
               : 0u;
}

static void mif_fill_owner_outputs(
    const npu_mif_cycle_t *model,
    npu_mif_cycle_outputs_t *outputs)
{
    uint8_t free_requests = mif_count_free_requests(model);
    uint8_t owner;

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        const npu_mif_response_hold_t *hold =
            &model->rsp_hold[owner];
        npu_mif_owner_outputs_t *output =
            &outputs->owner[owner];

        if (hold->valid != 0u) {
            output->rsp_valid = 1u;
            output->rsp_data = hold->data;
            output->rsp_tag = hold->tag;
            output->rsp_is_write = hold->is_write;
            output->rsp_last = hold->last;
            output->rsp_status = hold->status;
        }

        if (free_requests >= NPU_MIF_OWNER_COUNT) {
            output->req_ready = 1u;
        }
    }

    if (free_requests == 1u) {
        uint8_t selected =
            (uint8_t)(model->request_rr_owner %
                      NPU_MIF_OWNER_COUNT);
        outputs->owner[selected].req_ready = 1u;
    }

    if (model->w_input.valid == 0u &&
        model->write_fifo_count != 0u) {
        uint8_t out_slot = mif_write_fifo_head(model);
        const npu_mif_axi_entry_t *entry;
        const npu_mif_request_entry_t *request;
        uint16_t accepted_for_entry;

        if (out_slot >= NPU_MIF_MAX_AXI_OUTSTANDING) {
            return;
        }
        entry = &model->axi_entries[out_slot];
        if (entry->valid == 0u ||
            entry->write == 0u ||
            entry->addr_sent == 0u ||
            entry->req_slot >= NPU_MIF_MAX_REQUESTS) {
            return;
        }
        request = &model->requests[entry->req_slot];
        accepted_for_entry = entry->beats_done;
        if (model->w_hold.valid != 0u &&
            model->w_hold.out_slot == out_slot) {
            accepted_for_entry++;
        }
        if (request->valid != 0u &&
            request->owner < NPU_MIF_OWNER_COUNT &&
            accepted_for_entry < entry->beats) {
            outputs->owner[request->owner].wready = 1u;
        }
    }
}

static void mif_fill_axi_address(
    const npu_mif_cycle_t *model,
    npu_mif_cycle_outputs_t *outputs)
{
    npu_mif_axi_outputs_t *axi = &outputs->axi;
    uint8_t out_slot = model->aw_hold;

    if (out_slot != NPU_MIF_INVALID_SLOT) {
        const npu_mif_axi_entry_t *entry =
            &model->axi_entries[out_slot];
        const npu_mif_request_entry_t *request =
            &model->requests[entry->req_slot];
        axi->awid = entry->axi_id;
        axi->awaddr = entry->addr;
        axi->awlen = (uint8_t)(entry->beats - 1u);
        axi->awsize = 3u;
        axi->awburst = 1u;
        axi->awlock = 0u;
        axi->awcache =
            mif_cache_value(&request->request_config,
                            entry->attr);
        axi->awprot = mif_prot_value(entry->attr);
        axi->awqos = mif_qos_value(entry->attr);
        axi->awvalid = 1u;
    }

    out_slot = model->ar_hold;
    if (out_slot != NPU_MIF_INVALID_SLOT) {
        const npu_mif_axi_entry_t *entry =
            &model->axi_entries[out_slot];
        const npu_mif_request_entry_t *request =
            &model->requests[entry->req_slot];
        axi->arid = entry->axi_id;
        axi->araddr = entry->addr;
        axi->arlen = (uint8_t)(entry->beats - 1u);
        axi->arsize = 3u;
        axi->arburst = 1u;
        axi->arlock = 0u;
        axi->arcache =
            mif_cache_value(&request->request_config,
                            entry->attr);
        axi->arprot = mif_prot_value(entry->attr);
        axi->arqos = mif_qos_value(entry->attr);
        axi->arvalid = 1u;
    }
}

static void mif_fill_axi_ready(
    const npu_mif_cycle_t *model,
    npu_mif_cycle_outputs_t *outputs)
{
    outputs->axi.bready =
        model->b_entry.valid == 0u ? 1u : 0u;
    outputs->axi.rready =
        model->r_entry.valid == 0u ? 1u : 0u;
}

static void mif_fill_outputs(
    const npu_mif_cycle_t *model,
    npu_mif_cycle_outputs_t *outputs)
{
    (void)memset(outputs, 0, sizeof(*outputs));
    mif_fill_owner_outputs(model, outputs);
    mif_fill_axi_address(model, outputs);

    if (model->w_hold.valid != 0u) {
        npu_mif_axi_outputs_t *axi = &outputs->axi;
        axi->wvalid = 1u;
        axi->wdata = model->w_hold.data;
        axi->wstrb = model->w_hold.strb;
        axi->wlast = model->w_hold.last;
    }

    mif_fill_axi_ready(model, outputs);

    outputs->mif_idle = npu_mif_cycle_is_idle(model);
    outputs->rd_outstanding =
        mif_count_axi_outstanding(model, 0u);
    outputs->wr_outstanding =
        mif_count_axi_outstanding(model, 1u);
    outputs->axi_slots_used = mif_count_axi_slots(model);

    outputs->first_error_valid = model->first_error_valid;
    outputs->first_error_status = model->first_error_status;
    outputs->first_error_owner = model->first_error_owner;
    outputs->first_error_tag = model->first_error_tag;
    outputs->first_error_task_id =
        model->first_error_task_id;
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
    outputs->protocol_error_owner =
        model->protocol_error_owner;
    outputs->protocol_error_tag =
        model->protocol_error_tag;
    outputs->protocol_error_has_task_identity =
        model->protocol_error_has_task_identity;
    outputs->protocol_error_task_id =
        model->protocol_error_task_id;

    outputs->cycle_count = model->cycle_count;
    outputs->idle_cycles = model->idle_cycles;
}

static void mif_consume_owner_responses(
    npu_mif_cycle_t *model,
    const npu_mif_cycle_inputs_t *inputs,
    const npu_mif_cycle_outputs_t *outputs)
{
    uint8_t owner;

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        npu_mif_response_hold_t *hold =
            &model->rsp_hold[owner];
        if (outputs->owner[owner].rsp_valid != 0u &&
            inputs->owner[owner].rsp_ready != 0u) {
            uint8_t request_slot = hold->req_slot;
            uint8_t final = hold->final;
            (void)memset(hold, 0, sizeof(*hold));
            if (final != 0u) {
                mif_release_request(model, request_slot);
            }
        }
    }
}

static void mif_capture_axi_responses(
    npu_mif_cycle_t *model,
    const npu_mif_cycle_inputs_t *inputs,
    const npu_mif_cycle_outputs_t *outputs)
{
    const npu_mif_axi_inputs_t *axi_in = &inputs->axi;

    if (axi_in->bvalid != 0u &&
        outputs->axi.bready != 0u) {
        model->b_entry.valid = 1u;
        model->b_entry.id = axi_in->bid;
        model->b_entry.resp = axi_in->bresp;
    }

    if (axi_in->rvalid != 0u &&
        outputs->axi.rready != 0u) {
        model->r_entry.valid = 1u;
        model->r_entry.id = axi_in->rid;
        model->r_entry.data = axi_in->rdata;
        model->r_entry.resp = axi_in->rresp;
        model->r_entry.last =
            axi_in->rlast != 0u ? 1u : 0u;
    }
}

static uint8_t mif_checked_axi_request(
    npu_mif_cycle_t *model,
    uint8_t out_slot,
    npu_mif_request_entry_t **request)
{
    npu_mif_axi_entry_t *entry;

    if (out_slot >= NPU_MIF_MAX_AXI_OUTSTANDING) {
        return 0u;
    }
    entry = &model->axi_entries[out_slot];
    if (entry->valid == 0u ||
        entry->req_slot >= NPU_MIF_MAX_REQUESTS ||
        model->requests[entry->req_slot].valid == 0u ||
        model->requests[entry->req_slot].owner >=
            NPU_MIF_OWNER_COUNT) {
        return 0u;
    }
    *request = &model->requests[entry->req_slot];
    return 1u;
}

static void mif_process_r_entries(
    npu_mif_cycle_t *model,
    const npu_mif_cycle_inputs_t *inputs)
{
        npu_mif_axi_r_entry_t *r_entry = &model->r_entry;
        uint8_t out_slot;
        npu_mif_axi_entry_t *entry;
        npu_mif_request_entry_t *request;
        npu_mif_response_hold_t *hold;
        uint8_t owner;
        uint8_t expected_last;
        uint8_t actual_last;
        uint8_t burst_end;
        uint8_t final;
        uint8_t successful_end;
        uint8_t request_slot;
        uint16_t burst_beats;
        uint64_t beat_addr;

        if (r_entry->valid == 0u) {
            return;
        }

        out_slot =
            mif_find_axi_id_entry(model, r_entry->id);
        if (out_slot == NPU_MIF_INVALID_SLOT) {
            mif_mark_axi_protocol_error(
                model, NPU_MIF_PROTOCOL_AXI_RID,
                r_entry->id, 0u);
            (void)memset(r_entry, 0, sizeof(*r_entry));
            return;
        }

        entry = &model->axi_entries[out_slot];
        /*
         * A read response for a write ID, or a response observed before the
         * AR handshake, is consumed as malformed traffic. The real entry is
         * retained so a later valid response can still finish it.
         */
        if (entry->write != 0u || entry->addr_sent == 0u) {
            mif_mark_axi_protocol_error(
                model, NPU_MIF_PROTOCOL_AXI_RID,
                r_entry->id, entry->addr);
            (void)memset(r_entry, 0, sizeof(*r_entry));
            return;
        }
        if (mif_checked_axi_request(model, out_slot,
                                    &request) == 0u) {
            mif_mark_axi_protocol_error(
                model, NPU_MIF_PROTOCOL_AXI_ENTRY,
                r_entry->id, entry->addr);
            (void)memset(r_entry, 0, sizeof(*r_entry));
            return;
        }

        owner = request->owner;
        if (mif_response_capacity(model, inputs, owner) == 0u) {
            return;
        }

        hold = &model->rsp_hold[owner];
        expected_last =
            (uint16_t)(entry->beats_done + 1u) ==
                    entry->beats
                ? 1u
                : 0u;
        actual_last = r_entry->last;
        beat_addr =
            entry->addr +
            (uint64_t)entry->beats_done * UINT64_C(8);

        if (r_entry->resp > NPU_MIF_AXI_RESP_DECERR) {
            mif_mark_axi_protocol_error(
                model, NPU_MIF_PROTOCOL_AXI_RRESP,
                r_entry->id, beat_addr);
        }
        if (r_entry->resp != NPU_MIF_AXI_RESP_OKAY &&
            request->status == NPU_STATUS_SUCCESS) {
            uint8_t status = mif_axi_status(r_entry->resp);
            request->status = status;
            mif_record_first_error(
                model, request, status,
                beat_addr,
                1u,
                entry->axi_id, r_entry->resp);
        }

        if (actual_last != expected_last) {
            mif_mark_request_protocol_error(
                model, NPU_MIF_PROTOCOL_AXI_RLAST,
                request, beat_addr);
            if (request->status == NPU_STATUS_SUCCESS) {
                request->status = NPU_STATUS_BUS_SLVERR;
                mif_record_first_error(
                    model, request, NPU_STATUS_BUS_SLVERR,
                    beat_addr,
                    1u,
                    entry->axi_id, r_entry->resp);
            }
        }

        burst_end =
            actual_last != 0u || expected_last != 0u
                ? 1u
                : 0u;
        final =
            burst_end != 0u &&
                    (request->status != NPU_STATUS_SUCCESS ||
                     request->remaining_beats == entry->beats)
                ? 1u
                : 0u;

        hold->valid = 1u;
        hold->req_slot = entry->req_slot;
        hold->final = final;
        hold->data = r_entry->data;
        hold->tag = request->tag;
        hold->is_write = 0u;
        hold->last = final;
        hold->status = request->status;

        entry->beats_done++;
        if (burst_end != 0u) {
            request_slot = entry->req_slot;
            burst_beats = entry->beats;
            successful_end =
                request->status == NPU_STATUS_SUCCESS &&
                        actual_last != 0u &&
                        expected_last != 0u
                    ? 1u
                    : 0u;

            mif_clear_axi_entry(model, out_slot);
            if (successful_end != 0u) {
                mif_advance_request(request, burst_beats);
                if (request->remaining_beats == 0u) {
                    request->phase =
                        NPU_MIF_REQ_RESPONSE_HELD;
                }
            } else {
                model->requests[request_slot].phase =
                    NPU_MIF_REQ_RESPONSE_HELD;
            }
        }

        (void)memset(r_entry, 0, sizeof(*r_entry));
}

static uint8_t mif_fail_early_write_response(
    npu_mif_cycle_t *model,
    uint8_t out_slot,
    uint8_t axi_response)
{
    npu_mif_axi_entry_t entry;
    npu_mif_request_entry_t *request;
    uint8_t removed_head;

    if (mif_checked_axi_request(model, out_slot,
                                &request) == 0u) {
        return 0u;
    }
    entry = model->axi_entries[out_slot];
    removed_head =
        mif_write_fifo_head(model) == out_slot ? 1u : 0u;

    mif_mark_request_protocol_error(
        model, NPU_MIF_PROTOCOL_AXI_EARLY_B,
        request, entry.addr);
    if (request->status == NPU_STATUS_SUCCESS) {
        request->status = NPU_STATUS_BUS_SLVERR;
        mif_record_first_error(
            model, request, NPU_STATUS_BUS_SLVERR,
            entry.addr,
            1u,
            entry.axi_id, axi_response);
    }

    if (model->w_hold.valid != 0u &&
        model->w_hold.out_slot == out_slot) {
        (void)memset(&model->w_hold, 0,
                     sizeof(model->w_hold));
    }
    if (model->w_input.valid != 0u &&
        model->w_input.out_slot == out_slot) {
        (void)memset(&model->w_input, 0,
                     sizeof(model->w_input));
    }
    mif_write_fifo_remove(model, out_slot);
    if (model->aw_hold == out_slot) {
        model->aw_hold = NPU_MIF_INVALID_SLOT;
    }
    mif_clear_axi_entry(model, out_slot);
    request->phase = NPU_MIF_REQ_RESPONSE_PENDING;
    return removed_head;
}

static uint8_t mif_process_b_entries(npu_mif_cycle_t *model)
{
    uint8_t block_owner_write_accept = 0u;
        npu_mif_axi_b_entry_t *b_entry = &model->b_entry;
        uint8_t out_slot;
        npu_mif_axi_entry_t entry;
        npu_mif_request_entry_t *request;

        if (b_entry->valid == 0u) {
            return 0u;
        }

        out_slot =
            mif_find_axi_id_entry(model, b_entry->id);
        if (out_slot == NPU_MIF_INVALID_SLOT) {
            mif_mark_axi_protocol_error(
                model, NPU_MIF_PROTOCOL_AXI_BID,
                b_entry->id, 0u);
            (void)memset(b_entry, 0, sizeof(*b_entry));
            return 0u;
        }

        entry = model->axi_entries[out_slot];
        /*
         * B on a read ID, or B before the AW handshake, is discarded without
         * modifying the active transaction. B after AW but before the final
         * W beat is a terminal protocol failure because the write stream can
         * no longer be paired reliably with that completion.
         */
        if (entry.write == 0u || entry.addr_sent == 0u) {
            mif_mark_axi_protocol_error(
                model, NPU_MIF_PROTOCOL_AXI_BID,
                b_entry->id, entry.addr);
            (void)memset(b_entry, 0, sizeof(*b_entry));
            return 0u;
        }
        if (mif_checked_axi_request(model, out_slot,
                                    &request) == 0u) {
            mif_mark_axi_protocol_error(
                model, NPU_MIF_PROTOCOL_AXI_ENTRY,
                b_entry->id, entry.addr);
            (void)memset(b_entry, 0, sizeof(*b_entry));
            return 0u;
        }
        if (entry.w_done == 0u) {
            block_owner_write_accept |=
                mif_fail_early_write_response(
                    model, out_slot, b_entry->resp);
            (void)memset(b_entry, 0, sizeof(*b_entry));
            return block_owner_write_accept;
        }

        if (b_entry->resp > NPU_MIF_AXI_RESP_DECERR) {
            mif_mark_axi_protocol_error(
                model, NPU_MIF_PROTOCOL_AXI_BRESP,
                b_entry->id, entry.addr);
        }
        if (b_entry->resp != NPU_MIF_AXI_RESP_OKAY &&
            request->status == NPU_STATUS_SUCCESS) {
            uint8_t status = mif_axi_status(b_entry->resp);
            request->status = status;
            mif_record_first_error(
                model, request, status,
                entry.addr,
                1u,
                entry.axi_id, b_entry->resp);
        }

        mif_clear_axi_entry(model, out_slot);
        if (request->status != NPU_STATUS_SUCCESS) {
            request->phase = NPU_MIF_REQ_RESPONSE_PENDING;
        } else {
            mif_advance_request(request, entry.beats);
            if (request->remaining_beats == 0u) {
                request->phase =
                    NPU_MIF_REQ_RESPONSE_PENDING;
            }
        }
        (void)memset(b_entry, 0, sizeof(*b_entry));
    return block_owner_write_accept;
}

static void mif_process_axi_addresses(
    npu_mif_cycle_t *model,
    const npu_mif_cycle_inputs_t *inputs,
    const npu_mif_cycle_outputs_t *outputs)
{
    if (outputs->axi.awvalid != 0u &&
        inputs->axi.awready != 0u) {
        uint8_t out_slot = model->aw_hold;
        model->axi_entries[out_slot].addr_sent = 1u;
        mif_write_fifo_push(model, out_slot);
        model->aw_hold = NPU_MIF_INVALID_SLOT;
    }

    if (outputs->axi.arvalid != 0u &&
        inputs->axi.arready != 0u) {
        uint8_t out_slot = model->ar_hold;
        model->axi_entries[out_slot].addr_sent = 1u;
        model->ar_hold = NPU_MIF_INVALID_SLOT;
    }
}

static void mif_process_axi_write_data(
    npu_mif_cycle_t *model,
    const npu_mif_cycle_inputs_t *inputs,
    const npu_mif_cycle_outputs_t *outputs)
{
    if (model->w_hold.valid == 0u) {
        return;
    }

    if (outputs->axi.wvalid != 0u &&
        inputs->axi.wready != 0u) {
        uint8_t out_slot = model->w_hold.out_slot;
        npu_mif_axi_entry_t *entry =
            &model->axi_entries[out_slot];

        entry->beats_done++;
        if (model->w_hold.last != 0u) {
            entry->w_done = 1u;
            if (mif_write_fifo_head(model) == out_slot) {
                mif_write_fifo_pop(model);
            }
        }
        (void)memset(&model->w_hold, 0,
                     sizeof(model->w_hold));
    }
}

static void mif_process_write_input(
    npu_mif_cycle_t *model)
{
    uint8_t out_slot;
    npu_mif_axi_entry_t *entry;
    npu_mif_request_entry_t *request;
    uint8_t child_last;
    uint8_t request_last;

    if (model->w_input.valid == 0u ||
        model->w_input.blocked != 0u) {
        return;
    }

    out_slot = model->w_input.out_slot;
    if (out_slot >= NPU_MIF_MAX_AXI_OUTSTANDING ||
        mif_write_fifo_head(model) != out_slot ||
        mif_checked_axi_request(model, out_slot,
                                &request) == 0u) {
        model->w_input.blocked = 1u;
        mif_mark_protocol_error(
            model, NPU_MIF_PROTOCOL_AXI_ENTRY, 0u,
            model->w_input.owner, model->w_input.tag,
            0u, 0u);
        return;
    }

    entry = &model->axi_entries[out_slot];
    if (model->w_input.owner != request->owner ||
        model->w_input.tag != request->tag) {
        model->w_input.blocked = 1u;
        mif_mark_protocol_error(
            model, NPU_MIF_PROTOCOL_WRITE_TAG,
            request->next_addr,
            model->w_input.owner,
            model->w_input.tag, 1u,
            request->task_id);
        return;
    }

    if (model->w_hold.valid != 0u) {
        return;
    }

    child_last =
        (uint16_t)(entry->beats_done + 1u) ==
                entry->beats
            ? 1u
            : 0u;
    request_last =
        (uint16_t)(request->write_beats_accepted + 1u) ==
                request->total_beats
            ? 1u
            : 0u;

    model->w_hold.valid = 1u;
    model->w_hold.out_slot = out_slot;
    model->w_hold.data = model->w_input.data;
    model->w_hold.strb = model->w_input.strb;
    model->w_hold.last = child_last;
    request->write_beats_accepted++;

    if (model->w_input.last != request_last) {
        mif_mark_request_protocol_error(
            model, NPU_MIF_PROTOCOL_WRITE_LAST,
            request, request->next_addr);
        if (request->status == NPU_STATUS_SUCCESS) {
            request->status = NPU_STATUS_BAD_DESC;
            mif_record_first_error(
                model, request, NPU_STATUS_BAD_DESC,
                request->next_addr, 1u,
                entry->axi_id, 0u);
        }
    }

    (void)memset(&model->w_input, 0,
                 sizeof(model->w_input));
}

static void mif_capture_write_input(
    npu_mif_cycle_t *model,
    const npu_mif_cycle_inputs_t *inputs,
    const npu_mif_cycle_outputs_t *outputs)
{
    uint8_t owner;

    if (model->w_input.valid != 0u) {
        return;
    }

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        if (inputs->owner[owner].wvalid != 0u &&
            outputs->owner[owner].wready != 0u) {
            uint8_t out_slot = mif_write_fifo_head(model);

            model->w_input.valid = 1u;
            model->w_input.owner = owner;
            model->w_input.out_slot = out_slot;
            model->w_input.data =
                inputs->owner[owner].wdata;
            model->w_input.strb =
                inputs->owner[owner].wstrb;
            model->w_input.last =
                inputs->owner[owner].wlast != 0u ? 1u : 0u;
            model->w_input.tag =
                inputs->owner[owner].wtag;
            break;
        }
    }
}

static void mif_accept_owner_requests(
    npu_mif_cycle_t *model,
    const npu_mif_cycle_inputs_t *inputs,
    const npu_mif_cycle_outputs_t *outputs)
{
    uint8_t owner;
    npu_mif_cycle_config_t config =
        mif_effective_config(model, inputs);

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        if (inputs->owner[owner].req_valid != 0u &&
            outputs->owner[owner].req_ready != 0u) {
            mif_accept_request(model, owner,
                               &inputs->owner[owner],
                               &config);
        }
    }

    /*
     * With one free request slot, ready is offered to one owner per cycle.
     * Advance even without a handshake so an idle selected owner cannot
     * indefinitely delay the other owner.
     */
    if ((outputs->owner[0].req_ready != 0u) !=
        (outputs->owner[1].req_ready != 0u)) {
        model->request_rr_owner ^= 1u;
    }
}

void npu_mif_cycle_config_default(npu_mif_cycle_config_t *config)
{
    if (config == NULL) {
        return;
    }

    (void)memset(config, 0, sizeof(*config));
    config->system_addr_enable = 1u;
    config->system_addr_base = 0u;
    config->system_addr_limit =
        NPU_MIF_ADDR_MASK & ~UINT64_C(7);
    config->axi_cache_device = 0u;
    config->axi_cache_normal_noncache = 2u;
    config->axi_cache_normal_cacheable = 15u;
}

void npu_mif_cycle_reset(npu_mif_cycle_t *model)
{
    npu_mif_cycle_config_t config;
    if (model == NULL) {
        return;
    }

    config = model->config;
    (void)memset(model, 0, sizeof(*model));
    model->config = config;
    mif_clear_diagnostics(model);
    model->aw_hold = NPU_MIF_INVALID_SLOT;
    model->ar_hold = NPU_MIF_INVALID_SLOT;
}

int npu_mif_cycle_init(npu_mif_cycle_t *model,
                       const npu_mif_cycle_config_t *config)
{
    npu_mif_cycle_config_t defaults;
    npu_mif_cycle_config_t resolved;

    if (model == NULL) {
        return -1;
    }

    npu_mif_cycle_config_default(&defaults);
    resolved = config != NULL ? *config : defaults;
    if (npu_mif_cycle_config_valid(&resolved) == 0u) {
        return -1;
    }
    (void)memset(model, 0, sizeof(*model));
    model->config = resolved;
    npu_mif_cycle_reset(model);
    return 0;
}

void npu_mif_cycle_step(npu_mif_cycle_t *model,
                        const npu_mif_cycle_inputs_t *inputs,
                        npu_mif_cycle_outputs_t *outputs)
{
    uint8_t block_owner_write_accept;
    uint8_t config_update_valid = 0u;
    npu_mif_cycle_config_t effective_config;

    if (model == NULL || inputs == NULL || outputs == NULL) {
        return;
    }

    if (inputs->reset_n == 0u) {
        npu_mif_cycle_reset(model);
        (void)memset(outputs, 0, sizeof(*outputs));
        outputs->mif_idle = 1u;
        return;
    }

    mif_fill_outputs(model, outputs);
    if (inputs->error_clear != 0u) {
        mif_clear_diagnostics(model);
    }
    if (inputs->config_valid != 0u) {
        effective_config = mif_effective_config(model, inputs);
        if (npu_mif_cycle_config_valid(
                &effective_config) != 0u) {
            config_update_valid = 1u;
        } else {
            uint8_t owner;

            for (owner = 0u;
                 owner < NPU_MIF_OWNER_COUNT;
                 owner++) {
                outputs->owner[owner].req_ready = 0u;
            }
            mif_mark_protocol_error(
                model, NPU_MIF_PROTOCOL_CONFIG, 0u,
                NPU_MIF_INVALID_OWNER, 0u, 0u, 0u);
        }
    }

    mif_consume_owner_responses(model, inputs, outputs);
    mif_capture_axi_responses(model, inputs, outputs);
    mif_process_r_entries(model, inputs);
    block_owner_write_accept = mif_process_b_entries(model);
    mif_process_axi_addresses(model, inputs, outputs);
    mif_process_axi_write_data(model, inputs, outputs);
    mif_process_write_input(model);
    if (block_owner_write_accept == 0u) {
        mif_capture_write_input(model, inputs, outputs);
    }
    mif_accept_owner_requests(model, inputs, outputs);

    mif_schedule_axi(model);
    mif_schedule_responses(model);

    if (outputs->mif_idle != 0u) {
        model->idle_cycles++;
    }
    if (config_update_valid != 0u) {
        model->config = effective_config;
    }
    model->cycle_count++;
}
