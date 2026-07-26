#include "npu_bus_replay_cycle.h"

#include <limits.h>
#include <string.h>

#define NPU_BUS_REPLAY_L1_MAX_BURST \
    NPU_L1_CYCLE_MAX_BEATS
#define NPU_BUS_REPLAY_MIF_MAX_BURST \
    NPU_MIF_AXI_MAX_BURST_BEATS

static uint8_t npu_bus_replay_popcount8(uint8_t value)
{
    uint8_t count = 0u;

    while (value != 0u) {
        count += (uint8_t)(value & 1u);
        value >>= 1u;
    }
    return count;
}

static int npu_bus_replay_task_status_valid(uint8_t status)
{
    return status <= (uint8_t)NPU_STATUS_ADDR_OVERLAP;
}

static int npu_bus_replay_trace_entry_valid(
    const npu_bus_trace_entry_t *entry,
    uint8_t read)
{
    if (entry->space != NPU_SPACE_L1 &&
        entry->space != NPU_SPACE_DDR) {
        return 0;
    }
    if ((entry->addr &
         (uint64_t)(NPU_BUS_TRACE_WORD_BYTES - 1u)) != 0u ||
        entry->strb == 0u ||
        entry->reserved != 0u) {
        return 0;
    }
    if (entry->space == NPU_SPACE_L1 &&
        entry->addr > UINT32_MAX) {
        return 0;
    }
    if (read != 0u) {
        return entry->port < NPU_BUS_REPLAY_READ_PORTS;
    }
    return entry->port == 0u &&
           entry->read_pass == 0u;
}

static int npu_bus_replay_trace_valid(
    const npu_bus_trace_t *trace)
{
    size_t index;

    if (trace == (const npu_bus_trace_t *)0 ||
        trace->active != 0u ||
        trace->overflow != 0u ||
        trace->read_count > trace->read_capacity ||
        trace->write_count > trace->write_capacity ||
        (trace->read_count != 0u &&
         trace->read == (npu_bus_trace_entry_t *)0) ||
        (trace->write_count != 0u &&
         trace->write == (npu_bus_trace_entry_t *)0)) {
        return 0;
    }
    for (index = 0u; index < trace->read_count; index++) {
        if (!npu_bus_replay_trace_entry_valid(
                &trace->read[index], 1u) ||
            (index != 0u &&
             trace->read[index].read_pass <
                 trace->read[index - 1u].read_pass)) {
            return 0;
        }
    }
    for (index = 0u; index < trace->write_count; index++) {
        if (!npu_bus_replay_trace_entry_valid(
                &trace->write[index], 0u)) {
            return 0;
        }
    }
    return 1;
}

static uint16_t npu_bus_replay_tag(
    const npu_bus_replay_cycle_t *replay,
    size_t index,
    uint8_t write)
{
    uint64_t value =
        (uint64_t)replay->task_id +
        (uint64_t)index +
        (write != 0u ? UINT64_C(0x800) : 0u);

    return (uint16_t)(value & UINT64_C(0xfff));
}

static int npu_bus_replay_data_equal(
    const npu_bus_trace_entry_t *entry,
    uint64_t actual)
{
    uint32_t byte;

    for (byte = 0u; byte < NPU_BUS_TRACE_WORD_BYTES; byte++) {
        if ((entry->strb & (uint8_t)(1u << byte)) != 0u &&
            (uint8_t)(entry->data >> (byte * 8u)) !=
                (uint8_t)(actual >> (byte * 8u))) {
            return 0;
        }
    }
    return 1;
}

static npu_status_t npu_bus_replay_l1_status(
    uint8_t status,
    uint16_t *done_flags)
{
    if (status == NPU_L1_STATUS_OK ||
        status == NPU_L1_STATUS_ECC_CORRECTED) {
        return NPU_STATUS_SUCCESS;
    }
    if (status == NPU_L1_STATUS_ECC_UNCORRECTABLE) {
        *done_flags |= NPU_DONE_FAULT_ADDR_IS_L1;
        return NPU_STATUS_L1_ECC_UNCORRECTABLE;
    }
    if (status == NPU_L1_STATUS_ADDR_FAULT) {
        *done_flags |= NPU_DONE_FAULT_ADDR_IS_L1;
        return NPU_STATUS_ADDR_FAULT;
    }
    return NPU_STATUS_BAD_DESC;
}

static uint16_t npu_bus_replay_error_flags(
    const npu_bus_replay_cycle_t *replay,
    uint16_t flags)
{
    if (replay->confirmed_write_bytes != 0u) {
        flags |= NPU_DONE_PARTIAL_DEST;
    }
    return flags;
}

static void npu_bus_replay_finish(
    npu_bus_replay_cycle_t *replay,
    npu_status_t status,
    uint64_t fault_addr,
    uint16_t done_flags)
{
    replay->done_status = (uint8_t)status;
    replay->done_fault_addr = fault_addr;
    replay->done_flags =
        status == NPU_STATUS_SUCCESS
            ? done_flags
            : npu_bus_replay_error_flags(
                  replay, done_flags);
    replay->done_progress =
        status == NPU_STATUS_SUCCESS
            ? replay->functional_progress
            : replay->confirmed_write_bytes;
    replay->state = NPU_BUS_REPLAY_DONE;
}

static npu_status_t npu_bus_replay_abort_status(
    const npu_bus_replay_cycle_t *replay)
{
    return replay->abort_status ==
                   (uint8_t)NPU_STATUS_TIMEOUT
               ? NPU_STATUS_TIMEOUT
               : NPU_STATUS_ABORTED;
}

