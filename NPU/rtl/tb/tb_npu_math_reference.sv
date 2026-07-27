module tb_npu_math_reference;

  import npu_engine_pkg::*;

  integer checks_q;
  integer errors_q;
  logic clk_q;
  logic reset_n;
  logic req_valid;
  logic req_ready;
  logic rsp_valid;
  logic rsp_ready;
  logic [3:0] operation_q;
  logic [31:0] operand_q;
  logic [31:0] result;

  npu_complex_math_seq u_dut (
    .clk_i(clk_q),
    .reset_n(reset_n),
    .req_valid_i(req_valid),
    .req_ready_o(req_ready),
    .operation_i(operation_q),
    .operand0_i(operand_q),
    .operand1_i(32'd0),
    .rsp_valid_o(rsp_valid),
    .rsp_ready_i(rsp_ready),
    .result_o(result)
  );

  always #5 clk_q = ~clk_q;

  task automatic check_bits(
    input string       operation,
    input logic [3:0]  operation_code,
    input logic [31:0] operand,
    input logic [31:0] expected
  );
    integer timeout;
    begin
      while (!req_ready)
        @(posedge clk_q);
      @(negedge clk_q);
      operation_q = operation_code;
      operand_q = operand;
      req_valid = 1'b1;
      @(negedge clk_q);
      req_valid = 1'b0;
      timeout = 0;
      while (!rsp_valid && timeout < 10000) begin
        @(posedge clk_q);
        timeout = timeout + 1;
      end
      if (!rsp_valid)
        $fatal(1, "math timeout operation=%s operand=%08x",
               operation, operand);
      checks_q = checks_q + 1;
      if (result !== expected) begin
        errors_q = errors_q + 1;
        $display(
          "ERROR %s(%08x): RTL=%08x CModel=%08x",
          operation,
          operand,
          result,
          expected
        );
      end
      @(posedge clk_q);
    end
  endtask

  task automatic check_memory_status(
    input logic [2:0] memory_status,
    input logic [7:0] expected_task_status
  );
    logic [7:0] actual_task_status;
    begin
      actual_task_status = memory_status_to_task(memory_status);
      checks_q = checks_q + 1;
      if (actual_task_status !== expected_task_status) begin
        errors_q = errors_q + 1;
        $display(
          "ERROR memory status %0d: actual=%02x expected=%02x",
          memory_status,
          actual_task_status,
          expected_task_status
        );
      end
    end
  endtask

  initial begin
    clk_q = 1'b0;
    reset_n = 1'b0;
    req_valid = 1'b0;
    rsp_ready = 1'b1;
    operation_q = 4'd0;
    operand_q = 32'd0;
    checks_q = 0;
    errors_q = 0;
    repeat (4) @(posedge clk_q);
    reset_n = 1'b1;

    check_memory_status(3'd0, NPU_STATUS_SUCCESS);
    check_memory_status(3'd1, NPU_STATUS_ADDR_FAULT);
    check_memory_status(3'd2, NPU_STATUS_ADDR_FAULT);
    check_memory_status(3'd3, NPU_STATUS_BUS_SLVERR);
    check_memory_status(3'd4, NPU_STATUS_BUS_DECERR);
    check_memory_status(3'd5, NPU_STATUS_BAD_DESC);

    check_bits("exp", 4'd4, 32'hc188_0000, 32'h0000_0000);
    check_bits("exp", 4'd4, 32'hc180_0000, 32'h33f1_aade);
    check_bits("exp", 4'd4, 32'hbf80_0000, 32'h3ebc_5ab2);
    check_bits("exp", 4'd4, 32'h0000_0000, 32'h3f80_0000);
    check_bits("exp", 4'd4, 32'h3f80_0000, 32'h402d_f854);
    check_bits("exp", 4'd4, 32'h4180_0000, 32'h4b07_975f);
    check_bits("exp", 4'd4, 32'h7f80_0000, 32'h4b07_975f);
    check_bits("exp", 4'd4, 32'hff80_0000, 32'h0000_0000);
    check_bits("exp", 4'd4, 32'h7fc1_2345, 32'h0000_0000);

    check_bits("reciprocal", 4'd10, 32'h0000_0000, 32'h7f7f_ffff);
    check_bits("reciprocal", 4'd10, 32'h8000_0000, 32'hff7f_ffff);
    check_bits("reciprocal", 4'd10, 32'h3f80_0000, 32'h3f80_0000);
    check_bits("reciprocal", 4'd10, 32'hbf80_0000, 32'hbf80_0000);
    check_bits("reciprocal", 4'd10, 32'h4040_0000, 32'h3eaa_aaab);
    check_bits("reciprocal", 4'd10, 32'h0080_0000, 32'h7e80_0000);
    check_bits("reciprocal", 4'd10, 32'h0000_0001, 32'h7f7f_ffff);
    check_bits("reciprocal", 4'd10, 32'h7f7f_ffff, 32'h0020_0000);
    check_bits("reciprocal", 4'd10, 32'h7f80_0000, 32'h0000_0000);
    check_bits("reciprocal", 4'd10, 32'hff80_0000, 32'h8000_0000);
    check_bits("reciprocal", 4'd10, 32'h7fc1_2345, 32'h0000_0000);

    check_bits("sigmoid", 4'd0, 32'hc188_0000, 32'h0000_0000);
    check_bits("sigmoid", 4'd0, 32'hc180_0000, 32'h33f1_aadc);
    check_bits("sigmoid", 4'd0, 32'hbf80_0000, 32'h3e89_b2b1);
    check_bits("sigmoid", 4'd0, 32'h0000_0000, 32'h3f00_0000);
    check_bits("sigmoid", 4'd0, 32'h3f80_0000, 32'h3f3b_26a8);
    check_bits("sigmoid", 4'd0, 32'h4180_0000, 32'h3f7f_fffe);
    check_bits("sigmoid", 4'd0, 32'h7f80_0000, 32'h3f80_0000);
    check_bits("sigmoid", 4'd0, 32'hff80_0000, 32'h0000_0000);
    check_bits("sigmoid", 4'd0, 32'h7fc1_2345, 32'h0000_0000);

    check_bits("tanh", 4'd1, 32'hc188_0000, 32'hbf80_0000);
    check_bits("tanh", 4'd1, 32'hc180_0000, 32'hbf80_0000);
    check_bits("tanh", 4'd1, 32'hbf80_0000, 32'hbf42_f7d5);
    check_bits("tanh", 4'd1, 32'hbdcc_cccd, 32'hbdcc_1ebc);
    check_bits("tanh", 4'd1, 32'h8000_0000, 32'h8000_0000);
    check_bits("tanh", 4'd1, 32'h3dcc_cccd, 32'h3dcc_1ebc);
    check_bits("tanh", 4'd1, 32'h3e80_0000, 32'h3e7a_cbf5);
    check_bits("tanh", 4'd1, 32'h3f80_0000, 32'h3f42_f7d5);
    check_bits("tanh", 4'd1, 32'h7f80_0000, 32'h3f80_0000);
    check_bits("tanh", 4'd1, 32'hff80_0000, 32'hbf80_0000);
    check_bits("tanh", 4'd1, 32'h7fc1_2345, 32'h0000_0000);

    check_bits("gelu", 4'd2, 32'hc188_0000, 32'h0000_0000);
    check_bits("gelu", 4'd2, 32'hc180_0000, 32'h0000_0000);
    check_bits("gelu", 4'd2, 32'hc040_0000, 32'hbb6e_6080);
    check_bits("gelu", 4'd2, 32'hbf80_0000, 32'hbe22_9e90);
    check_bits("gelu", 4'd2, 32'h8000_0000, 32'h8000_0000);
    check_bits("gelu", 4'd2, 32'h3f80_0000, 32'h3f57_585c);
    check_bits("gelu", 4'd2, 32'h4040_0000, 32'h403f_c468);
    check_bits("gelu", 4'd2, 32'h7f80_0000, 32'h7f80_0000);
    check_bits("gelu", 4'd2, 32'hff80_0000, 32'h0000_0000);
    check_bits("gelu", 4'd2, 32'h7fc1_2345, 32'h0000_0000);

    check_bits("silu", 4'd3, 32'hc188_0000, 32'h0000_0000);
    check_bits("silu", 4'd3, 32'hc180_0000, 32'hb5f1_aadc);
    check_bits("silu", 4'd3, 32'hbf80_0000, 32'hbe89_b2b1);
    check_bits("silu", 4'd3, 32'h8000_0000, 32'h8000_0000);
    check_bits("silu", 4'd3, 32'h3f80_0000, 32'h3f3b_26a8);
    check_bits("silu", 4'd3, 32'h4180_0000, 32'h417f_fffe);
    check_bits("silu", 4'd3, 32'h7f80_0000, 32'h7f80_0000);
    check_bits("silu", 4'd3, 32'hff80_0000, 32'h0000_0000);
    check_bits("silu", 4'd3, 32'h7fc1_2345, 32'h0000_0000);

    check_bits("rsqrt", 4'd5, 32'h0000_0000, 32'h7f7f_ffff);
    check_bits("rsqrt", 4'd5, 32'h8000_0000, 32'h7f7f_ffff);
    check_bits("rsqrt", 4'd5, 32'hbf80_0000, 32'h7f7f_ffff);
    check_bits("rsqrt", 4'd5, 32'h3dcc_cccd, 32'h404a_62c3);
    check_bits("rsqrt", 4'd5, 32'h3f80_0000, 32'h3f7f_ffff);
    check_bits("rsqrt", 4'd5, 32'h4000_0000, 32'h3f35_04f3);
    check_bits("rsqrt", 4'd5, 32'h0080_0000, 32'h5eff_ffff);
    check_bits("rsqrt", 4'd5, 32'h0000_0001, 32'h64b5_04f3);
    check_bits("rsqrt", 4'd5, 32'h7f7f_ffff, 32'h1f80_0000);
    check_bits("rsqrt", 4'd5, 32'h7f80_0000, 32'h0000_0000);
    check_bits("rsqrt", 4'd5, 32'hff80_0000, 32'h7f7f_ffff);
    check_bits("rsqrt", 4'd5, 32'h7fc1_2345, 32'h0000_0000);

    if (errors_q != 0)
      $fatal(
        1,
        "math reference FAIL checks=%0d errors=%0d",
        checks_q,
        errors_q
      );
    $display("math reference PASS checks=%0d", checks_q);
    $finish;
  end

endmodule
