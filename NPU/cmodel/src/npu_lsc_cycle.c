#include "npu_lsc_cycle.h"

#include <stddef.h>
#include <string.h>

#define NPU_LSC_STATUS_SUCCESS 0x00u
#define NPU_LSC_STATUS_BAD_DESC 0x02u
#define NPU_LSC_STATUS_TIMEOUT 0x09u
#define NPU_LSC_STATUS_NUMERIC_EXCEPTION 0x0cu
#define NPU_LSC_STATUS_WDT 0x09u
#define NPU_LSC_STATUS_LAST_ERROR 0x0du
#define NPU_LSC_EXTERNAL_COMMAND_ID 0x0fffu

static uint64_t npu_lsc_strobe_mask(uint8_t strobe)
{
    uint64_t mask = 0u;
    uint32_t byte_index;

    for (byte_index = 0u; byte_index < 8u; byte_index++) {
        if ((strobe & (uint8_t)(1u << byte_index)) != 0u) {
            mask |= UINT64_C(0xff) << (byte_index * 8u);
        }
    }
    return mask;
}

static uint64_t npu_lsc_merge_write(uint64_t old_value,
                                    uint64_t write_data,
                                    uint8_t write_strobe)
{
    uint64_t mask = npu_lsc_strobe_mask(write_strobe);
    return (old_value & ~mask) | (write_data & mask);
}

static uint8_t npu_lsc_core_idle(const npu_lsc_cycle_inputs_t *inputs)
{
    return (uint8_t)(inputs->issue_idle != 0u &&
                     inputs->cfe_idle != 0u &&
                     inputs->ts_idle != 0u &&
                     (inputs->eng_quiescent & 0x0fu) == 0x0fu &&
                     inputs->l1_idle != 0u &&
                     inputs->mif_idle != 0u &&
                     inputs->gc_axi_idle != 0u);
}

static uint8_t npu_lsc_drain_idle(const npu_lsc_cycle_inputs_t *inputs)
{
    return (uint8_t)(inputs->issue_idle != 0u &&
                     inputs->cfe_idle != 0u &&
                     inputs->ts_quiescent != 0u &&
                     (inputs->eng_quiescent & 0x0fu) == 0x0fu &&
                     inputs->l1_idle != 0u &&
                     inputs->l1_write_idle != 0u &&
                     inputs->mif_idle != 0u &&
                     inputs->gc_axi_idle != 0u);
}

static uint64_t npu_lsc_version_value(const npu_lsc_cycle_t *model)
{
    return ((uint64_t)(model->config.version_major & UINT32_C(0xffff))) |
           ((uint64_t)(model->config.version_minor & UINT32_C(0xffff))
            << 16u) |
           ((uint64_t)model->config.build << 32u);
}

static uint64_t npu_lsc_core_control_value(
    const npu_lsc_cycle_t *model)
{
    uint64_t value = 0u;
    if (model->started != 0u) {
        value |= NPU_LSC_CORE_CONTROL_START;
    }
    if (model->stopped != 0u) {
        value |= NPU_LSC_CORE_CONTROL_STOP;
    }
    return value;
}

static uint64_t npu_lsc_core_status_value(
    const npu_lsc_cycle_t *model,
    const npu_lsc_cycle_inputs_t *inputs)
{
    uint64_t value = 0u;
    uint8_t idle = npu_lsc_core_idle(inputs);

    if (idle != 0u) {
        value |= NPU_LSC_CORE_STATUS_IDLE;
    } else {
        value |= NPU_LSC_CORE_STATUS_BUSY;
    }
    if (inputs->core_wfi != 0u) {
        value |= NPU_LSC_CORE_STATUS_WFI;
    }
    if (model->fault_valid != 0u) {
        value |= NPU_LSC_CORE_STATUS_ERROR;
    }
    if (idle != 0u && model->stopped != 0u) {
        value |= NPU_LSC_CORE_STATUS_POWER_READY;
    }
    if (model->soft_state != NPU_LSC_SOFT_IDLE) {
        value |= NPU_LSC_CORE_STATUS_SOFT_RESET_BUSY;
    }
    return value;
}

static int npu_lsc_perf_index(uint16_t address)
{
    uint16_t offset;

    if (address < NPU_LSC_REG_PERF_BASE ||
        address >= NPU_LSC_REG_PERF_BASE +
                       NPU_LSC_PERF_COUNTER_COUNT * 8u) {
        return -1;
    }
    offset = (uint16_t)(address - NPU_LSC_REG_PERF_BASE);
    if ((offset & 7u) != 0u) {
        return -1;
    }
    return (int)(offset / 8u);
}

static int npu_lsc_timeout_index(uint16_t address)
{
    uint16_t offset;

    if (address < NPU_LSC_REG_TIMEOUT_BASE ||
        address >= NPU_LSC_REG_TIMEOUT_BASE +
                       NPU_LSC_TIMEOUT_CLASS_COUNT * 8u) {
        return -1;
    }
    offset = (uint16_t)(address - NPU_LSC_REG_TIMEOUT_BASE);
    if ((offset & 7u) != 0u) {
        return -1;
    }
    return (int)(offset / 8u);
}