static uint16_t npu_bus_replay_abort_flags(
    const npu_bus_replay_cycle_t *replay)
{
    uint16_t flags =
        replay->abort_status ==
                (uint8_t)NPU_STATUS_TIMEOUT
            ? 0u
            : NPU_DONE_ABORT_DRAINED;

    if (replay->confirmed_write_bytes != 0u) {
        flags |= NPU_DONE_PARTIAL_DEST;
    }
    return flags;
}

static void npu_bus_replay_finish_abort(
    npu_bus_replay_cycle_t *replay)
{
    npu_bus_replay_finish(
        replay, npu_bus_replay_abort_status(replay), 0u,
        npu_bus_replay_abort_flags(replay));
}

static void npu_bus_replay_lock_terminal(
    npu_bus_replay_cycle_t *replay,
    npu_status_t status,
    uint64_t fault_addr,
    uint16_t done_flags,
    uint8_t protocol_error)
{
    if (protocol_error != 0u) {
        replay->protocol_error_pulse = 1u;
    }
    if (replay->aborting != 0u ||
        replay->terminal_locked != 0u) {
        return;
    }
    replay->terminal_locked = 1u;
    replay->terminal_status = (uint8_t)status;
    replay->terminal_fault_addr = fault_addr;
    replay->terminal_done_flags = done_flags;
}

static void npu_bus_replay_finish_terminal(
    npu_bus_replay_cycle_t *replay)
{
    npu_bus_replay_finish(
        replay, (npu_status_t)replay->terminal_status,
        replay->terminal_fault_addr,
        replay->terminal_done_flags);
}

static int npu_bus_replay_entry_matches_l1(
    const npu_bus_trace_entry_t *entry,
    uint8_t port)
{
    return entry->space == NPU_SPACE_L1 &&
           entry->port == port;
}

static int npu_bus_replay_entry_matches_mif(
    const npu_bus_trace_entry_t *entry)
{
    return entry->space == NPU_SPACE_DDR;
}

static size_t npu_bus_replay_next_l1_entry(
    const npu_bus_replay_cycle_t *replay,
    size_t start,
    uint8_t port)
{
    size_t index;

    for (index = start; index < replay->read_pass_end;
         index++) {
        if (npu_bus_replay_entry_matches_l1(
                &replay->trace->read[index], port)) {
            return index;
        }
    }
    return replay->read_pass_end;
}

static size_t npu_bus_replay_next_mif_entry(
    const npu_bus_replay_cycle_t *replay,
    size_t start)
{
    size_t index;

    for (index = start; index < replay->read_pass_end;
         index++) {
        if (npu_bus_replay_entry_matches_mif(
                &replay->trace->read[index])) {
            return index;
        }
    }
    return replay->read_pass_end;
}

static int npu_bus_replay_next_addr(
    uint64_t addr,
    uint16_t beats,
    uint64_t *expected)
{
    uint64_t offset =
        (uint64_t)beats * NPU_BUS_TRACE_WORD_BYTES;

    if (UINT64_MAX - addr < offset) {
        return 0;
    }
    *expected = addr + offset;
    return 1;
}

static void npu_bus_replay_prepare_l1_lane(
    npu_bus_replay_cycle_t *replay,
    uint8_t port)
{
    npu_bus_replay_read_lane_t *lane =
        &replay->l1_read_lane[port];
    size_t first;
    size_t next;
    size_t last;
    uint16_t beats = 1u;
    uint64_t expected_addr;

    if (replay->aborting != 0u ||
        replay->terminal_locked != 0u) {
        lane->state = NPU_BUS_REPLAY_LANE_IDLE;
        lane->scan_index = replay->read_pass_end;
        return;
    }
    first = npu_bus_replay_next_l1_entry(
        replay, lane->scan_index, port);
    if (first == replay->read_pass_end) {
        lane->state = NPU_BUS_REPLAY_LANE_IDLE;
        lane->scan_index = replay->read_pass_end;
        return;
    }
    last = first;
    next = first + 1u;
    while (beats < NPU_BUS_REPLAY_L1_MAX_BURST) {
        next = npu_bus_replay_next_l1_entry(
            replay, next, port);
        if (next == replay->read_pass_end ||
            !npu_bus_replay_next_addr(
                replay->trace->read[first].addr,
                beats, &expected_addr) ||
            replay->trace->read[next].addr !=
                expected_addr) {
            break;
        }
        last = next;
        beats++;
        next++;
    }
    lane->state = NPU_BUS_REPLAY_LANE_REQUEST;
    lane->group_first_index = first;
    lane->group_last_index = last;
    lane->entry_index = first;
    lane->beats = beats;
    lane->response_beat = 0u;
    lane->tag = npu_bus_replay_tag(
        replay, first, 0u);
}

static void npu_bus_replay_prepare_mif_lane(
    npu_bus_replay_cycle_t *replay)
{
    npu_bus_replay_read_lane_t *lane =
        &replay->mif_read_lane;
    size_t first;
    size_t next;
    size_t last;
    uint16_t beats = 1u;
    uint64_t expected_addr;

    if (replay->aborting != 0u ||
        replay->terminal_locked != 0u) {
        lane->state = NPU_BUS_REPLAY_LANE_IDLE;
        lane->scan_index = replay->read_pass_end;
        return;
    }
    first = npu_bus_replay_next_mif_entry(
        replay, lane->scan_index);
    if (first == replay->read_pass_end) {
        lane->state = NPU_BUS_REPLAY_LANE_IDLE;
        lane->scan_index = replay->read_pass_end;
        return;
    }
    last = first;
    next = first + 1u;
    while (beats < NPU_BUS_REPLAY_MIF_MAX_BURST) {
        next = npu_bus_replay_next_mif_entry(
            replay, next);
        if (next == replay->read_pass_end ||
            !npu_bus_replay_next_addr(
                replay->trace->read[first].addr,
                beats, &expected_addr) ||
            replay->trace->read[next].addr !=
                expected_addr) {
            break;
        }
        last = next;
        beats++;
        next++;
    }
    lane->state = NPU_BUS_REPLAY_LANE_REQUEST;
    lane->group_first_index = first;
    lane->group_last_index = last;
    lane->entry_index = first;
    lane->beats = beats;
    lane->response_beat = 0u;
    lane->tag = npu_bus_replay_tag(
        replay, first, 0u);
}

