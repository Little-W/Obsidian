#include "npu_bus_trace.h"
#include "test_util.h"

#include <string.h>

#define TRACE_TEST_ENTRY_CAPACITY 16u
#define TRACE_TEST_HASH_SLOTS 32u
#define TRACE_TEST_DDR_BYTES 4096u

static uint8_t trace_test_l1[NPU_REF_L1_BYTES];
static uint8_t trace_test_ddr[TRACE_TEST_DDR_BYTES];

static npu_tensor_t trace_test_tensor(npu_dtype_t dtype,
                                      uint64_t addr,
                                      uint64_t bytes)
{
    npu_tensor_t tensor;

    (void)memset(&tensor, 0, sizeof(tensor));
    tensor.space = NPU_SPACE_L1;
    tensor.dtype = dtype;
    tensor.addr = addr;
    tensor.region_bytes = bytes;
    tensor.row_stride_bytes = (uint32_t)bytes;
    return tensor;
}

static uint8_t trace_test_select_port(
    const void *context,
    npu_space_t space,
    uint64_t aligned_addr)
{
    (void)context;
    if (space != NPU_SPACE_L1) {
        return NPU_BUS_TRACE_IGNORE_PORT;
    }
    if (aligned_addr == UINT64_C(0x100)) {
        return 0u;
    }
    if (aligned_addr == UINT64_C(0x200)) {
        return 1u;
    }
    return NPU_BUS_TRACE_IGNORE_PORT;
}

static int trace_test_direct_capture(void)
{
    npu_bus_trace_entry_t read[TRACE_TEST_ENTRY_CAPACITY];
    npu_bus_trace_entry_t write[TRACE_TEST_ENTRY_CAPACITY];
    uint32_t read_hash[TRACE_TEST_HASH_SLOTS];
    uint32_t write_hash[TRACE_TEST_HASH_SLOTS];
    npu_bus_trace_t trace;
    uint8_t value = 0u;

    TEST_CHECK(npu_bus_trace_begin(
        &trace, read, TRACE_TEST_ENTRY_CAPACITY,
        read_hash, TRACE_TEST_HASH_SLOTS,
        write, TRACE_TEST_ENTRY_CAPACITY,
        write_hash, TRACE_TEST_HASH_SLOTS,
        2u, trace_test_select_port,
        (const void *)0));
    TEST_CHECK(npu_bus_trace_record_read_byte(
        &trace, NPU_SPACE_L1, UINT64_C(0x100), 0x12u));
    TEST_CHECK(npu_bus_trace_record_read_byte(
        &trace, NPU_SPACE_L1, UINT64_C(0x107), 0x34u));
    TEST_CHECK(npu_bus_trace_record_read_byte(
        &trace, NPU_SPACE_L1, UINT64_C(0x200), 0x56u));
    TEST_CHECK(npu_bus_trace_record_read_byte(
        &trace, NPU_SPACE_L1, UINT64_C(0x300), 0x78u));
    TEST_CHECK(trace.read_count == 2u);
    TEST_CHECK(trace.read[0].addr == UINT64_C(0x100));
    TEST_CHECK(trace.read[0].strb == 0x81u);
    TEST_CHECK((trace.read[0].data & UINT64_C(0xff)) == 0x12u);
    TEST_CHECK((trace.read[0].data >> 56u) == 0x34u);
    TEST_CHECK(trace.read[1].port == 1u);
    TEST_CHECK(trace.read[0].read_pass == 0u);
    TEST_CHECK(trace.read_pass_count == 1u);

    TEST_CHECK(npu_bus_trace_next_read_pass(&trace));
    TEST_CHECK(npu_bus_trace_record_read_byte(
        &trace, NPU_SPACE_L1, UINT64_C(0x100), 0x12u));
    TEST_CHECK(trace.read_count == 3u);
    TEST_CHECK(trace.read[2].addr == UINT64_C(0x100));
    TEST_CHECK(trace.read[2].read_pass == 1u);
    TEST_CHECK(trace.read_pass_count == 2u);
    TEST_CHECK(npu_bus_trace_set_read_capture(
                   &trace, 0u) == 1u);
    TEST_CHECK(npu_bus_trace_record_read_byte(
        &trace, NPU_SPACE_L1, UINT64_C(0x207), 0x9au));
    TEST_CHECK(trace.read_count == 3u);
    TEST_CHECK(npu_bus_trace_set_read_capture(
                   &trace, 1u) == 0u);

    TEST_CHECK(npu_bus_trace_record_write_byte(
        &trace, NPU_SPACE_L1, UINT64_C(0x302), 0xa5u));
    TEST_CHECK(npu_bus_trace_record_write_byte(
        &trace, NPU_SPACE_L1, UINT64_C(0x307), 0x5au));
    TEST_CHECK(trace.write_count == 1u);
    TEST_CHECK(trace.write[0].strb == 0x84u);
    TEST_CHECK(npu_bus_trace_lookup_write_byte(
        &trace, NPU_SPACE_L1, UINT64_C(0x302), &value));
    TEST_CHECK(value == 0xa5u);
    TEST_CHECK(!npu_bus_trace_lookup_write_byte(
        &trace, NPU_SPACE_L1, UINT64_C(0x303), &value));
    npu_bus_trace_end(&trace);
    TEST_CHECK(trace.active == 0u);
    return 0;
}

