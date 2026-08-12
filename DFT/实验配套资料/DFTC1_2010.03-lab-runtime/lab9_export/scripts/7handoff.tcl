# Generate reports required by downstream test and physical-design tools.
report_scan_configuration > reports/scan_config
report_dft_signal -view existing_dft > reports/dft_signals
report_dft_signal -view spec >> reports/dft_signals
report_scan_path -view existing_dft -chain all > reports/scan_chains
report_scan_path -view existing_dft -cell all > reports/scan_cells

# Write the scan netlist, test protocol, and scan reordering description.
set test_stil_netlist_format verilog
write -format verilog -hierarchy -output tmax/ORCA_scan.v
write_test_protocol -output tmax/ORCA_scan.spf
write_scan_def -output mapped_scan/ORCA.scandef
check_scan_def

# Write the DDC design after SCANDEF generation.
write -format ddc -hierarchy -output mapped_scan/ORCA.ddc
