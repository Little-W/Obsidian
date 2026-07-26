// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_lsc_crg_wdt_smoke.h for the primary calling header

#include "Vtb_lsc_crg_wdt_smoke__pch.h"
#include "Vtb_lsc_crg_wdt_smoke___024root.h"

VlCoroutine Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__0(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
VlCoroutine Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__1(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
VlCoroutine Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__2(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
VlCoroutine Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__3(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);

void Vtb_lsc_crg_wdt_smoke___024root___eval_initial(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_initial\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    Vtb_lsc_crg_wdt_smoke___024root___eval_initial__TOP__Vtiming__3(vlSelf);
}

void Vtb_lsc_crg_wdt_smoke___024root___act_comb__TOP__0(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);

void Vtb_lsc_crg_wdt_smoke___024root___eval_act(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_act\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x1e9ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb_lsc_crg_wdt_smoke___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_lsc_crg_wdt_smoke___024root___act_comb__TOP__0(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___act_comb__TOP__0\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__0(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__1(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__2(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__3(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__4(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
void Vtb_lsc_crg_wdt_smoke___024root___nba_comb__TOP__0(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__5(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
void Vtb_lsc_crg_wdt_smoke___024root___nba_comb__TOP__1(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__6(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
void Vtb_lsc_crg_wdt_smoke___024root___nba_comb__TOP__2(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);

void Vtb_lsc_crg_wdt_smoke___024root___eval_nba(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_nba\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0xaULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x12ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((0x1e9ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_lsc_crg_wdt_smoke___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x1ebULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_lsc_crg_wdt_smoke___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__6(vlSelf);
    }
    if ((0x1fbULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_lsc_crg_wdt_smoke___024root___nba_comb__TOP__2(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__0(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__0\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_reset_sync_q 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_reset_sync_q;
    vlSelfRef.__Vdly__tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_reset_sync_q 
        = ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reset_n)
            ? (1U | (2U & ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_reset_sync_q) 
                           << 1U))) : 0U);
}

VL_INLINE_OPT void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__1(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__1\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_reset_sync_q 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_reset_sync_q;
    vlSelfRef.__Vdly__tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_reset_sync_q 
        = ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reset_n)
            ? (1U | (2U & ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_reset_sync_q) 
                           << 1U))) : 0U);
}

VL_INLINE_OPT void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__2(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__2\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__Vfuncout;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__old_value;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__old_value = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__new_value;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__new_value = 0;
    CData/*7:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__strobe;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__mask;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__mask = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__Vfuncout;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__strobe;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__mask;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__mask = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__Vfuncout;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__old_value;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__old_value = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__new_value;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__new_value = 0;
    CData/*7:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__strobe;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__mask;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__mask = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__Vfuncout;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__strobe;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__mask;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__mask = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__Vfuncout;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__old_value;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__old_value = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__new_value;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__new_value = 0;
    CData/*7:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__strobe;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__mask;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__mask = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__Vfuncout;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__strobe;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__mask;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__mask = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__Vfuncout;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__old_value;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__old_value = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__new_value;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__new_value = 0;
    CData/*7:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__strobe;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__mask;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__mask = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__Vfuncout;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__strobe;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__mask;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__mask = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__Vfuncout;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__old_value;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__old_value = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__new_value;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__new_value = 0;
    CData/*7:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__strobe;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__mask;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__mask = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__Vfuncout;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__strobe;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__mask;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__mask = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__Vfuncout;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__strobe;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__mask;
    __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__mask = 0;
    IData/*19:0*/ __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q = 0;
    CData/*0:0*/ __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q = 0;
    QData/*47:0*/ __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q = 0;
    CData/*0:0*/ __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q = 0;
    CData/*1:0*/ __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q = 0;
    IData/*31:0*/ __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q = 0;
    CData/*0:0*/ __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q = 0;
    // Body
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q;
    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q 
        = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q;
    if (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__sync_reset_n) {
        if ((1U & ((~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_enable)) 
                   | (0U == vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_timeout_cycles)))) {
            __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q = 0U;
            __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q = 0U;
        } else if (((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_kick) 
                    | (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_progress))) {
            __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q = 0U;
            __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q)))) {
            if ((vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q 
                 >= (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__wdt_timeout_cycles 
                     - (IData)(1U)))) {
                __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q 
                    = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q;
                __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q = 1U;
            } else {
                __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q 
                    = ((IData)(1U) + vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q);
            }
        }
    } else {
        __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q = 0U;
        __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q = 0U;
    }
    if (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__sync_reset_n) {
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__single_step_pulse = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__interface_error_clear = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__lsc_wdt_kick = 0U;
        if (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q) {
            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q = 0U;
        }
        if (((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_valid) 
             & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_ready))) {
            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q = 1U;
            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_data_q 
                = ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write)
                    ? 0ULL : vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_read_data);
            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q 
                = ((0U == (7U & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))
                    ? 0U : 2U);
            if (((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_write) 
                 & (0U == (7U & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                              >> 0xfU)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                  >> 0xeU)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                      >> 0xdU)))) {
                            if ((1U & (~ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                          >> 0xcU)))) {
                                if ((1U & (~ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                              >> 0xbU)))) {
                                    if ((1U & (~ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                  >> 0xaU)))) {
                                        if ((0x200U 
                                             & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                     >> 8U)))) {
                                                if (
                                                    (0x80U 
                                                     & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                    if (
                                                        (0x40U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 5U)))) {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                         >> 3U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ 
                                                                            ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                             >> 2U)))) {
                                                                        if (
                                                                            (1U 
                                                                             & (~ 
                                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                                >> 1U)))) {
                                                                            if (
                                                                                (1U 
                                                                                & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                                if (
                                                                                (0U 
                                                                                != 
                                                                                (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                                >> 8U))) {
                                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                                } else {
                                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__module_clk_enable_q 
                                                                                = 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata));
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                         >> 2U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ 
                                                                            ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                             >> 1U)))) {
                                                                        if (
                                                                            (1U 
                                                                             & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                            if (
                                                                                (0U 
                                                                                != (IData)(
                                                                                (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                                >> 0x20U)))) {
                                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                            } else {
                                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__wdt_timeout_cycles_q 
                                                                                = (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata);
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (~ 
                                                                           ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                            >> 2U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                         >> 1U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                        if (
                                                                            (0U 
                                                                             != 
                                                                             (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                              >> 2U))) {
                                                                            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                        } else {
                                                                            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__wdt_enable_q 
                                                                                = 
                                                                                (1U 
                                                                                & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata));
                                                                            if (
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                                >> 1U)))) {
                                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__lsc_wdt_kick = 1U;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                        >> 8U)))) {
                                            if ((0x80U 
                                                 & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                if (
                                                    (0x40U 
                                                     & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                    if (
                                                        (0x20U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                        if (
                                                            (0x10U 
                                                             & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 3U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                         >> 2U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ 
                                                                            ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                             >> 1U)))) {
                                                                        if (
                                                                            (1U 
                                                                             & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                            if (
                                                                                (0U 
                                                                                != 
                                                                                (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                                >> 1U))) {
                                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                            } else {
                                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__l1_host_access_enable_q 
                                                                                = 
                                                                                (1U 
                                                                                & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata));
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        } else if (
                                                                   (8U 
                                                                    & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 2U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                         >> 1U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    }
                                                                }
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (~ 
                                                                       ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                        >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        (1U 
                                                                         & ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata) 
                                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb)))) {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_lock_q = 1U;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (0x10U 
                                                                & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 2U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                         >> 1U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                        if (
                                                                            ((IData)(
                                                                                (0ULL 
                                                                                != 
                                                                                (0xfffffffffff00007ULL 
                                                                                & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata))) 
                                                                             | ((0xfffffU 
                                                                                & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata)) 
                                                                                < vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_base_q))) {
                                                                            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                        } else {
                                                                            __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q 
                                                                                = 
                                                                                (0xfffffU 
                                                                                & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata));
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (~ 
                                                                       ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                        >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        ((IData)(
                                                                                (0ULL 
                                                                                != 
                                                                                (0xfffffffffff00007ULL 
                                                                                & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata))) 
                                                                         | ((0xfffffU 
                                                                             & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata)) 
                                                                            > vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q))) {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    } else {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_base_q 
                                                                            = 
                                                                            (0xfffffU 
                                                                             & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata));
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        (1U 
                                                                         & ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata) 
                                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb)))) {
                                                                        __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q = 0U;
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__interface_error_clear = 1U;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                    >> 2U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 1U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (0x20U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        (0U 
                                                                         != 
                                                                         (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                          >> 3U))) {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    } else {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_mask_q 
                                                                            = 
                                                                            (7U 
                                                                             & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata));
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                    >> 2U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 1U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q 
                                                                    = 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q) 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata) 
                                                                         & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb)))))));
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (0x10U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                             >> 3U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        (0U 
                                                                         != (IData)(
                                                                                (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                                >> 0x20U)))) {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    } else {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__tbu_stream_id_q 
                                                                            = 
                                                                            (0xffffU 
                                                                             & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata));
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__tbu_substream_id_q 
                                                                            = 
                                                                            (0xffffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                                >> 0x10U)));
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (8U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                             >> 2U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 1U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                if (
                                                                    ((IData)(
                                                                             (0ULL 
                                                                              != 
                                                                              (0xffff000000000007ULL 
                                                                               & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata))) 
                                                                     | ((0xffffffffffffULL 
                                                                         & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata) 
                                                                        < vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_base_q))) {
                                                                    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                } else {
                                                                    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q 
                                                                        = 
                                                                        (0xffffffffffffULL 
                                                                         & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata);
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                >> 2U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                            if (
                                                                ((IData)(
                                                                         (0ULL 
                                                                          != 
                                                                          (0xffff000000000007ULL 
                                                                           & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata))) 
                                                                 | ((0xffffffffffffULL 
                                                                     & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata) 
                                                                    > vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q))) {
                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                            } else {
                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_base_q 
                                                                    = 
                                                                    (0xffffffffffffULL 
                                                                     & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata);
                                                            }
                                                        }
                                                    }
                                                }
                                            } else if (
                                                       (0x40U 
                                                        & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                if (
                                                    (0x20U 
                                                     & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 2U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                         >> 1U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                        if ((IData)(
                                                                                (0ULL 
                                                                                != 
                                                                                (0xffff000000000007ULL 
                                                                                & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata)))) {
                                                                            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                        } else {
                                                                            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__kv_base_q 
                                                                                = 
                                                                                (0xffffffffffffULL 
                                                                                & ([&]() {
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__strobe 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__new_value 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__old_value 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__kv_base_q;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__strobe 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__strobe;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__mask = 0ULL;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__mask 
                                                                                = 
                                                                                ((0xffffffffffff0000ULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__mask) 
                                                                                | (IData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__strobe) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__strobe)))))))));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__mask 
                                                                                = 
                                                                                ((0xffffffff0000ffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__strobe) 
                                                                                >> 3U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__strobe) 
                                                                                >> 2U)))))))) 
                                                                                << 0x10U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__mask 
                                                                                = 
                                                                                ((0xffff0000ffffffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__strobe) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__strobe) 
                                                                                >> 4U)))))))) 
                                                                                << 0x20U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__mask 
                                                                                = 
                                                                                ((0xffffffffffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__strobe) 
                                                                                >> 7U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__strobe) 
                                                                                >> 6U)))))))) 
                                                                                << 0x30U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__Vfuncout 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__mask;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__mask 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__8__Vfuncout;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__Vfuncout 
                                                                                = 
                                                                                ((__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__old_value 
                                                                                & (~ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__mask)) 
                                                                                | (__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__new_value 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__mask));
                                                                                }(), __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__7__Vfuncout));
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (~ 
                                                                       ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                        >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                    if ((IData)(
                                                                                (0ULL 
                                                                                != 
                                                                                (0xffff000000000007ULL 
                                                                                & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata)))) {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    } else {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__output_base_q 
                                                                            = 
                                                                            (0xffffffffffffULL 
                                                                             & ([&]() {
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__strobe 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__new_value 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__old_value 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__output_base_q;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__strobe 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__strobe;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__mask = 0ULL;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__mask 
                                                                                = 
                                                                                ((0xffffffffffff0000ULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__mask) 
                                                                                | (IData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__strobe) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__strobe)))))))));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__mask 
                                                                                = 
                                                                                ((0xffffffff0000ffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__strobe) 
                                                                                >> 3U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__strobe) 
                                                                                >> 2U)))))))) 
                                                                                << 0x10U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__mask 
                                                                                = 
                                                                                ((0xffff0000ffffffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__strobe) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__strobe) 
                                                                                >> 4U)))))))) 
                                                                                << 0x20U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__mask 
                                                                                = 
                                                                                ((0xffffffffffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__strobe) 
                                                                                >> 7U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__strobe) 
                                                                                >> 6U)))))))) 
                                                                                << 0x30U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__Vfuncout 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__mask;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__mask 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__10__Vfuncout;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__Vfuncout 
                                                                                = 
                                                                                ((__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__old_value 
                                                                                & (~ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__mask)) 
                                                                                | (__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__new_value 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__mask));
                                                                                }(), __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__9__Vfuncout));
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                    if ((IData)(
                                                                                (0ULL 
                                                                                != 
                                                                                (0xffff000000000007ULL 
                                                                                & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata)))) {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    } else {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__work_base_q 
                                                                            = 
                                                                            (0xffffffffffffULL 
                                                                             & ([&]() {
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__strobe 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__new_value 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__old_value 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__work_base_q;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__strobe 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__strobe;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__mask = 0ULL;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__mask 
                                                                                = 
                                                                                ((0xffffffffffff0000ULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__mask) 
                                                                                | (IData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__strobe) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__strobe)))))))));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__mask 
                                                                                = 
                                                                                ((0xffffffff0000ffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__strobe) 
                                                                                >> 3U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__strobe) 
                                                                                >> 2U)))))))) 
                                                                                << 0x10U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__mask 
                                                                                = 
                                                                                ((0xffff0000ffffffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__strobe) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__strobe) 
                                                                                >> 4U)))))))) 
                                                                                << 0x20U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__mask 
                                                                                = 
                                                                                ((0xffffffffffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__strobe) 
                                                                                >> 7U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__strobe) 
                                                                                >> 6U)))))))) 
                                                                                << 0x30U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__Vfuncout 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__mask;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__mask 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__12__Vfuncout;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__Vfuncout 
                                                                                = 
                                                                                ((__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__old_value 
                                                                                & (~ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__mask)) 
                                                                                | (__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__new_value 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__mask));
                                                                                }(), __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__11__Vfuncout));
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                    >> 2U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 1U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                if ((IData)(
                                                                            (0ULL 
                                                                             != 
                                                                             (0xffff000000000007ULL 
                                                                              & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata)))) {
                                                                    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                } else {
                                                                    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__weight_base_q 
                                                                        = 
                                                                        (0xffffffffffffULL 
                                                                         & ([&]() {
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__strobe 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__new_value 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__old_value 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__weight_base_q;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__strobe 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__strobe;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__mask = 0ULL;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__mask 
                                                                                = 
                                                                                ((0xffffffffffff0000ULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__mask) 
                                                                                | (IData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__strobe) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__strobe)))))))));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__mask 
                                                                                = 
                                                                                ((0xffffffff0000ffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__strobe) 
                                                                                >> 3U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__strobe) 
                                                                                >> 2U)))))))) 
                                                                                << 0x10U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__mask 
                                                                                = 
                                                                                ((0xffff0000ffffffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__strobe) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__strobe) 
                                                                                >> 4U)))))))) 
                                                                                << 0x20U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__mask 
                                                                                = 
                                                                                ((0xffffffffffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__strobe) 
                                                                                >> 7U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__strobe) 
                                                                                >> 6U)))))))) 
                                                                                << 0x30U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__Vfuncout 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__mask;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__mask 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__14__Vfuncout;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__Vfuncout 
                                                                                = 
                                                                                ((__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__old_value 
                                                                                & (~ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__mask)) 
                                                                                | (__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__new_value 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__mask));
                                                                            }(), __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__13__Vfuncout));
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (0x10U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                    if ((IData)(
                                                                                (0ULL 
                                                                                != 
                                                                                (0xffff000000000007ULL 
                                                                                & vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata)))) {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    } else {
                                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__input_base_q 
                                                                            = 
                                                                            (0xffffffffffffULL 
                                                                             & ([&]() {
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__strobe 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__new_value 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__old_value 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__input_base_q;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__strobe 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__strobe;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__mask = 0ULL;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__mask 
                                                                                = 
                                                                                ((0xffffffffffff0000ULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__mask) 
                                                                                | (IData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__strobe) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__strobe)))))))));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__mask 
                                                                                = 
                                                                                ((0xffffffff0000ffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__strobe) 
                                                                                >> 3U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__strobe) 
                                                                                >> 2U)))))))) 
                                                                                << 0x10U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__mask 
                                                                                = 
                                                                                ((0xffff0000ffffffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__strobe) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__strobe) 
                                                                                >> 4U)))))))) 
                                                                                << 0x20U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__mask 
                                                                                = 
                                                                                ((0xffffffffffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__strobe) 
                                                                                >> 7U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__strobe) 
                                                                                >> 6U)))))))) 
                                                                                << 0x30U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__Vfuncout 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__mask;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__mask 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__16__Vfuncout;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__Vfuncout 
                                                                                = 
                                                                                ((__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__old_value 
                                                                                & (~ __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__mask)) 
                                                                                | (__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__new_value 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__mask));
                                                                                }(), __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__merge_write__15__Vfuncout));
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (8U 
                                                            & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                             >> 2U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 1U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                >> 2U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                            if (
                                                                (1U 
                                                                 & ((0U 
                                                                     != 
                                                                     (0xfffffffffffffff0ULL 
                                                                      & (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                         & ([&]() {
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__strobe 
                                                                                = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wstrb;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__mask = 0ULL;
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__mask 
                                                                                = 
                                                                                ((0xffffffffffff0000ULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__mask) 
                                                                                | (IData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__strobe) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__strobe)))))))));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__mask 
                                                                                = 
                                                                                ((0xffffffff0000ffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__strobe) 
                                                                                >> 3U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__strobe) 
                                                                                >> 2U)))))))) 
                                                                                << 0x10U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__mask 
                                                                                = 
                                                                                ((0xffff0000ffffffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__strobe) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__strobe) 
                                                                                >> 4U)))))))) 
                                                                                << 0x20U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__mask 
                                                                                = 
                                                                                ((0xffffffffffffULL 
                                                                                & __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__strobe) 
                                                                                >> 7U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__strobe) 
                                                                                >> 6U)))))))) 
                                                                                << 0x30U));
                                                                                __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__Vfuncout 
                                                                                = __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__mask;
                                                                                }(), __Vfunc_tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__write_mask__17__Vfuncout)))) 
                                                                    | ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata) 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                                >> 1U)))))) {
                                                                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                            } else {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                                >> 2U)))) {
                                                                    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q = 1U;
                                                                }
                                                                if (
                                                                    ((IData)(
                                                                             (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                              >> 3U)) 
                                                                     & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__stop_q))) {
                                                                    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__single_step_pulse = 1U;
                                                                }
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata))) {
                                                                    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__start_q = 1U;
                                                                    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__stop_q = 0U;
                                                                }
                                                                if (
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_wdata 
                                                                                >> 1U)))) {
                                                                    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__start_q = 0U;
                                                                    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__stop_q = 1U;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else if (
                                                       (0x20U 
                                                        & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                             >> 3U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                                    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                                >> 2U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                        }
                                                    }
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                            >> 2U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr) 
                                                         >> 1U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_addr)))) {
                                                        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_terminal_valid) {
            if ((0U != (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_status))) {
                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q 
                    = (((9U == (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_status)) 
                        | (0xcU == (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_status)))
                        ? (2U | (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q))
                        : (4U | (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q)));
            }
            if (((0U != (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_status)) 
                 & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q)))) {
                __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q = 1U;
                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_command_id_q 
                    = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_command_id;
                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_engine_q 
                    = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_engine;
                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_opcode_q 
                    = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_opcode;
                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_status_q 
                    = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_status;
                vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_addr_q 
                    = vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__task_fault_addr;
            }
        }
        if ((2U & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q))) {
                if ((1U & ((~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__soft_reset_req)) 
                           & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q))))) {
                    __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q = 0U;
                }
            } else if (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_done) {
                __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q = 0U;
                __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q))) {
            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse = 1U;
            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_reason_q 
                = (2U | (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_reason_q));
            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_lock_q = 0U;
            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__l1_host_access_enable_q = 0U;
            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q = 0U;
            __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q = 2U;
        } else if (vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_requested) {
            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__start_q = 0U;
            vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__stop_q = 1U;
            __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q = 1U;
        }
    } else {
        __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q = 0U;
        __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_data_q = 0ULL;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_status_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__start_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__stop_q = 1U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_status_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__irq_mask_q = 7U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_command_id_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_engine_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_opcode_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_status_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_addr_q = 0ULL;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_reason_q = 1U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__input_base_q = 0ULL;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__weight_base_q = 0ULL;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__work_base_q = 0ULL;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__output_base_q = 0ULL;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__kv_base_q = 0ULL;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_base_q = 0ULL;
        __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q = 0xfffffffffff8ULL;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__tbu_stream_id_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__tbu_substream_id_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_base_q = 0U;
        __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_lock_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__l1_host_access_enable_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__module_clk_enable_q = 0xffU;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__wdt_enable_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__wdt_timeout_cycles_q = 0U;
        __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__single_step_pulse = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__internal_soft_reset_pulse = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__interface_error_clear = 0U;
        vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__lsc_wdt_kick = 0U;
    }
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q 
        = __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__counter_q;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q 
        = __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_wdt__DOT__timeout_q;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q 
        = __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q 
        = __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__param_l1_limit_q;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q 
        = __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__fault_valid_q;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q 
        = __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__m_axi_addr_limit_q;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q 
        = __Vdly__tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_state_q;
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reg_req_ready 
        = (1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__rsp_valid_q)));
}