static int npu_bus_replay_read_lanes_idle(
    const npu_bus_replay_cycle_t *replay)
{
    uint8_t port;

    for (port = 0u; port < NPU_BUS_REPLAY_READ_PORTS;
         port++) {
        if (replay->l1_read_lane[port].state !=
            NPU_BUS_REPLAY_LANE_IDLE) {
            return 0;
        }
    }
    return replay->mif_read_lane.state ==
           NPU_BUS_REPLAY_LANE_IDLE;
}

static int npu_bus_replay_validate_pass(
    npu_bus_replay_cycle_t *replay)
{
    size_t index;

    for (index = replay->read_pass_start;
         index < replay->read_pass_end; index++) {
        const npu_bus_trace_entry_t *entry =
            &replay->trace->read[index];

        if (entry->port >=
            NPU_BUS_REPLAY_READ_PORTS) {
            npu_bus_replay_lock_terminal(
                replay, NPU_STATUS_BAD_DESC, 0u, 0u,
                1u);
            return 0;
        }
        if (entry->space != NPU_SPACE_L1 &&
            entry->space != NPU_SPACE_DDR) {
            npu_bus_replay_lock_terminal(
                replay, NPU_STATUS_BAD_DESC, 0u, 0u,
                1u);
            return 0;
        }
    }
    return 1;
}

static void npu_bus_replay_prepare_read_pass(
    npu_bus_replay_cycle_t *replay,
    size_t start)
{
    uint8_t port;

    replay->read_pass_start = start;
    replay->read_pass =
        replay->trace->read[start].read_pass;
    replay->read_pass_end = start + 1u;
    while (replay->read_pass_end <
               replay->trace->read_count &&
           replay->trace
                   ->read[replay->read_pass_end]
                   .read_pass == replay->read_pass) {
        replay->read_pass_end++;
    }
    for (port = 0u; port < NPU_BUS_REPLAY_READ_PORTS;
         port++) {
        (void)memset(
            &replay->l1_read_lane[port], 0,
            sizeof(replay->l1_read_lane[port]));
        replay->l1_read_lane[port].scan_index = start;
    }
    (void)memset(
        &replay->mif_read_lane, 0,
        sizeof(replay->mif_read_lane));
    replay->mif_read_lane.scan_index = start;
    replay->state = NPU_BUS_REPLAY_READ_REQUEST;
    if (!npu_bus_replay_validate_pass(replay)) {
        return;
    }
    for (port = 0u; port < NPU_BUS_REPLAY_READ_PORTS;
         port++) {
        npu_bus_replay_prepare_l1_lane(replay, port);
    }
    npu_bus_replay_prepare_mif_lane(replay);
}

static void npu_bus_replay_prepare_write_group(
    npu_bus_replay_cycle_t *replay)
{
    const npu_bus_trace_entry_t *first =
        &replay->trace->write[replay->write_index];
    size_t index;
    uint16_t beats = 1u;
    uint16_t limit;
    uint64_t expected_addr;

    if (first->space == NPU_SPACE_L1) {
        limit = NPU_BUS_REPLAY_L1_MAX_BURST;
    } else if (first->space == NPU_SPACE_DDR) {
        limit = NPU_BUS_REPLAY_MIF_MAX_BURST;
    } else {
        npu_bus_replay_finish(
            replay, NPU_STATUS_BAD_DESC, 0u, 0u);
        replay->protocol_error_pulse = 1u;
        return;
    }
    index = replay->write_index + 1u;
    while (index < replay->trace->write_count &&
           beats < limit &&
           replay->trace->write[index].space ==
               first->space &&
           npu_bus_replay_next_addr(
               first->addr, beats, &expected_addr) &&
           replay->trace->write[index].addr ==
               expected_addr) {
        beats++;
        index++;
    }
    replay->write_group_beats = beats;
    replay->write_data_beat = 0u;
    replay->current_tag = npu_bus_replay_tag(
        replay, replay->write_index, 1u);
    replay->write_request_sent = 0u;
    replay->write_data_sent = 0u;
    replay->state = NPU_BUS_REPLAY_WRITE_TRANSFER;
}

static void npu_bus_replay_after_reads(
    npu_bus_replay_cycle_t *replay)
{
    if (replay->aborting != 0u) {
        npu_bus_replay_finish_abort(replay);
    } else if (replay->terminal_locked != 0u) {
        npu_bus_replay_finish_terminal(replay);
    } else if (replay->functional_status !=
               NPU_STATUS_SUCCESS) {
        npu_bus_replay_finish(
            replay,
            (npu_status_t)replay->functional_status,
            0u, 0u);
    } else if (replay->compute_required != 0u) {
        replay->state = NPU_BUS_REPLAY_COMPUTE_HOLD;
    } else if (replay->trace->write_count != 0u) {
        replay->write_index = 0u;
        npu_bus_replay_prepare_write_group(replay);
    } else {
        npu_bus_replay_finish(
            replay, NPU_STATUS_SUCCESS, 0u, 0u);
    }
}

