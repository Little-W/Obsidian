class i2c_smoke_test extends i2c_base_test;
  `uvm_component_utils(i2c_smoke_test)

  function new(string name = "i2c_smoke_test", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  task run_phase(uvm_phase phase);
    string seq_name;
    uvm_object seq_obj;
    uvm_sequence_base seq_base;
    base_virt_seq virt_seq;
    phase.raise_objection(this);

    if (!$value$plusargs("SEQ=%s", seq_name)) begin
      seq_name = "i2c_smoke_seq";
    end

    seq_obj = uvm_factory::get().create_object_by_name(seq_name, get_full_name(), "seq_obj");
    if (seq_obj == null) begin
      `uvm_fatal("BAD_SEQ", $sformatf("Unknown +SEQ=%s", seq_name))
    end
    if (!$cast(seq_base, seq_obj)) begin
      `uvm_fatal("BAD_SEQ_TYPE", $sformatf("SEQ=%s is not a uvm_sequence", seq_name))
    end
    if ($cast(virt_seq, seq_base)) begin
      virt_seq.vif = vif;
      virt_seq.env = m_env;
`ifdef BMS_USE_SVT_VIP
      virt_seq.apb_vip_sqr_m0 = apb_vip_sqr_m0;
      virt_seq.ahb_vip_sqr_m0 = ahb_vip_sqr_m0;
      virt_seq.axi_vip_sqr_m0 = axi_vip_sqr_m0;
      virt_seq.i2c_vip_slv_sqr0 = i2c_vip_slv_sqr0;
      virt_seq.i2c_vip_mst_sqr0 = i2c_vip_mst_sqr0;
      virt_seq.apb_vip_sqr = m_env.virt_sqr.apb_vip_sqr;
      virt_seq.ahb_vip_sqr = m_env.virt_sqr.ahb_vip_sqr;
      virt_seq.axi_vip_sqr = m_env.virt_sqr.axi_vip_sqr;
`endif
      seq_base.start(null);
    end else begin
      seq_base.start(m_env.agt.sqr);
    end

    repeat (20) @(posedge vif.clk);
    `uvm_info(get_type_name(), $sformatf("i2c_smoke_test completed with +SEQ=%s", seq_name), UVM_LOW)
    phase.drop_objection(this);
  endtask
endclass
