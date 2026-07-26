#include "npu_mif_cdc_cycle.h"

#include <stddef.h>
#include <string.h>

static uint64_t cdc_reader_write_seq(
    const npu_mif_cdc_fifo_control_t *control)
{
    return control->write_seq_at_reader[
        NPU_MIF_CDC_SYNC_STAGES - 1u];
}

static uint64_t cdc_writer_read_seq(
    const npu_mif_cdc_fifo_control_t *control)
{
    return control->read_seq_at_writer[
        NPU_MIF_CDC_SYNC_STAGES - 1u];
}

static uint8_t cdc_can_write(
    const npu_mif_cdc_fifo_control_t *control,
    uint64_t depth)
{
    uint64_t visible_read = cdc_writer_read_seq(control);

    if (control->write_seq < visible_read) {
        return 0u;
    }
    return control->write_seq - visible_read < depth ? 1u : 0u;
}

static uint8_t cdc_can_read(
    const npu_mif_cdc_fifo_control_t *control,
    uint64_t depth)
{
    uint64_t visible_write = cdc_reader_write_seq(control);

    if (visible_write < control->read_seq ||
        visible_write - control->read_seq > depth) {
        return 0u;
    }
    return visible_write != control->read_seq ? 1u : 0u;
}

static void cdc_sync_write_at_reader(
    npu_mif_cdc_fifo_control_t *control)
{
    uint8_t stage;

    for (stage = NPU_MIF_CDC_SYNC_STAGES - 1u;
         stage != 0u;
         stage--) {
        control->write_seq_at_reader[stage] =
            control->write_seq_at_reader[stage - 1u];
    }
    control->write_seq_at_reader[0] = control->write_seq;
}

static void cdc_sync_read_at_writer(
    npu_mif_cdc_fifo_control_t *control)
{
    uint8_t stage;

    for (stage = NPU_MIF_CDC_SYNC_STAGES - 1u;
         stage != 0u;
         stage--) {
        control->read_seq_at_writer[stage] =
            control->read_seq_at_writer[stage - 1u];
    }
    control->read_seq_at_writer[0] = control->read_seq;
}

static uint8_t cdc_level(
    const npu_mif_cdc_fifo_control_t *control,
    uint64_t depth)
{
    uint64_t level;

    if (control->write_seq < control->read_seq) {
        return 0u;
    }
    level = control->write_seq - control->read_seq;
    if (level > depth) {
        level = depth;
    }
    return (uint8_t)level;
}

static void cdc_clear_fifos(npu_mif_cdc_cycle_t *model)
{
    (void)memset(model->req_fifo, 0, sizeof(model->req_fifo));
    (void)memset(model->w_fifo, 0, sizeof(model->w_fifo));
    (void)memset(model->rsp_fifo, 0, sizeof(model->rsp_fifo));
    model->core_released = 0u;
    model->noc_released = 0u;
    model->core_tick_count = 0u;
    model->noc_tick_count = 0u;
}

static void cdc_assert_reset(npu_mif_cdc_cycle_t *model,
                             uint8_t core_domain)
{
    uint8_t first_assertion =
        core_domain != 0u
            ? (uint8_t)(model->core_reset_seen == 0u)
            : (uint8_t)(model->noc_reset_seen == 0u);

    if (first_assertion != 0u) {
        cdc_clear_fifos(model);
        model->reset_epoch++;
    }
    if (core_domain != 0u) {
        model->core_reset_seen = 1u;
        model->core_released = 0u;
        model->core_epoch_sync0 = model->reset_epoch;
        model->core_epoch_sync1 = model->reset_epoch;
    } else {
        model->noc_reset_seen = 1u;
        model->noc_released = 0u;
        model->noc_epoch_sync0 = model->reset_epoch;
        model->noc_epoch_sync1 = model->reset_epoch;
    }
}

static void cdc_sync_core_epoch(npu_mif_cdc_cycle_t *model)
{
    model->core_epoch_sync1 = model->core_epoch_sync0;
    model->core_epoch_sync0 = model->reset_epoch;
}

static void cdc_sync_noc_epoch(npu_mif_cdc_cycle_t *model)
{
    model->noc_epoch_sync1 = model->noc_epoch_sync0;
    model->noc_epoch_sync0 = model->reset_epoch;
}

