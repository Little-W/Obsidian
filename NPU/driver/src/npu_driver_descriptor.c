#include "npu_driver_internal.h"

#include <string.h>

static int npu_drv_boolean(uint8_t value)
{
    return value <= 1u;
}

size_t npu_drv_desc_type_bytes(npu_drv_desc_type_t type)
{
    switch (type) {
    case NPU_DRV_DESC_CONTROL:
        return NPU_DRV_CONTROL_DESC_BYTES;
    case NPU_DRV_DESC_DMA:
        return NPU_DRV_DMA_DESC_BYTES;
    case NPU_DRV_DESC_MATRIX:
        return NPU_DRV_MATRIX_DESC_BYTES;
    case NPU_DRV_DESC_VECTOR:
        return NPU_DRV_VECTOR_DESC_BYTES;
    case NPU_DRV_DESC_COMPLEX:
        return NPU_DRV_COMPLEX_DESC_BYTES;
    default:
        return 0u;
    }
}

int npu_drv_desc_pool_init(npu_drv_desc_pool_t *pool,
                           void *cpu_base,
                           uint64_t device_base,
                           size_t bytes)
{
    if (pool == (npu_drv_desc_pool_t *)0 ||
        cpu_base == (void *)0 ||
        bytes == 0u ||
        (device_base & ~NPU_DRV_ADDR48_MASK) != 0u ||
        (device_base & (NPU_DRV_DESC_ALIGNMENT - 1u)) != 0u ||
        ((uintptr_t)cpu_base &
         (uintptr_t)(NPU_DRV_DESC_ALIGNMENT - 1u)) != 0u) {
        return NPU_DRV_EINVAL;
    }
    pool->cpu_base = (uint8_t *)cpu_base;
    pool->device_base = device_base;
    pool->bytes = bytes;
    pool->used = 0u;
    return NPU_DRV_OK;
}

void npu_drv_desc_pool_reset(npu_drv_desc_pool_t *pool)
{
    if (pool != (npu_drv_desc_pool_t *)0) {
        pool->used = 0u;
    }
}

int npu_drv_desc_alloc(npu_drv_desc_pool_t *pool,
                       npu_drv_desc_type_t type,
                       npu_drv_desc_allocation_t *allocation)
{
    size_t descriptor_bytes;
    size_t offset;

    if (pool == (npu_drv_desc_pool_t *)0 ||
        allocation == (npu_drv_desc_allocation_t *)0) {
        return NPU_DRV_EINVAL;
    }
    descriptor_bytes = npu_drv_desc_type_bytes(type);
    if (descriptor_bytes == 0u) {
        return NPU_DRV_EINVAL;
    }
    offset = (pool->used + NPU_DRV_DESC_ALIGNMENT - 1u) &
             ~(size_t)(NPU_DRV_DESC_ALIGNMENT - 1u);
    if (offset > pool->bytes ||
        descriptor_bytes > pool->bytes - offset ||
        pool->device_base > NPU_DRV_ADDR48_MASK - offset ||
        descriptor_bytes - 1u >
            NPU_DRV_ADDR48_MASK - (pool->device_base + offset)) {
        return NPU_DRV_ENOMEM;
    }
    allocation->cpu_address = pool->cpu_base + offset;
    allocation->device_address = pool->device_base + offset;
    allocation->bytes = descriptor_bytes;
    memset(allocation->cpu_address, 0, descriptor_bytes);
    pool->used = offset + descriptor_bytes;
    return NPU_DRV_OK;
}

int npu_drv_desc_common_encode(void *descriptor,
                               size_t descriptor_bytes,
                               const npu_drv_desc_common_t *fields)
{
    uint32_t numeric;
    size_t expected;

    if (descriptor == (void *)0 ||
        fields == (const npu_drv_desc_common_t *)0) {
        return NPU_DRV_EINVAL;
    }
    expected = npu_drv_desc_type_bytes(fields->desc_type);
    if (expected == 0u ||
        descriptor_bytes != expected ||
        fields->desc_version != 1u ||
        (fields->src0_addr & ~NPU_DRV_ADDR48_MASK) != 0u ||
        (fields->src1_addr & ~NPU_DRV_ADDR48_MASK) != 0u ||
        (fields->src2_addr & ~NPU_DRV_ADDR48_MASK) != 0u ||
        (fields->dst_addr & ~NPU_DRV_ADDR48_MASK) != 0u ||
        (fields->aux0_addr & ~NPU_DRV_ADDR48_MASK) != 0u ||
        (fields->aux1_addr & ~NPU_DRV_ADDR48_MASK) != 0u ||
        fields->src0_dtype > NPU_DRV_DTYPE_INT16 ||
        fields->src1_dtype > NPU_DRV_DTYPE_INT16 ||
        fields->src2_dtype > NPU_DRV_DTYPE_INT16 ||
        fields->dst_dtype > NPU_DRV_DTYPE_INT16 ||
        fields->round_mode > 3u ||
        fields->scale_mode > 3u ||
        !npu_drv_boolean(fields->saturate_enable) ||
        !npu_drv_boolean(fields->zero_point_enable) ||
        !npu_drv_boolean(fields->internal_fp32_enable)) {
        return NPU_DRV_EINVAL;
    }
    memset(descriptor, 0, descriptor_bytes);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x00u,
        fields->desc_version);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x01u,
        (uint8_t)fields->desc_type);
    (void)npu_drv_desc_write_u16(
        descriptor, descriptor_bytes, 0x02u,
        (uint16_t)descriptor_bytes);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x04u,
        fields->op_flags);
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0x08u,
        fields->src0_addr);
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0x10u,
        fields->src1_addr);
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0x18u,
        fields->src2_addr);
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0x20u,
        fields->dst_addr);
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0x28u,
        fields->aux0_addr);
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0x30u,
        fields->aux1_addr);
    numeric =
        (uint32_t)fields->src0_dtype |
        ((uint32_t)fields->src1_dtype << 2u) |
        ((uint32_t)fields->src2_dtype << 4u) |
        ((uint32_t)fields->dst_dtype << 6u) |
        ((uint32_t)fields->round_mode << 10u) |
        ((uint32_t)fields->saturate_enable << 12u) |
        ((uint32_t)fields->scale_mode << 13u) |
        ((uint32_t)fields->zero_point_enable << 15u) |
        ((uint32_t)fields->internal_fp32_enable << 16u);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x38u, numeric);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x3cu,
        fields->user_tag);
    return NPU_DRV_OK;
}

