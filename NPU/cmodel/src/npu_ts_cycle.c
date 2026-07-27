#include "npu_ts_cycle.h"
#include "npu_inline.h"

#include <limits.h>
#include <string.h>

#define TS_DONE_FLAG_ALLOWED 0x0007u
#define TS_ENGINE_MASK_ALL 0x0fu
#define TS_ERROR_STAGE_SHIFT 28u
#define TS_ERROR_DETAIL_SHIFT 16u
#define TS_ERROR_WORD_SHIFT 8u
#define TS_ERROR_WORD_NONE 0xffu

static uint16_t ts_u16(const uint8_t *data, size_t offset)
{
    return (uint16_t)data[offset] |
           (uint16_t)((uint16_t)data[offset + 1u] << 8);
}

static uint32_t ts_u32(const uint8_t *data, size_t offset)
{
    return (uint32_t)data[offset] |
           ((uint32_t)data[offset + 1u] << 8) |
           ((uint32_t)data[offset + 2u] << 16) |
           ((uint32_t)data[offset + 3u] << 24);
}

static uint64_t ts_u64(const uint8_t *data, size_t offset)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        value |= (uint64_t)data[offset + byte] << (byte * 8u);
    }
    return value;
}

static void ts_store_u64(uint8_t *data,
                         size_t offset,
                         uint64_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static int ts_event_none(npu_event_ref_t event)
{
    return event.id == NPU_EVENT_NONE_ID &&
           event.generation == NPU_EVENT_NONE_GENERATION;
}

static uint16_t ts_event_pack(npu_event_ref_t event)
{
    return (uint16_t)(((uint16_t)event.generation << 8) | event.id);
}

static int ts_event_raw_valid(uint16_t raw)
{
    uint8_t id = (uint8_t)(raw & 0xffu);

    return id != NPU_EVENT_NONE_ID || raw == NPU_TS_EVENT_NONE;
}

static int ts_event_terminal(uint8_t state)
{
    return state == NPU_TS_EVENT_SUCCESS ||
           state == NPU_TS_EVENT_ERROR;
}

static int ts_task_terminal(uint8_t state)
{
    return state == NPU_TS_TASK_SUCCESS ||
           state == NPU_TS_TASK_ERROR ||
           state == NPU_TS_TASK_DEPENDENCY_FAILED ||
           state == NPU_TS_TASK_TIMEOUT ||
           state == NPU_TS_TASK_ABORTED;
}

static int ts_task_status_valid(uint8_t status)
{
    return status <= NPU_STATUS_ADDR_OVERLAP;
}

static uint8_t ts_engine_code(uint8_t port)
{
    return (uint8_t)(port + (uint8_t)NPU_ENGINE_DMA);
}

static int ts_opcode_valid(npu_engine_t engine, uint8_t opcode)
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

static size_t ts_expected_desc_bytes(npu_engine_t engine)
{
    return npu_wire_descriptor_bytes(engine);
}

static uint8_t ts_find_free_task(const npu_ts_cycle_t *model)
{
    uint32_t index;

    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        if (model->task[index].valid == 0u) {
            return (uint8_t)index;
        }
    }
    return NPU_TS_INVALID_INDEX;
}

static uint8_t ts_find_free_desc(const npu_ts_cycle_t *model)
{
    uint32_t index;

    for (index = 0u; index < NPU_TS_DESC_SLOT_COUNT; index++) {
        if (model->desc_slot[index].allocated == 0u) {
            return (uint8_t)index;
        }
    }
    return NPU_TS_INVALID_INDEX;
}

static uint8_t ts_find_task_slot(const npu_ts_cycle_t *model,
                                 uint16_t command_id)
{
    uint32_t index;

    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        if (model->task[index].valid != 0u &&
            model->task[index].cmd.command_id == command_id) {
            return (uint8_t)index;
        }
    }
    return NPU_TS_INVALID_INDEX;
}

static int ts_command_id_duplicate(
    const npu_ts_cycle_t *model,
    uint8_t current_slot,
    uint16_t command_id)
{
    uint32_t index;

    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        if (index != current_slot &&
            model->task[index].valid != 0u &&
            model->task[index].cmd.command_id == command_id) {
            return 1;
        }
    }
    return 0;
}

static uint8_t ts_task_slots_used(const npu_ts_cycle_t *model)
{
    uint32_t index;
    uint8_t used = 0u;

    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        used = (uint8_t)(used +
                         (model->task[index].valid != 0u ? 1u : 0u));
    }
    return used;
}

static uint8_t ts_desc_slots_used(const npu_ts_cycle_t *model)
{
    uint32_t index;
    uint8_t used = 0u;

    for (index = 0u; index < NPU_TS_DESC_SLOT_COUNT; index++) {
        used = (uint8_t)(used +
                         (model->desc_slot[index].allocated != 0u
                              ? 1u
                              : 0u));
    }
    return used;
}

static void ts_release_desc(npu_ts_cycle_t *model, uint8_t slot)
{
    if (slot >= NPU_TS_DESC_SLOT_COUNT) {
        return;
    }
    model->desc_slot[slot].allocated = 0u;
    model->desc_slot[slot].full = 0u;
    model->desc_slot[slot].bytes = 0u;
    model->desc_slot[slot].owner_engine = 0u;
    model->desc_slot[slot].owner_task_slot = NPU_TS_INVALID_INDEX;
}

static void ts_release_waiters(npu_ts_cycle_t *model,
                               npu_ts_task_entry_t *task)
{
    uint32_t index;

    if (task->waiters_released != 0u) {
        return;
    }
    for (index = 0u; index < 2u; index++) {
        npu_event_ref_t ref = task->cmd.wait_event[index];
        npu_ts_event_entry_t *entry;

        if (ts_event_none(ref)) {
            continue;
        }
        if (index == 1u &&
            ts_event_pack(ref) ==
                ts_event_pack(task->cmd.wait_event[0])) {
            continue;
        }
        if (ref.id >= NPU_TS_EVENT_COUNT) {
            continue;
        }
        entry = &model->event[ref.id];
        if (entry->generation == ref.generation &&
            entry->waiter_count != 0u) {
            entry->waiter_count--;
        }
    }
    task->waiters_released = 1u;
}

static uint32_t ts_error_info(uint8_t stage,
                              uint8_t status,
                              uint8_t opcode)
{
    return ((uint32_t)(stage & 0x0fu) <<
            TS_ERROR_STAGE_SHIFT) |
           ((uint32_t)status << TS_ERROR_DETAIL_SHIFT) |
           ((uint32_t)TS_ERROR_WORD_NONE <<
            TS_ERROR_WORD_SHIFT) |
           opcode;
}

static void ts_mark_commit(npu_ts_cycle_t *model,
                           uint8_t task_slot,
                           uint8_t status,
                           uint32_t error_info,
                           uint16_t done_flags,
                           uint64_t fault_addr,
                           uint64_t progress)
{
    npu_ts_task_entry_t *task;

    if (task_slot >= NPU_TS_TASK_COUNT) {
        return;
    }
    task = &model->task[task_slot];
    if (task->valid == 0u ||
        task->state == NPU_TS_TASK_COMMIT ||
        ts_task_terminal(task->state)) {
        return;
    }
    if (status != NPU_STATUS_SUCCESS && error_info == 0u) {
        error_info = ts_error_info(
            NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
            status, task->cmd.opcode);
    }
    task->status = status;
    task->error_info = error_info;
    task->done_flags = done_flags;
    task->fault_addr = fault_addr & UINT64_C(0x0000ffffffffffff);
    task->progress = progress;
    task->commit_cycle = model->cycle;
    task->state = NPU_TS_TASK_COMMIT;
}

static void ts_update_fence_copy(npu_ts_fence_target_t *target,
                                 uint8_t target_count,
                                 const npu_ts_task_entry_t *finished)
{
    uint32_t index;

    for (index = 0u; index < target_count; index++) {
        if (target[index].valid != 0u &&
            target[index].submit_seq == finished->submit_seq) {
            target[index].terminal = 1u;
            target[index].status = finished->status;
        }
    }
}

static void ts_notify_fences(npu_ts_cycle_t *model,
                             const npu_ts_task_entry_t *finished)
{
    uint32_t index;

    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        npu_ts_task_entry_t *fence = &model->task[index];

        if (fence->valid != 0u &&
            fence->cmd.engine == NPU_ENGINE_CONTROL &&
            fence->cmd.opcode == NPU_CTRL_GLOBAL_FENCE &&
            fence->submit_seq > finished->submit_seq) {
            ts_update_fence_copy(fence->fence_target,
                                 fence->fence_target_count,
                                 finished);
        }
    }
    if (model->ctl.active != 0u &&
        model->ctl.op == NPU_TS_CTL_FENCE) {
        ts_update_fence_copy(model->ctl.fence_target,
                             model->ctl.fence_target_count,
                             finished);
    }
}

static uint8_t ts_terminal_state(uint8_t status)
{
    if (status == NPU_STATUS_SUCCESS) {
        return NPU_TS_TASK_SUCCESS;
    }
    if (status == NPU_STATUS_DEPENDENCY_FAILED) {
        return NPU_TS_TASK_DEPENDENCY_FAILED;
    }
    if (status == NPU_STATUS_TIMEOUT) {
        return NPU_TS_TASK_TIMEOUT;
    }
    if (status == NPU_STATUS_ABORTED) {
        return NPU_TS_TASK_ABORTED;
    }
    return NPU_TS_TASK_ERROR;
}

static void ts_enqueue_terminal_notice(
    npu_ts_cycle_t *model,
    const npu_ts_task_entry_t *task)
{
    npu_ts_terminal_notice_t *notice;

    if (model->terminal_notice_count >= NPU_TS_TASK_COUNT) {
        return;
    }
    notice =
        &model->terminal_notice[model->terminal_notice_tail];
    notice->task_id = task->cmd.command_id;
    notice->status = task->status;
    notice->engine = (uint8_t)task->cmd.engine;
    notice->opcode = task->cmd.opcode;
    notice->fault_addr = task->fault_addr;
    notice->error_info = task->error_info;
    notice->done_flags = task->done_flags;
    notice->irq_on_success =
        (uint8_t)((task->cmd.header_flags &
                   NPU_TS_FLAG_IRQ_ON_SUCCESS) != 0u);
    notice->irq_on_error =
        (uint8_t)((task->cmd.header_flags &
                   NPU_TS_FLAG_IRQ_ON_ERROR) != 0u);
    model->terminal_notice_tail =
        (uint8_t)((model->terminal_notice_tail + 1u) %
                  NPU_TS_TASK_COUNT);
    model->terminal_notice_count++;
}

