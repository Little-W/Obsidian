#include "npu_single_core_cycle.h"
#include "npu_capability_internal.h"

#include <string.h>

static void single_eval_issue(
    const npu_issue_adapter_cycle_t *model,
    const npu_issue_adapter_cycle_inputs_t *inputs,
    npu_issue_adapter_cycle_outputs_t *outputs)
{
    npu_issue_adapter_cycle_t preview = *model;

    npu_issue_adapter_cycle_step(&preview, inputs, outputs);
}

static void single_eval_cfe(
    const npu_cfe_cycle_t *model,
    const npu_cfe_cycle_inputs_t *inputs,
    npu_cfe_cycle_outputs_t *outputs)
{
    npu_cfe_cycle_t preview = *model;

    npu_cfe_cycle_step(&preview, inputs, outputs);
}

static void single_eval_ts(
    const npu_ts_cycle_t *model,
    const npu_ts_cycle_inputs_t *inputs,
    npu_ts_cycle_outputs_t *outputs)
{
    npu_ts_cycle_t preview = *model;

    npu_ts_cycle_step(&preview, inputs, outputs);
}

static void single_eval_lsc(
    const npu_lsc_cycle_t *model,
    const npu_lsc_cycle_inputs_t *inputs,
    npu_lsc_cycle_outputs_t *outputs)
{
    npu_lsc_cycle_t preview = *model;

    npu_lsc_cycle_step(&preview, inputs, outputs);
}

static void single_eval_system(
    const npu_sys_slave_cycle_t *model,
    const npu_sys_slave_inputs_t *inputs,
    npu_sys_slave_outputs_t *outputs)
{
    npu_sys_slave_cycle_t preview = *model;

    npu_sys_slave_cycle_step(&preview, inputs, outputs);
}

static void single_eval_diag(
    const npu_l1_diag_bridge_t *model,
    const npu_l1_diag_bridge_inputs_t *inputs,
    npu_l1_diag_bridge_outputs_t *outputs)
{
    npu_l1_diag_bridge_t preview = *model;

    npu_l1_diag_bridge_step(&preview, inputs, outputs);
}

static void single_eval_gc_axi(
    const npu_gc_axi_cycle_t *model,
    const npu_gc_axi_cycle_inputs_t *inputs,
    npu_gc_axi_cycle_outputs_t *outputs)
{
    npu_gc_axi_cycle_t preview = *model;

    npu_gc_axi_cycle_step(&preview, inputs, outputs);
}

static void single_eval_cdc_noc(
    const npu_mif_cdc_cycle_t *model,
    const npu_mif_cdc_noc_inputs_t *inputs,
    npu_mif_cdc_noc_outputs_t *outputs)
{
    npu_mif_cdc_cycle_t preview = *model;

    npu_mif_cdc_noc_tick(&preview, inputs, outputs);
}

static void single_eval_mif(
    const npu_mif_cycle_t *model,
    const npu_mif_cycle_inputs_t *inputs,
    npu_mif_cycle_outputs_t *outputs)
{
    npu_mif_cycle_t preview = *model;

    npu_mif_cycle_step(&preview, inputs, outputs);
}

static void single_eval_tbu(
    const npu_tbu_cycle_t *model,
    const npu_tbu_cycle_inputs_t *inputs,
    npu_tbu_cycle_outputs_t *outputs)
{
    npu_tbu_cycle_t preview = *model;

    npu_tbu_cycle_step(&preview, inputs, outputs);
}

static uint8_t single_popcount8(uint8_t value)
{
    uint8_t count = 0u;

    while (value != 0u) {
        count += (uint8_t)(value & 1u);
        value >>= 1u;
    }
    return count;
}

static uint8_t single_engine_quiescent(
    const npu_engine_data_cycle_t *engine)
{
    return engine->data_pending == 0u &&
                   npu_engine_cycle_quiescent(&engine->engine) != 0u
               ? 1u
               : 0u;
}

static uint8_t single_engine_mask_quiescent(
    const npu_engine_data_cycle_t
        engine[NPU_TS_ENGINE_COUNT])
{
    uint8_t mask = 0u;
    uint32_t index;

    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        if (single_engine_quiescent(&engine[index]) != 0u) {
            mask |= (uint8_t)(1u << index);
        }
    }
    return mask;
}

static uint8_t single_cdc_core_idle(
    const npu_mif_cdc_cycle_t *cdc)
{
    uint32_t owner;

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        const npu_mif_cdc_fifo_control_t *req =
            &cdc->req_fifo[owner].control;
        const npu_mif_cdc_fifo_control_t *write =
            &cdc->w_fifo[owner].control;
        const npu_mif_cdc_fifo_control_t *response =
            &cdc->rsp_fifo[owner].control;

        if (req->write_seq !=
                req->read_seq_at_writer[
                    NPU_MIF_CDC_SYNC_STAGES - 1u] ||
            write->write_seq !=
                write->read_seq_at_writer[
                    NPU_MIF_CDC_SYNC_STAGES - 1u] ||
            response->read_seq !=
                response->write_seq_at_reader[
                    NPU_MIF_CDC_SYNC_STAGES - 1u]) {
            return 0u;
        }
    }
    return 1u;
}

static uint8_t single_cdc_noc_idle(
    const npu_mif_cdc_cycle_t *cdc)
{
    uint32_t owner;

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        const npu_mif_cdc_fifo_control_t *req =
            &cdc->req_fifo[owner].control;
        const npu_mif_cdc_fifo_control_t *write =
            &cdc->w_fifo[owner].control;
        const npu_mif_cdc_fifo_control_t *response =
            &cdc->rsp_fifo[owner].control;

        if (req->read_seq !=
                req->write_seq_at_reader[
                    NPU_MIF_CDC_SYNC_STAGES - 1u] ||
            write->read_seq !=
                write->write_seq_at_reader[
                    NPU_MIF_CDC_SYNC_STAGES - 1u] ||
            response->write_seq !=
                response->read_seq_at_writer[
                    NPU_MIF_CDC_SYNC_STAGES - 1u]) {
            return 0u;
        }
    }
    return 1u;
}

static uint8_t single_internal_tbu_idle(
    const npu_single_core_cycle_t *top)
{
    npu_tbu_cycle_inputs_t inputs;
    npu_tbu_cycle_outputs_t outputs;

    if (top->tbu_mode != NPU_SINGLE_CORE_TBU_INTERNAL) {
        return 1u;
    }
    (void)memset(&inputs, 0, sizeof(inputs));
    inputs.reset_n = 1u;
    npu_tbu_cycle_eval(&top->tbu, &inputs, &outputs);
    return outputs.idle;
}

static uint8_t single_clock_active(uint8_t active_mask,
                                   uint8_t bit)
{
    return (uint8_t)((active_mask >> bit) & 1u);
}

static void single_gate_cfe_outputs(
    const npu_cfe_cycle_t *model,
    npu_cfe_cycle_outputs_t *outputs)
{
    (void)memset(outputs, 0, sizeof(*outputs));
    outputs->cfe_idle_o = npu_cfe_cycle_idle(model);
}

static void single_gate_ts_outputs(
    const npu_ts_cycle_t *model,
    npu_ts_cycle_outputs_t *outputs)
{
    uint8_t idle =
        npu_ts_cycle_idle(model) != 0 ? 1u : 0u;

    (void)memset(outputs, 0, sizeof(*outputs));
    outputs->idle = idle;
    outputs->quiescent = idle;
    outputs->cycle = model->cycle;
}

static void single_gate_engine_outputs(
    const npu_engine_data_cycle_t *model,
    npu_engine_data_cycle_outputs_t *outputs)
{
    (void)memset(outputs, 0, sizeof(*outputs));
    outputs->engine.eng_quiescent_o = 1u;
    outputs->data_quiescent = 1u;
    outputs->dma_idle =
        model->engine.engine == NPU_ENGINE_DMA ? 1u : 0u;
    outputs->cycle = model->cycle;
}

static void single_gate_l1_outputs(
    const npu_l1_cycle_t *model,
    npu_l1_cycle_outputs_t *outputs)
{
    (void)memset(outputs, 0, sizeof(*outputs));
    outputs->idle = 1u;
    outputs->write_idle = 1u;
    outputs->ecc_error_valid = model->ecc_error_valid;
    outputs->ecc_error_status = model->ecc_error_status;
    outputs->ecc_error_addr = model->ecc_error_addr;
    outputs->ecc_error_port = model->ecc_error_port;
    outputs->ecc_error_bank = model->ecc_error_bank;
    outputs->ecc_error_write = model->ecc_error_write;
    outputs->cycle = model->cycle;
}

static void single_gate_mif_outputs(
    const npu_mif_cycle_t *model,
    npu_mif_cycle_outputs_t *outputs)
{
    (void)memset(outputs, 0, sizeof(*outputs));
    outputs->mif_idle = 1u;
    outputs->cycle_count = model->cycle_count;
    outputs->idle_cycles = model->idle_cycles;
}

static uint8_t single_stale_mif_transport_idle(
    const npu_single_core_cycle_t *top)
{
    uint32_t port;
    uint32_t id;
    uint32_t index;

    if (top->stale_axi_write_drain_count != 0u) {
        return 0u;
    }
    for (port = 0u; port < NPU_MIF_AXI_PORT_COUNT; port++) {
        for (id = 0u; id < NPU_SINGLE_CORE_AXI_ID_COUNT; id++) {
            if (top->stale_axi_read_beats[port][id] != 0u ||
                top->stale_axi_read_wait_rlast[port][id] != 0u ||
                top->stale_axi_write_pending[port][id] != 0u) {
                return 0u;
            }
        }
    }
    for (index = 0u;
         index < NPU_SINGLE_CORE_STALE_TBU_COUNT;
         index++) {
        if (top->stale_tbu_tag_valid[index] != 0u) {
            return 0u;
        }
    }
    return 1u;
}

static uint8_t single_stale_gc_transport_idle(
    const npu_single_core_cycle_t *top)
{
    uint32_t id;

    if (top->stale_gc_axi_write_drain_count != 0u) {
        return 0u;
    }
    for (id = 0u; id < NPU_SINGLE_CORE_AXI_ID_COUNT; id++) {
        if (top->stale_gc_axi_read_beats[id] != 0u ||
            top->stale_gc_axi_read_wait_rlast[id] != 0u ||
            top->stale_gc_axi_write_pending[id] != 0u) {
            return 0u;
        }
    }
    return 1u;
}

static uint8_t single_module_idle_mask(
    const npu_single_core_cycle_t *top)
{
    uint8_t mask = 0u;

    if (npu_cfe_cycle_idle(&top->cfe) != 0u) {
        mask |= (uint8_t)(1u << NPU_SINGLE_CORE_CLK_CFE);
    }
    if (npu_ts_cycle_idle(&top->ts) != 0) {
        mask |= (uint8_t)(1u << NPU_SINGLE_CORE_CLK_TS);
    }
    if (single_engine_quiescent(&top->engine[0]) != 0u) {
        mask |= (uint8_t)(1u << NPU_SINGLE_CORE_CLK_DMA);
    }
    if (single_engine_quiescent(&top->engine[1]) != 0u) {
        mask |= (uint8_t)(1u << NPU_SINGLE_CORE_CLK_ME);
    }
    if (single_engine_quiescent(&top->engine[2]) != 0u) {
        mask |= (uint8_t)(1u << NPU_SINGLE_CORE_CLK_IVE);
    }
    if (single_engine_quiescent(&top->engine[3]) != 0u) {
        mask |= (uint8_t)(1u << NPU_SINGLE_CORE_CLK_CME);
    }
    if (npu_l1_cycle_idle(&top->l1) != 0u &&
        single_engine_mask_quiescent(top->engine) == 0x0fu &&
        npu_l1_diag_bridge_idle(&top->l1_diag) != 0u) {
        mask |= (uint8_t)(1u << NPU_SINGLE_CORE_CLK_L1);
    }
    if (npu_mif_cycle_is_idle(&top->mif) != 0u &&
        single_cdc_noc_idle(&top->cdc) != 0u &&
        single_internal_tbu_idle(top) != 0u &&
        single_stale_mif_transport_idle(top) != 0u) {
        mask |= (uint8_t)(1u << NPU_SINGLE_CORE_CLK_MIF);
    }
    return mask;
}

static uint8_t single_axi_idle_state(
    const npu_single_core_cycle_t *top)
{
    return (uint8_t)(
        npu_gc_axi_cycle_is_idle(&top->gc_axi) != 0u &&
        single_stale_gc_transport_idle(top) != 0u &&
        top->mif_idle_sync1_core != 0u &&
        single_cdc_core_idle(&top->cdc) != 0u);
}

static uint8_t single_core_idle_state(
    const npu_single_core_cycle_t *top)
{
    return (uint8_t)(
        npu_issue_adapter_cycle_idle(&top->issue) != 0u &&
        npu_sys_slave_cmd_idle(&top->system_axi) != 0u &&
        top->cmd_source ==
            (uint8_t)NPU_SINGLE_CORE_CMD_SOURCE_NONE &&
        npu_cfe_cycle_idle(&top->cfe) != 0u &&
        npu_ts_cycle_idle(&top->ts) != 0 &&
        single_engine_mask_quiescent(top->engine) == 0x0fu &&
        npu_l1_cycle_idle(&top->l1) != 0u &&
        single_axi_idle_state(top) != 0u);
}

static void single_crg_edge(
    npu_single_core_cycle_t *top,
    uint8_t core_edge,
    uint8_t core_rst_ni,
    uint8_t noc_rst_ni,
    uint8_t module_clk_en,
    uint8_t dvfs_prepare,
    npu_crg_outputs_t *outputs)
{
    npu_crg_inputs_t crg_inputs;
    npu_crg_outputs_t ignored;
    uint8_t idle_mask = single_module_idle_mask(top);
    uint8_t preserved_mask =
        core_edge != 0u ? 0x80u : 0x7fu;
    uint8_t preserved_active =
        (uint8_t)(top->crg.module_clk_active &
                  preserved_mask);
    uint8_t preserved_sync0 =
        core_edge != 0u ? top->crg.noc_sync0
                        : top->crg.core_sync0;
    uint8_t preserved_sync1 =
        core_edge != 0u ? top->crg.noc_sync1
                        : top->crg.core_sync1;

    (void)memset(&crg_inputs, 0, sizeof(crg_inputs));
    crg_inputs.core_rst_ni = core_rst_ni;
    crg_inputs.noc_rst_ni = noc_rst_ni;
    crg_inputs.dvfs_prepare_req_i = dvfs_prepare;
    crg_inputs.core_idle_i = single_core_idle_state(top);
    crg_inputs.axi_idle_i = single_axi_idle_state(top);
    crg_inputs.module_clk_en_i = module_clk_en;
    crg_inputs.module_idle_i = idle_mask;

    /*
     * The low phase is explicit because a glitch-free gate changes its
     * enable only while the source clock is low.
     */
    npu_crg_cycle(&top->crg, &crg_inputs, &ignored);
    crg_inputs.core_clk_i = core_edge;
    crg_inputs.noc_clk_i = (uint8_t)(core_edge == 0u);
    npu_crg_cycle(&top->crg, &crg_inputs, outputs);
    top->crg.module_clk_active =
        (uint8_t)((top->crg.module_clk_active &
                   (uint8_t)~preserved_mask) |
                  preserved_active);
    if (core_edge != 0u) {
        top->crg.noc_sync0 = preserved_sync0;
        top->crg.noc_sync1 = preserved_sync1;
        outputs->noc_reset_n = preserved_sync1;
    } else {
        top->crg.core_sync0 = preserved_sync0;
        top->crg.core_sync1 = preserved_sync1;
        outputs->core_reset_n = preserved_sync1;
    }
    outputs->module_clk_active_o =
        top->crg.module_clk_active;
    top->last_crg = *outputs;
}

