

`ifndef CPU_WFI_DEEP_TEST_SV
`define CPU_WFI_DEEP_TEST_SV

class cpu_wfi_deep_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_wfi_deep_test)
    extern function new(string name = "cpu_wfi_deep_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_wfi_deep_test::new(string name = "cpu_wfi_deep_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_wfi_deep_test::main_phase(uvm_phase phase);
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

    wait_label(55);
    `uvm_info(get_type_name(),$psprintf("fst:detect core0_core_clk status !!!"), UVM_LOW)
    #500ns;    //wait sleep
    repeat(1000)begin
        uvm_hdl_read("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top.u_core0.u_core.u_core.core_clk", core_clk);
        if(core_clk != 0)begin
            `uvm_error(get_type_name(), "core0_core_clk bust be low after cpu exe WFI");
        end
        #1ns;
    end

    uvm_hdl_force("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.por_reset_n",0);
    #100ns;
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.por_reset_n");

    #500ns;

//    check_simend();

    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif

