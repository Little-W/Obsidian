#include "cmodel_driver_backend.h"

#include <string.h>

#define BACKEND_HANDSHAKE_LIMIT 100000u

static void backend_idle_inputs(npu_host_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->core_reset_n = 1u;
    inputs->noc_reset_n = 1u;
}

static int backend_queue_response(
    npu_example_cmodel_backend_t *backend,
    uint64_t response)
{
    size_t tail;

    if (backend->pending_response_count >=
        NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS) {
        return -1;
    }
    tail = (backend->pending_response_head +
            backend->pending_response_count) %
           NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS;
    backend->pending_response[tail] = response;
    backend->pending_response_count++;
    return 0;
}

static int backend_submit_fixed_burst(void *context,
                                      uint32_t fifo_offset,
                                      const uint64_t *beats,
                                      size_t beat_count)
{
    npu_example_cmodel_backend_t *backend =
        (npu_example_cmodel_backend_t *)context;
    npu_host_inputs_t inputs;
    npu_host_outputs_t outputs;
    size_t index;
    uint32_t cycle;

    if (backend == (npu_example_cmodel_backend_t *)0 ||
        beats == (const uint64_t *)0 ||
        fifo_offset != NPU_DRV_CMD_FIFO_DATA ||
        beat_count < NPU_DRV_CMD_FIFO_MIN_BURST_BEATS ||
        beat_count > NPU_DRV_CMD_FIFO_MAX_BURST_BEATS ||
        (beat_count & 1u) != 0u ||
        backend->pending_response_count >
            NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS ||
        beat_count / NPU_DRV_CMD128_BEATS >
            NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS -
                backend->pending_response_count) {
        return -1;
    }
    for (index = 0u; index < beat_count; index++) {
        for (cycle = 0u; cycle < BACKEND_HANDSHAKE_LIMIT; cycle++) {
            backend_idle_inputs(&inputs);
            inputs.cmd_rsp_ready = 1u;
            inputs.cmd_valid = 1u;
            inputs.cmd_data = beats[index];
            inputs.cmd_first =
                (uint8_t)((index & 1u) == 0u);
            inputs.cmd_last =
                (uint8_t)((index & 1u) != 0u);
            npu_model_cycle_io(&backend->model, &inputs, &outputs);
            if (outputs.cmd_rsp_valid != 0u &&
                backend_queue_response(
                    backend, outputs.cmd_rsp_data) != 0) {
                return -1;
            }
            if (outputs.cmd_ready != 0u) {
                backend->submitted_beats++;
                break;
            }
        }
        if (cycle == BACKEND_HANDSHAKE_LIMIT) {
            return -1;
        }
    }
    backend->submitted_bursts++;
    return 0;
}

static int backend_submit_response(void *context, uint64_t *value)
{
    npu_example_cmodel_backend_t *backend =
        (npu_example_cmodel_backend_t *)context;
    npu_host_inputs_t inputs;
    npu_host_outputs_t outputs;
    uint32_t cycle;

    if (backend == (npu_example_cmodel_backend_t *)0 ||
        value == (uint64_t *)0) {
        return -1;
    }
    if (backend->pending_response_count != 0u) {
        *value =
            backend->pending_response[backend->pending_response_head];
        backend->pending_response_head =
            (backend->pending_response_head + 1u) %
            NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS;
        backend->pending_response_count--;
        backend->responses++;
        return 0;
    }
    for (cycle = 0u; cycle < BACKEND_HANDSHAKE_LIMIT; cycle++) {
        backend_idle_inputs(&inputs);
        inputs.cmd_rsp_ready = 1u;
        npu_model_cycle_io(&backend->model, &inputs, &outputs);
        if (outputs.cmd_rsp_valid != 0u) {
            *value = outputs.cmd_rsp_data;
            backend->responses++;
            return 0;
        }
    }
    return -1;
}

static npu_task_state_t backend_task_state(
    const npu_example_cmodel_backend_t *backend,
    uint16_t command_id)
{
    uint32_t slot;

    for (slot = 0u; slot < backend->model.config.task_entries; slot++) {
        const npu_task_slot_t *task = &backend->model.tasks[slot];
        if (task->state != NPU_TASK_FREE &&
            task->request.cmd.command_id == command_id) {
            return task->state;
        }
    }
    return NPU_TASK_FREE;
}

static int backend_has_active_tasks(
    const npu_example_cmodel_backend_t *backend,
    uint8_t engine_mask)
{
    uint32_t slot;

    for (slot = 0u; slot < backend->model.config.task_entries; slot++) {
        const npu_task_slot_t *task = &backend->model.tasks[slot];
        npu_task_state_t state = task->state;
        uint8_t engine = (uint8_t)task->request.cmd.engine;
        uint8_t engine_bit =
            engine >= (uint8_t)NPU_ENGINE_DMA &&
                    engine <= (uint8_t)NPU_ENGINE_COMPLEX
                ? (uint8_t)(1u << (engine - 1u))
                : 0u;
        if ((state == NPU_TASK_WAITING || state == NPU_TASK_RUNNING) &&
            (engine_mask & engine_bit) != 0u) {
            return 1;
        }
    }
    return 0;
}

