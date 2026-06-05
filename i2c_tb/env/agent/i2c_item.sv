class i2c_item extends uvm_sequence_item;
  rand bit [7:0] data;
  `uvm_object_utils(i2c_item)

  function new(string name = "i2c_item");
    super.new(name);
  endfunction
endclass
