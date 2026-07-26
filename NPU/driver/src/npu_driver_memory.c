#include "npu_driver_internal.h"

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