static void single_build_issue_inputs(
    const npu_single_core_cycle_core_inputs_t *external,
    const npu_ts_cycle_outputs_t *ts,
    uint8_t issue_quiesce,
    uint8_t cmd_ready,
    uint8_t cmd_rsp_valid,
    uint64_t cmd_rsp_data,
    uint8_t reset_n,
    npu_issue_adapter_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = reset_n;
    inputs->issue_quiesce_i = issue_quiesce;
    inputs->issue_valid_i = external->issue_valid_i;
    inputs->issue_opcode_i = external->issue_opcode_i;
    inputs->issue_funct3_i = external->issue_funct3_i;
    inputs->issue_funct7_i = external->issue_funct7_i;
    inputs->issue_rs1_i = external->issue_rs1_i;
    inputs->issue_rs2_i = external->issue_rs2_i;
    inputs->issue_rd_i = external->issue_rd_i;
    inputs->dsa_permission_i = external->dsa_permission_i;
    inputs->dsa_enable_i = external->dsa_enable_i;
    inputs->cpu_cancel_i = external->cpu_cancel_i;
    inputs->issue_rsp_ready_i = external->issue_rsp_ready_i;
    inputs->gc_cmd_ready_i = cmd_ready;
    inputs->gc_rsp_valid_i = cmd_rsp_valid;
    inputs->gc_rsp_data_i = cmd_rsp_data;
    if (ts != (const npu_ts_cycle_outputs_t *)0) {
        inputs->gc_ctl_ready_i = ts->ctl.ready;
        inputs->gc_ctl_rsp_valid_i = ts->ctl.rsp_valid;
        inputs->gc_ctl_rsp_data_i = ts->ctl.rsp_data;
    }
}

static void single_build_cfe_inputs(
    const npu_ts_cycle_outputs_t *ts,
    const npu_lsc_cycle_outputs_t *lsc,
    uint8_t cmd_valid,
    uint64_t cmd_data,
    uint8_t cmd_first,
    uint8_t cmd_last,
    uint8_t cmd_rsp_ready,
    uint8_t source_busy,
    uint8_t reset_n,
    npu_cfe_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = reset_n;
    inputs->cfe_quiesce_i =
        (uint8_t)(lsc->cfe_quiesce != 0u &&
                  source_busy == 0u);
    inputs->gc_cmd_valid_i = cmd_valid;
    inputs->gc_cmd_data_i = cmd_data;
    inputs->gc_cmd_first_i = cmd_first;
    inputs->gc_cmd_last_i = cmd_last;
    inputs->gc_rsp_ready_i = cmd_rsp_ready;
    inputs->ts_cmd_ready_i = ts->cfe.ready;
    inputs->cmd_id_lookup_ready_i = ts->cfe.lookup_ready;
    inputs->cmd_id_lookup_rsp_valid_i =
        ts->cfe.lookup_rsp_valid;
    inputs->cmd_id_busy_i = ts->cfe.lookup_busy;
}

static void single_build_ts_inputs(
    const npu_issue_adapter_cycle_outputs_t *issue,
    const npu_cfe_cycle_outputs_t *cfe,
    const npu_engine_data_cycle_outputs_t
        engine[NPU_TS_ENGINE_COUNT],
    const npu_mif_cdc_core_outputs_t *cdc,
    const npu_lsc_cycle_outputs_t *lsc,
    uint8_t mif_reset_abort,
    uint8_t reset_n,
    npu_ts_cycle_inputs_t *inputs)
{
    uint32_t index;

    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = reset_n;
    inputs->stop_accept = lsc->stop_fetch;
    inputs->quiesce_req = lsc->ts_quiesce;
    inputs->abort_req = lsc->eng_abort != 0u ? 1u : 0u;
    inputs->mif_reset_abort = mif_reset_abort;
    for (index = 0u; index < NPU_TIMEOUT_CLASS_NUM; index++) {
        inputs->timeout_cycles[index] =
            lsc->timeout_cycles[index];
    }

    inputs->cfe.valid = cfe->ts_cmd_valid_o;
    inputs->cfe.data = cfe->ts_cmd_data_o;
    inputs->cfe.first = cfe->ts_cmd_first_o;
    inputs->cfe.last = cfe->ts_cmd_last_o;
    inputs->cfe.lookup_valid = cfe->cmd_id_lookup_valid_o;
    inputs->cfe.lookup_id = cfe->cmd_id_lookup_id_o;

    inputs->dfu.req_ready =
        cdc->owner[NPU_MIF_OWNER_DFU].req_ready;
    inputs->dfu.rsp_valid =
        cdc->owner[NPU_MIF_OWNER_DFU].rsp_valid;
    inputs->dfu.rsp_data =
        cdc->owner[NPU_MIF_OWNER_DFU].rsp_data;
    inputs->dfu.rsp_tag =
        cdc->owner[NPU_MIF_OWNER_DFU].rsp_tag;
    inputs->dfu.rsp_last =
        cdc->owner[NPU_MIF_OWNER_DFU].rsp_last;
    inputs->dfu.rsp_status =
        cdc->owner[NPU_MIF_OWNER_DFU].rsp_status;

    inputs->ctl.valid = issue->gc_ctl_valid_o;
    inputs->ctl.op = issue->gc_ctl_op_o;
    inputs->ctl.rs1 = issue->gc_ctl_rs1_o;
    inputs->ctl.rs2 = issue->gc_ctl_rs2_o;
    inputs->ctl.cancel = issue->gc_ctl_cancel_o;
    inputs->ctl.rsp_ready = issue->gc_ctl_rsp_ready_o;

    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        inputs->engine[index].req_ready =
            engine[index].engine.eng_req_ready_o;
        inputs->engine[index].cancel_ready =
            engine[index].engine.eng_cancel_ready_o;
        inputs->engine[index].done_valid =
            engine[index].engine.eng_done_valid_o;
        inputs->engine[index].done_data =
            engine[index].engine.eng_done_data_o;
        inputs->engine[index].done_first =
            engine[index].engine.eng_done_first_o;
        inputs->engine[index].done_last =
            engine[index].engine.eng_done_last_o;
        inputs->engine[index].quiescent =
            engine[index].engine.eng_quiescent_o;
        inputs->desc[index].req_valid =
            engine[index].engine.desc_rd_req_valid_o;
        inputs->desc[index].req_slot =
            engine[index].engine.desc_rd_slot_o;
        inputs->desc[index].req_word =
            engine[index].engine.desc_rd_word_o;
        inputs->desc[index].req_tag =
            engine[index].engine.desc_rd_req_tag_o;
        inputs->desc[index].rsp_ready =
            engine[index].engine.desc_rd_rsp_ready_o;
    }
}

static uint8_t single_engine_l1_read_port(
    uint32_t engine,
    uint32_t local_port)
{
    static const uint8_t base[NPU_TS_ENGINE_COUNT] = {
        NPU_L1_RD_DMA,
        NPU_L1_RD_ME_A,
        NPU_L1_RD_IVE_SRC0,
        NPU_L1_RD_CME_SRC0
    };

    return (uint8_t)(base[engine] + local_port);
}

static uint8_t single_engine_l1_write_port(uint32_t engine)
{
    static const uint8_t port[NPU_TS_ENGINE_COUNT] = {
        NPU_L1_WR_DMA,
        NPU_L1_WR_ME_C,
        NPU_L1_WR_IVE_DST,
        NPU_L1_WR_CME_DST
    };

    return port[engine];
}

static uint8_t single_engine_read_count(uint32_t engine)
{
    static const uint8_t count[NPU_TS_ENGINE_COUNT] = {
        1u, 3u, 4u, 4u
    };

    return count[engine];
}

static int single_l1_error_engine_index(uint8_t port,
                                        uint8_t write)
{
    uint32_t engine;

    for (engine = 0u; engine < NPU_TS_ENGINE_COUNT; engine++) {
        if (write != 0u) {
            if (single_engine_l1_write_port(engine) == port) {
                return (int)engine;
            }
        } else {
            uint32_t local_port;

            for (local_port = 0u;
                 local_port < single_engine_read_count(engine);
                 local_port++) {
                if (single_engine_l1_read_port(
                        engine, local_port) == port) {
                    return (int)engine;
                }
            }
        }
    }
    return -1;
}

static void single_update_l1_ecc_record(
    npu_single_core_cycle_t *top,
    const npu_l1_cycle_outputs_t *l1,
    uint8_t error_clear,
    uint8_t reset_n)
{
    npu_lsc_external_error_input_t *record =
        &top->l1_ecc_record;
    int engine_index;

    if (reset_n == 0u || error_clear != 0u) {
        (void)memset(record, 0, sizeof(*record));
    }
    if (reset_n == 0u || error_clear != 0u ||
        record->valid != 0u || l1->ecc_error_valid == 0u) {
        return;
    }

    record->valid = 1u;
    record->status = NPU_STATUS_L1_ECC_UNCORRECTABLE;
    record->addr = l1->ecc_error_addr;
    record->detail = l1->ecc_error_port;
    record->aux =
        (uint8_t)((l1->ecc_error_bank << 1u) |
                  (l1->ecc_error_write != 0u ? 1u : 0u));

    engine_index = single_l1_error_engine_index(
        l1->ecc_error_port, l1->ecc_error_write);
    if (engine_index >= 0) {
        const npu_engine_cycle_t *engine =
            &top->engine[(uint32_t)engine_index].engine;

        record->has_task_identity = 1u;
        record->command_id = engine->task_id;
        record->engine = (uint8_t)engine->engine;
        record->opcode = engine->opcode;
    }
}

static void single_build_engine_inputs(
    const npu_ts_cycle_outputs_t *ts,
    const npu_lsc_cycle_outputs_t *lsc,
    const npu_l1_cycle_outputs_t *l1,
    const npu_mif_cdc_core_outputs_t *cdc,
    uint8_t mif_reset_abort,
    uint8_t reset_n,
    npu_engine_data_cycle_inputs_t
        inputs[NPU_TS_ENGINE_COUNT])
{
    uint32_t engine;

    for (engine = 0u; engine < NPU_TS_ENGINE_COUNT; engine++) {
        uint32_t port;

        (void)memset(&inputs[engine], 0,
                     sizeof(inputs[engine]));
        inputs[engine].engine.reset_n =
            (uint8_t)(reset_n != 0u &&
                      (engine != NPU_TS_PORT_DMA ||
                       mif_reset_abort == 0u));
        inputs[engine].engine.eng_req_valid_i =
            ts->engine[engine].req_valid;
        inputs[engine].engine.eng_req_data_i =
            ts->engine[engine].req_data;
        inputs[engine].engine.eng_done_ready_i =
            ts->engine[engine].done_ready;
        inputs[engine].engine.eng_abort_i =
            (uint8_t)((lsc->eng_abort >> engine) & 1u);
        inputs[engine].engine.eng_cancel_valid_i =
            ts->engine[engine].cancel_valid;
        inputs[engine].engine.eng_cancel_status_i =
            ts->engine[engine].cancel_status;
        inputs[engine].engine.desc_rd_req_ready_i =
            ts->desc[engine].req_ready;
        inputs[engine].engine.desc_rd_rsp_valid_i =
            ts->desc[engine].rsp_valid;
        inputs[engine].engine.desc_rd_rsp_data_i =
            ts->desc[engine].rsp_data;
        inputs[engine].engine.desc_rd_rsp_tag_i =
            ts->desc[engine].rsp_tag;
        inputs[engine].engine.desc_rd_rsp_status_i =
            ts->desc[engine].rsp_status;
        inputs[engine].param_l1_base =
            lsc->param_l1_base;
        inputs[engine].param_l1_limit =
            lsc->param_l1_limit;
        inputs[engine].param_lock = lsc->param_lock;

        for (port = 0u;
             port < single_engine_read_count(engine);
             port++) {
            inputs[engine].l1_read[port] =
                l1->read[single_engine_l1_read_port(
                    engine, port)];
        }
        inputs[engine].l1_write =
            l1->write[single_engine_l1_write_port(engine)];
        if (engine == 0u) {
            inputs[engine].mif =
                cdc->owner[NPU_MIF_OWNER_DMA];
        }
    }
}

static uint8_t single_dma_param_write_allowed(
    const npu_single_core_cycle_t *top)
{
    const npu_engine_data_cycle_t *dma = &top->engine[0];
    const npu_dma_desc_t *desc =
        &dma->engine.request.desc.dma;

    return dma->data_pending != 0u &&
                   (dma->engine.opcode == NPU_DMA_COPY_1D ||
                    dma->engine.opcode == NPU_DMA_COPY_ND) &&
                   desc->convert_mode == NPU_DMA_CONVERT_NONE
               ? 1u
               : 0u;
}

static void single_build_l1_inputs(
    const npu_single_core_cycle_t *top,
    const npu_engine_data_cycle_outputs_t
        engine[NPU_TS_ENGINE_COUNT],
    const npu_l1_diag_bridge_outputs_t *diag,
    const npu_lsc_cycle_outputs_t *lsc,
    uint8_t error_clear,
    uint8_t reset_n,
    npu_l1_cycle_inputs_t *inputs)
{
    uint32_t engine_index;

    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = reset_n;
    inputs->error_clear = error_clear;
    inputs->param_l1_base = lsc->param_l1_base;
    inputs->param_l1_limit = lsc->param_l1_limit;
    inputs->param_lock = lsc->param_lock;
    if (single_dma_param_write_allowed(top) != 0u) {
        inputs->param_write_allow_mask =
            (uint8_t)(1u << NPU_L1_WR_DMA);
    }

    for (engine_index = 0u;
         engine_index < NPU_TS_ENGINE_COUNT;
         engine_index++) {
        uint32_t port;

        for (port = 0u;
             port < single_engine_read_count(engine_index);
             port++) {
            inputs->read[single_engine_l1_read_port(
                engine_index, port)] =
                engine[engine_index].l1_read[port];
        }
        inputs->write[single_engine_l1_write_port(
            engine_index)] =
            engine[engine_index].l1_write;
    }
    inputs->read[NPU_L1_RD_DEBUG] = diag->l1_read_o;
    inputs->write[NPU_L1_WR_DEBUG] = diag->l1_write_o;
}

static void single_build_cdc_core_inputs(
    const npu_ts_cycle_outputs_t *ts,
    const npu_engine_data_cycle_outputs_t *dma,
    uint8_t reset_n,
    npu_mif_cdc_core_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = reset_n;
    inputs->owner[NPU_MIF_OWNER_DFU].req_valid =
        ts->dfu.req_valid;
    inputs->owner[NPU_MIF_OWNER_DFU].req_write = 0u;
    inputs->owner[NPU_MIF_OWNER_DFU].req_vaddr =
        ts->dfu.req_addr;
    inputs->owner[NPU_MIF_OWNER_DFU].req_beats =
        ts->dfu.req_beats;
    inputs->owner[NPU_MIF_OWNER_DFU].req_tag =
        ts->dfu.req_tag;
    inputs->owner[NPU_MIF_OWNER_DFU].req_owner =
        NPU_MIF_OWNER_DFU;
    inputs->owner[NPU_MIF_OWNER_DFU].req_task_id =
        ts->dfu.req_task_id;
    inputs->owner[NPU_MIF_OWNER_DFU].req_attr =
        ts->dfu.req_attr;
    inputs->owner[NPU_MIF_OWNER_DFU].rsp_ready =
        ts->dfu.rsp_ready;

    inputs->owner[NPU_MIF_OWNER_DMA] = dma->mif;
    inputs->owner[NPU_MIF_OWNER_DMA].req_owner =
        NPU_MIF_OWNER_DMA;
}

static void single_build_diag_inputs(
    const npu_sys_slave_outputs_t *system,
    const npu_l1_cycle_outputs_t *l1,
    uint8_t error_clear,
    uint8_t reset_n,
    npu_l1_diag_bridge_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = reset_n;
    inputs->error_clear_i = error_clear;
    inputs->req_valid_i = system->ssa_l1_req_valid_o;
    inputs->req_write_i = system->ssa_l1_req_write_o;
    inputs->req_addr_i = system->ssa_l1_req_addr_o;
    inputs->req_wdata_i = system->ssa_l1_req_wdata_o;
    inputs->req_wstrb_i = system->ssa_l1_req_wstrb_o;
    inputs->rsp_ready_i = system->ssa_l1_rsp_ready_o;
    inputs->l1_read_i = l1->read[NPU_L1_RD_DEBUG];
    inputs->l1_write_i = l1->write[NPU_L1_WR_DEBUG];
}

