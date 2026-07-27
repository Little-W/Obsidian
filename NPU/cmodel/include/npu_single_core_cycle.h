#ifndef NPU_SINGLE_CORE_CYCLE_H
#define NPU_SINGLE_CORE_CYCLE_H

#include "npu_control_cycle.h"
#include "npu_cfe_cycle.h"
#include "npu_engine_data_cycle.h"
#include "npu_gc_axi_cycle.h"
#include "npu_issue_adapter_cycle.h"
#include "npu_l1_diag_bridge.h"
#include "npu_lsc_cycle.h"
#include "npu_mif_cdc_cycle.h"
#include "npu_sys_slave_cycle.h"
#include "npu_tbu_cycle.h"
#include "npu_ts_cycle.h"

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * System co-simulation wrapper. It combines the single NPU with optional
 * external-host compatibility helpers. The issue and gc_axi members model
 * host-side traffic for existing tests and are not part of the NPU RTL.
 * system_axi is the NPU AXI Slave; MIF is the NPU AXI Master toward memory.
 */

/*
 * Module clock-enable bit positions. A busy module remains clocked even when
 * its requested bit is zero; npu_crg_cycle() implements that rule.
 */
#define NPU_SINGLE_CORE_CLK_CFE 0u
#define NPU_SINGLE_CORE_CLK_TS 1u
#define NPU_SINGLE_CORE_CLK_DMA 2u
#define NPU_SINGLE_CORE_CLK_ME 3u
#define NPU_SINGLE_CORE_CLK_IVE 4u
#define NPU_SINGLE_CORE_CLK_CME 5u
#define NPU_SINGLE_CORE_CLK_L1 6u
#define NPU_SINGLE_CORE_CLK_MIF 7u
#define NPU_SINGLE_CORE_CLK_ALL UINT8_C(0xff)
#define NPU_SINGLE_CORE_AXI_ID_COUNT 256u
#define NPU_SINGLE_CORE_STALE_WRITE_DEPTH 256u
#define NPU_SINGLE_CORE_STALE_TBU_COUNT \
    (NPU_MIF_MAX_TBU_OUTSTANDING + 1u)

typedef enum {
    NPU_SINGLE_CORE_TBU_EXTERNAL = 0,
    NPU_SINGLE_CORE_TBU_INTERNAL = 1
} npu_single_core_tbu_mode_t;

typedef enum {
    NPU_SINGLE_CORE_CMD_SOURCE_NONE = 0,
    NPU_SINGLE_CORE_CMD_SOURCE_ISSUE = 1,
    NPU_SINGLE_CORE_CMD_SOURCE_AXI = 2
} npu_single_core_cmd_source_t;

typedef struct {
    uint8_t core_rst_ni;
    uint8_t noc_rst_ni;
    uint8_t module_clk_en_i;
    uint8_t dvfs_prepare_req_i;
    uint8_t scan_mode_i;
    uint8_t stop_fetch_i;
    uint8_t clk_ack_i;

    uint8_t issue_valid_i;
    uint8_t issue_opcode_i;
    uint8_t issue_funct3_i;
    uint8_t issue_funct7_i;
    uint64_t issue_rs1_i;
    uint64_t issue_rs2_i;
    uint8_t issue_rd_i;
    uint8_t dsa_permission_i;
    uint8_t dsa_enable_i;
    uint8_t cpu_cancel_i;
    uint8_t issue_rsp_ready_i;

    /*
     * Only the external AXI pins, access-control inputs, and response-ready
     * fields of system_axi are consumed. Internal reg/L1 fields are driven by
     * this composition.
     */
    npu_sys_slave_inputs_t system_axi;

    /*
     * External-host compatibility helper used only by system co-simulation.
     * Only cache-side requests, response-ready inputs, and external AXI pins
     * are consumed. reset_n and quiesce are driven by this wrapper.
     */
    npu_gc_axi_cycle_inputs_t gc_axi;

    uint8_t soft_reset_req_i;
    uint8_t power_down_req_i;
    uint8_t core_wfi_i;

    uint8_t wdt_enable_i;
    uint32_t wdt_timeout_cycles_i;
    uint8_t wdt_kick_i;
} npu_single_core_cycle_core_inputs_t;

