#include "npu_tbu_cycle.h"

#include <string.h>

static uint8_t tbu_request_count(const npu_tbu_cycle_t *model)
{
    uint8_t count = 0u;
    uint8_t index;

    for (index = 0u; index < NPU_TBU_OUTSTANDING; index++) {
        if (model->requests[index].valid != 0u) {
            count++;
        }
    }
    return count;
}

static uint8_t tbu_find_free_request(const npu_tbu_cycle_t *model)
{
    uint8_t index;

    for (index = 0u; index < NPU_TBU_OUTSTANDING; index++) {
        if (model->requests[index].valid == 0u) {
            return index;
        }
    }
    return NPU_TBU_INVALID_SLOT;
}

static uint8_t tbu_find_ready_response(
    const npu_tbu_cycle_t *model)
{
    uint8_t selected = NPU_TBU_INVALID_SLOT;
    uint8_t index;

    for (index = 0u; index < NPU_TBU_OUTSTANDING; index++) {
        const npu_tbu_request_entry_t *entry =
            &model->requests[index];

        if (entry->valid == 0u ||
            entry->remaining_cycles != 0u) {
            continue;
        }
        if (selected == NPU_TBU_INVALID_SLOT ||
            entry->sequence <
                model->requests[selected].sequence) {
            selected = index;
        }
    }
    return selected;
}

static const npu_tbu_rule_t *tbu_find_rule(
    const npu_tbu_cycle_t *model,
    uint64_t virtual_page,
    uint16_t stream_id,
    uint16_t substream_id)
{
    uint8_t index;

    for (index = 0u; index < NPU_TBU_RULE_COUNT; index++) {
        const npu_tbu_rule_t *rule = &model->rules[index];

        if (rule->valid != 0u &&
            rule->virtual_page == virtual_page &&
            rule->stream_id == stream_id &&
            rule->substream_id == substream_id) {
            return rule;
        }
    }
    return (const npu_tbu_rule_t *)0;
}

static void tbu_prepare_request(
    const npu_tbu_cycle_t *model,
    const npu_tbu_cycle_inputs_t *inputs,
    npu_tbu_request_entry_t *entry)
{
    const npu_tbu_rule_t *rule;
    uint64_t virtual_page;

    (void)memset(entry, 0, sizeof(*entry));
    entry->valid = 1u;
    entry->tag = (uint16_t)(inputs->req_tag & 0x3fffu);

    if ((inputs->req_vaddr & ~NPU_TBU_VADDR_MASK) != 0u ||
        (inputs->req_tag & 0xc000u) != 0u ||
        inputs->req_write > 1u) {
        entry->status = (uint8_t)NPU_STATUS_BAD_DESC;
        entry->remaining_cycles = NPU_TBU_HIT_LATENCY;
        return;
    }

    virtual_page = inputs->req_vaddr >> 12u;
    rule = tbu_find_rule(
        model, virtual_page,
        inputs->req_stream_id,
        inputs->req_substream_id);
    if (rule == (const npu_tbu_rule_t *)0) {
        entry->status = (uint8_t)NPU_STATUS_ADDR_FAULT;
        entry->remaining_cycles = NPU_TBU_MISS_LATENCY;
        return;
    }

    entry->remaining_cycles = NPU_TBU_HIT_LATENCY;
    if ((inputs->req_write != 0u &&
         rule->write_enable == 0u) ||
        (inputs->req_write == 0u &&
         rule->read_enable == 0u)) {
        entry->status = (uint8_t)NPU_STATUS_ADDR_FAULT;
        return;
    }

    entry->status = (uint8_t)NPU_STATUS_SUCCESS;
    entry->paddr =
        (((uint64_t)rule->physical_page << 12u) |
         (inputs->req_vaddr & UINT64_C(0xfff))) &
        NPU_TBU_PADDR_MASK;
}

void npu_tbu_cycle_init(npu_tbu_cycle_t *model)
{
    if (model == (npu_tbu_cycle_t *)0) {
        return;
    }
    (void)memset(model, 0, sizeof(*model));
    model->initialized = 1u;
}

void npu_tbu_cycle_reset(npu_tbu_cycle_t *model)
{
    if (model == (npu_tbu_cycle_t *)0 ||
        model->initialized == 0u) {
        return;
    }
    (void)memset(
        model->requests, 0, sizeof(model->requests));
    model->next_sequence = 0u;
    model->cycle_count = 0u;
}

