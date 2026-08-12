# Read in the unmapped design
set hdlin_enable_rtldrc_info true;# enable rtl code checking in DV
acs_read_hdl -f vhdl -hdl_source {../ref/rtl/RISC_CORE/vhdl} RISC_CORE

# Apply non test constraints to the design
source -echo -verbose scripts/constraints.tcl

# Perform a test-ready compile
compile_ultra -scan
write -format ddc -hierarchy -output mapped/RISC_CORE.ddc

############################################################
#
# USER: Add test protocol specifications here
#
############################################################

# Specify test components in preparation for create_test_protocol

set_dft_signal -view existing_dft -type ScanClock -timing {45 55} -port Clk
set_dft_signal -view existing_dft -type Reset -active_state 0 -port Reset
set_dft_signal -view existing_dft -type Constant -active_state 1 -port TEST_MODE

# From the above specifications, create the test protocol
create_test_protocol

# Check the test_protocol
dft_drc

# Write out the test protocol
write_test_protocol -output unmapped/unmapped_flow.spf
