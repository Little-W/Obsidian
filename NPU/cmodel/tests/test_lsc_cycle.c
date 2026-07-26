#include "npu_lsc_cycle.h"
#include "test_util.h"

#include <string.h>

static void lsc_set_idle(npu_lsc_cycle_inputs_t *inputs,
                         uint8_t idle)
{
    inputs->issue_idle = idle;
    inputs->cfe_idle = idle;
    inputs->ts_idle = idle;
    inputs->ts_quiescent = idle;
    inputs->eng_quiescent = idle != 0u ? 0x0fu : 0u;
    inputs->l1_idle = idle;
    inputs->l1_write_idle = idle;
    inputs->mif_idle = idle;
    inputs->gc_axi_idle = idle;
}

static void lsc_clear_response(npu_lsc_cycle_t *model,
                               npu_lsc_cycle_inputs_t *inputs,
                               npu_lsc_cycle_outputs_t *outputs)
{
    inputs->reg_req_valid = 0u;
    inputs->reg_rsp_ready = 1u;
    npu_lsc_cycle_step(model, inputs, outputs);
    inputs->reg_rsp_ready = 0u;
}

static uint8_t lsc_write(npu_lsc_cycle_t *model,
                         npu_lsc_cycle_inputs_t *inputs,
                         npu_lsc_cycle_outputs_t *outputs,
                         uint8_t space,
                         uint16_t address,
                         uint64_t data,
                         uint8_t strobe)
{
    uint8_t status;

    inputs->reg_req_valid = 1u;
    inputs->reg_req_write = 1u;
    inputs->reg_req_space = space;
    inputs->reg_req_addr = address;
    inputs->reg_req_wdata = data;
    inputs->reg_req_wstrb = strobe;
    npu_lsc_cycle_step(model, inputs, outputs);
    inputs->reg_req_valid = 0u;
    npu_lsc_cycle_step(model, inputs, outputs);
    status = outputs->reg_rsp_status;
    lsc_clear_response(model, inputs, outputs);
    return status;
}

static uint8_t lsc_read(npu_lsc_cycle_t *model,
                        npu_lsc_cycle_inputs_t *inputs,
                        npu_lsc_cycle_outputs_t *outputs,
                        uint8_t space,
                        uint16_t address,
                        uint64_t *data)
{
    uint8_t status;

    inputs->reg_req_valid = 1u;
    inputs->reg_req_write = 0u;
    inputs->reg_req_space = space;
    inputs->reg_req_addr = address;
    inputs->reg_req_wdata = 0u;
    inputs->reg_req_wstrb = 0u;
    npu_lsc_cycle_step(model, inputs, outputs);
    inputs->reg_req_valid = 0u;
    npu_lsc_cycle_step(model, inputs, outputs);
    status = outputs->reg_rsp_status;
    *data = outputs->reg_rsp_rdata;
    lsc_clear_response(model, inputs, outputs);
    return status;
}

static uint32_t lsc_external_error_info(uint8_t source,
                                        uint8_t detail,
                                        uint8_t aux,
                                        uint8_t raw_status)
{
    return ((uint32_t)NPU_LSC_EXTERNAL_ERROR_STAGE << 28u) |
           ((uint32_t)source << NPU_LSC_EXTERNAL_SOURCE_SHIFT) |
           ((uint32_t)detail << NPU_LSC_EXTERNAL_DETAIL_SHIFT) |
           ((uint32_t)aux << NPU_LSC_EXTERNAL_AUX_SHIFT) |
           raw_status;
}

