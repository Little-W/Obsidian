#include "npu_control_cycle.h"

void npu_crg_reset(npu_crg_model_t *model)
{
    if (model == (npu_crg_model_t *)0) {
        return;
    }
    model->core_sync0 = 0u;
    model->core_sync1 = 0u;
    model->noc_sync0 = 0u;
    model->noc_sync1 = 0u;
    model->module_clk_active = 0xffu;
}

void npu_crg_cycle(npu_crg_model_t *model,
                   const npu_crg_inputs_t *inputs,
                   npu_crg_outputs_t *outputs)
{
    uint8_t requested;
    uint8_t forced_on;
    uint8_t core_modules;

    if (model == (npu_crg_model_t *)0 ||
        inputs == (const npu_crg_inputs_t *)0 ||
        outputs == (npu_crg_outputs_t *)0) {
        return;
    }

    if (inputs->core_rst_ni == 0u) {
        model->core_sync0 = 0u;
        model->core_sync1 = 0u;
    } else if (inputs->core_clk_i != 0u) {
        model->core_sync1 = model->core_sync0;
        model->core_sync0 = 1u;
    }
    if (inputs->noc_rst_ni == 0u) {
        model->noc_sync0 = 0u;
        model->noc_sync1 = 0u;
    } else if (inputs->noc_clk_i != 0u) {
        model->noc_sync1 = model->noc_sync0;
        model->noc_sync0 = 1u;
    }

    requested = inputs->module_clk_en_i;
    forced_on = (uint8_t)~inputs->module_idle_i;
    if (inputs->core_clk_i == 0u) {
        model->module_clk_active =
            (uint8_t)((model->module_clk_active & 0x80u) |
                      ((requested | forced_on) & 0x7fu));
    }
    if (inputs->noc_clk_i == 0u) {
        model->module_clk_active =
            (uint8_t)((model->module_clk_active & 0x7fu) |
                      ((requested | forced_on) & 0x80u));
    }
    core_modules = (uint8_t)(model->module_clk_active & 0x7fu);

    outputs->core_reset_n = model->core_sync1;
    outputs->noc_reset_n = model->noc_sync1;
    outputs->module_clk_active_o = model->module_clk_active;
    outputs->core_clk_gated_o =
        (uint8_t)(inputs->core_clk_i != 0u &&
                  core_modules != 0u &&
                  model->core_sync1 != 0u);
    outputs->noc_clk_gated_o =
        (uint8_t)(inputs->noc_clk_i != 0u &&
                  (model->module_clk_active & 0x80u) != 0u &&
                  model->noc_sync1 != 0u);
    outputs->dvfs_prepare_ack_o =
        (uint8_t)(inputs->dvfs_prepare_req_i != 0u &&
                  inputs->core_idle_i != 0u &&
                  inputs->axi_idle_i != 0u);
}

void npu_wdt_reset(npu_wdt_model_t *model)
{
    if (model == (npu_wdt_model_t *)0) {
        return;
    }
    model->count = 0u;
    model->timeout = 0u;
}

void npu_wdt_cycle(npu_wdt_model_t *model,
                   const npu_wdt_inputs_t *inputs,
                   npu_wdt_outputs_t *outputs)
{
    if (model == (npu_wdt_model_t *)0 ||
        inputs == (const npu_wdt_inputs_t *)0 ||
        outputs == (npu_wdt_outputs_t *)0) {
        return;
    }

    if (inputs->reset_n == 0u || inputs->enable == 0u) {
        npu_wdt_reset(model);
    } else if (inputs->kick != 0u ||
               inputs->core_progress != 0u) {
        model->count = 0u;
        model->timeout = 0u;
    } else if (model->timeout == 0u &&
               inputs->timeout_cycles != 0u) {
        if (model->count < inputs->timeout_cycles) {
            model->count++;
        }
        if (model->count >= inputs->timeout_cycles) {
            model->timeout = 1u;
        }
    }

    outputs->timeout = model->timeout;
    outputs->reset_req = model->timeout;
    outputs->count = model->count;
}
