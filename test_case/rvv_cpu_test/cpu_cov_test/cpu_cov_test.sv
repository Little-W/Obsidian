

`ifndef CPU_COV_TEST_SV
`define CPU_COV_TEST_SV

class cpu_cov_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_cov_test)
    extern function new(string name = "cpu_cov_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_cov_test::new(string name = "cpu_cov_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_cov_test::main_phase(uvm_phase phase);
    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)
/*
    wait_label(55);
    #1ms;
    uvm_hdl_force("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_CPU_900_0.por_reset_n", 0);
    #100ns;
    uvm_hdl_release("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_CPU_900_0.por_reset_n");
*/
    
    check_simend();
    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
