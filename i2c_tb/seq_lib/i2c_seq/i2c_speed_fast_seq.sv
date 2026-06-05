class i2c_speed_fast_seq extends i2c_basic_sequence;
  `uvm_object_utils(i2c_speed_fast_seq)

  function new(string name = "i2c_speed_fast_seq");
    super.new(name);
    i2c_speed_mode = "fast";
    write_data = '{8'h22, 8'hc3, 8'h3c, 8'h5e};
    expected_read_data = '{8'hc3, 8'h3c, 8'h5e};
  endfunction
endclass
