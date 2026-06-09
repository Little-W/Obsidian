package fifo_env_pkg;
  import uvm_pkg::*;
  `include "uvm_macros.svh"
  import fifo_agt_pkg::*;

  `include "fifo_vir_sqr.sv"
  `include "fifo_scoreboard.sv"
  `include "fifo_coverage.sv"

  class fifo_env extends uvm_env;
    `uvm_component_utils(fifo_env)

    fifo_agent agt;
    fifo_virtual_sequencer virt_sqr;
    fifo_scoreboard scb;
    fifo_coverage cov;

    function new(string name = "fifo_env", uvm_component parent = null);
      super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      uvm_config_db#(uvm_active_passive_enum)::set(this, "agt", "is_active", UVM_ACTIVE);
      agt = fifo_agent::type_id::create("agt", this);
      virt_sqr = fifo_virtual_sequencer::type_id::create("virt_sqr", this);
      scb = fifo_scoreboard::type_id::create("scb", this);
      cov = fifo_coverage::type_id::create("cov", this);
    endfunction

    function void connect_phase(uvm_phase phase);
      super.connect_phase(phase);
      virt_sqr.fifo_sqr = agt.sqr;
      agt.mon.ap.connect(scb.imp);
      agt.mon.ap.connect(cov.analysis_export);
    endfunction
  endclass
endpackage
