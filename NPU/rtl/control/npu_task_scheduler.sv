module npu_task_scheduler #(
  parameter int unsigned TASK_SLOTS = 16,
  parameter int unsigned EVENT_COUNT = 255,
  localparam int unsigned TASK_IDX_W = (TASK_SLOTS <= 1) ? 1 : $clog2(TASK_SLOTS)
) (
  input  logic          clk_i,
  input  logic          reset_n,
  input  logic          enable_i,
  input  logic          quiesce_i,
  input  logic          abort_i,

  input  logic          cfe_cmd_valid_i,
  output logic          cfe_cmd_ready_o,
  input  logic [127:0]  cfe_cmd_i,

  input  logic [47:0]   input_base_i,
  input  logic [47:0]   weight_base_i,
  input  logic [47:0]   work_base_i,
  input  logic [47:0]   output_base_i,
  input  logic [47:0]   kv_base_i,
  input  logic [19:0]   param_l1_base_i,

  input  logic          cmd_id_lookup_valid_i,
  output logic          cmd_id_lookup_ready_o,
  input  logic [9:0]    cmd_id_lookup_id_i,
  output logic          cmd_id_lookup_rsp_valid_o,
  output logic          cmd_id_busy_o,

  output logic          dma_task_valid_o,
  input  logic          dma_task_ready_i,
  output logic [7:0]    dma_task_opcode_o,
  output logic [11:0]   dma_task_command_id_o,
  output logic [2047:0] dma_task_desc_flat_o,
  input  logic          dma_done_valid_i,
  output logic          dma_done_ready_o,
  input  logic [11:0]   dma_done_command_id_i,
  input  logic [7:0]    dma_done_status_i,
  input  logic [47:0]   dma_done_fault_addr_i,
  input  logic [63:0]   dma_done_progress_i,

  output logic          matrix_task_valid_o,
  input  logic          matrix_task_ready_i,
  output logic [7:0]    matrix_task_opcode_o,
  output logic [11:0]   matrix_task_command_id_o,
  output logic [2047:0] matrix_task_desc_flat_o,
  input  logic          matrix_done_valid_i,
  output logic          matrix_done_ready_o,
  input  logic [11:0]   matrix_done_command_id_i,
  input  logic [7:0]    matrix_done_status_i,
  input  logic [47:0]   matrix_done_fault_addr_i,
  input  logic [63:0]   matrix_done_progress_i,

  output logic          vector_task_valid_o,
  input  logic          vector_task_ready_i,
  output logic [7:0]    vector_task_opcode_o,
  output logic [11:0]   vector_task_command_id_o,
  output logic [2047:0] vector_task_desc_flat_o,
  input  logic          vector_done_valid_i,
  output logic          vector_done_ready_o,
  input  logic [11:0]   vector_done_command_id_i,
  input  logic [7:0]    vector_done_status_i,
  input  logic [47:0]   vector_done_fault_addr_i,
  input  logic [63:0]   vector_done_progress_i,

  output logic          complex_task_valid_o,
  input  logic          complex_task_ready_i,
  output logic [7:0]    complex_task_opcode_o,
  output logic [11:0]   complex_task_command_id_o,
  output logic [2047:0] complex_task_desc_flat_o,
  input  logic          complex_done_valid_i,
  output logic          complex_done_ready_o,
  input  logic [11:0]   complex_done_command_id_i,
  input  logic [7:0]    complex_done_status_i,
  input  logic [47:0]   complex_done_fault_addr_i,
  input  logic [63:0]   complex_done_progress_i,

  output logic          completion_valid_o,
  input  logic          completion_ready_i,
  output logic [11:0]   completion_command_id_o,
  output logic [3:0]    completion_engine_o,
  output logic [7:0]    completion_opcode_o,
  output logic [7:0]    completion_status_o,
  output logic [47:0]   completion_fault_addr_o,
  output logic [63:0]   completion_progress_o,
  output logic          completion_irq_success_o,
  output logic          completion_irq_error_o,

  input  logic          axi_ctl_valid_i,
  output logic          axi_ctl_ready_o,
  input  logic [1:0]    axi_ctl_op_i,
  input  logic [63:0]   axi_ctl_arg0_i,
  input  logic [63:0]   axi_ctl_arg1_i,
  input  logic          axi_ctl_cancel_i,
  output logic          axi_ctl_rsp_valid_o,
  input  logic          axi_ctl_rsp_ready_i,
  output logic [63:0]   axi_ctl_rsp_data_o,

  input  logic          event_query_valid_i,
  input  logic [11:0]   event_query_ref_i,
  output logic          event_query_found_o,
  output logic [2:0]    event_query_state_o,
  output logic [11:0]   event_query_producer_command_id_o,

  input  logic          task_query_valid_i,
  input  logic [11:0]   task_query_command_id_i,
  output logic          task_query_found_o,
  output logic [3:0]    task_query_state_o,
  output logic [7:0]    task_query_status_o,
  output logic [47:0]   task_query_fault_addr_o,
  output logic [63:0]   task_query_progress_o,
  output logic [31:0]   task_query_user_tag_o,
  output logic [11:0]   task_query_signal_event_o,
  output logic [31:0]   task_query_error_info_o,
  output logic [15:0]   task_query_done_flags_o,

  input  logic          task_ack_valid_i,
  input  logic [11:0]   task_ack_command_id_i,
  output logic          task_ack_ready_o,

  output logic          scheduler_idle_o,
  output logic [15:0]   task_occupancy_o
);
  import npu_rtl_pkg::*;

  logic [3:0]    task_state_q        [TASK_SLOTS];
  logic [11:0]   task_command_id_q   [TASK_SLOTS];
  logic [3:0]    task_engine_q       [TASK_SLOTS];
  logic [7:0]    task_opcode_q       [TASK_SLOTS];
  logic [11:0]   task_header_flags_q [TASK_SLOTS];
  logic [11:0]   task_wait0_q        [TASK_SLOTS];
  logic [11:0]   task_wait1_q        [TASK_SLOTS];
  logic [11:0]   task_signal_q       [TASK_SLOTS];
  logic [63:0]   task_submit_seq_q   [TASK_SLOTS];
  /*
   * Keep the submitted instruction and its address-base snapshot instead of
   * a 2048-bit expanded descriptor per slot.  The snapshot preserves the
   * values seen at submission even if software changes the CSRs later.
   */
  logic [127:0]  task_cmd_q           [TASK_SLOTS];
  logic [47:0]   task_input_base_q    [TASK_SLOTS];
  logic [47:0]   task_weight_base_q   [TASK_SLOTS];
  logic [47:0]   task_work_base_q     [TASK_SLOTS];
  logic [47:0]   task_output_base_q   [TASK_SLOTS];
  logic [47:0]   task_kv_base_q       [TASK_SLOTS];
  logic [19:0]   task_param_l1_base_q [TASK_SLOTS];
  logic [7:0]    task_status_q       [TASK_SLOTS];
  logic [47:0]   task_fault_addr_q   [TASK_SLOTS];
  logic [63:0]   task_progress_q     [TASK_SLOTS];
  logic [31:0]   task_error_info_q   [TASK_SLOTS];
  logic [15:0]   task_done_flags_q   [TASK_SLOTS];
  logic          task_notify_q       [TASK_SLOTS];
  logic          task_event_published_q [TASK_SLOTS];

  logic [2:0] event_state_q      [EVENT_COUNT];
  logic [3:0] event_generation_q [EVENT_COUNT];
  logic [11:0] event_producer_q  [EVENT_COUNT];

  logic [63:0] submit_seq_q;
  logic        dma_active_q;
  logic        matrix_active_q;
  logic        vector_active_q;
  logic        complex_active_q;
  logic [TASK_IDX_W-1:0] dma_active_slot_q;
  logic [TASK_IDX_W-1:0] matrix_active_slot_q;
  logic [TASK_IDX_W-1:0] vector_active_slot_q;
  logic [TASK_IDX_W-1:0] complex_active_slot_q;
  logic dma_dispatch_valid_q;
  logic matrix_dispatch_valid_q;
  logic vector_dispatch_valid_q;
  logic complex_dispatch_valid_q;
  logic [TASK_IDX_W-1:0] dma_dispatch_slot_q;
  logic [TASK_IDX_W-1:0] matrix_dispatch_slot_q;
  logic [TASK_IDX_W-1:0] vector_dispatch_slot_q;
  logic [TASK_IDX_W-1:0] complex_dispatch_slot_q;
  logic [7:0] dma_dispatch_opcode_q;
  logic [7:0] matrix_dispatch_opcode_q;
  logic [7:0] vector_dispatch_opcode_q;
  logic [7:0] complex_dispatch_opcode_q;
  logic [11:0] dma_dispatch_command_id_q;
  logic [11:0] matrix_dispatch_command_id_q;
  logic [11:0] vector_dispatch_command_id_q;
  logic [11:0] complex_dispatch_command_id_q;
  logic [2047:0] dma_dispatch_desc_q;
  logic [2047:0] matrix_dispatch_desc_q;
  logic [2047:0] vector_dispatch_desc_q;
  logic [2047:0] complex_dispatch_desc_q;
  logic ctl_active_q;
  logic [1:0] ctl_op_q;
  logic [11:0] ctl_arg0_q;
  logic [31:0] ctl_arg1_q;
  logic [31:0] ctl_wait_count_q;
  logic ctl_rsp_valid_q;
  logic [63:0] ctl_rsp_data_q;
  logic ctl_ack_release_q;
  logic [TASK_IDX_W-1:0] ctl_ack_slot_q;
  logic [TASK_SLOTS-1:0] ctl_fence_target_q;
  logic [63:0] ctl_fence_target_seq_q [TASK_SLOTS];
  logic [7:0] ctl_fence_status_q;
  logic [63:0] ctl_fence_failure_seq_q;

  logic free_found;
  logic [TASK_IDX_W-1:0] free_slot;
  logic lookup_busy_comb;
  logic lookup_busy_q;

  logic completion_found;
  logic [TASK_IDX_W-1:0] completion_select;
  logic completion_hold_valid_q;
  logic [TASK_IDX_W-1:0] completion_hold_slot_q;
  logic event_publish_found;
  logic [TASK_IDX_W-1:0] event_publish_select;
  logic event_publish_pending_valid_q;
  logic [TASK_IDX_W-1:0] event_publish_pending_slot_q;
  logic query_found;
  logic [TASK_IDX_W-1:0] query_select;
  logic ctl_query_found;
  logic [TASK_IDX_W-1:0] ctl_query_select;
  logic ack_found;
  logic [TASK_IDX_W-1:0] ack_select;

  logic control_select_found;
  logic [TASK_IDX_W-1:0] control_select;

  logic dependency_success [TASK_SLOTS];
  logic dependency_failed  [TASK_SLOTS];
  logic order_blocked      [TASK_SLOTS];
  logic event_resources_valid;
  logic cmd_static_valid;
  logic cmd_accept;
  logic event_query_ref_valid;
  logic ctl_wait_event_found;
  logic ctl_wait_event_terminal;
  logic [2:0] ctl_wait_event_state;
  logic [11:0] ctl_wait_event_producer;
  logic ctl_fence_pending;
  logic [7:0] ctl_fence_result_status;
  logic [63:0] ctl_fence_result_seq;
  logic [TASK_SLOTS-1:0] ctl_fence_accept_target;
  logic [7:0] ctl_fence_accept_status;
  logic [63:0] ctl_fence_accept_failure_seq;
  logic [11:0] cmd_command_id;
  logic [3:0] cmd_engine;
  logic [7:0] cmd_opcode;
  logic [11:0] cmd_header_flags;
  logic [11:0] cmd_wait0;
  logic [11:0] cmd_wait1;
  logic [11:0] cmd_signal;
  logic [11:0] cmd_wait0_resolved;
  logic [11:0] cmd_wait1_resolved;
  logic [11:0] cmd_signal_resolved;
  logic cmd_is_inline_rearm;
  logic inline_desc_valid;
  logic [3:0] inline_engine;
  logic [7:0] inline_opcode;
  logic decode_pending_valid_q;
  logic [3:0] decode_pending_engine_q;
  logic [TASK_IDX_W-1:0] decode_pending_slot_q;
  logic [7:0] decode_pending_opcode_q;
  logic [11:0] decode_pending_command_id_q;
  logic [127:0] decode_pending_cmd_q;
  logic [47:0] decode_pending_input_base_q;
  logic [47:0] decode_pending_weight_base_q;
  logic [47:0] decode_pending_work_base_q;
  logic [47:0] decode_pending_output_base_q;
  logic [47:0] decode_pending_kv_base_q;
  logic [19:0] decode_pending_param_l1_base_q;
  logic [2047:0] decode_pending_desc_flat;
  logic decode_scan_active_q;
  logic [TASK_IDX_W-1:0] decode_scan_slot_q;
  logic decode_scan_best_valid_q;
  logic [TASK_IDX_W-1:0] decode_scan_best_slot_q;
  logic [63:0] decode_scan_best_seq_q;
  logic [3:0] decode_scan_current_engine;
  logic decode_scan_current_eligible;
  logic decode_scan_best_eligible;
  logic decode_scan_winner_valid;
  logic [TASK_IDX_W-1:0] decode_scan_winner_slot;
  logic [3:0] decode_scan_winner_engine;
  logic decode_pending_task_valid;
  logic [11:0] control_rearm_current_ref;
  logic [3:0] control_rearm_next_generation;

  assign cmd_command_id   = npu_cmd_command_id(cfe_cmd_i);
  assign cmd_engine       = inline_engine;
  assign cmd_opcode       = inline_opcode;
  assign cmd_header_flags = npu_cmd_header_flags(cfe_cmd_i);
  assign cmd_wait0        = npu_cmd_wait0(cfe_cmd_i);
  assign cmd_wait1        = npu_cmd_wait1(cfe_cmd_i);
  assign cmd_signal       = npu_cmd_signal(cfe_cmd_i);
  assign cmd_is_inline_rearm =
    (cmd_engine == NPU_ENGINE_CONTROL) &&
    (cmd_opcode == NPU_OPCODE_EVENT_REARM);

  /* verilator lint_off PINCONNECTEMPTY */
  npu_inline_desc_decode u_inline_desc_decode (
    .cmd_i(cfe_cmd_i),
    .input_base_i(input_base_i),
    .weight_base_i(weight_base_i),
    .work_base_i(work_base_i),
    .output_base_i(output_base_i),
    .kv_base_i(kv_base_i),
    .param_l1_base_i(param_l1_base_i),
    .valid_o(inline_desc_valid),
    .engine_o(inline_engine),
    .opcode_o(inline_opcode),
    .desc_flat_o()
  );

  /*
   * Task selection writes a narrow snapshot first.  One shared decoder then
   * expands that snapshot and writes the selected engine's dispatch register.
   * Engine work lasts many cycles, so serializing this expansion removes four
   * wide decoder cones without constraining concurrent engine execution.
   */
  npu_inline_desc_decode u_task_desc_decode (
    .cmd_i(decode_pending_cmd_q),
    .input_base_i(decode_pending_input_base_q),
    .weight_base_i(decode_pending_weight_base_q),
    .work_base_i(decode_pending_work_base_q),
    .output_base_i(decode_pending_output_base_q),
    .kv_base_i(decode_pending_kv_base_q),
    .param_l1_base_i(decode_pending_param_l1_base_q),
    .valid_o(),
    .engine_o(),
    .opcode_o(),
    .desc_flat_o(decode_pending_desc_flat)
  );
  /* verilator lint_on PINCONNECTEMPTY */

  function automatic logic terminal_state(input logic [3:0] state);
    return (state == NPU_TASK_SUCCESS) || (state == NPU_TASK_ERROR);
  endfunction

  function automatic logic event_has_live_waiter(
    input logic [11:0] event_ref
  );
    logic found;
    begin
      found = 1'b0;
      if (event_ref != NPU_EVENT_NONE) begin
        for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
          if ((task_state_q[slot] != NPU_TASK_FREE) &&
              !terminal_state(task_state_q[slot]) &&
              ((task_wait0_q[slot] == event_ref) ||
               ((task_wait1_q[slot] == event_ref) &&
                (task_wait1_q[slot] != task_wait0_q[slot])))) begin
            found = 1'b1;
          end
        end
      end
      return found;
    end
  endfunction

  function automatic logic [3:0] software_task_state(input logic [3:0] state);
    if (state == NPU_TASK_FREE) begin
      return 4'd0;
    end
    if (state == NPU_TASK_RUNNING) begin
      return 4'd2;
    end
    if (terminal_state(state)) begin
      return 4'd3;
    end
    return 4'd1;
  endfunction

  function automatic logic task_status_valid(input logic [7:0] status);
    return status <= NPU_STATUS_ADDR_OVERLAP;
  endfunction

  function automatic logic [31:0] make_error_info(
    input logic [3:0] stage,
    input logic [7:0] status,
    input logic [7:0] opcode
  );
    return {stage, 4'd0, status, 8'hff, opcode};
  endfunction

  function automatic logic engine_mask_selected(
    input logic [3:0] engine,
    input logic [3:0] engine_mask
  );
    unique case (engine)
      NPU_ENGINE_DMA:     return engine_mask[0];
      NPU_ENGINE_MATRIX:  return engine_mask[1];
      NPU_ENGINE_VECTOR:  return engine_mask[2];
      NPU_ENGINE_COMPLEX: return engine_mask[3];
      default:            return 1'b0;
    endcase
  endfunction

  function automatic logic dispatch_engine_available(
    input logic [3:0] engine
  );
    unique case (engine)
      NPU_ENGINE_DMA:
        return !dma_active_q && !dma_dispatch_valid_q;
      NPU_ENGINE_MATRIX:
        return !matrix_active_q && !matrix_dispatch_valid_q;
      NPU_ENGINE_VECTOR:
        return !vector_active_q && !vector_dispatch_valid_q;
      NPU_ENGINE_COMPLEX:
        return !complex_active_q && !complex_dispatch_valid_q;
      default:
        return 1'b0;
    endcase
  endfunction

  function automatic logic event_is_success(input logic [11:0] event_ref);
    if (event_ref == NPU_EVENT_NONE) begin
      return 1'b1;
    end
    if (event_ref[7:0] >= 8'(EVENT_COUNT)) begin
      return 1'b0;
    end
    return (event_generation_q[event_ref[7:0]] == event_ref[11:8])
        && (event_state_q[event_ref[7:0]] == NPU_EVENT_SUCCESS);
  endfunction

  function automatic logic event_is_failed(input logic [11:0] event_ref);
    if (event_ref == NPU_EVENT_NONE) begin
      return 1'b0;
    end
    if (event_ref[7:0] >= 8'(EVENT_COUNT)) begin
      return 1'b1;
    end
    if (event_generation_q[event_ref[7:0]] != event_ref[11:8]) begin
      return 1'b1;
    end
    return (event_state_q[event_ref[7:0]] == NPU_EVENT_FREE)
        || (event_state_q[event_ref[7:0]] == NPU_EVENT_ERROR);
  endfunction

  always_comb begin
    free_found = 1'b0;
    free_slot  = '0;
    for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
      if (!free_found && (task_state_q[slot] == NPU_TASK_FREE)) begin
        free_found = 1'b1;
        free_slot  = TASK_IDX_W'(slot);
      end
    end
  end

  always_comb begin
    event_query_ref_valid = 1'b0;
    event_query_found_o = 1'b0;
    event_query_state_o = NPU_EVENT_FREE;
    event_query_producer_command_id_o = 12'd0;
    if ((event_query_ref_i != NPU_EVENT_NONE)
        && (event_query_ref_i[7:0] < 8'(EVENT_COUNT))) begin
      event_query_ref_valid =
        event_generation_q[event_query_ref_i[7:0]] ==
        event_query_ref_i[11:8];
      if (event_query_valid_i && event_query_ref_valid
          && (event_state_q[event_query_ref_i[7:0]] != NPU_EVENT_FREE)) begin
        event_query_found_o = 1'b1;
        event_query_state_o = event_state_q[event_query_ref_i[7:0]];
        event_query_producer_command_id_o =
          event_producer_q[event_query_ref_i[7:0]];
      end
    end
  end

  always_comb begin
    ctl_wait_event_found    = 1'b0;
    ctl_wait_event_terminal = 1'b0;
    ctl_wait_event_state    = NPU_EVENT_FREE;
    ctl_wait_event_producer = 12'd0;
    if ((ctl_arg0_q != NPU_EVENT_NONE)
        && (ctl_arg0_q[7:0] < 8'(EVENT_COUNT))
        && (event_generation_q[ctl_arg0_q[7:0]] == ctl_arg0_q[11:8])
        && (event_state_q[ctl_arg0_q[7:0]] != NPU_EVENT_FREE)) begin
      ctl_wait_event_found = 1'b1;
      ctl_wait_event_state = event_state_q[ctl_arg0_q[7:0]];
      ctl_wait_event_terminal =
        (event_state_q[ctl_arg0_q[7:0]] == NPU_EVENT_SUCCESS)
        || (event_state_q[ctl_arg0_q[7:0]] == NPU_EVENT_ERROR);
      ctl_wait_event_producer = event_producer_q[ctl_arg0_q[7:0]];
    end
  end

  always_comb begin
    ctl_fence_accept_target = '0;
    ctl_fence_accept_status = NPU_STATUS_SUCCESS;
    ctl_fence_accept_failure_seq = 64'hffff_ffff_ffff_ffff;
    for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
      if ((task_state_q[slot] != NPU_TASK_FREE)
          && engine_mask_selected(task_engine_q[slot],
                                  axi_ctl_arg0_i[3:0])) begin
        if (terminal_state(task_state_q[slot])) begin
          if ((task_status_q[slot] != NPU_STATUS_SUCCESS)
              && (task_submit_seq_q[slot] <
                  ctl_fence_accept_failure_seq)) begin
            ctl_fence_accept_status = task_status_q[slot];
            ctl_fence_accept_failure_seq = task_submit_seq_q[slot];
          end
        end else begin
          ctl_fence_accept_target[slot] = 1'b1;
        end
      end
    end
  end

  always_comb begin
    ctl_fence_pending       = 1'b0;
    ctl_fence_result_status = ctl_fence_status_q;
    ctl_fence_result_seq    = ctl_fence_failure_seq_q;
    for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
      if (ctl_fence_target_q[slot]
          && (task_state_q[slot] != NPU_TASK_FREE)
          && (task_submit_seq_q[slot] ==
              ctl_fence_target_seq_q[slot])) begin
        if (!terminal_state(task_state_q[slot])) begin
          ctl_fence_pending = 1'b1;
        end else if ((task_status_q[slot] != NPU_STATUS_SUCCESS)
                     && (task_submit_seq_q[slot] <
                         ctl_fence_result_seq)) begin
          ctl_fence_result_status = task_status_q[slot];
          ctl_fence_result_seq    = task_submit_seq_q[slot];
        end
      end
    end
  end

  assign cmd_static_valid =
    event_resources_valid && inline_desc_valid;

  always_comb begin
    lookup_busy_comb = 1'b0;
    for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
      if ((task_state_q[slot] != NPU_TASK_FREE) &&
          (task_command_id_q[slot] == {2'd0, cmd_id_lookup_id_i})) begin
        lookup_busy_comb = 1'b1;
      end
    end
  end

  always_comb begin
    cmd_wait0_resolved = cmd_wait0;
    cmd_wait1_resolved = cmd_wait1;
    cmd_signal_resolved = cmd_signal;
    if ((cmd_wait0 != NPU_EVENT_NONE) &&
        (cmd_wait0[7:0] < 8'(EVENT_COUNT))) begin
      cmd_wait0_resolved =
        {event_generation_q[cmd_wait0[7:0]], cmd_wait0[7:0]};
    end
    if ((cmd_wait1 != NPU_EVENT_NONE) &&
        (cmd_wait1[7:0] < 8'(EVENT_COUNT))) begin
      cmd_wait1_resolved =
        {event_generation_q[cmd_wait1[7:0]], cmd_wait1[7:0]};
    end
    if ((cmd_signal != NPU_EVENT_NONE) &&
        (cmd_signal[7:0] < 8'(EVENT_COUNT))) begin
      cmd_signal_resolved =
        {event_generation_q[cmd_signal[7:0]], cmd_signal[7:0]};
    end

    event_resources_valid = 1'b1;
    if (cmd_wait0 != NPU_EVENT_NONE) begin
      if ((cmd_wait0[7:0] >= 8'(EVENT_COUNT)) ||
          (event_state_q[cmd_wait0[7:0]] == NPU_EVENT_FREE)) begin
        event_resources_valid = 1'b0;
      end
    end
    if (cmd_wait1 != NPU_EVENT_NONE) begin
      if ((cmd_wait1[7:0] >= 8'(EVENT_COUNT)) ||
          (event_state_q[cmd_wait1[7:0]] == NPU_EVENT_FREE)) begin
        event_resources_valid = 1'b0;
      end
    end

    if (cmd_is_inline_rearm) begin
      if ((cmd_wait0 != NPU_EVENT_NONE) ||
          (cmd_wait1 != NPU_EVENT_NONE) ||
          (cmd_signal == NPU_EVENT_NONE) ||
          (cmd_signal[7:0] >= 8'(EVENT_COUNT)) ||
          !((event_state_q[cmd_signal[7:0]] == NPU_EVENT_SUCCESS) ||
            (event_state_q[cmd_signal[7:0]] == NPU_EVENT_ERROR)) ||
          event_has_live_waiter(cmd_signal_resolved)) begin
        event_resources_valid = 1'b0;
      end
    end else if (cmd_signal != NPU_EVENT_NONE) begin
      if ((cmd_signal[7:0] >= 8'(EVENT_COUNT)) ||
          (event_state_q[cmd_signal[7:0]] != NPU_EVENT_FREE) ||
          event_has_live_waiter(cmd_signal_resolved) ||
          (cmd_signal_resolved == cmd_wait0_resolved) ||
          (cmd_signal_resolved == cmd_wait1_resolved)) begin
        event_resources_valid = 1'b0;
      end
    end
  end

  assign control_rearm_current_ref = task_signal_q[control_select];
  assign control_rearm_next_generation =
    task_signal_q[control_select][11:8] + 1'b1;

  always_comb begin
    for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
      if ((task_engine_q[slot] == NPU_ENGINE_CONTROL) &&
          (task_opcode_q[slot] == NPU_OPCODE_EVENT_JOIN) &&
          task_cmd_q[slot][75]) begin
        dependency_success[slot] =
          event_is_success(task_wait0_q[slot])
          || event_is_success(task_wait1_q[slot]);
        dependency_failed[slot] =
          event_is_failed(task_wait0_q[slot])
          && event_is_failed(task_wait1_q[slot]);
      end else begin
        dependency_success[slot] =
          event_is_success(task_wait0_q[slot])
          && event_is_success(task_wait1_q[slot]);
        dependency_failed[slot] =
          event_is_failed(task_wait0_q[slot])
          || event_is_failed(task_wait1_q[slot]);
      end
      order_blocked[slot] = 1'b0;
      if (task_header_flags_q[slot][4]) begin
        for (int unsigned prior = 0; prior < TASK_SLOTS; prior++) begin
          if ((task_state_q[prior] != NPU_TASK_FREE) &&
              (task_submit_seq_q[prior] < task_submit_seq_q[slot]) &&
              !terminal_state(task_state_q[prior])) begin
            order_blocked[slot] = 1'b1;
          end
        end
      end
      if ((task_engine_q[slot] == NPU_ENGINE_CONTROL) &&
          (task_opcode_q[slot] == NPU_OPCODE_GLOBAL_FENCE)) begin
        for (int unsigned prior = 0; prior < TASK_SLOTS; prior++) begin
          if ((task_state_q[prior] != NPU_TASK_FREE) &&
              (task_submit_seq_q[prior] < task_submit_seq_q[slot]) &&
              engine_mask_selected(
                task_engine_q[prior], task_cmd_q[slot][79:76]
              ) &&
              !terminal_state(task_state_q[prior])) begin
            order_blocked[slot] = 1'b1;
          end
        end
      end
      for (int unsigned barrier = 0;
           barrier < TASK_SLOTS; barrier++) begin
        if ((task_state_q[barrier] != NPU_TASK_FREE)
            && task_header_flags_q[barrier][4]
            && (task_submit_seq_q[barrier] < task_submit_seq_q[slot])
            && !terminal_state(task_state_q[barrier])) begin
          order_blocked[slot] = 1'b1;
        end
      end
    end
  end

  /*
   * Non-control tasks use a registered slot scan.  One slot is inspected per
   * cycle, and only the smallest submit sequence seen during the scan is
   * retained.  The final cycle compares the last slot with the saved
   * candidate and snapshots the winning task for the shared decoder.
   */
  always_comb begin
    decode_scan_current_engine =
      task_engine_q[decode_scan_slot_q];
    decode_scan_current_eligible =
      (task_state_q[decode_scan_slot_q] == NPU_TASK_READY) &&
      !order_blocked[decode_scan_slot_q] &&
      dispatch_engine_available(decode_scan_current_engine);

    decode_scan_best_eligible =
      decode_scan_best_valid_q &&
      (task_state_q[decode_scan_best_slot_q] == NPU_TASK_READY) &&
      !order_blocked[decode_scan_best_slot_q] &&
      dispatch_engine_available(task_engine_q[decode_scan_best_slot_q]);

    decode_scan_winner_valid  = decode_scan_best_eligible;
    decode_scan_winner_slot   = decode_scan_best_slot_q;
    decode_scan_winner_engine =
      task_engine_q[decode_scan_best_slot_q];
    if (decode_scan_current_eligible &&
        (!decode_scan_winner_valid ||
         (task_submit_seq_q[decode_scan_slot_q] <
          decode_scan_best_seq_q))) begin
      decode_scan_winner_valid  = 1'b1;
      decode_scan_winner_slot   = decode_scan_slot_q;
      decode_scan_winner_engine = decode_scan_current_engine;
    end

    decode_pending_task_valid =
      (task_state_q[decode_pending_slot_q] == NPU_TASK_READY) &&
      (task_engine_q[decode_pending_slot_q] ==
       decode_pending_engine_q) &&
      !order_blocked[decode_pending_slot_q];
  end

  always_comb begin
    completion_found    = 1'b0;
    completion_select   = '0;
    event_publish_found = 1'b0;
    event_publish_select = '0;
    control_select_found = 1'b0;
    control_select      = '0;

    for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
      if (task_notify_q[slot] &&
          (!completion_found ||
           (task_submit_seq_q[slot] <
            task_submit_seq_q[completion_select]))) begin
        completion_found  = 1'b1;
        completion_select = TASK_IDX_W'(slot);
      end
      if (task_notify_q[slot] && !task_event_published_q[slot] &&
          !(event_publish_pending_valid_q &&
            (event_publish_pending_slot_q == TASK_IDX_W'(slot))) &&
          (task_signal_q[slot] != NPU_EVENT_NONE) &&
          !((task_engine_q[slot] == NPU_ENGINE_CONTROL) &&
            (task_opcode_q[slot] == NPU_OPCODE_EVENT_REARM)) &&
          (!event_publish_found ||
           (task_submit_seq_q[slot] <
            task_submit_seq_q[event_publish_select]))) begin
        event_publish_found  = 1'b1;
        event_publish_select = TASK_IDX_W'(slot);
      end
      if ((task_state_q[slot] == NPU_TASK_READY) && !order_blocked[slot]) begin
        if (task_engine_q[slot] == NPU_ENGINE_CONTROL) begin
          if (!control_select_found ||
              (task_submit_seq_q[slot] <
               task_submit_seq_q[control_select])) begin
            control_select_found = 1'b1;
            control_select       = TASK_IDX_W'(slot);
          end
        end
      end
    end
  end

  always_comb begin
    query_found  = 1'b0;
    query_select = '0;
    ctl_query_found  = 1'b0;
    ctl_query_select = '0;
    ack_found    = 1'b0;
    ack_select   = '0;
    for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
      if ((task_state_q[slot] != NPU_TASK_FREE) &&
          (task_command_id_q[slot] == task_query_command_id_i)) begin
        query_found  = 1'b1;
        query_select = TASK_IDX_W'(slot);
      end
      if ((task_state_q[slot] != NPU_TASK_FREE) &&
          (task_command_id_q[slot] == axi_ctl_arg0_i[11:0])) begin
        ctl_query_found  = 1'b1;
        ctl_query_select = TASK_IDX_W'(slot);
      end
      if (terminal_state(task_state_q[slot]) && !task_notify_q[slot] &&
          (task_command_id_q[slot] == task_ack_command_id_i)) begin
        ack_found  = 1'b1;
        ack_select = TASK_IDX_W'(slot);
      end
    end
  end

  assign cfe_cmd_ready_o = enable_i && !quiesce_i && free_found;
  assign cmd_accept      = cfe_cmd_valid_i && cfe_cmd_ready_o;

  assign cmd_id_lookup_ready_o = 1'b1;
  assign cmd_id_busy_o          = lookup_busy_q;

  assign dma_task_valid_o       = dma_dispatch_valid_q && !abort_i;
  assign dma_task_opcode_o      = dma_dispatch_opcode_q;
  assign dma_task_command_id_o  = dma_dispatch_command_id_q;
  assign dma_task_desc_flat_o   = dma_dispatch_desc_q;
  assign dma_done_ready_o       = dma_active_q;

  assign matrix_task_valid_o      = matrix_dispatch_valid_q && !abort_i;
  assign matrix_task_opcode_o     = matrix_dispatch_opcode_q;
  assign matrix_task_command_id_o = matrix_dispatch_command_id_q;
  assign matrix_task_desc_flat_o  = matrix_dispatch_desc_q;
  assign matrix_done_ready_o      = matrix_active_q;

  assign vector_task_valid_o      = vector_dispatch_valid_q && !abort_i;
  assign vector_task_opcode_o     = vector_dispatch_opcode_q;
  assign vector_task_command_id_o = vector_dispatch_command_id_q;
  assign vector_task_desc_flat_o  = vector_dispatch_desc_q;
  assign vector_done_ready_o      = vector_active_q;

  assign complex_task_valid_o      = complex_dispatch_valid_q && !abort_i;
  assign complex_task_opcode_o     = complex_dispatch_opcode_q;
  assign complex_task_command_id_o = complex_dispatch_command_id_q;
  assign complex_task_desc_flat_o  = complex_dispatch_desc_q;
  assign complex_done_ready_o      = complex_active_q;

  assign completion_valid_o       = completion_hold_valid_q;
  assign completion_command_id_o  =
    task_command_id_q[completion_hold_slot_q];
  assign completion_engine_o      = task_engine_q[completion_hold_slot_q];
  assign completion_opcode_o      = task_opcode_q[completion_hold_slot_q];
  assign completion_status_o      = task_status_q[completion_hold_slot_q];
  assign completion_fault_addr_o  =
    task_fault_addr_q[completion_hold_slot_q];
  assign completion_progress_o    =
    task_progress_q[completion_hold_slot_q];
  assign completion_irq_success_o =
    task_header_flags_q[completion_hold_slot_q][0] &&
    (task_status_q[completion_hold_slot_q] == NPU_STATUS_SUCCESS);
  assign completion_irq_error_o =
    task_header_flags_q[completion_hold_slot_q][1] &&
    (task_status_q[completion_hold_slot_q] != NPU_STATUS_SUCCESS);

  assign axi_ctl_ready_o    = !ctl_active_q && !ctl_rsp_valid_q;
  assign axi_ctl_rsp_valid_o = ctl_rsp_valid_q;
  assign axi_ctl_rsp_data_o  = ctl_rsp_data_q;

  assign task_query_found_o      = task_query_valid_i && query_found;
  assign task_query_state_o      = software_task_state(task_state_q[query_select]);
  assign task_query_status_o     = task_status_q[query_select];
  assign task_query_fault_addr_o = task_fault_addr_q[query_select];
  assign task_query_progress_o   = task_progress_q[query_select];
  assign task_query_user_tag_o   = {
    22'd0, task_cmd_q[query_select][121:112]
  };
  assign task_query_signal_event_o = task_signal_q[query_select];
  assign task_query_error_info_o = task_error_info_q[query_select];
  assign task_query_done_flags_o = task_done_flags_q[query_select];
  assign task_ack_ready_o        = ack_found;

  always_comb begin
    task_occupancy_o = 16'd0;
    for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
      if (task_state_q[slot] != NPU_TASK_FREE) begin
        task_occupancy_o = task_occupancy_o + 1'b1;
      end
    end
  end
  assign scheduler_idle_o = (task_occupancy_o == 0)
                          && !dma_active_q
                          && !matrix_active_q
                          && !vector_active_q
                          && !complex_active_q;

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      submit_seq_q               <= 64'd0;
      dma_active_q               <= 1'b0;
      matrix_active_q            <= 1'b0;
      vector_active_q            <= 1'b0;
      complex_active_q           <= 1'b0;
      dma_active_slot_q          <= '0;
      matrix_active_slot_q       <= '0;
      vector_active_slot_q       <= '0;
      complex_active_slot_q      <= '0;
      dma_dispatch_valid_q       <= 1'b0;
      matrix_dispatch_valid_q    <= 1'b0;
      vector_dispatch_valid_q    <= 1'b0;
      complex_dispatch_valid_q   <= 1'b0;
      decode_pending_valid_q     <= 1'b0;
      decode_scan_active_q       <= 1'b0;
      decode_scan_slot_q         <= '0;
      decode_scan_best_valid_q   <= 1'b0;
      decode_scan_best_slot_q    <= '0;
      decode_scan_best_seq_q     <= 64'd0;
      completion_hold_valid_q    <= 1'b0;
      completion_hold_slot_q     <= '0;
      event_publish_pending_valid_q <= 1'b0;
      event_publish_pending_slot_q  <= '0;
      dma_dispatch_slot_q        <= '0;
      matrix_dispatch_slot_q     <= '0;
      vector_dispatch_slot_q     <= '0;
      complex_dispatch_slot_q    <= '0;
      dma_dispatch_opcode_q      <= 8'd0;
      matrix_dispatch_opcode_q   <= 8'd0;
      vector_dispatch_opcode_q   <= 8'd0;
      complex_dispatch_opcode_q  <= 8'd0;
      dma_dispatch_command_id_q     <= 12'd0;
      matrix_dispatch_command_id_q  <= 12'd0;
      vector_dispatch_command_id_q  <= 12'd0;
      complex_dispatch_command_id_q <= 12'd0;
      cmd_id_lookup_rsp_valid_o  <= 1'b0;
      lookup_busy_q              <= 1'b0;
      ctl_active_q               <= 1'b0;
      ctl_op_q                   <= 2'd0;
      ctl_arg0_q                 <= 12'd0;
      ctl_arg1_q                 <= 32'd0;
      ctl_wait_count_q           <= 32'd0;
      ctl_rsp_valid_q            <= 1'b0;
      ctl_rsp_data_q             <= 64'd0;
      ctl_ack_release_q          <= 1'b0;
      ctl_ack_slot_q             <= '0;
      ctl_fence_target_q         <= '0;
      ctl_fence_status_q         <= NPU_STATUS_SUCCESS;
      ctl_fence_failure_seq_q    <= 64'hffff_ffff_ffff_ffff;
      for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
        task_state_q[slot]        <= NPU_TASK_FREE;
        task_command_id_q[slot]   <= 12'd0;
        task_engine_q[slot]       <= 4'd0;
        task_opcode_q[slot]       <= 8'd0;
        task_header_flags_q[slot] <= 12'd0;
        task_wait0_q[slot]        <= NPU_EVENT_NONE;
        task_wait1_q[slot]        <= NPU_EVENT_NONE;
        task_signal_q[slot]       <= NPU_EVENT_NONE;
        task_submit_seq_q[slot]   <= 64'd0;
        task_status_q[slot]       <= NPU_STATUS_SUCCESS;
        task_fault_addr_q[slot]   <= 48'd0;
        task_progress_q[slot]     <= 64'd0;
        task_error_info_q[slot]   <= 32'd0;
        task_done_flags_q[slot]   <= 16'd0;
        task_notify_q[slot]       <= 1'b0;
        task_event_published_q[slot] <= 1'b0;
        ctl_fence_target_seq_q[slot] <= 64'd0;
      end
      for (int unsigned event_idx = 0;
           event_idx < EVENT_COUNT; event_idx++) begin
        event_state_q[event_idx]      <= NPU_EVENT_FREE;
        event_generation_q[event_idx] <= 4'd0;
        event_producer_q[event_idx]   <= 12'd0;
      end
    end else begin
      cmd_id_lookup_rsp_valid_o <= cmd_id_lookup_valid_i
                                && cmd_id_lookup_ready_o;
      if (cmd_id_lookup_valid_i && cmd_id_lookup_ready_o) begin
        lookup_busy_q <= lookup_busy_comb;
      end

      if (ctl_rsp_valid_q && axi_ctl_rsp_ready_i) begin
        ctl_rsp_valid_q <= 1'b0;
        if (ctl_ack_release_q) begin
          task_state_q[ctl_ack_slot_q]      <= NPU_TASK_FREE;
          task_notify_q[ctl_ack_slot_q]     <= 1'b0;
          task_progress_q[ctl_ack_slot_q]   <= 64'd0;
          task_error_info_q[ctl_ack_slot_q] <= 32'd0;
          task_done_flags_q[ctl_ack_slot_q] <= 16'd0;
          task_event_published_q[ctl_ack_slot_q] <= 1'b0;
          ctl_ack_release_q                 <= 1'b0;
        end
      end

      if (axi_ctl_valid_i && axi_ctl_ready_o) begin
        ctl_op_q                <= axi_ctl_op_i;
        ctl_arg0_q              <= axi_ctl_arg0_i[11:0];
        ctl_arg1_q              <= axi_ctl_arg1_i[31:0];
        ctl_wait_count_q        <= 32'd0;
        ctl_ack_release_q       <= 1'b0;
        ctl_fence_target_q      <= '0;
        ctl_fence_status_q      <= NPU_STATUS_SUCCESS;
        ctl_fence_failure_seq_q <= 64'hffff_ffff_ffff_ffff;

        unique case (axi_ctl_op_i)
          NPU_CTL_QUERY: begin
            ctl_rsp_valid_q <= 1'b1;
            if ((|axi_ctl_arg0_i[63:10])
                || (|axi_ctl_arg1_i[63:3])
                || (axi_ctl_arg1_i[2:0] == 3'd7)) begin
              ctl_rsp_data_q <= {56'd0, NPU_STATUS_BAD_DESC};
            end else begin
              unique case (axi_ctl_arg1_i[2:0])
                3'd0: begin
                  ctl_rsp_data_q <= ctl_query_found
                    ? {40'd0,
                       task_command_id_q[ctl_query_select],
                       task_status_q[ctl_query_select],
                       software_task_state(task_state_q[ctl_query_select])}
                    : {40'd0, axi_ctl_arg0_i[11:0],
                       NPU_STATUS_NOT_FOUND, 4'd0};
                end
                3'd1: begin
                  ctl_rsp_data_q <= ctl_query_found
                    ? {20'd0, task_signal_q[ctl_query_select],
                       22'd0,
                       task_cmd_q[ctl_query_select][121:112]}
                    : 64'd0;
                end
                3'd2: begin
                  ctl_rsp_data_q <= ctl_query_found
                    ? {16'd0, task_fault_addr_q[ctl_query_select]}
                    : 64'd0;
                end
                3'd3: begin
                  ctl_rsp_data_q <= ctl_query_found
                    ? task_progress_q[ctl_query_select] : 64'd0;
                end
                3'd4: begin
                  if (!ctl_query_found) begin
                    ctl_rsp_data_q <= 64'd2;
                  end else if (!terminal_state(
                               task_state_q[ctl_query_select])
                               || task_notify_q[ctl_query_select]) begin
                    ctl_rsp_data_q <= 64'd1;
                  end else begin
                    ctl_rsp_data_q    <= 64'd0;
                    ctl_ack_release_q <= 1'b1;
                    ctl_ack_slot_q    <= ctl_query_select;
                  end
                end
                3'd5: begin
                  ctl_rsp_data_q <= ctl_query_found
                    ? {32'd0, task_error_info_q[ctl_query_select]}
                    : 64'd0;
                end
                3'd6: begin
                  ctl_rsp_data_q <= ctl_query_found
                    ? {48'd0, task_done_flags_q[ctl_query_select]}
                    : 64'd0;
                end
                default: ctl_rsp_data_q <= {56'd0, NPU_STATUS_BAD_DESC};
              endcase
            end
          end

          NPU_CTL_WAIT: begin
            if ((|axi_ctl_arg0_i[63:8])
                || (|axi_ctl_arg1_i[63:32])
                || (axi_ctl_arg0_i[7:0] == 8'hff)
                || (axi_ctl_arg0_i[7:0] >= 8'(EVENT_COUNT))) begin
              ctl_rsp_data_q  <= {56'd0, NPU_STATUS_BAD_DESC};
              ctl_rsp_valid_q <= 1'b1;
            end else if (event_state_q[axi_ctl_arg0_i[7:0]] ==
                         NPU_EVENT_FREE) begin
              ctl_rsp_data_q  <= {56'd0, NPU_STATUS_NOT_FOUND};
              ctl_rsp_valid_q <= 1'b1;
            end else if ((event_state_q[axi_ctl_arg0_i[7:0]] ==
                          NPU_EVENT_SUCCESS)
                         || (event_state_q[axi_ctl_arg0_i[7:0]] ==
                             NPU_EVENT_ERROR)) begin
              ctl_rsp_data_q <= {
                44'd0,
                event_producer_q[axi_ctl_arg0_i[7:0]],
                5'd0,
                event_state_q[axi_ctl_arg0_i[7:0]]
              };
              ctl_rsp_valid_q <= 1'b1;
            end else if (axi_ctl_arg1_i[31:0] == 32'd0) begin
              ctl_rsp_data_q  <= {56'd0, NPU_STATUS_TIMEOUT};
              ctl_rsp_valid_q <= 1'b1;
            end else begin
              ctl_arg0_q <= {
                event_generation_q[axi_ctl_arg0_i[7:0]],
                axi_ctl_arg0_i[7:0]
              };
              ctl_active_q <= 1'b1;
            end
          end

          NPU_CTL_FENCE: begin
            if ((|axi_ctl_arg0_i[63:4])
                || (|axi_ctl_arg1_i[63:32])) begin
              ctl_rsp_data_q  <= {56'd0, NPU_STATUS_BAD_DESC};
              ctl_rsp_valid_q <= 1'b1;
            end else begin
              ctl_fence_target_q      <= ctl_fence_accept_target;
              ctl_fence_status_q      <= ctl_fence_accept_status;
              ctl_fence_failure_seq_q <= ctl_fence_accept_failure_seq;
              for (int unsigned slot = 0;
                   slot < TASK_SLOTS; slot++) begin
                ctl_fence_target_seq_q[slot] <= task_submit_seq_q[slot];
              end
              ctl_active_q <= 1'b1;
            end
          end

          default: begin
            ctl_rsp_data_q  <= {56'd0, NPU_STATUS_BAD_DESC};
            ctl_rsp_valid_q <= 1'b1;
          end
        endcase
      end

      if (ctl_active_q) begin
        if (axi_ctl_cancel_i
            && ((ctl_op_q == NPU_CTL_WAIT)
                || (ctl_op_q == NPU_CTL_FENCE))) begin
          ctl_active_q          <= 1'b0;
          ctl_fence_target_q    <= '0;
          ctl_wait_count_q      <= 32'd0;
        end else if (ctl_op_q == NPU_CTL_WAIT) begin
          if (!ctl_wait_event_found) begin
            ctl_rsp_data_q  <= {56'd0, NPU_STATUS_NOT_FOUND};
            ctl_rsp_valid_q <= 1'b1;
            ctl_active_q    <= 1'b0;
          end else if (ctl_wait_event_terminal) begin
            ctl_rsp_data_q <= {
              44'd0,
              ctl_wait_event_producer,
              5'd0,
              ctl_wait_event_state
            };
            ctl_rsp_valid_q <= 1'b1;
            ctl_active_q    <= 1'b0;
          end else if (ctl_wait_count_q >= ctl_arg1_q) begin
            ctl_rsp_data_q  <= {56'd0, NPU_STATUS_TIMEOUT};
            ctl_rsp_valid_q <= 1'b1;
            ctl_active_q    <= 1'b0;
          end else begin
            ctl_wait_count_q <= ctl_wait_count_q + 1'b1;
          end
        end else if (ctl_op_q == NPU_CTL_FENCE) begin
          ctl_fence_status_q      <= ctl_fence_result_status;
          ctl_fence_failure_seq_q <= ctl_fence_result_seq;
          for (int unsigned slot = 0;
               slot < TASK_SLOTS; slot++) begin
            if (ctl_fence_target_q[slot]
                && ((task_state_q[slot] == NPU_TASK_FREE)
                    || (task_submit_seq_q[slot] !=
                        ctl_fence_target_seq_q[slot])
                    || terminal_state(task_state_q[slot]))) begin
              ctl_fence_target_q[slot] <= 1'b0;
            end
          end
          if (!ctl_fence_pending) begin
            ctl_rsp_data_q  <= {56'd0, ctl_fence_result_status};
            ctl_rsp_valid_q <= 1'b1;
            ctl_active_q    <= 1'b0;
          end else if (ctl_wait_count_q >= ctl_arg1_q) begin
            ctl_rsp_data_q  <= {56'd0, NPU_STATUS_TIMEOUT};
            ctl_rsp_valid_q <= 1'b1;
            ctl_active_q    <= 1'b0;
          end else begin
            ctl_wait_count_q <= ctl_wait_count_q + 1'b1;
          end
        end else begin
          ctl_rsp_data_q  <= {56'd0, NPU_STATUS_BAD_DESC};
          ctl_rsp_valid_q <= 1'b1;
          ctl_active_q    <= 1'b0;
        end
      end

      if (cmd_accept) begin
        task_state_q[free_slot]        <= cmd_static_valid
                                        ? NPU_TASK_WAIT_EVENT
                                        : NPU_TASK_ERROR;
        task_command_id_q[free_slot]   <= cmd_command_id;
        task_engine_q[free_slot]       <= cmd_engine;
        task_opcode_q[free_slot]       <= cmd_opcode;
        task_header_flags_q[free_slot] <= cmd_header_flags;
        task_wait0_q[free_slot]        <= cmd_wait0_resolved;
        task_wait1_q[free_slot]        <= cmd_wait1_resolved;
        task_signal_q[free_slot]       <= cmd_static_valid
                                        ? cmd_signal_resolved
                                        : NPU_EVENT_NONE;
        task_submit_seq_q[free_slot]   <= submit_seq_q;
        task_cmd_q[free_slot]           <= cfe_cmd_i;
        task_input_base_q[free_slot]    <= input_base_i;
        task_weight_base_q[free_slot]   <= weight_base_i;
        task_work_base_q[free_slot]     <= work_base_i;
        task_output_base_q[free_slot]   <= output_base_i;
        task_kv_base_q[free_slot]       <= kv_base_i;
        task_param_l1_base_q[free_slot] <= param_l1_base_i;
        task_status_q[free_slot]       <= cmd_static_valid
                                        ? NPU_STATUS_SUCCESS
                                        : NPU_STATUS_BAD_DESC;
        task_fault_addr_q[free_slot]   <= 48'd0;
        task_progress_q[free_slot]     <= 64'd0;
        task_error_info_q[free_slot]   <= cmd_static_valid
                                        ? 32'd0
                                        : make_error_info(
                                            4'd6,
                                            NPU_STATUS_BAD_DESC,
                                            cmd_opcode);
        task_done_flags_q[free_slot]   <= 16'd0;
        task_notify_q[free_slot]       <= !cmd_static_valid;
        task_event_published_q[free_slot] <=
          !cmd_static_valid ||
          (cmd_signal_resolved == NPU_EVENT_NONE) ||
          cmd_is_inline_rearm;
        submit_seq_q                   <= submit_seq_q + 1'b1;
        if (cmd_static_valid &&
            (cmd_signal_resolved != NPU_EVENT_NONE) &&
            !cmd_is_inline_rearm) begin
          event_state_q[cmd_signal_resolved[7:0]] <= NPU_EVENT_PENDING;
          event_producer_q[cmd_signal_resolved[7:0]] <= cmd_command_id;
        end
      end

      for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
        if (task_state_q[slot] == NPU_TASK_WAIT_EVENT) begin
          if (dependency_failed[slot]) begin
            task_state_q[slot]      <= NPU_TASK_ERROR;
            task_status_q[slot]     <= NPU_STATUS_DEPENDENCY_FAILED;
            task_fault_addr_q[slot] <= 48'd0;
            task_progress_q[slot]   <= 64'd0;
            task_error_info_q[slot] <= make_error_info(
              4'd6, NPU_STATUS_DEPENDENCY_FAILED, task_opcode_q[slot]);
            task_done_flags_q[slot] <= 16'd0;
            task_notify_q[slot]     <= 1'b1;
          end else if (dependency_success[slot] && !order_blocked[slot]) begin
            task_state_q[slot] <= NPU_TASK_READY;
          end
        end
      end

      if (control_select_found && !abort_i) begin
        task_fault_addr_q[control_select] <= 48'd0;
        task_progress_q[control_select]   <= 64'd0;
        task_done_flags_q[control_select] <= 16'd0;
        task_notify_q[control_select]     <= 1'b1;
        if (task_opcode_q[control_select] == NPU_OPCODE_EVENT_REARM) begin
          if ((control_rearm_current_ref[7:0] < 8'(EVENT_COUNT)) &&
              ((event_state_q[control_rearm_current_ref[7:0]] ==
                NPU_EVENT_SUCCESS) ||
               (event_state_q[control_rearm_current_ref[7:0]] ==
                NPU_EVENT_ERROR)) &&
              (event_generation_q[control_rearm_current_ref[7:0]] ==
               control_rearm_current_ref[11:8]) &&
              !event_has_live_waiter(control_rearm_current_ref) &&
              !(cmd_accept && cmd_static_valid &&
                ((cmd_wait0_resolved == control_rearm_current_ref) ||
                 (cmd_wait1_resolved == control_rearm_current_ref)))) begin
            task_status_q[control_select]     <= NPU_STATUS_SUCCESS;
            task_error_info_q[control_select] <= 32'd0;
            task_state_q[control_select]      <= NPU_TASK_SUCCESS;
            event_state_q[control_rearm_current_ref[7:0]]
              <= NPU_EVENT_FREE;
            event_generation_q[control_rearm_current_ref[7:0]]
              <= control_rearm_next_generation;
            event_producer_q[control_rearm_current_ref[7:0]]
              <= 12'd0;
          end else begin
            task_status_q[control_select] <= NPU_STATUS_BAD_DESC;
            task_error_info_q[control_select] <= make_error_info(
              4'd4, NPU_STATUS_BAD_DESC,
              task_opcode_q[control_select]
            );
            task_state_q[control_select] <= NPU_TASK_ERROR;
          end
        end else begin
          task_status_q[control_select]     <= NPU_STATUS_SUCCESS;
          task_error_info_q[control_select] <= 32'd0;
          task_state_q[control_select]      <= NPU_TASK_SUCCESS;
        end
      end

      if (decode_pending_valid_q && !abort_i) begin
        decode_scan_active_q     <= 1'b0;
        decode_scan_slot_q       <= '0;
        decode_scan_best_valid_q <= 1'b0;
        if (!decode_pending_task_valid) begin
          decode_pending_valid_q <= 1'b0;
        end else begin
          unique case (decode_pending_engine_q)
            NPU_ENGINE_DMA: begin
              if (!dma_active_q && !dma_dispatch_valid_q) begin
                dma_dispatch_valid_q      <= 1'b1;
                dma_dispatch_slot_q       <= decode_pending_slot_q;
                dma_dispatch_opcode_q     <= decode_pending_opcode_q;
                dma_dispatch_command_id_q <= decode_pending_command_id_q;
                dma_dispatch_desc_q       <= decode_pending_desc_flat;
                decode_pending_valid_q    <= 1'b0;
              end
            end
            NPU_ENGINE_MATRIX: begin
              if (!matrix_active_q && !matrix_dispatch_valid_q) begin
                matrix_dispatch_valid_q      <= 1'b1;
                matrix_dispatch_slot_q       <= decode_pending_slot_q;
                matrix_dispatch_opcode_q     <= decode_pending_opcode_q;
                matrix_dispatch_command_id_q <= decode_pending_command_id_q;
                matrix_dispatch_desc_q       <= decode_pending_desc_flat;
                decode_pending_valid_q       <= 1'b0;
              end
            end
            NPU_ENGINE_VECTOR: begin
              if (!vector_active_q && !vector_dispatch_valid_q) begin
                vector_dispatch_valid_q      <= 1'b1;
                vector_dispatch_slot_q       <= decode_pending_slot_q;
                vector_dispatch_opcode_q     <= decode_pending_opcode_q;
                vector_dispatch_command_id_q <= decode_pending_command_id_q;
                vector_dispatch_desc_q       <= decode_pending_desc_flat;
                decode_pending_valid_q       <= 1'b0;
              end
            end
            NPU_ENGINE_COMPLEX: begin
              if (!complex_active_q && !complex_dispatch_valid_q) begin
                complex_dispatch_valid_q      <= 1'b1;
                complex_dispatch_slot_q       <= decode_pending_slot_q;
                complex_dispatch_opcode_q     <= decode_pending_opcode_q;
                complex_dispatch_command_id_q <= decode_pending_command_id_q;
                complex_dispatch_desc_q       <= decode_pending_desc_flat;
                decode_pending_valid_q        <= 1'b0;
              end
            end
            default: decode_pending_valid_q <= 1'b0;
          endcase
        end
      end else if (!abort_i) begin
        if (!decode_scan_active_q) begin
          if (TASK_SLOTS == 1) begin
            if (decode_scan_winner_valid) begin
              decode_pending_valid_q      <= 1'b1;
              decode_pending_engine_q     <= decode_scan_winner_engine;
              decode_pending_slot_q       <= decode_scan_winner_slot;
              decode_pending_opcode_q     <=
                task_opcode_q[decode_scan_winner_slot];
              decode_pending_command_id_q <=
                task_command_id_q[decode_scan_winner_slot];
              decode_pending_cmd_q        <=
                task_cmd_q[decode_scan_winner_slot];
              decode_pending_input_base_q <=
                task_input_base_q[decode_scan_winner_slot];
              decode_pending_weight_base_q <=
                task_weight_base_q[decode_scan_winner_slot];
              decode_pending_work_base_q <=
                task_work_base_q[decode_scan_winner_slot];
              decode_pending_output_base_q <=
                task_output_base_q[decode_scan_winner_slot];
              decode_pending_kv_base_q <=
                task_kv_base_q[decode_scan_winner_slot];
              decode_pending_param_l1_base_q <=
                task_param_l1_base_q[decode_scan_winner_slot];
            end
            decode_scan_slot_q       <= '0;
            decode_scan_best_valid_q <= 1'b0;
          end else begin
            decode_scan_active_q     <= 1'b1;
            decode_scan_slot_q       <= TASK_IDX_W'(1);
            decode_scan_best_valid_q <= decode_scan_current_eligible;
            if (decode_scan_current_eligible) begin
              decode_scan_best_slot_q <= decode_scan_slot_q;
              decode_scan_best_seq_q  <=
                task_submit_seq_q[decode_scan_slot_q];
            end
          end
        end else if (decode_scan_slot_q ==
                     TASK_IDX_W'(TASK_SLOTS - 1)) begin
          if (decode_scan_winner_valid) begin
            decode_pending_valid_q      <= 1'b1;
            decode_pending_engine_q     <= decode_scan_winner_engine;
            decode_pending_slot_q       <= decode_scan_winner_slot;
            decode_pending_opcode_q     <=
              task_opcode_q[decode_scan_winner_slot];
            decode_pending_command_id_q <=
              task_command_id_q[decode_scan_winner_slot];
            decode_pending_cmd_q        <=
              task_cmd_q[decode_scan_winner_slot];
            decode_pending_input_base_q <=
              task_input_base_q[decode_scan_winner_slot];
            decode_pending_weight_base_q <=
              task_weight_base_q[decode_scan_winner_slot];
            decode_pending_work_base_q <=
              task_work_base_q[decode_scan_winner_slot];
            decode_pending_output_base_q <=
              task_output_base_q[decode_scan_winner_slot];
            decode_pending_kv_base_q <=
              task_kv_base_q[decode_scan_winner_slot];
            decode_pending_param_l1_base_q <=
              task_param_l1_base_q[decode_scan_winner_slot];
          end
          decode_scan_active_q     <= 1'b0;
          decode_scan_slot_q       <= '0;
          decode_scan_best_valid_q <= 1'b0;
        end else begin
          decode_scan_slot_q <= decode_scan_slot_q + 1'b1;
          if (!decode_scan_best_eligible) begin
            decode_scan_best_valid_q <= decode_scan_current_eligible;
            if (decode_scan_current_eligible) begin
              decode_scan_best_slot_q <= decode_scan_slot_q;
              decode_scan_best_seq_q  <=
                task_submit_seq_q[decode_scan_slot_q];
            end
          end else if (decode_scan_current_eligible &&
                       (task_submit_seq_q[decode_scan_slot_q] <
                        decode_scan_best_seq_q)) begin
            decode_scan_best_valid_q <= 1'b1;
            decode_scan_best_slot_q  <= decode_scan_slot_q;
            decode_scan_best_seq_q   <=
              task_submit_seq_q[decode_scan_slot_q];
          end
        end
      end

      if (dma_task_valid_o && dma_task_ready_i) begin
        dma_dispatch_valid_q       <= 1'b0;
        dma_active_q              <= 1'b1;
        dma_active_slot_q         <= dma_dispatch_slot_q;
        task_state_q[dma_dispatch_slot_q] <= NPU_TASK_RUNNING;
      end
      if (matrix_task_valid_o && matrix_task_ready_i) begin
        matrix_dispatch_valid_q      <= 1'b0;
        matrix_active_q             <= 1'b1;
        matrix_active_slot_q        <= matrix_dispatch_slot_q;
        task_state_q[matrix_dispatch_slot_q] <= NPU_TASK_RUNNING;
      end
      if (vector_task_valid_o && vector_task_ready_i) begin
        vector_dispatch_valid_q      <= 1'b0;
        vector_active_q             <= 1'b1;
        vector_active_slot_q        <= vector_dispatch_slot_q;
        task_state_q[vector_dispatch_slot_q] <= NPU_TASK_RUNNING;
      end
      if (complex_task_valid_o && complex_task_ready_i) begin
        complex_dispatch_valid_q      <= 1'b0;
        complex_active_q             <= 1'b1;
        complex_active_slot_q        <= complex_dispatch_slot_q;
        task_state_q[complex_dispatch_slot_q] <= NPU_TASK_RUNNING;
      end

      if (dma_done_valid_i && dma_done_ready_o) begin
        dma_active_q <= 1'b0;
        if (!terminal_state(task_state_q[dma_active_slot_q])) begin
        task_status_q[dma_active_slot_q] <=
          ((dma_done_command_id_i == task_command_id_q[dma_active_slot_q])
           && task_status_valid(dma_done_status_i))
          ? dma_done_status_i : NPU_STATUS_BAD_DESC;
        task_fault_addr_q[dma_active_slot_q] <= dma_done_fault_addr_i;
        task_progress_q[dma_active_slot_q] <= dma_done_progress_i;
        task_error_info_q[dma_active_slot_q] <=
          ((dma_done_command_id_i == task_command_id_q[dma_active_slot_q])
           && task_status_valid(dma_done_status_i)
           && (dma_done_status_i == NPU_STATUS_SUCCESS))
          ? 32'd0
          : make_error_info(
              4'd4,
              ((dma_done_command_id_i ==
                task_command_id_q[dma_active_slot_q])
               && task_status_valid(dma_done_status_i))
              ? dma_done_status_i : NPU_STATUS_BAD_DESC,
              task_opcode_q[dma_active_slot_q]);
        task_done_flags_q[dma_active_slot_q] <= 16'd0;
        task_state_q[dma_active_slot_q] <=
          ((dma_done_command_id_i == task_command_id_q[dma_active_slot_q])
           && task_status_valid(dma_done_status_i)
           && (dma_done_status_i == NPU_STATUS_SUCCESS))
          ? NPU_TASK_SUCCESS : NPU_TASK_ERROR;
        task_notify_q[dma_active_slot_q] <= 1'b1;
        end
      end
      if (matrix_done_valid_i && matrix_done_ready_o) begin
        matrix_active_q <= 1'b0;
        if (!terminal_state(task_state_q[matrix_active_slot_q])) begin
        task_status_q[matrix_active_slot_q] <=
          ((matrix_done_command_id_i ==
            task_command_id_q[matrix_active_slot_q])
           && task_status_valid(matrix_done_status_i))
          ? matrix_done_status_i : NPU_STATUS_BAD_DESC;
        task_fault_addr_q[matrix_active_slot_q] <= matrix_done_fault_addr_i;
        task_progress_q[matrix_active_slot_q] <= matrix_done_progress_i;
        task_error_info_q[matrix_active_slot_q] <=
          ((matrix_done_command_id_i ==
            task_command_id_q[matrix_active_slot_q])
           && task_status_valid(matrix_done_status_i)
           && (matrix_done_status_i == NPU_STATUS_SUCCESS))
          ? 32'd0
          : make_error_info(
              4'd4,
              ((matrix_done_command_id_i ==
                task_command_id_q[matrix_active_slot_q])
               && task_status_valid(matrix_done_status_i))
              ? matrix_done_status_i : NPU_STATUS_BAD_DESC,
              task_opcode_q[matrix_active_slot_q]);
        task_done_flags_q[matrix_active_slot_q] <= 16'd0;
        task_state_q[matrix_active_slot_q] <=
          ((matrix_done_command_id_i == task_command_id_q[matrix_active_slot_q])
           && task_status_valid(matrix_done_status_i)
           && (matrix_done_status_i == NPU_STATUS_SUCCESS))
          ? NPU_TASK_SUCCESS : NPU_TASK_ERROR;
        task_notify_q[matrix_active_slot_q] <= 1'b1;
        end
      end
      if (vector_done_valid_i && vector_done_ready_o) begin
        vector_active_q <= 1'b0;
        if (!terminal_state(task_state_q[vector_active_slot_q])) begin
        task_status_q[vector_active_slot_q] <=
          ((vector_done_command_id_i ==
            task_command_id_q[vector_active_slot_q])
           && task_status_valid(vector_done_status_i))
          ? vector_done_status_i : NPU_STATUS_BAD_DESC;
        task_fault_addr_q[vector_active_slot_q] <= vector_done_fault_addr_i;
        task_progress_q[vector_active_slot_q] <= vector_done_progress_i;
        task_error_info_q[vector_active_slot_q] <=
          ((vector_done_command_id_i ==
            task_command_id_q[vector_active_slot_q])
           && task_status_valid(vector_done_status_i)
           && (vector_done_status_i == NPU_STATUS_SUCCESS))
          ? 32'd0
          : make_error_info(
              4'd4,
              ((vector_done_command_id_i ==
                task_command_id_q[vector_active_slot_q])
               && task_status_valid(vector_done_status_i))
              ? vector_done_status_i : NPU_STATUS_BAD_DESC,
              task_opcode_q[vector_active_slot_q]);
        task_done_flags_q[vector_active_slot_q] <= 16'd0;
        task_state_q[vector_active_slot_q] <=
          ((vector_done_command_id_i == task_command_id_q[vector_active_slot_q])
           && task_status_valid(vector_done_status_i)
           && (vector_done_status_i == NPU_STATUS_SUCCESS))
          ? NPU_TASK_SUCCESS : NPU_TASK_ERROR;
        task_notify_q[vector_active_slot_q] <= 1'b1;
        end
      end
      if (complex_done_valid_i && complex_done_ready_o) begin
        complex_active_q <= 1'b0;
        if (!terminal_state(task_state_q[complex_active_slot_q])) begin
        task_status_q[complex_active_slot_q] <=
          ((complex_done_command_id_i ==
            task_command_id_q[complex_active_slot_q])
           && task_status_valid(complex_done_status_i))
          ? complex_done_status_i : NPU_STATUS_BAD_DESC;
        task_fault_addr_q[complex_active_slot_q] <= complex_done_fault_addr_i;
        task_progress_q[complex_active_slot_q] <= complex_done_progress_i;
        task_error_info_q[complex_active_slot_q] <=
          ((complex_done_command_id_i ==
            task_command_id_q[complex_active_slot_q])
           && task_status_valid(complex_done_status_i)
           && (complex_done_status_i == NPU_STATUS_SUCCESS))
          ? 32'd0
          : make_error_info(
              4'd4,
              ((complex_done_command_id_i ==
                task_command_id_q[complex_active_slot_q])
               && task_status_valid(complex_done_status_i))
              ? complex_done_status_i : NPU_STATUS_BAD_DESC,
              task_opcode_q[complex_active_slot_q]);
        task_done_flags_q[complex_active_slot_q] <= 16'd0;
        task_state_q[complex_active_slot_q] <=
          ((complex_done_command_id_i == task_command_id_q[complex_active_slot_q])
           && task_status_valid(complex_done_status_i)
           && (complex_done_status_i == NPU_STATUS_SUCCESS))
          ? NPU_TASK_SUCCESS : NPU_TASK_ERROR;
        task_notify_q[complex_active_slot_q] <= 1'b1;
        end
      end

      if (completion_hold_valid_q) begin
        if (completion_ready_i) begin
          task_notify_q[completion_hold_slot_q] <= 1'b0;
          completion_hold_valid_q <= 1'b0;
        end
      end else if (completion_found &&
                   task_event_published_q[completion_select]) begin
        completion_hold_valid_q <= 1'b1;
        completion_hold_slot_q  <= completion_select;
      end

      if (task_ack_valid_i && task_ack_ready_o) begin
        task_state_q[ack_select]      <= NPU_TASK_FREE;
        task_notify_q[ack_select]     <= 1'b0;
        task_progress_q[ack_select]   <= 64'd0;
        task_error_info_q[ack_select] <= 32'd0;
        task_done_flags_q[ack_select] <= 16'd0;
        task_event_published_q[ack_select] <= 1'b0;
      end

      if (event_publish_pending_valid_q) begin
        if (task_status_q[event_publish_pending_slot_q] ==
            NPU_STATUS_SUCCESS)
          event_state_q[
            task_signal_q[event_publish_pending_slot_q][7:0]
          ] <= NPU_EVENT_SUCCESS;
        else
          event_state_q[
            task_signal_q[event_publish_pending_slot_q][7:0]
          ] <= NPU_EVENT_ERROR;
        task_event_published_q[event_publish_pending_slot_q] <= 1'b1;
        if (event_publish_found) begin
          event_publish_pending_valid_q <= 1'b1;
          event_publish_pending_slot_q  <= event_publish_select;
        end else begin
          event_publish_pending_valid_q <= 1'b0;
        end
      end else if (event_publish_found) begin
        event_publish_pending_valid_q <= 1'b1;
        event_publish_pending_slot_q  <= event_publish_select;
      end

      if (abort_i) begin
        dma_dispatch_valid_q     <= 1'b0;
        matrix_dispatch_valid_q  <= 1'b0;
        vector_dispatch_valid_q  <= 1'b0;
        complex_dispatch_valid_q <= 1'b0;
        decode_pending_valid_q   <= 1'b0;
        decode_scan_active_q     <= 1'b0;
        decode_scan_slot_q       <= '0;
        decode_scan_best_valid_q <= 1'b0;
        for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
          if ((task_state_q[slot] != NPU_TASK_FREE) &&
              !terminal_state(task_state_q[slot])) begin
            task_state_q[slot]      <= NPU_TASK_ERROR;
            task_status_q[slot]     <= NPU_STATUS_ABORTED;
            task_fault_addr_q[slot] <= 48'd0;
            task_progress_q[slot]   <= 64'd0;
            task_error_info_q[slot] <= make_error_info(
              4'd5, NPU_STATUS_ABORTED, task_opcode_q[slot]);
            task_done_flags_q[slot] <= 16'h0004;
            task_notify_q[slot]     <= 1'b1;
          end
        end
      end
    end
  end

endmodule
