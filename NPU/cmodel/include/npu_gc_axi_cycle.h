#ifndef NPU_GC_AXI_CYCLE_H
#define NPU_GC_AXI_CYCLE_H

#include "npu_cmodel.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_GC_AXI_CLIENT_COUNT 2u
#define NPU_GC_AXI_CLIENT_ICACHE 0u
#define NPU_GC_AXI_CLIENT_DCACHE 1u

/*
 * The Spec fixes the bus widths but not the adapter table sizes. These
 * deterministic C-model values allow eight concurrent reads, four concurrent
 * writes, and child bursts of at most sixteen 64-bit beats.
 */
#define NPU_GC_AXI_READ_OUTSTANDING 8u
#define NPU_GC_AXI_WRITE_OUTSTANDING 4u
#define NPU_GC_AXI_MAX_BURST_BEATS 16u
#define NPU_GC_AXI_WRITE_ORDER_DEPTH \
    NPU_GC_AXI_WRITE_OUTSTANDING

#define NPU_GC_AXI_PA_MASK UINT64_C(0x000000ffffffffff)
#define NPU_GC_AXI_INVALID_SLOT 0xffu
#define NPU_GC_AXI_INVALID_CLIENT 0xffu
#define NPU_GC_AXI_READ_ID_LIMIT 0x80u
#define NPU_GC_AXI_WRITE_ID_BASE 0x80u
#define NPU_GC_AXI_WRITE_ID_LIMIT 0x100u

typedef enum {
    NPU_GC_AXI_PROTOCOL_NONE = 0,
    NPU_GC_AXI_PROTOCOL_RID = 1,
    NPU_GC_AXI_PROTOCOL_BID = 2,
    NPU_GC_AXI_PROTOCOL_RLAST = 3,
    NPU_GC_AXI_PROTOCOL_WLAST = 4,
    NPU_GC_AXI_PROTOCOL_WTAG = 5,
    NPU_GC_AXI_PROTOCOL_RRESP = 6,
    NPU_GC_AXI_PROTOCOL_BRESP = 7,
    NPU_GC_AXI_PROTOCOL_DUPLICATE_TAG = 8
} npu_gc_axi_protocol_kind_t;

typedef enum {
    NPU_GC_AXI_RESP_OKAY = 0,
    NPU_GC_AXI_RESP_EXOKAY = 1,
    NPU_GC_AXI_RESP_SLVERR = 2,
    NPU_GC_AXI_RESP_DECERR = 3
} npu_gc_axi_resp_t;

typedef struct {
    uint8_t valid;
    uint64_t addr;
    uint8_t beats;
    uint16_t tag;
    uint8_t cache;
    uint8_t prot;
    /* P0 requires qos to be zero. */
    uint8_t qos;
} npu_gc_axi_read_req_t;

typedef struct {
    uint8_t valid;
    uint64_t addr;
    uint8_t beats;
    uint16_t tag;
    uint8_t cache;
    uint8_t prot;
    /* P0 requires qos to be zero. */
    uint8_t qos;
} npu_gc_axi_write_req_t;

typedef struct {
    uint8_t valid;
    uint64_t data;
    uint8_t strb;
    /*
     * last marks the final beat of the complete internal request, not a
     * child AXI burst. beats in the request is authoritative even when last
     * is malformed; the producer must still provide exactly that many beats.
     */
    uint8_t last;
    uint16_t tag;
} npu_gc_axi_write_data_t;

typedef struct {
    uint8_t valid;
    uint64_t data;
    uint16_t tag;
    uint8_t last;
    uint8_t status;
} npu_gc_axi_read_rsp_t;

typedef struct {
    uint8_t valid;
    uint16_t tag;
    uint8_t status;
} npu_gc_axi_write_rsp_t;

typedef struct {
    uint8_t awready;
    uint8_t wready;
    uint8_t bvalid;
    uint8_t bid;
    uint8_t bresp;

    uint8_t arready;
    uint8_t rvalid;
    uint8_t rid;
    uint64_t rdata;
    uint8_t rresp;
    uint8_t rlast;
} npu_gc_axi_bus_inputs_t;

