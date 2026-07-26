#include "npu_l1_cycle.h"

#include <string.h>

#define NPU_L1_CANDIDATE_COUNT \
    (NPU_L1_READ_PORT_COUNT + NPU_L1_WRITE_PORT_COUNT)

typedef enum {
    NPU_L1_CANDIDATE_READ = 0,
    NPU_L1_CANDIDATE_WRITE = 1
} npu_l1_candidate_kind_t;

typedef struct {
    uint8_t valid;
    uint8_t blocked;
    uint8_t selected;
    npu_l1_candidate_kind_t kind;
    uint8_t port;
    uint32_t addr;
    uint32_t priority;
    uint32_t wait_cycles;
} npu_l1_candidate_t;

static uint32_t npu_l1_read_priority(uint32_t port)
{
    switch (port) {
    case NPU_L1_RD_ME_A:
        return 2u;
    case NPU_L1_RD_ME_B:
        return 3u;
    case NPU_L1_RD_ME_AUX:
        return 4u;
    case NPU_L1_RD_IVE_SRC0:
        return 6u;
    case NPU_L1_RD_IVE_SRC1:
        return 7u;
    case NPU_L1_RD_IVE_SRC2:
        return 8u;
    case NPU_L1_RD_IVE_MASK:
        return 9u;
    case NPU_L1_RD_CME_SRC0:
        return 10u;
    case NPU_L1_RD_CME_SRC1:
        return 11u;
    case NPU_L1_RD_CME_SRC2:
        return 12u;
    case NPU_L1_RD_CME_MASK:
        return 13u;
    case NPU_L1_RD_DMA:
        return 15u;
    case NPU_L1_RD_DEBUG:
        return 17u;
    default:
        return UINT32_MAX;
    }
}

static uint32_t npu_l1_write_priority(uint32_t port)
{
    switch (port) {
    case NPU_L1_WR_ME_C:
        return 0u;
    case NPU_L1_WR_CME_DST:
        return 1u;
    case NPU_L1_WR_IVE_DST:
        return 5u;
    case NPU_L1_WR_DMA:
        return 14u;
    case NPU_L1_WR_DEBUG:
        return 16u;
    default:
        return UINT32_MAX;
    }
}

static uint32_t npu_l1_bank(uint32_t addr)
{
    return (addr / NPU_L1_CYCLE_WORD_BYTES) %
           NPU_L1_CYCLE_BANKS;
}

static void npu_l1_clear_ecc_error(npu_l1_cycle_t *controller)
{
    controller->ecc_error_valid = 0u;
    controller->ecc_error_status = 0u;
    controller->ecc_error_addr = 0u;
    controller->ecc_error_port = 0u;
    controller->ecc_error_bank = 0u;
    controller->ecc_error_write = 0u;
}

static void npu_l1_record_ecc_error(npu_l1_cycle_t *controller,
                                    uint8_t status,
                                    uint32_t addr,
                                    uint8_t port,
                                    uint8_t write)
{
    if (controller->ecc_error_valid != 0u) {
        return;
    }
    controller->ecc_error_valid = 1u;
    controller->ecc_error_status = status;
    controller->ecc_error_addr = addr;
    controller->ecc_error_port = port;
    controller->ecc_error_bank = (uint8_t)npu_l1_bank(addr);
    controller->ecc_error_write = write;
}

static uint32_t npu_l1_increment_wait(uint32_t value)
{
    return value == UINT32_MAX ? value : value + 1u;
}

