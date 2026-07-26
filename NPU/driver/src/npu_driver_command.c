#include "npu_driver_internal.h"

#include <string.h>

int npu_drv_event_encode(npu_drv_event_t event, uint8_t *encoded)
{
    if (encoded == (uint8_t *)0 ||
        (event.id != NPU_DRV_EVENT_NONE &&
         event.id > NPU_DRV_MAX_EVENT_ID)) {
        return NPU_DRV_EINVAL;
    }
    *encoded = event.id;
    return NPU_DRV_OK;
}

int npu_drv_event_decode(uint8_t encoded, npu_drv_event_t *event)
{
    if (event == (npu_drv_event_t *)0 ||
        (encoded != NPU_DRV_EVENT_NONE &&
         encoded > NPU_DRV_MAX_EVENT_ID)) {
        return NPU_DRV_EINVAL;
    }
    event->id = encoded;
    return NPU_DRV_OK;
}

int npu_drv_payload_field_set(npu_drv_payload80_t *payload,
                              uint8_t lsb,
                              uint8_t width,
                              uint64_t value)
{
    uint8_t bit;

    if (payload == (npu_drv_payload80_t *)0 ||
        width == 0u || width > 64u ||
        lsb >= 80u || width > (uint8_t)(80u - lsb) ||
        (width < 64u && value >= (UINT64_C(1) << width))) {
        return NPU_DRV_EINVAL;
    }
    for (bit = 0u; bit < width; bit++) {
        uint8_t destination = (uint8_t)(lsb + bit);
        uint64_t source_mask = UINT64_C(1) << bit;

        if (destination < 64u) {
            uint64_t destination_mask = UINT64_C(1) << destination;
            if ((payload->lo & destination_mask) != 0u) {
                return NPU_DRV_EINVAL;
            }
            if ((value & source_mask) != 0u) {
                payload->lo |= destination_mask;
            }
        } else {
            uint16_t destination_mask =
                (uint16_t)(UINT16_C(1) << (destination - 64u));
            if ((payload->hi & destination_mask) != 0u) {
                return NPU_DRV_EINVAL;
            }
            if ((value & source_mask) != 0u) {
                payload->hi =
                    (uint16_t)(payload->hi | destination_mask);
            }
        }
    }
    return NPU_DRV_OK;
}

int npu_drv_aref_encode(uint8_t ddr_space,
                        uint8_t base_select,
                        uint32_t byte_offset,
                        uint32_t *encoded)
{
    if (encoded == (uint32_t *)0 ||
        ddr_space > 1u ||
        byte_offset > UINT32_C(0x00ffffff) ||
        (ddr_space == 0u && base_select != 0u) ||
        (ddr_space != 0u && base_select >= 6u)) {
        return NPU_DRV_EINVAL;
    }
    *encoded =
        ((uint32_t)ddr_space << 27u) |
        ((uint32_t)base_select << 24u) |
        byte_offset;
    return NPU_DRV_OK;
}

int npu_drv_lref_encode(uint32_t byte_address,
                        uint8_t unit_shift,
                        uint8_t width,
                        uint16_t *encoded)
{
    uint32_t reference;
    uint32_t alignment_mask;

    if (encoded == (uint16_t *)0 ||
        unit_shift >= 31u || width == 0u || width > 16u) {
        return NPU_DRV_EINVAL;
    }
    alignment_mask = (UINT32_C(1) << unit_shift) - 1u;
    reference = byte_address >> unit_shift;
    if ((byte_address & alignment_mask) != 0u ||
        reference >= (UINT32_C(1) << width)) {
        return NPU_DRV_ERANGE;
    }
    *encoded = (uint16_t)reference;
    return NPU_DRV_OK;
}

