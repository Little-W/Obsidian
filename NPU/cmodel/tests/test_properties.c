#include "npu_cmodel.h"

#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#define PROP_L1_BYTES NPU_REF_L1_BYTES
#define PROP_DDR_BYTES (1024u * 1024u)
#define PROP_MATRIX_CASES 100u
#define PROP_MAX_C_REGION 512u
#define PROP_VECTOR_ROWS 3u
#define PROP_VECTOR_LENGTH 5u
#define PROP_VECTOR_VALID_LENGTH 3u

#define PROP_CHECK(condition)       \
    do {                            \
        if (!(condition)) {         \
            return __LINE__;        \
        }                           \
    } while (0)

#define PROP_CHECK_STATUS(actual, expected) \
    PROP_CHECK((actual) == (expected))

static uint8_t prop_l1[PROP_L1_BYTES];
static uint8_t prop_ddr[PROP_DDR_BYTES];
static npu_model_t prop_model;
static uint32_t prop_lcg_state;

static void prop_fill_bytes(uint8_t *memory, size_t bytes, uint8_t value)
{
    size_t index;

    for (index = 0u; index < bytes; index++) {
        memory[index] = value;
    }
}

static int prop_bytes_are(const uint8_t *memory,
                          size_t bytes,
                          uint8_t value)
{
    size_t index;

    for (index = 0u; index < bytes; index++) {
        if (memory[index] != value) {
            return 0;
        }
    }
    return 1;
}

static int prop_init_model(void)
{
    npu_config_t config;

    npu_config_reference(&config);
    prop_fill_bytes(prop_l1, sizeof(prop_l1), 0u);
    prop_fill_bytes(prop_ddr, sizeof(prop_ddr), 0u);
    prop_lcg_state = 0x6d2b79f5u;
    return npu_model_init(&prop_model, &config,
                          prop_l1, sizeof(prop_l1),
                          prop_ddr, sizeof(prop_ddr)) ==
           NPU_STATUS_SUCCESS;
}

static uint32_t prop_lcg_next(void)
{
    prop_lcg_state =
        prop_lcg_state * UINT32_C(1664525) + UINT32_C(1013904223);
    return prop_lcg_state;
}

static int32_t prop_lcg_value(int32_t minimum, int32_t maximum)
{
    uint32_t width = (uint32_t)(maximum - minimum + 1);

    return minimum + (int32_t)(prop_lcg_next() % width);
}

static uint8_t *prop_space_memory(npu_space_t space)
{
    return space == NPU_SPACE_L1 ? prop_l1 : prop_ddr;
}

static uint32_t prop_dtype_bytes(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT32) {
        return 4u;
    }
    return 1u;
}

static uint32_t prop_row_storage_bytes(npu_dtype_t dtype,
                                       uint8_t start_nibble,
                                       uint32_t elements)
{
    if (elements == 0u) {
        return 0u;
    }
    if (dtype == NPU_DTYPE_INT4) {
        return ((uint32_t)start_nibble + elements + 1u) / 2u;
    }
    return elements * prop_dtype_bytes(dtype);
}

static npu_tensor_t prop_tensor(npu_dtype_t dtype,
                                uint64_t addr,
                                uint64_t region_bytes,
                                uint32_t row_stride,
                                uint32_t batch_stride)
{
    npu_tensor_t tensor = {0};

    tensor.space = NPU_SPACE_L1;
    tensor.dtype = dtype;
    tensor.addr = addr;
    tensor.region_bytes = region_bytes;
    tensor.row_stride_bytes = row_stride;
    tensor.batch_stride_bytes = batch_stride;
    return tensor;
}

static uint64_t prop_tensor_offset(const npu_tensor_t *tensor,
                                   uint32_t batch,
                                   uint32_t row,
                                   uint32_t element,
                                   uint8_t *high_nibble)
{
    uint64_t offset =
        (uint64_t)batch * tensor->batch_stride_bytes +
        (uint64_t)row * tensor->row_stride_bytes;

    if (tensor->dtype == NPU_DTYPE_INT4) {
        uint64_t half_index =
            (uint64_t)tensor->start_nibble + element;

        if (tensor->elem_stride_bytes != 0u) {
            offset += (uint64_t)element *
                      tensor->elem_stride_bytes;
            half_index = tensor->start_nibble;
        } else {
            offset += half_index / 2u;
        }
        *high_nibble = (uint8_t)(half_index & 1u);
    } else {
        uint32_t stride =
            tensor->elem_stride_bytes != 0u
                ? tensor->elem_stride_bytes
                : prop_dtype_bytes(tensor->dtype);

        offset += (uint64_t)element * stride;
        *high_nibble = 0u;
    }
    return offset;
}

static uint32_t prop_i32_bits(int32_t value)
{
    return (uint32_t)value;
}

static int32_t prop_i32_from_bits(uint32_t bits)
{
    if (bits <= UINT32_C(0x7fffffff)) {
        return (int32_t)bits;
    }
    return -1 - (int32_t)(UINT32_MAX - bits);
}

static void prop_tensor_store(const npu_tensor_t *tensor,
                              uint32_t batch,
                              uint32_t row,
                              uint32_t element,
                              int32_t value)
{
    uint8_t high_nibble;
    uint64_t offset =
        prop_tensor_offset(tensor, batch, row, element, &high_nibble);
    uint8_t *memory = prop_space_memory(tensor->space);
    size_t addr = (size_t)(tensor->addr + offset);

    if (tensor->dtype == NPU_DTYPE_INT4) {
        uint8_t nibble = (uint8_t)value & 0x0fu;

        if (high_nibble != 0u) {
            memory[addr] =
                (uint8_t)((memory[addr] & 0x0fu) |
                          (uint8_t)(nibble << 4));
        } else {
            memory[addr] =
                (uint8_t)((memory[addr] & 0xf0u) | nibble);
        }
    } else if (tensor->dtype == NPU_DTYPE_INT8) {
        memory[addr] = (uint8_t)value;
    } else {
        uint32_t bits = prop_i32_bits(value);

        memory[addr] = (uint8_t)(bits & 0xffu);
        memory[addr + 1u] = (uint8_t)((bits >> 8) & 0xffu);
        memory[addr + 2u] = (uint8_t)((bits >> 16) & 0xffu);
        memory[addr + 3u] = (uint8_t)((bits >> 24) & 0xffu);
    }
}

static int32_t prop_tensor_load(const npu_tensor_t *tensor,
                                uint32_t batch,
                                uint32_t row,
                                uint32_t element)
{
    uint8_t high_nibble;
    uint64_t offset =
        prop_tensor_offset(tensor, batch, row, element, &high_nibble);
    const uint8_t *memory = prop_space_memory(tensor->space);
    size_t addr = (size_t)(tensor->addr + offset);

    if (tensor->dtype == NPU_DTYPE_INT4) {
        uint8_t nibble =
            high_nibble != 0u
                ? (uint8_t)(memory[addr] >> 4)
                : (uint8_t)(memory[addr] & 0x0fu);

        if ((nibble & 0x08u) != 0u) {
            return -1 - (int32_t)(0x0fu - nibble);
        }
        return (int32_t)nibble;
    }
    if (tensor->dtype == NPU_DTYPE_INT8) {
        uint8_t bits = memory[addr];

        if ((bits & 0x80u) != 0u) {
            return -1 - (int32_t)(0xffu - bits);
        }
        return (int32_t)bits;
    }
    return prop_i32_from_bits(
        (uint32_t)memory[addr] |
        ((uint32_t)memory[addr + 1u] << 8) |
        ((uint32_t)memory[addr + 2u] << 16) |
        ((uint32_t)memory[addr + 3u] << 24));
}

static int32_t prop_saturate(int64_t value, npu_dtype_t dtype)
{
    int64_t minimum;
    int64_t maximum;

    if (dtype == NPU_DTYPE_INT4) {
        minimum = -8;
        maximum = 7;
    } else if (dtype == NPU_DTYPE_INT8) {
        minimum = -128;
        maximum = 127;
    } else {
        minimum = INT32_MIN;
        maximum = INT32_MAX;
    }
    if (value < minimum) {
        return (int32_t)minimum;
    }
    if (value > maximum) {
        return (int32_t)maximum;
    }
    return (int32_t)value;
}

static void prop_matrix_store_tiled_b(
    const npu_matrix_desc_t *desc,
    uint32_t batch,
    uint32_t k,
    uint32_t n,
    int32_t value)
{
    uint64_t n_tiles =
        ((uint64_t)desc->n + prop_model.config.nt - 1u) /
        prop_model.config.nt;
    uint64_t linear =
        (((((uint64_t)k / prop_model.config.kt) * n_tiles +
           (uint64_t)n / prop_model.config.nt) *
              prop_model.config.kt +
          (uint64_t)k % prop_model.config.kt) *
             prop_model.config.nt) +
        (uint64_t)n % prop_model.config.nt;
    uint64_t offset =
        (uint64_t)batch * desc->b.batch_stride_bytes;
    uint8_t *memory = prop_space_memory(desc->b.space);

    if (desc->b.dtype == NPU_DTYPE_INT4) {
        size_t addr =
            (size_t)(desc->b.addr + offset + linear / 2u);
        uint8_t nibble = (uint8_t)value & 0x0fu;

        if ((linear & 1u) != 0u) {
            memory[addr] =
                (uint8_t)((memory[addr] & 0x0fu) |
                          (uint8_t)(nibble << 4));
        } else {
            memory[addr] =
                (uint8_t)((memory[addr] & 0xf0u) | nibble);
        }
    } else {
        memory[(size_t)(desc->b.addr + offset + linear)] =
            (uint8_t)value;
    }
}

