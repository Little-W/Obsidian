#include "npu_axi_mem_target_cycle.h"

#include <limits.h>
#include <string.h>

#define NPU_AXI_MEM_SIZE_64BIT 3u
#define NPU_AXI_MEM_BURST_INCR 1u
#define NPU_AXI_MEM_PAGE_BYTES UINT64_C(4096)

static uint64_t axi_mem_add_limit(uint64_t value,
                                  uint64_t add)
{
    return UINT64_MAX - value < add
               ? UINT64_MAX
               : value + add;
}

static uint64_t axi_mem_ready_cycle(uint64_t cycle,
                                    uint32_t latency,
                                    uint32_t extra)
{
    uint64_t ready = axi_mem_add_limit(
        cycle, (uint64_t)latency);

    ready = axi_mem_add_limit(ready, (uint64_t)extra);
    return axi_mem_add_limit(ready, 1u);
}

static int axi_mem_config_valid(
    const npu_axi_mem_target_config_t *config)
{
    return config !=
               (const npu_axi_mem_target_config_t *)0 &&
           config->max_read_transactions != 0u &&
           config->max_read_transactions <=
               NPU_AXI_MEM_TARGET_MAX_READS &&
           config->max_write_transactions != 0u &&
           config->max_write_transactions <=
               NPU_AXI_MEM_TARGET_MAX_WRITES;
}

void npu_axi_mem_target_config_reference(
    npu_axi_mem_target_config_t *config)
{
    if (config ==
        (npu_axi_mem_target_config_t *)0) {
        return;
    }
    config->read_latency_cycles =
        NPU_AXI_MEM_TARGET_DEFAULT_READ_LATENCY;
    config->write_latency_cycles =
        NPU_AXI_MEM_TARGET_DEFAULT_WRITE_LATENCY;
    config->max_read_transactions =
        NPU_AXI_MEM_TARGET_MAX_READS;
    config->max_write_transactions =
        NPU_AXI_MEM_TARGET_MAX_WRITES;
}

static void axi_mem_reset_state(
    npu_axi_mem_target_cycle_t *model)
{
    (void)memset(
        model->read, 0, sizeof(model->read));
    (void)memset(
        model->write, 0, sizeof(model->write));
    (void)memset(
        model->write_order, 0,
        sizeof(model->write_order));
    (void)memset(
        &model->r_hold, 0, sizeof(model->r_hold));
    (void)memset(
        &model->b_hold, 0, sizeof(model->b_hold));
    model->write_order_head = 0u;
    model->write_order_tail = 0u;
    model->write_order_count = 0u;
    model->read_active_slot =
        NPU_AXI_MEM_TARGET_INVALID_SLOT;
    model->read_count = 0u;
    model->write_count = 0u;
    model->protocol_error_valid = 0u;
    model->protocol_error_kind =
        NPU_AXI_MEM_PROTOCOL_NONE;
    model->protocol_error_id = 0u;
    model->next_sequence = 0u;
    model->cycle = 0u;
}

int npu_axi_mem_target_cycle_init(
    npu_axi_mem_target_cycle_t *model,
    uint8_t *memory,
    size_t memory_bytes,
    uint64_t base_addr,
    const npu_axi_mem_target_config_t *config)
{
    uint64_t bytes64;

    if (model == (npu_axi_mem_target_cycle_t *)0 ||
        memory == (uint8_t *)0 ||
        memory_bytes == 0u ||
        !axi_mem_config_valid(config)) {
        return 0;
    }
    bytes64 = (uint64_t)memory_bytes;
    if ((size_t)bytes64 != memory_bytes ||
        bytes64 > UINT64_MAX - base_addr) {
        return 0;
    }
    (void)memset(model, 0, sizeof(*model));
    model->memory = memory;
    model->memory_bytes = memory_bytes;
    model->base_addr = base_addr;
    model->config = *config;
    model->initialized = 1u;
    axi_mem_reset_state(model);
    return 1;
}

void npu_axi_mem_target_cycle_reset(
    npu_axi_mem_target_cycle_t *model)
{
    if (model == (npu_axi_mem_target_cycle_t *)0 ||
        model->initialized == 0u) {
        return;
    }
    axi_mem_reset_state(model);
}

