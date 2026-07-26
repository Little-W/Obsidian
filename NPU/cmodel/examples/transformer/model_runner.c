#include "cmodel_driver_backend.h"
#include "keras_transformer_model.h"
#include "keras_transformer_test_data.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MODEL_SYSTEM_MEMORY_BYTES (2u * 1024u * 1024u)
#define MODEL_L1_BYTES NPU_REF_L1_BYTES
#define MODEL_FEATURE_ELEMENTS (KT_TEST_TOKENS * KT_TEST_WIDTH)
#define MODEL_LOGIT_ELEMENTS (KT_TEST_TOKENS * KT_TEST_CLASSES)
#define MODEL_NEAR_LIMIT_INT8 \
    ((INT32_C(95) * (INT32_C(1) << KT_TEST_FRACTION_BITS) + \
      INT32_C(99)) / INT32_C(100))
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
    const char *name;
    uint32_t tolerance;
    uint32_t element_count;
    uint32_t exact_count;
    uint32_t within_tolerance_count;
    uint32_t max_abs_error;
    uint64_t absolute_error_sum;
    double squared_error_sum;
    int32_t minimum;
    int32_t maximum;
    int64_t value_sum;
    uint64_t value_square_sum;
    uint32_t int8_extreme_count;
    uint32_t near_limit_count;
    uint8_t seen[256];
} tensor_metrics_t;

typedef struct {
    tensor_metrics_t probe1;
    tensor_metrics_t probe2;
    tensor_metrics_t logits;
    uint32_t keras_correct;
    uint32_t cmodel_correct;
    uint32_t cmodel_matches_keras;
    double minimum_keras_margin;
    double minimum_cmodel_margin;
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
    if (event.id == NPU_DRV_EVENT_NONE) {
        (void)snprintf(text, text_bytes, "none");
    } else {
        (void)snprintf(text, text_bytes, "%u", (unsigned)event.id);
    }
}

static int initialize_device_images(uint32_t sample)
{
    const keras_transformer_model_binding_t *word_input;
    const keras_transformer_model_binding_t *position_input;
    size_t fixture_offset;
    uint32_t index;

    if (sample >= KT_TEST_SAMPLES ||
        KERAS_TRANSFORMER_MODEL_INPUT_COUNT != 2u ||
        KERAS_TRANSFORMER_MODEL_OUTPUT_COUNT != 3u ||
        keras_transformer_model_config.command_format ==
            (const char *)0 ||
        strcmp(keras_transformer_model_config.command_format,
               "cmd128-inline-v2") != 0 ||
        keras_transformer_model_config.commands !=
            keras_transformer_model_commands ||
        keras_transformer_model_config.command_count !=
            KERAS_TRANSFORMER_MODEL_COMMAND_COUNT ||
        keras_transformer_model_config.weights !=
            keras_transformer_model_weights ||
        keras_transformer_model_config.weight_bytes !=
            KERAS_TRANSFORMER_MODEL_WEIGHT_BYTES) {
        return -1;
    }
    if (!address_span_valid(
            KERAS_TRANSFORMER_MODEL_WEIGHT_BASE_DDR,
            (size_t)KERAS_TRANSFORMER_MODEL_WEIGHT_BYTES)) {
        return -1;
    }
    word_input = &keras_transformer_model_inputs[0];
    position_input = &keras_transformer_model_inputs[1];
    if (word_input->dtype != NPU_DRV_DTYPE_INT8 ||
        position_input->dtype != NPU_DRV_DTYPE_INT8 ||
        word_input->rank != 3u || position_input->rank != 3u ||
        word_input->shape[0] != 1u || position_input->shape[0] != 1u ||
        word_input->shape[1] != KT_TEST_TOKENS ||
        position_input->shape[1] != KT_TEST_TOKENS ||
        word_input->shape[2] != KT_TEST_WIDTH ||
        position_input->shape[2] != KT_TEST_WIDTH ||
        word_input->bytes != MODEL_FEATURE_ELEMENTS * sizeof(int8_t) ||
        position_input->bytes != MODEL_FEATURE_ELEMENTS * sizeof(int8_t) ||
        !address_span_valid(word_input->ddr_addr, word_input->bytes) ||
        !address_span_valid(
            position_input->ddr_addr, position_input->bytes)) {
        return -1;
    }

    (void)memset(model_l1, 0, sizeof(model_l1));
    (void)memset(model_system_memory, 0, sizeof(model_system_memory));
    (void)memcpy(
        &model_system_memory[KERAS_TRANSFORMER_MODEL_WEIGHT_BASE_DDR],
        keras_transformer_model_weights,
        (size_t)KERAS_TRANSFORMER_MODEL_WEIGHT_BYTES);
    fixture_offset = (size_t)sample * MODEL_FEATURE_ELEMENTS;
    for (index = 0u; index < MODEL_FEATURE_ELEMENTS; index++) {
        put_i8(model_system_memory,
               (size_t)word_input->ddr_addr +
                   (size_t)index * sizeof(int8_t),
               kt_test_word_input[fixture_offset + index]);
        put_i8(model_system_memory,
               (size_t)position_input->ddr_addr +
                   (size_t)index * sizeof(int8_t),
               kt_test_position_input[fixture_offset + index]);
    }
    return 0;
}

