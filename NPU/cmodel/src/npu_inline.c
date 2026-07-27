#include "npu_inline.h"

#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <string.h>

enum {
    NPU_COMPACT_NOP = 0,
    NPU_COMPACT_EVENT_SIGNAL = 1,
    NPU_COMPACT_EVENT_REARM = 2,
    NPU_COMPACT_EVENT_JOIN = 3,
    NPU_COMPACT_GLOBAL_FENCE = 4,
    NPU_COMPACT_DMA_COPY_1D = 5,
    NPU_COMPACT_DMA_COPY_ND = 6,
    NPU_COMPACT_DMA_FILL = 7,
    NPU_COMPACT_DMA_TRANSPOSE_2D = 8,
    NPU_COMPACT_DMA_PACK = 9,
    NPU_COMPACT_DMA_SPLIT = 10,
    NPU_COMPACT_MATRIX_GEMM = 11,
    NPU_COMPACT_MATRIX_BMM = 12,
    NPU_COMPACT_MATRIX_GEMM_ACCUM = 13,
    NPU_COMPACT_MATRIX_GEMM_ZERO = 14,
    NPU_COMPACT_VECTOR_ADD = 15,
    NPU_COMPACT_VECTOR_SUB = 16,
    NPU_COMPACT_VECTOR_MUL = 17,
    NPU_COMPACT_VECTOR_FMA = 18,
    NPU_COMPACT_VECTOR_MAX = 19,
    NPU_COMPACT_VECTOR_MIN = 20,
    NPU_COMPACT_VECTOR_CMP = 21,
    NPU_COMPACT_VECTOR_SELECT = 22,
    NPU_COMPACT_VECTOR_CLAMP = 23,
    NPU_COMPACT_VECTOR_RELU = 24,
    NPU_COMPACT_COMPLEX_ACT = 25,
    NPU_COMPACT_COMPLEX_SOFTMAX = 26,
    NPU_COMPACT_COMPLEX_NORM = 27,
    NPU_COMPACT_COMPLEX_ROPE = 28,
    NPU_COMPACT_COMPLEX_STAT = 29,
    NPU_COMPACT_COMPLEX_RECIP = 30,
    NPU_COMPACT_COMPLEX_ADD_RESCALE = 31
};

static uint64_t npu_inline_mask(uint32_t width)
{
    if (width >= 64u) {
        return UINT64_MAX;
    }
    return (UINT64_C(1) << width) - UINT64_C(1);
}

static uint64_t npu_inline_bits(const npu_cmd_t *cmd,
                                uint32_t lsb,
                                uint32_t width)
{
    uint64_t value;

    if (width == 0u || lsb >= 80u || width > 64u ||
        width > 80u - lsb) {
        return 0u;
    }
    if (lsb >= 64u) {
        value = (uint64_t)cmd->inline_payload_hi >> (lsb - 64u);
    } else {
        value = cmd->inline_payload_lo >> lsb;
        if (lsb + width > 64u) {
            value |= (uint64_t)cmd->inline_payload_hi << (64u - lsb);
        }
    }
    return value & npu_inline_mask(width);
}

static uint32_t npu_inline_dtype_bits(npu_dtype_t dtype)
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

static uint32_t npu_inline_dtype_bytes(npu_dtype_t dtype)
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

static int npu_inline_dtype_valid(npu_dtype_t dtype)
{
    return dtype == NPU_DTYPE_INT4 ||
           dtype == NPU_DTYPE_INT8 ||
           dtype == NPU_DTYPE_INT16 ||
           dtype == NPU_DTYPE_INT32;
}

static int npu_inline_mul_u64(uint64_t left,
                              uint64_t right,
                              uint64_t *result)
{
    if (right != 0u && left > UINT64_MAX / right) {
        return 0;
    }
    *result = left * right;
    return 1;
}

static int npu_inline_add_u64(uint64_t left,
                              uint64_t right,
                              uint64_t *result)
{
    if (left > UINT64_MAX - right) {
        return 0;
    }
    *result = left + right;
    return 1;
}

static int npu_inline_storage_bytes(npu_dtype_t dtype,
                                    uint64_t elements,
                                    uint64_t *bytes)
{
    uint32_t bits = npu_inline_dtype_bits(dtype);
    uint64_t total_bits;

    if (bits == 0u ||
        !npu_inline_mul_u64(elements, bits, &total_bits) ||
        total_bits > UINT64_MAX - 7u) {
        return 0;
    }
    *bytes = (total_bits + 7u) / 8u;
    return 1;
}

static int npu_inline_row_bytes(npu_dtype_t dtype,
                                uint32_t elements,
                                uint32_t *bytes)
{
    uint64_t value;

    if (!npu_inline_storage_bytes(dtype, elements, &value) ||
        value > UINT32_MAX) {
        return 0;
    }
    *bytes = (uint32_t)value;
    return 1;
}

static uint64_t npu_inline_align_up_u64(uint64_t value,
                                        uint64_t alignment)
{
    if (alignment == 0u || value > UINT64_MAX - (alignment - 1u)) {
        return UINT64_MAX;
    }
    return (value + alignment - 1u) & ~(alignment - 1u);
}

static int32_t npu_inline_sign_extend(uint32_t value, uint32_t width)
{
    uint32_t sign;
    uint32_t mask;

    if (width == 0u || width >= 32u) {
        return (int32_t)value;
    }
    sign = UINT32_C(1) << (width - 1u);
    mask = (UINT32_C(1) << width) - UINT32_C(1);
    value &= mask;
    if ((value & sign) == 0u) {
        return (int32_t)value;
    }
    return -1 - (int32_t)(mask - value);
}

static float npu_inline_pow2_scale(uint32_t raw)
{
    return ldexpf(1.0f, npu_inline_sign_extend(raw, 4u));
}

static float npu_inline_epsilon(uint32_t profile)
{
    if (profile == 0u) {
        return 1.0e-5f;
    }
    if (profile == 1u) {
        return 1.0e-6f;
    }
    if (profile == 2u) {
        return 1.0e-3f;
    }
    return 1.0e-4f;
}

static int npu_inline_address_in_range(npu_space_t space,
                                       uint64_t address,
                                       uint64_t bytes,
                                       const npu_wire_limits_t *limits)
{
    uint64_t limit =
        space == NPU_SPACE_L1 ? limits->l1_bytes : limits->gaddr_limit;

    if (address > limit) {
        return 0;
    }
    return bytes <= limit - address;
}

