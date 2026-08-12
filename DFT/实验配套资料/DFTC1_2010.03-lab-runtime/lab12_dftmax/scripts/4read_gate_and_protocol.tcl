read_ddc mapped/ORCA.ddc ;# note this was created during the unmapped flow
current_design ORCA
link

source -echo -verbose scripts/settings_protocol.tcl
create_test_protocol


dft_drc 

