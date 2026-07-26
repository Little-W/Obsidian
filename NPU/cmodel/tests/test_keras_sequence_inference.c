#include "generated/keras_sequence_fixtures.h"
#include "test_util.h"

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#ifdef KSI_MODEL_INFER_STANDALONE
#include <stdio.h>
#endif

#define KSI_L1_BYTES (256u * 1024u)
#define KSI_DDR_BYTES 4096u

#define KSI_A_ADDR UINT64_C(0x0000)
#define KSI_B_ADDR UINT64_C(0x1000)
#define KSI_BIAS_ADDR UINT64_C(0x3000)
#define KSI_REQUANT_ADDR UINT64_C(0x3100)
#define KSI_C_ADDR UINT64_C(0x4000)
#define KSI_SRC0_ADDR UINT64_C(0x5000)
#define KSI_SRC1_ADDR UINT64_C(0x6000)
#define KSI_DST_ADDR UINT64_C(0x7000)

#define KSI_MAX_VALUES 128u
#define KSI_GATE_SCALE (1.0f / 127.0f)
#define KSI_RECURRENT_VALUE_COUNT                              \
    (KSF_RECURRENT_BATCH * KSF_RECURRENT_STEPS *              \
     KSF_RECURRENT_UNITS)

static uint8_t ksi_l1[KSI_L1_BYTES];
static uint8_t ksi_ddr[KSI_DDR_BYTES];
static npu_model_t ksi_model;
static const uint8_t ksi_transformer_true_classes[
    KSF_TRANSFORMER_BATCH] = {
    KSF_TRANSFORMER_FIXED_TRUE_CLASSES_INITIALIZER
};
static const uint8_t ksi_transformer_keras_classes[
    KSF_TRANSFORMER_BATCH] = {
    KSF_TRANSFORMER_FIXED_PREDICTED_CLASSES_INITIALIZER
};
static const uint32_t ksi_recurrent_application_target_bits[
    KSI_RECURRENT_VALUE_COUNT] = {
    KSF_RECURRENT_APPLICATION_TARGET_F32_BITS_INITIALIZER
};

#ifdef KSI_MODEL_INFER_STANDALONE
static int8_t ksi_runner_transformer_logits[
    KSF_TRANSFORMER_BATCH * KSF_TRANSFORMER_CLASSES];
static int8_t ksi_runner_simple_rnn_output[
    KSI_RECURRENT_VALUE_COUNT];
static int8_t ksi_runner_gru_output[KSI_RECURRENT_VALUE_COUNT];
static int8_t ksi_runner_lstm_output[KSI_RECURRENT_VALUE_COUNT];

float test_abs_float(float value)
{
    return value < 0.0f ? -value : value;
}

npu_tensor_t test_tensor(npu_dtype_t dtype,
                         uint64_t addr,
                         uint64_t region_bytes,
                         uint32_t row_stride)
{
    npu_tensor_t tensor;

    tensor.space = NPU_SPACE_L1;
    tensor.dtype = dtype;
    tensor.addr = addr;
    tensor.region_bytes = region_bytes;
    tensor.row_stride_bytes = row_stride;
    tensor.elem_stride_bytes = 0u;
    tensor.batch_stride_bytes = 0u;
    tensor.start_nibble = 0u;
    return tensor;
}
#endif

static float ksi_float_from_bits(uint32_t bits)
{
    float value;

    (void)memcpy(&value, &bits, sizeof(value));
    return value;
}

static uint32_t ksi_float_bits(float value)
{
    uint32_t bits;

    (void)memcpy(&bits, &value, sizeof(bits));
    return bits;
}

static float ksi_scale(ksf_qparam_t qparam)
{
    return ksi_float_from_bits(qparam.scale_bits);
}

static int32_t ksi_abs_i32(int32_t value)
{
    return value < 0 ? -value : value;
}

static int8_t ksi_saturate_i8(int64_t value)
{
    if (value > INT8_MAX) {
        return INT8_MAX;
    }
    if (value < INT8_MIN) {
        return INT8_MIN;
    }
    return (int8_t)value;
}

