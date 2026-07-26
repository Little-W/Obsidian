#include "npu_l1_diag_bridge.h"
#include "npu_cmodel.h"

#include <string.h>

static uint8_t npu_l1_diag_bridge_status_valid(uint8_t status)
{
    return status <= (uint8_t)NPU_L1_STATUS_ADDR_FAULT;
}

static uint8_t npu_l1_diag_bridge_request_valid(
    const npu_l1_diag_bridge_inputs_t *inputs)
{
    return (uint8_t)(
        (inputs->req_addr_i &
         (uint32_t)(~NPU_L1_DIAG_BRIDGE_ADDR_MASK)) == 0u &&
        (inputs->req_addr_i &
         (NPU_L1_CYCLE_WORD_BYTES - 1u)) == 0u &&
        inputs->req_write_i <= 1u);
}

static uint8_t npu_l1_diag_bridge_task_status(uint8_t status)
{
    if (status == (uint8_t)NPU_L1_STATUS_ECC_UNCORRECTABLE) {
        return (uint8_t)NPU_STATUS_L1_ECC_UNCORRECTABLE;
    }
    if (status == (uint8_t)NPU_L1_STATUS_PORT_PROTOCOL_ERROR) {
        return (uint8_t)NPU_STATUS_BAD_DESC;
    }
    if (status == (uint8_t)NPU_L1_STATUS_ADDR_FAULT) {
        return (uint8_t)NPU_STATUS_ADDR_FAULT;
    }
    return (uint8_t)NPU_STATUS_SUCCESS;
}

static void npu_l1_diag_bridge_clear_error(
    npu_l1_diag_bridge_t *bridge)
{
    bridge->error_valid = 0u;
    bridge->error_status = 0u;
    bridge->error_addr = 0u;
    bridge->error_detail = 0u;
    bridge->error_write = 0u;
}

static void npu_l1_diag_bridge_record_error(
    npu_l1_diag_bridge_t *bridge,
    uint8_t detail)
{
    uint8_t status = npu_l1_diag_bridge_task_status(detail);

    if (status == (uint8_t)NPU_STATUS_SUCCESS ||
        bridge->error_valid != 0u) {
        return;
    }
    bridge->error_valid = 1u;
    bridge->error_status = status;
    bridge->error_addr = bridge->request_addr;
    bridge->error_detail = detail;
    bridge->error_write = bridge->request_write;
}

static void npu_l1_diag_bridge_make_response(
    npu_l1_diag_bridge_t *bridge,
    uint64_t rdata,
    uint8_t status)
{
    npu_l1_diag_bridge_record_error(bridge, status);
    bridge->response_rdata = rdata;
    bridge->response_status = status;
    bridge->state = NPU_L1_DIAG_BRIDGE_UPSTREAM_RESPONSE;
}

int npu_l1_diag_bridge_init(npu_l1_diag_bridge_t *bridge)
{
    if (bridge == (npu_l1_diag_bridge_t *)0) {
        return -1;
    }
    (void)memset(bridge, 0, sizeof(*bridge));
    bridge->state = NPU_L1_DIAG_BRIDGE_IDLE;
    return 0;
}

void npu_l1_diag_bridge_reset(npu_l1_diag_bridge_t *bridge)
{
    if (bridge == (npu_l1_diag_bridge_t *)0) {
        return;
    }
    (void)memset(bridge, 0, sizeof(*bridge));
    bridge->state = NPU_L1_DIAG_BRIDGE_IDLE;
}

uint8_t npu_l1_diag_bridge_idle(
    const npu_l1_diag_bridge_t *bridge)
{
    if (bridge == (const npu_l1_diag_bridge_t *)0) {
        return 0u;
    }
    return bridge->state == NPU_L1_DIAG_BRIDGE_IDLE ? 1u : 0u;
}

static void npu_l1_diag_bridge_fill_outputs(
    const npu_l1_diag_bridge_t *bridge,
    npu_l1_diag_bridge_outputs_t *outputs)
{
    (void)memset(outputs, 0, sizeof(*outputs));
    outputs->idle_o = npu_l1_diag_bridge_idle(bridge);
    outputs->cycle_o = bridge->cycle;
    outputs->error_valid_o = bridge->error_valid;
    outputs->error_status_o = bridge->error_status;
    outputs->error_addr_o = bridge->error_addr;
    outputs->error_detail_o = bridge->error_detail;
    outputs->error_write_o = bridge->error_write;

    switch (bridge->state) {
    case NPU_L1_DIAG_BRIDGE_IDLE:
        outputs->req_ready_o = 1u;
        break;
    case NPU_L1_DIAG_BRIDGE_READ_REQUEST:
        outputs->l1_read_o.req_valid = 1u;
        outputs->l1_read_o.req_addr = bridge->request_addr;
        outputs->l1_read_o.req_beats = 0u;
        outputs->l1_read_o.req_tag = bridge->request_tag;
        break;
    case NPU_L1_DIAG_BRIDGE_READ_RESPONSE:
        outputs->l1_read_o.rsp_ready = 1u;
        break;
    case NPU_L1_DIAG_BRIDGE_WRITE_REQUEST:
        outputs->l1_write_o.req_valid = 1u;
        outputs->l1_write_o.req_addr = bridge->request_addr;
        outputs->l1_write_o.req_beats = 0u;
        outputs->l1_write_o.req_tag = bridge->request_tag;
        break;
    case NPU_L1_DIAG_BRIDGE_WRITE_DATA:
        outputs->l1_write_o.data_valid = 1u;
        outputs->l1_write_o.data = bridge->request_wdata;
        outputs->l1_write_o.strb = bridge->request_wstrb;
        outputs->l1_write_o.last = 1u;
        break;
    case NPU_L1_DIAG_BRIDGE_WRITE_RESPONSE:
        outputs->l1_write_o.rsp_ready = 1u;
        break;
    case NPU_L1_DIAG_BRIDGE_UPSTREAM_RESPONSE:
        outputs->rsp_valid_o = 1u;
        outputs->rsp_rdata_o = bridge->response_rdata;
        outputs->rsp_status_o = bridge->response_status;
        break;
    default:
        break;
    }
}

