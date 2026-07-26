#include "npu_driver_internal.h"

static int npu_drv_range(size_t total, size_t offset, size_t bytes)
{
    return offset <= total && bytes <= total - offset;
}

int npu_drv_sync_for_device(npu_driver_t *driver,
                            const void *address,
                            size_t bytes)
{
    if (driver == (npu_driver_t *)0 ||
        (bytes != 0u && address == (const void *)0)) {
        return NPU_DRV_EINVAL;
    }
    if (bytes != 0u && driver->ops.cache_clean != (void *)0) {
        driver->ops.cache_clean(driver->ops.context, address, bytes);
    }
    if (driver->ops.write_barrier != (void *)0) {
        driver->ops.write_barrier(driver->ops.context);
    }
    return NPU_DRV_OK;
}

int npu_drv_sync_for_cpu(npu_driver_t *driver,
                         void *address,
                         size_t bytes)
{
    if (driver == (npu_driver_t *)0 ||
        (bytes != 0u && address == (void *)0)) {
        return NPU_DRV_EINVAL;
    }
    if (bytes != 0u && driver->ops.cache_invalidate != (void *)0) {
        driver->ops.cache_invalidate(
            driver->ops.context, address, bytes);
    }
    if (driver->ops.read_barrier != (void *)0) {
        driver->ops.read_barrier(driver->ops.context);
    }
    return NPU_DRV_OK;
}

int npu_drv_desc_write_u8(void *descriptor,
                          size_t descriptor_bytes,
                          size_t offset,
                          uint8_t value)
{
    if (descriptor == (void *)0 ||
        !npu_drv_range(descriptor_bytes, offset, 1u)) {
        return NPU_DRV_ERANGE;
    }
    ((uint8_t *)descriptor)[offset] = value;
    return NPU_DRV_OK;
}

int npu_drv_desc_write_u16(void *descriptor,
                           size_t descriptor_bytes,
                           size_t offset,
                           uint16_t value)
{
    uint8_t *data;

    if (descriptor == (void *)0 ||
        !npu_drv_range(descriptor_bytes, offset, 2u)) {
        return NPU_DRV_ERANGE;
    }
    data = (uint8_t *)descriptor + offset;
    data[0] = (uint8_t)value;
    data[1] = (uint8_t)(value >> 8u);
    return NPU_DRV_OK;
}

int npu_drv_desc_write_u32(void *descriptor,
                           size_t descriptor_bytes,
                           size_t offset,
                           uint32_t value)
{
    uint8_t *data;
    uint32_t index;

    if (descriptor == (void *)0 ||
        !npu_drv_range(descriptor_bytes, offset, 4u)) {
        return NPU_DRV_ERANGE;
    }
    data = (uint8_t *)descriptor + offset;
    for (index = 0u; index < 4u; index++) {
        data[index] = (uint8_t)(value >> (index * 8u));
    }
    return NPU_DRV_OK;
}

int npu_drv_desc_write_u64(void *descriptor,
                           size_t descriptor_bytes,
                           size_t offset,
                           uint64_t value)
{
    uint8_t *data;
    uint32_t index;

    if (descriptor == (void *)0 ||
        !npu_drv_range(descriptor_bytes, offset, 8u)) {
        return NPU_DRV_ERANGE;
    }
    data = (uint8_t *)descriptor + offset;
    for (index = 0u; index < 8u; index++) {
        data[index] = (uint8_t)(value >> (index * 8u));
    }
    return NPU_DRV_OK;
}
