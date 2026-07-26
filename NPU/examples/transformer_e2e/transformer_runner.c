#include "cmodel_driver_backend.h"
#include "transformer_model.npu.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MODEL_DDR_BYTES (2u * 1024u * 1024u)
#define MODEL_L1_BYTES NPU_REF_L1_BYTES
#define MODEL_TOKENS 4u
#define MODEL_WIDTH 8u
#define MODEL_HEADS 2u
#define MODEL_HEAD_WIDTH 4u
#define MODEL_FFN_WIDTH 16u

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

static const int16_t test_input[MODEL_TOKENS][MODEL_WIDTH] = {
    {4, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 4, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 4}
};

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

static uint64_t get_u64(const unsigned char *bytes)
{
    uint64_t value = 0u;
    uint32_t byte;

    for (byte = 0u; byte < 8u; byte++) {
        value |= (uint64_t)bytes[byte] << (byte * 8u);
    }
    return value;
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

static const transformer_model_operation_t *
operation_for_command(uint16_t command_id)
{
    uint32_t index;

    for (index = 0u; index < TRANSFORMER_MODEL_COMMAND_COUNT; index++) {
        if (transformer_model_operations[index].command_id == command_id) {
            return &transformer_model_operations[index];
        }
    }
    return (const transformer_model_operation_t *)0;
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
    for (index = 0u; index < TRANSFORMER_MODEL_COMMAND_COUNT; index++) {
        const unsigned char *wire =
            &transformer_model_commands[index * NPU_DRV_CMD128_BYTES];

        command->lo = get_u64(&wire[0]);
        command->hi = get_u64(&wire[8]);
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
    const transformer_model_binding_t *input;
    uint32_t token;
    uint32_t feature;

    if (TRANSFORMER_MODEL_INPUT_COUNT != 1u ||
        TRANSFORMER_MODEL_OUTPUT_COUNT != 1u ||
        transformer_model_commands_bytes !=
            (unsigned long)TRANSFORMER_MODEL_COMMAND_COUNT *
                NPU_DRV_CMD128_BYTES) {
        return -1;
    }
    if (!address_span_valid(
            TRANSFORMER_MODEL_DESCRIPTOR_BASE,
            (size_t)transformer_model_descriptors_bytes) ||
        !address_span_valid(
            TRANSFORMER_MODEL_CONSTANT_BASE_DDR,
            (size_t)transformer_model_constants_bytes)) {
        return -1;
    }
    input = &transformer_model_inputs[0];
    if (input->dtype != NPU_DRV_DTYPE_INT16 ||
        input->rank != 2u ||
        input->shape[0] != MODEL_TOKENS ||
        input->shape[1] != MODEL_WIDTH ||
        input->bytes != MODEL_TOKENS * MODEL_WIDTH * sizeof(int16_t) ||
        !address_span_valid(input->ddr_addr, input->bytes)) {
        return -1;
    }

    (void)memset(model_l1, 0, sizeof(model_l1));
    (void)memset(model_ddr, 0, sizeof(model_ddr));
    (void)memcpy(
        &model_ddr[TRANSFORMER_MODEL_DESCRIPTOR_BASE],
        transformer_model_descriptors,
        (size_t)transformer_model_descriptors_bytes);
    (void)memcpy(
        &model_ddr[TRANSFORMER_MODEL_CONSTANT_BASE_DDR],
        transformer_model_constants,
        (size_t)transformer_model_constants_bytes);
    for (token = 0u; token < MODEL_TOKENS; token++) {
        for (feature = 0u; feature < MODEL_WIDTH; feature++) {
            put_i16(model_ddr,
                    (size_t)input->ddr_addr +
                        ((size_t)token * MODEL_WIDTH + feature) *
                            sizeof(int16_t),
                    test_input[token][feature]);
        }
    }
    return 0;
}

static int sync_device_images(npu_driver_t *driver)
{
    const transformer_model_binding_t *input =
        &transformer_model_inputs[0];

    if (npu_drv_sync_for_device(
            driver,
            &model_ddr[TRANSFORMER_MODEL_DESCRIPTOR_BASE],
            (size_t)transformer_model_descriptors_bytes) != NPU_DRV_OK ||
        npu_drv_sync_for_device(
            driver,
            &model_ddr[TRANSFORMER_MODEL_CONSTANT_BASE_DDR],
            (size_t)transformer_model_constants_bytes) != NPU_DRV_OK ||
        npu_drv_sync_for_device(
            driver,
            &model_ddr[input->ddr_addr],
            input->bytes) != NPU_DRV_OK) {
        return -1;
    }
    return 0;
}

static int submit_command(npu_driver_t *driver,
                          uint32_t batch,
                          uint16_t command_id)
{
    const transformer_model_operation_t *operation =
        operation_for_command(command_id);
    npu_drv_cmd128_t command;
    npu_drv_cmd_fields_t fields;
    npu_drv_submit_result_t result;
    uint64_t descriptor_offset;
    size_t descriptor_bytes;
    char wait0[24];
    char wait1[24];
    char signal[24];
    int rc;

    if (operation == (const transformer_model_operation_t *)0 ||
        command_for_id(command_id, &command, &fields) != 0 ||
        fields.descriptor_addr < TRANSFORMER_MODEL_DESCRIPTOR_BASE) {
        return -1;
    }
    descriptor_offset =
        fields.descriptor_addr - TRANSFORMER_MODEL_DESCRIPTOR_BASE;
    descriptor_bytes = descriptor_bytes_for_engine(fields.engine);
    if (descriptor_bytes == 0u ||
        descriptor_offset >
            (uint64_t)transformer_model_descriptors_bytes ||
        descriptor_bytes >
            (size_t)transformer_model_descriptors_bytes -
                (size_t)descriptor_offset ||
        !address_span_valid(fields.descriptor_addr, descriptor_bytes)) {
        return -1;
    }
    rc = npu_drv_submit(
        driver,
        &command,
        &model_ddr[fields.descriptor_addr],
        descriptor_bytes,
        &result);
    event_text(fields.wait_event[0], wait0, sizeof(wait0));
    event_text(fields.wait_event[1], wait1, sizeof(wait1));
    event_text(fields.signal_event, signal, sizeof(signal));
    printf("submit batch=%u op=%s node=%s command_id=%u "
           "wait=[%s,%s] signal=%s accepted_status=%u rc=%d\n",
           (unsigned)batch,
           operation->name,
           operation->high_level_node,
           (unsigned)fields.command_id,
           wait0,
           wait1,
           signal,
           (unsigned)result.status,
           rc);
    return rc == NPU_DRV_OK && result.status == 0u ? 0 : -1;
}

static int wait_query_batch(npu_driver_t *driver, uint32_t batch)
{
    uint16_t begin = transformer_model_batch_offsets[batch];
    uint16_t end = transformer_model_batch_offsets[batch + 1u];
    uint16_t index;

    for (index = begin; index < end; index++) {
        uint16_t command_id =
            transformer_model_batch_command_ids[index];
        const transformer_model_operation_t *operation =
            operation_for_command(command_id);
        npu_drv_task_status_t waited;
        npu_drv_task_status_t queried;
        uint64_t progress = 0u;
        int rc;

        if (operation == (const transformer_model_operation_t *)0) {
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
            transformer_model_batch_command_ids[index];
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

    if (transformer_model_batch_offsets[0] != 0u ||
        transformer_model_batch_offsets[TRANSFORMER_MODEL_BATCH_COUNT] !=
            TRANSFORMER_MODEL_COMMAND_COUNT) {
        return -1;
    }
    for (batch = 0u; batch < TRANSFORMER_MODEL_BATCH_COUNT; batch++) {
        uint16_t begin = transformer_model_batch_offsets[batch];
        uint16_t end = transformer_model_batch_offsets[batch + 1u];
        uint16_t index;

        printf("batch begin=%u index=%u commands=%u\n",
               (unsigned)batch,
               (unsigned)begin,
               (unsigned)(end - begin));
        for (index = begin; index < end; index++) {
            if (submit_command(
                    driver,
                    batch,
                    transformer_model_batch_command_ids[index]) != 0) {
                return -1;
            }
        }
        if (wait_query_batch(driver, batch) != 0) {
            return -1;
        }
    }
    return 0;
}

static int16_t reference_round(float value)
{
    float rounded = nearbyintf(value);

    if (rounded > 32767.0f) {
        return 32767;
    }
    if (rounded < -32768.0f) {
        return -32768;
    }
    return (int16_t)rounded;
}

static void reference_norm(
    int16_t input[MODEL_TOKENS][MODEL_WIDTH],
    float epsilon,
    int16_t gamma,
    int16_t beta,
    int16_t output[MODEL_TOKENS][MODEL_WIDTH])
{
    uint32_t token;
    uint32_t feature;

    for (token = 0u; token < MODEL_TOKENS; token++) {
        float mean = 0.0f;
        float variance = 0.0f;

        for (feature = 0u; feature < MODEL_WIDTH; feature++) {
            mean += (float)input[token][feature];
        }
        mean /= (float)MODEL_WIDTH;
        for (feature = 0u; feature < MODEL_WIDTH; feature++) {
            float delta = (float)input[token][feature] - mean;
            variance += delta * delta;
        }
        variance /= (float)MODEL_WIDTH;
        for (feature = 0u; feature < MODEL_WIDTH; feature++) {
            float normalized =
                ((float)input[token][feature] - mean) /
                sqrtf(variance + epsilon);
            output[token][feature] =
                reference_round(
                    normalized * (float)gamma + (float)beta);
        }
    }
}

static void reference_transformer(
    int16_t output[MODEL_TOKENS][MODEL_WIDTH])
{
    int16_t attention[MODEL_TOKENS][MODEL_WIDTH] = {{0}};
    int16_t residual1[MODEL_TOKENS][MODEL_WIDTH] = {{0}};
    int16_t norm1[MODEL_TOKENS][MODEL_WIDTH] = {{0}};
    int16_t hidden[MODEL_TOKENS][MODEL_FFN_WIDTH] = {{0}};
    int16_t activated[MODEL_TOKENS][MODEL_FFN_WIDTH] = {{0}};
    int16_t ffn_output[MODEL_TOKENS][MODEL_WIDTH] = {{0}};
    int16_t residual2[MODEL_TOKENS][MODEL_WIDTH] = {{0}};
    uint32_t head;
    uint32_t query;
    uint32_t key;
    uint32_t feature;

    for (head = 0u; head < MODEL_HEADS; head++) {
        for (query = 0u; query < MODEL_TOKENS; query++) {
            int32_t scores[MODEL_TOKENS] = {0};
            int16_t probabilities[MODEL_TOKENS] = {0};
            float maximum;
            float sum = 0.0f;

            for (key = 0u; key < MODEL_TOKENS; key++) {
                for (feature = 0u;
                     feature < MODEL_HEAD_WIDTH;
                     feature++) {
                    uint32_t channel =
                        head * MODEL_HEAD_WIDTH + feature;
                    scores[key] +=
                        test_input[query][channel] *
                        test_input[key][channel];
                }
            }
            maximum = (float)scores[0];
            for (key = 1u; key < MODEL_TOKENS; key++) {
                if ((float)scores[key] > maximum) {
                    maximum = (float)scores[key];
                }
            }
            for (key = 0u; key < MODEL_TOKENS; key++) {
                float clipped = (float)scores[key];
                if (clipped < -16.0f) {
                    clipped = -16.0f;
                }
                if (clipped > 16.0f) {
                    clipped = 16.0f;
                }
                sum += expf(clipped - maximum);
            }
            for (key = 0u; key < MODEL_TOKENS; key++) {
                float clipped = (float)scores[key];
                float probability;

                if (clipped < -16.0f) {
                    clipped = -16.0f;
                }
                if (clipped > 16.0f) {
                    clipped = 16.0f;
                }
                probability = expf(clipped - maximum) / sum;
                probabilities[key] =
                    reference_round(probability / 0.25f);
            }
            for (feature = 0u;
                 feature < MODEL_HEAD_WIDTH;
                 feature++) {
                int32_t weighted = 0;
                uint32_t channel =
                    head * MODEL_HEAD_WIDTH + feature;

                for (key = 0u; key < MODEL_TOKENS; key++) {
                    weighted +=
                        probabilities[key] *
                        test_input[key][channel];
                }
                attention[query][channel] =
                    reference_round((float)weighted / 4.0f);
            }
        }
    }

    for (query = 0u; query < MODEL_TOKENS; query++) {
        for (feature = 0u; feature < MODEL_WIDTH; feature++) {
            residual1[query][feature] =
                (int16_t)(attention[query][feature] +
                          test_input[query][feature]);
        }
    }
    reference_norm(residual1, 0.5625f, 4, 1, norm1);

    for (query = 0u; query < MODEL_TOKENS; query++) {
        for (feature = 0u; feature < MODEL_WIDTH; feature++) {
            float positive;
            float negative;

            hidden[query][feature] = norm1[query][feature];
            hidden[query][feature + MODEL_WIDTH] =
                (int16_t)-norm1[query][feature];
            positive =
                0.5f * (float)hidden[query][feature] *
                (1.0f + erff(
                    (float)hidden[query][feature] / sqrtf(2.0f)));
            negative =
                0.5f *
                (float)hidden[query][feature + MODEL_WIDTH] *
                (1.0f + erff(
                    (float)hidden[query][feature + MODEL_WIDTH] /
                    sqrtf(2.0f)));
            activated[query][feature] = reference_round(positive);
            activated[query][feature + MODEL_WIDTH] =
                reference_round(negative);
            ffn_output[query][feature] =
                (int16_t)(activated[query][feature] +
                          activated[query][feature + MODEL_WIDTH]);
            residual2[query][feature] =
                (int16_t)(ffn_output[query][feature] +
                          norm1[query][feature]);
        }
    }
    reference_norm(residual2, 8.0f, 3, 1, output);
}

static uint32_t vector_class(const int16_t values[MODEL_WIDTH])
{
    uint32_t feature;
    uint32_t best = 0u;

    for (feature = 1u; feature < MODEL_WIDTH; feature++) {
        if (values[feature] > values[best]) {
            best = feature;
        }
    }
    return best;
}

static int check_output(npu_driver_t *driver)
{
    const transformer_model_binding_t *output_binding =
        &transformer_model_outputs[0];
    int16_t expected[MODEL_TOKENS][MODEL_WIDTH] = {{0}};
    int16_t actual[MODEL_TOKENS][MODEL_WIDTH] = {{0}};
    uint32_t exact = 0u;
    uint32_t class_correct = 0u;
    uint32_t max_abs_error = 0u;
    uint32_t token;
    uint32_t feature;

    if (output_binding->dtype != NPU_DRV_DTYPE_INT16 ||
        output_binding->rank != 2u ||
        output_binding->shape[0] != MODEL_TOKENS ||
        output_binding->shape[1] != MODEL_WIDTH ||
        output_binding->bytes !=
            MODEL_TOKENS * MODEL_WIDTH * sizeof(int16_t) ||
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
    reference_transformer(expected);
    for (token = 0u; token < MODEL_TOKENS; token++) {
        uint32_t expected_class;
        uint32_t actual_class;

        printf("input token=%u values=[", (unsigned)token);
        for (feature = 0u; feature < MODEL_WIDTH; feature++) {
            printf("%s%d",
                   feature == 0u ? "" : ",",
                   (int)test_input[token][feature]);
        }
        printf("]\n");
        printf("output token=%u actual=[", (unsigned)token);
        for (feature = 0u; feature < MODEL_WIDTH; feature++) {
            int32_t delta;
            uint32_t magnitude;

            actual[token][feature] = get_i16(
                model_ddr,
                (size_t)output_binding->ddr_addr +
                    ((size_t)token * MODEL_WIDTH + feature) *
                        sizeof(int16_t));
            delta =
                (int32_t)actual[token][feature] -
                (int32_t)expected[token][feature];
            magnitude = (uint32_t)(delta < 0 ? -delta : delta);
            if (magnitude == 0u) {
                exact++;
            }
            if (magnitude > max_abs_error) {
                max_abs_error = magnitude;
            }
            printf("%s%d",
                   feature == 0u ? "" : ",",
                   (int)actual[token][feature]);
        }
        printf("] expected=[");
        for (feature = 0u; feature < MODEL_WIDTH; feature++) {
            printf("%s%d",
                   feature == 0u ? "" : ",",
                   (int)expected[token][feature]);
        }
        expected_class = vector_class(expected[token]);
        actual_class = vector_class(actual[token]);
        if (expected_class == actual_class) {
            class_correct++;
        }
        printf("] expected_class=%u actual_class=%u\n",
               (unsigned)expected_class,
               (unsigned)actual_class);
    }
    printf("metrics exact_elements=%u/%u max_abs_error=%u "
           "class_accuracy=%u/%u\n",
           (unsigned)exact,
           (unsigned)(MODEL_TOKENS * MODEL_WIDTH),
           (unsigned)max_abs_error,
           (unsigned)class_correct,
           (unsigned)MODEL_TOKENS);
    return exact == MODEL_TOKENS * MODEL_WIDTH &&
                   class_correct == MODEL_TOKENS
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

    printf("PASS model=int16_transformer_encoder high_ops=8 "
           "commands=%u cmd_bits=128 batches=%u "
           "submitted_beats=%u responses=%u cycles=%llu "
           "cache_clean=%u cache_invalidate=%u\n",
           TRANSFORMER_MODEL_COMMAND_COUNT,
           TRANSFORMER_MODEL_BATCH_COUNT,
           (unsigned)model_backend.submitted_beats,
           (unsigned)model_backend.responses,
           (unsigned long long)model_backend.model.cycle,
           (unsigned)model_backend.cache_clean_calls,
           (unsigned)model_backend.cache_invalidate_calls);
    return 0;
}
