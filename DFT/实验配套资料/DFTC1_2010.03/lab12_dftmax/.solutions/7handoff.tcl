change_names -rule verilog -hierarchy
report_dft > reports/dft
report_scan_configuration > reports/scan_config
report_dft_signal -view existing_dft > reports/dft_signals
report_scan_path -view existing_dft -chain all > reports/scan_chains
report_scan_path -view existing_dft -cell all > reports/scan_cells

# hand off
set test_stil_netlist_format verilog
write -hierarchy -format verilog -output tmax/ORCA_COMP_scan.v
write -hierarchy -format ddc     -output mapped_scan/ORCA_COMP.ddc

# Write Internal_scan protocol:
write_test_protocol -out ./tmax/scan.spf \
  -test_mode Internal_scan

# Write ScanCompression_mode protocol:
write_test_protocol -out ./tmax/scancompress.spf \
  -test_mode ScanCompression_mode
