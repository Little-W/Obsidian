module tb_npu_complex_engine;
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

  npu_complex_engine dut (
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

  task automatic submit_and_expect(input logic [7:0] expected_status);
    integer timeout;
    begin
      timeout = 0;
      while (!task_ready && timeout < 1000) begin
        @(posedge clk);
        timeout = timeout + 1;
      end
      if (!task_ready)
        $fatal(1, "complex task_ready timeout");
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
        $fatal(1, "complex done timeout");
      if (done_status !== expected_status)
        $fatal(1, "complex status %02x expected %02x",
               done_status, expected_status);
      if (done_fault_addr !== 48'd0)
        $fatal(1, "complex unexpected fault address %012x",
               done_fault_addr);
    end
  endtask

  task automatic setup_fp_task(
    input logic [7:0] task_opcode,
    input logic [31:0] task_function,
    input logic [63:0] src0_address,
    input logic [63:0] src1_address,
    input logic [63:0] src2_address,
    input logic [63:0] dst_address,
    input logic [31:0] element_count,
    input logic [31:0] src0_scale,
    input logic [31:0] src1_scale,
    input logic [31:0] src2_scale,
    input logic [31:0] dst_scale,
    input logic [31:0] epsilon
  );
    begin
      opcode = task_opcode;
      desc = '0;
      put8('h00, 8'h01);
      put8('h01, 8'h04);
      put16('h02, 16'd256);
      put64('h08, src0_address);
      put64('h10, src1_address);
      put64('h18, src2_address);
      put64('h20, dst_address);
      put32('h38, 32'h0001_3055);
      put32('h40, 32'd1);
      put32('h44, element_count);
      put32('h48, element_count);
      put32('h4c, task_function);
      put32('h50, element_count);
      put32('h54, 32'd0);
      put32('h58, 32'd0);
      put32('h5c, element_count);
      put32('h6c, 32'd0);
      put32('h70, src0_scale);
      put32('h74, src1_scale);
      put32('h78, src2_scale);
      put32('h7c, dst_scale);
      put32('h90, epsilon);
      if (task_opcode == NPU_COMPLEX_ACT ||
          task_opcode == NPU_COMPLEX_SOFTMAX) begin
        put32('h94, 32'hc180_0000);
        put32('h98, 32'h4180_0000);
      end
      put8('h9c, 8'd0);
      put8('h9d, 8'd0);
      put8('h9e, 8'd0);
      put8('h9f, 8'd0);
    end
  endtask

  initial begin
    clk = 1'b0;
    reset_n = 1'b0;
    task_valid = 1'b0;
    done_ready = 1'b1;
    opcode = NPU_COMPLEX_ACT;
    command_id = 12'h401;
    desc = '0;
    repeat (4) @(posedge clk);
    reset_n = 1'b1;

    l1.mem['h100] = 8'hfe;
    l1.mem['h101] = 8'h00;
    l1.mem['h102] = 8'h02;

    setup_fp_task(
      NPU_COMPLEX_ACT, 32'd0,
      64'h100, 64'd0, 64'd0, 64'h180, 32'd3,
      32'h3f80_0000, 32'd0, 32'd0, 32'h3e80_0000, 32'd0
    );

    submit_and_expect(NPU_STATUS_SUCCESS);
    if (done_progress != 3)
      $fatal(1, "complex progress %0d expected 3", done_progress);
    if ($signed(l1.mem['h180]) != 0 ||
        $signed(l1.mem['h181]) != 2 ||
        $signed(l1.mem['h182]) != 4)
      $fatal(1, "complex sigmoid mismatch: %0d %0d %0d",
             $signed(l1.mem['h180]),
             $signed(l1.mem['h181]),
             $signed(l1.mem['h182]));

    setup_fp_task(
      NPU_COMPLEX_ACT, 32'd1,
      64'h100, 64'd0, 64'd0, 64'h190, 32'd3,
      32'h3f80_0000, 32'd0, 32'd0, 32'h3e80_0000, 32'd0
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed(l1.mem['h190]) != -4 ||
        $signed(l1.mem['h191]) != 0 ||
        $signed(l1.mem['h192]) != 4)
      $fatal(1, "complex tanh mismatch: %0d %0d %0d",
             $signed(l1.mem['h190]),
             $signed(l1.mem['h191]),
             $signed(l1.mem['h192]));

    l1.mem['h110] = 8'd0;
    l1.mem['h111] = 8'd0;
    setup_fp_task(
      NPU_COMPLEX_SOFTMAX, 32'd4,
      64'h110, 64'd0, 64'd0, 64'h1a0, 32'd2,
      32'h3f80_0000, 32'd0, 32'd0, 32'h3e80_0000, 32'd0
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed(l1.mem['h1a0]) != 2 ||
        $signed(l1.mem['h1a1]) != 2)
      $fatal(1, "complex softmax mismatch: %0d %0d",
             $signed(l1.mem['h1a0]),
             $signed(l1.mem['h1a1]));

    l1.mem['h120] = 8'hff;
    l1.mem['h121] = 8'h01;
    l1.mem['h130] = 8'h01;
    l1.mem['h131] = 8'h01;
    l1.mem['h140] = 8'h00;
    l1.mem['h141] = 8'h00;
    setup_fp_task(
      NPU_COMPLEX_NORM, 32'd5,
      64'h120, 64'h130, 64'h140, 64'h1b0, 32'd2,
      32'h3f80_0000, 32'h3f80_0000,
      32'h3f80_0000, 32'h3f80_0000, 32'h38d1_b717
    );
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed(l1.mem['h1b0]) != -1 ||
        $signed(l1.mem['h1b1]) != 1)
      $fatal(1, "complex layernorm mismatch: %0d %0d",
             $signed(l1.mem['h1b0]),
             $signed(l1.mem['h1b1]));

    setup_fp_task(
      NPU_COMPLEX_ACT, 32'd0,
      64'h100, 64'd0, 64'd0, 64'h1c0, 32'd3,
      32'h7fc0_0000, 32'd0, 32'd0, 32'h3e80_0000, 32'd0
    );
    submit_and_expect(NPU_STATUS_BAD_DESC);
    if (done_progress != 0)
      $fatal(1, "invalid FP32 scale changed progress");

    put32('h70, 32'h3f80_0000);
    desc['h38 * 8 + 8 +: 2] = 2'd1;
    submit_and_expect(NPU_STATUS_BAD_DESC);

    l1.mem['h200] = 8'hfe;
    l1.mem['h201] = 8'hff;
    l1.mem['h202] = 8'h02;
    l1.mem['h203] = 8'h00;
    setup_fp_task(
      NPU_COMPLEX_ACT, 32'd0,
      64'h200, 64'd0, 64'd0, 64'h220, 32'd2,
      32'h3f80_0000, 32'd0, 32'd0, 32'h3e80_0000, 32'd0
    );
    put32('h38, 32'h0001_30c3);
    submit_and_expect(NPU_STATUS_SUCCESS);
    if ($signed({l1.mem['h221], l1.mem['h220]}) != 16'sd0 ||
        $signed({l1.mem['h223], l1.mem['h222]}) != 16'sd4)
      $fatal(1, "complex INT16 sigmoid mismatch: %0d %0d",
             $signed({l1.mem['h221], l1.mem['h220]}),
             $signed({l1.mem['h223], l1.mem['h222]}));

    $display("tb_npu_complex_engine PASS");
    $finish;
  end

  initial begin
    #2ms;
    $fatal(1, "tb_npu_complex_engine global timeout");
  end
endmodule
