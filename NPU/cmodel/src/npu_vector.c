#include "npu_internal.h"

#include <limits.h>

#define NPU_VECTOR_MAX_BEAT_ELEMENTS 16u

static npu_status_t npu_vector_read_operand(const npu_model_t *model,
                                            const npu_tensor_t *tensor,
                                            npu_broadcast_t broadcast,
                                            uint32_t row,
                                            uint32_t element,
                                            int32_t *value)
{
    uint32_t source_row = row;
    uint32_t source_element = element;

    if (broadcast == NPU_BROADCAST_SCALAR) {
        source_row = 0u;
        source_element = 0u;
    } else if (broadcast == NPU_BROADCAST_ROW) {
        source_element = 0u;
    } else if (broadcast == NPU_BROADCAST_FEATURE) {
        source_row = 0u;
    } else if (broadcast != NPU_BROADCAST_NONE) {
        return NPU_STATUS_BAD_DESC;
    }
    return npu_tensor_read(model, tensor, 0u, source_row,
                           source_element, value);
}

static int npu_vector_compare(int32_t a,
                              int32_t b,
                              npu_compare_t mode)
{
    if (mode == NPU_COMPARE_EQ) {
        return a == b;
    }
    if (mode == NPU_COMPARE_NE) {
        return a != b;
    }
    if (mode == NPU_COMPARE_LT) {
        return a < b;
    }
    if (mode == NPU_COMPARE_LE) {
        return a <= b;
    }
    if (mode == NPU_COMPARE_GT) {
        return a > b;
    }
    if (mode == NPU_COMPARE_GE) {
        return a >= b;
    }
    return 0;
}

static int npu_vector_opcode_valid(uint8_t opcode)
{
    return opcode >= NPU_VECTOR_ADD && opcode <= NPU_VECTOR_RELU;
}

static int npu_vector_uses_src1(uint8_t opcode)
{
    return opcode == NPU_VECTOR_ADD ||
           opcode == NPU_VECTOR_SUB ||
           opcode == NPU_VECTOR_MUL ||
           opcode == NPU_VECTOR_FMA ||
           opcode == NPU_VECTOR_MAX ||
           opcode == NPU_VECTOR_MIN ||
           opcode == NPU_VECTOR_CMP ||
           opcode == NPU_VECTOR_SELECT;
}

static int npu_vector_scale_is_positive_finite(uint32_t bits)
{
    return (bits & 0x80000000u) == 0u &&
           (bits & 0x7fffffffu) != 0u &&
           (bits & 0x7f800000u) != 0x7f800000u;
}

