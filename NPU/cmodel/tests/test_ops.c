#include "test_util.h"
#include "npu_wire.h"

#include <limits.h>
#include <string.h>

#define TEST_L1_BYTES NPU_REF_L1_BYTES
#define TEST_DDR_BYTES (1024u * 1024u)

static uint8_t test_l1[TEST_L1_BYTES];
static uint8_t test_ddr[TEST_DDR_BYTES];
static npu_model_t test_model;

static int test_init_model(void)
{
    npu_config_t config;
    npu_config_reference(&config);
    test_clear_bytes(test_l1, sizeof(test_l1));
    test_clear_bytes(test_ddr, sizeof(test_ddr));
    return npu_model_init(&test_model, &config,
                          test_l1, sizeof(test_l1),
                          test_ddr, sizeof(test_ddr)) ==
           NPU_STATUS_SUCCESS;
}

static int test_read_tensor(const npu_tensor_t *tensor,
                            uint32_t row,
                            uint32_t element,
                            int32_t expected)
{
    int32_t value = 0;
    if (npu_tensor_read(&test_model, tensor, 0u,
                        row, element, &value) != NPU_STATUS_SUCCESS) {
        return 0;
    }
    return value == expected;
}

static int test_write_tensor(const npu_tensor_t *tensor,
                             uint32_t row,
                             uint32_t element,
                             int32_t value)
{
    return npu_tensor_write(&test_model, tensor, 0u,
                            row, element, value) ==
           NPU_STATUS_SUCCESS;
}

