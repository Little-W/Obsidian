#include "npu_wire.h"
#include "test_util.h"

#define WIRE_NONE 0x0fffu

static void wire_zero(uint8_t *data, size_t bytes)
{
    size_t index;

    for (index = 0u; index < bytes; index++) {
        data[index] = 0u;
    }
}

static void wire_put_u16(uint8_t *data, size_t offset, uint16_t value)
{
    data[offset] = (uint8_t)(value & 0xffu);
    data[offset + 1u] = (uint8_t)(value >> 8);
}

static void wire_put_u32(uint8_t *data, size_t offset, uint32_t value)
{
    uint32_t index;

    for (index = 0u; index < 4u; index++) {
        data[offset + index] =
            (uint8_t)(value >> (index * 8u));
    }
}

static void wire_put_u64(uint8_t *data, size_t offset, uint64_t value)
{
    uint32_t index;

    for (index = 0u; index < 8u; index++) {
        data[offset + index] =
            (uint8_t)(value >> (index * 8u));
    }
}

static uint64_t wire_get_u64(const uint8_t *data, size_t offset)
{
    uint64_t value = 0u;
    uint32_t index;

    for (index = 0u; index < 8u; index++) {
        value |= (uint64_t)data[offset + index] << (index * 8u);
    }
    return value;
}

static uint32_t wire_numeric(npu_dtype_t src0,
                             npu_dtype_t src1,
                             npu_dtype_t src2,
                             npu_dtype_t dst,
                             npu_round_mode_t round_mode,
                             uint8_t saturate,
                             uint8_t scale_mode,
                             uint8_t zero_point_enable,
                             uint8_t internal_fp32)
{
    return (uint32_t)src0 |
           ((uint32_t)src1 << 2) |
           ((uint32_t)src2 << 4) |
           ((uint32_t)dst << 6) |
           ((uint32_t)round_mode << 10) |
           ((uint32_t)(saturate & 1u) << 12) |
           ((uint32_t)(scale_mode & 3u) << 13) |
           ((uint32_t)(zero_point_enable & 1u) << 15) |
           ((uint32_t)(internal_fp32 & 1u) << 16);
}

static void wire_make_cmd(uint8_t *wire,
                          uint64_t desc_addr,
                          uint16_t command_id,
                          npu_engine_t engine,
                          uint8_t opcode,
                          uint16_t header_flags,
                          uint16_t wait0,
                          uint16_t wait1,
                          uint16_t signal)
{
    uint64_t low =
        (desc_addr & UINT64_C(0x0000ffffffffffff)) |
        ((uint64_t)(command_id & 0x0fffu) << 48u) |
        ((uint64_t)((uint8_t)engine & 0x0fu) << 60u);
    uint64_t high =
        (uint64_t)opcode |
        ((uint64_t)(header_flags & 0x0fffu) << 8u) |
        ((uint64_t)(wait0 & 0x0fffu) << 20u) |
        ((uint64_t)(wait1 & 0x0fffu) << 32u) |
        ((uint64_t)(signal & 0x0fffu) << 44u) |
        ((uint64_t)NPU_WIRE_HEADER_VERSION << 56u);

    wire_zero(wire, NPU_WIRE_CMD_BYTES);
    wire_put_u64(wire, 0u, low);
    wire_put_u64(wire, 8u, high);
}