int npu_drv_desc_dma_encode(void *descriptor,
                            size_t descriptor_bytes,
                            const npu_drv_desc_common_t *common,
                            const npu_drv_dma_fields_t *fields)
{
    uint32_t index;
    int result;

    if (common == (const npu_drv_desc_common_t *)0 ||
        fields == (const npu_drv_dma_fields_t *)0 ||
        common->desc_type != NPU_DRV_DESC_DMA ||
        descriptor_bytes != NPU_DRV_DMA_DESC_BYTES ||
        fields->rank == 0u || fields->rank > 5u ||
        fields->src_space > 1u || fields->dst_space > 1u ||
        fields->convert_mode > 3u ||
        fields->burst_beats == 0u ||
        fields->max_outstanding == 0u ||
        fields->src_nibble > 1u || fields->dst_nibble > 1u) {
        return NPU_DRV_EINVAL;
    }
    result = npu_drv_desc_common_encode(
        descriptor, descriptor_bytes, common);
    if (result != NPU_DRV_OK) {
        return result;
    }
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x40u, fields->rank);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x41u, fields->src_space);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x42u, fields->dst_space);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x43u, fields->convert_mode);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x44u,
        (uint8_t)(fields->burst_beats - 1u));
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x45u,
        fields->max_outstanding);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x46u,
        fields->src_nibble);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x47u,
        fields->dst_nibble);
    for (index = 0u; index < 5u; index++) {
        (void)npu_drv_desc_write_u32(
            descriptor, descriptor_bytes,
            0x48u + index * 4u, fields->shape[index]);
        (void)npu_drv_desc_write_u32(
            descriptor, descriptor_bytes,
            0x60u + index * 4u,
            fields->src_stride_bytes[index]);
        (void)npu_drv_desc_write_u32(
            descriptor, descriptor_bytes,
            0x78u + index * 4u,
            fields->dst_stride_bytes[index]);
    }
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0x90u,
        fields->fill_value);
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0x98u,
        fields->src_region_bytes);
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0xa0u,
        fields->dst_region_bytes);
    (void)npu_drv_desc_write_u16(
        descriptor, descriptor_bytes, 0xa8u,
        fields->segment_count);
    (void)npu_drv_desc_write_u16(
        descriptor, descriptor_bytes, 0xaau,
        fields->segment_bytes);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0xacu,
        fields->segment_stride);
    return NPU_DRV_OK;
}

int npu_drv_desc_matrix_encode(void *descriptor,
                               size_t descriptor_bytes,
                               const npu_drv_desc_common_t *common,
                               const npu_drv_matrix_fields_t *fields)
{
    int result;

    if (common == (const npu_drv_desc_common_t *)0 ||
        fields == (const npu_drv_matrix_fields_t *)0 ||
        common->desc_type != NPU_DRV_DESC_MATRIX ||
        descriptor_bytes != NPU_DRV_MATRIX_DESC_BYTES ||
        fields->batch_count == 0u ||
        (fields->flags & 0xffffff00u) != 0u ||
        fields->overflow_mode > 2u ||
        fields->activation_mode > 1u ||
        fields->requant_mode > 2u ||
        fields->residual_mode > 1u) {
        return NPU_DRV_EINVAL;
    }
    result = npu_drv_desc_common_encode(
        descriptor, descriptor_bytes, common);
    if (result != NPU_DRV_OK) {
        return result;
    }
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x40u, fields->m);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x44u, fields->n);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x48u, fields->k);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x4cu,
        fields->batch_count);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x50u,
        fields->last_tile_valid_m);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x54u,
        fields->last_tile_valid_n);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x58u,
        fields->last_tile_valid_k);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x5cu, fields->flags);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x60u,
        fields->lda_bytes);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x64u,
        fields->ldb_bytes);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x68u,
        fields->ldc_bytes);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x6cu,
        fields->bias_stride_bytes);
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0x70u,
        fields->a_batch_stride_bytes);
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0x78u,
        fields->b_batch_stride_bytes);
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0x80u,
        fields->c_batch_stride_bytes);
    (void)npu_drv_desc_write_u64(
        descriptor, descriptor_bytes, 0x88u,
        fields->src2_batch_stride_bytes);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x90u,
        fields->a_pack_format);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x91u,
        fields->b_pack_format);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x92u,
        fields->c_pack_format);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x93u,
        fields->pack_version);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x94u,
        fields->overflow_mode);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0x95u,
        fields->activation_mode);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x98u,
        (uint32_t)fields->output_zero_point);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0x9cu,
        fields->requant_count);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0xa0u,
        fields->bias_count);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0xa4u,
        fields->requant_mode);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0xa5u,
        fields->residual_mode);
    (void)npu_drv_desc_write_u8(
        descriptor, descriptor_bytes, 0xa6u,
        fields->requant_entry_bytes);
    (void)npu_drv_desc_write_u32(
        descriptor, descriptor_bytes, 0xa8u,
        fields->requant_region_bytes);
    return NPU_DRV_OK;
}
