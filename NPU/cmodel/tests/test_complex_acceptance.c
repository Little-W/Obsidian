#include "npu_engine_data_cycle.h"
#include "test_util.h"

#include <limits.h>

#ifdef NPU_COMPLEX_ACCEPTANCE_STANDALONE
#include <stdio.h>
#endif

#define COMPLEX_ACCEPT_L1_BYTES NPU_REF_L1_BYTES
#define COMPLEX_ACCEPT_DDR_BYTES (1024u * 1024u)
#define COMPLEX_ACCEPT_SRC0_ADDR UINT64_C(0x1000)
#define COMPLEX_ACCEPT_SRC1_ADDR UINT64_C(0x2000)
#define COMPLEX_ACCEPT_SRC2_ADDR UINT64_C(0x3000)
#define COMPLEX_ACCEPT_DST_ADDR UINT64_C(0x4000)
#define COMPLEX_ACCEPT_MASK_ADDR UINT64_C(0x5000)
#define COMPLEX_ACCEPT_VALID_ADDR UINT64_C(0x6000)

static uint8_t complex_accept_l1[COMPLEX_ACCEPT_L1_BYTES];
static uint8_t complex_accept_ddr[COMPLEX_ACCEPT_DDR_BYTES];
static npu_model_t complex_accept_model;

static void complex_accept_clear(uint8_t *memory, size_t bytes)
{
    size_t index;

    for (index = 0u; index < bytes; index++) {
        memory[index] = 0u;
    }
}

static uint32_t complex_accept_row_bytes(npu_dtype_t dtype,
                                         uint32_t length)
{
    if (dtype == NPU_DTYPE_INT4) {
        return (length + 1u) / 2u;
    }
    if (dtype == NPU_DTYPE_INT8) {
        return length;
    }
    return length * 4u;
}

static npu_tensor_t complex_accept_tensor(npu_dtype_t dtype,
                                          uint64_t addr,
                                          uint32_t rows,
                                          uint32_t length)
{
    npu_tensor_t tensor;
    uint32_t row_bytes =
        complex_accept_row_bytes(dtype, length);

    tensor.space = NPU_SPACE_L1;
    tensor.dtype = dtype;
    tensor.addr = addr;
    tensor.region_bytes = (uint64_t)rows * row_bytes;
    tensor.row_stride_bytes = row_bytes;
    tensor.elem_stride_bytes = 0u;
    tensor.batch_stride_bytes = 0u;
    tensor.start_nibble = 0u;
    return tensor;
}

static int complex_accept_init(void)
{
    npu_config_t config;

    npu_config_reference(&config);
    complex_accept_clear(
        complex_accept_l1, sizeof(complex_accept_l1));
    complex_accept_clear(
        complex_accept_ddr, sizeof(complex_accept_ddr));
    return npu_model_init(
               &complex_accept_model, &config,
               complex_accept_l1, sizeof(complex_accept_l1),
               complex_accept_ddr,
               sizeof(complex_accept_ddr)) ==
           NPU_STATUS_SUCCESS;
}

static npu_complex_desc_t complex_accept_desc(
    npu_dtype_t src0_dtype,
    npu_dtype_t src1_dtype,
    npu_dtype_t src2_dtype,
    npu_dtype_t dst_dtype,
    uint32_t rows,
    uint32_t length)
{
    npu_complex_desc_t desc = {0};

    desc.rows = rows;
    desc.length = length;
    desc.valid_length = rows == 0u ? 0u : length;
    desc.src0 = complex_accept_tensor(
        src0_dtype, COMPLEX_ACCEPT_SRC0_ADDR, rows, length);
    desc.src1 = complex_accept_tensor(
        src1_dtype, COMPLEX_ACCEPT_SRC1_ADDR, 1u, length);
    desc.src2 = complex_accept_tensor(
        src2_dtype, COMPLEX_ACCEPT_SRC2_ADDR, 1u, length);
    desc.dst = complex_accept_tensor(
        dst_dtype, COMPLEX_ACCEPT_DST_ADDR, rows, length);
    desc.mask = complex_accept_tensor(
        NPU_DTYPE_INT8, COMPLEX_ACCEPT_MASK_ADDR,
        rows, length);
    desc.valid_lengths = complex_accept_tensor(
        NPU_DTYPE_INT32, COMPLEX_ACCEPT_VALID_ADDR,
        rows, 1u);
    desc.src0_scale = 1.0f;
    desc.src1_scale = 1.0f;
    desc.src2_scale = 1.0f;
    desc.dst_scale = 1.0f;
    desc.epsilon = 0.0f;
    desc.input_clip_min = -16.0f;
    desc.input_clip_max = 16.0f;
    desc.round_mode = NPU_ROUND_NEAREST_EVEN;
    desc.overflow_mode = NPU_OVERFLOW_SATURATE;
    desc.scale_mode = NPU_SCALE_PER_TENSOR;
    desc.mask_mode = NPU_MASK_NONE;
    desc.all_mask_mode = NPU_ALL_MASK_WRITE_ZERO;
    desc.beta_enable = 1u;
    return desc;
}

