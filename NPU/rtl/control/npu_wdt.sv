module npu_wdt (
  input  logic        clk_i,
  input  logic        reset_n,
  input  logic        wdt_enable_i,
  input  logic [31:0] wdt_timeout_cycles_i,
  input  logic        wdt_kick_i,
  input  logic        wdt_core_progress_i,
  output logic        wdt_timeout_o,
  output logic        wdt_reset_req_o
);

  logic [31:0] counter_q;
  logic timeout_q;

  assign wdt_timeout_o   = timeout_q;
  assign wdt_reset_req_o = timeout_q;

  always_ff @(posedge clk_i) begin
    if (!reset_n) begin
      counter_q <= 32'd0;
      timeout_q <= 1'b0;
    end else if (!wdt_enable_i || (wdt_timeout_cycles_i == 32'd0)) begin
      counter_q <= 32'd0;
      timeout_q <= 1'b0;
    end else if (wdt_kick_i || wdt_core_progress_i) begin
      counter_q <= 32'd0;
      timeout_q <= 1'b0;
    end else if (!timeout_q) begin
      if (counter_q >= (wdt_timeout_cycles_i - 1'b1)) begin
        counter_q <= counter_q;
        timeout_q <= 1'b1;
      end else begin
        counter_q <= counter_q + 1'b1;
      end
    end
  end

endmodule