static uint64_t npu_lsc_fault_info(const npu_lsc_cycle_t *model)
{
    if (model->fault_valid == 0u) {
        return 0u;
    }
    return (uint64_t)model->fault_status |
           ((uint64_t)(model->fault_engine & 0x0fu) << 8u) |
           ((uint64_t)model->fault_opcode << 12u);
}

static uint64_t npu_lsc_fault_detail(const npu_lsc_cycle_t *model)
{
    if (model->fault_valid == 0u) {
        return 0u;
    }
    return (uint64_t)model->fault_error_info |
           ((uint64_t)model->fault_done_flags << 32u);
}

static uint8_t npu_lsc_external_status(
    const npu_lsc_external_error_input_t *error)
{
    if (error->status == NPU_LSC_STATUS_SUCCESS ||
        error->status > NPU_LSC_STATUS_LAST_ERROR) {
        return NPU_LSC_STATUS_BAD_DESC;
    }
    return error->status;
}

static uint32_t npu_lsc_external_error_info(
    uint8_t source,
    const npu_lsc_external_error_input_t *error)
{
    return ((uint32_t)NPU_LSC_EXTERNAL_ERROR_STAGE << 28u) |
           ((uint32_t)(source & 0x0fu)
            << NPU_LSC_EXTERNAL_SOURCE_SHIFT) |
           ((uint32_t)error->detail
            << NPU_LSC_EXTERNAL_DETAIL_SHIFT) |
           ((uint32_t)error->aux
            << NPU_LSC_EXTERNAL_AUX_SHIFT) |
           (uint32_t)error->status;
}

static uint64_t npu_lsc_read_register(
    const npu_lsc_cycle_t *model,
    const npu_lsc_cycle_inputs_t *inputs,
    uint8_t space,
    uint16_t address)
{
    int index;

    if (space != 0u) {
        index = npu_lsc_perf_index(address);
        if (index >= 0) {
            return model->perf_counter[(uint32_t)index];
        }
        if (address == NPU_LSC_REG_PERF_CONTROL) {
            return model->perf_frozen != 0u ?
                       NPU_LSC_PERF_FREEZE : 0u;
        }
        return 0u;
    }
    index = npu_lsc_timeout_index(address);
    if (index >= 0) {
        return model->timeout_cycles[(uint32_t)index];
    }
    switch (address) {
    case NPU_LSC_REG_NPU_VERSION:
        return npu_lsc_version_value(model);
    case NPU_LSC_REG_ISA_FEATURE:
        return model->config.isa_feature;
    case NPU_LSC_REG_BUS_CONFIG:
        return model->config.bus_config;
    case NPU_LSC_REG_L1_CONFIG:
        return model->config.l1_config;
    case NPU_LSC_REG_MATRIX_CONFIG:
        return model->config.matrix_config;
    case NPU_LSC_REG_VECTOR_CONFIG:
        return model->config.vector_config;
    case NPU_LSC_REG_CME_CONFIG:
        return model->config.cme_config;
    case NPU_LSC_REG_CORE_CONTROL:
        return npu_lsc_core_control_value(model);
    case NPU_LSC_REG_CORE_STATUS:
        return npu_lsc_core_status_value(model, inputs);
    case NPU_LSC_REG_RESERVED_0050:
        return 0u;
    case NPU_LSC_REG_INPUT_BASE:
        return model->input_base;
    case NPU_LSC_REG_WEIGHT_BASE:
        return model->weight_base;
    case NPU_LSC_REG_WORK_BASE:
        return model->work_base;
    case NPU_LSC_REG_OUTPUT_BASE:
        return model->output_base;
    case NPU_LSC_REG_KV_BASE:
        return model->kv_base;
    case NPU_LSC_REG_M_AXI_ADDR_BASE:
        return model->m_axi_addr_base;
    case NPU_LSC_REG_M_AXI_ADDR_LIMIT:
        return model->m_axi_addr_limit;
    case NPU_LSC_REG_IRQ_STATUS:
        return model->irq_status;
    case NPU_LSC_REG_IRQ_MASK:
        return model->irq_mask;
    case NPU_LSC_REG_FAULT_CMD:
        return model->fault_valid != 0u ?
                   model->fault_command_id : 0u;
    case NPU_LSC_REG_FAULT_ADDR:
        return model->fault_valid != 0u ?
                   model->fault_addr : 0u;
    case NPU_LSC_REG_FAULT_INFO:
        return npu_lsc_fault_info(model);
    case NPU_LSC_REG_PARAM_L1_BASE:
        return model->param_l1_base;
    case NPU_LSC_REG_PARAM_L1_LIMIT:
        return model->param_l1_limit;
    case NPU_LSC_REG_PARAM_LOCK:
        return model->param_lock;
    case NPU_LSC_REG_RESET_REASON:
        return model->reset_reason;
    case NPU_LSC_REG_L1_DIAG_CONTROL:
        return model->l1_diag_enable != 0u ?
                   NPU_LSC_L1_DIAG_ENABLE : 0u;
    case NPU_LSC_REG_FAULT_DETAIL:
        return npu_lsc_fault_detail(model);
    default:
        return 0u;
    }
}