static void npu_bus_replay_fill_read_outputs(
    const npu_bus_replay_cycle_t *replay,
    npu_bus_replay_cycle_outputs_t *outputs)
{
    uint8_t port;

    for (port = 0u; port < NPU_BUS_REPLAY_READ_PORTS;
         port++) {
        const npu_bus_replay_read_lane_t *lane =
            &replay->l1_read_lane[port];

        if (lane->state ==
            NPU_BUS_REPLAY_LANE_REQUEST) {
            const npu_bus_trace_entry_t *entry =
                &replay->trace
                     ->read[lane->group_first_index];

            outputs->l1_read[port].req_valid = 1u;
            outputs->l1_read[port].req_addr =
                (uint32_t)entry->addr;
            outputs->l1_read[port].req_beats =
                (uint8_t)(lane->beats - 1u);
            outputs->l1_read[port].req_tag =
                lane->tag;
        } else if (
            lane->state ==
            NPU_BUS_REPLAY_LANE_RESPONSE) {
            outputs->l1_read[port].rsp_ready = 1u;
        }
    }
    if (replay->mif_read_lane.state ==
        NPU_BUS_REPLAY_LANE_REQUEST) {
        const npu_bus_replay_read_lane_t *lane =
            &replay->mif_read_lane;
        const npu_bus_trace_entry_t *entry =
            &replay->trace
                 ->read[lane->group_first_index];

        outputs->mif.req_valid = 1u;
        outputs->mif.req_write = 0u;
        outputs->mif.req_vaddr = entry->addr;
        outputs->mif.req_beats =
            (uint8_t)(lane->beats - 1u);
        outputs->mif.req_tag = lane->tag;
        outputs->mif.req_owner = NPU_MIF_OWNER_DMA;
        outputs->mif.req_task_id = replay->task_id;
        outputs->mif.req_attr = replay->req_attr;
    } else if (
        replay->mif_read_lane.state ==
        NPU_BUS_REPLAY_LANE_RESPONSE) {
        outputs->mif.rsp_ready = 1u;
    }
}

static void npu_bus_replay_fill_write_outputs(
    const npu_bus_replay_cycle_t *replay,
    npu_bus_replay_cycle_outputs_t *outputs)
{
    const npu_bus_trace_entry_t *first =
        &replay->trace->write[replay->write_index];
    const npu_bus_trace_entry_t *data_entry =
        replay->write_data_beat <
                replay->write_group_beats
            ? &replay->trace->write[
                  replay->write_index +
                  replay->write_data_beat]
            : first;

    if (first->space == NPU_SPACE_L1) {
        if (replay->state ==
            NPU_BUS_REPLAY_WRITE_TRANSFER) {
            if (replay->write_request_sent == 0u) {
                outputs->l1_write.req_valid = 1u;
                outputs->l1_write.req_addr =
                    (uint32_t)first->addr;
                outputs->l1_write.req_beats =
                    (uint8_t)(
                        replay->write_group_beats - 1u);
                outputs->l1_write.req_tag =
                    replay->current_tag;
            }
            if (replay->write_data_sent == 0u) {
                outputs->l1_write.data_valid = 1u;
                outputs->l1_write.data =
                    data_entry->data;
                outputs->l1_write.strb =
                    data_entry->strb;
                outputs->l1_write.last =
                    replay->write_data_beat + 1u ==
                            replay->write_group_beats
                        ? 1u
                        : 0u;
            }
        } else {
            outputs->l1_write.rsp_ready = 1u;
        }
        return;
    }
    if (replay->state ==
        NPU_BUS_REPLAY_WRITE_TRANSFER) {
        if (replay->write_request_sent == 0u) {
            outputs->mif.req_valid = 1u;
            outputs->mif.req_write = 1u;
            outputs->mif.req_vaddr = first->addr;
            outputs->mif.req_beats =
                (uint8_t)(
                    replay->write_group_beats - 1u);
            outputs->mif.req_tag =
                replay->current_tag;
            outputs->mif.req_owner =
                NPU_MIF_OWNER_DMA;
            outputs->mif.req_task_id =
                replay->task_id;
            outputs->mif.req_attr = replay->req_attr;
        }
        if (replay->write_data_sent == 0u) {
            outputs->mif.wvalid = 1u;
            outputs->mif.wdata = data_entry->data;
            outputs->mif.wstrb = data_entry->strb;
            outputs->mif.wlast =
                replay->write_data_beat + 1u ==
                        replay->write_group_beats
                    ? 1u
                    : 0u;
            outputs->mif.wtag = replay->current_tag;
        }
    } else {
        outputs->mif.rsp_ready = 1u;
    }
}

static void npu_bus_replay_fill_outputs(
    const npu_bus_replay_cycle_t *replay,
    npu_bus_replay_cycle_outputs_t *outputs)
{
    uint8_t port;

    (void)memset(outputs, 0, sizeof(*outputs));
    outputs->busy =
        replay->state != NPU_BUS_REPLAY_IDLE ? 1u : 0u;
    outputs->quiescent =
        replay->state == NPU_BUS_REPLAY_IDLE ||
                replay->state == NPU_BUS_REPLAY_DONE
            ? 1u
            : 0u;
    outputs->confirmed_write_bytes =
        replay->confirmed_write_bytes;
    outputs->protocol_error =
        replay->protocol_error_pulse;
    outputs->accepted_read_words =
        replay->accepted_read_words;
    for (port = 0u; port < NPU_BUS_REPLAY_READ_PORTS;
         port++) {
        outputs->accepted_read_words_by_port[port] =
            replay->accepted_read_words_by_port[port];
    }
    outputs->cycle = replay->cycle;

    if (replay->state == NPU_BUS_REPLAY_COMPUTE_HOLD ||
        (replay->stream_compute != 0u &&
         replay->compute_required != 0u &&
         replay->accepted_read_words != 0u &&
         replay->aborting == 0u &&
         replay->terminal_locked == 0u &&
         (replay->state ==
              NPU_BUS_REPLAY_READ_REQUEST ||
          replay->state ==
              NPU_BUS_REPLAY_READ_RESPONSE))) {
        outputs->compute_valid = 1u;
    }
    if (replay->state == NPU_BUS_REPLAY_DONE) {
        outputs->done_valid = 1u;
        outputs->done_status = replay->done_status;
        outputs->done_fault_addr =
            replay->done_fault_addr;
        outputs->done_flags = replay->done_flags;
        outputs->done_progress = replay->done_progress;
    } else if (
        replay->state == NPU_BUS_REPLAY_READ_REQUEST ||
        replay->state == NPU_BUS_REPLAY_READ_RESPONSE) {
        npu_bus_replay_fill_read_outputs(
            replay, outputs);
    } else if (
        replay->state == NPU_BUS_REPLAY_WRITE_TRANSFER ||
        replay->state == NPU_BUS_REPLAY_WRITE_RESPONSE) {
        npu_bus_replay_fill_write_outputs(
            replay, outputs);
    }
}

