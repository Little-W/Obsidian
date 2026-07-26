#include "test_util.h"

#include <limits.h>

#ifdef NPU_MATRIX_ACCEPTANCE_STANDALONE
#include <stdio.h>
#endif

#define MATRIX_ACCEPT_L1_BYTES NPU_REF_L1_BYTES
#define MATRIX_ACCEPT_DDR_BYTES (1024u * 1024u)
#define MATRIX_ACCEPT_A_ADDR UINT64_C(0x10000)
#define MATRIX_ACCEPT_B_ADDR UINT64_C(0x20000)
#define MATRIX_ACCEPT_C_ADDR UINT64_C(0x30000)
#define MATRIX_ACCEPT_BIAS_ADDR UINT64_C(0x40000)
#define MATRIX_ACCEPT_REQUANT_ADDR UINT64_C(0x50000)

static uint8_t matrix_accept_l1[MATRIX_ACCEPT_L1_BYTES];
static uint8_t matrix_accept_ddr[MATRIX_ACCEPT_DDR_BYTES];
static npu_model_t matrix_accept_model;
static npu_config_t matrix_accept_config;

static void matrix_accept_clear(uint8_t *memory, size_t bytes)
{
    size_t index;

    for (index = 0u; index < bytes; index++) {
        memory[index] = 0u;
    }
}

static uint32_t matrix_accept_row_bytes(npu_dtype_t dtype,
                                        uint32_t length)
{
    if (dtype == NPU_DTYPE_INT4) {
        return (length + 1u) / 2u;
    }
    if (dtype == NPU_DTYPE_INT8) {
        return length;
    }
    return length * 4u;
}

static npu_tensor_t matrix_accept_tensor(npu_dtype_t dtype,
                                         uint64_t addr,
                                         uint32_t rows,
                                         uint32_t length)
{
    npu_tensor_t tensor;
    uint32_t row_bytes =
        matrix_accept_row_bytes(dtype, length);

    tensor.space = NPU_SPACE_L1;
    tensor.dtype = dtype;
    tensor.addr = addr;
    tensor.region_bytes = (uint64_t)rows * row_bytes;
    tensor.row_stride_bytes = row_bytes;
    tensor.elem_stride_bytes = 0u;
    tensor.batch_stride_bytes = 0u;
    tensor.start_nibble = 0u;
    return tensor;
}

static int matrix_accept_init(void)
{
    npu_config_reference(&matrix_accept_config);
    matrix_accept_clear(
        matrix_accept_l1, sizeof(matrix_accept_l1));
    matrix_accept_clear(
        matrix_accept_ddr, sizeof(matrix_accept_ddr));
    return npu_model_init(
               &matrix_accept_model, &matrix_accept_config,
               matrix_accept_l1, sizeof(matrix_accept_l1),
               matrix_accept_ddr,
               sizeof(matrix_accept_ddr)) ==
           NPU_STATUS_SUCCESS;
}

static npu_matrix_desc_t matrix_accept_desc(
    npu_dtype_t a_dtype,
    npu_dtype_t b_dtype,
    npu_dtype_t c_dtype,
    uint32_t m,
    uint32_t n,
    uint32_t k)
{
    npu_matrix_desc_t desc = {0};
    uint64_t k_tiles =
        ((uint64_t)k + matrix_accept_config.kt - 1u) /
        matrix_accept_config.kt;
    uint64_t n_tiles =
        ((uint64_t)n + matrix_accept_config.nt - 1u) /
        matrix_accept_config.nt;
    uint64_t b_elements =
        k_tiles * n_tiles *
        matrix_accept_config.kt *
        matrix_accept_config.nt;
    uint64_t b_bytes =
        b_dtype == NPU_DTYPE_INT4
            ? (b_elements + 1u) / 2u
            : b_elements;

    desc.m = m;
    desc.n = n;
    desc.k = k;
    desc.batch_count = 1u;
    desc.a = matrix_accept_tensor(
        a_dtype, MATRIX_ACCEPT_A_ADDR, m, k);
    desc.b = matrix_accept_tensor(
        b_dtype, MATRIX_ACCEPT_B_ADDR, 1u,
        (uint32_t)b_elements);
    desc.b.region_bytes = b_bytes;
    desc.b.row_stride_bytes = 0u;
    desc.b.batch_stride_bytes = (uint32_t)b_bytes;
    desc.c = matrix_accept_tensor(
        c_dtype, MATRIX_ACCEPT_C_ADDR, m, n);
    desc.b_tiled = 1u;
    desc.final_output = 1u;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    return desc;
}

