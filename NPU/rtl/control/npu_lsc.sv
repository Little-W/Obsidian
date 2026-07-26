module npu_lsc (
  input  logic        clk_i,
  input  logic        reset_n,

  input  logic        reg_req_valid_i,
  output logic        reg_req_ready_o,
  input  logic        reg_req_write_i,
  input  logic        reg_req_space_i,
  input  logic [15:0] reg_req_addr_i,
  input  logic [63:0] reg_req_wdata_i,
  input  logic [7:0]  reg_req_wstrb_i,
  output logic        reg_rsp_valid_o,
  input  logic        reg_rsp_ready_i,
  output logic [63:0] reg_rsp_rdata_o,
  output logic [1:0]  reg_rsp_status_o,

  input  logic        cmd_ingress_idle_i,
  input  logic        cfe_idle_i,
  input  logic        ts_idle_i,
  input  logic        ts_quiescent_i,
  input  logic [3:0]  eng_quiescent_i,
  input  logic        l1_idle_i,
  input  logic        l1_write_idle_i,
  input  logic        mif_idle_i,
  input  logic        s_axi_idle_i,

  input  logic        soft_reset_req_i,
  input  logic        internal_soft_reset_done_i,
  input  logic        power_down_req_i,
  output logic        soft_reset_done_o,
  output logic        power_down_ack_o,
  output logic        accept_new_cmd_o,
  output logic        cfe_quiesce_o,
  output logic        ts_quiesce_o,
  output logic [3:0]  eng_abort_o,
  output logic        single_step_pulse_o,
  output logic        internal_soft_reset_pulse_o,
  output logic        core_idle_o,

  input  logic        task_terminal_valid_i,
  output logic        task_terminal_ready_o,
  input  logic [11:0] task_command_id_i,
  input  logic [3:0]  task_engine_i,
  input  logic [7:0]  task_opcode_i,
  input  logic [7:0]  task_status_i,
  input  logic [47:0] task_fault_addr_i,
  input  logic        task_irq_on_success_i,
  input  logic        task_irq_on_error_i,

  input  logic        interface_error_valid_i,
  input  logic [7:0]  interface_error_status_i,
  input  logic [47:0] interface_error_addr_i,
  output logic        interface_error_clear_o,

  input  logic        wdt_timeout_i,
  output logic        wdt_enable_o,
  output logic [31:0] wdt_timeout_cycles_o,
  output logic        wdt_kick_o,

  output logic        irq_done_o,
  output logic        irq_exception_o,
  output logic        irq_error_o,

  output logic [47:0] input_base_o,
  output logic [47:0] weight_base_o,
  output logic [47:0] work_base_o,
  output logic [47:0] output_base_o,
  output logic [47:0] kv_base_o,
  output logic [47:0] m_axi_addr_base_o,
  output logic [47:0] m_axi_addr_limit_o,
  output logic [15:0] tbu_stream_id_o,
  output logic [15:0] tbu_substream_id_o,
  output logic        tbu_allow_read_o,
  output logic        tbu_allow_write_o,
  output logic [19:0] param_l1_base_o,
  output logic [19:0] param_l1_limit_o,
  output logic        param_lock_o,
  output logic        l1_host_access_enable_o,
  output logic [7:0]  module_clk_enable_o
);
  import npu_rtl_pkg::*;

  typedef enum logic [1:0] {
    RESET_IDLE,
    RESET_DRAIN,
    RESET_WAIT_INTERNAL,
    RESET_DONE
  } reset_state_e;

  logic rsp_valid_q;
  logic [63:0] rsp_data_q;
  logic [1:0] rsp_status_q;

  logic start_q;
  logic stop_q;
  logic [2:0] irq_status_q;
  logic [2:0] irq_mask_q;
  logic fault_valid_q;
  logic [11:0] fault_command_id_q;
  logic [3:0] fault_engine_q;
  logic [7:0] fault_opcode_q;
  logic [7:0] fault_status_q;
  logic [47:0] fault_addr_q;
  logic [2:0] reset_reason_q;
  logic [47:0] input_base_q;
  logic [47:0] weight_base_q;
  logic [47:0] work_base_q;
  logic [47:0] output_base_q;
  logic [47:0] kv_base_q;
  logic [47:0] m_axi_addr_base_q;
  logic [47:0] m_axi_addr_limit_q;
  logic [15:0] tbu_stream_id_q;
  logic [15:0] tbu_substream_id_q;
  logic [19:0] param_l1_base_q;
  logic [19:0] param_l1_limit_q;
  logic param_lock_q;
  logic l1_host_access_enable_q;
  logic [7:0] module_clk_enable_q;
  logic wdt_enable_q;
  logic [31:0] wdt_timeout_cycles_q;
  reset_state_e reset_state_q;
  logic csr_soft_reset_req_q;

  logic [63:0] csr_read_data;
  logic all_drain_idle;
  logic reset_requested;

  function automatic logic [63:0] write_mask(input logic [7:0] strobe);
    logic [63:0] mask;
    begin
      mask = 64'd0;
      for (int unsigned byte_idx = 0; byte_idx < 8; byte_idx++) begin
        mask[byte_idx*8 +: 8] = {8{strobe[byte_idx]}};
      end
      return mask;
    end
  endfunction

  function automatic logic [63:0] merge_write(
    input logic [63:0] old_value,
    input logic [63:0] new_value,
    input logic [7:0]  strobe
  );
    logic [63:0] mask;
    begin
      mask = write_mask(strobe);
      return (old_value & ~mask) | (new_value & mask);
    end
  endfunction

  assign reg_req_ready_o  = !rsp_valid_q;
  assign reg_rsp_valid_o  = rsp_valid_q;
  assign reg_rsp_rdata_o  = rsp_data_q;
  assign reg_rsp_status_o = rsp_status_q;

  assign core_idle_o = cmd_ingress_idle_i
                     && cfe_idle_i
                     && ts_idle_i
                     && (&eng_quiescent_i)
                     && l1_idle_i
                     && mif_idle_i
                     && s_axi_idle_i;
  assign all_drain_idle = cmd_ingress_idle_i
                        && cfe_idle_i
                        && ts_quiescent_i
                        && (&eng_quiescent_i)
                        && l1_idle_i
                        && mif_idle_i
                        && s_axi_idle_i;
  assign reset_requested = soft_reset_req_i || csr_soft_reset_req_q;

  assign accept_new_cmd_o = start_q && !stop_q
                          && (reset_state_q == RESET_IDLE)
                          && !power_down_req_i;
  assign cfe_quiesce_o = (reset_state_q != RESET_IDLE)
                       || power_down_req_i || stop_q;
  assign ts_quiesce_o  = (reset_state_q != RESET_IDLE)
                       || power_down_req_i || stop_q;
  assign eng_abort_o   = {4{reset_state_q == RESET_DRAIN}};
  assign soft_reset_done_o = reset_state_q == RESET_DONE;
  assign power_down_ack_o = power_down_req_i && core_idle_o && stop_q;
  assign task_terminal_ready_o = 1'b1;

  assign irq_done_o      = irq_status_q[0] && !irq_mask_q[0];
  assign irq_exception_o = irq_status_q[1] && !irq_mask_q[1];
  assign irq_error_o     = irq_status_q[2] && !irq_mask_q[2];

  assign input_base_o          = input_base_q;
  assign weight_base_o         = weight_base_q;
  assign work_base_o           = work_base_q;
  assign output_base_o         = output_base_q;
  assign kv_base_o             = kv_base_q;
  assign m_axi_addr_base_o     = m_axi_addr_base_q;
  assign m_axi_addr_limit_o    = m_axi_addr_limit_q;
  assign tbu_stream_id_o       = tbu_stream_id_q;
  assign tbu_substream_id_o    = tbu_substream_id_q;
  assign tbu_allow_read_o      = 1'b1;
  assign tbu_allow_write_o     = 1'b1;
  assign param_l1_base_o       = param_l1_base_q;
  assign param_l1_limit_o      = param_l1_limit_q;
  assign param_lock_o          = param_lock_q;
  assign l1_host_access_enable_o = l1_host_access_enable_q;
  assign module_clk_enable_o   = module_clk_enable_q;
  assign wdt_enable_o          = wdt_enable_q;
  assign wdt_timeout_cycles_o  = wdt_timeout_cycles_q;

  always_comb begin
    csr_read_data = 64'd0;
    if (!reg_req_space_i) begin
      unique case (reg_req_addr_i)
        16'h0000: csr_read_data = 64'h0000_0001_0001_0001;
        16'h0008: csr_read_data = 64'd0;
        16'h0010: csr_read_data = {32'd0, 8'd8, 8'd40, 8'd48, 8'd64};
        16'h0018: csr_read_data = {16'd0, 8'd2, 8'd16, 32'd1048576};
        16'h0020: csr_read_data = {36'd0, 4'b0111, 8'd8, 8'd16, 8'd8};
        16'h0028: csr_read_data = {46'd0, 10'h3ff, 8'd8};
        16'h0030: csr_read_data = {16'd0, 16'd4096, 7'd0, 4'b0001,
                                  13'h1fff, 8'd4};
        16'h0040: csr_read_data = {62'd0, stop_q, start_q};
        16'h0048: csr_read_data = {
          58'd0,
          (reset_state_q != RESET_IDLE),
          (core_idle_o && stop_q),
          fault_valid_q,
          accept_new_cmd_o,
          !core_idle_o,
          core_idle_o
        };
        16'h0058: csr_read_data = {16'd0, input_base_q};
        16'h0060: csr_read_data = {16'd0, weight_base_q};
        16'h0068: csr_read_data = {16'd0, work_base_q};
        16'h0070: csr_read_data = {16'd0, output_base_q};
        16'h0078: csr_read_data = {16'd0, kv_base_q};
        16'h0080: csr_read_data = {16'd0, m_axi_addr_base_q};
        16'h0088: csr_read_data = {16'd0, m_axi_addr_limit_q};
        16'h0090: csr_read_data = {32'd0, tbu_substream_id_q,
                                  tbu_stream_id_q};
        16'h00a0: csr_read_data = {61'd0, irq_status_q};
        16'h00a8: csr_read_data = {61'd0, irq_mask_q};
        16'h00b0: csr_read_data = fault_valid_q
                                 ? {52'd0, fault_command_id_q} : 64'd0;
        16'h00b8: csr_read_data = fault_valid_q
                                 ? {16'd0, fault_addr_q} : 64'd0;
        16'h00c0: csr_read_data = fault_valid_q
                                 ? {44'd0, fault_opcode_q, fault_engine_q,
                                    fault_status_q} : 64'd0;
        16'h00d0: csr_read_data = {44'd0, param_l1_base_q};
        16'h00d8: csr_read_data = {44'd0, param_l1_limit_q};
        16'h00e0: csr_read_data = {63'd0, param_lock_q};
        16'h00e8: csr_read_data = {61'd0, reset_reason_q};
        16'h00f0: csr_read_data = {63'd0, l1_host_access_enable_q};
        16'h02c0: csr_read_data = {63'd0, wdt_enable_q};
        16'h02c8: csr_read_data = {32'd0, wdt_timeout_cycles_q};
        16'h02d0: csr_read_data = {56'd0, module_clk_enable_q};
        default:  csr_read_data = 64'd0;
      endcase
    end
  end

  always_ff @(posedge clk_i) begin
    if (!reset_n) begin
      rsp_valid_q                  <= 1'b0;
      rsp_data_q                   <= 64'd0;
      rsp_status_q                 <= 2'b00;
      start_q                      <= 1'b0;
      stop_q                       <= 1'b1;
      irq_status_q                 <= 3'd0;
      irq_mask_q                   <= 3'b111;
      fault_valid_q                <= 1'b0;
      fault_command_id_q           <= 12'd0;
      fault_engine_q               <= 4'd0;
      fault_opcode_q               <= 8'd0;
      fault_status_q               <= NPU_STATUS_SUCCESS;
      fault_addr_q                 <= 48'd0;
      reset_reason_q               <= 3'b001;
      input_base_q                 <= 48'd0;
      weight_base_q                <= 48'd0;
      work_base_q                  <= 48'd0;
      output_base_q                <= 48'd0;
      kv_base_q                    <= 48'd0;
      m_axi_addr_base_q            <= 48'd0;
      m_axi_addr_limit_q           <= 48'hffff_ffff_ffF8;
      tbu_stream_id_q              <= 16'd0;
      tbu_substream_id_q           <= 16'd0;
      param_l1_base_q              <= 20'd0;
      param_l1_limit_q             <= 20'd0;
      param_lock_q                 <= 1'b0;
      l1_host_access_enable_q      <= 1'b0;
      module_clk_enable_q          <= 8'hff;
      wdt_enable_q                 <= 1'b0;
      wdt_timeout_cycles_q         <= 32'd0;
      reset_state_q                <= RESET_IDLE;
      csr_soft_reset_req_q         <= 1'b0;
      single_step_pulse_o          <= 1'b0;
      internal_soft_reset_pulse_o  <= 1'b0;
      interface_error_clear_o      <= 1'b0;
      wdt_kick_o                   <= 1'b0;
    end else begin
      single_step_pulse_o         <= 1'b0;
      internal_soft_reset_pulse_o <= 1'b0;
      interface_error_clear_o     <= 1'b0;
      wdt_kick_o                  <= 1'b0;

      if (rsp_valid_q && reg_rsp_ready_i) begin
        rsp_valid_q <= 1'b0;
      end

      if (reg_req_valid_i && reg_req_ready_o) begin
        rsp_valid_q  <= 1'b1;
        rsp_data_q   <= reg_req_write_i ? 64'd0 : csr_read_data;
        rsp_status_q <= (reg_req_addr_i[2:0] == 3'd0) ? 2'b00 : 2'b10;

        if (reg_req_write_i && (reg_req_addr_i[2:0] == 3'd0)
            && !reg_req_space_i) begin
          unique case (reg_req_addr_i)
            16'h0000, 16'h0008, 16'h0010, 16'h0018,
            16'h0020, 16'h0028, 16'h0030, 16'h0048,
            16'h00b0, 16'h00b8, 16'h00c0, 16'h00e8: begin
              rsp_status_q <= 2'b10;
            end

            16'h0040: begin
              if ((|(reg_req_wdata_i & write_mask(reg_req_wstrb_i)
                    & ~64'hf))
                  || (reg_req_wdata_i[0] && reg_req_wdata_i[1])) begin
                rsp_status_q <= 2'b10;
              end else begin
                if (reg_req_wdata_i[0]) begin
                  start_q <= 1'b1;
                  stop_q  <= 1'b0;
                end
                if (reg_req_wdata_i[1]) begin
                  start_q <= 1'b0;
                  stop_q  <= 1'b1;
                end
                if (reg_req_wdata_i[2]) begin
                  csr_soft_reset_req_q <= 1'b1;
                end
                if (reg_req_wdata_i[3] && stop_q && core_idle_o) begin
                  single_step_pulse_o <= 1'b1;
                end
              end
            end

            16'h0058: begin
              if (!core_idle_o || (|reg_req_wdata_i[63:48])
                  || (|reg_req_wdata_i[2:0])) begin
                rsp_status_q <= 2'b10;
              end else begin
                input_base_q <= merge_write({16'd0, input_base_q},
                                            reg_req_wdata_i,
                                            reg_req_wstrb_i)[47:0];
              end
            end
            16'h0060: begin
              if (!core_idle_o || (|reg_req_wdata_i[63:48])
                  || (|reg_req_wdata_i[2:0])) begin
                rsp_status_q <= 2'b10;
              end else begin
                weight_base_q <= merge_write({16'd0, weight_base_q},
                                             reg_req_wdata_i,
                                             reg_req_wstrb_i)[47:0];
              end
            end
            16'h0068: begin
              if (!core_idle_o || (|reg_req_wdata_i[63:48])
                  || (|reg_req_wdata_i[2:0])) begin
                rsp_status_q <= 2'b10;
              end else begin
                work_base_q <= merge_write({16'd0, work_base_q},
                                           reg_req_wdata_i,
                                           reg_req_wstrb_i)[47:0];
              end
            end
            16'h0070: begin
              if (!core_idle_o || (|reg_req_wdata_i[63:48])
                  || (|reg_req_wdata_i[2:0])) begin
                rsp_status_q <= 2'b10;
              end else begin
                output_base_q <= merge_write({16'd0, output_base_q},
                                             reg_req_wdata_i,
                                             reg_req_wstrb_i)[47:0];
              end
            end
            16'h0078: begin
              if (!core_idle_o || (|reg_req_wdata_i[63:48])
                  || (|reg_req_wdata_i[2:0])) begin
                rsp_status_q <= 2'b10;
              end else begin
                kv_base_q <= merge_write({16'd0, kv_base_q},
                                         reg_req_wdata_i,
                                         reg_req_wstrb_i)[47:0];
              end
            end
            16'h0080: begin
              if (!core_idle_o || (|reg_req_wdata_i[63:48])
                  || (|reg_req_wdata_i[2:0])
                  || (reg_req_wdata_i[47:0] > m_axi_addr_limit_q)) begin
                rsp_status_q <= 2'b10;
              end else begin
                m_axi_addr_base_q <= reg_req_wdata_i[47:0];
              end
            end
            16'h0088: begin
              if (!core_idle_o || (|reg_req_wdata_i[63:48])
                  || (|reg_req_wdata_i[2:0])
                  || (reg_req_wdata_i[47:0] < m_axi_addr_base_q)) begin
                rsp_status_q <= 2'b10;
              end else begin
                m_axi_addr_limit_q <= reg_req_wdata_i[47:0];
              end
            end
            16'h0090: begin
              if (!core_idle_o || (|reg_req_wdata_i[63:32])) begin
                rsp_status_q <= 2'b10;
              end else begin
                tbu_stream_id_q    <= reg_req_wdata_i[15:0];
                tbu_substream_id_q <= reg_req_wdata_i[31:16];
              end
            end
            16'h00a0: begin
              irq_status_q <= irq_status_q
                            & ~(reg_req_wdata_i[2:0]
                                & {3{reg_req_wstrb_i[0]}});
            end
            16'h00a8: begin
              if (|reg_req_wdata_i[63:3]) begin
                rsp_status_q <= 2'b10;
              end else begin
                irq_mask_q <= reg_req_wdata_i[2:0];
              end
            end
            16'h00c8: begin
              if (reg_req_wdata_i[0] && reg_req_wstrb_i[0]) begin
                fault_valid_q          <= 1'b0;
                interface_error_clear_o <= 1'b1;
              end
            end
            16'h00d0: begin
              if (!core_idle_o || (|reg_req_wdata_i[63:20])
                  || (|reg_req_wdata_i[2:0])
                  || (reg_req_wdata_i[19:0] > param_l1_limit_q)) begin
                rsp_status_q <= 2'b10;
              end else begin
                param_l1_base_q <= reg_req_wdata_i[19:0];
              end
            end
            16'h00d8: begin
              if (!core_idle_o || (|reg_req_wdata_i[63:20])
                  || (|reg_req_wdata_i[2:0])
                  || (reg_req_wdata_i[19:0] < param_l1_base_q)) begin
                rsp_status_q <= 2'b10;
              end else begin
                param_l1_limit_q <= reg_req_wdata_i[19:0];
              end
            end
            16'h00e0: begin
              if (reg_req_wdata_i[0] && reg_req_wstrb_i[0]) begin
                if (!l1_write_idle_i) begin
                  rsp_status_q <= 2'b10;
                end else begin
                  param_lock_q <= 1'b1;
                end
              end
            end
            16'h00f0: begin
              if (|reg_req_wdata_i[63:1]) begin
                rsp_status_q <= 2'b10;
              end else begin
                l1_host_access_enable_q <= reg_req_wdata_i[0];
              end
            end
            16'h02c0: begin
              if (|reg_req_wdata_i[63:2]) begin
                rsp_status_q <= 2'b10;
              end else begin
                wdt_enable_q <= reg_req_wdata_i[0];
                if (reg_req_wdata_i[1]) begin
                  wdt_kick_o <= 1'b1;
                end
              end
            end
            16'h02c8: begin
              if (|reg_req_wdata_i[63:32]) begin
                rsp_status_q <= 2'b10;
              end else begin
                wdt_timeout_cycles_q <= reg_req_wdata_i[31:0];
              end
            end
            16'h02d0: begin
              if (|reg_req_wdata_i[63:8]) begin
                rsp_status_q <= 2'b10;
              end else begin
                module_clk_enable_q <= reg_req_wdata_i[7:0];
              end
            end
            default: begin
            end
          endcase
        end
      end

      if (task_terminal_valid_i && task_terminal_ready_o) begin
        if ((task_status_i == NPU_STATUS_SUCCESS)
            && task_irq_on_success_i) begin
          irq_status_q[0] <= 1'b1;
        end else if ((task_status_i != NPU_STATUS_SUCCESS)
                     && task_irq_on_error_i) begin
          if ((task_status_i == NPU_STATUS_TIMEOUT)
              || (task_status_i == NPU_STATUS_NUMERIC_EXCEPTION)) begin
            irq_status_q[1] <= 1'b1;
          end else begin
            irq_status_q[2] <= 1'b1;
          end
        end
        if ((task_status_i != NPU_STATUS_SUCCESS) && !fault_valid_q) begin
          fault_valid_q      <= 1'b1;
          fault_command_id_q <= task_command_id_i;
          fault_engine_q     <= task_engine_i;
          fault_opcode_q     <= task_opcode_i;
          fault_status_q     <= task_status_i;
          fault_addr_q       <= task_fault_addr_i;
        end
      end else if (interface_error_valid_i && !fault_valid_q) begin
        fault_valid_q      <= 1'b1;
        fault_command_id_q <= 12'hfff;
        fault_engine_q     <= 4'd0;
        fault_opcode_q     <= 8'd0;
        fault_status_q     <= interface_error_status_i;
        fault_addr_q       <= interface_error_addr_i;
        irq_status_q[2]    <= 1'b1;
      end else if (wdt_timeout_i && !fault_valid_q) begin
        fault_valid_q      <= 1'b1;
        fault_command_id_q <= 12'hfff;
        fault_engine_q     <= 4'd0;
        fault_opcode_q     <= 8'd0;
        fault_status_q     <= NPU_STATUS_TIMEOUT;
        fault_addr_q       <= 48'd0;
        irq_status_q[2]    <= 1'b1;
        reset_reason_q[2]  <= 1'b1;
      end

      unique case (reset_state_q)
        RESET_IDLE: begin
          if (reset_requested) begin
            start_q      <= 1'b0;
            stop_q       <= 1'b1;
            reset_state_q <= RESET_DRAIN;
          end
        end
        RESET_DRAIN: begin
          if (all_drain_idle) begin
            internal_soft_reset_pulse_o <= 1'b1;
            reset_reason_q[1]           <= 1'b1;
            param_lock_q                <= 1'b0;
            l1_host_access_enable_q     <= 1'b0;
            irq_status_q                <= 3'd0;
            reset_state_q               <= RESET_WAIT_INTERNAL;
          end
        end
        RESET_WAIT_INTERNAL: begin
          if (internal_soft_reset_done_i) begin
            csr_soft_reset_req_q <= 1'b0;
            reset_state_q        <= RESET_DONE;
          end
        end
        RESET_DONE: begin
          if (!soft_reset_req_i && !csr_soft_reset_req_q) begin
            reset_state_q <= RESET_IDLE;
          end
        end
        default: reset_state_q <= RESET_IDLE;
      endcase
    end
  end

endmodule