static int complex_accept_write(const npu_tensor_t *tensor,
                                uint32_t row,
                                uint32_t element,
                                int32_t value)
{
    TEST_CHECK_STATUS(
        npu_tensor_write(
            &complex_accept_model, tensor, 0u,
            row, element, value),
        NPU_STATUS_SUCCESS);
    return 0;
}

static int complex_accept_read(const npu_tensor_t *tensor,
                               uint32_t row,
                               uint32_t element,
                               int32_t expected)
{
    int32_t actual = 0;

    TEST_CHECK_STATUS(
        npu_tensor_read(
            &complex_accept_model, tensor, 0u,
            row, element, &actual),
        NPU_STATUS_SUCCESS);
    TEST_CHECK(actual == expected);
    return 0;
}

static int complex_accept_activations(void)
{
    static const npu_function_t functions[] = {
        NPU_FUNC_SIGMOID,
        NPU_FUNC_TANH,
        NPU_FUNC_GELU,
        NPU_FUNC_SILU
    };
    npu_dtype_t src_dtype;
    npu_dtype_t dst_dtype;
    uint32_t function_index;

    for (src_dtype = NPU_DTYPE_INT4;
         src_dtype <= NPU_DTYPE_INT32; src_dtype++) {
        for (dst_dtype = NPU_DTYPE_INT4;
             dst_dtype <= NPU_DTYPE_INT32; dst_dtype++) {
            for (function_index = 0u;
                 function_index <
                     sizeof(functions) / sizeof(functions[0]);
                 function_index++) {
                npu_complex_desc_t desc;
                uint64_t progress = UINT64_MAX;
                int line;

                TEST_CHECK(complex_accept_init());
                desc = complex_accept_desc(
                    src_dtype, NPU_DTYPE_INT8,
                    NPU_DTYPE_INT8, dst_dtype, 1u, 1u);
                desc.function = functions[function_index];
                desc.dst_scale = 0.25f;
                line = complex_accept_write(
                    &desc.src0, 0u, 0u, 0);
                if (line != 0) {
                    return line;
                }
                TEST_CHECK_STATUS(
                    npu_complex_execute(
                        &complex_accept_model,
                        NPU_COMPLEX_ACT, &desc, &progress),
                    NPU_STATUS_SUCCESS);
                TEST_CHECK(progress == 1u);
                line = complex_accept_read(
                    &desc.dst, 0u, 0u,
                    functions[function_index] ==
                            NPU_FUNC_SIGMOID
                        ? 2
                        : 0);
                if (line != 0) {
                    return line;
                }
            }
        }
    }
    return 0;
}

