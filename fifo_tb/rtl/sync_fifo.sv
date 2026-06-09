module sync_fifo #(
  parameter int DATA_WIDTH = 8,
  parameter int DEPTH = 16,
  parameter int ALMOST_FULL_LEVEL = DEPTH - 1,
  parameter int ALMOST_EMPTY_LEVEL = 1
) (
  input  logic                         clk,
  input  logic                         rst_n,
  input  logic                         wr_en,
  input  logic                         rd_en,
  input  logic [DATA_WIDTH-1:0]        wdata,
  output logic [DATA_WIDTH-1:0]        rdata,
  output logic                         full,
  output logic                         empty,
  output logic                         almost_full,
  output logic                         almost_empty,
  output logic [$clog2(DEPTH+1)-1:0]   level,
  output logic                         overflow,
  output logic                         underflow
);
  localparam int ADDR_WIDTH = (DEPTH <= 2) ? 1 : $clog2(DEPTH);
  typedef logic [ADDR_WIDTH-1:0] ptr_t;

  logic [DATA_WIDTH-1:0] mem [0:DEPTH-1];
  ptr_t wr_ptr;
  ptr_t rd_ptr;
  logic do_write;
  logic do_read;

  assign empty = (level == '0);
  assign full = (level == DEPTH);
  assign almost_empty = (level <= ALMOST_EMPTY_LEVEL);
  assign almost_full = (level >= ALMOST_FULL_LEVEL);

  assign do_read = rd_en && !empty;
  assign do_write = wr_en && (!full || do_read);

  function automatic ptr_t ptr_inc(input ptr_t ptr);
    if (ptr == ptr_t'(DEPTH - 1)) begin
      return '0;
    end
    return ptr + ptr_t'(1);
  endfunction

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      wr_ptr <= '0;
      rd_ptr <= '0;
      rdata <= '0;
      level <= '0;
      overflow <= 1'b0;
      underflow <= 1'b0;
    end else begin
      overflow <= wr_en && full && !do_read;
      underflow <= rd_en && empty;

      if (do_write) begin
        mem[wr_ptr] <= wdata;
        wr_ptr <= ptr_inc(wr_ptr);
      end

      if (do_read) begin
        rdata <= mem[rd_ptr];
        rd_ptr <= ptr_inc(rd_ptr);
      end

      unique case ({do_write, do_read})
        2'b10: level <= level + 1'b1;
        2'b01: level <= level - 1'b1;
        default: level <= level;
      endcase
    end
  end
endmodule