typedef struct {
    uint8_t awid;
    uint64_t awaddr;
    uint8_t awlen;
    uint8_t awsize;
    uint8_t awburst;
    uint8_t awlock;
    uint8_t awcache;
    uint8_t awprot;
    uint8_t awqos;
    uint8_t awvalid;

    uint64_t wdata;
    uint8_t wstrb;
    uint8_t wlast;
    uint8_t wvalid;

    uint8_t bready;

    uint8_t arid;
    uint64_t araddr;
    uint8_t arlen;
    uint8_t arsize;
    uint8_t arburst;
    uint8_t arlock;
    uint8_t arcache;
    uint8_t arprot;
    uint8_t arqos;
    uint8_t arvalid;

    uint8_t rready;
} npu_gc_axi_bus_outputs_t;

typedef struct {
    uint8_t reset_n;
    /* Clears sticky first/protocol diagnostics at this rising edge. */
    uint8_t error_clear;

    /*
     * quiesce stops new I-cache and D-cache request handshakes. Requests
     * already accepted continue until all AXI and internal responses finish.
     *
     * A client must not reuse a tag before its final response handshake.
     * A duplicate is nevertheless consumed and returns BAD_DESC with the
     * repeated tag; that status identifies the rejected request. The original
     * request continues independently.
     */
    uint8_t quiesce;

    npu_gc_axi_read_req_t icache_req;
    uint8_t icache_rsp_ready;

    npu_gc_axi_read_req_t dcache_read_req;
    uint8_t dcache_read_rsp_ready;

    npu_gc_axi_write_req_t dcache_write_req;
    npu_gc_axi_write_data_t dcache_write_data;
    uint8_t dcache_write_rsp_ready;

    npu_gc_axi_bus_inputs_t axi;
} npu_gc_axi_cycle_inputs_t;

typedef struct {
    uint8_t icache_req_ready;
    npu_gc_axi_read_rsp_t icache_rsp;

    uint8_t dcache_read_req_ready;
    npu_gc_axi_read_rsp_t dcache_read_rsp;

    uint8_t dcache_write_req_ready;
    uint8_t dcache_write_data_ready;
    /*
     * Meaningful when dcache_write_data_ready is one. AXI4 has no WID,
     * so the producer must present data for this tag. The adapter reports
     * a tag mismatch and associates the beat with this advertised tag.
     */
    uint16_t dcache_write_data_tag;
    npu_gc_axi_write_rsp_t dcache_write_rsp;

    npu_gc_axi_bus_outputs_t axi;

    uint8_t idle;
    uint8_t quiescent;
    uint8_t read_requests_used;
    uint8_t write_requests_used;
    uint8_t read_axi_outstanding;
    uint8_t write_axi_outstanding;

    uint8_t first_error_valid;
    uint8_t first_error_status;
    uint8_t first_error_client;
    uint16_t first_error_tag;
    uint64_t first_error_addr;
    uint8_t first_error_axi_id;
    uint8_t first_error_axi_id_valid;
    uint8_t first_error_axi_resp;

    uint8_t protocol_error_valid;
    uint8_t protocol_error_kind;
    uint64_t protocol_error_addr;
    uint8_t protocol_error_client;
    uint16_t protocol_error_tag;
    uint8_t protocol_error_axi_id;
    uint8_t protocol_error_axi_id_valid;

    uint64_t cycle_count;
} npu_gc_axi_cycle_outputs_t;

typedef struct {
    uint8_t valid;
    uint8_t client;
    uint16_t tag;
    uint8_t status;
    uint8_t response_pending;
    uint8_t response_held;

    uint64_t first_addr;
    uint64_t next_addr;
    uint16_t total_beats;
    uint16_t remaining_beats;
    uint8_t cache;
    uint8_t prot;
    uint8_t qos;

    uint8_t child_active;
    uint8_t addr_sent;
    uint8_t axi_id;
    uint16_t child_beats;
    uint16_t child_beats_done;
    /*
     * A missing RLAST at the declared child length enters discard mode.
     * The AXI ID remains live and idle stays low until RLAST is accepted.
     */
    uint8_t drain_rlast;
} npu_gc_axi_read_entry_t;

