
/**
 * Abstract:
 * Defines a virtual sequencer for the testbench ENV.  
 */

`ifndef GUARD_AHB_VIRTUAL_SEQUENCER_SV
`define GUARD_AHB_VIRTUAL_SEQUENCER_SV

class ahb_virtual_sequencer extends uvm_sequencer;


  `uvm_component_utils(ahb_virtual_sequencer)

  function new(string name="ahb_virtual_sequencer", uvm_component parent=null);
    super.new(name,parent);
  endfunction // new


  virtual function void build_phase(uvm_phase phase);
    `uvm_info("build_phase", "Entered...", UVM_LOW)

    super.build_phase(phase);

    `uvm_info("build_phase", "Exiting...", UVM_LOW)
  endfunction

endclass

`endif // GUARD_AHB_VIRTUAL_SEQUENCER_SV
