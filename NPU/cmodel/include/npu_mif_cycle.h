#ifndef NPU_MIF_CYCLE_H
#define NPU_MIF_CYCLE_H

#include "npu_cmodel.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_MIF_OWNER_COUNT 2u
#define NPU_MIF_MAX_REQUESTS 16u
#define NPU_MIF_MAX_AXI_OUTSTANDING 16u
#define NPU_MIF_MAX_TBU_OUTSTANDING 8u
#define NPU_MIF_AXI_MAX_BURST_BEATS 16u
#define NPU_MIF_INVALID_SLOT 0xffu
#define NPU_MIF_INVALID_OWNER 0xffu
#define NPU_MIF_INVALID_AXI_ID 0xffu
#define NPU_MIF_GVA_MASK UINT64_C(0x0000ffffffffffff)
#define NPU_MIF_PA_MASK UINT64_C(0x000000ffffffffff)

#define NPU_MIF_ATTR_TBU_BYPASS 0x01u
#define NPU_MIF_ATTR_CACHE_MASK 0x06u
#define NPU_MIF_ATTR_CACHE_SHIFT 1u
#define NPU_MIF_ATTR_PRIVILEGED 0x08u
#define NPU_MIF_ATTR_NONSECURE 0x10u
#define NPU_MIF_ATTR_INSTRUCTION 0x20u
#define NPU_MIF_ATTR_QOS_MASK 0xc0u
#define NPU_MIF_ATTR_QOS_SHIFT 6u

typedef enum {
    NPU_MIF_OWNER_DFU = 0,
    NPU_MIF_OWNER_DMA = 1
} npu_mif_owner_t;

typedef enum {
    NPU_MIF_AXI_RESP_OKAY = 0,
    NPU_MIF_AXI_RESP_EXOKAY = 1,
    NPU_MIF_AXI_RESP_SLVERR = 2,
    NPU_MIF_AXI_RESP_DECERR = 3
} npu_mif_axi_resp_t;

typedef enum {
    NPU_MIF_PROTOCOL_NONE = 0,
    NPU_MIF_PROTOCOL_REQUEST_OWNER = 1,
    NPU_MIF_PROTOCOL_REQUEST_TAG_RANGE = 2,
    NPU_MIF_PROTOCOL_REQUEST_TAG_DUPLICATE = 3,
    NPU_MIF_PROTOCOL_TBU_TAG = 4,
    NPU_MIF_PROTOCOL_TBU_STATUS = 5,
    NPU_MIF_PROTOCOL_AXI_RID = 6,
    NPU_MIF_PROTOCOL_AXI_BID = 7,
    NPU_MIF_PROTOCOL_AXI_RLAST = 8,
    NPU_MIF_PROTOCOL_WRITE_LAST = 9,
    NPU_MIF_PROTOCOL_WRITE_TAG = 10,
    NPU_MIF_PROTOCOL_AXI_RRESP = 11,
    NPU_MIF_PROTOCOL_AXI_BRESP = 12,
    NPU_MIF_PROTOCOL_AXI_EARLY_B = 13,
    NPU_MIF_PROTOCOL_AXI_ENTRY = 14,
    NPU_MIF_PROTOCOL_CONFIG = 15
} npu_mif_protocol_kind_t;

typedef struct {
    uint8_t req_valid;
    uint8_t req_write;
    uint64_t req_vaddr;
    uint8_t req_beats;
    uint16_t req_tag;
    uint8_t req_owner;
    uint16_t req_task_id;
    uint8_t req_attr;

    uint8_t wvalid;
    uint64_t wdata;
    uint8_t wstrb;
    uint8_t wlast;
    uint16_t wtag;

    uint8_t rsp_ready;
} npu_mif_owner_inputs_t;

typedef struct {
    uint8_t req_ready;
    uint8_t wready;

    uint8_t rsp_valid;
    uint64_t rsp_data;
    uint16_t rsp_tag;
    uint8_t rsp_is_write;
    uint8_t rsp_last;
    uint8_t rsp_status;
} npu_mif_owner_outputs_t;

typedef struct {
    uint8_t req_ready;

    uint8_t rsp_valid;
    uint64_t rsp_paddr;
    uint16_t rsp_tag;
    uint8_t rsp_status;
} npu_mif_tbu_inputs_t;

typedef struct {
    uint8_t req_valid;
    uint64_t req_vaddr;
    uint8_t req_write;
    uint16_t req_stream_id;
    uint16_t req_substream_id;
    uint16_t req_tag;

    uint8_t rsp_ready;
} npu_mif_tbu_outputs_t;

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
} npu_mif_axi_inputs_t;

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
} npu_mif_axi_outputs_t;

