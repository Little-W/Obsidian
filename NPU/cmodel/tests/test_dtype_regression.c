#include "test_util.h"

#include "npu_lsc_cycle.h"

#include <limits.h>
#include <stdio.h>
#include <string.h>

#define DTYPE_TEST_L1_BYTES NPU_REF_L1_BYTES
#define DTYPE_TEST_DDR_BYTES (256u * 1024u)
#define DTYPE_TEST_LENGTH 5u

static uint8_t dtype_test_l1[DTYPE_TEST_L1_BYTES];
static uint8_t dtype_test_ddr[DTYPE_TEST_DDR_BYTES];
static npu_model_t dtype_test_model;
static npu_config_t dtype_test_config;

static const npu_dtype_t dtype_test_types[] = {
    NPU_DTYPE_INT4,
    NPU_DTYPE_INT8,
    NPU_DTYPE_INT16,
    NPU_DTYPE_INT32
};

static uint32_t dtype_test_bits(npu_dtype_t dtype)
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
    return 32u;
}

static uint32_t dtype_test_storage_bytes(npu_dtype_t dtype,
                                         uint32_t length)
{
    if (dtype == NPU_DTYPE_INT4) {
        return (length + 1u) / 2u;
    }
    return length * (dtype_test_bits(dtype) / 8u);
}

static int32_t dtype_test_min(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT4) {
        return -8;
    }
    if (dtype == NPU_DTYPE_INT8) {
        return INT8_MIN;
    }
    if (dtype == NPU_DTYPE_INT16) {
        return INT16_MIN;
    }
    return INT32_MIN;
}

static int32_t dtype_test_max(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT4) {
        return 7;
    }
    if (dtype == NPU_DTYPE_INT8) {
        return INT8_MAX;
    }
    if (dtype == NPU_DTYPE_INT16) {
        return INT16_MAX;
    }
    return INT32_MAX;
}

static int32_t dtype_test_clamp(int32_t value,
                                npu_dtype_t dtype)
{
    int32_t minimum = dtype_test_min(dtype);
    int32_t maximum = dtype_test_max(dtype);

    if (value < minimum) {
        return minimum;
    }
    if (value > maximum) {
        return maximum;
    }
    return value;
}

static npu_tensor_t dtype_test_tensor(npu_dtype_t dtype,
                                      uint64_t addr,
                                      uint32_t length)
{
    npu_tensor_t tensor = {0};
    uint32_t bytes = dtype_test_storage_bytes(dtype, length);

    tensor.space = NPU_SPACE_L1;
    tensor.dtype = dtype;
    tensor.addr = addr;
    tensor.region_bytes = bytes;
    tensor.row_stride_bytes = bytes;
    return tensor;
}

static int dtype_test_reset(void)
{
    npu_config_reference(&dtype_test_config);
    (void)memset(dtype_test_l1, 0, sizeof(dtype_test_l1));
    (void)memset(dtype_test_ddr, 0, sizeof(dtype_test_ddr));
    TEST_CHECK_STATUS(
        npu_model_init(
            &dtype_test_model, &dtype_test_config,
            dtype_test_l1, sizeof(dtype_test_l1),
            dtype_test_ddr, sizeof(dtype_test_ddr)),
        NPU_STATUS_SUCCESS);
    return 0;
}

static int dtype_test_write_values(const npu_tensor_t *tensor,
                                   const int32_t values[],
                                   uint32_t length)
{
    uint32_t element;

    for (element = 0u; element < length; element++) {
        TEST_CHECK_STATUS(
            npu_tensor_write(
                &dtype_test_model, tensor, 0u, 0u,
                element, values[element]),
            NPU_STATUS_SUCCESS);
    }
    return 0;
}

static int dtype_test_check_values(const npu_tensor_t *tensor,
                                   const int32_t values[],
                                   uint32_t length)
{
    uint32_t element;
    int32_t actual;

    for (element = 0u; element < length; element++) {
        TEST_CHECK_STATUS(
            npu_tensor_read(
                &dtype_test_model, tensor, 0u, 0u,
                element, &actual),
            NPU_STATUS_SUCCESS);
        TEST_CHECK(actual == values[element]);
    }
    return 0;
}

