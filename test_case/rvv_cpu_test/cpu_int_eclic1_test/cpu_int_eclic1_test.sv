

`ifndef CPU_INT_ECLIC1_TEST_SV
`define CPU_INT_ECLIC1_TEST_SV

class cpu_int_eclic1_test extends cpu_int_eclic_base_test; //andyf
    `uvm_component_utils(cpu_int_eclic1_test)
    extern function new(string name = "cpu_int_eclic1_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_int_eclic1_test::new(string name = "cpu_int_eclic1_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_int_eclic1_test::main_phase(uvm_phase phase);
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
                     
    `uvm_info(get_type_name(),$psprintf("ECLIC1 start!"), UVM_LOW)

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