static int prop_test_matrix_properties(void)
{
    uint8_t seen_batch[3] = {0u, 0u, 0u};
    uint8_t seen_m[4] = {0u, 0u, 0u, 0u};
    uint8_t seen_n[4] = {0u, 0u, 0u, 0u};
    uint8_t seen_k[8] = {0u, 0u, 0u, 0u,
                         0u, 0u, 0u, 0u};
    uint8_t seen_combination[3] = {0u, 0u, 0u};
    uint8_t seen_opcode[2] = {0u, 0u};
    uint8_t seen_bias[2] = {0u, 0u};
    uint32_t case_index;

    PROP_CHECK(prop_init_model());
    for (case_index = 0u;
         case_index < PROP_MATRIX_CASES;
         case_index++) {
        npu_matrix_desc_t desc = {0};
        int32_t a_values[3][4][7] = {{{0}}};
        int32_t b_values[3][7][4] = {{{0}}};
        int32_t bias_values[4] = {0, 0, 0, 0};
        uint8_t written[PROP_MAX_C_REGION];
        uint32_t combination = case_index % 3u;
        uint32_t batch_count = 1u + case_index % 3u;
        uint32_t m = 1u + prop_lcg_next() % 4u;
        uint32_t n = 1u + prop_lcg_next() % 4u;
        uint32_t k = case_index % 8u;
        uint32_t a_row_bytes;
        uint32_t a_row_stride;
        uint32_t a_batch_stride;
        uint64_t b_tile_elements;
        uint32_t b_tile_bytes;
        uint32_t b_batch_stride;
        uint32_t c_row_stride;
        uint32_t c_batch_stride;
        uint32_t c_region;
        uint32_t batch;
        uint32_t row;
        uint32_t col;
        uint32_t inner;
        uint32_t byte;
        uint8_t opcode;
        uint64_t progress = UINT64_MAX;
        npu_status_t status;

        desc.m = m;
        desc.n = n;
        desc.k = k;
        desc.batch_count = batch_count;
        if (combination == 0u) {
            desc.a.dtype = NPU_DTYPE_INT8;
            desc.b.dtype = NPU_DTYPE_INT8;
        } else if (combination == 1u) {
            desc.a.dtype = NPU_DTYPE_INT4;
            desc.b.dtype = NPU_DTYPE_INT4;
        } else {
            desc.a.dtype = NPU_DTYPE_INT8;
            desc.b.dtype = NPU_DTYPE_INT4;
        }

        a_row_bytes =
            prop_row_storage_bytes(desc.a.dtype, 0u, k);
        a_row_stride = a_row_bytes + 4u;
        a_batch_stride = m * a_row_stride + 8u;
        desc.a = prop_tensor(desc.a.dtype, 0x1000u,
                             (uint64_t)batch_count * a_batch_stride,
                             a_row_stride, a_batch_stride);

        b_tile_elements =
            ((uint64_t)k + prop_model.config.kt - 1u) /
            prop_model.config.kt;
        b_tile_elements *=
            ((uint64_t)n + prop_model.config.nt - 1u) /
            prop_model.config.nt;
        b_tile_elements *=
            (uint64_t)prop_model.config.kt *
            prop_model.config.nt;
        b_tile_bytes =
            desc.b.dtype == NPU_DTYPE_INT4
                ? (uint32_t)((b_tile_elements + 1u) / 2u)
                : (uint32_t)b_tile_elements;
        b_batch_stride = b_tile_bytes + 16u;
        desc.b = prop_tensor(desc.b.dtype, 0x4000u,
                             (uint64_t)batch_count * b_batch_stride,
                             0u, b_batch_stride);

        c_row_stride = n * 4u + 8u;
        c_batch_stride = m * c_row_stride + 16u;
        c_region = batch_count * c_batch_stride;
        PROP_CHECK(c_region <= PROP_MAX_C_REGION);
        desc.c = prop_tensor(NPU_DTYPE_INT32, 0x8000u,
                             c_region, c_row_stride,
                             c_batch_stride);
        desc.b_tiled = 1u;
        desc.final_output = 1u;
        desc.round_mode = NPU_ROUND_NEAREST_EVEN;
        desc.overflow_mode = NPU_OVERFLOW_SATURATE;

        if (((case_index / 8u) & 1u) != 0u) {
            desc.bias_enable = 1u;
            desc.bias_addr = 0xa000u;
            desc.bias_count = n;
            desc.bias_stride_bytes = 4u;
        }

        prop_fill_bytes(prop_l1 + (size_t)desc.a.addr,
                        (size_t)desc.a.region_bytes, 0u);
        prop_fill_bytes(prop_l1 + (size_t)desc.b.addr,
                        (size_t)desc.b.region_bytes, 0u);
        prop_fill_bytes(prop_l1 + (size_t)desc.c.addr,
                        c_region, 0xa5u);
        prop_fill_bytes(written, c_region, 0u);

        for (batch = 0u; batch < batch_count; batch++) {
            for (row = 0u; row < m; row++) {
                for (inner = 0u; inner < k; inner++) {
                    int32_t value =
                        desc.a.dtype == NPU_DTYPE_INT4
                            ? prop_lcg_value(-8, 7)
                            : prop_lcg_value(-16, 15);

                    a_values[batch][row][inner] = value;
                    prop_tensor_store(&desc.a, batch, row,
                                      inner, value);
                }
            }
            for (inner = 0u; inner < k; inner++) {
                for (col = 0u; col < n; col++) {
                    int32_t value =
                        desc.b.dtype == NPU_DTYPE_INT4
                            ? prop_lcg_value(-8, 7)
                            : prop_lcg_value(-16, 15);

                    b_values[batch][inner][col] = value;
                    prop_matrix_store_tiled_b(
                        &desc, batch, inner, col, value);
                }
            }
        }
        for (col = 0u; col < n; col++) {
            bias_values[col] = prop_lcg_value(-11, 11);
            if (desc.bias_enable != 0u) {
                npu_tensor_t bias_tensor =
                    prop_tensor(NPU_DTYPE_INT32,
                                desc.bias_addr,
                                (uint64_t)n * 4u,
                                (uint32_t)n * 4u, 0u);

                prop_tensor_store(&bias_tensor, 0u, 0u,
                                  col, bias_values[col]);
            }
        }

        opcode =
            batch_count == 1u && (case_index & 3u) != 3u
                ? NPU_MATRIX_GEMM
                : NPU_MATRIX_BMM;
        seen_batch[batch_count - 1u] = 1u;
        seen_m[m - 1u] = 1u;
        seen_n[n - 1u] = 1u;
        seen_k[k] = 1u;
        seen_combination[combination] = 1u;
        seen_opcode[opcode == NPU_MATRIX_GEMM ? 0u : 1u] = 1u;
        seen_bias[desc.bias_enable != 0u ? 1u : 0u] = 1u;
        status = npu_matrix_execute(&prop_model, opcode,
                                    &desc, &progress);
        PROP_CHECK_STATUS(status, NPU_STATUS_SUCCESS);
        PROP_CHECK(progress ==
                   (uint64_t)batch_count * m * n);

        for (batch = 0u; batch < batch_count; batch++) {
            for (row = 0u; row < m; row++) {
                for (col = 0u; col < n; col++) {
                    int64_t expected =
                        desc.bias_enable != 0u
                            ? bias_values[col]
                            : 0;
                    uint64_t offset =
                        (uint64_t)batch * c_batch_stride +
                        (uint64_t)row * c_row_stride +
                        (uint64_t)col * 4u;

                    for (inner = 0u; inner < k; inner++) {
                        expected +=
                            (int64_t)a_values[batch][row][inner] *
                            b_values[batch][inner][col];
                    }
                    PROP_CHECK(prop_tensor_load(
                                   &desc.c, batch, row, col) ==
                               prop_saturate(
                                   expected, NPU_DTYPE_INT32));
                    for (byte = 0u; byte < 4u; byte++) {
                        written[(size_t)offset + byte] = 1u;
                    }
                }
            }
        }
        for (byte = 0u; byte < c_region; byte++) {
            if (written[byte] == 0u) {
                PROP_CHECK(
                    prop_l1[(size_t)desc.c.addr + byte] == 0xa5u);
            }
        }
    }
    for (case_index = 0u; case_index < 3u; case_index++) {
        PROP_CHECK(seen_batch[case_index] != 0u);
        PROP_CHECK(seen_combination[case_index] != 0u);
    }
    for (case_index = 0u; case_index < 4u; case_index++) {
        PROP_CHECK(seen_m[case_index] != 0u);
        PROP_CHECK(seen_n[case_index] != 0u);
    }
    for (case_index = 0u; case_index < 8u; case_index++) {
        PROP_CHECK(seen_k[case_index] != 0u);
    }
    PROP_CHECK(seen_opcode[0] != 0u && seen_opcode[1] != 0u);
    PROP_CHECK(seen_bias[0] != 0u && seen_bias[1] != 0u);
    return 0;
}