static void dtype_test_source_values(npu_dtype_t dtype,
                                     int32_t values[DTYPE_TEST_LENGTH])
{
    if (dtype == NPU_DTYPE_INT4) {
        values[0] = -8;
        values[1] = -1;
        values[2] = 0;
        values[3] = 1;
        values[4] = 7;
    } else if (dtype == NPU_DTYPE_INT8) {
        values[0] = -128;
        values[1] = -9;
        values[2] = 0;
        values[3] = 8;
        values[4] = 127;
    } else if (dtype == NPU_DTYPE_INT16) {
        values[0] = INT16_MIN;
        values[1] = -129;
        values[2] = 0;
        values[3] = 128;
        values[4] = INT16_MAX;
    } else {
        values[0] = -100000;
        values[1] = -32769;
        values[2] = 0;
        values[3] = 32768;
        values[4] = 100000;
    }
}

static int dtype_test_tensor_storage(void)
{
    uint32_t type_index;
    int32_t values[DTYPE_TEST_LENGTH];
    npu_tensor_t tensor;
    int line;

    TEST_CHECK(dtype_test_reset() == 0);
    for (type_index = 0u;
         type_index <
             (uint32_t)(sizeof(dtype_test_types) /
                        sizeof(dtype_test_types[0]));
         type_index++) {
        npu_dtype_t dtype = dtype_test_types[type_index];

        dtype_test_source_values(dtype, values);
        tensor = dtype_test_tensor(
            dtype, UINT64_C(0x1000) +
                       (uint64_t)type_index * UINT64_C(0x100),
            DTYPE_TEST_LENGTH);
        line = dtype_test_write_values(
            &tensor, values, DTYPE_TEST_LENGTH);
        if (line != 0) {
            return line;
        }
        line = dtype_test_check_values(
            &tensor, values, DTYPE_TEST_LENGTH);
        if (line != 0) {
            return line;
        }
        if (dtype == NPU_DTYPE_INT4) {
            size_t tail =
                (size_t)tensor.addr +
                dtype_test_storage_bytes(
                    dtype, DTYPE_TEST_LENGTH) -
                1u;
            TEST_CHECK((dtype_test_l1[tail] & 0xf0u) == 0u);
        }
    }
    return 0;
}

