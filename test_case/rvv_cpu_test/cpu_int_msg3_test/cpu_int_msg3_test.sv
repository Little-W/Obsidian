
`ifndef CPU_INT_MSG3_TEST_SV
`define CPU_INT_MSG3_TEST_SV

class cpu_int_msg3_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_int_msg3_test)
    extern function new(string name = "cpu_int_msg3_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_int_msg3_test::new(string name = "cpu_int_msg3_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_int_msg3_test::main_phase(uvm_phase phase);
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

    `uvm_info(get_type_name(),$psprintf("wait 0x12345678"), UVM_LOW)
    wait_label('h12345678);
    `uvm_info(get_type_name(),$psprintf("wait 0x12345678======"), UVM_LOW)


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core3_tbu1_pmu_intr", 1);
    wait_label(19+186);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core3_tbu1_pmu_intr");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core3_tbu1_ras_intr", 1);
    wait_label(19+187);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core3_tbu1_ras_intr");
    send_label('haabbccdd); 
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core3_tbu0_pmu_intr", 1);
    wait_label(19+188);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core3_tbu0_pmu_intr");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core3_tbu0_ras_intr", 1);
    wait_label(19+189);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core3_tbu0_ras_intr");
    send_label('haabbccdd); 
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core2_tbu1_pmu_intr", 1);
    wait_label(19+190);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core2_tbu1_pmu_intr");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core2_tbu1_ras_intr", 1);
    wait_label(19+191);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core2_tbu1_ras_intr");
    send_label('haabbccdd); 
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core2_tbu0_pmu_intr", 1);
    wait_label(19+192);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core2_tbu0_pmu_intr");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core2_tbu0_ras_intr", 1);
    wait_label(19+193);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core2_tbu0_ras_intr");
    send_label('haabbccdd); 
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core1_tbu1_pmu_intr", 1);
    wait_label(19+194);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core1_tbu1_pmu_intr");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core1_tbu1_ras_intr", 1);
    wait_label(19+195);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core1_tbu1_ras_intr");
    send_label('haabbccdd); 
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core1_tbu0_pmu_intr", 1);
    wait_label(19+196);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core1_tbu0_pmu_intr");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core1_tbu0_ras_intr", 1);
    wait_label(19+197);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core1_tbu0_ras_intr");
    send_label('haabbccdd); 
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core0_tbu1_pmu_intr", 1);
    wait_label(19+198);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core0_tbu1_pmu_intr");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core0_tbu1_ras_intr", 1);
    wait_label(19+199);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core0_tbu1_ras_intr");
    send_label('haabbccdd); 
    #1us;



    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core0_tbu0_pmu_intr", 1);
    wait_label(19+200);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core0_tbu0_pmu_intr");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core0_tbu0_ras_intr", 1);
    wait_label(19+201);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.core0_tbu0_ras_intr");
    send_label('haabbccdd); 
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.media_tbu_pmu_intr", 1);
    wait_label(19+213);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.media_tbu_pmu_intr");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.media_tbu_ras_intr", 1);
    wait_label(19+214);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.media_tbu_ras_intr");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_global_intr_s_scu", 1); //1209
    wait_label(19+215);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_global_intr_s_scu");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_pri_q_intr_ns_scu", 1); //1209
    wait_label(19+216);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_pri_q_intr_ns_scu");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_global_intr_ns_scu", 1);
    wait_label(19+217);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_global_intr_ns_scu");
    send_label('haabbccdd); 
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_cmd_sync_intr_ns_scu", 1);
    wait_label(19+218);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_cmd_sync_intr_ns_scu");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_cmd_sync_intr_s_scu", 1);
    wait_label(19+219);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_cmd_sync_intr_s_scu");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_event_q_intr_ns_scu", 1);
    wait_label(19+220);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_event_q_intr_ns_scu");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_event_q_intr_s_scu", 1);
    wait_label(19+221);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_event_q_intr_s_scu");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_pmu_intr_scu", 1);
    wait_label(19+222);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_pmu_intr_scu");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_ras_intr_scu", 1);
    wait_label(19+223);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.tcu_ras_intr_scu");
    send_label('haabbccdd); 
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.barrier_intr", 1);
    wait_label(19+224);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.barrier_intr");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[0]", 1);
    wait_label(19+225);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[0]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[1]", 1);
    wait_label(19+226);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[1]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[2]", 1);
    wait_label(19+227);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[2]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[3]", 1);
    wait_label(19+228);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[3]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[4]", 1);
    wait_label(19+229);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[4]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[5]", 1);
    wait_label(19+230);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[5]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[6]", 1);
    wait_label(19+231);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[6]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[7]", 1);
    wait_label(19+232);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr3[7]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[0]", 1);
    wait_label(19+233);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[0]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[1]", 1);
    wait_label(19+234);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[1]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[2]", 1);
    wait_label(19+235);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[2]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[3]", 1);
    wait_label(19+236);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[3]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[4]", 1);
    wait_label(19+237);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[4]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[5]", 1);
    wait_label(19+238);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[5]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[6]", 1);
    wait_label(19+239);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[6]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[7]", 1);
    wait_label(19+240);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr2[7]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[0]", 1);
    wait_label(19+241);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[0]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[1]", 1);
    wait_label(19+242);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[1]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[2]", 1);
    wait_label(19+243);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[2]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[3]", 1);
    wait_label(19+244);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[3]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[4]", 1);
    wait_label(19+245);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[4]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[5]", 1);
    wait_label(19+246);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[5]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[6]", 1);
    wait_label(19+247);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[6]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[7]", 1);
    wait_label(19+248);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr1[7]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[0]", 1);
    wait_label(19+249);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[0]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[1]", 1);
    wait_label(19+250);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[1]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[2]", 1);
    wait_label(19+251);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[2]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[3]", 1);
    wait_label(19+252);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[3]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[4]", 1);
    wait_label(19+253);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[4]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[5]", 1);
    wait_label(19+254);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[5]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[6]", 1);
    wait_label(19+255);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[6]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[7]", 1);
    wait_label(19+256);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_intr0[7]");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_wdt_intr3", 1);
    wait_label(19+257);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_wdt_intr3");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_wdt_intr2", 1);
    wait_label(19+258);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_wdt_intr2");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_wdt_intr1", 1);
    wait_label(19+259);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_wdt_intr1");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_wdt_intr0", 1);
    wait_label(19+260);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.npu_wdt_intr0");
    send_label('haabbccdd); 
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_wdt_intr", 1);
    wait_label(19+261);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_wdt_intr");
    send_label('haabbccdd); 


    check_simend();

    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif

    
