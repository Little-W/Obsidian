#ifndef NPU_ENGINE_CYCLE_H
#define NPU_ENGINE_CYCLE_H

#include "npu_cmodel.h"
#include "npu_wire.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_ENGINE_DESC_TAGS 16u
#define NPU_ENGINE_DESC_MAX_BYTES NPU_WIRE_DMA_DESC_BYTES
#define NPU_ENGINE_DESC_MAX_WORDS \
    (NPU_ENGINE_DESC_MAX_BYTES / NPU_REF_BUS_BYTES)
#define NPU_ENGINE_DESC_OVERHEAD_CYCLES 3u
#define NPU_ENGINE_INVALID_DESC_WORD 0xffu

/*
 * Descriptor SRAM status values are the values used by the 3-bit interface
 * in Spec section 8.4. Values 3 through 7 are protocol errors.
 */
typedef enum {
    NPU_ENGINE_DESC_OK = 0,
    NPU_ENGINE_DESC_ECC_CORRECTED = 1,
    NPU_ENGINE_DESC_ECC_UNCORRECTABLE = 2
} npu_engine_desc_status_t;

typedef enum {
    NPU_ENGINE_CYCLE_IDLE = 0,
    NPU_ENGINE_CYCLE_FETCH_DESC = 1,
    NPU_ENGINE_CYCLE_DECODE_DESC = 2,
    NPU_ENGINE_CYCLE_EXECUTE = 3,
    NPU_ENGINE_CYCLE_DONE = 4
} npu_engine_cycle_state_t;

/* Spec section 8.5 error_info stage encoding. */
typedef enum {
    NPU_ENGINE_ERROR_NONE = 0,
    NPU_ENGINE_ERROR_METADATA = 1,
    NPU_ENGINE_ERROR_DESC_PORT = 2,
    NPU_ENGINE_ERROR_DESC_DECODE = 3,
    NPU_ENGINE_ERROR_EXECUTE = 4,
    NPU_ENGINE_ERROR_ABORT = 5
} npu_engine_error_stage_t;

typedef enum {
    NPU_ENGINE_META_RESERVED = 1,
    NPU_ENGINE_META_TASK_FLAGS = 2,
    NPU_ENGINE_META_DESC_SLOT = 3,
    NPU_ENGINE_META_OPCODE = 4,
    NPU_ENGINE_META_DESC_CRC = 5
} npu_engine_metadata_error_t;

/*
 * Spec section 8.5 error_info layout:
 *   [31:28] stage
 *   [27:16] detail (metadata reason, port status, or task status)
 *   [15:8]  descriptor word, 0xff when not applicable
 *   [7:0]   opcode
 */
#define NPU_ENGINE_ERROR_STAGE_SHIFT 28u
#define NPU_ENGINE_ERROR_DETAIL_SHIFT 16u
#define NPU_ENGINE_ERROR_WORD_SHIFT 8u
#define NPU_ENGINE_ERROR_DETAIL_MASK 0x0fffu

typedef struct {
    uint8_t reset_n;

    uint8_t eng_req_valid_i;
    uint64_t eng_req_data_i;

    uint8_t eng_done_ready_i;
    uint8_t eng_abort_i;

    /*
     * Per-task cancellation is accepted only while a task is active and
     * status is TIMEOUT or ABORTED. eng_abort_i remains the independent
     * level-sensitive controlled-reset input.
     */
    uint8_t eng_cancel_valid_i;
    uint8_t eng_cancel_status_i;

    uint8_t desc_rd_req_ready_i;

    uint8_t desc_rd_rsp_valid_i;
    uint64_t desc_rd_rsp_data_i;
    uint8_t desc_rd_rsp_tag_i;
    uint8_t desc_rd_rsp_status_i;
} npu_engine_cycle_inputs_t;

