module dip_base_add4 (
  input  logic [3:0] a_i,
  input  logic [3:0] b_i,
  input  logic       carry_i,
  output logic [3:0] sum_o,
  output logic       carry_o
);

  logic [4:0] full_sum;

  assign full_sum =
    {1'b0, a_i} + {1'b0, b_i} + {4'b0, carry_i};
  assign sum_o = full_sum[3:0];
  assign carry_o = full_sum[4];

endmodule
