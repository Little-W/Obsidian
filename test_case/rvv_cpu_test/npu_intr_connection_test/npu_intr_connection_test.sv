`ifndef NPU_INTR_CONNECTION_TEST_SV
`define NPU_INTR_CONNECTION_TEST_SV

class npu_intr_connection_test extends chip_noc_base_test;
  `uvm_component_utils(npu_intr_connection_test)

  extern function new(string name = "npu_intr_connection_test", uvm_component parent = null);
  extern virtual task main_phase(uvm_phase phase);
  extern task test_intr_conn(string path, int index, string signal_name);
  extern task test_intr_conn_per_core(
    string  path,
    int     index,
    string  signal_name,
    int     core_id
);

endclass

function npu_intr_connection_test::new(string name = "npu_intr_connection_test", uvm_component parent = null);
  super.new(name, parent);
endfunction : new

task npu_intr_connection_test::main_phase(uvm_phase phase);
  super.main_phase(phase);
  phase.raise_objection(this);
  `uvm_info(get_type_name(), $psprintf("main_phase start!"), UVM_LOW)
  `uvm_info(get_type_name(), "npu_intr_connection_test start", UVM_LOW);

    // I2C1 / SPI0 / UART
    test_intr_conn(`MCU_NPU_I2C1_INTR_PATH, `MCU_NPU_I2C1_INTR_IRQ_ID, "MCU_I2C1_INTR");
    test_intr_conn(`MCU_NPU_SPI0_INTR_PATH, `MCU_NPU_SPI0_INTR_IRQ_ID, "MCU_SPI0_INTR");
    test_intr_conn(`MCU_NPU_UART3_INTR_PATH, `MCU_NPU_UART3_INTR_IRQ_ID, "MCU_UART3_INTR");
    test_intr_conn(`MCU_NPU_UART2_INTR_PATH, `MCU_NPU_UART2_INTR_IRQ_ID, "MCU_UART2_INTR");
    test_intr_conn(`MCU_NPU_UART1_INTR_PATH, `MCU_NPU_UART1_INTR_IRQ_ID, "MCU_UART1_INTR");
    test_intr_conn(`MCU_NPU_UART0_INTR_PATH, `MCU_NPU_UART0_INTR_IRQ_ID, "MCU_UART0_INTR");

    // Timer
    test_intr_conn(`MCU_NPU_TIMER0_INTR_PATH, `MCU_NPU_TIMER0_IRQ_ID, "MCU_TIMER0_INTR");
    test_intr_conn(`MCU_NPU_TIMER1_INTR_PATH, `MCU_NPU_TIMER1_IRQ_ID, "MCU_TIMER1_INTR");

    // GPIO
    test_intr_conn(`MCU_NPU_GPIO_INTR1_PATH, `MCU_NPU_GPIO_INTR1_IRQ_ID, "MCU_GPIO_INTR1");
    test_intr_conn(`MCU_NPU_GPIO_INTR0_PATH, `MCU_NPU_GPIO_INTR0_IRQ_ID, "MCU_GPIO_INTR0");

    // WDT
    test_intr_conn(`MCU_NPU_WDT_INTR_PATH, `MCU_NPU_WDT_INTR0_IRQ_ID, "MCU_WDT_INTR0");

  // -------------------------- Core0 MailBox 16~23 tests --------------------------
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR16_PATH, `MCU_NPU_MAILBOX_INTR16_IRQ_ID, "MCU_NPU_MAILBOX_INTR16", 0); // test Core0
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR17_PATH, `MCU_NPU_MAILBOX_INTR17_IRQ_ID, "MCU_NPU_MAILBOX_INTR17", 0);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR18_PATH, `MCU_NPU_MAILBOX_INTR18_IRQ_ID, "MCU_NPU_MAILBOX_INTR18", 0);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR19_PATH, `MCU_NPU_MAILBOX_INTR19_IRQ_ID, "MCU_NPU_MAILBOX_INTR19", 0);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR20_PATH, `MCU_NPU_MAILBOX_INTR20_IRQ_ID, "MCU_NPU_MAILBOX_INTR20", 0);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR21_PATH, `MCU_NPU_MAILBOX_INTR21_IRQ_ID, "MCU_NPU_MAILBOX_INTR21", 0);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR22_PATH, `MCU_NPU_MAILBOX_INTR22_IRQ_ID, "MCU_NPU_MAILBOX_INTR22", 0);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR23_PATH, `MCU_NPU_MAILBOX_INTR23_IRQ_ID, "MCU_NPU_MAILBOX_INTR23", 0);

  // -------------------------- Core1 MailBox 24~31 tests --------------------------
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR24_PATH, `MCU_NPU_MAILBOX_INTR24_IRQ_ID, "MCU_NPU_MAILBOX_INTR24", 1); // test Core1
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR25_PATH, `MCU_NPU_MAILBOX_INTR25_IRQ_ID, "MCU_NPU_MAILBOX_INTR25", 1);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR26_PATH, `MCU_NPU_MAILBOX_INTR26_IRQ_ID, "MCU_NPU_MAILBOX_INTR26", 1);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR27_PATH, `MCU_NPU_MAILBOX_INTR27_IRQ_ID, "MCU_NPU_MAILBOX_INTR27", 1);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR28_PATH, `MCU_NPU_MAILBOX_INTR28_IRQ_ID, "MCU_NPU_MAILBOX_INTR28", 1);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR29_PATH, `MCU_NPU_MAILBOX_INTR29_IRQ_ID, "MCU_NPU_MAILBOX_INTR29", 1);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR30_PATH, `MCU_NPU_MAILBOX_INTR30_IRQ_ID, "MCU_NPU_MAILBOX_INTR30", 1);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR31_PATH, `MCU_NPU_MAILBOX_INTR31_IRQ_ID, "MCU_NPU_MAILBOX_INTR31", 1);

  // -------------------------- Core2 MailBox 32~39 tests --------------------------
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR32_PATH, `MCU_NPU_MAILBOX_INTR32_IRQ_ID, "MCU_NPU_MAILBOX_INTR32", 2); // test Core2
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR33_PATH, `MCU_NPU_MAILBOX_INTR33_IRQ_ID, "MCU_NPU_MAILBOX_INTR33", 2);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR34_PATH, `MCU_NPU_MAILBOX_INTR34_IRQ_ID, "MCU_NPU_MAILBOX_INTR34", 2);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR35_PATH, `MCU_NPU_MAILBOX_INTR35_IRQ_ID, "MCU_NPU_MAILBOX_INTR35", 2);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR36_PATH, `MCU_NPU_MAILBOX_INTR36_IRQ_ID, "MCU_NPU_MAILBOX_INTR36", 2);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR37_PATH, `MCU_NPU_MAILBOX_INTR37_IRQ_ID, "MCU_NPU_MAILBOX_INTR37", 2);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR38_PATH, `MCU_NPU_MAILBOX_INTR38_IRQ_ID, "MCU_NPU_MAILBOX_INTR38", 2);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR39_PATH, `MCU_NPU_MAILBOX_INTR39_IRQ_ID, "MCU_NPU_MAILBOX_INTR39", 2);

  // -------------------------- Core3 MailBox 40~47 tests --------------------------
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR40_PATH, `MCU_NPU_MAILBOX_INTR40_IRQ_ID, "MCU_NPU_MAILBOX_INTR40", 3); // test Core3
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR41_PATH, `MCU_NPU_MAILBOX_INTR41_IRQ_ID, "MCU_NPU_MAILBOX_INTR41", 3);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR42_PATH, `MCU_NPU_MAILBOX_INTR42_IRQ_ID, "MCU_NPU_MAILBOX_INTR42", 3);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR43_PATH, `MCU_NPU_MAILBOX_INTR43_IRQ_ID, "MCU_NPU_MAILBOX_INTR43", 3);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR44_PATH, `MCU_NPU_MAILBOX_INTR44_IRQ_ID, "MCU_NPU_MAILBOX_INTR44", 3);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR45_PATH, `MCU_NPU_MAILBOX_INTR45_IRQ_ID, "MCU_NPU_MAILBOX_INTR45", 3);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR46_PATH, `MCU_NPU_MAILBOX_INTR46_IRQ_ID, "MCU_NPU_MAILBOX_INTR46", 3);
  test_intr_conn_per_core(`MCU_NPU_MAILBOX_INTR47_PATH, `MCU_NPU_MAILBOX_INTR47_IRQ_ID, "MCU_NPU_MAILBOX_INTR47", 3);
  

  `uvm_info(get_type_name(), $psprintf("main_phase done!"), UVM_LOW)
  phase.drop_objection(this);
endtask : main_phase

task npu_intr_connection_test::test_intr_conn(string path, int index, string signal_name);
    logic [0:3] intr_value;
    string full_path0, full_path1, full_path2, full_path3;

    // Force the interrupt signal to 1'b1
    uvm_hdl_force(path, 1'b1);
    // Wait for the signal to propagate
    #30ns;

    // Construct full paths for each core's interrupt input at this index
    full_path0 = $sformatf("%s[%0d]", `CORE0_INTR_PATH, index);
    full_path1 = $sformatf("%s[%0d]", `CORE1_INTR_PATH, index);
    full_path2 = $sformatf("%s[%0d]", `CORE2_INTR_PATH, index);
    full_path3 = $sformatf("%s[%0d]", `CORE3_INTR_PATH, index);

    // Read the interrupt value from each core
    uvm_hdl_read(full_path0, intr_value[0]);
    uvm_hdl_read(full_path1, intr_value[1]);
    uvm_hdl_read(full_path2, intr_value[2]);
    uvm_hdl_read(full_path3, intr_value[3]);

    // Check if all 4 cores received the interrupt
    if (&intr_value) begin
        `uvm_info(get_type_name(),
                  $psprintf("%s received at intr_sync_out[%0d] on all 4 cores",
                            signal_name, index),
                  UVM_LOW);
    end else begin
        `uvm_error(get_type_name(),
                   $psprintf("%s NOT received at intr_sync_out[%0d] on core(s): %s",
                             signal_name,
                             index,
                             $psprintf("%s%s%s%s",
                                       (intr_value[0] ? "" : "CORE0 "),
                                       (intr_value[1] ? "" : "CORE1 "),
                                       (intr_value[2] ? "" : "CORE2 "),
                                       (intr_value[3] ? "" : "CORE3 "))));
    end

    // Release the forced signal
    uvm_hdl_release(path);
endtask : test_intr_conn

task npu_intr_connection_test::test_intr_conn_per_core(
    string  path,
    int     index,
    string  signal_name,
    int     core_id
);

    bit      intr_val;
    string   full_path;

    if (core_id < 0 || core_id > 3) begin
        `uvm_fatal(get_type_name(), $psprintf("Invalid core_id: %0d", core_id));
    end

    uvm_hdl_force(path, 1'b1);
    #30ns;

    case(core_id)
        0: full_path = $sformatf("%s[%0d]", `CORE0_INTR_PATH, index);
        1: full_path = $sformatf("%s[%0d]", `CORE1_INTR_PATH, index);
        2: full_path = $sformatf("%s[%0d]", `CORE2_INTR_PATH, index);
        3: full_path = $sformatf("%s[%0d]", `CORE3_INTR_PATH, index);
    endcase

    if(!uvm_hdl_read(full_path, intr_val)) begin
        `uvm_fatal(get_type_name(), $psprintf("Failed to read path: %s", full_path));
    end

    if(intr_val) begin
        `uvm_info(get_type_name(),
                  $psprintf("[PASS] %s (index:%0d) triggered on CORE%0d",
                            signal_name, index, core_id),
                  UVM_LOW);
    end else begin
        `uvm_error(get_type_name(),
                   $psprintf("[FAIL] %s (index:%0d) not triggered on CORE%0d",
                             signal_name, index, core_id));
    end

    uvm_hdl_release(path);
    #10ns;
endtask : test_intr_conn_per_core

`endif