static int sync_device_images(npu_driver_t *driver)
{
    const keras_transformer_model_binding_t *word_input =
        &keras_transformer_model_inputs[0];
    const keras_transformer_model_binding_t *position_input =
        &keras_transformer_model_inputs[1];

    if (npu_drv_sync_for_device(
            driver,
            &model_system_memory[
                KERAS_TRANSFORMER_MODEL_WEIGHT_BASE_DDR],
            (size_t)KERAS_TRANSFORMER_MODEL_WEIGHT_BYTES) != NPU_DRV_OK ||
        npu_drv_sync_for_device(
            driver,
            &model_system_memory[word_input->ddr_addr],
            word_input->bytes) != NPU_DRV_OK ||
        npu_drv_sync_for_device(
            driver,
            &model_system_memory[position_input->ddr_addr],
            position_input->bytes) != NPU_DRV_OK) {
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

        operations[local_index] = operation_for_command(command_id);
        if (operations[local_index] ==
                (const keras_transformer_model_operation_t *)0 ||
            command_for_id(
                command_id,
                &commands[local_index],
                &fields[local_index]) != 0) {
            return -1;
        }
    }

    rc = npu_drv_submit_batch(
        driver,
        commands,
        command_count,
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

typedef struct {
    int32_t minimum;
    int32_t maximum;
    int64_t sum;
    uint64_t square_sum;
    uint32_t extreme_count;
    uint32_t near_limit_count;
} sample_stats_t;

static void tensor_metrics_init(tensor_metrics_t *metrics,
                                const char *name,
                                uint32_t tolerance)
{
    (void)memset(metrics, 0, sizeof(*metrics));
    metrics->name = name;
    metrics->tolerance = tolerance;
    metrics->minimum = 128;
    metrics->maximum = -129;
}

static sample_stats_t sample_stats(const int8_t *values, uint32_t count)
{
    sample_stats_t result;
    uint32_t index;

    result.minimum = 128;
    result.maximum = -129;
    result.sum = 0;
    result.square_sum = 0u;
    result.extreme_count = 0u;
    result.near_limit_count = 0u;
    for (index = 0u; index < count; index++) {
        int32_t value = (int32_t)values[index];
        int32_t magnitude = value < 0 ? -value : value;

        if (value < result.minimum) {
            result.minimum = value;
        }
        if (value > result.maximum) {
            result.maximum = value;
        }
        result.sum += value;
        result.square_sum += (uint64_t)(value * value);
        if (value == -128 || value == 127) {
            result.extreme_count++;
        }
        if (magnitude >= MODEL_NEAR_LIMIT_INT8) {
            result.near_limit_count++;
        }
    }
    return result;
}

static double stats_stddev(const sample_stats_t *stats, uint32_t count)
{
    double mean = (double)stats->sum / (double)count;
    double variance =
        (double)stats->square_sum / (double)count - mean * mean;

    return sqrt(variance > 0.0 ? variance : 0.0);
}

static void print_sample_stats(const char *label,
                               const int8_t *values,
                               uint32_t count)
{
    sample_stats_t stats = sample_stats(values, count);

    printf("%s min=%d max=%d mean=%.7f std=%.7f "
           "int8_extreme=%u/%u abs_ge_0.95=%u/%u\n",
           label,
           (int)stats.minimum,
           (int)stats.maximum,
           (double)stats.sum * MODEL_SCALE / (double)count,
           stats_stddev(&stats, count) * MODEL_SCALE,
           (unsigned)stats.extreme_count,
           (unsigned)count,
           (unsigned)stats.near_limit_count,
           (unsigned)count);
}

static void update_tensor_metrics(tensor_metrics_t *metrics,
                                  const int8_t *actual,
                                  const int8_t *expected,
                                  uint32_t count)
{
    uint32_t index;

    for (index = 0u; index < count; index++) {
        int32_t value = (int32_t)actual[index];
        int32_t delta = value - (int32_t)expected[index];
        uint32_t magnitude =
            (uint32_t)(delta < 0 ? -delta : delta);
        int32_t value_magnitude = value < 0 ? -value : value;

        metrics->element_count++;
        if (magnitude == 0u) {
            metrics->exact_count++;
        }
        if (magnitude <= metrics->tolerance) {
            metrics->within_tolerance_count++;
        }
        if (magnitude > metrics->max_abs_error) {
            metrics->max_abs_error = magnitude;
        }
        metrics->absolute_error_sum += magnitude;
        metrics->squared_error_sum += (double)delta * (double)delta;
        if (value < metrics->minimum) {
            metrics->minimum = value;
        }
        if (value > metrics->maximum) {
            metrics->maximum = value;
        }
        metrics->value_sum += value;
        metrics->value_square_sum += (uint64_t)(value * value);
        if (value == -128 || value == 127) {
            metrics->int8_extreme_count++;
        }
        if (value_magnitude >= MODEL_NEAR_LIMIT_INT8) {
            metrics->near_limit_count++;
        }
        metrics->seen[(uint8_t)((uint32_t)value + 128u)] = 1u;
    }
}

static uint32_t unique_value_count(const tensor_metrics_t *metrics)
{
    uint32_t count = 0u;
    uint32_t index;

    for (index = 0u; index < 256u; index++) {
        count += metrics->seen[index] != 0u ? 1u : 0u;
    }
    return count;
}

static double tensor_stddev_real(const tensor_metrics_t *metrics)
{
    double mean =
        (double)metrics->value_sum / (double)metrics->element_count;
    double variance =
        (double)metrics->value_square_sum /
            (double)metrics->element_count -
        mean * mean;

    return sqrt(variance > 0.0 ? variance : 0.0) * MODEL_SCALE;
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

static void print_real_vector(const char *label,
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

static int read_output(npu_driver_t *driver,
                       uint32_t output_index,
                       uint32_t last_dimension,
                       int8_t *values,
                       uint32_t element_count)
{
    const keras_transformer_model_binding_t *binding;
    uint32_t index;

    if (output_index >= KERAS_TRANSFORMER_MODEL_OUTPUT_COUNT) {
        return -1;
    }
    binding = &keras_transformer_model_outputs[output_index];
    if (binding->dtype != NPU_DRV_DTYPE_INT8 ||
        binding->rank != 3u ||
        binding->shape[0] != 1u ||
        binding->shape[1] != KT_TEST_TOKENS ||
        binding->shape[2] != last_dimension ||
        binding->bytes != element_count * sizeof(int8_t) ||
        !address_span_valid(binding->ddr_addr, binding->bytes) ||
        npu_drv_sync_for_cpu(
            driver,
            &model_system_memory[binding->ddr_addr],
            binding->bytes) != NPU_DRV_OK) {
        return -1;
    }
    for (index = 0u; index < element_count; index++) {
        values[index] = get_i8(
            model_system_memory,
            (size_t)binding->ddr_addr + (size_t)index);
    }
    return 0;
}

static void print_probe_result(const char *name,
                               const int8_t *actual,
                               const int8_t *expected,
                               uint32_t count,
                               uint32_t tolerance)
{
    uint32_t index;
    uint32_t exact = 0u;
    uint32_t within = 0u;
    uint32_t maximum = 0u;
    uint64_t absolute_sum = 0u;

    for (index = 0u; index < count; index++) {
        int32_t delta =
            (int32_t)actual[index] - (int32_t)expected[index];
        uint32_t magnitude =
            (uint32_t)(delta < 0 ? -delta : delta);

        exact += magnitude == 0u ? 1u : 0u;
        within += magnitude <= tolerance ? 1u : 0u;
        maximum = magnitude > maximum ? magnitude : maximum;
        absolute_sum += magnitude;
    }
    printf("%s comparison exact=%u/%u within_%u_lsb=%u/%u "
           "max_abs_error_lsb=%u mae_lsb=%.7f\n",
           name,
           (unsigned)exact,
           (unsigned)count,
           (unsigned)tolerance,
           (unsigned)within,
           (unsigned)count,
           (unsigned)maximum,
           (double)absolute_sum / (double)count);
    print_sample_stats("  Keras", expected, count);
    print_sample_stats("  CModel", actual, count);
}

static uint32_t maximum_i32(const int32_t *values, uint32_t count)
{
    uint32_t best = 0u;
    uint32_t index;

    for (index = 1u; index < count; index++) {
        if (values[index] > values[best]) {
            best = index;
        }
    }
    return best;
}

static double score_margin(const int32_t *scores,
                           uint32_t count,
                           uint32_t valid_length)
{
    uint32_t best = maximum_i32(scores, count);
    int32_t second = INT32_MIN;
    uint32_t index;

    for (index = 0u; index < count; index++) {
        if (index != best && scores[index] > second) {
            second = scores[index];
        }
    }
    return (double)(scores[best] - second) * MODEL_SCALE /
           (double)valid_length;
}

static int check_outputs(npu_driver_t *driver,
                         uint32_t sample,
                         transformer_metrics_t *metrics)
{
    int8_t actual_probe1[MODEL_FEATURE_ELEMENTS];
    int8_t actual_probe2[MODEL_FEATURE_ELEMENTS];
    int8_t actual_logits[MODEL_LOGIT_ELEMENTS];
    int32_t keras_scores[KT_TEST_CLASSES] = {0};
    int32_t cmodel_scores[KT_TEST_CLASSES] = {0};
    size_t feature_offset = (size_t)sample * MODEL_FEATURE_ELEMENTS;
    size_t logit_offset = (size_t)sample * MODEL_LOGIT_ELEMENTS;
    size_t token_offset = (size_t)sample * KT_TEST_TOKENS;
    uint32_t valid_length;
    uint32_t true_class;
    uint32_t keras_prediction;
    uint32_t cmodel_prediction;
    double keras_margin;
    double cmodel_margin;
    uint32_t token;
    uint32_t class_index;

    if (sample >= KT_TEST_SAMPLES ||
        metrics == (transformer_metrics_t *)0 ||
        read_output(
            driver, 0u, KT_TEST_WIDTH,
            actual_probe1, MODEL_FEATURE_ELEMENTS) != 0 ||
        read_output(
            driver, 1u, KT_TEST_WIDTH,
            actual_probe2, MODEL_FEATURE_ELEMENTS) != 0 ||
        read_output(
            driver, 2u, KT_TEST_CLASSES,
            actual_logits, MODEL_LOGIT_ELEMENTS) != 0) {
        return -1;
    }
    valid_length = kt_test_valid_lengths[sample];
    true_class = kt_test_labels[sample];
    if (valid_length == 0u || valid_length > KT_TEST_TOKENS ||
        true_class >= KT_TEST_CLASSES) {
        return -1;
    }

    printf("\nresult sample=%u valid_tokens=%u padded_positions=%u "
           "sentence=\"",
           (unsigned)sample,
           (unsigned)valid_length,
           (unsigned)(KT_TEST_TOKENS - valid_length));
    for (token = 0u; token < valid_length; token++) {
        uint32_t token_id = kt_test_token_ids[token_offset + token];

        if (token_id >= KT_TEST_VOCAB_SIZE) {
            return -1;
        }
        printf("%s%s", token == 0u ? "" : " ",
               kt_vocabulary[token_id]);
    }
    printf("\" true_intent=%s\n", kt_class_names[true_class]);
    printf("input_shapes=[[1,%u,%u],[1,%u,%u]] "
           "output_shapes=[[1,%u,%u],[1,%u,%u],[1,%u,%u]] "
           "Q%u_scale=%.9f\n",
           (unsigned)KT_TEST_TOKENS, (unsigned)KT_TEST_WIDTH,
           (unsigned)KT_TEST_TOKENS, (unsigned)KT_TEST_WIDTH,
           (unsigned)KT_TEST_TOKENS, (unsigned)KT_TEST_WIDTH,
           (unsigned)KT_TEST_TOKENS, (unsigned)KT_TEST_WIDTH,
           (unsigned)KT_TEST_TOKENS, (unsigned)KT_TEST_CLASSES,
           (unsigned)KT_TEST_FRACTION_BITS, MODEL_SCALE);

    for (token = 0u; token < KT_TEST_TOKENS; token++) {
        uint32_t token_id = kt_test_token_ids[token_offset + token];
        const int8_t *word =
            &kt_test_word_input[
                feature_offset + (size_t)token * KT_TEST_WIDTH];
        const int8_t *position =
            &kt_test_position_input[
                feature_offset + (size_t)token * KT_TEST_WIDTH +
                KT_TEST_VOCAB_SIZE];

        if (token_id >= KT_TEST_VOCAB_SIZE) {
            return -1;
        }
        printf("input_token position=%u role=%s word=%s "
               "meaning=\"%s\" one_hot_channel=%u one_hot_q=%d\n",
               (unsigned)token,
               token < valid_length ? "valid" : "padding",
               kt_vocabulary[token_id],
               kt_token_meanings[token_id],
               (unsigned)token_id,
               (int)word[token_id]);
        print_i8_vector(
            "  position_features_INT8",
            position,
            KT_TEST_POSITION_WIDTH);
        print_real_vector(
            "  position_features_real",
            position,
            KT_TEST_POSITION_WIDTH);
    }

    print_probe_result(
        "encoder1_probe",
        actual_probe1,
        &kt_test_probe1[feature_offset],
        MODEL_FEATURE_ELEMENTS,
        KT_PROBE1_ALLOWED_ABS_ERROR);
    print_probe_result(
        "encoder2_probe",
        actual_probe2,
        &kt_test_probe2[feature_offset],
        MODEL_FEATURE_ELEMENTS,
        KT_PROBE2_ALLOWED_ABS_ERROR);

    printf("logit_class_order=[");
    for (class_index = 0u;
         class_index < KT_TEST_CLASSES;
         class_index++) {
        printf("%s%s",
               class_index == 0u ? "" : ",",
               kt_class_names[class_index]);
    }
    printf("]\n");
    for (token = 0u; token < KT_TEST_TOKENS; token++) {
        const int8_t *expected =
            &kt_test_logits[
                logit_offset + (size_t)token * KT_TEST_CLASSES];
        const int8_t *actual =
            &actual_logits[(size_t)token * KT_TEST_CLASSES];

        printf("logit_token position=%u role=%s word=%s\n",
               (unsigned)token,
               token < valid_length ? "valid" : "padding",
               kt_vocabulary[kt_test_token_ids[token_offset + token]]);
        print_i8_vector("  Keras_INT8", expected, KT_TEST_CLASSES);
        print_real_vector("  Keras_real", expected, KT_TEST_CLASSES);
        print_i8_vector("  CModel_INT8", actual, KT_TEST_CLASSES);
        print_real_vector("  CModel_real", actual, KT_TEST_CLASSES);
        print_error_vector(
            "  signed_error_lsb",
            actual,
            expected,
            KT_TEST_CLASSES,
            0);
        print_error_vector(
            "  absolute_error_lsb",
            actual,
            expected,
            KT_TEST_CLASSES,
            1);
        if (token < valid_length) {
            for (class_index = 0u;
                 class_index < KT_TEST_CLASSES;
                 class_index++) {
                keras_scores[class_index] += expected[class_index];
                cmodel_scores[class_index] += actual[class_index];
            }
        }
    }

    update_tensor_metrics(
        &metrics->probe1,
        actual_probe1,
        &kt_test_probe1[feature_offset],
        MODEL_FEATURE_ELEMENTS);
    update_tensor_metrics(
        &metrics->probe2,
        actual_probe2,
        &kt_test_probe2[feature_offset],
        MODEL_FEATURE_ELEMENTS);
    update_tensor_metrics(
        &metrics->logits,
        actual_logits,
        &kt_test_logits[logit_offset],
        MODEL_LOGIT_ELEMENTS);

    keras_prediction = maximum_i32(keras_scores, KT_TEST_CLASSES);
    cmodel_prediction = maximum_i32(cmodel_scores, KT_TEST_CLASSES);
    keras_margin =
        score_margin(keras_scores, KT_TEST_CLASSES, valid_length);
    cmodel_margin =
        score_margin(cmodel_scores, KT_TEST_CLASSES, valid_length);
    if (keras_prediction == true_class) {
        metrics->keras_correct++;
    }
    if (cmodel_prediction == true_class) {
        metrics->cmodel_correct++;
    }
    if (cmodel_prediction == keras_prediction) {
        metrics->cmodel_matches_keras++;
    }
    if (keras_margin < metrics->minimum_keras_margin) {
        metrics->minimum_keras_margin = keras_margin;
    }
    if (cmodel_margin < metrics->minimum_cmodel_margin) {
        metrics->minimum_cmodel_margin = cmodel_margin;
    }

    printf("sentence_mean_logits Keras=[");
    for (class_index = 0u;
         class_index < KT_TEST_CLASSES;
         class_index++) {
        printf("%s%.6f",
               class_index == 0u ? "" : ",",
               (double)keras_scores[class_index] * MODEL_SCALE /
                   (double)valid_length);
    }
    printf("] CModel=[");
    for (class_index = 0u;
         class_index < KT_TEST_CLASSES;
         class_index++) {
        printf("%s%.6f",
               class_index == 0u ? "" : ",",
               (double)cmodel_scores[class_index] * MODEL_SCALE /
                   (double)valid_length);
    }
    printf("]\n");
    printf("classification true=%s Keras=%s CModel=%s "
           "Keras_margin=%.7f CModel_margin=%.7f "
           "Keras_correct=%s CModel_correct=%s agreement=%s\n",
           kt_class_names[true_class],
           kt_class_names[keras_prediction],
           kt_class_names[cmodel_prediction],
           keras_margin,
           cmodel_margin,
           keras_prediction == true_class ? "yes" : "no",
           cmodel_prediction == true_class ? "yes" : "no",
           cmodel_prediction == keras_prediction ? "yes" : "no");
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
    uint32_t binding;
    uint32_t sample;

    (void)memset(&metrics, 0, sizeof(metrics));
    tensor_metrics_init(
        &metrics.probe1,
        "encoder1_probe",
        KT_PROBE1_ALLOWED_ABS_ERROR);
    tensor_metrics_init(
        &metrics.probe2,
        "encoder2_probe",
        KT_PROBE2_ALLOWED_ABS_ERROR);
    tensor_metrics_init(
        &metrics.logits,
        "intent_logits",
        KT_LOGIT_ALLOWED_ABS_ERROR);
    metrics.minimum_keras_margin = 1.0e30;
    metrics.minimum_cmodel_margin = 1.0e30;
    printf("task=room_device_command_intent_classification "
           "architecture=two_transformer_encoders "
           "fit_method=Keras_model_fit held_out_samples=%u\n",
           (unsigned)KT_TEST_SAMPLES);
    printf("device_images inline_cmd128=yes "
           "weight_addr=0x%llx weight_bytes=%u "
           "commands=%u batches=%u\n",
           (unsigned long long)
               KERAS_TRANSFORMER_MODEL_WEIGHT_BASE_DDR,
           (unsigned)KERAS_TRANSFORMER_MODEL_WEIGHT_BYTES,
           (unsigned)KERAS_TRANSFORMER_MODEL_COMMAND_COUNT,
           (unsigned)KERAS_TRANSFORMER_MODEL_COMMAND_BATCH_COUNT);
    for (binding = 0u;
         binding < KERAS_TRANSFORMER_MODEL_INPUT_COUNT;
         binding++) {
        printf("input_binding index=%u name=%s ddr=0x%llx "
               "bytes=%u shape=[%u,%u,%u]\n",
               (unsigned)binding,
               keras_transformer_model_inputs[binding].name,
               (unsigned long long)
                   keras_transformer_model_inputs[binding].ddr_addr,
               (unsigned)keras_transformer_model_inputs[binding].bytes,
               (unsigned)keras_transformer_model_inputs[binding].shape[0],
               (unsigned)keras_transformer_model_inputs[binding].shape[1],
               (unsigned)keras_transformer_model_inputs[binding].shape[2]);
    }
    for (binding = 0u;
         binding < KERAS_TRANSFORMER_MODEL_OUTPUT_COUNT;
         binding++) {
        printf("output_binding index=%u name=%s ddr=0x%llx "
               "bytes=%u shape=[%u,%u,%u]\n",
               (unsigned)binding,
               keras_transformer_model_outputs[binding].name,
               (unsigned long long)
                   keras_transformer_model_outputs[binding].ddr_addr,
               (unsigned)keras_transformer_model_outputs[binding].bytes,
               (unsigned)keras_transformer_model_outputs[binding].shape[0],
               (unsigned)keras_transformer_model_outputs[binding].shape[1],
               (unsigned)keras_transformer_model_outputs[binding].shape[2]);
    }

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
        CHECK(check_outputs(&driver, sample, &metrics));
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
           "agreement=%u/%u=%.7f "
           "Keras_min_margin=%.7f CModel_min_margin=%.7f\n",
           (unsigned)metrics.cmodel_correct,
           (unsigned)KT_TEST_SAMPLES,
           (double)metrics.cmodel_correct / (double)KT_TEST_SAMPLES,
           (unsigned)metrics.keras_correct,
           (unsigned)KT_TEST_SAMPLES,
           (double)metrics.keras_correct / (double)KT_TEST_SAMPLES,
           (unsigned)metrics.cmodel_matches_keras,
           (unsigned)KT_TEST_SAMPLES,
           (double)metrics.cmodel_matches_keras /
               (double)KT_TEST_SAMPLES,
           metrics.minimum_keras_margin,
           metrics.minimum_cmodel_margin);
    {
        const tensor_metrics_t *sets[3] = {
            &metrics.probe1, &metrics.probe2, &metrics.logits
        };
        uint32_t set_index;

        for (set_index = 0u; set_index < 3u; set_index++) {
            const tensor_metrics_t *set = sets[set_index];

            printf("CModel_vs_Keras tensor=%s exact=%u/%u "
                   "within_%u_lsb=%u/%u max_abs_error_lsb=%u "
                   "mae_lsb=%.7f mse_lsb2=%.7f "
                   "distribution_min=%.7f max=%.7f mean=%.7f "
                   "std=%.7f int8_extreme=%u/%u "
                   "abs_ge_0.95=%u/%u unique_int8=%u\n",
                   set->name,
                   (unsigned)set->exact_count,
                   (unsigned)set->element_count,
                   (unsigned)set->tolerance,
                   (unsigned)set->within_tolerance_count,
                   (unsigned)set->element_count,
                   (unsigned)set->max_abs_error,
                   (double)set->absolute_error_sum /
                       (double)set->element_count,
                   set->squared_error_sum /
                       (double)set->element_count,
                   (double)set->minimum * MODEL_SCALE,
                   (double)set->maximum * MODEL_SCALE,
                   (double)set->value_sum * MODEL_SCALE /
                       (double)set->element_count,
                   tensor_stddev_real(set),
                   (unsigned)set->int8_extreme_count,
                   (unsigned)set->element_count,
                   (unsigned)set->near_limit_count,
                   (unsigned)set->element_count,
                   (unsigned)unique_value_count(set));
        }
    }
    CHECK(metrics.keras_correct == KT_TEST_SAMPLES &&
                  metrics.cmodel_correct == KT_TEST_SAMPLES &&
                  metrics.cmodel_matches_keras == KT_TEST_SAMPLES &&
                  metrics.probe1.within_tolerance_count ==
                      metrics.probe1.element_count &&
                  metrics.probe2.within_tolerance_count ==
                      metrics.probe2.element_count &&
                  metrics.logits.within_tolerance_count ==
                      metrics.logits.element_count &&
                  metrics.probe1.absolute_error_sum <=
                      (uint64_t)metrics.probe1.element_count * 8u &&
                  metrics.probe2.absolute_error_sum <=
                      (uint64_t)metrics.probe2.element_count * 5u &&
                  metrics.logits.absolute_error_sum <=
                      (uint64_t)metrics.logits.element_count * 5u &&
                  metrics.probe1.int8_extreme_count * 100u <=
                      metrics.probe1.element_count &&
                  metrics.probe2.int8_extreme_count * 100u <=
                      metrics.probe2.element_count &&
                  metrics.logits.int8_extreme_count * 100u <=
                      metrics.logits.element_count &&
                  metrics.logits.near_limit_count * 100u <=
                      metrics.logits.element_count * 35u &&
                  unique_value_count(&metrics.probe1) >= 16u &&
                  unique_value_count(&metrics.probe2) >= 16u &&
                  unique_value_count(&metrics.logits) >= 16u &&
                  tensor_stddev_real(&metrics.probe1) >= 0.08 &&
                  tensor_stddev_real(&metrics.probe2) >= 0.08 &&
                  tensor_stddev_real(&metrics.logits) >= 0.08 &&
                  metrics.minimum_cmodel_margin >= 0.10
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
