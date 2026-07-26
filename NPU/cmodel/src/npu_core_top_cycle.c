#include "npu_core_top_cycle.h"
#include "npu_capability_internal.h"

#include <stddef.h>
#include <string.h>

static void npu_core_top_eval_cfe(
    const npu_cfe_cycle_t *model,
    const npu_cfe_cycle_inputs_t *inputs,
    npu_cfe_cycle_outputs_t *outputs)
{
    npu_cfe_cycle_t preview = *model;

    npu_cfe_cycle_step(&preview, inputs, outputs);
}

static void npu_core_top_eval_ts(
    const npu_ts_cycle_t *model,
    const npu_ts_cycle_inputs_t *inputs,
    npu_ts_cycle_outputs_t *outputs)
{
    npu_ts_cycle_t preview = *model;

    npu_ts_cycle_step(&preview, inputs, outputs);
}

static void npu_core_top_eval_lsc(
    const npu_lsc_cycle_t *model,
    const npu_lsc_cycle_inputs_t *inputs,
    npu_lsc_cycle_outputs_t *outputs)
{
    npu_lsc_cycle_t preview = *model;

    npu_lsc_cycle_step(&preview, inputs, outputs);
}

static void npu_core_top_build_lsc_inputs(
    const npu_core_top_cycle_inputs_t *inputs,
    const npu_cfe_cycle_outputs_t *cfe,
    const npu_ts_cycle_outputs_t *ts,
    const npu_engine_cycle_outputs_t
        engine[NPU_TS_ENGINE_COUNT],
    npu_lsc_cycle_inputs_t *lsc_inputs)
{
    uint32_t index;
    uint8_t engine_quiescent = 0u;

    (void)memset(lsc_inputs, 0, sizeof(*lsc_inputs));
    lsc_inputs->reset_n = inputs->reset_n;
    lsc_inputs->reg_req_valid = inputs->reg_req_valid_i;
    lsc_inputs->reg_req_write = inputs->reg_req_write_i;
    lsc_inputs->reg_req_space = inputs->reg_req_space_i;
    lsc_inputs->reg_req_addr = inputs->reg_req_addr_i;
    lsc_inputs->reg_req_wdata = inputs->reg_req_wdata_i;
    lsc_inputs->reg_req_wstrb = inputs->reg_req_wstrb_i;
    lsc_inputs->reg_rsp_ready = inputs->reg_rsp_ready_i;
    lsc_inputs->soft_reset_req = inputs->soft_reset_req_i;
    /*
     * This control-only composition has no independently clocked MIF/TBU
     * state. Reaching WAIT_RESET therefore means every contained module
     * completed its one-cycle internal reset.
     */
    lsc_inputs->internal_soft_reset_done = 1u;
    lsc_inputs->power_down_req = inputs->power_down_req_i;
    lsc_inputs->core_wfi = inputs->core_wfi_i;
    lsc_inputs->issue_idle = 1u;
    lsc_inputs->l1_idle = inputs->l1_idle_i;
    lsc_inputs->l1_write_idle = inputs->l1_write_idle_i;
    lsc_inputs->mif_idle = inputs->mif_idle_i;
    lsc_inputs->gc_axi_idle = inputs->gc_axi_idle_i;
    lsc_inputs->wdt_timeout = inputs->wdt_timeout_i;
    for (index = 0u;
         index < NPU_LSC_PERF_COUNTER_COUNT;
         index++) {
        lsc_inputs->perf_increment[index] =
            inputs->perf_increment_i[index];
    }

    if (cfe != (const npu_cfe_cycle_outputs_t *)0) {
        lsc_inputs->cfe_idle = cfe->cfe_idle_o;
    }
    if (ts != (const npu_ts_cycle_outputs_t *)0) {
        lsc_inputs->ts_idle = ts->idle;
        lsc_inputs->ts_quiescent = ts->quiescent;
        lsc_inputs->task_terminal_valid = ts->terminal_valid;
        lsc_inputs->task_irq_on_success =
            ts->terminal_irq_on_success;
        lsc_inputs->task_irq_on_error =
            ts->terminal_irq_on_error;
        lsc_inputs->task_command_id = ts->terminal_task_id;
        lsc_inputs->task_status = ts->terminal_status;
        lsc_inputs->task_engine = ts->terminal_engine;
        lsc_inputs->task_opcode = ts->terminal_opcode;
        lsc_inputs->task_fault_addr =
            ts->terminal_fault_addr;
        lsc_inputs->task_error_info =
            ts->terminal_error_info;
        lsc_inputs->task_done_flags =
            ts->terminal_done_flags;
    }
    if (engine !=
        (const npu_engine_cycle_outputs_t *)0) {
        for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
            if (engine[index].eng_quiescent_o != 0u) {
                engine_quiescent |=
                    (uint8_t)(1u << index);
            }
        }
    }
    lsc_inputs->eng_quiescent = engine_quiescent;
}

