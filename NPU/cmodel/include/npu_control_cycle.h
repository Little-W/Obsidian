#ifndef NPU_CONTROL_CYCLE_H
#define NPU_CONTROL_CYCLE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_CRG_MODULE_COUNT 8u

typedef struct {
    uint8_t core_clk_i;
    uint8_t noc_clk_i;
    uint8_t core_rst_ni;
    uint8_t noc_rst_ni;
    uint8_t dvfs_prepare_req_i;
    uint8_t core_idle_i;
    uint8_t axi_idle_i;
    uint8_t module_clk_en_i;
    uint8_t module_idle_i;
} npu_crg_inputs_t;

typedef struct {
    uint8_t dvfs_prepare_ack_o;
    /* Per-module local-ICG enables after busy-module forcing. */
    uint8_t module_clk_active_o;
    /* Aggregate domain observations, not individual module clocks. */
    uint8_t core_clk_gated_o;
    uint8_t noc_clk_gated_o;
    uint8_t core_reset_n;
    uint8_t noc_reset_n;
} npu_crg_outputs_t;

typedef struct {
    uint8_t core_sync0;
    uint8_t core_sync1;
    uint8_t noc_sync0;
    uint8_t noc_sync1;
    uint8_t module_clk_active;
} npu_crg_model_t;

void npu_crg_reset(npu_crg_model_t *model);
void npu_crg_cycle(npu_crg_model_t *model,
                   const npu_crg_inputs_t *inputs,
                   npu_crg_outputs_t *outputs);

typedef struct {
    uint8_t reset_n;
    uint8_t enable;
    uint8_t kick;
    uint8_t core_progress;
    uint32_t timeout_cycles;
} npu_wdt_inputs_t;

typedef struct {
    uint8_t timeout;
    uint8_t reset_req;
    uint32_t count;
} npu_wdt_outputs_t;

typedef struct {
    uint32_t count;
    uint8_t timeout;
} npu_wdt_model_t;

void npu_wdt_reset(npu_wdt_model_t *model);
void npu_wdt_cycle(npu_wdt_model_t *model,
                   const npu_wdt_inputs_t *inputs,
                   npu_wdt_outputs_t *outputs);

#ifdef __cplusplus
}
#endif

#endif
