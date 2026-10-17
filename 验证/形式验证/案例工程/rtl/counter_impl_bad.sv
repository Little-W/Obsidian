// Different module name from counter_impl; select it only in the broken example.
module counter_impl(input logic clk, rst_n, en, output logic [3:0] q);
  always_ff @(posedge clk or negedge rst_n)
    if (!rst_n) q <= 4'd0;
    else        q <= q + (en ? 4'd2 : 4'd0);
endmodule
