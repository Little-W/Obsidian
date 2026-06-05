class i2c_addr_nack_seq extends i2c_basic_sequence;
  `uvm_object_utils(i2c_addr_nack_seq)

  function new(string name = "i2c_addr_nack_seq");
    super.new(name);
    write_data = '{8'h44, 8'hde};
    expected_read_data.delete();
  endfunction

  task body();
    basic_payload_c.constraint_mode(0);
    wait_reset_done();
    configure_from_plusargs();
    set_i2c_speed_mode(i2c_speed_mode);

`ifdef BMS_USE_SVT_VIP
    fork
      start_i2c_vip_slave_sequence("i2c_slv_nack_sequence");
    join_none

    i2c_dut_init_controller();
    i2c_dut_write_bytes_expect_abort(write_data, "address NACK feature case");
    wait_i2c_observation_window(100);
`else
    `uvm_fatal("I2C_SVT_REQUIRED", "Address NACK test requires BMS_USE_SVT_VIP")
`endif
  endtask
endclass