typedef struct {
    uint8_t reset_n;
    /* Clears sticky first/protocol diagnostics at this rising edge. */
    uint8_t error_clear;

    /*
     * When config_valid is high, these values are the configuration used
     * by requests accepted in this cycle and become the retained
     * configuration at the end of the cycle.
     */
    uint8_t config_valid;
    uint8_t system_addr_enable;
    uint64_t system_addr_base;
    uint64_t system_addr_limit;
    uint8_t bypass_enable;
    uint64_t bypass_base;
    uint64_t bypass_limit;
    uint16_t tbu_stream_id;
    uint16_t tbu_substream_id;

    npu_mif_owner_inputs_t owner[NPU_MIF_OWNER_COUNT];
    npu_mif_tbu_inputs_t tbu;
    npu_mif_axi_inputs_t axi;
} npu_mif_cycle_inputs_t;

typedef struct {
    npu_mif_owner_outputs_t owner[NPU_MIF_OWNER_COUNT];
    npu_mif_tbu_outputs_t tbu;
    npu_mif_axi_outputs_t axi;

    uint8_t mif_idle;
    uint16_t rd_outstanding;
    uint16_t wr_outstanding;
    uint16_t tbu_outstanding;
    uint8_t axi_slots_used;

    uint8_t first_error_valid;
    uint8_t first_error_status;
    uint8_t first_error_owner;
    uint16_t first_error_tag;
    uint16_t first_error_task_id;
    uint64_t first_error_vaddr;
    uint64_t first_error_paddr;
    uint8_t first_error_axi_id;
    uint8_t first_error_axi_id_valid;
    uint8_t first_error_axi_resp;

    uint8_t protocol_error_valid;
    uint8_t protocol_error_kind;
    uint64_t protocol_error_addr;
    uint8_t protocol_error_owner;
    uint16_t protocol_error_tag;
    uint8_t protocol_error_has_task_identity;
    uint16_t protocol_error_task_id;

    uint64_t cycle_count;
    uint64_t idle_cycles;
} npu_mif_cycle_outputs_t;

typedef struct {
    uint8_t system_addr_enable;
    uint64_t system_addr_base;
    /*
     * Each limit is the aligned start address of the final legal 64-bit
     * beat. Thus a one-beat region has base equal to limit.
     */
    uint64_t system_addr_limit;

    uint8_t bypass_enable;
    uint64_t bypass_base;
    uint64_t bypass_limit;

    uint16_t tbu_stream_id;
    uint16_t tbu_substream_id;

    uint8_t axi_cache_device;
    uint8_t axi_cache_normal_noncache;
    uint8_t axi_cache_normal_cacheable;
} npu_mif_cycle_config_t;

typedef enum {
    NPU_MIF_REQ_FREE = 0,
    NPU_MIF_REQ_NEED_TRANSLATION = 1,
    NPU_MIF_REQ_TBU_QUEUED = 2,
    NPU_MIF_REQ_TBU_WAIT = 3,
    NPU_MIF_REQ_READY_BURST = 4,
    NPU_MIF_REQ_AXI = 5,
    NPU_MIF_REQ_RESPONSE_PENDING = 6,
    NPU_MIF_REQ_RESPONSE_HELD = 7
} npu_mif_request_phase_t;

typedef struct {
    uint8_t valid;
    uint8_t phase;
    uint8_t owner;
    uint8_t write;
    uint16_t tag;
    uint16_t task_id;
    uint8_t attr;
    uint8_t status;

    uint64_t first_vaddr;
    uint64_t first_paddr;
    uint64_t next_vaddr;
    uint64_t next_paddr;
    uint16_t total_beats;
    uint16_t remaining_beats;
    uint16_t page_beats;
    uint16_t write_beats_accepted;

    /*
     * The system address range and TBU identifiers are sampled with the owner
     * request. Later configuration writes cannot alter this transaction.
     */
    npu_mif_cycle_config_t request_config;
} npu_mif_request_entry_t;

typedef struct {
    uint8_t valid;
    uint8_t addr_sent;
    uint8_t write;
    uint8_t axi_id;
    uint8_t req_slot;
    uint8_t w_done;
    uint16_t beats;
    uint16_t beats_done;
    uint64_t vaddr;
    uint64_t paddr;
    uint8_t attr;
} npu_mif_axi_entry_t;

