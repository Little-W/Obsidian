# Formal Coverage Analyzer uses COV appmode in X-2025.06-SP1 User Guide.
# Run from example project root; treat result as tool-dependent.
set_fml_appmode COV
read_file -top coverage_demo -format sverilog -cov all -vcs {-f filelist_fca.f}
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
check_fv_setup
check_fv -block
report_fv -verbose
