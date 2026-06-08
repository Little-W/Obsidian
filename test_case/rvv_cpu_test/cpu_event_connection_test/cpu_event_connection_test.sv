`ifndef CPU_EVENT_CONNECTION_TEST_SV
`define CPU_EVENT_CONNECTION_TEST_SV

class cpu_event_connection_test extends chip_noc_base_test;
  `uvm_component_utils(cpu_event_connection_test)

  extern function new(string name = "cpu_event_connection_test", uvm_component parent = null);
  extern virtual task main_phase(uvm_phase phase);
  extern task clear_all_rx_masks(string signal_name);
  extern task write_single_rx_mask(bit [31:0] rx_evtc_offset, bit [7:0] tx_mask, string rx_name, string signal_name);
  extern task send_tx_and_check_all_rx(string tx_name, string scenario_name, string active_rx_name, bit mode, string path, time high_time, time settle_time);
  extern task clear_all_tx_evt_rx_signal();
  extern task test_tx_evt_to_each_rx(string path, bit [7:0] tx_mask, string signal_name, bit mode, time high_time = 50ns, time settle_time = 80ns);
  extern task test_tx_evt_negative_to_each_rx(string path, bit [7:0] tx_mask, string signal_name, bit mode, time high_time = 50ns, time settle_time = 80ns);
  extern task check_rx_evt(string rx_path, string rx_name, string tx_name, bit expected_value, string scenario_name);
endclass

function cpu_event_connection_test::new(string name = "cpu_event_connection_test", uvm_component parent = null);
  super.new(name, parent);
endfunction : new

task cpu_event_connection_test::main_phase(uvm_phase phase);
  super.main_phase(phase);
  phase.raise_objection(this);
  `uvm_info(get_type_name(), $psprintf("main_phase start!"), UVM_LOW)
  `uvm_info(get_type_name(), "cpu_event_connection_test start", UVM_LOW);

  // TX/RX event connectivity depends on tx_evt mask register configuration.
  // positive masks
  test_tx_evt_to_each_rx(`CPU_CORE0_TX_EVT_PATH, `CPU_CORE0_TX_EVT_MASK, "CPU_CORE0_TX_EVT", `TEST_RELAY_MODE, 1.25ns);
  test_tx_evt_to_each_rx(`CPU_CORE1_TX_EVT_PATH, `CPU_CORE1_TX_EVT_MASK, "CPU_CORE1_TX_EVT", `TEST_RELAY_MODE, 1.25ns);
  test_tx_evt_to_each_rx(`NPU_CORE0_TX_EVT_PATH, `NPU_CORE0_TX_EVT_MASK, "NPU_CORE0_TX_EVT", `TEST_RELAY_MODE, 50ns);
  test_tx_evt_to_each_rx(`NPU_CORE1_TX_EVT_PATH, `NPU_CORE1_TX_EVT_MASK, "NPU_CORE1_TX_EVT", `TEST_RELAY_MODE, 50ns);
  test_tx_evt_to_each_rx(`NPU_CORE2_TX_EVT_PATH, `NPU_CORE2_TX_EVT_MASK, "NPU_CORE2_TX_EVT", `TEST_RELAY_MODE, 50ns);
  test_tx_evt_to_each_rx(`NPU_CORE3_TX_EVT_PATH, `NPU_CORE3_TX_EVT_MASK, "NPU_CORE3_TX_EVT", `TEST_RELAY_MODE, 50ns);
  test_tx_evt_to_each_rx(`PMU_EVT_PATH, `PMU_EVT_MASK, "PMU_EVT",`TEST_DIREC_MODE, 100ns);
  test_tx_evt_to_each_rx(`HSM_CORE0_TX_EVT_PATH, `HSM_CORE0_TX_EVT_MASK, "HSM_CORE0_TX_EVT", `TEST_RELAY_MODE,  5ns);
  // negative masks
  test_tx_evt_negative_to_each_rx(`CPU_CORE0_TX_EVT_PATH, `CPU_CORE0_TX_EVT_MASK, "CPU_CORE0_TX_EVT", `TEST_RELAY_MODE, 1.25ns);
  test_tx_evt_negative_to_each_rx(`CPU_CORE1_TX_EVT_PATH, `CPU_CORE1_TX_EVT_MASK, "CPU_CORE1_TX_EVT", `TEST_RELAY_MODE, 1.25ns);
  test_tx_evt_negative_to_each_rx(`NPU_CORE0_TX_EVT_PATH, `NPU_CORE0_TX_EVT_MASK, "NPU_CORE0_TX_EVT", `TEST_RELAY_MODE, 50ns);
  test_tx_evt_negative_to_each_rx(`NPU_CORE1_TX_EVT_PATH, `NPU_CORE1_TX_EVT_MASK, "NPU_CORE1_TX_EVT", `TEST_RELAY_MODE, 50ns);
  test_tx_evt_negative_to_each_rx(`NPU_CORE2_TX_EVT_PATH, `NPU_CORE2_TX_EVT_MASK, "NPU_CORE2_TX_EVT", `TEST_RELAY_MODE, 50ns);
  test_tx_evt_negative_to_each_rx(`NPU_CORE3_TX_EVT_PATH, `NPU_CORE3_TX_EVT_MASK, "NPU_CORE3_TX_EVT", `TEST_RELAY_MODE, 50ns);
  test_tx_evt_negative_to_each_rx(`PMU_EVT_PATH, `PMU_EVT_MASK, "PMU_EVT", `TEST_DIREC_MODE, 100ns);
  test_tx_evt_negative_to_each_rx(`HSM_CORE0_TX_EVT_PATH, `HSM_CORE0_TX_EVT_MASK, "HSM_CORE0_TX_EVT", `TEST_RELAY_MODE, 5ns);

  clear_all_rx_masks("EVT_MASK_CLEAR");

  `uvm_info(get_type_name(), $psprintf("main_phase done!"), UVM_LOW)
  phase.drop_objection(this);
endtask : main_phase

task cpu_event_connection_test::clear_all_rx_masks(string signal_name);
  `uvm_info(get_type_name(), $psprintf("Clear all rx evt mask regs for %s", signal_name), UVM_LOW)

  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `CPU_CORE0_TX_EVTC_OFFSET, `EVT_MASK_CLEAR);
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `CPU_CORE1_TX_EVTC_OFFSET, `EVT_MASK_CLEAR);
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `NPU_CORE0_TX_EVTC_OFFSET, `EVT_MASK_CLEAR);
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `NPU_CORE1_TX_EVTC_OFFSET, `EVT_MASK_CLEAR);
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `NPU_CORE2_TX_EVTC_OFFSET, `EVT_MASK_CLEAR);
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `NPU_CORE3_TX_EVTC_OFFSET, `EVT_MASK_CLEAR);
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `HSM_CORE0_TX_EVTC_OFFSET, `EVT_MASK_CLEAR);

  #20ns;
endtask : clear_all_rx_masks

task cpu_event_connection_test::write_single_rx_mask(bit [31:0] rx_evtc_offset, bit [7:0] tx_mask, string rx_name, string signal_name);
  `uvm_info(get_type_name(), $psprintf("Configure single rx mask for %s with %s, mask=0x%0h", signal_name, rx_name, tx_mask), UVM_LOW)
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + rx_evtc_offset, tx_mask);
  #50ns;
