#ifndef NPU_AXI_MEM_TARGET_CYCLE_H
#define NPU_AXI_MEM_TARGET_CYCLE_H

#include "npu_gc_axi_cycle.h"
#include "npu_mif_cycle.h"

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_AXI_MEM_TARGET_DATA_BYTES 8u
#define NPU_AXI_MEM_TARGET_MAX_READS 16u
#define NPU_AXI_MEM_TARGET_MAX_WRITES 16u
#define NPU_AXI_MEM_TARGET_MAX_BURST_BEATS 16u
#define NPU_AXI_MEM_TARGET_MAX_INJECTIONS 32u
#define NPU_AXI_MEM_TARGET_INVALID_SLOT 0xffu

#define NPU_AXI_MEM_TARGET_DEFAULT_READ_LATENCY 20u
#define NPU_AXI_MEM_TARGET_DEFAULT_WRITE_LATENCY 12u

typedef enum {
    NPU_AXI_MEM_RESP_OKAY = 0,
    NPU_AXI_MEM_RESP_EXOKAY = 1,
    NPU_AXI_MEM_RESP_SLVERR = 2,
    NPU_AXI_MEM_RESP_DECERR = 3
} npu_axi_mem_resp_t;

typedef enum {
    NPU_AXI_MEM_PROTOCOL_NONE = 0,
    NPU_AXI_MEM_PROTOCOL_WLAST = 1
} npu_axi_mem_protocol_kind_t;

/*
 * Signals driven by an AXI master. The field names and widths are identical
 * to npu_mif_axi_outputs_t and npu_gc_axi_bus_outputs_t.
 */
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
} npu_axi_mem_master_outputs_t;

/*
 * Signals driven by the memory target. The field names and widths are
 * identical to npu_mif_axi_inputs_t and npu_gc_axi_bus_inputs_t.
 */
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
} npu_axi_mem_target_outputs_t;

typedef struct {
    uint32_t read_latency_cycles;
    uint32_t write_latency_cycles;
    uint8_t max_read_transactions;
    uint8_t max_write_transactions;
} npu_axi_mem_target_config_t;

/*
 * A rule matches the transaction start address and, when match_id is one,
 * its AXI ID. The first matching array entry supplies one response value and
 * additional first-response delay. A non-OKAY write rule suppresses all
 * memory writes for that transaction.
 */
typedef struct {
    uint8_t valid;
    uint8_t write;
    uint8_t match_id;
    uint8_t id;
    uint64_t addr;
    uint8_t resp;
    uint32_t extra_delay_cycles;
} npu_axi_mem_target_injection_t;

typedef struct {
    uint8_t reset_n;

    /*
     * These three independent controls force the corresponding ready low
     * for the current cycle. Zero is the normal operating value.
     */
    uint8_t pause_aw;
    uint8_t pause_w;
    uint8_t pause_ar;

    npu_axi_mem_master_outputs_t master;
} npu_axi_mem_target_cycle_inputs_t;

typedef struct {
    npu_axi_mem_target_outputs_t target;

    uint8_t read_outstanding;
    uint8_t write_outstanding;
    uint8_t idle;

    uint8_t protocol_error_valid;
    uint8_t protocol_error_kind;
    uint8_t protocol_error_id;

    uint64_t cycle;
} npu_axi_mem_target_cycle_outputs_t;

typedef struct {
    uint8_t valid;
    uint8_t id;
    uint8_t resp;
    uint16_t beats;
    uint16_t beat;
    uint64_t addr;
    uint64_t ready_cycle;
    uint64_t sequence;
} npu_axi_mem_target_read_t;

typedef struct {
    uint8_t valid;
    uint8_t id;
    uint8_t resp;
    uint8_t data_done;
    uint16_t beats;
    uint16_t beat;
    uint64_t addr;
    uint64_t b_ready_cycle;
    uint64_t sequence;
    uint32_t extra_delay_cycles;
} npu_axi_mem_target_write_t;

typedef struct {
    uint8_t valid;
    uint8_t slot;
    uint8_t id;
    uint8_t resp;
    uint8_t last;
    uint64_t data;
} npu_axi_mem_target_r_hold_t;

typedef struct {
    uint8_t valid;
    uint8_t slot;
    uint8_t id;
    uint8_t resp;
} npu_axi_mem_target_b_hold_t;

typedef struct {
    uint8_t *memory;
    size_t memory_bytes;
    uint64_t base_addr;
    npu_axi_mem_target_config_t config;
    npu_axi_mem_target_injection_t
        injection[NPU_AXI_MEM_TARGET_MAX_INJECTIONS];

    npu_axi_mem_target_read_t
        read[NPU_AXI_MEM_TARGET_MAX_READS];
    npu_axi_mem_target_write_t
        write[NPU_AXI_MEM_TARGET_MAX_WRITES];

    uint8_t write_order[NPU_AXI_MEM_TARGET_MAX_WRITES];
    uint8_t write_order_head;
    uint8_t write_order_tail;
    uint8_t write_order_count;

    uint8_t read_active_slot;
    npu_axi_mem_target_r_hold_t r_hold;
    npu_axi_mem_target_b_hold_t b_hold;

    uint8_t read_count;
    uint8_t write_count;
    uint8_t protocol_error_valid;
    uint8_t protocol_error_kind;
    uint8_t protocol_error_id;

    uint64_t next_sequence;
    uint64_t cycle;
    uint8_t initialized;
} npu_axi_mem_target_cycle_t;

void npu_axi_mem_target_config_reference(
    npu_axi_mem_target_config_t *config);

/*
 * memory remains caller-owned. base_addr is the AXI address corresponding
 * to memory[0]. Initialization does not alter memory contents.
 */
int npu_axi_mem_target_cycle_init(
    npu_axi_mem_target_cycle_t *model,
    uint8_t *memory,
    size_t memory_bytes,
    uint64_t base_addr,
    const npu_axi_mem_target_config_t *config);

/*
 * Reset discards all accepted transactions and response holds but preserves
 * memory, configuration, base address, and injection rules.
 */
void npu_axi_mem_target_cycle_reset(
    npu_axi_mem_target_cycle_t *model);

int npu_axi_mem_target_set_injection(
    npu_axi_mem_target_cycle_t *model,
    size_t index,
    const npu_axi_mem_target_injection_t *injection);

void npu_axi_mem_target_clear_injections(
    npu_axi_mem_target_cycle_t *model);

void npu_axi_mem_target_cycle_step(
    npu_axi_mem_target_cycle_t *model,
    const npu_axi_mem_target_cycle_inputs_t *inputs,
    npu_axi_mem_target_cycle_outputs_t *outputs);

void npu_axi_mem_target_cycle_eval(
    const npu_axi_mem_target_cycle_t *model,
    const npu_axi_mem_target_cycle_inputs_t *inputs,
    npu_axi_mem_target_cycle_outputs_t *outputs);

uint8_t npu_axi_mem_target_cycle_is_idle(
    const npu_axi_mem_target_cycle_t *model);

void npu_axi_mem_master_from_mif(
    npu_axi_mem_master_outputs_t *target,
    const npu_mif_axi_outputs_t *source);

void npu_axi_mem_target_to_mif(
    npu_mif_axi_inputs_t *target,
    const npu_axi_mem_target_outputs_t *source);

void npu_axi_mem_master_from_gc(
    npu_axi_mem_master_outputs_t *target,
    const npu_gc_axi_bus_outputs_t *source);

void npu_axi_mem_target_to_gc(
    npu_gc_axi_bus_inputs_t *target,
    const npu_axi_mem_target_outputs_t *source);

#ifdef __cplusplus
}
#endif

#endif
