#ifndef NPU_ENGINE_DATA_CYCLE_H
#define NPU_ENGINE_DATA_CYCLE_H

#include "npu_bus_replay_cycle.h"
#include "npu_engine_cycle.h"

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Local read-port meanings:
 *
 * DMA:    0=L1 source
 * Matrix: 0=A, 1=B, 2=bias/residual/requant
 * Vector: 0=src0, 1=src1, 2=src2, 3=mask
 * Complex:0=src0, 1=src1/parameter, 2=src2, 3=mask/valid length
 */
#define NPU_ENGINE_DATA_READ_PORTS 4u

/*
 * cme_numeric_flag bits are sticky for the current task. Bits 0 through 2
 * retain their original values for source compatibility; bits 3 through 5
 * add independent FP event indications.
 */
#define NPU_ENGINE_DATA_CME_NUMERIC_EXCEPTION 0x01u
#define NPU_ENGINE_DATA_CME_ALL_MASK 0x02u
#define NPU_ENGINE_DATA_CME_CLIPPED_OR_RANGE 0x04u
#define NPU_ENGINE_DATA_CME_OUTPUT_RANGE \
    NPU_ENGINE_DATA_CME_CLIPPED_OR_RANGE
#define NPU_ENGINE_DATA_CME_INT_SATURATED \
    NPU_ENGINE_DATA_CME_CLIPPED_OR_RANGE
#define NPU_ENGINE_DATA_CME_FP_INF 0x08u
#define NPU_ENGINE_DATA_CME_FP_NAN 0x10u
#define NPU_ENGINE_DATA_CME_DIVIDE_BY_ZERO 0x20u

typedef struct {
    npu_bus_trace_entry_t *read_entries;
    size_t read_capacity;
    uint32_t *read_hash;
    size_t read_hash_slots;
    npu_bus_trace_entry_t *write_entries;
    size_t write_capacity;
    uint32_t *write_hash;
    size_t write_hash_slots;
} npu_engine_data_workspace_t;

typedef struct {
    npu_engine_cycle_inputs_t engine;
    /*
     * LSC parameter-region configuration sampled before any externally
     * visible data request is emitted for the decoded task.
     */
    uint32_t param_l1_base;
    uint32_t param_l1_limit;
    uint8_t param_lock;
    npu_l1_cycle_read_output_t
        l1_read[NPU_ENGINE_DATA_READ_PORTS];
    npu_l1_cycle_write_output_t l1_write;
    npu_mif_owner_outputs_t mif;
} npu_engine_data_cycle_inputs_t;

typedef struct {
    npu_engine_cycle_outputs_t engine;
    npu_l1_cycle_read_input_t
        l1_read[NPU_ENGINE_DATA_READ_PORTS];
    npu_l1_cycle_write_input_t l1_write;
    npu_mif_owner_inputs_t mif;

    uint8_t data_busy;
    uint8_t data_quiescent;
    uint8_t l1_stall;
    uint8_t mif_stall;

    uint8_t dma_idle;
    uint8_t dma_busy;
    uint8_t me_mac_active;
    uint8_t me_operand_stall;
    uint8_t me_write_stall;
    uint8_t me_acc_overflow;
    uint8_t ive_alu_active;
    uint8_t ive_l1_stall;
    uint8_t ive_overflow;
    uint8_t ive_lane_valid;
    uint8_t cme_i2f_active;
    uint8_t cme_fp_active;
    uint8_t cme_f2i_active;
    uint8_t cme_l1_stall;
    uint8_t cme_numeric_flag;

    uint8_t trace_overflow;
    size_t captured_read_words;
    size_t captured_write_words;
    uint64_t cycle;
} npu_engine_data_cycle_outputs_t;

typedef enum {
    NPU_ENGINE_DATA_COMPUTE_DONE = 0,
    NPU_ENGINE_DATA_COMPUTE_ME = 1,
    NPU_ENGINE_DATA_COMPUTE_IVE = 2,
    NPU_ENGINE_DATA_COMPUTE_CME_PIPELINE = 3
} npu_engine_data_compute_stage_t;

