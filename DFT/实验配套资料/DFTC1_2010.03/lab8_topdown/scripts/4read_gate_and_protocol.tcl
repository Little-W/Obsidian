# Read the design from the unmapped flow
read_ddc mapped/ORCA.ddc
set current_design ORCA
link

# Setup timing
set test_default_delay 0
set test_default_bidir_delay 0
set test_default_strobe 40

# Declare signals for the protocol
set_dft_signal -view existing_dft -type ScanClock -timing {45 55} -port {pclk sdr_clk sys_clk}
set_dft_signal -view existing_dft -port prst_n -type Reset -active_state 0
set_dft_signal -view existing_dft -port scan_en -type ScanEnable -active_state 1
set_dft_signal -view existing_dft -type Constant -active_state 1 -port test_mode

# From the above specifications, create the test protocal
create_test_protocol

dft_drc 
