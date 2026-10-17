module fifo_ctrl #(
    parameter int DEPTH = 4,
    parameter int CW = $clog2(DEPTH + 1)
) (
    input logic clk, rst_n,
    input logic push, pop,
    output logic full, empty,
    output logic push_accept, pop_accept,
    output logic [CW-1:0] occupancy
);
  assign full       = (occupancy == DEPTH);
  assign empty      = (occupancy == 0);
  assign pop_accept  = pop && !empty;
  assign push_accept = push && (!full || pop_accept);

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) occupancy <= '0;
    else case ({push_accept, pop_accept})
      2'b10: occupancy <= occupancy + 1'b1;
      2'b01: occupancy <= occupancy - 1'b1;
      default: occupancy <= occupancy;
    endcase
  end
endmodule
