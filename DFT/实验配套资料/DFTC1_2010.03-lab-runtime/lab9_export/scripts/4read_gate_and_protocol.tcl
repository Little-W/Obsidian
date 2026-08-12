set test_simulation_library ./tmax/rams.v

# Read the mapped design.  DDC must be copied to the container-local
# filesystem before DC reads it.
set local_ddc "/tmp/dftc_[pid]_lab9_orca.ddc"
file copy -force mapped/ORCA.ddc $local_ddc
read_file -format ddc $local_ddc
current_design ORCA
link
file delete -force $local_ddc

# Declare the signal needed for the test protocol
set_dft_signal -view existing_dft -type ScanClock -timing {45 55} -port pclk
set_dft_signal -view existing_dft -type ScanClock -timing {45 55} -port sdr_clk
set_dft_signal -view existing_dft -type ScanClock -timing {45 55} -port sys_clk
set_dft_signal -view existing_dft -port prst_n -type Reset -active_state 0
set_dft_signal -view existing_dft -port scan_en -type ScanEnable -active_state 1
set_dft_signal -view existing_dft -type Constant -active_state 0 -port conf_ena

# Read in the init sequence and create the test protocol
read_test_protocol -section test_setup ./scripts/orca_mapped.spf
create_test_protocol

# Run DRC checks
dft_drc