int npu_axi_mem_target_set_injection(
    npu_axi_mem_target_cycle_t *model,
    size_t index,
    const npu_axi_mem_target_injection_t *injection)
{
    if (model == (npu_axi_mem_target_cycle_t *)0 ||
        model->initialized == 0u ||
        injection ==
            (const npu_axi_mem_target_injection_t *)0 ||
        index >= NPU_AXI_MEM_TARGET_MAX_INJECTIONS ||
        injection->write > 1u ||
        injection->match_id > 1u ||
        injection->resp > NPU_AXI_MEM_RESP_DECERR) {
        return 0;
    }
    model->injection[index] = *injection;
    model->injection[index].valid =
        injection->valid != 0u ? 1u : 0u;
    return 1;
}

void npu_axi_mem_target_clear_injections(
    npu_axi_mem_target_cycle_t *model)
{
    if (model == (npu_axi_mem_target_cycle_t *)0 ||
        model->initialized == 0u) {
        return;
    }
    (void)memset(
        model->injection, 0,
        sizeof(model->injection));
}

static const npu_axi_mem_target_injection_t *
axi_mem_find_injection(
    const npu_axi_mem_target_cycle_t *model,
    uint8_t write,
    uint8_t id,
    uint64_t addr)
{
    size_t index;

    for (index = 0u;
         index < NPU_AXI_MEM_TARGET_MAX_INJECTIONS;
         index++) {
        const npu_axi_mem_target_injection_t *rule =
            &model->injection[index];

        if (rule->valid != 0u &&
            rule->write == write &&
            rule->addr == addr &&
            (rule->match_id == 0u ||
             rule->id == id)) {
            return rule;
        }
    }
    return (const npu_axi_mem_target_injection_t *)0;
}

static int axi_mem_request_valid(
    const npu_axi_mem_target_cycle_t *model,
    uint64_t addr,
    uint8_t len,
    uint8_t size,
    uint8_t burst)
{
    uint64_t beats = (uint64_t)len + 1u;
    uint64_t bytes =
        beats * NPU_AXI_MEM_TARGET_DATA_BYTES;
    uint64_t offset;

    if (beats > NPU_AXI_MEM_TARGET_MAX_BURST_BEATS ||
        size != NPU_AXI_MEM_SIZE_64BIT ||
        burst != NPU_AXI_MEM_BURST_INCR ||
        (addr & (NPU_AXI_MEM_TARGET_DATA_BYTES - 1u)) !=
            0u ||
        (addr & (NPU_AXI_MEM_PAGE_BYTES - 1u)) >
            NPU_AXI_MEM_PAGE_BYTES - bytes ||
        addr < model->base_addr) {
        return 0;
    }
    offset = addr - model->base_addr;
    return offset <= (uint64_t)model->memory_bytes &&
           bytes <=
               (uint64_t)model->memory_bytes - offset;
}

static uint8_t axi_mem_find_free_read(
    const npu_axi_mem_target_cycle_t *model)
{
    uint8_t slot;

    for (slot = 0u;
         slot < NPU_AXI_MEM_TARGET_MAX_READS; slot++) {
        if (model->read[slot].valid == 0u) {
            return slot;
        }
    }
    return NPU_AXI_MEM_TARGET_INVALID_SLOT;
}

static uint8_t axi_mem_find_free_write(
    const npu_axi_mem_target_cycle_t *model)
{
    uint8_t slot;

    for (slot = 0u;
         slot < NPU_AXI_MEM_TARGET_MAX_WRITES; slot++) {
        if (model->write[slot].valid == 0u) {
            return slot;
        }
    }
    return NPU_AXI_MEM_TARGET_INVALID_SLOT;
}

