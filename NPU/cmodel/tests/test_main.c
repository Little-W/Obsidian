#include "test_util.h"

#include <stdio.h>

typedef int (*test_function_t)(void);

typedef struct {
    const char *name;
    test_function_t function;
} test_case_t;

void test_clear_bytes(uint8_t *memory, size_t bytes)
{
    size_t index;
    for (index = 0u; index < bytes; index++) {
        memory[index] = 0u;
    }
}

float test_abs_float(float value)
{
    return value < 0.0f ? -value : value;
}

npu_tensor_t test_tensor(npu_dtype_t dtype,
                         uint64_t addr,
                         uint64_t region_bytes,
                         uint32_t row_stride)
{
    npu_tensor_t tensor;
    tensor.space = NPU_SPACE_L1;
    tensor.dtype = dtype;
    tensor.addr = addr;
    tensor.region_bytes = region_bytes;
    tensor.row_stride_bytes = row_stride;
    tensor.elem_stride_bytes = 0u;
    tensor.batch_stride_bytes = 0u;
    tensor.start_nibble = 0u;
    return tensor;
}

npu_task_request_t test_base_request(npu_engine_t engine,
                                     uint8_t opcode,
                                     uint16_t command_id)
{
    npu_task_request_t request = {0};
    request.cmd.desc_addr = 0u;
    request.cmd.command_id = command_id;
    request.cmd.engine = engine;
    request.cmd.opcode = opcode;
    request.cmd.header_flags = 0u;
    request.cmd.wait_event[0] = npu_event_none();
    request.cmd.wait_event[1] = npu_event_none();
    request.cmd.signal_event = npu_event_none();
    request.cmd.header_version = 1u;
    request.cmd.timeout_class = 0u;
    request.cmd.user_tag = command_id;
    return request;
}

int main(void)
{
    static const test_case_t tests[] = {
        {"bits", test_bits},
        {"bus_trace", test_bus_trace},
        {"bus_replay_cycle", test_bus_replay_cycle},
        {"dma", test_dma},
        {"dma_acceptance", test_dma_acceptance},
        {"int16", test_int16},
        {"dtype_regression", test_dtype_regression},
        {"matrix", test_matrix},
        {"matrix_tiles", test_matrix_tiles},
        {"matrix_acceptance", test_matrix_acceptance},
        {"matrix_pipeline", test_matrix_pipeline},
        {"keras_mlp_inference", test_keras_mlp_inference},
        {"keras_sequence_inference",
         test_keras_sequence_inference},
        {"vector", test_vector},
        {"vector_acceptance", test_vector_acceptance},
        {"math", test_math},
        {"math_accuracy", test_math_accuracy},
        {"complex", test_complex},
        {"complex_acceptance", test_complex_acceptance},
        {"scheduler", test_scheduler},
        {"frontend", test_frontend},
        {"wire", test_wire},
        {"inline", test_inline},
        {"wire_e2e", test_wire_e2e},
        {"control_cycle", test_control_cycle},
        {"cfe_cycle", test_cfe_cycle},
        {"issue_adapter_cycle", test_issue_adapter_cycle},
        {"l1_cycle", test_l1_cycle},
        {"l1_diag_bridge", test_l1_diag_bridge},
        {"lsc_cycle", test_lsc_cycle},
        {"gc_axi_cycle", test_gc_axi_cycle},
        {"axi_mem_target_cycle", test_axi_mem_target_cycle},
        {"mif_cycle", test_mif_cycle},
        {"mif_cdc_cycle", test_mif_cdc_cycle},
        {"sys_slave_cycle", test_sys_slave_cycle},
        {"engine_cycle", test_engine_cycle},
        {"engine_data_cycle", test_engine_data_cycle},
        {"ts_cycle", test_ts_cycle},
        {"core_top_cycle", test_core_top_cycle},
        {"single_core_cycle", test_single_core_cycle},
        {"single_core_axi_target",
         test_single_core_axi_target},
        {"properties", test_properties}
    };
    unsigned int index;
    int line;
    int failures = 0;

    for (index = 0u;
         index < (unsigned int)(sizeof(tests) / sizeof(tests[0]));
         index++) {
        line = tests[index].function();
        if (line == 0) {
            (void)printf("[PASS] %s\n", tests[index].name);
        } else {
            (void)printf("[FAIL] %s at test line %d\n",
                         tests[index].name, line);
            failures++;
        }
    }
    (void)printf("%u tests, %d failures\n",
                 (unsigned int)(sizeof(tests) / sizeof(tests[0])),
                 failures);
    return failures == 0 ? 0 : 1;
}