VL_INLINE_OPT void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__3(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__3\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_gate_enable_q 
        = ((1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reset_n))) 
           || (1U & ((~ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_reset_sync_q) 
                         >> 1U)) | (0U != (0x7fU & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__module_clk_active))))));
}

VL_INLINE_OPT void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__4(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__4\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_gate_enable_q 
        = ((1U & (~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__reset_n))) 
           || (1U & ((~ ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_reset_sync_q) 
                         >> 1U)) | ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__module_clk_active) 
                                    >> 7U))));
}

VL_INLINE_OPT void Vtb_lsc_crg_wdt_smoke___024root___nba_comb__TOP__0(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___nba_comb__TOP__0\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__reset_requested 
        = ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__soft_reset_req) 
           | (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_lsc__DOT__csr_soft_reset_req_q));
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
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__module_clk_active 
        = (0xffU & ((~ (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__module_idle)) 
                    | (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__module_clk_en)));
}

VL_INLINE_OPT void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__5(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__5\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_reset_sync_q 
        = vlSelfRef.__Vdly__tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_reset_sync_q;
}

VL_INLINE_OPT void Vtb_lsc_crg_wdt_smoke___024root___nba_comb__TOP__1(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___nba_comb__TOP__1\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__core_clk_gated 
        = ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__clk) 
           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__core_gate_enable_q));
}

