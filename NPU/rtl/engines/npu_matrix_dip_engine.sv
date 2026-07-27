module npu_matrix_dip_engine (
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

  localparam int unsigned ARRAY_N = 4;
  localparam int unsigned MAX_LOGICAL_N = ARRAY_N * 4;
  localparam int unsigned DIP_ACCUM_ROW_W = ARRAY_N * 4 * 64;

  localparam logic [1:0] DIP_MODE_INT16 = 2'd0;
  localparam logic [1:0] DIP_MODE_INT8 = 2'd1;
  localparam logic [1:0] DIP_MODE_INT4 = 2'd2;

  typedef enum logic [4:0] {
    ST_IDLE,
    ST_CHECK,
    ST_B_ROW_INIT,
    ST_B_LOAD,
    ST_B_REQ,
    ST_B_RSP,
    ST_B_SEND,
    ST_A_ROW_INIT,
    ST_A_LOAD,
    ST_A_REQ,
    ST_A_RSP,
    ST_A_SEND,
    ST_WAIT_RESULT,
    ST_WRITE_ROW_LOAD,
    ST_WRITE_INIT,
    ST_WRITE_REQ,
    ST_WRITE_RSP,
    ST_DONE
  } state_t;

  state_t state_q;
  logic [2047:0] desc_q;
  logic [7:0] opcode_q;
  logic [1:0] dip_mode_q;
  logic [4:0] logical_n_q;
  logic [31:0] batch_q;
  logic [4:0] b_row_index_q;
  logic [4:0] b_element_index_q;
  logic [4:0] a_row_index_q;
  logic [4:0] a_element_index_q;
  logic [63:0] b_row_q;
  logic [63:0] a_row_q;
  logic [63:0] a_batch_base_q;
  logic [63:0] b_batch_base_q;
  logic [63:0] c_batch_base_q;
  logic [63:0] a_row_base_q;
  logic [63:0] b_row_base_q;
  logic [63:0] c_row_base_q;
  logic [63:0] read_addr_q;
  logic [63:0] write_addr_q;
  logic [63:0] write_data_q;
  logic [DIP_ACCUM_ROW_W-1:0] write_row_data_q;
  logic read_cache_valid_q;
  logic [60:0] read_cache_tag_q;
  logic [63:0] read_cache_data_q;
  logic [4:0] captured_rows_q;
  logic [DIP_ACCUM_ROW_W-1:0] accum_rows_q [0:MAX_LOGICAL_N-1];
  logic [4:0] write_row_q;
  logic [3:0] write_pair_q;
  logic [7:0] status_q;
  logic [47:0] fault_addr_q;
  logic [63:0] progress_q;

  wire [63:0] a_base = desc_q[64 +: 64];
  wire [63:0] b_base = desc_q[128 +: 64];
  wire [63:0] c_base = desc_q[256 +: 64];
  wire [31:0] numeric_cfg = desc_q[448 +: 32];
  wire [1:0] a_dtype = numeric_cfg[1:0];
  wire [1:0] b_dtype = numeric_cfg[3:2];
  wire [7:0] b_pack_format = desc_q[16'h91 * 8 +: 8];
  wire [7:0] overflow_mode = desc_q[16'h94 * 8 +: 8];
  wire [31:0] lda_bytes = desc_q[16'h60 * 8 +: 32];
  wire [31:0] ldb_bytes = desc_q[16'h64 * 8 +: 32];
  wire [31:0] ldc_bytes = desc_q[16'h68 * 8 +: 32];
  wire [63:0] a_batch_stride = desc_q[16'h70 * 8 +: 64];
  wire [63:0] b_batch_stride = desc_q[16'h78 * 8 +: 64];
  wire [63:0] c_batch_stride = desc_q[16'h80 * 8 +: 64];
  wire [31:0] batch_count = desc_q[16'h4c * 8 +: 32];
  wire b_is_tiled =
    b_pack_format == 8'd2 || b_pack_format == 8'd3 ||
    b_pack_format == 8'd6;

  logic dip_b_valid;
  logic dip_b_ready;
  logic dip_a_valid;
  logic dip_a_ready;
  logic dip_c_valid;
  logic dip_c_last;
  logic [ARRAY_N * 32 - 1:0] dip_c_row;
  logic [DIP_ACCUM_ROW_W-1:0] dip_c_accum_row;
  logic dip_busy;
  logic dip_tile_done;

  function automatic logic [4:0] logical_size_from_dtype(
    input logic [1:0] dtype
  );
    case (dtype)
      NPU_DTYPE_INT16: return 5'd4;
      NPU_DTYPE_INT8:  return 5'd8;
      NPU_DTYPE_INT4:  return 5'd16;
      default:         return 5'd0;
    endcase
  endfunction

  function automatic logic [1:0] dip_mode_from_dtype(
    input logic [1:0] dtype
  );
    case (dtype)
      NPU_DTYPE_INT8: return DIP_MODE_INT8;
      NPU_DTYPE_INT4: return DIP_MODE_INT4;
      default:        return DIP_MODE_INT16;
    endcase
  endfunction

  function automatic logic [63:0] packed_element_offset(
    input logic [4:0] element_index,
    input logic [1:0] dtype
  );
    begin
      if (dtype == NPU_DTYPE_INT4)
        return {59'd0, element_index} >> 1;
      if (dtype == NPU_DTYPE_INT8)
        return {59'd0, element_index};
      return {59'd0, element_index} << 1;
    end
  endfunction

  function automatic logic crosses_beat(
    input logic [2:0] byte_lane,
    input logic [1:0] dtype
  );
    return dtype == NPU_DTYPE_INT16 && byte_lane > 3'd6;
  endfunction

  function automatic logic signed [63:0] selected_accum(
    input logic [DIP_ACCUM_ROW_W-1:0] row_data,
    input logic [3:0] logical_col,
    input logic [1:0] mode
  );
    logic [3:0] flat_lane;
    logic [9:0] bit_index;
    begin
      case (mode)
        DIP_MODE_INT8:
          flat_lane = 4'(
            {logical_col[2:1], 2'b00} +
            {3'd0, logical_col[0]}
          );
        DIP_MODE_INT4:
          flat_lane = logical_col[3:0];
        default:
          flat_lane = {logical_col[1:0], 2'b00};
      endcase
      bit_index = {flat_lane, 6'b000000};
      return $signed(row_data[bit_index +: 64]);
    end
  endfunction

  function automatic logic [31:0] int32_result(
    input logic signed [63:0] value,
    input logic [7:0] overflow
  );
    begin
      if (overflow == 8'd2)
        return value[31:0];
      if (value < -64'sd2147483648)
        return 32'h8000_0000;
      if (value > 64'sd2147483647)
        return 32'h7fff_ffff;
      return value[31:0];
    end
  endfunction

  logic [63:0] tiled_b_element_addr;
  always_comb begin
    tiled_b_element_addr = b_batch_base_q;
    case (b_dtype)
      NPU_DTYPE_INT16:
        tiled_b_element_addr =
          b_batch_base_q +
          ({59'd0, b_row_index_q} << 4) +
          ({59'd0, b_element_index_q} << 1);
      NPU_DTYPE_INT8:
        tiled_b_element_addr =
          b_batch_base_q +
          ({59'd0, b_row_index_q} << 3) +
          {59'd0, b_element_index_q};
      default:
        tiled_b_element_addr =
          b_batch_base_q +
          (b_element_index_q[3] ? 64'd64 : 64'd0) +
          ({59'd0, b_row_index_q} << 2) +
          {61'd0, b_element_index_q[2:1]};
    endcase
  end

  wire [63:0] b_load_addr =
    b_is_tiled ? tiled_b_element_addr :
    b_row_base_q + packed_element_offset(b_element_index_q, b_dtype);
  wire [63:0] a_load_addr =
    a_row_base_q + packed_element_offset(a_element_index_q, a_dtype);
  wire b_read_state =
    state_q == ST_B_LOAD || state_q == ST_B_REQ ||
    state_q == ST_B_RSP;
  wire [63:0] current_load_addr =
    b_read_state ? b_load_addr : a_load_addr;
  wire [1:0] active_read_dtype =
    b_read_state ? b_dtype : a_dtype;
  wire active_element_lsb =
    (state_q == ST_B_LOAD || state_q == ST_B_REQ ||
     state_q == ST_B_RSP) ?
    b_element_index_q[0] : a_element_index_q[0];
  wire active_high_nibble =
    active_read_dtype == NPU_DTYPE_INT4 &&
    active_element_lsb;
  wire read_cache_hit =
    read_cache_valid_q &&
    read_cache_tag_q == current_load_addr[63:3];

  wire [3:0] write_col0 = {write_pair_q[2:0], 1'b0};
  wire [3:0] write_col1 = write_col0 + 1'b1;
  wire signed [63:0] write_accum0 =
    selected_accum(write_row_data_q, write_col0, dip_mode_q);
  wire signed [63:0] write_accum1 =
    selected_accum(write_row_data_q, write_col1, dip_mode_q);
  wire [31:0] write_value0 = int32_result(write_accum0, overflow_mode);
  wire [31:0] write_value1 = int32_result(write_accum1, overflow_mode);
  wire unused_command_id = ^command_id_i;
  wire unused_opcode = ^opcode_q;
  wire unused_desc_q = ^desc_q;
  wire unused_numeric_cfg = ^numeric_cfg[31:4];
  wire unused_dip_outputs =
    ^dip_c_row ^ dip_c_last ^ dip_busy;

  assign dip_b_valid = state_q == ST_B_SEND;
  assign dip_a_valid = state_q == ST_A_SEND;

  dip_gemm_core #(
    .ARRAY_N(ARRAY_N)
  ) u_dip_gemm_core (
    .clk_i(clk_i),
    .reset_n(reset_n),
    .mode_i(dip_mode_q),
    .b_raw_row_valid_i(dip_b_valid),
    .b_raw_row_ready_o(dip_b_ready),
    .b_raw_row_i(b_row_q),
    .a_row_valid_i(dip_a_valid),
    .a_row_ready_o(dip_a_ready),
    .a_row_i(a_row_q),
    .c_row_valid_o(dip_c_valid),
    .c_row_last_o(dip_c_last),
    .c_row_o(dip_c_row),
    .c_accum_row_o(dip_c_accum_row),
    .busy_o(dip_busy),
    .tile_done_o(dip_tile_done)
  );

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
    task_ready_o = state_q == ST_IDLE;
    done_valid_o = state_q == ST_DONE;
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
      ST_B_REQ,
      ST_A_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_addr_o = {read_addr_q[19:3], 3'b000};
      end

      ST_B_RSP,
      ST_A_RSP: l1_rsp_ready_o = 1'b1;

      ST_WRITE_REQ: begin
        l1_req_valid_o = 1'b1;
        l1_req_write_o = 1'b1;
        l1_req_addr_o = write_addr_q[19:0];
        l1_req_wdata_o = write_data_q;
        l1_req_wstrb_o = 8'hff;
      end

      ST_WRITE_RSP: l1_rsp_ready_o = 1'b1;
      default: begin end
    endcase
  end

  always_ff @(posedge clk_i or negedge reset_n) begin
    logic [15:0] loaded_value;
    if (!reset_n) begin
      state_q <= ST_IDLE;
      status_q <= NPU_STATUS_SUCCESS;
      fault_addr_q <= 48'd0;
      progress_q <= 64'd0;
      captured_rows_q <= 5'd0;
      read_cache_valid_q <= 1'b0;
    end else begin
      if (dip_c_valid) begin
        accum_rows_q[captured_rows_q[3:0]] <= dip_c_accum_row;
        captured_rows_q <= captured_rows_q + 1'b1;
      end

      case (state_q)
        ST_IDLE: begin
          status_q <= NPU_STATUS_SUCCESS;
          fault_addr_q <= 48'd0;
          progress_q <= 64'd0;
          captured_rows_q <= 5'd0;
          read_cache_valid_q <= 1'b0;
          if (task_valid_i) begin
            desc_q <= desc_i;
            opcode_q <= opcode_i;
            state_q <= ST_CHECK;
          end
        end

        ST_CHECK: begin
          dip_mode_q <= dip_mode_from_dtype(a_dtype);
          logical_n_q <= logical_size_from_dtype(a_dtype);
          batch_q <= 32'd0;
          a_batch_base_q <= a_base;
          b_batch_base_q <= b_base;
          c_batch_base_q <= c_base;
          a_row_base_q <= a_base;
          b_row_base_q <= b_base;
          c_row_base_q <= c_base;
          b_row_index_q <= 5'd0;
          b_element_index_q <= 5'd0;
          captured_rows_q <= 5'd0;
          state_q <= ST_B_ROW_INIT;
        end

        ST_B_ROW_INIT: begin
          b_row_q <= 64'd0;
          b_element_index_q <= 5'd0;
          read_cache_valid_q <= 1'b0;
          state_q <= ST_B_LOAD;
        end

        ST_B_LOAD: begin
          if (b_element_index_q >= logical_n_q)
            state_q <= ST_B_SEND;
          else if (current_load_addr[63:20] != 0 ||
                   crosses_beat(
                     current_load_addr[2:0], active_read_dtype
                   ))
            fail_task(NPU_STATUS_ADDR_FAULT, current_load_addr[47:0]);
          else if (read_cache_hit) begin
            loaded_value = 16'(load_element(
              read_cache_data_q, current_load_addr[2:0],
              active_high_nibble, active_read_dtype
            ));
            case (b_dtype)
              NPU_DTYPE_INT16:
                b_row_q[b_element_index_q * 16 +: 16] <=
                  loaded_value[15:0];
              NPU_DTYPE_INT8:
                b_row_q[b_element_index_q * 8 +: 8] <=
                  loaded_value[7:0];
              default:
                b_row_q[b_element_index_q * 4 +: 4] <=
                  loaded_value[3:0];
            endcase
            b_element_index_q <= b_element_index_q + 1'b1;
          end else begin
            read_addr_q <= current_load_addr;
            state_q <= ST_B_REQ;
          end
        end

        ST_B_REQ:
          if (l1_req_ready_i)
            state_q <= ST_B_RSP;

        ST_B_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(
                memory_status_to_task(l1_rsp_status_i),
                read_addr_q[47:0]
              );
            else begin
              loaded_value = 16'(load_element(
                l1_rsp_rdata_i, read_addr_q[2:0],
                active_high_nibble, active_read_dtype
              ));
              read_cache_valid_q <= 1'b1;
              read_cache_tag_q <= read_addr_q[63:3];
              read_cache_data_q <= l1_rsp_rdata_i;
              case (b_dtype)
                NPU_DTYPE_INT16:
                  b_row_q[b_element_index_q * 16 +: 16] <=
                    loaded_value[15:0];
                NPU_DTYPE_INT8:
                  b_row_q[b_element_index_q * 8 +: 8] <=
                    loaded_value[7:0];
                default:
                  b_row_q[b_element_index_q * 4 +: 4] <=
                    loaded_value[3:0];
              endcase
              b_element_index_q <= b_element_index_q + 1'b1;
              state_q <= ST_B_LOAD;
            end
          end

        ST_B_SEND:
          if (dip_b_ready) begin
            if (b_row_index_q + 1 >= logical_n_q) begin
              a_row_index_q <= 5'd0;
              state_q <= ST_A_ROW_INIT;
            end else begin
              b_row_index_q <= b_row_index_q + 1'b1;
              b_row_base_q <= b_row_base_q + {32'd0, ldb_bytes};
              state_q <= ST_B_ROW_INIT;
            end
          end

        ST_A_ROW_INIT: begin
          a_row_q <= 64'd0;
          a_element_index_q <= 5'd0;
          read_cache_valid_q <= 1'b0;
          state_q <= ST_A_LOAD;
        end

        ST_A_LOAD: begin
          if (a_element_index_q >= logical_n_q)
            state_q <= ST_A_SEND;
          else if (current_load_addr[63:20] != 0 ||
                   crosses_beat(
                     current_load_addr[2:0], active_read_dtype
                   ))
            fail_task(NPU_STATUS_ADDR_FAULT, current_load_addr[47:0]);
          else if (read_cache_hit) begin
            loaded_value = 16'(load_element(
              read_cache_data_q, current_load_addr[2:0],
              active_high_nibble, active_read_dtype
            ));
            case (a_dtype)
              NPU_DTYPE_INT16:
                a_row_q[a_element_index_q * 16 +: 16] <=
                  loaded_value[15:0];
              NPU_DTYPE_INT8:
                a_row_q[a_element_index_q * 8 +: 8] <=
                  loaded_value[7:0];
              default:
                a_row_q[a_element_index_q * 4 +: 4] <=
                  loaded_value[3:0];
            endcase
            a_element_index_q <= a_element_index_q + 1'b1;
          end else begin
            read_addr_q <= current_load_addr;
            state_q <= ST_A_REQ;
          end
        end

        ST_A_REQ:
          if (l1_req_ready_i)
            state_q <= ST_A_RSP;

        ST_A_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(
                memory_status_to_task(l1_rsp_status_i),
                read_addr_q[47:0]
              );
            else begin
              loaded_value = 16'(load_element(
                l1_rsp_rdata_i, read_addr_q[2:0],
                active_high_nibble, active_read_dtype
              ));
              read_cache_valid_q <= 1'b1;
              read_cache_tag_q <= read_addr_q[63:3];
              read_cache_data_q <= l1_rsp_rdata_i;
              case (a_dtype)
                NPU_DTYPE_INT16:
                  a_row_q[a_element_index_q * 16 +: 16] <=
                    loaded_value[15:0];
                NPU_DTYPE_INT8:
                  a_row_q[a_element_index_q * 8 +: 8] <=
                    loaded_value[7:0];
                default:
                  a_row_q[a_element_index_q * 4 +: 4] <=
                    loaded_value[3:0];
              endcase
              a_element_index_q <= a_element_index_q + 1'b1;
              state_q <= ST_A_LOAD;
            end
          end

        ST_A_SEND:
          if (dip_a_ready) begin
            if (a_row_index_q + 1 >= logical_n_q)
              state_q <= ST_WAIT_RESULT;
            else begin
              a_row_index_q <= a_row_index_q + 1'b1;
              a_row_base_q <= a_row_base_q + {32'd0, lda_bytes};
              state_q <= ST_A_ROW_INIT;
            end
          end

        ST_WAIT_RESULT:
          if (dip_tile_done) begin
            write_row_q <= 5'd0;
            write_pair_q <= 4'd0;
            write_addr_q <= c_batch_base_q;
            state_q <= ST_WRITE_ROW_LOAD;
          end

        ST_WRITE_ROW_LOAD: begin
          write_row_data_q <= accum_rows_q[write_row_q[3:0]];
          state_q <= ST_WRITE_INIT;
        end

        ST_WRITE_INIT: begin
          if (write_addr_q[63:20] != 0 || write_addr_q[2:0] != 0)
            fail_task(NPU_STATUS_ADDR_FAULT, write_addr_q[47:0]);
          else begin
            write_data_q <= {write_value1, write_value0};
            state_q <= ST_WRITE_REQ;
          end
        end

        ST_WRITE_REQ:
          if (l1_req_ready_i)
            state_q <= ST_WRITE_RSP;

        ST_WRITE_RSP:
          if (l1_rsp_valid_i) begin
            if (l1_rsp_status_i != 0)
              fail_task(
                memory_status_to_task(l1_rsp_status_i),
                write_addr_q[47:0]
              );
            else begin
              progress_q <= progress_q + 2;
              if ({write_pair_q, 1'b0} + 2 < logical_n_q) begin
                write_pair_q <= write_pair_q + 1'b1;
                write_addr_q <= write_addr_q + 8;
                state_q <= ST_WRITE_INIT;
              end else if (write_row_q + 1 < logical_n_q) begin
                write_row_q <= write_row_q + 1'b1;
                write_pair_q <= 4'd0;
                c_row_base_q <= c_row_base_q + {32'd0, ldc_bytes};
                write_addr_q <= c_row_base_q + {32'd0, ldc_bytes};
                state_q <= ST_WRITE_ROW_LOAD;
              end else if (batch_q + 1 < batch_count) begin
                batch_q <= batch_q + 1'b1;
                a_batch_base_q <= a_batch_base_q + a_batch_stride;
                b_batch_base_q <= b_batch_base_q + b_batch_stride;
                c_batch_base_q <= c_batch_base_q + c_batch_stride;
                a_row_base_q <= a_batch_base_q + a_batch_stride;
                b_row_base_q <= b_batch_base_q + b_batch_stride;
                c_row_base_q <= c_batch_base_q + c_batch_stride;
                b_row_index_q <= 5'd0;
                captured_rows_q <= 5'd0;
                state_q <= ST_B_ROW_INIT;
              end else begin
                status_q <= NPU_STATUS_SUCCESS;
                state_q <= ST_DONE;
              end
            end
          end

        ST_DONE:
          if (done_ready_i)
            state_q <= ST_IDLE;

        default:
          state_q <= ST_IDLE;
      endcase
    end
  end

endmodule
