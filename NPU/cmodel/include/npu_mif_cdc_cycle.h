#ifndef NPU_MIF_CDC_CYCLE_H
#define NPU_MIF_CDC_CYCLE_H

#include "npu_mif_cycle.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Each MIF owner has an independent FIFO for each direction.  Keeping the
 * owners separate lets both Core-side producers observe ready independently
 * and preserves the owner that is implicit in the array index.
 */
#define NPU_MIF_CDC_REQ_FIFO_DEPTH 4u
#define NPU_MIF_CDC_W_FIFO_DEPTH 8u
#define NPU_MIF_CDC_RSP_FIFO_DEPTH 8u

/*
 * Pointer changes pass through two receiving-domain stages.  A payload
 * accepted on one domain therefore cannot become valid on the other domain
 * during the same tick.
 */
#define NPU_MIF_CDC_SYNC_STAGES 2u

typedef struct {
    uint8_t write;
    uint64_t vaddr;
    uint8_t beats;
    uint16_t tag;
    uint8_t owner;
    uint16_t task_id;
    uint8_t attr;
} npu_mif_cdc_req_payload_t;

typedef struct {
    uint64_t data;
    uint8_t strb;
    uint8_t last;
    uint16_t tag;
    uint8_t owner;
} npu_mif_cdc_w_payload_t;

typedef struct {
    uint64_t data;
    uint16_t tag;
    uint8_t is_write;
    uint8_t last;
    uint8_t status;
    uint8_t owner;
} npu_mif_cdc_rsp_payload_t;

/*
 * write_seq and read_seq are monotonic item counters.  The arrays hold the
 * delayed copy used in the opposite domain; index
 * NPU_MIF_CDC_SYNC_STAGES - 1 is the value visible to local ready/valid
 * generation.
 */
typedef struct {
    uint64_t write_seq;
    uint64_t read_seq;
    uint64_t write_seq_at_reader[NPU_MIF_CDC_SYNC_STAGES];
    uint64_t read_seq_at_writer[NPU_MIF_CDC_SYNC_STAGES];
} npu_mif_cdc_fifo_control_t;

typedef struct {
    npu_mif_cdc_fifo_control_t control;
    npu_mif_cdc_req_payload_t
        entry[NPU_MIF_CDC_REQ_FIFO_DEPTH];
} npu_mif_cdc_req_fifo_t;

typedef struct {
    npu_mif_cdc_fifo_control_t control;
    npu_mif_cdc_w_payload_t entry[NPU_MIF_CDC_W_FIFO_DEPTH];
} npu_mif_cdc_w_fifo_t;

typedef struct {
    npu_mif_cdc_fifo_control_t control;
    npu_mif_cdc_rsp_payload_t
        entry[NPU_MIF_CDC_RSP_FIFO_DEPTH];
} npu_mif_cdc_rsp_fifo_t;

/*
 * Core-side inputs are driven by DFU/DMA.  Only req_*, w*, and rsp_ready from
 * npu_mif_owner_inputs_t are consumed.
 */
typedef struct {
    uint8_t reset_n;
    npu_mif_owner_inputs_t owner[NPU_MIF_OWNER_COUNT];
} npu_mif_cdc_core_inputs_t;

/*
 * Core-side outputs return FIFO capacity and MIF responses.  They use the
 * same field names as the corresponding MIF owner port.
 */
typedef struct {
    npu_mif_owner_outputs_t owner[NPU_MIF_OWNER_COUNT];
    /*
     * reset_epoch is the two-stage synchronized copy visible in the Core
     * domain. transport_active is one only after both domains have observed
     * the current epoch and completed their local release tick.
     */
    uint32_t reset_epoch;
    uint8_t transport_active;
} npu_mif_cdc_core_outputs_t;

/*
 * NoC-side inputs are the owner outputs produced by npu_mif_cycle_step().
 */
typedef struct {
    uint8_t reset_n;
    npu_mif_owner_outputs_t owner[NPU_MIF_OWNER_COUNT];
} npu_mif_cdc_noc_inputs_t;

/*
 * NoC-side outputs connect directly to npu_mif_cycle_inputs_t.owner[].
 * Only req_*, w*, and rsp_ready are driven.
 */
typedef struct {
    npu_mif_owner_inputs_t owner[NPU_MIF_OWNER_COUNT];
    /*
     * reset_epoch is the two-stage synchronized copy visible in the NoC
     * domain. transport_active follows the same rule as the Core output.
     */
    uint32_t reset_epoch;
    uint8_t transport_active;
} npu_mif_cdc_noc_outputs_t;

typedef struct {
    npu_mif_cdc_req_fifo_t req_fifo[NPU_MIF_OWNER_COUNT];
    npu_mif_cdc_w_fifo_t w_fifo[NPU_MIF_OWNER_COUNT];
    npu_mif_cdc_rsp_fifo_t rsp_fifo[NPU_MIF_OWNER_COUNT];

    uint8_t core_released;
    uint8_t noc_released;
    uint8_t core_reset_seen;
    uint8_t noc_reset_seen;
    uint32_t reset_epoch;
    uint32_t core_epoch_sync0;
    uint32_t core_epoch_sync1;
    uint32_t noc_epoch_sync0;
    uint32_t noc_epoch_sync1;
    uint64_t core_tick_count;
    uint64_t noc_tick_count;
} npu_mif_cdc_cycle_t;

void npu_mif_cdc_cycle_init(npu_mif_cdc_cycle_t *model);

/*
 * Clears all request, write-data, and response entries. Each domain must
 * observe the new reset epoch through two synchronizer stages and then
 * complete its local release tick before transport is enabled.
 */
void npu_mif_cdc_cycle_reset(npu_mif_cdc_cycle_t *model);

/*
 * The returned outputs are the pins visible before the supplied domain edge.
 * Handshakes and synchronizer movement are committed at the end of the call.
 * Calls for the two domains may be interleaved in any order and at any ratio.
 *
 * A low reset_n on either tick clears every FIFO in both directions and
 * advances reset_epoch. Each domain passes that epoch through two local
 * synchronization stages. Transport remains disabled until both synchronized
 * copies equal the current epoch and each domain has then completed one local
 * release tick. This prevents traffic from returning before the NoC-side MIF
 * reset and the Core-side task termination logic have observed the event.
 */
void npu_mif_cdc_core_tick(
    npu_mif_cdc_cycle_t *model,
    const npu_mif_cdc_core_inputs_t *inputs,
    npu_mif_cdc_core_outputs_t *outputs);

void npu_mif_cdc_noc_tick(
    npu_mif_cdc_cycle_t *model,
    const npu_mif_cdc_noc_inputs_t *inputs,
    npu_mif_cdc_noc_outputs_t *outputs);

uint8_t npu_mif_cdc_cycle_is_active(
    const npu_mif_cdc_cycle_t *model);

/*
 * Debug helpers return the exact number of stored entries.  An invalid owner
 * value returns zero and is never used as an array index.
 */
uint8_t npu_mif_cdc_req_level(
    const npu_mif_cdc_cycle_t *model,
    uint8_t owner);
uint8_t npu_mif_cdc_w_level(
    const npu_mif_cdc_cycle_t *model,
    uint8_t owner);
uint8_t npu_mif_cdc_rsp_level(
    const npu_mif_cdc_cycle_t *model,
    uint8_t owner);

#ifdef __cplusplus
}
#endif

#endif
