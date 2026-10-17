set_fml_appmode CC
read_file -top mux2 -format sverilog -vcs {./rtl/mux2.sv}
load_cc -format csv cc_connections.csv
report_load_cc
check_fv -block
report_fv -verbose
