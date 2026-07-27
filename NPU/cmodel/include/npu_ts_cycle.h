#ifndef NPU_TS_CYCLE_H
#define NPU_TS_CYCLE_H

#include "npu_wire.h"

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_TS_TASK_COUNT 32u
#define NPU_TS_DESC_SLOT_COUNT 32u
#define NPU_TS_DESC_BYTES 256u
#define NPU_TS_DESC_WORDS 32u
#define NPU_TS_EVENT_COUNT 255u
#define NPU_TS_ENGINE_COUNT 4u
#define NPU_TS_DESC_TAG_COUNT 16u
#define NPU_TS_INVALID_INDEX 0xffu
#define NPU_TS_EVENT_NONE 0x0fffu

#define NPU_TS_FLAG_IRQ_ON_SUCCESS (1u << 0)
#define NPU_TS_FLAG_IRQ_ON_ERROR (1u << 1)
#define NPU_TS_FLAG_ORDERED (1u << 4)
#define NPU_TS_FLAG_DESC_CRC_ENABLE (1u << 5)

typedef enum {
    NPU_TS_TASK_FREE = 0,
    NPU_TS_TASK_CMD_HALF = 1,
    NPU_TS_TASK_ACCEPTED = 2,
    NPU_TS_TASK_FETCH_DESC = 3,
    NPU_TS_TASK_CHECK_DESC = 4,
    NPU_TS_TASK_WAIT_EVENT = 5,
    NPU_TS_TASK_READY = 6,
    NPU_TS_TASK_RUNNING = 7,
    NPU_TS_TASK_COMMIT = 8,
    NPU_TS_TASK_SUCCESS = 9,
    NPU_TS_TASK_ERROR = 10,
    NPU_TS_TASK_DEPENDENCY_FAILED = 11,
    NPU_TS_TASK_TIMEOUT = 12,
    NPU_TS_TASK_ABORTED = 13
} npu_ts_task_state_t;

typedef enum {
    NPU_TS_EVENT_FREE = 0,
    NPU_TS_EVENT_RESERVED = 1,
    NPU_TS_EVENT_SUCCESS = 2,
    NPU_TS_EVENT_ERROR = 3
} npu_ts_event_state_t;

typedef enum {
    NPU_TS_PORT_DMA = 0,
    NPU_TS_PORT_MATRIX = 1,
    NPU_TS_PORT_VECTOR = 2,
    NPU_TS_PORT_COMPLEX = 3
} npu_ts_engine_port_t;

typedef enum {
    NPU_TS_CTL_WAIT = 0,
    NPU_TS_CTL_QUERY = 1,
    NPU_TS_CTL_FENCE = 2
} npu_ts_ctl_op_t;

typedef enum {
    NPU_TS_CANCEL_IDLE = 0,
    NPU_TS_CANCEL_REQUEST = 1,
    NPU_TS_CANCEL_WAIT_DONE = 2
} npu_ts_cancel_phase_t;

typedef enum {
    NPU_TS_QUERY_STATUS = 0,
    NPU_TS_QUERY_TAG_EVENT = 1,
    NPU_TS_QUERY_FAULT_ADDR = 2,
    NPU_TS_QUERY_PROGRESS = 3,
    NPU_TS_QUERY_ACK = 4,
    NPU_TS_QUERY_ERROR_INFO = 5,
    NPU_TS_QUERY_DONE_FLAGS = 6,
    NPU_TS_QUERY_RESERVED = 7
} npu_ts_query_selector_t;

typedef enum {
    NPU_TS_ERROR_STAGE_DESC_PORT = 2,
    NPU_TS_ERROR_STAGE_ABORT = 5,
    NPU_TS_ERROR_STAGE_TASK_SCHEDULER = 6
} npu_ts_error_stage_t;

typedef struct {
    uint8_t valid;
    uint64_t data;
    uint8_t first;
    uint8_t last;

    uint8_t lookup_valid;
    uint16_t lookup_id;
} npu_ts_cfe_inputs_t;

typedef struct {
    uint8_t ready;

    uint8_t lookup_ready;
    uint8_t lookup_rsp_valid;
    uint8_t lookup_busy;
} npu_ts_cfe_outputs_t;

typedef struct {
    uint8_t req_ready;

    uint8_t rsp_valid;
    uint64_t rsp_data;
    uint16_t rsp_tag;
    uint8_t rsp_last;
    uint8_t rsp_status;
} npu_ts_dfu_inputs_t;

typedef struct {
    uint8_t req_valid;
    uint64_t req_addr;
    uint8_t req_beats;
    uint16_t req_tag;
    uint16_t req_task_id;
    uint8_t req_attr;

    uint8_t rsp_ready;
} npu_ts_dfu_outputs_t;

typedef struct {
    uint8_t req_ready;
    uint8_t cancel_ready;

    uint8_t done_valid;
    uint64_t done_data;
    uint8_t done_first;
    uint8_t done_last;

    uint8_t quiescent;
} npu_ts_engine_inputs_t;