void npu_bus_replay_cycle_reset(
    npu_bus_replay_cycle_t *replay)
{
    if (replay == (npu_bus_replay_cycle_t *)0) {
        return;
    }
    (void)memset(replay, 0, sizeof(*replay));
    replay->state = NPU_BUS_REPLAY_IDLE;
    replay->abort_status =
        (uint8_t)NPU_STATUS_ABORTED;
}

int npu_bus_replay_cycle_start_stream(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_trace_t *trace,
    uint16_t task_id,
    uint8_t req_attr,
    npu_status_t functional_status,
    uint64_t functional_progress,
    uint8_t compute_required,
    uint8_t stream_compute)
{
    uint64_t cycle;

    if (replay == (npu_bus_replay_cycle_t *)0 ||
        replay->state != NPU_BUS_REPLAY_IDLE ||
        task_id > 0x0fffu ||
        !npu_bus_replay_trace_valid(trace)) {
        return 0;
    }
    cycle = replay->cycle;
    (void)memset(replay, 0, sizeof(*replay));
    replay->cycle = cycle;
    replay->trace = trace;
    replay->task_id = task_id;
    replay->req_attr = req_attr;
    replay->functional_status =
        (uint8_t)functional_status;
    replay->functional_progress = functional_progress;
    replay->compute_required =
        compute_required != 0u ? 1u : 0u;
    replay->stream_compute =
        compute_required != 0u &&
                stream_compute != 0u
            ? 1u
            : 0u;
    replay->abort_status =
        (uint8_t)NPU_STATUS_ABORTED;
    if (trace->read_count != 0u) {
        npu_bus_replay_prepare_read_pass(replay, 0u);
        if (replay->terminal_locked != 0u &&
            npu_bus_replay_read_lanes_idle(replay)) {
            npu_bus_replay_finish_terminal(replay);
        }
    } else {
        npu_bus_replay_after_reads(replay);
    }
    return 1;
}

int npu_bus_replay_cycle_start(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_trace_t *trace,
    uint16_t task_id,
    uint8_t req_attr,
    npu_status_t functional_status,
    uint64_t functional_progress,
    uint8_t compute_required)
{
    return npu_bus_replay_cycle_start_stream(
        replay, trace, task_id, req_attr,
        functional_status, functional_progress,
        compute_required, 0u);
}

static void npu_bus_replay_complete_l1_group(
    npu_bus_replay_cycle_t *replay,
    uint8_t port)
{
    npu_bus_replay_read_lane_t *lane =
        &replay->l1_read_lane[port];

    replay->read_index += lane->beats;
    lane->scan_index = lane->group_last_index + 1u;
    lane->state = NPU_BUS_REPLAY_LANE_IDLE;
}

static void npu_bus_replay_complete_mif_group(
    npu_bus_replay_cycle_t *replay)
{
    npu_bus_replay_read_lane_t *lane =
        &replay->mif_read_lane;

    replay->read_index += lane->beats;
    lane->scan_index = lane->group_last_index + 1u;
    lane->state = NPU_BUS_REPLAY_LANE_IDLE;
}

static size_t npu_bus_replay_l1_next_in_group(
    const npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_read_lane_t *lane,
    uint8_t port)
{
    return npu_bus_replay_next_l1_entry(
        replay, lane->entry_index + 1u, port);
}

static size_t npu_bus_replay_mif_next_in_group(
    const npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_read_lane_t *lane)
{
    return npu_bus_replay_next_mif_entry(
        replay, lane->entry_index + 1u);
}

static void npu_bus_replay_accept_l1_response(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_cycle_inputs_t *inputs,
    uint8_t port)
{
    npu_bus_replay_read_lane_t *lane =
        &replay->l1_read_lane[port];
    const npu_bus_trace_entry_t *entry =
        &replay->trace->read[lane->entry_index];
    uint8_t expected_last =
        lane->response_beat + 1u == lane->beats
            ? 1u
            : 0u;
    uint16_t flags = 0u;
    npu_status_t status = npu_bus_replay_l1_status(
        inputs->l1_read[port].rsp_status, &flags);
    int structural_error =
        inputs->l1_read[port].rsp_tag != lane->tag ||
        inputs->l1_read[port].rsp_last != expected_last;
    int data_accepted = 0;

    if (replay->aborting != 0u ||
        replay->terminal_locked != 0u) {
        if (structural_error) {
            replay->protocol_error_pulse = 1u;
        }
    } else if (structural_error) {
        npu_bus_replay_lock_terminal(
            replay, NPU_STATUS_BAD_DESC, 0u, 0u, 1u);
    } else if (status != NPU_STATUS_SUCCESS) {
        npu_bus_replay_lock_terminal(
            replay, status, entry->addr, flags, 0u);
    } else if (!npu_bus_replay_data_equal(
                   entry,
                   inputs->l1_read[port].rsp_data)) {
        npu_bus_replay_lock_terminal(
            replay, NPU_STATUS_BUS_SLVERR, 0u, 0u, 1u);
    } else {
        data_accepted = 1;
    }
    if (data_accepted != 0) {
        replay->accepted_read_words++;
        replay->accepted_read_words_by_port[port]++;
    }

    lane->response_beat++;
    if (lane->response_beat >= lane->beats ||
        (inputs->l1_read[port].rsp_last != 0u &&
         expected_last == 0u)) {
        npu_bus_replay_complete_l1_group(
            replay, port);
    } else {
        size_t next = npu_bus_replay_l1_next_in_group(
            replay, lane, port);

        if (next > lane->group_last_index) {
            npu_bus_replay_lock_terminal(
                replay, NPU_STATUS_BAD_DESC, 0u, 0u, 1u);
            npu_bus_replay_complete_l1_group(
                replay, port);
        } else {
            lane->entry_index = next;
        }
    }
}

