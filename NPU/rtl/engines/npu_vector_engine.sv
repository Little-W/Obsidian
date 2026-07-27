module npu_vector_engine (
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

  typedef enum logic [5:0] {
    ST_IDLE,
    ST_CHECK,
    ST_MASK_REQ,
    ST_MASK_RSP,
    ST_SRC0_REQ,
    ST_SRC0_RSP,
    ST_SRC1_REQ,
    ST_SRC1_RSP,
    ST_SRC2_REQ,
    ST_SRC2_RSP,
    ST_KEEP_REQ,
    ST_KEEP_RSP,
    ST_EXEC,
    ST_MUL,
    ST_MUL_POST,
    ST_FAST_SRC0_REQ,
    ST_FAST_SRC0_RSP,
    ST_FAST_SRC1_REQ,
    ST_FAST_SRC1_RSP,
    ST_FAST_MUL_REQ,
    ST_FAST_MUL_WAIT,
    ST_FAST_WRITE_PREP,
    ST_FAST_WRITE_REQ,
    ST_FAST_WRITE_RSP,
    ST_RMW_REQ,
    ST_RMW_RSP,
    ST_WRITE_REQ,
    ST_WRITE_RSP,
    ST_DONE,
    ST_ADDR_PREP,
    ST_ADDR_ROW_ADD,
    ST_ADDR_FINAL,
    ST_ADDR_CHECK,
    ST_FAST_ADDR_CHECK,
    ST_FAST_WRITE_CHECK
  } state_t;

  state_t state_q;
  logic [2047:0] desc_q;
  logic [7:0] opcode_q;
  logic [31:0] row_q;
  logic [31:0] col_q;
  logic signed [63:0] src0_value_q;
  logic signed [63:0] src1_value_q;
  logic signed [31:0] src2_value_q;
  logic signed [47:0] mul_product_q;
  logic signed [31:0] mul_addend_q;
  logic mul_is_fma_q;
  logic [1:0] mul_dst_dtype_q;
  logic [7:0] mul_overflow_mode_q;
  logic [47:0] mul_dst_addr_q;
  logic signed [63:0] result_q;
  logic [63:0] rmw_beat_q;
  logic mask_value_q;
  logic [63:0] element_src0_addr_q;
  logic [63:0] element_src1_addr_q;
  logic [63:0] element_src2_addr_q;
  logic [63:0] element_dst_addr_q;
  logic [63:0] element_mask_addr_q;
  logic [63:0] element_src0_offset_q;
  logic [63:0] element_src1_offset_q;
  logic [63:0] element_src2_offset_q;
  logic [63:0] element_dst_offset_q;
  logic [63:0] element_mask_offset_q;
  logic element_src0_addr_valid_q;
  logic element_src1_addr_valid_q;
  logic element_src2_addr_valid_q;
  logic element_dst_addr_valid_q;
  logic element_mask_addr_valid_q;
  logic element_src0_high_nibble_q;
  logic element_src1_high_nibble_q;
  logic element_src2_high_nibble_q;
  logic element_dst_high_nibble_q;
  logic write_last_col_q;
  logic write_last_row_q;
  logic [7:0] status_q;
  logic [47:0] fault_addr_q;
  logic [63:0] progress_q;
  logic fast_path_active_q;
  logic [63:0] fast_src0_beat_q;
  logic [63:0] fast_src1_beat_q;
  logic [47:0] fast_src0_row_base_q;
  logic [47:0] fast_src1_row_base_q;
  logic [47:0] fast_dst_row_base_q;
  logic [47:0] fast_src0_addr_q;
  logic [47:0] fast_src1_addr_q;
  logic [47:0] fast_dst_addr_q;
  logic fast_src0_addr_valid_q;
  logic fast_src1_addr_valid_q;
  logic [1:0] fast_group_q;
  logic [3:0] fast_write_index_q;
  logic [31:0] fast_row_element_count_q;
  logic fast_current_row_last_q;
  logic [1:0] fast_write_action_q;
  logic [1:0] fast_write_progress_q;
  logic [47:0] fast_write_addr_q;
  logic fast_write_addr_valid_q;
  logic [63:0] fast_write_data_q;
  logic [7:0] fast_write_strb_q;
  logic signed [31:0] fast_products_q [0:15];

  localparam logic [1:0] FAST_WRITE_NEXT_PAIR = 2'd0;
  localparam logic [1:0] FAST_WRITE_NEXT_BEAT = 2'd1;
  localparam logic [1:0] FAST_WRITE_NEXT_ROW = 2'd2;
  localparam logic [1:0] FAST_WRITE_DONE = 2'd3;

  logic packed_mul_req_valid;
  logic packed_mul_rsp_valid;
  logic [1:0] packed_mul_rsp_dtype;
  logic [1:0] packed_mul_rsp_group;
  logic [4:0] packed_mul_rsp_count;
  logic [511:0] packed_mul_rsp_products;

  wire [7:0] desc_version = desc_q[7:0];
  wire [7:0] desc_type = desc_q[15:8];
  wire [15:0] desc_bytes = desc_q[31:16];
  wire [63:0] src0_base = desc_q[64 +: 64];
  wire [63:0] src1_base = desc_q[128 +: 64];
  wire [63:0] src2_base = desc_q[192 +: 64];
  wire [63:0] dst_base = desc_q[256 +: 64];
  wire [63:0] mask_base = desc_q[320 +: 64];
  wire [31:0] numeric_cfg = desc_q[448 +: 32];
  wire [1:0] src0_dtype = numeric_cfg[1:0];
  wire [1:0] src1_dtype = numeric_cfg[3:2];
  wire [1:0] src2_dtype = numeric_cfg[5:4];
  wire [1:0] dst_dtype = numeric_cfg[7:6];
  wire unused_numeric_cfg = ^numeric_cfg[16:10];
  wire unused_command_id = ^command_id_i;
  wire unused_result_upper = ^result_q[63:32];
  wire unused_desc_fields = ^{
    desc_q[2047:1216],
    desc_q[1151:1024],
    desc_q[511:480],
    desc_q[447:384],
    desc_q[63:32]
  };

  wire [31:0] rows = desc_q[16'h40 * 8 +: 32];
  wire [31:0] length = desc_q[16'h44 * 8 +: 32];
  wire [31:0] valid_length = desc_q[16'h48 * 8 +: 32];
  wire [31:0] vector_flags = desc_q[16'h4c * 8 +: 32];
  wire [31:0] src0_elem_stride = desc_q[16'h50 * 8 +: 32];
  wire [31:0] src0_row_stride = desc_q[16'h54 * 8 +: 32];
  wire [31:0] src1_elem_stride = desc_q[16'h58 * 8 +: 32];
  wire [31:0] src1_row_stride = desc_q[16'h5c * 8 +: 32];
  wire [31:0] src2_elem_stride = desc_q[16'h60 * 8 +: 32];
  wire [31:0] src2_row_stride = desc_q[16'h64 * 8 +: 32];
  wire [31:0] dst_elem_stride = desc_q[16'h68 * 8 +: 32];
  wire [31:0] dst_row_stride = desc_q[16'h6c * 8 +: 32];
  wire signed [31:0] scalar0 = desc_q[16'h70 * 8 +: 32];
  wire signed [31:0] scalar1 = desc_q[16'h74 * 8 +: 32];
  wire [7:0] broadcast_mode = desc_q[16'h78 * 8 +: 8];
  wire [7:0] compare_mode = desc_q[16'h79 * 8 +: 8];
  wire [7:0] overflow_mode = desc_q[16'h7a * 8 +: 8];
  wire [7:0] mask_mode = desc_q[16'h7b * 8 +: 8];
  wire src0_nibble = desc_q[16'h7c * 8];
  wire src1_nibble = desc_q[16'h7d * 8];
  wire dst_nibble = desc_q[16'h7e * 8];
  wire src2_nibble = desc_q[16'h7f * 8];
  wire [31:0] mask_elem_stride = desc_q[16'h90 * 8 +: 32];
  wire [31:0] mask_row_stride = desc_q[16'h94 * 8 +: 32];

  wire mask_enable = vector_flags[0];
  wire mask_false_keep_dst = vector_flags[1];
  wire src1_from_scalar0 = vector_flags[2];
  wire src2_from_scalar1 = vector_flags[3];

  function automatic logic [4:0] elements_per_input_beat(
    input logic [1:0] dtype
  );
    case (dtype)
      NPU_DTYPE_INT4:  return 5'd16;
      NPU_DTYPE_INT8:  return 5'd8;
      NPU_DTYPE_INT16: return 5'd4;
      default:         return 5'd0;
    endcase
  endfunction

  function automatic logic [63:0] packed_row_bytes(
    input logic [31:0] element_count,
    input logic [1:0] dtype
  );
    case (dtype)
      NPU_DTYPE_INT4:
        return ({32'd0, element_count} + 64'd1) >> 1;
      NPU_DTYPE_INT8:
        return {32'd0, element_count};
      NPU_DTYPE_INT16:
        return {32'd0, element_count} << 1;
      default:
        return {32'd0, element_count} << 2;
    endcase
  endfunction

  wire [63:0] fast_src_row_bytes =
    packed_row_bytes(length, src0_dtype);
  wire [63:0] fast_dst_row_bytes = {32'd0, length} << 2;
  wire fast_multirow_layout_ok =
    (rows <= 1) ||
    (({32'd0, src0_row_stride} == fast_src_row_bytes) &&
     ({32'd0, src1_row_stride} == fast_src_row_bytes) &&
     ({32'd0, dst_row_stride} == fast_dst_row_bytes) &&
     (src0_row_stride[2:0] == 3'd0) &&
     (src1_row_stride[2:0] == 3'd0) &&
     (dst_row_stride[2:0] == 3'd0));
  wire fast_path_eligible =
    (opcode_q == NPU_VECTOR_MUL) &&
    (vector_flags == 32'd0) &&
    (broadcast_mode == 8'd0) &&
    (mask_mode == 8'd0) &&
    (src0_dtype == src1_dtype) &&
    ((src0_dtype == NPU_DTYPE_INT4) ||
     (src0_dtype == NPU_DTYPE_INT8) ||
     (src0_dtype == NPU_DTYPE_INT16)) &&
    (dst_dtype == NPU_DTYPE_INT32) &&
    (src0_elem_stride ==
      ((src0_dtype == NPU_DTYPE_INT16) ? 32'd2 :
       (src0_dtype == NPU_DTYPE_INT8) ? 32'd1 : 32'd0)) &&
    (src1_elem_stride == src0_elem_stride) &&
    (dst_elem_stride == 32'd4) &&
    (src0_base[2:0] == 3'd0) &&
    (src1_base[2:0] == 3'd0) &&
    (dst_base[2:0] == 3'd0) &&
    !src0_nibble &&
    !src1_nibble &&
    !dst_nibble &&
    fast_multirow_layout_ok;

  wire [31:0] fast_remaining_elements =
    (col_q < fast_row_element_count_q) ?
    (fast_row_element_count_q - col_q) : 32'd0;
  wire [4:0] fast_elements_per_beat =
    elements_per_input_beat(src0_dtype);
  wire [4:0] fast_beat_element_count =
    (fast_remaining_elements < {27'd0, fast_elements_per_beat}) ?
    fast_remaining_elements[4:0] : fast_elements_per_beat;
  wire [2:0] fast_group_count =
    (src0_dtype == NPU_DTYPE_INT16) ? 3'd4 :
    (src0_dtype == NPU_DTYPE_INT8) ? 3'd2 : 3'd1;
  wire [47:0] fast_next_src0_row_addr =
    fast_src0_row_base_q + {16'd0, src0_row_stride};
  wire [47:0] fast_next_src1_row_addr =
    fast_src1_row_base_q + {16'd0, src1_row_stride};
  wire [47:0] fast_next_dst_row_addr =
    fast_dst_row_base_q + {16'd0, dst_row_stride};
  wire [47:0] fast_next_src0_beat_addr =
    fast_src0_addr_q + 48'd8;
  wire [47:0] fast_next_src1_beat_addr =
    fast_src1_addr_q + 48'd8;
  wire [47:0] fast_next_dst_beat_addr =
    fast_dst_addr_q + ({43'd0, fast_elements_per_beat} << 2);
  wire [47:0] fast_dst_write_addr =
    fast_dst_addr_q + ({44'd0, fast_write_index_q} << 2);

  assign packed_mul_req_valid =
    (state_q == ST_FAST_MUL_REQ) && fast_path_active_q;

  npu_vector_packed_mul u_packed_mul (
    .clk_i(clk_i),
    .reset_n(reset_n),
    .req_valid_i(packed_mul_req_valid),
    .dtype_i(src0_dtype),
    .group_i(fast_group_q),
    .src0_beat_i(fast_src0_beat_q),
    .src1_beat_i(fast_src1_beat_q),
    .rsp_valid_o(packed_mul_rsp_valid),
    .rsp_dtype_o(packed_mul_rsp_dtype),
    .rsp_group_o(packed_mul_rsp_group),
    .rsp_count_o(packed_mul_rsp_count),
    .rsp_products_o(packed_mul_rsp_products)
  );

  function automatic logic [63:0] tensor_row_offset(
    input logic [31:0] row,
    input logic [31:0] row_stride,
    input logic [1:0] bcast
  );
    begin
      if (bcast == 2'd0 || bcast == 2'd2)
        return {32'd0, row} * {32'd0, row_stride};
      return 64'd0;
    end
  endfunction

  function automatic logic [63:0] tensor_col_offset(
    input logic [31:0] col,
    input logic [31:0] elem_stride,
    input logic [1:0] bcast,
    input logic [1:0] dtype,
    input logic start_nibble
  );
    begin
      if (bcast == 2'd1 || bcast == 2'd2)
        return 64'd0;
      if (dtype == NPU_DTYPE_INT4)
        return ({32'd0, col} + {63'd0, start_nibble}) >> 1;
      return {32'd0, col} * {32'd0, elem_stride};
    end
  endfunction

  function automatic logic tensor_nibble(
    input logic col_odd,
    input logic [1:0] bcast,
    input logic [1:0] dtype,
    input logic start_nibble
  );
    begin
      if (dtype != NPU_DTYPE_INT4)
        return 1'b0;
      case (bcast)
        2'd0,
        2'd3: return col_odd ^ start_nibble;
        default: return start_nibble;
      endcase
    end
  endfunction

  wire [63:0] src0_row_offset = tensor_row_offset(
    row_q, src0_row_stride, broadcast_mode[1:0]
  );
  wire [63:0] src1_row_offset = tensor_row_offset(
    row_q, src1_row_stride, broadcast_mode[3:2]
  );
  wire [63:0] src2_row_offset = tensor_row_offset(
    row_q, src2_row_stride, broadcast_mode[5:4]
  );
  wire [63:0] dst_row_offset = tensor_row_offset(
    row_q, dst_row_stride, 2'd0
  );
  wire [63:0] mask_row_offset =
    {32'd0, row_q} * {32'd0, mask_row_stride};

  wire [63:0] src0_col_offset = tensor_col_offset(
    col_q, src0_elem_stride, broadcast_mode[1:0],
    src0_dtype, src0_nibble
  );
  wire [63:0] src1_col_offset = tensor_col_offset(
    col_q, src1_elem_stride, broadcast_mode[3:2],
    src1_dtype, src1_nibble
  );
  wire [63:0] src2_col_offset = tensor_col_offset(
    col_q, src2_elem_stride, broadcast_mode[5:4],
    src2_dtype, src2_nibble
  );
  wire [63:0] dst_col_offset = tensor_col_offset(
    col_q, dst_elem_stride, 2'd0, dst_dtype, dst_nibble
  );
  wire [63:0] mask_col_offset =
    {32'd0, col_q} * {32'd0, mask_elem_stride};

  wire vector_mul_opcode =
    opcode_q == NPU_VECTOR_MUL || opcode_q == NPU_VECTOR_FMA;
  wire signed [15:0] mul_src0_operand = $signed(src0_value_q[15:0]);
  wire signed [31:0] mul_src1_operand = $signed(src1_value_q[31:0]);
  wire signed [47:0] mul_product =
    mul_src0_operand * mul_src1_operand;

  wire src0_high_nibble = tensor_nibble(
    col_q[0], broadcast_mode[1:0], src0_dtype, src0_nibble
  );
  wire src1_high_nibble = tensor_nibble(
    col_q[0], broadcast_mode[3:2], src1_dtype, src1_nibble
  );
  wire src2_high_nibble = tensor_nibble(
    col_q[0], broadcast_mode[5:4], src2_dtype, src2_nibble
  );
  wire dst_high_nibble = tensor_nibble(
    col_q[0], 2'd0, dst_dtype, dst_nibble
  );

  function automatic logic opcode_uses_src1(input logic [7:0] opcode);
    case (opcode)
      NPU_VECTOR_ADD,
      NPU_VECTOR_SUB,
      NPU_VECTOR_MUL,
      NPU_VECTOR_MAX,
      NPU_VECTOR_MIN,
      NPU_VECTOR_CMP,
      NPU_VECTOR_SELECT,
      NPU_VECTOR_FMA: return 1'b1;
      default: return 1'b0;
    endcase
  endfunction

  function automatic logic opcode_uses_src2(input logic [7:0] opcode);
    return opcode == NPU_VECTOR_FMA;
  endfunction

  function automatic logic opcode_known(input logic [7:0] opcode);
    return opcode >= NPU_VECTOR_ADD && opcode <= NPU_VECTOR_RELU;
  endfunction

  function automatic logic element_crosses_beat(
    input logic [2:0] byte_lane,
    input logic [1:0] dtype
  );
    return ((dtype == NPU_DTYPE_INT32) && (byte_lane > 3'd4)) ||
           ((dtype == NPU_DTYPE_INT16) && (byte_lane > 3'd6));
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
      ST_MASK_REQ: begin
        l1_req_valid_o = element_mask_addr_valid_q;
        l1_req_addr_o = {element_mask_addr_q[19:3], 3'b000};
      end
      ST_SRC0_REQ: begin
        l1_req_valid_o = element_src0_addr_valid_q;
        l1_req_addr_o = {element_src0_addr_q[19:3], 3'b000};
      end
      ST_SRC1_REQ: begin
        l1_req_valid_o = element_src1_addr_valid_q;
        l1_req_addr_o = {element_src1_addr_q[19:3], 3'b000};
      end
      ST_SRC2_REQ: begin
        l1_req_valid_o = element_src2_addr_valid_q;
        l1_req_addr_o = {element_src2_addr_q[19:3], 3'b000};
      end
      ST_FAST_SRC0_REQ: begin
        l1_req_valid_o =
          fast_path_active_q && fast_src0_addr_valid_q;
        l1_req_addr_o = fast_src0_addr_q[19:0];
      end
      ST_FAST_SRC1_REQ: begin
        l1_req_valid_o =
          fast_path_active_q && fast_src1_addr_valid_q;
        l1_req_addr_o = fast_src1_addr_q[19:0];
      end
      ST_FAST_WRITE_REQ: begin
        l1_req_valid_o =
          fast_path_active_q && fast_write_addr_valid_q;
        l1_req_write_o = 1'b1;
        l1_req_addr_o = fast_write_addr_q[19:0];
        l1_req_wdata_o = fast_write_data_q;
        l1_req_wstrb_o = fast_write_strb_q;
      end
      ST_KEEP_REQ,
      ST_RMW_REQ: begin
        l1_req_valid_o = element_dst_addr_valid_q;
        l1_req_addr_o = {element_dst_addr_q[19:3], 3'b000};
      end
      ST_WRITE_REQ: begin
        l1_req_valid_o = element_dst_addr_valid_q;
        l1_req_write_o = 1'b1;
        l1_req_addr_o = {element_dst_addr_q[19:3], 3'b000};
        l1_req_wdata_o = store_element_data(
          rmw_beat_q, result_q[31:0], element_dst_addr_q[2:0],
          element_dst_high_nibble_q, dst_dtype
        );
        l1_req_wstrb_o =
          store_element_strb(element_dst_addr_q[2:0], dst_dtype);
      end
      ST_MASK_RSP,
      ST_SRC0_RSP,
      ST_SRC1_RSP,
      ST_SRC2_RSP,
      ST_FAST_SRC0_RSP,
      ST_FAST_SRC1_RSP,
      ST_FAST_WRITE_RSP,
      ST_KEEP_RSP,
      ST_RMW_RSP,
      ST_WRITE_RSP: l1_rsp_ready_o = 1'b1;
      default: begin end
    endcase
  end

  always_ff @(posedge clk_i or negedge reset_n) begin
    logic signed [63:0] arithmetic_result;
    logic compare_result;
    logic overflow;
    if (!reset_n) begin
      state_q <= ST_IDLE;
      status_q <= NPU_STATUS_SUCCESS;
      fault_addr_q <= '0;
      progress_q <= 64'd0;
      fast_path_active_q <= 1'b0;
      element_src0_offset_q <= 64'd0;
      element_src1_offset_q <= 64'd0;
      element_src2_offset_q <= 64'd0;
      element_dst_offset_q <= 64'd0;
      element_mask_offset_q <= 64'd0;
    end else begin
      case (state_q)
        ST_IDLE: begin
          status_q <= NPU_STATUS_SUCCESS;
          fault_addr_q <= 48'd0;
          progress_q <= 64'd0;
          fast_path_active_q <= 1'b0;
          if (task_valid_i) begin
            desc_q <= desc_i;
            opcode_q <= opcode_i;
            state_q <= ST_CHECK;
          end
        end

        ST_CHECK: begin
          if (!opcode_known(opcode_q))
            fail_task(NPU_STATUS_ILLEGAL_OPCODE, 48'd0);
          else if (desc_version != 8'h01 || desc_type != 8'h03 ||
                   desc_bytes != 16'd192)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (!dtype_valid(src0_dtype) || !dtype_valid(src1_dtype) ||
                   !dtype_valid(src2_dtype) || !dtype_valid(dst_dtype) ||
                   numeric_cfg[9:8] != 2'd0 ||
                   numeric_cfg[31:17] != 15'd0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (vector_flags[31:4] != 28'd0 ||
                   broadcast_mode[7:6] != 2'd0 ||
                   compare_mode > 8'd5 || overflow_mode > 8'd2 ||
                   mask_mode > 8'd1 ||
                   desc_q[16'h7c * 8 + 7 -: 7] != 7'd0 ||
                   desc_q[16'h7d * 8 + 7 -: 7] != 7'd0 ||
                   desc_q[16'h7e * 8 + 7 -: 7] != 7'd0 ||
                   desc_q[16'h7f * 8 + 7 -: 7] != 7'd0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if ((rows == 0 || length == 0) &&
                   valid_length != 0)
            fail_task(NPU_STATUS_BAD_SHAPE, 48'd0);
          else if (rows != 0 && length != 0 &&
                   (valid_length == 0 || valid_length > length))
            fail_task(NPU_STATUS_BAD_SHAPE, 48'd0);
          else if (dst_nibble != 1'b0)
            fail_task(NPU_STATUS_BAD_DESC, dst_base[47:0]);
          else if (src0_base[63:20] != 0 || dst_base[63:20] != 0 ||
                   (opcode_uses_src1(opcode_q) && !src1_from_scalar0 &&
                    src1_base[63:20] != 0) ||
                   (opcode_uses_src2(opcode_q) && !src2_from_scalar1 &&
                    src2_base[63:20] != 0) ||
                   (mask_enable && mask_base[63:20] != 0))
            fail_task(NPU_STATUS_ADDR_FAULT, 48'd0);
          else if ((mask_enable && mask_mode != 8'd1) ||
                   (!mask_enable && mask_mode != 8'd0) ||
                   (mask_enable &&
                    (mask_elem_stride != 32'd1 ||
                     (rows > 1 && mask_row_stride == 0))))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if ((opcode_q == NPU_VECTOR_ADD ||
                    opcode_q == NPU_VECTOR_SUB ||
                    opcode_q == NPU_VECTOR_MAX ||
                    opcode_q == NPU_VECTOR_MIN ||
                    opcode_q == NPU_VECTOR_SELECT) &&
                   (src0_dtype != src1_dtype || dst_dtype != src0_dtype))
            fail_task(NPU_STATUS_DTYPE_UNSUPPORTED, 48'd0);
          else if (opcode_q == NPU_VECTOR_CMP &&
                   (src0_dtype != src1_dtype ||
                    dst_dtype != NPU_DTYPE_INT8))
            fail_task(NPU_STATUS_DTYPE_UNSUPPORTED, 48'd0);
          else if ((opcode_q == NPU_VECTOR_MUL ||
                    opcode_q == NPU_VECTOR_FMA) &&
                   ((src0_dtype == NPU_DTYPE_INT32) ||
                    (src1_dtype == NPU_DTYPE_INT32) ||
                    dst_dtype != NPU_DTYPE_INT32 ||
                    (opcode_q == NPU_VECTOR_FMA &&
                     src2_dtype != NPU_DTYPE_INT32)))
            fail_task(NPU_STATUS_DTYPE_UNSUPPORTED, 48'd0);
          else if ((opcode_q == NPU_VECTOR_CLAMP ||
                    opcode_q == NPU_VECTOR_RELU) &&
                   dst_dtype != src0_dtype)
            fail_task(NPU_STATUS_DTYPE_UNSUPPORTED, 48'd0);
          else if (opcode_q == NPU_VECTOR_CLAMP && scalar0 > scalar1)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (rows == 0 || length == 0) begin
            status_q <= NPU_STATUS_SUCCESS;
            state_q <= ST_DONE;
          end else begin
            row_q <= 32'd0;
            col_q <= 32'd0;
            mask_value_q <= 1'b1;
            fast_path_active_q <= fast_path_eligible;
            fast_src0_row_base_q <= src0_base[47:0];
            fast_src1_row_base_q <= src1_base[47:0];
            fast_dst_row_base_q <= dst_base[47:0];
            fast_src0_addr_q <= src0_base[47:0];
            fast_src1_addr_q <= src1_base[47:0];
            fast_dst_addr_q <= dst_base[47:0];
            fast_src0_addr_valid_q <= 1'b0;
            fast_src1_addr_valid_q <= 1'b0;
            fast_group_q <= 2'd0;
            fast_write_index_q <= 4'd0;
            fast_row_element_count_q <=
              (rows == 32'd1) ? valid_length : length;
            fast_current_row_last_q <= rows == 32'd1;
            state_q <= fast_path_eligible ? ST_FAST_ADDR_CHECK :
              ST_ADDR_PREP;
          end
        end

        ST_ADDR_PREP: begin
          element_src0_offset_q <= src0_row_offset;
          element_src1_offset_q <= src1_row_offset;
          element_src2_offset_q <= src2_row_offset;
          element_dst_offset_q <= dst_row_offset;
          element_mask_offset_q <= mask_row_offset;
          element_src0_high_nibble_q <= src0_high_nibble;
          element_src1_high_nibble_q <= src1_high_nibble;
          element_src2_high_nibble_q <= src2_high_nibble;
          element_dst_high_nibble_q <= dst_high_nibble;
          state_q <= ST_ADDR_ROW_ADD;
        end

        ST_ADDR_ROW_ADD: begin
          element_src0_addr_q <= src0_base + element_src0_offset_q;
          element_src1_addr_q <= src1_base + element_src1_offset_q;
          element_src2_addr_q <= src2_base + element_src2_offset_q;
          element_dst_addr_q <= dst_base + element_dst_offset_q;
          element_mask_addr_q <= mask_base + element_mask_offset_q;
          element_src0_offset_q <= src0_col_offset;
          element_src1_offset_q <= src1_col_offset;
          element_src2_offset_q <= src2_col_offset;
          element_dst_offset_q <= dst_col_offset;
          element_mask_offset_q <= mask_col_offset;
          state_q <= ST_ADDR_FINAL;
        end

        ST_ADDR_FINAL: begin
          element_src0_addr_q <=
            element_src0_addr_q + element_src0_offset_q;
          element_src1_addr_q <=
            element_src1_addr_q + element_src1_offset_q;
          element_src2_addr_q <=
            element_src2_addr_q + element_src2_offset_q;
          element_dst_addr_q <=
            element_dst_addr_q + element_dst_offset_q;
          element_mask_addr_q <=
            element_mask_addr_q + element_mask_offset_q;
          state_q <= ST_ADDR_CHECK;
        end

        ST_ADDR_CHECK: begin
          element_src0_addr_valid_q <=
            (element_src0_addr_q[63:20] == 44'd0) &&
            !element_crosses_beat(
              element_src0_addr_q[2:0], src0_dtype
            );
          element_src1_addr_valid_q <=
            (element_src1_addr_q[63:20] == 44'd0) &&
            !element_crosses_beat(
              element_src1_addr_q[2:0], src1_dtype
            );
          element_src2_addr_valid_q <=
            (element_src2_addr_q[63:20] == 44'd0) &&
            !element_crosses_beat(
              element_src2_addr_q[2:0], src2_dtype
            );
          element_dst_addr_valid_q <=
            (element_dst_addr_q[63:20] == 44'd0) &&
            !element_crosses_beat(
              element_dst_addr_q[2:0], dst_dtype
            );
          element_mask_addr_valid_q <=
            element_mask_addr_q[63:20] == 44'd0;
          state_q <= mask_enable ? ST_MASK_REQ : ST_SRC0_REQ;
        end

        ST_FAST_ADDR_CHECK: begin
          fast_src0_addr_valid_q <=
            (fast_src0_addr_q[47:20] == 28'd0) &&
            (fast_src0_addr_q[2:0] == 3'd0);
          fast_src1_addr_valid_q <=
            (fast_src1_addr_q[47:20] == 28'd0) &&
            (fast_src1_addr_q[2:0] == 3'd0);
          state_q <= ST_FAST_SRC0_REQ;
        end

        ST_MASK_REQ:
          if (!element_mask_addr_valid_q)
            fail_task(
              NPU_STATUS_ADDR_FAULT, element_mask_addr_q[47:0]
            );
          else if (l1_req_ready_i)
            state_q <= ST_MASK_RSP;

        ST_MASK_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        element_mask_addr_q[47:0]);
            else begin
              mask_value_q <=
                l1_rsp_rdata_i[
                  element_mask_addr_q[2:0] * 8 +: 8
                ] != 8'd0;
              if (opcode_q == NPU_VECTOR_SELECT)
                state_q <= ST_SRC0_REQ;
              else if (l1_rsp_rdata_i[
                         element_mask_addr_q[2:0] * 8 +: 8
                       ] == 8'd0) begin
                if (mask_false_keep_dst)
                  state_q <= ST_KEEP_REQ;
                else begin
                  result_q <= 64'sd0;
                  rmw_beat_q <= 64'd0;
                  state_q <= (dst_dtype == NPU_DTYPE_INT4) ?
                    ST_RMW_REQ : ST_WRITE_REQ;
                end
              end else
                state_q <= ST_SRC0_REQ;
            end
          end

        ST_SRC0_REQ:
          if (!element_src0_addr_valid_q)
            fail_task(
              NPU_STATUS_ADDR_FAULT, element_src0_addr_q[47:0]
            );
          else if (l1_req_ready_i)
            state_q <= ST_SRC0_RSP;

        ST_SRC0_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        element_src0_addr_q[47:0]);
            else begin
              src0_value_q <= load_element(
                l1_rsp_rdata_i, element_src0_addr_q[2:0],
                element_src0_high_nibble_q, src0_dtype
              );
              if (opcode_uses_src1(opcode_q)) begin
                if (src1_from_scalar0) begin
                  src1_value_q <= {{32{scalar0[31]}}, scalar0};
                  if (opcode_uses_src2(opcode_q)) begin
                    if (src2_from_scalar1) begin
                      src2_value_q <= scalar1;
                      state_q <= vector_mul_opcode ? ST_MUL : ST_EXEC;
                    end else
                      state_q <= ST_SRC2_REQ;
                  end else
                    state_q <= vector_mul_opcode ? ST_MUL : ST_EXEC;
                end else
                  state_q <= ST_SRC1_REQ;
              end else
                state_q <= vector_mul_opcode ? ST_MUL : ST_EXEC;
            end
          end

        ST_SRC1_REQ:
          if (!element_src1_addr_valid_q)
            fail_task(
              NPU_STATUS_ADDR_FAULT, element_src1_addr_q[47:0]
            );
          else if (l1_req_ready_i)
            state_q <= ST_SRC1_RSP;

        ST_SRC1_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        element_src1_addr_q[47:0]);
            else begin
              src1_value_q <= load_element(
                l1_rsp_rdata_i, element_src1_addr_q[2:0],
                element_src1_high_nibble_q, src1_dtype
              );
              if (opcode_uses_src2(opcode_q)) begin
                if (src2_from_scalar1) begin
                  src2_value_q <= scalar1;
                  state_q <= vector_mul_opcode ? ST_MUL : ST_EXEC;
                end else
                  state_q <= ST_SRC2_REQ;
              end else
                state_q <= vector_mul_opcode ? ST_MUL : ST_EXEC;
            end
          end

        ST_FAST_SRC0_REQ:
          if (!fast_src0_addr_valid_q)
            fail_task(NPU_STATUS_ADDR_FAULT, fast_src0_addr_q);
          else if (l1_req_ready_i)
            state_q <= ST_FAST_SRC0_RSP;

        ST_FAST_SRC0_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        fast_src0_addr_q);
            else begin
              fast_src0_beat_q <= l1_rsp_rdata_i;
              state_q <= ST_FAST_SRC1_REQ;
            end
          end

        ST_FAST_SRC1_REQ:
          if (!fast_src1_addr_valid_q)
            fail_task(NPU_STATUS_ADDR_FAULT, fast_src1_addr_q);
          else if (l1_req_ready_i)
            state_q <= ST_FAST_SRC1_RSP;

        ST_FAST_SRC1_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        fast_src1_addr_q);
            else begin
              fast_src1_beat_q <= l1_rsp_rdata_i;
              fast_group_q <= 2'd0;
              state_q <= ST_FAST_MUL_REQ;
            end
          end

        ST_FAST_MUL_REQ:
          state_q <= ST_FAST_MUL_WAIT;

        ST_FAST_MUL_WAIT:
          if (packed_mul_rsp_valid) begin
            if ((packed_mul_rsp_dtype != src0_dtype) ||
                (packed_mul_rsp_group != fast_group_q) ||
                ((src0_dtype == NPU_DTYPE_INT16) &&
                 (packed_mul_rsp_count != 5'd1)) ||
                ((src0_dtype == NPU_DTYPE_INT8) &&
                 (packed_mul_rsp_count != 5'd4)) ||
                ((src0_dtype == NPU_DTYPE_INT4) &&
                 (packed_mul_rsp_count != 5'd16))) begin
              fail_task(NPU_STATUS_BAD_DESC, 48'd0);
            end else begin
              case (src0_dtype)
                NPU_DTYPE_INT4:
                  for (integer lane = 0; lane < 16; lane++)
                    fast_products_q[lane] <=
                      packed_mul_rsp_products[lane * 32 +: 32];

                NPU_DTYPE_INT8:
                  for (integer lane = 0; lane < 4; lane++)
                    fast_products_q[
                      int'(fast_group_q) * 4 + lane
                    ] <= packed_mul_rsp_products[lane * 32 +: 32];

                default:
                  fast_products_q[{2'd0, fast_group_q}] <=
                    packed_mul_rsp_products[31:0];
              endcase

              if ({1'b0, fast_group_q} + 3'd1 < fast_group_count) begin
                fast_group_q <= fast_group_q + 1'b1;
                state_q <= ST_FAST_MUL_REQ;
              end else begin
                fast_write_index_q <= 4'd0;
                state_q <= ST_FAST_WRITE_PREP;
              end
            end
          end

        ST_FAST_WRITE_PREP: begin
          fast_write_addr_q <= fast_dst_write_addr;
          fast_write_data_q[31:0] <=
            fast_products_q[fast_write_index_q];
          if (fast_write_index_q + 1 < fast_beat_element_count)
            fast_write_data_q[63:32] <=
              fast_products_q[fast_write_index_q + 1];
          else
            fast_write_data_q[63:32] <= 32'd0;
          fast_write_strb_q <=
            (fast_write_index_q + 1 < fast_beat_element_count) ?
            8'hff : 8'h0f;
          state_q <= ST_FAST_WRITE_CHECK;
        end

        ST_FAST_WRITE_CHECK: begin
          fast_write_addr_valid_q <=
            (fast_write_addr_q[47:20] == 28'd0) &&
            (fast_write_addr_q[2:0] == 3'd0);
          state_q <= ST_FAST_WRITE_REQ;
        end

        ST_FAST_WRITE_REQ:
          if (!fast_write_addr_valid_q)
            fail_task(NPU_STATUS_ADDR_FAULT, fast_write_addr_q);
          else if (l1_req_ready_i) begin
            fast_write_progress_q <=
              (fast_write_index_q + 1 <
               fast_beat_element_count) ? 2'd2 : 2'd1;
            if (fast_write_index_q + 2 <
                fast_beat_element_count)
              fast_write_action_q <= FAST_WRITE_NEXT_PAIR;
            else if (col_q +
                     {27'd0, fast_beat_element_count} <
                     fast_row_element_count_q)
              fast_write_action_q <= FAST_WRITE_NEXT_BEAT;
            else if (fast_current_row_last_q)
              fast_write_action_q <= FAST_WRITE_DONE;
            else
              fast_write_action_q <= FAST_WRITE_NEXT_ROW;
            state_q <= ST_FAST_WRITE_RSP;
          end

        ST_FAST_WRITE_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        fast_write_addr_q);
            else begin
              progress_q <= progress_q +
                {62'd0, fast_write_progress_q};
              case (fast_write_action_q)
                FAST_WRITE_DONE: begin
                  status_q <= NPU_STATUS_SUCCESS;
                  state_q <= ST_DONE;
                end

                FAST_WRITE_NEXT_ROW: begin
                  row_q <= row_q + 1;
                  col_q <= 32'd0;
                  fast_src0_row_base_q <=
                    fast_src0_row_base_q + {16'd0, src0_row_stride};
                  fast_src1_row_base_q <=
                    fast_src1_row_base_q + {16'd0, src1_row_stride};
                  fast_dst_row_base_q <=
                    fast_dst_row_base_q + {16'd0, dst_row_stride};
                  fast_src0_addr_q <= fast_next_src0_row_addr;
                  fast_src1_addr_q <= fast_next_src1_row_addr;
                  fast_dst_addr_q <= fast_next_dst_row_addr;
                  fast_group_q <= 2'd0;
                  fast_write_index_q <= 4'd0;
                  fast_row_element_count_q <=
                    (row_q + 32'd2 >= rows) ?
                    valid_length : length;
                  fast_current_row_last_q <=
                    row_q + 32'd2 >= rows;
                  state_q <= ST_FAST_ADDR_CHECK;
                end

                FAST_WRITE_NEXT_BEAT: begin
                  col_q <= col_q + {27'd0, fast_elements_per_beat};
                  fast_src0_addr_q <= fast_next_src0_beat_addr;
                  fast_src1_addr_q <= fast_next_src1_beat_addr;
                  fast_dst_addr_q <= fast_next_dst_beat_addr;
                  fast_group_q <= 2'd0;
                  fast_write_index_q <= 4'd0;
                  state_q <= ST_FAST_ADDR_CHECK;
                end

                default: begin
                  fast_write_index_q <= fast_write_index_q + 4'd2;
                  state_q <= ST_FAST_WRITE_PREP;
                end
              endcase
            end
          end

        ST_SRC2_REQ:
          if (!element_src2_addr_valid_q)
            fail_task(
              NPU_STATUS_ADDR_FAULT, element_src2_addr_q[47:0]
            );
          else if (l1_req_ready_i)
            state_q <= ST_SRC2_RSP;

        ST_SRC2_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        element_src2_addr_q[47:0]);
            else begin
              src2_value_q <= 32'(load_element(
                l1_rsp_rdata_i, element_src2_addr_q[2:0],
                element_src2_high_nibble_q, src2_dtype
              ));
              state_q <= vector_mul_opcode ? ST_MUL : ST_EXEC;
            end
          end

        ST_KEEP_REQ:
          if (!element_dst_addr_valid_q)
            fail_task(
              NPU_STATUS_ADDR_FAULT, element_dst_addr_q[47:0]
            );
          else if (l1_req_ready_i)
            state_q <= ST_KEEP_RSP;

        ST_KEEP_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        element_dst_addr_q[47:0]);
            else begin
              result_q <= load_element(
                l1_rsp_rdata_i, element_dst_addr_q[2:0],
                element_dst_high_nibble_q, dst_dtype
              );
              rmw_beat_q <= l1_rsp_rdata_i;
              state_q <= ST_WRITE_REQ;
            end
          end

        ST_EXEC: begin
          arithmetic_result = 64'sd0;
          compare_result = 1'b0;
          case (opcode_q)
            NPU_VECTOR_ADD:
              arithmetic_result = src0_value_q + src1_value_q;
            NPU_VECTOR_SUB:
              arithmetic_result = src0_value_q - src1_value_q;
            NPU_VECTOR_MAX:
              arithmetic_result =
                src0_value_q > src1_value_q ? src0_value_q : src1_value_q;
            NPU_VECTOR_MIN:
              arithmetic_result =
                src0_value_q < src1_value_q ? src0_value_q : src1_value_q;
            NPU_VECTOR_CMP: begin
              case (compare_mode)
                8'd0: compare_result = src0_value_q == src1_value_q;
                8'd1: compare_result = src0_value_q != src1_value_q;
                8'd2: compare_result = src0_value_q < src1_value_q;
                8'd3: compare_result = src0_value_q <= src1_value_q;
                8'd4: compare_result = src0_value_q > src1_value_q;
                default: compare_result = src0_value_q >= src1_value_q;
              endcase
              arithmetic_result = compare_result ? 64'sd1 : 64'sd0;
            end
            NPU_VECTOR_SELECT:
              arithmetic_result =
                mask_value_q ? src1_value_q : src0_value_q;
            NPU_VECTOR_CLAMP:
              if (src0_value_q <
                  $signed({{32{scalar0[31]}}, scalar0}))
                arithmetic_result =
                  $signed({{32{scalar0[31]}}, scalar0});
              else if (src0_value_q >
                       $signed({{32{scalar1[31]}}, scalar1}))
                arithmetic_result =
                  $signed({{32{scalar1[31]}}, scalar1});
              else
                arithmetic_result = src0_value_q;
            default:
              arithmetic_result =
                src0_value_q < 0 ? 64'sd0 : src0_value_q;
          endcase

          overflow = arithmetic_result < dtype_min(dst_dtype) ||
                     arithmetic_result > dtype_max(dst_dtype);
          if (overflow && overflow_mode == 8'd1)
            fail_task(
              NPU_STATUS_NUMERIC_EXCEPTION, element_dst_addr_q[47:0]
            );
          else begin
            if (overflow_mode == 8'd2)
              result_q <= wrap_to_dtype(
                arithmetic_result[31:0], dst_dtype
              );
            else
              result_q <= clip_to_dtype(arithmetic_result, dst_dtype);
            rmw_beat_q <= 64'd0;
            if (!element_dst_addr_valid_q)
              fail_task(
                NPU_STATUS_ADDR_FAULT, element_dst_addr_q[47:0]
              );
            else
              state_q <= (dst_dtype == NPU_DTYPE_INT4) ?
                ST_RMW_REQ : ST_WRITE_REQ;
          end
        end

        ST_MUL: begin
          mul_product_q <= mul_product;
          mul_addend_q <= src2_value_q;
          mul_is_fma_q <= opcode_q == NPU_VECTOR_FMA;
          mul_dst_dtype_q <= dst_dtype;
          mul_overflow_mode_q <= overflow_mode;
          mul_dst_addr_q <= element_dst_addr_q[47:0];
          state_q <= ST_MUL_POST;
        end

        ST_MUL_POST: begin
          arithmetic_result =
            $signed({{16{mul_product_q[47]}}, mul_product_q});
          if (mul_is_fma_q)
            arithmetic_result = arithmetic_result +
              $signed({{32{mul_addend_q[31]}}, mul_addend_q});
          overflow =
            arithmetic_result < dtype_min(mul_dst_dtype_q) ||
            arithmetic_result > dtype_max(mul_dst_dtype_q);
          if (overflow && mul_overflow_mode_q == 8'd1)
            fail_task(NPU_STATUS_NUMERIC_EXCEPTION, mul_dst_addr_q);
          else begin
            if (mul_overflow_mode_q == 8'd2)
              result_q <= wrap_to_dtype(
                arithmetic_result[31:0], mul_dst_dtype_q
              );
            else
              result_q <= clip_to_dtype(
                arithmetic_result, mul_dst_dtype_q
              );
            rmw_beat_q <= 64'd0;
            if (!element_dst_addr_valid_q)
              fail_task(
                NPU_STATUS_ADDR_FAULT, mul_dst_addr_q
              );
            else
              state_q <=
                (mul_dst_dtype_q == NPU_DTYPE_INT4) ?
                ST_RMW_REQ : ST_WRITE_REQ;
          end
        end

        ST_RMW_REQ:
          if (!element_dst_addr_valid_q)
            fail_task(
              NPU_STATUS_ADDR_FAULT, element_dst_addr_q[47:0]
            );
          else if (l1_req_ready_i)
            state_q <= ST_RMW_RSP;

        ST_RMW_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        element_dst_addr_q[47:0]);
            else begin
              rmw_beat_q <= l1_rsp_rdata_i;
              state_q <= ST_WRITE_REQ;
            end
          end

        ST_WRITE_REQ:
          if (!element_dst_addr_valid_q)
            fail_task(
              NPU_STATUS_ADDR_FAULT, element_dst_addr_q[47:0]
            );
          else if (l1_req_ready_i) begin
            write_last_col_q <=
              col_q + 1 >=
              ((row_q + 1 == rows) ? valid_length : length);
            write_last_row_q <= row_q + 1 >= rows;
            state_q <= ST_WRITE_RSP;
          end

        ST_WRITE_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(memory_status_to_task(l1_rsp_status_i),
                        element_dst_addr_q[47:0]);
            else begin
              progress_q <= progress_q + 1;
              if (!write_last_col_q) begin
                col_q <= col_q + 1;
                mask_value_q <= 1'b1;
                state_q <= ST_ADDR_PREP;
              end else if (!write_last_row_q) begin
                row_q <= row_q + 1;
                col_q <= 32'd0;
                mask_value_q <= 1'b1;
                state_q <= ST_ADDR_PREP;
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
