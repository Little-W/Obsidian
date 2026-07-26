#include "npu_internal.h"
#include "npu_engine_data_cycle.h"

#include <limits.h>

typedef union {
    float value;
    uint32_t bits;
} npu_complex_float_bits_t;

typedef struct {
    uint64_t low;
    uint32_t high;
} npu_u96_t;

static void npu_u96_add_u64(npu_u96_t *accumulator, uint64_t value)
{
    uint64_t old_low = accumulator->low;
    accumulator->low += value;
    if (accumulator->low < old_low && accumulator->high != UINT32_MAX) {
        accumulator->high++;
    }
}

static int npu_float_is_finite(float value)
{
    npu_complex_float_bits_t bits;
    bits.value = value;
    return (bits.bits & 0x7f800000u) != 0x7f800000u;
}

static int npu_float_is_nan(float value)
{
    npu_complex_float_bits_t bits;

    bits.value = value;
    return (bits.bits & 0x7f800000u) == 0x7f800000u &&
           (bits.bits & 0x007fffffu) != 0u;
}

static int npu_float_is_infinite(float value)
{
    npu_complex_float_bits_t bits;

    bits.value = value;
    return (bits.bits & 0x7fffffffu) == 0x7f800000u;
}

static float npu_float_maximum_finite(uint32_t sign)
{
    npu_complex_float_bits_t bits;

    bits.bits = (sign & 0x80000000u) | 0x7f7fffffu;
    return bits.value;
}

static float npu_float_saturate_infinity(
    const npu_model_t *model,
    float value)
{
    npu_complex_float_bits_t bits;

    bits.value = value;
    if ((bits.bits & 0x7fffffffu) == 0x7f800000u) {
        npu_engine_data_record_cme_numeric(
            model,
            NPU_ENGINE_DATA_CME_FP_INF |
                NPU_ENGINE_DATA_CME_OUTPUT_RANGE);
        return npu_float_maximum_finite(bits.bits);
    }
    return value;
}

static float npu_fp32_mul_saturating(
    const npu_model_t *model,
    float left,
    float right)
{
    volatile float result = left * right;

    if (npu_float_is_nan(result)) {
        npu_engine_data_record_cme_numeric(
            model, NPU_ENGINE_DATA_CME_FP_NAN);
    }
    return npu_float_saturate_infinity(model, result);
}

static float npu_fp32_add_saturating(
    const npu_model_t *model,
    float left,
    float right)
{
    volatile float result = left + right;

    if (npu_float_is_nan(result)) {
        npu_engine_data_record_cme_numeric(
            model, NPU_ENGINE_DATA_CME_FP_NAN);
    }
    return npu_float_saturate_infinity(model, result);
}

static float npu_fp32_sub_saturating(
    const npu_model_t *model,
    float left,
    float right)
{
    volatile float result = left - right;

    if (npu_float_is_nan(result)) {
        npu_engine_data_record_cme_numeric(
            model, NPU_ENGINE_DATA_CME_FP_NAN);
    }
    return npu_float_saturate_infinity(model, result);
}

static float npu_complex_reciprocal(
    const npu_model_t *model,
    float value)
{
    if (value == 0.0f) {
        npu_engine_data_record_cme_numeric(
            model,
            NPU_ENGINE_DATA_CME_DIVIDE_BY_ZERO |
                NPU_ENGINE_DATA_CME_OUTPUT_RANGE);
    } else if (npu_float_is_nan(value)) {
        npu_engine_data_record_cme_numeric(
            model, NPU_ENGINE_DATA_CME_FP_NAN);
    }
    return npu_reciprocal_approx(value);
}

static float npu_complex_rsqrt(
    const npu_model_t *model,
    float value)
{
    if (value == 0.0f) {
        npu_engine_data_record_cme_numeric(
            model,
            NPU_ENGINE_DATA_CME_DIVIDE_BY_ZERO |
                NPU_ENGINE_DATA_CME_OUTPUT_RANGE);
    } else if (value < 0.0f ||
               npu_float_is_nan(value)) {
        npu_engine_data_record_cme_numeric(
            model, NPU_ENGINE_DATA_CME_FP_NAN);
    }
    return npu_rsqrt_approx(value);
}

static int npu_float_is_positive_finite(float value)
{
    return value > 0.0f && npu_float_is_finite(value);
}

