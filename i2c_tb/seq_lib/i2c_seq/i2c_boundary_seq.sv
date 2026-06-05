class i2c_boundary_seq extends i2c_reg_boundary_seq;
  `uvm_object_utils(i2c_boundary_seq)

  function new(string name = "i2c_boundary_seq");
    super.new(name);
  endfunction
endclass
