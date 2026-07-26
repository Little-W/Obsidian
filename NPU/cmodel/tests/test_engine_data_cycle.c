#include "npu_engine_data_cycle.h"
#include "test_util.h"

#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define DATA_TEST_DDR_BYTES (64u * 1024u)
#define DATA_TEST_TRACE_ENTRIES 64u
#define DATA_TEST_TRACE_HASH 128u
#define DATA_TEST_MAX_CYCLES 20000u

#define DATA_TEST_SRC0 0x0100u
#define DATA_TEST_SRC1 0x0200u
#define DATA_TEST_DST 0x0300u
#define DATA_TEST_DMA_DST 0x0400u
#define DATA_TEST_DDR_SRC 0x0800u
#define DATA_TEST_MATRIX_A 0x1000u
#define DATA_TEST_MATRIX_B 0x1100u
#define DATA_TEST_MATRIX_BIAS 0x1180u
#define DATA_TEST_MATRIX_DST 0x1200u
#define DATA_TEST_COMPLEX_SRC0 0x1300u
#define DATA_TEST_COMPLEX_SRC1 0x1400u
#define DATA_TEST_COMPLEX_SRC2 0x1500u
#define DATA_TEST_COMPLEX_DST 0x1600u
#define DATA_TEST_COMPLEX_MASK 0x1700u

typedef struct {
    uint8_t valid[NPU_ENGINE_DESC_TAGS];
    uint8_t word[NPU_ENGINE_DESC_TAGS];
    uint8_t count;
} data_test_desc_server_t;

typedef struct {
    uint8_t valid;
    uint16_t tag;
    uint32_t addr;
    uint16_t beats;
    uint16_t beat;
    uint8_t response_pause;
    uint8_t response_status;
} data_test_l1_read_t;

typedef struct {
    data_test_l1_read_t
        read[NPU_ENGINE_DATA_READ_PORTS];
    uint8_t write_req_valid;
    uint16_t write_tag;
    uint32_t write_addr;
    uint16_t write_beats;
    uint16_t write_data_count;
    uint16_t write_committed_count;
    uint64_t write_data[NPU_L1_CYCLE_MAX_BEATS];
    uint8_t write_strb[NPU_L1_CYCLE_MAX_BEATS];
    uint8_t write_last[NPU_L1_CYCLE_MAX_BEATS];
    uint8_t write_response_valid;
    uint8_t write_response_pause;
    uint8_t write_response_status;
} data_test_l1_t;

typedef struct {
    uint8_t read_valid;
    uint16_t read_tag;
    uint64_t read_addr;
    uint16_t read_beats;
    uint16_t read_beat;
    uint8_t response_pause;
    uint8_t response_status;
} data_test_mif_t;

static uint8_t data_test_l1[NPU_REF_L1_BYTES];
static uint8_t data_test_ddr[DATA_TEST_DDR_BYTES];
static npu_bus_trace_entry_t
    data_test_read_entries[DATA_TEST_TRACE_ENTRIES];
static npu_bus_trace_entry_t
    data_test_write_entries[DATA_TEST_TRACE_ENTRIES];
static uint32_t
    data_test_read_hash[DATA_TEST_TRACE_HASH];
static uint32_t
    data_test_write_hash[DATA_TEST_TRACE_HASH];

static int data_test_workspace_validation(void)
{
    npu_bus_trace_entry_t read_entries[4];
    npu_bus_trace_entry_t read_entries_snapshot[4];
    npu_bus_trace_entry_t write_entries[4];
    npu_bus_trace_entry_t write_entries_snapshot[4];
    uint32_t read_hash[8];
    uint32_t read_hash_snapshot[8];
    uint32_t write_hash[8];
    uint32_t write_hash_snapshot[8];
    npu_engine_data_workspace_t workspace;
    npu_engine_data_workspace_t workspace_snapshot;
    npu_engine_data_workspace_t candidate;

    (void)memset(read_entries, 0x11, sizeof(read_entries));
    (void)memset(write_entries, 0x22, sizeof(write_entries));
    (void)memset(read_hash, 0x33, sizeof(read_hash));
    (void)memset(write_hash, 0x44, sizeof(write_hash));
    workspace.read_entries = read_entries;
    workspace.read_capacity = 4u;
    workspace.read_hash = read_hash;
    workspace.read_hash_slots = 8u;
    workspace.write_entries = write_entries;
    workspace.write_capacity = 4u;
    workspace.write_hash = write_hash;
    workspace.write_hash_slots = 8u;
    workspace_snapshot = workspace;
    (void)memcpy(
        read_entries_snapshot, read_entries,
        sizeof(read_entries));
    (void)memcpy(
        write_entries_snapshot, write_entries,
        sizeof(write_entries));
    (void)memcpy(
        read_hash_snapshot, read_hash, sizeof(read_hash));
    (void)memcpy(
        write_hash_snapshot, write_hash, sizeof(write_hash));

    TEST_CHECK(npu_engine_data_workspace_valid(
                   (const npu_engine_data_workspace_t *)0) == 0);
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &workspace) != 0);

    candidate = workspace;
    candidate.read_entries = (npu_bus_trace_entry_t *)0;
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &candidate) == 0);
    candidate = workspace;
    candidate.read_capacity = 0u;
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &candidate) == 0);
    candidate = workspace;
    candidate.read_hash = (uint32_t *)0;
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &candidate) == 0);
    candidate = workspace;
    candidate.read_hash_slots = 0u;
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &candidate) == 0);
    candidate = workspace;
    candidate.read_hash_slots = 6u;
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &candidate) == 0);
    candidate = workspace;
    candidate.read_hash_slots = 2u;
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &candidate) == 0);

    candidate = workspace;
    candidate.write_entries = (npu_bus_trace_entry_t *)0;
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &candidate) == 0);
    candidate = workspace;
    candidate.write_capacity = 0u;
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &candidate) == 0);
    candidate = workspace;
    candidate.write_hash = (uint32_t *)0;
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &candidate) == 0);
    candidate = workspace;
    candidate.write_hash_slots = 0u;
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &candidate) == 0);
    candidate = workspace;
    candidate.write_hash_slots = 6u;
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &candidate) == 0);
    candidate = workspace;
    candidate.write_hash_slots = 2u;
    TEST_CHECK(npu_engine_data_workspace_valid(
                   &candidate) == 0);

    TEST_CHECK(memcmp(
                   &workspace, &workspace_snapshot,
                   sizeof(workspace)) == 0);
    TEST_CHECK(memcmp(
                   read_entries, read_entries_snapshot,
                   sizeof(read_entries)) == 0);
    TEST_CHECK(memcmp(
                   write_entries, write_entries_snapshot,
                   sizeof(write_entries)) == 0);
    TEST_CHECK(memcmp(
                   read_hash, read_hash_snapshot,
                   sizeof(read_hash)) == 0);
    TEST_CHECK(memcmp(
                   write_hash, write_hash_snapshot,
                   sizeof(write_hash)) == 0);
    return 0;
}

static void data_test_put_u16(uint8_t *data,
                              size_t offset,
                              uint16_t value)
{
    data[offset] = (uint8_t)value;
    data[offset + 1u] = (uint8_t)(value >> 8u);
}

static void data_test_put_u32(uint8_t *data,
                              size_t offset,
                              uint32_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 4u; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static void data_test_put_u64(uint8_t *data,
                              size_t offset,
                              uint64_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        data[offset + byte] =
            (uint8_t)(value >> (byte * 8u));
    }
}

static uint64_t data_test_get_u64(const uint8_t *data,
                                  uint32_t addr)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        value |= (uint64_t)data[addr + byte] <<
                 (byte * 8u);
    }
    return value;
}

static uint64_t data_test_descriptor_word(
    const uint8_t *descriptor,
    uint8_t word)
{
    uint64_t value = 0u;
    size_t offset = (size_t)word * NPU_REF_BUS_BYTES;
    uint32_t byte;

    for (byte = 0u; byte < NPU_REF_BUS_BYTES; byte++) {
        value |= (uint64_t)descriptor[offset + byte] <<
                 (byte * 8u);
    }
    return value;
}

static uint32_t data_test_numeric(
    npu_dtype_t src0,
    npu_dtype_t src1,
    npu_dtype_t src2,
    npu_dtype_t dst)
{
    return (uint32_t)src0 |
           ((uint32_t)src1 << 2u) |
           ((uint32_t)src2 << 4u) |
           ((uint32_t)dst << 6u) |
           ((uint32_t)NPU_ROUND_NEAREST_EVEN << 10u) |
           (UINT32_C(1) << 12u) |
           ((uint32_t)NPU_SCALE_PER_TENSOR << 13u);
}

static uint32_t data_test_numeric_full(
    npu_dtype_t src0,
    npu_dtype_t src1,
    npu_dtype_t src2,
    npu_dtype_t dst,
    npu_round_mode_t round_mode,
    uint8_t saturate,
    npu_scale_mode_t scale_mode,
    uint8_t internal_fp32)
{
    return (uint32_t)src0 |
           ((uint32_t)src1 << 2u) |
           ((uint32_t)src2 << 4u) |
           ((uint32_t)dst << 6u) |
           ((uint32_t)round_mode << 10u) |
           ((uint32_t)(saturate & 1u) << 12u) |
           ((uint32_t)scale_mode << 13u) |
           ((uint32_t)(internal_fp32 & 1u) << 16u);
}

