

`ifndef CPU_INT_PLIC_TEST_SV
`define CPU_INT_PLIC_TEST_SV

class cpu_int_plic_test extends cpu_int_plic_base_test; //andyf
    `uvm_component_utils(cpu_int_plic_test)
    extern function new(string name = "cpu_int_plic_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_int_plic_test::new(string name = "cpu_int_plic_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_int_plic_test::main_phase(uvm_phase phase);
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

    intr_handler_check(`MCU_GPIO_INTR31_IRQ_ID, `MCU_GPIO_INTR31_PATH);
    intr_handler_check(`MCU_GPIO_INTR30_IRQ_ID, `MCU_GPIO_INTR30_PATH);
    intr_handler_check(`MCU_GPIO_INTR29_IRQ_ID, `MCU_GPIO_INTR29_PATH);
    intr_handler_check(`MCU_GPIO_INTR28_IRQ_ID, `MCU_GPIO_INTR28_PATH);
    intr_handler_check(`MCU_GPIO_INTR27_IRQ_ID, `MCU_GPIO_INTR27_PATH);
    intr_handler_check(`MCU_GPIO_INTR26_IRQ_ID, `MCU_GPIO_INTR26_PATH);
    intr_handler_check(`MCU_GPIO_INTR25_IRQ_ID, `MCU_GPIO_INTR25_PATH);
    intr_handler_check(`MCU_GPIO_INTR24_IRQ_ID, `MCU_GPIO_INTR24_PATH);
    intr_handler_check(`MCU_GPIO_INTR23_IRQ_ID, `MCU_GPIO_INTR23_PATH);
    intr_handler_check(`MCU_GPIO_INTR22_IRQ_ID, `MCU_GPIO_INTR22_PATH);
    intr_handler_check(`MCU_GPIO_INTR21_IRQ_ID, `MCU_GPIO_INTR21_PATH);
    intr_handler_check(`MCU_GPIO_INTR20_IRQ_ID, `MCU_GPIO_INTR20_PATH);
    intr_handler_check(`MCU_GPIO_INTR19_IRQ_ID, `MCU_GPIO_INTR19_PATH);
    intr_handler_check(`MCU_GPIO_INTR18_IRQ_ID, `MCU_GPIO_INTR18_PATH);
    intr_handler_check(`MCU_GPIO_INTR17_IRQ_ID, `MCU_GPIO_INTR17_PATH);
    intr_handler_check(`MCU_GPIO_INTR16_IRQ_ID, `MCU_GPIO_INTR16_PATH);
    intr_handler_check(`MCU_GPIO_INTR15_IRQ_ID, `MCU_GPIO_INTR15_PATH);
    intr_handler_check(`MCU_GPIO_INTR14_IRQ_ID, `MCU_GPIO_INTR14_PATH);
    intr_handler_check(`MCU_GPIO_INTR13_IRQ_ID, `MCU_GPIO_INTR13_PATH);
    intr_handler_check(`MCU_GPIO_INTR12_IRQ_ID, `MCU_GPIO_INTR12_PATH);
    intr_handler_check(`MCU_GPIO_INTR11_IRQ_ID, `MCU_GPIO_INTR11_PATH);
    intr_handler_check(`MCU_GPIO_INTR10_IRQ_ID, `MCU_GPIO_INTR10_PATH);
    intr_handler_check(`MCU_GPIO_INTR9_IRQ_ID, `MCU_GPIO_INTR9_PATH);
    intr_handler_check(`MCU_GPIO_INTR8_IRQ_ID, `MCU_GPIO_INTR8_PATH);
    intr_handler_check(`AON_GPIO_INTR31_IRQ_ID, `AON_GPIO_INTR31_PATH);
    intr_handler_check(`AON_GPIO_INTR30_IRQ_ID, `AON_GPIO_INTR30_PATH);
    intr_handler_check(`AON_GPIO_INTR29_IRQ_ID, `AON_GPIO_INTR29_PATH);
    intr_handler_check(`AON_GPIO_INTR28_IRQ_ID, `AON_GPIO_INTR28_PATH);
    intr_handler_check(`AON_GPIO_INTR27_IRQ_ID, `AON_GPIO_INTR27_PATH);
    intr_handler_check(`AON_GPIO_INTR26_IRQ_ID, `AON_GPIO_INTR26_PATH);
    intr_handler_check(`AON_GPIO_INTR25_IRQ_ID, `AON_GPIO_INTR25_PATH);
    intr_handler_check(`AON_GPIO_INTR24_IRQ_ID, `AON_GPIO_INTR24_PATH);
    intr_handler_check(`AON_GPIO_INTR23_IRQ_ID, `AON_GPIO_INTR23_PATH);
    intr_handler_check(`AON_GPIO_INTR22_IRQ_ID, `AON_GPIO_INTR22_PATH);
    intr_handler_check(`AON_GPIO_INTR21_IRQ_ID, `AON_GPIO_INTR21_PATH);
    intr_handler_check(`AON_GPIO_INTR20_IRQ_ID, `AON_GPIO_INTR20_PATH);
    intr_handler_check(`AON_GPIO_INTR19_IRQ_ID, `AON_GPIO_INTR19_PATH);
    intr_handler_check(`AON_GPIO_INTR18_IRQ_ID, `AON_GPIO_INTR18_PATH);
    intr_handler_check(`AON_GPIO_INTR17_IRQ_ID, `AON_GPIO_INTR17_PATH);
    intr_handler_check(`AON_GPIO_INTR16_IRQ_ID, `AON_GPIO_INTR16_PATH);
    intr_handler_check(`AON_GPIO_INTR15_IRQ_ID, `AON_GPIO_INTR15_PATH);
    intr_handler_check(`AON_GPIO_INTR14_IRQ_ID, `AON_GPIO_INTR14_PATH);
    intr_handler_check(`AON_GPIO_INTR13_IRQ_ID, `AON_GPIO_INTR13_PATH);
    intr_handler_check(`AON_GPIO_INTR12_IRQ_ID, `AON_GPIO_INTR12_PATH);
    intr_handler_check(`AON_GPIO_INTR11_IRQ_ID, `AON_GPIO_INTR11_PATH);
    intr_handler_check(`AON_GPIO_INTR10_IRQ_ID, `AON_GPIO_INTR10_PATH);
    intr_handler_check(`AON_GPIO_INTR9_IRQ_ID, `AON_GPIO_INTR9_PATH);
    intr_handler_check(`AON_GPIO_INTR8_IRQ_ID, `AON_GPIO_INTR8_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR15_IRQ_ID, `MCU_MAILBOX_INTR15_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR14_IRQ_ID, `MCU_MAILBOX_INTR14_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR13_IRQ_ID, `MCU_MAILBOX_INTR13_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR12_IRQ_ID, `MCU_MAILBOX_INTR12_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR11_IRQ_ID, `MCU_MAILBOX_INTR11_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR10_IRQ_ID, `MCU_MAILBOX_INTR10_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR9_IRQ_ID, `MCU_MAILBOX_INTR9_PATH);
    intr_handler_check(`MCU_MAILBOX_INTR8_IRQ_ID, `MCU_MAILBOX_INTR8_PATH);
    intr_handler_check(`MCU_DMA_CH7_INTR_IRQ_ID, `MCU_DMA_CH7_INTR_PATH);
    intr_handler_check(`MCU_DMA_CH6_INTR_IRQ_ID, `MCU_DMA_CH6_INTR_PATH);
    intr_handler_check(`MCU_DMA_CH5_INTR_IRQ_ID, `MCU_DMA_CH5_INTR_PATH);
    intr_handler_check(`MCU_DMA_CH4_INTR_IRQ_ID, `MCU_DMA_CH4_INTR_PATH);
    intr_handler_check(`MCU_DMA_CH3_INTR_IRQ_ID, `MCU_DMA_CH3_INTR_PATH);
    intr_handler_check(`MCU_DMA_CH2_INTR_IRQ_ID, `MCU_DMA_CH2_INTR_PATH);
    intr_handler_check(`MCU_DMA_CH1_INTR_IRQ_ID, `MCU_DMA_CH1_INTR_PATH);
    intr_handler_check(`MCU_DMA_CH0_INTR_IRQ_ID, `MCU_DMA_CH0_INTR_PATH);
    // intr_handler_check(`UCIE1_P2P_INTR_IRQ_ID, `UCIE1_P2P_INTR_PATH);
    intr_handler_check(`UCIE1_MCU_DB2SOC_INTR_IRQ_ID, `UCIE1_MCU_DB2SOC_INTR_PATH);
    intr_handler_check(`UCIE1_DBG_INTR_IRQ_ID, `UCIE1_DBG_INTR_PATH);
    // intr_handler_check(`UCIE0_P2P_INTR_IRQ_ID, `UCIE0_P2P_INTR_PATH);
    intr_handler_check(`UCIE0_MCU_DB2SOC_INTR_IRQ_ID, `UCIE0_MCU_DB2SOC_INTR_PATH);

    // ***************** 68 *****************

    intr_handler_check(`UCIE0_DBG_INTR_IRQ_ID, `UCIE0_DBG_INTR_PATH);
    // intr_handler_check(`HS_P2P_BRIDGE_INTR_IRQ_ID, `HS_P2P_BRIDGE_INTR_PATH);
    intr_handler_check(`T2_UEE_RAS_IRPT_IRQ_ID, `T2_UEE_RAS_IRPT_PATH);
    intr_handler_check(`HS_ETH_INTR_IRQ_ID, `HS_ETH_INTR_PATH);
    intr_handler_check(`HS_EMMC_WAKEUP_INTR_IRQ_ID, `HS_EMMC_WAKEUP_INTR_PATH);
    intr_handler_check(`HS_EMMC_INTR_IRQ_ID, `HS_EMMC_INTR_PATH);
    intr_handler_check(`HS_USB_BCA_INTR_IRQ_ID, `HS_USB_BCA_INTR_PATH);
    intr_handler_check(`HS_USB_INTR1_IRQ_ID, `HS_USB_INTR1_PATH);
    intr_handler_check(`HS_USB_INTR0_IRQ_ID, `HS_USB_INTR0_PATH);
    intr_handler_check(`HS_NVME_INTR_IRQ_ID, `HS_NVME_INTR_PATH);
    intr_handler_check(`HS_DMA_PMU_IRPT_IRQ_ID, `HS_DMA_PMU_IRPT_PATH);
    intr_handler_check(`HS_DMA_RAS_IRPT_IRQ_ID, `HS_DMA_RAS_IRPT_PATH);
    intr_handler_check(`HS_DMA_CH3_INTR_IRQ_ID, `HS_DMA_CH3_INTR_PATH);
    intr_handler_check(`HS_DMA_CH2_INTR_IRQ_ID, `HS_DMA_CH2_INTR_PATH);
    intr_handler_check(`HS_DMA_CH1_INTR_IRQ_ID, `HS_DMA_CH1_INTR_PATH);
    intr_handler_check(`HS_DMA_CH0_INTR_IRQ_ID, `HS_DMA_CH0_INTR_PATH);
    intr_handler_check(`HS_PCIESS01_PMU_IRPT_IRQ_ID, `HS_PCIESS01_PMU_IRPT_PATH);
    intr_handler_check(`HS_PCIESS01_RAS_IRPT_IRQ_ID, `HS_PCIESS01_RAS_IRPT_PATH);
    intr_handler_check(`HS_PCIESS01_MSI_INTR_IRQ_ID, `HS_PCIESS01_MSI_INTR_PATH);
    intr_handler_check(`HS_PCIESS01_MSIDONE_INTR_IRQ_ID, `HS_PCIESS01_MSIDONE_INTR_PATH);
    intr_handler_check(`HS_PCIESS01_INTX_INTR_IRQ_ID, `HS_PCIESS01_INTX_INTR_PATH);
    intr_handler_check(`HS_PCIESS01_STATUS_INTR_IRQ_ID, `HS_PCIESS01_STATUS_INTR_PATH);
    intr_handler_check(`HS_PCIESS00_PMU_IRPT_IRQ_ID, `HS_PCIESS00_PMU_IRPT_PATH);
    intr_handler_check(`HS_PCIESS00_RAS_IRPT_IRQ_ID, `HS_PCIESS00_RAS_IRPT_PATH);
    intr_handler_check(`HS_PCIESS00_MSI_INTR_IRQ_ID, `HS_PCIESS00_MSI_INTR_PATH);
    intr_handler_check(`HS_PCIESS00_MSIDONE_INTR_IRQ_ID, `HS_PCIESS00_MSIDONE_INTR_PATH);
    intr_handler_check(`HS_PCIESS00_INTX_INTR_IRQ_ID, `HS_PCIESS00_INTX_INTR_PATH);
    intr_handler_check(`HS_PCIESS00_STATUS_INTR_IRQ_ID, `HS_PCIESS00_STATUS_INTR_PATH);
    intr_handler_check(`LP3_DDR_INT_IRQ_ID, `LP3_DDR_INT_PATH);
    intr_handler_check(`LP2_DDR_INT_IRQ_ID, `LP2_DDR_INT_PATH);
    intr_handler_check(`LP1_DDR_INT_IRQ_ID, `LP1_DDR_INT_PATH);
    intr_handler_check(`LP0_DDR_INT_IRQ_ID, `LP0_DDR_INT_PATH);
    intr_handler_check(`MEDIA_SUB_DPU_INTR_IRQ_ID, `MEDIA_SUB_DPU_INTR_PATH);
    intr_handler_check(`MEDIA_SUB_GPU_INTR_IRQ_ID, `MEDIA_SUB_GPU_INTR_PATH);
    intr_handler_check(`MEDIA_SUB_JPU_INTR_IRQ_ID, `MEDIA_SUB_JPU_INTR_PATH);
    intr_handler_check(`MEDIA_SUB_VPU_INTR_3_IRQ_ID, `MEDIA_SUB_VPU_INTR_3_PATH);
    intr_handler_check(`MEDIA_SUB_VPU_INTR_2_IRQ_ID, `MEDIA_SUB_VPU_INTR_2_PATH);
    intr_handler_check(`MEDIA_SUB_VPU_INTR_1_IRQ_ID, `MEDIA_SUB_VPU_INTR_1_PATH);
    intr_handler_check(`MEDIA_SUB_VPU_INTR_0_IRQ_ID, `MEDIA_SUB_VPU_INTR_0_PATH);
    intr_handler_check(`MCU_I2S1_INTR_IRQ_ID, `MCU_I2S1_INTR_PATH);
    intr_handler_check(`MCU_I3C1_INTR_IRQ_ID, `MCU_I3C1_INTR_PATH);
    intr_handler_check(`MCU_I2C3_INTR_IRQ_ID, `MCU_I2C3_INTR_PATH);
    intr_handler_check(`MCU_I2C2_INTR_IRQ_ID, `MCU_I2C2_INTR_PATH);
    intr_handler_check(`MCU_XSPI1_INTR_IRQ_ID, `MCU_XSPI1_INTR_PATH);
    intr_handler_check(`MCU_SPI1_INTR_IRQ_ID, `MCU_SPI1_INTR_PATH);
    intr_handler_check(`MCU_UART3_INTR_IRQ_ID, `MCU_UART3_INTR_PATH);
    intr_handler_check(`MCU_UART2_INTR_IRQ_ID, `MCU_UART2_INTR_PATH);
    intr_handler_check(`MCU_TIMER1_INTR_IRQ_ID, `MCU_TIMER1_INTR_PATH);
    intr_handler_check(`MCU_TIMER0_INTR_IRQ_ID, `MCU_TIMER0_INTR_PATH);

    //117 update

    check_simend();

    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase
`endif