static void ksi_put_u32(uint64_t addr, uint32_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 4u; byte++) {
        ksi_l1[(size_t)addr + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static void ksi_put_i32(uint64_t addr, int32_t value)
{
    ksi_put_u32(addr, (uint32_t)value);
}

static npu_tensor_t ksi_tensor(npu_dtype_t dtype,
                               uint64_t addr,
                               uint64_t region_bytes,
                               uint32_t row_stride,
                               uint32_t batch_stride)
{
    npu_tensor_t tensor =
        test_tensor(dtype, addr, region_bytes, row_stride);

    tensor.batch_stride_bytes = batch_stride;
    return tensor;
}

static int ksi_init(void)
{
    npu_config_t config;

    (void)memset(ksi_l1, 0, sizeof(ksi_l1));
    (void)memset(ksi_ddr, 0, sizeof(ksi_ddr));
    npu_config_reference(&config);
    config.l1_bytes = sizeof(ksi_l1);
    TEST_CHECK_STATUS(
        npu_model_init(&ksi_model, &config,
                       ksi_l1, sizeof(ksi_l1),
                       ksi_ddr, sizeof(ksi_ddr)),
        NPU_STATUS_SUCCESS);
    return 0;
}

static void ksi_clear_scratch(void)
{
    (void)memset(ksi_l1, 0, sizeof(ksi_l1));
}

static uint64_t ksi_tiled_batch_bytes(uint32_t k, uint32_t n)
{
    uint64_t k_tiles =
        ((uint64_t)k + ksi_model.config.kt - 1u) /
        ksi_model.config.kt;
    uint64_t n_tiles =
        ((uint64_t)n + ksi_model.config.nt - 1u) /
        ksi_model.config.nt;

    return k_tiles * n_tiles * ksi_model.config.kt *
           ksi_model.config.nt;
}

static void ksi_pack_b(const int8_t *ordinary,
                       uint32_t batch_count,
                       uint32_t k,
                       uint32_t n)
{
    uint64_t batch_bytes = ksi_tiled_batch_bytes(k, n);
    uint64_t n_tiles =
        ((uint64_t)n + ksi_model.config.nt - 1u) /
        ksi_model.config.nt;
    uint32_t batch;
    uint32_t row;
    uint32_t column;

    for (batch = 0u; batch < batch_count; batch++) {
        for (row = 0u; row < k; row++) {
            for (column = 0u; column < n; column++) {
                uint64_t linear =
                    ((((uint64_t)(row / ksi_model.config.kt) *
                           n_tiles +
                       column / ksi_model.config.nt) *
                          ksi_model.config.kt +
                      row % ksi_model.config.kt) *
                         ksi_model.config.nt) +
                    column % ksi_model.config.nt;
                ksi_l1[KSI_B_ADDR +
                       (uint64_t)batch * batch_bytes + linear] =
                    (uint8_t)ordinary[
                        ((size_t)batch * k + row) * n + column];
            }
        }
    }
}

static int ksi_matrix_run(uint8_t opcode,
                          uint32_t batch_count,
                          uint32_t m,
                          uint32_t k,
                          uint32_t n,
                          const int8_t *a,
                          const int8_t *b,
                          const int32_t *bias,
                          const ksf_requant_t *requant,
                          uint8_t relu,
                          npu_dtype_t output_dtype,
                          void *output)
{
    npu_matrix_desc_t desc;
    uint64_t progress = UINT64_MAX;
    uint64_t a_bytes = (uint64_t)batch_count * m * k;
    uint64_t b_batch_bytes = ksi_tiled_batch_bytes(k, n);
    uint64_t c_element_bytes =
        output_dtype == NPU_DTYPE_INT32 ? 4u : 1u;
    uint64_t c_bytes =
        (uint64_t)batch_count * m * n * c_element_bytes;
    uint32_t index;

    TEST_CHECK(batch_count != 0u);
    TEST_CHECK(a_bytes <= KSI_MAX_VALUES);
    TEST_CHECK((uint64_t)batch_count * k * n <=
               KSI_MAX_VALUES * 2u);
    TEST_CHECK(c_bytes <= KSI_MAX_VALUES * 4u);

    ksi_clear_scratch();
    (void)memcpy(&ksi_l1[KSI_A_ADDR], a, (size_t)a_bytes);
    ksi_pack_b(b, batch_count, k, n);
    if (bias != (const int32_t *)0) {
        for (index = 0u; index < n; index++) {
            ksi_put_i32(KSI_BIAS_ADDR + (uint64_t)index * 4u,
                        bias[index]);
        }
    }
    if (requant != (const ksf_requant_t *)0) {
        ksi_put_i32(KSI_REQUANT_ADDR, requant->multiplier);
        ksi_l1[KSI_REQUANT_ADDR + 4u] = requant->right_shift;
    }

    (void)memset(&desc, 0, sizeof(desc));
    desc.m = m;
    desc.n = n;
    desc.k = k;
    desc.batch_count = batch_count;
    desc.a = ksi_tensor(
        NPU_DTYPE_INT8, KSI_A_ADDR, a_bytes, k,
        m * k);
    desc.b = ksi_tensor(
        NPU_DTYPE_INT8, KSI_B_ADDR,
        b_batch_bytes * batch_count, 0u,
        (uint32_t)b_batch_bytes);
    desc.c = ksi_tensor(
        output_dtype, KSI_C_ADDR, c_bytes,
        n * (uint32_t)c_element_bytes,
        m * n * (uint32_t)c_element_bytes);
    desc.b_tiled = 1u;
    desc.bias_enable =
        bias != (const int32_t *)0 ? 1u : 0u;
    desc.bias_addr = KSI_BIAS_ADDR;
    desc.bias_count = desc.bias_enable != 0u ? n : 0u;
    desc.bias_stride_bytes = desc.bias_enable != 0u ? 4u : 0u;
    desc.final_output = 1u;
    desc.relu_enable = relu;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    if (output_dtype != NPU_DTYPE_INT32) {
        TEST_CHECK(requant != (const ksf_requant_t *)0);
        desc.requant_enable = 1u;
        desc.requant_addr = KSI_REQUANT_ADDR;
        desc.requant_count = 1u;
        desc.requant_region_bytes = 8u;
    }

    TEST_CHECK_STATUS(
        npu_matrix_execute(&ksi_model, opcode, &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == (uint64_t)batch_count * m * n);
    if (output_dtype == NPU_DTYPE_INT32) {
        int32_t *output_i32 = (int32_t *)output;

        for (index = 0u;
             index < batch_count * m * n; index++) {
            int32_t value = 0;
            uint32_t batch = index / (m * n);
            uint32_t within = index % (m * n);

            TEST_CHECK_STATUS(
                npu_tensor_read(
                    &ksi_model, &desc.c, batch,
                    within / n, within % n, &value),
                NPU_STATUS_SUCCESS);
            output_i32[index] = value;
        }
    } else {
        int8_t *output_i8 = (int8_t *)output;

        for (index = 0u;
             index < batch_count * m * n; index++) {
            int32_t value = 0;
            uint32_t batch = index / (m * n);
            uint32_t within = index % (m * n);

            TEST_CHECK_STATUS(
                npu_tensor_read(
                    &ksi_model, &desc.c, batch,
                    within / n, within % n, &value),
                NPU_STATUS_SUCCESS);
            output_i8[index] = (int8_t)value;
        }
    }
    return 0;
}

static int ksi_matrix_dense_i8(uint32_t m,
                               uint32_t k,
                               uint32_t n,
                               const int8_t *a,
                               const int8_t *b,
                               const int32_t *bias,
                               const ksf_requant_t *requant,
                               uint8_t relu,
                               int8_t *output)
{
    return ksi_matrix_run(
        NPU_MATRIX_GEMM, 1u, m, k, n, a, b, bias,
        requant, relu, NPU_DTYPE_INT8, output);
}

static int ksi_verify_dense(const char *name,
                            uint32_t m,
                            uint32_t k,
                            uint32_t n,
                            const int8_t *a,
                            const int8_t *b,
                            const int32_t *bias,
                            const ksf_requant_t *requant,
                            uint8_t relu,
                            const int32_t *expected_accum,
                            const int8_t *expected_output)
{
    int32_t accum[KSI_MAX_VALUES];
    int8_t output[KSI_MAX_VALUES];
    uint32_t index;

    (void)name;
    TEST_CHECK((uint64_t)m * n <= KSI_MAX_VALUES);
    TEST_CHECK(
        ksi_matrix_run(
            NPU_MATRIX_GEMM, 1u, m, k, n, a, b, bias,
            (const ksf_requant_t *)0, relu,
            NPU_DTYPE_INT32, accum) == 0);
    for (index = 0u; index < m * n; index++) {
        TEST_CHECK(accum[index] == expected_accum[index]);
    }
    TEST_CHECK(
        ksi_matrix_dense_i8(
            m, k, n, a, b, bias, requant, relu,
            output) == 0);
    for (index = 0u; index < m * n; index++) {
        TEST_CHECK(output[index] == expected_output[index]);
    }
    return 0;
}

static int ksi_check_q_close(const int8_t *actual,
                             const int8_t *expected,
                             uint32_t count,
                             int32_t tolerance)
{
    uint32_t index;

    for (index = 0u; index < count; index++) {
        TEST_CHECK(
            ksi_abs_i32((int32_t)actual[index] -
                        (int32_t)expected[index]) <= tolerance);
    }
    return 0;
}

static int ksi_check_dequantized(const int8_t *actual,
                                 float actual_scale,
                                 const uint32_t *expected_bits,
                                 uint32_t count,
                                 float tolerance)
{
    uint32_t index;

    for (index = 0u; index < count; index++) {
        float actual_value = (float)actual[index] * actual_scale;
        float expected_value =
            ksi_float_from_bits(expected_bits[index]);

        TEST_CHECK(
            test_abs_float(actual_value - expected_value) <=
            tolerance);
    }
    return 0;
}

static float ksi_application_mse(
    const int8_t *actual,
    float actual_scale,
    const uint32_t *target_bits,
    uint32_t count)
{
    double squared_error = 0.0;
    uint32_t index;

    for (index = 0u; index < count; index++) {
        double actual_value =
            (double)actual[index] * (double)actual_scale;
        double target_value =
            (double)ksi_float_from_bits(target_bits[index]);
        double difference = actual_value - target_value;

        squared_error += difference * difference;
    }
    return count == 0u
               ? 0.0f
               : (float)(squared_error / (double)count);
}

static uint32_t ksi_argmax_i8(const int8_t *values,
                              uint32_t count)
{
    uint32_t best = 0u;
    uint32_t index;

    for (index = 1u; index < count; index++) {
        if (values[index] > values[best]) {
            best = index;
        }
    }
    return best;
}

static int ksi_has_recurrent_history_response(const int8_t *values,
                                              float scale,
                                              const uint32_t *target_bits)
{
    float maximum_difference = 0.0f;
    double own_error = 0.0;
    double swapped_error = 0.0;
    double same_current_error = 0.0;
    uint32_t unit;

    for (unit = 0u; unit < KSF_RECURRENT_UNITS; unit++) {
        size_t first =
            (KSF_RECURRENT_STEPS - 1u) * KSF_RECURRENT_UNITS +
            unit;
        size_t second =
            ((size_t)KSF_RECURRENT_STEPS * KSF_RECURRENT_UNITS) +
            first;
        float difference =
            test_abs_float(
                (float)values[first] * scale -
                (float)values[second] * scale);
        double prediction_first =
            (double)values[first] * (double)scale;
        double prediction_second =
            (double)values[second] * (double)scale;
        double target_first =
            (double)ksi_float_from_bits(target_bits[first]);
        double target_second =
            (double)ksi_float_from_bits(target_bits[second]);
        double shared_target =
            (target_first + target_second) * 0.5;

        if (difference > maximum_difference) {
            maximum_difference = difference;
        }
        own_error +=
            (prediction_first - target_first) *
                (prediction_first - target_first) +
            (prediction_second - target_second) *
                (prediction_second - target_second);
        swapped_error +=
            (prediction_first - target_second) *
                (prediction_first - target_second) +
            (prediction_second - target_first) *
                (prediction_second - target_first);
        same_current_error +=
            (shared_target - target_first) *
                (shared_target - target_first) +
            (shared_target - target_second) *
                (shared_target - target_second);
    }
    return maximum_difference > 0.005f &&
           own_error < swapped_error &&
           own_error < same_current_error;
}

static int ksi_transformer_dense_layers(void)
{
    TEST_CHECK(
        ksi_verify_dense(
            "query", 8u, 4u, 4u,
            ksf_transformer_embedding_sum_q,
            ksf_transformer_query_kernel_q,
            ksf_transformer_query_bias_q,
            &ksf_transformer_query_requant, 0u,
            ksf_transformer_query_accum_i32,
            ksf_transformer_query_integer_q) == 0);
    TEST_CHECK(
        ksi_verify_dense(
            "key", 8u, 4u, 4u,
            ksf_transformer_embedding_sum_q,
            ksf_transformer_key_kernel_q,
            ksf_transformer_key_bias_q,
            &ksf_transformer_key_requant, 0u,
            ksf_transformer_key_accum_i32,
            ksf_transformer_key_integer_q) == 0);
    TEST_CHECK(
        ksi_verify_dense(
            "value", 8u, 4u, 4u,
            ksf_transformer_embedding_sum_q,
            ksf_transformer_value_kernel_q,
            ksf_transformer_value_bias_q,
            &ksf_transformer_value_requant, 0u,
            ksf_transformer_value_accum_i32,
            ksf_transformer_value_integer_q) == 0);
    TEST_CHECK(
        ksi_verify_dense(
            "attention_output", 8u, 4u, 4u,
            ksf_transformer_attention_context_q,
            ksf_transformer_attention_output_kernel_q,
            ksf_transformer_attention_output_bias_q,
            &ksf_transformer_attention_output_requant, 0u,
            ksf_transformer_attention_output_accum_i32,
            ksf_transformer_attention_output_integer_q) == 0);
    TEST_CHECK(
        ksi_verify_dense(
            "ffn_inner", 8u, 4u, 6u,
            ksf_transformer_attention_residual_q,
            ksf_transformer_ffn_inner_kernel_q,
            ksf_transformer_ffn_inner_bias_q,
            &ksf_transformer_ffn_inner_requant, 1u,
            ksf_transformer_ffn_inner_accum_i32,
            ksf_transformer_ffn_inner_integer_q) == 0);
    TEST_CHECK(
        ksi_verify_dense(
            "ffn_output", 8u, 6u, 4u,
            ksf_transformer_ffn_inner_q,
            ksf_transformer_ffn_output_kernel_q,
            ksf_transformer_ffn_output_bias_q,
            &ksf_transformer_ffn_output_requant, 0u,
            ksf_transformer_ffn_output_accum_i32,
            ksf_transformer_ffn_output_integer_q) == 0);
    TEST_CHECK(
        ksi_verify_dense(
            "classifier", 2u, 4u, 3u,
            ksf_transformer_pooled_q,
            ksf_transformer_classifier_kernel_q,
            ksf_transformer_classifier_bias_q,
            &ksf_transformer_classifier_requant, 0u,
            ksf_transformer_classifier_accum_i32,
            ksf_transformer_classifier_integer_q) == 0);
    return 0;
}

static uint32_t ksi_dtype_bytes(npu_dtype_t dtype)
{
    return dtype == NPU_DTYPE_INT32 ? 4u : 1u;
}

static void ksi_copy_to_l1(uint64_t addr,
                           npu_dtype_t dtype,
                           const void *values,
                           uint32_t count)
{
    uint32_t index;

    if (dtype == NPU_DTYPE_INT32) {
        const int32_t *values_i32 = (const int32_t *)values;

        for (index = 0u; index < count; index++) {
            ksi_put_i32(addr + (uint64_t)index * 4u,
                        values_i32[index]);
        }
    } else {
        (void)memcpy(&ksi_l1[addr], values, count);
    }
}

static int ksi_complex_add_rescale(uint32_t rows,
                                   uint32_t length,
                                   npu_dtype_t src0_dtype,
                                   const void *src0,
                                   float src0_scale,
                                   npu_dtype_t src1_dtype,
                                   const void *src1,
                                   float src1_scale,
                                   npu_dtype_t dst_dtype,
                                   float dst_scale,
                                   void *output)
{
    npu_complex_desc_t desc;
    uint64_t progress = UINT64_MAX;
    uint32_t count = rows * length;
    uint32_t src0_bytes = ksi_dtype_bytes(src0_dtype);
    uint32_t src1_bytes = ksi_dtype_bytes(src1_dtype);
    uint32_t dst_bytes = ksi_dtype_bytes(dst_dtype);
    uint32_t index;

    TEST_CHECK(count <= KSI_MAX_VALUES);
    ksi_clear_scratch();
    ksi_copy_to_l1(KSI_SRC0_ADDR, src0_dtype, src0, count);
    ksi_copy_to_l1(KSI_SRC1_ADDR, src1_dtype, src1, count);

    (void)memset(&desc, 0, sizeof(desc));
    desc.rows = rows;
    desc.length = length;
    desc.valid_length = length;
    desc.function = NPU_FUNC_ADD_RESCALE;
    desc.src0 = ksi_tensor(
        src0_dtype, KSI_SRC0_ADDR,
        (uint64_t)count * src0_bytes,
        length * src0_bytes, 0u);
    desc.src1 = ksi_tensor(
        src1_dtype, KSI_SRC1_ADDR,
        (uint64_t)count * src1_bytes,
        length * src1_bytes, 0u);
    desc.dst = ksi_tensor(
        dst_dtype, KSI_DST_ADDR,
        (uint64_t)count * dst_bytes,
        length * dst_bytes, 0u);
    desc.src0_scale = src0_scale;
    desc.src1_scale = src1_scale;
    desc.dst_scale = dst_scale;
    desc.scale_mode = NPU_SCALE_PER_TENSOR;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.all_mask_mode = NPU_ALL_MASK_WRITE_ZERO;

    TEST_CHECK_STATUS(
        npu_complex_execute(
            &ksi_model, NPU_COMPLEX_ADD_RESCALE,
            &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == count);
    for (index = 0u; index < count; index++) {
        int32_t value = 0;

        TEST_CHECK_STATUS(
            npu_tensor_read(
                &ksi_model, &desc.dst, 0u,
                index / length, index % length, &value),
            NPU_STATUS_SUCCESS);
        if (dst_dtype == NPU_DTYPE_INT32) {
            ((int32_t *)output)[index] = value;
        } else {
            ((int8_t *)output)[index] = (int8_t)value;
        }
    }
    return 0;
}

static int ksi_complex_activation(uint32_t rows,
                                  uint32_t length,
                                  const int8_t *input,
                                  float input_scale,
                                  npu_function_t function,
                                  float output_scale,
                                  int8_t *output)
{
    npu_complex_desc_t desc;
    uint64_t progress = UINT64_MAX;
    uint32_t count = rows * length;
    uint32_t index;

    TEST_CHECK(count <= KSI_MAX_VALUES);
    ksi_clear_scratch();
    (void)memcpy(&ksi_l1[KSI_SRC0_ADDR], input, count);

    (void)memset(&desc, 0, sizeof(desc));
    desc.rows = rows;
    desc.length = length;
    desc.valid_length = length;
    desc.function = function;
    desc.src0 = ksi_tensor(
        NPU_DTYPE_INT8, KSI_SRC0_ADDR, count, length, 0u);
    desc.dst = ksi_tensor(
        NPU_DTYPE_INT8, KSI_DST_ADDR, count, length, 0u);
    desc.src0_scale = input_scale;
    desc.dst_scale = output_scale;
    desc.scale_mode = NPU_SCALE_PER_TENSOR;
    desc.input_clip_min = -16.0f;
    desc.input_clip_max = 16.0f;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.all_mask_mode = NPU_ALL_MASK_WRITE_ZERO;

    TEST_CHECK_STATUS(
        npu_complex_execute(
            &ksi_model, NPU_COMPLEX_ACT, &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == count);
    for (index = 0u; index < count; index++) {
        int32_t value = 0;

        TEST_CHECK_STATUS(
            npu_tensor_read(
                &ksi_model, &desc.dst, 0u,
                index / length, index % length, &value),
            NPU_STATUS_SUCCESS);
        output[index] = (int8_t)value;
    }
    return 0;
}

static int ksi_complex_softmax(uint32_t rows,
                               uint32_t length,
                               const int8_t *input,
                               float input_scale,
                               float output_scale,
                               int8_t *output)
{
    npu_complex_desc_t desc;
    uint64_t progress = UINT64_MAX;
    uint32_t count = rows * length;
    uint32_t index;

    TEST_CHECK(count <= KSI_MAX_VALUES);
    ksi_clear_scratch();
    (void)memcpy(&ksi_l1[KSI_SRC0_ADDR], input, count);

    (void)memset(&desc, 0, sizeof(desc));
    desc.rows = rows;
    desc.length = length;
    desc.valid_length = length;
    desc.function = NPU_FUNC_SOFTMAX;
    desc.src0 = ksi_tensor(
        NPU_DTYPE_INT8, KSI_SRC0_ADDR, count, length, 0u);
    desc.dst = ksi_tensor(
        NPU_DTYPE_INT8, KSI_DST_ADDR, count, length, 0u);
    desc.src0_scale = input_scale;
    desc.dst_scale = output_scale;
    desc.scale_mode = NPU_SCALE_PER_TENSOR;
    desc.input_clip_min = -16.0f;
    desc.input_clip_max = 16.0f;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.mask_mode = NPU_MASK_NONE;
    desc.all_mask_mode = NPU_ALL_MASK_WRITE_ZERO;
    desc.scratch_request_elems = length;

    TEST_CHECK_STATUS(
        npu_complex_execute(
            &ksi_model, NPU_COMPLEX_SOFTMAX,
            &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == count);
    for (index = 0u; index < count; index++) {
        int32_t value = 0;

        TEST_CHECK_STATUS(
            npu_tensor_read(
                &ksi_model, &desc.dst, 0u,
                index / length, index % length, &value),
            NPU_STATUS_SUCCESS);
        output[index] = (int8_t)value;
    }
    return 0;
}

static int ksi_complex_sum(uint32_t rows,
                           uint32_t length,
                           const int8_t *input,
                           int32_t *output)
{
    npu_complex_desc_t desc;
    uint64_t progress = UINT64_MAX;
    uint32_t count = rows * length;
    uint32_t row;

    TEST_CHECK(count <= KSI_MAX_VALUES);
    ksi_clear_scratch();
    (void)memcpy(&ksi_l1[KSI_SRC0_ADDR], input, count);

    (void)memset(&desc, 0, sizeof(desc));
    desc.rows = rows;
    desc.length = length;
    desc.valid_length = length;
    desc.function = NPU_FUNC_STAT_SUM;
    desc.src0 = ksi_tensor(
        NPU_DTYPE_INT8, KSI_SRC0_ADDR, count, length, 0u);
    desc.dst = ksi_tensor(
        NPU_DTYPE_INT32, KSI_DST_ADDR,
        (uint64_t)rows * 4u, 4u, 0u);
    desc.scale_mode = NPU_SCALE_NONE;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.all_mask_mode = NPU_ALL_MASK_WRITE_ZERO;

    TEST_CHECK_STATUS(
        npu_complex_execute(
            &ksi_model, NPU_COMPLEX_STAT, &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == rows);
    for (row = 0u; row < rows; row++) {
        TEST_CHECK_STATUS(
            npu_tensor_read(
                &ksi_model, &desc.dst, 0u, row, 0u,
                &output[row]),
            NPU_STATUS_SUCCESS);
    }
    return 0;
}

static int ksi_vector_mul(const int8_t *src0,
                          const int8_t *src1,
                          uint32_t count,
                          float src0_scale,
                          float src1_scale,
                          int32_t *output)
{
    npu_vector_desc_t desc;
    uint64_t progress = UINT64_MAX;
    uint32_t index;

    TEST_CHECK(count <= KSI_MAX_VALUES);
    ksi_clear_scratch();
    (void)memcpy(&ksi_l1[KSI_SRC0_ADDR], src0, count);
    (void)memcpy(&ksi_l1[KSI_SRC1_ADDR], src1, count);

    (void)memset(&desc, 0, sizeof(desc));
    desc.rows = 1u;
    desc.length = count;
    desc.valid_length = count;
    desc.src0 = ksi_tensor(
        NPU_DTYPE_INT8, KSI_SRC0_ADDR, count, count, 0u);
    desc.src1 = ksi_tensor(
        NPU_DTYPE_INT8, KSI_SRC1_ADDR, count, count, 0u);
    desc.dst = ksi_tensor(
        NPU_DTYPE_INT32, KSI_DST_ADDR,
        (uint64_t)count * 4u, count * 4u, 0u);
    desc.src0_scale_bits = ksi_float_bits(src0_scale);
    desc.src1_scale_bits = ksi_float_bits(src1_scale);
    desc.src2_scale_bits = ksi_float_bits(1.0f);
    desc.dst_scale_bits =
        ksi_float_bits(src0_scale * src1_scale);
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;

    TEST_CHECK_STATUS(
        npu_vector_execute(
            &ksi_model, NPU_VECTOR_MUL, &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == count);
    for (index = 0u; index < count; index++) {
        TEST_CHECK_STATUS(
            npu_tensor_read(
                &ksi_model, &desc.dst, 0u, 0u, index,
                &output[index]),
            NPU_STATUS_SUCCESS);
    }
    return 0;
}

static int ksi_matrix_bmm_i8(uint32_t batch_count,
                             uint32_t m,
                             uint32_t k,
                             uint32_t n,
                             const int8_t *a,
                             const int8_t *b,
                             const ksf_requant_t *requant,
                             int8_t *output)
{
    return ksi_matrix_run(
        NPU_MATRIX_BMM, batch_count, m, k, n,
        a, b, (const int32_t *)0, requant, 0u,
        NPU_DTYPE_INT8, output);
}

static void ksi_transpose_attention_key(const int8_t *key,
                                        int8_t *transposed)
{
    uint32_t batch;
    uint32_t k;
    uint32_t n;

    for (batch = 0u; batch < KSF_TRANSFORMER_BATCH; batch++) {
        for (k = 0u; k < KSF_TRANSFORMER_WIDTH; k++) {
            for (n = 0u; n < KSF_TRANSFORMER_SEQUENCE; n++) {
                transposed[
                    ((size_t)batch * KSF_TRANSFORMER_WIDTH + k) *
                        KSF_TRANSFORMER_SEQUENCE +
                    n] =
                    key[
                        ((size_t)batch * KSF_TRANSFORMER_SEQUENCE + n) *
                            KSF_TRANSFORMER_WIDTH +
                        k];
            }
        }
    }
}

static int ksi_transformer_operator_layers(void)
{
    int8_t key_transposed[32];
    int8_t score[32];
    int8_t probability[32];
    int8_t context[32];
    int8_t residual[32];
    int8_t encoded[32];
    int8_t pool_source[32];
    int8_t pooled[8];
    int32_t sums[8];
    int32_t zeros[8] = {0};
    uint32_t batch;
    uint32_t sequence;
    uint32_t feature;

    ksi_transpose_attention_key(
        ksf_transformer_key_q, key_transposed);
    TEST_CHECK(
        ksi_matrix_bmm_i8(
            KSF_TRANSFORMER_BATCH,
            KSF_TRANSFORMER_SEQUENCE,
            KSF_TRANSFORMER_WIDTH,
            KSF_TRANSFORMER_SEQUENCE,
            ksf_transformer_query_q, key_transposed,
            &ksf_transformer_attention_score_requant,
            score) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            score, ksf_transformer_attention_score_q,
            32u, 3) == 0);

    TEST_CHECK(
        ksi_complex_softmax(
            KSF_TRANSFORMER_BATCH *
                KSF_TRANSFORMER_SEQUENCE,
            KSF_TRANSFORMER_SEQUENCE,
            ksf_transformer_attention_score_q,
            ksi_scale(
                ksf_transformer_attention_score_qparam),
            ksi_scale(
                ksf_transformer_attention_probability_qparam),
            probability) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            probability,
            ksf_transformer_attention_probability_q,
            32u, 1) == 0);

    TEST_CHECK(
        ksi_matrix_bmm_i8(
            KSF_TRANSFORMER_BATCH,
            KSF_TRANSFORMER_SEQUENCE,
            KSF_TRANSFORMER_SEQUENCE,
            KSF_TRANSFORMER_WIDTH,
            ksf_transformer_attention_probability_q,
            ksf_transformer_value_q,
            &ksf_transformer_attention_context_requant,
            context) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            context, ksf_transformer_attention_context_q,
            32u, 3) == 0);

    TEST_CHECK(
        ksi_complex_add_rescale(
            8u, 4u, NPU_DTYPE_INT8,
            ksf_transformer_embedding_sum_q,
            ksi_scale(ksf_transformer_embedding_sum_qparam),
            NPU_DTYPE_INT8,
            ksf_transformer_attention_output_q,
            ksi_scale(
                ksf_transformer_attention_output_qparam),
            NPU_DTYPE_INT8,
            ksi_scale(
                ksf_transformer_attention_residual_qparam),
            residual) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            residual,
            ksf_transformer_attention_residual_q,
            32u, 1) == 0);

    TEST_CHECK(
        ksi_complex_add_rescale(
            8u, 4u, NPU_DTYPE_INT8,
            ksf_transformer_attention_residual_q,
            ksi_scale(
                ksf_transformer_attention_residual_qparam),
            NPU_DTYPE_INT8,
            ksf_transformer_ffn_output_q,
            ksi_scale(ksf_transformer_ffn_output_qparam),
            NPU_DTYPE_INT8,
            ksi_scale(ksf_transformer_encoded_qparam),
            encoded) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            encoded, ksf_transformer_encoded_q,
            32u, 1) == 0);

    for (batch = 0u; batch < KSF_TRANSFORMER_BATCH; batch++) {
        for (feature = 0u;
             feature < KSF_TRANSFORMER_WIDTH; feature++) {
            for (sequence = 0u;
                 sequence < KSF_TRANSFORMER_SEQUENCE;
                 sequence++) {
                pool_source[
                    ((size_t)batch * KSF_TRANSFORMER_WIDTH +
                     feature) *
                        KSF_TRANSFORMER_SEQUENCE +
                    sequence] =
                    ksf_transformer_encoded_q[
                        ((size_t)batch *
                             KSF_TRANSFORMER_SEQUENCE +
                         sequence) *
                            KSF_TRANSFORMER_WIDTH +
                        feature];
            }
        }
    }
    TEST_CHECK(
        ksi_complex_sum(
            KSF_TRANSFORMER_BATCH * KSF_TRANSFORMER_WIDTH,
            KSF_TRANSFORMER_SEQUENCE, pool_source, sums) == 0);
    TEST_CHECK(
        ksi_complex_add_rescale(
            2u, 4u, NPU_DTYPE_INT32, sums,
            ksi_scale(ksf_transformer_encoded_qparam) /
                (float)KSF_TRANSFORMER_SEQUENCE,
            NPU_DTYPE_INT32, zeros, 1.0f,
            NPU_DTYPE_INT8,
            ksi_scale(ksf_transformer_pooled_qparam),
            pooled) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            pooled, ksf_transformer_pooled_q, 8u, 1) == 0);
    return 0;
}

static int ksi_transformer_full_network(void)
{
    int8_t token_embedding[32];
    int8_t position_embedding[32];
    int8_t embedding[32];
    int8_t query[32];
    int8_t key[32];
    int8_t value[32];
    int8_t key_transposed[32];
    int8_t score[32];
    int8_t probability[32];
    int8_t context[32];
    int8_t attention_output[32];
    int8_t residual[32];
    int8_t ffn_inner[48];
    int8_t ffn_output[32];
    int8_t encoded[32];
    int8_t pool_source[32];
    int32_t pool_sum[8];
    int32_t zeros[8] = {0};
    int8_t pooled[8];
    int8_t logits[6];
    uint32_t batch;
    uint32_t sequence;
    uint32_t feature;
    uint32_t index;

    for (index = 0u; index < 8u; index++) {
        uint32_t token = ksf_transformer_token_ids[index];
        uint32_t position =
            ksf_transformer_position_ids[index];

        TEST_CHECK(token < KSF_TRANSFORMER_VOCAB);
        TEST_CHECK(position < KSF_TRANSFORMER_SEQUENCE);
        for (feature = 0u;
             feature < KSF_TRANSFORMER_WIDTH; feature++) {
            token_embedding[index * KSF_TRANSFORMER_WIDTH +
                            feature] =
                ksf_transformer_token_embedding_weight_q[
                    token * KSF_TRANSFORMER_WIDTH + feature];
            position_embedding[index * KSF_TRANSFORMER_WIDTH +
                               feature] =
                ksf_transformer_position_embedding_weight_q[
                    position * KSF_TRANSFORMER_WIDTH + feature];
        }
    }
    TEST_CHECK(
        ksi_complex_add_rescale(
            8u, 4u, NPU_DTYPE_INT8, token_embedding,
            ksi_scale(
                ksf_transformer_token_embedding_weight_qparam),
            NPU_DTYPE_INT8, position_embedding,
            ksi_scale(
                ksf_transformer_position_embedding_weight_qparam),
            NPU_DTYPE_INT8,
            ksi_scale(ksf_transformer_embedding_sum_qparam),
            embedding) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            embedding, ksf_transformer_embedding_sum_q,
            32u, 2) == 0);

    TEST_CHECK(
        ksi_matrix_dense_i8(
            8u, 4u, 4u, embedding,
            ksf_transformer_query_kernel_q,
            ksf_transformer_query_bias_q,
            &ksf_transformer_query_requant, 0u, query) == 0);
    TEST_CHECK(
        ksi_matrix_dense_i8(
            8u, 4u, 4u, embedding,
            ksf_transformer_key_kernel_q,
            ksf_transformer_key_bias_q,
            &ksf_transformer_key_requant, 0u, key) == 0);
    TEST_CHECK(
        ksi_matrix_dense_i8(
            8u, 4u, 4u, embedding,
            ksf_transformer_value_kernel_q,
            ksf_transformer_value_bias_q,
            &ksf_transformer_value_requant, 0u, value) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            query, ksf_transformer_query_q, 32u, 4) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            key, ksf_transformer_key_q, 32u, 4) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            value, ksf_transformer_value_q, 32u, 4) == 0);

    ksi_transpose_attention_key(key, key_transposed);
    TEST_CHECK(
        ksi_matrix_bmm_i8(
            2u, 4u, 4u, 4u, query, key_transposed,
            &ksf_transformer_attention_score_requant,
            score) == 0);
    TEST_CHECK(
        ksi_complex_softmax(
            8u, 4u, score,
            ksi_scale(
                ksf_transformer_attention_score_qparam),
            ksi_scale(
                ksf_transformer_attention_probability_qparam),
            probability) == 0);
    TEST_CHECK(
        ksi_matrix_bmm_i8(
            2u, 4u, 4u, 4u, probability, value,
            &ksf_transformer_attention_context_requant,
            context) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            probability,
            ksf_transformer_attention_probability_q,
            32u, 4) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            context, ksf_transformer_attention_context_q,
            32u, 8) == 0);

    TEST_CHECK(
        ksi_matrix_dense_i8(
            8u, 4u, 4u, context,
            ksf_transformer_attention_output_kernel_q,
            ksf_transformer_attention_output_bias_q,
            &ksf_transformer_attention_output_requant,
            0u, attention_output) == 0);
    TEST_CHECK(
        ksi_complex_add_rescale(
            8u, 4u, NPU_DTYPE_INT8, embedding,
            ksi_scale(ksf_transformer_embedding_sum_qparam),
            NPU_DTYPE_INT8, attention_output,
            ksi_scale(
                ksf_transformer_attention_output_qparam),
            NPU_DTYPE_INT8,
            ksi_scale(
                ksf_transformer_attention_residual_qparam),
            residual) == 0);
    TEST_CHECK(
        ksi_matrix_dense_i8(
            8u, 4u, 6u, residual,
            ksf_transformer_ffn_inner_kernel_q,
            ksf_transformer_ffn_inner_bias_q,
            &ksf_transformer_ffn_inner_requant,
            1u, ffn_inner) == 0);
    TEST_CHECK(
        ksi_matrix_dense_i8(
            8u, 6u, 4u, ffn_inner,
            ksf_transformer_ffn_output_kernel_q,
            ksf_transformer_ffn_output_bias_q,
            &ksf_transformer_ffn_output_requant,
            0u, ffn_output) == 0);
    TEST_CHECK(
        ksi_complex_add_rescale(
            8u, 4u, NPU_DTYPE_INT8, residual,
            ksi_scale(
                ksf_transformer_attention_residual_qparam),
            NPU_DTYPE_INT8, ffn_output,
            ksi_scale(ksf_transformer_ffn_output_qparam),
            NPU_DTYPE_INT8,
            ksi_scale(ksf_transformer_encoded_qparam),
            encoded) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            residual,
            ksf_transformer_attention_residual_q,
            32u, 7) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            ffn_inner, ksf_transformer_ffn_inner_q,
            48u, 10) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            encoded, ksf_transformer_encoded_q,
            32u, 10) == 0);

    for (batch = 0u; batch < KSF_TRANSFORMER_BATCH; batch++) {
        for (feature = 0u;
             feature < KSF_TRANSFORMER_WIDTH; feature++) {
            for (sequence = 0u;
                 sequence < KSF_TRANSFORMER_SEQUENCE;
                 sequence++) {
                pool_source[
                    ((size_t)batch * KSF_TRANSFORMER_WIDTH +
                     feature) *
                        KSF_TRANSFORMER_SEQUENCE +
                    sequence] =
                    encoded[
                        ((size_t)batch *
                             KSF_TRANSFORMER_SEQUENCE +
                         sequence) *
                            KSF_TRANSFORMER_WIDTH +
                        feature];
            }
        }
    }
    TEST_CHECK(
        ksi_complex_sum(8u, 4u, pool_source, pool_sum) == 0);
    TEST_CHECK(
        ksi_complex_add_rescale(
            2u, 4u, NPU_DTYPE_INT32, pool_sum,
            ksi_scale(ksf_transformer_encoded_qparam) / 4.0f,
            NPU_DTYPE_INT32, zeros, 1.0f,
            NPU_DTYPE_INT8,
            ksi_scale(ksf_transformer_pooled_qparam),
            pooled) == 0);
    TEST_CHECK(
        ksi_matrix_dense_i8(
            2u, 4u, 3u, pooled,
            ksf_transformer_classifier_kernel_q,
            ksf_transformer_classifier_bias_q,
            &ksf_transformer_classifier_requant,
            0u, logits) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            logits, ksf_transformer_logits_q,
            6u, 15) == 0);
    TEST_CHECK(
        ksi_check_dequantized(
            logits, ksi_scale(ksf_transformer_logits_qparam),
            ksf_transformer_logits_f32_bits, 6u, 0.08f) == 0);
    for (batch = 0u; batch < KSF_TRANSFORMER_BATCH; batch++) {
        uint32_t predicted = ksi_argmax_i8(
            &logits[batch * KSF_TRANSFORMER_CLASSES],
            KSF_TRANSFORMER_CLASSES);

        TEST_CHECK(predicted == ksi_transformer_true_classes[batch]);
        TEST_CHECK(predicted == ksi_transformer_keras_classes[batch]);
    }