typedef struct {
    uint8_t valid;
    uint16_t tag;
    uint8_t status;
    uint8_t response_pending;
    uint8_t response_held;

    uint64_t first_addr;
    uint64_t next_addr;
    uint16_t total_beats;
    uint16_t remaining_beats;
    uint16_t total_write_beats_accepted;
    uint8_t cache;
    uint8_t prot;
    uint8_t qos;

    uint8_t child_active;
    uint8_t addr_sent;
    uint8_t axi_id;
    uint16_t child_beats;
    uint16_t child_write_beats_accepted;
    uint16_t child_write_beats_sent;
    uint8_t w_done;
    /*
     * Set after an illegal B response arrives before the final W beat.
     * The declared logical beat count remains authoritative: remaining
     * internal beats are accepted and discarded before completion.
     */
    uint8_t discard_write_data;
} npu_gc_axi_write_entry_t;

typedef struct {
    uint8_t valid;
    uint8_t request_slot;
    uint8_t final;
    uint64_t data;
    uint16_t tag;
    uint8_t last;
    uint8_t status;
} npu_gc_axi_read_rsp_hold_t;

typedef struct {
    uint8_t valid;
    uint8_t request_slot;
    uint16_t tag;
    uint8_t status;
} npu_gc_axi_write_rsp_hold_t;

typedef struct {
    uint8_t valid;
    uint8_t request_slot;
    uint64_t data;
    uint8_t strb;
    uint8_t last;
} npu_gc_axi_w_hold_t;

typedef struct {
    uint8_t valid;
    uint8_t id;
    uint8_t resp;
} npu_gc_axi_b_entry_t;

typedef struct {
    uint8_t valid;
    uint8_t id;
    uint64_t data;
    uint8_t resp;
    uint8_t last;
} npu_gc_axi_r_entry_t;

typedef struct {
    npu_gc_axi_read_entry_t
        read[NPU_GC_AXI_READ_OUTSTANDING];
    npu_gc_axi_write_entry_t
        write[NPU_GC_AXI_WRITE_OUTSTANDING];

    npu_gc_axi_read_rsp_hold_t icache_rsp_hold;
    npu_gc_axi_read_rsp_hold_t dcache_read_rsp_hold;
    npu_gc_axi_write_rsp_hold_t dcache_write_rsp_hold;

    uint8_t ar_hold;
    uint8_t aw_hold;
    npu_gc_axi_w_hold_t w_hold;
    npu_gc_axi_b_entry_t b_entry;
    npu_gc_axi_r_entry_t r_entry;

    uint8_t write_order[NPU_GC_AXI_WRITE_ORDER_DEPTH];
    uint8_t write_order_head;
    uint8_t write_order_tail;
    uint8_t write_order_count;

    uint8_t next_read_id;
    uint8_t next_write_id;
    uint8_t read_req_rr_client;
    uint8_t read_schedule_rr;
    uint8_t write_schedule_rr;

    uint8_t first_error_valid;
    uint8_t first_error_status;
    uint8_t first_error_client;
    uint16_t first_error_tag;
    uint64_t first_error_addr;
    uint8_t first_error_axi_id;
    uint8_t first_error_axi_id_valid;
    uint8_t first_error_axi_resp;

    uint8_t protocol_error_valid;
    uint8_t protocol_error_kind;
    uint64_t protocol_error_addr;
    uint8_t protocol_error_client;
    uint16_t protocol_error_tag;
    uint8_t protocol_error_axi_id;
    uint8_t protocol_error_axi_id_valid;

    uint64_t cycle_count;
} npu_gc_axi_cycle_t;

void npu_gc_axi_cycle_init(npu_gc_axi_cycle_t *model);
void npu_gc_axi_cycle_reset(npu_gc_axi_cycle_t *model);

/*
 * outputs describes signals visible during the current cycle. Handshakes
 * update model state at the end of the call. A low reset_n clears all state
 * immediately. Controlled reset must assert quiesce first and wait for idle.
 */
void npu_gc_axi_cycle_step(
    npu_gc_axi_cycle_t *model,
    const npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs);

uint8_t npu_gc_axi_cycle_is_idle(
    const npu_gc_axi_cycle_t *model);

#ifdef __cplusplus
}
#endif

#endif
