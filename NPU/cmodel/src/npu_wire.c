#include "npu_wire.h"
#include "npu_inline.h"

#include <limits.h>

#define NPU_WIRE_EVENT_NONE 0x0fffu

#define NPU_WIRE_FLAG_IRQ_ON_SUCCESS (1u << 0)
#define NPU_WIRE_FLAG_IRQ_ON_ERROR (1u << 1)
#define NPU_WIRE_FLAG_STRICT_NUMERIC (1u << 2)
#define NPU_WIRE_FLAG_TRACE_ENABLE (1u << 3)
#define NPU_WIRE_FLAG_ORDERED (1u << 4)
#define NPU_WIRE_FLAG_DESC_CRC_ENABLE (1u << 5)
#define NPU_WIRE_FLAG_TIMEOUT_MASK (0x0fu << 6)
#define NPU_WIRE_FLAG_ALLOWED                                                \
    (NPU_WIRE_FLAG_IRQ_ON_SUCCESS | NPU_WIRE_FLAG_IRQ_ON_ERROR |            \
     NPU_WIRE_FLAG_STRICT_NUMERIC | NPU_WIRE_FLAG_TRACE_ENABLE |            \
     NPU_WIRE_FLAG_ORDERED | NPU_WIRE_FLAG_DESC_CRC_ENABLE |                \
     NPU_WIRE_FLAG_TIMEOUT_MASK)

#define NPU_WIRE_OP_SRC0_GADDR (1u << 0)
#define NPU_WIRE_OP_SRC1_GADDR (1u << 1)
#define NPU_WIRE_OP_SRC2_GADDR (1u << 2)
#define NPU_WIRE_OP_DST_GADDR (1u << 3)
#define NPU_WIRE_OP_AUX0_GADDR (1u << 4)
#define NPU_WIRE_OP_AUX1_GADDR (1u << 5)
#define NPU_WIRE_OP_ALLOW_INPLACE (1u << 6)
#define NPU_WIRE_OP_ALLOW_PARTIAL_DEST (1u << 7)
#define NPU_WIRE_OP_ALLOWED 0x000000ffu

#define NPU_WIRE_MATRIX_A_TRANSPOSE (1u << 0)
#define NPU_WIRE_MATRIX_B_TRANSPOSE (1u << 1)
#define NPU_WIRE_MATRIX_BIAS (1u << 2)
#define NPU_WIRE_MATRIX_RESIDUAL (1u << 3)
#define NPU_WIRE_MATRIX_RELU (1u << 4)
#define NPU_WIRE_MATRIX_REQUANT (1u << 5)
#define NPU_WIRE_MATRIX_ACCUM_SRC2 (1u << 6)
#define NPU_WIRE_MATRIX_FINAL (1u << 7)

/*
 * Matrix pack-format codes are layout codes, not dtype enum values.  Codes
 * Codes 0..4 cover the original integer layouts. INT16 uses two unused codes:
 * linear tensors use 5 and KT-by-NT tiled weights use 6.
 */
#define NPU_WIRE_MATRIX_PACK_LINEAR_INT8 0u
#define NPU_WIRE_MATRIX_PACK_LINEAR_INT4 1u
#define NPU_WIRE_MATRIX_PACK_TILED_INT8 2u
#define NPU_WIRE_MATRIX_PACK_TILED_INT4 3u
#define NPU_WIRE_MATRIX_PACK_LINEAR_INT32 4u
#define NPU_WIRE_MATRIX_PACK_LINEAR_INT16 5u
#define NPU_WIRE_MATRIX_PACK_TILED_INT16 6u

#define NPU_WIRE_VECTOR_MASK (1u << 0)
#define NPU_WIRE_VECTOR_MASK_KEEP (1u << 1)
#define NPU_WIRE_VECTOR_SRC1_SCALAR (1u << 2)
#define NPU_WIRE_VECTOR_SRC2_SCALAR (1u << 3)

typedef union {
    uint32_t bits;
    float value;
} npu_wire_float_bits_t;

typedef struct {
    uint8_t desc_version;
    uint8_t desc_type;
    uint16_t desc_bytes;
    uint32_t op_flags;
    uint64_t src0_addr;
    uint64_t src1_addr;
    uint64_t src2_addr;
    uint64_t dst_addr;
    uint64_t aux0_addr;
    uint64_t aux1_addr;
    uint32_t numeric_cfg;
    uint32_t user_tag;
    npu_dtype_t src0_dtype;
    npu_dtype_t src1_dtype;
    npu_dtype_t src2_dtype;
    npu_dtype_t dst_dtype;
    npu_round_mode_t round_mode;
    uint8_t saturate_enable;
    uint8_t scale_mode;
    uint8_t zero_point_enable;
    uint8_t internal_fp32_enable;
} npu_wire_common_t;

static uint16_t npu_wire_u16(const uint8_t *wire, size_t offset)
{
    return (uint16_t)wire[offset] |
           (uint16_t)((uint16_t)wire[offset + 1u] << 8);
}

static uint32_t npu_wire_u32(const uint8_t *wire, size_t offset)
{
    return (uint32_t)wire[offset] |
           ((uint32_t)wire[offset + 1u] << 8) |
           ((uint32_t)wire[offset + 2u] << 16) |
           ((uint32_t)wire[offset + 3u] << 24);
}

static uint64_t npu_wire_u64(const uint8_t *wire, size_t offset)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        value |= (uint64_t)wire[offset + byte] << (byte * 8u);
    }
    return value;
}

static int32_t npu_wire_i32(const uint8_t *wire, size_t offset)
{
    uint32_t value = npu_wire_u32(wire, offset);

    if (value <= 0x7fffffffu) {
        return (int32_t)value;
    }
    return -1 - (int32_t)(0xffffffffu - value);
}

static int npu_wire_zero_range(const uint8_t *wire,
                               size_t first,
                               size_t end)
{
    size_t offset;

    for (offset = first; offset < end; offset++) {
        if (wire[offset] != 0u) {
            return 0;
        }
    }
    return 1;
}

static void npu_wire_clear(void *object, size_t bytes)
{
    uint8_t *data = (uint8_t *)object;
    size_t offset;

    for (offset = 0u; offset < bytes; offset++) {
        data[offset] = 0u;
    }
}

static int npu_wire_add_u64(uint64_t left,
                            uint64_t right,
                            uint64_t *result)
{
    if (UINT64_MAX - left < right) {
        return 0;
    }
    *result = left + right;
    return 1;
}

static int npu_wire_mul_u64(uint64_t left,
                            uint64_t right,
                            uint64_t *result)
{
    if (left != 0u && right > UINT64_MAX / left) {
        return 0;
    }
    *result = left * right;
    return 1;
}

static int npu_wire_ranges_overlap(uint64_t addr0,
                                   uint64_t bytes0,
                                   uint64_t addr1,
                                   uint64_t bytes1)
{
    if (bytes0 == 0u || bytes1 == 0u) {
        return 0;
    }
    if (addr0 <= addr1) {
        return addr1 - addr0 < bytes0;
    }
    return addr0 - addr1 < bytes1;
}

static int npu_wire_event_decode(uint16_t raw, npu_event_ref_t *event)
{
    uint8_t id = (uint8_t)(raw & 0xffu);
    uint8_t generation = (uint8_t)((raw >> 8) & 0x0fu);

    if (id == NPU_EVENT_NONE_ID && raw != NPU_WIRE_EVENT_NONE) {
        return 0;
    }
    event->id = id;
    event->generation = generation;
    return 1;
}

static int npu_wire_event_is_none(npu_event_ref_t event)
{
    return event.id == NPU_EVENT_NONE_ID &&
           event.generation == NPU_EVENT_NONE_GENERATION;
}

static int npu_wire_event_equal(npu_event_ref_t left,
                                npu_event_ref_t right)
{
    return left.id == right.id && left.generation == right.generation;
}

static npu_event_ref_t npu_wire_inline_event(uint8_t raw)
{
    npu_event_ref_t event;

    event.id = raw;
    event.generation =
        raw == NPU_EVENT_NONE_ID ? NPU_EVENT_NONE_GENERATION : 0u;
    return event;
}

static int npu_wire_opcode_valid(npu_engine_t engine, uint8_t opcode)
{
    if (engine == NPU_ENGINE_CONTROL) {
        return opcode == NPU_CTRL_NOP ||
               opcode == NPU_CTRL_EVENT_SIGNAL ||
               opcode == NPU_CTRL_EVENT_REARM ||
               opcode == NPU_CTRL_EVENT_JOIN ||
               opcode == NPU_CTRL_GLOBAL_FENCE;
    }
    if (engine == NPU_ENGINE_DMA) {
        return opcode == NPU_DMA_COPY_1D ||
               opcode == NPU_DMA_COPY_ND ||
               opcode == NPU_DMA_FILL ||
               opcode == NPU_DMA_TRANSPOSE_2D ||
               opcode == NPU_DMA_PACK ||
               opcode == NPU_DMA_SPLIT;
    }
    if (engine == NPU_ENGINE_MATRIX) {
        return opcode == NPU_MATRIX_GEMM ||
               opcode == NPU_MATRIX_BMM ||
               opcode == NPU_MATRIX_GEMM_ACCUM ||
               opcode == NPU_MATRIX_GEMM_ZERO;
    }
    if (engine == NPU_ENGINE_VECTOR) {
        return opcode >= NPU_VECTOR_ADD && opcode <= NPU_VECTOR_RELU;
    }
    if (engine == NPU_ENGINE_COMPLEX) {
        return opcode == NPU_COMPLEX_ACT ||
               opcode == NPU_COMPLEX_SOFTMAX ||
               opcode == NPU_COMPLEX_NORM ||
               opcode == NPU_COMPLEX_STAT ||
               opcode == NPU_COMPLEX_ADD_RESCALE;
    }
    return 0;
}

static int npu_wire_limits_valid(const npu_wire_limits_t *limits)
{
    uint32_t index;

    if (limits == (const npu_wire_limits_t *)0 ||
        limits->l1_bytes == 0u ||
        limits->l1_bytes > (1u << 24) ||
        limits->gaddr_limit == 0u ||
        limits->gaddr_limit > (UINT64_C(1) << 40) ||
        limits->dma_max_burst_beats == 0u ||
        limits->dma_max_burst_beats > 256u ||
        limits->dma_max_outstanding == 0u ||
        limits->mt == 0u ||
        limits->kt == 0u ||
        limits->nt == 0u ||
        limits->cme_scratch_elems == 0u ||
        limits->desc_version == 0u) {
        return 0;
    }
    for (index = 0u; index < 6u; index++) {
        if (limits->gaddr_base[index] >= limits->gaddr_limit) {
            return 0;
        }
    }
    return 1;
}

void npu_wire_limits_reference(npu_wire_limits_t *limits)
{
    if (limits == (npu_wire_limits_t *)0) {
        return;
    }
    npu_wire_clear(limits, sizeof(*limits));
    limits->l1_bytes = NPU_REF_L1_BYTES;
    limits->gaddr_limit = UINT64_C(1) << 40;
    limits->dma_max_burst_beats = NPU_REF_DMA_MAX_BURST_BEATS;
    limits->dma_max_outstanding = NPU_REF_DMA_OUTSTANDING;
    limits->mt = NPU_REF_MT;
    limits->kt = NPU_REF_KT;
    limits->nt = NPU_REF_NT;
    limits->cme_scratch_elems = NPU_REF_CME_SCRATCH_ELEMS;
    limits->desc_version = NPU_WIRE_DEFAULT_DESC_VERSION;
}

size_t npu_wire_descriptor_bytes(npu_engine_t engine)
{
    if (engine == NPU_ENGINE_CONTROL) {
        return NPU_WIRE_CONTROL_DESC_BYTES;
    }
    if (engine == NPU_ENGINE_DMA) {
        return NPU_WIRE_DMA_DESC_BYTES;
    }
    if (engine == NPU_ENGINE_MATRIX) {
        return NPU_WIRE_MATRIX_DESC_BYTES;
    }
    if (engine == NPU_ENGINE_VECTOR) {
        return NPU_WIRE_VECTOR_DESC_BYTES;
    }
    if (engine == NPU_ENGINE_COMPLEX) {
        return NPU_WIRE_COMPLEX_DESC_BYTES;
    }
    return 0u;
}

static int npu_wire_address_valid(npu_space_t space,
                                  uint64_t address,
                                  uint64_t bytes,
                                  const npu_wire_limits_t *limits)
{
    uint64_t limit;

    if (space == NPU_SPACE_L1) {
        if ((address >> 24) != 0u) {
            return 0;
        }
        limit = limits->l1_bytes;
    } else if (space == NPU_SPACE_DDR) {
        if ((address >> 40) != 0u) {
            return 0;
        }
        limit = limits->gaddr_limit;
    } else {
        return 0;
    }
    if (address > limit) {
        return 0;
    }
    return bytes <= limit - address;
}

static uint64_t npu_wire_space_limit(
    npu_space_t space,
    const npu_wire_limits_t *limits)
{
    return space == NPU_SPACE_L1
               ? limits->l1_bytes
               : limits->gaddr_limit;
}

static void npu_wire_record_fault(npu_wire_meta_t *meta,
                                  npu_space_t space,
                                  uint64_t address)
{
    if (meta == (npu_wire_meta_t *)0 ||
        meta->fault_valid != 0u) {
        return;
    }
    meta->fault_valid = 1u;
    meta->fault_space = space;
    meta->fault_addr = address;
}

