#include "npu_cmodel.h"
#include "npu_wire.h"

static void npu_frontend_store_u64(uint8_t bytes[16],
                                   uint32_t offset,
                                   uint64_t value)
{
    uint32_t index;
    for (index = 0u; index < 8u; index++) {
        bytes[offset + index] =
            (uint8_t)(value >> (index * 8u));
    }
}

static uint32_t npu_frontend_free_tasks(const npu_model_t *model)
{
    uint32_t index;
    uint32_t free_count = 0u;

    for (index = 0u; index < model->config.task_entries; index++) {
        if (model->tasks[index].state == NPU_TASK_FREE) {
            free_count++;
        }
    }
    return free_count;
}

static int npu_frontend_descriptor_opcode_valid(
    npu_engine_t engine,
    uint8_t opcode)
{
    if (engine == NPU_ENGINE_CONTROL) {
        return opcode <= NPU_CTRL_GLOBAL_FENCE;
    }
    if (engine == NPU_ENGINE_DMA) {
        return opcode >= NPU_DMA_COPY_1D &&
               opcode <= NPU_DMA_SPLIT;
    }
    if (engine == NPU_ENGINE_MATRIX) {
        return opcode >= NPU_MATRIX_GEMM &&
               opcode <= NPU_MATRIX_GEMM_ZERO;
    }
    if (engine == NPU_ENGINE_VECTOR) {
        return opcode >= NPU_VECTOR_ADD &&
               opcode <= NPU_VECTOR_RELU;
    }
    if (engine == NPU_ENGINE_COMPLEX) {
        return opcode == NPU_COMPLEX_ACT ||
               opcode == NPU_COMPLEX_SOFTMAX ||
               opcode == NPU_COMPLEX_NORM ||
               opcode == NPU_COMPLEX_STAT ||
               opcode == NPU_COMPLEX_ADD_RESCALE;
    }
    return 0;
}

static uint64_t npu_frontend_response(uint16_t command_id,
                                      npu_status_t status,
                                      uint32_t free_count)
{
    if (free_count > 255u) {
        free_count = 255u;
    }
    return (uint64_t)(command_id & 0x0fffu) |
           ((uint64_t)((uint8_t)status) << 12) |
           ((uint64_t)free_count << 20);
}

static uint16_t npu_frontend_command_id(uint64_t low_beat,
                                        uint64_t high_beat,
                                        uint8_t descriptor_diagnostic_mode)
{
    if (descriptor_diagnostic_mode != 0u) {
        return (uint16_t)((low_beat >> 48u) & 0x0fffu);
    }
    (void)low_beat;
    return (uint16_t)((high_beat >> 48u) & 0x03ffu);
}

