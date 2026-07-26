#include "test_util.h"

#include <limits.h>

#ifdef NPU_VECTOR_ACCEPTANCE_STANDALONE
#include <stdio.h>
#endif

#define VECTOR_ACCEPT_L1_BYTES NPU_REF_L1_BYTES
#define VECTOR_ACCEPT_DDR_BYTES (1024u * 1024u)

static uint8_t vector_accept_l1[VECTOR_ACCEPT_L1_BYTES];
static uint8_t vector_accept_ddr[VECTOR_ACCEPT_DDR_BYTES];
static npu_model_t vector_accept_model;

static void vector_accept_clear(uint8_t *memory, size_t bytes)
{
    size_t index;

    for (index = 0u; index < bytes; index++) {
        memory[index] = 0u;
    }
}

static uint32_t vector_accept_storage_bytes(npu_dtype_t dtype,
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

static npu_tensor_t vector_accept_tensor(npu_dtype_t dtype,
                                         uint64_t addr,
                                         uint32_t length)
{
    uint32_t bytes =
        vector_accept_storage_bytes(dtype, length);
    npu_tensor_t tensor;

    tensor.space = NPU_SPACE_L1;
    tensor.dtype = dtype;
    tensor.addr = addr;
    tensor.region_bytes = bytes;
    tensor.row_stride_bytes = bytes;
    tensor.elem_stride_bytes = 0u;
    tensor.batch_stride_bytes = 0u;
    tensor.start_nibble = 0u;
    return tensor;
}

static int vector_accept_init(void)
{
    npu_config_t config;

    npu_config_reference(&config);
    vector_accept_clear(
        vector_accept_l1, sizeof(vector_accept_l1));
    vector_accept_clear(
        vector_accept_ddr, sizeof(vector_accept_ddr));
    return npu_model_init(
               &vector_accept_model, &config,
               vector_accept_l1, sizeof(vector_accept_l1),
               vector_accept_ddr,
               sizeof(vector_accept_ddr)) ==
           NPU_STATUS_SUCCESS;
}

static npu_vector_desc_t vector_accept_desc(
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
    desc.src0 = vector_accept_tensor(
        src0_dtype, UINT64_C(0x1000), length);
    desc.src1 = vector_accept_tensor(
        src1_dtype, UINT64_C(0x2000), length);
    desc.src2 = vector_accept_tensor(
        src2_dtype, UINT64_C(0x3000), length);
    desc.dst = vector_accept_tensor(
        dst_dtype, UINT64_C(0x4000), length);
    desc.mask = vector_accept_tensor(
        NPU_DTYPE_INT8, UINT64_C(0x5000), length);
    desc.broadcast0 = NPU_BROADCAST_NONE;
    desc.broadcast1 = NPU_BROADCAST_NONE;
    desc.broadcast2 = NPU_BROADCAST_NONE;
    desc.compare_mode = NPU_COMPARE_GT;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.clamp_min = -1;
    desc.clamp_max = 4;
    desc.src0_scale_bits = UINT32_C(0x3f800000);
    desc.src1_scale_bits = UINT32_C(0x3f800000);
    desc.src2_scale_bits = UINT32_C(0x3f800000);
    desc.dst_scale_bits = UINT32_C(0x3f800000);
    return desc;
}

static int vector_accept_write(const npu_tensor_t *tensor,
                               const int32_t *values,
                               uint32_t length)
{
    uint32_t element;

    for (element = 0u; element < length; element++) {
        TEST_CHECK_STATUS(
            npu_tensor_write(
                &vector_accept_model, tensor, 0u, 0u,
                element, values[element]),
            NPU_STATUS_SUCCESS);
    }
    return 0;
}

static int vector_accept_check(const npu_tensor_t *tensor,
                               const int32_t *expected,
                               uint32_t length)
{
    uint32_t element;

    for (element = 0u; element < length; element++) {
        int32_t actual = 0;

        TEST_CHECK_STATUS(
            npu_tensor_read(
                &vector_accept_model, tensor, 0u, 0u,
                element, &actual),
            NPU_STATUS_SUCCESS);
        TEST_CHECK(actual == expected[element]);
    }
    return 0;
}

static int vector_accept_same_dtype(void)
{
    static const uint8_t opcodes[] = {
        NPU_VECTOR_ADD,
        NPU_VECTOR_SUB,
        NPU_VECTOR_MAX,
        NPU_VECTOR_MIN,
        NPU_VECTOR_SELECT,
        NPU_VECTOR_CLAMP,
        NPU_VECTOR_RELU
    };
    static const int32_t src0[3] = {-2, 3, 5};
    static const int32_t src1[3] = {1, -4, 2};
    static const int32_t mask[3] = {0, 1, 0};
    static const int32_t expected[][3] = {
        {-1, -1, 7},
        {-3, 7, 3},
        {1, 3, 5},
        {-2, -4, 2},
        {-2, -4, 5},
        {-1, 3, 4},
        {0, 3, 5}
    };
    npu_dtype_t dtype;
    uint32_t opcode_index;

    for (dtype = NPU_DTYPE_INT4;
         dtype <= NPU_DTYPE_INT32; dtype++) {
        for (opcode_index = 0u;
             opcode_index <
                 sizeof(opcodes) / sizeof(opcodes[0]);
             opcode_index++) {
            npu_vector_desc_t desc;
            uint64_t progress = UINT64_MAX;
            int line;

            TEST_CHECK(vector_accept_init());
            desc = vector_accept_desc(
                dtype, dtype, NPU_DTYPE_INT32, dtype, 3u);
            if (opcodes[opcode_index] == NPU_VECTOR_CLAMP ||
                opcodes[opcode_index] == NPU_VECTOR_RELU) {
                desc.src1_scale_bits = 0u;
            }
            if (opcodes[opcode_index] != NPU_VECTOR_FMA) {
                desc.src2_scale_bits = 0u;
            }
            if (opcodes[opcode_index] == NPU_VECTOR_SELECT) {
                desc.mask_enable = 1u;
            }
            line = vector_accept_write(&desc.src0, src0, 3u);
            if (line != 0) {
                return line;
            }
            if (opcodes[opcode_index] != NPU_VECTOR_CLAMP &&
                opcodes[opcode_index] != NPU_VECTOR_RELU) {
                line = vector_accept_write(
                    &desc.src1, src1, 3u);
                if (line != 0) {
                    return line;
                }
            }
            if (opcodes[opcode_index] == NPU_VECTOR_SELECT) {
                line = vector_accept_write(
                    &desc.mask, mask, 3u);
                if (line != 0) {
                    return line;
                }
            }
            TEST_CHECK_STATUS(
                npu_vector_execute(
                    &vector_accept_model,
                    opcodes[opcode_index], &desc, &progress),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(progress == 3u);
            line = vector_accept_check(
                &desc.dst, expected[opcode_index], 3u);
            if (line != 0) {
                return line;
            }
            if (dtype == NPU_DTYPE_INT4) {
                TEST_CHECK(
                    (vector_accept_l1[
                         (size_t)desc.dst.addr + 1u] &
                     0xf0u) == 0u);
            }
        }
    }
    return 0;
}

static int vector_accept_cmp_mul_fma(void)
{
    static const int32_t src0[3] = {-2, 3, 5};
    static const int32_t src1[3] = {1, -4, 2};
    static const int32_t src2[3] = {10, 20, 30};
    static const int32_t cmp_expected[3] = {0, 1, 1};
    static const int32_t mul_expected[3] = {-2, -12, 10};
    static const int32_t fma_expected[3] = {8, 8, 40};
    npu_dtype_t dtype0;
    npu_dtype_t dtype1;

    for (dtype0 = NPU_DTYPE_INT4;
         dtype0 <= NPU_DTYPE_INT32; dtype0++) {
        npu_vector_desc_t desc;
        uint64_t progress = UINT64_MAX;
        int line;

        TEST_CHECK(vector_accept_init());
        desc = vector_accept_desc(
            dtype0, dtype0, NPU_DTYPE_INT32,
            NPU_DTYPE_INT8, 3u);
        desc.src2_scale_bits = 0u;
        line = vector_accept_write(&desc.src0, src0, 3u);
        if (line != 0) {
            return line;
        }
        line = vector_accept_write(&desc.src1, src1, 3u);
        if (line != 0) {
            return line;
        }
        TEST_CHECK_STATUS(
            npu_vector_execute(
                &vector_accept_model, NPU_VECTOR_CMP,
                &desc, &progress),
            NPU_STATUS_SUCCESS);
        line = vector_accept_check(
            &desc.dst, cmp_expected, 3u);
        if (line != 0) {
            return line;
        }
    }

    for (dtype0 = NPU_DTYPE_INT4;
         dtype0 <= NPU_DTYPE_INT8; dtype0++) {
        for (dtype1 = NPU_DTYPE_INT4;
             dtype1 <= NPU_DTYPE_INT8; dtype1++) {
            npu_vector_desc_t desc;
            uint64_t progress = UINT64_MAX;
            int line;

            TEST_CHECK(vector_accept_init());
            desc = vector_accept_desc(
                dtype0, dtype1, NPU_DTYPE_INT32,
                NPU_DTYPE_INT32, 3u);
            desc.src2_scale_bits = 0u;
            line = vector_accept_write(
                &desc.src0, src0, 3u);
            if (line != 0) {
                return line;
            }
            line = vector_accept_write(
                &desc.src1, src1, 3u);
            if (line != 0) {
                return line;
            }
            TEST_CHECK_STATUS(
                npu_vector_execute(
                    &vector_accept_model, NPU_VECTOR_MUL,
                    &desc, &progress),
                NPU_STATUS_SUCCESS);
            line = vector_accept_check(
                &desc.dst, mul_expected, 3u);
            if (line != 0) {
                return line;
            }

            TEST_CHECK(vector_accept_init());
            desc = vector_accept_desc(
                dtype0, dtype1, NPU_DTYPE_INT32,
                NPU_DTYPE_INT32, 3u);
            line = vector_accept_write(
                &desc.src0, src0, 3u);
            if (line != 0) {
                return line;
            }
            line = vector_accept_write(
                &desc.src1, src1, 3u);
            if (line != 0) {
                return line;
            }
            line = vector_accept_write(
                &desc.src2, src2, 3u);
            if (line != 0) {
                return line;
            }
            TEST_CHECK_STATUS(
                npu_vector_execute(
                    &vector_accept_model, NPU_VECTOR_FMA,
                    &desc, &progress),
                NPU_STATUS_SUCCESS);
            line = vector_accept_check(
                &desc.dst, fma_expected, 3u);
            if (line != 0) {
                return line;
            }
        }
    }
    return 0;
}

static int32_t vector_accept_max(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT4) {
        return 7;
    }
    if (dtype == NPU_DTYPE_INT8) {
        return 127;
    }
    return INT32_MAX;
}

static int32_t vector_accept_wrapped(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT4) {
        return -7;
    }
    if (dtype == NPU_DTYPE_INT8) {
        return -127;
    }
    return INT32_MIN + 1;
}

