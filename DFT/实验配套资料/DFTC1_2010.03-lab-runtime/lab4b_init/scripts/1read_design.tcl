set hdlin_enable_rtldrc_info true;# enable rtl code checking in DV
set test_simulation_library "./tmax/rams.v"


read_file -format ddc mapped/ORCA.ddc
current_design ORCA
link
