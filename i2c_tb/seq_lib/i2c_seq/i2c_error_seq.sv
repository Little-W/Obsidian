class i2c_error_seq extends i2c_addr_nack_seq;
  `uvm_object_utils(i2c_error_seq)

  function new(string name = "i2c_error_seq");
    super.new(name);
  endfunction
endclass
