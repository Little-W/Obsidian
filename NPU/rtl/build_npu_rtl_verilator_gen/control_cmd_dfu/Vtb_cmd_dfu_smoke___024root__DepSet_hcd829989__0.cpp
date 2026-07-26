// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cmd_dfu_smoke.h for the primary calling header

#include "Vtb_cmd_dfu_smoke__pch.h"
#include "Vtb_cmd_dfu_smoke___024root.h"

VlCoroutine Vtb_cmd_dfu_smoke___024root___eval_initial__TOP__Vtiming__0(Vtb_cmd_dfu_smoke___024root* vlSelf);
VlCoroutine Vtb_cmd_dfu_smoke___024root___eval_initial__TOP__Vtiming__1(Vtb_cmd_dfu_smoke___024root* vlSelf);
VlCoroutine Vtb_cmd_dfu_smoke___024root___eval_initial__TOP__Vtiming__2(Vtb_cmd_dfu_smoke___024root* vlSelf);

void Vtb_cmd_dfu_smoke___024root___eval_initial(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_initial\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_cmd_dfu_smoke___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_cmd_dfu_smoke___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_cmd_dfu_smoke___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

void Vtb_cmd_dfu_smoke___024root___act_comb__TOP__0(Vtb_cmd_dfu_smoke___024root* vlSelf);

void Vtb_cmd_dfu_smoke___024root___eval_act(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_act\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x3dULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb_cmd_dfu_smoke___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_cmd_dfu_smoke___024root___act_comb__TOP__0(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___act_comb__TOP__0\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__input_handshake 
        = (((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
            | (1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) 
           & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake 
        = ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__ts_cmd_ready) 
           & (0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__mem_request_handshake 
        = ((1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q)) 
           & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_req_ready));
}

void Vtb_cmd_dfu_smoke___024root___nba_sequent__TOP__0(Vtb_cmd_dfu_smoke___024root* vlSelf);
void Vtb_cmd_dfu_smoke___024root___nba_comb__TOP__0(Vtb_cmd_dfu_smoke___024root* vlSelf);

void Vtb_cmd_dfu_smoke___024root___eval_nba(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_nba\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_cmd_dfu_smoke___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x3fULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_cmd_dfu_smoke___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_cmd_dfu_smoke___024root___nba_comb__TOP__0(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___nba_comb__TOP__0\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__output_handshake 
        = ((IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__ts_cmd_ready) 
           & (0U != (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__fifo_count_q)));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__input_handshake 
        = (((0U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q)) 
            | (1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_cfe__DOT__state_q))) 
           & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__cmd_valid));
    vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__mem_request_handshake 
        = ((1U == (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__u_dfu__DOT__state_q)) 
           & (IData)(vlSelfRef.tb_cmd_dfu_smoke__DOT__mem_req_ready));
}

void Vtb_cmd_dfu_smoke___024root___timing_resume(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___timing_resume\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hefdb7d35__0.resume(
                                                   "@(posedge tb_cmd_dfu_smoke.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hefdb7bf8__0.resume(
                                                   "@(negedge tb_cmd_dfu_smoke.clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h165597e7__0.resume(
                                                   "@( (3'h5 == tb_cmd_dfu_smoke.u_cfe.state_q))");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hbc886484__0.resume(
                                                   "@( (4'h0 != tb_cmd_dfu_smoke.u_cfe.fifo_count_q))");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hfb15c31a__0.resume(
                                                   "@( (3'h4 == tb_cmd_dfu_smoke.u_dfu.state_q))");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_cmd_dfu_smoke___024root___timing_commit(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___timing_commit\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hefdb7d35__0.commit(
                                                   "@(posedge tb_cmd_dfu_smoke.clk)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hefdb7bf8__0.commit(
                                                   "@(negedge tb_cmd_dfu_smoke.clk)");
    }
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h165597e7__0.commit(
                                                   "@( (3'h5 == tb_cmd_dfu_smoke.u_cfe.state_q))");
    }
    if ((! (0x10ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hbc886484__0.commit(
                                                   "@( (4'h0 != tb_cmd_dfu_smoke.u_cfe.fifo_count_q))");
    }
    if ((! (0x20ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hfb15c31a__0.commit(
                                                   "@( (3'h4 == tb_cmd_dfu_smoke.u_dfu.state_q))");
    }
}

void Vtb_cmd_dfu_smoke___024root___eval_triggers__act(Vtb_cmd_dfu_smoke___024root* vlSelf);

bool Vtb_cmd_dfu_smoke___024root___eval_phase__act(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_phase__act\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<7> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_cmd_dfu_smoke___024root___eval_triggers__act(vlSelf);
    Vtb_cmd_dfu_smoke___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_cmd_dfu_smoke___024root___timing_resume(vlSelf);
        Vtb_cmd_dfu_smoke___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_cmd_dfu_smoke___024root___eval_phase__nba(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_phase__nba\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_cmd_dfu_smoke___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___dump_triggers__nba(Vtb_cmd_dfu_smoke___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cmd_dfu_smoke___024root___dump_triggers__act(Vtb_cmd_dfu_smoke___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_cmd_dfu_smoke___024root___eval(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtb_cmd_dfu_smoke___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("control/tb_cmd_dfu_smoke.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_cmd_dfu_smoke___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("control/tb_cmd_dfu_smoke.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_cmd_dfu_smoke___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_cmd_dfu_smoke___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_cmd_dfu_smoke___024root___eval_debug_assertions(Vtb_cmd_dfu_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cmd_dfu_smoke___024root___eval_debug_assertions\n"); );
    Vtb_cmd_dfu_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