static void cdc_core_fill_meta(
    const npu_mif_cdc_cycle_t *model,
    npu_mif_cdc_core_outputs_t *outputs)
{
    outputs->reset_epoch = model->core_epoch_sync1;
    outputs->transport_active =
        npu_mif_cdc_cycle_is_active(model);
}

static void cdc_noc_fill_meta(
    const npu_mif_cdc_cycle_t *model,
    npu_mif_cdc_noc_outputs_t *outputs)
{
    outputs->reset_epoch = model->noc_epoch_sync1;
    outputs->transport_active =
        npu_mif_cdc_cycle_is_active(model);
}

void npu_mif_cdc_cycle_init(npu_mif_cdc_cycle_t *model)
{
    if (model == NULL) {
        return;
    }

    (void)memset(model, 0, sizeof(*model));
    model->core_reset_seen = 1u;
    model->noc_reset_seen = 1u;
}

void npu_mif_cdc_cycle_reset(npu_mif_cdc_cycle_t *model)
{
    uint32_t next_epoch;

    if (model == NULL) {
        return;
    }

    next_epoch = model->reset_epoch + 1u;
    (void)memset(model, 0, sizeof(*model));
    model->core_reset_seen = 1u;
    model->noc_reset_seen = 1u;
    model->reset_epoch = next_epoch;
    model->core_epoch_sync0 = next_epoch;
    model->core_epoch_sync1 = next_epoch;
    model->noc_epoch_sync0 = next_epoch;
    model->noc_epoch_sync1 = next_epoch;
}

uint8_t npu_mif_cdc_cycle_is_active(
    const npu_mif_cdc_cycle_t *model)
{
    if (model == NULL) {
        return 0u;
    }
    return model->core_released != 0u &&
                   model->noc_released != 0u
               ? 1u
               : 0u;
}

static void cdc_core_fill_outputs(
    const npu_mif_cdc_cycle_t *model,
    npu_mif_cdc_core_outputs_t *outputs)
{
    uint8_t owner;

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        const npu_mif_cdc_rsp_fifo_t *fifo =
            &model->rsp_fifo[owner];
        npu_mif_owner_outputs_t *output =
            &outputs->owner[owner];

        output->req_ready = cdc_can_write(
            &model->req_fifo[owner].control,
            NPU_MIF_CDC_REQ_FIFO_DEPTH);
        output->wready = cdc_can_write(
            &model->w_fifo[owner].control,
            NPU_MIF_CDC_W_FIFO_DEPTH);

        if (cdc_can_read(&fifo->control,
                         NPU_MIF_CDC_RSP_FIFO_DEPTH) != 0u) {
            const npu_mif_cdc_rsp_payload_t *payload =
                &fifo->entry[
                    fifo->control.read_seq %
                    NPU_MIF_CDC_RSP_FIFO_DEPTH];
            output->rsp_valid = 1u;
            output->rsp_data = payload->data;
            output->rsp_tag = payload->tag;
            output->rsp_is_write = payload->is_write;
            output->rsp_last = payload->last;
            output->rsp_status = payload->status;
        }
    }
}

static void cdc_core_apply_handshakes(
    npu_mif_cdc_cycle_t *model,
    const npu_mif_cdc_core_inputs_t *inputs,
    const npu_mif_cdc_core_outputs_t *outputs)
{
    uint8_t owner;

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        const npu_mif_owner_inputs_t *input =
            &inputs->owner[owner];
        const npu_mif_owner_outputs_t *output =
            &outputs->owner[owner];
        npu_mif_cdc_req_fifo_t *req_fifo =
            &model->req_fifo[owner];
        npu_mif_cdc_w_fifo_t *w_fifo =
            &model->w_fifo[owner];
        npu_mif_cdc_rsp_fifo_t *rsp_fifo =
            &model->rsp_fifo[owner];

        if (input->req_valid != 0u &&
            output->req_ready != 0u) {
            npu_mif_cdc_req_payload_t *payload =
                &req_fifo->entry[
                    req_fifo->control.write_seq %
                    NPU_MIF_CDC_REQ_FIFO_DEPTH];
            payload->write = input->req_write;
            payload->vaddr = input->req_vaddr;
            payload->beats = input->req_beats;
            payload->tag = input->req_tag;
            payload->owner = input->req_owner;
            payload->task_id = input->req_task_id;
            payload->attr = input->req_attr;
            req_fifo->control.write_seq++;
        }

        if (input->wvalid != 0u && output->wready != 0u) {
            npu_mif_cdc_w_payload_t *payload =
                &w_fifo->entry[
                    w_fifo->control.write_seq %
                    NPU_MIF_CDC_W_FIFO_DEPTH];
            payload->data = input->wdata;
            payload->strb = input->wstrb;
            payload->last = input->wlast;
            payload->tag = input->wtag;
            payload->owner = owner;
            w_fifo->control.write_seq++;
        }

        if (output->rsp_valid != 0u &&
            input->rsp_ready != 0u) {
            rsp_fifo->control.read_seq++;
        }
    }
}

