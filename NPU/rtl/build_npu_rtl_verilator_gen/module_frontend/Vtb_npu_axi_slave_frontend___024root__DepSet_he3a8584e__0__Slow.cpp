// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_axi_slave_frontend.h for the primary calling header

#include "Vtb_npu_axi_slave_frontend__pch.h"
#include "Vtb_npu_axi_slave_frontend___024root.h"

VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___eval_static(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_static\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_axi_slave_frontend__DOT__clk_i__0 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_axi_slave_frontend__DOT__reset_n__0 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__reset_n;
}

VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___eval_final(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_final\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___dump_triggers__stl(Vtb_npu_axi_slave_frontend___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_npu_axi_slave_frontend___024root___eval_phase__stl(Vtb_npu_axi_slave_frontend___024root* vlSelf);

VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___eval_settle(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_settle\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_npu_axi_slave_frontend___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_npu_axi_slave_frontend.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_npu_axi_slave_frontend___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___dump_triggers__stl(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___dump_triggers__stl\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___stl_sequent__TOP__0(Vtb_npu_axi_slave_frontend___024root* vlSelf);

VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___eval_stl(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_stl\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_npu_axi_slave_frontend___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___stl_sequent__TOP__0(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___stl_sequent__TOP__0\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__Vfuncout;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__addr;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__addr = 0;
    SData/*8:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__beats;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__beats = 0;
    CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__size;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__size = 0;
    CData/*1:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__burst;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__burst = 0;
    CData/*0:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__lock;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__lock = 0;
    IData/*24:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__last_addr;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__last_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__Vfuncout;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__addr;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__addr = 0;
    SData/*8:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__beats;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__beats = 0;
    CData/*2:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__size;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__size = 0;
    CData/*1:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__burst;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__burst = 0;
    CData/*0:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__lock;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__lock = 0;
    IData/*24:0*/ __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__last_addr;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__last_addr = 0;
    // Body
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_ready 
        = (1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_pending_q)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_ready 
        = (1U & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_pending_q)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_ready 
        = ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid)) 
           & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_enable));
    if ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q))) {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr 
            = (0xfff8U & vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_addr_q);
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
            = (0xffff8U & vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_addr_q);
    } else {
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_addr 
            = (0xfff8U & vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q);
        vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_addr 
            = (0xffff8U & vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q);
    }
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_rsp_ready 
        = (((4U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
            & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q))) 
           | ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
              & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_rsp_ready 
        = (((4U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
            & (2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q))) 
           | ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
              & (2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT____VdfgRegularize_h97cdcae2_0_0 
        = ((1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlen)))) 
           & ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arsize)) 
              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlock)) 
                 & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arburst)))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__fifo_status_w 
        = (QData)((IData)(((((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__protocol_error) 
                             << 0x13U) | ((8U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q)) 
                                          << 0x12U)) 
                           | (((0x10U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q)) 
                               << 0x11U) | ((((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
                                              & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q)) 
                                             << 0x10U) 
                                            | (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q) 
                                                << 8U) 
                                               | (0xffU 
                                                  & ((IData)(0x10U) 
                                                     - (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q)))))))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arready 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reset_n) 
           & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid)) 
                 & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
                    & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid)) 
                       & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid)))))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__reg_req_valid 
        = (((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
            & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_sent_q)) 
               & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q)))) 
           | ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_req_sent_q)) 
                 & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q)))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__l1_req_valid 
        = (((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
            & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_sent_q)) 
               & (2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q)))) 
           | ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_req_sent_q)) 
                 & (2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q)))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready 
        = ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
           | ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
              | (5U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_data 
        = ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q))
            ? vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem
           [([&]() {
                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__base 
                    = vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_rptr_q;
                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__value 
                    = ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__base));
                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__Vfuncout 
                    = (0xfU & vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__value);
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__Vfuncout))]
            : vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem
           [vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_rptr_q]);
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_valid 
        = ((2U <= (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q)) 
           & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q)) 
              | (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_csr_format_w 
        = ((((((0x20000U > vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr) 
               & (1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen))))) 
              & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awburst))) 
             & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlock))) 
            & (3U >= (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awsize))) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__addr_low 
                    = (7U & vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr);
                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__size 
                    = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awsize;
                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__Vfuncout 
                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__size) 
                                 >> 2U))) && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__size))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__size))
                                                   ? 
                                                  (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__addr_low))
                                                   : 
                                                  (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__addr_low))))
                                               : ((1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__size))) 
                                                  || (1U 
                                                      & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__addr_low))))));
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__Vfuncout)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ar_csr_format_w 
        = ((((((0x20000U > vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr) 
               & (1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlen))))) 
              & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arburst))) 
             & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlock))) 
            & (3U >= (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arsize))) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__addr_low 
                    = (7U & vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr);
                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__size 
                    = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arsize;
                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__Vfuncout 
                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__size) 
                                 >> 2U))) && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__size))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__size))
                                                   ? 
                                                  (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__addr_low))
                                                   : 
                                                  (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__addr_low))))
                                               : ((1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__size))) 
                                                  || (1U 
                                                      & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__addr_low))))));
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__Vfuncout)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_pop_w 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid) 
           & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_pop_rsp_q) 
              & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_cmd_format_w 
        = ((0x20000U == vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr) 
           & ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awsize)) 
              & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awburst)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlock)) 
                    & ((2U <= (0x1ffU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen)))) 
                       & ((~ ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen))) 
                          & (0x10U >= (0x1ffU & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen))))))))));
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__lock 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlock;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__burst 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awburst;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__size 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awsize;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__beats 
        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen)));
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__addr 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awaddr;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__last_addr 
        = (0x1ffffffU & (__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__addr 
                         + (((IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__beats) 
                             - (IData)(1U)) << (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__size))));
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__Vfuncout 
        = ((((((((~ (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__lock)) 
                 & (1U == (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__burst))) 
                & (3U >= (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__size))) 
               & ([&]() {
                                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__addr_low 
                                    = (7U & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__addr);
                                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__size 
                                    = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__size;
                                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__Vfuncout 
                                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__size) 
                                                 >> 2U))) 
                                       && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__size))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__size))
                                                ? (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__addr_low))
                                                : (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__addr_low))))
                                            : ((1U 
                                                & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__size))) 
                                               || (1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__addr_low))))));
                            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__Vfuncout))) 
              & ((1U == (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__beats)) 
                 | (3U == (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__size)))) 
             & (0x100000U <= __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__addr)) 
            & (0x1fffffU >= __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__last_addr)) 
           & ((0xfffU & (__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__addr 
                         >> 0xcU)) == (0xfffU & (__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__last_addr 
                                                 >> 0xcU))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_l1_format_w 
        = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__62__Vfuncout;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__lock 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlock;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__burst 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arburst;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__size 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arsize;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__beats 
        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlen)));
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__addr 
        = vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_araddr;
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__last_addr 
        = (0x1ffffffU & (__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__addr 
                         + (((IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__beats) 
                             - (IData)(1U)) << (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__size))));
    __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__Vfuncout 
        = ((((((((~ (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__lock)) 
                 & (1U == (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__burst))) 
                & (3U >= (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__size))) 
               & ([&]() {
                                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__addr_low 
                                    = (7U & __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__addr);
                                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__size 
                                    = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__size;
                                vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__Vfuncout 
                                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__size) 
                                                 >> 2U))) 
                                       && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__size))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__size))
                                                ? (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__addr_low))
                                                : (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__addr_low))))
                                            : ((1U 
                                                & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__size))) 
                                               || (1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__addr_low))))));
                            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__Vfuncout))) 
              & ((1U == (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__beats)) 
                 | (3U == (IData)(__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__size)))) 
             & (0x100000U <= __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__addr)) 
            & (0x1fffffU >= __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__last_addr)) 
           & ((0xfffU & (__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__addr 
                         >> 0xcU)) == (0xfffU & (__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__last_addr 
                                                 >> 0xcU))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ar_l1_format_w 
        = __Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__l1_burst_ok__65__Vfuncout;
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_last_expected_w 
        = ((0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q))) 
           == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_first 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_valid) 
           & (0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_last 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_valid) 
           & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_ready 
        = ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q)) 
           & ((8U > (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q)) 
              | (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_pop_w)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awready 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reset_n) 
           & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid)) 
                 & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
                    & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid)) 
                       & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_cmd_format_w)) 
                          | ((0x1ffU & ((IData)(0x10U) 
                                        - (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q))) 
                             >= (0x1ffU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awlen))))))))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_current_error_w 
        = (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast) 
            != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_last_expected_w)) 
           | ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
              & (0xffU != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid) 
           & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_ready));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_complete_error_w 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q) 
           | (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_current_error_w));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_commit_w 
        = ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
           & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid) 
              & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready) 
                 & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_complete_error_w)) 
                    & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_last_expected_w)))));
}

VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___eval_triggers__stl(Vtb_npu_axi_slave_frontend___024root* vlSelf);

VL_ATTR_COLD bool Vtb_npu_axi_slave_frontend___024root___eval_phase__stl(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_phase__stl\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_npu_axi_slave_frontend___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_npu_axi_slave_frontend___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___dump_triggers__act(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___dump_triggers__act\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_npu_axi_slave_frontend.clk_i)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_npu_axi_slave_frontend.reset_n)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge tb_npu_axi_slave_frontend.clk_i)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___dump_triggers__nba(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___dump_triggers__nba\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_npu_axi_slave_frontend.clk_i)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_npu_axi_slave_frontend.reset_n)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge tb_npu_axi_slave_frontend.clk_i)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___ctor_var_reset(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___ctor_var_reset\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb_npu_axi_slave_frontend__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4935025009189416344ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17355956862605399345ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_awid = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4959479030494682688ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_awaddr = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12319964494542370620ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_awlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15945540998580270871ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_awsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12460798402056425537ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_awburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14058324183054119944ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_awlock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5383613356618460554ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3905217190997989964ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14785505811858888748ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_wdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5917608909943181183ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_wstrb = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6263522599311387232ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_wlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13981910071885873808ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7552545693156280693ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8126722757255859087ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16596583921966026390ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9616788262208351992ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8285103875314838837ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_arid = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6930029011239486291ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_araddr = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12471271100260853551ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_arlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5155090490352122837ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_arsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16289890815116996660ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_arburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16421461765788672127ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_arlock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15337118096303902930ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4576191645774978560ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6047398984519099981ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_rid = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4424061714273083525ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_rdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4306950078553635432ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8172556402389923721ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_rlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16478306304511529325ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6679435985661941510ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__s_axi_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18212262230753159498ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__cmd_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12350232125272157561ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__cmd_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11018678919979204560ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__cmd_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4410044706934729473ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__cmd_first = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11384570846672951484ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__cmd_last = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15397741925053335419ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12123910412971354006ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__cmd_rsp_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17643222586538482881ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__cmd_rsp_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7203784695262462467ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__reg_req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2953888589111033493ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__reg_req_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1590445278613896847ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__reg_req_addr = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4853187848084586159ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__reg_rsp_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15212081425930416767ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__l1_req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12748197356210086060ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__l1_req_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13132006324358696152ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__l1_req_addr = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 4569558112289409807ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__l1_rsp_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6528219541183711718ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__cfe_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10912583361573177288ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__cfe_have_low_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8004510641499915789ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__cfe_low_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16744263762278344533ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__cfe_command_count_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13061547495059559169ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_npu_axi_slave_frontend__DOT__csr_mem[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5256152736184783294ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_npu_axi_slave_frontend__DOT__l1_mem[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5895038902941005394ull);
    }
    vlSelf->tb_npu_axi_slave_frontend__DOT__reg_pending_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12030572727101733079ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__l1_pending_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 94377269935688048ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__reg_rsp_data_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12633637691597084866ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__l1_rsp_data_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5827685917330897442ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__reg_rsp_status_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12727340862885585747ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__l1_rsp_status_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10801878571006226584ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__protocol_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8094162418211829450ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__protocol_error_clear = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18276409517947256058ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__byte_index = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1624730256894068028ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__staging_mem[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 589976915603471915ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_mem[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9578296449745736726ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_mem[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12234048986666827302ull);
    }
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_wptr_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6713924677208588051ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_rptr_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7629107161785144771ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_count_q = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13192729269268882932ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_wptr_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2128806757436574571ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_rptr_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9514528419536798845ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3622130450539905870ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3319916805174517620ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14075618311604295743ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_target_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2249540451046257953ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_target_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13303838017520209383ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17047454104285214788ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_id_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17785885004630935992ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_addr_q = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11594286307821995782ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_beats_q = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4390155256371015973ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_index_q = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 187538676852201926ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5709902658047167531ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_sent_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1810447113286424495ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_id_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8096287253450141841ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_addr_q = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8602735193498485260ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_beats_q = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 8900659097792654369ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_index_q = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 11245172649400588257ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_size_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6940247193176439053ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_req_sent_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3677046743900136476ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_pop_rsp_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9708394386337519616ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_data_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16553326894382802553ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_strb_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4393765926399527187ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_req_addr_q = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2241725747239299695ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_cmd_format_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5826880495300318500ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_csr_format_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 93880880272471291ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__aw_l1_format_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13751172472877711004ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ar_csr_format_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18030817590980020996ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ar_l1_format_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5951018526983679764ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_commit_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17353204006019480458ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4723432341785286055ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_pop_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7891921505671786045ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_last_expected_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2467587200688969650ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_current_error_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15834846415282866528ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_complete_error_w = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9356720878766754980ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__fifo_status_w = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14814649264016402365ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg0_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17066702318861081278ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_arg1_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15224406560621279396ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_result_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15528878294702872306ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_status_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10610498374513361803ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_busy_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2705308815257726492ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_done_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13128101264407296646ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_pending_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5116346086851019395ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_inflight_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9983904978233386190ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT__ctl_op_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7999216196286468230ull);
    vlSelf->tb_npu_axi_slave_frontend__DOT__dut__DOT____VdfgRegularize_h97cdcae2_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7991395716188661672ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10590314894238397346ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__size = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7190871400032827896ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__61__addr_low = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8190991050917775842ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12084451456379985279ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__size = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12256373381125978645ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__63__addr_low = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3677931122252865530ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6794056755450232014ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__size = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17969022916323837092ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__64__addr_low = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3052469661950947129ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__Vfuncout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1696300512263577647ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__size = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16040491372811605486ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__aligned_for_size__66__addr_low = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4455902629114004651ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__Vfuncout = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15525399019003240098ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__base = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6476397006513684372ull);
    vlSelf->__Vfunc_tb_npu_axi_slave_frontend__DOT__dut__DOT__ingress_ptr_add__67__value = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_npu_axi_slave_frontend__DOT__clk_i__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9671577918144087156ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_npu_axi_slave_frontend__DOT__reset_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17879312493979972019ull);
}