static uint64_t npu_wire_first_invalid_address(
    npu_space_t space,
    uint64_t address,
    uint64_t bytes,
    const npu_wire_limits_t *limits)
{
    uint64_t limit = npu_wire_space_limit(space, limits);

    if ((space == NPU_SPACE_L1 && (address >> 24u) != 0u) ||
        (space == NPU_SPACE_DDR && (address >> 40u) != 0u) ||
        address > limit) {
        return address;
    }
    if (bytes > limit - address) {
        return limit;
    }
    return address;
}

static npu_status_t npu_wire_check_address(
    npu_space_t space,
    uint64_t address,
    uint64_t bytes,
    const npu_wire_limits_t *limits,
    npu_wire_meta_t *meta)
{
    if (npu_wire_address_valid(space, address, bytes, limits)) {
        return NPU_STATUS_SUCCESS;
    }
    npu_wire_record_fault(
        meta, space,
        npu_wire_first_invalid_address(
            space, address, bytes, limits));
    return NPU_STATUS_ADDR_FAULT;
}

static void npu_wire_record_unbounded_span_fault(
    npu_wire_meta_t *meta,
    npu_space_t space,
    uint64_t address,
    const npu_wire_limits_t *limits)
{
    uint64_t limit = npu_wire_space_limit(space, limits);

    if ((space == NPU_SPACE_L1 && (address >> 24u) != 0u) ||
        (space == NPU_SPACE_DDR && (address >> 40u) != 0u) ||
        address > limit) {
        npu_wire_record_fault(meta, space, address);
    } else {
        npu_wire_record_fault(meta, space, limit);
    }
}

static void npu_wire_record_region_fault(
    npu_wire_meta_t *meta,
    npu_space_t space,
    uint64_t address,
    uint64_t region_bytes,
    const npu_wire_limits_t *limits)
{
    uint64_t limit = npu_wire_space_limit(space, limits);
    uint64_t available;
    uint64_t offset;

    if ((space == NPU_SPACE_L1 && (address >> 24u) != 0u) ||
        (space == NPU_SPACE_DDR && (address >> 40u) != 0u) ||
        address > limit) {
        npu_wire_record_fault(meta, space, address);
        return;
    }
    available = limit - address;
    offset = region_bytes < available ? region_bytes : available;
    npu_wire_record_fault(meta, space, address + offset);
}

static int npu_wire_dtype_valid(npu_dtype_t dtype)
{
    return dtype == NPU_DTYPE_INT4 ||
           dtype == NPU_DTYPE_INT8 ||
           dtype == NPU_DTYPE_INT16 ||
           dtype == NPU_DTYPE_INT32;
}

static uint32_t npu_wire_dtype_bits(npu_dtype_t dtype)
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
    if (dtype == NPU_DTYPE_INT32) {
        return 32u;
    }
    return 0u;
}

static uint32_t npu_wire_dtype_bytes(npu_dtype_t dtype)
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

static int npu_wire_dtype_code(uint32_t numeric_cfg,
                               uint32_t shift,
                               npu_dtype_t *dtype)
{
    uint32_t code = (numeric_cfg >> shift) & 0x03u;

    if (!npu_wire_dtype_valid((npu_dtype_t)code)) {
        return 0;
    }
    *dtype = (npu_dtype_t)code;
    return 1;
}