static void data_test_vector_descriptor(uint8_t *descriptor)
{
    uint32_t numeric = data_test_numeric(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8,
        NPU_DTYPE_INT4, NPU_DTYPE_INT8);

    (void)memset(
        descriptor, 0, NPU_WIRE_VECTOR_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_VECTOR;
    data_test_put_u16(
        descriptor, 0x02u, NPU_WIRE_VECTOR_DESC_BYTES);
    data_test_put_u64(descriptor, 0x08u, DATA_TEST_SRC0);
    data_test_put_u64(descriptor, 0x10u, DATA_TEST_SRC1);
    data_test_put_u64(descriptor, 0x20u, DATA_TEST_DST);
    data_test_put_u32(descriptor, 0x38u, numeric);
    data_test_put_u32(descriptor, 0x3cu, 0x12345678u);
    data_test_put_u32(descriptor, 0x40u, 1u);
    data_test_put_u32(descriptor, 0x44u, 4u);
    data_test_put_u32(descriptor, 0x48u, 4u);
    data_test_put_u32(descriptor, 0x50u, 1u);
    data_test_put_u32(descriptor, 0x54u, 4u);
    data_test_put_u32(descriptor, 0x58u, 1u);
    data_test_put_u32(descriptor, 0x5cu, 4u);
    data_test_put_u32(descriptor, 0x68u, 1u);
    data_test_put_u32(descriptor, 0x6cu, 4u);
    descriptor[0x79u] = NPU_COMPARE_EQ;
    descriptor[0x7au] = NPU_OVERFLOW_SATURATE;
    data_test_put_u32(descriptor, 0x80u, 0x3f800000u);
    data_test_put_u32(descriptor, 0x84u, 0x3f800000u);
    data_test_put_u32(descriptor, 0x8cu, 0x3f800000u);
}

static void data_test_dma_descriptor(uint8_t *descriptor)
{
    uint32_t numeric =
        (uint32_t)NPU_DTYPE_INT8 |
        ((uint32_t)NPU_DTYPE_INT4 << 2u) |
        ((uint32_t)NPU_DTYPE_INT4 << 4u) |
        ((uint32_t)NPU_DTYPE_INT8 << 6u);

    (void)memset(
        descriptor, 0, NPU_WIRE_DMA_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_DMA;
    data_test_put_u16(
        descriptor, 0x02u, NPU_WIRE_DMA_DESC_BYTES);
    data_test_put_u32(descriptor, 0x04u, 1u);
    data_test_put_u64(
        descriptor, 0x08u, DATA_TEST_DDR_SRC);
    data_test_put_u64(
        descriptor, 0x20u, DATA_TEST_DMA_DST);
    data_test_put_u32(descriptor, 0x38u, numeric);
    data_test_put_u32(descriptor, 0x3cu, 0x44554131u);
    descriptor[0x40u] = 1u;
    descriptor[0x41u] = NPU_SPACE_DDR;
    descriptor[0x42u] = NPU_SPACE_L1;
    descriptor[0x43u] = NPU_DMA_CONVERT_NONE;
    descriptor[0x44u] =
        NPU_REF_DMA_MAX_BURST_BEATS - 1u;
    descriptor[0x45u] = NPU_REF_DMA_OUTSTANDING;
    data_test_put_u32(descriptor, 0x48u, 2u);
    data_test_put_u64(descriptor, 0x98u, 2u);
    data_test_put_u64(descriptor, 0xa0u, 2u);
}

static void data_test_matrix_descriptor(uint8_t *descriptor)
{
    uint32_t numeric = data_test_numeric_full(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8,
        NPU_DTYPE_INT4, NPU_DTYPE_INT32,
        NPU_ROUND_NEAREST_EVEN, 0u, NPU_SCALE_NONE,
        0u);

    (void)memset(
        descriptor, 0, NPU_WIRE_MATRIX_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_MATRIX;
    data_test_put_u16(
        descriptor, 0x02u, NPU_WIRE_MATRIX_DESC_BYTES);
    data_test_put_u64(
        descriptor, 0x08u, DATA_TEST_MATRIX_A);
    data_test_put_u64(
        descriptor, 0x10u, DATA_TEST_MATRIX_B);
    data_test_put_u64(
        descriptor, 0x20u, DATA_TEST_MATRIX_DST);
    data_test_put_u64(
        descriptor, 0x28u, DATA_TEST_MATRIX_BIAS);
    data_test_put_u32(descriptor, 0x38u, numeric);
    data_test_put_u32(descriptor, 0x3cu, 0x4d415452u);
    data_test_put_u32(descriptor, 0x40u, 1u);
    data_test_put_u32(descriptor, 0x44u, 1u);
    data_test_put_u32(descriptor, 0x48u, 2u);
    data_test_put_u32(descriptor, 0x4cu, 1u);
    data_test_put_u32(descriptor, 0x50u, 1u);
    data_test_put_u32(descriptor, 0x54u, 1u);
    data_test_put_u32(descriptor, 0x58u, 2u);
    data_test_put_u32(
        descriptor, 0x5cu,
        (UINT32_C(1) << 7u) | (UINT32_C(1) << 2u));
    data_test_put_u32(descriptor, 0x60u, 2u);
    data_test_put_u32(descriptor, 0x68u, 4u);
    data_test_put_u32(descriptor, 0x6cu, 4u);
    descriptor[0x90u] = 0u;
    descriptor[0x91u] = 2u;
    descriptor[0x92u] = 4u;
    descriptor[0x93u] = 0u;
    descriptor[0x94u] = NPU_OVERFLOW_SATURATE;
    data_test_put_u32(descriptor, 0xa0u, 1u);
    descriptor[0xa6u] = 8u;
}

static void data_test_matrix_int16_descriptor(
    uint8_t *descriptor)
{
    uint32_t numeric = data_test_numeric_full(
        NPU_DTYPE_INT16, NPU_DTYPE_INT16,
        NPU_DTYPE_INT4, NPU_DTYPE_INT32,
        NPU_ROUND_NEAREST_EVEN, 0u, NPU_SCALE_NONE,
        0u);

    (void)memset(
        descriptor, 0, NPU_WIRE_MATRIX_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_MATRIX;
    data_test_put_u16(
        descriptor, 0x02u, NPU_WIRE_MATRIX_DESC_BYTES);
    data_test_put_u64(
        descriptor, 0x08u, DATA_TEST_MATRIX_A);
    data_test_put_u64(
        descriptor, 0x10u, DATA_TEST_MATRIX_B);
    data_test_put_u64(
        descriptor, 0x20u, DATA_TEST_MATRIX_DST);
    data_test_put_u32(descriptor, 0x38u, numeric);
    data_test_put_u32(descriptor, 0x3cu, 0x4931364du);
    data_test_put_u32(descriptor, 0x40u, 1u);
    data_test_put_u32(descriptor, 0x44u, 8u);
    data_test_put_u32(descriptor, 0x48u, 16u);
    data_test_put_u32(descriptor, 0x4cu, 1u);
    data_test_put_u32(descriptor, 0x50u, 1u);
    data_test_put_u32(descriptor, 0x54u, 8u);
    data_test_put_u32(descriptor, 0x58u, 16u);
    data_test_put_u32(
        descriptor, 0x5cu, UINT32_C(1) << 7u);
    data_test_put_u32(descriptor, 0x60u, 32u);
    data_test_put_u32(descriptor, 0x68u, 32u);
    descriptor[0x90u] = 5u;
    descriptor[0x91u] = 6u;
    descriptor[0x92u] = 4u;
    descriptor[0x93u] = 0u;
    descriptor[0x94u] = NPU_OVERFLOW_SATURATE;
    descriptor[0xa6u] = 8u;
}

static void data_test_matrix_zero_descriptor(
    uint8_t *descriptor)
{
    uint32_t numeric = data_test_numeric_full(
        NPU_DTYPE_INT4, NPU_DTYPE_INT4,
        NPU_DTYPE_INT4, NPU_DTYPE_INT32,
        NPU_ROUND_NEAREST_EVEN, 0u, NPU_SCALE_NONE,
        0u);

    (void)memset(
        descriptor, 0, NPU_WIRE_MATRIX_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_MATRIX;
    data_test_put_u16(
        descriptor, 0x02u, NPU_WIRE_MATRIX_DESC_BYTES);
    data_test_put_u64(
        descriptor, 0x20u, DATA_TEST_MATRIX_DST);
    data_test_put_u32(descriptor, 0x38u, numeric);
    data_test_put_u32(descriptor, 0x3cu, 0x5a45524fu);
    data_test_put_u32(descriptor, 0x40u, 1u);
    data_test_put_u32(descriptor, 0x44u, 2u);
    data_test_put_u32(descriptor, 0x48u, 0u);
    data_test_put_u32(descriptor, 0x4cu, 1u);
    data_test_put_u32(descriptor, 0x50u, 1u);
    data_test_put_u32(descriptor, 0x54u, 2u);
    data_test_put_u32(descriptor, 0x58u, 0u);
    data_test_put_u32(descriptor, 0x68u, 8u);
    descriptor[0x90u] = 1u;
    descriptor[0x91u] = 3u;
    descriptor[0x92u] = 4u;
    descriptor[0x93u] = 0u;
    descriptor[0x94u] = NPU_OVERFLOW_SATURATE;
    descriptor[0xa6u] = 8u;
}

static void data_test_complex_descriptor(uint8_t *descriptor)
{
    uint32_t numeric = data_test_numeric_full(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8,
        NPU_DTYPE_INT8, NPU_DTYPE_INT8,
        NPU_ROUND_NEAREST_EVEN, 1u,
        NPU_SCALE_PER_TENSOR, 1u);

    (void)memset(
        descriptor, 0, NPU_WIRE_COMPLEX_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_COMPLEX;
    data_test_put_u16(
        descriptor, 0x02u, NPU_WIRE_COMPLEX_DESC_BYTES);
    data_test_put_u64(
        descriptor, 0x08u, DATA_TEST_COMPLEX_SRC0);
    data_test_put_u64(
        descriptor, 0x10u, DATA_TEST_COMPLEX_SRC1);
    data_test_put_u64(
        descriptor, 0x18u, DATA_TEST_COMPLEX_SRC2);
    data_test_put_u64(
        descriptor, 0x20u, DATA_TEST_COMPLEX_DST);
    data_test_put_u32(descriptor, 0x38u, numeric);
    data_test_put_u32(descriptor, 0x3cu, 0x434d4552u);
    data_test_put_u32(descriptor, 0x40u, 1u);
    data_test_put_u32(descriptor, 0x44u, 4u);
    data_test_put_u32(descriptor, 0x48u, 4u);
    data_test_put_u32(
        descriptor, 0x4cu, NPU_FUNC_LAYERNORM);
    data_test_put_u32(descriptor, 0x50u, 4u);
    data_test_put_u32(descriptor, 0x5cu, 4u);
    data_test_put_u32(descriptor, 0x6cu, NPU_MASK_NONE);
    data_test_put_u32(descriptor, 0x70u, 0x3f800000u);
    data_test_put_u32(descriptor, 0x74u, 0x3f800000u);
    data_test_put_u32(descriptor, 0x78u, 0x3f800000u);
    data_test_put_u32(descriptor, 0x7cu, 0x3d800000u);
    data_test_put_u32(descriptor, 0x90u, 0x3727c5acu);
    descriptor[0x9du] = NPU_OVERFLOW_SATURATE;
    descriptor[0x9eu] = NPU_ALL_MASK_WRITE_ZERO;
    data_test_put_u32(descriptor, 0xb0u, 4u);
}

static void data_test_stat_descriptor(uint8_t *descriptor)
{
    uint32_t numeric = data_test_numeric_full(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4,
        NPU_DTYPE_INT4, NPU_DTYPE_INT32,
        NPU_ROUND_NEAREST_EVEN, 1u, NPU_SCALE_NONE,
        0u);

    (void)memset(
        descriptor, 0, NPU_WIRE_COMPLEX_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_COMPLEX;
    data_test_put_u16(
        descriptor, 0x02u, NPU_WIRE_COMPLEX_DESC_BYTES);
    data_test_put_u64(
        descriptor, 0x08u, DATA_TEST_COMPLEX_SRC0);
    data_test_put_u64(
        descriptor, 0x20u, DATA_TEST_COMPLEX_DST);
    data_test_put_u32(descriptor, 0x38u, numeric);
    data_test_put_u32(descriptor, 0x3cu, 0x53544154u);
    data_test_put_u32(descriptor, 0x40u, 1u);
    data_test_put_u32(descriptor, 0x44u, 5u);
    data_test_put_u32(descriptor, 0x48u, 5u);
    data_test_put_u32(
        descriptor, 0x4cu, NPU_FUNC_STAT_SUM);
    data_test_put_u32(descriptor, 0x50u, 5u);
    data_test_put_u32(descriptor, 0x5cu, 4u);
    descriptor[0x9du] = NPU_OVERFLOW_SATURATE;
}

static void data_test_activation_descriptor(
    uint8_t *descriptor)
{
    uint32_t numeric = data_test_numeric_full(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4,
        NPU_DTYPE_INT4, NPU_DTYPE_INT8,
        NPU_ROUND_NEAREST_EVEN, 1u,
        NPU_SCALE_PER_TENSOR, 1u);

    (void)memset(
        descriptor, 0, NPU_WIRE_COMPLEX_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_COMPLEX;
    data_test_put_u16(
        descriptor, 0x02u, NPU_WIRE_COMPLEX_DESC_BYTES);
    data_test_put_u64(
        descriptor, 0x08u, DATA_TEST_COMPLEX_SRC0);
    data_test_put_u64(
        descriptor, 0x20u, DATA_TEST_COMPLEX_DST);
    data_test_put_u32(descriptor, 0x38u, numeric);
    data_test_put_u32(descriptor, 0x3cu, 0x41435456u);
    data_test_put_u32(descriptor, 0x40u, 1u);
    data_test_put_u32(descriptor, 0x44u, 9u);
    data_test_put_u32(descriptor, 0x48u, 9u);
    data_test_put_u32(
        descriptor, 0x4cu, NPU_FUNC_SIGMOID);
    data_test_put_u32(descriptor, 0x50u, 9u);
    data_test_put_u32(descriptor, 0x5cu, 9u);
    data_test_put_u32(descriptor, 0x70u, 0x3f800000u);
    data_test_put_u32(descriptor, 0x7cu, 0x3f800000u);
    data_test_put_u32(descriptor, 0x94u, 0xc1800000u);
    data_test_put_u32(descriptor, 0x98u, 0x41800000u);
    descriptor[0x9du] = NPU_OVERFLOW_SATURATE;
}

static void data_test_rmsnorm_descriptor(uint8_t *descriptor)
{
    uint32_t numeric = data_test_numeric_full(
        NPU_DTYPE_INT8, NPU_DTYPE_INT8,
        NPU_DTYPE_INT4, NPU_DTYPE_INT8,
        NPU_ROUND_NEAREST_EVEN, 1u,
        NPU_SCALE_PER_TENSOR, 1u);

    data_test_complex_descriptor(descriptor);
    data_test_put_u64(descriptor, 0x18u, 0u);
    data_test_put_u32(descriptor, 0x38u, numeric);
    data_test_put_u32(
        descriptor, 0x4cu, NPU_FUNC_RMSNORM);
    data_test_put_u32(descriptor, 0x78u, 0u);
}

static void data_test_softmax_descriptor(uint8_t *descriptor)
{
    uint32_t numeric = data_test_numeric_full(
        NPU_DTYPE_INT8, NPU_DTYPE_INT4,
        NPU_DTYPE_INT4, NPU_DTYPE_INT8,
        NPU_ROUND_NEAREST_EVEN, 1u,
        NPU_SCALE_PER_TENSOR, 1u);

    (void)memset(
        descriptor, 0, NPU_WIRE_COMPLEX_DESC_BYTES);
    descriptor[0x00u] = NPU_WIRE_DEFAULT_DESC_VERSION;
    descriptor[0x01u] = NPU_ENGINE_COMPLEX;
    data_test_put_u16(
        descriptor, 0x02u, NPU_WIRE_COMPLEX_DESC_BYTES);
    data_test_put_u64(
        descriptor, 0x08u, DATA_TEST_COMPLEX_SRC0);
    data_test_put_u64(
        descriptor, 0x20u, DATA_TEST_COMPLEX_DST);
    data_test_put_u32(descriptor, 0x38u, numeric);
    data_test_put_u32(descriptor, 0x3cu, 0x534f4654u);
    data_test_put_u32(descriptor, 0x40u, 1u);
    data_test_put_u32(descriptor, 0x44u, 4u);
    data_test_put_u32(descriptor, 0x48u, 4u);
    data_test_put_u32(
        descriptor, 0x4cu, NPU_FUNC_SOFTMAX);
    data_test_put_u32(descriptor, 0x50u, 4u);
    data_test_put_u32(descriptor, 0x5cu, 4u);
    data_test_put_u64(
        descriptor, 0x60u, DATA_TEST_COMPLEX_MASK);
    data_test_put_u32(descriptor, 0x68u, 4u);
    data_test_put_u32(
        descriptor, 0x6cu, NPU_MASK_BOOLEAN);
    data_test_put_u32(descriptor, 0x70u, 0x3f800000u);
    data_test_put_u32(descriptor, 0x7cu, 0x3c000000u);
    data_test_put_u32(descriptor, 0x94u, 0xc1800000u);
    data_test_put_u32(descriptor, 0x98u, 0x41800000u);
    descriptor[0x9du] = NPU_OVERFLOW_SATURATE;
    descriptor[0x9eu] = NPU_ALL_MASK_WRITE_ZERO;
    data_test_put_u32(descriptor, 0xb0u, 4u);
}

static uint64_t data_test_metadata(uint16_t task_id,
                                   uint8_t opcode)
{
    return (uint64_t)task_id |
           ((uint64_t)opcode << 12u) |
           (UINT64_C(3) << 20u);
}

static void data_test_idle_inputs(
    npu_engine_data_cycle_inputs_t *inputs)
{
    (void)memset(inputs, 0, sizeof(*inputs));
    inputs->engine.reset_n = 1u;
    inputs->engine.desc_rd_req_ready_i = 1u;
    inputs->engine.eng_done_ready_i = 0u;
    inputs->l1_write.req_ready = 1u;
    inputs->l1_write.data_ready = 1u;
    inputs->mif.req_ready = 1u;
    inputs->mif.wready = 1u;
}

static void data_test_drive_desc_response(
    const uint8_t *descriptor,
    const data_test_desc_server_t *server,
    npu_engine_data_cycle_inputs_t *inputs)
{
    uint8_t tag;

    for (tag = 0u; tag < NPU_ENGINE_DESC_TAGS; tag++) {
        if (server->valid[tag] != 0u) {
            inputs->engine.desc_rd_rsp_valid_i = 1u;
            inputs->engine.desc_rd_rsp_tag_i = tag;
            inputs->engine.desc_rd_rsp_data_i =
                data_test_descriptor_word(
                    descriptor, server->word[tag]);
            inputs->engine.desc_rd_rsp_status_i =
                NPU_ENGINE_DESC_OK;
            return;
        }
    }
}

static int data_test_update_desc_server(
    data_test_desc_server_t *server,
    const npu_engine_data_cycle_inputs_t *inputs,
    const npu_engine_data_cycle_outputs_t *outputs)
{
    uint8_t tag;

    if (inputs->engine.desc_rd_rsp_valid_i != 0u &&
        outputs->engine.desc_rd_rsp_ready_o != 0u) {
        tag = inputs->engine.desc_rd_rsp_tag_i;
        TEST_CHECK(tag < NPU_ENGINE_DESC_TAGS);
        TEST_CHECK(server->valid[tag] != 0u);
        server->valid[tag] = 0u;
        TEST_CHECK(server->count != 0u);
        server->count--;
    }
    if (outputs->engine.desc_rd_req_valid_o != 0u &&
        inputs->engine.desc_rd_req_ready_i != 0u) {
        tag = outputs->engine.desc_rd_req_tag_o;
        TEST_CHECK(tag < NPU_ENGINE_DESC_TAGS);
        TEST_CHECK(server->valid[tag] == 0u);
        server->valid[tag] = 1u;
        server->word[tag] =
            outputs->engine.desc_rd_word_o;
        server->count++;
    }
    return 0;
}

static void data_test_drive_l1(
    const data_test_l1_t *l1,
    npu_engine_data_cycle_inputs_t *inputs)
{
    uint32_t port;

    for (port = 0u; port < NPU_ENGINE_DATA_READ_PORTS;
         port++) {
        const data_test_l1_read_t *read =
            &l1->read[port];

        if (read->valid != 0u &&
            read->response_pause == 0u) {
            inputs->l1_read[port].rsp_valid = 1u;
            inputs->l1_read[port].rsp_data =
                data_test_get_u64(
                    data_test_l1,
                    read->addr +
                        (uint32_t)read->beat * 8u);
            inputs->l1_read[port].rsp_tag =
                read->tag;
            inputs->l1_read[port].rsp_last =
                read->beat + 1u == read->beats
                    ? 1u
                    : 0u;
            inputs->l1_read[port].rsp_status =
                read->response_status;
        }
    }
    if (l1->write_response_valid != 0u &&
        l1->write_response_pause == 0u) {
        inputs->l1_write.rsp_valid = 1u;
        inputs->l1_write.rsp_tag = l1->write_tag;
        inputs->l1_write.rsp_status =
            l1->write_response_status;
    }
}

static int data_test_l1_any_read_valid(
    const data_test_l1_t *l1)
{
    uint32_t port;

    for (port = 0u; port < NPU_ENGINE_DATA_READ_PORTS;
         port++) {
        if (l1->read[port].valid != 0u) {
            return 1;
        }
    }
    return 0;
}

static int data_test_update_l1(
    data_test_l1_t *l1,
    const npu_engine_data_cycle_inputs_t *inputs,
    const npu_engine_data_cycle_outputs_t *outputs,
    uint8_t *write_happened)
{
    uint32_t port;
    uint32_t byte;

    *write_happened = 0u;
    for (port = 0u; port < NPU_ENGINE_DATA_READ_PORTS;
         port++) {
        data_test_l1_read_t *read = &l1->read[port];

        if (read->valid != 0u &&
            inputs->l1_read[port].rsp_valid != 0u &&
            outputs->l1_read[port].rsp_ready != 0u) {
            read->beat++;
            if (read->beat >= read->beats) {
                read->valid = 0u;
            }
        }
        if (outputs->l1_read[port].req_valid != 0u &&
            inputs->l1_read[port].req_ready != 0u) {
            TEST_CHECK(read->valid == 0u);
            read->valid = 1u;
            read->tag = outputs->l1_read[port].req_tag;
            read->addr = outputs->l1_read[port].req_addr;
            read->beats =
                (uint16_t)outputs->l1_read[port].req_beats +
                1u;
            read->beat = 0u;
        }
    }

    if (l1->write_response_valid != 0u &&
        inputs->l1_write.rsp_valid != 0u &&
        outputs->l1_write.rsp_ready != 0u) {
        l1->write_response_valid = 0u;
        l1->write_req_valid = 0u;
        l1->write_beats = 0u;
        l1->write_data_count = 0u;
        l1->write_committed_count = 0u;
    }
    if (outputs->l1_write.req_valid != 0u &&
        inputs->l1_write.req_ready != 0u) {
        TEST_CHECK(l1->write_req_valid == 0u);
        l1->write_req_valid = 1u;
        l1->write_tag = outputs->l1_write.req_tag;
        l1->write_addr = outputs->l1_write.req_addr;
        l1->write_beats =
            (uint16_t)outputs->l1_write.req_beats + 1u;
    }
    if (outputs->l1_write.data_valid != 0u &&
        inputs->l1_write.data_ready != 0u) {
        uint16_t beat = l1->write_data_count;

        TEST_CHECK(beat < NPU_L1_CYCLE_MAX_BEATS);
        l1->write_data[beat] = outputs->l1_write.data;
        l1->write_strb[beat] = outputs->l1_write.strb;
        l1->write_last[beat] = outputs->l1_write.last;
        l1->write_data_count++;
    }
    while (l1->write_req_valid != 0u &&
           l1->write_committed_count <
               l1->write_data_count) {
        uint16_t beat = l1->write_committed_count;
        uint32_t addr =
            l1->write_addr + (uint32_t)beat * 8u;

        TEST_CHECK(beat < l1->write_beats);
        TEST_CHECK(l1->write_last[beat] ==
                   (uint8_t)(beat + 1u ==
                             l1->write_beats));
        for (byte = 0u; byte < 8u; byte++) {
            if ((l1->write_strb[beat] &
                 (uint8_t)(1u << byte)) != 0u) {
                TEST_CHECK(addr + byte <
                           sizeof(data_test_l1));
                data_test_l1[addr + byte] =
                    (uint8_t)(l1->write_data[beat] >>
                              (byte * 8u));
            }
        }
        l1->write_committed_count++;
        *write_happened = 1u;
    }
    if (l1->write_req_valid != 0u &&
        l1->write_data_count == l1->write_beats &&
        l1->write_response_valid == 0u) {
        l1->write_response_valid = 1u;
    }
    return 0;
}

static void data_test_drive_mif(
    const data_test_mif_t *mif,
    npu_engine_data_cycle_inputs_t *inputs)
{
    if (mif->read_valid != 0u &&
        mif->response_pause == 0u) {
        inputs->mif.rsp_valid = 1u;
        inputs->mif.rsp_data = data_test_get_u64(
            data_test_ddr,
            (uint32_t)(
                mif->read_addr +
                (uint64_t)mif->read_beat * 8u));
        inputs->mif.rsp_tag = mif->read_tag;
        inputs->mif.rsp_is_write = 0u;
        inputs->mif.rsp_last =
            mif->read_beat + 1u == mif->read_beats
                ? 1u
                : 0u;
        inputs->mif.rsp_status = mif->response_status;
    }
}

static int data_test_update_mif(
    data_test_mif_t *mif,
    const npu_engine_data_cycle_inputs_t *inputs,
    const npu_engine_data_cycle_outputs_t *outputs)
{
    if (mif->read_valid != 0u &&
        inputs->mif.rsp_valid != 0u &&
        outputs->mif.rsp_ready != 0u) {
        mif->read_beat++;
        if (mif->read_beat >= mif->read_beats) {
            mif->read_valid = 0u;
        }
    }
    if (outputs->mif.req_valid != 0u &&
        inputs->mif.req_ready != 0u) {
        TEST_CHECK(outputs->mif.req_write == 0u);
        TEST_CHECK(mif->read_valid == 0u);
        mif->read_valid = 1u;
        mif->read_tag = outputs->mif.req_tag;
        mif->read_addr = outputs->mif.req_vaddr;
        mif->read_beats =
            (uint16_t)outputs->mif.req_beats + 1u;
        mif->read_beat = 0u;
    }
    TEST_CHECK(outputs->mif.wvalid == 0u);
    return 0;
}

static int data_test_init_wrapper(
    npu_engine_data_cycle_t *model,
    npu_model_t *functional,
    npu_engine_t engine)
{
    npu_config_t config;
    npu_wire_limits_t limits;
    npu_engine_data_workspace_t workspace;

    npu_config_reference(&config);
    if (npu_model_init(
            functional, &config, data_test_l1,
            sizeof(data_test_l1), data_test_ddr,
            sizeof(data_test_ddr)) != NPU_STATUS_SUCCESS) {
        return 0;
    }
    npu_wire_limits_reference(&limits);
    limits.gaddr_limit = sizeof(data_test_ddr);
    if (npu_engine_data_cycle_init(
            model, functional, engine,
            &limits) != NPU_STATUS_SUCCESS) {
        return 0;
    }
    workspace.read_entries = data_test_read_entries;
    workspace.read_capacity = DATA_TEST_TRACE_ENTRIES;
    workspace.read_hash = data_test_read_hash;
    workspace.read_hash_slots = DATA_TEST_TRACE_HASH;
    workspace.write_entries = data_test_write_entries;
    workspace.write_capacity = DATA_TEST_TRACE_ENTRIES;
    workspace.write_hash = data_test_write_hash;
    workspace.write_hash_slots = DATA_TEST_TRACE_HASH;
    return npu_engine_data_cycle_bind_workspace(
        model, &workspace);
}

static void data_test_set_param_region(
    npu_engine_data_cycle_inputs_t *inputs,
    uint32_t base,
    uint32_t limit,
    uint8_t lock)
{
    inputs->param_l1_base = base;
    inputs->param_l1_limit = limit;
    inputs->param_lock = lock;
}

static int data_test_reach_replay_param(
    npu_engine_data_cycle_t *model,
    const uint8_t *descriptor,
    uint64_t metadata,
    data_test_desc_server_t *server,
    npu_engine_data_cycle_outputs_t *outputs,
    uint32_t param_base,
    uint32_t param_limit,
    uint8_t param_lock)
{
    npu_engine_data_cycle_inputs_t inputs;
    uint32_t cycle;
    int line;

    data_test_idle_inputs(&inputs);
    data_test_set_param_region(
        &inputs, param_base, param_limit, param_lock);
    inputs.engine.eng_req_valid_i = 1u;
    inputs.engine.eng_req_data_i = metadata;
    npu_engine_data_cycle_step(model, &inputs, outputs);
    if (outputs->engine.eng_req_ready_o == 0u) {
        return __LINE__;
    }

    for (cycle = 0u; cycle < DATA_TEST_MAX_CYCLES; cycle++) {
        data_test_idle_inputs(&inputs);
        data_test_set_param_region(
            &inputs, param_base, param_limit, param_lock);
        data_test_drive_desc_response(
            descriptor, server, &inputs);
        npu_engine_data_cycle_step(model, &inputs, outputs);
        line = data_test_update_desc_server(
            server, &inputs, outputs);
        if (line != 0) {
            return line;
        }
        if (model->data_pending != 0u) {
            return 0;
        }
        if (outputs->engine.eng_done_valid_o != 0u) {
            return __LINE__;
        }
    }
    return __LINE__;
}

static int data_test_reach_replay(
    npu_engine_data_cycle_t *model,
    const uint8_t *descriptor,
    uint64_t metadata,
    data_test_desc_server_t *server,
    npu_engine_data_cycle_outputs_t *outputs)
{
    return data_test_reach_replay_param(
        model, descriptor, metadata, server, outputs,
        0u, 0u, 0u);
}

static int data_test_accept_done(
    npu_engine_data_cycle_t *model,
    npu_engine_data_cycle_inputs_t *inputs,
    npu_engine_data_cycle_outputs_t *outputs,
    uint64_t done[3])
{
    uint8_t beat;

    for (beat = 0u; beat < 3u; beat++) {
        uint32_t cycle;

        for (cycle = 0u; cycle < 16u; cycle++) {
            data_test_idle_inputs(inputs);
            npu_engine_data_cycle_step(
                model, inputs, outputs);
            if (outputs->engine.eng_done_valid_o != 0u) {
                break;
            }
        }
        if (cycle == 16u ||
            outputs->engine.eng_done_first_o !=
                (uint8_t)(beat == 0u) ||
            outputs->engine.eng_done_last_o !=
                (uint8_t)(beat == 2u)) {
            return __LINE__;
        }
        done[beat] = outputs->engine.eng_done_data_o;

        data_test_idle_inputs(inputs);
        npu_engine_data_cycle_step(
            model, inputs, outputs);
        if (outputs->engine.eng_done_valid_o == 0u ||
            outputs->engine.eng_done_data_o != done[beat] ||
            outputs->engine.eng_done_first_o !=
                (uint8_t)(beat == 0u) ||
            outputs->engine.eng_done_last_o !=
                (uint8_t)(beat == 2u)) {
            return __LINE__;
        }

        data_test_idle_inputs(inputs);
        inputs->engine.eng_done_ready_i = 1u;
        npu_engine_data_cycle_step(
            model, inputs, outputs);
    }
    return 0;
}

static int data_test_finish_l1_replay(
    npu_engine_data_cycle_t *model,
    data_test_l1_t *l1,
    uint64_t done[3],
    uint32_t *read_requests)
{
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    uint8_t done_beat = 0u;
    uint8_t write_happened;
    uint32_t cycle;
    uint32_t port;
    int line;

    *read_requests = 0u;
    for (cycle = 0u; cycle < DATA_TEST_MAX_CYCLES; cycle++) {
        data_test_idle_inputs(&inputs);
        for (port = 0u;
             port < NPU_ENGINE_DATA_READ_PORTS;
             port++) {
            inputs.l1_read[port].req_ready = 1u;
        }
        data_test_drive_l1(l1, &inputs);
        npu_engine_data_cycle_step(
            model, &inputs, &outputs);
        for (port = 0u;
             port < NPU_ENGINE_DATA_READ_PORTS;
             port++) {
            if (outputs.l1_read[port].req_valid != 0u &&
                inputs.l1_read[port].req_ready != 0u) {
                (*read_requests)++;
            }
        }
        line = data_test_update_l1(
            l1, &inputs, &outputs, &write_happened);
        if (line != 0) {
            return line;
        }
        if (outputs.engine.eng_done_valid_o != 0u) {
            if (done_beat >= 3u) {
                return __LINE__;
            }
            done[done_beat] =
                outputs.engine.eng_done_data_o;
            data_test_idle_inputs(&inputs);
            inputs.engine.eng_done_ready_i = 1u;
            npu_engine_data_cycle_step(
                model, &inputs, &outputs);
            done_beat++;
        }
        if (done_beat == 3u) {
            return 0;
        }
    }
    return __LINE__;
}

static int data_test_vector_replay(void)
{
    uint8_t descriptor[NPU_WIRE_VECTOR_DESC_BYTES];
    npu_config_t config;
    npu_model_t functional;
    npu_wire_limits_t limits;
    npu_engine_data_workspace_t workspace;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    npu_engine_data_cycle_outputs_t preview;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint8_t done_beat = 0u;
    uint8_t write_happened;
    uint8_t write_seen = 0u;
    uint8_t capture_eval_checked = 0u;
    uint8_t lane_mask[2] = {0u, 0u};
    uint8_t lane_group_count = 0u;
    uint8_t eval_group_checked = 0u;
    uint8_t read_compute_overlap_seen = 0u;
    uint32_t cycle;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_vector_descriptor(descriptor);
    data_test_put_u32(descriptor, 0x44u, 11u);
    data_test_put_u32(descriptor, 0x48u, 11u);
    for (index = 0u; index < 11u; index++) {
        data_test_l1[DATA_TEST_SRC0 + index] =
            (uint8_t)(index + 1u);
        data_test_l1[DATA_TEST_SRC1 + index] =
            (uint8_t)(10u * (index + 1u));
    }

    npu_config_reference(&config);
    TEST_CHECK_STATUS(
        npu_model_init(
            &functional, &config, data_test_l1,
            sizeof(data_test_l1), data_test_ddr,
            sizeof(data_test_ddr)),
        NPU_STATUS_SUCCESS);
    npu_wire_limits_reference(&limits);
    limits.gaddr_limit = sizeof(data_test_ddr);
    TEST_CHECK_STATUS(
        npu_engine_data_cycle_init(
            &model, &functional, NPU_ENGINE_VECTOR,
            &limits),
        NPU_STATUS_SUCCESS);
    workspace.read_entries = data_test_read_entries;
    workspace.read_capacity = DATA_TEST_TRACE_ENTRIES;
    workspace.read_hash = data_test_read_hash;
    workspace.read_hash_slots = DATA_TEST_TRACE_HASH;
    workspace.write_entries = data_test_write_entries;
    workspace.write_capacity = DATA_TEST_TRACE_ENTRIES;
    workspace.write_hash = data_test_write_hash;
    workspace.write_hash_slots = DATA_TEST_TRACE_HASH;
    TEST_CHECK(npu_engine_data_cycle_bind_workspace(
        &model, &workspace));

    data_test_idle_inputs(&inputs);
    inputs.engine.eng_req_valid_i = 1u;
    inputs.engine.eng_req_data_i = data_test_metadata(
        0x123u, NPU_VECTOR_ADD);
    npu_engine_data_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine.eng_req_ready_o == 1u);

    for (cycle = 0u; cycle < DATA_TEST_MAX_CYCLES; cycle++) {
        data_test_idle_inputs(&inputs);
        for (index = 0u;
             index < NPU_ENGINE_DATA_READ_PORTS;
             index++) {
            inputs.l1_read[index].req_ready =
                (uint8_t)((cycle + index) % 3u != 0u);
        }
        inputs.l1_write.req_ready =
            (uint8_t)(cycle % 4u != 0u);
        inputs.l1_write.data_ready =
            (uint8_t)(cycle % 5u != 0u);
        data_test_drive_desc_response(
            descriptor, &server, &inputs);
        data_test_drive_l1(&l1, &inputs);

        if (model.replay.state ==
                NPU_BUS_REPLAY_COMPUTE_HOLD &&
            model.compute_stage ==
                NPU_ENGINE_DATA_COMPUTE_IVE &&
            eval_group_checked == 0u) {
            uint64_t remaining =
                model.compute_stage_remaining;

            npu_engine_data_cycle_eval(
                &model, &inputs, &preview);
            TEST_CHECK(preview.ive_alu_active != 0u);
            TEST_CHECK(
                preview.ive_lane_valid ==
                (model.compute_groups_issued + 1u >=
                         model.compute_groups
                     ? model.compute_tail_lane_mask
                     : model.compute_full_lane_mask));
            npu_engine_data_cycle_eval(
                &model, &inputs, &preview);
            TEST_CHECK(preview.ive_alu_active != 0u);
            TEST_CHECK(
                preview.ive_lane_valid ==
                (model.compute_groups_issued + 1u >=
                         model.compute_groups
                     ? model.compute_tail_lane_mask
                     : model.compute_full_lane_mask));
            TEST_CHECK(
                model.compute_stage_remaining == remaining);
            eval_group_checked = 1u;
        }

        if (model.engine.state ==
                NPU_ENGINE_CYCLE_EXECUTE &&
            model.engine.execute_remaining <= 1u &&
            model.data_pending == 0u) {
            npu_perf_t perf_before = functional.perf;
            size_t reads_before = model.trace.read_count;
            size_t writes_before = model.trace.write_count;

            npu_engine_data_cycle_eval(
                &model, &inputs, &preview);
            npu_engine_data_cycle_eval(
                &model, &inputs, &preview);
            TEST_CHECK(memcmp(
                           &perf_before, &functional.perf,
                           sizeof(perf_before)) == 0);
            TEST_CHECK(model.trace.read_count ==
                       reads_before);
            TEST_CHECK(model.trace.write_count ==
                       writes_before);
            TEST_CHECK(data_test_l1[DATA_TEST_DST] == 0u);
            capture_eval_checked = 1u;
        }

        {
            npu_bus_replay_state_t replay_state_before =
                model.replay.state;

            npu_engine_data_cycle_step(
                &model, &inputs, &outputs);
            if (outputs.ive_alu_active != 0u &&
                (replay_state_before ==
                     NPU_BUS_REPLAY_READ_REQUEST ||
                 replay_state_before ==
                     NPU_BUS_REPLAY_READ_RESPONSE)) {
                read_compute_overlap_seen = 1u;
            }
        }
        if (outputs.ive_lane_valid != 0u) {
            TEST_CHECK(lane_group_count < 2u);
            TEST_CHECK(write_seen == 0u);
            TEST_CHECK(outputs.ive_alu_active != 0u);
            lane_mask[lane_group_count] =
                outputs.ive_lane_valid;
            lane_group_count++;
        }
        line = data_test_update_desc_server(
            &server, &inputs, &outputs);
        if (line != 0) {
            return line;
        }
        line = data_test_update_l1(
            &l1, &inputs, &outputs, &write_happened);
        if (line != 0) {
            return line;
        }
        if (write_happened != 0u) {
            TEST_CHECK(outputs.engine.eng_done_valid_o == 0u);
            write_seen = 1u;
        }
        if (write_seen == 0u) {
            TEST_CHECK(data_test_l1[DATA_TEST_DST] == 0u);
        }
        if (outputs.engine.eng_done_valid_o != 0u) {
            TEST_CHECK(l1.write_response_valid == 0u);
            TEST_CHECK(done_beat < 3u);
            done[done_beat] =
                outputs.engine.eng_done_data_o;
            inputs.engine.eng_done_ready_i = 1u;
            npu_engine_data_cycle_step(
                &model, &inputs, &outputs);
            done_beat++;
        }
        if (done_beat == 3u) {
            break;
        }
    }

    TEST_CHECK(cycle < DATA_TEST_MAX_CYCLES);
    TEST_CHECK(capture_eval_checked != 0u);
    TEST_CHECK(eval_group_checked != 0u);
    TEST_CHECK(read_compute_overlap_seen != 0u);
    TEST_CHECK(lane_group_count == 2u);
    TEST_CHECK(lane_mask[0] == 0xffu);
    TEST_CHECK(lane_mask[1] == 0x07u);
    TEST_CHECK(write_seen != 0u);
    TEST_CHECK(done_beat == 3u);
    TEST_CHECK((done[0] & 0x0fffu) == 0x123u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 11u);
    TEST_CHECK(model.trace.read_count == 4u);
    TEST_CHECK(model.trace.write_count == 2u);
    TEST_CHECK(data_test_read_entries[0].port == 0u);
    TEST_CHECK(data_test_read_entries[1].port == 1u);
    for (index = 0u; index < 11u; index++) {
        TEST_CHECK(
            data_test_l1[DATA_TEST_DST + index] ==
            (uint8_t)((index + 1u) * 11u));
    }
    return 0;
}

static int data_test_vector_int16_geometry(void)
{
    uint8_t descriptor[NPU_WIRE_VECTOR_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint32_t read_requests;
    uint32_t port0_words = 0u;
    uint32_t port1_words = 0u;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_vector_descriptor(descriptor);
    data_test_put_u32(
        descriptor, 0x38u,
        data_test_numeric(
            NPU_DTYPE_INT16, NPU_DTYPE_INT16,
            NPU_DTYPE_INT4, NPU_DTYPE_INT16));
    data_test_put_u32(descriptor, 0x44u, 5u);
    data_test_put_u32(descriptor, 0x48u, 5u);
    data_test_put_u32(descriptor, 0x50u, 2u);
    data_test_put_u32(descriptor, 0x54u, 10u);
    data_test_put_u32(descriptor, 0x58u, 2u);
    data_test_put_u32(descriptor, 0x5cu, 10u);
    data_test_put_u32(descriptor, 0x68u, 2u);
    data_test_put_u32(descriptor, 0x6cu, 10u);
    for (index = 0u; index < 5u; index++) {
        data_test_put_u16(
            data_test_l1,
            DATA_TEST_SRC0 + index * 2u,
            (uint16_t)(index + 1u));
        data_test_put_u16(
            data_test_l1,
            DATA_TEST_SRC1 + index * 2u,
            (uint16_t)(10u * (index + 1u)));
    }

    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_VECTOR));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x160u, NPU_VECTOR_ADD),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.compute_lanes == 4u);
    TEST_CHECK(model.compute_groups == 2u);
    TEST_CHECK(model.compute_full_lane_mask == 0x0fu);
    TEST_CHECK(model.compute_tail_lane_mask == 0x01u);
    TEST_CHECK(model.trace.read_count == 4u);
    TEST_CHECK(model.trace.write_count == 2u);
    for (index = 0u; index < model.trace.read_count; index++) {
        if (data_test_read_entries[index].port == 0u) {
            port0_words++;
        } else if (data_test_read_entries[index].port == 1u) {
            port1_words++;
        }
    }
    TEST_CHECK(port0_words == 2u);
    TEST_CHECK(port1_words == 2u);

    line = data_test_finish_l1_replay(
        &model, &l1, done, &read_requests);
    if (line != 0) {
        return line;
    }
    /*
     * Each source occupies two adjacent 64-bit words.  The replay
     * interface combines those words into one two-beat L1 request per
     * read port, so four captured words become two requests.
     */
    TEST_CHECK(read_requests == 2u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 5u);
    for (index = 0u; index < 5u; index++) {
        uint16_t value =
            (uint16_t)data_test_l1[
                DATA_TEST_DST + index * 2u] |
            (uint16_t)((uint16_t)data_test_l1[
                DATA_TEST_DST + index * 2u + 1u] << 8u);

        TEST_CHECK(value ==
                   (uint16_t)(11u * (index + 1u)));
    }
    return 0;
}

static int data_test_matrix_int16_b_span(void)
{
    uint8_t descriptor[NPU_WIRE_MATRIX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint32_t read_requests;
    uint32_t b_words = 0u;
    uint8_t b_last_word_seen = 0u;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_matrix_int16_descriptor(descriptor);
    for (index = 0u; index < 16u; index++) {
        data_test_put_u16(
            data_test_l1,
            DATA_TEST_MATRIX_A + index * 2u, 1u);
    }
    for (index = 0u;
         index < NPU_REF_KT * NPU_REF_NT;
         index++) {
        data_test_put_u16(
            data_test_l1,
            DATA_TEST_MATRIX_B + index * 2u, 1u);
    }

    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_MATRIX));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x161u, NPU_MATRIX_GEMM),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.compute_groups == 1u);
    TEST_CHECK(model.trace.read_count == 36u);
    TEST_CHECK(model.trace.write_count == 4u);
    for (index = 0u; index < model.trace.read_count; index++) {
        if (data_test_read_entries[index].port == 1u) {
            b_words++;
            if (data_test_read_entries[index].addr ==
                DATA_TEST_MATRIX_B + 248u) {
                b_last_word_seen = 1u;
            }
        }
    }
    TEST_CHECK(b_words == 32u);
    TEST_CHECK(b_last_word_seen != 0u);

    line = data_test_finish_l1_replay(
        &model, &l1, done, &read_requests);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(read_requests != 0u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 8u);
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(data_test_get_u64(
                       data_test_l1,
                       DATA_TEST_MATRIX_DST + index * 8u) ==
                   UINT64_C(0x0000001000000010));
    }
    return 0;
}

