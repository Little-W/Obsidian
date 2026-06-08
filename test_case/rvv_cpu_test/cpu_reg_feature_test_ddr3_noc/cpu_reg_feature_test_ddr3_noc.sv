

`ifndef CPU_REG_FEATURE_TEST_DDR3_NOC_SV
`define CPU_REG_FEATURE_TEST_DDR3_NOC_SV

class cpu_reg_feature_test_ddr3_noc extends chip_noc_base_test;
    `uvm_component_utils(cpu_reg_feature_test_ddr3_noc)
    extern function new(string name = "cpu_reg_feature_test_ddr3_noc", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_reg_feature_test_ddr3_noc::new(string name = "cpu_reg_feature_test_ddr3_noc", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_reg_feature_test_ddr3_noc::main_phase(uvm_phase phase);
    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    check_simend();
    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
