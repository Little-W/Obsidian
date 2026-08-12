
# Specify test components in preparation for create_test_protocol
set_dft_signal -view existing_dft -type ScanClock -timing {45 55} -port {pclk sdr_clk sys_clk}
set_dft_signal -view existing_dft -port prst_n -type Reset -active_state 0
set_dft_signal -view existing_dft -port scan_en -type ScanEnable -active_state 1

# The conf_ena port need to be defined as a Constant to hold the design in test mode
set_dft_signal -view existing_dft -type Constant -active_state 0 -port conf_ena

#From the above specifications, create the test protocal
create_test_protocol

#check the test_protocol
dft_drc

#write out the test protocol
write_test_protocol -out orca_mapped.spf