static int data_test_dma_replay(void)
{
    uint8_t descriptor[NPU_WIRE_DMA_DESC_BYTES];
    npu_config_t config;
    npu_model_t functional;
    npu_wire_limits_t limits;
    npu_engine_data_workspace_t workspace;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    data_test_mif_t mif;
    uint64_t done[3] = {0u, 0u, 0u};
    uint8_t done_beat = 0u;
    uint8_t write_happened;
    uint8_t mif_read_seen = 0u;
    uint32_t cycle;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    (void)memset(&mif, 0, sizeof(mif));
    data_test_ddr[DATA_TEST_DDR_SRC] = 0x12u;
    data_test_ddr[DATA_TEST_DDR_SRC + 1u] = 0x34u;
    data_test_dma_descriptor(descriptor);

    npu_config_reference(&config);
    TEST_CHECK_STATUS(
        npu_model_init(
            &functional, &config, data_test_l1,
            sizeof(data_test_l1), data_test_ddr,
            sizeof(data_test_ddr)),
        NPU_STATUS_SUCCESS);
    npu_wire_limits_reference(&limits);
    limits.gaddr_limit = sizeof(data_test_ddr);
    TEST_CHECK_STATUS(
        npu_engine_data_cycle_init(
            &model, &functional, NPU_ENGINE_DMA,
            &limits),
        NPU_STATUS_SUCCESS);
    workspace.read_entries = data_test_read_entries;
    workspace.read_capacity = DATA_TEST_TRACE_ENTRIES;
    workspace.read_hash = data_test_read_hash;
    workspace.read_hash_slots = DATA_TEST_TRACE_HASH;
    workspace.write_entries = data_test_write_entries;
    workspace.write_capacity = DATA_TEST_TRACE_ENTRIES;
    workspace.write_hash = data_test_write_hash;
    workspace.write_hash_slots = DATA_TEST_TRACE_HASH;
    TEST_CHECK(npu_engine_data_cycle_bind_workspace(
        &model, &workspace));

    data_test_idle_inputs(&inputs);
    inputs.engine.eng_req_valid_i = 1u;
    inputs.engine.eng_req_data_i = data_test_metadata(
        0x124u, NPU_DMA_COPY_1D);
    npu_engine_data_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.engine.eng_req_ready_o == 1u);

    for (cycle = 0u; cycle < DATA_TEST_MAX_CYCLES; cycle++) {
        data_test_idle_inputs(&inputs);
        inputs.mif.req_ready =
            (uint8_t)(cycle % 3u != 0u);
        inputs.l1_write.req_ready =
            (uint8_t)(cycle % 4u != 0u);
        inputs.l1_write.data_ready =
            (uint8_t)(cycle % 5u != 0u);
        data_test_drive_desc_response(
            descriptor, &server, &inputs);
        data_test_drive_l1(&l1, &inputs);
        data_test_drive_mif(&mif, &inputs);
        npu_engine_data_cycle_step(
            &model, &inputs, &outputs);
        line = data_test_update_desc_server(
            &server, &inputs, &outputs);
        if (line != 0) {
            return line;
        }
        line = data_test_update_mif(
            &mif, &inputs, &outputs);
        if (line != 0) {
            return line;
        }
        if (outputs.mif.req_valid != 0u) {
            mif_read_seen = 1u;
        }
        line = data_test_update_l1(
            &l1, &inputs, &outputs, &write_happened);
        if (line != 0) {
            return line;
        }
        if (outputs.engine.eng_done_valid_o != 0u) {
            TEST_CHECK(l1.write_response_valid == 0u);
            done[done_beat] =
                outputs.engine.eng_done_data_o;
            inputs.engine.eng_done_ready_i = 1u;
            npu_engine_data_cycle_step(
                &model, &inputs, &outputs);
            done_beat++;
        }
        if (done_beat == 3u) {
            break;
        }
    }

    TEST_CHECK(cycle < DATA_TEST_MAX_CYCLES);
    TEST_CHECK(mif_read_seen != 0u);
    TEST_CHECK(done_beat == 3u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 2u);
    TEST_CHECK(functional.perf.dma_read_bytes == 2u);
    TEST_CHECK(functional.perf.dma_write_bytes == 0u);
    TEST_CHECK(model.trace.read_count == 1u);
    TEST_CHECK(model.trace.write_count == 1u);
    TEST_CHECK(data_test_read_entries[0].space ==
               NPU_SPACE_DDR);
    TEST_CHECK(data_test_write_entries[0].space ==
               NPU_SPACE_L1);
    TEST_CHECK(data_test_l1[DATA_TEST_DMA_DST] == 0x12u);
    TEST_CHECK(data_test_l1[DATA_TEST_DMA_DST + 1u] ==
               0x34u);
    return 0;
}