static int prop_vector_uses_src1(uint8_t opcode)
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

static npu_tensor_t prop_vector_operand_tensor(
    npu_dtype_t dtype,
    uint64_t addr,
    npu_broadcast_t broadcast,
    uint8_t start_nibble)
{
    npu_tensor_t tensor = {0};
    uint32_t logical_length =
        broadcast == NPU_BROADCAST_SCALAR ||
        broadcast == NPU_BROADCAST_ROW
            ? 1u
            : PROP_VECTOR_LENGTH;
    uint32_t row_bytes =
        prop_row_storage_bytes(dtype, start_nibble,
                               logical_length);
    uint32_t row_stride =
        row_bytes + (dtype == NPU_DTYPE_INT32 ? 4u : 2u);

    tensor.space = NPU_SPACE_L1;
    tensor.dtype = dtype;
    tensor.addr = addr;
    tensor.start_nibble = start_nibble;
    if (broadcast == NPU_BROADCAST_NONE ||
        broadcast == NPU_BROADCAST_ROW) {
        tensor.row_stride_bytes = row_stride;
        tensor.region_bytes =
            (uint64_t)PROP_VECTOR_ROWS * row_stride;
    } else {
        tensor.row_stride_bytes = 0u;
        tensor.region_bytes = row_bytes;
    }
    return tensor;
}

static void prop_vector_source_coordinate(
    npu_broadcast_t broadcast,
    uint32_t row,
    uint32_t element,
    uint32_t *source_row,
    uint32_t *source_element)
{
    *source_row = row;
    *source_element = element;
    if (broadcast == NPU_BROADCAST_SCALAR) {
        *source_row = 0u;
        *source_element = 0u;
    } else if (broadcast == NPU_BROADCAST_ROW) {
        *source_element = 0u;
    } else if (broadcast == NPU_BROADCAST_FEATURE) {
        *source_row = 0u;
    }
}

static int32_t prop_vector_source_value(uint32_t source,
                                        uint32_t opcode_index,
                                        uint32_t variant,
                                        uint32_t row,
                                        uint32_t element)
{
    uint32_t bits =
        (source + 1u) * 17u +
        opcode_index * 11u +
        variant * 7u +
        row * 5u +
        element * 3u;

    if (source == 2u) {
        return (int32_t)(bits % 41u) - 20;
    }
    return (int32_t)(bits % 15u) - 7;
}

static int32_t prop_vector_operand_value(
    uint32_t source,
    uint32_t opcode_index,
    uint32_t variant,
    npu_broadcast_t broadcast,
    uint32_t row,
    uint32_t element)
{
    uint32_t source_row;
    uint32_t source_element;

    prop_vector_source_coordinate(
        broadcast, row, element,
        &source_row, &source_element);
    return prop_vector_source_value(
        source, opcode_index, variant,
        source_row, source_element);
}

static void prop_vector_populate_operand(
    const npu_tensor_t *tensor,
    uint32_t source,
    uint32_t opcode_index,
    uint32_t variant,
    npu_broadcast_t broadcast)
{
    uint32_t row;
    uint32_t element;

    for (row = 0u; row < PROP_VECTOR_ROWS; row++) {
        for (element = 0u;
             element < PROP_VECTOR_LENGTH;
             element++) {
            uint32_t source_row;
            uint32_t source_element;

            prop_vector_source_coordinate(
                broadcast, row, element,
                &source_row, &source_element);
            prop_tensor_store(
                tensor, 0u, source_row, source_element,
                prop_vector_source_value(
                    source, opcode_index, variant,
                    source_row, source_element));
        }
    }
}

static int prop_vector_compare(int32_t a,
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
    return a >= b;
}

static int32_t prop_vector_initial_value(uint32_t opcode_index,
                                         uint32_t variant,
                                         uint32_t row,
                                         uint32_t element,
                                         npu_dtype_t dtype)
{
    int32_t value =
        (int32_t)((opcode_index * 3u +
                   variant * 5u +
                   row * 7u +
                   element) %
                  17u) -
        8;

    return prop_saturate(value, dtype);
}

static int64_t prop_vector_alu(uint8_t opcode,
                               const npu_vector_desc_t *desc,
                               int32_t src0,
                               int32_t src1,
                               int32_t src2)
{
    if (opcode == NPU_VECTOR_ADD) {
        return (int64_t)src0 + src1;
    }
    if (opcode == NPU_VECTOR_SUB) {
        return (int64_t)src0 - src1;
    }
    if (opcode == NPU_VECTOR_MUL) {
        return (int64_t)src0 * src1;
    }
    if (opcode == NPU_VECTOR_FMA) {
        return (int64_t)src0 * src1 + src2;
    }
    if (opcode == NPU_VECTOR_MAX) {
        return src0 > src1 ? src0 : src1;
    }
    if (opcode == NPU_VECTOR_MIN) {
        return src0 < src1 ? src0 : src1;
    }
    if (opcode == NPU_VECTOR_CMP) {
        return prop_vector_compare(
                   src0, src1, desc->compare_mode)
                   ? 1
                   : 0;
    }
    if (opcode == NPU_VECTOR_CLAMP) {
        if (src0 < desc->clamp_min) {
            return desc->clamp_min;
        }
        if (src0 > desc->clamp_max) {
            return desc->clamp_max;
        }
        return src0;
    }
    if (opcode == NPU_VECTOR_RELU) {
        return src0 < 0 ? 0 : src0;
    }
    return 0;
}