#ifdef KSI_MODEL_INFER_STANDALONE
    (void)memcpy(
        ksi_runner_transformer_logits, logits, sizeof(logits));
#endif
    return 0;
}

static void ksi_recurrent_previous_hidden(
    const int8_t *hidden_sequence,
    int8_t *previous)
{
    uint32_t batch;
    uint32_t step;
    uint32_t unit;

    for (batch = 0u; batch < KSF_RECURRENT_BATCH; batch++) {
        for (step = 0u; step < KSF_RECURRENT_STEPS; step++) {
            for (unit = 0u; unit < KSF_RECURRENT_UNITS; unit++) {
                size_t index =
                    ((size_t)batch * KSF_RECURRENT_STEPS + step) *
                        KSF_RECURRENT_UNITS +
                    unit;

                previous[index] =
                    step == 0u
                        ? 0
                        : hidden_sequence[index -
                                          KSF_RECURRENT_UNITS];
            }
        }
    }
}

static int ksi_matrix_projection(uint32_t rows,
                                 uint32_t k,
                                 uint32_t n,
                                 const int8_t *input,
                                 const int8_t *kernel,
                                 const ksf_requant_t *requant,
                                 int8_t *output)
{
    int32_t accum[KSI_MAX_VALUES];
    uint32_t row;
    uint32_t column;
    uint32_t inner;

    TEST_CHECK((uint64_t)rows * n <= KSI_MAX_VALUES);
    TEST_CHECK(
        ksi_matrix_run(
            NPU_MATRIX_GEMM, 1u, rows, k, n,
            input, kernel, (const int32_t *)0,
            (const ksf_requant_t *)0, 0u,
            NPU_DTYPE_INT32, accum) == 0);
    for (row = 0u; row < rows; row++) {
        for (column = 0u; column < n; column++) {
            int32_t expected = 0;

            for (inner = 0u; inner < k; inner++) {
                expected +=
                    (int32_t)input[row * k + inner] *
                    (int32_t)kernel[inner * n + column];
            }
            TEST_CHECK(accum[row * n + column] == expected);
        }
    }
    TEST_CHECK(
        ksi_matrix_dense_i8(
            rows, k, n, input, kernel,
            (const int32_t *)0, requant, 0u,
            output) == 0);
    return 0;
}

