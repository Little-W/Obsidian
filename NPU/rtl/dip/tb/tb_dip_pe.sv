`timescale 1ns/1ps

module tb_dip_pe;

  logic clk;
  logic reset_n;
  logic wshift;
  logic pe_en;
  logic mul_en;
  logic adder_en;
  logic signed [15:0] data_in;
  logic signed [15:0] weight_in;
  logic signed [31:0] psum_in;
  logic signed [15:0] data_out;
  logic signed [15:0] weight_out;
  logic signed [31:0] psum_out;

  dip_pe dut (
    .clk_i(clk),
    .reset_n(reset_n),
    .wshift_i(wshift),
    .pe_en_i(pe_en),
    .mul_en_i(mul_en),
    .adder_en_i(adder_en),
    .data_i(data_in),
    .weight_i(weight_in),
    .psum_i(psum_in),
    .data_o(data_out),
    .weight_o(weight_out),
    .psum_o(psum_out)
  );

  always #5 clk = ~clk;

  initial begin
    logic signed [15:0] held_data;
    logic signed [15:0] held_weight;
    logic signed [31:0] held_psum;

    clk = 1'b0;
    reset_n = 1'b0;
    wshift = 1'b0;
    pe_en = 1'b0;
    mul_en = 1'b0;
    adder_en = 1'b0;
    data_in = '0;
    weight_in = '0;
    psum_in = '0;

    repeat (3) @(posedge clk);
    @(negedge clk);
    reset_n = 1'b1;

    data_in = -16'sd123;
    weight_in = 16'sd45;
    pe_en = 1'b1;
    wshift = 1'b1;
    @(posedge clk);
    #1;
    if (data_out !== -16'sd123 || weight_out !== 16'sd45)
      $fatal(1, "PE input/weight register load failed");

    @(negedge clk);
    pe_en = 1'b0;
    wshift = 1'b0;
    mul_en = 1'b1;
    @(posedge clk);

    @(negedge clk);
    mul_en = 1'b0;
    adder_en = 1'b1;
    psum_in = 32'sd1000;
    @(posedge clk);
    #1;
    if (psum_out !== -32'sd4535)
      $fatal(1, "PE signed MAC mismatch: got %0d expected -4535",
             psum_out);

    @(negedge clk);
    adder_en = 1'b0;
    data_in = 16'sd777;
    weight_in = -16'sd9;
    psum_in = 32'sd42;
    held_data = data_out;
    held_weight = weight_out;
    held_psum = psum_out;
    repeat (2) begin
      @(posedge clk);
      #1;
      if (data_out !== held_data ||
          weight_out !== held_weight ||
          psum_out !== held_psum)
        $fatal(1, "PE enable-low hold behavior failed");
    end

    @(negedge clk);
    data_in = 16'sd32767;
    pe_en = 1'b1;
    @(posedge clk);

    @(negedge clk);
    pe_en = 1'b0;
    mul_en = 1'b1;
    @(posedge clk);

    @(negedge clk);
    mul_en = 1'b0;
    adder_en = 1'b1;
    psum_in = -32'sd2000000;
    @(posedge clk);
    #1;
    if (psum_out !== -32'sd525485)
      $fatal(1, "PE second MAC mismatch: got %0d expected -525485",
             psum_out);

    @(negedge clk);
    reset_n = 1'b0;
    #1;
    if (data_out !== '0 || weight_out !== '0 || psum_out !== '0)
      $fatal(1, "PE asynchronous reset failed");

    $display("tb_dip_pe: PASS");
    $finish;
  end

endmodule