/*
 * ME, IVE, and single-pass CME operations use verified read-response credits.
 * A logical arithmetic group may start while later source responses are
 * still arriving. Multi-pass CME operations retain an after-read compute
 * interval because the access trace does not yet identify row-local
 * dependencies between passes.
 *
 * ME emits one MAC-active cycle for each valid (Batch, M tile, N tile,
 * K tile) group. GEMM_ZERO emits none. IVE emits one cycle per element group;
 * ive_lane_valid identifies the exact valid lanes, including the final group.
 * Direct CME operations use token pipelines with I2F, function, and F2I
 * latencies. Softmax and normalization use the explicit reference work
 * formulas in npu_engine_data_prepare_compute(); those formulas describe
 * activity scheduling, not another numeric implementation. VSTAT is integer
 * work and has no I2F, FP, or F2I activity.
 *
 * The functional operator still calculates its final result atomically while
 * capturing the access trace. These signals model the externally observable
 * arithmetic schedule; they do not recalculate the result from response data.
 */

typedef struct {
    npu_engine_cycle_t engine;
    npu_bus_trace_t trace;
    npu_bus_replay_cycle_t replay;
    npu_engine_data_workspace_t workspace;

    npu_perf_t perf_delta;
    uint8_t workspace_bound;
    uint8_t data_pending;
    uint8_t data_done_released;
    uint8_t perf_delta_valid;
    uint8_t initialized;

    npu_engine_data_compute_stage_t compute_stage;
    uint64_t compute_stage_remaining;
    uint64_t compute_groups;
    uint64_t compute_groups_issued;
    uint32_t compute_lanes;
    uint8_t compute_full_lane_mask;
    uint8_t compute_tail_lane_mask;
    uint64_t compute_elapsed;
    uint64_t compute_total_cycles;
    uint64_t cme_i2f_start;
    uint64_t cme_i2f_cycles;
    uint64_t cme_fp_start;
    uint64_t cme_fp_cycles;
    uint64_t cme_f2i_start;
    uint64_t cme_f2i_cycles;
    uint8_t stream_compute;
    uint8_t cme_direct_stream;
    uint8_t cme_direct_fp_latency;
    uint64_t cme_i2f_tokens;
    uint64_t cme_fp_tokens;
    uint64_t cme_f2i_tokens;

    uint8_t me_acc_overflow_latched;
    uint8_t ive_overflow_latched;
    uint8_t cme_numeric_flags_latched;

    uint64_t cycle;
} npu_engine_data_cycle_t;

npu_status_t npu_engine_data_cycle_init(
    npu_engine_data_cycle_t *model,
    npu_model_t *functional_model,
    npu_engine_t engine,
    const npu_wire_limits_t *limits);

/*
 * Workspace arrays remain caller-owned. Binding is accepted only while the
 * wrapper is idle. Read capacity covers aligned source words after combining
 * accesses within each read pass; the same word in another pass consumes
 * another entry. Write capacity covers distinct destination words. The
 * validation function only reads the workspace description and never changes
 * the entry or hash arrays.
 */
int npu_engine_data_workspace_valid(
    const npu_engine_data_workspace_t *workspace);

int npu_engine_data_cycle_bind_workspace(
    npu_engine_data_cycle_t *model,
    const npu_engine_data_workspace_t *workspace);

/*
 * Functional operator integration hooks. They are no-ops unless
 * functional_model is executing under an active Engine Data capture.
 */
void npu_engine_data_record_integer_range(
    const npu_model_t *functional_model,
    npu_dtype_t dtype);

void npu_engine_data_record_cme_numeric(
    const npu_model_t *functional_model,
    uint8_t flags);

void npu_engine_data_cycle_reset(
    npu_engine_data_cycle_t *model);

void npu_engine_data_cycle_step(
    npu_engine_data_cycle_t *model,
    const npu_engine_data_cycle_inputs_t *inputs,
    npu_engine_data_cycle_outputs_t *outputs);

/*
 * Produces current-cycle signals without executing a functional operator,
 * changing memory, recording accesses, or changing performance counters.
 */
void npu_engine_data_cycle_eval(
    const npu_engine_data_cycle_t *model,
    const npu_engine_data_cycle_inputs_t *inputs,
    npu_engine_data_cycle_outputs_t *outputs);

#ifdef __cplusplus
}
#endif

#endif