static int prop_test_vector_properties(void)
{
    static const uint8_t opcodes[] = {
        NPU_VECTOR_ADD,
        NPU_VECTOR_SUB,
        NPU_VECTOR_MUL,
        NPU_VECTOR_FMA,
        NPU_VECTOR_MAX,
        NPU_VECTOR_MIN,
        NPU_VECTOR_CMP,
        NPU_VECTOR_SELECT,
        NPU_VECTOR_CLAMP,
        NPU_VECTOR_RELU
    };
    uint8_t seen_broadcast0[4] = {0u, 0u, 0u, 0u};
    uint8_t seen_broadcast1[4] = {0u, 0u, 0u, 0u};
    uint8_t seen_broadcast2[4] = {0u, 0u, 0u, 0u};
    uint8_t seen_mask[2] = {0u, 0u};
    uint8_t seen_int4_tail = 0u;
    uint32_t opcode_index;

    PROP_CHECK(prop_init_model());
    for (opcode_index = 0u;
         opcode_index <
             (uint32_t)(sizeof(opcodes) / sizeof(opcodes[0]));
         opcode_index++) {
        uint8_t opcode = opcodes[opcode_index];
        uint32_t variants =
            opcode == NPU_VECTOR_CMP ? 6u : 4u;
        uint32_t variant;

        for (variant = 0u; variant < variants; variant++) {
            npu_vector_desc_t desc = {0};
            npu_dtype_t src0_dtype = NPU_DTYPE_INT4;
            npu_dtype_t src1_dtype = NPU_DTYPE_INT4;
            npu_dtype_t dst_dtype = NPU_DTYPE_INT4;
            npu_broadcast_t broadcast0 =
                (npu_broadcast_t)(variant % 4u);
            npu_broadcast_t broadcast1 =
                (npu_broadcast_t)((variant + 1u) % 4u);
            npu_broadcast_t broadcast2 =
                (npu_broadcast_t)((variant + 2u) % 4u);
            uint8_t src0_nibble =
                (uint8_t)((variant + opcode_index) & 1u);
            uint8_t src1_nibble =
                (uint8_t)((variant + opcode_index + 1u) & 1u);
            uint32_t row;
            uint32_t element;
            uint64_t progress = UINT64_MAX;
            npu_status_t status;

            if (opcode == NPU_VECTOR_MUL) {
                src0_dtype = NPU_DTYPE_INT8;
                src1_dtype = NPU_DTYPE_INT4;
                dst_dtype = NPU_DTYPE_INT32;
                src0_nibble = 0u;
            } else if (opcode == NPU_VECTOR_FMA) {
                src0_dtype = NPU_DTYPE_INT4;
                src1_dtype = NPU_DTYPE_INT8;
                dst_dtype = NPU_DTYPE_INT32;
                src1_nibble = 0u;
            } else if (opcode == NPU_VECTOR_CMP) {
                dst_dtype = NPU_DTYPE_INT8;
            }

            desc.rows = PROP_VECTOR_ROWS;
            desc.length = PROP_VECTOR_LENGTH;
            desc.valid_length = PROP_VECTOR_VALID_LENGTH;
            desc.broadcast0 = broadcast0;
            desc.broadcast1 =
                prop_vector_uses_src1(opcode)
                    ? broadcast1
                    : NPU_BROADCAST_NONE;
            desc.broadcast2 =
                opcode == NPU_VECTOR_FMA
                    ? broadcast2
                    : NPU_BROADCAST_NONE;
            desc.src0 = prop_vector_operand_tensor(
                src0_dtype, 0x10000u,
                desc.broadcast0, src0_nibble);
            if (prop_vector_uses_src1(opcode)) {
                desc.src1 = prop_vector_operand_tensor(
                    src1_dtype, 0x11000u,
                    desc.broadcast1, src1_nibble);
            }
            if (opcode == NPU_VECTOR_FMA) {
                desc.src2 = prop_vector_operand_tensor(
                    NPU_DTYPE_INT32, 0x12000u,
                    desc.broadcast2, 0u);
            }
            desc.dst = prop_vector_operand_tensor(
                dst_dtype, 0x14000u,
                NPU_BROADCAST_NONE, 0u);
            desc.mask = prop_vector_operand_tensor(
                NPU_DTYPE_INT8, 0x15000u,
                NPU_BROADCAST_NONE, 0u);
            desc.compare_mode =
                (npu_compare_t)(variant % 6u);
            desc.overflow_mode = NPU_OVERFLOW_SATURATE;
            desc.clamp_min = -3;
            desc.clamp_max = 3;
            desc.src0_scale_bits = 0x3f800000u;
            desc.src1_scale_bits =
                prop_vector_uses_src1(opcode)
                    ? 0x3f800000u
                    : 0u;
            desc.src2_scale_bits =
                opcode == NPU_VECTOR_FMA
                    ? 0x3f800000u
                    : 0u;
            desc.dst_scale_bits = 0x3f800000u;

            if (opcode == NPU_VECTOR_SELECT) {
                desc.mask_enable = 1u;
            } else {
                desc.mask_enable =
                    (uint8_t)((variant + opcode_index) & 1u);
                desc.mask_false_keep_dst =
                    (uint8_t)(desc.mask_enable != 0u &&
                              ((variant + opcode_index) & 2u) != 0u);
            }
            seen_broadcast0[(uint32_t)desc.broadcast0] = 1u;
            if (prop_vector_uses_src1(opcode)) {
                seen_broadcast1[(uint32_t)desc.broadcast1] = 1u;
            }
            if (opcode == NPU_VECTOR_FMA) {
                seen_broadcast2[(uint32_t)desc.broadcast2] = 1u;
            }
            seen_mask[desc.mask_enable != 0u ? 1u : 0u] = 1u;
            if (dst_dtype == NPU_DTYPE_INT4) {
                seen_int4_tail = 1u;
            }

            prop_fill_bytes(
                prop_l1 + (size_t)desc.src0.addr,
                (size_t)desc.src0.region_bytes, 0u);
            if (prop_vector_uses_src1(opcode)) {
                prop_fill_bytes(
                    prop_l1 + (size_t)desc.src1.addr,
                    (size_t)desc.src1.region_bytes, 0u);
            }
            if (opcode == NPU_VECTOR_FMA) {
                prop_fill_bytes(
                    prop_l1 + (size_t)desc.src2.addr,
                    (size_t)desc.src2.region_bytes, 0u);
            }
            prop_fill_bytes(
                prop_l1 + (size_t)desc.dst.addr,
                (size_t)desc.dst.region_bytes, 0xccu);
            prop_fill_bytes(
                prop_l1 + (size_t)desc.mask.addr,
                (size_t)desc.mask.region_bytes, 0u);

            prop_vector_populate_operand(
                &desc.src0, 0u, opcode_index,
                variant, desc.broadcast0);
            if (prop_vector_uses_src1(opcode)) {
                prop_vector_populate_operand(
                    &desc.src1, 1u, opcode_index,
                    variant, desc.broadcast1);
            }
            if (opcode == NPU_VECTOR_FMA) {
                prop_vector_populate_operand(
                    &desc.src2, 2u, opcode_index,
                    variant, desc.broadcast2);
            }
            for (row = 0u; row < PROP_VECTOR_ROWS; row++) {
                for (element = 0u;
                     element < PROP_VECTOR_LENGTH;
                     element++) {
                    prop_tensor_store(
                        &desc.dst, 0u, row, element,
                        prop_vector_initial_value(
                            opcode_index, variant, row,
                            element, dst_dtype));
                    prop_tensor_store(
                        &desc.mask, 0u, row, element,
                        ((row * PROP_VECTOR_LENGTH +
                          element + variant) %
                         3u) == 0u
                            ? 0
                            : 1);
                }
            }

            status = npu_vector_execute(
                &prop_model, opcode, &desc, &progress);
            PROP_CHECK_STATUS(status, NPU_STATUS_SUCCESS);
            PROP_CHECK(
                progress ==
                (uint64_t)(PROP_VECTOR_ROWS - 1u) *
                    PROP_VECTOR_LENGTH +
                PROP_VECTOR_VALID_LENGTH);

            for (row = 0u; row < PROP_VECTOR_ROWS; row++) {
                uint32_t row_length =
                    row + 1u == PROP_VECTOR_ROWS
                        ? PROP_VECTOR_VALID_LENGTH
                        : PROP_VECTOR_LENGTH;

                for (element = 0u;
                     element < row_length;
                     element++) {
                    int32_t src0 =
                        prop_vector_operand_value(
                            0u, opcode_index, variant,
                            desc.broadcast0, row, element);
                    int32_t src1 =
                        prop_vector_uses_src1(opcode)
                            ? prop_vector_operand_value(
                                  1u, opcode_index, variant,
                                  desc.broadcast1, row, element)
                            : 0;
                    int32_t src2 =
                        opcode == NPU_VECTOR_FMA
                            ? prop_vector_operand_value(
                                  2u, opcode_index, variant,
                                  desc.broadcast2, row, element)
                            : 0;
                    int32_t mask =
                        ((row * PROP_VECTOR_LENGTH +
                          element + variant) %
                         3u) == 0u
                            ? 0
                            : 1;
                    int64_t expected;

                    if (opcode == NPU_VECTOR_SELECT) {
                        expected =
                            mask == 0 ? src0 : src1;
                    } else if (desc.mask_enable != 0u &&
                               mask == 0) {
                        expected =
                            desc.mask_false_keep_dst != 0u
                                ? prop_vector_initial_value(
                                      opcode_index, variant,
                                      row, element, dst_dtype)
                                : 0;
                    } else {
                        expected = prop_vector_alu(
                            opcode, &desc, src0, src1, src2);
                    }
                    PROP_CHECK(
                        prop_tensor_load(
                            &desc.dst, 0u, row, element) ==
                        prop_saturate(expected, dst_dtype));
                }

                if (dst_dtype == NPU_DTYPE_INT4) {
                    uint8_t high;
                    uint64_t offset =
                        prop_tensor_offset(
                            &desc.dst, 0u, row,
                            row_length - 1u, &high);

                    PROP_CHECK(high == 0u);
                    PROP_CHECK(
                        (prop_l1[(size_t)desc.dst.addr +
                                 (size_t)offset] &
                         0xf0u) == 0u);
                }
            }

            for (element = PROP_VECTOR_VALID_LENGTH;
                 element < PROP_VECTOR_LENGTH;
                 element++) {
                int32_t expected =
                    prop_vector_initial_value(
                        opcode_index, variant,
                        PROP_VECTOR_ROWS - 1u,
                        element, dst_dtype);

                if (dst_dtype == NPU_DTYPE_INT4 &&
                    element == PROP_VECTOR_VALID_LENGTH) {
                    expected = 0;
                }
                PROP_CHECK(
                    prop_tensor_load(
                        &desc.dst, 0u,
                        PROP_VECTOR_ROWS - 1u,
                        element) == expected);
            }

            if (dst_dtype == NPU_DTYPE_INT4) {
                uint32_t row_bytes =
                    prop_row_storage_bytes(
                        dst_dtype, 0u,
                        PROP_VECTOR_LENGTH);

                for (row = 0u;
                     row < PROP_VECTOR_ROWS;
                     row++) {
                    uint64_t padding =
                        desc.dst.addr +
                        (uint64_t)row *
                            desc.dst.row_stride_bytes +
                        row_bytes;
                    uint32_t pad;

                    for (pad = row_bytes;
                         pad < desc.dst.row_stride_bytes;
                         pad++) {
                        PROP_CHECK(
                            prop_l1[(size_t)padding +
                                    (pad - row_bytes)] ==
                            0xccu);
                    }
                }
            }
        }
    }
    for (opcode_index = 0u; opcode_index < 4u; opcode_index++) {
        PROP_CHECK(seen_broadcast0[opcode_index] != 0u);
        PROP_CHECK(seen_broadcast1[opcode_index] != 0u);
        PROP_CHECK(seen_broadcast2[opcode_index] != 0u);
    }
    PROP_CHECK(seen_mask[0] != 0u && seen_mask[1] != 0u);
    PROP_CHECK(seen_int4_tail != 0u);
    return 0;
}

