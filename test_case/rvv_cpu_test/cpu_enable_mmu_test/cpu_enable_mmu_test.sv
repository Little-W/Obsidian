

`ifndef CPU_ENABLE_MMU_TEST_SV
`define CPU_ENABLE_MMU_TEST_SV

class cpu_enable_mmu_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_enable_mmu_test)
    extern function new(string name = "cpu_enable_mmu_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_enable_mmu_test::new(string name = "cpu_enable_mmu_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_enable_mmu_test::main_phase(uvm_phase phase);
    bit[31:0] rdata;
    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    #6ms;  //can't get flag after enable mmu, so use delay time temporary
    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