static void ts_finish_commits(npu_ts_cycle_t *model)
{
    uint32_t index;

    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        npu_ts_task_entry_t *task = &model->task[index];
        npu_event_ref_t signal;

        if (task->valid == 0u ||
            task->state != NPU_TS_TASK_COMMIT ||
            task->commit_cycle >= model->cycle) {
            continue;
        }
        task->state = ts_terminal_state(task->status);
        task->end_cycle = model->cycle;
        ts_release_waiters(model, task);
        signal = task->cmd.signal_event;
        if (!ts_event_none(signal) &&
            !(task->cmd.inline_format != 0u &&
              task->cmd.engine == NPU_ENGINE_CONTROL &&
              task->cmd.opcode == NPU_CTRL_EVENT_REARM) &&
            signal.id < NPU_TS_EVENT_COUNT) {
            npu_ts_event_entry_t *event = &model->event[signal.id];

            if (event->state == NPU_TS_EVENT_RESERVED &&
                event->generation == signal.generation &&
                event->producer_task_id == task->cmd.command_id) {
                event->state =
                    task->status == NPU_STATUS_SUCCESS
                        ? NPU_TS_EVENT_SUCCESS
                        : NPU_TS_EVENT_ERROR;
                event->error_status = task->status;
            }
        }
        ts_release_desc(model, task->desc_slot);
        ts_notify_fences(model, task);
        ts_enqueue_terminal_notice(model, task);

        if (task->status == NPU_STATUS_SUCCESS) {
            if ((task->cmd.header_flags &
                 NPU_TS_FLAG_IRQ_ON_SUCCESS) != 0u) {
                model->irq_success_pending = 1u;
                model->irq_success_task_id = task->cmd.command_id;
            }
        } else if ((task->cmd.header_flags &
                    NPU_TS_FLAG_IRQ_ON_ERROR) != 0u) {
            model->irq_error_pending = 1u;
            model->irq_error_task_id = task->cmd.command_id;
        }
    }
}

static void ts_snapshot_fence_targets(
    const npu_ts_cycle_t *model,
    uint64_t before_seq,
    uint8_t engine_mask,
    npu_ts_fence_target_t target[NPU_TS_TASK_COUNT],
    uint8_t *target_count)
{
    uint32_t index;
    uint8_t count = 0u;

    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        const npu_ts_task_entry_t *task = &model->task[index];
        uint8_t bit;

        if (task->valid == 0u ||
            task->submit_seq >= before_seq ||
            task->cmd.engine < NPU_ENGINE_DMA ||
            task->cmd.engine > NPU_ENGINE_COMPLEX) {
            continue;
        }
        bit = (uint8_t)(1u << ((uint8_t)task->cmd.engine - 1u));
        if ((engine_mask & bit) == 0u) {
            continue;
        }
        target[count].valid = 1u;
        target[count].terminal =
            (uint8_t)ts_task_terminal(task->state);
        target[count].engine = (uint8_t)task->cmd.engine;
        target[count].status = task->status;
        target[count].submit_seq = task->submit_seq;
        count++;
    }
    *target_count = count;
}

static int ts_fence_result(const npu_ts_fence_target_t *target,
                           uint8_t target_count,
                           uint8_t engine_mask,
                           uint8_t *status)
{
    uint32_t index;
    uint64_t first_error_seq = UINT64_MAX;
    uint8_t first_error_status = NPU_STATUS_SUCCESS;

    for (index = 0u; index < target_count; index++) {
        uint8_t bit;

        if (target[index].valid == 0u ||
            target[index].engine < NPU_ENGINE_DMA ||
            target[index].engine > NPU_ENGINE_COMPLEX) {
            continue;
        }
        bit = (uint8_t)(1u << (target[index].engine - 1u));
        if ((engine_mask & bit) == 0u) {
            continue;
        }
        if (target[index].terminal == 0u) {
            return 0;
        }
        if (target[index].status != NPU_STATUS_SUCCESS &&
            target[index].submit_seq < first_error_seq) {
            first_error_seq = target[index].submit_seq;
            first_error_status = target[index].status;
        }
    }
    *status = first_error_status;
    return 1;
}

static void ts_free_task(npu_ts_cycle_t *model, uint8_t task_slot)
{
    if (task_slot >= NPU_TS_TASK_COUNT) {
        return;
    }
    memset(&model->task[task_slot], 0,
           sizeof(model->task[task_slot]));
    model->task[task_slot].desc_slot = NPU_TS_INVALID_INDEX;
}

void npu_ts_cycle_init(npu_ts_cycle_t *model)
{
    npu_ts_cycle_reset(model);
}

void npu_ts_cycle_reset(npu_ts_cycle_t *model)
{
    uint32_t index;

    if (model == (npu_ts_cycle_t *)0) {
        return;
    }
    memset(model, 0, sizeof(*model));
    npu_wire_limits_reference(&model->wire_limits);
    model->cfe_half_task_slot = NPU_TS_INVALID_INDEX;
    model->cfe_half_desc_slot = NPU_TS_INVALID_INDEX;
    model->dfu.task_slot = NPU_TS_INVALID_INDEX;
    model->ctl.ack_task_slot = NPU_TS_INVALID_INDEX;
    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        model->task[index].desc_slot = NPU_TS_INVALID_INDEX;
    }
    for (index = 0u; index < NPU_TS_DESC_SLOT_COUNT; index++) {
        model->desc_slot[index].owner_task_slot =
            NPU_TS_INVALID_INDEX;
    }
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        model->engine_active_task[index] = NPU_TS_INVALID_INDEX;
        model->req_hold[index].task_slot = NPU_TS_INVALID_INDEX;
        model->done_rx[index].task_slot = NPU_TS_INVALID_INDEX;
    }
}

int npu_ts_cycle_inject_desc_ecc(npu_ts_cycle_t *model,
                                 uint8_t desc_slot,
                                 uint8_t word,
                                 uint8_t status)
{
    if (model == (npu_ts_cycle_t *)0 ||
        desc_slot >= NPU_TS_DESC_SLOT_COUNT ||
        word >= NPU_TS_DESC_WORDS ||
        status > 2u) {
        return 0;
    }
    model->desc_slot[desc_slot].ecc_status[word] = status;
    return 1;
}

const npu_ts_task_entry_t *npu_ts_cycle_find_task(
    const npu_ts_cycle_t *model,
    uint16_t command_id)
{
    uint8_t slot;

    if (model == (const npu_ts_cycle_t *)0) {
        return (const npu_ts_task_entry_t *)0;
    }
    slot = ts_find_task_slot(model, command_id);
    if (slot == NPU_TS_INVALID_INDEX) {
        return (const npu_ts_task_entry_t *)0;
    }
    return &model->task[slot];
}

static int ts_cmd_event_resources_valid(
    const npu_ts_cycle_t *model,
    const npu_cmd_t *cmd)
{
    uint32_t index;
    npu_event_ref_t signal = cmd->signal_event;

    for (index = 0u; index < 2u; index++) {
        npu_event_ref_t ref = cmd->wait_event[index];

        if (ts_event_none(ref)) {
            continue;
        }
        if (ref.id >= NPU_TS_EVENT_COUNT ||
            model->event[ref.id].state == NPU_TS_EVENT_FREE ||
            model->event[ref.id].generation != ref.generation) {
            return 0;
        }
    }
    if (cmd->engine == NPU_ENGINE_CONTROL &&
        cmd->opcode == NPU_CTRL_EVENT_REARM) {
        if (cmd->inline_format != 0u) {
            return !ts_event_none(signal) &&
                   signal.id < NPU_TS_EVENT_COUNT &&
                   model->event[signal.id].generation ==
                       signal.generation &&
                   ts_event_terminal(
                       model->event[signal.id].state) &&
                   model->event[signal.id].waiter_count == 0u;
        }
        return ts_event_none(signal);
    }
    if (!ts_event_none(signal)) {
        if (signal.id >= NPU_TS_EVENT_COUNT ||
            model->event[signal.id].state != NPU_TS_EVENT_FREE ||
            model->event[signal.id].generation != signal.generation) {
            return 0;
        }
        for (index = 0u; index < 2u; index++) {
            if (!ts_event_none(cmd->wait_event[index]) &&
                ts_event_pack(signal) ==
                    ts_event_pack(cmd->wait_event[index])) {
                return 0;
            }
        }
    }
    return 1;
}

static void ts_cmd_event_resources_apply(
    npu_ts_cycle_t *model,
    npu_ts_task_entry_t *task)
{
    uint32_t index;
    npu_event_ref_t signal = task->cmd.signal_event;

    for (index = 0u; index < 2u; index++) {
        npu_event_ref_t ref = task->cmd.wait_event[index];

        if (ts_event_none(ref)) {
            continue;
        }
        if (index == 1u &&
            ts_event_pack(ref) ==
                ts_event_pack(task->cmd.wait_event[0])) {
            continue;
        }
        model->event[ref.id].waiter_count++;
    }
    if (!ts_event_none(signal) &&
        !(task->cmd.inline_format != 0u &&
          task->cmd.engine == NPU_ENGINE_CONTROL &&
          task->cmd.opcode == NPU_CTRL_EVENT_REARM)) {
        npu_ts_event_entry_t *event = &model->event[signal.id];

        event->state = NPU_TS_EVENT_RESERVED;
        event->generation = signal.generation;
        event->producer_task_id = task->cmd.command_id;
        event->error_status = NPU_STATUS_BUSY;
    }
}

static void ts_accept_first_beat(npu_ts_cycle_t *model,
                                 const npu_ts_cfe_inputs_t *input)
{
    uint8_t task_slot = ts_find_free_task(model);
    uint8_t desc_slot = ts_find_free_desc(model);
    npu_ts_task_entry_t *task;
    npu_ts_desc_slot_t *desc;

    if (task_slot == NPU_TS_INVALID_INDEX ||
        desc_slot == NPU_TS_INVALID_INDEX) {
        return;
    }
    task = &model->task[task_slot];
    desc = &model->desc_slot[desc_slot];
    memset(task, 0, sizeof(*task));
    task->valid = 1u;
    task->state = NPU_TS_TASK_CMD_HALF;
    task->desc_slot = desc_slot;
    task->cmd.desc_addr =
        input->data & UINT64_C(0x0000ffffffffffff);
    task->cmd.command_id = 0u;
    task->cmd.engine = NPU_ENGINE_CONTROL;
    task->cmd.wait_event[0] = npu_event_none();
    task->cmd.wait_event[1] = npu_event_none();
    task->cmd.signal_event = npu_event_none();
    task->status = NPU_STATUS_BUSY;
    task->malformed_cmd =
        (uint8_t)(input->first == 0u ||
                  input->last != 0u);

    memset(desc, 0, sizeof(*desc));
    desc->allocated = 1u;
    desc->owner_engine = 0u;
    desc->owner_task_slot = task_slot;
    ts_store_u64(desc->data, 0u, input->data);

    model->cfe_half_valid = 1u;
    model->cfe_half_terminate = 0u;
    model->cfe_half_task_slot = task_slot;
    model->cfe_half_desc_slot = desc_slot;
    model->cfe_low = input->data;
}

