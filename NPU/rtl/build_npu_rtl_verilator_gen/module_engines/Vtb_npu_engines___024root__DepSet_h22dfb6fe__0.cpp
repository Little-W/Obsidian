// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_engines.h for the primary calling header

#include "Vtb_npu_engines__pch.h"
#include "Vtb_npu_engines___024root.h"

VlCoroutine Vtb_npu_engines___024root___eval_initial__TOP__Vtiming__0(Vtb_npu_engines___024root* vlSelf);
VlCoroutine Vtb_npu_engines___024root___eval_initial__TOP__Vtiming__1(Vtb_npu_engines___024root* vlSelf);
VlCoroutine Vtb_npu_engines___024root___eval_initial__TOP__Vtiming__2(Vtb_npu_engines___024root* vlSelf);

void Vtb_npu_engines___024root___eval_initial(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_initial\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_npu_engines___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_npu_engines___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_npu_engines___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

void Vtb_npu_engines___024root___act_comb__TOP__0(Vtb_npu_engines___024root* vlSelf);

void Vtb_npu_engines___024root___eval_act(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_act\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((5ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb_npu_engines___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_npu_engines___024root___act_comb__TOP__0(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___act_comb__TOP__0\n"); );
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
    vlSelfRef.tb_npu_engines__DOT__l1_req_ready = 0U;
    if (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_found) {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h08238727__0 = 1U;
        if ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))) {
            vlSelfRef.tb_npu_engines__DOT__l1_req_ready 
                = (((~ ((IData)(1U) << (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))) 
                    & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready)) 
                   | (0x3fU & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h08238727__0) 
                               << (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))));
            vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_handshake 
                = (((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_valid) 
                    >> (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)) 
                   & ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)) 
                      & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready) 
                         >> (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))));
        } else {
            vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_handshake = 0U;
        }
    } else {
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_handshake = 0U;
    }
}

