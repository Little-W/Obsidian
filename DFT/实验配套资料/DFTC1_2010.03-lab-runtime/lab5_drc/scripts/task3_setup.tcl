
# Preserve design names
set_dft_insertion_configuration -preserve_design_name true

# Declare scan in and scan out ports.
# The current VHDL reader stores bus-bit names with escaped brackets.  Select
# bit 0 from the ordered bit-port collections so the command receives a port
# collection instead of an unescaped text name.
set scan_in_port  [index_collection [get_ports {Instrn*}] 31]
set scan_out_port [index_collection [get_ports {Xecutng_Instrn*}] 31]
set_dft_signal -view spec -port $scan_in_port -type ScanDataIn
set_dft_signal -view spec -port $scan_out_port -type ScanDataOut
set_scan_configuration -chain_count 1

# Allow clock domains to be mixed together on same chain
set_scan_configuration -clock_mixing mix_clocks

# Preview the scan architecture
preview_dft