void npu_l1_diag_bridge_step(
    npu_l1_diag_bridge_t *bridge,
    const npu_l1_diag_bridge_inputs_t *inputs,
    npu_l1_diag_bridge_outputs_t *outputs)
{
    if (bridge == (npu_l1_diag_bridge_t *)0 ||
        inputs == (const npu_l1_diag_bridge_inputs_t *)0 ||
        outputs == (npu_l1_diag_bridge_outputs_t *)0) {
        return;
    }

    if (inputs->reset_n == 0u) {
        npu_l1_diag_bridge_reset(bridge);
        (void)memset(outputs, 0, sizeof(*outputs));
        outputs->idle_o = 1u;
        return;
    }

    npu_l1_diag_bridge_fill_outputs(bridge, outputs);
    if (inputs->error_clear_i != 0u) {
        npu_l1_diag_bridge_clear_error(bridge);
    }

    switch (bridge->state) {
    case NPU_L1_DIAG_BRIDGE_IDLE:
        if (inputs->req_valid_i != 0u) {
            bridge->request_write =
                inputs->req_write_i != 0u ? 1u : 0u;
            bridge->request_addr = inputs->req_addr_i;
            if (npu_l1_diag_bridge_request_valid(inputs) == 0u) {
                npu_l1_diag_bridge_make_response(
                    bridge, 0u,
                    (uint8_t)
                        NPU_L1_STATUS_PORT_PROTOCOL_ERROR);
            } else {
                bridge->request_wdata = inputs->req_wdata_i;
                bridge->request_wstrb = inputs->req_wstrb_i;
                bridge->request_tag =
                    bridge->next_tag & NPU_L1_CYCLE_TAG_MASK;
                bridge->next_tag =
                    (uint16_t)((bridge->next_tag + 1u) &
                               NPU_L1_CYCLE_TAG_MASK);
                bridge->state =
                    inputs->req_write_i != 0u
                        ? NPU_L1_DIAG_BRIDGE_WRITE_REQUEST
                        : NPU_L1_DIAG_BRIDGE_READ_REQUEST;
            }
        }
        break;
    case NPU_L1_DIAG_BRIDGE_READ_REQUEST:
        if (inputs->l1_read_i.req_ready != 0u) {
            bridge->state = NPU_L1_DIAG_BRIDGE_READ_RESPONSE;
        }
        break;
    case NPU_L1_DIAG_BRIDGE_READ_RESPONSE:
        if (inputs->l1_read_i.rsp_valid != 0u) {
            uint8_t status = inputs->l1_read_i.rsp_status;
            uint64_t rdata = inputs->l1_read_i.rsp_data;

            if (inputs->l1_read_i.rsp_tag !=
                    bridge->request_tag ||
                inputs->l1_read_i.rsp_last == 0u ||
                npu_l1_diag_bridge_status_valid(status) == 0u) {
                status =
                    (uint8_t)NPU_L1_STATUS_PORT_PROTOCOL_ERROR;
                rdata = 0u;
            }
            npu_l1_diag_bridge_make_response(
                bridge, rdata, status);
        }
        break;
    case NPU_L1_DIAG_BRIDGE_WRITE_REQUEST:
        if (inputs->l1_write_i.req_ready != 0u) {
            bridge->state = NPU_L1_DIAG_BRIDGE_WRITE_DATA;
        }
        break;
    case NPU_L1_DIAG_BRIDGE_WRITE_DATA:
        if (inputs->l1_write_i.data_ready != 0u) {
            bridge->state = NPU_L1_DIAG_BRIDGE_WRITE_RESPONSE;
        }
        break;
    case NPU_L1_DIAG_BRIDGE_WRITE_RESPONSE:
        if (inputs->l1_write_i.rsp_valid != 0u) {
            uint8_t status = inputs->l1_write_i.rsp_status;

            if (inputs->l1_write_i.rsp_tag !=
                    bridge->request_tag ||
                npu_l1_diag_bridge_status_valid(status) == 0u) {
                status =
                    (uint8_t)NPU_L1_STATUS_PORT_PROTOCOL_ERROR;
            }
            npu_l1_diag_bridge_make_response(
                bridge, 0u, status);
        }
        break;
    case NPU_L1_DIAG_BRIDGE_UPSTREAM_RESPONSE:
        if (inputs->rsp_ready_i != 0u) {
            bridge->response_rdata = 0u;
            bridge->response_status = 0u;
            bridge->state = NPU_L1_DIAG_BRIDGE_IDLE;
        }
        break;
    default:
        npu_l1_diag_bridge_reset(bridge);
        break;
    }
    bridge->cycle++;
}
