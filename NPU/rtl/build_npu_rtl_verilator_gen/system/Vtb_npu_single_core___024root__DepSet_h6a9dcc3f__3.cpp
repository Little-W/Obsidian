// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core___024root.h"

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__12(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__12\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [5U] == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_comb = 1U;
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [6U] == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_comb = 1U;
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [7U] == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_comb = 1U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [0U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [0U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [0U]));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 0U;
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [1U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [1U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [1U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [0U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 0U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [2U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [2U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [2U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [1U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 1U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [3U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [3U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [3U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [2U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 2U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [4U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [4U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [4U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [3U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 3U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [5U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [5U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [5U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [4U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 4U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [6U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [6U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [6U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [5U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 5U;
    }
    (void)((([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [7U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1703__Vfuncout)) 
            & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
               [7U])) & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                         [7U]));
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [6U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 6U;
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [7U] == (0xfffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_query_select = 7U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__completion_status 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
        [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select];
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_status_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_failure_seq_q;
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
          & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
             [0U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                       [0U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                       [0U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [0U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [0U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [0U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 1U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [1U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [1U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [1U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [1U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [1U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [1U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 2U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [2U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [2U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [2U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [2U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [2U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [2U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 3U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [3U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [3U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [3U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [3U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [3U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [3U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 4U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [4U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [4U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [4U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [4U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [4U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [4U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 5U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [5U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [5U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [5U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [5U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [5U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [5U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 6U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [6U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [6U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [6U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [6U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [6U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [6U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    if (((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_q) 
           >> 7U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                     [7U])) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                               [7U] == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_target_seq_q
                               [7U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [7U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1688__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [7U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_result_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [7U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_pending = 1U;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq = 0xffffffffffffffffULL;
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [0U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [0U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [0U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [0U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [0U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (1U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [1U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [1U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [1U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [1U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [1U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (2U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [2U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [2U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [2U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [2U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [2U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (4U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [3U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [3U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [3U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [3U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [3U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (8U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [4U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [4U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [4U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [4U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [4U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (0x10U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [5U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [5U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [5U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [5U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [5U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (0x20U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [6U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [6U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [6U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [6U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [6U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (0x40U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [7U]) & ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask 
                        = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ctl_arg0_q));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                        [7U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout 
                        = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                     >> 3U))) && (1U 
                                                  & ((4U 
                                                      & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                      ? 
                                                     ((1U 
                                                       & (~ 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine) 
                                                           >> 1U))) 
                                                      && ((1U 
                                                           & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))) 
                                                          && (1U 
                                                              & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                                 >> 3U))))
                                                      : 
                                                     ((2U 
                                                       & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                       ? 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine))
                                                        ? 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 2U)
                                                        : 
                                                       ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask) 
                                                        >> 1U))
                                                       : 
                                                      ((1U 
                                                        & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine)) 
                                                       && (1U 
                                                           & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__engine_mask)))))));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__engine_mask_selected__1686__Vfuncout)))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                        [7U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout 
                        = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)) 
                           | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__state)));
                }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1687__Vfuncout))) {
            if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                  [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                           [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_status 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                    [7U];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_failure_seq 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [7U];
            }
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target 
                = (0x80U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__ctl_fence_accept_target));
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[0U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel0;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel0;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel0: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel1;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel1: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[0U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel2;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel2;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                                      : 0U)));
                    __Vlabel2: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [0U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel3;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                                      : 0U)));
                    __Vlabel3: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 0U;
    if ((1U & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                [0U] >> 4U) | (4U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                               [0U])))) {
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[0U] = 1U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[1U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel4;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel4;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel4: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel5;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel5;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel5: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[1U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel6;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel6;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                                      : 0U)));
                    __Vlabel6: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [1U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel7;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel7;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                                      : 0U)));
                    __Vlabel7: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 0U;
    if ((1U & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                [1U] >> 4U) | (4U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                               [1U])))) {
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[1U] = 1U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[2U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel8;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel8;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel8: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel9;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel9;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel9: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[2U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel10;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel10;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                                      : 0U)));
                    __Vlabel10: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [2U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel11;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel11;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                                      : 0U)));
                    __Vlabel11: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 0U;
    if ((1U & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                [2U] >> 4U) | (4U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                               [2U])))) {
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[2U] = 1U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[3U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel12;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel12;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel12: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel13;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel13;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel13: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[3U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel14;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel14;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                                      : 0U)));
                    __Vlabel14: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [3U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel15;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel15;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                                      : 0U)));
                    __Vlabel15: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 0U;
    if ((1U & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                [3U] >> 4U) | (4U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                               [3U])))) {
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
        }
    }
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__13(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__13\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
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
    // Body
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[3U] = 1U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[4U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [4U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel0;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel0;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel0: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [4U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel1;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel1: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[4U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [4U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel2;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel2;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                                      : 0U)));
                    __Vlabel2: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [4U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel3;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                                      : 0U)));
                    __Vlabel3: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 0U;
    if ((1U & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                [4U] >> 4U) | (4U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                               [4U])))) {
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[4U] = 1U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[5U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [5U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel4;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel4;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel4: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [5U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel5;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel5;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel5: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[5U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [5U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel6;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel6;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                                      : 0U)));
                    __Vlabel6: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [5U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel7;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel7;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                                      : 0U)));
                    __Vlabel7: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 0U;
    if ((1U & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                [5U] >> 4U) | (4U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                               [5U])))) {
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[5U] = 1U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[6U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [6U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel8;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel8;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel8: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [6U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel9;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel9;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel9: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[6U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [6U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel10;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel10;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                                      : 0U)));
                    __Vlabel10: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [6U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel11;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel11;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                                      : 0U)));
                    __Vlabel11: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 0U;
    if ((1U & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                [6U] >> 4U) | (4U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                               [6U])))) {
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[6U] = 1U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_success[7U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [7U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 1U;
                        goto __Vlabel12;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel12;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref))]
                                      : 0U)));
                    __Vlabel12: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [7U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel13;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel13;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref) 
                                                >> 8U))) 
                           & (2U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))]
                                      : 0U)));
                    __Vlabel13: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[7U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [7U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel14;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel14;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))]
                                      : 0U)));
                    __Vlabel14: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [7U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel15;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel15;
                    }
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout 
                        = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                              ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                             [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                              : 0U) == (0xfU & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref) 
                                                >> 8U))) 
                           & (3U == ((0xfeU >= (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))
                                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                     [(0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))]
                                      : 0U)));
                    __Vlabel15: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 0U;
    if ((1U & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                [7U] >> 4U) | (4U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                               [7U])))) {
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [0U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [1U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [2U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [3U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [4U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [5U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [6U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
        }
        if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
               [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                        [7U])) & (~ ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                [7U];
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout 
                                = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)) 
                                   | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__state)));
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1701__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
        }
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [0U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [0U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [1U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [1U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [2U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [2U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [3U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [3U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [4U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [4U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [5U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [5U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [5U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [6U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [6U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [6U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
    }
    if (((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
            [7U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                     [7U] >> 4U)) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                     [7U])) & (~ ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                            [7U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout 
                            = ((5U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)) 
                               | (6U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__state)));
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1702__Vfuncout))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked[7U] = 1U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_rsp_ready 
        = (((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
            & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q))) 
           | ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
              & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__fifo_status_w 
        = (QData)((IData)(((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error) 
                             << 0x13U) | ((8U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q)) 
                                          << 0x12U)) 
                           | (((0x10U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q)) 
                               << 0x11U) | ((((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
                                              & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_index_q)) 
                                             << 0x10U) 
                                            | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q) 
                                                << 8U) 
                                               | (0xffU 
                                                  & ((IData)(0x10U) 
                                                     - (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q)))))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_valid 
        = (((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
            & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_sent_q)) 
               & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q)))) 
           | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_req_sent_q)) 
                 & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q)))));
    vlSelfRef.tb_npu_single_core__DOT__s_axi_wready_o 
        = ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
           | ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
              | (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))));
    if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr 
            = (0xfff8U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_addr_q);
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_space 
            = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_addr_q 
                     >> 0x10U));
    } else {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr 
            = (0xfff8U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q);
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_space 
            = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q 
                     >> 0x10U));
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__fe_l1_rsp_ready 
        = (((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
            & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q))) 
           | ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
              & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__fe_l1_req_valid 
        = (((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
            & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_sent_q)) 
               & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_target_q)))) 
           | ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_req_sent_q)) 
                 & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_target_q)))));
    vlSelfRef.__VdfgRegularize_h081c6435_0_0 = ((0U 
                                                 != 
                                                 (7U 
                                                  & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q))) 
                                                | (0x3ff8ULL 
                                                   < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_req_ready 
        = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_rsp_valid 
        = (7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__tbu_req_valid 
        = (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__tbu_rsp_ready 
        = (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_bready_o 
        = (6U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_arvalid_o 
        = (3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_rready_o 
        = (4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__tbu_req_ready 
        = (1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_valid_q)) 
                 | (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__mem_response_handshake 
        = (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__busy_q) 
            & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__owner_dma_q)) 
               & (7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)))) 
           & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q)));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_awvalid_o 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_done_q)) 
           & (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_wvalid_o 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_done_q)) 
           & (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_rsp_valid 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__busy_q) 
           & ((7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)) 
              & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__owner_dma_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_rsp_ready 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__busy_q) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__owner_dma_q)
               ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_rsp_ready)
               : (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_dma_w 
        = (1U & (((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q)) 
                  & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_valid))
                  ? (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__last_grant_dma_q))
                  : (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_valid)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_valid_w 
        = ((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q)) 
           | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_valid));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_write 
        = ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_write) 
             << 4U) | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_write) 
                        << 3U) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_write) 
                                  << 2U))) | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_write) 
                                               << 1U) 
                                              | (3U 
                                                 == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))));
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_wstrb 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_wstrb)) 
            << 0x20U) | (QData)((IData)(((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_wstrb) 
                                           << 0x18U) 
                                          | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_wstrb) 
                                             << 0x10U)) 
                                         | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_wstrb) 
                                             << 8U) 
                                            | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q))))));
    __Vfunc_fp32_add__2372__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
    __Vfunc_fp32_add__2372__lhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_q;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
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
            goto __Vlabel16;
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
                goto __Vlabel16;
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
            goto __Vlabel16;
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
            goto __Vlabel16;
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
            goto __Vlabel16;
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
                goto __Vlabel16;
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
            goto __Vlabel16;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__2372__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__2372__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__2372__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2372__mantissa));
            goto __Vlabel16;
        }
        vlSelfRef.__Vfunc_fp32_add__2372__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_add__2372__result_sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__2372__large_exp) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2372__mantissa)));
        __Vlabel16: ;
    }
}
