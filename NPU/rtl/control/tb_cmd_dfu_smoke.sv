module tb_cmd_dfu_smoke;
  import npu_rtl_pkg::*;

  logic clk;
  logic reset_n;

  logic cmd_valid;
  logic cmd_ready;
  logic [63:0] cmd_data;
  logic cmd_first;
  logic cmd_last;
  logic cmd_rsp_valid;
  logic [63:0] cmd_rsp_data;
  logic ts_cmd_valid;
  logic ts_cmd_ready;
  logic [127:0] ts_cmd;
  logic lookup_valid;
  logic lookup_ready;
  logic [11:0] lookup_id;
  logic lookup_rsp_valid;
  logic lookup_busy;
  logic lookup_pending_q;
  logic cfe_idle;
  logic cfe_error;
  logic cmd_accepted;
  int unsigned cfe_error_count;
  int unsigned cmd_accepted_count;

  logic fetch_valid;
  logic fetch_ready;
  logic [47:0] fetch_addr;
  logic [11:0] fetch_id;
  logic [3:0] fetch_engine;
  logic fetch_crc;
  logic fetch_rsp_valid;
  logic [11:0] fetch_rsp_id;
  logic [7:0] fetch_rsp_status;
  logic [47:0] fetch_rsp_fault;
  logic [2047:0] fetch_rsp_desc;
  logic mem_req_valid;
  logic mem_req_ready;
  logic mem_req_write;
  logic [47:0] mem_req_addr;
  logic [63:0] mem_req_wdata;
  logic [7:0] mem_req_wstrb;
  logic mem_rsp_valid;
  logic mem_rsp_ready;
  logic [63:0] mem_rsp_data;
  logic [2:0] mem_rsp_status;
  logic dfu_idle;
  logic [63:0] descriptor_words [32];
  int unsigned mem_request_count;

  always #5 clk = ~clk;

  npu_cmd_frontend u_cfe (
    .clk_i(clk),
    .reset_n(reset_n),
    .quiesce_i(1'b0),
    .axi_cmd_valid_i(cmd_valid),
    .axi_cmd_ready_o(cmd_ready),
    .axi_cmd_data_i(cmd_data),
    .axi_cmd_first_i(cmd_first),
    .axi_cmd_last_i(cmd_last),
    .axi_cmd_rsp_valid_o(cmd_rsp_valid),
    .axi_cmd_rsp_ready_i(1'b1),
    .axi_cmd_rsp_data_o(cmd_rsp_data),
    .ts_cmd_valid_o(ts_cmd_valid),
    .ts_cmd_ready_i(ts_cmd_ready),
    .ts_cmd_o(ts_cmd),
    .cmd_id_lookup_valid_o(lookup_valid),
    .cmd_id_lookup_ready_i(lookup_ready),
    .cmd_id_lookup_id_o(lookup_id),
    .cmd_id_lookup_rsp_valid_i(lookup_rsp_valid),
    .cmd_id_busy_i(lookup_busy),
    .cfe_idle_o(cfe_idle),
    .cfe_error_o(cfe_error),
    .cmd_accepted_o(cmd_accepted)
  );

  npu_descriptor_fetch u_dfu (
    .clk_i(clk),
    .reset_n(reset_n),
    .abort_i(1'b0),
    .fetch_valid_i(fetch_valid),
    .fetch_ready_o(fetch_ready),
    .fetch_desc_addr_i(fetch_addr),
    .fetch_command_id_i(fetch_id),
    .fetch_engine_i(fetch_engine),
    .fetch_crc_enable_i(fetch_crc),
    .fetch_rsp_valid_o(fetch_rsp_valid),
    .fetch_rsp_ready_i(1'b1),
    .fetch_rsp_command_id_o(fetch_rsp_id),
    .fetch_rsp_status_o(fetch_rsp_status),
    .fetch_rsp_fault_addr_o(fetch_rsp_fault),
    .fetch_rsp_desc_flat_o(fetch_rsp_desc),
    .mem_req_valid_o(mem_req_valid),
    .mem_req_ready_i(mem_req_ready),
    .mem_req_write_o(mem_req_write),
    .mem_req_addr_o(mem_req_addr),
    .mem_req_wdata_o(mem_req_wdata),
    .mem_req_wstrb_o(mem_req_wstrb),
    .mem_rsp_valid_i(mem_rsp_valid),
    .mem_rsp_ready_o(mem_rsp_ready),
    .mem_rsp_rdata_i(mem_rsp_data),
    .mem_rsp_status_i(mem_rsp_status),
    .dfu_idle_o(dfu_idle)
  );

  always_ff @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
      lookup_pending_q <= 1'b0;
      lookup_rsp_valid <= 1'b0;
      lookup_busy      <= 1'b0;
    end else begin
      lookup_rsp_valid <= lookup_pending_q;
      lookup_pending_q <= lookup_valid && lookup_ready;
      if (lookup_valid && lookup_ready) begin
        if (lookup_id != 12'h001) begin
          $fatal(1, "CFE lookup used the wrong command ID");
        end
        lookup_busy <= 1'b0;
      end
    end
  end

  always_ff @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
      cfe_error_count   <= 0;
      cmd_accepted_count <= 0;
    end else begin
      if (cfe_error) begin
        cfe_error_count <= cfe_error_count + 1;
      end
      if (cmd_accepted) begin
        cmd_accepted_count <= cmd_accepted_count + 1;
      end
    end
  end

  always_ff @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
    end else if (lookup_valid || lookup_rsp_valid || cmd_rsp_valid) begin
      $display("TRACE: t=%0t lookup_v=%0b lookup_rsp=%0b cmd_rsp=%0b state=%0d",
               $time, lookup_valid, lookup_rsp_valid, cmd_rsp_valid,
               u_cfe.state_q);
    end
  end

  always_ff @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
      mem_rsp_valid      <= 1'b0;
      mem_rsp_data       <= 64'd0;
      mem_rsp_status     <= NPU_MEM_OK;
      mem_request_count  <= 0;
    end else begin
      mem_rsp_valid <= 1'b0;
      if (mem_req_valid && mem_req_ready) begin
        if (mem_req_write || (mem_req_wdata != 64'd0)
            || (mem_req_wstrb != 8'd0)) begin
          $fatal(1, "DFU emitted a write-form memory request");
        end
        mem_rsp_valid <= 1'b1;
        mem_rsp_data  <= descriptor_words[
          5'((mem_req_addr - fetch_addr) >> 3)
        ];
        mem_rsp_status <= NPU_MEM_OK;
        mem_request_count <= mem_request_count + 1;
      end
      if (mem_rsp_valid && !mem_rsp_ready) begin
        $fatal(1, "DFU did not accept its pending memory response");
      end
    end
  end

  task automatic check_cmd_response(
    input logic [11:0] expected_id,
    input logic [7:0] expected_status
  );
    begin
      if ((cmd_rsp_data[11:0] != expected_id)
          || (cmd_rsp_data[19:12] != expected_status)
          || (cmd_rsp_data[27:20] > 8'd8)
          || (cmd_rsp_data[63:28] != 36'd0)) begin
        $fatal(1, "CFE response fields are incorrect");
      end
    end
  endtask

  task automatic send_cmd_beat(
    input logic [63:0] data,
    input logic first,
    input logic last
  );
    begin
      @(negedge clk);
      cmd_data  = data;
      cmd_first = first;
      cmd_last  = last;
      cmd_valid = 1'b1;
      while (!cmd_ready) @(negedge clk);
      @(posedge clk);
      @(negedge clk);
      cmd_valid = 1'b0;
      cmd_data  = 64'd0;
      cmd_first = 1'b0;
      cmd_last  = 1'b0;
    end
  endtask

  task automatic start_fetch(input logic [31:0] numeric_cfg);
    begin
      for (int unsigned word_idx = 0; word_idx < 32; word_idx++) begin
        descriptor_words[word_idx] = 64'd0;
      end
      descriptor_words[0] = 64'h0000_0000_0100_0101;
      descriptor_words[7] = {32'h1234_5678, numeric_cfg};
      @(negedge clk);
      fetch_valid  = 1'b1;
      while (!fetch_ready) @(negedge clk);
      @(posedge clk);
      @(negedge clk);
      fetch_valid = 1'b0;
    end
  endtask

  initial begin
    logic [63:0] low_word;
    logic [63:0] high_word;

    clk            = 1'b0;
    reset_n        = 1'b0;
    cmd_valid      = 1'b0;
    cmd_data       = 64'd0;
    cmd_first      = 1'b0;
    cmd_last       = 1'b0;
    ts_cmd_ready   = 1'b0;
    lookup_ready   = 1'b1;
    fetch_valid    = 1'b0;
    fetch_addr     = 48'h0000_0000_1000;
    fetch_id       = 12'h02a;
    fetch_engine   = NPU_ENGINE_DMA;
    fetch_crc      = 1'b0;
    mem_req_ready  = 1'b1;
    repeat (4) @(posedge clk);
    reset_n = 1'b1;
    repeat (2) @(posedge clk);

    low_word  = {NPU_ENGINE_DMA, 12'h001, 48'h0000_0000_1000};
    high_word = {8'h01, NPU_EVENT_NONE, NPU_EVENT_NONE,
                 NPU_EVENT_NONE, 12'd0, NPU_OPCODE_DMA_COPY_1D};

    send_cmd_beat(low_word, 1'b1, 1'b0);
    $display("INFO: CFE low beat accepted");
    repeat (3) begin
      @(posedge clk);
      if (ts_cmd_valid || cmd_rsp_valid) begin
        $fatal(1, "CFE exposed a partial CMD128");
      end
    end
    send_cmd_beat(high_word, 1'b0, 1'b1);
    $display("INFO: CFE high beat accepted");
    wait (cmd_rsp_valid);
    $display("INFO: CFE response observed");
    check_cmd_response(12'h001, NPU_STATUS_SUCCESS);
    wait (ts_cmd_valid);
    if (ts_cmd != {high_word, low_word}) begin
      $fatal(1, "CFE changed CMD128 data");
    end
    ts_cmd_ready = 1'b1;
    @(posedge clk);
    @(negedge clk);
    ts_cmd_ready = 1'b0;

    send_cmd_beat(low_word, 1'b1, 1'b0);
    send_cmd_beat(high_word, 1'b1, 1'b0);
    wait (cmd_rsp_valid);
    $display("INFO: malformed CFE response observed");
    check_cmd_response(12'h001, NPU_STATUS_BAD_DESC);
    if (ts_cmd_valid) begin
      $fatal(1, "malformed CMD reached the scheduler output");
    end
    @(posedge clk);

    low_word = {NPU_ENGINE_DMA, 12'h002, 48'h0000_0000_1000};
    send_cmd_beat(low_word, 1'b1, 1'b0);
    wait (cmd_rsp_valid);
    check_cmd_response(12'h002, NPU_STATUS_TIMEOUT);
    if (ts_cmd_valid) begin
      $fatal(1, "timed-out CMD reached the scheduler output");
    end
    @(posedge clk);

    mem_request_count = 0;
    start_fetch(32'd0);
    $display("INFO: valid DFU request started");
    wait (fetch_rsp_valid);
    $display("INFO: valid DFU response observed");
    if ((fetch_rsp_status != NPU_STATUS_SUCCESS)
        || (fetch_rsp_id != fetch_id)
        || (mem_request_count != 32)) begin
      $fatal(1, "valid 256-byte Descriptor fetch failed");
    end
    for (int unsigned word_idx = 0; word_idx < 32; word_idx++) begin
      if (fetch_rsp_desc[word_idx*64 +: 64]
          != descriptor_words[word_idx]) begin
        $fatal(1, "DFU changed descriptor word %0d", word_idx);
      end
    end
    @(posedge clk);

    mem_request_count = 0;
    start_fetch(32'h0000_0100);
    $display("INFO: reserved accumulator encoding DFU request started");
    wait (fetch_rsp_valid);
    $display("INFO: reserved accumulator encoding DFU response observed");
    if ((fetch_rsp_status != NPU_STATUS_BAD_DESC)
        || (fetch_rsp_fault != fetch_addr)
        || (mem_request_count != 8)) begin
      $fatal(1, "reserved accumulator encoding was not rejected");
    end
    @(posedge clk);
    @(negedge clk);

    if (!cfe_idle || !dfu_idle || (cmd_accepted_count != 1)
        || (cfe_error_count != 2)) begin
      $fatal(
        1,
        "CFE/DFU state/count error: cfe_idle=%0b dfu_idle=%0b accepted=%0d errors=%0d",
        cfe_idle, dfu_idle, cmd_accepted_count, cfe_error_count
      );
    end

    $display("PASS: CFE atomic/timeout checks and DFU numeric checks");
    $finish;
  end

  initial begin
    #100000;
    $fatal(1, "smoke test timeout");
  end

endmodule
