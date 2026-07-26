/*
 * Complex Engine IEEE-754 binary32 reference datapath.
 *
 * The ports carry IEEE-754 binary32 bit patterns.  They are private to CME:
 * L1 and MIF continue to carry INT4, INT8, or INT32 tensors only.
 *
 * This combinational implementation provides deterministic simulation and a
 * synthesizable bit-level reference.  A production target may replace this
 * module with pipelined vendor FP IP while preserving operation_i and the
 * operand/result bit-pattern contract.
 */
module npu_complex_math_core (
  input  logic [3:0]  operation_i,
  input  logic [31:0] operand0_i,
  input  logic [31:0] operand1_i,
  output logic [31:0] result_o
);

  import npu_engine_pkg::*;

  localparam logic [3:0] MATH_SIGMOID = 4'd0;
  localparam logic [3:0] MATH_TANH    = 4'd1;
  localparam logic [3:0] MATH_GELU    = 4'd2;
  localparam logic [3:0] MATH_SILU    = 4'd3;
  localparam logic [3:0] MATH_EXP_NEG = 4'd4;
  localparam logic [3:0] MATH_RSQRT   = 4'd5;
  localparam logic [3:0] MATH_MUL     = 4'd6;
  localparam logic [3:0] MATH_DIV     = 4'd7;
  localparam logic [3:0] MATH_ADD     = 4'd8;
  localparam logic [3:0] MATH_SUB     = 4'd9;

  logic [31:0] sigmoid_argument;

  always_comb begin
    sigmoid_argument = fp32_mul(operand0_i, 32'h3fd9_db23);
    case (operation_i)
      MATH_SIGMOID: result_o = fp32_sigmoid_approx(operand0_i);
      MATH_TANH:    result_o = fp32_tanh_approx(operand0_i);
      MATH_GELU:
        result_o = fp32_mul(
          operand0_i, fp32_sigmoid_approx(sigmoid_argument)
        );
      MATH_SILU:
        result_o = fp32_mul(
          operand0_i, fp32_sigmoid_approx(operand0_i)
        );
      MATH_EXP_NEG: result_o = fp32_exp_neg_approx(operand0_i);
      MATH_RSQRT:   result_o = fp32_rsqrt_approx(operand0_i);
      MATH_MUL:     result_o = fp32_mul(operand0_i, operand1_i);
      MATH_DIV:     result_o = fp32_div(operand0_i, operand1_i);
      MATH_ADD:     result_o = fp32_add(operand0_i, operand1_i);
      MATH_SUB:     result_o = fp32_sub(operand0_i, operand1_i);
      default:      result_o = 32'h7fc0_0000;
    endcase
  end

endmodule
