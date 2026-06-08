

`ifndef CPU_INT_MSG2_TEST_SV
`define CPU_INT_MSG2_TEST_SV

class cpu_int_msg2_test extends chip_noc_base_test;
    `uvm_component_utils(cpu_int_msg2_test)
    extern function new(string name = "cpu_int_msg2_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_int_msg2_test::new(string name = "cpu_int_msg2_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_int_msg2_test::main_phase(uvm_phase phase);
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
  

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[7]", 1);
    wait_label(19+118);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[7]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[6]", 1);
    wait_label(19+119);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[6]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[5]", 1);
    wait_label(19+120);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[5]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[4]", 1);
    wait_label(19+121);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[4]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[3]", 1);
    wait_label(19+122);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[3]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[2]", 1);
    wait_label(19+123);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[2]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[1]", 1);
    wait_label(19+124);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[1]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[0]", 1);
    wait_label(19+125);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_mailbox_intr_l[0]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[7]", 1);
    wait_label(19+126);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[7]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[6]", 1);
    wait_label(19+127);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[6]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[5]", 1);
    wait_label(19+128);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[5]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[4]", 1);
    wait_label(19+129);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[4]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[3]", 1);
    wait_label(19+130);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[3]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[2]", 1);
    wait_label(19+131);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[2]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[1]", 1);
    wait_label(19+132);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[1]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[0]", 1);
    wait_label(19+133);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_gpio_intr[0]");
    send_label('haabbccdd);
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[7]", 1);
    wait_label(19+134);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[7]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[6]", 1);
    wait_label(19+135);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[6]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[5]", 1);
    wait_label(19+136);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[5]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[4]", 1);
    wait_label(19+137);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[4]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[3]", 1);
    wait_label(19+138);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[3]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[2]", 1);
    wait_label(19+139);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[2]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[1]", 1);
    wait_label(19+140);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[1]");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[0]", 1);
    wait_label(19+141);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_gpio_intr[0]");
    send_label('haabbccdd);
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_i2c1_intr", 1);
    wait_label(19+142);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_i2c1_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_i2c0_intr", 1);
    wait_label(19+143);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_i2c0_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_rtc_intr", 1);
    wait_label(19+144);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_rtc_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_pvtc_intr", 1);
    wait_label(19+145);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_pvtc_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_mailbox_host_0_intr", 1);
    wait_label(19+146);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_mailbox_host_0_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_mailbox_internal_intr", 1);
    wait_label(19+147);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_mailbox_internal_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_trng0_trng_intr", 1);
    wait_label(19+148);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_trng0_trng_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_hash0_intr", 1);
    wait_label(19+149);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_hash0_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_cryp0_intr", 1);
    wait_label(19+150);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_cryp0_intr");
    send_label('haabbccdd);
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_acryp0_intr", 1);
    wait_label(19+151);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_acryp0_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_rtc0_rtc_intr", 1);
    wait_label(19+152);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_rtc0_rtc_intr");
    send_label('haabbccdd);
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_basic_timer0_bsc_tim_intr", 1);
    wait_label(19+153);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_basic_timer0_bsc_tim_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_usart0_uart_intr", 1);
    wait_label(19+154);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_usart0_uart_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_udma0_udma_intr", 1);
    wait_label(19+155);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hsm_udma0_udma_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_can1_intr", 1);
    wait_label(19+156);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_can1_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_can0_intr", 1);
    wait_label(19+157);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_can0_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_atb2axi_intr", 1);
    wait_label(19+158);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_atb2axi_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i2s0_intr", 1);
    wait_label(19+160);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i2s0_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i3c0_intr", 1);
    wait_label(19+161);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i3c0_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_xspi0_intr", 1);
    wait_label(19+162);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_xspi0_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_spi0_intr", 1);
    wait_label(19+163);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_spi0_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i2c1_intr", 1);
    wait_label(19+164);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i2c1_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i2c0_intr", 1);
    wait_label(19+165);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_i2c0_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_uart1_intr", 1);
    wait_label(19+166);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_uart1_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_uart0_intr", 1);
    wait_label(19+167);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_uart0_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_noc_intr", 1);
    wait_label(19+168);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_noc_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_data_noc_intr", 1);
    wait_label(19+169);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_data_noc_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_reg_noc_intr", 1);
    wait_label(19+170);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_reg_noc_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.top_crg_pll_intr", 1);  //1209
    wait_label(19+171);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.top_crg_pll_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.soc_noc_intr", 1);
    wait_label(19+172);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.soc_noc_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.media_sub_gpu_syserr_intr", 1);
    wait_label(19+173);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.media_sub_gpu_syserr_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_crg_intr", 1);
    wait_label(19+174);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.aon_crg_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.t2_uee_pmu_intr", 1);
    wait_label(19+175);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.t2_uee_pmu_intr");
    send_label('haabbccdd);
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_usb_host_sys_err_intr", 1);
    wait_label(19+176);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_usb_host_sys_err_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_intr", 1);
    wait_label(19+177);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_dma_intr");
    send_label('haabbccdd);
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_atu_intr", 1);
    wait_label(19+178);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_atu_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_err_intr", 1);
    wait_label(19+179);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_err_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_dma_intr", 1);
    wait_label(19+180);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess01_dma_intr");
    send_label('haabbccdd);
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_atu_intr", 1);
    wait_label(19+181);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_atu_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_err_intr", 1);
    wait_label(19+182);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_err_intr");
    send_label('haabbccdd);
    #1us;

    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_dma_intr", 1);
    wait_label(19+183);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.hs_pciess00_dma_intr");
    send_label('haabbccdd);
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_intr", 1);
    wait_label(19+184);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.mcu_dma_intr");
    send_label('haabbccdd);
    #1us;


    uvm_hdl_force  ("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.pmu_evt_wakeup_intr", 1);
    wait_label(19+185);
    uvm_hdl_release("hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_GLUE_0.pmu_evt_wakeup_intr");
    send_label('haabbccdd);
    #1us;




    check_simend();

    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