endtask : write_single_rx_mask

task cpu_event_connection_test::check_rx_evt(string rx_path, string rx_name, string tx_name, bit expected_value, string scenario_name);
  bit rx_value;

  if (!uvm_hdl_read(rx_path, rx_value)) begin
    `uvm_error(get_type_name(), $psprintf("Failed to read RX path %s while testing %s", rx_path, tx_name));
    return;
  end

  if (rx_value === expected_value) begin
    `uvm_info(get_type_name(), $psprintf("[%s] Connectivity verified for %s -> %s, expected=%0b actual=%0b", scenario_name, tx_name, rx_name, expected_value, rx_value), UVM_LOW);
  end else begin
    `uvm_error(get_type_name(), $psprintf("[%s] Connectivity failed for %s -> %s, expected=%0b actual=%0b", scenario_name, tx_name, rx_name, expected_value, rx_value));
  end
endtask : check_rx_evt

task cpu_event_connection_test::send_tx_and_check_all_rx(string tx_name, string scenario_name, string active_rx_name, bit mode, string path, time high_time, time settle_time);
  
  if (!uvm_hdl_force(path, 1'b1)) begin
    `uvm_error(get_type_name(), $psprintf("Failed to force TX EVT source path %s for %s", path, tx_name));
    return;
  end

  #high_time;
  if(mode == `TEST_RELAY_MODE) begin
    uvm_hdl_release(path);
  end

  #settle_time;
  
  check_rx_evt(`CPU_CORE0_RX_EVT_PATH, "CPU_CORE0_RX_EVT", tx_name, (active_rx_name == "CPU_CORE0_RX_EVT"), scenario_name);
  check_rx_evt(`CPU_CORE1_RX_EVT_PATH, "CPU_CORE1_RX_EVT", tx_name, (active_rx_name == "CPU_CORE1_RX_EVT"), scenario_name);
  check_rx_evt(`NPU_CORE0_RX_EVT_PATH, "NPU_CORE0_RX_EVT", tx_name, (active_rx_name == "NPU_CORE0_RX_EVT"), scenario_name);
  check_rx_evt(`NPU_CORE1_RX_EVT_PATH, "NPU_CORE1_RX_EVT", tx_name, (active_rx_name == "NPU_CORE1_RX_EVT"), scenario_name);
  check_rx_evt(`NPU_CORE2_RX_EVT_PATH, "NPU_CORE2_RX_EVT", tx_name, (active_rx_name == "NPU_CORE2_RX_EVT"), scenario_name);
  check_rx_evt(`NPU_CORE3_RX_EVT_PATH, "NPU_CORE3_RX_EVT", tx_name, (active_rx_name == "NPU_CORE3_RX_EVT"), scenario_name);
  check_rx_evt(`HSM_CORE0_RX_EVT_PATH, "HSM_CORE0_RX_EVT", tx_name, (active_rx_name == "HSM_CORE0_RX_EVT"), scenario_name);

  if(mode == `TEST_DIREC_MODE) begin
    uvm_hdl_release(path);
  end

endtask : send_tx_and_check_all_rx


task cpu_event_connection_test::clear_all_tx_evt_rx_signal();
  `uvm_info(get_type_name(), "Clear all SCU-side tx_evt_up registers", UVM_LOW)

  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `CPU_CORE0_TX_EVT_UP_OFFSET, 32'h0);
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `CPU_CORE1_TX_EVT_UP_OFFSET, 32'h0);
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `NPU_CORE0_TX_EVT_UP_OFFSET, 32'h0);
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `NPU_CORE1_TX_EVT_UP_OFFSET, 32'h0);
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `NPU_CORE2_TX_EVT_UP_OFFSET, 32'h0);
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `NPU_CORE3_TX_EVT_UP_OFFSET, 32'h0);
  noc_reg_write(`MCU_SUB_SCU_BASE_ADDR + `HSM_CORE0_TX_EVT_UP_OFFSET, 32'h0);


  #20ns;
endtask : clear_all_tx_evt_rx_signal

task cpu_event_connection_test::test_tx_evt_to_each_rx(string path, bit [7:0] tx_mask, string signal_name, bit mode, time high_time, time settle_time);
  string scenario_name;

  clear_all_rx_masks($sformatf("%s_CPU_CORE0_RX_EVT_CLEAR", signal_name));
  write_single_rx_mask(`CPU_CORE0_TX_EVTC_OFFSET, tx_mask, "CPU_CORE0_RX_EVT", signal_name);
  

  scenario_name = "positive-CPU_CORE0_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "CPU_CORE0_RX_EVT", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_CPU_CORE1_RX_EVT_CLEAR", signal_name));
  write_single_rx_mask(`CPU_CORE1_TX_EVTC_OFFSET, tx_mask, "CPU_CORE1_RX_EVT", signal_name);
  

  scenario_name = "positive-CPU_CORE1_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "CPU_CORE1_RX_EVT", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_NPU_CORE0_RX_EVT_CLEAR", signal_name));
  write_single_rx_mask(`NPU_CORE0_TX_EVTC_OFFSET, tx_mask, "NPU_CORE0_RX_EVT", signal_name);
  

  scenario_name = "positive-NPU_CORE0_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "NPU_CORE0_RX_EVT", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_NPU_CORE1_RX_EVT_CLEAR", signal_name));
  write_single_rx_mask(`NPU_CORE1_TX_EVTC_OFFSET, tx_mask, "NPU_CORE1_RX_EVT", signal_name);
  

  scenario_name = "positive-NPU_CORE1_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "NPU_CORE1_RX_EVT", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_NPU_CORE2_RX_EVT_CLEAR", signal_name));
  write_single_rx_mask(`NPU_CORE2_TX_EVTC_OFFSET, tx_mask, "NPU_CORE2_RX_EVT", signal_name);
  

  scenario_name = "positive-NPU_CORE2_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "NPU_CORE2_RX_EVT", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_NPU_CORE3_RX_EVT_CLEAR", signal_name));
  write_single_rx_mask(`NPU_CORE3_TX_EVTC_OFFSET, tx_mask, "NPU_CORE3_RX_EVT", signal_name);
  

  scenario_name = "positive-NPU_CORE3_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "NPU_CORE3_RX_EVT", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_HSM_CORE0_RX_EVT_CLEAR", signal_name));
  write_single_rx_mask(`HSM_CORE0_TX_EVTC_OFFSET, tx_mask, "HSM_CORE0_RX_EVT", signal_name);
  

  scenario_name = "positive-HSM_CORE0_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "HSM_CORE0_RX_EVT", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_POSITIVE_DONE", signal_name));
endtask : test_tx_evt_to_each_rx

task cpu_event_connection_test::test_tx_evt_negative_to_each_rx(string path, bit [7:0] tx_mask, string signal_name, bit mode, time high_time, time settle_time);
  bit [7:0] wrong_mask;
  string scenario_name;

  wrong_mask = (~tx_mask) & 8'hFF;

  clear_all_rx_masks($sformatf("%s_MASK_CLEAR_NEGATIVE", signal_name));
  

  send_tx_and_check_all_rx(signal_name, "negative-clear-mask", "", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_CPU_CORE0_RX_EVT_WRONG_CLEAR", signal_name));
  write_single_rx_mask(`CPU_CORE0_TX_EVTC_OFFSET, wrong_mask, "CPU_CORE0_RX_EVT", signal_name);
  

  scenario_name = "negative-wrong-mask-CPU_CORE0_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_CPU_CORE1_RX_EVT_WRONG_CLEAR", signal_name));
  write_single_rx_mask(`CPU_CORE1_TX_EVTC_OFFSET, wrong_mask, "CPU_CORE1_RX_EVT", signal_name);
  

  scenario_name = "negative-wrong-mask-CPU_CORE1_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_NPU_CORE0_RX_EVT_WRONG_CLEAR", signal_name));
  write_single_rx_mask(`NPU_CORE0_TX_EVTC_OFFSET, wrong_mask, "NPU_CORE0_RX_EVT", signal_name);
  

  scenario_name = "negative-wrong-mask-NPU_CORE0_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_NPU_CORE1_RX_EVT_WRONG_CLEAR", signal_name));
  write_single_rx_mask(`NPU_CORE1_TX_EVTC_OFFSET, wrong_mask, "NPU_CORE1_RX_EVT", signal_name);
  

  scenario_name = "negative-wrong-mask-NPU_CORE1_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_NPU_CORE2_RX_EVT_WRONG_CLEAR", signal_name));
  write_single_rx_mask(`NPU_CORE2_TX_EVTC_OFFSET, wrong_mask, "NPU_CORE2_RX_EVT", signal_name);
  

  scenario_name = "negative-wrong-mask-NPU_CORE2_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_NPU_CORE3_RX_EVT_WRONG_CLEAR", signal_name));
  write_single_rx_mask(`NPU_CORE3_TX_EVTC_OFFSET, wrong_mask, "NPU_CORE3_RX_EVT", signal_name);
  

  scenario_name = "negative-wrong-mask-NPU_CORE3_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_HSM_CORE0_RX_EVT_WRONG_CLEAR", signal_name));
  write_single_rx_mask(`HSM_CORE0_TX_EVTC_OFFSET, wrong_mask, "HSM_CORE0_RX_EVT", signal_name);
  

  scenario_name = "negative-wrong-mask-HSM_CORE0_RX_EVT";
  send_tx_and_check_all_rx(signal_name, scenario_name, "", mode, path, high_time, settle_time);
  clear_all_tx_evt_rx_signal();

  clear_all_rx_masks($sformatf("%s_NEGATIVE_DONE", signal_name));
endtask : test_tx_evt_negative_to_each_rx

`endif