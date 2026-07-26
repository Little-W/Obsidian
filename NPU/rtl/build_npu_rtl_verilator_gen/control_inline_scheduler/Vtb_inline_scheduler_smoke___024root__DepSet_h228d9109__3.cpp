// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_inline_scheduler_smoke.h for the primary calling header

#include "Vtb_inline_scheduler_smoke__pch.h"
#include "Vtb_inline_scheduler_smoke__Syms.h"
#include "Vtb_inline_scheduler_smoke___024root.h"

VL_INLINE_OPT void Vtb_inline_scheduler_smoke___024root___nba_comb__TOP__1(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___nba_comb__TOP__1\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
         >> 0x1fU)) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_opcode 
            = (0xffU & (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode.opcode_o));
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_engine 
            = (0xfU & (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode.engine_o));
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT____VdfgExtracted_hf6182e41__0 
            = (0U == (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_engine));
    } else {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_opcode 
            = (0xffU & vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U]);
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_engine 
            = (0xfU & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] 
                        << 4U) | (vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] 
                                  >> 0x1cU)));
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT____VdfgExtracted_hf6182e41__0 = 0U;
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_is_inline_rearm 
        = ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT____VdfgExtracted_hf6182e41__0) 
           & (2U == (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_opcode)));
}

VL_INLINE_OPT void Vtb_inline_scheduler_smoke___024root___nba_comb__TOP__2(Vtb_inline_scheduler_smoke___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_inline_scheduler_smoke___024root___nba_comb__TOP__2\n"); );
    Vtb_inline_scheduler_smoke__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_inline_scheduler_smoke__DOT__dut__DOT__event_resources_valid;
    tb_inline_scheduler_smoke__DOT__dut__DOT__event_resources_valid = 0;
    IData/*31:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__unnamedblk1__DOT__slot;
    __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__unnamedblk1__DOT__slot = 0;
    IData/*31:0*/ __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__unnamedblk1__DOT__slot;
    __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__unnamedblk1__DOT__slot = 0;
    // Body
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0_resolved 
        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1_resolved 
        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1;
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved 
        = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal;
    if ((vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
         >> 0x1fU)) {
        if (((0xfffU != (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0)))
                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0)));
        }
        if (((0xfffU != (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1)))
                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1)));
        }
        if (((0xfffU != (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal))))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal)))
                      ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal)));
        }
    }
    tb_inline_scheduler_smoke__DOT__dut__DOT__event_resources_valid = 1U;
    if ((0xfffU != (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0))) {
        if ((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0))) 
              | (0U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0)))
                         ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                        [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0))]
                         : 0U))) | ((~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
                                        >> 0x1fU)) 
                                    & (((0xfeU >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0)))
                                         ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                                        [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0))]
                                         : 0U) != (0xfU 
                                                   & ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0) 
                                                      >> 8U)))))) {
            tb_inline_scheduler_smoke__DOT__dut__DOT__event_resources_valid = 0U;
        }
    }
    if ((0xfffU != (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1))) {
        if ((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1))) 
              | (0U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1)))
                         ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                        [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1))]
                         : 0U))) | ((~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
                                        >> 0x1fU)) 
                                    & (((0xfeU >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1)))
                                         ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                                        [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1))]
                                         : 0U) != (0xfU 
                                                   & ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1) 
                                                      >> 8U)))))) {
            tb_inline_scheduler_smoke__DOT__dut__DOT__event_resources_valid = 0U;
        }
    }
    if (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_is_inline_rearm) {
        if ((1U & ((((((0xfffU != (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0)) 
                       | (0xfffU != (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1))) 
                      | (0xfffU == (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal))) 
                     | (0xffU <= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal)))) 
                    | (~ ((2U == ((0xfeU >= (0xffU 
                                             & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal)))
                                   ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                  [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal))]
                                   : 0U)) | (3U == 
                                             ((0xfeU 
                                               >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal)))
                                               ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                                              [(0xffU 
                                                & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal))]
                                               : 0U))))) 
                   | ([&]() {
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref 
                                = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved;
                            __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__unnamedblk1__DOT__slot = 0;
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__found = 0U;
                            if ((0xfffU != (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref))) {
                                if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                       [0U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                            [0U];
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                         [0U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                            [0U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                              [0U] 
                                              != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                              [0U]))))) {
                                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__unnamedblk1__DOT__slot = 8U;
                                if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                       [1U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                            [1U];
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                         [1U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                            [1U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                              [1U] 
                                              != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                              [1U]))))) {
                                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                       [2U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                            [2U];
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                         [2U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                            [2U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                              [2U] 
                                              != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                              [2U]))))) {
                                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                       [3U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                            [3U];
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                         [3U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                            [3U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                              [3U] 
                                              != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                              [3U]))))) {
                                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                       [4U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                            [4U];
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                         [4U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                            [4U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                              [4U] 
                                              != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                              [4U]))))) {
                                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                       [5U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                            [5U];
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                         [5U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                            [5U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                              [5U] 
                                              != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                              [5U]))))) {
                                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                       [6U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                            [6U];
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                         [6U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                            [6U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                              [6U] 
                                              != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                              [6U]))))) {
                                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                       [7U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state 
                                                            = 
                                                            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                            [7U];
                                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__45__Vfuncout)))) 
                                     & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                         [7U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                        | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                            [7U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__event_ref)) 
                                           & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                              [7U] 
                                              != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                              [7U]))))) {
                                    vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__found = 1U;
                                }
                            }
                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__Vfuncout 
                                = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__found;
                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__44__Vfuncout))))) {
            tb_inline_scheduler_smoke__DOT__dut__DOT__event_resources_valid = 0U;
        }
    } else if ((0xfffU != (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal))) {
        if (((((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal))) 
                 | (0U != ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal)))
                            ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_state_q
                           [(0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal))]
                            : 0U))) | ((~ (vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
                                           >> 0x1fU)) 
                                       & (((0xfeU >= 
                                            (0xffU 
                                             & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal)))
                                            ? vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__event_generation_q
                                           [(0xffU 
                                             & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal))]
                                            : 0U) != 
                                          (0xfU & ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal) 
                                                   >> 8U))))) 
               | ([&]() {
                                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref 
                                    = vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved;
                                __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__unnamedblk1__DOT__slot = 0;
                                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__found = 0U;
                                if ((0xfffU != (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref))) {
                                    if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                           [0U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                                [0U];
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                             [0U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                [0U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                  [0U] 
                                                  != 
                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                                  [0U]))))) {
                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    __Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__unnamedblk1__DOT__slot = 8U;
                                    if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                           [1U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                                [1U];
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                             [1U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                [1U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                  [1U] 
                                                  != 
                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                                  [1U]))))) {
                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                           [2U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                                [2U];
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                             [2U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                [2U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                  [2U] 
                                                  != 
                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                                  [2U]))))) {
                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                           [3U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                                [3U];
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                             [3U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                [3U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                  [3U] 
                                                  != 
                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                                  [3U]))))) {
                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                           [4U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                                [4U];
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                             [4U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                [4U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                  [4U] 
                                                  != 
                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                                  [4U]))))) {
                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                           [5U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                                [5U];
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                             [5U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                [5U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                  [5U] 
                                                  != 
                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                                  [5U]))))) {
                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                           [6U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                                [6U];
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                             [6U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                [6U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                  [6U] 
                                                  != 
                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                                  [6U]))))) {
                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                           [7U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state 
                                                                = 
                                                                vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_state_q
                                                                [7U];
                                                            vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__terminal_state__47__Vfuncout)))) 
                                         & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                             [7U] == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                            | ((vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                [7U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__event_ref)) 
                                               & (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait1_q
                                                  [7U] 
                                                  != 
                                                  vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__task_wait0_q
                                                  [7U]))))) {
                                        vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__found = 1U;
                                    }
                                }
                                vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__Vfuncout 
                                    = vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__found;
                            }(), (IData)(vlSelfRef.__Vfunc_tb_inline_scheduler_smoke__DOT__dut__DOT__event_has_live_waiter__46__Vfuncout))) 
              | ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved) 
                 == (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0_resolved))) 
             | ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved) 
                == (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1_resolved)))) {
            tb_inline_scheduler_smoke__DOT__dut__DOT__event_resources_valid = 0U;
        }
    }
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[__Vilp1] 
            = vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode.desc_flat_o[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    if (vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT____VdfgExtracted_hf6182e41__0) {
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[2U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0_resolved)));
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[3U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait0_resolved)) 
                       >> 0x20U));
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[4U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1_resolved)));
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[5U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_wait1_resolved)) 
                       >> 0x20U));
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[8U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved)));
        vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[9U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved)) 
                       >> 0x20U));
        if (((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_is_inline_rearm) 
             & (0xfffU != (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved)))) {
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[2U] 
                = (IData)((QData)((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved)));
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[3U] 
                = (IData)(((QData)((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved)) 
                           >> 0x20U));
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[8U] 
                = ((0xffffff00U & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[8U]) 
                   | (0xffU & (IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved)));
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[8U] 
                = ((0xffU & vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[8U]) 
                   | ((IData)((QData)((IData)((0xfU 
                                               & ((IData)(1U) 
                                                  + 
                                                  ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved) 
                                                   >> 8U)))))) 
                      << 8U));
            vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__inline_desc_resolved[9U] 
                = (((IData)((QData)((IData)((0xfU & 
                                             ((IData)(1U) 
                                              + ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved) 
                                                 >> 8U)))))) 
                    >> 0x18U) | ((IData)(((QData)((IData)(
                                                          (0xfU 
                                                           & ((IData)(1U) 
                                                              + 
                                                              ((IData)(vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_signal_resolved) 
                                                               >> 8U))))) 
                                          >> 0x20U)) 
                                 << 8U));
        }
    }
    vlSelfRef.tb_inline_scheduler_smoke__DOT__dut__DOT__cmd_static_valid 
        = ((IData)(tb_inline_scheduler_smoke__DOT__dut__DOT__event_resources_valid) 
           & ((vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
               >> 0x1fU) ? (IData)(vlSymsp->TOP__tb_inline_scheduler_smoke__DOT__dut__DOT__u_inline_desc_decode.valid_o)
               : (((((IData)((((0U == (0x3fU & vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[0U])) 
                               & (0U == (0xc0000U & 
                                         vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U]))) 
                              & (0x1000000U == (0xff000000U 
                                                & vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U])))) 
                     & ([&]() {
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__opcode 
                                        = (0xffU & 
                                           vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U]);
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__40__engine 
                                        = (vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[1U] 
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
                                    = (vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[2U] 
                                       >> 0x14U);
                                vlSelfRef.__Vfunc_npu_event_ref_valid__41__Vfuncout 
                                    = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__41__event_ref)) 
                                       | (0xffU != 
                                          (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__41__event_ref))));
                            }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__41__Vfuncout))) 
                   & ([&]() {
                            vlSelfRef.__Vfunc_npu_event_ref_valid__42__event_ref 
                                = (0xfffU & vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U]);
                            vlSelfRef.__Vfunc_npu_event_ref_valid__42__Vfuncout 
                                = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__42__event_ref)) 
                                   | (0xffU != (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__42__event_ref))));
                        }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__42__Vfuncout))) 
                  & ([&]() {
                        vlSelfRef.__Vfunc_npu_event_ref_valid__43__event_ref 
                            = (0xfffU & (vlSelfRef.tb_inline_scheduler_smoke__DOT__cfe_cmd[3U] 
                                         >> 0xcU));
                        vlSelfRef.__Vfunc_npu_event_ref_valid__43__Vfuncout 
                            = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__43__event_ref)) 
                               | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__43__event_ref))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__43__Vfuncout)))));
}
