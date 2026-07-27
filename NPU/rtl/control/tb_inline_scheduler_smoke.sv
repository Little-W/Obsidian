`timescale 1ns/1ps

module tb_inline_scheduler_smoke;
  import npu_rtl_pkg::*;

  logic clk;
  logic reset_n;
  logic cfe_cmd_valid;
  logic cfe_cmd_ready;
  logic [127:0] cfe_cmd;
  logic dma_task_valid;
  logic [7:0] dma_task_opcode;
  logic [11:0] dma_task_command_id;
  logic [2047:0] dma_task_desc;
  logic matrix_task_valid;
  logic [7:0] matrix_task_opcode;
  logic [11:0] matrix_task_command_id;
  logic [2047:0] matrix_task_desc;
  logic vector_task_valid;
  logic [7:0] vector_task_opcode;
  logic [11:0] vector_task_command_id;
  logic [2047:0] vector_task_desc;
  logic complex_task_valid;
  logic [7:0] complex_task_opcode;
  logic [11:0] complex_task_command_id;
  logic [2047:0] complex_task_desc;
  logic completion_valid;
  logic [11:0] completion_command_id;
  logic [3:0] completion_engine;
  logic [7:0] completion_opcode;
  logic [7:0] completion_status;
  logic [47:0] completion_fault_addr;
  logic [63:0] completion_progress;
  logic completion_irq_success;
  logic completion_irq_error;
  logic lookup_ready;
  logic lookup_rsp_valid;
  logic lookup_busy;
  logic dma_done_ready;
  logic matrix_done_ready;
  logic vector_done_ready;
  logic complex_done_ready;
  logic ctl_ready;
  logic ctl_rsp_valid;
  logic [63:0] ctl_rsp_data;
  logic event_query_found;
  logic [2:0] event_query_state;
  logic [11:0] event_query_producer;
  logic task_query_found;
  logic [3:0] task_query_state;
  logic [7:0] task_query_status;
  logic [47:0] task_query_fault;
  logic [63:0] task_query_progress;
  logic [31:0] task_query_tag;
  logic [11:0] task_query_signal;
  logic [31:0] task_query_error;
  logic [15:0] task_query_flags;
  logic task_ack_ready;
  logic scheduler_idle;
  logic [15:0] task_occupancy;
  logic [127:0] decode_cmd;
  logic decode_valid;
  logic [3:0] decode_engine;
  logic [7:0] decode_opcode;
  logic [2047:0] decode_desc;
  logic [47:0] scheduler_input_base;
  logic [47:0] scheduler_weight_base;
  logic [47:0] scheduler_work_base;
  logic [47:0] scheduler_output_base;
  logic [47:0] scheduler_kv_base;
  logic [19:0] scheduler_param_l1_base;

  always #5 clk = ~clk;

  function automatic logic [127:0] make_command(
    input logic [5:0] command_opcode,
    input logic [9:0] command_id,
    input logic [1:0] dtype,
    input logic [79:0] payload
  );
    logic [127:0] command;
    begin
      command = 128'd0;
      command[127:122] = command_opcode;
      command[121:112] = command_id;
      command[111:104] = 8'hff;
      command[103:96] = 8'hff;
      command[95:88] = 8'hff;
      command[81:80] = dtype;
      command[79:0] = payload;
      return command;
    end
  endfunction

  function automatic logic [79:0] payload_for_opcode(
    input logic [5:0] command_opcode
  );
    logic [79:0] result;
    begin
      result = 80'd0;
      unique case (command_opcode)
        6'd4:
          result[79:76] = 4'hf;
        6'd5, 6'd6:
          result = {
            28'h000_0100, 28'h000_0200, 20'd4,
            NPU_DTYPE_INT8, 1'b0, 1'b0
          };
        6'd7:
          result = {28'h000_0200, 20'd4, 32'h1234_5678};
        6'd8:
          result = {
            28'h000_0100, 28'h000_0200,
            8'd2, 8'd2, NPU_DTYPE_INT8, 2'd0, 4'd0
          };
        6'd9, 6'd10:
          result = {
            28'h000_0100, 28'h000_0200, 8'd2, 8'd4, 8'd8
          };
        6'd12, 6'd14:
          result = {
            14'h004, 14'h008, 14'h00c, 12'd0,
            6'd0, 6'd0, 6'd0,
            1'b0, NPU_DTYPE_INT32, 5'd0
          };
        6'd15:
          result = {
            14'd0, 14'd0, 14'h00c, 12'd0,
            6'd0, 6'd0, 6'd0,
            1'b0, NPU_DTYPE_INT32, 5'd0
          };
        6'd13:
          result = {
            14'h004, 14'h008, 14'h00c,
            6'd0, 6'd0, 6'd0, 6'd0,
            1'b0, NPU_DTYPE_INT32, 5'd0, 6'd0
          };
        6'd16, 6'd17, 6'd18, 6'd20, 6'd21:
          result = {
            16'h0010, 16'h0020, 16'h0000,
            16'h0030, 5'd0, 5'd0, 2'd0, 2'd0, 2'd0
          };
        6'd19:
          result = {
            16'h0010, 16'h0020, 16'h0040, 16'h0030,
            5'd0, 5'd0, 2'd0, 2'd0, 2'd0
          };
        6'd22:
          result = {
            16'h0010, 16'h0020, 16'h4000, 16'h0030,
            5'd0, 5'd0, 2'd0, 2'd0, 2'd0
          };
        6'd23:
          result = {
            16'h0010, 16'h0020, 16'h0040, 16'h0030,
            5'd0, 5'd0, 2'd0, 2'd0, 2'd0
          };
        6'd24:
          result = {
            16'h0010, 16'hffff, 16'h0001, 16'h0030,
            5'd0, 5'd0, 2'd0, 2'd0, 2'd0
          };
        6'd25:
          result = {
            16'h0010, 16'h0000, 16'h0000, 16'h0030,
            5'd0, 5'd0, 2'd0, 2'd0, 2'd0
          };
        6'd26:
          result = {
            16'h0010, 16'h0000, 16'h0020, 5'd0, 8'd0,
            2'd0, 4'd0, 4'd0, NPU_DTYPE_INT8, 2'd0, 5'd0
          };
        6'd27:
          result = {
            16'h0010, 16'h0000, 16'h0020, 5'd0, 8'd0,
            2'd0, 1'b0, 4'd0, 4'd0, NPU_DTYPE_INT8, 6'd0
          };
        6'd28:
          result = {
            16'h0010, 16'h0040, 16'h0020, 5'd0, 8'd0,
            1'b0, 2'd0, 4'd0, 4'd0, 4'd0,
            NPU_DTYPE_INT8, 2'd0
          };
        6'd30:
          result = {
            16'h0010, 16'h0000, 16'h0020, 5'd0, 8'd0,
            2'd0, 17'd0
          };
        6'd32:
          result = {
            16'h0010, 16'h0040, 16'h0020, 5'd0, 8'd0,
            4'd0, 4'd0, 4'd0, NPU_DTYPE_INT8, 5'd0
          };
        default: begin
        end
      endcase
      return result;
    end
  endfunction

  task automatic submit(input logic [127:0] command);
    begin
      @(negedge clk);
      cfe_cmd = command;
      cfe_cmd_valid = 1'b1;
      while (!cfe_cmd_ready) @(negedge clk);
      @(posedge clk);
      @(negedge clk);
      cfe_cmd_valid = 1'b0;
      cfe_cmd = 128'd0;
    end
  endtask

  npu_inline_desc_decode u_decode_smoke (
    .cmd_i(decode_cmd),
    .input_base_i(48'h0001_0000),
    .weight_base_i(48'h0002_0000),
    .work_base_i(48'h0003_0000),
    .output_base_i(48'h0004_0000),
    .kv_base_i(48'h0005_0000),
    .param_l1_base_i(20'h00800),
    .valid_o(decode_valid),
    .engine_o(decode_engine),
    .opcode_o(decode_opcode),
    .desc_flat_o(decode_desc)
  );

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
    .input_base_i(scheduler_input_base),
    .weight_base_i(scheduler_weight_base),
    .work_base_i(scheduler_work_base),
    .output_base_i(scheduler_output_base),
    .kv_base_i(scheduler_kv_base),
    .param_l1_base_i(scheduler_param_l1_base),
    .cmd_id_lookup_valid_i(1'b0),
    .cmd_id_lookup_ready_o(lookup_ready),
    .cmd_id_lookup_id_i(10'd0),
    .cmd_id_lookup_rsp_valid_o(lookup_rsp_valid),
    .cmd_id_busy_o(lookup_busy),
    .dma_task_valid_o(dma_task_valid),
    .dma_task_ready_i(1'b0),
    .dma_task_opcode_o(dma_task_opcode),
    .dma_task_command_id_o(dma_task_command_id),
    .dma_task_desc_flat_o(dma_task_desc),
    .dma_done_valid_i(1'b0),
    .dma_done_ready_o(dma_done_ready),
    .dma_done_command_id_i(12'd0),
    .dma_done_status_i(NPU_STATUS_SUCCESS),
    .dma_done_fault_addr_i(48'd0),
    .dma_done_progress_i(64'd0),
    .matrix_task_valid_o(matrix_task_valid),
    .matrix_task_ready_i(1'b0),
    .matrix_task_opcode_o(matrix_task_opcode),
    .matrix_task_command_id_o(matrix_task_command_id),
    .matrix_task_desc_flat_o(matrix_task_desc),
    .matrix_done_valid_i(1'b0),
    .matrix_done_ready_o(matrix_done_ready),
    .matrix_done_command_id_i(12'd0),
    .matrix_done_status_i(NPU_STATUS_SUCCESS),
    .matrix_done_fault_addr_i(48'd0),
    .matrix_done_progress_i(64'd0),
    .vector_task_valid_o(vector_task_valid),
    .vector_task_ready_i(1'b0),
    .vector_task_opcode_o(vector_task_opcode),
    .vector_task_command_id_o(vector_task_command_id),
    .vector_task_desc_flat_o(vector_task_desc),
    .vector_done_valid_i(1'b0),
    .vector_done_ready_o(vector_done_ready),
    .vector_done_command_id_i(12'd0),
    .vector_done_status_i(NPU_STATUS_SUCCESS),
    .vector_done_fault_addr_i(48'd0),
    .vector_done_progress_i(64'd0),
    .complex_task_valid_o(complex_task_valid),
    .complex_task_ready_i(1'b0),
    .complex_task_opcode_o(complex_task_opcode),
    .complex_task_command_id_o(complex_task_command_id),
    .complex_task_desc_flat_o(complex_task_desc),
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
    .axi_ctl_valid_i(1'b0),
    .axi_ctl_ready_o(ctl_ready),
    .axi_ctl_op_i(2'd0),
    .axi_ctl_arg0_i(64'd0),
    .axi_ctl_arg1_i(64'd0),
    .axi_ctl_cancel_i(1'b0),
    .axi_ctl_rsp_valid_o(ctl_rsp_valid),
    .axi_ctl_rsp_ready_i(1'b1),
    .axi_ctl_rsp_data_o(ctl_rsp_data),
    .event_query_valid_i(1'b0),
    .event_query_ref_i(12'd0),
    .event_query_found_o(event_query_found),
    .event_query_state_o(event_query_state),
    .event_query_producer_command_id_o(event_query_producer),
    .task_query_valid_i(1'b0),
    .task_query_command_id_i(12'd0),
    .task_query_found_o(task_query_found),
    .task_query_state_o(task_query_state),
    .task_query_status_o(task_query_status),
    .task_query_fault_addr_o(task_query_fault),
    .task_query_progress_o(task_query_progress),
    .task_query_user_tag_o(task_query_tag),
    .task_query_signal_event_o(task_query_signal),
    .task_query_error_info_o(task_query_error),
    .task_query_done_flags_o(task_query_flags),
    .task_ack_valid_i(1'b0),
    .task_ack_command_id_i(12'd0),
    .task_ack_ready_o(task_ack_ready),
    .scheduler_idle_o(scheduler_idle),
    .task_occupancy_o(task_occupancy)
  );

  initial begin
    logic [79:0] dma_payload;
    logic [79:0] matrix_payload;
    logic [79:0] vector_payload;
    logic [79:0] complex_payload;
    logic [79:0] requant_payload;
    logic [127:0] event_command;

    clk = 1'b0;
    reset_n = 1'b0;
    cfe_cmd_valid = 1'b0;
    cfe_cmd = 128'd0;
    decode_cmd = 128'd0;
    scheduler_input_base = 48'h0001_0000;
    scheduler_weight_base = 48'h0002_0000;
    scheduler_work_base = 48'h0003_0000;
    scheduler_output_base = 48'h0004_0000;
    scheduler_kv_base = 48'h0005_0000;
    scheduler_param_l1_base = 20'h00800;
    repeat (4) @(posedge clk);
    reset_n = 1'b1;
    repeat (2) @(posedge clk);

    for (int unsigned opcode_index = 0; opcode_index <= 32; opcode_index++) begin
      decode_cmd = make_command(
        6'(opcode_index), 10'h3ff, NPU_DTYPE_INT8,
        payload_for_opcode(6'(opcode_index))
      );
      if (opcode_index == 1 || opcode_index == 2) begin
        decode_cmd[95:88] = 8'h01;
      end else if (opcode_index == 3) begin
        decode_cmd[111:104] = 8'h01;
        decode_cmd[103:96] = 8'h02;
        decode_cmd[95:88] = 8'h03;
      end
      #1;
      if ((opcode_index == 11) || (opcode_index == 29) ||
          (opcode_index == 31)) begin
        if (decode_valid ||
            npu_cmd_engine_from_opcode(6'(opcode_index)) != 4'hf ||
            npu_cmd_expanded_opcode(6'(opcode_index)) != 8'hff) begin
          $fatal(
            1,
            "disabled opcode %0d did not produce invalid decode values",
            opcode_index
          );
        end
      end else begin
        if (!decode_valid ||
            decode_engine != npu_cmd_engine_from_opcode(6'(opcode_index)) ||
            decode_opcode != npu_cmd_expanded_opcode(6'(opcode_index)) ||
            decode_desc[15:8] !=
              {4'd0, npu_cmd_engine_from_opcode(6'(opcode_index))} ||
            decode_desc[31:16] !=
              npu_desc_bytes_for_engine(
                npu_cmd_engine_from_opcode(6'(opcode_index))) ||
            decode_desc[511:480] != 32'h0000_03ff) begin
          $fatal(1, "CMD128 expansion failed for opcode %0d", opcode_index);
        end
      end
    end

    decode_cmd = make_command(
      6'd33, 10'h001, NPU_DTYPE_INT8, payload_for_opcode(6'd0)
    );
    #1;
    if (decode_valid ||
        npu_cmd_engine_from_opcode(6'd33) != 4'hf ||
        npu_cmd_expanded_opcode(6'd33) != 8'hff) begin
      $fatal(1, "opcode 33 did not produce invalid decode values");
    end

    decode_cmd = make_command(
      6'd24, 10'h001, NPU_DTYPE_INT8, payload_for_opcode(6'd24)
    );
    decode_cmd[2] = 1'b1;
    #1;
    if (decode_valid)
      $fatal(1, "VCLAMP accepted a nonzero reserved broadcast field");

    requant_payload = {
      14'h004, 14'h008, 14'h00c, 12'h010,
      6'd0, 6'd0, 6'd0,
      1'b1, NPU_DTYPE_INT8, 5'd19
    };
    decode_cmd = make_command(
      6'd12, 10'h001, NPU_DTYPE_INT8, requant_payload
    );
    #1;
    if (!decode_valid ||
        !decode_desc[16'hb0 * 8] ||
        decode_desc[16'hb1 * 8 +: 8] != 8'd19 ||
        decode_desc[320 +: 64] != 64'h400 ||
        decode_desc[448 + 3 -: 2] != NPU_DTYPE_INT4 ||
        !decode_desc[16'h5c * 8 + 2] ||
        decode_desc[16'h9c * 8 +: 32] != 32'd1) begin
      $fatal(1, "inline Matrix output scaling fields are incorrect");
    end
    requant_payload[37:26] = 12'd0;
    requant_payload[6:5] = NPU_DTYPE_INT32;
    requant_payload[4:0] = 5'd0;
    decode_cmd = make_command(
      6'd12, 10'h002, NPU_DTYPE_INT16, requant_payload
    );
    #1;
    if (decode_valid)
      $fatal(1, "inline Matrix accepted INT16 A with b_int4 set");
    requant_payload[79:66] = 14'd0;
    requant_payload[65:52] = 14'd0;
    requant_payload[13:8] = 6'd0;
    requant_payload[7] = 1'b0;
    decode_cmd = make_command(
      6'd15, 10'h003, NPU_DTYPE_INT16, requant_payload
    );
    #1;
    if (!decode_valid ||
        decode_desc[64 +: 192] != 192'd0 ||
        decode_desc[16'h48 * 8 +: 32] != 32'd0)
      $fatal(1, "inline Matrix ZERO fields are incorrect");
    requant_payload[79:66] = 14'h004;
    decode_cmd = make_command(
      6'd15, 10'h004, NPU_DTYPE_INT16, requant_payload
    );
    #1;
    if (decode_valid)
      $fatal(1, "inline Matrix ZERO accepted a nonzero A reference");
    matrix_payload = {
      14'h004, 14'h008, 14'h00c,
      6'd0, 6'd0, 6'd0, 6'd0,
      1'b1, NPU_DTYPE_INT8, 5'd13, 6'd0
    };
    decode_cmd = make_command(
      6'd13, 10'h005, NPU_DTYPE_INT8, matrix_payload
    );
    #1;
    if (!decode_valid ||
        decode_desc[448 + 3 -: 2] != NPU_DTYPE_INT4 ||
        decode_desc[16'hb1 * 8 +: 8] != 8'd13 ||
        decode_desc[16'h4c * 8 +: 32] != 32'd1)
      $fatal(1, "inline Matrix BMM fields are incorrect");
    matrix_payload[0] = 1'b1;
    decode_cmd = make_command(
      6'd13, 10'h006, NPU_DTYPE_INT8, matrix_payload
    );
    #1;
    if (decode_valid)
      $fatal(1, "inline Matrix BMM accepted a reserved payload bit");
    decode_cmd = 128'd0;

    event_command = make_command(
      6'd1, 10'h009, NPU_DTYPE_INT8, 80'd0
    );
    event_command[95:88] = 8'h07;
    submit(event_command);
    wait (dut.event_state_q[7] == NPU_EVENT_SUCCESS);

    event_command = make_command(
      6'd2, 10'h00a, NPU_DTYPE_INT8, 80'd0
    );
    event_command[95:88] = 8'h07;
    submit(event_command);
    wait ((dut.event_state_q[7] == NPU_EVENT_FREE) &&
          (dut.event_generation_q[7] == 4'd1));
    repeat (3) @(posedge clk);
    if ((dut.event_state_q[7] != NPU_EVENT_FREE) ||
        (dut.event_generation_q[7] != 4'd1)) begin
      $fatal(1, "EVENT_REARM was treated as an ordinary signal");
    end

    submit(make_command(6'd0, 10'h011, NPU_DTYPE_INT8, 80'd0));

    dma_payload = {
      28'h900_0100, 28'hc00_0200, 20'd4,
      NPU_DTYPE_INT8, 1'b0, 1'b0
    };
    submit(make_command(
      6'd5, 10'h3ff, NPU_DTYPE_INT8, dma_payload
    ));
    scheduler_input_base = 48'h0006_0000;
    scheduler_weight_base = 48'h0007_0000;
    scheduler_work_base = 48'h0008_0000;
    scheduler_output_base = 48'h0009_0000;
    scheduler_kv_base = 48'h000a_0000;
    scheduler_param_l1_base = 20'h01000;

    matrix_payload = {
      14'h004, 14'h008, 14'h00c, 12'd0,
      6'd0, 6'd0, 6'd0,
      1'b0, NPU_DTYPE_INT32, 5'd0
    };
    submit(make_command(
      6'd12, 10'h013, NPU_DTYPE_INT8, matrix_payload
    ));

    vector_payload = {
      16'h0010, 16'h0020, 16'h0000, 16'h0030,
      5'd0, 5'd0, 2'd0, 2'd0, 2'd0
    };
    submit(make_command(
      6'd16, 10'h014, NPU_DTYPE_INT8, vector_payload
    ));

    complex_payload = {
      16'h0010, 16'h0000, 16'h0020,
      5'd0, 8'd0,
      2'd0, 4'd0, 4'd0, NPU_DTYPE_INT8, 2'd0, 5'd0
    };
    submit(make_command(
      6'd26, 10'h015, NPU_DTYPE_INT8, complex_payload
    ));

    wait (dma_task_valid && matrix_task_valid &&
          vector_task_valid && complex_task_valid);
    repeat (2) @(posedge clk);

    if (dma_task_opcode != NPU_OPCODE_DMA_COPY_1D ||
        dma_task_command_id != 12'h3ff ||
        dma_task_desc[15:8] != {4'd0, NPU_ENGINE_DMA} ||
        dma_task_desc[64 +: 64] != 64'h1_0100 ||
        dma_task_desc[256 +: 64] != 64'h4_0200 ||
        dma_task_desc[16'h48 * 8 +: 32] != 32'd4)
      $fatal(1, "DMA command expansion mismatch");
    if (matrix_task_opcode != NPU_OPCODE_GEMM ||
        matrix_task_command_id != 12'h013 ||
        matrix_task_desc[15:8] != {4'd0, NPU_ENGINE_MATRIX} ||
        matrix_task_desc[16'h40 * 8 +: 32] != 32'd1 ||
        matrix_task_desc[16'h44 * 8 +: 32] != 32'd1 ||
        matrix_task_desc[16'h48 * 8 +: 32] != 32'd1)
      $fatal(1, "Matrix command expansion mismatch");
    if (vector_task_opcode != NPU_OPCODE_VADD_I ||
        vector_task_command_id != 12'h014 ||
        vector_task_desc[15:8] != {4'd0, NPU_ENGINE_VECTOR} ||
        vector_task_desc[16'h40 * 8 +: 32] != 32'd1 ||
        vector_task_desc[16'h44 * 8 +: 32] != 32'd1)
      $fatal(1, "Vector command expansion mismatch");
    if (complex_task_opcode != NPU_OPCODE_VACT_I ||
        complex_task_command_id != 12'h015 ||
        complex_task_desc[15:8] != {4'd0, NPU_ENGINE_COMPLEX} ||
        complex_task_desc[16'h40 * 8 +: 32] != 32'd1 ||
        complex_task_desc[16'h44 * 8 +: 32] != 32'd1 ||
        complex_task_desc[16'h70 * 8 +: 32] != 32'h3f80_0000)
      $fatal(1, "Complex command expansion mismatch");

    $display(
      "PASS: CMD128 directly expands all engine classes %0b",
      ^{
        dma_task_desc, matrix_task_desc, vector_task_desc,
        complex_task_desc,
        completion_valid, completion_command_id, completion_engine,
        completion_opcode, completion_status, completion_fault_addr,
        completion_progress, completion_irq_success, completion_irq_error,
        lookup_ready, lookup_rsp_valid, lookup_busy,
        dma_done_ready, matrix_done_ready, vector_done_ready,
        complex_done_ready, ctl_ready, ctl_rsp_valid, ctl_rsp_data,
        event_query_found, event_query_state, event_query_producer,
        task_query_found, task_query_state, task_query_status,
        task_query_fault, task_query_progress, task_query_tag,
        task_query_signal, task_query_error, task_query_flags,
        task_ack_ready, scheduler_idle, task_occupancy,
        decode_cmd, decode_valid, decode_engine, decode_opcode, decode_desc
      }
    );
    $finish;
  end

  initial begin
    #100000;
    $fatal(1, "inline scheduler smoke test timeout");
  end

endmodule