static void ts_accept_second_beat(npu_ts_cycle_t *model,
                                  const npu_ts_cfe_inputs_t *input,
                                  uint8_t terminate)
{
    uint8_t task_slot = model->cfe_half_task_slot;
    npu_ts_task_entry_t *task;
    npu_status_t status;
    uint64_t fault_addr = 0u;
    uint16_t done_flags = 0u;

    if (task_slot >= NPU_TS_TASK_COUNT) {
        return;
    }
    task = &model->task[task_slot];
    ts_store_u64(
        model->desc_slot[task->desc_slot].data,
        8u, input->data);
    status =
        model->descriptor_diagnostic_mode != 0u
            ? npu_cmd_decode_descriptor(
                  model->cfe_low, input->data, &task->cmd)
            : npu_cmd_decode(
                  model->cfe_low, input->data, &task->cmd);
    if (status == NPU_STATUS_SUCCESS &&
        task->cmd.inline_format != 0u) {
        uint32_t event_index;

        for (event_index = 0u; event_index < 2u;
             event_index++) {
            npu_event_ref_t *event =
                &task->cmd.wait_event[event_index];

            if (event->id < NPU_TS_EVENT_COUNT) {
                event->generation =
                    model->event[event->id].generation;
            }
        }
        if (task->cmd.signal_event.id <
            NPU_TS_EVENT_COUNT) {
            task->cmd.signal_event.generation =
                model->event[
                    task->cmd.signal_event.id].generation;
        }
    }
    task->submit_seq = model->next_submit_seq++;
    task->accept_cycle = model->cycle;
    task->state = NPU_TS_TASK_ACCEPTED;
    if (terminate != 0u) {
        model->desc_slot[task->desc_slot].owner_engine =
            (uint8_t)task->cmd.engine;
        if (status == NPU_STATUS_SUCCESS &&
            ts_opcode_valid(task->cmd.engine,
                            task->cmd.opcode) &&
            ts_cmd_event_resources_valid(model,
                                         &task->cmd)) {
            ts_cmd_event_resources_apply(model, task);
        }
        ts_mark_commit(model, task_slot, NPU_STATUS_ABORTED,
                       ts_error_info(
                           NPU_TS_ERROR_STAGE_ABORT,
                           NPU_STATUS_ABORTED,
                           task->cmd.opcode),
                       NPU_DONE_ABORT_DRAINED, 0u, 0u);
        model->cfe_half_valid = 0u;
        model->cfe_half_terminate = 0u;
        model->cfe_half_task_slot = NPU_TS_INVALID_INDEX;
        model->cfe_half_desc_slot = NPU_TS_INVALID_INDEX;
        return;
    }
    if (input->first != 0u || input->last == 0u ||
        task->malformed_cmd != 0u) {
        status = NPU_STATUS_BAD_DESC;
    }
    if (status == NPU_STATUS_SUCCESS &&
        ts_command_id_duplicate(
            model, task_slot, task->cmd.command_id)) {
        status = NPU_STATUS_BAD_DESC;
    }
    if (status == NPU_STATUS_SUCCESS &&
        (!ts_opcode_valid(task->cmd.engine, task->cmd.opcode) ||
         (task->cmd.header_flags &
          NPU_TS_FLAG_DESC_CRC_ENABLE) != 0u)) {
        status = !ts_opcode_valid(task->cmd.engine,
                                  task->cmd.opcode)
                     ? NPU_STATUS_ILLEGAL_OPCODE
                     : NPU_STATUS_BAD_DESC;
    }
    if (status == NPU_STATUS_SUCCESS &&
        !ts_cmd_event_resources_valid(model, &task->cmd)) {
        status = NPU_STATUS_BAD_DESC;
    }
    if (status == NPU_STATUS_SUCCESS) {
        status = npu_wire_validate_cmd_address(
            &task->cmd, &model->wire_limits, &task->meta);
        if (status == NPU_STATUS_ADDR_FAULT &&
            task->meta.fault_valid != 0u) {
            fault_addr = task->meta.fault_addr;
            if (task->meta.fault_space == NPU_SPACE_L1) {
                done_flags |= NPU_DONE_FAULT_ADDR_IS_L1;
            }
        }
    }
    if (status == NPU_STATUS_SUCCESS) {
        ts_cmd_event_resources_apply(model, task);
        model->desc_slot[task->desc_slot].owner_engine =
            (uint8_t)task->cmd.engine;
        if (task->cmd.inline_format != 0u) {
            status = npu_inline_decode_task(
                &task->cmd, &model->wire_limits,
                &task->request, &task->meta);
            if (status == NPU_STATUS_SUCCESS) {
                model->desc_slot[task->desc_slot].bytes =
                    NPU_WIRE_CMD_BYTES;
                model->desc_slot[task->desc_slot].full = 1u;
                task->user_tag = task->request.cmd.user_tag;
                task->fetch_started = 1u;
                task->state = NPU_TS_TASK_CHECK_DESC;
                task->commit_cycle = model->cycle;
            }
        }
        if (status != NPU_STATUS_SUCCESS) {
            if (status == NPU_STATUS_ADDR_FAULT &&
                task->meta.fault_valid != 0u) {
                fault_addr = task->meta.fault_addr;
                if (task->meta.fault_space == NPU_SPACE_L1) {
                    done_flags |= NPU_DONE_FAULT_ADDR_IS_L1;
                }
            }
            ts_mark_commit(
                model, task_slot, (uint8_t)status,
                0u, done_flags, fault_addr, 0u);
        }
        if (status == NPU_STATUS_SUCCESS &&
            task->cmd.engine == NPU_ENGINE_CONTROL &&
            task->cmd.opcode == NPU_CTRL_GLOBAL_FENCE) {
            ts_snapshot_fence_targets(
                model, task->submit_seq, TS_ENGINE_MASK_ALL,
                task->fence_target, &task->fence_target_count);
        }
    } else {
        ts_mark_commit(model, task_slot, (uint8_t)status,
                       0u, done_flags, fault_addr, 0u);
    }

    model->cfe_half_valid = 0u;
    model->cfe_half_terminate = 0u;
    model->cfe_half_task_slot = NPU_TS_INVALID_INDEX;
    model->cfe_half_desc_slot = NPU_TS_INVALID_INDEX;
}

static int ts_prefix_valid(const npu_ts_task_entry_t *task,
                           const npu_ts_desc_slot_t *slot)
{
    uint32_t numeric;
    uint32_t op_flags;
    size_t expected;

    expected = ts_expected_desc_bytes(task->cmd.engine);
    if (expected == 0u || expected > NPU_TS_DESC_BYTES ||
        slot->data[0x00u] != NPU_WIRE_DEFAULT_DESC_VERSION ||
        slot->data[0x01u] != (uint8_t)task->cmd.engine ||
        ts_u16(slot->data, 0x02u) != expected) {
        return 0;
    }
    numeric = ts_u32(slot->data, 0x38u);
    op_flags = ts_u32(slot->data, 0x04u);
    if ((numeric & 0xfffe0000u) != 0u ||
        ((numeric >> 8) & 0x03u) != 0u) {
        return 0;
    }
    if (task->cmd.engine == NPU_ENGINE_CONTROL) {
        if (numeric != 0u ||
            (op_flags & 0xfffff0ffu) != 0u) {
            return 0;
        }
    } else {
        if ((op_flags & 0xffffff00u) != 0u) {
            return 0;
        }
        if (task->cmd.engine == NPU_ENGINE_MATRIX ||
            task->cmd.engine == NPU_ENGINE_VECTOR ||
            task->cmd.engine == NPU_ENGINE_COMPLEX) {
            if ((op_flags & 0x3fu) != 0u) {
                return 0;
            }
        }
    }
    return 1;
}

static void ts_dfu_clear(npu_ts_cycle_t *model)
{
    memset(&model->dfu, 0, sizeof(model->dfu));
    model->dfu.task_slot = NPU_TS_INVALID_INDEX;
}

static void ts_dfu_fail(npu_ts_cycle_t *model,
                        uint8_t status,
                        uint32_t error_info,
                        uint16_t done_flags,
                        uint64_t fault_addr)
{
    if (model->dfu.task_slot < NPU_TS_TASK_COUNT &&
        model->dfu.drain_only == 0u) {
        ts_mark_commit(model, model->dfu.task_slot, status,
                       error_info, done_flags, fault_addr, 0u);
    }
    ts_dfu_clear(model);
}

static void ts_dfu_decode_complete(npu_ts_cycle_t *model)
{
    uint8_t task_slot = model->dfu.task_slot;
    npu_ts_task_entry_t *task;
    npu_ts_desc_slot_t *slot;
    npu_status_t status;
    size_t bytes;

    if (task_slot >= NPU_TS_TASK_COUNT) {
        ts_dfu_clear(model);
        return;
    }
    task = &model->task[task_slot];
    slot = &model->desc_slot[task->desc_slot];
    bytes = ts_expected_desc_bytes(task->cmd.engine);
    status = npu_wire_decode_descriptor(
        &task->cmd, slot->data, bytes, &model->wire_limits,
        &task->request, &task->meta);
    if (status != NPU_STATUS_SUCCESS) {
        uint64_t fault_addr = 0u;
        uint16_t done_flags = 0u;

        if (status == NPU_STATUS_ADDR_FAULT &&
            task->meta.fault_valid != 0u) {
            fault_addr = task->meta.fault_addr;
            if (task->meta.fault_space == NPU_SPACE_L1) {
                done_flags |= NPU_DONE_FAULT_ADDR_IS_L1;
            }
        }
        ts_dfu_fail(model, (uint8_t)status, 0u,
                    done_flags, fault_addr);
        return;
    }
    slot->bytes = (uint16_t)bytes;
    slot->full = 1u;
    task->user_tag = task->request.cmd.user_tag;
    task->state = NPU_TS_TASK_CHECK_DESC;
    task->commit_cycle = model->cycle;
    ts_dfu_clear(model);
}

