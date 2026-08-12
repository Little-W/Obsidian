set_command noabort
set_messages -log comp.log -rep -level expert
read_netlist libs.v.gz
read_netlist rams.v
read_netlist ORCA_COMP_scan.v 
set_rule b5 warning
run_build
set_drc -nodisturb
run_drc scancompress.spf
add_faults -all
run_atpg -auto
