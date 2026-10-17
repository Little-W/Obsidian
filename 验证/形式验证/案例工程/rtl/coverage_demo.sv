// FCA exercise: branch conditions and reachability.
// mode is intentionally unconstrained, unless the verification environment
// supplies an explicitly reviewed operating-mode assumption.
module coverage_demo (
  input  logic       clk,
  input  logic       rst_n,
  input  logic [1:0] mode,
  output logic [1:0] result
);
  always_comb begin
    result = 2'd0;
    case (mode)
      2'd0: result = 2'd1;
      2'd1: result = 2'd2;
      2'd2: result = 2'd3;
      default: result = 2'd0;
    endcase
  end
endmodule
