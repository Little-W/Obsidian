#ifndef NPU_CMODEL_INTERNAL_H
#define NPU_CMODEL_INTERNAL_H

#include "npu_bus_trace.h"
#include "npu_cmodel.h"

typedef struct {
    uint8_t valid;
    npu_space_t space;
    uint64_t addr;
} npu_fault_capture_t;

void npu_fault_capture_record(const npu_model_t *model,
                              npu_space_t space,
                              uint64_t addr);

int npu_model_trace_next_read_pass(npu_model_t *model);
uint8_t npu_model_trace_set_read_capture(
    npu_model_t *model,
    uint8_t enable);

uint64_t npu_ceil_div_u64(uint64_t value, uint64_t divisor);
uint32_t npu_dtype_bits(npu_dtype_t dtype);
uint32_t npu_dtype_bytes(npu_dtype_t dtype);
int npu_dtype_valid(npu_dtype_t dtype);

npu_status_t npu_memory_read_u8(const npu_model_t *model,
                                npu_space_t space,
                                uint64_t addr,
                                uint8_t *value);
npu_status_t npu_memory_write_u8(npu_model_t *model,
                                 npu_space_t space,
                                 uint64_t addr,
                                 uint8_t value);
npu_status_t npu_memory_read_i16(const npu_model_t *model,
                                 npu_space_t space,
                                 uint64_t addr,
                                 int32_t *value);
npu_status_t npu_memory_write_i16(npu_model_t *model,
                                  npu_space_t space,
                                  uint64_t addr,
                                  int32_t value);
npu_status_t npu_memory_read_i32(const npu_model_t *model,
                                 npu_space_t space,
                                 uint64_t addr,
                                 int32_t *value);
npu_status_t npu_memory_write_i32(npu_model_t *model,
                                  npu_space_t space,
                                  uint64_t addr,
                                  int32_t value);
npu_status_t npu_memory_read_u32(const npu_model_t *model,
                                 npu_space_t space,
                                 uint64_t addr,
                                 uint32_t *value);
int npu_memory_range_valid(const npu_model_t *model,
                           npu_space_t space,
                           uint64_t addr,
                           uint64_t bytes);
int npu_regions_overlap(uint64_t addr0,
                        uint64_t bytes0,
                        uint64_t addr1,
                        uint64_t bytes1);
npu_status_t npu_tensor_location(const npu_model_t *model,
                                 const npu_tensor_t *tensor,
                                 uint32_t batch,
                                 uint32_t row,
                                 uint32_t element,
                                 uint64_t *byte_addr,
                                 uint8_t *high_nibble);
void npu_clear_int4_tail(npu_model_t *model,
                         const npu_tensor_t *tensor,
                         uint32_t batch,
                         uint32_t row,
                         uint32_t length);

npu_status_t npu_execute_task(npu_model_t *model,
                              npu_task_slot_t *slot);
uint64_t npu_task_desc_beats(npu_engine_t engine);

#endif