static int data_test_dma_sixteen_beat_burst(void)
{
    uint8_t descriptor[NPU_WIRE_DMA_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    data_test_mif_t mif;
    uint64_t done[3] = {0u, 0u, 0u};
    uint8_t done_beat = 0u;
    uint8_t write_happened;
    uint32_t mif_requests = 0u;
    uint32_t l1_write_requests = 0u;
    uint32_t cycle;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    (void)memset(&mif, 0, sizeof(mif));
    data_test_dma_descriptor(descriptor);
    data_test_put_u32(descriptor, 0x48u, 128u);
    data_test_put_u64(descriptor, 0x98u, 128u);
    data_test_put_u64(descriptor, 0xa0u, 128u);
    for (index = 0u; index < 128u; index++) {
        data_test_ddr[DATA_TEST_DDR_SRC + index] =
            (uint8_t)(index ^ 0x5au);
    }
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_DMA));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x12eu, NPU_DMA_COPY_1D),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.trace.read_count == 16u);
    TEST_CHECK(model.trace.write_count == 16u);

    for (cycle = 0u; cycle < DATA_TEST_MAX_CYCLES; cycle++) {
        data_test_idle_inputs(&inputs);
        data_test_drive_mif(&mif, &inputs);
        data_test_drive_l1(&l1, &inputs);
        npu_engine_data_cycle_step(
            &model, &inputs, &outputs);

        if (outputs.mif.req_valid != 0u &&
            inputs.mif.req_ready != 0u) {
            TEST_CHECK(outputs.mif.req_write == 0u);
            TEST_CHECK(outputs.mif.req_beats == 15u);
            mif_requests++;
        }
        if (outputs.l1_write.req_valid != 0u &&
            inputs.l1_write.req_ready != 0u) {
            TEST_CHECK(outputs.l1_write.req_beats == 15u);
            l1_write_requests++;
        }
        line = data_test_update_mif(
            &mif, &inputs, &outputs);
        if (line != 0) {
            return line;
        }
        line = data_test_update_l1(
            &l1, &inputs, &outputs, &write_happened);
        if (line != 0) {
            return line;
        }
        if (outputs.engine.eng_done_valid_o != 0u) {
            TEST_CHECK(done_beat < 3u);
            done[done_beat] =
                outputs.engine.eng_done_data_o;
            data_test_idle_inputs(&inputs);
            inputs.engine.eng_done_ready_i = 1u;
            npu_engine_data_cycle_step(
                &model, &inputs, &outputs);
            done_beat++;
        }
        if (done_beat == 3u) {
            break;
        }
    }

    TEST_CHECK(cycle < DATA_TEST_MAX_CYCLES);
    TEST_CHECK(mif_requests == 1u);
    TEST_CHECK(l1_write_requests == 1u);
    TEST_CHECK(done_beat == 3u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 128u);
    TEST_CHECK(functional.perf.dma_read_bytes == 128u);
    TEST_CHECK(functional.perf.dma_write_bytes == 0u);
    for (index = 0u; index < 128u; index++) {
        TEST_CHECK(
            data_test_l1[DATA_TEST_DMA_DST + index] ==
            (uint8_t)(index ^ 0x5au));
    }
    return 0;
}

