module npu_matrix_engine (
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

  localparam logic [31:0] MATRIX_MT = 32'd8;
  localparam logic [31:0] MATRIX_KT = 32'd16;
  localparam logic [31:0] MATRIX_NT = 32'd8;

  typedef enum logic [4:0] {
    ST_IDLE,
    ST_CHECK,
    ST_START_OUTPUT,
    ST_A_REQ,
    ST_A_RSP,
    ST_B_REQ,
    ST_B_RSP,
    ST_MAC,
    ST_SRC2_REQ,
    ST_SRC2_RSP,
    ST_BIAS_REQ,
    ST_BIAS_RSP,
    ST_REQUANT_REQ,
    ST_REQUANT_RSP,
    ST_EPILOGUE,
    ST_RMW_REQ,
    ST_RMW_RSP,
    ST_WRITE_REQ,
    ST_WRITE_RSP,
    ST_DONE
  } state_t;

  state_t state_q;
  logic [2047:0] desc_q;
  logic [7:0] opcode_q;
  logic [31:0] batch_q;
  logic [31:0] row_q;
  logic [31:0] col_q;
  logic [31:0] k_q;
  logic signed [63:0] a_value_q;
  logic signed [63:0] b_value_q;
  logic signed [63:0] accum_q;
  logic signed [63:0] result_q;
  logic [39:0] requant_entry_q;
  logic [63:0] rmw_beat_q;
  logic [7:0] status_q;
  logic [47:0] fault_addr_q;
  logic [63:0] progress_q;

  wire [7:0] desc_version = desc_q[7:0];
  wire [7:0] desc_type = desc_q[15:8];
  wire [15:0] desc_bytes = desc_q[31:16];
  wire [63:0] a_base = desc_q[64 +: 64];
  wire [63:0] b_base = desc_q[128 +: 64];
  wire [63:0] src2_base = desc_q[192 +: 64];
  wire [63:0] c_base = desc_q[256 +: 64];
  wire [63:0] bias_base = desc_q[320 +: 64];
  wire [63:0] requant_base = desc_q[384 +: 64];
  wire [31:0] numeric_cfg = desc_q[448 +: 32];
  wire [1:0] a_dtype = numeric_cfg[1:0];
  wire [1:0] b_dtype = numeric_cfg[3:2];
  wire [1:0] src2_dtype = numeric_cfg[5:4];
  wire [1:0] c_dtype = numeric_cfg[7:6];
  wire [1:0] round_mode = numeric_cfg[11:10];
  wire unused_numeric_cfg = ^numeric_cfg[16:12];
  wire unused_command_id = ^command_id_i;
  wire unused_result_upper = ^result_q[63:32];
  wire unused_desc_fields = ^{
    desc_q[2047:1424],
    desc_q[1215:1200],
    desc_q[511:480],
    desc_q[63:32]
  };

  wire [31:0] matrix_m = desc_q[16'h40 * 8 +: 32];
  wire [31:0] matrix_n = desc_q[16'h44 * 8 +: 32];
  wire [31:0] matrix_k = desc_q[16'h48 * 8 +: 32];
  wire [31:0] batch_count = desc_q[16'h4c * 8 +: 32];
  wire [31:0] last_valid_m = desc_q[16'h50 * 8 +: 32];
  wire [31:0] last_valid_n = desc_q[16'h54 * 8 +: 32];
  wire [31:0] last_valid_k = desc_q[16'h58 * 8 +: 32];
  wire [31:0] matrix_flags = desc_q[16'h5c * 8 +: 32];
  wire [31:0] lda_bytes = desc_q[16'h60 * 8 +: 32];
  wire [31:0] ldb_bytes = desc_q[16'h64 * 8 +: 32];
  wire [31:0] ldc_bytes = desc_q[16'h68 * 8 +: 32];
  wire [31:0] bias_stride_bytes = desc_q[16'h6c * 8 +: 32];
  wire [63:0] a_batch_stride = desc_q[16'h70 * 8 +: 64];
  wire [63:0] b_batch_stride = desc_q[16'h78 * 8 +: 64];
  wire [63:0] c_batch_stride = desc_q[16'h80 * 8 +: 64];
  wire [63:0] src2_batch_stride = desc_q[16'h88 * 8 +: 64];
  wire [7:0] a_pack_format = desc_q[16'h90 * 8 +: 8];
  wire [7:0] b_pack_format = desc_q[16'h91 * 8 +: 8];
  wire [7:0] c_pack_format = desc_q[16'h92 * 8 +: 8];
  wire [7:0] pack_version = desc_q[16'h93 * 8 +: 8];
  wire [7:0] overflow_mode = desc_q[16'h94 * 8 +: 8];
  wire [7:0] activation_mode = desc_q[16'h95 * 8 +: 8];
  wire signed [31:0] output_zero_point =
    desc_q[16'h98 * 8 +: 32];
  wire [31:0] requant_count = desc_q[16'h9c * 8 +: 32];
  wire [31:0] bias_count = desc_q[16'ha0 * 8 +: 32];
  wire [7:0] requant_mode = desc_q[16'ha4 * 8 +: 8];
  wire [7:0] residual_mode = desc_q[16'ha5 * 8 +: 8];
  wire [7:0] requant_entry_bytes = desc_q[16'ha6 * 8 +: 8];
  wire [31:0] requant_region_bytes = desc_q[16'ha8 * 8 +: 32];
  wire inline_requant = desc_q[16'hb0 * 8];
  wire [7:0] inline_requant_shift = desc_q[16'hb1 * 8 +: 8];

  wire transpose_a = matrix_flags[0];
  wire transpose_b = matrix_flags[1];
  wire bias_enable = matrix_flags[2];
  wire residual_enable = matrix_flags[3];
  wire relu_enable = matrix_flags[4];
  wire requant_enable = matrix_flags[5];
  wire accum_from_src2 = matrix_flags[6];
  wire final_output = matrix_flags[7];

  function automatic logic opcode_known(input logic [7:0] opcode);
    return opcode >= NPU_MATRIX_GEMM &&
           opcode <= NPU_MATRIX_GEMM_ZERO;
  endfunction

  function automatic logic [31:0] expected_tail(
    input logic [31:0] size,
    input logic [31:0] tile
  );
    if (size == 0)
      return 32'd0;
    if ((size % tile) == 0)
      return tile;
    return size % tile;
  endfunction

  function automatic logic [63:0] row_major_offset(
    input logic [31:0] row,
    input logic [31:0] col,
    input logic [31:0] row_stride,
    input logic [1:0] dtype
  );
    logic [63:0] element_offset;
    begin
      if (dtype == NPU_DTYPE_INT4)
        element_offset = {32'd0, col} >> 1;
      else
        element_offset = col * dtype_bytes(dtype);
      return row * row_stride + element_offset;
    end
  endfunction

  function automatic logic tiled_b_high_nibble(
    input logic n_index_odd
  );
    /*
     * MATRIX_NT is eight, so every preceding tiled-address term is
     * multiplied by an even value.  The packed INT4 nibble therefore
     * depends only on the low bit of the N index.
     */
    return n_index_odd;
  endfunction

  function automatic logic [63:0] tiled_b_offset(
    input logic [31:0] k_index,
    input logic [31:0] n_index,
    input logic [31:0] n_size,
    input logic [1:0] dtype
  );
    logic [31:0] k_outer;
    logic [31:0] n_outer;
    logic [31:0] k_inner;
    logic [31:0] n_inner;
    logic [31:0] n_tiles;
    logic [63:0] element_index;
    begin
      k_outer = k_index / MATRIX_KT;
      n_outer = n_index / MATRIX_NT;
      k_inner = k_index % MATRIX_KT;
      n_inner = n_index % MATRIX_NT;
      n_tiles = (n_size + MATRIX_NT - 1) / MATRIX_NT;
      element_index =
        ((({32'd0, k_outer} * {32'd0, n_tiles} +
           {32'd0, n_outer}) * {32'd0, MATRIX_KT} +
          {32'd0, k_inner}) * {32'd0, MATRIX_NT}) +
        {32'd0, n_inner};
      if (dtype == NPU_DTYPE_INT4)
        return element_index >> 1;
      return element_index * dtype_bytes(dtype);
    end
  endfunction

  function automatic logic signed [63:0] requantize(
    input logic signed [63:0] value,
    input logic [31:0] multiplier,
    input logic signed [7:0] shift_value,
    input logic [1:0] rounding
  );
    logic signed [127:0] product;
    logic signed [127:0] shifted;
    logic signed [127:0] absolute_product;
    logic signed [127:0] rounding_bias;
    integer shift_amount;
    begin
      product = value * $signed({1'b0, multiplier});
      if (shift_value < 0) begin
        shift_amount =
          -$signed({{24{shift_value[7]}}, shift_value});
        shifted = product <<< shift_amount;
      end else if (shift_value == 0)
        shifted = product;
      else begin
        shift_amount =
          $signed({{24{shift_value[7]}}, shift_value});
        rounding_bias = 128'd0;
        if (rounding == 2'd0 && shift_amount > 0) begin
          absolute_product = product < 0 ? -product : product;
          rounding_bias = 128'sd1 <<< (shift_amount - 1);
          absolute_product = absolute_product + rounding_bias;
          shifted = product < 0 ?
                    -(absolute_product >>> shift_amount) :
                    (absolute_product >>> shift_amount);
        end else if (rounding == 2'd2 && product > 0)
          shifted = (product + ((128'sd1 <<< shift_amount) - 1)) >>>
                    shift_amount;
        else if (rounding == 2'd3 && product < 0)
          shifted = -(((-product) +
                      ((128'sd1 <<< shift_amount) - 1)) >>>
                      shift_amount);
        else
          shifted = product >>> shift_amount;
      end
      if (shifted[127:64] != {64{shifted[63]}})
        return shifted[127] ?
               64'sh8000_0000_0000_0000 :
               64'sh7fff_ffff_ffff_ffff;
      return shifted[63:0];
    end
  endfunction

  wire [63:0] a_addr =
    a_base + batch_q * a_batch_stride +
    (transpose_a ?
     row_major_offset(k_q, row_q, lda_bytes, a_dtype) :
     row_major_offset(row_q, k_q, lda_bytes, a_dtype));

  wire b_is_tiled =
    b_pack_format == 8'd2 || b_pack_format == 8'd3 ||
    b_pack_format == 8'd6;
  wire [63:0] b_addr =
    b_base + batch_q * b_batch_stride +
    (b_is_tiled ?
     tiled_b_offset(k_q, col_q, matrix_n, b_dtype) :
     (transpose_b ?
      row_major_offset(col_q, k_q, ldb_bytes, b_dtype) :
      row_major_offset(k_q, col_q, ldb_bytes, b_dtype)));

  wire [63:0] c_addr =
    c_base + batch_q * c_batch_stride +
    row_major_offset(row_q, col_q, ldc_bytes, c_dtype);
  wire [63:0] src2_addr =
    src2_base + batch_q * src2_batch_stride +
    row_major_offset(row_q, col_q, ldc_bytes, NPU_DTYPE_INT32);
  wire [63:0] bias_addr =
    bias_base + col_q * bias_stride_bytes;
  /*
   * This single-core implementation exposes a 48-bit architectural fault
   * address.  Descriptor validation constrains every L1 base address, so the
   * arithmetic high bits are intentionally outside the reported address.
   */
  wire unused_address_upper = ^{
    a_addr[63:48],
    b_addr[63:48],
    c_addr[63:48],
    src2_addr[63:48],
    bias_addr[63:48]
  };
  wire [47:0] requant_addr =
    requant_base[47:0] +
    ((requant_mode == 8'd2) ? {13'd0, col_q, 3'b000} : 48'd0);

  wire a_high_nibble = a_dtype == NPU_DTYPE_INT4 &&
    (transpose_a ? row_q[0] : k_q[0]);
  wire b_high_nibble = b_dtype == NPU_DTYPE_INT4 &&
    (b_is_tiled ?
     tiled_b_high_nibble(col_q[0]) :
     (transpose_b ? k_q[0] : col_q[0]));
  wire c_high_nibble = c_dtype == NPU_DTYPE_INT4 && col_q[0];

  function automatic logic crosses_beat(
    input logic [2:0] byte_lane,
    input logic [1:0] dtype
  );
    return (dtype == NPU_DTYPE_INT32 && byte_lane > 3'd4) ||
           (dtype == NPU_DTYPE_INT16 && byte_lane > 3'd6);
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
      ST_A_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {a_addr[19:3], 3'b000};
      end
      ST_B_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {b_addr[19:3], 3'b000};
      end
      ST_SRC2_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {src2_addr[19:3], 3'b000};
      end
      ST_BIAS_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {bias_addr[19:3], 3'b000};
      end
      ST_REQUANT_REQ: begin
        if (!inline_requant) begin
          l1_req_valid_o = 1'b1;
          l1_req_addr_o = {requant_addr[19:3], 3'b000};
        end
      end
      ST_RMW_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {c_addr[19:3], 3'b000};
      end
      ST_WRITE_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_write_o = 1'b1;
        l1_req_addr_o = {c_addr[19:3], 3'b000};
        l1_req_wdata_o = store_element_data(
          rmw_beat_q, result_q[31:0], c_addr[2:0],
          c_high_nibble, c_dtype
        );
        l1_req_wstrb_o = store_element_strb(c_addr[2:0], c_dtype);
      end
      ST_A_RSP,
      ST_B_RSP,
      ST_SRC2_RSP,
      ST_BIAS_RSP,
      ST_REQUANT_RSP,
      ST_RMW_RSP,
      ST_WRITE_RSP: l1_rsp_ready_o = 1'b1;
      default: begin end
    endcase
  end

  always_ff @(posedge clk_i or negedge reset_n) begin
    logic signed [63:0] epilogue_value;
    logic signed [63:0] requant_value;
    logic overflow;
    if (!reset_n) begin
      state_q <= ST_IDLE;
      desc_q <= '0;
      opcode_q <= '0;
      batch_q <= '0;
      row_q <= '0;
      col_q <= '0;
      k_q <= '0;
      a_value_q <= '0;
      b_value_q <= '0;
      accum_q <= '0;
      result_q <= '0;
      requant_entry_q <= '0;
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
          else if (desc_version != 8'h01 || desc_type != 8'h02 ||
                   desc_bytes != 16'd256)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (!dtype_valid(a_dtype) || !dtype_valid(b_dtype) ||
                   !dtype_valid(src2_dtype) || !dtype_valid(c_dtype) ||
                   numeric_cfg[9:8] != 2'd0 ||
                   numeric_cfg[31:17] != 15'd0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (a_pack_format > 8'd6 || b_pack_format > 8'd6 ||
                   c_pack_format > 8'd6 || pack_version != 0 ||
                   overflow_mode > 2 || activation_mode > 1 ||
                   matrix_flags[31:8] != 0 ||
                   residual_mode > 1 ||
                   desc_q[16'ha7 * 8 +: 8] != 0 ||
                   desc_q[16'hac * 8 +: 32] != 0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (a_base[63:20] != 0 || b_base[63:20] != 0 ||
                   c_base[63:20] != 0 ||
                   ((accum_from_src2 || residual_enable) &&
                    src2_base[63:20] != 0) ||
                   (bias_enable && bias_base[63:20] != 0) ||
                   (requant_enable && !inline_requant &&
                    requant_base[63:20] != 0))
            fail_task(NPU_STATUS_ADDR_FAULT, 48'd0);
          else if (desc_q[16'hb0 * 8 + 7 -: 7] != 0 ||
                   (inline_requant &&
                    (!requant_enable || requant_mode != 1 ||
                     requant_count != 1)))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (batch_count == 0 ||
                   (opcode_q == NPU_MATRIX_GEMM && batch_count != 1) ||
                   (opcode_q == NPU_MATRIX_BMM && batch_count < 1))
            fail_task(NPU_STATUS_BAD_SHAPE, 48'd0);
          else if (last_valid_m != expected_tail(matrix_m, MATRIX_MT) ||
                   last_valid_n != expected_tail(matrix_n, MATRIX_NT) ||
                   last_valid_k != expected_tail(matrix_k, MATRIX_KT))
            fail_task(NPU_STATUS_BAD_SHAPE, 48'd0);
          else if (opcode_q != NPU_MATRIX_GEMM_ZERO &&
                   !(((a_dtype == NPU_DTYPE_INT4) &&
                      (b_dtype == NPU_DTYPE_INT4)) ||
                     ((a_dtype == NPU_DTYPE_INT8) &&
                      (b_dtype == NPU_DTYPE_INT8 ||
                       b_dtype == NPU_DTYPE_INT4)) ||
                     ((a_dtype == NPU_DTYPE_INT16) &&
                      (b_dtype == NPU_DTYPE_INT16))))
            fail_task(NPU_STATUS_DTYPE_UNSUPPORTED, 48'd0);
          else if (opcode_q != NPU_MATRIX_GEMM_ZERO &&
                   !((a_dtype == NPU_DTYPE_INT4 &&
                      a_pack_format == 8'd1) ||
                     (a_dtype == NPU_DTYPE_INT8 &&
                      a_pack_format == 8'd0) ||
                     (a_dtype == NPU_DTYPE_INT16 &&
                      a_pack_format == 8'd5)))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (opcode_q != NPU_MATRIX_GEMM_ZERO &&
                   !((b_dtype == NPU_DTYPE_INT4 &&
                      (b_pack_format == 8'd1 ||
                       b_pack_format == 8'd3)) ||
                     (b_dtype == NPU_DTYPE_INT8 &&
                      (b_pack_format == 8'd0 ||
                       b_pack_format == 8'd2)) ||
                     (b_dtype == NPU_DTYPE_INT16 &&
                      (b_pack_format == 8'd5 ||
                       b_pack_format == 8'd6))))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (!((c_dtype == NPU_DTYPE_INT4 &&
                      c_pack_format == 8'd1) ||
                     (c_dtype == NPU_DTYPE_INT8 &&
                      c_pack_format == 8'd0) ||
                     (c_dtype == NPU_DTYPE_INT32 &&
                      c_pack_format == 8'd4) ||
                     (c_dtype == NPU_DTYPE_INT16 &&
                      c_pack_format == 8'd5)))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (b_is_tiled && transpose_b)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (output_zero_point != 0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (residual_enable && accum_from_src2)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if ((opcode_q == NPU_MATRIX_GEMM_ACCUM) &&
                   (!accum_from_src2 || final_output ||
                    bias_enable || residual_enable || relu_enable ||
                    requant_enable || c_dtype != NPU_DTYPE_INT32))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (opcode_q == NPU_MATRIX_GEMM_ZERO &&
                   (c_dtype != NPU_DTYPE_INT32 ||
                    bias_enable || residual_enable || accum_from_src2 ||
                    requant_enable || relu_enable))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (!final_output && opcode_q != NPU_MATRIX_GEMM_ZERO &&
                   (c_dtype != NPU_DTYPE_INT32 ||
                    bias_enable || residual_enable || relu_enable ||
                    requant_enable))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (final_output && c_dtype != NPU_DTYPE_INT32 &&
                   (!requant_enable ||
                    !(requant_mode == 1 || requant_mode == 2) ||
                    requant_entry_bytes != 8 ||
                    !((requant_mode == 1 && requant_count == 1) ||
                      (requant_mode == 2 &&
                       requant_count == matrix_n)) ||
                    requant_region_bytes < requant_count * 8))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (c_dtype == NPU_DTYPE_INT32 &&
                   (requant_enable || requant_count != 0 ||
                    requant_mode != 0))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if ((bias_enable &&
                    (bias_count != matrix_n ||
                     bias_stride_bytes < 4 ||
                     bias_stride_bytes[1:0] != 0)) ||
                   (!bias_enable && bias_count != 0))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (matrix_m == 0 || matrix_n == 0) begin
            status_q <= NPU_STATUS_SUCCESS;
            state_q <= ST_DONE;
          end else begin
            batch_q <= 0;
            row_q <= 0;
            col_q <= 0;
            k_q <= 0;
            accum_q <= 0;
            state_q <= ST_START_OUTPUT;
          end
        end

        ST_START_OUTPUT: begin
          accum_q <= 64'sd0;
          k_q <= 32'd0;
          rmw_beat_q <= 64'd0;
          if (crosses_beat(c_addr[2:0], c_dtype))
            fail_task(NPU_STATUS_ADDR_FAULT, c_addr[47:0]);
          else if (opcode_q == NPU_MATRIX_GEMM_ZERO ||
                   matrix_k == 0) begin
            if (opcode_q == NPU_MATRIX_GEMM_ZERO)
              state_q <= ST_EPILOGUE;
            else if (accum_from_src2 || residual_enable)
              state_q <= ST_SRC2_REQ;
            else if (bias_enable)
              state_q <= ST_BIAS_REQ;
            else if (requant_enable)
              state_q <= ST_REQUANT_REQ;
            else
              state_q <= ST_EPILOGUE;
          end else if (crosses_beat(a_addr[2:0], a_dtype))
            fail_task(NPU_STATUS_ADDR_FAULT, a_addr[47:0]);
          else
            state_q <= ST_A_REQ;
        end

        ST_A_REQ:
          if (l1_req_ready_i)
            state_q <= ST_A_RSP;

        ST_A_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        a_addr[47:0]);
            else begin
              a_value_q <= load_element(
                l1_rsp_rdata_i, a_addr[2:0], a_high_nibble, a_dtype
              );
              if (crosses_beat(b_addr[2:0], b_dtype))
                fail_task(NPU_STATUS_ADDR_FAULT, b_addr[47:0]);
              else
                state_q <= ST_B_REQ;
            end
          end

        ST_B_REQ:
          if (l1_req_ready_i)
            state_q <= ST_B_RSP;

        ST_B_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        b_addr[47:0]);
            else begin
              b_value_q <= load_element(
                l1_rsp_rdata_i, b_addr[2:0], b_high_nibble, b_dtype
              );
              state_q <= ST_MAC;
            end
          end

        ST_MAC: begin
          accum_q <= accum_q + a_value_q * b_value_q;
          if (k_q + 1 < matrix_k) begin
            k_q <= k_q + 1;
            state_q <= ST_A_REQ;
          end else if (accum_from_src2 || residual_enable)
            state_q <= ST_SRC2_REQ;
          else if (bias_enable)
            state_q <= ST_BIAS_REQ;
          else if (requant_enable)
            state_q <= ST_REQUANT_REQ;
          else
            state_q <= ST_EPILOGUE;
        end

        ST_SRC2_REQ:
          if (crosses_beat(src2_addr[2:0], NPU_DTYPE_INT32))
            fail_task(NPU_STATUS_ADDR_FAULT, src2_addr[47:0]);
          else if (l1_req_ready_i)
            state_q <= ST_SRC2_RSP;

        ST_SRC2_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        src2_addr[47:0]);
            else begin
              accum_q <= accum_q + load_element(
                l1_rsp_rdata_i, src2_addr[2:0], 1'b0, NPU_DTYPE_INT32
              );
              state_q <= bias_enable ? ST_BIAS_REQ :
                         (requant_enable ? ST_REQUANT_REQ : ST_EPILOGUE);
            end
          end

        ST_BIAS_REQ:
          if (crosses_beat(bias_addr[2:0], NPU_DTYPE_INT32))
            fail_task(NPU_STATUS_ADDR_FAULT, bias_addr[47:0]);
          else if (l1_req_ready_i)
            state_q <= ST_BIAS_RSP;

        ST_BIAS_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        bias_addr[47:0]);
            else begin
              accum_q <= accum_q + load_element(
                l1_rsp_rdata_i, bias_addr[2:0], 1'b0, NPU_DTYPE_INT32
              );
              state_q <= requant_enable ? ST_REQUANT_REQ : ST_EPILOGUE;
            end
          end

        ST_REQUANT_REQ:
          if (inline_requant) begin
            requant_entry_q <= {inline_requant_shift, 32'd1};
            state_q <= ST_EPILOGUE;
          end else if (l1_req_ready_i)
            state_q <= ST_REQUANT_RSP;

        ST_REQUANT_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        requant_addr);
            else if (l1_rsp_rdata_i[63:40] != 0)
              fail_task(NPU_STATUS_BAD_DESC, requant_addr);
            else begin
              requant_entry_q <= l1_rsp_rdata_i[39:0];
              state_q <= ST_EPILOGUE;
            end
          end

        ST_EPILOGUE: begin
          epilogue_value =
            opcode_q == NPU_MATRIX_GEMM_ZERO ? 64'sd0 : accum_q;
          if (relu_enable && epilogue_value < 0)
            epilogue_value = 64'sd0;
          if (requant_enable) begin
            requant_value = requantize(
              epilogue_value, requant_entry_q[31:0],
              $signed(requant_entry_q[39:32]), round_mode
            ) + {{32{output_zero_point[31]}}, output_zero_point};
            epilogue_value = requant_value;
          end
          overflow = epilogue_value < dtype_min(c_dtype) ||
                     epilogue_value > dtype_max(c_dtype);
          if (overflow && overflow_mode == 1)
            fail_task(NPU_STATUS_NUMERIC_EXCEPTION, c_addr[47:0]);
          else begin
            if (overflow_mode == 2)
              result_q <= wrap_to_dtype(epilogue_value[31:0], c_dtype);
            else
              result_q <= clip_to_dtype(epilogue_value, c_dtype);
            rmw_beat_q <= 64'd0;
            state_q <= c_dtype == NPU_DTYPE_INT4 &&
                       c_high_nibble ? ST_RMW_REQ : ST_WRITE_REQ;
          end
        end

        ST_RMW_REQ:
          if (l1_req_ready_i)
            state_q <= ST_RMW_RSP;

        ST_RMW_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        c_addr[47:0]);
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
                        c_addr[47:0]);
            else begin
              progress_q <= progress_q + 1;
              if (col_q + 1 < matrix_n) begin
                col_q <= col_q + 1;
                state_q <= ST_START_OUTPUT;
              end else if (row_q + 1 < matrix_m) begin
                row_q <= row_q + 1;
                col_q <= 0;
                state_q <= ST_START_OUTPUT;
              end else if (batch_q + 1 < batch_count) begin
                batch_q <= batch_q + 1;
                row_q <= 0;
                col_q <= 0;
                state_q <= ST_START_OUTPUT;
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
