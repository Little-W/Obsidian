// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_scheduler_ctl_smoke.h for the primary calling header

#include "Vtb_scheduler_ctl_smoke__pch.h"
#include "Vtb_scheduler_ctl_smoke___024root.h"

VlCoroutine Vtb_scheduler_ctl_smoke___024root___eval_initial__TOP__Vtiming__0(Vtb_scheduler_ctl_smoke___024root* vlSelf);
VlCoroutine Vtb_scheduler_ctl_smoke___024root___eval_initial__TOP__Vtiming__1(Vtb_scheduler_ctl_smoke___024root* vlSelf);
VlCoroutine Vtb_scheduler_ctl_smoke___024root___eval_initial__TOP__Vtiming__2(Vtb_scheduler_ctl_smoke___024root* vlSelf);

void Vtb_scheduler_ctl_smoke___024root___eval_initial(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___eval_initial\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_scheduler_ctl_smoke___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_scheduler_ctl_smoke___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_scheduler_ctl_smoke___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vtb_scheduler_ctl_smoke___024root___eval_initial__TOP__Vtiming__0____Vfork_1__1(Vtb_scheduler_ctl_smoke___024root* vlSelf, VlForkSync __Vfork_1__sync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___eval_initial__TOP__Vtiming__0____Vfork_1__1\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtask_tb_scheduler_ctl_smoke__DOT__complete_matrix__9__status;
    __Vtask_tb_scheduler_ctl_smoke__DOT__complete_matrix__9__status = 0;
    QData/*63:0*/ __Vtask_tb_scheduler_ctl_smoke__DOT__complete_matrix__9__progress;
    __Vtask_tb_scheduler_ctl_smoke__DOT__complete_matrix__9__progress = 0;
    // Body
    __Vtask_tb_scheduler_ctl_smoke__DOT__complete_matrix__9__progress = 0x456ULL;
    __Vtask_tb_scheduler_ctl_smoke__DOT__complete_matrix__9__status = 0U;
    co_await vlSelfRef.__VtrigSched_h876d4562__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_scheduler_ctl_smoke.clk)", 
                                                         "control/tb_scheduler_ctl_smoke.sv", 
                                                         440);
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_command_id 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_accepted_command_id_q;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_status 
        = __Vtask_tb_scheduler_ctl_smoke__DOT__complete_matrix__9__status;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_fault_addr = 0ULL;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_progress 
        = __Vtask_tb_scheduler_ctl_smoke__DOT__complete_matrix__9__progress;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_valid = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_q)))) {
        co_await vlSelfRef.__VtrigSched_h876d4562__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_scheduler_ctl_smoke.clk)", 
                                                             "control/tb_scheduler_ctl_smoke.sv", 
                                                             446);
    }
    co_await vlSelfRef.__VtrigSched_h876d44a3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_scheduler_ctl_smoke.clk)", 
                                                         "control/tb_scheduler_ctl_smoke.sv", 
                                                         447);
    co_await vlSelfRef.__VtrigSched_h876d4562__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_scheduler_ctl_smoke.clk)", 
                                                         "control/tb_scheduler_ctl_smoke.sv", 
                                                         448);
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_done_valid = 0U;
    __Vfork_1__sync.done("control/tb_scheduler_ctl_smoke.sv", 
                         502);
}

VL_INLINE_OPT VlCoroutine Vtb_scheduler_ctl_smoke___024root___eval_initial__TOP__Vtiming__0____Vfork_1__0(Vtb_scheduler_ctl_smoke___024root* vlSelf, VlForkSync __Vfork_1__sync) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___eval_initial__TOP__Vtiming__0____Vfork_1__0\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtask_tb_scheduler_ctl_smoke__DOT__complete_dma__8__status;
    __Vtask_tb_scheduler_ctl_smoke__DOT__complete_dma__8__status = 0;
    QData/*63:0*/ __Vtask_tb_scheduler_ctl_smoke__DOT__complete_dma__8__progress;
    __Vtask_tb_scheduler_ctl_smoke__DOT__complete_dma__8__progress = 0;
    // Body
    __Vtask_tb_scheduler_ctl_smoke__DOT__complete_dma__8__progress = 0x123ULL;
    __Vtask_tb_scheduler_ctl_smoke__DOT__complete_dma__8__status = 0U;
    co_await vlSelfRef.__VtrigSched_h876d4562__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_scheduler_ctl_smoke.clk)", 
                                                         "control/tb_scheduler_ctl_smoke.sv", 
                                                         422);
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_command_id 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_accepted_command_id_q;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_status 
        = __Vtask_tb_scheduler_ctl_smoke__DOT__complete_dma__8__status;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_fault_addr = 0ULL;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_progress 
        = __Vtask_tb_scheduler_ctl_smoke__DOT__complete_dma__8__progress;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_valid = 1U;
    while ((1U & (~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_q)))) {
        co_await vlSelfRef.__VtrigSched_h876d4562__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_scheduler_ctl_smoke.clk)", 
                                                             "control/tb_scheduler_ctl_smoke.sv", 
                                                             428);
    }
    co_await vlSelfRef.__VtrigSched_h876d44a3__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_scheduler_ctl_smoke.clk)", 
                                                         "control/tb_scheduler_ctl_smoke.sv", 
                                                         429);
    co_await vlSelfRef.__VtrigSched_h876d4562__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_scheduler_ctl_smoke.clk)", 
                                                         "control/tb_scheduler_ctl_smoke.sv", 
                                                         430);
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_done_valid = 0U;
    __Vfork_1__sync.done("control/tb_scheduler_ctl_smoke.sv", 
                         501);
}

void Vtb_scheduler_ctl_smoke___024root___act_comb__TOP__0(Vtb_scheduler_ctl_smoke___024root* vlSelf);
void Vtb_scheduler_ctl_smoke___024root___act_comb__TOP__1(Vtb_scheduler_ctl_smoke___024root* vlSelf);