static int data_test_matrix_replay(void)
{
    uint8_t descriptor[NPU_WIRE_MATRIX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    npu_l1_cycle_read_input_t
        held_read[NPU_ENGINE_DATA_READ_PORTS] = {{0}};
    npu_l1_cycle_write_input_t held_write = {0};
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint8_t done_beat = 0u;
    uint8_t
        held_read_valid[NPU_ENGINE_DATA_READ_PORTS] = {0};
    uint8_t held_write_req = 0u;
    uint8_t held_write_data = 0u;
    uint8_t write_happened;
    uint8_t write_seen = 0u;
    uint8_t write_response_wait_checked = 0u;
    uint32_t mac_active_cycles = 0u;
    uint32_t cycle;
    uint32_t port;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_matrix_descriptor(descriptor);
    data_test_l1[DATA_TEST_MATRIX_A] = 2u;
    data_test_l1[DATA_TEST_MATRIX_A + 1u] = 3u;
    data_test_l1[DATA_TEST_MATRIX_B] = 4u;
    data_test_l1[DATA_TEST_MATRIX_B + NPU_REF_NT] =
        (uint8_t)-1;
    data_test_put_u32(
        data_test_l1, DATA_TEST_MATRIX_BIAS, 7u);
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_MATRIX));

    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x125u, NPU_MATRIX_GEMM),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(outputs.me_mac_active == 0u);
    TEST_CHECK(data_test_l1[DATA_TEST_MATRIX_DST] == 0u);

    data_test_idle_inputs(&inputs);
    inputs.l1_read[0].req_ready = 1u;
    inputs.l1_read[1].req_ready = 1u;
    inputs.l1_read[2].req_ready = 0u;
    inputs.l1_read[3].req_ready = 1u;
    data_test_drive_l1(&l1, &inputs);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read[2].req_valid != 0u);
    TEST_CHECK(outputs.l1_stall != 0u);
    TEST_CHECK(outputs.me_operand_stall == 0u);
    line = data_test_update_l1(
        &l1, &inputs, &outputs, &write_happened);
    if (line != 0) {
        return line;
    }

    for (cycle = 0u; cycle < DATA_TEST_MAX_CYCLES; cycle++) {
        data_test_idle_inputs(&inputs);
        for (port = 0u;
             port < NPU_ENGINE_DATA_READ_PORTS;
             port++) {
            inputs.l1_read[port].req_ready =
                (uint8_t)((cycle + port) % 4u != 0u);
        }
        inputs.l1_write.req_ready =
            (uint8_t)(cycle % 3u != 0u);
        inputs.l1_write.data_ready =
            (uint8_t)(cycle % 5u != 0u);
        if (l1.write_response_valid != 0u &&
            write_response_wait_checked == 0u) {
            l1.write_response_pause = 1u;
        }
        data_test_drive_l1(&l1, &inputs);
        npu_engine_data_cycle_step(
            &model, &inputs, &outputs);
        if (l1.write_response_pause != 0u) {
            TEST_CHECK(outputs.l1_write.rsp_ready != 0u);
            TEST_CHECK(outputs.l1_stall != 0u);
            TEST_CHECK(outputs.me_write_stall == 0u);
            write_response_wait_checked = 1u;
            l1.write_response_pause = 0u;
        }
        if (outputs.me_mac_active != 0u) {
            TEST_CHECK(write_seen == 0u);
            TEST_CHECK(outputs.l1_write.req_valid == 0u);
            TEST_CHECK(outputs.l1_write.data_valid == 0u);
            mac_active_cycles++;
        }

        for (port = 0u;
             port < NPU_ENGINE_DATA_READ_PORTS;
             port++) {
            if (held_read_valid[port] != 0u) {
                TEST_CHECK(
                    outputs.l1_read[port].req_valid != 0u);
                TEST_CHECK(
                    outputs.l1_read[port].req_addr ==
                    held_read[port].req_addr);
                TEST_CHECK(
                    outputs.l1_read[port].req_beats ==
                    held_read[port].req_beats);
                TEST_CHECK(
                    outputs.l1_read[port].req_tag ==
                    held_read[port].req_tag);
            }
            held_read_valid[port] = 0u;
            if (outputs.l1_read[port].req_valid != 0u &&
                inputs.l1_read[port].req_ready == 0u) {
                held_read_valid[port] = 1u;
                held_read[port] = outputs.l1_read[port];
            }
        }

        if (held_write_req != 0u) {
            TEST_CHECK(outputs.l1_write.req_valid != 0u);
            TEST_CHECK(outputs.l1_write.req_addr ==
                       held_write.req_addr);
            TEST_CHECK(outputs.l1_write.req_beats ==
                       held_write.req_beats);
            TEST_CHECK(outputs.l1_write.req_tag ==
                       held_write.req_tag);
        }
        if (held_write_data != 0u) {
            TEST_CHECK(outputs.l1_write.data_valid != 0u);
            TEST_CHECK(outputs.l1_write.data ==
                       held_write.data);
            TEST_CHECK(outputs.l1_write.strb ==
                       held_write.strb);
            TEST_CHECK(outputs.l1_write.last ==
                       held_write.last);
        }
        held_write_req =
            outputs.l1_write.req_valid != 0u &&
                    inputs.l1_write.req_ready == 0u
                ? 1u
                : 0u;
        held_write_data =
            outputs.l1_write.data_valid != 0u &&
                    inputs.l1_write.data_ready == 0u
                ? 1u
                : 0u;
        held_write = outputs.l1_write;

        line = data_test_update_l1(
            &l1, &inputs, &outputs, &write_happened);
        if (line != 0) {
            return line;
        }
        if (write_happened != 0u) {
            TEST_CHECK(
                outputs.engine.eng_done_valid_o == 0u);
            write_seen = 1u;
        }
        if (write_seen == 0u) {
            TEST_CHECK(
                data_test_l1[DATA_TEST_MATRIX_DST] == 0u);
        }
        if (data_test_l1_any_read_valid(&l1) ||
            l1.write_response_valid != 0u) {
            TEST_CHECK(
                outputs.engine.eng_done_valid_o == 0u);
        }
        if (outputs.engine.eng_done_valid_o != 0u) {
            TEST_CHECK(done_beat < 3u);
            done[done_beat] =
                outputs.engine.eng_done_data_o;
            data_test_idle_inputs(&inputs);
            inputs.engine.eng_done_ready_i = 1u;
            npu_engine_data_cycle_step(
                &model, &inputs, &outputs);
            done_beat++;
        }
        if (done_beat == 3u) {
            break;
        }
    }

    TEST_CHECK(cycle < DATA_TEST_MAX_CYCLES);
    TEST_CHECK(mac_active_cycles == 1u);
    TEST_CHECK(write_response_wait_checked != 0u);
    TEST_CHECK(write_seen != 0u);
    TEST_CHECK(done_beat == 3u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 1u);
    TEST_CHECK(model.trace.read_count == 4u);
    TEST_CHECK(model.trace.write_count == 1u);
    TEST_CHECK(data_test_read_entries[0].port == 0u);
    TEST_CHECK(data_test_read_entries[1].port == 1u);
    TEST_CHECK(data_test_read_entries[2].port == 1u);
    TEST_CHECK(data_test_read_entries[3].port == 2u);
    TEST_CHECK(data_test_write_entries[0].addr ==
               DATA_TEST_MATRIX_DST);
    TEST_CHECK(data_test_l1[DATA_TEST_MATRIX_DST] == 12u);
    TEST_CHECK(data_test_l1[DATA_TEST_MATRIX_DST + 1u] ==
               0u);
    TEST_CHECK(data_test_l1[DATA_TEST_MATRIX_DST + 2u] ==
               0u);
    TEST_CHECK(data_test_l1[DATA_TEST_MATRIX_DST + 3u] ==
               0u);
    return 0;
}

static int data_test_matrix_k_tile_activity(void)
{
    uint8_t descriptor[NPU_WIRE_MATRIX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint8_t done_beat = 0u;
    uint8_t write_happened;
    uint8_t write_seen = 0u;
    uint8_t read_compute_overlap_seen = 0u;
    uint32_t mac_active_cycles = 0u;
    uint32_t cycle;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_matrix_descriptor(descriptor);

    /*
     * M=N=1 and K=17 span two K tiles with the reference KT=16.
     * Bias is disabled so packed B can occupy [0x1100,0x1200).
     */
    data_test_put_u64(descriptor, 0x28u, 0u);
    data_test_put_u32(descriptor, 0x48u, 17u);
    data_test_put_u32(descriptor, 0x58u, 1u);
    data_test_put_u32(
        descriptor, 0x5cu, UINT32_C(1) << 7u);
    data_test_put_u32(descriptor, 0x60u, 17u);
    data_test_put_u32(descriptor, 0x6cu, 0u);
    data_test_put_u32(descriptor, 0xa0u, 0u);

    for (index = 0u; index < 17u; index++) {
        data_test_l1[DATA_TEST_MATRIX_A + index] = 1u;
        data_test_l1[
            DATA_TEST_MATRIX_B +
            (index / NPU_REF_KT) *
                NPU_REF_KT * NPU_REF_NT +
            (index % NPU_REF_KT) * NPU_REF_NT] = 1u;
    }

    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_MATRIX));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x144u, NPU_MATRIX_GEMM),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.compute_groups == 2u);
    TEST_CHECK(
        model.compute_stage ==
        NPU_ENGINE_DATA_COMPUTE_ME);

    for (cycle = 0u; cycle < DATA_TEST_MAX_CYCLES; cycle++) {
        data_test_idle_inputs(&inputs);
        for (index = 0u;
             index < NPU_ENGINE_DATA_READ_PORTS;
             index++) {
            inputs.l1_read[index].req_ready = 1u;
        }
        data_test_drive_l1(&l1, &inputs);
        {
            npu_bus_replay_state_t replay_state_before =
                model.replay.state;

            npu_engine_data_cycle_step(
                &model, &inputs, &outputs);
            if (outputs.me_mac_active != 0u &&
                (replay_state_before ==
                     NPU_BUS_REPLAY_READ_REQUEST ||
                 replay_state_before ==
                     NPU_BUS_REPLAY_READ_RESPONSE)) {
                read_compute_overlap_seen = 1u;
            }
        }
        if (outputs.me_mac_active != 0u) {
            TEST_CHECK(write_seen == 0u);
            TEST_CHECK(outputs.l1_write.req_valid == 0u);
            TEST_CHECK(outputs.l1_write.data_valid == 0u);
            mac_active_cycles++;
        }
        line = data_test_update_l1(
            &l1, &inputs, &outputs, &write_happened);
        if (line != 0) {
            return line;
        }
        if (write_happened != 0u) {
            TEST_CHECK(mac_active_cycles == 2u);
            write_seen = 1u;
        }
        if (outputs.engine.eng_done_valid_o != 0u) {
            TEST_CHECK(done_beat < 3u);
            done[done_beat] =
                outputs.engine.eng_done_data_o;
            data_test_idle_inputs(&inputs);
            inputs.engine.eng_done_ready_i = 1u;
            npu_engine_data_cycle_step(
                &model, &inputs, &outputs);
            done_beat++;
        }
        if (done_beat == 3u) {
            break;
        }
    }

    TEST_CHECK(cycle < DATA_TEST_MAX_CYCLES);
    TEST_CHECK(mac_active_cycles == 2u);
    TEST_CHECK(read_compute_overlap_seen != 0u);
    TEST_CHECK(write_seen != 0u);
    TEST_CHECK(done_beat == 3u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 1u);
    TEST_CHECK(
        (uint32_t)data_test_get_u64(
            data_test_l1, DATA_TEST_MATRIX_DST) == 17u);
    return 0;
}

static int data_test_complex_replay(void)
{
    static const uint8_t expected[4] = {
        (uint8_t)-21, (uint8_t)-7, 7u, 21u
    };
    uint8_t descriptor[NPU_WIRE_COMPLEX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint8_t done_beat = 0u;
    uint8_t write_happened;
    uint8_t write_seen = 0u;
    uint32_t i2f_cycles = 0u;
    uint32_t fp_cycles = 0u;
    uint32_t f2i_cycles = 0u;
    uint8_t i2f_fp_overlap = 0u;
    uint32_t cycle;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_complex_descriptor(descriptor);
    for (index = 0u; index < 4u; index++) {
        data_test_l1[DATA_TEST_COMPLEX_SRC0 + index] =
            (uint8_t)(index + 1u);
        data_test_l1[DATA_TEST_COMPLEX_SRC1 + index] = 1u;
        data_test_l1[DATA_TEST_COMPLEX_SRC2 + index] = 0u;
        data_test_l1[DATA_TEST_COMPLEX_DST + index] = 0x55u;
    }
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_COMPLEX));

    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x126u, NPU_COMPLEX_NORM),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(outputs.cme_i2f_active == 0u);
    TEST_CHECK(outputs.cme_fp_active == 0u);
    TEST_CHECK(outputs.cme_f2i_active == 0u);
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(
            data_test_l1[DATA_TEST_COMPLEX_DST + index] ==
            0x55u);
    }

    for (cycle = 0u; cycle < DATA_TEST_MAX_CYCLES; cycle++) {
        data_test_idle_inputs(&inputs);
        for (index = 0u;
             index < NPU_ENGINE_DATA_READ_PORTS;
             index++) {
            inputs.l1_read[index].req_ready =
                (uint8_t)((cycle + index) % 3u != 0u);
        }
        inputs.l1_write.req_ready =
            (uint8_t)(cycle % 4u != 0u);
        inputs.l1_write.data_ready =
            (uint8_t)(cycle % 6u != 0u);
        data_test_drive_l1(&l1, &inputs);
        npu_engine_data_cycle_step(
            &model, &inputs, &outputs);
        if (outputs.cme_i2f_active != 0u) {
            i2f_cycles++;
        }
        if (outputs.cme_fp_active != 0u) {
            TEST_CHECK(i2f_cycles != 0u);
            fp_cycles++;
        }
        if (outputs.cme_f2i_active != 0u) {
            TEST_CHECK(fp_cycles != 0u);
            f2i_cycles++;
        }
        if (outputs.cme_i2f_active != 0u &&
            outputs.cme_fp_active != 0u) {
            i2f_fp_overlap = 1u;
        }
        if (outputs.cme_i2f_active != 0u ||
            outputs.cme_fp_active != 0u ||
            outputs.cme_f2i_active != 0u) {
            TEST_CHECK(
                !data_test_l1_any_read_valid(&l1));
            TEST_CHECK(write_seen == 0u);
            TEST_CHECK(outputs.l1_write.req_valid == 0u);
            TEST_CHECK(outputs.l1_write.data_valid == 0u);
        }
        line = data_test_update_l1(
            &l1, &inputs, &outputs, &write_happened);
        if (line != 0) {
            return line;
        }
        if (write_happened != 0u) {
            TEST_CHECK(
                outputs.engine.eng_done_valid_o == 0u);
            write_seen = 1u;
        }
        if (write_seen == 0u) {
            for (index = 0u; index < 4u; index++) {
                TEST_CHECK(
                    data_test_l1[
                        DATA_TEST_COMPLEX_DST + index] ==
                    0x55u);
            }
        }
        if (outputs.engine.eng_done_valid_o != 0u) {
            TEST_CHECK(l1.write_response_valid == 0u);
            TEST_CHECK(done_beat < 3u);
            done[done_beat] =
                outputs.engine.eng_done_data_o;
            data_test_idle_inputs(&inputs);
            inputs.engine.eng_done_ready_i = 1u;
            npu_engine_data_cycle_step(
                &model, &inputs, &outputs);
            done_beat++;
        }
        if (done_beat == 3u) {
            break;
        }
    }

    TEST_CHECK(cycle < DATA_TEST_MAX_CYCLES);
    TEST_CHECK(i2f_cycles == 5u);
    TEST_CHECK(fp_cycles == 29u);
    TEST_CHECK(f2i_cycles == 4u);
    TEST_CHECK(i2f_fp_overlap != 0u);
    TEST_CHECK(write_seen != 0u);
    TEST_CHECK(done_beat == 3u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 4u);
    TEST_CHECK(model.trace.read_count == 5u);
    TEST_CHECK(model.trace.write_count == 1u);
    TEST_CHECK(data_test_read_entries[0].port == 0u);
    TEST_CHECK(data_test_read_entries[0].read_pass == 0u);
    TEST_CHECK(data_test_read_entries[1].port == 0u);
    TEST_CHECK(data_test_read_entries[1].read_pass == 1u);
    TEST_CHECK(data_test_read_entries[2].port == 0u);
    TEST_CHECK(data_test_read_entries[2].read_pass == 2u);
    TEST_CHECK(data_test_read_entries[3].port == 1u);
    TEST_CHECK(data_test_read_entries[3].read_pass == 2u);
    TEST_CHECK(data_test_read_entries[4].port == 2u);
    TEST_CHECK(data_test_read_entries[4].read_pass == 2u);
    TEST_CHECK(model.trace.read_pass_count == 3u);
    TEST_CHECK(data_test_write_entries[0].addr ==
               DATA_TEST_COMPLEX_DST);
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(
            data_test_l1[DATA_TEST_COMPLEX_DST + index] ==
            expected[index]);
    }
    return 0;
}

static int data_test_softmax_three_read_passes(void)
{
    static const uint8_t expected[4] = {
        15u, 0u, 113u, 0u
    };
    static const uint8_t expected_port[6] = {
        3u, 0u, 3u, 0u, 3u, 0u
    };
    uint8_t descriptor[NPU_WIRE_COMPLEX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint32_t read_requests;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_softmax_descriptor(descriptor);
    for (index = 0u; index < 4u; index++) {
        data_test_l1[DATA_TEST_COMPLEX_SRC0 + index] =
            (uint8_t)(index + 1u);
        data_test_l1[DATA_TEST_COMPLEX_MASK + index] =
            (uint8_t)((index & 1u) == 0u);
        data_test_l1[DATA_TEST_COMPLEX_DST + index] =
            0x55u;
    }
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_COMPLEX));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(
            0x12cu, NPU_COMPLEX_SOFTMAX),
        &server, &outputs);
    if (line != 0) {
        return line;
    }

    TEST_CHECK(model.trace.read_count == 6u);
    TEST_CHECK(model.trace.read_pass_count == 3u);
    for (index = 0u; index < 6u; index++) {
        TEST_CHECK(data_test_read_entries[index].port ==
                   expected_port[index]);
        TEST_CHECK(
            data_test_read_entries[index].read_pass ==
            index / 2u);
    }
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(
            data_test_l1[DATA_TEST_COMPLEX_DST + index] ==
            0x55u);
    }

    line = data_test_finish_l1_replay(
        &model, &l1, done, &read_requests);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(read_requests == 6u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 4u);
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(
            data_test_l1[DATA_TEST_COMPLEX_DST + index] ==
            expected[index]);
    }
    return 0;
}

