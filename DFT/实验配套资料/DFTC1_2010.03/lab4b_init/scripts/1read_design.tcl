set hdlin_enable_rtldrc_info true;# enable rtl code checking in DV
set test_simulation_library "./tmax/rams.v"


# Read the mapped ORCA design
read_ddc mapped/ORCA.ddc
current_design ORCA
link

