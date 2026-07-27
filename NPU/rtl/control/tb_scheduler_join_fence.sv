`timescale 1ns/1ps

module tb_scheduler_join_fence;
  import npu_rtl_pkg::*;

  logic clk;
  logic reset_n;

  logic         cfe_cmd_valid;
  logic         cfe_cmd_ready;
  logic [127:0] cfe_cmd;

  logic        dma_task_valid;
  logic [11:0] dma_task_command_id;
  logic        dma_done_valid;
  logic        dma_done_ready;
  logic [11:0] dma_done_command_id;
  logic [7:0]  dma_done_status;

  logic        matrix_task_valid;
  logic [11:0] matrix_task_command_id;
  logic        matrix_done_valid;
  logic        matrix_done_ready;
  logic [11:0] matrix_done_command_id;
  logic [7:0]  matrix_done_status;

  logic        completion_valid;
  logic [11:0] completion_command_id;
  logic [3:0]  completion_engine;
  logic [7:0]  completion_opcode;
  logic [7:0]  completion_status;

  logic        dma_dispatch_seen_q;
  logic [11:0] dma_dispatch_id_q;
  logic        matrix_dispatch_seen_q;
  logic [11:0] matrix_dispatch_id_q;

  logic       completion_seen_q [0:15];
  logic [3:0] completion_engine_q [0:15];
  logic [7:0] completion_opcode_q [0:15];
  logic [7:0] completion_status_q [0:15];

  always #5 clk = ~clk;

  function automatic logic [79:0] dma_payload();
    return {
      28'h000_0100, 28'h000_0200, 20'd4,
      NPU_DTYPE_INT8, 1'b0, 1'b0
    };
  endfunction

  function automatic logic [79:0] matrix_payload();
    return {
      14'h004, 14'h008, 14'h00c, 12'd0,
      6'd0, 6'd0, 6'd0,
      1'b0, NPU_DTYPE_INT32, 5'd0
    };
  endfunction

  function automatic logic [127:0] make_command(
    input logic [5:0] command_opcode,
    input logic [9:0] command_id,
    input logic [1:0] dtype,
    input logic [79:0] payload,
    input logic [7:0] wait0_event,
    input logic [7:0] wait1_event,
    input logic [7:0] signal_event
  );
    logic [127:0] command;
    begin
      command = 128'd0;
      command[127:122] = command_opcode;
      command[121:112] = command_id;
      command[111:104] = wait0_event;
      command[103:96] = wait1_event;
      command[95:88] = signal_event;
      command[81:80] = dtype;
      command[79:0] = payload;
      return command;
    end
  endfunction

  task automatic apply_reset;
    begin
      @(negedge clk);
      reset_n               = 1'b0;
      cfe_cmd_valid         = 1'b0;
      cfe_cmd               = 128'd0;
      dma_done_valid        = 1'b0;
      dma_done_command_id   = 12'd0;
      dma_done_status       = NPU_STATUS_SUCCESS;
      matrix_done_valid     = 1'b0;
      matrix_done_command_id = 12'd0;
      matrix_done_status    = NPU_STATUS_SUCCESS;
      repeat (4) @(posedge clk);
      @(negedge clk);
      reset_n = 1'b1;
      repeat (3) @(posedge clk);
    end
  endtask

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

  task automatic wait_for_engine_pair;
    int unsigned cycles;
    begin
      cycles = 0;
      while (!(dma_dispatch_seen_q && matrix_dispatch_seen_q) &&
             (cycles < 100)) begin
        @(negedge clk);
        cycles++;
      end
      if (!(dma_dispatch_seen_q && matrix_dispatch_seen_q))
        $fatal(1, "producer engines did not accept both tasks");
      if ((dma_dispatch_id_q != 12'h001) ||
          (matrix_dispatch_id_q != 12'h002))
        $fatal(1, "producer command IDs changed at dispatch");
      if (!(dma_done_ready && matrix_done_ready))
        $fatal(1, "producer engines were not both active");
    end
  endtask

  task automatic complete_dma(
    input logic [11:0] expected_command_id,
    input logic [7:0] status
  );
    begin
      wait (dma_done_ready);
      if (dma_dispatch_id_q != expected_command_id)
        $fatal(1, "unexpected active DMA command");
      @(negedge clk);
      dma_done_command_id = expected_command_id;
      dma_done_status     = status;
      dma_done_valid      = 1'b1;
      @(posedge clk);
      @(negedge clk);
      dma_done_valid = 1'b0;
    end
  endtask

  task automatic complete_matrix(
    input logic [11:0] expected_command_id,
    input logic [7:0] status
  );
    begin
      wait (matrix_done_ready);
      if (matrix_dispatch_id_q != expected_command_id)
        $fatal(1, "unexpected active Matrix command");
      @(negedge clk);
      matrix_done_command_id = expected_command_id;
      matrix_done_status     = status;
      matrix_done_valid      = 1'b1;
      @(posedge clk);
      @(negedge clk);
      matrix_done_valid = 1'b0;
    end
  endtask

  task automatic wait_for_event(
    input int unsigned event_id,
    input logic [2:0] expected_state
  );
    int unsigned cycles;
    begin
      cycles = 0;
      while ((dut.event_state_q[event_id] != expected_state) &&
             (cycles < 100)) begin
        @(negedge clk);
        cycles++;
      end
      if (dut.event_state_q[event_id] != expected_state)
        $fatal(
          1,
          "event %0d state=%0d expected=%0d",
          event_id,
          dut.event_state_q[event_id],
          expected_state
        );
    end
  endtask

  task automatic wait_for_completion(
    input int unsigned command_id,
    input logic [3:0] expected_engine,
    input logic [7:0] expected_opcode,
    input logic [7:0] expected_status
  );
    int unsigned cycles;
    begin
      cycles = 0;
      while (!completion_seen_q[command_id] && (cycles < 150)) begin
        @(negedge clk);
        cycles++;
      end
      if (!completion_seen_q[command_id])
        $fatal(1, "command %0d did not complete", command_id);
      if ((completion_engine_q[command_id] != expected_engine) ||
          (completion_opcode_q[command_id] != expected_opcode) ||
          (completion_status_q[command_id] != expected_status)) begin
        $fatal(
          1,
          "command %0d completion engine/opcode/status=%0h/%0h/%0h",
          command_id,
          completion_engine_q[command_id],
          completion_opcode_q[command_id],
          completion_status_q[command_id]
        );
      end
    end
  endtask

  task automatic expect_not_completed(
    input int unsigned command_id,
    input int unsigned cycles
  );
    begin
      repeat (cycles) @(posedge clk);
      @(negedge clk);
      if (completion_seen_q[command_id])
        $fatal(1, "command %0d completed too early", command_id);
    end
  endtask

  task automatic start_join(input logic join_or);
    logic [79:0] join_payload;
    begin
      submit_command(make_command(
        6'd5, 10'h001, NPU_DTYPE_INT8, dma_payload(),
        8'hff, 8'hff, 8'h01
      ));
      submit_command(make_command(
        6'd12, 10'h002, NPU_DTYPE_INT8, matrix_payload(),
        8'hff, 8'hff, 8'h02
      ));
      join_payload = 80'd0;
      join_payload[75] = join_or;
      submit_command(make_command(
        6'd3, 10'h003, NPU_DTYPE_INT8, join_payload,
        8'h01, 8'h02, 8'h03
      ));
      wait_for_engine_pair();
      if ((dut.event_state_q[1] != NPU_EVENT_PENDING) ||
          (dut.event_state_q[2] != NPU_EVENT_PENDING) ||
          (dut.event_state_q[3] != NPU_EVENT_PENDING))
        $fatal(1, "join events were not pending before producer completion");
    end
  endtask

  always_ff @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
      dma_dispatch_seen_q    <= 1'b0;
      dma_dispatch_id_q      <= 12'd0;
      matrix_dispatch_seen_q <= 1'b0;
      matrix_dispatch_id_q   <= 12'd0;
      for (int unsigned command_id = 0;
           command_id < 16; command_id++) begin
        completion_seen_q[command_id]   <= 1'b0;
        completion_engine_q[command_id] <= 4'd0;
        completion_opcode_q[command_id] <= 8'd0;
        completion_status_q[command_id] <= 8'd0;
      end
    end else begin
      if (dma_task_valid) begin
        dma_dispatch_seen_q <= 1'b1;
        dma_dispatch_id_q   <= dma_task_command_id;
      end
      if (matrix_task_valid) begin
        matrix_dispatch_seen_q <= 1'b1;
        matrix_dispatch_id_q   <= matrix_task_command_id;
      end
      if (completion_valid) begin
        if (completion_command_id[11:4] != 8'd0)
          $fatal(1, "completion command ID exceeds test monitor range");
        completion_seen_q[completion_command_id[3:0]]   <= 1'b1;
        completion_engine_q[completion_command_id[3:0]] <=
          completion_engine;
        completion_opcode_q[completion_command_id[3:0]] <=
          completion_opcode;
        completion_status_q[completion_command_id[3:0]] <=
          completion_status;
      end
    end
  end

  /* verilator lint_off PINCONNECTEMPTY */
  npu_task_scheduler #(
    .TASK_SLOTS(8),
    .EVENT_COUNT(255)
  ) dut (
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
    .cmd_id_lookup_ready_o(),
    .cmd_id_lookup_id_i(10'd0),
    .cmd_id_lookup_rsp_valid_o(),
    .cmd_id_busy_o(),

    .dma_task_valid_o(dma_task_valid),
    .dma_task_ready_i(1'b1),
    .dma_task_opcode_o(),
    .dma_task_command_id_o(dma_task_command_id),
    .dma_task_desc_flat_o(),
    .dma_done_valid_i(dma_done_valid),
    .dma_done_ready_o(dma_done_ready),
    .dma_done_command_id_i(dma_done_command_id),
    .dma_done_status_i(dma_done_status),
    .dma_done_fault_addr_i(48'd0),
    .dma_done_progress_i(64'd0),

    .matrix_task_valid_o(matrix_task_valid),
    .matrix_task_ready_i(1'b1),
    .matrix_task_opcode_o(),
    .matrix_task_command_id_o(matrix_task_command_id),
    .matrix_task_desc_flat_o(),
    .matrix_done_valid_i(matrix_done_valid),
    .matrix_done_ready_o(matrix_done_ready),
    .matrix_done_command_id_i(matrix_done_command_id),
    .matrix_done_status_i(matrix_done_status),
    .matrix_done_fault_addr_i(48'd0),
    .matrix_done_progress_i(64'd0),

    .vector_task_valid_o(),
    .vector_task_ready_i(1'b1),
    .vector_task_opcode_o(),
    .vector_task_command_id_o(),
    .vector_task_desc_flat_o(),
    .vector_done_valid_i(1'b0),
    .vector_done_ready_o(),
    .vector_done_command_id_i(12'd0),
    .vector_done_status_i(NPU_STATUS_SUCCESS),
    .vector_done_fault_addr_i(48'd0),
    .vector_done_progress_i(64'd0),

    .complex_task_valid_o(),
    .complex_task_ready_i(1'b1),
    .complex_task_opcode_o(),
    .complex_task_command_id_o(),
    .complex_task_desc_flat_o(),
    .complex_done_valid_i(1'b0),
    .complex_done_ready_o(),
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
    .completion_fault_addr_o(),
    .completion_progress_o(),
    .completion_irq_success_o(),
    .completion_irq_error_o(),

    .axi_ctl_valid_i(1'b0),
    .axi_ctl_ready_o(),
    .axi_ctl_op_i(2'd0),
    .axi_ctl_arg0_i(64'd0),
    .axi_ctl_arg1_i(64'd0),
    .axi_ctl_cancel_i(1'b0),
    .axi_ctl_rsp_valid_o(),
    .axi_ctl_rsp_ready_i(1'b1),
    .axi_ctl_rsp_data_o(),

    .event_query_valid_i(1'b0),
    .event_query_ref_i(12'd0),
    .event_query_found_o(),
    .event_query_state_o(),
    .event_query_producer_command_id_o(),

    .task_query_valid_i(1'b0),
    .task_query_command_id_i(12'd0),
    .task_query_found_o(),
    .task_query_state_o(),
    .task_query_status_o(),
    .task_query_fault_addr_o(),
    .task_query_progress_o(),
    .task_query_user_tag_o(),
    .task_query_signal_event_o(),
    .task_query_error_info_o(),
    .task_query_done_flags_o(),

    .task_ack_valid_i(1'b0),
    .task_ack_command_id_i(12'd0),
    .task_ack_ready_o(),

    .scheduler_idle_o(),
    .task_occupancy_o()
  );
  /* verilator lint_on PINCONNECTEMPTY */

  initial begin
    logic [79:0] fence_payload;

    clk                    = 1'b0;
    reset_n                = 1'b0;
    cfe_cmd_valid          = 1'b0;
    cfe_cmd                = 128'd0;
    dma_done_valid         = 1'b0;
    dma_done_command_id    = 12'd0;
    dma_done_status        = NPU_STATUS_SUCCESS;
    matrix_done_valid      = 1'b0;
    matrix_done_command_id = 12'd0;
    matrix_done_status     = NPU_STATUS_SUCCESS;

    apply_reset();
    start_join(1'b1);
    complete_dma(12'h001, NPU_STATUS_SUCCESS);
    wait_for_event(1, NPU_EVENT_SUCCESS);
    wait_for_completion(
      3, NPU_ENGINE_CONTROL, NPU_OPCODE_EVENT_JOIN, NPU_STATUS_SUCCESS
    );
    wait_for_event(3, NPU_EVENT_SUCCESS);
    if (!matrix_done_ready || completion_seen_q[2])
      $fatal(1, "OR join waited for the second producer after one success");
    complete_matrix(12'h002, NPU_STATUS_SUCCESS);
    wait_for_completion(
      2, NPU_ENGINE_MATRIX, NPU_OPCODE_GEMM, NPU_STATUS_SUCCESS
    );
    $display("PASS: EVENT_JOIN OR continued after either producer succeeded");

    apply_reset();
    start_join(1'b1);
    complete_dma(12'h001, NPU_STATUS_BUS_SLVERR);
    wait_for_event(1, NPU_EVENT_ERROR);
    expect_not_completed(3, 8);
    if (dut.event_state_q[3] != NPU_EVENT_PENDING)
      $fatal(1, "OR join failed before both producer events failed");
    complete_matrix(12'h002, NPU_STATUS_BUS_SLVERR);
    wait_for_completion(
      3, NPU_ENGINE_CONTROL, NPU_OPCODE_EVENT_JOIN,
      NPU_STATUS_DEPENDENCY_FAILED
    );
    wait_for_event(3, NPU_EVENT_ERROR);
    $display("PASS: EVENT_JOIN OR failed only after both producers failed");

    apply_reset();
    start_join(1'b0);
    complete_dma(12'h001, NPU_STATUS_BUS_SLVERR);
    wait_for_event(1, NPU_EVENT_ERROR);
    wait_for_completion(
      3, NPU_ENGINE_CONTROL, NPU_OPCODE_EVENT_JOIN,
      NPU_STATUS_DEPENDENCY_FAILED
    );
    wait_for_event(3, NPU_EVENT_ERROR);
    if (!matrix_done_ready || completion_seen_q[2])
      $fatal(1, "AND join waited for the second producer after one failure");
    complete_matrix(12'h002, NPU_STATUS_SUCCESS);
    $display("PASS: EVENT_JOIN AND failed after either producer failed");

    apply_reset();
    submit_command(make_command(
      6'd5, 10'h001, NPU_DTYPE_INT8, dma_payload(),
      8'hff, 8'hff, 8'hff
    ));
    submit_command(make_command(
      6'd12, 10'h002, NPU_DTYPE_INT8, matrix_payload(),
      8'hff, 8'hff, 8'hff
    ));
    wait_for_engine_pair();
    fence_payload = 80'd0;
    fence_payload[79:76] = 4'b0001;
    submit_command(make_command(
      6'd4, 10'h003, NPU_DTYPE_INT8, fence_payload,
      8'hff, 8'hff, 8'hff
    ));
    expect_not_completed(3, 8);
    complete_dma(12'h001, NPU_STATUS_SUCCESS);
    wait_for_completion(
      3, NPU_ENGINE_CONTROL, NPU_OPCODE_GLOBAL_FENCE,
      NPU_STATUS_SUCCESS
    );
    if (!matrix_done_ready || completion_seen_q[2])
      $fatal(1, "DMA-masked GLOBAL_FENCE waited for Matrix");
    complete_matrix(12'h002, NPU_STATUS_SUCCESS);
    $display("PASS: GLOBAL_FENCE ignored the unselected Matrix engine");

    $display("PASS: scheduler EVENT_JOIN and masked GLOBAL_FENCE directed test");
    $finish;
  end

  initial begin
    #200000;
    $fatal(1, "scheduler EVENT_JOIN/GLOBAL_FENCE test timeout");
  end

endmodule
