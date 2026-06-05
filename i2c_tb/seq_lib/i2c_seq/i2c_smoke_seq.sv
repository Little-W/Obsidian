class i2c_smoke_seq extends i2c_basic_sequence;
  `uvm_object_utils(i2c_smoke_seq)

  function new(string name = "i2c_smoke_seq");
    super.new(name);
  endfunction
endclass
