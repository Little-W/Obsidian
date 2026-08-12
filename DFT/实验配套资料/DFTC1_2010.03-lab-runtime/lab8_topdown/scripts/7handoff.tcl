change_names -rule verilog -hierarchy
report_dft > reports/dft
report_scan_configuration > reports/scan_config
report_dft_signal -view existing_dft > reports/dft_signals
report_scan_path -view existing_dft -chain all > reports/scan_chains
report_scan_path -view existing_dft -cell all > reports/scan_cells
set test_stil_netlist_format verilog ;# hand off
write -f verilog -h -o tmax/ORCA_scan.v
write_test_protocol -o tmax/ORCA_scan.spf
write -format ddc -hierarchy -output mapped_scan/ORCA.ddc