void Vtb_scheduler_ctl_smoke___024root___eval_act(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___eval_act\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x3dULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb_scheduler_ctl_smoke___024root___act_comb__TOP__0(vlSelf);
        Vtb_scheduler_ctl_smoke___024root___act_comb__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_scheduler_ctl_smoke___024root___act_comb__TOP__1(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___act_comb__TOP__1\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid;
    tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid = 0;
    IData/*31:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__unnamedblk1__DOT__slot;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__unnamedblk1__DOT__slot = 0;
    IData/*31:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__unnamedblk1__DOT__slot;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__unnamedblk1__DOT__slot = 0;
    CData/*3:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__state;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__state = 0;
    // Body
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__state 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__query_select];
    {
        if ((0U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__state))) {
            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__Vfuncout = 0U;
            goto __Vlabel0;
        }
        if ((4U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__state))) {
            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__Vfuncout = 2U;
            goto __Vlabel0;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__56__state 
                        = __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__state;
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__56__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__56__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__56__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__56__Vfuncout))) {
            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__Vfuncout = 3U;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__Vfuncout = 1U;
        __Vlabel0: ;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__task_query_state 
        = vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__Vfuncout;
    if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
         >> 0x1fU)) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_opcode 
            = (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_opcode));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_engine 
            = (0xfU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_engine));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____VdfgExtracted_hf6182e41__0 
            = (0U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_engine));
    } else {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_opcode 
            = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[2U]);
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_engine 
            = (0xfU & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[1U] 
                        << 4U) | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[1U] 
                                  >> 0x1cU)));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____VdfgExtracted_hf6182e41__0 = 0U;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_is_inline_rearm 
        = ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____VdfgExtracted_hf6182e41__0) 
           & (2U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_opcode)));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0_resolved 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1_resolved 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal;
    if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
         >> 0x1fU)) {
        if (((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0)))
                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0)));
        }
        if (((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1)))
                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1)));
        }
        if (((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)))
                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)));
        }
    }
    tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid = 1U;
    if ((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0))) {
        if ((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0))) 
              | (0U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0)))
                         ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                        [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0))]
                         : 0U))) | ((~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
                                        >> 0x1fU)) 
                                    & (((0xfeU >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0)))
                                         ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                                        [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0))]
                                         : 0U) != (0xfU 
                                                   & ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0) 
                                                      >> 8U)))))) {
            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid = 0U;
        }
    }
    if ((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))) {
        if ((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))) 
              | (0U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1)))
                         ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                        [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))]
                         : 0U))) | ((~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
                                        >> 0x1fU)) 
                                    & (((0xfeU >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1)))
                                         ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                                        [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))]
                                         : 0U) != (0xfU 
                                                   & ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1) 
                                                      >> 8U)))))) {
            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid = 0U;
        }
    }
    if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_is_inline_rearm) {
        if ((1U & ((((((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0)) 
                       | (0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))) 
                      | (0xfffU == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))) 
                     | (0xffU <= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)))) 
                    | (~ ((2U == ((0xfeU >= (0xffU 
                                             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)))
                                   ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                  [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))]
                                   : 0U)) | (3U == 
                                             ((0xfeU 
                                               >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)))
                                               ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                              [(0xffU 
                                                & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))]
                                               : 0U))))) 
                   | ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved;
                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__unnamedblk1__DOT__slot = 0;
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__found = 0U;
                            if ((0xfffU != (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref))) {
                                if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                       [0U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                            [0U];
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                         [0U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                            [0U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                              [0U] 
                                              != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                              [0U]))))) {
                                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__unnamedblk1__DOT__slot = 4U;
                                if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                       [1U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                            [1U];
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                         [1U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                            [1U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                              [1U] 
                                              != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                              [1U]))))) {
                                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                       [2U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                            [2U];
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                         [2U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                            [2U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                              [2U] 
                                              != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                              [2U]))))) {
                                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                       [3U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                            [3U];
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                         [3U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                            [3U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                              [3U] 
                                              != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                              [3U]))))) {
                                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__found = 1U;
                                }
                            }
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__Vfuncout 
                                = vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__found;
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__Vfuncout))))) {
            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid = 0U;
        }
    } else if ((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))) {
        if (((((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))) 
                 | (0U != ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)))
                            ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                           [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))]
                            : 0U))) | ((~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
                                           >> 0x1fU)) 
                                       & (((0xfeU >= 
                                            (0xffU 
                                             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)))
                                            ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                                           [(0xffU 
                                             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))]
                                            : 0U) != 
                                          (0xfU & ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal) 
                                                   >> 8U))))) 
               | ([&]() {
                                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref 
                                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved;
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__unnamedblk1__DOT__slot = 0;
                                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__found = 0U;
                                if ((0xfffU != (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref))) {
                                    if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                           [0U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                                [0U];
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                             [0U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                [0U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                  [0U] 
                                                  != 
                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                  [0U]))))) {
                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__unnamedblk1__DOT__slot = 4U;
                                    if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                           [1U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                                [1U];
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                             [1U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                [1U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                  [1U] 
                                                  != 
                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                  [1U]))))) {
                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                           [2U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                                [2U];
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                             [2U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                [2U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                  [2U] 
                                                  != 
                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                  [2U]))))) {
                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                           [3U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                                [3U];
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                             [3U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                [3U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                  [3U] 
                                                  != 
                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                  [3U]))))) {
                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                }
                                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__Vfuncout 
                                    = vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__found;
                            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__Vfuncout))) 
              | ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved) 
                 == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0_resolved))) 
             | ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved) 
                == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1_resolved)))) {
            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid = 0U;
        }
    }
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[__Vilp1] 
            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_flat[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____VdfgExtracted_hf6182e41__0) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[2U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0_resolved)));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[3U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0_resolved)) 
                       >> 0x20U));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[4U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1_resolved)));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[5U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1_resolved)) 
                       >> 0x20U));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[8U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[9U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)) 
                       >> 0x20U));
        if (((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_is_inline_rearm) 
             & (0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[2U] 
                = (IData)((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)));
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[3U] 
                = (IData)(((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)) 
                           >> 0x20U));
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[8U] 
                = ((0xffffff00U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[8U]) 
                   | (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)));
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[8U] 
                = ((0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[8U]) 
                   | ((IData)((QData)((IData)((0xfU 
                                               & ((IData)(1U) 
                                                  + 
                                                  ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved) 
                                                   >> 8U)))))) 
                      << 8U));
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[9U] 
                = (((IData)((QData)((IData)((0xfU & 
                                             ((IData)(1U) 
                                              + ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved) 
                                                 >> 8U)))))) 
                    >> 0x18U) | ((IData)(((QData)((IData)(
                                                          (0xfU 
                                                           & ((IData)(1U) 
                                                              + 
                                                              ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved) 
                                                               >> 8U))))) 
                                          >> 0x20U)) 
                                 << 8U));
        }
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_static_valid 
        = ((IData)(tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid) 
           & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
               >> 0x1fU) ? (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_valid)
               : (((((IData)((((0U == (0x3fU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[0U])) 
                               & (0U == (0xc0000U & 
                                         vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[2U]))) 
                              & (0x1000000U == (0xff000000U 
                                                & vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U])))) 
                     & ([&]() {
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode 
                                        = (0xffU & 
                                           vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[2U]);
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine 
                                        = (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[1U] 
                                           >> 0x1cU);
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__Vfuncout 
                                        = ((1U & (~ 
                                                  ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine) 
                                                   >> 3U))) 
                                           && ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine))
                                                ? (
                                                   (1U 
                                                    & (~ 
                                                       ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine) 
                                                        >> 1U))) 
                                                   && ((1U 
                                                        & (~ (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine))) 
                                                       && (((((0x80U 
                                                               == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)) 
                                                              | (0x81U 
                                                                 == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                             | (0x82U 
                                                                == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                            | (0x84U 
                                                               == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                           | (0x86U 
                                                              == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)))))
                                                : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine))
                                                     ? 
                                                    ((((((((((0x60U 
                                                              == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)) 
                                                             | (0x61U 
                                                                == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                            | (0x62U 
                                                               == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                           | (0x63U 
                                                              == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                          | (0x64U 
                                                             == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                         | (0x65U 
                                                            == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                        | (0x66U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                       | (0x67U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                      | (0x68U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                     | (0x69U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)))
                                                     : 
                                                    ((((0x40U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)) 
                                                       | (0x41U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                      | (0x42U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                     | (0x43U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine))
                                                     ? 
                                                    ((((((0x20U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)) 
                                                         | (0x21U 
                                                            == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                        | (0x22U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                       | (0x23U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                      | (0x24U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                     | (0x25U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)))
                                                     : 
                                                    (((((0U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)) 
                                                        | (1U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                       | (2U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                      | (3U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                     | (4U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)))))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__Vfuncout))) 
                    & ([&]() {
                                vlSelfRef.__Vfunc_npu_event_ref_valid__41__event_ref 
                                    = (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[2U] 
                                       >> 0x14U);
                                vlSelfRef.__Vfunc_npu_event_ref_valid__41__Vfuncout 
                                    = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__41__event_ref)) 
                                       | (0xffU != 
                                          (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__41__event_ref))));
                            }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__41__Vfuncout))) 
                   & ([&]() {
                            vlSelfRef.__Vfunc_npu_event_ref_valid__42__event_ref 
                                = (0xfffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U]);
                            vlSelfRef.__Vfunc_npu_event_ref_valid__42__Vfuncout 
                                = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__42__event_ref)) 
                                   | (0xffU != (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__42__event_ref))));
                        }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__42__Vfuncout))) 
                  & ([&]() {
                        vlSelfRef.__Vfunc_npu_event_ref_valid__43__event_ref 
                            = (0xfffU & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
                                         >> 0xcU));
                        vlSelfRef.__Vfunc_npu_event_ref_valid__43__Vfuncout 
                            = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__43__event_ref)) 
                               | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__43__event_ref))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__43__Vfuncout)))));
}

void Vtb_scheduler_ctl_smoke___024root___nba_sequent__TOP__0(Vtb_scheduler_ctl_smoke___024root* vlSelf);
void Vtb_scheduler_ctl_smoke___024root___nba_sequent__TOP__1(Vtb_scheduler_ctl_smoke___024root* vlSelf);
void Vtb_scheduler_ctl_smoke___024root___nba_comb__TOP__0(Vtb_scheduler_ctl_smoke___024root* vlSelf);
void Vtb_scheduler_ctl_smoke___024root___nba_comb__TOP__1(Vtb_scheduler_ctl_smoke___024root* vlSelf);
void Vtb_scheduler_ctl_smoke___024root___nba_comb__TOP__2(Vtb_scheduler_ctl_smoke___024root* vlSelf);

void Vtb_scheduler_ctl_smoke___024root___eval_nba(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___eval_nba\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_scheduler_ctl_smoke___024root___nba_sequent__TOP__0(vlSelf);
        Vtb_scheduler_ctl_smoke___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x3dULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_scheduler_ctl_smoke___024root___nba_comb__TOP__0(vlSelf);
        Vtb_scheduler_ctl_smoke___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((0x3fULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_scheduler_ctl_smoke___024root___nba_comb__TOP__2(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_scheduler_ctl_smoke___024root___nba_sequent__TOP__1(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___nba_sequent__TOP__1\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select_found;
    tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select_found = 0;
    CData/*0:0*/ tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select_found;
    tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select_found = 0;
    // Body
    if (((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q) 
           >> 2U) & (0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                     [2U])) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                               [2U] == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q
                               [2U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__state 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                        [2U];
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__Vfuncout))) {
            if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                  [2U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                           [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                    [2U];
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [2U];
            }
        } else {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_q) 
           >> 3U) & (0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                     [3U])) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                               [3U] == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_target_seq_q
                               [3U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__state 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                        [3U];
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__39__Vfuncout))) {
            if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                  [3U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                           [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                    [3U];
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [3U];
            }
        } else {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_valid 
        = vlSelfRef.__Vdly__tb_scheduler_ctl_smoke__DOT__df_fetch_rsp_valid;
    if (vlSelfRef.__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v1) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_addr_q[vlSelfRef.__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_addr_q__v0] 
            = vlSelfRef.__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_addr_q__v0;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q[vlSelfRef.__VdlyDim0__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q__v0] 
            = vlSelfRef.__VdlyVal__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q__v0;
    }
    if (vlSelfRef.__VdlySet__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q__v22) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_addr_q[0U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_addr_q[1U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_addr_q[2U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_addr_q[3U] = 0ULL;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q[0U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q[1U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q[2U] = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q[3U] = 0U;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_active_q 
        = vlSelfRef.__Vdly__tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_active_q;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_found = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select = 0U;
    if ((1U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
         [0U])) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select = 0U;
    }
    if (((1U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [1U]) & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_found)) 
                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                      [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select])))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select = 1U;
    }
    if (((1U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [2U]) & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_found)) 
                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                      [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select])))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select = 2U;
    }
    if (((1U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [3U]) & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_found)) 
                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                      [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select])))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select = 3U;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_command_id 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_engine 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_opcode 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__completion_progress 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_progress_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__completion_select];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_valid 
        = ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_active_q)) 
           & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_found));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_command_id 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__df_fetch_engine 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__fetch_select];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_success[0U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout = 1U;
                        goto __Vlabel0;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout = 0U;
                        goto __Vlabel0;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref))]
                                      : 0U)));
                    __Vlabel0: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout = 1U;
                        goto __Vlabel1;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref))]
                                      : 0U)));
                    __Vlabel1: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout)));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_failed[0U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout = 0U;
                        goto __Vlabel2;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout = 1U;
                        goto __Vlabel2;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref))]
                                      : 0U)));
                    __Vlabel2: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout = 1U;
                        goto __Vlabel3;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref))]
                                      : 0U)));
                    __Vlabel3: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout)));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[0U] = 0U;
    if ((1U & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                [0U] >> 4U) | (4U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                               [0U])))) {
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[0U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[0U] = 1U;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_success[1U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout = 1U;
                        goto __Vlabel4;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout = 0U;
                        goto __Vlabel4;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref))]
                                      : 0U)));
                    __Vlabel4: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout = 1U;
                        goto __Vlabel5;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout = 0U;
                        goto __Vlabel5;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref))]
                                      : 0U)));
                    __Vlabel5: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout)));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_failed[1U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout = 0U;
                        goto __Vlabel6;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout = 1U;
                        goto __Vlabel6;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref))]
                                      : 0U)));
                    __Vlabel6: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout = 0U;
                        goto __Vlabel7;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout = 1U;
                        goto __Vlabel7;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref))]
                                      : 0U)));
                    __Vlabel7: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout)));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[1U] = 0U;
    if ((1U & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                [1U] >> 4U) | (4U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                               [1U])))) {
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[1U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[1U] = 1U;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_success[2U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout = 1U;
                        goto __Vlabel8;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout = 0U;
                        goto __Vlabel8;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref))]
                                      : 0U)));
                    __Vlabel8: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout = 1U;
                        goto __Vlabel9;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout = 0U;
                        goto __Vlabel9;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref))]
                                      : 0U)));
                    __Vlabel9: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout)));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_failed[2U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout = 0U;
                        goto __Vlabel10;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout = 1U;
                        goto __Vlabel10;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref))]
                                      : 0U)));
                    __Vlabel10: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout = 0U;
                        goto __Vlabel11;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout = 1U;
                        goto __Vlabel11;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref))]
                                      : 0U)));
                    __Vlabel11: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout)));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[2U] = 0U;
    if ((1U & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                [2U] >> 4U) | (4U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                               [2U])))) {
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[2U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[2U] = 1U;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_success[3U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout = 1U;
                        goto __Vlabel12;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout = 0U;
                        goto __Vlabel12;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__event_ref))]
                                      : 0U)));
                    __Vlabel12: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__48__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout = 1U;
                        goto __Vlabel13;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout = 0U;
                        goto __Vlabel13;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__event_ref))]
                                      : 0U)));
                    __Vlabel13: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_success__49__Vfuncout)));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dependency_failed[3U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout = 0U;
                        goto __Vlabel14;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout = 1U;
                        goto __Vlabel14;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__event_ref))]
                                      : 0U)));
                    __Vlabel14: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__50__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout = 0U;
                        goto __Vlabel15;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout = 1U;
                        goto __Vlabel15;
                    }
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref)))
                              ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref)))
                                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__event_ref))]
                                      : 0U)));
                    __Vlabel15: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_is_failed__51__Vfuncout)));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[3U] = 0U;
    if ((1U & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                [3U] >> 4U) | (4U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_opcode_q
                               [3U])))) {
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__52__Vfuncout))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[3U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__53__Vfuncout))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked[3U] = 1U;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select_found = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select_found = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select = 0U;
    if (((3U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                   [0U]))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select_found = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select = 0U;
        if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                          [0U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                              [0U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                               [0U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select])))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select = 0U;
                        }
                    }
                }
                if ((2U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                     [0U])) {
                    if ((1U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                         [0U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select])))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select = 0U;
                        }
                    }
                }
            }
            if ((4U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                 [0U])) {
                if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                              [0U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                               [0U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select])))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select = 0U;
                        }
                    }
                }
            }
        }
    } else {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select_found = 0U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select = 0U;
    }
    if (((3U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                          [1U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                              [1U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                               [1U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select])))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select = 1U;
                        }
                    }
                }
                if ((2U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                     [1U])) {
                    if ((1U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                         [1U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select])))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select = 1U;
                        }
                    }
                }
            }
            if ((4U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                 [1U])) {
                if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                              [1U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                               [1U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select])))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select = 1U;
                        }
                    }
                }
            }
        }
    }
    tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select_found = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select = 0U;
    if (((3U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                   [0U]))) {
        if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                          [0U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                              [0U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                         [0U])) {
                        if ((1U & ((~ (IData)(tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select])))) {
                            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select = 0U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                          [1U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                              [1U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                         [1U])) {
                        if ((1U & ((~ (IData)(tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select])))) {
                            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                          [2U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                              [2U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                               [2U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select])))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select = 2U;
                        }
                    }
                    if ((1U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                         [2U])) {
                        if ((1U & ((~ (IData)(tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select])))) {
                            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select = 2U;
                        }
                    }
                }
                if ((2U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                     [2U])) {
                    if ((1U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                         [2U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select])))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select = 2U;
                        }
                    }
                }
            }
            if ((4U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                 [2U])) {
                if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                              [2U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                               [2U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select])))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select = 2U;
                        }
                    }
                }
            }
        }
    }
    tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select_found = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select = 0U;
    if (((3U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                   [0U]))) {
        if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                          [0U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                     [0U])) {
                    if ((1U & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                               [0U]))) {
                        if ((1U & ((~ (IData)(tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select])))) {
                            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select = 0U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                          [1U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                     [1U])) {
                    if ((1U & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                               [1U]))) {
                        if ((1U & ((~ (IData)(tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select])))) {
                            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                          [2U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                     [2U])) {
                    if ((1U & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                               [2U]))) {
                        if ((1U & ((~ (IData)(tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select])))) {
                            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select = 2U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [3U]) & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__order_blocked
                   [3U]))) {
        if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                      [3U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                          [3U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                              [3U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                               [3U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select])))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__control_select = 3U;
                        }
                    }
                    if ((1U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                         [3U])) {
                        if ((1U & ((~ (IData)(tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select])))) {
                            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select = 3U;
                        }
                    }
                }
                if ((2U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                     [3U])) {
                    if ((1U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                         [3U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select])))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select = 3U;
                        }
                    }
                    if ((1U & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                               [3U]))) {
                        if ((1U & ((~ (IData)(tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select])))) {
                            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select = 3U;
                        }
                    }
                }
            }
            if ((4U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                 [3U])) {
                if ((1U & (~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                              [3U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                               [3U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select])))) {
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select = 3U;
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__vector_task_valid 
        = ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_active_q)) 
           & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__vector_select_found));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__complex_task_valid 
        = ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_active_q)) 
           & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__complex_select_found));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_valid 
        = ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_active_q)) 
           & (IData)(tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select_found));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[1U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][1U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[2U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][2U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[3U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][3U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[4U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][4U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[5U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][5U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[6U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][6U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[7U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][7U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[8U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][8U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[9U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][9U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0xaU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0xaU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0xbU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0xbU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0xcU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0xcU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0xdU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0xdU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0xeU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0xeU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0xfU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0xfU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x10U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x10U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x11U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x11U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x12U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x12U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x13U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x13U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x14U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x14U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x15U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x15U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x16U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x16U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x17U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x17U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x18U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x18U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x19U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x19U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x1aU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x1aU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x1bU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x1bU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x1cU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x1cU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x1dU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x1dU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x1eU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x1eU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x1fU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x1fU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x20U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x20U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x21U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x21U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x22U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x22U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x23U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x23U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x24U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x24U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x25U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x25U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x26U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x26U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x27U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x27U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x28U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x28U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x29U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x29U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x2aU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x2aU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x2bU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x2bU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x2cU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x2cU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x2dU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x2dU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x2eU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x2eU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x2fU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x2fU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x30U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x30U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x31U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x31U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x32U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x32U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x33U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x33U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x34U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x34U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x35U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x35U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x36U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x36U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x37U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x37U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x38U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x38U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x39U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x39U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x3aU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x3aU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x3bU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x3bU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x3cU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x3cU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x3dU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x3dU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x3eU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x3eU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__dma_task_desc_flat[0x3fU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__dma_select][0x3fU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_valid 
        = ((~ (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_active_q)) 
           & (IData)(tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select_found));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[1U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][1U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[2U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][2U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[3U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][3U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[4U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][4U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[5U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][5U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[6U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][6U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[7U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][7U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[8U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][8U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[9U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][9U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0xaU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0xaU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0xbU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0xbU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0xcU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0xcU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0xdU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0xdU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0xeU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0xeU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0xfU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0xfU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x10U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x10U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x11U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x11U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x12U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x12U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x13U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x13U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x14U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x14U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x15U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x15U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x16U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x16U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x17U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x17U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x18U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x18U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x19U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x19U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x1aU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x1aU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x1bU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x1bU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x1cU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x1cU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x1dU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x1dU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x1eU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x1eU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x1fU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x1fU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x20U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x20U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x21U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x21U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x22U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x22U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x23U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x23U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x24U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x24U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x25U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x25U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x26U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x26U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x27U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x27U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x28U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x28U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x29U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x29U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x2aU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x2aU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x2bU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x2bU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x2cU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x2cU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x2dU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x2dU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x2eU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x2eU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x2fU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x2fU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x30U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x30U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x31U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x31U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x32U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x32U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x33U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x33U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x34U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x34U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x35U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x35U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x36U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x36U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x37U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x37U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x38U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x38U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x39U] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x39U];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x3aU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x3aU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x3bU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x3bU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x3cU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x3cU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x3dU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x3dU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x3eU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x3eU];
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__matrix_task_desc_flat[0x3fU] 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_desc_flat_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__matrix_select][0x3fU];
}

VL_INLINE_OPT void Vtb_scheduler_ctl_smoke___024root___nba_comb__TOP__1(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___nba_comb__TOP__1\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*11:0*/ __Vfunc_npu_cmd_command_id__29__Vfuncout;
    __Vfunc_npu_cmd_command_id__29__Vfuncout = 0;
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_command_id__29__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_command_id__29__command);
    VlWide<4>/*127:0*/ __Vfunc_npu_cmd_header_flags__30__command;
    VL_ZERO_W(128, __Vfunc_npu_cmd_header_flags__30__command);
    // Body
    __Vfunc_npu_cmd_command_id__29__command[0U] = vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[0U];
    __Vfunc_npu_cmd_command_id__29__command[1U] = vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[1U];
    __Vfunc_npu_cmd_command_id__29__command[2U] = vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[2U];
    __Vfunc_npu_cmd_command_id__29__command[3U] = vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U];
    __Vfunc_npu_cmd_command_id__29__Vfuncout = (0xfffU 
                                                & ((__Vfunc_npu_cmd_command_id__29__command[3U] 
                                                    >> 0x1fU)
                                                    ? 
                                                   (0x3ffU 
                                                    & (__Vfunc_npu_cmd_command_id__29__command[3U] 
                                                       >> 0x10U))
                                                    : 
                                                   ((__Vfunc_npu_cmd_command_id__29__command[1U] 
                                                     << 0x10U) 
                                                    | (__Vfunc_npu_cmd_command_id__29__command[1U] 
                                                       >> 0x10U))));
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_command_id 
        = __Vfunc_npu_cmd_command_id__29__Vfuncout;
    __Vfunc_npu_cmd_header_flags__30__command[0U] = 
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[0U];
    __Vfunc_npu_cmd_header_flags__30__command[1U] = 
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[1U];
    __Vfunc_npu_cmd_header_flags__30__command[2U] = 
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[2U];
    __Vfunc_npu_cmd_header_flags__30__command[3U] = 
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U];
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_npu_cmd_header_flags__30__flags = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17311288755175545044ull);
    {
        if ((1U & (~ (__Vfunc_npu_cmd_header_flags__30__command[3U] 
                      >> 0x1fU)))) {
            vlSelfRef.__Vfunc_npu_cmd_header_flags__30__Vfuncout 
                = (0xfffU & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                             >> 8U));
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags = 0U;
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags 
            = ((0xff8U & (IData)(vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags)) 
               | ((4U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                         >> 0x13U)) | ((2U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                                              >> 0x15U)) 
                                       | (1U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                                                >> 0x17U)))));
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags 
            = ((0xfefU & (IData)(vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags)) 
               | (0x10U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                           >> 0x10U)));
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags 
            = ((0xf3fU & (IData)(vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags)) 
               | (0xc0U & (__Vfunc_npu_cmd_header_flags__30__command[2U] 
                           >> 0xcU)));
        vlSelfRef.__Vfunc_npu_cmd_header_flags__30__Vfuncout 
            = vlSelfRef.__Vfunc_npu_cmd_header_flags__30__flags;
        __Vlabel0: ;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_header_flags 
        = vlSelfRef.__Vfunc_npu_cmd_header_flags__30__Vfuncout;
    if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
         >> 0x1fU)) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_opcode 
            = (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_opcode));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_engine 
            = (0xfU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_engine));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____VdfgExtracted_hf6182e41__0 
            = (0U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_engine));
    } else {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_opcode 
            = (0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[2U]);
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_engine 
            = (0xfU & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[1U] 
                        << 4U) | (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[1U] 
                                  >> 0x1cU)));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____VdfgExtracted_hf6182e41__0 = 0U;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_is_inline_rearm 
        = ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____VdfgExtracted_hf6182e41__0) 
           & (2U == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_opcode)));
}

