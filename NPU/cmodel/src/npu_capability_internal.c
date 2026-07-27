#include "npu_capability_internal.h"

#include "npu_cfe_cycle.h"
#include "npu_l1_cycle.h"
#include "npu_mif_cycle.h"
#include "npu_ts_cycle.h"

static uint64_t npu_capability_field(
    uint64_t value,
    uint8_t shift,
    uint64_t mask)
{
    return (value >> shift) & mask;
}

int npu_capability_config_match(
    const npu_model_t *functional_model,
    const npu_wire_limits_t *wire,
    const npu_lsc_cycle_config_t *lsc,
    uint8_t full_single_core)
{
    const npu_config_t *functional;
    const uint64_t bus_used_mask =
        (NPU_LSC_FIELD_U8_MASK <<
         NPU_LSC_BUS_DATA_BITS_SHIFT) |
        (NPU_LSC_FIELD_U8_MASK <<
         NPU_LSC_BUS_GADDR_BITS_SHIFT) |
        (NPU_LSC_FIELD_U8_MASK <<
         NPU_LSC_BUS_PA_BITS_SHIFT) |
        (NPU_LSC_FIELD_U8_MASK <<
         NPU_LSC_BUS_AXI_ID_BITS_SHIFT);
    const uint64_t l1_used_mask =
        (NPU_LSC_FIELD_U32_MASK <<
         NPU_LSC_L1_BYTES_SHIFT) |
        (NPU_LSC_FIELD_U8_MASK <<
         NPU_LSC_L1_BANKS_SHIFT) |
        (NPU_LSC_FIELD_U8_MASK <<
         NPU_LSC_L1_READ_LATENCY_SHIFT);
    const uint64_t matrix_used_mask =
        (NPU_LSC_FIELD_U8_MASK <<
         NPU_LSC_MATRIX_MT_SHIFT) |
        (NPU_LSC_FIELD_U8_MASK <<
         NPU_LSC_MATRIX_KT_SHIFT) |
        (NPU_LSC_FIELD_U8_MASK <<
         NPU_LSC_MATRIX_NT_SHIFT) |
        (NPU_LSC_MATRIX_DTYPE_MASK <<
         NPU_LSC_MATRIX_DTYPE_MASK_SHIFT);
    const uint64_t vector_used_mask =
        (NPU_LSC_FIELD_U8_MASK <<
         NPU_LSC_VECTOR_LANES_SHIFT) |
        (NPU_LSC_VECTOR_OPCODE_MASK <<
         NPU_LSC_VECTOR_OPCODE_MASK_SHIFT);
    const uint64_t cme_used_mask =
        (NPU_LSC_FIELD_U8_MASK <<
         NPU_LSC_CME_FP32_LANES_SHIFT) |
        (NPU_LSC_CME_FUNCTION_MASK <<
         NPU_LSC_CME_FUNCTION_MASK_SHIFT) |
        (NPU_LSC_CME_APPROX_MASK <<
         NPU_LSC_CME_APPROX_MASK_SHIFT) |
        (NPU_LSC_FIELD_U16_MASK <<
         NPU_LSC_CME_SCRATCH_ELEMS_SHIFT);
    uint32_t timeout_class;

    if (functional_model == (const npu_model_t *)0 ||
        wire == (const npu_wire_limits_t *)0 ||
        lsc == (const npu_lsc_cycle_config_t *)0) {
        return 0;
    }
    functional = &functional_model->config;
    if (wire->l1_bytes == 0u ||
        wire->l1_bytes > (1u << 24) ||
        wire->gaddr_limit == 0u ||
        wire->gaddr_limit > (UINT64_C(1) << 40) ||
        wire->gaddr_limit > functional_model->ddr_size ||
        wire->dma_max_burst_beats == 0u ||
        wire->dma_max_burst_beats > 256u ||
        wire->dma_max_outstanding == 0u ||
        wire->mt == 0u ||
        wire->kt == 0u ||
        wire->nt == 0u ||
        wire->cme_scratch_elems == 0u ||
        functional->task_entries != NPU_TS_TASK_COUNT ||
        functional->descriptor_slots !=
            NPU_TS_DESC_SLOT_COUNT ||
        functional->cfe_fifo_depth !=
            NPU_CFE_CYCLE_FIFO_DEPTH ||
        functional->l1_bytes != wire->l1_bytes ||
        functional->mt != wire->mt ||
        functional->kt != wire->kt ||
        functional->nt != wire->nt ||
        functional->dma_outstanding !=
            wire->dma_max_outstanding ||
        functional->dma_max_burst_beats !=
            wire->dma_max_burst_beats ||
        functional->cme_scratch_elems !=
            wire->cme_scratch_elems ||
        wire->desc_version !=
            NPU_WIRE_DEFAULT_DESC_VERSION ||
        (lsc->isa_feature &
         ~NPU_LSC_IMPLEMENTED_ISA_FEATURES) != 0u ||
        (lsc->bus_config & ~bus_used_mask) != 0u ||
        (lsc->l1_config & ~l1_used_mask) != 0u ||
        (lsc->matrix_config & ~matrix_used_mask) != 0u ||
        (lsc->vector_config & ~vector_used_mask) != 0u ||
        (lsc->cme_config & ~cme_used_mask) != 0u ||
        lsc->l1_bytes != functional->l1_bytes ||
        npu_capability_field(
            lsc->bus_config,
            NPU_LSC_BUS_DATA_BITS_SHIFT,
            NPU_LSC_FIELD_U8_MASK) !=
            NPU_REF_BUS_DATA_BITS ||
        npu_capability_field(
            lsc->bus_config,
            NPU_LSC_BUS_GADDR_BITS_SHIFT,
            NPU_LSC_FIELD_U8_MASK) != 48u ||
        npu_capability_field(
            lsc->bus_config,
            NPU_LSC_BUS_PA_BITS_SHIFT,
            NPU_LSC_FIELD_U8_MASK) != 40u ||
        npu_capability_field(
            lsc->bus_config,
            NPU_LSC_BUS_AXI_ID_BITS_SHIFT,
            NPU_LSC_FIELD_U8_MASK) != 8u ||
        npu_capability_field(
            lsc->l1_config,
            NPU_LSC_L1_BYTES_SHIFT,
            NPU_LSC_FIELD_U32_MASK) !=
            functional->l1_bytes ||
        npu_capability_field(
            lsc->l1_config,
            NPU_LSC_L1_BANKS_SHIFT,
            NPU_LSC_FIELD_U8_MASK) !=
            functional->l1_banks ||
        npu_capability_field(
            lsc->l1_config,
            NPU_LSC_L1_READ_LATENCY_SHIFT,
            NPU_LSC_FIELD_U8_MASK) !=
            functional->l1_read_latency ||
        npu_capability_field(
            lsc->matrix_config,
            NPU_LSC_MATRIX_MT_SHIFT,
            NPU_LSC_FIELD_U8_MASK) != functional->mt ||
        npu_capability_field(
            lsc->matrix_config,
            NPU_LSC_MATRIX_KT_SHIFT,
            NPU_LSC_FIELD_U8_MASK) != functional->kt ||
        npu_capability_field(
            lsc->matrix_config,
            NPU_LSC_MATRIX_NT_SHIFT,
            NPU_LSC_FIELD_U8_MASK) != functional->nt ||
        npu_capability_field(
            lsc->matrix_config,
            NPU_LSC_MATRIX_DTYPE_MASK_SHIFT,
            NPU_LSC_MATRIX_DTYPE_MASK) !=
            NPU_LSC_MATRIX_DTYPE_MASK ||
        npu_capability_field(
            lsc->vector_config,
            NPU_LSC_VECTOR_LANES_SHIFT,
            NPU_LSC_FIELD_U8_MASK) !=
            functional->vector_lanes ||
        npu_capability_field(
            lsc->vector_config,
            NPU_LSC_VECTOR_OPCODE_MASK_SHIFT,
            NPU_LSC_VECTOR_OPCODE_MASK) !=
            NPU_LSC_VECTOR_OPCODE_MASK ||
        npu_capability_field(
            lsc->cme_config,
            NPU_LSC_CME_FP32_LANES_SHIFT,
            NPU_LSC_FIELD_U8_MASK) !=
            functional->cme_lanes ||
        npu_capability_field(
            lsc->cme_config,
            NPU_LSC_CME_FUNCTION_MASK_SHIFT,
            NPU_LSC_CME_FUNCTION_MASK) !=
            NPU_LSC_CME_FUNCTION_MASK ||
        npu_capability_field(
            lsc->cme_config,
            NPU_LSC_CME_APPROX_MASK_SHIFT,
            NPU_LSC_CME_APPROX_MASK) != 1u ||
        npu_capability_field(
            lsc->cme_config,
            NPU_LSC_CME_SCRATCH_ELEMS_SHIFT,
            NPU_LSC_FIELD_U16_MASK) !=
            functional->cme_scratch_elems) {
        return 0;
    }

    if (full_single_core != 0u &&
        (functional_model->ddr == (uint8_t *)0 ||
         functional->l1_bytes != NPU_L1_CYCLE_BYTES ||
         functional->l1_banks != NPU_L1_CYCLE_BANKS ||
         functional->l1_read_latency !=
             NPU_L1_CYCLE_READ_LATENCY ||
         functional->l1_starve_limit !=
             NPU_L1_CYCLE_STARVE_LIMIT ||
         functional->mif_outstanding !=
             NPU_MIF_MAX_AXI_OUTSTANDING)) {
        return 0;
    }

    for (timeout_class = 0u;
         timeout_class < NPU_LSC_TIMEOUT_CLASS_COUNT;
         timeout_class++) {
        if (lsc->timeout_reset[timeout_class] !=
            functional->timeout_cycles[timeout_class]) {
            return 0;
        }
    }
    return 1;
}