typedef struct {
    uint8_t eng_req_ready_o;

    /* Completes one cancellation transfer with eng_cancel_valid_i. */
    uint8_t eng_cancel_ready_o;

    uint8_t desc_rd_req_valid_o;
    uint8_t desc_rd_slot_o;
    uint8_t desc_rd_word_o;
    uint8_t desc_rd_req_tag_o;

    uint8_t desc_rd_rsp_ready_o;

    uint8_t eng_done_valid_o;
    uint64_t eng_done_data_o;
    uint8_t eng_done_first_o;
    uint8_t eng_done_last_o;

    uint8_t eng_busy_o;
    uint8_t eng_quiescent_o;

    /*
     * Common activity signals are valid for all four engine instances.
     * active means the functional execution interval. stall reports only
     * Descriptor SRAM or done-interface pauses represented by this adapter;
     * it does not stand in for the separate L1BUF or MIF data interfaces.
     */
    uint8_t eng_active_o;
    uint8_t eng_stall_o;
    uint8_t desc_stall_o;
    uint8_t done_stall_o;

    uint8_t desc_outstanding_o;
    uint8_t desc_words_received_o;
    uint8_t ecc_corrected_o;
    uint8_t protocol_error_o;

    uint64_t cycle;
} npu_engine_cycle_outputs_t;

typedef struct {
    uint8_t valid;
    uint8_t word;
} npu_engine_desc_tag_t;

typedef struct {
    npu_engine_t engine;
    npu_model_t *functional_model;
    npu_wire_limits_t wire_limits;
    uint8_t initialized;

    npu_engine_cycle_state_t state;
    uint64_t cycle;

    uint16_t task_id;
    uint8_t opcode;
    uint8_t desc_slot;
    uint16_t task_flags;
    uint8_t timeout_class;

    uint8_t descriptor[NPU_ENGINE_DESC_MAX_BYTES];
    uint16_t descriptor_bytes;
    uint8_t descriptor_words;
    uint8_t next_desc_word;
    uint8_t desc_words_received;

    npu_engine_desc_tag_t desc_tag[NPU_ENGINE_DESC_TAGS];
    uint8_t desc_outstanding;

    uint8_t desc_req_hold_valid;
    uint8_t desc_req_hold_word;
    uint8_t desc_req_hold_tag;

    uint8_t aborting;
    uint8_t canceling;
    uint8_t terminal_pending;
    npu_status_t pending_status;
    uint32_t pending_error_info;
    uint64_t pending_fault_addr;
    uint16_t pending_done_flags;
    uint64_t pending_progress;

    npu_task_request_t request;
    npu_wire_meta_t wire_meta;
    uint64_t estimated_total_cycles;
    uint64_t descriptor_phase_cycles;
    uint64_t execute_remaining;

    uint64_t done_data[3];
    uint8_t done_beat;

    uint64_t ecc_corrected_count;
    uint8_t ecc_corrected_pulse;
    uint8_t protocol_error_pulse;
} npu_engine_cycle_t;

/*
 * Binds one adapter instance to one functional npu_model_t and one engine.
 * engine must be DMA, MATRIX, VECTOR, or COMPLEX. The caller owns all memory.
 * limits may be NULL to use npu_wire_limits_reference().
 */
npu_status_t npu_engine_cycle_init(
    npu_engine_cycle_t *adapter,
    npu_model_t *functional_model,
    npu_engine_t engine,
    const npu_wire_limits_t *limits);

/*
 * Reset clears the interface state and all outstanding descriptor tags. It
 * keeps the engine/model binding and does not alter L1 or DDR contents.
 */
void npu_engine_cycle_reset(npu_engine_cycle_t *adapter);

/*
 * One call models one rising edge. Functional operators run only on the last
 * EXECUTE edge. Their writes therefore become visible together at that edge;
 * this adapter does not claim per-L1-beat data visibility. The full task
 * estimate is reduced by descriptor_words + 3 because descriptor transfer,
 * collection, and decode have already completed in this adapter.
 */
void npu_engine_cycle_step(npu_engine_cycle_t *adapter,
                           const npu_engine_cycle_inputs_t *inputs,
                           npu_engine_cycle_outputs_t *outputs);

/*
 * Computes the signals driven during the current cycle without committing
 * adapter state. The function may prepare a descriptor request in a private
 * structure copy, but it never invokes a functional operator and therefore
 * cannot write L1/DDR data or change functional-model performance counters.
 */
void npu_engine_cycle_eval(
    const npu_engine_cycle_t *adapter,
    const npu_engine_cycle_inputs_t *inputs,
    npu_engine_cycle_outputs_t *outputs);

uint8_t npu_engine_cycle_quiescent(
    const npu_engine_cycle_t *adapter);

uint32_t npu_engine_cycle_error_info(
    npu_engine_error_stage_t stage,
    uint16_t detail,
    uint8_t descriptor_word,
    uint8_t opcode);

#ifdef __cplusplus
}
#endif

#endif