static uint8_t axi_mem_choose_read(
    const npu_axi_mem_target_cycle_t *model)
{
    uint8_t selected =
        NPU_AXI_MEM_TARGET_INVALID_SLOT;
    uint8_t slot;

    for (slot = 0u;
         slot < NPU_AXI_MEM_TARGET_MAX_READS; slot++) {
        const npu_axi_mem_target_read_t *entry =
            &model->read[slot];
        uint8_t older = 0u;
        uint8_t other;

        if (entry->valid == 0u ||
            entry->ready_cycle > model->cycle) {
            continue;
        }
        for (other = 0u;
             other < NPU_AXI_MEM_TARGET_MAX_READS;
             other++) {
            if (model->read[other].valid != 0u &&
                model->read[other].id == entry->id &&
                model->read[other].sequence <
                    entry->sequence) {
                older = 1u;
                break;
            }
        }
        if (older != 0u) {
            continue;
        }
        if (selected ==
                NPU_AXI_MEM_TARGET_INVALID_SLOT ||
            entry->ready_cycle <
                model->read[selected].ready_cycle ||
            (entry->ready_cycle ==
                 model->read[selected].ready_cycle &&
             entry->sequence <
                 model->read[selected].sequence)) {
            selected = slot;
        }
    }
    return selected;
}

static uint8_t axi_mem_choose_write_response(
    const npu_axi_mem_target_cycle_t *model)
{
    uint8_t selected =
        NPU_AXI_MEM_TARGET_INVALID_SLOT;
    uint8_t slot;

    for (slot = 0u;
         slot < NPU_AXI_MEM_TARGET_MAX_WRITES; slot++) {
        const npu_axi_mem_target_write_t *entry =
            &model->write[slot];
        uint8_t older = 0u;
        uint8_t other;

        if (entry->valid == 0u ||
            entry->data_done == 0u ||
            entry->b_ready_cycle > model->cycle) {
            continue;
        }
        for (other = 0u;
             other < NPU_AXI_MEM_TARGET_MAX_WRITES;
             other++) {
            if (model->write[other].valid != 0u &&
                model->write[other].id == entry->id &&
                model->write[other].sequence <
                    entry->sequence) {
                older = 1u;
                break;
            }
        }
        if (older != 0u) {
            continue;
        }
        if (selected ==
                NPU_AXI_MEM_TARGET_INVALID_SLOT ||
            entry->b_ready_cycle <
                model->write[selected].b_ready_cycle ||
            (entry->b_ready_cycle ==
                 model->write[selected].b_ready_cycle &&
             entry->sequence <
                 model->write[selected].sequence)) {
            selected = slot;
        }
    }
    return selected;
}

static uint64_t axi_mem_read_word(
    const npu_axi_mem_target_cycle_t *model,
    uint64_t addr)
{
    uint64_t value = 0u;
    size_t offset =
        (size_t)(addr - model->base_addr);
    uint32_t byte;

    for (byte = 0u;
         byte < NPU_AXI_MEM_TARGET_DATA_BYTES; byte++) {
        value |= (uint64_t)model->memory[offset + byte] <<
                 (byte * 8u);
    }
    return value;
}

static void axi_mem_prepare_r(
    npu_axi_mem_target_cycle_t *model)
{
    npu_axi_mem_target_read_t *entry;
    uint8_t slot;
    uint64_t addr;

    if (model->r_hold.valid != 0u) {
        return;
    }
    slot = model->read_active_slot;
    if (slot == NPU_AXI_MEM_TARGET_INVALID_SLOT) {
        slot = axi_mem_choose_read(model);
        if (slot == NPU_AXI_MEM_TARGET_INVALID_SLOT) {
            return;
        }
        model->read_active_slot = slot;
    }
    entry = &model->read[slot];
    if (entry->valid == 0u ||
        entry->beat >= entry->beats) {
        model->read_active_slot =
            NPU_AXI_MEM_TARGET_INVALID_SLOT;
        return;
    }
    addr = entry->addr +
           (uint64_t)entry->beat *
               NPU_AXI_MEM_TARGET_DATA_BYTES;
    model->r_hold.valid = 1u;
    model->r_hold.slot = slot;
    model->r_hold.id = entry->id;
    model->r_hold.resp = entry->resp;
    model->r_hold.last =
        entry->beat + 1u == entry->beats ? 1u : 0u;
    model->r_hold.data =
        entry->resp < NPU_AXI_MEM_RESP_SLVERR
            ? axi_mem_read_word(model, addr)
            : 0u;
}

