# Set logfile
set_command noabort
set_messages -log tmax.log -replace -level expert

# Read the library and design
read_netlist libs.v.gz
read_netlist rams.v
read_netlist ORCA_scan.v 

# Run build
set_rule b5 warning
run_build

# Run DRC (ensure the name of the SPF matchs what was written from DFTC)
run_drc ORCA_scan.spf

# Add fault adn run ATPG
add_faults -all
run_atpg -auto

# Increase capture cycles to enable fast sequential ATPG
set_atpg -capture_cycles 4
run_atpg -auto

