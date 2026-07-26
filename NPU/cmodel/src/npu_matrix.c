#include "npu_internal.h"

#include <limits.h>

static npu_status_t npu_matrix_read_b(const npu_model_t *model,
                                      const npu_matrix_desc_t *desc,
                                      uint32_t batch,
                                      uint32_t k,
                                      uint32_t n,
                                      int32_t *value)
{
    uint64_t n_tiles;
    uint64_t k_outer;
    uint64_t n_outer;
    uint64_t k_inner;
    uint64_t n_inner;
    uint64_t linear;
    uint64_t addr;
    uint64_t batch_offset;
    uint64_t element_offset;
    uint8_t byte_value;
    uint8_t byte_high;
    uint16_t raw_value;
    npu_status_t status;

    if (!desc->b_tiled) {
        if (desc->transpose_b != 0u) {
            return npu_tensor_read(model, &desc->b, batch, n, k, value);
        }
        return npu_tensor_read(model, &desc->b, batch, k, n, value);
    }
    if (desc->transpose_b != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    n_tiles = npu_ceil_div_u64(desc->n, model->config.nt);
    k_outer = k / model->config.kt;
    n_outer = n / model->config.nt;
    k_inner = k % model->config.kt;
    n_inner = n % model->config.nt;
    linear = (((k_outer * n_tiles + n_outer) * model->config.kt +
               k_inner) *
              model->config.nt) +
             n_inner;
    batch_offset = (uint64_t)batch * desc->b.batch_stride_bytes;
    if (UINT64_MAX - desc->b.addr < batch_offset) {
        return NPU_STATUS_ADDR_FAULT;
    }
    if (desc->b.dtype == NPU_DTYPE_INT8 ||
        desc->b.dtype == NPU_DTYPE_INT16) {
        if (desc->b.dtype == NPU_DTYPE_INT16 &&
            linear > UINT64_MAX / 2u) {
            return NPU_STATUS_ADDR_FAULT;
        }
        element_offset =
            desc->b.dtype == NPU_DTYPE_INT16 ? linear * 2u : linear;
        if (UINT64_MAX - batch_offset < element_offset) {
            return NPU_STATUS_ADDR_FAULT;
        }
        element_offset += batch_offset;
        if ((desc->b.region_bytes != 0u &&
             (element_offset >= desc->b.region_bytes ||
              (desc->b.dtype == NPU_DTYPE_INT16 &&
               desc->b.region_bytes - element_offset < 2u))) ||
            UINT64_MAX - desc->b.addr < element_offset) {
            return NPU_STATUS_ADDR_FAULT;
        }
        addr = desc->b.addr + element_offset;
        status = npu_memory_read_u8(model, desc->b.space, addr, &byte_value);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        if (desc->b.dtype == NPU_DTYPE_INT16) {
            if (addr == UINT64_MAX) {
                return NPU_STATUS_ADDR_FAULT;
            }
            status = npu_memory_read_u8(model, desc->b.space, addr + 1u,
                                        &byte_high);
            if (status != NPU_STATUS_SUCCESS) {
                return status;
            }
            raw_value = (uint16_t)byte_value |
                        (uint16_t)((uint16_t)byte_high << 8);
            if ((raw_value & 0x8000u) != 0u) {
                *value = -1 - (int32_t)(0xffffu - raw_value);
            } else {
                *value = raw_value;
            }
            return NPU_STATUS_SUCCESS;
        }
        if ((byte_value & 0x80u) != 0u) {
            *value = -1 - (int32_t)(0xffu - byte_value);
        } else {
            *value = byte_value;
        }
        return NPU_STATUS_SUCCESS;
    }
    if (desc->b.dtype != NPU_DTYPE_INT4) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    element_offset = linear / 2u;
    if (UINT64_MAX - batch_offset < element_offset) {
        return NPU_STATUS_ADDR_FAULT;
    }
    element_offset += batch_offset;
    if ((desc->b.region_bytes != 0u &&
         element_offset >= desc->b.region_bytes) ||
        UINT64_MAX - desc->b.addr < element_offset) {
        return NPU_STATUS_ADDR_FAULT;
    }
    addr = desc->b.addr + element_offset;
    status = npu_memory_read_u8(model, desc->b.space, addr, &byte_value);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    *value = npu_int4_unpack(byte_value, (uint8_t)(linear & 1u));
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_matrix_read_a(const npu_model_t *model,
                                      const npu_matrix_desc_t *desc,
                                      uint32_t batch,
                                      uint32_t m,
                                      uint32_t k,
                                      int32_t *value)
{
    if (desc->transpose_a != 0u) {
        return npu_tensor_read(model, &desc->a, batch, k, m, value);
    }
    return npu_tensor_read(model, &desc->a, batch, m, k, value);
}

static npu_status_t npu_matrix_read_requant(const npu_model_t *model,
                                            const npu_matrix_desc_t *desc,
                                            uint32_t n,
                                            npu_requant_t *entry)
{
    uint32_t index;
    uint32_t multiplier;
    uint8_t shift_bits;
    uint8_t reserved;
    uint64_t addr;
    uint32_t byte;
    npu_status_t status;

    if (desc->requant_count == 1u) {
        index = 0u;
    } else if (desc->requant_count == desc->n) {
        index = n;
    } else {
        return NPU_STATUS_BAD_DESC;
    }
    if ((uint64_t)(index + 1u) * 8u > desc->requant_region_bytes) {
        return NPU_STATUS_ADDR_FAULT;
    }
    addr = desc->requant_addr + (uint64_t)index * 8u;
    status = npu_memory_read_u32(model, NPU_SPACE_L1, addr, &multiplier);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (multiplier == 0u || multiplier > 0x7fffffffu) {
        return NPU_STATUS_BAD_DESC;
    }
    status = npu_memory_read_u8(model, NPU_SPACE_L1, addr + 4u,
                                &shift_bits);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    for (byte = 5u; byte < 8u; byte++) {
        status = npu_memory_read_u8(model, NPU_SPACE_L1, addr + byte,
                                    &reserved);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        if (reserved != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    }
    entry->multiplier = multiplier;
    if ((shift_bits & 0x80u) != 0u) {
        entry->shift = (int8_t)(-1 - (int8_t)(0xffu - shift_bits));
    } else {
        entry->shift = (int8_t)shift_bits;
    }
    if (entry->shift < -31 || entry->shift > 63) {
        return NPU_STATUS_BAD_DESC;
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_matrix_bias(const npu_model_t *model,
                                    const npu_matrix_desc_t *desc,
                                    uint32_t n,
                                    int32_t *bias)
{
    uint64_t offset;
    uint64_t addr;

    if (desc->bias_enable == 0u) {
        *bias = 0;
        return NPU_STATUS_SUCCESS;
    }
    if (desc->bias_count != desc->n ||
        desc->bias_stride_bytes < 4u) {
        return NPU_STATUS_BAD_DESC;
    }
    offset = (uint64_t)n * desc->bias_stride_bytes;
    if (UINT64_MAX - desc->bias_addr < offset) {
        return NPU_STATUS_ADDR_FAULT;
    }
    addr = desc->bias_addr + offset;
    return npu_memory_read_i32(model, NPU_SPACE_L1, addr, bias);
}

static npu_status_t npu_matrix_accumulator(npu_model_t *model,
                                           const npu_matrix_desc_t *desc,
                                           uint32_t batch,
                                           uint32_t m,
                                           uint32_t n,
                                           int32_t *accumulator,
                                           int count_saturation)
{
    uint32_t k;
    int32_t a;
    int32_t b;
    int32_t bias;
    int32_t old_value;
    int64_t sum = 0;
    int64_t with_aux;
    npu_status_t status;

    for (k = 0u; k < desc->k; k++) {
        status = npu_matrix_read_a(model, desc, batch, m, k, &a);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        status = npu_matrix_read_b(model, desc, batch, k, n, &b);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        sum += (int64_t)a * b;
    }
    status = npu_matrix_bias(model, desc, n, &bias);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    with_aux = sum + bias;

    if (desc->residual_enable != 0u ||
        desc->accum_from_src2 != 0u) {
        status = npu_tensor_read(model, &desc->src2, batch, m, n,
                                 &old_value);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        with_aux += old_value;
    }
    return npu_cast_integer(count_saturation != 0 ? model
                                                  : (npu_model_t *)0,
                            with_aux, NPU_DTYPE_INT32,
                            desc->overflow_mode, accumulator);
}

static npu_status_t npu_matrix_write_result(npu_model_t *model,
                                            const npu_matrix_desc_t *desc,
                                            uint32_t batch,
                                            uint32_t m,
                                            uint32_t n,
                                            int32_t accumulator)
{
    npu_requant_t requant;
    int64_t value = accumulator;
    int64_t shifted;
    int32_t output;
    npu_status_t status;

    if (desc->relu_enable != 0u && value < 0) {
        value = 0;
    }
    if (desc->c.dtype == NPU_DTYPE_INT32) {
        status = npu_cast_integer(model, value, NPU_DTYPE_INT32,
                                  desc->overflow_mode, &output);
    } else {
        status = npu_matrix_read_requant(model, desc, n, &requant);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        shifted = npu_round_shift(value * (int64_t)requant.multiplier,
                                  requant.shift,
                                  desc->round_mode);
        if (desc->output_zero_point > 0 &&
            shifted > INT64_MAX - desc->output_zero_point) {
            shifted = INT64_MAX;
        } else if (desc->output_zero_point < 0 &&
                   shifted < INT64_MIN - desc->output_zero_point) {
            shifted = INT64_MIN;
        } else {
            shifted += desc->output_zero_point;
        }
        status = npu_cast_integer(model, shifted, desc->c.dtype,
                                  NPU_OVERFLOW_SATURATE, &output);
    }
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    return npu_tensor_write(model, &desc->c, batch, m, n, output);
}

static npu_status_t npu_matrix_validate(const npu_model_t *model,
                                        uint8_t opcode,
                                        const npu_matrix_desc_t *desc)
{
    if (desc->batch_count == 0u ||
        desc->a.space != NPU_SPACE_L1 ||
        desc->b.space != NPU_SPACE_L1 ||
        desc->c.space != NPU_SPACE_L1 ||
        !npu_dtype_valid(desc->a.dtype) ||
        !npu_dtype_valid(desc->b.dtype) ||
        !npu_dtype_valid(desc->c.dtype)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->round_mode > NPU_ROUND_TO_NEG_INF ||
        desc->overflow_mode > NPU_OVERFLOW_WRAP) {
        return NPU_STATUS_BAD_DESC;
    }
    if (!((desc->a.dtype == NPU_DTYPE_INT4 &&
           desc->b.dtype == NPU_DTYPE_INT4) ||
          (desc->a.dtype == NPU_DTYPE_INT8 &&
           desc->b.dtype == NPU_DTYPE_INT8) ||
          (desc->a.dtype == NPU_DTYPE_INT8 &&
           desc->b.dtype == NPU_DTYPE_INT4) ||
          (desc->a.dtype == NPU_DTYPE_INT16 &&
           desc->b.dtype == NPU_DTYPE_INT16))) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (desc->b_tiled == 0u || desc->transpose_b != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (opcode == NPU_MATRIX_GEMM && desc->batch_count != 1u) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (opcode == NPU_MATRIX_BMM && desc->batch_count < 1u) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (desc->residual_enable != 0u &&
        desc->accum_from_src2 != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((desc->residual_enable != 0u ||
         desc->accum_from_src2 != 0u) &&
        (desc->src2.dtype != NPU_DTYPE_INT32 ||
         desc->src2.space != NPU_SPACE_L1)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (desc->bias_enable != 0u &&
        (desc->bias_count != desc->n ||
         desc->bias_stride_bytes < 4u)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->output_zero_point != 0) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->c.dtype == NPU_DTYPE_INT32) {
        if (desc->requant_enable != 0u ||
            desc->requant_count != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else {
        if (desc->requant_enable == 0u ||
            !(desc->requant_count == 1u ||
              desc->requant_count == desc->n) ||
            desc->requant_region_bytes <
                (uint64_t)desc->requant_count * 8u) {
            return NPU_STATUS_BAD_DESC;
        }
    }
    if (desc->final_output == 0u &&
        (desc->bias_enable != 0u ||
         desc->residual_enable != 0u ||
         desc->relu_enable != 0u ||
         desc->requant_enable != 0u ||
         desc->c.dtype != NPU_DTYPE_INT32)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (opcode == NPU_MATRIX_GEMM_ACCUM &&
        (desc->accum_from_src2 == 0u ||
         desc->final_output != 0u ||
         desc->c.dtype != NPU_DTYPE_INT32)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (model->config.mt == 0u ||
        model->config.kt == 0u ||
        model->config.nt == 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_matrix_zero(npu_model_t *model,
                                    const npu_matrix_desc_t *desc,
                                    uint64_t *progress)
{
    uint32_t batch;
    uint32_t m;
    uint32_t n;
    int32_t old_value;
    npu_status_t status;

    if (desc->c.dtype != NPU_DTYPE_INT32) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (desc->batch_count != 1u ||
        desc->k != 0u ||
        desc->c.space != NPU_SPACE_L1 ||
        desc->bias_enable != 0u ||
        desc->residual_enable != 0u ||
        desc->accum_from_src2 != 0u ||
        desc->final_output != 0u ||
        desc->relu_enable != 0u ||
        desc->requant_enable != 0u ||
        desc->bias_addr != 0u ||
        desc->bias_count != 0u ||
        desc->requant_addr != 0u ||
        desc->requant_count != 0u ||
        desc->requant_region_bytes != 0u ||
        desc->output_zero_point != 0) {
        return NPU_STATUS_BAD_DESC;
    }
    for (batch = 0u; batch < desc->batch_count; batch++) {
        for (m = 0u; m < desc->m; m++) {
            for (n = 0u; n < desc->n; n++) {
                status = npu_tensor_read(model, &desc->c,
                                         batch, m, n, &old_value);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
            }
        }
    }
    for (batch = 0u; batch < desc->batch_count; batch++) {
        for (m = 0u; m < desc->m; m++) {
            for (n = 0u; n < desc->n; n++) {
                status = npu_tensor_write(model, &desc->c,
                                          batch, m, n, 0);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                (*progress)++;
            }
        }
    }
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_matrix_preflight(
    npu_model_t *model,
    const npu_matrix_desc_t *desc)
{
    uint32_t batch;
    uint32_t m;
    uint32_t n;
    int32_t accumulator;
    int32_t old_value;
    npu_requant_t requant;
    npu_status_t status;

    for (batch = 0u; batch < desc->batch_count; batch++) {
        for (m = 0u; m < desc->m; m++) {
            for (n = 0u; n < desc->n; n++) {
                status = npu_matrix_accumulator(model, desc, batch,
                                                m, n, &accumulator, 0);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                status = npu_tensor_read(model, &desc->c,
                                         batch, m, n, &old_value);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                if (desc->c.dtype != NPU_DTYPE_INT32) {
                    status = npu_matrix_read_requant(model, desc, n,
                                                     &requant);
                    if (status != NPU_STATUS_SUCCESS) {
                        return status;
                    }
                }
            }
        }
    }
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_matrix_execute(npu_model_t *model,
                                uint8_t opcode,
                                const npu_matrix_desc_t *desc,
                                uint64_t *progress)
{
    uint32_t batch;
    uint32_t m;
    uint32_t n;
    int32_t accumulator;
    npu_status_t status;

    if (model == (npu_model_t *)0 ||
        desc == (const npu_matrix_desc_t *)0 ||
        progress == (uint64_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    *progress = 0u;
    if (opcode != NPU_MATRIX_GEMM &&
        opcode != NPU_MATRIX_BMM &&
        opcode != NPU_MATRIX_GEMM_ACCUM &&
        opcode != NPU_MATRIX_GEMM_ZERO) {
        return NPU_STATUS_ILLEGAL_OPCODE;
    }
    if (opcode == NPU_MATRIX_GEMM_ZERO) {
        return npu_matrix_zero(model, desc, progress);
    }
    status = npu_matrix_validate(model, opcode, desc);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (desc->m == 0u || desc->n == 0u) {
        return NPU_STATUS_SUCCESS;
    }

    status = npu_matrix_preflight(model, desc);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }

    for (batch = 0u; batch < desc->batch_count; batch++) {
        for (m = 0u; m < desc->m; m++) {
            for (n = 0u; n < desc->n; n++) {
                status = npu_matrix_accumulator(model, desc, batch,
                                                m, n, &accumulator, 1);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                status = npu_matrix_write_result(model, desc, batch,
                                                 m, n, accumulator);
                if (status != NPU_STATUS_SUCCESS) {
                    return status;
                }
                (*progress)++;
            }
            npu_clear_int4_tail(model, &desc->c, batch, m, desc->n);
        }
    }
    return NPU_STATUS_SUCCESS;
}