static int vector_accept_overflow(void)
{
    npu_dtype_t dtype;
    npu_overflow_mode_t mode;

    for (dtype = NPU_DTYPE_INT4;
         dtype <= NPU_DTYPE_INT32; dtype++) {
        for (mode = NPU_OVERFLOW_SATURATE;
             mode <= NPU_OVERFLOW_WRAP; mode++) {
            npu_vector_desc_t desc;
            int32_t src0[1];
            int32_t src1[1] = {2};
            int32_t initial[1] = {0};
            int32_t expected[1];
            uint64_t progress = UINT64_MAX;
            npu_status_t expected_status;
            int line;

            TEST_CHECK(vector_accept_init());
            desc = vector_accept_desc(
                dtype, dtype, NPU_DTYPE_INT32, dtype, 1u);
            desc.src2_scale_bits = 0u;
            desc.overflow_mode = mode;
            src0[0] = vector_accept_max(dtype);
            line = vector_accept_write(
                &desc.src0, src0, 1u);
            if (line != 0) {
                return line;
            }
            line = vector_accept_write(
                &desc.src1, src1, 1u);
            if (line != 0) {
                return line;
            }
            line = vector_accept_write(
                &desc.dst, initial, 1u);
            if (line != 0) {
                return line;
            }

            expected_status =
                mode == NPU_OVERFLOW_ERROR
                    ? NPU_STATUS_NUMERIC_EXCEPTION
                    : NPU_STATUS_SUCCESS;
            TEST_CHECK_STATUS(
                npu_vector_execute(
                    &vector_accept_model, NPU_VECTOR_ADD,
                    &desc, &progress),
                expected_status);
            if (mode == NPU_OVERFLOW_SATURATE) {
                expected[0] = vector_accept_max(dtype);
            } else if (mode == NPU_OVERFLOW_WRAP) {
                expected[0] = vector_accept_wrapped(dtype);
            } else {
                expected[0] = 0;
                TEST_CHECK(progress == 0u);
            }
            line = vector_accept_check(
                &desc.dst, expected, 1u);
            if (line != 0) {
                return line;
            }
        }
    }
    return 0;
}