static int complex_accept_round_modes(void)
{
    static const int32_t expected[] = {0, 0, 1, 0};
    npu_round_mode_t mode;

    for (mode = NPU_ROUND_NEAREST_EVEN;
         mode <= NPU_ROUND_TO_NEG_INF; mode++) {
        npu_complex_desc_t desc;
        uint64_t progress = UINT64_MAX;
        int line;

        TEST_CHECK(complex_accept_init());
        desc = complex_accept_desc(
            NPU_DTYPE_INT8, NPU_DTYPE_INT8,
            NPU_DTYPE_INT8, NPU_DTYPE_INT8, 1u, 1u);
        desc.function = NPU_FUNC_SIGMOID;
        desc.round_mode = mode;
        line = complex_accept_write(
            &desc.src0, 0u, 0u, 0);
        if (line != 0) {
            return line;
        }
        TEST_CHECK_STATUS(
            npu_complex_execute(
                &complex_accept_model, NPU_COMPLEX_ACT,
                &desc, &progress),
            NPU_STATUS_SUCCESS);
        TEST_CHECK(progress == 1u);
        line = complex_accept_read(
            &desc.dst, 0u, 0u, expected[mode]);
        if (line != 0) {
            return line;
        }
    }
    return 0;
}

static int complex_accept_shapes_and_tail(void)
{
    static const uint32_t lengths[] = {0u, 1u, 3u, 4u, 5u};
    uint32_t length_index;

    for (length_index = 0u;
         length_index <
             sizeof(lengths) / sizeof(lengths[0]);
         length_index++) {
        npu_complex_desc_t desc;
        uint32_t element;
        uint32_t length = lengths[length_index];
        uint64_t progress = UINT64_MAX;

        TEST_CHECK(complex_accept_init());
        desc = complex_accept_desc(
            NPU_DTYPE_INT4, NPU_DTYPE_INT8,
            NPU_DTYPE_INT8, NPU_DTYPE_INT4, 1u, length);
        desc.function = NPU_FUNC_TANH;
        for (element = 0u; element < length; element++) {
            int line = complex_accept_write(
                &desc.src0, 0u, element, 0);

            if (line != 0) {
                return line;
            }
        }
        if (length != 0u) {
            complex_accept_l1[
                (size_t)desc.dst.addr +
                (size_t)(length - 1u) / 2u] = 0xffu;
        }
        TEST_CHECK_STATUS(
            npu_complex_execute(
                &complex_accept_model, NPU_COMPLEX_ACT,
                &desc, &progress),
            NPU_STATUS_SUCCESS);
        TEST_CHECK(progress == length);
        for (element = 0u; element < length; element++) {
            int line = complex_accept_read(
                &desc.dst, 0u, element, 0);

            if (line != 0) {
                return line;
            }
        }
        if ((length & 1u) != 0u) {
            TEST_CHECK(
                (complex_accept_l1[
                     (size_t)desc.dst.addr + length / 2u] &
                 0xf0u) == 0u);
        }
    }

    {
        npu_complex_desc_t desc;
        uint64_t progress = UINT64_MAX;

        TEST_CHECK(complex_accept_init());
        desc = complex_accept_desc(
            NPU_DTYPE_INT8, NPU_DTYPE_INT8,
            NPU_DTYPE_INT8, NPU_DTYPE_INT8, 0u, 5u);
        desc.function = NPU_FUNC_SIGMOID;
        complex_accept_l1[(size_t)desc.dst.addr] = 0x5au;
        TEST_CHECK_STATUS(
            npu_complex_execute(
                &complex_accept_model, NPU_COMPLEX_ACT,
                &desc, &progress),
            NPU_STATUS_SUCCESS);
        TEST_CHECK(progress == 0u);
        TEST_CHECK(
            complex_accept_l1[(size_t)desc.dst.addr] == 0x5au);
    }
    return 0;
}