static int ksi_simple_rnn_projection_layers(void)
{
    int8_t previous[24];
    int8_t input_projection[24];
    int8_t recurrent_projection[24];
    int8_t preactivation[24];
    uint32_t index;
    float pre_scale =
        ksi_scale(ksf_simple_rnn_preactivation_qparam);

    ksi_recurrent_previous_hidden(
        ksf_simple_rnn_hidden_q, previous);
    TEST_CHECK(
        ksi_verify_dense(
            "simple_rnn_input_projection",
            8u, 3u, 3u, ksf_simple_rnn_input_q,
            ksf_simple_rnn_kernel_q,
            (const int32_t *)0,
            &ksf_simple_rnn_input_projection_requant, 0u,
            ksf_simple_rnn_input_projection_accum_i32,
            ksf_simple_rnn_input_projection_integer_q) == 0);
    TEST_CHECK(
        ksi_verify_dense(
            "simple_rnn_recurrent_projection",
            8u, 3u, 3u, previous,
            ksf_simple_rnn_recurrent_kernel_q,
            (const int32_t *)0,
            &ksf_simple_rnn_recurrent_projection_requant, 0u,
            ksf_simple_rnn_recurrent_projection_accum_i32,
            ksf_simple_rnn_recurrent_projection_integer_q) == 0);
    TEST_CHECK(
        ksi_matrix_projection(
            8u, 3u, 3u, ksf_simple_rnn_input_q,
            ksf_simple_rnn_kernel_q,
            &ksf_simple_rnn_input_projection_requant,
            input_projection) == 0);
    TEST_CHECK(
        ksi_matrix_projection(
            8u, 3u, 3u, previous,
            ksf_simple_rnn_recurrent_kernel_q,
            &ksf_simple_rnn_recurrent_projection_requant,
            recurrent_projection) == 0);
    for (index = 0u; index < 24u; index++) {
        preactivation[index] = ksi_saturate_i8(
            (int32_t)input_projection[index] +
            recurrent_projection[index] +
            ksf_simple_rnn_bias_q[
                index % KSF_RECURRENT_UNITS]);
    }
    TEST_CHECK(
        ksi_check_dequantized(
            preactivation, pre_scale,
            ksf_simple_rnn_preactivation_f32_bits,
            24u, 0.08f) == 0);
    return 0;
}

static int ksi_gru_projection_layers(void)
{
    int8_t previous[24];
    int8_t input_projection[72];
    int8_t recurrent_projection[72];
    uint32_t index;

    ksi_recurrent_previous_hidden(ksf_gru_hidden_q, previous);
    TEST_CHECK(
        ksi_verify_dense(
            "gru_input_projection",
            8u, 3u, 9u, ksf_gru_input_q,
            ksf_gru_kernel_q, (const int32_t *)0,
            &ksf_gru_input_projection_requant, 0u,
            ksf_gru_input_projection_accum_i32,
            ksf_gru_input_projection_integer_q) == 0);
    TEST_CHECK(
        ksi_verify_dense(
            "gru_recurrent_projection",
            8u, 3u, 9u, previous,
            ksf_gru_recurrent_kernel_q,
            (const int32_t *)0,
            &ksf_gru_recurrent_projection_requant, 0u,
            ksf_gru_recurrent_projection_accum_i32,
            ksf_gru_recurrent_projection_integer_q) == 0);
    TEST_CHECK(
        ksi_matrix_projection(
            8u, 3u, 9u, ksf_gru_input_q,
            ksf_gru_kernel_q,
            &ksf_gru_input_projection_requant,
            input_projection) == 0);
    TEST_CHECK(
        ksi_matrix_projection(
            8u, 3u, 9u, previous,
            ksf_gru_recurrent_kernel_q,
            &ksf_gru_recurrent_projection_requant,
            recurrent_projection) == 0);
    for (index = 0u; index < 72u; index++) {
        input_projection[index] = ksi_saturate_i8(
            (int32_t)input_projection[index] +
            ksf_gru_input_bias_q[index % 9u]);
        recurrent_projection[index] = ksi_saturate_i8(
            (int32_t)recurrent_projection[index] +
            ksf_gru_recurrent_bias_q[index % 9u]);
    }
    TEST_CHECK(
        ksi_check_dequantized(
            input_projection,
            ksi_scale(ksf_gru_input_projection_qparam),
            ksf_gru_input_projection_f32_bits,
            72u, 0.10f) == 0);
    TEST_CHECK(
        ksi_check_dequantized(
            recurrent_projection,
            ksi_scale(ksf_gru_recurrent_projection_qparam),
            ksf_gru_recurrent_projection_f32_bits,
            72u, 0.06f) == 0);
    return 0;
}

static int ksi_lstm_projection_layers(void)
{
    int8_t previous[24];
    int8_t input_projection[96];
    int8_t recurrent_projection[96];

    ksi_recurrent_previous_hidden(ksf_lstm_hidden_q, previous);
    TEST_CHECK(
        ksi_verify_dense(
            "lstm_input_projection",
            8u, 3u, 12u, ksf_lstm_input_q,
            ksf_lstm_kernel_q, (const int32_t *)0,
            &ksf_lstm_input_projection_requant, 0u,
            ksf_lstm_input_projection_accum_i32,
            ksf_lstm_input_projection_integer_q) == 0);
    TEST_CHECK(
        ksi_verify_dense(
            "lstm_recurrent_projection",
            8u, 3u, 12u, previous,
            ksf_lstm_recurrent_kernel_q,
            (const int32_t *)0,
            &ksf_lstm_recurrent_projection_requant, 0u,
            ksf_lstm_recurrent_projection_accum_i32,
            ksf_lstm_recurrent_projection_integer_q) == 0);
    TEST_CHECK(
        ksi_matrix_projection(
            8u, 3u, 12u, ksf_lstm_input_q,
            ksf_lstm_kernel_q,
            &ksf_lstm_input_projection_requant,
            input_projection) == 0);
    TEST_CHECK(
        ksi_matrix_projection(
            8u, 3u, 12u, previous,
            ksf_lstm_recurrent_kernel_q,
            &ksf_lstm_recurrent_projection_requant,
            recurrent_projection) == 0);
    TEST_CHECK(
        ksi_check_dequantized(
            input_projection,
            ksi_scale(ksf_lstm_preactivation_qparam),
            ksf_lstm_input_projection_f32_bits,
            96u, 0.10f) == 0);
    TEST_CHECK(
        ksi_check_dequantized(
            recurrent_projection,
            ksi_scale(ksf_lstm_preactivation_qparam),
            ksf_lstm_recurrent_projection_f32_bits,
            96u, 0.06f) == 0);
    return 0;
}

static float ksi_add_scale_i8(const int8_t *src0,
                              float src0_scale,
                              const int8_t *src1,
                              float src1_scale,
                              uint32_t count)
{
    float maximum = 0.0f;
    uint32_t index;

    for (index = 0u; index < count; index++) {
        float value =
            (float)src0[index] * src0_scale +
            (float)src1[index] * src1_scale;
        float magnitude = test_abs_float(value);

        if (magnitude > maximum) {
            maximum = magnitude;
        }
    }
    return maximum == 0.0f ? 1.0f / 32768.0f
                           : maximum / 120.0f;
}

static float ksi_add_scale_i8_i32(const int8_t *src0,
                                  float src0_scale,
                                  const int32_t *src1,
                                  float src1_scale,
                                  uint32_t count)
{
    float maximum = 0.0f;
    uint32_t index;

    for (index = 0u; index < count; index++) {
        float value =
            (float)src0[index] * src0_scale +
            (float)src1[index] * src1_scale;
        float magnitude = test_abs_float(value);

        if (magnitude > maximum) {
            maximum = magnitude;
        }
    }
    return maximum == 0.0f ? 1.0f / 32768.0f
                           : maximum / 120.0f;
}

static int ksi_rescale_i8(const int8_t *input,
                          uint32_t count,
                          float input_scale,
                          float output_scale,
                          int8_t *output)
{
    int8_t zeros[KSI_MAX_VALUES] = {0};

    TEST_CHECK(count <= KSI_MAX_VALUES);
    return ksi_complex_add_rescale(
        1u, count, NPU_DTYPE_INT8, input, input_scale,
        NPU_DTYPE_INT8, zeros, 1.0f,
        NPU_DTYPE_INT8, output_scale, output);
}

static int ksi_rescale_i32(const int32_t *input,
                           uint32_t count,
                           float input_scale,
                           float output_scale,
                           int8_t *output)
{
    int32_t zeros[KSI_MAX_VALUES] = {0};

    TEST_CHECK(count <= KSI_MAX_VALUES);
    return ksi_complex_add_rescale(
        1u, count, NPU_DTYPE_INT32, input, input_scale,
        NPU_DTYPE_INT32, zeros, 1.0f,
        NPU_DTYPE_INT8, output_scale, output);
}

static int ksi_vector_sub(const int8_t *src0,
                          const int8_t *src1,
                          uint32_t count,
                          float scale,
                          int8_t *output)
{
    npu_vector_desc_t desc;
    uint64_t progress = UINT64_MAX;
    uint32_t index;

    TEST_CHECK(count <= KSI_MAX_VALUES);
    ksi_clear_scratch();
    (void)memcpy(&ksi_l1[KSI_SRC0_ADDR], src0, count);
    (void)memcpy(&ksi_l1[KSI_SRC1_ADDR], src1, count);
    (void)memset(&desc, 0, sizeof(desc));
    desc.rows = 1u;
    desc.length = count;
    desc.valid_length = count;
    desc.src0 = ksi_tensor(
        NPU_DTYPE_INT8, KSI_SRC0_ADDR, count, count, 0u);
    desc.src1 = ksi_tensor(
        NPU_DTYPE_INT8, KSI_SRC1_ADDR, count, count, 0u);
    desc.dst = ksi_tensor(
        NPU_DTYPE_INT8, KSI_DST_ADDR, count, count, 0u);
    desc.src0_scale_bits = ksi_float_bits(scale);
    desc.src1_scale_bits = ksi_float_bits(scale);
    desc.src2_scale_bits = ksi_float_bits(1.0f);
    desc.dst_scale_bits = ksi_float_bits(scale);
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    TEST_CHECK_STATUS(
        npu_vector_execute(
            &ksi_model, NPU_VECTOR_SUB, &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == count);
    for (index = 0u; index < count; index++) {
        int32_t value = 0;

        TEST_CHECK_STATUS(
            npu_tensor_read(
                &ksi_model, &desc.dst, 0u, 0u, index, &value),
            NPU_STATUS_SUCCESS);
        output[index] = (int8_t)value;
    }
    return 0;
}

static void ksi_extract_columns(const int8_t *source,
                                uint32_t rows,
                                uint32_t source_columns,
                                uint32_t offset,
                                uint32_t columns,
                                int8_t *destination)
{
    uint32_t row;
    uint32_t column;

    for (row = 0u; row < rows; row++) {
        for (column = 0u; column < columns; column++) {
            destination[row * columns + column] =
                source[row * source_columns + offset + column];
        }
    }
}

static void ksi_store_recurrent_step(int8_t *sequence,
                                     uint32_t step,
                                     const int8_t *values)
{
    uint32_t batch;
    uint32_t unit;

    for (batch = 0u; batch < KSF_RECURRENT_BATCH; batch++) {
        for (unit = 0u; unit < KSF_RECURRENT_UNITS; unit++) {
            sequence[
                ((size_t)batch * KSF_RECURRENT_STEPS + step) *
                    KSF_RECURRENT_UNITS +
                unit] =
                values[batch * KSF_RECURRENT_UNITS + unit];
        }
    }
}

static void ksi_load_recurrent_input_step(const int8_t *sequence,
                                          uint32_t step,
                                          int8_t *values)
{
    uint32_t batch;
    uint32_t feature;

    for (batch = 0u; batch < KSF_RECURRENT_BATCH; batch++) {
        for (feature = 0u;
             feature < KSF_RECURRENT_FEATURES; feature++) {
            values[batch * KSF_RECURRENT_FEATURES + feature] =
                sequence[
                    ((size_t)batch * KSF_RECURRENT_STEPS + step) *
                        KSF_RECURRENT_FEATURES +
                    feature];
        }
    }
}

static int ksi_simple_rnn_activation_layer(void)
{
    int8_t hidden[24];

    TEST_CHECK(
        ksi_complex_activation(
            8u, 3u, ksf_simple_rnn_preactivation_q,
            ksi_scale(ksf_simple_rnn_preactivation_qparam),
            NPU_FUNC_TANH,
            ksi_scale(ksf_simple_rnn_hidden_qparam),
            hidden) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            hidden, ksf_simple_rnn_hidden_q, 24u, 1) == 0);
    return 0;
}

