set hdlin_enable_rtldrc_info true;# enable rtl code checking in DV
set test_simulation_library "./tmax/rams.v"


# The mounted /media/6 filesystem can write DDC files but DC cannot read them
# directly.  Copy the DDC to the container-local /tmp directory before reading.
set local_ddc "/tmp/dftc_[pid]_lab4b_orca.ddc"
file copy -force mapped/ORCA.ddc $local_ddc
read_file -format ddc $local_ddc
current_design ORCA
link
file delete -force $local_ddc
