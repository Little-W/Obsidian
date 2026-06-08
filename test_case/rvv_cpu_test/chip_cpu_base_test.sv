

`ifndef CHIP_CPU_BASE_TEST_SV
`define CHIP_CPU_BASE_TEST_SV


class cpu_int_eclic_base_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_int_eclic_base_test)
    extern function new(string name = "cpu_int_eclic_base_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
    extern task intr_handler_check(input int intr_id, input string intr_path);
endclass

function cpu_int_eclic_base_test::new(string name = "cpu_int_eclic_base_test", uvm_component parent = null);
    super.new(name,parent);
endfunction:new

task cpu_int_eclic_base_test::main_phase(uvm_phase phase);
    super.main_phase(phase);
    phase.raise_objection(this);
    phase.drop_objection(this); 
endtask:main_phase


task cpu_int_eclic_base_test::intr_handler_check(input int intr_id, input string intr_path);
    bit[31:0] read_val;
    uvm_hdl_force(intr_path, 1'b1);
    #50ns;
    $display("Test INTR ID = %d \n",intr_id);  
    wait_label(intr_id + 19); 
    $display("Got Label %d \n",intr_id + 19);  
    uvm_hdl_release(intr_path);
endtask : intr_handler_check

class cpu_int_plic_base_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_int_plic_base_test)
    extern function new(string name = "cpu_int_plic_base_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
    extern task intr_handler_check(input int intr_id, input string intr_path);
endclass

function cpu_int_plic_base_test::new(string name = "cpu_int_plic_base_test", uvm_component parent = null);
    super.new(name,parent);
endfunction:new

task cpu_int_plic_base_test::main_phase(uvm_phase phase);
    super.main_phase(phase);
    phase.raise_objection(this);
    phase.drop_objection(this); 
endtask:main_phase

task cpu_int_plic_base_test::intr_handler_check(input int intr_id, input string intr_path);
    bit[31:0] read_val;
    uvm_hdl_force(intr_path, 1'b1);
    #50ns;
    $display("Test INTR ID = %d \n",intr_id);  
    wait_label(intr_id + 1); 
    $display("Got Label %d \n",intr_id + 1);  
    uvm_hdl_release(intr_path);
endtask : intr_handler_check

`endif