module dip_pe (
  input  logic               clk_i,
  input  logic               reset_n,

  input  logic               wshift_i,
  input  logic               pe_en_i,
  input  logic               mul_en_i,
  input  logic               adder_en_i,

  input  logic signed [15:0] data_i,
  input  logic signed [15:0] weight_i,
  input  logic signed [31:0] psum_i,

  output logic signed [15:0] data_o,
  output logic signed [15:0] weight_o,
  output logic signed [31:0] psum_o
);

  logic signed [15:0] data_q;
  logic signed [15:0] weight_q;
  logic signed [31:0] product_q;
  logic signed [31:0] psum_q;

  assign data_o = data_q;
  assign weight_o = weight_q;
  assign psum_o = psum_q;

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      data_q <= '0;
      weight_q <= '0;
      product_q <= '0;
      psum_q <= '0;
    end else begin
      if (wshift_i)
        weight_q <= weight_i;

      if (pe_en_i)
        data_q <= data_i;

      if (mul_en_i)
        product_q <= $signed(data_q) * $signed(weight_q);

      if (adder_en_i)
        psum_q <= $signed(psum_i) + $signed(product_q);
    end
  end

endmodule