static void wire_make_common(uint8_t *wire,
                             size_t bytes,
                             npu_engine_t engine,
                             uint32_t op_flags,
                             uint64_t src0,
                             uint64_t src1,
                             uint64_t src2,
                             uint64_t dst,
                             uint64_t aux0,
                             uint64_t aux1,
                             uint32_t numeric,
                             uint32_t user_tag)
{
    wire_zero(wire, bytes);
    wire[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    wire[0x01u] = (uint8_t)engine;
    wire_put_u16(wire, 0x02u, (uint16_t)bytes);
    wire_put_u32(wire, 0x04u, op_flags);
    wire_put_u64(wire, 0x08u, src0);
    wire_put_u64(wire, 0x10u, src1);
    wire_put_u64(wire, 0x18u, src2);
    wire_put_u64(wire, 0x20u, dst);
    wire_put_u64(wire, 0x28u, aux0);
    wire_put_u64(wire, 0x30u, aux1);
    wire_put_u32(wire, 0x38u, numeric);
    wire_put_u32(wire, 0x3cu, user_tag);
}

static int wire_test_cmd_and_control(const npu_wire_limits_t *limits)
{
    uint8_t cmd_wire[NPU_WIRE_CMD_BYTES];
    uint8_t desc_wire[NPU_WIRE_CONTROL_DESC_BYTES];
    npu_cmd_t cmd;
    npu_task_request_t request;
    npu_wire_meta_t meta;
    uint64_t valid_low;
    uint64_t valid_high;
    static const npu_engine_t engines[NPU_ENGINE_COUNT] = {
        NPU_ENGINE_CONTROL,
        NPU_ENGINE_DMA,
        NPU_ENGINE_MATRIX,
        NPU_ENGINE_VECTOR,
        NPU_ENGINE_COMPLEX
    };
    static const uint8_t opcodes[NPU_ENGINE_COUNT] = {
        NPU_CTRL_NOP,
        NPU_DMA_COPY_1D,
        NPU_MATRIX_GEMM,
        NPU_VECTOR_ADD,
        NPU_COMPLEX_ACT
    };
    uint32_t index;
    uint16_t event0 = 0x103u;
    uint16_t event1 = 0x204u;
    uint16_t target = 0x305u;

    wire_make_cmd(cmd_wire, 0x400u, 0x345u,
                  NPU_ENGINE_CONTROL, NPU_CTRL_EVENT_JOIN,
                  (uint16_t)(7u << 6),
                  event0, event1, target);
    TEST_CHECK_STATUS(npu_wire_decode_cmd(cmd_wire,
                                          sizeof(cmd_wire),
                                          limits, &cmd),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(cmd.desc_addr == 0x400u);
    TEST_CHECK(cmd.command_id == 0x345u);
    TEST_CHECK(cmd.engine == NPU_ENGINE_CONTROL);
    TEST_CHECK(cmd.opcode == NPU_CTRL_EVENT_JOIN);
    TEST_CHECK(cmd.header_version == NPU_WIRE_HEADER_VERSION);
    TEST_CHECK(cmd.timeout_class == 7u);
    TEST_CHECK(cmd.wait_event[0].id == 3u);
    TEST_CHECK(cmd.wait_event[0].generation == 1u);
    TEST_CHECK(cmd.signal_event.id == 5u);

    wire_make_common(desc_wire, sizeof(desc_wire),
                     NPU_ENGINE_CONTROL, 2u << 8,
                     event0, event1, 0u, target,
                     0u, 0u, 0u, 0x78563412u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(request.cmd.user_tag == 0x78563412u);
    TEST_CHECK(request.desc.control.event0.id == 3u);
    TEST_CHECK(request.desc.control.event1.generation == 2u);
    TEST_CHECK(request.desc.control.target.generation == 3u);
    TEST_CHECK(request.desc.control.join_mode == 2u);
    TEST_CHECK(request.desc.control.engine_mask == 0u);
    TEST_CHECK(meta.control_join_mode == 2u);

    valid_high = wire_get_u64(cmd_wire, 8u);
    wire_put_u64(
        cmd_wire, 8u,
        valid_high | (UINT64_C(1) << (8u + 10u)));
    TEST_CHECK_STATUS(npu_wire_decode_cmd(cmd_wire,
                                          sizeof(cmd_wire),
                                          limits, &cmd),
                      NPU_STATUS_BAD_DESC);
    wire_put_u64(
        cmd_wire, 8u,
        valid_high | (UINT64_C(1) << (8u + 5u)));
    TEST_CHECK_STATUS(npu_wire_decode_cmd(cmd_wire,
                                          sizeof(cmd_wire),
                                          limits, &cmd),
                      NPU_STATUS_BAD_DESC);
    wire_put_u64(
        cmd_wire, 8u,
        (valid_high & ~(UINT64_C(0x0fff) << 20u)) |
            (UINT64_C(0x00ff) << 20u));
    TEST_CHECK_STATUS(npu_wire_decode_cmd(cmd_wire,
                                          sizeof(cmd_wire),
                                          limits, &cmd),
                      NPU_STATUS_BAD_DESC);
    wire_put_u64(cmd_wire, 8u, valid_high);

    wire_put_u64(
        cmd_wire, 8u,
        (valid_high & ~UINT64_C(0xff)) | UINT64_C(0x0f));
    TEST_CHECK_STATUS(npu_wire_decode_cmd(cmd_wire,
                                          sizeof(cmd_wire),
                                          limits, &cmd),
                      NPU_STATUS_ILLEGAL_OPCODE);

    for (index = 0u; index < NPU_ENGINE_COUNT; index++) {
        wire_make_cmd(cmd_wire, 0x400u,
                      (uint16_t)(0x380u + index),
                      engines[index], opcodes[index], 0u,
                      WIRE_NONE, WIRE_NONE, WIRE_NONE);
        TEST_CHECK_STATUS(npu_wire_decode_cmd(
                              cmd_wire, sizeof(cmd_wire),
                              limits, &cmd),
                          NPU_STATUS_SUCCESS);
        TEST_CHECK(cmd.engine == engines[index]);
        TEST_CHECK(cmd.opcode == opcodes[index]);
    }

    wire_make_cmd(cmd_wire, UINT64_C(0xffffffffffc0),
                  0x390u, NPU_ENGINE_CONTROL, NPU_CTRL_NOP,
                  0u, WIRE_NONE, WIRE_NONE, WIRE_NONE);
    TEST_CHECK_STATUS(npu_wire_decode_cmd(cmd_wire,
                                          sizeof(cmd_wire),
                                          limits, &cmd),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(cmd.desc_addr == UINT64_C(0xffffffffffc0));

    wire_make_cmd(cmd_wire, 0x400u, 0x391u,
                  NPU_ENGINE_CONTROL, NPU_CTRL_NOP,
                  (uint16_t)(0x1bu | (3u << 6u)),
                  event0, event1, target);
    valid_low = wire_get_u64(cmd_wire, 0u);
    valid_high = wire_get_u64(cmd_wire, 8u);
    TEST_CHECK((valid_low & UINT64_C(0x0000ffffffffffff)) ==
               0x400u);
    TEST_CHECK(((valid_low >> 48u) & 0x0fffu) == 0x391u);
    TEST_CHECK(((valid_low >> 60u) & 0x0fu) ==
               NPU_ENGINE_CONTROL);
    TEST_CHECK((valid_high & 0xffu) == NPU_CTRL_NOP);
    TEST_CHECK(((valid_high >> 8u) & 0x0fffu) ==
               (uint16_t)(0x1bu | (3u << 6u)));
    TEST_CHECK(((valid_high >> 20u) & 0x0fffu) == event0);
    TEST_CHECK(((valid_high >> 32u) & 0x0fffu) == event1);
    TEST_CHECK(((valid_high >> 44u) & 0x0fffu) == target);
    TEST_CHECK((valid_high >> 56u) == NPU_WIRE_HEADER_VERSION);
    return 0;
}

static int wire_test_dma(const npu_wire_limits_t *limits)
{
    uint8_t cmd_wire[NPU_WIRE_CMD_BYTES];
    uint8_t desc_wire[NPU_WIRE_DMA_DESC_BYTES];
    npu_task_request_t request;
    npu_wire_meta_t meta;
    uint32_t numeric = wire_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT32, NPU_ROUND_NEAREST_EVEN,
        0u, 0u, 0u, 0u);

    wire_make_cmd(cmd_wire, 0x800u, 1u,
                  NPU_ENGINE_DMA, NPU_DMA_COPY_ND,
                  0u, WIRE_NONE, WIRE_NONE, WIRE_NONE);
    wire_make_common(desc_wire, sizeof(desc_wire),
                     NPU_ENGINE_DMA, 1u,
                     0x2000u, 0u, 0u, 0x100u,
                     0u, 0u, numeric, 0x01020304u);
    desc_wire[0x40u] = 2u;
    desc_wire[0x41u] = NPU_SPACE_DDR;
    desc_wire[0x42u] = NPU_SPACE_L1;
    desc_wire[0x43u] = NPU_DMA_SIGN_EXTEND;
    desc_wire[0x44u] = 15u;
    desc_wire[0x45u] = 8u;
    wire_put_u32(desc_wire, 0x48u, 2u);
    wire_put_u32(desc_wire, 0x4cu, 3u);
    wire_put_u32(desc_wire, 0x60u, 3u);
    wire_put_u32(desc_wire, 0x78u, 12u);
    wire_put_u64(desc_wire, 0x98u, 6u);
    wire_put_u64(desc_wire, 0xa0u, 24u);

    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(request.desc.dma.rank == 2u);
    TEST_CHECK(request.desc.dma.shape[0] == 2u);
    TEST_CHECK(request.desc.dma.shape[1] == 3u);
    TEST_CHECK(request.desc.dma.src_stride_bytes[0] == 3u);
    TEST_CHECK(request.desc.dma.dst_stride_bytes[0] == 12u);
    TEST_CHECK(request.desc.dma.burst_beats == 16u);
    TEST_CHECK(meta.dma_burst_beats == 16u);

    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire) - 1u,
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);
    wire_put_u16(desc_wire, 0x02u,
                 NPU_WIRE_DMA_DESC_BYTES - 64u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);
    wire_put_u16(desc_wire, 0x02u,
                 NPU_WIRE_DMA_DESC_BYTES);

    desc_wire[0x5cu] = 1u;
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);
    desc_wire[0x5cu] = 0u;
    wire_put_u64(desc_wire, 0x20u,
                 UINT64_C(1) << 24);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_ADDR_FAULT);

    wire_make_cmd(cmd_wire, 0x800u, 5u,
                  NPU_ENGINE_DMA, NPU_DMA_FILL,
                  0u, WIRE_NONE, WIRE_NONE, WIRE_NONE);
    numeric = wire_numeric(
        NPU_DTYPE_INT4, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT4, NPU_ROUND_NEAREST_EVEN,
        0u, 0u, 0u, 0u);
    wire_make_common(desc_wire, sizeof(desc_wire),
                     NPU_ENGINE_DMA, 0u,
                     0u, 0u, 0u, 0x200u,
                     0u, 0u, numeric, 0x11223344u);
    desc_wire[0x40u] = 1u;
    desc_wire[0x41u] = NPU_SPACE_L1;
    desc_wire[0x42u] = NPU_SPACE_L1;
    desc_wire[0x43u] = NPU_DMA_CONVERT_NONE;
    desc_wire[0x44u] = 15u;
    desc_wire[0x45u] = 8u;
    wire_put_u32(desc_wire, 0x48u, 5u);
    wire_put_u64(desc_wire, 0x90u, 0x0du);
    wire_put_u64(desc_wire, 0x98u, 0u);
    wire_put_u64(desc_wire, 0xa0u, 3u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(request.desc.dma.fill_value == 0x0du);
    TEST_CHECK(request.desc.dma.shape[0] == 5u);

    wire_make_cmd(cmd_wire, 0x800u, 6u,
                  NPU_ENGINE_DMA, NPU_DMA_PACK,
                  0u, WIRE_NONE, WIRE_NONE, WIRE_NONE);
    numeric = wire_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        0u, 0u, 0u, 0u);
    wire_make_common(desc_wire, sizeof(desc_wire),
                     NPU_ENGINE_DMA, 0u,
                     0x300u, 0u, 0u, 0x400u,
                     0u, 0u, numeric, 0x5041434bu);
    desc_wire[0x40u] = 1u;
    desc_wire[0x41u] = NPU_SPACE_L1;
    desc_wire[0x42u] = NPU_SPACE_L1;
    desc_wire[0x43u] = NPU_DMA_CONVERT_NONE;
    desc_wire[0x44u] = 15u;
    desc_wire[0x45u] = 8u;
    wire_put_u32(desc_wire, 0x48u, 3u);
    wire_put_u64(desc_wire, 0x98u, 23u);
    wire_put_u64(desc_wire, 0xa0u, 15u);
    wire_put_u16(desc_wire, 0xa8u, 3u);
    wire_put_u16(desc_wire, 0xaau, 5u);
    wire_put_u32(desc_wire, 0xacu, 9u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(request.desc.dma.shape[0] == 3u);
    TEST_CHECK(request.desc.dma.segment_count == 3u);
    TEST_CHECK(request.desc.dma.segment_bytes == 5u);
    TEST_CHECK(request.desc.dma.segment_stride == 9u);

    wire_put_u32(desc_wire, 0x48u, 4u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_SHAPE);
    wire_put_u32(desc_wire, 0x48u, 3u);
    wire_put_u32(desc_wire, 0xacu, 4u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);
    wire_put_u32(desc_wire, 0xacu, 9u);

    wire_make_cmd(cmd_wire, 0x800u, 7u,
                  NPU_ENGINE_DMA, NPU_DMA_SPLIT,
                  0u, WIRE_NONE, WIRE_NONE, WIRE_NONE);
    wire_put_u64(desc_wire, 0x98u, 15u);
    wire_put_u64(desc_wire, 0xa0u, 23u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_SUCCESS);
    return 0;
}

