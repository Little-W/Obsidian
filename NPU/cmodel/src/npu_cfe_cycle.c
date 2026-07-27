#include "npu_cfe_cycle.h"

#include <string.h>

static uint8_t npu_cfe_next_index(uint8_t index)
{
    index++;
    if (index >= NPU_CFE_CYCLE_FIFO_DEPTH) {
        index = 0u;
    }
    return index;
}

static uint16_t npu_cfe_command_id(uint64_t low_beat,
                                   uint64_t high_beat,
                                   uint8_t descriptor_diagnostic_mode)
{
    if (descriptor_diagnostic_mode != 0u) {
        return (uint16_t)((low_beat >> 48u) &
                          UINT64_C(0x0fff));
    }
    (void)low_beat;
    return (uint16_t)((high_beat >> 48u) &
                      UINT64_C(0x03ff));
}

static uint8_t npu_cfe_free_entries(
    const npu_cfe_cycle_t *model)
{
    if (model->fifo_count >= NPU_CFE_CYCLE_FIFO_DEPTH) {
        return 0u;
    }
    return (uint8_t)(NPU_CFE_CYCLE_FIFO_DEPTH -
                     model->fifo_count);
}

static uint64_t npu_cfe_response_data(
    const npu_cfe_cycle_t *model)
{
    return (uint64_t)(model->response_command_id & 0x0fffu) |
           ((uint64_t)model->response_status << 12) |
           ((uint64_t)model->response_free_entries << 20);
}

static void npu_cfe_set_response(npu_cfe_cycle_t *model,
                                 npu_status_t status,
                                 npu_cfe_cycle_state_t state)
{
    model->response_status = (uint8_t)status;
    model->response_free_entries = npu_cfe_free_entries(model);
    model->state = state;
}

static uint8_t npu_cfe_fifo_has_id(
    const npu_cfe_cycle_t *model,
    uint16_t command_id)
{
    uint8_t index = model->fifo_read_index;
    uint8_t count;

    for (count = 0u; count < model->fifo_count; count++) {
        if (npu_cfe_command_id(
                model->fifo[index].low,
                model->fifo[index].high,
                model->descriptor_diagnostic_mode) ==
            command_id) {
            return 1u;
        }
        index = npu_cfe_next_index(index);
    }
    return 0u;
}

static uint8_t npu_cfe_enqueue(npu_cfe_cycle_t *model)
{
    npu_cfe_fifo_entry_t *entry;

    if (model->fifo_count >= NPU_CFE_CYCLE_FIFO_DEPTH) {
        return 0u;
    }
    entry = &model->fifo[model->fifo_write_index];
    entry->low = model->low_beat;
    entry->high = model->high_beat;
    model->fifo_write_index =
        npu_cfe_next_index(model->fifo_write_index);
    model->fifo_count++;
    return 1u;
}

static void npu_cfe_pop(npu_cfe_cycle_t *model)
{
    npu_cfe_fifo_entry_t *entry;

    if (model->fifo_count == 0u) {
        return;
    }
    entry = &model->fifo[model->fifo_read_index];
    entry->low = 0u;
    entry->high = 0u;
    model->fifo_read_index =
        npu_cfe_next_index(model->fifo_read_index);
    model->fifo_count--;
}

static uint8_t npu_cfe_wait_expired(
    const npu_cfe_cycle_t *model)
{
    return model->state == NPU_CFE_STATE_WAIT_HI &&
                   NPU_CFE_CYCLE_BEAT_TIMEOUT != 0u &&
                   model->beat_wait_cycles >=
                       NPU_CFE_CYCLE_BEAT_TIMEOUT
               ? 1u
               : 0u;
}

uint8_t npu_cfe_cycle_idle(const npu_cfe_cycle_t *model)
{
    if (model == (const npu_cfe_cycle_t *)0) {
        return 0u;
    }
    return model->state == NPU_CFE_STATE_IDLE &&
                   model->fifo_count == 0u &&
                   model->ts_output_beat == 0u
               ? 1u
               : 0u;
}

void npu_cfe_cycle_reset(npu_cfe_cycle_t *model)
{
    if (model == (npu_cfe_cycle_t *)0) {
        return;
    }
    (void)memset(model, 0, sizeof(*model));
    model->state = NPU_CFE_STATE_IDLE;
}