static int data_test_cme_numeric_flags(void)
{
    uint8_t descriptor[NPU_WIRE_COMPLEX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint32_t read_requests;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_softmax_descriptor(descriptor);
    descriptor[0x9eu] = NPU_ALL_MASK_ERROR;
    for (index = 0u; index < 4u; index++) {
        data_test_l1[DATA_TEST_COMPLEX_SRC0 + index] =
            (uint8_t)(index + 1u);
        data_test_l1[DATA_TEST_COMPLEX_MASK + index] = 0u;
        data_test_l1[DATA_TEST_COMPLEX_DST + index] =
            0x55u;
    }
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_COMPLEX));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(
            0x12fu, NPU_COMPLEX_SOFTMAX),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.engine.pending_status ==
               NPU_STATUS_NUMERIC_EXCEPTION);
    TEST_CHECK(model.perf_delta.all_mask_row_count == 1u);
    TEST_CHECK(
        model.compute_stage ==
        NPU_ENGINE_DATA_COMPUTE_DONE);
    TEST_CHECK(model.compute_total_cycles == 0u);

    data_test_idle_inputs(&inputs);
    npu_engine_data_cycle_eval(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.cme_i2f_active == 0u);
    TEST_CHECK(outputs.cme_fp_active == 0u);
    TEST_CHECK(outputs.cme_f2i_active == 0u);
    TEST_CHECK(outputs.cme_numeric_flag ==
               (NPU_ENGINE_DATA_CME_NUMERIC_EXCEPTION |
                NPU_ENGINE_DATA_CME_ALL_MASK));

    line = data_test_finish_l1_replay(
        &model, &l1, done, &read_requests);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(read_requests == 1u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_NUMERIC_EXCEPTION);
    TEST_CHECK(done[2] == 0u);
    TEST_CHECK(functional.perf.all_mask_row_count == 1u);
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(
            data_test_l1[DATA_TEST_COMPLEX_DST + index] ==
            0x55u);
    }
    return 0;
}

static int data_test_me_overflow_modes(void)
{
    npu_overflow_mode_t mode;

    for (mode = NPU_OVERFLOW_SATURATE;
         mode <= NPU_OVERFLOW_WRAP; mode++) {
        uint8_t descriptor[NPU_WIRE_MATRIX_DESC_BYTES];
        npu_model_t functional;
        npu_engine_data_cycle_t model;
        npu_engine_data_cycle_inputs_t inputs;
        npu_engine_data_cycle_outputs_t outputs;
        data_test_desc_server_t server;
        data_test_l1_t l1;
        uint64_t done[3] = {0u, 0u, 0u};
        uint32_t read_requests;
        npu_status_t expected_status =
            mode == NPU_OVERFLOW_ERROR
                ? NPU_STATUS_NUMERIC_EXCEPTION
                : NPU_STATUS_SUCCESS;
        int line;

        (void)memset(
            data_test_l1, 0, sizeof(data_test_l1));
        (void)memset(
            data_test_ddr, 0, sizeof(data_test_ddr));
        (void)memset(&server, 0, sizeof(server));
        (void)memset(&l1, 0, sizeof(l1));
        data_test_matrix_descriptor(descriptor);
        descriptor[0x94u] = (uint8_t)mode;
        data_test_l1[DATA_TEST_MATRIX_A] = 1u;
        data_test_l1[DATA_TEST_MATRIX_B] = 1u;
        data_test_put_u32(
            data_test_l1, DATA_TEST_MATRIX_BIAS,
            (uint32_t)INT32_MAX);
        TEST_CHECK(data_test_init_wrapper(
            &model, &functional, NPU_ENGINE_MATRIX));
        line = data_test_reach_replay(
            &model, descriptor,
            data_test_metadata(
                0x160u + (uint16_t)mode,
                NPU_MATRIX_GEMM),
            &server, &outputs);
        if (line != 0) {
            return line;
        }
        TEST_CHECK(
            model.engine.pending_status == expected_status);
        TEST_CHECK(
            model.engine.request.desc.matrix.bias_enable != 0u);
        TEST_CHECK(
            model.engine.request.desc.matrix.overflow_mode ==
            mode);
        TEST_CHECK(model.trace.select_read_port_context ==
                   (const void *)&model);
        if (mode != NPU_OVERFLOW_ERROR) {
            TEST_CHECK(model.trace.write_count == 1u);
            TEST_CHECK(
                (uint32_t)data_test_write_entries[0].data ==
                (mode == NPU_OVERFLOW_SATURATE
                     ? (uint32_t)INT32_MAX
                     : UINT32_C(0x80000000)));
        }
        TEST_CHECK(
            model.perf_delta.int_saturate_count ==
            (mode == NPU_OVERFLOW_SATURATE ? 1u : 0u));
        TEST_CHECK(model.me_acc_overflow_latched != 0u);

        data_test_idle_inputs(&inputs);
        npu_engine_data_cycle_eval(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.me_acc_overflow != 0u);

        line = data_test_finish_l1_replay(
            &model, &l1, done, &read_requests);
        if (line != 0) {
            return line;
        }
        TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
                   (uint64_t)expected_status);

        data_test_idle_inputs(&inputs);
        npu_engine_data_cycle_eval(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.me_acc_overflow == 0u);
    }
    return 0;
}

static int data_test_ive_overflow_modes(void)
{
    npu_overflow_mode_t mode;

    for (mode = NPU_OVERFLOW_SATURATE;
         mode <= NPU_OVERFLOW_WRAP; mode++) {
        uint8_t descriptor[NPU_WIRE_VECTOR_DESC_BYTES];
        npu_model_t functional;
        npu_engine_data_cycle_t model;
        npu_engine_data_cycle_inputs_t inputs;
        npu_engine_data_cycle_outputs_t outputs;
        data_test_desc_server_t server;
        data_test_l1_t l1;
        uint64_t done[3] = {0u, 0u, 0u};
        uint32_t read_requests;
        uint32_t numeric;
        uint32_t index;
        npu_status_t expected_status =
            mode == NPU_OVERFLOW_ERROR
                ? NPU_STATUS_NUMERIC_EXCEPTION
                : NPU_STATUS_SUCCESS;
        int line;

        (void)memset(
            data_test_l1, 0, sizeof(data_test_l1));
        (void)memset(
            data_test_ddr, 0, sizeof(data_test_ddr));
        (void)memset(&server, 0, sizeof(server));
        (void)memset(&l1, 0, sizeof(l1));
        data_test_vector_descriptor(descriptor);
        numeric = data_test_numeric_full(
            NPU_DTYPE_INT8, NPU_DTYPE_INT8,
            NPU_DTYPE_INT4, NPU_DTYPE_INT8,
            NPU_ROUND_NEAREST_EVEN,
            mode == NPU_OVERFLOW_SATURATE ? 1u : 0u,
            NPU_SCALE_PER_TENSOR, 0u);
        data_test_put_u32(descriptor, 0x38u, numeric);
        descriptor[0x7au] = (uint8_t)mode;
        for (index = 0u; index < 4u; index++) {
            data_test_l1[DATA_TEST_SRC0 + index] = 127u;
            data_test_l1[DATA_TEST_SRC1 + index] = 1u;
            data_test_l1[DATA_TEST_DST + index] = 0x55u;
        }
        TEST_CHECK(data_test_init_wrapper(
            &model, &functional, NPU_ENGINE_VECTOR));
        line = data_test_reach_replay(
            &model, descriptor,
            data_test_metadata(
                0x164u + (uint16_t)mode,
                NPU_VECTOR_ADD),
            &server, &outputs);
        if (line != 0) {
            return line;
        }
        TEST_CHECK(
            model.engine.pending_status == expected_status);
        TEST_CHECK(model.ive_overflow_latched != 0u);

        data_test_idle_inputs(&inputs);
        npu_engine_data_cycle_eval(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.ive_overflow != 0u);

        line = data_test_finish_l1_replay(
            &model, &l1, done, &read_requests);
        if (line != 0) {
            return line;
        }
        TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
                   (uint64_t)expected_status);

        data_test_idle_inputs(&inputs);
        npu_engine_data_cycle_eval(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.ive_overflow == 0u);
    }
    return 0;
}

static int data_test_cme_success_numeric_flags(void)
{
    uint8_t descriptor[NPU_WIRE_COMPLEX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint32_t read_requests;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_activation_descriptor(descriptor);
    data_test_put_u32(descriptor, 0x44u, 1u);
    data_test_put_u32(descriptor, 0x48u, 1u);
    data_test_put_u32(descriptor, 0x50u, 1u);
    data_test_put_u32(descriptor, 0x5cu, 1u);
    data_test_put_u32(descriptor, 0x70u, 0x7f7fffffu);
    data_test_l1[DATA_TEST_COMPLEX_SRC0] = 127u;
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_COMPLEX));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x168u, NPU_COMPLEX_ACT),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.engine.pending_status ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(
        model.cme_numeric_flags_latched ==
        (NPU_ENGINE_DATA_CME_OUTPUT_RANGE |
         NPU_ENGINE_DATA_CME_FP_INF));

    data_test_idle_inputs(&inputs);
    npu_engine_data_cycle_eval(
        &model, &inputs, &outputs);
    TEST_CHECK(
        outputs.cme_numeric_flag ==
        (NPU_ENGINE_DATA_CME_OUTPUT_RANGE |
         NPU_ENGINE_DATA_CME_FP_INF));

    line = data_test_finish_l1_replay(
        &model, &l1, done, &read_requests);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);

    data_test_idle_inputs(&inputs);
    npu_engine_data_cycle_eval(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.cme_numeric_flag == 0u);

    data_test_idle_inputs(&inputs);
    inputs.engine.eng_req_valid_i = 1u;
    inputs.engine.eng_req_data_i =
        data_test_metadata(0x169u, NPU_COMPLEX_ACT);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.engine.eng_req_ready_o != 0u);
    TEST_CHECK(model.cme_numeric_flags_latched == 0u);
    return 0;
}

static int data_test_rmsnorm_two_read_passes(void)
{
    static const uint8_t expected[4] = {
        6u, 12u, 18u, 23u
    };
    static const uint8_t expected_port[3] = {
        0u, 0u, 1u
    };
    static const uint32_t expected_pass[3] = {
        0u, 1u, 1u
    };
    uint8_t descriptor[NPU_WIRE_COMPLEX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint32_t read_requests;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_rmsnorm_descriptor(descriptor);
    for (index = 0u; index < 4u; index++) {
        data_test_l1[DATA_TEST_COMPLEX_SRC0 + index] =
            (uint8_t)(index + 1u);
        data_test_l1[DATA_TEST_COMPLEX_SRC1 + index] = 1u;
        data_test_l1[DATA_TEST_COMPLEX_DST + index] =
            0x55u;
    }
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_COMPLEX));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x12du, NPU_COMPLEX_NORM),
        &server, &outputs);
    if (line != 0) {
        return line;
    }

    TEST_CHECK(model.trace.read_count == 3u);
    TEST_CHECK(model.trace.read_pass_count == 2u);
    for (index = 0u; index < 3u; index++) {
        TEST_CHECK(data_test_read_entries[index].port ==
                   expected_port[index]);
        TEST_CHECK(
            data_test_read_entries[index].read_pass ==
            expected_pass[index]);
    }
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(
            data_test_l1[DATA_TEST_COMPLEX_DST + index] ==
            0x55u);
    }

    line = data_test_finish_l1_replay(
        &model, &l1, done, &read_requests);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(read_requests == 3u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 4u);
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(
            data_test_l1[DATA_TEST_COMPLEX_DST + index] ==
            expected[index]);
    }
    return 0;
}

static int data_test_l1_ecc_error(void)
{
    uint8_t descriptor[NPU_WIRE_VECTOR_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint8_t write_happened;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_vector_descriptor(descriptor);
    for (index = 0u; index < 4u; index++) {
        data_test_l1[DATA_TEST_SRC0 + index] =
            (uint8_t)(index + 1u);
        data_test_l1[DATA_TEST_SRC1 + index] =
            (uint8_t)(index + 2u);
        data_test_l1[DATA_TEST_DST + index] = 0x5au;
    }
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_VECTOR));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x127u, NPU_VECTOR_ADD),
        &server, &outputs);
    if (line != 0) {
        return line;
    }

    data_test_idle_inputs(&inputs);
    for (index = 0u; index < NPU_ENGINE_DATA_READ_PORTS;
         index++) {
        inputs.l1_read[index].req_ready = 1u;
    }
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.l1_read[0].req_valid != 0u);
    TEST_CHECK(outputs.l1_read[0].req_addr ==
               DATA_TEST_SRC0);
    line = data_test_update_l1(
        &l1, &inputs, &outputs, &write_happened);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(l1.read[0].valid != 0u);
    TEST_CHECK(l1.read[1].valid != 0u);

    l1.read[0].response_status =
        NPU_L1_STATUS_ECC_UNCORRECTABLE;
    l1.read[1].response_pause = 1u;
    data_test_idle_inputs(&inputs);
    data_test_drive_l1(&l1, &inputs);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.engine.eng_done_valid_o == 0u);
    line = data_test_update_l1(
        &l1, &inputs, &outputs, &write_happened);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(write_happened == 0u);
    TEST_CHECK(l1.read[0].valid == 0u);
    TEST_CHECK(l1.read[1].valid != 0u);
    TEST_CHECK(model.replay.terminal_locked != 0u);

    data_test_idle_inputs(&inputs);
    inputs.engine.eng_cancel_valid_i = 1u;
    inputs.engine.eng_cancel_status_i =
        NPU_STATUS_ABORTED;
    data_test_drive_l1(&l1, &inputs);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.engine.eng_cancel_ready_o == 0u);
    TEST_CHECK(outputs.engine.eng_done_valid_o == 0u);
    TEST_CHECK(outputs.l1_read[1].rsp_ready != 0u);

    l1.read[1].response_pause = 0u;
    l1.read[1].response_status =
        NPU_L1_STATUS_ECC_UNCORRECTABLE;
    data_test_idle_inputs(&inputs);
    data_test_drive_l1(&l1, &inputs);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    line = data_test_update_l1(
        &l1, &inputs, &outputs, &write_happened);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(l1.read[1].valid == 0u);

    line = data_test_accept_done(
        &model, &inputs, &outputs, done);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_L1_ECC_UNCORRECTABLE);
    TEST_CHECK(((done[0] >> 52u) & 0x0fffu) ==
               NPU_DONE_FAULT_ADDR_IS_L1);
    TEST_CHECK((done[1] &
                UINT64_C(0x0000ffffffffffff)) ==
               DATA_TEST_SRC0);
    TEST_CHECK(done[2] == 0u);
    for (index = 0u; index < 4u; index++) {
        TEST_CHECK(data_test_l1[DATA_TEST_DST + index] ==
                   0x5au);
    }
    return 0;
}

static int data_test_mif_error_and_hold(void)
{
    uint8_t descriptor[NPU_WIRE_DMA_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_mif_t mif;
    uint64_t done[3] = {0u, 0u, 0u};
    uint64_t held_addr = 0u;
    uint16_t held_tag = 0u;
    uint32_t cycle;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&mif, 0, sizeof(mif));
    data_test_ddr[DATA_TEST_DDR_SRC] = 0x12u;
    data_test_ddr[DATA_TEST_DDR_SRC + 1u] = 0x34u;
    data_test_dma_descriptor(descriptor);
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_DMA));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x128u, NPU_DMA_COPY_1D),
        &server, &outputs);
    if (line != 0) {
        return line;
    }

    for (cycle = 0u; cycle < 3u; cycle++) {
        data_test_idle_inputs(&inputs);
        inputs.mif.req_ready = 0u;
        npu_engine_data_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.mif.req_valid != 0u);
        TEST_CHECK(outputs.mif.req_write == 0u);
        TEST_CHECK(outputs.mif.req_vaddr ==
                   DATA_TEST_DDR_SRC);
        if (cycle == 0u) {
            held_addr = outputs.mif.req_vaddr;
            held_tag = outputs.mif.req_tag;
        } else {
            TEST_CHECK(outputs.mif.req_vaddr == held_addr);
            TEST_CHECK(outputs.mif.req_tag == held_tag);
        }
        TEST_CHECK(outputs.engine.eng_done_valid_o == 0u);
    }

    data_test_idle_inputs(&inputs);
    inputs.mif.req_ready = 1u;
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    line = data_test_update_mif(
        &mif, &inputs, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(mif.read_valid != 0u);
    mif.response_status = NPU_STATUS_BUS_SLVERR;

    data_test_idle_inputs(&inputs);
    data_test_drive_mif(&mif, &inputs);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.engine.eng_done_valid_o == 0u);
    line = data_test_update_mif(
        &mif, &inputs, &outputs);
    if (line != 0) {
        return line;
    }

    line = data_test_accept_done(
        &model, &inputs, &outputs, done);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_BUS_SLVERR);
    TEST_CHECK(((done[0] >> 52u) & 0x0fffu) == 0u);
    TEST_CHECK((done[1] &
                UINT64_C(0x0000ffffffffffff)) ==
               DATA_TEST_DDR_SRC);
    TEST_CHECK(done[2] == 0u);
    TEST_CHECK(data_test_l1[DATA_TEST_DMA_DST] == 0u);
    TEST_CHECK(data_test_l1[DATA_TEST_DMA_DST + 1u] == 0u);
    return 0;
}

