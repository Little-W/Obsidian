#ifndef NPU_INLINE_H
#define NPU_INLINE_H

#include "npu_wire.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NPU_INLINE_FORMAT_VERSION 2u
#define NPU_INLINE_EVENT_NONE UINT8_C(0xff)

int npu_inline_opcode_decode(uint8_t compact_opcode,
                             npu_engine_t *engine,
                             uint8_t *opcode);

int npu_inline_opcode_encode(npu_engine_t engine,
                             uint8_t opcode,
                             uint8_t *compact_opcode);

npu_status_t npu_inline_decode_task(
    const npu_cmd_t *cmd,
    const npu_wire_limits_t *limits,
    npu_task_request_t *request,
    npu_wire_meta_t *meta);

#ifdef __cplusplus
}
#endif

#endif
