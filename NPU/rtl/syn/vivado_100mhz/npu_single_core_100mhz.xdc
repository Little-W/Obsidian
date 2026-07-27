create_clock -name core_clk -period 10.000 [get_ports core_clk_i]
create_clock -name noc_clk  -period 10.000 [get_ports noc_clk_i]

set_clock_uncertainty 0.200 [get_clocks core_clk]
set_clock_uncertainty 0.200 [get_clocks noc_clk]
set_clock_groups -asynchronous \
  -group [get_clocks core_clk] \
  -group [get_clocks noc_clk]

set_false_path -from [get_ports reset_n]

set all_inputs [get_ports -filter {DIRECTION == IN}]
set all_outputs [get_ports -filter {DIRECTION == OUT}]
set clock_reset_ports [get_ports {core_clk_i noc_clk_i reset_n}]
set data_inputs [remove_from_collection $all_inputs $clock_reset_ports]
set noc_inputs [get_ports -quiet -filter {
  DIRECTION == IN && NAME =~ m_axi_*
}]
set noc_outputs [get_ports -quiet -filter {
  DIRECTION == OUT && NAME =~ m_axi_*
}]
set core_inputs [remove_from_collection $data_inputs $noc_inputs]
set core_outputs [remove_from_collection $all_outputs $noc_outputs]

set_input_delay 1.000 -clock core_clk $core_inputs
set_output_delay 1.000 -clock core_clk $core_outputs
set_input_delay 1.000 -clock noc_clk $noc_inputs
set_output_delay 1.000 -clock noc_clk $noc_outputs