int npu_tbu_cycle_set_rule(npu_tbu_cycle_t *model,
                           uint8_t index,
                           const npu_tbu_rule_t *rule)
{
    if (model == (npu_tbu_cycle_t *)0 ||
        rule == (const npu_tbu_rule_t *)0 ||
        model->initialized == 0u ||
        index >= NPU_TBU_RULE_COUNT ||
        tbu_request_count(model) != 0u ||
        rule->valid > 1u ||
        rule->virtual_page > NPU_TBU_VPAGE_MASK ||
        rule->physical_page > NPU_TBU_PPAGE_MASK ||
        rule->read_enable > 1u ||
        rule->write_enable > 1u) {
        return 0;
    }
    model->rules[index] = *rule;
    return 1;
}

void npu_tbu_cycle_eval(const npu_tbu_cycle_t *model,
                        const npu_tbu_cycle_inputs_t *inputs,
                        npu_tbu_cycle_outputs_t *outputs)
{
    uint8_t count;
    uint8_t response;

    if (outputs == (npu_tbu_cycle_outputs_t *)0) {
        return;
    }
    (void)memset(outputs, 0, sizeof(*outputs));
    if (model == (const npu_tbu_cycle_t *)0 ||
        inputs == (const npu_tbu_cycle_inputs_t *)0 ||
        model->initialized == 0u) {
        return;
    }

    count = tbu_request_count(model);
    outputs->outstanding = count;
    outputs->idle = count == 0u ? 1u : 0u;
    outputs->cycle_count = model->cycle_count;
    if (inputs->reset_n == 0u) {
        return;
    }

    outputs->req_ready =
        count < NPU_TBU_OUTSTANDING ? 1u : 0u;
    response = tbu_find_ready_response(model);
    if (response != NPU_TBU_INVALID_SLOT) {
        const npu_tbu_request_entry_t *entry =
            &model->requests[response];

        outputs->rsp_valid = 1u;
        outputs->rsp_paddr = entry->paddr;
        outputs->rsp_tag = entry->tag;
        outputs->rsp_status = entry->status;
    }
}

void npu_tbu_cycle_step(npu_tbu_cycle_t *model,
                        const npu_tbu_cycle_inputs_t *inputs,
                        npu_tbu_cycle_outputs_t *outputs)
{
    uint8_t response;
    uint8_t free_request;
    uint8_t request_handshake;
    uint8_t response_handshake;
    uint8_t index;

    if (model == (npu_tbu_cycle_t *)0 ||
        inputs == (const npu_tbu_cycle_inputs_t *)0 ||
        outputs == (npu_tbu_cycle_outputs_t *)0 ||
        model->initialized == 0u) {
        if (outputs != (npu_tbu_cycle_outputs_t *)0) {
            (void)memset(outputs, 0, sizeof(*outputs));
        }
        return;
    }
    if (inputs->reset_n == 0u) {
        npu_tbu_cycle_reset(model);
        npu_tbu_cycle_eval(model, inputs, outputs);
        return;
    }

    npu_tbu_cycle_eval(model, inputs, outputs);
    response = tbu_find_ready_response(model);
    request_handshake =
        (uint8_t)(inputs->req_valid != 0u &&
                  outputs->req_ready != 0u);
    response_handshake =
        (uint8_t)(outputs->rsp_valid != 0u &&
                  inputs->rsp_ready != 0u);

    for (index = 0u; index < NPU_TBU_OUTSTANDING; index++) {
        if (model->requests[index].valid != 0u &&
            model->requests[index].remaining_cycles != 0u) {
            model->requests[index].remaining_cycles--;
        }
    }
    if (response_handshake != 0u &&
        response != NPU_TBU_INVALID_SLOT) {
        (void)memset(
            &model->requests[response], 0,
            sizeof(model->requests[response]));
    }
    if (request_handshake != 0u) {
        npu_tbu_request_entry_t entry;

        free_request = tbu_find_free_request(model);
        if (free_request != NPU_TBU_INVALID_SLOT) {
            tbu_prepare_request(model, inputs, &entry);
            entry.sequence = model->next_sequence;
            model->next_sequence++;
            model->requests[free_request] = entry;
        }
    }
    model->cycle_count++;
}
