package i2c_env_pkg;
  import uvm_pkg::*;
  `include "uvm_macros.svh"
`ifdef BMS_USE_SVT_VIP
  import svt_uvm_pkg::*;
  import svt_mem_uvm_pkg::*;
  import svt_axi_uvm_pkg::*;
  import svt_apb_uvm_pkg::*;
  import svt_ahb_uvm_pkg::*;
  import vip_stub_pkg::*;
`endif
  import i2c_agt_pkg::*;

  `include "i2c_vir_sqr.sv"

  class i2c_env extends uvm_env;
    `uvm_component_utils(i2c_env)

    i2c_agent agt;
    i2c_virtual_sequencer virt_sqr;

    function new(string name = "i2c_env", uvm_component parent = null);
      super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      agt = i2c_agent::type_id::create("agt", this);
      virt_sqr = i2c_virtual_sequencer::type_id::create("virt_sqr", this);
    endfunction

    function void connect_phase(uvm_phase phase);
      super.connect_phase(phase);
      virt_sqr.i2c_sqr = agt.sqr;
    endfunction
  endclass
endpackage
