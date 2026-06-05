module i2c_bind_if_checker (
  input logic pclk,
  input logic presetn,
  input logic ic_clk,
  input logic ic_rst_n,
  input logic ic_intr,
  input logic ic_en
);
  property p_i2c_status_known;
    @(posedge ic_clk) ic_rst_n |-> !$isunknown({ic_intr, ic_en});
  endproperty

  property p_apb_reset_known;
    @(posedge pclk) !$isunknown(presetn);
  endproperty

  a_i2c_status_known: assert property (p_i2c_status_known);
  a_apb_reset_known: assert property (p_apb_reset_known);
endmodule