static int wire_test_matrix(const npu_wire_limits_t *limits)
{
    uint8_t cmd_wire[NPU_WIRE_CMD_BYTES];
    uint8_t desc_wire[NPU_WIRE_MATRIX_DESC_BYTES];
    npu_task_request_t request;
    npu_wire_meta_t meta;
    uint32_t flags = (1u << 2) | (1u << 7);
    uint32_t numeric = wire_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8, NPU_DTYPE_INT4,
        NPU_DTYPE_INT32, NPU_ROUND_NEAREST_EVEN,
        0u, 0u, 0u, 0u);

    wire_make_cmd(cmd_wire, 0xc00u, 2u,
                  NPU_ENGINE_MATRIX, NPU_MATRIX_GEMM,
                  0u, WIRE_NONE, WIRE_NONE, WIRE_NONE);
    wire_make_common(desc_wire, sizeof(desc_wire),
                     NPU_ENGINE_MATRIX, 0u,
                     0x1000u, 0x2000u, 0u, 0x3000u,
                     0x4000u, 0u, numeric, 0xaabbccddu);
    wire_put_u32(desc_wire, 0x40u, 2u);
    wire_put_u32(desc_wire, 0x44u, 3u);
    wire_put_u32(desc_wire, 0x48u, 4u);
    wire_put_u32(desc_wire, 0x4cu, 1u);
    wire_put_u32(desc_wire, 0x50u, 2u);
    wire_put_u32(desc_wire, 0x54u, 3u);
    wire_put_u32(desc_wire, 0x58u, 4u);
    wire_put_u32(desc_wire, 0x5cu, flags);
    wire_put_u32(desc_wire, 0x60u, 4u);
    wire_put_u32(desc_wire, 0x64u, 0u);
    wire_put_u32(desc_wire, 0x68u, 12u);
    wire_put_u32(desc_wire, 0x6cu, 4u);
    desc_wire[0x90u] = 0u;
    desc_wire[0x91u] = 2u;
    desc_wire[0x92u] = 4u;
    desc_wire[0x93u] = 0u;
    desc_wire[0x94u] = NPU_OVERFLOW_SATURATE;
    desc_wire[0x95u] = 0u;
    wire_put_u32(desc_wire, 0x98u, 0u);
    wire_put_u32(desc_wire, 0x9cu, 0u);
    wire_put_u32(desc_wire, 0xa0u, 3u);
    desc_wire[0xa4u] = 0u;
    desc_wire[0xa5u] = 0u;
    desc_wire[0xa6u] = 8u;

    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(request.desc.matrix.m == 2u);
    TEST_CHECK(request.desc.matrix.n == 3u);
    TEST_CHECK(request.desc.matrix.k == 4u);
    TEST_CHECK(request.desc.matrix.bias_enable == 1u);
    TEST_CHECK(request.desc.matrix.bias_count == 3u);
    TEST_CHECK(request.desc.matrix.a.row_stride_bytes == 4u);
    TEST_CHECK(meta.matrix_last_tile_valid_n == 3u);
    TEST_CHECK(meta.matrix_b_pack_format == 2u);

    wire_put_u32(desc_wire, 0x50u, 1u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_SHAPE);
    wire_put_u32(desc_wire, 0x50u, 2u);
    wire_put_u32(desc_wire, 0x54u, 2u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_SHAPE);
    wire_put_u32(desc_wire, 0x54u, 3u);
    wire_put_u32(desc_wire, 0x58u, 3u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_SHAPE);
    wire_put_u32(desc_wire, 0x58u, 4u);
    desc_wire[0x96u] = 1u;
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);

    return 0;
}