static int data_test_cancel_pending_l1_read(void)
{
    uint8_t descriptor[NPU_WIRE_MATRIX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint8_t write_happened;
    uint32_t port;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_matrix_descriptor(descriptor);
    data_test_l1[DATA_TEST_MATRIX_A] = 2u;
    data_test_l1[DATA_TEST_MATRIX_A + 1u] = 3u;
    data_test_l1[DATA_TEST_MATRIX_B] = 4u;
    data_test_l1[DATA_TEST_MATRIX_B + NPU_REF_NT] =
        (uint8_t)-1;
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_MATRIX));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x129u, NPU_MATRIX_GEMM),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.trace.read_count > 1u);

    data_test_idle_inputs(&inputs);
    inputs.l1_read[0].req_ready = 1u;
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    line = data_test_update_l1(
        &l1, &inputs, &outputs, &write_happened);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(l1.read[0].valid != 0u);
    l1.read[0].response_pause = 1u;

    data_test_idle_inputs(&inputs);
    inputs.engine.eng_cancel_valid_i = 1u;
    inputs.engine.eng_cancel_status_i =
        NPU_STATUS_ABORTED;
    data_test_drive_l1(&l1, &inputs);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.engine.eng_cancel_ready_o != 0u);
    TEST_CHECK(outputs.engine.eng_done_valid_o == 0u);

    data_test_idle_inputs(&inputs);
    inputs.engine.eng_cancel_valid_i = 1u;
    inputs.engine.eng_cancel_status_i =
        NPU_STATUS_ABORTED;
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.engine.eng_cancel_ready_o == 0u);
    for (port = 0u; port < NPU_ENGINE_DATA_READ_PORTS;
         port++) {
        TEST_CHECK(outputs.l1_read[port].req_valid == 0u);
    }
    TEST_CHECK(outputs.engine.eng_done_valid_o == 0u);

    l1.read[0].response_pause = 0u;
    l1.read[0].response_status =
        NPU_L1_STATUS_ECC_UNCORRECTABLE;
    data_test_idle_inputs(&inputs);
    data_test_drive_l1(&l1, &inputs);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    line = data_test_update_l1(
        &l1, &inputs, &outputs, &write_happened);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(l1.read[0].valid == 0u);
    for (port = 0u; port < NPU_ENGINE_DATA_READ_PORTS;
         port++) {
        TEST_CHECK(outputs.l1_read[port].req_valid == 0u);
    }
    TEST_CHECK(model.replay.state == NPU_BUS_REPLAY_DONE);
    TEST_CHECK(model.replay.read_index == 1u);
    TEST_CHECK(model.replay.read_index <
               model.trace.read_count);

    line = data_test_accept_done(
        &model, &inputs, &outputs, done);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_ABORTED);
    TEST_CHECK(((done[0] >> 52u) & 0x0fffu) ==
               NPU_DONE_ABORT_DRAINED);
    TEST_CHECK(done[2] == 0u);
    TEST_CHECK(data_test_l1[DATA_TEST_MATRIX_DST] == 0u);
    return 0;
}

static int data_test_timeout_pending_mif_read(void)
{
    uint8_t descriptor[NPU_WIRE_DMA_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_mif_t mif;
    uint64_t done[3] = {0u, 0u, 0u};
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&mif, 0, sizeof(mif));
    data_test_ddr[DATA_TEST_DDR_SRC] = 0x12u;
    data_test_ddr[DATA_TEST_DDR_SRC + 1u] = 0x34u;
    data_test_dma_descriptor(descriptor);
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_DMA));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x12au, NPU_DMA_COPY_1D),
        &server, &outputs);
    if (line != 0) {
        return line;
    }

    data_test_idle_inputs(&inputs);
    inputs.mif.req_ready = 1u;
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    line = data_test_update_mif(
        &mif, &inputs, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(mif.read_valid != 0u);
    mif.response_pause = 1u;

    data_test_idle_inputs(&inputs);
    inputs.engine.eng_cancel_valid_i = 1u;
    inputs.engine.eng_cancel_status_i =
        NPU_STATUS_TIMEOUT;
    data_test_drive_mif(&mif, &inputs);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.engine.eng_cancel_ready_o != 0u);
    TEST_CHECK(outputs.engine.eng_done_valid_o == 0u);

    data_test_idle_inputs(&inputs);
    inputs.engine.eng_cancel_valid_i = 1u;
    inputs.engine.eng_cancel_status_i =
        NPU_STATUS_TIMEOUT;
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.engine.eng_cancel_ready_o == 0u);
    TEST_CHECK(outputs.mif.req_valid == 0u);
    TEST_CHECK(outputs.engine.eng_done_valid_o == 0u);

    mif.response_pause = 0u;
    mif.response_status = NPU_STATUS_BUS_SLVERR;
    data_test_idle_inputs(&inputs);
    data_test_drive_mif(&mif, &inputs);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    line = data_test_update_mif(
        &mif, &inputs, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(mif.read_valid == 0u);
    TEST_CHECK(outputs.mif.req_valid == 0u);
    TEST_CHECK(model.replay.state == NPU_BUS_REPLAY_DONE);
    TEST_CHECK(model.replay.read_index == 1u);

    line = data_test_accept_done(
        &model, &inputs, &outputs, done);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_TIMEOUT);
    TEST_CHECK(((done[0] >> 52u) & 0x0fffu) == 0u);
    TEST_CHECK(done[2] == 0u);
    TEST_CHECK(data_test_l1[DATA_TEST_DMA_DST] == 0u);
    TEST_CHECK(data_test_l1[DATA_TEST_DMA_DST + 1u] == 0u);
    return 0;
}

static int data_test_cancel_pending_write_response(void)
{
    uint8_t descriptor[NPU_WIRE_VECTOR_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    npu_l1_cycle_write_input_t held_data = {0};
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint8_t write_happened;
    uint8_t write_request_seen = 0u;
    uint8_t held_data_valid = 0u;
    uint32_t data_pause_cycles = 0u;
    uint32_t cycle;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_vector_descriptor(descriptor);
    for (index = 0u; index < 4u; index++) {
        data_test_l1[DATA_TEST_SRC0 + index] =
            (uint8_t)(index + 1u);
        data_test_l1[DATA_TEST_SRC1 + index] =
            (uint8_t)(10u * (index + 1u));
    }
    l1.write_response_pause = 1u;
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_VECTOR));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x12bu, NPU_VECTOR_ADD),
        &server, &outputs);
    if (line != 0) {
        return line;
    }

    for (cycle = 0u; cycle < DATA_TEST_MAX_CYCLES; cycle++) {
        data_test_idle_inputs(&inputs);
        for (index = 0u;
             index < NPU_ENGINE_DATA_READ_PORTS;
             index++) {
            inputs.l1_read[index].req_ready = 1u;
        }
        inputs.l1_write.req_ready = 1u;
        inputs.l1_write.data_ready =
            write_request_seen != 0u &&
                    data_pause_cycles >= 2u
                ? 1u
                : 0u;
        data_test_drive_l1(&l1, &inputs);
        npu_engine_data_cycle_step(
            &model, &inputs, &outputs);

        if (held_data_valid != 0u) {
            TEST_CHECK(outputs.l1_write.data_valid != 0u);
            TEST_CHECK(outputs.l1_write.data ==
                       held_data.data);
            TEST_CHECK(outputs.l1_write.strb ==
                       held_data.strb);
            TEST_CHECK(outputs.l1_write.last ==
                       held_data.last);
        }
        held_data_valid =
            outputs.l1_write.data_valid != 0u &&
                    inputs.l1_write.data_ready == 0u
                ? 1u
                : 0u;
        held_data = outputs.l1_write;
        if (outputs.l1_write.req_valid != 0u &&
            inputs.l1_write.req_ready != 0u) {
            write_request_seen = 1u;
        }
        if (write_request_seen != 0u &&
            inputs.l1_write.data_ready == 0u) {
            data_pause_cycles++;
        }

        line = data_test_update_l1(
            &l1, &inputs, &outputs, &write_happened);
        if (line != 0) {
            return line;
        }
        if (write_happened == 0u) {
            for (index = 0u; index < 4u; index++) {
                TEST_CHECK(
                    data_test_l1[DATA_TEST_DST + index] ==
                    0u);
            }
        } else {
            break;
        }
        TEST_CHECK(outputs.engine.eng_done_valid_o == 0u);
    }
    TEST_CHECK(cycle < DATA_TEST_MAX_CYCLES);
    TEST_CHECK(l1.write_response_valid != 0u);
    for (index = 0u; index < 4u; index++) {
        static const uint8_t expected[4] = {
            11u, 22u, 33u, 44u
        };

        TEST_CHECK(data_test_l1[DATA_TEST_DST + index] ==
                   expected[index]);
    }

    data_test_idle_inputs(&inputs);
    inputs.engine.eng_cancel_valid_i = 1u;
    inputs.engine.eng_cancel_status_i =
        NPU_STATUS_ABORTED;
    data_test_drive_l1(&l1, &inputs);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.engine.eng_cancel_ready_o != 0u);
    TEST_CHECK(outputs.engine.eng_done_valid_o == 0u);

    l1.write_response_pause = 0u;
    data_test_idle_inputs(&inputs);
    data_test_drive_l1(&l1, &inputs);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    line = data_test_update_l1(
        &l1, &inputs, &outputs, &write_happened);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(l1.write_response_valid == 0u);
    TEST_CHECK(outputs.engine.eng_done_valid_o == 0u);

    line = data_test_accept_done(
        &model, &inputs, &outputs, done);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_ABORTED);
    TEST_CHECK(((done[0] >> 52u) & 0x0fffu) ==
               (NPU_DONE_ABORT_DRAINED |
                NPU_DONE_PARTIAL_DEST));
    TEST_CHECK(done[2] == 4u);
    return 0;
}

static int data_test_zero_activity(void)
{
    uint8_t vector_desc[NPU_WIRE_VECTOR_DESC_BYTES];
    uint8_t matrix_desc[NPU_WIRE_MATRIX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint32_t read_requests;
    int line;

    (void)memset(data_test_l1, 0xa5, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    data_test_vector_descriptor(vector_desc);
    data_test_put_u32(vector_desc, 0x40u, 0u);
    data_test_put_u32(vector_desc, 0x44u, 0u);
    data_test_put_u32(vector_desc, 0x48u, 0u);
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_VECTOR));
    line = data_test_reach_replay(
        &model, vector_desc,
        data_test_metadata(0x140u, NPU_VECTOR_ADD),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(
        model.compute_stage ==
        NPU_ENGINE_DATA_COMPUTE_DONE);
    TEST_CHECK(outputs.ive_alu_active == 0u);
    TEST_CHECK(outputs.ive_lane_valid == 0u);
    TEST_CHECK(model.trace.read_count == 0u);
    TEST_CHECK(model.trace.write_count == 0u);

    data_test_idle_inputs(&inputs);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    TEST_CHECK(outputs.ive_alu_active == 0u);
    TEST_CHECK(outputs.ive_lane_valid == 0u);
    line = data_test_accept_done(
        &model, &inputs, &outputs, done);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 0u);

    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_matrix_zero_descriptor(matrix_desc);
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_MATRIX));
    line = data_test_reach_replay(
        &model, matrix_desc,
        data_test_metadata(
            0x141u, NPU_MATRIX_GEMM_ZERO),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(
        model.compute_stage ==
        NPU_ENGINE_DATA_COMPUTE_DONE);
    TEST_CHECK(outputs.me_mac_active == 0u);
    TEST_CHECK(model.trace.read_count == 0u);
    TEST_CHECK(model.trace.write_count == 1u);
    line = data_test_finish_l1_replay(
        &model, &l1, done, &read_requests);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(read_requests == 0u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 2u);
    TEST_CHECK(
        data_test_get_u64(
            data_test_l1, DATA_TEST_MATRIX_DST) == 0u);
    return 0;
}

static int data_test_vstat_activity(void)
{
    uint8_t descriptor[NPU_WIRE_COMPLEX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint8_t done_beat = 0u;
    uint8_t write_happened;
    uint8_t write_seen = 0u;
    uint8_t stage = 0u;
    uint32_t i2f_cycles = 0u;
    uint32_t f2i_cycles = 0u;
    uint32_t cycle;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_stat_descriptor(descriptor);
    for (index = 0u; index < 5u; index++) {
        data_test_l1[DATA_TEST_COMPLEX_SRC0 + index] =
            (uint8_t)(index + 1u);
    }
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_COMPLEX));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x142u, NPU_COMPLEX_STAT),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(outputs.cme_i2f_active == 0u);
    TEST_CHECK(outputs.cme_fp_active == 0u);
    TEST_CHECK(outputs.cme_f2i_active == 0u);
    TEST_CHECK(
        model.compute_stage ==
        NPU_ENGINE_DATA_COMPUTE_DONE);

    for (cycle = 0u; cycle < DATA_TEST_MAX_CYCLES; cycle++) {
        data_test_idle_inputs(&inputs);
        for (index = 0u;
             index < NPU_ENGINE_DATA_READ_PORTS;
             index++) {
            inputs.l1_read[index].req_ready = 1u;
        }
        data_test_drive_l1(&l1, &inputs);
        npu_engine_data_cycle_step(
            &model, &inputs, &outputs);
        TEST_CHECK(outputs.cme_fp_active == 0u);
        if (outputs.cme_i2f_active != 0u) {
            TEST_CHECK(stage <= 1u);
            stage = 1u;
            i2f_cycles++;
        }
        if (outputs.cme_f2i_active != 0u) {
            TEST_CHECK(stage <= 2u);
            stage = 2u;
            f2i_cycles++;
        }
        if (outputs.cme_i2f_active != 0u ||
            outputs.cme_f2i_active != 0u) {
            TEST_CHECK(
                !data_test_l1_any_read_valid(&l1));
            TEST_CHECK(write_seen == 0u);
            TEST_CHECK(outputs.l1_write.req_valid == 0u);
            TEST_CHECK(outputs.l1_write.data_valid == 0u);
        }
        line = data_test_update_l1(
            &l1, &inputs, &outputs, &write_happened);
        if (line != 0) {
            return line;
        }
        if (write_happened != 0u) {
            write_seen = 1u;
        }
        if (outputs.engine.eng_done_valid_o != 0u) {
            TEST_CHECK(done_beat < 3u);
            done[done_beat] =
                outputs.engine.eng_done_data_o;
            data_test_idle_inputs(&inputs);
            inputs.engine.eng_done_ready_i = 1u;
            npu_engine_data_cycle_step(
                &model, &inputs, &outputs);
            done_beat++;
        }
        if (done_beat == 3u) {
            break;
        }
    }

    TEST_CHECK(cycle < DATA_TEST_MAX_CYCLES);
    TEST_CHECK(i2f_cycles == 0u);
    TEST_CHECK(f2i_cycles == 0u);
    TEST_CHECK(write_seen != 0u);
    TEST_CHECK(done_beat == 3u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(model.trace.read_count == 1u);
    TEST_CHECK(model.trace.write_count == 1u);
    TEST_CHECK(
        (uint32_t)data_test_get_u64(
            data_test_l1, DATA_TEST_COMPLEX_DST) == 15u);
    return 0;
}

