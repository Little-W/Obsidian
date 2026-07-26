#include "cmodel_driver_backend.h"
#include "keras_transformer_model.h"
#include "keras_transformer_test_data.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MODEL_DDR_BYTES (2u * 1024u * 1024u)
#define MODEL_L1_BYTES NPU_REF_L1_BYTES
#define MODEL_ELEMENT_COUNT (KT_TEST_TOKENS * KT_TEST_WIDTH)
#define MODEL_SCALE (1.0 / (double)(UINT32_C(1) << KT_TEST_FRACTION_BITS))

#define CHECK(call)                                                        \
    do {                                                                   \
        int check_result = (call);                                         \
        if (check_result != 0) {                                           \
            fprintf(stderr, "failure:%s:%d rc=%d expression=%s\n",        \
                    __FILE__, __LINE__, check_result, #call);               \
            return 1;                                                      \
        }                                                                  \
    } while (0)

static uint8_t model_l1[MODEL_L1_BYTES];
static uint8_t model_ddr[MODEL_DDR_BYTES];
static transformer_cmodel_backend_t model_backend;

static void put_i16(uint8_t *memory, size_t address, int16_t value)
{
    uint16_t bits = (uint16_t)value;

    memory[address] = (uint8_t)bits;
    memory[address + 1u] = (uint8_t)(bits >> 8u);
}

static int16_t get_i16(const uint8_t *memory, size_t address)
{
    uint16_t bits = (uint16_t)memory[address] |
                    (uint16_t)((uint16_t)memory[address + 1u] << 8u);

    if ((bits & 0x8000u) != 0u) {
        return (int16_t)(-1 - (int32_t)(UINT16_MAX - bits));
    }
    return (int16_t)bits;
}

static int address_span_valid(uint64_t address, size_t bytes)
{
    return address <= MODEL_DDR_BYTES &&
           bytes <= MODEL_DDR_BYTES - (size_t)address;
}

static size_t descriptor_bytes_for_engine(uint8_t engine)
{
    if (engine == NPU_DRV_ENGINE_CONTROL) {
        return NPU_DRV_CONTROL_DESC_BYTES;
    }
    if (engine == NPU_DRV_ENGINE_DMA) {
        return NPU_DRV_DMA_DESC_BYTES;
    }
    if (engine == NPU_DRV_ENGINE_MATRIX) {
        return NPU_DRV_MATRIX_DESC_BYTES;
    }
    if (engine == NPU_DRV_ENGINE_VECTOR) {
        return NPU_DRV_VECTOR_DESC_BYTES;
    }
    if (engine == NPU_DRV_ENGINE_COMPLEX) {
        return NPU_DRV_COMPLEX_DESC_BYTES;
    }
    return 0u;
}

static const keras_transformer_model_operation_t *
operation_for_command(uint16_t command_id)
{
    uint32_t index;

    for (index = 0u;
         index < KERAS_TRANSFORMER_MODEL_OPERATION_COUNT;
         index++) {
        if (keras_transformer_model_operations[index].command_id ==
            command_id) {
            return &keras_transformer_model_operations[index];
        }
    }
    return (const keras_transformer_model_operation_t *)0;
}

static int command_for_id(uint16_t command_id,
                          npu_drv_cmd128_t *command,
                          npu_drv_cmd_fields_t *fields)
{
    uint32_t index;

    if (command == (npu_drv_cmd128_t *)0 ||
        fields == (npu_drv_cmd_fields_t *)0) {
        return -1;
    }
    for (index = 0u;
         index < KERAS_TRANSFORMER_MODEL_COMMAND_COUNT;
         index++) {
        command->lo = keras_transformer_model_commands[index].low;
        command->hi = keras_transformer_model_commands[index].high;
        if (npu_drv_cmd128_decode(command, fields) != NPU_DRV_OK) {
            return -1;
        }
        if (fields->command_id == command_id) {
            return 0;
        }
    }
    return -1;
}

static void event_text(npu_drv_event_t event,
                       char *text,
                       size_t text_bytes)
{
    uint16_t packed;

    if (npu_drv_event_pack(event, &packed) != NPU_DRV_OK) {
        (void)snprintf(text, text_bytes, "invalid");
    } else if (packed == NPU_DRV_EVENT_NONE) {
        (void)snprintf(text, text_bytes, "none");
    } else {
        (void)snprintf(text, text_bytes, "%u:g%u",
                       (unsigned)event.id,
                       (unsigned)event.generation);
    }
}

static int initialize_device_images(void)
{
    const keras_transformer_model_binding_t *input;
    uint32_t index;

    if (KERAS_TRANSFORMER_MODEL_INPUT_COUNT != 1u ||
        KERAS_TRANSFORMER_MODEL_OUTPUT_COUNT != 1u ||
        keras_transformer_model_config.command_count !=
            KERAS_TRANSFORMER_MODEL_COMMAND_COUNT) {
        return -1;
    }
    if (!address_span_valid(
            KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BASE,
            (size_t)KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BYTES) ||
        !address_span_valid(
            KERAS_TRANSFORMER_MODEL_WEIGHT_BASE_DDR,
            (size_t)KERAS_TRANSFORMER_MODEL_WEIGHT_BYTES)) {
        return -1;
    }
    input = &keras_transformer_model_inputs[0];
    if (input->dtype != NPU_DRV_DTYPE_INT16 ||
        input->rank != 3u ||
        input->shape[0] != 1u ||
        input->shape[1] != KT_TEST_TOKENS ||
        input->shape[2] != KT_TEST_WIDTH ||
        input->bytes != MODEL_ELEMENT_COUNT * sizeof(int16_t) ||
        !address_span_valid(input->ddr_addr, input->bytes)) {
        return -1;
    }

    (void)memset(model_l1, 0, sizeof(model_l1));
    (void)memset(model_ddr, 0, sizeof(model_ddr));
    (void)memcpy(
        &model_ddr[KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BASE],
        keras_transformer_model_descriptors,
        (size_t)KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BYTES);
    (void)memcpy(
        &model_ddr[KERAS_TRANSFORMER_MODEL_WEIGHT_BASE_DDR],
        keras_transformer_model_weights,
        (size_t)KERAS_TRANSFORMER_MODEL_WEIGHT_BYTES);
    for (index = 0u; index < MODEL_ELEMENT_COUNT; index++) {
        put_i16(model_ddr,
                (size_t)input->ddr_addr +
                    (size_t)index * sizeof(int16_t),
                kt_test_input[index]);
    }
    return 0;
}

static int sync_device_images(npu_driver_t *driver)
{
    const keras_transformer_model_binding_t *input =
        &keras_transformer_model_inputs[0];

    if (npu_drv_sync_for_device(
            driver,
            &model_ddr[KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BASE],
            (size_t)KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BYTES) != NPU_DRV_OK ||
        npu_drv_sync_for_device(
            driver,
            &model_ddr[KERAS_TRANSFORMER_MODEL_WEIGHT_BASE_DDR],
            (size_t)KERAS_TRANSFORMER_MODEL_WEIGHT_BYTES) != NPU_DRV_OK ||
        npu_drv_sync_for_device(
            driver,
            &model_ddr[input->ddr_addr],
            input->bytes) != NPU_DRV_OK) {
        return -1;
    }
    return 0;
}

static int submit_command_batch(npu_driver_t *driver,
                                uint32_t batch,
                                uint32_t begin,
                                uint32_t end)
{
    const keras_transformer_model_operation_t
        *operations[NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    npu_drv_cmd128_t
        commands[NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    npu_drv_cmd_fields_t
        fields[NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    npu_drv_submit_result_t
        results[NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    npu_drv_submit_batch_result_t summary;
    size_t command_count;
    size_t local_index;
    int rc;

    if (end < begin ||
        end > KERAS_TRANSFORMER_MODEL_BATCH_COMMAND_ID_COUNT) {
        return -1;
    }
    command_count = (size_t)(end - begin);
    if (command_count == 0u ||
        command_count > NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS) {
        return -1;
    }
    for (local_index = 0u;
         local_index < command_count;
         local_index++) {
        uint16_t command_id =
            keras_transformer_model_batch_command_ids[
                begin + (uint32_t)local_index];
        uint64_t descriptor_offset;
        size_t descriptor_bytes;

        operations[local_index] =
            operation_for_command(command_id);
        if (operations[local_index] ==
                (const keras_transformer_model_operation_t *)0 ||
            command_for_id(
                command_id,
                &commands[local_index],
                &fields[local_index]) != 0 ||
            fields[local_index].descriptor_addr <
                KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BASE) {
            return -1;
        }
        descriptor_offset =
            fields[local_index].descriptor_addr -
            KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BASE;
        descriptor_bytes = descriptor_bytes_for_engine(
            fields[local_index].engine);
        if (descriptor_bytes == 0u ||
            descriptor_offset >
                (uint64_t)KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BYTES ||
            descriptor_bytes >
                (size_t)KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BYTES -
                    (size_t)descriptor_offset ||
            !address_span_valid(
                fields[local_index].descriptor_addr,
                descriptor_bytes)) {
            return -1;
        }
    }

    rc = npu_drv_submit_batch(
        driver,
        commands,
        command_count,
        (const void *)0,
        0u,
        results,
        &summary);
    printf("submit burst batch=%u commands=%u beats=%u "
           "burst_completed=%u responses=%u "
           "first_failed_index=%lld rc=%d\n",
           (unsigned)batch,
           (unsigned)command_count,
           (unsigned)(command_count * NPU_DRV_CMD128_BEATS),
           (unsigned)summary.burst_completed,
           (unsigned)summary.responses_received,
           summary.first_failed_index == NPU_DRV_NO_FAILED_COMMAND
               ? -1LL
               : (long long)summary.first_failed_index,
           rc);
    for (local_index = 0u;
         local_index < command_count;
         local_index++) {
        char wait0[24];
        char wait1[24];
        char signal[24];

        event_text(
            fields[local_index].wait_event[0],
            wait0,
            sizeof(wait0));
        event_text(
            fields[local_index].wait_event[1],
            wait1,
            sizeof(wait1));
        event_text(
            fields[local_index].signal_event,
            signal,
            sizeof(signal));
        printf("submit batch=%u index=%u op=%s node=%s "
               "command_id=%u wait=[%s,%s] signal=%s "
               "accepted_id=%u accepted_status=%u fifo_free=%u\n",
               (unsigned)batch,
               (unsigned)local_index,
               operations[local_index]->name,
               operations[local_index]->high_level_node,
               (unsigned)fields[local_index].command_id,
               wait0,
               wait1,
               signal,
               (unsigned)results[local_index].command_id,
               (unsigned)results[local_index].status,
               (unsigned)results[local_index].fifo_free);
    }
    if (rc != NPU_DRV_OK ||
        summary.burst_completed == 0u ||
        summary.responses_received != command_count ||
        summary.first_failed_index !=
            NPU_DRV_NO_FAILED_COMMAND) {
        return -1;
    }
    return 0;
}

static int wait_query_batch(npu_driver_t *driver, uint32_t batch)
{
    uint32_t begin =
        keras_transformer_model_command_batches[batch].command_id_offset;
    uint32_t end =
        begin +
        keras_transformer_model_command_batches[batch].command_count;
    uint32_t index;

    for (index = begin; index < end; index++) {
        uint16_t command_id =
            keras_transformer_model_batch_command_ids[index];
        const keras_transformer_model_operation_t *operation =
            operation_for_command(command_id);
        npu_drv_task_status_t waited;
        npu_drv_task_status_t queried;
        uint64_t progress = 0u;
        int rc;

        if (operation == (const keras_transformer_model_operation_t *)0) {
            return -1;
        }
        (void)memset(&waited, 0, sizeof(waited));
        (void)memset(&queried, 0, sizeof(queried));
        rc = npu_drv_wait_task(
            driver, command_id, 1000000u, &waited);
        if (rc == NPU_DRV_OK) {
            rc = npu_drv_query_status(driver, command_id, &queried);
        }
        if (rc == NPU_DRV_OK) {
            rc = npu_drv_query_raw(
                driver,
                command_id,
                NPU_DRV_QUERY_PROGRESS,
                &progress);
        }
        printf("complete batch=%u op=%s command_id=%u "
               "state=%u status=%u progress=%llu rc=%d\n",
               (unsigned)batch,
               operation->name,
               (unsigned)command_id,
               (unsigned)queried.state,
               (unsigned)queried.status,
               (unsigned long long)progress,
               rc);
        if (rc != NPU_DRV_OK ||
            waited.state != NPU_DRV_TASK_TERMINAL ||
            waited.status != NPU_STATUS_SUCCESS ||
            queried.state != NPU_DRV_TASK_TERMINAL ||
            queried.status != NPU_STATUS_SUCCESS) {
            return -1;
        }
    }
    for (index = begin; index < end; index++) {
        uint16_t command_id =
            keras_transformer_model_batch_command_ids[index];
        if (npu_drv_ack_task(driver, command_id) != NPU_DRV_OK) {
            return -1;
        }
        printf("ack batch=%u command_id=%u\n",
               (unsigned)batch,
               (unsigned)command_id);
    }
    return 0;
}

static int run_batches(npu_driver_t *driver)
{
    uint32_t batch;

    if (keras_transformer_model_command_batches[0].command_id_offset != 0u ||
        KERAS_TRANSFORMER_MODEL_BATCH_COMMAND_ID_COUNT !=
            KERAS_TRANSFORMER_MODEL_COMMAND_COUNT) {
        return -1;
    }
    for (batch = 0u;
         batch < KERAS_TRANSFORMER_MODEL_COMMAND_BATCH_COUNT;
         batch++) {
        uint32_t begin =
            keras_transformer_model_command_batches[batch].
                command_id_offset;
        uint32_t end =
            begin +
            keras_transformer_model_command_batches[batch].command_count;

        printf("batch begin=%u index=%u commands=%u\n",
               (unsigned)batch,
               (unsigned)begin,
               (unsigned)(end - begin));
        if (submit_command_batch(
                driver, batch, begin, end) != 0) {
            return -1;
        }
        if (wait_query_batch(driver, batch) != 0) {
            return -1;
        }
    }
    return 0;
}

static uint32_t maximum_feature(const int16_t *values)
{
    uint32_t feature;
    uint32_t best = 0u;

    for (feature = 1u; feature < KT_TEST_WIDTH; feature++) {
        if (values[feature] > values[best]) {
            best = feature;
        }
    }
    return best;
}

static void print_fixed_vector(const char *label, const int16_t *values)
{
    uint32_t feature;

    printf("%s=[", label);
    for (feature = 0u; feature < KT_TEST_WIDTH; feature++) {
        printf("%s%d",
               feature == 0u ? "" : ",",
               (int)values[feature]);
    }
    printf("]\n");
}

static void print_float_vector(const char *label, const int16_t *values)
{
    uint32_t feature;

    printf("%s=[", label);
    for (feature = 0u; feature < KT_TEST_WIDTH; feature++) {
        printf("%s%.6f",
               feature == 0u ? "" : ",",
               (double)values[feature] * MODEL_SCALE);
    }
    printf("]\n");
}

static int check_output(npu_driver_t *driver)
{
    const keras_transformer_model_binding_t *output_binding =
        &keras_transformer_model_outputs[0];
    int16_t actual[KT_TEST_TOKENS][KT_TEST_WIDTH] = {{0}};
    uint32_t exact = 0u;
    uint32_t within_tolerance = 0u;
    uint32_t top_feature_correct = 0u;
    uint32_t max_abs_error = 0u;
    uint64_t absolute_error_sum = 0u;
    double squared_error_sum = 0.0;
    uint32_t token;
    uint32_t feature;

    if (output_binding->dtype != NPU_DRV_DTYPE_INT16 ||
        output_binding->rank != 3u ||
        output_binding->shape[0] != 1u ||
        output_binding->shape[1] != KT_TEST_TOKENS ||
        output_binding->shape[2] != KT_TEST_WIDTH ||
        output_binding->bytes !=
            MODEL_ELEMENT_COUNT * sizeof(int16_t) ||
        !address_span_valid(
            output_binding->ddr_addr, output_binding->bytes)) {
        return -1;
    }
    if (npu_drv_sync_for_cpu(
            driver,
            &model_ddr[output_binding->ddr_addr],
            output_binding->bytes) != NPU_DRV_OK) {
        return -1;
    }

    printf("tensor input_shape=[1,%u,%u] output_shape=[1,%u,%u] "
           "fraction_bits=%u scale=%.9f tolerance_lsb=%u\n",
           (unsigned)KT_TEST_TOKENS,
           (unsigned)KT_TEST_WIDTH,
           (unsigned)KT_TEST_TOKENS,
           (unsigned)KT_TEST_WIDTH,
           (unsigned)KT_TEST_FRACTION_BITS,
           MODEL_SCALE,
           (unsigned)KT_TEST_ALLOWED_ABS_ERROR);
    for (token = 0u; token < KT_TEST_TOKENS; token++) {
        int16_t signed_error[KT_TEST_WIDTH] = {0};
        int16_t absolute_error[KT_TEST_WIDTH] = {0};
        const int16_t *input =
            &kt_test_input[token * KT_TEST_WIDTH];
        const int16_t *expected =
            &kt_test_expected[token * KT_TEST_WIDTH];
        uint32_t expected_feature;
        uint32_t actual_feature;
        uint32_t token_max_abs_error = 0u;

        for (feature = 0u; feature < KT_TEST_WIDTH; feature++) {
            uint32_t flat_index = token * KT_TEST_WIDTH + feature;
            int32_t delta;
            uint32_t magnitude;

            actual[token][feature] = get_i16(
                model_ddr,
                (size_t)output_binding->ddr_addr +
                    (size_t)flat_index * sizeof(int16_t));
            delta =
                (int32_t)actual[token][feature] -
                (int32_t)expected[feature];
            magnitude = (uint32_t)(delta < 0 ? -delta : delta);
            signed_error[feature] = (int16_t)delta;
            absolute_error[feature] = (int16_t)magnitude;
            if (magnitude == 0u) {
                exact++;
            }
            if (magnitude <= KT_TEST_ALLOWED_ABS_ERROR) {
                within_tolerance++;
            }
            if (magnitude > token_max_abs_error) {
                token_max_abs_error = magnitude;
            }
            if (magnitude > max_abs_error) {
                max_abs_error = magnitude;
            }
            absolute_error_sum += magnitude;
            squared_error_sum += (double)delta * (double)delta;
        }

        expected_feature = maximum_feature(expected);
        actual_feature = maximum_feature(actual[token]);
        if (expected_feature == actual_feature) {
            top_feature_correct++;
        }
        printf("token=%u\n", (unsigned)token);
        print_fixed_vector("  input_fixed", input);
        print_float_vector("  input_float", input);
        print_fixed_vector("  actual_fixed", actual[token]);
        print_float_vector("  actual_float", actual[token]);
        print_fixed_vector("  keras_expected_fixed", expected);
        print_float_vector("  keras_expected_float", expected);
        print_fixed_vector("  signed_error_lsb", signed_error);
        print_fixed_vector("  absolute_error_lsb", absolute_error);
        printf("  expected_max_feature=%u actual_max_feature=%u "
               "max_feature_match=%s token_max_abs_error=%u\n",
               (unsigned)expected_feature,
               (unsigned)actual_feature,
               expected_feature == actual_feature ? "yes" : "no",
               (unsigned)token_max_abs_error);
    }

    printf("metrics exact=%u/%u exact_ratio=%.6f "
           "within_tolerance=%u/%u within_tolerance_ratio=%.6f "
           "max_abs_error_lsb=%u mae_lsb=%.6f mse_lsb2=%.6f "
           "max_feature_accuracy=%u/%u max_feature_ratio=%.6f\n",
           (unsigned)exact,
           (unsigned)MODEL_ELEMENT_COUNT,
           (double)exact / (double)MODEL_ELEMENT_COUNT,
           (unsigned)within_tolerance,
           (unsigned)MODEL_ELEMENT_COUNT,
           (double)within_tolerance / (double)MODEL_ELEMENT_COUNT,
           (unsigned)max_abs_error,
           (double)absolute_error_sum / (double)MODEL_ELEMENT_COUNT,
           squared_error_sum / (double)MODEL_ELEMENT_COUNT,
           (unsigned)top_feature_correct,
           (unsigned)KT_TEST_TOKENS,
           (double)top_feature_correct / (double)KT_TEST_TOKENS);

    return within_tolerance == MODEL_ELEMENT_COUNT &&
                   top_feature_correct == KT_TEST_TOKENS
               ? 0
               : -1;
}

int main(void)
{
    npu_driver_t driver;
    npu_drv_platform_ops_t operations;
    uint64_t fence_result = 0u;

    CHECK(initialize_device_images());
    CHECK(transformer_cmodel_backend_init(
        &model_backend,
        model_l1,
        sizeof(model_l1),
        model_ddr,
        sizeof(model_ddr)));
    operations = transformer_cmodel_backend_operations(&model_backend);
    CHECK(npu_drv_init(&driver, &operations));
    CHECK(sync_device_images(&driver));
    CHECK(run_batches(&driver));
    CHECK(npu_drv_fence(&driver, 1000000u, &fence_result));
    CHECK(check_output(&driver));
    CHECK(model_backend.submitted_bursts ==
                  KERAS_TRANSFORMER_MODEL_COMMAND_BATCH_COUNT &&
              model_backend.submitted_beats ==
                  KERAS_TRANSFORMER_MODEL_COMMAND_COUNT *
                      NPU_DRV_CMD128_BEATS &&
              model_backend.responses ==
                  KERAS_TRANSFORMER_MODEL_COMMAND_COUNT &&
              model_backend.pending_response_count == 0u
          ? 0
          : -1);

    printf("PASS model=keras_transformer_encoder "
           "commands=%u cmd_bits=%u batches=%u "
           "submitted_bursts=%u submitted_beats=%u "
           "responses=%u cycles=%llu "
           "cache_clean=%u cache_invalidate=%u\n",
           KERAS_TRANSFORMER_MODEL_COMMAND_COUNT,
           KERAS_TRANSFORMER_MODEL_COMMAND_BITS,
           KERAS_TRANSFORMER_MODEL_COMMAND_BATCH_COUNT,
           (unsigned)model_backend.submitted_bursts,
           (unsigned)model_backend.submitted_beats,
           (unsigned)model_backend.responses,
           (unsigned long long)model_backend.model.cycle,
           (unsigned)model_backend.cache_clean_calls,
           (unsigned)model_backend.cache_invalidate_calls);
    return 0;
}
