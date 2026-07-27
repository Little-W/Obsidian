#ifndef NPU_CFE_CYCLE_H
#define NPU_CFE_CYCLE_H

#include "npu_cmodel.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_CFE_CYCLE_FIFO_DEPTH 8u
#define NPU_CFE_CYCLE_BEAT_TIMEOUT 32u

typedef enum {
    NPU_CFE_STATE_IDLE = 0,
    NPU_CFE_STATE_WAIT_HI = 1,
    NPU_CFE_STATE_CHECK = 2,
    NPU_CFE_STATE_LOOKUP_ID = 3,
    NPU_CFE_STATE_ENQUEUE = 4,
    NPU_CFE_STATE_RESP_OK = 5,
    NPU_CFE_STATE_RESP_ERR = 6
} npu_cfe_cycle_state_t;

typedef struct {
    uint8_t reset_n;
    uint8_t cfe_quiesce_i;

    uint8_t gc_cmd_valid_i;
    uint64_t gc_cmd_data_i;
    uint8_t gc_cmd_first_i;
    uint8_t gc_cmd_last_i;
    uint8_t gc_rsp_ready_i;

    uint8_t ts_cmd_ready_i;

    uint8_t cmd_id_lookup_ready_i;
    uint8_t cmd_id_lookup_rsp_valid_i;
    uint8_t cmd_id_busy_i;
} npu_cfe_cycle_inputs_t;

typedef struct {
    uint8_t gc_cmd_ready_o;
    uint8_t gc_rsp_valid_o;
    uint64_t gc_rsp_data_o;

    uint8_t ts_cmd_valid_o;
    uint64_t ts_cmd_data_o;
    uint8_t ts_cmd_first_o;
    uint8_t ts_cmd_last_o;

    uint8_t cmd_id_lookup_valid_o;
    uint16_t cmd_id_lookup_id_o;

    uint8_t cfe_idle_o;
    uint8_t cfe_error_o;
    /* One-cycle pulse after a validated command enters the CFE FIFO. */
    uint8_t cmd_accepted_o;
} npu_cfe_cycle_outputs_t;

typedef struct {
    uint64_t low;
    uint64_t high;
} npu_cfe_fifo_entry_t;

typedef struct {
    npu_cfe_cycle_state_t state;

    uint64_t low_beat;
    uint64_t high_beat;
    uint32_t beat_wait_cycles;
    uint8_t ts_output_beat;

    uint16_t response_command_id;
    uint8_t response_status;
    uint8_t response_free_entries;

    uint8_t lookup_request_sent;
    uint8_t local_duplicate;
    uint8_t error_pulse;
    uint8_t accepted_pulse;
    uint8_t descriptor_diagnostic_mode;

    npu_cfe_fifo_entry_t fifo[NPU_CFE_CYCLE_FIFO_DEPTH];
    uint8_t fifo_read_index;
    uint8_t fifo_write_index;
    uint8_t fifo_count;

    uint64_t cycle;
} npu_cfe_cycle_t;

void npu_cfe_cycle_reset(npu_cfe_cycle_t *model);

void npu_cfe_cycle_step(npu_cfe_cycle_t *model,
                        const npu_cfe_cycle_inputs_t *inputs,
                        npu_cfe_cycle_outputs_t *outputs);

uint8_t npu_cfe_cycle_idle(const npu_cfe_cycle_t *model);

#ifdef __cplusplus
}
#endif

#endif
