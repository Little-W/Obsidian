package base_test_pkg;
  import uvm_pkg::*;
  `include "uvm_macros.svh"
  import i2c_agt_pkg::*;
  import i2c_env_pkg::*;
  import common_seq_pkg::*;
  import i2c_seq_pkg::*;

`ifdef BMS_USE_SVT_VIP
  import svt_uvm_pkg::*;
  import svt_mem_uvm_pkg::*;
  import svt_axi_uvm_pkg::*;
  import svt_apb_uvm_pkg::*;
  import svt_ahb_uvm_pkg::*;
  import svt_i2c_uvm_pkg::*;
  import svt_i2c_enum_pkg::*;
  import vip_stub_pkg::*;
`endif

  `include "i2c_base_test.sv"
  `include "i2c_smoke_test.sv"
endpackage
