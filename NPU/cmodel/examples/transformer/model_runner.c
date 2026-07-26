#include "cmodel_driver_backend.h"
#include "keras_transformer_model.h"
#include "keras_transformer_test_data.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MODEL_SYSTEM_MEMORY_BYTES (2u * 1024u * 1024u)
#define MODEL_L1_BYTES NPU_REF_L1_BYTES
#define MODEL_INPUT_ELEMENT_COUNT (KT_TEST_TOKENS * KT_TEST_WIDTH)
#define MODEL_OUTPUT_ELEMENT_COUNT (KT_TEST_TOKENS * KT_TEST_CLASSES)
#define MODEL_TOTAL_OUTPUT_ELEMENTS \
    (KT_TEST_SAMPLES * MODEL_OUTPUT_ELEMENT_COUNT)
#define MODEL_SCALE \
    (1.0 / (double)(UINT32_C(1) << KT_TEST_FRACTION_BITS))

#define CHECK(call)                                                        \
    do {                                                                   \
        int check_result = (call);                                         \
        if (check_result != 0) {                                           \
            fprintf(stderr, "failure:%s:%d rc=%d expression=%s\n",        \
                    __FILE__, __LINE__, check_result, #call);               \
            return 1;                                                      \
        }                                                                  \
    } while (0)

typedef struct {
    uint32_t exact_elements;
    uint32_t elements_within_tolerance;
    uint32_t max_abs_error;
    uint64_t absolute_error_sum;
    double squared_error_sum;
    uint32_t keras_correct;
    uint32_t cmodel_correct;
    uint32_t cmodel_matches_keras;
    uint64_t submitted_bursts;
    uint64_t submitted_beats;
    uint64_t responses;
    uint64_t cycles;
    uint64_t cache_clean_calls;
    uint64_t cache_invalidate_calls;
} transformer_metrics_t;

static uint8_t model_l1[MODEL_L1_BYTES];
static uint8_t model_system_memory[MODEL_SYSTEM_MEMORY_BYTES];
static npu_example_cmodel_backend_t model_backend;

static void put_i8(uint8_t *memory, size_t address, int8_t value)
{
    memory[address] = (uint8_t)value;
}

static int8_t get_i8(const uint8_t *memory, size_t address)
{
    uint8_t bits = memory[address];

    if ((bits & 0x80u) != 0u) {
        return (int8_t)(-1 - (int32_t)(0xffu - bits));
    }
    return (int8_t)bits;
}

static int address_span_valid(uint64_t address, size_t bytes)
{
    return address <= MODEL_SYSTEM_MEMORY_BYTES &&
           bytes <= MODEL_SYSTEM_MEMORY_BYTES - (size_t)address;
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

static int initialize_device_images(uint32_t sample)
{
    const keras_transformer_model_binding_t *input;
    size_t fixture_offset;
    uint32_t index;

    if (sample >= KT_TEST_SAMPLES ||
        KERAS_TRANSFORMER_MODEL_INPUT_COUNT != 1u ||
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
    if (input->dtype != NPU_DRV_DTYPE_INT8 ||
        input->rank != 3u ||
        input->shape[0] != 1u ||
        input->shape[1] != KT_TEST_TOKENS ||
        input->shape[2] != KT_TEST_WIDTH ||
        input->bytes != MODEL_INPUT_ELEMENT_COUNT * sizeof(int8_t) ||
        !address_span_valid(input->ddr_addr, input->bytes)) {
        return -1;
    }

    (void)memset(model_l1, 0, sizeof(model_l1));
    (void)memset(model_system_memory, 0, sizeof(model_system_memory));
    (void)memcpy(
        &model_system_memory[KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BASE],
        keras_transformer_model_descriptors,
        (size_t)KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BYTES);
    (void)memcpy(
        &model_system_memory[KERAS_TRANSFORMER_MODEL_WEIGHT_BASE_DDR],
        keras_transformer_model_weights,
        (size_t)KERAS_TRANSFORMER_MODEL_WEIGHT_BYTES);
    fixture_offset = (size_t)sample * MODEL_INPUT_ELEMENT_COUNT;
    for (index = 0u; index < MODEL_INPUT_ELEMENT_COUNT; index++) {
        put_i8(model_system_memory,
               (size_t)input->ddr_addr +
                   (size_t)index * sizeof(int8_t),
               kt_test_input[fixture_offset + index]);
    }
    return 0;
}

static int sync_device_images(npu_driver_t *driver)
{
    const keras_transformer_model_binding_t *input =
        &keras_transformer_model_inputs[0];

    if (npu_drv_sync_for_device(
            driver,
            &model_system_memory[
                KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BASE],
            (size_t)KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BYTES) != NPU_DRV_OK ||
        npu_drv_sync_for_device(
            driver,
            &model_system_memory[
                KERAS_TRANSFORMER_MODEL_WEIGHT_BASE_DDR],
            (size_t)KERAS_TRANSFORMER_MODEL_WEIGHT_BYTES) != NPU_DRV_OK ||
        npu_drv_sync_for_device(
            driver,
            &model_system_memory[input->ddr_addr],
            input->bytes) != NPU_DRV_OK) {
        return -1;
    }
    return 0;
}

static int submit_command_batch(npu_driver_t *driver,
                                uint32_t batch,
                                uint32_t begin,
                                uint32_t end,
                                int verbose)
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

        operations[local_index] = operation_for_command(command_id);
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
    if (verbose != 0) {
        printf("submit burst batch=%u commands=%u beats=%u "
               "burst_completed=%u responses=%u "
               "first_failed_index=%lld rc=%d\n",
               (unsigned)batch,
               (unsigned)command_count,
               (unsigned)(command_count * NPU_DRV_CMD128_BEATS),
               (unsigned)summary.burst_completed,
               (unsigned)summary.responses_received,
               summary.first_failed_index ==
                       NPU_DRV_NO_FAILED_COMMAND
                   ? -1LL
                   : (long long)summary.first_failed_index,
               rc);
    }
    for (local_index = 0u;
         local_index < command_count;
         local_index++) {
        char wait0[24];
        char wait1[24];
        char signal[24];

        if (verbose == 0) {
            continue;
        }
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
        summary.first_failed_index != NPU_DRV_NO_FAILED_COMMAND) {
        return -1;
    }
    return 0;
}

static int wait_query_batch(npu_driver_t *driver,
                            uint32_t batch,
                            int verbose)
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
        if (verbose != 0) {
            printf("complete batch=%u op=%s command_id=%u "
                   "state=%u status=%u progress=%llu rc=%d\n",
                   (unsigned)batch,
                   operation->name,
                   (unsigned)command_id,
                   (unsigned)queried.state,
                   (unsigned)queried.status,
                   (unsigned long long)progress,
                   rc);
        }
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
        if (verbose != 0) {
            printf("ack batch=%u command_id=%u\n",
                   (unsigned)batch,
                   (unsigned)command_id);
        }
    }
    return 0;
}