static int lsc_test_external_errors(void)
{
    npu_lsc_cycle_config_t config;
    npu_lsc_cycle_t model;
    npu_lsc_cycle_inputs_t inputs;
    npu_lsc_cycle_outputs_t outputs;
    static const uint8_t priority_source[5] = {
        NPU_LSC_FAULT_SOURCE_MIF_FIRST,
        NPU_LSC_FAULT_SOURCE_MIF_PROTOCOL,
        NPU_LSC_FAULT_SOURCE_GC_AXI_FIRST,
        NPU_LSC_FAULT_SOURCE_GC_AXI_PROTOCOL,
        NPU_LSC_FAULT_SOURCE_SYS_L1_DIAG
    };
    uint8_t priority_case;
    uint64_t value;

    npu_lsc_cycle_config_reference(&config);
    npu_lsc_cycle_init(&model, &config);
    (void)memset(&inputs, 0, sizeof(inputs));
    (void)memset(&outputs, 0, sizeof(outputs));
    inputs.reset_n = 1u;
    lsc_set_idle(&inputs, 1u);
    model.irq_mask = 0u;

    inputs.l1_ecc_error.valid = 1u;
    inputs.l1_ecc_error.status = 0x0bu;
    inputs.l1_ecc_error.addr = UINT64_C(0x1100);
    inputs.l1_ecc_error.detail = 0x12u;
    inputs.l1_ecc_error.aux = 0x34u;
    inputs.mif_first_error.valid = 1u;
    inputs.mif_first_error.status = 0x06u;
    inputs.mif_first_error.addr = UINT64_C(0x2200);
    inputs.mif_protocol_error.valid = 1u;
    inputs.mif_protocol_error.status = 0x02u;
    inputs.gc_axi_first_error.valid = 1u;
    inputs.gc_axi_first_error.status = 0x05u;
    inputs.gc_axi_protocol_error.valid = 1u;
    inputs.gc_axi_protocol_error.status = 0x02u;
    inputs.sys_l1_diag_error.valid = 1u;
    inputs.sys_l1_diag_error.status = 0x04u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);

    TEST_CHECK(model.fault_valid == 1u);
    TEST_CHECK(model.fault_source == NPU_LSC_FAULT_SOURCE_L1_ECC);
    TEST_CHECK(model.fault_command_id == UINT16_C(0x0fff));
    TEST_CHECK(model.fault_status == 0x0bu);
    TEST_CHECK(model.fault_engine == 0u);
    TEST_CHECK(model.fault_opcode == 0u);
    TEST_CHECK(model.fault_addr == UINT64_C(0x1100));
    TEST_CHECK(model.fault_done_flags == 0u);
    TEST_CHECK(model.fault_error_info ==
               lsc_external_error_info(
                   NPU_LSC_FAULT_SOURCE_L1_ECC,
                   0x12u, 0x34u, 0x0bu));
    TEST_CHECK((model.irq_status & NPU_LSC_IRQ_ERROR) != 0u);

    TEST_CHECK(lsc_read(&model, &inputs, &outputs, 0u,
                        NPU_LSC_REG_FAULT_INFO,
                        &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(value == UINT64_C(0x0b));
    TEST_CHECK(lsc_read(&model, &inputs, &outputs, 0u,
                        NPU_LSC_REG_FAULT_DETAIL,
                        &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(value == model.fault_error_info);

    inputs.l1_ecc_error.valid = 0u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.fault_source == NPU_LSC_FAULT_SOURCE_L1_ECC);
    TEST_CHECK(model.fault_addr == UINT64_C(0x1100));

    inputs.mif_protocol_error.valid = 0u;
    inputs.gc_axi_first_error.valid = 0u;
    inputs.gc_axi_protocol_error.valid = 0u;
    inputs.sys_l1_diag_error.valid = 0u;
    inputs.gc_axi_protocol_error.valid = 1u;
    inputs.gc_axi_protocol_error.status = 0x02u;
    inputs.gc_axi_protocol_error.addr = UINT64_C(0x2a40);
    inputs.gc_axi_protocol_error.detail = 0x9au;
    inputs.gc_axi_protocol_error.aux = 0xbcu;
    inputs.reg_req_valid = 1u;
    inputs.reg_req_write = 1u;
    inputs.reg_req_space = 0u;
    inputs.reg_req_addr = NPU_LSC_REG_FAULT_CLEAR;
    inputs.reg_req_wdata = 1u;
    inputs.reg_req_wstrb = 0x01u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.fault_valid == 0u);
    TEST_CHECK(model.external_error_clear_pulse == 1u);

    inputs.reg_req_valid = 0u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.external_error_clear_o == 1u);
    TEST_CHECK(model.fault_valid == 0u);
    inputs.mif_first_error.valid = 0u;
    inputs.reg_rsp_ready = 1u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.external_error_clear_o == 0u);
    TEST_CHECK(model.fault_valid == 1u);
    TEST_CHECK(model.fault_source ==
               NPU_LSC_FAULT_SOURCE_GC_AXI_PROTOCOL);
    TEST_CHECK(model.fault_addr == UINT64_C(0x2a40));
    TEST_CHECK(model.fault_error_info ==
               lsc_external_error_info(
                   NPU_LSC_FAULT_SOURCE_GC_AXI_PROTOCOL,
                   0x9au, 0xbcu, 0x02u));

    npu_lsc_cycle_reset(&model);
    (void)memset(&inputs, 0, sizeof(inputs));
    inputs.reset_n = 1u;
    lsc_set_idle(&inputs, 1u);
    inputs.sys_l1_diag_error.valid = 1u;
    inputs.sys_l1_diag_error.status = 0xffu;
    inputs.sys_l1_diag_error.addr = UINT64_C(0x3340);
    inputs.sys_l1_diag_error.detail = 0x56u;
    inputs.sys_l1_diag_error.aux = 0x78u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.fault_source ==
               NPU_LSC_FAULT_SOURCE_SYS_L1_DIAG);
    TEST_CHECK(model.fault_status == 0x02u);
    TEST_CHECK(model.fault_addr == UINT64_C(0x3340));
    TEST_CHECK(model.fault_error_info ==
               lsc_external_error_info(
                   NPU_LSC_FAULT_SOURCE_SYS_L1_DIAG,
                   0x56u, 0x78u, 0xffu));

    for (priority_case = 0u; priority_case < 5u;
         priority_case++) {
        npu_lsc_cycle_reset(&model);
        (void)memset(&inputs, 0, sizeof(inputs));
        inputs.reset_n = 1u;
        lsc_set_idle(&inputs, 1u);
        inputs.wdt_timeout = 1u;
        inputs.sys_l1_diag_error.valid = 1u;
        inputs.sys_l1_diag_error.status = 0x04u;
        inputs.sys_l1_diag_error.addr = UINT64_C(0x6000);
        if (priority_case <= 3u) {
            inputs.gc_axi_protocol_error.valid = 1u;
            inputs.gc_axi_protocol_error.status = 0x02u;
            inputs.gc_axi_protocol_error.addr =
                UINT64_C(0x5000);
        }
        if (priority_case <= 2u) {
            inputs.gc_axi_first_error.valid = 1u;
            inputs.gc_axi_first_error.status = 0x05u;
            inputs.gc_axi_first_error.addr =
                UINT64_C(0x4000);
        }
        if (priority_case <= 1u) {
            inputs.mif_protocol_error.valid = 1u;
            inputs.mif_protocol_error.status = 0x02u;
            inputs.mif_protocol_error.addr =
                UINT64_C(0x3000);
        }
        if (priority_case == 0u) {
            inputs.mif_first_error.valid = 1u;
            inputs.mif_first_error.status = 0x06u;
            inputs.mif_first_error.addr =
                UINT64_C(0x2000);
        }
        npu_lsc_cycle_step(&model, &inputs, &outputs);
        TEST_CHECK(model.fault_source ==
                   priority_source[priority_case]);
    }

    npu_lsc_cycle_reset(&model);
    (void)memset(&inputs, 0, sizeof(inputs));
    inputs.reset_n = 1u;
    lsc_set_idle(&inputs, 1u);
    inputs.mif_first_error.valid = 1u;
    inputs.mif_first_error.status = 0x06u;
    inputs.mif_first_error.addr = UINT64_C(0x7120);
    inputs.mif_first_error.detail = 1u;
    inputs.mif_first_error.aux = 2u;
    inputs.mif_first_error.has_task_identity = 1u;
    inputs.mif_first_error.command_id = 0x345u;
    inputs.mif_first_error.engine = 1u;
    inputs.mif_first_error.opcode = 0x20u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.fault_source ==
               NPU_LSC_FAULT_SOURCE_MIF_FIRST);
    TEST_CHECK(model.fault_command_id == 0x345u);
    TEST_CHECK(model.fault_engine == 1u);
    TEST_CHECK(model.fault_opcode == 0x20u);
    inputs.mif_first_error.valid = 0u;
    inputs.task_terminal_valid = 1u;
    inputs.task_status = 0x06u;
    inputs.task_command_id = 0x345u;
    inputs.task_engine = 1u;
    inputs.task_opcode = 0x20u;
    inputs.task_fault_addr = UINT64_C(0x7120);
    inputs.task_error_info = UINT32_C(0x4006ff20);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.fault_source ==
               NPU_LSC_FAULT_SOURCE_MIF_FIRST);
    TEST_CHECK(model.fault_command_id == 0x345u);
    TEST_CHECK(model.fault_addr == UINT64_C(0x7120));

    npu_lsc_cycle_reset(&model);
    (void)memset(&inputs, 0, sizeof(inputs));
    inputs.reset_n = 1u;
    lsc_set_idle(&inputs, 1u);
    inputs.task_terminal_valid = 1u;
    inputs.task_status = 0x04u;
    inputs.task_command_id = 0x21u;
    inputs.task_engine = 3u;
    inputs.task_opcode = 0x61u;
    inputs.task_fault_addr = UINT64_C(0x4450);
    inputs.task_error_info = UINT32_C(0x4123ff61);
    inputs.task_done_flags = 1u;
    inputs.l1_ecc_error.valid = 1u;
    inputs.l1_ecc_error.status = 0x0bu;
    inputs.l1_ecc_error.addr = UINT64_C(0x5560);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.fault_source == NPU_LSC_FAULT_SOURCE_TASK);
    TEST_CHECK(model.fault_command_id == 0x21u);
    TEST_CHECK(model.fault_addr == UINT64_C(0x4450));
    TEST_CHECK(model.fault_error_info == UINT32_C(0x4123ff61));

    npu_lsc_cycle_reset(&model);
    (void)memset(&inputs, 0, sizeof(inputs));
    inputs.reset_n = 1u;
    lsc_set_idle(&inputs, 1u);
    inputs.wdt_timeout = 1u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.fault_source == NPU_LSC_FAULT_SOURCE_WDT);
    TEST_CHECK(model.fault_command_id == UINT16_C(0x0fff));
    TEST_CHECK(model.fault_status == 0x09u);
    TEST_CHECK(model.fault_error_info ==
               lsc_external_error_info(
                   NPU_LSC_FAULT_SOURCE_WDT, 0u, 0u, 0x09u));
    TEST_CHECK((model.reset_reason &
                NPU_LSC_RESET_WATCHDOG) != 0u);

    return 0;
}