void Vtb_npu_engines___024root___nba_sequent__TOP__0(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___nba_sequent__TOP__1(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___nba_sequent__TOP__2(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___nba_sequent__TOP__3(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___nba_sequent__TOP__4(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___nba_sequent__TOP__5(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___nba_sequent__TOP__6(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___nba_sequent__TOP__7(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___nba_sequent__TOP__8(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___nba_sequent__TOP__9(Vtb_npu_engines___024root* vlSelf);
void Vtb_npu_engines___024root___nba_comb__TOP__0(Vtb_npu_engines___024root* vlSelf);

void Vtb_npu_engines___024root___eval_nba(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_nba\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_engines___024root___nba_sequent__TOP__0(vlSelf);
        Vtb_npu_engines___024root___nba_sequent__TOP__1(vlSelf);
        Vtb_npu_engines___024root___nba_sequent__TOP__2(vlSelf);
        Vtb_npu_engines___024root___nba_sequent__TOP__3(vlSelf);
        Vtb_npu_engines___024root___nba_sequent__TOP__4(vlSelf);
        Vtb_npu_engines___024root___nba_sequent__TOP__5(vlSelf);
        Vtb_npu_engines___024root___nba_sequent__TOP__6(vlSelf);
        Vtb_npu_engines___024root___nba_sequent__TOP__7(vlSelf);
        Vtb_npu_engines___024root___nba_sequent__TOP__8(vlSelf);
        Vtb_npu_engines___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_npu_engines___024root___nba_comb__TOP__0(vlSelf);
    }
}

extern const VlWide<64>/*2047:0*/ Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0;

VL_INLINE_OPT void Vtb_npu_engines___024root___nba_sequent__TOP__0(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___nba_sequent__TOP__0\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__197__fail_status;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__197__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__197__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__197__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__198__Vfuncout;
    __Vfunc_memory_status_to_task__198__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__198__status;
    __Vfunc_memory_status_to_task__198__status = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__199__fail_status;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__199__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__199__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__199__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__200__Vfuncout;
    __Vfunc_memory_status_to_task__200__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__200__status;
    __Vfunc_memory_status_to_task__200__status = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__value;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__value = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__multiplier;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__multiplier = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_value;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_value = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding = 0;
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product;
    VL_ZERO_W(128, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product);
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted;
    VL_ZERO_W(128, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted);
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product;
    VL_ZERO_W(128, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product);
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding_bias;
    VL_ZERO_W(128, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding_bias);
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount = 0;
    QData/*63:0*/ __Vfunc_dtype_min__202__Vfuncout;
    __Vfunc_dtype_min__202__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__202__dtype;
    __Vfunc_dtype_min__202__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__203__Vfuncout;
    __Vfunc_dtype_max__203__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__203__dtype;
    __Vfunc_dtype_max__203__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__204__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__204__fail_addr = 0;
    QData/*63:0*/ __Vfunc_wrap_to_dtype__205__Vfuncout;
    __Vfunc_wrap_to_dtype__205__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_wrap_to_dtype__205__value;
    __Vfunc_wrap_to_dtype__205__value = 0;
    CData/*1:0*/ __Vfunc_wrap_to_dtype__205__dtype;
    __Vfunc_wrap_to_dtype__205__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__206__Vfuncout;
    __Vfunc_clip_to_dtype__206__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__206__value;
    __Vfunc_clip_to_dtype__206__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__206__dtype;
    __Vfunc_clip_to_dtype__206__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__206__minimum;
    __Vfunc_clip_to_dtype__206__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__206__maximum;
    __Vfunc_clip_to_dtype__206__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__207__Vfuncout;
    __Vfunc_dtype_min__207__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__207__dtype;
    __Vfunc_dtype_min__207__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__208__Vfuncout;
    __Vfunc_dtype_max__208__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__208__dtype;
    __Vfunc_dtype_max__208__dtype = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__209__fail_status;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__209__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__209__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__209__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__210__Vfuncout;
    __Vfunc_memory_status_to_task__210__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__210__status;
    __Vfunc_memory_status_to_task__210__status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__211__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__211__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__212__fail_status;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__212__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__212__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__212__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__213__Vfuncout;
    __Vfunc_memory_status_to_task__213__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__213__status;
    __Vfunc_memory_status_to_task__213__status = 0;
    QData/*63:0*/ __Vfunc_load_element__214__Vfuncout;
    __Vfunc_load_element__214__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__214__beat;
    __Vfunc_load_element__214__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__214__byte_lane;
    __Vfunc_load_element__214__byte_lane = 0;
    IData/*31:0*/ __Vfunc_load_element__214__word_value;
    __Vfunc_load_element__214__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__215__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__215__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__215__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__215__byte_lane = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__216__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__216__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__217__fail_status;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__217__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__217__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__217__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__218__Vfuncout;
    __Vfunc_memory_status_to_task__218__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__218__status;
    __Vfunc_memory_status_to_task__218__status = 0;
    QData/*63:0*/ __Vfunc_load_element__219__Vfuncout;
    __Vfunc_load_element__219__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__219__beat;
    __Vfunc_load_element__219__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__219__byte_lane;
    __Vfunc_load_element__219__byte_lane = 0;
    IData/*31:0*/ __Vfunc_load_element__219__word_value;
    __Vfunc_load_element__219__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__220__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__220__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__220__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__220__byte_lane = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__221__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__221__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__222__fail_status;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__222__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__222__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__222__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__223__Vfuncout;
    __Vfunc_memory_status_to_task__223__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__223__status;
    __Vfunc_memory_status_to_task__223__status = 0;
    QData/*63:0*/ __Vfunc_load_element__224__Vfuncout;
    __Vfunc_load_element__224__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__224__beat;
    __Vfunc_load_element__224__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__224__byte_lane;
    __Vfunc_load_element__224__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__224__high_nibble;
    __Vfunc_load_element__224__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__224__dtype;
    __Vfunc_load_element__224__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__224__byte_value;
    __Vfunc_load_element__224__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__224__nibble_value;
    __Vfunc_load_element__224__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__224__half_value;
    __Vfunc_load_element__224__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__224__word_value;
    __Vfunc_load_element__224__word_value = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__225__fail_status;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__225__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__225__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__225__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__226__Vfuncout;
    __Vfunc_memory_status_to_task__226__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__226__status;
    __Vfunc_memory_status_to_task__226__status = 0;
    QData/*63:0*/ __Vfunc_load_element__227__Vfuncout;
    __Vfunc_load_element__227__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__227__beat;
    __Vfunc_load_element__227__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__227__byte_lane;
    __Vfunc_load_element__227__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__227__high_nibble;
    __Vfunc_load_element__227__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__227__dtype;
    __Vfunc_load_element__227__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__227__byte_value;
    __Vfunc_load_element__227__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__227__nibble_value;
    __Vfunc_load_element__227__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__227__half_value;
    __Vfunc_load_element__227__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__227__word_value;
    __Vfunc_load_element__227__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__dtype;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__229__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__229__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__dtype;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__231__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__231__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__dtype;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__233__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__233__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__opcode_known__234__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__opcode_known__234__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__opcode_known__234__opcode;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__opcode_known__234__opcode = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__size;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__size = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__tile;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__tile = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__size;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__size = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__tile;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__tile = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__size;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__size = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__tile;
    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__tile = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__273__fail_status;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__273__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__273__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__273__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__274__Vfuncout;
    __Vfunc_memory_status_to_task__274__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__274__status;
    __Vfunc_memory_status_to_task__274__status = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__275__fail_status;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__275__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__275__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__275__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__276__Vfuncout;
    __Vfunc_memory_status_to_task__276__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__276__status;
    __Vfunc_memory_status_to_task__276__status = 0;
    QData/*63:0*/ __Vfunc_dtype_min__277__Vfuncout;
    __Vfunc_dtype_min__277__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__277__dtype;
    __Vfunc_dtype_min__277__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__278__Vfuncout;
    __Vfunc_dtype_max__278__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__278__dtype;
    __Vfunc_dtype_max__278__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__279__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__279__fail_addr = 0;
    QData/*63:0*/ __Vfunc_wrap_to_dtype__280__Vfuncout;
    __Vfunc_wrap_to_dtype__280__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_wrap_to_dtype__280__value;
    __Vfunc_wrap_to_dtype__280__value = 0;
    CData/*1:0*/ __Vfunc_wrap_to_dtype__280__dtype;
    __Vfunc_wrap_to_dtype__280__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__281__Vfuncout;
    __Vfunc_clip_to_dtype__281__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__281__value;
    __Vfunc_clip_to_dtype__281__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__281__dtype;
    __Vfunc_clip_to_dtype__281__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__281__minimum;
    __Vfunc_clip_to_dtype__281__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__281__maximum;
    __Vfunc_clip_to_dtype__281__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__282__Vfuncout;
    __Vfunc_dtype_min__282__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__282__dtype;
    __Vfunc_dtype_min__282__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__283__Vfuncout;
    __Vfunc_dtype_max__283__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__283__dtype;
    __Vfunc_dtype_max__283__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__dtype;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__285__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__285__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__286__fail_status;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__286__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__286__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__286__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__287__Vfuncout;
    __Vfunc_memory_status_to_task__287__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__287__status;
    __Vfunc_memory_status_to_task__287__status = 0;
    QData/*63:0*/ __Vfunc_load_element__288__Vfuncout;
    __Vfunc_load_element__288__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__288__beat;
    __Vfunc_load_element__288__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__288__byte_lane;
    __Vfunc_load_element__288__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__288__high_nibble;
    __Vfunc_load_element__288__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__288__dtype;
    __Vfunc_load_element__288__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__288__byte_value;
    __Vfunc_load_element__288__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__288__nibble_value;
    __Vfunc_load_element__288__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__288__half_value;
    __Vfunc_load_element__288__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__288__word_value;
    __Vfunc_load_element__288__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__dtype;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__290__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__290__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__291__fail_status;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__291__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__291__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__291__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__292__Vfuncout;
    __Vfunc_memory_status_to_task__292__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__292__status;
    __Vfunc_memory_status_to_task__292__status = 0;
    QData/*63:0*/ __Vfunc_load_element__293__Vfuncout;
    __Vfunc_load_element__293__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__293__beat;
    __Vfunc_load_element__293__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__293__byte_lane;
    __Vfunc_load_element__293__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__293__high_nibble;
    __Vfunc_load_element__293__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__293__dtype;
    __Vfunc_load_element__293__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__293__byte_value;
    __Vfunc_load_element__293__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__293__nibble_value;
    __Vfunc_load_element__293__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__293__half_value;
    __Vfunc_load_element__293__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__293__word_value;
    __Vfunc_load_element__293__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__dtype;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__295__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__295__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__296__fail_status;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__296__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__296__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__296__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__297__Vfuncout;
    __Vfunc_memory_status_to_task__297__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__297__status;
    __Vfunc_memory_status_to_task__297__status = 0;
    QData/*63:0*/ __Vfunc_load_element__298__Vfuncout;
    __Vfunc_load_element__298__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__298__beat;
    __Vfunc_load_element__298__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__298__byte_lane;
    __Vfunc_load_element__298__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__298__high_nibble;
    __Vfunc_load_element__298__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__298__dtype;
    __Vfunc_load_element__298__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__298__byte_value;
    __Vfunc_load_element__298__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__298__nibble_value;
    __Vfunc_load_element__298__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__298__half_value;
    __Vfunc_load_element__298__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__298__word_value;
    __Vfunc_load_element__298__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__299__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__299__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__299__opcode;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__299__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__dtype;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__301__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__301__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__302__fail_status;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__302__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__302__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__302__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__303__Vfuncout;
    __Vfunc_memory_status_to_task__303__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__303__status;
    __Vfunc_memory_status_to_task__303__status = 0;
    QData/*63:0*/ __Vfunc_load_element__304__Vfuncout;
    __Vfunc_load_element__304__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__304__beat;
    __Vfunc_load_element__304__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__304__byte_lane;
    __Vfunc_load_element__304__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__304__high_nibble;
    __Vfunc_load_element__304__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__304__dtype;
    __Vfunc_load_element__304__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__304__byte_value;
    __Vfunc_load_element__304__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__304__nibble_value;
    __Vfunc_load_element__304__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__304__half_value;
    __Vfunc_load_element__304__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__304__word_value;
    __Vfunc_load_element__304__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__opcode;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__306__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__306__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__306__opcode;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__306__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__dtype;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__308__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__308__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__309__fail_status;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__309__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__309__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__309__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__310__Vfuncout;
    __Vfunc_memory_status_to_task__310__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__310__status;
    __Vfunc_memory_status_to_task__310__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_known__311__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_known__311__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_known__311__opcode;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_known__311__opcode = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__321__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__321__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__opcode;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__323__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__323__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__323__opcode;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__323__opcode = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<4>/*127:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<4>/*127:0*/ __Vtemp_6;
    VlWide<4>/*127:0*/ __Vtemp_7;
    VlWide<4>/*127:0*/ __Vtemp_8;
    VlWide<4>/*127:0*/ __Vtemp_9;
    VlWide<4>/*127:0*/ __Vtemp_10;
    VlWide<4>/*127:0*/ __Vtemp_11;
    VlWide<4>/*127:0*/ __Vtemp_13;
    VlWide<4>/*127:0*/ __Vtemp_14;
    VlWide<4>/*127:0*/ __Vtemp_15;
    VlWide<4>/*127:0*/ __Vtemp_16;
    VlWide<4>/*127:0*/ __Vtemp_17;
    VlWide<4>/*127:0*/ __Vtemp_18;
    VlWide<4>/*127:0*/ __Vtemp_19;
    VlWide<4>/*127:0*/ __Vtemp_20;
    VlWide<4>/*127:0*/ __Vtemp_21;
    VlWide<4>/*127:0*/ __Vtemp_22;
    VlWide<4>/*127:0*/ __Vtemp_23;
    VlWide<4>/*127:0*/ __Vtemp_24;
    VlWide<4>/*127:0*/ __Vtemp_25;
    VlWide<4>/*127:0*/ __Vtemp_26;
    VlWide<4>/*127:0*/ __Vtemp_27;
    VlWide<4>/*127:0*/ __Vtemp_28;
    VlWide<4>/*127:0*/ __Vtemp_29;
    // Body
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v0 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v1 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v2 = 0U;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q 
        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v0 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v1 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v2 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v3 = 0U;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__system_mem_pending_q 
        = vlSelfRef.tb_npu_engines__DOT__system_mem_pending_q;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v0 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v1 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v2 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v3 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v4 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v5 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v6 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__system_mem__v7 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v0 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v1 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v2 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v3 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v4 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v5 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v6 = 0U;
    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v7 = 0U;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__mask_value_q 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_value_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__accum_q 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__progress_q 
        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__progress_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q 
        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__linear_index_q 
        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_sum_q 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_sum_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_max_q 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_max_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_sumsq_q 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_sumsq_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__col_q 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__phase_q 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q;
    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__row_q 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q;
    if (vlSelfRef.tb_npu_engines__DOT__reset_n) {
        if ((1U & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                   & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready)))) {
            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q 
                = (0x3eU & (IData)(vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q));
        }
        if ((2U & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                   & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready)))) {
            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q 
                = (0x3dU & (IData)(vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q));
        }
        if ((4U & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                   & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready)))) {
            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q 
                = (0x3bU & (IData)(vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q));
        }
        if ((8U & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                   & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready)))) {
            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q 
                = (0x37U & (IData)(vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q));
        }
        if ((0x10U & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                      & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready)))) {
            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q 
                = (0x2fU & (IData)(vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q));
        }
        if ((0x20U & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                      & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_rsp_ready)))) {
            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q 
                = (0x1fU & (IData)(vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q));
        }
        if (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_handshake) {
            vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h78273bf2__0 = 0ULL;
            if ((0U == (7U & vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr))) {
                if ((0xffff8U >= vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr)) {
                    if ((1U & (~ ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)) 
                                  && (1U & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_write) 
                                            >> (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))))))) {
                        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h78273bf2__1 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__sram_q
                            [(0xfU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                      >> 3U))][(0x1fffU 
                                                & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                                   >> 7U))];
                        if ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))) {
                            vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v1 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h78273bf2__1;
                            vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v1 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client;
                            vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v1 = 1U;
                        }
                    }
                    if (((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client)) 
                         && (1U & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_write) 
                                   >> (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))))) {
                        if (((0x2fU >= (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_engines__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U))))))) {
                            vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v0 
                                = ((0x17fU >= (0x1ffU 
                                               & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))) 
                                                | (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))))
                                    : 0U);
                            vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v0 
                                = (0x1fffU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                              >> 7U));
                            vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v0 
                                = (0xfU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                           >> 3U));
                            vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v0 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(1U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_engines__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(1U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))))))) {
                            vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v1 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(8U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(8U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(8U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(8U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(8U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(8U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))))
                                    : 0U);
                            vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v1 
                                = (0x1fffU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                              >> 7U));
                            vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v1 
                                = (0xfU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                           >> 3U));
                            vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v1 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(2U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_engines__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(2U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))))))) {
                            vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v2 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(0x10U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x10U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x10U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x10U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(0x10U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x10U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))))
                                    : 0U);
                            vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v2 
                                = (0x1fffU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                              >> 7U));
                            vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v2 
                                = (0xfU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                           >> 3U));
                            vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v2 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(3U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_engines__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(3U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))))))) {
                            vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v3 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(0x18U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x18U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x18U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x18U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(0x18U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x18U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))))
                                    : 0U);
                            vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v3 
                                = (0x1fffU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                              >> 7U));
                            vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v3 
                                = (0xfU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                           >> 3U));
                            vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v3 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(4U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_engines__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(4U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))))))) {
                            vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v4 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(0x20U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x20U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x20U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x20U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(0x20U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x20U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))))
                                    : 0U);
                            vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v4 
                                = (0x1fffU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                              >> 7U));
                            vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v4 
                                = (0xfU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                           >> 3U));
                            vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v4 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(5U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_engines__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(5U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))))))) {
                            vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v5 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(0x28U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x28U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x28U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(0x28U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))))
                                    : 0U);
                            vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v5 
                                = (0x1fffU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                              >> 7U));
                            vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v5 
                                = (0xfU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                           >> 3U));
                            vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v5 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(6U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_engines__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(6U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))))))) {
                            vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v6 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(0x30U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x30U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x30U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x30U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(0x30U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x30U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))))
                                    : 0U);
                            vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v6 
                                = (0x1fffU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                              >> 7U));
                            vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v6 
                                = (0xfU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                           >> 3U));
                            vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v6 = 1U;
                        }
                        if (((0x2fU >= (0x3fU & ((IData)(7U) 
                                                 + 
                                                 VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))) 
                             && (1U & (IData)((vlSelfRef.tb_npu_engines__DOT__l1_req_wstrb 
                                               >> (0x3fU 
                                                   & ((IData)(7U) 
                                                      + 
                                                      VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 3U)))))))) {
                            vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__sram_q__v7 
                                = ((0x17fU >= (0x1ffU 
                                               & ((IData)(0x38U) 
                                                  + 
                                                  VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                    ? (0xffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x38U) 
                                                      + 
                                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x1ffU 
                                                     & ((IData)(0x38U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x38U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)))))) 
                                                | (vlSelfRef.tb_npu_engines__DOT__l1_req_wdata[
                                                   (0xfU 
                                                    & (((IData)(0x38U) 
                                                        + 
                                                        VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U)) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x38U) 
                                                       + 
                                                       VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client), 6U))))))
                                    : 0U);
                            vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__sram_q__v7 
                                = (0x1fffU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                              >> 7U));
                            vlSelfRef.__VdlyDim1__tb_npu_engines__DOT__u_l1__DOT__sram_q__v7 
                                = (0xfU & (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr 
                                           >> 3U));
                            vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__sram_q__v7 = 1U;
                        }
                    }
                }
            }
            vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h244b9fb6__0 = 1U;
            if ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))) {
                vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v0 
                    = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h78273bf2__0;
                vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v0 
                    = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client;
                vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v0 = 1U;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q 
                    = (((~ ((IData)(1U) << (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))) 
                        & (IData)(vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q)) 
                       | (0x3fU & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h244b9fb6__0) 
                                   << (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))));
            }
            if ((0U != (7U & vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr))) {
                vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h605c7b22__0 = 3U;
                if ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))) {
                    vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v0 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h605c7b22__0;
                    vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v0 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client;
                    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v0 = 1U;
                }
            } else if ((0xffff8U < vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_addr)) {
                vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h605c7b22__1 = 4U;
                if ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))) {
                    vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v1 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h605c7b22__1;
                    vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v1 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client;
                    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v1 = 1U;
                }
            } else {
                vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h605c7b22__2 = 0U;
                if ((5U >= (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))) {
                    vlSelfRef.__VdlyVal__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v2 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT____Vlvbound_h605c7b22__2;
                    vlSelfRef.__VdlyDim0__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v2 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client;
                    vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v2 = 1U;
                }
            }
            vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q 
                = ((5U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))
                    ? 0U : (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__grant_client))));
        }
    } else {
        vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_data_q__v2 = 1U;
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q = 0U;
        vlSelfRef.__VdlySet__tb_npu_engines__DOT__u_l1__DOT__rsp_status_q__v3 = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rr_client_q = 0U;
    }
    if (vlSelfRef.tb_npu_engines__DOT__reset_n) {
        if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0U;
            } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0U;
            } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0U;
            } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0U;
            } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                     [3U])) {
                    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__273__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr);
                    __Vfunc_memory_status_to_task__274__status 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                        [3U];
                    __Vfunc_memory_status_to_task__274__Vfuncout 
                        = ((0U == (IData)(__Vfunc_memory_status_to_task__274__status))
                            ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__274__status))
                                     ? 6U : ((2U == (IData)(__Vfunc_memory_status_to_task__274__status))
                                              ? 5U : 4U)));
                    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__273__fail_status 
                        = __Vfunc_memory_status_to_task__274__Vfuncout;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__273__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q 
                        = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__273__fail_status;
                } else {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__progress_q 
                        = (1ULL + vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__progress_q);
                    if ((((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q) 
                         < ((((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__row_q) 
                             == vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rows)
                             ? vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__valid_length
                             : vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__length))) {
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q 
                            = ((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q);
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__mask_value_q = 1U;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q 
                            = ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_enable)
                                ? 2U : 4U);
                    } else if ((((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__row_q) 
                                < vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rows)) {
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__row_q 
                            = ((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__row_q);
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q = 0U;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__mask_value_q = 1U;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q 
                            = ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_enable)
                                ? 2U : 4U);
                    } else {
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 0U;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                    }
                }
            }
        } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                        if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x10U;
                        }
                    } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                             [3U])) {
                            __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__275__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr);
                            __Vfunc_memory_status_to_task__276__status 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                                [3U];
                            __Vfunc_memory_status_to_task__276__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__276__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__276__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__276__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__275__fail_status 
                                = __Vfunc_memory_status_to_task__276__Vfuncout;
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__275__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q 
                                = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__275__fail_status;
                        } else {
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rmw_beat_q 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                [3U];
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0xfU;
                        }
                    }
                } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                    if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0xeU;
                    }
                } else {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result = 0ULL;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__compare_result = 0U;
                    if (((((((((0x60U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q)) 
                               | (0x61U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) 
                              | (0x62U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) 
                             | (0x63U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) 
                            | (0x64U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) 
                           | (0x65U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) 
                          | (0x66U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) 
                         | (0x67U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q)))) {
                        if ((0x60U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result 
                                = (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q 
                                   + vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q);
                        } else if ((0x61U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result 
                                = (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q 
                                   - vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q);
                        } else if ((0x62U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result 
                                = VL_MULS_QQQ(64, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q);
                        } else if ((0x63U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result 
                                = (VL_MULS_QQQ(64, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q) 
                                   + vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_value_q);
                        } else if ((0x64U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result 
                                = (VL_GTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q)
                                    ? vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q
                                    : vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q);
                        } else if ((0x65U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result 
                                = (VL_LTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q)
                                    ? vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q
                                    : vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q);
                        } else if ((0x66U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) {
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__compare_result 
                                = ((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__compare_mode))
                                    ? (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q 
                                       == vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q)
                                    : ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__compare_mode))
                                        ? (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q 
                                           != vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q)
                                        : ((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__compare_mode))
                                            ? VL_LTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q)
                                            : ((3U 
                                                == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__compare_mode))
                                                ? VL_LTES_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q)
                                                : (
                                                   (4U 
                                                    == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__compare_mode))
                                                    ? 
                                                   VL_GTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q)
                                                    : 
                                                   VL_GTES_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q))))));
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result 
                                = ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__compare_result)
                                    ? 1ULL : 0ULL);
                        } else {
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result 
                                = ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_value_q)
                                    ? vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q
                                    : vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q);
                        }
                    } else {
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result 
                            = ((0x68U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))
                                ? (VL_LTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q, 
                                              (((QData)((IData)(
                                                                (- (IData)(
                                                                           (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar0 
                                                                            >> 0x1fU))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar0))))
                                    ? (((QData)((IData)(
                                                        (- (IData)(
                                                                   (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar0 
                                                                    >> 0x1fU))))) 
                                        << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar0)))
                                    : (VL_GTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q, 
                                                  (((QData)((IData)(
                                                                    (- (IData)(
                                                                               (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar1 
                                                                                >> 0x1fU))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar1))))
                                        ? (((QData)((IData)(
                                                            (- (IData)(
                                                                       (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar1 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar1)))
                                        : vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q))
                                : (VL_GTS_IQQ(64, 0ULL, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q)
                                    ? 0ULL : vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q));
                    }
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__overflow 
                        = (VL_LTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result, 
                                      ([&]() {
                                    __Vfunc_dtype_min__277__dtype 
                                        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype;
                                    __Vfunc_dtype_min__277__Vfuncout 
                                        = ((2U & (IData)(__Vfunc_dtype_min__277__dtype))
                                            ? ((1U 
                                                & (IData)(__Vfunc_dtype_min__277__dtype))
                                                ? 0xffffffffffff8000ULL
                                                : 0xffffffff80000000ULL)
                                            : ((1U 
                                                & (IData)(__Vfunc_dtype_min__277__dtype))
                                                ? 0xffffffffffffff80ULL
                                                : 0xfffffffffffffff8ULL));
                                }(), __Vfunc_dtype_min__277__Vfuncout)) 
                           | VL_GTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result, 
                                        ([&]() {
                                    __Vfunc_dtype_max__278__dtype 
                                        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype;
                                    __Vfunc_dtype_max__278__Vfuncout 
                                        = ((2U & (IData)(__Vfunc_dtype_max__278__dtype))
                                            ? ((1U 
                                                & (IData)(__Vfunc_dtype_max__278__dtype))
                                                ? 0x7fffULL
                                                : 0x7fffffffULL)
                                            : ((1U 
                                                & (IData)(__Vfunc_dtype_max__278__dtype))
                                                ? 0x7fULL
                                                : 7ULL));
                                }(), __Vfunc_dtype_max__278__Vfuncout)));
                    if (((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__overflow) 
                         & (1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__overflow_mode)))) {
                        __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__279__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr);
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 0xcU;
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__279__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                    } else {
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__result_q 
                            = ((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__overflow_mode))
                                ? ([&]() {
                                    __Vfunc_wrap_to_dtype__280__dtype 
                                        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype;
                                    __Vfunc_wrap_to_dtype__280__value 
                                        = (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result);
                                    __Vfunc_wrap_to_dtype__280__Vfuncout 
                                        = ((2U & (IData)(__Vfunc_wrap_to_dtype__280__dtype))
                                            ? ((1U 
                                                & (IData)(__Vfunc_wrap_to_dtype__280__dtype))
                                                ? (
                                                   ((- (QData)((IData)(
                                                                       (1U 
                                                                        & (__Vfunc_wrap_to_dtype__280__value 
                                                                           >> 0xfU))))) 
                                                    << 0x10U) 
                                                   | (QData)((IData)(
                                                                     (0xffffU 
                                                                      & __Vfunc_wrap_to_dtype__280__value))))
                                                : (
                                                   ((QData)((IData)(
                                                                    (- (IData)(
                                                                               (__Vfunc_wrap_to_dtype__280__value 
                                                                                >> 0x1fU))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(__Vfunc_wrap_to_dtype__280__value))))
                                            : ((1U 
                                                & (IData)(__Vfunc_wrap_to_dtype__280__dtype))
                                                ? (
                                                   ((- (QData)((IData)(
                                                                       (1U 
                                                                        & (__Vfunc_wrap_to_dtype__280__value 
                                                                           >> 7U))))) 
                                                    << 8U) 
                                                   | (QData)((IData)(
                                                                     (0xffU 
                                                                      & __Vfunc_wrap_to_dtype__280__value))))
                                                : (
                                                   ((- (QData)((IData)(
                                                                       (1U 
                                                                        & (__Vfunc_wrap_to_dtype__280__value 
                                                                           >> 3U))))) 
                                                    << 4U) 
                                                   | (QData)((IData)(
                                                                     (0xfU 
                                                                      & __Vfunc_wrap_to_dtype__280__value))))));
                                }(), __Vfunc_wrap_to_dtype__280__Vfuncout)
                                : ([&]() {
                                    __Vfunc_clip_to_dtype__281__dtype 
                                        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype;
                                    __Vfunc_clip_to_dtype__281__value 
                                        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__unnamedblk1__DOT__arithmetic_result;
                                    __Vfunc_clip_to_dtype__281__minimum = 0;
                                    __Vfunc_clip_to_dtype__281__maximum = 0;
                                    {
                                        __Vfunc_dtype_min__282__dtype 
                                            = __Vfunc_clip_to_dtype__281__dtype;
                                        __Vfunc_dtype_min__282__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_dtype_min__282__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_min__282__dtype))
                                                    ? 0xffffffffffff8000ULL
                                                    : 0xffffffff80000000ULL)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_min__282__dtype))
                                                    ? 0xffffffffffffff80ULL
                                                    : 0xfffffffffffffff8ULL));
                                        __Vfunc_clip_to_dtype__281__minimum 
                                            = __Vfunc_dtype_min__282__Vfuncout;
                                        __Vfunc_dtype_max__283__dtype 
                                            = __Vfunc_clip_to_dtype__281__dtype;
                                        __Vfunc_dtype_max__283__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_dtype_max__283__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_max__283__dtype))
                                                    ? 0x7fffULL
                                                    : 0x7fffffffULL)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_max__283__dtype))
                                                    ? 0x7fULL
                                                    : 7ULL));
                                        __Vfunc_clip_to_dtype__281__maximum 
                                            = __Vfunc_dtype_max__283__Vfuncout;
                                        if (VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__281__value, __Vfunc_clip_to_dtype__281__minimum)) {
                                            __Vfunc_clip_to_dtype__281__Vfuncout 
                                                = __Vfunc_clip_to_dtype__281__minimum;
                                            goto __Vlabel0;
                                        }
                                        if (VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__281__value, __Vfunc_clip_to_dtype__281__maximum)) {
                                            __Vfunc_clip_to_dtype__281__Vfuncout 
                                                = __Vfunc_clip_to_dtype__281__maximum;
                                            goto __Vlabel0;
                                        }
                                        __Vfunc_clip_to_dtype__281__Vfuncout 
                                            = __Vfunc_clip_to_dtype__281__value;
                                        __Vlabel0: ;
                                    }
                                }(), __Vfunc_clip_to_dtype__281__Vfuncout));
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rmw_beat_q = 0ULL;
                        if (([&]() {
                                    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__dtype 
                                        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype;
                                    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__byte_lane 
                                        = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr));
                                    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__Vfuncout 
                                        = (((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__dtype)) 
                                            & (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__byte_lane))) 
                                           | ((3U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__dtype)) 
                                              & (6U 
                                                 < (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__byte_lane))));
                                }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__284__Vfuncout))) {
                            __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__285__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr);
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 4U;
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__285__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                        } else {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q 
                                = (((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype)) 
                                    & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_high_nibble))
                                    ? 0xdU : 0xfU);
                        }
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                    if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                             [3U])) {
                            __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__286__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr);
                            __Vfunc_memory_status_to_task__287__status 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                                [3U];
                            __Vfunc_memory_status_to_task__287__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__287__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__287__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__287__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__286__fail_status 
                                = __Vfunc_memory_status_to_task__287__Vfuncout;
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q 
                                = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__286__fail_status;
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__286__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                        } else {
                            __Vfunc_load_element__288__dtype 
                                = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype;
                            __Vfunc_load_element__288__high_nibble 
                                = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_high_nibble;
                            __Vfunc_load_element__288__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr));
                            __Vfunc_load_element__288__beat 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                [3U];
                            __Vfunc_load_element__288__byte_value 
                                = (0xffU & (IData)(
                                                   (__Vfunc_load_element__288__beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__288__byte_lane), 3U)))));
                            __Vfunc_load_element__288__nibble_value 
                                = (0xfU & ((IData)(__Vfunc_load_element__288__high_nibble)
                                            ? ((IData)(__Vfunc_load_element__288__byte_value) 
                                               >> 4U)
                                            : (IData)(__Vfunc_load_element__288__byte_value)));
                            __Vfunc_load_element__288__half_value 
                                = (0xffffU & (IData)(
                                                     (__Vfunc_load_element__288__beat 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__288__byte_lane), 3U)))));
                            __Vfunc_load_element__288__word_value 
                                = (IData)((__Vfunc_load_element__288__beat 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__288__byte_lane), 3U))));
                            __Vfunc_load_element__288__Vfuncout 
                                = ((2U & (IData)(__Vfunc_load_element__288__dtype))
                                    ? ((1U & (IData)(__Vfunc_load_element__288__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__288__half_value) 
                                                                   >> 0xfU))))) 
                                            << 0x10U) 
                                           | (QData)((IData)(__Vfunc_load_element__288__half_value)))
                                        : (((QData)((IData)(
                                                            (- (IData)(
                                                                       (__Vfunc_load_element__288__word_value 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(__Vfunc_load_element__288__word_value))))
                                    : ((1U & (IData)(__Vfunc_load_element__288__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__288__byte_value) 
                                                                   >> 7U))))) 
                                            << 8U) 
                                           | (QData)((IData)(__Vfunc_load_element__288__byte_value)))
                                        : (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__288__nibble_value) 
                                                                   >> 3U))))) 
                                            << 4U) 
                                           | (QData)((IData)(__Vfunc_load_element__288__nibble_value)))));
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__result_q 
                                = __Vfunc_load_element__288__Vfuncout;
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rmw_beat_q 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                [3U];
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0xfU;
                        }
                    }
                } else if (([&]() {
                            __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__dtype 
                                = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype;
                            __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr));
                            __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__Vfuncout 
                                = (((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__dtype)) 
                                    & (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__byte_lane))) 
                                   | ((3U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__dtype)) 
                                      & (6U < (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__byte_lane))));
                        }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__289__Vfuncout))) {
                    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__290__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr);
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__290__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0xbU;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                         [3U])) {
                        __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__291__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_addr);
                        __Vfunc_memory_status_to_task__292__status 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                            [3U];
                        __Vfunc_memory_status_to_task__292__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__292__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__292__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__292__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__291__fail_status 
                            = __Vfunc_memory_status_to_task__292__Vfuncout;
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q 
                            = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__291__fail_status;
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__291__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                    } else {
                        __Vfunc_load_element__293__dtype 
                            = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_dtype;
                        __Vfunc_load_element__293__high_nibble 
                            = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_high_nibble;
                        __Vfunc_load_element__293__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_addr));
                        __Vfunc_load_element__293__beat 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                            [3U];
                        __Vfunc_load_element__293__byte_value 
                            = (0xffU & (IData)((__Vfunc_load_element__293__beat 
                                                >> 
                                                (0x3fU 
                                                 & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__293__byte_lane), 3U)))));
                        __Vfunc_load_element__293__nibble_value 
                            = (0xfU & ((IData)(__Vfunc_load_element__293__high_nibble)
                                        ? ((IData)(__Vfunc_load_element__293__byte_value) 
                                           >> 4U) : (IData)(__Vfunc_load_element__293__byte_value)));
                        __Vfunc_load_element__293__half_value 
                            = (0xffffU & (IData)((__Vfunc_load_element__293__beat 
                                                  >> 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__293__byte_lane), 3U)))));
                        __Vfunc_load_element__293__word_value 
                            = (IData)((__Vfunc_load_element__293__beat 
                                       >> (0x3fU & 
                                           VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__293__byte_lane), 3U))));
                        __Vfunc_load_element__293__Vfuncout 
                            = ((2U & (IData)(__Vfunc_load_element__293__dtype))
                                ? ((1U & (IData)(__Vfunc_load_element__293__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__293__half_value) 
                                                               >> 0xfU))))) 
                                        << 0x10U) | (QData)((IData)(__Vfunc_load_element__293__half_value)))
                                    : (((QData)((IData)(
                                                        (- (IData)(
                                                                   (__Vfunc_load_element__293__word_value 
                                                                    >> 0x1fU))))) 
                                        << 0x20U) | (QData)((IData)(__Vfunc_load_element__293__word_value))))
                                : ((1U & (IData)(__Vfunc_load_element__293__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__293__byte_value) 
                                                               >> 7U))))) 
                                        << 8U) | (QData)((IData)(__Vfunc_load_element__293__byte_value)))
                                    : (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__293__nibble_value) 
                                                               >> 3U))))) 
                                        << 4U) | (QData)((IData)(__Vfunc_load_element__293__nibble_value)))));
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_value_q 
                            = __Vfunc_load_element__293__Vfuncout;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0xcU;
                    }
                }
            } else if (([&]() {
                        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__dtype 
                            = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_dtype;
                        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_addr));
                        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__Vfuncout 
                            = (((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__dtype)) 
                                & (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__byte_lane))) 
                               | ((3U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__dtype)) 
                                  & (6U < (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__byte_lane))));
                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__294__Vfuncout))) {
                __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__295__fail_addr 
                    = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_addr);
                vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 4U;
                vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                    = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__295__fail_addr;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
            } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 9U;
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                    if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                             [3U])) {
                            __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__296__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_addr);
                            __Vfunc_memory_status_to_task__297__status 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                                [3U];
                            __Vfunc_memory_status_to_task__297__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__297__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__297__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__297__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__296__fail_status 
                                = __Vfunc_memory_status_to_task__297__Vfuncout;
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q 
                                = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__296__fail_status;
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__296__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                        } else {
                            __Vfunc_load_element__298__dtype 
                                = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_dtype;
                            __Vfunc_load_element__298__high_nibble 
                                = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_high_nibble;
                            __Vfunc_load_element__298__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_addr));
                            __Vfunc_load_element__298__beat 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                [3U];
                            __Vfunc_load_element__298__byte_value 
                                = (0xffU & (IData)(
                                                   (__Vfunc_load_element__298__beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__298__byte_lane), 3U)))));
                            __Vfunc_load_element__298__nibble_value 
                                = (0xfU & ((IData)(__Vfunc_load_element__298__high_nibble)
                                            ? ((IData)(__Vfunc_load_element__298__byte_value) 
                                               >> 4U)
                                            : (IData)(__Vfunc_load_element__298__byte_value)));
                            __Vfunc_load_element__298__half_value 
                                = (0xffffU & (IData)(
                                                     (__Vfunc_load_element__298__beat 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__298__byte_lane), 3U)))));
                            __Vfunc_load_element__298__word_value 
                                = (IData)((__Vfunc_load_element__298__beat 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__298__byte_lane), 3U))));
                            __Vfunc_load_element__298__Vfuncout 
                                = ((2U & (IData)(__Vfunc_load_element__298__dtype))
                                    ? ((1U & (IData)(__Vfunc_load_element__298__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__298__half_value) 
                                                                   >> 0xfU))))) 
                                            << 0x10U) 
                                           | (QData)((IData)(__Vfunc_load_element__298__half_value)))
                                        : (((QData)((IData)(
                                                            (- (IData)(
                                                                       (__Vfunc_load_element__298__word_value 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(__Vfunc_load_element__298__word_value))))
                                    : ((1U & (IData)(__Vfunc_load_element__298__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__298__byte_value) 
                                                                   >> 7U))))) 
                                            << 8U) 
                                           | (QData)((IData)(__Vfunc_load_element__298__byte_value)))
                                        : (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__298__nibble_value) 
                                                                   >> 3U))))) 
                                            << 4U) 
                                           | (QData)((IData)(__Vfunc_load_element__298__nibble_value)))));
                            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q 
                                = __Vfunc_load_element__298__Vfuncout;
                            if (([&]() {
                                        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__299__opcode 
                                            = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q;
                                        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__299__Vfuncout 
                                            = (0x63U 
                                               == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__299__opcode));
                                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__299__Vfuncout))) {
                                if (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_from_scalar1) {
                                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_value_q 
                                        = (((QData)((IData)(
                                                            (- (IData)(
                                                                       (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar1 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar1)));
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0xcU;
                                } else {
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 8U;
                                }
                            } else {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0xcU;
                            }
                        }
                    }
                } else if (([&]() {
                            __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__dtype 
                                = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_dtype;
                            __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_addr));
                            __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__Vfuncout 
                                = (((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__dtype)) 
                                    & (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__byte_lane))) 
                                   | ((3U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__dtype)) 
                                      & (6U < (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__byte_lane))));
                        }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__300__Vfuncout))) {
                    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__301__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_addr);
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__301__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                         [3U])) {
                        __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__302__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_addr);
                        __Vfunc_memory_status_to_task__303__status 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                            [3U];
                        __Vfunc_memory_status_to_task__303__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__303__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__303__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__303__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__302__fail_status 
                            = __Vfunc_memory_status_to_task__303__Vfuncout;
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q 
                            = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__302__fail_status;
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__302__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                    } else {
                        __Vfunc_load_element__304__dtype 
                            = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_dtype;
                        __Vfunc_load_element__304__high_nibble 
                            = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_high_nibble;
                        __Vfunc_load_element__304__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_addr));
                        __Vfunc_load_element__304__beat 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                            [3U];
                        __Vfunc_load_element__304__byte_value 
                            = (0xffU & (IData)((__Vfunc_load_element__304__beat 
                                                >> 
                                                (0x3fU 
                                                 & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__304__byte_lane), 3U)))));
                        __Vfunc_load_element__304__nibble_value 
                            = (0xfU & ((IData)(__Vfunc_load_element__304__high_nibble)
                                        ? ((IData)(__Vfunc_load_element__304__byte_value) 
                                           >> 4U) : (IData)(__Vfunc_load_element__304__byte_value)));
                        __Vfunc_load_element__304__half_value 
                            = (0xffffU & (IData)((__Vfunc_load_element__304__beat 
                                                  >> 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__304__byte_lane), 3U)))));
                        __Vfunc_load_element__304__word_value 
                            = (IData)((__Vfunc_load_element__304__beat 
                                       >> (0x3fU & 
                                           VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__304__byte_lane), 3U))));
                        __Vfunc_load_element__304__Vfuncout 
                            = ((2U & (IData)(__Vfunc_load_element__304__dtype))
                                ? ((1U & (IData)(__Vfunc_load_element__304__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__304__half_value) 
                                                               >> 0xfU))))) 
                                        << 0x10U) | (QData)((IData)(__Vfunc_load_element__304__half_value)))
                                    : (((QData)((IData)(
                                                        (- (IData)(
                                                                   (__Vfunc_load_element__304__word_value 
                                                                    >> 0x1fU))))) 
                                        << 0x20U) | (QData)((IData)(__Vfunc_load_element__304__word_value))))
                                : ((1U & (IData)(__Vfunc_load_element__304__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__304__byte_value) 
                                                               >> 7U))))) 
                                        << 8U) | (QData)((IData)(__Vfunc_load_element__304__byte_value)))
                                    : (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__304__nibble_value) 
                                                               >> 3U))))) 
                                        << 4U) | (QData)((IData)(__Vfunc_load_element__304__nibble_value)))));
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q 
                            = __Vfunc_load_element__304__Vfuncout;
                        if (([&]() {
                                    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__opcode 
                                        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q;
                                    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__Vfuncout 
                                        = ((((((((0x60U 
                                                  == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__opcode)) 
                                                 || (0x61U 
                                                     == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__opcode))) 
                                                || (0x62U 
                                                    == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__opcode))) 
                                               || (0x64U 
                                                   == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__opcode))) 
                                              || (0x65U 
                                                  == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__opcode))) 
                                             || (0x66U 
                                                 == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__opcode))) 
                                            || (0x67U 
                                                == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__opcode))) 
                                           || (0x63U 
                                               == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__opcode)));
                                }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__305__Vfuncout))) {
                            if (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_from_scalar0) {
                                vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q 
                                    = (((QData)((IData)(
                                                        (- (IData)(
                                                                   (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar0 
                                                                    >> 0x1fU))))) 
                                        << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar0)));
                                if (([&]() {
                                            __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__306__opcode 
                                                = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q;
                                            __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__306__Vfuncout 
                                                = (0x63U 
                                                   == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__306__opcode));
                                        }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__306__Vfuncout))) {
                                    if (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_from_scalar1) {
                                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_value_q 
                                            = (((QData)((IData)(
                                                                (- (IData)(
                                                                           (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar1 
                                                                            >> 0x1fU))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar1)));
                                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0xcU;
                                    } else {
                                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 8U;
                                    }
                                } else {
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0xcU;
                                }
                            } else {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 6U;
                            }
                        } else {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0xcU;
                        }
                    }
                }
            } else if (([&]() {
                        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__dtype 
                            = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_dtype;
                        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_addr));
                        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__Vfuncout 
                            = (((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__dtype)) 
                                & (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__byte_lane))) 
                               | ((3U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__dtype)) 
                                  & (6U < (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__byte_lane))));
                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__element_crosses_beat__307__Vfuncout))) {
                __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__308__fail_addr 
                    = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_addr);
                vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 4U;
                vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                    = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__308__fail_addr;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
            } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 5U;
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                         [3U])) {
                        __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__309__fail_addr 
                            = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_addr;
                        __Vfunc_memory_status_to_task__310__status 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                            [3U];
                        __Vfunc_memory_status_to_task__310__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__310__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__310__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__310__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__309__fail_status 
                            = __Vfunc_memory_status_to_task__310__Vfuncout;
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q 
                            = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__309__fail_status;
                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__309__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__mask_value_q 
                            = (0U != (0xffU & (IData)(
                                                      (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                                       [3U] 
                                                       >> 
                                                       (0x3fU 
                                                        & VL_SHIFTL_III(6,32,32, 
                                                                        (7U 
                                                                         & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_addr)), 3U))))));
                        if ((0x67U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 4U;
                        } else if ((0U == (0xffU & (IData)(
                                                           (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                                            [3U] 
                                                            >> 
                                                            (0x3fU 
                                                             & VL_SHIFTL_III(6,32,32, 
                                                                             (7U 
                                                                              & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_addr)), 3U))))))) {
                            if (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_false_keep_dst) {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0xaU;
                            } else {
                                vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__result_q = 0ULL;
                                vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rmw_beat_q = 0ULL;
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q 
                                    = (((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype)) 
                                        & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_high_nibble))
                                        ? 0xdU : 0xfU);
                            }
                        } else {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 4U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if (([&]() {
                        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_known__311__opcode 
                            = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q;
                        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_known__311__Vfuncout 
                            = ((0x60U <= (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_known__311__opcode)) 
                               & (0x69U >= (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_known__311__opcode)));
                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_known__311__Vfuncout))) {
                if ((((1U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_version)) 
                      | (3U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_type))) 
                     | (0xc0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_bytes)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if ((IData)((0U != (0xfffe0300U 
                                           & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__numeric_cfg)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if ((IData)(((((0U != (0xfffffff0U 
                                              & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__vector_flags)) 
                                      | (0U != (0xc0U 
                                                & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__broadcast_mode)))) 
                                     | (0U != (0xfefefefeU 
                                               & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU]))) 
                                    | (((5U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__compare_mode)) 
                                        | (2U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__overflow_mode))) 
                                       | (1U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_mode)))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if ((((0U == vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rows) 
                             | (0U == vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__length)) 
                            & (0U != vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__valid_length))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if ((((0U != vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rows) 
                             & (0U != vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__length)) 
                            & ((0U == vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__valid_length) 
                               | (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__valid_length 
                                  > vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__length)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_nibble) {
                    __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__321__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_base);
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_vector__DOT__fail_task__321__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if ((((((0ULL != (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_base 
                                         >> 0x14U)) 
                               | (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_base 
                                           >> 0x14U))) 
                              | ((([&]() {
                                                __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__opcode 
                                                    = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q;
                                                __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__Vfuncout 
                                                    = 
                                                    ((((((((0x60U 
                                                            == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__opcode)) 
                                                           || (0x61U 
                                                               == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__opcode))) 
                                                          || (0x62U 
                                                              == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__opcode))) 
                                                         || (0x64U 
                                                             == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__opcode))) 
                                                        || (0x65U 
                                                            == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__opcode))) 
                                                       || (0x66U 
                                                           == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__opcode))) 
                                                      || (0x67U 
                                                          == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__opcode))) 
                                                     || (0x63U 
                                                         == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__opcode)));
                                            }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src1__322__Vfuncout)) 
                                  & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_from_scalar0))) 
                                 & (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_base 
                                             >> 0x14U)))) 
                             | ((([&]() {
                                            __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__323__opcode 
                                                = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q;
                                            __Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__323__Vfuncout 
                                                = (0x63U 
                                                   == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__323__opcode));
                                        }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__opcode_uses_src2__323__Vfuncout)) 
                                 & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_from_scalar1))) 
                                & (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_base 
                                            >> 0x14U)))) 
                            | ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_enable) 
                               & (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_base 
                                           >> 0x14U))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if (((((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_enable) 
                              & (1U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_mode))) 
                             | ((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_enable)) 
                                & (0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_mode)))) 
                            | ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_enable) 
                               & ((1U != vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_elem_stride) 
                                  | ((1U < vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rows) 
                                     & (0U == vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_row_stride)))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if (((((((0x60U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q)) 
                                | (0x61U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) 
                               | (0x64U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) 
                              | (0x65U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) 
                             | (0x67U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) 
                            & (((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_dtype) 
                                != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_dtype)) 
                               | ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype) 
                                  != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_dtype))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if (((0x66U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q)) 
                            & (((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_dtype) 
                                != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_dtype)) 
                               | (1U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if ((((0x62U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q)) 
                             | (0x63U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) 
                            & ((((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_dtype)) 
                                 | (2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_dtype))) 
                                | (2U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype))) 
                               | ((0x63U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q)) 
                                  & (2U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_dtype)))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if ((((0x68U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q)) 
                             | (0x69U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q))) 
                            & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype) 
                               != (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_dtype)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if (((0x68U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q)) 
                            & VL_GTS_III(32, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar0, vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar1))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else if (((0U == vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rows) 
                            | (0U == vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__length))) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
                } else {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__row_q = 0U;
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__mask_value_q = 1U;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q 
                        = ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_enable)
                            ? 2U : 4U);
                }
            } else {
                vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 1U;
                vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0x11U;
            }
        } else {
            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 0U;
            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__progress_q = 0ULL;
            if (vlSelfRef.tb_npu_engines__DOT__vector_task_valid) {
                IData/*31:0*/ __Vilp1;
                __Vilp1 = 0U;
                while ((__Vilp1 <= 0x3fU)) {
                    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[__Vilp1] 
                        = vlSelfRef.tb_npu_engines__DOT__vector_desc[__Vilp1];
                    __Vilp1 = ((IData)(1U) + __Vilp1);
                }
                vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q 
                    = vlSelfRef.tb_npu_engines__DOT__vector_opcode;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 1U;
            }
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__state_q = 0U;
        IData/*31:0*/ __Vilp2;
        __Vilp2 = 0U;
        while ((__Vilp2 <= 0x3fU)) {
            vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[__Vilp2] 
                = Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0[__Vilp2];
            __Vilp2 = ((IData)(1U) + __Vilp2);
        }
        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__opcode_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__row_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_value_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_value_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_value_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__result_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rmw_beat_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_vector__DOT__mask_value_q = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__status_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__fault_addr_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__progress_q = 0ULL;
    }
    if (vlSelfRef.tb_npu_engines__DOT__reset_n) {
        if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0U;
            } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0U;
            } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0U;
                } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                         [2U])) {
                        __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__197__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_addr);
                        __Vfunc_memory_status_to_task__198__status 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                            [2U];
                        __Vfunc_memory_status_to_task__198__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__198__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__198__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__198__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__197__fail_status 
                            = __Vfunc_memory_status_to_task__198__Vfuncout;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__197__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q 
                            = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__197__fail_status;
                    } else {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__progress_q 
                            = (1ULL + vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__progress_q);
                        if ((((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q) 
                             < vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_n)) {
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q 
                                = ((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q);
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 2U;
                        } else if ((((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__row_q) 
                                    < vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_m)) {
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__row_q 
                                = ((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__row_q);
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q = 0U;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 2U;
                        } else if ((((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_q) 
                                    < vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_count)) {
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_q 
                                = ((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_q);
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__row_q = 0U;
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q = 0U;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 2U;
                        } else {
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 0U;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                        }
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x12U;
                }
            } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                     [2U])) {
                    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__199__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_addr);
                    __Vfunc_memory_status_to_task__200__status 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                        [2U];
                    __Vfunc_memory_status_to_task__200__Vfuncout 
                        = ((0U == (IData)(__Vfunc_memory_status_to_task__200__status))
                            ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__200__status))
                                     ? 6U : ((2U == (IData)(__Vfunc_memory_status_to_task__200__status))
                                              ? 5U : 4U)));
                    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__199__fail_status 
                        = __Vfunc_memory_status_to_task__200__Vfuncout;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__199__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q 
                        = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__199__fail_status;
                } else {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__rmw_beat_q 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                        [2U];
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x11U;
                }
            }
        } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                        if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x10U;
                        }
                    } else {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__epilogue_value 
                            = ((0x43U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q))
                                ? 0ULL : vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_q);
                        if (((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__relu_enable) 
                             & VL_GTS_IQQ(64, 0ULL, vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__epilogue_value))) {
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__epilogue_value = 0ULL;
                        }
                        if (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable) {
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__requant_value 
                                = (([&]() {
                                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding 
                                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__round_mode;
                                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_value 
                                            = (0xffU 
                                               & (IData)(
                                                         (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_entry_q 
                                                          >> 0x20U)));
                                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__multiplier 
                                            = (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_entry_q);
                                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__value 
                                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__epilogue_value;
                                        VL_ZERO_W(128, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product);
                                        VL_ZERO_W(128, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted);
                                        VL_ZERO_W(128, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product);
                                        VL_ZERO_W(128, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding_bias);
                                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount = 0;
                                        {
                                            VL_EXTENDS_WQ(128,64, __Vtemp_1, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__value);
                                            VL_EXTENDS_WQ(128,33, __Vtemp_2, (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__multiplier)));
                                            VL_MULS_WWW(128, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product, __Vtemp_1, __Vtemp_2);
                                            if (VL_GTS_III(32, 0U, 
                                                           VL_EXTENDS_II(32,8, (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_value)))) {
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount 
                                                    = 
                                                    (- 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & ((IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_value) 
                                                                      >> 7U)))) 
                                                       << 8U) 
                                                      | (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_value)));
                                                VL_SHIFTL_WWI(128,128,32, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount);
                                            } else if (
                                                       (0U 
                                                        == 
                                                        VL_EXTENDS_II(32,8, (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_value)))) {
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[0U] 
                                                    = 
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product[0U];
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[1U] 
                                                    = 
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product[1U];
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[2U] 
                                                    = 
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product[2U];
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[3U] 
                                                    = 
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product[3U];
                                            } else {
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount 
                                                    = 
                                                    (((- (IData)(
                                                                 (1U 
                                                                  & ((IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_value) 
                                                                     >> 7U)))) 
                                                      << 8U) 
                                                     | (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_value));
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding_bias[0U] = 0U;
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding_bias[1U] = 0U;
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding_bias[2U] = 0U;
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding_bias[3U] = 0U;
                                                if (
                                                    ((0U 
                                                      == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding)) 
                                                     & VL_LTS_III(32, 0U, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount))) {
                                                    __Vtemp_3[0U] = 0U;
                                                    __Vtemp_3[1U] = 0U;
                                                    __Vtemp_3[2U] = 0U;
                                                    __Vtemp_3[3U] = 0U;
                                                    VL_NEGATE_W(4, __Vtemp_4, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product);
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product[0U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_3, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product)
                                                          ? 
                                                         __Vtemp_4[0U]
                                                          : 
                                                         __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product[0U]);
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product[1U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_3, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product)
                                                          ? 
                                                         __Vtemp_4[1U]
                                                          : 
                                                         __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product[1U]);
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product[2U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_3, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product)
                                                          ? 
                                                         __Vtemp_4[2U]
                                                          : 
                                                         __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product[2U]);
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product[3U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_3, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product)
                                                          ? 
                                                         __Vtemp_4[3U]
                                                          : 
                                                         __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product[3U]);
                                                    __Vtemp_6[0U] = 1U;
                                                    __Vtemp_6[1U] = 0U;
                                                    __Vtemp_6[2U] = 0U;
                                                    __Vtemp_6[3U] = 0U;
                                                    VL_SHIFTL_WWI(128,128,32, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding_bias, __Vtemp_6, 
                                                                  (__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount 
                                                                   - (IData)(1U)));
                                                    VL_ADD_W(4, __Vtemp_7, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding_bias);
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product[0U] 
                                                        = 
                                                        __Vtemp_7[0U];
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product[1U] 
                                                        = 
                                                        __Vtemp_7[1U];
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product[2U] 
                                                        = 
                                                        __Vtemp_7[2U];
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product[3U] 
                                                        = 
                                                        __Vtemp_7[3U];
                                                    __Vtemp_8[0U] = 0U;
                                                    __Vtemp_8[1U] = 0U;
                                                    __Vtemp_8[2U] = 0U;
                                                    __Vtemp_8[3U] = 0U;
                                                    VL_SHIFTRS_WWI(128,128,32, __Vtemp_9, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount);
                                                    VL_NEGATE_W(4, __Vtemp_10, __Vtemp_9);
                                                    VL_SHIFTRS_WWI(128,128,32, __Vtemp_11, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__absolute_product, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount);
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[0U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_8, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product)
                                                          ? 
                                                         __Vtemp_10[0U]
                                                          : 
                                                         __Vtemp_11[0U]);
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[1U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_8, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product)
                                                          ? 
                                                         __Vtemp_10[1U]
                                                          : 
                                                         __Vtemp_11[1U]);
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[2U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_8, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product)
                                                          ? 
                                                         __Vtemp_10[2U]
                                                          : 
                                                         __Vtemp_11[2U]);
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[3U] 
                                                        = 
                                                        (VL_GTS_IWW(128, __Vtemp_8, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product)
                                                          ? 
                                                         __Vtemp_10[3U]
                                                          : 
                                                         __Vtemp_11[3U]);
                                                } else {
                                                    __Vtemp_13[0U] = 0U;
                                                    __Vtemp_13[1U] = 0U;
                                                    __Vtemp_13[2U] = 0U;
                                                    __Vtemp_13[3U] = 0U;
                                                    __Vtemp_14[0U] = 1U;
                                                    __Vtemp_14[1U] = 0U;
                                                    __Vtemp_14[2U] = 0U;
                                                    __Vtemp_14[3U] = 0U;
                                                    VL_SHIFTL_WWI(128,128,32, __Vtemp_15, __Vtemp_14, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount);
                                                    __Vtemp_16[0U] = 1U;
                                                    __Vtemp_16[1U] = 0U;
                                                    __Vtemp_16[2U] = 0U;
                                                    __Vtemp_16[3U] = 0U;
                                                    VL_SUB_W(4, __Vtemp_17, __Vtemp_15, __Vtemp_16);
                                                    VL_ADD_W(4, __Vtemp_18, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product, __Vtemp_17);
                                                    VL_SHIFTRS_WWI(128,128,32, __Vtemp_19, __Vtemp_18, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount);
                                                    __Vtemp_20[0U] = 0U;
                                                    __Vtemp_20[1U] = 0U;
                                                    __Vtemp_20[2U] = 0U;
                                                    __Vtemp_20[3U] = 0U;
                                                    VL_NEGATE_W(4, __Vtemp_21, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product);
                                                    __Vtemp_22[0U] = 1U;
                                                    __Vtemp_22[1U] = 0U;
                                                    __Vtemp_22[2U] = 0U;
                                                    __Vtemp_22[3U] = 0U;
                                                    VL_SHIFTL_WWI(128,128,32, __Vtemp_23, __Vtemp_22, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount);
                                                    __Vtemp_24[0U] = 1U;
                                                    __Vtemp_24[1U] = 0U;
                                                    __Vtemp_24[2U] = 0U;
                                                    __Vtemp_24[3U] = 0U;
                                                    VL_SUB_W(4, __Vtemp_25, __Vtemp_23, __Vtemp_24);
                                                    VL_ADD_W(4, __Vtemp_26, __Vtemp_21, __Vtemp_25);
                                                    VL_SHIFTRS_WWI(128,128,32, __Vtemp_27, __Vtemp_26, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount);
                                                    VL_NEGATE_W(4, __Vtemp_28, __Vtemp_27);
                                                    VL_SHIFTRS_WWI(128,128,32, __Vtemp_29, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shift_amount);
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[0U] 
                                                        = 
                                                        (((2U 
                                                           == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding)) 
                                                          & VL_LTS_IWW(128, __Vtemp_13, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product))
                                                          ? 
                                                         __Vtemp_19[0U]
                                                          : 
                                                         (((3U 
                                                            == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding)) 
                                                           & VL_GTS_IWW(128, __Vtemp_20, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product))
                                                           ? 
                                                          __Vtemp_28[0U]
                                                           : 
                                                          __Vtemp_29[0U]));
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[1U] 
                                                        = 
                                                        (((2U 
                                                           == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding)) 
                                                          & VL_LTS_IWW(128, __Vtemp_13, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product))
                                                          ? 
                                                         __Vtemp_19[1U]
                                                          : 
                                                         (((3U 
                                                            == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding)) 
                                                           & VL_GTS_IWW(128, __Vtemp_20, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product))
                                                           ? 
                                                          __Vtemp_28[1U]
                                                           : 
                                                          __Vtemp_29[1U]));
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[2U] 
                                                        = 
                                                        (((2U 
                                                           == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding)) 
                                                          & VL_LTS_IWW(128, __Vtemp_13, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product))
                                                          ? 
                                                         __Vtemp_19[2U]
                                                          : 
                                                         (((3U 
                                                            == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding)) 
                                                           & VL_GTS_IWW(128, __Vtemp_20, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product))
                                                           ? 
                                                          __Vtemp_28[2U]
                                                           : 
                                                          __Vtemp_29[2U]));
                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[3U] 
                                                        = 
                                                        (((2U 
                                                           == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding)) 
                                                          & VL_LTS_IWW(128, __Vtemp_13, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product))
                                                          ? 
                                                         __Vtemp_19[3U]
                                                          : 
                                                         (((3U 
                                                            == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__rounding)) 
                                                           & VL_GTS_IWW(128, __Vtemp_20, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__product))
                                                           ? 
                                                          __Vtemp_28[3U]
                                                           : 
                                                          __Vtemp_29[3U]));
                                                }
                                            }
                                            if (((((QData)((IData)(
                                                                   __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[3U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[2U]))) 
                                                 != 
                                                 (- (QData)((IData)(
                                                                    (__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[1U] 
                                                                     >> 0x1fU)))))) {
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__Vfuncout 
                                                    = 
                                                    ((__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[3U] 
                                                      >> 0x1fU)
                                                      ? 0x8000000000000000ULL
                                                      : 0x7fffffffffffffffULL);
                                                goto __Vlabel1;
                                            }
                                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__Vfuncout 
                                                = (
                                                   ((QData)((IData)(
                                                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__shifted[0U])));
                                            __Vlabel1: ;
                                        }
                                    }(), __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__requantize__201__Vfuncout) 
                                   + (((QData)((IData)(
                                                       (- (IData)(
                                                                  (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__output_zero_point 
                                                                   >> 0x1fU))))) 
                                       << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__output_zero_point))));
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__epilogue_value 
                                = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__requant_value;
                        }
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__overflow 
                            = (VL_LTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__epilogue_value, 
                                          ([&]() {
                                        __Vfunc_dtype_min__202__dtype 
                                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype;
                                        __Vfunc_dtype_min__202__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_dtype_min__202__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_min__202__dtype))
                                                    ? 0xffffffffffff8000ULL
                                                    : 0xffffffff80000000ULL)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_min__202__dtype))
                                                    ? 0xffffffffffffff80ULL
                                                    : 0xfffffffffffffff8ULL));
                                    }(), __Vfunc_dtype_min__202__Vfuncout)) 
                               | VL_GTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__epilogue_value, 
                                            ([&]() {
                                        __Vfunc_dtype_max__203__dtype 
                                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype;
                                        __Vfunc_dtype_max__203__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_dtype_max__203__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_max__203__dtype))
                                                    ? 0x7fffULL
                                                    : 0x7fffffffULL)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_max__203__dtype))
                                                    ? 0x7fULL
                                                    : 7ULL));
                                    }(), __Vfunc_dtype_max__203__Vfuncout)));
                        if (((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__overflow) 
                             & (1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__overflow_mode)))) {
                            __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__204__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_addr);
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 0xcU;
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__204__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                        } else {
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__result_q 
                                = ((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__overflow_mode))
                                    ? ([&]() {
                                        __Vfunc_wrap_to_dtype__205__dtype 
                                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype;
                                        __Vfunc_wrap_to_dtype__205__value 
                                            = (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__epilogue_value);
                                        __Vfunc_wrap_to_dtype__205__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_wrap_to_dtype__205__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_wrap_to_dtype__205__dtype))
                                                    ? 
                                                   (((- (QData)((IData)(
                                                                        (1U 
                                                                         & (__Vfunc_wrap_to_dtype__205__value 
                                                                            >> 0xfU))))) 
                                                     << 0x10U) 
                                                    | (QData)((IData)(
                                                                      (0xffffU 
                                                                       & __Vfunc_wrap_to_dtype__205__value))))
                                                    : 
                                                   (((QData)((IData)(
                                                                     (- (IData)(
                                                                                (__Vfunc_wrap_to_dtype__205__value 
                                                                                >> 0x1fU))))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(__Vfunc_wrap_to_dtype__205__value))))
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_wrap_to_dtype__205__dtype))
                                                    ? 
                                                   (((- (QData)((IData)(
                                                                        (1U 
                                                                         & (__Vfunc_wrap_to_dtype__205__value 
                                                                            >> 7U))))) 
                                                     << 8U) 
                                                    | (QData)((IData)(
                                                                      (0xffU 
                                                                       & __Vfunc_wrap_to_dtype__205__value))))
                                                    : 
                                                   (((- (QData)((IData)(
                                                                        (1U 
                                                                         & (__Vfunc_wrap_to_dtype__205__value 
                                                                            >> 3U))))) 
                                                     << 4U) 
                                                    | (QData)((IData)(
                                                                      (0xfU 
                                                                       & __Vfunc_wrap_to_dtype__205__value))))));
                                    }(), __Vfunc_wrap_to_dtype__205__Vfuncout)
                                    : ([&]() {
                                        __Vfunc_clip_to_dtype__206__dtype 
                                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype;
                                        __Vfunc_clip_to_dtype__206__value 
                                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__unnamedblk1__DOT__epilogue_value;
                                        __Vfunc_clip_to_dtype__206__minimum = 0;
                                        __Vfunc_clip_to_dtype__206__maximum = 0;
                                        {
                                            __Vfunc_dtype_min__207__dtype 
                                                = __Vfunc_clip_to_dtype__206__dtype;
                                            __Vfunc_dtype_min__207__Vfuncout 
                                                = (
                                                   (2U 
                                                    & (IData)(__Vfunc_dtype_min__207__dtype))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_dtype_min__207__dtype))
                                                     ? 0xffffffffffff8000ULL
                                                     : 0xffffffff80000000ULL)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_dtype_min__207__dtype))
                                                     ? 0xffffffffffffff80ULL
                                                     : 0xfffffffffffffff8ULL));
                                            __Vfunc_clip_to_dtype__206__minimum 
                                                = __Vfunc_dtype_min__207__Vfuncout;
                                            __Vfunc_dtype_max__208__dtype 
                                                = __Vfunc_clip_to_dtype__206__dtype;
                                            __Vfunc_dtype_max__208__Vfuncout 
                                                = (
                                                   (2U 
                                                    & (IData)(__Vfunc_dtype_max__208__dtype))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(__Vfunc_dtype_max__208__dtype))
                                                     ? 0x7fffULL
                                                     : 0x7fffffffULL)
                                                    : 
                                                   ((1U 
                                                     & (IData)(__Vfunc_dtype_max__208__dtype))
                                                     ? 0x7fULL
                                                     : 7ULL));
                                            __Vfunc_clip_to_dtype__206__maximum 
                                                = __Vfunc_dtype_max__208__Vfuncout;
                                            if (VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__206__value, __Vfunc_clip_to_dtype__206__minimum)) {
                                                __Vfunc_clip_to_dtype__206__Vfuncout 
                                                    = __Vfunc_clip_to_dtype__206__minimum;
                                                goto __Vlabel2;
                                            }
                                            if (VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__206__value, __Vfunc_clip_to_dtype__206__maximum)) {
                                                __Vfunc_clip_to_dtype__206__Vfuncout 
                                                    = __Vfunc_clip_to_dtype__206__maximum;
                                                goto __Vlabel2;
                                            }
                                            __Vfunc_clip_to_dtype__206__Vfuncout 
                                                = __Vfunc_clip_to_dtype__206__value;
                                            __Vlabel2: ;
                                        }
                                    }(), __Vfunc_clip_to_dtype__206__Vfuncout));
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__rmw_beat_q = 0ULL;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q 
                                = (((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype)) 
                                    & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_high_nibble))
                                    ? 0xfU : 0x11U);
                        }
                    }
                } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                    if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                             [2U])) {
                            __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__209__fail_addr 
                                = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_addr;
                            __Vfunc_memory_status_to_task__210__status 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                                [2U];
                            __Vfunc_memory_status_to_task__210__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__210__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__210__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__210__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__209__fail_status 
                                = __Vfunc_memory_status_to_task__210__Vfuncout;
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q 
                                = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__209__fail_status;
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__209__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                        } else if ((0U != (0xffffffU 
                                           & (IData)(
                                                     (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                                      [2U] 
                                                      >> 0x28U))))) {
                            __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__211__fail_addr 
                                = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_addr;
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__211__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                        } else {
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_entry_q 
                                = (0xffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                   [2U]);
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0xeU;
                        }
                    }
                } else if (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__inline_requant) {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_entry_q 
                        = (1ULL | ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__inline_requant_shift)) 
                                   << 0x20U));
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0xeU;
                } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0xdU;
                }
            } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                    if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                             [2U])) {
                            __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__212__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_addr);
                            __Vfunc_memory_status_to_task__213__status 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                                [2U];
                            __Vfunc_memory_status_to_task__213__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__213__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__213__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__213__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__212__fail_status 
                                = __Vfunc_memory_status_to_task__213__Vfuncout;
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q 
                                = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__212__fail_status;
                            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__212__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                        } else {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__accum_q 
                                = (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_q 
                                   + ([&]() {
                                        __Vfunc_load_element__214__byte_lane 
                                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_addr));
                                        __Vfunc_load_element__214__beat 
                                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                            [2U];
                                        __Vfunc_load_element__214__word_value 
                                            = (IData)(
                                                      (__Vfunc_load_element__214__beat 
                                                       >> 
                                                       (0x3fU 
                                                        & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__214__byte_lane), 3U))));
                                        __Vfunc_load_element__214__Vfuncout 
                                            = (((QData)((IData)(
                                                                (- (IData)(
                                                                           (__Vfunc_load_element__214__word_value 
                                                                            >> 0x1fU))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(__Vfunc_load_element__214__word_value)));
                                    }(), __Vfunc_load_element__214__Vfuncout));
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q 
                                = ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable)
                                    ? 0xcU : 0xeU);
                        }
                    }
                } else if (([&]() {
                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__215__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_addr));
                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__215__Vfuncout 
                                = (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__215__byte_lane));
                        }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__215__Vfuncout))) {
                    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__216__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_addr);
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__216__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0xbU;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                         [2U])) {
                        __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__217__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__src2_addr);
                        __Vfunc_memory_status_to_task__218__status 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                            [2U];
                        __Vfunc_memory_status_to_task__218__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__218__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__218__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__218__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__217__fail_status 
                            = __Vfunc_memory_status_to_task__218__Vfuncout;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q 
                            = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__217__fail_status;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__217__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__accum_q 
                            = (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_q 
                               + ([&]() {
                                    __Vfunc_load_element__219__byte_lane 
                                        = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__src2_addr));
                                    __Vfunc_load_element__219__beat 
                                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                        [2U];
                                    __Vfunc_load_element__219__word_value 
                                        = (IData)((__Vfunc_load_element__219__beat 
                                                   >> 
                                                   (0x3fU 
                                                    & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__219__byte_lane), 3U))));
                                    __Vfunc_load_element__219__Vfuncout 
                                        = (((QData)((IData)(
                                                            (- (IData)(
                                                                       (__Vfunc_load_element__219__word_value 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(__Vfunc_load_element__219__word_value)));
                                }(), __Vfunc_load_element__219__Vfuncout));
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q 
                            = ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_enable)
                                ? 0xaU : ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable)
                                           ? 0xcU : 0xeU));
                    }
                }
            } else if (([&]() {
                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__220__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__src2_addr));
                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__220__Vfuncout 
                            = (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__220__byte_lane));
                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__220__Vfuncout))) {
                __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__221__fail_addr 
                    = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__src2_addr);
                vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 4U;
                vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                    = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__221__fail_addr;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
            } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 9U;
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__accum_q 
                        = (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_q 
                           + VL_MULS_QQQ(64, vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_value_q, vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_value_q));
                    if ((((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q) 
                         < vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_k)) {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q 
                            = ((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q);
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 3U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q 
                            = (((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_from_src2) 
                                | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__residual_enable))
                                ? 8U : ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_enable)
                                         ? 0xaU : ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable)
                                                    ? 0xcU
                                                    : 0xeU)));
                    }
                } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                         [2U])) {
                        __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__222__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_addr);
                        __Vfunc_memory_status_to_task__223__status 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                            [2U];
                        __Vfunc_memory_status_to_task__223__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__223__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__223__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__223__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__222__fail_status 
                            = __Vfunc_memory_status_to_task__223__Vfuncout;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q 
                            = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__222__fail_status;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__222__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else {
                        __Vfunc_load_element__224__dtype 
                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_dtype;
                        __Vfunc_load_element__224__high_nibble 
                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_high_nibble;
                        __Vfunc_load_element__224__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_addr));
                        __Vfunc_load_element__224__beat 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                            [2U];
                        __Vfunc_load_element__224__byte_value 
                            = (0xffU & (IData)((__Vfunc_load_element__224__beat 
                                                >> 
                                                (0x3fU 
                                                 & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__224__byte_lane), 3U)))));
                        __Vfunc_load_element__224__nibble_value 
                            = (0xfU & ((IData)(__Vfunc_load_element__224__high_nibble)
                                        ? ((IData)(__Vfunc_load_element__224__byte_value) 
                                           >> 4U) : (IData)(__Vfunc_load_element__224__byte_value)));
                        __Vfunc_load_element__224__half_value 
                            = (0xffffU & (IData)((__Vfunc_load_element__224__beat 
                                                  >> 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__224__byte_lane), 3U)))));
                        __Vfunc_load_element__224__word_value 
                            = (IData)((__Vfunc_load_element__224__beat 
                                       >> (0x3fU & 
                                           VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__224__byte_lane), 3U))));
                        __Vfunc_load_element__224__Vfuncout 
                            = ((2U & (IData)(__Vfunc_load_element__224__dtype))
                                ? ((1U & (IData)(__Vfunc_load_element__224__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__224__half_value) 
                                                               >> 0xfU))))) 
                                        << 0x10U) | (QData)((IData)(__Vfunc_load_element__224__half_value)))
                                    : (((QData)((IData)(
                                                        (- (IData)(
                                                                   (__Vfunc_load_element__224__word_value 
                                                                    >> 0x1fU))))) 
                                        << 0x20U) | (QData)((IData)(__Vfunc_load_element__224__word_value))))
                                : ((1U & (IData)(__Vfunc_load_element__224__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__224__byte_value) 
                                                               >> 7U))))) 
                                        << 8U) | (QData)((IData)(__Vfunc_load_element__224__byte_value)))
                                    : (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__224__nibble_value) 
                                                               >> 3U))))) 
                                        << 4U) | (QData)((IData)(__Vfunc_load_element__224__nibble_value)))));
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_value_q 
                            = __Vfunc_load_element__224__Vfuncout;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 7U;
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 6U;
                }
            } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                     [2U])) {
                    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__225__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_addr);
                    __Vfunc_memory_status_to_task__226__status 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                        [2U];
                    __Vfunc_memory_status_to_task__226__Vfuncout 
                        = ((0U == (IData)(__Vfunc_memory_status_to_task__226__status))
                            ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__226__status))
                                     ? 6U : ((2U == (IData)(__Vfunc_memory_status_to_task__226__status))
                                              ? 5U : 4U)));
                    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__225__fail_status 
                        = __Vfunc_memory_status_to_task__226__Vfuncout;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q 
                        = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__225__fail_status;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__225__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else {
                    __Vfunc_load_element__227__dtype 
                        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_dtype;
                    __Vfunc_load_element__227__high_nibble 
                        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_high_nibble;
                    __Vfunc_load_element__227__byte_lane 
                        = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_addr));
                    __Vfunc_load_element__227__beat 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                        [2U];
                    __Vfunc_load_element__227__byte_value 
                        = (0xffU & (IData)((__Vfunc_load_element__227__beat 
                                            >> (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__227__byte_lane), 3U)))));
                    __Vfunc_load_element__227__nibble_value 
                        = (0xfU & ((IData)(__Vfunc_load_element__227__high_nibble)
                                    ? ((IData)(__Vfunc_load_element__227__byte_value) 
                                       >> 4U) : (IData)(__Vfunc_load_element__227__byte_value)));
                    __Vfunc_load_element__227__half_value 
                        = (0xffffU & (IData)((__Vfunc_load_element__227__beat 
                                              >> (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__227__byte_lane), 3U)))));
                    __Vfunc_load_element__227__word_value 
                        = (IData)((__Vfunc_load_element__227__beat 
                                   >> (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__227__byte_lane), 3U))));
                    __Vfunc_load_element__227__Vfuncout 
                        = ((2U & (IData)(__Vfunc_load_element__227__dtype))
                            ? ((1U & (IData)(__Vfunc_load_element__227__dtype))
                                ? (((- (QData)((IData)(
                                                       (1U 
                                                        & ((IData)(__Vfunc_load_element__227__half_value) 
                                                           >> 0xfU))))) 
                                    << 0x10U) | (QData)((IData)(__Vfunc_load_element__227__half_value)))
                                : (((QData)((IData)(
                                                    (- (IData)(
                                                               (__Vfunc_load_element__227__word_value 
                                                                >> 0x1fU))))) 
                                    << 0x20U) | (QData)((IData)(__Vfunc_load_element__227__word_value))))
                            : ((1U & (IData)(__Vfunc_load_element__227__dtype))
                                ? (((- (QData)((IData)(
                                                       (1U 
                                                        & ((IData)(__Vfunc_load_element__227__byte_value) 
                                                           >> 7U))))) 
                                    << 8U) | (QData)((IData)(__Vfunc_load_element__227__byte_value)))
                                : (((- (QData)((IData)(
                                                       (1U 
                                                        & ((IData)(__Vfunc_load_element__227__nibble_value) 
                                                           >> 3U))))) 
                                    << 4U) | (QData)((IData)(__Vfunc_load_element__227__nibble_value)))));
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_value_q 
                        = __Vfunc_load_element__227__Vfuncout;
                    if (([&]() {
                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__dtype 
                                    = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_dtype;
                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__byte_lane 
                                    = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_addr));
                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__Vfuncout 
                                    = (((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__dtype)) 
                                        & (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__byte_lane))) 
                                       | ((3U == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__dtype)) 
                                          & (6U < (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__byte_lane))));
                            }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__228__Vfuncout))) {
                        __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__229__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_addr);
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 4U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__229__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 5U;
                    }
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 4U;
                }
            } else {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__accum_q = 0ULL;
                vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q = 0U;
                vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__rmw_beat_q = 0ULL;
                if (([&]() {
                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__dtype 
                                = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype;
                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_addr));
                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__Vfuncout 
                                = (((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__dtype)) 
                                    & (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__byte_lane))) 
                                   | ((3U == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__dtype)) 
                                      & (6U < (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__byte_lane))));
                        }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__230__Vfuncout))) {
                    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__231__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_addr);
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__231__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else if (((0x43U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q)) 
                            | (0U == vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_k))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q 
                        = ((0x43U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q))
                            ? 0xeU : (((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_from_src2) 
                                       | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__residual_enable))
                                       ? 8U : ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_enable)
                                                ? 0xaU
                                                : ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable)
                                                    ? 0xcU
                                                    : 0xeU))));
                } else if (([&]() {
                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__dtype 
                                = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_dtype;
                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_addr));
                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__Vfuncout 
                                = (((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__dtype)) 
                                    & (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__byte_lane))) 
                                   | ((3U == (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__dtype)) 
                                      & (6U < (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__byte_lane))));
                        }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__crosses_beat__232__Vfuncout))) {
                    __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__233__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_addr);
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_matrix__DOT__fail_task__233__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 3U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            if (([&]() {
                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__opcode_known__234__opcode 
                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q;
                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__opcode_known__234__Vfuncout 
                            = ((0x40U <= (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__opcode_known__234__opcode)) 
                               & (0x43U >= (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__opcode_known__234__opcode)));
                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__opcode_known__234__Vfuncout))) {
                if ((((1U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_version)) 
                      | (2U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_type))) 
                     | (0x100U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_bytes)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else if ((IData)((0U != (0xfffe0300U 
                                           & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__numeric_cfg)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else if (((((((((((6U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_pack_format)) 
                                    | (6U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_pack_format))) 
                                   | (6U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_pack_format))) 
                                  | (0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__pack_version))) 
                                 | (2U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__overflow_mode))) 
                                | (1U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__activation_mode))) 
                               | (0U != (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_flags 
                                         >> 8U))) | 
                              (1U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__residual_mode))) 
                             | (0U != (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x29U] 
                                       >> 0x18U))) 
                            | (0U != vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x2bU]))) {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else if (((((((0ULL != (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_base 
                                          >> 0x14U)) 
                                | (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_base 
                                            >> 0x14U))) 
                               | (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_base 
                                           >> 0x14U))) 
                              | (((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_from_src2) 
                                  | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__residual_enable)) 
                                 & (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__src2_base 
                                             >> 0x14U)))) 
                             | ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_enable) 
                                & (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_base 
                                            >> 0x14U)))) 
                            | (((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable) 
                                & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__inline_requant))) 
                               & (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_base 
                                           >> 0x14U))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else if (((0U != (0x7fU & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x2cU] 
                                             >> 1U))) 
                            | ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__inline_requant) 
                               & (((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable)) 
                                   | (1U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_mode))) 
                                  | (1U != vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_count))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else if ((((0U == vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_count) 
                             | ((0x40U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q)) 
                                & (1U != vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_count))) 
                            | ((0x41U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q)) 
                               & (1U > vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_count)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else if ((((vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__last_valid_m 
                              != ([&]() {
                                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__tile = 8U;
                                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__size 
                                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_m;
                                        {
                                            if ((0U 
                                                 == __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__size)) {
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__Vfuncout = 0U;
                                                goto __Vlabel3;
                                            }
                                            if ((0U 
                                                 == 
                                                 VL_MODDIV_III(32, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__size, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__tile))) {
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__Vfuncout 
                                                    = __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__tile;
                                                goto __Vlabel3;
                                            }
                                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__Vfuncout 
                                                = VL_MODDIV_III(32, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__size, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__tile);
                                            __Vlabel3: ;
                                        }
                                    }(), __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__245__Vfuncout)) 
                             | (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__last_valid_n 
                                != ([&]() {
                                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__tile = 8U;
                                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__size 
                                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_n;
                                        {
                                            if ((0U 
                                                 == __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__size)) {
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__Vfuncout = 0U;
                                                goto __Vlabel4;
                                            }
                                            if ((0U 
                                                 == 
                                                 VL_MODDIV_III(32, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__size, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__tile))) {
                                                __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__Vfuncout 
                                                    = __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__tile;
                                                goto __Vlabel4;
                                            }
                                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__Vfuncout 
                                                = VL_MODDIV_III(32, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__size, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__tile);
                                            __Vlabel4: ;
                                        }
                                    }(), __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__246__Vfuncout))) 
                            | (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__last_valid_k 
                               != ([&]() {
                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__tile = 0x10U;
                                    __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__size 
                                        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_k;
                                    {
                                        if ((0U == __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__size)) {
                                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__Vfuncout = 0U;
                                            goto __Vlabel5;
                                        }
                                        if ((0U == 
                                             VL_MODDIV_III(32, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__size, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__tile))) {
                                            __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__Vfuncout 
                                                = __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__tile;
                                            goto __Vlabel5;
                                        }
                                        __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__Vfuncout 
                                            = VL_MODDIV_III(32, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__size, __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__tile);
                                        __Vlabel5: ;
                                    }
                                }(), __Vfunc_tb_npu_engines__DOT__u_matrix__DOT__expected_tail__247__Vfuncout)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else if (((0x43U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q)) 
                            & (~ ((((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_dtype)) 
                                    & (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_dtype))) 
                                   | ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_dtype)) 
                                      & ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_dtype)) 
                                         | (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_dtype))))) 
                                  | ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_dtype)) 
                                     & (3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_dtype))))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else if (((0x43U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q)) 
                            & (~ ((((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_dtype)) 
                                    & (1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_pack_format))) 
                                   | ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_dtype)) 
                                      & (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_pack_format)))) 
                                  | ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_dtype)) 
                                     & (5U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_pack_format))))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else if (((0x43U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q)) 
                            & (~ ((((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_dtype)) 
                                    & ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_pack_format)) 
                                       | (3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_pack_format)))) 
                                   | ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_dtype)) 
                                      & ((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_pack_format)) 
                                         | (2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_pack_format))))) 
                                  | ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_dtype)) 
                                     & ((5U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_pack_format)) 
                                        | (6U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_pack_format)))))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                } else if ((((((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype)) 
                               & (1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_pack_format))) 
                              | ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype)) 
                                 & (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_pack_format)))) 
                             | ((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype)) 
                                & (4U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_pack_format)))) 
                            | ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype)) 
                               & (5U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_pack_format))))) {
                    if (((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_is_tiled) 
                         & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__transpose_b))) {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else if ((0U != vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__output_zero_point)) {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else if (((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__residual_enable) 
                                & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_from_src2))) {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else if (((0x42U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q)) 
                                & (((((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_from_src2)) 
                                        | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__final_output)) 
                                       | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_enable)) 
                                      | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__residual_enable)) 
                                     | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__relu_enable)) 
                                    | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable)) 
                                   | (2U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype))))) {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else if (((0x43U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q)) 
                                & ((((((2U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype)) 
                                       | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_enable)) 
                                      | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__residual_enable)) 
                                     | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_from_src2)) 
                                    | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable)) 
                                   | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__relu_enable)))) {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else if ((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__final_output)) 
                                 & (0x43U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q))) 
                                & (((((2U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype)) 
                                      | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_enable)) 
                                     | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__residual_enable)) 
                                    | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__relu_enable)) 
                                   | (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable)))) {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else if ((((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__final_output) 
                                 & (2U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype))) 
                                & (((((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable)) 
                                      | (~ ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_mode)) 
                                            | (2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_mode))))) 
                                     | (8U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_entry_bytes))) 
                                    | (~ (((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_mode)) 
                                           & (1U == vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_count)) 
                                          | ((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_mode)) 
                                             & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_count 
                                                == vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_n))))) 
                                   | (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_region_bytes 
                                      < VL_SHIFTL_III(32,32,32, vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_count, 3U))))) {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else if (((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype)) 
                                & (((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable) 
                                    | (0U != vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_count)) 
                                   | (0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_mode))))) {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else if ((((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_enable) 
                                 & (((vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_count 
                                      != vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_n) 
                                     | (4U > vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_stride_bytes)) 
                                    | (0U != (3U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_stride_bytes)))) 
                                | ((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_enable)) 
                                   & (0U != vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_count)))) {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else if (((0U == vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_m) 
                                | (0U == vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_n))) {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 0U;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                    } else {
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_q = 0U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__row_q = 0U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q = 0U;
                        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q = 0U;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__accum_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 2U;
                    }
                } else {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
                }
            } else {
                vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 1U;
                vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0x13U;
            }
        } else {
            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 0U;
            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__progress_q = 0ULL;
            if (vlSelfRef.tb_npu_engines__DOT__matrix_task_valid) {
                IData/*31:0*/ __Vilp3;
                __Vilp3 = 0U;
                while ((__Vilp3 <= 0x3fU)) {
                    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[__Vilp3] 
                        = vlSelfRef.tb_npu_engines__DOT__matrix_desc[__Vilp3];
                    __Vilp3 = ((IData)(1U) + __Vilp3);
                }
                vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q 
                    = vlSelfRef.tb_npu_engines__DOT__matrix_opcode;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 1U;
            }
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__state_q = 0U;
        IData/*31:0*/ __Vilp4;
        __Vilp4 = 0U;
        while ((__Vilp4 <= 0x3fU)) {
            vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[__Vilp4] 
                = Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0[__Vilp4];
            __Vilp4 = ((IData)(1U) + __Vilp4);
        }
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__opcode_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__row_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_value_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_value_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_matrix__DOT__accum_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__result_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_entry_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__rmw_beat_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__status_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__fault_addr_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__progress_q = 0ULL;
    }
}

