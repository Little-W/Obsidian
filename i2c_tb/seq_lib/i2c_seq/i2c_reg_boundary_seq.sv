class i2c_reg_boundary_seq extends i2c_basic_sequence;
  `uvm_object_utils(i2c_reg_boundary_seq)

  function new(string name = "i2c_reg_boundary_seq");
    super.new(name);
  endfunction

  task body();
    byte unsigned wr0[$];
    byte unsigned rd0[$];
    byte unsigned wrff[$];
    byte unsigned rdff[$];

    wait_reset_done();
    configure_from_plusargs();
    set_i2c_speed_mode(i2c_speed_mode);

`ifdef BMS_USE_SVT_VIP
    fork
      start_i2c_vip_slave_sequence("i2c_slv_directed_sequence");
    join_none

    wr0 = '{8'h00, 8'h11, 8'h22};
    rd0 = '{8'h11, 8'h22};
    wrff = '{8'hff, 8'hee};
    rdff = '{8'hee};

    i2c_dut_init_controller();
    i2c_dut_write_bytes(wr0);
    i2c_dut_read_and_check(rd0);
    i2c_dut_write_bytes(wrff);
    i2c_dut_read_and_check(rdff);
    i2c_dut_check_no_abort();
    wait_i2c_observation_window(100);
`else
    `uvm_fatal("I2C_SVT_REQUIRED", "Register boundary test requires BMS_USE_SVT_VIP")
`endif
  endtask
endclass
