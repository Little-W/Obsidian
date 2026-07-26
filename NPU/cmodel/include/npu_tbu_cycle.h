#ifndef NPU_TBU_CYCLE_H
#define NPU_TBU_CYCLE_H

#include "npu_cmodel.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_TBU_OUTSTANDING 8u
#define NPU_TBU_RULE_COUNT 64u
#define NPU_TBU_HIT_LATENCY 4u
#define NPU_TBU_MISS_LATENCY 64u
#define NPU_TBU_INVALID_SLOT 0xffu
#define NPU_TBU_VADDR_MASK UINT64_C(0x0000ffffffffffff)
#define NPU_TBU_PADDR_MASK UINT64_C(0x000000ffffffffff)
#define NPU_TBU_VPAGE_MASK UINT64_C(0x0000000fffffffff)
#define NPU_TBU_PPAGE_MASK UINT32_C(0x0fffffff)

typedef struct {
    uint8_t valid;
    uint64_t virtual_page;
    uint32_t physical_page;
    uint16_t stream_id;
    uint16_t substream_id;
    uint8_t read_enable;
    uint8_t write_enable;
} npu_tbu_rule_t;

typedef struct {
    uint8_t reset_n;

    uint8_t req_valid;
    uint64_t req_vaddr;
    uint8_t req_write;
    uint16_t req_stream_id;
    uint16_t req_substream_id;
    uint16_t req_tag;

    uint8_t rsp_ready;
} npu_tbu_cycle_inputs_t;

typedef struct {
    uint8_t req_ready;

    uint8_t rsp_valid;
    uint64_t rsp_paddr;
    uint16_t rsp_tag;
    uint8_t rsp_status;

    uint8_t idle;
    uint8_t outstanding;
    uint64_t cycle_count;
} npu_tbu_cycle_outputs_t;

typedef struct {
    uint8_t valid;
    uint16_t tag;
    uint8_t status;
    uint64_t paddr;
    uint16_t remaining_cycles;
    uint64_t sequence;
} npu_tbu_request_entry_t;

typedef struct {
    npu_tbu_rule_t rules[NPU_TBU_RULE_COUNT];
    npu_tbu_request_entry_t requests[NPU_TBU_OUTSTANDING];
    uint64_t next_sequence;
    uint64_t cycle_count;
    uint8_t initialized;
} npu_tbu_cycle_t;

void npu_tbu_cycle_init(npu_tbu_cycle_t *model);

/*
 * Reset discards requests and held responses, while keeping the programmed
 * test rules. Page-table ownership is outside the NPU reset domain.
 */
void npu_tbu_cycle_reset(npu_tbu_cycle_t *model);

/*
 * Test rules may be changed only while no request is outstanding. A virtual
 * page is vaddr[47:12], and a physical page is paddr[39:12].
 */
int npu_tbu_cycle_set_rule(npu_tbu_cycle_t *model,
                           uint8_t index,
                           const npu_tbu_rule_t *rule);

void npu_tbu_cycle_eval(const npu_tbu_cycle_t *model,
                        const npu_tbu_cycle_inputs_t *inputs,
                        npu_tbu_cycle_outputs_t *outputs);

void npu_tbu_cycle_step(npu_tbu_cycle_t *model,
                        const npu_tbu_cycle_inputs_t *inputs,
                        npu_tbu_cycle_outputs_t *outputs);

#ifdef __cplusplus
}
#endif

#endif