VL_INLINE_OPT void Vtb_scheduler_ctl_smoke___024root___nba_comb__TOP__2(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___nba_comb__TOP__2\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid;
    tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid = 0;
    IData/*31:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__unnamedblk1__DOT__slot;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__unnamedblk1__DOT__slot = 0;
    IData/*31:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__unnamedblk1__DOT__slot;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__unnamedblk1__DOT__slot = 0;
    CData/*3:0*/ __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__state;
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__state = 0;
    // Body
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_target = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_status = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_failure_seq = 0xffffffffffffffffULL;
    if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [0U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0));
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                        [0U];
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__state 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                        [0U];
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__Vfuncout))) {
            if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                  [0U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                           [0U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                    [0U];
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [0U];
            }
        } else {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_target 
                = (1U | (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [1U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0));
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                        [1U];
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__state 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                        [1U];
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__Vfuncout))) {
            if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                  [1U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                           [1U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                    [1U];
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [1U];
            }
        } else {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_target 
                = (2U | (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [2U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0));
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                        [2U];
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__state 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                        [2U];
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__Vfuncout))) {
            if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                  [2U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                           [2U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                    [2U];
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [2U];
            }
        } else {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_target 
                = (4U | (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [3U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0));
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_engine_q
                        [3U];
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__engine_mask_selected__37__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__state 
                        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                        [3U];
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__38__Vfuncout))) {
            if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                  [3U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                           [3U] < vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_status_q
                    [3U];
                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_submit_seq_q
                    [3U];
            }
        } else {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_target 
                = (8U | (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__query_select = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_found = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ack_found = 0U;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select = 0U;
    if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [0U]) & (0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                   [0U]))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__query_select = 0U;
    }
    if (((([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__Vfuncout)) 
          & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
             [0U])) & (0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                       [0U]))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ack_found = 1U;
    }
    if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [0U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                   [0U] == (0xfffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select = 0U;
    }
    if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [1U]) & (0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                   [1U]))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__query_select = 1U;
    }
    if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [1U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                   [1U] == (0xfffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select = 1U;
    }
    if (((([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__Vfuncout)) 
          & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
             [1U])) & (0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                       [1U]))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ack_found = 1U;
    }
    if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [2U]) & (0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                   [2U]))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__query_select = 2U;
    }
    if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [2U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                   [2U] == (0xfffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select = 2U;
    }
    if (((([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__Vfuncout)) 
          & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
             [2U])) & (0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                       [2U]))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ack_found = 1U;
    }
    if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [3U]) & (0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                   [3U]))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__query_select = 3U;
    }
    if (((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
          [3U]) & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                   [3U] == (0xfffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__ctl_arg0))))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ctl_query_select = 3U;
    }
    if (((([&]() {
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__state 
                            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__54__Vfuncout)) 
          & (~ vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_notify_q
             [3U])) & (0U == vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_command_id_q
                       [3U]))) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__ack_found = 1U;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0_resolved 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1_resolved 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1;
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal;
    if ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
         >> 0x1fU)) {
        if (((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0)))
                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0)));
        }
        if (((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1)))
                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1)));
        }
        if (((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)))
                      ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)));
        }
    }
    tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid = 1U;
    if ((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0))) {
        if ((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0))) 
              | (0U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0)))
                         ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                        [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0))]
                         : 0U))) | ((~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
                                        >> 0x1fU)) 
                                    & (((0xfeU >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0)))
                                         ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                                        [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0))]
                                         : 0U) != (0xfU 
                                                   & ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0) 
                                                      >> 8U)))))) {
            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid = 0U;
        }
    }
    if ((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))) {
        if ((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))) 
              | (0U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1)))
                         ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                        [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))]
                         : 0U))) | ((~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
                                        >> 0x1fU)) 
                                    & (((0xfeU >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1)))
                                         ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                                        [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))]
                                         : 0U) != (0xfU 
                                                   & ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1) 
                                                      >> 8U)))))) {
            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid = 0U;
        }
    }
    if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_is_inline_rearm) {
        if ((1U & ((((((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0)) 
                       | (0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1))) 
                      | (0xfffU == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))) 
                     | (0xffU <= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)))) 
                    | (~ ((2U == ((0xfeU >= (0xffU 
                                             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)))
                                   ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                  [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))]
                                   : 0U)) | (3U == 
                                             ((0xfeU 
                                               >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)))
                                               ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                                              [(0xffU 
                                                & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))]
                                               : 0U))))) 
                   | ([&]() {
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref 
                                = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved;
                            __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__unnamedblk1__DOT__slot = 0;
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__found = 0U;
                            if ((0xfffU != (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref))) {
                                if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                       [0U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                            [0U];
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                         [0U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                            [0U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                              [0U] 
                                              != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                              [0U]))))) {
                                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__unnamedblk1__DOT__slot = 4U;
                                if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                       [1U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                            [1U];
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                         [1U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                            [1U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                              [1U] 
                                              != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                              [1U]))))) {
                                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                       [2U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                            [2U];
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                         [2U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                            [2U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                              [2U] 
                                              != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                              [2U]))))) {
                                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                       [3U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                            [3U];
                                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                         [3U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                            [3U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                              [3U] 
                                              != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                              [3U]))))) {
                                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__found = 1U;
                                }
                            }
                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__Vfuncout 
                                = vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__found;
                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__44__Vfuncout))))) {
            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid = 0U;
        }
    } else if ((0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))) {
        if (((((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))) 
                 | (0U != ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)))
                            ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_state_q
                           [(0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))]
                            : 0U))) | ((~ (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
                                           >> 0x1fU)) 
                                       & (((0xfeU >= 
                                            (0xffU 
                                             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal)))
                                            ? vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_generation_q
                                           [(0xffU 
                                             & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal))]
                                            : 0U) != 
                                          (0xfU & ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal) 
                                                   >> 8U))))) 
               | ([&]() {
                                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref 
                                    = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved;
                                __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__unnamedblk1__DOT__slot = 0;
                                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__found = 0U;
                                if ((0xfffU != (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref))) {
                                    if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                           [0U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                                [0U];
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                             [0U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                [0U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                  [0U] 
                                                  != 
                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                  [0U]))))) {
                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__unnamedblk1__DOT__slot = 4U;
                                    if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                           [1U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                                [1U];
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                             [1U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                [1U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                  [1U] 
                                                  != 
                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                  [1U]))))) {
                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                           [2U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                                [2U];
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                             [2U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                [2U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                  [2U] 
                                                  != 
                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                  [2U]))))) {
                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                           [3U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
                                                                [3U];
                                                            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                             [3U] == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                [3U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait1_q
                                                  [3U] 
                                                  != 
                                                  vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_wait0_q
                                                  [3U]))))) {
                                        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                }
                                vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__Vfuncout 
                                    = vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__found;
                            }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_has_live_waiter__46__Vfuncout))) 
              | ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved) 
                 == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0_resolved))) 
             | ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved) 
                == (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1_resolved)))) {
            tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid = 0U;
        }
    }
    __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__state 
        = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__task_state_q
        [vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__query_select];
    {
        if ((0U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__state))) {
            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__Vfuncout = 0U;
            goto __Vlabel0;
        }
        if ((4U == (IData)(__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__state))) {
            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__Vfuncout = 2U;
            goto __Vlabel0;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__56__state 
                        = __Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__state;
                    vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__56__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__56__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__56__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__terminal_state__56__Vfuncout))) {
            vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__Vfuncout = 3U;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__Vfuncout = 1U;
        __Vlabel0: ;
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__task_query_state 
        = vlSelfRef.__Vfunc_tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__software_task_state__55__Vfuncout;
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[__Vilp1] 
            = vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_flat[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    if (vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT____VdfgExtracted_hf6182e41__0) {
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[2U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0_resolved)));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[3U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait0_resolved)) 
                       >> 0x20U));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[4U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1_resolved)));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[5U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_wait1_resolved)) 
                       >> 0x20U));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[8U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)));
        vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[9U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)) 
                       >> 0x20U));
        if (((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_is_inline_rearm) 
             & (0xfffU != (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)))) {
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[2U] 
                = (IData)((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)));
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[3U] 
                = (IData)(((QData)((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)) 
                           >> 0x20U));
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[8U] 
                = ((0xffffff00U & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[8U]) 
                   | (0xffU & (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved)));
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[8U] 
                = ((0xffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[8U]) 
                   | ((IData)((QData)((IData)((0xfU 
                                               & ((IData)(1U) 
                                                  + 
                                                  ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved) 
                                                   >> 8U)))))) 
                      << 8U));
            vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_resolved[9U] 
                = (((IData)((QData)((IData)((0xfU & 
                                             ((IData)(1U) 
                                              + ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved) 
                                                 >> 8U)))))) 
                    >> 0x18U) | ((IData)(((QData)((IData)(
                                                          (0xfU 
                                                           & ((IData)(1U) 
                                                              + 
                                                              ((IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_signal_resolved) 
                                                               >> 8U))))) 
                                          >> 0x20U)) 
                                 << 8U));
        }
    }
    vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__cmd_static_valid 
        = ((IData)(tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__event_resources_valid) 
           & ((vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
               >> 0x1fU) ? (IData)(vlSelfRef.tb_scheduler_ctl_smoke__DOT__u_scheduler__DOT__inline_desc_valid)
               : (((((IData)((((0U == (0x3fU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[0U])) 
                               & (0U == (0xc0000U & 
                                         vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[2U]))) 
                              & (0x1000000U == (0xff000000U 
                                                & vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U])))) 
                     & ([&]() {
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode 
                                        = (0xffU & 
                                           vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[2U]);
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine 
                                        = (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[1U] 
                                           >> 0x1cU);
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__Vfuncout 
                                        = ((1U & (~ 
                                                  ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine) 
                                                   >> 3U))) 
                                           && ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine))
                                                ? (
                                                   (1U 
                                                    & (~ 
                                                       ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine) 
                                                        >> 1U))) 
                                                   && ((1U 
                                                        & (~ (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine))) 
                                                       && (((((0x80U 
                                                               == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)) 
                                                              | (0x81U 
                                                                 == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                             | (0x82U 
                                                                == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                            | (0x84U 
                                                               == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                           | (0x86U 
                                                              == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)))))
                                                : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine))
                                                     ? 
                                                    ((((((((((0x60U 
                                                              == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)) 
                                                             | (0x61U 
                                                                == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                            | (0x62U 
                                                               == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                           | (0x63U 
                                                              == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                          | (0x64U 
                                                             == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                         | (0x65U 
                                                            == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                        | (0x66U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                       | (0x67U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                      | (0x68U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                     | (0x69U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)))
                                                     : 
                                                    ((((0x40U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)) 
                                                       | (0x41U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                      | (0x42U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                     | (0x43U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine))
                                                     ? 
                                                    ((((((0x20U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)) 
                                                         | (0x21U 
                                                            == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                        | (0x22U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                       | (0x23U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                      | (0x24U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                     | (0x25U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)))
                                                     : 
                                                    (((((0U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)) 
                                                        | (1U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                       | (2U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                      | (3U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode))) 
                                                     | (4U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode)))))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__Vfuncout))) 
                    & ([&]() {
                                vlSelfRef.__Vfunc_npu_event_ref_valid__41__event_ref 
                                    = (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[2U] 
                                       >> 0x14U);
                                vlSelfRef.__Vfunc_npu_event_ref_valid__41__Vfuncout 
                                    = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__41__event_ref)) 
                                       | (0xffU != 
                                          (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__41__event_ref))));
                            }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__41__Vfuncout))) 
                   & ([&]() {
                            vlSelfRef.__Vfunc_npu_event_ref_valid__42__event_ref 
                                = (0xfffU & vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U]);
                            vlSelfRef.__Vfunc_npu_event_ref_valid__42__Vfuncout 
                                = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__42__event_ref)) 
                                   | (0xffU != (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__42__event_ref))));
                        }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__42__Vfuncout))) 
                  & ([&]() {
                        vlSelfRef.__Vfunc_npu_event_ref_valid__43__event_ref 
                            = (0xfffU & (vlSelfRef.tb_scheduler_ctl_smoke__DOT__cfe_cmd[3U] 
                                         >> 0xcU));
                        vlSelfRef.__Vfunc_npu_event_ref_valid__43__Vfuncout 
                            = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__43__event_ref)) 
                               | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__43__event_ref))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__43__Vfuncout)))));
}

void Vtb_scheduler_ctl_smoke___024root___timing_resume(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___timing_resume\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h876d44a3__0.resume(
                                                   "@(posedge tb_scheduler_ctl_smoke.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h876d4562__0.resume(
                                                   "@(negedge tb_scheduler_ctl_smoke.clk)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hb6e59a6b__0.resume(
                                                   "@( (((tb_scheduler_ctl_smoke.dma_seen_q & tb_scheduler_ctl_smoke.matrix_seen_q) & tb_scheduler_ctl_smoke.u_scheduler.dma_active_q) & tb_scheduler_ctl_smoke.u_scheduler.matrix_active_q))");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_he8ffc904__0.resume(
                                                   "@( tb_scheduler_ctl_smoke.u_scheduler.ctl_rsp_valid_q)");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h490056a2__0.resume(
                                                   "@( (32'sh2 == tb_scheduler_ctl_smoke.completion_count))");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_scheduler_ctl_smoke___024root___timing_commit(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___timing_commit\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h876d44a3__0.commit(
                                                   "@(posedge tb_scheduler_ctl_smoke.clk)");
    }
    if ((! (4ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h876d4562__0.commit(
                                                   "@(negedge tb_scheduler_ctl_smoke.clk)");
    }
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hb6e59a6b__0.commit(
                                                   "@( (((tb_scheduler_ctl_smoke.dma_seen_q & tb_scheduler_ctl_smoke.matrix_seen_q) & tb_scheduler_ctl_smoke.u_scheduler.dma_active_q) & tb_scheduler_ctl_smoke.u_scheduler.matrix_active_q))");
    }
    if ((! (0x10ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_he8ffc904__0.commit(
                                                   "@( tb_scheduler_ctl_smoke.u_scheduler.ctl_rsp_valid_q)");
    }
    if ((! (0x20ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h490056a2__0.commit(
                                                   "@( (32'sh2 == tb_scheduler_ctl_smoke.completion_count))");
    }
}

void Vtb_scheduler_ctl_smoke___024root___eval_triggers__act(Vtb_scheduler_ctl_smoke___024root* vlSelf);

bool Vtb_scheduler_ctl_smoke___024root___eval_phase__act(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___eval_phase__act\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<7> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_scheduler_ctl_smoke___024root___eval_triggers__act(vlSelf);
    Vtb_scheduler_ctl_smoke___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_scheduler_ctl_smoke___024root___timing_resume(vlSelf);
        Vtb_scheduler_ctl_smoke___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_scheduler_ctl_smoke___024root___eval_phase__nba(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___eval_phase__nba\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_scheduler_ctl_smoke___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_scheduler_ctl_smoke___024root___dump_triggers__nba(Vtb_scheduler_ctl_smoke___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_scheduler_ctl_smoke___024root___dump_triggers__act(Vtb_scheduler_ctl_smoke___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_scheduler_ctl_smoke___024root___eval(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___eval\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtb_scheduler_ctl_smoke___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("control/tb_scheduler_ctl_smoke.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_scheduler_ctl_smoke___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("control/tb_scheduler_ctl_smoke.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_scheduler_ctl_smoke___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_scheduler_ctl_smoke___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_scheduler_ctl_smoke___024root___eval_debug_assertions(Vtb_scheduler_ctl_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_scheduler_ctl_smoke___024root___eval_debug_assertions\n"); );
    Vtb_scheduler_ctl_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
