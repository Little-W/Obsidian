#ifndef NPU_CMODEL_EXAMPLES_DRIVER_BACKEND_H
#define NPU_CMODEL_EXAMPLES_DRIVER_BACKEND_H

#include "npu_cmodel.h"
#include "npu_driver.h"

#include <stddef.h>
#include <stdint.h>

typedef struct {
    /*
     * Functional-model adapter for driver E2E tests. AXI AW/W/B and AR/R
     * timing is covered by npu_sys_slave_cycle tests; this adapter receives
     * one already-formed fixed burst and forwards its command pairs.
     */
    npu_model_t model;
    uint32_t cache_clean_calls;
    uint32_t cache_invalidate_calls;
    uint32_t submitted_bursts;
    uint32_t submitted_beats;
    uint32_t responses;
    uint64_t pending_response[
        NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    size_t pending_response_head;
    size_t pending_response_count;
} npu_example_cmodel_backend_t;

int npu_example_cmodel_backend_init(
    npu_example_cmodel_backend_t *backend,
    uint8_t *l1,
    size_t l1_bytes,
    uint8_t *system_memory,
    size_t system_memory_bytes);

npu_drv_platform_ops_t
npu_example_cmodel_backend_operations(
    npu_example_cmodel_backend_t *backend);

#endif