typedef struct {
    uint8_t req_valid;
    uint64_t req_data;

    uint8_t cancel_valid;
    uint8_t cancel_status;

    uint8_t done_ready;
    uint8_t abort;
} npu_ts_engine_outputs_t;

typedef struct {
    uint8_t req_valid;
    uint8_t req_slot;
    uint8_t req_word;
    uint8_t req_tag;
    uint8_t rsp_ready;
} npu_ts_desc_read_inputs_t;

typedef struct {
    uint8_t req_ready;
    uint8_t rsp_valid;
    uint64_t rsp_data;
    uint8_t rsp_tag;
    uint8_t rsp_status;
} npu_ts_desc_read_outputs_t;

typedef struct {
    uint8_t valid;
    uint8_t op;
    uint64_t rs1;
    uint64_t rs2;
    uint8_t cancel;
    uint8_t rsp_ready;
} npu_ts_ctl_inputs_t;

typedef struct {
    uint8_t ready;
    uint8_t rsp_valid;
    uint64_t rsp_data;
} npu_ts_ctl_outputs_t;

typedef struct {
    uint8_t reset_n;
    uint8_t stop_accept;
    uint8_t quiesce_req;
    uint8_t abort_req;
    /*
     * One-cycle notification that a non-controlled MIF CDC reset discarded
     * transport state. It terminates an active DFU fetch and an active DMA
     * task without waiting for responses that can no longer arrive.
     */
    uint8_t mif_reset_abort;
    uint32_t timeout_cycles[NPU_TIMEOUT_CLASS_NUM];

    npu_ts_cfe_inputs_t cfe;
    npu_ts_dfu_inputs_t dfu;
    npu_ts_engine_inputs_t engine[NPU_TS_ENGINE_COUNT];
    npu_ts_desc_read_inputs_t desc[NPU_TS_ENGINE_COUNT];
    npu_ts_ctl_inputs_t ctl;
} npu_ts_cycle_inputs_t;

typedef struct {
    npu_ts_cfe_outputs_t cfe;
    npu_ts_dfu_outputs_t dfu;
    npu_ts_engine_outputs_t engine[NPU_TS_ENGINE_COUNT];
    npu_ts_desc_read_outputs_t desc[NPU_TS_ENGINE_COUNT];
    npu_ts_ctl_outputs_t ctl;

    uint8_t irq_success_pulse;
    uint8_t irq_error_pulse;
    uint16_t irq_success_task_id;
    uint16_t irq_error_task_id;

    uint8_t terminal_valid;
    uint16_t terminal_task_id;
    uint8_t terminal_status;
    uint8_t terminal_engine;
    uint8_t terminal_opcode;
    uint64_t terminal_fault_addr;
    uint32_t terminal_error_info;
    uint16_t terminal_done_flags;
    uint8_t terminal_irq_on_success;
    uint8_t terminal_irq_on_error;

    uint8_t done_protocol_error_mask;
    uint64_t
        done_protocol_error_count[NPU_TS_ENGINE_COUNT];

    uint8_t idle;
    uint8_t quiescent;
    uint8_t task_slots_used;
    uint8_t desc_slots_used;
    uint64_t cycle;
} npu_ts_cycle_outputs_t;

typedef struct {
    uint8_t state;
    uint8_t generation;
    uint16_t producer_task_id;
    uint8_t error_status;
    uint8_t waiter_count;
} npu_ts_event_entry_t;

typedef struct {
    uint8_t valid;
    uint8_t terminal;
    uint8_t engine;
    uint8_t status;
    uint64_t submit_seq;
} npu_ts_fence_target_t;

typedef struct {
    uint8_t valid;
    uint8_t state;
    uint8_t desc_slot;
    uint8_t fetch_started;
    uint8_t waiters_released;
    uint8_t malformed_cmd;

    npu_cmd_t cmd;
    npu_task_request_t request;
    npu_wire_meta_t meta;

    uint64_t submit_seq;
    uint64_t accept_cycle;
    uint64_t start_cycle;
    uint64_t end_cycle;
    uint64_t commit_cycle;

    uint8_t status;
    uint32_t error_info;
    uint16_t done_flags;
    uint64_t fault_addr;
    uint64_t progress;
    uint32_t user_tag;

    uint8_t fence_target_count;
    npu_ts_fence_target_t fence_target[NPU_TS_TASK_COUNT];
} npu_ts_task_entry_t;

typedef struct {
    uint8_t allocated;
    uint8_t full;
    uint8_t owner_engine;
    uint8_t owner_task_slot;
    uint16_t bytes;
    uint8_t data[NPU_TS_DESC_BYTES];
    uint8_t ecc_status[NPU_TS_DESC_WORDS];
} npu_ts_desc_slot_t;

