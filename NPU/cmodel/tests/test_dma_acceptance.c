#include "test_util.h"

#include <limits.h>
#include <string.h>

#ifdef NPU_DMA_ACCEPTANCE_STANDALONE
#include <stdio.h>
#endif

#define DMA_ACCEPT_L1_BYTES NPU_REF_L1_BYTES
#define DMA_ACCEPT_DDR_BYTES (1024u * 1024u)
#define DMA_ACCEPT_SRC_ADDR UINT64_C(0x10000)
#define DMA_ACCEPT_DST_ADDR UINT64_C(0x20000)
#define DMA_ACCEPT_SEG_SRC_ADDR UINT64_C(0x30000)
#define DMA_ACCEPT_SEG_DST_ADDR UINT64_C(0x40000)
#define DMA_ACCEPT_MAX_SPAN 2048u
#define DMA_ACCEPT_SENTINEL 0xa5u

typedef struct {
    npu_dtype_t src_dtype;
    npu_dtype_t dst_dtype;
    npu_dma_convert_t mode;
} dma_accept_pair_t;

static uint8_t dma_accept_l1[DMA_ACCEPT_L1_BYTES];
static uint8_t dma_accept_ddr[DMA_ACCEPT_DDR_BYTES];
static npu_model_t dma_accept_model;
static npu_config_t dma_accept_config;

static uint8_t *dma_accept_space(npu_space_t space)
{
    if (space == NPU_SPACE_L1) {
        return dma_accept_l1;
    }
    if (space == NPU_SPACE_DDR) {
        return dma_accept_ddr;
    }
    return (uint8_t *)0;
}

static size_t dma_accept_space_size(npu_space_t space)
{
    if (space == NPU_SPACE_L1) {
        return sizeof(dma_accept_l1);
    }
    if (space == NPU_SPACE_DDR) {
        return sizeof(dma_accept_ddr);
    }
    return 0u;
}

static int dma_accept_init(void)
{
    npu_config_reference(&dma_accept_config);
    (void)memset(dma_accept_l1, 0, sizeof(dma_accept_l1));
    (void)memset(dma_accept_ddr, 0, sizeof(dma_accept_ddr));
    return npu_model_init(
               &dma_accept_model, &dma_accept_config,
               dma_accept_l1, sizeof(dma_accept_l1),
               dma_accept_ddr, sizeof(dma_accept_ddr)) ==
           NPU_STATUS_SUCCESS;
}

static uint32_t dma_accept_dtype_bytes(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT8) {
        return 1u;
    }
    if (dtype == NPU_DTYPE_INT32) {
        return 4u;
    }
    return 0u;
}

static uint64_t dma_accept_row_bytes(npu_dtype_t dtype,
                                     uint8_t start_nibble,
                                     uint32_t length)
{
    if (dtype == NPU_DTYPE_INT4) {
        return ((uint64_t)start_nibble + length + 1u) / 2u;
    }
    return (uint64_t)length * dma_accept_dtype_bytes(dtype);
}

static uint64_t dma_accept_span(const npu_dma_desc_t *desc,
                                int source)
{
    const uint32_t *stride =
        source != 0 ? desc->src_stride_bytes
                    : desc->dst_stride_bytes;
    npu_dtype_t dtype =
        source != 0 ? desc->src_dtype : desc->dst_dtype;
    uint8_t nibble =
        source != 0 ? desc->src_nibble : desc->dst_nibble;
    uint64_t span;
    uint32_t d;

    for (d = 0u; d < desc->rank; d++) {
        if (desc->shape[d] == 0u) {
            return 0u;
        }
    }
    span = dma_accept_row_bytes(
        dtype, nibble, desc->shape[desc->rank - 1u]);
    for (d = 0u; d + 1u < desc->rank; d++) {
        span +=
            (uint64_t)(desc->shape[d] - 1u) * stride[d];
    }
    return span;
}

static uint64_t dma_accept_payload(const npu_dma_desc_t *desc,
                                   int source)
{
    npu_dtype_t dtype =
        source != 0 ? desc->src_dtype : desc->dst_dtype;
    uint8_t nibble =
        source != 0 ? desc->src_nibble : desc->dst_nibble;
    uint64_t rows = 1u;
    uint32_t d;

    for (d = 0u; d < desc->rank; d++) {
        if (desc->shape[d] == 0u) {
            return 0u;
        }
    }
    for (d = 0u; d + 1u < desc->rank; d++) {
        rows *= desc->shape[d];
    }
    return rows *
           dma_accept_row_bytes(
               dtype, nibble,
               desc->shape[desc->rank - 1u]);
}

static uint64_t dma_accept_element_count(
    const npu_dma_desc_t *desc)
{
    uint64_t count = 1u;
    uint32_t d;

    for (d = 0u; d < desc->rank; d++) {
        count *= desc->shape[d];
    }
    return count;
}

static void dma_accept_index(const npu_dma_desc_t *desc,
                             uint64_t linear,
                             uint32_t index[NPU_MAX_DMA_RANK])
{
    uint32_t d;

    for (d = desc->rank; d != 0u; d--) {
        index[d - 1u] =
            (uint32_t)(linear % desc->shape[d - 1u]);
        linear /= desc->shape[d - 1u];
    }
    for (d = desc->rank; d < NPU_MAX_DMA_RANK; d++) {
        index[d] = 0u;
    }
}

static int dma_accept_location(
    const npu_dma_desc_t *desc,
    int source,
    const uint32_t index[NPU_MAX_DMA_RANK],
    uint64_t *addr,
    uint8_t *high)
{
    const uint32_t *stride =
        source != 0 ? desc->src_stride_bytes
                    : desc->dst_stride_bytes;
    npu_dtype_t dtype =
        source != 0 ? desc->src_dtype : desc->dst_dtype;
    uint8_t nibble =
        source != 0 ? desc->src_nibble : desc->dst_nibble;
    uint64_t value =
        source != 0 ? desc->src_addr : desc->dst_addr;
    uint32_t d;

    for (d = 0u; d + 1u < desc->rank; d++) {
        value += (uint64_t)index[d] * stride[d];
    }
    if (dtype == NPU_DTYPE_INT4) {
        uint64_t half =
            (uint64_t)nibble + index[desc->rank - 1u];
        value += half / 2u;
        *high = (uint8_t)(half & 1u);
    } else {
        value +=
            (uint64_t)index[desc->rank - 1u] *
            dma_accept_dtype_bytes(dtype);
        *high = 0u;
    }
    *addr = value;
    return 1;
}