static void axi_mem_prepare_b(
    npu_axi_mem_target_cycle_t *model)
{
    uint8_t slot;

    if (model->b_hold.valid != 0u) {
        return;
    }
    slot = axi_mem_choose_write_response(model);
    if (slot == NPU_AXI_MEM_TARGET_INVALID_SLOT) {
        return;
    }
    model->b_hold.valid = 1u;
    model->b_hold.slot = slot;
    model->b_hold.id = model->write[slot].id;
    model->b_hold.resp = model->write[slot].resp;
}

static void axi_mem_fill_outputs(
    const npu_axi_mem_target_cycle_t *model,
    const npu_axi_mem_target_cycle_inputs_t *inputs,
    npu_axi_mem_target_cycle_outputs_t *outputs)
{
    npu_axi_mem_target_outputs_t *target =
        &outputs->target;

    (void)memset(outputs, 0, sizeof(*outputs));
    target->awready =
        model->write_count <
                model->config.max_write_transactions &&
                axi_mem_find_free_write(model) !=
                    NPU_AXI_MEM_TARGET_INVALID_SLOT &&
                inputs->pause_aw == 0u
            ? 1u
            : 0u;
    target->wready =
        model->write_order_count != 0u &&
                inputs->pause_w == 0u
            ? 1u
            : 0u;
    target->arready =
        model->read_count <
                model->config.max_read_transactions &&
                axi_mem_find_free_read(model) !=
                    NPU_AXI_MEM_TARGET_INVALID_SLOT &&
                inputs->pause_ar == 0u
            ? 1u
            : 0u;

    if (model->b_hold.valid != 0u) {
        target->bvalid = 1u;
        target->bid = model->b_hold.id;
        target->bresp = model->b_hold.resp;
    }
    if (model->r_hold.valid != 0u) {
        target->rvalid = 1u;
        target->rid = model->r_hold.id;
        target->rdata = model->r_hold.data;
        target->rresp = model->r_hold.resp;
        target->rlast = model->r_hold.last;
    }

    outputs->read_outstanding = model->read_count;
    outputs->write_outstanding = model->write_count;
    outputs->idle =
        npu_axi_mem_target_cycle_is_idle(model);
    outputs->protocol_error_valid =
        model->protocol_error_valid;
    outputs->protocol_error_kind =
        model->protocol_error_kind;
    outputs->protocol_error_id =
        model->protocol_error_id;
    outputs->cycle = model->cycle;
}

static void axi_mem_accept_ar(
    npu_axi_mem_target_cycle_t *model,
    const npu_axi_mem_master_outputs_t *master)
{
    const npu_axi_mem_target_injection_t *rule;
    npu_axi_mem_target_read_t *entry;
    uint8_t slot = axi_mem_find_free_read(model);
    uint8_t valid;
    uint8_t resp;
    uint32_t extra = 0u;

    if (slot == NPU_AXI_MEM_TARGET_INVALID_SLOT) {
        return;
    }
    valid = (uint8_t)axi_mem_request_valid(
        model, master->araddr, master->arlen,
        master->arsize, master->arburst);
    resp = valid != 0u ? NPU_AXI_MEM_RESP_OKAY
                       : NPU_AXI_MEM_RESP_DECERR;
    rule = axi_mem_find_injection(
        model, 0u, master->arid, master->araddr);
    if (rule !=
        (const npu_axi_mem_target_injection_t *)0) {
        if (valid != 0u) {
            resp = rule->resp;
        }
        extra = rule->extra_delay_cycles;
    }
    entry = &model->read[slot];
    (void)memset(entry, 0, sizeof(*entry));
    entry->valid = 1u;
    entry->id = master->arid;
    entry->resp = resp;
    entry->beats = (uint16_t)master->arlen + 1u;
    entry->addr = master->araddr;
    entry->ready_cycle = axi_mem_ready_cycle(
        model->cycle, model->config.read_latency_cycles,
        extra);
    entry->sequence = model->next_sequence++;
    model->read_count++;
}

