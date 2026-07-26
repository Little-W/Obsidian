// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_engines.h for the primary calling header

#include "Vtb_npu_engines__pch.h"
#include "Vtb_npu_engines___024root.h"

VL_INLINE_OPT void Vtb_npu_engines___024root___nba_comb__TOP__0(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___nba_comb__TOP__0\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_6;
    // Body
    vlSelfRef.tb_npu_engines__DOT__l1_req_write = (
                                                   (((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_write) 
                                                     << 4U) 
                                                    | (((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_write) 
                                                        << 3U) 
                                                       | ((IData)(vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_write) 
                                                          << 2U))) 
                                                   | (((IData)(vlSelfRef.tb_npu_engines__DOT__dma_l1_req_write) 
                                                       << 1U) 
                                                      | (IData)(vlSelfRef.tb_npu_engines__DOT__bfm_req_write)));
    vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready = (
                                                   (((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_rsp_ready) 
                                                     << 4U) 
                                                    | (((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_rsp_ready) 
                                                        << 3U) 
                                                       | ((IData)(vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready) 
                                                          << 2U))) 
                                                   | (((IData)(vlSelfRef.tb_npu_engines__DOT__dma_l1_rsp_ready) 
                                                       << 1U) 
                                                      | (IData)(vlSelfRef.tb_npu_engines__DOT__bfm_rsp_ready)));
    vlSelfRef.tb_npu_engines__DOT__l1_req_valid = (
                                                   (((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_valid) 
                                                     << 4U) 
                                                    | (((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_valid) 
                                                        << 3U) 
                                                       | ((IData)(vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_valid) 
                                                          << 2U))) 
                                                   | (((IData)(vlSelfRef.tb_npu_engines__DOT__dma_l1_req_valid) 
                                                       << 1U) 
                                                      | (IData)(vlSelfRef.tb_npu_engines__DOT__bfm_req_valid)));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wstrb = (
                                                   ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_wstrb)) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     ((((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_wstrb) 
                                                                        << 0x18U) 
                                                                       | ((IData)(vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_wstrb) 
                                                                          << 0x10U)) 
                                                                      | (((IData)(vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wstrb) 
                                                                          << 8U) 
                                                                         | (IData)(vlSelfRef.tb_npu_engines__DOT__bfm_req_wstrb))))));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[0U] 
        = (IData)(vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata);
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[1U] 
        = (IData)((vlSelfRef.tb_npu_engines__DOT__bfm_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[2U] 
        = (IData)(vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wdata);
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[3U] 
        = (IData)((vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[4U] 
        = (IData)(vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_wdata);
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[5U] 
        = (IData)((vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[6U] 
        = (IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_wdata);
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[7U] 
        = (IData)((vlSelfRef.tb_npu_engines__DOT__vector_l1_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[8U] 
        = (IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_wdata);
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[9U] 
        = (IData)((vlSelfRef.tb_npu_engines__DOT__complex_l1_req_wdata 
                   >> 0x20U));
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[0xaU] = 0U;
    vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[0xbU] = 0U;
    vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 0U;
    vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client 
        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q;
    if ((((0U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q)) 
          & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid)) 
         & ((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)) 
            | (IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 0U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (1U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 1U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 1U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 1U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 1U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (2U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 2U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 2U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 2U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 2U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (3U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 3U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 3U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 3U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 3U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (4U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 4U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 4U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 4U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 4U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 5U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 5U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 5U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 5U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (0U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid)) 
         & ((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)) 
            | (IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 0U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (1U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 1U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 1U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 1U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 1U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (2U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 2U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 2U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 2U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 2U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (3U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 3U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 3U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 3U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 3U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (4U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 4U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 4U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 4U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 4U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found)) 
           & (5U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
             >> 5U)) & ((~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 5U)) | ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready) 
                                       >> 5U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client = 5U;
    }
    vlSelfRef.tb_npu_engines__DOT__l1_req_ready = 0U;
    if (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h08238727__0 = 1U;
        if ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))) {
            vlSelfRef.tb_npu_engines__DOT__l1_req_ready 
                = (((~ ((IData)(1U) << (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))) 
                    & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)) 
                   | (0x3fU & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h08238727__0) 
                               << (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))));
        }
    }
    __Vtemp_6[0U] = (IData)((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_addr)) 
                              << 0x28U) | (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__dma_l1_req_addr)) 
                                            << 0x14U) 
                                           | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__bfm_req_addr)))));
    __Vtemp_6[1U] = (((IData)((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr)) 
                                << 0x14U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr)))) 
                      << 0x1cU) | (IData)(((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_addr)) 
                                             << 0x28U) 
                                            | (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__dma_l1_req_addr)) 
                                                << 0x14U) 
                                               | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__bfm_req_addr)))) 
                                           >> 0x20U)));
    __Vtemp_6[2U] = (((IData)((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr)) 
                                << 0x14U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr)))) 
                      >> 4U) | ((IData)(((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr)) 
                                           << 0x14U) 
                                          | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr))) 
                                         >> 0x20U)) 
                                << 0x1cU));
    __Vtemp_6[3U] = ((IData)(((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__complex_l1_req_addr)) 
                                << 0x14U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr))) 
                              >> 0x20U)) >> 4U);
    vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
        = ((0x77U >= (0x7fU & ((IData)(0x14U) * (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))))
            ? (0xfffffU & (((0U == (0x1fU & ((IData)(0x14U) 
                                             * (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))))
                             ? 0U : (__Vtemp_6[(((IData)(0x13U) 
                                                 + 
                                                 (0x7fU 
                                                  & ((IData)(0x14U) 
                                                     * (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)))) 
                                                >> 5U)] 
                                     << ((IData)(0x20U) 
                                         - (0x1fU & 
                                            ((IData)(0x14U) 
                                             * (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)))))) 
                           | (__Vtemp_6[(3U & (((IData)(0x14U) 
                                                * (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)) 
                                               >> 5U))] 
                              >> (0x1fU & ((IData)(0x14U) 
                                           * (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))))))
            : 0U);
    vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_handshake 
        = ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found) 
           & ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)) 
              & (((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
                  >> (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)) 
                 & ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)) 
                    & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready) 
                       >> (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))))));
}

