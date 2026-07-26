#ifndef NPU_CMODEL_TEST_UTIL_H
#define NPU_CMODEL_TEST_UTIL_H

#include "npu_cmodel.h"

#define TEST_CHECK(condition)       \
    do {                            \
        if (!(condition)) {         \
            return __LINE__;        \
        }                           \
    } while (0)

#define TEST_CHECK_STATUS(actual, expected) \
    TEST_CHECK((actual) == (expected))

void test_clear_bytes(uint8_t *memory, size_t bytes);
float test_abs_float(float value);
npu_tensor_t test_tensor(npu_dtype_t dtype,
                         uint64_t addr,
                         uint64_t region_bytes,
                         uint32_t row_stride);
npu_task_request_t test_base_request(npu_engine_t engine,
                                     uint8_t opcode,
                                     uint16_t command_id);

int test_bits(void);
int test_bus_trace(void);
int test_bus_replay_cycle(void);
int test_dma(void);
int test_dma_acceptance(void);
int test_int16(void);
int test_dtype_regression(void);
int test_matrix(void);
int test_matrix_tiles(void);
int test_matrix_acceptance(void);
int test_matrix_pipeline(void);
int test_keras_mlp_inference(void);
int test_keras_sequence_inference(void);
int test_vector(void);
int test_vector_acceptance(void);
int test_math(void);
int test_math_accuracy(void);
int test_complex(void);
int test_complex_acceptance(void);
int test_scheduler(void);
int test_frontend(void);
int test_wire(void);
int test_inline(void);
int test_wire_e2e(void);
int test_control_cycle(void);
int test_cfe_cycle(void);
int test_issue_adapter_cycle(void);
int test_l1_cycle(void);
int test_l1_diag_bridge(void);
int test_lsc_cycle(void);
int test_tbu_cycle(void);
int test_mif_tbu_cycle(void);
int test_gc_axi_cycle(void);
int test_axi_mem_target_cycle(void);
int test_mif_cycle(void);
int test_mif_cdc_cycle(void);
int test_sys_slave_cycle(void);
int test_engine_cycle(void);
int test_engine_data_cycle(void);
int test_ts_cycle(void);
int test_core_top_cycle(void);
int test_single_core_cycle(void);
int test_single_core_axi_target(void);
int test_properties(void);

#endif