static uint8_t npu_l1_request_status(
    const npu_l1_cycle_t *controller,
    const npu_l1_cycle_inputs_t *inputs,
    uint32_t addr,
    uint16_t total_beats,
    uint16_t tag,
    uint32_t write_port)
{
    uint64_t end;

    if ((tag & (uint16_t)(~NPU_L1_CYCLE_TAG_MASK)) != 0u ||
        (addr & (NPU_L1_CYCLE_WORD_BYTES - 1u)) != 0u) {
        return (uint8_t)NPU_L1_STATUS_PORT_PROTOCOL_ERROR;
    }
    end = (uint64_t)addr +
          (uint64_t)total_beats * NPU_L1_CYCLE_WORD_BYTES;
    if (end > controller->memory_bytes) {
        return (uint8_t)NPU_L1_STATUS_ADDR_FAULT;
    }
    if (write_port < NPU_L1_WRITE_PORT_COUNT &&
        (uint64_t)addr < inputs->param_l1_limit &&
        end > inputs->param_l1_base) {
        if (inputs->param_lock != 0u ||
            (inputs->param_write_allow_mask &
             (uint8_t)(1u << write_port)) == 0u) {
            return (uint8_t)NPU_L1_STATUS_ADDR_FAULT;
        }
    }
    return (uint8_t)NPU_L1_STATUS_OK;
}

static uint64_t npu_l1_load_word(const uint8_t *memory,
                                 uint32_t addr)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < NPU_L1_CYCLE_WORD_BYTES; byte++) {
        value |= (uint64_t)memory[addr + byte] << (byte * 8u);
    }
    return value;
}

static void npu_l1_store_word(uint8_t *memory,
                              uint32_t addr,
                              uint64_t value,
                              uint8_t strb)
{
    uint32_t byte;

    for (byte = 0u; byte < NPU_L1_CYCLE_WORD_BYTES; byte++) {
        if ((strb & (uint8_t)(1u << byte)) != 0u) {
            memory[addr + byte] =
                (uint8_t)(value >> (byte * 8u));
        }
    }
}

static int npu_l1_candidate_better(
    const npu_l1_candidate_t *candidate,
    const npu_l1_candidate_t *current)
{
    uint8_t candidate_promoted =
        candidate->wait_cycles >= NPU_L1_CYCLE_STARVE_LIMIT;
    uint8_t current_promoted =
        current->wait_cycles >= NPU_L1_CYCLE_STARVE_LIMIT;

    if (candidate_promoted != current_promoted) {
        return candidate_promoted != 0u;
    }
    if (candidate_promoted != 0u &&
        candidate->wait_cycles != current->wait_cycles) {
        return candidate->wait_cycles > current->wait_cycles;
    }
    if (candidate->priority != current->priority) {
        return candidate->priority < current->priority;
    }
    if (candidate->kind != current->kind) {
        return candidate->kind == NPU_L1_CANDIDATE_WRITE;
    }
    return candidate->port < current->port;
}

static void npu_l1_add_candidate(
    npu_l1_candidate_t *candidates,
    uint32_t *candidate_count,
    int *port_index,
    npu_l1_candidate_kind_t kind,
    uint32_t port,
    uint32_t addr,
    uint32_t priority,
    uint32_t wait_cycles)
{
    uint32_t index = *candidate_count;

    if (index >= NPU_L1_CANDIDATE_COUNT) {
        return;
    }
    candidates[index].valid = 1u;
    candidates[index].blocked = 0u;
    candidates[index].selected = 0u;
    candidates[index].kind = kind;
    candidates[index].port = (uint8_t)port;
    candidates[index].addr = addr;
    candidates[index].priority = priority;
    candidates[index].wait_cycles = wait_cycles;
    port_index[port] = (int)index;
    *candidate_count = index + 1u;
}

static uint8_t npu_l1_pipe_can_accept(
    const npu_l1_cycle_t *controller,
    const npu_l1_cycle_inputs_t *inputs,
    uint32_t port)
{
    const npu_l1_cycle_read_pipe_t *stage0 =
        &controller->read_pipe[port][0];
    const npu_l1_cycle_read_pipe_t *stage1 =
        &controller->read_pipe[port][1];
    uint8_t stage0_will_be_free =
        stage0->valid == 0u ||
        (stage0->valid != 0u &&
         inputs->read[port].rsp_ready != 0u);

    return stage1->valid == 0u || stage0_will_be_free != 0u;
}