static int ksi_simple_rnn_full_network(void)
{
    int8_t hidden[6] = {0};
    int8_t input_step[6];
    int8_t input_projection[6];
    int8_t recurrent_projection[6];
    int8_t sum[6];
    int8_t bias[6];
    int8_t preactivation[6];
    int8_t sequence[24];
    float pre_scale =
        ksi_scale(ksf_simple_rnn_preactivation_qparam);
    float hidden_scale =
        ksi_scale(ksf_simple_rnn_hidden_qparam);
    uint32_t step;
    uint32_t index;

    for (index = 0u; index < 6u; index++) {
        bias[index] = ksi_saturate_i8(
            ksf_simple_rnn_bias_q[index % 3u]);
    }
    for (step = 0u; step < KSF_RECURRENT_STEPS; step++) {
        ksi_load_recurrent_input_step(
            ksf_simple_rnn_input_q, step, input_step);
        TEST_CHECK(
            ksi_matrix_projection(
                2u, 3u, 3u, input_step,
                ksf_simple_rnn_kernel_q,
                &ksf_simple_rnn_input_projection_requant,
                input_projection) == 0);
        TEST_CHECK(
            ksi_matrix_projection(
                2u, 3u, 3u, hidden,
                ksf_simple_rnn_recurrent_kernel_q,
                &ksf_simple_rnn_recurrent_projection_requant,
                recurrent_projection) == 0);
        TEST_CHECK(
            ksi_complex_add_rescale(
                2u, 3u, NPU_DTYPE_INT8,
                input_projection, pre_scale,
                NPU_DTYPE_INT8,
                recurrent_projection, pre_scale,
                NPU_DTYPE_INT8, pre_scale, sum) == 0);
        TEST_CHECK(
            ksi_complex_add_rescale(
                2u, 3u, NPU_DTYPE_INT8, sum, pre_scale,
                NPU_DTYPE_INT8, bias, pre_scale,
                NPU_DTYPE_INT8, pre_scale,
                preactivation) == 0);
        TEST_CHECK(
            ksi_complex_activation(
                2u, 3u, preactivation, pre_scale,
                NPU_FUNC_TANH, hidden_scale, hidden) == 0);
        ksi_store_recurrent_step(sequence, step, hidden);
    }
    TEST_CHECK(
        ksi_check_q_close(
            sequence, ksf_simple_rnn_hidden_q, 24u, 10) == 0);
    TEST_CHECK(
        ksi_check_dequantized(
            sequence, hidden_scale,
            ksf_simple_rnn_hidden_f32_bits,
            24u, 0.10f) == 0);
    TEST_CHECK(
        ksi_application_mse(
            sequence, hidden_scale,
            ksi_recurrent_application_target_bits,
            KSI_RECURRENT_VALUE_COUNT) <
        ksi_float_from_bits(
            KSF_SIMPLE_RNN_HISTORY_BASELINE_MSE_F32_BITS));
    TEST_CHECK(
        ksi_has_recurrent_history_response(
            sequence, hidden_scale,
            ksi_recurrent_application_target_bits) != 0);
#ifdef KSI_MODEL_INFER_STANDALONE
    (void)memcpy(
        ksi_runner_simple_rnn_output, sequence, sizeof(sequence));
#endif
    return 0;
}

static int ksi_lstm_activation_layers(void)
{
    int8_t input_pre[24];
    int8_t forget_pre[24];
    int8_t candidate_pre[24];
    int8_t output_pre[24];
    int8_t result[24];
    float pre_scale =
        ksi_scale(ksf_lstm_preactivation_qparam);

    ksi_extract_columns(
        ksf_lstm_preactivation_q, 8u, 12u,
        KSF_LSTM_GATE_I_OFFSET, 3u, input_pre);
    ksi_extract_columns(
        ksf_lstm_preactivation_q, 8u, 12u,
        KSF_LSTM_GATE_F_OFFSET, 3u, forget_pre);
    ksi_extract_columns(
        ksf_lstm_preactivation_q, 8u, 12u,
        KSF_LSTM_GATE_C_OFFSET, 3u, candidate_pre);
    ksi_extract_columns(
        ksf_lstm_preactivation_q, 8u, 12u,
        KSF_LSTM_GATE_O_OFFSET, 3u, output_pre);

    TEST_CHECK(
        ksi_complex_activation(
            8u, 3u, input_pre, pre_scale,
            NPU_FUNC_SIGMOID,
            ksi_scale(ksf_lstm_input_gate_qparam),
            result) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            result, ksf_lstm_input_gate_q, 24u, 1) == 0);
    TEST_CHECK(
        ksi_complex_activation(
            8u, 3u, forget_pre, pre_scale,
            NPU_FUNC_SIGMOID,
            ksi_scale(ksf_lstm_forget_gate_qparam),
            result) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            result, ksf_lstm_forget_gate_q, 24u, 1) == 0);
    TEST_CHECK(
        ksi_complex_activation(
            8u, 3u, candidate_pre, pre_scale,
            NPU_FUNC_TANH,
            ksi_scale(ksf_lstm_candidate_qparam),
            result) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            result, ksf_lstm_candidate_q, 24u, 1) == 0);
    TEST_CHECK(
        ksi_complex_activation(
            8u, 3u, output_pre, pre_scale,
            NPU_FUNC_SIGMOID,
            ksi_scale(ksf_lstm_output_gate_qparam),
            result) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            result, ksf_lstm_output_gate_q, 24u, 1) == 0);
    return 0;
}

static int ksi_add_i8_dynamic(const int8_t *src0,
                              float src0_scale,
                              const int8_t *src1,
                              float src1_scale,
                              uint32_t count,
                              int8_t *output,
                              float *output_scale)
{
    *output_scale = ksi_add_scale_i8(
        src0, src0_scale, src1, src1_scale, count);
    return ksi_complex_add_rescale(
        1u, count, NPU_DTYPE_INT8, src0, src0_scale,
        NPU_DTYPE_INT8, src1, src1_scale,
        NPU_DTYPE_INT8, *output_scale, output);
}

static int ksi_add_i8_i32_dynamic(const int8_t *src0,
                                  float src0_scale,
                                  const int32_t *src1,
                                  float src1_scale,
                                  uint32_t count,
                                  int8_t *output,
                                  float *output_scale)
{
    *output_scale = ksi_add_scale_i8_i32(
        src0, src0_scale, src1, src1_scale, count);
    return ksi_complex_add_rescale(
        1u, count, NPU_DTYPE_INT8, src0, src0_scale,
        NPU_DTYPE_INT32, src1, src1_scale,
        NPU_DTYPE_INT8, *output_scale, output);
}

static int ksi_product_sum(const int32_t *src0,
                           float src0_scale,
                           const int32_t *src1,
                           float src1_scale,
                           uint32_t count,
                           float output_scale,
                           int8_t *output)
{
    return ksi_complex_add_rescale(
        1u, count, NPU_DTYPE_INT32, src0, src0_scale,
        NPU_DTYPE_INT32, src1, src1_scale,
        NPU_DTYPE_INT8, output_scale, output);
}

static int ksi_gru_gate_layers(void)
{
    int8_t x_z[24];
    int8_t x_r[24];
    int8_t x_h[24];
    int8_t h_z[24];
    int8_t h_r[24];
    int8_t h_h[24];
    int8_t pre[24];
    int8_t update[24];
    int8_t reset[24];
    int8_t reset_127[24];
    int32_t reset_product[24];
    int8_t candidate_pre[24];
    int8_t candidate[24];
    float pre_scale;
    float candidate_pre_scale;
    float x_scale =
        ksi_scale(ksf_gru_input_projection_qparam);
    float h_scale =
        ksi_scale(ksf_gru_recurrent_projection_qparam);

    ksi_extract_columns(
        ksf_gru_input_projection_q, 8u, 9u,
        KSF_GRU_GATE_Z_OFFSET, 3u, x_z);
    ksi_extract_columns(
        ksf_gru_input_projection_q, 8u, 9u,
        KSF_GRU_GATE_R_OFFSET, 3u, x_r);
    ksi_extract_columns(
        ksf_gru_input_projection_q, 8u, 9u,
        KSF_GRU_GATE_H_OFFSET, 3u, x_h);
    ksi_extract_columns(
        ksf_gru_recurrent_projection_q, 8u, 9u,
        KSF_GRU_GATE_Z_OFFSET, 3u, h_z);
    ksi_extract_columns(
        ksf_gru_recurrent_projection_q, 8u, 9u,
        KSF_GRU_GATE_R_OFFSET, 3u, h_r);
    ksi_extract_columns(
        ksf_gru_recurrent_projection_q, 8u, 9u,
        KSF_GRU_GATE_H_OFFSET, 3u, h_h);

    TEST_CHECK(
        ksi_add_i8_dynamic(
            x_z, x_scale, h_z, h_scale, 24u,
            pre, &pre_scale) == 0);
    TEST_CHECK(
        ksi_complex_activation(
            8u, 3u, pre, pre_scale,
            NPU_FUNC_SIGMOID,
            ksi_scale(ksf_gru_update_gate_qparam),
            update) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            update, ksf_gru_update_gate_q, 24u, 2) == 0);

    TEST_CHECK(
        ksi_add_i8_dynamic(
            x_r, x_scale, h_r, h_scale, 24u,
            pre, &pre_scale) == 0);
    TEST_CHECK(
        ksi_complex_activation(
            8u, 3u, pre, pre_scale,
            NPU_FUNC_SIGMOID,
            ksi_scale(ksf_gru_reset_gate_qparam),
            reset) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            reset, ksf_gru_reset_gate_q, 24u, 2) == 0);

    TEST_CHECK(
        ksi_rescale_i8(
            reset, 24u,
            ksi_scale(ksf_gru_reset_gate_qparam),
            KSI_GATE_SCALE, reset_127) == 0);
    TEST_CHECK(
        ksi_vector_mul(
            reset_127, h_h, 24u,
            KSI_GATE_SCALE, h_scale,
            reset_product) == 0);
    TEST_CHECK(
        ksi_add_i8_i32_dynamic(
            x_h, x_scale, reset_product,
            KSI_GATE_SCALE * h_scale, 24u,
            candidate_pre, &candidate_pre_scale) == 0);
    TEST_CHECK(
        ksi_complex_activation(
            8u, 3u, candidate_pre,
            candidate_pre_scale, NPU_FUNC_TANH,
            ksi_scale(ksf_gru_candidate_qparam),
            candidate) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            candidate, ksf_gru_candidate_q, 24u, 3) == 0);
    return 0;
}

