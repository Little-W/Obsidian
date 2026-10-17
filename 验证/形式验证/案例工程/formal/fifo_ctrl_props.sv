module fifo_ctrl_props #(
  parameter int DEPTH = 4,
  parameter int CW = $clog2(DEPTH + 1)
) (
  input logic clk, rst_n, push, pop,
  input logic full, empty, push_accept, pop_accept,
  input logic [CW-1:0] occupancy
);
  ap_safe_count: assert property (@(posedge clk) disable iff (!rst_n)
    occupancy <= DEPTH);
  ap_flag_full: assert property (@(posedge clk) disable iff (!rst_n)
    full == (occupancy == DEPTH));
  ap_flag_empty: assert property (@(posedge clk) disable iff (!rst_n)
    empty == (occupancy == 0));
  ap_no_empty_pop: assert property (@(posedge clk) disable iff (!rst_n)
    pop_accept |-> !empty);
  ap_no_overflow_push: assert property (@(posedge clk) disable iff (!rst_n)
    push_accept |-> (!full || pop_accept));
  cp_full: cover property (@(posedge clk) disable iff (!rst_n)
    full);
  cp_empty_after_use: cover property (@(posedge clk) disable iff (!rst_n)
    !empty ##[1:5] empty);
endmodule

bind fifo_ctrl fifo_ctrl_props #(.DEPTH(DEPTH), .CW(CW)) u_fifo_ctrl_props (.*);
