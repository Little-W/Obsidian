# Enable file and line number tracking for RTL DFT DRC
set hdlin_enable_rtldrc_info true

# Read the RTL design
acs_read_hdl -f vhdl -hdl_source {../ref/rtl/RISC_CORE/vhdl} RISC_CORE

# Specify test components in preparation for create_test_protocol
set_dft_signal -view existing_dft -type ScanClock -timing {45 55} -port Clk
set_dft_signal -view existing_dft -port Reset -type Reset -active_state 0
set_dft_signal -view spec -port TEST_SE -type ScanEnable -active_state 1
set_dft_signal -view existing_dft -type Constant -active_state 1 -port TEST_MODE

# From the above specifications, create the test protocal
create_test_protocol