static void npu_bus_replay_accept_mif_response(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_cycle_inputs_t *inputs)
{
    npu_bus_replay_read_lane_t *lane =
        &replay->mif_read_lane;
    const npu_bus_trace_entry_t *entry =
        &replay->trace->read[lane->entry_index];
    uint8_t expected_last =
        lane->response_beat + 1u == lane->beats
            ? 1u
            : 0u;
    int structural_error =
        inputs->mif.rsp_tag != lane->tag ||
        inputs->mif.rsp_is_write != 0u ||
        inputs->mif.rsp_last != expected_last;
    int status_error =
        !npu_bus_replay_task_status_valid(
            inputs->mif.rsp_status);
    int data_accepted = 0;

    if (replay->aborting != 0u ||
        replay->terminal_locked != 0u) {
        if (structural_error || status_error) {
            replay->protocol_error_pulse = 1u;
        }
    } else if (structural_error || status_error) {
        npu_bus_replay_lock_terminal(
            replay, NPU_STATUS_BAD_DESC, 0u, 0u, 1u);
    } else if (inputs->mif.rsp_status !=
               NPU_STATUS_SUCCESS) {
        npu_bus_replay_lock_terminal(
            replay,
            (npu_status_t)inputs->mif.rsp_status,
            entry->addr, 0u, 0u);
    } else if (!npu_bus_replay_data_equal(
                   entry, inputs->mif.rsp_data)) {
        npu_bus_replay_lock_terminal(
            replay, NPU_STATUS_BUS_SLVERR, 0u, 0u, 1u);
    } else {
        data_accepted = 1;
    }
    if (data_accepted != 0) {
        replay->accepted_read_words++;
        replay->accepted_read_words_by_port[
            entry->port]++;
    }

    lane->response_beat++;
    if (lane->response_beat >= lane->beats ||
        (inputs->mif.rsp_last != 0u &&
         expected_last == 0u)) {
        npu_bus_replay_complete_mif_group(replay);
    } else {
        size_t next = npu_bus_replay_mif_next_in_group(
            replay, lane);

        if (next > lane->group_last_index) {
            npu_bus_replay_lock_terminal(
                replay, NPU_STATUS_BAD_DESC, 0u, 0u, 1u);
            npu_bus_replay_complete_mif_group(replay);
        } else {
            lane->entry_index = next;
        }
    }
}

static void npu_bus_replay_withdraw_read_requests(
    npu_bus_replay_cycle_t *replay)
{
    uint8_t port;

    for (port = 0u; port < NPU_BUS_REPLAY_READ_PORTS;
         port++) {
        npu_bus_replay_read_lane_t *lane =
            &replay->l1_read_lane[port];

        if (lane->state ==
            NPU_BUS_REPLAY_LANE_REQUEST) {
            lane->state = NPU_BUS_REPLAY_LANE_IDLE;
            lane->scan_index = replay->read_pass_end;
        }
    }
    if (replay->mif_read_lane.state ==
        NPU_BUS_REPLAY_LANE_REQUEST) {
        replay->mif_read_lane.state =
            NPU_BUS_REPLAY_LANE_IDLE;
        replay->mif_read_lane.scan_index =
            replay->read_pass_end;
    }
}

static void npu_bus_replay_schedule_read_lanes(
    npu_bus_replay_cycle_t *replay)
{
    uint8_t port;

    if (replay->aborting != 0u ||
        replay->terminal_locked != 0u) {
        npu_bus_replay_withdraw_read_requests(replay);
        return;
    }
    for (port = 0u; port < NPU_BUS_REPLAY_READ_PORTS;
         port++) {
        if (replay->l1_read_lane[port].state ==
            NPU_BUS_REPLAY_LANE_IDLE) {
            npu_bus_replay_prepare_l1_lane(
                replay, port);
        }
    }
    if (replay->mif_read_lane.state ==
        NPU_BUS_REPLAY_LANE_IDLE) {
        npu_bus_replay_prepare_mif_lane(replay);
    }
}

static void npu_bus_replay_finish_or_next_pass(
    npu_bus_replay_cycle_t *replay)
{
    if (!npu_bus_replay_read_lanes_idle(replay)) {
        return;
    }
    if (replay->aborting != 0u) {
        npu_bus_replay_finish_abort(replay);
    } else if (replay->terminal_locked != 0u) {
        npu_bus_replay_finish_terminal(replay);
    } else if (replay->read_pass_end <
               replay->trace->read_count) {
        npu_bus_replay_prepare_read_pass(
            replay, replay->read_pass_end);
    } else {
        npu_bus_replay_after_reads(replay);
    }
}

