/*
 * Shared variable-latency IEEE-754 binary32 add/subtract/multiply unit.
 *
 * The arithmetic matches npu_engine_pkg::fp32_add/fp32_sub/fp32_mul.
 * Work that was previously expanded into long combinational expressions is
 * split across registered states.  Subnormal normalization intentionally
 * shifts one bit per cycle so no 23- or 26-level combinational cascade is
 * present in the synthesized data path.
 */
module npu_fp32_alu_seq (
  input  logic        clk_i,
  input  logic        reset_n,

  input  logic        req_valid_i,
  output logic        req_ready_o,
  input  logic [1:0]  operation_i,
  input  logic [31:0] operand0_i,
  input  logic [31:0] operand1_i,

  output logic        rsp_valid_o,
  input  logic        rsp_ready_i,
  output logic [31:0] result_o
);

  import npu_engine_pkg::*;

  localparam logic [1:0] ALU_ADD = 2'd0;
  localparam logic [1:0] ALU_SUB = 2'd1;

  typedef enum logic [3:0] {
    ST_IDLE,
    ST_ADD_PREPARE,
    ST_ADD_ALIGN,
    ST_ADD_COMBINE,
    ST_ADD_NORMALIZE,
    ST_ADD_ROUND,
    ST_MUL_NORMALIZE,
    ST_MUL_PRODUCT,
    ST_MUL_PREPARE,
    ST_MUL_EXTRACT,
    ST_MUL_COMPARE,
    ST_MUL_ROUND,
    ST_RESPONSE
  } state_t;

  state_t state_q;
  logic [31:0] result_q;

  logic [8:0]  add_large_exp_q;
  logic [8:0]  add_small_exp_q;
  logic [23:0] add_large_mant_q;
  logic [23:0] add_small_mant_q;
  logic        add_large_sign_q;
  logic        add_small_sign_q;
  logic [27:0] add_large_ext_q;
  logic [27:0] add_small_ext_q;
  logic [27:0] add_aligned_small_q;
  logic [27:0] add_work_q;

  logic        mul_sign_q;
  logic [23:0] mul_lhs_mant_q;
  logic [23:0] mul_rhs_mant_q;
  logic signed [10:0] mul_lhs_exp_q;
  logic signed [10:0] mul_rhs_exp_q;
  logic signed [10:0] mul_result_exp_q;
  logic [47:0] mul_product_q;
  logic signed [11:0] mul_round_exp_q;
  logic [5:0]  mul_round_shift_q;
  logic        mul_round_subnormal_q;
  logic        mul_round_zero_q;
  logic [23:0] mul_round_mantissa_q;
  logic [47:0] mul_round_remainder_q;
  logic [47:0] mul_round_halfway_q;
  logic        mul_round_increment_q;

  assign req_ready_o = state_q == ST_IDLE;
  assign rsp_valid_o = state_q == ST_RESPONSE;
  assign result_o = result_q;

  always_ff @(posedge clk_i or negedge reset_n) begin
    logic [31:0] rhs_effective;
    logic [7:0] lhs_exp;
    logic [7:0] rhs_exp;
    logic [23:0] lhs_mant;
    logic [23:0] rhs_mant;
    logic lhs_larger;
    logic [8:0] lhs_order_exp;
    logic [8:0] rhs_order_exp;
    logic [27:0] discarded_mask;
    logic [27:0] aligned_small;
    logic sticky;
    logic [27:0] combined;
    logic [23:0] mantissa;
    logic [24:0] rounded;
    logic increment;
    logic [47:0] remainder_mask;
    logic signed [11:0] result_unbiased;
    logic signed [12:0] adjusted_shift;
    integer shift_amount;

    if (!reset_n) begin
      state_q <= ST_IDLE;
    end else begin
      case (state_q)
        ST_IDLE: begin
          if (req_valid_i) begin
            rhs_effective =
              operation_i == ALU_SUB ?
              fp32_neg(operand1_i) : operand1_i;
            if (operation_i == ALU_ADD ||
                operation_i == ALU_SUB) begin
              if (fp32_is_nan(operand0_i) ||
                  fp32_is_nan(rhs_effective)) begin
                result_q <= 32'h7fc0_0000;
                state_q <= ST_RESPONSE;
              end else if (fp32_is_inf(operand0_i) ||
                           fp32_is_inf(rhs_effective)) begin
                if (fp32_is_inf(operand0_i) &&
                    fp32_is_inf(rhs_effective) &&
                    operand0_i[31] != rhs_effective[31])
                  result_q <= 32'h7fc0_0000;
                else
                  result_q <= fp32_is_inf(operand0_i) ?
                              operand0_i : rhs_effective;
                state_q <= ST_RESPONSE;
              end else if (fp32_is_zero(operand0_i)) begin
                result_q <= rhs_effective;
                state_q <= ST_RESPONSE;
              end else if (fp32_is_zero(rhs_effective)) begin
                result_q <= operand0_i;
                state_q <= ST_RESPONSE;
              end else begin
                lhs_exp = operand0_i[30:23];
                rhs_exp = rhs_effective[30:23];
                lhs_mant = lhs_exp == 0 ?
                           {1'b0, operand0_i[22:0]} :
                           {1'b1, operand0_i[22:0]};
                rhs_mant = rhs_exp == 0 ?
                           {1'b0, rhs_effective[22:0]} :
                           {1'b1, rhs_effective[22:0]};
                lhs_order_exp =
                  {1'b0, (lhs_exp == 0 ? 8'd1 : lhs_exp)};
                rhs_order_exp =
                  {1'b0, (rhs_exp == 0 ? 8'd1 : rhs_exp)};
                lhs_larger =
                  lhs_order_exp > rhs_order_exp ||
                  (lhs_exp == rhs_exp && lhs_mant >= rhs_mant);
                if (lhs_larger) begin
                  add_large_exp_q <= lhs_order_exp;
                  add_small_exp_q <= rhs_order_exp;
                  add_large_mant_q <= lhs_mant;
                  add_small_mant_q <= rhs_mant;
                  add_large_sign_q <= operand0_i[31];
                  add_small_sign_q <= rhs_effective[31];
                end else begin
                  add_large_exp_q <= rhs_order_exp;
                  add_small_exp_q <= lhs_order_exp;
                  add_large_mant_q <= rhs_mant;
                  add_small_mant_q <= lhs_mant;
                  add_large_sign_q <= rhs_effective[31];
                  add_small_sign_q <= operand0_i[31];
                end
                state_q <= ST_ADD_PREPARE;
              end
            end else begin
              if (fp32_is_nan(operand0_i) ||
                  fp32_is_nan(operand1_i) ||
                  ((fp32_is_inf(operand0_i) &&
                    fp32_is_zero(operand1_i)) ||
                   (fp32_is_inf(operand1_i) &&
                    fp32_is_zero(operand0_i)))) begin
                result_q <= 32'h7fc0_0000;
                state_q <= ST_RESPONSE;
              end else if (fp32_is_inf(operand0_i) ||
                           fp32_is_inf(operand1_i)) begin
                result_q <= {
                  operand0_i[31] ^ operand1_i[31],
                  8'hff,
                  23'd0
                };
                state_q <= ST_RESPONSE;
              end else if (fp32_is_zero(operand0_i) ||
                           fp32_is_zero(operand1_i)) begin
                result_q <= {
                  operand0_i[31] ^ operand1_i[31],
                  31'd0
                };
                state_q <= ST_RESPONSE;
              end else begin
                mul_sign_q <= operand0_i[31] ^ operand1_i[31];
                mul_lhs_mant_q <=
                  operand0_i[30:23] == 0 ?
                  {1'b0, operand0_i[22:0]} :
                  {1'b1, operand0_i[22:0]};
                mul_rhs_mant_q <=
                  operand1_i[30:23] == 0 ?
                  {1'b0, operand1_i[22:0]} :
                  {1'b1, operand1_i[22:0]};
                mul_lhs_exp_q <=
                  operand0_i[30:23] == 0 ?
                  -11'sd126 :
                  $signed({3'd0, operand0_i[30:23]}) - 11'sd127;
                mul_rhs_exp_q <=
                  operand1_i[30:23] == 0 ?
                  -11'sd126 :
                  $signed({3'd0, operand1_i[30:23]}) - 11'sd127;
                state_q <= ST_MUL_NORMALIZE;
              end
            end
          end
        end

        ST_ADD_PREPARE: begin
          add_large_ext_q <= {1'b0, add_large_mant_q, 3'b000};
          add_small_ext_q <= {1'b0, add_small_mant_q, 3'b000};
          state_q <= ST_ADD_ALIGN;
        end

        ST_ADD_ALIGN: begin
          shift_amount =
            integer'(add_large_exp_q) -
            integer'(add_small_exp_q);
          if (shift_amount >= 28)
            aligned_small =
              add_small_ext_q == 0 ? 28'd0 : 28'd1;
          else begin
            aligned_small =
              add_small_ext_q >> shift_amount;
            discarded_mask =
              shift_amount == 0 ? 28'd0 :
              ((28'd1 << shift_amount) - 1);
            sticky =
              |(add_small_ext_q & discarded_mask);
            aligned_small[0] = aligned_small[0] | sticky;
          end
          add_aligned_small_q <= aligned_small;
          state_q <= ST_ADD_COMBINE;
        end

        ST_ADD_COMBINE: begin
          if (add_large_sign_q == add_small_sign_q) begin
            combined = add_large_ext_q + add_aligned_small_q;
            if (combined[27]) begin
              sticky = combined[0];
              combined = combined >> 1;
              combined[0] = combined[0] | sticky;
              add_large_exp_q <= add_large_exp_q + 1'b1;
            end
            add_work_q <= combined;
            state_q <= ST_ADD_ROUND;
          end else begin
            combined = add_large_ext_q - add_aligned_small_q;
            if (combined == 0) begin
              result_q <= 32'd0;
              state_q <= ST_RESPONSE;
            end else begin
              add_work_q <= combined;
              state_q <= ST_ADD_NORMALIZE;
            end
          end
        end

        ST_ADD_NORMALIZE: begin
          if (!add_work_q[26] && add_large_exp_q > 1) begin
            add_work_q <= add_work_q << 1;
            add_large_exp_q <= add_large_exp_q - 1'b1;
          end else
            state_q <= ST_ADD_ROUND;
        end

        ST_ADD_ROUND: begin
          mantissa = add_work_q[26:3];
          increment = add_work_q[2] &&
                      (add_work_q[1] ||
                       add_work_q[0] ||
                       mantissa[0]);
          rounded = {1'b0, mantissa} + {24'd0, increment};
          if (rounded[24]) begin
            mantissa = rounded[24:1];
            add_large_exp_q <= add_large_exp_q + 1'b1;
            if (add_large_exp_q + 1'b1 >= 255)
              result_q <= {add_large_sign_q, 8'hff, 23'd0};
            else
              result_q <= {
                add_large_sign_q,
                add_large_exp_q[7:0] + 1'b1,
                mantissa[22:0]
              };
          end else begin
            mantissa = rounded[23:0];
            if (add_large_exp_q >= 255)
              result_q <= {add_large_sign_q, 8'hff, 23'd0};
            else if (add_large_exp_q == 1 && !mantissa[23])
              result_q <= {
                add_large_sign_q,
                8'd0,
                mantissa[22:0]
              };
            else
              result_q <= {
                add_large_sign_q,
                add_large_exp_q[7:0],
                mantissa[22:0]
              };
          end
          state_q <= ST_RESPONSE;
        end

        ST_MUL_NORMALIZE: begin
          if (!mul_lhs_mant_q[23]) begin
            mul_lhs_mant_q <= mul_lhs_mant_q << 1;
            mul_lhs_exp_q <= mul_lhs_exp_q - 1'b1;
          end
          if (!mul_rhs_mant_q[23]) begin
            mul_rhs_mant_q <= mul_rhs_mant_q << 1;
            mul_rhs_exp_q <= mul_rhs_exp_q - 1'b1;
          end
          if (mul_lhs_mant_q[23] && mul_rhs_mant_q[23])
            state_q <= ST_MUL_PRODUCT;
        end

        ST_MUL_PRODUCT: begin
          mul_product_q <= mul_lhs_mant_q * mul_rhs_mant_q;
          mul_result_exp_q <= mul_lhs_exp_q + mul_rhs_exp_q;
          state_q <= ST_MUL_PREPARE;
        end

        ST_MUL_PREPARE: begin
          result_unbiased =
            $signed({mul_result_exp_q[10], mul_result_exp_q});
          if (mul_product_q[47])
            result_unbiased = result_unbiased + 12'sd1;
          mul_round_exp_q <= result_unbiased;
          mul_round_subnormal_q <= result_unbiased < -12'sd126;
          mul_round_zero_q <= 1'b0;
          if (result_unbiased < -12'sd126) begin
            adjusted_shift =
              $signed({
                7'd0,
                mul_product_q[47] ? 6'd24 : 6'd23
              }) +
              (-13'sd126 -
               $signed({
                 result_unbiased[11],
                 result_unbiased
               }));
            if (adjusted_shift > 13'sd48) begin
              mul_round_shift_q <= 6'd48;
              mul_round_zero_q <= 1'b1;
            end else
              mul_round_shift_q <= adjusted_shift[5:0];
          end else
            mul_round_shift_q <=
              mul_product_q[47] ? 6'd24 : 6'd23;
          state_q <= ST_MUL_EXTRACT;
        end

        ST_MUL_EXTRACT: begin
          if (mul_round_zero_q) begin
            mul_round_mantissa_q <= 24'd0;
            mul_round_remainder_q <= 48'd0;
            mul_round_halfway_q <= 48'd1;
          end else begin
            mul_round_mantissa_q <=
              24'(mul_product_q >> mul_round_shift_q);
            if (mul_round_shift_q == 6'd48)
              remainder_mask = 48'hffff_ffff_ffff;
            else
              remainder_mask =
                (48'd1 << mul_round_shift_q) - 1'b1;
            mul_round_remainder_q <=
              mul_product_q & remainder_mask;
            mul_round_halfway_q <=
              48'd1 << (mul_round_shift_q - 1'b1);
          end
          state_q <= ST_MUL_COMPARE;
        end

        ST_MUL_COMPARE: begin
          mul_round_increment_q <=
            !mul_round_zero_q &&
            (mul_round_remainder_q > mul_round_halfway_q ||
             (mul_round_remainder_q == mul_round_halfway_q &&
              mul_round_mantissa_q[0]));
          state_q <= ST_MUL_ROUND;
        end

        ST_MUL_ROUND: begin
          if (mul_round_zero_q)
            result_q <= {mul_sign_q, 31'd0};
          else begin
            rounded =
              {1'b0, mul_round_mantissa_q} +
              {24'd0, mul_round_increment_q};
            if (mul_round_subnormal_q) begin
              if (rounded[23])
                result_q <= {mul_sign_q, 8'd1, 23'd0};
              else
                result_q <= {
                  mul_sign_q,
                  8'd0,
                  rounded[22:0]
                };
            end else begin
              result_unbiased = mul_round_exp_q;
              mantissa = rounded[23:0];
              if (rounded[24]) begin
                mantissa = rounded[24:1];
                result_unbiased = result_unbiased + 12'sd1;
              end
              if (result_unbiased > 12'sd127)
                result_q <= {mul_sign_q, 8'hff, 23'd0};
              else
                result_q <= {
                  mul_sign_q,
                  8'(result_unbiased + 12'sd127),
                  mantissa[22:0]
                };
            end
          end
          state_q <= ST_RESPONSE;
        end

        ST_RESPONSE:
          if (rsp_ready_i)
            state_q <= ST_IDLE;

        default:
          state_q <= ST_IDLE;
      endcase
    end
  end

endmodule
