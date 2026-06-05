class i2c_basic_sequence extends base_virt_seq;
  `uvm_object_utils(i2c_basic_sequence)

  localparam bit [31:0] IC_CON            = 32'h000;
  localparam bit [31:0] IC_TAR            = 32'h004;
  localparam bit [31:0] IC_DATA_CMD       = 32'h010;
  localparam bit [31:0] IC_SS_SCL_HCNT    = 32'h014;
  localparam bit [31:0] IC_SS_SCL_LCNT    = 32'h018;
  localparam bit [31:0] IC_FS_SCL_HCNT    = 32'h01c;
  localparam bit [31:0] IC_FS_SCL_LCNT    = 32'h020;
  localparam bit [31:0] IC_HS_SCL_HCNT    = 32'h024;
  localparam bit [31:0] IC_HS_SCL_LCNT    = 32'h028;
  localparam bit [31:0] IC_RAW_INTR_STAT  = 32'h034;
  localparam bit [31:0] IC_RX_TL          = 32'h038;
  localparam bit [31:0] IC_TX_TL          = 32'h03c;
  localparam bit [31:0] IC_CLR_INTR       = 32'h040;
  localparam bit [31:0] IC_CLR_TX_ABRT    = 32'h054;
  localparam bit [31:0] IC_CLR_STOP_DET   = 32'h060;
  localparam bit [31:0] IC_ENABLE         = 32'h06c;
  localparam bit [31:0] IC_STATUS         = 32'h070;
  localparam bit [31:0] IC_TX_ABRT_SOURCE = 32'h080;
  localparam bit [31:0] IC_ENABLE_STATUS  = 32'h09c;

  rand bit [9:0]  i2c_target_addr = 10'h055;
  rand byte unsigned write_data[$];
  rand byte unsigned expected_read_data[$];
  string i2c_speed_mode = "standard";
  int unsigned i2c_timeout_scale = 4;
  int unsigned i2c_start_delay_cycles = 100;

  constraint basic_payload_c {
    write_data.size() == 4;
    expected_read_data.size() == 3;
    foreach (write_data[i]) write_data[i] inside {[8'h00:8'hff]};
  }

  function new(string name = "i2c_basic_sequence");
    super.new(name);
    write_data = '{8'h12, 8'h34, 8'ha5, 8'h5a};
    expected_read_data = '{8'h34, 8'ha5, 8'h5a};
  endfunction

  virtual task body();
    wait_reset_done();
    configure_from_plusargs();
    set_i2c_speed_mode(i2c_speed_mode);

`ifdef BMS_USE_SVT_VIP
    fork
      start_i2c_vip_slave_sequence("i2c_slv_directed_sequence");
    join_none

    i2c_dut_init_controller();
    i2c_dut_write_bytes(write_data);
    i2c_dut_read_and_check(expected_read_data);
    i2c_dut_check_no_abort();
    wait_i2c_observation_window(100);
`else
    `uvm_fatal("I2C_SVT_REQUIRED", "DUT register smoke requires BMS_USE_SVT_VIP APB/I2C VIP sequences")