typedef struct {
    uint8_t valid;
    uint8_t task_slot;
    uint8_t segment;
    uint8_t request_valid;
    uint8_t waiting_response;
    uint8_t drain_only;
    uint8_t expected_beats;
    uint8_t received_beats;
    uint8_t base_word;
    uint8_t first_status;
    uint32_t first_error_info;
    uint64_t req_addr;
} npu_ts_dfu_state_t;

typedef struct {
    uint8_t valid;
    uint8_t task_slot;
    uint64_t data;
} npu_ts_engine_req_hold_t;

typedef struct {
    uint8_t beat;
    uint8_t task_slot;
    uint8_t status;
    uint8_t protocol_error;
    uint16_t done_flags;
    uint32_t error_info;
    uint64_t fault_addr;
} npu_ts_done_receiver_t;

typedef struct {
    uint8_t phase;
    uint8_t status;
} npu_ts_cancel_state_t;

typedef struct {
    uint8_t valid;
    uint8_t tag;
    uint64_t data;
    uint8_t status;
    uint64_t ready_cycle;
} npu_ts_desc_rsp_entry_t;

typedef struct {
    npu_ts_desc_rsp_entry_t queue[NPU_TS_DESC_TAG_COUNT];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
    uint16_t tags_in_use;
    uint8_t tag_count[NPU_TS_DESC_TAG_COUNT];
} npu_ts_desc_port_state_t;

typedef struct {
    uint8_t active;
    uint8_t op;
    uint8_t rsp_valid;
    uint8_t ack_release_valid;
    uint8_t ack_task_slot;
    uint64_t rsp_data;
    uint64_t rs1;
    uint64_t rs2;
    uint32_t wait_count;
    uint32_t wait_limit;
    uint16_t wait_event;
    uint8_t waiter_registered;
    uint8_t fence_target_count;
    npu_ts_fence_target_t fence_target[NPU_TS_TASK_COUNT];
} npu_ts_ctl_state_t;

typedef struct {
    uint16_t task_id;
    uint8_t status;
    uint8_t engine;
    uint8_t opcode;
    uint64_t fault_addr;
    uint32_t error_info;
    uint16_t done_flags;
    uint8_t irq_on_success;
    uint8_t irq_on_error;
} npu_ts_terminal_notice_t;

typedef struct {
    uint64_t cycle;
    uint64_t next_submit_seq;
    npu_wire_limits_t wire_limits;
    uint8_t descriptor_diagnostic_mode;

    npu_ts_task_entry_t task[NPU_TS_TASK_COUNT];
    npu_ts_desc_slot_t desc_slot[NPU_TS_DESC_SLOT_COUNT];
    npu_ts_event_entry_t event[NPU_TS_EVENT_COUNT];

    uint8_t lookup_rsp_valid;
    uint8_t lookup_rsp_busy;

    uint8_t cfe_half_valid;
    uint8_t cfe_half_terminate;
    uint8_t cfe_half_task_slot;
    uint8_t cfe_half_desc_slot;
    uint64_t cfe_low;

    npu_ts_dfu_state_t dfu;
    npu_ts_engine_req_hold_t req_hold[NPU_TS_ENGINE_COUNT];
    npu_ts_done_receiver_t done_rx[NPU_TS_ENGINE_COUNT];
    npu_ts_cancel_state_t cancel[NPU_TS_ENGINE_COUNT];
    uint8_t engine_active_task[NPU_TS_ENGINE_COUNT];
    npu_ts_desc_port_state_t desc_port[NPU_TS_ENGINE_COUNT];
    npu_ts_ctl_state_t ctl;

    uint8_t irq_success_pending;
    uint8_t irq_error_pending;
    uint16_t irq_success_task_id;
    uint16_t irq_error_task_id;
    uint8_t done_protocol_error_pending;
    uint64_t
        done_protocol_error_count[NPU_TS_ENGINE_COUNT];

    npu_ts_terminal_notice_t
        terminal_notice[NPU_TS_TASK_COUNT];
    uint8_t terminal_notice_head;
    uint8_t terminal_notice_tail;
    uint8_t terminal_notice_count;
} npu_ts_cycle_t;

void npu_ts_cycle_init(npu_ts_cycle_t *model);
void npu_ts_cycle_reset(npu_ts_cycle_t *model);
int npu_ts_cycle_inject_desc_ecc(npu_ts_cycle_t *model,
                                 uint8_t desc_slot,
                                 uint8_t word,
                                 uint8_t status);
void npu_ts_cycle_step(npu_ts_cycle_t *model,
                       const npu_ts_cycle_inputs_t *inputs,
                       npu_ts_cycle_outputs_t *outputs);

/*
 * Returns nonzero only when every Task/Descriptor entry and all internal
 * request, response, notice, and control state are empty.
 */
int npu_ts_cycle_idle(const npu_ts_cycle_t *model);

const npu_ts_task_entry_t *npu_ts_cycle_find_task(
    const npu_ts_cycle_t *model,
    uint16_t command_id);

#ifdef __cplusplus
}
#endif

#endif
