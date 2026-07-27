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
    uint64_t beats[NPU_DRV_CMD_FIFO_MAX_BURST_BEATS];
    uint8_t response_status[NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    uint16_t response_command_id[NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    uint8_t response_override[NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    size_t beat_count;
    size_t response_index;
    size_t response_failure_index;
    uint32_t fifo_offset;
    uint32_t fixed_burst_count;
    int fixed_burst_result;
    uint32_t query_count;
    uint32_t cache_clean_count;
    uint32_t cache_invalidate_count;
    uint32_t write_barrier_count;
    uint32_t read_barrier_count;
    uint32_t relax_count;
    uint8_t last_control_operation;
    uint64_t last_control_rs1;
    uint64_t last_control_rs2;
} fake_platform_t;

static int fake_read64(void *context, uint32_t offset, uint64_t *value)
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

static int fake_submit_fixed_burst(void *context,
                                   uint32_t fifo_offset,
                                   const uint64_t *beats,
                                   size_t beat_count)
{
    fake_platform_t *fake = (fake_platform_t *)context;
    size_t index;

    if (beats == (const uint64_t *)0 ||
        fifo_offset != NPU_DRV_CMD_FIFO_DATA ||
        beat_count < NPU_DRV_CMD_FIFO_MIN_BURST_BEATS ||
        beat_count > NPU_DRV_CMD_FIFO_MAX_BURST_BEATS ||
        (beat_count & 1u) != 0u) {
        return -1;
    }
    fake->fifo_offset = fifo_offset;
    fake->beat_count = beat_count;
    fake->response_index = 0u;
    fake->fixed_burst_count++;
    for (index = 0u; index < beat_count; index++) {
        fake->beats[index] = beats[index];
    }
    return fake->fixed_burst_result;
}

static int fake_submit_response(void *context, uint64_t *value)
{
    fake_platform_t *fake = (fake_platform_t *)context;
    size_t command_count = fake->beat_count / NPU_DRV_CMD128_BEATS;
    size_t index = fake->response_index;
    uint16_t command_id;

    if (value == (uint64_t *)0 ||
        index >= command_count ||
        index == fake->response_failure_index) {
        return -1;
    }
    command_id = fake->response_override[index] != 0u
                     ? fake->response_command_id[index]
                     : (uint16_t)(
                           (fake->beats[
                                index * NPU_DRV_CMD128_BEATS + 1u] >>
                            48u) &
                           0x03ffu);
    *value = (uint64_t)command_id |
             ((uint64_t)fake->response_status[index] << 12u) |
             ((uint64_t)(NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS -
                         command_count)
              << 20u);
    fake->response_index++;
    return 0;
}

static int fake_control(void *context,
                        uint8_t operation,
                        uint64_t rs1,
                        uint64_t rs2,
                        uint64_t *rd)
{
    fake_platform_t *fake = (fake_platform_t *)context;

    fake->last_control_operation = operation;
    fake->last_control_rs1 = rs1;
    fake->last_control_rs2 = rs2;
    if (operation == NPU_DRV_CTL_QUERY) {
        uint8_t state = fake->query_count == 0u
                            ? NPU_DRV_TASK_WAITING
                            : fake->query_count == 1u
                                  ? NPU_DRV_TASK_RUNNING
                                  : NPU_DRV_TASK_TERMINAL;
        fake->query_count++;
        *rd = (uint64_t)state | (rs1 << 12u);
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
    if (address != (const void *)0 && bytes != 0u) {
        ((fake_platform_t *)context)->cache_clean_count++;
    }
}

static void fake_cache_invalidate(void *context,
                                  void *address,
                                  size_t bytes)
{
    if (address != (void *)0 && bytes != 0u) {
        ((fake_platform_t *)context)->cache_invalidate_count++;
    }
}

static void fake_relax(void *context)
{
    ((fake_platform_t *)context)->relax_count++;
}

static void fake_platform_reset(fake_platform_t *fake)
{
    memset(fake, 0, sizeof(*fake));
    fake->response_failure_index = SIZE_MAX;
}

static npu_drv_platform_ops_t fake_operations(fake_platform_t *fake)
{
    npu_drv_platform_ops_t operations;
    memset(&operations, 0, sizeof(operations));
    operations.context = fake;
    operations.mmio_read64 = fake_read64;
    operations.mmio_write64 = fake_write64;
    operations.submit_fixed_burst = fake_submit_fixed_burst;
    operations.submit_response = fake_submit_response;
    operations.control_request = fake_control;
    operations.write_barrier = fake_write_barrier;
    operations.read_barrier = fake_read_barrier;
    operations.cache_clean = fake_cache_clean;
    operations.cache_invalidate = fake_cache_invalidate;
    operations.relax = fake_relax;
    return operations;
}

static npu_drv_cmd128_t make_command(uint16_t command_id, uint64_t payload)
{
    npu_drv_cmd_fields_t fields;
    npu_drv_cmd128_t command = {0u, 0u};

    memset(&fields, 0, sizeof(fields));
    fields.payload.lo = payload;
    fields.command_id = command_id;
    fields.opcode = NPU_DRV_OPCODE_DMA_COPY_1D;
    fields.dtype = NPU_DRV_DTYPE_INT8;
    fields.wait_event[0].id = NPU_DRV_EVENT_NONE;
    fields.wait_event[1].id = NPU_DRV_EVENT_NONE;
    fields.signal_event.id = NPU_DRV_EVENT_NONE;
    (void)npu_drv_cmd128_encode(&fields, &command);
    return command;
}

static int test_references_and_payload(void)
{
    npu_drv_payload80_t payload = {0u, 0u};
    uint32_t aref;
    uint16_t lref;

    CHECK(npu_drv_aref_encode(0u, 0u, 0x123456u, &aref) == NPU_DRV_OK);
    CHECK(aref == UINT32_C(0x00123456));
    CHECK(npu_drv_aref_encode(1u, 4u, 0x345678u, &aref) == NPU_DRV_OK);
    CHECK(aref == UINT32_C(0x0c345678));
    CHECK(npu_drv_aref_encode(0u, 1u, 0u, &aref) == NPU_DRV_EINVAL);
    CHECK(npu_drv_aref_encode(1u, 6u, 0u, &aref) == NPU_DRV_EINVAL);
    CHECK(npu_drv_lref_encode(0x3000u, 6u, 14u, &lref) == NPU_DRV_OK);
    CHECK(lref == 0xc0u);
    CHECK(npu_drv_lref_encode(0x3001u, 6u, 14u, &lref) == NPU_DRV_ERANGE);

    CHECK(npu_drv_dma_gather_nd_payload_encode(
              UINT32_C(0x0a000100),
              0x100u,
              0x200u,
              3u,
              64u,
              &payload) == NPU_DRV_OK);
    CHECK(payload.lo == UINT64_C(0x100010002000203f));
    CHECK(payload.hi == UINT16_C(0xa000));
    CHECK(npu_drv_dma_gather_nd_payload_encode(
              UINT32_C(0x00000100),
              0x100u,
              0x200u,
              3u,
              64u,
              &payload) == NPU_DRV_EINVAL);
    CHECK(npu_drv_dma_gather_nd_payload_encode(
              UINT32_C(0x0a000100),
              0x100u,
              0x200u,
              0u,
              64u,
              &payload) == NPU_DRV_EINVAL);

    memset(&payload, 0, sizeof(payload));
    CHECK(npu_drv_payload_field_set(&payload, 66u, 14u, 0x1234u) ==
          NPU_DRV_OK);
    CHECK(payload.hi == (uint16_t)(0x1234u << 2u));
    CHECK(npu_drv_payload_field_set(&payload, 18u, 6u, 7u) ==
          NPU_DRV_OK);
    CHECK(((payload.lo >> 18u) & 0x3fu) == 7u);
    CHECK(npu_drv_payload_field_set(&payload, 18u, 6u, 1u) ==
          NPU_DRV_EINVAL);
    CHECK(npu_drv_payload_field_set(&payload, 79u, 2u, 0u) ==
          NPU_DRV_EINVAL);

    CHECK(npu_drv_matrix_gemm_payload_encode(
              0x40u,
              NPU_DRV_DTYPE_INT8,
              0x80u,
              NPU_DRV_DTYPE_INT4,
              0xc0u,
              NPU_DRV_DTYPE_INT8,
              0x100u,
              2u,
              3u,
              4u,
              31u,
              &payload) == NPU_DRV_OK);
    CHECK(((payload.lo >> 26u) & 0xfffu) == 0x100u);
    CHECK(((payload.lo >> 20u) & 0x3fu) == 1u);
    CHECK(((payload.lo >> 14u) & 0x3fu) == 2u);
    CHECK(((payload.lo >> 8u) & 0x3fu) == 3u);
    CHECK(((payload.lo >> 7u) & 0x1u) == 1u);
    CHECK(((payload.lo >> 5u) & 0x3u) == NPU_DRV_DTYPE_INT8);
    CHECK((payload.lo & 0x1fu) == 31u);
    CHECK(payload.hi == (uint16_t)(0x40u << 2u));

    CHECK(npu_drv_matrix_bmm_payload_encode(
              0x40u,
              NPU_DRV_DTYPE_INT8,
              0x80u,
              NPU_DRV_DTYPE_INT4,
              0xc0u,
              NPU_DRV_DTYPE_INT8,
              5u,
              6u,
              7u,
              8u,
              5u,
              &payload) == NPU_DRV_OK);
    CHECK(((payload.lo >> 32u) & 0x3fu) == 4u);
    CHECK(((payload.lo >> 26u) & 0x3fu) == 5u);
    CHECK(((payload.lo >> 20u) & 0x3fu) == 6u);
    CHECK(((payload.lo >> 14u) & 0x3fu) == 7u);
    CHECK(((payload.lo >> 13u) & 0x1u) == 1u);
    CHECK(((payload.lo >> 11u) & 0x3u) == NPU_DRV_DTYPE_INT8);
    CHECK(((payload.lo >> 6u) & 0x1fu) == 5u);
    CHECK((payload.lo & 0x3fu) == 0u);
    CHECK(npu_drv_matrix_gemm_payload_encode(
              0x40u,
              NPU_DRV_DTYPE_INT8,
              0x80u,
              NPU_DRV_DTYPE_INT8,
              0xc0u,
              NPU_DRV_DTYPE_INT32,
              0u,
              8u,
              8u,
              8u,
              5u,
              &payload) == NPU_DRV_EINVAL);
    return 0;
}

static int test_command(void)
{
    npu_drv_cmd_fields_t fields;
    npu_drv_cmd_fields_t decoded;
    npu_drv_cmd128_t command;
    uint64_t expected_high;

    memset(&fields, 0, sizeof(fields));
    fields.payload.lo = UINT64_C(0x0123456789abcdef);
    fields.payload.hi = UINT16_C(0xabcd);
    fields.command_id = 0x345u;
    fields.opcode = NPU_DRV_OPCODE_COMPLEX_NORM;
    fields.dtype = NPU_DRV_DTYPE_INT16;
    fields.timeout_class = 2u;
    fields.header_flags =
        NPU_DRV_HEADER_IRQ_SUCCESS |
        NPU_DRV_HEADER_STRICT_NUMERIC |
        NPU_DRV_HEADER_ORDERED;
    fields.wait_event[0].id = 0x23u;
    fields.wait_event[1].id = 0x56u;
    fields.signal_event.id = 0x89u;
    CHECK(npu_drv_cmd128_encode(&fields, &command) == NPU_DRV_OK);
    expected_high =
        UINT64_C(0xabcd) |
        (UINT64_C(3) << 16u) |
        (UINT64_C(2) << 18u) |
        (UINT64_C(0xb) << 20u) |
        (UINT64_C(0x89) << 24u) |
        (UINT64_C(0x56) << 32u) |
        (UINT64_C(0x23) << 40u) |
        (UINT64_C(0x345) << 48u) |
        (UINT64_C(28) << 58u);
    CHECK(command.lo == fields.payload.lo);
    CHECK(command.hi == expected_high);
    CHECK(npu_drv_cmd128_decode(&command, &decoded) == NPU_DRV_OK);
    CHECK(decoded.payload.lo == fields.payload.lo);
    CHECK(decoded.payload.hi == fields.payload.hi);
    CHECK(decoded.command_id == fields.command_id);
    CHECK(decoded.opcode == fields.opcode);
    CHECK(decoded.dtype == fields.dtype);
    CHECK(decoded.wait_event[0].id == 0x23u);
    CHECK(decoded.signal_event.id == 0x89u);
    fields.opcode = NPU_DRV_OPCODE_COMPLEX_ADD_RESCALE;
    fields.signal_event.id = 0x88u;
    CHECK(npu_drv_cmd128_encode(&fields, &command) == NPU_DRV_OK);
    CHECK(((command.hi >> 58u) & 0x3fu) == 32u);
    CHECK(npu_drv_cmd128_decode(&command, &decoded) == NPU_DRV_OK);
    CHECK(decoded.opcode == NPU_DRV_OPCODE_COMPLEX_ADD_RESCALE);

    fields.opcode = NPU_DRV_OPCODE_DMA_GATHER_ND;
    CHECK(npu_drv_cmd128_encode(&fields, &command) == NPU_DRV_OK);
    CHECK(((command.hi >> 58u) & 0x3fu) == 11u);
    CHECK(npu_drv_cmd128_decode(&command, &decoded) == NPU_DRV_OK);
    CHECK(decoded.opcode == NPU_DRV_OPCODE_DMA_GATHER_ND);

    fields.opcode = (npu_drv_opcode_t)33;
    CHECK(npu_drv_cmd128_encode(&fields, &command) == NPU_DRV_EINVAL);
    fields.signal_event = fields.wait_event[0];
    CHECK(npu_drv_cmd128_encode(&fields, &command) == NPU_DRV_EINVAL);
    return 0;
}

static int test_fixed_burst_batch(void)
{
    fake_platform_t fake;
    npu_drv_platform_ops_t operations;
    npu_driver_t driver;
    npu_drv_cmd128_t commands[3];
    npu_drv_submit_result_t results[3];
    npu_drv_submit_batch_result_t summary;
    size_t index;

    fake_platform_reset(&fake);
    operations = fake_operations(&fake);
    CHECK(npu_drv_init(&driver, &operations) == NPU_DRV_OK);
    for (index = 0u; index < 3u; index++) {
        commands[index] = make_command(
            (uint16_t)(0x20u + index), UINT64_C(0x100) + index);
    }
    CHECK(npu_drv_submit_batch(
              &driver, commands, 3u, results, &summary) == NPU_DRV_OK);
    CHECK(fake.fixed_burst_count == 1u);
    CHECK(fake.beat_count == 6u);
    CHECK(fake.beats[0] == commands[0].lo);
    CHECK(fake.beats[1] == commands[0].hi);
    CHECK(summary.responses_received == 3u);
    CHECK(summary.first_failed_index == NPU_DRV_NO_FAILED_COMMAND);
    CHECK(fake.cache_clean_count == 0u);
    CHECK(fake.write_barrier_count == 1u);

    fake.response_status[1] = 3u;
    CHECK(npu_drv_submit_batch(
              &driver, commands, 3u, results, &summary) ==
          NPU_DRV_EDEVICE);
    CHECK(summary.first_failed_index == 1u);
    fake.response_status[1] = 0u;
    fake.response_override[2] = 1u;
    fake.response_command_id[2] = 0x55u;
    CHECK(npu_drv_submit_batch(
              &driver, commands, 3u, results, &summary) == NPU_DRV_EIO);
    CHECK(summary.first_failed_index == 2u);
    CHECK(npu_drv_submit_batch(
              &driver,
              commands,
              NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS + 1u,
              results,
              &summary) == NPU_DRV_ERANGE);
    return 0;
}

static int test_driver(void)
{
    uint8_t data[64] = {0u};
    fake_platform_t fake;
    npu_drv_platform_ops_t operations;
    npu_driver_t driver;
    npu_drv_cmd128_t command;
    npu_drv_submit_result_t submit;
    npu_drv_task_status_t task;
    npu_drv_event_result_t event_result;
    npu_drv_event_t event;
    uint64_t raw;

    fake_platform_reset(&fake);
    operations = fake_operations(&fake);
    CHECK(npu_drv_init(&driver, &operations) == NPU_DRV_OK);
    CHECK(npu_drv_set_timeout(&driver, 3u, 1000u) == NPU_DRV_OK);
    CHECK(fake.registers[
              (NPU_DRV_REG_TIMEOUT_BASE + 3u * 8u) / 8u] == 1000u);
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

    command = make_command(0x123u, UINT64_C(0x55aa));
    CHECK(npu_drv_submit(&driver, &command, &submit) == NPU_DRV_OK);
    CHECK(fake.fixed_burst_count == 1u);
    CHECK(fake.beat_count == 2u);
    CHECK(submit.command_id == 0x123u);
    CHECK(submit.fifo_free == 7u);
    CHECK(npu_drv_wait_task(
              &driver, 0x123u, 4u, &task) == NPU_DRV_OK);
    CHECK(task.state == NPU_DRV_TASK_TERMINAL);
    CHECK(fake.relax_count == 2u);
    CHECK(npu_drv_ack_task(&driver, 0x123u) == NPU_DRV_OK);

    event.id = 4u;
    CHECK(npu_drv_wait_event(
              &driver, event, 100u, &event_result) == NPU_DRV_OK);
    CHECK(event_result.state == 2u);
    CHECK(event_result.producer_command_id == 0x321u);
    CHECK(fake.last_control_rs1 == 4u);
    CHECK(npu_drv_fence(&driver, 100u, &raw) == NPU_DRV_OK);
    CHECK(fake.last_control_operation == NPU_DRV_CTL_FENCE);
    CHECK(fake.last_control_rs1 == NPU_DRV_FENCE_ALL_ENGINES);

    CHECK(npu_drv_sync_for_device(&driver, data, sizeof(data)) ==
          NPU_DRV_OK);
    CHECK(npu_drv_sync_for_cpu(&driver, data, sizeof(data)) ==
          NPU_DRV_OK);
    CHECK(fake.cache_clean_count == 1u);
    CHECK(fake.cache_invalidate_count == 1u);
    CHECK(npu_drv_stop(&driver) == NPU_DRV_OK);
    CHECK(npu_drv_soft_reset(&driver) == NPU_DRV_OK);
    CHECK(npu_drv_irq_ack(&driver, NPU_DRV_IRQ_ALL) == NPU_DRV_OK);
    CHECK(npu_drv_fault_clear(&driver) == NPU_DRV_OK);
    return 0;
}

int main(void)
{
    CHECK(test_references_and_payload() == 0);
    CHECK(test_command() == 0);
    CHECK(test_fixed_burst_batch() == 0);
    CHECK(test_driver() == 0);
    puts("npu_driver CMD128 tests: PASS");
    return 0;
}