`endif
  endtask

  virtual function void configure_from_plusargs();
    string arg;
    int value;

    if ($value$plusargs("I2C_SPEED_MODE=%s", arg)) begin
      i2c_speed_mode = arg;
    end
    if ($value$plusargs("I2C_TARGET_ADDR=%h", value)) begin
      i2c_target_addr = value[9:0];
    end
    if ($value$plusargs("I2C_TIMEOUT_SCALE=%d", value)) begin
      i2c_timeout_scale = value;
    end
    if ($value$plusargs("I2C_START_DELAY_CYCLES=%d", value)) begin
      i2c_start_delay_cycles = value;
    end
    if (i2c_timeout_scale < 1) begin
      i2c_timeout_scale = 1;
    end
  endfunction

`ifdef BMS_USE_SVT_VIP
  virtual task i2c_dut_init_controller();
    bit [31:0] con;

    apb_vip_write32(IC_ENABLE, 32'h0);
    poll_reg_bit(IC_ENABLE_STATUS, 0, 1'b0, 2000, "IC_ENABLE_STATUS.IC_EN disable");
    poll_reg_bit(IC_STATUS, 2, 1'b1, 2000, "IC_STATUS.TFE after disable");
    read_clear(IC_CLR_INTR);

    con = build_ic_con_value(i2c_speed_mode);
    apb_vip_write32(IC_CON, con);
    check_reg_value(IC_CON, con, 32'h0000_007f, "IC_CON");
    apb_vip_write32(IC_TAR, {22'h0, i2c_target_addr});
    check_reg_value(IC_TAR, {22'h0, i2c_target_addr}, 32'h0000_03ff, "IC_TAR");
    apb_vip_write32(IC_RX_TL, 32'h0);
    apb_vip_write32(IC_TX_TL, 32'h0);
    program_scl_counts(i2c_speed_mode);

    apb_vip_write32(IC_ENABLE, 32'h1);
    check_reg_value(IC_ENABLE, 32'h1, 32'h0000_0001, "IC_ENABLE");
    poll_reg_bit(IC_ENABLE_STATUS, 0, 1'b1, 2000, "IC_ENABLE_STATUS.IC_EN enable");
    if (i2c_start_delay_cycles > 0) begin
      `uvm_info("I2C_START_DELAY",
                $sformatf("wait %0d clk cycles before starting I2C bus access",
                          i2c_start_delay_cycles),
                UVM_LOW)
      wait_i2c_observation_window(i2c_start_delay_cycles);
    end
  endtask

  virtual function bit [31:0] build_ic_con_value(string mode);
    bit [1:0] speed;

    if (mode == "standard") begin
      speed = 2'd1;
    end else if ((mode == "fast") || (mode == "fast_plus")) begin
      speed = 2'd2;
    end else if (mode == "high") begin
      speed = 2'd3;
    end else begin
      speed = 2'd1;
    end

    return (32'h1 << 0) | ({30'h0, speed} << 1) | (32'h1 << 5) | (32'h1 << 6);
  endfunction

  virtual task program_scl_counts(string mode);
    if (mode == "standard") begin
      apb_vip_write32(IC_SS_SCL_HCNT, 32'd400);
      apb_vip_write32(IC_SS_SCL_LCNT, 32'd470);
    end else if ((mode == "fast") || (mode == "fast_plus")) begin
      apb_vip_write32(IC_FS_SCL_HCNT, 32'd60);
      apb_vip_write32(IC_FS_SCL_LCNT, 32'd130);
    end else if (mode == "high") begin
      apb_vip_write32(IC_HS_SCL_HCNT, 32'd8);
      apb_vip_write32(IC_HS_SCL_LCNT, 32'd16);
    end
  endtask

  virtual task i2c_dut_write_bytes(input byte unsigned data_q[$]);
    foreach (data_q[i]) begin
      bit [31:0] cmd;
      poll_reg_bit(IC_STATUS, 1, 1'b1, 2000, "IC_STATUS.TFNF before write");
      cmd = {21'h0, 1'b0, (i == data_q.size() - 1), 1'b0, data_q[i]};
      apb_vip_write32(IC_DATA_CMD, cmd);
    end
    wait_transfer_done("write", data_q.size());
  endtask

  virtual task i2c_dut_read_and_check(input byte unsigned exp_q[$]);
    foreach (exp_q[i]) begin
      bit [31:0] cmd;
      bit [31:0] actual;

      poll_reg_bit(IC_STATUS, 1, 1'b1, 2000, "IC_STATUS.TFNF before read command");
      cmd = {21'h0, (i == 0), (i == exp_q.size() - 1), 1'b1, 8'h00};
      apb_vip_write32(IC_DATA_CMD, cmd);
      wait_rx_data_or_intr(i2c_timeout_ic_cycles(2),
                           $sformatf("read[%0d] IC_STATUS.RFNE before reading IC_DATA_CMD", i));
      apb_vip_read32(IC_DATA_CMD, actual);
      if (actual[7:0] !== exp_q[i]) begin
        `uvm_error("I2C_DATA_MISMATCH", $sformatf("read[%0d] expected=0x%02h actual=0x%02h raw=0x%08h", i, exp_q[i], actual[7:0], actual))
      end else begin
        `uvm_info("I2C_DATA_CHECK", $sformatf("read[%0d] matched 0x%02h", i, actual[7:0]), UVM_LOW)
      end
    end
    wait_transfer_done("read", exp_q.size() + 1);
  endtask

  virtual task wait_transfer_done(string tag, int unsigned transfer_bytes = 1);
    bit [31:0] raw_intr;

    poll_reg_bit_i2c_time(IC_STATUS, 2, 1'b1, i2c_timeout_ic_cycles(transfer_bytes),
                          $sformatf("IC_STATUS.TFE after %s", tag));
    wait_stop_or_master_idle(tag, i2c_timeout_ic_cycles(transfer_bytes));
    apb_vip_read32(IC_RAW_INTR_STAT, raw_intr);
    if (raw_intr[6]) begin
      report_and_clear_abort($sformatf("%s transfer", tag));
    end
    if (raw_intr[9]) begin
      read_clear(IC_CLR_STOP_DET);
    end
  endtask

  virtual task wait_stop_or_master_idle(string tag, int unsigned max_ic_clk_cycles);
    bit [31:0] status;
    bit [31:0] raw_intr;
    bit [31:0] abrt_source;
    int unsigned elapsed_ic_clk_cycles;
    int unsigned poll_gap_ic_clk_cycles;
    int unsigned polls;

    poll_gap_ic_clk_cycles = scl_period_ic_clk_cycles(i2c_speed_mode) / 4;
    if (poll_gap_ic_clk_cycles < 16) begin
      poll_gap_ic_clk_cycles = 16;
    end

    while (elapsed_ic_clk_cycles <= max_ic_clk_cycles) begin
      apb_vip_read32(IC_STATUS, status);
      apb_vip_read32(IC_RAW_INTR_STAT, raw_intr);
      polls++;

      if (raw_intr[6]) begin
        apb_vip_read32(IC_TX_ABRT_SOURCE, abrt_source);
        read_clear(IC_CLR_TX_ABRT);
        `uvm_fatal("I2C_TX_ABRT",
                   $sformatf("%s: TX_ABRT while waiting done, status=0x%08h raw_intr=0x%08h tx_abrt_source=0x%08h",
                             tag, status, raw_intr, abrt_source))
      end

      if (raw_intr[9] || (status[5] === 1'b0)) begin
        `uvm_info("I2C_XFER_DONE",
                  $sformatf("%s done after %0d polls, %0d ic_clk cycles, status=0x%08h raw_intr=0x%08h",
                            tag, polls, elapsed_ic_clk_cycles, status, raw_intr),
                  UVM_LOW)
        return;
      end

      repeat (poll_gap_ic_clk_cycles) @(posedge vif.ic_clk);
      elapsed_ic_clk_cycles += poll_gap_ic_clk_cycles;
    end

    apb_vip_read32(IC_STATUS, status);
    apb_vip_read32(IC_RAW_INTR_STAT, raw_intr);
    `uvm_fatal("I2C_POLL_TIMEOUT",
               $sformatf("%s transfer did not complete after %0d polls, %0d/%0d ic_clk cycles, final status=0x%08h raw_intr=0x%08h",
                         tag, polls, elapsed_ic_clk_cycles, max_ic_clk_cycles, status, raw_intr))
  endtask

  virtual task i2c_dut_check_no_abort();
    bit [31:0] raw_intr;
    bit [31:0] abrt_source;

    apb_vip_read32(IC_RAW_INTR_STAT, raw_intr);
    apb_vip_read32(IC_TX_ABRT_SOURCE, abrt_source);
    if (raw_intr[6] || (abrt_source[20:0] != 21'h0)) begin
      `uvm_error("I2C_TX_ABRT", $sformatf("unexpected abort raw_intr=0x%08h tx_abrt_source=0x%08h", raw_intr, abrt_source))
      read_clear(IC_CLR_TX_ABRT);
    end
  endtask

  virtual task i2c_dut_write_bytes_expect_abort(input byte unsigned data_q[$], input string context);
    bit [31:0] raw_intr;

    foreach (data_q[i]) begin
      bit [31:0] cmd;

      apb_vip_read32(IC_RAW_INTR_STAT, raw_intr);
      if (raw_intr[6]) begin
        break;
      end

      poll_reg_bit(IC_STATUS, 1, 1'b1, 2000, "IC_STATUS.TFNF before expected-abort write");
      cmd = {21'h0, 1'b0, (i == data_q.size() - 1), 1'b0, data_q[i]};
      apb_vip_write32(IC_DATA_CMD, cmd);
    end

    i2c_dut_expect_abort(context, i2c_timeout_ic_cycles(data_q.size()));
  endtask

  virtual task i2c_dut_expect_abort(string context, int unsigned max_ic_clk_cycles);
    bit [31:0] raw_intr;
    bit [31:0] abrt_source;
    int unsigned elapsed_ic_clk_cycles;
    int unsigned poll_gap_ic_clk_cycles;
    int unsigned polls;

    poll_gap_ic_clk_cycles = scl_period_ic_clk_cycles(i2c_speed_mode) / 4;
    if (poll_gap_ic_clk_cycles < 16) begin
      poll_gap_ic_clk_cycles = 16;
    end

    while (elapsed_ic_clk_cycles <= max_ic_clk_cycles) begin
      apb_vip_read32(IC_RAW_INTR_STAT, raw_intr);
      apb_vip_read32(IC_TX_ABRT_SOURCE, abrt_source);
      polls++;

      if (raw_intr[6] || (abrt_source[20:0] != 21'h0)) begin
        `uvm_info("I2C_EXPECTED_ABORT",
                  $sformatf("%s observed TX_ABRT after %0d polls, raw_intr=0x%08h tx_abrt_source=0x%08h",
                            context, polls, raw_intr, abrt_source),
                  UVM_LOW)
        read_clear(IC_CLR_TX_ABRT);
        return;
      end

      repeat (poll_gap_ic_clk_cycles) @(posedge vif.ic_clk);
      elapsed_ic_clk_cycles += poll_gap_ic_clk_cycles;
    end

    apb_vip_read32(IC_RAW_INTR_STAT, raw_intr);
    apb_vip_read32(IC_TX_ABRT_SOURCE, abrt_source);
    `uvm_fatal("I2C_EXPECTED_ABORT_MISSING",
               $sformatf("%s did not observe TX_ABRT after %0d polls, %0d/%0d ic_clk cycles, raw_intr=0x%08h tx_abrt_source=0x%08h",
                         context, polls, elapsed_ic_clk_cycles, max_ic_clk_cycles, raw_intr, abrt_source))
  endtask

  virtual task poll_reg_bit(bit [31:0] addr, int unsigned bit_idx, bit exp, int unsigned max_polls, string what);
    bit [31:0] data;

    repeat (max_polls) begin
      apb_vip_read32(addr, data);
      if (data[bit_idx] === exp) begin
        return;
      end
      repeat (2) @(posedge vif.pclk);
    end
    `uvm_fatal("I2C_POLL_TIMEOUT", $sformatf("%s did not become %0b after %0d polls", what, exp, max_polls))
  endtask

  virtual task poll_reg_bit_i2c_time(bit [31:0] addr, int unsigned bit_idx, bit exp,
                                     int unsigned max_ic_clk_cycles, string what);
    bit [31:0] data;
    int unsigned elapsed_ic_clk_cycles;
    int unsigned poll_gap_ic_clk_cycles;
    int unsigned polls;

    poll_gap_ic_clk_cycles = scl_period_ic_clk_cycles(i2c_speed_mode) / 4;
    if (poll_gap_ic_clk_cycles < 16) begin
      poll_gap_ic_clk_cycles = 16;
    end

    while (elapsed_ic_clk_cycles <= max_ic_clk_cycles) begin
      apb_vip_read32(addr, data);
      polls++;
      if (data[bit_idx] === exp) begin
        `uvm_info("I2C_POLL_DONE",
                  $sformatf("%s became %0b after %0d polls and %0d ic_clk cycles",
                            what, exp, polls, elapsed_ic_clk_cycles),
                  UVM_LOW)
        return;
      end
      repeat (poll_gap_ic_clk_cycles) @(posedge vif.ic_clk);
      elapsed_ic_clk_cycles += poll_gap_ic_clk_cycles;
    end

    `uvm_fatal("I2C_POLL_TIMEOUT",
               $sformatf("%s did not become %0b after %0d polls, %0d/%0d ic_clk cycles",
                         what, exp, polls, elapsed_ic_clk_cycles, max_ic_clk_cycles))
  endtask

  virtual task wait_rx_data_or_intr(int unsigned max_ic_clk_cycles, string what);
    bit [31:0] status;
    bit [31:0] raw_intr;
    bit [31:0] abrt_source;
    int unsigned elapsed_ic_clk_cycles;
    int unsigned poll_gap_ic_clk_cycles;
    int unsigned polls;

    poll_gap_ic_clk_cycles = scl_period_ic_clk_cycles(i2c_speed_mode) / 4;
    if (poll_gap_ic_clk_cycles < 16) begin
      poll_gap_ic_clk_cycles = 16;
    end

    while (elapsed_ic_clk_cycles <= max_ic_clk_cycles) begin
      apb_vip_read32(IC_STATUS, status);
      apb_vip_read32(IC_RAW_INTR_STAT, raw_intr);
      polls++;

      if (status[3] === 1'b1) begin
        `uvm_info("I2C_RX_READY",
                  $sformatf("%s: RFNE=1 after %0d polls, status=0x%08h raw_intr=0x%08h",
                            what, polls, status, raw_intr),
                  UVM_LOW)
        return;
      end

      if (raw_intr[6]) begin
        apb_vip_read32(IC_TX_ABRT_SOURCE, abrt_source);
        read_clear(IC_CLR_TX_ABRT);
        `uvm_fatal("I2C_TX_ABRT",
                   $sformatf("%s: TX_ABRT while waiting RX data, status=0x%08h raw_intr=0x%08h tx_abrt_source=0x%08h",
                             what, status, raw_intr, abrt_source))
      end

      if (raw_intr[2]) begin
        `uvm_warning("I2C_RX_INTR_NO_RFNE",
                     $sformatf("%s: RX_FULL interrupt set but RFNE=0, status=0x%08h raw_intr=0x%08h; retrying",
                               what, status, raw_intr))
      end

      if (raw_intr[9]) begin
        read_clear(IC_CLR_STOP_DET);
        `uvm_fatal("I2C_STOP_NO_RX",
                   $sformatf("%s: STOP_DET before RX FIFO non-empty, status=0x%08h raw_intr=0x%08h",
                             what, status, raw_intr))
      end

      repeat (poll_gap_ic_clk_cycles) @(posedge vif.ic_clk);
      elapsed_ic_clk_cycles += poll_gap_ic_clk_cycles;
    end

    apb_vip_read32(IC_STATUS, status);
    apb_vip_read32(IC_RAW_INTR_STAT, raw_intr);
    `uvm_fatal("I2C_POLL_TIMEOUT",
               $sformatf("%s did not receive RX data after %0d polls, %0d/%0d ic_clk cycles, final status=0x%08h raw_intr=0x%08h",
                         what, polls, elapsed_ic_clk_cycles, max_ic_clk_cycles, status, raw_intr))
  endtask

  virtual function int unsigned scl_period_ic_clk_cycles(string mode);
    if (mode == "standard") begin
      return 400 + 470;
    end else if ((mode == "fast") || (mode == "fast_plus")) begin
      return 60 + 130;
    end else if (mode == "high") begin
      return 8 + 16;
    end
    return 400 + 470;
  endfunction

  virtual function int unsigned i2c_timeout_ic_cycles(int unsigned transfer_bytes);
    int unsigned bits_on_bus;
    int unsigned scl_cycles;
    int unsigned timeout_cycles;

    if (transfer_bytes < 1) begin
      transfer_bytes = 1;
    end

    bits_on_bus = (transfer_bytes * 9) + 4;
    scl_cycles = bits_on_bus * scl_period_ic_clk_cycles(i2c_speed_mode);
    timeout_cycles = scl_cycles * i2c_timeout_scale;

    if (timeout_cycles < 2000) begin
      timeout_cycles = 2000;
    end
    `uvm_info("I2C_TIMEOUT_CFG",
              $sformatf("mode=%s transfer_bytes=%0d scl_period_ic_clk=%0d scale=%0d timeout_ic_clk_cycles=%0d",
                        i2c_speed_mode, transfer_bytes, scl_period_ic_clk_cycles(i2c_speed_mode),
                        i2c_timeout_scale, timeout_cycles),
              UVM_DEBUG)
    return timeout_cycles;
  endfunction

  virtual task check_reg_value(bit [31:0] addr, bit [31:0] exp, bit [31:0] mask, string name);
    bit [31:0] actual;

    apb_vip_read32(addr, actual);
    `uvm_info("I2C_REG_CHECK", $sformatf("%s addr=0x%08h exp=0x%08h actual=0x%08h mask=0x%08h", name, addr, exp, actual, mask), UVM_LOW)
    if ((actual & mask) !== (exp & mask)) begin
      `uvm_error("I2C_REG_MISMATCH", $sformatf("%s readback mismatch exp_masked=0x%08h actual_masked=0x%08h", name, (exp & mask), (actual & mask)))
    end
  endtask

  virtual task report_and_clear_abort(string context);
    bit [31:0] abrt_source;

    apb_vip_read32(IC_TX_ABRT_SOURCE, abrt_source);
    `uvm_error("I2C_TX_ABRT", $sformatf("%s aborted, IC_TX_ABRT_SOURCE=0x%08h", context, abrt_source))
    read_clear(IC_CLR_TX_ABRT);
  endtask

  virtual task read_clear(bit [31:0] addr);
    bit [31:0] data;

    apb_vip_read32(addr, data);
  endtask
`endif
endclass
