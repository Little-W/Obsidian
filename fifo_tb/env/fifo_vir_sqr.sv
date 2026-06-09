class fifo_virtual_sequencer extends uvm_sequencer;
  `uvm_component_utils(fifo_virtual_sequencer)

  virtual fifo_if vif;
  fifo_sequencer fifo_sqr;

  function new(string name = "fifo_virtual_sequencer", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if (!uvm_config_db#(virtual fifo_if)::get(this, "", "vif", vif)) begin
      `uvm_fatal("NOVIF", "fifo_if is not set for virtual sequencer")
    end
  endfunction
endclass
