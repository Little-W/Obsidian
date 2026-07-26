#include "cmodel_driver_backend.h"
#include "transformer_block.npu.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MODEL_COMMAND_COUNT 30u
#define MODEL_DESCRIPTOR_BASE UINT64_C(0x10000)
#define MODEL_DDR_BYTES (512u * 1024u)
#define MODEL_L1_BYTES NPU_REF_L1_BYTES

#define ADDR_DDR_INPUT 0x20000u
#define ADDR_DDR_WEIGHT_Q 0x20200u
#define ADDR_DDR_WEIGHT_K 0x20400u
#define ADDR_DDR_WEIGHT_V 0x20600u
#define ADDR_DDR_WEIGHT_O 0x20800u
#define ADDR_DDR_WEIGHT_FFN1 0x20a00u
#define ADDR_DDR_WEIGHT_FFN2 0x20c00u
#define ADDR_DDR_PARAMETERS 0x21000u

#define ADDR_INPUT 0x1000u
#define ADDR_WEIGHT_Q 0x2000u
#define ADDR_WEIGHT_K 0x2200u
#define ADDR_WEIGHT_V 0x2400u
#define ADDR_WEIGHT_O 0x2600u
#define ADDR_WEIGHT_FFN1 0x2800u
#define ADDR_WEIGHT_FFN2 0x2c00u
#define ADDR_REQUANT_IDENTITY 0x3000u
#define ADDR_REQUANT_SHIFT2 0x3008u
#define ADDR_NORM1_GAMMA 0x3100u
#define ADDR_NORM1_BETA 0x3120u
#define ADDR_NORM2_GAMMA 0x3140u
#define ADDR_NORM2_BETA 0x3160u
#define ADDR_OUTPUT 0x5500u

#define MODEL_TOKENS 2u
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

static const char *const operation_names[MODEL_COMMAND_COUNT] = {
    "load_input",
    "load_weight_q",
    "load_weight_k",
    "load_weight_v",
    "load_weight_o",
    "load_weight_ffn1",
    "load_weight_ffn2",
    "load_parameters",
    "q_projection",
    "k_projection",
    "v_projection",
    "pack_q_head0",
    "pack_q_head1",
    "transpose_k_head0",
    "transpose_k_head1",
    "tile_v_head0",
    "tile_v_head1",
    "qk_transpose",
    "attention_softmax",
    "attention_value",
    "concat_head0",
    "concat_head1",
    "output_projection",
    "residual_add_1",
    "layer_norm_1",
    "ffn_expand",
    "ffn_gelu",
    "ffn_contract",
    "residual_add_2",
    "layer_norm_2"
};

static const uint16_t operation_command_ids[MODEL_COMMAND_COUNT] = {
    240u, 241u, 242u, 243u, 244u, 245u, 246u, 247u,
    256u, 257u, 258u, 259u, 260u, 261u, 262u, 263u,
    264u, 265u, 266u, 267u, 268u, 269u, 270u, 271u,
    272u, 273u, 274u, 275u, 276u, 277u
};

static void put_u32(uint8_t *memory, size_t address, uint32_t value)
{
    uint32_t byte;

    for (byte = 0u; byte < 4u; byte++) {
        memory[address + byte] = (uint8_t)(value >> (byte * 8u));
    }
}

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
        return (int16_t)(-1 - (int32_t)(0xffffu - bits));
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

static size_t tiled_b_index(uint32_t k,
                            uint32_t n,
                            uint32_t columns)
{
    uint32_t n_tiles = (columns + NPU_REF_NT - 1u) / NPU_REF_NT;
    uint32_t k_outer = k / NPU_REF_KT;
    uint32_t n_outer = n / NPU_REF_NT;
    uint32_t k_inner = k % NPU_REF_KT;
    uint32_t n_inner = n % NPU_REF_NT;

    return (size_t)((((k_outer * n_tiles + n_outer) * NPU_REF_KT +
                      k_inner) *
                     NPU_REF_NT) +
                    n_inner);
}