static int dma_accept_store(npu_space_t space,
                            npu_dtype_t dtype,
                            uint64_t addr,
                            uint8_t high,
                            int32_t value)
{
    uint8_t *memory = dma_accept_space(space);
    size_t size = dma_accept_space_size(space);

    if (memory == (uint8_t *)0 || addr >= (uint64_t)size) {
        return 0;
    }
    if (dtype == NPU_DTYPE_INT4) {
        memory[(size_t)addr] =
            npu_int4_insert(memory[(size_t)addr], high, value);
        return 1;
    }
    if (dtype == NPU_DTYPE_INT8) {
        memory[(size_t)addr] = (uint8_t)value;
        return 1;
    }
    if (addr > (uint64_t)size - 4u) {
        return 0;
    }
    {
        uint32_t raw = (uint32_t)value;
        memory[(size_t)addr] = (uint8_t)raw;
        memory[(size_t)addr + 1u] = (uint8_t)(raw >> 8);
        memory[(size_t)addr + 2u] = (uint8_t)(raw >> 16);
        memory[(size_t)addr + 3u] = (uint8_t)(raw >> 24);
    }
    return 1;
}

static int dma_accept_load(npu_space_t space,
                           npu_dtype_t dtype,
                           uint64_t addr,
                           uint8_t high,
                           int32_t *value)
{
    const uint8_t *memory = dma_accept_space(space);
    size_t size = dma_accept_space_size(space);

    if (memory == (const uint8_t *)0 ||
        addr >= (uint64_t)size) {
        return 0;
    }
    if (dtype == NPU_DTYPE_INT4) {
        *value = npu_int4_unpack(memory[(size_t)addr], high);
        return 1;
    }
    if (dtype == NPU_DTYPE_INT8) {
        uint8_t raw = memory[(size_t)addr];
        if ((raw & 0x80u) != 0u) {
            *value = -1 - (int32_t)(0xffu - raw);
        } else {
            *value = raw;
        }
        return 1;
    }
    if (addr > (uint64_t)size - 4u) {
        return 0;
    }
    {
        uint32_t raw =
            (uint32_t)memory[(size_t)addr] |
            ((uint32_t)memory[(size_t)addr + 1u] << 8) |
            ((uint32_t)memory[(size_t)addr + 2u] << 16) |
            ((uint32_t)memory[(size_t)addr + 3u] << 24);
        if (raw <= (uint32_t)INT32_MAX) {
            *value = (int32_t)raw;
        } else {
            *value = -1 - (int32_t)(UINT32_MAX - raw);
        }
    }
    return 1;
}

static int dma_accept_write_element(
    const npu_dma_desc_t *desc,
    int source,
    const uint32_t index[NPU_MAX_DMA_RANK],
    int32_t value)
{
    npu_space_t space =
        source != 0 ? desc->src_space : desc->dst_space;
    npu_dtype_t dtype =
        source != 0 ? desc->src_dtype : desc->dst_dtype;
    uint64_t addr;
    uint8_t high;

    if (!dma_accept_location(
            desc, source, index, &addr, &high)) {
        return 0;
    }
    return dma_accept_store(space, dtype, addr, high, value);
}

static int dma_accept_read_element(
    const npu_dma_desc_t *desc,
    int source,
    const uint32_t index[NPU_MAX_DMA_RANK],
    int32_t *value)
{
    npu_space_t space =
        source != 0 ? desc->src_space : desc->dst_space;
    npu_dtype_t dtype =
        source != 0 ? desc->src_dtype : desc->dst_dtype;
    uint64_t addr;
    uint8_t high;

    if (!dma_accept_location(
            desc, source, index, &addr, &high)) {
        return 0;
    }
    return dma_accept_load(space, dtype, addr, high, value);
}

static int32_t dma_accept_clamp(int32_t value,
                                npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT4) {
        if (value < -8) {
            return -8;
        }
        if (value > 7) {
            return 7;
        }
    } else if (dtype == NPU_DTYPE_INT8) {
        if (value < -128) {
            return -128;
        }
        if (value > 127) {
            return 127;
        }
    }
    return value;
}

static int32_t dma_accept_source_value(
    const npu_dma_desc_t *desc,
    uint64_t linear)
{
    static const int32_t int4_values[] = {
        -8, -7, -1, 0, 1, 6, 7
    };
    static const int32_t int8_values[] = {
        -128, -127, -9, -8, -1, 0, 1, 7, 8, 126, 127
    };
    static const int32_t int32_values[] = {
        INT32_MIN, -1000, -129, -128, -9, -8, -1, 0,
        1, 7, 8, 127, 128, 1000, INT32_MAX
    };

    if (desc->convert_mode == NPU_DMA_PACK_INT4) {
        return int4_values[
            linear %
            (sizeof(int4_values) / sizeof(int4_values[0]))];
    }
    if (desc->src_dtype == NPU_DTYPE_INT4) {
        return int4_values[
            linear %
            (sizeof(int4_values) / sizeof(int4_values[0]))];
    }
    if (desc->src_dtype == NPU_DTYPE_INT8) {
        return int8_values[
            linear %
            (sizeof(int8_values) / sizeof(int8_values[0]))];
    }
    return int32_values[
        linear %
        (sizeof(int32_values) / sizeof(int32_values[0]))];
}

static int32_t dma_accept_expected_value(
    const npu_dma_desc_t *desc,
    uint64_t linear)
{
    int32_t value = dma_accept_source_value(desc, linear);

    if (desc->convert_mode == NPU_DMA_SATURATE_NARROW) {
        return dma_accept_clamp(value, desc->dst_dtype);
    }
    return value;
}

static void dma_accept_shapes(npu_dma_desc_t *desc,
                              uint8_t rank)
{
    uint32_t d;

    desc->rank = rank;
    for (d = 0u; d < NPU_MAX_DMA_RANK; d++) {
        desc->shape[d] = 0u;
    }
    for (d = 0u; d + 1u < rank; d++) {
        desc->shape[d] = 2u;
    }
    desc->shape[rank - 1u] =
        rank == 4u ? 3u : 5u;
}

