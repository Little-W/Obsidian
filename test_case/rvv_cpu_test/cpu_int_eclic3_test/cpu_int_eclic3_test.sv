

`ifndef CPU_INT_ECLIC3_TEST_SV
`define CPU_INT_ECLIC3_TEST_SV

class cpu_int_eclic3_test extends cpu_int_eclic_base_test;
    `uvm_component_utils(cpu_int_eclic3_test)
    extern function new(string name = "cpu_int_eclic3_test", uvm_component parent = null);
    extern virtual task main_phase(uvm_phase phase);
endclass

function cpu_int_eclic3_test::new(string name = "cpu_int_eclic3_test", uvm_component parent = null);
    super.new(name,parent);

endfunction:new

task cpu_int_eclic3_test::main_phase(uvm_phase phase);
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

    intr_handler_check(`MEDIA_TBU_PMU_INTR_IRQ_ID, `MEDIA_TBU_PMU_INTR_PATH);
    intr_handler_check(`MEDIA_TBU_RAS_INTR_IRQ_ID, `MEDIA_TBU_RAS_INTR_PATH);
    intr_handler_check(`TCU_GLOBAL_INTR_S_IRQ_ID, `TCU_GLOBAL_INTR_S_PATH);
    intr_handler_check(`TCU_PRI_Q_INTR_NS_IRQ_ID, `TCU_PRI_Q_INTR_NS_PATH);
    intr_handler_check(`TCU_GLOBAL_INTR_NS_IRQ_ID, `TCU_GLOBAL_INTR_NS_PATH);
    intr_handler_check(`TCU_CMD_SYNC_INTR_NS_IRQ_ID, `TCU_CMD_SYNC_INTR_NS_PATH);
    intr_handler_check(`TCU_CMD_SYNC_INTR_S_IRQ_ID, `TCU_CMD_SYNC_INTR_S_PATH);
    intr_handler_check(`TCU_EVENT_Q_INTR_NS_IRQ_ID, `TCU_EVENT_Q_INTR_NS_PATH);
    intr_handler_check(`TCU_EVENT_Q_INTR_S_IRQ_ID, `TCU_EVENT_Q_INTR_S_PATH);
    intr_handler_check(`TCU_PMU_INTR_IRQ_ID, `TCU_PMU_INTR_PATH);
    intr_handler_check(`TCU_RAS_INTR_IRQ_ID, `TCU_RAS_INTR_PATH);
    intr_handler_check(`BARRIER_INTR_IRQ_ID, `BARRIER_INTR_PATH);
    intr_handler_check(`NPU_INTR3_0_IRQ_ID, `NPU_INTR3_0_PATH);
    intr_handler_check(`NPU_INTR3_1_IRQ_ID, `NPU_INTR3_1_PATH);
    intr_handler_check(`NPU_INTR3_2_IRQ_ID, `NPU_INTR3_2_PATH);
    intr_handler_check(`NPU_INTR3_3_IRQ_ID, `NPU_INTR3_3_PATH);
    intr_handler_check(`NPU_INTR3_4_IRQ_ID, `NPU_INTR3_4_PATH);
    intr_handler_check(`NPU_INTR3_5_IRQ_ID, `NPU_INTR3_5_PATH);
    intr_handler_check(`NPU_INTR3_6_IRQ_ID, `NPU_INTR3_6_PATH);
    intr_handler_check(`NPU_INTR3_7_IRQ_ID, `NPU_INTR3_7_PATH);
    intr_handler_check(`NPU_INTR2_0_IRQ_ID, `NPU_INTR2_0_PATH);
    intr_handler_check(`NPU_INTR2_1_IRQ_ID, `NPU_INTR2_1_PATH);
    intr_handler_check(`NPU_INTR2_2_IRQ_ID, `NPU_INTR2_2_PATH);
    intr_handler_check(`NPU_INTR2_3_IRQ_ID, `NPU_INTR2_3_PATH);
    intr_handler_check(`NPU_INTR2_4_IRQ_ID, `NPU_INTR2_4_PATH);
    intr_handler_check(`NPU_INTR2_5_IRQ_ID, `NPU_INTR2_5_PATH);
    intr_handler_check(`NPU_INTR2_6_IRQ_ID, `NPU_INTR2_6_PATH);
    intr_handler_check(`NPU_INTR2_7_IRQ_ID, `NPU_INTR2_7_PATH);
    intr_handler_check(`NPU_INTR1_0_IRQ_ID, `NPU_INTR1_0_PATH);
    intr_handler_check(`NPU_INTR1_1_IRQ_ID, `NPU_INTR1_1_PATH);
    intr_handler_check(`NPU_INTR1_2_IRQ_ID, `NPU_INTR1_2_PATH);
    intr_handler_check(`NPU_INTR1_3_IRQ_ID, `NPU_INTR1_3_PATH);
    intr_handler_check(`NPU_INTR1_4_IRQ_ID, `NPU_INTR1_4_PATH);
    intr_handler_check(`NPU_INTR1_5_IRQ_ID, `NPU_INTR1_5_PATH);
    intr_handler_check(`NPU_INTR1_6_IRQ_ID, `NPU_INTR1_6_PATH);
    intr_handler_check(`NPU_INTR1_7_IRQ_ID, `NPU_INTR1_7_PATH);
    intr_handler_check(`NPU_INTR0_0_IRQ_ID, `NPU_INTR0_0_PATH);
    intr_handler_check(`NPU_INTR0_1_IRQ_ID, `NPU_INTR0_1_PATH);
    intr_handler_check(`NPU_INTR0_2_IRQ_ID, `NPU_INTR0_2_PATH);
    intr_handler_check(`NPU_INTR0_3_IRQ_ID, `NPU_INTR0_3_PATH);
    intr_handler_check(`NPU_INTR0_4_IRQ_ID, `NPU_INTR0_4_PATH);
    intr_handler_check(`NPU_INTR0_5_IRQ_ID, `NPU_INTR0_5_PATH);
    intr_handler_check(`NPU_INTR0_6_IRQ_ID, `NPU_INTR0_6_PATH);
    intr_handler_check(`NPU_INTR0_7_IRQ_ID, `NPU_INTR0_7_PATH);
    intr_handler_check(`NPU_WDT_INTR3_IRQ_ID, `NPU_WDT_INTR3_PATH);
    intr_handler_check(`NPU_WDT_INTR2_IRQ_ID, `NPU_WDT_INTR2_PATH);
    intr_handler_check(`NPU_WDT_INTR1_IRQ_ID, `NPU_WDT_INTR1_PATH);
    intr_handler_check(`NPU_WDT_INTR0_IRQ_ID, `NPU_WDT_INTR0_PATH);
    intr_handler_check(`MCU_WDT_INTR_IRQ_ID, `MCU_WDT_INTR_PATH);


    check_simend();

    `uvm_info(get_type_name(),$psprintf("main_phase done!"), UVM_LOW)
    phase.drop_objection(this);
endtask:main_phase

`endif