int test_bits(void)
{
    uint8_t packed;
    int32_t value;
    npu_tensor_t tensor;
    npu_cmd_t command = {0};
    npu_cmd_t decoded;
    npu_task_request_t timing_request;
    uint64_t low_beat;
    uint64_t high_beat;
    uint64_t invalid_beat;
    uint32_t index;

    TEST_CHECK(test_init_model());

    packed = 0u;
    packed = npu_int4_insert(packed, 0u, -8);
    packed = npu_int4_insert(packed, 1u, 7);
    TEST_CHECK(packed == 0x78u);
    TEST_CHECK(npu_int4_unpack(packed, 0u) == -8);
    TEST_CHECK(npu_int4_unpack(packed, 1u) == 7);
    TEST_CHECK(npu_int4_unpack(0x0fu, 0u) == -1);

    TEST_CHECK(npu_round_shift(5, 1, NPU_ROUND_NEAREST_EVEN) == 2);
    TEST_CHECK(npu_round_shift(7, 1, NPU_ROUND_NEAREST_EVEN) == 4);
    TEST_CHECK(npu_round_shift(-5, 1, NPU_ROUND_NEAREST_EVEN) == -2);
    TEST_CHECK(npu_round_shift(-7, 1, NPU_ROUND_NEAREST_EVEN) == -4);
    TEST_CHECK(npu_round_shift(7, 2, NPU_ROUND_TO_ZERO) == 1);
    TEST_CHECK(npu_round_shift(-7, 2, NPU_ROUND_TO_ZERO) == -1);
    TEST_CHECK(npu_round_shift(7, 2, NPU_ROUND_TO_POS_INF) == 2);
    TEST_CHECK(npu_round_shift(-7, 2, NPU_ROUND_TO_POS_INF) == -1);
    TEST_CHECK(npu_round_shift(7, 2, NPU_ROUND_TO_NEG_INF) == 1);
    TEST_CHECK(npu_round_shift(-7, 2, NPU_ROUND_TO_NEG_INF) == -2);
    TEST_CHECK(npu_round_shift(3, -2, NPU_ROUND_NEAREST_EVEN) == 12);
    TEST_CHECK(npu_round_shift(INT64_MAX, -1,
                               NPU_ROUND_NEAREST_EVEN) == INT64_MAX);
    TEST_CHECK(npu_round_shift(INT64_MIN, 63,
                               NPU_ROUND_NEAREST_EVEN) == -1);

    TEST_CHECK_STATUS(npu_cast_integer(&test_model, 130,
                                       NPU_DTYPE_INT8,
                                       NPU_OVERFLOW_SATURATE,
                                       &value),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(value == 127);
    TEST_CHECK_STATUS(npu_cast_integer(&test_model, 130,
                                       NPU_DTYPE_INT8,
                                       NPU_OVERFLOW_WRAP,
                                       &value),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(value == -126);
    TEST_CHECK_STATUS(npu_cast_integer(&test_model, 8,
                                       NPU_DTYPE_INT4,
                                       NPU_OVERFLOW_ERROR,
                                       &value),
                      NPU_STATUS_NUMERIC_EXCEPTION);

    tensor = test_tensor(NPU_DTYPE_INT4, 0x100u, 2u, 2u);
    tensor.start_nibble = 1u;
    TEST_CHECK(test_write_tensor(&tensor, 0u, 0u, -3));
    TEST_CHECK(test_write_tensor(&tensor, 0u, 1u, 5));
    TEST_CHECK(test_read_tensor(&tensor, 0u, 0u, -3));
    TEST_CHECK(test_read_tensor(&tensor, 0u, 1u, 5));

    command.desc_addr = 0x400u;
    command.command_id = 0x345u;
    command.engine = NPU_ENGINE_MATRIX;
    command.opcode = NPU_MATRIX_GEMM;
    command.header_flags = 0x0bu;
    command.wait_event[0].id = 3u;
    command.wait_event[0].generation = 2u;
    command.wait_event[1] = npu_event_none();
    command.signal_event.id = 4u;
    command.signal_event.generation = 7u;
    command.header_version = NPU_WIRE_HEADER_VERSION;
    command.timeout_class = 5u;
    npu_cmd_encode(&command, &low_beat, &high_beat);
    TEST_CHECK((low_beat & UINT64_C(0x0000ffffffffffff)) ==
               command.desc_addr);
    TEST_CHECK(((low_beat >> 48u) & 0x0fffu) ==
               command.command_id);
    TEST_CHECK(((low_beat >> 60u) & 0x0fu) ==
               command.engine);
    TEST_CHECK((high_beat & 0xffu) == command.opcode);
    TEST_CHECK(((high_beat >> 8u) & 0x0fffu) ==
               (uint16_t)(command.header_flags |
                          ((uint16_t)command.timeout_class << 6u)));
    TEST_CHECK(((high_beat >> 20u) & 0x0fffu) == 0x0203u);
    TEST_CHECK(((high_beat >> 32u) & 0x0fffu) == 0x0fffu);
    TEST_CHECK(((high_beat >> 44u) & 0x0fffu) == 0x0704u);
    TEST_CHECK((high_beat >> 56u) == NPU_WIRE_HEADER_VERSION);
    TEST_CHECK_STATUS(npu_cmd_decode_descriptor(
                          low_beat, high_beat, &decoded),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(decoded.desc_addr == command.desc_addr);
    TEST_CHECK(decoded.command_id == command.command_id);
    TEST_CHECK(decoded.engine == command.engine);
    TEST_CHECK(decoded.opcode == command.opcode);
    TEST_CHECK(decoded.header_flags ==
               (uint16_t)(command.header_flags |
                          ((uint16_t)command.timeout_class << 6u)));
    TEST_CHECK(decoded.timeout_class == command.timeout_class);
    TEST_CHECK(decoded.header_version == NPU_WIRE_HEADER_VERSION);
    TEST_CHECK(decoded.wait_event[0].id == 3u);
    TEST_CHECK(decoded.signal_event.generation == 7u);
    TEST_CHECK_STATUS(npu_cmd_decode_descriptor(
                          low_beat,
                          (high_beat &
                           UINT64_C(0x00ffffffffffffff)),
                          &decoded),
                      NPU_STATUS_BAD_DESC);
    TEST_CHECK_STATUS(npu_cmd_decode_descriptor(
                          low_beat,
                          (high_beat &
                           ~(UINT64_C(0x0fff) << 20u)) |
                              (UINT64_C(0x00ff) << 20u),
                          &decoded),
                      NPU_STATUS_BAD_DESC);
    invalid_beat =
        (high_beat & ~UINT64_C(0xff)) | UINT64_C(0x0f);
    TEST_CHECK_STATUS(npu_cmd_decode_descriptor(
                          low_beat, invalid_beat, &decoded),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(decoded.opcode == 0x0fu);
    invalid_beat =
        (low_beat & ~(UINT64_C(0x0f) << 60u)) |
        (UINT64_C(0x07) << 60u);
    TEST_CHECK_STATUS(npu_cmd_decode_descriptor(
                          invalid_beat, high_beat, &decoded),
                      NPU_STATUS_BAD_DESC);

    command.desc_addr = 0x43fu;
    npu_cmd_encode(&command, &low_beat, &high_beat);
    TEST_CHECK_STATUS(npu_cmd_decode_descriptor(
                          low_beat, high_beat, &decoded),
                      NPU_STATUS_BAD_DESC);

    TEST_CHECK(npu_float_to_int(0.5f, NPU_ROUND_NEAREST_EVEN) == 0);
    TEST_CHECK(npu_float_to_int(1.5f, NPU_ROUND_NEAREST_EVEN) == 2);
    TEST_CHECK(npu_float_to_int(2.5f, NPU_ROUND_NEAREST_EVEN) == 2);
    TEST_CHECK(npu_float_to_int(-1.5f, NPU_ROUND_NEAREST_EVEN) == -2);
    TEST_CHECK(npu_float_to_int(1.1f, NPU_ROUND_TO_POS_INF) == 2);
    TEST_CHECK(npu_float_to_int(-1.1f, NPU_ROUND_TO_NEG_INF) == -2);

    (void)memset(&timing_request, 0, sizeof(timing_request));
    timing_request.cmd.engine = NPU_ENGINE_DMA;
    timing_request.cmd.opcode = NPU_DMA_COPY_1D;
    timing_request.desc.dma.rank = NPU_MAX_DMA_RANK;
    timing_request.desc.dma.src_dtype = NPU_DTYPE_INT32;
    timing_request.desc.dma.dst_dtype = NPU_DTYPE_INT32;
    for (index = 0u; index < NPU_MAX_DMA_RANK; index++) {
        timing_request.desc.dma.shape[index] = UINT32_MAX;
    }
    TEST_CHECK(npu_estimate_task_cycles(
                   &test_model, &timing_request) >
               UINT64_MAX / 16u);

    (void)memset(&timing_request, 0, sizeof(timing_request));
    timing_request.cmd.engine = NPU_ENGINE_MATRIX;
    timing_request.cmd.opcode = NPU_MATRIX_GEMM;
    timing_request.desc.matrix.batch_count = UINT32_MAX;
    timing_request.desc.matrix.m = UINT32_MAX;
    timing_request.desc.matrix.n = UINT32_MAX;
    timing_request.desc.matrix.k = UINT32_MAX;
    timing_request.desc.matrix.a.dtype = NPU_DTYPE_INT8;
    timing_request.desc.matrix.b.dtype = NPU_DTYPE_INT8;
    timing_request.desc.matrix.c.dtype = NPU_DTYPE_INT32;
    TEST_CHECK(npu_estimate_task_cycles(
                   &test_model, &timing_request) ==
               UINT64_MAX);
    return 0;
}

static npu_dma_desc_t test_dma_base(void)
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

int test_dma(void)
{
    npu_dma_desc_t desc;
    npu_tensor_t tensor;
    uint64_t progress;
    uint64_t read_before;
    uint32_t index;
    static const int32_t expected_i32[6] = {-3, -2, -1, 0, 1, 2};
    static const uint8_t transposed[6] = {1u, 4u, 2u, 5u, 3u, 6u};

    TEST_CHECK(test_init_model());
    for (index = 0u; index < 6u; index++) {
        test_ddr[index] = (uint8_t)expected_i32[index];
    }
    desc = test_dma_base();
    desc.rank = 2u;
    desc.src_dtype = NPU_DTYPE_INT8;
    desc.dst_dtype = NPU_DTYPE_INT32;
    desc.convert_mode = NPU_DMA_SIGN_EXTEND;
    desc.src_addr = 0u;
    desc.dst_addr = 0x100u;
    desc.src_region_bytes = 6u;
    desc.dst_region_bytes = 24u;
    desc.shape[0] = 2u;
    desc.shape[1] = 3u;
    desc.src_stride_bytes[0] = 3u;
    desc.dst_stride_bytes[0] = 12u;
    TEST_CHECK_STATUS(npu_dma_execute(&test_model, NPU_DMA_COPY_ND,
                                      &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 24u);
    tensor = test_tensor(NPU_DTYPE_INT32, 0x100u, 24u, 12u);
    for (index = 0u; index < 6u; index++) {
        TEST_CHECK(test_read_tensor(&tensor, index / 3u,
                                    index % 3u, expected_i32[index]));
    }

    desc = test_dma_base();
    desc.src_space = NPU_SPACE_L1;
    desc.dst_space = NPU_SPACE_L1;
    desc.src_dtype = NPU_DTYPE_INT4;
    desc.dst_dtype = NPU_DTYPE_INT4;
    desc.dst_addr = 0x200u;
    desc.dst_region_bytes = 3u;
    desc.shape[0] = 5u;
    desc.fill_value = 0x0du;
    TEST_CHECK_STATUS(npu_dma_execute(&test_model, NPU_DMA_FILL,
                                      &desc, &progress),
                      NPU_STATUS_SUCCESS);
    tensor = test_tensor(NPU_DTYPE_INT4, 0x200u, 3u, 3u);
    for (index = 0u; index < 5u; index++) {
        TEST_CHECK(test_read_tensor(&tensor, 0u, index, -3));
    }
    TEST_CHECK((test_l1[0x202u] & 0xf0u) == 0u);

    for (index = 0u; index < 6u; index++) {
        test_ddr[0x100u + index] = (uint8_t)(index + 1u);
    }
    desc = test_dma_base();
    desc.rank = 2u;
    desc.src_addr = 0x100u;
    desc.dst_addr = 0x300u;
    desc.src_region_bytes = 6u;
    desc.dst_region_bytes = 6u;
    desc.shape[0] = 2u;
    desc.shape[1] = 3u;
    desc.src_stride_bytes[0] = 3u;
    desc.dst_stride_bytes[0] = 2u;
    TEST_CHECK_STATUS(npu_dma_execute(&test_model,
                                      NPU_DMA_TRANSPOSE_2D,
                                      &desc, &progress),
                      NPU_STATUS_SUCCESS);
    for (index = 0u; index < 6u; index++) {
        TEST_CHECK(test_l1[0x300u + index] == transposed[index]);
    }

    for (index = 0u; index < 12u; index++) {
        test_l1[0x400u + index] = (uint8_t)(0xa0u + index);
    }
    desc = test_dma_base();
    desc.src_space = NPU_SPACE_L1;
    desc.dst_space = NPU_SPACE_L1;
    desc.src_addr = 0x400u;
    desc.dst_addr = 0x500u;
    desc.src_region_bytes = 10u;
    desc.dst_region_bytes = 6u;
    desc.segment_count = 3u;
    desc.segment_bytes = 2u;
    desc.segment_stride = 4u;
    desc.shape[0] = desc.segment_count;
    TEST_CHECK_STATUS(npu_dma_execute(&test_model, NPU_DMA_PACK,
                                      &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_l1[0x500u] == 0xa0u);
    TEST_CHECK(test_l1[0x502u] == 0xa4u);
    TEST_CHECK(test_l1[0x504u] == 0xa8u);

    desc.src_addr = 0x500u;
    desc.dst_addr = 0x600u;
    desc.src_region_bytes = 6u;
    desc.dst_region_bytes = 10u;
    TEST_CHECK_STATUS(npu_dma_execute(&test_model, NPU_DMA_SPLIT,
                                      &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_l1[0x600u] == 0xa0u);
    TEST_CHECK(test_l1[0x604u] == 0xa4u);
    TEST_CHECK(test_l1[0x608u] == 0xa8u);

    desc.src_addr = 0x600u;
    desc.dst_addr = 0x604u;
    desc.src_region_bytes = 6u;
    desc.dst_region_bytes = 6u;
    desc.segment_count = 1u;
    desc.segment_bytes = 6u;
    desc.segment_stride = 6u;
    desc.shape[0] = desc.segment_count;
    TEST_CHECK_STATUS(npu_dma_execute(&test_model, NPU_DMA_PACK,
                                      &desc, &progress),
                      NPU_STATUS_ADDR_OVERLAP);

    test_ddr[0x700u] = 1u;
    test_ddr[0x701u] = 2u;
    test_ddr[0x702u] = 3u;
    desc = test_dma_base();
    desc.src_addr = 0x700u;
    desc.dst_addr = 0x700u;
    desc.src_region_bytes = 3u;
    desc.dst_region_bytes = 3u;
    desc.shape[0] = 3u;
    TEST_CHECK_STATUS(npu_dma_execute(&test_model, NPU_DMA_COPY_1D,
                                      &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_l1[0x700u] == 1u);
    TEST_CHECK(test_l1[0x702u] == 3u);

    test_ddr[0x710u] = 0x7fu;
    test_ddr[0x711u] = 0x80u;
    desc = test_dma_base();
    desc.src_addr = 0x710u;
    desc.dst_addr = 0x710u;
    desc.src_region_bytes = 2u;
    desc.dst_region_bytes = 1u;
    desc.shape[0] = 2u;
    desc.src_dtype = NPU_DTYPE_INT8;
    desc.dst_dtype = NPU_DTYPE_INT4;
    desc.convert_mode = NPU_DMA_SATURATE_NARROW;
    TEST_CHECK_STATUS(npu_dma_execute(&test_model, NPU_DMA_COPY_1D,
                                      &desc, &progress),
                      NPU_STATUS_SUCCESS);
    tensor = test_tensor(NPU_DTYPE_INT4, 0x710u, 1u, 1u);
    TEST_CHECK(test_read_tensor(&tensor, 0u, 0u, 7));
    TEST_CHECK(test_read_tensor(&tensor, 0u, 1u, -8));

    test_ddr[0x720u] = 8u;
    desc.src_addr = 0x720u;
    desc.dst_addr = 0x720u;
    desc.src_region_bytes = 1u;
    desc.dst_region_bytes = 1u;
    desc.shape[0] = 1u;
    desc.convert_mode = NPU_DMA_PACK_INT4;
    read_before = test_model.perf.dma_read_bytes;
    TEST_CHECK_STATUS(npu_dma_execute(&test_model, NPU_DMA_COPY_1D,
                                      &desc, &progress),
                      NPU_STATUS_NUMERIC_EXCEPTION);
    TEST_CHECK(test_model.perf.dma_read_bytes == read_before + 1u);
    TEST_CHECK(progress == 0u);
    return 0;
}

static int test_pack_b(const npu_matrix_desc_t *desc,
                       uint32_t batch,
                       uint32_t k,
                       uint32_t n,
                       int32_t value)
{
    uint64_t n_tiles =
        (desc->n + test_model.config.nt - 1u) / test_model.config.nt;
    uint64_t linear =
        ((((uint64_t)(k / test_model.config.kt) * n_tiles +
           n / test_model.config.nt) *
              test_model.config.kt +
          k % test_model.config.kt) *
             test_model.config.nt) +
        n % test_model.config.nt;
    uint64_t addr =
        desc->b.addr + (uint64_t)batch * desc->b.batch_stride_bytes;

    if (desc->b.dtype == NPU_DTYPE_INT8) {
        test_l1[addr + linear] = (uint8_t)value;
    } else {
        uint8_t old = test_l1[addr + linear / 2u];
        test_l1[addr + linear / 2u] =
            npu_int4_insert(old, (uint8_t)(linear & 1u), value);
    }
    return 1;
}

static npu_matrix_desc_t test_matrix_base(void)
{
    npu_matrix_desc_t desc = {0};
    desc.m = 2u;
    desc.n = 2u;
    desc.k = 3u;
    desc.batch_count = 1u;
    desc.a = test_tensor(NPU_DTYPE_INT8, 0x1000u, 6u, 3u);
    desc.b = test_tensor(NPU_DTYPE_INT8, 0x1100u, 128u, 0u);
    desc.b.batch_stride_bytes = 128u;
    desc.c = test_tensor(NPU_DTYPE_INT32, 0x1200u, 16u, 8u);
    desc.src2 = test_tensor(NPU_DTYPE_INT32, 0x1600u, 16u, 8u);
    desc.bias_addr = 0x1300u;
    desc.bias_count = 2u;
    desc.bias_stride_bytes = 4u;
    desc.b_tiled = 1u;
    desc.bias_enable = 1u;
    desc.final_output = 1u;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.output_zero_point = 0;
    return desc;
}

int test_matrix(void)
{
    npu_matrix_desc_t desc;
    npu_tensor_t tensor;
    uint64_t progress;
    uint32_t row;
    uint32_t col;
    int32_t matrix_value;
    static const int32_t a_values[6] = {1, 2, 3, 4, 5, 6};
    static const int32_t b_values[6] = {1, 2, 3, 4, 5, 6};
    static const int32_t expected[4] = {32, 48, 59, 84};

    TEST_CHECK(test_init_model());
    desc = test_matrix_base();
    for (row = 0u; row < 2u; row++) {
        for (col = 0u; col < 3u; col++) {
            TEST_CHECK(test_write_tensor(&desc.a, row, col,
                                         a_values[row * 3u + col]));
        }
    }
    for (row = 0u; row < 3u; row++) {
        for (col = 0u; col < 2u; col++) {
            TEST_CHECK(test_pack_b(&desc, 0u, row, col,
                                   b_values[row * 2u + col]));
        }
    }
    tensor = test_tensor(NPU_DTYPE_INT32, desc.bias_addr, 8u, 8u);
    TEST_CHECK(test_write_tensor(&tensor, 0u, 0u, 10));
    TEST_CHECK(test_write_tensor(&tensor, 0u, 1u, 20));
    TEST_CHECK_STATUS(npu_matrix_execute(&test_model, NPU_MATRIX_GEMM,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 4u);
    for (row = 0u; row < 2u; row++) {
        for (col = 0u; col < 2u; col++) {
            TEST_CHECK(test_read_tensor(&desc.c, row, col,
                                        expected[row * 2u + col]));
        }
    }

    desc.c = test_tensor(NPU_DTYPE_INT8, 0x1400u, 4u, 2u);
    desc.requant_addr = 0x1500u;
    desc.requant_count = 1u;
    desc.requant_region_bytes = 8u;
    desc.requant_enable = 1u;
    test_l1[0x1500u] = 1u;
    test_l1[0x1501u] = 0u;
    test_l1[0x1502u] = 0u;
    test_l1[0x1503u] = 0u;
    test_l1[0x1504u] = 0u;
    TEST_CHECK_STATUS(npu_matrix_execute(&test_model, NPU_MATRIX_GEMM,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    for (row = 0u; row < 2u; row++) {
        for (col = 0u; col < 2u; col++) {
            TEST_CHECK(test_read_tensor(&desc.c, row, col,
                                        expected[row * 2u + col]));
        }
    }

    desc = (npu_matrix_desc_t){0};
    desc.m = 2u;
    desc.n = 2u;
    desc.k = 0u;
    desc.batch_count = 1u;
    desc.c = test_tensor(NPU_DTYPE_INT32, 0x1700u, 16u, 8u);
    TEST_CHECK_STATUS(npu_matrix_execute(&test_model,
                                         NPU_MATRIX_GEMM_ZERO,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 4u);
    for (row = 0u; row < 2u; row++) {
        for (col = 0u; col < 2u; col++) {
            TEST_CHECK(test_read_tensor(&desc.c, row, col, 0));
        }
    }

    desc = test_matrix_base();
    desc.a = test_tensor(NPU_DTYPE_INT4, 0x1800u, 1u, 1u);
    desc.b = test_tensor(NPU_DTYPE_INT4, 0x1900u, 64u, 0u);
    desc.b.batch_stride_bytes = 64u;
    desc.c = test_tensor(NPU_DTYPE_INT32, 0x1a00u, 4u, 4u);
    desc.m = 1u;
    desc.n = 1u;
    desc.k = 2u;
    desc.bias_enable = 0u;
    desc.bias_count = 0u;
    TEST_CHECK(test_write_tensor(&desc.a, 0u, 0u, -2));
    TEST_CHECK(test_write_tensor(&desc.a, 0u, 1u, 3));
    TEST_CHECK(test_pack_b(&desc, 0u, 0u, 0u, 4));
    TEST_CHECK(test_pack_b(&desc, 0u, 1u, 0u, -1));
    TEST_CHECK_STATUS(npu_matrix_execute(&test_model, NPU_MATRIX_GEMM,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_read_tensor(&desc.c, 0u, 0u, -11));

    desc = test_matrix_base();
    desc.m = 1u;
    desc.n = 2u;
    desc.k = 2u;
    desc.batch_count = 2u;
    desc.a = test_tensor(NPU_DTYPE_INT8, 0x1e00u, 4u, 2u);
    desc.a.batch_stride_bytes = 2u;
    desc.b = test_tensor(NPU_DTYPE_INT8, 0x1f00u, 256u, 0u);
    desc.b.batch_stride_bytes = 128u;
    desc.c = test_tensor(NPU_DTYPE_INT32, 0x2100u, 16u, 8u);
    desc.c.batch_stride_bytes = 8u;
    tensor = test_tensor(NPU_DTYPE_INT32, desc.bias_addr, 8u, 8u);
    TEST_CHECK(test_write_tensor(&tensor, 0u, 0u, 1));
    TEST_CHECK(test_write_tensor(&tensor, 0u, 1u, 2));
    TEST_CHECK_STATUS(npu_tensor_write(&test_model, &desc.a,
                                       0u, 0u, 0u, 1),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_tensor_write(&test_model, &desc.a,
                                       0u, 0u, 1u, 2),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_tensor_write(&test_model, &desc.a,
                                       1u, 0u, 0u, 3),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_tensor_write(&test_model, &desc.a,
                                       1u, 0u, 1u, 4),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_pack_b(&desc, 0u, 0u, 0u, 1));
    TEST_CHECK(test_pack_b(&desc, 0u, 0u, 1u, 2));
    TEST_CHECK(test_pack_b(&desc, 0u, 1u, 0u, 3));
    TEST_CHECK(test_pack_b(&desc, 0u, 1u, 1u, 4));
    TEST_CHECK(test_pack_b(&desc, 1u, 0u, 0u, 5));
    TEST_CHECK(test_pack_b(&desc, 1u, 0u, 1u, 6));
    TEST_CHECK(test_pack_b(&desc, 1u, 1u, 0u, 7));
    TEST_CHECK(test_pack_b(&desc, 1u, 1u, 1u, 8));
    TEST_CHECK_STATUS(npu_matrix_execute(&test_model, NPU_MATRIX_BMM,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 4u);
    TEST_CHECK_STATUS(npu_tensor_read(&test_model, &desc.c,
                                      0u, 0u, 0u, &matrix_value),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(matrix_value == 8);
    TEST_CHECK_STATUS(npu_tensor_read(&test_model, &desc.c,
                                      0u, 0u, 1u, &matrix_value),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(matrix_value == 12);
    TEST_CHECK_STATUS(npu_tensor_read(&test_model, &desc.c,
                                      1u, 0u, 0u, &matrix_value),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(matrix_value == 44);
    TEST_CHECK_STATUS(npu_tensor_read(&test_model, &desc.c,
                                      1u, 0u, 1u, &matrix_value),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(matrix_value == 52);
    TEST_CHECK_STATUS(npu_matrix_execute(&test_model, NPU_MATRIX_GEMM,
                                         &desc, &progress),
                      NPU_STATUS_BAD_SHAPE);

    desc = test_matrix_base();
    desc.c = test_tensor(NPU_DTYPE_INT32, 0x1b00u, 16u, 8u);
    desc.src2 = test_tensor(NPU_DTYPE_INT32, 0x1c00u, 16u, 8u);
    desc.bias_enable = 0u;
    desc.bias_count = 0u;
    desc.accum_from_src2 = 1u;
    desc.final_output = 0u;
    for (row = 0u; row < 2u; row++) {
        for (col = 0u; col < 3u; col++) {
            TEST_CHECK(test_write_tensor(&desc.a, row, col,
                                         a_values[row * 3u + col]));
        }
    }
    for (row = 0u; row < 3u; row++) {
        for (col = 0u; col < 2u; col++) {
            TEST_CHECK(test_pack_b(&desc, 0u, row, col,
                                   b_values[row * 2u + col]));
        }
    }
    for (row = 0u; row < 2u; row++) {
        for (col = 0u; col < 2u; col++) {
            TEST_CHECK(test_write_tensor(&desc.src2, row, col, 100));
        }
    }
    TEST_CHECK_STATUS(npu_matrix_execute(&test_model,
                                         NPU_MATRIX_GEMM_ACCUM,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_read_tensor(&desc.c, 0u, 0u, 122));
    TEST_CHECK(test_read_tensor(&desc.c, 1u, 1u, 164));

    desc = test_matrix_base();
    desc.m = 1u;
    desc.n = 1u;
    desc.k = 0u;
    desc.c = test_tensor(NPU_DTYPE_INT32, 0x1d00u, 4u, 4u);
    desc.src2 = test_tensor(NPU_DTYPE_INT32, 0x1d10u, 4u, 4u);
    desc.bias_count = 1u;
    desc.residual_enable = 1u;
    tensor = test_tensor(NPU_DTYPE_INT32, desc.bias_addr, 4u, 4u);
    TEST_CHECK(test_write_tensor(&tensor, 0u, 0u, INT32_MAX));
    TEST_CHECK(test_write_tensor(&desc.src2, 0u, 0u, 1));
    TEST_CHECK_STATUS(npu_matrix_execute(&test_model, NPU_MATRIX_GEMM,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_read_tensor(&desc.c, 0u, 0u, INT32_MAX));
    desc.overflow_mode = NPU_OVERFLOW_WRAP;
    TEST_CHECK_STATUS(npu_matrix_execute(&test_model, NPU_MATRIX_GEMM,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_read_tensor(&desc.c, 0u, 0u, INT32_MIN));
    desc.overflow_mode = NPU_OVERFLOW_ERROR;
    TEST_CHECK_STATUS(npu_matrix_execute(&test_model, NPU_MATRIX_GEMM,
                                         &desc, &progress),
                      NPU_STATUS_NUMERIC_EXCEPTION);
    return 0;
}

static npu_vector_desc_t test_vector_base(void)
{
    npu_vector_desc_t desc = {0};
    desc.rows = 1u;
    desc.length = 4u;
    desc.valid_length = 4u;
    desc.src0 = test_tensor(NPU_DTYPE_INT8, 0x2000u, 4u, 4u);
    desc.src1 = test_tensor(NPU_DTYPE_INT8, 0x2100u, 4u, 4u);
    desc.src2 = test_tensor(NPU_DTYPE_INT32, 0x2200u, 16u, 16u);
    desc.dst = test_tensor(NPU_DTYPE_INT8, 0x2300u, 16u, 4u);
    desc.mask = test_tensor(NPU_DTYPE_INT8, 0x2400u, 4u, 4u);
    desc.broadcast0 = NPU_BROADCAST_NONE;
    desc.broadcast1 = NPU_BROADCAST_NONE;
    desc.broadcast2 = NPU_BROADCAST_NONE;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.src0_scale_bits = 0x3f800000u;
    desc.src1_scale_bits = 0x3f800000u;
    desc.src2_scale_bits = 0x3f800000u;
    desc.dst_scale_bits = 0x3f800000u;
    return desc;
}

static int test_vector_expected(const npu_tensor_t *tensor,
                                const int32_t values[4])
{
    uint32_t index;
    for (index = 0u; index < 4u; index++) {
        if (!test_read_tensor(tensor, 0u, index, values[index])) {
            return 0;
        }
    }
    return 1;
}

int test_vector(void)
{
    npu_vector_desc_t desc;
    uint64_t progress;
    uint32_t index;
    uint32_t invalid_scale;
    static const uint32_t invalid_scales[5] = {
        0x00000000u,
        0x80000000u,
        0xbf800000u,
        0x7f800000u,
        0x7fc00000u
    };
    static const int32_t src0[4] = {-2, -1, 2, 5};
    static const int32_t src1[4] = {3, -2, 2, 1};
    static const int32_t add_expected[4] = {1, -3, 4, 6};
    static const int32_t sub_expected[4] = {-5, 1, 0, 4};
    static const int32_t max_expected[4] = {3, -1, 2, 5};
    static const int32_t min_expected[4] = {-2, -2, 2, 1};
    static const int32_t cmp_expected[4] = {0, 1, 0, 1};
    static const int32_t select_expected[4] = {3, -1, 2, 5};
    static const int32_t clamp_expected[4] = {-1, -1, 2, 2};
    static const int32_t relu_expected[4] = {0, 0, 2, 5};
    static const int32_t mul_expected[4] = {-6, 2, 4, 5};
    static const int32_t fma_expected[4] = {4, 22, 34, 45};

    TEST_CHECK(test_init_model());
    desc = test_vector_base();
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(test_write_tensor(&desc.src0, 0u, index, src0[index]));
        TEST_CHECK(test_write_tensor(&desc.src1, 0u, index, src1[index]));
        TEST_CHECK(test_write_tensor(&desc.src2, 0u, index,
                                     (int32_t)(10u * (index + 1u))));
        TEST_CHECK(test_write_tensor(&desc.mask, 0u, index,
                                     (index & 1u) == 0u ? 1 : 0));
    }

    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_ADD,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_vector_expected(&desc.dst, add_expected));
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_SUB,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_vector_expected(&desc.dst, sub_expected));
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_MAX,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_vector_expected(&desc.dst, max_expected));
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_MIN,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_vector_expected(&desc.dst, min_expected));

    desc.compare_mode = NPU_COMPARE_GT;
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_CMP,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_vector_expected(&desc.dst, cmp_expected));

    desc.mask_enable = 1u;
    TEST_CHECK_STATUS(npu_vector_execute(&test_model,
                                         NPU_VECTOR_SELECT,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_vector_expected(&desc.dst, select_expected));
    desc.mask_enable = 0u;

    desc.clamp_min = -1;
    desc.clamp_max = 2;
    TEST_CHECK_STATUS(npu_vector_execute(&test_model,
                                         NPU_VECTOR_CLAMP,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_vector_expected(&desc.dst, clamp_expected));
    TEST_CHECK_STATUS(npu_vector_execute(&test_model,
                                         NPU_VECTOR_RELU,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_vector_expected(&desc.dst, relu_expected));

    desc.dst = test_tensor(NPU_DTYPE_INT32, 0x2500u, 16u, 16u);
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_MUL,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_vector_expected(&desc.dst, mul_expected));
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_FMA,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_vector_expected(&desc.dst, fma_expected));
    TEST_CHECK(progress == 4u);

    desc = test_vector_base();
    desc.rows = 2u;
    desc.length = 4u;
    desc.valid_length = 2u;
    desc.src0.region_bytes = 8u;
    desc.src0.row_stride_bytes = 4u;
    desc.src1.region_bytes = 4u;
    desc.broadcast1 = NPU_BROADCAST_FEATURE;
    desc.dst.region_bytes = 8u;
    desc.dst.row_stride_bytes = 4u;
    for (index = 0u; index < 8u; index++) {
        TEST_CHECK(test_write_tensor(&desc.src0, index / 4u,
                                     index % 4u, (int32_t)index));
        test_l1[desc.dst.addr + index] = 99u;
    }
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(test_write_tensor(&desc.src1, 0u, index,
                                     (int32_t)(10u + index)));
    }
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_ADD,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 6u);
    TEST_CHECK(test_read_tensor(&desc.dst, 0u, 3u, 16));
    TEST_CHECK(test_read_tensor(&desc.dst, 1u, 0u, 14));
    TEST_CHECK(test_read_tensor(&desc.dst, 1u, 1u, 16));
    TEST_CHECK(test_l1[desc.dst.addr + 6u] == 99u);

    desc.rows = 1u;
    desc.valid_length = 4u;
    desc.src1_from_scalar0 = 1u;
    desc.scalar0 = 5;
    desc.broadcast1 = NPU_BROADCAST_NONE;
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_ADD,
                                         &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_read_tensor(&desc.dst, 0u, 0u, 5));
    TEST_CHECK(test_read_tensor(&desc.dst, 0u, 3u, 8));

    desc = test_vector_base();
    for (invalid_scale = 0u;
         invalid_scale < sizeof(invalid_scales) / sizeof(invalid_scales[0]);
         invalid_scale++) {
        desc.src0_scale_bits = invalid_scales[invalid_scale];
        TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_ADD,
                                             &desc, &progress),
                          NPU_STATUS_BAD_DESC);
        TEST_CHECK(progress == 0u);
    }
    desc = test_vector_base();
    desc.src1_scale_bits = 0x7f800000u;
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_ADD,
                                         &desc, &progress),
                      NPU_STATUS_BAD_DESC);
    TEST_CHECK(progress == 0u);
    desc = test_vector_base();
    desc.dst_scale_bits = 0x7fc00000u;
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_RELU,
                                         &desc, &progress),
                      NPU_STATUS_BAD_DESC);
    TEST_CHECK(progress == 0u);
    desc = test_vector_base();
    desc.dst = test_tensor(NPU_DTYPE_INT32, 0x2500u, 16u, 16u);
    desc.src2_scale_bits = 0x80000000u;
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_FMA,
                                         &desc, &progress),
                      NPU_STATUS_BAD_DESC);
    TEST_CHECK(progress == 0u);

    desc = test_vector_base();
    desc.length = 2u;
    desc.valid_length = 2u;
    desc.overflow_mode = NPU_OVERFLOW_ERROR;
    TEST_CHECK(test_write_tensor(&desc.src0, 0u, 0u, 1));
    TEST_CHECK(test_write_tensor(&desc.src0, 0u, 1u, 100));
    TEST_CHECK(test_write_tensor(&desc.src1, 0u, 0u, 2));
    TEST_CHECK(test_write_tensor(&desc.src1, 0u, 1u, 100));
    TEST_CHECK(test_write_tensor(&desc.dst, 0u, 0u, 55));
    TEST_CHECK(test_write_tensor(&desc.dst, 0u, 1u, 55));
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_ADD,
                                         &desc, &progress),
                      NPU_STATUS_NUMERIC_EXCEPTION);
    TEST_CHECK(progress == 0u);
    TEST_CHECK(test_read_tensor(&desc.dst, 0u, 0u, 55));
    TEST_CHECK(test_read_tensor(&desc.dst, 0u, 1u, 55));

    desc = test_vector_base();
    desc.length = 9u;
    desc.valid_length = 9u;
    desc.src0.region_bytes = 9u;
    desc.dst.region_bytes = 9u;
    desc.src1_from_scalar0 = 1u;
    desc.scalar0 = 1;
    desc.overflow_mode = NPU_OVERFLOW_ERROR;
    for (index = 0u; index < 9u; index++) {
        TEST_CHECK(test_write_tensor(&desc.src0, 0u, index,
                                     index == 8u ? 127 : 1));
        TEST_CHECK(test_write_tensor(&desc.dst, 0u, index, 55));
    }
    TEST_CHECK_STATUS(npu_vector_execute(&test_model, NPU_VECTOR_ADD,
                                         &desc, &progress),
                      NPU_STATUS_NUMERIC_EXCEPTION);
    TEST_CHECK(progress == 8u);
    for (index = 0u; index < 8u; index++) {
        TEST_CHECK(test_read_tensor(&desc.dst, 0u, index, 2));
    }
    TEST_CHECK(test_read_tensor(&desc.dst, 0u, 8u, 55));
    return 0;
}

int test_math(void)
{
    TEST_CHECK(test_abs_float(npu_exp_approx(-1.0f) -
                              0.3678794503f) < 0.000002f);
    TEST_CHECK(test_abs_float(npu_exp_approx(1.0f) -
                              2.7182817459f) < 0.000005f);
    TEST_CHECK(test_abs_float(npu_reciprocal_approx(3.0f) -
                              0.3333333433f) < 0.000002f);
    TEST_CHECK(test_abs_float(npu_rsqrt_approx(2.0f) -
                              0.7071067691f) < 0.000002f);
    TEST_CHECK(test_abs_float(npu_sigmoid_approx(-4.0f) -
                              0.0179862082f) < 0.000002f);
    TEST_CHECK(test_abs_float(npu_sigmoid_approx(4.0f) -
                              0.9820137024f) < 0.000002f);
    TEST_CHECK(test_abs_float(npu_tanh_approx(2.0f) -
                              0.9640275240f) < 0.000002f);
    TEST_CHECK(test_abs_float(npu_silu_approx(2.0f) -
                              1.7615940571f) < 0.000005f);
    TEST_CHECK(test_abs_float(npu_gelu_approx(2.0f) -
                              1.9545977116f) < 0.00001f);
    TEST_CHECK(npu_float_is_finite_positive(1.0f));
    TEST_CHECK(!npu_float_is_finite_positive(0.0f));
    TEST_CHECK(!npu_float_is_finite_positive(-1.0f));
    return 0;
}

static npu_complex_desc_t test_complex_base(void)
{
    npu_complex_desc_t desc = {0};
    desc.rows = 1u;
    desc.length = 5u;
    desc.valid_length = 5u;
    desc.src0 = test_tensor(NPU_DTYPE_INT8, 0x3000u, 16u, 8u);
    desc.src1 = test_tensor(NPU_DTYPE_INT8, 0x3100u, 16u, 8u);
    desc.src2 = test_tensor(NPU_DTYPE_INT8, 0x3200u, 16u, 8u);
    desc.dst = test_tensor(NPU_DTYPE_INT8, 0x3300u, 16u, 8u);
    desc.mask = test_tensor(NPU_DTYPE_INT8, 0x3400u, 16u, 8u);
    desc.valid_lengths =
        test_tensor(NPU_DTYPE_INT32, 0x3500u, 4u, 4u);
    desc.src0_scale = 0.5f;
    desc.src1_scale = 1.0f;
    desc.src2_scale = 1.0f;
    desc.dst_scale = 1.0f / 128.0f;
    desc.scale_mode = NPU_SCALE_PER_TENSOR;
    desc.epsilon = 0.0f;
    desc.input_clip_min = -16.0f;
    desc.input_clip_max = 16.0f;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.mask_mode = NPU_MASK_NONE;
    desc.all_mask_mode = NPU_ALL_MASK_WRITE_ZERO;
    desc.scratch_request_elems = 0u;
    desc.beta_enable = 1u;
    return desc;
}

static int test_complex_vector(const npu_complex_desc_t *desc,
                               const int32_t *expected,
                               uint32_t length)
{
    uint32_t index;
    for (index = 0u; index < length; index++) {
        if (!test_read_tensor(&desc->dst, 0u, index, expected[index])) {
            return 0;
        }
    }
    return 1;
}

int test_complex(void)
{
    npu_complex_desc_t desc;
    npu_tensor_t src_scale_table;
    npu_tensor_t dst_scale_table;
    uint64_t progress;
    uint32_t index;
    static const int32_t activation_input[5] = {-8, -4, 0, 4, 8};
    static const int32_t sigmoid_expected[5] = {2, 15, 64, 113, 126};
    static const int32_t tanh_expected[5] = {-128, -123, 0, 123, 127};
    static const int32_t silu_expected[5] = {-2, -8, 0, 56, 126};
    static const int32_t gelu_expected[5] = {0, -1, 0, 63, 127};
    static const int32_t softmax_expected[4] = {4, 11, 30, 82};
    static const int32_t masked_expected[4] = {15, 0, 113, 0};
    static const int32_t norm_expected[4] = {-21, -7, 7, 21};
    static const int32_t rms_expected[4] = {6, 12, 18, 23};

    TEST_CHECK(test_init_model());
    desc = test_complex_base();
    for (index = 0u; index < 5u; index++) {
        TEST_CHECK(test_write_tensor(&desc.src0, 0u, index,
                                     activation_input[index]));
    }
    desc.function = NPU_FUNC_SIGMOID;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model, NPU_COMPLEX_ACT,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_complex_vector(&desc, sigmoid_expected, 5u));

    desc.function = NPU_FUNC_TANH;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model, NPU_COMPLEX_ACT,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_complex_vector(&desc, tanh_expected, 5u));
    desc.function = NPU_FUNC_SILU;
    desc.dst_scale = 1.0f / 32.0f;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model, NPU_COMPLEX_ACT,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_complex_vector(&desc, silu_expected, 5u));
    desc.function = NPU_FUNC_GELU;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model, NPU_COMPLEX_ACT,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_complex_vector(&desc, gelu_expected, 5u));

    src_scale_table =
        test_tensor(NPU_DTYPE_INT32, 0x3700u, 20u, 20u);
    dst_scale_table =
        test_tensor(NPU_DTYPE_INT32, 0x3800u, 20u, 20u);
    for (index = 0u; index < 5u; index++) {
        TEST_CHECK(test_write_tensor(&src_scale_table, 0u, index,
                                     0x3f000000));
        TEST_CHECK(test_write_tensor(&dst_scale_table, 0u, index,
                                     0x3c000000));
    }
    desc = test_complex_base();
    desc.function = NPU_FUNC_SIGMOID;
    desc.scale_mode = NPU_SCALE_PER_FEATURE;
    desc.src0_scale = 0.0f;
    desc.dst_scale = 0.0f;
    desc.src0_scale_table_addr = src_scale_table.addr;
    desc.dst_scale_table_addr = dst_scale_table.addr;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model, NPU_COMPLEX_ACT,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_complex_vector(&desc, sigmoid_expected, 5u));

    TEST_CHECK(test_write_tensor(&src_scale_table, 0u, 2u, 0));
    TEST_CHECK_STATUS(npu_complex_execute(&test_model, NPU_COMPLEX_ACT,
                                          &desc, &progress),
                      NPU_STATUS_BAD_DESC);
    TEST_CHECK(progress == 0u);
    TEST_CHECK(test_write_tensor(&src_scale_table, 0u, 2u,
                                 0x3f000000));
    desc.src0_scale_table_addr++;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model, NPU_COMPLEX_ACT,
                                          &desc, &progress),
                      NPU_STATUS_BAD_DESC);
    desc.src0_scale_table_addr = src_scale_table.addr;
    desc.dst_scale_table_addr = TEST_L1_BYTES - 4u;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model, NPU_COMPLEX_ACT,
                                          &desc, &progress),
                      NPU_STATUS_ADDR_FAULT);

    desc = test_complex_base();
    desc.length = 4u;
    desc.valid_length = 4u;
    desc.src0_scale = 1.0f;
    desc.dst_scale = 1.0f / 128.0f;
    desc.function = NPU_FUNC_SOFTMAX;
    desc.scratch_request_elems = 5u;
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(test_write_tensor(&desc.src0, 0u, index,
                                     (int32_t)(index + 1u)));
    }
    TEST_CHECK_STATUS(npu_complex_execute(&test_model,
                                          NPU_COMPLEX_SOFTMAX,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_complex_vector(&desc, softmax_expected, 4u));

    desc.mask_mode = NPU_MASK_BOOLEAN;
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(test_write_tensor(&desc.mask, 0u, index,
                                     (index & 1u) == 0u ? 1 : 0));
    }
    TEST_CHECK_STATUS(npu_complex_execute(&test_model,
                                          NPU_COMPLEX_SOFTMAX,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_complex_vector(&desc, masked_expected, 4u));

    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(test_write_tensor(&desc.mask, 0u, index, 0));
    }
    TEST_CHECK_STATUS(npu_complex_execute(&test_model,
                                          NPU_COMPLEX_SOFTMAX,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_model.perf.all_mask_row_count == 1u);
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(test_read_tensor(&desc.dst, 0u, index, 0));
    }
    desc.all_mask_mode = NPU_ALL_MASK_ERROR;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model,
                                          NPU_COMPLEX_SOFTMAX,
                                          &desc, &progress),
                      NPU_STATUS_NUMERIC_EXCEPTION);
    desc.all_mask_mode = NPU_ALL_MASK_WRITE_ZERO;

    desc = test_complex_base();
    desc.rows = 2u;
    desc.length = 4u;
    desc.valid_length = 4u;
    desc.src0.region_bytes = 8u;
    desc.src0.row_stride_bytes = 4u;
    desc.dst.region_bytes = 8u;
    desc.dst.row_stride_bytes = 4u;
    desc.valid_lengths.region_bytes = 8u;
    desc.valid_lengths.row_stride_bytes = 4u;
    desc.src0_scale = 1.0f;
    desc.dst_scale = 1.0f / 128.0f;
    desc.function = NPU_FUNC_SOFTMAX;
    desc.mask_mode = NPU_MASK_VALID_LENGTH;
    desc.scratch_request_elems = 4u;
    for (index = 0u; index < 8u; index++) {
        TEST_CHECK(test_write_tensor(&desc.src0, index / 4u,
                                     index % 4u, 0));
        test_l1[desc.dst.addr + index] = 77u;
    }
    TEST_CHECK(test_write_tensor(&desc.valid_lengths, 0u, 0u, 4));
    TEST_CHECK(test_write_tensor(&desc.valid_lengths, 1u, 0u, 5));
    TEST_CHECK_STATUS(npu_complex_execute(&test_model,
                                          NPU_COMPLEX_SOFTMAX,
                                          &desc, &progress),
                      NPU_STATUS_BAD_SHAPE);
    TEST_CHECK(progress == 0u);
    for (index = 0u; index < 8u; index++) {
        TEST_CHECK(test_l1[desc.dst.addr + index] == 77u);
    }

    desc = test_complex_base();
    desc.length = 4u;
    desc.valid_length = 4u;
    desc.mask_mode = NPU_MASK_NONE;
    desc.function = NPU_FUNC_LAYERNORM;
    desc.src0_scale = 1.0f;
    desc.src1_scale = 1.0f;
    desc.src2_scale = 1.0f;
    desc.dst_scale = 1.0f / 16.0f;
    desc.epsilon = 0.00001f;
    desc.input_clip_min = 0.0f;
    desc.input_clip_max = 0.0f;
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(test_write_tensor(&desc.src0, 0u, index,
                                     (int32_t)(index + 1u)));
        TEST_CHECK(test_write_tensor(&desc.src1, 0u, index, 1));
        TEST_CHECK(test_write_tensor(&desc.src2, 0u, index, 0));
    }
    TEST_CHECK_STATUS(npu_complex_execute(&test_model,
                                          NPU_COMPLEX_NORM,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_complex_vector(&desc, norm_expected, 4u));

    desc.stats_mode = 1u;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model,
                                          NPU_COMPLEX_NORM,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_complex_vector(&desc, norm_expected, 4u));
    desc.stats_mode = 0u;

    desc.function = NPU_FUNC_RMSNORM;
    desc.beta_enable = 0u;
    desc.src2.addr = 0u;
    desc.src2_scale = 0.0f;
    desc.src2_zero_point = 0;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model,
                                          NPU_COMPLEX_NORM,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_complex_vector(&desc, rms_expected, 4u));

    desc.function = NPU_FUNC_STAT_SUM;
    desc.dst = test_tensor(NPU_DTYPE_INT32, 0x3600u, 4u, 4u);
    desc.scale_mode = NPU_SCALE_NONE;
    desc.src0_scale = 0.0f;
    desc.src1_scale = 0.0f;
    desc.src2_scale = 0.0f;
    desc.dst_scale = 0.0f;
    desc.epsilon = 0.0f;
    desc.input_clip_min = 0.0f;
    desc.input_clip_max = 0.0f;
    desc.scratch_request_elems = 0u;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model,
                                          NPU_COMPLEX_STAT,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_read_tensor(&desc.dst, 0u, 0u, 10));
    desc.function = NPU_FUNC_STAT_MAX;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model,
                                          NPU_COMPLEX_STAT,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_read_tensor(&desc.dst, 0u, 0u, 4));
    desc.function = NPU_FUNC_STAT_SUMSQ;
    TEST_CHECK_STATUS(npu_complex_execute(&test_model,
                                          NPU_COMPLEX_STAT,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_read_tensor(&desc.dst, 0u, 0u, 30));

    desc = test_complex_base();
    desc.length = 4u;
    desc.valid_length = 4u;
    desc.function = NPU_FUNC_ADD_RESCALE;
    desc.src0_scale = 0.5f;
    desc.src1_scale = 0.25f;
    desc.dst_scale = 0.25f;
    desc.input_clip_min = 0.0f;
    desc.input_clip_max = 0.0f;
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(test_write_tensor(&desc.src0, 0u, index,
                                     (int32_t)index));
        TEST_CHECK(test_write_tensor(&desc.src1, 0u, index, 4));
    }
    TEST_CHECK_STATUS(npu_complex_execute(&test_model,
                                          NPU_COMPLEX_ADD_RESCALE,
                                          &desc, &progress),
                      NPU_STATUS_SUCCESS);
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(test_read_tensor(&desc.dst, 0u, index,
                                    (int32_t)(4u + index * 2u)));
    }
    for (index = 0u; index < 3u; index++) {
        TEST_CHECK(test_write_tensor(&desc.dst, 0u, index, 77));
    }
    desc.dst.region_bytes = 3u;
    TEST_CHECK_STATUS(npu_complex_execute(
                          &test_model, NPU_COMPLEX_ADD_RESCALE,
                          &desc, &progress),
                      NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(progress == 0u);
    for (index = 0u; index < 3u; index++) {
        TEST_CHECK(test_read_tensor(&desc.dst, 0u, index, 77));
    }
    return 0;
}

