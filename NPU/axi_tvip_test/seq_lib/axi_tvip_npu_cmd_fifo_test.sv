class npu_axi_fault_write_driver extends tvip_axi_master_write_driver;
  function new(
    string name = "npu_axi_fault_write_driver",
    uvm_component parent = null
  );
    super.new(name, parent);
  endfunction

  protected task drive_write_data(
    bit           valid,
    tvip_axi_item item,
    int           index
  );
    super.drive_write_data(valid, item, index);
    if (valid && (configuration.protocol == TVIP_AXI4)) begin
      case (npu_axi_wlast_fault_control::mode)
        NPU_WLAST_EARLY: begin
          vif.master_cb.wlast <= (index == 0);
        end
        NPU_WLAST_MISSING: begin
          vif.master_cb.wlast <= 1'b0;
        end
        default: begin
        end
      endcase
    end
  endtask

  `uvm_component_utils(npu_axi_fault_write_driver)
endclass

class axi_tvip_npu_cmd_fifo_test extends uvm_test;
  tvip_axi_configuration axi_cfg;
  tvip_axi_master_agent  master_agent;
  tvip_axi_vif           axi_vif;
  npu_cmd_backend_vif    backend_vif;

  function new(
    string name = "axi_tvip_npu_cmd_fifo_test",
    uvm_component parent = null
  );
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    if (!uvm_config_db#(tvip_axi_vif)::get(this, "", "vif", axi_vif)) begin
      `uvm_fatal("NPU_AXI", "missing tvip_axi_vif config")
    end
    if (!uvm_config_db#(npu_cmd_backend_vif)::get(
          this, "", "backend_vif", backend_vif
        )) begin
      `uvm_fatal("NPU_AXI", "missing npu_cmd_backend_vif config")
    end

    tvip_axi_master_write_driver::type_id::set_type_override(
      npu_axi_fault_write_driver::get_type()
    );

    axi_cfg = tvip_axi_configuration::type_id::create("axi_cfg");
    axi_cfg.vif = axi_vif;
    if (!axi_cfg.randomize() with {
      protocol == TVIP_AXI4;
      id_width == 8;
      address_width == 24;
      max_burst_length == 16;
      data_width == 64;
      qos_range[0] == 0;
      qos_range[1] == 0;
      response_ordering == TVIP_AXI_IN_ORDER;
      outstanding_responses == 0;
      enable_response_interleaving == 0;
      reset_by_agent == 0;

      request_start_delay.min_delay == 0;
      request_start_delay.max_delay == 0;
      write_data_delay.min_delay == 0;
      write_data_delay.mid_delay[0] == 1;
      write_data_delay.mid_delay[1] == 16;
      write_data_delay.max_delay == 32;
      write_data_delay.weight_zero_delay == 1;
      write_data_delay.weight_short_delay == 1;
      write_data_delay.weight_long_delay == 1;
      bready_delay.min_delay == 0;
      bready_delay.max_delay == 0;
      rready_delay.min_delay == 0;
      rready_delay.max_delay == 0;
      default_bready == 1;
      default_rready == 1;
    }) begin
      `uvm_fatal("NPU_AXI", "AXI configuration randomization failed")
    end

    master_agent = tvip_axi_master_agent::type_id::create(
      "master_agent", this
    );
    master_agent.set_configuration(axi_cfg);
  endfunction

  task main_phase(uvm_phase phase);
    axi_tvip_npu_cmd_fifo_sequence npu_sequence;

    phase.raise_objection(this);
    npu_sequence = axi_tvip_npu_cmd_fifo_sequence::type_id::create(
      "npu_cmd_fifo_sequence"
    );
    npu_sequence.axi_vif     = axi_vif;
    npu_sequence.backend_vif = backend_vif;
    npu_sequence.start(master_agent.sequencer);
    phase.drop_objection(this);
  endtask

  function void report_phase(uvm_phase phase);
    uvm_report_server server;

    super.report_phase(phase);
    server = uvm_report_server::get_server();
    if ((server.get_severity_count(UVM_ERROR) == 0) &&
        (server.get_severity_count(UVM_FATAL) == 0)) begin
      `uvm_info("NPU_AXI", "\nNpuAxiCmdFifoEpilog: Passed", UVM_NONE)
      `uvm_info("NPU_AXI", "\nTvipAxiTestEpilog: Passed", UVM_NONE)
    end
  endfunction

  `uvm_component_utils(axi_tvip_npu_cmd_fifo_test)
endclass
