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

