#include "npu_driver_internal.h"

#include <string.h>

int npu_drv_init(npu_driver_t *driver,
                 const npu_drv_platform_ops_t *operations)
{
    if (driver == (npu_driver_t *)0 ||
        operations == (const npu_drv_platform_ops_t *)0) {
        return NPU_DRV_EINVAL;
    }
    memset(driver, 0, sizeof(*driver));
    driver->ops = *operations;
    return NPU_DRV_OK;
}

int npu_drv_reg_read(npu_driver_t *driver,
                     uint32_t offset,
                     uint64_t *value)
{
    if (driver == (npu_driver_t *)0 ||
        value == (uint64_t *)0 ||
        (offset & 7u) != 0u) {
        return NPU_DRV_EINVAL;
    }
    if (driver->ops.mmio_read64 == (void *)0) {
        return NPU_DRV_ENOTSUP;
    }
    return npu_drv_internal_platform_result(
        driver->ops.mmio_read64(
            driver->ops.context, offset, value));
}

int npu_drv_reg_write(npu_driver_t *driver,
                      uint32_t offset,
                      uint64_t value)
{
    int result;

    if (driver == (npu_driver_t *)0 || (offset & 7u) != 0u) {
        return NPU_DRV_EINVAL;
    }
    if (driver->ops.mmio_write64 == (void *)0) {
        return NPU_DRV_ENOTSUP;
    }
    result = driver->ops.mmio_write64(
        driver->ops.context, offset, value, NPU_DRV_FULL_WSTRB);
    return npu_drv_internal_platform_result(result);
}

int npu_drv_set_timeout(npu_driver_t *driver,
                        uint8_t timeout_class,
                        uint32_t cycles)
{
    if (timeout_class >= 16u) {
        return NPU_DRV_ERANGE;
    }
    return npu_drv_reg_write(
        driver,
        NPU_DRV_REG_TIMEOUT_BASE + (uint32_t)timeout_class * 8u,
        cycles);
}

static int npu_drv_global_address_register(uint32_t offset)
{
    return offset == NPU_DRV_REG_INPUT_BASE ||
           offset == NPU_DRV_REG_WEIGHT_BASE ||
           offset == NPU_DRV_REG_WORK_BASE ||
           offset == NPU_DRV_REG_OUTPUT_BASE ||
           offset == NPU_DRV_REG_KV_BASE ||
           offset == NPU_DRV_REG_M_AXI_ADDR_BASE ||
           offset == NPU_DRV_REG_M_AXI_ADDR_LIMIT;
}

static int npu_drv_l1_address_register(uint32_t offset)
{
    return offset == NPU_DRV_REG_PARAM_L1_BASE ||
           offset == NPU_DRV_REG_PARAM_L1_LIMIT;
}

int npu_drv_set_base(npu_driver_t *driver,
                     uint32_t register_offset,
                     uint64_t address)
{
    if ((address & 7u) != 0u) {
        return NPU_DRV_EINVAL;
    }
    if (npu_drv_global_address_register(register_offset)) {
        if ((address & ~NPU_DRV_PHYS_ADDR_MASK) != 0u) {
            return NPU_DRV_ERANGE;
        }
    } else if (npu_drv_l1_address_register(register_offset)) {
        if ((address & ~NPU_DRV_L1_ADDR_MASK) != 0u) {
            return NPU_DRV_ERANGE;
        }
    } else {
        return NPU_DRV_EINVAL;
    }
    return npu_drv_reg_write(driver, register_offset, address);
}

int npu_drv_start(npu_driver_t *driver)
{
    return npu_drv_reg_write(
        driver, NPU_DRV_REG_CORE_CONTROL, NPU_DRV_CORE_START);
}

int npu_drv_stop(npu_driver_t *driver)
{
    return npu_drv_reg_write(
        driver, NPU_DRV_REG_CORE_CONTROL, NPU_DRV_CORE_STOP);
}

int npu_drv_soft_reset(npu_driver_t *driver)
{
    return npu_drv_reg_write(
        driver, NPU_DRV_REG_CORE_CONTROL, NPU_DRV_CORE_SOFT_RESET);
}

int npu_drv_irq_enable(npu_driver_t *driver, uint64_t mask)
{
    if ((mask & ~NPU_DRV_IRQ_ALL) != 0u) {
        return NPU_DRV_EINVAL;
    }
    return npu_drv_reg_write(driver, NPU_DRV_REG_IRQ_MASK, mask);
}

int npu_drv_irq_ack(npu_driver_t *driver, uint64_t mask)
{
    if ((mask & ~NPU_DRV_IRQ_ALL) != 0u) {
        return NPU_DRV_EINVAL;
    }
    return npu_drv_reg_write(driver, NPU_DRV_REG_IRQ_STATUS, mask);
}

int npu_drv_fault_clear(npu_driver_t *driver)
{
    return npu_drv_reg_write(driver, NPU_DRV_REG_FAULT_CLEAR, 1u);
}
