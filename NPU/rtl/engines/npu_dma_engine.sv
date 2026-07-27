module npu_dma_engine (
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
  input  logic [2:0]    l1_rsp_status_i,

  output logic          mif_req_valid_o,
  input  logic          mif_req_ready_i,
  output logic          mif_req_write_o,
  output logic [47:0]   mif_req_addr_o,
  output logic [63:0]   mif_req_wdata_o,
  output logic [7:0]    mif_req_wstrb_o,
  input  logic          mif_rsp_valid_i,
  output logic          mif_rsp_ready_o,
  input  logic [63:0]   mif_rsp_rdata_i,
  input  logic [2:0]    mif_rsp_status_i
);

  import npu_engine_pkg::*;

  typedef enum logic [4:0] {
    ST_IDLE,
    ST_CHECK,
    ST_SHAPE_LOAD,
    ST_SHAPE_MUL,
    ST_REGION_CHECK,
    ST_CURSOR_INIT,
    ST_PREP,
    ST_READ_REQ,
    ST_READ_RSP,
    ST_CONVERT,
    ST_RMW_REQ,
    ST_RMW_RSP,
    ST_WRITE_REQ,
    ST_WRITE_RSP,
    ST_ADVANCE,
    ST_DONE
  } state_t;

  state_t state_q;
  logic [2047:0] desc_q;
  logic [7:0] opcode_q;
  logic verify_pass_q;
  logic signed [63:0] source_value_q;
  logic signed [63:0] result_q;
  logic [63:0] rmw_beat_q;
  logic [7:0] status_q;
  logic [47:0] fault_addr_q;
  logic [63:0] progress_q;

  /*
   * Address state advances with the logical tensor indexes.  The last
   * dimension is contiguous; dimensions 0 through rank-2 use the descriptor
   * strides.  Keeping the current addresses and the accumulated contribution
   * of every outer dimension removes division, remainder, and multiply
   * operations from the per-element path.
   */
  logic [31:0] index_q [0:4];
  logic [63:0] src_dim_offset_q [0:4];
  logic [63:0] dst_dim_offset_q [0:4];
  logic [63:0] src_inner_base_q;
  logic [63:0] dst_inner_base_q;
  logic [63:0] current_src_addr_q;
  logic [63:0] current_dst_addr_q;
  logic source_high_nibble_q;
  logic destination_high_nibble_q;
  logic [2:0] advance_dim_q;

  logic [15:0] segment_index_q;
  logic [15:0] segment_byte_q;
  logic [63:0] src_segment_base_q;
  logic [63:0] dst_segment_base_q;

  logic [31:0] transpose_row_q;
  logic [31:0] transpose_col_q;
  logic [63:0] transpose_src_row_base_q;
  logic [63:0] transpose_dst_inner_base_q;

  /*
   * Shape overflow checking uses a bit-serial 128-by-32 multiply.  One
   * 128-bit add is performed per cycle, so rank 1 through 5 no longer creates
   * a combinational cascade of wide multipliers.
   */
  logic [127:0] shape_product_q;
  logic [127:0] shape_mul_accum_q;
  logic [127:0] shape_mul_multiplicand_q;
  logic [31:0] shape_mul_multiplier_q;
  logic [5:0] shape_mul_bit_q;
  logic [2:0] shape_dim_q;
  logic shape_zero_q;
  logic shape_overflow_q;

  wire [7:0] desc_version = desc_q[7:0];
  wire [7:0] desc_type = desc_q[15:8];
  wire [15:0] desc_bytes = desc_q[31:16];
  wire [63:0] src_base = desc_q[64 +: 64];
  wire [63:0] dst_base = desc_q[256 +: 64];
  wire [31:0] numeric_cfg = desc_q[448 +: 32];
  wire [1:0] src_dtype = numeric_cfg[1:0];
  wire [1:0] src1_dtype = numeric_cfg[3:2];
  wire [1:0] src2_dtype = numeric_cfg[5:4];
  wire [1:0] dst_dtype = numeric_cfg[7:6];
  wire unused_numeric_cfg = ^numeric_cfg[16:10];
  wire unused_command_id = ^command_id_i;
  wire unused_result_upper = ^result_q[63:32];
  wire unused_desc_fields = ^{
    desc_q[2047:1408],
    desc_q[1215:1184],
    desc_q[1151:1120],
    desc_q[959:928],
    desc_q[767:736],
    desc_q[511:480],
    desc_q[447:320],
    desc_q[255:128],
    desc_q[63:32]
  };

  wire [7:0] rank = desc_q[16'h40 * 8 +: 8];
  wire [7:0] src_space = desc_q[16'h41 * 8 +: 8];
  wire [7:0] dst_space = desc_q[16'h42 * 8 +: 8];
  wire [7:0] convert_mode = desc_q[16'h43 * 8 +: 8];
  wire [7:0] burst_beats_minus1 = desc_q[16'h44 * 8 +: 8];
  wire [7:0] max_outstanding = desc_q[16'h45 * 8 +: 8];
  wire src_nibble = desc_q[16'h46 * 8];
  wire dst_nibble = desc_q[16'h47 * 8];
  wire [159:0] shape_packed = desc_q[16'h48 * 8 +: 160];
  wire [159:0] src_stride_packed = desc_q[16'h60 * 8 +: 160];
  wire [159:0] dst_stride_packed = desc_q[16'h78 * 8 +: 160];
  wire [31:0] fill_value = desc_q[16'h90 * 8 +: 32];
  wire [63:0] src_region_bytes = desc_q[16'h98 * 8 +: 64];
  wire [63:0] dst_region_bytes = desc_q[16'ha0 * 8 +: 64];
  wire [15:0] segment_count = desc_q[16'ha8 * 8 +: 16];
  wire [15:0] segment_bytes = desc_q[16'haa * 8 +: 16];
  wire [31:0] segment_stride = desc_q[16'hac * 8 +: 32];

  function automatic logic opcode_known(input logic [7:0] opcode);
    case (opcode)
      NPU_DMA_COPY_1D,
      NPU_DMA_COPY_ND,
      NPU_DMA_FILL,
      NPU_DMA_TRANSPOSE_2D,
      NPU_DMA_PACK,
      NPU_DMA_SPLIT: return 1'b1;
      default:       return 1'b0;
    endcase
  endfunction

  function automatic logic byte_mode(input logic [7:0] opcode);
    return opcode == NPU_DMA_PACK || opcode == NPU_DMA_SPLIT;
  endfunction

  function automatic logic [31:0] shape_at(
    input logic [2:0] dimension
  );
    case (dimension)
      3'd0: return shape_packed[31:0];
      3'd1: return shape_packed[63:32];
      3'd2: return shape_packed[95:64];
      3'd3: return shape_packed[127:96];
      3'd4: return shape_packed[159:128];
      default: return 32'd0;
    endcase
  endfunction

  function automatic logic [31:0] src_stride_at(
    input logic [2:0] dimension
  );
    case (dimension)
      3'd0: return src_stride_packed[31:0];
      3'd1: return src_stride_packed[63:32];
      3'd2: return src_stride_packed[95:64];
      3'd3: return src_stride_packed[127:96];
      3'd4: return src_stride_packed[159:128];
      default: return 32'd0;
    endcase
  endfunction

  function automatic logic [31:0] dst_stride_at(
    input logic [2:0] dimension
  );
    case (dimension)
      3'd0: return dst_stride_packed[31:0];
      3'd1: return dst_stride_packed[63:32];
      3'd2: return dst_stride_packed[95:64];
      3'd3: return dst_stride_packed[127:96];
      3'd4: return dst_stride_packed[159:128];
      default: return 32'd0;
    endcase
  endfunction

  function automatic logic signed [63:0] fill_as_integer(
    input logic [31:0] value,
    input logic [1:0] dtype
  );
    case (dtype)
      NPU_DTYPE_INT4: return {{60{value[3]}}, value[3:0]};
      NPU_DTYPE_INT8: return {{56{value[7]}}, value[7:0]};
      NPU_DTYPE_INT16: return {{48{value[15]}}, value[15:0]};
      default: return {{32{value[31]}}, value[31:0]};
    endcase
  endfunction

  wire [63:0] current_src_addr = current_src_addr_q;
  wire [63:0] current_dst_addr = current_dst_addr_q;
  wire source_high_nibble = source_high_nibble_q;
  wire destination_high_nibble = destination_high_nibble_q;
  wire [1:0] transfer_src_dtype =
    byte_mode(opcode_q) ? NPU_DTYPE_INT8 : src_dtype;
  wire [1:0] transfer_dst_dtype =
    byte_mode(opcode_q) ? NPU_DTYPE_INT8 : dst_dtype;
  wire [63:0] source_end_addr =
    current_src_addr +
    {61'd0, dtype_storage_bytes(transfer_src_dtype)};
  wire [63:0] destination_end_addr =
    current_dst_addr +
    {61'd0, dtype_storage_bytes(transfer_dst_dtype)};

  wire read_rsp_valid =
    src_space == 0 ? l1_rsp_valid_i : mif_rsp_valid_i;
  wire [63:0] read_rsp_data =
    src_space == 0 ? l1_rsp_rdata_i : mif_rsp_rdata_i;
  wire [2:0] read_rsp_status =
    src_space == 0 ? l1_rsp_status_i : mif_rsp_status_i;
  wire write_rsp_valid =
    dst_space == 0 ? l1_rsp_valid_i : mif_rsp_valid_i;
  wire [2:0] write_rsp_status =
    dst_space == 0 ? l1_rsp_status_i : mif_rsp_status_i;

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

  task automatic finish_pass_or_task;
    begin
      if (verify_pass_q) begin
        verify_pass_q <= 1'b0;
        state_q <= ST_CURSOR_INIT;
      end else begin
        status_q <= NPU_STATUS_SUCCESS;
        state_q <= ST_DONE;
      end
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

    mif_req_valid_o = 1'b0;
    mif_req_write_o = 1'b0;
    mif_req_addr_o = 48'd0;
    mif_req_wdata_o = 64'd0;
    mif_req_wstrb_o = 8'd0;
    mif_rsp_ready_o = 1'b0;

    if (state_q == ST_READ_REQ) begin
      if (src_space == 0) begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {current_src_addr[19:3], 3'b000};
      end else begin
        mif_req_valid_o = 1'b1;
        mif_req_addr_o = {current_src_addr[47:3], 3'b000};
      end
    end

    if (state_q == ST_RMW_REQ) begin
      if (dst_space == 0) begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {current_dst_addr[19:3], 3'b000};
      end else begin
        mif_req_valid_o = 1'b1;
        mif_req_addr_o = {current_dst_addr[47:3], 3'b000};
      end
    end

    if (state_q == ST_WRITE_REQ) begin
      if (dst_space == 0) begin
        l1_req_valid_o = 1'b1;
        l1_req_write_o = 1'b1;
        l1_req_addr_o = {current_dst_addr[19:3], 3'b000};
        l1_req_wdata_o = store_element_data(
          rmw_beat_q, result_q[31:0], current_dst_addr[2:0],
          destination_high_nibble, transfer_dst_dtype
        );
        l1_req_wstrb_o =
          store_element_strb(current_dst_addr[2:0], transfer_dst_dtype);
      end else begin
        mif_req_valid_o = 1'b1;
        mif_req_write_o = 1'b1;
        mif_req_addr_o = {current_dst_addr[47:3], 3'b000};
        mif_req_wdata_o = store_element_data(
          rmw_beat_q, result_q[31:0], current_dst_addr[2:0],
          destination_high_nibble, transfer_dst_dtype
        );
        mif_req_wstrb_o =
          store_element_strb(current_dst_addr[2:0], transfer_dst_dtype);
      end
    end

    if (state_q == ST_READ_RSP) begin
      if (src_space == 0)
        l1_rsp_ready_o = 1'b1;
      else
        mif_rsp_ready_o = 1'b1;
    end

    if (state_q == ST_RMW_RSP || state_q == ST_WRITE_RSP) begin
      if (dst_space == 0)
        l1_rsp_ready_o = 1'b1;
      else
        mif_rsp_ready_o = 1'b1;
    end
  end

  always_ff @(posedge clk_i or negedge reset_n) begin
    logic signed [63:0] converted_value;
    logic [127:0] shape_mul_sum;
    logic read_ready;
    logic rmw_ready;
    logic write_ready;
    logic source_in_range;
    logic destination_in_range;
    logic [2:0] inner_dimension;
    integer dimension;
    if (!reset_n) begin
      /*
       * The state is the only asynchronously reset storage.  Descriptor,
       * datapath, address, and counter registers are initialized when a task
       * is accepted or when its cursor is initialized.
       */
      state_q <= ST_IDLE;
    end else begin
      read_ready = src_space == 0 ? l1_req_ready_i : mif_req_ready_i;
      rmw_ready = dst_space == 0 ? l1_req_ready_i : mif_req_ready_i;
      write_ready = dst_space == 0 ? l1_req_ready_i : mif_req_ready_i;
      source_in_range =
        src_region_bytes != 0 &&
        current_src_addr >= src_base &&
        source_end_addr <= src_base + src_region_bytes &&
        source_end_addr >= current_src_addr;
      destination_in_range =
        dst_region_bytes != 0 &&
        current_dst_addr >= dst_base &&
        destination_end_addr <= dst_base + dst_region_bytes &&
        destination_end_addr >= current_dst_addr;

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
          else if (desc_version != 8'h01 || desc_type != 8'h01 ||
                   desc_bytes != 16'd256)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (!dtype_valid(src_dtype) || !dtype_valid(src1_dtype) ||
                   !dtype_valid(src2_dtype) || !dtype_valid(dst_dtype) ||
                   numeric_cfg[9:8] != 2'd0 ||
                   numeric_cfg[31:17] != 15'd0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (rank == 0 || rank > 5 ||
                   src_space > 1 || dst_space > 1 ||
                   convert_mode > 3 ||
                   burst_beats_minus1 > 15 ||
                   max_outstanding == 0 || max_outstanding > 16 ||
                   desc_q[16'h46 * 8 + 7 -: 7] != 0 ||
                   desc_q[16'h47 * 8 + 7 -: 7] != 0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (dst_nibble != 1'b0)
            fail_task(NPU_STATUS_BAD_DESC, dst_base[47:0]);
          else if ((src_space == 0 && src_base[63:20] != 0 &&
                    opcode_q != NPU_DMA_FILL) ||
                   (src_space == 1 && src_base[63:48] != 0 &&
                    opcode_q != NPU_DMA_FILL) ||
                   (dst_space == 0 && dst_base[63:20] != 0) ||
                   (dst_space == 1 && dst_base[63:48] != 0))
            fail_task(NPU_STATUS_ADDR_FAULT, 48'd0);
          else if (opcode_q == NPU_DMA_COPY_1D && rank != 1)
            fail_task(NPU_STATUS_BAD_SHAPE, 48'd0);
          else if (opcode_q == NPU_DMA_TRANSPOSE_2D &&
                   (rank != 2 || src_dtype != dst_dtype ||
                    convert_mode != 0))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (byte_mode(opcode_q) &&
                   (rank != 1 || convert_mode != 0 ||
                    src_dtype != dst_dtype ||
                    segment_count == 0 || segment_bytes == 0 ||
                    segment_stride < segment_bytes ||
                    shape_packed[31:0] !=
                    {16'd0, segment_count}))
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (opcode_q == NPU_DMA_FILL && convert_mode != 0)
            fail_task(NPU_STATUS_BAD_DESC, 48'd0);
          else if (opcode_q != NPU_DMA_FILL &&
                   ((convert_mode == 0 && src_dtype != dst_dtype) ||
                    (convert_mode == 1 &&
                     !((src_dtype == NPU_DTYPE_INT4 &&
                        (dst_dtype == NPU_DTYPE_INT8 ||
                         dst_dtype == NPU_DTYPE_INT16 ||
                         dst_dtype == NPU_DTYPE_INT32)) ||
                       (src_dtype == NPU_DTYPE_INT8 &&
                        (dst_dtype == NPU_DTYPE_INT16 ||
                         dst_dtype == NPU_DTYPE_INT32)) ||
                       (src_dtype == NPU_DTYPE_INT16 &&
                        dst_dtype == NPU_DTYPE_INT32))) ||
                    (convert_mode == 2 &&
                     !((src_dtype == NPU_DTYPE_INT32 &&
                        (dst_dtype == NPU_DTYPE_INT16 ||
                         dst_dtype == NPU_DTYPE_INT8 ||
                         dst_dtype == NPU_DTYPE_INT4)) ||
                       (src_dtype == NPU_DTYPE_INT16 &&
                        (dst_dtype == NPU_DTYPE_INT8 ||
                         dst_dtype == NPU_DTYPE_INT4)) ||
                       (src_dtype == NPU_DTYPE_INT8 &&
                        dst_dtype == NPU_DTYPE_INT4))) ||
                    (convert_mode == 3 &&
                     !((src_dtype == NPU_DTYPE_INT8 ||
                        src_dtype == NPU_DTYPE_INT16 ||
                        src_dtype == NPU_DTYPE_INT32) &&
                       dst_dtype == NPU_DTYPE_INT4))))
            fail_task(NPU_STATUS_DTYPE_UNSUPPORTED, 48'd0);
          else begin
            verify_pass_q <=
              opcode_q != NPU_DMA_FILL && convert_mode == 8'd3;
            if (byte_mode(opcode_q)) begin
              state_q <= ST_REGION_CHECK;
            end else begin
              shape_product_q <= 128'd1;
              shape_dim_q <= 3'd0;
              shape_zero_q <= 1'b0;
              shape_overflow_q <= 1'b0;
              state_q <= ST_SHAPE_LOAD;
            end
          end
        end

        ST_SHAPE_LOAD: begin
          shape_mul_accum_q <= 128'd0;
          shape_mul_multiplicand_q <= shape_product_q;
          shape_mul_multiplier_q <= shape_at(shape_dim_q);
          shape_mul_bit_q <= 6'd0;
          if (shape_at(shape_dim_q) == 0)
            shape_zero_q <= 1'b1;
          state_q <= ST_SHAPE_MUL;
        end

        ST_SHAPE_MUL: begin
          shape_mul_sum =
            shape_mul_accum_q +
            (shape_mul_multiplier_q[0] ?
             shape_mul_multiplicand_q : 128'd0);
          if (shape_mul_bit_q == 6'd31) begin
            shape_product_q <= shape_mul_sum;
            if (shape_mul_sum[127:64] != 0)
              shape_overflow_q <= 1'b1;
            if ({5'd0, shape_dim_q} + 8'd1 < rank) begin
              shape_dim_q <= shape_dim_q + 3'd1;
              state_q <= ST_SHAPE_LOAD;
            end else if (shape_zero_q ||
                         shape_at(shape_dim_q) == 0) begin
              status_q <= NPU_STATUS_SUCCESS;
              state_q <= ST_DONE;
            end else if (shape_overflow_q ||
                         shape_mul_sum[127:64] != 0 ||
                         shape_mul_sum[63:0] ==
                           64'hffff_ffff_ffff_ffff) begin
              fail_task(NPU_STATUS_BAD_SHAPE, 48'd0);
            end else begin
              state_q <= ST_REGION_CHECK;
            end
          end else begin
            shape_mul_accum_q <= shape_mul_sum;
            shape_mul_multiplicand_q <=
              shape_mul_multiplicand_q << 1;
            shape_mul_multiplier_q <= shape_mul_multiplier_q >> 1;
            shape_mul_bit_q <= shape_mul_bit_q + 6'd1;
          end
        end

        ST_REGION_CHECK: begin
          if (dst_region_bytes == 0 ||
              (opcode_q != NPU_DMA_FILL &&
               src_region_bytes == 0))
            fail_task(NPU_STATUS_ADDR_FAULT, 48'd0);
          else if (opcode_q != NPU_DMA_FILL &&
                   src_space == dst_space &&
                   src_base < dst_base + dst_region_bytes &&
                   dst_base < src_base + src_region_bytes)
            fail_task(NPU_STATUS_ADDR_OVERLAP, dst_base[47:0]);
          else
            state_q <= ST_CURSOR_INIT;
        end

        ST_CURSOR_INIT: begin
          for (dimension = 0;
               dimension < 5;
               dimension = dimension + 1) begin
            index_q[dimension] <= 32'd0;
            src_dim_offset_q[dimension] <= 64'd0;
            dst_dim_offset_q[dimension] <= 64'd0;
          end
          src_inner_base_q <= src_base;
          dst_inner_base_q <= dst_base;
          current_src_addr_q <= src_base;
          current_dst_addr_q <= dst_base;
          source_high_nibble_q <=
            !byte_mode(opcode_q) && src_dtype == NPU_DTYPE_INT4 ?
              src_nibble : 1'b0;
          destination_high_nibble_q <=
            !byte_mode(opcode_q) && dst_dtype == NPU_DTYPE_INT4 ?
              dst_nibble : 1'b0;
          advance_dim_q <= 3'd7;

          segment_index_q <= 16'd0;
          segment_byte_q <= 16'd0;
          src_segment_base_q <= src_base;
          dst_segment_base_q <= dst_base;

          transpose_row_q <= 32'd0;
          transpose_col_q <= 32'd0;
          transpose_src_row_base_q <= src_base;
          transpose_dst_inner_base_q <= dst_base;
          state_q <= ST_PREP;
        end

        ST_PREP: begin
          rmw_beat_q <= 64'd0;
          if (!destination_in_range)
            fail_task(NPU_STATUS_ADDR_FAULT, current_dst_addr[47:0]);
          else if (opcode_q == NPU_DMA_FILL) begin
            result_q <= fill_as_integer(fill_value, dst_dtype);
            if (transfer_dst_dtype == NPU_DTYPE_INT4 &&
                destination_high_nibble)
              state_q <= ST_RMW_REQ;
            else
              state_q <= ST_WRITE_REQ;
          end else if (!source_in_range)
            fail_task(NPU_STATUS_ADDR_FAULT, current_src_addr[47:0]);
          else if ((transfer_src_dtype == NPU_DTYPE_INT32 &&
                    current_src_addr[2:0] > 3'd4) ||
                   (transfer_src_dtype == NPU_DTYPE_INT16 &&
                    current_src_addr[2:0] > 3'd6))
            fail_task(NPU_STATUS_ADDR_FAULT, current_src_addr[47:0]);
          else
            state_q <= ST_READ_REQ;
        end

        ST_READ_REQ:
          if (read_ready)
            state_q <= ST_READ_RSP;

        ST_READ_RSP:
          if (read_rsp_valid) begin
            if (read_rsp_status != 0)
              fail_task(memory_status_to_task(read_rsp_status),
                        current_src_addr[47:0]);
            else begin
              source_value_q <= load_element(
                read_rsp_data, current_src_addr[2:0],
                source_high_nibble, transfer_src_dtype
              );
              state_q <= ST_CONVERT;
            end
          end

        ST_CONVERT: begin
          converted_value = source_value_q;
          if (verify_pass_q) begin
            if (source_value_q < -64'sd8 || source_value_q > 64'sd7)
              fail_task(NPU_STATUS_NUMERIC_EXCEPTION,
                        current_src_addr[47:0]);
            else begin
              advance_dim_q <= 3'd7;
              state_q <= ST_ADVANCE;
            end
          end else begin
            if (convert_mode == 8'd2)
              converted_value = clip_to_dtype(source_value_q, dst_dtype);
            result_q <= converted_value;
            rmw_beat_q <= 64'd0;
            if ((transfer_dst_dtype == NPU_DTYPE_INT32 &&
                 current_dst_addr[2:0] > 3'd4) ||
                (transfer_dst_dtype == NPU_DTYPE_INT16 &&
                 current_dst_addr[2:0] > 3'd6))
              fail_task(NPU_STATUS_ADDR_FAULT, current_dst_addr[47:0]);
            else if (transfer_dst_dtype == NPU_DTYPE_INT4 &&
                     destination_high_nibble)
              state_q <= ST_RMW_REQ;
            else
              state_q <= ST_WRITE_REQ;
          end
        end

        ST_RMW_REQ:
          if (rmw_ready)
            state_q <= ST_RMW_RSP;

        ST_RMW_RSP:
          if (write_rsp_valid) begin
            if (write_rsp_status != 0)
              fail_task(memory_status_to_task(write_rsp_status),
                        current_dst_addr[47:0]);
            else begin
              rmw_beat_q <=
                dst_space == 0 ? l1_rsp_rdata_i : mif_rsp_rdata_i;
              state_q <= ST_WRITE_REQ;
            end
          end

        ST_WRITE_REQ:
          if (write_ready)
            state_q <= ST_WRITE_RSP;

        ST_WRITE_RSP:
          if (write_rsp_valid) begin
            if (write_rsp_status != 0)
              fail_task(memory_status_to_task(write_rsp_status),
                        current_dst_addr[47:0]);
            else begin
              if (transfer_dst_dtype == NPU_DTYPE_INT4) begin
                if (!destination_high_nibble)
                  progress_q <= progress_q + 64'd1;
              end else
                progress_q <=
                  progress_q +
                  {61'd0, dtype_bytes(transfer_dst_dtype)};
              advance_dim_q <= 3'd7;
              state_q <= ST_ADVANCE;
            end
          end

        ST_ADVANCE: begin
          case (opcode_q)
            NPU_DMA_PACK,
            NPU_DMA_SPLIT: begin
              if (segment_byte_q + 16'd1 < segment_bytes) begin
                segment_byte_q <= segment_byte_q + 16'd1;
                current_src_addr_q <= current_src_addr_q + 64'd1;
                current_dst_addr_q <= current_dst_addr_q + 64'd1;
                state_q <= ST_PREP;
              end else if (segment_index_q + 16'd1 <
                           segment_count) begin
                segment_index_q <= segment_index_q + 16'd1;
                segment_byte_q <= 16'd0;
                if (opcode_q == NPU_DMA_PACK) begin
                  src_segment_base_q <=
                    src_segment_base_q +
                    {32'd0, segment_stride};
                  dst_segment_base_q <=
                    dst_segment_base_q +
                    {48'd0, segment_bytes};
                  current_src_addr_q <=
                    src_segment_base_q +
                    {32'd0, segment_stride};
                  current_dst_addr_q <=
                    dst_segment_base_q +
                    {48'd0, segment_bytes};
                end else begin
                  src_segment_base_q <=
                    src_segment_base_q +
                    {48'd0, segment_bytes};
                  dst_segment_base_q <=
                    dst_segment_base_q +
                    {32'd0, segment_stride};
                  current_src_addr_q <=
                    src_segment_base_q +
                    {48'd0, segment_bytes};
                  current_dst_addr_q <=
                    dst_segment_base_q +
                    {32'd0, segment_stride};
                end
                state_q <= ST_PREP;
              end else begin
                finish_pass_or_task();
              end
            end

            NPU_DMA_TRANSPOSE_2D: begin
              if (transpose_col_q + 32'd1 < shape_at(3'd1)) begin
                transpose_col_q <= transpose_col_q + 32'd1;
                if (src_dtype == NPU_DTYPE_INT4) begin
                  source_high_nibble_q <= ~source_high_nibble_q;
                  if (source_high_nibble_q)
                    current_src_addr_q <= current_src_addr_q + 64'd1;
                end else begin
                  current_src_addr_q <=
                    current_src_addr_q +
                    {61'd0, dtype_bytes(src_dtype)};
                end
                current_dst_addr_q <=
                  current_dst_addr_q +
                  {32'd0, dst_stride_at(3'd0)};
                state_q <= ST_PREP;
              end else if (transpose_row_q + 32'd1 <
                           shape_at(3'd0)) begin
                transpose_row_q <= transpose_row_q + 32'd1;
                transpose_col_q <= 32'd0;
                transpose_src_row_base_q <=
                  transpose_src_row_base_q +
                  {32'd0, src_stride_at(3'd0)};
                current_src_addr_q <=
                  transpose_src_row_base_q +
                  {32'd0, src_stride_at(3'd0)};
                source_high_nibble_q <=
                  src_dtype == NPU_DTYPE_INT4 ? src_nibble : 1'b0;
                if (dst_dtype == NPU_DTYPE_INT4) begin
                  destination_high_nibble_q <=
                    ~destination_high_nibble_q;
                  if (destination_high_nibble_q) begin
                    transpose_dst_inner_base_q <=
                      transpose_dst_inner_base_q + 64'd1;
                    current_dst_addr_q <=
                      transpose_dst_inner_base_q + 64'd1;
                  end else begin
                    current_dst_addr_q <=
                      transpose_dst_inner_base_q;
                  end
                end else begin
                  transpose_dst_inner_base_q <=
                    transpose_dst_inner_base_q +
                    {61'd0, dtype_bytes(dst_dtype)};
                  current_dst_addr_q <=
                    transpose_dst_inner_base_q +
                    {61'd0, dtype_bytes(dst_dtype)};
                  destination_high_nibble_q <= 1'b0;
                end
                state_q <= ST_PREP;
              end else begin
                finish_pass_or_task();
              end
            end

            default: begin
              inner_dimension = rank[2:0] - 3'd1;
              if (advance_dim_q == 3'd7) begin
                if (index_q[inner_dimension] + 32'd1 <
                    shape_at(inner_dimension)) begin
                  index_q[inner_dimension] <=
                    index_q[inner_dimension] + 32'd1;
                  if (src_dtype == NPU_DTYPE_INT4) begin
                    source_high_nibble_q <= ~source_high_nibble_q;
                    if (source_high_nibble_q)
                      current_src_addr_q <= current_src_addr_q + 64'd1;
                  end else begin
                    current_src_addr_q <=
                      current_src_addr_q +
                      {61'd0, dtype_bytes(src_dtype)};
                  end
                  if (dst_dtype == NPU_DTYPE_INT4) begin
                    destination_high_nibble_q <=
                      ~destination_high_nibble_q;
                    if (destination_high_nibble_q)
                      current_dst_addr_q <= current_dst_addr_q + 64'd1;
                  end else begin
                    current_dst_addr_q <=
                      current_dst_addr_q +
                      {61'd0, dtype_bytes(dst_dtype)};
                  end
                  state_q <= ST_PREP;
                end else begin
                  index_q[inner_dimension] <= 32'd0;
                  source_high_nibble_q <=
                    src_dtype == NPU_DTYPE_INT4 ? src_nibble : 1'b0;
                  destination_high_nibble_q <=
                    dst_dtype == NPU_DTYPE_INT4 ? dst_nibble : 1'b0;
                  if (rank == 8'd1)
                    finish_pass_or_task();
                  else
                    advance_dim_q <= rank[2:0] - 3'd2;
                end
              end else if (index_q[advance_dim_q] + 32'd1 <
                           shape_at(advance_dim_q)) begin
                index_q[advance_dim_q] <=
                  index_q[advance_dim_q] + 32'd1;
                src_dim_offset_q[advance_dim_q] <=
                  src_dim_offset_q[advance_dim_q] +
                  {32'd0, src_stride_at(advance_dim_q)};
                dst_dim_offset_q[advance_dim_q] <=
                  dst_dim_offset_q[advance_dim_q] +
                  {32'd0, dst_stride_at(advance_dim_q)};
                src_inner_base_q <=
                  src_inner_base_q +
                  {32'd0, src_stride_at(advance_dim_q)};
                dst_inner_base_q <=
                  dst_inner_base_q +
                  {32'd0, dst_stride_at(advance_dim_q)};
                current_src_addr_q <=
                  src_inner_base_q +
                  {32'd0, src_stride_at(advance_dim_q)};
                current_dst_addr_q <=
                  dst_inner_base_q +
                  {32'd0, dst_stride_at(advance_dim_q)};
                source_high_nibble_q <=
                  src_dtype == NPU_DTYPE_INT4 ? src_nibble : 1'b0;
                destination_high_nibble_q <=
                  dst_dtype == NPU_DTYPE_INT4 ? dst_nibble : 1'b0;
                advance_dim_q <= 3'd7;
                state_q <= ST_PREP;
              end else begin
                index_q[advance_dim_q] <= 32'd0;
                src_inner_base_q <=
                  src_inner_base_q -
                  src_dim_offset_q[advance_dim_q];
                dst_inner_base_q <=
                  dst_inner_base_q -
                  dst_dim_offset_q[advance_dim_q];
                src_dim_offset_q[advance_dim_q] <= 64'd0;
                dst_dim_offset_q[advance_dim_q] <= 64'd0;
                if (advance_dim_q == 3'd0)
                  finish_pass_or_task();
                else
                  advance_dim_q <= advance_dim_q - 3'd1;
              end
            end
          endcase
        end

        ST_DONE:
          if (done_ready_i)
            state_q <= ST_IDLE;

        default: state_q <= ST_IDLE;
      endcase
    end
  end

endmodule