static int backend_query(npu_example_cmodel_backend_t *backend,
                         uint16_t command_id,
                         uint8_t selector,
                         uint64_t *value)
{
    npu_task_result_t result;
    npu_task_state_t state;
    npu_status_t status;

    state = backend_task_state(backend, command_id);
    status = npu_model_query(&backend->model, command_id, 0, &result);
    if (selector == NPU_DRV_QUERY_ACK) {
        if (state == NPU_TASK_FREE) {
            return -1;
        }
        status = npu_model_query(&backend->model, command_id, 1, &result);
        *value = (uint64_t)(uint8_t)status;
        return status == NPU_STATUS_SUCCESS ? 0 : -1;
    }
    if (state == NPU_TASK_FREE || status == NPU_STATUS_NOT_FOUND) {
        return -1;
    }
    if (selector == NPU_DRV_QUERY_STATUS) {
        *value = (uint64_t)(uint8_t)state |
                 ((uint64_t)(uint8_t)result.status << 4u) |
                 ((uint64_t)command_id << 12u);
    } else if (selector == NPU_DRV_QUERY_TAG_EVENT) {
        *value = (uint64_t)result.user_tag;
    } else if (selector == NPU_DRV_QUERY_FAULT_ADDR) {
        *value = result.fault_addr;
    } else if (selector == NPU_DRV_QUERY_PROGRESS) {
        *value = result.progress;
    } else if (selector == NPU_DRV_QUERY_ERROR_INFO) {
        *value = result.error_info;
    } else if (selector == NPU_DRV_QUERY_DONE_FLAGS) {
        *value = result.done_flags;
    } else {
        return -1;
    }
    return 0;
}

static int backend_wait_event(npu_example_cmodel_backend_t *backend,
                              uint16_t packed,
                              uint32_t max_cycles,
                              uint64_t *value)
{
    uint8_t event_id = (uint8_t)(packed & 0xffu);
    uint8_t generation = (uint8_t)((packed >> 8u) & 0x0fu);
    uint32_t cycle;

    if (event_id >= NPU_EVENT_NUM) {
        return -1;
    }
    for (cycle = 0u; cycle <= max_cycles; cycle++) {
        const npu_event_entry_t *event = &backend->model.events[event_id];
        if (event->generation != generation) {
            return -1;
        }
        if (event->state == NPU_EVENT_SUCCESS ||
            event->state == NPU_EVENT_FAILED) {
            *value = (uint64_t)(uint8_t)event->state |
                     ((uint64_t)event->producer_task_id << 8u);
            return 0;
        }
        if (cycle != max_cycles) {
            npu_model_step(&backend->model, 1u);
        }
    }
    return -1;
}

static int backend_control_request(void *context,
                                   uint8_t operation,
                                   uint64_t rs1,
                                   uint64_t rs2,
                                   uint64_t *rd)
{
    npu_example_cmodel_backend_t *backend =
        (npu_example_cmodel_backend_t *)context;
    uint32_t cycle;

    if (backend == (npu_example_cmodel_backend_t *)0 ||
        rd == (uint64_t *)0) {
        return -1;
    }
    if (operation == NPU_DRV_CTL_QUERY) {
        return backend_query(backend, (uint16_t)rs1, (uint8_t)rs2, rd);
    }
    if (operation == NPU_DRV_CTL_WAIT) {
        return backend_wait_event(
            backend, (uint16_t)rs1, (uint32_t)rs2, rd);
    }
    if (operation == NPU_DRV_CTL_FENCE) {
        if ((rs1 & ~(uint64_t)NPU_DRV_FENCE_ALL_ENGINES) != 0u) {
            return -1;
        }
        for (cycle = 0u; cycle <= (uint32_t)rs2; cycle++) {
            if (!backend_has_active_tasks(backend, (uint8_t)rs1)) {
                *rd = 0u;
                return 0;
            }
            if (cycle != (uint32_t)rs2) {
                npu_model_step(&backend->model, 1u);
            }
        }
    }
    return -1;
}

static void backend_cache_clean(void *context,
                                const void *address,
                                size_t bytes)
{
    npu_example_cmodel_backend_t *backend =
        (npu_example_cmodel_backend_t *)context;
    if (address != (const void *)0 && bytes != 0u) {
        backend->cache_clean_calls++;
    }
}

static void backend_cache_invalidate(void *context,
                                     void *address,
                                     size_t bytes)
{
    npu_example_cmodel_backend_t *backend =
        (npu_example_cmodel_backend_t *)context;
    if (address != (void *)0 && bytes != 0u) {
        backend->cache_invalidate_calls++;
    }
}

static void backend_relax(void *context)
{
    npu_example_cmodel_backend_t *backend =
        (npu_example_cmodel_backend_t *)context;
    npu_model_step(&backend->model, 1u);
}

int npu_example_cmodel_backend_init(
    npu_example_cmodel_backend_t *backend,
    uint8_t *l1,
    size_t l1_bytes,
    uint8_t *system_memory,
    size_t system_memory_bytes)
{
    npu_config_t config;

    if (backend == (npu_example_cmodel_backend_t *)0) {
        return -1;
    }
    (void)memset(backend, 0, sizeof(*backend));
    npu_config_reference(&config);
    if (l1_bytes < config.l1_bytes) {
        return -1;
    }
    return npu_model_init(&backend->model, &config,
                          l1, l1_bytes,
                          system_memory, system_memory_bytes) ==
                   NPU_STATUS_SUCCESS
               ? 0
               : -1;
}

npu_drv_platform_ops_t
npu_example_cmodel_backend_operations(
    npu_example_cmodel_backend_t *backend)
{
    npu_drv_platform_ops_t operations;

    (void)memset(&operations, 0, sizeof(operations));
    operations.context = backend;
    operations.submit_fixed_burst = backend_submit_fixed_burst;
    operations.submit_response = backend_submit_response;
    operations.control_request = backend_control_request;
    operations.cache_clean = backend_cache_clean;
    operations.cache_invalidate = backend_cache_invalidate;
    operations.relax = backend_relax;
    return operations;
}