static uint8_t npu_lsc_gaddr_valid(uint64_t address)
{
    return (uint8_t)((address & UINT64_C(0xffffff0000000000)) == 0u &&
                     (address & 7u) == 0u);
}

static uint8_t npu_lsc_pa_valid(uint64_t address)
{
    return (uint8_t)((address & UINT64_C(0xffffff0000000000)) == 0u &&
                     (address & 7u) == 0u);
}

static uint8_t npu_lsc_write_core_control(
    npu_lsc_cycle_t *model,
    uint64_t data,
    uint8_t strobe,
    uint8_t core_idle)
{
    uint64_t value = data & npu_lsc_strobe_mask(strobe);
    uint8_t next_started = model->started;
    uint8_t next_stopped = model->stopped;

    if ((value & ~(NPU_LSC_CORE_CONTROL_START |
                   NPU_LSC_CORE_CONTROL_STOP |
                   NPU_LSC_CORE_CONTROL_SOFT_RESET |
                   NPU_LSC_CORE_CONTROL_SINGLE_STEP)) != 0u ||
        ((value & NPU_LSC_CORE_CONTROL_START) != 0u &&
         (value & NPU_LSC_CORE_CONTROL_STOP) != 0u)) {
        return NPU_LSC_REG_SLVERR;
    }

    if ((value & NPU_LSC_CORE_CONTROL_START) != 0u) {
        if (model->soft_state != NPU_LSC_SOFT_IDLE ||
            model->power_state != NPU_LSC_POWER_IDLE) {
            return NPU_LSC_REG_SLVERR;
        }
        next_started = 1u;
        next_stopped = 0u;
    }
    if ((value & NPU_LSC_CORE_CONTROL_STOP) != 0u) {
        next_started = 0u;
        next_stopped = 1u;
    }
    if ((value & NPU_LSC_CORE_CONTROL_SINGLE_STEP) != 0u) {
        if (next_stopped == 0u || core_idle == 0u) {
            return NPU_LSC_REG_SLVERR;
        }
    }
    if ((value & NPU_LSC_CORE_CONTROL_SOFT_RESET) != 0u) {
        if (model->soft_state != NPU_LSC_SOFT_IDLE) {
            return NPU_LSC_REG_SLVERR;
        }
        next_started = 0u;
        next_stopped = 1u;
    }

    model->started = next_started;
    model->stopped = next_stopped;
    if ((value & NPU_LSC_CORE_CONTROL_SINGLE_STEP) != 0u) {
        model->single_step_pulse = 1u;
    }
    if ((value & NPU_LSC_CORE_CONTROL_SOFT_RESET) != 0u) {
        model->soft_state = NPU_LSC_SOFT_DRAIN;
        model->soft_external_request = 0u;
    }
    return NPU_LSC_REG_OKAY;
}

static uint8_t npu_lsc_write_base(uint64_t *target,
                                  uint64_t data,
                                  uint8_t strobe,
                                  uint8_t core_idle)
{
    uint64_t merged;

    if (core_idle == 0u) {
        return NPU_LSC_REG_SLVERR;
    }
    merged = npu_lsc_merge_write(*target, data, strobe);
    if (npu_lsc_gaddr_valid(merged) == 0u) {
        return NPU_LSC_REG_SLVERR;
    }
    *target = merged;
    return NPU_LSC_REG_OKAY;
}

static uint8_t npu_lsc_write_param_address(
    npu_lsc_cycle_t *model,
    uint16_t address,
    uint64_t data,
    uint8_t strobe,
    uint8_t core_idle)
{
    uint64_t old_value;
    uint64_t merged;
    uint32_t new_value;

    if (core_idle == 0u || model->param_lock != 0u) {
        return NPU_LSC_REG_SLVERR;
    }
    old_value = address == NPU_LSC_REG_PARAM_L1_BASE ?
                    model->param_l1_base : model->param_l1_limit;
    merged = npu_lsc_merge_write(old_value, data, strobe);
    if ((merged >> 24u) != 0u || (merged & 7u) != 0u ||
        merged > model->config.l1_bytes) {
        return NPU_LSC_REG_SLVERR;
    }
    new_value = (uint32_t)merged;
    if (address == NPU_LSC_REG_PARAM_L1_BASE) {
        if (new_value > model->param_l1_limit) {
            return NPU_LSC_REG_SLVERR;
        }
        model->param_l1_base = new_value;
    } else {
        if (new_value < model->param_l1_base) {
            return NPU_LSC_REG_SLVERR;
        }
        model->param_l1_limit = new_value;
    }
    return NPU_LSC_REG_OKAY;
}

