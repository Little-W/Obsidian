#include "generated/keras_mlp_fixture.h"
#include "test_util.h"

#include <stdint.h>
#include <string.h>

#define KERAS_TEST_L1_BYTES (64u * 1024u)
#define KERAS_TEST_INPUT_ADDR UINT64_C(0x0000)
#define KERAS_TEST_WEIGHT1_ADDR UINT64_C(0x1000)
#define KERAS_TEST_BIAS1_ADDR UINT64_C(0x1100)
#define KERAS_TEST_REQUANT1_ADDR UINT64_C(0x1140)
#define KERAS_TEST_HIDDEN_ADDR UINT64_C(0x2000)
#define KERAS_TEST_WEIGHT2_ADDR UINT64_C(0x3000)
#define KERAS_TEST_BIAS2_ADDR UINT64_C(0x3100)
#define KERAS_TEST_LOGITS_ADDR UINT64_C(0x4000)

static uint8_t keras_test_l1[KERAS_TEST_L1_BYTES];
static uint8_t keras_test_ddr[KERAS_TEST_L1_BYTES];
static npu_model_t keras_test_model;

_Static_assert(
    sizeof(keras_npu_layer1_weight_tiled) ==
        NPU_REF_KT * NPU_REF_NT,
    "layer 1 fixture must occupy one reference Matrix weight tile");
_Static_assert(
    sizeof(keras_npu_layer2_weight_tiled) ==
        NPU_REF_KT * NPU_REF_NT,
    "layer 2 fixture must occupy one reference Matrix weight tile");