static void single_build_system_inputs(
    const npu_single_core_cycle_core_inputs_t *external,
    const npu_lsc_cycle_outputs_t *lsc,
    const npu_l1_diag_bridge_outputs_t *diag,
    uint8_t access_idle,
    uint8_t cmd_ready,
    uint8_t cmd_rsp_valid,
    uint64_t cmd_rsp_data,
    uint8_t reset_n,
    npu_sys_slave_inputs_t *inputs)
{
    *inputs = external->system_axi;
    inputs->core_reset_n = reset_n;
    /*
     * The caller supplies the current pre-edge idle state and removes a
     * same-edge Issue or Generic Core AXI request handshake from it.
     */
    inputs->core_idle_i = access_idle;
    inputs->debug_frozen_i = lsc->debug_frozen;
    inputs->l1_diag_enable_i = lsc->l1_diag_enable;
    inputs->reg_req_ready_i = lsc->reg_req_ready;
    inputs->reg_rsp_valid_i = lsc->reg_rsp_valid;
    inputs->reg_rsp_rdata_i = lsc->reg_rsp_rdata;
    inputs->reg_rsp_status_i = lsc->reg_rsp_status;
    inputs->ssa_l1_req_ready_i = diag->req_ready_o;
    inputs->ssa_l1_rsp_valid_i = diag->rsp_valid_o;
    inputs->ssa_l1_rsp_rdata_i = diag->rsp_rdata_o;
    inputs->ssa_l1_rsp_status_i = diag->rsp_status_o;
    inputs->cmd_ready_i = cmd_ready;
    inputs->cmd_rsp_valid_i = cmd_rsp_valid;
    inputs->cmd_rsp_data_i = cmd_rsp_data;
    inputs->cmd_error_clear_i =
        lsc->external_error_clear_o;
}

typedef struct {
    uint8_t source;

    uint8_t cfe_valid;
    uint64_t cfe_data;
    uint8_t cfe_first;
    uint8_t cfe_last;
    uint8_t cfe_rsp_ready;
    uint8_t source_busy;

    uint8_t issue_ready;
    uint8_t issue_rsp_valid;
    uint64_t issue_rsp_data;

    uint8_t axi_ready;
    uint8_t axi_rsp_valid;
    uint64_t axi_rsp_data;
} npu_single_core_cmd_route_t;

static void single_route_command(
    const npu_single_core_cycle_t *top,
    const npu_issue_adapter_cycle_outputs_t *issue,
    const npu_sys_slave_outputs_t *system,
    const npu_cfe_cycle_outputs_t *cfe,
    npu_single_core_cmd_route_t *route)
{
    uint8_t source = top->cmd_source;

    (void)memset(route, 0, sizeof(*route));
    if (source ==
        (uint8_t)NPU_SINGLE_CORE_CMD_SOURCE_NONE) {
        if (system->cmd_valid_o != 0u ||
            system->cmd_rsp_ready_o != 0u) {
            source =
                (uint8_t)NPU_SINGLE_CORE_CMD_SOURCE_AXI;
        } else if (issue->gc_cmd_valid_o != 0u ||
                   issue->gc_rsp_ready_o != 0u) {
            source =
                (uint8_t)NPU_SINGLE_CORE_CMD_SOURCE_ISSUE;
        }
    }
    route->source = source;

    if (source ==
        (uint8_t)NPU_SINGLE_CORE_CMD_SOURCE_AXI) {
        route->cfe_valid = system->cmd_valid_o;
        route->cfe_data = system->cmd_data_o;
        route->cfe_first = system->cmd_first_o;
        route->cfe_last = system->cmd_last_o;
        route->cfe_rsp_ready = system->cmd_rsp_ready_o;
        route->source_busy =
            (uint8_t)(npu_sys_slave_cmd_idle(
                          &top->system_axi) == 0u);
        route->axi_ready = cfe->gc_cmd_ready_o;
        route->axi_rsp_valid = cfe->gc_rsp_valid_o;
        route->axi_rsp_data = cfe->gc_rsp_data_o;
    } else if (
        source ==
        (uint8_t)NPU_SINGLE_CORE_CMD_SOURCE_ISSUE) {
        route->cfe_valid = issue->gc_cmd_valid_o;
        route->cfe_data = issue->gc_cmd_data_o;
        route->cfe_first = issue->gc_cmd_first_o;
        route->cfe_last = issue->gc_cmd_last_o;
        route->cfe_rsp_ready = issue->gc_rsp_ready_o;
        route->source_busy = issue->issue_busy_o;
        route->issue_ready = cfe->gc_cmd_ready_o;
        route->issue_rsp_valid = cfe->gc_rsp_valid_o;
        route->issue_rsp_data = cfe->gc_rsp_data_o;
    }
}

static void single_update_command_source(
    npu_single_core_cycle_t *top,
    const npu_single_core_cmd_route_t *route,
    const npu_cfe_cycle_outputs_t *cfe,
    uint8_t reset_n)
{
    uint8_t command_handshake;
    uint8_t response_handshake;

    if (reset_n == 0u) {
        top->cmd_source =
            (uint8_t)NPU_SINGLE_CORE_CMD_SOURCE_NONE;
        return;
    }
    command_handshake =
        (uint8_t)(route->cfe_valid != 0u &&
                  cfe->gc_cmd_ready_o != 0u);
    response_handshake =
        (uint8_t)(route->cfe_rsp_ready != 0u &&
                  cfe->gc_rsp_valid_o != 0u);

    if (top->cmd_source ==
            (uint8_t)NPU_SINGLE_CORE_CMD_SOURCE_NONE &&
        command_handshake != 0u) {
        top->cmd_source = route->source;
    }
    if (response_handshake != 0u) {
        top->cmd_source =
            (uint8_t)NPU_SINGLE_CORE_CMD_SOURCE_NONE;
    }
}

static uint8_t single_system_access_idle(
    const npu_single_core_cycle_t *top,
    const npu_single_core_cycle_core_inputs_t *external,
    const npu_issue_adapter_cycle_outputs_t *issue,
    const npu_gc_axi_cycle_inputs_t *gc_inputs,
    const npu_gc_axi_cycle_outputs_t *gc_axi)
{
    if (single_core_idle_state(top) == 0u ||
        (external->issue_valid_i != 0u &&
         issue->issue_ready_o != 0u) ||
        (gc_inputs->icache_req.valid != 0u &&
         gc_axi->icache_req_ready != 0u) ||
        (gc_inputs->dcache_read_req.valid != 0u &&
         gc_axi->dcache_read_req_ready != 0u) ||
        (gc_inputs->dcache_write_req.valid != 0u &&
         gc_axi->dcache_write_req_ready != 0u)) {
        return 0u;
    }
    return 1u;
}

static uint8_t single_task_progress(
    const npu_single_core_cycle_t *top,
    const npu_single_core_cycle_core_inputs_t *external,
    const npu_issue_adapter_cycle_outputs_t *issue,
    const npu_single_core_cmd_route_t *cmd_route,
    const npu_cfe_cycle_outputs_t *cfe,
    const npu_ts_cycle_outputs_t *ts,
    const npu_engine_data_cycle_outputs_t
        engine[NPU_TS_ENGINE_COUNT],
    const npu_l1_diag_bridge_outputs_t *diag,
    const npu_l1_cycle_outputs_t *l1,
    const npu_mif_cdc_core_outputs_t *cdc,
    const npu_gc_axi_cycle_inputs_t *gc_inputs,
    const npu_gc_axi_cycle_outputs_t *gc_axi)
{
    uint32_t engine_index;

    if ((external->issue_valid_i != 0u &&
         issue->issue_ready_o != 0u) ||
        (issue->issue_rsp_valid_o != 0u &&
         external->issue_rsp_ready_i != 0u) ||
        (cmd_route->cfe_valid != 0u &&
         cfe->gc_cmd_ready_o != 0u) ||
        (cfe->gc_rsp_valid_o != 0u &&
         cmd_route->cfe_rsp_ready != 0u) ||
        (issue->gc_ctl_valid_o != 0u &&
         ts->ctl.ready != 0u) ||
        (ts->ctl.rsp_valid != 0u &&
         issue->gc_ctl_rsp_ready_o != 0u)) {
        return 1u;
    }
    if ((cfe->ts_cmd_valid_o != 0u &&
         ts->cfe.ready != 0u) ||
        (cfe->cmd_id_lookup_valid_o != 0u &&
         ts->cfe.lookup_ready != 0u) ||
        ts->cfe.lookup_rsp_valid != 0u) {
        return 1u;
    }
    if (engine[1].me_mac_active != 0u ||
        engine[2].ive_alu_active != 0u ||
        engine[3].cme_i2f_active != 0u ||
        engine[3].cme_fp_active != 0u ||
        engine[3].cme_f2i_active != 0u) {
        return 1u;
    }
    if (ts->dfu.req_valid != 0u &&
        cdc->owner[NPU_MIF_OWNER_DFU].req_ready != 0u) {
        return 1u;
    }
    if (ts->dfu.rsp_ready != 0u &&
        cdc->owner[NPU_MIF_OWNER_DFU].rsp_valid != 0u) {
        return 1u;
    }
    for (engine_index = 0u;
         engine_index < NPU_TS_ENGINE_COUNT;
         engine_index++) {
        uint32_t local_port;

        if ((ts->engine[engine_index].req_valid != 0u &&
             engine[engine_index]
                     .engine.eng_req_ready_o != 0u) ||
            (ts->engine[engine_index].cancel_valid != 0u &&
             engine[engine_index]
                     .engine.eng_cancel_ready_o != 0u) ||
            (ts->engine[engine_index].done_ready != 0u &&
             engine[engine_index]
                     .engine.eng_done_valid_o != 0u)) {
            return 1u;
        }
        if ((engine[engine_index]
                     .engine.desc_rd_req_valid_o != 0u &&
             ts->desc[engine_index].req_ready != 0u) ||
            (engine[engine_index]
                     .engine.desc_rd_rsp_ready_o != 0u &&
             ts->desc[engine_index].rsp_valid != 0u)) {
            return 1u;
        }
        for (local_port = 0u;
             local_port <
                 single_engine_read_count(engine_index);
             local_port++) {
            uint8_t l1_port =
                single_engine_l1_read_port(
                    engine_index, local_port);

            if ((engine[engine_index]
                         .l1_read[local_port].req_valid != 0u &&
                 l1->read[l1_port].req_ready != 0u) ||
                (engine[engine_index]
                         .l1_read[local_port].rsp_ready != 0u &&
                 l1->read[l1_port].rsp_valid != 0u)) {
                return 1u;
            }
        }
        {
            uint8_t l1_port =
                single_engine_l1_write_port(engine_index);

            if ((engine[engine_index].l1_write.req_valid != 0u &&
                 l1->write[l1_port].req_ready != 0u) ||
                (engine[engine_index].l1_write.data_valid != 0u &&
                 l1->write[l1_port].data_ready != 0u) ||
                (engine[engine_index].l1_write.rsp_ready != 0u &&
                 l1->write[l1_port].rsp_valid != 0u)) {
                return 1u;
            }
        }
        if (top->engine[engine_index].data_pending == 0u &&
            top->engine[engine_index].workspace_bound != 0u &&
            top->engine[engine_index].engine.state ==
                NPU_ENGINE_CYCLE_EXECUTE &&
            top->engine[engine_index]
                    .engine.execute_remaining <= 1u) {
            return 1u;
        }
    }

    if ((diag->l1_read_o.req_valid != 0u &&
         l1->read[NPU_L1_RD_DEBUG].req_ready != 0u) ||
        (diag->l1_read_o.rsp_ready != 0u &&
         l1->read[NPU_L1_RD_DEBUG].rsp_valid != 0u) ||
        (diag->l1_write_o.req_valid != 0u &&
         l1->write[NPU_L1_WR_DEBUG].req_ready != 0u) ||
        (diag->l1_write_o.data_valid != 0u &&
         l1->write[NPU_L1_WR_DEBUG].data_ready != 0u) ||
        (diag->l1_write_o.rsp_ready != 0u &&
         l1->write[NPU_L1_WR_DEBUG].rsp_valid != 0u)) {
        return 1u;
    }

    if ((engine[0].mif.req_valid != 0u &&
         cdc->owner[NPU_MIF_OWNER_DMA].req_ready != 0u) ||
        (engine[0].mif.wvalid != 0u &&
         cdc->owner[NPU_MIF_OWNER_DMA].wready != 0u) ||
        (engine[0].mif.rsp_ready != 0u &&
         cdc->owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u) ||
        ts->terminal_valid != 0u) {
        return 1u;
    }
    if ((gc_inputs->icache_req.valid != 0u &&
         gc_axi->icache_req_ready != 0u) ||
        (gc_inputs->dcache_read_req.valid != 0u &&
         gc_axi->dcache_read_req_ready != 0u) ||
        (gc_inputs->dcache_write_req.valid != 0u &&
         gc_axi->dcache_write_req_ready != 0u) ||
        (gc_inputs->dcache_write_data.valid != 0u &&
         gc_axi->dcache_write_data_ready != 0u) ||
        (gc_axi->icache_rsp.valid != 0u &&
         gc_inputs->icache_rsp_ready != 0u) ||
        (gc_axi->dcache_read_rsp.valid != 0u &&
         gc_inputs->dcache_read_rsp_ready != 0u) ||
        (gc_axi->dcache_write_rsp.valid != 0u &&
         gc_inputs->dcache_write_rsp_ready != 0u) ||
        (gc_axi->axi.awvalid != 0u &&
         gc_inputs->axi.awready != 0u) ||
        (gc_axi->axi.wvalid != 0u &&
         gc_inputs->axi.wready != 0u) ||
        (gc_inputs->axi.bvalid != 0u &&
         gc_axi->axi.bready != 0u) ||
        (gc_axi->axi.arvalid != 0u &&
         gc_inputs->axi.arready != 0u) ||
        (gc_inputs->axi.rvalid != 0u &&
         gc_axi->axi.rready != 0u)) {
        return 1u;
    }
    return 0u;
}

static void single_build_perf(
    const npu_single_core_cycle_t *top,
    const npu_cfe_cycle_outputs_t *cfe,
    const npu_ts_cycle_outputs_t *ts,
    const npu_engine_data_cycle_outputs_t
        engine[NPU_TS_ENGINE_COUNT],
    const npu_l1_cycle_outputs_t *l1,
    const npu_mif_cdc_core_outputs_t *cdc,
    uint8_t core_idle,
    uint64_t perf[NPU_LSC_PERF_COUNTER_COUNT])
{
    const npu_bus_replay_cycle_t *dma_replay =
        &top->engine[0].replay;

    (void)memset(
        perf, 0,
        sizeof(uint64_t) * NPU_LSC_PERF_COUNTER_COUNT);
    perf[0] = core_idle == 0u ? 1u : 0u;
    perf[1] = cfe->cmd_accepted_o != 0u ? 1u : 0u;
    perf[2] =
        ts->terminal_valid != 0u &&
                ts->terminal_status == NPU_STATUS_SUCCESS
            ? 1u
            : 0u;
    perf[3] =
        ts->terminal_valid != 0u &&
                ts->terminal_status != NPU_STATUS_SUCCESS
            ? 1u
            : 0u;

    if (engine[0].mif.rsp_ready != 0u &&
        cdc->owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u &&
        cdc->owner[NPU_MIF_OWNER_DMA].rsp_is_write == 0u &&
        cdc->owner[NPU_MIF_OWNER_DMA].rsp_status ==
            NPU_STATUS_SUCCESS &&
        dma_replay->trace != (const npu_bus_trace_t *)0 &&
        dma_replay->mif_read_lane.entry_index <
            dma_replay->trace->read_count) {
        perf[4] = single_popcount8(
            dma_replay->trace
                ->read[dma_replay->mif_read_lane.entry_index]
                .strb);
    }
    if (engine[0].mif.rsp_ready != 0u &&
        cdc->owner[NPU_MIF_OWNER_DMA].rsp_valid != 0u &&
        cdc->owner[NPU_MIF_OWNER_DMA].rsp_is_write != 0u &&
        cdc->owner[NPU_MIF_OWNER_DMA].rsp_status ==
            NPU_STATUS_SUCCESS &&
        dma_replay->trace != (const npu_bus_trace_t *)0 &&
        dma_replay->write_index <
            dma_replay->trace->write_count) {
        uint16_t beat;

        for (beat = 0u;
             beat < dma_replay->write_group_beats &&
             dma_replay->write_index + beat <
                 dma_replay->trace->write_count;
             beat++) {
            perf[5] += single_popcount8(
                dma_replay->trace
                    ->write[dma_replay->write_index + beat]
                    .strb);
        }
    }
    perf[6] =
        engine[0].l1_stall != 0u ||
                engine[0].mif_stall != 0u
            ? 1u
            : 0u;
    perf[7] = l1->bank_stall != 0u ? 1u : 0u;
    perf[8] = engine[1].me_mac_active;
    perf[9] = engine[1].me_operand_stall;
    perf[10] = engine[2].ive_alu_active;
    perf[11] = engine[3].cme_fp_active;
    perf[12] = engine[3].cme_l1_stall;
    perf[13] = top->pending_int_saturate_count;
    perf[14] = top->pending_all_mask_row_count;
    perf[15] =
        (uint64_t)l1->ecc_corrected_events +
        (uint64_t)(engine[0].engine.ecc_corrected_o != 0u) +
        (uint64_t)(engine[1].engine.ecc_corrected_o != 0u) +
        (uint64_t)(engine[2].engine.ecc_corrected_o != 0u) +
        (uint64_t)(engine[3].engine.ecc_corrected_o != 0u);
}

