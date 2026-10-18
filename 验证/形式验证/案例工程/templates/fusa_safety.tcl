# FuSa：功能安全分析，需要 SFF/FDB、真实的安全检测点和失效定义。
error "此文件是 FuSa 教学模板：请先提供 SFF/FDB、观察点、检测点、RTL 和安全场景"
# set_fml_appmode FUSA
# fusa_config -sff /project/faults/campaign.sff
# read_file -top safety_top -format sverilog -vcs {-f filelist.f}
# create_clock clk -period 100
# create_reset rst_n -sense low
# sim_run -stable
# sim_save_reset
# fusa_observation -add {safety_top.data_out safety_top.done}
# fusa_detection -add {safety_top.error_alarm}
# fusa_generate
# set_fml_var fusa_run_mode structural
# check_fv -block
# fusa_report
