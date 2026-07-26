#include "npu_driver.h"

#include <inttypes.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    npu_drv_cmd_fields_t fields;
    npu_drv_cmd128_t command;
    uint16_t a;
    uint16_t b;
    uint16_t c;

    memset(&fields, 0, sizeof(fields));
    if (npu_drv_lref_encode(0x1000u, 6u, 14u, &a) != NPU_DRV_OK ||
        npu_drv_lref_encode(0x2000u, 6u, 14u, &b) != NPU_DRV_OK ||
        npu_drv_lref_encode(0x3000u, 6u, 14u, &c) != NPU_DRV_OK ||
        npu_drv_matrix_gemm_payload_encode(
            a,
            NPU_DRV_DTYPE_INT16,
            b,
            NPU_DRV_DTYPE_INT16,
            c,
            NPU_DRV_DTYPE_INT16,
            0u,
            8u,
            8u,
            8u,
            8u,
            &fields.payload) != NPU_DRV_OK) {
        return 1;
    }
    fields.command_id = 7u;
    fields.compact_opcode = NPU_DRV_COMPACT_MATRIX_GEMM;
    fields.dtype = NPU_DRV_DTYPE_INT16;
    fields.wait_event[0].id = NPU_DRV_EVENT_NONE;
    fields.wait_event[1].id = NPU_DRV_EVENT_NONE;
    fields.signal_event.id = NPU_DRV_EVENT_NONE;
    if (npu_drv_cmd128_encode(&fields, &command) != NPU_DRV_OK) {
        return 1;
    }
    printf("CMD FIFO offset: 0x%06" PRIx32
           " AWBURST=FIXED beats=2\n",
           NPU_DRV_CMD_FIFO_DATA);
    printf("beat[0] CMD low : 0x%016" PRIx64 "\n", command.lo);
    printf("beat[1] CMD high: 0x%016" PRIx64 " WLAST=1\n", command.hi);
    return 0;
}
