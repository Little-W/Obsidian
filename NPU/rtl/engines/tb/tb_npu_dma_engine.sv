module tb_npu_dma_engine;
  import npu_engine_pkg::*;

  logic clk;
  logic reset_n;
  logic task_valid;
  logic task_ready;
  logic [7:0] opcode;
  logic [11:0] command_id;
  logic [2047:0] desc;
  logic done_valid;
  logic done_ready;
  logic [7:0] done_status;
  logic [47:0] done_fault_addr;
  logic [63:0] done_progress;

  logic l1_req_valid;
  logic l1_req_ready;
  logic l1_req_write;
  logic [19:0] l1_req_addr;
  logic [63:0] l1_req_wdata;
  logic [7:0] l1_req_wstrb;
  logic l1_rsp_valid;
  logic l1_rsp_ready;
  logic [63:0] l1_rsp_rdata;
  logic [2:0] l1_rsp_status;

  logic mif_req_valid;
  logic mif_req_ready;
  logic mif_req_write;
  logic [47:0] mif_req_addr;
  logic [63:0] mif_req_wdata;
  logic [7:0] mif_req_wstrb;
  logic mif_rsp_valid;
  logic mif_rsp_ready;
  logic [63:0] mif_rsp_rdata;
  logic [2:0] mif_rsp_status;

  npu_dma_engine dut (
    .clk_i(clk),
    .reset_n(reset_n),
    .task_valid_i(task_valid),
    .task_ready_o(task_ready),
    .opcode_i(opcode),
    .command_id_i(command_id),
    .desc_i(desc),
    .done_valid_o(done_valid),
    .done_ready_i(done_ready),
    .done_status_o(done_status),
    .done_fault_addr_o(done_fault_addr),
    .done_progress_o(done_progress),
    .l1_req_valid_o(l1_req_valid),
    .l1_req_ready_i(l1_req_ready),
    .l1_req_write_o(l1_req_write),
    .l1_req_addr_o(l1_req_addr),
    .l1_req_wdata_o(l1_req_wdata),
    .l1_req_wstrb_o(l1_req_wstrb),
    .l1_rsp_valid_i(l1_rsp_valid),
    .l1_rsp_ready_o(l1_rsp_ready),
    .l1_rsp_rdata_i(l1_rsp_rdata),
    .l1_rsp_status_i(l1_rsp_status),
    .mif_req_valid_o(mif_req_valid),
    .mif_req_ready_i(mif_req_ready),
    .mif_req_write_o(mif_req_write),
    .mif_req_addr_o(mif_req_addr),
    .mif_req_wdata_o(mif_req_wdata),
    .mif_req_wstrb_o(mif_req_wstrb),
    .mif_rsp_valid_i(mif_rsp_valid),
    .mif_rsp_ready_o(mif_rsp_ready),
    .mif_rsp_rdata_i(mif_rsp_rdata),
    .mif_rsp_status_i(mif_rsp_status)
  );

  npu_single_beat_memory_model #(
    .ADDR_W(20),
    .MEM_BYTES(4096)
  ) l1 (
    .clk_i(clk),
    .reset_n(reset_n),
    .req_valid_i(l1_req_valid),
    .req_ready_o(l1_req_ready),
    .req_write_i(l1_req_write),
    .req_addr_i(l1_req_addr),
    .req_wdata_i(l1_req_wdata),
    .req_wstrb_i(l1_req_wstrb),
    .rsp_valid_o(l1_rsp_valid),
    .rsp_ready_i(l1_rsp_ready),
    .rsp_rdata_o(l1_rsp_rdata),
    .rsp_status_o(l1_rsp_status)
  );

  npu_single_beat_memory_model #(
    .ADDR_W(48),
    .MEM_BYTES(4096)
  ) mif (
    .clk_i(clk),
    .reset_n(reset_n),
    .req_valid_i(mif_req_valid),
    .req_ready_o(mif_req_ready),
    .req_write_i(mif_req_write),
    .req_addr_i(mif_req_addr),
    .req_wdata_i(mif_req_wdata),
    .req_wstrb_i(mif_req_wstrb),
    .rsp_valid_o(mif_rsp_valid),
    .rsp_ready_i(mif_rsp_ready),
    .rsp_rdata_o(mif_rsp_rdata),
    .rsp_status_o(mif_rsp_status)
  );

  always #5 clk = ~clk;

  task automatic put8(input integer offset, input logic [7:0] value);
    desc[offset * 8 +: 8] = value;
  endtask

  task automatic put16(input integer offset, input logic [15:0] value);
    desc[offset * 8 +: 16] = value;
  endtask

  task automatic put32(input integer offset, input logic [31:0] value);
    desc[offset * 8 +: 32] = value;
  endtask

  task automatic put64(input integer offset, input logic [63:0] value);
    desc[offset * 8 +: 64] = value;
  endtask

  task automatic submit_and_expect(input logic [7:0] expected_status);
    integer timeout;
    begin
      timeout = 0;
      while (!task_ready && timeout < 1000) begin
        @(posedge clk);
        timeout = timeout + 1;
      end
      if (!task_ready)
        $fatal(1, "dma task_ready timeout");
      @(negedge clk);
      task_valid = 1'b1;
      @(negedge clk);
      task_valid = 1'b0;
      timeout = 0;
      while (!done_valid && timeout < 10000) begin
        @(posedge clk);
        timeout = timeout + 1;
      end
      if (!done_valid)
        $fatal(1, "dma done timeout");
      if (done_status !== expected_status)
        $fatal(1, "dma status %02x expected %02x",
               done_status, expected_status);
    end
  endtask

  initial begin
    clk = 1'b0;
    reset_n = 1'b0;
    task_valid = 1'b0;
    done_ready = 1'b1;
    opcode = NPU_DMA_COPY_1D;
    command_id = 12'h201;
    desc = '0;
    repeat (4) @(posedge clk);
    reset_n = 1'b1;

    l1.mem[16'h100] = 8'h81;
    l1.mem[16'h101] = 8'h02;
    l1.mem[16'h102] = 8'h7f;
    l1.mem[16'h103] = 8'h55;

    put8(16'h00, 8'h01);
    put8(16'h01, 8'h01);
    put16(16'h02, 16'd256);
    put64(16'h08, 64'h100);
    put64(16'h20, 64'h200);
    put32(16'h38, 32'h0000_0041);
    put8(16'h40, 8'd1);
    put8(16'h41, 8'd0);
    put8(16'h42, 8'd0);
    put8(16'h43, 8'd0);
    put8(16'h44, 8'd0);
    put8(16'h45, 8'd1);
    put32(16'h48, 32'd4);
    put64(16'h98, 64'd4);
    put64(16'ha0, 64'd4);

    submit_and_expect(NPU_STATUS_SUCCESS);
    if (done_progress != 4)
      $fatal(1, "DMA progress %0d expected 4", done_progress);
    if (l1.mem[16'h200] != 8'h81 ||
        l1.mem[16'h201] != 8'h02 ||
        l1.mem[16'h202] != 8'h7f ||
        l1.mem[16'h203] != 8'h55)
      $fatal(1, "DMA COPY_1D data mismatch");

    desc[16'h38 * 8 + 8 +: 2] = 2'd1;
    submit_and_expect(NPU_STATUS_BAD_DESC);

    l1.mem['h300] = 8'hf8;
    l1.mem['h301] = 8'hff;
    l1.mem['h302] = 8'h00;
    l1.mem['h303] = 8'h07;
    l1.mem['h304] = 8'h03;
    desc = '0;
    opcode = NPU_DMA_COPY_1D;
    put8('h00, 8'h01);
    put8('h01, 8'h01);
    put16('h02, 16'd256);
    put64('h08, 64'h300);
    put64('h20, 64'h340);
    put32('h38, 32'h0000_0001);
    put8('h40, 8'd1);
    put8('h41, 8'd0);
    put8('h42, 8'd0);
    put8('h43, 8'd3);
    put8('h44, 8'd0);
    put8('h45, 8'd1);
    put32('h48, 32'd5);
    put64('h98, 64'd5);
    put64('ha0, 64'd3);
    submit_and_expect(NPU_STATUS_SUCCESS);
    if (done_progress != 3)
      $fatal(1, "DMA INT4 pack progress %0d expected 3",
             done_progress);
    if (l1.mem['h340] != 8'hf8 ||
        l1.mem['h341] != 8'h70 ||
        l1.mem['h342] != 8'h03)
      $fatal(1, "DMA INT4 pack mismatch: %02x %02x %02x",
             l1.mem['h340], l1.mem['h341], l1.mem['h342]);

    l1.mem['h500] = 8'h34;
    l1.mem['h501] = 8'h12;
    l1.mem['h502] = 8'hfe;
    l1.mem['h503] = 8'hff;
    l1.mem['h504] = 8'h30;
    l1.mem['h505] = 8'h75;
    desc = '0;
    opcode = NPU_DMA_COPY_1D;
    put8('h00, 8'h01);
    put8('h01, 8'h01);
    put16('h02, 16'd256);
    put64('h08, 64'h500);
    put64('h20, 64'h520);
    put32('h38, 32'h0000_00c3);
    put8('h40, 8'd1);
    put8('h41, 8'd0);
    put8('h42, 8'd0);
    put8('h43, 8'd0);
    put8('h44, 8'd0);
    put8('h45, 8'd1);
    put32('h48, 32'd3);
    put64('h98, 64'd6);
    put64('ha0, 64'd6);
    submit_and_expect(NPU_STATUS_SUCCESS);
    if (done_progress != 6)
      $fatal(1, "DMA INT16 progress %0d expected 6",
             done_progress);
    if (l1.mem['h520] != 8'h34 || l1.mem['h521] != 8'h12 ||
        l1.mem['h522] != 8'hfe || l1.mem['h523] != 8'hff ||
        l1.mem['h524] != 8'h30 || l1.mem['h525] != 8'h75)
      $fatal(1, "DMA INT16 COPY_1D mismatch");

    $display("tb_npu_dma_engine PASS");
    $finish;
  end

  initial begin
    #2ms;
    $fatal(1, "tb_npu_dma_engine global timeout");
  end
endmodule
