set_commands noabort
read_netlist libs.v.gz
read_netlist rams.v
read_netlist *_gates.v
read_netlist ORCA_scan.v
set_rule b5 warning
run_build
run_drc ORCA.spf
set_atpg -capture 4
add_faults -all
run_atpg -auto
quit -force
