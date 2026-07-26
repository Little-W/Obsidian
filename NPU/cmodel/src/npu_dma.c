#include "npu_internal.h"

#include <limits.h>

static int npu_dma_dtype_pair_valid(const npu_dma_desc_t *desc)
{
    uint32_t src_bits;
    uint32_t dst_bits;

    if (!npu_dtype_valid(desc->src_dtype) ||
        !npu_dtype_valid(desc->dst_dtype)) {
        return 0;
    }
    src_bits = npu_dtype_bits(desc->src_dtype);
    dst_bits = npu_dtype_bits(desc->dst_dtype);
    if (desc->convert_mode == NPU_DMA_CONVERT_NONE) {
        return desc->src_dtype == desc->dst_dtype;
    }
    if (desc->convert_mode == NPU_DMA_SIGN_EXTEND) {
        return src_bits < dst_bits;
    }
    if (desc->convert_mode == NPU_DMA_SATURATE_NARROW) {
        return src_bits > dst_bits;
    }
    if (desc->convert_mode == NPU_DMA_PACK_INT4) {
        return src_bits > 4u &&
               desc->dst_dtype == NPU_DTYPE_INT4;
    }
    return 0;
}

static npu_status_t npu_dma_span(const npu_dma_desc_t *desc,
                                 int source,
                                 uint64_t *span)
{
    npu_dtype_t dtype = source != 0 ? desc->src_dtype : desc->dst_dtype;
    const uint32_t *stride = source != 0 ? desc->src_stride_bytes
                                         : desc->dst_stride_bytes;
    uint8_t nibble = source != 0 ? desc->src_nibble : desc->dst_nibble;
    uint64_t maximum = 0u;
    uint64_t add;
    uint32_t d;
    uint32_t last;
    uint32_t bytes;

    if (desc->rank == 0u || desc->rank > NPU_MAX_DMA_RANK) {
        return NPU_STATUS_BAD_SHAPE;
    }
    for (d = 0u; d < desc->rank; d++) {
        if (desc->shape[d] == 0u) {
            *span = 0u;
            return NPU_STATUS_SUCCESS;
        }
    }
    for (d = 0u; d + 1u < desc->rank; d++) {
        if (desc->shape[d] > 1u && stride[d] == 0u) {
            return NPU_STATUS_BAD_SHAPE;
        }
        add = (uint64_t)(desc->shape[d] == 0u ? 0u
                                             : desc->shape[d] - 1u) *
              stride[d];
        if (UINT64_MAX - maximum < add) {
            return NPU_STATUS_ADDR_FAULT;
        }
        maximum += add;
    }
    last = desc->shape[desc->rank - 1u];
    if (last == 0u) {
        *span = 0u;
        return NPU_STATUS_SUCCESS;
    }
    if (dtype == NPU_DTYPE_INT4) {
        add = ((uint64_t)nibble + last + 1u) / 2u;
    } else {
        bytes = npu_dtype_bytes(dtype);
        add = (uint64_t)last * bytes;
    }
    if (UINT64_MAX - maximum < add) {
        return NPU_STATUS_ADDR_FAULT;
    }
    *span = maximum + add;
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_dma_element_location(const npu_dma_desc_t *desc,
                                             int source,
                                             const uint32_t index[],
                                             uint64_t *addr,
                                             uint8_t *high)
{
    npu_dtype_t dtype = source != 0 ? desc->src_dtype : desc->dst_dtype;
    const uint32_t *stride = source != 0 ? desc->src_stride_bytes
                                         : desc->dst_stride_bytes;
    uint64_t base = source != 0 ? desc->src_addr : desc->dst_addr;
    uint8_t start = source != 0 ? desc->src_nibble : desc->dst_nibble;
    uint64_t offset = 0u;
    uint64_t add;
    uint64_t half;
    uint32_t d;

    if (desc->rank == 0u ||
        desc->rank > NPU_MAX_DMA_RANK) {
        return NPU_STATUS_BAD_SHAPE;
    }
    for (d = 0u; d + 1u < desc->rank; d++) {
        add = (uint64_t)index[d] * stride[d];
        if (UINT64_MAX - offset < add) {
            return NPU_STATUS_ADDR_FAULT;
        }
        offset += add;
    }
    if (dtype == NPU_DTYPE_INT4) {
        half = (uint64_t)start + index[desc->rank - 1u];
        if (UINT64_MAX - offset < half / 2u) {
            return NPU_STATUS_ADDR_FAULT;
        }
        offset += half / 2u;
        *high = (uint8_t)(half & 1u);
    } else {
        add = (uint64_t)index[desc->rank - 1u] *
              npu_dtype_bytes(dtype);
        if (UINT64_MAX - offset < add) {
            return NPU_STATUS_ADDR_FAULT;
        }
        offset += add;
        *high = 0u;
    }
    if (UINT64_MAX - base < offset) {
        return NPU_STATUS_ADDR_FAULT;
    }
    *addr = base + offset;
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_dma_read_value(const npu_model_t *model,
                                       npu_space_t space,
                                       npu_dtype_t dtype,
                                       uint64_t addr,
                                       uint8_t high,
                                       int32_t *value)
{
    uint8_t byte_value;
    npu_status_t status;

    if (dtype == NPU_DTYPE_INT32) {
        return npu_memory_read_i32(model, space, addr, value);
    }
    if (dtype == NPU_DTYPE_INT16) {
        return npu_memory_read_i16(model, space, addr, value);
    }
    status = npu_memory_read_u8(model, space, addr, &byte_value);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (dtype == NPU_DTYPE_INT4) {
        *value = npu_int4_unpack(byte_value, high);
    } else if ((byte_value & 0x80u) != 0u) {
        *value = -1 - (int32_t)(0xffu - byte_value);
    } else {
        *value = byte_value;
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_dma_write_value(npu_model_t *model,
                                        npu_space_t space,
                                        npu_dtype_t dtype,
                                        uint64_t addr,
                                        uint8_t high,
                                        int32_t value)
{
    uint8_t byte_value;
    npu_status_t status;

    if (dtype == NPU_DTYPE_INT32) {
        return npu_memory_write_i32(model, space, addr, value);
    }
    if (dtype == NPU_DTYPE_INT16) {
        return npu_memory_write_i16(model, space, addr, value);
    }
    if (dtype == NPU_DTYPE_INT8) {
        return npu_memory_write_u8(model, space, addr, (uint8_t)value);
    }
    status = npu_memory_read_u8(model, space, addr, &byte_value);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    byte_value = npu_int4_insert(byte_value, high, value);
    return npu_memory_write_u8(model, space, addr, byte_value);
}

static int npu_dma_advance_index(const npu_dma_desc_t *desc,
                                 uint32_t index[])
{
    uint32_t d = desc->rank;

    while (d != 0u) {
        d--;
        index[d]++;
        if (index[d] < desc->shape[d]) {
            return 1;
        }
        index[d] = 0u;
    }
    return 0;
}

static npu_status_t npu_dma_copy_elements(npu_model_t *model,
                                          const npu_dma_desc_t *desc,
                                          uint64_t *progress)
{
    uint32_t index[NPU_MAX_DMA_RANK] = {0u, 0u, 0u, 0u, 0u};
    uint32_t d;
    uint64_t src_addr;
    uint64_t dst_addr;
    uint8_t src_high;
    uint8_t dst_high;
    int32_t value;
    int32_t converted;
    npu_status_t status;
    int more = 1;

    for (d = 0u; d < desc->rank; d++) {
        if (desc->shape[d] == 0u) {
            *progress = 0u;
            return NPU_STATUS_SUCCESS;
        }
    }

    while (more != 0) {
        status = npu_dma_element_location(desc, 1, index,
                                          &src_addr, &src_high);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        status = npu_dma_element_location(desc, 0, index,
                                          &dst_addr, &dst_high);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        status = npu_dma_read_value(model, desc->src_space, desc->src_dtype,
                                    src_addr, src_high, &value);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        status = npu_cast_integer(model, value, desc->dst_dtype,
                                  NPU_OVERFLOW_SATURATE, &converted);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        status = npu_dma_write_value(model, desc->dst_space, desc->dst_dtype,
                                     dst_addr, dst_high, converted);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        if (desc->dst_dtype == NPU_DTYPE_INT4) {
            if (dst_high == 0u) {
                (*progress)++;
            }
        } else {
            *progress += npu_dtype_bytes(desc->dst_dtype);
        }
        more = npu_dma_advance_index(desc, index);
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_dma_check_pack_int4(
    const npu_model_t *model,
    const npu_dma_desc_t *desc,
    uint64_t *checked_bytes)
{
    uint32_t index[NPU_MAX_DMA_RANK] = {0u, 0u, 0u, 0u, 0u};
    uint32_t d;
    uint64_t src_addr;
    uint8_t src_high;
    int32_t value;
    npu_status_t status;
    int more = 1;

    if (checked_bytes == (uint64_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    *checked_bytes = 0u;
    if (desc->convert_mode != NPU_DMA_PACK_INT4) {
        return NPU_STATUS_SUCCESS;
    }
    for (d = 0u; d < desc->rank; d++) {
        if (desc->shape[d] == 0u) {
            return NPU_STATUS_SUCCESS;
        }
    }
    while (more != 0) {
        status = npu_dma_element_location(desc, 1, index,
                                          &src_addr, &src_high);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        status = npu_dma_read_value(model, desc->src_space,
                                    desc->src_dtype, src_addr,
                                    src_high, &value);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        *checked_bytes += npu_dtype_bytes(desc->src_dtype);
        if (value < -8 || value > 7) {
            return NPU_STATUS_NUMERIC_EXCEPTION;
        }
        more = npu_dma_advance_index(desc, index);
    }
    return NPU_STATUS_SUCCESS;
}

static int32_t npu_dma_fill_value(const npu_dma_desc_t *desc)
{
    uint32_t low = (uint32_t)desc->fill_value;

    if (desc->dst_dtype == NPU_DTYPE_INT4) {
        return npu_int4_unpack((uint8_t)low, 0u);
    }
    if (desc->dst_dtype == NPU_DTYPE_INT8) {
        if ((low & 0x80u) != 0u) {
            return -1 - (int32_t)(0xffu - (low & 0xffu));
        }
        return (int32_t)(low & 0xffu);
    }
    if (desc->dst_dtype == NPU_DTYPE_INT16) {
        if ((low & 0x8000u) != 0u) {
            return -1 - (int32_t)(0xffffu - (low & 0xffffu));
        }
        return (int32_t)(low & 0xffffu);
    }
    if (low <= 0x7fffffffu) {
        return (int32_t)low;
    }
    return -1 - (int32_t)(0xffffffffu - low);
}

static npu_status_t npu_dma_fill_elements(npu_model_t *model,
                                          const npu_dma_desc_t *desc,
                                          uint64_t *progress)
{
    uint32_t index[NPU_MAX_DMA_RANK] = {0u, 0u, 0u, 0u, 0u};
    uint32_t d;
    uint64_t dst_addr;
    uint8_t dst_high;
    int32_t value = npu_dma_fill_value(desc);
    npu_status_t status;
    int more = 1;

    for (d = 0u; d < desc->rank; d++) {
        if (desc->shape[d] == 0u) {
            *progress = 0u;
            return NPU_STATUS_SUCCESS;
        }
    }
    while (more != 0) {
        status = npu_dma_element_location(desc, 0, index,
                                          &dst_addr, &dst_high);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        status = npu_dma_write_value(model, desc->dst_space, desc->dst_dtype,
                                     dst_addr, dst_high, value);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        if (desc->dst_dtype == NPU_DTYPE_INT4) {
            if (dst_high == 0u) {
                (*progress)++;
            }
        } else {
            *progress += npu_dtype_bytes(desc->dst_dtype);
        }
        more = npu_dma_advance_index(desc, index);
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_dma_clear_int4_copy_tails(
    npu_model_t *model,
    const npu_dma_desc_t *desc)
{
    uint32_t index[NPU_MAX_DMA_RANK] = {0u, 0u, 0u, 0u, 0u};
    uint32_t d;
    uint64_t addr;
    uint8_t high;
    uint8_t value;
    npu_status_t status;
    int more = 1;

    if (desc->dst_dtype != NPU_DTYPE_INT4 ||
        desc->rank == 0u ||
        desc->shape[desc->rank - 1u] == 0u ||
        (desc->shape[desc->rank - 1u] & 1u) == 0u) {
        return NPU_STATUS_SUCCESS;
    }
    for (d = 0u; d + 1u < desc->rank; d++) {
        if (desc->shape[d] == 0u) {
            return NPU_STATUS_SUCCESS;
        }
    }
    index[desc->rank - 1u] =
        desc->shape[desc->rank - 1u] - 1u;
    while (more != 0) {
        status = npu_dma_element_location(desc, 0, index,
                                          &addr, &high);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        if (high != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        status = npu_memory_read_u8(model, desc->dst_space,
                                    addr, &value);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        status = npu_memory_write_u8(model, desc->dst_space,
                                     addr, (uint8_t)(value & 0x0fu));
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }

        more = 0;
        d = desc->rank - 1u;
        while (d != 0u) {
            d--;
            index[d]++;
            if (index[d] < desc->shape[d]) {
                more = 1;
                break;
            }
            index[d] = 0u;
        }
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_dma_clear_int4_transpose_tails(
    npu_model_t *model,
    const npu_dma_desc_t *desc)
{
    uint32_t row;
    uint64_t row_offset;
    uint64_t addr;
    uint8_t value;
    npu_status_t status;

    if (desc->dst_dtype != NPU_DTYPE_INT4 ||
        desc->shape[0] == 0u ||
        desc->shape[1] == 0u ||
        (desc->shape[0] & 1u) == 0u) {
        return NPU_STATUS_SUCCESS;
    }
    for (row = 0u; row < desc->shape[1]; row++) {
        row_offset = (uint64_t)row * desc->dst_stride_bytes[0];
        row_offset += (uint64_t)(desc->shape[0] - 1u) / 2u;
        if (UINT64_MAX - desc->dst_addr < row_offset) {
            return NPU_STATUS_ADDR_FAULT;
        }
        addr = desc->dst_addr + row_offset;
        status = npu_memory_read_u8(model, desc->dst_space,
                                    addr, &value);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        status = npu_memory_write_u8(model, desc->dst_space,
                                     addr, (uint8_t)(value & 0x0fu));
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_dma_transpose(npu_model_t *model,
                                      const npu_dma_desc_t *desc,
                                      uint64_t *progress)
{
    uint32_t row;
    uint32_t col;
    uint32_t src_index[NPU_MAX_DMA_RANK] = {0u, 0u, 0u, 0u, 0u};
    uint64_t src_addr;
    uint64_t dst_addr;
    uint8_t src_high;
    uint8_t dst_high;
    int32_t value;
    int32_t converted;
    npu_status_t status;

    if (desc->rank != 2u) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (desc->shape[0] == 0u || desc->shape[1] == 0u) {
        *progress = 0u;
        return NPU_STATUS_SUCCESS;
    }
    for (row = 0u; row < desc->shape[0]; row++) {
        for (col = 0u; col < desc->shape[1]; col++) {
            src_index[0] = row;
            src_index[1] = col;
            status = npu_dma_element_location(desc, 1, src_index,
                                              &src_addr, &src_high);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }

            /*
             * Destination shape is [source_cols, source_rows].  The public
             * descriptor stores only the source logical shape, so destination
             * address arithmetic is written explicitly here.
             */
            dst_addr = desc->dst_addr +
                       (uint64_t)col * desc->dst_stride_bytes[0];
            if (desc->dst_dtype == NPU_DTYPE_INT4) {
                uint64_t half = (uint64_t)desc->dst_nibble + row;
                dst_addr += half / 2u;
                dst_high = (uint8_t)(half & 1u);
            } else {
                dst_addr += (uint64_t)row *
                            npu_dtype_bytes(desc->dst_dtype);
                dst_high = 0u;
            }
            status = npu_dma_read_value(model, desc->src_space,
                                        desc->src_dtype, src_addr,
                                        src_high, &value);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_cast_integer(model, value, desc->dst_dtype,
                                      NPU_OVERFLOW_SATURATE, &converted);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_dma_write_value(model, desc->dst_space,
                                         desc->dst_dtype, dst_addr,
                                         dst_high, converted);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            if (desc->dst_dtype == NPU_DTYPE_INT4) {
                if (dst_high == 0u) {
                    (*progress)++;
                }
            } else {
                *progress += npu_dtype_bytes(desc->dst_dtype);
            }
        }
    }
    return npu_dma_clear_int4_transpose_tails(model, desc);
}

static npu_status_t npu_dma_segment_copy(npu_model_t *model,
                                         const npu_dma_desc_t *desc,
                                         int split,
                                         uint64_t *progress)
{
    uint32_t segment;
    uint32_t byte;
    uint64_t src;
    uint64_t dst;
    uint8_t value;
    npu_status_t status;

    if (desc->convert_mode != NPU_DMA_CONVERT_NONE ||
        desc->src_dtype != desc->dst_dtype) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->segment_count == 0u || desc->segment_bytes == 0u) {
        *progress = 0u;
        return NPU_STATUS_SUCCESS;
    }
    for (segment = 0u; segment < desc->segment_count; segment++) {
        if (split != 0) {
            src = desc->src_addr +
                  (uint64_t)segment * desc->segment_bytes;
            dst = desc->dst_addr +
                  (uint64_t)segment * desc->segment_stride;
        } else {
            src = desc->src_addr +
                  (uint64_t)segment * desc->segment_stride;
            dst = desc->dst_addr +
                  (uint64_t)segment * desc->segment_bytes;
        }
        for (byte = 0u; byte < desc->segment_bytes; byte++) {
            status = npu_memory_read_u8(model, desc->src_space,
                                        src + byte, &value);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_memory_write_u8(model, desc->dst_space,
                                         dst + byte, value);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            (*progress)++;
        }
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_dma_payload_bytes(
    const npu_dma_desc_t *desc,
    uint8_t opcode,
    int source,
    uint64_t *bytes)
{
    npu_dtype_t dtype = source != 0 ? desc->src_dtype
                                    : desc->dst_dtype;
    uint8_t nibble = source != 0 ? desc->src_nibble
                                 : desc->dst_nibble;
    uint64_t outer = 1u;
    uint64_t row_bytes;
    uint32_t row_length;
    uint32_t d;

    if (opcode == NPU_DMA_FILL && source != 0) {
        *bytes = 0u;
        return NPU_STATUS_SUCCESS;
    }
    if (opcode == NPU_DMA_PACK || opcode == NPU_DMA_SPLIT) {
        if (desc->segment_count != 0u &&
            desc->segment_bytes >
                UINT64_MAX / desc->segment_count) {
            return NPU_STATUS_ADDR_FAULT;
        }
        *bytes = (uint64_t)desc->segment_count *
                 desc->segment_bytes;
        return NPU_STATUS_SUCCESS;
    }
    if (opcode == NPU_DMA_TRANSPOSE_2D) {
        outer = source != 0 ? desc->shape[0]
                            : desc->shape[1];
        row_length = source != 0 ? desc->shape[1]
                                 : desc->shape[0];
    } else {
        row_length = desc->shape[desc->rank - 1u];
        for (d = 0u; d + 1u < desc->rank; d++) {
            if (desc->shape[d] != 0u &&
                outer > UINT64_MAX / desc->shape[d]) {
                return NPU_STATUS_ADDR_FAULT;
            }
            outer *= desc->shape[d];
        }
    }
    if (outer == 0u || row_length == 0u) {
        *bytes = 0u;
        return NPU_STATUS_SUCCESS;
    }
    if (dtype == NPU_DTYPE_INT4) {
        row_bytes = ((uint64_t)nibble + row_length + 1u) / 2u;
    } else {
        row_bytes = (uint64_t)row_length *
                    npu_dtype_bytes(dtype);
    }
    if (row_bytes != 0u && outer > UINT64_MAX / row_bytes) {
        return NPU_STATUS_ADDR_FAULT;
    }
    *bytes = outer * row_bytes;
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_dma_validate(const npu_model_t *model,
                                     uint8_t opcode,
                                     const npu_dma_desc_t *desc,
                                     uint64_t *src_span,
                                     uint64_t *dst_span)
{
    npu_status_t status;
    uint32_t d;

    if (desc == (const npu_dma_desc_t *)0 ||
        desc->rank == 0u ||
        desc->rank > NPU_MAX_DMA_RANK ||
        desc->dst_nibble > 1u ||
        desc->src_nibble > 1u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->dst_dtype == NPU_DTYPE_INT4 && desc->dst_nibble != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((desc->src_dtype != NPU_DTYPE_INT4 &&
         desc->src_nibble != 0u) ||
        (desc->dst_dtype != NPU_DTYPE_INT4 &&
         desc->dst_nibble != 0u)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (opcode == NPU_DMA_COPY_1D && desc->rank != 1u) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (opcode != NPU_DMA_FILL && !npu_dma_dtype_pair_valid(desc)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (opcode == NPU_DMA_TRANSPOSE_2D &&
        (desc->convert_mode != NPU_DMA_CONVERT_NONE ||
         desc->src_dtype != desc->dst_dtype)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (opcode == NPU_DMA_FILL) {
        if (desc->convert_mode != NPU_DMA_CONVERT_NONE) {
            return NPU_STATUS_BAD_DESC;
        }
        for (d = 0u; d < NPU_MAX_DMA_RANK; d++) {
            if (desc->src_stride_bytes[d] != 0u) {
                return NPU_STATUS_BAD_DESC;
            }
        }
        if (desc->src_addr != 0u ||
            desc->src_region_bytes != 0u ||
            desc->src_nibble != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    }
    if (opcode == NPU_DMA_FILL && !npu_dtype_valid(desc->dst_dtype)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (desc->burst_beats == 0u ||
        desc->burst_beats > model->config.dma_max_burst_beats ||
        desc->max_outstanding == 0u ||
        desc->max_outstanding > model->config.dma_outstanding) {
        return NPU_STATUS_BAD_DESC;
    }
    for (d = desc->rank; d < NPU_MAX_DMA_RANK; d++) {
        if (desc->shape[d] != 0u ||
            desc->src_stride_bytes[d] != 0u ||
            desc->dst_stride_bytes[d] != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    }

    if (opcode == NPU_DMA_PACK || opcode == NPU_DMA_SPLIT) {
        uint64_t packed_bytes;
        uint64_t spaced_bytes;
        if (desc->rank != 1u ||
            desc->segment_count == 0u ||
            desc->segment_bytes == 0u ||
            desc->segment_stride < desc->segment_bytes ||
            desc->convert_mode != NPU_DMA_CONVERT_NONE ||
            desc->src_dtype != desc->dst_dtype ||
            desc->fill_value != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        if (desc->shape[0] != desc->segment_count) {
            return NPU_STATUS_BAD_SHAPE;
        }
        for (d = 0u; d < NPU_MAX_DMA_RANK; d++) {
            if (desc->src_stride_bytes[d] != 0u ||
                desc->dst_stride_bytes[d] != 0u) {
                return NPU_STATUS_BAD_DESC;
            }
        }
        packed_bytes =
            (uint64_t)desc->segment_count * desc->segment_bytes;
        spaced_bytes =
            (uint64_t)(desc->segment_count - 1u) *
                desc->segment_stride +
            desc->segment_bytes;
        *src_span = opcode == NPU_DMA_PACK ? spaced_bytes : packed_bytes;
        *dst_span = opcode == NPU_DMA_PACK ? packed_bytes : spaced_bytes;
    } else if (opcode == NPU_DMA_TRANSPOSE_2D) {
        uint32_t src_elem_bytes =
            desc->src_dtype == NPU_DTYPE_INT4
                ? 0u
                : npu_dtype_bytes(desc->src_dtype);
        uint32_t dst_elem_bytes =
            desc->dst_dtype == NPU_DTYPE_INT4
                ? 0u
                : npu_dtype_bytes(desc->dst_dtype);
        if (desc->rank != 2u) {
            return NPU_STATUS_BAD_SHAPE;
        }
        if (desc->src_stride_bytes[1] != 0u ||
            desc->dst_stride_bytes[1] != 0u ||
            desc->segment_count != 0u ||
            desc->segment_bytes != 0u ||
            desc->segment_stride != 0u ||
            desc->fill_value != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        if (desc->shape[0] != 0u &&
            desc->shape[1] != 0u) {
            uint64_t src_outer =
                (uint64_t)(desc->shape[0] - 1u) *
                desc->src_stride_bytes[0];
            uint64_t dst_outer =
                (uint64_t)(desc->shape[1] - 1u) *
                desc->dst_stride_bytes[0];
            uint64_t src_inner =
                desc->src_dtype == NPU_DTYPE_INT4
                    ? ((uint64_t)desc->src_nibble +
                       desc->shape[1] + 1u) /
                          2u
                    : (uint64_t)desc->shape[1] * src_elem_bytes;
            uint64_t dst_inner =
                desc->dst_dtype == NPU_DTYPE_INT4
                    ? ((uint64_t)desc->dst_nibble +
                       desc->shape[0] + 1u) /
                          2u
                    : (uint64_t)desc->shape[0] * dst_elem_bytes;
            if (UINT64_MAX - src_outer < src_inner ||
                UINT64_MAX - dst_outer < dst_inner) {
                return NPU_STATUS_ADDR_FAULT;
            }
        }
        *src_span = desc->shape[0] == 0u || desc->shape[1] == 0u
                        ? 0u
                        : (uint64_t)(desc->shape[0] - 1u) *
                                  desc->src_stride_bytes[0] +
                              (desc->src_dtype == NPU_DTYPE_INT4
                                   ? ((uint64_t)desc->src_nibble +
                                      desc->shape[1] + 1u) /
                                         2u
                                   : (uint64_t)desc->shape[1] *
                                         src_elem_bytes);
        *dst_span = desc->shape[0] == 0u || desc->shape[1] == 0u
                        ? 0u
                        : (uint64_t)(desc->shape[1] - 1u) *
                                  desc->dst_stride_bytes[0] +
                              (desc->dst_dtype == NPU_DTYPE_INT4
                                   ? ((uint64_t)desc->dst_nibble +
                                      desc->shape[0] + 1u) /
                                         2u
                                   : (uint64_t)desc->shape[0] *
                                         dst_elem_bytes);
    } else {
        if (desc->segment_count != 0u ||
            desc->segment_bytes != 0u ||
            desc->segment_stride != 0u ||
            (opcode != NPU_DMA_FILL && desc->fill_value != 0u)) {
            return NPU_STATUS_BAD_DESC;
        }
        if (desc->src_stride_bytes[desc->rank - 1u] != 0u ||
            desc->dst_stride_bytes[desc->rank - 1u] != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        status = npu_dma_span(desc, 0, dst_span);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        if (opcode == NPU_DMA_FILL) {
            *src_span = 0u;
        } else {
            status = npu_dma_span(desc, 1, src_span);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
        }
    }

    if (*dst_span > desc->dst_region_bytes ||
        !npu_memory_range_valid(model, desc->dst_space,
                                desc->dst_addr, *dst_span)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    if (opcode != NPU_DMA_FILL &&
        (*src_span > desc->src_region_bytes ||
         !npu_memory_range_valid(model, desc->src_space,
                                 desc->src_addr, *src_span))) {
        return NPU_STATUS_ADDR_FAULT;
    }
    if (opcode != NPU_DMA_FILL &&
        desc->src_space == desc->dst_space &&
        npu_regions_overlap(desc->src_addr, *src_span,
                            desc->dst_addr, *dst_span)) {
        return NPU_STATUS_ADDR_OVERLAP;
    }
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_dma_execute(npu_model_t *model,
                             uint8_t opcode,
                             const npu_dma_desc_t *desc,
                             uint64_t *progress)
{
    uint64_t src_span = 0u;
    uint64_t dst_span = 0u;
    uint64_t src_payload = 0u;
    uint64_t checked_bytes = 0u;
    npu_status_t status;

    if (model == (npu_model_t *)0 ||
        desc == (const npu_dma_desc_t *)0 ||
        progress == (uint64_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    *progress = 0u;
    if (opcode != NPU_DMA_COPY_1D &&
        opcode != NPU_DMA_COPY_ND &&
        opcode != NPU_DMA_FILL &&
        opcode != NPU_DMA_TRANSPOSE_2D &&
        opcode != NPU_DMA_PACK &&
        opcode != NPU_DMA_SPLIT) {
        return NPU_STATUS_ILLEGAL_OPCODE;
    }

    status = npu_dma_validate(model, opcode, desc, &src_span, &dst_span);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    status = npu_dma_check_pack_int4(model, desc, &checked_bytes);
    if (status != NPU_STATUS_SUCCESS) {
        if (desc->src_space == NPU_SPACE_DDR) {
            model->perf.dma_read_bytes += checked_bytes;
        }
        return status;
    }
    status = npu_dma_payload_bytes(desc, opcode, 1,
                                   &src_payload);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (opcode == NPU_DMA_FILL) {
        status = npu_dma_fill_elements(model, desc, progress);
    } else if (opcode == NPU_DMA_TRANSPOSE_2D) {
        status = npu_dma_transpose(model, desc, progress);
    } else if (opcode == NPU_DMA_PACK) {
        status = npu_dma_segment_copy(model, desc, 0, progress);
    } else if (opcode == NPU_DMA_SPLIT) {
        status = npu_dma_segment_copy(model, desc, 1, progress);
    } else {
        status = npu_dma_copy_elements(model, desc, progress);
    }
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (opcode == NPU_DMA_COPY_1D ||
        opcode == NPU_DMA_COPY_ND ||
        opcode == NPU_DMA_FILL) {
        status = npu_dma_clear_int4_copy_tails(model, desc);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    if (desc->src_space == NPU_SPACE_DDR) {
        model->perf.dma_read_bytes += src_payload;
    }
    if (desc->dst_space == NPU_SPACE_DDR) {
        model->perf.dma_write_bytes += *progress;
    }
    return NPU_STATUS_SUCCESS;
}
