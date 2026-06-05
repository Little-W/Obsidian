`ifndef GUARD_I2C_MST_DUT_SLAVE_SMOKE_SEQUENCE_SV
`define GUARD_I2C_MST_DUT_SLAVE_SMOKE_SEQUENCE_SV

class i2c_mst_dut_slave_base_sequence extends uvm_sequence #(svt_i2c_master_transaction);
  `uvm_object_utils(i2c_mst_dut_slave_base_sequence)
  `uvm_declare_p_sequencer(svt_i2c_master_transaction_sequencer)

  bit [9:0] vip_target_addr = 10'h055;
  byte unsigned write_data[$];
  byte unsigned expected_read_data[$];
  svt_i2c_configuration i2c_cfg;

  function new(string name = "i2c_mst_dut_slave_base_sequence");
    super.new(name);
    write_data = '{8'h21, 8'h43, 8'h65};
    expected_read_data = '{8'ha1, 8'hb2, 8'hc3};
  endfunction

  virtual task setup_common();
    svt_configuration cfg;
    int value;

    p_sequencer.get_cfg(cfg);
    if (!$cast(i2c_cfg, cfg)) begin
      `uvm_fatal("I2C_MST_CFG", "Unable to cast configuration to svt_i2c_configuration")
    end
    if (i2c_cfg.enable_put_response != 1) begin
      `uvm_fatal("I2C_MST_CFG", "i2c_mst_dut_slave_smoke_sequence requires master_cfg[0].enable_put_response=1")
    end

    if ($value$plusargs("I2C_TARGET_ADDR=%h", value)) begin
      vip_target_addr = value[9:0];
    end
  endtask

  virtual function void relax_directed_constraints(svt_i2c_master_transaction req);
    req.reasonable_data.constraint_mode(0);
    req.reasonable_addr.constraint_mode(0);
    req.reasonable_send_start_byte.constraint_mode(0);
    req.reasonable_addr_10bit.constraint_mode(0);
    req.reasonable_arbitrate.constraint_mode(0);
    req.reasonable_abort_if_arb_lost.constraint_mode(0);
    req.reasonable_sr_or_p_gen.constraint_mode(0);
    req.reasonable_retry_if_nack.constraint_mode(0);
  endfunction

  virtual function void log_master_response(string tag,
                                            svt_i2c_master_transaction req,
                                            svt_i2c_master_transaction rsp);
    string ack_text;

    ack_text = "rsp_missing";
    if (rsp != null) begin
      ack_text = "";
      foreach (rsp.ack_detected[i]) begin
        ack_text = {ack_text, $sformatf("%s%0d", (i == 0) ? "" : ",", rsp.ack_detected[i])};
      end
      if (ack_text == "") begin
        ack_text = "none";
      end
    end

    `uvm_info("I2C_VIP_MASTER_RSP",
              $sformatf("%s req_cmd=%s req_addr=0x%03h req_size=%0d rsp_start=%0d rsp_stop=%0d rsp_rep_start=%0d rsp_size=%0d ack=%s",
                        tag, (req.cmd == I2C_WRITE) ? "I2C_WRITE" : "I2C_READ",
                        req.addr, req.data.size(),
                        (rsp == null) ? 0 : rsp.start_detected,
                        (rsp == null) ? 0 : rsp.stop_detected,
                        (rsp == null) ? 0 : rsp.rep_start_detected,
                        (rsp == null) ? 0 : rsp.data.size(),
                        ack_text),
              UVM_LOW)
  endfunction

  virtual task send_write_transaction();
    svt_i2c_master_transaction req;
    svt_i2c_master_transaction rsp;
    int unsigned payload_size;

    req = svt_i2c_master_transaction::type_id::create("dut_slave_write_req");
    start_item(req);
    payload_size = write_data.size();
    relax_directed_constraints(req);
    if (!req.randomize() with {
      req.cmd == I2C_WRITE;
      req.addr == local::vip_target_addr;
      req.addr_10bit == 0;
      req.data.size() == local::payload_size;
      req.sr_or_p_gen == 0;
      req.send_start_byte == 0;
      req.arbitrate == 0;
      req.abort_if_arb_lost == 0;
      req.retry_if_nack == 0;
      req.do_insert_error == 0;
    }) begin
      `uvm_fatal("I2C_MST_RAND", "Failed to randomize DUT-slave write transaction")
    end
    foreach (write_data[i]) begin
      req.data[i] = write_data[i];
    end
    `uvm_info("I2C_VIP_MASTER_WRITE",
              $sformatf("VIP master writes DUT slave addr=0x%03h bytes=%0d data[0]=0x%02h",
                        req.addr, req.data.size(), (req.data.size() == 0) ? 8'hxx : req.data[0]),
              UVM_LOW)
    finish_item(req);
    get_response(rsp);
    log_master_response("write", req, rsp);
  endtask

  virtual task send_read_transaction();
    svt_i2c_master_transaction req;
    svt_i2c_master_transaction rsp;
    int unsigned payload_size;

    req = svt_i2c_master_transaction::type_id::create("dut_slave_read_req");
    start_item(req);
    payload_size = expected_read_data.size();
    relax_directed_constraints(req);
    if (!req.randomize() with {
      req.cmd == I2C_READ;
      req.addr == local::vip_target_addr;
      req.addr_10bit == 0;
      req.data.size() == local::payload_size;
      req.sr_or_p_gen == 0;
      req.send_start_byte == 0;
      req.arbitrate == 0;
      req.abort_if_arb_lost == 0;
      req.retry_if_nack == 0;
      req.do_insert_error == 0;
    }) begin
      `uvm_fatal("I2C_MST_RAND", "Failed to randomize DUT-slave read transaction")
    end
    foreach (expected_read_data[i]) begin
      req.data[i] = 8'h00;
    end
    `uvm_info("I2C_VIP_MASTER_READ",
              $sformatf("VIP master reads DUT slave addr=0x%03h bytes=%0d",
                        req.addr, req.data.size()),
              UVM_LOW)
    finish_item(req);
    get_response(rsp);
    log_master_response("read", req, rsp);
    foreach (expected_read_data[i]) begin
      if ((rsp == null) || (rsp.data.size() <= i) || (rsp.data[i] !== expected_read_data[i])) begin
        `uvm_error("I2C_VIP_MASTER_READ_MISMATCH",
                   $sformatf("read[%0d] expected=0x%02h actual=0x%02h rsp_missing=%0d rsp_size=%0d",
                             i, expected_read_data[i],
                             ((rsp == null) || (rsp.data.size() <= i)) ? 8'hxx : rsp.data[i],
                             (rsp == null), (rsp == null) ? 0 : rsp.data.size()))
      end else begin
        `uvm_info("I2C_VIP_MASTER_READ_MATCH",
                  $sformatf("read[%0d] matched 0x%02h", i, rsp.data[i]),
                  UVM_LOW)
      end
    end
  endtask
endclass

class i2c_mst_dut_slave_write_sequence extends i2c_mst_dut_slave_base_sequence;
  `uvm_object_utils(i2c_mst_dut_slave_write_sequence)

  function new(string name = "i2c_mst_dut_slave_write_sequence");
    super.new(name);
  endfunction

  virtual task body();
    setup_common();
    send_write_transaction();
  endtask
endclass

class i2c_mst_dut_slave_read_sequence extends i2c_mst_dut_slave_base_sequence;
  `uvm_object_utils(i2c_mst_dut_slave_read_sequence)

  function new(string name = "i2c_mst_dut_slave_read_sequence");
    super.new(name);
  endfunction

  virtual task body();
    setup_common();
    send_read_transaction();
  endtask
endclass

class i2c_mst_dut_slave_smoke_sequence extends i2c_mst_dut_slave_base_sequence;
  `uvm_object_utils(i2c_mst_dut_slave_smoke_sequence)

  function new(string name = "i2c_mst_dut_slave_smoke_sequence");
    super.new(name);
  endfunction

  virtual task body();
    setup_common();
    send_write_transaction();
    send_read_transaction();
  endtask
endclass

`endif