static uint8_t npu_lsc_write_register(
    npu_lsc_cycle_t *model,
    const npu_lsc_cycle_inputs_t *inputs,
    uint8_t space,
    uint16_t address,
    uint64_t data,
    uint8_t strobe)
{
    uint8_t core_idle = npu_lsc_core_idle(inputs);
    uint64_t merged;
    int index;

    if (space != 0u) {
        index = npu_lsc_perf_index(address);
        if (index >= 0) {
            model->perf_counter[(uint32_t)index] &=
                ~(data & npu_lsc_strobe_mask(strobe));
            return NPU_LSC_REG_OKAY;
        }
        if (address == NPU_LSC_REG_PERF_CONTROL) {
            merged = data & npu_lsc_strobe_mask(strobe);
            if ((merged & ~(NPU_LSC_PERF_FREEZE |
                            NPU_LSC_PERF_CLEAR)) != 0u) {
                return NPU_LSC_REG_SLVERR;
            }
            if ((merged & NPU_LSC_PERF_CLEAR) != 0u) {
                (void)memset(model->perf_counter, 0,
                             sizeof(model->perf_counter));
            }
            if ((strobe & 1u) != 0u) {
                model->perf_frozen =
                    (uint8_t)((data & NPU_LSC_PERF_FREEZE) != 0u);
            }
            return NPU_LSC_REG_OKAY;
        }
        return NPU_LSC_REG_OKAY;
    }
    index = npu_lsc_timeout_index(address);
    if (index >= 0) {
        if (core_idle == 0u) {
            return NPU_LSC_REG_SLVERR;
        }
        merged = npu_lsc_merge_write(
            model->timeout_cycles[(uint32_t)index], data, strobe);
        if ((merged >> 32u) != 0u) {
            return NPU_LSC_REG_SLVERR;
        }
        model->timeout_cycles[(uint32_t)index] = (uint32_t)merged;
        return NPU_LSC_REG_OKAY;
    }
    switch (address) {
    case NPU_LSC_REG_CORE_CONTROL:
        return npu_lsc_write_core_control(model, data, strobe,
                                          core_idle);
    case NPU_LSC_REG_RESERVED_0050:
        return NPU_LSC_REG_OKAY;
    case NPU_LSC_REG_INPUT_BASE:
        return npu_lsc_write_base(&model->input_base, data, strobe,
                                  core_idle);
    case NPU_LSC_REG_WEIGHT_BASE:
        return npu_lsc_write_base(&model->weight_base, data, strobe,
                                  core_idle);
    case NPU_LSC_REG_WORK_BASE:
        return npu_lsc_write_base(&model->work_base, data, strobe,
                                  core_idle);
    case NPU_LSC_REG_OUTPUT_BASE:
        return npu_lsc_write_base(&model->output_base, data, strobe,
                                  core_idle);
    case NPU_LSC_REG_KV_BASE:
        return npu_lsc_write_base(&model->kv_base, data, strobe,
                                  core_idle);
    case NPU_LSC_REG_M_AXI_ADDR_BASE:
        if (core_idle == 0u) {
            return NPU_LSC_REG_SLVERR;
        }
        merged = npu_lsc_merge_write(model->m_axi_addr_base,
                                     data, strobe);
        if (npu_lsc_pa_valid(merged) == 0u ||
            merged > model->m_axi_addr_limit) {
            return NPU_LSC_REG_SLVERR;
        }
        model->m_axi_addr_base = merged;
        return NPU_LSC_REG_OKAY;
    case NPU_LSC_REG_M_AXI_ADDR_LIMIT:
        if (core_idle == 0u) {
            return NPU_LSC_REG_SLVERR;
        }
        merged = npu_lsc_merge_write(model->m_axi_addr_limit,
                                     data, strobe);
        if (npu_lsc_pa_valid(merged) == 0u ||
            merged < model->m_axi_addr_base) {
            return NPU_LSC_REG_SLVERR;
        }
        model->m_axi_addr_limit = merged;
        return NPU_LSC_REG_OKAY;
    case NPU_LSC_REG_IRQ_STATUS:
        model->irq_status &=
            ~(data & npu_lsc_strobe_mask(strobe) &
              NPU_LSC_IRQ_ALL);
        return NPU_LSC_REG_OKAY;
    case NPU_LSC_REG_IRQ_MASK:
        merged = npu_lsc_merge_write(model->irq_mask, data, strobe);
        if ((merged & ~NPU_LSC_IRQ_ALL) != 0u) {
            return NPU_LSC_REG_SLVERR;
        }
        model->irq_mask = merged;
        return NPU_LSC_REG_OKAY;
    case NPU_LSC_REG_FAULT_CLEAR:
        if ((data & npu_lsc_strobe_mask(strobe) & 1u) != 0u) {
            model->fault_valid = 0u;
            model->fault_command_id = 0u;
            model->fault_addr = 0u;
            model->fault_status = 0u;
            model->fault_engine = 0u;
            model->fault_opcode = 0u;
            model->fault_source = NPU_LSC_FAULT_SOURCE_TASK;
            model->fault_error_info = 0u;
            model->fault_done_flags = 0u;
            model->external_error_clear_pulse = 1u;
        }
        return NPU_LSC_REG_OKAY;
    case NPU_LSC_REG_PARAM_L1_BASE:
    case NPU_LSC_REG_PARAM_L1_LIMIT:
        return npu_lsc_write_param_address(
            model, address, data, strobe, core_idle);
    case NPU_LSC_REG_PARAM_LOCK:
        merged = data & npu_lsc_strobe_mask(strobe);
        if ((merged & ~UINT64_C(1)) != 0u) {
            return NPU_LSC_REG_SLVERR;
        }
        if ((merged & 1u) != 0u) {
            if (core_idle == 0u || inputs->l1_write_idle == 0u ||
                model->param_l1_base > model->param_l1_limit) {
                return NPU_LSC_REG_SLVERR;
            }
            model->param_lock = 1u;
        }
        return NPU_LSC_REG_OKAY;
    case NPU_LSC_REG_L1_DIAG_CONTROL:
        if (core_idle == 0u) {
            return NPU_LSC_REG_SLVERR;
        }
        merged = npu_lsc_merge_write(
            model->l1_diag_enable != 0u ?
                NPU_LSC_L1_DIAG_ENABLE : 0u,
            data, strobe);
        if ((merged & ~NPU_LSC_L1_DIAG_ENABLE) != 0u) {
            return NPU_LSC_REG_SLVERR;
        }
        model->l1_diag_enable =
            (uint8_t)((merged & NPU_LSC_L1_DIAG_ENABLE) != 0u);
        return NPU_LSC_REG_OKAY;
    case NPU_LSC_REG_NPU_VERSION:
    case NPU_LSC_REG_ISA_FEATURE:
    case NPU_LSC_REG_BUS_CONFIG:
    case NPU_LSC_REG_L1_CONFIG:
    case NPU_LSC_REG_MATRIX_CONFIG:
    case NPU_LSC_REG_VECTOR_CONFIG:
    case NPU_LSC_REG_CME_CONFIG:
    case NPU_LSC_REG_CORE_STATUS:
    case NPU_LSC_REG_FAULT_CMD:
    case NPU_LSC_REG_FAULT_ADDR:
    case NPU_LSC_REG_FAULT_INFO:
    case NPU_LSC_REG_FAULT_DETAIL:
    case NPU_LSC_REG_RESET_REASON:
        return NPU_LSC_REG_SLVERR;
    default:
        return NPU_LSC_REG_OKAY;
    }
}

