/*
 * Integer tensor element to private IEEE-754 binary32 conversion.
 * integer_i is already sign extended from INT4, INT8, or INT32.
 */
module npu_complex_i2f (
  input  logic signed [63:0] integer_i,
  input  logic [31:0]        scale_i,
  output logic [31:0]        result_o
);

  import npu_engine_pkg::*;

  always_comb
    result_o = fp32_mul(fp32_from_int(integer_i), scale_i);

endmodule

/*
 * Private IEEE-754 binary32 to integer tensor conversion.  Division by the
 * destination scale and the requested rounding operation happen before dtype
 * clipping in npu_complex_engine.
 */
module npu_complex_f2i (
  input  logic [31:0]        value_i,
  input  logic [31:0]        scale_i,
  input  logic [1:0]         round_mode_i,
  output logic signed [63:0] result_o,
  output logic               exceptional_o
);

  import npu_engine_pkg::*;

  logic [31:0] scaled_value;

  always_comb begin
    scaled_value = fp32_div(value_i, scale_i);
    result_o = fp32_to_int_round(scaled_value, round_mode_i);
    exceptional_o = fp32_is_nan(scaled_value) ||
                    fp32_is_inf(scaled_value);
  end

endmodule
