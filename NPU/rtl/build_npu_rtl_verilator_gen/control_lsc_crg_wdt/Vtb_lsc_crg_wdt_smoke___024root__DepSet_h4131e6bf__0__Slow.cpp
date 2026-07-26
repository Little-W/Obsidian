// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_lsc_crg_wdt_smoke.h for the primary calling header

#include "Vtb_lsc_crg_wdt_smoke__pch.h"
#include "Vtb_lsc_crg_wdt_smoke___024root.h"

VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___eval_static(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_static\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__clk__0 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__reset_n__0 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reset_n;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__noc_clk__0 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__noc_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q__0 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse__0 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse;
    vlSelfRef.__Vtrigprevexpr_hf82c736a__1 = (3U == (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q));
}

VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___eval_final(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_final\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__stl(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_lsc_crg_wdt_smoke___024root___eval_phase__stl(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);

VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___eval_settle(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_settle\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("control/tb_lsc_crg_wdt_smoke.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_lsc_crg_wdt_smoke___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__stl(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__stl\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___stl_sequent__TOP__0(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);

VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___eval_stl(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_stl\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_lsc_crg_wdt_smoke___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___stl_sequent__TOP__0(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___stl_sequent__TOP__0\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_ready 
        = (1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q)));
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_requested 
        = ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__soft_reset_req) 
           | (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q));
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__module_clk_active 
        = (0xffU & ((~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__module_idle)) 
                    | (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__module_clk_en)));
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__core_clk_gated 
        = ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__clk) 
           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_gate_enable_q));
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__noc_clk_gated 
        = ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__noc_clk) 
           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_gate_enable_q));
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_read_data 
        = ((0x8000U & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
            ? 0ULL : ((0x4000U & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                       ? 0ULL : ((0x2000U & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                  ? 0ULL : ((0x1000U 
                                             & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                             ? 0ULL
                                             : ((0x800U 
                                                 & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                 ? 0ULL
                                                 : 
                                                ((0x400U 
                                                  & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                  ? 0ULL
                                                  : 
                                                 ((0x200U 
                                                   & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                   ? 
                                                  ((0x100U 
                                                    & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                    ? 0ULL
                                                    : 
                                                   ((0x80U 
                                                     & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                     ? 
                                                    ((0x40U 
                                                      & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                      ? 
                                                     ((0x20U 
                                                       & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                       ? 0ULL
                                                       : 
                                                      ((0x10U 
                                                        & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                        ? 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 0ULL
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__module_clk_enable_q))))))
                                                        : 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__wdt_timeout_cycles_q)))))
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__wdt_enable_q))))))))
                                                      : 0ULL)
                                                     : 0ULL))
                                                   : 
                                                  ((0x100U 
                                                    & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                    ? 0ULL
                                                    : 
                                                   ((0x80U 
                                                     & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                     ? 
                                                    ((0x40U 
                                                      & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                      ? 
                                                     ((0x20U 
                                                       & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                       ? 
                                                      ((0x10U 
                                                        & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                        ? 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 0ULL
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__l1_host_access_enable_q))))))
                                                        : 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_reason_q)))))
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_lock_q)))))))
                                                       : 
                                                      ((0x10U 
                                                        & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                        ? 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q)))))
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_base_q))))))
                                                        : 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 0ULL
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q)
                                                             ? (QData)((IData)(
                                                                               (((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_opcode_q) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_engine_q) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_status_q)))))
                                                             : 0ULL)))))))
                                                      : 
                                                     ((0x20U 
                                                       & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                       ? 
                                                      ((0x10U 
                                                        & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                        ? 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q)
                                                             ? vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_addr_q
                                                             : 0ULL))))
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q)
                                                             ? (QData)((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_command_id_q))
                                                             : 0ULL)))))
                                                        : 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_mask_q)))))
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q)))))))
                                                       : 
                                                      ((0x10U 
                                                        & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                        ? 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 0ULL
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(
                                                                              (((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__tbu_substream_id_q) 
                                                                                << 0x10U) 
                                                                               | (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__tbu_stream_id_q))))))))
                                                        : 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q)))
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_base_q)))))))
                                                     : 
                                                    ((0x40U 
                                                      & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                      ? 
                                                     ((0x20U 
                                                       & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                       ? 
                                                      ((0x10U 
                                                        & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                        ? 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__kv_base_q)))
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__output_base_q))))
                                                        : 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__work_base_q)))
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__weight_base_q)))))
                                                       : 
                                                      ((0x10U 
                                                        & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                        ? 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__input_base_q)))
                                                         : 0ULL)
                                                        : 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(
                                                                              (1U 
                                                                               | ((((0U 
                                                                                != (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q)) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__stop_q) 
                                                                                << 4U) 
                                                                                | ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q) 
                                                                                << 3U))) 
                                                                                | (((~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__stop_q)) 
                                                                                & ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__start_q) 
                                                                                & (0U 
                                                                                == (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q)))) 
                                                                                << 2U))))))))
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : (QData)((IData)(
                                                                              (((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__stop_q) 
                                                                                << 1U) 
                                                                               | (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__start_q))))))))))
                                                      : 
                                                     ((0x20U 
                                                       & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                       ? 
                                                      ((0x10U 
                                                        & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                        ? 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 0ULL
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 0x1000003fff04ULL))))
                                                        : 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 0x3ff08ULL)))
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 0x7081008ULL)))))
                                                       : 
                                                      ((0x10U 
                                                        & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                        ? 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 0x21000100000ULL)))
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 0x8283040ULL))))
                                                        : 
                                                       ((8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                         ? 0ULL
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((2U 
                                                           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((1U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 0x100010001ULL))))))))))))))));
}

VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___eval_triggers__stl(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);

VL_ATTR_COLD bool Vtb_lsc_crg_wdt_smoke___024root___eval_phase__stl(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_phase__stl\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_lsc_crg_wdt_smoke___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_lsc_crg_wdt_smoke___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__act(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__act\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_lsc_crg_wdt_smoke.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_lsc_crg_wdt_smoke.reset_n)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge tb_lsc_crg_wdt_smoke.noc_clk)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge tb_lsc_crg_wdt_smoke.clk)\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(negedge tb_lsc_crg_wdt_smoke.noc_clk)\n");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @( tb_lsc_crg_wdt_smoke.u_lsc.rsp_valid_q)\n");
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @( tb_lsc_crg_wdt_smoke.internal_soft_reset_pulse)\n");
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @( (2'h3 == tb_lsc_crg_wdt_smoke.u_lsc.reset_state_q))\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__nba(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__nba\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_lsc_crg_wdt_smoke.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_lsc_crg_wdt_smoke.reset_n)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge tb_lsc_crg_wdt_smoke.noc_clk)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge tb_lsc_crg_wdt_smoke.clk)\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(negedge tb_lsc_crg_wdt_smoke.noc_clk)\n");
    }
    if ((0x20ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @( tb_lsc_crg_wdt_smoke.u_lsc.rsp_valid_q)\n");
    }
    if ((0x80ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @( tb_lsc_crg_wdt_smoke.internal_soft_reset_pulse)\n");
    }
    if ((0x100ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @( (2'h3 == tb_lsc_crg_wdt_smoke.u_lsc.reset_state_q))\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___ctor_var_reset(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___ctor_var_reset\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6845919763987265486ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__noc_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11736732904986596547ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11012307977091007884ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__sync_reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1359451521481933375ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__reg_req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17256144795139555041ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__reg_req_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7773935375790216902ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__reg_req_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12346532497688154761ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__reg_req_addr = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17160840710225734963ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16087708584170852899ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8784157875114444989ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__single_step_pulse = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9740438012012280419ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__soft_reset_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12210934805461800046ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1919308977125252955ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18057610946762278438ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__task_terminal_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11830052618449450089ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__task_command_id = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 18287160544584789388ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__task_engine = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16373094272237272753ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__task_opcode = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3713150817202980294ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__task_status = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8989974082854167555ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__task_fault_addr = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 14842204628896774502ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__interface_error_clear = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15858193027857855134ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__lsc_wdt_kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12921253563272169328ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__wdt_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17908476935551302902ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__wdt_timeout_cycles = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6945597329773003326ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__wdt_kick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13645678365158848741ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__wdt_progress = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10774545858106570196ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__module_clk_en = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16980413665440738629ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__module_idle = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10999038773953702827ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__module_clk_active = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14126303415910362959ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__core_clk_gated = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14464380393698546102ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__noc_clk_gated = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14410740372990073520ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11136690199194598933ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_data_q = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7962362179143116927ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7154247660887816653ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__start_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17208920978934019503ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__stop_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14295787443378813835ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13816639913079335438ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_mask_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4384948194284921624ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7373883006036007165ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_command_id_q = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 14928429834539170364ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_engine_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13845542847710269649ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_opcode_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18367372675195130863ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_status_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17885134305186904937ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_addr_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 15404370754766902765ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_reason_q = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11215504203886432437ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__input_base_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 9506132391745999448ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__weight_base_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 10659064694857445669ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__work_base_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 1982915012962216206ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__output_base_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 17553842426814495655ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__kv_base_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 16686068260211052661ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_base_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 16816442106441195929ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 6511508667661891986ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__tbu_stream_id_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6973131878311519531ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__tbu_substream_id_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15779479761701177538ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_base_q = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 16741997001392224375ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 2913864455606839923ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_lock_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12502531081235722440ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__l1_host_access_enable_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10699050208946114851ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__module_clk_enable_q = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15851920396108949956ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__wdt_enable_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 486696444247863744ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__wdt_timeout_cycles_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10081840811686089701ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1520330290884351308ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16237386259481877702ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_read_data = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8026944581706591713ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_requested = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6384029075387525893ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12744699663986570864ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6073554437689957716ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_reset_sync_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2297883935198540917ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_reset_sync_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8152945457720737432ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_gate_enable_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2142293524905041054ull);
    vlSelf->tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_gate_enable_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6183512837166275939ull);
    vlSelf->__Vdly__tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_reset_sync_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6591851743155967868ull);
    vlSelf->__Vdly__tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_reset_sync_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12309673652730049998ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11777096930044390439ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__reset_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14152953999472307412ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__noc_clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18238512121146396823ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14128909464501329066ull);
    vlSelf->__Vtrigprevexpr___TOP__tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14974912677679102363ull);
    vlSelf->__Vtrigprevexpr_hf82c736a__1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14729673535184478251ull);
    vlSelf->__VactDidInit = 0;
}
