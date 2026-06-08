

`ifndef DEMO_SRAM_SCAN_TEST_SV
`define DEMO_SRAM_SCAN_TEST_SV

class demo_sram_scan_test extends chip_noc_base_test;
    `uvm_component_utils(demo_sram_scan_test)
    extern function new(string name = "demo_sram_scan_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function demo_sram_scan_test::new(string name = "demo_sram_scan_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task demo_sram_scan_test::main_phase(uvm_phase phase);
    bit[31:0] rdata;
    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    while(1)begin
        //rdata = sram_rd32_bd(`SRAM_START_ADDR+'hffff8);
        rdata = sram_rd32_bd(`SRAM_START_ADDR);
        if(rdata == 'h11223344)begin
            `uvm_error("demo_sram_scan_test","scan sram function fail");
            break;
        end
        else if(rdata == 'h12345678)begin
            `uvm_info("demo_sram_scan_test","scan sram function pass",UVM_LOW);
            break;
        end
        #10ns;
    end
    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