static int ksi_gru_full_network(void)
{
    int8_t hidden[6] = {0};
    int8_t input_step[6];
    int8_t input_projection[18];
    int8_t recurrent_projection[18];
    int8_t input_bias[18];
    int8_t recurrent_bias[18];
    int8_t projected_x[18];
    int8_t projected_h[18];
    int8_t x_z[6];
    int8_t x_r[6];
    int8_t x_h[6];
    int8_t h_z[6];
    int8_t h_r[6];
    int8_t h_h[6];
    int8_t pre[6];
    int8_t update[6];
    int8_t reset[6];
    int8_t reset_127[6];
    int8_t update_127[6];
    int8_t one[6];
    int8_t one_minus_update[6];
    int32_t reset_product[6];
    int8_t candidate_pre[6];
    int8_t candidate[6];
    int32_t old_product[6];
    int32_t candidate_product[6];
    int8_t hidden_sequence[24];
    int8_t update_sequence[24];
    int8_t reset_sequence[24];
    int8_t candidate_sequence[24];
    float x_scale =
        ksi_scale(ksf_gru_input_projection_qparam);
    float h_projection_scale =
        ksi_scale(ksf_gru_recurrent_projection_qparam);
    float hidden_scale = ksi_scale(ksf_gru_hidden_qparam);
    float candidate_scale =
        ksi_scale(ksf_gru_candidate_qparam);
    float pre_scale;
    uint32_t step;
    uint32_t index;

    for (index = 0u; index < 18u; index++) {
        input_bias[index] = ksi_saturate_i8(
            ksf_gru_input_bias_q[index % 9u]);
        recurrent_bias[index] = ksi_saturate_i8(
            ksf_gru_recurrent_bias_q[index % 9u]);
    }
    for (index = 0u; index < 6u; index++) {
        one[index] = INT8_MAX;
    }

    for (step = 0u; step < KSF_RECURRENT_STEPS; step++) {
        ksi_load_recurrent_input_step(
            ksf_gru_input_q, step, input_step);
        TEST_CHECK(
            ksi_matrix_projection(
                2u, 3u, 9u, input_step,
                ksf_gru_kernel_q,
                &ksf_gru_input_projection_requant,
                input_projection) == 0);
        TEST_CHECK(
            ksi_matrix_projection(
                2u, 3u, 9u, hidden,
                ksf_gru_recurrent_kernel_q,
                &ksf_gru_recurrent_projection_requant,
                recurrent_projection) == 0);
        TEST_CHECK(
            ksi_complex_add_rescale(
                2u, 9u, NPU_DTYPE_INT8,
                input_projection, x_scale,
                NPU_DTYPE_INT8, input_bias, x_scale,
                NPU_DTYPE_INT8, x_scale,
                projected_x) == 0);
        TEST_CHECK(
            ksi_complex_add_rescale(
                2u, 9u, NPU_DTYPE_INT8,
                recurrent_projection, h_projection_scale,
                NPU_DTYPE_INT8, recurrent_bias,
                h_projection_scale,
                NPU_DTYPE_INT8, h_projection_scale,
                projected_h) == 0);

        ksi_extract_columns(
            projected_x, 2u, 9u,
            KSF_GRU_GATE_Z_OFFSET, 3u, x_z);
        ksi_extract_columns(
            projected_x, 2u, 9u,
            KSF_GRU_GATE_R_OFFSET, 3u, x_r);
        ksi_extract_columns(
            projected_x, 2u, 9u,
            KSF_GRU_GATE_H_OFFSET, 3u, x_h);
        ksi_extract_columns(
            projected_h, 2u, 9u,
            KSF_GRU_GATE_Z_OFFSET, 3u, h_z);
        ksi_extract_columns(
            projected_h, 2u, 9u,
            KSF_GRU_GATE_R_OFFSET, 3u, h_r);
        ksi_extract_columns(
            projected_h, 2u, 9u,
            KSF_GRU_GATE_H_OFFSET, 3u, h_h);

        TEST_CHECK(
            ksi_add_i8_dynamic(
                x_z, x_scale, h_z, h_projection_scale,
                6u, pre, &pre_scale) == 0);
        TEST_CHECK(
            ksi_complex_activation(
                2u, 3u, pre, pre_scale,
                NPU_FUNC_SIGMOID,
                ksi_scale(ksf_gru_update_gate_qparam),
                update) == 0);
        TEST_CHECK(
            ksi_add_i8_dynamic(
                x_r, x_scale, h_r, h_projection_scale,
                6u, pre, &pre_scale) == 0);
        TEST_CHECK(
            ksi_complex_activation(
                2u, 3u, pre, pre_scale,
                NPU_FUNC_SIGMOID,
                ksi_scale(ksf_gru_reset_gate_qparam),
                reset) == 0);
        TEST_CHECK(
            ksi_rescale_i8(
                reset, 6u,
                ksi_scale(ksf_gru_reset_gate_qparam),
                KSI_GATE_SCALE, reset_127) == 0);
        TEST_CHECK(
            ksi_vector_mul(
                reset_127, h_h, 6u, KSI_GATE_SCALE,
                h_projection_scale, reset_product) == 0);
        TEST_CHECK(
            ksi_add_i8_i32_dynamic(
                x_h, x_scale, reset_product,
                KSI_GATE_SCALE * h_projection_scale,
                6u, candidate_pre, &pre_scale) == 0);
        TEST_CHECK(
            ksi_complex_activation(
                2u, 3u, candidate_pre, pre_scale,
                NPU_FUNC_TANH, candidate_scale,
                candidate) == 0);

        TEST_CHECK(
            ksi_rescale_i8(
                update, 6u,
                ksi_scale(ksf_gru_update_gate_qparam),
                KSI_GATE_SCALE, update_127) == 0);
        TEST_CHECK(
            ksi_vector_sub(
                one, update_127, 6u,
                KSI_GATE_SCALE, one_minus_update) == 0);
        TEST_CHECK(
            ksi_vector_mul(
                update_127, hidden, 6u,
                KSI_GATE_SCALE, hidden_scale,
                old_product) == 0);
        TEST_CHECK(
            ksi_vector_mul(
                one_minus_update, candidate, 6u,
                KSI_GATE_SCALE, candidate_scale,
                candidate_product) == 0);
        TEST_CHECK(
            ksi_product_sum(
                old_product, KSI_GATE_SCALE * hidden_scale,
                candidate_product,
                KSI_GATE_SCALE * candidate_scale,
                6u, hidden_scale, hidden) == 0);

        ksi_store_recurrent_step(
            hidden_sequence, step, hidden);
        ksi_store_recurrent_step(
            update_sequence, step, update);
        ksi_store_recurrent_step(
            reset_sequence, step, reset);
        ksi_store_recurrent_step(
            candidate_sequence, step, candidate);
    }
    TEST_CHECK(
        ksi_check_q_close(
            update_sequence, ksf_gru_update_gate_q,
            24u, 8) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            reset_sequence, ksf_gru_reset_gate_q,
            24u, 8) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            candidate_sequence, ksf_gru_candidate_q,
            24u, 15) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            hidden_sequence, ksf_gru_hidden_q,
            24u, 18) == 0);
    TEST_CHECK(
        ksi_check_dequantized(
            hidden_sequence, hidden_scale,
            ksf_gru_hidden_f32_bits, 24u, 0.12f) == 0);
    TEST_CHECK(
        ksi_application_mse(
            hidden_sequence, hidden_scale,
            ksi_recurrent_application_target_bits,
            KSI_RECURRENT_VALUE_COUNT) <
        ksi_float_from_bits(
            KSF_GRU_HISTORY_BASELINE_MSE_F32_BITS));
    TEST_CHECK(
        ksi_has_recurrent_history_response(
            hidden_sequence, hidden_scale,
            ksi_recurrent_application_target_bits) != 0);
#ifdef KSI_MODEL_INFER_STANDALONE
    (void)memcpy(
        ksi_runner_gru_output, hidden_sequence,
        sizeof(hidden_sequence));
#endif
    return 0;
}

static int ksi_lstm_full_network(void)
{
    int8_t hidden[6] = {0};
    int8_t cell[6] = {0};
    int8_t input_step[6];
    int8_t input_projection[24];
    int8_t recurrent_projection[24];
    int8_t sum[24];
    int8_t bias[24];
    int8_t preactivation[24];
    int8_t input_pre[6];
    int8_t forget_pre[6];
    int8_t candidate_pre[6];
    int8_t output_pre[6];
    int8_t input_gate[6];
    int8_t forget_gate[6];
    int8_t candidate[6];
    int8_t output_gate[6];
    int8_t input_gate_127[6];
    int8_t forget_gate_127[6];
    int8_t output_gate_127[6];
    int32_t old_cell_product[6];
    int32_t candidate_product[6];
    int8_t tanh_cell[6];
    int32_t hidden_product[6];
    int8_t input_gate_sequence[24];
    int8_t forget_gate_sequence[24];
    int8_t candidate_sequence[24];
    int8_t output_gate_sequence[24];
    int8_t cell_sequence[24];
    int8_t hidden_sequence[24];
    float pre_scale =
        ksi_scale(ksf_lstm_preactivation_qparam);
    float input_gate_scale =
        ksi_scale(ksf_lstm_input_gate_qparam);
    float forget_gate_scale =
        ksi_scale(ksf_lstm_forget_gate_qparam);
    float candidate_scale =
        ksi_scale(ksf_lstm_candidate_qparam);
    float output_gate_scale =
        ksi_scale(ksf_lstm_output_gate_qparam);
    float cell_scale = ksi_scale(ksf_lstm_cell_qparam);
    float hidden_scale = ksi_scale(ksf_lstm_hidden_qparam);
    uint32_t step;
    uint32_t index;

    for (index = 0u; index < 24u; index++) {
        bias[index] = ksi_saturate_i8(
            ksf_lstm_bias_q[index % 12u]);
    }
    for (step = 0u; step < KSF_RECURRENT_STEPS; step++) {
        ksi_load_recurrent_input_step(
            ksf_lstm_input_q, step, input_step);
        TEST_CHECK(
            ksi_matrix_projection(
                2u, 3u, 12u, input_step,
                ksf_lstm_kernel_q,
                &ksf_lstm_input_projection_requant,
                input_projection) == 0);
        TEST_CHECK(
            ksi_matrix_projection(
                2u, 3u, 12u, hidden,
                ksf_lstm_recurrent_kernel_q,
                &ksf_lstm_recurrent_projection_requant,
                recurrent_projection) == 0);
        TEST_CHECK(
            ksi_complex_add_rescale(
                2u, 12u, NPU_DTYPE_INT8,
                input_projection, pre_scale,
                NPU_DTYPE_INT8, recurrent_projection,
                pre_scale, NPU_DTYPE_INT8, pre_scale,
                sum) == 0);
        TEST_CHECK(
            ksi_complex_add_rescale(
                2u, 12u, NPU_DTYPE_INT8, sum, pre_scale,
                NPU_DTYPE_INT8, bias, pre_scale,
                NPU_DTYPE_INT8, pre_scale,
                preactivation) == 0);
        ksi_extract_columns(
            preactivation, 2u, 12u,
            KSF_LSTM_GATE_I_OFFSET, 3u, input_pre);
        ksi_extract_columns(
            preactivation, 2u, 12u,
            KSF_LSTM_GATE_F_OFFSET, 3u, forget_pre);
        ksi_extract_columns(
            preactivation, 2u, 12u,
            KSF_LSTM_GATE_C_OFFSET, 3u, candidate_pre);
        ksi_extract_columns(
            preactivation, 2u, 12u,
            KSF_LSTM_GATE_O_OFFSET, 3u, output_pre);
        TEST_CHECK(
            ksi_complex_activation(
                2u, 3u, input_pre, pre_scale,
                NPU_FUNC_SIGMOID, input_gate_scale,
                input_gate) == 0);
        TEST_CHECK(
            ksi_complex_activation(
                2u, 3u, forget_pre, pre_scale,
                NPU_FUNC_SIGMOID, forget_gate_scale,
                forget_gate) == 0);
        TEST_CHECK(
            ksi_complex_activation(
                2u, 3u, candidate_pre, pre_scale,
                NPU_FUNC_TANH, candidate_scale,
                candidate) == 0);
        TEST_CHECK(
            ksi_complex_activation(
                2u, 3u, output_pre, pre_scale,
                NPU_FUNC_SIGMOID, output_gate_scale,
                output_gate) == 0);

        TEST_CHECK(
            ksi_rescale_i8(
                input_gate, 6u, input_gate_scale,
                KSI_GATE_SCALE, input_gate_127) == 0);
        TEST_CHECK(
            ksi_rescale_i8(
                forget_gate, 6u, forget_gate_scale,
                KSI_GATE_SCALE, forget_gate_127) == 0);
        TEST_CHECK(
            ksi_vector_mul(
                forget_gate_127, cell, 6u,
                KSI_GATE_SCALE, cell_scale,
                old_cell_product) == 0);
        TEST_CHECK(
            ksi_vector_mul(
                input_gate_127, candidate, 6u,
                KSI_GATE_SCALE, candidate_scale,
                candidate_product) == 0);
        TEST_CHECK(
            ksi_product_sum(
                old_cell_product,
                KSI_GATE_SCALE * cell_scale,
                candidate_product,
                KSI_GATE_SCALE * candidate_scale,
                6u, cell_scale, cell) == 0);
        TEST_CHECK(
            ksi_complex_activation(
                2u, 3u, cell, cell_scale,
                NPU_FUNC_TANH, KSI_GATE_SCALE,
                tanh_cell) == 0);
        TEST_CHECK(
            ksi_rescale_i8(
                output_gate, 6u, output_gate_scale,
                KSI_GATE_SCALE, output_gate_127) == 0);
        TEST_CHECK(
            ksi_vector_mul(
                output_gate_127, tanh_cell, 6u,
                KSI_GATE_SCALE, KSI_GATE_SCALE,
                hidden_product) == 0);
        TEST_CHECK(
            ksi_rescale_i32(
                hidden_product, 6u,
                KSI_GATE_SCALE * KSI_GATE_SCALE,
                hidden_scale, hidden) == 0);

        ksi_store_recurrent_step(
            input_gate_sequence, step, input_gate);
        ksi_store_recurrent_step(
            forget_gate_sequence, step, forget_gate);
        ksi_store_recurrent_step(
            candidate_sequence, step, candidate);
        ksi_store_recurrent_step(
            output_gate_sequence, step, output_gate);
        ksi_store_recurrent_step(cell_sequence, step, cell);
        ksi_store_recurrent_step(hidden_sequence, step, hidden);
    }

    TEST_CHECK(
        ksi_check_q_close(
            input_gate_sequence, ksf_lstm_input_gate_q,
            24u, 8) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            forget_gate_sequence, ksf_lstm_forget_gate_q,
            24u, 8) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            candidate_sequence, ksf_lstm_candidate_q,
            24u, 15) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            output_gate_sequence, ksf_lstm_output_gate_q,
            24u, 8) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            cell_sequence, ksf_lstm_cell_q, 24u, 18) == 0);
    TEST_CHECK(
        ksi_check_q_close(
            hidden_sequence, ksf_lstm_hidden_q, 24u, 18) == 0);
    TEST_CHECK(
        ksi_check_dequantized(
            hidden_sequence, hidden_scale,
            ksf_lstm_hidden_f32_bits, 24u, 0.08f) == 0);
    TEST_CHECK(
        ksi_application_mse(
            hidden_sequence, hidden_scale,
            ksi_recurrent_application_target_bits,
            KSI_RECURRENT_VALUE_COUNT) <
        ksi_float_from_bits(
            KSF_LSTM_HISTORY_BASELINE_MSE_F32_BITS));
    TEST_CHECK(
        ksi_has_recurrent_history_response(
            hidden_sequence, hidden_scale,
            ksi_recurrent_application_target_bits) != 0);
#ifdef KSI_MODEL_INFER_STANDALONE
    (void)memcpy(
        ksi_runner_lstm_output, hidden_sequence,
        sizeof(hidden_sequence));
#endif
    return 0;
}

