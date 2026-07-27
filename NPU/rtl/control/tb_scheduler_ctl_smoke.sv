module tb_scheduler_ctl_smoke;
  import npu_rtl_pkg::*;

  logic clk;
  logic reset_n;

  logic cfe_cmd_valid;
  logic cfe_cmd_ready;
  logic [127:0] cfe_cmd;

  logic cmd_id_lookup_ready;
  logic cmd_id_lookup_rsp_valid;
  logic cmd_id_busy;

  logic dma_task_valid;
  logic [7:0] dma_task_opcode;
  logic [11:0] dma_task_command_id;
  logic [2047:0] dma_task_desc_flat;
  logic dma_done_valid;
  logic dma_done_ready;
  logic [11:0] dma_done_command_id;
  logic [7:0] dma_done_status;
  logic [47:0] dma_done_fault_addr;
  logic [63:0] dma_done_progress;
  logic dma_seen_q;
  logic [7:0] dma_accepted_opcode_q;
  logic [11:0] dma_accepted_command_id_q;
  logic [31:0] dma_accepted_user_tag_q;

  logic matrix_task_valid;
  logic [7:0] matrix_task_opcode;
  logic [11:0] matrix_task_command_id;
  logic [2047:0] matrix_task_desc_flat;
  logic matrix_done_valid;
  logic matrix_done_ready;
  logic [11:0] matrix_done_command_id;
  logic [7:0] matrix_done_status;
  logic [47:0] matrix_done_fault_addr;
  logic [63:0] matrix_done_progress;
  logic matrix_seen_q;
  logic [7:0] matrix_accepted_opcode_q;
  logic [11:0] matrix_accepted_command_id_q;
  logic [31:0] matrix_accepted_user_tag_q;

  logic vector_task_valid;
  logic [7:0] vector_task_opcode;
  logic [11:0] vector_task_command_id;
  logic [2047:0] vector_task_desc_flat;
  logic vector_done_ready;
  logic complex_task_valid;
  logic [7:0] complex_task_opcode;
  logic [11:0] complex_task_command_id;
  logic [2047:0] complex_task_desc_flat;
  logic complex_done_ready;

  logic completion_valid;
  logic [11:0] completion_command_id;
  logic [3:0] completion_engine;
  logic [7:0] completion_opcode;
  logic [7:0] completion_status;
  logic [47:0] completion_fault_addr;
  logic [63:0] completion_progress;
  logic completion_irq_success;
  logic completion_irq_error;
  int unsigned completion_count;

  logic ctl_valid;
  logic ctl_ready;
  logic [1:0] ctl_op;
  logic [63:0] ctl_arg0;
  logic [63:0] ctl_arg1;
  logic ctl_rsp_valid;
  logic [63:0] ctl_rsp_data;
  logic event_query_found;
  logic [2:0] event_query_state;
  logic [11:0] event_query_producer_command_id;
  logic task_query_found;
  logic [3:0] task_query_state;
  logic [7:0] task_query_status;
  logic [47:0] task_query_fault_addr;
  logic [63:0] task_query_progress;
  logic [31:0] task_query_user_tag;
  logic [11:0] task_query_signal_event;
  logic [31:0] task_query_error_info;
  logic [15:0] task_query_done_flags;
  logic task_ack_ready;
  logic scheduler_idle;
  logic [15:0] task_occupancy;

  always #5 clk = ~clk;

  function automatic logic [127:0] make_command(
    input logic [5:0] command_opcode,
    input logic [9:0] command_id,
    input logic [1:0] dtype,
    input logic [79:0] payload,
    input logic [7:0] signal_event
  );
    logic [127:0] command;
    begin
      command = 128'd0;
      command[127:122] = command_opcode;
      command[121:112] = command_id;
      command[111:104] = 8'hff;
      command[103:96] = 8'hff;
      command[95:88] = signal_event;
      command[81:80] = dtype;
      command[79:0] = payload;
      return command;
    end
  endfunction

  npu_task_scheduler #(
    .TASK_SLOTS(4),
    .EVENT_COUNT(255)
  ) u_scheduler (
    .clk_i(clk),
    .reset_n(reset_n),
    .enable_i(1'b1),
    .quiesce_i(1'b0),
    .abort_i(1'b0),

    .cfe_cmd_valid_i(cfe_cmd_valid),
    .cfe_cmd_ready_o(cfe_cmd_ready),
    .cfe_cmd_i(cfe_cmd),
    .input_base_i(48'd0),
    .weight_base_i(48'd0),
    .work_base_i(48'd0),
    .output_base_i(48'd0),
    .kv_base_i(48'd0),
    .param_l1_base_i(20'd0),

    .cmd_id_lookup_valid_i(1'b0),
    .cmd_id_lookup_ready_o(cmd_id_lookup_ready),
    .cmd_id_lookup_id_i(10'd0),
    .cmd_id_lookup_rsp_valid_o(cmd_id_lookup_rsp_valid),
    .cmd_id_busy_o(cmd_id_busy),

    .dma_task_valid_o(dma_task_valid),
    .dma_task_ready_i(1'b1),
    .dma_task_opcode_o(dma_task_opcode),
    .dma_task_command_id_o(dma_task_command_id),
    .dma_task_desc_flat_o(dma_task_desc_flat),
    .dma_done_valid_i(dma_done_valid),
    .dma_done_ready_o(dma_done_ready),
    .dma_done_command_id_i(dma_done_command_id),
    .dma_done_status_i(dma_done_status),
    .dma_done_fault_addr_i(dma_done_fault_addr),
    .dma_done_progress_i(dma_done_progress),

    .matrix_task_valid_o(matrix_task_valid),
    .matrix_task_ready_i(1'b1),
    .matrix_task_opcode_o(matrix_task_opcode),
    .matrix_task_command_id_o(matrix_task_command_id),
    .matrix_task_desc_flat_o(matrix_task_desc_flat),
    .matrix_done_valid_i(matrix_done_valid),
    .matrix_done_ready_o(matrix_done_ready),
    .matrix_done_command_id_i(matrix_done_command_id),
    .matrix_done_status_i(matrix_done_status),
    .matrix_done_fault_addr_i(matrix_done_fault_addr),
    .matrix_done_progress_i(matrix_done_progress),

    .vector_task_valid_o(vector_task_valid),
    .vector_task_ready_i(1'b1),
    .vector_task_opcode_o(vector_task_opcode),
    .vector_task_command_id_o(vector_task_command_id),
    .vector_task_desc_flat_o(vector_task_desc_flat),
    .vector_done_valid_i(1'b0),
    .vector_done_ready_o(vector_done_ready),
    .vector_done_command_id_i(12'd0),
    .vector_done_status_i(NPU_STATUS_SUCCESS),
    .vector_done_fault_addr_i(48'd0),
    .vector_done_progress_i(64'd0),

    .complex_task_valid_o(complex_task_valid),
    .complex_task_ready_i(1'b1),
    .complex_task_opcode_o(complex_task_opcode),
    .complex_task_command_id_o(complex_task_command_id),
    .complex_task_desc_flat_o(complex_task_desc_flat),
    .complex_done_valid_i(1'b0),
    .complex_done_ready_o(complex_done_ready),
    .complex_done_command_id_i(12'd0),
    .complex_done_status_i(NPU_STATUS_SUCCESS),
    .complex_done_fault_addr_i(48'd0),
    .complex_done_progress_i(64'd0),

    .completion_valid_o(completion_valid),
    .completion_ready_i(1'b1),
    .completion_command_id_o(completion_command_id),
    .completion_engine_o(completion_engine),
    .completion_opcode_o(completion_opcode),
    .completion_status_o(completion_status),
    .completion_fault_addr_o(completion_fault_addr),
    .completion_progress_o(completion_progress),
    .completion_irq_success_o(completion_irq_success),
    .completion_irq_error_o(completion_irq_error),

    .axi_ctl_valid_i(ctl_valid),
    .axi_ctl_ready_o(ctl_ready),
    .axi_ctl_op_i(ctl_op),
    .axi_ctl_arg0_i(ctl_arg0),
    .axi_ctl_arg1_i(ctl_arg1),
    .axi_ctl_cancel_i(1'b0),
    .axi_ctl_rsp_valid_o(ctl_rsp_valid),
    .axi_ctl_rsp_ready_i(1'b1),
    .axi_ctl_rsp_data_o(ctl_rsp_data),

    .event_query_valid_i(1'b0),
    .event_query_ref_i(12'd0),
    .event_query_found_o(event_query_found),
    .event_query_state_o(event_query_state),
    .event_query_producer_command_id_o(
      event_query_producer_command_id
    ),

    .task_query_valid_i(1'b0),
    .task_query_command_id_i(12'd0),
    .task_query_found_o(task_query_found),
    .task_query_state_o(task_query_state),
    .task_query_status_o(task_query_status),
    .task_query_fault_addr_o(task_query_fault_addr),
    .task_query_progress_o(task_query_progress),
    .task_query_user_tag_o(task_query_user_tag),
    .task_query_signal_event_o(task_query_signal_event),
    .task_query_error_info_o(task_query_error_info),
    .task_query_done_flags_o(task_query_done_flags),

    .task_ack_valid_i(1'b0),
    .task_ack_command_id_i(12'd0),
    .task_ack_ready_o(task_ack_ready),

    .scheduler_idle_o(scheduler_idle),
    .task_occupancy_o(task_occupancy)
  );

  always_ff @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
      completion_count <= 0;
    end else if (completion_valid) begin
      completion_count <= completion_count + 1;
      if (completion_status != NPU_STATUS_SUCCESS) begin
        $fatal(1, "unexpected failed completion");
      end
      if ((completion_fault_addr != 48'd0)
          || completion_irq_success || completion_irq_error
          || !((completion_command_id == 12'h001
                && completion_engine == NPU_ENGINE_DMA
                && completion_opcode == NPU_OPCODE_DMA_COPY_1D)
               || (completion_command_id == 12'h002
                   && completion_engine == NPU_ENGINE_MATRIX
                   && completion_opcode == NPU_OPCODE_GEMM)
               || (completion_command_id == 12'h003
                   && completion_engine == NPU_ENGINE_CONTROL
                   && completion_opcode == NPU_OPCODE_EVENT_REARM)
               || (completion_command_id == 12'h004
                   && completion_engine == NPU_ENGINE_CONTROL
                   && completion_opcode == NPU_OPCODE_EVENT_SIGNAL))) begin
        $fatal(1, "completion metadata is incorrect");
      end
      if ((completion_command_id == 12'h001)
          && (completion_progress != 64'h123)) begin
        $fatal(1, "DMA progress was not retained");
      end
      if ((completion_command_id == 12'h002)
          && (completion_progress != 64'h456)) begin
        $fatal(1, "Matrix progress was not retained");
      end
    end
  end

  always_ff @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
      dma_seen_q                    <= 1'b0;
      dma_accepted_opcode_q         <= 8'd0;
      dma_accepted_command_id_q     <= 12'd0;
      dma_accepted_user_tag_q       <= 32'd0;
      matrix_seen_q                 <= 1'b0;
      matrix_accepted_opcode_q      <= 8'd0;
      matrix_accepted_command_id_q  <= 12'd0;
      matrix_accepted_user_tag_q    <= 32'd0;
    end else begin
      if (dma_task_valid) begin
        if ((dma_task_desc_flat[64 +: 64] != 64'h100)
            || (dma_task_desc_flat[256 +: 64] != 64'h200)
            || (dma_task_desc_flat[16'h48 * 8 +: 32] != 32'd4)) begin
          $fatal(1, "DMA dispatch changed descriptor data");
        end
        dma_seen_q                <= 1'b1;
        dma_accepted_opcode_q     <= dma_task_opcode;
        dma_accepted_command_id_q <= dma_task_command_id;
        dma_accepted_user_tag_q   <= dma_task_desc_flat[511:480];
      end
      if (matrix_task_valid) begin
        if ((matrix_task_desc_flat[64 +: 64] != 64'h100)
            || (matrix_task_desc_flat[128 +: 64] != 64'h200)
            || (matrix_task_desc_flat[256 +: 64] != 64'h300)
            || (matrix_task_desc_flat[16'h40 * 8 +: 32] != 32'd1)
            || (matrix_task_desc_flat[16'h44 * 8 +: 32] != 32'd1)
            || (matrix_task_desc_flat[16'h48 * 8 +: 32] != 32'd1)) begin
          $fatal(1, "Matrix dispatch changed descriptor data");
        end
        matrix_seen_q                <= 1'b1;
        matrix_accepted_opcode_q     <= matrix_task_opcode;
        matrix_accepted_command_id_q <= matrix_task_command_id;
        matrix_accepted_user_tag_q   <= matrix_task_desc_flat[511:480];
      end
    end
  end

  task automatic submit_command(input logic [127:0] command);
    begin
      @(negedge clk);
      cfe_cmd       = command;
      cfe_cmd_valid = 1'b1;
      while (!cfe_cmd_ready) @(negedge clk);
      @(posedge clk);
      @(negedge clk);
      cfe_cmd_valid = 1'b0;
      cfe_cmd       = 128'd0;
    end
  endtask

  task automatic start_ctl(
    input logic [1:0] operation,
    input logic [63:0] argument0,
    input logic [63:0] argument1
  );
    begin
      @(negedge clk);
      ctl_op    = operation;
      ctl_arg0  = argument0;
      ctl_arg1  = argument1;
      ctl_valid = 1'b1;
      while (!ctl_ready) @(negedge clk);
      @(posedge clk);
      @(negedge clk);
      ctl_valid = 1'b0;
      ctl_op    = 2'd0;
      ctl_arg0  = 64'd0;
      ctl_arg1  = 64'd0;
    end
  endtask

  task automatic receive_ctl(output logic [63:0] response);
    begin
      wait (ctl_rsp_valid);
      response = ctl_rsp_data;
      @(posedge clk);
      @(negedge clk);
    end
  endtask

  task automatic ctl_request(
    input logic [1:0] operation,
    input logic [63:0] argument0,
    input logic [63:0] argument1,
    output logic [63:0] response
  );
    begin
      start_ctl(operation, argument0, argument1);
      receive_ctl(response);
    end
  endtask

  task automatic complete_dma(
    input logic [7:0] status,
    input logic [63:0] progress
  );
    begin
      @(negedge clk);
      dma_done_command_id = dma_accepted_command_id_q;
      dma_done_status     = status;
      dma_done_fault_addr = 48'd0;
      dma_done_progress   = progress;
      dma_done_valid      = 1'b1;
      while (!dma_done_ready) @(negedge clk);
      @(posedge clk);
      @(negedge clk);
      dma_done_valid = 1'b0;
    end
  endtask

  task automatic complete_matrix(
    input logic [7:0] status,
    input logic [63:0] progress
  );
    begin
      @(negedge clk);
      matrix_done_command_id = matrix_accepted_command_id_q;
      matrix_done_status     = status;
      matrix_done_fault_addr = 48'd0;
      matrix_done_progress   = progress;
      matrix_done_valid      = 1'b1;
      while (!matrix_done_ready) @(negedge clk);
      @(posedge clk);
      @(negedge clk);
      matrix_done_valid = 1'b0;
    end
  endtask

  initial begin
    logic [63:0] response;
    logic [79:0] payload;

    clk                    = 1'b0;
    reset_n                = 1'b0;
    cfe_cmd_valid          = 1'b0;
    cfe_cmd                = 128'd0;
    dma_done_valid         = 1'b0;
    dma_done_command_id    = 12'd0;
    dma_done_status        = NPU_STATUS_SUCCESS;
    dma_done_fault_addr    = 48'd0;
    dma_done_progress      = 64'd0;
    matrix_done_valid      = 1'b0;
    matrix_done_command_id = 12'd0;
    matrix_done_status     = NPU_STATUS_SUCCESS;
    matrix_done_fault_addr = 48'd0;
    matrix_done_progress   = 64'd0;
    ctl_valid              = 1'b0;
    ctl_op                 = 2'd0;
    ctl_arg0               = 64'd0;
    ctl_arg1               = 64'd0;

    repeat (4) @(posedge clk);
    reset_n = 1'b1;
    repeat (2) @(posedge clk);

    payload = {
      28'h000_0100, 28'h000_0200, 20'd4,
      NPU_DTYPE_INT8, 1'b0, 1'b0
    };
    submit_command(make_command(
      6'd5, 10'h001, NPU_DTYPE_INT8, payload, 8'h00));
    payload = {
      14'h004, 14'h008, 14'h00c, 12'd0,
      6'd0, 6'd0, 6'd0,
      1'b0, NPU_DTYPE_INT32, 5'd0
    };
    submit_command(make_command(
      6'd12, 10'h002, NPU_DTYPE_INT8, payload, 8'hff));

    wait (dma_seen_q && matrix_seen_q
          && dma_done_ready && matrix_done_ready);
    if ((dma_accepted_opcode_q != NPU_OPCODE_DMA_COPY_1D)
        || (matrix_accepted_opcode_q != NPU_OPCODE_GEMM)
        || (dma_accepted_user_tag_q != 32'h0000_0001)
        || (matrix_accepted_user_tag_q != 32'h0000_0002)) begin
      $fatal(1, "engine dispatch data mismatch");
    end

    ctl_request(NPU_CTL_WAIT, 64'h000, 64'd3, response);
    if (response[7:0] != NPU_STATUS_TIMEOUT) begin
      $fatal(1, "WAIT did not time out a pending event");
    end

    start_ctl(NPU_CTL_FENCE, 64'h1, 64'd100);
    complete_dma(NPU_STATUS_SUCCESS, 64'h123);
    receive_ctl(response);
    if (response[7:0] != NPU_STATUS_SUCCESS) begin
      $fatal(1, "DMA-only FENCE did not complete successfully");
    end
    if (!matrix_done_ready) begin
      $fatal(1, "DMA-only FENCE waited for the Matrix engine");
    end

    start_ctl(NPU_CTL_FENCE, 64'h2, 64'd100);
    complete_matrix(NPU_STATUS_SUCCESS, 64'h456);
    receive_ctl(response);
    if (response[7:0] != NPU_STATUS_SUCCESS) begin
      $fatal(1, "Matrix-only FENCE did not complete successfully");
    end

    wait (completion_count == 2);
    repeat (2) @(posedge clk);

    ctl_request(NPU_CTL_WAIT, 64'h000, 64'd10, response);
    if ((response[2:0] != NPU_EVENT_SUCCESS)
        || (response[19:8] != 12'h001)) begin
      $fatal(1, "WAIT result did not identify the event producer");
    end

    ctl_request(NPU_CTL_QUERY, 64'h001, 64'd3, response);
    if (response != 64'h123) begin
      $fatal(1, "QUERY progress did not return the engine count");
    end

    ctl_request(NPU_CTL_QUERY, 64'h001, 64'd0, response);
    if ((response[23:12] != 12'h001)
        || (response[11:4] != NPU_STATUS_SUCCESS)
        || (response[3:0] != 4'd3)) begin
      $fatal(1, "QUERY status result is malformed");
    end

    ctl_request(NPU_CTL_QUERY, 64'h001, 64'd4, response);
    if (response != 64'd0) begin
      $fatal(1, "QUERY ACK did not release a terminal task");
    end

    ctl_request(NPU_CTL_QUERY, 64'h001, 64'd0, response);
    if ((response[11:4] != NPU_STATUS_NOT_FOUND)
        || (response[3:0] != 4'd0)) begin
      $fatal(1, "released task was still visible");
    end

    ctl_request(NPU_CTL_QUERY, 64'h002, 64'd7, response);
    if (response[7:0] != NPU_STATUS_BAD_DESC) begin
      $fatal(1, "reserved QUERY selector was not rejected");
    end

    ctl_request(NPU_CTL_QUERY, 64'h401, 64'd0, response);
    if (response[7:0] != NPU_STATUS_BAD_DESC) begin
      $fatal(1, "QUERY accepted nonzero command-ID reserved bits");
    end

    submit_command(make_command(
      6'd2, 10'h003, NPU_DTYPE_INT8, 80'd0, 8'h00));
    wait ((completion_count == 3)
          && (u_scheduler.event_state_q[0] == NPU_EVENT_FREE)
          && (u_scheduler.event_generation_q[0] == 4'd1));

    submit_command(make_command(
      6'd1, 10'h004, NPU_DTYPE_INT8, 80'd0, 8'h00));
    wait ((completion_count == 4)
          && (u_scheduler.event_state_q[0] == NPU_EVENT_SUCCESS)
          && (u_scheduler.event_generation_q[0] == 4'd1));

    ctl_request(NPU_CTL_WAIT, 64'h000, 64'd10, response);
    if ((response[2:0] != NPU_EVENT_SUCCESS)
        || (response[19:8] != 12'h004)) begin
      $fatal(1, "WAIT did not resolve the current event generation");
    end

    $display(
      "PASS: scheduler WAIT by event ID, masked FENCE, QUERY and ACK signature=%0b",
      ^{
        cmd_id_lookup_ready, cmd_id_lookup_rsp_valid, cmd_id_busy,
        dma_task_desc_flat, matrix_task_desc_flat,
        vector_task_valid, vector_task_opcode, vector_task_command_id,
        vector_task_desc_flat, vector_done_ready,
        complex_task_valid, complex_task_opcode, complex_task_command_id,
        complex_task_desc_flat, complex_done_ready,
        event_query_found, event_query_state,
        event_query_producer_command_id,
        task_query_found, task_query_state, task_query_status,
        task_query_fault_addr, task_query_progress, task_query_user_tag,
        task_query_signal_event, task_query_error_info,
        task_query_done_flags, task_ack_ready,
        scheduler_idle, task_occupancy
      }
    );
    $finish;
  end

  initial begin
    #100000;
    $fatal(1, "scheduler control smoke test timeout");
  end

endmodule
