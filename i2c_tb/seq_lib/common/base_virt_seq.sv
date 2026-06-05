class base_virt_seq extends uvm_sequence;
  `uvm_object_utils(base_virt_seq)

  virtual i2c_if vif;
  i2c_env env;
`ifdef BMS_USE_SVT_VIP
  uvm_sequencer_base apb_vip_sqr_m0;
  uvm_sequencer_base ahb_vip_sqr_m0;
  uvm_sequencer_base axi_vip_sqr_m0;
  uvm_sequencer_base i2c_vip_slv_sqr0;
  uvm_sequencer_base i2c_vip_mst_sqr0;
  svt_apb_system_sequencer apb_vip_sqr;
  svt_ahb_system_sequencer ahb_vip_sqr;
  svt_axi_system_sequencer axi_vip_sqr;
`endif

  function new(string name = "base_virt_seq");
    super.new(name);
  endfunction

  task pre_body();
    if (vif == null) begin
      `uvm_fatal("NOVIF", "base_virt_seq requires vif")
    end
    if (env == null) begin
      `uvm_fatal("NOENV", "base_virt_seq requires env")
    end
  endtask

  task wait_reset_done();
    wait (vif.rst_n === 1'b1);
    wait (vif.presetn === 1'b1);
    wait (vif.ic_rst_n === 1'b1);
    repeat (2) @(posedge vif.clk);
  endtask

  task wait_i2c_observation_window(int unsigned cycles);
    repeat (cycles) @(posedge vif.clk);
  endtask

  task set_i2c_speed_mode(string mode);
    int unsigned pclk_half_ns;
    int unsigned ic_clk_half_ns;

    pclk_half_ns = 5;
    if (mode == "standard") begin
      ic_clk_half_ns = 50;
    end else if ((mode == "fast") || (mode == "fast_plus")) begin
      ic_clk_half_ns = 10;
    end else if (mode == "high") begin
      ic_clk_half_ns = 2;
    end else begin
      `uvm_warning("I2C_SPEED_MODE", $sformatf("Unknown I2C_SPEED_MODE=%s; use standard timing", mode))
      ic_clk_half_ns = 50;
    end

    vif.pclk_half_period_ns = pclk_half_ns;
    vif.ic_clk_half_period_ns = ic_clk_half_ns;
    `uvm_info("I2C_SPEED_MODE", $sformatf("mode=%s pclk_half=%0dns ic_clk_half=%0dns", mode, pclk_half_ns, ic_clk_half_ns), UVM_LOW)
  endtask

`ifdef BMS_USE_SVT_VIP
  task apb_vip_write32(bit [31:0] addr, bit [31:0] data);
    apb_master_directed_write_sequence seq;
    uvm_sequencer_base target_sqr;

    target_sqr = apb_vip_sqr_m0;
    if ((target_sqr == null) && (apb_vip_sqr != null)) begin
      target_sqr = apb_vip_sqr.master_sequencer;
    end
    if (target_sqr == null) begin
      `uvm_fatal("APB_VIP_SQR_NULL", "apb_vip_sqr_m0 is null; cannot access DUT registers")
    end
    seq = apb_master_directed_write_sequence::type_id::create("apb_vip_write32_seq");
    seq.apb_w_addr = addr;
    seq.apb_w_data = data;
    seq.start(target_sqr);
  endtask

  task apb_vip_read32(bit [31:0] addr, output bit [31:0] data);
    apb_master_directed_read_sequence seq;
    uvm_sequencer_base target_sqr;

    target_sqr = apb_vip_sqr_m0;
    if ((target_sqr == null) && (apb_vip_sqr != null)) begin
      target_sqr = apb_vip_sqr.master_sequencer;
    end
    if (target_sqr == null) begin
      `uvm_fatal("APB_VIP_SQR_NULL", "apb_vip_sqr_m0 is null; cannot access DUT registers")
    end
    seq = apb_master_directed_read_sequence::type_id::create("apb_vip_read32_seq");
    seq.apb_r_addr = addr;
    seq.start(target_sqr);
    data = seq.apb_r_data;
  endtask
`endif

  task start_i2c_vip_slave_sequence(string seq_name);
`ifdef BMS_USE_SVT_VIP
    uvm_object seq_obj;
    uvm_sequence_base seq_base;
    if (i2c_vip_slv_sqr0 == null) begin
      `uvm_fatal("I2C_VIP_SQR_NULL", "i2c_vip_slv_sqr0 is null; cannot start I2C VIP slave sequence")
    end
    seq_obj = uvm_factory::get().create_object_by_name(seq_name, get_full_name(), "i2c_vip_slave_seq");
    if (seq_obj == null) begin
      `uvm_fatal("I2C_VIP_SEQ_NF", $sformatf("Cannot create I2C VIP sequence: %s", seq_name))
    end
    if (!$cast(seq_base, seq_obj)) begin
      `uvm_fatal("I2C_VIP_SEQ_BAD", $sformatf("Not a uvm_sequence: %s", seq_name))
    end
    seq_base.start(i2c_vip_slv_sqr0);
`else
    `uvm_info("I2C_VIP_DISABLED", $sformatf("Skip I2C VIP sequence %s because BMS_USE_SVT_VIP is off", seq_name), UVM_LOW)
`endif
  endtask

  task start_i2c_vip_master_sequence(string seq_name);
`ifdef BMS_USE_SVT_VIP
    uvm_object seq_obj;
    uvm_sequence_base seq_base;
    if (i2c_vip_mst_sqr0 == null) begin
      `uvm_fatal("I2C_VIP_SQR_NULL", "i2c_vip_mst_sqr0 is null; cannot start I2C VIP master sequence")
    end
    seq_obj = uvm_factory::get().create_object_by_name(seq_name, get_full_name(), "i2c_vip_master_seq");
    if (seq_obj == null) begin
      `uvm_fatal("I2C_VIP_SEQ_NF", $sformatf("Cannot create I2C VIP sequence: %s", seq_name))
    end
    if (!$cast(seq_base, seq_obj)) begin
      `uvm_fatal("I2C_VIP_SEQ_BAD", $sformatf("Not a uvm_sequence: %s", seq_name))
    end
    seq_base.start(i2c_vip_mst_sqr0);
`else
    `uvm_info("I2C_VIP_DISABLED", $sformatf("Skip I2C VIP sequence %s because BMS_USE_SVT_VIP is off", seq_name), UVM_LOW)
`endif
  endtask
endclass