static int data_test_cme_overlapped_pipeline(void)
{
    uint8_t descriptor[NPU_WIRE_COMPLEX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    npu_engine_data_cycle_outputs_t preview;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint8_t done_beat = 0u;
    uint8_t write_happened;
    uint8_t write_seen = 0u;
    uint8_t i2f_fp_overlap = 0u;
    uint8_t fp_f2i_overlap = 0u;
    uint8_t eval_overlap_checked = 0u;
    uint8_t read_compute_overlap_seen = 0u;
    uint32_t i2f_cycles = 0u;
    uint32_t fp_cycles = 0u;
    uint32_t f2i_cycles = 0u;
    uint32_t activity_cycles = 0u;
    uint64_t last_f2i_elapsed = UINT64_MAX;
    uint32_t cycle;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0, sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0, sizeof(data_test_ddr));
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    data_test_activation_descriptor(descriptor);
    for (index = 0u; index < 9u; index++) {
        data_test_l1[DATA_TEST_COMPLEX_SRC0 + index] =
            (uint8_t)((int32_t)index - 4);
        data_test_l1[DATA_TEST_COMPLEX_DST + index] = 0x55u;
    }
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_COMPLEX));
    line = data_test_reach_replay(
        &model, descriptor,
        data_test_metadata(0x143u, NPU_COMPLEX_ACT),
        &server, &outputs);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(
        model.compute_stage ==
        NPU_ENGINE_DATA_COMPUTE_CME_PIPELINE);
    TEST_CHECK(model.compute_groups == 3u);
    TEST_CHECK(model.cme_i2f_start == 0u);
    TEST_CHECK(model.cme_i2f_cycles == 5u);
    TEST_CHECK(model.cme_fp_start == 3u);
    TEST_CHECK(model.cme_fp_cycles == 12u);
    TEST_CHECK(model.cme_f2i_start == 13u);
    TEST_CHECK(model.cme_f2i_cycles == 6u);
    TEST_CHECK(model.compute_total_cycles == 19u);

    for (cycle = 0u; cycle < DATA_TEST_MAX_CYCLES; cycle++) {
        uint64_t elapsed_before = model.compute_elapsed;

        data_test_idle_inputs(&inputs);
        for (index = 0u;
             index < NPU_ENGINE_DATA_READ_PORTS;
             index++) {
            inputs.l1_read[index].req_ready = 1u;
        }
        data_test_drive_l1(&l1, &inputs);
        if (model.compute_stage ==
                NPU_ENGINE_DATA_COMPUTE_CME_PIPELINE &&
            model.compute_elapsed == 3u &&
            eval_overlap_checked == 0u) {
            npu_engine_data_cycle_eval(
                &model, &inputs, &preview);
            TEST_CHECK(preview.cme_i2f_active != 0u);
            TEST_CHECK(preview.cme_fp_active != 0u);
            npu_engine_data_cycle_eval(
                &model, &inputs, &preview);
            TEST_CHECK(preview.cme_i2f_active != 0u);
            TEST_CHECK(preview.cme_fp_active != 0u);
            TEST_CHECK(model.compute_elapsed == 3u);
            eval_overlap_checked = 1u;
        }
        {
            npu_bus_replay_state_t replay_state_before =
                model.replay.state;

            npu_engine_data_cycle_step(
                &model, &inputs, &outputs);
            if ((outputs.cme_i2f_active != 0u ||
                 outputs.cme_fp_active != 0u ||
                 outputs.cme_f2i_active != 0u) &&
                (replay_state_before ==
                     NPU_BUS_REPLAY_READ_REQUEST ||
                 replay_state_before ==
                     NPU_BUS_REPLAY_READ_RESPONSE)) {
                read_compute_overlap_seen = 1u;
            }
        }
        if (outputs.cme_i2f_active != 0u ||
            outputs.cme_fp_active != 0u ||
            outputs.cme_f2i_active != 0u) {
            TEST_CHECK(write_seen == 0u);
            activity_cycles++;
        }
        if (outputs.cme_i2f_active != 0u) {
            i2f_cycles++;
        }
        if (outputs.cme_fp_active != 0u) {
            fp_cycles++;
        }
        if (outputs.cme_f2i_active != 0u) {
            f2i_cycles++;
            last_f2i_elapsed = elapsed_before;
        }
        if (outputs.cme_i2f_active != 0u &&
            outputs.cme_fp_active != 0u) {
            i2f_fp_overlap = 1u;
        }
        if (outputs.cme_fp_active != 0u &&
            outputs.cme_f2i_active != 0u) {
            fp_f2i_overlap = 1u;
        }
        line = data_test_update_l1(
            &l1, &inputs, &outputs, &write_happened);
        if (line != 0) {
            return line;
        }
        if (write_happened != 0u) {
            TEST_CHECK(f2i_cycles == 6u);
            TEST_CHECK(last_f2i_elapsed == 18u);
            write_seen = 1u;
        }
        if (outputs.engine.eng_done_valid_o != 0u) {
            TEST_CHECK(done_beat < 3u);
            done[done_beat] =
                outputs.engine.eng_done_data_o;
            data_test_idle_inputs(&inputs);
            inputs.engine.eng_done_ready_i = 1u;
            npu_engine_data_cycle_step(
                &model, &inputs, &outputs);
            done_beat++;
        }
        if (done_beat == 3u) {
            break;
        }
    }

    TEST_CHECK(cycle < DATA_TEST_MAX_CYCLES);
    TEST_CHECK(i2f_cycles == 5u);
    TEST_CHECK(fp_cycles == 12u);
    TEST_CHECK(f2i_cycles == 6u);
    TEST_CHECK(activity_cycles == 19u);
    TEST_CHECK(i2f_fp_overlap != 0u);
    TEST_CHECK(fp_f2i_overlap != 0u);
    TEST_CHECK(eval_overlap_checked != 0u);
    TEST_CHECK(read_compute_overlap_seen != 0u);
    TEST_CHECK(last_f2i_elapsed == 18u);
    TEST_CHECK(write_seen != 0u);
    TEST_CHECK(done_beat == 3u);
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(model.trace.read_count == 2u);
    TEST_CHECK(model.trace.write_count == 2u);
    return 0;
}

static int data_test_expect_param_fault(
    npu_engine_t engine,
    const uint8_t *descriptor,
    uint16_t task_id,
    uint8_t opcode,
    uint32_t param_base,
    uint32_t param_limit,
    uint8_t param_lock,
    uint64_t expected_fault_addr,
    size_t expected_write_words)
{
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_inputs_t inputs;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    uint64_t done[3] = {0u, 0u, 0u};
    uint32_t port;
    int line;

    (void)memset(&server, 0, sizeof(server));
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, engine));
    line = data_test_reach_replay_param(
        &model, descriptor,
        data_test_metadata(task_id, opcode),
        &server, &outputs, param_base, param_limit,
        param_lock);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.engine.pending_status ==
               NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(model.engine.pending_fault_addr ==
               expected_fault_addr);
    TEST_CHECK(model.engine.pending_done_flags ==
               NPU_DONE_FAULT_ADDR_IS_L1);
    TEST_CHECK(model.engine.pending_progress == 0u);
    TEST_CHECK(model.perf_delta_valid == 0u);
    TEST_CHECK(model.trace.read_count == 0u);
    TEST_CHECK(model.trace.write_count ==
               expected_write_words);
    TEST_CHECK(model.compute_stage ==
               NPU_ENGINE_DATA_COMPUTE_DONE);

    data_test_idle_inputs(&inputs);
    data_test_set_param_region(
        &inputs, param_base, param_limit, param_lock);
    npu_engine_data_cycle_step(
        &model, &inputs, &outputs);
    for (port = 0u; port < NPU_ENGINE_DATA_READ_PORTS;
         port++) {
        TEST_CHECK(outputs.l1_read[port].req_valid == 0u);
    }
    TEST_CHECK(outputs.l1_write.req_valid == 0u);
    TEST_CHECK(outputs.l1_write.data_valid == 0u);
    TEST_CHECK(outputs.mif.req_valid == 0u);
    TEST_CHECK(outputs.mif.wvalid == 0u);

    line = data_test_accept_done(
        &model, &inputs, &outputs, done);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_ADDR_FAULT);
    TEST_CHECK(((done[0] >> 20u) & 0xffffffffu) ==
               npu_engine_cycle_error_info(
                   NPU_ENGINE_ERROR_EXECUTE,
                   NPU_STATUS_ADDR_FAULT,
                   NPU_ENGINE_INVALID_DESC_WORD,
                   opcode));
    TEST_CHECK(((done[0] >> 52u) & 0x0fffu) ==
               NPU_DONE_FAULT_ADDR_IS_L1);
    TEST_CHECK((done[1] &
                UINT64_C(0x0000ffffffffffff)) ==
               expected_fault_addr);
    TEST_CHECK(done[2] == 0u);
    TEST_CHECK(functional.perf.task_success == 0u);
    TEST_CHECK(functional.perf.task_failed == 0u);
    return 0;
}

static int data_test_param_region_precheck(void)
{
    uint8_t vector_desc[NPU_WIRE_VECTOR_DESC_BYTES];
    uint8_t dma_desc[NPU_WIRE_DMA_DESC_BYTES];
    uint8_t matrix_desc[NPU_WIRE_MATRIX_DESC_BYTES];
    uint8_t complex_desc[NPU_WIRE_COMPLEX_DESC_BYTES];
    npu_model_t functional;
    npu_engine_data_cycle_t model;
    npu_engine_data_cycle_outputs_t outputs;
    data_test_desc_server_t server;
    data_test_l1_t l1;
    uint64_t done[3] = {0u, 0u, 0u};
    uint32_t read_requests;
    uint32_t index;
    int line;

    (void)memset(data_test_l1, 0x5a,
                 sizeof(data_test_l1));
    (void)memset(data_test_ddr, 0,
                 sizeof(data_test_ddr));

    /*
     * IVE has two destination words. The first is outside the
     * parameter region and the second is inside it. No destination byte
     * may change when the full-task check reports the later conflict.
     */
    data_test_vector_descriptor(vector_desc);
    data_test_put_u32(vector_desc, 0x44u, 16u);
    data_test_put_u32(vector_desc, 0x48u, 16u);
    line = data_test_expect_param_fault(
        NPU_ENGINE_VECTOR, vector_desc, 0x150u,
        NPU_VECTOR_ADD, DATA_TEST_DST + 8u,
        DATA_TEST_DST + 16u, 0u,
        DATA_TEST_DST + 8u, 2u);
    if (line != 0) {
        return line;
    }
    for (index = 0u; index < 16u; index++) {
        TEST_CHECK(data_test_l1[DATA_TEST_DST + index] ==
                   0x5au);
    }

    /*
     * Raw L1-to-L1 COPY_1D is the only unlocked write case. It must
     * complete normally even when its second destination word is inside
     * the configured region.
     */
    data_test_dma_descriptor(dma_desc);
    data_test_put_u32(dma_desc, 0x04u, 0u);
    data_test_put_u64(dma_desc, 0x08u, DATA_TEST_SRC0);
    dma_desc[0x41u] = NPU_SPACE_L1;
    data_test_put_u32(dma_desc, 0x48u, 16u);
    data_test_put_u64(dma_desc, 0x98u, 16u);
    data_test_put_u64(dma_desc, 0xa0u, 16u);
    for (index = 0u; index < 16u; index++) {
        data_test_l1[DATA_TEST_SRC0 + index] =
            (uint8_t)(index + 1u);
        data_test_l1[DATA_TEST_DMA_DST + index] = 0x5au;
    }
    (void)memset(&server, 0, sizeof(server));
    (void)memset(&l1, 0, sizeof(l1));
    TEST_CHECK(data_test_init_wrapper(
        &model, &functional, NPU_ENGINE_DMA));
    line = data_test_reach_replay_param(
        &model, dma_desc,
        data_test_metadata(0x151u, NPU_DMA_COPY_1D),
        &server, &outputs, DATA_TEST_DMA_DST + 8u,
        DATA_TEST_DMA_DST + 16u, 0u);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(model.engine.pending_status ==
               NPU_STATUS_SUCCESS);
    line = data_test_finish_l1_replay(
        &model, &l1, done, &read_requests);
    if (line != 0) {
        return line;
    }
    TEST_CHECK(((done[0] >> 12u) & 0xffu) ==
               NPU_STATUS_SUCCESS);
    TEST_CHECK(done[2] == 16u);
    for (index = 0u; index < 16u; index++) {
        TEST_CHECK(
            data_test_l1[DATA_TEST_DMA_DST + index] ==
            (uint8_t)(index + 1u));
    }

    /*
     * The same raw copy is rejected while locked. This also verifies that
     * a legal first destination word is not written before the conflict
     * in the second word is known.
     */
    for (index = 0u; index < 16u; index++) {
        data_test_l1[DATA_TEST_DMA_DST + index] = 0x5au;
    }
    line = data_test_expect_param_fault(
        NPU_ENGINE_DMA, dma_desc, 0x152u,
        NPU_DMA_COPY_1D, DATA_TEST_DMA_DST + 8u,
        DATA_TEST_DMA_DST + 16u, 1u,
        DATA_TEST_DMA_DST + 8u, 2u);
    if (line != 0) {
        return line;
    }
    for (index = 0u; index < 16u; index++) {
        TEST_CHECK(
            data_test_l1[DATA_TEST_DMA_DST + index] ==
            0x5au);
    }

    /*
     * A legal SIGN_EXTEND copy is not a raw byte copy and is rejected
     * even before PARAM_LOCK is set.
     */
    data_test_dma_descriptor(dma_desc);
    data_test_put_u32(
        dma_desc, 0x38u,
        (uint32_t)NPU_DTYPE_INT8 |
            ((uint32_t)NPU_DTYPE_INT32 << 6u));
    dma_desc[0x43u] = NPU_DMA_SIGN_EXTEND;
    data_test_put_u64(dma_desc, 0xa0u, 8u);
    line = data_test_expect_param_fault(
        NPU_ENGINE_DMA, dma_desc, 0x153u,
        NPU_DMA_COPY_1D, DATA_TEST_DMA_DST,
        DATA_TEST_DMA_DST + 8u, 0u,
        DATA_TEST_DMA_DST, 1u);
    if (line != 0) {
        return line;
    }

    data_test_matrix_zero_descriptor(matrix_desc);
    line = data_test_expect_param_fault(
        NPU_ENGINE_MATRIX, matrix_desc, 0x154u,
        NPU_MATRIX_GEMM_ZERO, DATA_TEST_MATRIX_DST,
        DATA_TEST_MATRIX_DST + 8u, 0u,
        DATA_TEST_MATRIX_DST, 1u);
    if (line != 0) {
        return line;
    }

    data_test_stat_descriptor(complex_desc);
    return data_test_expect_param_fault(
        NPU_ENGINE_COMPLEX, complex_desc, 0x155u,
        NPU_COMPLEX_STAT, DATA_TEST_COMPLEX_DST,
        DATA_TEST_COMPLEX_DST + 8u, 0u,
        DATA_TEST_COMPLEX_DST, 1u);
}

int test_engine_data_cycle(void)
{
    int line = data_test_workspace_validation();

    if (line != 0) {
        return line;
    }
    line = data_test_vector_replay();

    if (line != 0) {
        return line;
    }
    line = data_test_vector_int16_geometry();
    if (line != 0) {
        return line;
    }
    line = data_test_dma_replay();
    if (line != 0) {
        return line;
    }
    line = data_test_dma_sixteen_beat_burst();
    if (line != 0) {
        return line;
    }
    line = data_test_matrix_replay();
    if (line != 0) {
        return line;
    }
    line = data_test_matrix_int16_b_span();
    if (line != 0) {
        return line;
    }
    line = data_test_matrix_k_tile_activity();
    if (line != 0) {
        return line;
    }
    line = data_test_complex_replay();
    if (line != 0) {
        return line;
    }
    line = data_test_zero_activity();
    if (line != 0) {
        return line;
    }
    line = data_test_vstat_activity();
    if (line != 0) {
        return line;
    }
    line = data_test_cme_overlapped_pipeline();
    if (line != 0) {
        return line;
    }
    line = data_test_param_region_precheck();
    if (line != 0) {
        return line;
    }
    line = data_test_softmax_three_read_passes();
    if (line != 0) {
        return line;
    }
    line = data_test_cme_numeric_flags();
    if (line != 0) {
        return line;
    }
    line = data_test_me_overflow_modes();
    if (line != 0) {
        return line;
    }
    line = data_test_ive_overflow_modes();
    if (line != 0) {
        return line;
    }
    line = data_test_cme_success_numeric_flags();
    if (line != 0) {
        return line;
    }
    line = data_test_rmsnorm_two_read_passes();
    if (line != 0) {
        return line;
    }
    line = data_test_l1_ecc_error();
    if (line != 0) {
        return line;
    }
    line = data_test_mif_error_and_hold();
    if (line != 0) {
        return line;
    }
    line = data_test_cancel_pending_l1_read();
    if (line != 0) {
        return line;
    }
    line = data_test_timeout_pending_mif_read();
    if (line != 0) {
        return line;
    }
    return data_test_cancel_pending_write_response();
}

#ifdef NPU_ENGINE_DATA_CYCLE_STANDALONE
int main(void)
{
    return test_engine_data_cycle();
}
#endif
