#include "npu_internal.h"
#include "npu_inline.h"

#include <limits.h>
#include <string.h>

static void npu_fence_record_one(npu_task_slot_t *fence,
                                 const npu_task_slot_t *completed);
static uint64_t npu_matrix_accum_timing(
    const npu_model_t *model,
    uint8_t opcode,
    const npu_matrix_desc_t *desc);

static void npu_perf_reset(npu_perf_t *perf)
{
    perf->core_active_cycles = 0u;
    perf->cmd_accepted = 0u;
    perf->task_success = 0u;
    perf->task_failed = 0u;
    perf->dma_read_bytes = 0u;
    perf->dma_write_bytes = 0u;
    perf->dma_stall_cycles = 0u;
    perf->l1_bank_stall_cycles = 0u;
    perf->matrix_mac_active_cycles = 0u;
    perf->matrix_accum_active_cycles = 0u;
    perf->matrix_overlap_cycles = 0u;
    perf->matrix_hazard_stall_cycles = 0u;
    perf->matrix_operand_stall_cycles = 0u;
    perf->ive_active_cycles = 0u;
    perf->cme_fp_active_cycles = 0u;
    perf->cme_l1_stall_cycles = 0u;
    perf->int_saturate_count = 0u;
    perf->all_mask_row_count = 0u;
    perf->ecc_corrected_count = 0u;
}

void npu_config_reference(npu_config_t *config)
{
    static const uint32_t timeout_values[NPU_TIMEOUT_CLASS_NUM] = {
        0u,
        1024u,
        4096u,
        16384u,
        65536u,
        262144u,
        1048576u,
        4194304u,
        16777216u,
        67108864u,
        268435456u,
        1073741824u,
        0xffffffffu,
        0u,
        0u,
        0u
    };
    uint32_t index;

    if (config == (npu_config_t *)0) {
        return;
    }
    config->l1_bytes = NPU_REF_L1_BYTES;
    config->l1_banks = NPU_REF_L1_BANKS;
    config->l1_read_latency = NPU_REF_L1_RD_LATENCY;
    config->mt = NPU_REF_MT;
    config->kt = NPU_REF_KT;
    config->nt = NPU_REF_NT;
    config->vector_lanes = NPU_REF_VLANES;
    config->cme_lanes = NPU_REF_CME_LANES;
    config->task_entries = NPU_REF_TASK_NUM;
    config->descriptor_slots = NPU_REF_DESC_SLOTS;
    config->cfe_fifo_depth = NPU_REF_CFE_FIFO_DEPTH;
    config->dma_outstanding = NPU_REF_DMA_OUTSTANDING;
    config->mif_outstanding = NPU_REF_MIF_OUTSTANDING;
    config->dma_max_burst_beats = NPU_REF_DMA_MAX_BURST_BEATS;
    config->l1_starve_limit = NPU_REF_L1_STARVE_LIMIT;
    config->cme_scratch_elems = NPU_REF_CME_SCRATCH_ELEMS;
    for (index = 0u; index < NPU_TIMEOUT_CLASS_NUM; index++) {
        config->timeout_cycles[index] = timeout_values[index];
    }
    config->ddr_read_latency = 20u;
    config->ddr_write_latency = 12u;
    config->cfe_beat_timeout = 32u;
}

static int npu_config_valid(const npu_config_t *config)
{
    return config != (const npu_config_t *)0 &&
           config->l1_bytes != 0u &&
           config->l1_banks != 0u &&
           config->l1_read_latency != 0u &&
           config->mt != 0u &&
           config->kt != 0u &&
           config->nt != 0u &&
           config->vector_lanes != 0u &&
           config->cme_lanes == NPU_REF_CME_LANES &&
           config->task_entries != 0u &&
           config->task_entries <= NPU_MAX_TASKS &&
           config->descriptor_slots >= config->task_entries &&
           config->cfe_fifo_depth != 0u &&
           config->dma_outstanding != 0u &&
           config->mif_outstanding >= config->dma_outstanding &&
           config->dma_max_burst_beats != 0u;
}

npu_status_t npu_model_init(npu_model_t *model,
                            const npu_config_t *config,
                            uint8_t *l1,
                            size_t l1_size,
                            uint8_t *ddr,
                            size_t ddr_size)
{
    if (model == (npu_model_t *)0 ||
        !npu_config_valid(config) ||
        l1 == (uint8_t *)0 ||
        ddr == (uint8_t *)0 ||
        l1_size < config->l1_bytes) {
        return NPU_STATUS_BAD_DESC;
    }
    model->config = *config;
    model->l1 = l1;
    model->l1_size = l1_size;
    model->ddr = ddr;
    model->ddr_size = ddr_size;
    model->internal_fault_capture = (void *)0;
    model->internal_bus_trace = (void *)0;
    npu_model_reset(model);
    return NPU_STATUS_SUCCESS;
}

void npu_model_reset(npu_model_t *model)
{
    uint32_t index;

    if (model == (npu_model_t *)0) {
        return;
    }
    model->internal_fault_capture = (void *)0;
    model->internal_bus_trace = (void *)0;
    model->cycle = 0u;
    model->next_submit_seq = 0u;
    model->cfe.have_low_beat = 0u;
    model->cfe.response_valid = 0u;
    model->cfe.low_beat = 0u;
    model->cfe.response_data = 0u;
    model->cfe.wait_cycles = 0u;
    for (index = 0u; index < NPU_ENGINE_COUNT; index++) {
        model->active_slot[index] = -1;
    }
    model->matrix_accum_slot = -1;
    for (index = 0u; index < NPU_MAX_TASKS; index++) {
        model->tasks[index].state = NPU_TASK_FREE;
        model->tasks[index].submit_seq = 0u;
        model->tasks[index].estimated_cycles = 0u;
        model->tasks[index].remaining_cycles = 0u;
        model->tasks[index].matrix_accum_cycles = 0u;
        model->tasks[index].fence_error_seq = UINT64_MAX;
        model->tasks[index].fence_error_status = NPU_STATUS_SUCCESS;
        model->tasks[index].matrix_in_accum = 0u;
        model->tasks[index].waiters_released = 1u;
        model->tasks[index].result.command_id = 0u;
        model->tasks[index].result.status = NPU_STATUS_NOT_FOUND;
        model->tasks[index].result.user_tag = 0u;
        model->tasks[index].result.submit_cycle = 0u;
        model->tasks[index].result.start_cycle = 0u;
        model->tasks[index].result.end_cycle = 0u;
        model->tasks[index].result.progress = 0u;
        model->tasks[index].result.fault_addr = 0u;
        model->tasks[index].result.error_info = 0u;
        model->tasks[index].result.done_flags = 0u;
    }
    for (index = 0u; index < NPU_EVENT_NUM; index++) {
        model->events[index].state = NPU_EVENT_UNUSED;
        model->events[index].generation = 0u;
        model->events[index].status = NPU_STATUS_SUCCESS;
        model->events[index].waiter_count = 0u;
        model->events[index].producer_task_id = 0u;
    }
    npu_perf_reset(&model->perf);
}

npu_event_ref_t npu_event_none(void)
{
    npu_event_ref_t event;
    event.id = NPU_EVENT_NONE_ID;
    event.generation = NPU_EVENT_NONE_GENERATION;
    return event;
}

static int npu_event_is_none(npu_event_ref_t event)
{
    return event.id == NPU_EVENT_NONE_ID &&
           event.generation == NPU_EVENT_NONE_GENERATION;
}

static int npu_event_ref_valid(npu_event_ref_t event)
{
    return npu_event_is_none(event) ||
           (event.id < NPU_EVENT_NUM && event.generation < 16u);
}

static int npu_event_equal(npu_event_ref_t first,
                           npu_event_ref_t second)
{
    return first.id == second.id &&
           first.generation == second.generation;
}

static void npu_resolve_inline_event_generations(
    const npu_model_t *model,
    npu_task_request_t *request)
{
    uint32_t index;

    if (request->cmd.inline_format == 0u) {
        return;
    }
    for (index = 0u; index < 2u; index++) {
        npu_event_ref_t *event = &request->cmd.wait_event[index];

        if (event->id < NPU_EVENT_NUM) {
            event->generation = model->events[event->id].generation;
        }
    }
    if (request->cmd.signal_event.id < NPU_EVENT_NUM) {
        request->cmd.signal_event.generation =
            model->events[request->cmd.signal_event.id].generation;
    }
    if (request->cmd.engine == NPU_ENGINE_CONTROL) {
        request->desc.control.event0 =
            request->cmd.wait_event[0];
        request->desc.control.event1 =
            request->cmd.wait_event[1];
        request->desc.control.target =
            request->cmd.signal_event;
    }
    if (request->cmd.engine == NPU_ENGINE_CONTROL &&
        request->cmd.opcode == NPU_CTRL_EVENT_REARM &&
        request->cmd.signal_event.id < NPU_EVENT_NUM) {
        request->desc.control.event0 =
            request->cmd.signal_event;
        request->desc.control.target.id =
            request->cmd.signal_event.id;
        request->desc.control.target.generation =
            (uint8_t)((request->cmd.signal_event.generation + 1u) &
                      0x0fu);
    }
}

