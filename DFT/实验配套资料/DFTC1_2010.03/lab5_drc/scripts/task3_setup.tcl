
# Preserve design names
set_dft_insertion_configuration -preserve_design_name true

# Declare scan in and scan out ports
set_dft_signal -view spec -port Instrn[0] -type ScanDataIn
set_dft_signal -view spec -port Xecutng_Instrn[0] -type ScanDataOut
set_scan_configuration -chain_count 1

# Allow clock domains to be mixed together on same chain
set_scan_configuration -clock_mixing mix_clocks

# Preview the scan architecture
preview_dft