npu_status_t npu_wire_validate_cmd_address(
    const npu_cmd_t *cmd,
    const npu_wire_limits_t *limits,
    npu_wire_meta_t *meta)
{
    size_t desc_bytes;

    if (meta == (npu_wire_meta_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    npu_wire_clear(meta, sizeof(*meta));
    if (cmd == (const npu_cmd_t *)0 ||
        !npu_wire_limits_valid(limits)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (cmd->inline_format != 0u) {
        return NPU_STATUS_SUCCESS;
    }
    desc_bytes = npu_wire_descriptor_bytes(cmd->engine);
    if (desc_bytes == 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    return npu_wire_check_address(
        NPU_SPACE_DDR, cmd->desc_addr,
        desc_bytes, limits, meta);
}

npu_status_t npu_wire_decode_cmd_with_meta(
    const uint8_t *wire,
    size_t wire_bytes,
    const npu_wire_limits_t *limits,
    npu_cmd_t *cmd,
    npu_wire_meta_t *meta)
{
    uint64_t low;
    uint64_t high;
    uint8_t opcode_field;
    uint8_t packed_flags;

    if (wire == (const uint8_t *)0 ||
        cmd == (npu_cmd_t *)0 ||
        meta == (npu_wire_meta_t *)0 ||
        wire_bytes != NPU_WIRE_CMD_BYTES ||
        !npu_wire_limits_valid(limits)) {
        return NPU_STATUS_BAD_DESC;
    }
    npu_wire_clear(cmd, sizeof(*cmd));
    npu_wire_clear(meta, sizeof(*meta));
    low = npu_wire_u64(wire, 0u);
    high = npu_wire_u64(wire, 8u);

    opcode_field =
        (uint8_t)((high >> 58u) & UINT64_C(0x3f));
    packed_flags =
        (uint8_t)((high >> 20u) & UINT64_C(0x0f));

    cmd->inline_payload_lo = low;
    cmd->inline_payload_hi =
        (uint16_t)(high & UINT64_C(0xffff));
    cmd->inline_format = 1u;
    cmd->inline_dtype =
        (npu_dtype_t)((high >> 16u) & UINT64_C(0x03));
    cmd->timeout_class =
        (uint8_t)((high >> 18u) & UINT64_C(0x03));
    cmd->header_flags =
        (uint16_t)(((packed_flags >> 3u) & 0x01u) |
                   (((packed_flags >> 2u) & 0x01u) << 1u) |
                   (((packed_flags >> 1u) & 0x01u) << 2u) |
                   ((packed_flags & 0x01u) << 4u) |
                   ((uint16_t)cmd->timeout_class << 6u));
    cmd->signal_event = npu_wire_inline_event(
        (uint8_t)((high >> 24u) & UINT64_C(0xff)));
    cmd->wait_event[1] = npu_wire_inline_event(
        (uint8_t)((high >> 32u) & UINT64_C(0xff)));
    cmd->wait_event[0] = npu_wire_inline_event(
        (uint8_t)((high >> 40u) & UINT64_C(0xff)));
    cmd->command_id =
        (uint16_t)((high >> 48u) & UINT64_C(0x03ff));
    if (!npu_wire_dtype_valid(cmd->inline_dtype)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (!npu_inline_opcode_decode(
            opcode_field, &cmd->engine, &cmd->opcode)) {
        return NPU_STATUS_ILLEGAL_OPCODE;
    }
    if (!npu_wire_event_is_none(cmd->signal_event) &&
        (npu_wire_event_equal(cmd->signal_event, cmd->wait_event[0]) ||
         npu_wire_event_equal(cmd->signal_event, cmd->wait_event[1]))) {
        return NPU_STATUS_BAD_DESC;
    }
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_wire_decode_cmd(const uint8_t *wire,
                                 size_t wire_bytes,
                                 const npu_wire_limits_t *limits,
                                 npu_cmd_t *cmd)
{
    npu_wire_meta_t meta;

    return npu_wire_decode_cmd_with_meta(
        wire, wire_bytes, limits, cmd, &meta);
}

static npu_status_t npu_wire_decode_common(
    const npu_cmd_t *cmd,
    const uint8_t *wire,
    size_t wire_bytes,
    const npu_wire_limits_t *limits,
    npu_wire_common_t *common,
    npu_wire_meta_t *meta)
{
    size_t expected = npu_wire_descriptor_bytes(cmd->engine);

    if (wire_bytes != expected || expected == 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    npu_wire_clear(common, sizeof(*common));
    common->desc_version = wire[0x00u];
    common->desc_type = wire[0x01u];
    common->desc_bytes = npu_wire_u16(wire, 0x02u);
    common->op_flags = npu_wire_u32(wire, 0x04u);
    common->src0_addr = npu_wire_u64(wire, 0x08u);
    common->src1_addr = npu_wire_u64(wire, 0x10u);
    common->src2_addr = npu_wire_u64(wire, 0x18u);
    common->dst_addr = npu_wire_u64(wire, 0x20u);
    common->aux0_addr = npu_wire_u64(wire, 0x28u);
    common->aux1_addr = npu_wire_u64(wire, 0x30u);
    common->numeric_cfg = npu_wire_u32(wire, 0x38u);
    common->user_tag = npu_wire_u32(wire, 0x3cu);

    if (common->desc_version != limits->desc_version ||
        common->desc_type != (uint8_t)cmd->engine ||
        common->desc_bytes != expected ||
        (common->numeric_cfg & 0xfffe0000u) != 0u ||
        ((common->numeric_cfg >> 8) & 0x03u) != 0u ||
        !npu_wire_dtype_code(common->numeric_cfg, 0u,
                             &common->src0_dtype) ||
        !npu_wire_dtype_code(common->numeric_cfg, 2u,
                             &common->src1_dtype) ||
        !npu_wire_dtype_code(common->numeric_cfg, 4u,
                             &common->src2_dtype) ||
        !npu_wire_dtype_code(common->numeric_cfg, 6u,
                             &common->dst_dtype)) {
        return NPU_STATUS_BAD_DESC;
    }
    common->round_mode =
        (npu_round_mode_t)((common->numeric_cfg >> 10) & 0x03u);
    common->saturate_enable =
        (uint8_t)((common->numeric_cfg >> 12) & 0x01u);
    common->scale_mode =
        (uint8_t)((common->numeric_cfg >> 13) & 0x03u);
    common->zero_point_enable =
        (uint8_t)((common->numeric_cfg >> 15) & 0x01u);
    common->internal_fp32_enable =
        (uint8_t)((common->numeric_cfg >> 16) & 0x01u);

    if (cmd->engine != NPU_ENGINE_CONTROL &&
        (common->op_flags & ~NPU_WIRE_OP_ALLOWED) != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    meta->desc_version = common->desc_version;
    meta->desc_type = common->desc_type;
    meta->desc_bytes = common->desc_bytes;
    meta->op_flags = common->op_flags;
    meta->numeric_cfg = common->numeric_cfg;
    meta->allow_inplace =
        (uint8_t)((common->op_flags & NPU_WIRE_OP_ALLOW_INPLACE) != 0u);
    meta->allow_partial_dest =
        (uint8_t)((common->op_flags &
                   NPU_WIRE_OP_ALLOW_PARTIAL_DEST) != 0u);
    meta->saturate_enable = common->saturate_enable;
    meta->scale_mode = common->scale_mode;
    meta->zero_point_enable = common->zero_point_enable;
    meta->internal_fp32_enable = common->internal_fp32_enable;
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_wire_decode_control(
    const npu_cmd_t *cmd,
    const npu_wire_common_t *common,
    npu_task_request_t *request,
    npu_wire_meta_t *meta)
{
    uint8_t join_mode = (uint8_t)((common->op_flags >> 8) & 0x03u);
    uint8_t engine_mask = (uint8_t)(common->aux0_addr & 0x0fu);
    npu_event_ref_t event0;
    npu_event_ref_t event1;
    npu_event_ref_t target;

    if (common->numeric_cfg != 0u ||
        (common->op_flags & 0xfffff0ffu) != 0u ||
        (common->src0_addr >> 12) != 0u ||
        (common->src1_addr >> 12) != 0u ||
        common->src2_addr != 0u ||
        (common->dst_addr >> 12) != 0u ||
        (common->aux0_addr >> 4) != 0u ||
        common->aux1_addr != 0u ||
        join_mode > 2u ||
        !npu_wire_event_decode((uint16_t)common->src0_addr, &event0) ||
        !npu_wire_event_decode((uint16_t)common->src1_addr, &event1) ||
        !npu_wire_event_decode((uint16_t)common->dst_addr, &target)) {
        return NPU_STATUS_BAD_DESC;
    }

    meta->control_join_mode = join_mode;
    meta->control_engine_mask = engine_mask;
    request->desc.control.event0 = event0;
    request->desc.control.event1 = event1;
    request->desc.control.target = target;
    request->desc.control.join_mode = join_mode;
    request->desc.control.engine_mask = engine_mask;

    if (cmd->opcode == NPU_CTRL_NOP) {
        if (common->op_flags != 0u ||
            common->src0_addr != 0u || common->src1_addr != 0u ||
            common->dst_addr != 0u || common->aux0_addr != 0u ||
            !npu_wire_event_is_none(cmd->wait_event[0]) ||
            !npu_wire_event_is_none(cmd->wait_event[1]) ||
            !npu_wire_event_is_none(cmd->signal_event)) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (cmd->opcode == NPU_CTRL_EVENT_SIGNAL) {
        if (common->op_flags != 0u ||
            common->src0_addr != 0u || common->src1_addr != 0u ||
            common->aux0_addr != 0u ||
            npu_wire_event_is_none(target) ||
            !npu_wire_event_equal(target, cmd->signal_event) ||
            !npu_wire_event_is_none(cmd->wait_event[0]) ||
            !npu_wire_event_is_none(cmd->wait_event[1])) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (cmd->opcode == NPU_CTRL_EVENT_REARM) {
        if (common->op_flags != 0u ||
            common->src1_addr != 0u || common->aux0_addr != 0u ||
            npu_wire_event_is_none(event0) ||
            npu_wire_event_is_none(target) ||
            event0.id != target.id ||
            target.generation !=
                (uint8_t)((event0.generation + 1u) & 0x0fu) ||
            !npu_wire_event_is_none(cmd->wait_event[0]) ||
            !npu_wire_event_is_none(cmd->wait_event[1]) ||
            !npu_wire_event_is_none(cmd->signal_event)) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (cmd->opcode == NPU_CTRL_EVENT_JOIN) {
        if ((common->op_flags & ~0x00000300u) != 0u ||
            common->aux0_addr != 0u ||
            npu_wire_event_is_none(event0) ||
            npu_wire_event_is_none(event1) ||
            npu_wire_event_is_none(target) ||
            npu_wire_event_equal(event0, event1) ||
            !npu_wire_event_equal(event0, cmd->wait_event[0]) ||
            !npu_wire_event_equal(event1, cmd->wait_event[1]) ||
            !npu_wire_event_equal(target, cmd->signal_event)) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (cmd->opcode == NPU_CTRL_GLOBAL_FENCE) {
        if (common->op_flags != 0u ||
            common->src0_addr != 0u || common->src1_addr != 0u ||
            common->dst_addr != 0u ||
            !npu_wire_event_is_none(cmd->wait_event[0]) ||
            !npu_wire_event_is_none(cmd->wait_event[1])) {
            return NPU_STATUS_BAD_DESC;
        }
    } else {
        return NPU_STATUS_ILLEGAL_OPCODE;
    }
    return NPU_STATUS_SUCCESS;
}

static int npu_wire_dma_dtype_pair(npu_dtype_t src,
                                   npu_dtype_t dst,
                                   npu_dma_convert_t mode)
{
    uint32_t src_bits;
    uint32_t dst_bits;

    if (!npu_wire_dtype_valid(src) ||
        !npu_wire_dtype_valid(dst)) {
        return 0;
    }
    src_bits = npu_wire_dtype_bits(src);
    dst_bits = npu_wire_dtype_bits(dst);
    if (mode == NPU_DMA_CONVERT_NONE) {
        return src == dst;
    }
    if (mode == NPU_DMA_SIGN_EXTEND) {
        return src_bits < dst_bits;
    }
    if (mode == NPU_DMA_SATURATE_NARROW) {
        return src_bits > dst_bits;
    }
    if (mode == NPU_DMA_PACK_INT4) {
        return src_bits > 4u &&
               dst == NPU_DTYPE_INT4;
    }
    return 0;
}

static npu_status_t npu_wire_dma_span(const npu_dma_desc_t *desc,
                                      int source,
                                      uint64_t *span)
{
    const uint32_t *stride = source != 0 ? desc->src_stride_bytes
                                         : desc->dst_stride_bytes;
    npu_dtype_t dtype = source != 0 ? desc->src_dtype : desc->dst_dtype;
    uint8_t nibble = source != 0 ? desc->src_nibble : desc->dst_nibble;
    uint64_t value = 0u;
    uint64_t part;
    uint32_t dimension;
    uint32_t last;

    for (dimension = 0u; dimension < desc->rank; dimension++) {
        if (desc->shape[dimension] == 0u) {
            *span = 0u;
            return NPU_STATUS_SUCCESS;
        }
    }
    for (dimension = 0u; dimension + 1u < desc->rank; dimension++) {
        if (!npu_wire_mul_u64(desc->shape[dimension] - 1u,
                              stride[dimension], &part) ||
            !npu_wire_add_u64(value, part, &value)) {
            return NPU_STATUS_ADDR_FAULT;
        }
    }
    last = desc->shape[desc->rank - 1u];
    if (dtype == NPU_DTYPE_INT4) {
        part = ((uint64_t)nibble + last + 1u) / 2u;
    } else {
        part = (uint64_t)last * npu_wire_dtype_bytes(dtype);
    }
    if (!npu_wire_add_u64(value, part, &value)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    *span = value;
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_wire_decode_dma(
    const npu_cmd_t *cmd,
    const uint8_t *wire,
    const npu_wire_common_t *common,
    const npu_wire_limits_t *limits,
    npu_task_request_t *request,
    npu_wire_meta_t *meta)
{
    npu_dma_desc_t *desc = &request->desc.dma;
    uint64_t src_span = 0u;
    uint64_t dst_span = 0u;
    uint64_t packed_span;
    uint64_t spaced_span;
    uint16_t burst_beats;
    uint32_t dimension;
    npu_status_t status;
    uint32_t address_flags;

    if (!npu_wire_zero_range(wire, 0x5cu, 0x60u) ||
        !npu_wire_zero_range(wire, 0x74u, 0x78u) ||
        !npu_wire_zero_range(wire, 0x8cu, 0x90u) ||
        !npu_wire_zero_range(wire, 0xb0u, NPU_WIRE_DMA_DESC_BYTES) ||
        (common->numeric_cfg & 0xffffff00u) != 0u ||
        common->src1_dtype != NPU_DTYPE_INT4 ||
        common->src2_dtype != NPU_DTYPE_INT4 ||
        common->src1_addr != 0u ||
        common->src2_addr != 0u ||
        common->aux0_addr != 0u ||
        common->aux1_addr != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    desc->rank = wire[0x40u];
    desc->src_space = (npu_space_t)wire[0x41u];
    desc->dst_space = (npu_space_t)wire[0x42u];
    desc->convert_mode = (npu_dma_convert_t)wire[0x43u];
    burst_beats = (uint16_t)wire[0x44u] + 1u;
    desc->max_outstanding = wire[0x45u];
    desc->src_nibble = wire[0x46u];
    desc->dst_nibble = wire[0x47u];
    desc->src_dtype = common->src0_dtype;
    desc->dst_dtype = common->dst_dtype;
    desc->src_addr = common->src0_addr;
    desc->dst_addr = common->dst_addr;
    for (dimension = 0u; dimension < NPU_MAX_DMA_RANK; dimension++) {
        desc->shape[dimension] =
            npu_wire_u32(wire, 0x48u + dimension * 4u);
        desc->src_stride_bytes[dimension] =
            npu_wire_u32(wire, 0x60u + dimension * 4u);
        desc->dst_stride_bytes[dimension] =
            npu_wire_u32(wire, 0x78u + dimension * 4u);
    }
    desc->fill_value = npu_wire_u64(wire, 0x90u);
    desc->src_region_bytes = npu_wire_u64(wire, 0x98u);
    desc->dst_region_bytes = npu_wire_u64(wire, 0xa0u);
    desc->segment_count = npu_wire_u16(wire, 0xa8u);
    desc->segment_bytes = npu_wire_u16(wire, 0xaau);
    desc->segment_stride = npu_wire_u32(wire, 0xacu);
    meta->dma_burst_beats = burst_beats;

    if (desc->rank == 0u || desc->rank > NPU_MAX_DMA_RANK ||
        desc->src_space > NPU_SPACE_DDR ||
        desc->dst_space > NPU_SPACE_DDR ||
        desc->convert_mode > NPU_DMA_PACK_INT4 ||
        desc->src_nibble > 1u || desc->dst_nibble > 1u ||
        burst_beats > limits->dma_max_burst_beats ||
        burst_beats > UINT8_MAX ||
        desc->max_outstanding == 0u ||
        desc->max_outstanding > limits->dma_max_outstanding) {
        return NPU_STATUS_BAD_DESC;
    }
    desc->burst_beats = (uint8_t)burst_beats;

    address_flags = common->op_flags &
                    (NPU_WIRE_OP_SRC0_GADDR |
                     NPU_WIRE_OP_SRC1_GADDR |
                     NPU_WIRE_OP_SRC2_GADDR |
                     NPU_WIRE_OP_DST_GADDR |
                     NPU_WIRE_OP_AUX0_GADDR |
                     NPU_WIRE_OP_AUX1_GADDR);
    if ((common->op_flags & NPU_WIRE_OP_ALLOW_INPLACE) != 0u ||
        ((address_flags & NPU_WIRE_OP_SRC0_GADDR) != 0u) !=
            (desc->src_space == NPU_SPACE_DDR) ||
        ((address_flags & NPU_WIRE_OP_DST_GADDR) != 0u) !=
            (desc->dst_space == NPU_SPACE_DDR) ||
        (address_flags &
         (NPU_WIRE_OP_SRC1_GADDR | NPU_WIRE_OP_SRC2_GADDR |
          NPU_WIRE_OP_AUX0_GADDR | NPU_WIRE_OP_AUX1_GADDR)) != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->dst_dtype == NPU_DTYPE_INT4 && desc->dst_nibble != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->src_dtype != NPU_DTYPE_INT4 && desc->src_nibble != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->dst_dtype != NPU_DTYPE_INT4 && desc->dst_nibble != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    for (dimension = desc->rank; dimension < NPU_MAX_DMA_RANK; dimension++) {
        if (desc->shape[dimension] != 0u ||
            desc->src_stride_bytes[dimension] != 0u ||
            desc->dst_stride_bytes[dimension] != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    }
    if (desc->src_stride_bytes[desc->rank - 1u] != 0u ||
        desc->dst_stride_bytes[desc->rank - 1u] != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    for (dimension = 0u; dimension + 1u < desc->rank; dimension++) {
        if (desc->shape[dimension] > 1u &&
            ((cmd->opcode != NPU_DMA_FILL &&
              desc->src_stride_bytes[dimension] == 0u) ||
             desc->dst_stride_bytes[dimension] == 0u)) {
            return NPU_STATUS_BAD_SHAPE;
        }
    }

    if (cmd->opcode == NPU_DMA_COPY_1D && desc->rank != 1u) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (cmd->opcode == NPU_DMA_TRANSPOSE_2D) {
        if (desc->rank != 2u ||
            desc->convert_mode != NPU_DMA_CONVERT_NONE ||
            desc->src_dtype != desc->dst_dtype ||
            desc->shape[2] != 0u ||
            desc->src_stride_bytes[1] != 0u ||
            desc->dst_stride_bytes[1] != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    }
    if (cmd->opcode == NPU_DMA_PACK || cmd->opcode == NPU_DMA_SPLIT) {
        if (desc->rank != 1u ||
            desc->src_stride_bytes[0] != 0u ||
            desc->dst_stride_bytes[0] != 0u ||
            desc->convert_mode != NPU_DMA_CONVERT_NONE ||
            desc->src_dtype != desc->dst_dtype ||
            desc->fill_value != 0u ||
            desc->segment_count == 0u ||
            desc->segment_bytes == 0u ||
            desc->segment_stride < desc->segment_bytes) {
            return NPU_STATUS_BAD_DESC;
        }
        if (desc->shape[0] != desc->segment_count) {
            return NPU_STATUS_BAD_SHAPE;
        }
    } else if (desc->segment_count != 0u ||
               desc->segment_bytes != 0u ||
               desc->segment_stride != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (cmd->opcode == NPU_DMA_FILL) {
        if (common->src0_addr != 0u ||
            desc->src_space != NPU_SPACE_L1 ||
            desc->src_region_bytes != 0u ||
            desc->src_nibble != 0u ||
            common->src0_dtype != NPU_DTYPE_INT4 ||
            desc->convert_mode != NPU_DMA_CONVERT_NONE) {
            return NPU_STATUS_BAD_DESC;
        }
        for (dimension = 0u; dimension < NPU_MAX_DMA_RANK; dimension++) {
            if (desc->src_stride_bytes[dimension] != 0u) {
                return NPU_STATUS_BAD_DESC;
            }
        }
    } else {
        if (desc->fill_value != 0u ||
            !npu_wire_dma_dtype_pair(desc->src_dtype,
                                     desc->dst_dtype,
                                     desc->convert_mode)) {
            return NPU_STATUS_DTYPE_UNSUPPORTED;
        }
    }

    if (cmd->opcode == NPU_DMA_PACK || cmd->opcode == NPU_DMA_SPLIT) {
        if (!npu_wire_mul_u64(desc->segment_count,
                              desc->segment_bytes,
                              &packed_span)) {
            if (cmd->opcode == NPU_DMA_PACK) {
                npu_wire_record_region_fault(
                    meta, desc->dst_space, desc->dst_addr,
                    desc->dst_region_bytes, limits);
            } else {
                npu_wire_record_region_fault(
                    meta, desc->src_space, desc->src_addr,
                    desc->src_region_bytes, limits);
            }
            return NPU_STATUS_ADDR_FAULT;
        }
        if (desc->segment_count == 0u) {
            spaced_span = 0u;
        } else {
            if (!npu_wire_mul_u64(desc->segment_count - 1u,
                                  desc->segment_stride,
                                  &spaced_span) ||
                !npu_wire_add_u64(spaced_span,
                                  desc->segment_bytes,
                                  &spaced_span)) {
                if (cmd->opcode == NPU_DMA_PACK) {
                    npu_wire_record_region_fault(
                        meta, desc->src_space, desc->src_addr,
                        desc->src_region_bytes, limits);
                } else {
                    npu_wire_record_region_fault(
                        meta, desc->dst_space, desc->dst_addr,
                        desc->dst_region_bytes, limits);
                }
                return NPU_STATUS_ADDR_FAULT;
            }
        }
        src_span = cmd->opcode == NPU_DMA_PACK ? spaced_span : packed_span;
        dst_span = cmd->opcode == NPU_DMA_PACK ? packed_span : spaced_span;
    } else if (cmd->opcode == NPU_DMA_TRANSPOSE_2D) {
        uint64_t row_part;
        uint64_t tail_part;

        if (desc->shape[0] != 0u && desc->shape[1] != 0u) {
            if (!npu_wire_mul_u64(desc->shape[0] - 1u,
                                  desc->src_stride_bytes[0],
                                  &row_part)) {
                npu_wire_record_region_fault(
                    meta, desc->src_space, desc->src_addr,
                    desc->src_region_bytes, limits);
                return NPU_STATUS_ADDR_FAULT;
            }
            tail_part = desc->src_dtype == NPU_DTYPE_INT4
                            ? ((uint64_t)desc->src_nibble +
                               desc->shape[1] + 1u) /
                                  2u
                            : (uint64_t)desc->shape[1] *
                                  npu_wire_dtype_bytes(desc->src_dtype);
            if (!npu_wire_add_u64(
                    row_part, tail_part, &src_span)) {
                npu_wire_record_region_fault(
                    meta, desc->src_space, desc->src_addr,
                    desc->src_region_bytes, limits);
                return NPU_STATUS_ADDR_FAULT;
            }
            if (!npu_wire_mul_u64(
                    desc->shape[1] - 1u,
                    desc->dst_stride_bytes[0],
                    &row_part)) {
                npu_wire_record_region_fault(
                    meta, desc->dst_space, desc->dst_addr,
                    desc->dst_region_bytes, limits);
                return NPU_STATUS_ADDR_FAULT;
            }
            tail_part = desc->dst_dtype == NPU_DTYPE_INT4
                            ? ((uint64_t)desc->dst_nibble +
                               desc->shape[0] + 1u) /
                                  2u
                            : (uint64_t)desc->shape[0] *
                                  npu_wire_dtype_bytes(desc->dst_dtype);
            if (!npu_wire_add_u64(row_part, tail_part, &dst_span)) {
                npu_wire_record_region_fault(
                    meta, desc->dst_space, desc->dst_addr,
                    desc->dst_region_bytes, limits);
                return NPU_STATUS_ADDR_FAULT;
            }
        }
    } else {
        if (cmd->opcode != NPU_DMA_FILL) {
            status = npu_wire_dma_span(desc, 1, &src_span);
            if (status != NPU_STATUS_SUCCESS) {
                if (status == NPU_STATUS_ADDR_FAULT) {
                    npu_wire_record_region_fault(
                        meta, desc->src_space, desc->src_addr,
                        desc->src_region_bytes, limits);
                }
                return status;
            }
        }
        status = npu_wire_dma_span(desc, 0, &dst_span);
        if (status != NPU_STATUS_SUCCESS) {
            if (status == NPU_STATUS_ADDR_FAULT) {
                npu_wire_record_region_fault(
                    meta, desc->dst_space, desc->dst_addr,
                    desc->dst_region_bytes, limits);
            }
            return status;
        }
    }

    if (cmd->opcode != NPU_DMA_FILL) {
        if (src_span > desc->src_region_bytes) {
            npu_wire_record_region_fault(
                meta, desc->src_space, desc->src_addr,
                desc->src_region_bytes, limits);
            return NPU_STATUS_ADDR_FAULT;
        }
        status = npu_wire_check_address(
            desc->src_space, desc->src_addr,
            src_span, limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    if (dst_span > desc->dst_region_bytes) {
        npu_wire_record_region_fault(
            meta, desc->dst_space, desc->dst_addr,
            desc->dst_region_bytes, limits);
        return NPU_STATUS_ADDR_FAULT;
    }
    status = npu_wire_check_address(
        desc->dst_space, desc->dst_addr,
        dst_span, limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (cmd->opcode != NPU_DMA_FILL &&
        desc->src_space == desc->dst_space &&
        npu_wire_ranges_overlap(desc->src_addr, src_span,
                                desc->dst_addr, dst_span)) {
        return NPU_STATUS_ADDR_OVERLAP;
    }
    return NPU_STATUS_SUCCESS;
}

static void npu_wire_tensor_init(npu_tensor_t *tensor,
                                 npu_space_t space,
                                 npu_dtype_t dtype,
                                 uint64_t addr,
                                 uint64_t region_bytes,
                                 uint32_t row_stride,
                                 uint32_t elem_stride,
                                 uint32_t batch_stride,
                                 uint8_t start_nibble)
{
    tensor->space = space;
    tensor->dtype = dtype;
    tensor->addr = addr;
    tensor->region_bytes = region_bytes;
    tensor->row_stride_bytes = row_stride;
    tensor->elem_stride_bytes = elem_stride;
    tensor->batch_stride_bytes = batch_stride;
    tensor->start_nibble = start_nibble;
}

static npu_status_t npu_wire_tensor_span(const npu_tensor_t *tensor,
                                         uint32_t batches,
                                         uint32_t rows,
                                         uint32_t length,
                                         uint64_t *span)
{
    uint64_t value = 0u;
    uint64_t part;
    uint64_t element_part;
    uint64_t row_extent;
    uint32_t element_bytes;

    if (batches == 0u || rows == 0u || length == 0u) {
        *span = 0u;
        return NPU_STATUS_SUCCESS;
    }
    if (batches > 1u && tensor->batch_stride_bytes == 0u) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (rows > 1u && tensor->row_stride_bytes == 0u) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (!npu_wire_mul_u64(batches - 1u,
                          tensor->batch_stride_bytes,
                          &value) ||
        !npu_wire_mul_u64(rows - 1u,
                          tensor->row_stride_bytes,
                          &part) ||
        !npu_wire_add_u64(value, part, &value)) {
        return NPU_STATUS_ADDR_FAULT;
    }

    if (tensor->dtype == NPU_DTYPE_INT4) {
        if (tensor->elem_stride_bytes == 0u) {
            element_part =
                ((uint64_t)tensor->start_nibble + length + 1u) / 2u;
        } else {
            if (!npu_wire_mul_u64(length - 1u,
                                  tensor->elem_stride_bytes,
                                  &element_part) ||
                !npu_wire_add_u64(element_part, 1u, &element_part)) {
                return NPU_STATUS_ADDR_FAULT;
            }
        }
    } else {
        element_bytes = npu_wire_dtype_bytes(tensor->dtype);
        if (element_bytes == 0u) {
            return NPU_STATUS_DTYPE_UNSUPPORTED;
        }
        if ((tensor->addr % element_bytes) != 0u ||
            (tensor->elem_stride_bytes != 0u &&
             (tensor->elem_stride_bytes % element_bytes) != 0u) ||
            (rows > 1u &&
             (tensor->row_stride_bytes % element_bytes) != 0u) ||
            (batches > 1u &&
             (tensor->batch_stride_bytes % element_bytes) != 0u)) {
            return NPU_STATUS_BAD_SHAPE;
        }
        if (tensor->elem_stride_bytes == 0u) {
            if (!npu_wire_mul_u64(length, element_bytes,
                                  &element_part)) {
                return NPU_STATUS_ADDR_FAULT;
            }
        } else {
            if (length > 1u &&
                tensor->elem_stride_bytes < element_bytes) {
                return NPU_STATUS_BAD_SHAPE;
            }
            if (!npu_wire_mul_u64(length - 1u,
                                  tensor->elem_stride_bytes,
                                  &element_part) ||
                !npu_wire_add_u64(element_part,
                                  element_bytes,
                                  &element_part)) {
                return NPU_STATUS_ADDR_FAULT;
            }
        }
    }
    if (rows > 1u &&
        tensor->row_stride_bytes < element_part) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (!npu_wire_mul_u64(rows - 1u,
                          tensor->row_stride_bytes,
                          &row_extent) ||
        !npu_wire_add_u64(row_extent, element_part,
                          &row_extent)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    if (batches > 1u &&
        tensor->batch_stride_bytes < row_extent) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (!npu_wire_add_u64(value, element_part, &value)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    *span = value;
    return NPU_STATUS_SUCCESS;
}

static npu_status_t npu_wire_validate_tensor(
    const npu_tensor_t *tensor,
    uint32_t batches,
    uint32_t rows,
    uint32_t length,
    const npu_wire_limits_t *limits,
    npu_wire_meta_t *meta,
    uint64_t *span)
{
    npu_status_t status =
        npu_wire_tensor_span(tensor, batches, rows, length, span);

    if (status != NPU_STATUS_SUCCESS) {
        if (status == NPU_STATUS_ADDR_FAULT) {
            npu_wire_record_region_fault(
                meta, tensor->space, tensor->addr,
                tensor->region_bytes, limits);
        }
        return status;
    }
    return npu_wire_check_address(
        tensor->space, tensor->addr, *span, limits, meta);
}

static uint32_t npu_wire_last_tile(uint32_t size, uint32_t tile)
{
    uint32_t remainder;

    if (size == 0u) {
        return 0u;
    }
    remainder = size % tile;
    return remainder == 0u ? tile : remainder;
}

static npu_status_t npu_wire_matrix_b_span(
    const npu_matrix_desc_t *desc,
    const npu_wire_limits_t *limits,
    uint64_t *span)
{
    uint64_t k_tiles =
        ((uint64_t)desc->k + limits->kt - 1u) / limits->kt;
    uint64_t n_tiles =
        ((uint64_t)desc->n + limits->nt - 1u) / limits->nt;
    uint64_t elements;
    uint64_t bytes;
    uint64_t batch_part;

    if (desc->k == 0u || desc->n == 0u || desc->batch_count == 0u) {
        *span = 0u;
        return NPU_STATUS_SUCCESS;
    }
    if (!npu_wire_mul_u64(k_tiles, n_tiles, &elements) ||
        !npu_wire_mul_u64(elements, limits->kt, &elements) ||
        !npu_wire_mul_u64(elements, limits->nt, &elements)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    if (desc->b.dtype == NPU_DTYPE_INT4) {
        bytes = (elements + 1u) / 2u;
    } else if (!npu_wire_mul_u64(
                   elements,
                   npu_wire_dtype_bytes(desc->b.dtype),
                   &bytes)) {
        return NPU_STATUS_ADDR_FAULT;
    }
    if (desc->batch_count > 1u) {
        if (desc->b.batch_stride_bytes == 0u ||
            !npu_wire_mul_u64(desc->batch_count - 1u,
                              desc->b.batch_stride_bytes,
                              &batch_part) ||
            !npu_wire_add_u64(batch_part, bytes, &bytes)) {
            return NPU_STATUS_ADDR_FAULT;
        }
    }
    *span = bytes;
    return NPU_STATUS_SUCCESS;
}

static int npu_wire_matrix_dtype_valid(npu_dtype_t a,
                                       npu_dtype_t b,
                                       npu_dtype_t c)
{
    int inputs = (a == NPU_DTYPE_INT4 && b == NPU_DTYPE_INT4) ||
                 (a == NPU_DTYPE_INT8 && b == NPU_DTYPE_INT8) ||
                 (a == NPU_DTYPE_INT8 && b == NPU_DTYPE_INT4) ||
                 (a == NPU_DTYPE_INT16 && b == NPU_DTYPE_INT16);

    return inputs &&
           (c == NPU_DTYPE_INT4 ||
            c == NPU_DTYPE_INT8 ||
            c == NPU_DTYPE_INT16 ||
            c == NPU_DTYPE_INT32);
}

static uint8_t npu_wire_matrix_a_pack(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT4) {
        return NPU_WIRE_MATRIX_PACK_LINEAR_INT4;
    }
    if (dtype == NPU_DTYPE_INT16) {
        return NPU_WIRE_MATRIX_PACK_LINEAR_INT16;
    }
    return NPU_WIRE_MATRIX_PACK_LINEAR_INT8;
}

static uint8_t npu_wire_matrix_b_pack(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT4) {
        return NPU_WIRE_MATRIX_PACK_TILED_INT4;
    }
    if (dtype == NPU_DTYPE_INT16) {
        return NPU_WIRE_MATRIX_PACK_TILED_INT16;
    }
    return NPU_WIRE_MATRIX_PACK_TILED_INT8;
}

static uint8_t npu_wire_matrix_c_pack(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT4) {
        return NPU_WIRE_MATRIX_PACK_LINEAR_INT4;
    }
    if (dtype == NPU_DTYPE_INT8) {
        return NPU_WIRE_MATRIX_PACK_LINEAR_INT8;
    }
    if (dtype == NPU_DTYPE_INT16) {
        return NPU_WIRE_MATRIX_PACK_LINEAR_INT16;
    }
    return NPU_WIRE_MATRIX_PACK_LINEAR_INT32;
}

static npu_status_t npu_wire_decode_matrix(
    const npu_cmd_t *cmd,
    const uint8_t *wire,
    const npu_wire_common_t *common,
    const npu_wire_limits_t *limits,
    npu_task_request_t *request,
    npu_wire_meta_t *meta)
{
    npu_matrix_desc_t *desc = &request->desc.matrix;
    uint32_t flags = npu_wire_u32(wire, 0x5cu);
    uint32_t last_m = npu_wire_u32(wire, 0x50u);
    uint32_t last_n = npu_wire_u32(wire, 0x54u);
    uint32_t last_k = npu_wire_u32(wire, 0x58u);
    uint32_t lda = npu_wire_u32(wire, 0x60u);
    uint32_t ldb = npu_wire_u32(wire, 0x64u);
    uint32_t ldc = npu_wire_u32(wire, 0x68u);
    uint64_t a_batch = npu_wire_u64(wire, 0x70u);
    uint64_t b_batch = npu_wire_u64(wire, 0x78u);
    uint64_t c_batch = npu_wire_u64(wire, 0x80u);
    uint64_t src2_batch = npu_wire_u64(wire, 0x88u);
    uint8_t a_pack = wire[0x90u];
    uint8_t b_pack = wire[0x91u];
    uint8_t c_pack = wire[0x92u];
    uint8_t pack_version = wire[0x93u];
    uint8_t overflow_mode = wire[0x94u];
    uint8_t activation_mode = wire[0x95u];
    uint8_t requant_mode = wire[0xa4u];
    uint8_t residual_mode = wire[0xa5u];
    uint8_t requant_entry_bytes = wire[0xa6u];
    uint64_t span;
    uint64_t required;
    uint64_t rows;
    uint64_t columns;
    npu_status_t status;

    if (!npu_wire_zero_range(wire, 0x96u, 0x98u) ||
        wire[0xa7u] != 0u ||
        npu_wire_u32(wire, 0xacu) != 0u ||
        !npu_wire_zero_range(wire, 0xb0u,
                             NPU_WIRE_MATRIX_DESC_BYTES) ||
        (common->op_flags & 0x3fu) != 0u ||
        common->scale_mode != 0u ||
        common->zero_point_enable != 0u ||
        common->internal_fp32_enable != 0u ||
        (flags & 0xffffff00u) != 0u ||
        overflow_mode > NPU_OVERFLOW_WRAP ||
        activation_mode > 1u ||
        requant_mode > 2u ||
        residual_mode > 1u) {
        return NPU_STATUS_BAD_DESC;
    }
    status = npu_wire_check_address(
        NPU_SPACE_L1, common->src0_addr, 0u, limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    status = npu_wire_check_address(
        NPU_SPACE_L1, common->src1_addr, 0u, limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    status = npu_wire_check_address(
        NPU_SPACE_L1, common->src2_addr, 0u, limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    status = npu_wire_check_address(
        NPU_SPACE_L1, common->dst_addr, 0u, limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    status = npu_wire_check_address(
        NPU_SPACE_L1, common->aux0_addr, 0u, limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    status = npu_wire_check_address(
        NPU_SPACE_L1, common->aux1_addr, 0u, limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (a_batch > UINT32_MAX) {
        npu_wire_record_unbounded_span_fault(
            meta, NPU_SPACE_L1, common->src0_addr, limits);
        return NPU_STATUS_ADDR_FAULT;
    }
    if (b_batch > UINT32_MAX) {
        npu_wire_record_unbounded_span_fault(
            meta, NPU_SPACE_L1, common->src1_addr, limits);
        return NPU_STATUS_ADDR_FAULT;
    }
    if (c_batch > UINT32_MAX) {
        npu_wire_record_unbounded_span_fault(
            meta, NPU_SPACE_L1, common->dst_addr, limits);
        return NPU_STATUS_ADDR_FAULT;
    }
    if (src2_batch > UINT32_MAX) {
        npu_wire_record_unbounded_span_fault(
            meta, NPU_SPACE_L1, common->src2_addr, limits);
        return NPU_STATUS_ADDR_FAULT;
    }

    desc->m = npu_wire_u32(wire, 0x40u);
    desc->n = npu_wire_u32(wire, 0x44u);
    desc->k = npu_wire_u32(wire, 0x48u);
    desc->batch_count = npu_wire_u32(wire, 0x4cu);
    desc->bias_stride_bytes = npu_wire_u32(wire, 0x6cu);
    desc->bias_addr = common->aux0_addr;
    desc->bias_count = npu_wire_u32(wire, 0xa0u);
    desc->requant_addr = common->aux1_addr;
    desc->requant_count = npu_wire_u32(wire, 0x9cu);
    desc->requant_region_bytes = npu_wire_u32(wire, 0xa8u);
    desc->transpose_a =
        (uint8_t)((flags & NPU_WIRE_MATRIX_A_TRANSPOSE) != 0u);
    desc->transpose_b =
        (uint8_t)((flags & NPU_WIRE_MATRIX_B_TRANSPOSE) != 0u);
    desc->bias_enable =
        (uint8_t)((flags & NPU_WIRE_MATRIX_BIAS) != 0u);
    desc->residual_enable =
        (uint8_t)((flags & NPU_WIRE_MATRIX_RESIDUAL) != 0u);
    desc->relu_enable =
        (uint8_t)((flags & NPU_WIRE_MATRIX_RELU) != 0u);
    desc->requant_enable =
        (uint8_t)((flags & NPU_WIRE_MATRIX_REQUANT) != 0u);
    desc->accum_from_src2 =
        (uint8_t)((flags & NPU_WIRE_MATRIX_ACCUM_SRC2) != 0u);
    desc->final_output =
        (uint8_t)((flags & NPU_WIRE_MATRIX_FINAL) != 0u);
    desc->b_tiled = 1u;
    desc->round_mode = common->round_mode;
    desc->overflow_mode = (npu_overflow_mode_t)overflow_mode;
    desc->output_zero_point = npu_wire_i32(wire, 0x98u);

    meta->matrix_last_tile_valid_m = last_m;
    meta->matrix_last_tile_valid_n = last_n;
    meta->matrix_last_tile_valid_k = last_k;
    meta->matrix_a_pack_format = a_pack;
    meta->matrix_b_pack_format = b_pack;
    meta->matrix_c_pack_format = c_pack;
    meta->matrix_pack_version = pack_version;
    meta->matrix_activation_mode = activation_mode;
    meta->matrix_requant_mode = requant_mode;
    meta->matrix_residual_mode = residual_mode;
    meta->matrix_requant_entry_bytes = requant_entry_bytes;

    if (desc->batch_count == 0u ||
        (cmd->opcode != NPU_MATRIX_BMM &&
         desc->batch_count != 1u) ||
        desc->transpose_b != 0u ||
        desc->output_zero_point != 0 ||
        desc->residual_enable + desc->accum_from_src2 > 1u ||
        activation_mode != desc->relu_enable) {
        return NPU_STATUS_BAD_DESC;
    }
    if (last_m !=
            npu_wire_last_tile(desc->m, limits->mt) ||
        last_n !=
            npu_wire_last_tile(desc->n, limits->nt) ||
        last_k !=
            npu_wire_last_tile(desc->k, limits->kt)) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (cmd->opcode != NPU_MATRIX_BMM &&
        (a_batch != 0u || b_batch != 0u ||
         c_batch != 0u || src2_batch != 0u)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (cmd->opcode == NPU_MATRIX_BMM &&
        desc->batch_count > 1u &&
        (a_batch == 0u || b_batch == 0u || c_batch == 0u)) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (ldb != 0u || requant_entry_bytes != 8u) {
        return NPU_STATUS_BAD_DESC;
    }

    if (cmd->opcode == NPU_MATRIX_GEMM_ZERO) {
        if (desc->k != 0u ||
            common->src0_addr != 0u ||
            common->src1_addr != 0u ||
            common->src2_addr != 0u ||
            common->aux0_addr != 0u ||
            common->aux1_addr != 0u ||
            flags != 0u ||
            common->src0_dtype != NPU_DTYPE_INT4 ||
            common->src1_dtype != NPU_DTYPE_INT4 ||
            common->src2_dtype != NPU_DTYPE_INT4 ||
            common->dst_dtype != NPU_DTYPE_INT32) {
            return NPU_STATUS_BAD_DESC;
        }
    } else {
        if (!npu_wire_matrix_dtype_valid(common->src0_dtype,
                                         common->src1_dtype,
                                         common->dst_dtype)) {
            return NPU_STATUS_DTYPE_UNSUPPORTED;
        }
        if (cmd->opcode == NPU_MATRIX_GEMM_ACCUM) {
            if (desc->accum_from_src2 == 0u ||
                desc->final_output != 0u ||
                common->src2_dtype != NPU_DTYPE_INT32 ||
                common->dst_dtype != NPU_DTYPE_INT32) {
                return NPU_STATUS_BAD_DESC;
            }
        } else if (desc->final_output == 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    }

    if (desc->final_output == 0u &&
        (desc->bias_enable != 0u ||
         desc->residual_enable != 0u ||
         desc->relu_enable != 0u ||
         desc->requant_enable != 0u ||
         common->dst_dtype != NPU_DTYPE_INT32)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (common->dst_dtype != NPU_DTYPE_INT32 &&
        (desc->requant_enable == 0u ||
         common->saturate_enable == 0u ||
         (requant_mode != 1u && requant_mode != 2u) ||
         requant_entry_bytes != 8u ||
         desc->requant_count !=
             (requant_mode == 1u ? 1u : desc->n))) {
        return NPU_STATUS_BAD_DESC;
    }
    if (common->dst_dtype == NPU_DTYPE_INT32 &&
        common->saturate_enable != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (common->dst_dtype == NPU_DTYPE_INT32 &&
        (desc->requant_enable != 0u ||
         requant_mode != 0u ||
         desc->requant_count != 0u ||
         common->aux1_addr != 0u ||
         desc->requant_region_bytes != 0u)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->requant_enable != 0u) {
        if (!npu_wire_mul_u64(
                desc->requant_count, 8u, &required)) {
            npu_wire_record_region_fault(
                meta, NPU_SPACE_L1, desc->requant_addr,
                desc->requant_region_bytes, limits);
            return NPU_STATUS_ADDR_FAULT;
        }
        if (required > desc->requant_region_bytes) {
            npu_wire_record_region_fault(
                meta, NPU_SPACE_L1, desc->requant_addr,
                desc->requant_region_bytes, limits);
            return NPU_STATUS_ADDR_FAULT;
        }
        status = npu_wire_check_address(
            NPU_SPACE_L1, desc->requant_addr,
            required, limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }

    if (desc->bias_enable != 0u) {
        if (desc->bias_count != desc->n ||
            desc->bias_stride_bytes < 4u ||
            (desc->bias_addr & 3u) != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        if (!npu_wire_mul_u64(
                desc->n == 0u ? 0u : desc->n - 1u,
                desc->bias_stride_bytes, &required) ||
            (desc->n != 0u &&
             !npu_wire_add_u64(required, 4u, &required))) {
            npu_wire_record_unbounded_span_fault(
                meta, NPU_SPACE_L1, desc->bias_addr, limits);
            return NPU_STATUS_ADDR_FAULT;
        }
        status = npu_wire_check_address(
            NPU_SPACE_L1, desc->bias_addr,
            required, limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    } else if (desc->bias_count != 0u ||
               desc->bias_stride_bytes != 0u ||
               common->aux0_addr != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    if (desc->residual_enable != 0u && residual_mode != 1u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->residual_enable == 0u && residual_mode != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((desc->residual_enable != 0u ||
         desc->accum_from_src2 != 0u) &&
        common->src2_dtype != NPU_DTYPE_INT32) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }
    if (desc->residual_enable == 0u &&
        desc->accum_from_src2 == 0u &&
        common->src2_addr != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    if (pack_version != 0u ||
        a_pack != npu_wire_matrix_a_pack(common->src0_dtype) ||
        b_pack != npu_wire_matrix_b_pack(common->src1_dtype) ||
        c_pack != npu_wire_matrix_c_pack(common->dst_dtype)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->requant_enable != 0u &&
        (desc->requant_addr & 7u) != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    npu_wire_tensor_init(&desc->a, NPU_SPACE_L1, common->src0_dtype,
                         common->src0_addr,
                         limits->l1_bytes - common->src0_addr,
                         lda, 0u, (uint32_t)a_batch, 0u);
    npu_wire_tensor_init(&desc->b, NPU_SPACE_L1, common->src1_dtype,
                         common->src1_addr,
                         limits->l1_bytes - common->src1_addr,
                         ldb, 0u, (uint32_t)b_batch, 0u);
    npu_wire_tensor_init(&desc->c, NPU_SPACE_L1, common->dst_dtype,
                         common->dst_addr,
                         limits->l1_bytes - common->dst_addr,
                         ldc, 0u, (uint32_t)c_batch, 0u);
    npu_wire_tensor_init(&desc->src2, NPU_SPACE_L1,
                         NPU_DTYPE_INT32, common->src2_addr,
                         limits->l1_bytes - common->src2_addr,
                         ldc, 0u, (uint32_t)src2_batch, 0u);

    if ((common->src0_addr & 7u) != 0u ||
        (common->src1_addr & 7u) != 0u ||
        (common->dst_addr & 7u) != 0u ||
        ((desc->residual_enable != 0u ||
          desc->accum_from_src2 != 0u) &&
         (common->src2_addr & 7u) != 0u)) {
        return NPU_STATUS_BAD_DESC;
    }

    rows = desc->transpose_a != 0u ? desc->k : desc->m;
    columns = desc->transpose_a != 0u ? desc->m : desc->k;
    status = npu_wire_validate_tensor(&desc->a, desc->batch_count,
                                      (uint32_t)rows,
                                      (uint32_t)columns,
                                      limits, meta, &span);
    if (status != NPU_STATUS_SUCCESS &&
        cmd->opcode != NPU_MATRIX_GEMM_ZERO) {
        return status;
    }
    status = npu_wire_matrix_b_span(desc, limits, &span);
    if (status == NPU_STATUS_ADDR_FAULT) {
        npu_wire_record_region_fault(
            meta, NPU_SPACE_L1, desc->b.addr,
            desc->b.region_bytes, limits);
    } else if (status == NPU_STATUS_SUCCESS) {
        status = npu_wire_check_address(
            NPU_SPACE_L1, desc->b.addr, span, limits, meta);
    }
    if (status != NPU_STATUS_SUCCESS &&
        cmd->opcode != NPU_MATRIX_GEMM_ZERO) {
        return status;
    }
    status = npu_wire_validate_tensor(&desc->c, desc->batch_count,
                                      desc->m, desc->n,
                                      limits, meta, &span);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (desc->residual_enable != 0u ||
        desc->accum_from_src2 != 0u) {
        status = npu_wire_validate_tensor(&desc->src2,
                                          desc->batch_count,
                                          desc->m, desc->n,
                                          limits, meta, &span);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    return NPU_STATUS_SUCCESS;
}

static int npu_wire_fp_positive_finite(uint32_t bits)
{
    return (bits & 0x80000000u) == 0u &&
           (bits & 0x7fffffffu) != 0u &&
           (bits & 0x7f800000u) != 0x7f800000u;
}

static int npu_wire_fp_finite(uint32_t bits)
{
    return (bits & 0x7f800000u) != 0x7f800000u;
}

static void npu_wire_vector_shape(npu_broadcast_t mode,
                                  uint32_t rows,
                                  uint32_t length,
                                  uint32_t *tensor_rows,
                                  uint32_t *tensor_length)
{
    if (mode == NPU_BROADCAST_SCALAR) {
        *tensor_rows = 1u;
        *tensor_length = 1u;
    } else if (mode == NPU_BROADCAST_ROW) {
        *tensor_rows = rows;
        *tensor_length = 1u;
    } else if (mode == NPU_BROADCAST_FEATURE) {
        *tensor_rows = 1u;
        *tensor_length = length;
    } else {
        *tensor_rows = rows;
        *tensor_length = length;
    }
}

static npu_status_t npu_wire_vector_tensor_check(
    const npu_tensor_t *tensor,
    npu_broadcast_t broadcast,
    uint32_t rows,
    uint32_t length,
    const npu_wire_limits_t *limits,
    npu_wire_meta_t *meta)
{
    uint32_t tensor_rows;
    uint32_t tensor_length;
    uint64_t span;

    npu_wire_vector_shape(broadcast, rows, length,
                          &tensor_rows, &tensor_length);
    return npu_wire_validate_tensor(tensor, 1u,
                                    tensor_rows, tensor_length,
                                    limits, meta, &span);
}

static int npu_wire_vector_input_used(uint8_t opcode, uint32_t input)
{
    if (input == 0u) {
        return 1;
    }
    if (input == 1u) {
        return opcode == NPU_VECTOR_ADD ||
               opcode == NPU_VECTOR_SUB ||
               opcode == NPU_VECTOR_MUL ||
               opcode == NPU_VECTOR_FMA ||
               opcode == NPU_VECTOR_MAX ||
               opcode == NPU_VECTOR_MIN ||
               opcode == NPU_VECTOR_CMP ||
               opcode == NPU_VECTOR_SELECT;
    }
    return opcode == NPU_VECTOR_FMA;
}

static npu_status_t npu_wire_decode_vector(
    const npu_cmd_t *cmd,
    const uint8_t *wire,
    const npu_wire_common_t *common,
    const npu_wire_limits_t *limits,
    npu_task_request_t *request,
    npu_wire_meta_t *meta)
{
    npu_vector_desc_t *desc = &request->desc.vector;
    uint32_t flags = npu_wire_u32(wire, 0x4cu);
    uint8_t broadcast = wire[0x78u];
    uint8_t compare_mode = wire[0x79u];
    uint8_t overflow_mode = wire[0x7au];
    uint8_t mask_mode = wire[0x7bu];
    uint8_t src0_nibble = wire[0x7cu];
    uint8_t src1_nibble = wire[0x7du];
    uint8_t dst_nibble = wire[0x7eu];
    uint8_t src2_nibble = wire[0x7fu];
    uint32_t src0_elem = npu_wire_u32(wire, 0x50u);
    uint32_t src1_elem = npu_wire_u32(wire, 0x58u);
    uint32_t src2_elem = npu_wire_u32(wire, 0x60u);
    uint32_t dst_elem = npu_wire_u32(wire, 0x68u);
    uint32_t src0_row = npu_wire_u32(wire, 0x54u);
    uint32_t src1_row = npu_wire_u32(wire, 0x5cu);
    uint32_t src2_row = npu_wire_u32(wire, 0x64u);
    uint32_t dst_row = npu_wire_u32(wire, 0x6cu);
    uint32_t mask_elem = npu_wire_u32(wire, 0x90u);
    uint32_t mask_row = npu_wire_u32(wire, 0x94u);
    int src1_used = npu_wire_vector_input_used(cmd->opcode, 1u);
    int src2_used = npu_wire_vector_input_used(cmd->opcode, 2u);
    npu_status_t status;
    uint64_t limit;

    if (!npu_wire_zero_range(wire, 0x98u,
                             NPU_WIRE_VECTOR_DESC_BYTES) ||
        (common->op_flags & 0x3fu) != 0u ||
        (flags & 0xfffffff0u) != 0u ||
        common->internal_fp32_enable != 0u ||
        common->zero_point_enable != 0u ||
        common->scale_mode != 1u ||
        broadcast > 0x3fu ||
        compare_mode > NPU_COMPARE_GE ||
        overflow_mode > NPU_OVERFLOW_WRAP ||
        mask_mode > 1u ||
        src0_nibble > 1u || src1_nibble > 1u ||
        src2_nibble > 1u || dst_nibble > 1u ||
        common->aux1_addr != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (((overflow_mode == NPU_OVERFLOW_SATURATE) !=
         (common->saturate_enable != 0u))) {
        return NPU_STATUS_BAD_DESC;
    }

    desc->rows = npu_wire_u32(wire, 0x40u);
    desc->length = npu_wire_u32(wire, 0x44u);
    desc->valid_length = npu_wire_u32(wire, 0x48u);
    desc->scalar0 = npu_wire_i32(wire, 0x70u);
    desc->scalar1 = npu_wire_i32(wire, 0x74u);
    desc->clamp_min = desc->scalar0;
    desc->clamp_max = desc->scalar1;
    desc->broadcast0 = (npu_broadcast_t)(broadcast & 0x03u);
    desc->broadcast1 =
        (npu_broadcast_t)((broadcast >> 2) & 0x03u);
    desc->broadcast2 =
        (npu_broadcast_t)((broadcast >> 4) & 0x03u);
    desc->compare_mode = (npu_compare_t)compare_mode;
    desc->overflow_mode = (npu_overflow_mode_t)overflow_mode;
    desc->src0_scale_bits = npu_wire_u32(wire, 0x80u);
    desc->src1_scale_bits = npu_wire_u32(wire, 0x84u);
    desc->src2_scale_bits = npu_wire_u32(wire, 0x88u);
    desc->dst_scale_bits = npu_wire_u32(wire, 0x8cu);
    desc->mask_enable =
        (uint8_t)((flags & NPU_WIRE_VECTOR_MASK) != 0u);
    desc->mask_false_keep_dst =
        (uint8_t)((flags & NPU_WIRE_VECTOR_MASK_KEEP) != 0u);
    desc->src1_from_scalar0 =
        (uint8_t)((flags & NPU_WIRE_VECTOR_SRC1_SCALAR) != 0u);
    desc->src2_from_scalar1 =
        (uint8_t)((flags & NPU_WIRE_VECTOR_SRC2_SCALAR) != 0u);

    if (desc->rows == 0u) {
        if (desc->valid_length != 0u) {
            return NPU_STATUS_BAD_SHAPE;
        }
    } else if (desc->length == 0u) {
        if (desc->valid_length != 0u) {
            return NPU_STATUS_BAD_SHAPE;
        }
    } else if (desc->valid_length == 0u ||
               desc->valid_length > desc->length) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if ((broadcast & 0xc0u) != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (common->src0_dtype == NPU_DTYPE_INT4) {
        if (src0_elem != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (desc->length > 1u &&
               src0_elem <
                   npu_wire_dtype_bytes(common->src0_dtype)) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (common->dst_dtype == NPU_DTYPE_INT4) {
        if (dst_elem != 0u || dst_nibble != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (desc->length > 1u &&
               dst_elem <
                   npu_wire_dtype_bytes(common->dst_dtype)) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (common->dst_dtype != NPU_DTYPE_INT4 &&
        npu_wire_dtype_bytes(common->dst_dtype) > 1u &&
        ((dst_elem %
          npu_wire_dtype_bytes(common->dst_dtype)) != 0u ||
         (desc->rows > 1u &&
          (dst_row %
           npu_wire_dtype_bytes(common->dst_dtype)) != 0u))) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (common->src0_dtype != NPU_DTYPE_INT4 && src0_nibble != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (common->dst_dtype != NPU_DTYPE_INT4 && dst_nibble != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    if (src1_used != 0 && desc->src1_from_scalar0 == 0u) {
        if (common->src1_dtype == NPU_DTYPE_INT4) {
            if (src1_elem != 0u) {
                return NPU_STATUS_BAD_DESC;
            }
        } else if (desc->length > 1u &&
                   src1_elem <
                       npu_wire_dtype_bytes(common->src1_dtype)) {
            return NPU_STATUS_BAD_SHAPE;
        }
        if (common->src1_dtype != NPU_DTYPE_INT4 && src1_nibble != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (desc->src1_from_scalar0 != 0u) {
        if (src1_used == 0) {
            return NPU_STATUS_BAD_DESC;
        }
        if (common->src1_dtype != NPU_DTYPE_INT4 ||
            common->src1_addr != 0u ||
            src1_elem != 0u || src1_row != 0u ||
            src1_nibble != 0u ||
            desc->broadcast1 != NPU_BROADCAST_NONE) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (common->src1_addr != 0u ||
               src1_elem != 0u || src1_row != 0u ||
               src1_nibble != 0u ||
               desc->broadcast1 != NPU_BROADCAST_NONE ||
               desc->src1_scale_bits != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    if (src2_used != 0 && desc->src2_from_scalar1 == 0u) {
        if (common->src2_dtype == NPU_DTYPE_INT4) {
            if (src2_elem != 0u) {
                return NPU_STATUS_BAD_DESC;
            }
        } else if (desc->length > 1u &&
                   src2_elem <
                       npu_wire_dtype_bytes(common->src2_dtype)) {
            return NPU_STATUS_BAD_SHAPE;
        }
        if (common->src2_dtype != NPU_DTYPE_INT4 && src2_nibble != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (desc->src2_from_scalar1 != 0u) {
        if (src2_used == 0) {
            return NPU_STATUS_BAD_DESC;
        }
        if (common->src2_dtype != NPU_DTYPE_INT4 ||
            common->src2_addr != 0u ||
            src2_elem != 0u || src2_row != 0u ||
            src2_nibble != 0u ||
            desc->broadcast2 != NPU_BROADCAST_NONE) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (common->src2_addr != 0u ||
               src2_elem != 0u || src2_row != 0u ||
               src2_nibble != 0u ||
               desc->broadcast2 != NPU_BROADCAST_NONE ||
               desc->src2_scale_bits != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    if (cmd->opcode == NPU_VECTOR_MUL) {
        if ((common->src0_dtype != NPU_DTYPE_INT4 &&
             common->src0_dtype != NPU_DTYPE_INT8 &&
             common->src0_dtype != NPU_DTYPE_INT16) ||
            (common->src1_dtype != NPU_DTYPE_INT4 &&
             common->src1_dtype != NPU_DTYPE_INT8 &&
             common->src1_dtype != NPU_DTYPE_INT16) ||
            common->dst_dtype != NPU_DTYPE_INT32) {
            return NPU_STATUS_DTYPE_UNSUPPORTED;
        }
    } else if (cmd->opcode == NPU_VECTOR_FMA) {
        if ((common->src0_dtype != NPU_DTYPE_INT4 &&
             common->src0_dtype != NPU_DTYPE_INT8 &&
             common->src0_dtype != NPU_DTYPE_INT16) ||
            (common->src1_dtype != NPU_DTYPE_INT4 &&
             common->src1_dtype != NPU_DTYPE_INT8 &&
             common->src1_dtype != NPU_DTYPE_INT16) ||
            common->src2_dtype != NPU_DTYPE_INT32 ||
            common->dst_dtype != NPU_DTYPE_INT32) {
            return NPU_STATUS_DTYPE_UNSUPPORTED;
        }
    } else if (cmd->opcode == NPU_VECTOR_CMP) {
        if (common->src0_dtype != common->src1_dtype ||
            common->dst_dtype != NPU_DTYPE_INT8) {
            return NPU_STATUS_DTYPE_UNSUPPORTED;
        }
    } else if (cmd->opcode == NPU_VECTOR_SELECT) {
        if (common->src0_dtype != common->src1_dtype ||
            common->dst_dtype != common->src0_dtype ||
            desc->mask_enable == 0u ||
            desc->mask_false_keep_dst != 0u) {
            return NPU_STATUS_DTYPE_UNSUPPORTED;
        }
    } else if (common->dst_dtype != common->src0_dtype ||
               (src1_used != 0 &&
                desc->src1_from_scalar0 == 0u &&
                common->src1_dtype != common->src0_dtype)) {
        return NPU_STATUS_DTYPE_UNSUPPORTED;
    }

    if (cmd->opcode != NPU_VECTOR_CMP && compare_mode != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (cmd->opcode == NPU_VECTOR_CLAMP) {
        if (desc->clamp_min > desc->clamp_max ||
            common->src1_addr != 0u ||
            common->src2_addr != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (cmd->opcode != NPU_VECTOR_ADD &&
               cmd->opcode != NPU_VECTOR_SUB &&
               cmd->opcode != NPU_VECTOR_MUL &&
               cmd->opcode != NPU_VECTOR_FMA &&
               desc->scalar0 != 0) {
        return NPU_STATUS_BAD_DESC;
    }
    if (cmd->opcode != NPU_VECTOR_CLAMP &&
        desc->src1_from_scalar0 == 0u &&
        desc->scalar0 != 0) {
        return NPU_STATUS_BAD_DESC;
    }
    if (cmd->opcode != NPU_VECTOR_CLAMP &&
        desc->src2_from_scalar1 == 0u &&
        desc->scalar1 != 0) {
        return NPU_STATUS_BAD_DESC;
    }

    if (desc->mask_enable != 0u) {
        if (mask_mode != 1u ||
            mask_elem != 1u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (mask_mode != 0u ||
               common->aux0_addr != 0u ||
               mask_elem != 0u ||
               mask_row != 0u ||
               desc->mask_false_keep_dst != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->mask_false_keep_dst != 0u &&
        (common->op_flags & NPU_WIRE_OP_ALLOW_INPLACE) == 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    if (!npu_wire_fp_positive_finite(desc->src0_scale_bits) ||
        !npu_wire_fp_positive_finite(desc->dst_scale_bits) ||
        (src1_used != 0 &&
         !npu_wire_fp_positive_finite(desc->src1_scale_bits)) ||
        (src2_used != 0 &&
         !npu_wire_fp_positive_finite(desc->src2_scale_bits))) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((cmd->opcode == NPU_VECTOR_ADD ||
         cmd->opcode == NPU_VECTOR_SUB ||
         cmd->opcode == NPU_VECTOR_MAX ||
         cmd->opcode == NPU_VECTOR_MIN ||
         cmd->opcode == NPU_VECTOR_CMP ||
         cmd->opcode == NPU_VECTOR_SELECT) &&
        (desc->src0_scale_bits != desc->src1_scale_bits ||
         (cmd->opcode != NPU_VECTOR_CMP &&
          desc->src0_scale_bits != desc->dst_scale_bits))) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((cmd->opcode == NPU_VECTOR_CLAMP ||
         cmd->opcode == NPU_VECTOR_RELU) &&
        desc->src0_scale_bits != desc->dst_scale_bits) {
        return NPU_STATUS_BAD_DESC;
    }

    status = npu_wire_check_address(
        NPU_SPACE_L1, common->src0_addr, 0u, limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (src1_used != 0 && desc->src1_from_scalar0 == 0u) {
        status = npu_wire_check_address(
            NPU_SPACE_L1, common->src1_addr, 0u, limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    if (src2_used != 0 && desc->src2_from_scalar1 == 0u) {
        status = npu_wire_check_address(
            NPU_SPACE_L1, common->src2_addr, 0u, limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    status = npu_wire_check_address(
        NPU_SPACE_L1, common->dst_addr, 0u, limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (desc->mask_enable != 0u) {
        status = npu_wire_check_address(
            NPU_SPACE_L1, common->aux0_addr, 0u, limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }

    limit = limits->l1_bytes;
    npu_wire_tensor_init(&desc->src0, NPU_SPACE_L1,
                         common->src0_dtype, common->src0_addr,
                         limit - common->src0_addr,
                         src0_row, src0_elem, 0u, src0_nibble);
    npu_wire_tensor_init(&desc->src1, NPU_SPACE_L1,
                         common->src1_dtype, common->src1_addr,
                         limit - common->src1_addr,
                         src1_row, src1_elem, 0u, src1_nibble);
    npu_wire_tensor_init(&desc->src2, NPU_SPACE_L1,
                         common->src2_dtype, common->src2_addr,
                         limit - common->src2_addr,
                         src2_row, src2_elem, 0u, src2_nibble);
    npu_wire_tensor_init(&desc->dst, NPU_SPACE_L1,
                         common->dst_dtype, common->dst_addr,
                         limit - common->dst_addr,
                         dst_row, dst_elem, 0u, dst_nibble);
    npu_wire_tensor_init(&desc->mask, NPU_SPACE_L1,
                         NPU_DTYPE_INT8, common->aux0_addr,
                         limit - common->aux0_addr,
                         mask_row, mask_elem, 0u, 0u);

    status = npu_wire_vector_tensor_check(&desc->src0,
                                          desc->broadcast0,
                                          desc->rows,
                                          desc->length,
                                          limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (src1_used != 0 && desc->src1_from_scalar0 == 0u) {
        status = npu_wire_vector_tensor_check(&desc->src1,
                                              desc->broadcast1,
                                              desc->rows,
                                              desc->length,
                                              limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    if (src2_used != 0 && desc->src2_from_scalar1 == 0u) {
        status = npu_wire_vector_tensor_check(&desc->src2,
                                              desc->broadcast2,
                                              desc->rows,
                                              desc->length,
                                              limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    status = npu_wire_vector_tensor_check(&desc->dst,
                                          NPU_BROADCAST_NONE,
                                          desc->rows,
                                          desc->length,
                                          limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (desc->mask_enable != 0u) {
        status = npu_wire_vector_tensor_check(&desc->mask,
                                              NPU_BROADCAST_NONE,
                                              desc->rows,
                                              desc->length,
                                              limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    return NPU_STATUS_SUCCESS;
}

static float npu_wire_float(uint32_t bits)
{
    npu_wire_float_bits_t value;

    value.bits = bits;
    return value.value;
}

static int npu_wire_complex_function_matches(uint8_t opcode,
                                             npu_function_t function)
{
    if (opcode == NPU_COMPLEX_ACT) {
        return function == NPU_FUNC_SIGMOID ||
               function == NPU_FUNC_TANH ||
               function == NPU_FUNC_GELU ||
               function == NPU_FUNC_SILU;
    }
    if (opcode == NPU_COMPLEX_SOFTMAX) {
        return function == NPU_FUNC_SOFTMAX;
    }
    if (opcode == NPU_COMPLEX_NORM) {
        return function == NPU_FUNC_LAYERNORM ||
               function == NPU_FUNC_RMSNORM;
    }
    if (opcode == NPU_COMPLEX_STAT) {
        return function == NPU_FUNC_STAT_SUM ||
               function == NPU_FUNC_STAT_MAX ||
               function == NPU_FUNC_STAT_SUMSQ;
    }
    if (opcode == NPU_COMPLEX_ADD_RESCALE) {
        return function == NPU_FUNC_ADD_RESCALE;
    }
    return 0;
}

static npu_status_t npu_wire_complex_validate_scale_table(
    uint64_t address,
    uint32_t length,
    const npu_wire_limits_t *limits,
    npu_wire_meta_t *meta)
{
    uint64_t bytes;

    if ((address & 3u) != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (!npu_wire_mul_u64(length, 4u, &bytes)) {
        npu_wire_record_unbounded_span_fault(
            meta, NPU_SPACE_L1, address, limits);
        return NPU_STATUS_ADDR_FAULT;
    }
    return npu_wire_check_address(
        NPU_SPACE_L1, address, bytes, limits, meta);
}

static npu_status_t npu_wire_decode_complex(
    const npu_cmd_t *cmd,
    const uint8_t *wire,
    const npu_wire_common_t *common,
    const npu_wire_limits_t *limits,
    npu_task_request_t *request,
    npu_wire_meta_t *meta)
{
    npu_complex_desc_t *desc = &request->desc.complex;
    uint32_t function_raw = npu_wire_u32(wire, 0x4cu);
    uint32_t src0_row = npu_wire_u32(wire, 0x50u);
    uint32_t src1_row = npu_wire_u32(wire, 0x54u);
    uint32_t src2_row = npu_wire_u32(wire, 0x58u);
    uint32_t dst_row = npu_wire_u32(wire, 0x5cu);
    uint64_t mask_addr = npu_wire_u64(wire, 0x60u);
    uint32_t mask_row = npu_wire_u32(wire, 0x68u);
    uint32_t mask_mode = npu_wire_u32(wire, 0x6cu);
    uint32_t src0_scale_bits = npu_wire_u32(wire, 0x70u);
    uint32_t src1_scale_bits = npu_wire_u32(wire, 0x74u);
    uint32_t src2_scale_bits = npu_wire_u32(wire, 0x78u);
    uint32_t dst_scale_bits = npu_wire_u32(wire, 0x7cu);
    uint32_t epsilon_bits = npu_wire_u32(wire, 0x90u);
    uint32_t clip_min_bits = npu_wire_u32(wire, 0x94u);
    uint32_t clip_max_bits = npu_wire_u32(wire, 0x98u);
    uint8_t approx_mode = wire[0x9cu];
    uint8_t overflow_mode = wire[0x9du];
    uint8_t all_mask_mode = wire[0x9eu];
    uint8_t stats_mode = wire[0x9fu];
    uint32_t rotary_dim = npu_wire_u32(wire, 0xa0u);
    uint32_t position_base = npu_wire_u32(wire, 0xa4u);
    uint32_t position_step = npu_wire_u32(wire, 0xa8u);
    uint8_t pair_mode = wire[0xacu];
    uint64_t valid_length_addr = npu_wire_u64(wire, 0xc0u);
    uint32_t valid_length_stride = npu_wire_u32(wire, 0xc8u);
    uint64_t src0_span;
    uint64_t src1_span = 0u;
    uint64_t src2_span = 0u;
    uint64_t dst_span;
    uint64_t span;
    uint64_t limit = limits->l1_bytes;
    int src1_used;
    int src2_used;
    uint32_t src1_rows;
    int fp_function;
    npu_status_t status;

    if (!npu_wire_zero_range(wire, 0xadu, 0xb0u) ||
        !npu_wire_zero_range(wire, 0xccu,
                             NPU_WIRE_COMPLEX_DESC_BYTES) ||
        (common->op_flags & 0x3fu) != 0u ||
        function_raw > NPU_FUNC_ADD_RESCALE ||
        mask_mode > NPU_MASK_VALID_LENGTH ||
        mask_mode == NPU_MASK_CAUSAL ||
        overflow_mode > NPU_OVERFLOW_WRAP ||
        all_mask_mode > NPU_ALL_MASK_ERROR ||
        stats_mode > 1u ||
        approx_mode != 0u ||
        pair_mode != 0u ||
        rotary_dim != 0u ||
        position_base != 0u ||
        position_step != 0u ||
        npu_wire_u32(wire, 0xb4u) != 0u ||
        npu_wire_u32(wire, 0xb8u) != 0u ||
        npu_wire_u32(wire, 0xbcu) != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    desc->rows = npu_wire_u32(wire, 0x40u);
    desc->length = npu_wire_u32(wire, 0x44u);
    desc->valid_length = npu_wire_u32(wire, 0x48u);
    desc->function = (npu_function_t)function_raw;
    desc->src0_scale = npu_wire_float(src0_scale_bits);
    desc->src1_scale = npu_wire_float(src1_scale_bits);
    desc->src2_scale = npu_wire_float(src2_scale_bits);
    desc->dst_scale = npu_wire_float(dst_scale_bits);
    desc->src0_zero_point = npu_wire_i32(wire, 0x80u);
    desc->src1_zero_point = npu_wire_i32(wire, 0x84u);
    desc->src2_zero_point = npu_wire_i32(wire, 0x88u);
    desc->dst_zero_point = npu_wire_i32(wire, 0x8cu);
    desc->epsilon = npu_wire_float(epsilon_bits);
    desc->input_clip_min = npu_wire_float(clip_min_bits);
    desc->input_clip_max = npu_wire_float(clip_max_bits);
    desc->round_mode = common->round_mode;
    desc->overflow_mode = (npu_overflow_mode_t)overflow_mode;
    desc->scale_mode = (npu_scale_mode_t)common->scale_mode;
    desc->mask_mode = (npu_mask_mode_t)mask_mode;
    desc->all_mask_mode = (npu_all_mask_mode_t)all_mask_mode;
    desc->src0_scale_table_addr = common->aux0_addr;
    desc->dst_scale_table_addr = common->aux1_addr;
    desc->scratch_request_elems = npu_wire_u32(wire, 0xb0u);
    desc->query_position_base = npu_wire_u32(wire, 0xb4u);
    desc->key_position_base = npu_wire_u32(wire, 0xb8u);
    desc->query_position_step = npu_wire_u32(wire, 0xbcu);
    desc->approx_mode = approx_mode;
    desc->stats_mode = stats_mode;
    desc->beta_enable =
        (uint8_t)(desc->function == NPU_FUNC_LAYERNORM);
    desc->strict_numeric =
        (uint8_t)((cmd->header_flags &
                   NPU_WIRE_FLAG_STRICT_NUMERIC) != 0u);

    meta->cme_approx_mode = approx_mode;
    meta->cme_stats_mode = stats_mode;
    meta->cme_src0_scale_table_addr = common->aux0_addr;
    meta->cme_dst_scale_table_addr = common->aux1_addr;

    if (!npu_wire_complex_function_matches(cmd->opcode,
                                           desc->function)) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->rows == 0u) {
        if (desc->valid_length != 0u) {
            return NPU_STATUS_BAD_SHAPE;
        }
    } else if (desc->length == 0u) {
        if (desc->valid_length != 0u ||
            cmd->opcode == NPU_COMPLEX_SOFTMAX ||
            cmd->opcode == NPU_COMPLEX_NORM ||
            cmd->opcode == NPU_COMPLEX_STAT) {
            return NPU_STATUS_BAD_SHAPE;
        }
    } else if (desc->valid_length == 0u ||
               desc->valid_length > desc->length) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (desc->length > NPU_REF_CME_MAX_LENGTH) {
        return NPU_STATUS_BAD_SHAPE;
    }
    if (desc->scratch_request_elems > limits->cme_scratch_elems) {
        return NPU_STATUS_BAD_DESC;
    }
    if ((cmd->opcode == NPU_COMPLEX_ACT ||
         cmd->opcode == NPU_COMPLEX_ADD_RESCALE ||
         cmd->opcode == NPU_COMPLEX_STAT) &&
        desc->scratch_request_elems != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (cmd->opcode != NPU_COMPLEX_NORM && stats_mode != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (stats_mode == 1u &&
        desc->function != NPU_FUNC_LAYERNORM) {
        return NPU_STATUS_BAD_DESC;
    }

    fp_function = cmd->opcode != NPU_COMPLEX_STAT;
    if ((fp_function != 0 &&
         (common->internal_fp32_enable == 0u ||
          common->saturate_enable == 0u ||
          common->scale_mode == 0u ||
          common->scale_mode == 2u ||
          overflow_mode != NPU_OVERFLOW_SATURATE)) ||
        (fp_function == 0 &&
         (common->internal_fp32_enable != 0u ||
          common->scale_mode != 0u ||
          common->saturate_enable !=
              (overflow_mode == NPU_OVERFLOW_SATURATE)))) {
        return NPU_STATUS_BAD_DESC;
    }
    if (desc->src0_zero_point != 0 ||
        desc->src1_zero_point != 0 ||
        desc->src2_zero_point != 0 ||
        desc->dst_zero_point != 0) {
        return NPU_STATUS_BAD_DESC;
    }

    src1_used = cmd->opcode == NPU_COMPLEX_NORM ||
                cmd->opcode == NPU_COMPLEX_ADD_RESCALE;
    src2_used = desc->function == NPU_FUNC_LAYERNORM;
    src1_rows = cmd->opcode == NPU_COMPLEX_ADD_RESCALE
                    ? desc->rows
                    : 1u;
    if (cmd->opcode == NPU_COMPLEX_STAT) {
        if (common->src1_addr != 0u ||
            common->src2_addr != 0u ||
            common->aux0_addr != 0u ||
            common->aux1_addr != 0u ||
            mask_addr != 0u ||
            mask_row != 0u ||
            mask_mode != NPU_MASK_NONE ||
            valid_length_addr != 0u ||
            valid_length_stride != 0u ||
            src0_scale_bits != 0u ||
            src1_scale_bits != 0u ||
            src2_scale_bits != 0u ||
            dst_scale_bits != 0u ||
            epsilon_bits != 0u ||
            clip_min_bits != 0u ||
            clip_max_bits != 0u ||
            common->dst_dtype != NPU_DTYPE_INT32 ||
            common->src1_dtype != NPU_DTYPE_INT4 ||
            common->src2_dtype != NPU_DTYPE_INT4 ||
            stats_mode != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else {
        if ((common->scale_mode == 1u &&
             (!npu_wire_fp_positive_finite(src0_scale_bits) ||
              !npu_wire_fp_positive_finite(dst_scale_bits))) ||
            (common->scale_mode == 3u &&
             (src0_scale_bits != 0u || dst_scale_bits != 0u)) ||
            (src1_used != 0 &&
             !npu_wire_fp_positive_finite(src1_scale_bits)) ||
            (src2_used != 0 &&
             !npu_wire_fp_positive_finite(src2_scale_bits))) {
            return NPU_STATUS_BAD_DESC;
        }
        if (src1_used == 0 &&
            (common->src1_addr != 0u ||
             src1_row != 0u ||
             src1_scale_bits != 0u ||
             common->src1_dtype != NPU_DTYPE_INT4)) {
            return NPU_STATUS_BAD_DESC;
        }
        if (src2_used == 0 &&
            (common->src2_addr != 0u ||
             src2_row != 0u ||
             src2_scale_bits != 0u ||
             common->src2_dtype != NPU_DTYPE_INT4)) {
            return NPU_STATUS_BAD_DESC;
        }
    }

    if (cmd->opcode == NPU_COMPLEX_NORM) {
        if (!npu_wire_fp_positive_finite(epsilon_bits) ||
            clip_min_bits != 0u ||
            clip_max_bits != 0u ||
            mask_mode != NPU_MASK_NONE ||
            mask_addr != 0u ||
            mask_row != 0u ||
            valid_length_addr != 0u ||
            valid_length_stride != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
        if (src1_row != 0u ||
            (desc->function == NPU_FUNC_LAYERNORM &&
             src2_row != 0u)) {
            return NPU_STATUS_BAD_DESC;
        }
        if (desc->function == NPU_FUNC_RMSNORM &&
            (common->src2_addr != 0u ||
             src2_scale_bits != 0u ||
             src2_row != 0u)) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (epsilon_bits != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    if (cmd->opcode == NPU_COMPLEX_ACT ||
        cmd->opcode == NPU_COMPLEX_SOFTMAX) {
        if (!npu_wire_fp_finite(clip_min_bits) ||
            !npu_wire_fp_finite(clip_max_bits) ||
            !(desc->input_clip_min < desc->input_clip_max)) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (clip_min_bits != 0u || clip_max_bits != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    if (cmd->opcode != NPU_COMPLEX_SOFTMAX) {
        if (mask_mode != NPU_MASK_NONE ||
            mask_addr != 0u ||
            mask_row != 0u ||
            valid_length_addr != 0u ||
            valid_length_stride != 0u ||
            all_mask_mode != NPU_ALL_MASK_WRITE_ZERO) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (mask_mode == NPU_MASK_BOOLEAN) {
        if (valid_length_addr != 0u ||
            valid_length_stride != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (mask_mode == NPU_MASK_VALID_LENGTH) {
        if (mask_addr != 0u ||
            mask_row != 0u ||
            valid_length_stride < 4u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (mask_addr != 0u ||
               mask_row != 0u ||
               valid_length_addr != 0u ||
               valid_length_stride != 0u) {
        return NPU_STATUS_BAD_DESC;
    }

    if (common->scale_mode == 1u) {
        if (common->aux0_addr != 0u ||
            common->aux1_addr != 0u) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if (common->scale_mode == 3u) {
        status = npu_wire_complex_validate_scale_table(
            common->aux0_addr, desc->length, limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
        status = npu_wire_complex_validate_scale_table(
            common->aux1_addr, desc->length, limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }

    status = npu_wire_check_address(
        NPU_SPACE_L1, common->src0_addr, 0u, limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (src1_used != 0) {
        status = npu_wire_check_address(
            NPU_SPACE_L1, common->src1_addr, 0u, limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    if (src2_used != 0) {
        status = npu_wire_check_address(
            NPU_SPACE_L1, common->src2_addr, 0u, limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    status = npu_wire_check_address(
        NPU_SPACE_L1, common->dst_addr, 0u, limits, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (mask_mode == NPU_MASK_BOOLEAN) {
        status = npu_wire_check_address(
            NPU_SPACE_L1, mask_addr, 0u, limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    if (mask_mode == NPU_MASK_VALID_LENGTH) {
        status = npu_wire_check_address(
            NPU_SPACE_L1, valid_length_addr, 0u, limits, meta);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }

    npu_wire_tensor_init(&desc->src0, NPU_SPACE_L1,
                         common->src0_dtype, common->src0_addr,
                         limit - common->src0_addr,
                         src0_row, 0u, 0u, 0u);
    npu_wire_tensor_init(&desc->src1, NPU_SPACE_L1,
                         common->src1_dtype, common->src1_addr,
                         limit - common->src1_addr,
                         src1_row, 0u, 0u, 0u);
    npu_wire_tensor_init(&desc->src2, NPU_SPACE_L1,
                         common->src2_dtype, common->src2_addr,
                         limit - common->src2_addr,
                         src2_row, 0u, 0u, 0u);
    npu_wire_tensor_init(&desc->dst, NPU_SPACE_L1,
                         common->dst_dtype, common->dst_addr,
                         limit - common->dst_addr,
                         dst_row, 0u, 0u, 0u);
    npu_wire_tensor_init(&desc->mask, NPU_SPACE_L1,
                         NPU_DTYPE_INT8, mask_addr,
                         limit - mask_addr,
                         mask_row, 1u, 0u, 0u);
    npu_wire_tensor_init(&desc->valid_lengths, NPU_SPACE_L1,
                         NPU_DTYPE_INT32, valid_length_addr,
                         limit - valid_length_addr,
                         valid_length_stride, 4u, 0u, 0u);

    status = npu_wire_validate_tensor(&desc->src0, 1u,
                                      desc->rows, desc->length,
                                      limits, meta, &src0_span);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    status = npu_wire_validate_tensor(&desc->dst, 1u,
                                      desc->rows, desc->length,
                                      limits, meta, &dst_span);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (src1_used != 0) {
        status = npu_wire_validate_tensor(&desc->src1, 1u, src1_rows,
                                          desc->length,
                                          limits, meta, &src1_span);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    if (src2_used != 0) {
        status = npu_wire_validate_tensor(&desc->src2, 1u, 1u,
                                          desc->length,
                                          limits, meta, &src2_span);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    if (mask_mode == NPU_MASK_BOOLEAN) {
        status = npu_wire_validate_tensor(&desc->mask, 1u,
                                          desc->rows, desc->length,
                                          limits, meta, &span);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }
    if (mask_mode == NPU_MASK_VALID_LENGTH) {
        status = npu_wire_validate_tensor(&desc->valid_lengths, 1u,
                                          desc->rows, 1u,
                                          limits, meta, &span);
        if (status != NPU_STATUS_SUCCESS) {
            return status;
        }
    }

    if (cmd->opcode == NPU_COMPLEX_ACT &&
        common->src0_addr == common->dst_addr) {
        if ((common->op_flags & NPU_WIRE_OP_ALLOW_INPLACE) == 0u ||
            common->src0_dtype != common->dst_dtype ||
            src0_row != dst_row) {
            return NPU_STATUS_BAD_DESC;
        }
    } else if ((common->op_flags & NPU_WIRE_OP_ALLOW_INPLACE) != 0u) {
        return NPU_STATUS_BAD_DESC;
    }
    if (!(cmd->opcode == NPU_COMPLEX_ACT &&
          common->src0_addr == common->dst_addr) &&
        npu_wire_ranges_overlap(common->src0_addr, src0_span,
                                common->dst_addr, dst_span)) {
        return NPU_STATUS_ADDR_OVERLAP;
    }
    if (src1_used != 0 &&
        npu_wire_ranges_overlap(common->src1_addr, src1_span,
                                common->dst_addr, dst_span)) {
        return NPU_STATUS_ADDR_OVERLAP;
    }
    if (src2_used != 0 &&
        npu_wire_ranges_overlap(common->src2_addr, src2_span,
                                common->dst_addr, dst_span)) {
        return NPU_STATUS_ADDR_OVERLAP;
    }
    return NPU_STATUS_SUCCESS;
}

npu_status_t npu_wire_decode_descriptor(const npu_cmd_t *cmd,
                                        const uint8_t *wire,
                                        size_t wire_bytes,
                                        const npu_wire_limits_t *limits,
                                        npu_task_request_t *request,
                                        npu_wire_meta_t *meta)
{
    npu_wire_common_t common;
    npu_status_t status;

    if (cmd == (const npu_cmd_t *)0 ||
        wire == (const uint8_t *)0 ||
        request == (npu_task_request_t *)0 ||
        meta == (npu_wire_meta_t *)0 ||
        !npu_wire_limits_valid(limits) ||
        !npu_wire_opcode_valid(cmd->engine, cmd->opcode)) {
        return NPU_STATUS_BAD_DESC;
    }
    npu_wire_clear(request, sizeof(*request));
    npu_wire_clear(meta, sizeof(*meta));
    request->cmd = *cmd;
    status = npu_wire_decode_common(cmd, wire, wire_bytes, limits,
                                    &common, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    request->cmd.user_tag = common.user_tag;
    request->desc_bytes = common.desc_bytes;
    request->desc_version = common.desc_version;
    request->allow_inplace = meta->allow_inplace;
    request->allow_partial_dest = meta->allow_partial_dest;

    if (cmd->engine == NPU_ENGINE_CONTROL) {
        return npu_wire_decode_control(cmd, &common, request, meta);
    }
    if (cmd->engine == NPU_ENGINE_DMA) {
        return npu_wire_decode_dma(cmd, wire, &common, limits,
                                   request, meta);
    }
    if (cmd->engine == NPU_ENGINE_MATRIX) {
        return npu_wire_decode_matrix(cmd, wire, &common, limits,
                                      request, meta);
    }
    if (cmd->engine == NPU_ENGINE_VECTOR) {
        return npu_wire_decode_vector(cmd, wire, &common, limits,
                                      request, meta);
    }
    if (cmd->engine == NPU_ENGINE_COMPLEX) {
        return npu_wire_decode_complex(cmd, wire, &common, limits,
                                       request, meta);
    }
    return NPU_STATUS_ILLEGAL_OPCODE;
}

npu_status_t npu_wire_decode_task(const uint8_t *cmd_wire,
                                  size_t cmd_wire_bytes,
                                  const uint8_t *desc_wire,
                                  size_t desc_wire_bytes,
                                  const npu_wire_limits_t *limits,
                                  npu_task_request_t *request,
                                  npu_wire_meta_t *meta)
{
    npu_cmd_t cmd;
    npu_status_t status;

    if (request == (npu_task_request_t *)0 ||
        meta == (npu_wire_meta_t *)0) {
        return NPU_STATUS_BAD_DESC;
    }
    npu_wire_clear(request, sizeof(*request));
    npu_wire_clear(meta, sizeof(*meta));
    status = npu_wire_decode_cmd_with_meta(
        cmd_wire, cmd_wire_bytes, limits, &cmd, meta);
    if (status != NPU_STATUS_SUCCESS) {
        return status;
    }
    if (cmd.inline_format != 0u) {
        return npu_inline_decode_task(
            &cmd, limits, request, meta);
    }
    return npu_wire_decode_descriptor(&cmd, desc_wire, desc_wire_bytes,
                                      limits, request, meta);
}
