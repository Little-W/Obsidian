
/**
 * Abstract:
 * Defines a virtual sequencer for the testbench ENV.  This sequencer obtains
 * a handle to the reset interface using the config db.  This allows
 * reset sequences to be written for this sequencer.
 */

`ifndef GUARD_AXI_VIRTUAL_SEQUENCER_SV
`define GUARD_AXI_VIRTUAL_SEQUENCER_SV

class axi_virtual_sequencer extends uvm_sequencer;

  /** Typedef of the reset modport to simplify access */

  /** Reset modport provides access to the reset signal */


  `uvm_component_utils(axi_virtual_sequencer)

  function new(string name="axi_virtual_sequencer", uvm_component parent=null);
    super.new(name,parent);
  endfunction // new


  virtual function void build_phase(uvm_phase phase);
    `uvm_info("build_phase", "Entered...", UVM_LOW)

    super.build_phase(phase);



    `uvm_info("build_phase", "Exiting...", UVM_LOW)
  endfunction

endclass

`endif // GUARD_AXI_VIRTUAL_SEQUENCER_SV