static void npu_lsc_record_fault(npu_lsc_cycle_t *model,
                                 uint16_t command_id,
                                 uint8_t status,
                                 uint8_t engine,
                                 uint8_t opcode,
                                 uint64_t address,
                                 uint8_t source,
                                 uint32_t error_info,
                                 uint16_t done_flags)
{
    if (model->fault_valid != 0u) {
        return;
    }
    model->fault_valid = 1u;
    model->fault_command_id = (uint16_t)(command_id & 0x0fffu);
    model->fault_status = status;
    model->fault_engine = (uint8_t)(engine & 0x0fu);
    model->fault_opcode = opcode;
    model->fault_addr = address;
    model->fault_source = source;
    model->fault_error_info = error_info;
    model->fault_done_flags = done_flags;
}

static void npu_lsc_record_external_fault(
    npu_lsc_cycle_t *model,
    uint8_t source,
    const npu_lsc_external_error_input_t *error)
{
    uint16_t command_id = NPU_LSC_EXTERNAL_COMMAND_ID;
    uint8_t engine = 0u;
    uint8_t opcode = 0u;

    if (error->has_task_identity != 0u) {
        command_id = error->command_id;
        engine = error->engine;
        opcode = error->opcode;
    }
    npu_lsc_record_fault(
        model, command_id, npu_lsc_external_status(error),
        engine, opcode, error->addr,
        source, npu_lsc_external_error_info(source, error), 0u);
}