static void ts_dfu_segment_complete(npu_ts_cycle_t *model)
{
    uint8_t task_slot = model->dfu.task_slot;
    npu_ts_task_entry_t *task;
    npu_ts_desc_slot_t *slot;
    size_t bytes;

    if (model->dfu.drain_only != 0u) {
        ts_dfu_clear(model);
        return;
    }
    if (model->dfu.first_status != NPU_STATUS_SUCCESS) {
        ts_dfu_fail(model, model->dfu.first_status,
                    model->dfu.first_error_info, 0u, 0u);
        return;
    }
    if (task_slot >= NPU_TS_TASK_COUNT) {
        ts_dfu_clear(model);
        return;
    }
    task = &model->task[task_slot];
    slot = &model->desc_slot[task->desc_slot];
    if (model->dfu.segment == 0u) {
        if (!ts_prefix_valid(task, slot)) {
            ts_dfu_fail(model, NPU_STATUS_BAD_DESC, 0u, 0u, 0u);
            return;
        }
        bytes = ts_expected_desc_bytes(task->cmd.engine);
        if (bytes == NPU_WIRE_CONTROL_DESC_BYTES) {
            ts_dfu_decode_complete(model);
            return;
        }
        model->dfu.segment = 1u;
        model->dfu.request_valid = 1u;
        model->dfu.waiting_response = 0u;
        model->dfu.expected_beats =
            (uint8_t)((bytes - NPU_WIRE_CONTROL_DESC_BYTES) /
                      NPU_REF_BUS_BYTES);
        model->dfu.received_beats = 0u;
        model->dfu.base_word = 8u;
        model->dfu.first_status = NPU_STATUS_SUCCESS;
        model->dfu.first_error_info = 0u;
        model->dfu.req_addr =
            task->cmd.desc_addr + NPU_WIRE_CONTROL_DESC_BYTES;
        return;
    }
    ts_dfu_decode_complete(model);
}

static void ts_dfu_accept_response(npu_ts_cycle_t *model,
                                   const npu_ts_dfu_inputs_t *input)
{
    npu_ts_dfu_state_t *dfu = &model->dfu;
    npu_ts_task_entry_t *task;
    uint8_t expected_last;
    int status_valid;
    uint8_t word;

    if (dfu->task_slot >= NPU_TS_TASK_COUNT) {
        ts_dfu_clear(model);
        return;
    }
    task = &model->task[dfu->task_slot];
    expected_last =
        (uint8_t)(dfu->received_beats + 1u ==
                  dfu->expected_beats);
    status_valid = ts_task_status_valid(input->rsp_status);
    if (input->rsp_tag != task->cmd.command_id) {
        dfu->first_status = NPU_STATUS_BAD_DESC;
    }
    if (input->rsp_last != expected_last) {
        dfu->first_status = NPU_STATUS_BAD_DESC;
    }
    if (!status_valid) {
        dfu->first_status = NPU_STATUS_BAD_DESC;
        if (dfu->first_error_info == 0u) {
            dfu->first_error_info = ts_error_info(
                NPU_TS_ERROR_STAGE_DESC_PORT,
                input->rsp_status, task->cmd.opcode);
        }
    } else if (input->rsp_status != NPU_STATUS_SUCCESS &&
        dfu->first_status == NPU_STATUS_SUCCESS) {
        dfu->first_status = input->rsp_status;
    }
    word = (uint8_t)(dfu->base_word + dfu->received_beats);
    if (dfu->drain_only == 0u &&
        word < NPU_TS_DESC_WORDS) {
        uint32_t byte;
        uint8_t *destination =
            &model->desc_slot[task->desc_slot].data[
                (size_t)word * NPU_REF_BUS_BYTES];

        for (byte = 0u; byte < NPU_REF_BUS_BYTES; byte++) {
            destination[byte] =
                (uint8_t)(input->rsp_data >> (byte * 8u));
        }
    }
    dfu->received_beats++;
    if (expected_last != 0u || input->rsp_last != 0u) {
        dfu->waiting_response = 0u;
        ts_dfu_segment_complete(model);
    }
}

static void ts_start_next_dfu(npu_ts_cycle_t *model)
{
    uint32_t index;
    uint8_t selected = NPU_TS_INVALID_INDEX;
    uint64_t best_seq = UINT64_MAX;

    if (model->dfu.valid != 0u) {
        return;
    }
    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        npu_ts_task_entry_t *task = &model->task[index];

        if (task->valid != 0u &&
            task->state == NPU_TS_TASK_ACCEPTED &&
            task->fetch_started == 0u &&
            task->submit_seq < best_seq) {
            selected = (uint8_t)index;
            best_seq = task->submit_seq;
        }
    }
    if (selected == NPU_TS_INVALID_INDEX) {
        return;
    }
    model->task[selected].fetch_started = 1u;
    model->task[selected].state = NPU_TS_TASK_FETCH_DESC;
    model->dfu.valid = 1u;
    model->dfu.task_slot = selected;
    model->dfu.segment = 0u;
    model->dfu.request_valid = 1u;
    model->dfu.waiting_response = 0u;
    model->dfu.expected_beats = 8u;
    model->dfu.received_beats = 0u;
    model->dfu.base_word = 0u;
    model->dfu.first_status = NPU_STATUS_SUCCESS;
    model->dfu.first_error_info = 0u;
    model->dfu.req_addr =
        model->task[selected].cmd.desc_addr;
}

static int ts_order_allows(const npu_ts_cycle_t *model,
                           const npu_ts_task_entry_t *candidate)
{
    uint32_t index;
    int candidate_ordered =
        (candidate->cmd.header_flags & NPU_TS_FLAG_ORDERED) != 0u;

    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        const npu_ts_task_entry_t *other = &model->task[index];

        if (other->valid == 0u ||
            other == candidate ||
            other->submit_seq >= candidate->submit_seq ||
            ts_task_terminal(other->state)) {
            continue;
        }
        if (candidate_ordered ||
            (other->cmd.header_flags &
             NPU_TS_FLAG_ORDERED) != 0u) {
            return 0;
        }
    }
    return 1;
}

static uint8_t ts_event_failure_status(
    const npu_ts_event_entry_t *event)
{
    if (event->error_status == NPU_STATUS_SUCCESS ||
        event->error_status == NPU_STATUS_BUSY ||
        event->error_status == NPU_STATUS_NOT_FOUND) {
        return NPU_STATUS_DEPENDENCY_FAILED;
    }
    return event->error_status;
}

static void ts_advance_waiting_task(npu_ts_cycle_t *model,
                                    uint8_t task_slot)
{
    npu_ts_task_entry_t *task = &model->task[task_slot];
    const npu_ts_event_entry_t *event0 = (const npu_ts_event_entry_t *)0;
    const npu_ts_event_entry_t *event1 = (const npu_ts_event_entry_t *)0;
    int none0 = ts_event_none(task->cmd.wait_event[0]);
    int none1 = ts_event_none(task->cmd.wait_event[1]);
    int success0;
    int success1;
    int error0;
    int error1;

    if (!none0) {
        event0 = &model->event[task->cmd.wait_event[0].id];
    }
    if (!none1) {
        event1 = &model->event[task->cmd.wait_event[1].id];
    }
    success0 = none0 ||
               event0->state == NPU_TS_EVENT_SUCCESS;
    success1 = none1 ||
               event1->state == NPU_TS_EVENT_SUCCESS;
    error0 = !none0 &&
             event0->state == NPU_TS_EVENT_ERROR;
    error1 = !none1 &&
             event1->state == NPU_TS_EVENT_ERROR;

    if (task->cmd.engine == NPU_ENGINE_CONTROL &&
        task->cmd.opcode == NPU_CTRL_EVENT_JOIN) {
        uint8_t mode = task->request.desc.control.join_mode;

        if (mode == 0u) {
            if (error0 || error1) {
                uint8_t status =
                    error0 ? ts_event_failure_status(event0)
                           : ts_event_failure_status(event1);
                ts_release_waiters(model, task);
                ts_mark_commit(model, task_slot, status,
                               0u, 0u, 0u, 0u);
            } else if (success0 && success1) {
                ts_release_waiters(model, task);
                task->state = NPU_TS_TASK_READY;
            }
        } else if (mode == 1u) {
            if (success0 || success1) {
                ts_release_waiters(model, task);
                task->state = NPU_TS_TASK_READY;
            } else if (error0 && error1) {
                ts_release_waiters(model, task);
                ts_mark_commit(
                    model, task_slot,
                    ts_event_failure_status(event0),
                    0u, 0u, 0u, 0u);
            }
        } else {
            int terminal0 = none0 ||
                            ts_event_terminal(event0->state);
            int terminal1 = none1 ||
                            ts_event_terminal(event1->state);

            if (terminal0 && terminal1) {
                ts_release_waiters(model, task);
                if (error0 || error1) {
                    ts_mark_commit(
                        model, task_slot,
                        error0
                            ? ts_event_failure_status(event0)
                            : ts_event_failure_status(event1),
                        0u, 0u, 0u, 0u);
                } else {
                    task->state = NPU_TS_TASK_READY;
                }
            }
        }
        return;
    }

    if (error0 || error1) {
        ts_release_waiters(model, task);
        ts_mark_commit(model, task_slot,
                       NPU_STATUS_DEPENDENCY_FAILED,
                       0u, 0u, 0u, 0u);
    } else if (success0 && success1) {
        ts_release_waiters(model, task);
        task->state = NPU_TS_TASK_READY;
    }
}

static void ts_advance_descriptor_states(npu_ts_cycle_t *model)
{
    uint32_t index;

    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        npu_ts_task_entry_t *task = &model->task[index];

        if (task->valid == 0u) {
            continue;
        }
        if (task->state == NPU_TS_TASK_CHECK_DESC &&
            task->commit_cycle < model->cycle) {
            task->state = NPU_TS_TASK_WAIT_EVENT;
        }
        if (task->state == NPU_TS_TASK_WAIT_EVENT) {
            ts_advance_waiting_task(model, (uint8_t)index);
        }
    }
}

static uint64_t ts_task_metadata(const npu_ts_task_entry_t *task)
{
    return ((uint64_t)task->cmd.command_id & 0x0fffu) |
           ((uint64_t)task->cmd.opcode << 12) |
           ((uint64_t)task->desc_slot << 20) |
           ((uint64_t)(task->cmd.header_flags & 0x003fu)
            << 28) |
           ((uint64_t)(task->cmd.timeout_class & 0x0fu)
            << 40) |
           ((uint64_t)(task->cmd.inline_format != 0u) << 44);
}