static int run_batches(npu_driver_t *driver, int verbose)
{
    uint32_t batch;

    if (KERAS_TRANSFORMER_MODEL_COMMAND_BATCH_COUNT == 0u ||
        keras_transformer_model_command_batches[0].command_id_offset != 0u ||
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

        if (verbose != 0) {
            printf("batch begin=%u index=%u commands=%u\n",
                   (unsigned)batch,
                   (unsigned)begin,
                   (unsigned)(end - begin));
        }
        if (submit_command_batch(
                driver, batch, begin, end, verbose) != 0 ||
            wait_query_batch(driver, batch, verbose) != 0) {
            return -1;
        }
    }
    return 0;
}

static uint32_t maximum_i32(const int32_t *values, uint32_t count)
{
    uint32_t index;
    uint32_t best = 0u;

    for (index = 1u; index < count; index++) {
        if (values[index] > values[best]) {
            best = index;
        }
    }
    return best;
}

static void print_i8_vector(const char *label,
                            const int8_t *values,
                            uint32_t count)
{
    uint32_t index;

    printf("%s=[", label);
    for (index = 0u; index < count; index++) {
        printf("%s%d", index == 0u ? "" : ",", (int)values[index]);
    }
    printf("]\n");
}

static void print_float_vector(const char *label,
                               const int8_t *values,
                               uint32_t count)
{
    uint32_t index;

    printf("%s=[", label);
    for (index = 0u; index < count; index++) {
        printf("%s%.6f",
               index == 0u ? "" : ",",
               (double)values[index] * MODEL_SCALE);
    }
    printf("]\n");
}