static void cdc_core_advance_synchronizers(
    npu_mif_cdc_cycle_t *model)
{
    uint8_t owner;

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        cdc_sync_read_at_writer(
            &model->req_fifo[owner].control);
        cdc_sync_read_at_writer(
            &model->w_fifo[owner].control);
        cdc_sync_write_at_reader(
            &model->rsp_fifo[owner].control);
    }
}

void npu_mif_cdc_core_tick(
    npu_mif_cdc_cycle_t *model,
    const npu_mif_cdc_core_inputs_t *inputs,
    npu_mif_cdc_core_outputs_t *outputs)
{
    if (outputs == NULL) {
        return;
    }
    (void)memset(outputs, 0, sizeof(*outputs));
    if (model == NULL || inputs == NULL) {
        return;
    }

    if (inputs->reset_n == 0u) {
        cdc_assert_reset(model, 1u);
        cdc_core_fill_meta(model, outputs);
        return;
    }

    model->core_tick_count++;
    cdc_core_fill_meta(model, outputs);
    if (model->core_epoch_sync1 != model->reset_epoch) {
        model->core_released = 0u;
        model->core_reset_seen = 0u;
        cdc_sync_core_epoch(model);
        return;
    }
    if (model->core_released == 0u) {
        model->core_reset_seen = 0u;
        model->core_released = 1u;
        cdc_sync_core_epoch(model);
        return;
    }
    model->core_reset_seen = 0u;
    if (model->noc_released == 0u) {
        cdc_sync_core_epoch(model);
        return;
    }

    cdc_core_fill_outputs(model, outputs);
    cdc_core_apply_handshakes(model, inputs, outputs);
    cdc_core_advance_synchronizers(model);
    cdc_sync_core_epoch(model);
}

static void cdc_noc_fill_outputs(
    const npu_mif_cdc_cycle_t *model,
    npu_mif_cdc_noc_outputs_t *outputs)
{
    uint8_t owner;

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        const npu_mif_cdc_req_fifo_t *req_fifo =
            &model->req_fifo[owner];
        const npu_mif_cdc_w_fifo_t *w_fifo =
            &model->w_fifo[owner];
        npu_mif_owner_inputs_t *output =
            &outputs->owner[owner];

        if (cdc_can_read(&req_fifo->control,
                         NPU_MIF_CDC_REQ_FIFO_DEPTH) != 0u) {
            const npu_mif_cdc_req_payload_t *payload =
                &req_fifo->entry[
                    req_fifo->control.read_seq %
                    NPU_MIF_CDC_REQ_FIFO_DEPTH];
            output->req_valid = 1u;
            output->req_write = payload->write;
            output->req_vaddr = payload->vaddr;
            output->req_beats = payload->beats;
            output->req_tag = payload->tag;
            output->req_owner = payload->owner;
            output->req_task_id = payload->task_id;
            output->req_attr = payload->attr;
        }

        if (cdc_can_read(&w_fifo->control,
                         NPU_MIF_CDC_W_FIFO_DEPTH) != 0u) {
            const npu_mif_cdc_w_payload_t *payload =
                &w_fifo->entry[
                    w_fifo->control.read_seq %
                    NPU_MIF_CDC_W_FIFO_DEPTH];
            output->wvalid = 1u;
            output->wdata = payload->data;
            output->wstrb = payload->strb;
            output->wlast = payload->last;
            output->wtag = payload->tag;
        }

        output->rsp_ready = cdc_can_write(
            &model->rsp_fifo[owner].control,
            NPU_MIF_CDC_RSP_FIFO_DEPTH);
    }
}