static uint64_t dma_accept_build_strides(
    npu_dma_desc_t *desc,
    int source,
    uint32_t gap)
{
    uint32_t *stride =
        source != 0 ? desc->src_stride_bytes
                    : desc->dst_stride_bytes;
    npu_dtype_t dtype =
        source != 0 ? desc->src_dtype : desc->dst_dtype;
    uint8_t nibble =
        source != 0 ? desc->src_nibble : desc->dst_nibble;
    uint64_t inner =
        dma_accept_row_bytes(
            dtype, nibble,
            desc->shape[desc->rank - 1u]);
    uint32_t d;

    for (d = 0u; d < NPU_MAX_DMA_RANK; d++) {
        stride[d] = 0u;
    }
    for (d = desc->rank - 1u; d != 0u; d--) {
        uint32_t outer = d - 1u;
        stride[outer] = (uint32_t)(inner + gap + outer);
        inner =
            (uint64_t)(desc->shape[outer] - 1u) *
                stride[outer] +
            inner;
    }
    return inner;
}

static npu_dma_desc_t dma_accept_copy_desc(
    npu_dtype_t src_dtype,
    npu_dtype_t dst_dtype,
    npu_dma_convert_t mode,
    uint8_t rank)
{
    npu_dma_desc_t desc = {0};

    desc.src_space = NPU_SPACE_DDR;
    desc.dst_space = NPU_SPACE_L1;
    desc.src_dtype = src_dtype;
    desc.dst_dtype = dst_dtype;
    desc.convert_mode = mode;
    desc.src_addr = DMA_ACCEPT_SRC_ADDR;
    desc.dst_addr = DMA_ACCEPT_DST_ADDR;
    desc.src_nibble =
        src_dtype == NPU_DTYPE_INT4 ? 1u : 0u;
    desc.dst_nibble = 0u;
    desc.burst_beats = NPU_REF_DMA_MAX_BURST_BEATS;
    desc.max_outstanding = NPU_REF_DMA_OUTSTANDING;
    dma_accept_shapes(&desc, rank);
    desc.src_region_bytes =
        dma_accept_build_strides(&desc, 1, 3u);
    desc.dst_region_bytes =
        dma_accept_build_strides(&desc, 0, 5u);
    return desc;
}

static int dma_accept_prepare_copy(
    const npu_dma_desc_t *desc)
{
    uint8_t *src = dma_accept_space(desc->src_space);
    uint8_t *dst = dma_accept_space(desc->dst_space);
    uint64_t src_span = dma_accept_span(desc, 1);
    uint64_t dst_span = dma_accept_span(desc, 0);
    uint64_t count = dma_accept_element_count(desc);
    uint64_t linear;

    TEST_CHECK(src_span <= DMA_ACCEPT_MAX_SPAN);
    TEST_CHECK(dst_span <= DMA_ACCEPT_MAX_SPAN);
    (void)memset(
        src + (size_t)desc->src_addr, 0x3cu,
        (size_t)src_span);
    (void)memset(
        dst + (size_t)desc->dst_addr,
        DMA_ACCEPT_SENTINEL, (size_t)dst_span);
    for (linear = 0u; linear < count; linear++) {
        uint32_t index[NPU_MAX_DMA_RANK];
        dma_accept_index(desc, linear, index);
        TEST_CHECK(dma_accept_write_element(
            desc, 1, index,
            dma_accept_source_value(desc, linear)));
    }
    return 0;
}

static int dma_accept_check_storage(
    const npu_dma_desc_t *desc)
{
    uint8_t touched[DMA_ACCEPT_MAX_SPAN];
    uint8_t *dst = dma_accept_space(desc->dst_space);
    uint64_t span = dma_accept_span(desc, 0);
    uint64_t count = dma_accept_element_count(desc);
    uint64_t linear;
    uint64_t offset;

    TEST_CHECK(span <= sizeof(touched));
    (void)memset(touched, 0, sizeof(touched));
    for (linear = 0u; linear < count; linear++) {
        uint32_t index[NPU_MAX_DMA_RANK];
        uint64_t addr;
        uint8_t high;
        uint32_t bytes;
        uint32_t byte;

        dma_accept_index(desc, linear, index);
        TEST_CHECK(dma_accept_location(
            desc, 0, index, &addr, &high));
        TEST_CHECK(addr >= desc->dst_addr);
        offset = addr - desc->dst_addr;
        bytes =
            desc->dst_dtype == NPU_DTYPE_INT32 ? 4u : 1u;
        TEST_CHECK(offset + bytes <= sizeof(touched));
        for (byte = 0u; byte < bytes; byte++) {
            touched[(size_t)offset + byte] = 1u;
        }
        if (desc->dst_dtype == NPU_DTYPE_INT4 &&
            index[desc->rank - 1u] + 1u ==
                desc->shape[desc->rank - 1u] &&
            (desc->shape[desc->rank - 1u] & 1u) != 0u) {
            TEST_CHECK(high == 0u);
            TEST_CHECK(
                (dst[(size_t)addr] & 0xf0u) == 0u);
        }
    }
    for (offset = 0u; offset < span; offset++) {
        if (touched[(size_t)offset] == 0u) {
            TEST_CHECK(
                dst[(size_t)(desc->dst_addr + offset)] ==
                DMA_ACCEPT_SENTINEL);
        }
    }
    return 0;
}

static int dma_accept_check_copy(
    const npu_dma_desc_t *desc)
{
    uint64_t count = dma_accept_element_count(desc);
    uint64_t linear;

    for (linear = 0u; linear < count; linear++) {
        uint32_t index[NPU_MAX_DMA_RANK];
        int32_t actual;

        dma_accept_index(desc, linear, index);
        TEST_CHECK(dma_accept_read_element(
            desc, 0, index, &actual));
        TEST_CHECK(
            actual == dma_accept_expected_value(desc, linear));
    }
    return dma_accept_check_storage(desc);
}

