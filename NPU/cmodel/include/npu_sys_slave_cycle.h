#ifndef NPU_SYS_SLAVE_CYCLE_H
#define NPU_SYS_SLAVE_CYCLE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_SYS_SLAVE_ADDR_MASK 0x00ffffffu
#define NPU_SYS_SLAVE_CSR_LIMIT 0x00010000u
#define NPU_SYS_SLAVE_DEBUG_BASE 0x00010000u
#define NPU_SYS_SLAVE_DEBUG_LIMIT 0x00020000u
#define NPU_SYS_SLAVE_L1_BASE 0x00100000u
#define NPU_SYS_SLAVE_L1_WINDOW_BYTES 0x00f00000u
#define NPU_SYS_SLAVE_DEFAULT_L1_BYTES (1024u * 1024u)
#define NPU_SYS_SLAVE_WORD_BYTES 8u
#define NPU_SYS_SLAVE_MAX_BEATS 256u

typedef enum {
    NPU_SYS_AXI_RESP_OKAY = 0,
    NPU_SYS_AXI_RESP_EXOKAY = 1,
    NPU_SYS_AXI_RESP_SLVERR = 2,
    NPU_SYS_AXI_RESP_DECERR = 3
} npu_sys_axi_response_t;

typedef enum {
    NPU_SYS_AXI_BURST_FIXED = 0,
    NPU_SYS_AXI_BURST_INCR = 1,
    NPU_SYS_AXI_BURST_WRAP = 2
} npu_sys_axi_burst_t;

typedef enum {
    NPU_SYS_L1_STATUS_OK = 0,
    NPU_SYS_L1_STATUS_ECC_CORRECTED = 1,
    NPU_SYS_L1_STATUS_ECC_UNCORRECTABLE = 2,
    NPU_SYS_L1_STATUS_PORT_PROTOCOL_ERROR = 3,
    NPU_SYS_L1_STATUS_ADDR_FAULT = 4
} npu_sys_l1_status_t;

typedef enum {
    NPU_SYS_TARGET_NONE = 0,
    NPU_SYS_TARGET_REG = 1,
    NPU_SYS_TARGET_L1 = 2,
    NPU_SYS_TARGET_RESERVED = 3,
    NPU_SYS_TARGET_ERROR = 4
} npu_sys_slave_target_t;

typedef enum {
    NPU_SYS_OWNER_NONE = 0,
    NPU_SYS_OWNER_READ = 1,
    NPU_SYS_OWNER_WRITE = 2
} npu_sys_slave_owner_t;

typedef struct {
    uint8_t core_reset_n;
    /* Debug CSR access is allowed while idle or explicitly frozen. */
    uint8_t core_idle_i;
    uint8_t debug_frozen_i;
    /* L1 diagnostic access requires both core_idle_i and this bit. */
    uint8_t l1_diag_enable_i;

    uint8_t s_axi_awid;
    uint32_t s_axi_awaddr;
    uint8_t s_axi_awlen;
    uint8_t s_axi_awsize;
    uint8_t s_axi_awburst;
    uint8_t s_axi_awlock;
    uint8_t s_axi_awcache;
    uint8_t s_axi_awprot;
    uint8_t s_axi_awqos;
    uint8_t s_axi_awvalid;

    uint64_t s_axi_wdata;
    uint8_t s_axi_wstrb;
    uint8_t s_axi_wlast;
    uint8_t s_axi_wvalid;
    uint8_t s_axi_bready;

    uint8_t s_axi_arid;
    uint32_t s_axi_araddr;
    uint8_t s_axi_arlen;
    uint8_t s_axi_arsize;
    uint8_t s_axi_arburst;
    uint8_t s_axi_arlock;
    uint8_t s_axi_arcache;
    uint8_t s_axi_arprot;
    uint8_t s_axi_arqos;
    uint8_t s_axi_arvalid;
    uint8_t s_axi_rready;

    uint8_t reg_req_ready_i;
    uint8_t reg_rsp_valid_i;
    uint64_t reg_rsp_rdata_i;
    uint8_t reg_rsp_status_i;

    uint8_t ssa_l1_req_ready_i;
    uint8_t ssa_l1_rsp_valid_i;
    uint64_t ssa_l1_rsp_rdata_i;
    uint8_t ssa_l1_rsp_status_i;
} npu_sys_slave_inputs_t;

