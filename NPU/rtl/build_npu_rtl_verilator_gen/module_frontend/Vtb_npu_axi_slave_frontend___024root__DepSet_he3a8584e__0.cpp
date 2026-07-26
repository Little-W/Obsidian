// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_axi_slave_frontend.h for the primary calling header

#include "Vtb_npu_axi_slave_frontend__pch.h"
#include "Vtb_npu_axi_slave_frontend___024root.h"

VlCoroutine Vtb_npu_axi_slave_frontend___024root___eval_initial__TOP__Vtiming__0(Vtb_npu_axi_slave_frontend___024root* vlSelf);
VlCoroutine Vtb_npu_axi_slave_frontend___024root___eval_initial__TOP__Vtiming__1(Vtb_npu_axi_slave_frontend___024root* vlSelf);
VlCoroutine Vtb_npu_axi_slave_frontend___024root___eval_initial__TOP__Vtiming__2(Vtb_npu_axi_slave_frontend___024root* vlSelf);

void Vtb_npu_axi_slave_frontend___024root___eval_initial(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_initial\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_npu_axi_slave_frontend___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_npu_axi_slave_frontend___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_npu_axi_slave_frontend___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

void Vtb_npu_axi_slave_frontend___024root___act_comb__TOP__0(Vtb_npu_axi_slave_frontend___024root* vlSelf);

void Vtb_npu_axi_slave_frontend___024root___eval_act(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_act\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((5ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb_npu_axi_slave_frontend___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_npu_axi_slave_frontend___024root___act_comb__TOP__0(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___act_comb__TOP__0\n"); );
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
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_ready 
        = ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid)) 
           & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_enable));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT____VdfgRegularize_h97cdcae2_0_0 
        = ((1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlen)))) 
           & ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arsize)) 
              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlock)) 
                 & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arburst)))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arready 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reset_n) 
           & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid)) 
                 & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
                    & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid)) 
                       & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid)))))));
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
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_current_error_w 
        = (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast) 
            != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_last_expected_w)) 
           | ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
              & (0xffU != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb))));
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
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_complete_error_w 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q) 
           | (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_current_error_w));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid) 
           & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_ready));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_commit_w 
        = ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
           & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid) 
              & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready) 
                 & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_complete_error_w)) 
                    & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_last_expected_w)))));
}

void Vtb_npu_axi_slave_frontend___024root___nba_sequent__TOP__0(Vtb_npu_axi_slave_frontend___024root* vlSelf);
void Vtb_npu_axi_slave_frontend___024root___nba_comb__TOP__0(Vtb_npu_axi_slave_frontend___024root* vlSelf);
void Vtb_npu_axi_slave_frontend___024root___nba_comb__TOP__1(Vtb_npu_axi_slave_frontend___024root* vlSelf);

void Vtb_npu_axi_slave_frontend___024root___eval_nba(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_nba\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_axi_slave_frontend___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_axi_slave_frontend___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_axi_slave_frontend___024root___nba_comb__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_npu_axi_slave_frontend___024root___nba_comb__TOP__0(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___nba_comb__TOP__0\n"); );
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
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT____VdfgRegularize_h97cdcae2_0_0 
        = ((1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlen)))) 
           & ((3U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arsize)) 
              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arlock)) 
                 & (1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arburst)))));
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
}

VL_INLINE_OPT void Vtb_npu_axi_slave_frontend___024root___nba_comb__TOP__1(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___nba_comb__TOP__1\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_pop_w 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid) 
           & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_pop_rsp_q) 
              & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rready)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_ready 
        = ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid)) 
           & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cfe_enable));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_arready 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__reset_n) 
           & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_rvalid)) 
                 & ((0U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
                    & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_bvalid)) 
                       & (~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_awvalid)))))));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_current_error_w 
        = (((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wlast) 
            != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_last_expected_w)) 
           | ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
              & (0xffU != (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wstrb))));
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
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_ready 
        = ((2U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_state_q)) 
           & ((8U > (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_count_q)) 
              | (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__rsp_pop_w)));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_complete_error_w 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_error_q) 
           | (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_current_error_w));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_pop_w 
        = ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_valid) 
           & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__cmd_rsp_ready));
    vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__cmd_commit_w 
        = ((1U == (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_state_q)) 
           & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wvalid) 
              & ((IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__s_axi_wready) 
                 & ((~ (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_complete_error_w)) 
                    & (IData)(vlSelfRef.tb_npu_axi_slave_frontend__DOT__dut__DOT__wr_last_expected_w)))));
}

void Vtb_npu_axi_slave_frontend___024root___timing_resume(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___timing_resume\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h4a2ae8f4__0.resume(
                                                   "@(posedge tb_npu_axi_slave_frontend.clk_i)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h4a2ae8b1__0.resume(
                                                   "@(negedge tb_npu_axi_slave_frontend.clk_i)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_npu_axi_slave_frontend___024root___timing_commit(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___timing_commit\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h4a2ae8f4__0.commit(
                                                   "@(posedge tb_npu_axi_slave_frontend.clk_i)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h4a2ae8b1__0.commit(
                                                   "@(negedge tb_npu_axi_slave_frontend.clk_i)");
    }
}

void Vtb_npu_axi_slave_frontend___024root___eval_triggers__act(Vtb_npu_axi_slave_frontend___024root* vlSelf);

bool Vtb_npu_axi_slave_frontend___024root___eval_phase__act(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_phase__act\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_npu_axi_slave_frontend___024root___eval_triggers__act(vlSelf);
    Vtb_npu_axi_slave_frontend___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_npu_axi_slave_frontend___024root___timing_resume(vlSelf);
        Vtb_npu_axi_slave_frontend___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_npu_axi_slave_frontend___024root___eval_phase__nba(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_phase__nba\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_npu_axi_slave_frontend___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___dump_triggers__nba(Vtb_npu_axi_slave_frontend___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_axi_slave_frontend___024root___dump_triggers__act(Vtb_npu_axi_slave_frontend___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_npu_axi_slave_frontend___024root___eval(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_npu_axi_slave_frontend___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_npu_axi_slave_frontend.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_npu_axi_slave_frontend___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_npu_axi_slave_frontend.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_npu_axi_slave_frontend___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_npu_axi_slave_frontend___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_npu_axi_slave_frontend___024root___eval_debug_assertions(Vtb_npu_axi_slave_frontend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_axi_slave_frontend___024root___eval_debug_assertions\n"); );
    Vtb_npu_axi_slave_frontend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