static void npu_lsc_process_events(npu_lsc_cycle_t *model,
                                   const npu_lsc_cycle_inputs_t *inputs,
                                   uint8_t external_clear_active)
{
    if (inputs->task_terminal_valid != 0u) {
        if (inputs->task_status == NPU_LSC_STATUS_SUCCESS) {
            if (inputs->task_irq_on_success != 0u) {
                model->irq_status |= NPU_LSC_IRQ_DONE;
            }
        } else if (inputs->task_status ==
                       NPU_LSC_STATUS_NUMERIC_EXCEPTION ||
                   inputs->task_status == NPU_LSC_STATUS_TIMEOUT) {
            if (inputs->task_irq_on_error != 0u) {
                model->irq_status |= NPU_LSC_IRQ_EXCEPTION;
            }
            npu_lsc_record_fault(model, inputs->task_command_id,
                                 inputs->task_status,
                                 inputs->task_engine,
                                 inputs->task_opcode,
                                 inputs->task_fault_addr,
                                 NPU_LSC_FAULT_SOURCE_TASK,
                                 inputs->task_error_info,
                                 inputs->task_done_flags);
        } else {
            if (inputs->task_irq_on_error != 0u) {
                model->irq_status |= NPU_LSC_IRQ_ERROR;
            }
            npu_lsc_record_fault(model, inputs->task_command_id,
                                 inputs->task_status,
                                 inputs->task_engine,
                                 inputs->task_opcode,
                                 inputs->task_fault_addr,
                                 NPU_LSC_FAULT_SOURCE_TASK,
                                 inputs->task_error_info,
                                 inputs->task_done_flags);
        }
    }
    if (external_clear_active == 0u) {
        if (inputs->l1_ecc_error.valid != 0u) {
            npu_lsc_record_external_fault(
                model, NPU_LSC_FAULT_SOURCE_L1_ECC,
                &inputs->l1_ecc_error);
        }
        if (inputs->mif_first_error.valid != 0u) {
            npu_lsc_record_external_fault(
                model, NPU_LSC_FAULT_SOURCE_MIF_FIRST,
                &inputs->mif_first_error);
        }
        if (inputs->mif_protocol_error.valid != 0u) {
            npu_lsc_record_external_fault(
                model, NPU_LSC_FAULT_SOURCE_MIF_PROTOCOL,
                &inputs->mif_protocol_error);
        }
        if (inputs->gc_axi_first_error.valid != 0u) {
            npu_lsc_record_external_fault(
                model, NPU_LSC_FAULT_SOURCE_GC_AXI_FIRST,
                &inputs->gc_axi_first_error);
        }
        if (inputs->gc_axi_protocol_error.valid != 0u) {
            npu_lsc_record_external_fault(
                model, NPU_LSC_FAULT_SOURCE_GC_AXI_PROTOCOL,
                &inputs->gc_axi_protocol_error);
        }
        if (inputs->sys_l1_diag_error.valid != 0u) {
            npu_lsc_record_external_fault(
                model, NPU_LSC_FAULT_SOURCE_SYS_L1_DIAG,
                &inputs->sys_l1_diag_error);
        }
    }
    if (inputs->wdt_timeout != 0u) {
        npu_lsc_external_error_input_t error;

        (void)memset(&error, 0, sizeof(error));
        error.status = NPU_LSC_STATUS_WDT;
        model->irq_status |= NPU_LSC_IRQ_ERROR;
        model->reset_reason |= NPU_LSC_RESET_WATCHDOG;
        npu_lsc_record_external_fault(
            model, NPU_LSC_FAULT_SOURCE_WDT, &error);
    }

    if (external_clear_active == 0u &&
        (inputs->l1_ecc_error.valid != 0u ||
         inputs->mif_first_error.valid != 0u ||
         inputs->mif_protocol_error.valid != 0u ||
         inputs->gc_axi_first_error.valid != 0u ||
         inputs->gc_axi_protocol_error.valid != 0u ||
         inputs->sys_l1_diag_error.valid != 0u)) {
        model->irq_status |= NPU_LSC_IRQ_ERROR;
    }
}

static void npu_lsc_process_perf(npu_lsc_cycle_t *model,
                                 const npu_lsc_cycle_inputs_t *inputs)
{
    uint32_t index;

    if (model->perf_frozen != 0u) {
        return;
    }
    for (index = 0u; index < NPU_LSC_PERF_COUNTER_COUNT; index++) {
        model->perf_counter[index] += inputs->perf_increment[index];
    }
}

static void npu_lsc_soft_reset_state(
    npu_lsc_cycle_t *model,
    const npu_lsc_cycle_inputs_t *inputs)
{
    if (model->soft_state == NPU_LSC_SOFT_IDLE &&
        inputs->soft_reset_req != 0u) {
        model->soft_state = NPU_LSC_SOFT_DRAIN;
        model->soft_external_request = 1u;
        model->started = 0u;
        model->stopped = 1u;
        model->power_state = NPU_LSC_POWER_IDLE;
    }

    if (model->soft_state == NPU_LSC_SOFT_DRAIN &&
        npu_lsc_drain_idle(inputs) != 0u) {
        model->internal_soft_reset_pulse = 1u;
        model->param_lock = 0u;
        model->l1_diag_enable = 0u;
        model->irq_status = 0u;
        model->perf_frozen = 0u;
        model->reset_reason |= NPU_LSC_RESET_SOFTWARE;
        model->soft_state = NPU_LSC_SOFT_WAIT_RESET;
    } else if (
        model->soft_state == NPU_LSC_SOFT_WAIT_RESET &&
        inputs->internal_soft_reset_done != 0u) {
        model->soft_state = NPU_LSC_SOFT_ACK;
    } else if (model->soft_state == NPU_LSC_SOFT_ACK) {
        if (model->soft_external_request == 0u ||
            inputs->soft_reset_req == 0u) {
            model->soft_state = NPU_LSC_SOFT_IDLE;
            model->soft_external_request = 0u;
        }
    }
}

static void npu_lsc_power_state(
    npu_lsc_cycle_t *model,
    const npu_lsc_cycle_inputs_t *inputs)
{
    if (model->soft_state != NPU_LSC_SOFT_IDLE) {
        return;
    }
    if (model->power_state == NPU_LSC_POWER_IDLE &&
        inputs->power_down_req != 0u) {
        model->power_state = NPU_LSC_POWER_DRAIN;
        model->power_request_held = 1u;
        model->started = 0u;
        model->stopped = 1u;
    }
    if (model->power_state == NPU_LSC_POWER_DRAIN) {
        if (inputs->power_down_req == 0u) {
            model->power_request_held = 0u;
        }
        if (npu_lsc_core_idle(inputs) != 0u) {
            if (model->power_request_held != 0u &&
                inputs->power_down_req != 0u) {
                model->power_state = NPU_LSC_POWER_ACK;
            } else {
                model->power_state = NPU_LSC_POWER_IDLE;
            }
        }
    } else if (model->power_state == NPU_LSC_POWER_ACK &&
               inputs->power_down_req == 0u) {
        model->power_state = NPU_LSC_POWER_IDLE;
        model->power_request_held = 0u;
    }
}