static uint8_t npu_l1_read_request_slot_free(
    const npu_l1_cycle_t *controller,
    uint32_t port)
{
    uint32_t stage;

    if (controller->read_state[port].active != 0u) {
        return 0u;
    }
    for (stage = 0u;
         stage < NPU_L1_CYCLE_READ_LATENCY;
         stage++) {
        if (controller->read_pipe[port][stage].valid != 0u) {
            return 0u;
        }
    }
    return 1u;
}

static void npu_l1_make_read_payload(
    npu_l1_cycle_t *controller,
    uint32_t port,
    npu_l1_cycle_read_pipe_t *payload)
{
    npu_l1_cycle_read_state_t *state =
        &controller->read_state[port];
    uint32_t addr =
        state->base_addr +
        (uint32_t)state->issued_beats *
            NPU_L1_CYCLE_WORD_BYTES;
    uint8_t status = state->request_status;

    payload->valid = 1u;
    payload->data = 0u;
    payload->tag = state->tag;
    payload->last =
        state->issued_beats + 1u == state->total_beats;
    payload->ecc_event_pending = 0u;
    if (status == NPU_L1_STATUS_OK) {
        status = controller->ecc_status[
            addr / NPU_L1_CYCLE_WORD_BYTES];
        if (status != NPU_L1_STATUS_OK &&
            status != NPU_L1_STATUS_ECC_CORRECTED &&
            status != NPU_L1_STATUS_ECC_UNCORRECTABLE) {
            status = (uint8_t)NPU_L1_STATUS_PORT_PROTOCOL_ERROR;
        }
        payload->data = npu_l1_load_word(controller->memory,
                                         addr);
        if (status == NPU_L1_STATUS_ECC_CORRECTED) {
            controller->ecc_corrected_count++;
            payload->ecc_event_pending = 1u;
        } else if (status ==
                   NPU_L1_STATUS_ECC_UNCORRECTABLE) {
            controller->ecc_uncorrectable_count++;
            payload->ecc_event_pending = 1u;
            npu_l1_record_ecc_error(
                controller, status, addr, (uint8_t)port, 0u);
        }
    }
    payload->status = status;
    state->issued_beats++;
}

static void npu_l1_finish_write(
    npu_l1_cycle_write_state_t *state,
    uint8_t status)
{
    state->active = 0u;
    state->wait_cycles = 0u;
    state->completion_pending = 1u;
    state->completion_tag = state->tag;
    state->completion_status = status;
}

int npu_l1_cycle_init(npu_l1_cycle_t *controller,
                      uint8_t *memory,
                      size_t memory_bytes,
                      uint8_t *ecc_status,
                      size_t ecc_status_bytes)
{
    size_t index;

    if (controller == (npu_l1_cycle_t *)0 ||
        memory == (uint8_t *)0 ||
        ecc_status == (uint8_t *)0 ||
        memory_bytes != NPU_L1_CYCLE_BYTES ||
        ecc_status_bytes < NPU_L1_CYCLE_WORDS) {
        return -1;
    }
    (void)memset(controller, 0, sizeof(*controller));
    controller->memory = memory;
    controller->ecc_status = ecc_status;
    controller->memory_bytes = memory_bytes;
    for (index = 0u; index < NPU_L1_CYCLE_WORDS; index++) {
        ecc_status[index] = (uint8_t)NPU_L1_STATUS_OK;
    }
    npu_l1_cycle_reset(controller);
    return 0;
}

void npu_l1_cycle_reset(npu_l1_cycle_t *controller)
{
    if (controller == (npu_l1_cycle_t *)0) {
        return;
    }
    (void)memset(controller->read_state, 0,
                 sizeof(controller->read_state));
    (void)memset(controller->read_pipe, 0,
                 sizeof(controller->read_pipe));
    (void)memset(controller->write_state, 0,
                 sizeof(controller->write_state));
    controller->cycle = 0u;
    controller->ecc_corrected_count = 0u;
    controller->ecc_uncorrectable_count = 0u;
    npu_l1_clear_ecc_error(controller);
}