int test_scheduler(void)
{
    npu_task_request_t producer;
    npu_task_request_t consumer;
    npu_task_request_t bad;
    npu_task_request_t dependent;
    npu_task_result_t producer_result;
    npu_task_result_t consumer_result;
    npu_event_ref_t event;
    npu_event_ref_t event_b;
    npu_event_ref_t event_out;
    npu_event_ref_t next_event;
    npu_task_request_t join;
    npu_task_request_t rearm;
    npu_task_request_t timed;

    TEST_CHECK(test_init_model());
    event.id = 3u;
    event.generation = 0u;
    producer = test_base_request(NPU_ENGINE_CONTROL,
                                 NPU_CTRL_EVENT_SIGNAL, 1u);
    producer.cmd.signal_event = event;
    producer.desc.control.event0 = npu_event_none();
    producer.desc.control.event1 = npu_event_none();
    producer.desc.control.target = event;
    consumer = test_base_request(NPU_ENGINE_VECTOR,
                                 NPU_VECTOR_ADD, 2u);
    consumer.cmd.wait_event[0] = event;
    consumer.desc.vector = test_vector_base();
    TEST_CHECK_STATUS(npu_model_submit(&test_model, &producer),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_submit(&test_model, &consumer),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_run(&test_model, 200u),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 1u, 0,
                                      &producer_result),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 2u, 0,
                                      &consumer_result),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(consumer_result.start_cycle >
               producer_result.end_cycle);
    TEST_CHECK(!npu_model_idle(&test_model));
    TEST_CHECK_STATUS(npu_model_query(&test_model, 1u, 1,
                                      &producer_result),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 2u, 1,
                                      &consumer_result),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(npu_model_idle(&test_model));

    event.id = 4u;
    event.generation = 0u;
    bad = test_base_request(NPU_ENGINE_DMA,
                            NPU_DMA_COPY_1D, 3u);
    bad.cmd.signal_event = event;
    bad.desc.dma = test_dma_base();
    bad.desc.dma.src_addr = TEST_DDR_BYTES - 1u;
    bad.desc.dma.dst_addr = 0x7000u;
    bad.desc.dma.src_region_bytes = 2u;
    bad.desc.dma.dst_region_bytes = 2u;
    bad.desc.dma.shape[0] = 2u;
    dependent = test_base_request(NPU_ENGINE_VECTOR,
                                  NPU_VECTOR_ADD, 4u);
    dependent.cmd.wait_event[0] = event;
    dependent.desc.vector = test_vector_base();
    TEST_CHECK_STATUS(npu_model_submit(&test_model, &bad),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_submit(&test_model, &dependent),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_run(&test_model, 200u),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 3u, 0,
                                      &producer_result),
                      NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(producer_result.fault_addr == TEST_DDR_BYTES);
    TEST_CHECK((producer_result.done_flags &
                NPU_DONE_FAULT_ADDR_IS_L1) == 0u);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 4u, 0,
                                      &consumer_result),
                      NPU_STATUS_DEPENDENCY_FAILED);
    TEST_CHECK(consumer_result.start_cycle == 0u);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 3u, 1,
                                      &producer_result),
                      NPU_STATUS_ADDR_FAULT);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 4u, 1,
                                      &consumer_result),
                      NPU_STATUS_DEPENDENCY_FAILED);

    producer = test_base_request(NPU_ENGINE_CONTROL, NPU_CTRL_NOP, 5u);
    TEST_CHECK_STATUS(npu_model_submit(&test_model, &producer),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_submit(&test_model, &producer),
                      NPU_STATUS_BUSY);
    TEST_CHECK_STATUS(npu_model_run(&test_model, 100u),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 5u, 1,
                                      &producer_result),
                      NPU_STATUS_SUCCESS);

    event.id = 10u;
    event.generation = 0u;
    event_b.id = 11u;
    event_b.generation = 0u;
    event_out.id = 12u;
    event_out.generation = 0u;
    TEST_CHECK_STATUS(npu_event_reserve(
                          &test_model, event.id,
                          event.generation, 0x1000u),
                      NPU_STATUS_BAD_DESC);
    TEST_CHECK(test_model.events[event.id].state ==
               NPU_EVENT_FREE);
    TEST_CHECK_STATUS(npu_event_reserve(&test_model, event.id,
                                        event.generation, 0x701u),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_event_reserve(&test_model, event_b.id,
                                        event_b.generation, 0x702u),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_event_signal(&test_model, event,
                                       NPU_STATUS_SUCCESS),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_event_signal(
                          &test_model, event_b,
                          (npu_status_t)0x7fu),
                      NPU_STATUS_BAD_DESC);
    TEST_CHECK(test_model.events[event_b.id].state ==
               NPU_EVENT_RESERVED);
    TEST_CHECK(test_model.events[event_b.id].status ==
               NPU_STATUS_BUSY);
    TEST_CHECK_STATUS(npu_event_signal(&test_model, event_b,
                                       NPU_STATUS_BUS_SLVERR),
                      NPU_STATUS_SUCCESS);
    join = test_base_request(NPU_ENGINE_CONTROL,
                             NPU_CTRL_EVENT_JOIN, 8u);
    join.cmd.wait_event[0] = event;
    join.cmd.wait_event[1] = event_b;
    join.cmd.signal_event = event_out;
    join.desc.control.event0 = event;
    join.desc.control.event1 = event_b;
    join.desc.control.target = event_out;
    join.desc.control.join_mode = 1u;
    TEST_CHECK_STATUS(npu_model_submit(&test_model, &join),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_run(&test_model, 100u),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 8u, 0,
                                      &producer_result),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_model.events[event_out.id].state ==
               NPU_EVENT_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 8u, 1,
                                      &producer_result),
                      NPU_STATUS_SUCCESS);

    next_event = event;
    next_event.generation = 1u;
    rearm = test_base_request(NPU_ENGINE_CONTROL,
                              NPU_CTRL_EVENT_REARM, 10u);
    rearm.desc.control.event0 = event;
    rearm.desc.control.event1 = npu_event_none();
    rearm.desc.control.target = next_event;
    TEST_CHECK_STATUS(npu_model_submit(&test_model, &rearm),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_run(&test_model, 100u),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 10u, 0,
                                      &producer_result),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(test_model.events[event.id].state == NPU_EVENT_FREE);
    TEST_CHECK(test_model.events[event.id].generation ==
               next_event.generation);
    TEST_CHECK(test_model.events[event.id].waiter_count == 0u);
    TEST_CHECK(test_model.events[event.id].producer_task_id == 0u);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 10u, 1,
                                      &producer_result),
                      NPU_STATUS_SUCCESS);

    timed = test_base_request(NPU_ENGINE_VECTOR,
                              NPU_VECTOR_ADD, 9u);
    timed.cmd.timeout_class = 1u;
    timed.desc.vector = test_vector_base();
    test_model.config.timeout_cycles[1] = 2u;
    TEST_CHECK_STATUS(npu_model_submit(&test_model, &timed),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_run(&test_model, 100u),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 9u, 0,
                                      &producer_result),
                      NPU_STATUS_TIMEOUT);
    TEST_CHECK(producer_result.progress == 0u);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 9u, 1,
                                      &producer_result),
                      NPU_STATUS_TIMEOUT);
    return 0;
}

