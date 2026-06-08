`ifndef I3C_TEST_PKG__SVH
`define I3C_TEST_PKG__SVH

`ifdef I3C_TEST
package i3c_test_pkg;
    `include "uvm_macros.svh"
    import uvm_pkg::*;
    import svt_uvm_pkg::*;
    import svt_amba_uvm_pkg::*;
    import chip_top_seq_pkg::*;
    import chip_top_env_pkg::*;
    import chip_top_test_pkg::*;
    import mcu_dma_seq_pkg::*;
    import svt_mipi_i3c_uvm_pkg::*;
    import svt_i2c_uvm_pkg::*;
    import i3c_pkg::*;

    `include "i3c_define.svh"
    `include "i3c_reg_struct.sv"
    `include "i3c_base_test.sv"
    // ======i3c0============
    `include "i3c_smoke_test.sv"
    `include "i3c0_reg_test.sv"
    `include "i3c0_slave_receive_trans_test.sv"
    `include "i3c0_slave_transmit_trans_test.sv"
    `include "i2c0_slave_receive_trans_test.sv"
    `include "i2c0_slave_transmit_trans_test.sv"
    `include "i3c0_debug_port_test.sv"
    `include "i2c0_master_transmit_withtxfifo_test.sv"
    `include "i3c0_master_transmit_withtxfifo_test.sv"
    `include "i3c0_master_mode_sdr0_rate_test.sv"
    `include "i3c0_master_mode_sdr1_rate_test.sv"
    `include "i3c0_master_mode_sdr2_rate_test.sv"
    `include "i3c0_master_mode_sdr3_rate_test.sv"
    `include "i3c0_master_mode_sdr4_rate_test.sv"
    `include "i3c0_master_mode_hdr_ddr_rate_test.sv"
    `include "i3c0_master_mode_i2c_fm_rate_test.sv"
    `include "i3c0_master_directed_ccc_trans_test.sv"
    `include "i3c0_master_broadcast_ccc_trans_test.sv"
    `include "i3c0_rstn_test.sv"
    `include "i3c0_slave_to_secmaster_test.sv"
    `include "i3c0_trans_txfifo_to_mem_withdma_test.sv"
    `include "i3c0_trans_rxfifo_to_mem_withdma_test.sv"
    `include "i3c0_clk_test.sv"
    `include "i3c0_master_setaasa_test.sv"
    `include "i3c0_master_setdasa_test.sv"
    `include "i3c0_master_transmit_withrxfifo_test.sv"
    `include "i2c0_slave_i2c_fm_transmit_trans_test.sv"
    `include "i2c0_slave_i2c_fm_plus_transmit_trans_test.sv"
    `include "i3c0_master_transmit_withshortdata_test.sv"
    `include "i3c0_slave_test_mode_test.sv"
    //`include "i3c0_master_mode_cov_mem_test.sv"
    //==================i3c1==============================
    `include "i3c1_reg_test.sv"
    `include "i3c1_slave_receive_trans_test.sv"
    `include "i3c1_slave_transmit_trans_test.sv"
    `include "i2c1_slave_receive_trans_test.sv"
    `include "i2c1_slave_transmit_trans_test.sv"
    `include "i3c1_debug_port_test.sv"
    `include "i2c1_master_transmit_withtxfifo_test.sv"
    `include "i3c1_master_transmit_withtxfifo_test.sv"
    `include "i3c1_master_mode_sdr0_rate_test.sv"
    `include "i3c1_master_mode_sdr1_rate_test.sv"
    `include "i3c1_master_mode_sdr2_rate_test.sv"
    `include "i3c1_master_mode_sdr3_rate_test.sv"
    `include "i3c1_master_mode_sdr4_rate_test.sv"
    `include "i3c1_master_mode_hdr_ddr_rate_test.sv"
    `include "i3c1_master_mode_i2c_fm_rate_test.sv"
    `include "i3c1_master_directed_ccc_trans_test.sv"
    `include "i3c1_master_broadcast_ccc_trans_test.sv"
    `include "i3c1_rstn_test.sv"
    `include "i3c1_slave_to_secmaster_test.sv"
    `include "i3c1_trans_txfifo_to_mem_withdma_test.sv"
    `include "i3c1_trans_rxfifo_to_mem_withdma_test.sv"
    `include "i3c1_clk_test.sv"
    `include "i3c1_master_setaasa_test.sv"
    `include "i3c1_master_setdasa_test.sv"
    `include "i3c1_master_transmit_withrxfifo_test.sv"
    `include "i2c1_slave_i2c_fm_transmit_trans_test.sv"
    `include "i2c1_slave_i2c_fm_plus_transmit_trans_test.sv"
    `include "i3c1_master_transmit_withshortdata_test.sv"
    `include "i3c1_slave_test_mode_test.sv"
   //`include "i3c1_master_mode_cov_mem_test.sv"
   //================================================
    `ifdef CPU_TEST
	  `include "i3c0_intr_test.sv"
      `include "i3c1_intr_test.sv"
    `endif


endpackage: i3c_test_pkg
`endif

`endif
