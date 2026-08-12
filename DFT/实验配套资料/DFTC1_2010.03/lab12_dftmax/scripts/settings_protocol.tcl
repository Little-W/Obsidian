
#step2 -- read
#specify test components in preparation for create_test_protocol

  set test_default_delay 0
  set test_default_bidir_delay 0
  set test_default_strobe 40

  set_dft_signal -view existing_dft -type ScanClock -timing {45 55} -port {pclk sdr_clk sys_clk}
  set_dft_signal -view existing_dft -port prst_n -type Reset -active_state 0
  set_dft_signal -view spec -port scan_en -type ScanEnable -active_state 1
  set_dft_signal -view existing_dft -type Constant -active_state 1 -port test_mode

#step three -- nothing