static void npu_cfe_fill_outputs(
    const npu_cfe_cycle_t *model,
    const npu_cfe_cycle_inputs_t *inputs,
    npu_cfe_cycle_outputs_t *outputs)
{
    uint8_t wait_expired = npu_cfe_wait_expired(model);

    (void)memset(outputs, 0, sizeof(*outputs));
    outputs->cfe_idle_o = npu_cfe_cycle_idle(model);
    outputs->cfe_error_o = model->error_pulse;
    outputs->cmd_accepted_o = model->accepted_pulse;

    if (model->state == NPU_CFE_STATE_IDLE) {
        outputs->gc_cmd_ready_o =
            inputs->cfe_quiesce_i == 0u &&
                    model->fifo_count <
                        NPU_CFE_CYCLE_FIFO_DEPTH
                ? 1u
                : 0u;
    } else if (model->state == NPU_CFE_STATE_WAIT_HI) {
        outputs->gc_cmd_ready_o =
            wait_expired == 0u ? 1u : 0u;
    }

    if (model->state == NPU_CFE_STATE_RESP_OK ||
        model->state == NPU_CFE_STATE_RESP_ERR) {
        outputs->gc_rsp_valid_o = 1u;
        outputs->gc_rsp_data_o =
            npu_cfe_response_data(model);
    }

    if (model->fifo_count != 0u) {
        const npu_cfe_fifo_entry_t *entry =
            &model->fifo[model->fifo_read_index];

        outputs->ts_cmd_valid_o = 1u;
        if (model->ts_output_beat == 0u) {
            outputs->ts_cmd_data_o = entry->low;
            outputs->ts_cmd_first_o = 1u;
            outputs->ts_cmd_last_o = 0u;
        } else {
            outputs->ts_cmd_data_o = entry->high;
            outputs->ts_cmd_first_o = 0u;
            outputs->ts_cmd_last_o = 1u;
        }
    }

    if (model->state == NPU_CFE_STATE_LOOKUP_ID &&
        model->lookup_request_sent == 0u) {
        outputs->cmd_id_lookup_valid_o = 1u;
        outputs->cmd_id_lookup_id_o =
            model->response_command_id;
    }
}

