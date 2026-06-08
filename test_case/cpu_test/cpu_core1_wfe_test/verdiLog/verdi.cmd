verdiSetActWin -dock widgetDock_<Message>
simSetSimulator "-vcssv" -exec \
           "/tmpdata/zc_data/yusen/work/chip_top/cpu_test4/cpu_test/cpu_core1_wfe_test.0.0/../simv" \
           -args \
           "+TESTDIR=/tmpdata/zc_data/yusen/work/chip_top/cpu_test4/cpu_test/cpu_core1_wfe_test.0.0 +vcs+lic+wait +UVM_VERBOSITY=UVM_MEDIUM +USER_CONTROLLED_PLLTS6FFLJFRACS_LOCK_TIME=20 +USER_CONTROLLED_PLLTS6FFFRACG4_LOCK_TIME=20 +UVM_MAX_QUIT_COUNT=50 +speed_grades=SG9600ODR +vcs+initreg+0+noreg +ELF=/projects/platform/temp/yusen/t100_br_dv_1114/verif/chip_top/test/c/cpu_test/cpu_core1_wfe_test/cpu_core1_wfe_test.elf -sv_lib /projects/platform/temp/yusen/t100_br_dv_1114/verif/chip_top/tb/hvl_top/rvv_cpu/rvv_cpu_dpi +DUAL_BOOT +ntb_random_seed=666 -ucli +UVM_TESTNAME=cpu_core1_wfe_test"
debImport "-sverilog" "-dbdir" \
          "/tmpdata/zc_data/yusen/work/chip_top/cpu_test4/cpu_test/cpu_core1_wfe_test.0.0/../simv.daidir"
debLoadSimResult \
           /tmpdata/zc_data/yusen/work/chip_top/cpu_test4/cpu_test/cpu_core1_wfe_test.0.0/wave.fsdb
wvCreateWindow
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
srcHBSelect "hdl_top" -win $_nTrace1
srcSetScope "hdl_top" -delim "." -win $_nTrace1
srcHBSelect "hdl_top" -win $_nTrace1
verdiSetActWin -dock widgetDock_<Inst._Tree>
srcHBSelect "hdl_top.T100_TOP_u" -win $_nTrace1
srcSetScope "hdl_top.T100_TOP_u" -delim "." -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.T1_NPU_CORE_1" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.T1_SOC_NOC_0" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0" -win $_nTrace1
srcSetScope "hdl_top.T100_TOP_u.PD_MCU_SUB_0" -delim "." -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0" -win $_nTrace1
srcSetScope "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0" -delim "." -win \
           $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_mcu_atb2axi_top" \
           -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top" \
           -win $_nTrace1
srcSetScope "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top" \
           -delim "." -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top" \
           -win $_nTrace1
srcHBSelect \
           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top.u_core1" \
           -win $_nTrace1
srcHBSelect \
           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top.u_core0" \
           -win $_nTrace1
srcSetScope \
           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top.u_core0" \
           -delim "." -win $_nTrace1
srcHBSelect \
           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top.u_core0" \
           -win $_nTrace1
srcHBSelect \
           "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top.u_cc_top" \
           -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top" \
           -win $_nTrace1
srcSetScope "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top" \
           -delim "." -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top" \
           -win $_nTrace1
srcDeselectAll -win $_nTrace1
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
srcDeselectAll -win $_nTrace1
srcSelect -win $_nTrace1 -range {57 59 3 1 6 1} -backward
srcAddSelectedToWave -clipboard -win $_nTrace1
wvDrop -win $_nWave2
wvSetCursor -win $_nWave2 97768330469.087463 -snap {("G1" 2)}
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
verdiSetActWin -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomIn -win $_nWave2
wvZoomIn -win $_nWave2
wvZoomIn -win $_nWave2
wvZoomIn -win $_nWave2
wvZoomIn -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvSetCursor -win $_nWave2 2930947369331.352539 -snap {("G1" 0)}
wvSetCursor -win $_nWave2 3179047648801.294922
wvSetWindowTimeUnit -win $_nWave2 1.000000 ns
wvZoom -win $_nWave2 1185835.234077 1747214.679996
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvSetWindowTimeUnit -win $_nWave2 1.000000 us
wvSetCursor -win $_nWave2 3179.047649
wvSetCursor -win $_nWave2 3136.996754
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomIn -win $_nWave2
wvZoomIn -win $_nWave2
wvZoomIn -win $_nWave2
wvZoomIn -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
debExit
