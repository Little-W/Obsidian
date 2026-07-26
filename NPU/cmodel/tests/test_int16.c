#include "test_util.h"

#include <limits.h>
#include <string.h>

#define INT16_TEST_L1_BYTES NPU_REF_L1_BYTES
#define INT16_TEST_DDR_BYTES (1024u * 1024u)
#define INT16_TEST_DMA_SRC_ADDR UINT64_C(0x10000)
#define INT16_TEST_DMA_DST_ADDR UINT64_C(0x20000)
#define INT16_TEST_MATRIX_A_ADDR UINT64_C(0x10000)
#define INT16_TEST_MATRIX_B_ADDR UINT64_C(0x20000)
#define INT16_TEST_MATRIX_C_ADDR UINT64_C(0x30000)
#define INT16_TEST_MATRIX_SRC2_ADDR UINT64_C(0x40000)
#define INT16_TEST_MATRIX_BIAS_ADDR UINT64_C(0x50000)
#define INT16_TEST_MATRIX_REQUANT_ADDR UINT64_C(0x60000)

static uint8_t int16_test_l1[INT16_TEST_L1_BYTES];
static uint8_t int16_test_ddr[INT16_TEST_DDR_BYTES];
static npu_model_t int16_test_model;
static npu_config_t int16_test_config;

static uint32_t int16_test_dtype_bytes(npu_dtype_t dtype)
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

static uint32_t int16_test_storage_bytes(npu_dtype_t dtype,
                                         uint32_t length)
{
    if (dtype == NPU_DTYPE_INT4) {
        return (length + 1u) / 2u;
    }
    return length * int16_test_dtype_bytes(dtype);
}

static npu_tensor_t int16_test_tensor(npu_dtype_t dtype,
                                      uint64_t addr,
                                      uint32_t rows,
                                      uint32_t length)
{
    npu_tensor_t tensor = {0};
    uint32_t row_bytes =
        int16_test_storage_bytes(dtype, length);

    tensor.space = NPU_SPACE_L1;
    tensor.dtype = dtype;
    tensor.addr = addr;
    tensor.region_bytes = (uint64_t)rows * row_bytes;
    tensor.row_stride_bytes = row_bytes;
    return tensor;
}

static int int16_test_init(void)
{
    npu_config_reference(&int16_test_config);
    (void)memset(int16_test_l1, 0, sizeof(int16_test_l1));
    (void)memset(int16_test_ddr, 0, sizeof(int16_test_ddr));
    return npu_model_init(
               &int16_test_model, &int16_test_config,
               int16_test_l1, sizeof(int16_test_l1),
               int16_test_ddr, sizeof(int16_test_ddr)) ==
           NPU_STATUS_SUCCESS;
}

static int int16_test_write(const npu_tensor_t *tensor,
                            uint32_t row,
                            uint32_t element,
                            int32_t value)
{
    TEST_CHECK_STATUS(
        npu_tensor_write(&int16_test_model, tensor, 0u,
                         row, element, value),
        NPU_STATUS_SUCCESS);
    return 0;
}

