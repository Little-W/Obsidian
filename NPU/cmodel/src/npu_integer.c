#include "npu_internal.h"
#include "npu_engine_data_cycle.h"

#include <limits.h>

void npu_fault_capture_record(const npu_model_t *model,
                              npu_space_t space,
                              uint64_t addr)
{
    npu_fault_capture_t *capture;

    if (model == (const npu_model_t *)0 ||
        model->internal_fault_capture == (void *)0) {
        return;
    }
    capture = (npu_fault_capture_t *)model->internal_fault_capture;
    if (capture->valid != 0u) {
        return;
    }
    capture->valid = 1u;
    capture->space = space;
    capture->addr = addr;
}

uint64_t npu_ceil_div_u64(uint64_t value, uint64_t divisor)
{
    if (divisor == 0u) {
        return 0u;
    }
    return value / divisor + ((value % divisor) != 0u);
}

uint32_t npu_dtype_bits(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT4) {
        return 4u;
    }
    if (dtype == NPU_DTYPE_INT8) {
        return 8u;
    }
    if (dtype == NPU_DTYPE_INT16) {
        return 16u;
    }
    if (dtype == NPU_DTYPE_INT32) {
        return 32u;
    }
    return 0u;
}

uint32_t npu_dtype_bytes(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT8) {
        return 1u;
    }
    if (dtype == NPU_DTYPE_INT16) {
        return 2u;
    }
    if (dtype == NPU_DTYPE_INT32) {
        return 4u;
    }
    return 0u;
}

int npu_dtype_valid(npu_dtype_t dtype)
{
    return dtype == NPU_DTYPE_INT4 ||
           dtype == NPU_DTYPE_INT8 ||
           dtype == NPU_DTYPE_INT16 ||
           dtype == NPU_DTYPE_INT32;
}

static const uint8_t *npu_memory_read_base(const npu_model_t *model,
                                           npu_space_t space,
                                           size_t *size)
{
    if (space == NPU_SPACE_L1) {
        *size = model->l1_size;
        return model->l1;
    }
    if (space == NPU_SPACE_DDR) {
        *size = model->ddr_size;
        return model->ddr;
    }
    *size = 0u;
    return (const uint8_t *)0;
}

static uint8_t *npu_memory_write_base(npu_model_t *model,
                                      npu_space_t space,
                                      size_t *size)
{
    if (space == NPU_SPACE_L1) {
        *size = model->l1_size;
        return model->l1;
    }
    if (space == NPU_SPACE_DDR) {
        *size = model->ddr_size;
        return model->ddr;
    }
    *size = 0u;
    return (uint8_t *)0;
}

static npu_bus_trace_t *npu_memory_bus_trace(
    const npu_model_t *model)
{
    if (model == (const npu_model_t *)0 ||
        model->internal_bus_trace == (void *)0) {
        return (npu_bus_trace_t *)0;
    }
    return (npu_bus_trace_t *)model->internal_bus_trace;
}

int npu_model_trace_next_read_pass(npu_model_t *model)
{
    return npu_bus_trace_next_read_pass(
        npu_memory_bus_trace(model));
}

uint8_t npu_model_trace_set_read_capture(
    npu_model_t *model,
    uint8_t enable)
{
    return npu_bus_trace_set_read_capture(
        npu_memory_bus_trace(model), enable);
}