int test_frontend(void)
{
    npu_cmd_t command = {0};
    npu_host_inputs_t inputs = {0};
    npu_host_outputs_t outputs;
    npu_task_result_t result;
    uint64_t low_beat;
    uint64_t high_beat;
    uint64_t held_response;
    uint32_t cycle;

    TEST_CHECK(test_init_model());
    command.command_id = 6u;
    command.engine = NPU_ENGINE_CONTROL;
    command.opcode = NPU_CTRL_NOP;
    command.header_flags = 1u;
    command.wait_event[0] = npu_event_none();
    command.wait_event[1] = npu_event_none();
    command.signal_event = npu_event_none();
    command.timeout_class = 0u;
    command.inline_format = 1u;
    command.inline_dtype = NPU_DTYPE_INT8;
    npu_cmd_encode(&command, &low_beat, &high_beat);

    inputs.core_reset_n = 1u;
    inputs.noc_reset_n = 1u;
    inputs.cmd_valid = 1u;
    inputs.cmd_data = low_beat;
    inputs.cmd_first = 1u;
    inputs.cmd_last = 0u;
    npu_model_cycle_io(&test_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_ready == 1u);
    TEST_CHECK(outputs.cmd_rsp_valid == 0u);

    inputs.cmd_data = high_beat;
    inputs.cmd_first = 0u;
    inputs.cmd_last = 1u;
    npu_model_cycle_io(&test_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_ready == 1u);
    TEST_CHECK(outputs.cmd_rsp_valid == 0u);
    TEST_CHECK(test_model.tasks[0].request.cmd.header_version == 0u);
    TEST_CHECK((test_model.tasks[0].request.cmd.header_flags & 1u) !=
               0u);

    inputs.cmd_valid = 0u;
    inputs.cmd_first = 0u;
    inputs.cmd_last = 0u;
    npu_model_cycle_io(&test_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_rsp_valid == 1u);
    TEST_CHECK(outputs.cmd_ready == 0u);
    held_response = outputs.cmd_rsp_data;
    TEST_CHECK((held_response & 0x0fffu) == 6u);
    TEST_CHECK(((held_response >> 12) & 0xffu) ==
               NPU_STATUS_SUCCESS);

    inputs.cmd_rsp_ready = 0u;
    for (cycle = 0u; cycle < 4u; cycle++) {
        npu_model_cycle_io(&test_model, &inputs, &outputs);
        TEST_CHECK(outputs.cmd_rsp_valid == 1u);
        TEST_CHECK(outputs.cmd_rsp_data == held_response);
        TEST_CHECK(outputs.cmd_ready == 0u);
    }
    inputs.cmd_rsp_ready = 1u;
    npu_model_cycle_io(&test_model, &inputs, &outputs);
    TEST_CHECK(outputs.cmd_rsp_valid == 1u);
    TEST_CHECK(outputs.cmd_rsp_data == held_response);

    inputs.cmd_rsp_ready = 0u;
    for (cycle = 0u; cycle < 32u; cycle++) {
        npu_model_cycle_io(&test_model, &inputs, &outputs);
    }
    TEST_CHECK_STATUS(npu_model_query(&test_model, 6u, 0, &result),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(result.user_tag == 6u);
    TEST_CHECK(result.end_cycle > result.start_cycle);
    TEST_CHECK_STATUS(npu_model_query(&test_model, 6u, 1, &result),
                      NPU_STATUS_SUCCESS);
    return 0;
}
