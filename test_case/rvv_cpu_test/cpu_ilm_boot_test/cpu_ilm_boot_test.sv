

`ifndef CPU_ILM_BOOT_TEST_SV
`define CPU_ILM_BOOT_TEST_SV

class cpu_ilm_boot_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_ilm_boot_test)
    extern function new(string name = "cpu_ilm_boot_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_ilm_boot_test::new(string name = "cpu_ilm_boot_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_ilm_boot_test::main_phase(uvm_phase phase);
    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    uvm_hdl_force  ("hdl_top.T100_TOP_u.DIE_ID0", 0);
    uvm_hdl_force  ("hdl_top.T100_TOP_u.DIE_ID1", 0);
    
    uvm_hdl_force  ("hdl_top.T100_TOP_u.CHIP_ID0", 0);
    uvm_hdl_force  ("hdl_top.T100_TOP_u.CHIP_ID1", 0);
    uvm_hdl_force  ("hdl_top.T100_TOP_u.BOOT_SEQ", 0); //bing xing
    
//    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.core0_stop_on_reset",0); 
    
    wait_label(1);
    $display("cpu_ilm_boot_test wait_label 1 \n");

    send_label(2);
    $display("cpu_ilm_boot_test send_label 2 \n");


    check_simend();
    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