static int vector_accept_shapes(void)
{
    static const uint32_t lengths[] = {
        1u, 7u, 8u, 9u, 17u
    };
    uint32_t case_index;

    for (case_index = 0u;
         case_index < sizeof(lengths) / sizeof(lengths[0]);
         case_index++) {
        npu_vector_desc_t desc;
        uint32_t element;
        uint64_t progress = UINT64_MAX;

        TEST_CHECK(vector_accept_init());
        desc = vector_accept_desc(
            NPU_DTYPE_INT8, NPU_DTYPE_INT8,
            NPU_DTYPE_INT32, NPU_DTYPE_INT8,
            lengths[case_index]);
        desc.src1_scale_bits = 0u;
        desc.src2_scale_bits = 0u;
        for (element = 0u;
             element < lengths[case_index]; element++) {
            int32_t value =
                (int32_t)(element % 9u) - 4;

            TEST_CHECK_STATUS(
                npu_tensor_write(
                    &vector_accept_model, &desc.src0,
                    0u, 0u, element, value),
                NPU_STATUS_SUCCESS);
        }
        TEST_CHECK_STATUS(
            npu_vector_execute(
                &vector_accept_model, NPU_VECTOR_RELU,
                &desc, &progress),
            NPU_STATUS_SUCCESS);
        TEST_CHECK(progress == lengths[case_index]);
    }

    TEST_CHECK(vector_accept_init());
    {
        npu_vector_desc_t desc = vector_accept_desc(
            NPU_DTYPE_INT8, NPU_DTYPE_INT8,
            NPU_DTYPE_INT32, NPU_DTYPE_INT8, 0u);
        uint64_t progress = UINT64_MAX;

        desc.src1_scale_bits = 0u;
        desc.src2_scale_bits = 0u;
        TEST_CHECK_STATUS(
            npu_vector_execute(
                &vector_accept_model, NPU_VECTOR_RELU,
                &desc, &progress),
            NPU_STATUS_SUCCESS);
        TEST_CHECK(progress == 0u);

        desc.rows = 0u;
        desc.length = 17u;
        desc.valid_length = 0u;
        TEST_CHECK_STATUS(
            npu_vector_execute(
                &vector_accept_model, NPU_VECTOR_RELU,
                &desc, &progress),
            NPU_STATUS_SUCCESS);
        TEST_CHECK(progress == 0u);
    }
    return 0;
}

int test_vector_acceptance(void)
{
    int line;

    line = vector_accept_same_dtype();
    if (line != 0) {
        return line;
    }
    line = vector_accept_cmp_mul_fma();
    if (line != 0) {
        return line;
    }
    line = vector_accept_overflow();
    if (line != 0) {
        return line;
    }
    line = vector_accept_shapes();
    if (line != 0) {
        return line;
    }
    return 0;
}

#ifdef NPU_VECTOR_ACCEPTANCE_STANDALONE
int main(void)
{
    int line = test_vector_acceptance();

    if (line == 0) {
        (void)printf("[PASS] vector_acceptance\n");
        return 0;
    }
    (void)printf(
        "[FAIL] vector_acceptance at test line %d\n", line);
    return 1;
}
#endif
