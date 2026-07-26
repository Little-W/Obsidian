// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core___024root.h"

VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__6(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___stl_sequent__TOP__6\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_squared;
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_squared = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__unnamedblk1__DOT__slot;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__unnamedblk1__DOT__slot = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__unnamedblk1__DOT__slot;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__unnamedblk1__DOT__slot = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2425__lhs;
    __Vfunc_fp32_mul__2425__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2425__rhs;
    __Vfunc_fp32_mul__2425__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2425__normalize_count;
    __Vfunc_fp32_mul__2425__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2426__unused_sign;
    __Vfunc_fp32_is_nan__2426__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2427__unused_sign;
    __Vfunc_fp32_is_nan__2427__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2428__unused_sign;
    __Vfunc_fp32_is_inf__2428__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2429__unused_sign;
    __Vfunc_fp32_is_zero__2429__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2430__unused_sign;
    __Vfunc_fp32_is_inf__2430__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2431__unused_sign;
    __Vfunc_fp32_is_zero__2431__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2432__unused_sign;
    __Vfunc_fp32_is_inf__2432__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2433__unused_sign;
    __Vfunc_fp32_is_inf__2433__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2434__unused_sign;
    __Vfunc_fp32_is_zero__2434__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2435__unused_sign;
    __Vfunc_fp32_is_zero__2435__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__2436__Vfuncout;
    __Vfunc_fp32_sub__2436__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__2436__lhs;
    __Vfunc_fp32_sub__2436__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__2436__rhs;
    __Vfunc_fp32_sub__2436__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2437__lhs;
    __Vfunc_fp32_add__2437__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2437__rhs;
    __Vfunc_fp32_add__2437__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2437__normalize_count;
    __Vfunc_fp32_add__2437__normalize_count = 0;
    IData/*31:0*/ __Vfunc_fp32_neg__2438__Vfuncout;
    __Vfunc_fp32_neg__2438__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_neg__2438__value;
    __Vfunc_fp32_neg__2438__value = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2439__unused_sign;
    __Vfunc_fp32_is_nan__2439__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2440__unused_sign;
    __Vfunc_fp32_is_nan__2440__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2441__unused_sign;
    __Vfunc_fp32_is_inf__2441__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2442__unused_sign;
    __Vfunc_fp32_is_inf__2442__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2443__unused_sign;
    __Vfunc_fp32_is_inf__2443__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2444__unused_sign;
    __Vfunc_fp32_is_inf__2444__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2445__unused_sign;
    __Vfunc_fp32_is_inf__2445__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2446__unused_sign;
    __Vfunc_fp32_is_zero__2446__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2447__unused_sign;
    __Vfunc_fp32_is_zero__2447__unused_sign = 0;
    VlWide<4>/*127:0*/ __Vtemp_4;
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_square 
        = vlSelfRef.__Vfunc_fp32_div__2414__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_commit_w 
        = ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i) 
              & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_complete_error_w)) 
                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_last_expected_w)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready = 0U;
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h08238727__0 = 1U;
        if ((5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready 
                = (((~ ((IData)(1U) << (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))) 
                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready)) 
                   | (0x3fU & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT____Vlvbound_h08238727__0) 
                               << (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))));
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_ready 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__busy_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_dma_w) 
              & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT____VdfgRegularize_hd916d9cf_0_1)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__mem_request_handshake 
        = ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q)) 
           & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__busy_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_dma_w)) 
                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT____VdfgRegularize_hd916d9cf_0_1))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_read_data 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_space)
            ? 0ULL : ((0x8000U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                       ? 0ULL : ((0x4000U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                  ? 0ULL : ((0x2000U 
                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                             ? 0ULL
                                             : ((0x1000U 
                                                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                 ? 0ULL
                                                 : 
                                                ((0x800U 
                                                  & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                  ? 0ULL
                                                  : 
                                                 ((0x400U 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                   ? 0ULL
                                                   : 
                                                  ((0x200U 
                                                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                    ? 
                                                   ((0x100U 
                                                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                     ? 0ULL
                                                     : 
                                                    ((0x80U 
                                                      & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                      ? 
                                                     ((0x40U 
                                                       & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                       ? 
                                                      ((0x20U 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                        ? 0ULL
                                                        : 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__module_clk_enable_q))))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__wdt_timeout_cycles_q)))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__wdt_enable_q))))))))
                                                       : 0ULL)
                                                      : 0ULL))
                                                    : 
                                                   ((0x100U 
                                                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                     ? 0ULL
                                                     : 
                                                    ((0x80U 
                                                      & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                      ? 
                                                     ((0x40U 
                                                       & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                       ? 
                                                      ((0x20U 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                        ? 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__l1_host_access_enable_q))))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_reason_q)))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_lock_q)))))))
                                                        : 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_limit_q)))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_base_q))))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q)
                                                              ? (QData)((IData)(
                                                                                (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_opcode_q) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_engine_q) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_status_q)))))
                                                              : 0ULL)))))))
                                                       : 
                                                      ((0x20U 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                        ? 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q)
                                                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_addr_q
                                                              : 0ULL))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q)
                                                              ? (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_command_id_q))
                                                              : 0ULL)))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_mask_q)))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q)))))))
                                                        : 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(
                                                                               (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__tbu_substream_id_q) 
                                                                                << 0x10U) 
                                                                                | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__tbu_stream_id_q))))))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_limit_q)))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_base_q)))))))
                                                      : 
                                                     ((0x40U 
                                                       & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                       ? 
                                                      ((0x20U 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                        ? 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__kv_base_q)))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__output_base_q))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__work_base_q)))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__weight_base_q)))))
                                                        : 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__input_base_q)))
                                                          : 0ULL)
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(
                                                                               ((((0U 
                                                                                != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)) 
                                                                                << 5U) 
                                                                                | ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle) 
                                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q)) 
                                                                                << 4U) 
                                                                                | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q) 
                                                                                << 3U))) 
                                                                                | (((IData)(vlSelfRef.tb_npu_single_core__DOT__accept_new_cmd_o) 
                                                                                << 2U) 
                                                                                | ((2U 
                                                                                & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)))))))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : (QData)((IData)(
                                                                               (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__start_q))))))))))
                                                       : 
                                                      ((0x20U 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                        ? 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 0x1000003fff04ULL))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 0x3ff08ULL)))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 0x7081008ULL)))))
                                                        : 
                                                       ((0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                         ? 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 0x21000100000ULL)))
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 0x8283040ULL))))
                                                         : 
                                                        ((8U 
                                                          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                          ? 0ULL
                                                          : 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                           ? 0ULL
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                            ? 0ULL
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))
                                                             ? 0ULL
                                                             : 0x100010001ULL)))))))))))))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_wstrb = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_wstrb 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT____VdfgExtracted_h20747776__0;
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[3U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[2U]))) 
           + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_offset);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[9U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[8U]))) 
           + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_offset);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____VdfgExtracted_hf6182e41__0 
        = ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
            >> 0x1fU) & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_engine)));
    __Vfunc_fp32_mul__2425__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean;
    __Vfunc_fp32_mul__2425__lhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_mul__2425__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13706289441196013065ull);
    vlSelf->__Vfunc_fp32_mul__2425__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16181479144531634524ull);
    vlSelf->__Vfunc_fp32_mul__2425__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5923235082932919960ull);
    vlSelf->__Vfunc_fp32_mul__2425__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 1243125166700601081ull);
    vlSelf->__Vfunc_fp32_mul__2425__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 8380245393415625386ull);
    vlSelf->__Vfunc_fp32_mul__2425__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13355607362820050559ull);
    vlSelf->__Vfunc_fp32_mul__2425__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13748853482830093108ull);
    vlSelf->__Vfunc_fp32_mul__2425__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 5272402888217514778ull);
    vlSelf->__Vfunc_fp32_mul__2425__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11068574965977406646ull);
    vlSelf->__Vfunc_fp32_mul__2425__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7104586774730884109ull);
    vlSelf->__Vfunc_fp32_mul__2425__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18014721168583176642ull);
    vlSelf->__Vfunc_fp32_mul__2425__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8493055548631120530ull);
    vlSelf->__Vfunc_fp32_mul__2425__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5042039411659964677ull);
    __Vfunc_fp32_mul__2425__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2426__bits 
                                = __Vfunc_fp32_mul__2425__lhs;
                            __Vfunc_fp32_is_nan__2426__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2426__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2426__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2426__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2426__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2426__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2426__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2427__bits 
                                = __Vfunc_fp32_mul__2425__rhs;
                            __Vfunc_fp32_is_nan__2427__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2427__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2427__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2427__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2427__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2427__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2427__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2428__bits 
                                    = __Vfunc_fp32_mul__2425__lhs;
                                __Vfunc_fp32_is_inf__2428__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2428__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2428__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2428__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2428__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2428__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2429__bits 
                                    = __Vfunc_fp32_mul__2425__rhs;
                                __Vfunc_fp32_is_zero__2429__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2429__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2429__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2429__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2429__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2429__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2430__bits 
                                    = __Vfunc_fp32_mul__2425__rhs;
                                __Vfunc_fp32_is_inf__2430__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2430__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2430__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2430__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2430__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2430__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2431__bits 
                                    = __Vfunc_fp32_mul__2425__lhs;
                                __Vfunc_fp32_is_zero__2431__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2431__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2431__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2431__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2431__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2431__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout = 0x7fc00000U;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_mul__2425__result_sign 
            = ((__Vfunc_fp32_mul__2425__lhs ^ __Vfunc_fp32_mul__2425__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2432__bits 
                            = __Vfunc_fp32_mul__2425__lhs;
                        __Vfunc_fp32_is_inf__2432__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2432__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2432__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2432__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2432__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2432__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2433__bits 
                            = __Vfunc_fp32_mul__2425__rhs;
                        __Vfunc_fp32_is_inf__2433__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2433__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2433__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2433__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2433__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2433__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2434__bits 
                            = __Vfunc_fp32_mul__2425__lhs;
                        __Vfunc_fp32_is_zero__2434__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2434__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2434__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2434__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2434__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2434__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2435__bits 
                            = __Vfunc_fp32_mul__2425__rhs;
                        __Vfunc_fp32_is_zero__2435__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2435__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2435__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2435__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2435__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2435__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__result_sign) 
                   << 0x1fU);
            goto __Vlabel0;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2425__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2425__lhs);
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2425__lhs));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2425__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2425__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2425__rhs);
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2425__rhs));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2425__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__2425__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__2425__normalize_count = 1U;
        __Vfunc_fp32_mul__2425__normalize_count = 2U;
        __Vfunc_fp32_mul__2425__normalize_count = 3U;
        __Vfunc_fp32_mul__2425__normalize_count = 4U;
        __Vfunc_fp32_mul__2425__normalize_count = 5U;
        __Vfunc_fp32_mul__2425__normalize_count = 6U;
        __Vfunc_fp32_mul__2425__normalize_count = 7U;
        __Vfunc_fp32_mul__2425__normalize_count = 8U;
        __Vfunc_fp32_mul__2425__normalize_count = 9U;
        __Vfunc_fp32_mul__2425__normalize_count = 0xaU;
        __Vfunc_fp32_mul__2425__normalize_count = 0xbU;
        __Vfunc_fp32_mul__2425__normalize_count = 0xcU;
        __Vfunc_fp32_mul__2425__normalize_count = 0xdU;
        __Vfunc_fp32_mul__2425__normalize_count = 0xeU;
        __Vfunc_fp32_mul__2425__normalize_count = 0xfU;
        __Vfunc_fp32_mul__2425__normalize_count = 0x10U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x11U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x12U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x13U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x14U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x15U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x16U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__2425__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__2425__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2425__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__2425__mantissa 
            = (0xffffffU & (IData)((0xffffffffffffULL 
                                    & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__2425__product, vlSelfRef.__Vfunc_fp32_mul__2425__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__2425__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__2425__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__2425__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__2425__product 
               & vlSelfRef.__Vfunc_fp32_mul__2425__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__2425__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__2425__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__2425__rounded = vlSelfRef.__Vfunc_fp32_mul__2425__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__2425__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__2425__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__2425__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__2425__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__2425__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2425__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__2425__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__2425__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__2425__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2425__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__2425__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__result_sign) 
                   << 0x1fU);
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__2425__mantissa)));
        __Vlabel0: ;
    }
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_squared 
        = vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_handshake 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found) 
           & ((5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)) 
              & (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
                  >> (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)) 
                 & ((5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)) 
                    & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready) 
                       >> (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_end_addr 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr 
           + VL_EXTEND_QI(64,3, ([&]() {
                    vlSelfRef.__Vfunc_dtype_storage_bytes__2134__dtype 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_src_dtype;
                    {
                        if ((0U == (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__2134__dtype))) {
                            vlSelfRef.__Vfunc_dtype_storage_bytes__2134__Vfuncout = 1U;
                            goto __Vlabel1;
                        }
                        vlSelfRef.__Vfunc_dtype_bytes__2135__dtype 
                            = vlSelfRef.__Vfunc_dtype_storage_bytes__2134__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__2135__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2135__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2135__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2135__dtype))
                                                  ? 2U
                                                  : 0U)));
                        vlSelfRef.__Vfunc_dtype_storage_bytes__2134__Vfuncout 
                            = vlSelfRef.__Vfunc_dtype_bytes__2135__Vfuncout;
                        __Vlabel1: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__2134__Vfuncout))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_addr = 0ULL;
    if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_addr 
                = (0xfffffffffff8ULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr);
        }
    }
    if ((6U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_addr 
                = (0xfffffffffff8ULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr);
        }
    }
    if ((8U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_addr 
                = (0xfffffffffff8ULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr);
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_end_addr 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr 
           + VL_EXTEND_QI(64,3, ([&]() {
                    vlSelfRef.__Vfunc_dtype_storage_bytes__2136__dtype 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype;
                    {
                        if ((0U == (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__2136__dtype))) {
                            vlSelfRef.__Vfunc_dtype_storage_bytes__2136__Vfuncout = 1U;
                            goto __Vlabel2;
                        }
                        vlSelfRef.__Vfunc_dtype_bytes__2137__dtype 
                            = vlSelfRef.__Vfunc_dtype_storage_bytes__2136__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__2137__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2137__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2137__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2137__dtype))
                                                  ? 2U
                                                  : 0U)));
                        vlSelfRef.__Vfunc_dtype_storage_bytes__2136__Vfuncout 
                            = vlSelfRef.__Vfunc_dtype_bytes__2137__Vfuncout;
                        __Vlabel2: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__2136__Vfuncout))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_wstrb = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_addr = 0U;
    if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr 
                                        >> 3U)) << 3U));
        }
    }
    if ((6U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr 
                                        >> 3U)) << 3U));
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_wstrb = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_wdata = 0ULL;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_wdata = 0ULL;
    if ((8U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.__Vfunc_store_element_strb__2141__dtype 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_strb__2141__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_strb__2141__result = 0U;
            vlSelfRef.__Vfunc_store_element_strb__2141__result 
                = ((2U & (IData)(vlSelfRef.__Vfunc_store_element_strb__2141__dtype))
                    ? (0xffU & ((1U & (IData)(vlSelfRef.__Vfunc_store_element_strb__2141__dtype))
                                 ? ((IData)(3U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__2141__byte_lane))
                                 : ((IData)(0xfU) << (IData)(vlSelfRef.__Vfunc_store_element_strb__2141__byte_lane))))
                    : ((IData)(vlSelfRef.__Vfunc_store_element_strb__2141__result) 
                       | (0xffU & ((IData)(1U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__2141__byte_lane)))));
            vlSelfRef.__Vfunc_store_element_strb__2141__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_strb__2141__result;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_wstrb 
                = vlSelfRef.__Vfunc_store_element_strb__2141__Vfuncout;
            vlSelfRef.__Vfunc_store_element_data__2140__dtype 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_data__2140__high_nibble 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_high_nibble;
            vlSelfRef.__Vfunc_store_element_data__2140__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_data__2140__value 
                = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__result_q);
            vlSelfRef.__Vfunc_store_element_data__2140__old_beat 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rmw_beat_q;
            vlSelf->__Vfunc_store_element_data__2140__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8648678862284573608ull);
            vlSelfRef.__Vfunc_store_element_data__2140__result 
                = vlSelfRef.__Vfunc_store_element_data__2140__old_beat;
            if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__2140__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__2140__result 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2140__dtype))
                        ? (((~ (0xffffULL << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__2140__result) 
                           | ((QData)((IData)((0xffffU 
                                               & vlSelfRef.__Vfunc_store_element_data__2140__value))) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U))))
                        : (((~ (0xffffffffULL << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__2140__result) 
                           | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2140__value)) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U)))));
            } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2140__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__2140__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__2140__result) 
                       | ((QData)((IData)((0xffU & vlSelfRef.__Vfunc_store_element_data__2140__value))) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U))));
            } else {
                vlSelfRef.__Vfunc_store_element_data__2140__byte_value 
                    = (0xffU & (IData)((vlSelfRef.__Vfunc_store_element_data__2140__old_beat 
                                        >> (0x3fU & 
                                            VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U)))));
                vlSelfRef.__Vfunc_store_element_data__2140__byte_value 
                    = ((IData)(vlSelfRef.__Vfunc_store_element_data__2140__high_nibble)
                        ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_value)) 
                           | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__2140__value 
                                       << 4U))) : (
                                                   (0xf0U 
                                                    & (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_value)) 
                                                   | (0xfU 
                                                      & vlSelfRef.__Vfunc_store_element_data__2140__value)));
                vlSelfRef.__Vfunc_store_element_data__2140__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__2140__result) 
                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_value)) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U))));
            }
            vlSelfRef.__Vfunc_store_element_data__2140__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_data__2140__result;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_wdata 
                = vlSelfRef.__Vfunc_store_element_data__2140__Vfuncout;
        }
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr 
                                        >> 3U)) << 3U));
            vlSelfRef.__Vfunc_store_element_strb__2139__dtype 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_strb__2139__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_strb__2139__result = 0U;
            vlSelfRef.__Vfunc_store_element_strb__2139__result 
                = ((2U & (IData)(vlSelfRef.__Vfunc_store_element_strb__2139__dtype))
                    ? (0xffU & ((1U & (IData)(vlSelfRef.__Vfunc_store_element_strb__2139__dtype))
                                 ? ((IData)(3U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__2139__byte_lane))
                                 : ((IData)(0xfU) << (IData)(vlSelfRef.__Vfunc_store_element_strb__2139__byte_lane))))
                    : ((IData)(vlSelfRef.__Vfunc_store_element_strb__2139__result) 
                       | (0xffU & ((IData)(1U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__2139__byte_lane)))));
            vlSelfRef.__Vfunc_store_element_strb__2139__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_strb__2139__result;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_wstrb 
                = vlSelfRef.__Vfunc_store_element_strb__2139__Vfuncout;
            vlSelfRef.__Vfunc_store_element_data__2138__dtype 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_data__2138__high_nibble 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_high_nibble;
            vlSelfRef.__Vfunc_store_element_data__2138__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_data__2138__value 
                = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__result_q);
            vlSelfRef.__Vfunc_store_element_data__2138__old_beat 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rmw_beat_q;
            vlSelf->__Vfunc_store_element_data__2138__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11181074453923148189ull);
            vlSelfRef.__Vfunc_store_element_data__2138__result 
                = vlSelfRef.__Vfunc_store_element_data__2138__old_beat;
            if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__2138__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__2138__result 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2138__dtype))
                        ? (((~ (0xffffULL << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__2138__result) 
                           | ((QData)((IData)((0xffffU 
                                               & vlSelfRef.__Vfunc_store_element_data__2138__value))) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U))))
                        : (((~ (0xffffffffULL << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__2138__result) 
                           | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2138__value)) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U)))));
            } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2138__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__2138__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__2138__result) 
                       | ((QData)((IData)((0xffU & vlSelfRef.__Vfunc_store_element_data__2138__value))) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U))));
            } else {
                vlSelfRef.__Vfunc_store_element_data__2138__byte_value 
                    = (0xffU & (IData)((vlSelfRef.__Vfunc_store_element_data__2138__old_beat 
                                        >> (0x3fU & 
                                            VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U)))));
                vlSelfRef.__Vfunc_store_element_data__2138__byte_value 
                    = ((IData)(vlSelfRef.__Vfunc_store_element_data__2138__high_nibble)
                        ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_value)) 
                           | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__2138__value 
                                       << 4U))) : (
                                                   (0xf0U 
                                                    & (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_value)) 
                                                   | (0xfU 
                                                      & vlSelfRef.__Vfunc_store_element_data__2138__value)));
                vlSelfRef.__Vfunc_store_element_data__2138__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__2138__result) 
                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_value)) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U))));
            }
            vlSelfRef.__Vfunc_store_element_data__2138__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_data__2138__result;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_wdata 
                = vlSelfRef.__Vfunc_store_element_data__2138__Vfuncout;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_is_inline_rearm 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____VdfgExtracted_hf6182e41__0) 
           & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_opcode)));
    __Vfunc_fp32_sub__2436__rhs = tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_squared;
    __Vfunc_fp32_sub__2436__lhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_square;
    __Vfunc_fp32_neg__2438__value = __Vfunc_fp32_sub__2436__rhs;
    __Vfunc_fp32_neg__2438__Vfuncout = (((~ (__Vfunc_fp32_neg__2438__value 
                                             >> 0x1fU)) 
                                         << 0x1fU) 
                                        | (0x7fffffffU 
                                           & __Vfunc_fp32_neg__2438__value));
    __Vfunc_fp32_add__2437__rhs = __Vfunc_fp32_neg__2438__Vfuncout;
    __Vfunc_fp32_add__2437__lhs = __Vfunc_fp32_sub__2436__lhs;
    vlSelf->__Vfunc_fp32_add__2437__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12396167667122423764ull);
    vlSelf->__Vfunc_fp32_add__2437__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9182541537041416815ull);
    vlSelf->__Vfunc_fp32_add__2437__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17869611884961207652ull);
    vlSelf->__Vfunc_fp32_add__2437__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4821762331992246136ull);
    vlSelf->__Vfunc_fp32_add__2437__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10480670302901893633ull);
    vlSelf->__Vfunc_fp32_add__2437__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 5700416318048334676ull);
    vlSelf->__Vfunc_fp32_add__2437__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 25352554779997779ull);
    vlSelf->__Vfunc_fp32_add__2437__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 832561423158902341ull);
    vlSelf->__Vfunc_fp32_add__2437__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6538712335114811328ull);
    vlSelf->__Vfunc_fp32_add__2437__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15117733359832009155ull);
    vlSelf->__Vfunc_fp32_add__2437__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17921300180387387258ull);
    vlSelf->__Vfunc_fp32_add__2437__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14873851006478294891ull);
    vlSelf->__Vfunc_fp32_add__2437__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10319594150145861802ull);
    vlSelf->__Vfunc_fp32_add__2437__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13406562219566418587ull);
    vlSelf->__Vfunc_fp32_add__2437__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 17417619907832215001ull);
    vlSelf->__Vfunc_fp32_add__2437__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 8041393611067723731ull);
    vlSelf->__Vfunc_fp32_add__2437__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 7559055265922987524ull);
    vlSelf->__Vfunc_fp32_add__2437__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 7252590634982523811ull);
    vlSelf->__Vfunc_fp32_add__2437__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 9980489910215471558ull);
    vlSelf->__Vfunc_fp32_add__2437__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6348751833414835508ull);
    vlSelf->__Vfunc_fp32_add__2437__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12502495825765101911ull);
    vlSelf->__Vfunc_fp32_add__2437__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11505125971654731551ull);
    vlSelf->__Vfunc_fp32_add__2437__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14600666836710277042ull);
    vlSelf->__Vfunc_fp32_add__2437__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6326471822609847451ull);
    __Vfunc_fp32_add__2437__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2439__bits 
                            = __Vfunc_fp32_add__2437__lhs;
                        __Vfunc_fp32_is_nan__2439__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2439__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2439__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2439__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2439__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2439__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2439__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2440__bits 
                            = __Vfunc_fp32_add__2437__rhs;
                        __Vfunc_fp32_is_nan__2440__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2440__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2440__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2440__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2440__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2440__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2440__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout = 0x7fc00000U;
            goto __Vlabel3;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2441__bits 
                            = __Vfunc_fp32_add__2437__lhs;
                        __Vfunc_fp32_is_inf__2441__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2441__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2441__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2441__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2441__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2441__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2442__bits 
                            = __Vfunc_fp32_add__2437__rhs;
                        __Vfunc_fp32_is_inf__2442__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2442__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2442__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2442__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2442__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2442__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2443__bits 
                                    = __Vfunc_fp32_add__2437__lhs;
                                __Vfunc_fp32_is_inf__2443__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2443__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2443__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2443__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2443__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2443__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2444__bits 
                                    = __Vfunc_fp32_add__2437__rhs;
                                __Vfunc_fp32_is_inf__2444__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2444__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2444__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2444__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2444__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2444__Vfuncout))) 
                 & ((__Vfunc_fp32_add__2437__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__2437__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout = 0x7fc00000U;
                goto __Vlabel3;
            }
            vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2445__bits 
                            = __Vfunc_fp32_add__2437__lhs;
                        __Vfunc_fp32_is_inf__2445__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2445__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2445__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2445__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2445__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2445__Vfuncout))
                    ? __Vfunc_fp32_add__2437__lhs : __Vfunc_fp32_add__2437__rhs);
            goto __Vlabel3;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2446__bits 
                        = __Vfunc_fp32_add__2437__lhs;
                    __Vfunc_fp32_is_zero__2446__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2446__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2446__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2446__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2446__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2446__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout 
                = __Vfunc_fp32_add__2437__rhs;
            goto __Vlabel3;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2447__bits 
                        = __Vfunc_fp32_add__2437__rhs;
                    __Vfunc_fp32_is_zero__2447__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2447__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2447__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2447__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2447__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2447__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout 
                = __Vfunc_fp32_add__2437__lhs;
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_add__2437__lhs_sign 
            = (__Vfunc_fp32_add__2437__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2437__rhs_sign 
            = (__Vfunc_fp32_add__2437__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2437__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2437__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2437__lhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2437__lhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2437__lhs)));
        vlSelfRef.__Vfunc_fp32_add__2437__rhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2437__rhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2437__rhs)));
        vlSelfRef.__Vfunc_fp32_add__2437__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__2437__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__2437__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__2437__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2437__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2437__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2437__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2437__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2437__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2437__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2437__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2437__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2437__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2437__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2437__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2437__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2437__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2437__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2437__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2437__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2437__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2437__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__2437__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2437__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2437__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2437__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2437__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__2437__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__2437__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__2437__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2437__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__2437__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__small_ext, vlSelfRef.__Vfunc_fp32_add__2437__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__2437__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2437__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__2437__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__2437__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__2437__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__2437__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__2437__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2437__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__2437__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__2437__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__2437__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__2437__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2437__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__2437__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__2437__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2437__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__2437__work_ext);
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2437__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__2437__sticky))));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2437__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__2437__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__2437__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout = 0U;
                goto __Vlabel3;
            }
            __Vfunc_fp32_add__2437__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__2437__normalize_count = 1U;
            __Vfunc_fp32_add__2437__normalize_count = 2U;
            __Vfunc_fp32_add__2437__normalize_count = 3U;
            __Vfunc_fp32_add__2437__normalize_count = 4U;
            __Vfunc_fp32_add__2437__normalize_count = 5U;
            __Vfunc_fp32_add__2437__normalize_count = 6U;
            __Vfunc_fp32_add__2437__normalize_count = 7U;
            __Vfunc_fp32_add__2437__normalize_count = 8U;
            __Vfunc_fp32_add__2437__normalize_count = 9U;
            __Vfunc_fp32_add__2437__normalize_count = 0xaU;
            __Vfunc_fp32_add__2437__normalize_count = 0xbU;
            __Vfunc_fp32_add__2437__normalize_count = 0xcU;
            __Vfunc_fp32_add__2437__normalize_count = 0xdU;
            __Vfunc_fp32_add__2437__normalize_count = 0xeU;
            __Vfunc_fp32_add__2437__normalize_count = 0xfU;
            __Vfunc_fp32_add__2437__normalize_count = 0x10U;
            __Vfunc_fp32_add__2437__normalize_count = 0x11U;
            __Vfunc_fp32_add__2437__normalize_count = 0x12U;
            __Vfunc_fp32_add__2437__normalize_count = 0x13U;
            __Vfunc_fp32_add__2437__normalize_count = 0x14U;
            __Vfunc_fp32_add__2437__normalize_count = 0x15U;
            __Vfunc_fp32_add__2437__normalize_count = 0x16U;
            __Vfunc_fp32_add__2437__normalize_count = 0x17U;
            __Vfunc_fp32_add__2437__normalize_count = 0x18U;
            __Vfunc_fp32_add__2437__normalize_count = 0x19U;
            __Vfunc_fp32_add__2437__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__2437__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_add__2437__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__2437__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__2437__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__2437__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__2437__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__2437__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__2437__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__2437__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2437__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__2437__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__2437__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__2437__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__2437__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2437__mantissa));
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_add__2437__result_sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2437__mantissa)));
        __Vlabel3: ;
    }
    __Vfunc_fp32_sub__2436__Vfuncout = vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_variance 
        = __Vfunc_fp32_sub__2436__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_req_addr 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_dma_w)
            ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_addr
            : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_mem_req_addr);
    __Vtemp_4[0U] = (IData)((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr)) 
                              << 0x28U) | (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_addr)) 
                                            << 0x14U) 
                                           | (QData)((IData)(
                                                             (0xffff8U 
                                                              & ((3U 
                                                                  == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))
                                                                  ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_addr_q
                                                                  : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q)))))));
    __Vtemp_4[1U] = (((IData)((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr)) 
                                << 0x14U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr)))) 
                      << 0x1cU) | (IData)(((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr)) 
                                             << 0x28U) 
                                            | (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_addr)) 
                                                << 0x14U) 
                                               | (QData)((IData)(
                                                                 (0xffff8U 
                                                                  & ((3U 
                                                                      == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))
                                                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_addr_q
                                                                      : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q)))))) 
                                           >> 0x20U)));
    __Vtemp_4[2U] = (((IData)((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr)) 
                                << 0x14U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr)))) 
                      >> 4U) | ((IData)(((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr)) 
                                           << 0x14U) 
                                          | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr))) 
                                         >> 0x20U)) 
                                << 0x1cU));
    __Vtemp_4[3U] = ((IData)(((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr)) 
                                << 0x14U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr))) 
                              >> 0x20U)) >> 4U);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
        = ((0x77U >= (0x7fU & ((IData)(0x14U) * (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))))
            ? (0xfffffU & (((0U == (0x1fU & ((IData)(0x14U) 
                                             * (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))))
                             ? 0U : (__Vtemp_4[(((IData)(0x13U) 
                                                 + 
                                                 (0x7fU 
                                                  & ((IData)(0x14U) 
                                                     * (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)))) 
                                                >> 5U)] 
                                     << ((IData)(0x20U) 
                                         - (0x1fU & 
                                            ((IData)(0x14U) 
                                             * (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)))))) 
                           | (__Vtemp_4[(3U & (((IData)(0x14U) 
                                                * (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)) 
                                               >> 5U))] 
                              >> (0x1fU & ((IData)(0x14U) 
                                           * (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))))))
            : 0U);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wstrb 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_wstrb)) 
            << 0x20U) | (QData)((IData)(((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_wstrb) 
                                           << 0x18U) 
                                          | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_wstrb) 
                                             << 0x10U)) 
                                         | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_wstrb) 
                                             << 8U) 
                                            | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[0U] 
        = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[1U] 
        = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                   >> 0x20U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[2U] 
        = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_wdata);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[3U] 
        = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[4U] 
        = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_wdata);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[5U] 
        = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[6U] 
        = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_wdata);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[7U] 
        = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[8U] 
        = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_wdata);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[9U] 
        = (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[0xaU] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wdata[0xbU] = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0_resolved 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1_resolved 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal;
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
         >> 0x1fU)) {
        if (((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0)))
                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0)));
        }
        if (((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1)))
                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1)));
        }
        if (((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)))
                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)));
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_resources_valid = 1U;
    if ((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0))) {
        if ((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0))) 
              | (0U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0)))
                         ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                        [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0))]
                         : 0U))) | ((~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
                                        >> 0x1fU)) 
                                    & (((0xfeU >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0)))
                                         ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                                        [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0))]
                                         : 0U) != (0xfU 
                                                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0) 
                                                      >> 8U)))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_resources_valid = 0U;
        }
    }
    if ((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))) {
        if ((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))) 
              | (0U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1)))
                         ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                        [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))]
                         : 0U))) | ((~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
                                        >> 0x1fU)) 
                                    & (((0xfeU >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1)))
                                         ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                                        [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))]
                                         : 0U) != (0xfU 
                                                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1) 
                                                      >> 8U)))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_resources_valid = 0U;
        }
    }
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_is_inline_rearm) {
        if ((1U & ((((((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0)) 
                       | (0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))) 
                      | (0xfffU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))) 
                     | (0xffU <= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)))) 
                    | (~ ((2U == ((0xfeU >= (0xffU 
                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)))
                                   ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                  [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))]
                                   : 0U)) | (3U == 
                                             ((0xfeU 
                                               >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)))
                                               ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                              [(0xffU 
                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))]
                                               : 0U))))) 
                   | ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__unnamedblk1__DOT__slot = 0;
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 0U;
                            if ((0xfffU != (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref))) {
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [0U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [0U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [0U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [0U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [0U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [0U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__unnamedblk1__DOT__slot = 8U;
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [1U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [1U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [1U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [1U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [1U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [1U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [2U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [2U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [2U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [2U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [2U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [2U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [3U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [3U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [3U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [3U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [3U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [3U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [4U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [4U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [4U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [4U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [4U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [4U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [5U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [5U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [5U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [5U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [5U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [5U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [6U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [6U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [6U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [6U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [6U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [6U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [7U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [7U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [7U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [7U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [7U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [7U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                            }
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__Vfuncout 
                                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found;
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_resources_valid = 0U;
        }
    } else if ((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))) {
        if (((((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))) 
                 | (0U != ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)))
                            ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                           [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))]
                            : 0U))) | ((~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
                                           >> 0x1fU)) 
                                       & (((0xfeU >= 
                                            (0xffU 
                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)))
                                            ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                                           [(0xffU 
                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))]
                                            : 0U) != 
                                          (0xfU & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal) 
                                                   >> 8U))))) 
               | ([&]() {
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved;
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__unnamedblk1__DOT__slot = 0;
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 0U;
                                if ((0xfffU != (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref))) {
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [0U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [0U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [0U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [0U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [0U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [0U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__unnamedblk1__DOT__slot = 8U;
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [1U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [1U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [1U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [1U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [1U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [1U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [2U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [2U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [2U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [2U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [2U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [2U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [3U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [3U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [3U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [3U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [3U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [3U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [4U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [4U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [4U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [4U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [4U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [4U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [5U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [5U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [5U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [5U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [5U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [5U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [6U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [6U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [6U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [6U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [6U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [6U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [7U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [7U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [7U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [7U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [7U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [7U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                }
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__Vfuncout 
                                    = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found;
                            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__Vfuncout))) 
              | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved) 
                 == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0_resolved))) 
             | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved) 
                == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1_resolved)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_resources_valid = 0U;
        }
    }
}

VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__7(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___stl_sequent__TOP__7\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vfunc_fp32_is_nan__2344__unused_sign;
    __Vfunc_fp32_is_nan__2344__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2345__unused_sign;
    __Vfunc_fp32_is_nan__2345__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2347__unused_sign;
    __Vfunc_fp32_is_nan__2347__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2348__unused_sign;
    __Vfunc_fp32_is_nan__2348__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2349__unused_sign;
    __Vfunc_fp32_is_zero__2349__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2350__unused_sign;
    __Vfunc_fp32_is_zero__2350__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2352__unused_sign;
    __Vfunc_fp32_is_nan__2352__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2353__unused_sign;
    __Vfunc_fp32_is_nan__2353__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2355__unused_sign;
    __Vfunc_fp32_is_nan__2355__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2356__unused_sign;
    __Vfunc_fp32_is_nan__2356__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2357__unused_sign;
    __Vfunc_fp32_is_zero__2357__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2358__unused_sign;
    __Vfunc_fp32_is_zero__2358__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2360__normalize_count;
    __Vfunc_fp32_add__2360__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2362__unused_sign;
    __Vfunc_fp32_is_nan__2362__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2363__unused_sign;
    __Vfunc_fp32_is_nan__2363__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2364__unused_sign;
    __Vfunc_fp32_is_inf__2364__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2365__unused_sign;
    __Vfunc_fp32_is_inf__2365__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2366__unused_sign;
    __Vfunc_fp32_is_inf__2366__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2367__unused_sign;
    __Vfunc_fp32_is_inf__2367__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2368__unused_sign;
    __Vfunc_fp32_is_inf__2368__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2369__unused_sign;
    __Vfunc_fp32_is_zero__2369__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2370__unused_sign;
    __Vfunc_fp32_is_zero__2370__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2372__lhs;
    __Vfunc_fp32_add__2372__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2372__rhs;
    __Vfunc_fp32_add__2372__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2372__normalize_count;
    __Vfunc_fp32_add__2372__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2373__unused_sign;
    __Vfunc_fp32_is_nan__2373__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2374__unused_sign;
    __Vfunc_fp32_is_nan__2374__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2375__unused_sign;
    __Vfunc_fp32_is_inf__2375__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2376__unused_sign;
    __Vfunc_fp32_is_inf__2376__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2377__unused_sign;
    __Vfunc_fp32_is_inf__2377__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2378__unused_sign;
    __Vfunc_fp32_is_inf__2378__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2379__unused_sign;
    __Vfunc_fp32_is_inf__2379__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2380__unused_sign;
    __Vfunc_fp32_is_zero__2380__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2381__unused_sign;
    __Vfunc_fp32_is_zero__2381__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2382__lhs;
    __Vfunc_fp32_mul__2382__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2382__rhs;
    __Vfunc_fp32_mul__2382__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2382__normalize_count;
    __Vfunc_fp32_mul__2382__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2383__unused_sign;
    __Vfunc_fp32_is_nan__2383__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2384__unused_sign;
    __Vfunc_fp32_is_nan__2384__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2385__unused_sign;
    __Vfunc_fp32_is_inf__2385__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2386__unused_sign;
    __Vfunc_fp32_is_zero__2386__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2387__unused_sign;
    __Vfunc_fp32_is_inf__2387__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2388__unused_sign;
    __Vfunc_fp32_is_zero__2388__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2389__unused_sign;
    __Vfunc_fp32_is_inf__2389__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2390__unused_sign;
    __Vfunc_fp32_is_inf__2390__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2391__unused_sign;
    __Vfunc_fp32_is_zero__2391__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2392__unused_sign;
    __Vfunc_fp32_is_zero__2392__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2448__lhs;
    __Vfunc_fp32_add__2448__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2448__rhs;
    __Vfunc_fp32_add__2448__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2448__normalize_count;
    __Vfunc_fp32_add__2448__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2449__unused_sign;
    __Vfunc_fp32_is_nan__2449__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2450__unused_sign;
    __Vfunc_fp32_is_nan__2450__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2451__unused_sign;
    __Vfunc_fp32_is_inf__2451__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2452__unused_sign;
    __Vfunc_fp32_is_inf__2452__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2453__unused_sign;
    __Vfunc_fp32_is_inf__2453__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2454__unused_sign;
    __Vfunc_fp32_is_inf__2454__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2455__unused_sign;
    __Vfunc_fp32_is_inf__2455__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2456__unused_sign;
    __Vfunc_fp32_is_zero__2456__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2457__unused_sign;
    __Vfunc_fp32_is_zero__2457__unused_sign = 0;
    // Body
    __Vfunc_fp32_add__2448__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x24U];
    __Vfunc_fp32_add__2448__lhs = ((5U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x13U])
                                    ? ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_variance 
                                        >> 0x1fU) ? 0U
                                        : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_variance)
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_square);
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_add__2448__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7780758949167807412ull);
    vlSelf->__Vfunc_fp32_add__2448__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5176698633999424678ull);
    vlSelf->__Vfunc_fp32_add__2448__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3067407594559305820ull);
    vlSelf->__Vfunc_fp32_add__2448__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3804385220796930687ull);
    vlSelf->__Vfunc_fp32_add__2448__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8430069223449870185ull);
    vlSelf->__Vfunc_fp32_add__2448__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 11426233674736146748ull);
    vlSelf->__Vfunc_fp32_add__2448__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 13084585499509199178ull);
    vlSelf->__Vfunc_fp32_add__2448__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4513079105965656071ull);
    vlSelf->__Vfunc_fp32_add__2448__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15196973929670138337ull);
    vlSelf->__Vfunc_fp32_add__2448__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8998493861487238488ull);
    vlSelf->__Vfunc_fp32_add__2448__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5811507611962379444ull);
    vlSelf->__Vfunc_fp32_add__2448__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4895881032328722293ull);
    vlSelf->__Vfunc_fp32_add__2448__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6660698895974017831ull);
    vlSelf->__Vfunc_fp32_add__2448__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5602688285804464671ull);
    vlSelf->__Vfunc_fp32_add__2448__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 8124151621159397754ull);
    vlSelf->__Vfunc_fp32_add__2448__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 2009129899732855975ull);
    vlSelf->__Vfunc_fp32_add__2448__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 11331594719887510584ull);
    vlSelf->__Vfunc_fp32_add__2448__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 881483821224458656ull);
    vlSelf->__Vfunc_fp32_add__2448__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 15782164056792614256ull);
    vlSelf->__Vfunc_fp32_add__2448__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6744894437367558003ull);
    vlSelf->__Vfunc_fp32_add__2448__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5601754097249558828ull);
    vlSelf->__Vfunc_fp32_add__2448__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1156223759068138376ull);
    vlSelf->__Vfunc_fp32_add__2448__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16081085957908036682ull);
    vlSelf->__Vfunc_fp32_add__2448__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13133338306691817769ull);
    __Vfunc_fp32_add__2448__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2449__bits 
                            = __Vfunc_fp32_add__2448__lhs;
                        __Vfunc_fp32_is_nan__2449__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2449__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2449__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2449__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2449__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2449__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2449__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2450__bits 
                            = __Vfunc_fp32_add__2448__rhs;
                        __Vfunc_fp32_is_nan__2450__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2450__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2450__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2450__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2450__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2450__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2450__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout = 0x7fc00000U;
            goto __Vlabel0;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2451__bits 
                            = __Vfunc_fp32_add__2448__lhs;
                        __Vfunc_fp32_is_inf__2451__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2451__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2451__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2451__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2451__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2451__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2452__bits 
                            = __Vfunc_fp32_add__2448__rhs;
                        __Vfunc_fp32_is_inf__2452__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2452__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2452__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2452__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2452__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2452__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2453__bits 
                                    = __Vfunc_fp32_add__2448__lhs;
                                __Vfunc_fp32_is_inf__2453__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2453__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2453__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2453__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2453__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2453__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2454__bits 
                                    = __Vfunc_fp32_add__2448__rhs;
                                __Vfunc_fp32_is_inf__2454__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2454__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2454__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2454__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2454__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2454__Vfuncout))) 
                 & ((__Vfunc_fp32_add__2448__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__2448__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout = 0x7fc00000U;
                goto __Vlabel0;
            }
            vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2455__bits 
                            = __Vfunc_fp32_add__2448__lhs;
                        __Vfunc_fp32_is_inf__2455__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2455__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2455__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2455__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2455__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2455__Vfuncout))
                    ? __Vfunc_fp32_add__2448__lhs : __Vfunc_fp32_add__2448__rhs);
            goto __Vlabel0;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2456__bits 
                        = __Vfunc_fp32_add__2448__lhs;
                    __Vfunc_fp32_is_zero__2456__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2456__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2456__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2456__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2456__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2456__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout 
                = __Vfunc_fp32_add__2448__rhs;
            goto __Vlabel0;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2457__bits 
                        = __Vfunc_fp32_add__2448__rhs;
                    __Vfunc_fp32_is_zero__2457__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2457__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2457__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2457__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2457__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2457__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout 
                = __Vfunc_fp32_add__2448__lhs;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_add__2448__lhs_sign 
            = (__Vfunc_fp32_add__2448__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2448__rhs_sign 
            = (__Vfunc_fp32_add__2448__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2448__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2448__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2448__lhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2448__lhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2448__lhs)));
        vlSelfRef.__Vfunc_fp32_add__2448__rhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2448__rhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2448__rhs)));
        vlSelfRef.__Vfunc_fp32_add__2448__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__2448__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__2448__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__2448__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2448__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2448__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2448__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2448__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2448__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2448__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2448__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2448__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2448__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2448__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2448__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2448__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2448__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2448__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2448__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2448__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2448__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2448__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__2448__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2448__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2448__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2448__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2448__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__2448__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__2448__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__2448__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2448__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__2448__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__small_ext, vlSelfRef.__Vfunc_fp32_add__2448__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__2448__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2448__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__2448__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__2448__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__2448__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__2448__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__2448__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2448__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__2448__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__2448__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__2448__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__2448__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2448__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__2448__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__2448__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2448__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__2448__work_ext);
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2448__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__2448__sticky))));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2448__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__2448__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__2448__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout = 0U;
                goto __Vlabel0;
            }
            __Vfunc_fp32_add__2448__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__2448__normalize_count = 1U;
            __Vfunc_fp32_add__2448__normalize_count = 2U;
            __Vfunc_fp32_add__2448__normalize_count = 3U;
            __Vfunc_fp32_add__2448__normalize_count = 4U;
            __Vfunc_fp32_add__2448__normalize_count = 5U;
            __Vfunc_fp32_add__2448__normalize_count = 6U;
            __Vfunc_fp32_add__2448__normalize_count = 7U;
            __Vfunc_fp32_add__2448__normalize_count = 8U;
            __Vfunc_fp32_add__2448__normalize_count = 9U;
            __Vfunc_fp32_add__2448__normalize_count = 0xaU;
            __Vfunc_fp32_add__2448__normalize_count = 0xbU;
            __Vfunc_fp32_add__2448__normalize_count = 0xcU;
            __Vfunc_fp32_add__2448__normalize_count = 0xdU;
            __Vfunc_fp32_add__2448__normalize_count = 0xeU;
            __Vfunc_fp32_add__2448__normalize_count = 0xfU;
            __Vfunc_fp32_add__2448__normalize_count = 0x10U;
            __Vfunc_fp32_add__2448__normalize_count = 0x11U;
            __Vfunc_fp32_add__2448__normalize_count = 0x12U;
            __Vfunc_fp32_add__2448__normalize_count = 0x13U;
            __Vfunc_fp32_add__2448__normalize_count = 0x14U;
            __Vfunc_fp32_add__2448__normalize_count = 0x15U;
            __Vfunc_fp32_add__2448__normalize_count = 0x16U;
            __Vfunc_fp32_add__2448__normalize_count = 0x17U;
            __Vfunc_fp32_add__2448__normalize_count = 0x18U;
            __Vfunc_fp32_add__2448__normalize_count = 0x19U;
            __Vfunc_fp32_add__2448__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__2448__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_add__2448__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__2448__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__2448__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__2448__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__2448__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__2448__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__2448__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__2448__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2448__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__2448__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__2448__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__2448__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__2448__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2448__mantissa));
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_add__2448__result_sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2448__mantissa)));
        __Vlabel0: ;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_variance_plus_epsilon 
        = vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout;
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[__Vilp1] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_flat[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____VdfgExtracted_hf6182e41__0) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[2U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0_resolved)));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[3U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0_resolved)) 
                       >> 0x20U));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[4U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1_resolved)));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[5U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1_resolved)) 
                       >> 0x20U));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[8U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[9U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)) 
                       >> 0x20U));
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_is_inline_rearm) 
             & (0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[2U] 
                = (IData)((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[3U] 
                = (IData)(((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)) 
                           >> 0x20U));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[8U] 
                = ((0xffffff00U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[8U]) 
                   | (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[8U] 
                = ((0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[8U]) 
                   | ((IData)((QData)((IData)((0xfU 
                                               & ((IData)(1U) 
                                                  + 
                                                  ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved) 
                                                   >> 8U)))))) 
                      << 8U));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[9U] 
                = (((IData)((QData)((IData)((0xfU & 
                                             ((IData)(1U) 
                                              + ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved) 
                                                 >> 8U)))))) 
                    >> 0x18U) | ((IData)(((QData)((IData)(
                                                          (0xfU 
                                                           & ((IData)(1U) 
                                                              + 
                                                              ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved) 
                                                               >> 8U))))) 
                                          >> 0x20U)) 
                                 << 8U));
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_static_valid 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_resources_valid) 
           & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
               >> 0x1fU) ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_valid)
               : (((((IData)((((0U == (0x3fU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[0U])) 
                               & (0U == (0xc0000U & 
                                         vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U]))) 
                              & (0x1000000U == (0xff000000U 
                                                & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U])))) 
                     & ([&]() {
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode 
                                        = (0xffU & 
                                           vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U]);
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine 
                                        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U] 
                                           >> 0x1cU);
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__Vfuncout 
                                        = ((1U & (~ 
                                                  ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine) 
                                                   >> 3U))) 
                                           && ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine))
                                                ? (
                                                   (1U 
                                                    & (~ 
                                                       ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine) 
                                                        >> 1U))) 
                                                   && ((1U 
                                                        & (~ (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine))) 
                                                       && (((((0x80U 
                                                               == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)) 
                                                              | (0x81U 
                                                                 == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                             | (0x82U 
                                                                == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                            | (0x84U 
                                                               == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                           | (0x86U 
                                                              == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)))))
                                                : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine))
                                                     ? 
                                                    ((((((((((0x60U 
                                                              == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)) 
                                                             | (0x61U 
                                                                == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                            | (0x62U 
                                                               == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                           | (0x63U 
                                                              == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                          | (0x64U 
                                                             == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                         | (0x65U 
                                                            == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                        | (0x66U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                       | (0x67U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                      | (0x68U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                     | (0x69U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)))
                                                     : 
                                                    ((((0x40U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)) 
                                                       | (0x41U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                      | (0x42U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                     | (0x43U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine))
                                                     ? 
                                                    ((((((0x20U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)) 
                                                         | (0x21U 
                                                            == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                        | (0x22U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                       | (0x23U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                      | (0x24U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                     | (0x25U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)))
                                                     : 
                                                    (((((0U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)) 
                                                        | (1U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                       | (2U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                      | (3U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                     | (4U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)))))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__Vfuncout))) 
                    & ([&]() {
                                vlSelfRef.__Vfunc_npu_event_ref_valid__1690__event_ref 
                                    = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U] 
                                       >> 0x14U);
                                vlSelfRef.__Vfunc_npu_event_ref_valid__1690__Vfuncout 
                                    = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1690__event_ref)) 
                                       | (0xffU != 
                                          (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1690__event_ref))));
                            }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1690__Vfuncout))) 
                   & ([&]() {
                            vlSelfRef.__Vfunc_npu_event_ref_valid__1691__event_ref 
                                = (0xfffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U]);
                            vlSelfRef.__Vfunc_npu_event_ref_valid__1691__Vfuncout 
                                = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1691__event_ref)) 
                                   | (0xffU != (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1691__event_ref))));
                        }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1691__Vfuncout))) 
                  & ([&]() {
                        vlSelfRef.__Vfunc_npu_event_ref_valid__1692__event_ref 
                            = (0xfffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
                                         >> 0xcU));
                        vlSelfRef.__Vfunc_npu_event_ref_valid__1692__Vfuncout 
                            = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1692__event_ref)) 
                               | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1692__event_ref))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1692__Vfuncout)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_fp;
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x25U]) 
         | (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x26U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_less_than__2343__rhs 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x25U];
                    vlSelfRef.__Vfunc_fp32_less_than__2343__lhs 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
                    {
                        if (((([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__2344__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__2343__lhs;
                                            __Vfunc_fp32_is_nan__2344__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__2344__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__2344__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__2344__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2344__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2344__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2344__Vfuncout)) 
                              | ([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__2345__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__2343__rhs;
                                            __Vfunc_fp32_is_nan__2345__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__2345__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__2345__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__2345__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2345__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2345__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2345__Vfuncout))) 
                             | ([&]() {
                                        vlSelfRef.__Vfunc_fp32_equal__2346__rhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__2343__rhs;
                                        vlSelfRef.__Vfunc_fp32_equal__2346__lhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__2343__lhs;
                                        {
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2347__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2346__lhs;
                                                            __Vfunc_fp32_is_nan__2347__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__2347__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__2347__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2347__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2347__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2347__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2347__Vfuncout)) 
                                                 | ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2348__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2346__rhs;
                                                            __Vfunc_fp32_is_nan__2348__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__2348__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__2348__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2348__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2348__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2348__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2348__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__2346__Vfuncout = 0U;
                                                goto __Vlabel2;
                                            }
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2349__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2346__lhs;
                                                            __Vfunc_fp32_is_zero__2349__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__2349__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__2349__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2349__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__2349__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2349__Vfuncout)) 
                                                 & ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2350__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2346__rhs;
                                                            __Vfunc_fp32_is_zero__2350__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__2350__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__2350__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2350__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__2350__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2350__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__2346__Vfuncout = 1U;
                                                goto __Vlabel2;
                                            }
                                            vlSelfRef.__Vfunc_fp32_equal__2346__Vfuncout 
                                                = (vlSelfRef.__Vfunc_fp32_equal__2346__lhs 
                                                   == vlSelfRef.__Vfunc_fp32_equal__2346__rhs);
                                            __Vlabel2: ;
                                        }
                                    }(), (IData)(vlSelfRef.__Vfunc_fp32_equal__2346__Vfuncout)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__2343__Vfuncout = 0U;
                            goto __Vlabel1;
                        }
                        if (((vlSelfRef.__Vfunc_fp32_less_than__2343__lhs 
                              >> 0x1fU) != (vlSelfRef.__Vfunc_fp32_less_than__2343__rhs 
                                            >> 0x1fU))) {
                            vlSelfRef.__Vfunc_fp32_less_than__2343__Vfuncout 
                                = (vlSelfRef.__Vfunc_fp32_less_than__2343__lhs 
                                   >> 0x1fU);
                            goto __Vlabel1;
                        }
                        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_less_than__2343__lhs 
                                      >> 0x1fU)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__2343__Vfuncout 
                                = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2343__lhs) 
                                   < (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2343__rhs));
                            goto __Vlabel1;
                        }
                        vlSelfRef.__Vfunc_fp32_less_than__2343__Vfuncout 
                            = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2343__lhs) 
                               > (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2343__rhs));
                        __Vlabel1: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_fp32_less_than__2343__Vfuncout))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x25U];
        } else if (([&]() {
                    vlSelfRef.__Vfunc_fp32_less_than__2351__rhs 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
                    vlSelfRef.__Vfunc_fp32_less_than__2351__lhs 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x26U];
                    {
                        if (((([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__2352__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__2351__lhs;
                                            __Vfunc_fp32_is_nan__2352__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__2352__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__2352__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__2352__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2352__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2352__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2352__Vfuncout)) 
                              | ([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__2353__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__2351__rhs;
                                            __Vfunc_fp32_is_nan__2353__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__2353__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__2353__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__2353__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2353__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2353__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2353__Vfuncout))) 
                             | ([&]() {
                                        vlSelfRef.__Vfunc_fp32_equal__2354__rhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__2351__rhs;
                                        vlSelfRef.__Vfunc_fp32_equal__2354__lhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__2351__lhs;
                                        {
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2355__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2354__lhs;
                                                            __Vfunc_fp32_is_nan__2355__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__2355__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__2355__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2355__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2355__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2355__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2355__Vfuncout)) 
                                                 | ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2356__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2354__rhs;
                                                            __Vfunc_fp32_is_nan__2356__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__2356__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__2356__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2356__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2356__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2356__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2356__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__2354__Vfuncout = 0U;
                                                goto __Vlabel4;
                                            }
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2357__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2354__lhs;
                                                            __Vfunc_fp32_is_zero__2357__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__2357__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__2357__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2357__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__2357__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2357__Vfuncout)) 
                                                 & ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2358__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2354__rhs;
                                                            __Vfunc_fp32_is_zero__2358__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__2358__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__2358__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2358__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__2358__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2358__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__2354__Vfuncout = 1U;
                                                goto __Vlabel4;
                                            }
                                            vlSelfRef.__Vfunc_fp32_equal__2354__Vfuncout 
                                                = (vlSelfRef.__Vfunc_fp32_equal__2354__lhs 
                                                   == vlSelfRef.__Vfunc_fp32_equal__2354__rhs);
                                            __Vlabel4: ;
                                        }
                                    }(), (IData)(vlSelfRef.__Vfunc_fp32_equal__2354__Vfuncout)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__2351__Vfuncout = 0U;
                            goto __Vlabel3;
                        }
                        if (((vlSelfRef.__Vfunc_fp32_less_than__2351__lhs 
                              >> 0x1fU) != (vlSelfRef.__Vfunc_fp32_less_than__2351__rhs 
                                            >> 0x1fU))) {
                            vlSelfRef.__Vfunc_fp32_less_than__2351__Vfuncout 
                                = (vlSelfRef.__Vfunc_fp32_less_than__2351__lhs 
                                   >> 0x1fU);
                            goto __Vlabel3;
                        }
                        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_less_than__2351__lhs 
                                      >> 0x1fU)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__2351__Vfuncout 
                                = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2351__lhs) 
                                   < (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2351__rhs));
                            goto __Vlabel3;
                        }
                        vlSelfRef.__Vfunc_fp32_less_than__2351__Vfuncout 
                            = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2351__lhs) 
                               > (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2351__rhs));
                        __Vlabel3: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_fp32_less_than__2351__Vfuncout))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x26U];
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operation = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operand0 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operand1 = 0U;
    if ((0x80U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operation 
            = (0xfU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x13U]);
    } else if (((0x81U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                & ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q)) 
                   | (3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operation = 4U;
        vlSelfRef.__Vfunc_fp32_sub__2359__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_max_q;
        vlSelfRef.__Vfunc_fp32_sub__2359__lhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
        vlSelfRef.__Vfunc_fp32_neg__2361__value = vlSelfRef.__Vfunc_fp32_sub__2359__rhs;
        vlSelfRef.__Vfunc_fp32_neg__2361__Vfuncout 
            = (((~ (vlSelfRef.__Vfunc_fp32_neg__2361__value 
                    >> 0x1fU)) << 0x1fU) | (0x7fffffffU 
                                            & vlSelfRef.__Vfunc_fp32_neg__2361__value));
        vlSelfRef.__Vfunc_fp32_add__2360__rhs = vlSelfRef.__Vfunc_fp32_neg__2361__Vfuncout;
        vlSelfRef.__Vfunc_fp32_add__2360__lhs = vlSelfRef.__Vfunc_fp32_sub__2359__lhs;
        vlSelf->__Vfunc_fp32_add__2360__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10265547131006217732ull);
        vlSelf->__Vfunc_fp32_add__2360__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 85024869238508557ull);
        vlSelf->__Vfunc_fp32_add__2360__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13014727098614984705ull);
        vlSelf->__Vfunc_fp32_add__2360__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4813721593793642595ull);
        vlSelf->__Vfunc_fp32_add__2360__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17067703270188751039ull);
        vlSelf->__Vfunc_fp32_add__2360__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 17228302460925776939ull);
        vlSelf->__Vfunc_fp32_add__2360__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 1549187448501195905ull);
        vlSelf->__Vfunc_fp32_add__2360__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8950245997014681777ull);
        vlSelf->__Vfunc_fp32_add__2360__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13138414311530266297ull);
        vlSelf->__Vfunc_fp32_add__2360__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16598204646133939613ull);
        vlSelf->__Vfunc_fp32_add__2360__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13114435659719338443ull);
        vlSelf->__Vfunc_fp32_add__2360__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18427442913078939794ull);
        vlSelf->__Vfunc_fp32_add__2360__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15265864459633018339ull);
        vlSelf->__Vfunc_fp32_add__2360__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2534114477501486751ull);
        vlSelf->__Vfunc_fp32_add__2360__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 16021483574395267855ull);
        vlSelf->__Vfunc_fp32_add__2360__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 16410497028910950986ull);
        vlSelf->__Vfunc_fp32_add__2360__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 10116591446261072266ull);
        vlSelf->__Vfunc_fp32_add__2360__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 17989576811800875276ull);
        vlSelf->__Vfunc_fp32_add__2360__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 8107448091836035102ull);
        vlSelf->__Vfunc_fp32_add__2360__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 4520624777215271370ull);
        vlSelf->__Vfunc_fp32_add__2360__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14124718824766696345ull);
        vlSelf->__Vfunc_fp32_add__2360__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18042654413233783696ull);
        vlSelf->__Vfunc_fp32_add__2360__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3300309385422820550ull);
        vlSelf->__Vfunc_fp32_add__2360__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17543925457218567973ull);
        __Vfunc_fp32_add__2360__normalize_count = 0;
        {
            if ((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2362__bits 
                                = vlSelfRef.__Vfunc_fp32_add__2360__lhs;
                            __Vfunc_fp32_is_nan__2362__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2362__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2362__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2362__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2362__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2362__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2362__Vfuncout)) 
                 | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2363__bits 
                                = vlSelfRef.__Vfunc_fp32_add__2360__rhs;
                            __Vfunc_fp32_is_nan__2363__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2363__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2363__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2363__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2363__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2363__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2363__Vfuncout)))) {
                vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout = 0x7fc00000U;
                goto __Vlabel5;
            }
            if ((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2364__bits 
                                = vlSelfRef.__Vfunc_fp32_add__2360__lhs;
                            __Vfunc_fp32_is_inf__2364__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2364__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2364__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2364__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2364__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2364__Vfuncout)) 
                 | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2365__bits 
                                = vlSelfRef.__Vfunc_fp32_add__2360__rhs;
                            __Vfunc_fp32_is_inf__2365__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2365__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2365__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2365__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2365__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2365__Vfuncout)))) {
                if (((([&]() {
                                    vlSelfRef.__Vfunc_fp32_is_inf__2366__bits 
                                        = vlSelfRef.__Vfunc_fp32_add__2360__lhs;
                                    __Vfunc_fp32_is_inf__2366__unused_sign = 0;
                                    __Vfunc_fp32_is_inf__2366__unused_sign 
                                        = (vlSelfRef.__Vfunc_fp32_is_inf__2366__bits 
                                           >> 0x1fU);
                                    vlSelfRef.__Vfunc_fp32_is_inf__2366__Vfuncout 
                                        = (IData)((0x7f800000U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__Vfunc_fp32_is_inf__2366__bits)));
                                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2366__Vfuncout)) 
                      & ([&]() {
                                    vlSelfRef.__Vfunc_fp32_is_inf__2367__bits 
                                        = vlSelfRef.__Vfunc_fp32_add__2360__rhs;
                                    __Vfunc_fp32_is_inf__2367__unused_sign = 0;
                                    __Vfunc_fp32_is_inf__2367__unused_sign 
                                        = (vlSelfRef.__Vfunc_fp32_is_inf__2367__bits 
                                           >> 0x1fU);
                                    vlSelfRef.__Vfunc_fp32_is_inf__2367__Vfuncout 
                                        = (IData)((0x7f800000U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__Vfunc_fp32_is_inf__2367__bits)));
                                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2367__Vfuncout))) 
                     & ((vlSelfRef.__Vfunc_fp32_add__2360__lhs 
                         >> 0x1fU) != (vlSelfRef.__Vfunc_fp32_add__2360__rhs 
                                       >> 0x1fU)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout = 0x7fc00000U;
                    goto __Vlabel5;
                }
                vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout 
                    = (([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2368__bits 
                                = vlSelfRef.__Vfunc_fp32_add__2360__lhs;
                            __Vfunc_fp32_is_inf__2368__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2368__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2368__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2368__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2368__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2368__Vfuncout))
                        ? vlSelfRef.__Vfunc_fp32_add__2360__lhs
                        : vlSelfRef.__Vfunc_fp32_add__2360__rhs);
                goto __Vlabel5;
            }
            if (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2369__bits 
                            = vlSelfRef.__Vfunc_fp32_add__2360__lhs;
                        __Vfunc_fp32_is_zero__2369__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2369__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2369__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2369__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2369__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2369__Vfuncout))) {
                vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout 
                    = vlSelfRef.__Vfunc_fp32_add__2360__rhs;
                goto __Vlabel5;
            }
            if (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2370__bits 
                            = vlSelfRef.__Vfunc_fp32_add__2360__rhs;
                        __Vfunc_fp32_is_zero__2370__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2370__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2370__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2370__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2370__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2370__Vfuncout))) {
                vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout 
                    = vlSelfRef.__Vfunc_fp32_add__2360__lhs;
                goto __Vlabel5;
            }
            vlSelfRef.__Vfunc_fp32_add__2360__lhs_sign 
                = (vlSelfRef.__Vfunc_fp32_add__2360__lhs 
                   >> 0x1fU);
            vlSelfRef.__Vfunc_fp32_add__2360__rhs_sign 
                = (vlSelfRef.__Vfunc_fp32_add__2360__rhs 
                   >> 0x1fU);
            vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp 
                = (0xffU & (vlSelfRef.__Vfunc_fp32_add__2360__lhs 
                            >> 0x17U));
            vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp 
                = (0xffU & (vlSelfRef.__Vfunc_fp32_add__2360__rhs 
                            >> 0x17U));
            vlSelfRef.__Vfunc_fp32_add__2360__lhs_mant 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp))
                    ? (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2360__lhs)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2360__lhs)));
            vlSelfRef.__Vfunc_fp32_add__2360__rhs_mant 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp))
                    ? (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2360__rhs)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2360__rhs)));
            vlSelfRef.__Vfunc_fp32_add__2360__lhs_larger 
                = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp))
                      ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp)) 
                    > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp))) 
                   | (((IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp) 
                       == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp)) 
                      & (vlSelfRef.__Vfunc_fp32_add__2360__lhs_mant 
                         >= vlSelfRef.__Vfunc_fp32_add__2360__rhs_mant)));
            if (vlSelfRef.__Vfunc_fp32_add__2360__lhs_larger) {
                vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp));
                vlSelfRef.__Vfunc_fp32_add__2360__small_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp));
                vlSelfRef.__Vfunc_fp32_add__2360__large_mant 
                    = vlSelfRef.__Vfunc_fp32_add__2360__lhs_mant;
                vlSelfRef.__Vfunc_fp32_add__2360__small_mant 
                    = vlSelfRef.__Vfunc_fp32_add__2360__rhs_mant;
                vlSelfRef.__Vfunc_fp32_add__2360__large_sign 
                    = vlSelfRef.__Vfunc_fp32_add__2360__lhs_sign;
                vlSelfRef.__Vfunc_fp32_add__2360__small_sign 
                    = vlSelfRef.__Vfunc_fp32_add__2360__rhs_sign;
            } else {
                vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp));
                vlSelfRef.__Vfunc_fp32_add__2360__small_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp));
                vlSelfRef.__Vfunc_fp32_add__2360__large_mant 
                    = vlSelfRef.__Vfunc_fp32_add__2360__rhs_mant;
                vlSelfRef.__Vfunc_fp32_add__2360__small_mant 
                    = vlSelfRef.__Vfunc_fp32_add__2360__lhs_mant;
                vlSelfRef.__Vfunc_fp32_add__2360__large_sign 
                    = vlSelfRef.__Vfunc_fp32_add__2360__rhs_sign;
                vlSelfRef.__Vfunc_fp32_add__2360__small_sign 
                    = vlSelfRef.__Vfunc_fp32_add__2360__lhs_sign;
            }
            vlSelfRef.__Vfunc_fp32_add__2360__large_ext 
                = (vlSelfRef.__Vfunc_fp32_add__2360__large_mant 
                   << 3U);
            vlSelfRef.__Vfunc_fp32_add__2360__small_ext 
                = (vlSelfRef.__Vfunc_fp32_add__2360__small_mant 
                   << 3U);
            vlSelfRef.__Vfunc_fp32_add__2360__shift_amount 
                = ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                   - (IData)(vlSelfRef.__Vfunc_fp32_add__2360__small_exp));
            if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__2360__shift_amount)) {
                vlSelfRef.__Vfunc_fp32_add__2360__aligned_small 
                    = ((0U == vlSelfRef.__Vfunc_fp32_add__2360__small_ext)
                        ? 0U : 1U);
            } else {
                vlSelfRef.__Vfunc_fp32_add__2360__aligned_small 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__small_ext, vlSelfRef.__Vfunc_fp32_add__2360__shift_amount));
                vlSelfRef.__Vfunc_fp32_add__2360__discarded_mask 
                    = ((0U == vlSelfRef.__Vfunc_fp32_add__2360__shift_amount)
                        ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__2360__shift_amount) 
                                              - (IData)(1U))));
                vlSelfRef.__Vfunc_fp32_add__2360__sticky 
                    = (0U != (vlSelfRef.__Vfunc_fp32_add__2360__small_ext 
                              & vlSelfRef.__Vfunc_fp32_add__2360__discarded_mask));
                vlSelfRef.__Vfunc_fp32_add__2360__aligned_small 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2360__aligned_small) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__2360__aligned_small 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__2360__sticky))));
            }
            vlSelfRef.__Vfunc_fp32_add__2360__result_sign 
                = vlSelfRef.__Vfunc_fp32_add__2360__large_sign;
            if (((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_sign) 
                 == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__small_sign))) {
                vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                    = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2360__large_ext 
                                     + vlSelfRef.__Vfunc_fp32_add__2360__aligned_small));
                if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__2360__work_ext)) {
                    vlSelfRef.__Vfunc_fp32_add__2360__sticky 
                        = (1U & vlSelfRef.__Vfunc_fp32_add__2360__work_ext);
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2360__work_ext) 
                           | (1U & (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                                    | (IData)(vlSelfRef.__Vfunc_fp32_add__2360__sticky))));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)));
                }
            } else {
                vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                    = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2360__large_ext 
                                     - vlSelfRef.__Vfunc_fp32_add__2360__aligned_small));
                if ((0U == vlSelfRef.__Vfunc_fp32_add__2360__work_ext)) {
                    vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout = 0U;
                    goto __Vlabel5;
                }
                __Vfunc_fp32_add__2360__normalize_count = 0U;
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                __Vfunc_fp32_add__2360__normalize_count = 1U;
                __Vfunc_fp32_add__2360__normalize_count = 2U;
                __Vfunc_fp32_add__2360__normalize_count = 3U;
                __Vfunc_fp32_add__2360__normalize_count = 4U;
                __Vfunc_fp32_add__2360__normalize_count = 5U;
                __Vfunc_fp32_add__2360__normalize_count = 6U;
                __Vfunc_fp32_add__2360__normalize_count = 7U;
                __Vfunc_fp32_add__2360__normalize_count = 8U;
                __Vfunc_fp32_add__2360__normalize_count = 9U;
                __Vfunc_fp32_add__2360__normalize_count = 0xaU;
                __Vfunc_fp32_add__2360__normalize_count = 0xbU;
                __Vfunc_fp32_add__2360__normalize_count = 0xcU;
                __Vfunc_fp32_add__2360__normalize_count = 0xdU;
                __Vfunc_fp32_add__2360__normalize_count = 0xeU;
                __Vfunc_fp32_add__2360__normalize_count = 0xfU;
                __Vfunc_fp32_add__2360__normalize_count = 0x10U;
                __Vfunc_fp32_add__2360__normalize_count = 0x11U;
                __Vfunc_fp32_add__2360__normalize_count = 0x12U;
                __Vfunc_fp32_add__2360__normalize_count = 0x13U;
                __Vfunc_fp32_add__2360__normalize_count = 0x14U;
                __Vfunc_fp32_add__2360__normalize_count = 0x15U;
                __Vfunc_fp32_add__2360__normalize_count = 0x16U;
                __Vfunc_fp32_add__2360__normalize_count = 0x17U;
                __Vfunc_fp32_add__2360__normalize_count = 0x18U;
                __Vfunc_fp32_add__2360__normalize_count = 0x19U;
                __Vfunc_fp32_add__2360__normalize_count = 0x1aU;
            }
            vlSelfRef.__Vfunc_fp32_add__2360__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                                >> 3U));
            vlSelfRef.__Vfunc_fp32_add__2360__increment 
                = (1U & ((vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                          >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                                      >> 1U) | vlSelfRef.__Vfunc_fp32_add__2360__work_ext) 
                                    | vlSelfRef.__Vfunc_fp32_add__2360__mantissa)));
            vlSelfRef.__Vfunc_fp32_add__2360__rounded 
                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__2360__mantissa 
                                 + (IData)(vlSelfRef.__Vfunc_fp32_add__2360__increment)));
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__2360__rounded)) {
                vlSelfRef.__Vfunc_fp32_add__2360__mantissa 
                    = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2360__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)));
            } else {
                vlSelfRef.__Vfunc_fp32_add__2360__mantissa 
                    = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__2360__rounded);
            }
            if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp))) {
                vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout 
                    = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__result_sign) 
                                      << 0x1fU));
                goto __Vlabel5;
            }
            if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)) 
                 & (~ (vlSelfRef.__Vfunc_fp32_add__2360__mantissa 
                       >> 0x17U)))) {
                vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout 
                    = (((IData)(vlSelfRef.__Vfunc_fp32_add__2360__result_sign) 
                        << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2360__mantissa));
                goto __Vlabel5;
            }
            vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__2360__result_sign) 
                    << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                                 << 0x17U)) 
                                 | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2360__mantissa)));
            __Vlabel5: ;
        }
        vlSelfRef.__Vfunc_fp32_sub__2359__Vfuncout 
            = vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operand0 
            = vlSelfRef.__Vfunc_fp32_sub__2359__Vfuncout;
    } else if ((((0x82U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                 & (4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) 
                & (0xfU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operation = 5U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operand0 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_variance_plus_epsilon;
    }
    __Vfunc_fp32_add__2372__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
    __Vfunc_fp32_add__2372__lhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_q;
    vlSelf->__Vfunc_fp32_add__2372__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15784468020137470993ull);
    vlSelf->__Vfunc_fp32_add__2372__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6781694929890654319ull);
    vlSelf->__Vfunc_fp32_add__2372__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6897450347017560216ull);
    vlSelf->__Vfunc_fp32_add__2372__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2078292003106641261ull);
    vlSelf->__Vfunc_fp32_add__2372__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17171407236919381424ull);
    vlSelf->__Vfunc_fp32_add__2372__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2591267356027490760ull);
    vlSelf->__Vfunc_fp32_add__2372__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15474492935856957272ull);
    vlSelf->__Vfunc_fp32_add__2372__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 3116061100711832455ull);
    vlSelf->__Vfunc_fp32_add__2372__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18162127991969034775ull);
    vlSelf->__Vfunc_fp32_add__2372__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 1164433951343992446ull);
    vlSelf->__Vfunc_fp32_add__2372__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16956599900293910037ull);
    vlSelf->__Vfunc_fp32_add__2372__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3292759210754679556ull);
    vlSelf->__Vfunc_fp32_add__2372__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2785992656188754781ull);
    vlSelf->__Vfunc_fp32_add__2372__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5829963184843980109ull);
    vlSelf->__Vfunc_fp32_add__2372__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 4104249995490511669ull);
    vlSelf->__Vfunc_fp32_add__2372__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 1482341946139903203ull);
    vlSelf->__Vfunc_fp32_add__2372__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 3644717347254901327ull);
    vlSelf->__Vfunc_fp32_add__2372__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 11159501393630393763ull);
    vlSelf->__Vfunc_fp32_add__2372__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 15397042247053913107ull);
    vlSelf->__Vfunc_fp32_add__2372__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 17710570143786108935ull);
    vlSelf->__Vfunc_fp32_add__2372__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 916233850746986101ull);
    vlSelf->__Vfunc_fp32_add__2372__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2323054413384578536ull);
    vlSelf->__Vfunc_fp32_add__2372__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16989784512008634081ull);
    vlSelf->__Vfunc_fp32_add__2372__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12285815612537813824ull);
    __Vfunc_fp32_add__2372__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2373__bits 
                            = __Vfunc_fp32_add__2372__lhs;
                        __Vfunc_fp32_is_nan__2373__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2373__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2373__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2373__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2373__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2373__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2373__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2374__bits 
                            = __Vfunc_fp32_add__2372__rhs;
                        __Vfunc_fp32_is_nan__2374__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2374__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2374__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2374__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2374__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2374__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2374__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__2372__Vfuncout = 0x7fc00000U;
            goto __Vlabel6;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2375__bits 
                            = __Vfunc_fp32_add__2372__lhs;
                        __Vfunc_fp32_is_inf__2375__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2375__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2375__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2375__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2375__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2375__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2376__bits 
                            = __Vfunc_fp32_add__2372__rhs;
                        __Vfunc_fp32_is_inf__2376__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2376__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2376__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2376__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2376__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2376__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2377__bits 
                                    = __Vfunc_fp32_add__2372__lhs;
                                __Vfunc_fp32_is_inf__2377__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2377__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2377__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2377__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2377__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2377__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2378__bits 
                                    = __Vfunc_fp32_add__2372__rhs;
                                __Vfunc_fp32_is_inf__2378__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2378__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2378__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2378__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2378__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2378__Vfuncout))) 
                 & ((__Vfunc_fp32_add__2372__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__2372__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__Vfuncout = 0x7fc00000U;
                goto __Vlabel6;
            }
            vlSelfRef.__Vfunc_fp32_add__2372__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2379__bits 
                            = __Vfunc_fp32_add__2372__lhs;
                        __Vfunc_fp32_is_inf__2379__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2379__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2379__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2379__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2379__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2379__Vfuncout))
                    ? __Vfunc_fp32_add__2372__lhs : __Vfunc_fp32_add__2372__rhs);
            goto __Vlabel6;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2380__bits 
                        = __Vfunc_fp32_add__2372__lhs;
                    __Vfunc_fp32_is_zero__2380__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2380__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2380__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2380__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2380__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2380__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2372__Vfuncout 
                = __Vfunc_fp32_add__2372__rhs;
            goto __Vlabel6;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2381__bits 
                        = __Vfunc_fp32_add__2372__rhs;
                    __Vfunc_fp32_is_zero__2381__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2381__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2381__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2381__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2381__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2381__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2372__Vfuncout 
                = __Vfunc_fp32_add__2372__lhs;
            goto __Vlabel6;
        }
        vlSelfRef.__Vfunc_fp32_add__2372__lhs_sign 
            = (__Vfunc_fp32_add__2372__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2372__rhs_sign 
            = (__Vfunc_fp32_add__2372__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2372__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2372__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2372__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2372__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2372__lhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2372__lhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2372__lhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2372__lhs)));
        vlSelfRef.__Vfunc_fp32_add__2372__rhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2372__rhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2372__rhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2372__rhs)));
        vlSelfRef.__Vfunc_fp32_add__2372__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2372__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2372__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2372__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2372__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__2372__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__2372__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__2372__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__2372__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__2372__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2372__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2372__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2372__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2372__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2372__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2372__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2372__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2372__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2372__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2372__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2372__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2372__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2372__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2372__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2372__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2372__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2372__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2372__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2372__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2372__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2372__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2372__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2372__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2372__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2372__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2372__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__2372__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2372__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2372__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2372__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2372__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__2372__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__2372__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__2372__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2372__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__2372__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__small_ext, vlSelfRef.__Vfunc_fp32_add__2372__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__2372__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2372__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__2372__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__2372__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__2372__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__2372__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__2372__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2372__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__2372__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__2372__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__2372__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__2372__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__2372__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2372__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__2372__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__2372__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2372__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__2372__work_ext);
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2372__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__2372__sticky))));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2372__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__2372__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__2372__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2372__Vfuncout = 0U;
                goto __Vlabel6;
            }
            __Vfunc_fp32_add__2372__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2372__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__2372__normalize_count = 1U;
            __Vfunc_fp32_add__2372__normalize_count = 2U;
            __Vfunc_fp32_add__2372__normalize_count = 3U;
            __Vfunc_fp32_add__2372__normalize_count = 4U;
            __Vfunc_fp32_add__2372__normalize_count = 5U;
            __Vfunc_fp32_add__2372__normalize_count = 6U;
            __Vfunc_fp32_add__2372__normalize_count = 7U;
            __Vfunc_fp32_add__2372__normalize_count = 8U;
            __Vfunc_fp32_add__2372__normalize_count = 9U;
            __Vfunc_fp32_add__2372__normalize_count = 0xaU;
            __Vfunc_fp32_add__2372__normalize_count = 0xbU;
            __Vfunc_fp32_add__2372__normalize_count = 0xcU;
            __Vfunc_fp32_add__2372__normalize_count = 0xdU;
            __Vfunc_fp32_add__2372__normalize_count = 0xeU;
            __Vfunc_fp32_add__2372__normalize_count = 0xfU;
            __Vfunc_fp32_add__2372__normalize_count = 0x10U;
            __Vfunc_fp32_add__2372__normalize_count = 0x11U;
            __Vfunc_fp32_add__2372__normalize_count = 0x12U;
            __Vfunc_fp32_add__2372__normalize_count = 0x13U;
            __Vfunc_fp32_add__2372__normalize_count = 0x14U;
            __Vfunc_fp32_add__2372__normalize_count = 0x15U;
            __Vfunc_fp32_add__2372__normalize_count = 0x16U;
            __Vfunc_fp32_add__2372__normalize_count = 0x17U;
            __Vfunc_fp32_add__2372__normalize_count = 0x18U;
            __Vfunc_fp32_add__2372__normalize_count = 0x19U;
            __Vfunc_fp32_add__2372__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__2372__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_add__2372__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__2372__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__2372__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__2372__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__2372__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__2372__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__2372__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__2372__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__2372__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2372__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__2372__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__2372__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__2372__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__2372__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__result_sign) 
                                  << 0x1fU));
            goto __Vlabel6;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__2372__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__2372__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__2372__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2372__mantissa));
            goto __Vlabel6;
        }
        vlSelfRef.__Vfunc_fp32_add__2372__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_add__2372__result_sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2372__mantissa)));
        __Vlabel6: ;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_plus_x 
        = vlSelfRef.__Vfunc_fp32_add__2372__Vfuncout;
    __Vfunc_fp32_mul__2382__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
    __Vfunc_fp32_mul__2382__lhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
    vlSelf->__Vfunc_fp32_mul__2382__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17351666783713089087ull);
    vlSelf->__Vfunc_fp32_mul__2382__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12941955071424495006ull);
    vlSelf->__Vfunc_fp32_mul__2382__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11579908089622436014ull);
    vlSelf->__Vfunc_fp32_mul__2382__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 11238753775614868766ull);
    vlSelf->__Vfunc_fp32_mul__2382__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 459675014107909907ull);
    vlSelf->__Vfunc_fp32_mul__2382__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 12825697076929113491ull);
    vlSelf->__Vfunc_fp32_mul__2382__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 6619364927224269480ull);
    vlSelf->__Vfunc_fp32_mul__2382__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 14803552427108456207ull);
    vlSelf->__Vfunc_fp32_mul__2382__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11539612469540225726ull);
    vlSelf->__Vfunc_fp32_mul__2382__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4396402887935630445ull);
    vlSelf->__Vfunc_fp32_mul__2382__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17574398987388197055ull);
    vlSelf->__Vfunc_fp32_mul__2382__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2672486982233795630ull);
    vlSelf->__Vfunc_fp32_mul__2382__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14933134398432623221ull);
    __Vfunc_fp32_mul__2382__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2383__bits 
                                = __Vfunc_fp32_mul__2382__lhs;
                            __Vfunc_fp32_is_nan__2383__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2383__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2383__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2383__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2383__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2383__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2383__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2384__bits 
                                = __Vfunc_fp32_mul__2382__rhs;
                            __Vfunc_fp32_is_nan__2384__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2384__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2384__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2384__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2384__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2384__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2384__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2385__bits 
                                    = __Vfunc_fp32_mul__2382__lhs;
                                __Vfunc_fp32_is_inf__2385__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2385__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2385__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2385__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2385__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2385__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2386__bits 
                                    = __Vfunc_fp32_mul__2382__rhs;
                                __Vfunc_fp32_is_zero__2386__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2386__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2386__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2386__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2386__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2386__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2387__bits 
                                    = __Vfunc_fp32_mul__2382__rhs;
                                __Vfunc_fp32_is_inf__2387__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2387__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2387__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2387__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2387__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2387__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2388__bits 
                                    = __Vfunc_fp32_mul__2382__lhs;
                                __Vfunc_fp32_is_zero__2388__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2388__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2388__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2388__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2388__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2388__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__Vfuncout = 0x7fc00000U;
            goto __Vlabel7;
        }
        vlSelfRef.__Vfunc_fp32_mul__2382__result_sign 
            = ((__Vfunc_fp32_mul__2382__lhs ^ __Vfunc_fp32_mul__2382__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2389__bits 
                            = __Vfunc_fp32_mul__2382__lhs;
                        __Vfunc_fp32_is_inf__2389__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2389__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2389__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2389__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2389__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2389__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2390__bits 
                            = __Vfunc_fp32_mul__2382__rhs;
                        __Vfunc_fp32_is_inf__2390__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2390__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2390__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2390__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2390__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2390__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2382__result_sign) 
                                  << 0x1fU));
            goto __Vlabel7;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2391__bits 
                            = __Vfunc_fp32_mul__2382__lhs;
                        __Vfunc_fp32_is_zero__2391__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2391__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2391__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2391__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2391__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2391__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2392__bits 
                            = __Vfunc_fp32_mul__2382__rhs;
                        __Vfunc_fp32_is_zero__2392__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2392__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2392__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2392__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2392__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2392__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2382__result_sign) 
                   << 0x1fU);
            goto __Vlabel7;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2382__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2382__lhs);
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2382__lhs));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2382__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2382__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2382__rhs);
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2382__rhs));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2382__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__2382__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__2382__normalize_count = 1U;
        __Vfunc_fp32_mul__2382__normalize_count = 2U;
        __Vfunc_fp32_mul__2382__normalize_count = 3U;
        __Vfunc_fp32_mul__2382__normalize_count = 4U;
        __Vfunc_fp32_mul__2382__normalize_count = 5U;
        __Vfunc_fp32_mul__2382__normalize_count = 6U;
        __Vfunc_fp32_mul__2382__normalize_count = 7U;
        __Vfunc_fp32_mul__2382__normalize_count = 8U;
        __Vfunc_fp32_mul__2382__normalize_count = 9U;
        __Vfunc_fp32_mul__2382__normalize_count = 0xaU;
        __Vfunc_fp32_mul__2382__normalize_count = 0xbU;
        __Vfunc_fp32_mul__2382__normalize_count = 0xcU;
        __Vfunc_fp32_mul__2382__normalize_count = 0xdU;
        __Vfunc_fp32_mul__2382__normalize_count = 0xeU;
        __Vfunc_fp32_mul__2382__normalize_count = 0xfU;
        __Vfunc_fp32_mul__2382__normalize_count = 0x10U;
        __Vfunc_fp32_mul__2382__normalize_count = 0x11U;
        __Vfunc_fp32_mul__2382__normalize_count = 0x12U;
        __Vfunc_fp32_mul__2382__normalize_count = 0x13U;
        __Vfunc_fp32_mul__2382__normalize_count = 0x14U;
        __Vfunc_fp32_mul__2382__normalize_count = 0x15U;
        __Vfunc_fp32_mul__2382__normalize_count = 0x16U;
        __Vfunc_fp32_mul__2382__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__2382__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2382__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2382__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__2382__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__2382__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__2382__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__2382__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__2382__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2382__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2382__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__2382__mantissa 
            = (0xffffffU & (IData)((0xffffffffffffULL 
                                    & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__2382__product, vlSelfRef.__Vfunc_fp32_mul__2382__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__2382__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__2382__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__2382__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__2382__product 
               & vlSelfRef.__Vfunc_fp32_mul__2382__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__2382__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__2382__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__2382__rounded = vlSelfRef.__Vfunc_fp32_mul__2382__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__2382__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__2382__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__2382__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__2382__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__2382__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__2382__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2382__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__2382__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__2382__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__2382__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__2382__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2382__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2382__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__2382__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__2382__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2382__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2382__result_sign) 
                                  << 0x1fU));
            goto __Vlabel7;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__2382__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2382__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2382__result_sign) 
                   << 0x1fU);
            goto __Vlabel7;
        }
        vlSelfRef.__Vfunc_fp32_mul__2382__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_mul__2382__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_mul__2382__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__2382__mantissa)));
        __Vlabel7: ;
    }
}
