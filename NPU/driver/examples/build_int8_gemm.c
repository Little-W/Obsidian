#include "npu_driver.h"

#include <inttypes.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    _Alignas(64) uint8_t descriptor_memory[256];
    npu_drv_desc_pool_t pool;
    npu_drv_desc_allocation_t allocation;
    npu_drv_desc_common_t common;
    npu_drv_matrix_fields_t matrix;
    npu_drv_cmd_fields_t fields;
    npu_drv_cmd128_t command;

    if (npu_drv_desc_pool_init(
            &pool,
            descriptor_memory,
            UINT64_C(0x100000),
            sizeof(descriptor_memory)) != NPU_DRV_OK ||
        npu_drv_desc_alloc(
            &pool,
            NPU_DRV_DESC_MATRIX,
            &allocation) != NPU_DRV_OK) {
        return 1;
    }

    memset(&common, 0, sizeof(common));
    common.desc_version = 1u;
    common.desc_type = NPU_DRV_DESC_MATRIX;
    common.src0_addr = UINT64_C(0x1000);
    common.src1_addr = UINT64_C(0x2000);
    common.dst_addr = UINT64_C(0x3000);
    common.aux1_addr = UINT64_C(0x4000);
    common.src0_dtype = NPU_DRV_DTYPE_INT8;
    common.src1_dtype = NPU_DRV_DTYPE_INT8;
    common.src2_dtype = NPU_DRV_DTYPE_INT4;
    common.dst_dtype = NPU_DRV_DTYPE_INT8;
    common.saturate_enable = 1u;
    common.user_tag = UINT32_C(0x52454731);

    memset(&matrix, 0, sizeof(matrix));
    matrix.m = 8u;
    matrix.n = 8u;
    matrix.k = 8u;
    matrix.batch_count = 1u;
    matrix.last_tile_valid_m = 8u;
    matrix.last_tile_valid_n = 8u;
    matrix.last_tile_valid_k = 8u;
    matrix.flags = (1u << 5u) | (1u << 7u);
    matrix.lda_bytes = 8u;
    matrix.ldc_bytes = 8u;
    matrix.a_pack_format = NPU_DRV_PACK_LINEAR_INT8;
    matrix.b_pack_format = NPU_DRV_PACK_TILED_INT8;
    matrix.c_pack_format = NPU_DRV_PACK_LINEAR_INT8;
    matrix.pack_version = 0u;
    matrix.requant_mode = 1u;
    matrix.requant_count = 1u;
    matrix.requant_entry_bytes = 8u;
    matrix.requant_region_bytes = 8u;
    if (npu_drv_desc_matrix_encode(
            allocation.cpu_address,
            allocation.bytes,
            &common,
            &matrix) != NPU_DRV_OK) {
        return 1;
    }

    memset(&fields, 0, sizeof(fields));
    fields.descriptor_addr = allocation.device_address;
    fields.command_id = 7u;
    fields.engine = NPU_DRV_ENGINE_MATRIX;
    fields.opcode = 0x40u;
    fields.wait_event[0].id = 255u;
    fields.wait_event[0].generation = 15u;
    fields.wait_event[1] = fields.wait_event[0];
    fields.signal_event = fields.wait_event[0];
    if (npu_drv_cmd128_encode(&fields, &command) != NPU_DRV_OK) {
        return 1;
    }

    printf("CMD FIFO offset: 0x%06" PRIx32
           " AWBURST=FIXED beats=2\n",
           NPU_DRV_CMD_FIFO_DATA);
    printf("beat[0] CMD low : 0x%016" PRIx64 "\n", command.lo);
    printf("beat[1] CMD high: 0x%016" PRIx64 " WLAST=1\n", command.hi);
    printf("Descriptor device address: 0x%012" PRIx64 "\n",
           allocation.device_address);
    return 0;
}
