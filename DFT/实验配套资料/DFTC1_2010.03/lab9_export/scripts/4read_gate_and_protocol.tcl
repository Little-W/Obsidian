set test_simulation_library ./tmax/rams.v

# Read them mapped design
read_ddc mapped/ORCA.ddc
current_design ORCA
link

# Declare the signal needed for the test protocol
set_dft_signal -view existing_dft -type ScanClock -timing {45 55} -port {pclk sdr_clk sys_clk}
set_dft_signal -view existing_dft -port prst_n -type Reset -active_state 0
set_dft_signal -view existing_dft -port scan_en -type ScanEnable -active_state 1
set_dft_signal -view existing_dft -type Constant -active_state 0 -port conf_ena

# Read in the init sequence and create the test protocol
read_test_protocol -section test_setup ./scripts/orca_mapped.spf
create_test_protocol

# Run DRC checks
dft_drc