static int npu_drv_matrix_type_fields(npu_drv_dtype_t a_dtype,
                                      npu_drv_dtype_t b_dtype,
                                      npu_drv_dtype_t c_dtype,
                                      uint8_t requant_shift,
                                      uint8_t *b_int4)
{
    if (b_int4 == (uint8_t *)0 ||
        a_dtype > NPU_DRV_DTYPE_INT16 ||
        b_dtype > NPU_DRV_DTYPE_INT16 ||
        c_dtype > NPU_DRV_DTYPE_INT16 ||
        requant_shift > 31u ||
        (c_dtype == NPU_DRV_DTYPE_INT32 && requant_shift != 0u)) {
        return NPU_DRV_EINVAL;
    }
    if (a_dtype == NPU_DRV_DTYPE_INT8 &&
        b_dtype == NPU_DRV_DTYPE_INT4) {
        *b_int4 = 1u;
        return NPU_DRV_OK;
    }
    if (a_dtype != b_dtype) {
        return NPU_DRV_EINVAL;
    }
    *b_int4 = 0u;
    return NPU_DRV_OK;
}

int npu_drv_matrix_gemm_payload_encode(
    uint16_t a_ref,
    npu_drv_dtype_t a_dtype,
    uint16_t b_ref,
    npu_drv_dtype_t b_dtype,
    uint16_t c_ref,
    npu_drv_dtype_t c_dtype,
    uint16_t bias_ref,
    uint8_t m,
    uint8_t n,
    uint8_t k,
    uint8_t requant_shift,
    npu_drv_payload80_t *payload)
{
    uint8_t b_int4;

    if (payload == (npu_drv_payload80_t *)0 ||
        a_ref >= (UINT16_C(1) << 14u) ||
        b_ref >= (UINT16_C(1) << 14u) ||
        c_ref >= (UINT16_C(1) << 14u) ||
        bias_ref >= (UINT16_C(1) << 12u) ||
        m == 0u || m > 64u ||
        n == 0u || n > 64u ||
        k == 0u || k > 64u ||
        npu_drv_matrix_type_fields(
            a_dtype, b_dtype, c_dtype, requant_shift, &b_int4) !=
            NPU_DRV_OK) {
        return NPU_DRV_EINVAL;
    }
    memset(payload, 0, sizeof(*payload));
    if (npu_drv_payload_field_set(payload, 66u, 14u, a_ref) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 52u, 14u, b_ref) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 38u, 14u, c_ref) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 26u, 12u, bias_ref) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 20u, 6u, m - 1u) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 14u, 6u, n - 1u) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 8u, 6u, k - 1u) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 7u, 1u, b_int4) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 5u, 2u, c_dtype) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 0u, 5u, requant_shift) !=
            NPU_DRV_OK) {
        memset(payload, 0, sizeof(*payload));
        return NPU_DRV_EINVAL;
    }
    return NPU_DRV_OK;
}

int npu_drv_matrix_bmm_payload_encode(
    uint16_t a_ref,
    npu_drv_dtype_t a_dtype,
    uint16_t b_ref,
    npu_drv_dtype_t b_dtype,
    uint16_t c_ref,
    npu_drv_dtype_t c_dtype,
    uint8_t batch_count,
    uint8_t m,
    uint8_t n,
    uint8_t k,
    uint8_t requant_shift,
    npu_drv_payload80_t *payload)
{
    uint8_t b_int4;

    if (payload == (npu_drv_payload80_t *)0 ||
        a_ref >= (UINT16_C(1) << 14u) ||
        b_ref >= (UINT16_C(1) << 14u) ||
        c_ref >= (UINT16_C(1) << 14u) ||
        batch_count == 0u || batch_count > 64u ||
        m == 0u || m > 64u ||
        n == 0u || n > 64u ||
        k == 0u || k > 64u ||
        npu_drv_matrix_type_fields(
            a_dtype, b_dtype, c_dtype, requant_shift, &b_int4) !=
            NPU_DRV_OK) {
        return NPU_DRV_EINVAL;
    }
    memset(payload, 0, sizeof(*payload));
    if (npu_drv_payload_field_set(payload, 66u, 14u, a_ref) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 52u, 14u, b_ref) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 38u, 14u, c_ref) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(
            payload, 32u, 6u, batch_count - 1u) != NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 26u, 6u, m - 1u) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 20u, 6u, n - 1u) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 14u, 6u, k - 1u) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 13u, 1u, b_int4) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 11u, 2u, c_dtype) !=
            NPU_DRV_OK ||
        npu_drv_payload_field_set(payload, 6u, 5u, requant_shift) !=
            NPU_DRV_OK) {
        memset(payload, 0, sizeof(*payload));
        return NPU_DRV_EINVAL;
    }
    return NPU_DRV_OK;
}