static void axi_mem_accept_aw(
    npu_axi_mem_target_cycle_t *model,
    const npu_axi_mem_master_outputs_t *master)
{
    const npu_axi_mem_target_injection_t *rule;
    npu_axi_mem_target_write_t *entry;
    uint8_t slot = axi_mem_find_free_write(model);
    uint8_t valid;
    uint8_t resp;

    if (slot == NPU_AXI_MEM_TARGET_INVALID_SLOT ||
        model->write_order_count >=
            NPU_AXI_MEM_TARGET_MAX_WRITES) {
        return;
    }
    valid = (uint8_t)axi_mem_request_valid(
        model, master->awaddr, master->awlen,
        master->awsize, master->awburst);
    resp = valid != 0u ? NPU_AXI_MEM_RESP_OKAY
                       : NPU_AXI_MEM_RESP_DECERR;
    rule = axi_mem_find_injection(
        model, 1u, master->awid, master->awaddr);
    if (rule !=
        (const npu_axi_mem_target_injection_t *)0) {
        if (valid != 0u) {
            resp = rule->resp;
        }
    }
    entry = &model->write[slot];
    (void)memset(entry, 0, sizeof(*entry));
    entry->valid = 1u;
    entry->id = master->awid;
    entry->resp = resp;
    entry->beats = (uint16_t)master->awlen + 1u;
    entry->addr = master->awaddr;
    entry->sequence = model->next_sequence++;
    entry->extra_delay_cycles =
        rule !=
                (const npu_axi_mem_target_injection_t *)0
            ? rule->extra_delay_cycles
            : 0u;

    model->write_order[model->write_order_tail] = slot;
    model->write_order_tail =
        (uint8_t)(
            (model->write_order_tail + 1u) %
            NPU_AXI_MEM_TARGET_MAX_WRITES);
    model->write_order_count++;
    model->write_count++;
}

static void axi_mem_write_word(
    npu_axi_mem_target_cycle_t *model,
    const npu_axi_mem_target_write_t *entry,
    uint64_t data,
    uint8_t strb)
{
    uint64_t addr =
        entry->addr +
        (uint64_t)entry->beat *
            NPU_AXI_MEM_TARGET_DATA_BYTES;
    size_t offset =
        (size_t)(addr - model->base_addr);
    uint32_t byte;

    for (byte = 0u;
         byte < NPU_AXI_MEM_TARGET_DATA_BYTES; byte++) {
        if ((strb & (uint8_t)(1u << byte)) != 0u) {
            model->memory[offset + byte] =
                (uint8_t)(data >> (byte * 8u));
        }
    }
}

static void axi_mem_accept_w(
    npu_axi_mem_target_cycle_t *model,
    const npu_axi_mem_master_outputs_t *master,
    uint8_t commit_memory)
{
    npu_axi_mem_target_write_t *entry;
    uint8_t expected_last;
    uint8_t slot;

    if (model->write_order_count == 0u) {
        return;
    }
    slot = model->write_order[model->write_order_head];
    entry = &model->write[slot];
    expected_last =
        entry->beat + 1u == entry->beats ? 1u : 0u;
    if (master->wlast != expected_last) {
        if (model->protocol_error_valid == 0u) {
            model->protocol_error_valid = 1u;
            model->protocol_error_kind =
                NPU_AXI_MEM_PROTOCOL_WLAST;
            model->protocol_error_id = entry->id;
        }
        if (entry->resp != NPU_AXI_MEM_RESP_DECERR) {
            entry->resp = NPU_AXI_MEM_RESP_SLVERR;
        }
    }
    if (commit_memory != 0u &&
        entry->resp < NPU_AXI_MEM_RESP_SLVERR) {
        axi_mem_write_word(
            model, entry, master->wdata, master->wstrb);
    }
    entry->beat++;
    if (entry->beat < entry->beats) {
        return;
    }
    entry->data_done = 1u;
    entry->b_ready_cycle = axi_mem_ready_cycle(
        model->cycle,
        model->config.write_latency_cycles,
        entry->extra_delay_cycles);
    model->write_order_head =
        (uint8_t)(
            (model->write_order_head + 1u) %
            NPU_AXI_MEM_TARGET_MAX_WRITES);
    model->write_order_count--;
}