static void cdc_noc_apply_handshakes(
    npu_mif_cdc_cycle_t *model,
    const npu_mif_cdc_noc_inputs_t *inputs,
    const npu_mif_cdc_noc_outputs_t *outputs)
{
    uint8_t owner;

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        const npu_mif_owner_outputs_t *input =
            &inputs->owner[owner];
        const npu_mif_owner_inputs_t *output =
            &outputs->owner[owner];
        npu_mif_cdc_req_fifo_t *req_fifo =
            &model->req_fifo[owner];
        npu_mif_cdc_w_fifo_t *w_fifo =
            &model->w_fifo[owner];
        npu_mif_cdc_rsp_fifo_t *rsp_fifo =
            &model->rsp_fifo[owner];

        if (output->req_valid != 0u &&
            input->req_ready != 0u) {
            req_fifo->control.read_seq++;
        }
        if (output->wvalid != 0u &&
            input->wready != 0u) {
            w_fifo->control.read_seq++;
        }

        if (input->rsp_valid != 0u &&
            output->rsp_ready != 0u) {
            npu_mif_cdc_rsp_payload_t *payload =
                &rsp_fifo->entry[
                    rsp_fifo->control.write_seq %
                    NPU_MIF_CDC_RSP_FIFO_DEPTH];
            payload->data = input->rsp_data;
            payload->tag = input->rsp_tag;
            payload->is_write = input->rsp_is_write;
            payload->last = input->rsp_last;
            payload->status = input->rsp_status;
            payload->owner = owner;
            rsp_fifo->control.write_seq++;
        }
    }
}

static void cdc_noc_advance_synchronizers(
    npu_mif_cdc_cycle_t *model)
{
    uint8_t owner;

    for (owner = 0u; owner < NPU_MIF_OWNER_COUNT; owner++) {
        cdc_sync_write_at_reader(
            &model->req_fifo[owner].control);
        cdc_sync_write_at_reader(
            &model->w_fifo[owner].control);
        cdc_sync_read_at_writer(
            &model->rsp_fifo[owner].control);
    }
}

void npu_mif_cdc_noc_tick(
    npu_mif_cdc_cycle_t *model,
    const npu_mif_cdc_noc_inputs_t *inputs,
    npu_mif_cdc_noc_outputs_t *outputs)
{
    if (outputs == NULL) {
        return;
    }
    (void)memset(outputs, 0, sizeof(*outputs));
    if (model == NULL || inputs == NULL) {
        return;
    }

    if (inputs->reset_n == 0u) {
        cdc_assert_reset(model, 0u);
        cdc_noc_fill_meta(model, outputs);
        return;
    }

    model->noc_tick_count++;
    cdc_noc_fill_meta(model, outputs);
    if (model->noc_epoch_sync1 != model->reset_epoch) {
        model->noc_released = 0u;
        model->noc_reset_seen = 0u;
        cdc_sync_noc_epoch(model);
        return;
    }
    if (model->noc_released == 0u) {
        model->noc_reset_seen = 0u;
        model->noc_released = 1u;
        cdc_sync_noc_epoch(model);
        return;
    }
    model->noc_reset_seen = 0u;
    if (model->core_released == 0u) {
        cdc_sync_noc_epoch(model);
        return;
    }

    cdc_noc_fill_outputs(model, outputs);
    cdc_noc_apply_handshakes(model, inputs, outputs);
    cdc_noc_advance_synchronizers(model);
    cdc_sync_noc_epoch(model);
}

uint8_t npu_mif_cdc_req_level(
    const npu_mif_cdc_cycle_t *model,
    uint8_t owner)
{
    if (model == NULL || owner >= NPU_MIF_OWNER_COUNT) {
        return 0u;
    }
    return cdc_level(&model->req_fifo[owner].control,
                     NPU_MIF_CDC_REQ_FIFO_DEPTH);
}

uint8_t npu_mif_cdc_w_level(
    const npu_mif_cdc_cycle_t *model,
    uint8_t owner)
{
    if (model == NULL || owner >= NPU_MIF_OWNER_COUNT) {
        return 0u;
    }
    return cdc_level(&model->w_fifo[owner].control,
                     NPU_MIF_CDC_W_FIFO_DEPTH);
}

uint8_t npu_mif_cdc_rsp_level(
    const npu_mif_cdc_cycle_t *model,
    uint8_t owner)
{
    if (model == NULL || owner >= NPU_MIF_OWNER_COUNT) {
        return 0u;
    }
    return cdc_level(&model->rsp_fifo[owner].control,
                     NPU_MIF_CDC_RSP_FIFO_DEPTH);
}