static int dma_accept_run_copy(
    uint8_t opcode,
    const dma_accept_pair_t *pair,
    uint8_t rank)
{
    npu_dma_desc_t desc =
        dma_accept_copy_desc(
            pair->src_dtype, pair->dst_dtype,
            pair->mode, rank);
    uint64_t progress = UINT64_MAX;
    int line;

    line = dma_accept_prepare_copy(&desc);
    if (line != 0) {
        return line;
    }
    TEST_CHECK_STATUS(
        npu_dma_execute(
            &dma_accept_model, opcode, &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == dma_accept_payload(&desc, 0));
    return dma_accept_check_copy(&desc);
}

static int dma_accept_pair_valid(npu_dtype_t src_dtype,
                                 npu_dtype_t dst_dtype,
                                 npu_dma_convert_t mode)
{
    if (mode == NPU_DMA_CONVERT_NONE) {
        return src_dtype == dst_dtype;
    }
    if (mode == NPU_DMA_SIGN_EXTEND) {
        return
            (src_dtype == NPU_DTYPE_INT4 &&
             (dst_dtype == NPU_DTYPE_INT8 ||
              dst_dtype == NPU_DTYPE_INT32)) ||
            (src_dtype == NPU_DTYPE_INT8 &&
             dst_dtype == NPU_DTYPE_INT32);
    }
    if (mode == NPU_DMA_SATURATE_NARROW) {
        return
            (src_dtype == NPU_DTYPE_INT32 &&
             (dst_dtype == NPU_DTYPE_INT8 ||
              dst_dtype == NPU_DTYPE_INT4)) ||
            (src_dtype == NPU_DTYPE_INT8 &&
             dst_dtype == NPU_DTYPE_INT4);
    }
    return
        mode == NPU_DMA_PACK_INT4 &&
        (src_dtype == NPU_DTYPE_INT8 ||
         src_dtype == NPU_DTYPE_INT32) &&
        dst_dtype == NPU_DTYPE_INT4;
}

static int dma_accept_copy_modes(void)
{
    static const dma_accept_pair_t pairs[] = {
        {NPU_DTYPE_INT4, NPU_DTYPE_INT4,
         NPU_DMA_CONVERT_NONE},
        {NPU_DTYPE_INT8, NPU_DTYPE_INT8,
         NPU_DMA_CONVERT_NONE},
        {NPU_DTYPE_INT32, NPU_DTYPE_INT32,
         NPU_DMA_CONVERT_NONE},
        {NPU_DTYPE_INT4, NPU_DTYPE_INT8,
         NPU_DMA_SIGN_EXTEND},
        {NPU_DTYPE_INT4, NPU_DTYPE_INT32,
         NPU_DMA_SIGN_EXTEND},
        {NPU_DTYPE_INT8, NPU_DTYPE_INT32,
         NPU_DMA_SIGN_EXTEND},
        {NPU_DTYPE_INT32, NPU_DTYPE_INT8,
         NPU_DMA_SATURATE_NARROW},
        {NPU_DTYPE_INT32, NPU_DTYPE_INT4,
         NPU_DMA_SATURATE_NARROW},
        {NPU_DTYPE_INT8, NPU_DTYPE_INT4,
         NPU_DMA_SATURATE_NARROW},
        {NPU_DTYPE_INT8, NPU_DTYPE_INT4,
         NPU_DMA_PACK_INT4},
        {NPU_DTYPE_INT32, NPU_DTYPE_INT4,
         NPU_DMA_PACK_INT4}
    };
    size_t pair;
    uint8_t rank;

    for (pair = 0u;
         pair < sizeof(pairs) / sizeof(pairs[0]);
         pair++) {
        int line =
            dma_accept_run_copy(
                NPU_DMA_COPY_1D, &pairs[pair], 1u);
        if (line != 0) {
            return line;
        }
        for (rank = 1u; rank <= NPU_MAX_DMA_RANK; rank++) {
            line = dma_accept_run_copy(
                NPU_DMA_COPY_ND, &pairs[pair], rank);
            if (line != 0) {
                return line;
            }
        }
    }
    return 0;
}

static int dma_accept_invalid_pairs(void)
{
    int src;
    int dst;
    int mode;

    for (mode = NPU_DMA_CONVERT_NONE;
         mode <= NPU_DMA_PACK_INT4; mode++) {
        for (src = NPU_DTYPE_INT4;
             src <= NPU_DTYPE_INT32; src++) {
            for (dst = NPU_DTYPE_INT4;
                 dst <= NPU_DTYPE_INT32; dst++) {
                npu_dma_desc_t desc;
                uint8_t before[64];
                uint8_t *target;
                uint64_t progress = UINT64_MAX;
                uint64_t span;
                int line;

                if (dma_accept_pair_valid(
                        (npu_dtype_t)src,
                        (npu_dtype_t)dst,
                        (npu_dma_convert_t)mode)) {
                    continue;
                }
                desc = dma_accept_copy_desc(
                    (npu_dtype_t)src, (npu_dtype_t)dst,
                    (npu_dma_convert_t)mode, 1u);
                span = dma_accept_span(&desc, 0);
                TEST_CHECK(span <= sizeof(before));
                line = dma_accept_prepare_copy(&desc);
                if (line != 0) {
                    return line;
                }
                target =
                    dma_accept_space(desc.dst_space) +
                    (size_t)desc.dst_addr;
                (void)memcpy(before, target, (size_t)span);
                TEST_CHECK_STATUS(
                    npu_dma_execute(
                        &dma_accept_model,
                        NPU_DMA_COPY_1D,
                        &desc, &progress),
                    NPU_STATUS_DTYPE_UNSUPPORTED);
                TEST_CHECK(progress == 0u);
                TEST_CHECK(
                    memcmp(before, target, (size_t)span) == 0);
            }
        }
    }
    return 0;
}

static int32_t dma_accept_fill_expected(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT4) {
        return -3;
    }
    if (dtype == NPU_DTYPE_INT8) {
        return -126;
    }
    return -1000;
}

static uint64_t dma_accept_fill_bits(npu_dtype_t dtype)
{
    if (dtype == NPU_DTYPE_INT4) {
        return UINT64_C(0xd);
    }
    if (dtype == NPU_DTYPE_INT8) {
        return UINT64_C(0x82);
    }
    return UINT64_C(0xfffffc18);
}