static void axi_mem_accept_r(
    npu_axi_mem_target_cycle_t *model)
{
    npu_axi_mem_target_read_t *entry;
    uint8_t slot = model->r_hold.slot;

    if (slot >= NPU_AXI_MEM_TARGET_MAX_READS) {
        model->r_hold.valid = 0u;
        model->read_active_slot =
            NPU_AXI_MEM_TARGET_INVALID_SLOT;
        return;
    }
    entry = &model->read[slot];
    model->r_hold.valid = 0u;
    entry->beat++;
    if (entry->beat < entry->beats) {
        return;
    }
    (void)memset(entry, 0, sizeof(*entry));
    if (model->read_count != 0u) {
        model->read_count--;
    }
    model->read_active_slot =
        NPU_AXI_MEM_TARGET_INVALID_SLOT;
}

static void axi_mem_accept_b(
    npu_axi_mem_target_cycle_t *model)
{
    uint8_t slot = model->b_hold.slot;

    model->b_hold.valid = 0u;
    if (slot >= NPU_AXI_MEM_TARGET_MAX_WRITES) {
        return;
    }
    (void)memset(
        &model->write[slot], 0,
        sizeof(model->write[slot]));
    if (model->write_count != 0u) {
        model->write_count--;
    }
}

uint8_t npu_axi_mem_target_cycle_is_idle(
    const npu_axi_mem_target_cycle_t *model)
{
    return model !=
                   (const npu_axi_mem_target_cycle_t *)0 &&
                   model->initialized != 0u &&
                   model->read_count == 0u &&
                   model->write_count == 0u &&
                   model->write_order_count == 0u &&
                   model->r_hold.valid == 0u &&
                   model->b_hold.valid == 0u
               ? 1u
               : 0u;
}

static void axi_mem_cycle_run(
    npu_axi_mem_target_cycle_t *model,
    const npu_axi_mem_target_cycle_inputs_t *inputs,
    npu_axi_mem_target_cycle_outputs_t *outputs,
    uint8_t commit_memory)
{
    const npu_axi_mem_master_outputs_t *master;
    uint8_t ar_handshake;
    uint8_t aw_handshake;
    uint8_t w_handshake;
    uint8_t r_handshake;
    uint8_t b_handshake;

    if (inputs->reset_n == 0u) {
        npu_axi_mem_target_cycle_reset(model);
        (void)memset(outputs, 0, sizeof(*outputs));
        outputs->idle = 1u;
        return;
    }
    axi_mem_prepare_r(model);
    axi_mem_prepare_b(model);
    axi_mem_fill_outputs(model, inputs, outputs);
    master = &inputs->master;

    ar_handshake =
        master->arvalid != 0u &&
                outputs->target.arready != 0u
            ? 1u
            : 0u;
    aw_handshake =
        master->awvalid != 0u &&
                outputs->target.awready != 0u
            ? 1u
            : 0u;
    w_handshake =
        master->wvalid != 0u &&
                outputs->target.wready != 0u
            ? 1u
            : 0u;
    r_handshake =
        outputs->target.rvalid != 0u &&
                master->rready != 0u
            ? 1u
            : 0u;
    b_handshake =
        outputs->target.bvalid != 0u &&
                master->bready != 0u
            ? 1u
            : 0u;

    if (r_handshake != 0u) {
        axi_mem_accept_r(model);
    }
    if (b_handshake != 0u) {
        axi_mem_accept_b(model);
    }
    if (ar_handshake != 0u) {
        axi_mem_accept_ar(model, master);
    }
    if (aw_handshake != 0u) {
        axi_mem_accept_aw(model, master);
    }
    if (w_handshake != 0u) {
        axi_mem_accept_w(
            model, master, commit_memory);
    }
    if (model->cycle != UINT64_MAX) {
        model->cycle++;
    }
}

void npu_axi_mem_target_cycle_step(
    npu_axi_mem_target_cycle_t *model,
    const npu_axi_mem_target_cycle_inputs_t *inputs,
    npu_axi_mem_target_cycle_outputs_t *outputs)
{
    if (model == (npu_axi_mem_target_cycle_t *)0 ||
        inputs ==
            (const npu_axi_mem_target_cycle_inputs_t *)0 ||
        outputs ==
            (npu_axi_mem_target_cycle_outputs_t *)0 ||
        model->initialized == 0u) {
        return;
    }
    axi_mem_cycle_run(model, inputs, outputs, 1u);
}

