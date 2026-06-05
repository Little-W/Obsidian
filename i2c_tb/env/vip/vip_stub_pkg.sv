package vip_stub_pkg;
  typedef struct packed {
    bit [31:0] addr;
    bit [31:0] data;
  } vip_stub_tr_t;

`ifdef BMS_USE_SVT_VIP
  import uvm_pkg::*;
  `include "uvm_macros.svh"
  import svt_uvm_pkg::*;
  import svt_mem_uvm_pkg::*;
  import svt_axi_uvm_pkg::*;
  import svt_ahb_uvm_pkg::*;
  import svt_apb_uvm_pkg::*;
  import svt_i2c_uvm_pkg::*;
  import svt_i2c_enum_pkg::*;
  `ifndef SVT_I2C_GENERIC
    `define SVT_I2C_GENERIC 1
  `endif
  `ifndef SVT_I2C_EEPROM
    `define SVT_I2C_EEPROM 2
  `endif

  `include "axi_vip/env/axi_basic_env.sv"
  `include "ahb_vip/env/ahb_ral_env.sv"
  `include "apb_vip/env/cust_svt_apb_master_transaction.sv"
  `include "apb_vip/env/apb_basic_env.sv"
  `include "apb_vip/env/apb_master_directed_sequence.sv"

  `include "i2c_vip/env/i2c_mst_dut_slave_smoke_sequence.sv"
  `include "i2c_vip/env/cust_svt_i2c_slave_transaction.sv"
  `include "i2c_vip/env/cust_svt_i2c_system_configuration.sv"
  `include "i2c_vip/env/i2c_vip_reg_model.sv"
  `include "i2c_vip/env/i2c_vip_basic_env.sv"
  `include "i2c_vip/env/i2c_default_slv_sequence.sv"
  `include "i2c_vip/env/i2c_slave_user_conf_sequence.sv"
  `include "i2c_vip/env/i2c_slv_directed_sequence.sv"
  `include "i2c_vip/env/i2c_slv_nack_sequence.sv"
  `include "i2c_vip/env/i2c_slv_nack_address_sequence.sv"
  `include "i2c_vip/env/i2c_slv_nack_data_sequence.sv"
  `include "i2c_vip/env/i2c_slv_random_sequence.sv"
`endif
endpackage
