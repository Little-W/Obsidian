# FSV：信息流安全。请先完成 source、destination 与授权策略审查。
error "此文件是 FSV 教学模板：必须指定真正的安全源与公开输出"
# set_fml_appmode FSV
# read_file -top secure_top -format sverilog -vcs {-f filelist.f}
# create_clock clk -period 100
# create_reset rst_n -sense low
# sim_run -stable
# sim_save_reset
# fsv_generate -src u_core.secret -dest u_dbg.out
# check_fv -block
# fsv_report
