alias s "source -echo -verbose"
sh cat scripts/4read_gate_and_protocol.tcl
s 4read_gate_and_protocol.tcl
report_scan_state
report_dft_signal -view exist
report_dft_signal -view spec
source settings_protocol.tcl
preview_dft
preview_dft -show scan_clocks
preview_dft -show scan_summary
set_scan_configuration -clock_mix mix_edges
preview_dft -show scan_clocks
set_scan_configuration -clock_mix mix_clocks
preview_dft -show scan_clocks
set_scan_configuration -chain_count 6
preview_dft -show scan_clocks
s settings_insert_dft.tcl
set_dft_insertion_configuration -preserve_design_name true -synthesis none
s 6insert_dft.tcl