static void print_error_vector(const char *label,
                               const int8_t *actual,
                               const int8_t *expected,
                               uint32_t count,
                               int absolute)
{
    uint32_t index;

    printf("%s=[", label);
    for (index = 0u; index < count; index++) {
        int32_t delta =
            (int32_t)actual[index] - (int32_t)expected[index];
        if (absolute != 0 && delta < 0) {
            delta = -delta;
        }
        printf("%s%d", index == 0u ? "" : ",", (int)delta);
    }
    printf("]\n");
}

static int check_output(npu_driver_t *driver,
                        uint32_t sample,
                        transformer_metrics_t *metrics)
{
    const keras_transformer_model_binding_t *output_binding =
        &keras_transformer_model_outputs[0];
    int8_t actual[KT_TEST_TOKENS][KT_TEST_CLASSES] = {{0}};
    int32_t keras_score_sum[KT_TEST_CLASSES] = {0};
    int32_t cmodel_score_sum[KT_TEST_CLASSES] = {0};
    size_t input_offset =
        (size_t)sample * MODEL_INPUT_ELEMENT_COUNT;
    size_t expected_offset =
        (size_t)sample * MODEL_OUTPUT_ELEMENT_COUNT;
    size_t token_id_offset = (size_t)sample * KT_TEST_TOKENS;
    uint32_t token;
    uint32_t class_index;
    uint32_t keras_prediction;
    uint32_t cmodel_prediction;
    uint32_t true_class;
    uint32_t sample_exact = 0u;
    uint32_t sample_within_tolerance = 0u;
    uint32_t sample_max_abs_error = 0u;
    uint64_t sample_absolute_error_sum = 0u;
    double sample_squared_error_sum = 0.0;

    if (sample >= KT_TEST_SAMPLES ||
        metrics == (transformer_metrics_t *)0 ||
        output_binding->dtype != NPU_DRV_DTYPE_INT8 ||
        output_binding->rank != 3u ||
        output_binding->shape[0] != 1u ||
        output_binding->shape[1] != KT_TEST_TOKENS ||
        output_binding->shape[2] != KT_TEST_CLASSES ||
        output_binding->bytes !=
            MODEL_OUTPUT_ELEMENT_COUNT * sizeof(int8_t) ||
        !address_span_valid(
            output_binding->ddr_addr, output_binding->bytes)) {
        return -1;
    }
    if (npu_drv_sync_for_cpu(
            driver,
            &model_system_memory[output_binding->ddr_addr],
            output_binding->bytes) != NPU_DRV_OK) {
        return -1;
    }

    printf("\nresult sample=%u sentence=\"",
           (unsigned)sample);
    for (token = 0u; token < KT_TEST_TOKENS; token++) {
        uint32_t token_id = kt_test_token_ids[token_id_offset + token];
        if (token_id >= KT_TEST_WIDTH) {
            return -1;
        }
        printf("%s%s",
               token == 0u ? "" : " ",
               kt_vocabulary[token_id]);
    }
    printf("\" true_intent=%s\n", kt_class_names[kt_test_labels[sample]]);
    printf("input_shape=[1,%u,%u] output_shape=[1,%u,%u] "
           "Q%u_scale=%.9f\n",
           (unsigned)KT_TEST_TOKENS,
           (unsigned)KT_TEST_WIDTH,
           (unsigned)KT_TEST_TOKENS,
           (unsigned)KT_TEST_CLASSES,
           (unsigned)KT_TEST_FRACTION_BITS,
           MODEL_SCALE);

    for (token = 0u; token < KT_TEST_TOKENS; token++) {
        const int8_t *input =
            &kt_test_input[
                input_offset + (size_t)token * KT_TEST_WIDTH];
        const int8_t *expected =
            &kt_test_expected[
                expected_offset + (size_t)token * KT_TEST_CLASSES];
        uint32_t token_id = kt_test_token_ids[token_id_offset + token];
        uint32_t token_max_abs_error = 0u;

        printf("token_position=%u word=%s meaning=\"%s\"\n",
               (unsigned)token,
               kt_vocabulary[token_id],
               kt_token_meanings[token_id]);
        print_i8_vector(
            "  input_one_hot_INT8", input, KT_TEST_WIDTH);
        print_float_vector(
            "  input_one_hot_real", input, KT_TEST_WIDTH);
        for (class_index = 0u;
             class_index < KT_TEST_CLASSES;
             class_index++) {
            uint32_t flat_index =
                token * KT_TEST_CLASSES + class_index;
            int32_t delta;
            uint32_t magnitude;

            actual[token][class_index] = get_i8(
                model_system_memory,
                (size_t)output_binding->ddr_addr +
                    (size_t)flat_index * sizeof(int8_t));
            delta =
                (int32_t)actual[token][class_index] -
                (int32_t)expected[class_index];
            magnitude = (uint32_t)(delta < 0 ? -delta : delta);
            if (magnitude == 0u) {
                sample_exact++;
            }
            if (magnitude <= KT_TEST_ALLOWED_ABS_ERROR) {
                sample_within_tolerance++;
            }
            if (magnitude > token_max_abs_error) {
                token_max_abs_error = magnitude;
            }
            if (magnitude > sample_max_abs_error) {
                sample_max_abs_error = magnitude;
            }
            sample_absolute_error_sum += magnitude;
            sample_squared_error_sum += (double)delta * (double)delta;
            keras_score_sum[class_index] += (int32_t)expected[class_index];
            cmodel_score_sum[class_index] +=
                (int32_t)actual[token][class_index];
        }
        print_i8_vector(
            "  Keras_reference_INT8", expected, KT_TEST_CLASSES);
        print_float_vector(
            "  Keras_reference", expected, KT_TEST_CLASSES);
        print_i8_vector(
            "  CModel_output_INT8", actual[token], KT_TEST_CLASSES);
        print_float_vector(
            "  CModel_output", actual[token], KT_TEST_CLASSES);
        print_error_vector(
            "  signed_error_lsb",
            actual[token],
            expected,
            KT_TEST_CLASSES,
            0);
        print_error_vector(
            "  absolute_error_lsb",
            actual[token],
            expected,
            KT_TEST_CLASSES,
            1);
        printf("  token_max_abs_error_lsb=%u\n",
               (unsigned)token_max_abs_error);
    }

    true_class = kt_test_labels[sample];
    if (true_class >= KT_TEST_CLASSES) {
        return -1;
    }
    keras_prediction =
        maximum_i32(keras_score_sum, KT_TEST_CLASSES);
    cmodel_prediction =
        maximum_i32(cmodel_score_sum, KT_TEST_CLASSES);
    metrics->exact_elements += sample_exact;
    metrics->elements_within_tolerance += sample_within_tolerance;
    metrics->absolute_error_sum += sample_absolute_error_sum;
    metrics->squared_error_sum += sample_squared_error_sum;
    if (sample_max_abs_error > metrics->max_abs_error) {
        metrics->max_abs_error = sample_max_abs_error;
    }
    if (keras_prediction == true_class) {
        metrics->keras_correct++;
    }
    if (cmodel_prediction == true_class) {
        metrics->cmodel_correct++;
    }
    if (cmodel_prediction == keras_prediction) {
        metrics->cmodel_matches_keras++;
    }

    printf("sentence_scores class_order=[");
    for (class_index = 0u;
         class_index < KT_TEST_CLASSES;
         class_index++) {
        printf("%s%s",
               class_index == 0u ? "" : ",",
               kt_class_names[class_index]);
    }
    printf("]\n");
    printf("  Keras_reference_mean=[");
    for (class_index = 0u;
         class_index < KT_TEST_CLASSES;
         class_index++) {
        printf("%s%.6f",
               class_index == 0u ? "" : ",",
               (double)keras_score_sum[class_index] *
                   MODEL_SCALE / (double)KT_TEST_TOKENS);
    }
    printf("]\n");
    printf("  CModel_output_mean=[");
    for (class_index = 0u;
         class_index < KT_TEST_CLASSES;
         class_index++) {
        printf("%s%.6f",
               class_index == 0u ? "" : ",",
               (double)cmodel_score_sum[class_index] *
                   MODEL_SCALE / (double)KT_TEST_TOKENS);
    }
    printf("]\n");
    printf("  Keras_prediction=%s CModel_prediction=%s "
           "true_intent=%s Keras_correct=%s CModel_correct=%s "
           "CModel_matches_Keras=%s\n",
           kt_class_names[keras_prediction],
           kt_class_names[cmodel_prediction],
           kt_class_names[true_class],
           keras_prediction == true_class ? "yes" : "no",
           cmodel_prediction == true_class ? "yes" : "no",
           cmodel_prediction == keras_prediction ? "yes" : "no");
    printf("sample_error exact=%u/%u within_%u_lsb=%u/%u "
           "max_abs_error_lsb=%u mae_lsb=%.6f mse_lsb2=%.6f\n",
           (unsigned)sample_exact,
           (unsigned)MODEL_OUTPUT_ELEMENT_COUNT,
           (unsigned)KT_TEST_ALLOWED_ABS_ERROR,
           (unsigned)sample_within_tolerance,
           (unsigned)MODEL_OUTPUT_ELEMENT_COUNT,
           (unsigned)sample_max_abs_error,
           (double)sample_absolute_error_sum /
               (double)MODEL_OUTPUT_ELEMENT_COUNT,
           sample_squared_error_sum /
               (double)MODEL_OUTPUT_ELEMENT_COUNT);
    return 0;
}

