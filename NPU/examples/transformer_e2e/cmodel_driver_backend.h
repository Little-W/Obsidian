#ifndef TRANSFORMER_CMODEL_DRIVER_BACKEND_H
#define TRANSFORMER_CMODEL_DRIVER_BACKEND_H

#include "npu_cmodel.h"
#include "npu_driver.h"

#include <stddef.h>
#include <stdint.h>

typedef struct {
    npu_model_t model;
    uint32_t cache_clean_calls;
    uint32_t cache_invalidate_calls;
    uint32_t submitted_beats;
    uint32_t responses;
} transformer_cmodel_backend_t;

int transformer_cmodel_backend_init(transformer_cmodel_backend_t *backend,
                                    uint8_t *l1,
                                    size_t l1_bytes,
                                    uint8_t *ddr,
                                    size_t ddr_bytes);

npu_drv_platform_ops_t
transformer_cmodel_backend_operations(transformer_cmodel_backend_t *backend);

#endif
