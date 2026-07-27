`timescale 1ns/1ps

module tb_dip_pe;

  localparam logic [1:0] MODE_INT16 = 2'd0;
  localparam logic [1:0] MODE_INT8 = 2'd1;
  localparam logic [1:0] MODE_INT4 = 2'd2;

  logic clk;
  logic reset_n;
  logic [1:0] mode;
  logic wshift;
  logic pe_en;
  logic mul_en;
  logic reduce_en;
  logic adder_en;
  logic signed [15:0] data_in;
  logic signed [15:0] data_neighbor;
  logic signed [15:0] weight_in;
  logic signed [63:0] psum_in;
  logic signed [15:0] data_out;
  logic signed [15:0] weight_out;
  logic signed [63:0] psum_out;

  dip_pe dut (
    .clk_i(clk),
    .reset_n(reset_n),
    .mode_i(mode),
    .wshift_i(wshift),
    .pe_en_i(pe_en),
    .mul_en_i(mul_en),
    .reduce_en_i(reduce_en),
    .adder_en_i(adder_en),
    .data_i(data_in),
    .data_neighbor_i(data_neighbor),
    .weight_i(weight_in),
    .psum_i(psum_in),
    .data_o(data_out),
    .weight_o(weight_out),
    .psum_o(psum_out)
  );

  always #5 clk = ~clk;

  task automatic shift_weight(input logic [15:0] word);
    begin
      @(negedge clk);
      weight_in = word;
      wshift = 1'b1;
      @(posedge clk);
      @(negedge clk);
      wshift = 1'b0;
    end
  endtask

  task automatic load_data(
    input logic [15:0] own_word,
    input logic [15:0] neighbor_word
  );
    begin
      @(negedge clk);
      data_in = own_word;
      data_neighbor = neighbor_word;
      pe_en = 1'b1;
      @(posedge clk);
      @(negedge clk);
      pe_en = 1'b0;
    end
  endtask

  task automatic execute_mac(input logic [63:0] initial_psum);
    begin
      mul_en = 1'b1;
      @(posedge clk);
      @(negedge clk);
      mul_en = 1'b0;
      reduce_en = 1'b1;
      @(posedge clk);
      @(negedge clk);
      reduce_en = 1'b0;
      psum_in = initial_psum;
      adder_en = 1'b1;
      @(posedge clk);
      #1;
      @(negedge clk);
      adder_en = 1'b0;
    end
  endtask

  initial begin
    logic [15:0] int8_weight_u0;
    logic [15:0] int8_weight_u1;
    logic [15:0] int4_weight_u [0:3];
    logic [63:0] expected;

    clk = 1'b0;
    reset_n = 1'b0;
    mode = MODE_INT16;
    wshift = 1'b0;
    pe_en = 1'b0;
    mul_en = 1'b0;
    reduce_en = 1'b0;
    adder_en = 1'b0;
    data_in = '0;
    data_neighbor = '0;
    weight_in = '0;
    psum_in = '0;

    repeat (3) @(posedge clk);
    @(negedge clk);
    reset_n = 1'b1;

    // INT16: one signed product, one signed 64-bit temporary accumulator.
    mode = MODE_INT16;
    shift_weight(-16'sd30000);
    load_data(16'sd32767, 16'sd0);
    execute_mac(64'sd5000000000);
    expected = 64'sd5000000000 +
               (64'sd32767 * -64'sd30000);
    if ($signed(psum_out) !== $signed(expected))
      $fatal(1, "INT16 PE got %0d expected %0d",
             $signed(psum_out), $signed(expected));

    /*
     * INT8:
     *   own data     = [3, -4]
     *   right data   = [9, 10]
     *   W[u=0]       = [5, -6]
     *   W[u=1]       = [7,  8]
     * contribution lanes = [-13, 96].
     */
    mode = MODE_INT8;
    int8_weight_u0[7:0] = 8'd5;
    int8_weight_u0[15:8] = -8'sd6;
    int8_weight_u1[7:0] = 8'd7;
    int8_weight_u1[15:8] = 8'd8;
    shift_weight(int8_weight_u1);
    shift_weight(int8_weight_u0);
    if (weight_out !== int8_weight_u1)
      $fatal(1, "INT8 weight-chain tail mismatch");

    load_data({-8'sd4, 8'd3}, {8'd10, 8'd9});
    execute_mac({-32'sd2000, 32'd1000});
    expected = {-32'sd1904, 32'd987};
    if (psum_out !== expected)
      $fatal(1, "INT8 PE got %h expected %h", psum_out, expected);

    /*
     * INT4 own=[1,-2,3,-4], right=[5,6,7,-8].
     * The four local dot products are [21,-4,17,-56].
     */
    mode = MODE_INT4;
    int4_weight_u[0] = {4'd4, 4'd3, 4'd2, 4'd1};
    int4_weight_u[1] = {-4'sd4, -4'sd3, -4'sd2, -4'sd1};
    int4_weight_u[2] = {-4'sd1, -4'sd2, 4'd1, 4'd2};
    int4_weight_u[3] = {-4'sd2, 4'd1, 4'd2, -4'sd3};
    for (int u = 3; u >= 0; u--)
      shift_weight(int4_weight_u[u]);
    if (weight_out !== int4_weight_u[3])
      $fatal(1, "INT4 weight-chain tail mismatch");

    load_data(
      {-4'sd4, 4'd3, -4'sd2, 4'd1},
      {-4'sd8, 4'd7, 4'd6, 4'd5}
    );
    execute_mac({
      -16'sd400,
      16'd300,
      -16'sd200,
      16'd100
    });
    expected = {
      -16'sd456,
      16'd317,
      -16'sd204,
      16'd121
    };
    if (psum_out !== expected)
      $fatal(1, "INT4 PE got %h expected %h", psum_out, expected);

    // Disabled registers must hold, then asynchronous reset must clear them.
    @(negedge clk);
    data_in = 16'h55aa;
    weight_in = 16'haa55;
    psum_in = 64'h1234;
    repeat (2) @(posedge clk);
    #1;
    if (psum_out !== expected)
      $fatal(1, "PE enable-low hold behavior failed");

    @(negedge clk);
    reset_n = 1'b0;
    #1;
    if (data_out !== '0 || weight_out !== '0 || psum_out !== '0)
      $fatal(1, "PE asynchronous reset failed");

    $display("tb_dip_pe: PASS");
    $finish;
  end

endmodule