static void npu_bus_replay_read_step(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_cycle_inputs_t *inputs,
    const npu_bus_replay_cycle_outputs_t *outputs)
{
    uint8_t l1_state[NPU_BUS_REPLAY_READ_PORTS];
    uint8_t mif_state = replay->mif_read_lane.state;
    uint8_t port;

    for (port = 0u; port < NPU_BUS_REPLAY_READ_PORTS;
         port++) {
        l1_state[port] =
            replay->l1_read_lane[port].state;
    }

    for (port = 0u; port < NPU_BUS_REPLAY_READ_PORTS;
         port++) {
        if (l1_state[port] ==
                NPU_BUS_REPLAY_LANE_REQUEST &&
            outputs->l1_read[port].req_valid != 0u &&
            inputs->l1_read[port].req_ready != 0u) {
            replay->l1_read_lane[port].state =
                NPU_BUS_REPLAY_LANE_RESPONSE;
        }
    }
    if (mif_state == NPU_BUS_REPLAY_LANE_REQUEST &&
        outputs->mif.req_valid != 0u &&
        inputs->mif.req_ready != 0u) {
        replay->mif_read_lane.state =
            NPU_BUS_REPLAY_LANE_RESPONSE;
    }

    for (port = 0u; port < NPU_BUS_REPLAY_READ_PORTS;
         port++) {
        if (l1_state[port] ==
                NPU_BUS_REPLAY_LANE_RESPONSE &&
            outputs->l1_read[port].rsp_ready != 0u &&
            inputs->l1_read[port].rsp_valid != 0u) {
            npu_bus_replay_accept_l1_response(
                replay, inputs, port);
        }
    }
    if (mif_state == NPU_BUS_REPLAY_LANE_RESPONSE &&
        outputs->mif.rsp_ready != 0u &&
        inputs->mif.rsp_valid != 0u) {
        npu_bus_replay_accept_mif_response(
            replay, inputs);
    }

    npu_bus_replay_schedule_read_lanes(replay);
    npu_bus_replay_finish_or_next_pass(replay);
}

static uint64_t npu_bus_replay_write_group_bytes(
    const npu_bus_replay_cycle_t *replay)
{
    uint64_t bytes = 0u;
    uint16_t beat;

    for (beat = 0u; beat < replay->write_group_beats;
         beat++) {
        bytes += npu_bus_replay_popcount8(
            replay->trace
                ->write[replay->write_index + beat]
                .strb);
    }
    return bytes;
}

static void npu_bus_replay_advance_write_group(
    npu_bus_replay_cycle_t *replay,
    uint8_t confirmed)
{
    if (confirmed != 0u) {
        replay->confirmed_write_bytes +=
            npu_bus_replay_write_group_bytes(replay);
    }
    replay->write_index += replay->write_group_beats;
    if (replay->aborting != 0u) {
        npu_bus_replay_finish_abort(replay);
    } else if (replay->write_index <
               replay->trace->write_count) {
        npu_bus_replay_prepare_write_group(replay);
    } else {
        npu_bus_replay_finish(
            replay, NPU_STATUS_SUCCESS, 0u, 0u);
    }
}

static int npu_bus_replay_write_started(
    const npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_cycle_inputs_t *inputs,
    const npu_bus_replay_cycle_outputs_t *outputs)
{
    const npu_bus_trace_entry_t *entry =
        &replay->trace->write[replay->write_index];

    if (replay->write_request_sent != 0u ||
        replay->write_data_beat != 0u) {
        return 1;
    }
    if (entry->space == NPU_SPACE_L1) {
        return (outputs->l1_write.req_valid != 0u &&
                inputs->l1_write.req_ready != 0u) ||
               (outputs->l1_write.data_valid != 0u &&
                inputs->l1_write.data_ready != 0u);
    }
    return (outputs->mif.req_valid != 0u &&
            inputs->mif.req_ready != 0u) ||
           (outputs->mif.wvalid != 0u &&
            inputs->mif.wready != 0u);
}

static void npu_bus_replay_write_transfer_step(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_cycle_inputs_t *inputs,
    const npu_bus_replay_cycle_outputs_t *outputs)
{
    const npu_bus_trace_entry_t *entry =
        &replay->trace->write[replay->write_index];
    int started = npu_bus_replay_write_started(
        replay, inputs, outputs);

    if (entry->space == NPU_SPACE_L1) {
        if (outputs->l1_write.req_valid != 0u &&
            inputs->l1_write.req_ready != 0u) {
            replay->write_request_sent = 1u;
        }
        if (outputs->l1_write.data_valid != 0u &&
            inputs->l1_write.data_ready != 0u) {
            replay->write_data_beat++;
        }
    } else {
        if (outputs->mif.req_valid != 0u &&
            inputs->mif.req_ready != 0u) {
            replay->write_request_sent = 1u;
        }
        if (outputs->mif.wvalid != 0u &&
            inputs->mif.wready != 0u) {
            replay->write_data_beat++;
        }
    }
    if (replay->write_data_beat >=
        replay->write_group_beats) {
        replay->write_data_sent = 1u;
    }
    if (replay->aborting != 0u && !started) {
        npu_bus_replay_finish_abort(replay);
    } else if (
        replay->write_request_sent != 0u &&
        replay->write_data_sent != 0u) {
        replay->state =
            NPU_BUS_REPLAY_WRITE_RESPONSE;
    }
}

