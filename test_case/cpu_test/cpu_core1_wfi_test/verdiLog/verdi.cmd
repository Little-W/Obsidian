verdiSetActWin -dock widgetDock_<Message>
simSetSimulator "-vcssv" -exec \
           "/tmpdata/zc_data/yusen/work/chip_top/cpu_memmap_test5/cpu_memmap_test/cpu_memmap5_test.0.0/../simv" \
           -args \
           "+TESTDIR=/tmpdata/zc_data/yusen/work/chip_top/cpu_memmap_test5/cpu_memmap_test/cpu_memmap5_test.0.0 +vcs+lic+wait +UVM_VERBOSITY=UVM_MEDIUM +USER_CONTROLLED_PLLTS6FFLJFRACS_LOCK_TIME=20 +USER_CONTROLLED_PLLTS6FFFRACG4_LOCK_TIME=20 +UVM_MAX_QUIT_COUNT=50 +speed_grades=SG9600ODR +vcs+initreg+0+noreg +ELF=/projects/platform/temp/yusen/t100_br_dv_1114/verif/chip_top/test/c/cpu_test/cpu_memmap5_test/cpu_memmap5_test.elf -sv_lib /projects/platform/temp/yusen/t100_br_dv_1114/verif/chip_top/tb/hvl_top/rvv_cpu/rvv_cpu_dpi +ntb_random_seed=666 -ucli +UVM_TESTNAME=cpu_memmap5_test"
debImport "-sverilog" "-dbdir" \
          "/tmpdata/zc_data/yusen/work/chip_top/cpu_memmap_test5/cpu_memmap_test/cpu_memmap5_test.0.0/../simv.daidir"
debLoadSimResult \
           /tmpdata/zc_data/yusen/work/chip_top/cpu_memmap_test5/cpu_memmap_test/cpu_memmap5_test.0.0/wave.fsdb
wvCreateWindow
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
srcHBSelect "hdl_top" -win $_nTrace1
srcSetScope "hdl_top" -delim "." -win $_nTrace1
verdiSetActWin -dock widgetDock_<Inst._Tree>
srcHBSelect "hdl_top" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u" -win $_nTrace1
srcSetScope "hdl_top.T100_TOP_u" -delim "." -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0" -win $_nTrace1
srcSetScope "hdl_top.T100_TOP_u.PD_MCU_SUB_0" -delim "." -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0" -win $_nTrace1
srcSetScope "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0" -delim "." -win \
           $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top" \
           -win $_nTrace1
srcSetScope "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top" \
           -delim "." -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0.MCU_CPU_900_0.U_ux900_cluster_top" \
           -win $_nTrace1
