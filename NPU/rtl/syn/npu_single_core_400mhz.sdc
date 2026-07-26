set CORE_PERIOD_NS 2.500
set NOC_PERIOD_NS  2.500

create_clock -name CORE_CLK -period $CORE_PERIOD_NS \
  -waveform {0.000 1.250} [get_ports core_clk_i]
create_clock -name NOC_CLK -period $NOC_PERIOD_NS \
  -waveform {0.000 1.250} [get_ports noc_clk_i]

set_clock_uncertainty -setup 0.150 [get_clocks {CORE_CLK NOC_CLK}]
set_clock_uncertainty -hold  0.050 [get_clocks {CORE_CLK NOC_CLK}]
set_clock_transition 0.050 [get_clocks {CORE_CLK NOC_CLK}]

set non_data_inputs [get_ports {core_clk_i noc_clk_i reset_n}]
set timed_inputs [remove_from_collection [all_inputs] $non_data_inputs]
set_input_delay 0.250 -clock CORE_CLK $timed_inputs
set_output_delay 0.250 -clock CORE_CLK [all_outputs]
set_load 0.020 [all_outputs]

set_false_path -from [get_ports reset_n]

set_max_transition 0.300 [current_design]
set_max_fanout 32 [current_design]

# Both clock inputs are checked at 400 MHz.  No inter-clock false path is
# declared: any direct transfer between them remains visible in timing.
