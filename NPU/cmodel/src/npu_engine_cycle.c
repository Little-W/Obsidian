#include "npu_engine_cycle.h"
#include "npu_internal.h"

#include <stddef.h>
#include <string.h>

#define NPU_ENGINE_TASK_FLAGS_ALLOWED 0x003fu
#define NPU_ENGINE_TASK_FLAG_DESC_CRC (1u << 5)
#define NPU_ENGINE_FAULT_ADDR_MASK UINT64_C(0x0000ffffffffffff)

static uint8_t npu_engine_instance_valid(npu_engine_t engine)
{
    return engine == NPU_ENGINE_DMA ||
                   engine == NPU_ENGINE_MATRIX ||
                   engine == NPU_ENGINE_VECTOR ||
                   engine == NPU_ENGINE_COMPLEX
               ? 1u
               : 0u;
}

static uint8_t npu_engine_opcode_valid(npu_engine_t engine,
                                       uint8_t opcode)
{
    if (engine == NPU_ENGINE_DMA) {
        return opcode >= NPU_DMA_COPY_1D &&
                       opcode <= NPU_DMA_SPLIT
                   ? 1u
                   : 0u;
    }
    if (engine == NPU_ENGINE_MATRIX) {
        return opcode >= NPU_MATRIX_GEMM &&
                       opcode <= NPU_MATRIX_GEMM_ZERO
                   ? 1u
                   : 0u;
    }
    if (engine == NPU_ENGINE_VECTOR) {
        return opcode >= NPU_VECTOR_ADD &&
                       opcode <= NPU_VECTOR_RELU
                   ? 1u
                   : 0u;
    }
    if (engine == NPU_ENGINE_COMPLEX) {
        return opcode == NPU_COMPLEX_ACT ||
                       opcode == NPU_COMPLEX_SOFTMAX ||
                       opcode == NPU_COMPLEX_NORM ||
                       opcode == NPU_COMPLEX_STAT ||
                       opcode == NPU_COMPLEX_ADD_RESCALE
                   ? 1u
                   : 0u;
    }
    return 0u;
}

static uint8_t npu_engine_cancel_status_valid(uint8_t status)
{
    return status == (uint8_t)NPU_STATUS_TIMEOUT ||
                   status == (uint8_t)NPU_STATUS_ABORTED
               ? 1u
               : 0u;
}

static uint64_t npu_engine_raw_u64(const uint8_t *wire,
                                   size_t offset)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < NPU_REF_BUS_BYTES; byte++) {
        value |= (uint64_t)wire[offset + byte] << (byte * 8u);
    }
    return value;
}

static void npu_engine_store_word(uint8_t *wire,
                                  uint8_t word,
                                  uint64_t data)
{
    uint32_t byte;
    size_t offset = (size_t)word * NPU_REF_BUS_BYTES;

    for (byte = 0u; byte < NPU_REF_BUS_BYTES; byte++) {
        wire[offset + byte] = (uint8_t)(data >> (byte * 8u));
    }
}

uint32_t npu_engine_cycle_error_info(
    npu_engine_error_stage_t stage,
    uint16_t detail,
    uint8_t descriptor_word,
    uint8_t opcode)
{
    return ((uint32_t)stage << NPU_ENGINE_ERROR_STAGE_SHIFT) |
           (((uint32_t)detail & NPU_ENGINE_ERROR_DETAIL_MASK)
            << NPU_ENGINE_ERROR_DETAIL_SHIFT) |
           ((uint32_t)descriptor_word
            << NPU_ENGINE_ERROR_WORD_SHIFT) |
           opcode;
}

static void npu_engine_clear_task(npu_engine_cycle_t *adapter)
{
    npu_engine_t engine = adapter->engine;
    npu_model_t *functional_model = adapter->functional_model;
    npu_wire_limits_t wire_limits = adapter->wire_limits;
    uint8_t initialized = adapter->initialized;
    uint64_t cycle = adapter->cycle;
    uint64_t corrected = adapter->ecc_corrected_count;

    (void)memset(adapter, 0, sizeof(*adapter));
    adapter->engine = engine;
    adapter->functional_model = functional_model;
    adapter->wire_limits = wire_limits;
    adapter->initialized = initialized;
    adapter->cycle = cycle;
    adapter->ecc_corrected_count = corrected;
    adapter->state = NPU_ENGINE_CYCLE_IDLE;
}

