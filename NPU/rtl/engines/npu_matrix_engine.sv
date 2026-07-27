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

  typedef enum logic [1:0] {
    PATH_IDLE,
    PATH_CLASSIFY,
    PATH_SCALAR,
    PATH_DIP
  } path_t;

  path_t active_path_q;
  logic child_issued_q;
  logic [7:0] task_opcode_q;
  logic [11:0] task_command_id_q;
  logic [2047:0] task_desc_q;
  logic [31:0] dip_task_count_q;

  logic scalar_task_valid;
  logic scalar_task_ready;
  logic scalar_done_valid;
  logic [7:0] scalar_done_status;
  logic [47:0] scalar_done_fault_addr;
  logic [63:0] scalar_done_progress;
  logic scalar_l1_req_valid;
  logic scalar_l1_req_write;
  logic [19:0] scalar_l1_req_addr;
  logic [63:0] scalar_l1_req_wdata;
  logic [7:0] scalar_l1_req_wstrb;
  logic scalar_l1_rsp_ready;

  logic dip_task_valid;
  logic dip_task_ready;
  logic dip_done_valid;
  logic [7:0] dip_done_status;
  logic [47:0] dip_done_fault_addr;
  logic [63:0] dip_done_progress;
  logic dip_l1_req_valid;
  logic dip_l1_req_write;
  logic [19:0] dip_l1_req_addr;
  logic [63:0] dip_l1_req_wdata;
  logic [7:0] dip_l1_req_wstrb;
  logic dip_l1_rsp_ready;

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

  function automatic logic [4:0] dip_logical_size(
    input logic [1:0] dtype
  );
    case (dtype)
      NPU_DTYPE_INT16: return 5'd4;
      NPU_DTYPE_INT8:  return 5'd8;
      NPU_DTYPE_INT4:  return 5'd16;
      default:         return 5'd0;
    endcase
  endfunction

  function automatic logic dip_task_eligible(
    input logic [7:0] opcode,
    input logic [2047:0] desc
  );
    logic [31:0] numeric_cfg;
    logic [1:0] a_dtype;
    logic [1:0] b_dtype;
    logic [1:0] c_dtype;
    logic [4:0] logical_n;
    logic [31:0] matrix_m;
    logic [31:0] matrix_n;
    logic [31:0] matrix_k;
    logic [31:0] batch_count;
    logic [31:0] matrix_flags;
    logic [7:0] a_pack;
    logic [7:0] b_pack;
    logic [7:0] c_pack;
    logic pack_ok;
    logic opcode_ok;
    logic unused_desc_bits;
    logic unused_numeric_bits;
    begin
      numeric_cfg = desc[448 +: 32];
      a_dtype = numeric_cfg[1:0];
      b_dtype = numeric_cfg[3:2];
      c_dtype = numeric_cfg[7:6];
      logical_n = dip_logical_size(a_dtype);
      matrix_m = desc[16'h40 * 8 +: 32];
      matrix_n = desc[16'h44 * 8 +: 32];
      matrix_k = desc[16'h48 * 8 +: 32];
      batch_count = desc[16'h4c * 8 +: 32];
      matrix_flags = desc[16'h5c * 8 +: 32];
      a_pack = desc[16'h90 * 8 +: 8];
      b_pack = desc[16'h91 * 8 +: 8];
      c_pack = desc[16'h92 * 8 +: 8];
      unused_desc_bits = ^desc;
      unused_numeric_bits = ^numeric_cfg[16:10];

      opcode_ok =
        (opcode == NPU_MATRIX_GEMM && batch_count == 1) ||
        (opcode == NPU_MATRIX_BMM && batch_count >= 1);
      pack_ok =
        ((a_dtype == NPU_DTYPE_INT4 && a_pack == 8'd1 &&
          (b_pack == 8'd1 || b_pack == 8'd3)) ||
         (a_dtype == NPU_DTYPE_INT8 && a_pack == 8'd0 &&
          (b_pack == 8'd0 || b_pack == 8'd2)) ||
         (a_dtype == NPU_DTYPE_INT16 && a_pack == 8'd5 &&
          (b_pack == 8'd5 || b_pack == 8'd6))) &&
        c_pack == 8'd4;

      return
        opcode_ok &&
        desc[7:0] == 8'h01 &&
        desc[15:8] == 8'h02 &&
        desc[31:16] == 16'd256 &&
        logical_n != 0 &&
        a_dtype == b_dtype &&
        c_dtype == NPU_DTYPE_INT32 &&
        numeric_cfg[5:4] == NPU_DTYPE_INT32 &&
        numeric_cfg[9:8] == 2'd0 &&
        numeric_cfg[31:17] == 15'd0 &&
        matrix_m == {27'd0, logical_n} &&
        matrix_n == {27'd0, logical_n} &&
        matrix_k == {27'd0, logical_n} &&
        desc[16'h50 * 8 +: 32] ==
          expected_tail(matrix_m, 32'd8) &&
        desc[16'h54 * 8 +: 32] ==
          expected_tail(matrix_n, 32'd8) &&
        desc[16'h58 * 8 +: 32] ==
          expected_tail(matrix_k, 32'd16) &&
        matrix_flags == 32'h0000_0080 &&
        pack_ok &&
        desc[16'h93 * 8 +: 8] == 8'd0 &&
        (desc[16'h94 * 8 +: 8] == 8'd0 ||
         desc[16'h94 * 8 +: 8] == 8'd2) &&
        desc[16'h95 * 8 +: 8] == 8'd0 &&
        desc[16'h98 * 8 +: 32] == 32'd0 &&
        desc[16'h9c * 8 +: 32] == 32'd0 &&
        desc[16'ha0 * 8 +: 32] == 32'd0 &&
        desc[16'ha4 * 8 +: 8] == 8'd0 &&
        desc[16'ha5 * 8 +: 8] == 8'd0 &&
        desc[16'ha7 * 8 +: 8] == 8'd0 &&
        desc[16'hac * 8 +: 32] == 32'd0 &&
        desc[16'hb0 * 8 +: 8] == 8'd0 &&
        desc[64 + 20 +: 44] == 44'd0 &&
        desc[128 + 20 +: 44] == 44'd0 &&
        desc[256 + 20 +: 44] == 44'd0 &&
        desc[256 +: 3] == 3'd0 &&
        desc[16'h68 * 8 +: 3] == 3'd0 &&
        desc[16'h80 * 8 +: 3] == 3'd0;
    end
  endfunction

  wire choose_dip =
    dip_task_eligible(task_opcode_q, task_desc_q);
  wire idle_path = active_path_q == PATH_IDLE;

  assign scalar_task_valid =
    active_path_q == PATH_SCALAR && !child_issued_q;
  assign dip_task_valid =
    active_path_q == PATH_DIP && !child_issued_q;
  assign task_ready_o = idle_path;

  npu_matrix_scalar_engine u_scalar_engine (
    .clk_i(clk_i),
    .reset_n(reset_n),
    .task_valid_i(scalar_task_valid),
    .task_ready_o(scalar_task_ready),
    .opcode_i(task_opcode_q),
    .command_id_i(task_command_id_q),
    .desc_i(task_desc_q),
    .done_valid_o(scalar_done_valid),
    .done_ready_i(done_ready_i && active_path_q == PATH_SCALAR),
    .done_status_o(scalar_done_status),
    .done_fault_addr_o(scalar_done_fault_addr),
    .done_progress_o(scalar_done_progress),
    .l1_req_valid_o(scalar_l1_req_valid),
    .l1_req_ready_i(
      l1_req_ready_i && active_path_q == PATH_SCALAR
    ),
    .l1_req_write_o(scalar_l1_req_write),
    .l1_req_addr_o(scalar_l1_req_addr),
    .l1_req_wdata_o(scalar_l1_req_wdata),
    .l1_req_wstrb_o(scalar_l1_req_wstrb),
    .l1_rsp_valid_i(
      l1_rsp_valid_i && active_path_q == PATH_SCALAR
    ),
    .l1_rsp_ready_o(scalar_l1_rsp_ready),
    .l1_rsp_rdata_i(l1_rsp_rdata_i),
    .l1_rsp_status_i(l1_rsp_status_i)
  );

  npu_matrix_dip_engine u_dip_engine (
    .clk_i(clk_i),
    .reset_n(reset_n),
    .task_valid_i(dip_task_valid),
    .task_ready_o(dip_task_ready),
    .opcode_i(task_opcode_q),
    .command_id_i(task_command_id_q),
    .desc_i(task_desc_q),
    .done_valid_o(dip_done_valid),
    .done_ready_i(done_ready_i && active_path_q == PATH_DIP),
    .done_status_o(dip_done_status),
    .done_fault_addr_o(dip_done_fault_addr),
    .done_progress_o(dip_done_progress),
    .l1_req_valid_o(dip_l1_req_valid),
    .l1_req_ready_i(
      l1_req_ready_i && active_path_q == PATH_DIP
    ),
    .l1_req_write_o(dip_l1_req_write),
    .l1_req_addr_o(dip_l1_req_addr),
    .l1_req_wdata_o(dip_l1_req_wdata),
    .l1_req_wstrb_o(dip_l1_req_wstrb),
    .l1_rsp_valid_i(
      l1_rsp_valid_i && active_path_q == PATH_DIP
    ),
    .l1_rsp_ready_o(dip_l1_rsp_ready),
    .l1_rsp_rdata_i(l1_rsp_rdata_i),
    .l1_rsp_status_i(l1_rsp_status_i)
  );

  always_comb begin
    done_valid_o = 1'b0;
    done_status_o = NPU_STATUS_SUCCESS;
    done_fault_addr_o = 48'd0;
    done_progress_o = 64'd0;
    l1_req_valid_o = 1'b0;
    l1_req_write_o = 1'b0;
    l1_req_addr_o = 20'd0;
    l1_req_wdata_o = 64'd0;
    l1_req_wstrb_o = 8'd0;
    l1_rsp_ready_o = 1'b0;

    case (active_path_q)
      PATH_SCALAR: begin
        done_valid_o = scalar_done_valid;
        done_status_o = scalar_done_status;
        done_fault_addr_o = scalar_done_fault_addr;
        done_progress_o = scalar_done_progress;
        l1_req_valid_o = scalar_l1_req_valid;
        l1_req_write_o = scalar_l1_req_write;
        l1_req_addr_o = scalar_l1_req_addr;
        l1_req_wdata_o = scalar_l1_req_wdata;
        l1_req_wstrb_o = scalar_l1_req_wstrb;
        l1_rsp_ready_o = scalar_l1_rsp_ready;
      end

      PATH_DIP: begin
        done_valid_o = dip_done_valid;
        done_status_o = dip_done_status;
        done_fault_addr_o = dip_done_fault_addr;
        done_progress_o = dip_done_progress;
        l1_req_valid_o = dip_l1_req_valid;
        l1_req_write_o = dip_l1_req_write;
        l1_req_addr_o = dip_l1_req_addr;
        l1_req_wdata_o = dip_l1_req_wdata;
        l1_req_wstrb_o = dip_l1_req_wstrb;
        l1_rsp_ready_o = dip_l1_rsp_ready;
      end

      default: begin end
    endcase
  end

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      active_path_q <= PATH_IDLE;
      child_issued_q <= 1'b0;
      dip_task_count_q <= 32'd0;
    end else begin
      if (idle_path && task_valid_i && task_ready_o) begin
        task_opcode_q <= opcode_i;
        task_command_id_q <= command_id_i;
        task_desc_q <= desc_i;
        active_path_q <= PATH_CLASSIFY;
        child_issued_q <= 1'b0;
      end else if (active_path_q == PATH_CLASSIFY) begin
        if (choose_dip) begin
          active_path_q <= PATH_DIP;
          dip_task_count_q <= dip_task_count_q + 1'b1;
        end else
          active_path_q <= PATH_SCALAR;
      end else if (
        (active_path_q == PATH_SCALAR &&
         scalar_task_valid && scalar_task_ready) ||
        (active_path_q == PATH_DIP &&
         dip_task_valid && dip_task_ready)
      ) begin
        child_issued_q <= 1'b1;
      end else if (
        (active_path_q == PATH_SCALAR &&
         scalar_done_valid && done_ready_i) ||
        (active_path_q == PATH_DIP &&
         dip_done_valid && done_ready_i)
      ) begin
        active_path_q <= PATH_IDLE;
        child_issued_q <= 1'b0;
      end
    end
  end

endmodule
