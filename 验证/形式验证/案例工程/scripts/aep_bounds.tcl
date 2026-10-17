set_fml_appmode AEP
read_file -top array_demo -aep bounds_check -format sverilog -vcs {-f filelist_aep.f}
create_clock clk -period 100
check_fv_setup
report_fv -list
check_fv -block
report_fv -verbose