static void single_capture_functional_perf(
    npu_single_core_cycle_t *top)
{
    const npu_perf_t *now = &top->functional_model->perf;
    const npu_perf_t *before = &top->last_functional_perf;

    if (now->int_saturate_count >=
        before->int_saturate_count) {
        top->pending_int_saturate_count +=
            now->int_saturate_count -
            before->int_saturate_count;
    }
    if (now->all_mask_row_count >=
        before->all_mask_row_count) {
        top->pending_all_mask_row_count +=
            now->all_mask_row_count -
            before->all_mask_row_count;
    }
    top->last_functional_perf = *now;
}

static void single_set_mif_task_identity(
    const npu_single_core_cycle_t *top,
    uint8_t owner,
    uint8_t has_task_identity,
    uint16_t task_id,
    npu_lsc_external_error_input_t *error)
{
    const npu_engine_cycle_t *dma = &top->engine[0].engine;

    error->has_task_identity =
        has_task_identity != 0u ? 1u : 0u;
    if (error->has_task_identity == 0u) {
        return;
    }
    error->command_id = task_id;
    if (owner == NPU_MIF_OWNER_DMA) {
        error->engine = NPU_ENGINE_DMA;
        if (dma->task_id == task_id &&
            dma->state != NPU_ENGINE_CYCLE_IDLE) {
            error->opcode = dma->opcode;
        }
    }
}

static uint8_t single_lsc_input_idle(
    const npu_lsc_cycle_inputs_t *inputs)
{
    return (uint8_t)(
        inputs->issue_idle != 0u &&
        inputs->cfe_idle != 0u &&
        inputs->ts_idle != 0u &&
        (inputs->eng_quiescent & 0x0fu) == 0x0fu &&
        inputs->l1_idle != 0u &&
        inputs->mif_idle != 0u &&
        inputs->gc_axi_idle != 0u);
}

static void single_build_lsc_inputs(
    const npu_single_core_cycle_t *top,
    const npu_single_core_cycle_core_inputs_t *external,
    const npu_sys_slave_outputs_t *system,
    const npu_cfe_cycle_outputs_t *cfe,
    const npu_ts_cycle_outputs_t *ts,
    const npu_engine_data_cycle_outputs_t
        engine[NPU_TS_ENGINE_COUNT],
    const npu_l1_diag_bridge_outputs_t *diag,
    const npu_l1_cycle_outputs_t *l1,
    const npu_gc_axi_cycle_outputs_t *gc_axi,
    const npu_mif_cdc_core_outputs_t *cdc,
    uint8_t reset_n,
    npu_lsc_cycle_inputs_t *inputs)
{
    uint32_t index;
    uint64_t perf[NPU_LSC_PERF_COUNTER_COUNT];

    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = reset_n;
    inputs->reg_req_valid = system->reg_req_valid_o;
    inputs->reg_req_write = system->reg_req_write_o;
    inputs->reg_req_space = system->reg_req_space_o;
    inputs->reg_req_addr = system->reg_req_addr_o;
    inputs->reg_req_wdata = system->reg_req_wdata_o;
    inputs->reg_req_wstrb = system->reg_req_wstrb_o;
    inputs->reg_rsp_ready = system->reg_rsp_ready_o;
    inputs->soft_reset_req = external->soft_reset_req_i;
    inputs->internal_soft_reset_done =
        (uint8_t)(top->mif_soft_reset_started_core != 0u &&
                  top->mif_soft_reset_pending_core == 0u);
    inputs->power_down_req = external->power_down_req_i;
    inputs->core_wfi = external->core_wfi_i;
    inputs->issue_idle =
        npu_issue_adapter_cycle_idle(&top->issue);
    inputs->cfe_idle = cfe->cfe_idle_o;
    inputs->ts_idle = ts->idle;
    inputs->ts_quiescent = ts->quiescent;
    inputs->eng_quiescent =
        single_engine_mask_quiescent(top->engine);
    inputs->l1_idle = l1->idle;
    inputs->l1_write_idle = l1->write_idle;
    inputs->mif_idle =
        (uint8_t)(top->mif_idle_sync1_core != 0u &&
                  single_cdc_core_idle(&top->cdc) != 0u);
    inputs->gc_axi_idle =
        (uint8_t)(gc_axi->idle != 0u &&
                  single_stale_gc_transport_idle(top) != 0u);
    inputs->task_terminal_valid = ts->terminal_valid;
    inputs->task_irq_on_success =
        ts->terminal_irq_on_success;
    inputs->task_irq_on_error = ts->terminal_irq_on_error;
    inputs->task_command_id = ts->terminal_task_id;
    inputs->task_status = ts->terminal_status;
    inputs->task_engine = ts->terminal_engine;
    inputs->task_opcode = ts->terminal_opcode;
    inputs->task_fault_addr = ts->terminal_fault_addr;
    inputs->task_error_info = ts->terminal_error_info;
    inputs->task_done_flags = ts->terminal_done_flags;

    inputs->sys_l1_diag_error.valid = diag->error_valid_o;
    inputs->sys_l1_diag_error.status = diag->error_status_o;
    inputs->sys_l1_diag_error.addr = diag->error_addr_o;
    inputs->sys_l1_diag_error.detail = diag->error_detail_o;
    inputs->sys_l1_diag_error.aux =
        diag->error_write_o != 0u ? 1u : 0u;

    inputs->l1_ecc_error = top->l1_ecc_record;

    if (top->mif_error_clear_pending_core == 0u) {
        const npu_single_core_mif_diag_t *mif =
            &top->mif_diag_sync1;

        inputs->mif_first_error.valid = mif->first_valid;
        inputs->mif_first_error.status = mif->first_status;
        inputs->mif_first_error.addr = mif->first_vaddr;
        inputs->mif_first_error.detail =
            mif->first_owner;
        inputs->mif_first_error.aux =
            mif->first_axi_resp;
        single_set_mif_task_identity(
            top, mif->first_owner, mif->first_valid,
            mif->first_task_id,
            &inputs->mif_first_error);

        inputs->mif_protocol_error.valid =
            mif->protocol_valid;
        inputs->mif_protocol_error.status =
            NPU_STATUS_BAD_DESC;
        inputs->mif_protocol_error.addr =
            mif->protocol_addr;
        inputs->mif_protocol_error.detail =
            mif->protocol_kind;
        inputs->mif_protocol_error.aux =
            mif->protocol_owner;
        single_set_mif_task_identity(
            top, mif->protocol_owner,
            mif->protocol_has_task_identity,
            mif->protocol_task_id,
            &inputs->mif_protocol_error);
    }

    inputs->gc_axi_first_error.valid =
        gc_axi->first_error_valid;
    inputs->gc_axi_first_error.status =
        gc_axi->first_error_status;
    inputs->gc_axi_first_error.addr =
        gc_axi->first_error_addr;
    inputs->gc_axi_first_error.detail =
        gc_axi->first_error_client;
    inputs->gc_axi_first_error.aux =
        gc_axi->first_error_axi_resp;
    inputs->gc_axi_protocol_error.valid =
        gc_axi->protocol_error_valid;
    inputs->gc_axi_protocol_error.status =
        NPU_STATUS_BAD_DESC;
    inputs->gc_axi_protocol_error.addr =
        gc_axi->protocol_error_addr;
    inputs->gc_axi_protocol_error.detail =
        gc_axi->protocol_error_kind;
    inputs->gc_axi_protocol_error.aux =
        gc_axi->protocol_error_client;

    inputs->wdt_timeout =
        (uint8_t)(top->last_wdt.timeout != 0u &&
                  top->last_wdt_timeout_level == 0u);
    single_build_perf(
        top, cfe, ts, engine, l1, cdc,
        single_lsc_input_idle(inputs), perf);
    for (index = 0u;
         index < NPU_LSC_PERF_COUNTER_COUNT;
         index++) {
        inputs->perf_increment[index] = perf[index];
    }
}

static void single_update_mif_core_config(
    npu_single_core_cycle_t *top,
    const npu_lsc_cycle_outputs_t *lsc)
{
    top->mif_config_core = top->mif_soc_config;
    top->mif_config_core.ddr_enable =
        lsc->ddr_local_base <= lsc->ddr_local_limit ? 1u : 0u;
    top->mif_config_core.ddr_base = lsc->ddr_local_base;
    top->mif_config_core.ddr_limit = lsc->ddr_local_limit;
    top->mif_config_core.tbu_stream_id =
        lsc->tbu_stream_id;
    top->mif_config_core.tbu_substream_id =
        lsc->tbu_substream_id;
}

static void single_capture_mif_diag(
    const npu_mif_cycle_t *mif,
    npu_single_core_mif_diag_t *diag)
{
    (void)memset(diag, 0, sizeof(*diag));
    diag->first_valid = mif->first_error_valid;
    diag->first_status = mif->first_error_status;
    diag->first_owner = mif->first_error_owner;
    diag->first_tag = mif->first_error_tag;
    diag->first_task_id = mif->first_error_task_id;
    diag->first_vaddr = mif->first_error_vaddr;
    diag->first_paddr = mif->first_error_paddr;
    diag->first_axi_id = mif->first_error_axi_id;
    diag->first_axi_id_valid =
        mif->first_error_axi_id_valid;
    diag->first_axi_resp = mif->first_error_axi_resp;
    diag->protocol_valid = mif->protocol_error_valid;
    diag->protocol_kind = mif->protocol_error_kind;
    diag->protocol_addr = mif->protocol_error_addr;
    diag->protocol_owner = mif->protocol_error_owner;
    diag->protocol_tag = mif->protocol_error_tag;
    diag->protocol_has_task_identity =
        mif->protocol_error_has_task_identity;
    diag->protocol_task_id =
        mif->protocol_error_task_id;
}

static uint8_t single_stale_tbu_tag_present(
    const npu_single_core_cycle_t *top,
    uint16_t tag)
{
    uint32_t index;

    for (index = 0u;
         index < NPU_SINGLE_CORE_STALE_TBU_COUNT;
         index++) {
        if (top->stale_tbu_tag_valid[index] != 0u &&
            top->stale_tbu_tag[index] == tag) {
            return 1u;
        }
    }
    return 0u;
}

static void single_add_stale_tbu_tag(
    npu_single_core_cycle_t *top,
    uint16_t tag)
{
    uint32_t index;

    if (single_stale_tbu_tag_present(top, tag) != 0u) {
        return;
    }
    for (index = 0u;
         index < NPU_SINGLE_CORE_STALE_TBU_COUNT;
         index++) {
        if (top->stale_tbu_tag_valid[index] == 0u) {
            top->stale_tbu_tag[index] = tag;
            top->stale_tbu_tag_valid[index] = 1u;
            return;
        }
    }
}

static void single_remove_stale_tbu_tag(
    npu_single_core_cycle_t *top,
    uint16_t tag)
{
    uint32_t index;

    for (index = 0u;
         index < NPU_SINGLE_CORE_STALE_TBU_COUNT;
         index++) {
        if (top->stale_tbu_tag_valid[index] != 0u &&
            top->stale_tbu_tag[index] == tag) {
            top->stale_tbu_tag_valid[index] = 0u;
            top->stale_tbu_tag[index] = 0u;
            return;
        }
    }
}

static uint8_t single_mif_read_buffered(
    const npu_mif_cycle_t *mif,
    uint8_t port,
    uint8_t id)
{
    return port < NPU_MIF_AXI_PORT_COUNT &&
                   mif->r_entry[port].valid != 0u &&
                   mif->r_entry[port].id == id
               ? 1u
               : 0u;
}

static uint8_t single_mif_write_buffered(
    const npu_mif_cycle_t *mif,
    uint8_t port,
    uint8_t id)
{
    return port < NPU_MIF_AXI_PORT_COUNT &&
                   mif->b_entry[port].valid != 0u &&
                   mif->b_entry[port].id == id
               ? 1u
               : 0u;
}

static void single_stale_write_push(
    npu_single_core_stale_write_t
        queue[NPU_SINGLE_CORE_STALE_WRITE_DEPTH],
    uint16_t *tail,
    uint16_t *count,
    uint8_t port,
    uint8_t axi_id,
    uint16_t beats)
{
    npu_single_core_stale_write_t *entry;

    if (beats == 0u ||
        *count >= NPU_SINGLE_CORE_STALE_WRITE_DEPTH) {
        return;
    }
    entry = &queue[*tail];
    entry->port = port;
    entry->axi_id = axi_id;
    entry->beats_remaining = beats;
    *tail = (uint16_t)(
        (*tail + 1u) % NPU_SINGLE_CORE_STALE_WRITE_DEPTH);
    (*count)++;
}

static void single_stale_write_pop(
    npu_single_core_stale_write_t
        queue[NPU_SINGLE_CORE_STALE_WRITE_DEPTH],
    uint16_t *head,
    uint16_t *count)
{
    if (*count == 0u) {
        return;
    }
    (void)memset(&queue[*head], 0, sizeof(queue[*head]));
    *head = (uint16_t)(
        (*head + 1u) % NPU_SINGLE_CORE_STALE_WRITE_DEPTH);
    (*count)--;
}

static void single_capture_stale_transport(
    npu_single_core_cycle_t *top)
{
    uint32_t index;

    if (top->tbu_mode == NPU_SINGLE_CORE_TBU_EXTERNAL) {
        for (index = 0u; index < NPU_MIF_MAX_REQUESTS;
             index++) {
            const npu_mif_request_entry_t *request =
                &top->mif.requests[index];

            if (request->valid != 0u &&
                request->phase == NPU_MIF_REQ_TBU_WAIT) {
                uint16_t tag =
                    (uint16_t)(
                        ((uint16_t)request->owner << 12u) |
                        (request->tag & 0x0fffu));

                single_add_stale_tbu_tag(top, tag);
            }
        }
    }

    for (index = 0u;
         index < NPU_MIF_MAX_AXI_OUTSTANDING;
         index++) {
        const npu_mif_axi_entry_t *entry =
            &top->mif.axi_entries[index];
        uint8_t port;
        uint8_t id;

        if (entry->valid == 0u ||
            entry->addr_sent == 0u ||
            entry->port >= NPU_MIF_AXI_PORT_COUNT) {
            continue;
        }
        port = entry->port;
        id = entry->axi_id;
        if (entry->write == 0u) {
            uint16_t remaining =
                entry->beats > entry->beats_done
                    ? (uint16_t)(entry->beats -
                                 entry->beats_done)
                    : 0u;
            uint16_t retained;

            if (remaining != 0u &&
                single_mif_read_buffered(
                    &top->mif, port, id) != 0u) {
                const npu_mif_axi_r_entry_t *buffered =
                    &top->mif.r_entry[port];

                if (buffered->last != 0u) {
                    remaining = 0u;
                } else {
                    remaining--;
                    if (remaining == 0u) {
                        top->stale_axi_read_wait_rlast[port][id] =
                            1u;
                    }
                }
            }
            retained =
                (uint16_t)
                    top->stale_axi_read_beats[port][id] +
                remaining;
            top->stale_axi_read_beats[port][id] =
                retained > UINT8_MAX
                    ? UINT8_MAX
                    : (uint8_t)retained;
        } else if (single_mif_write_buffered(
                       &top->mif, port, id) == 0u) {
            /*
             * An accepted AW cannot be cancelled by AXI. Keep its ID
             * unavailable even when reset interrupts the W stream before
             * its last beat. If the target eventually emits B, the top-level
             * gate accepts and discards it.
             */
            top->stale_axi_write_pending[port][id] = 1u;
        }
    }

    for (index = 0u; index < top->mif.write_fifo_count;
         index++) {
        uint8_t fifo_index =
            (uint8_t)((top->mif.write_fifo_head + index) %
                      NPU_MIF_MAX_AXI_OUTSTANDING);
        uint8_t slot = top->mif.write_fifo[fifo_index];
        const npu_mif_axi_entry_t *entry;
        uint16_t remaining;

        if (slot >= NPU_MIF_MAX_AXI_OUTSTANDING) {
            continue;
        }
        entry = &top->mif.axi_entries[slot];
        if (entry->valid == 0u ||
            entry->write == 0u ||
            entry->addr_sent == 0u ||
            entry->w_done != 0u ||
            entry->port >= NPU_MIF_AXI_PORT_COUNT) {
            continue;
        }
        remaining =
            entry->beats > entry->beats_done
                ? (uint16_t)(entry->beats -
                             entry->beats_done)
                : 0u;
        single_stale_write_push(
            top->stale_axi_write_drain,
            &top->stale_axi_write_drain_tail,
            &top->stale_axi_write_drain_count,
            entry->port, entry->axi_id, remaining);
    }
}

