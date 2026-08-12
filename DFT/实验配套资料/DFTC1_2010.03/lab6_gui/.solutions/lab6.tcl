# Read the RTL
acs_read_hdl -f vhdl -hdl_source ../ref/rtl/RISC_CORE/vhdl  RISC_CORE

# Read the design constraints
source -e -v constraints.tcl

# Compile the design (test-ready)
compile_ultra -scan

# Save the mapped design
write -format ddc -hierarchy -output mapped/RISC_CORE.ddc

# Declare scan signals
set_dft_signal -view exist -type ScanClock -timing {45 55} -port Clk
set_dft_signal -view exist -type Constant -active 1 -port TEST_MODE
set_dft_signal -view exist -type Reset -active 0 -port Reset

create_test_protocol

dft_drc