static npu_dma_desc_t prop_dma_base(void)
{
    npu_dma_desc_t desc = {0};

    desc.rank = 1u;
    desc.src_space = NPU_SPACE_DDR;
    desc.dst_space = NPU_SPACE_L1;
    desc.src_dtype = NPU_DTYPE_INT8;
    desc.dst_dtype = NPU_DTYPE_INT8;
    desc.convert_mode = NPU_DMA_CONVERT_NONE;
    desc.burst_beats = NPU_REF_DMA_MAX_BURST_BEATS;
    desc.max_outstanding = NPU_REF_DMA_OUTSTANDING;
    return desc;
}

static uint64_t prop_dma_element_offset(
    const npu_dma_desc_t *desc,
    int source,
    const uint32_t index[NPU_MAX_DMA_RANK],
    uint8_t *high_nibble)
{
    const uint32_t *stride =
        source != 0
            ? desc->src_stride_bytes
            : desc->dst_stride_bytes;
    npu_dtype_t dtype =
        source != 0 ? desc->src_dtype : desc->dst_dtype;
    uint8_t start =
        source != 0 ? desc->src_nibble : desc->dst_nibble;
    uint64_t offset = 0u;
    uint32_t dimension;

    for (dimension = 0u;
         dimension + 1u < desc->rank;
         dimension++) {
        offset +=
            (uint64_t)index[dimension] * stride[dimension];
    }
    if (dtype == NPU_DTYPE_INT4) {
        uint64_t half =
            (uint64_t)start + index[desc->rank - 1u];

        offset += half / 2u;
        *high_nibble = (uint8_t)(half & 1u);
    } else {
        offset +=
            (uint64_t)index[desc->rank - 1u] *
            prop_dtype_bytes(dtype);
        *high_nibble = 0u;
    }
    return offset;
}

static void prop_dma_store_element(
    const npu_dma_desc_t *desc,
    int source,
    const uint32_t index[NPU_MAX_DMA_RANK],
    int32_t value)
{
    npu_space_t space =
        source != 0 ? desc->src_space : desc->dst_space;
    npu_dtype_t dtype =
        source != 0 ? desc->src_dtype : desc->dst_dtype;
    uint64_t base =
        source != 0 ? desc->src_addr : desc->dst_addr;
    uint8_t high;
    uint64_t offset =
        prop_dma_element_offset(desc, source, index, &high);
    npu_tensor_t scalar =
        prop_tensor(dtype, base + offset,
                    prop_dtype_bytes(dtype), 0u, 0u);

    scalar.space = space;
    scalar.start_nibble = high;
    prop_tensor_store(&scalar, 0u, 0u, 0u, value);
}

static int32_t prop_dma_load_element(
    const npu_dma_desc_t *desc,
    int source,
    const uint32_t index[NPU_MAX_DMA_RANK])
{
    npu_space_t space =
        source != 0 ? desc->src_space : desc->dst_space;
    npu_dtype_t dtype =
        source != 0 ? desc->src_dtype : desc->dst_dtype;
    uint64_t base =
        source != 0 ? desc->src_addr : desc->dst_addr;
    uint8_t high;
    uint64_t offset =
        prop_dma_element_offset(desc, source, index, &high);
    npu_tensor_t scalar =
        prop_tensor(dtype, base + offset,
                    prop_dtype_bytes(dtype), 0u, 0u);

    scalar.space = space;
    scalar.start_nibble = high;
    return prop_tensor_load(&scalar, 0u, 0u, 0u);
}

static int prop_test_dma_copy_1d(void)
{
    uint32_t combination;

    for (combination = 0u; combination < 4u; combination++) {
        npu_dma_desc_t desc = prop_dma_base();
        uint32_t length = 3u + combination;
        uint32_t index;
        uint64_t progress = UINT64_MAX;
        uint8_t *source;
        uint8_t *destination;

        desc.src_space =
            (combination & 1u) != 0u
                ? NPU_SPACE_L1
                : NPU_SPACE_DDR;
        desc.dst_space =
            (combination & 2u) != 0u
                ? NPU_SPACE_L1
                : NPU_SPACE_DDR;
        desc.src_addr =
            desc.src_space == NPU_SPACE_L1
                ? 0x20000u
                : 0x2000u;
        desc.dst_addr =
            desc.dst_space == NPU_SPACE_L1
                ? 0x20200u
                : 0x2200u;
        desc.src_region_bytes = length;
        desc.dst_region_bytes = length;
        desc.shape[0] = length;
        source =
            prop_space_memory(desc.src_space) +
            (size_t)desc.src_addr;
        destination =
            prop_space_memory(desc.dst_space) +
            (size_t)desc.dst_addr;
        prop_fill_bytes(destination, length + 3u, 0xd7u);
        for (index = 0u; index < length; index++) {
            source[index] =
                (uint8_t)prop_lcg_value(-128, 127);
        }

        PROP_CHECK_STATUS(
            npu_dma_execute(&prop_model,
                            NPU_DMA_COPY_1D,
                            &desc, &progress),
            NPU_STATUS_SUCCESS);
        PROP_CHECK(progress == length);
        for (index = 0u; index < length; index++) {
            PROP_CHECK(destination[index] == source[index]);
        }
        for (index = length; index < length + 3u; index++) {
            PROP_CHECK(destination[index] == 0xd7u);
        }
    }

    {
        npu_dma_desc_t desc = prop_dma_base();
        uint32_t index;
        uint64_t progress = UINT64_MAX;
        static const int32_t values[5] = {-8, 7, -3, 2, 6};

        desc.src_space = NPU_SPACE_L1;
        desc.dst_space = NPU_SPACE_DDR;
        desc.src_addr = 0x21000u;
        desc.dst_addr = 0x3000u;
        desc.src_region_bytes = 5u;
        desc.dst_region_bytes = 3u;
        desc.shape[0] = 5u;
        desc.src_dtype = NPU_DTYPE_INT8;
        desc.dst_dtype = NPU_DTYPE_INT4;
        desc.convert_mode = NPU_DMA_PACK_INT4;
        prop_fill_bytes(prop_ddr + (size_t)desc.dst_addr,
                        5u, 0xeeu);
        for (index = 0u; index < 5u; index++) {
            prop_l1[(size_t)desc.src_addr + index] =
                (uint8_t)values[index];
        }
        PROP_CHECK_STATUS(
            npu_dma_execute(&prop_model,
                            NPU_DMA_COPY_1D,
                            &desc, &progress),
            NPU_STATUS_SUCCESS);
        PROP_CHECK(progress == 3u);
        for (index = 0u; index < 5u; index++) {
            uint32_t logical[NPU_MAX_DMA_RANK] =
                {index, 0u, 0u, 0u, 0u};

            PROP_CHECK(
                prop_dma_load_element(
                    &desc, 0, logical) == values[index]);
        }
        PROP_CHECK(
            (prop_ddr[(size_t)desc.dst_addr + 2u] &
             0xf0u) == 0u);
        PROP_CHECK(
            prop_ddr[(size_t)desc.dst_addr + 3u] == 0xeeu);
    }

    {
        npu_dma_desc_t desc = prop_dma_base();
        uint32_t index;
        uint64_t progress = UINT64_MAX;
        static const int32_t values[5] = {7, -8, 1, -2, 5};

        desc.src_space = NPU_SPACE_DDR;
        desc.dst_space = NPU_SPACE_L1;
        desc.src_addr = 0x3100u;
        desc.dst_addr = 0x22000u;
        desc.src_region_bytes = 3u;
        desc.dst_region_bytes = 5u;
        desc.shape[0] = 5u;
        desc.src_dtype = NPU_DTYPE_INT4;
        desc.dst_dtype = NPU_DTYPE_INT8;
        desc.src_nibble = 1u;
        desc.convert_mode = NPU_DMA_SIGN_EXTEND;
        prop_fill_bytes(prop_ddr + (size_t)desc.src_addr, 3u, 0u);
        prop_fill_bytes(prop_l1 + (size_t)desc.dst_addr, 7u, 0xacu);
        for (index = 0u; index < 5u; index++) {
            uint32_t logical[NPU_MAX_DMA_RANK] =
                {index, 0u, 0u, 0u, 0u};

            prop_dma_store_element(
                &desc, 1, logical, values[index]);
        }
        PROP_CHECK_STATUS(
            npu_dma_execute(&prop_model,
                            NPU_DMA_COPY_1D,
                            &desc, &progress),
            NPU_STATUS_SUCCESS);
        PROP_CHECK(progress == 5u);
        for (index = 0u; index < 5u; index++) {
            uint32_t logical[NPU_MAX_DMA_RANK] =
                {index, 0u, 0u, 0u, 0u};

            PROP_CHECK(
                prop_dma_load_element(
                    &desc, 0, logical) == values[index]);
        }
        PROP_CHECK(
            prop_l1[(size_t)desc.dst_addr + 5u] == 0xacu);
    }
    return 0;
}

