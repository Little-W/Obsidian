interface fifo_if (
  input logic clk
);
  localparam int DATA_WIDTH = 8;
  localparam int DEPTH = 16;

  logic rst_n;
  logic wr_en;
  logic rd_en;
  logic [DATA_WIDTH-1:0] wdata;
  logic [DATA_WIDTH-1:0] rdata;
  logic full;
  logic empty;
  logic almost_full;
  logic almost_empty;
  logic [$clog2(DEPTH+1)-1:0] level;
  logic overflow;
  logic underflow;
endinterface