int test_lsc_cycle(void)
{
    npu_lsc_cycle_config_t config;
    npu_lsc_cycle_t model;
    npu_lsc_cycle_inputs_t inputs;
    npu_lsc_cycle_outputs_t outputs;
    uint64_t value;

    npu_lsc_cycle_config_reference(&config);
    npu_lsc_cycle_init(&model, &config);
    (void)memset(&inputs, 0, sizeof(inputs));
    (void)memset(&outputs, 0, sizeof(outputs));
    lsc_set_idle(&inputs, 1u);

    inputs.reset_n = 0u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.reg_req_ready == 0u);
    TEST_CHECK(outputs.stop_fetch == 1u);
    TEST_CHECK(outputs.param_lock == 0u);
    TEST_CHECK(outputs.l1_diag_enable == 0u);

    inputs.reset_n = 1u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.reg_req_ready == 1u);
    TEST_CHECK(outputs.core_idle == 1u);

    TEST_CHECK(lsc_read(&model, &inputs, &outputs, 0u,
                        NPU_LSC_REG_NPU_VERSION,
                        &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK((value & UINT64_C(0xffff)) == config.version_major);
    TEST_CHECK(((value >> 16u) & UINT64_C(0xffff)) ==
               config.version_minor);
    TEST_CHECK(((value >> 32u) & UINT64_C(0xffffffff)) ==
               config.build);
    TEST_CHECK(lsc_read(&model, &inputs, &outputs, 0u,
                        NPU_LSC_REG_ISA_FEATURE,
                        &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(value == config.isa_feature);
    TEST_CHECK((value & ~NPU_LSC_ISA_OPTIONAL_MASK) == 0u);
    TEST_CHECK(value == 0u);

    inputs.reg_req_valid = 1u;
    inputs.reg_req_write = 0u;
    inputs.reg_req_space = 0u;
    inputs.reg_req_addr = NPU_LSC_REG_BUS_CONFIG;
    inputs.reg_rsp_ready = 0u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.reg_req_ready == 1u);
    TEST_CHECK(outputs.reg_rsp_valid == 0u);
    inputs.reg_req_valid = 0u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.reg_rsp_valid == 1u);
    value = outputs.reg_rsp_rdata;
    TEST_CHECK(
        ((value >> NPU_LSC_BUS_DATA_BITS_SHIFT) &
         NPU_LSC_FIELD_U8_MASK) == 64u);
    TEST_CHECK(
        ((value >> NPU_LSC_BUS_GVA_BITS_SHIFT) &
         NPU_LSC_FIELD_U8_MASK) == 48u);
    TEST_CHECK(
        ((value >> NPU_LSC_BUS_PA_BITS_SHIFT) &
         NPU_LSC_FIELD_U8_MASK) == 40u);
    TEST_CHECK(
        ((value >> NPU_LSC_BUS_AXI_ID_BITS_SHIFT) &
         NPU_LSC_FIELD_U8_MASK) == 8u);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.reg_rsp_valid == 1u);
    TEST_CHECK(outputs.reg_rsp_rdata == value);
    TEST_CHECK(outputs.reg_req_ready == 0u);
    lsc_clear_response(&model, &inputs, &outputs);

    TEST_CHECK(lsc_read(
                   &model, &inputs, &outputs, 0u,
                   NPU_LSC_REG_L1_CONFIG,
                   &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(
        ((value >> NPU_LSC_L1_BYTES_SHIFT) &
         NPU_LSC_FIELD_U32_MASK) ==
        UINT64_C(1024 * 1024));
    TEST_CHECK(
        ((value >> NPU_LSC_L1_BANKS_SHIFT) &
         NPU_LSC_FIELD_U8_MASK) == 16u);
    TEST_CHECK(
        ((value >> NPU_LSC_L1_READ_LATENCY_SHIFT) &
         NPU_LSC_FIELD_U8_MASK) == 2u);

    TEST_CHECK(lsc_read(
                   &model, &inputs, &outputs, 0u,
                   NPU_LSC_REG_MATRIX_CONFIG,
                   &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(
        ((value >> NPU_LSC_MATRIX_MT_SHIFT) &
         NPU_LSC_FIELD_U8_MASK) == 8u);
    TEST_CHECK(
        ((value >> NPU_LSC_MATRIX_KT_SHIFT) &
         NPU_LSC_FIELD_U8_MASK) == 16u);
    TEST_CHECK(
        ((value >> NPU_LSC_MATRIX_NT_SHIFT) &
         NPU_LSC_FIELD_U8_MASK) == 8u);
    TEST_CHECK(
        ((value >> NPU_LSC_MATRIX_DTYPE_MASK_SHIFT) &
         NPU_LSC_MATRIX_DTYPE_MASK) ==
        NPU_LSC_MATRIX_DTYPE_MASK);

    TEST_CHECK(lsc_read(
                   &model, &inputs, &outputs, 0u,
                   NPU_LSC_REG_VECTOR_CONFIG,
                   &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(
        ((value >> NPU_LSC_VECTOR_LANES_SHIFT) &
         NPU_LSC_FIELD_U8_MASK) == 8u);
    TEST_CHECK(
        ((value >> NPU_LSC_VECTOR_OPCODE_MASK_SHIFT) &
         NPU_LSC_VECTOR_OPCODE_MASK) ==
        NPU_LSC_VECTOR_OPCODE_MASK);

    TEST_CHECK(lsc_read(
                   &model, &inputs, &outputs, 0u,
                   NPU_LSC_REG_CME_CONFIG,
                   &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(
        ((value >> NPU_LSC_CME_FP32_LANES_SHIFT) &
         NPU_LSC_FIELD_U8_MASK) == 4u);
    TEST_CHECK(
        ((value >> NPU_LSC_CME_FUNCTION_MASK_SHIFT) &
         NPU_LSC_CME_FUNCTION_MASK) ==
        NPU_LSC_CME_FUNCTION_MASK);
    TEST_CHECK(
        ((value >> NPU_LSC_CME_APPROX_MASK_SHIFT) &
         NPU_LSC_CME_APPROX_MASK) == 1u);
    TEST_CHECK(
        ((value >> NPU_LSC_CME_SCRATCH_ELEMS_SHIFT) &
         NPU_LSC_FIELD_U16_MASK) == 4096u);

    TEST_CHECK(lsc_write(
                   &model, &inputs, &outputs, 0u,
                   NPU_LSC_REG_CORE_CONTROL,
                   NPU_LSC_CORE_CONTROL_START |
                       NPU_LSC_CORE_CONTROL_SINGLE_STEP,
                   0x01u) == NPU_LSC_REG_SLVERR);
    TEST_CHECK(lsc_read(
                   &model, &inputs, &outputs, 0u,
                   NPU_LSC_REG_CORE_CONTROL,
                   &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(value == NPU_LSC_CORE_CONTROL_STOP);
    TEST_CHECK(model.single_step_pulse == 0u);
    TEST_CHECK(lsc_write(
                   &model, &inputs, &outputs, 0u,
                   NPU_LSC_REG_CORE_CONTROL,
                   NPU_LSC_CORE_CONTROL_START |
                       NPU_LSC_CORE_CONTROL_STOP,
                   0x01u) == NPU_LSC_REG_SLVERR);
    TEST_CHECK(lsc_write(
                   &model, &inputs, &outputs, 0u,
                   NPU_LSC_REG_CORE_CONTROL,
                   UINT64_C(0x10),
                   0x01u) == NPU_LSC_REG_SLVERR);
    TEST_CHECK(model.started == 0u);
    TEST_CHECK(model.stopped != 0u);

    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_CORE_CONTROL,
                         NPU_LSC_CORE_CONTROL_START,
                         0x01u) == NPU_LSC_REG_OKAY);
    TEST_CHECK(outputs.stop_fetch == 0u);
    model.soft_state = NPU_LSC_SOFT_WAIT_RESET;
    TEST_CHECK(lsc_write(
                   &model, &inputs, &outputs, 0u,
                   NPU_LSC_REG_CORE_CONTROL,
                   NPU_LSC_CORE_CONTROL_STOP |
                       NPU_LSC_CORE_CONTROL_SOFT_RESET,
                   0x01u) == NPU_LSC_REG_SLVERR);
    TEST_CHECK(model.started != 0u);
    TEST_CHECK(model.stopped == 0u);
    TEST_CHECK(model.soft_state == NPU_LSC_SOFT_WAIT_RESET);
    model.soft_state = NPU_LSC_SOFT_IDLE;

    lsc_set_idle(&inputs, 0u);
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_INPUT_BASE,
                         UINT64_C(0x1000),
                         0xffu) == NPU_LSC_REG_SLVERR);
    TEST_CHECK(model.input_base == 0u);
    lsc_set_idle(&inputs, 1u);

    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_M_AXI_ADDR_LIMIT,
                         UINT64_C(0x4000),
                         0xffu) == NPU_LSC_REG_OKAY);
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_M_AXI_ADDR_BASE,
                         UINT64_C(0x1000),
                         0xffu) == NPU_LSC_REG_OKAY);
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_M_AXI_ADDR_BASE,
                         UINT64_C(0x5000),
                         0xffu) == NPU_LSC_REG_SLVERR);
    TEST_CHECK(model.m_axi_addr_base == UINT64_C(0x1000));

    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_PARAM_L1_LIMIT,
                         UINT64_C(0x8000),
                         0xffu) == NPU_LSC_REG_OKAY);
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_PARAM_L1_BASE,
                         UINT64_C(0x4000),
                         0xffu) == NPU_LSC_REG_OKAY);
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_PARAM_LOCK,
                         UINT64_C(1),
                         0x01u) == NPU_LSC_REG_OKAY);
    TEST_CHECK(model.param_lock == 1u);
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_PARAM_L1_BASE,
                         UINT64_C(0),
                         0xffu) == NPU_LSC_REG_SLVERR);
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_L1_DIAG_CONTROL,
                         NPU_LSC_L1_DIAG_ENABLE,
                         0x01u) == NPU_LSC_REG_OKAY);
    TEST_CHECK(outputs.l1_diag_enable == 1u);

    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_IRQ_MASK,
                         UINT64_C(0),
                         0x01u) == NPU_LSC_REG_OKAY);
    inputs.task_terminal_valid = 1u;
    inputs.task_irq_on_success = 1u;
    inputs.task_status = 0u;
    inputs.task_command_id = 7u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    inputs.task_terminal_valid = 0u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.irq_done == 1u);

    inputs.reg_req_valid = 1u;
    inputs.reg_req_write = 1u;
    inputs.reg_req_space = 0u;
    inputs.reg_req_addr = NPU_LSC_REG_IRQ_STATUS;
    inputs.reg_req_wdata = NPU_LSC_IRQ_DONE;
    inputs.reg_req_wstrb = 0x01u;
    inputs.task_terminal_valid = 1u;
    inputs.task_irq_on_success = 1u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    inputs.task_terminal_valid = 0u;
    inputs.reg_req_valid = 0u;
    TEST_CHECK((model.irq_status & NPU_LSC_IRQ_DONE) != 0u);
    lsc_clear_response(&model, &inputs, &outputs);

    inputs.task_terminal_valid = 1u;
    inputs.task_irq_on_success = 0u;
    inputs.task_irq_on_error = 1u;
    inputs.task_status = 0x02u;
    inputs.task_command_id = 9u;
    inputs.task_engine = 2u;
    inputs.task_opcode = 0x40u;
    inputs.task_fault_addr = UINT64_C(0x1230);
    inputs.task_error_info = UINT32_C(0x12345678);
    inputs.task_done_flags = UINT16_C(0xa55a);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    inputs.task_terminal_valid = 0u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.fault_valid == 1u);
    TEST_CHECK(model.fault_command_id == 9u);
    TEST_CHECK(model.fault_error_info == UINT32_C(0x12345678));
    TEST_CHECK(model.fault_done_flags == UINT16_C(0xa55a));
    TEST_CHECK(outputs.irq_error == 1u);
    TEST_CHECK(lsc_read(&model, &inputs, &outputs, 0u,
                        NPU_LSC_REG_FAULT_DETAIL,
                        &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(value == UINT64_C(0x0000a55a12345678));
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_FAULT_DETAIL,
                         UINT64_MAX,
                         0xffu) == NPU_LSC_REG_SLVERR);
    TEST_CHECK(model.fault_error_info == UINT32_C(0x12345678));
    TEST_CHECK(model.fault_done_flags == UINT16_C(0xa55a));

    inputs.task_terminal_valid = 1u;
    inputs.task_status = 0x04u;
    inputs.task_command_id = 10u;
    inputs.task_engine = 1u;
    inputs.task_opcode = 0x20u;
    inputs.task_fault_addr = UINT64_C(0x5670);
    inputs.task_error_info = UINT32_C(0xdeadbeef);
    inputs.task_done_flags = UINT16_C(0x5aa5);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    inputs.task_terminal_valid = 0u;
    TEST_CHECK(model.fault_command_id == 9u);
    TEST_CHECK(model.fault_error_info == UINT32_C(0x12345678));
    TEST_CHECK(model.fault_done_flags == UINT16_C(0xa55a));
    TEST_CHECK(lsc_read(&model, &inputs, &outputs, 0u,
                        NPU_LSC_REG_FAULT_DETAIL,
                        &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(value == UINT64_C(0x0000a55a12345678));

    inputs.reg_req_valid = 1u;
    inputs.reg_req_write = 1u;
    inputs.reg_req_space = 0u;
    inputs.reg_req_addr = NPU_LSC_REG_FAULT_CLEAR;
    inputs.reg_req_wdata = 1u;
    inputs.reg_req_wstrb = 0x01u;
    inputs.task_terminal_valid = 1u;
    inputs.task_status = 0x04u;
    inputs.task_command_id = 10u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    inputs.reg_req_valid = 0u;
    inputs.task_terminal_valid = 0u;
    TEST_CHECK(model.fault_command_id == 10u);
    TEST_CHECK(model.fault_error_info == UINT32_C(0xdeadbeef));
    TEST_CHECK(model.fault_done_flags == UINT16_C(0x5aa5));
    lsc_clear_response(&model, &inputs, &outputs);

    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_IRQ_STATUS,
                         NPU_LSC_IRQ_ERROR,
                         0x01u) == NPU_LSC_REG_OKAY);
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_FAULT_CLEAR,
                         UINT64_C(1),
                         0x01u) == NPU_LSC_REG_OKAY);
    TEST_CHECK(model.fault_valid == 0u);
    TEST_CHECK(model.fault_error_info == 0u);
    TEST_CHECK(model.fault_done_flags == 0u);
    TEST_CHECK(lsc_read(&model, &inputs, &outputs, 0u,
                        NPU_LSC_REG_FAULT_DETAIL,
                        &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(value == 0u);
    inputs.task_terminal_valid = 1u;
    inputs.task_irq_on_error = 0u;
    inputs.task_status = 0x02u;
    inputs.task_command_id = 11u;
    inputs.task_engine = 3u;
    inputs.task_opcode = 0x61u;
    inputs.task_fault_addr = UINT64_C(0x6000);
    inputs.task_error_info = UINT32_C(0xc001c0de);
    inputs.task_done_flags = UINT16_C(0x8040);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    inputs.task_terminal_valid = 0u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.fault_command_id == 11u);
    TEST_CHECK((model.irq_status & NPU_LSC_IRQ_ERROR) == 0u);

    inputs.perf_increment[0] = 3u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(model.perf_counter[0] == 3u);
    TEST_CHECK(outputs.debug_frozen == 0u);
    inputs.perf_increment[0] = 0u;
    TEST_CHECK(lsc_read(
                   &model, &inputs, &outputs, 0u,
                   NPU_LSC_REG_PERF_BASE,
                   &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(value == 0u);
    TEST_CHECK(lsc_read(
                   &model, &inputs, &outputs, 1u,
                   NPU_LSC_REG_PERF_BASE,
                   &value) == NPU_LSC_REG_OKAY);
    TEST_CHECK(value == 3u);
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_PERF_BASE,
                         UINT64_MAX,
                         0xffu) == NPU_LSC_REG_OKAY);
    TEST_CHECK(model.perf_counter[0] == 3u);
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 0u,
                         NPU_LSC_REG_PERF_CONTROL,
                         NPU_LSC_PERF_FREEZE,
                         0x01u) == NPU_LSC_REG_OKAY);
    TEST_CHECK(outputs.debug_frozen == 0u);
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 1u,
                         NPU_LSC_REG_PERF_CONTROL,
                         NPU_LSC_PERF_FREEZE,
                         0x01u) == NPU_LSC_REG_OKAY);
    TEST_CHECK(outputs.debug_frozen == 1u);
    inputs.perf_increment[0] = 5u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    inputs.perf_increment[0] = 0u;
    TEST_CHECK(model.perf_counter[0] == 3u);
    TEST_CHECK(lsc_write(&model, &inputs, &outputs, 1u,
                         NPU_LSC_REG_PERF_CONTROL,
                         NPU_LSC_PERF_CLEAR,
                         0x01u) == NPU_LSC_REG_OKAY);
    TEST_CHECK(model.perf_counter[0] == 0u);

    lsc_set_idle(&inputs, 0u);
    inputs.issue_idle = 1u;
    inputs.soft_reset_req = 1u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.cfe_quiesce == 1u);
    TEST_CHECK(outputs.ts_quiesce == 1u);
    TEST_CHECK(outputs.eng_abort == 0x0fu);
    TEST_CHECK(outputs.soft_reset_done == 0u);
    lsc_set_idle(&inputs, 1u);
    inputs.ts_idle = 0u;
    inputs.ts_quiescent = 1u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.core_idle == 0u);
    TEST_CHECK(outputs.internal_soft_reset_pulse == 1u);
    TEST_CHECK(outputs.soft_reset_done == 0u);
    TEST_CHECK(outputs.param_lock == 0u);
    TEST_CHECK(outputs.l1_diag_enable == 0u);
    TEST_CHECK(model.fault_command_id == 11u);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.internal_soft_reset_pulse == 0u);
    TEST_CHECK(outputs.soft_reset_done == 0u);
    inputs.internal_soft_reset_done = 1u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.soft_reset_done == 1u);
    inputs.soft_reset_req = 0u;
    inputs.internal_soft_reset_done = 0u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.soft_reset_done == 0u);

    lsc_set_idle(&inputs, 0u);
    inputs.power_down_req = 1u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.power_down_ack == 0u);
    inputs.power_down_req = 0u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    lsc_set_idle(&inputs, 1u);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.power_down_ack == 0u);

    inputs.issue_idle = 0u;
    inputs.power_down_req = 1u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.core_idle == 0u);
    TEST_CHECK(outputs.power_down_ack == 0u);
    TEST_CHECK(outputs.cfe_quiesce == 0u);
    inputs.issue_idle = 1u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.power_down_ack == 1u);
    TEST_CHECK(outputs.cfe_quiesce == 1u);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.power_down_ack == 1u);
    inputs.power_down_req = 0u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK(outputs.power_down_ack == 0u);

    inputs.wdt_timeout = 1u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    inputs.wdt_timeout = 0u;
    npu_lsc_cycle_step(&model, &inputs, &outputs);
    TEST_CHECK((model.reset_reason & NPU_LSC_RESET_WATCHDOG) != 0u);
    TEST_CHECK(outputs.irq_error == 1u);

    TEST_CHECK(lsc_test_external_errors() == 0);

    return 0;
}

#ifdef NPU_LSC_CYCLE_STANDALONE
int main(void)
{
    return test_lsc_cycle() == 0 ? 0 : 1;
}
#endif