static void npu_core_top_build_ts_inputs(
    const npu_core_top_cycle_inputs_t *inputs,
    const npu_lsc_cycle_outputs_t *lsc,
    const npu_cfe_cycle_outputs_t *cfe,
    const npu_engine_cycle_outputs_t
        engine[NPU_TS_ENGINE_COUNT],
    uint8_t module_reset_n,
    npu_ts_cycle_inputs_t *ts_inputs)
{
    uint32_t index;

    (void)memset(ts_inputs, 0, sizeof(*ts_inputs));
    ts_inputs->reset_n = module_reset_n;
    ts_inputs->stop_accept = lsc->stop_fetch;
    ts_inputs->quiesce_req = lsc->ts_quiesce;
    ts_inputs->abort_req =
        lsc->eng_abort != 0u ? 1u : 0u;
    for (index = 0u; index < NPU_TIMEOUT_CLASS_NUM; index++) {
        ts_inputs->timeout_cycles[index] =
            lsc->timeout_cycles[index];
    }

    ts_inputs->dfu.req_ready = inputs->df_mem_req_ready_i;
    ts_inputs->dfu.rsp_valid = inputs->df_mem_rsp_valid_i;
    ts_inputs->dfu.rsp_data = inputs->df_mem_rsp_data_i;
    ts_inputs->dfu.rsp_tag = inputs->df_mem_rsp_tag_i;
    ts_inputs->dfu.rsp_last = inputs->df_mem_rsp_last_i;
    ts_inputs->dfu.rsp_status =
        inputs->df_mem_rsp_status_i;

    ts_inputs->ctl.valid = inputs->gc_ctl_valid_i;
    ts_inputs->ctl.op = inputs->gc_ctl_op_i;
    ts_inputs->ctl.rs1 = inputs->gc_ctl_rs1_i;
    ts_inputs->ctl.rs2 = inputs->gc_ctl_rs2_i;
    ts_inputs->ctl.cancel = inputs->gc_ctl_cancel_i;
    ts_inputs->ctl.rsp_ready =
        inputs->gc_ctl_rsp_ready_i;

    if (cfe != (const npu_cfe_cycle_outputs_t *)0) {
        ts_inputs->cfe.valid = cfe->ts_cmd_valid_o;
        ts_inputs->cfe.data = cfe->ts_cmd_data_o;
        ts_inputs->cfe.first = cfe->ts_cmd_first_o;
        ts_inputs->cfe.last = cfe->ts_cmd_last_o;
        ts_inputs->cfe.lookup_valid =
            cfe->cmd_id_lookup_valid_o;
        ts_inputs->cfe.lookup_id =
            cfe->cmd_id_lookup_id_o;
    }

    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        if (engine !=
            (const npu_engine_cycle_outputs_t *)0) {
            ts_inputs->engine[index].req_ready =
                engine[index].eng_req_ready_o;
            ts_inputs->engine[index].cancel_ready =
                engine[index].eng_cancel_ready_o;
            ts_inputs->engine[index].done_valid =
                engine[index].eng_done_valid_o;
            ts_inputs->engine[index].done_data =
                engine[index].eng_done_data_o;
            ts_inputs->engine[index].done_first =
                engine[index].eng_done_first_o;
            ts_inputs->engine[index].done_last =
                engine[index].eng_done_last_o;
            ts_inputs->engine[index].quiescent =
                engine[index].eng_quiescent_o;
            ts_inputs->desc[index].req_valid =
                engine[index].desc_rd_req_valid_o;
            ts_inputs->desc[index].req_slot =
                engine[index].desc_rd_slot_o;
            ts_inputs->desc[index].req_word =
                engine[index].desc_rd_word_o;
            ts_inputs->desc[index].req_tag =
                engine[index].desc_rd_req_tag_o;
            ts_inputs->desc[index].rsp_ready =
                engine[index].desc_rd_rsp_ready_o;
        }
    }
}