srcDeselectAll -win $_nTrace1
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
srcSelect -win $_nTrace1 -range {26 55 1 1 2 1} -backward
wvAddSignal -win $_nWave2 \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i0_trace_ivalid" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i0_trace_iexception" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i0_trace_interrupt" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i0_trace_cause\[63:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i0_trace_tval\[63:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i0_trace_iaddr\[63:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i0_trace_instr\[31:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i0_trace_priv\[1:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i0_trace_bjp_taken" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i0_trace_dmode" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i0_trace_cmt_ena" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i1_trace_ivalid" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i1_trace_iexception" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i1_trace_interrupt" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i1_trace_cause\[63:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i1_trace_tval\[63:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i1_trace_iaddr\[63:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i1_trace_instr\[31:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i1_trace_priv\[1:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i1_trace_bjp_taken" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i1_trace_dmode" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_i1_trace_cmt_ena" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_atb_o_atvalid" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_atb_i_atready" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_atb_i_active" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_atb_o_atbytes\[2:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_atb_o_atid\[4:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_atb_o_atbeat\[1:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/core0_atb_o_atdata\[63:0\]"
wvSetPosition -win $_nWave2 {("G1" 0)}
wvSetPosition -win $_nWave2 {("G1" 29)}
wvSetPosition -win $_nWave2 {("G1" 29)}
srcDeselectAll -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -win $_nTrace1 -range {109 149 1 1 1 1} -backward
verdiSetActWin -win $_nWave2
wvScrollDown -win $_nWave2 1
wvSetPosition -win $_nWave2 {("G1" 26)}
wvSetPosition -win $_nWave2 {("G1" 25)}
wvSetPosition -win $_nWave2 {("G1" 24)}
wvSetPosition -win $_nWave2 {("G1" 23)}
wvSetPosition -win $_nWave2 {("G1" 22)}
wvSetPosition -win $_nWave2 {("G1" 21)}
wvSetPosition -win $_nWave2 {("G1" 20)}
wvSetPosition -win $_nWave2 {("G1" 19)}
wvSetPosition -win $_nWave2 {("G1" 18)}
wvSetPosition -win $_nWave2 {("G1" 17)}
wvSetPosition -win $_nWave2 {("G1" 16)}
wvSetPosition -win $_nWave2 {("G1" 15)}
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
wvSetPosition -win $_nWave2 {("G1" 16)}
wvSetPosition -win $_nWave2 {("G1" 17)}
wvSetPosition -win $_nWave2 {("G1" 18)}
wvSetPosition -win $_nWave2 {("G1" 19)}
wvSetPosition -win $_nWave2 {("G1" 20)}
wvSetPosition -win $_nWave2 {("G1" 21)}
wvSetPosition -win $_nWave2 {("G1" 22)}
wvSetPosition -win $_nWave2 {("G1" 23)}
wvSetPosition -win $_nWave2 {("G1" 24)}
wvSetPosition -win $_nWave2 {("G1" 25)}
wvSetPosition -win $_nWave2 {("G1" 26)}
wvSetPosition -win $_nWave2 {("G1" 27)}
wvSetPosition -win $_nWave2 {("G1" 28)}
wvSetPosition -win $_nWave2 {("G1" 29)}
wvSetPosition -win $_nWave2 {("G2" 0)}
wvSetPosition -win $_nWave2 {("G1" 29)}
wvSetPosition -win $_nWave2 {("G2" 0)}
wvAddSignal -win $_nWave2 \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/cc_enable_init_dram" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_arvalid" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_arready" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_araddr\[47:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_arlen\[7:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_arsize\[2:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_arburst\[1:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_arlock" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_arcache\[3:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_arprot\[2:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_rready" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_rvalid" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_rdata\[63:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_rresp\[1:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_rlast" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_awvalid" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_awready" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_awaddr\[47:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_awlen\[7:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_awsize\[2:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_awburst\[1:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_awlock" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_awcache\[3:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_awprot\[2:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_bready" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_bvalid" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_bresp\[1:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_wready" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_wvalid" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_wdata\[63:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_wstrb\[7:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_wlast" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_arsmode" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_ardmode" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_awsmode" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_awdmode" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_arid\[4:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_rid\[4:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_awid\[4:0\]" \
           "/hdl_top/T100_TOP_u/PD_MCU_SUB_0/MCU_CPU_900_0/U_ux900_cluster_top/mem_bid\[4:0\]"
wvSetPosition -win $_nWave2 {("G2" 0)}
wvSetPosition -win $_nWave2 {("G2" 40)}
wvSetPosition -win $_nWave2 {("G2" 40)}
verdiSetActWin -win $_nWave2
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G2" 37 )} 
wvSelectSignal -win $_nWave2 {( "G2" 31 )} 
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G2" 36 )} 
wvSelectSignal -win $_nWave2 {( "G2" 30 )} 
wvSelectSignal -win $_nWave2 {( "G2" 27 )} 
wvSelectSignal -win $_nWave2 {( "G2" 25 )} 
wvSelectSignal -win $_nWave2 {( "G2" 27 )} 
wvSelectSignal -win $_nWave2 {( "G2" 22 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G2" 27 )} 
wvSelectSignal -win $_nWave2 {( "G2" 15 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G2" 5 )} 
wvScrollDown -win $_nWave2 0
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 6
wvScrollUp -win $_nWave2 9
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvSetCursor -win $_nWave2 939075321017.774780 -snap {("G1" 4)}
wvSetCursor -win $_nWave2 936075080375.545532 -snap {("G1" 8)}
wvSetCursor -win $_nWave2 936075080375.545532 -snap {("G1" 9)}
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 3
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 3
wvScrollDown -win $_nWave2 2
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 2
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 2
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 2
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 1
wvSelectSignal -win $_nWave2 {( "G2" 32 )} 
wvSelectSignal -win $_nWave2 {( "G2" 38 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G2" 40 )} 
wvSelectSignal -win $_nWave2 {( "G2" 39 )} 
wvSelectSignal -win $_nWave2 {( "G2" 37 )} 
wvSelectSignal -win $_nWave2 {( "G2" 37 )} 
wvSelectSignal -win $_nWave2 {( "G2" 29 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G2" 27 )} 
wvScrollUp -win $_nWave2 11
wvSelectSignal -win $_nWave2 {( "G2" 15 )} 
wvSelectSignal -win $_nWave2 {( "G2" 14 )} 
wvZoom -win $_nWave2 875320207370.401855 969077727440.067871
wvZoom -win $_nWave2 937027023133.343262 939912814517.281860
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoom -win $_nWave2 936810636025.605957 937128129773.151245
wvZoom -win $_nWave2 936989239253.590454 937015645085.901001
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G2" 13 )} 
wvSelectSignal -win $_nWave2 {( "G2" 12 )} 
wvSelectSignal -win $_nWave2 {( "G2" 14 )} 
wvSelectSignal -win $_nWave2 {( "G2" 12 )} 
wvSelectSignal -win $_nWave2 {( "G2" 9 )} 
wvSelectSignal -win $_nWave2 {( "G2" 4 )} 
wvSelectSignal -win $_nWave2 {( "G2" 3 )} 
wvSelectSignal -win $_nWave2 {( "G2" 4 )} 
wvZoom -win $_nWave2 936874615115.094727 936918884224.927734
wvZoom -win $_nWave2 936899460319.405273 936903461064.105347
wvZoomOut -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G2" 14 )} 
wvSelectSignal -win $_nWave2 {( "G2" 15 )} 
wvSelectSignal -win $_nWave2 {( "G2" 14 )} 
wvCopySignalFullPathToClipboard -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G2" 4 )} 
wvSelectSignal -win $_nWave2 {( "G2" 5 )} 
wvSelectSignal -win $_nWave2 {( "G2" 3 )} 
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoom -win $_nWave2 936900370770.421997 936904059734.755737
verdiSetActWin -dock widgetDock_<Inst._Tree>
srcHBSelect "hdl_top.T100_TOP_u.PD_MCU_SUB_0" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.T1_SOC_NOC_0" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.T1_NPU_CORE_0" -win $_nTrace1
srcSetScope "hdl_top.T100_TOP_u.T1_NPU_CORE_0" -delim "." -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.T1_NPU_CORE_0" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core" -win $_nTrace1
srcSetScope "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core" -delim "." -win \
           $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core" -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif" -win \
           $_nTrace1
srcSetScope "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif" \
           -delim "." -win $_nTrace1
srcHBSelect "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif" -win \
           $_nTrace1
srcDeselectAll -win $_nTrace1
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
srcSelect -win $_nTrace1 -range {37 75 1 6 1 1} -backward
wvSetPosition -win $_nWave2 {("G2" 10)}
wvSetPosition -win $_nWave2 {("G2" 11)}
wvSetPosition -win $_nWave2 {("G2" 12)}
wvSetPosition -win $_nWave2 {("G2" 14)}
wvSetPosition -win $_nWave2 {("G2" 15)}
wvSetPosition -win $_nWave2 {("G2" 16)}
wvSetPosition -win $_nWave2 {("G2" 17)}
wvSetPosition -win $_nWave2 {("G2" 18)}
wvSetPosition -win $_nWave2 {("G1" 29)}
wvSetPosition -win $_nWave2 {("G2" 25)}
wvSetPosition -win $_nWave2 {("G2" 26)}
wvSetPosition -win $_nWave2 {("G2" 27)}
wvSetPosition -win $_nWave2 {("G2" 28)}
wvSetPosition -win $_nWave2 {("G2" 29)}
wvSetPosition -win $_nWave2 {("G2" 30)}
wvSetPosition -win $_nWave2 {("G2" 31)}
wvSetPosition -win $_nWave2 {("G2" 32)}
wvSetPosition -win $_nWave2 {("G2" 33)}
wvSetPosition -win $_nWave2 {("G2" 34)}
wvSetPosition -win $_nWave2 {("G2" 35)}
wvSetPosition -win $_nWave2 {("G2" 36)}
wvSetPosition -win $_nWave2 {("G2" 37)}
wvSetPosition -win $_nWave2 {("G2" 38)}
wvSetPosition -win $_nWave2 {("G2" 39)}
wvSetPosition -win $_nWave2 {("G2" 40)}
wvSetPosition -win $_nWave2 {("G3" 0)}
wvAddSignal -win $_nWave2 \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_awid\[7:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_awaddr\[39:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_awlen\[7:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_awsize\[2:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_awburst\[1:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_awlock" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_awcache\[3:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_awprot\[2:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_awuser\[19:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_awvalid" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_awready" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_wdata\[1023:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_wstrb\[127:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_wlast" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_wvalid" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_wready" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_bid\[7:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_bresp\[1:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_buser\[19:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_bvalid" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_bready" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_arid\[7:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_araddr\[39:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_arlen\[7:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_arsize\[2:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_arburst\[1:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_arlock" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_arcache\[3:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_arprot\[2:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_aruser\[19:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_arvalid" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_arready" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_rid\[7:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_rdata\[1023:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_rresp\[1:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_rlast" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_ruser\[19:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_rvalid" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/m1_soc_rready"
wvSetPosition -win $_nWave2 {("G3" 0)}
wvSetPosition -win $_nWave2 {("G3" 39)}
wvSetPosition -win $_nWave2 {("G3" 39)}
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
wvZoom -win $_nWave2 936804499974.663330 937103830319.658569
verdiSetActWin -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G3" 20 )} 
wvSelectSignal -win $_nWave2 {( "G3" 9 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 4 )} 
wvSelectSignal -win $_nWave2 {( "G3" 2 )} 
wvSelectSignal -win $_nWave2 {( "G3" 5 )} 
wvSelectSignal -win $_nWave2 {( "G3" 8 )} 
wvScrollDown -win $_nWave2 4
wvScrollDown -win $_nWave2 5
wvSelectSignal -win $_nWave2 {( "G3" 21 )} 
wvSelectSignal -win $_nWave2 {( "G3" 25 )} 
wvSelectSignal -win $_nWave2 {( "G3" 23 )} 
wvZoom -win $_nWave2 936937012949.856567 936945442029.643555
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
wvSelectSignal -win $_nWave2 {( "G3" 27 )} 
wvSelectSignal -win $_nWave2 {( "G3" 28 )} 
wvSelectSignal -win $_nWave2 {( "G3" 28 )} 
wvSelectSignal -win $_nWave2 {( "G3" 25 )} 
wvSelectSignal -win $_nWave2 {( "G3" 23 )} 
wvSelectSignal -win $_nWave2 {( "G3" 25 )} 
wvSelectSignal -win $_nWave2 {( "G3" 26 )} 
wvScrollUp -win $_nWave2 9
wvSelectSignal -win $_nWave2 {( "G3" 4 )} 
wvSelectSignal -win $_nWave2 {( "G3" 2 )} 
srcDeselectAll -win $_nTrace1
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
srcDeselectAll -win $_nTrace1
srcSelect -win $_nTrace1 -range {15 17 3 1 39 1} -backward
wvSetPosition -win $_nWave2 {("G2" 37)}
wvSetPosition -win $_nWave2 {("G2" 36)}
wvSetPosition -win $_nWave2 {("G2" 35)}
wvSetPosition -win $_nWave2 {("G2" 34)}
wvSetPosition -win $_nWave2 {("G2" 33)}
wvSetPosition -win $_nWave2 {("G1" 29)}
wvSetPosition -win $_nWave2 {("G2" 36)}
wvSetPosition -win $_nWave2 {("G2" 37)}
wvSetPosition -win $_nWave2 {("G2" 38)}
wvSetPosition -win $_nWave2 {("G2" 39)}
wvSetPosition -win $_nWave2 {("G2" 40)}
wvSetPosition -win $_nWave2 {("G3" 0)}
wvAddSignal -win $_nWave2 \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/mif_clk" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/mif_rst_n"
wvSetPosition -win $_nWave2 {("G3" 0)}
wvSetPosition -win $_nWave2 {("G3" 2)}
wvSelectSignal -win $_nWave2 {( "G3" 2 )} 
wvSelectSignal -win $_nWave2 {( "G3" 1 )} 
verdiSetActWin -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G3" 2 )} 
srcDeselectAll -win $_nTrace1
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
wvSelectSignal -win $_nWave2 {( "G3" 12 )} 
verdiSetActWin -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G3" 21 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 26 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 31 )} 
wvSelectSignal -win $_nWave2 {( "G3" 28 )} 
wvZoom -win $_nWave2 936819698596.096191 937130586463.550781
wvZoom -win $_nWave2 936937375863.445190 936945519618.977661
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
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G3" 27 )} 
wvSelectSignal -win $_nWave2 {( "G3" 25 )} 
wvSelectSignal -win $_nWave2 {( "G3" 24 )} 
wvSelectSignal -win $_nWave2 {( "G3" 23 )} 
wvSelectSignal -win $_nWave2 {( "G3" 22 )} 
wvSelectSignal -win $_nWave2 {( "G3" 22 )} 
wvSelectSignal -win $_nWave2 {( "G3" 35 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 37 )} 
wvZoom -win $_nWave2 931089267489.868408 939477623679.667969
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomIn -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomIn -win $_nWave2
wvZoomOut -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G3" 28 )} 
wvSelectSignal -win $_nWave2 {( "G3" 26 )} 
srcDeselectAll -win $_nTrace1
srcSelect -word -line 37 -pos 5 -win $_nTrace1
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
srcDeselectAll -win $_nTrace1
srcDeselectAll -win $_nTrace1
srcSelect -word -line 58 -pos 5 -win $_nTrace1
verdiSetActWin -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G3" 31 )} 
wvSelectSignal -win $_nWave2 {( "G3" 39 )} 
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 3
wvScrollUp -win $_nWave2 31
wvSelectSignal -win $_nWave2 {( "G3" 2 )} 
wvSelectSignal -win $_nWave2 {( "G3" 2 )} 
wvSelectSignal -win $_nWave2 {( "G3" 1 )} 
wvSelectSignal -win $_nWave2 {( "G3" 2 )} 
wvSelectSignal -win $_nWave2 {( "G3" 3 )} 
wvSetPosition -win $_nWave2 {("G3" 15)}
wvExpandBus -win $_nWave2
wvScrollUp -win $_nWave2 1
wvScrollUp -win $_nWave2 118
wvSelectSignal -win $_nWave2 {( "G3" 15 )} 
wvSetPosition -win $_nWave2 {("G3" 15)}
wvCollapseBus -win $_nWave2
wvSetPosition -win $_nWave2 {("G3" 15)}
wvScrollDown -win $_nWave2 11
wvSelectSignal -win $_nWave2 {( "G3" 23 )} 
wvScrollUp -win $_nWave2 10
wvScrollUp -win $_nWave2 9
srcHBSelect "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif" -win \
           $_nTrace1
verdiSetActWin -dock widgetDock_<Inst._Tree>
srcHBSelect \
           "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif.u_mif_noc" \
           -win $_nTrace1
srcSetScope \
           "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif.u_mif_noc" \
           -delim "." -win $_nTrace1
srcHBSelect \
           "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif.u_mif_noc" \
           -win $_nTrace1
srcDeselectAll -win $_nTrace1
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
srcSelect -win $_nTrace1 -range {16 60 1 1 1 1} -backward
wvSetPosition -win $_nWave2 {("G3" 0)}
wvAddSignal -win $_nWave2 \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/mif_clk" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/mif_rstn" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/testmode" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/wdt_ext_ref" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/tmode\[17:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_ar_addr\[39:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_ar_burst\[1:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_ar_cache\[3:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_ar_id\[7:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_ar_len\[7:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_ar_lock" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_ar_prot\[2:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_ar_ready" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_ar_size\[2:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_ar_user\[52:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_ar_valid" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_aw_addr\[39:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_aw_burst\[1:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_aw_cache\[3:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_aw_id\[7:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_aw_len\[7:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_aw_lock" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_aw_prot\[2:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_aw_ready" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_aw_size\[2:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_aw_user\[52:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_aw_valid" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_b_id\[7:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_b_ready" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_b_resp\[1:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_b_user\[52:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_b_valid" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_r_data\[1023:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_r_id\[7:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_r_last" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_r_ready" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_r_resp\[1:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_r_user\[52:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_r_valid" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_w_data\[1023:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_w_last" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_w_ready" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_w_strb\[127:0\]" \
           "/hdl_top/T100_TOP_u/T1_NPU_CORE_0/u_zcnpu_top_core/u_zcnpu_mif/u_mif_noc/m1_soc_init_w_valid"
wvSetPosition -win $_nWave2 {("G3" 0)}
wvSetPosition -win $_nWave2 {("G3" 44)}
verdiSetActWin -win $_nWave2
wvScrollDown -win $_nWave2 4
wvSelectSignal -win $_nWave2 {( "G3" 44 )} 
wvSelectSignal -win $_nWave2 {( "G3" 45 )} 
wvScrollDown -win $_nWave2 21
wvSelectSignal -win $_nWave2 {( "G3" 45 46 47 48 49 50 51 52 53 54 55 56 57 58 \
           59 60 61 62 63 64 65 66 67 68 69 )} 
wvScrollDown -win $_nWave2 6
wvScrollDown -win $_nWave2 3
wvSelectSignal -win $_nWave2 {( "G3" 45 46 47 48 49 50 51 52 53 54 55 56 57 58 \
           59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 )} 
wvCut -win $_nWave2
wvSetPosition -win $_nWave2 {("G3" 44)}
wvSelectSignal -win $_nWave2 {( "G3" 51 )} 
wvScrollUp -win $_nWave2 5
wvScrollDown -win $_nWave2 3
wvSelectSignal -win $_nWave2 {( "G3" 46 )} 
wvSelectSignal -win $_nWave2 {( "G3" 45 )} 
wvScrollDown -win $_nWave2 2
wvSelectSignal -win $_nWave2 {( "G3" 45 46 47 48 49 50 51 )} 
wvCut -win $_nWave2
wvSetPosition -win $_nWave2 {("G3" 44)}
wvSelectSignal -win $_nWave2 {( "G3" 41 )} 
wvScrollUp -win $_nWave2 5
wvSelectSignal -win $_nWave2 {( "G3" 35 )} 
wvSelectSignal -win $_nWave2 {( "G3" 37 )} 
wvSelectSignal -win $_nWave2 {( "G3" 35 )} 
wvSelectSignal -win $_nWave2 {( "G3" 34 )} 
wvSelectSignal -win $_nWave2 {( "G3" 36 )} 
wvSelectSignal -win $_nWave2 {( "G3" 34 )} 
wvSelectSignal -win $_nWave2 {( "G3" 35 )} 
wvSelectSignal -win $_nWave2 {( "G3" 35 )} 
wvSelectSignal -win $_nWave2 {( "G3" 34 )} 
wvSelectSignal -win $_nWave2 {( "G3" 33 )} 
wvSelectSignal -win $_nWave2 {( "G3" 32 )} 
wvScrollUp -win $_nWave2 13
wvScrollUp -win $_nWave2 8
wvScrollDown -win $_nWave2 16
wvSelectSignal -win $_nWave2 {( "G3" 28 )} 
wvSelectSignal -win $_nWave2 {( "G3" 30 )} 
wvSelectSignal -win $_nWave2 {( "G3" 35 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 33 )} 
wvSelectSignal -win $_nWave2 {( "G3" 21 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 19 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 16 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 14 )} 
wvSelectSignal -win $_nWave2 {( "G3" 13 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 10 )} 
wvScrollUp -win $_nWave2 2
wvSelectSignal -win $_nWave2 {( "G3" 10 )} 
wvSelectSignal -win $_nWave2 {( "G3" 7 )} 
wvScrollUp -win $_nWave2 3
wvSelectSignal -win $_nWave2 {( "G3" 6 )} 
srcDeselectAll -win $_nTrace1
verdiSetActWin -dock widgetDock_MTB_SOURCE_TAB_1
srcHBSelect \
           "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif.u_mif_noc.u_mif_noc" \
           -win $_nTrace1
srcSetScope \
           "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif.u_mif_noc.u_mif_noc" \
           -delim "." -win $_nTrace1
srcHBSelect \
           "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif.u_mif_noc.u_mif_noc" \
           -win $_nTrace1
verdiSetActWin -dock widgetDock_<Inst._Tree>
srcHBSelect \
           "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif.u_mif_noc.u_mif_noc.mod_fast" \
           -win $_nTrace1
srcSetScope \
           "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif.u_mif_noc.u_mif_noc.mod_fast" \
           -delim "." -win $_nTrace1
srcHBSelect \
           "hdl_top.T100_TOP_u.T1_NPU_CORE_0.u_zcnpu_top_core.u_zcnpu_mif.u_mif_noc.u_mif_noc.mod_fast" \
           -win $_nTrace1
wvSelectSignal -win $_nWave2 {( "G3" 8 )} 
verdiSetActWin -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G3" 11 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 13 )} 
wvSelectSignal -win $_nWave2 {( "G3" 1 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 2 )} 
wvScrollDown -win $_nWave2 2
wvSelectSignal -win $_nWave2 {( "G3" 5 )} 
wvSelectSignal -win $_nWave2 {( "G3" 2 )} 
wvSelectSignal -win $_nWave2 {( "G3" 1 )} 
wvSelectSignal -win $_nWave2 {( "G2" 40 )} 
wvSelectSignal -win $_nWave2 {( "G2" 25 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G2" 17 )} 
wvScrollUp -win $_nWave2 5
wvSelectSignal -win $_nWave2 {( "G2" 13 )} 
wvSelectSignal -win $_nWave2 {( "G2" 9 )} 
wvScrollDown -win $_nWave2 0
wvScrollUp -win $_nWave2 10
wvSelectSignal -win $_nWave2 {( "G2" 1 )} 
wvScrollUp -win $_nWave2 5
wvSelectSignal -win $_nWave2 {( "G1" 29 )} 
wvSelectSignal -win $_nWave2 {( "G1" 25 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G1" 10 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G1" 20 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G1" 21 )} 
wvScrollDown -win $_nWave2 13
wvSelectSignal -win $_nWave2 {( "G1" 29 )} 
wvScrollUp -win $_nWave2 20
wvSelectSignal -win $_nWave2 {( "G1" 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 \
           18 19 20 21 22 23 24 25 26 27 28 29 )} 
wvCut -win $_nWave2
wvSetPosition -win $_nWave2 {("G3" 44)}
wvSelectGroup -win $_nWave2 {G2}
wvScrollDown -win $_nWave2 5
wvSelectSignal -win $_nWave2 {( "G2" 10 )} 
wvSelectSignal -win $_nWave2 {( "G2" 16 )} 
wvSelectSignal -win $_nWave2 {( "G2" 20 )} 
wvSelectSignal -win $_nWave2 {( "G2" 18 )} 
wvSelectSignal -win $_nWave2 {( "G2" 21 )} 
wvSelectSignal -win $_nWave2 {( "G2" 26 )} 
wvSelectSignal -win $_nWave2 {( "G2" 23 )} 
wvSelectSignal -win $_nWave2 {( "G2" 24 )} 
wvSelectSignal -win $_nWave2 {( "G2" 18 19 20 21 22 23 24 )} 
wvCut -win $_nWave2
wvSetPosition -win $_nWave2 {("G3" 44)}
wvSelectSignal -win $_nWave2 {( "G2" 17 )} 
wvSelectSignal -win $_nWave2 {( "G2" 16 )} 
wvSelectSignal -win $_nWave2 {( "G2" 16 17 18 19 20 21 22 23 24 25 26 27 28 29 \
           30 31 32 )} 
wvCut -win $_nWave2
wvSetPosition -win $_nWave2 {("G3" 44)}
wvSelectSignal -win $_nWave2 {( "G2" 16 )} 
wvScrollUp -win $_nWave2 4
wvZoom -win $_nWave2 914182235293.139404 948343391120.502930
wvZoom -win $_nWave2 935233739964.710327 938656566972.953125
wvZoom -win $_nWave2 936789366646.900635 937076283383.675415
wvZoom -win $_nWave2 937005634599.766968 937012210949.332886
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoom -win $_nWave2 936509481971.291992 936694705050.618164
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoom -win $_nWave2 936610827015.632080 936764148542.985229
wvZoom -win $_nWave2 936652997966.148926 936659725236.831787
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G2" 12 )} 
wvSelectSignal -win $_nWave2 {( "G2" 13 )} 
wvSelectSignal -win $_nWave2 {( "G2" 4 )} 
wvZoom -win $_nWave2 936619848425.669189 936628870986.480347
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoom -win $_nWave2 936966942263.030029 937021396696.845093
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvZoom -win $_nWave2 936895530996.673828 936902663208.044434
wvZoomOut -win $_nWave2
wvZoomOut -win $_nWave2
wvSelectSignal -win $_nWave2 {( "G3" 7 )} 
wvSelectSignal -win $_nWave2 {( "G3" 11 )} 
wvScrollDown -win $_nWave2 0
wvScrollDown -win $_nWave2 17
wvSelectSignal -win $_nWave2 {( "G3" 27 )} 
wvSelectSignal -win $_nWave2 {( "G3" 37 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 41 )} 
wvScrollDown -win $_nWave2 0
wvScrollUp -win $_nWave2 23
wvSelectSignal -win $_nWave2 {( "G3" 6 )} 
wvScrollUp -win $_nWave2 5
wvSelectSignal -win $_nWave2 {( "G3" 4 )} 
wvSelectSignal -win $_nWave2 {( "G3" 1 )} 
wvSelectSignal -win $_nWave2 {( "G3" 3 )} 
wvSelectSignal -win $_nWave2 {( "G3" 4 )} 
wvSelectSignal -win $_nWave2 {( "G3" 5 )} 
wvScrollDown -win $_nWave2 8
wvSelectSignal -win $_nWave2 {( "G3" 15 )} 
wvScrollDown -win $_nWave2 19
wvSelectSignal -win $_nWave2 {( "G3" 4 )} 
wvScrollDown -win $_nWave2 0
wvSelectSignal -win $_nWave2 {( "G3" 7 )} 
wvSelectSignal -win $_nWave2 {( "G3" 8 )} 
wvSelectSignal -win $_nWave2 {( "G3" 5 )} 
wvSelectSignal -win $_nWave2 {( "G3" 4 )} 
wvSelectSignal -win $_nWave2 {( "G3" 8 )} 
wvSelectSignal -win $_nWave2 {( "G3" 14 )} 
wvSelectSignal -win $_nWave2 {( "G3" 10 )} 
wvSelectSignal -win $_nWave2 {( "G3" 14 )} 
debExit
