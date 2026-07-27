module tb_npu_math_reference;

  import npu_engine_pkg::*;

  integer checks_q;
  integer errors_q;
  logic [3:0] operation_q;
  logic [31:0] operand_q;
  logic [31:0] result;

  npu_complex_math_core u_dut (
    .operation_i(operation_q),
    .operand0_i(operand_q),
    .operand1_i(32'd0),
    .result_o(result)
  );

  task automatic check_bits(
    input string       operation,
    input logic [3:0]  operation_code,
    input logic [31:0] operand,
    input logic [31:0] expected
  );
    begin
      operation_q = operation_code;
      operand_q = operand;
      #1;
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
    end
  endtask

  initial begin
    checks_q = 0;
    errors_q = 0;

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
