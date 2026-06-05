class i2c_virtual_sequencer extends uvm_sequencer;
`ifdef BMS_USE_SVT_VIP
  svt_axi_system_sequencer axi_vip_sqr;
  svt_ahb_system_sequencer ahb_vip_sqr;
  svt_apb_system_sequencer apb_vip_sqr;

  svt_apb_vif svt_apb_vif_s1;
  svt_ahb_vif svt_ahb_vif_t;
  svt_axi_vif svt_axi_vif_t;
`endif

  virtual i2c_if i2c_if_p;
  i2c_sequencer i2c_sqr;

  `uvm_component_utils(i2c_virtual_sequencer)

  function new(string name = "i2c_virtual_sequencer", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if (!uvm_config_db#(virtual i2c_if)::get(this, "", "vif", i2c_if_p)) begin
      `uvm_fatal("i2c_vir_sqr", "cannot get i2c_if vif")
    end
  endfunction
endclass
