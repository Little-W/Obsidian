class base_virt_seq extends uvm_sequence;
  `uvm_object_utils(base_virt_seq)
  `uvm_declare_p_sequencer(fifo_virtual_sequencer)

  function new(string name = "base_virt_seq");
    super.new(name);
  endfunction
endclass