static int npu_opcode_valid(npu_engine_t engine, uint8_t opcode)
{
    if (engine == NPU_ENGINE_CONTROL) {
        return opcode <= NPU_CTRL_GLOBAL_FENCE;
    }
    if (engine == NPU_ENGINE_DMA) {
        return opcode >= NPU_DMA_COPY_1D &&
               opcode <= NPU_DMA_SPLIT;
    }
    if (engine == NPU_ENGINE_MATRIX) {
        return opcode >= NPU_MATRIX_GEMM &&
               opcode <= NPU_MATRIX_GEMM_ZERO;
    }
    if (engine == NPU_ENGINE_VECTOR) {
        return opcode >= NPU_VECTOR_ADD &&
               opcode <= NPU_VECTOR_RELU;
    }
    if (engine == NPU_ENGINE_COMPLEX) {
        return opcode == NPU_COMPLEX_ACT ||
               opcode == NPU_COMPLEX_SOFTMAX ||
               opcode == NPU_COMPLEX_NORM ||
               opcode == NPU_COMPLEX_STAT ||
               opcode == NPU_COMPLEX_ADD_RESCALE;
    }
    return 0;
}

static int npu_control_request_valid(
    const npu_task_request_t *request)
{
    const npu_cmd_t *cmd = &request->cmd;
    const npu_control_desc_t *desc = &request->desc.control;

    if (cmd->opcode == NPU_CTRL_NOP) {
        return npu_event_is_none(cmd->wait_event[0]) &&
               npu_event_is_none(cmd->wait_event[1]) &&
               npu_event_is_none(cmd->signal_event) &&
               desc->join_mode == 0u &&
               desc->engine_mask == 0u;
    }
    if (cmd->opcode == NPU_CTRL_EVENT_SIGNAL) {
        return npu_event_is_none(cmd->wait_event[0]) &&
               npu_event_is_none(cmd->wait_event[1]) &&
               !npu_event_is_none(cmd->signal_event) &&
               npu_event_equal(desc->target, cmd->signal_event) &&
               desc->join_mode == 0u &&
               desc->engine_mask == 0u;
    }
    if (cmd->opcode == NPU_CTRL_EVENT_REARM) {
        if (cmd->inline_format != 0u) {
            return npu_event_is_none(cmd->wait_event[0]) &&
                   npu_event_is_none(cmd->wait_event[1]) &&
                   !npu_event_is_none(cmd->signal_event) &&
                   npu_event_equal(
                       desc->event0, cmd->signal_event) &&
                   desc->event0.id == desc->target.id &&
                   desc->target.generation ==
                       (uint8_t)((desc->event0.generation + 1u) &
                                 0x0fu) &&
                   desc->join_mode == 0u &&
                   desc->engine_mask == 0u;
        }
        return npu_event_is_none(cmd->wait_event[0]) &&
               npu_event_is_none(cmd->wait_event[1]) &&
               npu_event_is_none(cmd->signal_event) &&
               desc->event0.id == desc->target.id &&
               desc->target.generation ==
                   (uint8_t)((desc->event0.generation + 1u) & 0x0fu) &&
               desc->join_mode == 0u &&
               desc->engine_mask == 0u;
    }
    if (cmd->opcode == NPU_CTRL_EVENT_JOIN) {
        return desc->join_mode <= 2u &&
               desc->engine_mask == 0u &&
               !npu_event_equal(desc->event0, desc->event1) &&
               npu_event_equal(desc->event0, cmd->wait_event[0]) &&
               npu_event_equal(desc->event1, cmd->wait_event[1]) &&
               npu_event_equal(desc->target, cmd->signal_event);
    }
    if (cmd->opcode == NPU_CTRL_GLOBAL_FENCE) {
        return npu_event_is_none(cmd->wait_event[0]) &&
               npu_event_is_none(cmd->wait_event[1]) &&
               desc->join_mode == 0u &&
               (desc->engine_mask & 0xf0u) == 0u;
    }
    return 0;
}