int npu_drv_cmd128_encode(const npu_drv_cmd_fields_t *fields,
                          npu_drv_cmd128_t *command)
{
    uint8_t wait0;
    uint8_t wait1;
    uint8_t signal;

    if (fields == (const npu_drv_cmd_fields_t *)0 ||
        command == (npu_drv_cmd128_t *)0 ||
        fields->command_id > NPU_DRV_MAX_COMMAND_ID ||
        fields->compact_opcode > NPU_DRV_COMPACT_COMPLEX_ADD_RESCALE ||
        fields->dtype > NPU_DRV_DTYPE_INT16 ||
        fields->timeout_class > 3u ||
        (fields->header_flags & (uint8_t)~NPU_DRV_HEADER_FLAGS_MASK) != 0u ||
        npu_drv_event_encode(fields->wait_event[0], &wait0) != NPU_DRV_OK ||
        npu_drv_event_encode(fields->wait_event[1], &wait1) != NPU_DRV_OK ||
        npu_drv_event_encode(fields->signal_event, &signal) != NPU_DRV_OK ||
        (signal != NPU_DRV_EVENT_NONE &&
         (signal == wait0 || signal == wait1))) {
        return NPU_DRV_EINVAL;
    }
    command->lo = fields->payload.lo;
    command->hi =
        (uint64_t)fields->payload.hi |
        ((uint64_t)fields->dtype << 16u) |
        ((uint64_t)fields->timeout_class << 18u) |
        ((uint64_t)fields->header_flags << 20u) |
        ((uint64_t)signal << 24u) |
        ((uint64_t)wait1 << 32u) |
        ((uint64_t)wait0 << 40u) |
        ((uint64_t)fields->command_id << 48u) |
        ((uint64_t)fields->compact_opcode << 58u) |
        (UINT64_C(1) << 63u);
    return NPU_DRV_OK;
}

int npu_drv_cmd128_decode(const npu_drv_cmd128_t *command,
                          npu_drv_cmd_fields_t *fields)
{
    uint8_t wait0;
    uint8_t wait1;
    uint8_t signal;

    if (command == (const npu_drv_cmd128_t *)0 ||
        fields == (npu_drv_cmd_fields_t *)0 ||
        (command->hi & (UINT64_C(1) << 63u)) == 0u) {
        return NPU_DRV_EINVAL;
    }
    memset(fields, 0, sizeof(*fields));
    fields->payload.lo = command->lo;
    fields->payload.hi = (uint16_t)(command->hi & UINT64_C(0xffff));
    fields->dtype =
        (npu_drv_dtype_t)((command->hi >> 16u) & UINT64_C(0x3));
    fields->timeout_class =
        (uint8_t)((command->hi >> 18u) & UINT64_C(0x3));
    fields->header_flags =
        (uint8_t)((command->hi >> 20u) & UINT64_C(0xf));
    signal = (uint8_t)((command->hi >> 24u) & UINT64_C(0xff));
    wait1 = (uint8_t)((command->hi >> 32u) & UINT64_C(0xff));
    wait0 = (uint8_t)((command->hi >> 40u) & UINT64_C(0xff));
    fields->command_id =
        (uint16_t)((command->hi >> 48u) & UINT64_C(0x3ff));
    fields->compact_opcode =
        (npu_drv_compact_opcode_t)(
            (command->hi >> 58u) & UINT64_C(0x1f));
    if (fields->compact_opcode >
            NPU_DRV_COMPACT_COMPLEX_ADD_RESCALE ||
        npu_drv_event_decode(wait0, &fields->wait_event[0]) != NPU_DRV_OK ||
        npu_drv_event_decode(wait1, &fields->wait_event[1]) != NPU_DRV_OK ||
        npu_drv_event_decode(signal, &fields->signal_event) != NPU_DRV_OK ||
        (signal != NPU_DRV_EVENT_NONE &&
         (signal == wait0 || signal == wait1))) {
        memset(fields, 0, sizeof(*fields));
        return NPU_DRV_EINVAL;
    }
    return NPU_DRV_OK;
}

