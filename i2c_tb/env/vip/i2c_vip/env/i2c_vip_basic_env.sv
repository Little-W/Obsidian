`ifndef GUARD_I2C_VIP_BASIC_ENV_SV
`define GUARD_I2C_VIP_BASIC_ENV_SV

class i2c_vip_basic_env extends uvm_env;
  `uvm_component_utils(i2c_vip_basic_env)

  svt_i2c_system_env i2c_system_env;
  cust_svt_i2c_system_configuration i2c_system_cfg;
  svt_i2c_vif vif;
  i2c_vip_reg_model reg_model;

  function new(string name = "i2c_vip_basic_env", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  virtual function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    if (!uvm_config_db#(cust_svt_i2c_system_configuration)::get(this, "", "i2c_system_cfg", i2c_system_cfg) ||
        (i2c_system_cfg == null)) begin
      `uvm_fatal("I2C_VIP_CFG", "i2c_system_cfg is not set")
    end

    if (uvm_config_db#(svt_i2c_vif)::get(this, "", "vif", vif)) begin
      i2c_system_cfg.set_if(vif);
    end else if (i2c_system_cfg.i2c_if == null) begin
      `uvm_fatal("I2C_VIP_VIF", "svt_i2c_vif is not set")
    end

    uvm_config_db#(svt_i2c_system_configuration)::set(this, "i2c_system_env", "cfg", i2c_system_cfg);
    i2c_system_env = svt_i2c_system_env::type_id::create("i2c_system_env", this);
    reg_model = i2c_vip_reg_model::type_id::create("reg_model", this);
  endfunction

  virtual function void connect_phase(uvm_phase phase);
    super.connect_phase(phase);

    i2c_system_env.slave[0].monitor.xact_observed_port.connect(reg_model.slave_obs_export);
  endfunction
endclass

`endif
