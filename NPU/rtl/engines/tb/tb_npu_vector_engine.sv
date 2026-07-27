module tb_npu_vector_engine;
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

  npu_vector_engine dut (
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

  task automatic put_s32(
    input integer address,
    input logic signed [31:0] value
  );
    begin
      l1.mem[address] = value[7:0];
      l1.mem[address + 1] = value[15:8];
      l1.mem[address + 2] = value[23:16];
      l1.mem[address + 3] = value[31:24];
    end
  endtask

  task automatic setup_int8_vector_task(
    input logic [7:0] task_opcode,
    input logic [63:0] dst_address,
    input logic [31:0] task_numeric_cfg,
    input logic [31:0] task_flags,
    input logic [63:0] src2_address,
    input logic [63:0] mask_address,
    input logic signed [31:0] task_scalar0,
    input logic signed [31:0] task_scalar1,
    input logic [7:0] task_compare_mode,
    input logic [7:0] task_mask_mode
  );
    begin
      opcode = task_opcode;
      desc = '0;
      put8('h00, 8'h01);
      put8('h01, 8'h03);
      put16('h02, 16'd192);
      put64('h08, 64'h100);
      put64('h10, 64'h120);
      put64('h18, src2_address);
      put64('h20, dst_address);
      put64('h28, mask_address);
      put32('h38, task_numeric_cfg);
      put32('h40, 32'd1);
      put32('h44, 32'd4);
      put32('h48, 32'd4);
      put32('h4c, task_flags);
      put32('h50, task_numeric_cfg[1:0] == NPU_DTYPE_INT16 ?
                    32'd2 : 32'd1);
      put32('h54, task_numeric_cfg[1:0] == NPU_DTYPE_INT16 ?
                    32'd8 : 32'd4);
      put32('h58, task_numeric_cfg[3:2] == NPU_DTYPE_INT16 ?
                    32'd2 : 32'd1);
      put32('h5c, task_numeric_cfg[3:2] == NPU_DTYPE_INT16 ?
                    32'd8 : 32'd4);
      put32('h60, 32'd4);
      put32('h64, 32'd16);
      put32('h68, task_numeric_cfg[7:6] == NPU_DTYPE_INT32 ?
                    32'd4 :
                    (task_numeric_cfg[7:6] == NPU_DTYPE_INT16 ?
                     32'd2 : 32'd1));
      put32('h6c, task_numeric_cfg[7:6] == NPU_DTYPE_INT32 ?
                    32'd16 :
                    (task_numeric_cfg[7:6] == NPU_DTYPE_INT16 ?
                     32'd8 : 32'd4));
      put32('h70, task_scalar0);
      put32('h74, task_scalar1);
      put8('h78, 8'd0);
      put8('h79, task_compare_mode);
      put8('h7a, 8'd0);
      put8('h7b, task_mask_mode);
      if (task_mask_mode == 8'd1) begin
        put32('h90, 32'd1);
        put32('h94, 32'd4);
      end
    end
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
        $fatal(1, "vector task_ready timeout");
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
        $fatal(1, "vector done timeout");
      if (done_status !== expected_status)
        $fatal(1, "vector status %02x expected %02x",
               done_status, expected_status);
      if (done_fault_addr !== 48'd0)
        $fatal(1, "vector unexpected fault address %012x",
               done_fault_addr);
    end
  endtask

  initial begin
    clk = 1'b0;
    reset_n = 1'b0;
    task_valid = 1'b0;
    done_ready = 1'b1;
    opcode = NPU_VECTOR_ADD;
    command_id = 12'h101;
    desc = '0;
    repeat (4) @(posedge clk);
    reset_n = 1'b1;

    l1.mem['h100] = 8'h01;
    l1.mem['h101] = 8'h02;
    l1.mem['h102] = 8'hfd;
    l1.mem['h103] = 8'h04;
    l1.mem['h120] = 8'h05;
    l1.mem['h121] = 8'hfe;
    l1.mem['h122] = 8'h07;
    l1.mem['h123] = 8'h08;

    put8('h00, 8'h01);
    put8('h01, 8'h03);
    put16('h02, 16'd192);
    put64('h08, 64'h100);
    put64('h10, 64'h120);
    put64('h20, 64'h140);
    put32('h38, 32'h0000_0045);
    put32('h40, 32'd1);
    put32('h44, 32'd4);
    put32('h48, 32'd4);
    put32('h50, 32'd1);
    put32('h54, 32'd4);
    put32('h58, 32'd1);
    put32('h5c, 32'd4);
    put32('h68, 32'd1);
    put32('h6c, 32'd4);
    put8('h7a, 8'd0);

    submit_and_expect(NPU_STATUS_SUCCESS);
    if (done_progress != 4)
      $fatal(1, "vector progress %0d expected 4", done_progress);
    if ($signed(l1.mem['h140]) != 6 ||
        $signed(l1.mem['h141]) != 0 ||
        $signed(l1.mem['h142]) != 4 ||
        $signed(l1.mem['h143]) != 12)
      $fatal(1, "vector ADD data mismatch: %0d %0d %0d %0d",
             $signed(l1.mem['h140]), $signed(l1.mem['h141]),
             $signed(l1.mem['h142]), $signed(l1.mem['h143]));

    desc['h38 * 8 + 8 +: 2] = 2'd1;
    submit_and_expect(NPU_STATUS_BAD_DESC);

    l1.mem['h200] = 8'hf8;
    l1.mem['h201] = 8'h10;
    l1.mem['h202] = 8'h07;
    l1.mem['h220] = 8'h21;
    l1.mem['h221] = 8'h4d;
    l1.mem['h222] = 8'h0f;
    desc = '0;
    opcode = NPU_VECTOR_ADD;
    put8('h00, 8'h01);
    put8('h01, 8'h03);
    put16('h02, 16'd192);
    put64('h08, 64'h200);
    put64('h10, 64'h220);
    put64('h20, 64'h240);
    put32('h38, 32'h0000_0000);
    put32('h40, 32'd1);
    put32('h44, 32'd5);
    put32('h48, 32'd5);
    put32('h50, 32'd0);
    put32('h54, 32'd3);
    put32('h58, 32'd0);
    put32('h5c, 32'd3);
    put32('h68, 32'd0);
    put32('h6c, 32'd3);
    put8('h7a, 8'd0);
    submit_and_expect(NPU_STATUS_SUCCESS);
    if (done_progress != 5)
      $fatal(1, "vector INT4 progress %0d expected 5",
             done_progress);
    if (l1.mem['h240] != 8'h19 ||
        l1.mem['h241] != 8'h5d ||
        l1.mem['h242] != 8'h06)
      $fatal(1, "vector INT4 ADD mismatch: %02x %02x %02x",
             l1.mem['h240], l1.mem['h241], l1.mem['h242]);

    setup_int8_vector_task(
      NPU_VECTOR_SUB, 64'h280, 32'h0000_0045, 32'd0,
      64'd0, 64'd0, 32'sd0, 32'sd0, 8'd0, 8'd0
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed(l1.mem['h280]) != -4 ||
        $signed(l1.mem['h281]) != 4 ||
        $signed(l1.mem['h282]) != -10 ||
        $signed(l1.mem['h283]) != -4)
      $fatal(1, "vector SUB mismatch");

    setup_int8_vector_task(
      NPU_VECTOR_MAX, 64'h290, 32'h0000_0045, 32'd0,
      64'd0, 64'd0, 32'sd0, 32'sd0, 8'd0, 8'd0
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed(l1.mem['h290]) != 5 ||
        $signed(l1.mem['h291]) != 2 ||
        $signed(l1.mem['h292]) != 7 ||
        $signed(l1.mem['h293]) != 8)
      $fatal(1, "vector MAX mismatch");

    setup_int8_vector_task(
      NPU_VECTOR_MIN, 64'h2a0, 32'h0000_0045, 32'd0,
      64'd0, 64'd0, 32'sd0, 32'sd0, 8'd0, 8'd0
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed(l1.mem['h2a0]) != 1 ||
        $signed(l1.mem['h2a1]) != -2 ||
        $signed(l1.mem['h2a2]) != -3 ||
        $signed(l1.mem['h2a3]) != 4)
      $fatal(1, "vector MIN mismatch");

    setup_int8_vector_task(
      NPU_VECTOR_CMP, 64'h2b0, 32'h0000_0045, 32'd0,
      64'd0, 64'd0, 32'sd0, 32'sd0, 8'd2, 8'd0
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if (l1.mem['h2b0] != 1 || l1.mem['h2b1] != 0 ||
        l1.mem['h2b2] != 1 || l1.mem['h2b3] != 1)
      $fatal(1, "vector CMP mismatch");

    l1.mem['h1e0] = 8'd0;
    l1.mem['h1e1] = 8'd1;
    l1.mem['h1e2] = 8'd0;
    l1.mem['h1e3] = 8'd1;
    setup_int8_vector_task(
      NPU_VECTOR_SELECT, 64'h2c0, 32'h0000_0045, 32'd1,
      64'd0, 64'h1e0, 32'sd0, 32'sd0, 8'd0, 8'd1
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed(l1.mem['h2c0]) != 1 ||
        $signed(l1.mem['h2c1]) != -2 ||
        $signed(l1.mem['h2c2]) != -3 ||
        $signed(l1.mem['h2c3]) != 8)
      $fatal(1, "vector SELECT mismatch");

    setup_int8_vector_task(
      NPU_VECTOR_CLAMP, 64'h2d0, 32'h0000_0045, 32'd0,
      64'd0, 64'd0, -32'sd1, 32'sd2, 8'd0, 8'd0
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed(l1.mem['h2d0]) != 1 ||
        $signed(l1.mem['h2d1]) != 2 ||
        $signed(l1.mem['h2d2]) != -1 ||
        $signed(l1.mem['h2d3]) != 2)
      $fatal(1, "vector CLAMP mismatch: %0d %0d %0d %0d",
             $signed(l1.mem['h2d0]), $signed(l1.mem['h2d1]),
             $signed(l1.mem['h2d2]), $signed(l1.mem['h2d3]));

    setup_int8_vector_task(
      NPU_VECTOR_RELU, 64'h2e0, 32'h0000_0045, 32'd0,
      64'd0, 64'd0, 32'sd0, 32'sd0, 8'd0, 8'd0
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed(l1.mem['h2e0]) != 1 ||
        $signed(l1.mem['h2e1]) != 2 ||
        $signed(l1.mem['h2e2]) != 0 ||
        $signed(l1.mem['h2e3]) != 4)
      $fatal(1, "vector RELU mismatch");

    setup_int8_vector_task(
      NPU_VECTOR_MUL, 64'h300, 32'h0000_0085, 32'd0,
      64'd0, 64'd0, 32'sd0, 32'sd0, 8'd0, 8'd0
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if (read_s32('h300) != 5 || read_s32('h304) != -4 ||
        read_s32('h308) != -21 || read_s32('h30c) != 32)
      $fatal(1, "vector MUL mismatch");

    put_s32('h340, 32'sd10);
    put_s32('h344, 32'sd20);
    put_s32('h348, 32'sd30);
    put_s32('h34c, 32'sd40);
    setup_int8_vector_task(
      NPU_VECTOR_FMA, 64'h380, 32'h0000_00a5, 32'd0,
      64'h340, 64'd0, 32'sd0, 32'sd0, 8'd0, 8'd0
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if (read_s32('h380) != 15 || read_s32('h384) != 16 ||
        read_s32('h388) != 9 || read_s32('h38c) != 72)
      $fatal(1, "vector FMA mismatch");

    l1.mem['h100] = 8'h2c;
    l1.mem['h101] = 8'h01;
    l1.mem['h102] = 8'h38;
    l1.mem['h103] = 8'hff;
    l1.mem['h104] = 8'hf8;
    l1.mem['h105] = 8'h7f;
    l1.mem['h106] = 8'h08;
    l1.mem['h107] = 8'h80;
    l1.mem['h120] = 8'h9c;
    l1.mem['h121] = 8'hff;
    l1.mem['h122] = 8'h32;
    l1.mem['h123] = 8'h00;
    l1.mem['h124] = 8'h0a;
    l1.mem['h125] = 8'h00;
    l1.mem['h126] = 8'hf6;
    l1.mem['h127] = 8'hff;
    setup_int8_vector_task(
      NPU_VECTOR_ADD, 64'h3c0, 32'h0000_00ff, 32'd0,
      64'd0, 64'd0, 32'sd0, 32'sd0, 8'd0, 8'd0
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed({l1.mem['h3c1], l1.mem['h3c0]}) != 16'sd200 ||
        $signed({l1.mem['h3c3], l1.mem['h3c2]}) != -16'sd150 ||
        $signed({l1.mem['h3c5], l1.mem['h3c4]}) != 16'sd32767 ||
        $signed({l1.mem['h3c7], l1.mem['h3c6]}) != -16'sd32768)
      $fatal(1, "vector INT16 ADD mismatch: %0d %0d %0d %0d",
             $signed({l1.mem['h3c1], l1.mem['h3c0]}),
             $signed({l1.mem['h3c3], l1.mem['h3c2]}),
             $signed({l1.mem['h3c5], l1.mem['h3c4]}),
             $signed({l1.mem['h3c7], l1.mem['h3c6]}));

    $display("tb_npu_vector_engine PASS");
    $finish;
  end

  initial begin
    #2ms;
    $fatal(1, "tb_npu_vector_engine global timeout");
  end
endmodule