typedef struct {
    npu_crg_outputs_t crg;
    npu_wdt_outputs_t wdt;
    npu_issue_adapter_cycle_outputs_t issue;
    npu_sys_slave_outputs_t system_axi;
    npu_gc_axi_cycle_outputs_t gc_axi;
    npu_cfe_cycle_outputs_t cfe;
    npu_ts_cycle_outputs_t ts;
    npu_engine_data_cycle_outputs_t
        engine[NPU_TS_ENGINE_COUNT];
    npu_l1_diag_bridge_outputs_t l1_diag;
    npu_l1_cycle_outputs_t l1;
    npu_lsc_cycle_outputs_t lsc;
    npu_mif_cdc_core_outputs_t cdc;

    uint8_t core_reset_n;
    uint8_t module_clk_active_o;
    uint8_t effective_stop_fetch_o;
    uint8_t clk_req_o;
    uint8_t soft_reset_done_o;
    uint8_t power_down_ack_o;
    uint8_t wdt_reset_req_o;
    uint8_t core_idle_o;
    uint8_t irq_done_o;
    uint8_t irq_exception_o;
    uint8_t irq_error_o;
    uint8_t progress_pulse_o;
    uint64_t core_cycle;
} npu_single_core_cycle_core_outputs_t;

typedef struct {
    uint8_t core_rst_ni;
    uint8_t noc_rst_ni;
    uint8_t module_clk_en_i;
    uint8_t dvfs_prepare_req_i;
    uint8_t scan_mode_i;

    /* Consumed only when tbu_mode is EXTERNAL. */
    npu_mif_tbu_inputs_t tbu;
    npu_mif_axi_inputs_t axi;
} npu_single_core_cycle_noc_inputs_t;

typedef struct {
    npu_crg_outputs_t crg;
    npu_mif_cdc_noc_outputs_t cdc;
    npu_mif_cycle_outputs_t mif;
    npu_tbu_cycle_outputs_t tbu;

    uint8_t noc_reset_n;
    uint8_t module_clk_active_o;
    uint64_t noc_cycle;
} npu_single_core_cycle_noc_outputs_t;

/*
 * MIF diagnostics remain stable in the NoC domain until a clear event. This
 * packed snapshot passes through two Core-domain stages before LSC uses it.
 */
typedef struct {
    uint8_t first_valid;
    uint8_t first_status;
    uint8_t first_owner;
    uint16_t first_tag;
    uint16_t first_task_id;
    uint64_t first_vaddr;
    uint64_t first_paddr;
    uint8_t first_axi_id;
    uint8_t first_axi_id_valid;
    uint8_t first_axi_resp;

    uint8_t protocol_valid;
    uint8_t protocol_kind;
    uint64_t protocol_addr;
    uint8_t protocol_owner;
    uint16_t protocol_tag;
    uint8_t protocol_has_task_identity;
    uint16_t protocol_task_id;
} npu_single_core_mif_diag_t;

typedef struct {
    uint8_t axi_id;
    uint16_t beats_remaining;
} npu_single_core_stale_write_t;