npu_status_t npu_event_reserve(npu_model_t *model,
                               uint8_t event_id,
                               uint8_t generation,
                               uint16_t producer_task_id)
{
    npu_event_entry_t *entry;

    if (model == (npu_model_t *)0 ||
        event_id >= NPU_EVENT_NUM ||
        generation >= 16u ||
        producer_task_id > 0x0fffu) {
        return NPU_STATUS_BAD_DESC;
    }
    entry = &model->events[event_id];
    if (entry->state != NPU_EVENT_FREE ||
        entry->generation != generation ||
        entry->waiter_count != 0u) {
        return NPU_STATUS_BUSY;
    }
    entry->state = NPU_EVENT_RESERVED;
    entry->status = NPU_STATUS_BUSY;
    entry->producer_task_id = producer_task_id;
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_event_rearm(npu_model_t *model,
                             uint8_t event_id,
                             uint8_t generation)
{
    npu_event_entry_t *entry;
    uint8_t expected_generation;

    if (model == (npu_model_t *)0 ||
        event_id >= NPU_EVENT_NUM ||
        generation >= 16u) {
        return NPU_STATUS_BAD_DESC;
    }
    entry = &model->events[event_id];
    expected_generation =
        (uint8_t)((entry->generation + 1u) & 0x0fu);
    if ((entry->state != NPU_EVENT_SUCCESS &&
         entry->state != NPU_EVENT_FAILED) ||
        entry->waiter_count != 0u ||
        generation != expected_generation) {
        return NPU_STATUS_BAD_DESC;
    }
    entry->state = NPU_EVENT_FREE;
    entry->generation = generation;
    entry->status = NPU_STATUS_SUCCESS;
    entry->producer_task_id = 0u;
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_event_signal(npu_model_t *model,
                              npu_event_ref_t event,
                              npu_status_t status)
{
    npu_event_entry_t *entry;

    if (model == (npu_model_t *)0 ||
        event.id >= NPU_EVENT_NUM ||
        event.generation >= 16u ||
        status < NPU_STATUS_SUCCESS ||
        status > NPU_STATUS_ADDR_OVERLAP) {
        return NPU_STATUS_BAD_DESC;
    }
    entry = &model->events[event.id];
    if (entry->state != NPU_EVENT_RESERVED ||
        entry->generation != event.generation ||
        status == NPU_STATUS_BUSY ||
        status == NPU_STATUS_NOT_FOUND) {
        return NPU_STATUS_BAD_DESC;
    }
    entry->status = status;
    entry->state = status == NPU_STATUS_SUCCESS
                       ? NPU_EVENT_SUCCESS
                       : NPU_EVENT_FAILED;
    return NPU_STATUS_SUCCESS;
}

static uint16_t npu_event_pack(npu_event_ref_t event)
{
    return (uint16_t)(((uint16_t)event.generation << 8) | event.id);
}

npu_status_t npu_cmd_decode(uint64_t low_beat,
                            uint64_t high_beat,
                            npu_cmd_t *cmd)
{
    uint8_t compact_opcode;
    uint8_t packed_flags;
    uint8_t wait0;
    uint8_t wait1;
    uint8_t signal;

    if (cmd == (npu_cmd_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    cmd->desc_addr = 0u;
    cmd->command_id = 0u;
    cmd->engine = NPU_ENGINE_CONTROL;
    cmd->opcode = 0u;
    cmd->header_flags = 0u;
    cmd->wait_event[0] = npu_event_none();
    cmd->wait_event[1] = npu_event_none();
    cmd->signal_event = npu_event_none();
    cmd->header_version = 0u;
    cmd->timeout_class = 0u;
    cmd->user_tag = 0u;
    cmd->inline_payload_lo = 0u;
    cmd->inline_payload_hi = 0u;
    cmd->inline_format = 0u;
    cmd->inline_dtype = NPU_DTYPE_INT4;

    compact_opcode =
        (uint8_t)((high_beat >> 59u) & UINT64_C(0x1f));
    packed_flags =
        (uint8_t)((high_beat >> 20u) & UINT64_C(0x0f));
    wait0 = (uint8_t)((high_beat >> 40u) & UINT64_C(0xff));
    wait1 = (uint8_t)((high_beat >> 32u) & UINT64_C(0xff));
    signal = (uint8_t)((high_beat >> 24u) & UINT64_C(0xff));

    cmd->inline_payload_lo = low_beat;
    cmd->inline_payload_hi =
        (uint16_t)(high_beat & UINT64_C(0xffff));
    cmd->inline_format = 1u;
    cmd->inline_dtype =
        (npu_dtype_t)((high_beat >> 16u) & UINT64_C(0x03));
    cmd->timeout_class =
        (uint8_t)((high_beat >> 18u) & UINT64_C(0x03));
    cmd->header_flags =
        (uint16_t)(((packed_flags >> 3u) & 0x01u) |
                   (((packed_flags >> 2u) & 0x01u) << 1u) |
                   (((packed_flags >> 1u) & 0x01u) << 2u) |
                   ((packed_flags & 0x01u) << 4u) |
                   ((uint16_t)cmd->timeout_class << 6u));
    cmd->wait_event[0].id = wait0;
    cmd->wait_event[0].generation =
        wait0 == NPU_EVENT_NONE_ID
            ? NPU_EVENT_NONE_GENERATION
            : 0u;
    cmd->wait_event[1].id = wait1;
    cmd->wait_event[1].generation =
        wait1 == NPU_EVENT_NONE_ID
            ? NPU_EVENT_NONE_GENERATION
            : 0u;
    cmd->signal_event.id = signal;
    cmd->signal_event.generation =
        signal == NPU_EVENT_NONE_ID
            ? NPU_EVENT_NONE_GENERATION
            : 0u;
    cmd->command_id =
        (uint16_t)((high_beat >> 48u) & UINT64_C(0x07ff));
    if (!npu_dtype_valid(cmd->inline_dtype)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (!npu_inline_opcode_decode(
            compact_opcode, &cmd->engine, &cmd->opcode)) {
        return NPU_STATUS_ILLEGAL_OPCODE;
    }
    if (cmd->signal_event.id != NPU_EVENT_NONE_ID &&
        ((cmd->signal_event.id == cmd->wait_event[0].id &&
          cmd->signal_event.generation ==
              cmd->wait_event[0].generation) ||
         (cmd->signal_event.id == cmd->wait_event[1].id &&
          cmd->signal_event.generation ==
              cmd->wait_event[1].generation))) {
        return NPU_STATUS_BAD_DESC;
    }
    return NPU_STATUS_SUCCESS;
}

static npu_event_ref_t npu_event_unpack(uint16_t value)
{
    npu_event_ref_t event;

    event.id = (uint8_t)(value & 0xffu);
    event.generation = (uint8_t)((value >> 8) & 0x0fu);
    return event;
}

npu_status_t npu_cmd_decode_descriptor(uint64_t low_beat,
                                       uint64_t high_beat,
                                       npu_cmd_t *cmd)
{
    uint16_t flags;

    if (cmd == (npu_cmd_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    memset(cmd, 0, sizeof(*cmd));
    cmd->desc_addr = low_beat & UINT64_C(0x0000ffffffffffff);
    cmd->command_id = (uint16_t)((low_beat >> 48) & 0x0fffu);
    cmd->engine = (npu_engine_t)((low_beat >> 60) & 0x0fu);
    cmd->opcode = (uint8_t)(high_beat & 0xffu);
    flags = (uint16_t)((high_beat >> 8) & 0x0fffu);
    cmd->header_flags = flags;
    cmd->wait_event[0] =
        npu_event_unpack((uint16_t)((high_beat >> 20) & 0x0fffu));
    cmd->wait_event[1] =
        npu_event_unpack((uint16_t)((high_beat >> 32) & 0x0fffu));
    cmd->signal_event =
        npu_event_unpack((uint16_t)((high_beat >> 44) & 0x0fffu));
    cmd->header_version = (uint8_t)(high_beat >> 56);
    cmd->timeout_class = (uint8_t)((flags >> 6) & 0x0fu);

    if (cmd->header_version != NPU_WIRE_HEADER_VERSION ||
        cmd->engine > NPU_ENGINE_COMPLEX ||
        (cmd->desc_addr & 63u) != 0u ||
        (flags & 0x0c00u) != 0u ||
        !npu_event_ref_valid(cmd->wait_event[0]) ||
        !npu_event_ref_valid(cmd->wait_event[1]) ||
        !npu_event_ref_valid(cmd->signal_event)) {
        return NPU_STATUS_BAD_DESC;
    }
    return NPU_STATUS_SUCCESS;
}

void npu_cmd_encode(const npu_cmd_t *cmd,
                    uint64_t *low_beat,
                    uint64_t *high_beat)
{
    uint16_t flags;

    if (cmd == (const npu_cmd_t *)0 ||
        low_beat == (uint64_t *)0 ||
        high_beat == (uint64_t *)0) {
        return;
    }
    if (cmd->inline_format != 0u) {
        uint8_t compact_opcode;
        uint8_t packed_flags;

        if (!npu_inline_opcode_encode(
                cmd->engine, cmd->opcode, &compact_opcode) ||
            cmd->command_id > 0x07ffu ||
            cmd->timeout_class > 3u ||
            !npu_dtype_valid(cmd->inline_dtype) ||
            !npu_event_ref_valid(cmd->wait_event[0]) ||
            !npu_event_ref_valid(cmd->wait_event[1]) ||
            !npu_event_ref_valid(cmd->signal_event) ||
            (cmd->wait_event[0].id != NPU_EVENT_NONE_ID &&
             cmd->wait_event[0].generation != 0u) ||
            (cmd->wait_event[1].id != NPU_EVENT_NONE_ID &&
             cmd->wait_event[1].generation != 0u) ||
            (cmd->signal_event.id != NPU_EVENT_NONE_ID &&
             cmd->signal_event.generation != 0u)) {
            *low_beat = 0u;
            *high_beat = 0u;
            return;
        }
        packed_flags =
            (uint8_t)(((cmd->header_flags >> 0u) & 0x01u) << 3u);
        packed_flags |=
            (uint8_t)(((cmd->header_flags >> 1u) & 0x01u) << 2u);
        packed_flags |=
            (uint8_t)(((cmd->header_flags >> 2u) & 0x01u) << 1u);
        packed_flags |=
            (uint8_t)((cmd->header_flags >> 4u) & 0x01u);
        *low_beat = cmd->inline_payload_lo;
        *high_beat =
            (uint64_t)cmd->inline_payload_hi |
            ((uint64_t)(cmd->inline_dtype & 0x03u) << 16u) |
            ((uint64_t)(cmd->timeout_class & 0x03u) << 18u) |
            ((uint64_t)packed_flags << 20u) |
            ((uint64_t)cmd->signal_event.id << 24u) |
            ((uint64_t)cmd->wait_event[1].id << 32u) |
            ((uint64_t)cmd->wait_event[0].id << 40u) |
            ((uint64_t)(cmd->command_id & 0x07ffu) << 48u) |
            ((uint64_t)compact_opcode << 59u);
        return;
    }
    flags = (uint16_t)(cmd->header_flags & 0x0fffu);
    flags &= (uint16_t)~0x03c0u;
    flags |= (uint16_t)((cmd->timeout_class & 0x0fu) << 6);
    *low_beat =
        (cmd->desc_addr & UINT64_C(0x0000ffffffffffff)) |
        ((uint64_t)(cmd->command_id & 0x0fffu) << 48) |
        ((uint64_t)(cmd->engine & 0x0fu) << 60);
    *high_beat =
        (uint64_t)cmd->opcode |
        ((uint64_t)flags << 8) |
        ((uint64_t)npu_event_pack(cmd->wait_event[0]) << 20) |
        ((uint64_t)npu_event_pack(cmd->wait_event[1]) << 32) |
        ((uint64_t)npu_event_pack(cmd->signal_event) << 44) |
        ((uint64_t)cmd->header_version << 56);
}

static int npu_command_id_busy(const npu_model_t *model,
                               uint16_t command_id)
{
    uint32_t index;
    for (index = 0u; index < model->config.task_entries; index++) {
        if (model->tasks[index].state != NPU_TASK_FREE &&
            model->tasks[index].request.cmd.command_id == command_id) {
            return 1;
        }
    }
    return 0;
}

static int npu_signal_event_reserved(const npu_model_t *model,
                                     npu_event_ref_t event)
{
    uint32_t index;
    if (npu_event_is_none(event)) {
        return 0;
    }
    for (index = 0u; index < model->config.task_entries; index++) {
        if ((model->tasks[index].state == NPU_TASK_WAITING ||
             model->tasks[index].state == NPU_TASK_RUNNING) &&
            model->tasks[index].request.cmd.signal_event.id == event.id &&
            model->tasks[index].request.cmd.signal_event.generation ==
                event.generation) {
            return 1;
        }
    }
    return 0;
}

static npu_status_t npu_submit_event_check(const npu_model_t *model,
                                           const npu_cmd_t *cmd)
{
    uint32_t index;
    npu_event_ref_t event;

    for (index = 0u; index < 2u; index++) {
        event = cmd->wait_event[index];
        if (npu_event_is_none(event)) {
            continue;
        }
        if (!npu_event_ref_valid(event) ||
            model->events[event.id].state == NPU_EVENT_UNUSED ||
            model->events[event.id].generation != event.generation) {
            return NPU_STATUS_BAD_DESC;
        }
    }
    event = cmd->signal_event;
    if (cmd->inline_format != 0u &&
        cmd->engine == NPU_ENGINE_CONTROL &&
        cmd->opcode == NPU_CTRL_EVENT_REARM) {
        if (npu_event_is_none(event) ||
            !npu_event_ref_valid(event) ||
            model->events[event.id].generation != event.generation ||
            (model->events[event.id].state != NPU_EVENT_SUCCESS &&
             model->events[event.id].state != NPU_EVENT_FAILED) ||
            model->events[event.id].waiter_count != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        return NPU_STATUS_SUCCESS;
    }
    if (!npu_event_is_none(event)) {
        if (!npu_event_ref_valid(event) ||
            model->events[event.id].state != NPU_EVENT_FREE ||
            model->events[event.id].generation != event.generation ||
            npu_signal_event_reserved(model, event)) {
            return NPU_STATUS_BAD_DESC;
        }
        for (index = 0u; index < 2u; index++) {
            if (!npu_event_is_none(cmd->wait_event[index]) &&
                cmd->wait_event[index].id == event.id &&
                cmd->wait_event[index].generation == event.generation) {
                return NPU_STATUS_BAD_DESC;
            }
        }
    }
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_model_submit(npu_model_t *model,
                              const npu_task_request_t *request)
{
    npu_task_request_t resolved_request;
    uint32_t index;
    uint32_t free_slot = NPU_MAX_TASKS;
    npu_status_t status;

    if (model == (npu_model_t *)0 ||
        request == (const npu_task_request_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    if (request->cmd.inline_format != 0u) {
        resolved_request = *request;
        npu_resolve_inline_event_generations(
            model, &resolved_request);
        request = &resolved_request;
    }
    if ((request->cmd.inline_format == 0u &&
         request->cmd.header_version != 1u) ||
        request->cmd.engine > NPU_ENGINE_COMPLEX ||
        request->cmd.command_id >
            (request->cmd.inline_format != 0u
                 ? 0x07ffu
                 : 0x0fffu) ||
        request->cmd.timeout_class >= NPU_TIMEOUT_CLASS_NUM ||
        (request->cmd.header_flags & 0x0c00u) != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (!npu_opcode_valid(request->cmd.engine,
                          request->cmd.opcode)) {
        return NPU_STATUS_ILLEGAL_OPCODE;
    }
    if (request->cmd.engine == NPU_ENGINE_CONTROL &&
        !npu_control_request_valid(request)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (npu_command_id_busy(model, request->cmd.command_id)) {
        return NPU_STATUS_BUSY;
    }
    status = npu_submit_event_check(model, &request->cmd);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    for (index = 0u; index < model->config.task_entries; index++) {
        if (model->tasks[index].state == NPU_TASK_FREE) {
            free_slot = index;
            break;
        }
    }
    if (free_slot == NPU_MAX_TASKS) {
        return NPU_STATUS_BUSY;
    }

    model->tasks[free_slot].state = NPU_TASK_WAITING;
    model->tasks[free_slot].request = *request;
    model->tasks[free_slot].submit_seq = model->next_submit_seq++;
    model->tasks[free_slot].estimated_cycles =
        npu_estimate_task_cycles(model, request);
    if (model->tasks[free_slot].estimated_cycles == 0u) {
        model->tasks[free_slot].estimated_cycles = 1u;
    }
    model->tasks[free_slot].remaining_cycles = 0u;
    model->tasks[free_slot].matrix_accum_cycles =
        request->cmd.engine == NPU_ENGINE_MATRIX
            ? npu_matrix_accum_timing(
                  model, request->cmd.opcode,
                  &request->desc.matrix)
            : 0u;
    model->tasks[free_slot].fence_error_seq = UINT64_MAX;
    model->tasks[free_slot].fence_error_status = NPU_STATUS_SUCCESS;
    model->tasks[free_slot].matrix_in_accum = 0u;
    model->tasks[free_slot].waiters_released = 0u;
    model->tasks[free_slot].result.command_id = request->cmd.command_id;
    model->tasks[free_slot].result.status = NPU_STATUS_BUSY;
    model->tasks[free_slot].result.user_tag = request->cmd.user_tag;
    model->tasks[free_slot].result.submit_cycle = model->cycle;
    model->tasks[free_slot].result.start_cycle = 0u;
    model->tasks[free_slot].result.end_cycle = 0u;
    model->tasks[free_slot].result.progress = 0u;
    model->tasks[free_slot].result.fault_addr = 0u;
    model->tasks[free_slot].result.error_info = 0u;
    model->tasks[free_slot].result.done_flags = 0u;
    if (request->cmd.engine == NPU_ENGINE_CONTROL &&
        request->cmd.opcode == NPU_CTRL_GLOBAL_FENCE) {
        for (index = 0u; index < model->config.task_entries; index++) {
            if (index != free_slot &&
                model->tasks[index].state == NPU_TASK_TERMINAL) {
                npu_fence_record_one(&model->tasks[free_slot],
                                     &model->tasks[index]);
            }
        }
    }
    for (index = 0u; index < 2u; index++) {
        npu_event_ref_t wait_event = request->cmd.wait_event[index];
        if (npu_event_is_none(wait_event) ||
            wait_event.id >= NPU_EVENT_NUM) {
            continue;
        }
        if (index == 1u &&
            wait_event.id == request->cmd.wait_event[0].id &&
            wait_event.generation ==
                request->cmd.wait_event[0].generation) {
            continue;
        }
        model->events[wait_event.id].waiter_count++;
    }
    if (!npu_event_is_none(request->cmd.signal_event) &&
        !(request->cmd.inline_format != 0u &&
          request->cmd.engine == NPU_ENGINE_CONTROL &&
          request->cmd.opcode == NPU_CTRL_EVENT_REARM)) {
        npu_event_entry_t *signal =
            &model->events[request->cmd.signal_event.id];
        signal->state = NPU_EVENT_RESERVED;
        signal->generation = request->cmd.signal_event.generation;
        signal->status = NPU_STATUS_BUSY;
        signal->producer_task_id = request->cmd.command_id;
    }
    model->perf.cmd_accepted++;
    return NPU_STATUS_SUCCESS;
}

uint64_t npu_task_desc_beats(npu_engine_t engine)
{
    if (engine == NPU_ENGINE_CONTROL) {
        return 8u;
    }
    if (engine == NPU_ENGINE_VECTOR) {
        return 24u;
    }
    return 32u;
}

static uint64_t npu_product_shape(const uint32_t shape[], uint32_t rank)
{
    uint64_t product = 1u;
    uint32_t index;

    for (index = 0u; index < rank; index++) {
        if (shape[index] == 0u) {
            return 0u;
        }
        if (product > UINT64_MAX / shape[index]) {
            return UINT64_MAX;
        }
        product *= shape[index];
    }
    return product;
}

static uint64_t npu_timing_add_limit(uint64_t left,
                                     uint64_t right)
{
    return UINT64_MAX - left < right
               ? UINT64_MAX
               : left + right;
}

static uint64_t npu_timing_mul_limit(uint64_t left,
                                     uint64_t right)
{
    return left != 0u && right > UINT64_MAX / left
               ? UINT64_MAX
               : left * right;
}

static uint64_t npu_dma_timing(const npu_model_t *model,
                               uint8_t opcode,
                               const npu_dma_desc_t *desc)
{
    uint64_t elements = npu_product_shape(desc->shape, desc->rank);
    uint64_t src_bytes;
    uint64_t dst_bytes;
    uint64_t cycles = 3u;

    if (opcode == NPU_DMA_PACK || opcode == NPU_DMA_SPLIT) {
        src_bytes = npu_timing_mul_limit(
            desc->segment_count, desc->segment_bytes);
        dst_bytes = src_bytes;
    } else {
        src_bytes = npu_ceil_div_u64(
            npu_timing_mul_limit(
                elements, npu_dtype_bits(desc->src_dtype)),
            8u);
        dst_bytes = npu_ceil_div_u64(
            npu_timing_mul_limit(
                elements, npu_dtype_bits(desc->dst_dtype)),
            8u);
    }
    if (opcode != NPU_DMA_FILL) {
        cycles = npu_timing_add_limit(
            cycles,
            npu_ceil_div_u64(src_bytes, NPU_REF_BUS_BYTES));
        cycles = npu_timing_add_limit(
            cycles,
            desc->src_space == NPU_SPACE_DDR
                ? model->config.ddr_read_latency
                : model->config.l1_read_latency);
    }
    cycles = npu_timing_add_limit(
        cycles,
        npu_ceil_div_u64(dst_bytes, NPU_REF_BUS_BYTES));
    cycles = npu_timing_add_limit(
        cycles,
        desc->dst_space == NPU_SPACE_DDR
            ? model->config.ddr_write_latency
            : 2u);
    cycles = npu_timing_add_limit(
        cycles, npu_ceil_div_u64(elements, 8u));
    return cycles;
}

static uint64_t npu_matrix_accum_timing(
    const npu_model_t *model,
    uint8_t opcode,
    const npu_matrix_desc_t *desc)
{
    uint64_t output_elements;
    uint64_t output_beats;
    uint64_t cycles;

    output_elements = npu_timing_mul_limit(
        desc->batch_count, desc->m);
    output_elements = npu_timing_mul_limit(
        output_elements, desc->n);
    output_beats = npu_ceil_div_u64(
        npu_timing_mul_limit(
            output_elements, npu_dtype_bits(desc->c.dtype)),
        NPU_REF_BUS_DATA_BITS);
    if (opcode == NPU_MATRIX_GEMM_ZERO) {
        return npu_timing_add_limit(output_beats, 3u);
    }
    cycles = npu_timing_add_limit(output_beats, 2u);
    cycles = npu_timing_add_limit(
        cycles,
        npu_ceil_div_u64(
            output_elements, model->config.vector_lanes));
    return npu_timing_add_limit(cycles, 3u);
}

static uint64_t npu_matrix_timing(const npu_model_t *model,
                                  uint8_t opcode,
                                  const npu_matrix_desc_t *desc)
{
    uint64_t m_tiles;
    uint64_t n_tiles;
    uint64_t k_tiles;
    uint64_t output_tiles;
    uint64_t a_beats;
    uint64_t b_beats;
    uint64_t load_beats;
    uint64_t per_k_tile;
    uint64_t output_elements;
    uint64_t cycles;

    output_elements = npu_timing_mul_limit(
        desc->batch_count, desc->m);
    output_elements = npu_timing_mul_limit(
        output_elements, desc->n);
    if (opcode == NPU_MATRIX_GEMM_ZERO) {
        return npu_matrix_accum_timing(model, opcode, desc);
    }
    m_tiles = npu_ceil_div_u64(desc->m, model->config.mt);
    n_tiles = npu_ceil_div_u64(desc->n, model->config.nt);
    k_tiles = npu_ceil_div_u64(desc->k, model->config.kt);
    output_tiles = npu_timing_mul_limit(
        desc->batch_count, m_tiles);
    output_tiles = npu_timing_mul_limit(
        output_tiles, n_tiles);

    a_beats = npu_ceil_div_u64(
        npu_timing_mul_limit(
            npu_timing_mul_limit(
                model->config.mt, model->config.kt),
            npu_dtype_bits(desc->a.dtype)),
        NPU_REF_BUS_DATA_BITS);
    b_beats = npu_ceil_div_u64(
        npu_timing_mul_limit(
            npu_timing_mul_limit(
                model->config.kt, model->config.nt),
            npu_dtype_bits(desc->b.dtype)),
        NPU_REF_BUS_DATA_BITS);
    load_beats = a_beats > b_beats ? a_beats : b_beats;
    per_k_tile = load_beats > model->config.kt
                     ? load_beats
                     : model->config.kt;
    cycles = npu_timing_mul_limit(
        output_tiles,
        npu_timing_add_limit(
            model->config.l1_read_latency,
            k_tiles == 0u
                ? 0u
                : npu_timing_mul_limit(
                      k_tiles, per_k_tile)));

    return npu_timing_add_limit(
        cycles, npu_matrix_accum_timing(model, opcode, desc));
}

static uint64_t npu_vector_timing(const npu_model_t *model,
                                  const npu_vector_desc_t *desc)
{
    uint64_t elements;
    uint32_t width;
    uint32_t per_beat;
    uint32_t lanes;

    if (desc->rows == 0u) {
        elements = 0u;
    } else {
        elements = npu_timing_add_limit(
            npu_timing_mul_limit(
                desc->rows - 1u, desc->length),
            desc->valid_length);
    }
    width = npu_dtype_bits(desc->src0.dtype);
    if (npu_dtype_bits(desc->dst.dtype) > width) {
        width = npu_dtype_bits(desc->dst.dtype);
    }
    per_beat = width == 0u ? 1u : NPU_REF_BUS_DATA_BITS / width;
    lanes = model->config.vector_lanes < per_beat
                ? model->config.vector_lanes
                : per_beat;
    if (lanes == 0u) {
        lanes = 1u;
    }
    return npu_timing_add_limit(
        npu_timing_add_limit(
            npu_timing_add_limit(
                3u, model->config.l1_read_latency),
            npu_ceil_div_u64(elements, lanes)),
        2u);
}

static uint64_t npu_complex_timing(const npu_model_t *model,
                                   const npu_complex_desc_t *desc)
{
    uint64_t elements;
    uint64_t groups;
    uint64_t function_latency;
    uint32_t passes;

    if (desc->rows == 0u) {
        elements = 0u;
    } else {
        elements = npu_timing_add_limit(
            npu_timing_mul_limit(
                desc->rows - 1u, desc->length),
            desc->valid_length);
    }
    groups = npu_ceil_div_u64(elements, model->config.cme_lanes);
    function_latency = 1u;
    passes = 1u;

    if (desc->function == NPU_FUNC_SIGMOID ||
        desc->function == NPU_FUNC_TANH) {
        function_latency = 25u;
    } else if (desc->function == NPU_FUNC_SILU) {
        function_latency = 26u;
    } else if (desc->function == NPU_FUNC_GELU) {
        function_latency = 31u;
    } else if (desc->function == NPU_FUNC_SOFTMAX) {
        function_latency = 27u;
        passes = 3u;
    } else if (desc->function == NPU_FUNC_LAYERNORM ||
               desc->function == NPU_FUNC_RMSNORM) {
        function_latency = 19u;
        passes = 3u;
    } else if (desc->function == NPU_FUNC_ADD_RESCALE) {
        function_latency = 6u;
    }
    return npu_timing_add_limit(
        npu_timing_add_limit(
            npu_timing_add_limit(
                npu_timing_add_limit(
                    3u, model->config.l1_read_latency),
                npu_timing_mul_limit(passes, groups)),
            function_latency),
        2u);
}

uint64_t npu_estimate_task_cycles(const npu_model_t *model,
                                  const npu_task_request_t *request)
{
    uint64_t descriptor_cycles;
    uint64_t engine_cycles;

    if (model == (const npu_model_t *)0 ||
        request == (const npu_task_request_t *)0) {
        return 0u;
    }
    descriptor_cycles =
        request->cmd.inline_format != 0u
            ? 0u
            : npu_task_desc_beats(request->cmd.engine) + 3u;
    if (request->cmd.engine == NPU_ENGINE_CONTROL) {
        engine_cycles = 1u;
    } else if (request->cmd.engine == NPU_ENGINE_DMA) {
        engine_cycles = npu_dma_timing(model, request->cmd.opcode,
                                       &request->desc.dma);
    } else if (request->cmd.engine == NPU_ENGINE_MATRIX) {
        engine_cycles = npu_matrix_timing(model, request->cmd.opcode,
                                          &request->desc.matrix);
    } else if (request->cmd.engine == NPU_ENGINE_VECTOR) {
        engine_cycles = npu_vector_timing(model, &request->desc.vector);
    } else if (request->cmd.engine == NPU_ENGINE_COMPLEX) {
        engine_cycles = npu_complex_timing(model,
                                           &request->desc.complex);
    } else {
        return 1u;
    }
    return npu_timing_add_limit(
        descriptor_cycles, engine_cycles);
}

static npu_status_t npu_control_execute(npu_model_t *model,
                                        npu_task_slot_t *slot)
{
    const npu_control_desc_t *desc = &slot->request.desc.control;
    uint8_t opcode = slot->request.cmd.opcode;

    if (opcode == NPU_CTRL_NOP) {
        return NPU_STATUS_SUCCESS;
    }
    if (opcode == NPU_CTRL_EVENT_SIGNAL) {
        return NPU_STATUS_SUCCESS;
    }
    if (opcode == NPU_CTRL_EVENT_REARM) {
        return npu_event_rearm(model, desc->target.id,
                               desc->target.generation);
    }
    if (opcode == NPU_CTRL_EVENT_JOIN) {
        const npu_event_entry_t *event0 =
            &model->events[desc->event0.id];
        const npu_event_entry_t *event1 =
            &model->events[desc->event1.id];
        if (desc->join_mode == 1u) {
            if (event0->state == NPU_EVENT_SUCCESS ||
                event1->state == NPU_EVENT_SUCCESS) {
                return NPU_STATUS_SUCCESS;
            }
        } else if (event0->state == NPU_EVENT_SUCCESS &&
                   event1->state == NPU_EVENT_SUCCESS) {
            return NPU_STATUS_SUCCESS;
        }
        if (event0->state == NPU_EVENT_FAILED) {
            return event0->status;
        }
        if (event1->state == NPU_EVENT_FAILED) {
            return event1->status;
        }
        return NPU_STATUS_BAD_DESC;
    }
    if (opcode == NPU_CTRL_GLOBAL_FENCE) {
        return slot->fence_error_status;
    }
    return NPU_STATUS_ILLEGAL_OPCODE;
}

npu_status_t npu_execute_task(npu_model_t *model,
                              npu_task_slot_t *slot)
{
    npu_engine_t engine = slot->request.cmd.engine;
    uint8_t opcode = slot->request.cmd.opcode;
    npu_fault_capture_t capture;
    void *previous_capture;
    uint64_t progress = 0u;
    npu_status_t status;

    capture.valid = 0u;
    capture.space = NPU_SPACE_L1;
    capture.addr = 0u;
    previous_capture = model->internal_fault_capture;
    model->internal_fault_capture = &capture;
    if (engine == NPU_ENGINE_CONTROL) {
        status = npu_control_execute(model, slot);
    } else if (engine == NPU_ENGINE_DMA) {
        status = npu_dma_execute(model, opcode,
                                 &slot->request.desc.dma, &progress);
    } else if (engine == NPU_ENGINE_MATRIX) {
        status = npu_matrix_execute(model, opcode,
                                    &slot->request.desc.matrix,
                                    &progress);
    } else if (engine == NPU_ENGINE_VECTOR) {
        status = npu_vector_execute(model, opcode,
                                    &slot->request.desc.vector,
                                    &progress);
    } else if (engine == NPU_ENGINE_COMPLEX) {
        status = npu_complex_execute(model, opcode,
                                     &slot->request.desc.complex,
                                     &progress);
    } else {
        status = NPU_STATUS_ILLEGAL_OPCODE;
    }
    model->internal_fault_capture = previous_capture;
    if ((status == NPU_STATUS_ADDR_FAULT ||
         status == NPU_STATUS_L1_ECC_UNCORRECTABLE) &&
        capture.valid != 0u) {
        slot->result.fault_addr = capture.addr;
        if (capture.space == NPU_SPACE_L1) {
            slot->result.done_flags |=
                NPU_DONE_FAULT_ADDR_IS_L1;
        }
        npu_fault_capture_record(model, capture.space,
                                 capture.addr);
    }
    slot->result.progress = progress;
    return status;
}

static void npu_release_task_waiters(npu_model_t *model,
                                     npu_task_slot_t *slot)
{
    uint32_t index;
    npu_event_ref_t event;

    if (slot->waiters_released != 0u) {
        return;
    }
    for (index = 0u; index < 2u; index++) {
        event = slot->request.cmd.wait_event[index];
        if (npu_event_is_none(event)) {
            continue;
        }
        if (index == 1u &&
            event.id == slot->request.cmd.wait_event[0].id &&
            event.generation ==
                slot->request.cmd.wait_event[0].generation) {
            continue;
        }
        if (model->events[event.id].generation == event.generation &&
            model->events[event.id].waiter_count != 0u) {
            model->events[event.id].waiter_count--;
        }
    }
    slot->waiters_released = 1u;
}

static uint8_t npu_engine_mask_bit(npu_engine_t engine)
{
    if (engine < NPU_ENGINE_DMA ||
        engine > NPU_ENGINE_COMPLEX) {
        return 0u;
    }
    return (uint8_t)(1u << (engine - NPU_ENGINE_DMA));
}

static void npu_fence_record_one(npu_task_slot_t *fence,
                                 const npu_task_slot_t *completed)
{
    uint8_t engine_bit;

    if (fence->request.cmd.engine != NPU_ENGINE_CONTROL ||
        fence->request.cmd.opcode != NPU_CTRL_GLOBAL_FENCE ||
        completed->submit_seq >= fence->submit_seq ||
        completed->result.status == NPU_STATUS_SUCCESS) {
        return;
    }
    engine_bit =
        npu_engine_mask_bit(completed->request.cmd.engine);
    if (engine_bit == 0u ||
        (fence->request.desc.control.engine_mask &
         engine_bit) == 0u) {
        return;
    }
    if (completed->submit_seq < fence->fence_error_seq) {
        fence->fence_error_seq = completed->submit_seq;
        fence->fence_error_status = completed->result.status;
    }
}

static void npu_fence_record_completion(npu_model_t *model,
                                        const npu_task_slot_t *completed)
{
    uint32_t index;

    for (index = 0u; index < model->config.task_entries; index++) {
        npu_task_slot_t *fence = &model->tasks[index];
        if (fence == completed ||
            (fence->state != NPU_TASK_WAITING &&
             fence->state != NPU_TASK_RUNNING)) {
            continue;
        }
        npu_fence_record_one(fence, completed);
    }
}

static void npu_task_finish(npu_model_t *model,
                            uint32_t slot_index,
                            npu_status_t status)
{
    npu_task_slot_t *slot = &model->tasks[slot_index];
    npu_event_ref_t signal = slot->request.cmd.signal_event;

    npu_release_task_waiters(model, slot);
    slot->state = NPU_TASK_TERMINAL;
    slot->remaining_cycles = 0u;
    slot->matrix_in_accum = 0u;
    slot->result.status = status;
    slot->result.end_cycle = model->cycle;
    if (status != NPU_STATUS_SUCCESS &&
        slot->result.progress != 0u) {
        slot->result.done_flags |= NPU_DONE_PARTIAL_DEST;
    }
    if (status == NPU_STATUS_SUCCESS) {
        model->perf.task_success++;
    } else {
        model->perf.task_failed++;
    }
    npu_fence_record_completion(model, slot);
    if (!npu_event_is_none(signal) &&
        !(slot->request.cmd.inline_format != 0u &&
          slot->request.cmd.engine == NPU_ENGINE_CONTROL &&
          slot->request.cmd.opcode == NPU_CTRL_EVENT_REARM)) {
        (void)npu_event_signal(model, signal, status);
    }
    if (slot->request.cmd.engine < NPU_ENGINE_COUNT &&
        model->active_slot[slot->request.cmd.engine] ==
            (int16_t)slot_index) {
        model->active_slot[slot->request.cmd.engine] = -1;
    }
    if (model->matrix_accum_slot == (int16_t)slot_index) {
        model->matrix_accum_slot = -1;
    }
}

static int npu_task_dependencies(const npu_model_t *model,
                                 const npu_task_slot_t *slot,
                                 npu_status_t *failure)
{
    uint32_t index;
    npu_event_ref_t event;
    const npu_event_entry_t *entry;

    if (slot->request.cmd.engine == NPU_ENGINE_CONTROL &&
        slot->request.cmd.opcode == NPU_CTRL_EVENT_JOIN) {
        const npu_control_desc_t *desc =
            &slot->request.desc.control;
        const npu_event_entry_t *event0;
        const npu_event_entry_t *event1;
        if (desc->join_mode > 2u ||
            desc->event0.id >= NPU_EVENT_NUM ||
            desc->event1.id >= NPU_EVENT_NUM) {
            *failure = NPU_STATUS_BAD_DESC;
            return -1;
        }
        event0 = &model->events[desc->event0.id];
        event1 = &model->events[desc->event1.id];
        if (event0->generation != desc->event0.generation ||
            event1->generation != desc->event1.generation) {
            *failure = NPU_STATUS_BAD_DESC;
            return -1;
        }
        if (desc->join_mode == 0u) {
            return (event0->state == NPU_EVENT_SUCCESS &&
                    event1->state == NPU_EVENT_SUCCESS) ||
                           event0->state == NPU_EVENT_FAILED ||
                           event1->state == NPU_EVENT_FAILED;
        }
        if (desc->join_mode == 1u) {
            if (event0->state == NPU_EVENT_SUCCESS ||
                event1->state == NPU_EVENT_SUCCESS) {
                return 1;
            }
            return event0->state == NPU_EVENT_FAILED &&
                   event1->state == NPU_EVENT_FAILED;
        }
        return (event0->state == NPU_EVENT_SUCCESS ||
                event0->state == NPU_EVENT_FAILED) &&
               (event1->state == NPU_EVENT_SUCCESS ||
                event1->state == NPU_EVENT_FAILED);
    }

    for (index = 0u; index < 2u; index++) {
        event = slot->request.cmd.wait_event[index];
        if (npu_event_is_none(event)) {
            continue;
        }
        entry = &model->events[event.id];
        if (entry->generation != event.generation) {
            *failure = NPU_STATUS_BAD_DESC;
            return -1;
        }
        if (entry->state == NPU_EVENT_FAILED) {
            *failure = NPU_STATUS_DEPENDENCY_FAILED;
            return -1;
        }
        if (entry->state != NPU_EVENT_SUCCESS) {
            return 0;
        }
    }
    return 1;
}

static int npu_lower_sequence_incomplete(const npu_model_t *model,
                                         uint64_t submit_seq)
{
    uint32_t index;
    for (index = 0u; index < model->config.task_entries; index++) {
        if ((model->tasks[index].state == NPU_TASK_WAITING ||
             model->tasks[index].state == NPU_TASK_RUNNING) &&
            model->tasks[index].submit_seq < submit_seq) {
            return 1;
        }
    }
    return 0;
}

static int npu_earlier_ordered_blocks(const npu_model_t *model,
                                      uint64_t submit_seq)
{
    uint32_t index;
    for (index = 0u; index < model->config.task_entries; index++) {
        if ((model->tasks[index].state == NPU_TASK_WAITING ||
             model->tasks[index].state == NPU_TASK_RUNNING) &&
            model->tasks[index].submit_seq < submit_seq &&
            (model->tasks[index].request.cmd.header_flags & (1u << 4)) !=
                0u) {
            return 1;
        }
    }
    return 0;
}

static int npu_fence_incomplete(const npu_model_t *model,
                                const npu_task_slot_t *fence)
{
    uint32_t index;
    uint8_t engine_bit;

    for (index = 0u; index < model->config.task_entries; index++) {
        const npu_task_slot_t *prior = &model->tasks[index];
        if ((prior->state != NPU_TASK_WAITING &&
             prior->state != NPU_TASK_RUNNING) ||
            prior->submit_seq >= fence->submit_seq ||
            prior->request.cmd.engine == NPU_ENGINE_CONTROL) {
            continue;
        }
        engine_bit = npu_engine_mask_bit(prior->request.cmd.engine);
        if ((fence->request.desc.control.engine_mask &
             engine_bit) != 0u) {
            return 1;
        }
    }
    return 0;
}

static int npu_task_can_dispatch(const npu_model_t *model,
                                 const npu_task_slot_t *slot)
{
    if ((slot->request.cmd.header_flags & (1u << 4)) != 0u &&
        npu_lower_sequence_incomplete(model, slot->submit_seq)) {
        return 0;
    }
    if (npu_earlier_ordered_blocks(model, slot->submit_seq)) {
        return 0;
    }
    return 1;
}

typedef struct {
    npu_space_t space;
    uint64_t first;
    uint64_t end;
    uint8_t valid;
} npu_matrix_region_t;

typedef struct {
    npu_matrix_region_t reads[5];
    uint32_t read_count;
    npu_matrix_region_t writes[1];
    uint32_t write_count;
} npu_matrix_regions_t;

static int npu_checked_mul_u64(uint64_t left,
                               uint64_t right,
                               uint64_t *result)
{
    if (left != 0u && right > UINT64_MAX / left) {
        return 0;
    }
    *result = left * right;
    return 1;
}

static int npu_checked_add_u64(uint64_t left,
                               uint64_t right,
                               uint64_t *result)
{
    if (UINT64_MAX - left < right) {
        return 0;
    }
    *result = left + right;
    return 1;
}

static int npu_matrix_region_set(npu_matrix_region_t *region,
                                 npu_space_t space,
                                 uint64_t address,
                                 uint64_t span)
{
    region->space = space;
    region->first = address;
    region->valid = span != 0u;
    if (span == 0u) {
        region->end = address;
        return 1;
    }
    return npu_checked_add_u64(address, span, &region->end);
}

static int npu_matrix_tensor_region(
    const npu_tensor_t *tensor,
    uint32_t batches,
    uint32_t rows,
    uint32_t length,
    npu_matrix_region_t *region)
{
    uint64_t batch_part;
    uint64_t row_part;
    uint64_t element_part;
    uint64_t span;
    uint32_t element_bytes;

    if (batches == 0u || rows == 0u || length == 0u) {
        return npu_matrix_region_set(
            region, tensor->space, tensor->addr, 0u);
    }
    if (!npu_checked_mul_u64(
            batches - 1u, tensor->batch_stride_bytes,
            &batch_part) ||
        !npu_checked_mul_u64(
            rows - 1u, tensor->row_stride_bytes,
            &row_part)) {
        return 0;
    }
    if (tensor->dtype == NPU_DTYPE_INT4) {
        if (tensor->elem_stride_bytes == 0u) {
            element_part =
                ((uint64_t)tensor->start_nibble +
                 (uint64_t)length + 1u) /
                2u;
        } else if (!npu_checked_mul_u64(
                       length - 1u,
                       tensor->elem_stride_bytes,
                       &element_part) ||
                   !npu_checked_add_u64(
                       element_part, 1u, &element_part)) {
            return 0;
        }
    } else {
        element_bytes = npu_dtype_bytes(tensor->dtype);
        if (element_bytes == 0u) {
            return 0;
        }
        if (tensor->elem_stride_bytes == 0u) {
            if (!npu_checked_mul_u64(
                    length, element_bytes, &element_part)) {
                return 0;
            }
        } else if (!npu_checked_mul_u64(
                       length - 1u,
                       tensor->elem_stride_bytes,
                       &element_part) ||
                   !npu_checked_add_u64(
                       element_part, element_bytes,
                       &element_part)) {
            return 0;
        }
    }
    if (!npu_checked_add_u64(
            batch_part, row_part, &span) ||
        !npu_checked_add_u64(
            span, element_part, &span)) {
        return 0;
    }
    return npu_matrix_region_set(
        region, tensor->space, tensor->addr, span);
}

static int npu_matrix_b_region(
    const npu_model_t *model,
    const npu_matrix_desc_t *desc,
    npu_matrix_region_t *region)
{
    uint64_t k_tiles;
    uint64_t n_tiles;
    uint64_t tile_elements;
    uint64_t batch_bytes;
    uint64_t last_batch;
    uint64_t span;

    if (desc->b_tiled == 0u) {
        return npu_matrix_tensor_region(
            &desc->b, desc->batch_count,
            desc->transpose_b != 0u ? desc->n : desc->k,
            desc->transpose_b != 0u ? desc->k : desc->n,
            region);
    }
    if (desc->batch_count == 0u ||
        desc->k == 0u || desc->n == 0u) {
        return npu_matrix_region_set(
            region, desc->b.space, desc->b.addr, 0u);
    }
    k_tiles = npu_ceil_div_u64(
        desc->k, model->config.kt);
    n_tiles = npu_ceil_div_u64(
        desc->n, model->config.nt);
    if (!npu_checked_mul_u64(
            k_tiles, n_tiles, &tile_elements) ||
        !npu_checked_mul_u64(
            tile_elements, model->config.kt,
            &tile_elements) ||
        !npu_checked_mul_u64(
            tile_elements, model->config.nt,
            &tile_elements)) {
        return 0;
    }
    if (desc->b.dtype == NPU_DTYPE_INT4) {
        batch_bytes = npu_ceil_div_u64(tile_elements, 2u);
    } else if (!npu_checked_mul_u64(
                   tile_elements,
                   npu_dtype_bytes(desc->b.dtype),
                   &batch_bytes)) {
        return 0;
    }
    if (!npu_checked_mul_u64(
            desc->batch_count - 1u,
            desc->b.batch_stride_bytes,
            &last_batch) ||
        !npu_checked_add_u64(
            last_batch, batch_bytes, &span)) {
        return 0;
    }
    return npu_matrix_region_set(
        region, desc->b.space, desc->b.addr, span);
}

static int npu_matrix_collect_regions(
    const npu_model_t *model,
    const npu_task_slot_t *slot,
    npu_matrix_regions_t *regions)
{
    const npu_matrix_desc_t *desc =
        &slot->request.desc.matrix;
    npu_matrix_region_t *region;
    uint64_t span;

    regions->read_count = 0u;
    regions->write_count = 0u;
    if (slot->request.cmd.opcode != NPU_MATRIX_GEMM_ZERO) {
        region = &regions->reads[regions->read_count++];
        if (!npu_matrix_tensor_region(
                &desc->a, desc->batch_count,
                desc->transpose_a != 0u ? desc->k : desc->m,
                desc->transpose_a != 0u ? desc->m : desc->k,
                region)) {
            return 0;
        }
        region = &regions->reads[regions->read_count++];
        if (!npu_matrix_b_region(model, desc, region)) {
            return 0;
        }
        if (desc->residual_enable != 0u ||
            desc->accum_from_src2 != 0u) {
            region = &regions->reads[regions->read_count++];
            if (!npu_matrix_tensor_region(
                    &desc->src2, desc->batch_count,
                    desc->m, desc->n, region)) {
                return 0;
            }
        }
        if (desc->bias_enable != 0u) {
            if (!npu_checked_mul_u64(
                    desc->bias_count - 1u,
                    desc->bias_stride_bytes, &span) ||
                !npu_checked_add_u64(span, 4u, &span) ||
                !npu_matrix_region_set(
                    &regions->reads[regions->read_count++],
                    NPU_SPACE_L1, desc->bias_addr, span)) {
                return 0;
            }
        }
        if (desc->requant_enable != 0u &&
            desc->inline_requant_enable == 0u) {
            if (!npu_checked_mul_u64(
                    desc->requant_count, 8u, &span) ||
                !npu_matrix_region_set(
                    &regions->reads[regions->read_count++],
                    NPU_SPACE_L1, desc->requant_addr, span)) {
                return 0;
            }
        }
    }
    region = &regions->writes[regions->write_count++];
    return npu_matrix_tensor_region(
        &desc->c, desc->batch_count,
        desc->m, desc->n, region);
}

static int npu_matrix_regions_overlap(
    const npu_matrix_region_t *left,
    const npu_matrix_region_t *right)
{
    return left->valid != 0u &&
           right->valid != 0u &&
           left->space == right->space &&
           left->first < right->end &&
           right->first < left->end;
}

static int npu_matrix_pipeline_hazard(
    const npu_model_t *model,
    const npu_task_slot_t *candidate)
{
    npu_matrix_regions_t active_regions;
    npu_matrix_regions_t candidate_regions;
    const npu_task_slot_t *active;
    uint32_t active_write;
    uint32_t candidate_read;

    if (model->matrix_accum_slot < 0) {
        return 0;
    }
    active =
        &model->tasks[(uint32_t)model->matrix_accum_slot];
    if (!npu_matrix_collect_regions(
            model, active, &active_regions) ||
        !npu_matrix_collect_regions(
            model, candidate, &candidate_regions)) {
        return 1;
    }
    for (active_write = 0u;
         active_write < active_regions.write_count;
         active_write++) {
        for (candidate_read = 0u;
             candidate_read < candidate_regions.read_count;
             candidate_read++) {
            if (npu_matrix_regions_overlap(
                    &active_regions.writes[active_write],
                    &candidate_regions.reads[candidate_read])) {
                return 1;
            }
        }
    }
    return 0;
}

static int npu_model_has_work(const npu_model_t *model)
{
    uint32_t index;
    for (index = 0u; index < model->config.task_entries; index++) {
        if (model->tasks[index].state == NPU_TASK_WAITING ||
            model->tasks[index].state == NPU_TASK_RUNNING) {
            return 1;
        }
    }
    return 0;
}

static void npu_update_engine_perf(npu_model_t *model)
{
    int matrix_mac_active =
        model->active_slot[NPU_ENGINE_MATRIX] >= 0 &&
        model->tasks[
            (uint32_t)model->active_slot[NPU_ENGINE_MATRIX]]
                .remaining_cycles != 0u;
    int matrix_accum_active =
        model->matrix_accum_slot >= 0;

    if (matrix_mac_active) {
        model->perf.matrix_mac_active_cycles++;
    }
    if (matrix_accum_active) {
        model->perf.matrix_accum_active_cycles++;
    }
    if (matrix_mac_active && matrix_accum_active) {
        model->perf.matrix_overlap_cycles++;
    }
    if (model->active_slot[NPU_ENGINE_VECTOR] >= 0) {
        model->perf.ive_active_cycles++;
    }
    if (model->active_slot[NPU_ENGINE_COMPLEX] >= 0) {
        model->perf.cme_fp_active_cycles++;
    }
}

static int npu_task_timeout_expired(
    const npu_model_t *model,
    const npu_task_slot_t *slot)
{
    uint32_t timeout =
        model->config.timeout_cycles[
            slot->request.cmd.timeout_class];
    uint64_t elapsed =
        model->cycle - slot->result.start_cycle;

    return timeout != 0u && elapsed > timeout;
}

static void npu_step_matrix_accum(npu_model_t *model)
{
    uint32_t slot_index;
    npu_task_slot_t *slot;
    npu_status_t status;

    if (model->matrix_accum_slot < 0) {
        return;
    }
    slot_index = (uint32_t)model->matrix_accum_slot;
    slot = &model->tasks[slot_index];
    if (slot->remaining_cycles > 0u) {
        slot->remaining_cycles--;
    }
    if (slot->remaining_cycles == 0u) {
        status = npu_execute_task(model, slot);
        npu_task_finish(model, slot_index, status);
        return;
    }
    if (npu_task_timeout_expired(model, slot)) {
        npu_task_finish(model, slot_index, NPU_STATUS_TIMEOUT);
    }
}

static void npu_step_running(npu_model_t *model)
{
    static const npu_engine_t execution_order[NPU_ENGINE_COUNT] = {
        NPU_ENGINE_DMA,
        NPU_ENGINE_MATRIX,
        NPU_ENGINE_VECTOR,
        NPU_ENGINE_COMPLEX,
        NPU_ENGINE_CONTROL
    };
    uint32_t order_index;
    npu_engine_t engine;
    uint32_t slot_index;
    npu_task_slot_t *slot;
    npu_status_t status;

    npu_step_matrix_accum(model);
    for (order_index = 0u;
         order_index < NPU_ENGINE_COUNT;
         order_index++) {
        engine = execution_order[order_index];
        if (model->active_slot[engine] < 0) {
            continue;
        }
        slot_index = (uint32_t)model->active_slot[engine];
        slot = &model->tasks[slot_index];
        if (slot->result.start_cycle == model->cycle) {
            continue;
        }
        if (slot->request.cmd.engine == NPU_ENGINE_CONTROL &&
            slot->request.cmd.opcode == NPU_CTRL_GLOBAL_FENCE &&
            npu_fence_incomplete(model, slot)) {
            if (npu_task_timeout_expired(model, slot)) {
                npu_task_finish(model, slot_index,
                                NPU_STATUS_TIMEOUT);
            }
            continue;
        }
        if (slot->remaining_cycles > 0u) {
            slot->remaining_cycles--;
        }
        if (slot->remaining_cycles == 0u) {
            if (engine == NPU_ENGINE_MATRIX) {
                if (model->matrix_accum_slot < 0) {
                    model->active_slot[NPU_ENGINE_MATRIX] = -1;
                    model->matrix_accum_slot =
                        (int16_t)slot_index;
                    slot->matrix_in_accum = 1u;
                    slot->remaining_cycles =
                        slot->matrix_accum_cycles != 0u
                            ? slot->matrix_accum_cycles
                            : 1u;
                }
                if (npu_task_timeout_expired(model, slot)) {
                    npu_task_finish(
                        model, slot_index,
                        NPU_STATUS_TIMEOUT);
                }
                continue;
            }
            status = npu_execute_task(model, slot);
            npu_task_finish(model, slot_index, status);
            continue;
        }
        if (npu_task_timeout_expired(model, slot)) {
            npu_task_finish(model, slot_index, NPU_STATUS_TIMEOUT);
        }
    }
}

static void npu_step_dispatch(npu_model_t *model)
{
    uint32_t engine;
    uint32_t index;
    uint32_t best;
    uint64_t best_sequence;
    npu_status_t failure;
    int dependency;
    int matrix_hazard_blocked;

    for (index = 0u; index < model->config.task_entries; index++) {
        if (model->tasks[index].state != NPU_TASK_WAITING) {
            continue;
        }
        dependency =
            npu_task_dependencies(model, &model->tasks[index], &failure);
        if (dependency < 0) {
            npu_task_finish(model, index, failure);
        }
    }

    for (engine = 0u; engine < NPU_ENGINE_COUNT; engine++) {
        if (model->active_slot[engine] >= 0) {
            continue;
        }
        best = NPU_MAX_TASKS;
        best_sequence = UINT64_MAX;
        matrix_hazard_blocked = 0;
        for (index = 0u; index < model->config.task_entries; index++) {
            if (model->tasks[index].state != NPU_TASK_WAITING ||
                model->tasks[index].request.cmd.engine !=
                    (npu_engine_t)engine) {
                continue;
            }
            dependency =
                npu_task_dependencies(model, &model->tasks[index],
                                      &failure);
            if (dependency != 1 ||
                !npu_task_can_dispatch(model, &model->tasks[index])) {
                continue;
            }
            if (engine == NPU_ENGINE_MATRIX &&
                npu_matrix_pipeline_hazard(
                    model, &model->tasks[index])) {
                matrix_hazard_blocked = 1;
                continue;
            }
            if (model->tasks[index].submit_seq < best_sequence) {
                best_sequence = model->tasks[index].submit_seq;
                best = index;
            }
        }
        if (best == NPU_MAX_TASKS &&
            engine == NPU_ENGINE_MATRIX &&
            matrix_hazard_blocked != 0) {
            model->perf.matrix_hazard_stall_cycles++;
        }
        if (best != NPU_MAX_TASKS) {
            npu_release_task_waiters(model, &model->tasks[best]);
            model->tasks[best].state = NPU_TASK_RUNNING;
            if (engine == NPU_ENGINE_MATRIX) {
                uint64_t total =
                    model->tasks[best].estimated_cycles;
                uint64_t accum =
                    model->tasks[best].matrix_accum_cycles;
                model->tasks[best].remaining_cycles =
                    total > accum ? total - accum : 1u;
                model->tasks[best].matrix_in_accum = 0u;
            } else {
                model->tasks[best].remaining_cycles =
                    model->tasks[best].estimated_cycles;
            }
            model->tasks[best].result.start_cycle = model->cycle;
            model->active_slot[engine] = (int16_t)best;
        }
    }
}

void npu_model_step(npu_model_t *model, uint64_t cycles)
{
    uint64_t count;
    int active;

    if (model == (npu_model_t *)0) {
        return;
    }
    for (count = 0u; count < cycles; count++) {
        active = !npu_model_idle(model);
        if (active) {
            model->perf.core_active_cycles++;
        }
        model->cycle++;
        npu_step_dispatch(model);
        npu_update_engine_perf(model);
        npu_step_running(model);
    }
}

npu_status_t npu_model_run(npu_model_t *model, uint64_t max_cycles)
{
    uint64_t count;

    if (model == (npu_model_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    for (count = 0u; count < max_cycles; count++) {
        if (!npu_model_has_work(model)) {
            return NPU_STATUS_SUCCESS;
        }
        npu_model_step(model, 1u);
    }
    return npu_model_has_work(model)
               ? NPU_STATUS_TIMEOUT
               : NPU_STATUS_SUCCESS;
}

int npu_model_idle(const npu_model_t *model)
{
    uint32_t index;

    if (model == (const npu_model_t *)0) {
        return 0;
    }
    if (model->cfe.have_low_beat != 0u ||
        model->cfe.response_valid != 0u) {
        return 0;
    }
    for (index = 0u; index < model->config.task_entries; index++) {
        if (model->tasks[index].state != NPU_TASK_FREE) {
            return 0;
        }
    }
    return 1;
}

npu_status_t npu_model_query(npu_model_t *model,
                             uint16_t command_id,
                             int acknowledge,
                             npu_task_result_t *result)
{
    uint32_t index;
    npu_task_slot_t *slot;

    if (model == (npu_model_t *)0 ||
        result == (npu_task_result_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    for (index = 0u; index < model->config.task_entries; index++) {
        slot = &model->tasks[index];
        if (slot->state != NPU_TASK_FREE &&
            slot->request.cmd.command_id == command_id) {
            *result = slot->result;
            if (slot->state != NPU_TASK_TERMINAL) {
                return NPU_STATUS_BUSY;
            }
            if (acknowledge != 0) {
                slot->state = NPU_TASK_FREE;
                slot->result.status = NPU_STATUS_NOT_FOUND;
            }
            return result->status;
        }
    }
    return NPU_STATUS_NOT_FOUND;
}
