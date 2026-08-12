# This script insert the scan chains

# Scan synthesis and autofix settings
set_dft_insertion_configuration -synthesis none -preserve_design_name true
set_autofix_configuration -type bidirectional -method input

# allow clock domains to be mixed together on same chain

set_scan_configuration -chain_count 5 -add_lockup true -clock_mixing mix_clocks

# Specify all scan ports

for {set i 0} {$i < 5 } {incr i} {
    set hookup_cell pad_iopad_$i
    set_dft_signal -view spec -port pad[$i] -type ScanDataIn -hookup_pin $hookup_cell/CIN
    set hookup_cell sdram_A_iopad_$i
    set_dft_signal -view spec -port sd_A[$i] -type ScanDataOut -hookup_pin $hookup_cell/I
    set_scan_path chain$i -view spec -scan_data_in pad[$i] -scan_data_out sd_A[$i] 
}

#
### Enable Adaptive scan HERE
#


#
### Specify compression ratio HERE
#


#
### Add TM_COMP port HERE
#

