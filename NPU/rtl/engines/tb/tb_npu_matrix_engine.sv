module tb_npu_matrix_engine;
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

  npu_matrix_engine dut (
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
    .l1_rsp_status_i(l1_rsp_status)
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

  function automatic logic signed [31:0] read_s32(input integer address);
    return $signed({
      l1.mem[address + 3],
      l1.mem[address + 2],
      l1.mem[address + 1],
      l1.mem[address]
    });
  endfunction

  task automatic submit_and_expect(input logic [7:0] expected_status);
    integer timeout;
    begin
      timeout = 0;
      while (!task_ready && timeout < 1000) begin
        @(posedge clk);
        timeout = timeout + 1;
      end
      if (!task_ready)
        $fatal(1, "matrix task_ready timeout");
      @(negedge clk);
      task_valid = 1'b1;
      @(negedge clk);
      task_valid = 1'b0;
      timeout = 0;
      while (!done_valid && timeout < 20000) begin
        @(posedge clk);
        timeout = timeout + 1;
      end
      if (!done_valid)
        $fatal(1, "matrix done timeout");
      if (done_status !== expected_status)
        $fatal(1, "matrix status %02x expected %02x",
               done_status, expected_status);
    end
  endtask

  initial begin
    clk = 1'b0;
    reset_n = 1'b0;
    task_valid = 1'b0;
    done_ready = 1'b1;
    opcode = NPU_MATRIX_GEMM;
    command_id = 12'h301;
    desc = '0;
    repeat (4) @(posedge clk);
    reset_n = 1'b1;

    l1.mem[16'h100] = 8'd1;
    l1.mem[16'h101] = 8'd2;
    l1.mem[16'h102] = 8'd3;
    l1.mem[16'h103] = 8'd4;
    l1.mem[16'h120] = 8'd5;
    l1.mem[16'h121] = 8'd6;
    l1.mem[16'h122] = 8'd7;
    l1.mem[16'h123] = 8'd8;

    put8(16'h00, 8'h01);
    put8(16'h01, 8'h02);
    put16(16'h02, 16'd256);
    put64(16'h08, 64'h100);
    put64(16'h10, 64'h120);
    put64(16'h20, 64'h200);
    put32(16'h38, 32'h0000_0085);
    put32(16'h40, 32'd2);
    put32(16'h44, 32'd2);
    put32(16'h48, 32'd2);
    put32(16'h4c, 32'd1);
    put32(16'h50, 32'd2);
    put32(16'h54, 32'd2);
    put32(16'h58, 32'd2);
    put32(16'h5c, 32'h0000_0080);
    put32(16'h60, 32'd2);
    put32(16'h64, 32'd2);
    put32(16'h68, 32'd8);
    put8(16'h90, 8'd0);
    put8(16'h91, 8'd0);
    put8(16'h92, 8'd4);
    put8(16'h93, 8'd0);
    put8(16'h94, 8'd0);
    put8(16'h95, 8'd0);

    submit_and_expect(NPU_STATUS_SUCCESS);
    if (done_progress != 4)
      $fatal(1, "matrix progress %0d expected 4", done_progress);
    if (read_s32(16'h200) != 19 ||
        read_s32(16'h204) != 22 ||
        read_s32(16'h208) != 43 ||
        read_s32(16'h20c) != 50)
      $fatal(1, "matrix GEMM mismatch: %0d %0d %0d %0d",
             read_s32(16'h200), read_s32(16'h204),
             read_s32(16'h208), read_s32(16'h20c));

    desc[16'h38 * 8 + 8 +: 2] = 2'd1;
    submit_and_expect(NPU_STATUS_BAD_DESC);

    desc[16'h38 * 8 + 8 +: 2] = 2'd0;
    put8(16'h90, 8'd7);
    submit_and_expect(NPU_STATUS_BAD_DESC);

    l1.mem['h300] = 8'hf8;
    l1.mem['h301] = 8'h02;
    l1.mem['h320] = 8'he1;
    l1.mem['h321] = 8'h4d;
    l1.mem['h322] = 8'hf5;
    desc = '0;
    opcode = NPU_MATRIX_GEMM;
    put8('h00, 8'h01);
    put8('h01, 8'h02);
    put16('h02, 16'd256);
    put64('h08, 64'h300);
    put64('h10, 64'h320);
    put64('h20, 64'h380);
    put32('h38, 32'h0000_0080);
    put32('h40, 32'd1);
    put32('h44, 32'd2);
    put32('h48, 32'd3);
    put32('h4c, 32'd1);
    put32('h50, 32'd1);
    put32('h54, 32'd2);
    put32('h58, 32'd3);
    put32('h5c, 32'h0000_0080);
    put32('h60, 32'd2);
    put32('h64, 32'd1);
    put32('h68, 32'd8);
    put8('h90, 8'd1);
    put8('h91, 8'd1);
    put8('h92, 8'd4);
    put8('h93, 8'd0);
    put8('h94, 8'd0);
    put8('h95, 8'd0);
    submit_and_expect(NPU_STATUS_SUCCESS);
    if (done_progress != 2)
      $fatal(1, "matrix INT4 progress %0d expected 2",
             done_progress);
    if (read_s32('h380) != 5 || read_s32('h384) != 10)
      $fatal(1, "matrix INT4 GEMM mismatch: %0d %0d",
             read_s32('h380), read_s32('h384));

    l1.mem['h400] = 8'hfe;
    l1.mem['h401] = 8'h03;
    l1.mem['h420] = 8'hf4;
    l1.mem['h421] = 8'h00;
    l1.mem['h422] = 8'h00;
    l1.mem['h423] = 8'h00;
    l1.mem['h424] = 8'h2d;
    desc = '0;
    put8('h00, 8'h01);
    put8('h01, 8'h02);
    put16('h02, 16'd256);
    put64('h08, 64'h400);
    put64('h10, 64'h420);
    put64('h20, 64'h480);
    put32('h38, 32'h0000_0081);
    put32('h40, 32'd1);
    put32('h44, 32'd2);
    put32('h48, 32'd2);
    put32('h4c, 32'd1);
    put32('h50, 32'd1);
    put32('h54, 32'd2);
    put32('h58, 32'd2);
    put32('h5c, 32'h0000_0080);
    put32('h60, 32'd2);
    put32('h64, 32'd0);
    put32('h68, 32'd8);
    put8('h90, 8'd0);
    put8('h91, 8'd3);
    put8('h92, 8'd4);
    put8('h93, 8'd0);
    put8('h94, 8'd0);
    put8('h95, 8'd0);
    submit_and_expect(NPU_STATUS_SUCCESS);
    if (read_s32('h480) != -17 || read_s32('h484) != 8)
      $fatal(1, "matrix INT8xINT4 GEMM mismatch: %0d %0d",
             read_s32('h480), read_s32('h484));

    l1.mem['h600] = 8'h02;
    l1.mem['h601] = 8'h00;
    l1.mem['h602] = 8'hfd;
    l1.mem['h603] = 8'hff;
    l1.mem['h620] = 8'h04;
    l1.mem['h621] = 8'h00;
    l1.mem['h622] = 8'hff;
    l1.mem['h623] = 8'hff;
    l1.mem['h630] = 8'hfe;
    l1.mem['h631] = 8'hff;
    l1.mem['h632] = 8'h05;
    l1.mem['h633] = 8'h00;
    l1.mem['h680] = 8'h01;
    l1.mem['h681] = 8'h00;
    l1.mem['h682] = 8'h00;
    l1.mem['h683] = 8'h00;
    l1.mem['h684] = 8'h00;
    l1.mem['h685] = 8'h00;
    l1.mem['h686] = 8'h00;
    l1.mem['h687] = 8'h00;
    desc = '0;
    opcode = NPU_MATRIX_GEMM;
    put8('h00, 8'h01);
    put8('h01, 8'h02);
    put16('h02, 16'd256);
    put64('h08, 64'h600);
    put64('h10, 64'h620);
    put64('h20, 64'h660);
    put64('h30, 64'h680);
    put32('h38, 32'h0000_00cf);
    put32('h40, 32'd1);
    put32('h44, 32'd2);
    put32('h48, 32'd2);
    put32('h4c, 32'd1);
    put32('h50, 32'd1);
    put32('h54, 32'd2);
    put32('h58, 32'd2);
    put32('h5c, 32'h0000_00a0);
    put32('h60, 32'd4);
    put32('h64, 32'd4);
    put32('h68, 32'd4);
    put8('h90, 8'd5);
    put8('h91, 8'd6);
    put8('h92, 8'd5);
    put8('h93, 8'd0);
    put8('h94, 8'd0);
    put8('h95, 8'd0);
    put32('h9c, 32'd1);
    put32('ha0, 32'd0);
    put8('ha4, 8'd1);
    put8('ha5, 8'd0);
    put8('ha6, 8'd8);
    put32('ha8, 32'd8);
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed({l1.mem['h661], l1.mem['h660]}) != 16'sd14 ||
        $signed({l1.mem['h663], l1.mem['h662]}) != -16'sd17)
      $fatal(1, "matrix INT16 pack5/pack6 mismatch: %0d %0d",
             $signed({l1.mem['h661], l1.mem['h660]}),
             $signed({l1.mem['h663], l1.mem['h662]}));

    $display("tb_npu_matrix_engine PASS");
    $finish;
  end

  initial begin
    #2ms;
    $fatal(1, "tb_npu_matrix_engine global timeout");
  end
endmodule
