#ifndef NPU_CORE_TOP_CYCLE_H
#define NPU_CORE_TOP_CYCLE_H

#include "npu_cfe_cycle.h"
#include "npu_engine_cycle.h"
#include "npu_lsc_cycle.h"
#include "npu_ts_cycle.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Control/scheduling-side NPU composition:
 *
 *   AXI Slave command window -> CFE -> TS -> four Engine Adapters
 *                                      \-> Descriptor SRAM read ports
 *   AXI Slave control window ---------> TS / LSC
 *   TS terminal notice ---------------> LSC
 *
 * The four Engine Adapters share the supplied functional npu_model_t.
 * Their current execution model invokes one functional operator on the final
 * EXECUTE edge. L1 and DDR changes become visible together on that edge.
 * This composition intentionally does not invent per-beat Engine L1/MIF data
 * ports; those ports require a separate data-side cycle model.
 *
 * Historical gc_cmd/gc_ctl field names denote signals after the AXI Slave
 * windows. They do not place a Generic Core inside the NPU.
 */

typedef struct {
    uint8_t reset_n;

    uint8_t gc_cmd_valid_i;
    uint64_t gc_cmd_data_i;
    uint8_t gc_cmd_first_i;
    uint8_t gc_cmd_last_i;
    uint8_t gc_rsp_ready_i;

    uint8_t gc_ctl_valid_i;
    uint8_t gc_ctl_op_i;
    uint64_t gc_ctl_rs1_i;
    uint64_t gc_ctl_rs2_i;
    uint8_t gc_ctl_cancel_i;
    uint8_t gc_ctl_rsp_ready_i;

    uint8_t reg_req_valid_i;
    uint8_t reg_req_write_i;
    uint8_t reg_req_space_i;
    uint16_t reg_req_addr_i;
    uint64_t reg_req_wdata_i;
    uint8_t reg_req_wstrb_i;
    uint8_t reg_rsp_ready_i;

    uint8_t df_mem_req_ready_i;
    uint8_t df_mem_rsp_valid_i;
    uint64_t df_mem_rsp_data_i;
    uint16_t df_mem_rsp_tag_i;
    uint8_t df_mem_rsp_last_i;
    uint8_t df_mem_rsp_status_i;

    uint8_t soft_reset_req_i;
    uint8_t power_down_req_i;
    uint8_t core_wfi_i;
    uint8_t l1_idle_i;
    uint8_t l1_write_idle_i;
    uint8_t mif_idle_i;
    uint8_t gc_axi_idle_i;
    uint8_t wdt_timeout_i;
    uint64_t perf_increment_i[NPU_LSC_PERF_COUNTER_COUNT];
} npu_core_top_cycle_inputs_t;

typedef struct {
    uint8_t gc_cmd_ready_o;
    uint8_t gc_rsp_valid_o;
    uint64_t gc_rsp_data_o;

    uint8_t gc_ctl_ready_o;
    uint8_t gc_ctl_rsp_valid_o;
    uint64_t gc_ctl_rsp_data_o;

    uint8_t reg_req_ready_o;
    uint8_t reg_rsp_valid_o;
    uint64_t reg_rsp_rdata_o;
    uint8_t reg_rsp_status_o;

    uint8_t df_mem_req_valid_o;
    uint64_t df_mem_req_addr_o;
    uint8_t df_mem_req_beats_o;
    uint16_t df_mem_req_tag_o;
    uint16_t df_mem_req_task_id_o;
    uint8_t df_mem_req_attr_o;
    uint8_t df_mem_rsp_ready_o;

    uint8_t cfe_quiesce_o;
    uint8_t ts_quiesce_o;
    uint8_t eng_abort_o;
    uint8_t stop_fetch_o;
    uint8_t single_step_pulse_o;
    uint8_t internal_soft_reset_pulse_o;
    uint8_t soft_reset_done_o;
    uint8_t power_down_ack_o;
    uint8_t core_idle_o;
    uint8_t irq_done_o;
    uint8_t irq_exception_o;
    uint8_t irq_error_o;

    uint8_t cfe_idle_o;
    uint8_t ts_idle_o;
    uint8_t ts_quiescent_o;
    uint8_t eng_quiescent_o;
    uint8_t eng_busy_o;

    /*
     * Module outputs sampled from the same pre-edge state. These records are
     * exposed for signal-level checking; all connected modules still commit
     * exactly once in npu_core_top_cycle_step().
     */
    npu_cfe_cycle_outputs_t cfe;
    npu_ts_cycle_outputs_t ts;
    npu_engine_cycle_outputs_t engine[NPU_TS_ENGINE_COUNT];
    npu_lsc_cycle_outputs_t lsc;

    uint64_t cycle;
} npu_core_top_cycle_outputs_t;

typedef struct {
    npu_model_t *functional_model;
    npu_wire_limits_t wire_limits;

    npu_cfe_cycle_t cfe;
    npu_ts_cycle_t ts;
    npu_engine_cycle_t engine[NPU_TS_ENGINE_COUNT];
    npu_lsc_cycle_t lsc;

    uint64_t cycle;
    uint8_t initialized;
} npu_core_top_cycle_t;

npu_status_t npu_core_top_cycle_init(
    npu_core_top_cycle_t *top,
    npu_model_t *functional_model,
    const npu_wire_limits_t *wire_limits,
    const npu_lsc_cycle_config_t *lsc_config);

/*
 * Clears the control/scheduling modules while retaining the functional-model
 * binding, wire limits, LSC configuration, and L1/DDR contents.
 */
void npu_core_top_cycle_reset(npu_core_top_cycle_t *top);

/*
 * Models one rising Core clock edge. All ready/valid values are evaluated
 * from one shared pre-edge snapshot. Every contained module then commits one
 * and only one state transition with those values.
 */
void npu_core_top_cycle_step(
    npu_core_top_cycle_t *top,
    const npu_core_top_cycle_inputs_t *inputs,
    npu_core_top_cycle_outputs_t *outputs);

#ifdef __cplusplus
}
#endif

#endif
