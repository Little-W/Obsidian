

`ifndef DEMO_CACHE_TEST_SV
`define DEMO_CACHE_TEST_SV

class demo_cache_test extends chip_noc_base_test;
    `uvm_component_utils(demo_cache_test)
    extern function new(string name = "demo_cache_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function demo_cache_test::new(string name = "demo_cache_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task demo_cache_test::main_phase(uvm_phase phase);
    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    check_simend();
    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
