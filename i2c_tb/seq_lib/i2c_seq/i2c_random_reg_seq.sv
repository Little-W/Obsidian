class i2c_random_reg_seq extends i2c_basic_sequence;
  `uvm_object_utils(i2c_random_reg_seq)

  constraint random_reg_payload_c {
    write_data.size() inside {[2:8]};
    expected_read_data.size() == write_data.size() - 1;
  }

  function new(string name = "i2c_random_reg_seq");
    super.new(name);
  endfunction

  task body();
    basic_payload_c.constraint_mode(0);
    expected_read_data.delete();
    if (!randomize()) begin
      `uvm_fatal("I2C_RANDOMIZE_FAILED", "i2c_random_reg_seq randomize failed")
    end
    expected_read_data.delete();
    for (int i = 1; i < write_data.size(); i++) begin
      expected_read_data.push_back(write_data[i]);
    end
    super.body();
  endtask
endclass
