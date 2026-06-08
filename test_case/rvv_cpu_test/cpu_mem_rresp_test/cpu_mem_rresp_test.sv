

`ifndef CPU_MEM_RRESP_TEST_SV
`define CPU_MEM_RRESP_TEST_SV

class cpu_mem_rresp_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_mem_rresp_test)
    extern function new(string name = "cpu_mem_rresp_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_mem_rresp_test::new(string name = "cpu_mem_rresp_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_mem_rresp_test::main_phase(uvm_phase phase);

    bit[31:0] read_val = 0;
    
    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    uvm_hdl_force  ("hdl_top.T100_TOP_u.DIE_ID0", 0);
    uvm_hdl_force  ("hdl_top.T100_TOP_u.DIE_ID1", 0);
    
    uvm_hdl_force  ("hdl_top.T100_TOP_u.CHIP_ID0", 0);
    uvm_hdl_force  ("hdl_top.T100_TOP_u.CHIP_ID1", 0);
    uvm_hdl_force  ("hdl_top.T100_TOP_u.BOOT_SEQ", 0); //bing xing
    
//    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.core0_stop_on_reset",0); 
    
    wait_label(1);
    $display("cpu_mem_rresp_test wait_label 123 \n");
    
    do begin
        #1ns;                      
        uvm_hdl_read("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top.u_core0.i0_trace_iexception",read_val);
        $display("waitting mem_rresp send data \n");
    end while(read_val !==32'h1); 


//    check_simend();
    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
