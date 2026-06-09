`timescale 1ns/1ps

module fifo_tb;
  import uvm_pkg::*;
  `include "uvm_macros.svh"
  import base_test_pkg::*;

  localparam int DATA_WIDTH = 8;
  localparam int DEPTH = 16;

  logic clk;
  fifo_if tb_if(clk);

  sync_fifo #(
    .DATA_WIDTH(DATA_WIDTH),
    .DEPTH(DEPTH)
  ) u_dut (
    .clk          (clk),
    .rst_n        (tb_if.rst_n),
    .wr_en        (tb_if.wr_en),
    .rd_en        (tb_if.rd_en),
    .wdata        (tb_if.wdata),
    .rdata        (tb_if.rdata),
    .full         (tb_if.full),
    .empty        (tb_if.empty),
    .almost_full  (tb_if.almost_full),
    .almost_empty (tb_if.almost_empty),
    .level        (tb_if.level),
    .overflow     (tb_if.overflow),
    .underflow    (tb_if.underflow)
  );

  initial begin
    clk = 1'b0;
    forever #5 clk = ~clk;
  end

  initial begin
    tb_if.rst_n = 1'b0;
    tb_if.wr_en = 1'b0;
    tb_if.rd_en = 1'b0;
    tb_if.wdata = '0;
    repeat (5) @(posedge clk);
    tb_if.rst_n = 1'b1;
  end

  initial begin
    uvm_config_db#(virtual fifo_if)::set(null, "uvm_test_top", "vif", tb_if);
    run_test();
  end
endmodule
