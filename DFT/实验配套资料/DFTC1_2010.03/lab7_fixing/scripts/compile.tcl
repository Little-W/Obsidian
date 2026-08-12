# Read in the RTL
acs_read_hdl -f vhdl -hdl_source {../ref/rtl/RISC_CORE_nodft/vhdl} RISC_CORE

# Apply non test constraints to the design
source -echo -verbose scripts/constraints.tcl

# Compile
compile_ultra -scan

# Save mapped design
write -format ddc -hierarchy -output mapped/RISC_CORE.ddc

exit