static void ts_execute_control_ready(npu_ts_cycle_t *model,
                                     uint8_t task_slot)
{
    npu_ts_task_entry_t *task = &model->task[task_slot];
    const npu_control_desc_t *desc =
        &task->request.desc.control;

    if (!ts_order_allows(model, task)) {
        return;
    }
    if (task->cmd.opcode == NPU_CTRL_NOP ||
        task->cmd.opcode == NPU_CTRL_EVENT_SIGNAL ||
        task->cmd.opcode == NPU_CTRL_EVENT_JOIN) {
        task->start_cycle = model->cycle;
        ts_mark_commit(model, task_slot, NPU_STATUS_SUCCESS,
                       0u, 0u, 0u, 0u);
        return;
    }
    if (task->cmd.opcode == NPU_CTRL_EVENT_REARM) {
        npu_event_ref_t old_event = desc->event0;
        npu_event_ref_t new_event = desc->target;
        npu_ts_event_entry_t *event;

        if (old_event.id >= NPU_TS_EVENT_COUNT) {
            ts_mark_commit(model, task_slot,
                           NPU_STATUS_BAD_DESC,
                           0u, 0u, 0u, 0u);
            return;
        }
        event = &model->event[old_event.id];
        if (!ts_event_terminal(event->state) ||
            event->generation != old_event.generation ||
            event->waiter_count != 0u ||
            new_event.id != old_event.id ||
            new_event.generation !=
                (uint8_t)((old_event.generation + 1u) & 0x0fu)) {
            ts_mark_commit(model, task_slot,
                           NPU_STATUS_BAD_DESC,
                           0u, 0u, 0u, 0u);
            return;
        }
        event->state = NPU_TS_EVENT_FREE;
        event->generation = new_event.generation;
        event->producer_task_id = 0u;
        event->error_status = NPU_STATUS_SUCCESS;
        task->start_cycle = model->cycle;
        ts_mark_commit(model, task_slot, NPU_STATUS_SUCCESS,
                       0u, 0u, 0u, 0u);
        return;
    }
    if (task->cmd.opcode == NPU_CTRL_GLOBAL_FENCE) {
        uint8_t status;

        task->state = NPU_TS_TASK_RUNNING;
        task->start_cycle = model->cycle;
        if (ts_fence_result(task->fence_target,
                            task->fence_target_count,
                            desc->engine_mask, &status)) {
            ts_mark_commit(model, task_slot, status,
                           0u, 0u, 0u, 0u);
        }
        return;
    }
    ts_mark_commit(model, task_slot, NPU_STATUS_ILLEGAL_OPCODE,
                   0u, 0u, 0u, 0u);
}

static void ts_run_control_fences(
    npu_ts_cycle_t *model,
    const npu_ts_cycle_inputs_t *inputs)
{
    uint32_t index;

    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        npu_ts_task_entry_t *task = &model->task[index];
        uint8_t status;
        uint32_t limit;
        uint64_t elapsed;

        if (task->valid == 0u ||
            task->state != NPU_TS_TASK_RUNNING ||
            task->cmd.engine != NPU_ENGINE_CONTROL ||
            task->cmd.opcode != NPU_CTRL_GLOBAL_FENCE) {
            continue;
        }
        if (ts_fence_result(
                task->fence_target,
                task->fence_target_count,
                task->request.desc.control.engine_mask,
                &status)) {
            ts_mark_commit(model, (uint8_t)index, status,
                           0u, 0u, 0u, 0u);
            continue;
        }
        limit =
            inputs->timeout_cycles[task->cmd.timeout_class];
        elapsed = model->cycle - task->start_cycle;
        if (limit != 0u && elapsed > limit) {
            ts_mark_commit(model, (uint8_t)index,
                           NPU_STATUS_TIMEOUT,
                           0u, 0u, 0u, 0u);
        }
    }
}

static void ts_start_control_tasks(npu_ts_cycle_t *model)
{
    uint32_t index;
    uint8_t selected = NPU_TS_INVALID_INDEX;
    uint64_t best_seq = UINT64_MAX;

    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        npu_ts_task_entry_t *task = &model->task[index];

        if (task->valid != 0u &&
            task->state == NPU_TS_TASK_READY &&
            task->cmd.engine == NPU_ENGINE_CONTROL &&
            task->submit_seq < best_seq &&
            ts_order_allows(model, task)) {
            selected = (uint8_t)index;
            best_seq = task->submit_seq;
        }
    }
    if (selected != NPU_TS_INVALID_INDEX) {
        ts_execute_control_ready(model, selected);
    }
}

static void ts_select_engine_requests(npu_ts_cycle_t *model)
{
    uint32_t port;

    for (port = 0u; port < NPU_TS_ENGINE_COUNT; port++) {
        uint32_t index;
        uint8_t selected = NPU_TS_INVALID_INDEX;
        uint64_t best_seq = UINT64_MAX;

        if (model->req_hold[port].valid != 0u ||
            model->engine_active_task[port] !=
                NPU_TS_INVALID_INDEX) {
            continue;
        }
        for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
            npu_ts_task_entry_t *task = &model->task[index];

            if (task->valid != 0u &&
                task->state == NPU_TS_TASK_READY &&
                (uint8_t)task->cmd.engine ==
                    ts_engine_code((uint8_t)port) &&
                task->submit_seq < best_seq &&
                ts_order_allows(model, task)) {
                selected = (uint8_t)index;
                best_seq = task->submit_seq;
            }
        }
        if (selected != NPU_TS_INVALID_INDEX) {
            model->req_hold[port].valid = 1u;
            model->req_hold[port].task_slot = selected;
            model->req_hold[port].data =
                ts_task_metadata(&model->task[selected]);
        }
    }
}

static void ts_accept_engine_request(npu_ts_cycle_t *model,
                                     uint8_t port)
{
    npu_ts_engine_req_hold_t *hold = &model->req_hold[port];
    uint8_t task_slot = hold->task_slot;

    if (task_slot >= NPU_TS_TASK_COUNT ||
        model->task[task_slot].state != NPU_TS_TASK_READY) {
        hold->valid = 0u;
        hold->task_slot = NPU_TS_INVALID_INDEX;
        return;
    }
    model->task[task_slot].state = NPU_TS_TASK_RUNNING;
    model->task[task_slot].start_cycle = model->cycle;
    model->engine_active_task[port] = task_slot;
    model->cancel[port].phase = NPU_TS_CANCEL_IDLE;
    model->cancel[port].status = 0u;
    model->done_rx[port].beat = 0u;
    model->done_rx[port].task_slot = task_slot;
    hold->valid = 0u;
    hold->task_slot = NPU_TS_INVALID_INDEX;
}

static int ts_done_status_valid(uint8_t status)
{
    return ts_task_status_valid(status);
}

static void ts_record_done_protocol_error(
    npu_ts_cycle_t *model,
    uint8_t port)
{
    if (port >= NPU_TS_ENGINE_COUNT) {
        return;
    }
    model->done_protocol_error_pending |=
        (uint8_t)(1u << port);
    model->done_protocol_error_count[port]++;
    model->done_rx[port].protocol_error = 1u;
}

static void ts_accept_done_beat(npu_ts_cycle_t *model,
                                uint8_t port,
                                const npu_ts_engine_inputs_t *input)
{
    npu_ts_done_receiver_t *receiver = &model->done_rx[port];
    uint8_t task_slot = model->engine_active_task[port];
    npu_ts_task_entry_t *task;

    if (task_slot >= NPU_TS_TASK_COUNT ||
        receiver->task_slot != task_slot) {
        ts_record_done_protocol_error(model, port);
        return;
    }
    task = &model->task[task_slot];
    if (receiver->beat == 0u) {
        uint16_t incoming_task =
            (uint16_t)(input->done_data & 0x0fffu);
        uint8_t status =
            (uint8_t)((input->done_data >> 12) & 0xffu);
        uint16_t done_flags =
            (uint16_t)((input->done_data >> 52) & 0x0fffu);

        uint32_t error_info =
            (uint32_t)((input->done_data >> 20) &
                       UINT64_C(0xffffffff));
        int status_valid = ts_done_status_valid(status);
        int format_error =
            input->done_first == 0u ||
            input->done_last != 0u ||
            incoming_task != task->cmd.command_id ||
            !status_valid ||
            (done_flags & (uint16_t)~TS_DONE_FLAG_ALLOWED) !=
                0u;

        if (status_valid &&
            status == NPU_STATUS_SUCCESS &&
            (error_info != 0u || done_flags != 0u)) {
            format_error = 1;
        }
        if (status_valid &&
            status != NPU_STATUS_SUCCESS &&
            error_info == 0u) {
            format_error = 1;
        }
        if (format_error) {
            ts_record_done_protocol_error(model, port);
        }
        receiver->status =
            status_valid ? status : NPU_STATUS_BAD_DESC;
        if (receiver->status == NPU_STATUS_SUCCESS) {
            receiver->error_info = 0u;
        } else if (!status_valid || error_info == 0u) {
            receiver->error_info = ts_error_info(
                NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                receiver->status, task->cmd.opcode);
        } else {
            receiver->error_info = error_info;
        }
        receiver->done_flags =
            receiver->status == NPU_STATUS_SUCCESS
                ? 0u
                : (uint16_t)(done_flags &
                             TS_DONE_FLAG_ALLOWED);
        if (incoming_task != task->cmd.command_id ||
            input->done_first == 0u ||
            input->done_last != 0u) {
            receiver->status = NPU_STATUS_BAD_DESC;
            receiver->error_info =
                ts_error_info(
                    NPU_TS_ERROR_STAGE_TASK_SCHEDULER,
                    NPU_STATUS_BAD_DESC,
                    task->cmd.opcode);
            receiver->done_flags = 0u;
        }
        /*
         * Beat 0 fixes the task status. It also wins over a timeout
         * request observed on the same edge, so no later cancel is sent
         * for this task.
         */
        model->cancel[port].phase = NPU_TS_CANCEL_IDLE;
        model->cancel[port].status = 0u;
        receiver->beat = 1u;
        return;
    }
    if (receiver->beat == 1u) {
        uint8_t engine =
            (uint8_t)((input->done_data >> 48) & 0x0fu);
        uint8_t opcode =
            (uint8_t)((input->done_data >> 52) & 0xffu);
        uint8_t reserved =
            (uint8_t)(input->done_data >> 60);

        if (input->done_first != 0u ||
            input->done_last != 0u ||
            engine != (uint8_t)task->cmd.engine ||
            opcode != task->cmd.opcode ||
            reserved != 0u) {
            ts_record_done_protocol_error(model, port);
        }
        receiver->fault_addr =
            input->done_data &
            UINT64_C(0x0000ffffffffffff);
        if (receiver->status == NPU_STATUS_SUCCESS &&
            receiver->fault_addr != 0u) {
            ts_record_done_protocol_error(model, port);
            receiver->fault_addr = 0u;
        }
        receiver->beat = 2u;
        return;
    }
    if (input->done_first != 0u ||
        input->done_last == 0u) {
        ts_record_done_protocol_error(model, port);
    }
    ts_mark_commit(model, task_slot, receiver->status,
                   receiver->error_info,
                   receiver->done_flags,
                   receiver->fault_addr,
                   input->done_data);
    model->engine_active_task[port] = NPU_TS_INVALID_INDEX;
    model->cancel[port].phase = NPU_TS_CANCEL_IDLE;
    model->cancel[port].status = 0u;
    memset(receiver, 0, sizeof(*receiver));
    receiver->task_slot = NPU_TS_INVALID_INDEX;
}

