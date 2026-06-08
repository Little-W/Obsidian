

`ifndef CPU_INT_PLIC1_TEST_SV
`define CPU_INT_PLIC1_TEST_SV

class cpu_int_plic1_test extends cpu_int_plic_base_test;
    `uvm_component_utils(cpu_int_plic1_test)
    extern function new(string name = "cpu_int_plic1_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_int_plic1_test::new(string name = "cpu_int_plic1_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_int_plic1_test::main_phase(uvm_phase phase);
    bit[7:0] clk_flg = 0;
    int start_time;
    int end_time;
    int freq = 0;
    bit core_clk;

    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    repeat(100)begin
        @(posedge chip_top_vif.core0_core_clk);
    end

    `uvm_info(get_type_name(),$psprintf("wait 0x12345678"), UVM_LOW)
    wait_label('h12345678);

    `uvm_info(get_type_name(),$psprintf("force MCU_GLUE_0 start!"), UVM_LOW)


    intr_handler_check(`MCU_MAILBOX_INTR7_IRQ_ID, `MCU_MAILBOX_INTR7_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR6_IRQ_ID, `MCU_MAILBOX_INTR6_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR5_IRQ_ID, `MCU_MAILBOX_INTR5_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR4_IRQ_ID, `MCU_MAILBOX_INTR4_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR3_IRQ_ID, `MCU_MAILBOX_INTR3_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR2_IRQ_ID, `MCU_MAILBOX_INTR2_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR1_IRQ_ID, `MCU_MAILBOX_INTR1_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR0_IRQ_ID, `MCU_MAILBOX_INTR0_PATH);
    intr_handler_check(`MCU_GPIO_INTR7_IRQ_ID, `MCU_GPIO_INTR7_PATH);
    intr_handler_check(`MCU_GPIO_INTR6_IRQ_ID, `MCU_GPIO_INTR6_PATH);
    intr_handler_check(`MCU_GPIO_INTR5_IRQ_ID, `MCU_GPIO_INTR5_PATH);
    intr_handler_check(`MCU_GPIO_INTR4_IRQ_ID, `MCU_GPIO_INTR4_PATH);
    intr_handler_check(`MCU_GPIO_INTR3_IRQ_ID, `MCU_GPIO_INTR3_PATH);
    intr_handler_check(`MCU_GPIO_INTR2_IRQ_ID, `MCU_GPIO_INTR2_PATH);
    intr_handler_check(`MCU_GPIO_INTR1_IRQ_ID, `MCU_GPIO_INTR1_PATH);
    intr_handler_check(`MCU_GPIO_INTR0_IRQ_ID, `MCU_GPIO_INTR0_PATH);
    intr_handler_check(`AON_GPIO_INTR7_IRQ_ID, `AON_GPIO_INTR7_PATH);
    intr_handler_check(`AON_GPIO_INTR6_IRQ_ID, `AON_GPIO_INTR6_PATH);
    intr_handler_check(`AON_GPIO_INTR5_IRQ_ID, `AON_GPIO_INTR5_PATH);
    intr_handler_check(`AON_GPIO_INTR4_IRQ_ID, `AON_GPIO_INTR4_PATH);
    intr_handler_check(`AON_GPIO_INTR3_IRQ_ID, `AON_GPIO_INTR3_PATH);
    intr_handler_check(`AON_GPIO_INTR2_IRQ_ID, `AON_GPIO_INTR2_PATH);
    intr_handler_check(`AON_GPIO_INTR1_IRQ_ID, `AON_GPIO_INTR1_PATH);
    intr_handler_check(`AON_GPIO_INTR0_IRQ_ID, `AON_GPIO_INTR0_PATH);
    intr_handler_check(`AON_I2C1_INTR_IRQ_ID, `AON_I2C1_INTR_PATH);
    intr_handler_check(`AON_I2C0_INTR_IRQ_ID, `AON_I2C0_INTR_PATH);
    intr_handler_check(`AON_RTC_INTR_IRQ_ID, `AON_RTC_INTR_PATH);
    intr_handler_check(`AON_PVTC_INTR_IRQ_ID, `AON_PVTC_INTR_PATH);
    intr_handler_check(`HSM_MAILBOX_HOST_0_INTR_IRQ_ID, `HSM_MAILBOX_HOST_0_INTR_PATH);
    intr_handler_check(`HSM_MAILBOX_INTERNAL_INTR_IRQ_ID, `HSM_MAILBOX_INTERNAL_INTR_PATH);
    intr_handler_check(`HSM_TRNG0_TRNG_INTR_IRQ_ID, `HSM_TRNG0_TRNG_INTR_PATH);
    intr_handler_check(`HSM_HASH0_INTR_IRQ_ID, `HSM_HASH0_INTR_PATH);
    intr_handler_check(`HSM_CRYP0_INTR_IRQ_ID, `HSM_CRYP0_INTR_PATH);
    intr_handler_check(`HSM_ACRYP0_INTR_IRQ_ID, `HSM_ACRYP0_INTR_PATH);
    intr_handler_check(`HSM_RTC0_RTC_INTR_IRQ_ID, `HSM_RTC0_RTC_INTR_PATH);
    intr_handler_check(`HSM_BASIC_TIMER0_BSC_TIM_INTR_IRQ_ID, `HSM_BASIC_TIMER0_BSC_TIM_INTR_PATH);
    intr_handler_check(`HSM_USART0_UART_INTR_IRQ_ID, `HSM_USART0_UART_INTR_PATH);
    intr_handler_check(`HSM_UDMA0_UDMA_INTR_IRQ_ID, `HSM_UDMA0_UDMA_INTR_PATH);
    intr_handler_check(`MCU_CAN1_INTR_IRQ_ID, `MCU_CAN1_INTR_PATH);
    intr_handler_check(`MCU_CAN0_INTR_IRQ_ID, `MCU_CAN0_INTR_PATH);
    intr_handler_check(`MCU_ATB2AXI_INTR_IRQ_ID, `MCU_ATB2AXI_INTR_PATH);
    // intr_handler_check(`MCU_SDIO_INTR_IRQ_ID, `MCU_SDIO_INTR_PATH);
    intr_handler_check(`MCU_I2S0_INTR_IRQ_ID, `MCU_I2S0_INTR_PATH);
    intr_handler_check(`MCU_I3C0_INTR_IRQ_ID, `MCU_I3C0_INTR_PATH);
    intr_handler_check(`MCU_XSPI0_INTR_IRQ_ID, `MCU_XSPI0_INTR_PATH);
    intr_handler_check(`MCU_SPI0_INTR_IRQ_ID, `MCU_SPI0_INTR_PATH);
    intr_handler_check(`MCU_I2C1_INTR_IRQ_ID, `MCU_I2C1_INTR_PATH);
    intr_handler_check(`MCU_I2C0_INTR_IRQ_ID, `MCU_I2C0_INTR_PATH);
    intr_handler_check(`MCU_UART1_INTR_IRQ_ID, `MCU_UART1_INTR_PATH);
    intr_handler_check(`MCU_UART0_INTR_IRQ_ID, `MCU_UART0_INTR_PATH);
    intr_handler_check(`MCU_NOC_INTR_IRQ_ID, `MCU_NOC_INTR_PATH);
    intr_handler_check(`HS_DATA_NOC_INTR_IRQ_ID, `HS_DATA_NOC_INTR_PATH);
    intr_handler_check(`HS_REG_NOC_INTR_IRQ_ID, `HS_REG_NOC_INTR_PATH);
    intr_handler_check(`TOP_CRG_PLL_INTR_IRQ_ID, `TOP_CRG_PLL_INTR_PATH);
    intr_handler_check(`SOC_NOC_INTR_IRQ_ID, `SOC_NOC_INTR_PATH);
    intr_handler_check(`MEDIA_SUB_GPU_SYSERR_INTR_IRQ_ID, `MEDIA_SUB_GPU_SYSERR_INTR_PATH);
    intr_handler_check(`AON_CRG_INTR_IRQ_ID, `AON_CRG_INTR_PATH);
    intr_handler_check(`T2_UEE_PMU_IRPT_IRQ_ID, `T2_UEE_PMU_IRPT_PATH);
    intr_handler_check(`HS_USB_HOST_SYS_ERR_INTR_IRQ_ID, `HS_USB_HOST_SYS_ERR_INTR_PATH);
    intr_handler_check(`HS_HS_DMA_INTR_IRQ_ID, `HS_HS_DMA_INTR_PATH);
    intr_handler_check(`HS_PCIESS01_ATU_INTR_IRQ_ID, `HS_PCIESS01_ATU_INTR_PATH);
    intr_handler_check(`HS_PCIESS01_ERR_INTR_IRQ_ID, `HS_PCIESS01_ERR_INTR_PATH);
    intr_handler_check(`HS_PCIESS01_DMA_INTR_IRQ_ID, `HS_PCIESS01_DMA_INTR_PATH);
    intr_handler_check(`HS_PCIESS00_ATU_INTR_IRQ_ID, `HS_PCIESS00_ATU_INTR_PATH);
    intr_handler_check(`HS_PCIESS00_ERR_INTR_IRQ_ID, `HS_PCIESS00_ERR_INTR_PATH);
    intr_handler_check(`HS_PCIESS00_DMA_INTR_IRQ_ID, `HS_PCIESS00_DMA_INTR_PATH);
    intr_handler_check(`MCU_DMA_INTR_IRQ_ID, `MCU_DMA_INTR_PATH);

    intr_handler_check(`PMU_EVT_WAKEUP_INTR_IRQ_ID, `PMU_EVT_WAKEUP_INTR_PATH);
    intr_handler_check(`NPU_CORE0_TBU0_RAS_INTR_IRQ_ID, `NPU_CORE0_TBU0_RAS_INTR_PATH);
    intr_handler_check(`NPU_CORE0_TBU0_PMU_INTR_IRQ_ID, `NPU_CORE0_TBU0_PMU_INTR_PATH);
    intr_handler_check(`NPU_CORE0_TBU1_RAS_INTR_IRQ_ID, `NPU_CORE0_TBU1_RAS_INTR_PATH);
    intr_handler_check(`NPU_CORE0_TBU1_PMU_INTR_IRQ_ID, `NPU_CORE0_TBU1_PMU_INTR_PATH);
    intr_handler_check(`NPU_CORE1_TBU0_RAS_INTR_IRQ_ID, `NPU_CORE1_TBU0_RAS_INTR_PATH);
    intr_handler_check(`NPU_CORE1_TBU0_PMU_INTR_IRQ_ID, `NPU_CORE1_TBU0_PMU_INTR_PATH);
    intr_handler_check(`NPU_CORE1_TBU1_RAS_INTR_IRQ_ID, `NPU_CORE1_TBU1_RAS_INTR_PATH);
    intr_handler_check(`NPU_CORE1_TBU1_PMU_INTR_IRQ_ID, `NPU_CORE1_TBU1_PMU_INTR_PATH);
    intr_handler_check(`NPU_CORE2_TBU0_RAS_INTR_IRQ_ID, `NPU_CORE2_TBU0_RAS_INTR_PATH);
    intr_handler_check(`NPU_CORE2_TBU0_PMU_INTR_IRQ_ID, `NPU_CORE2_TBU0_PMU_INTR_PATH);
    intr_handler_check(`NPU_CORE2_TBU1_RAS_INTR_IRQ_ID, `NPU_CORE2_TBU1_RAS_INTR_PATH);
    intr_handler_check(`NPU_CORE2_TBU1_PMU_INTR_IRQ_ID, `NPU_CORE2_TBU1_PMU_INTR_PATH);
    intr_handler_check(`NPU_CORE3_TBU0_RAS_INTR_IRQ_ID, `NPU_CORE3_TBU0_RAS_INTR_PATH);
    intr_handler_check(`NPU_CORE3_TBU0_PMU_INTR_IRQ_ID, `NPU_CORE3_TBU0_PMU_INTR_PATH);
    intr_handler_check(`NPU_CORE3_TBU1_RAS_INTR_IRQ_ID, `NPU_CORE3_TBU1_RAS_INTR_PATH);
    intr_handler_check(`NPU_CORE3_TBU1_PMU_INTR_IRQ_ID, `NPU_CORE3_TBU1_PMU_INTR_PATH);

    intr_handler_check(`MEDIA_TBU_PMU_INTR_IRQ_ID, `MEDIA_TBU_PMU_INTR_PATH);

    //

    intr_handler_check(`MEDIA_TBU_RAS_INTR_IRQ_ID, `MEDIA_TBU_RAS_INTR_PATH);
    intr_handler_check(`TCU_GLOBAL_INTR_S_IRQ_ID, `TCU_GLOBAL_INTR_S_PATH);
    intr_handler_check(`TCU_PRI_Q_INTR_NS_IRQ_ID, `TCU_PRI_Q_INTR_NS_PATH);
    intr_handler_check(`TCU_GLOBAL_INTR_NS_IRQ_ID, `TCU_GLOBAL_INTR_NS_PATH);
    intr_handler_check(`TCU_CMD_SYNC_INTR_NS_IRQ_ID, `TCU_CMD_SYNC_INTR_NS_PATH);
    intr_handler_check(`TCU_CMD_SYNC_INTR_S_IRQ_ID, `TCU_CMD_SYNC_INTR_S_PATH);
    intr_handler_check(`TCU_EVENT_Q_INTR_NS_IRQ_ID, `TCU_EVENT_Q_INTR_NS_PATH);
    intr_handler_check(`TCU_EVENT_Q_INTR_S_IRQ_ID, `TCU_EVENT_Q_INTR_S_PATH);
    intr_handler_check(`TCU_PMU_INTR_IRQ_ID, `TCU_PMU_INTR_PATH);
    intr_handler_check(`TCU_RAS_INTR_IRQ_ID, `TCU_RAS_INTR_PATH);
    intr_handler_check(`BARRIER_INTR_IRQ_ID, `BARRIER_INTR_PATH);
    intr_handler_check(`NPU_INTR3_0_IRQ_ID, `NPU_INTR3_0_PATH);
    intr_handler_check(`NPU_INTR3_1_IRQ_ID, `NPU_INTR3_1_PATH);
    intr_handler_check(`NPU_INTR3_2_IRQ_ID, `NPU_INTR3_2_PATH);
    intr_handler_check(`NPU_INTR3_3_IRQ_ID, `NPU_INTR3_3_PATH);
    intr_handler_check(`NPU_INTR3_4_IRQ_ID, `NPU_INTR3_4_PATH);
    intr_handler_check(`NPU_INTR3_5_IRQ_ID, `NPU_INTR3_5_PATH);
    intr_handler_check(`NPU_INTR3_6_IRQ_ID, `NPU_INTR3_6_PATH);
    intr_handler_check(`NPU_INTR3_7_IRQ_ID, `NPU_INTR3_7_PATH);
    intr_handler_check(`NPU_INTR2_0_IRQ_ID, `NPU_INTR2_0_PATH);
    intr_handler_check(`NPU_INTR2_1_IRQ_ID, `NPU_INTR2_1_PATH);
    intr_handler_check(`NPU_INTR2_2_IRQ_ID, `NPU_INTR2_2_PATH);
    intr_handler_check(`NPU_INTR2_3_IRQ_ID, `NPU_INTR2_3_PATH);
    intr_handler_check(`NPU_INTR2_4_IRQ_ID, `NPU_INTR2_4_PATH);
    intr_handler_check(`NPU_INTR2_5_IRQ_ID, `NPU_INTR2_5_PATH);
    intr_handler_check(`NPU_INTR2_6_IRQ_ID, `NPU_INTR2_6_PATH);
    intr_handler_check(`NPU_INTR2_7_IRQ_ID, `NPU_INTR2_7_PATH);
    intr_handler_check(`NPU_INTR1_0_IRQ_ID, `NPU_INTR1_0_PATH);
    intr_handler_check(`NPU_INTR1_1_IRQ_ID, `NPU_INTR1_1_PATH);
    intr_handler_check(`NPU_INTR1_2_IRQ_ID, `NPU_INTR1_2_PATH);
    intr_handler_check(`NPU_INTR1_3_IRQ_ID, `NPU_INTR1_3_PATH);
    intr_handler_check(`NPU_INTR1_4_IRQ_ID, `NPU_INTR1_4_PATH);
    intr_handler_check(`NPU_INTR1_5_IRQ_ID, `NPU_INTR1_5_PATH);
    intr_handler_check(`NPU_INTR1_6_IRQ_ID, `NPU_INTR1_6_PATH);
    intr_handler_check(`NPU_INTR1_7_IRQ_ID, `NPU_INTR1_7_PATH);
    intr_handler_check(`NPU_INTR0_0_IRQ_ID, `NPU_INTR0_0_PATH);
    intr_handler_check(`NPU_INTR0_1_IRQ_ID, `NPU_INTR0_1_PATH);
    intr_handler_check(`NPU_INTR0_2_IRQ_ID, `NPU_INTR0_2_PATH);
    intr_handler_check(`NPU_INTR0_3_IRQ_ID, `NPU_INTR0_3_PATH);
    intr_handler_check(`NPU_INTR0_4_IRQ_ID, `NPU_INTR0_4_PATH);
    intr_handler_check(`NPU_INTR0_5_IRQ_ID, `NPU_INTR0_5_PATH);
    intr_handler_check(`NPU_INTR0_6_IRQ_ID, `NPU_INTR0_6_PATH);
    intr_handler_check(`NPU_INTR0_7_IRQ_ID, `NPU_INTR0_7_PATH);
    intr_handler_check(`NPU_WDT_INTR3_IRQ_ID, `NPU_WDT_INTR3_PATH);
    intr_handler_check(`NPU_WDT_INTR2_IRQ_ID, `NPU_WDT_INTR2_PATH);
    intr_handler_check(`NPU_WDT_INTR1_IRQ_ID, `NPU_WDT_INTR1_PATH);
    intr_handler_check(`NPU_WDT_INTR0_IRQ_ID, `NPU_WDT_INTR0_PATH);
    intr_handler_check(`MCU_WDT_INTR_IRQ_ID, `MCU_WDT_INTR_PATH);


    check_simend();

    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