static int int16_test_read(const npu_tensor_t *tensor,
                           uint32_t row,
                           uint32_t element,
                           int32_t expected)
{
    int32_t actual = 0;

    TEST_CHECK_STATUS(
        npu_tensor_read(&int16_test_model, tensor, 0u,
                        row, element, &actual),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(actual == expected);
    return 0;
}

static int int16_test_write_values(const npu_tensor_t *tensor,
                                   const int32_t *values,
                                   uint32_t length)
{
    uint32_t element;
    int line;

    for (element = 0u; element < length; element++) {
        line = int16_test_write(
            tensor, 0u, element, values[element]);
        if (line != 0) {
            return line;
        }
    }
    return 0;
}

static int int16_test_check_values(const npu_tensor_t *tensor,
                                   const int32_t *expected,
                                   uint32_t length)
{
    uint32_t element;
    int line;

    for (element = 0u; element < length; element++) {
        line = int16_test_read(
            tensor, 0u, element, expected[element]);
        if (line != 0) {
            return line;
        }
    }
    return 0;
}

static int int16_test_memory(void)
{
    static const int32_t values[] = {
        INT16_MIN, -1, 0, INT16_MAX
    };
    static const uint8_t expected_bytes[] = {
        0x00u, 0x80u, 0xffu, 0xffu,
        0x00u, 0x00u, 0xffu, 0x7fu
    };
    npu_tensor_t tensor;
    npu_tensor_t manual;
    uint32_t index;
    int line;

    TEST_CHECK(int16_test_init());
    tensor = int16_test_tensor(
        NPU_DTYPE_INT16, UINT64_C(0x1000), 1u, 4u);
    line = int16_test_write_values(&tensor, values, 4u);
    if (line != 0) {
        return line;
    }
    for (index = 0u; index < sizeof(expected_bytes); index++) {
        TEST_CHECK(
            int16_test_l1[(size_t)tensor.addr + index] ==
            expected_bytes[index]);
    }
    line = int16_test_check_values(&tensor, values, 4u);
    if (line != 0) {
        return line;
    }

    manual = int16_test_tensor(
        NPU_DTYPE_INT16, UINT64_C(0x1100), 1u, 2u);
    int16_test_l1[(size_t)manual.addr] = 0x34u;
    int16_test_l1[(size_t)manual.addr + 1u] = 0x12u;
    int16_test_l1[(size_t)manual.addr + 2u] = 0x00u;
    int16_test_l1[(size_t)manual.addr + 3u] = 0x80u;
    line = int16_test_read(&manual, 0u, 0u, 0x1234);
    if (line != 0) {
        return line;
    }
    return int16_test_read(&manual, 0u, 1u, INT16_MIN);
}

static int int16_test_dma_case(
    npu_dtype_t src_dtype,
    npu_dtype_t dst_dtype,
    npu_dma_convert_t mode,
    const int32_t *source,
    const int32_t *expected,
    uint32_t length)
{
    npu_dma_desc_t desc = {0};
    npu_tensor_t src;
    npu_tensor_t dst;
    uint32_t src_bytes =
        int16_test_storage_bytes(src_dtype, length);
    uint32_t dst_bytes =
        int16_test_storage_bytes(dst_dtype, length);
    uint64_t progress = UINT64_MAX;
    int line;

    TEST_CHECK(int16_test_init());
    src = int16_test_tensor(
        src_dtype, INT16_TEST_DMA_SRC_ADDR, 1u, length);
    dst = int16_test_tensor(
        dst_dtype, INT16_TEST_DMA_DST_ADDR, 1u, length);
    line = int16_test_write_values(&src, source, length);
    if (line != 0) {
        return line;
    }

    desc.rank = 1u;
    desc.src_space = NPU_SPACE_L1;
    desc.dst_space = NPU_SPACE_L1;
    desc.src_dtype = src_dtype;
    desc.dst_dtype = dst_dtype;
    desc.convert_mode = mode;
    desc.src_addr = src.addr;
    desc.dst_addr = dst.addr;
    desc.src_region_bytes = src_bytes;
    desc.dst_region_bytes = dst_bytes;
    desc.shape[0] = length;
    desc.burst_beats = 1u;
    desc.max_outstanding = 1u;

    TEST_CHECK_STATUS(
        npu_dma_execute(&int16_test_model, NPU_DMA_COPY_1D,
                        &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == dst_bytes);
    return int16_test_check_values(&dst, expected, length);
}

static int int16_test_dma(void)
{
    static const int32_t int4_values[] = {-8, -1, 0, 7};
    static const int32_t int8_values[] = {-128, -1, 0, 127};
    static const int32_t int16_values[] = {
        INT16_MIN, -1, 0, INT16_MAX
    };
    static const int32_t narrow_32_to_16[] = {
        -50000, INT16_MIN, INT16_MAX, 50000
    };
    static const int32_t expected_16[] = {
        INT16_MIN, INT16_MIN, INT16_MAX, INT16_MAX
    };
    static const int32_t narrow_to_8[] = {
        -500, -128, 127, 500
    };
    static const int32_t expected_8[] = {
        -128, -128, 127, 127
    };
    static const int32_t narrow_to_4[] = {
        -20, -8, 7, 20
    };
    static const int32_t expected_4[] = {
        -8, -8, 7, 7
    };
    int line;

#define INT16_TEST_DMA_CASE(src, dst, mode, values, expected)       \
    do {                                                            \
        line = int16_test_dma_case(                                  \
            (src), (dst), (mode), (values), (expected), 4u);        \
        if (line != 0) {                                             \
            return line;                                             \
        }                                                            \
    } while (0)

    INT16_TEST_DMA_CASE(
        NPU_DTYPE_INT4, NPU_DTYPE_INT8, NPU_DMA_SIGN_EXTEND,
        int4_values, int4_values);
    INT16_TEST_DMA_CASE(
        NPU_DTYPE_INT4, NPU_DTYPE_INT16, NPU_DMA_SIGN_EXTEND,
        int4_values, int4_values);
    INT16_TEST_DMA_CASE(
        NPU_DTYPE_INT4, NPU_DTYPE_INT32, NPU_DMA_SIGN_EXTEND,
        int4_values, int4_values);
    INT16_TEST_DMA_CASE(
        NPU_DTYPE_INT8, NPU_DTYPE_INT16, NPU_DMA_SIGN_EXTEND,
        int8_values, int8_values);
    INT16_TEST_DMA_CASE(
        NPU_DTYPE_INT8, NPU_DTYPE_INT32, NPU_DMA_SIGN_EXTEND,
        int8_values, int8_values);
    INT16_TEST_DMA_CASE(
        NPU_DTYPE_INT16, NPU_DTYPE_INT32, NPU_DMA_SIGN_EXTEND,
        int16_values, int16_values);

    INT16_TEST_DMA_CASE(
        NPU_DTYPE_INT32, NPU_DTYPE_INT16,
        NPU_DMA_SATURATE_NARROW,
        narrow_32_to_16, expected_16);
    INT16_TEST_DMA_CASE(
        NPU_DTYPE_INT32, NPU_DTYPE_INT8,
        NPU_DMA_SATURATE_NARROW,
        narrow_to_8, expected_8);
    INT16_TEST_DMA_CASE(
        NPU_DTYPE_INT32, NPU_DTYPE_INT4,
        NPU_DMA_SATURATE_NARROW,
        narrow_to_4, expected_4);
    INT16_TEST_DMA_CASE(
        NPU_DTYPE_INT16, NPU_DTYPE_INT8,
        NPU_DMA_SATURATE_NARROW,
        narrow_to_8, expected_8);
    INT16_TEST_DMA_CASE(
        NPU_DTYPE_INT16, NPU_DTYPE_INT4,
        NPU_DMA_SATURATE_NARROW,
        narrow_to_4, expected_4);
    INT16_TEST_DMA_CASE(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4,
        NPU_DMA_SATURATE_NARROW,
        narrow_to_4, expected_4);

#undef INT16_TEST_DMA_CASE

    return 0;
}

static npu_matrix_desc_t int16_test_matrix_desc(
    uint32_t m,
    uint32_t n,
    uint32_t k)
{
    npu_matrix_desc_t desc = {0};
    uint64_t k_tiles =
        ((uint64_t)k + int16_test_config.kt - 1u) /
        int16_test_config.kt;
    uint64_t n_tiles =
        ((uint64_t)n + int16_test_config.nt - 1u) /
        int16_test_config.nt;
    uint64_t b_elements =
        k_tiles * n_tiles *
        int16_test_config.kt *
        int16_test_config.nt;
    uint32_t b_bytes = (uint32_t)(b_elements * 2u);

    desc.m = m;
    desc.n = n;
    desc.k = k;
    desc.batch_count = 1u;
    desc.a = int16_test_tensor(
        NPU_DTYPE_INT16, INT16_TEST_MATRIX_A_ADDR, m, k);
    desc.b = int16_test_tensor(
        NPU_DTYPE_INT16, INT16_TEST_MATRIX_B_ADDR,
        1u, (uint32_t)b_elements);
    desc.b.row_stride_bytes = 0u;
    desc.b.batch_stride_bytes = b_bytes;
    desc.c = int16_test_tensor(
        NPU_DTYPE_INT16, INT16_TEST_MATRIX_C_ADDR, m, n);
    desc.src2 = int16_test_tensor(
        NPU_DTYPE_INT32, INT16_TEST_MATRIX_SRC2_ADDR, m, n);
    desc.requant_addr = INT16_TEST_MATRIX_REQUANT_ADDR;
    desc.requant_count = 1u;
    desc.requant_region_bytes = 8u;
    desc.b_tiled = 1u;
    desc.final_output = 1u;
    desc.requant_enable = 1u;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    int16_test_l1[INT16_TEST_MATRIX_REQUANT_ADDR] = 1u;
    return desc;
}

static int int16_test_matrix_write_b(
    const npu_matrix_desc_t *desc,
    uint32_t inner,
    uint32_t column,
    int32_t value)
{
    uint64_t n_tiles =
        ((uint64_t)desc->n + int16_test_config.nt - 1u) /
        int16_test_config.nt;
    uint64_t linear =
        (((((uint64_t)inner / int16_test_config.kt) *
               n_tiles +
           column / int16_test_config.nt) *
              int16_test_config.kt +
          inner % int16_test_config.kt) *
             int16_test_config.nt) +
        column % int16_test_config.nt;

    TEST_CHECK(linear <= UINT32_MAX);
    return int16_test_write(
        &desc->b, 0u, (uint32_t)linear, value);
}

static int int16_test_matrix(void)
{
    npu_matrix_desc_t desc;
    npu_tensor_t bias;
    uint64_t progress = UINT64_MAX;
    int line;

    TEST_CHECK(int16_test_init());
    desc = int16_test_matrix_desc(2u, 1u, 2u);
    desc.bias_addr = INT16_TEST_MATRIX_BIAS_ADDR;
    desc.bias_count = 1u;
    desc.bias_stride_bytes = 4u;
    desc.bias_enable = 1u;
    desc.residual_enable = 1u;
    bias = int16_test_tensor(
        NPU_DTYPE_INT32, INT16_TEST_MATRIX_BIAS_ADDR, 1u, 1u);

    line = int16_test_write(&desc.a, 0u, 0u, 100);
    if (line != 0) {
        return line;
    }
    line = int16_test_write(&desc.a, 0u, 1u, 20);
    if (line != 0) {
        return line;
    }
    line = int16_test_write(&desc.a, 1u, 0u, -100);
    if (line != 0) {
        return line;
    }
    line = int16_test_write(&desc.a, 1u, 1u, 20);
    if (line != 0) {
        return line;
    }
    line = int16_test_matrix_write_b(&desc, 0u, 0u, 2);
    if (line != 0) {
        return line;
    }
    line = int16_test_matrix_write_b(&desc, 1u, 0u, -3);
    if (line != 0) {
        return line;
    }
    line = int16_test_write(&bias, 0u, 0u, 7);
    if (line != 0) {
        return line;
    }
    line = int16_test_write(&desc.src2, 0u, 0u, 10);
    if (line != 0) {
        return line;
    }
    line = int16_test_write(&desc.src2, 1u, 0u, -10);
    if (line != 0) {
        return line;
    }

    TEST_CHECK_STATUS(
        npu_matrix_execute(&int16_test_model, NPU_MATRIX_GEMM,
                           &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 2u);
    line = int16_test_read(&desc.c, 0u, 0u, 157);
    if (line != 0) {
        return line;
    }
    line = int16_test_read(&desc.c, 1u, 0u, -263);
    if (line != 0) {
        return line;
    }

    desc.src2.dtype = NPU_DTYPE_INT16;
    TEST_CHECK_STATUS(
        npu_matrix_execute(&int16_test_model, NPU_MATRIX_GEMM,
                           &desc, &progress),
        NPU_STATUS_DTYPE_UNSUPPORTED);
    TEST_CHECK(progress == 0u);

    TEST_CHECK(int16_test_init());
    desc = int16_test_matrix_desc(2u, 1u, 1u);
    line = int16_test_write(&desc.a, 0u, 0u, INT16_MAX);
    if (line != 0) {
        return line;
    }
    line = int16_test_write(&desc.a, 1u, 0u, INT16_MIN);
    if (line != 0) {
        return line;
    }
    line = int16_test_matrix_write_b(&desc, 0u, 0u, 2);
    if (line != 0) {
        return line;
    }
    TEST_CHECK_STATUS(
        npu_matrix_execute(&int16_test_model, NPU_MATRIX_GEMM,
                           &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 2u);
    line = int16_test_read(&desc.c, 0u, 0u, INT16_MAX);
    if (line != 0) {
        return line;
    }
    return int16_test_read(&desc.c, 1u, 0u, INT16_MIN);
}

static npu_vector_desc_t int16_test_vector_desc(
    npu_dtype_t src0_dtype,
    npu_dtype_t src1_dtype,
    npu_dtype_t src2_dtype,
    npu_dtype_t dst_dtype,
    uint32_t length)
{
    npu_vector_desc_t desc = {0};

    desc.rows = 1u;
    desc.length = length;
    desc.valid_length = length;
    desc.src0 = int16_test_tensor(
        src0_dtype, UINT64_C(0x1000), 1u, length);
    desc.src1 = int16_test_tensor(
        src1_dtype, UINT64_C(0x2000), 1u, length);
    desc.src2 = int16_test_tensor(
        src2_dtype, UINT64_C(0x3000), 1u, length);
    desc.dst = int16_test_tensor(
        dst_dtype, UINT64_C(0x4000), 1u, length);
    desc.mask = int16_test_tensor(
        NPU_DTYPE_INT8, UINT64_C(0x5000), 1u, length);
    desc.broadcast0 = NPU_BROADCAST_NONE;
    desc.broadcast1 = NPU_BROADCAST_NONE;
    desc.broadcast2 = NPU_BROADCAST_NONE;
    desc.compare_mode = NPU_COMPARE_GT;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.src0_scale_bits = UINT32_C(0x3f800000);
    desc.src1_scale_bits = UINT32_C(0x3f800000);
    desc.src2_scale_bits = UINT32_C(0x3f800000);
    desc.dst_scale_bits = UINT32_C(0x3f800000);
    return desc;
}

static int int16_test_vector_add_mode(
    npu_overflow_mode_t mode,
    npu_status_t expected_status,
    const int32_t *expected)
{
    static const int32_t src0[] = {30000, -30000};
    static const int32_t src1[] = {10000, -10000};
    static const int32_t sentinel[] = {123, -123};
    npu_vector_desc_t desc;
    uint64_t progress = UINT64_MAX;
    int line;

    TEST_CHECK(int16_test_init());
    desc = int16_test_vector_desc(
        NPU_DTYPE_INT16, NPU_DTYPE_INT16,
        NPU_DTYPE_INT32, NPU_DTYPE_INT16, 2u);
    desc.overflow_mode = mode;
    line = int16_test_write_values(&desc.src0, src0, 2u);
    if (line != 0) {
        return line;
    }
    line = int16_test_write_values(&desc.src1, src1, 2u);
    if (line != 0) {
        return line;
    }
    line = int16_test_write_values(&desc.dst, sentinel, 2u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK_STATUS(
        npu_vector_execute(&int16_test_model, NPU_VECTOR_ADD,
                           &desc, &progress),
        expected_status);
    if (expected_status == NPU_STATUS_SUCCESS) {
        TEST_CHECK(progress == 2u);
        return int16_test_check_values(&desc.dst, expected, 2u);
    }
    TEST_CHECK(progress == 0u);
    return int16_test_check_values(&desc.dst, sentinel, 2u);
}

static int int16_test_vector(void)
{
    static const int32_t saturate_expected[] = {
        INT16_MAX, INT16_MIN
    };
    static const int32_t wrap_expected[] = {-25536, 25536};
    static const int32_t mul_src0[] = {INT16_MAX, INT16_MIN};
    static const int32_t mul_src1[] = {INT16_MIN, INT16_MAX};
    static const int32_t mul_expected[] = {
        -1073709056, -1073709056
    };
    static const int32_t fma_src2[] = {7, -7};
    static const int32_t fma_expected[] = {
        -1073709049, -1073709063
    };
    static const int32_t cmp_src0[] = {4, -3};
    static const int32_t cmp_src1[] = {-2, -3};
    static const int32_t cmp_expected[] = {1, 0};
    npu_vector_desc_t desc;
    uint64_t progress = UINT64_MAX;
    int line;

    line = int16_test_vector_add_mode(
        NPU_OVERFLOW_SATURATE, NPU_STATUS_SUCCESS,
        saturate_expected);
    if (line != 0) {
        return line;
    }
    line = int16_test_vector_add_mode(
        NPU_OVERFLOW_WRAP, NPU_STATUS_SUCCESS,
        wrap_expected);
    if (line != 0) {
        return line;
    }
    line = int16_test_vector_add_mode(
        NPU_OVERFLOW_ERROR, NPU_STATUS_NUMERIC_EXCEPTION,
        saturate_expected);
    if (line != 0) {
        return line;
    }

    TEST_CHECK(int16_test_init());
    desc = int16_test_vector_desc(
        NPU_DTYPE_INT16, NPU_DTYPE_INT16,
        NPU_DTYPE_INT32, NPU_DTYPE_INT32, 2u);
    line = int16_test_write_values(&desc.src0, mul_src0, 2u);
    if (line != 0) {
        return line;
    }
    line = int16_test_write_values(&desc.src1, mul_src1, 2u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK_STATUS(
        npu_vector_execute(&int16_test_model, NPU_VECTOR_MUL,
                           &desc, &progress),
        NPU_STATUS_SUCCESS);
    line = int16_test_check_values(&desc.dst, mul_expected, 2u);
    if (line != 0) {
        return line;
    }

    line = int16_test_write_values(&desc.src2, fma_src2, 2u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK_STATUS(
        npu_vector_execute(&int16_test_model, NPU_VECTOR_FMA,
                           &desc, &progress),
        NPU_STATUS_SUCCESS);
    line = int16_test_check_values(&desc.dst, fma_expected, 2u);
    if (line != 0) {
        return line;
    }

    TEST_CHECK(int16_test_init());
    desc = int16_test_vector_desc(
        NPU_DTYPE_INT16, NPU_DTYPE_INT16,
        NPU_DTYPE_INT32, NPU_DTYPE_INT8, 2u);
    line = int16_test_write_values(&desc.src0, cmp_src0, 2u);
    if (line != 0) {
        return line;
    }
    line = int16_test_write_values(&desc.src1, cmp_src1, 2u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK_STATUS(
        npu_vector_execute(&int16_test_model, NPU_VECTOR_CMP,
                           &desc, &progress),
        NPU_STATUS_SUCCESS);
    line = int16_test_check_values(&desc.dst, cmp_expected, 2u);
    if (line != 0) {
        return line;
    }

    TEST_CHECK(int16_test_init());
    desc = int16_test_vector_desc(
        NPU_DTYPE_INT16, NPU_DTYPE_INT8,
        NPU_DTYPE_INT32, NPU_DTYPE_INT32, 1u);
    TEST_CHECK_STATUS(
        npu_vector_execute(&int16_test_model, NPU_VECTOR_MUL,
                           &desc, &progress),
        NPU_STATUS_DTYPE_UNSUPPORTED);
    TEST_CHECK(progress == 0u);
    return 0;
}

static int int16_test_complex(void)
{
    static const int32_t input[] = {1000, -1000};
    static const int32_t expected[] = {INT16_MAX, INT16_MIN};
    npu_complex_desc_t desc = {0};
    uint64_t progress = UINT64_MAX;
    int line;

    TEST_CHECK(int16_test_init());
    desc.rows = 1u;
    desc.length = 2u;
    desc.valid_length = 2u;
    desc.function = NPU_FUNC_TANH;
    desc.src0 = int16_test_tensor(
        NPU_DTYPE_INT16, UINT64_C(0x1000), 1u, 2u);
    desc.dst = int16_test_tensor(
        NPU_DTYPE_INT16, UINT64_C(0x4000), 1u, 2u);
    desc.src0_scale = 0.01f;
    desc.dst_scale = 0.000001f;
    desc.input_clip_min = -16.0f;
    desc.input_clip_max = 16.0f;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.scale_mode = NPU_SCALE_PER_TENSOR;
    desc.mask_mode = NPU_MASK_NONE;
    desc.all_mask_mode = NPU_ALL_MASK_WRITE_ZERO;

    line = int16_test_write_values(&desc.src0, input, 2u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK_STATUS(
        npu_complex_execute(&int16_test_model, NPU_COMPLEX_ACT,
                            &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 2u);
    return int16_test_check_values(&desc.dst, expected, 2u);
}

static int int16_test_regression_product(
    npu_dtype_t dtype,
    int32_t input,
    int32_t weight,
    int32_t *product)
{
    npu_vector_desc_t desc;
    uint64_t progress = UINT64_MAX;

    TEST_CHECK(product != (int32_t *)0);
    TEST_CHECK(int16_test_init());
    desc = int16_test_vector_desc(
        dtype, dtype, NPU_DTYPE_INT32,
        NPU_DTYPE_INT32, 1u);
    TEST_CHECK_STATUS(
        npu_tensor_write(&int16_test_model, &desc.src0,
                         0u, 0u, 0u, input),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_tensor_write(&int16_test_model, &desc.src1,
                         0u, 0u, 0u, weight),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_vector_execute(&int16_test_model, NPU_VECTOR_MUL,
                           &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 1u);
    TEST_CHECK_STATUS(
        npu_tensor_read(&int16_test_model, &desc.dst,
                        0u, 0u, 0u, product),
        NPU_STATUS_SUCCESS);
    return 0;
}

static int int16_test_regression_precision(void)
{
    const float real_input = 0.73125f;
    const float real_weight = 1.2345f;
    const float real_bias = -0.125f;
    const float input_scale_int8 = 1.0f / 127.0f;
    const float weight_scale_int8 = 2.0f / 127.0f;
    const float input_scale_int16 = 1.0f / 32767.0f;
    const float weight_scale_int16 = 2.0f / 32767.0f;
    int32_t input_int8;
    int32_t weight_int8;
    int32_t input_int16;
    int32_t weight_int16;
    int32_t product_int8;
    int32_t product_int16;
    float reference;
    float prediction_int8;
    float prediction_int16;
    float error_int8;
    float error_int16;
    int line;

    input_int8 = npu_float_to_int(
        real_input / input_scale_int8,
        NPU_ROUND_NEAREST_EVEN);
    weight_int8 = npu_float_to_int(
        real_weight / weight_scale_int8,
        NPU_ROUND_NEAREST_EVEN);
    input_int16 = npu_float_to_int(
        real_input / input_scale_int16,
        NPU_ROUND_NEAREST_EVEN);
    weight_int16 = npu_float_to_int(
        real_weight / weight_scale_int16,
        NPU_ROUND_NEAREST_EVEN);

    line = int16_test_regression_product(
        NPU_DTYPE_INT8, input_int8, weight_int8,
        &product_int8);
    if (line != 0) {
        return line;
    }
    line = int16_test_regression_product(
        NPU_DTYPE_INT16, input_int16, weight_int16,
        &product_int16);
    if (line != 0) {
        return line;
    }

    reference = real_input * real_weight + real_bias;
    prediction_int8 =
        (float)product_int8 *
            input_scale_int8 * weight_scale_int8 +
        real_bias;
    prediction_int16 =
        (float)product_int16 *
            input_scale_int16 * weight_scale_int16 +
        real_bias;
    error_int8 = test_abs_float(prediction_int8 - reference);
    error_int16 = test_abs_float(prediction_int16 - reference);

    TEST_CHECK(error_int16 < error_int8);
    TEST_CHECK(error_int16 < 0.0001f);
    TEST_CHECK(error_int8 > 0.001f);
    return 0;
}

int test_int16(void)
{
    int line;

    line = int16_test_memory();
    if (line != 0) {
        return line;
    }
    line = int16_test_dma();
    if (line != 0) {
        return line;
    }
    line = int16_test_matrix();
    if (line != 0) {
        return line;
    }
    line = int16_test_vector();
    if (line != 0) {
        return line;
    }
    line = int16_test_complex();
    if (line != 0) {
        return line;
    }
    return int16_test_regression_precision();
}