void npu_axi_mem_target_cycle_eval(
    const npu_axi_mem_target_cycle_t *model,
    const npu_axi_mem_target_cycle_inputs_t *inputs,
    npu_axi_mem_target_cycle_outputs_t *outputs)
{
    npu_axi_mem_target_cycle_t preview;

    if (model ==
            (const npu_axi_mem_target_cycle_t *)0 ||
        inputs ==
            (const npu_axi_mem_target_cycle_inputs_t *)0 ||
        outputs ==
            (npu_axi_mem_target_cycle_outputs_t *)0 ||
        model->initialized == 0u) {
        return;
    }
    preview = *model;
    axi_mem_cycle_run(
        &preview, inputs, outputs, 0u);
}

void npu_axi_mem_master_from_mif(
    npu_axi_mem_master_outputs_t *target,
    const npu_mif_axi_outputs_t *source)
{
    if (target == (npu_axi_mem_master_outputs_t *)0 ||
        source == (const npu_mif_axi_outputs_t *)0) {
        return;
    }
    (void)memset(target, 0, sizeof(*target));
#define NPU_AXI_COPY_MASTER_FIELD(name) \
    target->name = source->name
    NPU_AXI_COPY_MASTER_FIELD(awid);
    NPU_AXI_COPY_MASTER_FIELD(awaddr);
    NPU_AXI_COPY_MASTER_FIELD(awlen);
    NPU_AXI_COPY_MASTER_FIELD(awsize);
    NPU_AXI_COPY_MASTER_FIELD(awburst);
    NPU_AXI_COPY_MASTER_FIELD(awlock);
    NPU_AXI_COPY_MASTER_FIELD(awcache);
    NPU_AXI_COPY_MASTER_FIELD(awprot);
    NPU_AXI_COPY_MASTER_FIELD(awqos);
    NPU_AXI_COPY_MASTER_FIELD(awvalid);
    NPU_AXI_COPY_MASTER_FIELD(wdata);
    NPU_AXI_COPY_MASTER_FIELD(wstrb);
    NPU_AXI_COPY_MASTER_FIELD(wlast);
    NPU_AXI_COPY_MASTER_FIELD(wvalid);
    NPU_AXI_COPY_MASTER_FIELD(bready);
    NPU_AXI_COPY_MASTER_FIELD(arid);
    NPU_AXI_COPY_MASTER_FIELD(araddr);
    NPU_AXI_COPY_MASTER_FIELD(arlen);
    NPU_AXI_COPY_MASTER_FIELD(arsize);
    NPU_AXI_COPY_MASTER_FIELD(arburst);
    NPU_AXI_COPY_MASTER_FIELD(arlock);
    NPU_AXI_COPY_MASTER_FIELD(arcache);
    NPU_AXI_COPY_MASTER_FIELD(arprot);
    NPU_AXI_COPY_MASTER_FIELD(arqos);
    NPU_AXI_COPY_MASTER_FIELD(arvalid);
    NPU_AXI_COPY_MASTER_FIELD(rready);
#undef NPU_AXI_COPY_MASTER_FIELD
}

void npu_axi_mem_target_to_mif(
    npu_mif_axi_inputs_t *target,
    const npu_axi_mem_target_outputs_t *source)
{
    if (target == (npu_mif_axi_inputs_t *)0 ||
        source ==
            (const npu_axi_mem_target_outputs_t *)0) {
        return;
    }
    (void)memset(target, 0, sizeof(*target));
#define NPU_AXI_COPY_TARGET_FIELD(name) \
    target->name = source->name
    NPU_AXI_COPY_TARGET_FIELD(awready);
    NPU_AXI_COPY_TARGET_FIELD(wready);
    NPU_AXI_COPY_TARGET_FIELD(bvalid);
    NPU_AXI_COPY_TARGET_FIELD(bid);
    NPU_AXI_COPY_TARGET_FIELD(bresp);
    NPU_AXI_COPY_TARGET_FIELD(arready);
    NPU_AXI_COPY_TARGET_FIELD(rvalid);
    NPU_AXI_COPY_TARGET_FIELD(rid);
    NPU_AXI_COPY_TARGET_FIELD(rdata);
    NPU_AXI_COPY_TARGET_FIELD(rresp);
    NPU_AXI_COPY_TARGET_FIELD(rlast);
#undef NPU_AXI_COPY_TARGET_FIELD
}

