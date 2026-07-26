#ifndef NPU_BUS_REPLAY_CYCLE_H
#define NPU_BUS_REPLAY_CYCLE_H

#include "npu_bus_trace.h"
#include "npu_l1_cycle.h"
#include "npu_mif_cycle.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_BUS_REPLAY_READ_PORTS 4u

typedef enum {
    NPU_BUS_REPLAY_IDLE = 0,
    NPU_BUS_REPLAY_READ_REQUEST = 1,
    NPU_BUS_REPLAY_READ_RESPONSE = 2,
    NPU_BUS_REPLAY_COMPUTE_HOLD = 3,
    NPU_BUS_REPLAY_WRITE_TRANSFER = 4,
    NPU_BUS_REPLAY_WRITE_RESPONSE = 5,
    NPU_BUS_REPLAY_DONE = 6
} npu_bus_replay_state_t;

typedef enum {
    NPU_BUS_REPLAY_LANE_IDLE = 0,
    NPU_BUS_REPLAY_LANE_REQUEST = 1,
    NPU_BUS_REPLAY_LANE_RESPONSE = 2
} npu_bus_replay_lane_state_t;

typedef struct {
    uint8_t state;
    size_t scan_index;
    size_t group_first_index;
    size_t group_last_index;
    size_t entry_index;
    uint16_t beats;
    uint16_t response_beat;
    uint16_t tag;
} npu_bus_replay_read_lane_t;

typedef struct {
    uint8_t reset_n;
    uint8_t abort;
    uint8_t abort_status;
    uint8_t done_ready;
    uint8_t compute_done;

    npu_l1_cycle_read_output_t
        l1_read[NPU_BUS_REPLAY_READ_PORTS];
    npu_l1_cycle_write_output_t l1_write;
    npu_mif_owner_outputs_t mif;
} npu_bus_replay_cycle_inputs_t;

typedef struct {
    npu_l1_cycle_read_input_t
        l1_read[NPU_BUS_REPLAY_READ_PORTS];
    npu_l1_cycle_write_input_t l1_write;
    npu_mif_owner_inputs_t mif;

    uint8_t busy;
    uint8_t quiescent;
    /*
     * compute_valid may accompany read traffic when stream_compute is
     * enabled. accepted_read_words_by_port counts only successful,
     * byte-consistent source responses and therefore acts as the operand
     * credit visible to the arithmetic scheduler.
     */
    uint8_t compute_valid;
    uint64_t accepted_read_words;
    uint64_t accepted_read_words_by_port[
        NPU_BUS_REPLAY_READ_PORTS];
    uint8_t done_valid;
    uint8_t done_status;
    uint64_t done_fault_addr;
    uint16_t done_flags;
    uint64_t done_progress;
    uint64_t confirmed_write_bytes;
    uint8_t protocol_error;
    uint64_t cycle;
} npu_bus_replay_cycle_outputs_t;

typedef struct {
    const npu_bus_trace_t *trace;
    npu_bus_replay_state_t state;

    uint16_t task_id;
    uint8_t req_attr;
    uint8_t functional_status;
    uint64_t functional_progress;
    uint8_t compute_required;
    uint8_t stream_compute;

    size_t read_index;
    size_t write_index;
    size_t read_pass_start;
    size_t read_pass_end;
    uint32_t read_pass;
    uint64_t accepted_read_words;
    uint64_t accepted_read_words_by_port[
        NPU_BUS_REPLAY_READ_PORTS];
    npu_bus_replay_read_lane_t
        l1_read_lane[NPU_BUS_REPLAY_READ_PORTS];
    npu_bus_replay_read_lane_t mif_read_lane;
    uint16_t current_tag;
    uint8_t write_request_sent;
    uint8_t write_data_sent;
    uint16_t write_group_beats;
    uint16_t write_data_beat;
    uint8_t aborting;
    uint8_t abort_status;

    uint8_t terminal_locked;
    uint8_t terminal_status;
    uint64_t terminal_fault_addr;
    uint16_t terminal_done_flags;

    uint8_t done_status;
    uint64_t done_fault_addr;
    uint16_t done_flags;
    uint64_t done_progress;
    uint64_t confirmed_write_bytes;
    uint8_t protocol_error_pulse;

    uint64_t cycle;
} npu_bus_replay_cycle_t;

void npu_bus_replay_cycle_reset(
    npu_bus_replay_cycle_t *replay);

/*
 * Starts replay of one completed functional access trace. The trace arrays
 * must remain valid and unchanged until done_valid is accepted.
 * A zero entry count permits a null array pointer. Nonzero counts must not
 * exceed their capacities, and every entry must describe an aligned,
 * strobed L1 or DDR word. A rejected start leaves the replay object
 * unchanged.
 *
 * The functional operator has already calculated its result when replay
 * starts. Read response data is checked byte for byte against the captured
 * value on every asserted strobe; it is not supplied to the operator for a
 * second calculation. A difference reports an interface consistency error.
 *
 * When compute_required is nonzero, compute_valid is asserted after every
 * source response has transferred and before any destination request or data
 * is presented. The replay remains in that state until compute_done is high
 * for one step. This handshake lets an engine expose a deterministic
 * arithmetic interval even though the functional result was calculated
 * atomically while the trace was captured.
 */
int npu_bus_replay_cycle_start(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_trace_t *trace,
    uint16_t task_id,
    uint8_t req_attr,
    npu_status_t functional_status,
    uint64_t functional_progress,
    uint8_t compute_required);

/*
 * Extended start operation used by arithmetic engines. stream_compute lets
 * compute_valid accompany source-read traffic after at least one verified
 * response. The caller must use the per-port accepted-word counters to
 * decide whether a complete operand group is ready. Destination traffic
 * still starts only after every source response has drained and
 * compute_done has been observed.
 */
int npu_bus_replay_cycle_start_stream(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_trace_t *trace,
    uint16_t task_id,
    uint8_t req_attr,
    npu_status_t functional_status,
    uint64_t functional_progress,
    uint8_t compute_required,
    uint8_t stream_compute);

/*
 * One call models one rising Core clock edge. Each L1 read port and the MIF
 * read interface may hold one independent burst request. Requests belonging
 * to the same read pass may proceed concurrently. A later read pass starts
 * only after every accepted request from the current pass has drained.
 * Contiguous L1 transfers use up to 256 beats; contiguous MIF transfers use
 * up to 16 beats. All valid payloads remain stable during a ready pause.
 */
void npu_bus_replay_cycle_step(
    npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_cycle_inputs_t *inputs,
    npu_bus_replay_cycle_outputs_t *outputs);

void npu_bus_replay_cycle_eval(
    const npu_bus_replay_cycle_t *replay,
    const npu_bus_replay_cycle_inputs_t *inputs,
    npu_bus_replay_cycle_outputs_t *outputs);

#ifdef __cplusplus
}
#endif

#endif