static void npu_core_top_build_cfe_inputs(
    const npu_core_top_cycle_inputs_t *inputs,
    const npu_lsc_cycle_outputs_t *lsc,
    const npu_ts_cycle_outputs_t *ts,
    uint8_t module_reset_n,
    npu_cfe_cycle_inputs_t *cfe_inputs)
{
    (void)memset(cfe_inputs, 0, sizeof(*cfe_inputs));
    cfe_inputs->reset_n = module_reset_n;
    cfe_inputs->cfe_quiesce_i = lsc->cfe_quiesce;
    cfe_inputs->gc_cmd_valid_i = inputs->gc_cmd_valid_i;
    cfe_inputs->gc_cmd_data_i = inputs->gc_cmd_data_i;
    cfe_inputs->gc_cmd_first_i = inputs->gc_cmd_first_i;
    cfe_inputs->gc_cmd_last_i = inputs->gc_cmd_last_i;
    cfe_inputs->gc_rsp_ready_i = inputs->gc_rsp_ready_i;
    cfe_inputs->ts_cmd_ready_i = ts->cfe.ready;
    cfe_inputs->cmd_id_lookup_ready_i =
        ts->cfe.lookup_ready;
    cfe_inputs->cmd_id_lookup_rsp_valid_i =
        ts->cfe.lookup_rsp_valid;
    cfe_inputs->cmd_id_busy_i = ts->cfe.lookup_busy;
}

static void npu_core_top_build_engine_inputs(
    const npu_lsc_cycle_outputs_t *lsc,
    const npu_ts_cycle_outputs_t *ts,
    uint8_t module_reset_n,
    npu_engine_cycle_inputs_t
        engine_inputs[NPU_TS_ENGINE_COUNT])
{
    uint32_t index;

    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        npu_engine_cycle_inputs_t *engine =
            &engine_inputs[index];

        (void)memset(engine, 0, sizeof(*engine));
        engine->reset_n = module_reset_n;
        engine->eng_req_valid_i =
            ts->engine[index].req_valid;
        engine->eng_req_data_i =
            ts->engine[index].req_data;
        engine->eng_done_ready_i =
            ts->engine[index].done_ready;
        engine->eng_abort_i =
            (uint8_t)((lsc->eng_abort >> index) & 1u);
        engine->eng_cancel_valid_i =
            ts->engine[index].cancel_valid;
        engine->eng_cancel_status_i =
            ts->engine[index].cancel_status;
        engine->desc_rd_req_ready_i =
            ts->desc[index].req_ready;
        engine->desc_rd_rsp_valid_i =
            ts->desc[index].rsp_valid;
        engine->desc_rd_rsp_data_i =
            ts->desc[index].rsp_data;
        engine->desc_rd_rsp_tag_i =
            ts->desc[index].rsp_tag;
        engine->desc_rd_rsp_status_i =
            ts->desc[index].rsp_status;
    }
}