void npu_cfe_cycle_step(npu_cfe_cycle_t *model,
                        const npu_cfe_cycle_inputs_t *inputs,
                        npu_cfe_cycle_outputs_t *outputs)
{
    uint8_t gc_command_handshake;
    uint8_t gc_response_handshake;
    uint8_t ts_command_handshake;
    uint8_t lookup_handshake;
    uint8_t wait_expired;

    if (model == (npu_cfe_cycle_t *)0 ||
        inputs == (const npu_cfe_cycle_inputs_t *)0 ||
        outputs == (npu_cfe_cycle_outputs_t *)0) {
        return;
    }

    if (inputs->reset_n == 0u) {
        npu_cfe_cycle_reset(model);
        (void)memset(outputs, 0, sizeof(*outputs));
        outputs->cfe_idle_o = 1u;
        return;
    }

    npu_cfe_fill_outputs(model, inputs, outputs);
    gc_command_handshake =
        inputs->gc_cmd_valid_i != 0u &&
                outputs->gc_cmd_ready_o != 0u
            ? 1u
            : 0u;
    gc_response_handshake =
        outputs->gc_rsp_valid_o != 0u &&
                inputs->gc_rsp_ready_i != 0u
            ? 1u
            : 0u;
    ts_command_handshake =
        outputs->ts_cmd_valid_o != 0u &&
                inputs->ts_cmd_ready_i != 0u
            ? 1u
            : 0u;
    lookup_handshake =
        outputs->cmd_id_lookup_valid_o != 0u &&
                inputs->cmd_id_lookup_ready_i != 0u
            ? 1u
            : 0u;
    wait_expired = npu_cfe_wait_expired(model);
    model->error_pulse = 0u;
    model->accepted_pulse = 0u;

    if (ts_command_handshake != 0u) {
        if (model->ts_output_beat == 0u) {
            model->ts_output_beat = 1u;
        } else {
            npu_cfe_pop(model);
            model->ts_output_beat = 0u;
        }
    }

    switch (model->state) {
    case NPU_CFE_STATE_IDLE:
        if (gc_command_handshake != 0u) {
            model->response_command_id =
                npu_cfe_command_id(
                    inputs->gc_cmd_data_i, 0u,
                    model->descriptor_diagnostic_mode);
            if (inputs->gc_cmd_first_i == 0u ||
                inputs->gc_cmd_last_i != 0u) {
                model->error_pulse = 1u;
                npu_cfe_set_response(
                    model, NPU_STATUS_BAD_DESC,
                    NPU_CFE_STATE_RESP_ERR);
            } else {
                model->low_beat = inputs->gc_cmd_data_i;
                model->beat_wait_cycles = 0u;
                model->state = NPU_CFE_STATE_WAIT_HI;
            }
        }
        break;

    case NPU_CFE_STATE_WAIT_HI:
        if (gc_command_handshake != 0u) {
            model->high_beat = inputs->gc_cmd_data_i;
            model->response_command_id =
                npu_cfe_command_id(model->low_beat,
                                   model->high_beat,
                                   model->descriptor_diagnostic_mode);
            if (inputs->gc_cmd_first_i != 0u ||
                inputs->gc_cmd_last_i == 0u) {
                model->error_pulse = 1u;
                npu_cfe_set_response(
                    model, NPU_STATUS_BAD_DESC,
                    NPU_CFE_STATE_RESP_ERR);
            } else {
                model->beat_wait_cycles = 0u;
                model->state = NPU_CFE_STATE_CHECK;
            }
        } else if (wait_expired != 0u) {
            model->beat_wait_cycles = 0u;
            model->error_pulse = 1u;
            npu_cfe_set_response(
                model, NPU_STATUS_TIMEOUT,
                NPU_CFE_STATE_RESP_ERR);
        } else if (NPU_CFE_CYCLE_BEAT_TIMEOUT != 0u) {
            model->beat_wait_cycles++;
        }
        break;

    case NPU_CFE_STATE_CHECK:
    {
        npu_cmd_t command;
        npu_status_t status =
            model->descriptor_diagnostic_mode != 0u
                ? npu_cmd_decode_descriptor(
                      model->low_beat, model->high_beat,
                      &command)
                : npu_cmd_decode(
                      model->low_beat, model->high_beat,
                      &command);

        if (status != NPU_STATUS_SUCCESS) {
            model->error_pulse = 1u;
            npu_cfe_set_response(
                model, status, NPU_CFE_STATE_RESP_ERR);
        } else {
            model->response_command_id = command.command_id;
            model->local_duplicate = npu_cfe_fifo_has_id(
                model, command.command_id);
            model->lookup_request_sent = 0u;
            model->state = NPU_CFE_STATE_LOOKUP_ID;
        }
        break;
    }

    case NPU_CFE_STATE_LOOKUP_ID:
        if (model->lookup_request_sent == 0u) {
            if (lookup_handshake != 0u) {
                model->lookup_request_sent = 1u;
            }
        } else if (inputs->cmd_id_lookup_rsp_valid_i != 0u) {
            if (model->local_duplicate != 0u ||
                inputs->cmd_id_busy_i != 0u) {
                npu_cfe_set_response(
                    model, NPU_STATUS_BAD_DESC,
                    NPU_CFE_STATE_RESP_ERR);
            } else {
                model->state = NPU_CFE_STATE_ENQUEUE;
            }
        }
        break;

    case NPU_CFE_STATE_ENQUEUE:
        if (npu_cfe_enqueue(model) != 0u) {
            model->accepted_pulse = 1u;
            npu_cfe_set_response(
                model, NPU_STATUS_SUCCESS,
                NPU_CFE_STATE_RESP_OK);
        } else {
            npu_cfe_set_response(
                model, NPU_STATUS_BUSY,
                NPU_CFE_STATE_RESP_ERR);
        }
        break;

    case NPU_CFE_STATE_RESP_OK:
    case NPU_CFE_STATE_RESP_ERR:
        if (gc_response_handshake != 0u) {
            model->low_beat = 0u;
            model->high_beat = 0u;
            model->beat_wait_cycles = 0u;
            model->lookup_request_sent = 0u;
            model->local_duplicate = 0u;
            model->state = NPU_CFE_STATE_IDLE;
        }
        break;

    default:
        npu_cfe_cycle_reset(model);
        break;
    }

    model->cycle++;
}
