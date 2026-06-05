package common_seq_pkg;
  import uvm_pkg::*;
  `include "uvm_macros.svh"
`ifdef BMS_USE_SVT_VIP
  import svt_uvm_pkg::*;
  import svt_mem_uvm_pkg::*;
  import svt_axi_uvm_pkg::*;
  import svt_apb_uvm_pkg::*;
  import svt_ahb_uvm_pkg::*;
  import vip_stub_pkg::*;
`endif
  import i2c_env_pkg::*;

  `include "base_virt_seq.sv"
endpackage
