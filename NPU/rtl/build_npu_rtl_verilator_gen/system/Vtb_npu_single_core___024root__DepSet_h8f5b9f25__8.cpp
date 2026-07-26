// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core__Syms.h"
#include "Vtb_npu_single_core___024root.h"

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__16(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__16\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        while ((0x4e20U > vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__poll_count)) {
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__address = 0x20038U;
            const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18332226371053824922ull);
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13584156324243209474ull);
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14473746424445454022ull);
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__address;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 600);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     600);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 601);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 604);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     604);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1517__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1517__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1517__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1517__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1518__message = 
                std::string{"AXI Slave changed read response during host stall"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1518__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1518__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1518__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 612);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 614);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1519__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1519__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1519__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1519__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1520__message = 
                std::string{"AXI Slave returned the wrong RID"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1520__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1520__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1520__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1521__message = 
                std::string{"AXI Slave single read failed"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1521__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1521__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1521__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1522__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1522__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1522__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1522__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status 
                = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__data;
            if ((1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status 
                               >> 1U)))) {
                goto __Vlabel0;
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__poll_count 
                = ((IData)(1U) + vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__poll_count);
        }
        __Vlabel0: ;
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1523__message = 
        std::string{"control request polling timed out"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1523__condition 
        = (1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1523__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1523__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1524__message = 
        std::string{"control request stayed busy after completion"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1524__condition 
        = (1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1524__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1524__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1525__message = 
        std::string{"control window reported an internal failure"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1525__condition 
        = (0U == (0xffU & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1525__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1525__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1526__message = 
        std::string{"control window status reserved bits are nonzero"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1526__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1526__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1526__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__address = 0x20040U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7337237412135300662ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10623455078878347306ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7757374652300179137ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         600);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             600);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         601);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         604);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             604);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1528__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1528__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1528__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1528__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1529__message = 
        std::string{"AXI Slave changed read response during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1529__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1529__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1529__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         612);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         614);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1530__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1530__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1530__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1530__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1531__message = 
        std::string{"AXI Slave returned the wrong RID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1531__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1531__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1531__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1532__message = 
        std::string{"AXI Slave single read failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1532__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1532__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1532__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1533__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1533__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1533__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1533__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__data;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1496__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__result;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1496__result;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1534__message = 
        std::string{"INT16 Matrix pack task status is incorrect"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1534__condition 
        = (IData)((3ULL == (0xfffULL & vlSelfRef.tb_npu_single_core__DOT__ctl_data)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1534__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1534__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1535__selector = 3U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1535__command_id = 0x107U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__argument1 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1535__selector));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__argument0 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1535__command_id));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__operation = 2U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 18320117521651841311ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1536__poll_count = 0;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__data 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__argument0;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__address = 0x20020U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17077821235074897542ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4304897147433023252ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1538__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1538__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1538__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1538__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1539__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1539__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1539__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1539__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1540__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1540__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1540__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1540__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1541__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1541__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1541__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1541__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1542__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1542__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1542__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1542__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__data 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__argument1;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__address = 0x20028U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5782266350681631203ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3638157727177461467ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1544__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1544__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1544__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1544__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1545__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1545__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1545__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1545__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1546__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1546__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1546__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1546__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1547__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1547__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1547__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1547__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1548__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1548__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1548__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1548__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__data 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__operation));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__address = 0x20030U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 718934160309065236ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1452101477211717602ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1550__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1550__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1550__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1550__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1551__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1551__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1551__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1551__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1552__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1552__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1552__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1552__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1553__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1553__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1553__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1553__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1554__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1554__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1554__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1554__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status = 0ULL;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__poll_count = 0U;
    {
        while ((0x4e20U > vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__poll_count)) {
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__address = 0x20038U;
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5028821201664581801ull);
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6985495587040827714ull);
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10776431659455870649ull);
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__address;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 600);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     600);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 601);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 604);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     604);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1556__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1556__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1556__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1556__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1557__message = 
                std::string{"AXI Slave changed read response during host stall"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1557__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1557__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1557__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 612);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 614);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1558__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1558__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1558__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1558__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1559__message = 
                std::string{"AXI Slave returned the wrong RID"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1559__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1559__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1559__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1560__message = 
                std::string{"AXI Slave single read failed"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1560__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1560__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1560__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1561__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1561__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1561__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1561__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status 
                = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__data;
            if ((1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status 
                               >> 1U)))) {
                goto __Vlabel1;
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__poll_count 
                = ((IData)(1U) + vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__poll_count);
        }
        __Vlabel1: ;
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1562__message = 
        std::string{"control request polling timed out"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1562__condition 
        = (1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1562__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1562__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1563__message = 
        std::string{"control request stayed busy after completion"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1563__condition 
        = (1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1563__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1563__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1564__message = 
        std::string{"control window reported an internal failure"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1564__condition 
        = (0U == (0xffU & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1564__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1564__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1565__message = 
        std::string{"control window status reserved bits are nonzero"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1565__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1565__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1565__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__address = 0x20040U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8389132427170794637ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16685310162078859860ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12160322784227297210ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         600);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             600);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         601);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         604);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             604);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1567__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1567__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1567__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1567__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1568__message = 
        std::string{"AXI Slave changed read response during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1568__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1568__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1568__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         612);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         614);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1569__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1569__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1569__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1569__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1570__message = 
        std::string{"AXI Slave returned the wrong RID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1570__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1570__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1570__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1571__message = 
        std::string{"AXI Slave single read failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1571__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1571__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1571__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1572__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1572__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1572__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1572__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__data;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1535__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__result;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1535__result;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1573__message = 
        std::string{"INT16 Matrix pack progress is incorrect"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1573__condition 
        = (4ULL == vlSelfRef.tb_npu_single_core__DOT__ctl_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1573__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1573__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__acknowledge_task__1574__command_id = 0x107U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__acknowledge_task__1574__result = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2571428705450770721ull);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1575__selector = 4U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1575__command_id 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__acknowledge_task__1574__command_id;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__argument1 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1575__selector));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__argument0 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1575__command_id));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__operation = 2U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4792362852885621923ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1576__poll_count = 0;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__data 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__argument0;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__address = 0x20020U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4061655978757977879ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6823436811477635345ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1578__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1578__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1578__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1578__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1579__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1579__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1579__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1579__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1580__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1580__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1580__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1580__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1581__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1581__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1581__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1581__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1582__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1582__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1582__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1582__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__data 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__argument1;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__address = 0x20028U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4546582003619451810ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14804391456058773544ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1584__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1584__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1584__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1584__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1585__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1585__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1585__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1585__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1586__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1586__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1586__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1586__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1587__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1587__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1587__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1587__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1588__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1588__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1588__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1588__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__data 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__operation));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__address = 0x20030U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3052695406479855192ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6463220792117450163ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1590__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1590__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1590__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1590__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1591__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1591__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1591__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1591__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1592__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1592__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1592__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1592__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1593__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1593__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1593__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1593__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1594__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1594__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1594__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1594__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status = 0ULL;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__poll_count = 0U;
    {
        while ((0x4e20U > vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__poll_count)) {
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__address = 0x20038U;
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3402767623919169640ull);
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14454354453382195889ull);
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6985855388382305058ull);
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__address;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 600);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     600);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 601);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 604);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     604);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1596__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1596__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1596__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1596__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1597__message = 
                std::string{"AXI Slave changed read response during host stall"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1597__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1597__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1597__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 612);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 614);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1598__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1598__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1598__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1598__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1599__message = 
                std::string{"AXI Slave returned the wrong RID"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1599__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1599__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1599__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1600__message = 
                std::string{"AXI Slave single read failed"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1600__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1600__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1600__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1601__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1601__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1601__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1601__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status 
                = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1595__data;
            if ((1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status 
                               >> 1U)))) {
                goto __Vlabel2;
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__poll_count 
                = ((IData)(1U) + vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__poll_count);
        }
        __Vlabel2: ;
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1602__message = 
        std::string{"control request polling timed out"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1602__condition 
        = (1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1602__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1602__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1603__message = 
        std::string{"control request stayed busy after completion"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1603__condition 
        = (1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1603__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1603__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1604__message = 
        std::string{"control window reported an internal failure"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1604__condition 
        = (0U == (0xffU & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1604__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1604__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1605__message = 
        std::string{"control window status reserved bits are nonzero"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1605__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1605__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1605__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__address = 0x20040U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11066262605308097167ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14349498641428824955ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7912393072372769947ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         600);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             600);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         601);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         604);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             604);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1607__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1607__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1607__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1607__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1608__message = 
        std::string{"AXI Slave changed read response during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1608__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1608__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1608__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         612);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         614);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1609__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1609__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1609__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1609__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1610__message = 
        std::string{"AXI Slave returned the wrong RID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1610__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1610__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1610__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1611__message = 
        std::string{"AXI Slave single read failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1611__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1611__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1611__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1612__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1612__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1612__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1612__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1606__data;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1575__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__result;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__acknowledge_task__1574__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1575__result;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1613__message = 
        std::string{"task ACK failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1613__condition 
        = (0ULL == vlSelfRef.__Vtask_tb_npu_single_core__DOT__acknowledge_task__1574__result);
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1613__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1613__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1496__selector = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1496__command_id = 0x108U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__argument1 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1496__selector));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__argument0 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1496__command_id));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__operation = 2U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9911163044651935087ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1497__poll_count = 0;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__data 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__argument0;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__address = 0x20020U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7490793861977190552ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10789861173747183375ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
}

VlCoroutine Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__17(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_initial__TOP__Vtiming__0__17\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1499__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1499__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1499__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1499__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1500__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1500__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1498__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1500__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1500__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1501__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1501__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1501__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1501__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1502__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1502__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1502__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1502__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1503__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1503__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1503__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1503__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__data 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__argument1;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__address = 0x20028U;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17358175357095065069ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2933013935391769655ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1505__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1505__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1505__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1505__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1506__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1506__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1504__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1506__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1506__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1507__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1507__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1507__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1507__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1508__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1508__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1508__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1508__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1509__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1509__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1509__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1509__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__data 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__operation));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__address = 0x20030U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17745592791394368246ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 64903836166300487ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1511__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1511__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1511__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1511__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1512__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1512__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1510__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1512__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1512__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1513__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1513__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1513__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1513__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1514__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1514__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1514__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1514__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1515__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1515__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1515__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1515__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status = 0ULL;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__poll_count = 0U;
    {
        while ((0x4e20U > vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__poll_count)) {
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__address = 0x20038U;
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18332226371053824922ull);
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13584156324243209474ull);
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14473746424445454022ull);
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__address;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 600);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     600);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 601);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 604);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     604);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1517__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1517__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1517__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1517__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1518__message = 
                std::string{"AXI Slave changed read response during host stall"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1518__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1518__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1518__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 612);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 614);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1519__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1519__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1519__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1519__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1520__message = 
                std::string{"AXI Slave returned the wrong RID"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1520__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1520__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1520__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1521__message = 
                std::string{"AXI Slave single read failed"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1521__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1521__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1521__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1522__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1522__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1522__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1522__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status 
                = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1516__data;
            if ((1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status 
                               >> 1U)))) {
                goto __Vlabel0;
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__poll_count 
                = ((IData)(1U) + vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__poll_count);
        }
        __Vlabel0: ;
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1523__message = 
        std::string{"control request polling timed out"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1523__condition 
        = (1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1523__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1523__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1524__message = 
        std::string{"control request stayed busy after completion"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1524__condition 
        = (1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1524__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1524__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1525__message = 
        std::string{"control window reported an internal failure"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1525__condition 
        = (0U == (0xffU & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1525__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1525__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1526__message = 
        std::string{"control window status reserved bits are nonzero"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1526__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1526__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1526__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__address = 0x20040U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7337237412135300662ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10623455078878347306ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7757374652300179137ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         600);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             600);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         601);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         604);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             604);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1528__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1528__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1528__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1528__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1529__message = 
        std::string{"AXI Slave changed read response during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1529__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1529__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1529__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         612);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         614);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1530__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1530__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1530__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1530__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1531__message = 
        std::string{"AXI Slave returned the wrong RID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1531__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1531__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1531__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1532__message = 
        std::string{"AXI Slave single read failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1532__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1532__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1532__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1533__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1533__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1533__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1533__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1527__data;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1496__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1497__result;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1496__result;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1534__message = 
        std::string{"INT16 Matrix pack task status is incorrect"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1534__condition 
        = (IData)((0x23ULL == (0xfffULL & vlSelfRef.tb_npu_single_core__DOT__ctl_data)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1534__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1534__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1535__selector = 3U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1535__command_id = 0x108U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__argument1 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1535__selector));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__argument0 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1535__command_id));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__operation = 2U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 18320117521651841311ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1536__poll_count = 0;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__data 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__argument0;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__address = 0x20020U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17077821235074897542ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4304897147433023252ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1538__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1538__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1538__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1538__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1539__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1539__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1537__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1539__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1539__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1540__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1540__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1540__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1540__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1541__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1541__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1541__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1541__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1542__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1542__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1542__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1542__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__data 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__argument1;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__address = 0x20028U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5782266350681631203ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3638157727177461467ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1544__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1544__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1544__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1544__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1545__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1545__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1543__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1545__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1545__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1546__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1546__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1546__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1546__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1547__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1547__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1547__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1547__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1548__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1548__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1548__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1548__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__data 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__operation));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__address = 0x20030U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 718934160309065236ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1452101477211717602ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1550__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1550__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1550__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1550__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1551__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1551__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1549__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1551__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1551__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1552__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1552__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1552__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1552__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1553__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1553__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1553__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1553__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1554__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1554__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1554__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1554__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status = 0ULL;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__poll_count = 0U;
    {
        while ((0x4e20U > vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__poll_count)) {
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__address = 0x20038U;
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5028821201664581801ull);
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6985495587040827714ull);
            vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10776431659455870649ull);
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 592);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
                = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__address;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 600);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     600);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 601);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 604);
            while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
                co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                     nullptr, 
                                                                     "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                     "tb/tb_npu_single_core.sv", 
                                                                     604);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__observed_data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__observed_response 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 607);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1556__message = 
                std::string{"AXI Slave dropped RVALID during host stall"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1556__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1556__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1556__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1557__message = 
                std::string{"AXI Slave changed read response during host stall"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1557__condition 
                = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
                    == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__observed_data) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
                      == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__observed_response)));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1557__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1557__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 612);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
            co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(posedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 614);
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1558__message = 
                std::string{"AXI Slave RVALID disappeared before handshake"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1558__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1558__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1558__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1559__message = 
                std::string{"AXI Slave returned the wrong RID"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1559__condition 
                = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1559__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1559__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1560__message = 
                std::string{"AXI Slave single read failed"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1560__condition 
                = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1560__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1560__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1561__message = 
                std::string{"AXI Slave single read did not assert RLAST"};
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1561__condition 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
            if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1561__condition)))))) {
                VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),-1,
                             &(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1561__message));
                VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__data 
                = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
            co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                                 nullptr, 
                                                                 "@(negedge tb_npu_single_core.core_clk_i)", 
                                                                 "tb/tb_npu_single_core.sv", 
                                                                 620);
            vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status 
                = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1555__data;
            if ((1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status 
                               >> 1U)))) {
                goto __Vlabel1;
            }
            vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__poll_count 
                = ((IData)(1U) + vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__poll_count);
        }
        __Vlabel1: ;
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1562__message = 
        std::string{"control request polling timed out"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1562__condition 
        = (1U & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status 
                         >> 1U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1562__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1562__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1563__message = 
        std::string{"control request stayed busy after completion"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1563__condition 
        = (1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1563__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1563__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1564__message = 
        std::string{"control window reported an internal failure"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1564__condition 
        = (0U == (0xffU & (IData)((vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status 
                                   >> 8U))));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1564__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1564__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1565__message = 
        std::string{"control window status reserved bits are nonzero"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1565__condition 
        = (IData)((0ULL == (0xffffffffffff00fcULL & vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__status)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1565__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1565__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__address = 0x20040U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8389132427170794637ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__observed_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16685310162078859860ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12160322784227297210ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         592);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arid_i = 0x52U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         600);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             600);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         601);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         604);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             604);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__observed_data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         607);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__tb_npu_single_core__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1567__message = 
        std::string{"AXI Slave dropped RVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1567__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1567__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1567__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1568__message = 
        std::string{"AXI Slave changed read response during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1568__condition 
        = ((vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o 
            == vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__observed_data) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o) 
              == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__observed_response)));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1568__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1568__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         612);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         614);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1569__message = 
        std::string{"AXI Slave RVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1569__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1569__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1569__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1570__message = 
        std::string{"AXI Slave returned the wrong RID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1570__condition 
        = (0x52U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1570__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1570__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1571__message = 
        std::string{"AXI Slave single read failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1571__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1571__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1571__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1572__message = 
        std::string{"AXI Slave single read did not assert RLAST"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1572__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1572__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1572__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__data 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         620);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_read_single__1566__data;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1535__result 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1536__result;
    vlSelfRef.tb_npu_single_core__DOT__ctl_data = vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1535__result;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1573__message = 
        std::string{"INT16 Matrix pack progress is incorrect"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1573__condition 
        = (0ULL == vlSelfRef.tb_npu_single_core__DOT__ctl_data);
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1573__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1573__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__acknowledge_task__1574__command_id = 0x108U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__acknowledge_task__1574__result = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2571428705450770721ull);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1575__selector = 4U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1575__command_id 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__acknowledge_task__1574__command_id;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__argument1 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1575__selector));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__argument0 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__query_task__1575__command_id));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__operation = 2U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4792362852885621923ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__ctl_request__1576__poll_count = 0;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__data 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__argument0;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__address = 0x20020U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4061655978757977879ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6823436811477635345ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1578__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1578__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1578__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1578__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1579__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1579__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1577__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1579__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1579__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1580__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1580__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1580__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1580__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1581__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1581__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1581__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1581__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1582__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1582__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1582__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1582__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__data 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__argument1;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__address = 0x20028U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4546582003619451810ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14804391456058773544ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1584__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1584__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1584__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1584__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1585__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1585__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1583__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1585__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1585__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1586__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1586__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1586__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1586__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1587__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1587__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1587__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1587__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1588__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1588__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1588__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1588__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__strobe = 0xffU;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__data 
        = (QData)((IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__operation));
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__address = 0x20030U;
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3052695406479855192ull);
    vlSelf->__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__observed_response = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6463220792117450163ull);
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         550);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awid_i = 0x31U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__address;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i = 3U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         558);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             558);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         559);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i = 0U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wdata_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__data;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i 
        = vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__strobe;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i = 1U;
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         566);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             566);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         567);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i = 0U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         570);
    while ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)))) {
        co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_npu_single_core.core_clk_i)", 
                                                             "tb/tb_npu_single_core.sv", 
                                                             570);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__observed_response 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         572);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__tb_npu_single_core__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1590__message = 
        std::string{"AXI Slave dropped BVALID during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1590__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1590__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1590__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1591__message = 
        std::string{"AXI Slave changed BRESP during host stall"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1591__condition 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o) 
           == (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__axi_write_single__1589__observed_response));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1591__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1591__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         576);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 1U;
    co_await vlSelfRef.__VtrigSched_heaff7433__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         578);
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1592__message = 
        std::string{"AXI Slave BVALID disappeared before handshake"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1592__condition 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1592__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1592__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1593__message = 
        std::string{"AXI Slave returned the wrong BID"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1593__condition 
        = (0x31U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1593__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1593__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1594__message = 
        std::string{"AXI Slave single write failed"};
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1594__condition 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o));
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1594__condition)))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_npu_single_core.sv:429: Assertion failed in %Ntb_npu_single_core.check: %@\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     -1,&(vlSelfRef.__Vtask_tb_npu_single_core__DOT__check__1594__message));
        VL_STOP_MT("tb/tb_npu_single_core.sv", 429, "", false);
    }
    co_await vlSelfRef.__VtrigSched_heaff72f2__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_npu_single_core.core_clk_i)", 
                                                         "tb/tb_npu_single_core.sv", 
                                                         582);
    vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i = 0U;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__status = 0ULL;
    vlSelfRef.__Vtask_tb_npu_single_core__DOT__ctl_request__1576__poll_count = 0U;
}
