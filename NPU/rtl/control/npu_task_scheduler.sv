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

  input  logic          cmd_id_lookup_valid_i,
  output logic          cmd_id_lookup_ready_o,
  input  logic [11:0]   cmd_id_lookup_id_i,
  output logic          cmd_id_lookup_rsp_valid_o,
  output logic          cmd_id_busy_o,

  output logic          df_fetch_valid_o,
  input  logic          df_fetch_ready_i,
  output logic [47:0]   df_fetch_desc_addr_o,
  output logic [11:0]   df_fetch_command_id_o,
  output logic [3:0]    df_fetch_engine_o,
  output logic          df_fetch_crc_enable_o,

  input  logic          df_fetch_rsp_valid_i,
  output logic          df_fetch_rsp_ready_o,
  input  logic [11:0]   df_fetch_rsp_command_id_i,
  input  logic [7:0]    df_fetch_rsp_status_i,
  input  logic [47:0]   df_fetch_rsp_fault_addr_i,
  input  logic [2047:0] df_fetch_rsp_desc_flat_i,

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
  logic [47:0]   task_desc_addr_q    [TASK_SLOTS];
  logic [11:0]   task_command_id_q   [TASK_SLOTS];
  logic [3:0]    task_engine_q       [TASK_SLOTS];
  logic [7:0]    task_opcode_q       [TASK_SLOTS];
  logic [11:0]   task_header_flags_q [TASK_SLOTS];
  logic [11:0]   task_wait0_q        [TASK_SLOTS];
  logic [11:0]   task_wait1_q        [TASK_SLOTS];
  logic [11:0]   task_signal_q       [TASK_SLOTS];
  logic [63:0]   task_submit_seq_q   [TASK_SLOTS];
  logic [2047:0] task_desc_flat_q    [TASK_SLOTS];
  logic [7:0]    task_status_q       [TASK_SLOTS];
  logic [47:0]   task_fault_addr_q   [TASK_SLOTS];
  logic [63:0]   task_progress_q     [TASK_SLOTS];
  logic [31:0]   task_error_info_q   [TASK_SLOTS];
  logic [15:0]   task_done_flags_q   [TASK_SLOTS];
  logic          task_notify_q       [TASK_SLOTS];

  logic [2:0] event_state_q      [EVENT_COUNT];
  logic [3:0] event_generation_q [EVENT_COUNT];
  logic [11:0] event_producer_q  [EVENT_COUNT];

  logic [63:0] submit_seq_q;
  logic        fetch_active_q;
  logic [TASK_IDX_W-1:0] fetch_slot_q;

  logic        dma_active_q;
  logic        matrix_active_q;
  logic        vector_active_q;
  logic        complex_active_q;
  logic [TASK_IDX_W-1:0] dma_active_slot_q;
  logic [TASK_IDX_W-1:0] matrix_active_slot_q;
  logic [TASK_IDX_W-1:0] vector_active_slot_q;
  logic [TASK_IDX_W-1:0] complex_active_slot_q;

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

  logic fetch_found;
  logic [TASK_IDX_W-1:0] fetch_select;
  logic completion_found;
  logic [TASK_IDX_W-1:0] completion_select;
  logic query_found;
  logic [TASK_IDX_W-1:0] query_select;
  logic ctl_query_found;
  logic [TASK_IDX_W-1:0] ctl_query_select;
  logic ack_found;
  logic [TASK_IDX_W-1:0] ack_select;

  logic dma_select_found;
  logic matrix_select_found;
  logic vector_select_found;
  logic complex_select_found;
  logic control_select_found;
  logic [TASK_IDX_W-1:0] dma_select;
  logic [TASK_IDX_W-1:0] matrix_select;
  logic [TASK_IDX_W-1:0] vector_select;
  logic [TASK_IDX_W-1:0] complex_select;
  logic [TASK_IDX_W-1:0] control_select;

  logic dependency_success [TASK_SLOTS];
  logic dependency_failed  [TASK_SLOTS];
  logic order_blocked      [TASK_SLOTS];
  logic signal_available;
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

  function automatic logic terminal_state(input logic [3:0] state);
    return (state == NPU_TASK_SUCCESS) || (state == NPU_TASK_ERROR);
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
    return (event_generation_q[event_ref[7:0]] == event_ref[11:8])
        && (event_state_q[event_ref[7:0]] == NPU_EVENT_ERROR);
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
      signal_available
    && (cfe_cmd_i[127:120] == 8'h01)
    && (cfe_cmd_i[5:0] == 6'd0)
    && (cfe_cmd_i[83:82] == 2'd0)
    && npu_opcode_engine_valid(cfe_cmd_i[63:60], cfe_cmd_i[71:64])
    && npu_event_ref_valid(cfe_cmd_i[95:84])
    && npu_event_ref_valid(cfe_cmd_i[107:96])
    && npu_event_ref_valid(cfe_cmd_i[119:108]);

  always_comb begin
    lookup_busy_comb = 1'b0;
    for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
      if ((task_state_q[slot] != NPU_TASK_FREE) &&
          (task_command_id_q[slot] == cmd_id_lookup_id_i)) begin
        lookup_busy_comb = 1'b1;
      end
    end
  end

  always_comb begin
    signal_available = 1'b1;
    if (cfe_cmd_i[119:108] != NPU_EVENT_NONE) begin
      if (cfe_cmd_i[115:108] >= 8'(EVENT_COUNT)) begin
        signal_available = 1'b0;
      end else begin
        signal_available =
          (event_state_q[cfe_cmd_i[115:108]] == NPU_EVENT_FREE)
          && (event_generation_q[cfe_cmd_i[115:108]] == cfe_cmd_i[119:116]);
      end
    end
  end

  always_comb begin
    for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
      dependency_success[slot] =
        event_is_success(task_wait0_q[slot])
        && event_is_success(task_wait1_q[slot]);
      dependency_failed[slot] =
        event_is_failed(task_wait0_q[slot])
        || event_is_failed(task_wait1_q[slot]);
      order_blocked[slot] = 1'b0;
      if (task_header_flags_q[slot][4] ||
          (task_opcode_q[slot] == NPU_OPCODE_GLOBAL_FENCE)) begin
        for (int unsigned prior = 0; prior < TASK_SLOTS; prior++) begin
          if ((task_state_q[prior] != NPU_TASK_FREE) &&
              (task_submit_seq_q[prior] < task_submit_seq_q[slot]) &&
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

  always_comb begin
    fetch_found         = 1'b0;
    fetch_select        = '0;
    completion_found    = 1'b0;
    completion_select   = '0;
    dma_select_found    = 1'b0;
    matrix_select_found = 1'b0;
    vector_select_found = 1'b0;
    complex_select_found = 1'b0;
    control_select_found = 1'b0;
    dma_select          = '0;
    matrix_select       = '0;
    vector_select       = '0;
    complex_select      = '0;
    control_select      = '0;

    for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
      if ((task_state_q[slot] == NPU_TASK_FETCH_DESC) &&
          (!fetch_found ||
           (task_submit_seq_q[slot] < task_submit_seq_q[fetch_select]))) begin
        fetch_found  = 1'b1;
        fetch_select = TASK_IDX_W'(slot);
      end
      if (task_notify_q[slot] &&
          (!completion_found ||
           (task_submit_seq_q[slot] <
            task_submit_seq_q[completion_select]))) begin
        completion_found  = 1'b1;
        completion_select = TASK_IDX_W'(slot);
      end
      if ((task_state_q[slot] == NPU_TASK_READY) && !order_blocked[slot]) begin
        unique case (task_engine_q[slot])
          NPU_ENGINE_CONTROL: begin
            if (!control_select_found ||
                (task_submit_seq_q[slot] <
                 task_submit_seq_q[control_select])) begin
              control_select_found = 1'b1;
              control_select       = TASK_IDX_W'(slot);
            end
          end
          NPU_ENGINE_DMA: begin
            if (!dma_select_found ||
                (task_submit_seq_q[slot] <
                 task_submit_seq_q[dma_select])) begin
              dma_select_found = 1'b1;
              dma_select       = TASK_IDX_W'(slot);
            end
          end
          NPU_ENGINE_MATRIX: begin
            if (!matrix_select_found ||
                (task_submit_seq_q[slot] <
                 task_submit_seq_q[matrix_select])) begin
              matrix_select_found = 1'b1;
              matrix_select       = TASK_IDX_W'(slot);
            end
          end
          NPU_ENGINE_VECTOR: begin
            if (!vector_select_found ||
                (task_submit_seq_q[slot] <
                 task_submit_seq_q[vector_select])) begin
              vector_select_found = 1'b1;
              vector_select       = TASK_IDX_W'(slot);
            end
          end
          NPU_ENGINE_COMPLEX: begin
            if (!complex_select_found ||
                (task_submit_seq_q[slot] <
                 task_submit_seq_q[complex_select])) begin
              complex_select_found = 1'b1;
              complex_select       = TASK_IDX_W'(slot);
            end
          end
          default: begin
          end
        endcase
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

  assign df_fetch_valid_o       = fetch_found && !fetch_active_q && !abort_i;
  assign df_fetch_desc_addr_o   = task_desc_addr_q[fetch_select];
  assign df_fetch_command_id_o  = task_command_id_q[fetch_select];
  assign df_fetch_engine_o      = task_engine_q[fetch_select];
  assign df_fetch_crc_enable_o  = task_header_flags_q[fetch_select][5];
  assign df_fetch_rsp_ready_o   = fetch_active_q;

  assign dma_task_valid_o       = dma_select_found && !dma_active_q && !abort_i;
  assign dma_task_opcode_o      = task_opcode_q[dma_select];
  assign dma_task_command_id_o  = task_command_id_q[dma_select];
  assign dma_task_desc_flat_o   = task_desc_flat_q[dma_select];
  assign dma_done_ready_o       = dma_active_q;

  assign matrix_task_valid_o      = matrix_select_found && !matrix_active_q && !abort_i;
  assign matrix_task_opcode_o     = task_opcode_q[matrix_select];
  assign matrix_task_command_id_o = task_command_id_q[matrix_select];
  assign matrix_task_desc_flat_o  = task_desc_flat_q[matrix_select];
  assign matrix_done_ready_o      = matrix_active_q;

  assign vector_task_valid_o      = vector_select_found && !vector_active_q && !abort_i;
  assign vector_task_opcode_o     = task_opcode_q[vector_select];
  assign vector_task_command_id_o = task_command_id_q[vector_select];
  assign vector_task_desc_flat_o  = task_desc_flat_q[vector_select];
  assign vector_done_ready_o      = vector_active_q;

  assign complex_task_valid_o      = complex_select_found && !complex_active_q && !abort_i;
  assign complex_task_opcode_o     = task_opcode_q[complex_select];
  assign complex_task_command_id_o = task_command_id_q[complex_select];
  assign complex_task_desc_flat_o  = task_desc_flat_q[complex_select];
  assign complex_done_ready_o      = complex_active_q;

  assign completion_valid_o       = completion_found;
  assign completion_command_id_o  = task_command_id_q[completion_select];
  assign completion_engine_o      = task_engine_q[completion_select];
  assign completion_opcode_o      = task_opcode_q[completion_select];
  assign completion_status_o      = task_status_q[completion_select];
  assign completion_fault_addr_o  = task_fault_addr_q[completion_select];
  assign completion_progress_o    = task_progress_q[completion_select];
  assign completion_irq_success_o = task_header_flags_q[completion_select][0]
                                  && (task_status_q[completion_select] ==
                                      NPU_STATUS_SUCCESS);
  assign completion_irq_error_o   = task_header_flags_q[completion_select][1]
                                  && (task_status_q[completion_select] !=
                                      NPU_STATUS_SUCCESS);

  assign axi_ctl_ready_o    = !ctl_active_q && !ctl_rsp_valid_q;
  assign axi_ctl_rsp_valid_o = ctl_rsp_valid_q;
  assign axi_ctl_rsp_data_o  = ctl_rsp_data_q;

  assign task_query_found_o      = task_query_valid_i && query_found;
  assign task_query_state_o      = software_task_state(task_state_q[query_select]);
  assign task_query_status_o     = task_status_q[query_select];
  assign task_query_fault_addr_o = task_fault_addr_q[query_select];
  assign task_query_progress_o   = task_progress_q[query_select];
  assign task_query_user_tag_o   = task_desc_flat_q[query_select][511:480];
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
                          && !fetch_active_q
                          && !dma_active_q
                          && !matrix_active_q
                          && !vector_active_q
                          && !complex_active_q;

  always_ff @(posedge clk_i or negedge reset_n) begin
    if (!reset_n) begin
      submit_seq_q               <= 64'd0;
      fetch_active_q             <= 1'b0;
      fetch_slot_q               <= '0;
      dma_active_q               <= 1'b0;
      matrix_active_q            <= 1'b0;
      vector_active_q            <= 1'b0;
      complex_active_q           <= 1'b0;
      dma_active_slot_q          <= '0;
      matrix_active_slot_q       <= '0;
      vector_active_slot_q       <= '0;
      complex_active_slot_q      <= '0;
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
        task_desc_addr_q[slot]    <= 48'd0;
        task_command_id_q[slot]   <= 12'd0;
        task_engine_q[slot]       <= 4'd0;
        task_opcode_q[slot]       <= 8'd0;
        task_header_flags_q[slot] <= 12'd0;
        task_wait0_q[slot]        <= NPU_EVENT_NONE;
        task_wait1_q[slot]        <= NPU_EVENT_NONE;
        task_signal_q[slot]       <= NPU_EVENT_NONE;
        task_submit_seq_q[slot]   <= 64'd0;
        task_desc_flat_q[slot]    <= '0;
        task_status_q[slot]       <= NPU_STATUS_SUCCESS;
        task_fault_addr_q[slot]   <= 48'd0;
        task_progress_q[slot]     <= 64'd0;
        task_error_info_q[slot]   <= 32'd0;
        task_done_flags_q[slot]   <= 16'd0;
        task_notify_q[slot]       <= 1'b0;
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
          task_desc_flat_q[ctl_ack_slot_q]  <= '0;
          task_progress_q[ctl_ack_slot_q]   <= 64'd0;
          task_error_info_q[ctl_ack_slot_q] <= 32'd0;
          task_done_flags_q[ctl_ack_slot_q] <= 16'd0;
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
            if ((|axi_ctl_arg0_i[63:12])
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
                       task_desc_flat_q[ctl_query_select][511:480]}
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
            if ((|axi_ctl_arg0_i[63:12])
                || (|axi_ctl_arg1_i[63:32])
                || !npu_event_ref_valid(axi_ctl_arg0_i[11:0])
                || (axi_ctl_arg0_i[11:0] == NPU_EVENT_NONE)
                || (axi_ctl_arg0_i[7:0] >= 8'(EVENT_COUNT))) begin
              ctl_rsp_data_q  <= {56'd0, NPU_STATUS_BAD_DESC};
              ctl_rsp_valid_q <= 1'b1;
            end else if ((event_generation_q[axi_ctl_arg0_i[7:0]] !=
                          axi_ctl_arg0_i[11:8])
                         || (event_state_q[axi_ctl_arg0_i[7:0]] ==
                             NPU_EVENT_FREE)) begin
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
                                        ? NPU_TASK_FETCH_DESC
                                        : NPU_TASK_ERROR;
        task_desc_addr_q[free_slot]    <= cfe_cmd_i[47:0];
        task_command_id_q[free_slot]   <= cfe_cmd_i[59:48];
        task_engine_q[free_slot]       <= cfe_cmd_i[63:60];
        task_opcode_q[free_slot]       <= cfe_cmd_i[71:64];
        task_header_flags_q[free_slot] <= cfe_cmd_i[83:72];
        task_wait0_q[free_slot]        <= cfe_cmd_i[95:84];
        task_wait1_q[free_slot]        <= cfe_cmd_i[107:96];
        task_signal_q[free_slot]       <= cmd_static_valid
                                        ? cfe_cmd_i[119:108]
                                        : NPU_EVENT_NONE;
        task_submit_seq_q[free_slot]   <= submit_seq_q;
        task_desc_flat_q[free_slot]    <= '0;
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
                                            cfe_cmd_i[71:64]);
        task_done_flags_q[free_slot]   <= 16'd0;
        task_notify_q[free_slot]       <= !cmd_static_valid;
        submit_seq_q                   <= submit_seq_q + 1'b1;
        if (cmd_static_valid &&
            (cfe_cmd_i[119:108] != NPU_EVENT_NONE)) begin
          event_state_q[cfe_cmd_i[115:108]] <= NPU_EVENT_PENDING;
          event_producer_q[cfe_cmd_i[115:108]]
            <= cfe_cmd_i[59:48];
        end
      end

      if (df_fetch_valid_o && df_fetch_ready_i) begin
        fetch_active_q <= 1'b1;
        fetch_slot_q   <= fetch_select;
      end

      if (df_fetch_rsp_valid_i && df_fetch_rsp_ready_o) begin
        fetch_active_q <= 1'b0;
        if (terminal_state(task_state_q[fetch_slot_q])) begin
          // An abort can make the task terminal while DFU drains its response.
        end else if (df_fetch_rsp_command_id_i !=
                     task_command_id_q[fetch_slot_q]) begin
          task_state_q[fetch_slot_q]      <= NPU_TASK_ERROR;
          task_status_q[fetch_slot_q]     <= NPU_STATUS_BAD_DESC;
          task_fault_addr_q[fetch_slot_q] <= task_desc_addr_q[fetch_slot_q];
          task_progress_q[fetch_slot_q]   <= 64'd0;
          task_error_info_q[fetch_slot_q] <= make_error_info(
            4'd2, NPU_STATUS_BAD_DESC, task_opcode_q[fetch_slot_q]);
          task_done_flags_q[fetch_slot_q] <= 16'd0;
          task_notify_q[fetch_slot_q]     <= 1'b1;
        end else if (df_fetch_rsp_status_i != NPU_STATUS_SUCCESS) begin
          task_state_q[fetch_slot_q]      <= NPU_TASK_ERROR;
          task_status_q[fetch_slot_q]     <= df_fetch_rsp_status_i;
          task_fault_addr_q[fetch_slot_q] <= df_fetch_rsp_fault_addr_i;
          task_progress_q[fetch_slot_q]   <= 64'd0;
          task_error_info_q[fetch_slot_q] <= make_error_info(
            4'd2, df_fetch_rsp_status_i, task_opcode_q[fetch_slot_q]);
          task_done_flags_q[fetch_slot_q] <= 16'd0;
          task_notify_q[fetch_slot_q]     <= 1'b1;
        end else begin
          task_desc_flat_q[fetch_slot_q] <= df_fetch_rsp_desc_flat_i;
          task_state_q[fetch_slot_q]     <= NPU_TASK_WAIT_EVENT;
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
        task_status_q[control_select]     <= NPU_STATUS_SUCCESS;
        task_fault_addr_q[control_select] <= 48'd0;
        task_progress_q[control_select]   <= 64'd0;
        task_error_info_q[control_select] <= 32'd0;
        task_done_flags_q[control_select] <= 16'd0;
        task_state_q[control_select]      <= NPU_TASK_SUCCESS;
        task_notify_q[control_select]     <= 1'b1;
        if (task_opcode_q[control_select] == NPU_OPCODE_EVENT_REARM) begin
          if (task_desc_flat_q[control_select][263:256] <
              8'(EVENT_COUNT)) begin
            event_state_q[task_desc_flat_q[control_select][263:256]]
              <= NPU_EVENT_FREE;
            event_generation_q[task_desc_flat_q[control_select][263:256]]
              <= event_generation_q[task_desc_flat_q[control_select][263:256]]
               + 1'b1;
            event_producer_q[task_desc_flat_q[control_select][263:256]]
              <= 12'd0;
          end
        end
      end

      if (dma_task_valid_o && dma_task_ready_i) begin
        dma_active_q              <= 1'b1;
        dma_active_slot_q         <= dma_select;
        task_state_q[dma_select]  <= NPU_TASK_RUNNING;
      end
      if (matrix_task_valid_o && matrix_task_ready_i) begin
        matrix_active_q             <= 1'b1;
        matrix_active_slot_q        <= matrix_select;
        task_state_q[matrix_select] <= NPU_TASK_RUNNING;
      end
      if (vector_task_valid_o && vector_task_ready_i) begin
        vector_active_q             <= 1'b1;
        vector_active_slot_q        <= vector_select;
        task_state_q[vector_select] <= NPU_TASK_RUNNING;
      end
      if (complex_task_valid_o && complex_task_ready_i) begin
        complex_active_q             <= 1'b1;
        complex_active_slot_q        <= complex_select;
        task_state_q[complex_select] <= NPU_TASK_RUNNING;
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

      if (completion_valid_o && completion_ready_i) begin
        task_notify_q[completion_select] <= 1'b0;
      end

      if (task_ack_valid_i && task_ack_ready_o) begin
        task_state_q[ack_select]      <= NPU_TASK_FREE;
        task_notify_q[ack_select]     <= 1'b0;
        task_desc_flat_q[ack_select]  <= '0;
        task_progress_q[ack_select]   <= 64'd0;
        task_error_info_q[ack_select] <= 32'd0;
        task_done_flags_q[ack_select] <= 16'd0;
      end

      // Event state changes only after a task has a complete terminal record.
      for (int unsigned slot = 0; slot < TASK_SLOTS; slot++) begin
        if (task_notify_q[slot] &&
            (task_signal_q[slot] != NPU_EVENT_NONE)) begin
          if (task_status_q[slot] == NPU_STATUS_SUCCESS) begin
            event_state_q[task_signal_q[slot][7:0]] <= NPU_EVENT_SUCCESS;
          end else begin
            event_state_q[task_signal_q[slot][7:0]] <= NPU_EVENT_ERROR;
          end
        end
      end

      if (abort_i) begin
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
