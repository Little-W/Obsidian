# Change names
change_names -rule verilog -hierarchy

# Generate some reports
report_scan_configuration > reports/scan_config
report_dft_signal -view exist > reports/dft_signals
report_dft_signal -view spec >> reports/dft_signals
report_scan_path -view existing_dft -chain all > reports/scan_chains
report_scan_path -view existing_dft -cell all > reports/scan_cells

# Write a Verilog netlist
set test_stil_netlist_format verilog
write -f verilog -h -o tmax/ORCA_scan.v


# Write the ddc design
write -format ddc -hierarchy -output mapped_scan/ORCA.ddc
