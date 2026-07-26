module npu_cmd_frontend #(
  parameter int unsigned FIFO_DEPTH = 8,
  parameter int unsigned WAIT_HIGH_TIMEOUT = 32,
  localparam int unsigned PTR_W = (FIFO_DEPTH <= 1) ? 1 : $clog2(FIFO_DEPTH),
  localparam int unsigned COUNT_W = $clog2(FIFO_DEPTH + 1),
  localparam int unsigned TIMEOUT_W =
    (WAIT_HIGH_TIMEOUT <= 1) ? 1 : $clog2(WAIT_HIGH_TIMEOUT)
) (
  input  logic         clk_i,
  input  logic         reset_n,
  input  logic         quiesce_i,

  input  logic         axi_cmd_valid_i,
  output logic         axi_cmd_ready_o,
  input  logic [63:0]  axi_cmd_data_i,
  input  logic         axi_cmd_first_i,
  input  logic         axi_cmd_last_i,

  output logic         axi_cmd_rsp_valid_o,
  input  logic         axi_cmd_rsp_ready_i,
  output logic [63:0]  axi_cmd_rsp_data_o,

  output logic         ts_cmd_valid_o,
  input  logic         ts_cmd_ready_i,
  output logic [127:0] ts_cmd_o,

  output logic         cmd_id_lookup_valid_o,
  input  logic         cmd_id_lookup_ready_i,
  output logic [11:0]  cmd_id_lookup_id_o,
  input  logic         cmd_id_lookup_rsp_valid_i,
  input  logic         cmd_id_busy_i,

  output logic         cfe_idle_o,
  output logic         cfe_error_o,
  output logic         cmd_accepted_o
);
  import npu_rtl_pkg::*;

  typedef enum logic [2:0] {
    CFE_IDLE,
    CFE_WAIT_HIGH,
    CFE_CHECK,
    CFE_LOOKUP,
    CFE_ENQUEUE,
    CFE_RESPOND
  } cfe_state_e;

  cfe_state_e state_q;
  logic [63:0] low_word_q;
  logic [63:0] high_word_q;
  logic [7:0]  response_status_q;
  logic        lookup_sent_q;
  logic [TIMEOUT_W-1:0] wait_high_count_q;

  logic [127:0] fifo_q [FIFO_DEPTH];
  logic [FIFO_DEPTH-1:0] fifo_valid_q;
  logic [PTR_W-1:0] fifo_wr_ptr_q;
  logic [PTR_W-1:0] fifo_rd_ptr_q;
  logic [COUNT_W-1:0] fifo_count_q;

  logic local_duplicate;
  logic header_format_valid;
  logic opcode_format_valid;
  logic input_handshake;
  logic output_handshake;
  logic enqueue_now;
  logic [7:0] fifo_free_entries;
  logic [127:0] candidate_cmd;
  logic [11:0] candidate_command_id;

  function automatic logic [PTR_W-1:0] increment_ptr(
    input logic [PTR_W-1:0] pointer
  );
    if (pointer == PTR_W'(FIFO_DEPTH - 1)) begin
      return '0;
    end
    return pointer + 1'b1;
  endfunction

  assign input_handshake  = axi_cmd_valid_i && axi_cmd_ready_o;
  assign output_handshake = ts_cmd_valid_o && ts_cmd_ready_i;
  assign enqueue_now      = state_q == CFE_ENQUEUE;
  assign candidate_cmd    = {high_word_q, low_word_q};
  assign candidate_command_id = npu_cmd_command_id(candidate_cmd);

  always_comb begin
    local_duplicate = 1'b0;
    for (int unsigned entry = 0; entry < FIFO_DEPTH; entry++) begin
      if (fifo_valid_q[entry]
          && (npu_cmd_command_id(fifo_q[entry]) ==
              candidate_command_id)) begin
        local_duplicate = 1'b1;
      end
    end
  end

  assign fifo_free_entries = 8'(FIFO_DEPTH) - 8'(fifo_count_q);

  always_comb begin
    if (candidate_cmd[127]) begin
      header_format_valid = 1'b1;
      opcode_format_valid =
        npu_v2_compact_opcode_valid(candidate_cmd[126:122]);
    end else begin
      header_format_valid =
          (low_word_q[5:0] == 6'd0)
        && (high_word_q[63:56] == 8'h01)
        && (high_word_q[19:18] == 2'b00)
        && npu_event_ref_valid(high_word_q[31:20])
        && npu_event_ref_valid(high_word_q[43:32])
        && npu_event_ref_valid(high_word_q[55:44]);
      opcode_format_valid =
        npu_opcode_engine_valid(low_word_q[63:60], high_word_q[7:0]);
    end
  end

  always_comb begin
    axi_cmd_ready_o       = 1'b0;
    axi_cmd_rsp_valid_o   = state_q == CFE_RESPOND;
    axi_cmd_rsp_data_o    = 64'd0;
    axi_cmd_rsp_data_o[11:0]  = candidate_command_id;
    axi_cmd_rsp_data_o[19:12] = response_status_q;
    axi_cmd_rsp_data_o[27:20] = fifo_free_entries;

    ts_cmd_valid_o        = fifo_count_q != 0;
    ts_cmd_o              = fifo_q[fifo_rd_ptr_q];

    cmd_id_lookup_valid_o = (state_q == CFE_LOOKUP) && !lookup_sent_q;
    cmd_id_lookup_id_o    = candidate_command_id;

    cfe_idle_o = (state_q == CFE_IDLE) && (fifo_count_q == 0);

    if (!quiesce_i) begin
      unique case (state_q)
        CFE_IDLE:      axi_cmd_ready_o = 1'b1;
        CFE_WAIT_HIGH: axi_cmd_ready_o = 1'b1;
        default:       axi_cmd_ready_o = 1'b0;
      endcase
    end
  end

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      state_q             <= CFE_IDLE;
      low_word_q          <= '0;
      high_word_q         <= '0;
      response_status_q   <= NPU_STATUS_SUCCESS;
      lookup_sent_q       <= 1'b0;
      wait_high_count_q   <= '0;
      fifo_valid_q        <= '0;
      fifo_wr_ptr_q       <= '0;
      fifo_rd_ptr_q       <= '0;
      fifo_count_q        <= '0;
      cfe_error_o         <= 1'b0;
      cmd_accepted_o      <= 1'b0;
    end else begin
      cfe_error_o    <= 1'b0;
      cmd_accepted_o <= 1'b0;

      unique case ({enqueue_now, output_handshake})
        2'b10: begin
          fifo_q[fifo_wr_ptr_q] <= {high_word_q, low_word_q};
          fifo_valid_q[fifo_wr_ptr_q] <= 1'b1;
          fifo_wr_ptr_q         <= increment_ptr(fifo_wr_ptr_q);
          fifo_count_q          <= fifo_count_q + 1'b1;
        end
        2'b01: begin
          fifo_valid_q[fifo_rd_ptr_q] <= 1'b0;
          fifo_rd_ptr_q  <= increment_ptr(fifo_rd_ptr_q);
          fifo_count_q   <= fifo_count_q - 1'b1;
        end
        2'b11: begin
          fifo_q[fifo_wr_ptr_q] <= {high_word_q, low_word_q};
          fifo_valid_q[fifo_rd_ptr_q] <= 1'b0;
          fifo_valid_q[fifo_wr_ptr_q] <= 1'b1;
          fifo_wr_ptr_q         <= increment_ptr(fifo_wr_ptr_q);
          fifo_rd_ptr_q         <= increment_ptr(fifo_rd_ptr_q);
        end
        default: begin
        end
      endcase

      unique case (state_q)
        CFE_IDLE: begin
          lookup_sent_q <= 1'b0;
          if (input_handshake) begin
            low_word_q <= axi_cmd_data_i;
            if (axi_cmd_first_i && !axi_cmd_last_i) begin
              wait_high_count_q <= '0;
              state_q <= CFE_WAIT_HIGH;
            end else begin
              response_status_q <= NPU_STATUS_BAD_DESC;
              cfe_error_o       <= 1'b1;
              state_q           <= CFE_RESPOND;
            end
          end
        end

        CFE_WAIT_HIGH: begin
          if (input_handshake) begin
            high_word_q <= axi_cmd_data_i;
            if (!axi_cmd_first_i && axi_cmd_last_i) begin
              state_q     <= CFE_CHECK;
            end else begin
              response_status_q <= NPU_STATUS_BAD_DESC;
              cfe_error_o       <= 1'b1;
              state_q           <= CFE_RESPOND;
            end
          end else if (wait_high_count_q ==
                       TIMEOUT_W'(WAIT_HIGH_TIMEOUT - 1)) begin
            response_status_q <= NPU_STATUS_TIMEOUT;
            cfe_error_o       <= 1'b1;
            state_q           <= CFE_RESPOND;
          end else begin
            wait_high_count_q <= wait_high_count_q + 1'b1;
          end
        end

        CFE_CHECK: begin
          if (!header_format_valid) begin
            response_status_q <= NPU_STATUS_BAD_DESC;
            cfe_error_o       <= 1'b1;
            state_q           <= CFE_RESPOND;
          end else if (!opcode_format_valid) begin
            response_status_q <= NPU_STATUS_ILLEGAL_OPCODE;
            cfe_error_o       <= 1'b1;
            state_q           <= CFE_RESPOND;
          end else if (local_duplicate) begin
            response_status_q <= NPU_STATUS_BAD_DESC;
            cfe_error_o       <= 1'b1;
            state_q           <= CFE_RESPOND;
          end else begin
            lookup_sent_q <= 1'b0;
            state_q       <= CFE_LOOKUP;
          end
        end

        CFE_LOOKUP: begin
          if (cmd_id_lookup_valid_o && cmd_id_lookup_ready_i) begin
            lookup_sent_q <= 1'b1;
          end
          if (lookup_sent_q && cmd_id_lookup_rsp_valid_i) begin
            if (cmd_id_busy_i) begin
              response_status_q <= NPU_STATUS_BAD_DESC;
              cfe_error_o       <= 1'b1;
              state_q           <= CFE_RESPOND;
            end else if (fifo_count_q == COUNT_W'(FIFO_DEPTH)) begin
              response_status_q <= NPU_STATUS_BAD_DESC;
              cfe_error_o       <= 1'b1;
              state_q           <= CFE_RESPOND;
            end else begin
              state_q <= CFE_ENQUEUE;
            end
          end
        end

        CFE_ENQUEUE: begin
          response_status_q <= NPU_STATUS_SUCCESS;
          cmd_accepted_o    <= 1'b1;
          state_q           <= CFE_RESPOND;
        end

        CFE_RESPOND: begin
          if (axi_cmd_rsp_valid_o && axi_cmd_rsp_ready_i) begin
            state_q           <= CFE_IDLE;
          end
        end

        default: state_q <= CFE_IDLE;
      endcase
    end
  end

  initial begin
    if (WAIT_HIGH_TIMEOUT == 0) begin
      $error("WAIT_HIGH_TIMEOUT must be greater than zero");
    end
  end

endmodule