typedef struct {
    npu_model_t *functional_model;
    npu_wire_limits_t wire_limits;

    npu_issue_adapter_cycle_t issue;
    uint8_t cmd_source;
    npu_cfe_cycle_t cfe;
    npu_ts_cycle_t ts;
    npu_engine_data_cycle_t engine[NPU_TS_ENGINE_COUNT];
    npu_lsc_cycle_t lsc;
    npu_sys_slave_cycle_t system_axi;
    npu_l1_diag_bridge_t l1_diag;
    npu_l1_cycle_t l1;
    npu_gc_axi_cycle_t gc_axi;
    npu_mif_cdc_cycle_t cdc;
    npu_mif_cycle_t mif;
    npu_tbu_cycle_t tbu;
    npu_crg_model_t crg;
    npu_wdt_model_t wdt;

    npu_mif_cycle_config_t mif_soc_config;
    npu_mif_cycle_config_t mif_config_core;
    npu_mif_cycle_config_t mif_config_sync0;
    npu_mif_cycle_config_t mif_config_sync1;

    npu_crg_outputs_t last_crg;
    npu_wdt_outputs_t last_wdt;
    uint8_t last_wdt_timeout_level;
    npu_mif_cycle_outputs_t last_mif;
    npu_lsc_cycle_outputs_t last_lsc;
    npu_perf_t last_functional_perf;
    uint64_t pending_int_saturate_count;
    uint64_t pending_all_mask_row_count;

    npu_single_core_mif_diag_t mif_diag_source;
    npu_single_core_mif_diag_t mif_diag_sync0;
    npu_single_core_mif_diag_t mif_diag_sync1;
    /*
     * Adds the issuing engine identity to the L1 controller's persistent
     * ECC payload. This record is captured when the L1 sticky status first
     * reaches the single-core composition and remains stable until clear.
     */
    npu_lsc_external_error_input_t l1_ecc_record;
    uint8_t mif_error_clear_toggle_core;
    uint8_t mif_error_clear_sync0_noc;
    uint8_t mif_error_clear_sync1_noc;
    uint8_t mif_error_clear_seen_noc;
    uint8_t mif_error_clear_ack_noc;
    uint8_t mif_error_clear_ack_sync0_core;
    uint8_t mif_error_clear_ack_sync1_core;
    uint8_t mif_error_clear_pending_core;

    uint8_t mif_soft_reset_toggle_core;
    uint8_t mif_soft_reset_sync0_noc;
    uint8_t mif_soft_reset_sync1_noc;
    uint8_t mif_soft_reset_seen_noc;
    uint8_t mif_soft_reset_ack_noc;
    uint8_t mif_soft_reset_ack_sync0_core;
    uint8_t mif_soft_reset_ack_sync1_core;
    uint8_t mif_soft_reset_pending_core;
    uint8_t mif_soft_reset_started_core;

    uint8_t mif_idle_source_noc;
    uint8_t mif_idle_sync0_core;
    uint8_t mif_idle_sync1_core;

    /*
     * Each domain consumes the CDC reset epoch only after the bridge's local
     * two-stage synchronizer exposes it. A Core-domain change terminates
     * transport-dependent TS work. A NoC-domain change resets MIF before the
     * bridge is released.
     */
    uint32_t cdc_reset_epoch_seen_core;
    uint32_t cdc_reset_epoch_seen_noc;

    /*
     * Responses from AXI or an external TBU can outlive a Core-only reset.
     * Their identifiers remain unavailable to new MIF transactions until
     * those old responses are accepted and discarded at the top-level gate.
     */
    uint8_t stale_axi_read_beats[NPU_SINGLE_CORE_AXI_ID_COUNT];
    uint8_t stale_axi_read_wait_rlast[NPU_SINGLE_CORE_AXI_ID_COUNT];
    uint8_t stale_axi_write_pending[NPU_SINGLE_CORE_AXI_ID_COUNT];
    npu_single_core_stale_write_t
        stale_axi_write_drain[NPU_SINGLE_CORE_STALE_WRITE_DEPTH];
    uint16_t stale_axi_write_drain_head;
    uint16_t stale_axi_write_drain_tail;
    uint16_t stale_axi_write_drain_count;
    uint16_t stale_tbu_tag[NPU_SINGLE_CORE_STALE_TBU_COUNT];
    uint8_t stale_tbu_tag_valid[NPU_SINGLE_CORE_STALE_TBU_COUNT];
    uint64_t stale_axi_read_drop_count;
    uint64_t stale_axi_write_drop_count;
    uint64_t stale_axi_w_drain_count;
    uint64_t stale_tbu_drop_count;

    /*
     * Generic Core AXI uses the Core clock but its target is not reset by a
     * Core-only reset. Old R/B responses and unfinished W streams are retained
     * here while the adapter itself starts again from reset state.
     */
    uint8_t stale_gc_axi_read_beats[NPU_SINGLE_CORE_AXI_ID_COUNT];
    uint8_t stale_gc_axi_read_wait_rlast
        [NPU_SINGLE_CORE_AXI_ID_COUNT];
    uint8_t stale_gc_axi_write_pending
        [NPU_SINGLE_CORE_AXI_ID_COUNT];
    npu_single_core_stale_write_t
        stale_gc_axi_write_drain[NPU_SINGLE_CORE_STALE_WRITE_DEPTH];
    uint16_t stale_gc_axi_write_drain_head;
    uint16_t stale_gc_axi_write_drain_tail;
    uint16_t stale_gc_axi_write_drain_count;
    uint64_t stale_gc_axi_read_drop_count;
    uint64_t stale_gc_axi_write_drop_count;
    uint64_t stale_gc_axi_w_drain_count;

    uint64_t last_engine_confirmed[NPU_TS_ENGINE_COUNT];
    uint64_t core_cycle;
    uint64_t noc_cycle;
    uint8_t tbu_mode;
    uint8_t initialized;
} npu_single_core_cycle_t;