static void keras_test_put_u32(uint64_t addr, uint32_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 4u; byte++) {
        keras_test_l1[(size_t)addr + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static void keras_test_put_i32(uint64_t addr, int32_t value)
{
    keras_test_put_u32(addr, (uint32_t)value);
}

static npu_tensor_t keras_test_tensor(
    npu_dtype_t dtype,
    uint64_t addr,
    uint64_t region_bytes,
    uint32_t row_stride)
{
    npu_tensor_t tensor =
        test_tensor(dtype, addr, region_bytes, row_stride);

    tensor.batch_stride_bytes = (uint32_t)region_bytes;
    return tensor;
}

static npu_matrix_desc_t keras_test_layer1_desc(void)
{
    npu_matrix_desc_t desc;

    (void)memset(&desc, 0, sizeof(desc));
    desc.m = KERAS_NPU_SAMPLE_COUNT;
    desc.n = KERAS_NPU_HIDDEN_DIM;
    desc.k = KERAS_NPU_INPUT_DIM;
    desc.batch_count = 1u;
    desc.a = keras_test_tensor(
        NPU_DTYPE_INT8, KERAS_TEST_INPUT_ADDR,
        sizeof(keras_npu_input), KERAS_NPU_INPUT_DIM);
    desc.b = keras_test_tensor(
        NPU_DTYPE_INT8, KERAS_TEST_WEIGHT1_ADDR,
        sizeof(keras_npu_layer1_weight_tiled), 0u);
    desc.c = keras_test_tensor(
        NPU_DTYPE_INT8, KERAS_TEST_HIDDEN_ADDR,
        sizeof(keras_npu_layer1_expected),
        KERAS_NPU_HIDDEN_DIM);
    desc.bias_addr = KERAS_TEST_BIAS1_ADDR;
    desc.bias_count = KERAS_NPU_HIDDEN_DIM;
    desc.bias_stride_bytes = 4u;
    desc.requant_addr = KERAS_TEST_REQUANT1_ADDR;
    desc.requant_count = 1u;
    desc.requant_region_bytes = 8u;
    desc.b_tiled = 1u;
    desc.bias_enable = 1u;
    desc.final_output = 1u;
    desc.relu_enable = 1u;
    desc.requant_enable = 1u;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    return desc;
}

static npu_matrix_desc_t keras_test_layer2_desc(void)
{
    npu_matrix_desc_t desc;

    (void)memset(&desc, 0, sizeof(desc));
    desc.m = KERAS_NPU_SAMPLE_COUNT;
    desc.n = KERAS_NPU_OUTPUT_DIM;
    desc.k = KERAS_NPU_HIDDEN_DIM;
    desc.batch_count = 1u;
    desc.a = keras_test_tensor(
        NPU_DTYPE_INT8, KERAS_TEST_HIDDEN_ADDR,
        sizeof(keras_npu_layer1_expected),
        KERAS_NPU_HIDDEN_DIM);
    desc.b = keras_test_tensor(
        NPU_DTYPE_INT8, KERAS_TEST_WEIGHT2_ADDR,
        sizeof(keras_npu_layer2_weight_tiled), 0u);
    desc.c = keras_test_tensor(
        NPU_DTYPE_INT32, KERAS_TEST_LOGITS_ADDR,
        sizeof(keras_npu_logits_expected),
        KERAS_NPU_OUTPUT_DIM * 4u);
    desc.bias_addr = KERAS_TEST_BIAS2_ADDR;
    desc.bias_count = KERAS_NPU_OUTPUT_DIM;
    desc.bias_stride_bytes = 4u;
    desc.b_tiled = 1u;
    desc.bias_enable = 1u;
    desc.final_output = 1u;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    return desc;
}

static int keras_test_init(void)
{
    npu_config_t config;
    uint32_t index;

    (void)memset(keras_test_l1, 0, sizeof(keras_test_l1));
    (void)memset(keras_test_ddr, 0, sizeof(keras_test_ddr));
    npu_config_reference(&config);
    config.l1_bytes = sizeof(keras_test_l1);
    TEST_CHECK_STATUS(
        npu_model_init(
            &keras_test_model, &config,
            keras_test_l1, sizeof(keras_test_l1),
            keras_test_ddr, sizeof(keras_test_ddr)),
        NPU_STATUS_SUCCESS);

    (void)memcpy(
        &keras_test_l1[KERAS_TEST_INPUT_ADDR],
        keras_npu_input, sizeof(keras_npu_input));
    (void)memcpy(
        &keras_test_l1[KERAS_TEST_WEIGHT1_ADDR],
        keras_npu_layer1_weight_tiled,
        sizeof(keras_npu_layer1_weight_tiled));
    (void)memcpy(
        &keras_test_l1[KERAS_TEST_WEIGHT2_ADDR],
        keras_npu_layer2_weight_tiled,
        sizeof(keras_npu_layer2_weight_tiled));
    for (index = 0u; index < KERAS_NPU_HIDDEN_DIM; index++) {
        keras_test_put_i32(
            KERAS_TEST_BIAS1_ADDR + (uint64_t)index * 4u,
            keras_npu_layer1_bias[index]);
    }
    for (index = 0u; index < KERAS_NPU_OUTPUT_DIM; index++) {
        keras_test_put_i32(
            KERAS_TEST_BIAS2_ADDR + (uint64_t)index * 4u,
            keras_npu_layer2_bias[index]);
    }
    keras_test_put_u32(
        KERAS_TEST_REQUANT1_ADDR,
        KERAS_NPU_LAYER1_MULTIPLIER);
    keras_test_l1[KERAS_TEST_REQUANT1_ADDR + 4u] =
        (uint8_t)(int8_t)KERAS_NPU_LAYER1_SHIFT;
    return 0;
}

static int keras_test_check_hidden(
    const npu_matrix_desc_t *desc)
{
    uint32_t row;
    uint32_t column;

    for (row = 0u; row < KERAS_NPU_SAMPLE_COUNT; row++) {
        for (column = 0u;
             column < KERAS_NPU_HIDDEN_DIM;
             column++) {
            int32_t actual = 0;
            uint32_t index =
                row * KERAS_NPU_HIDDEN_DIM + column;

            TEST_CHECK_STATUS(
                npu_tensor_read(
                    &keras_test_model, &desc->c,
                    0u, row, column, &actual),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(
                actual == keras_npu_layer1_expected[index]);
        }
    }
    return 0;
}

static int keras_test_check_logits_and_classes(
    const npu_matrix_desc_t *desc)
{
    uint32_t row;
    uint32_t column;
    uint32_t correct = 0u;
    uint32_t agreement = 0u;

    for (row = 0u; row < KERAS_NPU_SAMPLE_COUNT; row++) {
        int32_t best_value = 0;
        uint8_t best_class = 0u;

        for (column = 0u;
             column < KERAS_NPU_OUTPUT_DIM;
             column++) {
            int32_t actual = 0;
            uint32_t index =
                row * KERAS_NPU_OUTPUT_DIM + column;

            TEST_CHECK_STATUS(
                npu_tensor_read(
                    &keras_test_model, &desc->c,
                    0u, row, column, &actual),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(
                actual == keras_npu_logits_expected[index]);
            if (column == 0u || actual > best_value) {
                best_value = actual;
                best_class = (uint8_t)column;
            }
        }
        TEST_CHECK(best_class == keras_npu_integer_class[row]);
        if (best_class == keras_npu_label[row]) {
            correct++;
        }
        if (best_class == keras_npu_float_class[row]) {
            agreement++;
        }
    }
    TEST_CHECK(correct == KERAS_NPU_INTEGER_CORRECT);
    TEST_CHECK(agreement == KERAS_NPU_CLASS_AGREEMENT);
    TEST_CHECK(
        correct * 10u >= KERAS_NPU_SAMPLE_COUNT * 9u);
    TEST_CHECK(
        KERAS_NPU_FLOAT_CORRECT * 10u >=
        KERAS_NPU_SAMPLE_COUNT * 9u);
    return 0;
}

int test_keras_mlp_inference(void)
{
    npu_matrix_desc_t layer1;
    npu_matrix_desc_t layer2;
    uint64_t progress = UINT64_MAX;

    TEST_CHECK(keras_test_init() == 0);
    layer1 = keras_test_layer1_desc();
    TEST_CHECK_STATUS(
        npu_matrix_execute(
            &keras_test_model, NPU_MATRIX_GEMM,
            &layer1, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(
        progress ==
        (uint64_t)KERAS_NPU_SAMPLE_COUNT *
            KERAS_NPU_HIDDEN_DIM);
    TEST_CHECK(keras_test_check_hidden(&layer1) == 0);

    layer2 = keras_test_layer2_desc();
    progress = UINT64_MAX;
    TEST_CHECK_STATUS(
        npu_matrix_execute(
            &keras_test_model, NPU_MATRIX_GEMM,
            &layer2, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(
        progress ==
        (uint64_t)KERAS_NPU_SAMPLE_COUNT *
            KERAS_NPU_OUTPUT_DIM);
    TEST_CHECK(
        keras_test_check_logits_and_classes(&layer2) == 0);
    return 0;
}

#ifdef NPU_KERAS_MLP_STANDALONE
int main(void)
{
    return test_keras_mlp_inference();
}
#endif
