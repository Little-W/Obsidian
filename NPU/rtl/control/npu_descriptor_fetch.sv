module npu_descriptor_fetch (
  input  logic          clk_i,
  input  logic          reset_n,
  input  logic          abort_i,

  input  logic          fetch_valid_i,
  output logic          fetch_ready_o,
  input  logic [47:0]   fetch_desc_addr_i,
  input  logic [11:0]   fetch_command_id_i,
  input  logic [3:0]    fetch_engine_i,
  input  logic          fetch_crc_enable_i,

  output logic          fetch_rsp_valid_o,
  input  logic          fetch_rsp_ready_i,
  output logic [11:0]   fetch_rsp_command_id_o,
  output logic [7:0]    fetch_rsp_status_o,
  output logic [47:0]   fetch_rsp_fault_addr_o,
  output logic [2047:0] fetch_rsp_desc_flat_o,

  output logic          mem_req_valid_o,
  input  logic          mem_req_ready_i,
  output logic          mem_req_write_o,
  output logic [47:0]   mem_req_addr_o,
  output logic [63:0]   mem_req_wdata_o,
  output logic [7:0]    mem_req_wstrb_o,

  input  logic          mem_rsp_valid_i,
  output logic          mem_rsp_ready_o,
  input  logic [63:0]   mem_rsp_rdata_i,
  input  logic [2:0]    mem_rsp_status_i,

  output logic          dfu_idle_o
);
  import npu_rtl_pkg::*;

  typedef enum logic [2:0] {
    DFU_IDLE,
    DFU_ISSUE,
    DFU_WAIT,
    DFU_CHECK_PREFIX,
    DFU_RESPOND
  } dfu_state_e;

  dfu_state_e state_q;
  logic [47:0] desc_addr_q;
  logic [11:0] command_id_q;
  logic [3:0]  engine_q;
  logic        crc_enable_q;
  logic [5:0]  beat_index_q;
  logic [5:0]  total_beats_q;
  logic [7:0]  rsp_status_q;
  logic [47:0] fault_addr_q;
  logic [2047:0] desc_flat_q;
  logic abort_pending_q;

  logic [15:0] expected_desc_bytes;
  logic prefix_valid;
  logic mem_request_handshake;
  logic mem_response_handshake;

  assign expected_desc_bytes = npu_desc_bytes_for_engine(engine_q);
  assign prefix_valid =
      (desc_flat_q[7:0] == 8'h01)
    && (desc_flat_q[15:8] == {4'd0, engine_q})
    && (desc_flat_q[31:16] == expected_desc_bytes)
    && (desc_flat_q[31:16] >= 16'd64)
    && (desc_flat_q[31:16] <= 16'd256)
    && ((engine_q == NPU_ENGINE_CONTROL)
          ? (desc_flat_q[479:448] == 32'd0)
          : npu_numeric_cfg_valid(desc_flat_q[479:448]));

  assign fetch_ready_o          = state_q == DFU_IDLE;
  assign fetch_rsp_valid_o      = state_q == DFU_RESPOND;
  assign fetch_rsp_command_id_o = command_id_q;
  assign fetch_rsp_status_o     = rsp_status_q;
  assign fetch_rsp_fault_addr_o = fault_addr_q;
  assign fetch_rsp_desc_flat_o  = desc_flat_q;

  assign mem_req_valid_o = state_q == DFU_ISSUE;
  assign mem_req_write_o = 1'b0;
  assign mem_req_addr_o  = desc_addr_q
                         + {39'd0, beat_index_q, 3'b000};
  assign mem_req_wdata_o = 64'd0;
  assign mem_req_wstrb_o = 8'd0;
  assign mem_rsp_ready_o = state_q == DFU_WAIT;

  assign mem_request_handshake  = mem_req_valid_o && mem_req_ready_i;
  assign mem_response_handshake = mem_rsp_valid_i && mem_rsp_ready_o;
  assign dfu_idle_o              = state_q == DFU_IDLE;

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      state_q        <= DFU_IDLE;
      desc_addr_q    <= '0;
      command_id_q   <= '0;
      engine_q       <= '0;
      crc_enable_q   <= 1'b0;
      beat_index_q   <= '0;
      total_beats_q  <= '0;
      rsp_status_q   <= NPU_STATUS_SUCCESS;
      fault_addr_q   <= '0;
      desc_flat_q    <= '0;
      abort_pending_q <= 1'b0;
    end else begin
      if (abort_i && (state_q != DFU_IDLE) && (state_q != DFU_RESPOND)) begin
        if (state_q == DFU_WAIT) begin
          if (mem_response_handshake) begin
            rsp_status_q   <= NPU_STATUS_ABORTED;
            fault_addr_q   <= mem_req_addr_o;
            abort_pending_q <= 1'b0;
            state_q        <= DFU_RESPOND;
          end else begin
            abort_pending_q <= 1'b1;
          end
        end else if ((state_q == DFU_ISSUE) && mem_request_handshake) begin
          abort_pending_q <= 1'b1;
          state_q         <= DFU_WAIT;
        end else begin
          rsp_status_q   <= NPU_STATUS_ABORTED;
          fault_addr_q   <= mem_req_addr_o;
          abort_pending_q <= 1'b0;
          state_q        <= DFU_RESPOND;
        end
      end else begin
        unique case (state_q)
          DFU_IDLE: begin
            if (fetch_valid_i && fetch_ready_o) begin
              desc_addr_q   <= fetch_desc_addr_i;
              command_id_q  <= fetch_command_id_i;
              engine_q      <= fetch_engine_i;
              crc_enable_q  <= fetch_crc_enable_i;
              beat_index_q  <= 6'd0;
              total_beats_q <= 6'd8;
              rsp_status_q  <= NPU_STATUS_SUCCESS;
              fault_addr_q  <= 48'd0;
              desc_flat_q   <= '0;
              abort_pending_q <= 1'b0;
              if (fetch_desc_addr_i[5:0] != 6'd0) begin
                rsp_status_q <= NPU_STATUS_BAD_DESC;
                fault_addr_q <= fetch_desc_addr_i;
                state_q      <= DFU_RESPOND;
              end else begin
                state_q <= DFU_ISSUE;
              end
            end
          end

          DFU_ISSUE: begin
            if (mem_request_handshake) begin
              state_q <= DFU_WAIT;
            end
          end

          DFU_WAIT: begin
            if (mem_response_handshake) begin
              if (abort_pending_q) begin
                rsp_status_q   <= NPU_STATUS_ABORTED;
                fault_addr_q   <= mem_req_addr_o;
                abort_pending_q <= 1'b0;
                state_q        <= DFU_RESPOND;
              end else if (mem_rsp_status_i != NPU_MEM_OK) begin
                rsp_status_q <= npu_mem_to_task_status(mem_rsp_status_i);
                fault_addr_q <= mem_req_addr_o;
                state_q      <= DFU_RESPOND;
              end else begin
                desc_flat_q[beat_index_q*64 +: 64] <= mem_rsp_rdata_i;
                if (beat_index_q == total_beats_q - 1'b1) begin
                  if (total_beats_q == 6'd8) begin
                    state_q <= DFU_CHECK_PREFIX;
                  end else begin
                    rsp_status_q <= NPU_STATUS_SUCCESS;
                    state_q      <= DFU_RESPOND;
                  end
                end else begin
                  beat_index_q <= beat_index_q + 1'b1;
                  state_q      <= DFU_ISSUE;
                end
              end
            end
          end

          DFU_CHECK_PREFIX: begin
            if (!prefix_valid || crc_enable_q) begin
              rsp_status_q <= NPU_STATUS_BAD_DESC;
              fault_addr_q <= desc_addr_q;
              state_q      <= DFU_RESPOND;
            end else if (expected_desc_bytes == 16'd64) begin
              rsp_status_q <= NPU_STATUS_SUCCESS;
              state_q      <= DFU_RESPOND;
            end else begin
              total_beats_q <= expected_desc_bytes[8:3];
              beat_index_q  <= 6'd8;
              state_q       <= DFU_ISSUE;
            end
          end

          DFU_RESPOND: begin
            if (fetch_rsp_valid_o && fetch_rsp_ready_i) begin
              state_q <= DFU_IDLE;
            end
          end

          default: state_q <= DFU_IDLE;
        endcase
      end
    end
  end

endmodule