static int trace_test_vector_capture(void)
{
    npu_bus_trace_entry_t read[TRACE_TEST_ENTRY_CAPACITY];
    npu_bus_trace_entry_t write[TRACE_TEST_ENTRY_CAPACITY];
    uint32_t read_hash[TRACE_TEST_HASH_SLOTS];
    uint32_t write_hash[TRACE_TEST_HASH_SLOTS];
    npu_bus_trace_t trace;
    npu_model_t model = {0};
    npu_vector_desc_t desc;
    uint64_t progress = 0u;
    uint8_t value = 0u;
    int32_t overlay_value = 0;
    uint32_t index;

    (void)memset(trace_test_l1, 0, sizeof(trace_test_l1));
    (void)memset(trace_test_ddr, 0, sizeof(trace_test_ddr));
    model.l1 = trace_test_l1;
    model.l1_size = sizeof(trace_test_l1);
    model.ddr = trace_test_ddr;
    model.ddr_size = sizeof(trace_test_ddr);
    for (index = 0u; index < 4u; index++) {
        trace_test_l1[0x100u + index] =
            (uint8_t)(index + 1u);
        trace_test_l1[0x200u + index] =
            (uint8_t)(10u * (index + 1u));
        trace_test_l1[0x300u + index] = 0xccu;
    }

    (void)memset(&desc, 0, sizeof(desc));
    desc.rows = 1u;
    desc.length = 4u;
    desc.valid_length = 4u;
    desc.src0 =
        trace_test_tensor(NPU_DTYPE_INT8, 0x100u, 4u);
    desc.src1 =
        trace_test_tensor(NPU_DTYPE_INT8, 0x200u, 4u);
    desc.dst =
        trace_test_tensor(NPU_DTYPE_INT8, 0x300u, 4u);
    desc.src0_scale_bits = 0x3f800000u;
    desc.src1_scale_bits = 0x3f800000u;
    desc.dst_scale_bits = 0x3f800000u;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;

    TEST_CHECK(npu_bus_trace_begin(
        &trace, read, TRACE_TEST_ENTRY_CAPACITY,
        read_hash, TRACE_TEST_HASH_SLOTS,
        write, TRACE_TEST_ENTRY_CAPACITY,
        write_hash, TRACE_TEST_HASH_SLOTS,
        2u, trace_test_select_port,
        (const void *)0));
    model.internal_bus_trace = &trace;
    TEST_CHECK_STATUS(
        npu_vector_execute(
            &model, NPU_VECTOR_ADD, &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(npu_bus_trace_set_read_capture(
                   &trace, 0u) == 1u);
    TEST_CHECK_STATUS(
        npu_tensor_read(
            &model, &desc.dst, 0u, 0u, 0u,
            &overlay_value),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(overlay_value == 11);
    TEST_CHECK(trace.read_count == 2u);
    TEST_CHECK(trace_test_l1[0x300u] == 0xccu);
    TEST_CHECK(npu_bus_trace_set_read_capture(
                   &trace, 1u) == 0u);
    model.internal_bus_trace = (void *)0;
    npu_bus_trace_end(&trace);

    TEST_CHECK(progress == 4u);
    TEST_CHECK(trace.read_count == 2u);
    TEST_CHECK(trace.write_count == 1u);
    TEST_CHECK(trace.write[0].addr == UINT64_C(0x300));
    TEST_CHECK(trace.write[0].strb == 0x0fu);
    TEST_CHECK(trace_test_l1[0x300u] == 0xccu);
    TEST_CHECK(trace_test_l1[0x303u] == 0xccu);
    TEST_CHECK(npu_bus_trace_lookup_write_byte(
        &trace, NPU_SPACE_L1, UINT64_C(0x300), &value));
    TEST_CHECK(value == 11u);
    TEST_CHECK(npu_bus_trace_lookup_write_byte(
        &trace, NPU_SPACE_L1, UINT64_C(0x303), &value));
    TEST_CHECK(value == 44u);
    return 0;
}

int test_bus_trace(void)
{
    int line;

    line = trace_test_direct_capture();
    if (line != 0) {
        return line;
    }
    return trace_test_vector_capture();
}

#ifdef NPU_BUS_TRACE_STANDALONE
int main(void)
{
    return test_bus_trace();
}
#endif
