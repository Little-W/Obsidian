
remove_design -designs

set local_ddc "/tmp/dftc_[pid]_lab7_risc_core.ddc"
file copy -force mapped/RISC_CORE.ddc $local_ddc
read_file -format ddc $local_ddc
current_design RISC_CORE
link
file delete -force $local_ddc

#Declare test components in preparation for create_test_protocol
set_dft_signal -view existing_dft -port Clk -type ScanClock -timing {45 55}
set_dft_signal -view existing_dft -port Reset -type Reset -active_state 0
set_dft_signal -view spec -port TEST_SE -type ScanEnable -active_state 1
set_dft_signal -view existing_dft -type Constant -active_state 1 -port TEST_MODE

create_test_protocol

dft_drc
