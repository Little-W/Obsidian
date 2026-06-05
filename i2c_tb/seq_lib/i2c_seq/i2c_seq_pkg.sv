package i2c_seq_pkg;
  import uvm_pkg::*;
  `include "uvm_macros.svh"
  import i2c_agt_pkg::*;
  import i2c_env_pkg::*;
  import common_seq_pkg::*;
`ifdef BMS_USE_SVT_VIP
  import vip_stub_pkg::*;
`endif

  `include "i2c_seq/i2c_basic_sequence.sv"
  `include "i2c_seq/i2c_smoke_seq.sv"
  `include "i2c_seq/i2c_slave_smoke_seq.sv"
  `include "i2c_seq/i2c_speed_fast_seq.sv"
  `include "i2c_seq/i2c_speed_high_seq.sv"
  `include "i2c_seq/i2c_reg_boundary_seq.sv"
  `include "i2c_seq/i2c_random_reg_seq.sv"
  `include "i2c_seq/i2c_addr_nack_seq.sv"
  `include "i2c_seq/i2c_data_nack_seq.sv"
  `include "i2c_seq/i2c_error_seq.sv"
  `include "i2c_seq/i2c_boundary_seq.sv"
  `include "i2c_seq/i2c_random_seq.sv"
endpackage
