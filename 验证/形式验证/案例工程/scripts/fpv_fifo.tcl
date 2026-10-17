set_fml_appmode FPV
read_file -top fifo_ctrl -sva -format sverilog -vcs {-f filelist_fifo.f}
create_clock clk -period 100
create_reset rst_n -sense low
sim_run -stable
sim_save_reset
check_fv_setup
check_fv -block
report_fv -verbose