VL_INLINE_OPT void Vtb_npu_engines___024root___nba_sequent__TOP__1(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___nba_sequent__TOP__1\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__140__fail_status;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__140__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__140__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__140__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__141__Vfuncout;
    __Vfunc_memory_status_to_task__141__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__141__status;
    __Vfunc_memory_status_to_task__141__status = 0;
    CData/*2:0*/ __Vfunc_dtype_bytes__142__Vfuncout;
    __Vfunc_dtype_bytes__142__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_bytes__142__dtype;
    __Vfunc_dtype_bytes__142__dtype = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__143__fail_status;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__143__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__143__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__143__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__144__Vfuncout;
    __Vfunc_memory_status_to_task__144__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__144__status;
    __Vfunc_memory_status_to_task__144__status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__145__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__145__fail_addr = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__146__Vfuncout;
    __Vfunc_clip_to_dtype__146__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__146__value;
    __Vfunc_clip_to_dtype__146__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__146__dtype;
    __Vfunc_clip_to_dtype__146__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__146__minimum;
    __Vfunc_clip_to_dtype__146__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__146__maximum;
    __Vfunc_clip_to_dtype__146__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__147__Vfuncout;
    __Vfunc_dtype_min__147__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__147__dtype;
    __Vfunc_dtype_min__147__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__148__Vfuncout;
    __Vfunc_dtype_max__148__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__148__dtype;
    __Vfunc_dtype_max__148__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__149__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__149__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__150__fail_status;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__150__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__150__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__150__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__151__Vfuncout;
    __Vfunc_memory_status_to_task__151__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__151__status;
    __Vfunc_memory_status_to_task__151__status = 0;
    QData/*63:0*/ __Vfunc_load_element__152__Vfuncout;
    __Vfunc_load_element__152__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__152__beat;
    __Vfunc_load_element__152__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__152__byte_lane;
    __Vfunc_load_element__152__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__152__high_nibble;
    __Vfunc_load_element__152__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__152__dtype;
    __Vfunc_load_element__152__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__152__byte_value;
    __Vfunc_load_element__152__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__152__nibble_value;
    __Vfunc_load_element__152__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__152__half_value;
    __Vfunc_load_element__152__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__152__word_value;
    __Vfunc_load_element__152__word_value = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__value;
    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__value = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__dtype;
    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__154__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__154__fail_addr = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__155__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__155__fail_addr = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__156__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__156__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__157__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__157__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__157__opcode;
    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__157__opcode = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__rank_value;
    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__rank_value = 0;
    VlWide<5>/*159:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__shapes;
    VL_ZERO_W(160, __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__shapes);
    VlWide<4>/*127:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product;
    VL_ZERO_W(128, __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product);
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__dimension;
    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__dimension = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__opcode;
    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__opcode = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__167__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__167__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__171__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__171__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__171__opcode;
    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__171__opcode = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__177__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__177__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__533__fail_status;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__533__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__533__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__533__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__534__Vfuncout;
    __Vfunc_memory_status_to_task__534__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__534__status;
    __Vfunc_memory_status_to_task__534__status = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__535__fail_status;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__535__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__535__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__535__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__536__Vfuncout;
    __Vfunc_memory_status_to_task__536__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__536__status;
    __Vfunc_memory_status_to_task__536__status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__537__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__537__fail_addr = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__540__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__540__fail_addr = 0;
    QData/*63:0*/ __Vfunc_wrap_to_dtype__541__Vfuncout;
    __Vfunc_wrap_to_dtype__541__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_wrap_to_dtype__541__value;
    __Vfunc_wrap_to_dtype__541__value = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__542__Vfuncout;
    __Vfunc_clip_to_dtype__542__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__542__value;
    __Vfunc_clip_to_dtype__542__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__542__dtype;
    __Vfunc_clip_to_dtype__542__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__542__minimum;
    __Vfunc_clip_to_dtype__542__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__542__maximum;
    __Vfunc_clip_to_dtype__542__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__543__Vfuncout;
    __Vfunc_dtype_min__543__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__543__dtype;
    __Vfunc_dtype_min__543__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__544__Vfuncout;
    __Vfunc_dtype_max__544__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__544__dtype;
    __Vfunc_dtype_max__544__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__545__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__545__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__545__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__545__byte_lane = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__546__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__546__fail_addr = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__549__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__549__fail_addr = 0;
    QData/*63:0*/ __Vfunc_wrap_to_dtype__550__Vfuncout;
    __Vfunc_wrap_to_dtype__550__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_wrap_to_dtype__550__value;
    __Vfunc_wrap_to_dtype__550__value = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__551__Vfuncout;
    __Vfunc_clip_to_dtype__551__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__551__value;
    __Vfunc_clip_to_dtype__551__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__551__dtype;
    __Vfunc_clip_to_dtype__551__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__551__minimum;
    __Vfunc_clip_to_dtype__551__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__551__maximum;
    __Vfunc_clip_to_dtype__551__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__552__Vfuncout;
    __Vfunc_dtype_min__552__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__552__dtype;
    __Vfunc_dtype_min__552__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__553__Vfuncout;
    __Vfunc_dtype_max__553__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__553__dtype;
    __Vfunc_dtype_max__553__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__554__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__554__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__554__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__554__byte_lane = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__555__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__555__fail_addr = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__556__Vfuncout;
    __Vfunc_clip_to_dtype__556__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__556__value;
    __Vfunc_clip_to_dtype__556__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__556__dtype;
    __Vfunc_clip_to_dtype__556__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__556__minimum;
    __Vfunc_clip_to_dtype__556__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__556__maximum;
    __Vfunc_clip_to_dtype__556__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__557__Vfuncout;
    __Vfunc_dtype_min__557__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__557__dtype;
    __Vfunc_dtype_min__557__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__558__Vfuncout;
    __Vfunc_dtype_max__558__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__558__dtype;
    __Vfunc_dtype_max__558__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__dtype;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__560__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__560__fail_addr = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__561__Vfuncout;
    __Vfunc_clip_to_dtype__561__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__561__value;
    __Vfunc_clip_to_dtype__561__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__561__dtype;
    __Vfunc_clip_to_dtype__561__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__561__minimum;
    __Vfunc_clip_to_dtype__561__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__561__maximum;
    __Vfunc_clip_to_dtype__561__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__562__Vfuncout;
    __Vfunc_dtype_min__562__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__562__dtype;
    __Vfunc_dtype_min__562__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__563__Vfuncout;
    __Vfunc_dtype_max__563__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__563__dtype;
    __Vfunc_dtype_max__563__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__dtype;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__565__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__565__fail_addr = 0;
    CData/*0:0*/ __Vfunc_fp32_less_than__566__Vfuncout;
    __Vfunc_fp32_less_than__566__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_less_than__566__lhs;
    __Vfunc_fp32_less_than__566__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_less_than__566__rhs;
    __Vfunc_fp32_less_than__566__rhs = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__567__Vfuncout;
    __Vfunc_fp32_is_nan__567__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__567__bits;
    __Vfunc_fp32_is_nan__567__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__567__unused_sign;
    __Vfunc_fp32_is_nan__567__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__568__Vfuncout;
    __Vfunc_fp32_is_nan__568__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__568__bits;
    __Vfunc_fp32_is_nan__568__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__568__unused_sign;
    __Vfunc_fp32_is_nan__568__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_equal__569__Vfuncout;
    __Vfunc_fp32_equal__569__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_equal__569__lhs;
    __Vfunc_fp32_equal__569__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_equal__569__rhs;
    __Vfunc_fp32_equal__569__rhs = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__570__Vfuncout;
    __Vfunc_fp32_is_nan__570__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__570__bits;
    __Vfunc_fp32_is_nan__570__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__570__unused_sign;
    __Vfunc_fp32_is_nan__570__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__571__Vfuncout;
    __Vfunc_fp32_is_nan__571__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__571__bits;
    __Vfunc_fp32_is_nan__571__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__571__unused_sign;
    __Vfunc_fp32_is_nan__571__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__572__Vfuncout;
    __Vfunc_fp32_is_zero__572__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_zero__572__bits;
    __Vfunc_fp32_is_zero__572__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__572__unused_sign;
    __Vfunc_fp32_is_zero__572__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__573__Vfuncout;
    __Vfunc_fp32_is_zero__573__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_zero__573__bits;
    __Vfunc_fp32_is_zero__573__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__573__unused_sign;
    __Vfunc_fp32_is_zero__573__unused_sign = 0;
    QData/*63:0*/ __Vfunc_dtype_min__574__Vfuncout;
    __Vfunc_dtype_min__574__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__574__dtype;
    __Vfunc_dtype_min__574__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__575__Vfuncout;
    __Vfunc_dtype_max__575__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__575__dtype;
    __Vfunc_dtype_max__575__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__576__Vfuncout;
    __Vfunc_clip_to_dtype__576__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__576__value;
    __Vfunc_clip_to_dtype__576__value = 0;
    CData/*1:0*/ __Vfunc_clip_to_dtype__576__dtype;
    __Vfunc_clip_to_dtype__576__dtype = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__576__minimum;
    __Vfunc_clip_to_dtype__576__minimum = 0;
    QData/*63:0*/ __Vfunc_clip_to_dtype__576__maximum;
    __Vfunc_clip_to_dtype__576__maximum = 0;
    QData/*63:0*/ __Vfunc_dtype_min__577__Vfuncout;
    __Vfunc_dtype_min__577__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_min__577__dtype;
    __Vfunc_dtype_min__577__dtype = 0;
    QData/*63:0*/ __Vfunc_dtype_max__578__Vfuncout;
    __Vfunc_dtype_max__578__Vfuncout = 0;
    CData/*1:0*/ __Vfunc_dtype_max__578__dtype;
    __Vfunc_dtype_max__578__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__579__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__579__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__dtype;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__581__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__581__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__582__fail_status;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__582__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__582__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__582__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__583__Vfuncout;
    __Vfunc_memory_status_to_task__583__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__583__status;
    __Vfunc_memory_status_to_task__583__status = 0;
    QData/*63:0*/ __Vfunc_load_element__584__Vfuncout;
    __Vfunc_load_element__584__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__584__beat;
    __Vfunc_load_element__584__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__584__byte_lane;
    __Vfunc_load_element__584__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__584__high_nibble;
    __Vfunc_load_element__584__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__584__dtype;
    __Vfunc_load_element__584__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__584__byte_value;
    __Vfunc_load_element__584__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__584__nibble_value;
    __Vfunc_load_element__584__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__584__half_value;
    __Vfunc_load_element__584__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__584__word_value;
    __Vfunc_load_element__584__word_value = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__585__fail_status;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__585__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__585__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__585__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__586__Vfuncout;
    __Vfunc_memory_status_to_task__586__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__586__status;
    __Vfunc_memory_status_to_task__586__status = 0;
    QData/*63:0*/ __Vfunc_load_element__587__Vfuncout;
    __Vfunc_load_element__587__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__587__beat;
    __Vfunc_load_element__587__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__587__byte_lane;
    __Vfunc_load_element__587__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__587__high_nibble;
    __Vfunc_load_element__587__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__587__dtype;
    __Vfunc_load_element__587__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__587__byte_value;
    __Vfunc_load_element__587__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__587__nibble_value;
    __Vfunc_load_element__587__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__587__half_value;
    __Vfunc_load_element__587__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__587__word_value;
    __Vfunc_load_element__587__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__dtype;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__589__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__589__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__590__fail_status;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__590__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__590__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__590__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__591__Vfuncout;
    __Vfunc_memory_status_to_task__591__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__591__status;
    __Vfunc_memory_status_to_task__591__status = 0;
    QData/*63:0*/ __Vfunc_load_element__592__Vfuncout;
    __Vfunc_load_element__592__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__592__beat;
    __Vfunc_load_element__592__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__592__byte_lane;
    __Vfunc_load_element__592__byte_lane = 0;
    CData/*0:0*/ __Vfunc_load_element__592__high_nibble;
    __Vfunc_load_element__592__high_nibble = 0;
    CData/*1:0*/ __Vfunc_load_element__592__dtype;
    __Vfunc_load_element__592__dtype = 0;
    CData/*7:0*/ __Vfunc_load_element__592__byte_value;
    __Vfunc_load_element__592__byte_value = 0;
    CData/*3:0*/ __Vfunc_load_element__592__nibble_value;
    __Vfunc_load_element__592__nibble_value = 0;
    SData/*15:0*/ __Vfunc_load_element__592__half_value;
    __Vfunc_load_element__592__half_value = 0;
    IData/*31:0*/ __Vfunc_load_element__592__word_value;
    __Vfunc_load_element__592__word_value = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__dtype;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__594__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__594__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__595__fail_status;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__595__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__595__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__595__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__596__Vfuncout;
    __Vfunc_memory_status_to_task__596__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__596__status;
    __Vfunc_memory_status_to_task__596__status = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__dtype;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__598__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__598__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__byte_lane = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__dtype;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__dtype = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__600__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__600__fail_addr = 0;
    CData/*7:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__601__fail_status;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__601__fail_status = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__601__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__601__fail_addr = 0;
    CData/*7:0*/ __Vfunc_memory_status_to_task__602__Vfuncout;
    __Vfunc_memory_status_to_task__602__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_memory_status_to_task__602__status;
    __Vfunc_memory_status_to_task__602__status = 0;
    QData/*63:0*/ __Vfunc_load_element__603__Vfuncout;
    __Vfunc_load_element__603__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_load_element__603__beat;
    __Vfunc_load_element__603__beat = 0;
    CData/*2:0*/ __Vfunc_load_element__603__byte_lane;
    __Vfunc_load_element__603__byte_lane = 0;
    IData/*31:0*/ __Vfunc_load_element__603__word_value;
    __Vfunc_load_element__603__word_value = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__604__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__604__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__605__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__605__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__605__byte_lane;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__605__byte_lane = 0;
    QData/*47:0*/ __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__606__fail_addr;
    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__606__fail_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__opcode_known__607__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__opcode_known__607__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__opcode_known__607__opcode;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__opcode_known__607__opcode = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__opcode;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__opcode = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__function_value;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__function_value = 0;
    CData/*0:0*/ __Vfunc_fp32_finite_positive__623__Vfuncout;
    __Vfunc_fp32_finite_positive__623__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_finite_positive__623__bits;
    __Vfunc_fp32_finite_positive__623__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_finite_positive__624__Vfuncout;
    __Vfunc_fp32_finite_positive__624__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_finite_positive__624__bits;
    __Vfunc_fp32_finite_positive__624__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_finite_positive__625__Vfuncout;
    __Vfunc_fp32_finite_positive__625__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_finite_positive__625__bits;
    __Vfunc_fp32_finite_positive__625__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_finite_positive__626__Vfuncout;
    __Vfunc_fp32_finite_positive__626__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_finite_positive__626__bits;
    __Vfunc_fp32_finite_positive__626__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_finite_positive__628__Vfuncout;
    __Vfunc_fp32_finite_positive__628__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_finite_positive__628__bits;
    __Vfunc_fp32_finite_positive__628__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_less_than__631__Vfuncout;
    __Vfunc_fp32_less_than__631__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_less_than__631__lhs;
    __Vfunc_fp32_less_than__631__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_less_than__631__rhs;
    __Vfunc_fp32_less_than__631__rhs = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__632__Vfuncout;
    __Vfunc_fp32_is_nan__632__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__632__bits;
    __Vfunc_fp32_is_nan__632__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__632__unused_sign;
    __Vfunc_fp32_is_nan__632__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__633__Vfuncout;
    __Vfunc_fp32_is_nan__633__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__633__bits;
    __Vfunc_fp32_is_nan__633__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__633__unused_sign;
    __Vfunc_fp32_is_nan__633__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_equal__634__Vfuncout;
    __Vfunc_fp32_equal__634__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_equal__634__lhs;
    __Vfunc_fp32_equal__634__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_equal__634__rhs;
    __Vfunc_fp32_equal__634__rhs = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__635__Vfuncout;
    __Vfunc_fp32_is_nan__635__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__635__bits;
    __Vfunc_fp32_is_nan__635__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__635__unused_sign;
    __Vfunc_fp32_is_nan__635__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__636__Vfuncout;
    __Vfunc_fp32_is_nan__636__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__636__bits;
    __Vfunc_fp32_is_nan__636__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__636__unused_sign;
    __Vfunc_fp32_is_nan__636__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__637__Vfuncout;
    __Vfunc_fp32_is_zero__637__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_zero__637__bits;
    __Vfunc_fp32_is_zero__637__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__637__unused_sign;
    __Vfunc_fp32_is_zero__637__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__638__Vfuncout;
    __Vfunc_fp32_is_zero__638__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_zero__638__bits;
    __Vfunc_fp32_is_zero__638__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__638__unused_sign;
    __Vfunc_fp32_is_zero__638__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__639__Vfuncout;
    __Vfunc_fp32_is_nan__639__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__639__bits;
    __Vfunc_fp32_is_nan__639__bits = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__640__Vfuncout;
    __Vfunc_fp32_is_nan__640__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_is_nan__640__bits;
    __Vfunc_fp32_is_nan__640__bits = 0;
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    VlWide<4>/*127:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<4>/*127:0*/ __Vtemp_5;
    VlWide<4>/*127:0*/ __Vtemp_6;
    VlWide<4>/*127:0*/ __Vtemp_7;
    VlWide<4>/*127:0*/ __Vtemp_8;
    VlWide<4>/*127:0*/ __Vtemp_9;
    VlWide<4>/*127:0*/ __Vtemp_10;
    // Body
    if (vlSelfRef.tb_npu_engines__DOT__reset_n) {
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__read_ready 
            = (1U & ((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_space))
                      ? ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready) 
                         >> 1U) : (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_ready)));
        if ((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_space))) {
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__rmw_ready 
                = (1U & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready) 
                         >> 1U));
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__write_ready 
                = (1U & ((IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready) 
                         >> 1U));
        } else {
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__rmw_ready 
                = (1U & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_ready));
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__write_ready 
                = (1U & (IData)(vlSelfRef.tb_npu_engines__DOT__dma_mif_req_ready));
        }
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__source_in_range 
            = ((((0ULL != vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_region_bytes) 
                 & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr 
                    >= vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_base)) 
                & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_end_addr 
                   <= (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_base 
                       + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_region_bytes))) 
               & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_end_addr 
                  >= vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr));
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__destination_in_range 
            = ((((0ULL != vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_region_bytes) 
                 & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr 
                    >= vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_base)) 
                & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_end_addr 
                   <= (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_base 
                       + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_region_bytes))) 
               & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_end_addr 
                  >= vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr));
        if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0U;
        } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0U;
            } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0U;
            } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
                if (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__write_rsp_valid) {
                    if ((0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__write_rsp_status))) {
                        __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__140__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr);
                        __Vfunc_memory_status_to_task__141__status 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__write_rsp_status;
                        __Vfunc_memory_status_to_task__141__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__141__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__141__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__141__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__140__fail_status 
                            = __Vfunc_memory_status_to_task__141__Vfuncout;
                        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__140__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q 
                            = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__140__fail_status;
                    } else {
                        if ((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype))) {
                            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_high_nibble)))) {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__progress_q 
                                    = (1ULL + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__progress_q);
                            }
                        } else {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__progress_q 
                                = (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__progress_q 
                                   + VL_EXTEND_QI(64,3, 
                                                  ([&]() {
                                            __Vfunc_dtype_bytes__142__dtype 
                                                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype;
                                            __Vfunc_dtype_bytes__142__Vfuncout 
                                                = (
                                                   (1U 
                                                    == (IData)(__Vfunc_dtype_bytes__142__dtype))
                                                    ? 1U
                                                    : 
                                                   ((2U 
                                                     == (IData)(__Vfunc_dtype_bytes__142__dtype))
                                                     ? 4U
                                                     : 
                                                    ((3U 
                                                      == (IData)(__Vfunc_dtype_bytes__142__dtype))
                                                      ? 2U
                                                      : 0U)));
                                        }(), (IData)(__Vfunc_dtype_bytes__142__Vfuncout))));
                        }
                        if (((1ULL + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q) 
                             < vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__total_units_q)) {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__linear_index_q 
                                = (1ULL + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q);
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 2U;
                        } else {
                            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 0U;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                        }
                    }
                }
            } else if (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__write_ready) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 9U;
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
                    if (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__write_rsp_valid) {
                        if ((0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__write_rsp_status))) {
                            __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__143__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr);
                            __Vfunc_memory_status_to_task__144__status 
                                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__write_rsp_status;
                            __Vfunc_memory_status_to_task__144__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__144__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__144__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__144__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__143__fail_status 
                                = __Vfunc_memory_status_to_task__144__Vfuncout;
                            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__143__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q 
                                = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__143__fail_status;
                        } else {
                            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rmw_beat_q 
                                = ((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_space))
                                    ? vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                   [1U] : vlSelfRef.tb_npu_engines__DOT__system_mem_rsp_data_q);
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 8U;
                        }
                    }
                } else if (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__rmw_ready) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__converted_value 
                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_value_q;
                if (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__verify_pass_q) {
                    if ((VL_GTS_IQQ(64, 0xfffffffffffffff8ULL, vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_value_q) 
                         | VL_LTS_IQQ(64, 7ULL, vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_value_q))) {
                        __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__145__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr);
                        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 0xcU;
                        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__145__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                    } else if (((1ULL + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q) 
                                < vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__total_units_q)) {
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__linear_index_q 
                            = (1ULL + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q);
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 2U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__linear_index_q = 0ULL;
                        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__verify_pass_q = 0U;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 2U;
                    }
                } else {
                    if ((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__convert_mode))) {
                        __Vfunc_clip_to_dtype__146__dtype 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype;
                        __Vfunc_clip_to_dtype__146__value 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_value_q;
                        __Vfunc_clip_to_dtype__146__minimum = 0;
                        __Vfunc_clip_to_dtype__146__maximum = 0;
                        {
                            __Vfunc_dtype_min__147__dtype 
                                = __Vfunc_clip_to_dtype__146__dtype;
                            __Vfunc_dtype_min__147__Vfuncout 
                                = ((2U & (IData)(__Vfunc_dtype_min__147__dtype))
                                    ? ((1U & (IData)(__Vfunc_dtype_min__147__dtype))
                                        ? 0xffffffffffff8000ULL
                                        : 0xffffffff80000000ULL)
                                    : ((1U & (IData)(__Vfunc_dtype_min__147__dtype))
                                        ? 0xffffffffffffff80ULL
                                        : 0xfffffffffffffff8ULL));
                            __Vfunc_clip_to_dtype__146__minimum 
                                = __Vfunc_dtype_min__147__Vfuncout;
                            __Vfunc_dtype_max__148__dtype 
                                = __Vfunc_clip_to_dtype__146__dtype;
                            __Vfunc_dtype_max__148__Vfuncout 
                                = ((2U & (IData)(__Vfunc_dtype_max__148__dtype))
                                    ? ((1U & (IData)(__Vfunc_dtype_max__148__dtype))
                                        ? 0x7fffULL
                                        : 0x7fffffffULL)
                                    : ((1U & (IData)(__Vfunc_dtype_max__148__dtype))
                                        ? 0x7fULL : 7ULL));
                            __Vfunc_clip_to_dtype__146__maximum 
                                = __Vfunc_dtype_max__148__Vfuncout;
                            if (VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__146__value, __Vfunc_clip_to_dtype__146__minimum)) {
                                __Vfunc_clip_to_dtype__146__Vfuncout 
                                    = __Vfunc_clip_to_dtype__146__minimum;
                                goto __Vlabel0;
                            }
                            if (VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__146__value, __Vfunc_clip_to_dtype__146__maximum)) {
                                __Vfunc_clip_to_dtype__146__Vfuncout 
                                    = __Vfunc_clip_to_dtype__146__maximum;
                                goto __Vlabel0;
                            }
                            __Vfunc_clip_to_dtype__146__Vfuncout 
                                = __Vfunc_clip_to_dtype__146__value;
                            __Vlabel0: ;
                        }
                        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__converted_value 
                            = __Vfunc_clip_to_dtype__146__Vfuncout;
                    }
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__result_q 
                        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__converted_value;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rmw_beat_q = 0ULL;
                    if ((((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype)) 
                          & (4U < (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr)))) 
                         | ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype)) 
                            & (6U < (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr)))))) {
                        __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__149__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr);
                        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 4U;
                        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__149__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q 
                            = (((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype)) 
                                & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_high_nibble))
                                ? 6U : 8U);
                    }
                }
            } else if (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__read_rsp_valid) {
                if ((0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__read_rsp_status))) {
                    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__150__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr);
                    __Vfunc_memory_status_to_task__151__status 
                        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__read_rsp_status;
                    __Vfunc_memory_status_to_task__151__Vfuncout 
                        = ((0U == (IData)(__Vfunc_memory_status_to_task__151__status))
                            ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__151__status))
                                     ? 6U : ((2U == (IData)(__Vfunc_memory_status_to_task__151__status))
                                              ? 5U : 4U)));
                    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__150__fail_status 
                        = __Vfunc_memory_status_to_task__151__Vfuncout;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q 
                        = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__150__fail_status;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__150__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else {
                    __Vfunc_load_element__152__dtype 
                        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_src_dtype;
                    __Vfunc_load_element__152__high_nibble 
                        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_high_nibble;
                    __Vfunc_load_element__152__byte_lane 
                        = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr));
                    __Vfunc_load_element__152__beat 
                        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__read_rsp_data;
                    __Vfunc_load_element__152__byte_value 
                        = (0xffU & (IData)((__Vfunc_load_element__152__beat 
                                            >> (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__152__byte_lane), 3U)))));
                    __Vfunc_load_element__152__nibble_value 
                        = (0xfU & ((IData)(__Vfunc_load_element__152__high_nibble)
                                    ? ((IData)(__Vfunc_load_element__152__byte_value) 
                                       >> 4U) : (IData)(__Vfunc_load_element__152__byte_value)));
                    __Vfunc_load_element__152__half_value 
                        = (0xffffU & (IData)((__Vfunc_load_element__152__beat 
                                              >> (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__152__byte_lane), 3U)))));
                    __Vfunc_load_element__152__word_value 
                        = (IData)((__Vfunc_load_element__152__beat 
                                   >> (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__152__byte_lane), 3U))));
                    __Vfunc_load_element__152__Vfuncout 
                        = ((2U & (IData)(__Vfunc_load_element__152__dtype))
                            ? ((1U & (IData)(__Vfunc_load_element__152__dtype))
                                ? (((- (QData)((IData)(
                                                       (1U 
                                                        & ((IData)(__Vfunc_load_element__152__half_value) 
                                                           >> 0xfU))))) 
                                    << 0x10U) | (QData)((IData)(__Vfunc_load_element__152__half_value)))
                                : (((QData)((IData)(
                                                    (- (IData)(
                                                               (__Vfunc_load_element__152__word_value 
                                                                >> 0x1fU))))) 
                                    << 0x20U) | (QData)((IData)(__Vfunc_load_element__152__word_value))))
                            : ((1U & (IData)(__Vfunc_load_element__152__dtype))
                                ? (((- (QData)((IData)(
                                                       (1U 
                                                        & ((IData)(__Vfunc_load_element__152__byte_value) 
                                                           >> 7U))))) 
                                    << 8U) | (QData)((IData)(__Vfunc_load_element__152__byte_value)))
                                : (((- (QData)((IData)(
                                                       (1U 
                                                        & ((IData)(__Vfunc_load_element__152__nibble_value) 
                                                           >> 3U))))) 
                                    << 4U) | (QData)((IData)(__Vfunc_load_element__152__nibble_value)))));
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_value_q 
                        = __Vfunc_load_element__152__Vfuncout;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 5U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
                if (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__read_ready) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 4U;
                }
            } else {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rmw_beat_q = 0ULL;
                if (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__destination_in_range) {
                    if ((0x22U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q))) {
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__dtype 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype;
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__value 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fill_value;
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__Vfuncout 
                            = ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__dtype))
                                ? (((- (QData)((IData)(
                                                       (1U 
                                                        & (__Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__value 
                                                           >> 3U))))) 
                                    << 4U) | (QData)((IData)(
                                                             (0xfU 
                                                              & __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__value))))
                                : ((1U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & (__Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__value 
                                                               >> 7U))))) 
                                        << 8U) | (QData)((IData)(
                                                                 (0xffU 
                                                                  & __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__value))))
                                    : ((3U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & (__Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__value 
                                                                   >> 0xfU))))) 
                                            << 0x10U) 
                                           | (QData)((IData)(
                                                             (0xffffU 
                                                              & __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__value))))
                                        : (((QData)((IData)(
                                                            (- (IData)(
                                                                       (__Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__value 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__value))))));
                        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__result_q 
                            = __Vfunc_tb_npu_engines__DOT__u_dma__DOT__fill_as_integer__153__Vfuncout;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q 
                            = (((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype)) 
                                & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_high_nibble))
                                ? 6U : 8U);
                    } else if (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__source_in_range) {
                        if ((((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_src_dtype)) 
                              & (4U < (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr)))) 
                             | ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_src_dtype)) 
                                & (6U < (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr)))))) {
                            __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__154__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr);
                            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 4U;
                            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__154__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                        } else {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 3U;
                        }
                    } else {
                        __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__155__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr);
                        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 4U;
                        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__155__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                    }
                } else {
                    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__156__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr);
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__156__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__computed_total 
                = (([&]() {
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__157__opcode 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q;
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__157__Vfuncout 
                            = ((0x24U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__157__opcode)) 
                               | (0x25U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__157__opcode)));
                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__157__Vfuncout))
                    ? ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__segment_count)) 
                       * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__segment_bytes)))
                    : ([&]() {
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__shapes[0U] 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__shape_packed[0U];
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__shapes[1U] 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__shape_packed[1U];
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__shapes[2U] 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__shape_packed[2U];
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__shapes[3U] 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__shape_packed[3U];
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__shapes[4U] 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__shape_packed[4U];
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__rank_value 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rank;
                        VL_ZERO_W(128, __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product);
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__dimension = 0;
                        {
                            __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[0U] = 1U;
                            __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[1U] = 0U;
                            __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[2U] = 0U;
                            __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[3U] = 0U;
                            __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__dimension = 0U;
                            if ((0U < (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__rank_value))) {
                                __Vtemp_2[0U] = __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__shapes[0U];
                                __Vtemp_2[1U] = 0U;
                                __Vtemp_2[2U] = 0U;
                                __Vtemp_2[3U] = 0U;
                                VL_MUL_W(4, __Vtemp_1, __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product, __Vtemp_2);
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[0U] 
                                    = __Vtemp_1[0U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[1U] 
                                    = __Vtemp_1[1U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[2U] 
                                    = __Vtemp_1[2U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[3U] 
                                    = __Vtemp_1[3U];
                            }
                            __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__dimension = 1U;
                            if ((1U < (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__rank_value))) {
                                __Vtemp_4[0U] = __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__shapes[1U];
                                __Vtemp_4[1U] = 0U;
                                __Vtemp_4[2U] = 0U;
                                __Vtemp_4[3U] = 0U;
                                VL_MUL_W(4, __Vtemp_3, __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product, __Vtemp_4);
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[0U] 
                                    = __Vtemp_3[0U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[1U] 
                                    = __Vtemp_3[1U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[2U] 
                                    = __Vtemp_3[2U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[3U] 
                                    = __Vtemp_3[3U];
                            }
                            __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__dimension = 2U;
                            if ((2U < (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__rank_value))) {
                                __Vtemp_6[0U] = __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__shapes[2U];
                                __Vtemp_6[1U] = 0U;
                                __Vtemp_6[2U] = 0U;
                                __Vtemp_6[3U] = 0U;
                                VL_MUL_W(4, __Vtemp_5, __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product, __Vtemp_6);
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[0U] 
                                    = __Vtemp_5[0U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[1U] 
                                    = __Vtemp_5[1U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[2U] 
                                    = __Vtemp_5[2U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[3U] 
                                    = __Vtemp_5[3U];
                            }
                            __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__dimension = 3U;
                            if ((3U < (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__rank_value))) {
                                __Vtemp_8[0U] = __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__shapes[3U];
                                __Vtemp_8[1U] = 0U;
                                __Vtemp_8[2U] = 0U;
                                __Vtemp_8[3U] = 0U;
                                VL_MUL_W(4, __Vtemp_7, __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product, __Vtemp_8);
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[0U] 
                                    = __Vtemp_7[0U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[1U] 
                                    = __Vtemp_7[1U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[2U] 
                                    = __Vtemp_7[2U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[3U] 
                                    = __Vtemp_7[3U];
                            }
                            __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__dimension = 4U;
                            if ((4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__rank_value))) {
                                __Vtemp_10[0U] = __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__shapes[4U];
                                __Vtemp_10[1U] = 0U;
                                __Vtemp_10[2U] = 0U;
                                __Vtemp_10[3U] = 0U;
                                VL_MUL_W(4, __Vtemp_9, __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product, __Vtemp_10);
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[0U] 
                                    = __Vtemp_9[0U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[1U] 
                                    = __Vtemp_9[1U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[2U] 
                                    = __Vtemp_9[2U];
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[3U] 
                                    = __Vtemp_9[3U];
                            }
                            __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__dimension = 5U;
                            if ((0ULL != (((QData)((IData)(
                                                           __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[3U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[2U]))))) {
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__Vfuncout = 0xffffffffffffffffULL;
                                goto __Vlabel1;
                            }
                            __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__Vfuncout 
                                = (((QData)((IData)(
                                                    __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__product[0U])));
                            __Vlabel1: ;
                        }
                    }(), __Vfunc_tb_npu_engines__DOT__u_dma__DOT__shape_product__158__Vfuncout));
            if (([&]() {
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__opcode 
                            = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q;
                        __Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__Vfuncout 
                            = ((((((0x20U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__opcode)) 
                                   || (0x21U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__opcode))) 
                                  || (0x22U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__opcode))) 
                                 || (0x23U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__opcode))) 
                                || (0x24U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__opcode))) 
                               || (0x25U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__opcode)));
                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__opcode_known__159__Vfuncout))) {
                if ((((1U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_version)) 
                      | (1U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_type))) 
                     | (0x100U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_bytes)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if ((IData)((0U != (0xfffe0300U 
                                           & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__numeric_cfg)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if ((IData)(((0U != (0xfefe0000U 
                                            & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x11U])) 
                                    | ((((((((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rank)) 
                                             | (5U 
                                                < (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rank))) 
                                            | (1U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_space))) 
                                           | (1U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_space))) 
                                          | (3U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__convert_mode))) 
                                         | (0xfU < (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__burst_beats_minus1))) 
                                        | (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__max_outstanding))) 
                                       | (0x10U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__max_outstanding)))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_nibble) {
                    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__167__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_base);
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__167__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if (((((((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_space)) 
                                & (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_base 
                                            >> 0x14U))) 
                               & (0x22U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q))) 
                              | (((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_space)) 
                                  & (0U != (0xffffU 
                                            & (IData)(
                                                      (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_base 
                                                       >> 0x30U))))) 
                                 & (0x22U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q)))) 
                             | ((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_space)) 
                                & (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_base 
                                            >> 0x14U)))) 
                            | ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_space)) 
                               & (0U != (0xffffU & (IData)(
                                                           (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_base 
                                                            >> 0x30U))))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if (((0x20U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q)) 
                            & (1U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rank)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if (((0x23U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q)) 
                            & (((2U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rank)) 
                                | ((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype) 
                                   != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype))) 
                               | (0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__convert_mode))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if ((([&]() {
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__171__opcode 
                                    = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q;
                                __Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__171__Vfuncout 
                                    = ((0x24U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__171__opcode)) 
                                       | (0x25U == (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__171__opcode)));
                            }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_dma__DOT__byte_mode__171__Vfuncout)) 
                            & (((((((1U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rank)) 
                                    | (0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__convert_mode))) 
                                   | ((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype) 
                                      != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype))) 
                                  | (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__segment_count))) 
                                 | (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__segment_bytes))) 
                                | (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__segment_stride 
                                   < (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__segment_bytes))) 
                               | (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__shape_packed[0U] 
                                  != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__segment_count))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if (((0x22U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q)) 
                            & (0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__convert_mode)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if (((0x22U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q)) 
                            & (((((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__convert_mode)) 
                                  & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype) 
                                     != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype))) 
                                 | ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__convert_mode)) 
                                    & (~ ((((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype)) 
                                            & (((1U 
                                                 == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype)) 
                                                | (3U 
                                                   == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype))) 
                                               | (2U 
                                                  == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype)))) 
                                           | ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype)) 
                                              & ((3U 
                                                  == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype)) 
                                                 | (2U 
                                                    == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype))))) 
                                          | ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype)) 
                                             & (2U 
                                                == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype))))))) 
                                | ((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__convert_mode)) 
                                   & (~ ((((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype)) 
                                           & (((3U 
                                                == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype)) 
                                               | (1U 
                                                  == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype))) 
                                              | (0U 
                                                 == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype)))) 
                                          | ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype)) 
                                             & ((1U 
                                                 == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype)) 
                                                | (0U 
                                                   == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype))))) 
                                         | ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype)) 
                                            & (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype))))))) 
                               | ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__convert_mode)) 
                                  & (~ ((((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype)) 
                                          | (3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype))) 
                                         | (2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype))) 
                                        & (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype)))))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if ((0xffffffffffffffffULL == vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__computed_total)) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if ((0ULL == vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__computed_total)) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if (((0ULL == vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_region_bytes) 
                            | ((0x22U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q)) 
                               & (0ULL == vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_region_bytes)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else if (((((0x22U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q)) 
                              & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_space) 
                                 == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_space))) 
                             & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_base 
                                < (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_base 
                                   + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_region_bytes))) 
                            & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_base 
                               < (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_base 
                                  + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_region_bytes)))) {
                    __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__177__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_base);
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 0xdU;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_dma__DOT__fail_task__177__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
                } else {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__total_units_q 
                        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__unnamedblk1__DOT__computed_total;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__linear_index_q = 0ULL;
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__verify_pass_q 
                        = ((0x22U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q)) 
                           & (3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__convert_mode)));
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 2U;
                }
            } else {
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 1U;
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0xaU;
            }
        } else {
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 0U;
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__progress_q = 0ULL;
            if (vlSelfRef.tb_npu_engines__DOT__dma_task_valid) {
                IData/*31:0*/ __Vilp1;
                __Vilp1 = 0U;
                while ((__Vilp1 <= 0x3fU)) {
                    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[__Vilp1] 
                        = vlSelfRef.tb_npu_engines__DOT__dma_desc[__Vilp1];
                    __Vilp1 = ((IData)(1U) + __Vilp1);
                }
                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q 
                    = vlSelfRef.tb_npu_engines__DOT__dma_opcode;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 1U;
            }
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__state_q = 0U;
        IData/*31:0*/ __Vilp2;
        __Vilp2 = 0U;
        while ((__Vilp2 <= 0x3fU)) {
            vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[__Vilp2] 
                = Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0[__Vilp2];
            __Vilp2 = ((IData)(1U) + __Vilp2);
        }
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__opcode_q = 0U;
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__linear_index_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__total_units_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__verify_pass_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_value_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__result_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rmw_beat_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__status_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fault_addr_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_dma__DOT__progress_q = 0ULL;
    }
    if (vlSelfRef.tb_npu_engines__DOT__reset_n) {
        if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0U;
            } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0U;
            } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                             [4U])) {
                            __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__533__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr);
                            __Vfunc_memory_status_to_task__534__status 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                                [4U];
                            __Vfunc_memory_status_to_task__534__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__534__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__534__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__534__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__533__fail_status 
                                = __Vfunc_memory_status_to_task__534__Vfuncout;
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__533__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q 
                                = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__533__fail_status;
                        } else {
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__progress_q 
                                = (1ULL + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__progress_q);
                            if ((7U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                                if ((((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q) 
                                     < vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__rows)) {
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__row_q 
                                        = ((IData)(1U) 
                                           + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q);
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 2U;
                                } else {
                                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 0U;
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                                }
                            } else if ((((IData)(1U) 
                                         + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q) 
                                        < vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__active_columns)) {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__col_q 
                                    = ((IData)(1U) 
                                       + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q);
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 5U;
                            } else if ((((IData)(1U) 
                                         + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q) 
                                        < vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__rows)) {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__row_q 
                                    = ((IData)(1U) 
                                       + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q);
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 2U;
                            } else {
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 0U;
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x13U;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                         [4U])) {
                        __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__535__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr);
                        __Vfunc_memory_status_to_task__536__status 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                            [4U];
                        __Vfunc_memory_status_to_task__536__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__536__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__536__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__536__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__535__fail_status 
                            = __Vfunc_memory_status_to_task__536__Vfuncout;
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__535__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q 
                            = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__535__fail_status;
                    } else {
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__rmw_beat_q 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                            [4U];
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x12U;
                    }
                }
            } else if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x11U;
            }
        } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                        if ((((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q) 
                             < vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__active_columns)) {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__col_q 
                                = ((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q);
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 5U;
                        } else {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__col_q = 0U;
                            if ((1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                                if (((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_seen_q)) 
                                     & (1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__all_mask_mode)))) {
                                    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__537__fail_addr 
                                        = (0xffffffffffffULL 
                                           & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_base);
                                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 0xcU;
                                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                        = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__537__fail_addr;
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                                } else {
                                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_q = 0U;
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__phase_q 
                                        = ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_seen_q)
                                            ? 2U : 3U);
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 5U;
                                }
                            } else if ((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__phase_q = 3U;
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 5U;
                            } else if ((4U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_mean_q 
                                    = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_mean;
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_invstd_q 
                                    = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_result;
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__phase_q = 5U;
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 5U;
                            } else {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 5U;
                            }
                        }
                    } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                        if ((7U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__function_mode)) {
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat 
                                = (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_sum_q 
                                   + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q);
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_sum_q 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat;
                        } else if ((8U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__function_mode)) {
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat 
                                = (((0U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q) 
                                    | VL_GTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_max_q))
                                    ? vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q
                                    : vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_max_q);
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_max_q 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat;
                        } else {
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat 
                                = (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_sumsq_q 
                                   + VL_MULS_QQQ(64, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q));
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_sumsq_q 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat;
                        }
                        if ((((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q) 
                             == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__active_columns)) {
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_overflow 
                                = (VL_GTS_IQQ(64, 0xffffffff80000000ULL, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat) 
                                   | VL_LTS_IQQ(64, 0x7fffffffULL, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat));
                            if (((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_overflow) 
                                 & (1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__overflow_mode)))) {
                                __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__540__fail_addr 
                                    = (0xffffffffffffULL 
                                       & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_dst_addr);
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 0xcU;
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                    = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__540__fail_addr;
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                            } else {
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__result_q 
                                    = ((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__overflow_mode))
                                        ? ([&]() {
                                            __Vfunc_wrap_to_dtype__541__value 
                                                = (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat);
                                            __Vfunc_wrap_to_dtype__541__Vfuncout 
                                                = (
                                                   ((QData)((IData)(
                                                                    (- (IData)(
                                                                               (__Vfunc_wrap_to_dtype__541__value 
                                                                                >> 0x1fU))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(__Vfunc_wrap_to_dtype__541__value)));
                                        }(), __Vfunc_wrap_to_dtype__541__Vfuncout)
                                        : ([&]() {
                                            __Vfunc_clip_to_dtype__542__dtype = 2U;
                                            __Vfunc_clip_to_dtype__542__value 
                                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat;
                                            __Vfunc_clip_to_dtype__542__minimum = 0;
                                            __Vfunc_clip_to_dtype__542__maximum = 0;
                                            {
                                                __Vfunc_dtype_min__543__dtype 
                                                    = __Vfunc_clip_to_dtype__542__dtype;
                                                __Vfunc_dtype_min__543__Vfuncout 
                                                    = 
                                                    ((2U 
                                                      & (IData)(__Vfunc_dtype_min__543__dtype))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(__Vfunc_dtype_min__543__dtype))
                                                       ? 0xffffffffffff8000ULL
                                                       : 0xffffffff80000000ULL)
                                                      : 
                                                     ((1U 
                                                       & (IData)(__Vfunc_dtype_min__543__dtype))
                                                       ? 0xffffffffffffff80ULL
                                                       : 0xfffffffffffffff8ULL));
                                                __Vfunc_clip_to_dtype__542__minimum 
                                                    = __Vfunc_dtype_min__543__Vfuncout;
                                                __Vfunc_dtype_max__544__dtype 
                                                    = __Vfunc_clip_to_dtype__542__dtype;
                                                __Vfunc_dtype_max__544__Vfuncout 
                                                    = 
                                                    ((2U 
                                                      & (IData)(__Vfunc_dtype_max__544__dtype))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(__Vfunc_dtype_max__544__dtype))
                                                       ? 0x7fffULL
                                                       : 0x7fffffffULL)
                                                      : 
                                                     ((1U 
                                                       & (IData)(__Vfunc_dtype_max__544__dtype))
                                                       ? 0x7fULL
                                                       : 7ULL));
                                                __Vfunc_clip_to_dtype__542__maximum 
                                                    = __Vfunc_dtype_max__544__Vfuncout;
                                                if (
                                                    VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__542__value, __Vfunc_clip_to_dtype__542__minimum)) {
                                                    __Vfunc_clip_to_dtype__542__Vfuncout 
                                                        = __Vfunc_clip_to_dtype__542__minimum;
                                                    goto __Vlabel2;
                                                }
                                                if (
                                                    VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__542__value, __Vfunc_clip_to_dtype__542__maximum)) {
                                                    __Vfunc_clip_to_dtype__542__Vfuncout 
                                                        = __Vfunc_clip_to_dtype__542__maximum;
                                                    goto __Vlabel2;
                                                }
                                                __Vfunc_clip_to_dtype__542__Vfuncout 
                                                    = __Vfunc_clip_to_dtype__542__value;
                                                __Vlabel2: ;
                                            }
                                        }(), __Vfunc_clip_to_dtype__542__Vfuncout));
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__phase_q = 7U;
                                if (([&]() {
                                            __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__545__byte_lane 
                                                = (7U 
                                                   & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_dst_addr));
                                            __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__545__Vfuncout 
                                                = (4U 
                                                   < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__545__byte_lane));
                                        }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__545__Vfuncout))) {
                                    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__546__fail_addr 
                                        = (0xffffffffffffULL 
                                           & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_dst_addr);
                                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 4U;
                                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                        = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__546__fail_addr;
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                                } else {
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x12U;
                                }
                            }
                        } else {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xfU;
                        }
                    } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                        if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                            if ((7U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__function_mode)) {
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat 
                                    = (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_sum_q 
                                       + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q);
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_sum_q 
                                    = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat;
                            } else if ((8U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__function_mode)) {
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat 
                                    = (((0U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q) 
                                        | VL_GTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_max_q))
                                        ? vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q
                                        : vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_max_q);
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_max_q 
                                    = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat;
                            } else {
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat 
                                    = (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_sumsq_q 
                                       + VL_MULS_QQQ(64, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q));
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_sumsq_q 
                                    = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat;
                            }
                            if ((((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q) 
                                 == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__active_columns)) {
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_overflow 
                                    = (VL_GTS_IQQ(64, 0xffffffff80000000ULL, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat) 
                                       | VL_LTS_IQQ(64, 0x7fffffffULL, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat));
                                if (((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_overflow) 
                                     & (1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__overflow_mode)))) {
                                    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__549__fail_addr 
                                        = (0xffffffffffffULL 
                                           & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_dst_addr);
                                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 0xcU;
                                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                        = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__549__fail_addr;
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                                } else {
                                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__result_q 
                                        = ((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__overflow_mode))
                                            ? ([&]() {
                                                __Vfunc_wrap_to_dtype__550__value 
                                                    = (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat);
                                                __Vfunc_wrap_to_dtype__550__Vfuncout 
                                                    = 
                                                    (((QData)((IData)(
                                                                      (- (IData)(
                                                                                (__Vfunc_wrap_to_dtype__550__value 
                                                                                >> 0x1fU))))) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(__Vfunc_wrap_to_dtype__550__value)));
                                            }(), __Vfunc_wrap_to_dtype__550__Vfuncout)
                                            : ([&]() {
                                                __Vfunc_clip_to_dtype__551__dtype = 2U;
                                                __Vfunc_clip_to_dtype__551__value 
                                                    = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__next_stat;
                                                __Vfunc_clip_to_dtype__551__minimum = 0;
                                                __Vfunc_clip_to_dtype__551__maximum = 0;
                                                {
                                                    __Vfunc_dtype_min__552__dtype 
                                                        = __Vfunc_clip_to_dtype__551__dtype;
                                                    __Vfunc_dtype_min__552__Vfuncout 
                                                        = 
                                                        ((2U 
                                                          & (IData)(__Vfunc_dtype_min__552__dtype))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(__Vfunc_dtype_min__552__dtype))
                                                           ? 0xffffffffffff8000ULL
                                                           : 0xffffffff80000000ULL)
                                                          : 
                                                         ((1U 
                                                           & (IData)(__Vfunc_dtype_min__552__dtype))
                                                           ? 0xffffffffffffff80ULL
                                                           : 0xfffffffffffffff8ULL));
                                                    __Vfunc_clip_to_dtype__551__minimum 
                                                        = __Vfunc_dtype_min__552__Vfuncout;
                                                    __Vfunc_dtype_max__553__dtype 
                                                        = __Vfunc_clip_to_dtype__551__dtype;
                                                    __Vfunc_dtype_max__553__Vfuncout 
                                                        = 
                                                        ((2U 
                                                          & (IData)(__Vfunc_dtype_max__553__dtype))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(__Vfunc_dtype_max__553__dtype))
                                                           ? 0x7fffULL
                                                           : 0x7fffffffULL)
                                                          : 
                                                         ((1U 
                                                           & (IData)(__Vfunc_dtype_max__553__dtype))
                                                           ? 0x7fULL
                                                           : 7ULL));
                                                    __Vfunc_clip_to_dtype__551__maximum 
                                                        = __Vfunc_dtype_max__553__Vfuncout;
                                                    if (
                                                        VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__551__value, __Vfunc_clip_to_dtype__551__minimum)) {
                                                        __Vfunc_clip_to_dtype__551__Vfuncout 
                                                            = __Vfunc_clip_to_dtype__551__minimum;
                                                        goto __Vlabel3;
                                                    }
                                                    if (
                                                        VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__551__value, __Vfunc_clip_to_dtype__551__maximum)) {
                                                        __Vfunc_clip_to_dtype__551__Vfuncout 
                                                            = __Vfunc_clip_to_dtype__551__maximum;
                                                        goto __Vlabel3;
                                                    }
                                                    __Vfunc_clip_to_dtype__551__Vfuncout 
                                                        = __Vfunc_clip_to_dtype__551__value;
                                                    __Vlabel3: ;
                                                }
                                            }(), __Vfunc_clip_to_dtype__551__Vfuncout));
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__phase_q = 7U;
                                    if (([&]() {
                                                __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__554__byte_lane 
                                                    = 
                                                    (7U 
                                                     & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_dst_addr));
                                                __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__554__Vfuncout 
                                                    = 
                                                    (4U 
                                                     < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__554__byte_lane));
                                            }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__554__Vfuncout))) {
                                        __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__555__fail_addr 
                                            = (0xffffffffffffULL 
                                               & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_dst_addr);
                                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 4U;
                                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                            = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__555__fail_addr;
                                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                                    } else {
                                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x12U;
                                    }
                                }
                            } else {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xfU;
                            }
                        } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_integer 
                                = (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__f2i_result 
                                   + (((QData)((IData)(
                                                       (- (IData)(
                                                                  (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_zero_point 
                                                                   >> 0x1fU))))) 
                                       << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_zero_point))));
                            __Vfunc_clip_to_dtype__556__dtype 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype;
                            __Vfunc_clip_to_dtype__556__value 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_integer;
                            __Vfunc_clip_to_dtype__556__minimum = 0;
                            __Vfunc_clip_to_dtype__556__maximum = 0;
                            {
                                __Vfunc_dtype_min__557__dtype 
                                    = __Vfunc_clip_to_dtype__556__dtype;
                                __Vfunc_dtype_min__557__Vfuncout 
                                    = ((2U & (IData)(__Vfunc_dtype_min__557__dtype))
                                        ? ((1U & (IData)(__Vfunc_dtype_min__557__dtype))
                                            ? 0xffffffffffff8000ULL
                                            : 0xffffffff80000000ULL)
                                        : ((1U & (IData)(__Vfunc_dtype_min__557__dtype))
                                            ? 0xffffffffffffff80ULL
                                            : 0xfffffffffffffff8ULL));
                                __Vfunc_clip_to_dtype__556__minimum 
                                    = __Vfunc_dtype_min__557__Vfuncout;
                                __Vfunc_dtype_max__558__dtype 
                                    = __Vfunc_clip_to_dtype__556__dtype;
                                __Vfunc_dtype_max__558__Vfuncout 
                                    = ((2U & (IData)(__Vfunc_dtype_max__558__dtype))
                                        ? ((1U & (IData)(__Vfunc_dtype_max__558__dtype))
                                            ? 0x7fffULL
                                            : 0x7fffffffULL)
                                        : ((1U & (IData)(__Vfunc_dtype_max__558__dtype))
                                            ? 0x7fULL
                                            : 7ULL));
                                __Vfunc_clip_to_dtype__556__maximum 
                                    = __Vfunc_dtype_max__558__Vfuncout;
                                if (VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__556__value, __Vfunc_clip_to_dtype__556__minimum)) {
                                    __Vfunc_clip_to_dtype__556__Vfuncout 
                                        = __Vfunc_clip_to_dtype__556__minimum;
                                    goto __Vlabel4;
                                }
                                if (VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__556__value, __Vfunc_clip_to_dtype__556__maximum)) {
                                    __Vfunc_clip_to_dtype__556__Vfuncout 
                                        = __Vfunc_clip_to_dtype__556__maximum;
                                    goto __Vlabel4;
                                }
                                __Vfunc_clip_to_dtype__556__Vfuncout 
                                    = __Vfunc_clip_to_dtype__556__value;
                                __Vlabel4: ;
                            }
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__result_q 
                                = __Vfunc_clip_to_dtype__556__Vfuncout;
                            if (([&]() {
                                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__dtype 
                                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype;
                                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__byte_lane 
                                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr));
                                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__Vfuncout 
                                            = (((2U 
                                                 == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__dtype)) 
                                                & (4U 
                                                   < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__byte_lane))) 
                                               | ((3U 
                                                   == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__dtype)) 
                                                  & (6U 
                                                     < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__byte_lane))));
                                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__559__Vfuncout))) {
                                __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__560__fail_addr 
                                    = (0xffffffffffffULL 
                                       & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr);
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 4U;
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                    = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__560__fail_addr;
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                            } else {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q 
                                    = (((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype)) 
                                        & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_high_nibble))
                                        ? 0x10U : 0x12U);
                            }
                        } else {
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_q 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_plus_x;
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sumsq_q 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sumsq_plus_x_squared;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xfU;
                        }
                    } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                        if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_integer 
                                = (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__f2i_result 
                                   + (((QData)((IData)(
                                                       (- (IData)(
                                                                  (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_zero_point 
                                                                   >> 0x1fU))))) 
                                       << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_zero_point))));
                            __Vfunc_clip_to_dtype__561__dtype 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype;
                            __Vfunc_clip_to_dtype__561__value 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_integer;
                            __Vfunc_clip_to_dtype__561__minimum = 0;
                            __Vfunc_clip_to_dtype__561__maximum = 0;
                            {
                                __Vfunc_dtype_min__562__dtype 
                                    = __Vfunc_clip_to_dtype__561__dtype;
                                __Vfunc_dtype_min__562__Vfuncout 
                                    = ((2U & (IData)(__Vfunc_dtype_min__562__dtype))
                                        ? ((1U & (IData)(__Vfunc_dtype_min__562__dtype))
                                            ? 0xffffffffffff8000ULL
                                            : 0xffffffff80000000ULL)
                                        : ((1U & (IData)(__Vfunc_dtype_min__562__dtype))
                                            ? 0xffffffffffffff80ULL
                                            : 0xfffffffffffffff8ULL));
                                __Vfunc_clip_to_dtype__561__minimum 
                                    = __Vfunc_dtype_min__562__Vfuncout;
                                __Vfunc_dtype_max__563__dtype 
                                    = __Vfunc_clip_to_dtype__561__dtype;
                                __Vfunc_dtype_max__563__Vfuncout 
                                    = ((2U & (IData)(__Vfunc_dtype_max__563__dtype))
                                        ? ((1U & (IData)(__Vfunc_dtype_max__563__dtype))
                                            ? 0x7fffULL
                                            : 0x7fffffffULL)
                                        : ((1U & (IData)(__Vfunc_dtype_max__563__dtype))
                                            ? 0x7fULL
                                            : 7ULL));
                                __Vfunc_clip_to_dtype__561__maximum 
                                    = __Vfunc_dtype_max__563__Vfuncout;
                                if (VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__561__value, __Vfunc_clip_to_dtype__561__minimum)) {
                                    __Vfunc_clip_to_dtype__561__Vfuncout 
                                        = __Vfunc_clip_to_dtype__561__minimum;
                                    goto __Vlabel5;
                                }
                                if (VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__561__value, __Vfunc_clip_to_dtype__561__maximum)) {
                                    __Vfunc_clip_to_dtype__561__Vfuncout 
                                        = __Vfunc_clip_to_dtype__561__maximum;
                                    goto __Vlabel5;
                                }
                                __Vfunc_clip_to_dtype__561__Vfuncout 
                                    = __Vfunc_clip_to_dtype__561__value;
                                __Vlabel5: ;
                            }
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__result_q 
                                = __Vfunc_clip_to_dtype__561__Vfuncout;
                            if (([&]() {
                                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__dtype 
                                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype;
                                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__byte_lane 
                                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr));
                                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__Vfuncout 
                                            = (((2U 
                                                 == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__dtype)) 
                                                & (4U 
                                                   < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__byte_lane))) 
                                               | ((3U 
                                                   == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__dtype)) 
                                                  & (6U 
                                                     < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__byte_lane))));
                                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__564__Vfuncout))) {
                                __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__565__fail_addr 
                                    = (0xffffffffffffULL 
                                       & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr);
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 4U;
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                    = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__565__fail_addr;
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                            } else {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q 
                                    = (((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype)) 
                                        & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_high_nibble))
                                        ? 0x10U : 0x12U);
                            }
                        } else {
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_q 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_soft_sum_plus_exp;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xfU;
                        }
                    } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_seen_q)) 
                                   | ([&]() {
                                            __Vfunc_fp32_less_than__566__rhs 
                                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
                                            __Vfunc_fp32_less_than__566__lhs 
                                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_max_q;
                                            {
                                                if (
                                                    ((([&]() {
                                                                    __Vfunc_fp32_is_nan__567__bits 
                                                                        = __Vfunc_fp32_less_than__566__lhs;
                                                                    __Vfunc_fp32_is_nan__567__unused_sign = 0;
                                                                    __Vfunc_fp32_is_nan__567__unused_sign 
                                                                        = 
                                                                        (__Vfunc_fp32_is_nan__567__bits 
                                                                         >> 0x1fU);
                                                                    __Vfunc_fp32_is_nan__567__Vfuncout 
                                                                        = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__567__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__567__bits))));
                                                                }(), (IData)(__Vfunc_fp32_is_nan__567__Vfuncout)) 
                                                      | ([&]() {
                                                                    __Vfunc_fp32_is_nan__568__bits 
                                                                        = __Vfunc_fp32_less_than__566__rhs;
                                                                    __Vfunc_fp32_is_nan__568__unused_sign = 0;
                                                                    __Vfunc_fp32_is_nan__568__unused_sign 
                                                                        = 
                                                                        (__Vfunc_fp32_is_nan__568__bits 
                                                                         >> 0x1fU);
                                                                    __Vfunc_fp32_is_nan__568__Vfuncout 
                                                                        = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__568__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__568__bits))));
                                                                }(), (IData)(__Vfunc_fp32_is_nan__568__Vfuncout))) 
                                                     | ([&]() {
                                                                __Vfunc_fp32_equal__569__rhs 
                                                                    = __Vfunc_fp32_less_than__566__rhs;
                                                                __Vfunc_fp32_equal__569__lhs 
                                                                    = __Vfunc_fp32_less_than__566__lhs;
                                                                {
                                                                    if (
                                                                        (([&]() {
                                                                                __Vfunc_fp32_is_nan__570__bits 
                                                                                = __Vfunc_fp32_equal__569__lhs;
                                                                                __Vfunc_fp32_is_nan__570__unused_sign = 0;
                                                                                __Vfunc_fp32_is_nan__570__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_nan__570__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_nan__570__Vfuncout 
                                                                                = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__570__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__570__bits))));
                                                                                }(), (IData)(__Vfunc_fp32_is_nan__570__Vfuncout)) 
                                                                         | ([&]() {
                                                                                __Vfunc_fp32_is_nan__571__bits 
                                                                                = __Vfunc_fp32_equal__569__rhs;
                                                                                __Vfunc_fp32_is_nan__571__unused_sign = 0;
                                                                                __Vfunc_fp32_is_nan__571__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_nan__571__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_nan__571__Vfuncout 
                                                                                = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__571__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__571__bits))));
                                                                                }(), (IData)(__Vfunc_fp32_is_nan__571__Vfuncout)))) {
                                                                        __Vfunc_fp32_equal__569__Vfuncout = 0U;
                                                                        goto __Vlabel7;
                                                                    }
                                                                    if (
                                                                        (([&]() {
                                                                                __Vfunc_fp32_is_zero__572__bits 
                                                                                = __Vfunc_fp32_equal__569__lhs;
                                                                                __Vfunc_fp32_is_zero__572__unused_sign = 0;
                                                                                __Vfunc_fp32_is_zero__572__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_zero__572__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_zero__572__Vfuncout 
                                                                                = 
                                                                                (0U 
                                                                                == 
                                                                                (0x7fffffffU 
                                                                                & __Vfunc_fp32_is_zero__572__bits));
                                                                                }(), (IData)(__Vfunc_fp32_is_zero__572__Vfuncout)) 
                                                                         & ([&]() {
                                                                                __Vfunc_fp32_is_zero__573__bits 
                                                                                = __Vfunc_fp32_equal__569__rhs;
                                                                                __Vfunc_fp32_is_zero__573__unused_sign = 0;
                                                                                __Vfunc_fp32_is_zero__573__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_zero__573__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_zero__573__Vfuncout 
                                                                                = 
                                                                                (0U 
                                                                                == 
                                                                                (0x7fffffffU 
                                                                                & __Vfunc_fp32_is_zero__573__bits));
                                                                                }(), (IData)(__Vfunc_fp32_is_zero__573__Vfuncout)))) {
                                                                        __Vfunc_fp32_equal__569__Vfuncout = 1U;
                                                                        goto __Vlabel7;
                                                                    }
                                                                    __Vfunc_fp32_equal__569__Vfuncout 
                                                                        = 
                                                                        (__Vfunc_fp32_equal__569__lhs 
                                                                         == __Vfunc_fp32_equal__569__rhs);
                                                                    __Vlabel7: ;
                                                                }
                                                            }(), (IData)(__Vfunc_fp32_equal__569__Vfuncout)))) {
                                                    __Vfunc_fp32_less_than__566__Vfuncout = 0U;
                                                    goto __Vlabel6;
                                                }
                                                if (
                                                    ((__Vfunc_fp32_less_than__566__lhs 
                                                      >> 0x1fU) 
                                                     != 
                                                     (__Vfunc_fp32_less_than__566__rhs 
                                                      >> 0x1fU))) {
                                                    __Vfunc_fp32_less_than__566__Vfuncout 
                                                        = 
                                                        (__Vfunc_fp32_less_than__566__lhs 
                                                         >> 0x1fU);
                                                    goto __Vlabel6;
                                                }
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (__Vfunc_fp32_less_than__566__lhs 
                                                         >> 0x1fU)))) {
                                                    __Vfunc_fp32_less_than__566__Vfuncout 
                                                        = 
                                                        ((0x7fffffffU 
                                                          & __Vfunc_fp32_less_than__566__lhs) 
                                                         < 
                                                         (0x7fffffffU 
                                                          & __Vfunc_fp32_less_than__566__rhs));
                                                    goto __Vlabel6;
                                                }
                                                __Vfunc_fp32_less_than__566__Vfuncout 
                                                    = 
                                                    ((0x7fffffffU 
                                                      & __Vfunc_fp32_less_than__566__lhs) 
                                                     > 
                                                     (0x7fffffffU 
                                                      & __Vfunc_fp32_less_than__566__rhs));
                                                __Vlabel6: ;
                                            }
                                        }(), (IData)(__Vfunc_fp32_less_than__566__Vfuncout))))) {
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_max_q 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
                        }
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_seen_q = 1U;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xfU;
                    } else {
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_integer 
                            = (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__f2i_result 
                               + (((QData)((IData)(
                                                   (- (IData)(
                                                              (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_zero_point 
                                                               >> 0x1fU))))) 
                                   << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_zero_point))));
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_overflow 
                            = (VL_LTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_integer, 
                                          ([&]() {
                                        __Vfunc_dtype_min__574__dtype 
                                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype;
                                        __Vfunc_dtype_min__574__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_dtype_min__574__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_min__574__dtype))
                                                    ? 0xffffffffffff8000ULL
                                                    : 0xffffffff80000000ULL)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_min__574__dtype))
                                                    ? 0xffffffffffffff80ULL
                                                    : 0xfffffffffffffff8ULL));
                                    }(), __Vfunc_dtype_min__574__Vfuncout)) 
                               | VL_GTS_IQQ(64, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_integer, 
                                            ([&]() {
                                        __Vfunc_dtype_max__575__dtype 
                                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype;
                                        __Vfunc_dtype_max__575__Vfuncout 
                                            = ((2U 
                                                & (IData)(__Vfunc_dtype_max__575__dtype))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_max__575__dtype))
                                                    ? 0x7fffULL
                                                    : 0x7fffffffULL)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_dtype_max__575__dtype))
                                                    ? 0x7fULL
                                                    : 7ULL));
                                    }(), __Vfunc_dtype_max__575__Vfuncout)));
                        __Vfunc_clip_to_dtype__576__dtype 
                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype;
                        __Vfunc_clip_to_dtype__576__value 
                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_integer;
                        __Vfunc_clip_to_dtype__576__minimum = 0;
                        __Vfunc_clip_to_dtype__576__maximum = 0;
                        {
                            __Vfunc_dtype_min__577__dtype 
                                = __Vfunc_clip_to_dtype__576__dtype;
                            __Vfunc_dtype_min__577__Vfuncout 
                                = ((2U & (IData)(__Vfunc_dtype_min__577__dtype))
                                    ? ((1U & (IData)(__Vfunc_dtype_min__577__dtype))
                                        ? 0xffffffffffff8000ULL
                                        : 0xffffffff80000000ULL)
                                    : ((1U & (IData)(__Vfunc_dtype_min__577__dtype))
                                        ? 0xffffffffffffff80ULL
                                        : 0xfffffffffffffff8ULL));
                            __Vfunc_clip_to_dtype__576__minimum 
                                = __Vfunc_dtype_min__577__Vfuncout;
                            __Vfunc_dtype_max__578__dtype 
                                = __Vfunc_clip_to_dtype__576__dtype;
                            __Vfunc_dtype_max__578__Vfuncout 
                                = ((2U & (IData)(__Vfunc_dtype_max__578__dtype))
                                    ? ((1U & (IData)(__Vfunc_dtype_max__578__dtype))
                                        ? 0x7fffULL
                                        : 0x7fffffffULL)
                                    : ((1U & (IData)(__Vfunc_dtype_max__578__dtype))
                                        ? 0x7fULL : 7ULL));
                            __Vfunc_clip_to_dtype__576__maximum 
                                = __Vfunc_dtype_max__578__Vfuncout;
                            if (VL_LTS_IQQ(64, __Vfunc_clip_to_dtype__576__value, __Vfunc_clip_to_dtype__576__minimum)) {
                                __Vfunc_clip_to_dtype__576__Vfuncout 
                                    = __Vfunc_clip_to_dtype__576__minimum;
                                goto __Vlabel8;
                            }
                            if (VL_GTS_IQQ(64, __Vfunc_clip_to_dtype__576__value, __Vfunc_clip_to_dtype__576__maximum)) {
                                __Vfunc_clip_to_dtype__576__Vfuncout 
                                    = __Vfunc_clip_to_dtype__576__maximum;
                                goto __Vlabel8;
                            }
                            __Vfunc_clip_to_dtype__576__Vfuncout 
                                = __Vfunc_clip_to_dtype__576__value;
                            __Vlabel8: ;
                        }
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__result_q 
                            = __Vfunc_clip_to_dtype__576__Vfuncout;
                        if ((((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__output_overflow) 
                              | (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__f2i_exceptional)) 
                             & (1U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__overflow_mode)))) {
                            __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__579__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr);
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 0xcU;
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__579__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                        } else if (([&]() {
                                    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__dtype 
                                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype;
                                    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__byte_lane 
                                        = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr));
                                    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__Vfuncout 
                                        = (((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__dtype)) 
                                            & (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__byte_lane))) 
                                           | ((3U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__dtype)) 
                                              & (6U 
                                                 < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__byte_lane))));
                                }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__580__Vfuncout))) {
                            __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__581__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr);
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 4U;
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__581__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                        } else {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q 
                                = (((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype)) 
                                    & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_high_nibble))
                                    ? 0x10U : 0x12U);
                        }
                    }
                } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                             [4U])) {
                            __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__582__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_addr);
                            __Vfunc_memory_status_to_task__583__status 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                                [4U];
                            __Vfunc_memory_status_to_task__583__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__583__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__583__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__583__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__582__fail_status 
                                = __Vfunc_memory_status_to_task__583__Vfuncout;
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q 
                                = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__582__fail_status;
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__582__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                        } else {
                            __Vfunc_load_element__584__dtype 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_dtype;
                            __Vfunc_load_element__584__high_nibble 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_high_nibble;
                            __Vfunc_load_element__584__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_addr));
                            __Vfunc_load_element__584__beat 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                [4U];
                            __Vfunc_load_element__584__byte_value 
                                = (0xffU & (IData)(
                                                   (__Vfunc_load_element__584__beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__584__byte_lane), 3U)))));
                            __Vfunc_load_element__584__nibble_value 
                                = (0xfU & ((IData)(__Vfunc_load_element__584__high_nibble)
                                            ? ((IData)(__Vfunc_load_element__584__byte_value) 
                                               >> 4U)
                                            : (IData)(__Vfunc_load_element__584__byte_value)));
                            __Vfunc_load_element__584__half_value 
                                = (0xffffU & (IData)(
                                                     (__Vfunc_load_element__584__beat 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__584__byte_lane), 3U)))));
                            __Vfunc_load_element__584__word_value 
                                = (IData)((__Vfunc_load_element__584__beat 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__584__byte_lane), 3U))));
                            __Vfunc_load_element__584__Vfuncout 
                                = ((2U & (IData)(__Vfunc_load_element__584__dtype))
                                    ? ((1U & (IData)(__Vfunc_load_element__584__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__584__half_value) 
                                                                   >> 0xfU))))) 
                                            << 0x10U) 
                                           | (QData)((IData)(__Vfunc_load_element__584__half_value)))
                                        : (((QData)((IData)(
                                                            (- (IData)(
                                                                       (__Vfunc_load_element__584__word_value 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(__Vfunc_load_element__584__word_value))))
                                    : ((1U & (IData)(__Vfunc_load_element__584__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__584__byte_value) 
                                                                   >> 7U))))) 
                                            << 8U) 
                                           | (QData)((IData)(__Vfunc_load_element__584__byte_value)))
                                        : (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__584__nibble_value) 
                                                                   >> 3U))))) 
                                            << 4U) 
                                           | (QData)((IData)(__Vfunc_load_element__584__nibble_value)))));
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_value_q 
                                = __Vfunc_load_element__584__Vfuncout;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xeU;
                        }
                    }
                } else if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xdU;
                }
            } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                             [4U])) {
                            __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__585__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_addr);
                            __Vfunc_memory_status_to_task__586__status 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                                [4U];
                            __Vfunc_memory_status_to_task__586__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__586__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__586__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__586__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__585__fail_status 
                                = __Vfunc_memory_status_to_task__586__Vfuncout;
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q 
                                = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__585__fail_status;
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__585__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                        } else {
                            __Vfunc_load_element__587__dtype 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_dtype;
                            __Vfunc_load_element__587__high_nibble 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_high_nibble;
                            __Vfunc_load_element__587__byte_lane 
                                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_addr));
                            __Vfunc_load_element__587__beat 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                [4U];
                            __Vfunc_load_element__587__byte_value 
                                = (0xffU & (IData)(
                                                   (__Vfunc_load_element__587__beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__587__byte_lane), 3U)))));
                            __Vfunc_load_element__587__nibble_value 
                                = (0xfU & ((IData)(__Vfunc_load_element__587__high_nibble)
                                            ? ((IData)(__Vfunc_load_element__587__byte_value) 
                                               >> 4U)
                                            : (IData)(__Vfunc_load_element__587__byte_value)));
                            __Vfunc_load_element__587__half_value 
                                = (0xffffU & (IData)(
                                                     (__Vfunc_load_element__587__beat 
                                                      >> 
                                                      (0x3fU 
                                                       & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__587__byte_lane), 3U)))));
                            __Vfunc_load_element__587__word_value 
                                = (IData)((__Vfunc_load_element__587__beat 
                                           >> (0x3fU 
                                               & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__587__byte_lane), 3U))));
                            __Vfunc_load_element__587__Vfuncout 
                                = ((2U & (IData)(__Vfunc_load_element__587__dtype))
                                    ? ((1U & (IData)(__Vfunc_load_element__587__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__587__half_value) 
                                                                   >> 0xfU))))) 
                                            << 0x10U) 
                                           | (QData)((IData)(__Vfunc_load_element__587__half_value)))
                                        : (((QData)((IData)(
                                                            (- (IData)(
                                                                       (__Vfunc_load_element__587__word_value 
                                                                        >> 0x1fU))))) 
                                            << 0x20U) 
                                           | (QData)((IData)(__Vfunc_load_element__587__word_value))))
                                    : ((1U & (IData)(__Vfunc_load_element__587__dtype))
                                        ? (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__587__byte_value) 
                                                                   >> 7U))))) 
                                            << 8U) 
                                           | (QData)((IData)(__Vfunc_load_element__587__byte_value)))
                                        : (((- (QData)((IData)(
                                                               (1U 
                                                                & ((IData)(__Vfunc_load_element__587__nibble_value) 
                                                                   >> 3U))))) 
                                            << 4U) 
                                           | (QData)((IData)(__Vfunc_load_element__587__nibble_value)))));
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_value_q 
                                = __Vfunc_load_element__587__Vfuncout;
                            if (((5U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q)) 
                                 & (5U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__function_mode))) {
                                if (([&]() {
                                            __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__dtype 
                                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_dtype;
                                            __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__byte_lane 
                                                = (7U 
                                                   & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_addr));
                                            __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__Vfuncout 
                                                = (
                                                   ((2U 
                                                     == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__dtype)) 
                                                    & (4U 
                                                       < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__byte_lane))) 
                                                   | ((3U 
                                                       == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__dtype)) 
                                                      & (6U 
                                                         < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__byte_lane))));
                                        }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__588__Vfuncout))) {
                                    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__589__fail_addr 
                                        = (0xffffffffffffULL 
                                           & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_addr);
                                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 4U;
                                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                        = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__589__fail_addr;
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                                } else {
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xcU;
                                }
                            } else {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xeU;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xbU;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                    if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                         [4U])) {
                        __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__590__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_addr);
                        __Vfunc_memory_status_to_task__591__status 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                            [4U];
                        __Vfunc_memory_status_to_task__591__Vfuncout 
                            = ((0U == (IData)(__Vfunc_memory_status_to_task__591__status))
                                ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__591__status))
                                         ? 6U : ((2U 
                                                  == (IData)(__Vfunc_memory_status_to_task__591__status))
                                                  ? 5U
                                                  : 4U)));
                        __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__590__fail_status 
                            = __Vfunc_memory_status_to_task__591__Vfuncout;
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q 
                            = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__590__fail_status;
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__590__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                    } else {
                        __Vfunc_load_element__592__dtype 
                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_dtype;
                        __Vfunc_load_element__592__high_nibble 
                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_high_nibble;
                        __Vfunc_load_element__592__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_addr));
                        __Vfunc_load_element__592__beat 
                            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                            [4U];
                        __Vfunc_load_element__592__byte_value 
                            = (0xffU & (IData)((__Vfunc_load_element__592__beat 
                                                >> 
                                                (0x3fU 
                                                 & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__592__byte_lane), 3U)))));
                        __Vfunc_load_element__592__nibble_value 
                            = (0xfU & ((IData)(__Vfunc_load_element__592__high_nibble)
                                        ? ((IData)(__Vfunc_load_element__592__byte_value) 
                                           >> 4U) : (IData)(__Vfunc_load_element__592__byte_value)));
                        __Vfunc_load_element__592__half_value 
                            = (0xffffU & (IData)((__Vfunc_load_element__592__beat 
                                                  >> 
                                                  (0x3fU 
                                                   & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__592__byte_lane), 3U)))));
                        __Vfunc_load_element__592__word_value 
                            = (IData)((__Vfunc_load_element__592__beat 
                                       >> (0x3fU & 
                                           VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__592__byte_lane), 3U))));
                        __Vfunc_load_element__592__Vfuncout 
                            = ((2U & (IData)(__Vfunc_load_element__592__dtype))
                                ? ((1U & (IData)(__Vfunc_load_element__592__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__592__half_value) 
                                                               >> 0xfU))))) 
                                        << 0x10U) | (QData)((IData)(__Vfunc_load_element__592__half_value)))
                                    : (((QData)((IData)(
                                                        (- (IData)(
                                                                   (__Vfunc_load_element__592__word_value 
                                                                    >> 0x1fU))))) 
                                        << 0x20U) | (QData)((IData)(__Vfunc_load_element__592__word_value))))
                                : ((1U & (IData)(__Vfunc_load_element__592__dtype))
                                    ? (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__592__byte_value) 
                                                               >> 7U))))) 
                                        << 8U) | (QData)((IData)(__Vfunc_load_element__592__byte_value)))
                                    : (((- (QData)((IData)(
                                                           (1U 
                                                            & ((IData)(__Vfunc_load_element__592__nibble_value) 
                                                               >> 3U))))) 
                                        << 4U) | (QData)((IData)(__Vfunc_load_element__592__nibble_value)))));
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q 
                            = __Vfunc_load_element__592__Vfuncout;
                        if (((0x86U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                             | (5U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q)))) {
                            if (([&]() {
                                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__dtype 
                                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_dtype;
                                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__byte_lane 
                                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_addr));
                                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__Vfuncout 
                                            = (((2U 
                                                 == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__dtype)) 
                                                & (4U 
                                                   < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__byte_lane))) 
                                               | ((3U 
                                                   == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__dtype)) 
                                                  & (6U 
                                                     < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__byte_lane))));
                                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__593__Vfuncout))) {
                                __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__594__fail_addr 
                                    = (0xffffffffffffULL 
                                       & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_addr);
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 4U;
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                    = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__594__fail_addr;
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                            } else {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xaU;
                            }
                        } else {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xeU;
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 9U;
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                        if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                             [4U])) {
                            __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__595__fail_addr 
                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_addr;
                            __Vfunc_memory_status_to_task__596__status 
                                = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                                [4U];
                            __Vfunc_memory_status_to_task__596__Vfuncout 
                                = ((0U == (IData)(__Vfunc_memory_status_to_task__596__status))
                                    ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__596__status))
                                             ? 6U : 
                                            ((2U == (IData)(__Vfunc_memory_status_to_task__596__status))
                                              ? 5U : 4U)));
                            __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__595__fail_status 
                                = __Vfunc_memory_status_to_task__596__Vfuncout;
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q 
                                = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__595__fail_status;
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__595__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                        } else {
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_value_q 
                                = (0U != (0xffU & (IData)(
                                                          (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                                           [4U] 
                                                           >> 
                                                           (0x3fU 
                                                            & VL_SHIFTL_III(6,32,32, 
                                                                            (7U 
                                                                             & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_addr)), 3U))))));
                            if ((0U == (0xffU & (IData)(
                                                        (vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                                                         [4U] 
                                                         >> 
                                                         (0x3fU 
                                                          & VL_SHIFTL_III(6,32,32, 
                                                                          (7U 
                                                                           & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_addr)), 3U))))))) {
                                if ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__result_q = 0ULL;
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q 
                                        = (((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype)) 
                                            & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_high_nibble))
                                            ? 0x10U
                                            : 0x12U);
                                } else {
                                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xfU;
                                }
                            } else if (([&]() {
                                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__dtype 
                                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_dtype;
                                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__byte_lane 
                                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_addr));
                                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__Vfuncout 
                                            = (((2U 
                                                 == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__dtype)) 
                                                & (4U 
                                                   < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__byte_lane))) 
                                               | ((3U 
                                                   == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__dtype)) 
                                                  & (6U 
                                                     < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__byte_lane))));
                                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__597__Vfuncout))) {
                                __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__598__fail_addr 
                                    = (0xffffffffffffULL 
                                       & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_addr);
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 4U;
                                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                    = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__598__fail_addr;
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                            } else {
                                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 8U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_value_q = 1U;
                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__rmw_beat_q = 0ULL;
                if (((0x81U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                     & (1U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_mode))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 6U;
                } else {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__current_valid 
                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__derived_mask_valid;
                    if (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__current_valid) {
                        if (([&]() {
                                    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__dtype 
                                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_dtype;
                                    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__byte_lane 
                                        = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_addr));
                                    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__Vfuncout 
                                        = (((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__dtype)) 
                                            & (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__byte_lane))) 
                                           | ((3U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__dtype)) 
                                              & (6U 
                                                 < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__byte_lane))));
                                }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__599__Vfuncout))) {
                            __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__600__fail_addr 
                                = (0xffffffffffffULL 
                                   & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_addr);
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 4U;
                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                                = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__600__fail_addr;
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                        } else {
                            vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 8U;
                        }
                    } else if ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__result_q = 0ULL;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q 
                            = (((0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype)) 
                                & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_high_nibble))
                                ? 0x10U : 0x12U);
                    } else {
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0xfU;
                    }
                }
            } else if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q))) {
                if ((0U != vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                     [4U])) {
                    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__601__fail_addr 
                        = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_valid_length_addr);
                    __Vfunc_memory_status_to_task__602__status 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
                        [4U];
                    __Vfunc_memory_status_to_task__602__Vfuncout 
                        = ((0U == (IData)(__Vfunc_memory_status_to_task__602__status))
                            ? 0U : ((1U == (IData)(__Vfunc_memory_status_to_task__602__status))
                                     ? 6U : ((2U == (IData)(__Vfunc_memory_status_to_task__602__status))
                                              ? 5U : 4U)));
                    __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__601__fail_status 
                        = __Vfunc_memory_status_to_task__602__Vfuncout;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q 
                        = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__601__fail_status;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                        = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__601__fail_addr;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else {
                    __Vfunc_load_element__603__byte_lane 
                        = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_valid_length_addr));
                    __Vfunc_load_element__603__beat 
                        = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
                        [4U];
                    __Vfunc_load_element__603__word_value 
                        = (IData)((__Vfunc_load_element__603__beat 
                                   >> (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(__Vfunc_load_element__603__byte_lane), 3U))));
                    __Vfunc_load_element__603__Vfuncout 
                        = (((QData)((IData)((- (IData)(
                                                       (__Vfunc_load_element__603__word_value 
                                                        >> 0x1fU))))) 
                            << 0x20U) | (QData)((IData)(__Vfunc_load_element__603__word_value)));
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__valid_length_value 
                        = __Vfunc_load_element__603__Vfuncout;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_key_length_q 
                        = (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__valid_length_value);
                    if ((VL_GTS_IQQ(64, 0ULL, vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__valid_length_value) 
                         | (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__unnamedblk1__DOT__valid_length_value 
                            > (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__length))))) {
                        __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__604__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_valid_length_addr);
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 3U;
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__604__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 5U;
                    }
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__l1_req_ready))) {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 4U;
                }
            } else {
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__col_q = 0U;
                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_value_q = 1U;
                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_seen_q = 0U;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_sum_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_sumsq_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_max_q = 0xc000000000000001ULL;
                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_q = 0U;
                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sumsq_q = 0U;
                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_max_q = 0xff800000U;
                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_mean_q = 0U;
                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_invstd_q = 0U;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__phase_q 
                    = ((0x81U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q))
                        ? 1U : ((0x82U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q))
                                 ? 4U : ((0x84U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q))
                                          ? 6U : 0U)));
                if (((0x81U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                     & (3U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_mode))) {
                    if (([&]() {
                                __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__605__byte_lane 
                                    = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_valid_length_addr));
                                __Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__605__Vfuncout 
                                    = (4U < (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__605__byte_lane));
                            }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__crosses_beat__605__Vfuncout))) {
                        __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__606__fail_addr 
                            = (0xffffffffffffULL & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_valid_length_addr);
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 4U;
                        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q 
                            = __Vtask_tb_npu_engines__DOT__u_complex__DOT__fail_task__606__fail_addr;
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                    } else {
                        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 3U;
                    }
                } else {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_key_length_q 
                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__length;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 5U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            if (([&]() {
                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__opcode_known__607__opcode 
                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q;
                        __Vfunc_tb_npu_engines__DOT__u_complex__DOT__opcode_known__607__Vfuncout 
                            = (((((0x80U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__opcode_known__607__opcode)) 
                                  | (0x81U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__opcode_known__607__opcode))) 
                                 | (0x82U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__opcode_known__607__opcode))) 
                                | (0x84U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__opcode_known__607__opcode))) 
                               | (0x86U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__opcode_known__607__opcode)));
                    }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__opcode_known__607__Vfuncout))) {
                if ((((1U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_version)) 
                      | (4U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_type))) 
                     | (0x100U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_bytes)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if ((IData)((0U != (0xfffe0300U 
                                           & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__numeric_cfg)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if ((1U & ((((((((((((~ ([&]() {
                                                                                __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__function_value 
                                                                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__function_mode;
                                                                                __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__opcode 
                                                                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q;
                                                                                __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__Vfuncout 
                                                                                = 
                                                                                ((0x80U 
                                                                                == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__opcode))
                                                                                 ? 
                                                                                (3U 
                                                                                >= __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__function_value)
                                                                                 : 
                                                                                ((0x81U 
                                                                                == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__opcode))
                                                                                 ? 
                                                                                (4U 
                                                                                == __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__function_value)
                                                                                 : 
                                                                                ((0x82U 
                                                                                == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__opcode))
                                                                                 ? 
                                                                                ((5U 
                                                                                == __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__function_value) 
                                                                                | (6U 
                                                                                == __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__function_value))
                                                                                 : 
                                                                                ((0x84U 
                                                                                == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__opcode))
                                                                                 ? 
                                                                                ((7U 
                                                                                <= __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__function_value) 
                                                                                & (9U 
                                                                                >= __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__function_value))
                                                                                 : 
                                                                                ((0x86U 
                                                                                == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__opcode)) 
                                                                                && (0xcU 
                                                                                == __Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__function_value))))));
                                                                            }(), (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__function_matches__614__Vfuncout))) 
                                            | (0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__approx_mode))) 
                                           | (2U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__overflow_mode))) 
                                          | (1U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__all_mask_mode))) 
                                         | (1U < (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stats_mode))) 
                                        | (3U < vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_mode)) 
                                       | (0x1000U < vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__scratch_request_elems)) 
                                      | (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__zero_point_enable)) 
                                     | (0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_zero_point)) 
                                    | (0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_zero_point)) 
                                   | (0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_zero_point)) 
                                  | (0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_zero_point)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if (((((((((0ULL != (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_base 
                                            >> 0x14U)) 
                                  | (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_base 
                                              >> 0x14U))) 
                                 | (((0x86U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                                     | (0x82U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q))) 
                                    & (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_base 
                                                >> 0x14U)))) 
                                | (((0x82U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                                    & (5U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__function_mode)) 
                                   & (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_base 
                                               >> 0x14U)))) 
                               | ((1U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_mode) 
                                  & (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_base 
                                              >> 0x14U)))) 
                              | ((3U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_mode) 
                                 & (0ULL != (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_length_base 
                                             >> 0x14U)))) 
                             | (0ULL != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__aux0_addr_high)) 
                            | (0ULL != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__aux1_addr_high))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 4U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if ((((0U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__rows) 
                             | (0U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__length)) 
                            & (0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_length))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if ((((0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__rows) 
                             & (0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__length)) 
                            & ((0U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_length) 
                               | (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_length 
                                  > vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__length)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if ((((0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__rows) 
                             & (0U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__length)) 
                            & (~ ((0x80U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                                  | (0x86U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 3U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if (((0x84U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                            & (2U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype)))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 7U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if (((0x84U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                            & (((0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__scale_mode)) 
                                | (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__internal_fp32_enable)) 
                               | ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__saturate_enable) 
                                  != (0U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__overflow_mode)))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if (((0x84U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                            & ((((1U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__scale_mode)) 
                                 | (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__internal_fp32_enable))) 
                                | (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__saturate_enable))) 
                               | (0U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__overflow_mode))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if (((0x84U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                            & ((((~ ([&]() {
                                                __Vfunc_fp32_finite_positive__623__bits 
                                                    = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_scale_bits;
                                                __Vfunc_fp32_finite_positive__623__Vfuncout 
                                                    = 
                                                    (((0xffU 
                                                       != 
                                                       (0xffU 
                                                        & (__Vfunc_fp32_finite_positive__623__bits 
                                                           >> 0x17U))) 
                                                      & (~ 
                                                         (__Vfunc_fp32_finite_positive__623__bits 
                                                          >> 0x1fU))) 
                                                     & (0U 
                                                        != 
                                                        (0x7fffffffU 
                                                         & __Vfunc_fp32_finite_positive__623__bits)));
                                            }(), (IData)(__Vfunc_fp32_finite_positive__623__Vfuncout))) 
                                 | (~ ([&]() {
                                                __Vfunc_fp32_finite_positive__624__bits 
                                                    = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_scale_bits;
                                                __Vfunc_fp32_finite_positive__624__Vfuncout 
                                                    = 
                                                    (((0xffU 
                                                       != 
                                                       (0xffU 
                                                        & (__Vfunc_fp32_finite_positive__624__bits 
                                                           >> 0x17U))) 
                                                      & (~ 
                                                         (__Vfunc_fp32_finite_positive__624__bits 
                                                          >> 0x1fU))) 
                                                     & (0U 
                                                        != 
                                                        (0x7fffffffU 
                                                         & __Vfunc_fp32_finite_positive__624__bits)));
                                            }(), (IData)(__Vfunc_fp32_finite_positive__624__Vfuncout)))) 
                                | (((0x86U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                                    | (0x82U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q))) 
                                   & (~ ([&]() {
                                                __Vfunc_fp32_finite_positive__625__bits 
                                                    = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_scale_bits;
                                                __Vfunc_fp32_finite_positive__625__Vfuncout 
                                                    = 
                                                    (((0xffU 
                                                       != 
                                                       (0xffU 
                                                        & (__Vfunc_fp32_finite_positive__625__bits 
                                                           >> 0x17U))) 
                                                      & (~ 
                                                         (__Vfunc_fp32_finite_positive__625__bits 
                                                          >> 0x1fU))) 
                                                     & (0U 
                                                        != 
                                                        (0x7fffffffU 
                                                         & __Vfunc_fp32_finite_positive__625__bits)));
                                            }(), (IData)(__Vfunc_fp32_finite_positive__625__Vfuncout))))) 
                               | (((0x82U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                                   & (5U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__function_mode)) 
                                  & (~ ([&]() {
                                            __Vfunc_fp32_finite_positive__626__bits 
                                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_scale_bits;
                                            __Vfunc_fp32_finite_positive__626__Vfuncout 
                                                = (
                                                   ((0xffU 
                                                     != 
                                                     (0xffU 
                                                      & (__Vfunc_fp32_finite_positive__626__bits 
                                                         >> 0x17U))) 
                                                    & (~ 
                                                       (__Vfunc_fp32_finite_positive__626__bits 
                                                        >> 0x1fU))) 
                                                   & (0U 
                                                      != 
                                                      (0x7fffffffU 
                                                       & __Vfunc_fp32_finite_positive__626__bits)));
                                        }(), (IData)(__Vfunc_fp32_finite_positive__626__Vfuncout))))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if (((0x82U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                            & (~ ([&]() {
                                    __Vfunc_fp32_finite_positive__628__bits 
                                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__epsilon_bits;
                                    __Vfunc_fp32_finite_positive__628__Vfuncout 
                                        = (((0xffU 
                                             != (0xffU 
                                                 & (__Vfunc_fp32_finite_positive__628__bits 
                                                    >> 0x17U))) 
                                            & (~ (__Vfunc_fp32_finite_positive__628__bits 
                                                  >> 0x1fU))) 
                                           & (0U != 
                                              (0x7fffffffU 
                                               & __Vfunc_fp32_finite_positive__628__bits)));
                                }(), (IData)(__Vfunc_fp32_finite_positive__628__Vfuncout))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if (((0x82U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                            & (0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__epsilon_bits))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if ((((0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__input_clip_min_bits) 
                             | (0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__input_clip_max_bits)) 
                            & (((~ ([&]() {
                                            __Vfunc_fp32_less_than__631__rhs 
                                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__input_clip_max_bits;
                                            __Vfunc_fp32_less_than__631__lhs 
                                                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__input_clip_min_bits;
                                            {
                                                if (
                                                    ((([&]() {
                                                                    __Vfunc_fp32_is_nan__632__bits 
                                                                        = __Vfunc_fp32_less_than__631__lhs;
                                                                    __Vfunc_fp32_is_nan__632__unused_sign = 0;
                                                                    __Vfunc_fp32_is_nan__632__unused_sign 
                                                                        = 
                                                                        (__Vfunc_fp32_is_nan__632__bits 
                                                                         >> 0x1fU);
                                                                    __Vfunc_fp32_is_nan__632__Vfuncout 
                                                                        = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__632__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__632__bits))));
                                                                }(), (IData)(__Vfunc_fp32_is_nan__632__Vfuncout)) 
                                                      | ([&]() {
                                                                    __Vfunc_fp32_is_nan__633__bits 
                                                                        = __Vfunc_fp32_less_than__631__rhs;
                                                                    __Vfunc_fp32_is_nan__633__unused_sign = 0;
                                                                    __Vfunc_fp32_is_nan__633__unused_sign 
                                                                        = 
                                                                        (__Vfunc_fp32_is_nan__633__bits 
                                                                         >> 0x1fU);
                                                                    __Vfunc_fp32_is_nan__633__Vfuncout 
                                                                        = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__633__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__633__bits))));
                                                                }(), (IData)(__Vfunc_fp32_is_nan__633__Vfuncout))) 
                                                     | ([&]() {
                                                                __Vfunc_fp32_equal__634__rhs 
                                                                    = __Vfunc_fp32_less_than__631__rhs;
                                                                __Vfunc_fp32_equal__634__lhs 
                                                                    = __Vfunc_fp32_less_than__631__lhs;
                                                                {
                                                                    if (
                                                                        (([&]() {
                                                                                __Vfunc_fp32_is_nan__635__bits 
                                                                                = __Vfunc_fp32_equal__634__lhs;
                                                                                __Vfunc_fp32_is_nan__635__unused_sign = 0;
                                                                                __Vfunc_fp32_is_nan__635__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_nan__635__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_nan__635__Vfuncout 
                                                                                = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__635__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__635__bits))));
                                                                                }(), (IData)(__Vfunc_fp32_is_nan__635__Vfuncout)) 
                                                                         | ([&]() {
                                                                                __Vfunc_fp32_is_nan__636__bits 
                                                                                = __Vfunc_fp32_equal__634__rhs;
                                                                                __Vfunc_fp32_is_nan__636__unused_sign = 0;
                                                                                __Vfunc_fp32_is_nan__636__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_nan__636__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_nan__636__Vfuncout 
                                                                                = (IData)(
                                                                                ((0x7f800000U 
                                                                                == 
                                                                                (0x7f800000U 
                                                                                & __Vfunc_fp32_is_nan__636__bits)) 
                                                                                & (0U 
                                                                                != 
                                                                                (0x7fffffU 
                                                                                & __Vfunc_fp32_is_nan__636__bits))));
                                                                                }(), (IData)(__Vfunc_fp32_is_nan__636__Vfuncout)))) {
                                                                        __Vfunc_fp32_equal__634__Vfuncout = 0U;
                                                                        goto __Vlabel10;
                                                                    }
                                                                    if (
                                                                        (([&]() {
                                                                                __Vfunc_fp32_is_zero__637__bits 
                                                                                = __Vfunc_fp32_equal__634__lhs;
                                                                                __Vfunc_fp32_is_zero__637__unused_sign = 0;
                                                                                __Vfunc_fp32_is_zero__637__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_zero__637__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_zero__637__Vfuncout 
                                                                                = 
                                                                                (0U 
                                                                                == 
                                                                                (0x7fffffffU 
                                                                                & __Vfunc_fp32_is_zero__637__bits));
                                                                                }(), (IData)(__Vfunc_fp32_is_zero__637__Vfuncout)) 
                                                                         & ([&]() {
                                                                                __Vfunc_fp32_is_zero__638__bits 
                                                                                = __Vfunc_fp32_equal__634__rhs;
                                                                                __Vfunc_fp32_is_zero__638__unused_sign = 0;
                                                                                __Vfunc_fp32_is_zero__638__unused_sign 
                                                                                = 
                                                                                (__Vfunc_fp32_is_zero__638__bits 
                                                                                >> 0x1fU);
                                                                                __Vfunc_fp32_is_zero__638__Vfuncout 
                                                                                = 
                                                                                (0U 
                                                                                == 
                                                                                (0x7fffffffU 
                                                                                & __Vfunc_fp32_is_zero__638__bits));
                                                                                }(), (IData)(__Vfunc_fp32_is_zero__638__Vfuncout)))) {
                                                                        __Vfunc_fp32_equal__634__Vfuncout = 1U;
                                                                        goto __Vlabel10;
                                                                    }
                                                                    __Vfunc_fp32_equal__634__Vfuncout 
                                                                        = 
                                                                        (__Vfunc_fp32_equal__634__lhs 
                                                                         == __Vfunc_fp32_equal__634__rhs);
                                                                    __Vlabel10: ;
                                                                }
                                                            }(), (IData)(__Vfunc_fp32_equal__634__Vfuncout)))) {
                                                    __Vfunc_fp32_less_than__631__Vfuncout = 0U;
                                                    goto __Vlabel9;
                                                }
                                                if (
                                                    ((__Vfunc_fp32_less_than__631__lhs 
                                                      >> 0x1fU) 
                                                     != 
                                                     (__Vfunc_fp32_less_than__631__rhs 
                                                      >> 0x1fU))) {
                                                    __Vfunc_fp32_less_than__631__Vfuncout 
                                                        = 
                                                        (__Vfunc_fp32_less_than__631__lhs 
                                                         >> 0x1fU);
                                                    goto __Vlabel9;
                                                }
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        (__Vfunc_fp32_less_than__631__lhs 
                                                         >> 0x1fU)))) {
                                                    __Vfunc_fp32_less_than__631__Vfuncout 
                                                        = 
                                                        ((0x7fffffffU 
                                                          & __Vfunc_fp32_less_than__631__lhs) 
                                                         < 
                                                         (0x7fffffffU 
                                                          & __Vfunc_fp32_less_than__631__rhs));
                                                    goto __Vlabel9;
                                                }
                                                __Vfunc_fp32_less_than__631__Vfuncout 
                                                    = 
                                                    ((0x7fffffffU 
                                                      & __Vfunc_fp32_less_than__631__lhs) 
                                                     > 
                                                     (0x7fffffffU 
                                                      & __Vfunc_fp32_less_than__631__rhs));
                                                __Vlabel9: ;
                                            }
                                        }(), (IData)(__Vfunc_fp32_less_than__631__Vfuncout))) 
                                | ([&]() {
                                        __Vfunc_fp32_is_nan__639__bits 
                                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__input_clip_min_bits;
                                        __Vfunc_fp32_is_nan__639__Vfuncout 
                                            = (IData)(
                                                      ((0x7f800000U 
                                                        == 
                                                        (0x7f800000U 
                                                         & __Vfunc_fp32_is_nan__639__bits)) 
                                                       & (0U 
                                                          != 
                                                          (0x7fffffU 
                                                           & __Vfunc_fp32_is_nan__639__bits))));
                                    }(), (IData)(__Vfunc_fp32_is_nan__639__Vfuncout))) 
                               | ([&]() {
                                    __Vfunc_fp32_is_nan__640__bits 
                                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__input_clip_max_bits;
                                    __Vfunc_fp32_is_nan__640__Vfuncout 
                                        = (IData)((
                                                   (0x7f800000U 
                                                    == 
                                                    (0x7f800000U 
                                                     & __Vfunc_fp32_is_nan__640__bits)) 
                                                   & (0U 
                                                      != 
                                                      (0x7fffffU 
                                                       & __Vfunc_fp32_is_nan__640__bits))));
                                }(), (IData)(__Vfunc_fp32_is_nan__640__Vfuncout))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if (((0x81U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                            & (((1U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_mode) 
                                & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_row_stride 
                                   < vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__length)) 
                               | ((3U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_mode) 
                                  & ((4U > vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_length_stride) 
                                     | (0U != (3U & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_length_stride))))))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if (((0x81U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                            & (0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_mode))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if ((((0x82U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                             & (6U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__function_mode)) 
                            & (0ULL != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_base))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 2U;
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else if (((0U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__rows) 
                            | (0U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__length))) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
                } else {
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__row_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__col_q = 0U;
                    vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 2U;
                }
            } else {
                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 1U;
                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0x14U;
            }
        } else {
            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 0U;
            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__progress_q = 0ULL;
            if (vlSelfRef.tb_npu_engines__DOT__complex_task_valid) {
                IData/*31:0*/ __Vilp3;
                __Vilp3 = 0U;
                while ((__Vilp3 <= 0x3fU)) {
                    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[__Vilp3] 
                        = vlSelfRef.tb_npu_engines__DOT__complex_desc[__Vilp3];
                    __Vilp3 = ((IData)(1U) + __Vilp3);
                }
                vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q 
                    = vlSelfRef.tb_npu_engines__DOT__complex_opcode;
                vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 1U;
            }
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__state_q = 0U;
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__phase_q = 0U;
        IData/*31:0*/ __Vilp4;
        __Vilp4 = 0U;
        while ((__Vilp4 <= 0x3fU)) {
            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[__Vilp4] 
                = Vtb_npu_engines__ConstPool__CONST_h6be9aa18_0[__Vilp4];
            __Vilp4 = ((IData)(1U) + __Vilp4);
        }
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q = 0U;
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__row_q = 0U;
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__col_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_key_length_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_value_q = 1U;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_seen_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_value_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_value_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_sum_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_sumsq_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_engines__DOT__u_complex__DOT__stat_max_q = 0xc000000000000001ULL;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sumsq_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_max_q = 0xff800000U;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_mean_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_invstd_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__result_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__rmw_beat_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__status_q = 0U;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fault_addr_q = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__progress_q = 0ULL;
    }
}
