class i2c_base_test extends uvm_test;
  `uvm_component_utils(i2c_base_test)

  virtual i2c_if vif;
  i2c_env m_env;

`ifdef BMS_USE_SVT_VIP
  ahb_ral_env ahb_env;
  apb_basic_env apb_env;
  axi_basic_env axi_env;

  svt_mem slave_mem_0;

  apb_shared_cfg apb_cfg;
  cust_svt_axi_system_configuration axi_cfg;
  cust_svt_ahb_system_configuration ahb_cfg;
  cust_svt_i2c_system_configuration i2c_vip_cfg;

  uvm_sequencer_base apb_vip_sqr_m0;
  uvm_sequencer_base ahb_vip_sqr_m0;
  uvm_sequencer_base axi_vip_sqr_m0;
  uvm_sequencer_base i2c_vip_slv_sqr0;
  uvm_sequencer_base i2c_vip_mst_sqr0;

  i2c_vip_basic_env i2c_vip_env;
`endif

  function new(string name = "i2c_base_test", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
`ifdef BMS_USE_SVT_VIP
    int i2c_plusarg_value;
    string i2c_speed_mode;
    string i2c_slave_type;
    string i2c_dut_mode;
`endif
    super.build_phase(phase);
    if (!uvm_config_db#(virtual i2c_if)::get(this, "", "vif", vif)) begin
      `uvm_fatal("NOVIF", "virtual interface i2c_if is not set")
    end
    uvm_config_db#(virtual i2c_if)::set(this, "m_env*", "vif", vif);
    m_env = i2c_env::type_id::create("m_env", this);

`ifdef BMS_USE_SVT_VIP
    set_type_override_by_type(svt_apb_master_transaction::get_type(),
                              cust_svt_apb_master_transaction::get_type());
    set_type_override_by_type(svt_i2c_slave_transaction::get_type(),
                              cust_svt_i2c_slave_transaction::get_type());

    apb_cfg = apb_shared_cfg::type_id::create("apb_cfg", this);
    axi_cfg = cust_svt_axi_system_configuration::type_id::create("axi_cfg", this);
    ahb_cfg = cust_svt_ahb_system_configuration::type_id::create("ahb_cfg", this);
    i2c_vip_cfg = cust_svt_i2c_system_configuration::type_id::create("i2c_vip_cfg", this);
    if ($value$plusargs("I2C_TARGET_ADDR=%h", i2c_plusarg_value)) begin
      i2c_vip_cfg.slave_cfg[0].slave_address = i2c_plusarg_value[9:0];
    end
    if (!$value$plusargs("I2C_DUT_MODE=%s", i2c_dut_mode)) begin
      i2c_dut_mode = "master";
    end
    if (!$value$plusargs("I2C_SLAVE_TYPE=%s", i2c_slave_type)) begin
      i2c_slave_type = "generic";
    end
    if (i2c_slave_type == "generic") begin
      i2c_vip_cfg.slave_cfg[0].slave_type = `SVT_I2C_GENERIC;
      i2c_vip_cfg.slave_cfg[0].enable_cci_8bit = 0;
      i2c_vip_cfg.slave_cfg[0].enable_eeprom_32bit = 0;
    end else if (i2c_slave_type == "eeprom") begin
      i2c_vip_cfg.slave_cfg[0].slave_type = `SVT_I2C_EEPROM;
      i2c_vip_cfg.slave_cfg[0].enable_cci_8bit = 1;
      i2c_vip_cfg.slave_cfg[0].enable_eeprom_32bit = 0;
    end else begin
      `uvm_warning("I2C_SLAVE_TYPE", $sformatf("Unknown I2C_SLAVE_TYPE=%s; use GENERIC slave like SVT basic examples", i2c_slave_type))
      i2c_vip_cfg.slave_cfg[0].slave_type = `SVT_I2C_GENERIC;
      i2c_vip_cfg.slave_cfg[0].enable_cci_8bit = 0;
      i2c_vip_cfg.slave_cfg[0].enable_eeprom_32bit = 0;
    end
    if (!$value$plusargs("I2C_SPEED_MODE=%s", i2c_speed_mode)) begin
      i2c_speed_mode = "standard";
    end
    if (i2c_speed_mode == "standard") begin
      i2c_vip_cfg.set_bus_speed(STANDARD_MODE);
    end else if (i2c_speed_mode == "fast") begin
      i2c_vip_cfg.set_bus_speed(FAST_MODE);
    end else if (i2c_speed_mode == "fast_plus") begin
      i2c_vip_cfg.set_bus_speed(FAST_MODE_PLUS);
    end else if (i2c_speed_mode == "high") begin
      i2c_vip_cfg.set_bus_speed(HIGHSPEED_MODE);
    end else begin
      `uvm_warning("I2C_SPEED_MODE", $sformatf("Unknown I2C_SPEED_MODE=%s; use STANDARD_MODE for I2C VIP", i2c_speed_mode))
      i2c_vip_cfg.set_bus_speed(STANDARD_MODE);
    end
    if (i2c_dut_mode == "slave") begin
      i2c_vip_cfg.master_cfg[0].is_active = 1;
      i2c_vip_cfg.master_cfg[0].enable_put_response = 1;
      i2c_vip_cfg.slave_cfg[0].is_active = 0;
      i2c_vip_cfg.slave_cfg[0].enable_put_response = 0;
    end else begin
      i2c_vip_cfg.master_cfg[0].is_active = 0;
      i2c_vip_cfg.master_cfg[0].enable_put_response = 0;
      i2c_vip_cfg.slave_cfg[0].is_active = 1;
    end
    `uvm_info("I2C_VIP_CFG",
              $sformatf("dut_mode=%s master_active=%0d slave_active=%0d slave_addr=0x%03h speed_mode=%s slave_type=%s type_value=%0d enable_cci_8bit=%0d enable_eeprom_32bit=%0d",
                        i2c_dut_mode, i2c_vip_cfg.master_cfg[0].is_active,
                        i2c_vip_cfg.slave_cfg[0].is_active,
                        i2c_vip_cfg.slave_cfg[0].slave_address, i2c_speed_mode,
                        i2c_slave_type, i2c_vip_cfg.slave_cfg[0].slave_type,
                        i2c_vip_cfg.slave_cfg[0].enable_cci_8bit,
                        i2c_vip_cfg.slave_cfg[0].enable_eeprom_32bit),
              UVM_LOW)

    uvm_config_db#(apb_shared_cfg)::set(this, "apb_env", "cfg", apb_cfg);
    uvm_config_db#(cust_svt_axi_system_configuration)::set(this, "axi_env", "cfg", axi_cfg);
    uvm_config_db#(cust_svt_ahb_system_configuration)::set(this, "ahb_env", "cfg", ahb_cfg);
    uvm_config_db#(cust_svt_i2c_system_configuration)::set(this, "i2c_vip_env", "i2c_system_cfg", i2c_vip_cfg);

    apb_env = apb_basic_env::type_id::create("apb_env", this);
    ahb_env = ahb_ral_env::type_id::create("ahb_env", this);
    axi_env = axi_basic_env::type_id::create("axi_env", this);
    i2c_vip_env = i2c_vip_basic_env::type_id::create("i2c_vip_env", this);

    slave_mem_0 = new("slave_mem_0", "AMBA4", 512, 0, 40'h0000_0000, 48'hffff_ffff_ffff);
    svt_config_object_db#(svt_mem)::set(this, "axi_env.axi_system_env.slave[0]", "axi_slave_mem", slave_mem_0);

    void'(uvm_config_db#(uvm_sequencer_base)::get(this, "", "apb_vip_sqr_m0", apb_vip_sqr_m0));
    void'(uvm_config_db#(uvm_sequencer_base)::get(this, "", "ahb_vip_sqr_m0", ahb_vip_sqr_m0));
    void'(uvm_config_db#(uvm_sequencer_base)::get(this, "", "axi_vip_sqr_m0", axi_vip_sqr_m0));
    void'(uvm_config_db#(uvm_sequencer_base)::get(this, "", "i2c_vip_slv_sqr0", i2c_vip_slv_sqr0));
    void'(uvm_config_db#(uvm_sequencer_base)::get(this, "", "i2c_vip_mst_sqr0", i2c_vip_mst_sqr0));
`endif
  endfunction

  function void connect_phase(uvm_phase phase);
    super.connect_phase(phase);