typedef struct {
    uint8_t s_axi_awready;
    uint8_t s_axi_wready;
    uint8_t s_axi_bid;
    uint8_t s_axi_bresp;
    uint8_t s_axi_bvalid;

    uint8_t s_axi_arready;
    uint8_t s_axi_rid;
    uint64_t s_axi_rdata;
    uint8_t s_axi_rresp;
    uint8_t s_axi_rlast;
    uint8_t s_axi_rvalid;

    uint8_t reg_req_valid_o;
    uint8_t reg_req_write_o;
    uint8_t reg_req_space_o;
    uint16_t reg_req_addr_o;
    uint64_t reg_req_wdata_o;
    uint8_t reg_req_wstrb_o;
    uint8_t reg_rsp_ready_o;

    uint8_t ssa_l1_req_valid_o;
    uint8_t ssa_l1_req_write_o;
    uint32_t ssa_l1_req_addr_o;
    uint64_t ssa_l1_req_wdata_o;
    uint8_t ssa_l1_req_wstrb_o;
    uint8_t ssa_l1_rsp_ready_o;

    uint8_t idle;
    uint64_t cycle;
} npu_sys_slave_outputs_t;

typedef struct {
    uint8_t valid;
    uint8_t owner;
    uint8_t write;
    uint8_t space;
    uint32_t addr;
    uint64_t wdata;
    uint8_t wstrb;
} npu_sys_slave_internal_request_t;

typedef struct {
    uint8_t active;
    uint8_t id;
    uint32_t base_addr;
    uint8_t len;
    uint8_t size;
    uint8_t burst;
    uint8_t lock;
    uint8_t cache;
    uint8_t prot;
    uint8_t qos;
    uint8_t target;
    uint8_t reg_space;
    uint8_t error;
    uint16_t total_beats;
    uint16_t received_beats;
    uint16_t finished_beats;

    uint8_t beat_valid;
    uint16_t beat_index;
    uint64_t beat_data;
    uint8_t beat_strb;
    uint8_t beat_last;
} npu_sys_slave_write_state_t;

typedef struct {
    uint8_t active;
    uint8_t id;
    uint32_t base_addr;
    uint8_t len;
    uint8_t size;
    uint8_t burst;
    uint8_t lock;
    uint8_t cache;
    uint8_t prot;
    uint8_t qos;
    uint8_t target;
    uint8_t reg_space;
    uint8_t error;
    uint8_t decode_wait;
    uint16_t total_beats;
    uint16_t next_beat;
} npu_sys_slave_read_state_t;

typedef struct {
    uint32_t l1_bytes;
    uint64_t cycle;

    npu_sys_slave_write_state_t write;
    npu_sys_slave_read_state_t read;

    npu_sys_slave_internal_request_t reg_request;
    npu_sys_slave_internal_request_t l1_request;
    uint8_t reg_response_owner;
    uint8_t l1_response_owner;

    uint8_t bvalid;
    uint8_t bid;
    uint8_t bresp;

    uint8_t rvalid;
    uint8_t rid;
    uint64_t rdata;
    uint8_t rresp;
    uint8_t rlast;
} npu_sys_slave_cycle_t;

/*
 * l1_bytes must be nonzero, 8-byte aligned and no larger than the
 * 0xF00000-byte diagnostic window. The reference value is 1 MiB.
 */
int npu_sys_slave_cycle_init(npu_sys_slave_cycle_t *adapter,
                             uint32_t l1_bytes);

/*
 * Reset clears transactions and ready/valid state. It preserves l1_bytes.
 */
void npu_sys_slave_cycle_reset(npu_sys_slave_cycle_t *adapter);

/*
 * One call models one rising edge. Outputs describe the signals presented
 * during that cycle; accepted transfers change state for the next call.
 * For a narrow read, inactive RDATA lanes are driven to zero and selected
 * bytes remain in the lanes selected by the AXI address.
 */
void npu_sys_slave_cycle_step(npu_sys_slave_cycle_t *adapter,
                              const npu_sys_slave_inputs_t *inputs,
                              npu_sys_slave_outputs_t *outputs);

uint8_t npu_sys_slave_cycle_idle(
    const npu_sys_slave_cycle_t *adapter);

#ifdef __cplusplus
}
#endif

#endif