static void single_clear_stale_transport(
    npu_single_core_cycle_t *top)
{
    (void)memset(
        top->stale_axi_read_beats, 0,
        sizeof(top->stale_axi_read_beats));
    (void)memset(
        top->stale_axi_read_wait_rlast, 0,
        sizeof(top->stale_axi_read_wait_rlast));
    (void)memset(
        top->stale_axi_write_pending, 0,
        sizeof(top->stale_axi_write_pending));
    (void)memset(
        top->stale_axi_write_drain, 0,
        sizeof(top->stale_axi_write_drain));
    (void)memset(
        top->stale_tbu_tag, 0,
        sizeof(top->stale_tbu_tag));
    (void)memset(
        top->stale_tbu_tag_valid, 0,
        sizeof(top->stale_tbu_tag_valid));
    top->stale_axi_read_drop_count = 0u;
    top->stale_axi_write_drop_count = 0u;
    top->stale_axi_w_drain_count = 0u;
    top->stale_tbu_drop_count = 0u;
    top->stale_axi_write_drain_head = 0u;
    top->stale_axi_write_drain_tail = 0u;
    top->stale_axi_write_drain_count = 0u;
}

static uint8_t single_gc_read_buffered(
    const npu_gc_axi_cycle_t *gc_axi,
    uint8_t id)
{
    return gc_axi->r_entry.valid != 0u &&
                   gc_axi->r_entry.id == id
               ? 1u
               : 0u;
}

static uint8_t single_gc_write_buffered(
    const npu_gc_axi_cycle_t *gc_axi,
    uint8_t id)
{
    return gc_axi->b_entry.valid != 0u &&
                   gc_axi->b_entry.id == id
               ? 1u
               : 0u;
}

static void single_capture_stale_gc_transport(
    npu_single_core_cycle_t *top)
{
    uint32_t index;

    for (index = 0u;
         index < NPU_GC_AXI_READ_OUTSTANDING;
         index++) {
        const npu_gc_axi_read_entry_t *entry =
            &top->gc_axi.read[index];
        uint16_t remaining;
        uint16_t retained;
        uint8_t id;

        if (entry->valid == 0u ||
            entry->child_active == 0u ||
            entry->addr_sent == 0u) {
            continue;
        }
        id = entry->axi_id;
        remaining =
            entry->child_beats > entry->child_beats_done
                ? (uint16_t)(entry->child_beats -
                             entry->child_beats_done)
                : 0u;
        if (entry->drain_rlast != 0u) {
            remaining = 0u;
            top->stale_gc_axi_read_wait_rlast[id] = 1u;
        } else if (
            remaining != 0u &&
            single_gc_read_buffered(&top->gc_axi, id) != 0u) {
            if (top->gc_axi.r_entry.last != 0u) {
                remaining = 0u;
            } else {
                remaining--;
                if (remaining == 0u) {
                    top->stale_gc_axi_read_wait_rlast[id] = 1u;
                }
            }
        }
        retained =
            (uint16_t)top->stale_gc_axi_read_beats[id] +
            remaining;
        top->stale_gc_axi_read_beats[id] =
            retained > UINT8_MAX
                ? UINT8_MAX
                : (uint8_t)retained;
    }

    for (index = 0u;
         index < NPU_GC_AXI_WRITE_OUTSTANDING;
         index++) {
        const npu_gc_axi_write_entry_t *entry =
            &top->gc_axi.write[index];

        if (entry->valid != 0u &&
            entry->child_active != 0u &&
            entry->addr_sent != 0u &&
            single_gc_write_buffered(
                &top->gc_axi, entry->axi_id) == 0u) {
            top->stale_gc_axi_write_pending[entry->axi_id] = 1u;
        }
    }

    for (index = 0u;
         index < top->gc_axi.write_order_count;
         index++) {
        uint8_t order_index =
            (uint8_t)((top->gc_axi.write_order_head + index) %
                      NPU_GC_AXI_WRITE_ORDER_DEPTH);
        uint8_t slot = top->gc_axi.write_order[order_index];
        const npu_gc_axi_write_entry_t *entry;
        uint16_t remaining;

        if (slot >= NPU_GC_AXI_WRITE_OUTSTANDING) {
            continue;
        }
        entry = &top->gc_axi.write[slot];
        if (entry->valid == 0u ||
            entry->child_active == 0u ||
            entry->addr_sent == 0u ||
            entry->w_done != 0u) {
            continue;
        }
        remaining =
            entry->child_beats >
                    entry->child_write_beats_sent
                ? (uint16_t)(
                      entry->child_beats -
                      entry->child_write_beats_sent)
                : 0u;
        single_stale_write_push(
            top->stale_gc_axi_write_drain,
            &top->stale_gc_axi_write_drain_tail,
            &top->stale_gc_axi_write_drain_count,
            0u, entry->axi_id, remaining);
    }
}

static void single_clear_stale_gc_transport(
    npu_single_core_cycle_t *top)
{
    (void)memset(
        top->stale_gc_axi_read_beats, 0,
        sizeof(top->stale_gc_axi_read_beats));
    (void)memset(
        top->stale_gc_axi_read_wait_rlast, 0,
        sizeof(top->stale_gc_axi_read_wait_rlast));
    (void)memset(
        top->stale_gc_axi_write_pending, 0,
        sizeof(top->stale_gc_axi_write_pending));
    (void)memset(
        top->stale_gc_axi_write_drain, 0,
        sizeof(top->stale_gc_axi_write_drain));
    top->stale_gc_axi_write_drain_head = 0u;
    top->stale_gc_axi_write_drain_tail = 0u;
    top->stale_gc_axi_write_drain_count = 0u;
    top->stale_gc_axi_read_drop_count = 0u;
    top->stale_gc_axi_write_drop_count = 0u;
    top->stale_gc_axi_w_drain_count = 0u;
}

static uint8_t single_axi_id_stale(
    const npu_single_core_cycle_t *top,
    uint8_t port,
    uint8_t id)
{
    return top->stale_axi_read_beats[port][id] != 0u ||
                   top->stale_axi_read_wait_rlast[port][id] != 0u ||
                   top->stale_axi_write_pending[port][id] != 0u
               ? 1u
               : 0u;
}

static uint8_t single_axi_id_active(
    const npu_single_core_cycle_t *top,
    uint8_t id)
{
    uint32_t index;

    for (index = 0u;
         index < NPU_MIF_MAX_AXI_OUTSTANDING;
         index++) {
        if (top->mif.axi_entries[index].valid != 0u &&
            top->mif.axi_entries[index].axi_id == id) {
            return 1u;
        }
    }
    return 0u;
}

/*
 * MIF can create at most one AR and one AW hold per AXI port in one tick.
 * Selecting four consecutive clean IDs therefore prevents its sequential
 * allocator from crossing an identifier retained by pre-reset traffic.
 */
static uint8_t single_prepare_clean_axi_ids(
    npu_single_core_cycle_t *top)
{
    const uint16_t needed =
        (uint16_t)(NPU_MIF_AXI_PORT_COUNT * 2u);
    uint16_t offset;

    for (offset = 0u;
         offset < NPU_SINGLE_CORE_AXI_ID_COUNT;
         offset++) {
        uint8_t start =
            (uint8_t)((uint16_t)top->mif.next_axi_id +
                      offset);
        uint16_t item;
        uint8_t clean = 1u;

        for (item = 0u; item < needed; item++) {
            uint8_t id =
                (uint8_t)((uint16_t)start + item);
            uint8_t port;

            if (single_axi_id_active(top, id) != 0u) {
                clean = 0u;
                break;
            }
            for (port = 0u;
                 port < NPU_MIF_AXI_PORT_COUNT;
                 port++) {
                if (single_axi_id_stale(
                        top, port, id) != 0u) {
                    clean = 0u;
                    break;
                }
            }
            if (clean == 0u) {
                break;
            }
        }
        if (clean != 0u) {
            top->mif.next_axi_id = start;
            return 1u;
        }
    }
    return 0u;
}

static void single_filter_stale_gc_inputs(
    const npu_single_core_cycle_t *top,
    const npu_gc_axi_cycle_inputs_t *external,
    npu_gc_axi_cycle_inputs_t *filtered,
    uint8_t *stale_read,
    uint8_t *stale_write)
{
    *filtered = *external;
    *stale_read = 0u;
    *stale_write = 0u;

    if (external->axi.rvalid != 0u &&
        (top->stale_gc_axi_read_beats[external->axi.rid] != 0u ||
         top->stale_gc_axi_read_wait_rlast[external->axi.rid] !=
             0u)) {
        filtered->axi.rvalid = 0u;
        *stale_read = 1u;
    }
    if (external->axi.bvalid != 0u &&
        top->stale_gc_axi_write_pending[external->axi.bid] != 0u) {
        filtered->axi.bvalid = 0u;
        *stale_write = 1u;
    }
    if (single_stale_gc_transport_idle(top) == 0u) {
        filtered->quiesce = 1u;
        filtered->icache_req.valid = 0u;
        filtered->dcache_read_req.valid = 0u;
        filtered->dcache_write_req.valid = 0u;
        filtered->dcache_write_data.valid = 0u;
    }
}

static uint8_t single_stale_gc_read_count(
    const npu_single_core_cycle_t *top)
{
    uint16_t id;
    uint16_t count = 0u;

    for (id = 0u; id < NPU_SINGLE_CORE_AXI_ID_COUNT; id++) {
        if (top->stale_gc_axi_read_beats[id] != 0u ||
            top->stale_gc_axi_read_wait_rlast[id] != 0u) {
            count++;
        }
    }
    return count > UINT8_MAX ? UINT8_MAX : (uint8_t)count;
}

static uint8_t single_stale_gc_write_count(
    const npu_single_core_cycle_t *top)
{
    uint16_t id;
    uint16_t count = 0u;

    for (id = 0u; id < NPU_SINGLE_CORE_AXI_ID_COUNT; id++) {
        if (top->stale_gc_axi_write_pending[id] != 0u) {
            count++;
        }
    }
    return count > UINT8_MAX ? UINT8_MAX : (uint8_t)count;
}

static void single_apply_stale_gc_gates(
    const npu_single_core_cycle_t *top,
    uint8_t stale_read,
    uint8_t stale_write,
    npu_gc_axi_cycle_outputs_t *outputs)
{
    if (stale_read != 0u) {
        outputs->axi.rready = 1u;
    }
    if (stale_write != 0u) {
        outputs->axi.bready = 1u;
    }
    if (single_stale_gc_transport_idle(top) == 0u) {
        outputs->icache_req_ready = 0u;
        outputs->dcache_read_req_ready = 0u;
        outputs->dcache_write_req_ready = 0u;
        outputs->dcache_write_data_ready = 0u;
        outputs->axi.awvalid = 0u;
        outputs->axi.arvalid = 0u;
        outputs->idle = 0u;
        outputs->quiescent = 0u;
        outputs->read_axi_outstanding =
            single_stale_gc_read_count(top);
        outputs->write_axi_outstanding =
            single_stale_gc_write_count(top);
    }
    if (top->stale_gc_axi_write_drain_count != 0u) {
        const npu_single_core_stale_write_t *drain =
            &top->stale_gc_axi_write_drain[
                top->stale_gc_axi_write_drain_head];

        outputs->axi.wdata = 0u;
        outputs->axi.wstrb = 0u;
        outputs->axi.wlast =
            drain->beats_remaining == 1u ? 1u : 0u;
        outputs->axi.wvalid = 1u;
    }
}

static void single_consume_stale_read(
    uint8_t *remaining,
    uint8_t *wait_rlast,
    uint8_t last)
{
    if (*wait_rlast != 0u) {
        if (last != 0u) {
            *wait_rlast = 0u;
        }
        return;
    }
    if (*remaining > 1u) {
        if (last != 0u) {
            *remaining = 0u;
        } else {
            (*remaining)--;
        }
        return;
    }
    *remaining = 0u;
    if (last == 0u) {
        *wait_rlast = 1u;
    }
}

static void single_consume_stale_gc_transport(
    npu_single_core_cycle_t *top,
    const npu_gc_axi_cycle_inputs_t *external,
    const npu_gc_axi_cycle_outputs_t *outputs,
    uint8_t stale_read,
    uint8_t stale_write)
{
    if (stale_read != 0u &&
        external->axi.rvalid != 0u &&
        outputs->axi.rready != 0u) {
        single_consume_stale_read(
            &top->stale_gc_axi_read_beats[external->axi.rid],
            &top->stale_gc_axi_read_wait_rlast[
                external->axi.rid],
            external->axi.rlast);
        top->stale_gc_axi_read_drop_count++;
    }
    if (stale_write != 0u &&
        external->axi.bvalid != 0u &&
        outputs->axi.bready != 0u) {
        top->stale_gc_axi_write_pending[external->axi.bid] = 0u;
        top->stale_gc_axi_write_drop_count++;
    }
    if (top->stale_gc_axi_write_drain_count != 0u &&
        outputs->axi.wvalid != 0u &&
        external->axi.wready != 0u) {
        npu_single_core_stale_write_t *drain =
            &top->stale_gc_axi_write_drain[
                top->stale_gc_axi_write_drain_head];

        if (drain->beats_remaining != 0u) {
            drain->beats_remaining--;
            top->stale_gc_axi_w_drain_count++;
        }
        if (drain->beats_remaining == 0u) {
            single_stale_write_pop(
                top->stale_gc_axi_write_drain,
                &top->stale_gc_axi_write_drain_head,
                &top->stale_gc_axi_write_drain_count);
        }
    }
}

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
    npu_single_core_tbu_mode_t tbu_mode)
{
    npu_mif_cycle_config_t default_mif;
    npu_mif_cycle_config_t resolved_mif;
    npu_wire_limits_t resolved_wire;
    npu_lsc_cycle_config_t resolved_lsc;
    uint32_t index;
    npu_status_t status;

    if (top == (npu_single_core_cycle_t *)0 ||
        functional_model == (npu_model_t *)0 ||
        l1_memory == (uint8_t *)0 ||
        l1_ecc == (uint8_t *)0 ||
        workspace ==
            (const npu_engine_data_workspace_t *)0 ||
        functional_model->l1 != l1_memory ||
        functional_model->l1_size != l1_memory_bytes ||
        l1_memory_bytes != NPU_L1_CYCLE_BYTES ||
        l1_ecc_bytes < NPU_L1_CYCLE_WORDS ||
        (tbu_mode != NPU_SINGLE_CORE_TBU_EXTERNAL &&
         tbu_mode != NPU_SINGLE_CORE_TBU_INTERNAL)) {
        return NPU_STATUS_BAD_DESC;
    }

    if (wire_limits == (const npu_wire_limits_t *)0) {
        npu_wire_limits_reference(&resolved_wire);
        if (functional_model->ddr_size <
            resolved_wire.gaddr_limit) {
            resolved_wire.gaddr_limit =
                (uint64_t)functional_model->ddr_size;
        }
    } else {
        resolved_wire = *wire_limits;
    }
    if (lsc_config ==
        (const npu_lsc_cycle_config_t *)0) {
        npu_lsc_cycle_config_reference(&resolved_lsc);
    } else {
        resolved_lsc = *lsc_config;
    }
    if (npu_capability_config_match(
            functional_model, &resolved_wire,
            &resolved_lsc, 1u) == 0) {
        return NPU_STATUS_BAD_DESC;
    }
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        if (!npu_engine_data_workspace_valid(
                &workspace[index])) {
            return NPU_STATUS_BAD_DESC;
        }
    }
    npu_mif_cycle_config_default(&default_mif);
    resolved_mif =
        mif_soc_config !=
                (const npu_mif_cycle_config_t *)0
            ? *mif_soc_config
            : default_mif;
    if (npu_mif_cycle_config_valid(&resolved_mif) == 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    (void)memset(top, 0, sizeof(*top));
    top->functional_model = functional_model;
    top->wire_limits = resolved_wire;
    if (npu_l1_cycle_init(
            &top->l1, l1_memory, l1_memory_bytes,
            l1_ecc, l1_ecc_bytes) != 0 ||
        npu_sys_slave_cycle_init(
            &top->system_axi,
            (uint32_t)l1_memory_bytes) != 0 ||
        npu_l1_diag_bridge_init(&top->l1_diag) != 0) {
        (void)memset(top, 0, sizeof(*top));
        return NPU_STATUS_BAD_DESC;
    }

    npu_issue_adapter_cycle_reset(&top->issue);
    npu_cfe_cycle_reset(&top->cfe);
    npu_ts_cycle_init(&top->ts);
    top->ts.wire_limits = top->wire_limits;
    npu_lsc_cycle_init(&top->lsc, &resolved_lsc);
    npu_gc_axi_cycle_init(&top->gc_axi);
    npu_mif_cdc_cycle_init(&top->cdc);
    top->mif_soc_config = resolved_mif;
    top->mif_config_core = top->mif_soc_config;
    top->mif_config_sync0 = top->mif_soc_config;
    top->mif_config_sync1 = top->mif_soc_config;
    if (npu_mif_cycle_init(
            &top->mif, &top->mif_soc_config) != 0) {
        (void)memset(top, 0, sizeof(*top));
        return NPU_STATUS_BAD_DESC;
    }
    npu_tbu_cycle_init(&top->tbu);
    top->tbu_mode = (uint8_t)tbu_mode;
    npu_crg_reset(&top->crg);
    npu_wdt_reset(&top->wdt);

    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        status = npu_engine_data_cycle_init(
            &top->engine[index], functional_model,
            (npu_engine_t)(index + 1u),
            &top->wire_limits);
        if (status != NPU_STATUS_SUCCESS ||
            !npu_engine_data_cycle_bind_workspace(
                &top->engine[index], &workspace[index])) {
            (void)memset(top, 0, sizeof(*top));
            return status != NPU_STATUS_SUCCESS
                       ? status
                       : NPU_STATUS_BAD_DESC;
        }
    }
    top->last_functional_perf = functional_model->perf;
    top->initialized = 1u;
    return NPU_STATUS_SUCCESS;
}

