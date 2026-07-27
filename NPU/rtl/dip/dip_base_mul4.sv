module dip_base_mul4 (
  input  logic [3:0] a_i,
  input  logic [3:0] b_i,
  input  logic       a_signed_i,
  input  logic       b_signed_i,
  output logic [7:0] product_o
);

  // A non-sign nibble in a wider two's-complement operand is an unsigned
  // radix-16 digit.  The sign controls let the same physical 4x4 multiplier
  // handle both those digits and the signed most-significant digit.
  logic signed [4:0] a_ext;
  logic signed [4:0] b_ext;

  always_comb begin
    if (a_signed_i)
      a_ext = $signed({a_i[3], a_i});
    else
      a_ext = $signed({1'b0, a_i});

    if (b_signed_i)
      b_ext = $signed({b_i[3], b_i});
    else
      b_ext = $signed({1'b0, b_i});
  end

  // Unsigned x unsigned occupies the raw 8 bits.  Every combination with
  // at least one signed digit lies in the signed 8-bit range.  Consequently
  // the same 8-bit product representation is sufficient for all cases.
  assign product_o = 8'(a_ext * b_ext);

endmodule