int npu_l1_cycle_inject_ecc(npu_l1_cycle_t *controller,
                            uint32_t aligned_addr,
                            npu_l1_cycle_status_t status)
{
    if (controller == (npu_l1_cycle_t *)0 ||
        controller->ecc_status == (uint8_t *)0 ||
        (aligned_addr &
         (NPU_L1_CYCLE_WORD_BYTES - 1u)) != 0u ||
        aligned_addr >= controller->memory_bytes ||
        (status != NPU_L1_STATUS_OK &&
         status != NPU_L1_STATUS_ECC_CORRECTED &&
         status != NPU_L1_STATUS_ECC_UNCORRECTABLE)) {
        return -1;
    }
    controller->ecc_status[
        aligned_addr / NPU_L1_CYCLE_WORD_BYTES] =
        (uint8_t)status;
    return 0;
}

uint8_t npu_l1_cycle_idle(const npu_l1_cycle_t *controller)
{
    uint32_t port;
    uint32_t stage;

    if (controller == (const npu_l1_cycle_t *)0) {
        return 0u;
    }
    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        if (controller->read_state[port].active != 0u) {
            return 0u;
        }
        for (stage = 0u;
             stage < NPU_L1_CYCLE_READ_LATENCY;
             stage++) {
            if (controller->read_pipe[port][stage].valid != 0u) {
                return 0u;
            }
        }
    }
    for (port = 0u; port < NPU_L1_WRITE_PORT_COUNT; port++) {
        const npu_l1_cycle_write_state_t *state =
            &controller->write_state[port];
        if (state->active != 0u ||
            state->completion_pending != 0u ||
            state->response_valid != 0u ||
            state->data_buffer_valid != 0u) {
            return 0u;
        }
    }
    return 1u;
}

static uint8_t npu_l1_cycle_write_idle(
    const npu_l1_cycle_t *controller)
{
    uint32_t port;

    if (controller == (const npu_l1_cycle_t *)0) {
        return 0u;
    }
    for (port = 0u; port < NPU_L1_WRITE_PORT_COUNT; port++) {
        const npu_l1_cycle_write_state_t *state =
            &controller->write_state[port];

        if (state->active != 0u ||
            state->completion_pending != 0u ||
            state->response_valid != 0u ||
            state->data_buffer_valid != 0u) {
            return 0u;
        }
    }
    return 1u;
}

