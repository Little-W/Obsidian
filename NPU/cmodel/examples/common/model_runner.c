#include "cmodel_driver_backend.h"
#include "model_fixture.h"
#include "model_model.h"
#include "npu_driver.h"

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MODEL_DDR_BYTES (2u * 1024u * 1024u)
#define MODEL_L1_BYTES NPU_REF_L1_BYTES
#define MAX_BINDINGS 8u
#define MAX_VECTOR_ELEMENTS 256u

#define CHECK(call)                                                        \
    do {                                                                   \
        int check_result = (call);                                         \
        if (check_result != 0) {                                           \
            (void)fprintf(                                                 \
                stderr,                                                    \
                "failure:%s:%d rc=%d expression=%s\n",                    \
                __FILE__,                                                  \
                __LINE__,                                                  \
                check_result,                                              \
                #call);                                                    \
            return 1;                                                      \
        }                                                                  \
    } while (0)

typedef struct {
    const char *name;
    const int8_t *values;
    size_t elements;
} input_payload_t;

typedef struct {
    uint64_t device_runs;
    uint64_t bursts;
    uint64_t beats;
    uint64_t responses;
    uint64_t cycles;
    uint64_t cache_clean;
    uint64_t cache_invalidate;
} aggregate_stats_t;

typedef struct {
    double squared_target_error;
    double absolute_target_error;
    double squared_framework_error;
    double absolute_framework_error;
    double maximum_framework_error;
    double target_sum;
    double target_square_sum;
    uint64_t count;
} regression_stats_t;

static uint8_t model_l1[MODEL_L1_BYTES];
static uint8_t model_ddr[MODEL_DDR_BYTES];
static npu_example_cmodel_backend_t model_backend;
static aggregate_stats_t aggregate_stats;

static float float_from_bits(uint32_t bits)
{
    float value;

    (void)memcpy(&value, &bits, sizeof(value));
    return value;
}

static float model_scale(void)
{
    return float_from_bits(EXAMPLE_SCALE_F32_BITS);
}

#if EXAMPLE_MODEL_KIND != EXAMPLE_KIND_CNN
static int8_t encode_state(float value)
{
    double encoded = nearbyint((double)value / (double)model_scale());

    if (encoded < -128.0) {
        encoded = -128.0;
    } else if (encoded > 127.0) {
        encoded = 127.0;
    }
    return (int8_t)encoded;
}
#endif

static int address_span_valid(uint64_t address, size_t bytes)
{
    return address <= MODEL_DDR_BYTES &&
           bytes <= MODEL_DDR_BYTES - (size_t)address;
}

static const model_model_binding_t *find_input(const char *name)
{
    uint32_t index;

    for (index = 0u; index < MODEL_MODEL_INPUT_COUNT; index++) {
        if (strcmp(model_model_inputs[index].name, name) == 0) {
            return &model_model_inputs[index];
        }
    }
    return (const model_model_binding_t *)0;
}

static const model_model_binding_t *find_output(const char *name)
{
    uint32_t index;

    for (index = 0u; index < MODEL_MODEL_OUTPUT_COUNT; index++) {
        if (strcmp(model_model_outputs[index].name, name) == 0) {
            return &model_model_outputs[index];
        }
    }
    return (const model_model_binding_t *)0;
}

static int command_for_id(uint16_t command_id, npu_drv_cmd128_t *command)
{
    uint32_t index;

    if (command == (npu_drv_cmd128_t *)0) {
        return -1;
    }
    for (index = 0u; index < MODEL_MODEL_COMMAND_COUNT; index++) {
        npu_drv_cmd_fields_t fields;

        command->lo = model_model_commands[index].low;
        command->hi = model_model_commands[index].high;
        if (npu_drv_cmd128_decode(command, &fields) != NPU_DRV_OK) {
            return -1;
        }
        if (fields.command_id == command_id) {
            return 0;
        }
    }
    return -1;
}

static int initialize_images(const input_payload_t *payloads,
                             size_t payload_count)
{
    size_t payload_index;

    if (payloads == (const input_payload_t *)0 ||
        payload_count != MODEL_MODEL_INPUT_COUNT ||
        payload_count > MAX_BINDINGS ||
        model_model_config.command_format == (const char *)0 ||
        strcmp(model_model_config.command_format,
               "cmd128-inline-v2") != 0 ||
        model_model_config.commands != model_model_commands ||
        model_model_config.command_count != MODEL_MODEL_COMMAND_COUNT ||
        model_model_config.weights != model_model_weights ||
        model_model_config.weight_bytes != MODEL_MODEL_WEIGHT_BYTES ||
        !address_span_valid(
            MODEL_MODEL_WEIGHT_BASE_DDR,
            (size_t)MODEL_MODEL_WEIGHT_BYTES)) {
        return -1;
    }
    (void)memset(model_l1, 0, sizeof(model_l1));
    (void)memset(model_ddr, 0, sizeof(model_ddr));
    (void)memcpy(
        &model_ddr[MODEL_MODEL_WEIGHT_BASE_DDR],
        model_model_weights,
        (size_t)MODEL_MODEL_WEIGHT_BYTES);

    for (payload_index = 0u;
         payload_index < payload_count;
         payload_index++) {
        const input_payload_t *payload = &payloads[payload_index];
        const model_model_binding_t *binding =
            find_input(payload->name);

        if (binding == (const model_model_binding_t *)0 ||
            binding->dtype != NPU_DRV_DTYPE_INT8 ||
            binding->bytes != payload->elements ||
            payload->values == (const int8_t *)0 ||
            !address_span_valid(binding->ddr_addr, binding->bytes)) {
            return -1;
        }
        (void)memcpy(
            &model_ddr[binding->ddr_addr],
            payload->values,
            payload->elements);
    }
    return 0;
}

static int sync_for_device(npu_driver_t *driver,
                           const input_payload_t *payloads,
                           size_t payload_count)
{
    size_t payload_index;

    if (npu_drv_sync_for_device(
            driver,
            &model_ddr[MODEL_MODEL_WEIGHT_BASE_DDR],
            (size_t)MODEL_MODEL_WEIGHT_BYTES) != NPU_DRV_OK) {
        return -1;
    }
    for (payload_index = 0u;
         payload_index < payload_count;
         payload_index++) {
        const model_model_binding_t *binding =
            find_input(payloads[payload_index].name);

        if (binding == (const model_model_binding_t *)0 ||
            npu_drv_sync_for_device(
                driver,
                &model_ddr[binding->ddr_addr],
                binding->bytes) != NPU_DRV_OK) {
            return -1;
        }
    }
    return 0;
}

static int submit_batch(npu_driver_t *driver,
                        uint32_t batch,
                        uint32_t begin,
                        uint32_t end,
                        int verbose)
{
    npu_drv_cmd128_t
        commands[NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    npu_drv_submit_result_t
        results[NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS];
    npu_drv_submit_batch_result_t summary;
    size_t count;
    size_t index;
    int rc;

    if (end < begin || end > MODEL_MODEL_BATCH_COMMAND_ID_COUNT) {
        return -1;
    }
    count = (size_t)(end - begin);
    if (count == 0u ||
        count > NPU_DRV_CMD_FIFO_MAX_BURST_COMMANDS) {
        return -1;
    }
    for (index = 0u; index < count; index++) {
        uint16_t command_id =
            model_model_batch_command_ids[begin + (uint32_t)index];
        if (command_for_id(command_id, &commands[index]) != 0) {
            return -1;
        }
    }
    rc = npu_drv_submit_batch(
        driver,
        commands,
        count,
        results,
        &summary);
    if (verbose != 0) {
        (void)printf(
            "    command_batch[%u]: commands=%u beats=%u "
            "responses=%u rc=%d\n",
            (unsigned)batch,
            (unsigned)count,
            (unsigned)(count * NPU_DRV_CMD128_BEATS),
            (unsigned)summary.responses_received,
            rc);
    }
    if (rc != NPU_DRV_OK ||
        summary.burst_completed == 0u ||
        summary.responses_received != count ||
        summary.first_failed_index != NPU_DRV_NO_FAILED_COMMAND) {
        (void)printf(
            "      batch_error: batch=%u rc=%d "
            "burst_completed=%u "
            "first_failed_index=%u\n",
            (unsigned)batch,
            rc,
            (unsigned)summary.burst_completed,
            summary.first_failed_index == NPU_DRV_NO_FAILED_COMMAND
                ? UINT_MAX
                : (unsigned)summary.first_failed_index);
        for (index = 0u;
             index < summary.responses_received && index < count;
             index++) {
            (void)printf(
                "      response[%u]: command_id=%u status=%u "
                "fifo_free=%u raw=0x%016llx\n",
                (unsigned)index,
                (unsigned)results[index].command_id,
                (unsigned)results[index].status,
                (unsigned)results[index].fifo_free,
                (unsigned long long)results[index].raw);
        }
        return -1;
    }
    for (index = 0u; index < count; index++) {
        if (results[index].status != NPU_STATUS_SUCCESS) {
            return -1;
        }
    }
    return 0;
}

static int wait_and_ack_batch(npu_driver_t *driver,
                              uint32_t begin,
                              uint32_t end)
{
    uint32_t index;

    for (index = begin; index < end; index++) {
        uint16_t command_id = model_model_batch_command_ids[index];
        npu_drv_task_status_t waited;
        npu_drv_task_status_t queried;

        (void)memset(&waited, 0, sizeof(waited));
        (void)memset(&queried, 0, sizeof(queried));
        if (npu_drv_wait_task(
                driver, command_id, 1000000u, &waited) != NPU_DRV_OK ||
            npu_drv_query_status(
                driver, command_id, &queried) != NPU_DRV_OK ||
            waited.state != NPU_DRV_TASK_TERMINAL ||
            queried.state != NPU_DRV_TASK_TERMINAL ||
            waited.status != NPU_STATUS_SUCCESS ||
            queried.status != NPU_STATUS_SUCCESS) {
            return -1;
        }
    }
    for (index = begin; index < end; index++) {
        if (npu_drv_ack_task(
                driver,
                model_model_batch_command_ids[index]) != NPU_DRV_OK) {
            return -1;
        }
    }
    return 0;
}

static int run_batches(npu_driver_t *driver, int verbose)
{
    uint32_t batch;

    if (MODEL_MODEL_BATCH_COMMAND_ID_COUNT !=
        MODEL_MODEL_COMMAND_COUNT) {
        return -1;
    }
    for (batch = 0u;
         batch < MODEL_MODEL_COMMAND_BATCH_COUNT;
         batch++) {
        uint32_t begin =
            model_model_command_batches[batch].command_id_offset;
        uint32_t end =
            begin +
            model_model_command_batches[batch].command_count;

        if (submit_batch(
                driver, batch, begin, end, verbose) != 0 ||
            wait_and_ack_batch(driver, begin, end) != 0) {
            return -1;
        }
    }
    return 0;
}

static int execute_device(const input_payload_t *payloads,
                          size_t payload_count,
                          int verbose)
{
    npu_driver_t driver;
    npu_drv_platform_ops_t operations;
    uint64_t fence_result = 0u;
    uint32_t output_index;

    if (initialize_images(payloads, payload_count) != 0 ||
        npu_example_cmodel_backend_init(
            &model_backend,
            model_l1,
            sizeof(model_l1),
            model_ddr,
            sizeof(model_ddr)) != 0) {
        return -1;
    }
    operations = npu_example_cmodel_backend_operations(&model_backend);
    if (npu_drv_init(&driver, &operations) != NPU_DRV_OK ||
        sync_for_device(&driver, payloads, payload_count) != 0 ||
        run_batches(&driver, verbose) != 0 ||
        npu_drv_fence(&driver, 1000000u, &fence_result) != NPU_DRV_OK) {
        return -1;
    }
    for (output_index = 0u;
         output_index < MODEL_MODEL_OUTPUT_COUNT;
         output_index++) {
        const model_model_binding_t *binding =
            &model_model_outputs[output_index];

        if (binding->dtype != NPU_DRV_DTYPE_INT8 ||
            !address_span_valid(binding->ddr_addr, binding->bytes) ||
            npu_drv_sync_for_cpu(
                &driver,
                &model_ddr[binding->ddr_addr],
                binding->bytes) != NPU_DRV_OK) {
            return -1;
        }
    }
    aggregate_stats.device_runs++;
    aggregate_stats.bursts += model_backend.submitted_bursts;
    aggregate_stats.beats += model_backend.submitted_beats;
    aggregate_stats.responses += model_backend.responses;
    aggregate_stats.cycles += model_backend.model.cycle;
    aggregate_stats.cache_clean += model_backend.cache_clean_calls;
    aggregate_stats.cache_invalidate +=
        model_backend.cache_invalidate_calls;
    if (model_backend.pending_response_count != 0u ||
        model_backend.submitted_bursts !=
            MODEL_MODEL_COMMAND_BATCH_COUNT ||
        model_backend.submitted_beats !=
            MODEL_MODEL_COMMAND_COUNT * NPU_DRV_CMD128_BEATS ||
        model_backend.responses != MODEL_MODEL_COMMAND_COUNT) {
        return -1;
    }
    return 0;
}

static int read_output(const char *name,
                       int8_t *values,
                       size_t elements)
{
    const model_model_binding_t *binding = find_output(name);

    if (binding == (const model_model_binding_t *)0 ||
        values == (int8_t *)0 ||
        binding->dtype != NPU_DRV_DTYPE_INT8 ||
        binding->bytes != elements ||
        elements > MAX_VECTOR_ELEMENTS ||
        !address_span_valid(binding->ddr_addr, binding->bytes)) {
        return -1;
    }
    (void)memcpy(values, &model_ddr[binding->ddr_addr], elements);
    return 0;
}

static void print_float_vector(const char *label,
                               const float *values,
                               uint32_t count)
{
    uint32_t index;

    (void)printf("%s[", label);
    for (index = 0u; index < count; index++) {
        (void)printf(
            "%s%.7f", index == 0u ? "" : ", ", (double)values[index]);
    }
    (void)printf("]\n");
}

static void print_int8_vector(const char *label,
                              const int8_t *values,
                              uint32_t count)
{
    uint32_t index;

    (void)printf("%s[", label);
    for (index = 0u; index < count; index++) {
        (void)printf(
            "%s%d", index == 0u ? "" : ", ", (int)values[index]);
    }
    (void)printf("]\n");
}

#if EXAMPLE_MODEL_KIND != EXAMPLE_KIND_CNN
static void fixture_float_vector(const uint32_t *bits,
                                 float *values,
                                 uint32_t count)
{
    uint32_t index;

    for (index = 0u; index < count; index++) {
        values[index] = float_from_bits(bits[index]);
    }
}

static void update_regression_stats(regression_stats_t *stats,
                                    const float *actual,
                                    const float *target,
                                    const float *framework,
                                    uint32_t count)
{
    uint32_t index;

    for (index = 0u; index < count; index++) {
        double target_error =
            (double)actual[index] - (double)target[index];
        double framework_error =
            (double)actual[index] - (double)framework[index];
        double magnitude = fabs(framework_error);

        stats->squared_target_error += target_error * target_error;
        stats->absolute_target_error += fabs(target_error);
        stats->squared_framework_error +=
            framework_error * framework_error;
        stats->absolute_framework_error += magnitude;
        if (magnitude > stats->maximum_framework_error) {
            stats->maximum_framework_error = magnitude;
        }
        stats->target_sum += target[index];
        stats->target_square_sum +=
            (double)target[index] * (double)target[index];
        stats->count++;
    }
}

static int run_recurrent(void)
{
    regression_stats_t stats;
    uint32_t sample;
    float scale = model_scale();

    (void)memset(&stats, 0, sizeof(stats));
    for (sample = 0u; sample < EXAMPLE_SAMPLE_COUNT; sample++) {
        float hidden[EXAMPLE_OUTPUT_FEATURES];
#if EXAMPLE_MODEL_KIND == EXAMPLE_KIND_LSTM
        float cell[EXAMPLE_OUTPUT_FEATURES];
#endif
        uint32_t step;

        (void)memset(hidden, 0, sizeof(hidden));
#if EXAMPLE_MODEL_KIND == EXAMPLE_KIND_LSTM
        (void)memset(cell, 0, sizeof(cell));
#endif
        (void)printf("sample[%u]\n", (unsigned)sample);
        for (step = 0u; step < EXAMPLE_STEPS; step++) {
            size_t input_offset =
                ((size_t)sample * EXAMPLE_STEPS + step) *
                EXAMPLE_INPUT_FEATURES;
            size_t output_offset =
                ((size_t)sample * EXAMPLE_STEPS + step) *
                EXAMPLE_OUTPUT_FEATURES;
            int8_t hidden_q[EXAMPLE_OUTPUT_FEATURES];
            input_payload_t payloads[2];
            float input_f[EXAMPLE_INPUT_FEATURES];
            float target[EXAMPLE_OUTPUT_FEATURES];
            float framework[EXAMPLE_OUTPUT_FEATURES];
            float actual[EXAMPLE_OUTPUT_FEATURES];
            uint32_t feature;

            for (feature = 0u;
                 feature < EXAMPLE_OUTPUT_FEATURES;
                 feature++) {
                hidden_q[feature] = encode_state(hidden[feature]);
            }
            payloads[0].name = "x";
            payloads[0].values = &example_input_int8[input_offset];
            payloads[0].elements = EXAMPLE_INPUT_FEATURES;
            payloads[1].name = "h_prev";
            payloads[1].values = hidden_q;
            payloads[1].elements = EXAMPLE_OUTPUT_FEATURES;
            (void)printf(
                "  time_step[%u] device execution\n",
                (unsigned)step);
            if (execute_device(
                    payloads,
                    2u,
                    sample == 0u && step == 0u) != 0) {
                return -1;
            }

#if EXAMPLE_MODEL_KIND == EXAMPLE_KIND_RNN
            {
                int8_t h_q[EXAMPLE_OUTPUT_FEATURES];

                if (read_output(
                        "h",
                        h_q,
                        EXAMPLE_OUTPUT_FEATURES) != 0) {
                    return -1;
                }
                for (feature = 0u;
                     feature < EXAMPLE_OUTPUT_FEATURES;
                     feature++) {
                    hidden[feature] = (float)h_q[feature] * scale;
                    actual[feature] = hidden[feature];
                }
                print_int8_vector(
                    "    CModel_hidden_INT8:    ",
                    h_q,
                    EXAMPLE_OUTPUT_FEATURES);
            }
#elif EXAMPLE_MODEL_KIND == EXAMPLE_KIND_GRU
            {
                int8_t z_q[EXAMPLE_OUTPUT_FEATURES];
                int8_t r_q[EXAMPLE_OUTPUT_FEATURES];
                int8_t xh_q[EXAMPLE_OUTPUT_FEATURES];
                int8_t rh_q[EXAMPLE_OUTPUT_FEATURES];

                if (read_output(
                        "z", z_q, EXAMPLE_OUTPUT_FEATURES) != 0 ||
                    read_output(
                        "r", r_q, EXAMPLE_OUTPUT_FEATURES) != 0 ||
                    read_output(
                        "x_h_biased",
                        xh_q,
                        EXAMPLE_OUTPUT_FEATURES) != 0 ||
                    read_output(
                        "recurrent_h_biased",
                        rh_q,
                        EXAMPLE_OUTPUT_FEATURES) != 0) {
                    return -1;
                }
                print_int8_vector(
                    "    CModel_update_gate_INT8: ",
                    z_q,
                    EXAMPLE_OUTPUT_FEATURES);
                print_int8_vector(
                    "    CModel_reset_gate_INT8:  ",
                    r_q,
                    EXAMPLE_OUTPUT_FEATURES);
                for (feature = 0u;
                     feature < EXAMPLE_OUTPUT_FEATURES;
                     feature++) {
                    float z = (float)z_q[feature] * scale;
                    float r = (float)r_q[feature] * scale;
                    float candidate = tanhf(
                        (float)xh_q[feature] * scale +
                        r * (float)rh_q[feature] * scale);
                    hidden[feature] =
                        z * hidden[feature] + (1.0f - z) * candidate;
                    actual[feature] = hidden[feature];
                }
            }
#elif EXAMPLE_MODEL_KIND == EXAMPLE_KIND_LSTM
            {
                int8_t i_q[EXAMPLE_OUTPUT_FEATURES];
                int8_t f_q[EXAMPLE_OUTPUT_FEATURES];
                int8_t g_q[EXAMPLE_OUTPUT_FEATURES];
                int8_t o_q[EXAMPLE_OUTPUT_FEATURES];

                if (read_output(
                        "i", i_q, EXAMPLE_OUTPUT_FEATURES) != 0 ||
                    read_output(
                        "f", f_q, EXAMPLE_OUTPUT_FEATURES) != 0 ||
                    read_output(
                        "g", g_q, EXAMPLE_OUTPUT_FEATURES) != 0 ||
                    read_output(
                        "o", o_q, EXAMPLE_OUTPUT_FEATURES) != 0) {
                    return -1;
                }
                print_int8_vector(
                    "    CModel_input_gate_INT8:  ",
                    i_q,
                    EXAMPLE_OUTPUT_FEATURES);
                print_int8_vector(
                    "    CModel_forget_gate_INT8: ",
                    f_q,
                    EXAMPLE_OUTPUT_FEATURES);
                print_int8_vector(
                    "    CModel_output_gate_INT8: ",
                    o_q,
                    EXAMPLE_OUTPUT_FEATURES);
                for (feature = 0u;
                     feature < EXAMPLE_OUTPUT_FEATURES;
                     feature++) {
                    float input_gate = (float)i_q[feature] * scale;
                    float forget_gate = (float)f_q[feature] * scale;
                    float candidate = (float)g_q[feature] * scale;
                    float output_gate = (float)o_q[feature] * scale;

                    cell[feature] =
                        forget_gate * cell[feature] +
                        input_gate * candidate;
                    hidden[feature] =
                        output_gate * tanhf(cell[feature]);
                    actual[feature] = hidden[feature];
                }
            }
#else
#error "run_recurrent requires an RNN, GRU, or LSTM fixture"
#endif

            fixture_float_vector(
                &example_input_f32_bits[input_offset],
                input_f,
                EXAMPLE_INPUT_FEATURES);
            fixture_float_vector(
                &example_target_f32_bits[output_offset],
                target,
                EXAMPLE_OUTPUT_FEATURES);
            fixture_float_vector(
                &example_keras_output_f32_bits[output_offset],
                framework,
                EXAMPLE_OUTPUT_FEATURES);
            print_float_vector(
                "    input:             ",
                input_f,
                EXAMPLE_INPUT_FEATURES);
            print_float_vector(
                "    target:            ",
                target,
                EXAMPLE_OUTPUT_FEATURES);
            print_float_vector(
                "    Keras_reference:   ",
                framework,
                EXAMPLE_OUTPUT_FEATURES);
            print_float_vector(
                "    CModel_prediction: ",
                actual,
                EXAMPLE_OUTPUT_FEATURES);
            update_regression_stats(
                &stats,
                actual,
                target,
                framework,
                EXAMPLE_OUTPUT_FEATURES);
        }
    }
    if (stats.count == 0u) {
        return -1;
    }
    {
        double mse = stats.squared_target_error / (double)stats.count;
        double rmse = sqrt(mse);
        double mae = stats.absolute_target_error / (double)stats.count;
        double framework_mse =
            stats.squared_framework_error / (double)stats.count;
        double framework_mae =
            stats.absolute_framework_error / (double)stats.count;
        double target_mean = stats.target_sum / (double)stats.count;
        double total_variation =
            stats.target_square_sum -
            2.0 * target_mean * stats.target_sum +
            (double)stats.count * target_mean * target_mean;
        double r_squared =
            total_variation > 0.0
                ? 1.0 - stats.squared_target_error / total_variation
                : 0.0;
        double limit =
            (double)float_from_bits(
                EXAMPLE_C_MSE_LIMIT_F32_BITS);

        (void)printf(
            "regression_metrics: MSE=%.9g RMSE=%.9g "
            "MAE=%.9g R_squared=%.9g\n",
            mse,
            rmse,
            mae,
            r_squared);
        (void)printf(
            "CModel_vs_Keras: MSE=%.9g MAE=%.9g "
            "max_abs_error=%.9g\n",
            framework_mse,
            framework_mae,
            stats.maximum_framework_error);
        (void)printf(
            "Keras_training: initial_MSE=%.9g final_MSE=%.9g "
            "fixed_MSE=%.9g CModel_MSE_limit=%.9g\n",
            (double)float_from_bits(
                EXAMPLE_TRAIN_INITIAL_F32_BITS),
            (double)float_from_bits(
                EXAMPLE_TRAIN_FINAL_F32_BITS),
            (double)float_from_bits(
                EXAMPLE_FRAMEWORK_METRIC_F32_BITS),
            limit);
        if (!isfinite(mse) || mse > limit ||
            !isfinite(framework_mse) ||
            stats.maximum_framework_error > 0.55) {
            return -1;
        }
    }
    return 0;
}
#endif

#if EXAMPLE_MODEL_KIND == EXAMPLE_KIND_CNN
static const char *class_name(uint32_t class_id)
{
    if (class_id == 0u) {
        return "vertical_scratch";
    }
    if (class_id == 1u) {
        return "horizontal_scratch";
    }
    if (class_id == 2u) {
        return "diagonal_scratch";
    }
    return "unknown";
}

static uint32_t maximum_index(const float *values, uint32_t count)
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

static int run_cnn(void)
{
    const model_model_binding_t *input_binding =
        &model_model_inputs[0];
    const model_model_binding_t *output_binding =
        &model_model_outputs[0];
    uint32_t sample;
    uint32_t c_correct = 0u;
    uint32_t keras_correct = 0u;
    uint32_t agreement = 0u;
    double squared_error = 0.0;
    double absolute_error = 0.0;
    double max_abs_error = 0.0;
    uint64_t count = 0u;
    float scale = model_scale();

    if (MODEL_MODEL_INPUT_COUNT != 1u ||
        MODEL_MODEL_OUTPUT_COUNT != 1u ||
        input_binding->dtype != NPU_DRV_DTYPE_INT8 ||
        output_binding->dtype != NPU_DRV_DTYPE_INT8 ||
        input_binding->bytes !=
            EXAMPLE_INPUT_FEATURES * sizeof(int8_t) ||
        output_binding->bytes !=
            EXAMPLE_OUTPUT_FEATURES * sizeof(int8_t)) {
        return -1;
    }
    (void)printf(
        "cnn_device_images: inline_cmd128=yes "
        "weight_addr=0x%llx weight_bytes=%u "
        "input_addr=0x%llx input_bytes=%u "
        "output_addr=0x%llx output_bytes=%u\n",
        (unsigned long long)MODEL_MODEL_WEIGHT_BASE_DDR,
        (unsigned)MODEL_MODEL_WEIGHT_BYTES,
        (unsigned long long)input_binding->ddr_addr,
        (unsigned)input_binding->bytes,
        (unsigned long long)output_binding->ddr_addr,
        (unsigned)output_binding->bytes);
    for (sample = 0u; sample < EXAMPLE_SAMPLE_COUNT; sample++) {
        size_t input_offset =
            (size_t)sample * EXAMPLE_INPUT_FEATURES;
        size_t output_offset =
            (size_t)sample * EXAMPLE_OUTPUT_FEATURES;
        input_payload_t payload;
        int8_t output_q[EXAMPLE_OUTPUT_FEATURES];
        float output[EXAMPLE_OUTPUT_FEATURES];
        float framework[EXAMPLE_OUTPUT_FEATURES];
        uint32_t row;
        uint32_t feature;
        uint32_t cmodel_class;
        uint32_t keras_class;
        uint32_t label = example_label[sample];

        payload.name = input_binding->name;
        payload.values = &example_input_int8[input_offset];
        payload.elements = EXAMPLE_INPUT_FEATURES;
        (void)printf(
            "sample[%u] reference_class=%u (%s) device execution\n",
            (unsigned)sample,
            (unsigned)label,
            class_name(label));
        if (execute_device(
                &payload, 1u, sample == 0u) != 0 ||
            read_output(
                output_binding->name,
                output_q,
                EXAMPLE_OUTPUT_FEATURES) != 0) {
            return -1;
        }
        (void)printf("  input_image_float:\n");
        for (row = 0u; row < EXAMPLE_IMAGE_HEIGHT; row++) {
            float pixels[EXAMPLE_IMAGE_WIDTH];
            uint32_t column;

            for (column = 0u;
                 column < EXAMPLE_IMAGE_WIDTH;
                 column++) {
                size_t pixel =
                    input_offset +
                    (size_t)row * EXAMPLE_IMAGE_WIDTH +
                    column;
                pixels[column] =
                    float_from_bits(example_input_f32_bits[pixel]);
            }
            print_float_vector(
                "    ",
                pixels,
                EXAMPLE_IMAGE_WIDTH);
        }
        for (feature = 0u;
             feature < EXAMPLE_OUTPUT_FEATURES;
             feature++) {
            double difference;
            double magnitude;

            output[feature] = (float)output_q[feature] * scale;
            framework[feature] = float_from_bits(
                example_keras_output_f32_bits[
                    output_offset + feature]);
            difference =
                (double)output[feature] - (double)framework[feature];
            magnitude = fabs(difference);
            squared_error += difference * difference;
            absolute_error += magnitude;
            if (magnitude > max_abs_error) {
                max_abs_error = magnitude;
            }
            count++;
        }
        cmodel_class = maximum_index(
            output, EXAMPLE_OUTPUT_FEATURES);
        keras_class = maximum_index(
            framework, EXAMPLE_OUTPUT_FEATURES);
        if (cmodel_class == label) {
            c_correct++;
        }
        if (keras_class == label) {
            keras_correct++;
        }
        if (cmodel_class == keras_class) {
            agreement++;
        }
        print_int8_vector(
            "  CModel_logits_INT8: ",
            output_q,
            EXAMPLE_OUTPUT_FEATURES);
        print_float_vector(
            "  CModel_logits:      ",
            output,
            EXAMPLE_OUTPUT_FEATURES);
        print_float_vector(
            "  Keras_reference:   ",
            framework,
            EXAMPLE_OUTPUT_FEATURES);
        (void)printf(
            "  CModel_prediction_class=%u (%s) "
            "Keras_reference_class=%u (%s) "
            "CModel_correct=%s Keras_correct=%s "
            "CModel_matches_Keras=%s\n",
            (unsigned)cmodel_class,
            class_name(cmodel_class),
            (unsigned)keras_class,
            class_name(keras_class),
            cmodel_class == label ? "yes" : "no",
            keras_class == label ? "yes" : "no",
            cmodel_class == keras_class ? "yes" : "no");
    }
    if (count == 0u) {
        return -1;
    }
    (void)printf(
        "classification_metrics: CModel_accuracy=%u/%u=%.7f "
        "Keras_accuracy=%u/%u=%.7f agreement=%u/%u=%.7f\n",
        (unsigned)c_correct,
        (unsigned)EXAMPLE_SAMPLE_COUNT,
        (double)c_correct / (double)EXAMPLE_SAMPLE_COUNT,
        (unsigned)keras_correct,
        (unsigned)EXAMPLE_SAMPLE_COUNT,
        (double)keras_correct / (double)EXAMPLE_SAMPLE_COUNT,
        (unsigned)agreement,
        (unsigned)EXAMPLE_SAMPLE_COUNT,
        (double)agreement / (double)EXAMPLE_SAMPLE_COUNT);
    (void)printf(
        "CModel_vs_Keras: MSE=%.9g MAE=%.9g max_abs_error=%.9g\n",
        squared_error / (double)count,
        absolute_error / (double)count,
        max_abs_error);
    (void)printf(
        "Keras_training: initial_loss=%.9g final_loss=%.9g "
        "fixed_accuracy=%.7f\n",
        (double)float_from_bits(EXAMPLE_TRAIN_INITIAL_F32_BITS),
        (double)float_from_bits(EXAMPLE_TRAIN_FINAL_F32_BITS),
        (double)float_from_bits(
            EXAMPLE_FRAMEWORK_METRIC_F32_BITS));
    return c_correct >= EXAMPLE_CLASSIFICATION_MIN_CORRECT &&
                   keras_correct == EXAMPLE_SAMPLE_COUNT &&
                   agreement == EXAMPLE_SAMPLE_COUNT &&
                   max_abs_error <= 0.80
               ? 0
               : -1;
}
#endif

int main(void)
{
    int result;

    (void)memset(&aggregate_stats, 0, sizeof(aggregate_stats));
    (void)printf(
        "=== Keras %s -> model compiler -> C driver -> CModel ===\n",
        EXAMPLE_MODEL_NAME);
    (void)printf(
        "tensor_format=INT8 Q%u accumulator=INT32 "
        "complex_math=INT8->FP32->INT8 commands=%u batches=%u\n",
        (unsigned)EXAMPLE_FRACTION_BITS,
        (unsigned)MODEL_MODEL_COMMAND_COUNT,
        (unsigned)MODEL_MODEL_COMMAND_BATCH_COUNT);
#if EXAMPLE_MODEL_KIND == EXAMPLE_KIND_CNN
    result = run_cnn();
#else
    result = run_recurrent();
#endif
    if (result != 0) {
        return 1;
    }
    (void)printf(
        "driver_metrics: device_runs=%llu bursts=%llu beats=%llu "
        "responses=%llu cycles=%llu cache_clean=%llu "
        "cache_invalidate=%llu\n",
        (unsigned long long)aggregate_stats.device_runs,
        (unsigned long long)aggregate_stats.bursts,
        (unsigned long long)aggregate_stats.beats,
        (unsigned long long)aggregate_stats.responses,
        (unsigned long long)aggregate_stats.cycles,
        (unsigned long long)aggregate_stats.cache_clean,
        (unsigned long long)aggregate_stats.cache_invalidate);
    (void)printf(
        "PASS model=%s C_package=%s commands=%u batches=%u\n",
        EXAMPLE_MODEL_NAME,
        model_model_config.model_name,
        (unsigned)MODEL_MODEL_COMMAND_COUNT,
        (unsigned)MODEL_MODEL_COMMAND_BATCH_COUNT);
    return 0;
}
