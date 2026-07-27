#ifndef NPU_DRIVER_INTERNAL_H
#define NPU_DRIVER_INTERNAL_H

#include "npu_driver.h"

static inline int npu_drv_internal_platform_result(int callback_result)
{
    return callback_result == 0 ? NPU_DRV_OK : NPU_DRV_EIO;
}

#endif /* NPU_DRIVER_INTERNAL_H */