void npu_single_core_cycle_reset(
    npu_single_core_cycle_t *top)
{
    uint32_t index;

    if (top == (npu_single_core_cycle_t *)0 ||
        top->initialized == 0u) {
        return;
    }
    single_clear_stale_transport(top);
    single_clear_stale_gc_transport(top);
    npu_issue_adapter_cycle_reset(&top->issue);
    top->cmd_source =
        (uint8_t)NPU_SINGLE_CORE_CMD_SOURCE_NONE;
    npu_cfe_cycle_reset(&top->cfe);
    npu_ts_cycle_reset(&top->ts);
    top->ts.wire_limits = top->wire_limits;
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        npu_engine_data_cycle_reset(&top->engine[index]);
    }
    npu_lsc_cycle_reset(&top->lsc);
    npu_sys_slave_cycle_reset(&top->system_axi);
    npu_l1_diag_bridge_reset(&top->l1_diag);
    npu_l1_cycle_reset(&top->l1);
    npu_gc_axi_cycle_reset(&top->gc_axi);
    npu_mif_cdc_cycle_reset(&top->cdc);
    npu_mif_cycle_reset(&top->mif);
    npu_tbu_cycle_reset(&top->tbu);
    npu_crg_reset(&top->crg);
    npu_wdt_reset(&top->wdt);
    npu_model_reset(top->functional_model);
    top->mif_config_core = top->mif_soc_config;
    top->mif_config_sync0 = top->mif_soc_config;
    top->mif_config_sync1 = top->mif_soc_config;
    (void)memset(&top->last_crg, 0,
                 sizeof(top->last_crg));
    (void)memset(&top->last_wdt, 0,
                 sizeof(top->last_wdt));
    top->last_wdt_timeout_level = 0u;
    (void)memset(&top->last_mif, 0,
                 sizeof(top->last_mif));
    (void)memset(&top->last_lsc, 0,
                 sizeof(top->last_lsc));
    (void)memset(&top->mif_diag_source, 0,
                 sizeof(top->mif_diag_source));
    (void)memset(&top->mif_diag_sync0, 0,
                 sizeof(top->mif_diag_sync0));
    (void)memset(&top->mif_diag_sync1, 0,
                 sizeof(top->mif_diag_sync1));
    (void)memset(&top->l1_ecc_record, 0,
                 sizeof(top->l1_ecc_record));
    top->mif_error_clear_toggle_core = 0u;
    top->mif_error_clear_sync0_noc = 0u;
    top->mif_error_clear_sync1_noc = 0u;
    top->mif_error_clear_seen_noc = 0u;
    top->mif_error_clear_ack_noc = 0u;
    top->mif_error_clear_ack_sync0_core = 0u;
    top->mif_error_clear_ack_sync1_core = 0u;
    top->mif_error_clear_pending_core = 0u;
    top->mif_soft_reset_toggle_core = 0u;
    top->mif_soft_reset_sync0_noc = 0u;
    top->mif_soft_reset_sync1_noc = 0u;
    top->mif_soft_reset_seen_noc = 0u;
    top->mif_soft_reset_ack_noc = 0u;
    top->mif_soft_reset_ack_sync0_core = 0u;
    top->mif_soft_reset_ack_sync1_core = 0u;
    top->mif_soft_reset_pending_core = 0u;
    top->mif_soft_reset_started_core = 0u;
    top->mif_idle_source_noc = 0u;
    top->mif_idle_sync0_core = 0u;
    top->mif_idle_sync1_core = 0u;
    top->cdc_reset_epoch_seen_core =
        top->cdc.core_epoch_sync1;
    top->cdc_reset_epoch_seen_noc =
        top->cdc.noc_epoch_sync1;
    (void)memset(top->last_engine_confirmed, 0,
                 sizeof(top->last_engine_confirmed));
    top->last_functional_perf =
        top->functional_model->perf;
    top->pending_int_saturate_count = 0u;
    top->pending_all_mask_row_count = 0u;
    top->core_cycle = 0u;
    top->noc_cycle = 0u;
}