static npu_status_t npu_complex_table_scale(
    const npu_model_t *model,
    uint64_t table_addr,
    uint32_t element,
    float *scale)
{
    npu_complex_float_bits_t bits;
    uint64_t offset = (uint64_t)element * 4u;
    npu_status_t status;

    if (UINT64_MAX - table_addr < offset) {
        return NPU_STATUS_ADDR_FAULT;
    }
    status = npu_memory_read_u32(model, NPU_SPACE_L1,
                                 table_addr + offset, &bits.bits);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (!npu_float_is_positive_finite(bits.value)) {
        return NPU_STATUS_BAD_DESC;
    }
    *scale = bits.value;
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_complex_src0_scale(
    const npu_model_t *model,
    const npu_complex_desc_t *desc,
    uint32_t element,
    float *scale)
{
    if (desc->scale_mode == NPU_SCALE_PER_FEATURE) {
        return npu_complex_table_scale(model,
                                       desc->src0_scale_table_addr,
                                       element, scale);
    }
    *scale = desc->src0_scale;
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_complex_dst_scale(
    const npu_model_t *model,
    const npu_complex_desc_t *desc,
    uint32_t element,
    float *scale)
{
    if (desc->scale_mode == NPU_SCALE_PER_FEATURE) {
        return npu_complex_table_scale(model,
                                       desc->dst_scale_table_addr,
                                       element, scale);
    }
    *scale = desc->dst_scale;
    return NPU_STATUS_SUCCESS;
}

static uint32_t npu_complex_row_length(const npu_complex_desc_t *desc,
                                       uint32_t row)
{
    if (row + 1u == desc->rows) {
        return desc->valid_length;
    }
    return desc->length;
}

static npu_status_t npu_complex_i2f(const npu_model_t *model,
                                    const npu_tensor_t *tensor,
                                    uint32_t row,
                                    uint32_t element,
                                    float scale,
                                    int32_t zero_point,
                                    float *value)
{
    int32_t integer;
    npu_status_t status =
        npu_tensor_read(model, tensor, 0u, row, element, &integer);

    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    *value = npu_fp32_mul_saturating(
        model,
        (float)((int64_t)integer - (int64_t)zero_point),
        scale);
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_complex_f2i(npu_model_t *model,
                                    const npu_tensor_t *tensor,
                                    uint32_t row,
                                    uint32_t element,
                                    float value,
                                    float scale,
                                    int32_t zero_point,
                                    npu_round_mode_t round_mode,
                                    npu_overflow_mode_t overflow_mode,
                                    uint8_t strict_numeric)
{
    float scaled;
    int32_t rounded;
    int64_t with_zero_point;
    int32_t output;
    npu_status_t status;

    if (npu_float_is_nan(value)) {
        npu_engine_data_record_cme_numeric(
            model, NPU_ENGINE_DATA_CME_FP_NAN);
        if (strict_numeric != 0u) {
            return NPU_STATUS_NUMERIC_EXCEPTION;
        }
        value = 0.0f;
    } else {
        value = npu_float_saturate_infinity(model, value);
    }
    scaled = npu_fp32_mul_saturating(
        model, value,
        npu_complex_reciprocal(model, scale));
    if (npu_float_is_nan(scaled)) {
        npu_engine_data_record_cme_numeric(
            model, NPU_ENGINE_DATA_CME_FP_NAN);
        if (strict_numeric != 0u) {
            return NPU_STATUS_NUMERIC_EXCEPTION;
        }
        scaled = 0.0f;
    }
    if (tensor->dtype == NPU_DTYPE_INT32 &&
        (scaled >= 2147483648.0f || scaled < -2147483648.0f)) {
        npu_engine_data_record_integer_range(
            model, NPU_DTYPE_INT32);
        if (overflow_mode == NPU_OVERFLOW_ERROR) {
            return NPU_STATUS_NUMERIC_EXCEPTION;
        }
    }
    rounded = npu_float_to_int(scaled, round_mode);
    with_zero_point = (int64_t)rounded + zero_point;
    status = npu_cast_integer(model, with_zero_point, tensor->dtype,
                              overflow_mode, &output);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    return npu_tensor_write(model, tensor, 0u, row, element, output);
}

static int npu_complex_opcode_matches(uint8_t opcode,
                                      npu_function_t function)
{
    if (opcode == NPU_COMPLEX_ACT) {
        return function == NPU_FUNC_SIGMOID ||
               function == NPU_FUNC_TANH ||
               function == NPU_FUNC_GELU ||
               function == NPU_FUNC_SILU;
    }
    if (opcode == NPU_COMPLEX_SOFTMAX) {
        return function == NPU_FUNC_SOFTMAX;
    }
    if (opcode == NPU_COMPLEX_NORM) {
        return function == NPU_FUNC_LAYERNORM ||
               function == NPU_FUNC_RMSNORM;
    }
    if (opcode == NPU_COMPLEX_STAT) {
        return function == NPU_FUNC_STAT_SUM ||
               function == NPU_FUNC_STAT_MAX ||
               function == NPU_FUNC_STAT_SUMSQ;
    }
    if (opcode == NPU_COMPLEX_ADD_RESCALE) {
        return function == NPU_FUNC_ADD_RESCALE;
    }
    return 0;
}

static npu_status_t npu_complex_validate(const npu_model_t *model,
                                         uint8_t opcode,
                                         const npu_complex_desc_t *desc)
{
    uint32_t element;
    uint64_t table_bytes;
    float table_scale;

    if (!npu_complex_opcode_matches(opcode, desc->function)) {
        if (opcode == NPU_COMPLEX_ROPE ||
            opcode == NPU_COMPLEX_RECIP) {
            return NPU_STATUS_ILLEGAL_OPCODE;
        }
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->round_mode > NPU_ROUND_TO_NEG_INF ||
        desc->overflow_mode > NPU_OVERFLOW_WRAP ||
        desc->scale_mode > NPU_SCALE_PER_FEATURE ||
        desc->mask_mode > NPU_MASK_VALID_LENGTH ||
        desc->all_mask_mode > NPU_ALL_MASK_ERROR ||
        desc->approx_mode != 0u ||
        desc->stats_mode > 1u ||
        desc->strict_numeric > 1u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->stats_mode != 0u &&
        desc->function != NPU_FUNC_LAYERNORM) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->valid_length > desc->length ||
        (desc->rows == 0u && desc->valid_length != 0u) ||
        (desc->rows > 0u && desc->length > 0u &&
         desc->valid_length == 0u)) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (desc->length > NPU_REF_CME_MAX_LENGTH) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (desc->rows > 0u && desc->length == 0u &&
        (desc->function == NPU_FUNC_SOFTMAX ||
         desc->function == NPU_FUNC_LAYERNORM ||
         desc->function == NPU_FUNC_RMSNORM ||
         desc->function == NPU_FUNC_STAT_SUM ||
         desc->function == NPU_FUNC_STAT_MAX ||
         desc->function == NPU_FUNC_STAT_SUMSQ)) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (desc->src0.space != NPU_SPACE_L1 ||
        desc->dst.space != NPU_SPACE_L1 ||
        !npu_dtype_valid(desc->src0.dtype) ||
        !npu_dtype_valid(desc->dst.dtype)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->dst.dtype == NPU_DTYPE_INT4 &&
        desc->dst.start_nibble != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((desc->src0.dtype == NPU_DTYPE_INT4 &&
         desc->src0.start_nibble != 0u) ||
        (desc->src1.dtype == NPU_DTYPE_INT4 &&
         desc->src1.start_nibble != 0u) ||
        (desc->src2.dtype == NPU_DTYPE_INT4 &&
         desc->src2.start_nibble != 0u) ||
        desc->src0_zero_point != 0 ||
        desc->src1_zero_point != 0 ||
        desc->src2_zero_point != 0 ||
        desc->dst_zero_point != 0) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->scratch_request_elems >
        model->config.cme_scratch_elems) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((desc->function == NPU_FUNC_SIGMOID ||
         desc->function == NPU_FUNC_TANH ||
         desc->function == NPU_FUNC_GELU ||
         desc->function == NPU_FUNC_SILU ||
         desc->function == NPU_FUNC_ADD_RESCALE ||
         desc->function == NPU_FUNC_STAT_SUM ||
         desc->function == NPU_FUNC_STAT_MAX ||
         desc->function == NPU_FUNC_STAT_SUMSQ) &&
        desc->scratch_request_elems != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->function != NPU_FUNC_STAT_SUM &&
        desc->function != NPU_FUNC_STAT_MAX &&
        desc->function != NPU_FUNC_STAT_SUMSQ) {
        if (desc->overflow_mode != NPU_OVERFLOW_SATURATE) {
            return NPU_STATUS_BAD_DESC;
        }
        if (desc->scale_mode == NPU_SCALE_PER_TENSOR) {
            if (!npu_float_is_finite_positive(desc->src0_scale) ||
                !npu_float_is_finite_positive(desc->dst_scale) ||
                desc->src0_scale_table_addr != 0u ||
                desc->dst_scale_table_addr != 0u) {
                return NPU_STATUS_BAD_DESC;
            }
        } else if (desc->scale_mode == NPU_SCALE_PER_FEATURE) {
            if (!(desc->function == NPU_FUNC_SIGMOID ||
                  desc->function == NPU_FUNC_TANH ||
                  desc->function == NPU_FUNC_GELU ||
                  desc->function == NPU_FUNC_SILU ||
                  desc->function == NPU_FUNC_LAYERNORM ||
                  desc->function == NPU_FUNC_RMSNORM ||
                  desc->function == NPU_FUNC_ADD_RESCALE) ||
                desc->src0_scale != 0.0f ||
                desc->dst_scale != 0.0f ||
                (desc->src0_scale_table_addr & 3u) != 0u ||
                (desc->dst_scale_table_addr & 3u) != 0u) {
                return NPU_STATUS_BAD_DESC;
            }
            table_bytes = (uint64_t)desc->length * 4u;
            if (!npu_memory_range_valid(model, NPU_SPACE_L1,
                                        desc->src0_scale_table_addr,
                                        table_bytes) ||
                !npu_memory_range_valid(model, NPU_SPACE_L1,
                                        desc->dst_scale_table_addr,
                                        table_bytes)) {
                return NPU_STATUS_ADDR_FAULT;
            }
            for (element = 0u; element < desc->length; element++) {
                if (npu_complex_table_scale(
                        model, desc->src0_scale_table_addr,
                        element, &table_scale) != NPU_STATUS_SUCCESS ||
                    npu_complex_table_scale(
                        model, desc->dst_scale_table_addr,
                        element, &table_scale) != NPU_STATUS_SUCCESS) {
                    return NPU_STATUS_BAD_DESC;
                }
            }
        } else {
            return NPU_STATUS_BAD_DESC;
        }
    }
    if (desc->function == NPU_FUNC_ADD_RESCALE) {
        if (desc->src1.space != NPU_SPACE_L1 ||
            !npu_dtype_valid(desc->src1.dtype) ||
            !npu_float_is_finite_positive(desc->src1_scale)) {
            return NPU_STATUS_BAD_DESC;
        }
    }
    if (desc->function == NPU_FUNC_LAYERNORM ||
        desc->function == NPU_FUNC_RMSNORM) {
        if (desc->src1.space != NPU_SPACE_L1 ||
            !npu_dtype_valid(desc->src1.dtype) ||
            !npu_float_is_finite_positive(desc->src1_scale) ||
            !npu_float_is_finite_positive(desc->epsilon)) {
            return NPU_STATUS_BAD_DESC;
        }
        if (desc->function == NPU_FUNC_LAYERNORM &&
            (desc->beta_enable == 0u ||
             desc->src2.space != NPU_SPACE_L1 ||
             !npu_dtype_valid(desc->src2.dtype) ||
             !npu_float_is_finite_positive(desc->src2_scale))) {
            return NPU_STATUS_BAD_DESC;
        }
        if (desc->function == NPU_FUNC_RMSNORM &&
            (desc->beta_enable != 0u ||
             desc->src2.addr != 0u ||
             desc->src2_scale != 0.0f ||
             desc->src2_zero_point != 0)) {
            return NPU_STATUS_BAD_DESC;
        }
    }
    if (desc->function == NPU_FUNC_STAT_SUM ||
        desc->function == NPU_FUNC_STAT_MAX ||
        desc->function == NPU_FUNC_STAT_SUMSQ) {
        if (desc->scale_mode != NPU_SCALE_NONE ||
            desc->src0_scale != 0.0f ||
            desc->src1_scale != 0.0f ||
            desc->src2_scale != 0.0f ||
            desc->dst_scale != 0.0f ||
            desc->src0_scale_table_addr != 0u ||
            desc->dst_scale_table_addr != 0u ||
            desc->epsilon != 0.0f ||
            desc->input_clip_min != 0.0f ||
            desc->input_clip_max != 0.0f ||
            desc->mask_mode != NPU_MASK_NONE ||
            desc->dst.dtype != NPU_DTYPE_INT32) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (desc->function == NPU_FUNC_LAYERNORM ||
               desc->function == NPU_FUNC_RMSNORM) {
        if (desc->input_clip_min != 0.0f ||
            desc->input_clip_max != 0.0f ||
            desc->mask_mode != NPU_MASK_NONE) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (desc->function == NPU_FUNC_ADD_RESCALE) {
        if (desc->epsilon != 0.0f ||
            desc->input_clip_min != 0.0f ||
            desc->input_clip_max != 0.0f ||
            desc->mask_mode != NPU_MASK_NONE) {
            return NPU_STATUS_BAD_DESC;
        }
    } else {
        if (desc->epsilon != 0.0f ||
            !npu_float_is_finite(desc->input_clip_min) ||
            !npu_float_is_finite(desc->input_clip_max) ||
            !(desc->input_clip_min < desc->input_clip_max)) {
            return NPU_STATUS_BAD_DESC;
        }
    }
    if (desc->function != NPU_FUNC_SOFTMAX &&
        desc->all_mask_mode != NPU_ALL_MASK_WRITE_ZERO) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->mask_mode == NPU_MASK_BOOLEAN &&
        (desc->mask.space != NPU_SPACE_L1 ||
         desc->mask.dtype != NPU_DTYPE_INT8)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->mask_mode == NPU_MASK_VALID_LENGTH &&
        (desc->valid_lengths.space != NPU_SPACE_L1 ||
         desc->valid_lengths.dtype != NPU_DTYPE_INT32)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->mask_mode == NPU_MASK_CAUSAL) {
        return NPU_STATUS_ILLEGAL_OPCODE;
    }
    return NPU_STATUS_SUCCESS;
}

static float npu_complex_activation(npu_function_t function, float x)
{
    if (function == NPU_FUNC_SIGMOID) {
        return npu_sigmoid_approx(x);
    }
    if (function == NPU_FUNC_TANH) {
        return npu_tanh_approx(x);
    }
    if (function == NPU_FUNC_GELU) {
        return npu_gelu_approx(x);
    }
    return npu_silu_approx(x);
}

static npu_status_t npu_complex_activation_rows(
    npu_model_t *model,
    const npu_complex_desc_t *desc,
    uint64_t *progress)
{
    uint32_t row;
    uint32_t element;
    uint32_t row_length;
    float x;
    float y;
    float src_scale;
    float dst_scale;
    npu_status_t status;

    for (row = 0u; row < desc->rows; row++) {
        row_length = npu_complex_row_length(desc, row);
        for (element = 0u; element < row_length; element++) {
            status = npu_complex_src0_scale(model, desc, element,
                                            &src_scale);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_complex_dst_scale(model, desc, element,
                                           &dst_scale);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_complex_i2f(model, &desc->src0, row, element,
                                     src_scale,
                                     desc->src0_zero_point, &x);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            if (x < desc->input_clip_min) {
                npu_engine_data_record_cme_numeric(
                    model,
                    NPU_ENGINE_DATA_CME_OUTPUT_RANGE);
                x = desc->input_clip_min;
            } else if (x > desc->input_clip_max) {
                npu_engine_data_record_cme_numeric(
                    model,
                    NPU_ENGINE_DATA_CME_OUTPUT_RANGE);
                x = desc->input_clip_max;
            }
            y = npu_complex_activation(desc->function, x);
            if (npu_float_is_nan(y)) {
                npu_engine_data_record_cme_numeric(
                    model, NPU_ENGINE_DATA_CME_FP_NAN);
            } else if (npu_float_is_infinite(y)) {
                npu_engine_data_record_cme_numeric(
                    model,
                    NPU_ENGINE_DATA_CME_FP_INF |
                        NPU_ENGINE_DATA_CME_OUTPUT_RANGE);
            }
            status = npu_complex_f2i(model, &desc->dst, row, element,
                                     y, dst_scale,
                                     desc->dst_zero_point,
                                     desc->round_mode,
                                     desc->overflow_mode,
                                     desc->strict_numeric);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            (*progress)++;
        }
        npu_clear_int4_tail(model, &desc->dst, 0u, row, row_length);
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_complex_mask_valid(const npu_model_t *model,
                                           const npu_complex_desc_t *desc,
                                           uint32_t row,
                                           uint32_t element,
                                           int *valid)
{
    int32_t mask;
    int32_t valid_length;
    npu_status_t status;

    if (desc->mask_mode == NPU_MASK_NONE) {
        *valid = 1;
        return NPU_STATUS_SUCCESS;
    }
    if (desc->mask_mode == NPU_MASK_BOOLEAN) {
        status = npu_tensor_read(model, &desc->mask, 0u,
                                 row, element, &mask);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        *valid = mask != 0;
        return NPU_STATUS_SUCCESS;
    }
    if (desc->mask_mode == NPU_MASK_VALID_LENGTH) {
        status = npu_tensor_read(model, &desc->valid_lengths, 0u,
                                 row, 0u, &valid_length);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        if (valid_length < 0 ||
            (uint32_t)valid_length > npu_complex_row_length(desc, row)) {
            return NPU_STATUS_BAD_SHAPE;
        }
        *valid = element < (uint32_t)valid_length;
        return NPU_STATUS_SUCCESS;
    }
    return NPU_STATUS_ILLEGAL_OPCODE;
}

static npu_status_t npu_complex_write_masked_zero(
    npu_model_t *model,
    const npu_complex_desc_t *desc,
    uint32_t row,
    uint32_t length,
    uint64_t *progress)
{
    uint32_t element;
    int32_t output;
    npu_status_t status;

    status = npu_cast_integer(model, desc->dst_zero_point,
                              desc->dst.dtype,
                              desc->overflow_mode, &output);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    for (element = 0u; element < length; element++) {
        status = npu_tensor_write(model, &desc->dst, 0u,
                                  row, element, output);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        (*progress)++;
    }
    npu_clear_int4_tail(model, &desc->dst, 0u, row, length);
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_complex_softmax(npu_model_t *model,
                                        const npu_complex_desc_t *desc,
                                        uint64_t *progress)
{
    uint32_t row;
    uint32_t element;
    uint32_t row_length;
    float x;
    float maximum;
    float difference;
    float exponential;
    float sum;
    float lane_sum[NPU_REF_CME_LANES];
    float inverse;
    int valid;
    int any_valid;
    int32_t zero_output;
    npu_status_t status;
    uint32_t lane;

    status = npu_cast_integer(model, desc->dst_zero_point,
                              desc->dst.dtype,
                              desc->overflow_mode, &zero_output);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }

    for (row = 0u; row < desc->rows; row++) {
        if (row != 0u &&
            !npu_model_trace_next_read_pass(model)) {
            return NPU_STATUS_BUS_SLVERR;
        }
        row_length = npu_complex_row_length(desc, row);
        if (row_length == 0u) {
            continue;
        }

        any_valid = 0;
        maximum = 0.0f;
        for (element = 0u; element < row_length; element++) {
            status = npu_complex_mask_valid(model, desc, row,
                                            element, &valid);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            if (!valid) {
                continue;
            }
            status = npu_complex_i2f(model, &desc->src0, row, element,
                                     desc->src0_scale,
                                     desc->src0_zero_point, &x);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            if (!any_valid || x > maximum) {
                maximum = x;
            }
            any_valid = 1;
        }

        if (!any_valid) {
            model->perf.all_mask_row_count++;
            npu_engine_data_record_cme_numeric(
                model, NPU_ENGINE_DATA_CME_ALL_MASK);
            if (desc->all_mask_mode == NPU_ALL_MASK_ERROR) {
                return NPU_STATUS_NUMERIC_EXCEPTION;
            }
            status = npu_complex_write_masked_zero(model, desc, row,
                                                   row_length, progress);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            continue;
        }

        if (!npu_model_trace_next_read_pass(model)) {
            return NPU_STATUS_BUS_SLVERR;
        }
        for (lane = 0u; lane < NPU_REF_CME_LANES; lane++) {
            lane_sum[lane] = 0.0f;
        }
        for (element = 0u; element < row_length; element++) {
            status = npu_complex_mask_valid(model, desc, row,
                                            element, &valid);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            if (!valid) {
                continue;
            }
            status = npu_complex_i2f(model, &desc->src0, row, element,
                                     desc->src0_scale,
                                     desc->src0_zero_point, &x);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            difference = npu_fp32_sub_saturating(
                model, x, maximum);
            if (difference < desc->input_clip_min) {
                npu_engine_data_record_cme_numeric(
                    model,
                    NPU_ENGINE_DATA_CME_OUTPUT_RANGE);
                difference = desc->input_clip_min;
            }
            if (difference > 0.0f) {
                npu_engine_data_record_cme_numeric(
                    model,
                    NPU_ENGINE_DATA_CME_OUTPUT_RANGE);
                difference = 0.0f;
            }
            lane = element & (NPU_REF_CME_LANES - 1u);
            lane_sum[lane] = npu_fp32_add_saturating(
                model, lane_sum[lane],
                npu_exp_approx(difference));
        }
        sum = npu_fp32_add_saturating(
            model,
            npu_fp32_add_saturating(
                model, lane_sum[0], lane_sum[1]),
            npu_fp32_add_saturating(
                model, lane_sum[2], lane_sum[3]));
        inverse = npu_complex_reciprocal(model, sum);

        if (!npu_model_trace_next_read_pass(model)) {
            return NPU_STATUS_BUS_SLVERR;
        }
        for (element = 0u; element < row_length; element++) {
            status = npu_complex_mask_valid(model, desc, row,
                                            element, &valid);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            if (!valid) {
                status = npu_tensor_write(model, &desc->dst, 0u,
                                          row, element, zero_output);
            } else {
                status = npu_complex_i2f(model, &desc->src0, row,
                                         element, desc->src0_scale,
                                         desc->src0_zero_point, &x);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                difference = npu_fp32_sub_saturating(
                    model, x, maximum);
                if (difference < desc->input_clip_min) {
                    npu_engine_data_record_cme_numeric(
                        model,
                        NPU_ENGINE_DATA_CME_OUTPUT_RANGE);
                    difference = desc->input_clip_min;
                }
                exponential = npu_exp_approx(difference);
                status = npu_complex_f2i(model, &desc->dst, row,
                                         element,
                                         npu_fp32_mul_saturating(
                                             model, exponential,
                                             inverse),
                                         desc->dst_scale,
                                         desc->dst_zero_point,
                                         desc->round_mode,
                                         desc->overflow_mode,
                                         desc->strict_numeric);
            }
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            (*progress)++;
        }
        npu_clear_int4_tail(model, &desc->dst, 0u, row, row_length);
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_complex_norm(npu_model_t *model,
                                     const npu_complex_desc_t *desc,
                                     uint64_t *progress)
{
    uint32_t row;
    uint32_t element;
    uint32_t row_length;
    float x;
    float gamma;
    float beta;
    float mean = 0.0f;
    float sum;
    float square_sum;
    float lane_sum[NPU_REF_CME_LANES];
    float variance;
    float inverse = 0.0f;
    float normalized;
    float src_scale;
    float dst_scale;
    float delta;
    npu_status_t status;
    uint32_t lane;

    for (row = 0u; row < desc->rows; row++) {
        if (row != 0u &&
            !npu_model_trace_next_read_pass(model)) {
            return NPU_STATUS_BUS_SLVERR;
        }
        row_length = npu_complex_row_length(desc, row);
        if (row_length == 0u) {
            return NPU_STATUS_BAD_SHAPE;
        }
        if (desc->function == NPU_FUNC_LAYERNORM &&
            desc->stats_mode == 1u) {
            mean = 0.0f;
            square_sum = 0.0f;
            for (element = 0u; element < row_length; element++) {
                status = npu_complex_src0_scale(model, desc, element,
                                                &src_scale);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                status = npu_complex_i2f(model, &desc->src0,
                                         row, element, src_scale,
                                         desc->src0_zero_point, &x);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                delta = npu_fp32_sub_saturating(
                    model, x, mean);
                mean = npu_fp32_add_saturating(
                    model, mean,
                    npu_fp32_mul_saturating(
                        model, delta,
                        npu_complex_reciprocal(
                            model,
                            (float)(element + 1u))));
                square_sum = npu_fp32_add_saturating(
                    model, square_sum,
                    npu_fp32_mul_saturating(
                        model, delta,
                        npu_fp32_sub_saturating(
                            model, x, mean)));
            }
            variance = npu_fp32_mul_saturating(
                model, square_sum,
                npu_complex_reciprocal(
                    model, (float)row_length));
            if (variance < 0.0f) {
                variance = 0.0f;
            }
            inverse = npu_complex_rsqrt(
                model,
                npu_fp32_add_saturating(
                    model, variance, desc->epsilon));
        } else {
            for (lane = 0u; lane < NPU_REF_CME_LANES; lane++) {
                lane_sum[lane] = 0.0f;
            }
            for (element = 0u; element < row_length; element++) {
                status = npu_complex_src0_scale(model, desc, element,
                                                &src_scale);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                status = npu_complex_i2f(model, &desc->src0,
                                         row, element, src_scale,
                                         desc->src0_zero_point, &x);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                lane = element & (NPU_REF_CME_LANES - 1u);
                if (desc->function == NPU_FUNC_LAYERNORM) {
                    lane_sum[lane] = npu_fp32_add_saturating(
                        model, lane_sum[lane], x);
                } else {
                    lane_sum[lane] = npu_fp32_add_saturating(
                        model, lane_sum[lane],
                        npu_fp32_mul_saturating(
                            model, x, x));
                }
            }
        }

        if (desc->function == NPU_FUNC_LAYERNORM &&
            desc->stats_mode == 0u) {
            sum = npu_fp32_add_saturating(
                model,
                npu_fp32_add_saturating(
                    model, lane_sum[0], lane_sum[1]),
                npu_fp32_add_saturating(
                    model, lane_sum[2], lane_sum[3]));
            mean = npu_fp32_mul_saturating(
                model, sum,
                npu_complex_reciprocal(
                    model, (float)row_length));
            if (!npu_model_trace_next_read_pass(model)) {
                return NPU_STATUS_BUS_SLVERR;
            }
            for (lane = 0u; lane < NPU_REF_CME_LANES; lane++) {
                lane_sum[lane] = 0.0f;
            }
            for (element = 0u; element < row_length; element++) {
                status = npu_complex_src0_scale(model, desc, element,
                                                &src_scale);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                status = npu_complex_i2f(model, &desc->src0,
                                         row, element,
                                         src_scale,
                                         desc->src0_zero_point, &x);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                lane = element & (NPU_REF_CME_LANES - 1u);
                delta = npu_fp32_sub_saturating(
                    model, x, mean);
                lane_sum[lane] = npu_fp32_add_saturating(
                    model, lane_sum[lane],
                    npu_fp32_mul_saturating(
                        model, delta, delta));
            }
            square_sum = npu_fp32_add_saturating(
                model,
                npu_fp32_add_saturating(
                    model, lane_sum[0], lane_sum[1]),
                npu_fp32_add_saturating(
                    model, lane_sum[2], lane_sum[3]));
            variance = npu_fp32_mul_saturating(
                model, square_sum,
                npu_complex_reciprocal(
                    model, (float)row_length));
            if (variance < 0.0f) {
                variance = 0.0f;
            }
            inverse = npu_complex_rsqrt(
                model,
                npu_fp32_add_saturating(
                    model, variance, desc->epsilon));
        } else if (desc->function == NPU_FUNC_RMSNORM) {
            mean = 0.0f;
            square_sum = npu_fp32_add_saturating(
                model,
                npu_fp32_add_saturating(
                    model, lane_sum[0], lane_sum[1]),
                npu_fp32_add_saturating(
                    model, lane_sum[2], lane_sum[3]));
            inverse = npu_complex_rsqrt(
                model,
                npu_fp32_add_saturating(
                    model,
                    npu_fp32_mul_saturating(
                        model, square_sum,
                        npu_complex_reciprocal(
                            model,
                            (float)row_length)),
                    desc->epsilon));
        }

        if (!npu_model_trace_next_read_pass(model)) {
            return NPU_STATUS_BUS_SLVERR;
        }
        for (element = 0u; element < row_length; element++) {
            status = npu_complex_src0_scale(model, desc, element,
                                            &src_scale);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_complex_dst_scale(model, desc, element,
                                           &dst_scale);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_complex_i2f(model, &desc->src0, row, element,
                                     src_scale,
                                     desc->src0_zero_point, &x);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_complex_i2f(model, &desc->src1, 0u, element,
                                     desc->src1_scale,
                                     desc->src1_zero_point, &gamma);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            beta = 0.0f;
            if (desc->function == NPU_FUNC_LAYERNORM) {
                status = npu_complex_i2f(model, &desc->src2, 0u,
                                         element, desc->src2_scale,
                                         desc->src2_zero_point, &beta);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
            }
            normalized = npu_fp32_add_saturating(
                model,
                npu_fp32_mul_saturating(
                    model,
                    npu_fp32_mul_saturating(
                        model, gamma,
                        npu_fp32_sub_saturating(
                            model, x, mean)),
                    inverse),
                beta);
            status = npu_complex_f2i(model, &desc->dst, row, element,
                                     normalized, dst_scale,
                                     desc->dst_zero_point,
                                     desc->round_mode,
                                     desc->overflow_mode,
                                     desc->strict_numeric);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            (*progress)++;
        }
        npu_clear_int4_tail(model, &desc->dst, 0u, row, row_length);
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_complex_add_rescale(npu_model_t *model,
                                            const npu_complex_desc_t *desc,
                                            uint64_t *progress)
{
    uint32_t row;
    uint32_t element;
    uint32_t row_length;
    float x0;
    float x1;
    float src0_scale;
    float dst_scale;
    npu_status_t status;

    for (row = 0u; row < desc->rows; row++) {
        row_length = npu_complex_row_length(desc, row);
        for (element = 0u; element < row_length; element++) {
            status = npu_complex_src0_scale(model, desc, element,
                                            &src0_scale);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_complex_dst_scale(model, desc, element,
                                           &dst_scale);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_complex_i2f(model, &desc->src0, row, element,
                                     src0_scale,
                                     desc->src0_zero_point, &x0);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_complex_i2f(model, &desc->src1, row, element,
                                     desc->src1_scale,
                                     desc->src1_zero_point, &x1);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            status = npu_complex_f2i(model, &desc->dst, row, element,
                                     npu_fp32_add_saturating(
                                         model, x0, x1),
                                     dst_scale,
                                     desc->dst_zero_point,
                                     desc->round_mode,
                                     desc->overflow_mode,
                                     desc->strict_numeric);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            (*progress)++;
        }
        npu_clear_int4_tail(model, &desc->dst, 0u, row, row_length);
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_complex_stat(npu_model_t *model,
                                     const npu_complex_desc_t *desc,
                                     uint64_t *progress)
{
    uint32_t row;
    uint32_t element;
    uint32_t row_length;
    int32_t input;
    int32_t maximum;
    int32_t output;
    int64_t accumulator;
    int64_t term;
    npu_u96_t square_accumulator;
    npu_status_t status;

    for (row = 0u; row < desc->rows; row++) {
        row_length = npu_complex_row_length(desc, row);
        if (row_length == 0u) {
            return NPU_STATUS_BAD_SHAPE;
        }
        accumulator = 0;
        square_accumulator.low = 0u;
        square_accumulator.high = 0u;
        maximum = INT32_MIN;
        for (element = 0u; element < row_length; element++) {
            status = npu_tensor_read(model, &desc->src0, 0u,
                                     row, element, &input);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            if (desc->function == NPU_FUNC_STAT_MAX) {
                if (input > maximum) {
                    maximum = input;
                }
            } else if (desc->function == NPU_FUNC_STAT_SUMSQ) {
                term = (int64_t)input * input;
                npu_u96_add_u64(&square_accumulator,
                                (uint64_t)term);
            } else {
                term = input;
                if (term > 0 && accumulator > INT64_MAX - term) {
                    accumulator = INT64_MAX;
                } else if (term < 0 &&
                           accumulator < INT64_MIN - term) {
                    accumulator = INT64_MIN;
                } else {
                    accumulator += term;
                }
            }
        }
        if (desc->function == NPU_FUNC_STAT_MAX) {
            accumulator = maximum;
        }
        if (desc->function == NPU_FUNC_STAT_SUMSQ &&
            (square_accumulator.high != 0u ||
             square_accumulator.low > (uint64_t)INT32_MAX)) {
            npu_engine_data_record_integer_range(
                model, NPU_DTYPE_INT32);
            if (desc->overflow_mode == NPU_OVERFLOW_ERROR) {
                return NPU_STATUS_NUMERIC_EXCEPTION;
            }
            if (desc->overflow_mode == NPU_OVERFLOW_WRAP) {
                uint32_t low32 =
                    (uint32_t)square_accumulator.low;
                if (low32 <= 0x7fffffffu) {
                    output = (int32_t)low32;
                } else {
                    output =
                        -1 - (int32_t)(0xffffffffu - low32);
                }
            } else {
                output = INT32_MAX;
                model->perf.int_saturate_count++;
            }
            status = NPU_STATUS_SUCCESS;
        } else {
            if (desc->function == NPU_FUNC_STAT_SUMSQ) {
                accumulator = (int64_t)square_accumulator.low;
            }
            status = npu_cast_integer(model, accumulator,
                                      NPU_DTYPE_INT32,
                                      desc->overflow_mode, &output);
        }
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        status = npu_tensor_write(model, &desc->dst, 0u,
                                  row, 0u, output);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        (*progress)++;
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_complex_preflight(
    const npu_model_t *model,
    const npu_complex_desc_t *desc)
{
    uint32_t row;
    uint32_t element;
    uint32_t row_length;
    int32_t value;
    npu_status_t status;

    for (row = 0u; row < desc->rows; row++) {
        row_length = npu_complex_row_length(desc, row);
        if (desc->mask_mode == NPU_MASK_VALID_LENGTH) {
            status = npu_tensor_read(model, &desc->valid_lengths,
                                     0u, row, 0u, &value);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            if (value < 0 || (uint32_t)value > row_length) {
                return NPU_STATUS_BAD_SHAPE;
            }
        }
        for (element = 0u; element < row_length; element++) {
            status = npu_tensor_read(model, &desc->src0, 0u,
                                     row, element, &value);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            if (desc->function == NPU_FUNC_ADD_RESCALE) {
                status = npu_tensor_read(model, &desc->src1, 0u,
                                         row, element, &value);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
            } else if (desc->function == NPU_FUNC_LAYERNORM ||
                       desc->function == NPU_FUNC_RMSNORM) {
                status = npu_tensor_read(model, &desc->src1, 0u,
                                         0u, element, &value);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                if (desc->function == NPU_FUNC_LAYERNORM) {
                    status = npu_tensor_read(model, &desc->src2, 0u,
                                             0u, element, &value);
                    if (status != NPU_STATUS_SUCCESS) {
                        return status;
                    }
                }
            }
            if (desc->mask_mode == NPU_MASK_BOOLEAN) {
                status = npu_tensor_read(model, &desc->mask, 0u,
                                         row, element, &value);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
            }
            if (desc->function != NPU_FUNC_STAT_SUM &&
                desc->function != NPU_FUNC_STAT_MAX &&
                desc->function != NPU_FUNC_STAT_SUMSQ) {
                status = npu_tensor_read(model, &desc->dst, 0u,
                                         row, element, &value);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
            }
        }
        if (desc->function == NPU_FUNC_STAT_SUM ||
            desc->function == NPU_FUNC_STAT_MAX ||
            desc->function == NPU_FUNC_STAT_SUMSQ) {
            status = npu_tensor_read(model, &desc->dst, 0u,
                                     row, 0u, &value);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
        }
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_complex_trace_valid_lengths(
    const npu_model_t *model,
    const npu_complex_desc_t *desc)
{
    uint32_t row;
    int32_t value;
    npu_status_t status;

    if (model->internal_bus_trace == (void *)0 ||
        desc->mask_mode != NPU_MASK_VALID_LENGTH) {
        return NPU_STATUS_SUCCESS;
    }
    for (row = 0u; row < desc->rows; row++) {
        status = npu_tensor_read(
            model, &desc->valid_lengths, 0u, row, 0u,
            &value);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        if (value < 0 ||
            (uint32_t)value >
                npu_complex_row_length(desc, row)) {
            return NPU_STATUS_BAD_SHAPE;
        }
    }
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_complex_execute(npu_model_t *model,
                                 uint8_t opcode,
                                 const npu_complex_desc_t *desc,
                                 uint64_t *progress)
{
    npu_status_t status;
    uint8_t read_capture;

    if (model == (npu_model_t *)0 ||
        desc == (const npu_complex_desc_t *)0 ||
        progress == (uint64_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    *progress = 0u;
    status = npu_complex_validate(model, opcode, desc);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (desc->rows == 0u) {
        return NPU_STATUS_SUCCESS;
    }
    status = npu_complex_trace_valid_lengths(model, desc);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    read_capture =
        npu_model_trace_set_read_capture(model, 0u);
    status = npu_complex_preflight(model, desc);
    (void)npu_model_trace_set_read_capture(
        model, read_capture);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (desc->function == NPU_FUNC_SIGMOID ||
        desc->function == NPU_FUNC_TANH ||
        desc->function == NPU_FUNC_GELU ||
        desc->function == NPU_FUNC_SILU) {
        return npu_complex_activation_rows(model, desc, progress);
    }
    if (desc->function == NPU_FUNC_SOFTMAX) {
        return npu_complex_softmax(model, desc, progress);
    }
    if (desc->function == NPU_FUNC_LAYERNORM ||
        desc->function == NPU_FUNC_RMSNORM) {
        return npu_complex_norm(model, desc, progress);
    }
    if (desc->function == NPU_FUNC_ADD_RESCALE) {
        return npu_complex_add_rescale(model, desc, progress);
    }
    return npu_complex_stat(model, desc, progress);
}
