`timescale 1ns/1ps

`include "uvm_macros.svh"
`include "tue_macros.svh"

module axi_tvip_tb;
  timeunit 1ns;
  timeprecision 1ps;

  import uvm_pkg::*;
  import tue_pkg::*;
  import tvip_common_pkg::*;
  import tvip_axi_types_pkg::*;
  import tvip_axi_pkg::*;

  bit clk;
  bit reset_n;

  tvip_axi_if axi_if(clk, reset_n);
  axi_tvip_myip_wrapper dut_wrapper(axi_if);

  `include "axi_tvip_smoke_sequence.sv"
  `include "axi_tvip_smoke_test.sv"

  initial begin
    clk = 1'b0;
    forever #5ns clk = ~clk;
  end

  initial begin
    reset_n = 1'b0;
    repeat (8) @(posedge clk);
    reset_n = 1'b1;
  end

  initial begin
    uvm_config_db#(tvip_axi_vif)::set(null, "uvm_test_top", "vif", axi_if);
    run_test();
  end
endmodule