static void npu_drv_submit_result_decode(
    uint64_t response,
    npu_drv_submit_result_t *result)
{
    result->raw = response;
    result->command_id =
        (uint16_t)(response & (uint64_t)NPU_DRV_MAX_COMMAND_ID);
    result->status = (uint8_t)((response >> 12u) & 0xffu);
    result->fifo_free = (uint8_t)((response >> 20u) & 0xffu);
}

int npu_drv_submit_batch(
    npu_driver_t *driver,
    const npu_drv_cmd128_t *commands,
    size_t command_count,
    npu_drv_submit_result_t *results,
    npu_drv_submit_batch_result_t *batch_result)
{
    uint64_t beats[NPU_DRV_CMD_FIFO_MAX_BURST_BEATS];
    uint16_t expected_command_ids[
        NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    npu_drv_cmd_fields_t fields;
    size_t index;
    int saw_device_error = 0;
    int saw_protocol_error = 0;

    if (driver == (npu_driver_t *)0 ||
        commands == (const npu_drv_cmd128_t *)0 ||
        results == (npu_drv_submit_result_t *)0 ||
        batch_result == (npu_drv_submit_batch_result_t *)0 ||
        command_count == 0u) {
        return NPU_DRV_EINVAL;
    }
    if (command_count > NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS) {
        return NPU_DRV_ERANGE;
    }
    memset(results, 0, command_count * sizeof(*results));
    memset(batch_result, 0, sizeof(*batch_result));
    batch_result->first_failed_index = NPU_DRV_NO_FAILED_COMMAND;
    if (driver->ops.submit_fixed_burst == (void *)0 ||
        driver->ops.submit_response == (void *)0) {
        return NPU_DRV_ENOTSUP;
    }
    for (index = 0u; index < command_count; index++) {
        if (npu_drv_cmd128_decode(&commands[index], &fields) != NPU_DRV_OK) {
            return NPU_DRV_EINVAL;
        }
        expected_command_ids[index] = fields.command_id;
        beats[index * NPU_DRV_CMD128_BEATS] = commands[index].lo;
        beats[index * NPU_DRV_CMD128_BEATS + 1u] = commands[index].hi;
    }
    if (driver->ops.write_barrier != (void *)0) {
        driver->ops.write_barrier(driver->ops.context);
    }
    if (driver->ops.submit_fixed_burst(
            driver->ops.context,
            NPU_DRV_CMD_FIFO_DATA,
            beats,
            command_count * NPU_DRV_CMD128_BEATS) != 0) {
        batch_result->first_failed_index = 0u;
        return NPU_DRV_EIO;
    }
    batch_result->burst_completed = 1u;
    for (index = 0u; index < command_count; index++) {
        uint64_t response;

        if (driver->ops.submit_response(
                driver->ops.context, &response) != 0) {
            if (batch_result->first_failed_index ==
                NPU_DRV_NO_FAILED_COMMAND) {
                batch_result->first_failed_index = index;
            }
            return NPU_DRV_EIO;
        }
        npu_drv_submit_result_decode(response, &results[index]);
        batch_result->responses_received++;
        if (results[index].command_id != expected_command_ids[index]) {
            saw_protocol_error = 1;
            if (batch_result->first_failed_index ==
                NPU_DRV_NO_FAILED_COMMAND) {
                batch_result->first_failed_index = index;
            }
        } else if (results[index].status != 0u) {
            saw_device_error = 1;
            if (batch_result->first_failed_index ==
                NPU_DRV_NO_FAILED_COMMAND) {
                batch_result->first_failed_index = index;
            }
        }
    }
    if (saw_protocol_error != 0) {
        return NPU_DRV_EIO;
    }
    return saw_device_error == 0 ? NPU_DRV_OK : NPU_DRV_EDEVICE;
}

int npu_drv_submit(npu_driver_t *driver,
                   const npu_drv_cmd128_t *command,
                   npu_drv_submit_result_t *result)
{
    npu_drv_submit_batch_result_t batch_result;

    return npu_drv_submit_batch(
        driver, command, 1u, result, &batch_result);
}
