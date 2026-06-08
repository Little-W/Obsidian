

`ifndef CPU_SP_MODE_TEST_SV
`define CPU_SP_MODE_TEST_SV

class cpu_sp_mode_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_sp_mode_test)
    extern function new(string name = "cpu_sp_mode_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_sp_mode_test::new(string name = "cpu_sp_mode_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_sp_mode_test::main_phase(uvm_phase phase);

    bit[63:0] read_val;

    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    uvm_hdl_force  ("hdl_top.T100_TOP_u.DIE_ID0", 0);
    uvm_hdl_force  ("hdl_top.T100_TOP_u.DIE_ID1", 0);
    
    uvm_hdl_force  ("hdl_top.T100_TOP_u.CHIP_ID0", 0);
    uvm_hdl_force  ("hdl_top.T100_TOP_u.CHIP_ID1", 0);
    uvm_hdl_force  ("hdl_top.T100_TOP_u.BOOT_SEQ", 0); //bing xing
   
    uvm_hdl_force  ("hdl_top.T100_TOP_u.DFT_MODE", 0); 
     
//    check_simend();

    #1ms;
    
    do begin
        #1ns;                      
        uvm_hdl_read("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.sp_tmod[10:0]",read_val);
        #1ns;
        $display("waitting sp_tmod finish  \n");
    end while(read_val !==32'h7ff); 

    #100ns;

    $display("sp_tmod test c code pass \n");

    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
