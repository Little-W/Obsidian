`ifndef CPU_INT_MSG_TEST_SV
`define CPU_INT_MSG_TEST_SV
class cpu_int_msg_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_int_msg_test)
    extern function new(string name = "cpu_int_msg_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass
function cpu_int_msg_test::new(string name = "cpu_int_msg_test", uvm_component parent = null);
    super.new(name,parent);
endfunction:new
task cpu_int_msg_test::main_phase(uvm_phase phase);
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

    `uvm_info(get_type_name(),$psprintf("force MCU_GLUE_0 start!"), UVM_LOW)
    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[31]", 1);
    wait_label(19+0);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[31]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[30]", 1);
    wait_label(19+1);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[30]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[29]", 1);
    wait_label(19+2);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[29]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[28]", 1);
    wait_label(19+3);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[28]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[27]", 1);
    wait_label(19+4);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[27]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[26]", 1);
    wait_label(19+5);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[26]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[25]", 1);
    wait_label(19+6);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[25]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[24]", 1);
    wait_label(19+7);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[24]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[23]", 1);
    wait_label(19+8);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[23]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[22]", 1);
    wait_label(19+9);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[22]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[21]", 1);
    wait_label(19+10);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[21]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[20]", 1);
    wait_label(19+11);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[20]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[19]", 1);
    wait_label(19+12);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[19]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[18]", 1);
    wait_label(19+13);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[18]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[17]", 1);
    wait_label(19+14);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[17]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[16]", 1);
    wait_label(19+15);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[16]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[15]", 1);
    wait_label(19+16);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[15]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[14]", 1);
    wait_label(19+17);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[14]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[13]", 1);
    wait_label(19+18);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[13]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[12]", 1);
    wait_label(19+19);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[12]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[11]", 1);
    wait_label(19+20);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[11]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[10]", 1);
    wait_label(19+21);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[10]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[9]", 1);
    wait_label(19+22);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[9]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[8]", 1);
    wait_label(19+23);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[8]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[31]", 1);
    wait_label(19+24);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[31]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[30]", 1);
    wait_label(19+25);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[30]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[29]", 1);
    wait_label(19+26);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[29]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[28]", 1);
    wait_label(19+27);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[28]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[27]", 1);
    wait_label(19+28);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[27]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[26]", 1);
    wait_label(19+29);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[26]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[25]", 1);
    wait_label(19+30);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[25]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[24]", 1);
    wait_label(19+31);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[24]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[23]", 1);
    wait_label(19+32);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[23]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[22]", 1);
    wait_label(19+33);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[22]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[21]", 1);
    wait_label(19+34);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[21]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[20]", 1);
    wait_label(19+35);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[20]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[19]", 1);
    wait_label(19+36);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[19]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[18]", 1);
    wait_label(19+37);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[18]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[17]", 1);
    wait_label(19+38);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[17]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[16]", 1);
    wait_label(19+39);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[16]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[15]", 1);
    wait_label(19+40);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[15]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[14]", 1);
    wait_label(19+41);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[14]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[13]", 1);
    wait_label(19+42);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[13]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[12]", 1);
    wait_label(19+43);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[12]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[11]", 1);
    wait_label(19+44);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[11]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[10]", 1);
    wait_label(19+45);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[10]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[9]", 1);
    wait_label(19+46);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[9]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[8]", 1);
    wait_label(19+47);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[8]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[15]", 1);
    wait_label(19+48);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[15]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[14]", 1);
    wait_label(19+49);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[14]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[13]", 1);
    wait_label(19+50);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[13]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[12]", 1);
    wait_label(19+51);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[12]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[11]", 1);
    wait_label(19+52);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[11]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[10]", 1);
    wait_label(19+53);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[10]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[9]", 1);
    wait_label(19+54);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[9]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[8]", 1);
    wait_label(19+55);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[8]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[7]", 1);
    wait_label(19+56);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[7]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[6]", 1);
    wait_label(19+57);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[6]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[5]", 1);
    wait_label(19+58);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[5]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[4]", 1);
    wait_label(19+59);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[4]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[3]", 1);
    wait_label(19+60);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[3]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[2]", 1);
    wait_label(19+61);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[2]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[1]", 1);
    wait_label(19+62);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[1]");
    send_label('haabbccdd);
    #2us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[0]", 1);
    wait_label(19+63);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_ch_intr[0]");
    send_label('haabbccdd);

    check_simend();
    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase
`endif
