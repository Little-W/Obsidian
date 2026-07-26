// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core__Syms.h"
#include "Vtb_npu_single_core___024root.h"

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_comb__TOP__7(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_comb__TOP__7\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_current_error_w 
        = (((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wlast_i) 
            != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_last_expected_w)) 
           | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
              & (0xffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wstrb_i))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_ready = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_quiesce)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_ready 
            = ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)) 
               || (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)));
        if ((1U & (~ VL_ONEHOT_I((((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)) 
                                   << 1U) | (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q))))))) {
            if ((0U != (((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)) 
                         << 1U) | (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: npu_cmd_frontend.sv:134: Assertion failed in %Ntb_npu_single_core.dut.u_cmd_frontend: unique case, but multiple matches found for '3'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 3,(IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q));
                    VL_STOP_MT("control/npu_cmd_frontend.sv", 134, "");
                }
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd_ready 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__accept_new_cmd_o) 
           & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_quiesce)) 
              & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__free_found)));
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_complete_error_w 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q) 
           | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_current_error_w));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__input_handshake 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_ready) 
           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_valid));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd_ready) 
           & (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_commit_w 
        = ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wvalid_i) 
              & ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_complete_error_w)) 
                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_last_expected_w)))));
}
