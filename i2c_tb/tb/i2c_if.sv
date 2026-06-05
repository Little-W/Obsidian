interface i2c_if(input logic clk);
  int unsigned pclk_half_period_ns = 5;
  int unsigned ic_clk_half_period_ns = 50;

  logic rst_n;
  logic pclk;
  logic presetn;
  logic psel;
  logic penable;
  logic [2:0] pprot;
  logic [3:0] pstrb;
  logic pready;
  logic pslverr;
  logic [31:0] prdata;
  logic pwrite;
  logic [31:0] paddr;
  logic [31:0] pwdata;
  logic ic_clk;
  logic ic_rst_n;
  logic ic_current_src_en;
  logic ic_clk_in_a;
  logic ic_clk_oe;
  logic ic_data_in_a;
  logic ic_data_oe;
  logic ic_intr;
  logic ic_en;
endinterface