static int prop_test_dma_copy_nd(void)
{
    npu_dma_desc_t desc = prop_dma_base();
    uint8_t written[32];
    uint32_t index[NPU_MAX_DMA_RANK] =
        {0u, 0u, 0u, 0u, 0u};
    uint32_t outer0;
    uint32_t outer1;
    uint32_t element;
    uint32_t byte;
    uint64_t progress = UINT64_MAX;
    uint64_t dst_span;

    desc.rank = 3u;
    desc.src_space = NPU_SPACE_L1;
    desc.dst_space = NPU_SPACE_DDR;
    desc.src_dtype = NPU_DTYPE_INT4;
    desc.dst_dtype = NPU_DTYPE_INT4;
    desc.src_addr = 0x23000u;
    desc.dst_addr = 0x4000u;
    desc.shape[0] = 2u;
    desc.shape[1] = 2u;
    desc.shape[2] = 5u;
    desc.src_stride_bytes[0] = 13u;
    desc.src_stride_bytes[1] = 5u;
    desc.dst_stride_bytes[0] = 11u;
    desc.dst_stride_bytes[1] = 4u;
    desc.src_nibble = 1u;
    desc.src_region_bytes = 21u;
    desc.dst_region_bytes = 18u;
    dst_span = desc.dst_region_bytes;
    prop_fill_bytes(prop_l1 + (size_t)desc.src_addr,
                    (size_t)desc.src_region_bytes, 0u);
    prop_fill_bytes(prop_ddr + (size_t)desc.dst_addr,
                    (size_t)dst_span, 0xbbu);
    prop_fill_bytes(written, sizeof(written), 0u);

    for (outer0 = 0u; outer0 < 2u; outer0++) {
        for (outer1 = 0u; outer1 < 2u; outer1++) {
            for (element = 0u; element < 5u; element++) {
                int32_t value =
                    (int32_t)((outer0 * 11u +
                               outer1 * 5u +
                               element * 3u) %
                              16u) -
                    8;
                uint8_t high;
                uint64_t offset;

                index[0] = outer0;
                index[1] = outer1;
                index[2] = element;
                prop_dma_store_element(
                    &desc, 1, index, value);
                offset = prop_dma_element_offset(
                    &desc, 0, index, &high);
                written[(size_t)offset] = 1u;
            }
        }
    }

    PROP_CHECK_STATUS(
        npu_dma_execute(&prop_model,
                        NPU_DMA_COPY_ND,
                        &desc, &progress),
        NPU_STATUS_SUCCESS);
    PROP_CHECK(progress == 12u);
    for (outer0 = 0u; outer0 < 2u; outer0++) {
        for (outer1 = 0u; outer1 < 2u; outer1++) {
            for (element = 0u; element < 5u; element++) {
                int32_t expected =
                    (int32_t)((outer0 * 11u +
                               outer1 * 5u +
                               element * 3u) %
                              16u) -
                    8;

                index[0] = outer0;
                index[1] = outer1;
                index[2] = element;
                PROP_CHECK(
                    prop_dma_load_element(
                        &desc, 0, index) == expected);
            }
        }
    }
    for (byte = 0u; byte < dst_span; byte++) {
        if (written[byte] == 0u) {
            PROP_CHECK(
                prop_ddr[(size_t)desc.dst_addr + byte] == 0xbbu);
        }
    }
    return 0;
}

static int prop_test_dma_fill(void)
{
    npu_dma_desc_t desc = prop_dma_base();
    uint32_t index[NPU_MAX_DMA_RANK] =
        {0u, 0u, 0u, 0u, 0u};
    uint32_t row;
    uint32_t element;
    uint64_t progress = UINT64_MAX;

    desc.rank = 2u;
    desc.src_space = NPU_SPACE_L1;
    desc.dst_space = NPU_SPACE_DDR;
    desc.src_dtype = NPU_DTYPE_INT4;
    desc.dst_dtype = NPU_DTYPE_INT4;
    desc.src_addr = 0u;
    desc.dst_addr = 0x5000u;
    desc.src_region_bytes = 0u;
    desc.dst_region_bytes = 11u;
    desc.shape[0] = 3u;
    desc.shape[1] = 5u;
    desc.dst_stride_bytes[0] = 4u;
    desc.fill_value = 0x0du;
    prop_fill_bytes(prop_ddr + (size_t)desc.dst_addr,
                    12u, 0x9eu);

    PROP_CHECK_STATUS(
        npu_dma_execute(&prop_model,
                        NPU_DMA_FILL,
                        &desc, &progress),
        NPU_STATUS_SUCCESS);
    PROP_CHECK(progress == 9u);
    for (row = 0u; row < 3u; row++) {
        for (element = 0u; element < 5u; element++) {
            index[0] = row;
            index[1] = element;
            PROP_CHECK(
                prop_dma_load_element(
                    &desc, 0, index) == -3);
        }
        PROP_CHECK(
            (prop_ddr[(size_t)desc.dst_addr +
                      (size_t)row * 4u + 2u] &
             0xf0u) == 0u);
        if (row != 2u) {
            PROP_CHECK(
                prop_ddr[(size_t)desc.dst_addr +
                         (size_t)row * 4u + 3u] ==
                0x9eu);
        }
    }
    PROP_CHECK(
        prop_ddr[(size_t)desc.dst_addr + 11u] == 0x9eu);
    return 0;
}

static int prop_test_dma_transpose_int4(void)
{
    npu_dma_desc_t desc = prop_dma_base();
    uint8_t written[16];
    uint32_t index[NPU_MAX_DMA_RANK] =
        {0u, 0u, 0u, 0u, 0u};
    uint32_t row;
    uint32_t col;
    uint32_t byte;
    uint64_t progress = UINT64_MAX;
    npu_tensor_t destination;

    desc.rank = 2u;
    desc.src_space = NPU_SPACE_DDR;
    desc.dst_space = NPU_SPACE_L1;
    desc.src_dtype = NPU_DTYPE_INT4;
    desc.dst_dtype = NPU_DTYPE_INT4;
    desc.src_addr = 0x6000u;
    desc.dst_addr = 0x24000u;
    desc.src_region_bytes = 11u;
    desc.dst_region_bytes = 14u;
    desc.shape[0] = 3u;
    desc.shape[1] = 5u;
    desc.src_stride_bytes[0] = 4u;
    desc.dst_stride_bytes[0] = 3u;
    desc.src_nibble = 1u;
    prop_fill_bytes(prop_ddr + (size_t)desc.src_addr,
                    11u, 0u);
    prop_fill_bytes(prop_l1 + (size_t)desc.dst_addr,
                    14u, 0xadu);
    prop_fill_bytes(written, sizeof(written), 0u);

    for (row = 0u; row < 3u; row++) {
        for (col = 0u; col < 5u; col++) {
            int32_t value =
                (int32_t)((row * 5u + col * 3u) % 16u) -
                8;

            index[0] = row;
            index[1] = col;
            prop_dma_store_element(
                &desc, 1, index, value);
            written[col * 3u + row / 2u] = 1u;
        }
    }

    PROP_CHECK_STATUS(
        npu_dma_execute(&prop_model,
                        NPU_DMA_TRANSPOSE_2D,
                        &desc, &progress),
        NPU_STATUS_SUCCESS);
    PROP_CHECK(progress == 10u);
    destination =
        prop_tensor(NPU_DTYPE_INT4, desc.dst_addr,
                    desc.dst_region_bytes,
                    desc.dst_stride_bytes[0], 0u);
    for (col = 0u; col < 5u; col++) {
        for (row = 0u; row < 3u; row++) {
            int32_t expected =
                (int32_t)((row * 5u + col * 3u) % 16u) -
                8;

            PROP_CHECK(
                prop_tensor_load(
                    &destination, 0u,
                    col, row) == expected);
        }
        PROP_CHECK(
            (prop_l1[(size_t)desc.dst_addr +
                     (size_t)col * 3u + 1u] &
             0xf0u) == 0u);
    }
    for (byte = 0u; byte < 14u; byte++) {
        if (written[byte] == 0u) {
            PROP_CHECK(
                prop_l1[(size_t)desc.dst_addr + byte] == 0xadu);
        }
    }
    return 0;
}

static int prop_test_dma_transpose_int8(void)
{
    npu_dma_desc_t desc = prop_dma_base();
    uint32_t index[NPU_MAX_DMA_RANK] =
        {0u, 0u, 0u, 0u, 0u};
    uint32_t row;
    uint32_t col;
    uint32_t byte;
    uint64_t progress = UINT64_MAX;

    desc.rank = 2u;
    desc.src_space = NPU_SPACE_L1;
    desc.dst_space = NPU_SPACE_DDR;
    desc.src_addr = 0x25000u;
    desc.dst_addr = 0x7000u;
    desc.src_region_bytes = 10u;
    desc.dst_region_bytes = 14u;
    desc.shape[0] = 2u;
    desc.shape[1] = 4u;
    desc.src_stride_bytes[0] = 6u;
    desc.dst_stride_bytes[0] = 4u;
    prop_fill_bytes(prop_l1 + (size_t)desc.src_addr,
                    10u, 0u);
    prop_fill_bytes(prop_ddr + (size_t)desc.dst_addr,
                    16u, 0xc7u);
    for (row = 0u; row < 2u; row++) {
        for (col = 0u; col < 4u; col++) {
            index[0] = row;
            index[1] = col;
            prop_dma_store_element(
                &desc, 1, index,
                (int32_t)(row * 20u + col + 1u));
        }
    }

    PROP_CHECK_STATUS(
        npu_dma_execute(&prop_model,
                        NPU_DMA_TRANSPOSE_2D,
                        &desc, &progress),
        NPU_STATUS_SUCCESS);
    PROP_CHECK(progress == 8u);
    for (col = 0u; col < 4u; col++) {
        for (row = 0u; row < 2u; row++) {
            PROP_CHECK(
                prop_ddr[(size_t)desc.dst_addr +
                         (size_t)col * 4u + row] ==
                (uint8_t)(row * 20u + col + 1u));
        }
        for (byte = 2u; byte < 4u; byte++) {
            PROP_CHECK(
                prop_ddr[(size_t)desc.dst_addr +
                         (size_t)col * 4u + byte] ==
                0xc7u);
        }
    }
    return 0;
}