static int wire_test_vector(const npu_wire_limits_t *limits)
{
    uint8_t cmd_wire[NPU_WIRE_CMD_BYTES];
    uint8_t desc_wire[NPU_WIRE_VECTOR_DESC_BYTES];
    npu_task_request_t request;
    npu_wire_meta_t meta;
    uint32_t numeric = wire_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        1u, 1u, 0u, 0u);

    wire_make_cmd(cmd_wire, 0x1000u, 3u,
                  NPU_ENGINE_VECTOR, NPU_VECTOR_ADD,
                  0u, WIRE_NONE, WIRE_NONE, WIRE_NONE);
    wire_make_common(desc_wire, sizeof(desc_wire),
                     NPU_ENGINE_VECTOR, 0u,
                     0x1000u, 0x1100u, 0u, 0x1200u,
                     0u, 0u, numeric, 0x55aa55aau);
    wire_put_u32(desc_wire, 0x40u, 2u);
    wire_put_u32(desc_wire, 0x44u, 4u);
    wire_put_u32(desc_wire, 0x48u, 4u);
    wire_put_u32(desc_wire, 0x50u, 1u);
    wire_put_u32(desc_wire, 0x54u, 4u);
    wire_put_u32(desc_wire, 0x58u, 1u);
    wire_put_u32(desc_wire, 0x5cu, 4u);
    wire_put_u32(desc_wire, 0x68u, 1u);
    wire_put_u32(desc_wire, 0x6cu, 4u);
    desc_wire[0x78u] = 0u;
    desc_wire[0x79u] = NPU_COMPARE_EQ;
    desc_wire[0x7au] = NPU_OVERFLOW_SATURATE;
    desc_wire[0x7bu] = 0u;
    wire_put_u32(desc_wire, 0x80u, 0x3f800000u);
    wire_put_u32(desc_wire, 0x84u, 0x3f800000u);
    wire_put_u32(desc_wire, 0x88u, 0u);
    wire_put_u32(desc_wire, 0x8cu, 0x3f800000u);

    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(request.desc.vector.rows == 2u);
    TEST_CHECK(request.desc.vector.length == 4u);
    TEST_CHECK(request.desc.vector.src0.elem_stride_bytes == 1u);
    TEST_CHECK(request.desc.vector.src1.row_stride_bytes == 4u);
    TEST_CHECK(request.desc.vector.dst_scale_bits == 0x3f800000u);

    wire_put_u32(desc_wire, 0x84u, 0x40000000u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);
    wire_put_u32(desc_wire, 0x84u, 0x3f800000u);
    desc_wire[0x7eu] = 1u;
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);
    desc_wire[0x7eu] = 0u;

    numeric = wire_numeric(
        NPU_DTYPE_INT32, NPU_DTYPE_INT32, NPU_DTYPE_INT4,
        NPU_DTYPE_INT32, NPU_ROUND_NEAREST_EVEN,
        1u, 1u, 0u, 0u);
    wire_put_u32(desc_wire, 0x38u, numeric);
    wire_put_u32(desc_wire, 0x50u, 4u);
    wire_put_u32(desc_wire, 0x54u, 16u);
    wire_put_u32(desc_wire, 0x58u, 4u);
    wire_put_u32(desc_wire, 0x5cu, 16u);
    wire_put_u32(desc_wire, 0x68u, 5u);
    wire_put_u32(desc_wire, 0x6cu, 20u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_SHAPE);

    return 0;
}

