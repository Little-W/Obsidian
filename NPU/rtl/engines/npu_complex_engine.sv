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
    ST_VLEN_REQ,
    ST_VLEN_RSP,
    ST_ELEMENT_BEGIN,
    ST_MASK_REQ,
    ST_MASK_RSP,
    ST_SRC0_REQ,
    ST_SRC0_RSP,
    ST_SRC1_REQ,
    ST_SRC1_RSP,
    ST_SRC2_REQ,
    ST_SRC2_RSP,
    ST_COMPUTE,
    ST_ADVANCE,
    ST_RMW_REQ,
    ST_RMW_RSP,
    ST_WRITE_REQ,
    ST_WRITE_RSP,
    ST_DONE
  } state_t;

  state_t state_q;
  logic [3:0] phase_q;
  logic [2047:0] desc_q;
  logic [7:0] opcode_q;
  logic [31:0] row_q;
  logic [31:0] col_q;
  logic [31:0] row_key_length_q;
  logic mask_value_q;
  logic valid_seen_q;
  logic signed [63:0] src0_value_q;
  logic signed [63:0] src1_value_q;
  logic signed [63:0] src2_value_q;
  logic signed [63:0] stat_sum_q;
  logic signed [63:0] stat_sumsq_q;
  logic signed [63:0] stat_max_q;
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
  wire [63:0] stat_dst_addr =
    dst_base + row_q * dst_row_stride;
  wire [63:0] current_dst_addr =
    phase_q == PH_STAT_OUT ? stat_dst_addr : normal_dst_addr;
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
    src0_addr[63:48],
    src1_addr[63:48],
    src2_addr[63:48],
    current_dst_addr[63:48],
    current_valid_length_addr[63:48]
  };

  wire src0_high_nibble = src0_dtype == NPU_DTYPE_INT4 && col_q[0];
  wire src1_high_nibble = src1_dtype == NPU_DTYPE_INT4 && col_q[0];
  wire src2_high_nibble = src2_dtype == NPU_DTYPE_INT4 && col_q[0];
  wire dst_high_nibble =
    dst_dtype == NPU_DTYPE_INT4 && col_q[0] &&
    phase_q != PH_STAT_OUT;

  wire causal_valid =
    key_position_base + col_q <=
    query_position_base + row_q * query_position_step;
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

  logic [3:0] math_operation;
  logic [31:0] math_operand0;
  logic [31:0] math_operand1;
  logic [31:0] math_result;
  logic signed [63:0] src0_centered_integer;
  logic signed [63:0] src1_centered_integer;
  logic signed [63:0] src2_centered_integer;
  logic [31:0] src0_fp;
  logic [31:0] src1_fp;
  logic [31:0] src2_fp;
  logic [31:0] current_x_fp;
  logic [31:0] activation_x_fp;
  logic [31:0] softmax_difference_fp;
  logic [31:0] active_columns_fp;
  logic [31:0] fp_x_squared;
  logic [31:0] fp_centered_squared;
  logic [31:0] fp_lane_selected;
  logic [31:0] fp_lane_addend;
  logic [31:0] fp_lane_next;
  logic [31:0] fp_lane_total;
  logic [31:0] fp_active_columns_inverse;
  logic [31:0] fp_mean;
  logic [31:0] fp_variance;
  logic [31:0] fp_nonnegative_variance;
  logic [31:0] fp_variance_plus_epsilon;
  logic [31:0] fp_next_invstd;
  logic [31:0] fp_welford_count;
  logic [31:0] fp_welford_delta;
  logic [31:0] fp_welford_mean_next;
  logic [31:0] fp_welford_m2_next;
  logic [31:0] fp_centered_x;
  logic [31:0] fp_norm_base;
  logic [31:0] fp_norm_scaled;
  logic [31:0] fp_norm_output;
  logic [31:0] fp_add_rescale_output;
  logic [31:0] fp_soft_sum_plus_exp;
  logic [31:0] fp_softmax_output;
  logic [31:0] fp_output_value;
  logic signed [63:0] f2i_result;
  logic f2i_exceptional;

  always_comb begin
    src0_centered_integer =
      src0_value_q -
      {{32{src0_zero_point[31]}}, src0_zero_point};
    src1_centered_integer =
      src1_value_q -
      {{32{src1_zero_point[31]}}, src1_zero_point};
    src2_centered_integer =
      src2_value_q -
      {{32{src2_zero_point[31]}}, src2_zero_point};
  end

  npu_complex_i2f u_src0_i2f (
    .integer_i(src0_centered_integer),
    .scale_i(src0_scale_bits),
    .result_o(src0_fp)
  );

  npu_complex_i2f u_src1_i2f (
    .integer_i(src1_centered_integer),
    .scale_i(src1_scale_bits),
    .result_o(src1_fp)
  );

  npu_complex_i2f u_src2_i2f (
    .integer_i(src2_centered_integer),
    .scale_i(src2_scale_bits),
    .result_o(src2_fp)
  );

  always_comb begin
    current_x_fp = src0_fp;
    activation_x_fp = current_x_fp;
    if (fp32_less_than(activation_x_fp, input_clip_min_bits))
      activation_x_fp = input_clip_min_bits;
    else if (fp32_less_than(input_clip_max_bits, activation_x_fp))
      activation_x_fp = input_clip_max_bits;

    softmax_difference_fp = fp32_sub(current_x_fp, fp_row_max_q);
    if (fp32_less_than(
          softmax_difference_fp, input_clip_min_bits
        ))
      softmax_difference_fp = input_clip_min_bits;
    else if (fp32_less_than(32'd0, softmax_difference_fp))
      softmax_difference_fp = 32'd0;

    math_operation = 4'd0;
    math_operand0 = current_x_fp;
    math_operand1 = 32'd0;
    if (opcode_q == NPU_COMPLEX_ACT) begin
      math_operation = function_mode[3:0];
      math_operand0 = activation_x_fp;
    end else if (opcode_q == NPU_COMPLEX_SOFTMAX &&
                 (phase_q == PH_SOFT_SUM ||
                  phase_q == PH_SOFT_OUT)) begin
      math_operation = 4'd4;
      math_operand0 = softmax_difference_fp;
    end
  end

  npu_complex_math_core u_math_core (
    .operation_i(math_operation),
    .operand0_i(math_operand0),
    .operand1_i(math_operand1),
    .result_o(math_result)
  );

  assign active_columns_fp =
    fp32_from_int($signed({32'd0, active_columns}));

  assign fp_x_squared = fp32_mul(current_x_fp, current_x_fp);
  assign fp_centered_squared =
    fp32_mul(fp_centered_x, fp_centered_x);

  always_comb begin
    case (col_q[1:0])
      2'd0: fp_lane_selected = fp_lane_sum_q[0];
      2'd1: fp_lane_selected = fp_lane_sum_q[1];
      2'd2: fp_lane_selected = fp_lane_sum_q[2];
      default: fp_lane_selected = fp_lane_sum_q[3];
    endcase
    fp_lane_addend = current_x_fp;
    if (phase_q == PH_SOFT_SUM)
      fp_lane_addend = math_result;
    else if (phase_q == PH_NORM_VAR)
      fp_lane_addend = fp_centered_squared;
    else if (phase_q == PH_NORM_ACC && function_mode == 6)
      fp_lane_addend = fp_x_squared;
  end

  assign fp_lane_next =
    fp32_add(fp_lane_selected, fp_lane_addend);
  assign fp_lane_total = fp32_add(
    fp32_add(fp_lane_sum_q[0], fp_lane_sum_q[1]),
    fp32_add(fp_lane_sum_q[2], fp_lane_sum_q[3])
  );
  assign fp_active_columns_inverse =
    fp32_reciprocal_approx(active_columns_fp);
  assign fp_mean =
    fp32_mul(fp_lane_total, fp_active_columns_inverse);
  assign fp_variance =
    fp32_mul(
      stats_mode == 1 ? fp_row_sumsq_q : fp_lane_total,
      fp_active_columns_inverse
    );

  assign fp_nonnegative_variance =
    fp_variance[31] ? 32'd0 : fp_variance;

  assign fp_variance_plus_epsilon =
    fp32_add(fp_nonnegative_variance, epsilon_bits);
  assign fp_next_invstd =
    fp32_rsqrt_approx(fp_variance_plus_epsilon);
  assign fp_welford_count = fp32_from_int(
    $signed({32'd0, col_q}) + 64'sd1
  );
  assign fp_welford_delta =
    fp32_sub(current_x_fp, fp_row_mean_q);
  assign fp_welford_mean_next = fp32_add(
    fp_row_mean_q,
    fp32_mul(
      fp_welford_delta,
      fp32_reciprocal_approx(fp_welford_count)
    )
  );
  assign fp_welford_m2_next = fp32_add(
    fp_row_sumsq_q,
    fp32_mul(
      fp_welford_delta,
      fp32_sub(current_x_fp, fp_welford_mean_next)
    )
  );
  assign fp_centered_x = fp32_sub(current_x_fp, fp_row_mean_q);
  assign fp_norm_base = fp32_mul(
    src1_fp, function_mode == 5 ? fp_centered_x : current_x_fp
  );
  assign fp_norm_scaled =
    fp32_mul(fp_norm_base, fp_row_invstd_q);
  assign fp_norm_output = fp32_add(
    fp_norm_scaled, function_mode == 5 ? src2_fp : 32'd0
  );
  assign fp_add_rescale_output = fp32_add(current_x_fp, src1_fp);
  assign fp_soft_sum_plus_exp =
    fp32_add(fp_lane_selected, math_result);
  assign fp_softmax_output =
    fp32_mul(math_result, fp_row_inverse_q);

  always_comb begin
    fp_output_value = math_result;
    if (opcode_q == NPU_COMPLEX_ADD_RESCALE)
      fp_output_value = fp_add_rescale_output;
    else if (phase_q == PH_SOFT_OUT)
      fp_output_value =
        fp32_is_zero(fp_row_sum_q) ? 32'd0 : fp_softmax_output;
    else if (phase_q == PH_NORM_OUT)
      fp_output_value = fp_norm_output;
  end

  npu_complex_f2i u_f2i (
    .value_i(fp_output_value),
    .scale_i(dst_scale_bits),
    .round_mode_i(round_mode),
    .result_o(f2i_result),
    .exceptional_o(f2i_exceptional)
  );

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
        l1_req_addr_o = {current_valid_length_addr[19:3], 3'b000};
      end
      ST_MASK_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {mask_addr[19:3], 3'b000};
      end
      ST_SRC0_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {src0_addr[19:3], 3'b000};
      end
      ST_SRC1_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {src1_addr[19:3], 3'b000};
      end
      ST_SRC2_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {src2_addr[19:3], 3'b000};
      end
      ST_RMW_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {current_dst_addr[19:3], 3'b000};
      end
      ST_WRITE_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_write_o = 1'b1;
        l1_req_addr_o = {current_dst_addr[19:3], 3'b000};
        l1_req_wdata_o = store_element_data(
          rmw_beat_q, result_q[31:0], current_dst_addr[2:0],
          dst_high_nibble, dst_dtype
        );
        l1_req_wstrb_o =
          store_element_strb(current_dst_addr[2:0], dst_dtype);
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
    logic signed [63:0] output_integer;
    logic signed [63:0] valid_length_value;
    logic output_overflow;
    logic current_valid;
    if (!reset_n) begin
      state_q <= ST_IDLE;
      phase_q <= PH_ELEMENT;
      desc_q <= '0;
      opcode_q <= '0;
      row_q <= '0;
      col_q <= '0;
      row_key_length_q <= '0;
      mask_value_q <= 1'b1;
      valid_seen_q <= 1'b0;
      src0_value_q <= '0;
      src1_value_q <= '0;
      src2_value_q <= '0;
      stat_sum_q <= '0;
      stat_sumsq_q <= '0;
      stat_max_q <= -64'sh3fff_ffff_ffff_ffff;
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
      result_q <= '0;
      rmw_beat_q <= '0;
      status_q <= NPU_STATUS_SUCCESS;
      fault_addr_q <= 48'd0;
      progress_q <= 64'd0;
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
            state_q <= ST_ROW_INIT;
          end
        end

        ST_ROW_INIT: begin
          col_q <= 0;
          mask_value_q <= 1'b1;
          valid_seen_q <= 1'b0;
          stat_sum_q <= 64'sd0;
          stat_sumsq_q <= 64'sd0;
          stat_max_q <= -64'sh3fff_ffff_ffff_ffff;
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
            if (crosses_beat(current_valid_length_addr[2:0],
                             NPU_DTYPE_INT32))
              fail_task(NPU_STATUS_ADDR_FAULT,
                        current_valid_length_addr[47:0]);
            else
              state_q <= ST_VLEN_REQ;
          end else begin
            row_key_length_q <= length;
            state_q <= ST_ELEMENT_BEGIN;
          end
        end

        ST_VLEN_REQ:
          if (l1_req_ready_i)
            state_q <= ST_VLEN_RSP;

        ST_VLEN_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        current_valid_length_addr[47:0]);
            else begin
              valid_length_value = load_element(
                l1_rsp_rdata_i, current_valid_length_addr[2:0],
                1'b0, NPU_DTYPE_INT32
              );
              row_key_length_q <= valid_length_value[31:0];
              if (valid_length_value < 0 ||
                  valid_length_value > {32'd0, length})
                fail_task(NPU_STATUS_BAD_SHAPE,
                          current_valid_length_addr[47:0]);
              else
                state_q <= ST_ELEMENT_BEGIN;
            end
          end

        ST_ELEMENT_BEGIN: begin
          mask_value_q <= 1'b1;
          rmw_beat_q <= 64'd0;
          if (opcode_q == NPU_COMPLEX_SOFTMAX && mask_mode == 1)
            state_q <= ST_MASK_REQ;
          else begin
            current_valid = derived_mask_valid;
            if (!current_valid) begin
              if (phase_q == PH_SOFT_OUT) begin
                result_q <= 64'sd0;
                state_q <= dst_dtype == NPU_DTYPE_INT4 &&
                           dst_high_nibble ? ST_RMW_REQ : ST_WRITE_REQ;
              end else
                state_q <= ST_ADVANCE;
            end else if (crosses_beat(src0_addr[2:0], src0_dtype))
              fail_task(NPU_STATUS_ADDR_FAULT, src0_addr[47:0]);
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
                        mask_addr[47:0]);
            else begin
              mask_value_q <=
                l1_rsp_rdata_i[mask_addr[2:0] * 8 +: 8] != 0;
              if (l1_rsp_rdata_i[mask_addr[2:0] * 8 +: 8] == 0) begin
                if (phase_q == PH_SOFT_OUT) begin
                  result_q <= 64'sd0;
                  state_q <= dst_dtype == NPU_DTYPE_INT4 &&
                             dst_high_nibble ? ST_RMW_REQ : ST_WRITE_REQ;
                end else
                  state_q <= ST_ADVANCE;
              end else if (crosses_beat(src0_addr[2:0], src0_dtype))
                fail_task(NPU_STATUS_ADDR_FAULT, src0_addr[47:0]);
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
                        src0_addr[47:0]);
            else begin
              src0_value_q <= load_element(
                l1_rsp_rdata_i, src0_addr[2:0],
                src0_high_nibble, src0_dtype
              );
              if (opcode_q == NPU_COMPLEX_ADD_RESCALE ||
                  phase_q == PH_NORM_OUT) begin
                if (crosses_beat(src1_addr[2:0], src1_dtype))
                  fail_task(NPU_STATUS_ADDR_FAULT, src1_addr[47:0]);
                else
                  state_q <= ST_SRC1_REQ;
              end else
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
                        src1_addr[47:0]);
            else begin
              src1_value_q <= load_element(
                l1_rsp_rdata_i, src1_addr[2:0],
                src1_high_nibble, src1_dtype
              );
              if (phase_q == PH_NORM_OUT && function_mode == 5) begin
                if (crosses_beat(src2_addr[2:0], src2_dtype))
                  fail_task(NPU_STATUS_ADDR_FAULT, src2_addr[47:0]);
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
                        src2_addr[47:0]);
            else begin
              src2_value_q <= load_element(
                l1_rsp_rdata_i, src2_addr[2:0],
                src2_high_nibble, src2_dtype
              );
              state_q <= ST_COMPUTE;
            end
          end

        ST_COMPUTE: begin
          case (phase_q)
            PH_ELEMENT: begin
              output_integer =
                f2i_result +
                {{32{dst_zero_point[31]}}, dst_zero_point};
              output_overflow =
                output_integer < dtype_min(dst_dtype) ||
                output_integer > dtype_max(dst_dtype);
              result_q <= clip_to_dtype(output_integer, dst_dtype);
              if ((output_overflow || f2i_exceptional) &&
                  overflow_mode == 1)
                fail_task(NPU_STATUS_NUMERIC_EXCEPTION,
                          current_dst_addr[47:0]);
              else if (crosses_beat(
                         current_dst_addr[2:0], dst_dtype
                       ))
                fail_task(NPU_STATUS_ADDR_FAULT,
                          current_dst_addr[47:0]);
              else
                state_q <= dst_dtype == NPU_DTYPE_INT4 &&
                           dst_high_nibble ? ST_RMW_REQ : ST_WRITE_REQ;
            end

            PH_SOFT_MAX: begin
              if (!valid_seen_q ||
                  fp32_less_than(fp_row_max_q, current_x_fp))
                fp_row_max_q <= current_x_fp;
              valid_seen_q <= 1'b1;
              state_q <= ST_ADVANCE;
            end

            PH_SOFT_SUM: begin
              case (col_q[1:0])
                2'd0: fp_lane_sum_q[0] <= fp_soft_sum_plus_exp;
                2'd1: fp_lane_sum_q[1] <= fp_soft_sum_plus_exp;
                2'd2: fp_lane_sum_q[2] <= fp_soft_sum_plus_exp;
                default:
                  fp_lane_sum_q[3] <= fp_soft_sum_plus_exp;
              endcase
              state_q <= ST_ADVANCE;
            end

            PH_SOFT_OUT: begin
              output_integer =
                f2i_result +
                {{32{dst_zero_point[31]}}, dst_zero_point};
              result_q <= clip_to_dtype(output_integer, dst_dtype);
              if (crosses_beat(current_dst_addr[2:0], dst_dtype))
                fail_task(NPU_STATUS_ADDR_FAULT,
                          current_dst_addr[47:0]);
              else
                state_q <= dst_dtype == NPU_DTYPE_INT4 &&
                           dst_high_nibble ? ST_RMW_REQ : ST_WRITE_REQ;
            end

            PH_NORM_ACC: begin
              if (function_mode == 5 && stats_mode == 1) begin
                fp_row_mean_q <= fp_welford_mean_next;
                fp_row_sumsq_q <= fp_welford_m2_next;
              end else begin
                case (col_q[1:0])
                  2'd0: fp_lane_sum_q[0] <= fp_lane_next;
                  2'd1: fp_lane_sum_q[1] <= fp_lane_next;
                  2'd2: fp_lane_sum_q[2] <= fp_lane_next;
                  default: fp_lane_sum_q[3] <= fp_lane_next;
                endcase
              end
              state_q <= ST_ADVANCE;
            end

            PH_NORM_VAR: begin
              case (col_q[1:0])
                2'd0: fp_lane_sum_q[0] <= fp_lane_next;
                2'd1: fp_lane_sum_q[1] <= fp_lane_next;
                2'd2: fp_lane_sum_q[2] <= fp_lane_next;
                default: fp_lane_sum_q[3] <= fp_lane_next;
              endcase
              state_q <= ST_ADVANCE;
            end

            PH_NORM_OUT: begin
              output_integer =
                f2i_result +
                {{32{dst_zero_point[31]}}, dst_zero_point};
              result_q <= clip_to_dtype(output_integer, dst_dtype);
              if (crosses_beat(current_dst_addr[2:0], dst_dtype))
                fail_task(NPU_STATUS_ADDR_FAULT,
                          current_dst_addr[47:0]);
              else
                state_q <= dst_dtype == NPU_DTYPE_INT4 &&
                           dst_high_nibble ? ST_RMW_REQ : ST_WRITE_REQ;
            end

            default: begin
              case (function_mode)
                7: next_stat = stat_sum_q + src0_value_q;
                8: next_stat =
                     col_q == 0 || src0_value_q > stat_max_q ?
                     src0_value_q : stat_max_q;
                default:
                  next_stat =
                    stat_sumsq_q + src0_value_q * src0_value_q;
              endcase
              if (function_mode == 7)
                stat_sum_q <= next_stat;
              else if (function_mode == 8)
                stat_max_q <= next_stat;
              else
                stat_sumsq_q <= next_stat;

              if (col_q + 1 == active_columns) begin
                output_overflow =
                  next_stat < dtype_min(NPU_DTYPE_INT32) ||
                  next_stat > dtype_max(NPU_DTYPE_INT32);
                if (output_overflow && overflow_mode == 1)
                  fail_task(NPU_STATUS_NUMERIC_EXCEPTION,
                            stat_dst_addr[47:0]);
                else begin
                  result_q <= overflow_mode == 2 ?
                    wrap_to_dtype(
                      next_stat[31:0], NPU_DTYPE_INT32
                    ) :
                    clip_to_dtype(next_stat, NPU_DTYPE_INT32);
                  phase_q <= PH_STAT_OUT;
                  if (crosses_beat(
                        stat_dst_addr[2:0], NPU_DTYPE_INT32
                      ))
                    fail_task(NPU_STATUS_ADDR_FAULT,
                              stat_dst_addr[47:0]);
                  else
                    state_q <= ST_WRITE_REQ;
                end
              end else
                state_q <= ST_ADVANCE;
            end
          endcase
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
                fp_row_sum_q <= fp_lane_total;
                fp_row_inverse_q <=
                  fp32_reciprocal_approx(fp_lane_total);
                phase_q <= PH_SOFT_OUT;
                state_q <= ST_ELEMENT_BEGIN;
              end
              PH_NORM_ACC: begin
                if (function_mode == 5 && stats_mode == 0) begin
                  fp_row_mean_q <= fp_mean;
                  fp_lane_sum_q[0] <= 32'd0;
                  fp_lane_sum_q[1] <= 32'd0;
                  fp_lane_sum_q[2] <= 32'd0;
                  fp_lane_sum_q[3] <= 32'd0;
                  phase_q <= PH_NORM_VAR;
                end else begin
                  fp_row_invstd_q <= fp_next_invstd;
                  phase_q <= PH_NORM_OUT;
                end
                state_q <= ST_ELEMENT_BEGIN;
              end
              PH_NORM_VAR: begin
                fp_row_invstd_q <= fp_next_invstd;
                phase_q <= PH_NORM_OUT;
                state_q <= ST_ELEMENT_BEGIN;
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
                        current_dst_addr[47:0]);
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
                        current_dst_addr[47:0]);
            else begin
              progress_q <= progress_q + 1;
              if (phase_q == PH_STAT_OUT) begin
                if (row_q + 1 < rows) begin
                  row_q <= row_q + 1;
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