static int backend_counts_valid(void)
{
    return model_backend.submitted_bursts ==
                   KERAS_TRANSFORMER_MODEL_COMMAND_BATCH_COUNT &&
               model_backend.submitted_beats ==
                   KERAS_TRANSFORMER_MODEL_COMMAND_COUNT *
                       NPU_DRV_CMD128_BEATS &&
               model_backend.responses ==
                   KERAS_TRANSFORMER_MODEL_COMMAND_COUNT &&
               model_backend.pending_response_count == 0u
           ? 0
           : -1;
}

int main(void)
{
    transformer_metrics_t metrics;
    uint32_t sample;

    (void)memset(&metrics, 0, sizeof(metrics));
    printf("task=room_device_command_intent_classification "
           "fit_method=Keras_model_fit held_out_samples=%u\n",
           (unsigned)KT_TEST_SAMPLES);
    printf("device_images descriptor_addr=0x%llx descriptor_bytes=%u "
           "weight_addr=0x%llx weight_bytes=%u input_addr=0x%llx "
           "input_bytes=%u output_addr=0x%llx output_bytes=%u\n",
           (unsigned long long)
               KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BASE,
           (unsigned)KERAS_TRANSFORMER_MODEL_DESCRIPTOR_BYTES,
           (unsigned long long)
               KERAS_TRANSFORMER_MODEL_WEIGHT_BASE_DDR,
           (unsigned)KERAS_TRANSFORMER_MODEL_WEIGHT_BYTES,
           (unsigned long long)
               keras_transformer_model_inputs[0].ddr_addr,
           (unsigned)keras_transformer_model_inputs[0].bytes,
           (unsigned long long)
               keras_transformer_model_outputs[0].ddr_addr,
           (unsigned)keras_transformer_model_outputs[0].bytes);

    for (sample = 0u; sample < KT_TEST_SAMPLES; sample++) {
        npu_driver_t driver;
        npu_drv_platform_ops_t operations;
        uint64_t fence_result = 0u;
        int verbose = sample == 0u ? 1 : 0;

        printf("\n=== inference sample=%u/%u ===\n",
               (unsigned)(sample + 1u),
               (unsigned)KT_TEST_SAMPLES);
        if (verbose != 0) {
            printf("task_sequence_detail=enabled "
                   "wait_and_signal_events_are_printed_below\n");
        } else {
            printf("task_sequence_detail=not_repeated "
                   "same_generated_commands_as_sample_0\n");
        }
        CHECK(initialize_device_images(sample));
        CHECK(npu_example_cmodel_backend_init(
            &model_backend,
            model_l1,
            sizeof(model_l1),
            model_system_memory,
            sizeof(model_system_memory)));
        operations = npu_example_cmodel_backend_operations(&model_backend);
        CHECK(npu_drv_init(&driver, &operations));
        CHECK(sync_device_images(&driver));
        CHECK(run_batches(&driver, verbose));
        CHECK(npu_drv_fence(&driver, 1000000u, &fence_result));
        CHECK(fence_result == 0u ? 0 : -1);
        CHECK(check_output(&driver, sample, &metrics));
        CHECK(backend_counts_valid());

        metrics.submitted_bursts += model_backend.submitted_bursts;
        metrics.submitted_beats += model_backend.submitted_beats;
        metrics.responses += model_backend.responses;
        metrics.cycles += model_backend.model.cycle;
        metrics.cache_clean_calls += model_backend.cache_clean_calls;
        metrics.cache_invalidate_calls +=
            model_backend.cache_invalidate_calls;
    }

    printf("\nclassification_metrics "
           "CModel_accuracy=%u/%u=%.7f "
           "Keras_accuracy=%u/%u=%.7f "
           "agreement=%u/%u=%.7f\n",
           (unsigned)metrics.cmodel_correct,
           (unsigned)KT_TEST_SAMPLES,
           (double)metrics.cmodel_correct / (double)KT_TEST_SAMPLES,
           (unsigned)metrics.keras_correct,
           (unsigned)KT_TEST_SAMPLES,
           (double)metrics.keras_correct / (double)KT_TEST_SAMPLES,
           (unsigned)metrics.cmodel_matches_keras,
           (unsigned)KT_TEST_SAMPLES,
           (double)metrics.cmodel_matches_keras /
               (double)KT_TEST_SAMPLES);
    printf("CModel_vs_Keras exact=%u/%u exact_ratio=%.7f "
           "within_%u_lsb=%u/%u ratio=%.7f "
           "max_abs_error_lsb=%u mae_lsb=%.7f mse_lsb2=%.7f\n",
           (unsigned)metrics.exact_elements,
           (unsigned)MODEL_TOTAL_OUTPUT_ELEMENTS,
           (double)metrics.exact_elements /
               (double)MODEL_TOTAL_OUTPUT_ELEMENTS,
           (unsigned)KT_TEST_ALLOWED_ABS_ERROR,
           (unsigned)metrics.elements_within_tolerance,
           (unsigned)MODEL_TOTAL_OUTPUT_ELEMENTS,
           (double)metrics.elements_within_tolerance /
               (double)MODEL_TOTAL_OUTPUT_ELEMENTS,
           (unsigned)metrics.max_abs_error,
           (double)metrics.absolute_error_sum /
               (double)MODEL_TOTAL_OUTPUT_ELEMENTS,
           metrics.squared_error_sum /
               (double)MODEL_TOTAL_OUTPUT_ELEMENTS);
    CHECK(metrics.keras_correct == KT_TEST_SAMPLES &&
                  metrics.cmodel_correct == KT_TEST_SAMPLES &&
                  metrics.cmodel_matches_keras == KT_TEST_SAMPLES &&
                  metrics.elements_within_tolerance ==
                      MODEL_TOTAL_OUTPUT_ELEMENTS
              ? 0
              : -1);
    printf("PASS model=keras_transformer_intent_classifier "
           "commands_per_sample=%u cmd_bits=%u batches_per_sample=%u "
           "samples=%u submitted_bursts=%llu submitted_beats=%llu "
           "responses=%llu cycles=%llu "
           "cache_clean=%llu cache_invalidate=%llu\n",
           KERAS_TRANSFORMER_MODEL_COMMAND_COUNT,
           KERAS_TRANSFORMER_MODEL_COMMAND_BITS,
           KERAS_TRANSFORMER_MODEL_COMMAND_BATCH_COUNT,
           (unsigned)KT_TEST_SAMPLES,
           (unsigned long long)metrics.submitted_bursts,
           (unsigned long long)metrics.submitted_beats,
           (unsigned long long)metrics.responses,
           (unsigned long long)metrics.cycles,
           (unsigned long long)metrics.cache_clean_calls,
           (unsigned long long)metrics.cache_invalidate_calls);
    return 0;
}
