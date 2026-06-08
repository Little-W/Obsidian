

`ifndef CPU_CLKGATE_BYPASS_TEST_SV
`define CPU_CLKGATE_BYPASS_TEST_SV

class cpu_clkgate_bypass_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_clkgate_bypass_test)
    extern function new(string name = "cpu_clkgate_bypass_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_clkgate_bypass_test::new(string name = "cpu_clkgate_bypass_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_clkgate_bypass_test::main_phase(uvm_phase phase);
    bit[7:0] clk_flg = 0;
    int start_time;
    int end_time;
    int freq = 0;
    bit core_clk;

    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    repeat(100)begin
        @(posedge chip_top_vif.core0_core_clk);
    end

    wait_label('h12345678);
    `uvm_info(get_type_name(),$psprintf("fst:detect core0_core_clk status !!!"), UVM_LOW)
    #500ns;    //wait sleep
    repeat(1000)begin
        uvm_hdl_read("hdl_top.T100_TOP_u.T100_PD_CORE_0.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top.u_core0.u_core.u_core.core_clk", core_clk);
        if(core_clk != 0)begin
            `uvm_error(get_type_name(), "core0_core_clk bust be low after cpu exe WFI");
        end
        #1ns;
    end

    wait_label('habcd1111);
    //force reset_bypass to high
    `uvm_info(get_type_name(),$psprintf("force clkgate_bypass to high !!!"), UVM_LOW)
    uvm_hdl_force("hdl_top.T100_TOP_u.PD_AON_SUB_0.DFT_TCU_0.dft_ckgt_glb_te",1);
    send_label('h44556677);

    wait_label('h2547a9b3);
    @(posedge chip_top_vif.mon_clk);
    `uvm_info(get_type_name(),$psprintf("sec:detect core0_core_clk status !!!"), UVM_LOW)
    repeat(3000)begin
        start_time = $time;
        @(posedge chip_top_vif.mon_clk);
        @(posedge chip_top_vif.mon_clk);
        end_time = $time;
        freq = 10**6/(end_time-start_time);
        if(freq > 808 && freq < 792)begin
            `uvm_error(get_type_name(), $sformatf("detect actual freq = %0xM", freq));
        end
    end
    `uvm_info(get_type_name(),$psprintf("sec:detect core0_core_clk done !!!"), UVM_LOW)
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_AON_SUB_0.DFT_TCU_0.dft_ckgt_glb_te");
    
    #40ns;

    check_simend();

    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