static void ts_check_engine_timeouts(
    npu_ts_cycle_t *model,
    const npu_ts_cycle_inputs_t *inputs)
{
    uint32_t port;

    for (port = 0u; port < NPU_TS_ENGINE_COUNT; port++) {
        uint8_t task_slot = model->engine_active_task[port];
        npu_ts_task_entry_t *task;
        uint32_t limit;
        uint64_t elapsed;

        if (task_slot >= NPU_TS_TASK_COUNT) {
            continue;
        }
        task = &model->task[task_slot];
        if (task->state != NPU_TS_TASK_RUNNING) {
            continue;
        }
        /*
         * Beat 0 carries the final execution status. Once it is accepted,
         * Beats 1 and 2 only complete the fixed response record, so the
         * execution timeout no longer advances.
         */
        if (model->done_rx[port].beat != 0u) {
            continue;
        }
        if (model->cancel[port].phase !=
            NPU_TS_CANCEL_IDLE) {
            continue;
        }
        limit =
            inputs->timeout_cycles[task->cmd.timeout_class];
        elapsed = model->cycle - task->start_cycle;
        if (limit != 0u && elapsed > limit) {
            model->cancel[port].phase =
                NPU_TS_CANCEL_REQUEST;
            model->cancel[port].status =
                NPU_STATUS_TIMEOUT;
        }
    }
}

static void ts_ctl_release_waiter(npu_ts_cycle_t *model)
{
    npu_ts_ctl_state_t *ctl = &model->ctl;
    uint8_t id = (uint8_t)(ctl->wait_event & 0xffu);
    uint8_t generation =
        (uint8_t)((ctl->wait_event >> 8) & 0x0fu);

    if (ctl->waiter_registered != 0u &&
        id < NPU_TS_EVENT_COUNT &&
        model->event[id].generation == generation &&
        model->event[id].waiter_count != 0u) {
        model->event[id].waiter_count--;
    }
    ctl->waiter_registered = 0u;
}

static uint64_t ts_ctl_wait_result(
    const npu_ts_event_entry_t *event)
{
    return (uint64_t)event->state |
           ((uint64_t)(event->producer_task_id & 0x0fffu)
            << 8);
}

static uint64_t ts_ctl_query_result(npu_ts_cycle_t *model,
                                    uint16_t command_id,
                                    uint8_t selector,
                                    uint8_t *ack_valid,
                                    uint8_t *ack_slot)
{
    uint8_t task_slot =
        ts_find_task_slot(model, command_id);
    const npu_ts_task_entry_t *task;

    *ack_valid = 0u;
    *ack_slot = NPU_TS_INVALID_INDEX;
    if (selector == NPU_TS_QUERY_RESERVED) {
        return NPU_STATUS_BAD_DESC;
    }
    if (selector == NPU_TS_QUERY_ACK) {
        if (task_slot == NPU_TS_INVALID_INDEX) {
            return 2u;
        }
        task = &model->task[task_slot];
        if (!ts_task_terminal(task->state)) {
            return 1u;
        }
        *ack_valid = 1u;
        *ack_slot = task_slot;
        return 0u;
    }
    if (task_slot == NPU_TS_INVALID_INDEX) {
        if (selector == NPU_TS_QUERY_STATUS) {
            return ((uint64_t)NPU_STATUS_NOT_FOUND << 4) |
                   ((uint64_t)(command_id & 0x0fffu) << 12);
        }
        return 0u;
    }
    task = &model->task[task_slot];
    if (selector == NPU_TS_QUERY_STATUS) {
        return ((uint64_t)(task->state & 0x0fu)) |
               ((uint64_t)task->status << 4) |
               ((uint64_t)(command_id & 0x0fffu) << 12);
    }
    if (selector == NPU_TS_QUERY_TAG_EVENT) {
        return (uint64_t)task->user_tag |
               ((uint64_t)ts_event_pack(task->cmd.signal_event)
                << 32);
    }
    if (selector == NPU_TS_QUERY_FAULT_ADDR) {
        return task->fault_addr &
               UINT64_C(0x0000ffffffffffff);
    }
    if (selector == NPU_TS_QUERY_PROGRESS) {
        return task->progress;
    }
    if (selector == NPU_TS_QUERY_ERROR_INFO) {
        return task->error_info;
    }
    if (selector == NPU_TS_QUERY_DONE_FLAGS) {
        return task->done_flags;
    }
    return NPU_STATUS_BAD_DESC;
}

static void ts_ctl_accept(npu_ts_cycle_t *model,
                          const npu_ts_ctl_inputs_t *input)
{
    npu_ts_ctl_state_t *ctl = &model->ctl;

    ctl->op = input->op;
    ctl->rs1 = input->rs1;
    ctl->rs2 = input->rs2;
    ctl->wait_count = 0u;
    ctl->wait_limit = (uint32_t)input->rs2;
    ctl->ack_release_valid = 0u;
    ctl->ack_task_slot = NPU_TS_INVALID_INDEX;
    if (input->op == NPU_TS_CTL_QUERY) {
        uint8_t selector = (uint8_t)(input->rs2 & 0x07u);

        if ((input->rs1 >> 12) != 0u ||
            (input->rs2 >> 3) != 0u) {
            ctl->rsp_data = NPU_STATUS_BAD_DESC;
        } else {
            ctl->rsp_data = ts_ctl_query_result(
                model, (uint16_t)(input->rs1 & 0x0fffu),
                selector, &ctl->ack_release_valid,
                &ctl->ack_task_slot);
        }
        ctl->rsp_valid = 1u;
        return;
    }
    if (input->op == NPU_TS_CTL_WAIT) {
        uint16_t raw = (uint16_t)(input->rs1 & 0x0fffu);
        uint8_t id = (uint8_t)(raw & 0xffu);
        uint8_t generation = (uint8_t)(raw >> 8);
        npu_ts_event_entry_t *event;

        if ((input->rs1 >> 12) != 0u ||
            (input->rs2 >> 32) != 0u ||
            !ts_event_raw_valid(raw) ||
            raw == NPU_TS_EVENT_NONE ||
            id >= NPU_TS_EVENT_COUNT) {
            ctl->rsp_data = NPU_STATUS_BAD_DESC;
            ctl->rsp_valid = 1u;
            return;
        }
        event = &model->event[id];
        if (event->state == NPU_TS_EVENT_FREE ||
            event->generation != generation) {
            ctl->rsp_data = NPU_STATUS_NOT_FOUND;
            ctl->rsp_valid = 1u;
            return;
        }
        if (ts_event_terminal(event->state)) {
            ctl->rsp_data = ts_ctl_wait_result(event);
            ctl->rsp_valid = 1u;
            return;
        }
        if (ctl->wait_limit == 0u) {
            ctl->rsp_data = NPU_STATUS_TIMEOUT;
            ctl->rsp_valid = 1u;
            return;
        }
        ctl->active = 1u;
        ctl->wait_event = raw;
        if (event->waiter_count != UINT8_MAX) {
            event->waiter_count++;
            ctl->waiter_registered = 1u;
        }
        return;
    }
    if (input->op == NPU_TS_CTL_FENCE) {
        uint8_t engine_mask = (uint8_t)(input->rs1 & 0x0fu);
        uint8_t status;

        if ((input->rs1 >> 4) != 0u ||
            (input->rs2 >> 32) != 0u) {
            ctl->rsp_data = NPU_STATUS_BAD_DESC;
            ctl->rsp_valid = 1u;
            return;
        }
        ts_snapshot_fence_targets(
            model, model->next_submit_seq, engine_mask,
            ctl->fence_target, &ctl->fence_target_count);
        if (ts_fence_result(ctl->fence_target,
                            ctl->fence_target_count,
                            engine_mask, &status)) {
            ctl->rsp_data = status;
            ctl->rsp_valid = 1u;
            return;
        }
        if (ctl->wait_limit == 0u) {
            ctl->rsp_data = NPU_STATUS_TIMEOUT;
            ctl->rsp_valid = 1u;
            return;
        }
        ctl->active = 1u;
        return;
    }
    ctl->rsp_data = NPU_STATUS_BAD_DESC;
    ctl->rsp_valid = 1u;
}

static void ts_ctl_advance(npu_ts_cycle_t *model)
{
    npu_ts_ctl_state_t *ctl = &model->ctl;

    if (ctl->active == 0u) {
        return;
    }
    if (ctl->op == NPU_TS_CTL_WAIT) {
        uint8_t id = (uint8_t)(ctl->wait_event & 0xffu);
        uint8_t generation =
            (uint8_t)((ctl->wait_event >> 8) & 0x0fu);
        npu_ts_event_entry_t *event = &model->event[id];

        if (event->generation != generation ||
            event->state == NPU_TS_EVENT_FREE) {
            ts_ctl_release_waiter(model);
            ctl->rsp_data = NPU_STATUS_NOT_FOUND;
            ctl->rsp_valid = 1u;
            ctl->active = 0u;
            return;
        }
        if (ts_event_terminal(event->state)) {
            ts_ctl_release_waiter(model);
            ctl->rsp_data = ts_ctl_wait_result(event);
            ctl->rsp_valid = 1u;
            ctl->active = 0u;
            return;
        }
    } else {
        uint8_t status;
        uint8_t engine_mask = (uint8_t)(ctl->rs1 & 0x0fu);

        if (ts_fence_result(ctl->fence_target,
                            ctl->fence_target_count,
                            engine_mask, &status)) {
            ctl->rsp_data = status;
            ctl->rsp_valid = 1u;
            ctl->active = 0u;
            return;
        }
    }
    if (ctl->wait_count >= ctl->wait_limit) {
        ts_ctl_release_waiter(model);
        ctl->rsp_data = NPU_STATUS_TIMEOUT;
        ctl->rsp_valid = 1u;
        ctl->active = 0u;
    } else {
        ctl->wait_count++;
    }
}

static void ts_ctl_cancel(npu_ts_cycle_t *model)
{
    if (model->ctl.active == 0u ||
        (model->ctl.op != NPU_TS_CTL_WAIT &&
         model->ctl.op != NPU_TS_CTL_FENCE)) {
        return;
    }
    ts_ctl_release_waiter(model);
    model->ctl.active = 0u;
    model->ctl.fence_target_count = 0u;
}