static void npu_lsc_fill_outputs(
    const npu_lsc_cycle_t *model,
    const npu_lsc_cycle_inputs_t *inputs,
    npu_lsc_cycle_outputs_t *outputs,
    uint8_t request_ready)
{
    uint32_t index;
    uint8_t soft_active =
        (uint8_t)(model->soft_state != NPU_LSC_SOFT_IDLE);
    uint8_t power_active =
        (uint8_t)(model->power_state != NPU_LSC_POWER_IDLE);

    (void)memset(outputs, 0, sizeof(*outputs));
    outputs->reg_req_ready = request_ready;
    outputs->reg_rsp_valid = model->response_valid;
    outputs->reg_rsp_rdata = model->response_data;
    outputs->reg_rsp_status = model->response_status;

    outputs->cfe_quiesce =
        (uint8_t)((model->stopped != 0u ||
                   soft_active != 0u || power_active != 0u) &&
                  inputs->issue_idle != 0u);
    outputs->ts_quiesce = soft_active;
    outputs->eng_abort = soft_active != 0u ? 0x0fu : 0u;
    outputs->stop_fetch =
        (uint8_t)(model->stopped != 0u ||
                  soft_active != 0u || power_active != 0u);
    outputs->single_step_pulse = model->single_step_pulse;
    outputs->internal_soft_reset_pulse =
        model->internal_soft_reset_pulse;

    outputs->soft_reset_done =
        (uint8_t)(model->soft_state == NPU_LSC_SOFT_ACK);
    outputs->power_down_ack =
        (uint8_t)(model->power_state == NPU_LSC_POWER_ACK);
    outputs->core_idle = npu_lsc_core_idle(inputs);

    outputs->irq_done =
        (uint8_t)((model->irq_status & NPU_LSC_IRQ_DONE) != 0u &&
                  (model->irq_mask & NPU_LSC_IRQ_DONE) == 0u);
    outputs->irq_exception =
        (uint8_t)((model->irq_status &
                   NPU_LSC_IRQ_EXCEPTION) != 0u &&
                  (model->irq_mask &
                   NPU_LSC_IRQ_EXCEPTION) == 0u);
    outputs->irq_error =
        (uint8_t)((model->irq_status & NPU_LSC_IRQ_ERROR) != 0u &&
                  (model->irq_mask & NPU_LSC_IRQ_ERROR) == 0u);
    outputs->external_error_clear_o =
        model->external_error_clear_pulse;

    outputs->param_l1_base = model->param_l1_base;
    outputs->param_l1_limit = model->param_l1_limit;
    outputs->param_lock = model->param_lock;
    outputs->l1_diag_enable = model->l1_diag_enable;
    outputs->debug_frozen = model->perf_frozen;

    outputs->input_base = model->input_base;
    outputs->weight_base = model->weight_base;
    outputs->work_base = model->work_base;
    outputs->output_base = model->output_base;
    outputs->kv_base = model->kv_base;
    outputs->m_axi_addr_base = model->m_axi_addr_base;
    outputs->m_axi_addr_limit = model->m_axi_addr_limit;
    for (index = 0u; index < NPU_LSC_TIMEOUT_CLASS_COUNT; index++) {
        outputs->timeout_cycles[index] = model->timeout_cycles[index];
    }
}

void npu_lsc_cycle_config_reference(npu_lsc_cycle_config_t *config)
{
    static const uint32_t timeout_reset[NPU_LSC_TIMEOUT_CLASS_COUNT] = {
        0u, 1024u, 4096u, 16384u,
        65536u, 262144u, 1048576u, 4194304u,
        16777216u, 67108864u, 268435456u, 1073741824u,
        UINT32_MAX, 0u, 0u, 0u
    };
    uint32_t index;

    if (config == (npu_lsc_cycle_config_t *)0) {
        return;
    }
    (void)memset(config, 0, sizeof(*config));
    config->version_major = 1u;
    config->version_minor = 0u;
    config->build = 1u;
    /*
     * The base feature set implements every P0 operation. Optional P1
     * operations and descriptor CRC are disabled in the reference build.
     */
    config->isa_feature = 0u;
    config->bus_config =
        (UINT64_C(64) << NPU_LSC_BUS_DATA_BITS_SHIFT) |
        (UINT64_C(48) << NPU_LSC_BUS_GADDR_BITS_SHIFT) |
        (UINT64_C(40) << NPU_LSC_BUS_PA_BITS_SHIFT) |
        (UINT64_C(8) << NPU_LSC_BUS_AXI_ID_BITS_SHIFT);
    config->l1_config =
        (UINT64_C(1024 * 1024) <<
         NPU_LSC_L1_BYTES_SHIFT) |
        (UINT64_C(16) << NPU_LSC_L1_BANKS_SHIFT) |
        (UINT64_C(2) <<
         NPU_LSC_L1_READ_LATENCY_SHIFT);
    config->matrix_config =
        (UINT64_C(8) << NPU_LSC_MATRIX_MT_SHIFT) |
        (UINT64_C(16) << NPU_LSC_MATRIX_KT_SHIFT) |
        (UINT64_C(8) << NPU_LSC_MATRIX_NT_SHIFT) |
        (NPU_LSC_MATRIX_DTYPE_MASK <<
         NPU_LSC_MATRIX_DTYPE_MASK_SHIFT);
    config->vector_config =
        (UINT64_C(8) << NPU_LSC_VECTOR_LANES_SHIFT) |
        (NPU_LSC_VECTOR_OPCODE_MASK <<
         NPU_LSC_VECTOR_OPCODE_MASK_SHIFT);
    config->cme_config =
        (UINT64_C(4) <<
         NPU_LSC_CME_FP32_LANES_SHIFT) |
        (NPU_LSC_CME_FUNCTION_MASK <<
         NPU_LSC_CME_FUNCTION_MASK_SHIFT) |
        (UINT64_C(1) <<
         NPU_LSC_CME_APPROX_MASK_SHIFT) |
        (UINT64_C(4096) <<
         NPU_LSC_CME_SCRATCH_ELEMS_SHIFT);
    config->l1_bytes = 1024u * 1024u;
    for (index = 0u; index < NPU_LSC_TIMEOUT_CLASS_COUNT; index++) {
        config->timeout_reset[index] = timeout_reset[index];
    }
}