static npu_status_t npu_vector_validate(uint8_t opcode,
                                        const npu_vector_desc_t *desc)
{
    uint64_t row_span;
    uint64_t stride;
    uint32_t dst_bytes;
    uint32_t dst_alignment;

    if (!npu_vector_opcode_valid(opcode)) {
        return NPU_STATUS_ILLEGAL_OPCODE;
    }
    if (desc->overflow_mode > NPU_OVERFLOW_WRAP ||
        desc->broadcast0 > NPU_BROADCAST_FEATURE ||
        (npu_vector_uses_src1(opcode) &&
         desc->broadcast1 > NPU_BROADCAST_FEATURE) ||
        (opcode == NPU_VECTOR_FMA &&
         desc->broadcast2 > NPU_BROADCAST_FEATURE) ||
        (!npu_vector_uses_src1(opcode) &&
         desc->src1_from_scalar0 != 0u) ||
        (opcode != NPU_VECTOR_FMA &&
         desc->src2_from_scalar1 != 0u) ||
        (desc->mask_enable == 0u &&
         desc->mask_false_keep_dst != 0u)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->valid_length > desc->length ||
        (desc->rows > 0u && desc->length > 0u &&
         desc->valid_length == 0u)) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (desc->rows == 0u && desc->valid_length != 0u) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (desc->src0.space != NPU_SPACE_L1 ||
        desc->dst.space != NPU_SPACE_L1 ||
        !npu_dtype_valid(desc->src0.dtype) ||
        !npu_dtype_valid(desc->dst.dtype)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (npu_vector_uses_src1(opcode) &&
        desc->src1_from_scalar0 == 0u &&
        (desc->src1.space != NPU_SPACE_L1 ||
         !npu_dtype_valid(desc->src1.dtype))) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((opcode == NPU_VECTOR_ADD ||
         opcode == NPU_VECTOR_SUB ||
         opcode == NPU_VECTOR_MAX ||
         opcode == NPU_VECTOR_MIN ||
         opcode == NPU_VECTOR_SELECT) &&
        (desc->src0.dtype != desc->src1.dtype ||
         desc->src0.dtype != desc->dst.dtype)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if ((opcode == NPU_VECTOR_CLAMP ||
         opcode == NPU_VECTOR_RELU) &&
        desc->src0.dtype != desc->dst.dtype) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (opcode == NPU_VECTOR_CLAMP &&
        desc->clamp_min > desc->clamp_max) {
        return NPU_STATUS_BAD_DESC;
    }
    if (opcode == NPU_VECTOR_CMP &&
        (desc->src0.dtype != desc->src1.dtype ||
         desc->dst.dtype != NPU_DTYPE_INT8 ||
         desc->compare_mode > NPU_COMPARE_GE)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (opcode == NPU_VECTOR_MUL &&
        !((desc->src0.dtype == NPU_DTYPE_INT4 ||
           desc->src0.dtype == NPU_DTYPE_INT8 ||
           desc->src0.dtype == NPU_DTYPE_INT16) &&
          (desc->src1.dtype == NPU_DTYPE_INT4 ||
           desc->src1.dtype == NPU_DTYPE_INT8 ||
           desc->src1.dtype == NPU_DTYPE_INT16) &&
          ((desc->src0.dtype == NPU_DTYPE_INT16) ==
           (desc->src1.dtype == NPU_DTYPE_INT16)) &&
          desc->dst.dtype == NPU_DTYPE_INT32)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (opcode == NPU_VECTOR_FMA &&
        !((desc->src0.dtype == NPU_DTYPE_INT4 ||
           desc->src0.dtype == NPU_DTYPE_INT8 ||
           desc->src0.dtype == NPU_DTYPE_INT16) &&
          (desc->src1.dtype == NPU_DTYPE_INT4 ||
           desc->src1.dtype == NPU_DTYPE_INT8 ||
           desc->src1.dtype == NPU_DTYPE_INT16) &&
          ((desc->src0.dtype == NPU_DTYPE_INT16) ==
           (desc->src1.dtype == NPU_DTYPE_INT16)) &&
          desc->src2.dtype == NPU_DTYPE_INT32 &&
          desc->dst.dtype == NPU_DTYPE_INT32)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (opcode == NPU_VECTOR_SELECT &&
        (desc->mask_enable == 0u ||
         desc->mask_false_keep_dst != 0u)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->mask_enable != 0u &&
        (desc->mask.space != NPU_SPACE_L1 ||
         desc->mask.dtype != NPU_DTYPE_INT8)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (!npu_vector_scale_is_positive_finite(desc->src0_scale_bits) ||
        !npu_vector_scale_is_positive_finite(desc->dst_scale_bits) ||
        (npu_vector_uses_src1(opcode) &&
         !npu_vector_scale_is_positive_finite(desc->src1_scale_bits)) ||
        (opcode == NPU_VECTOR_FMA &&
         !npu_vector_scale_is_positive_finite(desc->src2_scale_bits))) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((opcode == NPU_VECTOR_ADD ||
         opcode == NPU_VECTOR_SUB ||
         opcode == NPU_VECTOR_MAX ||
         opcode == NPU_VECTOR_MIN ||
         opcode == NPU_VECTOR_CMP ||
         opcode == NPU_VECTOR_SELECT) &&
        (desc->src0_scale_bits != desc->src1_scale_bits ||
         (opcode != NPU_VECTOR_CMP &&
          desc->src0_scale_bits != desc->dst_scale_bits))) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((opcode == NPU_VECTOR_CLAMP ||
         opcode == NPU_VECTOR_RELU) &&
        desc->src0_scale_bits != desc->dst_scale_bits) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->dst.dtype == NPU_DTYPE_INT4 &&
        desc->dst.start_nibble != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->dst.dtype == NPU_DTYPE_INT4) {
        if (desc->dst.elem_stride_bytes != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        row_span = ((uint64_t)desc->length + 1u) / 2u;
    } else {
        dst_bytes = npu_dtype_bytes(desc->dst.dtype);
        stride = desc->dst.elem_stride_bytes != 0u
                     ? desc->dst.elem_stride_bytes
                     : dst_bytes;
        if (stride < dst_bytes) {
            return NPU_STATUS_BAD_SHAPE;
        }
        if (desc->length == 0u) {
            row_span = 0u;
        } else {
            row_span = (uint64_t)(desc->length - 1u) * stride +
                       dst_bytes;
        }
        dst_alignment =
            desc->dst.dtype == NPU_DTYPE_INT32
                ? 4u
                : (desc->dst.dtype == NPU_DTYPE_INT16 ? 2u : 1u);
        if (dst_alignment > 1u &&
            ((desc->dst.addr & (dst_alignment - 1u)) != 0u ||
             (stride & (dst_alignment - 1u)) != 0u ||
             (desc->rows > 1u &&
              (desc->dst.row_stride_bytes &
               (dst_alignment - 1u)) != 0u))) {
            return NPU_STATUS_BAD_SHAPE;
        }
    }
    if (desc->rows > 1u &&
        desc->dst.row_stride_bytes < row_span) {
        return NPU_STATUS_BAD_SHAPE;
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_vector_read_inputs(const npu_model_t *model,
                                           uint8_t opcode,
                                           const npu_vector_desc_t *desc,
                                           uint32_t row,
                                           uint32_t element,
                                           int32_t *src0,
                                           int32_t *src1,
                                           int32_t *src2)
{
    npu_status_t status;

    status = npu_vector_read_operand(model, &desc->src0,
                                     desc->broadcast0, row, element, src0);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    *src1 = 0;
    *src2 = 0;
    if (npu_vector_uses_src1(opcode)) {
        if (desc->src1_from_scalar0 != 0u) {
            *src1 = desc->scalar0;
        } else {
            status = npu_vector_read_operand(model, &desc->src1,
                                             desc->broadcast1, row,
                                             element, src1);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
        }
    }
    if (opcode == NPU_VECTOR_FMA) {
        if (desc->src2_from_scalar1 != 0u) {
            *src2 = desc->scalar1;
        } else {
            status = npu_vector_read_operand(model, &desc->src2,
                                             desc->broadcast2, row,
                                             element, src2);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
        }
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_vector_compute(uint8_t opcode,
                                       const npu_vector_desc_t *desc,
                                       int32_t src0,
                                       int32_t src1,
                                       int32_t src2,
                                       int64_t *value)
{
    if (opcode == NPU_VECTOR_ADD) {
        *value = (int64_t)src0 + src1;
    } else if (opcode == NPU_VECTOR_SUB) {
        *value = (int64_t)src0 - src1;
    } else if (opcode == NPU_VECTOR_MUL) {
        *value = (int64_t)src0 * src1;
    } else if (opcode == NPU_VECTOR_FMA) {
        *value = (int64_t)src0 * src1 + src2;
    } else if (opcode == NPU_VECTOR_MAX) {
        *value = src0 > src1 ? src0 : src1;
    } else if (opcode == NPU_VECTOR_MIN) {
        *value = src0 < src1 ? src0 : src1;
    } else if (opcode == NPU_VECTOR_CMP) {
        *value = npu_vector_compare(src0, src1,
                                    desc->compare_mode)
                     ? 1
                     : 0;
    } else if (opcode == NPU_VECTOR_SELECT) {
        *value = 0;
    } else if (opcode == NPU_VECTOR_CLAMP) {
        if (desc->clamp_min > desc->clamp_max) {
            return NPU_STATUS_BAD_DESC;
        }
        if (src0 < desc->clamp_min) {
            *value = desc->clamp_min;
        } else if (src0 > desc->clamp_max) {
            *value = desc->clamp_max;
        } else {
            *value = src0;
        }
    } else if (opcode == NPU_VECTOR_RELU) {
        *value = src0 < 0 ? 0 : src0;
    } else {
        return NPU_STATUS_ILLEGAL_OPCODE;
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_vector_preflight(
    const npu_model_t *model,
    uint8_t opcode,
    const npu_vector_desc_t *desc)
{
    uint32_t row;
    uint32_t element;
    uint32_t row_length;
    int32_t src0;
    int32_t src1;
    int32_t src2;
    int32_t value;
    npu_status_t status;

    for (row = 0u; row < desc->rows; row++) {
        row_length = row + 1u == desc->rows
                         ? desc->valid_length
                         : desc->length;
        for (element = 0u; element < row_length; element++) {
            status = npu_vector_read_inputs(model, opcode, desc, row,
                                            element, &src0, &src1,
                                            &src2);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            if (desc->mask_enable != 0u) {
                status = npu_tensor_read(model, &desc->mask, 0u,
                                         row, element, &value);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
            }
            status = npu_tensor_read(model, &desc->dst, 0u,
                                     row, element, &value);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
        }
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_vector_prepare_output(
    const npu_model_t *model,
    uint8_t opcode,
    const npu_vector_desc_t *desc,
    uint32_t row,
    uint32_t element,
    int64_t *value)
{
    int32_t src0;
    int32_t src1;
    int32_t src2;
    int32_t mask = 1;
    int32_t output;
    npu_status_t status;

    status = npu_vector_read_inputs(model, opcode, desc, row,
                                    element, &src0, &src1, &src2);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (desc->mask_enable != 0u) {
        status = npu_tensor_read(model, &desc->mask, 0u,
                                 row, element, &mask);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    if (opcode == NPU_VECTOR_SELECT) {
        *value = mask == 0 ? src0 : src1;
        return NPU_STATUS_SUCCESS;
    }
    if (desc->mask_enable != 0u && mask == 0) {
        if (desc->mask_false_keep_dst != 0u) {
            status = npu_tensor_read(model, &desc->dst, 0u,
                                     row, element, &output);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            *value = output;
        } else {
            *value = 0;
        }
        return NPU_STATUS_SUCCESS;
    }
    return npu_vector_compute(opcode, desc, src0, src1, src2, value);
}

npu_status_t npu_vector_execute(npu_model_t *model,
                                uint8_t opcode,
                                const npu_vector_desc_t *desc,
                                uint64_t *progress)
{
    uint32_t row = 0u;
    uint32_t element = 0u;
    uint32_t row_length;
    uint32_t staged_row[NPU_VECTOR_MAX_BEAT_ELEMENTS];
    uint32_t staged_element[NPU_VECTOR_MAX_BEAT_ELEMENTS];
    int32_t staged_output[NPU_VECTOR_MAX_BEAT_ELEMENTS];
    int64_t staged_value[NPU_VECTOR_MAX_BEAT_ELEMENTS];
    uint32_t staged_count;
    uint32_t index;
    uint64_t address;
    uint64_t beat_address;
    uint64_t candidate_beat;
    uint8_t high_nibble;
    npu_status_t status;

    if (model == (npu_model_t *)0 ||
        desc == (const npu_vector_desc_t *)0 ||
        progress == (uint64_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    *progress = 0u;
    status = npu_vector_validate(opcode, desc);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (desc->rows == 0u || desc->length == 0u) {
        return NPU_STATUS_SUCCESS;
    }
    status = npu_vector_preflight(model, opcode, desc);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }

    while (row < desc->rows) {
        staged_count = 0u;
        beat_address = 0u;
        while (row < desc->rows &&
               staged_count < NPU_VECTOR_MAX_BEAT_ELEMENTS) {
            status = npu_tensor_location(model, &desc->dst, 0u,
                                         row, element, &address,
                                         &high_nibble);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            candidate_beat = address & ~UINT64_C(7);
            if (staged_count != 0u &&
                candidate_beat != beat_address) {
                break;
            }
            if (staged_count == 0u) {
                beat_address = candidate_beat;
            }
            staged_row[staged_count] = row;
            staged_element[staged_count] = element;
            staged_count++;

            row_length = row + 1u == desc->rows
                             ? desc->valid_length
                             : desc->length;
            element++;
            if (element == row_length) {
                row++;
                element = 0u;
            }
        }
        if (staged_count == NPU_VECTOR_MAX_BEAT_ELEMENTS &&
            row < desc->rows) {
            status = npu_tensor_location(model, &desc->dst, 0u,
                                         row, element, &address,
                                         &high_nibble);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            if ((address & ~UINT64_C(7)) == beat_address) {
                return NPU_STATUS_BAD_SHAPE;
            }
        }

        for (index = 0u; index < staged_count; index++) {
            status = npu_vector_prepare_output(
                model, opcode, desc, staged_row[index],
                staged_element[index], &staged_value[index]);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_cast_integer(
                model, staged_value[index], desc->dst.dtype,
                desc->overflow_mode, &staged_output[index]);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
        }
        for (index = 0u; index < staged_count; index++) {
            status = npu_tensor_write(model, &desc->dst, 0u,
                                      staged_row[index],
                                      staged_element[index],
                                      staged_output[index]);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            (*progress)++;
            row_length = staged_row[index] + 1u == desc->rows
                             ? desc->valid_length
                             : desc->length;
            if (staged_element[index] + 1u == row_length) {
                npu_clear_int4_tail(model, &desc->dst, 0u,
                                    staged_row[index], row_length);
            }
        }
    }
    return NPU_STATUS_SUCCESS;
}
