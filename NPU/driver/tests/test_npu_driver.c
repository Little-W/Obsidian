#include "npu_driver.h"

#include <stdio.h>
#include <string.h>

#define CHECK(condition)                                                     \
    do {                                                                     \
        if (!(condition)) {                                                  \
            fprintf(stderr, "%s:%d: check failed: %s\n",                    \
                    __FILE__, __LINE__, #condition);                         \
            return 1;                                                        \
        }                                                                    \
    } while (0)

typedef struct {
    uint64_t registers[128];
    uint64_t beats[2];
    uint8_t first[2];
    uint8_t last[2];
    uint32_t beat_count;
    uint32_t query_count;
    uint32_t cache_clean_count;
    uint32_t cache_invalidate_count;
    uint32_t write_barrier_count;
    uint32_t read_barrier_count;
    uint32_t relax_count;
} fake_platform_t;

static int fake_read64(void *context,
                       uint32_t offset,
                       uint64_t *value)
{
    fake_platform_t *fake = (fake_platform_t *)context;
    if ((offset & 7u) != 0u || offset / 8u >= 128u) {
        return -1;
    }
    *value = fake->registers[offset / 8u];
    return 0;
}

static int fake_write64(void *context,
                        uint32_t offset,
                        uint64_t value,
                        uint8_t strobe)
{
    fake_platform_t *fake = (fake_platform_t *)context;
    if ((offset & 7u) != 0u ||
        offset / 8u >= 128u ||
        strobe != NPU_DRV_FULL_WSTRB) {
        return -1;
    }
    fake->registers[offset / 8u] = value;
    return 0;
}

static int fake_submit_beat(void *context,
                            uint64_t value,
                            uint8_t first,
                            uint8_t last)
{
    fake_platform_t *fake = (fake_platform_t *)context;
    if (fake->beat_count >= 2u) {
        return -1;
    }
    fake->beats[fake->beat_count] = value;
    fake->first[fake->beat_count] = first;
    fake->last[fake->beat_count] = last;
    fake->beat_count++;
    return 0;
}

static int fake_submit_response(void *context, uint64_t *value)
{
    fake_platform_t *fake = (fake_platform_t *)context;
    uint16_t command_id;
    if (fake->beat_count != 2u) {
        return -1;
    }
    command_id =
        (uint16_t)((fake->beats[0] >> 48u) & 0x0fffu);
    *value = command_id | (UINT64_C(7) << 20u);
    return 0;
}

static int fake_control(void *context,
                        uint8_t operation,
                        uint64_t rs1,
                        uint64_t rs2,
                        uint64_t *rd)
{
    fake_platform_t *fake = (fake_platform_t *)context;
    uint16_t command_id;
    uint8_t state;
    (void)rs2;

    if (operation == NPU_DRV_CTL_QUERY) {
        command_id = (uint16_t)rs1;
        if (rs2 == NPU_DRV_QUERY_STATUS) {
            state = fake->query_count == 0u
                        ? NPU_DRV_TASK_WAITING
                        : fake->query_count == 1u
                              ? NPU_DRV_TASK_RUNNING
                              : NPU_DRV_TASK_TERMINAL;
            fake->query_count++;
            *rd = (uint64_t)state |
                  ((uint64_t)command_id << 12u);
        } else {
            *rd = 0u;
        }
        return 0;
    }
    if (operation == NPU_DRV_CTL_WAIT) {
        *rd = UINT64_C(2) | (UINT64_C(0x321) << 8u);
        return 0;
    }
    if (operation == NPU_DRV_CTL_FENCE) {
        *rd = 0u;
        return 0;
    }
    return -1;
}

static void fake_write_barrier(void *context)
{
    ((fake_platform_t *)context)->write_barrier_count++;
}

static void fake_read_barrier(void *context)
{
    ((fake_platform_t *)context)->read_barrier_count++;
}

static void fake_cache_clean(void *context,
                             const void *address,
                             size_t bytes)
{
    fake_platform_t *fake = (fake_platform_t *)context;
    if (address != (const void *)0 && bytes != 0u) {
        fake->cache_clean_count++;
    }
}

static void fake_cache_invalidate(void *context,
                                  void *address,
                                  size_t bytes)
{
    fake_platform_t *fake = (fake_platform_t *)context;
    if (address != (void *)0 && bytes != 0u) {
        fake->cache_invalidate_count++;
    }
}

static void fake_relax(void *context)
{
    ((fake_platform_t *)context)->relax_count++;
}

static npu_drv_platform_ops_t fake_operations(fake_platform_t *fake)
{
    npu_drv_platform_ops_t operations;
    memset(&operations, 0, sizeof(operations));
    operations.context = fake;
    operations.mmio_read64 = fake_read64;
    operations.mmio_write64 = fake_write64;
    operations.submit_beat = fake_submit_beat;
    operations.submit_response = fake_submit_response;
    operations.control_request = fake_control;
    operations.write_barrier = fake_write_barrier;
    operations.read_barrier = fake_read_barrier;
    operations.cache_clean = fake_cache_clean;
    operations.cache_invalidate = fake_cache_invalidate;
    operations.relax = fake_relax;
    return operations;
}

static int test_command(void)
{
    npu_drv_cmd_fields_t fields;
    npu_drv_cmd_fields_t decoded;
    npu_drv_cmd128_t command;
    memset(&fields, 0, sizeof(fields));
    fields.descriptor_addr = UINT64_C(0x123400);
    fields.command_id = 0x345u;
    fields.engine = NPU_DRV_ENGINE_MATRIX;
    fields.opcode = 0x42u;
    fields.header_flags = 0x155u;
    fields.wait_event[0].id = 0x23u;
    fields.wait_event[0].generation = 1u;
    fields.wait_event[1].id = 0x56u;
    fields.wait_event[1].generation = 4u;
    fields.signal_event.id = 0x89u;
    fields.signal_event.generation = 7u;
    CHECK(npu_drv_cmd128_encode(&fields, &command) == NPU_DRV_OK);
    CHECK(command.lo == UINT64_C(0x2345000000123400));
    CHECK(command.hi ==
          ((UINT64_C(1) << 56u) |
           (UINT64_C(0x789) << 44u) |
           (UINT64_C(0x456) << 32u) |
           (UINT64_C(0x123) << 20u) |
           (UINT64_C(0x155) << 8u) |
           UINT64_C(0x42)));
    CHECK(npu_drv_cmd128_decode(&command, &decoded) == NPU_DRV_OK);
    CHECK(decoded.descriptor_addr == fields.descriptor_addr);
    CHECK(decoded.command_id == fields.command_id);
    CHECK(decoded.signal_event.id == fields.signal_event.id);
    command.hi |= UINT64_C(1) << 18u;
    CHECK(npu_drv_cmd128_decode(&command, &decoded) == NPU_DRV_EINVAL);
    return 0;
}

static uint32_t load_u32_le(const uint8_t *data)
{
    return (uint32_t)data[0] |
           ((uint32_t)data[1] << 8u) |
           ((uint32_t)data[2] << 16u) |
           ((uint32_t)data[3] << 24u);
}

static int test_descriptor(void)
{
    _Alignas(64) uint8_t storage[512];
    npu_drv_desc_pool_t pool;
    npu_drv_desc_allocation_t dma_allocation;
    npu_drv_desc_allocation_t vector_allocation;
    npu_drv_desc_common_t common;
    npu_drv_dma_fields_t dma;
    uint32_t numeric;

    CHECK(npu_drv_desc_pool_init(
              &pool, storage, UINT64_C(0x100000), sizeof(storage)) ==
          NPU_DRV_OK);
    CHECK(npu_drv_desc_alloc(
              &pool, NPU_DRV_DESC_DMA, &dma_allocation) ==
          NPU_DRV_OK);
    CHECK(dma_allocation.device_address == UINT64_C(0x100000));
    CHECK(dma_allocation.bytes == NPU_DRV_DMA_DESC_BYTES);
    CHECK(npu_drv_desc_alloc(
              &pool, NPU_DRV_DESC_VECTOR, &vector_allocation) ==
          NPU_DRV_OK);
    CHECK(vector_allocation.device_address == UINT64_C(0x100100));
    CHECK(vector_allocation.bytes == NPU_DRV_VECTOR_DESC_BYTES);
    CHECK(npu_drv_desc_alloc(
              &pool, NPU_DRV_DESC_CONTROL, &vector_allocation) ==
          NPU_DRV_OK);
    CHECK(vector_allocation.device_address == UINT64_C(0x1001c0));
    CHECK(npu_drv_desc_alloc(
              &pool, NPU_DRV_DESC_CONTROL, &vector_allocation) ==
          NPU_DRV_ENOMEM);

    memset(&common, 0, sizeof(common));
    common.desc_version = 1u;
    common.desc_type = NPU_DRV_DESC_DMA;
    common.op_flags = 0x09u;
    common.src0_addr = UINT64_C(0x200000);
    common.dst_addr = UINT64_C(0x1000);
    common.src0_dtype = NPU_DRV_DTYPE_INT16;
    common.src1_dtype = NPU_DRV_DTYPE_INT4;
    common.src2_dtype = NPU_DRV_DTYPE_INT4;
    common.dst_dtype = NPU_DRV_DTYPE_INT16;
    common.user_tag = 0xabcdef01u;
    memset(&dma, 0, sizeof(dma));
    dma.rank = 1u;
    dma.src_space = 1u;
    dma.dst_space = 0u;
    dma.burst_beats = 16u;
    dma.max_outstanding = 8u;
    dma.shape[0] = 64u;
    dma.src_region_bytes = 128u;
    dma.dst_region_bytes = 128u;
    CHECK(npu_drv_desc_dma_encode(
              dma_allocation.cpu_address,
              dma_allocation.bytes,
              &common,
              &dma) == NPU_DRV_OK);
    CHECK(storage[0] == 1u);
    CHECK(storage[1] == NPU_DRV_DESC_DMA);
    CHECK(storage[2] == 0u && storage[3] == 1u);
    numeric = load_u32_le(&storage[0x38]);
    CHECK((numeric & 0x3u) == NPU_DRV_DTYPE_INT16);
    CHECK(((numeric >> 6u) & 0x3u) == NPU_DRV_DTYPE_INT16);
    CHECK(npu_drv_desc_write_u64(
              storage, sizeof(storage), sizeof(storage) - 4u, 1u) ==
          NPU_DRV_ERANGE);
    return 0;
}

static int test_data_type_configurations(void)
{
    typedef struct {
        npu_drv_dtype_t dtype;
        uint8_t pack_format;
    } dtype_case_t;

    static const dtype_case_t cases[] = {
        {NPU_DRV_DTYPE_INT4, NPU_DRV_PACK_LINEAR_INT4},
        {NPU_DRV_DTYPE_INT4, NPU_DRV_PACK_TILED_INT4},
        {NPU_DRV_DTYPE_INT8, NPU_DRV_PACK_LINEAR_INT8},
        {NPU_DRV_DTYPE_INT8, NPU_DRV_PACK_TILED_INT8},
        {NPU_DRV_DTYPE_INT32, NPU_DRV_PACK_LINEAR_INT32},
        {NPU_DRV_DTYPE_INT16, NPU_DRV_PACK_LINEAR_INT16},
        {NPU_DRV_DTYPE_INT16, NPU_DRV_PACK_TILED_INT16}
    };
    _Alignas(64) uint8_t descriptor[NPU_DRV_MATRIX_DESC_BYTES];
    npu_drv_desc_common_t common;
    npu_drv_matrix_fields_t matrix;
    size_t index;
    uint32_t numeric;

    memset(&matrix, 0, sizeof(matrix));
    matrix.m = 1u;
    matrix.n = 1u;
    matrix.k = 1u;
    matrix.batch_count = 1u;
    for (index = 0u; index < sizeof(cases) / sizeof(cases[0]); index++) {
        memset(&common, 0, sizeof(common));
        common.desc_version = 1u;
        common.desc_type = NPU_DRV_DESC_MATRIX;
        common.src0_dtype = cases[index].dtype;
        common.src1_dtype = cases[index].dtype;
        common.src2_dtype = cases[index].dtype;
        common.dst_dtype = cases[index].dtype;
        matrix.a_pack_format = cases[index].pack_format;
        matrix.b_pack_format = cases[index].pack_format;
        matrix.c_pack_format = cases[index].pack_format;
        CHECK(npu_drv_desc_matrix_encode(
                  descriptor, sizeof(descriptor), &common, &matrix) ==
              NPU_DRV_OK);
        numeric = load_u32_le(&descriptor[0x38]);
        CHECK((numeric & 0x3u) == (uint32_t)cases[index].dtype);
        CHECK(((numeric >> 2u) & 0x3u) ==
              (uint32_t)cases[index].dtype);
        CHECK(((numeric >> 4u) & 0x3u) ==
              (uint32_t)cases[index].dtype);
        CHECK(((numeric >> 6u) & 0x3u) ==
              (uint32_t)cases[index].dtype);
        CHECK(descriptor[0x90] == cases[index].pack_format);
        CHECK(descriptor[0x91] == cases[index].pack_format);
        CHECK(descriptor[0x92] == cases[index].pack_format);
    }

    common.src0_dtype = (npu_drv_dtype_t)4;
    CHECK(npu_drv_desc_matrix_encode(
              descriptor, sizeof(descriptor), &common, &matrix) ==
          NPU_DRV_EINVAL);
    return 0;
}

static int test_little_endian_writes(void)
{
    uint8_t bytes[16];

    memset(bytes, 0, sizeof(bytes));
    CHECK(npu_drv_desc_write_u8(
              bytes, sizeof(bytes), 0u, UINT8_C(0xa5)) == NPU_DRV_OK);
    CHECK(npu_drv_desc_write_u16(
              bytes, sizeof(bytes), 1u, UINT16_C(0x1234)) == NPU_DRV_OK);
    CHECK(npu_drv_desc_write_u32(
              bytes, sizeof(bytes), 3u, UINT32_C(0x89abcdef)) ==
          NPU_DRV_OK);
    CHECK(npu_drv_desc_write_u64(
              bytes, sizeof(bytes), 8u, UINT64_C(0x0123456789abcdef)) ==
          NPU_DRV_OK);
    CHECK(bytes[0] == 0xa5u);
    CHECK(bytes[1] == 0x34u && bytes[2] == 0x12u);
    CHECK(bytes[3] == 0xefu && bytes[4] == 0xcdu &&
          bytes[5] == 0xabu && bytes[6] == 0x89u);
    CHECK(bytes[7] == 0u);
    CHECK(bytes[8] == 0xefu && bytes[9] == 0xcdu &&
          bytes[10] == 0xabu && bytes[11] == 0x89u &&
          bytes[12] == 0x67u && bytes[13] == 0x45u &&
          bytes[14] == 0x23u && bytes[15] == 0x01u);
    CHECK(npu_drv_desc_write_u32(
              bytes, sizeof(bytes), sizeof(bytes) - 3u, 0u) ==
          NPU_DRV_ERANGE);
    return 0;
}

static int test_driver(void)
{
    _Alignas(64) uint8_t descriptor[256];
    fake_platform_t fake;
    npu_drv_platform_ops_t operations;
    npu_driver_t driver;
    npu_drv_cmd_fields_t fields;
    npu_drv_cmd128_t command;
    npu_drv_submit_result_t submit;
    npu_drv_task_status_t task;
    npu_drv_event_result_t event_result;
    npu_drv_event_t event;
    uint64_t raw;

    memset(&fake, 0, sizeof(fake));
    operations = fake_operations(&fake);
    CHECK(npu_drv_init(&driver, &operations) == NPU_DRV_OK);
    CHECK(npu_drv_set_timeout(&driver, 3u, 1000u) == NPU_DRV_OK);
    CHECK(fake.registers[
              (NPU_DRV_REG_TIMEOUT_BASE + 3u * 8u) / 8u] == 1000u);
    CHECK(npu_drv_reg_read(
              &driver, NPU_DRV_REG_TIMEOUT_BASE + 3u * 8u, &raw) ==
          NPU_DRV_OK);
    CHECK(raw == 1000u);
    CHECK(npu_drv_set_base(
              &driver, NPU_DRV_REG_INPUT_BASE, UINT64_C(0x400000)) ==
          NPU_DRV_OK);
    CHECK(npu_drv_set_base(
              &driver, NPU_DRV_REG_INPUT_BASE, UINT64_C(0x400001)) ==
          NPU_DRV_EINVAL);
    CHECK(npu_drv_irq_enable(
              &driver, NPU_DRV_IRQ_DONE | NPU_DRV_IRQ_ERROR) ==
          NPU_DRV_OK);
    CHECK(npu_drv_start(&driver) == NPU_DRV_OK);
    CHECK(fake.registers[NPU_DRV_REG_CORE_CONTROL / 8u] ==
          NPU_DRV_CORE_START);

    memset(&fields, 0, sizeof(fields));
    fields.descriptor_addr = UINT64_C(0x100000);
    fields.command_id = 0x123u;
    fields.engine = NPU_DRV_ENGINE_DMA;
    fields.opcode = 0x20u;
    fields.wait_event[0].id = 255u;
    fields.wait_event[0].generation = 15u;
    fields.wait_event[1] = fields.wait_event[0];
    fields.signal_event = fields.wait_event[0];
    CHECK(npu_drv_cmd128_encode(&fields, &command) == NPU_DRV_OK);
    memset(descriptor, 0, sizeof(descriptor));
    CHECK(npu_drv_submit(
              &driver, &command, descriptor, sizeof(descriptor), &submit) ==
          NPU_DRV_OK);
    CHECK(fake.beat_count == 2u);
    CHECK(fake.beats[0] == command.lo && fake.first[0] == 1u &&
          fake.last[0] == 0u);
    CHECK(fake.beats[1] == command.hi && fake.first[1] == 0u &&
          fake.last[1] == 1u);
    CHECK(fake.cache_clean_count == 1u);
    CHECK(fake.write_barrier_count == 1u);
    CHECK(submit.command_id == fields.command_id);
    CHECK(submit.fifo_free == 7u);

    CHECK(npu_drv_wait_task(
              &driver, fields.command_id, 4u, &task) == NPU_DRV_OK);
    CHECK(task.state == NPU_DRV_TASK_TERMINAL);
    CHECK(fake.relax_count == 2u);
    CHECK(fake.read_barrier_count == 1u);
    CHECK(npu_drv_ack_task(&driver, fields.command_id) == NPU_DRV_OK);

    event.id = 4u;
    event.generation = 2u;
    CHECK(npu_drv_wait_event(
              &driver, event, 100u, &event_result) == NPU_DRV_OK);
    CHECK(event_result.state == 2u);
    CHECK(event_result.producer_command_id == 0x321u);
    CHECK(npu_drv_fence(&driver, 100u, &raw) == NPU_DRV_OK);
    CHECK(raw == 0u);
    CHECK(npu_drv_sync_for_cpu(
              &driver, descriptor, sizeof(descriptor)) == NPU_DRV_OK);
    CHECK(fake.cache_invalidate_count == 1u);
    CHECK(fake.read_barrier_count == 4u);
    CHECK(npu_drv_stop(&driver) == NPU_DRV_OK);
    CHECK(fake.registers[NPU_DRV_REG_CORE_CONTROL / 8u] ==
          NPU_DRV_CORE_STOP);
    CHECK(npu_drv_soft_reset(&driver) == NPU_DRV_OK);
    CHECK(fake.registers[NPU_DRV_REG_CORE_CONTROL / 8u] ==
          NPU_DRV_CORE_SOFT_RESET);
    CHECK(npu_drv_irq_ack(&driver, NPU_DRV_IRQ_ALL) == NPU_DRV_OK);
    CHECK(fake.registers[NPU_DRV_REG_IRQ_STATUS / 8u] ==
          NPU_DRV_IRQ_ALL);
    CHECK(npu_drv_fault_clear(&driver) == NPU_DRV_OK);
    CHECK(fake.registers[NPU_DRV_REG_FAULT_CLEAR / 8u] == 1u);
    return 0;
}

int main(void)
{
    CHECK(test_command() == 0);
    CHECK(test_descriptor() == 0);
    CHECK(test_data_type_configurations() == 0);
    CHECK(test_little_endian_writes() == 0);
    CHECK(test_driver() == 0);
    puts("npu_driver tests: PASS");
    return 0;
}
