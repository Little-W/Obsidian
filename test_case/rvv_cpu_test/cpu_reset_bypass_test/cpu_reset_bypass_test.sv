

`ifndef CPU_RESET_BYPASS_TEST_SV
`define CPU_RESET_BYPASS_TEST_SV

class cpu_reset_bypass_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_reset_bypass_test)
    extern function new(string name = "cpu_reset_bypass_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_reset_bypass_test::new(string name = "cpu_reset_bypass_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_reset_bypass_test::main_phase(uvm_phase phase);
    bit[7:0] clk_flg = 0;
    int start_time;
    int end_time;
    int freq = 0;

    super.main_phase(phase);
    phase.raise_objection(this);
    `uvm_info(get_type_name(),$psprintf("main_phase start!"), UVM_LOW)

    wait_label('h12345678);
    `uvm_info(get_type_name(),$psprintf("force reset_bypass to high !!!"), UVM_LOW)
    //force reset_bypass to high
    uvm_hdl_force("hdl_top.T100_TOP_u.PD_AON_SUB_0.DFT_TCU_0.U_DFT_GLOBAL_RST_N_BUF.I",1);
    uvm_hdl_force("hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_IOMUX_0.DFT_MODE_PIN",1);

    send_label('h11112222);

    wait_label('h41526311);
    `uvm_info(get_type_name(),$psprintf("wait sysrstreq !!!"), UVM_LOW)
    @(posedge chip_top_vif.sysrstreq);
    #100us;
    send_label('hadf57c8e);


    wait('h5555);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_AON_SUB_0.DFT_TCU_0.U_DFT_GLOBAL_RST_N_BUF.I");
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_AON_SUB_0.AON_IOMUX_0.DFT_MODE_PIN");

    check_simend();

    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