static void npu_core_top_copy_outputs(
    const npu_cfe_cycle_outputs_t *cfe,
    const npu_ts_cycle_outputs_t *ts,
    const npu_engine_cycle_outputs_t
        engine[NPU_TS_ENGINE_COUNT],
    const npu_lsc_cycle_outputs_t *lsc,
    uint64_t cycle,
    npu_core_top_cycle_outputs_t *outputs)
{
    uint32_t index;
    uint8_t engine_quiescent = 0u;
    uint8_t engine_busy = 0u;

    (void)memset(outputs, 0, sizeof(*outputs));
    outputs->cfe = *cfe;
    outputs->ts = *ts;
    outputs->lsc = *lsc;
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        outputs->engine[index] = engine[index];
        if (engine[index].eng_quiescent_o != 0u) {
            engine_quiescent |= (uint8_t)(1u << index);
        }
        if (engine[index].eng_busy_o != 0u) {
            engine_busy |= (uint8_t)(1u << index);
        }
    }

    outputs->gc_cmd_ready_o = cfe->gc_cmd_ready_o;
    outputs->gc_rsp_valid_o = cfe->gc_rsp_valid_o;
    outputs->gc_rsp_data_o = cfe->gc_rsp_data_o;
    outputs->gc_ctl_ready_o = ts->ctl.ready;
    outputs->gc_ctl_rsp_valid_o = ts->ctl.rsp_valid;
    outputs->gc_ctl_rsp_data_o = ts->ctl.rsp_data;
    outputs->reg_req_ready_o = lsc->reg_req_ready;
    outputs->reg_rsp_valid_o = lsc->reg_rsp_valid;
    outputs->reg_rsp_rdata_o = lsc->reg_rsp_rdata;
    outputs->reg_rsp_status_o = lsc->reg_rsp_status;
    outputs->df_mem_req_valid_o = ts->dfu.req_valid;
    outputs->df_mem_req_addr_o = ts->dfu.req_addr;
    outputs->df_mem_req_beats_o = ts->dfu.req_beats;
    outputs->df_mem_req_tag_o = ts->dfu.req_tag;
    outputs->df_mem_req_task_id_o =
        ts->dfu.req_task_id;
    outputs->df_mem_req_attr_o = ts->dfu.req_attr;
    outputs->df_mem_rsp_ready_o = ts->dfu.rsp_ready;

    outputs->cfe_quiesce_o = lsc->cfe_quiesce;
    outputs->ts_quiesce_o = lsc->ts_quiesce;
    outputs->eng_abort_o = lsc->eng_abort;
    outputs->stop_fetch_o = lsc->stop_fetch;
    outputs->single_step_pulse_o =
        lsc->single_step_pulse;
    outputs->internal_soft_reset_pulse_o =
        lsc->internal_soft_reset_pulse;
    outputs->soft_reset_done_o = lsc->soft_reset_done;
    outputs->power_down_ack_o = lsc->power_down_ack;
    outputs->core_idle_o = lsc->core_idle;
    outputs->irq_done_o = lsc->irq_done;
    outputs->irq_exception_o = lsc->irq_exception;
    outputs->irq_error_o = lsc->irq_error;

    outputs->cfe_idle_o = cfe->cfe_idle_o;
    outputs->ts_idle_o = ts->idle;
    outputs->ts_quiescent_o = ts->quiescent;
    outputs->eng_quiescent_o = engine_quiescent;
    outputs->eng_busy_o = engine_busy;
    outputs->cycle = cycle;
}