static int prop_test_dma_pack_split(void)
{
    npu_dma_desc_t desc = prop_dma_base();
    uint32_t segment;
    uint32_t byte;
    uint64_t progress = UINT64_MAX;

    desc.src_space = NPU_SPACE_L1;
    desc.dst_space = NPU_SPACE_DDR;
    desc.src_addr = 0x26000u;
    desc.dst_addr = 0x8000u;
    desc.src_region_bytes = 13u;
    desc.dst_region_bytes = 9u;
    desc.segment_count = 3u;
    desc.segment_bytes = 3u;
    desc.segment_stride = 5u;
    desc.shape[0] = desc.segment_count;
    prop_fill_bytes(prop_l1 + (size_t)desc.src_addr,
                    13u, 0x52u);
    prop_fill_bytes(prop_ddr + (size_t)desc.dst_addr,
                    11u, 0xceu);
    for (segment = 0u; segment < 3u; segment++) {
        for (byte = 0u; byte < 3u; byte++) {
            prop_l1[(size_t)desc.src_addr +
                    (size_t)segment * 5u + byte] =
                (uint8_t)(0x20u + segment * 8u + byte);
        }
    }

    PROP_CHECK_STATUS(
        npu_dma_execute(&prop_model,
                        NPU_DMA_PACK,
                        &desc, &progress),
        NPU_STATUS_SUCCESS);
    PROP_CHECK(progress == 9u);
    for (segment = 0u; segment < 3u; segment++) {
        for (byte = 0u; byte < 3u; byte++) {
            PROP_CHECK(
                prop_ddr[(size_t)desc.dst_addr +
                         (size_t)segment * 3u + byte] ==
                (uint8_t)(0x20u + segment * 8u + byte));
        }
    }
    PROP_CHECK(
        prop_ddr[(size_t)desc.dst_addr + 9u] == 0xceu);

    desc.src_space = NPU_SPACE_DDR;
    desc.dst_space = NPU_SPACE_L1;
    desc.src_addr = 0x8000u;
    desc.dst_addr = 0x27000u;
    desc.src_region_bytes = 9u;
    desc.dst_region_bytes = 13u;
    prop_fill_bytes(prop_l1 + (size_t)desc.dst_addr,
                    14u, 0xe3u);
    progress = UINT64_MAX;
    PROP_CHECK_STATUS(
        npu_dma_execute(&prop_model,
                        NPU_DMA_SPLIT,
                        &desc, &progress),
        NPU_STATUS_SUCCESS);
    PROP_CHECK(progress == 9u);
    for (segment = 0u; segment < 3u; segment++) {
        for (byte = 0u; byte < 3u; byte++) {
            PROP_CHECK(
                prop_l1[(size_t)desc.dst_addr +
                        (size_t)segment * 5u + byte] ==
                (uint8_t)(0x20u + segment * 8u + byte));
        }
        if (segment != 2u) {
            PROP_CHECK(
                prop_l1[(size_t)desc.dst_addr +
                        (size_t)segment * 5u + 3u] ==
                0xe3u);
            PROP_CHECK(
                prop_l1[(size_t)desc.dst_addr +
                        (size_t)segment * 5u + 4u] ==
                0xe3u);
        }
    }
    PROP_CHECK(
        prop_l1[(size_t)desc.dst_addr + 13u] == 0xe3u);
    return 0;
}

static int prop_test_dma_properties(void)
{
    int line;

    PROP_CHECK(prop_init_model());
    line = prop_test_dma_copy_1d();
    if (line != 0) {
        return line;
    }
    line = prop_test_dma_copy_nd();
    if (line != 0) {
        return line;
    }
    line = prop_test_dma_fill();
    if (line != 0) {
        return line;
    }
    line = prop_test_dma_transpose_int4();
    if (line != 0) {
        return line;
    }
    line = prop_test_dma_transpose_int8();
    if (line != 0) {
        return line;
    }
    return prop_test_dma_pack_split();
}

static npu_matrix_desc_t prop_negative_matrix_desc(void)
{
    npu_matrix_desc_t desc = {0};

    desc.m = 1u;
    desc.n = 2u;
    desc.k = 2u;
    desc.batch_count = 1u;
    desc.a = prop_tensor(
        NPU_DTYPE_INT8, 0x30000u, 2u, 2u, 2u);
    desc.b = prop_tensor(
        NPU_DTYPE_INT8, 0x30100u, 128u, 0u, 128u);
    desc.c = prop_tensor(
        NPU_DTYPE_INT32, 0x30300u, 8u, 8u, 8u);
    desc.b_tiled = 1u;
    desc.final_output = 1u;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    return desc;
}

static npu_vector_desc_t prop_negative_vector_desc(void)
{
    npu_vector_desc_t desc = {0};

    desc.rows = 2u;
    desc.length = 3u;
    desc.valid_length = 3u;
    desc.src0 = prop_tensor(
        NPU_DTYPE_INT8, 0x31000u, 6u, 3u, 0u);
    desc.src1 = prop_tensor(
        NPU_DTYPE_INT8, 0x31100u, 6u, 3u, 0u);
    desc.dst = prop_tensor(
        NPU_DTYPE_INT8, 0x31200u, 6u, 3u, 0u);
    desc.broadcast0 = NPU_BROADCAST_NONE;
    desc.broadcast1 = NPU_BROADCAST_NONE;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.src0_scale_bits = 0x3f800000u;
    desc.src1_scale_bits = 0x3f800000u;
    desc.dst_scale_bits = 0x3f800000u;
    return desc;
}

static int prop_test_zero_size(void)
{
    uint64_t progress = UINT64_MAX;

    {
        npu_dma_desc_t desc = prop_dma_base();

        desc.src_addr = 0x9000u;
        desc.dst_addr = 0x32000u;
        desc.shape[0] = 0u;
        desc.src_region_bytes = 0u;
        desc.dst_region_bytes = 0u;
        prop_fill_bytes(prop_l1 + (size_t)desc.dst_addr,
                        8u, 0x41u);
        PROP_CHECK_STATUS(
            npu_dma_execute(&prop_model,
                            NPU_DMA_COPY_1D,
                            &desc, &progress),
            NPU_STATUS_SUCCESS);
        PROP_CHECK(progress == 0u);
        PROP_CHECK(prop_bytes_are(
            prop_l1 + (size_t)desc.dst_addr, 8u, 0x41u));
    }

    {
        npu_matrix_desc_t desc =
            prop_negative_matrix_desc();

        desc.m = 0u;
        prop_fill_bytes(prop_l1 + (size_t)desc.c.addr,
                        8u, 0x42u);
        progress = UINT64_MAX;
        PROP_CHECK_STATUS(
            npu_matrix_execute(&prop_model,
                               NPU_MATRIX_GEMM,
                               &desc, &progress),
            NPU_STATUS_SUCCESS);
        PROP_CHECK(progress == 0u);
        PROP_CHECK(prop_bytes_are(
            prop_l1 + (size_t)desc.c.addr, 8u, 0x42u));
    }

    {
        npu_vector_desc_t desc =
            prop_negative_vector_desc();

        desc.rows = 0u;
        desc.valid_length = 0u;
        prop_fill_bytes(prop_l1 + (size_t)desc.dst.addr,
                        6u, 0x43u);
        progress = UINT64_MAX;
        PROP_CHECK_STATUS(
            npu_vector_execute(&prop_model,
                               NPU_VECTOR_ADD,
                               &desc, &progress),
            NPU_STATUS_SUCCESS);
        PROP_CHECK(progress == 0u);
        PROP_CHECK(prop_bytes_are(
            prop_l1 + (size_t)desc.dst.addr, 6u, 0x43u));

        desc.rows = 2u;
        desc.length = 0u;
        desc.valid_length = 0u;
        progress = UINT64_MAX;
        PROP_CHECK_STATUS(
            npu_vector_execute(&prop_model,
                               NPU_VECTOR_ADD,
                               &desc, &progress),
            NPU_STATUS_SUCCESS);
        PROP_CHECK(progress == 0u);
        PROP_CHECK(prop_bytes_are(
            prop_l1 + (size_t)desc.dst.addr, 6u, 0x43u));
    }
    return 0;
}

