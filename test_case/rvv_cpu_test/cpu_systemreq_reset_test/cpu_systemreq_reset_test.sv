

`ifndef CPU_SYSTEMREQ_RESET_TEST_SV
`define CPU_SYSTEMREQ_RESET_TEST_SV

class cpu_systemreq_reset_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_systemreq_reset_test)
    extern function new(string name = "cpu_systemreq_reset_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_systemreq_reset_test::new(string name = "cpu_systemreq_reset_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_systemreq_reset_test::main_phase(uvm_phase phase);
    bit[7:0] clk_flg = 0;
    int start_time;
    int end_time;
    int freq = 0;

    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    //wait first boot
    wait_label('h12345678);

    //detect sysrstreq
    @(posedge chip_top_vif.sysrstreq);

    //wait second boot
    wait_label('h11aa55bb);
    check_simend();

    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
