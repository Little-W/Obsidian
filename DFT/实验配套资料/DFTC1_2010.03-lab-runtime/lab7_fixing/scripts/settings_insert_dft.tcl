
# Prepare for scan insertion
set_dft_insertion_configuration -preserve_design_name true ;# no change to design names
# VHDL bit-port names are escaped by the current reader.  Use port
# collections to select bit 0 without relying on the printed escape form.
set scan_in_port  [index_collection [get_ports {Instrn*}] 31]
set scan_out_port [index_collection [get_ports {Xecutng_Instrn*}] 31]
set_dft_signal -view spec -port $scan_in_port -type ScanDataIn
set_dft_signal -view spec -port $scan_out_port -type ScanDataOut
set_scan_configuration -chain_count 1

# Allow clock domains to be mixed together on same chain
set_scan_configuration -clock_mixing mix_clocks
