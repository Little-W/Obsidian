module npu_complex_engine (
  input  logic          clk_i,
  input  logic          reset_n,

  input  logic          task_valid_i,
  output logic          task_ready_o,
  input  logic [7:0]    opcode_i,
  input  logic [11:0]   command_id_i,
  input  logic [2047:0] desc_i,

  output logic          done_valid_o,
  input  logic          done_ready_i,
  output logic [7:0]    done_status_o,
  output logic [47:0]   done_fault_addr_o,
  output logic [63:0]   done_progress_o,

  output logic          l1_req_valid_o,
  input  logic          l1_req_ready_i,
  output logic          l1_req_write_o,
  output logic [19:0]   l1_req_addr_o,
  output logic [63:0]   l1_req_wdata_o,
  output logic [7:0]    l1_req_wstrb_o,
  input  logic          l1_rsp_valid_i,
  output logic          l1_rsp_ready_o,
  input  logic [63:0]   l1_rsp_rdata_i,
  input  logic [2:0]    l1_rsp_status_i
);

  import npu_engine_pkg::*;

  localparam logic [3:0] PH_ELEMENT   = 4'd0;
  localparam logic [3:0] PH_SOFT_MAX  = 4'd1;
  localparam logic [3:0] PH_SOFT_SUM  = 4'd2;
  localparam logic [3:0] PH_SOFT_OUT  = 4'd3;
  localparam logic [3:0] PH_NORM_ACC  = 4'd4;
  localparam logic [3:0] PH_NORM_OUT  = 4'd5;
  localparam logic [3:0] PH_STAT_ACC  = 4'd6;
  localparam logic [3:0] PH_STAT_OUT  = 4'd7;
  localparam logic [3:0] PH_NORM_VAR  = 4'd8;

  typedef enum logic [4:0] {
    ST_IDLE,
    ST_CHECK,
    ST_ROW_INIT,
    ST_VLEN_CHECK,
    ST_VLEN_REQ,
    ST_VLEN_RSP,
    ST_ELEMENT_BEGIN,
    ST_ADDR_PREP,
    ST_MASK_REQ,
    ST_MASK_RSP,
    ST_SRC0_REQ,
    ST_SRC0_RSP,
    ST_SRC1_REQ,
    ST_SRC1_RSP,
    ST_SRC2_REQ,
    ST_SRC2_RSP,
    ST_COMPUTE,
    ST_STAT_SQUARE,
    ST_STAT_ACCUM,
    ST_MATH_REQ,
    ST_MATH_RSP,
    ST_F2I_ROUND,
    ST_F2I_MAG,
    ST_F2I_SIGN,
    ST_F2I_OFFSET,
    ST_F2I_FINISH,
    ST_ADVANCE,
    ST_RMW_REQ,
    ST_RMW_RSP,
    ST_WRITE_REQ,
    ST_WRITE_RSP,
    ST_DONE
  } state_t;

  typedef enum logic [5:0] {
    MA_SRC0_I2F,
    MA_SRC1_I2F,
    MA_SRC2_I2F,
    MA_ACT_VALUE,
    MA_ADD_VALUE,
    MA_SOFT_DIFF,
    MA_SOFT_EXP,
    MA_SOFT_VALUE,
    MA_LANE_ADD,
    MA_NORM_SQUARE,
    MA_NORM_CENTER,
    MA_NORM_BASE,
    MA_NORM_SCALED,
    MA_NORM_VALUE,
    MA_WELFORD_DELTA,
    MA_WELFORD_COUNT_FP,
    MA_WELFORD_COUNT_INV,
    MA_WELFORD_MEAN_STEP,
    MA_WELFORD_MEAN_NEW,
    MA_WELFORD_X_DIFF,
    MA_WELFORD_M2_TERM,
    MA_WELFORD_DONE,
    MA_TOTAL_01,
    MA_TOTAL_23,
    MA_TOTAL_FINAL,
    MA_COUNT_FP,
    MA_COUNT_INV,
    MA_MEAN_DONE,
    MA_VARIANCE,
    MA_VARIANCE_EPSILON,
    MA_INVSTD,
    MA_F2I
  } math_action_t;

  state_t state_q;
  logic [3:0] phase_q;
  logic [2047:0] desc_q;
  logic [7:0] opcode_q;
  logic [31:0] row_q;
  logic [31:0] col_q;
  logic [31:0] row_key_length_q;
  logic [63:0] src0_addr_q;
  logic [63:0] src1_addr_q;
  logic [63:0] src2_addr_q;
  logic [63:0] current_dst_addr_q;
  logic [47:0] mask_addr_q;
  logic [63:0] current_valid_length_addr_q;
  logic src0_high_nibble_q;
  logic src1_high_nibble_q;
  logic src2_high_nibble_q;
  logic dst_high_nibble_q;
  logic derived_mask_valid_q;
  logic [31:0] causal_query_position_q;
  logic mask_value_q;
  logic valid_seen_q;
  logic signed [63:0] src0_value_q;
  logic signed [63:0] src1_value_q;
  logic signed [63:0] src2_value_q;
  logic signed [63:0] stat_sum_q;
  logic signed [63:0] stat_sumsq_q;
  logic signed [63:0] stat_max_q;
  logic signed [63:0] stat_square_q;
  logic stat_sumsq_overflow_q;
  logic stat_square_last_q;
  logic [7:0] stat_square_overflow_mode_q;
  logic [47:0] stat_dst_addr_q;
  logic [31:0] fp_row_sum_q;
  logic [31:0] fp_row_sumsq_q;
  logic [31:0] fp_lane_sum_q [0:3];
  logic [31:0] fp_row_max_q;
  logic [31:0] fp_row_mean_q;
  logic [31:0] fp_row_invstd_q;
  logic [31:0] fp_row_inverse_q;
  logic signed [63:0] result_q;
  logic [63:0] rmw_beat_q;
  logic [7:0] status_q;
  logic [47:0] fault_addr_q;
  logic [63:0] progress_q;

  wire [7:0] desc_version = desc_q[7:0];
  wire [7:0] desc_type = desc_q[15:8];
  wire [15:0] desc_bytes = desc_q[31:16];
  wire [63:0] src0_base = desc_q[64 +: 64];
  wire [63:0] src1_base = desc_q[128 +: 64];
  wire [63:0] src2_base = desc_q[192 +: 64];
  wire [63:0] dst_base = desc_q[256 +: 64];
  wire [43:0] aux0_addr_high = desc_q[340 +: 44];
  wire [43:0] aux1_addr_high = desc_q[404 +: 44];
  wire [31:0] numeric_cfg = desc_q[448 +: 32];
  wire [1:0] src0_dtype = numeric_cfg[1:0];
  wire [1:0] src1_dtype = numeric_cfg[3:2];
  wire [1:0] src2_dtype = numeric_cfg[5:4];
  wire [1:0] dst_dtype = numeric_cfg[7:6];
  wire [1:0] round_mode = numeric_cfg[11:10];
  wire saturate_enable = numeric_cfg[12];
  wire [1:0] scale_mode = numeric_cfg[14:13];
  wire zero_point_enable = numeric_cfg[15];
  wire internal_fp32_enable = numeric_cfg[16];
  wire unused_command_id = ^command_id_i;
  wire unused_result_upper = ^result_q[63:32];
  wire unused_desc_fields = ^{
    desc_q[2047:1632],
    desc_q[1407:1280],
    desc_q[511:480],
    desc_q[403:384],
    desc_q[339:320],
    desc_q[63:32]
  };

  wire [31:0] rows = desc_q[16'h40 * 8 +: 32];
  wire [31:0] length = desc_q[16'h44 * 8 +: 32];
  wire [31:0] valid_length = desc_q[16'h48 * 8 +: 32];
  wire [31:0] function_mode = desc_q[16'h4c * 8 +: 32];
  wire [31:0] src0_row_stride = desc_q[16'h50 * 8 +: 32];
  wire [31:0] src1_row_stride = desc_q[16'h54 * 8 +: 32];
  wire [31:0] src2_row_stride = desc_q[16'h58 * 8 +: 32];
  wire [31:0] dst_row_stride = desc_q[16'h5c * 8 +: 32];
  wire [63:0] mask_base = desc_q[16'h60 * 8 +: 64];
  wire [31:0] mask_row_stride = desc_q[16'h68 * 8 +: 32];
  wire [31:0] mask_mode = desc_q[16'h6c * 8 +: 32];
  wire [31:0] src0_scale_bits = desc_q[16'h70 * 8 +: 32];
  wire [31:0] src1_scale_bits = desc_q[16'h74 * 8 +: 32];
  wire [31:0] src2_scale_bits = desc_q[16'h78 * 8 +: 32];
  wire [31:0] dst_scale_bits = desc_q[16'h7c * 8 +: 32];
  wire signed [31:0] src0_zero_point =
    desc_q[16'h80 * 8 +: 32];
  wire signed [31:0] src1_zero_point =
    desc_q[16'h84 * 8 +: 32];
  wire signed [31:0] src2_zero_point =
    desc_q[16'h88 * 8 +: 32];
  wire signed [31:0] dst_zero_point =
    desc_q[16'h8c * 8 +: 32];
  wire [31:0] epsilon_bits = desc_q[16'h90 * 8 +: 32];
  wire [31:0] input_clip_min_bits = desc_q[16'h94 * 8 +: 32];
  wire [31:0] input_clip_max_bits = desc_q[16'h98 * 8 +: 32];
  wire [7:0] approx_mode = desc_q[16'h9c * 8 +: 8];
  wire [7:0] overflow_mode = desc_q[16'h9d * 8 +: 8];
  wire [7:0] all_mask_mode = desc_q[16'h9e * 8 +: 8];
  wire [7:0] stats_mode = desc_q[16'h9f * 8 +: 8];
  wire [31:0] query_position_base =
    desc_q[16'hb4 * 8 +: 32];
  wire [31:0] key_position_base =
    desc_q[16'hb8 * 8 +: 32];
  wire [31:0] query_position_step =
    desc_q[16'hbc * 8 +: 32];
  wire [31:0] scratch_request_elems =
    desc_q[16'hb0 * 8 +: 32];
  wire [63:0] valid_length_base =
    desc_q[16'hc0 * 8 +: 64];
  wire [31:0] valid_length_stride =
    desc_q[16'hc8 * 8 +: 32];

  function automatic logic opcode_known(input logic [7:0] opcode);
    return opcode == NPU_COMPLEX_ACT ||
           opcode == NPU_COMPLEX_SOFTMAX ||
           opcode == NPU_COMPLEX_NORM ||
           opcode == NPU_COMPLEX_STAT ||
           opcode == NPU_COMPLEX_ADD_RESCALE;
  endfunction

  function automatic logic function_matches(
    input logic [7:0] opcode,
    input logic [31:0] function_value
  );
    case (opcode)
      NPU_COMPLEX_ACT:
        return function_value <= 3;
      NPU_COMPLEX_SOFTMAX:
        return function_value == 4;
      NPU_COMPLEX_NORM:
        return function_value == 5 || function_value == 6;
      NPU_COMPLEX_STAT:
        return function_value >= 7 && function_value <= 9;
      NPU_COMPLEX_ADD_RESCALE:
        return function_value == 12;
      default:
        return 1'b0;
    endcase
  endfunction

  function automatic logic [63:0] contiguous_element_addr(
    input logic [63:0] base,
    input logic [31:0] row,
    input logic [31:0] col,
    input logic [31:0] row_stride,
    input logic [1:0] dtype,
    input logic feature_only
  );
    logic [63:0] row_offset;
    logic [63:0] col_offset;
    begin
      row_offset = feature_only ? 64'd0 : row * row_stride;
      if (dtype == NPU_DTYPE_INT4)
        col_offset = {32'd0, col} >> 1;
      else
        col_offset = col * dtype_bytes(dtype);
      return base + row_offset + col_offset;
    end
  endfunction

  wire [31:0] active_columns =
    (row_q + 1 == rows) ? valid_length : length;
  wire [63:0] src0_addr = contiguous_element_addr(
    src0_base, row_q, col_q, src0_row_stride, src0_dtype, 1'b0
  );
  wire norm_parameter_phase =
    opcode_q == NPU_COMPLEX_NORM && phase_q == PH_NORM_OUT;
  wire [63:0] src1_addr = contiguous_element_addr(
    src1_base, row_q, col_q, src1_row_stride, src1_dtype,
    norm_parameter_phase
  );
  wire [63:0] src2_addr = contiguous_element_addr(
    src2_base, row_q, col_q, src2_row_stride, src2_dtype,
    norm_parameter_phase
  );
  wire [63:0] normal_dst_addr = contiguous_element_addr(
    dst_base, row_q, col_q, dst_row_stride, dst_dtype, 1'b0
  );
  wire [63:0] current_dst_addr =
    phase_q == PH_STAT_OUT ?
    {16'd0, stat_dst_addr_q} : normal_dst_addr;
  wire [47:0] mask_addr =
    mask_base[47:0] +
    ({16'd0, row_q} * {16'd0, mask_row_stride}) +
    {16'd0, col_q};
  wire [63:0] current_valid_length_addr =
    valid_length_base + row_q * valid_length_stride;
  /*
   * The engine's externally visible fault address is 48 bits.  Base-address
   * checks constrain accesses to the implemented L1 range; retain 64-bit
   * arithmetic for descriptor compatibility and explicitly consume the
   * unreported high bits here.
   */
  wire unused_address_upper = ^{
    src0_addr_q[63:48],
    src1_addr_q[63:48],
    src2_addr_q[63:48],
    current_dst_addr_q[63:48],
    current_valid_length_addr_q[63:48]
  };

  wire src0_high_nibble = src0_dtype == NPU_DTYPE_INT4 && col_q[0];
  wire src1_high_nibble = src1_dtype == NPU_DTYPE_INT4 && col_q[0];
  wire src2_high_nibble = src2_dtype == NPU_DTYPE_INT4 && col_q[0];
  wire dst_high_nibble =
    dst_dtype == NPU_DTYPE_INT4 && col_q[0] &&
    phase_q != PH_STAT_OUT;

  wire causal_valid =
    key_position_base + col_q <=
    causal_query_position_q;
  wire derived_mask_valid =
    mask_mode == 0 ? 1'b1 :
    mask_mode == 2 ? causal_valid :
    mask_mode == 3 ? col_q < row_key_length_q :
    mask_value_q;

  function automatic logic crosses_beat(
    input logic [2:0] byte_lane,
    input logic [1:0] dtype
  );
    return (dtype == NPU_DTYPE_INT32 && byte_lane > 3'd4) ||
           (dtype == NPU_DTYPE_INT16 && byte_lane > 3'd6);
  endfunction

  localparam logic [3:0] MATH_EXP      = 4'd4;
  localparam logic [3:0] MATH_RSQRT    = 4'd5;
  localparam logic [3:0] MATH_MUL      = 4'd6;
  localparam logic [3:0] MATH_ADD      = 4'd8;
  localparam logic [3:0] MATH_SUB      = 4'd9;
  localparam logic [3:0] MATH_RECIP    = 4'd10;
  localparam logic [3:0] MATH_I2F_MUL  = 4'd11;
  localparam logic [3:0] MATH_DIV_APRX = 4'd12;

  logic [3:0] math_operation_q;
  logic [31:0] math_operand0_q;
  logic [31:0] math_operand1_q;
  math_action_t math_action_q;
  logic math_req_ready;
  logic math_rsp_valid;
  logic [31:0] math_rsp_result;
  logic [31:0] fp_src0_q;
  logic [31:0] fp_src1_q;
  logic [31:0] fp_src2_q;
  logic [31:0] fp_active_inverse_q;
  logic [31:0] fp_tmp0_q;
  logic [31:0] fp_tmp1_q;
  logic [31:0] fp_tmp2_q;
  logic [31:0] fp_lane_selected;
  logic [63:0] f2i_quotient_q;
  logic [63:0] f2i_remainder_q;
  logic [63:0] f2i_halfway_q;
  logic [63:0] f2i_magnitude_q;
  logic signed [63:0] f2i_rounded_q;
  logic signed [63:0] f2i_output_integer_q;
  logic signed [31:0] f2i_dst_zero_point_q;
  logic [47:0] f2i_dst_addr_q;
  logic [7:0] f2i_overflow_mode_q;
  logic [3:0] f2i_phase_q;
  logic [1:0] f2i_round_mode_q;
  logic [1:0] f2i_dst_dtype_q;
  logic f2i_sign_q;
  logic f2i_force_limit_q;
  logic f2i_exceptional_q;
  logic f2i_dst_high_nibble_q;
  logic f2i_increment_q;

  wire signed [63:0] src0_centered_integer =
    src0_value_q -
    {{32{src0_zero_point[31]}}, src0_zero_point};
  wire signed [63:0] src1_centered_integer =
    src1_value_q -
    {{32{src1_zero_point[31]}}, src1_zero_point};
  wire signed [63:0] src2_centered_integer =
    src2_value_q -
    {{32{src2_zero_point[31]}}, src2_zero_point};
  wire signed [31:0] stat_square_operand =
    $signed(src0_value_q[31:0]);
  wire signed [63:0] stat_square_product =
    stat_square_operand * stat_square_operand;
  wire unused_centered_upper = ^{
    src0_centered_integer[63:32],
    src1_centered_integer[63:32],
    src2_centered_integer[63:32]
  };

  always_comb begin
    case (col_q[1:0])
      2'd0: fp_lane_selected = fp_lane_sum_q[0];
      2'd1: fp_lane_selected = fp_lane_sum_q[1];
      2'd2: fp_lane_selected = fp_lane_sum_q[2];
      default: fp_lane_selected = fp_lane_sum_q[3];
    endcase
  end

  npu_complex_math_seq u_math_seq (
    .clk_i(clk_i),
    .reset_n(reset_n),
    .req_valid_i(state_q == ST_MATH_REQ),
    .req_ready_o(math_req_ready),
    .operation_i(math_operation_q),
    .operand0_i(math_operand0_q),
    .operand1_i(math_operand1_q),
    .rsp_valid_o(math_rsp_valid),
    .rsp_ready_i(state_q == ST_MATH_RSP),
    .result_o(math_rsp_result)
  );

  task automatic issue_math(
    input logic [3:0]  operation,
    input logic [31:0] operand0,
    input logic [31:0] operand1,
    input math_action_t action
  );
    begin
      math_operation_q <= operation;
      math_operand0_q <= operand0;
      math_operand1_q <= operand1;
      math_action_q <= action;
      state_q <= ST_MATH_REQ;
    end
  endtask

  task automatic issue_output_conversion(
    input logic [31:0] value
  );
    begin
      issue_math(
        MATH_DIV_APRX,
        value,
        dst_scale_bits,
        MA_F2I
      );
    end
  endtask

  function automatic logic phase_writes_tensor(input logic [3:0] phase);
    return phase == PH_ELEMENT || phase == PH_SOFT_OUT ||
           phase == PH_NORM_OUT || phase == PH_STAT_OUT;
  endfunction

  task automatic fail_task(
    input logic [7:0] fail_status,
    input logic [47:0] fail_addr
  );
    begin
      status_q <= fail_status;
      fault_addr_q <= fail_addr;
      state_q <= ST_DONE;
    end
  endtask

  always_comb begin
    task_ready_o = (state_q == ST_IDLE);
    done_valid_o = (state_q == ST_DONE);
    done_status_o = status_q;
    done_fault_addr_o = fault_addr_q;
    done_progress_o = progress_q;

    l1_req_valid_o = 1'b0;
    l1_req_write_o = 1'b0;
    l1_req_addr_o = 20'd0;
    l1_req_wdata_o = 64'd0;
    l1_req_wstrb_o = 8'd0;
    l1_rsp_ready_o = 1'b0;

    case (state_q)
      ST_VLEN_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o =
          {current_valid_length_addr_q[19:3], 3'b000};
      end
      ST_MASK_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {mask_addr_q[19:3], 3'b000};
      end
      ST_SRC0_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {src0_addr_q[19:3], 3'b000};
      end
      ST_SRC1_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {src1_addr_q[19:3], 3'b000};
      end
      ST_SRC2_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {src2_addr_q[19:3], 3'b000};
      end
      ST_RMW_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {current_dst_addr_q[19:3], 3'b000};
      end
      ST_WRITE_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_write_o = 1'b1;
        l1_req_addr_o = {current_dst_addr_q[19:3], 3'b000};
        l1_req_wdata_o = store_element_data(
          rmw_beat_q, result_q[31:0], current_dst_addr_q[2:0],
          dst_high_nibble_q, dst_dtype
        );
        l1_req_wstrb_o =
          store_element_strb(current_dst_addr_q[2:0], dst_dtype);
      end
      ST_VLEN_RSP,
      ST_MASK_RSP,
      ST_SRC0_RSP,
      ST_SRC1_RSP,
      ST_SRC2_RSP,
      ST_RMW_RSP,
      ST_WRITE_RSP: l1_rsp_ready_o = 1'b1;
      default: begin end
    endcase
  end

  always_ff @(posedge clk_i or negedge reset_n) begin
    logic signed [63:0] next_stat;
    logic signed [63:0] valid_length_value;
    logic [31:0] activation_value;
    logic [31:0] softmax_difference;
    logic [31:0] nonnegative_variance;
    logic [23:0] f2i_significand;
    logic [63:0] f2i_quotient;
    logic [63:0] f2i_remainder;
    logic [63:0] f2i_remainder_mask;
    logic [63:0] f2i_halfway;
    logic f2i_force_limit;
    logic f2i_increment;
    integer f2i_unbiased;
    integer f2i_shift_amount;
    logic output_overflow;
    logic current_valid;
    if (!reset_n) begin
      state_q <= ST_IDLE;
      phase_q <= PH_ELEMENT;
      status_q <= NPU_STATUS_SUCCESS;
      fault_addr_q <= 48'd0;
      progress_q <= 64'd0;
      causal_query_position_q <= 32'd0;
      src0_addr_q <= 64'd0;
      src1_addr_q <= 64'd0;
      src2_addr_q <= 64'd0;
      current_dst_addr_q <= 64'd0;
      mask_addr_q <= 48'd0;
      current_valid_length_addr_q <= 64'd0;
      src0_high_nibble_q <= 1'b0;
      src1_high_nibble_q <= 1'b0;
      src2_high_nibble_q <= 1'b0;
      dst_high_nibble_q <= 1'b0;
      derived_mask_valid_q <= 1'b0;
    end else begin
      case (state_q)
        ST_IDLE: begin
          status_q <= NPU_STATUS_SUCCESS;
          fault_addr_q <= 48'd0;
          progress_q <= 64'd0;
          if (task_valid_i) begin
            desc_q <= desc_i;
            opcode_q <= opcode_i;
            state_q <= ST_CHECK;
          end
        end

        ST_CHECK: begin
          if (!opcode_known(opcode_q))
            fail_task(NPU_STATUS_ILLEGAL_OPCODE, 48'd0);
          else if (desc_version != 8'h01 || desc_type != 8'h04 ||
                   desc_bytes != 16'd256)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (!dtype_valid(src0_dtype) || !dtype_valid(src1_dtype) ||
                   !dtype_valid(src2_dtype) || !dtype_valid(dst_dtype) ||
                   numeric_cfg[9:8] != 0 ||
                   numeric_cfg[31:17] != 0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (!function_matches(opcode_q, function_mode) ||
                   approx_mode != 0 || overflow_mode > 2 ||
                   all_mask_mode > 1 || stats_mode > 1 ||
                   mask_mode > 3 || scratch_request_elems > 4096 ||
                   zero_point_enable ||
                   src0_zero_point != 0 || src1_zero_point != 0 ||
                   src2_zero_point != 0 || dst_zero_point != 0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (stats_mode != 0 &&
                   !(opcode_q == NPU_COMPLEX_NORM &&
                     function_mode == 5))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (src0_base[63:20] != 0 || dst_base[63:20] != 0 ||
                   ((opcode_q == NPU_COMPLEX_ADD_RESCALE ||
                     opcode_q == NPU_COMPLEX_NORM) &&
                    src1_base[63:20] != 0) ||
                   (opcode_q == NPU_COMPLEX_NORM &&
                    function_mode == 5 && src2_base[63:20] != 0) ||
                   (mask_mode == 1 && mask_base[63:20] != 0) ||
                   (mask_mode == 3 &&
                    valid_length_base[63:20] != 0) ||
                   aux0_addr_high != 0 || aux1_addr_high != 0)
            fail_task(NPU_STATUS_ADDR_FAULT, 48'd0);
          else if ((rows == 0 || length == 0) &&
                   valid_length != 0)
            fail_task(NPU_STATUS_BAD_SHAPE, 48'd0);
          else if (rows != 0 && length != 0 &&
                   (valid_length == 0 || valid_length > length))
            fail_task(NPU_STATUS_BAD_SHAPE, 48'd0);
          else if (rows != 0 && length == 0 &&
                   !(opcode_q == NPU_COMPLEX_ACT ||
                     opcode_q == NPU_COMPLEX_ADD_RESCALE))
            fail_task(NPU_STATUS_BAD_SHAPE, 48'd0);
          else if (opcode_q == NPU_COMPLEX_STAT &&
                   dst_dtype != NPU_DTYPE_INT32)
            fail_task(NPU_STATUS_DTYPE_UNSUPPORTED, 48'd0);
          else if (opcode_q == NPU_COMPLEX_STAT &&
                   (scale_mode != 0 || internal_fp32_enable ||
                    saturate_enable != (overflow_mode == 0)))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (opcode_q != NPU_COMPLEX_STAT &&
                   (scale_mode != 1 || !internal_fp32_enable ||
                    !saturate_enable || overflow_mode != 0))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (opcode_q != NPU_COMPLEX_STAT &&
                   (!fp32_finite_positive(src0_scale_bits) ||
                    !fp32_finite_positive(dst_scale_bits) ||
                    ((opcode_q == NPU_COMPLEX_ADD_RESCALE ||
                      opcode_q == NPU_COMPLEX_NORM) &&
                     !fp32_finite_positive(src1_scale_bits)) ||
                    (opcode_q == NPU_COMPLEX_NORM &&
                     function_mode == 5 &&
                     !fp32_finite_positive(src2_scale_bits))))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (opcode_q == NPU_COMPLEX_NORM &&
                   !fp32_finite_positive(epsilon_bits))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (opcode_q != NPU_COMPLEX_NORM &&
                   epsilon_bits != 0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if ((opcode_q == NPU_COMPLEX_ACT ||
                    opcode_q == NPU_COMPLEX_SOFTMAX) &&
                   (!fp32_less_than(
                      input_clip_min_bits, input_clip_max_bits
                    ) ||
                    input_clip_min_bits[30:23] == 8'hff ||
                    input_clip_max_bits[30:23] == 8'hff))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (!(opcode_q == NPU_COMPLEX_ACT ||
                     opcode_q == NPU_COMPLEX_SOFTMAX) &&
                   (input_clip_min_bits != 0 ||
                    input_clip_max_bits != 0))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (opcode_q != NPU_COMPLEX_SOFTMAX &&
                   all_mask_mode != 0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (opcode_q == NPU_COMPLEX_SOFTMAX &&
                   ((mask_mode == 1 &&
                     (mask_row_stride < length)) ||
                    (mask_mode == 3 &&
                     (valid_length_stride < 4 ||
                      valid_length_stride[1:0] != 0))))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (opcode_q != NPU_COMPLEX_SOFTMAX &&
                   mask_mode != 0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (opcode_q == NPU_COMPLEX_NORM &&
                   function_mode == 6 && src2_base != 0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (rows == 0 || length == 0) begin
            status_q <= NPU_STATUS_SUCCESS;
            state_q <= ST_DONE;
          end else begin
            row_q <= 0;
            col_q <= 0;
            stat_dst_addr_q <= dst_base[47:0];
            state_q <= ST_ROW_INIT;
          end
        end

        ST_ROW_INIT: begin
          col_q <= 0;
          current_valid_length_addr_q <=
            current_valid_length_addr;
          causal_query_position_q <=
            query_position_base + row_q * query_position_step;
          mask_value_q <= 1'b1;
          valid_seen_q <= 1'b0;
          stat_sum_q <= 64'sd0;
          stat_sumsq_q <= 64'sd0;
          stat_max_q <= -64'sh3fff_ffff_ffff_ffff;
          stat_sumsq_overflow_q <= 1'b0;
          fp_row_sum_q <= 32'd0;
          fp_row_sumsq_q <= 32'd0;
          fp_lane_sum_q[0] <= 32'd0;
          fp_lane_sum_q[1] <= 32'd0;
          fp_lane_sum_q[2] <= 32'd0;
          fp_lane_sum_q[3] <= 32'd0;
          fp_row_max_q <= 32'hff80_0000;
          fp_row_mean_q <= 32'd0;
          fp_row_invstd_q <= 32'd0;
          fp_row_inverse_q <= 32'd0;
          fp_src0_q <= 32'd0;
          fp_src1_q <= 32'd0;
          fp_src2_q <= 32'd0;
          fp_active_inverse_q <= 32'd0;
          fp_tmp0_q <= 32'd0;
          fp_tmp1_q <= 32'd0;
          fp_tmp2_q <= 32'd0;
          if (opcode_q == NPU_COMPLEX_SOFTMAX)
            phase_q <= PH_SOFT_MAX;
          else if (opcode_q == NPU_COMPLEX_NORM)
            phase_q <= PH_NORM_ACC;
          else if (opcode_q == NPU_COMPLEX_STAT)
            phase_q <= PH_STAT_ACC;
          else
            phase_q <= PH_ELEMENT;

          if (opcode_q == NPU_COMPLEX_SOFTMAX &&
              mask_mode == 3) begin
            state_q <= ST_VLEN_CHECK;
          end else begin
            row_key_length_q <= length;
            state_q <= ST_ELEMENT_BEGIN;
          end
        end

        ST_VLEN_CHECK:
          if (crosses_beat(current_valid_length_addr_q[2:0],
                           NPU_DTYPE_INT32))
            fail_task(
              NPU_STATUS_ADDR_FAULT,
              current_valid_length_addr_q[47:0]
            );
          else
            state_q <= ST_VLEN_REQ;

        ST_VLEN_REQ:
          if (l1_req_ready_i)
            state_q <= ST_VLEN_RSP;

        ST_VLEN_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        current_valid_length_addr_q[47:0]);
            else begin
              valid_length_value = load_element(
                l1_rsp_rdata_i, current_valid_length_addr_q[2:0],
                1'b0, NPU_DTYPE_INT32
              );
              row_key_length_q <= valid_length_value[31:0];
              if (valid_length_value < 0 ||
                  valid_length_value > {32'd0, length})
                fail_task(NPU_STATUS_BAD_SHAPE,
                          current_valid_length_addr_q[47:0]);
              else
                state_q <= ST_ELEMENT_BEGIN;
            end
          end

        ST_ELEMENT_BEGIN: begin
          mask_value_q <= 1'b1;
          rmw_beat_q <= 64'd0;
          src0_addr_q <= src0_addr;
          src1_addr_q <= src1_addr;
          src2_addr_q <= src2_addr;
          current_dst_addr_q <= current_dst_addr;
          mask_addr_q <= mask_addr;
          src0_high_nibble_q <= src0_high_nibble;
          src1_high_nibble_q <= src1_high_nibble;
          src2_high_nibble_q <= src2_high_nibble;
          dst_high_nibble_q <= dst_high_nibble;
          derived_mask_valid_q <= derived_mask_valid;
          state_q <= ST_ADDR_PREP;
        end

        ST_ADDR_PREP: begin
          if (opcode_q == NPU_COMPLEX_SOFTMAX && mask_mode == 1)
            state_q <= ST_MASK_REQ;
          else begin
            current_valid = derived_mask_valid_q;
            if (!current_valid) begin
              if (phase_q == PH_SOFT_OUT) begin
                result_q <= 64'sd0;
                state_q <= dst_dtype == NPU_DTYPE_INT4 &&
                           dst_high_nibble_q ?
                           ST_RMW_REQ : ST_WRITE_REQ;
              end else
                state_q <= ST_ADVANCE;
            end else if (crosses_beat(src0_addr_q[2:0], src0_dtype))
              fail_task(NPU_STATUS_ADDR_FAULT, src0_addr_q[47:0]);
            else
              state_q <= ST_SRC0_REQ;
          end
        end

        ST_MASK_REQ:
          if (l1_req_ready_i)
            state_q <= ST_MASK_RSP;

        ST_MASK_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        mask_addr_q[47:0]);
            else begin
              mask_value_q <=
                l1_rsp_rdata_i[mask_addr_q[2:0] * 8 +: 8] != 0;
              if (l1_rsp_rdata_i[
                    mask_addr_q[2:0] * 8 +: 8
                  ] == 0) begin
                if (phase_q == PH_SOFT_OUT) begin
                  result_q <= 64'sd0;
                  state_q <= dst_dtype == NPU_DTYPE_INT4 &&
                             dst_high_nibble_q ?
                             ST_RMW_REQ : ST_WRITE_REQ;
                end else
                  state_q <= ST_ADVANCE;
              end else if (crosses_beat(src0_addr_q[2:0], src0_dtype))
                fail_task(NPU_STATUS_ADDR_FAULT, src0_addr_q[47:0]);
              else
                state_q <= ST_SRC0_REQ;
            end
          end

        ST_SRC0_REQ:
          if (l1_req_ready_i)
            state_q <= ST_SRC0_RSP;

        ST_SRC0_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        src0_addr_q[47:0]);
            else begin
              src0_value_q <= load_element(
                l1_rsp_rdata_i, src0_addr_q[2:0],
                src0_high_nibble_q, src0_dtype
              );
              if (opcode_q == NPU_COMPLEX_ADD_RESCALE ||
                  phase_q == PH_NORM_OUT) begin
                if (crosses_beat(src1_addr_q[2:0], src1_dtype))
                  fail_task(NPU_STATUS_ADDR_FAULT, src1_addr_q[47:0]);
                else
                  state_q <= ST_SRC1_REQ;
              end else if (phase_q == PH_STAT_ACC &&
                           function_mode == 9)
                state_q <= ST_STAT_SQUARE;
              else
                state_q <= ST_COMPUTE;
            end
          end

        ST_SRC1_REQ:
          if (l1_req_ready_i)
            state_q <= ST_SRC1_RSP;

        ST_SRC1_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        src1_addr_q[47:0]);
            else begin
              src1_value_q <= load_element(
                l1_rsp_rdata_i, src1_addr_q[2:0],
                src1_high_nibble_q, src1_dtype
              );
              if (phase_q == PH_NORM_OUT && function_mode == 5) begin
                if (crosses_beat(src2_addr_q[2:0], src2_dtype))
                  fail_task(NPU_STATUS_ADDR_FAULT, src2_addr_q[47:0]);
                else
                  state_q <= ST_SRC2_REQ;
              end else
                state_q <= ST_COMPUTE;
            end
          end

        ST_SRC2_REQ:
          if (l1_req_ready_i)
            state_q <= ST_SRC2_RSP;

        ST_SRC2_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        src2_addr_q[47:0]);
            else begin
              src2_value_q <= load_element(
                l1_rsp_rdata_i, src2_addr_q[2:0],
                src2_high_nibble_q, src2_dtype
              );
              state_q <= ST_COMPUTE;
            end
          end

        ST_COMPUTE: begin
          if (phase_q == PH_STAT_ACC) begin
            if (function_mode == 9)
              state_q <= ST_STAT_SQUARE;
            else begin
              if (function_mode == 7)
                next_stat = stat_sum_q + src0_value_q;
              else
                next_stat =
                  col_q == 0 || src0_value_q > stat_max_q ?
                  src0_value_q : stat_max_q;
              if (function_mode == 7)
                stat_sum_q <= next_stat;
              else
                stat_max_q <= next_stat;

              if (col_q + 1 == active_columns) begin
                output_overflow =
                  next_stat < dtype_min(NPU_DTYPE_INT32) ||
                  next_stat > dtype_max(NPU_DTYPE_INT32);
                if (output_overflow && overflow_mode == 1)
                  fail_task(
                    NPU_STATUS_NUMERIC_EXCEPTION,
                    stat_dst_addr_q
                  );
                else begin
                  result_q <= overflow_mode == 2 ?
                    wrap_to_dtype(
                      next_stat[31:0], NPU_DTYPE_INT32
                    ) :
                    clip_to_dtype(next_stat, NPU_DTYPE_INT32);
                  phase_q <= PH_STAT_OUT;
                  current_dst_addr_q <= {16'd0, stat_dst_addr_q};
                  dst_high_nibble_q <= 1'b0;
                  if (crosses_beat(
                        stat_dst_addr_q[2:0], NPU_DTYPE_INT32
                      ))
                    fail_task(
                      NPU_STATUS_ADDR_FAULT,
                      stat_dst_addr_q
                    );
                  else
                    state_q <= ST_WRITE_REQ;
                end
              end else
                state_q <= ST_ADVANCE;
            end
          end else begin
            issue_math(
              MATH_I2F_MUL,
              src0_centered_integer[31:0],
              src0_scale_bits,
              MA_SRC0_I2F
            );
          end
        end

        ST_STAT_SQUARE: begin
          stat_square_q <= stat_square_product;
          stat_square_last_q <= col_q + 1 == active_columns;
          stat_square_overflow_mode_q <= overflow_mode;
          state_q <= ST_STAT_ACCUM;
        end

        ST_STAT_ACCUM: begin
          next_stat = stat_sumsq_q + stat_square_q;
          stat_sumsq_q <= next_stat;
          output_overflow =
            stat_sumsq_overflow_q || |next_stat[63:31];
          stat_sumsq_overflow_q <= output_overflow;
          if (stat_square_last_q) begin
            if (output_overflow &&
                stat_square_overflow_mode_q == 1)
              fail_task(
                NPU_STATUS_NUMERIC_EXCEPTION,
                stat_dst_addr_q
              );
            else begin
              if (stat_square_overflow_mode_q == 2)
                result_q <= wrap_to_dtype(
                  next_stat[31:0], NPU_DTYPE_INT32
                );
              else if (output_overflow)
                result_q <= dtype_max(NPU_DTYPE_INT32);
              else
                result_q <= clip_to_dtype(
                  next_stat, NPU_DTYPE_INT32
                );
              phase_q <= PH_STAT_OUT;
              current_dst_addr_q <= {16'd0, stat_dst_addr_q};
              dst_high_nibble_q <= 1'b0;
              if (crosses_beat(
                    stat_dst_addr_q[2:0],
                    NPU_DTYPE_INT32
                  ))
                fail_task(
                  NPU_STATUS_ADDR_FAULT,
                  stat_dst_addr_q
                );
              else
                state_q <= ST_WRITE_REQ;
            end
          end else
            state_q <= ST_ADVANCE;
        end

        ST_MATH_REQ:
          if (math_req_ready)
            state_q <= ST_MATH_RSP;

        ST_MATH_RSP:
          if (math_rsp_valid) begin
            case (math_action_q)
              MA_SRC0_I2F: begin
                fp_src0_q <= math_rsp_result;
                case (phase_q)
                  PH_ELEMENT: begin
                    if (opcode_q == NPU_COMPLEX_ACT) begin
                      activation_value = math_rsp_result;
                      if (fp32_less_than(
                            activation_value, input_clip_min_bits
                          ))
                        activation_value = input_clip_min_bits;
                      else if (fp32_less_than(
                                 input_clip_max_bits, activation_value
                               ))
                        activation_value = input_clip_max_bits;
                      issue_math(
                        function_mode[3:0],
                        activation_value,
                        32'd0,
                        MA_ACT_VALUE
                      );
                    end else begin
                      issue_math(
                        MATH_I2F_MUL,
                        src1_centered_integer[31:0],
                        src1_scale_bits,
                        MA_SRC1_I2F
                      );
                    end
                  end

                  PH_SOFT_MAX: begin
                    if (!valid_seen_q ||
                        fp32_less_than(fp_row_max_q, math_rsp_result))
                      fp_row_max_q <= math_rsp_result;
                    valid_seen_q <= 1'b1;
                    state_q <= ST_ADVANCE;
                  end

                  PH_SOFT_SUM,
                  PH_SOFT_OUT:
                    issue_math(
                      MATH_SUB,
                      math_rsp_result,
                      fp_row_max_q,
                      MA_SOFT_DIFF
                    );

                  PH_NORM_ACC: begin
                    if (function_mode == 5 && stats_mode == 1)
                      issue_math(
                        MATH_SUB,
                        math_rsp_result,
                        fp_row_mean_q,
                        MA_WELFORD_DELTA
                      );
                    else if (function_mode == 6)
                      issue_math(
                        MATH_MUL,
                        math_rsp_result,
                        math_rsp_result,
                        MA_NORM_SQUARE
                      );
                    else
                      issue_math(
                        MATH_ADD,
                        fp_lane_selected,
                        math_rsp_result,
                        MA_LANE_ADD
                      );
                  end

                  PH_NORM_VAR:
                    issue_math(
                      MATH_SUB,
                      math_rsp_result,
                      fp_row_mean_q,
                      MA_NORM_CENTER
                    );

                  PH_NORM_OUT:
                    issue_math(
                      MATH_I2F_MUL,
                      src1_centered_integer[31:0],
                      src1_scale_bits,
                      MA_SRC1_I2F
                    );

                  default:
                    fail_task(
                      NPU_STATUS_BAD_DESC,
                      current_dst_addr_q[47:0]
                    );
                endcase
              end

              MA_SRC1_I2F: begin
                fp_src1_q <= math_rsp_result;
                if (phase_q == PH_ELEMENT)
                  issue_math(
                    MATH_ADD,
                    fp_src0_q,
                    math_rsp_result,
                    MA_ADD_VALUE
                  );
                else if (function_mode == 5)
                  issue_math(
                    MATH_I2F_MUL,
                    src2_centered_integer[31:0],
                    src2_scale_bits,
                    MA_SRC2_I2F
                  );
                else
                  issue_math(
                    MATH_MUL,
                    math_rsp_result,
                    fp_src0_q,
                    MA_NORM_BASE
                  );
              end

              MA_SRC2_I2F: begin
                fp_src2_q <= math_rsp_result;
                issue_math(
                  MATH_SUB,
                  fp_src0_q,
                  fp_row_mean_q,
                  MA_NORM_CENTER
                );
              end

              MA_ACT_VALUE,
              MA_ADD_VALUE,
              MA_SOFT_VALUE,
              MA_NORM_VALUE:
                issue_output_conversion(math_rsp_result);

              MA_SOFT_DIFF: begin
                softmax_difference = math_rsp_result;
                if (fp32_less_than(
                      softmax_difference, input_clip_min_bits
                    ))
                  softmax_difference = input_clip_min_bits;
                else if (fp32_less_than(
                           32'd0, softmax_difference
                         ))
                  softmax_difference = 32'd0;
                issue_math(
                  MATH_EXP,
                  softmax_difference,
                  32'd0,
                  MA_SOFT_EXP
                );
              end

              MA_SOFT_EXP: begin
                if (phase_q == PH_SOFT_SUM)
                  issue_math(
                    MATH_ADD,
                    fp_lane_selected,
                    math_rsp_result,
                    MA_LANE_ADD
                  );
                else if (fp32_is_zero(fp_row_sum_q))
                  issue_output_conversion(32'd0);
                else
                  issue_math(
                    MATH_MUL,
                    math_rsp_result,
                    fp_row_inverse_q,
                    MA_SOFT_VALUE
                  );
              end

              MA_LANE_ADD: begin
                case (col_q[1:0])
                  2'd0: fp_lane_sum_q[0] <= math_rsp_result;
                  2'd1: fp_lane_sum_q[1] <= math_rsp_result;
                  2'd2: fp_lane_sum_q[2] <= math_rsp_result;
                  default: fp_lane_sum_q[3] <= math_rsp_result;
                endcase
                state_q <= ST_ADVANCE;
              end

              MA_NORM_SQUARE:
                issue_math(
                  MATH_ADD,
                  fp_lane_selected,
                  math_rsp_result,
                  MA_LANE_ADD
                );

              MA_NORM_CENTER: begin
                if (phase_q == PH_NORM_VAR) begin
                  fp_tmp0_q <= math_rsp_result;
                  issue_math(
                    MATH_MUL,
                    math_rsp_result,
                    math_rsp_result,
                    MA_NORM_SQUARE
                  );
                end else
                  issue_math(
                    MATH_MUL,
                    fp_src1_q,
                    math_rsp_result,
                    MA_NORM_BASE
                  );
              end

              MA_NORM_BASE:
                issue_math(
                  MATH_MUL,
                  math_rsp_result,
                  fp_row_invstd_q,
                  MA_NORM_SCALED
                );

              MA_NORM_SCALED:
                issue_math(
                  MATH_ADD,
                  math_rsp_result,
                  function_mode == 5 ? fp_src2_q : 32'd0,
                  MA_NORM_VALUE
                );

              MA_WELFORD_DELTA: begin
                fp_tmp0_q <= math_rsp_result;
                issue_math(
                  MATH_I2F_MUL,
                  col_q + 32'd1,
                  32'h3f80_0000,
                  MA_WELFORD_COUNT_FP
                );
              end

              MA_WELFORD_COUNT_FP:
                issue_math(
                  MATH_RECIP,
                  math_rsp_result,
                  32'd0,
                  MA_WELFORD_COUNT_INV
                );

              MA_WELFORD_COUNT_INV:
                issue_math(
                  MATH_MUL,
                  fp_tmp0_q,
                  math_rsp_result,
                  MA_WELFORD_MEAN_STEP
                );

              MA_WELFORD_MEAN_STEP:
                issue_math(
                  MATH_ADD,
                  fp_row_mean_q,
                  math_rsp_result,
                  MA_WELFORD_MEAN_NEW
                );

              MA_WELFORD_MEAN_NEW: begin
                fp_tmp1_q <= math_rsp_result;
                issue_math(
                  MATH_SUB,
                  fp_src0_q,
                  math_rsp_result,
                  MA_WELFORD_X_DIFF
                );
              end

              MA_WELFORD_X_DIFF:
                issue_math(
                  MATH_MUL,
                  fp_tmp0_q,
                  math_rsp_result,
                  MA_WELFORD_M2_TERM
                );

              MA_WELFORD_M2_TERM:
                issue_math(
                  MATH_ADD,
                  fp_row_sumsq_q,
                  math_rsp_result,
                  MA_WELFORD_DONE
                );

              MA_WELFORD_DONE: begin
                fp_row_mean_q <= fp_tmp1_q;
                fp_row_sumsq_q <= math_rsp_result;
                state_q <= ST_ADVANCE;
              end

              MA_TOTAL_01: begin
                fp_tmp0_q <= math_rsp_result;
                issue_math(
                  MATH_ADD,
                  fp_lane_sum_q[2],
                  fp_lane_sum_q[3],
                  MA_TOTAL_23
                );
              end

              MA_TOTAL_23: begin
                fp_tmp1_q <= math_rsp_result;
                issue_math(
                  MATH_ADD,
                  fp_tmp0_q,
                  math_rsp_result,
                  MA_TOTAL_FINAL
                );
              end

              MA_TOTAL_FINAL: begin
                fp_tmp2_q <= math_rsp_result;
                if (phase_q == PH_SOFT_SUM) begin
                  fp_row_sum_q <= math_rsp_result;
                  issue_math(
                    MATH_RECIP,
                    math_rsp_result,
                    32'd0,
                    MA_COUNT_INV
                  );
                end else if (phase_q == PH_NORM_VAR)
                  issue_math(
                    MATH_MUL,
                    math_rsp_result,
                    fp_active_inverse_q,
                    MA_VARIANCE
                  );
                else
                  issue_math(
                    MATH_I2F_MUL,
                    active_columns,
                    32'h3f80_0000,
                    MA_COUNT_FP
                  );
              end

              MA_COUNT_FP:
                issue_math(
                  MATH_RECIP,
                  math_rsp_result,
                  32'd0,
                  MA_COUNT_INV
                );

              MA_COUNT_INV: begin
                if (phase_q == PH_SOFT_SUM) begin
                  fp_row_inverse_q <= math_rsp_result;
                  phase_q <= PH_SOFT_OUT;
                  state_q <= ST_ELEMENT_BEGIN;
                end else begin
                  fp_active_inverse_q <= math_rsp_result;
                  if (function_mode == 5 && stats_mode == 0)
                    issue_math(
                      MATH_MUL,
                      fp_tmp2_q,
                      math_rsp_result,
                      MA_MEAN_DONE
                    );
                  else
                    issue_math(
                      MATH_MUL,
                      fp_tmp2_q,
                      math_rsp_result,
                      MA_VARIANCE
                    );
                end
              end

              MA_MEAN_DONE: begin
                fp_row_mean_q <= math_rsp_result;
                fp_lane_sum_q[0] <= 32'd0;
                fp_lane_sum_q[1] <= 32'd0;
                fp_lane_sum_q[2] <= 32'd0;
                fp_lane_sum_q[3] <= 32'd0;
                phase_q <= PH_NORM_VAR;
                col_q <= 32'd0;
                state_q <= ST_ELEMENT_BEGIN;
              end

              MA_VARIANCE: begin
                nonnegative_variance =
                  math_rsp_result[31] ? 32'd0 : math_rsp_result;
                issue_math(
                  MATH_ADD,
                  nonnegative_variance,
                  epsilon_bits,
                  MA_VARIANCE_EPSILON
                );
              end

              MA_VARIANCE_EPSILON:
                issue_math(
                  MATH_RSQRT,
                  math_rsp_result,
                  32'd0,
                  MA_INVSTD
                );

              MA_INVSTD: begin
                fp_row_invstd_q <= math_rsp_result;
                phase_q <= PH_NORM_OUT;
                col_q <= 32'd0;
                state_q <= ST_ELEMENT_BEGIN;
              end

              MA_F2I: begin
                f2i_significand =
                  math_rsp_result[30:23] == 0 ?
                  {1'b0, math_rsp_result[22:0]} :
                  {1'b1, math_rsp_result[22:0]};
                f2i_unbiased =
                  math_rsp_result[30:23] == 0 ?
                  -126 :
                  {24'd0, math_rsp_result[30:23]} - 127;
                f2i_quotient = 64'd0;
                f2i_remainder = 64'd0;
                f2i_halfway = 64'd0;
                f2i_force_limit = 1'b0;

                if (fp32_is_inf(math_rsp_result))
                  f2i_force_limit = 1'b1;
                else if (!fp32_is_nan(math_rsp_result) &&
                         !fp32_is_zero(math_rsp_result)) begin
                  if (f2i_unbiased >= 63)
                    f2i_force_limit = 1'b1;
                  else if (f2i_unbiased >= 23)
                    f2i_quotient =
                      {40'd0, f2i_significand} <<
                      (f2i_unbiased - 23);
                  else begin
                    f2i_shift_amount = 23 - f2i_unbiased;
                    if (f2i_shift_amount >= 64) begin
                      f2i_remainder = {40'd0, f2i_significand};
                      f2i_halfway = 64'hffff_ffff_ffff_ffff;
                    end else begin
                      f2i_quotient =
                        {40'd0, f2i_significand} >>
                        f2i_shift_amount;
                      f2i_remainder_mask =
                        (64'd1 << f2i_shift_amount) - 1;
                      f2i_remainder =
                        {40'd0, f2i_significand} &
                        f2i_remainder_mask;
                      f2i_halfway =
                        64'd1 << (f2i_shift_amount - 1);
                    end
                  end
                end

                f2i_quotient_q <= f2i_quotient;
                f2i_remainder_q <= f2i_remainder;
                f2i_halfway_q <= f2i_halfway;
                f2i_sign_q <= math_rsp_result[31];
                f2i_force_limit_q <= f2i_force_limit;
                f2i_exceptional_q <=
                  fp32_is_nan(math_rsp_result) ||
                  fp32_is_inf(math_rsp_result);
                f2i_round_mode_q <= round_mode;
                f2i_dst_zero_point_q <= dst_zero_point;
                f2i_dst_dtype_q <= dst_dtype;
                f2i_overflow_mode_q <= overflow_mode;
                f2i_phase_q <= phase_q;
                f2i_dst_addr_q <= current_dst_addr_q[47:0];
                f2i_dst_high_nibble_q <= dst_high_nibble_q;
                state_q <= ST_F2I_ROUND;
              end

              default:
                fail_task(
                  NPU_STATUS_BAD_DESC,
                  current_dst_addr_q[47:0]
                );
            endcase
          end

        ST_F2I_ROUND: begin
          f2i_increment = 1'b0;
          case (f2i_round_mode_q)
            2'd0:
              f2i_increment =
                f2i_remainder_q > f2i_halfway_q ||
                (f2i_remainder_q == f2i_halfway_q &&
                 f2i_quotient_q[0]);
            2'd2:
              f2i_increment =
                !f2i_sign_q && f2i_remainder_q != 0;
            2'd3:
              f2i_increment =
                f2i_sign_q && f2i_remainder_q != 0;
            default: f2i_increment = 1'b0;
          endcase
          f2i_increment_q <= f2i_increment;
          state_q <= ST_F2I_MAG;
        end

        ST_F2I_MAG: begin
          if (f2i_force_limit_q)
            f2i_magnitude_q <=
              f2i_sign_q ?
              64'h8000_0000_0000_0000 :
              64'h7fff_ffff_ffff_ffff;
          else
            f2i_magnitude_q <=
              f2i_quotient_q + {63'd0, f2i_increment_q};
          state_q <= ST_F2I_SIGN;
        end

        ST_F2I_SIGN: begin
          if (f2i_sign_q) begin
            if (f2i_magnitude_q >= 64'h8000_0000_0000_0000)
              f2i_rounded_q <= 64'sh8000_0000_0000_0000;
            else
              f2i_rounded_q <=
                $signed((~f2i_magnitude_q) + 64'd1);
          end else if (f2i_magnitude_q >
                       64'h7fff_ffff_ffff_ffff)
            f2i_rounded_q <= 64'sh7fff_ffff_ffff_ffff;
          else
            f2i_rounded_q <= $signed(f2i_magnitude_q);
          state_q <= ST_F2I_OFFSET;
        end

        ST_F2I_OFFSET: begin
          f2i_output_integer_q <=
            f2i_rounded_q +
            {{32{f2i_dst_zero_point_q[31]}},
             f2i_dst_zero_point_q};
          state_q <= ST_F2I_FINISH;
        end

        ST_F2I_FINISH: begin
          output_overflow =
            f2i_output_integer_q < dtype_min(f2i_dst_dtype_q) ||
            f2i_output_integer_q > dtype_max(f2i_dst_dtype_q);
          result_q <= clip_to_dtype(
            f2i_output_integer_q, f2i_dst_dtype_q
          );
          if (f2i_phase_q == PH_ELEMENT &&
              (output_overflow || f2i_exceptional_q) &&
              f2i_overflow_mode_q == 1)
            fail_task(
              NPU_STATUS_NUMERIC_EXCEPTION,
              f2i_dst_addr_q
            );
          else if (crosses_beat(
                     f2i_dst_addr_q[2:0], f2i_dst_dtype_q
                   ))
            fail_task(
              NPU_STATUS_ADDR_FAULT,
              f2i_dst_addr_q
            );
          else
            state_q <=
              f2i_dst_dtype_q == NPU_DTYPE_INT4 &&
              f2i_dst_high_nibble_q ?
              ST_RMW_REQ : ST_WRITE_REQ;
        end

        ST_ADVANCE: begin
          if (col_q + 1 < active_columns) begin
            col_q <= col_q + 1;
            state_q <= ST_ELEMENT_BEGIN;
          end else begin
            col_q <= 0;
            case (phase_q)
              PH_SOFT_MAX: begin
                if (!valid_seen_q && all_mask_mode == 1)
                  fail_task(NPU_STATUS_NUMERIC_EXCEPTION,
                            dst_base[47:0]);
                else begin
                  fp_row_sum_q <= 32'd0;
                  fp_lane_sum_q[0] <= 32'd0;
                  fp_lane_sum_q[1] <= 32'd0;
                  fp_lane_sum_q[2] <= 32'd0;
                  fp_lane_sum_q[3] <= 32'd0;
                  phase_q <= !valid_seen_q ?
                             PH_SOFT_OUT : PH_SOFT_SUM;
                  state_q <= ST_ELEMENT_BEGIN;
                end
              end
              PH_SOFT_SUM: begin
                issue_math(
                  MATH_ADD,
                  fp_lane_sum_q[0],
                  fp_lane_sum_q[1],
                  MA_TOTAL_01
                );
              end
              PH_NORM_ACC: begin
                if (function_mode == 5 && stats_mode == 1) begin
                  fp_tmp2_q <= fp_row_sumsq_q;
                  issue_math(
                    MATH_I2F_MUL,
                    active_columns,
                    32'h3f80_0000,
                    MA_COUNT_FP
                  );
                end else
                  issue_math(
                    MATH_ADD,
                    fp_lane_sum_q[0],
                    fp_lane_sum_q[1],
                    MA_TOTAL_01
                  );
              end
              PH_NORM_VAR: begin
                issue_math(
                  MATH_ADD,
                  fp_lane_sum_q[0],
                  fp_lane_sum_q[1],
                  MA_TOTAL_01
                );
              end
              default: state_q <= ST_ELEMENT_BEGIN;
            endcase
          end
        end

        ST_RMW_REQ:
          if (l1_req_ready_i)
            state_q <= ST_RMW_RSP;

        ST_RMW_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        current_dst_addr_q[47:0]);
            else begin
              rmw_beat_q <= l1_rsp_rdata_i;
              state_q <= ST_WRITE_REQ;
            end
          end

        ST_WRITE_REQ:
          if (l1_req_ready_i)
            state_q <= ST_WRITE_RSP;

        ST_WRITE_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        current_dst_addr_q[47:0]);
            else begin
              progress_q <= progress_q + 1;
              if (phase_q == PH_STAT_OUT) begin
                if (row_q + 1 < rows) begin
                  row_q <= row_q + 1;
                  stat_dst_addr_q <=
                    stat_dst_addr_q + {16'd0, dst_row_stride};
                  state_q <= ST_ROW_INIT;
                end else begin
                  status_q <= NPU_STATUS_SUCCESS;
                  state_q <= ST_DONE;
                end
              end else if (col_q + 1 < active_columns) begin
                col_q <= col_q + 1;
                state_q <= ST_ELEMENT_BEGIN;
              end else if (row_q + 1 < rows) begin
                row_q <= row_q + 1;
                state_q <= ST_ROW_INIT;
              end else begin
                status_q <= NPU_STATUS_SUCCESS;
                state_q <= ST_DONE;
              end
            end
          end

        ST_DONE:
          if (done_ready_i)
            state_q <= ST_IDLE;

        default: state_q <= ST_IDLE;
      endcase
    end
  end

endmodule