static void npu_bus_replay_write_response_step(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_cycle_inputs_t *inputs,
    const npu_bus_replay_cycle_outputs_t *outputs)
{
    const npu_bus_trace_entry_t *entry =
        &replay->trace->write[replay->write_index];
    npu_status_t status;
    uint16_t flags = 0u;
    int structural_error;
    int status_error = 0;

    if (entry->space == NPU_SPACE_L1) {
        if (outputs->l1_write.rsp_ready == 0u ||
            inputs->l1_write.rsp_valid == 0u) {
            return;
        }
        status = npu_bus_replay_l1_status(
            inputs->l1_write.rsp_status, &flags);
        structural_error =
            inputs->l1_write.rsp_tag !=
            replay->current_tag;
    } else {
        if (outputs->mif.rsp_ready == 0u ||
            inputs->mif.rsp_valid == 0u) {
            return;
        }
        status_error =
            !npu_bus_replay_task_status_valid(
                inputs->mif.rsp_status);
        status = status_error
                     ? NPU_STATUS_BAD_DESC
                     : (npu_status_t)
                           inputs->mif.rsp_status;
        structural_error =
            inputs->mif.rsp_tag !=
                replay->current_tag ||
            inputs->mif.rsp_is_write == 0u ||
            inputs->mif.rsp_last == 0u;
    }
    if (replay->aborting != 0u) {
        if (structural_error || status_error) {
            replay->protocol_error_pulse = 1u;
            npu_bus_replay_advance_write_group(
                replay, 0u);
        } else {
            npu_bus_replay_advance_write_group(
                replay,
                (uint8_t)(
                    status == NPU_STATUS_SUCCESS));
        }
    } else if (structural_error || status_error) {
        replay->protocol_error_pulse = 1u;
        npu_bus_replay_finish(
            replay, NPU_STATUS_BAD_DESC, 0u, 0u);
    } else if (status != NPU_STATUS_SUCCESS) {
        npu_bus_replay_finish(
            replay, status, entry->addr, flags);
    } else {
        npu_bus_replay_advance_write_group(
            replay, 1u);
    }
}

static void npu_bus_replay_write_step(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_cycle_inputs_t *inputs,
    const npu_bus_replay_cycle_outputs_t *outputs)
{
    if (replay->state ==
        NPU_BUS_REPLAY_WRITE_TRANSFER) {
        npu_bus_replay_write_transfer_step(
            replay, inputs, outputs);
    } else {
        npu_bus_replay_write_response_step(
            replay, inputs, outputs);
    }
}

static void npu_bus_replay_compute_step(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_cycle_inputs_t *inputs,
    const npu_bus_replay_cycle_outputs_t *outputs)
{
    if (replay->aborting != 0u) {
        npu_bus_replay_finish_abort(replay);
    } else if (replay->terminal_locked != 0u) {
        npu_bus_replay_finish_terminal(replay);
    } else if (outputs->compute_valid != 0u &&
               inputs->compute_done != 0u) {
        replay->compute_required = 0u;
        if (replay->trace->write_count != 0u) {
            replay->write_index = 0u;
            npu_bus_replay_prepare_write_group(replay);
        } else {
            npu_bus_replay_finish(
                replay, NPU_STATUS_SUCCESS, 0u, 0u);
        }
    }
}

void npu_bus_replay_cycle_step(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_cycle_inputs_t *inputs,
    npu_bus_replay_cycle_outputs_t *outputs)
{
    if (replay == (npu_bus_replay_cycle_t *)0 ||
        inputs == (const npu_bus_replay_cycle_inputs_t *)0 ||
        outputs == (npu_bus_replay_cycle_outputs_t *)0) {
        return;
    }
    if (inputs->reset_n == 0u) {
        npu_bus_replay_cycle_reset(replay);
        (void)memset(outputs, 0, sizeof(*outputs));
        outputs->quiescent = 1u;
        return;
    }

    npu_bus_replay_fill_outputs(replay, outputs);
    replay->protocol_error_pulse = 0u;
    if (inputs->abort != 0u &&
        replay->state != NPU_BUS_REPLAY_IDLE &&
        replay->state != NPU_BUS_REPLAY_DONE &&
        replay->aborting == 0u &&
        replay->terminal_locked == 0u) {
        replay->aborting = 1u;
        replay->abort_status =
            inputs->abort_status ==
                    (uint8_t)NPU_STATUS_TIMEOUT
                ? (uint8_t)NPU_STATUS_TIMEOUT
                : (uint8_t)NPU_STATUS_ABORTED;
    }

    if (replay->state == NPU_BUS_REPLAY_READ_REQUEST ||
        replay->state == NPU_BUS_REPLAY_READ_RESPONSE) {
        npu_bus_replay_read_step(
            replay, inputs, outputs);
    } else if (
        replay->state == NPU_BUS_REPLAY_COMPUTE_HOLD) {
        npu_bus_replay_compute_step(
            replay, inputs, outputs);
    } else if (
        replay->state == NPU_BUS_REPLAY_WRITE_TRANSFER ||
        replay->state == NPU_BUS_REPLAY_WRITE_RESPONSE) {
        npu_bus_replay_write_step(
            replay, inputs, outputs);
    } else if (
        replay->state == NPU_BUS_REPLAY_DONE &&
        outputs->done_valid != 0u &&
        inputs->done_ready != 0u) {
        uint64_t cycle = replay->cycle;

        npu_bus_replay_cycle_reset(replay);
        replay->cycle = cycle;
    }
    replay->cycle++;
}

void npu_bus_replay_cycle_eval(
    const npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_cycle_inputs_t *inputs,
    npu_bus_replay_cycle_outputs_t *outputs)
{
    npu_bus_replay_cycle_t preview;

    if (replay == (const npu_bus_replay_cycle_t *)0 ||
        inputs == (const npu_bus_replay_cycle_inputs_t *)0 ||
        outputs == (npu_bus_replay_cycle_outputs_t *)0) {
        return;
    }
    preview = *replay;
    npu_bus_replay_cycle_step(
        &preview, inputs, outputs);
}
