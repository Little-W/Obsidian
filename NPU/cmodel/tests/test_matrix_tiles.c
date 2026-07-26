#include "test_util.h"

#define TILE_TEST_L1_BYTES NPU_REF_L1_BYTES
#define TILE_TEST_DDR_BYTES (1024u * 1024u)
#define TILE_TEST_A_ADDR 0x10000u
#define TILE_TEST_B_ADDR 0x30000u
#define TILE_TEST_C_ADDR 0x60000u

typedef struct {
    uint32_t m;
    uint32_t n;
    uint32_t k;
} tile_test_shape_t;

static uint8_t tile_test_l1[TILE_TEST_L1_BYTES];
static uint8_t tile_test_ddr[TILE_TEST_DDR_BYTES];
static npu_model_t tile_test_model;

static int32_t tile_test_a_value(uint32_t row, uint32_t inner)
{
    return (int32_t)((row * 3u + inner) % 11u) - 5;
}

static int32_t tile_test_b_value(uint32_t inner, uint32_t col)
{
    return (int32_t)((inner + col * 2u) % 9u) - 4;
}

static void tile_test_store_b(const npu_config_t *config,
                              const npu_matrix_desc_t *desc,
                              uint32_t inner,
                              uint32_t col,
                              int32_t value)
{
    uint64_t n_tiles =
        ((uint64_t)desc->n + config->nt - 1u) / config->nt;
    uint64_t linear =
        (((((uint64_t)inner / config->kt) * n_tiles +
           col / config->nt) *
              config->kt +
          inner % config->kt) *
             config->nt) +
        col % config->nt;

    tile_test_l1[(size_t)(desc->b.addr + linear)] =
        (uint8_t)value;
}

static int tile_test_run_shape(const tile_test_shape_t *shape)
{
    npu_config_t config;
    npu_matrix_desc_t desc = {0};
    uint64_t b_tiles;
    uint64_t progress = UINT64_MAX;
    uint32_t row;
    uint32_t col;
    uint32_t inner;

    npu_config_reference(&config);
    test_clear_bytes(tile_test_l1, sizeof(tile_test_l1));
    test_clear_bytes(tile_test_ddr, sizeof(tile_test_ddr));
    TEST_CHECK_STATUS(
        npu_model_init(&tile_test_model, &config,
                       tile_test_l1, sizeof(tile_test_l1),
                       tile_test_ddr, sizeof(tile_test_ddr)),
        NPU_STATUS_SUCCESS);

    desc.m = shape->m;
    desc.n = shape->n;
    desc.k = shape->k;
    desc.batch_count = 1u;
    desc.a = test_tensor(
        NPU_DTYPE_INT8, TILE_TEST_A_ADDR,
        (uint64_t)shape->m * shape->k, shape->k);

    b_tiles =
        (((uint64_t)shape->k + config.kt - 1u) / config.kt) *
        (((uint64_t)shape->n + config.nt - 1u) / config.nt);
    b_tiles *= (uint64_t)config.kt * config.nt;
    desc.b = test_tensor(
        NPU_DTYPE_INT8, TILE_TEST_B_ADDR, b_tiles, 0u);
    desc.b.batch_stride_bytes = (uint32_t)b_tiles;

    desc.c = test_tensor(
        NPU_DTYPE_INT32, TILE_TEST_C_ADDR,
        (uint64_t)shape->m * shape->n * sizeof(uint32_t),
        shape->n * (uint32_t)sizeof(uint32_t));
    desc.b_tiled = 1u;
    desc.final_output = 1u;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;

    for (row = 0u; row < shape->m; row++) {
        for (inner = 0u; inner < shape->k; inner++) {
            TEST_CHECK_STATUS(
                npu_tensor_write(
                    &tile_test_model, &desc.a, 0u, row, inner,
                    tile_test_a_value(row, inner)),
                NPU_STATUS_SUCCESS);
        }
    }
    for (inner = 0u; inner < shape->k; inner++) {
        for (col = 0u; col < shape->n; col++) {
            tile_test_store_b(
                &config, &desc, inner, col,
                tile_test_b_value(inner, col));
        }
    }

    TEST_CHECK_STATUS(
        npu_matrix_execute(
            &tile_test_model, NPU_MATRIX_GEMM, &desc, &progress),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(progress == (uint64_t)shape->m * shape->n);

    for (row = 0u; row < shape->m; row++) {
        for (col = 0u; col < shape->n; col++) {
            int64_t expected = 0;
            int32_t actual = 0;

            for (inner = 0u; inner < shape->k; inner++) {
                expected +=
                    (int64_t)tile_test_a_value(row, inner) *
                    tile_test_b_value(inner, col);
            }
            TEST_CHECK_STATUS(
                npu_tensor_read(
                    &tile_test_model, &desc.c, 0u, row, col,
                    &actual),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(actual == (int32_t)expected);
        }
    }
    return 0;
}

int test_matrix_tiles(void)
{
    static const tile_test_shape_t shapes[] = {
        {0u, 1u, 1u},
        {1u, 0u, 1u},
        {1u, 1u, 0u},
        {1u, 1u, 1u},
        {7u, 7u, 15u},
        {8u, 8u, 16u},
        {9u, 9u, 17u},
        {17u, 17u, 33u}
    };
    size_t index;

    for (index = 0u;
         index < sizeof(shapes) / sizeof(shapes[0]);
         index++) {
        int line = tile_test_run_shape(&shapes[index]);

        if (line != 0) {
            return line;
        }
    }
    return 0;
}
