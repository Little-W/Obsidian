
# Repair uncontrollable clocks, resets, and sets during scan insertion.
set_dft_configuration -fix_set enable -fix_reset enable -fix_clock enable
set_dft_signal -view spec -type TestMode -active_state 1 -port TEST_MODE

# Use the functional clock as the data source for clock control logic.
set_dft_signal -view spec -port Clk -type TestData
set_autofix_configuration -type clock -control TEST_MODE -test_data Clk

# Use the active-low reset as the data source for reset and set control logic.
set_dft_signal -view spec -port Reset -type TestData
set_autofix_configuration -type reset -method mux -control TEST_MODE -test_data Reset
set_autofix_configuration -type set -method mux -control TEST_MODE -test_data Reset