void npu_lsc_cycle_init(npu_lsc_cycle_t *model,
                        const npu_lsc_cycle_config_t *config)
{
    npu_lsc_cycle_config_t reference;

    if (model == (npu_lsc_cycle_t *)0) {
        return;
    }
    if (config == (const npu_lsc_cycle_config_t *)0) {
        npu_lsc_cycle_config_reference(&reference);
        config = &reference;
    }
    (void)memset(model, 0, sizeof(*model));
    model->config = *config;
    model->config.isa_feature &=
        NPU_LSC_IMPLEMENTED_ISA_FEATURES;
    npu_lsc_cycle_reset(model);
}

void npu_lsc_cycle_reset(npu_lsc_cycle_t *model)
{
    npu_lsc_cycle_config_t config;
    uint32_t index;

    if (model == (npu_lsc_cycle_t *)0) {
        return;
    }
    config = model->config;
    (void)memset(model, 0, sizeof(*model));
    model->config = config;
    model->stopped = 1u;
    model->irq_mask = NPU_LSC_IRQ_ALL;
    model->reset_reason = NPU_LSC_RESET_EXTERNAL;
    model->m_axi_addr_base = 0u;
    model->m_axi_addr_limit = UINT64_C(0x00fffffffff8);
    for (index = 0u; index < NPU_LSC_TIMEOUT_CLASS_COUNT; index++) {
        model->timeout_cycles[index] =
            model->config.timeout_reset[index];
    }
}

void npu_lsc_cycle_step(npu_lsc_cycle_t *model,
                        const npu_lsc_cycle_inputs_t *inputs,
                        npu_lsc_cycle_outputs_t *outputs)
{
    uint8_t core_idle;
    uint8_t external_clear_visible;

    if (model == (npu_lsc_cycle_t *)0 ||
        inputs == (const npu_lsc_cycle_inputs_t *)0 ||
        outputs == (npu_lsc_cycle_outputs_t *)0) {
        return;
    }
    if (inputs->reset_n == 0u) {
        npu_lsc_cycle_reset(model);
        npu_lsc_fill_outputs(model, inputs, outputs, 0u);
        outputs->reg_rsp_valid = 0u;
        return;
    }

    npu_lsc_fill_outputs(
        model, inputs, outputs,
        (uint8_t)(model->response_valid == 0u));
    external_clear_visible = model->external_error_clear_pulse;
    model->external_error_clear_pulse = 0u;
    model->single_step_pulse = 0u;
    model->internal_soft_reset_pulse = 0u;
    if (outputs->reg_rsp_valid != 0u &&
        inputs->reg_rsp_ready != 0u) {
        model->response_valid = 0u;
    }

    core_idle = npu_lsc_core_idle(inputs);
    if (inputs->reg_req_valid != 0u &&
        outputs->reg_req_ready != 0u) {
        model->response_data = 0u;
        if ((inputs->reg_req_addr & 7u) != 0u) {
            model->response_status = NPU_LSC_REG_SLVERR;
        } else if (inputs->reg_req_write != 0u) {
            model->response_status = npu_lsc_write_register(
                model, inputs, inputs->reg_req_space,
                inputs->reg_req_addr, inputs->reg_req_wdata,
                inputs->reg_req_wstrb);
        } else {
            model->response_data = npu_lsc_read_register(
                model, inputs, inputs->reg_req_space,
                inputs->reg_req_addr);
            model->response_status = NPU_LSC_REG_OKAY;
        }
        model->response_valid = 1u;
    }

    npu_lsc_process_events(
        model, inputs,
        (uint8_t)(external_clear_visible != 0u ||
                  model->external_error_clear_pulse != 0u));
    npu_lsc_process_perf(model, inputs);
    npu_lsc_soft_reset_state(model, inputs);
    npu_lsc_power_state(model, inputs);

    if (core_idle == 0u &&
        model->power_state == NPU_LSC_POWER_ACK) {
        model->power_state = NPU_LSC_POWER_DRAIN;
    }
}