static npu_status_t npu_inline_resolve_aref(
    uint32_t raw,
    const npu_wire_limits_t *limits,
    npu_space_t *space,
    uint64_t *address)
{
    uint32_t base_select = (raw >> 24u) & 0x07u;
    uint64_t offset = raw & UINT32_C(0x00ffffff);

    if ((raw & UINT32_C(0x08000000)) == 0u) {
        if (base_select != 0u || offset >= limits->l1_bytes) {
            return NPU_STATUS_ADDR_FAULT;
        }
        *space = NPU_SPACE_L1;
        *address = offset;
        return NPU_STATUS_SUCCESS;
    }
    if (base_select >= 6u ||
        !npu_inline_add_u64(limits->gaddr_base[base_select],
                            offset, address) ||
        *address >= limits->gaddr_limit) {
        return NPU_STATUS_ADDR_FAULT;
    }
    *space = NPU_SPACE_DDR;
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_inline_resolve_lref(uint32_t raw,
                                           uint32_t shift,
                                           const npu_wire_limits_t *limits,
                                           uint64_t *address)
{
    *address = (uint64_t)raw << shift;
    if (*address >= limits->l1_bytes) {
        return NPU_STATUS_ADDR_FAULT;
    }
    return NPU_STATUS_SUCCESS;
}

static void npu_inline_tensor_init(npu_tensor_t *tensor,
                                   npu_space_t space,
                                   npu_dtype_t dtype,
                                   uint64_t address,
                                   uint64_t region_bytes,
                                   uint32_t row_stride,
                                   uint32_t element_stride,
                                   uint32_t batch_stride,
                                   uint8_t start_nibble)
{
    memset(tensor, 0, sizeof(*tensor));
    tensor->space = space;
    tensor->dtype = dtype;
    tensor->addr = address;
    tensor->region_bytes = region_bytes;
    tensor->row_stride_bytes = row_stride;
    tensor->elem_stride_bytes = element_stride;
    tensor->batch_stride_bytes = batch_stride;
    tensor->start_nibble = start_nibble;
}

static uint8_t npu_inline_pack_format(npu_dtype_t dtype, int tiled)
{
    if (dtype == NPU_DTYPE_INT4) {
        return (uint8_t)(tiled != 0 ? 3u : 1u);
    }
    if (dtype == NPU_DTYPE_INT8) {
        return (uint8_t)(tiled != 0 ? 2u : 0u);
    }
    if (dtype == NPU_DTYPE_INT16) {
        return (uint8_t)(tiled != 0 ? 6u : 5u);
    }
    return 4u;
}

static uint32_t npu_inline_tail(uint32_t size, uint32_t tile)
{
    if (size == 0u) {
        return 0u;
    }
    if (size % tile == 0u) {
        return tile;
    }
    return size % tile;
}

static npu_status_t npu_inline_decode_control(
    const npu_cmd_t *cmd,
    npu_task_request_t *request,
    npu_wire_meta_t *meta)
{
    uint32_t engine_mask = (uint32_t)npu_inline_bits(cmd, 76u, 4u);
    uint32_t join_mode = (uint32_t)npu_inline_bits(cmd, 75u, 1u);

    request->desc.control.event0 = cmd->wait_event[0];
    request->desc.control.event1 = cmd->wait_event[1];
    request->desc.control.target = cmd->signal_event;
    request->desc.control.join_mode = (uint8_t)join_mode;
    request->desc.control.engine_mask = (uint8_t)engine_mask;
    meta->control_join_mode = (uint8_t)join_mode;
    meta->control_engine_mask = (uint8_t)engine_mask;

    if (cmd->opcode == NPU_CTRL_EVENT_REARM) {
        request->desc.control.event0 = cmd->signal_event;
        request->desc.control.target.id = cmd->signal_event.id;
        request->desc.control.target.generation =
            (uint8_t)((cmd->signal_event.generation + 1u) & 0x0fu);
    }

    if (npu_inline_bits(cmd, 0u, 64u) != 0u ||
        npu_inline_bits(cmd, 64u, 11u) != 0u ||
        (cmd->opcode != NPU_CTRL_EVENT_JOIN && join_mode != 0u) ||
        (cmd->opcode != NPU_CTRL_GLOBAL_FENCE &&
         engine_mask != 0u)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (cmd->opcode == NPU_CTRL_NOP &&
        (cmd->wait_event[0].id != 0xffu ||
         cmd->wait_event[1].id != 0xffu ||
         cmd->signal_event.id != 0xffu)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (cmd->opcode == NPU_CTRL_EVENT_JOIN &&
        (cmd->wait_event[0].id == 0xffu ||
         cmd->wait_event[1].id == 0xffu ||
         cmd->signal_event.id == 0xffu)) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((cmd->opcode == NPU_CTRL_EVENT_SIGNAL ||
         cmd->opcode == NPU_CTRL_EVENT_REARM) &&
        cmd->signal_event.id == 0xffu) {
        return NPU_STATUS_BAD_DESC;
    }
    if (cmd->opcode == NPU_CTRL_GLOBAL_FENCE &&
        (engine_mask == 0u || (engine_mask & ~0x0fu) != 0u)) {
        return NPU_STATUS_BAD_DESC;
    }
    return NPU_STATUS_SUCCESS;
}

static npu_dma_convert_t npu_inline_convert_mode(npu_dtype_t source,
                                                 npu_dtype_t destination)
{
    uint32_t source_bits = npu_inline_dtype_bits(source);
    uint32_t destination_bits = npu_inline_dtype_bits(destination);

    if (source == destination) {
        return NPU_DMA_CONVERT_NONE;
    }
    if (source_bits < destination_bits) {
        return NPU_DMA_SIGN_EXTEND;
    }
    if (destination == NPU_DTYPE_INT4 &&
        source != NPU_DTYPE_INT4) {
        return NPU_DMA_PACK_INT4;
    }
    return NPU_DMA_SATURATE_NARROW;
}

static npu_status_t npu_inline_decode_dma(
    const npu_cmd_t *cmd,
    const npu_wire_limits_t *limits,
    npu_task_request_t *request,
    npu_wire_meta_t *meta)
{
    npu_dma_desc_t *desc = &request->desc.dma;
    uint32_t source_ref;
    uint32_t destination_ref;
    uint32_t count;
    uint32_t rows;
    uint32_t columns;
    uint32_t row_bytes;
    uint64_t source_bytes;
    uint64_t destination_bytes;
    uint64_t total;
    npu_dtype_t source_dtype = cmd->inline_dtype;
    npu_dtype_t destination_dtype = source_dtype;
    npu_status_t status;

    memset(desc, 0, sizeof(*desc));
    desc->rank = 1u;
    desc->src_dtype = source_dtype;
    desc->dst_dtype = destination_dtype;
    desc->burst_beats =
        (uint8_t)(limits->dma_max_burst_beats > 16u
                      ? 16u
                      : limits->dma_max_burst_beats);
    desc->max_outstanding =
        limits->dma_max_outstanding > 16u
            ? 16u
            : limits->dma_max_outstanding;
    meta->dma_burst_beats = desc->burst_beats;

    if (cmd->opcode == NPU_DMA_FILL) {
        destination_ref =
            (uint32_t)npu_inline_bits(cmd, 52u, 28u);
        count = (uint32_t)npu_inline_bits(cmd, 32u, 20u);
        if (count == 0u) {
            return NPU_STATUS_BAD_SHAPE;
        }
        status = npu_inline_resolve_aref(
            destination_ref, limits, &desc->dst_space, &desc->dst_addr);
        if (status != NPU_STATUS_SUCCESS ||
            !npu_inline_storage_bytes(destination_dtype, count,
                                      &destination_bytes) ||
            !npu_inline_address_in_range(
                desc->dst_space, desc->dst_addr, destination_bytes,
                limits)) {
            return NPU_STATUS_ADDR_FAULT;
        }
        desc->shape[0] = count;
        desc->fill_value = npu_inline_bits(cmd, 0u, 32u);
        desc->dst_region_bytes = destination_bytes;
        return NPU_STATUS_SUCCESS;
    }

    source_ref = (uint32_t)npu_inline_bits(cmd, 52u, 28u);
    destination_ref = (uint32_t)npu_inline_bits(cmd, 24u, 28u);
    status = npu_inline_resolve_aref(
        source_ref, limits, &desc->src_space, &desc->src_addr);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    status = npu_inline_resolve_aref(
        destination_ref, limits, &desc->dst_space, &desc->dst_addr);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }

    if (cmd->opcode == NPU_DMA_COPY_1D ||
        cmd->opcode == NPU_DMA_COPY_ND) {
        count = (uint32_t)npu_inline_bits(cmd, 4u, 20u);
        destination_dtype =
            (npu_dtype_t)npu_inline_bits(cmd, 2u, 2u);
        if (count == 0u) {
            return NPU_STATUS_BAD_SHAPE;
        }
        if (!npu_inline_dtype_valid(destination_dtype)) {
            return NPU_STATUS_DTYPE_UNSUPPORTED;
        }
        desc->dst_dtype = destination_dtype;
        desc->convert_mode =
            npu_inline_convert_mode(source_dtype, destination_dtype);
        desc->src_nibble = (uint8_t)npu_inline_bits(cmd, 1u, 1u);
        desc->dst_nibble = (uint8_t)npu_inline_bits(cmd, 0u, 1u);
        if (desc->dst_nibble != 0u ||
            !npu_inline_storage_bytes(source_dtype, count,
                                      &source_bytes) ||
            !npu_inline_storage_bytes(destination_dtype, count,
                                      &destination_bytes)) {
            return NPU_STATUS_BAD_DESC;
        }
        desc->shape[0] = count;
        desc->src_region_bytes = source_bytes;
        desc->dst_region_bytes = destination_bytes;
    } else if (cmd->opcode == NPU_DMA_TRANSPOSE_2D) {
        rows = (uint32_t)npu_inline_bits(cmd, 16u, 8u);
        columns = (uint32_t)npu_inline_bits(cmd, 8u, 8u);
        destination_dtype =
            (npu_dtype_t)npu_inline_bits(cmd, 6u, 2u);
        desc->src_nibble = (uint8_t)npu_inline_bits(cmd, 5u, 1u);
        desc->dst_nibble = (uint8_t)npu_inline_bits(cmd, 4u, 1u);
        if (rows == 0u || columns == 0u) {
            return NPU_STATUS_BAD_SHAPE;
        }
        if (destination_dtype != source_dtype ||
            desc->dst_nibble != 0u ||
            npu_inline_bits(cmd, 0u, 4u) != 0u ||
            !npu_inline_row_bytes(source_dtype, columns, &row_bytes)) {
            return NPU_STATUS_BAD_DESC;
        }
        desc->rank = 2u;
        desc->shape[0] = rows;
        desc->shape[1] = columns;
        desc->src_stride_bytes[0] = row_bytes;
        if (!npu_inline_row_bytes(destination_dtype, rows, &row_bytes)) {
            return NPU_STATUS_BAD_DESC;
        }
        desc->dst_stride_bytes[0] = row_bytes;
        if (!npu_inline_mul_u64(rows, desc->src_stride_bytes[0],
                                &source_bytes) ||
            !npu_inline_mul_u64(columns, desc->dst_stride_bytes[0],
                                &destination_bytes)) {
            return NPU_STATUS_ADDR_FAULT;
        }
        desc->src_region_bytes = source_bytes;
        desc->dst_region_bytes = destination_bytes;
    } else if (cmd->opcode == NPU_DMA_PACK ||
               cmd->opcode == NPU_DMA_SPLIT) {
        desc->segment_count =
            (uint32_t)npu_inline_bits(cmd, 16u, 8u);
        desc->segment_bytes =
            (uint32_t)npu_inline_bits(cmd, 8u, 8u);
        desc->segment_stride =
            (uint32_t)npu_inline_bits(cmd, 0u, 8u);
        if (desc->segment_count == 0u ||
            desc->segment_bytes == 0u ||
            desc->segment_stride < desc->segment_bytes) {
            return NPU_STATUS_BAD_SHAPE;
        }
        desc->shape[0] = desc->segment_count;
        if (!npu_inline_mul_u64(desc->segment_count,
                                desc->segment_bytes, &total)) {
            return NPU_STATUS_ADDR_FAULT;
        }
        if (cmd->opcode == NPU_DMA_PACK) {
            source_bytes =
                (uint64_t)(desc->segment_count - 1u) *
                    desc->segment_stride +
                desc->segment_bytes;
            destination_bytes = total;
        } else {
            source_bytes = total;
            destination_bytes =
                (uint64_t)(desc->segment_count - 1u) *
                    desc->segment_stride +
                desc->segment_bytes;
        }
        desc->src_region_bytes = source_bytes;
        desc->dst_region_bytes = destination_bytes;
    } else {
        return NPU_STATUS_ILLEGAL_OPCODE;
    }

    if (!npu_inline_address_in_range(
            desc->src_space, desc->src_addr, desc->src_region_bytes,
            limits) ||
        !npu_inline_address_in_range(
            desc->dst_space, desc->dst_addr, desc->dst_region_bytes,
            limits)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_inline_matrix_tensor(
    npu_tensor_t *tensor,
    uint32_t reference,
    npu_dtype_t dtype,
    uint64_t region_bytes,
    uint32_t row_stride,
    uint32_t batch_stride,
    const npu_wire_limits_t *limits)
{
    uint64_t address;
    npu_status_t status =
        npu_inline_resolve_lref(reference, 6u, limits, &address);

    if (status != NPU_STATUS_SUCCESS ||
        !npu_inline_address_in_range(
            NPU_SPACE_L1, address, region_bytes, limits)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    npu_inline_tensor_init(
        tensor, NPU_SPACE_L1, dtype, address, region_bytes,
        row_stride, npu_inline_dtype_bytes(dtype), batch_stride, 0u);
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_inline_decode_matrix(
    const npu_cmd_t *cmd,
    const npu_wire_limits_t *limits,
    npu_task_request_t *request,
    npu_wire_meta_t *meta)
{
    npu_matrix_desc_t *desc = &request->desc.matrix;
    uint32_t a_ref = (uint32_t)npu_inline_bits(cmd, 66u, 14u);
    uint32_t b_ref = (uint32_t)npu_inline_bits(cmd, 52u, 14u);
    uint32_t c_ref = (uint32_t)npu_inline_bits(cmd, 38u, 14u);
    uint32_t bias_ref = 0u;
    uint32_t b_int4;
    uint32_t requant_shift;
    uint32_t row_bytes_a;
    uint32_t row_bytes_b;
    uint32_t row_bytes_c;
    uint32_t batch_stride_a;
    uint32_t batch_stride_b;
    uint32_t batch_stride_c;
    uint64_t region_a;
    uint64_t region_b;
    uint64_t region_c;
    uint64_t elements_b;
    uint64_t bias_address;
    uint64_t bias_bytes;
    npu_dtype_t a_dtype = cmd->inline_dtype;
    npu_dtype_t b_dtype;
    npu_dtype_t c_dtype;
    npu_status_t status;

    memset(desc, 0, sizeof(*desc));
    if (cmd->opcode == NPU_MATRIX_BMM) {
        desc->batch_count =
            (uint32_t)npu_inline_bits(cmd, 32u, 6u) + 1u;
        desc->m = (uint32_t)npu_inline_bits(cmd, 26u, 6u) + 1u;
        desc->n = (uint32_t)npu_inline_bits(cmd, 20u, 6u) + 1u;
        desc->k = (uint32_t)npu_inline_bits(cmd, 14u, 6u) + 1u;
        b_int4 = (uint32_t)npu_inline_bits(cmd, 13u, 1u);
        c_dtype = (npu_dtype_t)npu_inline_bits(cmd, 11u, 2u);
        requant_shift = (uint32_t)npu_inline_bits(cmd, 6u, 5u);
        if (npu_inline_bits(cmd, 0u, 6u) != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else {
        bias_ref = (uint32_t)npu_inline_bits(cmd, 26u, 12u);
        desc->batch_count = 1u;
        desc->m = (uint32_t)npu_inline_bits(cmd, 20u, 6u) + 1u;
        desc->n = (uint32_t)npu_inline_bits(cmd, 14u, 6u) + 1u;
        desc->k = (uint32_t)npu_inline_bits(cmd, 8u, 6u) + 1u;
        b_int4 = (uint32_t)npu_inline_bits(cmd, 7u, 1u);
        c_dtype = (npu_dtype_t)npu_inline_bits(cmd, 5u, 2u);
        requant_shift = (uint32_t)npu_inline_bits(cmd, 0u, 5u);
    }
    if (a_dtype == NPU_DTYPE_INT8) {
        b_dtype =
            b_int4 != 0u ? NPU_DTYPE_INT4 : NPU_DTYPE_INT8;
    } else {
        if (b_int4 != 0u) {
            return NPU_STATUS_DTYPE_UNSUPPORTED;
        }
        b_dtype = a_dtype;
    }
    if (cmd->opcode == NPU_MATRIX_GEMM_ZERO) {
        uint64_t zero_region;

        if (!npu_inline_dtype_valid(c_dtype) ||
            c_dtype != NPU_DTYPE_INT32 ||
            a_ref != 0u ||
            b_ref != 0u ||
            bias_ref != 0u ||
            b_int4 != 0u ||
            requant_shift != 0u ||
            desc->k != 1u ||
            !npu_inline_row_bytes(
                c_dtype, desc->n, &row_bytes_c) ||
            !npu_inline_mul_u64(
                row_bytes_c, desc->m, &zero_region) ||
            zero_region > UINT32_MAX) {
            return NPU_STATUS_BAD_DESC;
        }
        status = npu_inline_matrix_tensor(
            &desc->c, c_ref, c_dtype, zero_region,
            row_bytes_c, (uint32_t)zero_region, limits);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        desc->k = 0u;
        desc->batch_count = 1u;
        desc->round_mode = NPU_ROUND_NEAREST_EVEN;
        desc->overflow_mode = NPU_OVERFLOW_SATURATE;
        meta->matrix_last_tile_valid_m =
            npu_inline_tail(desc->m, limits->mt);
        meta->matrix_last_tile_valid_n =
            npu_inline_tail(desc->n, limits->nt);
        meta->matrix_last_tile_valid_k = 0u;
        meta->matrix_c_pack_format =
            npu_inline_pack_format(c_dtype, 0);
        return NPU_STATUS_SUCCESS;
    }
    if (!npu_inline_dtype_valid(a_dtype) ||
        !npu_inline_dtype_valid(b_dtype) ||
        !npu_inline_dtype_valid(c_dtype) ||
        !((a_dtype == NPU_DTYPE_INT4 &&
           b_dtype == NPU_DTYPE_INT4) ||
          (a_dtype == NPU_DTYPE_INT8 &&
           (b_dtype == NPU_DTYPE_INT8 ||
            b_dtype == NPU_DTYPE_INT4)) ||
          (a_dtype == NPU_DTYPE_INT16 &&
           b_dtype == NPU_DTYPE_INT16)) ||
        !npu_inline_row_bytes(a_dtype, desc->k, &row_bytes_a) ||
        !npu_inline_row_bytes(b_dtype, desc->n, &row_bytes_b) ||
        !npu_inline_row_bytes(c_dtype, desc->n, &row_bytes_c)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }

    if (!npu_inline_mul_u64(
            row_bytes_a, desc->m, &region_a) ||
        !npu_inline_mul_u64(
            row_bytes_c, desc->m, &region_c) ||
        region_a > UINT32_MAX ||
        region_c > UINT32_MAX) {
        return NPU_STATUS_BAD_SHAPE;
    }
    batch_stride_a = (uint32_t)region_a;
    batch_stride_c = (uint32_t)region_c;
    elements_b =
        (uint64_t)((desc->k + limits->kt - 1u) / limits->kt) *
        ((desc->n + limits->nt - 1u) / limits->nt) *
        limits->kt * limits->nt;
    if (!npu_inline_storage_bytes(b_dtype, elements_b, &region_b) ||
        region_b > UINT32_MAX ||
        !npu_inline_mul_u64(batch_stride_a, desc->batch_count,
                            &region_a) ||
        !npu_inline_mul_u64(batch_stride_c, desc->batch_count,
                            &region_c) ||
        region_a > UINT32_MAX || region_c > UINT32_MAX) {
        return NPU_STATUS_BAD_SHAPE;
    }
    batch_stride_b = (uint32_t)region_b;
    if (!npu_inline_mul_u64(
            region_b, desc->batch_count, &region_b)) {
        return NPU_STATUS_BAD_SHAPE;
    }

    status = npu_inline_matrix_tensor(
        &desc->a, a_ref, a_dtype, region_a, row_bytes_a,
        batch_stride_a, limits);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    status = npu_inline_matrix_tensor(
        &desc->b, b_ref, b_dtype, region_b, row_bytes_b,
        batch_stride_b, limits);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    status = npu_inline_matrix_tensor(
        &desc->c, c_ref, c_dtype, region_c, row_bytes_c,
        batch_stride_c, limits);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }

    desc->b_tiled = 1u;
    desc->final_output =
        (uint8_t)(cmd->opcode == NPU_MATRIX_GEMM ||
                  cmd->opcode == NPU_MATRIX_BMM);
    desc->overflow_mode = NPU_OVERFLOW_SATURATE;
    desc->round_mode = NPU_ROUND_NEAREST_EVEN;
    if (cmd->opcode == NPU_MATRIX_GEMM_ACCUM) {
        if (c_dtype != NPU_DTYPE_INT32 || bias_ref != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        desc->accum_from_src2 = 1u;
        desc->src2 = desc->c;
        desc->final_output = 0u;
    }
    if (cmd->opcode == NPU_MATRIX_GEMM_ZERO) {
        if (c_dtype != NPU_DTYPE_INT32 || bias_ref != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        desc->final_output = 0u;
    }
    if (bias_ref != 0u) {
        if (cmd->opcode != NPU_MATRIX_GEMM) {
            return NPU_STATUS_BAD_DESC;
        }
        status = npu_inline_resolve_lref(
            bias_ref, 6u, limits, &bias_address);
        bias_bytes = (uint64_t)desc->n * 4u;
        if (status != NPU_STATUS_SUCCESS ||
            !npu_inline_address_in_range(
                NPU_SPACE_L1, bias_address, bias_bytes, limits)) {
            return NPU_STATUS_ADDR_FAULT;
        }
        desc->bias_enable = 1u;
        desc->bias_addr = bias_address;
        desc->bias_count = desc->n;
        desc->bias_stride_bytes = 4u;
    }
    if (c_dtype != NPU_DTYPE_INT32) {
        desc->requant_enable = 1u;
        desc->inline_requant_enable = 1u;
        desc->inline_requant_multiplier = 1u;
        desc->inline_requant_shift = (int8_t)requant_shift;
    } else if (requant_shift != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    meta->matrix_last_tile_valid_m =
        npu_inline_tail(desc->m, limits->mt);
    meta->matrix_last_tile_valid_n =
        npu_inline_tail(desc->n, limits->nt);
    meta->matrix_last_tile_valid_k =
        npu_inline_tail(desc->k, limits->kt);
    meta->matrix_a_pack_format =
        npu_inline_pack_format(a_dtype, 0);
    meta->matrix_b_pack_format =
        npu_inline_pack_format(b_dtype, 1);
    meta->matrix_c_pack_format =
        npu_inline_pack_format(c_dtype, 0);
    meta->matrix_requant_mode =
        desc->inline_requant_enable != 0u ? 3u : 0u;
    return NPU_STATUS_SUCCESS;
}

static uint32_t npu_inline_vector_row_stride(npu_dtype_t dtype,
                                             uint32_t length,
                                             npu_broadcast_t broadcast)
{
    uint32_t bytes = 0u;

    if (broadcast == NPU_BROADCAST_SCALAR ||
        broadcast == NPU_BROADCAST_FEATURE) {
        return 0u;
    }
    if (broadcast == NPU_BROADCAST_ROW) {
        return npu_inline_dtype_bytes(dtype);
    }
    if (!npu_inline_row_bytes(dtype, length, &bytes)) {
        return 0u;
    }
    return bytes;
}

static void npu_inline_vector_tensor(npu_tensor_t *tensor,
                                     uint32_t reference,
                                     npu_dtype_t dtype,
                                     uint32_t rows,
                                     uint32_t length,
                                     npu_broadcast_t broadcast)
{
    uint32_t row_stride =
        npu_inline_vector_row_stride(dtype, length, broadcast);
    uint64_t address = (uint64_t)reference << 4u;
    uint64_t region_bytes;
    uint64_t elements;

    if (broadcast == NPU_BROADCAST_SCALAR) {
        elements = 1u;
    } else if (broadcast == NPU_BROADCAST_ROW) {
        elements = rows;
    } else if (broadcast == NPU_BROADCAST_FEATURE) {
        elements = length;
    } else {
        elements = (uint64_t)rows * length;
    }
    if (!npu_inline_storage_bytes(dtype, elements, &region_bytes)) {
        region_bytes = 0u;
    }
    npu_inline_tensor_init(
        tensor, NPU_SPACE_L1, dtype, address, region_bytes,
        row_stride, npu_inline_dtype_bytes(dtype), 0u, 0u);
}

static npu_status_t npu_inline_decode_vector(
    const npu_cmd_t *cmd,
    const npu_wire_limits_t *limits,
    npu_task_request_t *request,
    npu_wire_meta_t *meta)
{
    npu_vector_desc_t *desc = &request->desc.vector;
    uint32_t src0_ref = (uint32_t)npu_inline_bits(cmd, 64u, 16u);
    uint32_t src1_raw = (uint32_t)npu_inline_bits(cmd, 48u, 16u);
    uint32_t src2_raw = (uint32_t)npu_inline_bits(cmd, 32u, 16u);
    uint32_t dst_ref = (uint32_t)npu_inline_bits(cmd, 16u, 16u);
    npu_dtype_t source_dtype = cmd->inline_dtype;
    npu_dtype_t destination_dtype = source_dtype;
    uint64_t region;

    (void)meta;
    memset(desc, 0, sizeof(*desc));
    desc->rows = (uint32_t)npu_inline_bits(cmd, 11u, 5u) + 1u;
    desc->length = (uint32_t)npu_inline_bits(cmd, 6u, 5u) + 1u;
    desc->valid_length = desc->length;
    desc->broadcast0 =
        (npu_broadcast_t)npu_inline_bits(cmd, 4u, 2u);
    desc->broadcast1 =
        (npu_broadcast_t)npu_inline_bits(cmd, 2u, 2u);
    desc->broadcast2 =
        (npu_broadcast_t)npu_inline_bits(cmd, 0u, 2u);
    desc->overflow_mode = NPU_OVERFLOW_SATURATE;
    desc->src0_scale_bits = UINT32_C(0x3f800000);
    desc->src1_scale_bits = UINT32_C(0x3f800000);
    desc->src2_scale_bits = UINT32_C(0x3f800000);
    desc->dst_scale_bits = UINT32_C(0x3f800000);

    if (cmd->opcode != NPU_VECTOR_FMA &&
        cmd->opcode != NPU_VECTOR_CMP &&
        cmd->opcode != NPU_VECTOR_SELECT &&
        cmd->opcode != NPU_VECTOR_CLAMP &&
        src2_raw != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (cmd->opcode == NPU_VECTOR_RELU &&
        (src1_raw != 0u ||
         desc->broadcast1 != NPU_BROADCAST_NONE ||
         desc->broadcast2 != NPU_BROADCAST_NONE)) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((cmd->opcode == NPU_VECTOR_CMP ||
         cmd->opcode == NPU_VECTOR_SELECT) &&
        desc->broadcast2 != NPU_BROADCAST_NONE) {
        return NPU_STATUS_BAD_DESC;
    }
    if (cmd->opcode == NPU_VECTOR_CLAMP &&
        (desc->broadcast1 != NPU_BROADCAST_NONE ||
         desc->broadcast2 != NPU_BROADCAST_NONE)) {
        return NPU_STATUS_BAD_DESC;
    }

    if (cmd->opcode == NPU_VECTOR_MUL ||
        cmd->opcode == NPU_VECTOR_FMA) {
        destination_dtype = NPU_DTYPE_INT32;
    } else if (cmd->opcode == NPU_VECTOR_CMP) {
        destination_dtype = NPU_DTYPE_INT8;
        desc->compare_mode =
            (npu_compare_t)((src2_raw >> 13u) & 0x07u);
        if (desc->compare_mode > NPU_COMPARE_GE ||
            (src2_raw & 0x1fffu) != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        src2_raw = 0u;
    } else if (cmd->opcode == NPU_VECTOR_CLAMP) {
        desc->scalar0 = npu_inline_sign_extend(src1_raw, 16u);
        desc->scalar1 = npu_inline_sign_extend(src2_raw, 16u);
        desc->clamp_min = desc->scalar0;
        desc->clamp_max = desc->scalar1;
        src1_raw = 0u;
        src2_raw = 0u;
    }

    npu_inline_vector_tensor(
        &desc->src0, src0_ref, source_dtype, desc->rows,
        desc->length, desc->broadcast0);
    npu_inline_vector_tensor(
        &desc->src1, src1_raw, source_dtype, desc->rows,
        desc->length, desc->broadcast1);
    npu_inline_vector_tensor(
        &desc->src2, src2_raw,
        cmd->opcode == NPU_VECTOR_FMA ? NPU_DTYPE_INT32
                                      : source_dtype,
        desc->rows, desc->length, desc->broadcast2);
    npu_inline_vector_tensor(
        &desc->dst, dst_ref, destination_dtype, desc->rows,
        desc->length, NPU_BROADCAST_NONE);

    if (cmd->opcode == NPU_VECTOR_SELECT) {
        desc->mask_enable = 1u;
        desc->mask_false_keep_dst = 0u;
        npu_inline_vector_tensor(
            &desc->mask, src2_raw, NPU_DTYPE_INT8, desc->rows,
            desc->length, NPU_BROADCAST_NONE);
        desc->src2.addr = 0u;
        desc->src2.region_bytes = 0u;
    }

    if (!npu_inline_address_in_range(
            NPU_SPACE_L1, desc->src0.addr,
            desc->src0.region_bytes, limits) ||
        !npu_inline_address_in_range(
            NPU_SPACE_L1, desc->dst.addr,
            desc->dst.region_bytes, limits)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    region = desc->src1.region_bytes;
    if (region != 0u &&
        !npu_inline_address_in_range(
            NPU_SPACE_L1, desc->src1.addr, region, limits)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    region = desc->src2.region_bytes;
    if (region != 0u &&
        !npu_inline_address_in_range(
            NPU_SPACE_L1, desc->src2.addr, region, limits)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    if (desc->mask_enable != 0u &&
        !npu_inline_address_in_range(
            NPU_SPACE_L1, desc->mask.addr,
            desc->mask.region_bytes, limits)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_inline_complex_tensor(
    npu_tensor_t *tensor,
    uint32_t reference,
    npu_dtype_t dtype,
    uint32_t rows,
    uint32_t length,
    npu_broadcast_t broadcast,
    const npu_wire_limits_t *limits)
{
    uint64_t address = (uint64_t)reference << 4u;
    uint64_t region_bytes;
    uint32_t row_bytes;
    uint64_t elements;

    if (!npu_inline_row_bytes(dtype, length, &row_bytes)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (broadcast == NPU_BROADCAST_FEATURE) {
        elements = length;
        row_bytes = 0u;
    } else {
        elements = (uint64_t)rows * length;
    }
    if (!npu_inline_storage_bytes(dtype, elements, &region_bytes) ||
        !npu_inline_address_in_range(
            NPU_SPACE_L1, address, region_bytes, limits)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    npu_inline_tensor_init(
        tensor, NPU_SPACE_L1, dtype, address, region_bytes,
        row_bytes, npu_inline_dtype_bytes(dtype), 0u, 0u);
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_inline_decode_complex(
    const npu_cmd_t *cmd,
    const npu_wire_limits_t *limits,
    npu_task_request_t *request,
    npu_wire_meta_t *meta)
{
    npu_complex_desc_t *desc = &request->desc.complex;
    uint32_t src_ref = (uint32_t)npu_inline_bits(cmd, 64u, 16u);
    uint32_t aux_ref = (uint32_t)npu_inline_bits(cmd, 48u, 16u);
    uint32_t dst_ref = (uint32_t)npu_inline_bits(cmd, 32u, 16u);
    uint32_t meta_bits = (uint32_t)npu_inline_bits(cmd, 0u, 19u);
    npu_dtype_t source_dtype = cmd->inline_dtype;
    npu_dtype_t destination_dtype = source_dtype;
    uint32_t parameter_row_bytes;
    uint64_t beta_address;
    uint64_t beta_offset;
    npu_status_t status;

    memset(desc, 0, sizeof(*desc));
    desc->rows = (uint32_t)npu_inline_bits(cmd, 27u, 5u) + 1u;
    desc->length = (uint32_t)npu_inline_bits(cmd, 19u, 8u) + 1u;
    desc->valid_length = desc->length;
    desc->round_mode = NPU_ROUND_NEAREST_EVEN;
    desc->overflow_mode = NPU_OVERFLOW_SATURATE;
    desc->scale_mode = NPU_SCALE_PER_TENSOR;
    desc->strict_numeric =
        (uint8_t)((cmd->header_flags >> 2u) & 0x01u);
    status = npu_inline_complex_tensor(
        &desc->src0, src_ref, source_dtype, desc->rows,
        desc->length, NPU_BROADCAST_NONE, limits);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }

    if (cmd->opcode == NPU_COMPLEX_ACT) {
        desc->function =
            (npu_function_t)((meta_bits >> 17u) & 0x03u);
        desc->src0_scale =
            npu_inline_pow2_scale((meta_bits >> 13u) & 0x0fu);
        desc->dst_scale =
            npu_inline_pow2_scale((meta_bits >> 9u) & 0x0fu);
        destination_dtype =
            (npu_dtype_t)((meta_bits >> 7u) & 0x03u);
        if (((meta_bits >> 5u) & 0x03u) == 0u) {
            desc->input_clip_min = -16.0f;
            desc->input_clip_max = 16.0f;
        } else if (((meta_bits >> 5u) & 0x03u) == 1u) {
            desc->input_clip_min = -8.0f;
            desc->input_clip_max = 8.0f;
        } else if (((meta_bits >> 5u) & 0x03u) == 2u) {
            desc->input_clip_min = -4.0f;
            desc->input_clip_max = 4.0f;
        } else {
            desc->input_clip_min = -2.0f;
            desc->input_clip_max = 2.0f;
        }
        if ((meta_bits & 0x1fu) != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (cmd->opcode == NPU_COMPLEX_SOFTMAX) {
        desc->function = NPU_FUNC_SOFTMAX;
        desc->mask_mode =
            (npu_mask_mode_t)((meta_bits >> 17u) & 0x03u);
        desc->all_mask_mode =
            (npu_all_mask_mode_t)((meta_bits >> 16u) & 0x01u);
        desc->src0_scale =
            npu_inline_pow2_scale((meta_bits >> 12u) & 0x0fu);
        desc->dst_scale =
            npu_inline_pow2_scale((meta_bits >> 8u) & 0x0fu);
        destination_dtype =
            (npu_dtype_t)((meta_bits >> 6u) & 0x03u);
        desc->scratch_request_elems = desc->length;
        desc->input_clip_min = -16.0f;
        desc->input_clip_max = 16.0f;
        if ((meta_bits & 0x3fu) != 0u ||
            desc->mask_mode == NPU_MASK_CAUSAL) {
            return NPU_STATUS_BAD_DESC;
        }
        if (desc->mask_mode == NPU_MASK_BOOLEAN) {
            status = npu_inline_complex_tensor(
                &desc->mask, aux_ref, NPU_DTYPE_INT8,
                desc->rows, desc->length, NPU_BROADCAST_NONE,
                limits);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
        } else if (desc->mask_mode == NPU_MASK_VALID_LENGTH) {
            status = npu_inline_complex_tensor(
                &desc->valid_lengths, aux_ref, NPU_DTYPE_INT32,
                desc->rows, 1u, NPU_BROADCAST_NONE, limits);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
        } else if (desc->mask_mode != NPU_MASK_NONE) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (cmd->opcode == NPU_COMPLEX_NORM) {
        desc->function =
            ((meta_bits >> 18u) & 0x01u) != 0u
                ? NPU_FUNC_RMSNORM
                : NPU_FUNC_LAYERNORM;
        desc->epsilon =
            npu_inline_epsilon((meta_bits >> 16u) & 0x03u);
        desc->src0_scale =
            npu_inline_pow2_scale((meta_bits >> 12u) & 0x0fu);
        desc->src1_scale =
            npu_inline_pow2_scale((meta_bits >> 8u) & 0x0fu);
        desc->src2_scale = desc->src1_scale;
        desc->dst_scale =
            npu_inline_pow2_scale((meta_bits >> 4u) & 0x0fu);
        destination_dtype =
            (npu_dtype_t)((meta_bits >> 2u) & 0x03u);
        desc->scratch_request_elems = desc->length;
        if ((meta_bits & 0x03u) != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        status = npu_inline_complex_tensor(
            &desc->src1, aux_ref, source_dtype, 1u,
            desc->length, NPU_BROADCAST_FEATURE, limits);
        if (status != NPU_STATUS_SUCCESS ||
            !npu_inline_row_bytes(source_dtype, desc->length,
                                  &parameter_row_bytes)) {
            return NPU_STATUS_ADDR_FAULT;
        }
        if (desc->function == NPU_FUNC_LAYERNORM) {
            beta_offset =
                npu_inline_align_up_u64(parameter_row_bytes, 64u);
            if (beta_offset == UINT64_MAX ||
                !npu_inline_add_u64(
                    desc->src1.addr, beta_offset, &beta_address) ||
                !npu_inline_address_in_range(
                    NPU_SPACE_L1, beta_address,
                    parameter_row_bytes, limits)) {
                return NPU_STATUS_ADDR_FAULT;
            }
            npu_inline_tensor_init(
                &desc->src2, NPU_SPACE_L1, source_dtype,
                beta_address, parameter_row_bytes, 0u,
                npu_inline_dtype_bytes(source_dtype), 0u, 0u);
            desc->beta_enable = 1u;
        }
    } else if (cmd->opcode == NPU_COMPLEX_STAT) {
        uint32_t stats_mode = (meta_bits >> 17u) & 0x03u;

        if ((meta_bits & 0x1ffffu) != 0u || stats_mode > 2u) {
            return NPU_STATUS_BAD_DESC;
        }
        desc->function =
            (npu_function_t)(NPU_FUNC_STAT_SUM + stats_mode);
        desc->stats_mode = 0u;
        desc->scale_mode = NPU_SCALE_NONE;
        desc->overflow_mode = NPU_OVERFLOW_SATURATE;
        destination_dtype = NPU_DTYPE_INT32;
    } else if (cmd->opcode == NPU_COMPLEX_ADD_RESCALE) {
        desc->function = NPU_FUNC_ADD_RESCALE;
        desc->src0_scale =
            npu_inline_pow2_scale((meta_bits >> 15u) & 0x0fu);
        desc->src1_scale =
            npu_inline_pow2_scale((meta_bits >> 11u) & 0x0fu);
        desc->dst_scale =
            npu_inline_pow2_scale((meta_bits >> 7u) & 0x0fu);
        destination_dtype =
            (npu_dtype_t)((meta_bits >> 5u) & 0x03u);
        if ((meta_bits & 0x1fu) != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        status = npu_inline_complex_tensor(
            &desc->src1, aux_ref, source_dtype, desc->rows,
            desc->length, NPU_BROADCAST_NONE, limits);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    } else {
        return NPU_STATUS_ILLEGAL_OPCODE;
    }
    if (!npu_inline_dtype_valid(destination_dtype)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    status = npu_inline_complex_tensor(
        &desc->dst, dst_ref, destination_dtype, desc->rows,
        cmd->opcode == NPU_COMPLEX_STAT ? 1u : desc->length,
        NPU_BROADCAST_NONE, limits);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }

    meta->cme_approx_mode = 0u;
    meta->cme_stats_mode = desc->stats_mode;
    meta->internal_fp32_enable =
        (uint8_t)(cmd->opcode != NPU_COMPLEX_STAT);
    meta->scale_mode = (uint8_t)desc->scale_mode;
    meta->saturate_enable = 1u;
    return NPU_STATUS_SUCCESS;
}

int npu_inline_opcode_decode(uint8_t compact_opcode,
                             npu_engine_t *engine,
                             uint8_t *opcode)
{
    if (engine == (npu_engine_t *)0 || opcode == (uint8_t *)0 ||
        compact_opcode > NPU_COMPACT_COMPLEX_ADD_RESCALE) {
        return 0;
    }
    if (compact_opcode <= NPU_COMPACT_GLOBAL_FENCE) {
        *engine = NPU_ENGINE_CONTROL;
        *opcode = compact_opcode;
    } else if (compact_opcode <= NPU_COMPACT_DMA_SPLIT) {
        *engine = NPU_ENGINE_DMA;
        *opcode =
            (uint8_t)(NPU_DMA_COPY_1D +
                      compact_opcode - NPU_COMPACT_DMA_COPY_1D);
    } else if (compact_opcode <= NPU_COMPACT_MATRIX_GEMM_ZERO) {
        *engine = NPU_ENGINE_MATRIX;
        *opcode =
            (uint8_t)(NPU_MATRIX_GEMM +
                      compact_opcode - NPU_COMPACT_MATRIX_GEMM);
    } else if (compact_opcode <= NPU_COMPACT_VECTOR_RELU) {
        *engine = NPU_ENGINE_VECTOR;
        *opcode =
            (uint8_t)(NPU_VECTOR_ADD +
                      compact_opcode - NPU_COMPACT_VECTOR_ADD);
    } else {
        static const uint8_t complex_opcode[7] = {
            NPU_COMPLEX_ACT,
            NPU_COMPLEX_SOFTMAX,
            NPU_COMPLEX_NORM,
            NPU_COMPLEX_ROPE,
            NPU_COMPLEX_STAT,
            NPU_COMPLEX_RECIP,
            NPU_COMPLEX_ADD_RESCALE
        };
        *engine = NPU_ENGINE_COMPLEX;
        *opcode =
            complex_opcode[compact_opcode - NPU_COMPACT_COMPLEX_ACT];
    }
    return 1;
}

int npu_inline_opcode_encode(npu_engine_t engine,
                             uint8_t opcode,
                             uint8_t *compact_opcode)
{
    if (compact_opcode == (uint8_t *)0) {
        return 0;
    }
    if (engine == NPU_ENGINE_CONTROL &&
        opcode <= NPU_CTRL_GLOBAL_FENCE) {
        *compact_opcode = opcode;
        return 1;
    }
    if (engine == NPU_ENGINE_DMA &&
        opcode >= NPU_DMA_COPY_1D &&
        opcode <= NPU_DMA_SPLIT) {
        *compact_opcode =
            (uint8_t)(NPU_COMPACT_DMA_COPY_1D +
                      opcode - NPU_DMA_COPY_1D);
        return 1;
    }
    if (engine == NPU_ENGINE_MATRIX &&
        opcode >= NPU_MATRIX_GEMM &&
        opcode <= NPU_MATRIX_GEMM_ZERO) {
        *compact_opcode =
            (uint8_t)(NPU_COMPACT_MATRIX_GEMM +
                      opcode - NPU_MATRIX_GEMM);
        return 1;
    }
    if (engine == NPU_ENGINE_VECTOR &&
        opcode >= NPU_VECTOR_ADD &&
        opcode <= NPU_VECTOR_RELU) {
        *compact_opcode =
            (uint8_t)(NPU_COMPACT_VECTOR_ADD +
                      opcode - NPU_VECTOR_ADD);
        return 1;
    }
    if (engine == NPU_ENGINE_COMPLEX) {
        if (opcode == NPU_COMPLEX_ACT) {
            *compact_opcode = NPU_COMPACT_COMPLEX_ACT;
            return 1;
        }
        if (opcode == NPU_COMPLEX_SOFTMAX) {
            *compact_opcode = NPU_COMPACT_COMPLEX_SOFTMAX;
            return 1;
        }
        if (opcode == NPU_COMPLEX_NORM) {
            *compact_opcode = NPU_COMPACT_COMPLEX_NORM;
            return 1;
        }
        if (opcode == NPU_COMPLEX_ROPE) {
            *compact_opcode = NPU_COMPACT_COMPLEX_ROPE;
            return 1;
        }
        if (opcode == NPU_COMPLEX_STAT) {
            *compact_opcode = NPU_COMPACT_COMPLEX_STAT;
            return 1;
        }
        if (opcode == NPU_COMPLEX_RECIP) {
            *compact_opcode = NPU_COMPACT_COMPLEX_RECIP;
            return 1;
        }
        if (opcode == NPU_COMPLEX_ADD_RESCALE) {
            *compact_opcode = NPU_COMPACT_COMPLEX_ADD_RESCALE;
            return 1;
        }
    }
    return 0;
}

npu_status_t npu_inline_decode_task(
    const npu_cmd_t *cmd,
    const npu_wire_limits_t *limits,
    npu_task_request_t *request,
    npu_wire_meta_t *meta)
{
    npu_status_t status;

    if (cmd == (const npu_cmd_t *)0 ||
        limits == (const npu_wire_limits_t *)0 ||
        request == (npu_task_request_t *)0 ||
        meta == (npu_wire_meta_t *)0 ||
        cmd->inline_format == 0u ||
        !npu_inline_dtype_valid(cmd->inline_dtype)) {
        return NPU_STATUS_BAD_DESC;
    }
    memset(request, 0, sizeof(*request));
    memset(meta, 0, sizeof(*meta));
    request->cmd = *cmd;
    request->cmd.user_tag = cmd->command_id;
    request->desc_version = NPU_INLINE_DESC_VERSION;
    request->desc_bytes = NPU_WIRE_CMD_BYTES;
    meta->desc_version = NPU_INLINE_DESC_VERSION;
    meta->desc_type = (uint8_t)cmd->engine;
    meta->desc_bytes = NPU_WIRE_CMD_BYTES;

    if (cmd->engine == NPU_ENGINE_CONTROL) {
        status = npu_inline_decode_control(cmd, request, meta);
    } else if (cmd->engine == NPU_ENGINE_DMA) {
        status = npu_inline_decode_dma(cmd, limits, request, meta);
    } else if (cmd->engine == NPU_ENGINE_MATRIX) {
        status = npu_inline_decode_matrix(cmd, limits, request, meta);
    } else if (cmd->engine == NPU_ENGINE_VECTOR) {
        status = npu_inline_decode_vector(cmd, limits, request, meta);
    } else if (cmd->engine == NPU_ENGINE_COMPLEX) {
        status = npu_inline_decode_complex(cmd, limits, request, meta);
    } else {
        status = NPU_STATUS_ILLEGAL_OPCODE;
    }
    return status;
}