static int prop_test_dma_no_write_errors(void)
{
    uint64_t progress = UINT64_MAX;

    {
        npu_dma_desc_t desc = prop_dma_base();

        desc.rank = 2u;
        desc.src_addr = 0xa000u;
        desc.dst_addr = 0x33000u;
        desc.shape[0] = 2u;
        desc.shape[1] = 4u;
        desc.src_stride_bytes[0] = 6u;
        desc.dst_stride_bytes[0] = 6u;
        desc.src_region_bytes = 10u;
        desc.dst_region_bytes = 9u;
        prop_fill_bytes(prop_l1 + (size_t)desc.dst_addr,
                        12u, 0x61u);
        PROP_CHECK_STATUS(
            npu_dma_execute(&prop_model,
                            NPU_DMA_COPY_ND,
                            &desc, &progress),
            NPU_STATUS_ADDR_FAULT);
        PROP_CHECK(progress == 0u);
        PROP_CHECK(prop_bytes_are(
            prop_l1 + (size_t)desc.dst_addr, 12u, 0x61u));
    }

    {
        npu_dma_desc_t desc = prop_dma_base();

        desc.src_addr = UINT64_MAX - 1u;
        desc.dst_addr = 0x33100u;
        desc.shape[0] = 4u;
        desc.src_region_bytes = 4u;
        desc.dst_region_bytes = 4u;
        prop_fill_bytes(prop_l1 + (size_t)desc.dst_addr,
                        8u, 0x62u);
        progress = UINT64_MAX;
        PROP_CHECK_STATUS(
            npu_dma_execute(&prop_model,
                            NPU_DMA_COPY_1D,
                            &desc, &progress),
            NPU_STATUS_ADDR_FAULT);
        PROP_CHECK(progress == 0u);
        PROP_CHECK(prop_bytes_are(
            prop_l1 + (size_t)desc.dst_addr, 8u, 0x62u));
    }

    {
        npu_dma_desc_t desc = prop_dma_base();

        desc.src_space = NPU_SPACE_DDR;
        desc.dst_space = NPU_SPACE_L1;
        desc.src_addr = 0xb000u;
        desc.dst_addr = 0x33200u;
        desc.shape[0] = 3u;
        desc.src_region_bytes = 3u;
        desc.dst_region_bytes = 2u;
        desc.src_dtype = NPU_DTYPE_INT8;
        desc.dst_dtype = NPU_DTYPE_INT4;
        desc.convert_mode = NPU_DMA_PACK_INT4;
        prop_ddr[(size_t)desc.src_addr] = 1u;
        prop_ddr[(size_t)desc.src_addr + 1u] = 2u;
        prop_ddr[(size_t)desc.src_addr + 2u] = 8u;
        prop_fill_bytes(prop_l1 + (size_t)desc.dst_addr,
                        5u, 0x63u);
        progress = UINT64_MAX;
        PROP_CHECK_STATUS(
            npu_dma_execute(&prop_model,
                            NPU_DMA_COPY_1D,
                            &desc, &progress),
            NPU_STATUS_NUMERIC_EXCEPTION);
        PROP_CHECK(progress == 0u);
        PROP_CHECK(prop_bytes_are(
            prop_l1 + (size_t)desc.dst_addr, 5u, 0x63u));
    }

    {
        npu_dma_desc_t desc = prop_dma_base();

        desc.rank = 2u;
        desc.src_dtype = NPU_DTYPE_INT32;
        desc.dst_dtype = NPU_DTYPE_INT32;
        desc.src_addr = 0u;
        desc.dst_addr = 0x33300u;
        desc.shape[0] = UINT32_MAX;
        desc.shape[1] = UINT32_MAX;
        desc.src_stride_bytes[0] = UINT32_MAX;
        desc.dst_stride_bytes[0] = UINT32_MAX;
        desc.src_region_bytes = UINT64_MAX;
        desc.dst_region_bytes = UINT64_MAX;
        prop_fill_bytes(prop_l1 + (size_t)desc.dst_addr,
                        8u, 0x64u);
        progress = UINT64_MAX;
        PROP_CHECK_STATUS(
            npu_dma_execute(&prop_model,
                            NPU_DMA_COPY_ND,
                            &desc, &progress),
            NPU_STATUS_ADDR_FAULT);
        PROP_CHECK(progress == 0u);
        PROP_CHECK(prop_bytes_are(
            prop_l1 + (size_t)desc.dst_addr, 8u, 0x64u));
    }
    return 0;
}

static int prop_test_matrix_no_write_errors(void)
{
    npu_matrix_desc_t desc =
        prop_negative_matrix_desc();
    uint64_t progress = UINT64_MAX;

    prop_l1[(size_t)desc.a.addr] = 2u;
    prop_l1[(size_t)desc.a.addr + 1u] = 3u;
    prop_fill_bytes(prop_l1 + (size_t)desc.b.addr,
                    (size_t)desc.b.region_bytes, 0u);
    prop_l1[(size_t)desc.b.addr] = 4u;
    prop_l1[(size_t)desc.b.addr + 1u] = 5u;
    prop_l1[(size_t)desc.b.addr + 8u] = 6u;
    prop_l1[(size_t)desc.b.addr + 9u] = 7u;

    desc.b.region_bytes = 9u;
    prop_fill_bytes(prop_l1 + (size_t)desc.c.addr,
                    8u, 0x71u);
    PROP_CHECK_STATUS(
        npu_matrix_execute(&prop_model,
                           NPU_MATRIX_GEMM,
                           &desc, &progress),
        NPU_STATUS_ADDR_FAULT);
    PROP_CHECK(progress == 0u);
    PROP_CHECK(prop_bytes_are(
        prop_l1 + (size_t)desc.c.addr, 8u, 0x71u));

    desc = prop_negative_matrix_desc();
    desc.a.addr = UINT64_MAX;
    prop_fill_bytes(prop_l1 + (size_t)desc.c.addr,
                    8u, 0x72u);
    progress = UINT64_MAX;
    PROP_CHECK_STATUS(
        npu_matrix_execute(&prop_model,
                           NPU_MATRIX_GEMM,
                           &desc, &progress),
        NPU_STATUS_ADDR_FAULT);
    PROP_CHECK(progress == 0u);
    PROP_CHECK(prop_bytes_are(
        prop_l1 + (size_t)desc.c.addr, 8u, 0x72u));
    return 0;
}

static int prop_test_vector_no_write_errors(void)
{
    npu_vector_desc_t desc =
        prop_negative_vector_desc();
    uint64_t progress = UINT64_MAX;
    uint32_t index;

    for (index = 0u; index < 6u; index++) {
        prop_l1[(size_t)desc.src0.addr + index] =
            (uint8_t)(index + 1u);
        prop_l1[(size_t)desc.src1.addr + index] =
            (uint8_t)(10u + index);
    }
    desc.src0.region_bytes = 3u;
    prop_fill_bytes(prop_l1 + (size_t)desc.dst.addr,
                    6u, 0x81u);
    PROP_CHECK_STATUS(
        npu_vector_execute(&prop_model,
                           NPU_VECTOR_ADD,
                           &desc, &progress),
        NPU_STATUS_ADDR_FAULT);
    PROP_CHECK(progress == 0u);
    PROP_CHECK(prop_bytes_are(
        prop_l1 + (size_t)desc.dst.addr, 6u, 0x81u));

    desc = prop_negative_vector_desc();
    desc.src0.addr = UINT64_MAX;
    prop_fill_bytes(prop_l1 + (size_t)desc.dst.addr,
                    6u, 0x82u);
    progress = UINT64_MAX;
    PROP_CHECK_STATUS(
        npu_vector_execute(&prop_model,
                           NPU_VECTOR_ADD,
                           &desc, &progress),
        NPU_STATUS_ADDR_FAULT);
    PROP_CHECK(progress == 0u);
    PROP_CHECK(prop_bytes_are(
        prop_l1 + (size_t)desc.dst.addr, 6u, 0x82u));

    desc = prop_negative_vector_desc();
    desc.clamp_min = 3;
    desc.clamp_max = -3;
    prop_fill_bytes(prop_l1 + (size_t)desc.dst.addr,
                    6u, 0x83u);
    progress = UINT64_MAX;
    PROP_CHECK_STATUS(
        npu_vector_execute(&prop_model,
                           NPU_VECTOR_CLAMP,
                           &desc, &progress),
        NPU_STATUS_BAD_DESC);
    PROP_CHECK(progress == 0u);
    PROP_CHECK(prop_bytes_are(
        prop_l1 + (size_t)desc.dst.addr, 6u, 0x83u));
    return 0;
}

static int prop_test_negative_properties(void)
{
    int line;

    PROP_CHECK(prop_init_model());
    line = prop_test_zero_size();
    if (line != 0) {
        return line;
    }
    line = prop_test_dma_no_write_errors();
    if (line != 0) {
        return line;
    }
    line = prop_test_matrix_no_write_errors();
    if (line != 0) {
        return line;
    }
    return prop_test_vector_no_write_errors();
}

int test_properties(void)
{
    int line;

    line = prop_test_matrix_properties();
    if (line != 0) {
        return line;
    }
    line = prop_test_vector_properties();
    if (line != 0) {
        return line;
    }
    line = prop_test_dma_properties();
    if (line != 0) {
        return line;
    }
    return prop_test_negative_properties();
}

#ifdef NPU_PROPERTIES_STANDALONE
int main(void)
{
    return test_properties();
}
#endif