static npu_status_t npu_memory_read_valid_byte(
    const npu_model_t *model,
    npu_space_t space,
    const uint8_t *base,
    uint64_t addr,
    uint8_t *value)
{
    npu_bus_trace_t *trace = npu_memory_bus_trace(model);

    *value = base[(size_t)addr];
    if (trace != (npu_bus_trace_t *)0) {
        (void)npu_bus_trace_lookup_write_byte(
            trace, space, addr, value);
        if (!npu_bus_trace_record_read_byte(
                trace, space, addr, *value)) {
            return NPU_STATUS_BUS_SLVERR;
        }
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_memory_write_valid_byte(
    npu_model_t *model,
    npu_space_t space,
    uint8_t *base,
    uint64_t addr,
    uint8_t value)
{
    npu_bus_trace_t *trace = npu_memory_bus_trace(model);

    if (trace != (npu_bus_trace_t *)0) {
        if (!npu_bus_trace_record_write_byte(
                trace, space, addr, value)) {
            return NPU_STATUS_BUS_SLVERR;
        }
    } else {
        base[(size_t)addr] = value;
    }
    return NPU_STATUS_SUCCESS;
}

int npu_memory_range_valid(const npu_model_t *model,
                           npu_space_t space,
                           uint64_t addr,
                           uint64_t bytes)
{
    size_t size = 0u;
    const uint8_t *base = npu_memory_read_base(model, space, &size);
    uint64_t limit = (uint64_t)size;

    if (base == (const uint8_t *)0) {
        npu_fault_capture_record(model, space, addr);
        return 0;
    }
    if (addr > limit) {
        npu_fault_capture_record(model, space, addr);
        return 0;
    }
    if (bytes > limit - addr) {
        npu_fault_capture_record(model, space, limit);
        return 0;
    }
    return 1;
}

npu_status_t npu_memory_read_u8(const npu_model_t *model,
                                npu_space_t space,
                                uint64_t addr,
                                uint8_t *value)
{
    size_t size = 0u;
    const uint8_t *base;

    if (value == (uint8_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    base = npu_memory_read_base(model, space, &size);
    if (base == (const uint8_t *)0 || addr >= (uint64_t)size) {
        npu_fault_capture_record(model, space, addr);
        return NPU_STATUS_ADDR_FAULT;
    }
    return npu_memory_read_valid_byte(
        model, space, base, addr, value);
}

npu_status_t npu_memory_write_u8(npu_model_t *model,
                                 npu_space_t space,
                                 uint64_t addr,
                                 uint8_t value)
{
    size_t size = 0u;
    uint8_t *base = npu_memory_write_base(model, space, &size);

    if (base == (uint8_t *)0 || addr >= (uint64_t)size) {
        npu_fault_capture_record(model, space, addr);
        return NPU_STATUS_ADDR_FAULT;
    }
    return npu_memory_write_valid_byte(
        model, space, base, addr, value);
}

npu_status_t npu_memory_read_i16(const npu_model_t *model,
                                 npu_space_t space,
                                 uint64_t addr,
                                 int32_t *value)
{
    size_t size = 0u;
    const uint8_t *base;
    uint8_t bytes[2];
    uint16_t bits;
    uint32_t index;
    npu_status_t status;

    if (value == (int32_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    base = npu_memory_read_base(model, space, &size);
    if (base == (const uint8_t *)0 ||
        addr > (uint64_t)size ||
        2u > (uint64_t)size - addr) {
        npu_fault_capture_record(
            model, space,
            base == (const uint8_t *)0 || addr > (uint64_t)size
                ? addr
                : (uint64_t)size);
        return NPU_STATUS_ADDR_FAULT;
    }
    for (index = 0u; index < 2u; index++) {
        status = npu_memory_read_valid_byte(
            model, space, base, addr + index, &bytes[index]);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    bits = (uint16_t)bytes[0] |
           (uint16_t)((uint16_t)bytes[1] << 8u);
    if (bits <= UINT16_C(0x7fff)) {
        *value = (int32_t)bits;
    } else {
        *value = -1 - (int32_t)(UINT16_C(0xffff) - bits);
    }
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_memory_write_i16(npu_model_t *model,
                                  npu_space_t space,
                                  uint64_t addr,
                                  int32_t value)
{
    size_t size = 0u;
    uint8_t *base = npu_memory_write_base(model, space, &size);
    uint16_t bits = (uint16_t)value;
    uint32_t index;
    npu_status_t status;

    if (base == (uint8_t *)0 ||
        addr > (uint64_t)size ||
        2u > (uint64_t)size - addr) {
        npu_fault_capture_record(
            model, space,
            base == (uint8_t *)0 || addr > (uint64_t)size
                ? addr
                : (uint64_t)size);
        return NPU_STATUS_ADDR_FAULT;
    }
    for (index = 0u; index < 2u; index++) {
        status = npu_memory_write_valid_byte(
            model, space, base, addr + index,
            (uint8_t)(bits >> (index * 8u)));
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_memory_read_u32(const npu_model_t *model,
                                 npu_space_t space,
                                 uint64_t addr,
                                 uint32_t *value)
{
    size_t size = 0u;
    const uint8_t *base;
    uint8_t bytes[4];
    uint32_t index;
    npu_status_t status;

    if (value == (uint32_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    base = npu_memory_read_base(model, space, &size);
    if (base == (const uint8_t *)0 ||
        addr > (uint64_t)size ||
        4u > (uint64_t)size - addr) {
        npu_fault_capture_record(
            model, space,
            base == (const uint8_t *)0 || addr > (uint64_t)size
                ? addr
                : (uint64_t)size);
        return NPU_STATUS_ADDR_FAULT;
    }
    for (index = 0u; index < 4u; index++) {
        status = npu_memory_read_valid_byte(
            model, space, base, addr + index,
            &bytes[index]);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    *value = (uint32_t)bytes[0] |
             ((uint32_t)bytes[1] << 8) |
             ((uint32_t)bytes[2] << 16) |
             ((uint32_t)bytes[3] << 24);
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_memory_read_i32(const npu_model_t *model,
                                 npu_space_t space,
                                 uint64_t addr,
                                 int32_t *value)
{
    uint32_t bits = 0u;
    npu_status_t status = npu_memory_read_u32(model, space, addr, &bits);

    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (bits <= 0x7fffffffu) {
        *value = (int32_t)bits;
    } else {
        *value = -1 - (int32_t)(0xffffffffu - bits);
    }
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_memory_write_i32(npu_model_t *model,
                                  npu_space_t space,
                                  uint64_t addr,
                                  int32_t value)
{
    size_t size = 0u;
    uint8_t *base = npu_memory_write_base(model, space, &size);
    uint32_t bits = (uint32_t)value;
    uint32_t index;
    npu_status_t status;

    if (base == (uint8_t *)0 ||
        addr > (uint64_t)size ||
        4u > (uint64_t)size - addr) {
        npu_fault_capture_record(
            model, space,
            base == (uint8_t *)0 || addr > (uint64_t)size
                ? addr
                : (uint64_t)size);
        return NPU_STATUS_ADDR_FAULT;
    }
    for (index = 0u; index < 4u; index++) {
        status = npu_memory_write_valid_byte(
            model, space, base, addr + index,
            (uint8_t)(bits >> (index * 8u)));
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    return NPU_STATUS_SUCCESS;
}

int npu_regions_overlap(uint64_t addr0,
                        uint64_t bytes0,
                        uint64_t addr1,
                        uint64_t bytes1)
{
    if (bytes0 == 0u || bytes1 == 0u) {
        return 0;
    }
    if (addr0 <= addr1) {
        return addr1 - addr0 < bytes0;
    }
    return addr0 - addr1 < bytes1;
}

int8_t npu_int4_unpack(uint8_t packed, uint8_t high_nibble)
{
    uint8_t value = high_nibble != 0u ? (uint8_t)(packed >> 4)
                                      : (uint8_t)(packed & 0x0fu);
    if ((value & 0x08u) != 0u) {
        return (int8_t)(-1 - (int8_t)(0x0fu - value));
    }
    return (int8_t)value;
}

uint8_t npu_int4_insert(uint8_t packed, uint8_t high_nibble, int32_t value)
{
    uint8_t nibble = (uint8_t)value & 0x0fu;

    if (high_nibble != 0u) {
        return (uint8_t)((packed & 0x0fu) | (uint8_t)(nibble << 4));
    }
    return (uint8_t)((packed & 0xf0u) | nibble);
}

npu_status_t npu_tensor_location(const npu_model_t *model,
                                 const npu_tensor_t *tensor,
                                 uint32_t batch,
                                 uint32_t row,
                                 uint32_t element,
                                 uint64_t *byte_addr,
                                 uint8_t *high_nibble)
{
    uint64_t offset = 0u;
    uint64_t row_part;
    uint64_t batch_part;
    uint64_t elem_part;
    uint32_t elem_bytes;

    if (tensor == (const npu_tensor_t *)0 ||
        byte_addr == (uint64_t *)0 ||
        high_nibble == (uint8_t *)0 ||
        !npu_dtype_valid(tensor->dtype)) {
        return NPU_STATUS_BAD_DESC;
    }

    batch_part = (uint64_t)batch * (uint64_t)tensor->batch_stride_bytes;
    row_part = (uint64_t)row * (uint64_t)tensor->row_stride_bytes;
    if (batch != 0u &&
        tensor->batch_stride_bytes != 0u &&
        batch_part / tensor->batch_stride_bytes != batch) {
        npu_fault_capture_record(model, tensor->space, UINT64_MAX);
        return NPU_STATUS_ADDR_FAULT;
    }
    if (row != 0u &&
        tensor->row_stride_bytes != 0u &&
        row_part / tensor->row_stride_bytes != row) {
        npu_fault_capture_record(model, tensor->space, UINT64_MAX);
        return NPU_STATUS_ADDR_FAULT;
    }
    if (UINT64_MAX - batch_part < row_part) {
        npu_fault_capture_record(model, tensor->space, UINT64_MAX);
        return NPU_STATUS_ADDR_FAULT;
    }
    offset = batch_part + row_part;

    if (tensor->dtype == NPU_DTYPE_INT4) {
        uint64_t half_index;
        if (tensor->elem_stride_bytes != 0u) {
            elem_part = (uint64_t)element *
                        (uint64_t)tensor->elem_stride_bytes;
            if (UINT64_MAX - offset < elem_part) {
                npu_fault_capture_record(model, tensor->space,
                                         UINT64_MAX);
                return NPU_STATUS_ADDR_FAULT;
            }
            offset += elem_part;
            half_index = tensor->start_nibble;
        } else {
            half_index = (uint64_t)tensor->start_nibble + element;
            if (UINT64_MAX - offset < half_index / 2u) {
                npu_fault_capture_record(model, tensor->space,
                                         UINT64_MAX);
                return NPU_STATUS_ADDR_FAULT;
            }
            offset += half_index / 2u;
        }
        *high_nibble = (uint8_t)(half_index & 1u);
    } else {
        elem_bytes = npu_dtype_bytes(tensor->dtype);
        elem_part = (uint64_t)element *
                    (uint64_t)(tensor->elem_stride_bytes != 0u
                                   ? tensor->elem_stride_bytes
                                   : elem_bytes);
        if (UINT64_MAX - offset < elem_part) {
            npu_fault_capture_record(model, tensor->space, UINT64_MAX);
            return NPU_STATUS_ADDR_FAULT;
        }
        offset += elem_part;
        *high_nibble = 0u;
    }

    if (UINT64_MAX - tensor->addr < offset) {
        npu_fault_capture_record(model, tensor->space, UINT64_MAX);
        return NPU_STATUS_ADDR_FAULT;
    }
    *byte_addr = tensor->addr + offset;

    elem_bytes = tensor->dtype == NPU_DTYPE_INT4
                     ? 1u
                     : npu_dtype_bytes(tensor->dtype);
    if (tensor->region_bytes != 0u) {
        if (offset >= tensor->region_bytes ||
            elem_bytes > tensor->region_bytes - offset) {
            uint64_t first_invalid =
                offset >= tensor->region_bytes
                    ? *byte_addr
                    : (UINT64_MAX - tensor->addr <
                               tensor->region_bytes
                           ? UINT64_MAX
                           : tensor->addr +
                                 tensor->region_bytes);
            npu_fault_capture_record(model, tensor->space,
                                     first_invalid);
            return NPU_STATUS_ADDR_FAULT;
        }
    }
    if (!npu_memory_range_valid(model, tensor->space, *byte_addr, elem_bytes)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_tensor_read(const npu_model_t *model,
                             const npu_tensor_t *tensor,
                             uint32_t batch,
                             uint32_t row,
                             uint32_t element,
                             int32_t *value)
{
    uint64_t addr = 0u;
    uint8_t high = 0u;
    uint8_t byte_value = 0u;
    npu_status_t status;

    if (value == (int32_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    status = npu_tensor_location(model, tensor, batch, row, element,
                                 &addr, &high);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (tensor->dtype == NPU_DTYPE_INT4) {
        status = npu_memory_read_u8(model, tensor->space, addr, &byte_value);
        if (status == NPU_STATUS_SUCCESS) {
            *value = npu_int4_unpack(byte_value, high);
        }
        return status;
    }
    if (tensor->dtype == NPU_DTYPE_INT8) {
        status = npu_memory_read_u8(model, tensor->space, addr, &byte_value);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        if ((byte_value & 0x80u) != 0u) {
            *value = -1 - (int32_t)(0xffu - byte_value);
        } else {
            *value = byte_value;
        }
        return NPU_STATUS_SUCCESS;
    }
    if (tensor->dtype == NPU_DTYPE_INT16) {
        return npu_memory_read_i16(model, tensor->space, addr, value);
    }
    return npu_memory_read_i32(model, tensor->space, addr, value);
}

npu_status_t npu_tensor_write(npu_model_t *model,
                              const npu_tensor_t *tensor,
                              uint32_t batch,
                              uint32_t row,
                              uint32_t element,
                              int32_t value)
{
    uint64_t addr = 0u;
    uint8_t high = 0u;
    uint8_t byte_value = 0u;
    npu_status_t status;

    status = npu_tensor_location(model, tensor, batch, row, element,
                                 &addr, &high);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (tensor->dtype == NPU_DTYPE_INT4) {
        status = npu_memory_read_u8(model, tensor->space, addr, &byte_value);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        byte_value = npu_int4_insert(byte_value, high, value);
        return npu_memory_write_u8(model, tensor->space, addr, byte_value);
    }
    if (tensor->dtype == NPU_DTYPE_INT8) {
        return npu_memory_write_u8(model, tensor->space, addr,
                                   (uint8_t)value);
    }
    if (tensor->dtype == NPU_DTYPE_INT16) {
        return npu_memory_write_i16(model, tensor->space, addr, value);
    }
    return npu_memory_write_i32(model, tensor->space, addr, value);
}

void npu_clear_int4_tail(npu_model_t *model,
                         const npu_tensor_t *tensor,
                         uint32_t batch,
                         uint32_t row,
                         uint32_t length)
{
    uint64_t addr = 0u;
    uint8_t high = 0u;
    uint8_t value = 0u;

    if (tensor == (const npu_tensor_t *)0 ||
        tensor->dtype != NPU_DTYPE_INT4 ||
        tensor->start_nibble != 0u ||
        (length & 1u) == 0u ||
        length == 0u) {
        return;
    }
    if (npu_tensor_location(model, tensor, batch, row, length - 1u,
                            &addr, &high) != NPU_STATUS_SUCCESS) {
        return;
    }
    if (high != 0u) {
        return;
    }
    if (npu_memory_read_u8(model, tensor->space, addr, &value) !=
        NPU_STATUS_SUCCESS) {
        return;
    }
    value &= 0x0fu;
    (void)npu_memory_write_u8(model, tensor->space, addr, value);
}

static uint64_t npu_abs_i64(int64_t value)
{
    uint64_t bits = (uint64_t)value;
    if (value < 0) {
        return (~bits) + 1u;
    }
    return bits;
}

static int64_t npu_restore_sign(uint64_t magnitude, int negative)
{
    if (!negative) {
        if (magnitude > (uint64_t)INT64_MAX) {
            return INT64_MAX;
        }
        return (int64_t)magnitude;
    }
    if (magnitude >= (UINT64_C(1) << 63)) {
        return INT64_MIN;
    }
    return -(int64_t)magnitude;
}

int64_t npu_round_shift(int64_t value,
                        int32_t shift,
                        npu_round_mode_t mode)
{
    uint64_t magnitude;
    uint64_t quotient;
    uint64_t remainder;
    uint64_t mask;
    uint64_t half;
    int negative = value < 0;
    uint32_t right;
    uint32_t left;
    int increment = 0;

    if (shift == 0) {
        return value;
    }
    magnitude = npu_abs_i64(value);

    if (shift > 0) {
        right = (uint32_t)shift;
        if (right >= 64u) {
            quotient = 0u;
            remainder = magnitude;
            if (mode == NPU_ROUND_TO_POS_INF && !negative &&
                remainder != 0u) {
                quotient = 1u;
            } else if (mode == NPU_ROUND_TO_NEG_INF && negative &&
                       remainder != 0u) {
                quotient = 1u;
            }
            return npu_restore_sign(quotient, negative);
        }
        mask = (UINT64_C(1) << right) - 1u;
        quotient = magnitude >> right;
        remainder = magnitude & mask;
        half = UINT64_C(1) << (right - 1u);

        if (mode == NPU_ROUND_NEAREST_EVEN) {
            if (remainder > half ||
                (remainder == half && (quotient & 1u) != 0u)) {
                increment = 1;
            }
        } else if (mode == NPU_ROUND_TO_POS_INF) {
            increment = !negative && remainder != 0u;
        } else if (mode == NPU_ROUND_TO_NEG_INF) {
            increment = negative && remainder != 0u;
        }
        if (increment != 0 && quotient != UINT64_MAX) {
            quotient++;
        }
        return npu_restore_sign(quotient, negative);
    }

    left = (uint32_t)(-(int64_t)shift);
    if (magnitude == 0u) {
        return 0;
    }
    if (left >= 63u) {
        return negative ? INT64_MIN : INT64_MAX;
    }
    if (!negative) {
        if (magnitude > ((uint64_t)INT64_MAX >> left)) {
            return INT64_MAX;
        }
    } else if (magnitude > ((UINT64_C(1) << 63) >> left)) {
        return INT64_MIN;
    }
    magnitude <<= left;
    return npu_restore_sign(magnitude, negative);
}

static int32_t npu_wrap_integer(int64_t value, uint32_t bits)
{
    uint64_t mask;
    uint64_t raw;
    uint64_t sign;

    if (bits == 32u) {
        mask = UINT64_C(0xffffffff);
    } else {
        mask = (UINT64_C(1) << bits) - 1u;
    }
    raw = (uint64_t)value & mask;
    sign = UINT64_C(1) << (bits - 1u);
    if ((raw & sign) == 0u) {
        return (int32_t)raw;
    }
    return -1 - (int32_t)(mask - raw);
}

npu_status_t npu_cast_integer(npu_model_t *model,
                              int64_t value,
                              npu_dtype_t dtype,
                              npu_overflow_mode_t mode,
                              int32_t *result)
{
    int64_t minimum;
    int64_t maximum;
    uint32_t bits;

    if (result == (int32_t *)0 || !npu_dtype_valid(dtype)) {
        return NPU_STATUS_BAD_DESC;
    }
    bits = npu_dtype_bits(dtype);
    if (dtype == NPU_DTYPE_INT4) {
        minimum = -8;
        maximum = 7;
    } else if (dtype == NPU_DTYPE_INT8) {
        minimum = -128;
        maximum = 127;
    } else if (dtype == NPU_DTYPE_INT16) {
        minimum = INT16_MIN;
        maximum = INT16_MAX;
    } else {
        minimum = INT32_MIN;
        maximum = INT32_MAX;
    }

    if (value >= minimum && value <= maximum) {
        *result = (int32_t)value;
        return NPU_STATUS_SUCCESS;
    }
    npu_engine_data_record_integer_range(model, dtype);
    if (mode == NPU_OVERFLOW_ERROR) {
        return NPU_STATUS_NUMERIC_EXCEPTION;
    }
    if (mode == NPU_OVERFLOW_WRAP) {
        *result = npu_wrap_integer(value, bits);
        return NPU_STATUS_SUCCESS;
    }
    *result = value < minimum ? (int32_t)minimum : (int32_t)maximum;
    if (model != (npu_model_t *)0) {
        model->perf.int_saturate_count++;
    }
    return NPU_STATUS_SUCCESS;
}