VL_INLINE_OPT void Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__6(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___nba_sequent__TOP__6\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_reset_sync_q 
        = vlSelfRef.__Vdly__tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_reset_sync_q;
}

VL_INLINE_OPT void Vtb_lsc_crg_wdt_smoke___024root___nba_comb__TOP__2(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___nba_comb__TOP__2\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__noc_clk_gated 
        = ((IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__noc_clk) 
           & (IData)(vlSelfRef.tb_lsc_crg_wdt_smoke__DOT__u_crg__DOT__noc_gate_enable_q));
}

void Vtb_lsc_crg_wdt_smoke___024root___timing_resume(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___timing_resume\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hf0804800__0.resume(
                                                   "@(posedge tb_lsc_crg_wdt_smoke.clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hf08046bd__0.resume(
                                                   "@(negedge tb_lsc_crg_wdt_smoke.clk)");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h77370d68__0.resume(
                                                   "@( tb_lsc_crg_wdt_smoke.u_lsc.rsp_valid_q)");
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h4baaed7e__0.resume(
                                                   "@( tb_lsc_crg_wdt_smoke.internal_soft_reset_pulse)");
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h701bf8e5__0.resume(
                                                   "@( (2'h3 == tb_lsc_crg_wdt_smoke.u_lsc.reset_state_q))");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_lsc_crg_wdt_smoke___024root___timing_commit(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___timing_commit\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hf0804800__0.commit(
                                                   "@(posedge tb_lsc_crg_wdt_smoke.clk)");
    }
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hf08046bd__0.commit(
                                                   "@(negedge tb_lsc_crg_wdt_smoke.clk)");
    }
    if ((! (0x40ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h77370d68__0.commit(
                                                   "@( tb_lsc_crg_wdt_smoke.u_lsc.rsp_valid_q)");
    }
    if ((! (0x80ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h4baaed7e__0.commit(
                                                   "@( tb_lsc_crg_wdt_smoke.internal_soft_reset_pulse)");
    }
    if ((! (0x100ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h701bf8e5__0.commit(
                                                   "@( (2'h3 == tb_lsc_crg_wdt_smoke.u_lsc.reset_state_q))");
    }
}

void Vtb_lsc_crg_wdt_smoke___024root___eval_triggers__act(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);

bool Vtb_lsc_crg_wdt_smoke___024root___eval_phase__act(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_phase__act\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<9> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_lsc_crg_wdt_smoke___024root___eval_triggers__act(vlSelf);
    Vtb_lsc_crg_wdt_smoke___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_lsc_crg_wdt_smoke___024root___timing_resume(vlSelf);
        Vtb_lsc_crg_wdt_smoke___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_lsc_crg_wdt_smoke___024root___eval_phase__nba(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_phase__nba\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_lsc_crg_wdt_smoke___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__nba(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__act(Vtb_lsc_crg_wdt_smoke___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_lsc_crg_wdt_smoke___024root___eval(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("control/tb_lsc_crg_wdt_smoke.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_lsc_crg_wdt_smoke___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("control/tb_lsc_crg_wdt_smoke.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_lsc_crg_wdt_smoke___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_lsc_crg_wdt_smoke___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_lsc_crg_wdt_smoke___024root___eval_debug_assertions(Vtb_lsc_crg_wdt_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_lsc_crg_wdt_smoke___024root___eval_debug_assertions\n"); );
    Vtb_lsc_crg_wdt_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