void npu_single_core_cycle_core_tick(
    npu_single_core_cycle_t *top,
    const npu_single_core_cycle_core_inputs_t *external,
    npu_single_core_cycle_core_outputs_t *outputs)
{
    npu_issue_adapter_cycle_inputs_t issue_inputs;
    npu_issue_adapter_cycle_outputs_t issue_outputs;
    npu_cfe_cycle_inputs_t cfe_inputs;
    npu_cfe_cycle_outputs_t cfe_outputs;
    npu_ts_cycle_inputs_t ts_inputs;
    npu_ts_cycle_outputs_t ts_outputs;
    npu_engine_data_cycle_inputs_t
        engine_inputs[NPU_TS_ENGINE_COUNT];
    npu_engine_data_cycle_outputs_t
        engine_outputs[NPU_TS_ENGINE_COUNT];
    npu_l1_cycle_inputs_t l1_inputs;
    npu_l1_cycle_outputs_t l1_outputs;
    npu_mif_cdc_core_inputs_t cdc_inputs;
    npu_mif_cdc_core_outputs_t cdc_outputs;
    npu_l1_diag_bridge_inputs_t diag_inputs;
    npu_l1_diag_bridge_outputs_t diag_outputs;
    npu_sys_slave_inputs_t system_inputs;
    npu_sys_slave_outputs_t system_outputs;
    npu_lsc_cycle_inputs_t lsc_inputs;
    npu_lsc_cycle_outputs_t lsc_outputs;
    npu_gc_axi_cycle_inputs_t gc_axi_inputs;
    npu_gc_axi_cycle_outputs_t gc_axi_outputs;
    npu_single_core_cmd_route_t cmd_route;
    npu_crg_outputs_t crg_outputs;
    npu_wdt_inputs_t wdt_inputs;
    npu_wdt_outputs_t wdt_outputs;
    npu_issue_adapter_cycle_outputs_t ignored_issue;
    npu_cfe_cycle_outputs_t ignored_cfe;
    npu_ts_cycle_outputs_t ignored_ts;
    npu_engine_data_cycle_outputs_t ignored_engine;
    npu_l1_diag_bridge_outputs_t ignored_diag;
    npu_sys_slave_outputs_t ignored_system;
    npu_lsc_cycle_outputs_t ignored_lsc;
    npu_gc_axi_cycle_outputs_t ignored_gc_axi;
    uint8_t reset_n;
    uint8_t module_reset_n;
    uint8_t active_mask;
    uint8_t cfe_clock;
    uint8_t ts_clock;
    uint8_t l1_clock;
    uint8_t issue_quiesce;
    uint8_t access_idle;
    uint8_t mif_reset_abort;
    uint8_t reset_abort_consumable;
    uint8_t requested_module_clocks;
    uint8_t progress;
    uint8_t stale_gc_read;
    uint8_t stale_gc_write;
    uint8_t core_was_released;
    uint32_t iteration;
    uint32_t index;

    if (top == (npu_single_core_cycle_t *)0 ||
        external ==
            (const npu_single_core_cycle_core_inputs_t *)0 ||
        outputs ==
            (npu_single_core_cycle_core_outputs_t *)0 ||
        top->initialized == 0u) {
        return;
    }
    (void)memset(outputs, 0, sizeof(*outputs));

    requested_module_clocks =
        external->scan_mode_i != 0u
            ? NPU_SINGLE_CORE_CLK_ALL
            : external->module_clk_en_i;
    core_was_released = top->last_crg.core_reset_n;
    single_crg_edge(
        top, 1u, external->core_rst_ni,
        external->noc_rst_ni,
        requested_module_clocks,
        external->dvfs_prepare_req_i, &crg_outputs);
    reset_n = crg_outputs.core_reset_n;
    active_mask = crg_outputs.module_clk_active_o;
    cfe_clock = single_clock_active(
        active_mask, NPU_SINGLE_CORE_CLK_CFE);
    ts_clock = single_clock_active(
        active_mask, NPU_SINGLE_CORE_CLK_TS);
    l1_clock = single_clock_active(
        active_mask, NPU_SINGLE_CORE_CLK_L1);
    if (core_was_released != 0u && reset_n == 0u) {
        single_capture_stale_gc_transport(top);
    }
    if (reset_n == 0u) {
        npu_model_reset(top->functional_model);
        top->last_functional_perf =
            top->functional_model->perf;
        top->pending_int_saturate_count = 0u;
        top->pending_all_mask_row_count = 0u;
        top->last_wdt_timeout_level = 0u;
    }
    mif_reset_abort =
        (uint8_t)(reset_n != 0u &&
                  top->cdc.core_epoch_sync1 !=
                      top->cdc_reset_epoch_seen_core);
    reset_abort_consumable =
        (uint8_t)(
            (ts_clock != 0u ||
             npu_ts_cycle_idle(&top->ts) != 0) &&
            (single_clock_active(
                 active_mask,
                 NPU_SINGLE_CORE_CLK_DMA) != 0u ||
             single_engine_quiescent(
                 &top->engine[0]) != 0u));

    /*
     * LSC control outputs are state-derived. The first preview supplies
     * quiesce/reset controls before the current idle and terminal inputs are
     * assembled below.
     */
    (void)memset(&lsc_inputs, 0, sizeof(lsc_inputs));
    lsc_inputs.reset_n = reset_n;
    lsc_inputs.issue_idle =
        npu_issue_adapter_cycle_idle(&top->issue);
    lsc_inputs.internal_soft_reset_done =
        (uint8_t)(top->mif_soft_reset_started_core != 0u &&
                  top->mif_soft_reset_pending_core == 0u);
    single_eval_lsc(&top->lsc, &lsc_inputs, &lsc_outputs);
    module_reset_n =
        (uint8_t)(reset_n != 0u &&
                  lsc_outputs.internal_soft_reset_pulse == 0u);

    (void)memset(&issue_outputs, 0, sizeof(issue_outputs));
    (void)memset(&cfe_outputs, 0, sizeof(cfe_outputs));
    (void)memset(&ts_outputs, 0, sizeof(ts_outputs));
    (void)memset(engine_outputs, 0,
                 sizeof(engine_outputs));
    (void)memset(&l1_outputs, 0, sizeof(l1_outputs));
    (void)memset(&cdc_outputs, 0, sizeof(cdc_outputs));
    (void)memset(&diag_outputs, 0, sizeof(diag_outputs));
    (void)memset(&system_outputs, 0,
                 sizeof(system_outputs));
    (void)memset(&cmd_route, 0, sizeof(cmd_route));
    issue_quiesce =
        (uint8_t)(external->stop_fetch_i != 0u ||
                  external->dvfs_prepare_req_i != 0u ||
                  external->soft_reset_req_i != 0u ||
                  external->power_down_req_i != 0u ||
                  lsc_outputs.stop_fetch != 0u);

    single_build_system_inputs(
        external, &lsc_outputs, &diag_outputs,
        single_core_idle_state(top), 0u, 0u, 0u,
        module_reset_n, &system_inputs);
    single_eval_system(
        &top->system_axi, &system_inputs, &system_outputs);

    /*
     * Resolve control-side ready/valid signals from copies of pre-edge
     * module state. Three passes cover Issue->CFE->TS and TS->Engine->TS.
     * No copied evaluation writes memory or advances functional operators.
     */
    for (iteration = 0u; iteration < 3u; iteration++) {
        single_route_command(
            top, &issue_outputs, &system_outputs,
            &cfe_outputs, &cmd_route);
        single_build_issue_inputs(
            external, &ts_outputs, issue_quiesce,
            cmd_route.issue_ready,
            cmd_route.issue_rsp_valid,
            cmd_route.issue_rsp_data,
            module_reset_n, &issue_inputs);
        single_eval_issue(
            &top->issue, &issue_inputs, &issue_outputs);
        single_route_command(
            top, &issue_outputs, &system_outputs,
            &cfe_outputs, &cmd_route);
        single_build_cfe_inputs(
            &ts_outputs, &lsc_outputs,
            cmd_route.cfe_valid, cmd_route.cfe_data,
            cmd_route.cfe_first, cmd_route.cfe_last,
            cmd_route.cfe_rsp_ready,
            cmd_route.source_busy,
            module_reset_n, &cfe_inputs);
        single_eval_cfe(
            &top->cfe, &cfe_inputs, &cfe_outputs);
        if (cfe_clock == 0u) {
            single_gate_cfe_outputs(
                &top->cfe, &cfe_outputs);
        }
        single_route_command(
            top, &issue_outputs, &system_outputs,
            &cfe_outputs, &cmd_route);
        single_build_system_inputs(
            external, &lsc_outputs, &diag_outputs,
            single_core_idle_state(top),
            cmd_route.axi_ready,
            cmd_route.axi_rsp_valid,
            cmd_route.axi_rsp_data,
            module_reset_n, &system_inputs);
        single_eval_system(
            &top->system_axi, &system_inputs,
            &system_outputs);
        single_build_ts_inputs(
            &issue_outputs, &cfe_outputs,
            engine_outputs, &cdc_outputs, &lsc_outputs,
            mif_reset_abort, module_reset_n, &ts_inputs);
        single_eval_ts(
            &top->ts, &ts_inputs, &ts_outputs);
        if (ts_clock == 0u) {
            single_gate_ts_outputs(
                &top->ts, &ts_outputs);
        }
        single_build_engine_inputs(
            &ts_outputs, &lsc_outputs, &l1_outputs,
            &cdc_outputs, mif_reset_abort, module_reset_n,
            engine_inputs);
        for (index = 0u;
             index < NPU_TS_ENGINE_COUNT; index++) {
            npu_engine_data_cycle_eval(
                &top->engine[index],
                &engine_inputs[index],
                &engine_outputs[index]);
            if (single_clock_active(
                    active_mask,
                    (uint8_t)(NPU_SINGLE_CORE_CLK_DMA +
                              index)) == 0u) {
                single_gate_engine_outputs(
                    &top->engine[index],
                    &engine_outputs[index]);
            }
        }
    }

    single_filter_stale_gc_inputs(
        top, &external->gc_axi, &gc_axi_inputs,
        &stale_gc_read, &stale_gc_write);
    gc_axi_inputs.reset_n = module_reset_n;
    gc_axi_inputs.quiesce =
        (uint8_t)(gc_axi_inputs.quiesce != 0u ||
                  lsc_outputs.stop_fetch != 0u ||
                  external->dvfs_prepare_req_i != 0u);
    gc_axi_inputs.error_clear =
        lsc_outputs.external_error_clear_o;
    single_eval_gc_axi(
        &top->gc_axi, &gc_axi_inputs, &gc_axi_outputs);
    if (module_reset_n != 0u) {
        single_apply_stale_gc_gates(
            top, stale_gc_read, stale_gc_write,
            &gc_axi_outputs);
    }
    access_idle = single_system_access_idle(
        top, external, &issue_outputs,
        &gc_axi_inputs, &gc_axi_outputs);

    /*
     * System/diagnostic outputs are also pre-edge state signals. A request
     * accepted by an idle adapter cannot reach L1 until a later cycle.
     */
    single_build_diag_inputs(
        &system_outputs, &l1_outputs,
        lsc_outputs.external_error_clear_o,
        module_reset_n, &diag_inputs);
    single_eval_diag(
        &top->l1_diag, &diag_inputs, &diag_outputs);
    single_build_system_inputs(
        external, &lsc_outputs, &diag_outputs,
        access_idle, cmd_route.axi_ready,
        cmd_route.axi_rsp_valid,
        cmd_route.axi_rsp_data, module_reset_n,
        &system_inputs);
    single_eval_system(
        &top->system_axi, &system_inputs, &system_outputs);
    single_build_diag_inputs(
        &system_outputs, &l1_outputs,
        lsc_outputs.external_error_clear_o,
        module_reset_n, &diag_inputs);
    single_eval_diag(
        &top->l1_diag, &diag_inputs, &diag_outputs);

    /*
     * Engine and Debug requests are independent of the returned ready. L1
     * can therefore commit first and its pre-edge outputs can be supplied to
     * every requester when those modules commit later in this function.
     */
    single_build_l1_inputs(
        top, engine_outputs, &diag_outputs, &lsc_outputs,
        lsc_outputs.external_error_clear_o,
        module_reset_n, &l1_inputs);
    if (module_reset_n == 0u || l1_clock != 0u ||
        lsc_outputs.external_error_clear_o != 0u) {
        npu_l1_cycle_step(
            &top->l1, &l1_inputs, &l1_outputs);
    } else {
        single_gate_l1_outputs(&top->l1, &l1_outputs);
    }

    /*
     * L1 outputs are the pins for the edge just committed above. Rebuild the
     * Debug adapter inputs so it observes the same request or response
     * handshake that L1 observed.
     */
    single_build_diag_inputs(
        &system_outputs, &l1_outputs,
        lsc_outputs.external_error_clear_o,
        module_reset_n, &diag_inputs);
    single_eval_diag(
        &top->l1_diag, &diag_inputs, &diag_outputs);

    single_build_cdc_core_inputs(
        &ts_outputs, &engine_outputs[0],
        module_reset_n, &cdc_inputs);
    npu_mif_cdc_core_tick(
        &top->cdc, &cdc_inputs, &cdc_outputs);

    /*
     * Current L1 and CDC responses can complete a replay. Re-evaluate the
     * control graph with those exact pins before committing TS and engines.
     */
    for (iteration = 0u; iteration < 3u; iteration++) {
        single_build_engine_inputs(
            &ts_outputs, &lsc_outputs, &l1_outputs,
            &cdc_outputs, mif_reset_abort, module_reset_n,
            engine_inputs);
        for (index = 0u;
             index < NPU_TS_ENGINE_COUNT; index++) {
            npu_engine_data_cycle_eval(
                &top->engine[index],
                &engine_inputs[index],
                &engine_outputs[index]);
            if (single_clock_active(
                    active_mask,
                    (uint8_t)(NPU_SINGLE_CORE_CLK_DMA +
                              index)) == 0u) {
                single_gate_engine_outputs(
                    &top->engine[index],
                    &engine_outputs[index]);
            }
        }
        single_build_ts_inputs(
            &issue_outputs, &cfe_outputs,
            engine_outputs, &cdc_outputs, &lsc_outputs,
            mif_reset_abort, module_reset_n, &ts_inputs);
        single_eval_ts(
            &top->ts, &ts_inputs, &ts_outputs);
        if (ts_clock == 0u) {
            single_gate_ts_outputs(
                &top->ts, &ts_outputs);
        }
        single_route_command(
            top, &issue_outputs, &system_outputs,
            &cfe_outputs, &cmd_route);
        single_build_cfe_inputs(
            &ts_outputs, &lsc_outputs,
            cmd_route.cfe_valid, cmd_route.cfe_data,
            cmd_route.cfe_first, cmd_route.cfe_last,
            cmd_route.cfe_rsp_ready,
            cmd_route.source_busy,
            module_reset_n, &cfe_inputs);
        single_eval_cfe(
            &top->cfe, &cfe_inputs, &cfe_outputs);
        if (cfe_clock == 0u) {
            single_gate_cfe_outputs(
                &top->cfe, &cfe_outputs);
        }
        single_route_command(
            top, &issue_outputs, &system_outputs,
            &cfe_outputs, &cmd_route);
        single_build_issue_inputs(
            external, &ts_outputs, issue_quiesce,
            cmd_route.issue_ready,
            cmd_route.issue_rsp_valid,
            cmd_route.issue_rsp_data,
            module_reset_n, &issue_inputs);
        single_eval_issue(
            &top->issue, &issue_inputs, &issue_outputs);
        single_route_command(
            top, &issue_outputs, &system_outputs,
            &cfe_outputs, &cmd_route);
        single_build_system_inputs(
            external, &lsc_outputs, &diag_outputs,
            access_idle, cmd_route.axi_ready,
            cmd_route.axi_rsp_valid,
            cmd_route.axi_rsp_data, module_reset_n,
            &system_inputs);
        single_eval_system(
            &top->system_axi, &system_inputs,
            &system_outputs);
    }

    single_eval_gc_axi(
        &top->gc_axi, &gc_axi_inputs, &gc_axi_outputs);
    if (module_reset_n != 0u) {
        single_apply_stale_gc_gates(
            top, stale_gc_read, stale_gc_write,
            &gc_axi_outputs);
    }

    single_build_system_inputs(
        external, &lsc_outputs, &diag_outputs,
        access_idle, cmd_route.axi_ready,
        cmd_route.axi_rsp_valid,
        cmd_route.axi_rsp_data, module_reset_n,
        &system_inputs);
    single_eval_system(
        &top->system_axi, &system_inputs, &system_outputs);
    single_update_l1_ecc_record(
        top, &l1_outputs,
        lsc_outputs.external_error_clear_o,
        module_reset_n);
    single_build_lsc_inputs(
        top, external, &system_outputs, &cfe_outputs,
        &ts_outputs, engine_outputs, &diag_outputs,
        &l1_outputs,
        &gc_axi_outputs, &cdc_outputs, reset_n,
        &lsc_inputs);
    single_eval_lsc(
        &top->lsc, &lsc_inputs, &lsc_outputs);

    progress = single_task_progress(
        top, external, &issue_outputs, &cmd_route,
        &cfe_outputs, &ts_outputs,
        engine_outputs, &diag_outputs, &l1_outputs,
        &cdc_outputs, &gc_axi_inputs, &gc_axi_outputs);
    (void)memset(&wdt_inputs, 0, sizeof(wdt_inputs));
    wdt_inputs.reset_n = module_reset_n;
    wdt_inputs.enable = external->wdt_enable_i;
    wdt_inputs.kick = external->wdt_kick_i;
    wdt_inputs.core_progress = progress;
    wdt_inputs.timeout_cycles =
        external->wdt_timeout_cycles_i;

    /*
     * Commit each Core-domain sequential block exactly once. L1 and CDC were
     * committed above because their pre-edge pins were needed to finalize
     * the connected requesters.
     */
    single_update_command_source(
        top, &cmd_route, &cfe_outputs, module_reset_n);
    npu_issue_adapter_cycle_step(
        &top->issue, &issue_inputs, &ignored_issue);
    if (module_reset_n == 0u || cfe_clock != 0u) {
        npu_cfe_cycle_step(
            &top->cfe, &cfe_inputs, &ignored_cfe);
    }
    if (module_reset_n == 0u || ts_clock != 0u) {
        npu_ts_cycle_step(
            &top->ts, &ts_inputs, &ignored_ts);
    }
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        if (module_reset_n == 0u ||
            single_clock_active(
                active_mask,
                (uint8_t)(NPU_SINGLE_CORE_CLK_DMA +
                          index)) != 0u) {
            npu_engine_data_cycle_step(
                &top->engine[index], &engine_inputs[index],
                &ignored_engine);
        }
    }
    npu_l1_diag_bridge_step(
        &top->l1_diag, &diag_inputs, &ignored_diag);
    npu_sys_slave_cycle_step(
        &top->system_axi, &system_inputs, &ignored_system);
    npu_lsc_cycle_step(
        &top->lsc, &lsc_inputs, &ignored_lsc);
    top->pending_int_saturate_count = 0u;
    top->pending_all_mask_row_count = 0u;
    single_capture_functional_perf(top);
    npu_gc_axi_cycle_step(
        &top->gc_axi, &gc_axi_inputs, &ignored_gc_axi);
    if (module_reset_n != 0u) {
        single_consume_stale_gc_transport(
            top, &external->gc_axi, &gc_axi_outputs,
            stale_gc_read, stale_gc_write);
    }
    npu_wdt_cycle(&top->wdt, &wdt_inputs, &wdt_outputs);

    if (module_reset_n == 0u) {
        top->ts.wire_limits = top->wire_limits;
    }
    top->last_wdt_timeout_level =
        reset_n != 0u ? top->last_wdt.timeout : 0u;
    top->last_wdt = wdt_outputs;
    top->last_lsc = lsc_outputs;
    single_update_mif_core_config(top, &lsc_outputs);

    if (reset_n == 0u) {
        (void)memset(&top->mif_diag_sync0, 0,
                     sizeof(top->mif_diag_sync0));
        (void)memset(&top->mif_diag_sync1, 0,
                     sizeof(top->mif_diag_sync1));
        top->mif_error_clear_toggle_core = 0u;
        top->mif_error_clear_ack_sync0_core = 0u;
        top->mif_error_clear_ack_sync1_core = 0u;
        top->mif_error_clear_pending_core = 0u;
        top->mif_soft_reset_toggle_core = 0u;
        top->mif_soft_reset_ack_sync0_core = 0u;
        top->mif_soft_reset_ack_sync1_core = 0u;
        top->mif_soft_reset_pending_core = 0u;
        top->mif_soft_reset_started_core = 0u;
        top->mif_idle_sync0_core = 0u;
        top->mif_idle_sync1_core = 0u;
        top->cdc_reset_epoch_seen_core =
            top->cdc.core_epoch_sync1;
    } else {
        if (module_reset_n == 0u ||
            (mif_reset_abort != 0u &&
             reset_abort_consumable != 0u)) {
            top->cdc_reset_epoch_seen_core =
                top->cdc.core_epoch_sync1;
        }
        if (lsc_outputs.external_error_clear_o != 0u &&
            top->mif_error_clear_pending_core == 0u) {
            top->mif_error_clear_toggle_core ^= 1u;
            top->mif_error_clear_pending_core = 1u;
        }
        if (lsc_outputs.internal_soft_reset_pulse != 0u &&
            top->mif_soft_reset_pending_core == 0u) {
            top->mif_soft_reset_toggle_core ^= 1u;
            top->mif_soft_reset_pending_core = 1u;
            top->mif_soft_reset_started_core = 1u;
        }

        top->mif_diag_sync1 = top->mif_diag_sync0;
        top->mif_diag_sync0 = top->mif_diag_source;
        top->mif_idle_sync1_core =
            top->mif_idle_sync0_core;
        top->mif_idle_sync0_core =
            top->mif_idle_source_noc;
        top->mif_error_clear_ack_sync1_core =
            top->mif_error_clear_ack_sync0_core;
        top->mif_error_clear_ack_sync0_core =
            top->mif_error_clear_ack_noc;
        if (top->mif_error_clear_pending_core != 0u &&
            top->mif_error_clear_ack_sync1_core ==
                top->mif_error_clear_toggle_core) {
            top->mif_error_clear_pending_core = 0u;
        }
        top->mif_soft_reset_ack_sync1_core =
            top->mif_soft_reset_ack_sync0_core;
        top->mif_soft_reset_ack_sync0_core =
            top->mif_soft_reset_ack_noc;
        if (top->mif_soft_reset_pending_core != 0u &&
            top->mif_soft_reset_ack_sync1_core ==
                top->mif_soft_reset_toggle_core) {
            top->mif_soft_reset_pending_core = 0u;
        }
        if (top->lsc.soft_state == NPU_LSC_SOFT_IDLE) {
            top->mif_soft_reset_started_core = 0u;
        }
    }

    outputs->crg = crg_outputs;
    outputs->wdt = wdt_outputs;
    outputs->issue = issue_outputs;
    outputs->system_axi = system_outputs;
    outputs->gc_axi = gc_axi_outputs;
    outputs->cfe = cfe_outputs;
    outputs->ts = ts_outputs;
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        outputs->engine[index] = engine_outputs[index];
    }
    outputs->l1_diag = diag_outputs;
    outputs->l1 = l1_outputs;
    outputs->lsc = lsc_outputs;
    outputs->cdc = cdc_outputs;
    outputs->core_reset_n = reset_n;
    outputs->module_clk_active_o =
        crg_outputs.module_clk_active_o;
    outputs->effective_stop_fetch_o =
        (uint8_t)(external->stop_fetch_i != 0u ||
                  external->dvfs_prepare_req_i != 0u ||
                  lsc_outputs.stop_fetch != 0u);
    outputs->clk_req_o =
        (uint8_t)(external->scan_mode_i != 0u ||
                  lsc_outputs.power_down_ack == 0u);
    outputs->soft_reset_done_o =
        lsc_outputs.soft_reset_done;
    outputs->power_down_ack_o =
        lsc_outputs.power_down_ack;
    outputs->wdt_reset_req_o = wdt_outputs.reset_req;
    outputs->core_idle_o = lsc_outputs.core_idle;
    outputs->irq_done_o = lsc_outputs.irq_done;
    outputs->irq_exception_o = lsc_outputs.irq_exception;
    outputs->irq_error_o = lsc_outputs.irq_error;
    outputs->progress_pulse_o = progress;
    outputs->core_cycle = top->core_cycle;

    if (reset_n == 0u) {
        top->core_cycle = 0u;
    } else {
        top->core_cycle++;
    }
}

static void single_build_mif_inputs(
    const npu_single_core_cycle_noc_inputs_t *external,
    const npu_mif_cdc_noc_outputs_t *cdc,
    const npu_mif_tbu_inputs_t *tbu,
    const npu_mif_cycle_config_t *config,
    uint8_t error_clear,
    uint8_t reset_n,
    npu_mif_cycle_inputs_t *inputs)
{
    uint32_t port;

    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = reset_n;
    inputs->error_clear = error_clear;
    inputs->config_valid = 1u;
    inputs->ddr_enable = config->ddr_enable;
    inputs->ddr_base = config->ddr_base;
    inputs->ddr_limit = config->ddr_limit;
    inputs->ext_enable = config->ext_enable;
    inputs->ext_base = config->ext_base;
    inputs->ext_limit = config->ext_limit;
    inputs->bypass_enable = config->bypass_enable;
    inputs->bypass_base = config->bypass_base;
    inputs->bypass_limit = config->bypass_limit;
    inputs->tbu_stream_id = config->tbu_stream_id;
    inputs->tbu_substream_id = config->tbu_substream_id;
    for (port = 0u; port < NPU_MIF_OWNER_COUNT; port++) {
        inputs->owner[port] = cdc->owner[port];
    }
    inputs->tbu = *tbu;
    for (port = 0u; port < NPU_MIF_AXI_PORT_COUNT; port++) {
        inputs->axi[port] = external->axi[port];
    }
}

static void single_build_internal_tbu_inputs(
    const npu_mif_cycle_outputs_t *mif,
    uint8_t reset_n,
    npu_tbu_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = reset_n;
    inputs->req_valid = mif->tbu.req_valid;
    inputs->req_vaddr = mif->tbu.req_vaddr;
    inputs->req_write = mif->tbu.req_write;
    inputs->req_stream_id = mif->tbu.req_stream_id;
    inputs->req_substream_id = mif->tbu.req_substream_id;
    inputs->req_tag = mif->tbu.req_tag;
    inputs->rsp_ready = mif->tbu.rsp_ready;
}

static void single_tbu_to_mif_inputs(
    const npu_tbu_cycle_outputs_t *tbu,
    npu_mif_tbu_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->req_ready = tbu->req_ready;
    inputs->rsp_valid = tbu->rsp_valid;
    inputs->rsp_paddr = tbu->rsp_paddr;
    inputs->rsp_tag = tbu->rsp_tag;
    inputs->rsp_status = tbu->rsp_status;
}

