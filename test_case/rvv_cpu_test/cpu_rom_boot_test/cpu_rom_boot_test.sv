

`ifndef CPU_ROM_BOOT_TEST_SV
`define CPU_ROM_BOOT_TEST_SV

class cpu_rom_boot_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_rom_boot_test)
    extern function new(string name = "cpu_rom_boot_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_rom_boot_test::new(string name = "cpu_rom_boot_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_rom_boot_test::main_phase(uvm_phase phase);
    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    for(int i = 'h20000; i < 'h40000; i=i+8)begin
        mem_write_bd(`ROM_START_ADDR+i, `ROM_START_ADDR+i);
    end

    check_simend();
    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
