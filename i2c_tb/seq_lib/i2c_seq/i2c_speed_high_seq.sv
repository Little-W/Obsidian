class i2c_speed_high_seq extends i2c_basic_sequence;
  `uvm_object_utils(i2c_speed_high_seq)

  function new(string name = "i2c_speed_high_seq");
    super.new(name);
    i2c_speed_mode = "high";
    write_data = '{8'h33, 8'h96, 8'h69, 8'hf0};
    expected_read_data = '{8'h96, 8'h69, 8'hf0};
    i2c_timeout_scale = 8;
  endfunction
endclass