static void set_tiled_b(uint8_t *memory,
                        size_t base,
                        uint32_t k,
                        uint32_t n,
                        uint32_t columns,
                        int16_t value)
{
    size_t index = tiled_b_index(k, n, columns);
    put_i16(memory, base + index * 2u, value);
}

static void initialize_identity_weight(uint8_t *memory,
                                       size_t base,
                                       uint32_t width)
{
    uint32_t index;

    for (index = 0u; index < width; index++) {
        set_tiled_b(memory, base, index, index, width, 1);
    }
}

static void initialize_model_data(void)
{
    uint32_t feature;

    (void)memset(model_l1, 0, sizeof(model_l1));
    (void)memset(model_ddr, 0, sizeof(model_ddr));
    (void)memcpy(&model_ddr[MODEL_DESCRIPTOR_BASE],
                 transformer_block_descriptors,
                 (size_t)transformer_block_descriptors_bytes);

    put_i16(model_ddr, ADDR_DDR_INPUT + 0u * 16u + 0u * 2u, 1);
    put_i16(model_ddr, ADDR_DDR_INPUT + 1u * 16u + 5u * 2u, 1);

    initialize_identity_weight(
        model_ddr, ADDR_DDR_WEIGHT_Q, MODEL_WIDTH);
    initialize_identity_weight(
        model_ddr, ADDR_DDR_WEIGHT_K, MODEL_WIDTH);
    initialize_identity_weight(
        model_ddr, ADDR_DDR_WEIGHT_V, MODEL_WIDTH);
    initialize_identity_weight(
        model_ddr, ADDR_DDR_WEIGHT_O, MODEL_WIDTH);

    for (feature = 0u; feature < MODEL_WIDTH; feature++) {
        set_tiled_b(model_ddr, ADDR_DDR_WEIGHT_FFN1,
                    feature, feature, MODEL_FFN_WIDTH, 1);
        set_tiled_b(model_ddr, ADDR_DDR_WEIGHT_FFN1,
                    feature, feature + MODEL_WIDTH,
                    MODEL_FFN_WIDTH, -1);
        set_tiled_b(model_ddr, ADDR_DDR_WEIGHT_FFN2,
                    feature, feature, MODEL_WIDTH, 1);
        set_tiled_b(model_ddr, ADDR_DDR_WEIGHT_FFN2,
                    feature + MODEL_WIDTH, feature,
                    MODEL_WIDTH, 1);
    }

    put_u32(model_ddr,
            ADDR_DDR_PARAMETERS +
                (ADDR_REQUANT_IDENTITY - ADDR_REQUANT_IDENTITY),
            1u);
    model_ddr[ADDR_DDR_PARAMETERS +
              (ADDR_REQUANT_IDENTITY - ADDR_REQUANT_IDENTITY) + 4u] = 0u;
    put_u32(model_ddr,
            ADDR_DDR_PARAMETERS +
                (ADDR_REQUANT_SHIFT2 - ADDR_REQUANT_IDENTITY),
            1u);
    model_ddr[ADDR_DDR_PARAMETERS +
              (ADDR_REQUANT_SHIFT2 - ADDR_REQUANT_IDENTITY) + 4u] = 2u;

    for (feature = 0u; feature < MODEL_WIDTH; feature++) {
        put_i16(model_ddr,
                ADDR_DDR_PARAMETERS +
                    (ADDR_NORM1_GAMMA - ADDR_REQUANT_IDENTITY) +
                    feature * 2u,
                4);
        put_i16(model_ddr,
                ADDR_DDR_PARAMETERS +
                    (ADDR_NORM1_BETA - ADDR_REQUANT_IDENTITY) +
                    feature * 2u,
                1);
        put_i16(model_ddr,
                ADDR_DDR_PARAMETERS +
                    (ADDR_NORM2_GAMMA - ADDR_REQUANT_IDENTITY) +
                    feature * 2u,
                3);
        put_i16(model_ddr,
                ADDR_DDR_PARAMETERS +
                    (ADDR_NORM2_BETA - ADDR_REQUANT_IDENTITY) +
                    feature * 2u,
                1);
    }
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
                reference_round(normalized * (float)gamma + (float)beta);
        }
    }
}