static int dma_accept_fill(void)
{
    int dtype;
    uint8_t rank;

    for (dtype = NPU_DTYPE_INT4;
         dtype <= NPU_DTYPE_INT32; dtype++) {
        for (rank = 1u; rank <= NPU_MAX_DMA_RANK; rank++) {
            npu_dma_desc_t desc = {0};
            uint64_t count;
            uint64_t linear;
            uint64_t progress = UINT64_MAX;

            desc.src_space = NPU_SPACE_L1;
            desc.dst_space = NPU_SPACE_L1;
            desc.src_dtype = NPU_DTYPE_INT4;
            desc.dst_dtype = (npu_dtype_t)dtype;
            desc.convert_mode = NPU_DMA_CONVERT_NONE;
            desc.dst_addr = DMA_ACCEPT_DST_ADDR;
            desc.fill_value =
                dma_accept_fill_bits((npu_dtype_t)dtype);
            desc.burst_beats =
                NPU_REF_DMA_MAX_BURST_BEATS;
            desc.max_outstanding =
                NPU_REF_DMA_OUTSTANDING;
            dma_accept_shapes(&desc, rank);
            desc.dst_region_bytes =
                dma_accept_build_strides(&desc, 0, 7u);
            (void)memset(
                dma_accept_l1 + (size_t)desc.dst_addr,
                DMA_ACCEPT_SENTINEL,
                (size_t)desc.dst_region_bytes);
            TEST_CHECK_STATUS(
                npu_dma_execute(
                    &dma_accept_model, NPU_DMA_FILL,
                    &desc, &progress),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(
                progress == dma_accept_payload(&desc, 0));
            count = dma_accept_element_count(&desc);
            for (linear = 0u; linear < count; linear++) {
                uint32_t index[NPU_MAX_DMA_RANK];
                int32_t actual;

                dma_accept_index(&desc, linear, index);
                TEST_CHECK(dma_accept_read_element(
                    &desc, 0, index, &actual));
                TEST_CHECK(
                    actual ==
                    dma_accept_fill_expected(
                        (npu_dtype_t)dtype));
            }
            {
                int line = dma_accept_check_storage(&desc);
                if (line != 0) {
                    return line;
                }
            }
        }
    }
    return 0;
}

static int dma_accept_zero_sizes(void)
{
    uint8_t rank;
    int dtype;

    for (rank = 1u; rank <= NPU_MAX_DMA_RANK; rank++) {
        npu_dma_desc_t copy = {0};
        npu_dma_desc_t fill;
        uint8_t before[32];
        uint64_t progress = UINT64_MAX;
        uint32_t d;

        copy.rank = rank;
        copy.src_space = NPU_SPACE_DDR;
        copy.dst_space = NPU_SPACE_L1;
        copy.src_dtype = NPU_DTYPE_INT8;
        copy.dst_dtype = NPU_DTYPE_INT8;
        copy.convert_mode = NPU_DMA_CONVERT_NONE;
        copy.src_addr = DMA_ACCEPT_SRC_ADDR;
        copy.dst_addr = DMA_ACCEPT_DST_ADDR;
        copy.burst_beats = NPU_REF_DMA_MAX_BURST_BEATS;
        copy.max_outstanding = NPU_REF_DMA_OUTSTANDING;
        for (d = 0u; d < rank; d++) {
            copy.shape[d] = 1u;
        }
        copy.shape[rank - 1u] = 0u;
        (void)memset(
            dma_accept_l1 + (size_t)copy.dst_addr,
            DMA_ACCEPT_SENTINEL, sizeof(before));
        (void)memcpy(
            before,
            dma_accept_l1 + (size_t)copy.dst_addr,
            sizeof(before));
        TEST_CHECK_STATUS(
            npu_dma_execute(
                &dma_accept_model,
                rank == 1u ? NPU_DMA_COPY_1D
                           : NPU_DMA_COPY_ND,
                &copy, &progress),
            NPU_STATUS_SUCCESS);
        TEST_CHECK(progress == 0u);
        TEST_CHECK(
            memcmp(
                before,
                dma_accept_l1 + (size_t)copy.dst_addr,
                sizeof(before)) == 0);

        fill = copy;
        fill.src_space = NPU_SPACE_L1;
        fill.src_dtype = NPU_DTYPE_INT4;
        fill.src_addr = 0u;
        fill.fill_value = UINT64_C(0x55);
        progress = UINT64_MAX;
        TEST_CHECK_STATUS(
            npu_dma_execute(
                &dma_accept_model, NPU_DMA_FILL,
                &fill, &progress),
            NPU_STATUS_SUCCESS);
        TEST_CHECK(progress == 0u);
        TEST_CHECK(
            memcmp(
                before,
                dma_accept_l1 + (size_t)fill.dst_addr,
                sizeof(before)) == 0);
    }

    for (dtype = NPU_DTYPE_INT4;
         dtype <= NPU_DTYPE_INT32; dtype++) {
        uint32_t which;

        for (which = 0u; which < 2u; which++) {
            npu_dma_desc_t desc = {0};
            uint8_t before[32];
            uint64_t progress = UINT64_MAX;

            desc.rank = 2u;
            desc.src_space = NPU_SPACE_DDR;
            desc.dst_space = NPU_SPACE_L1;
            desc.src_dtype = (npu_dtype_t)dtype;
            desc.dst_dtype = (npu_dtype_t)dtype;
            desc.convert_mode = NPU_DMA_CONVERT_NONE;
            desc.src_addr = DMA_ACCEPT_SRC_ADDR;
            desc.dst_addr = DMA_ACCEPT_DST_ADDR;
            desc.shape[0] = which == 0u ? 0u : 3u;
            desc.shape[1] = which == 0u ? 3u : 0u;
            desc.src_stride_bytes[0] = 8u;
            desc.dst_stride_bytes[0] = 8u;
            desc.src_nibble =
                dtype == NPU_DTYPE_INT4 ? 1u : 0u;
            desc.burst_beats =
                NPU_REF_DMA_MAX_BURST_BEATS;
            desc.max_outstanding =
                NPU_REF_DMA_OUTSTANDING;
            (void)memset(
                dma_accept_l1 + (size_t)desc.dst_addr,
                DMA_ACCEPT_SENTINEL, sizeof(before));
            (void)memcpy(
                before,
                dma_accept_l1 + (size_t)desc.dst_addr,
                sizeof(before));
            TEST_CHECK_STATUS(
                npu_dma_execute(
                    &dma_accept_model,
                    NPU_DMA_TRANSPOSE_2D,
                    &desc, &progress),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(progress == 0u);
            TEST_CHECK(
                memcmp(
                    before,
                    dma_accept_l1 + (size_t)desc.dst_addr,
                    sizeof(before)) == 0);
        }
    }
    return 0;
}

static int dma_accept_transpose(void)
{
    int dtype;

    for (dtype = NPU_DTYPE_INT4;
         dtype <= NPU_DTYPE_INT32; dtype++) {
        npu_dma_desc_t desc = {0};
        uint8_t touched[DMA_ACCEPT_MAX_SPAN];
        uint64_t src_row;
        uint64_t dst_row;
        uint64_t progress = UINT64_MAX;
        uint64_t span;
        uint32_t row;
        uint32_t col;
        uint64_t offset;

        desc.rank = 2u;
        desc.src_space = NPU_SPACE_DDR;
        desc.dst_space = NPU_SPACE_L1;
        desc.src_dtype = (npu_dtype_t)dtype;
        desc.dst_dtype = (npu_dtype_t)dtype;
        desc.convert_mode = NPU_DMA_CONVERT_NONE;
        desc.src_addr = DMA_ACCEPT_SRC_ADDR;
        desc.dst_addr = DMA_ACCEPT_DST_ADDR;
        desc.shape[0] = 3u;
        desc.shape[1] = 5u;
        desc.src_nibble =
            dtype == NPU_DTYPE_INT4 ? 1u : 0u;
        desc.dst_nibble = 0u;
        src_row = dma_accept_row_bytes(
            desc.src_dtype, desc.src_nibble, desc.shape[1]);
        dst_row = dma_accept_row_bytes(
            desc.dst_dtype, desc.dst_nibble, desc.shape[0]);
        desc.src_stride_bytes[0] = (uint32_t)(src_row + 3u);
        desc.dst_stride_bytes[0] = (uint32_t)(dst_row + 5u);
        desc.src_region_bytes =
            (uint64_t)(desc.shape[0] - 1u) *
                desc.src_stride_bytes[0] +
            src_row;
        desc.dst_region_bytes =
            (uint64_t)(desc.shape[1] - 1u) *
                desc.dst_stride_bytes[0] +
            dst_row;
        desc.burst_beats = NPU_REF_DMA_MAX_BURST_BEATS;
        desc.max_outstanding = NPU_REF_DMA_OUTSTANDING;
        (void)memset(
            dma_accept_ddr + (size_t)desc.src_addr,
            0x3c, (size_t)desc.src_region_bytes);
        (void)memset(
            dma_accept_l1 + (size_t)desc.dst_addr,
            DMA_ACCEPT_SENTINEL,
            (size_t)desc.dst_region_bytes);
        for (row = 0u; row < desc.shape[0]; row++) {
            for (col = 0u; col < desc.shape[1]; col++) {
                uint32_t index[NPU_MAX_DMA_RANK] = {
                    row, col, 0u, 0u, 0u
                };
                uint64_t linear =
                    (uint64_t)row * desc.shape[1] + col;
                TEST_CHECK(dma_accept_write_element(
                    &desc, 1, index,
                    dma_accept_source_value(&desc, linear)));
            }
        }
        TEST_CHECK_STATUS(
            npu_dma_execute(
                &dma_accept_model,
                NPU_DMA_TRANSPOSE_2D,
                &desc, &progress),
            NPU_STATUS_SUCCESS);
        TEST_CHECK(
            progress ==
            (uint64_t)desc.shape[1] * dst_row);

        span = desc.dst_region_bytes;
        TEST_CHECK(span <= sizeof(touched));
        (void)memset(touched, 0, sizeof(touched));
        for (col = 0u; col < desc.shape[1]; col++) {
            for (row = 0u; row < desc.shape[0]; row++) {
                uint64_t addr =
                    desc.dst_addr +
                    (uint64_t)col *
                        desc.dst_stride_bytes[0];
                uint8_t high = 0u;
                uint32_t bytes =
                    dtype == NPU_DTYPE_INT32 ? 4u : 1u;
                uint32_t byte;
                int32_t actual;
                int32_t expected =
                    dma_accept_source_value(
                        &desc,
                        (uint64_t)row *
                            desc.shape[1] +
                        col);

                if (dtype == NPU_DTYPE_INT4) {
                    addr += row / 2u;
                    high = (uint8_t)(row & 1u);
                } else {
                    addr +=
                        (uint64_t)row *
                        dma_accept_dtype_bytes(
                            (npu_dtype_t)dtype);
                }
                TEST_CHECK(dma_accept_load(
                    NPU_SPACE_L1, (npu_dtype_t)dtype,
                    addr, high, &actual));
                TEST_CHECK(actual == expected);
                offset = addr - desc.dst_addr;
                for (byte = 0u; byte < bytes; byte++) {
                    touched[(size_t)offset + byte] = 1u;
                }
            }
            if (dtype == NPU_DTYPE_INT4) {
                uint64_t tail =
                    desc.dst_addr +
                    (uint64_t)col *
                        desc.dst_stride_bytes[0] +
                    (desc.shape[0] - 1u) / 2u;
                TEST_CHECK(
                    (dma_accept_l1[(size_t)tail] &
                     0xf0u) == 0u);
            }
        }
        for (offset = 0u; offset < span; offset++) {
            if (touched[(size_t)offset] == 0u) {
                TEST_CHECK(
                    dma_accept_l1[
                        (size_t)(desc.dst_addr + offset)] ==
                    DMA_ACCEPT_SENTINEL);
            }
        }
    }
    return 0;
}

static npu_dma_desc_t dma_accept_segment_desc(
    npu_dtype_t dtype,
    uint8_t opcode)
{
    npu_dma_desc_t desc = {0};
    uint64_t packed;
    uint64_t spaced;

    desc.rank = 1u;
    desc.src_space = NPU_SPACE_L1;
    desc.dst_space = NPU_SPACE_L1;
    desc.src_dtype = dtype;
    desc.dst_dtype = dtype;
    desc.convert_mode = NPU_DMA_CONVERT_NONE;
    desc.src_addr = DMA_ACCEPT_SEG_SRC_ADDR;
    desc.dst_addr = DMA_ACCEPT_SEG_DST_ADDR;
    desc.segment_count = 3u;
    desc.segment_bytes = 5u;
    desc.segment_stride = 9u;
    desc.shape[0] = desc.segment_count;
    desc.burst_beats = NPU_REF_DMA_MAX_BURST_BEATS;
    desc.max_outstanding = NPU_REF_DMA_OUTSTANDING;
    packed =
        (uint64_t)desc.segment_count * desc.segment_bytes;
    spaced =
        (uint64_t)(desc.segment_count - 1u) *
            desc.segment_stride +
        desc.segment_bytes;
    if (opcode == NPU_DMA_PACK) {
        desc.src_region_bytes = spaced;
        desc.dst_region_bytes = packed;
    } else {
        desc.src_region_bytes = packed;
        desc.dst_region_bytes = spaced;
    }
    return desc;
}

static int dma_accept_segments(void)
{
    int dtype;
    uint8_t opcode;

    for (dtype = NPU_DTYPE_INT4;
         dtype <= NPU_DTYPE_INT32; dtype++) {
        for (opcode = NPU_DMA_PACK;
             opcode <= NPU_DMA_SPLIT; opcode++) {
            npu_dma_desc_t desc =
                dma_accept_segment_desc(
                    (npu_dtype_t)dtype, opcode);
            uint64_t progress = UINT64_MAX;
            uint32_t segment;
            uint32_t byte;
            uint64_t offset;

            (void)memset(
                dma_accept_l1 + (size_t)desc.src_addr,
                0x31, (size_t)desc.src_region_bytes);
            (void)memset(
                dma_accept_l1 + (size_t)desc.dst_addr,
                DMA_ACCEPT_SENTINEL,
                (size_t)desc.dst_region_bytes);
            for (segment = 0u;
                 segment < desc.segment_count; segment++) {
                for (byte = 0u;
                     byte < desc.segment_bytes; byte++) {
                    uint64_t src_offset =
                        opcode == NPU_DMA_PACK
                            ? (uint64_t)segment *
                                  desc.segment_stride +
                                  byte
                            : (uint64_t)segment *
                                  desc.segment_bytes +
                                  byte;
                    dma_accept_l1[
                        (size_t)(desc.src_addr + src_offset)] =
                        (uint8_t)(
                            0x40u + segment * 0x10u + byte);
                }
            }
            TEST_CHECK_STATUS(
                npu_dma_execute(
                    &dma_accept_model, opcode,
                    &desc, &progress),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(
                progress ==
                (uint64_t)desc.segment_count *
                    desc.segment_bytes);
            for (segment = 0u;
                 segment < desc.segment_count; segment++) {
                for (byte = 0u;
                     byte < desc.segment_bytes; byte++) {
                    uint64_t dst_offset =
                        opcode == NPU_DMA_PACK
                            ? (uint64_t)segment *
                                  desc.segment_bytes +
                                  byte
                            : (uint64_t)segment *
                                  desc.segment_stride +
                                  byte;
                    TEST_CHECK(
                        dma_accept_l1[
                            (size_t)(desc.dst_addr +
                                     dst_offset)] ==
                        (uint8_t)(
                            0x40u + segment * 0x10u + byte));
                }
            }
            if (opcode == NPU_DMA_SPLIT) {
                for (offset = 0u;
                     offset < desc.dst_region_bytes;
                     offset++) {
                    uint32_t within =
                        (uint32_t)(
                            offset % desc.segment_stride);
                    uint32_t segment_index =
                        (uint32_t)(
                            offset / desc.segment_stride);
                    if (segment_index <
                            desc.segment_count &&
                        within < desc.segment_bytes) {
                        continue;
                    }
                    TEST_CHECK(
                        dma_accept_l1[
                            (size_t)(desc.dst_addr +
                                     offset)] ==
                        DMA_ACCEPT_SENTINEL);
                }
            }
        }
    }
    return 0;
}

static int dma_accept_error_no_write(
    uint8_t opcode,
    const npu_dma_desc_t *desc,
    npu_status_t expected)
{
    uint8_t before[64];
    uint8_t *target =
        dma_accept_space(desc->dst_space) +
        (size_t)desc->dst_addr;
    uint64_t progress = UINT64_MAX;

    (void)memset(target, DMA_ACCEPT_SENTINEL, sizeof(before));
    (void)memcpy(before, target, sizeof(before));
    TEST_CHECK_STATUS(
        npu_dma_execute(
            &dma_accept_model, opcode, desc, &progress),
        expected);
    TEST_CHECK(progress == 0u);
    TEST_CHECK(memcmp(before, target, sizeof(before)) == 0);
    return 0;
}

static int dma_accept_overlap(void)
{
    npu_dma_desc_t desc =
        dma_accept_copy_desc(
            NPU_DTYPE_INT8, NPU_DTYPE_INT8,
            NPU_DMA_CONVERT_NONE, 1u);
    uint64_t progress = UINT64_MAX;
    uint64_t linear;
    int line;

    desc.shape[0] = 7u;
    desc.src_addr = UINT64_C(0x50000);
    desc.dst_addr = UINT64_C(0x50000);
    desc.src_region_bytes = 7u;
    desc.dst_region_bytes = 7u;
    (void)memset(
        dma_accept_ddr + (size_t)desc.src_addr, 0, 7u);
    (void)memset(
        dma_accept_l1 + (size_t)desc.dst_addr,
        DMA_ACCEPT_SENTINEL, 7u);
    for (linear = 0u; linear < 7u; linear++) {
        dma_accept_ddr[(size_t)desc.src_addr + (size_t)linear] =
            (uint8_t)(linear + 1u);
    }
    TEST_CHECK_STATUS(
        npu_dma_execute(
            &dma_accept_model, NPU_DMA_COPY_1D,
            &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 7u);
    for (linear = 0u; linear < 7u; linear++) {
        TEST_CHECK(
            dma_accept_l1[
                (size_t)desc.dst_addr + (size_t)linear] ==
            (uint8_t)(linear + 1u));
    }

    desc.src_space = NPU_SPACE_L1;
    desc.src_addr = UINT64_C(0x51000);
    desc.dst_addr = UINT64_C(0x51007);
    desc.src_region_bytes = 7u;
    desc.dst_region_bytes = 7u;
    for (linear = 0u; linear < 7u; linear++) {
        dma_accept_l1[
            (size_t)desc.src_addr + (size_t)linear] =
            (uint8_t)(0x20u + linear);
    }
    progress = UINT64_MAX;
    TEST_CHECK_STATUS(
        npu_dma_execute(
            &dma_accept_model, NPU_DMA_COPY_1D,
            &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == 7u);

    desc.src_addr = UINT64_C(0x52000);
    desc.dst_addr = UINT64_C(0x52000);
    line = dma_accept_error_no_write(
        NPU_DMA_COPY_1D, &desc,
        NPU_STATUS_ADDR_OVERLAP);
    if (line != 0) {
        return line;
    }
    desc.src_addr = UINT64_C(0x52100);
    desc.dst_addr = UINT64_C(0x52103);
    line = dma_accept_error_no_write(
        NPU_DMA_COPY_1D, &desc,
        NPU_STATUS_ADDR_OVERLAP);
    if (line != 0) {
        return line;
    }
    desc.src_addr = UINT64_C(0x52203);
    desc.dst_addr = UINT64_C(0x52200);
    line = dma_accept_error_no_write(
        NPU_DMA_COPY_1D, &desc,
        NPU_STATUS_ADDR_OVERLAP);
    if (line != 0) {
        return line;
    }
    return 0;
}

static int dma_accept_static_errors(void)
{
    npu_dma_desc_t desc;
    int line;

    desc = dma_accept_copy_desc(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8,
        NPU_DMA_CONVERT_NONE, 1u);
    desc.rank = 0u;
    line = dma_accept_error_no_write(
        NPU_DMA_COPY_1D, &desc, NPU_STATUS_BAD_DESC);
    if (line != 0) {
        return line;
    }

    desc = dma_accept_copy_desc(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8,
        NPU_DMA_CONVERT_NONE, 2u);
    line = dma_accept_error_no_write(
        NPU_DMA_COPY_1D, &desc, NPU_STATUS_BAD_SHAPE);
    if (line != 0) {
        return line;
    }

    desc = dma_accept_copy_desc(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8,
        NPU_DMA_CONVERT_NONE, 2u);
    desc.src_stride_bytes[0] = 0u;
    line = dma_accept_error_no_write(
        NPU_DMA_COPY_ND, &desc, NPU_STATUS_BAD_SHAPE);
    if (line != 0) {
        return line;
    }

    desc = dma_accept_copy_desc(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8,
        NPU_DMA_CONVERT_NONE, 1u);
    desc.dst_region_bytes--;
    line = dma_accept_error_no_write(
        NPU_DMA_COPY_1D, &desc, NPU_STATUS_ADDR_FAULT);
    if (line != 0) {
        return line;
    }

    desc = dma_accept_copy_desc(
        NPU_DTYPE_INT8, NPU_DTYPE_INT32,
        NPU_DMA_SIGN_EXTEND, 2u);
    line = dma_accept_error_no_write(
        NPU_DMA_TRANSPOSE_2D, &desc, NPU_STATUS_BAD_DESC);
    if (line != 0) {
        return line;
    }

    desc = dma_accept_segment_desc(
        NPU_DTYPE_INT8, NPU_DMA_PACK);
    desc.shape[0]++;
    line = dma_accept_error_no_write(
        NPU_DMA_PACK, &desc, NPU_STATUS_BAD_SHAPE);
    if (line != 0) {
        return line;
    }

    desc = dma_accept_segment_desc(
        NPU_DTYPE_INT8, NPU_DMA_PACK);
    desc.segment_stride = desc.segment_bytes - 1u;
    line = dma_accept_error_no_write(
        NPU_DMA_PACK, &desc, NPU_STATUS_BAD_DESC);
    if (line != 0) {
        return line;
    }

    desc = dma_accept_segment_desc(
        NPU_DTYPE_INT8, NPU_DMA_PACK);
    desc.segment_count = 0u;
    desc.shape[0] = 0u;
    line = dma_accept_error_no_write(
        NPU_DMA_PACK, &desc, NPU_STATUS_BAD_DESC);
    if (line != 0) {
        return line;
    }

    desc = dma_accept_segment_desc(
        NPU_DTYPE_INT8, NPU_DMA_SPLIT);
    desc.segment_bytes = 0u;
    line = dma_accept_error_no_write(
        NPU_DMA_SPLIT, &desc, NPU_STATUS_BAD_DESC);
    if (line != 0) {
        return line;
    }

    desc = (npu_dma_desc_t){0};
    desc.rank = 1u;
    desc.src_space = NPU_SPACE_L1;
    desc.dst_space = NPU_SPACE_L1;
    desc.src_dtype = NPU_DTYPE_INT4;
    desc.dst_dtype = NPU_DTYPE_INT8;
    desc.convert_mode = NPU_DMA_CONVERT_NONE;
    desc.src_addr = UINT64_C(1);
    desc.dst_addr = DMA_ACCEPT_DST_ADDR;
    desc.dst_region_bytes = 5u;
    desc.shape[0] = 5u;
    desc.fill_value = UINT64_C(0x44);
    desc.burst_beats = NPU_REF_DMA_MAX_BURST_BEATS;
    desc.max_outstanding = NPU_REF_DMA_OUTSTANDING;
    line = dma_accept_error_no_write(
        NPU_DMA_FILL, &desc, NPU_STATUS_BAD_DESC);
    if (line != 0) {
        return line;
    }
    return 0;
}

static int dma_accept_pack_int4_error(void)
{
    npu_dma_desc_t desc =
        dma_accept_copy_desc(
            NPU_DTYPE_INT8, NPU_DTYPE_INT4,
            NPU_DMA_PACK_INT4, 1u);
    static const int32_t values[5] = {1, -8, 7, 8, -1};
    uint8_t before[32];
    uint64_t progress = UINT64_MAX;
    uint64_t read_before;
    uint32_t index;

    desc.shape[0] = 5u;
    desc.src_region_bytes = 5u;
    desc.dst_region_bytes = 3u;
    (void)memset(
        dma_accept_l1 + (size_t)desc.dst_addr,
        DMA_ACCEPT_SENTINEL, sizeof(before));
    (void)memcpy(
        before,
        dma_accept_l1 + (size_t)desc.dst_addr,
        sizeof(before));
    for (index = 0u; index < 5u; index++) {
        dma_accept_ddr[(size_t)desc.src_addr + index] =
            (uint8_t)values[index];
    }
    read_before = dma_accept_model.perf.dma_read_bytes;
    TEST_CHECK_STATUS(
        npu_dma_execute(
            &dma_accept_model, NPU_DMA_COPY_1D,
            &desc, &progress),
        NPU_STATUS_NUMERIC_EXCEPTION);
    TEST_CHECK(progress == 0u);
    TEST_CHECK(
        dma_accept_model.perf.dma_read_bytes ==
        read_before + 4u);
    TEST_CHECK(
        memcmp(
            before,
            dma_accept_l1 + (size_t)desc.dst_addr,
            sizeof(before)) == 0);
    return 0;
}

int test_dma_acceptance(void)
{
    int line;

    TEST_CHECK(dma_accept_init());

    line = dma_accept_copy_modes();
    if (line != 0) {
        return line;
    }
    line = dma_accept_invalid_pairs();
    if (line != 0) {
        return line;
    }
    line = dma_accept_fill();
    if (line != 0) {
        return line;
    }
    line = dma_accept_zero_sizes();
    if (line != 0) {
        return line;
    }
    line = dma_accept_transpose();
    if (line != 0) {
        return line;
    }
    line = dma_accept_segments();
    if (line != 0) {
        return line;
    }
    line = dma_accept_overlap();
    if (line != 0) {
        return line;
    }
    line = dma_accept_static_errors();
    if (line != 0) {
        return line;
    }
    line = dma_accept_pack_int4_error();
    if (line != 0) {
        return line;
    }
    return 0;
}

#ifdef NPU_DMA_ACCEPTANCE_STANDALONE
int main(void)
{
    int line = test_dma_acceptance();

    if (line == 0) {
        (void)printf("[PASS] dma_acceptance\n");
        return 0;
    }
    (void)printf(
        "[FAIL] dma_acceptance at test line %d\n", line);
    return 1;
}
#endif
