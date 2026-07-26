class axi_tvip_smoke_test extends uvm_test;
  tvip_axi_configuration  axi_cfg;
  tvip_axi_master_agent   master_agent;

  function new(string name = "axi_tvip_smoke_test", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    tvip_axi_vif vif;

    super.build_phase(phase);
    if (!uvm_config_db#(tvip_axi_vif)::get(this, "", "vif", vif)) begin
      `uvm_fatal("AXI_TVIP", "missing tvip_axi_vif config")
    end

    axi_cfg = tvip_axi_configuration::type_id::create("axi_cfg");
    axi_cfg.vif = vif;
    if (!axi_cfg.randomize() with {
      protocol == TVIP_AXI4;
      id_width == 1;
      address_width == 6;
      max_burst_length == 1;
      data_width == 32;
      qos_range[0] == 0;
      qos_range[1] == 0;
      response_ordering == TVIP_AXI_IN_ORDER;
      outstanding_responses == 0;
      enable_response_interleaving == 0;
      reset_by_agent == 0;
    }) begin
      `uvm_fatal("AXI_TVIP", "AXI configuration randomization failed")
    end

    master_agent = tvip_axi_master_agent::type_id::create("master_agent", this);
    master_agent.set_configuration(axi_cfg);
  endfunction

  function void end_of_elaboration_phase(uvm_phase phase);
    super.end_of_elaboration_phase(phase);
    uvm_config_db#(uvm_object_wrapper)::set(
      master_agent.sequencer,
      "main_phase",
      "default_sequence",
      axi_tvip_smoke_sequence::type_id::get()
    );
  endfunction

  function void report_phase(uvm_phase phase);
    uvm_report_server server;
    super.report_phase(phase);
    server = uvm_report_server::get_server();
    if ((server.get_severity_count(UVM_ERROR) == 0) &&
        (server.get_severity_count(UVM_FATAL) == 0)) begin
      `uvm_info("AXI_TVIP", "\nTvipAxiTestEpilog: Passed", UVM_NONE)
    end
  endfunction

  `uvm_component_utils(axi_tvip_smoke_test)
endclass