static void reference_transformer(
    int16_t output[MODEL_TOKENS][MODEL_WIDTH])
{
    int16_t input[MODEL_TOKENS][MODEL_WIDTH] = {{0}};
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

    input[0][0] = 1;
    input[1][5] = 1;

    for (head = 0u; head < MODEL_HEADS; head++) {
        for (query = 0u; query < MODEL_TOKENS; query++) {
            int32_t scores[MODEL_TOKENS] = {0};
            int16_t probabilities[MODEL_TOKENS] = {0};
            float maximum;
            float sum = 0.0f;

            for (key = 0u; key < MODEL_TOKENS; key++) {
                for (feature = 0u; feature < MODEL_HEAD_WIDTH; feature++) {
                    uint32_t channel = head * MODEL_HEAD_WIDTH + feature;
                    scores[key] +=
                        input[query][channel] * input[key][channel];
                }
            }
            maximum = (float)scores[0];
            if ((float)scores[1] > maximum) {
                maximum = (float)scores[1];
            }
            for (key = 0u; key < MODEL_TOKENS; key++) {
                sum += expf((float)scores[key] - maximum);
            }
            for (key = 0u; key < MODEL_TOKENS; key++) {
                float probability =
                    expf((float)scores[key] - maximum) / sum;
                probabilities[key] = reference_round(probability / 0.25f);
            }
            for (feature = 0u; feature < MODEL_HEAD_WIDTH; feature++) {
                int32_t weighted = 0;
                uint32_t channel = head * MODEL_HEAD_WIDTH + feature;
                for (key = 0u; key < MODEL_TOKENS; key++) {
                    weighted += probabilities[key] * input[key][channel];
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
                          input[query][feature]);
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
                (1.0f + erff((float)hidden[query][feature] /
                             sqrtf(2.0f)));
            negative =
                0.5f * (float)hidden[query][feature + MODEL_WIDTH] *
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

static int submit_model(npu_driver_t *driver)
{
    uint32_t index;

    if ((size_t)transformer_block_commands_bytes !=
        MODEL_COMMAND_COUNT * NPU_DRV_CMD128_BYTES) {
        return -1;
    }
    for (index = 0u; index < MODEL_COMMAND_COUNT; index++) {
        const unsigned char *wire =
            &transformer_block_commands[index * NPU_DRV_CMD128_BYTES];
        npu_drv_cmd128_t command;
        npu_drv_cmd_fields_t fields;
        npu_drv_submit_result_t result;
        size_t descriptor_offset;
        size_t descriptor_bytes;
        char wait0[24];
        char wait1[24];
        char signal[24];
        int rc;

        command.lo = get_u64(&wire[0]);
        command.hi = get_u64(&wire[8]);
        rc = npu_drv_cmd128_decode(&command, &fields);
        if (rc != NPU_DRV_OK ||
            fields.descriptor_addr < MODEL_DESCRIPTOR_BASE) {
            return -1;
        }
        descriptor_offset =
            (size_t)(fields.descriptor_addr - MODEL_DESCRIPTOR_BASE);
        descriptor_bytes = descriptor_bytes_for_engine(fields.engine);
        if (descriptor_bytes == 0u ||
            descriptor_offset >
                (size_t)transformer_block_descriptors_bytes ||
            descriptor_bytes >
                (size_t)transformer_block_descriptors_bytes -
                    descriptor_offset) {
            return -1;
        }
        rc = npu_drv_submit(
            driver, &command,
            &transformer_block_descriptors[descriptor_offset],
            descriptor_bytes, &result);
        event_text(fields.wait_event[0], wait0, sizeof(wait0));
        event_text(fields.wait_event[1], wait1, sizeof(wait1));
        event_text(fields.signal_event, signal, sizeof(signal));
        printf("submit op=%s command_id=%u wait=[%s,%s] signal=%s "
               "accepted_status=%u rc=%d\n",
               operation_names[index], (unsigned)fields.command_id,
               wait0, wait1, signal,
               (unsigned)result.status, rc);
        if (rc != NPU_DRV_OK || result.status != 0u) {
            return -1;
        }
    }
    return 0;
}

static int wait_for_model(npu_driver_t *driver)
{
    uint32_t index;

    for (index = 0u; index < MODEL_COMMAND_COUNT; index++) {
        npu_drv_task_status_t status;
        uint64_t progress = 0u;
        uint16_t command_id = operation_command_ids[index];
        (void)memset(&status, 0, sizeof(status));
        int rc = npu_drv_wait_task(
            driver, command_id, 1000000u, &status);

        if (rc == NPU_DRV_OK) {
            rc = npu_drv_query_raw(
                driver, command_id, NPU_DRV_QUERY_PROGRESS, &progress);
        }
        printf("complete op=%s command_id=%u state=%u status=%u "
               "progress=%llu rc=%d\n",
               operation_names[index], (unsigned)command_id,
               (unsigned)status.state, (unsigned)status.status,
               (unsigned long long)progress, rc);
        if (rc != NPU_DRV_OK ||
            status.state != NPU_DRV_TASK_TERMINAL ||
            status.status != NPU_STATUS_SUCCESS) {
            return -1;
        }
    }
    return 0;
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
    int16_t expected[MODEL_TOKENS][MODEL_WIDTH] = {{0}};
    int16_t actual[MODEL_TOKENS][MODEL_WIDTH] = {{0}};
    uint32_t token;
    uint32_t feature;
    int mismatch = 0;

    reference_transformer(expected);
    CHECK(npu_drv_sync_for_cpu(
        driver, &model_l1[ADDR_OUTPUT],
        MODEL_TOKENS * MODEL_WIDTH * sizeof(int16_t)));
    for (token = 0u; token < MODEL_TOKENS; token++) {
        for (feature = 0u; feature < MODEL_WIDTH; feature++) {
            actual[token][feature] =
                get_i16(model_l1,
                        ADDR_OUTPUT +
                            (size_t)token * MODEL_WIDTH * 2u +
                            (size_t)feature * 2u);
            if (actual[token][feature] != expected[token][feature]) {
                mismatch = 1;
            }
        }
        printf("output token=%u values=[", (unsigned)token);
        for (feature = 0u; feature < MODEL_WIDTH; feature++) {
            printf("%s%d", feature == 0u ? "" : ",",
                   (int)actual[token][feature]);
        }
        printf("] reference_class=%u actual_class=%u\n",
               (unsigned)vector_class(expected[token]),
               (unsigned)vector_class(actual[token]));
    }
    return mismatch ? -1 : 0;
}

static int acknowledge_model(npu_driver_t *driver)
{
    uint32_t index;

    for (index = 0u; index < MODEL_COMMAND_COUNT; index++) {
        int rc = npu_drv_ack_task(driver, operation_command_ids[index]);
        if (rc != NPU_DRV_OK) {
            return -1;
        }
    }
    return 0;
}

int main(void)
{
    npu_driver_t driver;
    npu_drv_platform_ops_t operations;

    if ((size_t)transformer_block_descriptors_bytes +
            MODEL_DESCRIPTOR_BASE >
        sizeof(model_ddr)) {
        fprintf(stderr, "descriptor image does not fit DDR\n");
        return 1;
    }
    initialize_model_data();
    CHECK(transformer_cmodel_backend_init(
        &model_backend, model_l1, sizeof(model_l1),
        model_ddr, sizeof(model_ddr)));
    operations = transformer_cmodel_backend_operations(&model_backend);
    CHECK(npu_drv_init(&driver, &operations));
    CHECK(submit_model(&driver));
    CHECK(wait_for_model(&driver));
    CHECK(check_output(&driver));
    CHECK(acknowledge_model(&driver));

    printf("PASS commands=%u cmd_bits=128 submitted_beats=%u "
           "responses=%u cycles=%llu cache_clean=%u cache_invalidate=%u\n",
           MODEL_COMMAND_COUNT,
           (unsigned)model_backend.submitted_beats,
           (unsigned)model_backend.responses,
           (unsigned long long)model_backend.model.cycle,
           (unsigned)model_backend.cache_clean_calls,
           (unsigned)model_backend.cache_invalidate_calls);
    return 0;
}