typedef struct {
    uint8_t valid;
    uint8_t req_slot;
    uint64_t vaddr;
    uint8_t write;
    uint16_t tag;
} npu_mif_tbu_hold_t;

typedef struct {
    uint8_t valid;
    uint8_t req_slot;
    uint8_t final;
    uint64_t data;
    uint16_t tag;
    uint8_t is_write;
    uint8_t last;
    uint8_t status;
} npu_mif_response_hold_t;

typedef struct {
    uint8_t valid;
    uint8_t out_slot;
    uint64_t data;
    uint8_t strb;
    uint8_t last;
} npu_mif_w_hold_t;

/*
 * One registered beat separates the owner write-data handshake from tag
 * checking and the AXI W hold register. A bad tag leaves this entry occupied
 * and blocked until reset_n is low, so the beat cannot reach AXI and the
 * owner sees backpressure on subsequent beats.
 */
typedef struct {
    uint8_t valid;
    uint8_t blocked;
    uint8_t owner;
    uint8_t out_slot;
    uint64_t data;
    uint8_t strb;
    uint8_t last;
    uint16_t tag;
} npu_mif_w_input_t;

/*
 * One entry per AXI response channel decouples BREADY/RREADY from the incoming valid,
 * identifier, and payload. A captured entry remains unchanged until the
 * response checker either consumes it or explicitly discards malformed
 * traffic.
 */
typedef struct {
    uint8_t valid;
    uint8_t id;
    uint8_t resp;
} npu_mif_axi_b_entry_t;

typedef struct {
    uint8_t valid;
    uint8_t id;
    uint64_t data;
    uint8_t resp;
    uint8_t last;
} npu_mif_axi_r_entry_t;

typedef struct {
    npu_mif_cycle_config_t config;
    npu_mif_request_entry_t requests[NPU_MIF_MAX_REQUESTS];
    npu_mif_axi_entry_t axi_entries[NPU_MIF_MAX_AXI_OUTSTANDING];

    npu_mif_tbu_hold_t tbu_hold;
    npu_mif_response_hold_t rsp_hold[NPU_MIF_OWNER_COUNT];
    npu_mif_w_input_t w_input;
    npu_mif_w_hold_t w_hold;
    npu_mif_axi_b_entry_t b_entry;
    npu_mif_axi_r_entry_t r_entry;

    uint8_t aw_hold;
    uint8_t ar_hold;
    uint8_t write_fifo[NPU_MIF_MAX_AXI_OUTSTANDING];
    uint8_t write_fifo_head;
    uint8_t write_fifo_tail;
    uint8_t write_fifo_count;

    uint8_t next_axi_id;
    uint8_t request_rr_owner;
    uint8_t schedule_rr;
    uint8_t tbu_count;

    uint8_t first_error_valid;
    uint8_t first_error_status;
    uint8_t first_error_owner;
    uint16_t first_error_tag;
    uint16_t first_error_task_id;
    uint64_t first_error_vaddr;
    uint64_t first_error_paddr;
    uint8_t first_error_axi_id;
    uint8_t first_error_axi_id_valid;
    uint8_t first_error_axi_resp;

    uint8_t protocol_error_valid;
    uint8_t protocol_error_kind;
    uint64_t protocol_error_addr;
    uint8_t protocol_error_owner;
    uint16_t protocol_error_tag;
    uint8_t protocol_error_has_task_identity;
    uint16_t protocol_error_task_id;

    uint64_t cycle_count;
    uint64_t idle_cycles;
} npu_mif_cycle_t;

void npu_mif_cycle_config_default(npu_mif_cycle_config_t *config);

uint8_t npu_mif_cycle_config_valid(
    const npu_mif_cycle_config_t *config);

/*
 * Returns zero on success. An invalid configuration returns -1 without
 * changing model.
 */
int npu_mif_cycle_init(npu_mif_cycle_t *model,
                       const npu_mif_cycle_config_t *config);

void npu_mif_cycle_reset(npu_mif_cycle_t *model);

/*
 * outputs contains the pins visible during the current cycle. Handshakes are
 * applied to model state at the end of the call, so newly generated valid
 * signals are visible on the following call. Registered output payloads stay
 * unchanged for as long as their matching ready input is low.
 */
void npu_mif_cycle_step(npu_mif_cycle_t *model,
                        const npu_mif_cycle_inputs_t *inputs,
                        npu_mif_cycle_outputs_t *outputs);

uint8_t npu_mif_cycle_is_idle(const npu_mif_cycle_t *model);

#ifdef __cplusplus
}
#endif

#endif
