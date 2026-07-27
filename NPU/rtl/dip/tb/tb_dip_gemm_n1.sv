`timescale 1ns/1ps

module tb_dip_gemm_n1;

  localparam int unsigned ARRAY_N = 1;

  logic clk;
  logic reset_n;
  logic [1:0] mode;
  logic b_valid;
  logic b_ready;
  logic [15:0] b_row;
  logic a_valid;
  logic a_ready;
  logic [15:0] a_row;
  logic c_valid;
  logic c_last;
  logic [31:0] c_row;
  logic busy;
  logic done;

  dip_gemm_core #(
    .ARRAY_N(ARRAY_N)
  ) dut (
    .clk_i(clk),
    .reset_n(reset_n),
    .mode_i(mode),
    .b_raw_row_valid_i(b_valid),
    .b_raw_row_ready_o(b_ready),
    .b_raw_row_i(b_row),
    .a_row_valid_i(a_valid),
    .a_row_ready_o(a_ready),
    .a_row_i(a_row),
    .c_row_valid_o(c_valid),
    .c_row_last_o(c_last),
    .c_row_o(c_row),
    .busy_o(busy),
    .tile_done_o(done)
  );

  always #5 clk = ~clk;

  task automatic run_tile(
    input logic signed [15:0] a_value,
    input logic signed [15:0] b_value,
    input logic signed [31:0] expected
  );
    int timeout;
    begin
      @(negedge clk);
      b_row = b_value;
      b_valid = 1'b1;
      do @(posedge clk); while (!b_ready);

      @(negedge clk);
      b_valid = 1'b0;
      b_row = '0;
      a_row = a_value;
      a_valid = 1'b1;
      do @(posedge clk); while (!a_ready);

      @(negedge clk);
      a_valid = 1'b0;
      a_row = '0;

      timeout = 0;
      while (!c_valid && timeout < 20) begin
        @(negedge clk);
        timeout++;
      end
      if (!c_valid)
        $fatal(1, "N=1 result timeout");
      if ($signed(c_row) !== expected)
        $fatal(1, "N=1 result got %0d expected %0d",
               $signed(c_row), expected);
      if (!c_last)
        $fatal(1, "N=1 c_last was not asserted");

      while (!done)
        @(negedge clk);
      @(posedge clk);
      @(negedge clk);

      if (busy || !b_ready)
        $fatal(1, "N=1 core did not return to idle");
    end
  endtask

  initial begin
    clk = 1'b0;
    reset_n = 1'b0;
    mode = 2'd0;
    b_valid = 1'b0;
    b_row = '0;
    a_valid = 1'b0;
    a_row = '0;

    repeat (3) @(posedge clk);
    @(negedge clk);
    reset_n = 1'b1;

    run_tile(
      -16'sd32768,
      -16'sd32768,
      32'sd1073741824
    );
    run_tile(
      -16'sd32768,
      16'sd32767,
      -32'sd1073709056
    );

    $display("tb_dip_gemm_n1: PASS");
    $finish;
  end

endmodule
