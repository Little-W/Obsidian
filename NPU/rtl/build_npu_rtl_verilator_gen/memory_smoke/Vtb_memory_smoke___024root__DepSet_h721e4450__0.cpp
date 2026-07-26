// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_memory_smoke.h for the primary calling header

#include "Vtb_memory_smoke__pch.h"
#include "Vtb_memory_smoke___024root.h"

VlCoroutine Vtb_memory_smoke___024root___eval_initial__TOP__Vtiming__0(Vtb_memory_smoke___024root* vlSelf);
VlCoroutine Vtb_memory_smoke___024root___eval_initial__TOP__Vtiming__1(Vtb_memory_smoke___024root* vlSelf);
VlCoroutine Vtb_memory_smoke___024root___eval_initial__TOP__Vtiming__2(Vtb_memory_smoke___024root* vlSelf);

void Vtb_memory_smoke___024root___eval_initial(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_initial\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_memory_smoke___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_memory_smoke___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_memory_smoke___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

void Vtb_memory_smoke___024root___act_comb__TOP__0(Vtb_memory_smoke___024root* vlSelf);

void Vtb_memory_smoke___024root___eval_act(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_act\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x3fdULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb_memory_smoke___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_memory_smoke___024root___act_comb__TOP__0(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___act_comb__TOP__0\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_memory_smoke__DOT__u_l1__DOT__grant_found;
    tb_memory_smoke__DOT__u_l1__DOT__grant_found = 0;
    // Body
    tb_memory_smoke__DOT__u_l1__DOT__grant_found = 0U;
    vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client 
        = vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rr_client_q;
    if ((((0U >= (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rr_client_q)) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid)) 
         & ((~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q)) 
            | (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_rsp_ready)))) {
        tb_memory_smoke__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client = 0U;
    }
    if ((((~ (IData)(tb_memory_smoke__DOT__u_l1__DOT__grant_found)) 
          & ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid) 
             >> 1U)) & ((~ ((IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q) 
                            >> 1U)) | ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_rsp_ready) 
                                       >> 1U)))) {
        tb_memory_smoke__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client = 1U;
    }
    if (((((~ (IData)(tb_memory_smoke__DOT__u_l1__DOT__grant_found)) 
           & (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rr_client_q)) 
          & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid)) 
         & ((~ (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__rsp_valid_q)) 
            | (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_rsp_ready)))) {
        tb_memory_smoke__DOT__u_l1__DOT__grant_found = 1U;
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client = 0U;
    }
    vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_addr 
        = ((0x27U >= (0x3fU & ((IData)(0x14U) * (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client))))
            ? (0xfffffU & (IData)((vlSelfRef.tb_memory_smoke__DOT__l1_req_addr 
                                   >> (0x3fU & ((IData)(0x14U) 
                                                * (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client))))))
            : 0U);
    vlSelfRef.tb_memory_smoke__DOT__l1_req_ready = 0U;
    if (tb_memory_smoke__DOT__u_l1__DOT__grant_found) {
        vlSelfRef.tb_memory_smoke__DOT__l1_req_ready 
            = ((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_ready) 
               | (3U & ((IData)(1U) << (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client))));
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_handshake 
            = (1U & (((IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_valid) 
                      & (IData)(vlSelfRef.tb_memory_smoke__DOT__l1_req_ready)) 
                     >> (IData)(vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_client)));
    } else {
        vlSelfRef.tb_memory_smoke__DOT__u_l1__DOT__grant_handshake = 0U;
    }
}

void Vtb_memory_smoke___024root___nba_sequent__TOP__0(Vtb_memory_smoke___024root* vlSelf);

void Vtb_memory_smoke___024root___eval_nba(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_nba\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_memory_smoke___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x3ffULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_memory_smoke___024root___act_comb__TOP__0(vlSelf);
    }
}

void Vtb_memory_smoke___024root___timing_resume(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___timing_resume\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hf85b3a82__0.resume(
                                                   "@(posedge tb_memory_smoke.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hf85b3b43__0.resume(
                                                   "@(negedge tb_memory_smoke.clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_he4f62226__0.resume(
                                                   "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__0__client[0]+:1])");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hce1b93bc__0.resume(
                                                   "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__1__client[0]+:1])");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hfd03ddbb__0.resume(
                                                   "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__2__client[0]+:1])");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hd6285ddb__0.resume(
                                                   "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__3__client[0]+:1])");
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h39a94caa__0.resume(
                                                   "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__4__client[0]+:1])");
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h367e0241__0.resume(
                                                   "@( tb_memory_smoke.u_tbu_direct.rsp_valid_q)");
    }
    if ((0x200ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hc47e9d4d__0.resume(
                                                   "@( (3'h7 == tb_memory_smoke.u_mif.state_q))");
    }
    if ((0x400ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_memory_smoke___024root___timing_commit(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___timing_commit\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hf85b3a82__0.commit(
                                                   "@(posedge tb_memory_smoke.clk)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hf85b3b43__0.commit(
                                                   "@(negedge tb_memory_smoke.clk)");
    }
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_he4f62226__0.commit(
                                                   "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__0__client[0]+:1])");
    }
    if ((! (0x10ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hce1b93bc__0.commit(
                                                   "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__1__client[0]+:1])");
    }
    if ((! (0x20ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hfd03ddbb__0.commit(
                                                   "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__2__client[0]+:1])");
    }
    if ((! (0x40ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hd6285ddb__0.commit(
                                                   "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__3__client[0]+:1])");
    }
    if ((! (0x80ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h39a94caa__0.commit(
                                                   "@( tb_memory_smoke.u_l1.rsp_valid_q[__Vtask_tb_memory_smoke.l1_access__4__client[0]+:1])");
    }
    if ((! (0x100ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h367e0241__0.commit(
                                                   "@( tb_memory_smoke.u_tbu_direct.rsp_valid_q)");
    }
    if ((! (0x200ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hc47e9d4d__0.commit(
                                                   "@( (3'h7 == tb_memory_smoke.u_mif.state_q))");
    }
}

void Vtb_memory_smoke___024root___eval_triggers__act(Vtb_memory_smoke___024root* vlSelf);

bool Vtb_memory_smoke___024root___eval_phase__act(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_phase__act\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<11> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_memory_smoke___024root___eval_triggers__act(vlSelf);
    Vtb_memory_smoke___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_memory_smoke___024root___timing_resume(vlSelf);
        Vtb_memory_smoke___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_memory_smoke___024root___eval_phase__nba(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_phase__nba\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_memory_smoke___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_memory_smoke___024root___dump_triggers__nba(Vtb_memory_smoke___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_memory_smoke___024root___dump_triggers__act(Vtb_memory_smoke___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_memory_smoke___024root___eval(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtb_memory_smoke___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("memory/tb_memory_smoke.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_memory_smoke___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("memory/tb_memory_smoke.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_memory_smoke___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_memory_smoke___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_memory_smoke___024root___eval_debug_assertions(Vtb_memory_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memory_smoke___024root___eval_debug_assertions\n"); );
    Vtb_memory_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