npu_status_t npu_engine_cycle_init(
    npu_engine_cycle_t *adapter,
    npu_model_t *functional_model,
    npu_engine_t engine,
    const npu_wire_limits_t *limits)
{
    size_t descriptor_bytes;

    if (adapter == (npu_engine_cycle_t *)0 ||
        functional_model == (npu_model_t *)0 ||
        npu_engine_instance_valid(engine) == 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    descriptor_bytes = npu_wire_descriptor_bytes(engine);
    if (descriptor_bytes == 0u ||
        descriptor_bytes > NPU_ENGINE_DESC_MAX_BYTES ||
        (descriptor_bytes % NPU_REF_BUS_BYTES) != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    (void)memset(adapter, 0, sizeof(*adapter));
    adapter->engine = engine;
    adapter->functional_model = functional_model;
    if (limits == (const npu_wire_limits_t *)0) {
        npu_wire_limits_reference(&adapter->wire_limits);
    } else {
        adapter->wire_limits = *limits;
    }
    adapter->initialized = 1u;
    adapter->state = NPU_ENGINE_CYCLE_IDLE;
    return NPU_STATUS_SUCCESS;
}

void npu_engine_cycle_reset(npu_engine_cycle_t *adapter)
{
    npu_engine_t engine;
    npu_model_t *functional_model;
    npu_wire_limits_t wire_limits;
    uint8_t initialized;

    if (adapter == (npu_engine_cycle_t *)0) {
        return;
    }
    engine = adapter->engine;
    functional_model = adapter->functional_model;
    wire_limits = adapter->wire_limits;
    initialized = adapter->initialized;
    (void)memset(adapter, 0, sizeof(*adapter));
    adapter->engine = engine;
    adapter->functional_model = functional_model;
    adapter->wire_limits = wire_limits;
    adapter->initialized = initialized;
    adapter->state = NPU_ENGINE_CYCLE_IDLE;
}

uint8_t npu_engine_cycle_quiescent(
    const npu_engine_cycle_t *adapter)
{
    if (adapter == (const npu_engine_cycle_t *)0 ||
        adapter->initialized == 0u) {
        return 0u;
    }
    return adapter->state == NPU_ENGINE_CYCLE_IDLE &&
                   adapter->desc_outstanding == 0u &&
                   adapter->desc_req_hold_valid == 0u
               ? 1u
               : 0u;
}

static uint8_t npu_engine_find_free_tag(
    const npu_engine_cycle_t *adapter,
    uint8_t *tag)
{
    uint8_t index;

    for (index = 0u; index < NPU_ENGINE_DESC_TAGS; index++) {
        if (adapter->desc_tag[index].valid == 0u) {
            *tag = index;
            return 1u;
        }
    }
    return 0u;
}

static void npu_engine_prepare_desc_request(
    npu_engine_cycle_t *adapter)
{
    uint8_t tag;

    if (adapter->state != NPU_ENGINE_CYCLE_FETCH_DESC ||
        adapter->terminal_pending != 0u ||
        adapter->aborting != 0u ||
        adapter->canceling != 0u ||
        adapter->desc_req_hold_valid != 0u ||
        adapter->next_desc_word >= adapter->descriptor_words ||
        adapter->desc_outstanding >= NPU_ENGINE_DESC_TAGS ||
        npu_engine_find_free_tag(adapter, &tag) == 0u) {
        return;
    }
    adapter->desc_req_hold_valid = 1u;
    adapter->desc_req_hold_word = adapter->next_desc_word;
    adapter->desc_req_hold_tag = tag;
}

static void npu_engine_begin_done(npu_engine_cycle_t *adapter)
{
    uint64_t beat0;
    uint64_t beat1;

    beat0 = (uint64_t)(adapter->task_id & 0x0fffu) |
            ((uint64_t)(uint8_t)adapter->pending_status << 12) |
            ((uint64_t)adapter->pending_error_info << 20) |
            ((uint64_t)(adapter->pending_done_flags & 0x0fffu)
             << 52);
    beat1 =
        (adapter->pending_fault_addr & NPU_ENGINE_FAULT_ADDR_MASK) |
        ((uint64_t)adapter->engine << 48) |
        ((uint64_t)adapter->opcode << 52);

    adapter->done_data[0] = beat0;
    adapter->done_data[1] = beat1;
    adapter->done_data[2] = adapter->pending_progress;
    adapter->done_beat = 0u;
    adapter->state = NPU_ENGINE_CYCLE_DONE;
}

static void npu_engine_set_terminal(
    npu_engine_cycle_t *adapter,
    npu_status_t status,
    uint32_t error_info,
    uint64_t fault_addr,
    uint16_t done_flags,
    uint64_t progress)
{
    if (adapter->terminal_pending != 0u) {
        return;
    }
    adapter->terminal_pending = 1u;
    adapter->pending_status = status;
    adapter->pending_error_info = error_info;
    adapter->pending_fault_addr =
        fault_addr & NPU_ENGINE_FAULT_ADDR_MASK;
    adapter->pending_done_flags = done_flags;
    adapter->pending_progress = progress;
}

static void npu_engine_mark_abort(npu_engine_cycle_t *adapter)
{
    if (adapter->state == NPU_ENGINE_CYCLE_IDLE ||
        adapter->state == NPU_ENGINE_CYCLE_DONE ||
        adapter->aborting != 0u ||
        adapter->canceling != 0u) {
        return;
    }
    adapter->aborting = 1u;
    adapter->terminal_pending = 1u;
    adapter->pending_status = NPU_STATUS_ABORTED;
    adapter->pending_error_info = npu_engine_cycle_error_info(
        NPU_ENGINE_ERROR_ABORT, 0u,
        NPU_ENGINE_INVALID_DESC_WORD, adapter->opcode);
    adapter->pending_fault_addr = 0u;
    adapter->pending_done_flags = NPU_DONE_ABORT_DRAINED;
    adapter->pending_progress = 0u;
}

static void npu_engine_mark_cancel(
    npu_engine_cycle_t *adapter,
    uint8_t status,
    uint8_t desc_request_handshake)
{
    if (adapter->state == NPU_ENGINE_CYCLE_IDLE ||
        adapter->state == NPU_ENGINE_CYCLE_DONE ||
        adapter->terminal_pending != 0u ||
        adapter->aborting != 0u ||
        adapter->canceling != 0u ||
        npu_engine_cancel_status_valid(status) == 0u) {
        return;
    }

    adapter->canceling = 1u;
    adapter->terminal_pending = 1u;
    adapter->pending_status = (npu_status_t)status;
    adapter->pending_fault_addr = 0u;
    adapter->pending_progress = 0u;
    if (status == (uint8_t)NPU_STATUS_TIMEOUT) {
        adapter->pending_error_info = npu_engine_cycle_error_info(
            NPU_ENGINE_ERROR_EXECUTE,
            (uint16_t)(uint8_t)NPU_STATUS_TIMEOUT,
            NPU_ENGINE_INVALID_DESC_WORD, adapter->opcode);
        adapter->pending_done_flags = 0u;
    } else {
        adapter->pending_error_info = npu_engine_cycle_error_info(
            NPU_ENGINE_ERROR_ABORT, 0u,
            NPU_ENGINE_INVALID_DESC_WORD, adapter->opcode);
        adapter->pending_done_flags = NPU_DONE_ABORT_DRAINED;
    }

    /*
     * A request accepted on this edge belongs to the drain count. A held
     * request that did not handshake has not left the adapter and is
     * withdrawn by the accepted cancellation.
     */
    if (adapter->desc_req_hold_valid != 0u &&
        desc_request_handshake == 0u) {
        adapter->desc_req_hold_valid = 0u;
    }
}

static void npu_engine_start_metadata(
    npu_engine_cycle_t *adapter,
    uint64_t data)
{
    size_t descriptor_bytes;
    uint64_t reserved = data >> 44;
    uint16_t task_flags =
        (uint16_t)((data >> 28) & UINT64_C(0x0fff));
    uint8_t opcode = (uint8_t)((data >> 12) & UINT64_C(0x00ff));
    uint8_t desc_slot =
        (uint8_t)((data >> 20) & UINT64_C(0x00ff));
    uint8_t slot_count =
        adapter->functional_model->config.descriptor_slots;

    adapter->task_id = (uint16_t)(data & UINT64_C(0x0fff));
    adapter->opcode = opcode;
    adapter->desc_slot = desc_slot;
    adapter->task_flags = task_flags;
    adapter->timeout_class =
        (uint8_t)((data >> 40) & UINT64_C(0x0f));

    if (reserved != 0u) {
        npu_engine_set_terminal(
            adapter, NPU_STATUS_BAD_DESC,
            npu_engine_cycle_error_info(
                NPU_ENGINE_ERROR_METADATA,
                NPU_ENGINE_META_RESERVED,
                NPU_ENGINE_INVALID_DESC_WORD, opcode),
            0u, 0u, 0u);
        npu_engine_begin_done(adapter);
        return;
    }
    if ((task_flags & (uint16_t)~NPU_ENGINE_TASK_FLAGS_ALLOWED) != 0u) {
        npu_engine_set_terminal(
            adapter, NPU_STATUS_BAD_DESC,
            npu_engine_cycle_error_info(
                NPU_ENGINE_ERROR_METADATA,
                NPU_ENGINE_META_TASK_FLAGS,
                NPU_ENGINE_INVALID_DESC_WORD, opcode),
            0u, 0u, 0u);
        npu_engine_begin_done(adapter);
        return;
    }
    if ((task_flags & NPU_ENGINE_TASK_FLAG_DESC_CRC) != 0u) {
        npu_engine_set_terminal(
            adapter, NPU_STATUS_BAD_DESC,
            npu_engine_cycle_error_info(
                NPU_ENGINE_ERROR_METADATA,
                NPU_ENGINE_META_DESC_CRC,
                NPU_ENGINE_INVALID_DESC_WORD, opcode),
            0u, 0u, 0u);
        npu_engine_begin_done(adapter);
        return;
    }
    if (slot_count == 0u || desc_slot >= slot_count) {
        npu_engine_set_terminal(
            adapter, NPU_STATUS_BAD_DESC,
            npu_engine_cycle_error_info(
                NPU_ENGINE_ERROR_METADATA,
                NPU_ENGINE_META_DESC_SLOT,
                NPU_ENGINE_INVALID_DESC_WORD, opcode),
            0u, 0u, 0u);
        npu_engine_begin_done(adapter);
        return;
    }
    if (npu_engine_opcode_valid(adapter->engine, opcode) == 0u) {
        npu_engine_set_terminal(
            adapter, NPU_STATUS_ILLEGAL_OPCODE,
            npu_engine_cycle_error_info(
                NPU_ENGINE_ERROR_METADATA,
                NPU_ENGINE_META_OPCODE,
                NPU_ENGINE_INVALID_DESC_WORD, opcode),
            0u, 0u, 0u);
        npu_engine_begin_done(adapter);
        return;
    }

    descriptor_bytes = npu_wire_descriptor_bytes(adapter->engine);
    adapter->descriptor_bytes = (uint16_t)descriptor_bytes;
    adapter->descriptor_words =
        (uint8_t)(descriptor_bytes / NPU_REF_BUS_BYTES);
    adapter->next_desc_word = 0u;
    adapter->desc_words_received = 0u;
    adapter->state = NPU_ENGINE_CYCLE_FETCH_DESC;
}

static void npu_engine_capture_fault(
    npu_engine_cycle_t *adapter,
    npu_status_t status,
    uint64_t *fault_addr,
    uint16_t *done_flags)
{
    static const size_t address_offset[6] = {
        0x08u, 0x10u, 0x18u, 0x20u, 0x28u, 0x30u
    };
    uint64_t addr;
    size_t limit;
    uint32_t index;

    *fault_addr = 0u;
    if (status != NPU_STATUS_ADDR_FAULT &&
        status != NPU_STATUS_L1_ECC_UNCORRECTABLE) {
        return;
    }
    if (status == NPU_STATUS_L1_ECC_UNCORRECTABLE) {
        *done_flags |= NPU_DONE_FAULT_ADDR_IS_L1;
        return;
    }

    if (adapter->engine != NPU_ENGINE_DMA) {
        limit = adapter->functional_model->l1_size;
        for (index = 0u; index < 6u; index++) {
            addr = npu_engine_raw_u64(adapter->descriptor,
                                      address_offset[index]);
            if (addr >= limit) {
                *fault_addr = addr;
                *done_flags |= NPU_DONE_FAULT_ADDR_IS_L1;
                return;
            }
        }
        return;
    }

    addr = npu_engine_raw_u64(adapter->descriptor, 0x20u);
    if (adapter->descriptor[0x42u] == NPU_SPACE_L1) {
        limit = adapter->functional_model->l1_size;
        if (addr >= limit) {
            *fault_addr = addr;
            *done_flags |= NPU_DONE_FAULT_ADDR_IS_L1;
            return;
        }
    } else {
        limit = adapter->functional_model->ddr_size;
        if (addr >= limit) {
            *fault_addr = addr;
            return;
        }
    }
    addr = npu_engine_raw_u64(adapter->descriptor, 0x08u);
    if (adapter->descriptor[0x41u] == NPU_SPACE_L1) {
        limit = adapter->functional_model->l1_size;
        if (addr >= limit) {
            *fault_addr = addr;
            *done_flags |= NPU_DONE_FAULT_ADDR_IS_L1;
        }
    } else {
        limit = adapter->functional_model->ddr_size;
        if (addr >= limit) {
            *fault_addr = addr;
        }
    }
}

static void npu_engine_decode(npu_engine_cycle_t *adapter)
{
    npu_cmd_t command;
    npu_status_t status;
    uint64_t fault_addr = 0u;
    uint16_t done_flags = 0u;
    uint64_t total_cycles;

    (void)memset(&command, 0, sizeof(command));
    command.command_id = adapter->task_id;
    command.engine = adapter->engine;
    command.opcode = adapter->opcode;
    command.header_flags =
        (uint16_t)(adapter->task_flags |
                   ((uint16_t)adapter->timeout_class << 6));
    command.header_version = NPU_WIRE_HEADER_VERSION;
    command.timeout_class = adapter->timeout_class;
    command.wait_event[0] = npu_event_none();
    command.wait_event[1] = npu_event_none();
    command.signal_event = npu_event_none();

    status = npu_wire_decode_descriptor(
        &command, adapter->descriptor, adapter->descriptor_bytes,
        &adapter->wire_limits, &adapter->request,
        &adapter->wire_meta);
    if (status != NPU_STATUS_SUCCESS) {
        if (status == NPU_STATUS_ADDR_FAULT &&
            adapter->wire_meta.fault_valid != 0u) {
            fault_addr = adapter->wire_meta.fault_addr;
            if (adapter->wire_meta.fault_space == NPU_SPACE_L1) {
                done_flags |= NPU_DONE_FAULT_ADDR_IS_L1;
            }
        } else {
            npu_engine_capture_fault(adapter, status,
                                     &fault_addr, &done_flags);
        }
        npu_engine_set_terminal(
            adapter, status,
            npu_engine_cycle_error_info(
                NPU_ENGINE_ERROR_DESC_DECODE,
                (uint16_t)(uint8_t)status,
                NPU_ENGINE_INVALID_DESC_WORD, adapter->opcode),
            fault_addr, done_flags, 0u);
        npu_engine_begin_done(adapter);
        return;
    }

    total_cycles = npu_estimate_task_cycles(
        adapter->functional_model, &adapter->request);
    adapter->estimated_total_cycles = total_cycles;
    adapter->descriptor_phase_cycles =
        (uint64_t)adapter->descriptor_words +
        NPU_ENGINE_DESC_OVERHEAD_CYCLES;
    if (total_cycles > adapter->descriptor_phase_cycles) {
        adapter->execute_remaining =
            total_cycles - adapter->descriptor_phase_cycles;
    } else {
        adapter->execute_remaining = 1u;
    }
    adapter->state = NPU_ENGINE_CYCLE_EXECUTE;
}

static void npu_engine_execute(npu_engine_cycle_t *adapter)
{
    npu_status_t status;
    npu_fault_capture_t capture;
    void *previous_capture;
    uint64_t progress = 0u;
    uint64_t fault_addr = 0u;
    uint16_t done_flags = 0u;

    (void)memset(&capture, 0, sizeof(capture));
    previous_capture =
        adapter->functional_model->internal_fault_capture;
    adapter->functional_model->internal_fault_capture = &capture;
    if (adapter->engine == NPU_ENGINE_DMA) {
        status = npu_dma_execute(
            adapter->functional_model, adapter->opcode,
            &adapter->request.desc.dma, &progress);
    } else if (adapter->engine == NPU_ENGINE_MATRIX) {
        status = npu_matrix_execute(
            adapter->functional_model, adapter->opcode,
            &adapter->request.desc.matrix, &progress);
    } else if (adapter->engine == NPU_ENGINE_VECTOR) {
        status = npu_vector_execute(
            adapter->functional_model, adapter->opcode,
            &adapter->request.desc.vector, &progress);
    } else {
        status = npu_complex_execute(
            adapter->functional_model, adapter->opcode,
            &adapter->request.desc.complex, &progress);
    }
    adapter->functional_model->internal_fault_capture =
        previous_capture;

    if (status != NPU_STATUS_SUCCESS && progress != 0u) {
        done_flags |= NPU_DONE_PARTIAL_DEST;
    }
    if ((status == NPU_STATUS_ADDR_FAULT ||
         status == NPU_STATUS_L1_ECC_UNCORRECTABLE) &&
        capture.valid != 0u) {
        fault_addr = capture.addr;
        if (capture.space == NPU_SPACE_L1) {
            done_flags |= NPU_DONE_FAULT_ADDR_IS_L1;
        }
    } else {
        npu_engine_capture_fault(adapter, status,
                                 &fault_addr, &done_flags);
    }
    npu_engine_set_terminal(
        adapter, status,
        status == NPU_STATUS_SUCCESS
            ? 0u
            : npu_engine_cycle_error_info(
                  NPU_ENGINE_ERROR_EXECUTE,
                  (uint16_t)(uint8_t)status,
                  NPU_ENGINE_INVALID_DESC_WORD,
                  adapter->opcode),
        fault_addr, done_flags, progress);
    npu_engine_begin_done(adapter);
}

static void npu_engine_fill_outputs(
    const npu_engine_cycle_t *adapter,
    const npu_engine_cycle_inputs_t *inputs,
    npu_engine_cycle_outputs_t *outputs)
{
    uint8_t desc_stall;
    uint8_t done_stall;

    (void)memset(outputs, 0, sizeof(*outputs));
    outputs->cycle = adapter->cycle;
    outputs->eng_req_ready_o =
        adapter->state == NPU_ENGINE_CYCLE_IDLE &&
                inputs->eng_abort_i == 0u
            ? 1u
            : 0u;
    outputs->eng_cancel_ready_o =
        adapter->state != NPU_ENGINE_CYCLE_IDLE &&
                adapter->state != NPU_ENGINE_CYCLE_DONE &&
                adapter->terminal_pending == 0u &&
                adapter->aborting == 0u &&
                adapter->canceling == 0u &&
                npu_engine_cancel_status_valid(
                    inputs->eng_cancel_status_i) != 0u
            ? 1u
            : 0u;

    outputs->desc_rd_req_valid_o =
        adapter->desc_req_hold_valid;
    outputs->desc_rd_slot_o = adapter->desc_slot;
    outputs->desc_rd_word_o = adapter->desc_req_hold_word;
    outputs->desc_rd_req_tag_o = adapter->desc_req_hold_tag;
    outputs->desc_rd_rsp_ready_o =
        adapter->desc_outstanding != 0u ? 1u : 0u;

    if (adapter->state == NPU_ENGINE_CYCLE_DONE) {
        outputs->eng_done_valid_o = 1u;
        outputs->eng_done_data_o =
            adapter->done_data[adapter->done_beat];
        outputs->eng_done_first_o =
            adapter->done_beat == 0u ? 1u : 0u;
        outputs->eng_done_last_o =
            adapter->done_beat == 2u ? 1u : 0u;
    }

    outputs->eng_busy_o =
        adapter->state == NPU_ENGINE_CYCLE_IDLE ? 0u : 1u;
    outputs->eng_quiescent_o =
        npu_engine_cycle_quiescent(adapter);
    outputs->eng_active_o =
        adapter->state == NPU_ENGINE_CYCLE_EXECUTE ? 1u : 0u;
    desc_stall =
        outputs->desc_rd_req_valid_o != 0u &&
                inputs->desc_rd_req_ready_i == 0u
            ? 1u
            : 0u;
    done_stall =
        outputs->eng_done_valid_o != 0u &&
                inputs->eng_done_ready_i == 0u
            ? 1u
            : 0u;
    outputs->desc_stall_o = desc_stall;
    outputs->done_stall_o = done_stall;
    outputs->eng_stall_o =
        (uint8_t)(desc_stall | done_stall);
    outputs->desc_outstanding_o =
        adapter->desc_outstanding;
    outputs->desc_words_received_o =
        adapter->desc_words_received;
    outputs->ecc_corrected_o =
        adapter->ecc_corrected_pulse;
    outputs->protocol_error_o =
        adapter->protocol_error_pulse;
}

void npu_engine_cycle_eval(
    const npu_engine_cycle_t *adapter,
    const npu_engine_cycle_inputs_t *inputs,
    npu_engine_cycle_outputs_t *outputs)
{
    npu_engine_cycle_t preview;

    if (adapter == (const npu_engine_cycle_t *)0 ||
        inputs == (const npu_engine_cycle_inputs_t *)0 ||
        outputs == (npu_engine_cycle_outputs_t *)0) {
        return;
    }
    if (adapter->initialized == 0u ||
        inputs->reset_n == 0u) {
        (void)memset(outputs, 0, sizeof(*outputs));
        outputs->eng_quiescent_o =
            adapter->initialized != 0u ? 1u : 0u;
        return;
    }

    preview = *adapter;
    if (inputs->eng_abort_i != 0u) {
        npu_engine_mark_abort(&preview);
    }
    npu_engine_prepare_desc_request(&preview);
    npu_engine_fill_outputs(&preview, inputs, outputs);
}

static void npu_engine_accept_desc_response(
    npu_engine_cycle_t *adapter,
    const npu_engine_cycle_inputs_t *inputs)
{
    uint8_t tag = (uint8_t)(inputs->desc_rd_rsp_tag_i & 0x0fu);
    uint8_t word;
    uint8_t status =
        (uint8_t)(inputs->desc_rd_rsp_status_i & 0x07u);

    if (inputs->desc_rd_rsp_tag_i >= NPU_ENGINE_DESC_TAGS ||
        adapter->desc_tag[tag].valid == 0u) {
        adapter->protocol_error_pulse = 1u;
        if (adapter->aborting == 0u) {
            npu_engine_set_terminal(
                adapter, NPU_STATUS_BAD_DESC,
                npu_engine_cycle_error_info(
                    NPU_ENGINE_ERROR_DESC_PORT, status,
                    NPU_ENGINE_INVALID_DESC_WORD,
                    adapter->opcode),
                0u, 0u, 0u);
        }
        return;
    }

    word = adapter->desc_tag[tag].word;
    adapter->desc_tag[tag].valid = 0u;
    if (adapter->desc_outstanding != 0u) {
        adapter->desc_outstanding--;
    }

    if (adapter->aborting != 0u ||
        adapter->canceling != 0u ||
        adapter->terminal_pending != 0u) {
        return;
    }
    if (status == NPU_ENGINE_DESC_OK ||
        status == NPU_ENGINE_DESC_ECC_CORRECTED) {
        npu_engine_store_word(adapter->descriptor, word,
                              inputs->desc_rd_rsp_data_i);
        adapter->desc_words_received++;
        if (status == NPU_ENGINE_DESC_ECC_CORRECTED) {
            adapter->ecc_corrected_count++;
            adapter->ecc_corrected_pulse = 1u;
            adapter->functional_model->perf.ecc_corrected_count++;
        }
        return;
    }

    npu_engine_set_terminal(
        adapter, NPU_STATUS_BAD_DESC,
        npu_engine_cycle_error_info(
            NPU_ENGINE_ERROR_DESC_PORT, status,
            word, adapter->opcode),
        0u, 0u, 0u);
}

void npu_engine_cycle_step(npu_engine_cycle_t *adapter,
                           const npu_engine_cycle_inputs_t *inputs,
                           npu_engine_cycle_outputs_t *outputs)
{
    npu_engine_cycle_state_t state_at_entry;
    uint8_t task_handshake;
    uint8_t desc_request_handshake;
    uint8_t desc_response_handshake;
    uint8_t done_handshake;
    uint8_t cancel_handshake;
    uint8_t request_tag;

    if (adapter == (npu_engine_cycle_t *)0 ||
        inputs == (const npu_engine_cycle_inputs_t *)0 ||
        outputs == (npu_engine_cycle_outputs_t *)0) {
        return;
    }
    if (adapter->initialized == 0u ||
        inputs->reset_n == 0u) {
        npu_engine_cycle_reset(adapter);
        (void)memset(outputs, 0, sizeof(*outputs));
        outputs->eng_quiescent_o =
            adapter->initialized != 0u ? 1u : 0u;
        return;
    }

    state_at_entry = adapter->state;
    if (inputs->eng_abort_i != 0u) {
        npu_engine_mark_abort(adapter);
    }
    npu_engine_prepare_desc_request(adapter);
    npu_engine_fill_outputs(adapter, inputs, outputs);

    task_handshake =
        inputs->eng_req_valid_i != 0u &&
                outputs->eng_req_ready_o != 0u
            ? 1u
            : 0u;
    desc_request_handshake =
        outputs->desc_rd_req_valid_o != 0u &&
                inputs->desc_rd_req_ready_i != 0u
            ? 1u
            : 0u;
    desc_response_handshake =
        inputs->desc_rd_rsp_valid_i != 0u &&
                outputs->desc_rd_rsp_ready_o != 0u
            ? 1u
            : 0u;
    done_handshake =
        outputs->eng_done_valid_o != 0u &&
                inputs->eng_done_ready_i != 0u
            ? 1u
            : 0u;
    cancel_handshake =
        inputs->eng_cancel_valid_i != 0u &&
                outputs->eng_cancel_ready_o != 0u
            ? 1u
            : 0u;

    adapter->ecc_corrected_pulse = 0u;
    adapter->protocol_error_pulse = 0u;

    if (cancel_handshake != 0u) {
        npu_engine_mark_cancel(
            adapter, inputs->eng_cancel_status_i,
            desc_request_handshake);
    }

    if (desc_response_handshake != 0u) {
        npu_engine_accept_desc_response(adapter, inputs);
    }

    if (desc_request_handshake != 0u) {
        request_tag = adapter->desc_req_hold_tag;
        adapter->desc_tag[request_tag].valid = 1u;
        adapter->desc_tag[request_tag].word =
            adapter->desc_req_hold_word;
        adapter->desc_outstanding++;
        adapter->next_desc_word++;
        adapter->desc_req_hold_valid = 0u;
    }

    if (task_handshake != 0u) {
        npu_engine_start_metadata(adapter,
                                  inputs->eng_req_data_i);
    }

    if (state_at_entry == NPU_ENGINE_CYCLE_DONE &&
        done_handshake != 0u) {
        if (adapter->done_beat == 2u) {
            npu_engine_clear_task(adapter);
        } else {
            adapter->done_beat++;
        }
    } else if (adapter->state != NPU_ENGINE_CYCLE_DONE) {
        if ((adapter->aborting != 0u ||
             adapter->terminal_pending != 0u) &&
            adapter->desc_outstanding == 0u &&
            adapter->desc_req_hold_valid == 0u) {
            npu_engine_begin_done(adapter);
        } else if (adapter->state ==
                       NPU_ENGINE_CYCLE_FETCH_DESC &&
                   adapter->next_desc_word ==
                       adapter->descriptor_words &&
                   adapter->desc_words_received ==
                       adapter->descriptor_words &&
                   adapter->desc_outstanding == 0u &&
                   adapter->desc_req_hold_valid == 0u) {
            adapter->state = NPU_ENGINE_CYCLE_DECODE_DESC;
        }

        if (state_at_entry == NPU_ENGINE_CYCLE_DECODE_DESC &&
            adapter->state == NPU_ENGINE_CYCLE_DECODE_DESC &&
            adapter->aborting == 0u &&
            adapter->canceling == 0u &&
            adapter->terminal_pending == 0u) {
            npu_engine_decode(adapter);
        } else if (state_at_entry ==
                       NPU_ENGINE_CYCLE_EXECUTE &&
                   adapter->state ==
                       NPU_ENGINE_CYCLE_EXECUTE &&
                   adapter->aborting == 0u &&
                   adapter->canceling == 0u) {
            if (adapter->execute_remaining > 1u) {
                adapter->execute_remaining--;
            } else {
                adapter->execute_remaining = 0u;
                npu_engine_execute(adapter);
            }
        }
    }

    adapter->cycle++;
}