static int complex_accept_softmax_dtypes(void)
{
    npu_dtype_t src_dtype;
    npu_dtype_t dst_dtype;

    for (src_dtype = NPU_DTYPE_INT4;
         src_dtype <= NPU_DTYPE_INT32; src_dtype++) {
        for (dst_dtype = NPU_DTYPE_INT4;
             dst_dtype <= NPU_DTYPE_INT32; dst_dtype++) {
            npu_complex_desc_t desc;
            uint64_t progress = UINT64_MAX;
            int line;

            TEST_CHECK(complex_accept_init());
            desc = complex_accept_desc(
                src_dtype, NPU_DTYPE_INT8,
                NPU_DTYPE_INT8, dst_dtype, 1u, 1u);
            desc.function = NPU_FUNC_SOFTMAX;
            desc.dst_scale = 0.25f;
            desc.scratch_request_elems = 1u;
            line = complex_accept_write(
                &desc.src0, 0u, 0u, 3);
            if (line != 0) {
                return line;
            }
            TEST_CHECK_STATUS(
                npu_complex_execute(
                    &complex_accept_model,
                    NPU_COMPLEX_SOFTMAX,
                    &desc, &progress),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(progress == 1u);
            line = complex_accept_read(
                &desc.dst, 0u, 0u, 4);
            if (line != 0) {
                return line;
            }
        }
    }
    return 0;
}

static int complex_accept_layernorm_dtypes(void)
{
    npu_dtype_t src_dtype;
    npu_dtype_t gamma_dtype;
    npu_dtype_t beta_dtype;
    npu_dtype_t dst_dtype;

    for (src_dtype = NPU_DTYPE_INT4;
         src_dtype <= NPU_DTYPE_INT32; src_dtype++) {
        for (gamma_dtype = NPU_DTYPE_INT4;
             gamma_dtype <= NPU_DTYPE_INT32; gamma_dtype++) {
            for (beta_dtype = NPU_DTYPE_INT4;
                 beta_dtype <= NPU_DTYPE_INT32; beta_dtype++) {
                for (dst_dtype = NPU_DTYPE_INT4;
                     dst_dtype <= NPU_DTYPE_INT32; dst_dtype++) {
                    npu_complex_desc_t desc;
                    uint64_t progress = UINT64_MAX;
                    int line;

                    TEST_CHECK(complex_accept_init());
                    desc = complex_accept_desc(
                        src_dtype, gamma_dtype, beta_dtype,
                        dst_dtype, 1u, 1u);
                    desc.function = NPU_FUNC_LAYERNORM;
                    desc.epsilon = 0.00001f;
                    desc.input_clip_min = 0.0f;
                    desc.input_clip_max = 0.0f;
                    desc.scratch_request_elems = 1u;
                    line = complex_accept_write(
                        &desc.src0, 0u, 0u, 3);
                    if (line != 0) {
                        return line;
                    }
                    line = complex_accept_write(
                        &desc.src1, 0u, 0u, 2);
                    if (line != 0) {
                        return line;
                    }
                    line = complex_accept_write(
                        &desc.src2, 0u, 0u, 1);
                    if (line != 0) {
                        return line;
                    }
                    TEST_CHECK_STATUS(
                        npu_complex_execute(
                            &complex_accept_model,
                            NPU_COMPLEX_NORM,
                            &desc, &progress),
                        NPU_STATUS_SUCCESS);
                    TEST_CHECK(progress == 1u);
                    line = complex_accept_read(
                        &desc.dst, 0u, 0u, 1);
                    if (line != 0) {
                        return line;
                    }
                }
            }
        }
    }
    return 0;
}

static int complex_accept_rmsnorm_dtypes(void)
{
    npu_dtype_t src_dtype;
    npu_dtype_t gamma_dtype;
    npu_dtype_t dst_dtype;

    for (src_dtype = NPU_DTYPE_INT4;
         src_dtype <= NPU_DTYPE_INT32; src_dtype++) {
        for (gamma_dtype = NPU_DTYPE_INT4;
             gamma_dtype <= NPU_DTYPE_INT32; gamma_dtype++) {
            for (dst_dtype = NPU_DTYPE_INT4;
                 dst_dtype <= NPU_DTYPE_INT32; dst_dtype++) {
                npu_complex_desc_t desc;
                uint64_t progress = UINT64_MAX;
                int line;

                TEST_CHECK(complex_accept_init());
                desc = complex_accept_desc(
                    src_dtype, gamma_dtype, NPU_DTYPE_INT4,
                    dst_dtype, 1u, 1u);
                desc.function = NPU_FUNC_RMSNORM;
                desc.epsilon = 0.00001f;
                desc.src2 = (npu_tensor_t){0};
                desc.src2_scale = 0.0f;
                desc.beta_enable = 0u;
                desc.input_clip_min = 0.0f;
                desc.input_clip_max = 0.0f;
                desc.scratch_request_elems = 1u;
                line = complex_accept_write(
                    &desc.src0, 0u, 0u, 0);
                if (line != 0) {
                    return line;
                }
                line = complex_accept_write(
                    &desc.src1, 0u, 0u, 3);
                if (line != 0) {
                    return line;
                }
                TEST_CHECK_STATUS(
                    npu_complex_execute(
                        &complex_accept_model,
                        NPU_COMPLEX_NORM,
                        &desc, &progress),
                    NPU_STATUS_SUCCESS);
                TEST_CHECK(progress == 1u);
                line = complex_accept_read(
                    &desc.dst, 0u, 0u, 0);
                if (line != 0) {
                    return line;
                }
            }
        }
    }
    return 0;
}

static int complex_accept_add_rescale_dtypes(void)
{
    npu_dtype_t src0_dtype;
    npu_dtype_t src1_dtype;
    npu_dtype_t dst_dtype;

    for (src0_dtype = NPU_DTYPE_INT4;
         src0_dtype <= NPU_DTYPE_INT32; src0_dtype++) {
        for (src1_dtype = NPU_DTYPE_INT4;
             src1_dtype <= NPU_DTYPE_INT32; src1_dtype++) {
            for (dst_dtype = NPU_DTYPE_INT4;
                 dst_dtype <= NPU_DTYPE_INT32; dst_dtype++) {
                npu_complex_desc_t desc;
                uint64_t progress = UINT64_MAX;
                int line;

                TEST_CHECK(complex_accept_init());
                desc = complex_accept_desc(
                    src0_dtype, src1_dtype,
                    NPU_DTYPE_INT8, dst_dtype, 1u, 1u);
                desc.function = NPU_FUNC_ADD_RESCALE;
                desc.epsilon = 0.0f;
                desc.input_clip_min = 0.0f;
                desc.input_clip_max = 0.0f;
                line = complex_accept_write(
                    &desc.src0, 0u, 0u, 1);
                if (line != 0) {
                    return line;
                }
                line = complex_accept_write(
                    &desc.src1, 0u, 0u, 2);
                if (line != 0) {
                    return line;
                }
                TEST_CHECK_STATUS(
                    npu_complex_execute(
                        &complex_accept_model,
                        NPU_COMPLEX_ADD_RESCALE,
                        &desc, &progress),
                    NPU_STATUS_SUCCESS);
                TEST_CHECK(progress == 1u);
                line = complex_accept_read(
                    &desc.dst, 0u, 0u, 3);
                if (line != 0) {
                    return line;
                }
            }
        }
    }
    return 0;
}

static void complex_accept_stat_fields(
    npu_complex_desc_t *desc,
    npu_function_t function)
{
    desc->function = function;
    desc->dst = complex_accept_tensor(
        NPU_DTYPE_INT32, COMPLEX_ACCEPT_DST_ADDR,
        desc->rows, 1u);
    desc->src0_scale = 0.0f;
    desc->src1_scale = 0.0f;
    desc->src2_scale = 0.0f;
    desc->dst_scale = 0.0f;
    desc->epsilon = 0.0f;
    desc->input_clip_min = 0.0f;
    desc->input_clip_max = 0.0f;
    desc->scale_mode = NPU_SCALE_NONE;
    desc->beta_enable = 0u;
}

static int complex_accept_statistics(void)
{
    static const npu_function_t functions[] = {
        NPU_FUNC_STAT_SUM,
        NPU_FUNC_STAT_MAX,
        NPU_FUNC_STAT_SUMSQ
    };
    static const int32_t expected[] = {1, 3, 13};
    npu_dtype_t src_dtype;
    uint32_t function_index;

    for (src_dtype = NPU_DTYPE_INT4;
         src_dtype <= NPU_DTYPE_INT32; src_dtype++) {
        for (function_index = 0u;
             function_index <
                 sizeof(functions) / sizeof(functions[0]);
             function_index++) {
            npu_complex_desc_t desc;
            uint64_t progress = UINT64_MAX;
            int line;

            TEST_CHECK(complex_accept_init());
            desc = complex_accept_desc(
                src_dtype, NPU_DTYPE_INT8,
                NPU_DTYPE_INT8, NPU_DTYPE_INT32,
                1u, 2u);
            complex_accept_stat_fields(
                &desc, functions[function_index]);
            line = complex_accept_write(
                &desc.src0, 0u, 0u, -2);
            if (line != 0) {
                return line;
            }
            line = complex_accept_write(
                &desc.src0, 0u, 1u, 3);
            if (line != 0) {
                return line;
            }
            TEST_CHECK_STATUS(
                npu_complex_execute(
                    &complex_accept_model,
                    NPU_COMPLEX_STAT, &desc, &progress),
                NPU_STATUS_SUCCESS);
            TEST_CHECK(progress == 1u);
            line = complex_accept_read(
                &desc.dst, 0u, 0u,
                expected[function_index]);
            if (line != 0) {
                return line;
            }
        }
    }
    return 0;
}

static int complex_accept_stat_overflow(void)
{
    static const npu_status_t statuses[] = {
        NPU_STATUS_SUCCESS,
        NPU_STATUS_NUMERIC_EXCEPTION,
        NPU_STATUS_SUCCESS
    };
    static const int32_t expected[] = {
        INT32_MAX,
        77,
        -2
    };
    npu_overflow_mode_t mode;

    for (mode = NPU_OVERFLOW_SATURATE;
         mode <= NPU_OVERFLOW_WRAP; mode++) {
        npu_complex_desc_t desc;
        uint64_t progress = UINT64_MAX;
        int line;

        TEST_CHECK(complex_accept_init());
        desc = complex_accept_desc(
            NPU_DTYPE_INT32, NPU_DTYPE_INT8,
            NPU_DTYPE_INT8, NPU_DTYPE_INT32, 1u, 2u);
        complex_accept_stat_fields(
            &desc, NPU_FUNC_STAT_SUM);
        desc.overflow_mode = mode;
        line = complex_accept_write(
            &desc.src0, 0u, 0u, INT32_MAX);
        if (line != 0) {
            return line;
        }
        line = complex_accept_write(
            &desc.src0, 0u, 1u, INT32_MAX);
        if (line != 0) {
            return line;
        }
        line = complex_accept_write(
            &desc.dst, 0u, 0u, 77);
        if (line != 0) {
            return line;
        }
        TEST_CHECK_STATUS(
            npu_complex_execute(
                &complex_accept_model, NPU_COMPLEX_STAT,
                &desc, &progress),
            statuses[mode]);
        TEST_CHECK(
            progress ==
            (mode == NPU_OVERFLOW_ERROR ? 0u : 1u));
        line = complex_accept_read(
            &desc.dst, 0u, 0u, expected[mode]);
        if (line != 0) {
            return line;
        }
    }
    return 0;
}

static int complex_accept_numeric_flag_latching(void)
{
    npu_engine_data_cycle_t adapter;
    npu_engine_data_workspace_t workspace;
    npu_wire_limits_t limits;
    npu_bus_trace_entry_t read_entries[8];
    npu_bus_trace_entry_t write_entries[8];
    uint32_t read_hash[16];
    uint32_t write_hash[16];
    npu_bus_trace_port_fn select_read_port;
    const void *select_read_port_context;

    TEST_CHECK(complex_accept_init());
    npu_wire_limits_reference(&limits);
    TEST_CHECK_STATUS(
        npu_engine_data_cycle_init(
            &adapter, &complex_accept_model,
            NPU_ENGINE_COMPLEX, &limits),
        NPU_STATUS_SUCCESS);
    workspace.read_entries = read_entries;
    workspace.read_capacity = 8u;
    workspace.read_hash = read_hash;
    workspace.read_hash_slots = 16u;
    workspace.write_entries = write_entries;
    workspace.write_capacity = 8u;
    workspace.write_hash = write_hash;
    workspace.write_hash_slots = 16u;
    TEST_CHECK(npu_engine_data_cycle_bind_workspace(
        &adapter, &workspace));

    select_read_port = adapter.trace.select_read_port;
    select_read_port_context =
        adapter.trace.select_read_port_context;
    TEST_CHECK(npu_bus_trace_begin(
        &adapter.trace,
        read_entries, 8u, read_hash, 16u,
        write_entries, 8u, write_hash, 16u,
        NPU_ENGINE_DATA_READ_PORTS,
        select_read_port, select_read_port_context));
    complex_accept_model.internal_bus_trace =
        &adapter.trace;

    npu_engine_data_record_cme_numeric(
        &complex_accept_model,
        NPU_ENGINE_DATA_CME_FP_NAN);
    npu_engine_data_record_cme_numeric(
        &complex_accept_model,
        NPU_ENGINE_DATA_CME_DIVIDE_BY_ZERO);
    npu_engine_data_record_cme_numeric(
        &complex_accept_model,
        NPU_ENGINE_DATA_CME_FP_INF);
    npu_engine_data_record_cme_numeric(
        &complex_accept_model,
        NPU_ENGINE_DATA_CME_ALL_MASK);
    npu_engine_data_record_integer_range(
        &complex_accept_model, NPU_DTYPE_INT32);

    TEST_CHECK(NPU_ENGINE_DATA_CME_NUMERIC_EXCEPTION ==
               0x01u);
    TEST_CHECK(NPU_ENGINE_DATA_CME_ALL_MASK == 0x02u);
    TEST_CHECK(
        NPU_ENGINE_DATA_CME_CLIPPED_OR_RANGE == 0x04u);
    TEST_CHECK(NPU_ENGINE_DATA_CME_OUTPUT_RANGE ==
               NPU_ENGINE_DATA_CME_CLIPPED_OR_RANGE);
    TEST_CHECK(NPU_ENGINE_DATA_CME_INT_SATURATED ==
               NPU_ENGINE_DATA_CME_OUTPUT_RANGE);
    TEST_CHECK(NPU_ENGINE_DATA_CME_FP_INF == 0x08u);
    TEST_CHECK(NPU_ENGINE_DATA_CME_FP_NAN == 0x10u);
    TEST_CHECK(NPU_ENGINE_DATA_CME_DIVIDE_BY_ZERO ==
               0x20u);
    TEST_CHECK(
        adapter.cme_numeric_flags_latched ==
        (NPU_ENGINE_DATA_CME_ALL_MASK |
         NPU_ENGINE_DATA_CME_OUTPUT_RANGE |
         NPU_ENGINE_DATA_CME_FP_INF |
         NPU_ENGINE_DATA_CME_FP_NAN |
         NPU_ENGINE_DATA_CME_DIVIDE_BY_ZERO));

    complex_accept_model.internal_bus_trace = (void *)0;
    npu_bus_trace_end(&adapter.trace);
    return 0;
}

int test_complex_acceptance(void)
{
    int line;

    line = complex_accept_activations();
    if (line != 0) {
        return line;
    }
    line = complex_accept_round_modes();
    if (line != 0) {
        return line;
    }
    line = complex_accept_shapes_and_tail();
    if (line != 0) {
        return line;
    }
    line = complex_accept_softmax_dtypes();
    if (line != 0) {
        return line;
    }
    line = complex_accept_layernorm_dtypes();
    if (line != 0) {
        return line;
    }
    line = complex_accept_rmsnorm_dtypes();
    if (line != 0) {
        return line;
    }
    line = complex_accept_add_rescale_dtypes();
    if (line != 0) {
        return line;
    }
    line = complex_accept_statistics();
    if (line != 0) {
        return line;
    }
    line = complex_accept_stat_overflow();
    if (line != 0) {
        return line;
    }
    line = complex_accept_numeric_flag_latching();
    if (line != 0) {
        return line;
    }
    return 0;
}

#ifdef NPU_COMPLEX_ACCEPTANCE_STANDALONE
int main(void)
{
    int line = test_complex_acceptance();

    if (line == 0) {
        (void)printf("[PASS] complex_acceptance\n");
        return 0;
    }
    (void)printf(
        "[FAIL] complex_acceptance at test line %d\n", line);
    return 1;
}
#endif