static int matrix_accept_store_a(
    const npu_matrix_desc_t *desc,
    uint32_t row,
    uint32_t inner,
    int32_t value)
{
    return npu_tensor_write(
               &matrix_accept_model, &desc->a,
               0u, row, inner, value) ==
           NPU_STATUS_SUCCESS;
}

static void matrix_accept_store_b(
    const npu_matrix_desc_t *desc,
    uint32_t inner,
    uint32_t col,
    int32_t value)
{
    uint64_t n_tiles =
        ((uint64_t)desc->n + matrix_accept_config.nt - 1u) /
        matrix_accept_config.nt;
    uint64_t linear =
        (((((uint64_t)inner / matrix_accept_config.kt) *
               n_tiles +
           col / matrix_accept_config.nt) *
              matrix_accept_config.kt +
          inner % matrix_accept_config.kt) *
             matrix_accept_config.nt) +
        col % matrix_accept_config.nt;
    uint64_t addr = desc->b.addr;

    if (desc->b.dtype == NPU_DTYPE_INT4) {
        uint8_t old =
            matrix_accept_l1[(size_t)(addr + linear / 2u)];

        matrix_accept_l1[(size_t)(addr + linear / 2u)] =
            npu_int4_insert(
                old, (uint8_t)(linear & 1u), value);
    } else {
        matrix_accept_l1[(size_t)(addr + linear)] =
            (uint8_t)value;
    }
}

