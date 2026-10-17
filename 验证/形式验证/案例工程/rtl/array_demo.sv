// Deliberately has an index range wider than the 2-element memory.
module array_demo (
  input  logic       clk,
  input  logic [1:0] index,
  output logic [7:0] data_out
);
  logic [7:0] mem [0:1];
  always_ff @(posedge clk)
    data_out <= mem[index];
endmodule