npu_status_t npu_core_top_cycle_init(
    npu_core_top_cycle_t *top,
    npu_model_t *functional_model,
    const npu_wire_limits_t *wire_limits,
    const npu_lsc_cycle_config_t *lsc_config)
{
    npu_wire_limits_t resolved_wire_limits;
    npu_lsc_cycle_config_t resolved_lsc_config;
    uint32_t index;
    npu_status_t status;

    if (top == (npu_core_top_cycle_t *)0 ||
        functional_model == (npu_model_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }

    if (wire_limits == (const npu_wire_limits_t *)0) {
        npu_wire_limits_reference(&resolved_wire_limits);
        if (functional_model->ddr_size <
            resolved_wire_limits.gaddr_limit) {
            resolved_wire_limits.gaddr_limit =
                (uint64_t)functional_model->ddr_size;
        }
    } else {
        resolved_wire_limits = *wire_limits;
    }
    if (lsc_config == (const npu_lsc_cycle_config_t *)0) {
        npu_lsc_cycle_config_reference(&resolved_lsc_config);
    } else {
        resolved_lsc_config = *lsc_config;
    }
    if (npu_capability_config_match(
            functional_model, &resolved_wire_limits,
            &resolved_lsc_config, 0u) == 0) {
        return NPU_STATUS_BAD_DESC;
    }

    (void)memset(top, 0, sizeof(*top));
    top->functional_model = functional_model;
    top->wire_limits = resolved_wire_limits;
    npu_cfe_cycle_reset(&top->cfe);
    npu_ts_cycle_init(&top->ts);
    top->ts.wire_limits = top->wire_limits;
    npu_lsc_cycle_init(&top->lsc, &resolved_lsc_config);
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        status = npu_engine_cycle_init(
            &top->engine[index], functional_model,
            (npu_engine_t)(index + 1u),
            &top->wire_limits);
        if (status != NPU_STATUS_SUCCESS) {
            (void)memset(top, 0, sizeof(*top));
            return status;
        }
    }
    top->initialized = 1u;
    top->cycle = 0u;
    return NPU_STATUS_SUCCESS;
}

void npu_core_top_cycle_reset(npu_core_top_cycle_t *top)
{
    uint32_t index;

    if (top == (npu_core_top_cycle_t *)0 ||
        top->initialized == 0u) {
        return;
    }
    npu_cfe_cycle_reset(&top->cfe);
    npu_ts_cycle_reset(&top->ts);
    top->ts.wire_limits = top->wire_limits;
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        npu_engine_cycle_reset(&top->engine[index]);
    }
    npu_lsc_cycle_reset(&top->lsc);
    top->cycle = 0u;
}