static int matrix_accept_read_c(
    const npu_matrix_desc_t *desc,
    uint32_t row,
    uint32_t col,
    int32_t expected)
{
    int32_t actual = 0;

    TEST_CHECK_STATUS(
        npu_tensor_read(
            &matrix_accept_model, &desc->c,
            0u, row, col, &actual),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(actual == expected);
    return 0;
}

static void matrix_accept_requant(uint32_t index,
                                  uint32_t multiplier,
                                  int8_t shift)
{
    size_t addr =
        (size_t)MATRIX_ACCEPT_REQUANT_ADDR +
        (size_t)index * 8u;

    matrix_accept_l1[addr] =
        (uint8_t)(multiplier & 0xffu);
    matrix_accept_l1[addr + 1u] =
        (uint8_t)((multiplier >> 8u) & 0xffu);
    matrix_accept_l1[addr + 2u] =
        (uint8_t)((multiplier >> 16u) & 0xffu);
    matrix_accept_l1[addr + 3u] =
        (uint8_t)((multiplier >> 24u) & 0xffu);
    matrix_accept_l1[addr + 4u] = (uint8_t)shift;
}

static int matrix_accept_dtype_combinations(void)
{
    static const struct {
        npu_dtype_t a_dtype;
        npu_dtype_t b_dtype;
    } combinations[] = {
        {NPU_DTYPE_INT4, NPU_DTYPE_INT4},
        {NPU_DTYPE_INT8, NPU_DTYPE_INT8},
        {NPU_DTYPE_INT8, NPU_DTYPE_INT4}
    };
    uint32_t combination;
    npu_dtype_t output_dtype;

    for (combination = 0u;
         combination <
             sizeof(combinations) / sizeof(combinations[0]);
         combination++) {
        for (output_dtype = NPU_DTYPE_INT4;
             output_dtype <= NPU_DTYPE_INT32;
             output_dtype++) {
            npu_matrix_desc_t desc;
            uint64_t progress = UINT64_MAX;
            int32_t expected =
                output_dtype == NPU_DTYPE_INT4 ? -8 : -10;
            int line;

            TEST_CHECK(matrix_accept_init());
            desc = matrix_accept_desc(
                combinations[combination].a_dtype,
                combinations[combination].b_dtype,
                output_dtype, 1u, 1u, 2u);
            if (output_dtype != NPU_DTYPE_INT32) {
                desc.requant_addr =
                    MATRIX_ACCEPT_REQUANT_ADDR;
                desc.requant_count = 1u;
                desc.requant_region_bytes = 8u;
                desc.requant_enable = 1u;
                matrix_accept_requant(0u, 1u, 0);
            }
            TEST_CHECK(matrix_accept_store_a(
                &desc, 0u, 0u, 2));
            TEST_CHECK(matrix_accept_store_a(
                &desc, 0u, 1u, -1));
            matrix_accept_store_b(&desc, 0u, 0u, -3);
            matrix_accept_store_b(&desc, 1u, 0u, 4);
            TEST_CHECK_STATUS(
                npu_matrix_execute(
                    &matrix_accept_model, NPU_MATRIX_GEMM,
                    &desc, &progress),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(progress == 1u);
            line = matrix_accept_read_c(
                &desc, 0u, 0u, expected);
            if (line != 0) {
                return line;
            }
        }
    }
    return 0;
}

static int matrix_accept_rounding(void)
{
    static const npu_round_mode_t modes[] = {
        NPU_ROUND_NEAREST_EVEN,
        NPU_ROUND_TO_ZERO,
        NPU_ROUND_TO_POS_INF,
        NPU_ROUND_TO_NEG_INF
    };
    static const int32_t positive_expected[] = {2, 2, 3, 2};
    static const int32_t negative_expected[] = {-2, -2, -2, -3};
    uint32_t mode_index;

    for (mode_index = 0u;
         mode_index < sizeof(modes) / sizeof(modes[0]);
         mode_index++) {
        npu_matrix_desc_t desc;
        uint64_t progress = UINT64_MAX;
        int line;

        TEST_CHECK(matrix_accept_init());
        desc = matrix_accept_desc(
            NPU_DTYPE_INT8, NPU_DTYPE_INT8,
            NPU_DTYPE_INT8, 1u, 2u, 1u);
        desc.requant_addr = MATRIX_ACCEPT_REQUANT_ADDR;
        desc.requant_count = 1u;
        desc.requant_region_bytes = 8u;
        desc.requant_enable = 1u;
        desc.round_mode = modes[mode_index];
        matrix_accept_requant(0u, 1u, 1);
        TEST_CHECK(matrix_accept_store_a(
            &desc, 0u, 0u, 5));
        matrix_accept_store_b(&desc, 0u, 0u, 1);
        matrix_accept_store_b(&desc, 0u, 1u, -1);
        TEST_CHECK_STATUS(
            npu_matrix_execute(
                &matrix_accept_model, NPU_MATRIX_GEMM,
                &desc, &progress),
            NPU_STATUS_SUCCESS);
        line = matrix_accept_read_c(
            &desc, 0u, 0u,
            positive_expected[mode_index]);
        if (line != 0) {
            return line;
        }
        line = matrix_accept_read_c(
            &desc, 0u, 1u,
            negative_expected[mode_index]);
        if (line != 0) {
            return line;
        }
    }

    TEST_CHECK(matrix_accept_init());
    {
        npu_matrix_desc_t desc = matrix_accept_desc(
            NPU_DTYPE_INT8, NPU_DTYPE_INT8,
            NPU_DTYPE_INT8, 1u, 2u, 1u);
        uint64_t progress = UINT64_MAX;
        int line;

        desc.requant_addr = MATRIX_ACCEPT_REQUANT_ADDR;
        desc.requant_count = 2u;
        desc.requant_region_bytes = 16u;
        desc.requant_enable = 1u;
        matrix_accept_requant(0u, 1u, 0);
        matrix_accept_requant(1u, 1u, -1);
        TEST_CHECK(matrix_accept_store_a(
            &desc, 0u, 0u, 3));
        matrix_accept_store_b(&desc, 0u, 0u, 1);
        matrix_accept_store_b(&desc, 0u, 1u, 1);
        TEST_CHECK_STATUS(
            npu_matrix_execute(
                &matrix_accept_model, NPU_MATRIX_GEMM,
                &desc, &progress),
            NPU_STATUS_SUCCESS);
        line = matrix_accept_read_c(&desc, 0u, 0u, 3);
        if (line != 0) {
            return line;
        }
        line = matrix_accept_read_c(&desc, 0u, 1u, 6);
        if (line != 0) {
            return line;
        }
    }
    return 0;
}

static int matrix_accept_overflow(void)
{
    npu_overflow_mode_t mode;

    for (mode = NPU_OVERFLOW_SATURATE;
         mode <= NPU_OVERFLOW_WRAP; mode++) {
        npu_matrix_desc_t desc;
        npu_tensor_t bias;
        int32_t actual = 7;
        int32_t expected;
        uint64_t progress = UINT64_MAX;
        npu_status_t expected_status;

        TEST_CHECK(matrix_accept_init());
        desc = matrix_accept_desc(
            NPU_DTYPE_INT8, NPU_DTYPE_INT8,
            NPU_DTYPE_INT32, 1u, 1u, 1u);
        desc.bias_addr = MATRIX_ACCEPT_BIAS_ADDR;
        desc.bias_count = 1u;
        desc.bias_stride_bytes = 4u;
        desc.bias_enable = 1u;
        desc.overflow_mode = mode;
        bias = matrix_accept_tensor(
            NPU_DTYPE_INT32, MATRIX_ACCEPT_BIAS_ADDR,
            1u, 1u);
        TEST_CHECK(matrix_accept_store_a(
            &desc, 0u, 0u, 1));
        matrix_accept_store_b(&desc, 0u, 0u, 1);
        TEST_CHECK_STATUS(
            npu_tensor_write(
                &matrix_accept_model, &bias,
                0u, 0u, 0u, INT32_MAX),
            NPU_STATUS_SUCCESS);
        TEST_CHECK_STATUS(
            npu_tensor_write(
                &matrix_accept_model, &desc.c,
                0u, 0u, 0u, actual),
            NPU_STATUS_SUCCESS);

        expected_status =
            mode == NPU_OVERFLOW_ERROR
                ? NPU_STATUS_NUMERIC_EXCEPTION
                : NPU_STATUS_SUCCESS;
        TEST_CHECK_STATUS(
            npu_matrix_execute(
                &matrix_accept_model, NPU_MATRIX_GEMM,
                &desc, &progress),
            expected_status);
        TEST_CHECK_STATUS(
            npu_tensor_read(
                &matrix_accept_model, &desc.c,
                0u, 0u, 0u, &actual),
            NPU_STATUS_SUCCESS);
        if (mode == NPU_OVERFLOW_SATURATE) {
            expected = INT32_MAX;
        } else if (mode == NPU_OVERFLOW_WRAP) {
            expected = INT32_MIN;
        } else {
            expected = 7;
            TEST_CHECK(progress == 0u);
        }
        TEST_CHECK(actual == expected);
    }
    return 0;
}

static int matrix_accept_int4_output(void)
{
    npu_matrix_desc_t desc;
    uint64_t progress = UINT64_MAX;
    int line;

    TEST_CHECK(matrix_accept_init());
    desc = matrix_accept_desc(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8,
        NPU_DTYPE_INT4, 1u, 3u, 1u);
    desc.requant_addr = MATRIX_ACCEPT_REQUANT_ADDR;
    desc.requant_count = 1u;
    desc.requant_region_bytes = 8u;
    desc.requant_enable = 1u;
    matrix_accept_requant(0u, 1u, 0);
    TEST_CHECK(matrix_accept_store_a(
        &desc, 0u, 0u, 5));
    matrix_accept_store_b(&desc, 0u, 0u, 1);
    matrix_accept_store_b(&desc, 0u, 1u, 2);
    matrix_accept_store_b(&desc, 0u, 2u, -2);
    TEST_CHECK_STATUS(
        npu_matrix_execute(
            &matrix_accept_model, NPU_MATRIX_GEMM,
            &desc, &progress),
        NPU_STATUS_SUCCESS);
    line = matrix_accept_read_c(&desc, 0u, 0u, 5);
    if (line != 0) {
        return line;
    }
    line = matrix_accept_read_c(&desc, 0u, 1u, 7);
    if (line != 0) {
        return line;
    }
    line = matrix_accept_read_c(&desc, 0u, 2u, -8);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(
        (matrix_accept_l1[
             (size_t)desc.c.addr + 1u] &
         0xf0u) == 0u);
    return 0;
}

int test_matrix_acceptance(void)
{
    int line;

    line = matrix_accept_dtype_combinations();
    if (line != 0) {
        return line;
    }
    line = matrix_accept_rounding();
    if (line != 0) {
        return line;
    }
    line = matrix_accept_overflow();
    if (line != 0) {
        return line;
    }
    line = matrix_accept_int4_output();
    if (line != 0) {
        return line;
    }
    return 0;
}

#ifdef NPU_MATRIX_ACCEPTANCE_STANDALONE
int main(void)
{
    int line = test_matrix_acceptance();

    if (line == 0) {
        (void)printf("[PASS] matrix_acceptance\n");
        return 0;
    }
    (void)printf(
        "[FAIL] matrix_acceptance at test line %d\n", line);
    return 1;
}
#endif
