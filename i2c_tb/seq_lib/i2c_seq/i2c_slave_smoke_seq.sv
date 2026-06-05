class i2c_slave_smoke_seq extends i2c_basic_sequence;
  `uvm_object_utils(i2c_slave_smoke_seq)

  localparam bit [31:0] SLV_IC_CON           = 32'h000;
  localparam bit [31:0] SLV_IC_TAR           = 32'h004;
  localparam bit [31:0] SLV_IC_SAR           = 32'h008;
  localparam bit [31:0] SLV_IC_DATA_CMD      = 32'h010;
  localparam bit [31:0] SLV_IC_INTR_STAT     = 32'h02c;
  localparam bit [31:0] SLV_IC_INTR_MASK     = 32'h030;
  localparam bit [31:0] SLV_IC_RAW_INTR_STAT = 32'h034;
  localparam bit [31:0] SLV_IC_RX_TL         = 32'h038;
  localparam bit [31:0] SLV_IC_TX_TL         = 32'h03c;
  localparam bit [31:0] SLV_IC_CLR_INTR      = 32'h040;
  localparam bit [31:0] SLV_IC_CLR_RD_REQ    = 32'h050;
  localparam bit [31:0] SLV_IC_CLR_STOP_DET  = 32'h060;
  localparam bit [31:0] SLV_IC_CLR_START_DET = 32'h064;
  localparam bit [31:0] SLV_IC_ENABLE        = 32'h06c;
  localparam bit [31:0] SLV_IC_STATUS        = 32'h070;
  localparam bit [31:0] SLV_IC_TXFLR         = 32'h074;
  localparam bit [31:0] SLV_IC_RXFLR         = 32'h078;
  localparam bit [31:0] SLV_IC_SLV_DATA_NACK_ONLY = 32'h084;
  localparam bit [31:0] SLV_IC_ENABLE_STATUS = 32'h09c;
  localparam bit [31:0] SLV_IC_COMP_PARAM_1  = 32'h0f4;
  localparam bit [31:0] SLV_IC_ENABLE_EN     = 32'h0000_0001;
  localparam bit [31:0] SLV_IC_ENABLE_SAR_EN = 32'h0008_0000;
  localparam bit [31:0] SLV_IC_TARGET_ACK_MASK = 32'h0000_004f;

  bit i2c_target_keep_master = 1'b0;
  bit [9:0] i2c_controller_tar_addr = 10'h056;
  bit i2c_controller_tar_from_plusarg;
  byte unsigned slave_rx_expected[$];
  byte unsigned slave_tx_payload[$];

  function new(string name = "i2c_slave_smoke_seq");
    super.new(name);
    slave_rx_expected = '{8'h21, 8'h43, 8'h65};
    slave_tx_payload = '{8'ha1, 8'hb2, 8'hc3};
  endfunction

  virtual function void configure_from_plusargs();
    int value;
    bit [9:0] adjusted_tar;

    super.configure_from_plusargs();
    if ($value$plusargs("I2C_TARGET_KEEP_MASTER=%d", value)) begin
      i2c_target_keep_master = (value != 0);
    end
    if ($value$plusargs("I2C_CONTROLLER_TAR_ADDR=%h", value)) begin
      i2c_controller_tar_addr = value[9:0];
      i2c_controller_tar_from_plusarg = 1'b1;
    end else begin
      i2c_controller_tar_addr = select_non_self_tar_addr(i2c_target_addr);
      i2c_controller_tar_from_plusarg = 1'b0;
    end

    if (i2c_controller_tar_addr[6:0] == i2c_target_addr[6:0]) begin
      adjusted_tar = select_non_self_tar_addr(i2c_target_addr);
      `uvm_warning("I2C_TARGET_SELF_ADDR",
                   $sformatf("I2C_CONTROLLER_TAR_ADDR lower 7 bits equal IC_SAR target_addr=0x%02h; override IC_TAR to 0x%02h to avoid controller self-address restriction",
                             i2c_target_addr[6:0],
                             adjusted_tar[6:0]))
      i2c_controller_tar_addr = adjusted_tar;
    end
  endfunction

  virtual function bit [9:0] select_non_self_tar_addr(bit [9:0] target_addr);
    if (target_addr[6:0] == 7'h56) begin
      return 10'h057;
    end
    return 10'h056;
  endfunction

  virtual task body();
    wait_reset_done();
    configure_from_plusargs();
    set_i2c_speed_mode(i2c_speed_mode);

`ifdef BMS_USE_SVT_VIP
    i2c_dut_init_target();
    fork
      begin
        start_i2c_vip_master_sequence("i2c_mst_dut_slave_write_sequence");
      end
      begin
        i2c_dut_target_receive_and_check(slave_rx_expected);
        wait_target_stop("VIP master write to DUT target",
                         i2c_timeout_ic_cycles(slave_rx_expected.size() + 1));
        read_clear(SLV_IC_CLR_STOP_DET);
      end
    join
    i2c_dut_check_no_abort();
    wait_i2c_observation_window(16);

    fork
      begin
        start_i2c_vip_master_sequence("i2c_mst_dut_slave_read_sequence");
      end
      begin
        i2c_dut_target_service_read(slave_tx_payload);
        wait_target_stop("VIP master read from DUT target",
                         i2c_timeout_ic_cycles(slave_tx_payload.size() + 1));
        read_clear(SLV_IC_CLR_STOP_DET);
      end
    join
    i2c_dut_check_no_abort();
    wait_i2c_observation_window(100);
`else
    `uvm_fatal("I2C_SVT_REQUIRED", "DUT slave smoke requires BMS_USE_SVT_VIP APB/I2C VIP sequences")
`endif
  endtask

`ifdef BMS_USE_SVT_VIP
  virtual task i2c_dut_init_target();
    bit [31:0] con;

    apb_vip_write32(SLV_IC_ENABLE, 32'h0);
    poll_reg_bit(SLV_IC_ENABLE_STATUS, 0, 1'b0, 2000, "IC_ENABLE_STATUS.IC_EN disable for target mode");
    poll_reg_bit(SLV_IC_STATUS, 0, 1'b0, 2000, "IC_STATUS.ACTIVITY after disable for target mode");
    poll_reg_bit(SLV_IC_STATUS, 2, 1'b1, 2000, "IC_STATUS.TFE after disable for target mode");
    read_clear(SLV_IC_CLR_INTR);
    report_target_config("before target config", 1'b0);

    con = build_ic_con_target_value(i2c_speed_mode);
    `uvm_info("I2C_TARGET_PROGRAM",
              $sformatf("program target mode IC_CON=0x%08h MASTER_MODE=%0b SLAVE_DISABLE=0 10BIT_SLAVE=0 RESTART_EN=1 SPEED=%0d IC_SAR=0x%03h IC_TAR=0x%03h tar_from_plusarg=%0b",
                        con, con[0], con[2:1], i2c_target_addr,
                        i2c_controller_tar_addr,
                        i2c_controller_tar_from_plusarg),
              UVM_LOW)
    apb_vip_write32(SLV_IC_CON, con);
    check_reg_value(SLV_IC_CON, con, SLV_IC_TARGET_ACK_MASK, "IC_CON target ACK mode");
    `uvm_info("I2C_TARGET_ROLE",
              $sformatf("target role programming uses MASTER_MODE=%0b. For OE debug, MASTER_MODE=0 is pure target-only; use +I2C_TARGET_KEEP_MASTER=1 only for dual-role A/B comparison.",
                        i2c_target_keep_master),
              UVM_LOW)

    apb_vip_write32(SLV_IC_TAR, {22'h0, i2c_controller_tar_addr});
    check_reg_value(SLV_IC_TAR, {22'h0, i2c_controller_tar_addr}, 32'h0000_03ff, "IC_TAR non-self controller address");

    apb_vip_write32(SLV_IC_SAR, {22'h0, i2c_target_addr});
    check_reg_value(SLV_IC_SAR, {22'h0, i2c_target_addr}, 32'h0000_03ff, "IC_SAR");

    apb_vip_write32(SLV_IC_RX_TL, 32'h0);
    apb_vip_write32(SLV_IC_TX_TL, 32'h0);
    apb_vip_write32(SLV_IC_SLV_DATA_NACK_ONLY, 32'h0);
    check_reg_value(SLV_IC_SLV_DATA_NACK_ONLY, 32'h0, 32'h0000_0001,
                    "IC_SLV_DATA_NACK_ONLY");
    apb_vip_write32(SLV_IC_INTR_MASK, 32'h0);
    check_reg_value(SLV_IC_INTR_MASK, 32'h0, 32'h0001_ffff,
                    "IC_INTR_MASK target polling mode");

    confirm_target_config_programmed("after target register writes", con);

    apb_vip_write32(SLV_IC_ENABLE, SLV_IC_ENABLE_SAR_EN);
    apb_vip_write32(SLV_IC_ENABLE, SLV_IC_ENABLE_SAR_EN | SLV_IC_ENABLE_EN);
    poll_reg_bit(SLV_IC_ENABLE_STATUS, 0, 1'b1, 2000, "IC_ENABLE_STATUS.IC_EN enable for target mode");
    wait_target_external_enable();
    read_clear(SLV_IC_CLR_INTR);
    confirm_target_mode_enabled("after target enable");

    if (i2c_start_delay_cycles > 0) begin
      `uvm_info("I2C_START_DELAY",
                $sformatf("target mode waits %0d ic_clk cycles before VIP master access",
                          i2c_start_delay_cycles),
                UVM_LOW)
      wait_i2c_ic_clk_cycles(i2c_start_delay_cycles);
    end
    wait_target_bus_stable_before_vip_master();
  endtask

  virtual function bit [31:0] build_ic_con_target_value(string mode);
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

    return {31'h0, i2c_target_keep_master} | ({30'h0, speed} << 1) |
           (32'h1 << 5);
  endfunction

  virtual task wait_target_external_enable();
    bit done;

    repeat (2000) begin
      if (vif.ic_en === 1'b1) begin
        done = 1'b1;
        break;
      end
      repeat (2) @(posedge vif.ic_clk);
    end

    if (!done) begin
      report_target_config("ic_en timeout");
      `uvm_fatal("I2C_TARGET_IC_EN",
                 $sformatf("DUT ic_en did not assert after IC_ENABLE_STATUS.IC_EN=1, ic_en=%b", vif.ic_en))
    end

    `uvm_info("I2C_TARGET_IC_EN",
              $sformatf("DUT ic_en asserted, ic_en=%b ic_clk_in_a=%b ic_data_in_a=%b ic_clk_oe=%b ic_data_oe=%b",
                        vif.ic_en, vif.ic_clk_in_a, vif.ic_data_in_a,
                        vif.ic_clk_oe, vif.ic_data_oe),
              UVM_LOW)
  endtask

  virtual task wait_i2c_ic_clk_cycles(int unsigned cycles);
    repeat (cycles) @(posedge vif.ic_clk);
  endtask

  virtual task wait_target_bus_stable_before_vip_master();
    bit [31:0] intr_stat;
    bit [31:0] intr_mask;
    bit [31:0] status;
    bit [31:0] raw_intr;
    int unsigned stable_cycles;

    stable_cycles = scl_period_ic_clk_cycles(i2c_speed_mode);
    if (stable_cycles < 200) begin
      stable_cycles = 200;
    end

    apb_vip_read32(SLV_IC_INTR_STAT, intr_stat);
    apb_vip_read32(SLV_IC_INTR_MASK, intr_mask);
    apb_vip_read32(SLV_IC_STATUS, status);
    apb_vip_read32(SLV_IC_RAW_INTR_STAT, raw_intr);
    `uvm_info("I2C_TARGET_PRE_ACCESS",
              $sformatf("before extra target settle wait intr_stat=0x%08h intr_mask=0x%08h status=0x%08h raw_intr=0x%08h scl=%b sda=%b ic_en=%b ic_intr=%b ic_clk_oe=%b ic_data_oe=%b settle_ic_clk_cycles=%0d",
                        intr_stat, intr_mask, status, raw_intr,
                        vif.ic_clk_in_a, vif.ic_data_in_a, vif.ic_en,
                        vif.ic_intr, vif.ic_clk_oe, vif.ic_data_oe,
                        stable_cycles),
              UVM_LOW)
    wait_i2c_ic_clk_cycles(stable_cycles);
    apb_vip_read32(SLV_IC_INTR_STAT, intr_stat);
    apb_vip_read32(SLV_IC_INTR_MASK, intr_mask);
    apb_vip_read32(SLV_IC_STATUS, status);
    apb_vip_read32(SLV_IC_RAW_INTR_STAT, raw_intr);
    `uvm_info("I2C_TARGET_PRE_ACCESS",
              $sformatf("after extra target settle wait intr_stat=0x%08h intr_mask=0x%08h status=0x%08h raw_intr=0x%08h scl=%b sda=%b ic_en=%b ic_intr=%b ic_clk_oe=%b ic_data_oe=%b",
                        intr_stat, intr_mask, status, raw_intr,
                        vif.ic_clk_in_a, vif.ic_data_in_a, vif.ic_en,
                        vif.ic_intr, vif.ic_clk_oe, vif.ic_data_oe),
              UVM_LOW)
  endtask

  virtual task report_target_config(string tag, bit strict_target_expectation = 1'b1);
    bit [31:0] con;
    bit [31:0] tar;
    bit [31:0] sar;
    bit [31:0] enable;
    bit [31:0] enable_status;
    bit [31:0] intr_stat;
    bit [31:0] intr_mask;
    bit [31:0] status;
    bit [31:0] raw_intr;
    bit [31:0] txflr;
    bit [31:0] rxflr;
    bit [31:0] slv_data_nack_only;
    bit [31:0] comp_param_1;

    apb_vip_read32(SLV_IC_CON, con);
    apb_vip_read32(SLV_IC_TAR, tar);
    apb_vip_read32(SLV_IC_SAR, sar);
    apb_vip_read32(SLV_IC_ENABLE, enable);
    apb_vip_read32(SLV_IC_ENABLE_STATUS, enable_status);
    apb_vip_read32(SLV_IC_INTR_STAT, intr_stat);
    apb_vip_read32(SLV_IC_INTR_MASK, intr_mask);
    apb_vip_read32(SLV_IC_STATUS, status);
    apb_vip_read32(SLV_IC_RAW_INTR_STAT, raw_intr);
    apb_vip_read32(SLV_IC_TXFLR, txflr);
    apb_vip_read32(SLV_IC_RXFLR, rxflr);
    apb_vip_read32(SLV_IC_SLV_DATA_NACK_ONLY, slv_data_nack_only);
    apb_vip_read32(SLV_IC_COMP_PARAM_1, comp_param_1);

    `uvm_info("I2C_TARGET_CFG",
              $sformatf("%s IC_CON=0x%08h MASTER_MODE=%0b SLAVE_DISABLE=%0b 10BIT_SLAVE=%0b IC_TAR=0x%03h IC_SAR=0x%03h TAR_EQ_SAR7=%0b IC_ENABLE=0x%08h IC_ENABLE_STATUS=0x%08h IC_INTR_STAT=0x%08h IC_INTR_MASK=0x%08h IC_STATUS=0x%08h RAW_INTR=0x%08h TXFLR=0x%08h RXFLR=0x%08h IC_SLV_DATA_NACK_ONLY=0x%08h IC_COMP_PARAM_1=0x%08h target_addr=0x%03h controller_tar=0x%03h vif_ic_en=%b ic_intr=%b sda_in=%b scl_in=%b sda_oe=%b scl_oe=%b",
                        tag, con, con[0], con[6], con[3], tar[9:0], sar[9:0],
                        (tar[6:0] == sar[6:0]),
                        enable, enable_status, intr_stat, intr_mask, status,
                        raw_intr, txflr, rxflr, slv_data_nack_only,
                        comp_param_1, i2c_target_addr,
                        i2c_controller_tar_addr, vif.ic_en, vif.ic_intr,
                        vif.ic_data_in_a, vif.ic_clk_in_a, vif.ic_data_oe,
                        vif.ic_clk_oe),
              UVM_LOW)
    report_target_activity(tag, status, raw_intr, UVM_LOW);

    if (!strict_target_expectation) begin
      return;
    end

    if (con[0] !== i2c_target_keep_master) begin
      `uvm_error("I2C_TARGET_CFG",
                 $sformatf("DUT target mode expects IC_CON.MASTER_MODE=%0b, actual IC_CON=0x%08h",
                           i2c_target_keep_master, con))
    end
    if (con[6] !== 1'b0) begin
      `uvm_error("I2C_TARGET_CFG",
                 $sformatf("DUT target mode expects IC_CON.IC_SLAVE_DISABLE=0, actual IC_CON=0x%08h", con))
    end
    if (sar[9:0] !== i2c_target_addr) begin
      `uvm_error("I2C_TARGET_CFG",
                 $sformatf("IC_SAR mismatch expected=0x%03h actual=0x%03h raw=0x%08h",
                           i2c_target_addr, sar[9:0], sar))
    end
    if (enable_status[0] !== 1'b1) begin
      `uvm_error("I2C_TARGET_CFG",
                 $sformatf("IC_ENABLE_STATUS.IC_EN is not set after target enable, raw=0x%08h", enable_status))
    end
  endtask

  virtual task confirm_target_config_programmed(string tag, bit [31:0] exp_con);
    bit [31:0] con;
    bit [31:0] tar;
    bit [31:0] sar;
    bit [31:0] enable;
    bit [31:0] enable_status;
    string fail_reasons;

    apb_vip_read32(SLV_IC_CON, con);
    apb_vip_read32(SLV_IC_TAR, tar);
    apb_vip_read32(SLV_IC_SAR, sar);
    apb_vip_read32(SLV_IC_ENABLE, enable);
    apb_vip_read32(SLV_IC_ENABLE_STATUS, enable_status);

    if ((con & SLV_IC_TARGET_ACK_MASK) !== (exp_con & SLV_IC_TARGET_ACK_MASK)) begin
      fail_reasons = {fail_reasons,
                      $sformatf(" IC_CON target-ACK masked mismatch exp=0x%02h actual=0x%02h mask=0x%02h;",
                                exp_con[6:0], con[6:0],
                                SLV_IC_TARGET_ACK_MASK[6:0])};
    end
    if ((con & 32'h0000_007f) !== (exp_con & 32'h0000_007f)) begin
      `uvm_warning("I2C_TARGET_CFG_PARTIAL",
                   $sformatf("%s: IC_CON[6:0] differs from requested value, requested=0x%02h actual=0x%02h. This is only fatal if target ACK bits masked by 0x%02h mismatch.",
                             tag, exp_con[6:0], con[6:0],
                             SLV_IC_TARGET_ACK_MASK[6:0]))
    end
    if (con[0] !== i2c_target_keep_master) begin
      fail_reasons = {fail_reasons,
                      $sformatf(" IC_CON.MASTER_MODE(bit0) is %0b, expected %0b;",
                                con[0], i2c_target_keep_master)};
    end
    if (con[6] !== 1'b0) begin
      fail_reasons = {fail_reasons, " IC_CON.IC_SLAVE_DISABLE(bit6) did not clear;"};
    end
    if (con[3] !== 1'b0) begin
      fail_reasons = {fail_reasons, " IC_CON.IC_10BITADDR_SLAVE(bit3) did not clear for 7-bit target;"};
    end
    if (sar[9:0] !== i2c_target_addr) begin
      fail_reasons = {fail_reasons,
                      $sformatf(" IC_SAR[9:0]=0x%03h does not match target_addr=0x%03h;",
                                sar[9:0], i2c_target_addr)};
    end
    if (tar[9:0] !== i2c_controller_tar_addr) begin
      fail_reasons = {fail_reasons,
                      $sformatf(" IC_TAR[9:0]=0x%03h does not match controller_tar=0x%03h;",
                                tar[9:0], i2c_controller_tar_addr)};
    end
    if (i2c_target_keep_master && (tar[6:0] == sar[6:0])) begin
      fail_reasons = {fail_reasons, " IC_TAR[6:0] equals IC_SAR[6:0] while MASTER_MODE is kept on;"};
    end
    if (enable[0] !== 1'b0) begin
      fail_reasons = {fail_reasons, " IC_ENABLE.ENABLE(bit0) is not 0 during target config writeback check;"};
    end
    if (enable_status[0] !== 1'b0) begin
      fail_reasons = {fail_reasons, " IC_ENABLE_STATUS.IC_EN(bit0) is not 0 during target config writeback check;"};
    end

    if (fail_reasons != "") begin
      report_target_config(tag, 1'b0);
      `uvm_fatal("I2C_TARGET_CFG_WRITE_FAIL",
                 $sformatf("%s: DUT did not accept slave/target register programming:%s IC_CON=0x%08h exp_con=0x%08h IC_TAR=0x%08h IC_SAR=0x%08h IC_ENABLE=0x%08h IC_ENABLE_STATUS=0x%08h",
                           tag, fail_reasons, con, exp_con, tar, sar, enable,
                           enable_status))
    end

    `uvm_info("I2C_TARGET_CFG_WRITTEN",
              $sformatf("%s: DUT accepted target config while disabled, IC_CON=0x%08h IC_TAR=0x%08h IC_SAR=0x%08h target_addr=0x%03h controller_tar=0x%03h IC_ENABLE=0x%08h IC_ENABLE_STATUS=0x%08h",
                        tag, con, tar, sar, i2c_target_addr,
                        i2c_controller_tar_addr, enable,
                        enable_status),
              UVM_LOW)
  endtask

  virtual task confirm_target_mode_enabled(string tag);
    bit [31:0] con;
    bit [31:0] tar;
    bit [31:0] sar;
    bit [31:0] enable;
    bit [31:0] enable_status;
    string fail_reasons;

    report_target_config(tag);

    apb_vip_read32(SLV_IC_CON, con);
    apb_vip_read32(SLV_IC_TAR, tar);
    apb_vip_read32(SLV_IC_SAR, sar);
    apb_vip_read32(SLV_IC_ENABLE, enable);
    apb_vip_read32(SLV_IC_ENABLE_STATUS, enable_status);

    if (con[0] !== i2c_target_keep_master) begin
      fail_reasons = {fail_reasons,
                      $sformatf(" IC_CON.MASTER_MODE(bit0) is %0b, expected %0b;",
                                con[0], i2c_target_keep_master)};
    end
    if (con[6] !== 1'b0) begin
      fail_reasons = {fail_reasons, " IC_CON.IC_SLAVE_DISABLE(bit6) is not 0;"};
    end
    if (con[3] !== 1'b0) begin
      fail_reasons = {fail_reasons, " IC_CON.IC_10BITADDR_SLAVE(bit3) is not 0 for current 7-bit VIP access;"};
    end
    if (sar[9:0] !== i2c_target_addr) begin
      fail_reasons = {fail_reasons,
                      $sformatf(" IC_SAR[9:0]=0x%03h does not match target_addr=0x%03h;",
                                sar[9:0], i2c_target_addr)};
    end
    if (tar[9:0] !== i2c_controller_tar_addr) begin
      fail_reasons = {fail_reasons,
                      $sformatf(" IC_TAR[9:0]=0x%03h does not match controller_tar=0x%03h;",
                                tar[9:0], i2c_controller_tar_addr)};
    end
    if (i2c_target_keep_master && (tar[6:0] == sar[6:0])) begin
      fail_reasons = {fail_reasons, " IC_TAR[6:0] equals IC_SAR[6:0] while MASTER_MODE is kept on;"};
    end
    if (enable[0] !== 1'b1) begin
      fail_reasons = {fail_reasons, " IC_ENABLE.ENABLE(bit0) is not 1;"};
    end
    if (enable_status[0] !== 1'b1) begin
      fail_reasons = {fail_reasons, " IC_ENABLE_STATUS.IC_EN(bit0) is not 1;"};
    end
    if (vif.ic_en !== 1'b1) begin
      fail_reasons = {fail_reasons, " DUT top-level ic_en is not 1;"};
    end

    if (fail_reasons != "") begin
      `uvm_fatal("I2C_TARGET_MODE_OFF",
                 $sformatf("%s: DUT target/slave mode is not enabled:%s IC_CON=0x%08h IC_TAR=0x%08h IC_SAR=0x%08h IC_ENABLE=0x%08h IC_ENABLE_STATUS=0x%08h vif.ic_en=%b",
                           tag, fail_reasons, con, tar, sar, enable,
                           enable_status, vif.ic_en))
    end

    `uvm_info("I2C_TARGET_MODE_ON",
              $sformatf("%s: DUT target/slave mode confirmed, keep_master=%0b 7-bit addr=0x%02h controller_tar=0x%02h IC_CON=0x%08h IC_TAR=0x%08h IC_SAR=0x%08h IC_ENABLE=0x%08h IC_ENABLE_STATUS=0x%08h",
                        tag, i2c_target_keep_master, i2c_target_addr[6:0],
                        i2c_controller_tar_addr[6:0], con, tar, sar, enable,
                        enable_status),
              UVM_LOW)

    if (enable[19] !== 1'b1) begin
      `uvm_warning("I2C_TARGET_SAR_EN",
                   $sformatf("%s: IC_ENABLE[19]=%0b. This only matters when IC_MULTI_SAR_EN==1; if multi-SAR is enabled and this bit stays 0, IC_SAR will not ACK.",
                             tag, enable[19]))
    end
  endtask

  virtual task i2c_dut_target_receive_and_check(input byte unsigned exp_q[$]);
    foreach (exp_q[i]) begin
      bit [31:0] actual;

      wait_target_rx_data_or_intr(i2c_timeout_ic_cycles(exp_q.size() + 1),
                                  $sformatf("target RX byte[%0d] before reading IC_DATA_CMD", i));
      apb_vip_read32(SLV_IC_DATA_CMD, actual);
      if (actual[7:0] !== exp_q[i]) begin
        `uvm_error("I2C_TARGET_RX_MISMATCH",
                   $sformatf("target RX[%0d] expected=0x%02h actual=0x%02h raw=0x%08h",
                             i, exp_q[i], actual[7:0], actual))
      end else begin
        `uvm_info("I2C_TARGET_RX_CHECK",
                  $sformatf("target RX[%0d] matched 0x%02h raw=0x%08h",
                            i, actual[7:0], actual),
                  UVM_LOW)
      end
    end
  endtask

  virtual task wait_target_rx_data_or_intr(int unsigned max_ic_clk_cycles, string what);
    bit [31:0] status;
    bit [31:0] raw_intr;
    bit [31:0] prev_status;
    bit [31:0] prev_raw_intr;
    bit have_prev;
    int unsigned elapsed_ic_clk_cycles;
    int unsigned poll_gap_ic_clk_cycles;
    int unsigned polls;

    poll_gap_ic_clk_cycles = scl_period_ic_clk_cycles(i2c_speed_mode) / 4;
    if (poll_gap_ic_clk_cycles < 16) begin
      poll_gap_ic_clk_cycles = 16;
    end

    while (elapsed_ic_clk_cycles <= max_ic_clk_cycles) begin
      apb_vip_read32(SLV_IC_STATUS, status);
      apb_vip_read32(SLV_IC_RAW_INTR_STAT, raw_intr);
      polls++;

      if (!have_prev || ((status & 32'h0000_0049) != (prev_status & 32'h0000_0049)) ||
          ((raw_intr & 32'h0001_8664) != (prev_raw_intr & 32'h0001_8664))) begin
        `uvm_info("I2C_TARGET_RX_POLL",
                  $sformatf("%s poll=%0d elapsed_ic_clk=%0d status=0x%08h raw_intr=0x%08h",
                            what, polls, elapsed_ic_clk_cycles, status, raw_intr),
                  UVM_LOW)
        report_target_activity("RX poll state", status, raw_intr, UVM_LOW);
        prev_status = status;
        prev_raw_intr = raw_intr;
        have_prev = 1'b1;
      end

      if (status[3] === 1'b1) begin
        `uvm_info("I2C_TARGET_RX_READY",
                  $sformatf("%s: RFNE=1 after %0d polls, status=0x%08h raw_intr=0x%08h",
                            what, polls, status, raw_intr),
                  UVM_LOW)
        return;
      end

      if (raw_intr[10]) begin
        `uvm_info("I2C_TARGET_START_SEEN",
                  $sformatf("%s: START_DET observed while waiting RX, status=0x%08h raw_intr=0x%08h",
                            what, status, raw_intr),
                  UVM_DEBUG)
      end

      if (raw_intr[9]) begin
        report_target_activity("STOP before RX data activity", status, raw_intr, UVM_LOW);
        report_target_config("STOP before RX data");
        read_clear(SLV_IC_CLR_STOP_DET);
        if (raw_intr[10]) begin
          read_clear(SLV_IC_CLR_START_DET);
        end
        `uvm_fatal("I2C_STOP_NO_RX",
                   $sformatf("%s: STOP_DET before RX FIFO non-empty, status=0x%08h raw_intr=0x%08h. VIP may have seen ACK from TB pad bridge, but DUT did not push target write data into RX FIFO. Check true DUT slave ACK/OE path, IC_ENABLE[19]/multi-SAR support, and data-byte sampling at ic_data_in_a.",
                             what, status, raw_intr))
      end

      repeat (poll_gap_ic_clk_cycles) @(posedge vif.ic_clk);
      elapsed_ic_clk_cycles += poll_gap_ic_clk_cycles;
    end

    report_target_config("RX wait timeout");
    `uvm_fatal("I2C_TARGET_RX_TIMEOUT",
               $sformatf("%s did not receive RX data after %0d polls, %0d/%0d ic_clk cycles",
                         what, polls, elapsed_ic_clk_cycles, max_ic_clk_cycles))
  endtask

  virtual task i2c_dut_target_service_read(input byte unsigned data_q[$]);
    bit [31:0] raw_intr;
    bit [31:0] status;

    poll_reg_bit_i2c_time(SLV_IC_RAW_INTR_STAT, 5, 1'b1,
                          i2c_timeout_ic_cycles(data_q.size() + 1),
                          "IC_RAW_INTR_STAT.RD_REQ for target transmit");
    apb_vip_read32(SLV_IC_RAW_INTR_STAT, raw_intr);
    apb_vip_read32(SLV_IC_STATUS, status);
    report_target_activity("target transmit RD_REQ", status, raw_intr, UVM_LOW);
    `uvm_info("I2C_TARGET_RD_REQ",
              $sformatf("servicing RD_REQ raw_intr=0x%08h tx_bytes=%0d",
                        raw_intr, data_q.size()),
              UVM_LOW)

    foreach (data_q[i]) begin
      poll_reg_bit(SLV_IC_STATUS, 1, 1'b1, 2000, "IC_STATUS.TFNF before target TX data");
      apb_vip_write32(SLV_IC_DATA_CMD, {24'h0, data_q[i]});
      `uvm_info("I2C_TARGET_TX_DATA",
                $sformatf("target TX[%0d] <= 0x%02h", i, data_q[i]),
                UVM_LOW)
    end
    read_clear(SLV_IC_CLR_RD_REQ);
  endtask

  virtual task wait_target_stop(string tag, int unsigned max_ic_clk_cycles);
    bit [31:0] raw_intr;
    bit [31:0] status;
    bit [31:0] prev_status;
    bit [31:0] prev_raw_intr;
    bit have_prev;
    int unsigned elapsed_ic_clk_cycles;
    int unsigned poll_gap_ic_clk_cycles;
    int unsigned polls;

    poll_gap_ic_clk_cycles = scl_period_ic_clk_cycles(i2c_speed_mode) / 2;
    if (poll_gap_ic_clk_cycles < 16) begin
      poll_gap_ic_clk_cycles = 16;
    end

    while (elapsed_ic_clk_cycles <= max_ic_clk_cycles) begin
      apb_vip_read32(SLV_IC_RAW_INTR_STAT, raw_intr);
      apb_vip_read32(SLV_IC_STATUS, status);
      polls++;

      if (!have_prev || ((status & 32'h0000_0049) != (prev_status & 32'h0000_0049)) ||
          ((raw_intr & 32'h0001_8664) != (prev_raw_intr & 32'h0001_8664))) begin
        `uvm_info("I2C_TARGET_STOP_POLL",
                  $sformatf("%s poll=%0d elapsed_ic_clk=%0d status=0x%08h raw_intr=0x%08h",
                            tag, polls, elapsed_ic_clk_cycles, status, raw_intr),
                  UVM_LOW)
        report_target_activity("STOP poll state", status, raw_intr, UVM_LOW);
        prev_status = status;
        prev_raw_intr = raw_intr;
        have_prev = 1'b1;
      end

      if (raw_intr[6]) begin
        report_and_clear_abort(tag);
        `uvm_fatal("I2C_TARGET_TX_ABRT",
                   $sformatf("%s saw TX_ABRT while waiting STOP, status=0x%08h raw_intr=0x%08h",
                             tag, status, raw_intr))
      end

      if (raw_intr[9]) begin
        `uvm_info("I2C_TARGET_STOP",
                  $sformatf("%s observed STOP after %0d polls, %0d ic_clk cycles, status=0x%08h raw_intr=0x%08h",
                            tag, polls, elapsed_ic_clk_cycles, status, raw_intr),
                  UVM_LOW)
        return;
      end

      repeat (poll_gap_ic_clk_cycles) @(posedge vif.ic_clk);
      elapsed_ic_clk_cycles += poll_gap_ic_clk_cycles;
    end

    apb_vip_read32(SLV_IC_RAW_INTR_STAT, raw_intr);
    apb_vip_read32(SLV_IC_STATUS, status);
    `uvm_fatal("I2C_TARGET_STOP_TIMEOUT",
               $sformatf("%s did not observe STOP after %0d polls, %0d/%0d ic_clk cycles, status=0x%08h raw_intr=0x%08h",
                         tag, polls, elapsed_ic_clk_cycles, max_ic_clk_cycles,
                         status, raw_intr))
  endtask

  virtual function void report_target_activity(string tag,
                                               bit [31:0] status,
                                               bit [31:0] raw_intr,
                                               uvm_verbosity verbosity = UVM_LOW);
    `uvm_info("I2C_TARGET_ACTIVITY",
              $sformatf("%s STATUS.ACTIVITY=%0b MST_ACTIVITY=%0b SLV_ACTIVITY=%0b RFNE=%0b TFE=%0b TFNF=%0b RAW.SLV_ADDR1_TAG=%0b WR_REQ=%0b START_DET=%0b STOP_DET=%0b RX_DONE=%0b TX_ABRT=%0b RD_REQ=%0b RX_FULL=%0b ic_intr=%b sda_oe=%b scl_oe=%b",
                        tag, status[0], status[5], status[6], status[3],
                        status[2], status[1], raw_intr[16], raw_intr[15],
                        raw_intr[10], raw_intr[9], raw_intr[7], raw_intr[6],
                        raw_intr[5], raw_intr[2], vif.ic_intr,
                        vif.ic_data_oe, vif.ic_clk_oe),
              verbosity)
  endfunction
`endif
endclass
