create_clock -name core_clk -period 10.000 [get_ports core_clk_i]
create_clock -name noc_clk  -period 10.000 [get_ports noc_clk_i]

# Out-of-Context implementation does not include the SoC-level clock
# buffers.  Give Vivado the intended core-clock BUFG location so that it can
# estimate insertion delay and clock skew, and run the clock-placement checks.
set_property HD.CLK_SRC BUFGCTRL_X0Y0 [get_ports core_clk_i]

set_clock_uncertainty 0.200 [get_clocks core_clk]
set_clock_uncertainty 0.200 [get_clocks noc_clk]
set_clock_groups -asynchronous \
  -group [get_clocks core_clk] \
  -group [get_clocks noc_clk]

set_false_path -from [get_ports reset_n]

set_input_delay 1.000 -clock core_clk [get_ports -filter {
  DIRECTION == IN
  && NAME != core_clk_i
  && NAME != noc_clk_i
  && NAME != reset_n
}]
set_output_delay 1.000 -clock core_clk [get_ports -filter {
  DIRECTION == OUT
}]