void npu_core_top_cycle_step(
    npu_core_top_cycle_t *top,
    const npu_core_top_cycle_inputs_t *inputs,
    npu_core_top_cycle_outputs_t *outputs)
{
    npu_lsc_cycle_inputs_t lsc_inputs;
    npu_lsc_cycle_outputs_t lsc_control;
    npu_lsc_cycle_outputs_t lsc_outputs;
    npu_cfe_cycle_inputs_t cfe_inputs;
    npu_cfe_cycle_outputs_t cfe_outputs;
    npu_ts_cycle_inputs_t ts_inputs;
    npu_ts_cycle_outputs_t ts_outputs;
    npu_engine_cycle_inputs_t
        engine_inputs[NPU_TS_ENGINE_COUNT];
    npu_engine_cycle_outputs_t
        engine_outputs[NPU_TS_ENGINE_COUNT];
    npu_cfe_cycle_outputs_t cfe_commit_outputs;
    npu_ts_cycle_outputs_t ts_commit_outputs;
    npu_engine_cycle_outputs_t engine_commit_outputs;
    npu_lsc_cycle_outputs_t lsc_commit_outputs;
    uint8_t module_reset_n;
    uint32_t index;

    if (top == (npu_core_top_cycle_t *)0 ||
        inputs == (const npu_core_top_cycle_inputs_t *)0 ||
        outputs == (npu_core_top_cycle_outputs_t *)0) {
        return;
    }
    if (top->initialized == 0u) {
        (void)memset(outputs, 0, sizeof(*outputs));
        return;
    }

    /*
     * LSC control signals depend only on LSC's pre-edge state. Module idle
     * inputs affect status reporting, so a second LSC evaluation below
     * supplies their exact current values.
     */
    npu_core_top_build_lsc_inputs(
        inputs, (const npu_cfe_cycle_outputs_t *)0,
        (const npu_ts_cycle_outputs_t *)0,
        (const npu_engine_cycle_outputs_t *)0,
        &lsc_inputs);
    npu_core_top_eval_lsc(
        &top->lsc, &lsc_inputs, &lsc_control);
    module_reset_n =
        (uint8_t)(inputs->reset_n != 0u &&
                  lsc_control.internal_soft_reset_pulse == 0u);

    /*
     * TS interface outputs do not depend combinationally on CFE valid or an
     * Engine ready value. This first evaluation therefore gives the signals
     * needed to evaluate CFE and all Engine Adapters.
     */
    npu_core_top_build_ts_inputs(
        inputs, &lsc_control,
        (const npu_cfe_cycle_outputs_t *)0,
        (const npu_engine_cycle_outputs_t *)0,
        module_reset_n, &ts_inputs);
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        ts_inputs.engine[index].quiescent =
            npu_engine_cycle_quiescent(&top->engine[index]);
    }
    npu_core_top_eval_ts(&top->ts, &ts_inputs, &ts_outputs);

    npu_core_top_build_cfe_inputs(
        inputs, &lsc_control, &ts_outputs,
        module_reset_n, &cfe_inputs);
    npu_core_top_eval_cfe(
        &top->cfe, &cfe_inputs, &cfe_outputs);

    npu_core_top_build_engine_inputs(
        &lsc_control, &ts_outputs, module_reset_n,
        engine_inputs);
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        npu_engine_cycle_eval(
            &top->engine[index], &engine_inputs[index],
            &engine_outputs[index]);
    }

    /*
     * Re-evaluate TS with the exact CFE and Engine outputs. This updates
     * idle/quiescent reporting and forms every handshake from one shared
     * pre-edge snapshot. Its driven interface values remain the values used
     * above, so there is no ordering-dependent extra cycle.
     */
    npu_core_top_build_ts_inputs(
        inputs, &lsc_control, &cfe_outputs,
        engine_outputs, module_reset_n, &ts_inputs);
    npu_core_top_eval_ts(&top->ts, &ts_inputs, &ts_outputs);

    npu_core_top_build_cfe_inputs(
        inputs, &lsc_control, &ts_outputs,
        module_reset_n, &cfe_inputs);
    npu_core_top_eval_cfe(
        &top->cfe, &cfe_inputs, &cfe_outputs);
    npu_core_top_build_engine_inputs(
        &lsc_control, &ts_outputs, module_reset_n,
        engine_inputs);
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        npu_engine_cycle_eval(
            &top->engine[index], &engine_inputs[index],
            &engine_outputs[index]);
    }
    npu_core_top_build_ts_inputs(
        inputs, &lsc_control, &cfe_outputs,
        engine_outputs, module_reset_n, &ts_inputs);
    npu_core_top_eval_ts(&top->ts, &ts_inputs, &ts_outputs);

    npu_core_top_build_lsc_inputs(
        inputs, &cfe_outputs, &ts_outputs,
        engine_outputs, &lsc_inputs);
    npu_core_top_eval_lsc(
        &top->lsc, &lsc_inputs, &lsc_outputs);

    npu_core_top_copy_outputs(
        &cfe_outputs, &ts_outputs, engine_outputs,
        &lsc_outputs, top->cycle, outputs);

    /*
     * Commit only after every current-cycle signal has been fixed. The
     * returned per-module outputs are discarded because they equal the
     * pre-edge snapshots copied above.
     */
    npu_cfe_cycle_step(
        &top->cfe, &cfe_inputs, &cfe_commit_outputs);
    npu_ts_cycle_step(
        &top->ts, &ts_inputs, &ts_commit_outputs);
    for (index = 0u; index < NPU_TS_ENGINE_COUNT; index++) {
        npu_engine_cycle_step(
            &top->engine[index], &engine_inputs[index],
            &engine_commit_outputs);
    }
    npu_lsc_cycle_step(
        &top->lsc, &lsc_inputs, &lsc_commit_outputs);

    if (module_reset_n == 0u) {
        top->ts.wire_limits = top->wire_limits;
    }
    if (inputs->reset_n == 0u) {
        top->cycle = 0u;
    } else {
        top->cycle++;
    }
}
