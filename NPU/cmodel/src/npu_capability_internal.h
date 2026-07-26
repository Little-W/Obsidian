#ifndef NPU_CAPABILITY_INTERNAL_H
#define NPU_CAPABILITY_INTERNAL_H

#include "npu_cmodel.h"
#include "npu_lsc_cycle.h"
#include "npu_wire.h"

#include <stdint.h>

/*
 * Checks that the functional, wire-decoder, and LSC descriptions advertise
 * one coherent implementation. full_single_core also checks parameters that
 * are fixed by the concrete L1 and MIF modules.
 */
int npu_capability_config_match(
    const npu_model_t *functional_model,
    const npu_wire_limits_t *wire,
    const npu_lsc_cycle_config_t *lsc,
    uint8_t full_single_core);

#endif
