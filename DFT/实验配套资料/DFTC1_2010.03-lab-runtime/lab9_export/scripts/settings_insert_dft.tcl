
# Setup RSS
set_dft_insertion_configuration -synthesis none -preserve_design_name true

# Autofix bidirectionals to be input direction
set_autofix_configuration -type bidirectional -method input

# Allow clock domains to be mixed together on same chain
set_scan_configuration -chain_count 6 -add_lockup true -clock_mixing mix_clocks

# Specify all scan ports
for {set i 0} {$i < 6} {incr i} {
    set hookup_cell pad_iopad_$i
    # Select bus bit i by collection because current Tcl treats brackets in
    # textual VHDL port names specially.
    set pad_port [index_collection [get_ports {pad*}] [expr 15 - $i]]
    set_dft_signal -view spec -port $pad_port -type ScanDataIn -hookup_pin $hookup_cell/CIN
    set hookup_cell sdram_A_iopad_$i
    set sdram_port [index_collection [get_ports {sd_A*}] [expr 9 - $i]]
    set_dft_signal -view spec -port $sdram_port -type ScanDataOut -hookup_pin $hookup_cell/I
    set_scan_path chain$i -view spec -scan_data_in $pad_port -scan_data_out $sdram_port
}