npu_status_t npu_model_submit_wire(npu_model_t *model,
                                   uint64_t low_beat,
                                   uint64_t high_beat)
{
    uint8_t cmd_wire[NPU_WIRE_CMD_BYTES];
    npu_wire_limits_t limits;
    npu_wire_meta_t meta;
    npu_task_request_t request;
    npu_cmd_t command;
    const uint8_t *descriptor;
    size_t descriptor_bytes;
    npu_status_t status;

    if (model == (npu_model_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    npu_frontend_store_u64(cmd_wire, 0u, low_beat);
    npu_frontend_store_u64(cmd_wire, 8u, high_beat);
    npu_wire_limits_reference(&limits);
    limits.l1_bytes = model->config.l1_bytes;
    limits.gaddr_limit = model->ddr_size;
    limits.dma_max_burst_beats =
        model->config.dma_max_burst_beats;
    limits.dma_max_outstanding =
        model->config.dma_outstanding;
    limits.mt = model->config.mt;
    limits.kt = model->config.kt;
    limits.nt = model->config.nt;
    limits.cme_scratch_elems =
        model->config.cme_scratch_elems;

    if (model->descriptor_diagnostic_mode != 0u) {
        status = npu_cmd_decode_descriptor(
            low_beat, high_beat, &command);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        if (!npu_frontend_descriptor_opcode_valid(
                command.engine, command.opcode)) {
            return NPU_STATUS_ILLEGAL_OPCODE;
        }
        status = npu_wire_validate_cmd_address(
            &command, &limits, &meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        descriptor_bytes =
            npu_wire_descriptor_bytes(command.engine);
        if (descriptor_bytes == 0u ||
            command.desc_addr > model->ddr_size ||
            descriptor_bytes >
                model->ddr_size - (size_t)command.desc_addr) {
            return NPU_STATUS_ADDR_FAULT;
        }
        descriptor = &model->ddr[(size_t)command.desc_addr];
        status = npu_wire_decode_descriptor(
            &command, descriptor, descriptor_bytes,
            &limits, &request, &meta);
    } else {
        status = npu_wire_decode_cmd_with_meta(
            cmd_wire, sizeof(cmd_wire), &limits, &command, &meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        status = npu_wire_decode_task(
            cmd_wire, sizeof(cmd_wire),
            (const uint8_t *)0, 0u,
            &limits, &request, &meta);
    }
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    return npu_model_submit(model, &request);
}

void npu_model_cycle_io(npu_model_t *model,
                        const npu_host_inputs_t *inputs,
                        npu_host_outputs_t *outputs)
{
    uint16_t command_id;
    npu_status_t status;
    int command_handshake;
    int response_handshake;

    if (model == (npu_model_t *)0 ||
        inputs == (const npu_host_inputs_t *)0 ||
        outputs == (npu_host_outputs_t *)0) {
        return;
    }
    outputs->cmd_ready = 0u;
    outputs->cmd_rsp_valid = model->cfe.response_valid;
    outputs->cmd_rsp_data = model->cfe.response_data;
    outputs->cycle = model->cycle;

    if (inputs->core_reset_n == 0u ||
        inputs->noc_reset_n == 0u) {
        npu_model_reset(model);
        outputs->cmd_rsp_valid = 0u;
        outputs->cmd_rsp_data = 0u;
        outputs->cycle = 0u;
        return;
    }

    if (model->cfe.response_valid == 0u) {
        if (model->cfe.have_low_beat != 0u ||
            npu_frontend_free_tasks(model) != 0u) {
            outputs->cmd_ready = 1u;
        }
    }
    command_handshake =
        inputs->cmd_valid != 0u && outputs->cmd_ready != 0u;
    response_handshake =
        model->cfe.response_valid != 0u &&
        inputs->cmd_rsp_ready != 0u;

    if (response_handshake) {
        model->cfe.response_valid = 0u;
    }

    if (command_handshake) {
        if (model->cfe.have_low_beat == 0u) {
            if (inputs->cmd_first == 0u ||
                inputs->cmd_last != 0u) {
                command_id =
                    (uint16_t)((inputs->cmd_data >> 48) & 0x0fffu);
                model->cfe.response_data =
                    npu_frontend_response(
                        command_id, NPU_STATUS_BAD_DESC,
                        npu_frontend_free_tasks(model));
                model->cfe.response_valid = 1u;
            } else {
                model->cfe.low_beat = inputs->cmd_data;
                model->cfe.have_low_beat = 1u;
                model->cfe.wait_cycles = 0u;
            }
        } else {
            command_id = npu_frontend_command_id(
                model->cfe.low_beat, inputs->cmd_data,
                model->descriptor_diagnostic_mode);
            if (inputs->cmd_first != 0u ||
                inputs->cmd_last == 0u) {
                status = NPU_STATUS_BAD_DESC;
            } else {
                status = npu_model_submit_wire(
                    model, model->cfe.low_beat, inputs->cmd_data);
            }
            model->cfe.response_data =
                npu_frontend_response(
                    command_id, status,
                    npu_frontend_free_tasks(model));
            model->cfe.response_valid = 1u;
            model->cfe.have_low_beat = 0u;
            model->cfe.wait_cycles = 0u;
        }
    } else if (model->cfe.have_low_beat != 0u &&
               model->config.cfe_beat_timeout != 0u) {
        model->cfe.wait_cycles++;
        if (model->cfe.wait_cycles >=
            model->config.cfe_beat_timeout) {
            command_id =
                model->descriptor_diagnostic_mode != 0u
                    ? (uint16_t)(
                          (model->cfe.low_beat >> 48u) &
                          0x0fffu)
                    : 0u;
            model->cfe.response_data =
                npu_frontend_response(
                    command_id, NPU_STATUS_TIMEOUT,
                    npu_frontend_free_tasks(model));
            model->cfe.response_valid = 1u;
            model->cfe.have_low_beat = 0u;
            model->cfe.wait_cycles = 0u;
        }
    }
    npu_model_step(model, 1u);
}
