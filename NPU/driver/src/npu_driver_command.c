#include "npu_driver_internal.h"

#include <string.h>

int npu_drv_event_pack(npu_drv_event_t event, uint16_t *packed)
{
    if (packed == (uint16_t *)0 ||
        event.generation > 15u ||
        (event.id == 255u && event.generation != 15u)) {
        return NPU_DRV_EINVAL;
    }
    *packed = (uint16_t)(((uint16_t)event.generation << 8u) |
                         event.id);
    return NPU_DRV_OK;
}

int npu_drv_event_unpack(uint16_t packed, npu_drv_event_t *event)
{
    uint8_t id;
    uint8_t generation;

    if (event == (npu_drv_event_t *)0 || packed > NPU_DRV_EVENT_NONE) {
        return NPU_DRV_EINVAL;
    }
    id = (uint8_t)(packed & 0xffu);
    generation = (uint8_t)((packed >> 8u) & 0x0fu);
    if (id == 255u && generation != 15u) {
        return NPU_DRV_EINVAL;
    }
    event->id = id;
    event->generation = generation;
    return NPU_DRV_OK;
}

int npu_drv_cmd128_encode(const npu_drv_cmd_fields_t *fields,
                          npu_drv_cmd128_t *command)
{
    uint16_t wait0;
    uint16_t wait1;
    uint16_t signal;

    if (fields == (const npu_drv_cmd_fields_t *)0 ||
        command == (npu_drv_cmd128_t *)0 ||
        (fields->descriptor_addr & ~NPU_DRV_ADDR48_MASK) != 0u ||
        (fields->descriptor_addr & 0x3fu) != 0u ||
        fields->command_id > NPU_DRV_MAX_COMMAND_ID ||
        fields->engine > NPU_DRV_ENGINE_COMPLEX ||
        (fields->header_flags & 0xfc00u) != 0u ||
        npu_drv_event_pack(fields->wait_event[0], &wait0) != NPU_DRV_OK ||
        npu_drv_event_pack(fields->wait_event[1], &wait1) != NPU_DRV_OK ||
        npu_drv_event_pack(fields->signal_event, &signal) != NPU_DRV_OK ||
        (signal != NPU_DRV_EVENT_NONE &&
         (signal == wait0 || signal == wait1))) {
        return NPU_DRV_EINVAL;
    }
    command->lo =
        fields->descriptor_addr |
        ((uint64_t)fields->command_id << 48u) |
        ((uint64_t)fields->engine << 60u);
    command->hi =
        (uint64_t)fields->opcode |
        ((uint64_t)fields->header_flags << 8u) |
        ((uint64_t)wait0 << 20u) |
        ((uint64_t)wait1 << 32u) |
        ((uint64_t)signal << 44u) |
        ((uint64_t)NPU_DRV_CMD_HEADER_VERSION << 56u);
    return NPU_DRV_OK;
}

int npu_drv_cmd128_decode(const npu_drv_cmd128_t *command,
                          npu_drv_cmd_fields_t *fields)
{
    uint16_t wait0;
    uint16_t wait1;
    uint16_t signal;

    if (command == (const npu_drv_cmd128_t *)0 ||
        fields == (npu_drv_cmd_fields_t *)0 ||
        (uint8_t)(command->hi >> 56u) !=
            NPU_DRV_CMD_HEADER_VERSION) {
        return NPU_DRV_EINVAL;
    }
    memset(fields, 0, sizeof(*fields));
    fields->descriptor_addr = command->lo & NPU_DRV_ADDR48_MASK;
    fields->command_id =
        (uint16_t)((command->lo >> 48u) & 0x0fffu);
    fields->engine = (uint8_t)((command->lo >> 60u) & 0x0fu);
    fields->opcode = (uint8_t)(command->hi & 0xffu);
    fields->header_flags =
        (uint16_t)((command->hi >> 8u) & 0x0fffu);
    wait0 = (uint16_t)((command->hi >> 20u) & 0x0fffu);
    wait1 = (uint16_t)((command->hi >> 32u) & 0x0fffu);
    signal = (uint16_t)((command->hi >> 44u) & 0x0fffu);
    if ((fields->descriptor_addr & 0x3fu) != 0u ||
        fields->engine > NPU_DRV_ENGINE_COMPLEX ||
        (fields->header_flags & 0x0c00u) != 0u ||
        npu_drv_event_unpack(wait0, &fields->wait_event[0]) !=
            NPU_DRV_OK ||
        npu_drv_event_unpack(wait1, &fields->wait_event[1]) !=
            NPU_DRV_OK ||
        npu_drv_event_unpack(signal, &fields->signal_event) !=
            NPU_DRV_OK ||
        (signal != NPU_DRV_EVENT_NONE &&
         (signal == wait0 || signal == wait1))) {
        memset(fields, 0, sizeof(*fields));
        return NPU_DRV_EINVAL;
    }
    return NPU_DRV_OK;
}

int npu_drv_submit(npu_driver_t *driver,
                   const npu_drv_cmd128_t *command,
                   const void *descriptor_cpu_address,
                   size_t descriptor_bytes,
                   npu_drv_submit_result_t *result)
{
    npu_drv_cmd_fields_t fields;
    uint64_t response;
    int callback_result;

    if (driver == (npu_driver_t *)0 ||
        command == (const npu_drv_cmd128_t *)0 ||
        result == (npu_drv_submit_result_t *)0 ||
        npu_drv_cmd128_decode(command, &fields) != NPU_DRV_OK ||
        (descriptor_bytes != 0u &&
         descriptor_cpu_address == (const void *)0)) {
        return NPU_DRV_EINVAL;
    }
    if (driver->ops.submit_beat == (void *)0 ||
        driver->ops.submit_response == (void *)0) {
        return NPU_DRV_ENOTSUP;
    }
    memset(result, 0, sizeof(*result));
    (void)npu_drv_sync_for_device(
        driver, descriptor_cpu_address, descriptor_bytes);
    callback_result = driver->ops.submit_beat(
        driver->ops.context, command->lo, 1u, 0u);
    if (callback_result != 0) {
        return NPU_DRV_EIO;
    }
    callback_result = driver->ops.submit_beat(
        driver->ops.context, command->hi, 0u, 1u);
    if (callback_result != 0) {
        return NPU_DRV_EIO;
    }
    callback_result = driver->ops.submit_response(
        driver->ops.context, &response);
    if (callback_result != 0) {
        return NPU_DRV_EIO;
    }
    result->raw = response;
    result->command_id = (uint16_t)(response & 0x0fffu);
    result->status = (uint8_t)((response >> 12u) & 0xffu);
    result->fifo_free = (uint8_t)((response >> 20u) & 0xffu);
    if (result->command_id != fields.command_id) {
        return NPU_DRV_EIO;
    }
    return result->status == 0u ? NPU_DRV_OK : NPU_DRV_EDEVICE;
}
