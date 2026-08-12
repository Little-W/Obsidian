
#***********START AUTOFIX COMMANDS*******************************************************

# Use autofix to fix problems with sets/resets and clock problems

# Enable AutoFix
set_dft_configuration -fix_set enable -fix_reset enable -fix_clock enable
set_dft_signal -view spec -type TestMode -active_state 1 -port TEST_MODE

# Fix clocks
# If an autofix clock is not specified, tool will look for a controllable clock
# DFTC will create a new clock port if it does not find one
# Using the clock Clk as the autofix clock
set_dft_signal -view spec -port Clk -type TestData
set_autofix_configuration -type clock -control TEST_MODE -test_data Clk

# Fix resets
# Use the Reset line as the reset fix
set_dft_signal -view spec -port Reset -type TestData
set_autofix_configuration -type reset -method mux -control TEST_MODE -test_data Reset

# Fix sets
# Use the same Reset line to fix the sets
set_autofix_configuration -type set -method mux -control TEST_MODE -test_data Reset


# TEST_MODE already declared as part of the test protocol

#***********END AUTOFIX COMMANDS*********************************************************