`ifdef BMS_USE_SVT_VIP
    `uvm_info("connect_phase", "Connecting AMBA VIP system sequencers", UVM_LOW)
    m_env.virt_sqr.ahb_vip_sqr = ahb_env.ahb_system_env.sequencer;
    m_env.virt_sqr.apb_vip_sqr = apb_env.apb_master_env.sequencer;
    m_env.virt_sqr.axi_vip_sqr = axi_env.axi_system_env.sequencer;
    i2c_vip_mst_sqr0 = i2c_vip_env.i2c_system_env.sequencer.master_sequencer[0];
    if ((i2c_vip_cfg.master_cfg[0].is_active != 0) && (i2c_vip_mst_sqr0 == null)) begin
      `uvm_fatal("I2C_VIP_SQR_NULL", "i2c_vip_env.i2c_system_env.sequencer.master_sequencer[0] is null")
    end
    if (i2c_vip_mst_sqr0 != null) begin
      `uvm_info("I2C_VIP_CONNECT", "Connected I2C VIP master sequencer[0]", UVM_LOW)
    end
    i2c_vip_slv_sqr0 = i2c_vip_env.i2c_system_env.sequencer.slave_sequencer[0];
    if ((i2c_vip_cfg.slave_cfg[0].is_active != 0) && (i2c_vip_slv_sqr0 == null)) begin
      `uvm_fatal("I2C_VIP_SQR_NULL", "i2c_vip_env.i2c_system_env.sequencer.slave_sequencer[0] is null")
    end
    if (i2c_vip_slv_sqr0 != null) begin
      `uvm_info("I2C_VIP_CONNECT", "Connected I2C VIP slave sequencer[0]", UVM_LOW)
    end

    if (apb_vip_sqr_m0 == null) begin
      apb_vip_sqr_m0 = apb_env.apb_master_env.sequencer.master_sequencer;
    end
`endif
  endfunction

`ifdef BMS_USE_SVT_VIP
  task run_vip_seq_by_name(string vip_seq_name, uvm_sequencer_base target_sqr);
    uvm_object seq_obj;
    uvm_sequence_base seq_base;
    if (target_sqr == null) begin
      `uvm_fatal("VIP_SQR_NULL", "VIP sequencer handle is null")
    end
    seq_obj = uvm_factory::get().create_object_by_name(vip_seq_name, get_full_name(), "vip_seq_obj");
    if (seq_obj == null) begin
      `uvm_fatal("VIP_SEQ_NF", $sformatf("Cannot create VIP sequence: %s", vip_seq_name))
    end
    if (!$cast(seq_base, seq_obj)) begin
      `uvm_fatal("VIP_SEQ_BAD", $sformatf("Not a uvm_sequence: %s", vip_seq_name))
    end
    seq_base.start(target_sqr);
  endtask
`endif
endclass