static void ts_desc_pop_response(npu_ts_cycle_t *model,
                                 uint8_t port)
{
    npu_ts_desc_port_state_t *state =
        &model->desc_port[port];
    npu_ts_desc_rsp_entry_t *entry;

    if (state->count == 0u) {
        return;
    }
    entry = &state->queue[state->head];
    if (entry->tag < NPU_TS_DESC_TAG_COUNT &&
        state->tag_count[entry->tag] != 0u) {
        state->tag_count[entry->tag]--;
        if (state->tag_count[entry->tag] == 0u) {
            state->tags_in_use &=
                (uint16_t)~(uint16_t)(1u << entry->tag);
        }
    }
    memset(entry, 0, sizeof(*entry));
    state->head =
        (uint8_t)((state->head + 1u) %
                  NPU_TS_DESC_TAG_COUNT);
    state->count--;
}

static void ts_desc_accept_request(
    npu_ts_cycle_t *model,
    uint8_t port,
    const npu_ts_desc_read_inputs_t *input)
{
    npu_ts_desc_port_state_t *state =
        &model->desc_port[port];
    npu_ts_desc_rsp_entry_t *entry =
        &state->queue[state->tail];
    const npu_ts_desc_slot_t *slot;
    uint8_t tag =
        (uint8_t)(input->req_tag &
                  (NPU_TS_DESC_TAG_COUNT - 1u));
    uint8_t status = 3u;
    uint64_t data = 0u;
    int valid =
        input->req_tag < NPU_TS_DESC_TAG_COUNT &&
        state->tag_count[tag] == 0u &&
        input->req_slot < NPU_TS_DESC_SLOT_COUNT;

    if (valid) {
        slot = &model->desc_slot[input->req_slot];
        valid = slot->allocated != 0u &&
                slot->full != 0u &&
                slot->owner_engine == ts_engine_code(port) &&
                input->req_word <
                    slot->bytes / NPU_REF_BUS_BYTES;
        if (valid) {
            status = slot->ecc_status[input->req_word];
            data =
                status == 2u
                    ? 0u
                    : ts_u64(
                          slot->data,
                          (size_t)input->req_word *
                              NPU_REF_BUS_BYTES);
        }
    }

    entry->valid = 1u;
    entry->tag = tag;
    entry->status = status;
    entry->ready_cycle = model->cycle + 1u;
    entry->data = data;
    state->tags_in_use |=
        (uint16_t)(1u << tag);
    state->tag_count[tag]++;
    state->tail =
        (uint8_t)((state->tail + 1u) %
                  NPU_TS_DESC_TAG_COUNT);
    state->count++;
}

static void ts_apply_abort(npu_ts_cycle_t *model,
                           const npu_ts_cycle_inputs_t *inputs)
{
    uint32_t index;

    if (model->dfu.valid != 0u) {
        if (model->dfu.task_slot < NPU_TS_TASK_COUNT) {
            const npu_ts_task_entry_t *task =
                &model->task[model->dfu.task_slot];

            ts_mark_commit(model, model->dfu.task_slot,
                           NPU_STATUS_ABORTED,
                           ts_error_info(
                               NPU_TS_ERROR_STAGE_ABORT,
                               NPU_STATUS_ABORTED,
                               task->cmd.opcode),
                           NPU_DONE_ABORT_DRAINED,
                           0u, 0u);
        }
        if (model->dfu.waiting_response != 0u) {
            model->dfu.drain_only = 1u;
        } else {
            ts_dfu_clear(model);
        }
    }
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        npu_ts_engine_req_hold_t *hold =
            &model->req_hold[index];
        uint8_t active = model->engine_active_task[index];

        if (hold->valid != 0u &&
            hold->task_slot < NPU_TS_TASK_COUNT) {
            const npu_ts_task_entry_t *task =
                &model->task[hold->task_slot];

            ts_mark_commit(model, hold->task_slot,
                           NPU_STATUS_ABORTED,
                           ts_error_info(
                               NPU_TS_ERROR_STAGE_ABORT,
                               NPU_STATUS_ABORTED,
                               task->cmd.opcode),
                           NPU_DONE_ABORT_DRAINED,
                           0u, 0u);
            hold->valid = 0u;
            hold->task_slot = NPU_TS_INVALID_INDEX;
        }
        if (active < NPU_TS_TASK_COUNT &&
            inputs->engine[index].quiescent != 0u) {
            const npu_ts_task_entry_t *task =
                &model->task[active];

            ts_mark_commit(model, active,
                           NPU_STATUS_ABORTED,
                           ts_error_info(
                               NPU_TS_ERROR_STAGE_ABORT,
                               NPU_STATUS_ABORTED,
                               task->cmd.opcode),
                           NPU_DONE_ABORT_DRAINED,
                           0u, 0u);
            model->engine_active_task[index] =
                NPU_TS_INVALID_INDEX;
            model->cancel[index].phase =
                NPU_TS_CANCEL_IDLE;
            model->cancel[index].status = 0u;
            memset(&model->done_rx[index], 0,
                   sizeof(model->done_rx[index]));
            model->done_rx[index].task_slot =
                NPU_TS_INVALID_INDEX;
        }
    }
    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        npu_ts_task_entry_t *task = &model->task[index];

        if (task->valid == 0u ||
            task->state == NPU_TS_TASK_CMD_HALF ||
            task->state == NPU_TS_TASK_COMMIT ||
            ts_task_terminal(task->state)) {
            continue;
        }
        if (task->state != NPU_TS_TASK_RUNNING ||
            task->cmd.engine == NPU_ENGINE_CONTROL) {
            ts_mark_commit(model, (uint8_t)index,
                           NPU_STATUS_ABORTED,
                           ts_error_info(
                               NPU_TS_ERROR_STAGE_ABORT,
                               NPU_STATUS_ABORTED,
                               task->cmd.opcode),
                           NPU_DONE_ABORT_DRAINED,
                           0u, 0u);
        }
    }
}

static void ts_apply_mif_reset_abort(npu_ts_cycle_t *model)
{
    uint8_t active_dma =
        model->engine_active_task[NPU_TS_PORT_DMA];

    if (model->dfu.valid != 0u) {
        if (model->dfu.task_slot < NPU_TS_TASK_COUNT) {
            const npu_ts_task_entry_t *task =
                &model->task[model->dfu.task_slot];

            ts_mark_commit(model, model->dfu.task_slot,
                           NPU_STATUS_ABORTED,
                           ts_error_info(
                               NPU_TS_ERROR_STAGE_ABORT,
                               NPU_STATUS_ABORTED,
                               task->cmd.opcode),
                           NPU_DONE_ABORT_DRAINED,
                           0u, 0u);
        }
        /*
         * The CDC and MIF reset have discarded the response. Drain mode
         * would wait forever, so the DFU state is released immediately.
         */
        ts_dfu_clear(model);
    }

    if (active_dma < NPU_TS_TASK_COUNT) {
        const npu_ts_task_entry_t *task =
            &model->task[active_dma];

        ts_mark_commit(model, active_dma,
                       NPU_STATUS_ABORTED,
                       ts_error_info(
                           NPU_TS_ERROR_STAGE_ABORT,
                           NPU_STATUS_ABORTED,
                           task->cmd.opcode),
                       NPU_DONE_ABORT_DRAINED,
                       0u, 0u);
        model->engine_active_task[NPU_TS_PORT_DMA] =
            NPU_TS_INVALID_INDEX;
        model->cancel[NPU_TS_PORT_DMA].phase =
            NPU_TS_CANCEL_IDLE;
        model->cancel[NPU_TS_PORT_DMA].status = 0u;
        memset(&model->done_rx[NPU_TS_PORT_DMA], 0,
               sizeof(model->done_rx[NPU_TS_PORT_DMA]));
        model->done_rx[NPU_TS_PORT_DMA].task_slot =
            NPU_TS_INVALID_INDEX;
    }
}

static int ts_model_quiescent(
    const npu_ts_cycle_t *model,
    const npu_ts_cycle_inputs_t *inputs)
{
    uint32_t index;

    if (model->cfe_half_valid != 0u ||
        model->lookup_rsp_valid != 0u ||
        model->dfu.valid != 0u ||
        model->ctl.active != 0u ||
        model->ctl.rsp_valid != 0u ||
        model->terminal_notice_count != 0u ||
        model->irq_success_pending != 0u ||
        model->irq_error_pending != 0u ||
        model->done_protocol_error_pending != 0u) {
        return 0;
    }
    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        if (model->task[index].valid != 0u &&
            !ts_task_terminal(model->task[index].state)) {
            return 0;
        }
    }
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        if (model->req_hold[index].valid != 0u ||
            model->engine_active_task[index] !=
                NPU_TS_INVALID_INDEX ||
            model->desc_port[index].count != 0u ||
            inputs->engine[index].quiescent == 0u) {
            return 0;
        }
    }
    return 1;
}

static int ts_model_idle(const npu_ts_cycle_t *model)
{
    uint32_t index;

    if (model->cfe_half_valid != 0u ||
        model->lookup_rsp_valid != 0u ||
        model->dfu.valid != 0u ||
        model->ctl.active != 0u ||
        model->ctl.rsp_valid != 0u ||
        model->terminal_notice_count != 0u ||
        model->irq_success_pending != 0u ||
        model->irq_error_pending != 0u ||
        model->done_protocol_error_pending != 0u) {
        return 0;
    }
    for (index = 0u; index < NPU_TS_TASK_COUNT; index++) {
        if (model->task[index].valid != 0u) {
            return 0;
        }
    }
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        if (model->req_hold[index].valid != 0u ||
            model->engine_active_task[index] !=
                NPU_TS_INVALID_INDEX ||
            model->desc_port[index].count != 0u) {
            return 0;
        }
    }
    return 1;
}

int npu_ts_cycle_idle(const npu_ts_cycle_t *model)
{
    if (model == (const npu_ts_cycle_t *)0) {
        return 0;
    }
    return ts_model_idle(model);
}