/*
 * The functional model and L1 controller must use the same 1 MiB byte array.
 * The caller also owns the ECC array and all four trace workspaces.
 * mif_soc_config supplies the fixed system address and bypass ranges. LSC
 * subsequently supplies the system address range and TBU identifiers.
 *
 * tbu_mode is selected at initialization and is immutable for the lifetime
 * of this object. External mode consumes noc_inputs.tbu. Internal mode
 * ignores those pins and connects top->tbu to MIF; callers configure its
 * static test rules with npu_tbu_cycle_set_rule(&top->tbu, ...).
 *
 * All four workspace descriptions are validated before top, the ECC array,
 * or workspace storage is changed. A workspace validation failure returns
 * NPU_STATUS_BAD_DESC and preserves every caller-owned object. The complete
 * MIF SoC configuration is checked at the same point, including enable
 * encodings, aligned 40-bit range endpoints, range ordering, and AXI cache
 * fields.
 */
npu_status_t npu_single_core_cycle_init(
    npu_single_core_cycle_t *top,
    npu_model_t *functional_model,
    uint8_t *l1_memory,
    size_t l1_memory_bytes,
    uint8_t *l1_ecc,
    size_t l1_ecc_bytes,
    const npu_engine_data_workspace_t
        workspace[NPU_TS_ENGINE_COUNT],
    const npu_wire_limits_t *wire_limits,
    const npu_lsc_cycle_config_t *lsc_config,
    const npu_mif_cycle_config_t *mif_soc_config,
    npu_single_core_tbu_mode_t tbu_mode);

/*
 * Clears all sequential module state while preserving caller-owned memory,
 * ECC contents, workspace bindings, static configuration, and object
 * bindings. External reset assertion through either tick remains supported.
 */
void npu_single_core_cycle_reset(
    npu_single_core_cycle_t *top);

/*
 * Core and NoC clocks advance independently. Each call represents one rising
 * edge in the named domain. CDC pointers require two destination-domain ticks
 * before newly accepted data becomes visible.
 */
void npu_single_core_cycle_core_tick(
    npu_single_core_cycle_t *top,
    const npu_single_core_cycle_core_inputs_t *inputs,
    npu_single_core_cycle_core_outputs_t *outputs);

void npu_single_core_cycle_noc_tick(
    npu_single_core_cycle_t *top,
    const npu_single_core_cycle_noc_inputs_t *inputs,
    npu_single_core_cycle_noc_outputs_t *outputs);

#ifdef __cplusplus
}
#endif

#endif
