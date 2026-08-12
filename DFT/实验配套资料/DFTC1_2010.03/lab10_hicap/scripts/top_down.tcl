
# Read gate-level design .db and link top-level design

read_ddc mapped/ORCA.ddc
current_design ORCA
link

# Specify pre-clock measure timing

set test_default_bidir_delay 0
set test_default_delay 0
set test_default_strobe 40

# Define Clocks, Resets and Test Holds

set_dft_signal -view exist -type ScanClock -port {pclk sys_clk sdr_clk} -timing {45 55}
set_dft_signal -view exist -type Reset -active 0 -port prst_n
set_dft_signal -view exist -type Constant -active 1 -port test_mode

# Specify Scan Signals

set_dft_signal -view spec -type ScanEnable -active 1 -port scan_en

for {set i 0} {$i < 6} {incr i} {
    set hookup_cell pad_iopad_$i
    set_dft_signal -view spec -port pad[$i] -type ScanDataIn -hookup_pin $hookup_cell/CIN
    set hookup_cell sdram_A_iopad_$i
    set_dft_signal -view spec -port sd_A[$i] -type ScanDataOut -hookup_pin $hookup_cell/I
    set_scan_path chain$i -view spec -scan_data_in pad[$i] -scan_data_out sd_A[$i] 
}

# Specify Bidiretional Pins to be input mode during scan

set_autofix_configuration -type bidirectional -method input


# Specify desired number of balanced scan chains here

set_scan_configuration -chain_count 6


# Specify RSS options here




# Create the test protocol

create_test_protocol
write_test_protocol -o tmax/ORCA.spf

# Perform gate-level DFT checks

redirect -tee reports/ORCA_dft_drc.rpt {dft_drc}

# Preview the scan architecture

redirect -tee reports/ORCA_preview_dft.rpt {preview_dft -show scan_clocks}

# Insert the DFT structures

insert_dft

# Obtain an estimate of the test coverage
redirect -tee reports/ORCA_coverage.rpt {dft_drc -coverage}

# Document what happened during scan insertion

report_dft_signal -view spec > reports/ORCA_test.rpt
report_dft_signal -view exist >> reports/ORCA_test.rpt
report_dft_configuration >> reports/ORCA_test.rpt
report_scan_state >> reports/ORCA_test.rpt
report_scan_path -view exist > reports/ORCA_scan_path.rpt

# Handoff the design

# Avoid naming issues between tools

change_names -rule verilog -hierarchy

# Save out the gate-level scan netlist

write -f verilog -h -o tmax/ORCA_scan.v

# It is good practice to to save the .db file, too
# For example, tools such as PT and PC would prefer this format

write -format ddc -hierarchy -output mapped_scan/ORCA_scan.ddc

# Save the updated protocol

set test_stil_netlist_format verilog
write_test_protocol -o tmax/ORCA.spf