static int wire_test_complex(const npu_wire_limits_t *limits)
{
    uint8_t cmd_wire[NPU_WIRE_CMD_BYTES];
    uint8_t desc_wire[NPU_WIRE_COMPLEX_DESC_BYTES];
    npu_task_request_t request;
    npu_wire_meta_t meta;
    uint32_t numeric = wire_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        1u, 1u, 0u, 1u);

    wire_make_cmd(cmd_wire, 0x1400u, 4u,
                  NPU_ENGINE_COMPLEX, NPU_COMPLEX_ACT,
                  (uint16_t)(1u << 2),
                  WIRE_NONE, WIRE_NONE, WIRE_NONE);
    wire_make_common(desc_wire, sizeof(desc_wire),
                     NPU_ENGINE_COMPLEX, 0u,
                     0x1000u, 0u, 0u, 0x1100u,
                     0u, 0u, numeric, 0x12345678u);
    wire_put_u32(desc_wire, 0x40u, 2u);
    wire_put_u32(desc_wire, 0x44u, 4u);
    wire_put_u32(desc_wire, 0x48u, 4u);
    wire_put_u32(desc_wire, 0x4cu, NPU_FUNC_SIGMOID);
    wire_put_u32(desc_wire, 0x50u, 4u);
    wire_put_u32(desc_wire, 0x5cu, 4u);
    wire_put_u32(desc_wire, 0x6cu, NPU_MASK_NONE);
    wire_put_u32(desc_wire, 0x70u, 0x3f000000u);
    wire_put_u32(desc_wire, 0x7cu, 0x3c000000u);
    wire_put_u32(desc_wire, 0x94u, 0xc1800000u);
    wire_put_u32(desc_wire, 0x98u, 0x41800000u);
    desc_wire[0x9cu] = 0u;
    desc_wire[0x9du] = NPU_OVERFLOW_SATURATE;
    desc_wire[0x9eu] = NPU_ALL_MASK_WRITE_ZERO;
    desc_wire[0x9fu] = 0u;

    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(request.desc.complex.function == NPU_FUNC_SIGMOID);
    TEST_CHECK(request.desc.complex.rows == 2u);
    TEST_CHECK(request.desc.complex.length == 4u);
    TEST_CHECK(request.desc.complex.src0_scale == 0.5f);
    TEST_CHECK(request.desc.complex.dst_scale == 0.0078125f);
    TEST_CHECK(request.desc.complex.scale_mode ==
               NPU_SCALE_PER_TENSOR);
    TEST_CHECK(request.desc.complex.src0_scale_table_addr == 0u);
    TEST_CHECK(request.desc.complex.dst_scale_table_addr == 0u);
    TEST_CHECK(request.desc.complex.approx_mode == 0u);
    TEST_CHECK(request.desc.complex.stats_mode == 0u);
    TEST_CHECK(request.desc.complex.strict_numeric == 1u);
    TEST_CHECK(request.desc_bytes == NPU_WIRE_COMPLEX_DESC_BYTES);
    TEST_CHECK(request.desc_version == NPU_WIRE_DEFAULT_DESC_VERSION);
    TEST_CHECK(request.allow_inplace == 0u);
    TEST_CHECK(request.allow_partial_dest == 0u);
    TEST_CHECK(meta.cme_approx_mode == 0u);
    TEST_CHECK(meta.cme_stats_mode == 0u);

    wire_put_u32(desc_wire, 0x38u, numeric & ~(1u << 16));
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);
    wire_put_u32(desc_wire, 0x38u, numeric);
    desc_wire[0xadu] = 1u;
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);

    numeric = wire_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        1u, 3u, 0u, 1u);
    wire_make_common(desc_wire, sizeof(desc_wire),
                     NPU_ENGINE_COMPLEX, 0u,
                     0x1000u, 0u, 0u, 0x1100u,
                     0x1800u, 0x1900u, numeric, 0x87654321u);
    wire_put_u32(desc_wire, 0x40u, 2u);
    wire_put_u32(desc_wire, 0x44u, 4u);
    wire_put_u32(desc_wire, 0x48u, 4u);
    wire_put_u32(desc_wire, 0x4cu, NPU_FUNC_SIGMOID);
    wire_put_u32(desc_wire, 0x50u, 4u);
    wire_put_u32(desc_wire, 0x5cu, 4u);
    wire_put_u32(desc_wire, 0x6cu, NPU_MASK_NONE);
    wire_put_u32(desc_wire, 0x94u, 0xc1800000u);
    wire_put_u32(desc_wire, 0x98u, 0x41800000u);
    desc_wire[0x9du] = NPU_OVERFLOW_SATURATE;
    desc_wire[0x9eu] = NPU_ALL_MASK_WRITE_ZERO;
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(request.desc.complex.scale_mode ==
               NPU_SCALE_PER_FEATURE);
    TEST_CHECK(request.desc.complex.src0_scale == 0.0f);
    TEST_CHECK(request.desc.complex.dst_scale == 0.0f);
    TEST_CHECK(request.desc.complex.src0_scale_table_addr == 0x1800u);
    TEST_CHECK(request.desc.complex.dst_scale_table_addr == 0x1900u);
    TEST_CHECK(meta.cme_src0_scale_table_addr == 0x1800u);
    TEST_CHECK(meta.cme_dst_scale_table_addr == 0x1900u);

    wire_put_u32(desc_wire, 0x70u, 0x3f800000u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);
    wire_put_u32(desc_wire, 0x70u, 0u);
    wire_put_u64(desc_wire, 0x28u,
                 (uint64_t)limits->l1_bytes - 8u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_ADDR_FAULT);
    wire_put_u64(desc_wire, 0x28u, 0x1800u);
    wire_put_u64(desc_wire, 0x30u, 0x1901u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);
    wire_put_u64(desc_wire, 0x30u, 0x1900u);
    desc_wire[0x9fu] = 1u;
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);

    numeric = wire_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        1u, 1u, 0u, 1u);
    wire_put_u32(desc_wire, 0x04u, (1u << 6) | (1u << 7));
    wire_put_u64(desc_wire, 0x20u, 0x1000u);
    wire_put_u64(desc_wire, 0x28u, 0u);
    wire_put_u64(desc_wire, 0x30u, 0u);
    wire_put_u32(desc_wire, 0x38u, numeric);
    wire_put_u32(desc_wire, 0x70u, 0x3f000000u);
    wire_put_u32(desc_wire, 0x7cu, 0x3c000000u);
    desc_wire[0x9fu] = 0u;
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_SUCCESS);
    TEST_CHECK(request.allow_inplace == 1u);
    TEST_CHECK(request.allow_partial_dest == 1u);
    TEST_CHECK(meta.allow_inplace == 1u);
    TEST_CHECK(meta.allow_partial_dest == 1u);

    wire_put_u32(desc_wire, 0x04u, 1u << 7);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          desc_wire, sizeof(desc_wire),
                          limits, &request, &meta),
                      NPU_STATUS_BAD_DESC);
    return 0;
}

