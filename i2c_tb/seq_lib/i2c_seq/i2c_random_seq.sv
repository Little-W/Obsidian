class i2c_random_seq extends i2c_random_reg_seq;
  `uvm_object_utils(i2c_random_seq)

  function new(string name = "i2c_random_seq");
    super.new(name);
  endfunction
endclass
