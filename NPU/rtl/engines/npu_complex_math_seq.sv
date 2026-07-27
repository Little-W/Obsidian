/*
 * Shared sequential FP32 math engine for the NPU Complex Engine.
 *
 * A request executes one elementary or composite operation.  Composite
 * functions use micro-operations and the shared npu_fp32_alu_seq instance.
 * The response is held until accepted.
 */
module npu_complex_math_seq (
  input  logic        clk_i,
  input  logic        reset_n,

  input  logic        req_valid_i,
  output logic        req_ready_o,
  input  logic [3:0]  operation_i,
  input  logic [31:0] operand0_i,
  input  logic [31:0] operand1_i,

  output logic        rsp_valid_o,
  input  logic        rsp_ready_i,
  output logic [31:0] result_o
);

  import npu_engine_pkg::*;

  localparam logic [3:0] MATH_SIGMOID  = 4'd0;
  localparam logic [3:0] MATH_TANH     = 4'd1;
  localparam logic [3:0] MATH_GELU     = 4'd2;
  localparam logic [3:0] MATH_SILU     = 4'd3;
  localparam logic [3:0] MATH_EXP      = 4'd4;
  localparam logic [3:0] MATH_RSQRT    = 4'd5;
  localparam logic [3:0] MATH_MUL      = 4'd6;
  localparam logic [3:0] MATH_DIV      = 4'd7;
  localparam logic [3:0] MATH_ADD      = 4'd8;
  localparam logic [3:0] MATH_SUB      = 4'd9;
  localparam logic [3:0] MATH_RECIP    = 4'd10;
  localparam logic [3:0] MATH_I2F_MUL  = 4'd11;
  localparam logic [3:0] MATH_DIV_APRX = 4'd12;

  localparam logic [1:0] ALU_ADD = 2'd0;
  localparam logic [1:0] ALU_SUB = 2'd1;
  localparam logic [1:0] ALU_MUL = 2'd2;

  typedef enum logic [7:0] {
    ST_IDLE,
    ST_RESPONSE,
    ST_TOP_FINISH,
    ST_BASE_DONE,
    ST_ALU_REQ,
    ST_ALU_RSP,

    ST_I2F_CONVERT,
    ST_I2F_GROUP,
    ST_I2F_BIT,
    ST_I2F_ALIGN,
    ST_I2F_ROUND,
    ST_I2F_MUL_START,

    ST_DIV_AFTER_RECIP,
    ST_DIV_MUL_START,

    ST_EXP_ENTRY,
    ST_EXP_RANGE_MUL_START,
    ST_EXP_RANGE_ROUND,
    ST_EXP_RANGE_SHIFT,
    ST_EXP_RANGE_INCREMENT,
    ST_EXP_RANGE_COMMIT,
    ST_EXP_RANGE_FROM_INT,
    ST_EXP_HI_MUL_START,
    ST_EXP_HI_SUB_START,
    ST_EXP_HI_SUB_DONE,
    ST_EXP_LO_MUL_START,
    ST_EXP_LO_SUB_START,
    ST_EXP_POLY_INIT,
    ST_EXP_POLY_MUL_START,
    ST_EXP_POLY_ADD_START,
    ST_EXP_POLY_ADD_DONE,
    ST_EXP_FINAL_MUL_START,
    ST_EXP_RETURN,

    ST_RECIP_ENTRY,
    ST_RECIP_SUBNORM_MUL_START,
    ST_RECIP_SUBNORM_DONE,
    ST_RECIP_EST_MUL_START,
    ST_RECIP_EST_SUB_START,
    ST_RECIP_EST_SUB_DONE,
    ST_RECIP_NEWTON_PRODUCT_START,
    ST_RECIP_NEWTON_CORR_START,
    ST_RECIP_NEWTON_UPDATE_START,
    ST_RECIP_NEWTON_UPDATE_DONE,
    ST_RECIP_SCALE_CALL,
    ST_RECIP_AFTER_SCALE,

    ST_SCALE_ENTRY,
    ST_SCALE_MUL_DONE,

    ST_SIG_ENTRY,
    ST_SIG_AFTER_EXP,
    ST_SIG_DENOM_ADD_START,
    ST_SIG_DENOM_DONE,
    ST_SIG_AFTER_RECIP,
    ST_SIG_NEG_MUL_START,
    ST_SIG_NEG_DONE,

    ST_TANH_ENTRY,
    ST_TANH_SMALL_SQUARE_START,
    ST_TANH_SMALL_INIT,
    ST_TANH_SMALL_MUL_START,
    ST_TANH_SMALL_ADD_START,
    ST_TANH_SMALL_ADD_DONE,
    ST_TANH_SMALL_FINAL_MUL_START,
    ST_TANH_SMALL_RETURN,
    ST_TANH_EXP_ARG_MUL_START,
    ST_TANH_EXP_CALL,
    ST_TANH_AFTER_EXP,
    ST_TANH_NUM_SUB_START,
    ST_TANH_NUM_DONE,
    ST_TANH_DEN_ADD_START,
    ST_TANH_DEN_DONE,
    ST_TANH_AFTER_RECIP,
    ST_TANH_FINAL_MUL_START,
    ST_TANH_RETURN,

    ST_GELU_ENTRY,
    ST_GELU_SQUARE_START,
    ST_GELU_SHAPE_MUL_START,
    ST_GELU_SHAPE_ADD_START,
    ST_GELU_SHAPE_DONE,
    ST_GELU_KX_MUL_START,
    ST_GELU_INNER_MUL_START,
    ST_GELU_TANH_CALL,
    ST_GELU_AFTER_TANH,
    ST_GELU_HALF_MUL_START,
    ST_GELU_HALF_DONE,
    ST_GELU_SUM_ADD_START,
    ST_GELU_FINAL_MUL_START,
    ST_GELU_RETURN,

    ST_SILU_ENTRY,
    ST_SILU_AFTER_SIGMOID,
    ST_SILU_MUL_START,
    ST_SILU_RETURN,

    ST_RSQRT_ENTRY,
    ST_RSQRT_SUBNORM_MUL_START,
    ST_RSQRT_SUBNORM_DONE,
    ST_RSQRT_PARITY,
    ST_RSQRT_ODD_MUL_START,
    ST_RSQRT_ODD_DONE,
    ST_RSQRT_HALF_MUL_START,
    ST_RSQRT_HALF_DONE,
    ST_RSQRT_NEWTON_SQUARE_START,
    ST_RSQRT_NEWTON_PRODUCT_START,
    ST_RSQRT_NEWTON_CORR_START,
    ST_RSQRT_NEWTON_UPDATE_START,
    ST_RSQRT_NEWTON_UPDATE_DONE,
    ST_RSQRT_SCALE_CALL,
    ST_RSQRT_AFTER_SCALE
  } state_t;

  state_t state_q;
  state_t alu_resume_q;
  state_t return_stack_q [0:3];
  logic [2:0] return_sp_q;

  logic [31:0] result_q;
  logic [31:0] root_x_q;
  logic [31:0] root_y_q;
  logic [31:0] x_q;
  logic [31:0] temp_q;
  logic [31:0] work0_q;
  logic [31:0] work1_q;
  logic [31:0] work2_q;
  logic [31:0] mantissa_q;
  logic [31:0] estimate_q;
  logic [31:0] recip_magnitude_q;
  logic [31:0] polynomial_q;
  logic [31:0] reduced_q;
  logic signed [10:0] exponent_q;
  logic round_sign_q;
  logic [7:0] round_biased_exponent_q;
  logic [23:0] round_significand_q;
  logic [6:0] round_quotient_q;
  logic [23:0] round_remainder_q;
  logic [23:0] round_halfway_q;
  logic [6:0] round_magnitude_q;
  logic i2f_sign_q;
  logic [31:0] i2f_magnitude_q;
  logic [1:0] i2f_group_q;
  logic [7:0] i2f_byte_q;
  logic [4:0] i2f_leading_q;
  logic [7:0] i2f_exponent_q;
  logic [23:0] i2f_significand_q;
  logic [7:0] i2f_remainder_q;
  logic [7:0] i2f_halfway_q;
  logic [2:0] iteration_q;
  logic function_sign_q;
  logic recip_sign_q;

  logic [31:0] scale_value_q;
  logic signed [10:0] scale_remaining_q;
  logic scale_final_q;
  logic [1:0] scale_direction_q;

  logic [1:0] alu_operation_q;
  logic [31:0] alu_operand0_q;
  logic [31:0] alu_operand1_q;
  logic alu_req_valid;
  logic alu_req_ready;
  logic alu_rsp_valid;
  logic alu_rsp_ready;
  logic [31:0] alu_result;

  function automatic logic [31:0] exp_coefficient(
    input logic [2:0] index
  );
    case (index)
      3'd0: return 32'h3c08_8889;
      3'd1: return 32'h3d2a_aaab;
      3'd2: return 32'h3e2a_aaab;
      3'd3: return 32'h3f00_0000;
      3'd4: return 32'h3f80_0000;
      default: return 32'h3f80_0000;
    endcase
  endfunction

  function automatic logic [31:0] fp32_from_exp_integer(
    input logic       sign,
    input logic [6:0] magnitude
  );
    logic [30:0] positive_value;
    begin
      case (magnitude)
        7'd0:  positive_value = 31'h0000_0000;
        7'd1:  positive_value = 31'h3f80_0000;
        7'd2:  positive_value = 31'h4000_0000;
        7'd3:  positive_value = 31'h4040_0000;
        7'd4:  positive_value = 31'h4080_0000;
        7'd5:  positive_value = 31'h40a0_0000;
        7'd6:  positive_value = 31'h40c0_0000;
        7'd7:  positive_value = 31'h40e0_0000;
        7'd8:  positive_value = 31'h4100_0000;
        7'd9:  positive_value = 31'h4110_0000;
        7'd10: positive_value = 31'h4120_0000;
        7'd11: positive_value = 31'h4130_0000;
        7'd12: positive_value = 31'h4140_0000;
        7'd13: positive_value = 31'h4150_0000;
        7'd14: positive_value = 31'h4160_0000;
        7'd15: positive_value = 31'h4170_0000;
        7'd16: positive_value = 31'h4180_0000;
        7'd17: positive_value = 31'h4188_0000;
        7'd18: positive_value = 31'h4190_0000;
        7'd19: positive_value = 31'h4198_0000;
        7'd20: positive_value = 31'h41a0_0000;
        7'd21: positive_value = 31'h41a8_0000;
        7'd22: positive_value = 31'h41b0_0000;
        7'd23: positive_value = 31'h41b8_0000;
        default: positive_value = 31'h0000_0000;
      endcase
      return magnitude == 0
        ? 32'h0000_0000
        : {sign, positive_value};
    end
  endfunction

  function automatic logic [31:0] tanh_small_coefficient(
    input logic [1:0] index
  );
    case (index)
      2'd0: return 32'h3e08_8889;
      2'd1: return 32'hbeaa_aaab;
      default: return 32'h3f80_0000;
    endcase
  endfunction

  task automatic launch_alu(
    input logic [1:0]  operation,
    input logic [31:0] operand0,
    input logic [31:0] operand1,
    input state_t      resume_state
  );
    begin
      alu_operation_q <= operation;
      alu_operand0_q <= operand0;
      alu_operand1_q <= operand1;
      alu_resume_q <= resume_state;
      state_q <= ST_ALU_REQ;
    end
  endtask

  task automatic call_subroutine(
    input state_t      entry_state,
    input state_t      return_state,
    input logic [31:0] input_value
  );
    begin
      return_stack_q[return_sp_q[1:0]] <= return_state;
      return_sp_q <= return_sp_q + 1'b1;
      x_q <= input_value;
      state_q <= entry_state;
    end
  endtask

  task automatic return_subroutine(input logic [31:0] value);
    begin
      temp_q <= value;
      if (return_sp_q == 0) begin
        result_q <= value;
        state_q <= ST_RESPONSE;
      end else begin
        state_q <= return_stack_q[return_sp_q[1:0] - 1'b1];
        return_sp_q <= return_sp_q - 1'b1;
      end
    end
  endtask

  assign req_ready_o = state_q == ST_IDLE;
  assign rsp_valid_o = state_q == ST_RESPONSE;
  assign result_o = result_q;

  assign alu_req_valid = state_q == ST_ALU_REQ;
  assign alu_rsp_ready = state_q == ST_ALU_RSP;

  npu_fp32_alu_seq u_fp32_alu (
    .clk_i(clk_i),
    .reset_n(reset_n),
    .req_valid_i(alu_req_valid),
    .req_ready_o(alu_req_ready),
    .operation_i(alu_operation_q),
    .operand0_i(alu_operand0_q),
    .operand1_i(alu_operand1_q),
    .rsp_valid_o(alu_rsp_valid),
    .rsp_ready_i(alu_rsp_ready),
    .result_o(alu_result)
  );

  always_ff @(posedge clk_i or negedge reset_n) begin
    logic signed [10:0] staged_exponent;
    logic [31:0] magnitude;
    logic [31:0] clamped;
    logic [5:0] i2f_shift;
    logic [7:0] i2f_mask;
    logic [24:0] i2f_rounded;

    if (!reset_n) begin
      state_q <= ST_IDLE;
      alu_resume_q <= ST_IDLE;
      return_stack_q[0] <= ST_IDLE;
      return_stack_q[1] <= ST_IDLE;
      return_stack_q[2] <= ST_IDLE;
      return_stack_q[3] <= ST_IDLE;
      return_sp_q <= 3'd0;
      result_q <= 32'd0;
      root_x_q <= 32'd0;
      root_y_q <= 32'd0;
      x_q <= 32'd0;
      temp_q <= 32'd0;
      work0_q <= 32'd0;
      work1_q <= 32'd0;
      work2_q <= 32'd0;
      mantissa_q <= 32'd0;
      estimate_q <= 32'd0;
      recip_magnitude_q <= 32'd0;
      polynomial_q <= 32'd0;
      reduced_q <= 32'd0;
      exponent_q <= 11'sd0;
      round_sign_q <= 1'b0;
      round_biased_exponent_q <= 8'd0;
      round_significand_q <= 24'd0;
      round_quotient_q <= 7'd0;
      round_remainder_q <= 24'd0;
      round_halfway_q <= 24'd0;
      round_magnitude_q <= 7'd0;
      i2f_sign_q <= 1'b0;
      i2f_magnitude_q <= 32'd0;
      i2f_group_q <= 2'd0;
      i2f_byte_q <= 8'd0;
      i2f_leading_q <= 5'd0;
      i2f_exponent_q <= 8'd0;
      i2f_significand_q <= 24'd0;
      i2f_remainder_q <= 8'd0;
      i2f_halfway_q <= 8'd1;
      iteration_q <= 3'd0;
      function_sign_q <= 1'b0;
      recip_sign_q <= 1'b0;
      scale_value_q <= 32'd0;
      scale_remaining_q <= 11'sd0;
      scale_final_q <= 1'b0;
      scale_direction_q <= 2'd0;
      alu_operation_q <= ALU_ADD;
      alu_operand0_q <= 32'd0;
      alu_operand1_q <= 32'd0;
    end else begin
      case (state_q)
        ST_IDLE: begin
          if (req_valid_i) begin
            root_x_q <= operand0_i;
            root_y_q <= operand1_i;
            x_q <= operand0_i;
            return_sp_q <= 3'd0;
            case (operation_i)
              MATH_SIGMOID,
              MATH_TANH,
              MATH_GELU,
              MATH_SILU,
              MATH_EXP,
              MATH_RSQRT,
              MATH_RECIP: begin
                return_stack_q[0] <= ST_TOP_FINISH;
                return_sp_q <= 3'd1;
                case (operation_i)
                  MATH_SIGMOID: state_q <= ST_SIG_ENTRY;
                  MATH_TANH: state_q <= ST_TANH_ENTRY;
                  MATH_GELU: state_q <= ST_GELU_ENTRY;
                  MATH_SILU: state_q <= ST_SILU_ENTRY;
                  MATH_EXP: state_q <= ST_EXP_ENTRY;
                  MATH_RSQRT: state_q <= ST_RSQRT_ENTRY;
                  default: state_q <= ST_RECIP_ENTRY;
                endcase
              end
              MATH_MUL:
                launch_alu(
                  ALU_MUL, operand0_i, operand1_i, ST_BASE_DONE
                );
              MATH_ADD:
                launch_alu(
                  ALU_ADD, operand0_i, operand1_i, ST_BASE_DONE
                );
              MATH_SUB:
                launch_alu(
                  ALU_SUB, operand0_i, operand1_i, ST_BASE_DONE
                );
              MATH_DIV,
              MATH_DIV_APRX: begin
                return_stack_q[0] <= ST_DIV_AFTER_RECIP;
                return_sp_q <= 3'd1;
                x_q <= operand1_i;
                state_q <= ST_RECIP_ENTRY;
              end
              MATH_I2F_MUL:
                state_q <= ST_I2F_CONVERT;
              default: begin
                result_q <= 32'h7fc0_0000;
                state_q <= ST_RESPONSE;
              end
            endcase
          end
        end

        ST_RESPONSE:
          if (rsp_ready_i)
            state_q <= ST_IDLE;

        ST_TOP_FINISH: begin
          result_q <= temp_q;
          state_q <= ST_RESPONSE;
        end

        ST_BASE_DONE: begin
          result_q <= temp_q;
          state_q <= ST_RESPONSE;
        end

        ST_ALU_REQ:
          if (alu_req_ready)
            state_q <= ST_ALU_RSP;

        ST_ALU_RSP:
          if (alu_rsp_valid) begin
            temp_q <= alu_result;
            state_q <= alu_resume_q;
        end

        ST_I2F_CONVERT: begin
          i2f_sign_q <= root_x_q[31];
          i2f_magnitude_q <=
            root_x_q[31] ?
            (~root_x_q + 1'b1) :
            root_x_q;
          state_q <= ST_I2F_GROUP;
        end

        ST_I2F_GROUP: begin
          if (i2f_magnitude_q == 0) begin
            work0_q <= 32'd0;
            state_q <= ST_I2F_MUL_START;
          end else begin
            if (|i2f_magnitude_q[31:24]) begin
              i2f_group_q <= 2'd3;
              i2f_byte_q <= i2f_magnitude_q[31:24];
            end else if (|i2f_magnitude_q[23:16]) begin
              i2f_group_q <= 2'd2;
              i2f_byte_q <= i2f_magnitude_q[23:16];
            end else if (|i2f_magnitude_q[15:8]) begin
              i2f_group_q <= 2'd1;
              i2f_byte_q <= i2f_magnitude_q[15:8];
            end else begin
              i2f_group_q <= 2'd0;
              i2f_byte_q <= i2f_magnitude_q[7:0];
            end
            state_q <= ST_I2F_BIT;
          end
        end

        ST_I2F_BIT: begin
          casez (i2f_byte_q)
            8'b1???_????:
              i2f_leading_q <= {i2f_group_q, 3'd7};
            8'b01??_????:
              i2f_leading_q <= {i2f_group_q, 3'd6};
            8'b001?_????:
              i2f_leading_q <= {i2f_group_q, 3'd5};
            8'b0001_????:
              i2f_leading_q <= {i2f_group_q, 3'd4};
            8'b0000_1???:
              i2f_leading_q <= {i2f_group_q, 3'd3};
            8'b0000_01??:
              i2f_leading_q <= {i2f_group_q, 3'd2};
            8'b0000_001?:
              i2f_leading_q <= {i2f_group_q, 3'd1};
            default:
              i2f_leading_q <= {i2f_group_q, 3'd0};
          endcase
          state_q <= ST_I2F_ALIGN;
        end

        ST_I2F_ALIGN: begin
          i2f_exponent_q <=
            {3'd0, i2f_leading_q} + 8'd127;
          if (i2f_leading_q <= 5'd23) begin
            i2f_significand_q <=
              24'(i2f_magnitude_q <<
                  (5'd23 - i2f_leading_q));
            i2f_remainder_q <= 8'd0;
            i2f_halfway_q <= 8'd1;
          end else begin
            i2f_shift =
              {1'b0, i2f_leading_q} - 6'd23;
            i2f_significand_q <=
              24'(i2f_magnitude_q >> i2f_shift);
            i2f_mask =
              (8'd1 << i2f_shift) - 1'b1;
            i2f_remainder_q <=
              i2f_magnitude_q[7:0] & i2f_mask;
            i2f_halfway_q <=
              8'd1 << (i2f_shift - 1'b1);
          end
          state_q <= ST_I2F_ROUND;
        end

        ST_I2F_ROUND: begin
          i2f_rounded =
            {1'b0, i2f_significand_q} + {
              24'd0,
              i2f_remainder_q > i2f_halfway_q ||
              (i2f_remainder_q == i2f_halfway_q &&
               i2f_significand_q[0])
            };
          if (i2f_rounded[24])
            work0_q <= {
              i2f_sign_q,
              i2f_exponent_q + 1'b1,
              i2f_rounded[23:1]
            };
          else
            work0_q <= {
              i2f_sign_q,
              i2f_exponent_q,
              i2f_rounded[22:0]
            };
          state_q <= ST_I2F_MUL_START;
        end

        ST_I2F_MUL_START:
          launch_alu(
            ALU_MUL, work0_q, root_y_q, ST_BASE_DONE
          );

        ST_DIV_AFTER_RECIP:
          state_q <= ST_DIV_MUL_START;

        ST_DIV_MUL_START:
          launch_alu(
            ALU_MUL, root_x_q, temp_q, ST_BASE_DONE
          );

        ST_EXP_ENTRY: begin
          if (fp32_is_nan(x_q) ||
              fp32_less_than(x_q, 32'hc180_0000))
            return_subroutine(32'd0);
          else begin
            clamped =
              fp32_less_than(32'h4180_0000, x_q) ?
              32'h4180_0000 : x_q;
            work0_q <= clamped;
            state_q <= ST_EXP_RANGE_MUL_START;
          end
        end

        ST_EXP_RANGE_MUL_START:
          launch_alu(
            ALU_MUL,
            work0_q,
            32'h3fb8_aa3b,
            ST_EXP_RANGE_ROUND
          );

        ST_EXP_RANGE_ROUND: begin
          /*
           * ST_EXP_ENTRY limits x to [-16, 16].  Multiplication by
           * log2(e) therefore gives a finite magnitude below 24.  Capture
           * the FP32 fields here, then perform the shift, nearest-even
           * increment, and sign application in separate cycles.  The
           * seven-bit integer datapath covers every reachable result
           * (-23 through 23) without the former 64-bit carry chains.
           */
          round_sign_q <= temp_q[31];
          round_biased_exponent_q <= temp_q[30:23];
          round_significand_q <=
            temp_q[30:23] == 0 ?
            {1'b0, temp_q[22:0]} :
            {1'b1, temp_q[22:0]};
          state_q <= ST_EXP_RANGE_SHIFT;
        end

        ST_EXP_RANGE_SHIFT: begin
          round_quotient_q <= 7'd0;
          round_remainder_q <= 24'd0;
          round_halfway_q <= 24'd1;
          case (round_biased_exponent_q)
            8'd126: begin
              round_remainder_q <= round_significand_q;
              round_halfway_q <= 24'h80_0000;
            end
            8'd127: begin
              round_quotient_q <=
                {6'd0, round_significand_q[23]};
              round_remainder_q <=
                round_significand_q & 24'h7f_ffff;
              round_halfway_q <= 24'h40_0000;
            end
            8'd128: begin
              round_quotient_q <=
                {5'd0, round_significand_q[23:22]};
              round_remainder_q <=
                round_significand_q & 24'h3f_ffff;
              round_halfway_q <= 24'h20_0000;
            end
            8'd129: begin
              round_quotient_q <=
                {4'd0, round_significand_q[23:21]};
              round_remainder_q <=
                round_significand_q & 24'h1f_ffff;
              round_halfway_q <= 24'h10_0000;
            end
            8'd130: begin
              round_quotient_q <=
                {3'd0, round_significand_q[23:20]};
              round_remainder_q <=
                round_significand_q & 24'h0f_ffff;
              round_halfway_q <= 24'h08_0000;
            end
            8'd131: begin
              round_quotient_q <=
                {2'd0, round_significand_q[23:19]};
              round_remainder_q <=
                round_significand_q & 24'h07_ffff;
              round_halfway_q <= 24'h04_0000;
            end
            default: begin end
          endcase
          state_q <= ST_EXP_RANGE_INCREMENT;
        end

        ST_EXP_RANGE_INCREMENT: begin
          round_magnitude_q <= round_quotient_q + {
            6'd0,
            round_remainder_q > round_halfway_q ||
            (round_remainder_q == round_halfway_q &&
             round_quotient_q[0])
          };
          state_q <= ST_EXP_RANGE_COMMIT;
        end

        ST_EXP_RANGE_COMMIT: begin
          staged_exponent =
            round_sign_q ?
            -$signed({4'd0, round_magnitude_q}) :
            $signed({4'd0, round_magnitude_q});
          exponent_q <= staged_exponent;
          state_q <= ST_EXP_RANGE_FROM_INT;
        end

        ST_EXP_RANGE_FROM_INT: begin
          work1_q <= fp32_from_exp_integer(
            round_sign_q, round_magnitude_q
          );
          state_q <= ST_EXP_HI_MUL_START;
        end

        ST_EXP_HI_MUL_START:
          launch_alu(
            ALU_MUL,
            work1_q,
            32'h3f31_7180,
            ST_EXP_HI_SUB_START
          );

        ST_EXP_HI_SUB_START:
          launch_alu(
            ALU_SUB,
            work0_q,
            temp_q,
            ST_EXP_HI_SUB_DONE
          );

        ST_EXP_HI_SUB_DONE: begin
          reduced_q <= temp_q;
          state_q <= ST_EXP_LO_MUL_START;
        end

        ST_EXP_LO_MUL_START:
          launch_alu(
            ALU_MUL,
            work1_q,
            32'h3717_f7d1,
            ST_EXP_LO_SUB_START
          );

        ST_EXP_LO_SUB_START:
          launch_alu(
            ALU_SUB,
            reduced_q,
            temp_q,
            ST_EXP_POLY_INIT
          );

        ST_EXP_POLY_INIT: begin
          reduced_q <= temp_q;
          polynomial_q <= 32'h3ab6_0b61;
          iteration_q <= 3'd0;
          state_q <= ST_EXP_POLY_MUL_START;
        end

        ST_EXP_POLY_MUL_START:
          launch_alu(
            ALU_MUL,
            reduced_q,
            polynomial_q,
            ST_EXP_POLY_ADD_START
          );

        ST_EXP_POLY_ADD_START:
          launch_alu(
            ALU_ADD,
            exp_coefficient(iteration_q),
            temp_q,
            ST_EXP_POLY_ADD_DONE
          );

        ST_EXP_POLY_ADD_DONE: begin
          polynomial_q <= temp_q;
          if (iteration_q == 3'd5)
            state_q <= ST_EXP_FINAL_MUL_START;
          else begin
            iteration_q <= iteration_q + 1'b1;
            state_q <= ST_EXP_POLY_MUL_START;
          end
        end

        ST_EXP_FINAL_MUL_START:
          launch_alu(
            ALU_MUL,
            polynomial_q,
            fp32_pow2_integer(integer'($signed(exponent_q))),
            ST_EXP_RETURN
          );

        ST_EXP_RETURN:
          return_subroutine(temp_q);

        ST_RECIP_ENTRY: begin
          magnitude = fp32_abs(x_q);
          recip_sign_q <= x_q[31];
          recip_magnitude_q <= magnitude;
          if (fp32_is_zero(magnitude))
            return_subroutine(fp32_maximum_finite(x_q[31]));
          else if (magnitude[30:23] == 8'hff) begin
            if (magnitude[22:0] != 0)
              return_subroutine(32'd0);
            else
              return_subroutine({x_q[31], 31'd0});
          end else if (magnitude[30:23] == 0)
            state_q <= ST_RECIP_SUBNORM_MUL_START;
          else begin
            exponent_q <=
              $signed({3'd0, magnitude[30:23]}) - 11'sd127;
            mantissa_q <= {1'b0, 8'h7f, magnitude[22:0]};
            state_q <= ST_RECIP_EST_MUL_START;
          end
        end

        ST_RECIP_SUBNORM_MUL_START:
          launch_alu(
            ALU_MUL,
            recip_magnitude_q,
            32'h4b80_0000,
            ST_RECIP_SUBNORM_DONE
          );

        ST_RECIP_SUBNORM_DONE: begin
          exponent_q <=
            $signed({3'd0, temp_q[30:23]}) -
            11'sd127 -
            11'sd24;
          mantissa_q <= {1'b0, 8'h7f, temp_q[22:0]};
          state_q <= ST_RECIP_EST_MUL_START;
        end

        ST_RECIP_EST_MUL_START:
          launch_alu(
            ALU_MUL,
            32'h3ef0_f0f1,
            mantissa_q,
            ST_RECIP_EST_SUB_START
          );

        ST_RECIP_EST_SUB_START:
          launch_alu(
            ALU_SUB,
            32'h3fb4_b4b5,
            temp_q,
            ST_RECIP_EST_SUB_DONE
          );

        ST_RECIP_EST_SUB_DONE: begin
          estimate_q <= temp_q;
          iteration_q <= 3'd0;
          state_q <= ST_RECIP_NEWTON_PRODUCT_START;
        end

        ST_RECIP_NEWTON_PRODUCT_START:
          launch_alu(
            ALU_MUL,
            mantissa_q,
            estimate_q,
            ST_RECIP_NEWTON_CORR_START
          );

        ST_RECIP_NEWTON_CORR_START:
          launch_alu(
            ALU_SUB,
            32'h4000_0000,
            temp_q,
            ST_RECIP_NEWTON_UPDATE_START
          );

        ST_RECIP_NEWTON_UPDATE_START:
          launch_alu(
            ALU_MUL,
            estimate_q,
            temp_q,
            ST_RECIP_NEWTON_UPDATE_DONE
          );

        ST_RECIP_NEWTON_UPDATE_DONE: begin
          estimate_q <= temp_q;
          if (iteration_q == 3'd2)
            state_q <= ST_RECIP_SCALE_CALL;
          else begin
            iteration_q <= iteration_q + 1'b1;
            state_q <= ST_RECIP_NEWTON_PRODUCT_START;
          end
        end

        ST_RECIP_SCALE_CALL: begin
          scale_value_q <= estimate_q;
          scale_remaining_q <= -exponent_q;
          return_stack_q[return_sp_q[1:0]] <=
            ST_RECIP_AFTER_SCALE;
          return_sp_q <= return_sp_q + 1'b1;
          state_q <= ST_SCALE_ENTRY;
        end

        ST_RECIP_AFTER_SCALE:
          return_subroutine(
            fp32_with_sign(temp_q, recip_sign_q)
          );

        ST_SCALE_ENTRY: begin
          if (scale_remaining_q > 11'sd127) begin
            scale_final_q <= 1'b0;
            scale_direction_q <= 2'd1;
            launch_alu(
              ALU_MUL,
              scale_value_q,
              fp32_pow2_integer(127),
              ST_SCALE_MUL_DONE
            );
          end else if (scale_remaining_q < -11'sd149) begin
            scale_final_q <= 1'b0;
            scale_direction_q <= 2'd2;
            launch_alu(
              ALU_MUL,
              scale_value_q,
              fp32_pow2_integer(-149),
              ST_SCALE_MUL_DONE
            );
          end else begin
            scale_final_q <= 1'b1;
            scale_direction_q <= 2'd0;
            launch_alu(
              ALU_MUL,
              scale_value_q,
              fp32_pow2_integer(
                integer'($signed(scale_remaining_q))
              ),
              ST_SCALE_MUL_DONE
            );
          end
        end

        ST_SCALE_MUL_DONE: begin
          if (scale_final_q) begin
            if (fp32_is_inf(temp_q))
              return_subroutine(
                fp32_maximum_finite(temp_q[31])
              );
            else
              return_subroutine(temp_q);
          end else if (scale_direction_q == 2'd1) begin
            if (fp32_is_inf(temp_q))
              return_subroutine(
                fp32_maximum_finite(temp_q[31])
              );
            else begin
              scale_value_q <= temp_q;
              scale_remaining_q <=
                scale_remaining_q - 11'sd127;
              state_q <= ST_SCALE_ENTRY;
            end
          end else if (fp32_is_zero(temp_q))
            return_subroutine(temp_q);
          else begin
            scale_value_q <= temp_q;
            scale_remaining_q <=
              scale_remaining_q + 11'sd149;
            state_q <= ST_SCALE_ENTRY;
          end
        end

        ST_SIG_ENTRY: begin
          if (fp32_is_nan(x_q))
            return_subroutine(32'd0);
          else if (fp32_less_than(32'h4180_0000, x_q))
            return_subroutine(32'h3f80_0000);
          else if (fp32_less_than(x_q, 32'hc180_0000))
            return_subroutine(32'd0);
          else begin
            function_sign_q <= x_q[31];
            call_subroutine(
              ST_EXP_ENTRY,
              ST_SIG_AFTER_EXP,
              fp32_neg(fp32_abs(x_q))
            );
          end
        end

        ST_SIG_AFTER_EXP: begin
          work0_q <= temp_q;
          state_q <= ST_SIG_DENOM_ADD_START;
        end

        ST_SIG_DENOM_ADD_START:
          launch_alu(
            ALU_ADD,
            32'h3f80_0000,
            work0_q,
            ST_SIG_DENOM_DONE
          );

        ST_SIG_DENOM_DONE:
          call_subroutine(
            ST_RECIP_ENTRY,
            ST_SIG_AFTER_RECIP,
            temp_q
          );

        ST_SIG_AFTER_RECIP: begin
          if (!function_sign_q)
            return_subroutine(temp_q);
          else
            state_q <= ST_SIG_NEG_MUL_START;
        end

        ST_SIG_NEG_MUL_START:
          launch_alu(
            ALU_MUL,
            work0_q,
            temp_q,
            ST_SIG_NEG_DONE
          );

        ST_SIG_NEG_DONE:
          return_subroutine(temp_q);

        ST_TANH_ENTRY: begin
          if (fp32_is_nan(x_q))
            return_subroutine(32'd0);
          else begin
            magnitude = fp32_abs(x_q);
            function_sign_q <= x_q[31];
            work0_q <= magnitude;
            if (fp32_less_than(32'h4100_0000, magnitude))
              return_subroutine({x_q[31], 8'h7f, 23'd0});
            else if (fp32_less_than(magnitude, 32'h3e80_0000))
              state_q <= ST_TANH_SMALL_SQUARE_START;
            else
              state_q <= ST_TANH_EXP_ARG_MUL_START;
          end
        end

        ST_TANH_SMALL_SQUARE_START:
          launch_alu(
            ALU_MUL,
            work0_q,
            work0_q,
            ST_TANH_SMALL_INIT
          );

        ST_TANH_SMALL_INIT: begin
          work1_q <= temp_q;
          polynomial_q <= 32'hbd5d_0dd1;
          iteration_q <= 3'd0;
          state_q <= ST_TANH_SMALL_MUL_START;
        end

        ST_TANH_SMALL_MUL_START:
          launch_alu(
            ALU_MUL,
            work1_q,
            polynomial_q,
            ST_TANH_SMALL_ADD_START
          );

        ST_TANH_SMALL_ADD_START:
          launch_alu(
            ALU_ADD,
            tanh_small_coefficient(iteration_q[1:0]),
            temp_q,
            ST_TANH_SMALL_ADD_DONE
          );

        ST_TANH_SMALL_ADD_DONE: begin
          polynomial_q <= temp_q;
          if (iteration_q == 3'd2)
            state_q <= ST_TANH_SMALL_FINAL_MUL_START;
          else begin
            iteration_q <= iteration_q + 1'b1;
            state_q <= ST_TANH_SMALL_MUL_START;
          end
        end

        ST_TANH_SMALL_FINAL_MUL_START:
          launch_alu(
            ALU_MUL,
            work0_q,
            polynomial_q,
            ST_TANH_SMALL_RETURN
          );

        ST_TANH_SMALL_RETURN:
          return_subroutine(
            fp32_with_sign(temp_q, function_sign_q)
          );

        ST_TANH_EXP_ARG_MUL_START:
          launch_alu(
            ALU_MUL,
            32'hc000_0000,
            work0_q,
            ST_TANH_EXP_CALL
          );

        ST_TANH_EXP_CALL:
          call_subroutine(
            ST_EXP_ENTRY,
            ST_TANH_AFTER_EXP,
            temp_q
          );

        ST_TANH_AFTER_EXP: begin
          work1_q <= temp_q;
          state_q <= ST_TANH_NUM_SUB_START;
        end

        ST_TANH_NUM_SUB_START:
          launch_alu(
            ALU_SUB,
            32'h3f80_0000,
            work1_q,
            ST_TANH_NUM_DONE
          );

        ST_TANH_NUM_DONE: begin
          work2_q <= temp_q;
          state_q <= ST_TANH_DEN_ADD_START;
        end

        ST_TANH_DEN_ADD_START:
          launch_alu(
            ALU_ADD,
            32'h3f80_0000,
            work1_q,
            ST_TANH_DEN_DONE
          );

        ST_TANH_DEN_DONE:
          call_subroutine(
            ST_RECIP_ENTRY,
            ST_TANH_AFTER_RECIP,
            temp_q
          );

        ST_TANH_AFTER_RECIP:
          state_q <= ST_TANH_FINAL_MUL_START;

        ST_TANH_FINAL_MUL_START:
          launch_alu(
            ALU_MUL,
            work2_q,
            temp_q,
            ST_TANH_RETURN
          );

        ST_TANH_RETURN:
          return_subroutine(
            fp32_with_sign(temp_q, function_sign_q)
          );

        ST_GELU_ENTRY: begin
          if (fp32_is_nan(x_q))
            return_subroutine(32'd0);
          else if (fp32_less_than(32'h4100_0000, x_q))
            return_subroutine(x_q);
          else if (fp32_less_than(x_q, 32'hc100_0000))
            return_subroutine(32'd0);
          else
            state_q <= ST_GELU_SQUARE_START;
        end

        ST_GELU_SQUARE_START:
          launch_alu(
            ALU_MUL,
            root_x_q,
            root_x_q,
            ST_GELU_SHAPE_MUL_START
          );

        ST_GELU_SHAPE_MUL_START:
          launch_alu(
            ALU_MUL,
            32'h3d37_2713,
            temp_q,
            ST_GELU_SHAPE_ADD_START
          );

        ST_GELU_SHAPE_ADD_START:
          launch_alu(
            ALU_ADD,
            32'h3f80_0000,
            temp_q,
            ST_GELU_SHAPE_DONE
          );

        ST_GELU_SHAPE_DONE: begin
          work0_q <= temp_q;
          state_q <= ST_GELU_KX_MUL_START;
        end

        ST_GELU_KX_MUL_START:
          launch_alu(
            ALU_MUL,
            32'h3f4c_422a,
            root_x_q,
            ST_GELU_INNER_MUL_START
          );

        ST_GELU_INNER_MUL_START:
          launch_alu(
            ALU_MUL,
            temp_q,
            work0_q,
            ST_GELU_TANH_CALL
          );

        ST_GELU_TANH_CALL:
          call_subroutine(
            ST_TANH_ENTRY,
            ST_GELU_AFTER_TANH,
            temp_q
          );

        ST_GELU_AFTER_TANH: begin
          work1_q <= temp_q;
          state_q <= ST_GELU_HALF_MUL_START;
        end

        ST_GELU_HALF_MUL_START:
          launch_alu(
            ALU_MUL,
            32'h3f00_0000,
            root_x_q,
            ST_GELU_HALF_DONE
          );

        ST_GELU_HALF_DONE: begin
          work2_q <= temp_q;
          state_q <= ST_GELU_SUM_ADD_START;
        end

        ST_GELU_SUM_ADD_START:
          launch_alu(
            ALU_ADD,
            32'h3f80_0000,
            work1_q,
            ST_GELU_FINAL_MUL_START
          );

        ST_GELU_FINAL_MUL_START:
          launch_alu(
            ALU_MUL,
            work2_q,
            temp_q,
            ST_GELU_RETURN
          );

        ST_GELU_RETURN:
          return_subroutine(temp_q);

        ST_SILU_ENTRY: begin
          if (fp32_is_nan(x_q))
            return_subroutine(32'd0);
          else if (fp32_less_than(32'h4180_0000, x_q))
            return_subroutine(x_q);
          else if (fp32_less_than(x_q, 32'hc180_0000))
            return_subroutine(32'd0);
          else
            call_subroutine(
              ST_SIG_ENTRY,
              ST_SILU_AFTER_SIGMOID,
              x_q
            );
        end

        ST_SILU_AFTER_SIGMOID:
          state_q <= ST_SILU_MUL_START;

        ST_SILU_MUL_START:
          launch_alu(
            ALU_MUL,
            root_x_q,
            temp_q,
            ST_SILU_RETURN
          );

        ST_SILU_RETURN:
          return_subroutine(temp_q);

        ST_RSQRT_ENTRY: begin
          magnitude = fp32_abs(x_q);
          work0_q <= magnitude;
          if (magnitude[30:23] == 8'hff) begin
            if (magnitude[22:0] != 0 || !x_q[31])
              return_subroutine(32'd0);
            else
              return_subroutine(32'h7f7f_ffff);
          end else if (x_q[31] || fp32_is_zero(magnitude))
            return_subroutine(32'h7f7f_ffff);
          else if (magnitude[30:23] == 0)
            state_q <= ST_RSQRT_SUBNORM_MUL_START;
          else begin
            exponent_q <=
              $signed({3'd0, magnitude[30:23]}) - 11'sd127;
            mantissa_q <= {1'b0, 8'h7f, magnitude[22:0]};
            state_q <= ST_RSQRT_PARITY;
          end
        end

        ST_RSQRT_SUBNORM_MUL_START:
          launch_alu(
            ALU_MUL,
            work0_q,
            32'h4b80_0000,
            ST_RSQRT_SUBNORM_DONE
          );

        ST_RSQRT_SUBNORM_DONE: begin
          exponent_q <=
            $signed({3'd0, temp_q[30:23]}) -
            11'sd127 -
            11'sd24;
          mantissa_q <= {1'b0, 8'h7f, temp_q[22:0]};
          state_q <= ST_RSQRT_PARITY;
        end

        ST_RSQRT_PARITY: begin
          if ((exponent_q % 2) != 0)
            state_q <= ST_RSQRT_ODD_MUL_START;
          else
            state_q <= ST_RSQRT_HALF_MUL_START;
        end

        ST_RSQRT_ODD_MUL_START:
          launch_alu(
            ALU_MUL,
            mantissa_q,
            32'h4000_0000,
            ST_RSQRT_ODD_DONE
          );

        ST_RSQRT_ODD_DONE: begin
          mantissa_q <= temp_q;
          exponent_q <= exponent_q - 1'b1;
          state_q <= ST_RSQRT_HALF_MUL_START;
        end

        ST_RSQRT_HALF_MUL_START:
          launch_alu(
            ALU_MUL,
            32'h3f00_0000,
            mantissa_q,
            ST_RSQRT_HALF_DONE
          );

        ST_RSQRT_HALF_DONE: begin
          work1_q <= temp_q;
          estimate_q <= 32'h5f37_5a86 - (mantissa_q >> 1);
          iteration_q <= 3'd0;
          state_q <= ST_RSQRT_NEWTON_SQUARE_START;
        end

        ST_RSQRT_NEWTON_SQUARE_START:
          launch_alu(
            ALU_MUL,
            estimate_q,
            estimate_q,
            ST_RSQRT_NEWTON_PRODUCT_START
          );

        ST_RSQRT_NEWTON_PRODUCT_START:
          launch_alu(
            ALU_MUL,
            work1_q,
            temp_q,
            ST_RSQRT_NEWTON_CORR_START
          );

        ST_RSQRT_NEWTON_CORR_START:
          launch_alu(
            ALU_SUB,
            32'h3fc0_0000,
            temp_q,
            ST_RSQRT_NEWTON_UPDATE_START
          );

        ST_RSQRT_NEWTON_UPDATE_START:
          launch_alu(
            ALU_MUL,
            estimate_q,
            temp_q,
            ST_RSQRT_NEWTON_UPDATE_DONE
          );

        ST_RSQRT_NEWTON_UPDATE_DONE: begin
          estimate_q <= temp_q;
          if (iteration_q == 3'd2)
            state_q <= ST_RSQRT_SCALE_CALL;
          else begin
            iteration_q <= iteration_q + 1'b1;
            state_q <= ST_RSQRT_NEWTON_SQUARE_START;
          end
        end

        ST_RSQRT_SCALE_CALL: begin
          scale_value_q <= estimate_q;
          scale_remaining_q <= -(exponent_q / 2);
          return_stack_q[return_sp_q[1:0]] <=
            ST_RSQRT_AFTER_SCALE;
          return_sp_q <= return_sp_q + 1'b1;
          state_q <= ST_SCALE_ENTRY;
        end

        ST_RSQRT_AFTER_SCALE:
          return_subroutine(temp_q);

        default:
          state_q <= ST_IDLE;
      endcase
    end
  end

endmodule
