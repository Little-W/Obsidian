bind MCU_I2C_WRAPPER i2c_bind_if_checker u_i2c_bind_if_checker (
  .pclk(pclk),
  .presetn(presetn),
  .ic_clk(ic_clk),
  .ic_rst_n(ic_rst_n),
  .ic_intr(ic_intr),
  .ic_en(ic_en)
);