static void single_build_cdc_noc_inputs(
    const npu_mif_cycle_outputs_t *mif,
    uint8_t reset_n,
    npu_mif_cdc_noc_inputs_t *inputs)
{
    uint32_t owner;

    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->reset_n = reset_n;
    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        inputs->owner[owner] = mif->owner[owner];
    }
}

static void single_filter_stale_noc_inputs(
    const npu_single_core_cycle_t *top,
    const npu_single_core_cycle_noc_inputs_t *external,
    npu_single_core_cycle_noc_inputs_t *filtered,
    uint8_t stale_read[NPU_MIF_AXI_PORT_COUNT],
    uint8_t stale_write[NPU_MIF_AXI_PORT_COUNT],
    uint8_t *stale_tbu)
{
    uint8_t port;

    *filtered = *external;
    (void)memset(stale_read, 0,
                 NPU_MIF_AXI_PORT_COUNT *
                     sizeof(stale_read[0]));
    (void)memset(stale_write, 0,
                 NPU_MIF_AXI_PORT_COUNT *
                     sizeof(stale_write[0]));
    *stale_tbu = 0u;

    for (port = 0u; port < NPU_MIF_AXI_PORT_COUNT;
         port++) {
        const npu_mif_axi_inputs_t *axi =
            &external->axi[port];

        if (axi->rvalid != 0u &&
            (top->stale_axi_read_beats[port][axi->rid] != 0u ||
             top->stale_axi_read_wait_rlast[port][axi->rid] !=
                 0u)) {
            filtered->axi[port].rvalid = 0u;
            stale_read[port] = 1u;
        }
        if (axi->bvalid != 0u &&
            top->stale_axi_write_pending[port][axi->bid] !=
                0u) {
            filtered->axi[port].bvalid = 0u;
            stale_write[port] = 1u;
        }
    }

    if (top->tbu_mode == NPU_SINGLE_CORE_TBU_EXTERNAL &&
        external->tbu.rsp_valid != 0u &&
        single_stale_tbu_tag_present(
            top, external->tbu.rsp_tag) != 0u) {
        filtered->tbu.rsp_valid = 0u;
        *stale_tbu = 1u;
    }
}

static void single_apply_stale_mif_write_drain(
    const npu_single_core_cycle_t *top,
    npu_mif_cycle_outputs_t *mif)
{
    const npu_single_core_stale_write_t *drain;
    npu_mif_axi_outputs_t *axi;

    if (top->stale_axi_write_drain_count == 0u) {
        return;
    }
    drain = &top->stale_axi_write_drain[
        top->stale_axi_write_drain_head];
    if (drain->port >= NPU_MIF_AXI_PORT_COUNT) {
        return;
    }
    axi = &mif->axi[drain->port];
    axi->wdata = 0u;
    axi->wstrb = 0u;
    axi->wlast =
        drain->beats_remaining == 1u ? 1u : 0u;
    axi->wvalid = 1u;
    mif->mif_idle = 0u;
    mif->wr_outstanding =
        top->stale_axi_write_drain_count;
}

static uint8_t single_gate_stale_tbu_requests(
    const npu_single_core_cycle_t *top,
    uint8_t allow_new_requests,
    npu_mif_cdc_noc_outputs_t *cdc)
{
    uint8_t blocked = 0u;
    uint8_t owner;

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        npu_mif_owner_inputs_t *request =
            &cdc->owner[owner];
        uint16_t tbu_tag =
            (uint16_t)(((uint16_t)owner << 12u) |
                       (request->req_tag & 0x0fffu));

        if (request->req_valid != 0u &&
            (allow_new_requests == 0u ||
             single_stale_tbu_tag_present(
                 top, tbu_tag) != 0u)) {
            request->req_valid = 0u;
            blocked |= (uint8_t)(1u << owner);
        }
    }
    return blocked;
}

static void single_apply_noc_response_gates(
    const uint8_t stale_read[NPU_MIF_AXI_PORT_COUNT],
    const uint8_t stale_write[NPU_MIF_AXI_PORT_COUNT],
    uint8_t stale_tbu,
    uint8_t blocked_owner_mask,
    npu_mif_cycle_outputs_t *mif)
{
    uint8_t port;
    uint8_t owner;

    for (port = 0u; port < NPU_MIF_AXI_PORT_COUNT;
         port++) {
        if (stale_read[port] != 0u) {
            mif->axi[port].rready = 1u;
        }
        if (stale_write[port] != 0u) {
            mif->axi[port].bready = 1u;
        }
    }
    if (stale_tbu != 0u) {
        mif->tbu.rsp_ready = 1u;
    }
    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        if ((blocked_owner_mask & (uint8_t)(1u << owner)) !=
            0u) {
            mif->owner[owner].req_ready = 0u;
        }
    }
}

static void single_consume_stale_noc_responses(
    npu_single_core_cycle_t *top,
    const npu_single_core_cycle_noc_inputs_t *external,
    const npu_mif_cycle_outputs_t *mif,
    const uint8_t stale_read[NPU_MIF_AXI_PORT_COUNT],
    const uint8_t stale_write[NPU_MIF_AXI_PORT_COUNT],
    uint8_t stale_tbu)
{
    uint8_t port;

    for (port = 0u; port < NPU_MIF_AXI_PORT_COUNT;
         port++) {
        const npu_mif_axi_inputs_t *axi =
            &external->axi[port];

        if (stale_read[port] != 0u &&
            axi->rvalid != 0u &&
            mif->axi[port].rready != 0u) {
            single_consume_stale_read(
                &top->stale_axi_read_beats[port][axi->rid],
                &top->stale_axi_read_wait_rlast[port][axi->rid],
                axi->rlast);
            top->stale_axi_read_drop_count++;
        }
        if (stale_write[port] != 0u &&
            axi->bvalid != 0u &&
            mif->axi[port].bready != 0u) {
            top->stale_axi_write_pending[port][axi->bid] = 0u;
            top->stale_axi_write_drop_count++;
        }
    }
    if (top->stale_axi_write_drain_count != 0u) {
        npu_single_core_stale_write_t *drain =
            &top->stale_axi_write_drain[
                top->stale_axi_write_drain_head];

        if (drain->port < NPU_MIF_AXI_PORT_COUNT &&
            mif->axi[drain->port].wvalid != 0u &&
            external->axi[drain->port].wready != 0u) {
            if (drain->beats_remaining != 0u) {
                drain->beats_remaining--;
                top->stale_axi_w_drain_count++;
            }
            if (drain->beats_remaining == 0u) {
                single_stale_write_pop(
                    top->stale_axi_write_drain,
                    &top->stale_axi_write_drain_head,
                    &top->stale_axi_write_drain_count);
            }
        }
    }

    if (stale_tbu != 0u &&
        external->tbu.rsp_valid != 0u &&
        mif->tbu.rsp_ready != 0u) {
        single_remove_stale_tbu_tag(
            top, external->tbu.rsp_tag);
        top->stale_tbu_drop_count++;
    }
}

void npu_single_core_cycle_noc_tick(
    npu_single_core_cycle_t *top,
    const npu_single_core_cycle_noc_inputs_t *external,
    npu_single_core_cycle_noc_outputs_t *outputs)
{
    npu_single_core_cycle_noc_inputs_t filtered_external;
    npu_crg_outputs_t crg_outputs;
    npu_mif_cdc_noc_inputs_t cdc_inputs;
    npu_mif_cdc_noc_outputs_t cdc_outputs;
    npu_mif_cycle_inputs_t mif_inputs;
    npu_mif_cycle_outputs_t mif_outputs;
    npu_mif_cycle_outputs_t ignored_mif;
    npu_mif_tbu_inputs_t mif_tbu_inputs;
    npu_tbu_cycle_inputs_t tbu_inputs;
    npu_tbu_cycle_outputs_t tbu_outputs;
    npu_tbu_cycle_outputs_t ignored_tbu;
    npu_mif_cdc_noc_outputs_t ignored_cdc;
    uint8_t reset_n;
    uint8_t mif_clock;
    uint8_t clear_event;
    uint8_t soft_reset_event;
    uint8_t cdc_epoch_event;
    uint8_t mif_reset_n;
    uint8_t mif_run_clock;
    uint8_t allow_new_requests;
    uint8_t blocked_owner_mask;
    uint8_t stale_read[NPU_MIF_AXI_PORT_COUNT];
    uint8_t stale_write[NPU_MIF_AXI_PORT_COUNT];
    uint8_t stale_tbu;
    uint8_t requested_module_clocks;
    uint32_t iteration;

    if (top == (npu_single_core_cycle_t *)0 ||
        external ==
            (const npu_single_core_cycle_noc_inputs_t *)0 ||
        outputs ==
            (npu_single_core_cycle_noc_outputs_t *)0 ||
        top->initialized == 0u) {
        return;
    }
    (void)memset(outputs, 0, sizeof(*outputs));

    requested_module_clocks =
        external->scan_mode_i != 0u
            ? NPU_SINGLE_CORE_CLK_ALL
            : external->module_clk_en_i;
    single_crg_edge(
        top, 0u, external->core_rst_ni,
        external->noc_rst_ni,
        requested_module_clocks,
        external->dvfs_prepare_req_i, &crg_outputs);
    reset_n = crg_outputs.noc_reset_n;
    mif_clock = single_clock_active(
        crg_outputs.module_clk_active_o,
        NPU_SINGLE_CORE_CLK_MIF);
    clear_event =
        (uint8_t)(reset_n != 0u &&
                  top->mif_error_clear_sync1_noc !=
                      top->mif_error_clear_seen_noc);
    soft_reset_event =
        (uint8_t)(reset_n != 0u &&
                  top->mif_soft_reset_sync1_noc !=
                      top->mif_soft_reset_seen_noc);
    cdc_epoch_event =
        (uint8_t)(reset_n != 0u &&
                  top->cdc.noc_epoch_sync1 !=
                      top->cdc_reset_epoch_seen_noc);
    if (reset_n == 0u) {
        single_clear_stale_transport(top);
    } else if (cdc_epoch_event != 0u) {
        single_capture_stale_transport(top);
    }
    single_filter_stale_noc_inputs(
        top, external, &filtered_external, stale_read,
        stale_write, &stale_tbu);
    mif_reset_n =
        (uint8_t)(reset_n != 0u &&
                  soft_reset_event == 0u &&
                  cdc_epoch_event == 0u);
    mif_run_clock =
        (uint8_t)(mif_clock != 0u ||
                  clear_event != 0u ||
                  soft_reset_event != 0u ||
                  cdc_epoch_event != 0u);
    allow_new_requests =
        (uint8_t)(mif_reset_n != 0u &&
                  mif_run_clock != 0u &&
                  top->stale_axi_write_drain_count == 0u &&
                  single_prepare_clean_axi_ids(top) != 0u);

    /*
     * Resolve CDC, MIF, and the optional internal TBU from one pre-edge
     * snapshot. Three passes settle both request and response directions
     * without advancing any sequential state.
     */
    (void)memset(&mif_outputs, 0, sizeof(mif_outputs));
    (void)memset(&tbu_outputs, 0, sizeof(tbu_outputs));
    tbu_outputs.idle = 1u;
    for (iteration = 0u; iteration < 3u; iteration++) {
        single_build_cdc_noc_inputs(
            &mif_outputs, reset_n, &cdc_inputs);
        single_eval_cdc_noc(
            &top->cdc, &cdc_inputs, &cdc_outputs);
        blocked_owner_mask =
            single_gate_stale_tbu_requests(
                top, allow_new_requests, &cdc_outputs);
        if (top->tbu_mode ==
            NPU_SINGLE_CORE_TBU_INTERNAL) {
            single_build_internal_tbu_inputs(
                &mif_outputs, mif_reset_n, &tbu_inputs);
            single_eval_tbu(
                &top->tbu, &tbu_inputs, &tbu_outputs);
            single_tbu_to_mif_inputs(
                &tbu_outputs, &mif_tbu_inputs);
        } else {
            mif_tbu_inputs = filtered_external.tbu;
        }
        single_build_mif_inputs(
            &filtered_external, &cdc_outputs,
            &mif_tbu_inputs,
            &top->mif_config_sync1, clear_event,
            mif_reset_n, &mif_inputs);
        single_eval_mif(
            &top->mif, &mif_inputs, &mif_outputs);
        if (mif_run_clock == 0u) {
            single_gate_mif_outputs(
                &top->mif, &mif_outputs);
        }
        single_apply_noc_response_gates(
            stale_read, stale_write, stale_tbu,
            blocked_owner_mask, &mif_outputs);
        single_apply_stale_mif_write_drain(
            top, &mif_outputs);
    }

    if (mif_reset_n == 0u || mif_run_clock != 0u) {
        npu_mif_cycle_step(
            &top->mif, &mif_inputs, &ignored_mif);
    }
    if (top->tbu_mode == NPU_SINGLE_CORE_TBU_INTERNAL &&
        (mif_reset_n == 0u || mif_run_clock != 0u)) {
        npu_tbu_cycle_step(
            &top->tbu, &tbu_inputs, &ignored_tbu);
    } else if (reset_n == 0u) {
        npu_tbu_cycle_reset(&top->tbu);
    }
    npu_mif_cdc_noc_tick(
        &top->cdc, &cdc_inputs, &ignored_cdc);
    single_consume_stale_noc_responses(
        top, external, &mif_outputs, stale_read,
        stale_write, stale_tbu);

    top->mif_config_sync1 = top->mif_config_sync0;
    top->mif_config_sync0 = top->mif_config_core;
    top->last_mif = mif_outputs;
    if (reset_n == 0u) {
        top->mif_error_clear_sync0_noc =
            top->mif_error_clear_toggle_core;
        top->mif_error_clear_sync1_noc =
            top->mif_error_clear_toggle_core;
        top->mif_error_clear_seen_noc =
            top->mif_error_clear_toggle_core;
        top->mif_error_clear_ack_noc =
            top->mif_error_clear_toggle_core;
        top->mif_soft_reset_sync0_noc =
            top->mif_soft_reset_toggle_core;
        top->mif_soft_reset_sync1_noc =
            top->mif_soft_reset_toggle_core;
        top->mif_soft_reset_seen_noc =
            top->mif_soft_reset_toggle_core;
        top->mif_soft_reset_ack_noc =
            top->mif_soft_reset_toggle_core;
        (void)memset(&top->mif_diag_source, 0,
                     sizeof(top->mif_diag_source));
        top->mif_idle_source_noc = 1u;
        top->cdc_reset_epoch_seen_noc =
            top->cdc.noc_epoch_sync1;
    } else {
        if (clear_event != 0u) {
            top->mif_error_clear_ack_noc =
                top->mif_error_clear_sync1_noc;
        }
        top->mif_error_clear_seen_noc =
            top->mif_error_clear_sync1_noc;
        top->mif_error_clear_sync1_noc =
            top->mif_error_clear_sync0_noc;
        top->mif_error_clear_sync0_noc =
            top->mif_error_clear_toggle_core;

        top->mif_soft_reset_seen_noc =
            top->mif_soft_reset_sync1_noc;
        if (soft_reset_event != 0u) {
            top->mif_soft_reset_ack_noc =
                top->mif_soft_reset_sync1_noc;
        }
        top->mif_soft_reset_sync1_noc =
            top->mif_soft_reset_sync0_noc;
        top->mif_soft_reset_sync0_noc =
            top->mif_soft_reset_toggle_core;
        single_capture_mif_diag(
            &top->mif, &top->mif_diag_source);
        top->mif_idle_source_noc =
            (uint8_t)(
                npu_mif_cycle_is_idle(&top->mif) != 0u &&
                single_internal_tbu_idle(top) != 0u &&
                single_stale_mif_transport_idle(top) != 0u);
        if (cdc_epoch_event != 0u) {
            top->cdc_reset_epoch_seen_noc =
                top->cdc.noc_epoch_sync1;
        }
    }

    outputs->crg = crg_outputs;
    outputs->cdc = cdc_outputs;
    outputs->mif = mif_outputs;
    outputs->tbu = tbu_outputs;
    outputs->noc_reset_n = reset_n;
    outputs->module_clk_active_o =
        crg_outputs.module_clk_active_o;
    outputs->noc_cycle = top->noc_cycle;
    if (reset_n == 0u) {
        top->noc_cycle = 0u;
    } else {
        top->noc_cycle++;
    }
}
