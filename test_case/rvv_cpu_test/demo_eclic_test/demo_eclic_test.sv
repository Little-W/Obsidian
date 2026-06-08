

`ifndef DEMO_ECLIC_TEST_SV
`define DEMO_ECLIC_TEST_SV

class demo_eclic_test extends chip_noc_base_test;
    `uvm_component_utils(demo_eclic_test)
    extern function new(string name = "demo_eclic_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function demo_eclic_test::new(string name = "demo_eclic_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task demo_eclic_test::main_phase(uvm_phase phase);
    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    check_simend();
    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
