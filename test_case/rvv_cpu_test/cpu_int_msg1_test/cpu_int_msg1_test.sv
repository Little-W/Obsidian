

`ifndef CPU_INT_MSG1_TEST_SV
`define CPU_INT_MSG1_TEST_SV

class cpu_int_msg1_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_int_msg1_test)
    extern function new(string name = "cpu_int_msg1_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_int_msg1_test::new(string name = "cpu_int_msg1_test", uvm_component parent = null);
    super.new(name,parent);
 
endfunction:new

task cpu_int_msg1_test::main_phase(uvm_phase phase);
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

//andyf ++ 64 ->129
    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_pmu_intr", 1);
     wait_label(19+ 64  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_pmu_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_ras_intr", 1);
     wait_label(19+ 65  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_ras_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_nvme_intr", 1);
     wait_label(19+ 66   );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_nvme_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_p2p_bridge_intr", 1);
     wait_label(19+ 67  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_p2p_bridge_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess11_intr[5]", 1);
     wait_label(19+ 68  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess11_intr[5]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess11_intr[4]", 1);
     wait_label(19+ 69  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess11_intr[4]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess11_intr[3]", 1);
     wait_label(19+ 70  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess11_intr[3]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess10_intr[5]", 1);
     wait_label(19+ 71  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess10_intr[5]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess10_intr[4]", 1);
     wait_label(19+ 72  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess10_intr[4]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess10_intr[3]", 1);
     wait_label(19+  73 );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess10_intr[3]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_intr[5]", 1);
     wait_label(19+ 74  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_intr[5]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_intr[4]", 1);
     wait_label(19+ 75  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_intr[4]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_intr[3]", 1);
     wait_label(19+ 76  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_intr[3]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_pmu_intr", 1);
     wait_label(19+  77 );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_pmu_intr");
    send_label('haabbccdd);
    #1us;
                    
    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_ras_intr", 1);
     wait_label(19+ 78  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_ras_intr");
    send_label('haabbccdd);
    #1us;
                    
    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_intr[5]", 1);
     wait_label(19+ 79  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_intr[5]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_intr[4]", 1);
     wait_label(19+ 80  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_intr[4]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_intr[3]", 1);
     wait_label(19+  81 );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_intr[3]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.t2_uee_pmu_intr", 1);
     wait_label(19+ 82  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.t2_uee_pmu_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.t2_uee_ras_intr", 1);
     wait_label(19+ 83  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.t2_uee_ras_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_emmc_intr", 1);
     wait_label(19+  84 );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_emmc_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_emmc_wakeup_intr", 1);
     wait_label(19+ 85  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_emmc_wakeup_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_usb_tca_intr", 1);
     wait_label(19+ 86  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_usb_tca_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_usb_intr[1]", 1);
     wait_label(19+ 87  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_usb_intr[1]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_usb_intr[0]", 1);
     wait_label(19+ 88  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_usb_intr[0]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.lp3_ddr_intr", 1);
     wait_label(19+ 89  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.lp3_ddr_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.lp2_ddr_intr", 1);
     wait_label(19+ 90  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.lp2_ddr_intr");
    send_label('haabbccdd);
    #1us;
                     
    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.lp1_ddr_intr", 1);
     wait_label(19+ 91  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.lp1_ddr_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.lp0_ddr_intr", 1);
     wait_label(19+ 92  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.lp0_ddr_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess11_intr[0]", 1);
     wait_label(19+ 93  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess11_intr[0]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess10_intr[0]", 1);
     wait_label(19+ 94  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess10_intr[0]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_intr[0]", 1);
     wait_label(19+ 95  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_intr[0]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_intr[0]", 1);
     wait_label(19+ 96  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_intr[0]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_ch_intr[3]", 1);
     wait_label(19+ 97  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_ch_intr[3]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_ch_intr[2]", 1);
     wait_label(19+ 98  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_ch_intr[2]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_ch_intr[1]", 1);
     wait_label(19+ 99  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_ch_intr[1]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_ch_intr[0]", 1);
     wait_label(19+ 100  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_ch_intr[0]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i2s1_intr", 1);
     wait_label(19+ 101  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i2s1_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i3c1_intr", 1);
     wait_label(19+ 102  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i3c1_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i2c3_intr", 1);
     wait_label(19+ 103  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i2c3_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i2c2_intr", 1);
     wait_label(19+ 104  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i2c2_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_xspi1_intr", 1);
     wait_label(19+  105 );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_xspi1_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_spi1_intr", 1);
     wait_label(19+ 106  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_spi1_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_uart3_intr", 1);
     wait_label(19+ 107  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_uart3_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_uart2_intr", 1);
     wait_label(19+  108 );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_uart2_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_timer1_intr", 1);
     wait_label(19+ 109  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_timer1_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_timer0_intr", 1);
     wait_label(19+ 110  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_timer0_intr");
    send_label('haabbccdd);
    #1us;

        uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[7]", 1);
     wait_label(19+  111 );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[7]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[6]", 1);
     wait_label(19+ 112  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[6]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[5]", 1);
     wait_label(19+ 113  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[5]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[4]", 1);
     wait_label(19+ 114  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[4]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[3]", 1);
     wait_label(19+ 115  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[3]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[2]", 1);
     wait_label(19+  116 );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[2]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[1]", 1);
     wait_label(19+ 117  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[1]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[0]", 1);
     wait_label(19+ 118  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[0]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[7]", 1);
     wait_label(19+ 119  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[7]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[6]", 1);
     wait_label(19+ 120  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[6]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[5]", 1);
     wait_label(19+ 121  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[5]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[4]", 1);
     wait_label(19+ 122  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[4]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[3]", 1);
     wait_label(19+ 123  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[3]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[2]", 1);
     wait_label(19+ 124  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[2]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[1]", 1);
     wait_label(19+ 125  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[1]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[0]", 1);
     wait_label(19+ 126  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[0]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[7]", 1);
     wait_label(19+ 127  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[7]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[6]", 1);
     wait_label(19+ 128  );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[6]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[5]", 1);
     wait_label(19+  129 );
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[5]");
    send_label('haabbccdd);
    #1us;


    check_simend();

    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