static int wire_test_fault_metadata(void)
{
    uint8_t cmd_wire[NPU_WIRE_CMD_BYTES];
    uint8_t vector_wire[NPU_WIRE_VECTOR_DESC_BYTES];
    uint8_t dma_wire[NPU_WIRE_DMA_DESC_BYTES];
    npu_wire_limits_t limits;
    npu_task_request_t request;
    npu_wire_meta_t meta;
    npu_cmd_t cmd;
    uint32_t numeric;
    uint32_t dimension;

    npu_wire_limits_reference(&limits);
    limits.gaddr_limit = 0x1100u;
    wire_make_cmd(cmd_wire, 0x1080u, 0x301u,
                  NPU_ENGINE_VECTOR, NPU_VECTOR_ADD,
                  0u, WIRE_NONE, WIRE_NONE, WIRE_NONE);
    TEST_CHECK_STATUS(npu_wire_decode_cmd_with_meta(
                          cmd_wire, sizeof(cmd_wire),
                          &limits, &cmd, &meta),
                      NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(meta.fault_valid == 1u);
    TEST_CHECK(meta.fault_space == NPU_SPACE_DDR);
    TEST_CHECK(meta.fault_addr == 0x1100u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          vector_wire, sizeof(vector_wire),
                          &limits, &request, &meta),
                      NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(meta.fault_valid == 1u);
    TEST_CHECK(meta.fault_space == NPU_SPACE_DDR);
    TEST_CHECK(meta.fault_addr == 0x1100u);

    npu_wire_limits_reference(&limits);
    limits.l1_bytes = 0x1000u;
    limits.gaddr_limit = 0x2000u;
    wire_make_cmd(cmd_wire, 0x0200u, 0x302u,
                  NPU_ENGINE_VECTOR, NPU_VECTOR_ADD,
                  0u, WIRE_NONE, WIRE_NONE, WIRE_NONE);
    numeric = wire_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        1u, 1u, 0u, 0u);
    wire_make_common(vector_wire, sizeof(vector_wire),
                     NPU_ENGINE_VECTOR, 0u,
                     0x0100u, 0x0200u, 0u, 0x0ffcu,
                     0u, 0u, numeric, 0u);
    wire_put_u32(vector_wire, 0x40u, 1u);
    wire_put_u32(vector_wire, 0x44u, 8u);
    wire_put_u32(vector_wire, 0x48u, 8u);
    wire_put_u32(vector_wire, 0x50u, 1u);
    wire_put_u32(vector_wire, 0x54u, 8u);
    wire_put_u32(vector_wire, 0x58u, 1u);
    wire_put_u32(vector_wire, 0x5cu, 8u);
    wire_put_u32(vector_wire, 0x68u, 1u);
    wire_put_u32(vector_wire, 0x6cu, 8u);
    vector_wire[0x79u] = NPU_COMPARE_EQ;
    vector_wire[0x7au] = NPU_OVERFLOW_SATURATE;
    wire_put_u32(vector_wire, 0x80u, 0x3f800000u);
    wire_put_u32(vector_wire, 0x84u, 0x3f800000u);
    wire_put_u32(vector_wire, 0x8cu, 0x3f800000u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          vector_wire, sizeof(vector_wire),
                          &limits, &request, &meta),
                      NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(meta.fault_valid == 1u);
    TEST_CHECK(meta.fault_space == NPU_SPACE_L1);
    TEST_CHECK(meta.fault_addr == 0x1000u);

    limits.gaddr_limit = 0x1000u;
    wire_make_cmd(cmd_wire, 0x0200u, 0x303u,
                  NPU_ENGINE_DMA, NPU_DMA_COPY_ND,
                  0u, WIRE_NONE, WIRE_NONE, WIRE_NONE);
    numeric = wire_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT8, NPU_ROUND_NEAREST_EVEN,
        0u, 0u, 0u, 0u);
    wire_make_common(dma_wire, sizeof(dma_wire),
                     NPU_ENGINE_DMA, 1u,
                     0x0ffcu, 0u, 0u, 0x0100u,
                     0u, 0u, numeric, 0u);
    dma_wire[0x40u] = 1u;
    dma_wire[0x41u] = NPU_SPACE_DDR;
    dma_wire[0x42u] = NPU_SPACE_L1;
    dma_wire[0x43u] = NPU_DMA_CONVERT_NONE;
    dma_wire[0x44u] = NPU_REF_DMA_MAX_BURST_BEATS - 1u;
    dma_wire[0x45u] = NPU_REF_DMA_OUTSTANDING;
    wire_put_u32(dma_wire, 0x48u, 8u);
    wire_put_u64(dma_wire, 0x98u, 8u);
    wire_put_u64(dma_wire, 0xa0u, 8u);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          dma_wire, sizeof(dma_wire),
                          &limits, &request, &meta),
                      NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(meta.fault_valid == 1u);
    TEST_CHECK(meta.fault_space == NPU_SPACE_DDR);
    TEST_CHECK(meta.fault_addr == 0x1000u);

    wire_put_u64(dma_wire, 0x08u, 0x0100u);
    dma_wire[0x40u] = NPU_MAX_DMA_RANK;
    for (dimension = 0u; dimension < NPU_MAX_DMA_RANK; dimension++) {
        wire_put_u32(dma_wire, 0x48u + dimension * 4u,
                     UINT32_MAX);
        wire_put_u32(dma_wire, 0x60u + dimension * 4u,
                     dimension + 1u == NPU_MAX_DMA_RANK
                         ? 0u
                         : UINT32_MAX);
        wire_put_u32(dma_wire, 0x78u + dimension * 4u,
                     dimension + 1u == NPU_MAX_DMA_RANK
                         ? 0u
                         : UINT32_MAX);
    }
    wire_put_u64(dma_wire, 0x98u, UINT64_MAX);
    wire_put_u64(dma_wire, 0xa0u, UINT64_MAX);
    TEST_CHECK_STATUS(npu_wire_decode_task(
                          cmd_wire, sizeof(cmd_wire),
                          dma_wire, sizeof(dma_wire),
                          &limits, &request, &meta),
                      NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(meta.fault_valid == 1u);
    TEST_CHECK(meta.fault_space == NPU_SPACE_DDR);
    TEST_CHECK(meta.fault_addr == limits.gaddr_limit);
    return 0;
}

int test_wire(void)
{
    npu_wire_limits_t limits;
    int line;

    npu_wire_limits_reference(&limits);
    line = wire_test_cmd_and_control(&limits);
    if (line != 0) {
        return line;
    }
    line = wire_test_dma(&limits);
    if (line != 0) {
        return line;
    }
    line = wire_test_matrix(&limits);
    if (line != 0) {
        return line;
    }
    line = wire_test_vector(&limits);
    if (line != 0) {
        return line;
    }
    line = wire_test_complex(&limits);
    if (line != 0) {
        return line;
    }
    return wire_test_fault_metadata();
}

#if defined(NPU_WIRE_STANDALONE)
int main(void)
{
    return test_wire();
}
#endif