void npu_l1_cycle_step(npu_l1_cycle_t *controller,
                       const npu_l1_cycle_inputs_t *inputs,
                       npu_l1_cycle_outputs_t *outputs)
{
    npu_l1_candidate_t candidates[NPU_L1_CANDIDATE_COUNT];
    npu_l1_cycle_read_pipe_t
        new_read_payload[NPU_L1_READ_PORT_COUNT];
    int read_candidate[NPU_L1_READ_PORT_COUNT];
    int write_candidate[NPU_L1_WRITE_PORT_COUNT];
    uint8_t direct_read[NPU_L1_READ_PORT_COUNT];
    uint8_t
        read_request_handshake[NPU_L1_READ_PORT_COUNT];
    uint8_t direct_write[NPU_L1_WRITE_PORT_COUNT];
    uint8_t consume_write[NPU_L1_WRITE_PORT_COUNT];
    uint8_t write_beat_from_buffer[NPU_L1_WRITE_PORT_COUNT];
    uint8_t write_active_before[NPU_L1_WRITE_PORT_COUNT];
    uint8_t completion_before[NPU_L1_WRITE_PORT_COUNT];
    uint32_t candidate_count = 0u;
    uint32_t port;
    uint32_t index;
    uint32_t bank;

    if (controller == (npu_l1_cycle_t *)0 ||
        inputs == (const npu_l1_cycle_inputs_t *)0 ||
        outputs == (npu_l1_cycle_outputs_t *)0) {
        return;
    }
    if (inputs->reset_n == 0u) {
        npu_l1_cycle_reset(controller);
        (void)memset(outputs, 0, sizeof(*outputs));
        outputs->idle = 1u;
        outputs->write_idle = 1u;
        return;
    }

    (void)memset(outputs, 0, sizeof(*outputs));
    (void)memset(candidates, 0, sizeof(candidates));
    (void)memset(new_read_payload, 0,
                 sizeof(new_read_payload));
    (void)memset(direct_read, 0, sizeof(direct_read));
    (void)memset(read_request_handshake, 0,
                 sizeof(read_request_handshake));
    (void)memset(direct_write, 0, sizeof(direct_write));
    (void)memset(consume_write, 0, sizeof(consume_write));
    (void)memset(write_beat_from_buffer, 0,
                 sizeof(write_beat_from_buffer));

    outputs->cycle = controller->cycle;
    outputs->idle = npu_l1_cycle_idle(controller);
    outputs->write_idle =
        npu_l1_cycle_write_idle(controller);
    outputs->ecc_error_valid = controller->ecc_error_valid;
    outputs->ecc_error_status = controller->ecc_error_status;
    outputs->ecc_error_addr = controller->ecc_error_addr;
    outputs->ecc_error_port = controller->ecc_error_port;
    outputs->ecc_error_bank = controller->ecc_error_bank;
    outputs->ecc_error_write = controller->ecc_error_write;
    if (inputs->error_clear != 0u) {
        npu_l1_clear_ecc_error(controller);
    }

    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        npu_l1_cycle_read_pipe_t *response =
            &controller->read_pipe[port][0];

        read_candidate[port] = -1;
        outputs->read[port].req_ready =
            npu_l1_read_request_slot_free(
                controller, port);
        read_request_handshake[port] =
            outputs->read[port].req_ready != 0u &&
                    inputs->read[port].req_valid != 0u
                ? 1u
                : 0u;
        outputs->read[port].rsp_valid = response->valid;
        if (response->valid != 0u) {
            outputs->read[port].rsp_data = response->data;
            outputs->read[port].rsp_tag = response->tag;
            outputs->read[port].rsp_last = response->last;
            outputs->read[port].rsp_status = response->status;
            if (response->ecc_event_pending != 0u) {
                if (response->status ==
                    NPU_L1_STATUS_ECC_CORRECTED) {
                    outputs->ecc_corrected_pulse = 1u;
                    outputs->ecc_corrected_events++;
                } else if (response->status ==
                           NPU_L1_STATUS_ECC_UNCORRECTABLE) {
                    outputs->ecc_uncorrectable_pulse = 1u;
                    outputs->ecc_uncorrectable_events++;
                }
                response->ecc_event_pending = 0u;
            }
        }
    }

    for (port = 0u; port < NPU_L1_WRITE_PORT_COUNT; port++) {
        npu_l1_cycle_write_state_t *state =
            &controller->write_state[port];

        write_candidate[port] = -1;
        write_active_before[port] = state->active;
        write_beat_from_buffer[port] =
            state->data_buffer_valid;
        completion_before[port] = state->completion_pending;
        outputs->write[port].req_ready =
            state->active == 0u &&
            state->completion_pending == 0u &&
            state->response_valid == 0u;
        outputs->write[port].rsp_valid =
            state->response_valid;
        if (state->response_valid != 0u) {
            outputs->write[port].rsp_tag =
                state->response_tag;
            outputs->write[port].rsp_status =
                state->response_status;
        }
    }

    /*
     * Build one SRAM-operation candidate per port. Invalid reads and writes
     * do not consume a bank; they are drained through direct_* below.
     */
    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        npu_l1_cycle_read_state_t *state =
            &controller->read_state[port];
        uint8_t pipe_available =
            npu_l1_pipe_can_accept(controller, inputs, port);

        if (state->active != 0u &&
            state->issued_beats < state->total_beats &&
            pipe_available != 0u) {
            if (state->request_status != NPU_L1_STATUS_OK) {
                direct_read[port] = 1u;
            } else {
                uint32_t addr =
                    state->base_addr +
                    (uint32_t)state->issued_beats *
                        NPU_L1_CYCLE_WORD_BYTES;
                npu_l1_add_candidate(
                    candidates, &candidate_count,
                    read_candidate,
                    NPU_L1_CANDIDATE_READ,
                    port, addr,
                    npu_l1_read_priority(port),
                    state->wait_cycles);
            }
        } else if (read_request_handshake[port] != 0u &&
                   pipe_available != 0u) {
            uint16_t total_beats =
                (uint16_t)inputs->read[port].req_beats + 1u;
            uint8_t status = npu_l1_request_status(
                controller, inputs,
                inputs->read[port].req_addr,
                total_beats,
                inputs->read[port].req_tag,
                NPU_L1_WRITE_PORT_COUNT);

            if (status != NPU_L1_STATUS_OK) {
                direct_read[port] = 1u;
            } else {
                npu_l1_add_candidate(
                    candidates, &candidate_count,
                    read_candidate,
                    NPU_L1_CANDIDATE_READ,
                    port,
                    inputs->read[port].req_addr,
                    npu_l1_read_priority(port),
                    state->wait_cycles);
            }
        }
    }

    for (port = 0u; port < NPU_L1_WRITE_PORT_COUNT; port++) {
        npu_l1_cycle_write_state_t *state =
            &controller->write_state[port];

        /*
         * An empty slot is ready without consulting data_valid. Its
         * fall-through path may still use a valid input beat in this cycle.
         */
        if (state->active != 0u &&
            state->data_buffer_valid == 0u) {
            outputs->write[port].data_ready = 1u;
        }

        if (state->active != 0u &&
            (state->data_buffer_valid != 0u ||
             inputs->write[port].data_valid != 0u)) {
            if (state->request_status != NPU_L1_STATUS_OK) {
                direct_write[port] = 1u;
            } else {
                uint32_t addr =
                    state->base_addr +
                    (uint32_t)state->accepted_beats *
                        NPU_L1_CYCLE_WORD_BYTES;
                npu_l1_add_candidate(
                    candidates, &candidate_count,
                    write_candidate,
                    NPU_L1_CANDIDATE_WRITE,
                    port, addr,
                    npu_l1_write_priority(port),
                    state->wait_cycles);
            }
        }
    }

    /*
     * A write candidate blocks a read of the same word even when the read
     * has a better normal priority or has reached the starvation threshold.
     */
    for (index = 0u; index < candidate_count; index++) {
        uint32_t other;

        if (candidates[index].kind !=
            NPU_L1_CANDIDATE_READ) {
            continue;
        }
        for (other = 0u; other < candidate_count; other++) {
            if (candidates[other].kind ==
                    NPU_L1_CANDIDATE_WRITE &&
                candidates[other].addr ==
                    candidates[index].addr) {
                candidates[index].blocked = 1u;
                break;
            }
        }
    }

    for (bank = 0u; bank < NPU_L1_CYCLE_BANKS; bank++) {
        int best = -1;

        for (index = 0u; index < candidate_count; index++) {
            if (candidates[index].valid == 0u ||
                candidates[index].blocked != 0u ||
                npu_l1_bank(candidates[index].addr) != bank) {
                continue;
            }
            if (best < 0 ||
                npu_l1_candidate_better(
                    &candidates[index],
                    &candidates[(uint32_t)best]) != 0) {
                best = (int)index;
            }
        }
        if (best >= 0) {
            candidates[(uint32_t)best].selected = 1u;
        }
    }

    for (index = 0u; index < candidate_count; index++) {
        npu_l1_candidate_t *candidate = &candidates[index];

        if (candidate->kind == NPU_L1_CANDIDATE_READ) {
            npu_l1_cycle_read_state_t *state =
                &controller->read_state[candidate->port];
            if (candidate->selected != 0u) {
                state->wait_cycles = 0u;
            } else {
                outputs->bank_stall = 1u;
                outputs->read_bank_stall_mask |=
                    (uint16_t)(1u << candidate->port);
                state->wait_cycles =
                    npu_l1_increment_wait(state->wait_cycles);
            }
        } else {
            npu_l1_cycle_write_state_t *state =
                &controller->write_state[candidate->port];
            if (candidate->selected != 0u) {
                state->wait_cycles = 0u;
            } else {
                outputs->bank_stall = 1u;
                outputs->write_bank_stall_mask |=
                    (uint8_t)(1u << candidate->port);
                state->wait_cycles =
                    npu_l1_increment_wait(state->wait_cycles);
            }
        }
    }

    /*
     * A buffered beat may be replaced in the cycle in which it reaches
     * SRAM, except when that beat ends the request or reports an early last.
     * This preserves one beat per cycle after the slot has been filled.
     */
    for (port = 0u; port < NPU_L1_WRITE_PORT_COUNT; port++) {
        npu_l1_cycle_write_state_t *state =
            &controller->write_state[port];
        uint8_t selected =
            write_candidate[port] >= 0 &&
            candidates[(uint32_t)write_candidate[port]]
                    .selected != 0u;

        consume_write[port] =
            (uint8_t)(direct_write[port] != 0u ||
                      selected != 0u);
        if (state->active != 0u &&
            state->data_buffer_valid != 0u &&
            consume_write[port] != 0u &&
            state->accepted_beats + 1u <
                state->total_beats &&
            state->last_buffer == 0u) {
            outputs->write[port].data_ready = 1u;
        }
    }

    for (port = 0u; port < NPU_L1_READ_PORT_COUNT; port++) {
        npu_l1_cycle_read_state_t *state =
            &controller->read_state[port];
        npu_l1_cycle_read_pipe_t *stage0 =
            &controller->read_pipe[port][0];
        npu_l1_cycle_read_pipe_t *stage1 =
            &controller->read_pipe[port][1];
        uint8_t response_handshake =
            stage0->valid != 0u &&
            inputs->read[port].rsp_ready != 0u;
        uint8_t issue =
            direct_read[port] != 0u ||
            (read_candidate[port] >= 0 &&
             candidates[(uint32_t)read_candidate[port]]
                     .selected != 0u);
        uint8_t new_request =
            read_request_handshake[port];

        if (response_handshake != 0u) {
            state->retired_beats++;
            if (state->retired_beats >= state->total_beats) {
                state->active = 0u;
                state->wait_cycles = 0u;
            }
            stage0->valid = 0u;
        }

        if (new_request != 0u) {
            uint16_t total_beats =
                (uint16_t)inputs->read[port].req_beats + 1u;

            state->active = 1u;
            state->request_status = npu_l1_request_status(
                controller, inputs,
                inputs->read[port].req_addr,
                total_beats,
                inputs->read[port].req_tag,
                NPU_L1_WRITE_PORT_COUNT);
            state->tag =
                inputs->read[port].req_tag &
                NPU_L1_CYCLE_TAG_MASK;
            state->total_beats = total_beats;
            state->issued_beats = 0u;
            state->retired_beats = 0u;
            state->base_addr = inputs->read[port].req_addr;
            state->wait_cycles = 0u;
        }

        if (issue != 0u) {
            npu_l1_make_read_payload(
                controller, port, &new_read_payload[port]);
        }

        if (stage0->valid == 0u && stage1->valid != 0u) {
            *stage0 = *stage1;
            stage1->valid = 0u;
        }
        if (new_read_payload[port].valid != 0u) {
            *stage1 = new_read_payload[port];
        }

        if (read_candidate[port] < 0 &&
            direct_read[port] == 0u) {
            if (state->active == 0u &&
                inputs->read[port].req_valid == 0u) {
                state->wait_cycles = 0u;
            } else if (state->active != 0u &&
                       state->issued_beats >=
                           state->total_beats) {
                state->wait_cycles = 0u;
            }
        }
    }

    /*
     * Retire an existing response and move a completion that was already
     * pending at cycle start. A completion created below is therefore
     * visible exactly two cycles after its final data handshake.
     */
    for (port = 0u; port < NPU_L1_WRITE_PORT_COUNT; port++) {
        npu_l1_cycle_write_state_t *state =
            &controller->write_state[port];

        if (state->response_valid != 0u &&
            inputs->write[port].rsp_ready != 0u) {
            state->response_valid = 0u;
        }
        if (completion_before[port] != 0u &&
            state->response_valid == 0u) {
            state->response_valid = 1u;
            state->response_tag = state->completion_tag;
            state->response_status = state->completion_status;
            state->completion_pending = 0u;
        }
    }

    /*
     * Accept new write requests. Data is intentionally not accepted in the
     * same cycle as its request, matching the request/data phase ordering.
     */
    for (port = 0u; port < NPU_L1_WRITE_PORT_COUNT; port++) {
        npu_l1_cycle_write_state_t *state =
            &controller->write_state[port];

        if (outputs->write[port].req_ready != 0u &&
            inputs->write[port].req_valid != 0u) {
            uint16_t total_beats =
                (uint16_t)inputs->write[port].req_beats + 1u;

            state->active = 1u;
            state->request_status = npu_l1_request_status(
                controller, inputs,
                inputs->write[port].req_addr,
                total_beats,
                inputs->write[port].req_tag,
                port);
            state->tag =
                inputs->write[port].req_tag &
                NPU_L1_CYCLE_TAG_MASK;
            state->total_beats = total_beats;
            state->accepted_beats = 0u;
            state->base_addr = inputs->write[port].req_addr;
            state->wait_cycles = 0u;
        }
    }

    for (port = 0u; port < NPU_L1_WRITE_PORT_COUNT; port++) {
        npu_l1_cycle_write_state_t *state =
            &controller->write_state[port];
        uint8_t data_handshake =
            write_active_before[port] != 0u &&
            inputs->write[port].data_valid != 0u &&
            outputs->write[port].data_ready != 0u;
        uint8_t beat_valid =
            write_active_before[port] != 0u &&
            (write_beat_from_buffer[port] != 0u ||
             data_handshake != 0u);

        if (consume_write[port] != 0u &&
            beat_valid != 0u) {
            uint32_t addr =
                state->base_addr +
                (uint32_t)state->accepted_beats *
                    NPU_L1_CYCLE_WORD_BYTES;
            uint8_t status = state->request_status;
            uint8_t expected_last =
                state->accepted_beats + 1u ==
                state->total_beats;
            uint64_t beat_data =
                write_beat_from_buffer[port] != 0u
                    ? state->data_buffer
                    : inputs->write[port].data;
            uint8_t beat_strb =
                write_beat_from_buffer[port] != 0u
                    ? state->strb_buffer
                    : inputs->write[port].strb;
            uint8_t beat_last =
                write_beat_from_buffer[port] != 0u
                    ? state->last_buffer
                    : inputs->write[port].last;

            if (status == NPU_L1_STATUS_OK) {
                npu_l1_store_word(
                    controller->memory, addr,
                    beat_data, beat_strb);
                if (beat_strb != 0u) {
                    controller->ecc_status[
                        addr / NPU_L1_CYCLE_WORD_BYTES] =
                        (uint8_t)NPU_L1_STATUS_OK;
                }
            }
            state->accepted_beats++;
            if ((beat_last != 0u) !=
                (expected_last != 0u)) {
                status =
                    (uint8_t)NPU_L1_STATUS_PORT_PROTOCOL_ERROR;
                npu_l1_finish_write(state, status);
            } else if (expected_last != 0u) {
                npu_l1_finish_write(state, status);
            }
            state->data_buffer_valid = 0u;
        }

        /*
         * Capture an incoming beat only when it was not the beat consumed
         * through the empty-slot fall-through path.
         */
        if (data_handshake != 0u &&
            !(write_beat_from_buffer[port] == 0u &&
              consume_write[port] != 0u)) {
            state->data_buffer_valid = 1u;
            state->data_buffer = inputs->write[port].data;
            state->strb_buffer = inputs->write[port].strb;
            state->last_buffer = inputs->write[port].last;
        }

        if (write_candidate[port] < 0 &&
            direct_write[port] == 0u &&
            (state->active == 0u ||
             (state->data_buffer_valid == 0u &&
              inputs->write[port].data_valid == 0u))) {
            state->wait_cycles = 0u;
        }
    }

    controller->cycle++;
}