static void ts_drive_outputs(
    const npu_ts_cycle_t *model,
    const npu_ts_cycle_inputs_t *inputs,
    npu_ts_cycle_outputs_t *outputs)
{
    uint32_t port;
    uint8_t free_task;
    uint8_t free_desc;

    memset(outputs, 0, sizeof(*outputs));
    outputs->cycle = model->cycle;
    free_task = ts_find_free_task(model);
    free_desc = ts_find_free_desc(model);
    if (model->cfe_half_valid != 0u) {
        outputs->cfe.ready = 1u;
    } else if (free_task != NPU_TS_INVALID_INDEX &&
               free_desc != NPU_TS_INVALID_INDEX &&
               ((inputs->stop_accept == 0u &&
                 inputs->quiesce_req == 0u &&
                 inputs->abort_req == 0u) ||
                inputs->abort_req != 0u)) {
        /*
         * During a controlled reset, CFE has already stopped accepting new
         * host commands. Beats still visible here belong to commands that
         * CFE accepted before quiesce. TS must consume both beats and create
         * an ABORTED record so CFE can become idle.
         */
        outputs->cfe.ready = 1u;
    }
    outputs->cfe.lookup_ready =
        (uint8_t)(model->lookup_rsp_valid == 0u);
    outputs->cfe.lookup_rsp_valid =
        model->lookup_rsp_valid;
    outputs->cfe.lookup_busy =
        model->lookup_rsp_busy;

    if (model->dfu.valid != 0u &&
        model->dfu.task_slot < NPU_TS_TASK_COUNT) {
        const npu_ts_task_entry_t *task =
            &model->task[model->dfu.task_slot];

        outputs->dfu.req_valid =
            (uint8_t)(model->dfu.request_valid != 0u &&
                      inputs->abort_req == 0u &&
                      inputs->mif_reset_abort == 0u);
        outputs->dfu.req_addr = model->dfu.req_addr;
        outputs->dfu.req_beats =
            (uint8_t)(model->dfu.expected_beats - 1u);
        outputs->dfu.req_tag = task->cmd.command_id;
        outputs->dfu.req_task_id = task->cmd.command_id;
        outputs->dfu.req_attr = 0u;
        outputs->dfu.rsp_ready =
            (uint8_t)(model->dfu.waiting_response != 0u &&
                      inputs->mif_reset_abort == 0u);
    }

    for (port = 0u; port < NPU_TS_ENGINE_COUNT; port++) {
        const npu_ts_desc_port_state_t *state =
            &model->desc_port[port];

        outputs->engine[port].req_valid =
            (uint8_t)(model->req_hold[port].valid != 0u &&
                      inputs->abort_req == 0u &&
                      (port != NPU_TS_PORT_DMA ||
                       inputs->mif_reset_abort == 0u));
        outputs->engine[port].req_data =
            model->req_hold[port].data;
        outputs->engine[port].cancel_valid =
            (uint8_t)(model->cancel[port].phase ==
                      NPU_TS_CANCEL_REQUEST);
        outputs->engine[port].cancel_status =
            model->cancel[port].status;
        outputs->engine[port].done_ready =
            (uint8_t)(model->engine_active_task[port] !=
                      NPU_TS_INVALID_INDEX);
        outputs->engine[port].abort =
            (uint8_t)(inputs->abort_req != 0u ||
                      (port == NPU_TS_PORT_DMA &&
                       inputs->mif_reset_abort != 0u));

        outputs->desc[port].req_ready =
            (uint8_t)(state->count <
                      NPU_TS_DESC_TAG_COUNT);
        if (state->count != 0u) {
            const npu_ts_desc_rsp_entry_t *entry =
                &state->queue[state->head];

            if (entry->valid != 0u &&
                entry->ready_cycle <= model->cycle) {
                outputs->desc[port].rsp_valid = 1u;
                outputs->desc[port].rsp_data = entry->data;
                outputs->desc[port].rsp_tag = entry->tag;
                outputs->desc[port].rsp_status =
                    entry->status;
            }
        }
    }

    outputs->ctl.ready =
        (uint8_t)(model->ctl.active == 0u &&
                  model->ctl.rsp_valid == 0u);
    outputs->ctl.rsp_valid = model->ctl.rsp_valid;
    outputs->ctl.rsp_data = model->ctl.rsp_data;

    outputs->irq_success_pulse =
        model->irq_success_pending;
    outputs->irq_error_pulse =
        model->irq_error_pending;
    outputs->irq_success_task_id =
        model->irq_success_task_id;
    outputs->irq_error_task_id =
        model->irq_error_task_id;
    outputs->done_protocol_error_mask =
        model->done_protocol_error_pending;
    for (port = 0u; port < NPU_TS_ENGINE_COUNT; port++) {
        outputs->done_protocol_error_count[port] =
            model->done_protocol_error_count[port];
    }

    if (model->terminal_notice_count != 0u) {
        const npu_ts_terminal_notice_t *notice =
            &model->terminal_notice[
                model->terminal_notice_head];

        outputs->terminal_valid = 1u;
        outputs->terminal_task_id = notice->task_id;
        outputs->terminal_status = notice->status;
        outputs->terminal_engine = notice->engine;
        outputs->terminal_opcode = notice->opcode;
        outputs->terminal_fault_addr =
            notice->fault_addr;
        outputs->terminal_error_info =
            notice->error_info;
        outputs->terminal_done_flags =
            notice->done_flags;
        outputs->terminal_irq_on_success =
            notice->irq_on_success;
        outputs->terminal_irq_on_error =
            notice->irq_on_error;
    }

    outputs->task_slots_used = ts_task_slots_used(model);
    outputs->desc_slots_used = ts_desc_slots_used(model);
    outputs->idle = (uint8_t)ts_model_idle(model);
    outputs->quiescent =
        (uint8_t)ts_model_quiescent(model, inputs);
}

static void ts_consume_terminal_notice(npu_ts_cycle_t *model)
{
    if (model->terminal_notice_count == 0u) {
        return;
    }
    model->terminal_notice_head =
        (uint8_t)((model->terminal_notice_head + 1u) %
                  NPU_TS_TASK_COUNT);
    model->terminal_notice_count--;
}

void npu_ts_cycle_step(npu_ts_cycle_t *model,
                       const npu_ts_cycle_inputs_t *inputs,
                       npu_ts_cycle_outputs_t *outputs)
{
    uint32_t port;

    if (model == (npu_ts_cycle_t *)0 ||
        inputs == (const npu_ts_cycle_inputs_t *)0 ||
        outputs == (npu_ts_cycle_outputs_t *)0) {
        return;
    }
    if (inputs->reset_n == 0u) {
        npu_ts_cycle_reset(model);
        memset(outputs, 0, sizeof(*outputs));
        return;
    }

    ts_drive_outputs(model, inputs, outputs);

    if (outputs->terminal_valid != 0u) {
        ts_consume_terminal_notice(model);
    }
    model->irq_success_pending = 0u;
    model->irq_error_pending = 0u;
    model->done_protocol_error_pending = 0u;

    if (outputs->cfe.lookup_rsp_valid != 0u) {
        /*
         * The lookup response has no ready signal in the specified
         * interface. It is therefore a one-cycle pulse.
         */
        model->lookup_rsp_valid = 0u;
    }
    if (inputs->cfe.lookup_valid != 0u &&
        outputs->cfe.lookup_ready != 0u) {
        model->lookup_rsp_busy =
            (uint8_t)(ts_find_task_slot(
                          model, inputs->cfe.lookup_id) !=
                      NPU_TS_INVALID_INDEX);
        model->lookup_rsp_valid = 1u;
    }

    if (model->cfe_half_valid != 0u &&
        (inputs->abort_req != 0u ||
         inputs->quiesce_req != 0u)) {
        model->cfe_half_terminate = 1u;
    }
    if (inputs->cfe.valid != 0u &&
        outputs->cfe.ready != 0u) {
        if (model->cfe_half_valid == 0u) {
            ts_accept_first_beat(model, &inputs->cfe);
        } else {
            ts_accept_second_beat(
                model, &inputs->cfe,
                model->cfe_half_terminate);
        }
    }

    if (outputs->ctl.rsp_valid != 0u &&
        inputs->ctl.rsp_ready != 0u) {
        if (model->ctl.ack_release_valid != 0u &&
            model->ctl.ack_task_slot < NPU_TS_TASK_COUNT) {
            ts_free_task(model,
                         model->ctl.ack_task_slot);
        }
        model->ctl.rsp_valid = 0u;
        model->ctl.ack_release_valid = 0u;
        model->ctl.ack_task_slot = NPU_TS_INVALID_INDEX;
    }
    if (inputs->ctl.cancel != 0u) {
        ts_ctl_cancel(model);
    }

    for (port = 0u; port < NPU_TS_ENGINE_COUNT; port++) {
        if (outputs->desc[port].rsp_valid != 0u &&
            inputs->desc[port].rsp_ready != 0u) {
            ts_desc_pop_response(model, (uint8_t)port);
        }
        if (inputs->desc[port].req_valid != 0u &&
            outputs->desc[port].req_ready != 0u) {
            ts_desc_accept_request(
                model, (uint8_t)port,
                &inputs->desc[port]);
        }
    }

    if (outputs->dfu.req_valid != 0u &&
        inputs->dfu.req_ready != 0u) {
        model->dfu.request_valid = 0u;
        model->dfu.waiting_response = 1u;
    }
    if (inputs->dfu.rsp_valid != 0u &&
        outputs->dfu.rsp_ready != 0u) {
        ts_dfu_accept_response(model, &inputs->dfu);
    }

    for (port = 0u; port < NPU_TS_ENGINE_COUNT; port++) {
        if (outputs->engine[port].req_valid != 0u &&
            inputs->engine[port].req_ready != 0u &&
            inputs->abort_req == 0u) {
            ts_accept_engine_request(model, (uint8_t)port);
        }
        if (inputs->engine[port].done_valid != 0u &&
            outputs->engine[port].done_ready != 0u) {
            ts_accept_done_beat(
                model, (uint8_t)port,
                &inputs->engine[port]);
        }
        if (outputs->engine[port].cancel_valid != 0u &&
            inputs->engine[port].cancel_ready != 0u &&
            model->cancel[port].phase ==
                NPU_TS_CANCEL_REQUEST) {
            model->cancel[port].phase =
                NPU_TS_CANCEL_WAIT_DONE;
        }
    }

    if (inputs->abort_req != 0u) {
        ts_apply_abort(model, inputs);
    }
    if (inputs->mif_reset_abort != 0u) {
        ts_apply_mif_reset_abort(model);
    }

    ts_finish_commits(model);
    ts_advance_descriptor_states(model);
    ts_run_control_fences(model, inputs);
    ts_check_engine_timeouts(model, inputs);
    ts_ctl_advance(model);

    if (inputs->abort_req == 0u) {
        if (inputs->mif_reset_abort == 0u) {
            ts_start_next_dfu(model);
        }
        ts_start_control_tasks(model);
        ts_select_engine_requests(model);
    }

    if (inputs->ctl.valid != 0u &&
        outputs->ctl.ready != 0u) {
        ts_ctl_accept(model, &inputs->ctl);
    }

    model->cycle++;
}
