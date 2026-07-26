#ifndef NPU_L1_DIAG_BRIDGE_H
#define NPU_L1_DIAG_BRIDGE_H

#include <stdint.h>

#include "npu_l1_cycle.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_L1_DIAG_BRIDGE_ADDR_MASK UINT32_C(0x00ffffff)

typedef enum {
    NPU_L1_DIAG_BRIDGE_IDLE = 0,
    NPU_L1_DIAG_BRIDGE_READ_REQUEST = 1,
    NPU_L1_DIAG_BRIDGE_READ_RESPONSE = 2,
    NPU_L1_DIAG_BRIDGE_WRITE_REQUEST = 3,
    NPU_L1_DIAG_BRIDGE_WRITE_DATA = 4,
    NPU_L1_DIAG_BRIDGE_WRITE_RESPONSE = 5,
    NPU_L1_DIAG_BRIDGE_UPSTREAM_RESPONSE = 6
} npu_l1_diag_bridge_state_t;

/*
 * req_* is the single-beat request interface from the System Slave Adapter.
 * l1_read_i and l1_write_i are the outputs of the L1 debug ports.
 */
typedef struct {
    uint8_t reset_n;
    /* Clears the persistent diagnostic-failure record at this rising edge. */
    uint8_t error_clear_i;

    uint8_t req_valid_i;
    uint8_t req_write_i;
    uint32_t req_addr_i;
    uint64_t req_wdata_i;
    uint8_t req_wstrb_i;
    uint8_t rsp_ready_i;

    npu_l1_cycle_read_output_t l1_read_i;
    npu_l1_cycle_write_output_t l1_write_i;
} npu_l1_diag_bridge_inputs_t;

/*
 * rsp_* returns one response to the System Slave Adapter.
 * l1_read_o and l1_write_o directly drive NPU_L1_RD_DEBUG and
 * NPU_L1_WR_DEBUG respectively.
 */
typedef struct {
    uint8_t req_ready_o;
    uint8_t rsp_valid_o;
    uint64_t rsp_rdata_o;
    uint8_t rsp_status_o;

    npu_l1_cycle_read_input_t l1_read_o;
    npu_l1_cycle_write_input_t l1_write_o;

    uint8_t error_valid_o;
    uint8_t error_status_o;
    uint32_t error_addr_o;
    uint8_t error_detail_o;
    uint8_t error_write_o;

    uint8_t idle_o;
    uint64_t cycle_o;
} npu_l1_diag_bridge_outputs_t;

typedef struct {
    npu_l1_diag_bridge_state_t state;

    uint8_t request_write;
    uint32_t request_addr;
    uint64_t request_wdata;
    uint8_t request_wstrb;
    uint16_t request_tag;
    uint16_t next_tag;

    uint64_t response_rdata;
    uint8_t response_status;

    uint8_t error_valid;
    uint8_t error_status;
    uint32_t error_addr;
    uint8_t error_detail;
    uint8_t error_write;

    uint64_t cycle;
} npu_l1_diag_bridge_t;

int npu_l1_diag_bridge_init(npu_l1_diag_bridge_t *bridge);
void npu_l1_diag_bridge_reset(npu_l1_diag_bridge_t *bridge);
uint8_t npu_l1_diag_bridge_idle(
    const npu_l1_diag_bridge_t *bridge);

void npu_l1_diag_bridge_step(
    npu_l1_diag_bridge_t *bridge,
    const npu_l1_diag_bridge_inputs_t *inputs,
    npu_l1_diag_bridge_outputs_t *outputs);

#ifdef __cplusplus
}
#endif

#endif