static int ksi_training_metadata(void)
{
    float tflite_error;
    float tflite_limit;

    TEST_CHECK(KSF_TRANSFORMER_TRAIN_STEPS > 0u);
    TEST_CHECK(KSF_SIMPLE_RNN_TRAIN_STEPS > 0u);
    TEST_CHECK(KSF_GRU_TRAIN_STEPS > 0u);
    TEST_CHECK(KSF_LSTM_TRAIN_STEPS > 0u);
    TEST_CHECK(
        ksi_float_from_bits(
            KSF_TRANSFORMER_TRAIN_FINAL_LOSS_F32_BITS) <
        ksi_float_from_bits(
            KSF_TRANSFORMER_TRAIN_INITIAL_LOSS_F32_BITS));
    TEST_CHECK(
        ksi_float_from_bits(
            KSF_SIMPLE_RNN_TRAIN_FINAL_LOSS_F32_BITS) <
        ksi_float_from_bits(
            KSF_SIMPLE_RNN_TRAIN_INITIAL_LOSS_F32_BITS));
    TEST_CHECK(
        ksi_float_from_bits(
            KSF_GRU_TRAIN_FINAL_LOSS_F32_BITS) <
        ksi_float_from_bits(
            KSF_GRU_TRAIN_INITIAL_LOSS_F32_BITS));
    TEST_CHECK(
        ksi_float_from_bits(
            KSF_LSTM_TRAIN_FINAL_LOSS_F32_BITS) <
        ksi_float_from_bits(
            KSF_LSTM_TRAIN_INITIAL_LOSS_F32_BITS));
    TEST_CHECK(KSF_TRANSFORMER_TRAINING_SAMPLE_COUNT >= 9u);
    TEST_CHECK(KSF_RECURRENT_TRAINING_SAMPLE_COUNT == 32u);
    TEST_CHECK(KSF_RECURRENT_FIXED_SAMPLE_COUNT == 2u);
    TEST_CHECK(
        ksi_float_from_bits(
            KSF_TRANSFORMER_TRAIN_ACCURACY_F32_BITS) == 1.0f);
    TEST_CHECK(
        ksi_float_from_bits(
            KSF_TRANSFORMER_FIXED_ACCURACY_F32_BITS) == 1.0f);
    TEST_CHECK(
        ksi_float_from_bits(
            KSF_SIMPLE_RNN_APPLICATION_MSE_F32_BITS) <
        ksi_float_from_bits(
            KSF_SIMPLE_RNN_HISTORY_BASELINE_MSE_F32_BITS));
    TEST_CHECK(
        ksi_float_from_bits(
            KSF_GRU_APPLICATION_MSE_F32_BITS) <
        ksi_float_from_bits(
            KSF_GRU_HISTORY_BASELINE_MSE_F32_BITS));
    TEST_CHECK(
        ksi_float_from_bits(
            KSF_LSTM_APPLICATION_MSE_F32_BITS) <
        ksi_float_from_bits(
            KSF_LSTM_HISTORY_BASELINE_MSE_F32_BITS));
    TEST_CHECK(
        ksi_float_from_bits(
            KSF_SIMPLE_RNN_FINAL_STEP_MSE_F32_BITS) <
        ksi_float_from_bits(
            KSF_RECURRENT_SAME_CURRENT_BASELINE_MSE_F32_BITS));
    TEST_CHECK(
        ksi_float_from_bits(
            KSF_GRU_FINAL_STEP_MSE_F32_BITS) <
        ksi_float_from_bits(
            KSF_RECURRENT_SAME_CURRENT_BASELINE_MSE_F32_BITS));
    TEST_CHECK(
        ksi_float_from_bits(
            KSF_LSTM_FINAL_STEP_MSE_F32_BITS) <
        ksi_float_from_bits(
            KSF_RECURRENT_SAME_CURRENT_BASELINE_MSE_F32_BITS));
    TEST_CHECK(KSF_TRANSFORMER_TFLITE_STATUS == 1u);
    TEST_CHECK(
        KSF_SIMPLE_RNN_TFLITE_STATUS == 1u ||
        KSF_SIMPLE_RNN_TFLITE_STATUS == 2u);
    TEST_CHECK(
        KSF_GRU_TFLITE_STATUS == 1u ||
        KSF_GRU_TFLITE_STATUS == 2u);
    TEST_CHECK(
        KSF_LSTM_TFLITE_STATUS == 1u ||
        KSF_LSTM_TFLITE_STATUS == 2u);

    /*
     * The two fixed telemetry samples have the same current measurement
     * at their final step but different histories.  Their final targets
     * must therefore differ when the recurrent state is used.
     */
    TEST_CHECK(
        ksf_simple_rnn_input_f32_bits[9] ==
        ksf_simple_rnn_input_f32_bits[21]);
    TEST_CHECK(
        ksf_simple_rnn_input_f32_bits[10] ==
        ksf_simple_rnn_input_f32_bits[22]);
    TEST_CHECK(
        ksf_simple_rnn_input_f32_bits[11] ==
        ksf_simple_rnn_input_f32_bits[23]);
    TEST_CHECK(
        test_abs_float(
            ksi_float_from_bits(
                ksi_recurrent_application_target_bits[9]) -
            ksi_float_from_bits(
                ksi_recurrent_application_target_bits[21])) >
        0.01f);

#define KSI_CHECK_TFLITE_ERROR(network)                              \
    do {                                                             \
        tflite_error = ksi_float_from_bits(                           \
            KSF_##network##_TFLITE_MAX_ABS_ERROR_F32_BITS);          \
        tflite_limit = ksi_float_from_bits(                           \
            KSF_##network##_TFLITE_MAX_ABS_ERROR_LIMIT_F32_BITS);    \
        TEST_CHECK(isfinite(tflite_error));                           \
        TEST_CHECK(isfinite(tflite_limit));                           \
        TEST_CHECK(tflite_error >= 0.0f);                             \
        TEST_CHECK(tflite_limit > 0.0f);                              \
        TEST_CHECK(tflite_error <= tflite_limit);                     \
    } while (0)

    KSI_CHECK_TFLITE_ERROR(TRANSFORMER);
    KSI_CHECK_TFLITE_ERROR(SIMPLE_RNN);
    KSI_CHECK_TFLITE_ERROR(GRU);
    KSI_CHECK_TFLITE_ERROR(LSTM);

#undef KSI_CHECK_TFLITE_ERROR

    return 0;
}

int test_keras_sequence_inference(void)
{
    TEST_CHECK(ksi_init() == 0);
    TEST_CHECK(ksi_training_metadata() == 0);
    TEST_CHECK(ksi_transformer_dense_layers() == 0);
    TEST_CHECK(ksi_transformer_operator_layers() == 0);
    TEST_CHECK(ksi_transformer_full_network() == 0);
    TEST_CHECK(ksi_simple_rnn_projection_layers() == 0);
    TEST_CHECK(ksi_simple_rnn_activation_layer() == 0);
    TEST_CHECK(ksi_simple_rnn_full_network() == 0);
    TEST_CHECK(ksi_gru_projection_layers() == 0);
    TEST_CHECK(ksi_gru_gate_layers() == 0);
    TEST_CHECK(ksi_gru_full_network() == 0);
    TEST_CHECK(ksi_lstm_projection_layers() == 0);
    TEST_CHECK(ksi_lstm_activation_layers() == 0);
    TEST_CHECK(ksi_lstm_full_network() == 0);
    return 0;
}

#ifdef KSI_MODEL_INFER_STANDALONE
typedef struct {
    const char *name;
    const uint32_t *input_bits;
    const uint32_t *keras_output_bits;
    const int8_t *c_output;
    ksf_qparam_t output_qparam;
    uint32_t train_steps;
    uint32_t train_initial_mse_bits;
    uint32_t train_final_mse_bits;
    uint32_t keras_mse_bits;
    uint32_t keras_final_step_mse_bits;
    uint32_t history_baseline_mse_bits;
    uint32_t tflite_status;
    uint32_t tflite_error_bits;
    uint32_t tflite_error_limit_bits;
} ksi_runner_recurrent_config_t;

static const char *ksi_runner_tflite_status(uint32_t status)
{
    switch (status) {
    case 0u:
        return "skipped";
    case 1u:
        return "strict built-in integer conversion";
    case 2u:
        return "built-in or Select TF Ops fallback";
    case 3u:
        return "conversion unavailable";
    default:
        return "unknown";
    }
}

static double ksi_runner_dequantize(
    int8_t value, ksf_qparam_t qparam)
{
    return ((double)value - (double)qparam.zero_point) *
           (double)ksi_scale(qparam);
}

static void ksi_runner_print_f32_vector(
    const uint32_t *bits, uint32_t count)
{
    uint32_t index;

    (void)printf("[");
    for (index = 0u; index < count; index++) {
        (void)printf(
            "%s%.7f", index == 0u ? "" : ", ",
            (double)ksi_float_from_bits(bits[index]));
    }
    (void)printf("]");
}

static void ksi_runner_print_i8_vector(
    const int8_t *values, uint32_t count,
    ksf_qparam_t qparam)
{
    uint32_t index;

    (void)printf("[");
    for (index = 0u; index < count; index++) {
        (void)printf(
            "%s%.7f", index == 0u ? "" : ", ",
            ksi_runner_dequantize(values[index], qparam));
    }
    (void)printf("]");
}

static void ksi_runner_print_raw_i8_vector(
    const int8_t *values, uint32_t count)
{
    uint32_t index;

    (void)printf("[");
    for (index = 0u; index < count; index++) {
        (void)printf(
            "%s%d", index == 0u ? "" : ", ",
            (int)values[index]);
    }
    (void)printf("]");
}

static void ksi_runner_print_transformer(void)
{
    static const char *const texts[KSF_TRANSFORMER_BATCH] = {
        KSF_TRANSFORMER_FIXED_SAMPLE_0_TEXT,
        KSF_TRANSFORMER_FIXED_SAMPLE_1_TEXT
    };
    static const char *const class_names[
        KSF_TRANSFORMER_CLASSES] = {
        KSF_TRANSFORMER_CLASS_0_NAME,
        KSF_TRANSFORMER_CLASS_1_NAME,
        KSF_TRANSFORMER_CLASS_2_NAME
    };
    uint32_t correct = 0u;
    uint32_t batch;
    uint32_t class_index;
    uint32_t token;

    (void)printf(
        "\n=== transformer: short-text intent classification ===\n");
    (void)printf(
        "tensor_shape: token_ids[%u][%u], logits[%u][%u]\n",
        (unsigned)KSF_TRANSFORMER_BATCH,
        (unsigned)KSF_TRANSFORMER_SEQUENCE,
        (unsigned)KSF_TRANSFORMER_BATCH,
        (unsigned)KSF_TRANSFORMER_CLASSES);
    (void)printf(
        "logit_int8_scale=%.9g, zero_point=%d\n",
        (double)ksi_scale(ksf_transformer_logits_qparam),
        ksf_transformer_logits_qparam.zero_point);

    for (batch = 0u; batch < KSF_TRANSFORMER_BATCH; batch++) {
        const int8_t *sample_logits =
            &ksi_runner_transformer_logits[
                batch * KSF_TRANSFORMER_CLASSES];
        uint32_t predicted =
            ksi_argmax_i8(sample_logits, KSF_TRANSFORMER_CLASSES);
        uint32_t keras_predicted =
            ksi_transformer_keras_classes[batch];
        uint32_t true_class =
            ksi_transformer_true_classes[batch];

        correct += predicted == true_class ? 1u : 0u;
        (void)printf(
            "\nsample[%u]\n  text: \"%s\"\n  token_ids: [",
            (unsigned)batch, texts[batch]);
        for (token = 0u; token < KSF_TRANSFORMER_SEQUENCE;
             token++) {
            (void)printf(
                "%s%u", token == 0u ? "" : ", ",
                (unsigned)ksf_transformer_token_ids[
                    batch * KSF_TRANSFORMER_SEQUENCE + token]);
        }
        (void)printf("]\n");
        for (class_index = 0u;
             class_index < KSF_TRANSFORMER_CLASSES;
             class_index++) {
            size_t offset =
                (size_t)batch * KSF_TRANSFORMER_CLASSES +
                class_index;

            (void)printf(
                "  class[%u] %-21s: INT8=%4d, "
                "de-scaled=% .7f, Keras=% .7f\n",
                (unsigned)class_index, class_names[class_index],
                (int)sample_logits[class_index],
                ksi_runner_dequantize(
                    sample_logits[class_index],
                    ksf_transformer_logits_qparam),
                (double)ksi_float_from_bits(
                    ksf_transformer_logits_f32_bits[offset]));
        }
        (void)printf(
            "  true_class:  %u (%s)\n"
            "  C_predicted: %u (%s)\n"
            "  Keras_pred:  %u (%s)\n",
            (unsigned)true_class, class_names[true_class],
            (unsigned)predicted, class_names[predicted],
            (unsigned)keras_predicted,
            class_names[keras_predicted]);
    }

    (void)printf(
        "\nC_fixed_accuracy: %u/%u = %.7f\n",
        (unsigned)correct, (unsigned)KSF_TRANSFORMER_BATCH,
        (double)correct / (double)KSF_TRANSFORMER_BATCH);
    (void)printf(
        "Keras_fixed_accuracy: %.7f\n",
        (double)ksi_float_from_bits(
            KSF_TRANSFORMER_FIXED_ACCURACY_F32_BITS));
    (void)printf(
        "Keras_train_accuracy: %.7f (%u training samples)\n",
        (double)ksi_float_from_bits(
            KSF_TRANSFORMER_TRAIN_ACCURACY_F32_BITS),
        (unsigned)KSF_TRANSFORMER_TRAINING_SAMPLE_COUNT);
    (void)printf(
        "TFLite: status=%u (%s), max_abs_error=%.9g, "
        "allowed=%.9g\n",
        (unsigned)KSF_TRANSFORMER_TFLITE_STATUS,
        ksi_runner_tflite_status(KSF_TRANSFORMER_TFLITE_STATUS),
        (double)ksi_float_from_bits(
            KSF_TRANSFORMER_TFLITE_MAX_ABS_ERROR_F32_BITS),
        (double)ksi_float_from_bits(
            KSF_TRANSFORMER_TFLITE_MAX_ABS_ERROR_LIMIT_F32_BITS));
    (void)printf("C_full_network: PASS\n");
}

static void ksi_runner_print_recurrent(
    const ksi_runner_recurrent_config_t *config)
{
    static const char *const input_names[
        KSF_RECURRENT_FEATURES] = {
        KSF_RECURRENT_FEATURE_0_NAME,
        KSF_RECURRENT_FEATURE_1_NAME,
        KSF_RECURRENT_FEATURE_2_NAME
    };
    static const char *const output_names[
        KSF_RECURRENT_UNITS] = {
        KSF_RECURRENT_OUTPUT_0_NAME,
        KSF_RECURRENT_OUTPUT_1_NAME,
        KSF_RECURRENT_OUTPUT_2_NAME
    };
    double target_sum = 0.0;
    double target_mean;
    double squared_error_sum = 0.0;
    double absolute_error_sum = 0.0;
    double maximum_absolute_error = 0.0;
    double target_variation_sum = 0.0;
    double final_step_squared_error_sum = 0.0;
    uint32_t sample;
    uint32_t step;
    uint32_t unit;
    uint32_t index;

    for (index = 0u; index < KSI_RECURRENT_VALUE_COUNT; index++) {
        target_sum += (double)ksi_float_from_bits(
            ksi_recurrent_application_target_bits[index]);
    }
    target_mean =
        target_sum / (double)KSI_RECURRENT_VALUE_COUNT;

    (void)printf(
        "\n=== %s: device telemetry sequence regression ===\n",
        config->name);
    (void)printf(
        "tensor_shape: input[%u][%u][%u], "
        "prediction[%u][%u][%u]\n",
        (unsigned)KSF_RECURRENT_BATCH,
        (unsigned)KSF_RECURRENT_STEPS,
        (unsigned)KSF_RECURRENT_FEATURES,
        (unsigned)KSF_RECURRENT_BATCH,
        (unsigned)KSF_RECURRENT_STEPS,
        (unsigned)KSF_RECURRENT_UNITS);
    (void)printf(
        "input_features: [0]=%s, [1]=%s, [2]=%s\n",
        input_names[0], input_names[1], input_names[2]);
    (void)printf(
        "outputs: [0]=%s, [1]=%s, [2]=%s\n",
        output_names[0], output_names[1], output_names[2]);
    (void)printf(
        "C_output_int8_scale=%.9g, zero_point=%d\n",
        (double)ksi_scale(config->output_qparam),
        config->output_qparam.zero_point);

    for (sample = 0u; sample < KSF_RECURRENT_BATCH; sample++) {
        double sample_squared_error_sum = 0.0;

        (void)printf("\nsample[%u]\n", (unsigned)sample);
        for (step = 0u; step < KSF_RECURRENT_STEPS; step++) {
            size_t input_offset =
                ((size_t)sample * KSF_RECURRENT_STEPS + step) *
                KSF_RECURRENT_FEATURES;
            size_t output_offset =
                ((size_t)sample * KSF_RECURRENT_STEPS + step) *
                KSF_RECURRENT_UNITS;

            (void)printf("  time_step[%u]\n", (unsigned)step);
            (void)printf("    input_features:    ");
            ksi_runner_print_f32_vector(
                &config->input_bits[input_offset],
                KSF_RECURRENT_FEATURES);
            (void)printf("\n    target:            ");
            ksi_runner_print_f32_vector(
                &ksi_recurrent_application_target_bits[
                    output_offset],
                KSF_RECURRENT_UNITS);
            (void)printf("\n    C_prediction_INT8: ");
            ksi_runner_print_raw_i8_vector(
                &config->c_output[output_offset],
                KSF_RECURRENT_UNITS);
            (void)printf("\n    C_prediction:      ");
            ksi_runner_print_i8_vector(
                &config->c_output[output_offset],
                KSF_RECURRENT_UNITS, config->output_qparam);
            (void)printf("\n    Keras_reference:   ");
            ksi_runner_print_f32_vector(
                &config->keras_output_bits[output_offset],
                KSF_RECURRENT_UNITS);
            (void)printf("\n");

            for (unit = 0u; unit < KSF_RECURRENT_UNITS;
                 unit++) {
                size_t value_index = output_offset + unit;
                double target = (double)ksi_float_from_bits(
                    ksi_recurrent_application_target_bits[
                        value_index]);
                double prediction = ksi_runner_dequantize(
                    config->c_output[value_index],
                    config->output_qparam);
                double error = prediction - target;
                double absolute_error =
                    error < 0.0 ? -error : error;
                double centered = target - target_mean;

                sample_squared_error_sum += error * error;
                squared_error_sum += error * error;
                absolute_error_sum += absolute_error;
                target_variation_sum += centered * centered;
                if (absolute_error > maximum_absolute_error) {
                    maximum_absolute_error = absolute_error;
                }
                if (step + 1u == KSF_RECURRENT_STEPS) {
                    final_step_squared_error_sum +=
                        error * error;
                }
            }
        }
        (void)printf(
            "  sample_MSE: %.9g\n",
            sample_squared_error_sum /
                (double)(KSF_RECURRENT_STEPS *
                         KSF_RECURRENT_UNITS));
    }

    {
        double mse =
            squared_error_sum /
            (double)KSI_RECURRENT_VALUE_COUNT;
        double final_step_mse =
            final_step_squared_error_sum /
            (double)(KSF_RECURRENT_BATCH *
                     KSF_RECURRENT_UNITS);
        double r_squared =
            target_variation_sum == 0.0
                ? 0.0
                : 1.0 -
                      squared_error_sum / target_variation_sum;

        (void)printf("\nC_regression_metrics\n");
        (void)printf("  MSE:           %.9g\n", mse);
        (void)printf("  RMSE:          %.9g\n", sqrt(mse));
        (void)printf(
            "  MAE:           %.9g\n",
            absolute_error_sum /
                (double)KSI_RECURRENT_VALUE_COUNT);
        (void)printf(
            "  max_abs_error: %.9g\n", maximum_absolute_error);
        (void)printf("  R_squared:     %.9g\n", r_squared);
        (void)printf(
            "  final_step_MSE: %.9g\n", final_step_mse);
    }

    (void)printf(
        "Keras_fixed_metrics\n"
        "  whole_sequence_MSE: %.9g\n"
        "  final_step_MSE:     %.9g\n",
        (double)ksi_float_from_bits(config->keras_mse_bits),
        (double)ksi_float_from_bits(
            config->keras_final_step_mse_bits));
    (void)printf(
        "baselines\n"
        "  previous_target_baseline_MSE: %.9g\n"
        "  same_current_step_MSE:   %.9g\n",
        (double)ksi_float_from_bits(
            config->history_baseline_mse_bits),
        (double)ksi_float_from_bits(
            KSF_RECURRENT_SAME_CURRENT_BASELINE_MSE_F32_BITS));
    (void)printf(
        "Keras_training_MSE: initial=%.9g, final=%.9g, "
        "steps=%u, samples=%u\n",
        (double)ksi_float_from_bits(
            config->train_initial_mse_bits),
        (double)ksi_float_from_bits(
            config->train_final_mse_bits),
        (unsigned)config->train_steps,
        (unsigned)KSF_RECURRENT_TRAINING_SAMPLE_COUNT);
    (void)printf(
        "TFLite: status=%u (%s), max_abs_error=%.9g, "
        "allowed=%.9g\n",
        (unsigned)config->tflite_status,
        ksi_runner_tflite_status(config->tflite_status),
        (double)ksi_float_from_bits(config->tflite_error_bits),
        (double)ksi_float_from_bits(
            config->tflite_error_limit_bits));
    (void)printf(
        "classification_accuracy: not applicable "
        "(state-dependent regression)\n");
    (void)printf("C_full_network: PASS\n");
}

static int ksi_runner_execute_transformer(void)
{
    int result = ksi_transformer_full_network();

    if (result != 0) {
        (void)fprintf(
            stderr,
            "transformer C full network failed at source line %d\n",
            result);
        return 1;
    }
    ksi_runner_print_transformer();
    return 0;
}

static int ksi_runner_execute_simple_rnn(void)
{
    ksi_runner_recurrent_config_t config = {
        .name = "simple_rnn",
        .input_bits = ksf_simple_rnn_input_f32_bits,
        .keras_output_bits = ksf_simple_rnn_hidden_f32_bits,
        .c_output = ksi_runner_simple_rnn_output,
        .output_qparam = ksf_simple_rnn_hidden_qparam,
        .train_steps = KSF_SIMPLE_RNN_TRAIN_STEPS,
        .train_initial_mse_bits =
            KSF_SIMPLE_RNN_TRAIN_INITIAL_LOSS_F32_BITS,
        .train_final_mse_bits =
            KSF_SIMPLE_RNN_TRAIN_FINAL_LOSS_F32_BITS,
        .keras_mse_bits =
            KSF_SIMPLE_RNN_APPLICATION_MSE_F32_BITS,
        .keras_final_step_mse_bits =
            KSF_SIMPLE_RNN_FINAL_STEP_MSE_F32_BITS,
        .history_baseline_mse_bits =
            KSF_SIMPLE_RNN_HISTORY_BASELINE_MSE_F32_BITS,
        .tflite_status = KSF_SIMPLE_RNN_TFLITE_STATUS,
        .tflite_error_bits =
            KSF_SIMPLE_RNN_TFLITE_MAX_ABS_ERROR_F32_BITS,
        .tflite_error_limit_bits =
            KSF_SIMPLE_RNN_TFLITE_MAX_ABS_ERROR_LIMIT_F32_BITS
    };
    int result = ksi_simple_rnn_full_network();

    if (result != 0) {
        (void)fprintf(
            stderr,
            "simple_rnn C full network failed at source line %d\n",
            result);
        return 1;
    }
    ksi_runner_print_recurrent(&config);
    return 0;
}

static int ksi_runner_execute_gru(void)
{
    ksi_runner_recurrent_config_t config = {
        .name = "gru",
        .input_bits = ksf_gru_input_f32_bits,
        .keras_output_bits = ksf_gru_hidden_f32_bits,
        .c_output = ksi_runner_gru_output,
        .output_qparam = ksf_gru_hidden_qparam,
        .train_steps = KSF_GRU_TRAIN_STEPS,
        .train_initial_mse_bits =
            KSF_GRU_TRAIN_INITIAL_LOSS_F32_BITS,
        .train_final_mse_bits =
            KSF_GRU_TRAIN_FINAL_LOSS_F32_BITS,
        .keras_mse_bits = KSF_GRU_APPLICATION_MSE_F32_BITS,
        .keras_final_step_mse_bits =
            KSF_GRU_FINAL_STEP_MSE_F32_BITS,
        .history_baseline_mse_bits =
            KSF_GRU_HISTORY_BASELINE_MSE_F32_BITS,
        .tflite_status = KSF_GRU_TFLITE_STATUS,
        .tflite_error_bits =
            KSF_GRU_TFLITE_MAX_ABS_ERROR_F32_BITS,
        .tflite_error_limit_bits =
            KSF_GRU_TFLITE_MAX_ABS_ERROR_LIMIT_F32_BITS
    };
    int result = ksi_gru_full_network();

    if (result != 0) {
        (void)fprintf(
            stderr,
            "gru C full network failed at source line %d\n",
            result);
        return 1;
    }
    ksi_runner_print_recurrent(&config);
    return 0;
}

static int ksi_runner_execute_lstm(void)
{
    ksi_runner_recurrent_config_t config = {
        .name = "lstm",
        .input_bits = ksf_lstm_input_f32_bits,
        .keras_output_bits = ksf_lstm_hidden_f32_bits,
        .c_output = ksi_runner_lstm_output,
        .output_qparam = ksf_lstm_hidden_qparam,
        .train_steps = KSF_LSTM_TRAIN_STEPS,
        .train_initial_mse_bits =
            KSF_LSTM_TRAIN_INITIAL_LOSS_F32_BITS,
        .train_final_mse_bits =
            KSF_LSTM_TRAIN_FINAL_LOSS_F32_BITS,
        .keras_mse_bits = KSF_LSTM_APPLICATION_MSE_F32_BITS,
        .keras_final_step_mse_bits =
            KSF_LSTM_FINAL_STEP_MSE_F32_BITS,
        .history_baseline_mse_bits =
            KSF_LSTM_HISTORY_BASELINE_MSE_F32_BITS,
        .tflite_status = KSF_LSTM_TFLITE_STATUS,
        .tflite_error_bits =
            KSF_LSTM_TFLITE_MAX_ABS_ERROR_F32_BITS,
        .tflite_error_limit_bits =
            KSF_LSTM_TFLITE_MAX_ABS_ERROR_LIMIT_F32_BITS
    };
    int result = ksi_lstm_full_network();

    if (result != 0) {
        (void)fprintf(
            stderr,
            "lstm C full network failed at source line %d\n",
            result);
        return 1;
    }
    ksi_runner_print_recurrent(&config);
    return 0;
}

static void ksi_runner_usage(const char *program)
{
    (void)fprintf(
        stderr,
        "Usage: %s "
        "{transformer|simple_rnn|rnn|gru|lstm|all}\n",
        program);
}

int main(int argc, char **argv)
{
    const char *model;
    int run_all;
    int result;

    if (argc != 2) {
        ksi_runner_usage(argv[0]);
        return 2;
    }
    model = argv[1];
    run_all = strcmp(model, "all") == 0;
    if (!run_all &&
        strcmp(model, "transformer") != 0 &&
        strcmp(model, "simple_rnn") != 0 &&
        strcmp(model, "rnn") != 0 &&
        strcmp(model, "gru") != 0 &&
        strcmp(model, "lstm") != 0) {
        ksi_runner_usage(argv[0]);
        return 2;
    }

    result = ksi_init();
    if (result != 0) {
        (void)fprintf(
            stderr,
            "C model initialization failed at source line %d\n",
            result);
        return 1;
    }
    result = ksi_training_metadata();
    if (result != 0) {
        (void)fprintf(
            stderr,
            "fixture metadata check failed at source line %d\n",
            result);
        return 1;
    }

    if (run_all || strcmp(model, "transformer") == 0) {
        if (ksi_runner_execute_transformer() != 0) {
            return 1;
        }
    }
    if (run_all || strcmp(model, "simple_rnn") == 0 ||
        strcmp(model, "rnn") == 0) {
        if (ksi_runner_execute_simple_rnn() != 0) {
            return 1;
        }
    }
    if (run_all || strcmp(model, "gru") == 0) {
        if (ksi_runner_execute_gru() != 0) {
            return 1;
        }
    }
    if (run_all || strcmp(model, "lstm") == 0) {
        if (ksi_runner_execute_lstm() != 0) {
            return 1;
        }
    }
    return 0;
}
#endif
