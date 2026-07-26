#include "npu_driver_internal.h"

int npu_drv_query_raw(npu_driver_t *driver,
                      uint16_t command_id,
                      uint8_t selector,
                      uint64_t *value)
{
    int result;

    if (driver == (npu_driver_t *)0 ||
        value == (uint64_t *)0 ||
        command_id > NPU_DRV_MAX_COMMAND_ID ||
        selector > NPU_DRV_QUERY_DONE_FLAGS) {
        return NPU_DRV_EINVAL;
    }
    if (driver->ops.control_request == (void *)0) {
        return NPU_DRV_ENOTSUP;
    }
    result = driver->ops.control_request(
        driver->ops.context,
        NPU_DRV_CTL_QUERY,
        command_id,
        selector,
        value);
    return npu_drv_internal_platform_result(result);
}

int npu_drv_query_status(npu_driver_t *driver,
                         uint16_t command_id,
                         npu_drv_task_status_t *status)
{
    uint64_t raw;
    int result;

    if (status == (npu_drv_task_status_t *)0) {
        return NPU_DRV_EINVAL;
    }
    result = npu_drv_query_raw(
        driver, command_id, NPU_DRV_QUERY_STATUS, &raw);
    if (result != NPU_DRV_OK) {
        return result;
    }
    status->raw = raw;
    status->state = (uint8_t)(raw & 0x0fu);
    status->status = (uint8_t)((raw >> 4u) & 0xffu);
    status->command_id = (uint16_t)((raw >> 12u) & 0x0fffu);
    if (status->state > NPU_DRV_TASK_TERMINAL ||
        status->command_id != command_id) {
        return NPU_DRV_EIO;
    }
    return NPU_DRV_OK;
}

int npu_drv_wait_task(npu_driver_t *driver,
                      uint16_t command_id,
                      uint32_t poll_limit,
                      npu_drv_task_status_t *status)
{
    uint32_t poll;
    int result;

    if (driver == (npu_driver_t *)0 ||
        status == (npu_drv_task_status_t *)0 ||
        poll_limit == 0u) {
        return NPU_DRV_EINVAL;
    }
    for (poll = 0u; poll < poll_limit; poll++) {
        result = npu_drv_query_status(driver, command_id, status);
        if (result != NPU_DRV_OK) {
            return result;
        }
        if (status->state == NPU_DRV_TASK_TERMINAL) {
            if (driver->ops.read_barrier != (void *)0) {
                driver->ops.read_barrier(driver->ops.context);
            }
            return NPU_DRV_OK;
        }
        if (driver->ops.relax != (void *)0) {
            driver->ops.relax(driver->ops.context);
        }
    }
    return NPU_DRV_ETIMEOUT;
}

int npu_drv_ack_task(npu_driver_t *driver, uint16_t command_id)
{
    uint64_t raw;
    return npu_drv_query_raw(
        driver, command_id, NPU_DRV_QUERY_ACK, &raw);
}

int npu_drv_wait_event(npu_driver_t *driver,
                       npu_drv_event_t event,
                       uint32_t max_cycles,
                       npu_drv_event_result_t *result)
{
    uint8_t packed;
    uint64_t raw;
    int callback_result;

    if (driver == (npu_driver_t *)0 ||
        result == (npu_drv_event_result_t *)0 ||
        npu_drv_event_encode(event, &packed) != NPU_DRV_OK ||
        packed == NPU_DRV_EVENT_NONE) {
        return NPU_DRV_EINVAL;
    }
    if (driver->ops.control_request == (void *)0) {
        return NPU_DRV_ENOTSUP;
    }
    callback_result = driver->ops.control_request(
        driver->ops.context,
        NPU_DRV_CTL_WAIT,
        packed,
        max_cycles,
        &raw);
    if (callback_result != 0) {
        return NPU_DRV_EIO;
    }
    result->raw = raw;
    result->state = (uint8_t)(raw & 0xffu);
    result->producer_command_id =
        (uint16_t)((raw >> 8u) & 0x0fffu);
    if (driver->ops.read_barrier != (void *)0) {
        driver->ops.read_barrier(driver->ops.context);
    }
    return NPU_DRV_OK;
}

int npu_drv_fence_mask(npu_driver_t *driver,
                       uint8_t engine_mask,
                       uint32_t max_cycles,
                       uint64_t *raw)
{
    int callback_result;

    if (driver == (npu_driver_t *)0 ||
        raw == (uint64_t *)0 ||
        (engine_mask & (uint8_t)~NPU_DRV_FENCE_ALL_ENGINES) != 0u) {
        return NPU_DRV_EINVAL;
    }
    if (driver->ops.control_request == (void *)0) {
        return NPU_DRV_ENOTSUP;
    }
    callback_result = driver->ops.control_request(
        driver->ops.context,
        NPU_DRV_CTL_FENCE,
        engine_mask,
        max_cycles,
        raw);
    if (callback_result != 0) {
        return NPU_DRV_EIO;
    }
    if (driver->ops.read_barrier != (void *)0) {
        driver->ops.read_barrier(driver->ops.context);
    }
    return NPU_DRV_OK;
}

int npu_drv_fence(npu_driver_t *driver,
                  uint32_t max_cycles,
                  uint64_t *raw)
{
    return npu_drv_fence_mask(
        driver, NPU_DRV_FENCE_ALL_ENGINES, max_cycles, raw);
}