void npu_axi_mem_master_from_gc(
    npu_axi_mem_master_outputs_t *target,
    const npu_gc_axi_bus_outputs_t *source)
{
    if (target == (npu_axi_mem_master_outputs_t *)0 ||
        source ==
            (const npu_gc_axi_bus_outputs_t *)0) {
        return;
    }
    (void)memset(target, 0, sizeof(*target));
#define NPU_AXI_COPY_MASTER_FIELD(name) \
    target->name = source->name
    NPU_AXI_COPY_MASTER_FIELD(awid);
    NPU_AXI_COPY_MASTER_FIELD(awaddr);
    NPU_AXI_COPY_MASTER_FIELD(awlen);
    NPU_AXI_COPY_MASTER_FIELD(awsize);
    NPU_AXI_COPY_MASTER_FIELD(awburst);
    NPU_AXI_COPY_MASTER_FIELD(awlock);
    NPU_AXI_COPY_MASTER_FIELD(awcache);
    NPU_AXI_COPY_MASTER_FIELD(awprot);
    NPU_AXI_COPY_MASTER_FIELD(awqos);
    NPU_AXI_COPY_MASTER_FIELD(awvalid);
    NPU_AXI_COPY_MASTER_FIELD(wdata);
    NPU_AXI_COPY_MASTER_FIELD(wstrb);
    NPU_AXI_COPY_MASTER_FIELD(wlast);
    NPU_AXI_COPY_MASTER_FIELD(wvalid);
    NPU_AXI_COPY_MASTER_FIELD(bready);
    NPU_AXI_COPY_MASTER_FIELD(arid);
    NPU_AXI_COPY_MASTER_FIELD(araddr);
    NPU_AXI_COPY_MASTER_FIELD(arlen);
    NPU_AXI_COPY_MASTER_FIELD(arsize);
    NPU_AXI_COPY_MASTER_FIELD(arburst);
    NPU_AXI_COPY_MASTER_FIELD(arlock);
    NPU_AXI_COPY_MASTER_FIELD(arcache);
    NPU_AXI_COPY_MASTER_FIELD(arprot);
    NPU_AXI_COPY_MASTER_FIELD(arqos);
    NPU_AXI_COPY_MASTER_FIELD(arvalid);
    NPU_AXI_COPY_MASTER_FIELD(rready);
#undef NPU_AXI_COPY_MASTER_FIELD
}

void npu_axi_mem_target_to_gc(
    npu_gc_axi_bus_inputs_t *target,
    const npu_axi_mem_target_outputs_t *source)
{
    if (target == (npu_gc_axi_bus_inputs_t *)0 ||
        source ==
            (const npu_axi_mem_target_outputs_t *)0) {
        return;
    }
    (void)memset(target, 0, sizeof(*target));
#define NPU_AXI_COPY_TARGET_FIELD(name) \
    target->name = source->name
    NPU_AXI_COPY_TARGET_FIELD(awready);
    NPU_AXI_COPY_TARGET_FIELD(wready);
    NPU_AXI_COPY_TARGET_FIELD(bvalid);
    NPU_AXI_COPY_TARGET_FIELD(bid);
    NPU_AXI_COPY_TARGET_FIELD(bresp);
    NPU_AXI_COPY_TARGET_FIELD(arready);
    NPU_AXI_COPY_TARGET_FIELD(rvalid);
    NPU_AXI_COPY_TARGET_FIELD(rid);
    NPU_AXI_COPY_TARGET_FIELD(rdata);
    NPU_AXI_COPY_TARGET_FIELD(rresp);
    NPU_AXI_COPY_TARGET_FIELD(rlast);
#undef NPU_AXI_COPY_TARGET_FIELD
}