static int dtype_test_dma_all_pairs(void)
{
    uint32_t src_index;
    uint32_t dst_index;
    int32_t source[DTYPE_TEST_LENGTH];
    int32_t expected[DTYPE_TEST_LENGTH];
    npu_tensor_t src;
    npu_tensor_t dst;
    npu_dma_desc_t desc;
    uint64_t progress;
    uint32_t element;
    int line;

    for (src_index = 0u; src_index < 4u; src_index++) {
        for (dst_index = 0u; dst_index < 4u; dst_index++) {
            npu_dtype_t src_dtype = dtype_test_types[src_index];
            npu_dtype_t dst_dtype = dtype_test_types[dst_index];
            uint32_t src_bits = dtype_test_bits(src_dtype);
            uint32_t dst_bits = dtype_test_bits(dst_dtype);

            TEST_CHECK(dtype_test_reset() == 0);
            dtype_test_source_values(src_dtype, source);
            for (element = 0u;
                 element < DTYPE_TEST_LENGTH;
                 element++) {
                expected[element] =
                    dtype_test_clamp(source[element], dst_dtype);
            }
            src = dtype_test_tensor(
                src_dtype, UINT64_C(0x10000),
                DTYPE_TEST_LENGTH);
            dst = dtype_test_tensor(
                dst_dtype, UINT64_C(0x20000),
                DTYPE_TEST_LENGTH);
            line = dtype_test_write_values(
                &src, source, DTYPE_TEST_LENGTH);
            if (line != 0) {
                return line;
            }

            (void)memset(&desc, 0, sizeof(desc));
            desc.rank = 1u;
            desc.src_space = NPU_SPACE_L1;
            desc.dst_space = NPU_SPACE_L1;
            desc.src_dtype = src_dtype;
            desc.dst_dtype = dst_dtype;
            if (src_bits == dst_bits) {
                desc.convert_mode = NPU_DMA_CONVERT_NONE;
            } else if (src_bits < dst_bits) {
                desc.convert_mode = NPU_DMA_SIGN_EXTEND;
            } else {
                desc.convert_mode =
                    NPU_DMA_SATURATE_NARROW;
            }
            desc.src_addr = src.addr;
            desc.dst_addr = dst.addr;
            desc.src_region_bytes = src.region_bytes;
            desc.dst_region_bytes = dst.region_bytes;
            desc.shape[0] = DTYPE_TEST_LENGTH;
            desc.burst_beats = 1u;
            desc.max_outstanding = 1u;
            progress = 0u;

            TEST_CHECK_STATUS(
                npu_dma_execute(
                    &dtype_test_model, NPU_DMA_COPY_1D,
                    &desc, &progress),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(
                progress ==
                dtype_test_storage_bytes(
                    dst_dtype, DTYPE_TEST_LENGTH));
            line = dtype_test_check_values(
                &dst, expected, DTYPE_TEST_LENGTH);
            if (line != 0) {
                return line;
            }
        }
    }
    return 0;
}

static int dtype_test_matrix_pair_valid(npu_dtype_t a,
                                        npu_dtype_t b)
{
    return (a == NPU_DTYPE_INT4 &&
            b == NPU_DTYPE_INT4) ||
           (a == NPU_DTYPE_INT8 &&
            b == NPU_DTYPE_INT8) ||
           (a == NPU_DTYPE_INT8 &&
            b == NPU_DTYPE_INT4) ||
           (a == NPU_DTYPE_INT16 &&
            b == NPU_DTYPE_INT16);
}

static int dtype_test_matrix_all_combinations(void)
{
    uint32_t a_index;
    uint32_t b_index;
    uint32_t c_index;
    npu_matrix_desc_t desc;
    npu_tensor_t a;
    npu_tensor_t b;
    npu_tensor_t c;
    uint32_t b_elements;
    uint64_t progress;
    int32_t output;
    npu_status_t expected_status;
    npu_status_t actual_status;

    b_elements =
        (uint32_t)dtype_test_config.kt *
        (uint32_t)dtype_test_config.nt;
    for (a_index = 0u; a_index < 4u; a_index++) {
        for (b_index = 0u; b_index < 4u; b_index++) {
            for (c_index = 0u; c_index < 4u; c_index++) {
                npu_dtype_t a_dtype =
                    dtype_test_types[a_index];
                npu_dtype_t b_dtype =
                    dtype_test_types[b_index];
                npu_dtype_t c_dtype =
                    dtype_test_types[c_index];

                TEST_CHECK(dtype_test_reset() == 0);
                b_elements =
                    (uint32_t)dtype_test_config.kt *
                    (uint32_t)dtype_test_config.nt;
                a = dtype_test_tensor(
                    a_dtype, UINT64_C(0x10000), 1u);
                b = dtype_test_tensor(
                    b_dtype, UINT64_C(0x20000),
                    b_elements);
                c = dtype_test_tensor(
                    c_dtype, UINT64_C(0x30000), 1u);
                TEST_CHECK_STATUS(
                    npu_tensor_write(
                        &dtype_test_model, &a, 0u, 0u,
                        0u, 2),
                    NPU_STATUS_SUCCESS);
                TEST_CHECK_STATUS(
                    npu_tensor_write(
                        &dtype_test_model, &b, 0u, 0u,
                        0u, 3),
                    NPU_STATUS_SUCCESS);

                (void)memset(&desc, 0, sizeof(desc));
                desc.m = 1u;
                desc.n = 1u;
                desc.k = 1u;
                desc.batch_count = 1u;
                desc.a = a;
                desc.b = b;
                desc.b.batch_stride_bytes =
                    dtype_test_storage_bytes(
                        b_dtype, b_elements);
                desc.c = c;
                desc.b_tiled = 1u;
                desc.final_output = 1u;
                desc.round_mode =
                    NPU_ROUND_NEAREST_EVEN;
                desc.overflow_mode =
                    NPU_OVERFLOW_SATURATE;
                if (c_dtype != NPU_DTYPE_INT32) {
                    desc.requant_enable = 1u;
                    desc.requant_addr =
                        UINT64_C(0x40000);
                    desc.requant_count = 1u;
                    desc.requant_region_bytes = 8u;
                    dtype_test_l1[0x40000u] = 1u;
                }
                progress = 0u;
                expected_status =
                    dtype_test_matrix_pair_valid(
                        a_dtype, b_dtype)
                        ? NPU_STATUS_SUCCESS
                        : NPU_STATUS_DTYPE_UNSUPPORTED;
                actual_status = npu_matrix_execute(
                    &dtype_test_model, NPU_MATRIX_GEMM,
                    &desc, &progress);
                TEST_CHECK(actual_status == expected_status);
                if (actual_status == NPU_STATUS_SUCCESS) {
                    TEST_CHECK(progress == 1u);
                    TEST_CHECK_STATUS(
                        npu_tensor_read(
                            &dtype_test_model, &c, 0u,
                            0u, 0u, &output),
                        NPU_STATUS_SUCCESS);
                    TEST_CHECK(output == 6);
                }
            }
        }
    }
    return 0;
}

static npu_vector_desc_t dtype_test_vector_desc(
    npu_dtype_t src0_dtype,
    npu_dtype_t src1_dtype,
    npu_dtype_t src2_dtype,
    npu_dtype_t dst_dtype)
{
    npu_vector_desc_t desc;

    (void)memset(&desc, 0, sizeof(desc));
    desc.rows = 1u;
    desc.length = 1u;
    desc.valid_length = 1u;
    desc.src0 = dtype_test_tensor(
        src0_dtype, UINT64_C(0x10000), 1u);
    desc.src1 = dtype_test_tensor(
        src1_dtype, UINT64_C(0x11000), 1u);
    desc.src2 = dtype_test_tensor(
        src2_dtype, UINT64_C(0x12000), 1u);
    desc.dst = dtype_test_tensor(
        dst_dtype, UINT64_C(0x13000), 1u);
    desc.mask = dtype_test_tensor(
        NPU_DTYPE_INT8, UINT64_C(0x14000), 1u);
    desc.src0_scale_bits = UINT32_C(0x3f800000);
    desc.src1_scale_bits = UINT32_C(0x3f800000);
    desc.src2_scale_bits = UINT32_C(0x3f800000);
    desc.dst_scale_bits = UINT32_C(0x3f800000);
    desc.compare_mode = NPU_COMPARE_EQ;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.clamp_min = -1;
    desc.clamp_max = 1;
    return desc;
}

static int dtype_test_run_vector(uint8_t opcode,
                                 npu_vector_desc_t *desc)
{
    uint64_t progress = 0u;

    TEST_CHECK_STATUS(
        npu_tensor_write(
            &dtype_test_model, &desc->src0,
            0u, 0u, 0u, 1),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_tensor_write(
            &dtype_test_model, &desc->src1,
            0u, 0u, 0u, 1),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_tensor_write(
            &dtype_test_model, &desc->src2,
            0u, 0u, 0u, 1),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_tensor_write(
            &dtype_test_model, &desc->mask,
            0u, 0u, 0u, 1),
        NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(
        npu_vector_execute(
            &dtype_test_model, opcode, desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 1u);
    return 0;
}

static int dtype_test_vector_supported_combinations(void)
{
    static const uint8_t same_type_ops[] = {
        NPU_VECTOR_ADD,
        NPU_VECTOR_SUB,
        NPU_VECTOR_MAX,
        NPU_VECTOR_MIN
    };
    static const uint8_t unary_ops[] = {
        NPU_VECTOR_CLAMP,
        NPU_VECTOR_RELU
    };
    uint32_t type_index;
    uint32_t opcode_index;
    uint32_t a_index;
    uint32_t b_index;
    npu_vector_desc_t desc;
    int line;

    for (type_index = 0u; type_index < 4u; type_index++) {
        npu_dtype_t dtype = dtype_test_types[type_index];

        for (opcode_index = 0u;
             opcode_index <
                 (uint32_t)(sizeof(same_type_ops) /
                            sizeof(same_type_ops[0]));
             opcode_index++) {
            TEST_CHECK(dtype_test_reset() == 0);
            desc = dtype_test_vector_desc(
                dtype, dtype, NPU_DTYPE_INT32, dtype);
            line = dtype_test_run_vector(
                same_type_ops[opcode_index], &desc);
            if (line != 0) {
                return line;
            }
        }
        for (opcode_index = 0u;
             opcode_index <
                 (uint32_t)(sizeof(unary_ops) /
                            sizeof(unary_ops[0]));
             opcode_index++) {
            TEST_CHECK(dtype_test_reset() == 0);
            desc = dtype_test_vector_desc(
                dtype, NPU_DTYPE_INT32,
                NPU_DTYPE_INT32, dtype);
            line = dtype_test_run_vector(
                unary_ops[opcode_index], &desc);
            if (line != 0) {
                return line;
            }
        }

        TEST_CHECK(dtype_test_reset() == 0);
        desc = dtype_test_vector_desc(
            dtype, dtype, NPU_DTYPE_INT32,
            NPU_DTYPE_INT8);
        line = dtype_test_run_vector(
            NPU_VECTOR_CMP, &desc);
        if (line != 0) {
            return line;
        }

        TEST_CHECK(dtype_test_reset() == 0);
        desc = dtype_test_vector_desc(
            dtype, dtype, NPU_DTYPE_INT32, dtype);
        desc.mask_enable = 1u;
        line = dtype_test_run_vector(
            NPU_VECTOR_SELECT, &desc);
        if (line != 0) {
            return line;
        }
    }

    for (a_index = 0u; a_index < 4u; a_index++) {
        for (b_index = 0u; b_index < 4u; b_index++) {
            npu_dtype_t a_dtype =
                dtype_test_types[a_index];
            npu_dtype_t b_dtype =
                dtype_test_types[b_index];
            int pair_valid =
                ((a_dtype == NPU_DTYPE_INT4 ||
                  a_dtype == NPU_DTYPE_INT8) &&
                 (b_dtype == NPU_DTYPE_INT4 ||
                  b_dtype == NPU_DTYPE_INT8)) ||
                (a_dtype == NPU_DTYPE_INT16 &&
                 b_dtype == NPU_DTYPE_INT16);

            if (!pair_valid) {
                continue;
            }
            TEST_CHECK(dtype_test_reset() == 0);
            desc = dtype_test_vector_desc(
                a_dtype, b_dtype, NPU_DTYPE_INT32,
                NPU_DTYPE_INT32);
            line = dtype_test_run_vector(
                NPU_VECTOR_MUL, &desc);
            if (line != 0) {
                return line;
            }

            TEST_CHECK(dtype_test_reset() == 0);
            desc = dtype_test_vector_desc(
                a_dtype, b_dtype, NPU_DTYPE_INT32,
                NPU_DTYPE_INT32);
            line = dtype_test_run_vector(
                NPU_VECTOR_FMA, &desc);
            if (line != 0) {
                return line;
            }
        }
    }
    return 0;
}

static int dtype_test_complex_all_pairs(void)
{
    uint32_t src_index;
    uint32_t dst_index;
    npu_complex_desc_t desc;
    uint64_t progress;
    int32_t output;

    for (src_index = 0u; src_index < 4u; src_index++) {
        for (dst_index = 0u; dst_index < 4u; dst_index++) {
            TEST_CHECK(dtype_test_reset() == 0);
            (void)memset(&desc, 0, sizeof(desc));
            desc.rows = 1u;
            desc.length = 1u;
            desc.valid_length = 1u;
            desc.function = NPU_FUNC_SIGMOID;
            desc.src0 = dtype_test_tensor(
                dtype_test_types[src_index],
                UINT64_C(0x10000), 1u);
            desc.dst = dtype_test_tensor(
                dtype_test_types[dst_index],
                UINT64_C(0x11000), 1u);
            desc.src0_scale = 1.0f;
            desc.dst_scale = 1.0f;
            desc.input_clip_min = -8.0f;
            desc.input_clip_max = 8.0f;
            desc.round_mode = NPU_ROUND_NEAREST_EVEN;
            desc.overflow_mode = NPU_OVERFLOW_SATURATE;
            desc.scale_mode = NPU_SCALE_PER_TENSOR;
            desc.mask_mode = NPU_MASK_NONE;
            desc.all_mask_mode =
                NPU_ALL_MASK_WRITE_ZERO;
            TEST_CHECK_STATUS(
                npu_tensor_write(
                    &dtype_test_model, &desc.src0,
                    0u, 0u, 0u, 0),
                NPU_STATUS_SUCCESS);
            progress = 0u;
            TEST_CHECK_STATUS(
                npu_complex_execute(
                    &dtype_test_model, NPU_COMPLEX_ACT,
                    &desc, &progress),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(progress == 1u);
            TEST_CHECK_STATUS(
                npu_tensor_read(
                    &dtype_test_model, &desc.dst,
                    0u, 0u, 0u, &output),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(
                output >= dtype_test_min(
                              desc.dst.dtype) &&
                output <= dtype_test_max(
                              desc.dst.dtype));
        }
    }
    return 0;
}

int test_dtype_regression(void)
{
    int line;

    TEST_CHECK(NPU_DTYPE_INT4 == 0);
    TEST_CHECK(NPU_DTYPE_INT8 == 1);
    TEST_CHECK(NPU_DTYPE_INT32 == 2);
    TEST_CHECK(NPU_DTYPE_INT16 == 3);
    TEST_CHECK(NPU_LSC_MATRIX_DTYPE_MASK == UINT64_C(0xf));

    line = dtype_test_tensor_storage();
    if (line != 0) {
        return line;
    }
    line = dtype_test_dma_all_pairs();
    if (line != 0) {
        return line;
    }
    line = dtype_test_matrix_all_combinations();
    if (line != 0) {
        return line;
    }
    line = dtype_test_vector_supported_combinations();
    if (line != 0) {
        return line;
    }
    line = dtype_test_complex_all_pairs();
    if (line != 0) {
        return line;
    }

    (void)printf(
        "[INFO] dtype cases: tensor=4, dma=16, "
        "matrix=64, vector=42, complex=16\n");
    return 0;
}