void Vtb_npu_engines___024root___timing_resume(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___timing_resume\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h358e9255__0.resume(
                                                   "@(posedge tb_npu_engines.clk_i)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h358e9218__0.resume(
                                                   "@(negedge tb_npu_engines.clk_i)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_npu_engines___024root___timing_commit(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___timing_commit\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h358e9255__0.commit(
                                                   "@(posedge tb_npu_engines.clk_i)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h358e9218__0.commit(
                                                   "@(negedge tb_npu_engines.clk_i)");
    }
}

void Vtb_npu_engines___024root___eval_triggers__act(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___eval_act(Vtb_npu_engines___024root* vlSelf);

bool Vtb_npu_engines___024root___eval_phase__act(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_phase__act\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_npu_engines___024root___eval_triggers__act(vlSelf);
    Vtb_npu_engines___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_npu_engines___024root___timing_resume(vlSelf);
        Vtb_npu_engines___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtb_npu_engines___024root___eval_nba(Vtb_npu_engines___024root* vlSelf);

bool Vtb_npu_engines___024root___eval_phase__nba(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_phase__nba\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_npu_engines___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_engines___024root___dump_triggers__nba(Vtb_npu_engines___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_engines___024root___dump_triggers__act(Vtb_npu_engines___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_npu_engines___024root___eval(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtb_npu_engines___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_npu_engines.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_npu_engines___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_npu_engines.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_npu_engines___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_npu_engines___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_npu_engines___024root___eval_debug_assertions(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_debug_assertions\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
