// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core___024root.h"

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__16(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__16\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_fp32_add__2393__lhs;
    __Vfunc_fp32_add__2393__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2393__rhs;
    __Vfunc_fp32_add__2393__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2393__normalize_count;
    __Vfunc_fp32_add__2393__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2394__unused_sign;
    __Vfunc_fp32_is_nan__2394__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2395__unused_sign;
    __Vfunc_fp32_is_nan__2395__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2396__unused_sign;
    __Vfunc_fp32_is_inf__2396__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2397__unused_sign;
    __Vfunc_fp32_is_inf__2397__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2398__unused_sign;
    __Vfunc_fp32_is_inf__2398__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2399__unused_sign;
    __Vfunc_fp32_is_inf__2399__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2400__unused_sign;
    __Vfunc_fp32_is_inf__2400__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2401__unused_sign;
    __Vfunc_fp32_is_zero__2401__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2402__unused_sign;
    __Vfunc_fp32_is_zero__2402__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2470__lhs;
    __Vfunc_fp32_mul__2470__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2470__rhs;
    __Vfunc_fp32_mul__2470__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2470__normalize_count;
    __Vfunc_fp32_mul__2470__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2471__unused_sign;
    __Vfunc_fp32_is_nan__2471__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2472__unused_sign;
    __Vfunc_fp32_is_nan__2472__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2473__unused_sign;
    __Vfunc_fp32_is_inf__2473__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2474__unused_sign;
    __Vfunc_fp32_is_zero__2474__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2475__unused_sign;
    __Vfunc_fp32_is_inf__2475__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2476__unused_sign;
    __Vfunc_fp32_is_zero__2476__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2477__unused_sign;
    __Vfunc_fp32_is_inf__2477__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2478__unused_sign;
    __Vfunc_fp32_is_inf__2478__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2479__unused_sign;
    __Vfunc_fp32_is_zero__2479__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2480__unused_sign;
    __Vfunc_fp32_is_zero__2480__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2512__lhs;
    __Vfunc_fp32_add__2512__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2512__rhs;
    __Vfunc_fp32_add__2512__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2512__normalize_count;
    __Vfunc_fp32_add__2512__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2513__unused_sign;
    __Vfunc_fp32_is_nan__2513__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2514__unused_sign;
    __Vfunc_fp32_is_nan__2514__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2515__unused_sign;
    __Vfunc_fp32_is_inf__2515__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2516__unused_sign;
    __Vfunc_fp32_is_inf__2516__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2517__unused_sign;
    __Vfunc_fp32_is_inf__2517__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2518__unused_sign;
    __Vfunc_fp32_is_inf__2518__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2519__unused_sign;
    __Vfunc_fp32_is_inf__2519__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2520__unused_sign;
    __Vfunc_fp32_is_zero__2520__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2521__unused_sign;
    __Vfunc_fp32_is_zero__2521__unused_sign = 0;
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select = 0U;
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [0U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [0U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [0U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [0U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select = 0U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [1U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [1U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [1U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [2U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [2U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [2U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select = 2U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [3U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [3U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [3U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [3U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [3U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [3U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select = 3U;
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select = 0U;
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [0U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((4U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                 [0U])) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [0U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [0U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select = 0U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((4U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                 [1U])) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [1U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [1U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((4U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                 [2U])) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [2U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [2U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select = 2U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [3U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [3U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [3U] >> 3U)))) {
            if ((4U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                 [3U])) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [3U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [3U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select = 3U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [4U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [4U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [4U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [4U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [4U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [4U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select = 4U;
                        }
                    }
                }
            }
            if ((4U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                 [4U])) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [4U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [4U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select = 4U;
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select = 0U;
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [0U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [0U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [0U])) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [0U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select = 0U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [1U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [1U])) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [1U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [2U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [2U])) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [2U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select = 2U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [3U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [3U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [3U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [3U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [3U])) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [3U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select = 3U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [4U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [4U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [4U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [4U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [4U])) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [4U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select = 4U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [5U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [5U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [5U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [5U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [5U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [5U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select = 5U;
                        }
                    }
                }
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [5U])) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [5U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select = 5U;
                        }
                    }
                }
            }
            if ((4U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                 [5U])) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [5U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [5U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select = 5U;
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select = 0U;
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [0U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [0U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [0U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [0U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select = 0U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [1U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [1U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [1U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [2U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [2U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [2U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select = 2U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [3U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [3U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [3U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [3U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [3U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [3U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select = 3U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [4U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [4U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [4U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [4U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [4U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [4U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select = 4U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [5U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [5U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [5U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [5U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [5U] >> 1U)))) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [5U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select = 5U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [6U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [6U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [6U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [6U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [6U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [6U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select = 6U;
                        }
                    }
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [6U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select = 6U;
                        }
                    }
                }
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [6U])) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [6U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select = 6U;
                        }
                    }
                }
            }
            if ((4U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                 [6U])) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [6U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [6U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select = 6U;
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select = 0U;
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [0U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [0U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [0U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [0U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [0U])) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [0U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [0U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select = 0U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [1U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [1U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [1U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [1U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [1U])) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [1U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select = 1U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [2U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [2U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [2U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [2U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [2U])) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [2U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select = 2U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [3U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [3U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [3U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [3U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [3U])) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [3U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select = 3U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [4U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [4U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [4U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [4U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [4U])) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [4U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select = 4U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [5U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [5U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [5U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [5U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [5U])) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [5U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select = 5U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [6U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [6U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [6U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [6U] >> 2U)))) {
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [6U])) {
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [6U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select = 6U;
                        }
                    }
                }
            }
        }
    }
    if (((3U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [7U]) & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__order_blocked
                   [7U]))) {
        if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                      [7U] >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                          [7U] >> 2U)))) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [7U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [7U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__control_select = 7U;
                        }
                    }
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [7U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select = 7U;
                        }
                    }
                }
                if ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                     [7U])) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [7U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select = 7U;
                        }
                    }
                    if ((1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                         [7U])) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select = 7U;
                        }
                    }
                }
            }
            if ((4U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                 [7U])) {
                if ((1U & (~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                              [7U] >> 1U)))) {
                    if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                               [7U]))) {
                        if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found)) 
                                   | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select])))) {
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found = 1U;
                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select = 7U;
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready 
        = ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready) 
             << 4U) | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready) 
                        << 3U) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready) 
                                  << 2U))) | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_rsp_ready) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__fe_l1_rsp_ready)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid 
        = ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid) 
             << 4U) | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid) 
                        << 3U) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid) 
                                  << 2U))) | (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_valid) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__fe_l1_req_valid)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_valid 
        = (1U & ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                                  >> 8U))) ? ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                                              >> 1U)
                  : (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_rsp_valid)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__write_rsp_valid 
        = (1U & ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                                  >> 0x10U))) ? ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                                                 >> 1U)
                  : (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_rsp_valid)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_req_addr 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_dma_w)
            ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_addr
            : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__df_mem_req_addr);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__mif_arb_req_valid 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__busy_q)) 
           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_valid_w));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT____VdfgRegularize_hd916d9cf_0_1 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_valid_w) 
           & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_idle) 
           & (((1U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
               & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q)) 
                  & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q)))) 
              & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__scheduler_idle) 
                 & (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)) 
                     & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)) 
                        & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)) 
                           & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))))) 
                    & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q)) 
                       & (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)) 
                           & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__state_q)) 
                              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__busy_q)) 
                                 & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_mif_arbiter__DOT__select_valid_w))))) 
                          & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)) 
                             & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
                                & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)) 
                                   & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)))))))))));
    __Vfunc_fp32_add__2393__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_x_squared;
    __Vfunc_fp32_add__2393__lhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sumsq_q;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_add__2393__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13511068793769181466ull);
    vlSelf->__Vfunc_fp32_add__2393__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8703418614326423128ull);
    vlSelf->__Vfunc_fp32_add__2393__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2839226888153824215ull);
    vlSelf->__Vfunc_fp32_add__2393__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13671187335804499830ull);
    vlSelf->__Vfunc_fp32_add__2393__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9737193786113661560ull);
    vlSelf->__Vfunc_fp32_add__2393__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 17977057278363573878ull);
    vlSelf->__Vfunc_fp32_add__2393__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 5044652445533203958ull);
    vlSelf->__Vfunc_fp32_add__2393__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12172768653773806148ull);
    vlSelf->__Vfunc_fp32_add__2393__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17816769602141212074ull);
    vlSelf->__Vfunc_fp32_add__2393__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 1221688903025608950ull);
    vlSelf->__Vfunc_fp32_add__2393__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13978940616842518636ull);
    vlSelf->__Vfunc_fp32_add__2393__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2595674021957848534ull);
    vlSelf->__Vfunc_fp32_add__2393__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1051831306247405848ull);
    vlSelf->__Vfunc_fp32_add__2393__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 693480662138922007ull);
    vlSelf->__Vfunc_fp32_add__2393__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 9165205090468675300ull);
    vlSelf->__Vfunc_fp32_add__2393__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 4587261836977627989ull);
    vlSelf->__Vfunc_fp32_add__2393__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 3956519170651766730ull);
    vlSelf->__Vfunc_fp32_add__2393__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 5723596368594752444ull);
    vlSelf->__Vfunc_fp32_add__2393__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 13584824050446303320ull);
    vlSelf->__Vfunc_fp32_add__2393__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 15072940317497113544ull);
    vlSelf->__Vfunc_fp32_add__2393__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 3223260064991186528ull);
    vlSelf->__Vfunc_fp32_add__2393__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13895995088137555896ull);
    vlSelf->__Vfunc_fp32_add__2393__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6894339614240616002ull);
    vlSelf->__Vfunc_fp32_add__2393__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13905251343521667555ull);
    __Vfunc_fp32_add__2393__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2394__bits 
                            = __Vfunc_fp32_add__2393__lhs;
                        __Vfunc_fp32_is_nan__2394__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2394__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2394__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2394__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2394__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2394__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2394__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2395__bits 
                            = __Vfunc_fp32_add__2393__rhs;
                        __Vfunc_fp32_is_nan__2395__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2395__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2395__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2395__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2395__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2395__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2395__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__2393__Vfuncout = 0x7fc00000U;
            goto __Vlabel0;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2396__bits 
                            = __Vfunc_fp32_add__2393__lhs;
                        __Vfunc_fp32_is_inf__2396__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2396__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2396__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2396__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2396__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2396__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2397__bits 
                            = __Vfunc_fp32_add__2393__rhs;
                        __Vfunc_fp32_is_inf__2397__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2397__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2397__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2397__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2397__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2397__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2398__bits 
                                    = __Vfunc_fp32_add__2393__lhs;
                                __Vfunc_fp32_is_inf__2398__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2398__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2398__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2398__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2398__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2398__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2399__bits 
                                    = __Vfunc_fp32_add__2393__rhs;
                                __Vfunc_fp32_is_inf__2399__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2399__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2399__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2399__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2399__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2399__Vfuncout))) 
                 & ((__Vfunc_fp32_add__2393__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__2393__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__Vfuncout = 0x7fc00000U;
                goto __Vlabel0;
            }
            vlSelfRef.__Vfunc_fp32_add__2393__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2400__bits 
                            = __Vfunc_fp32_add__2393__lhs;
                        __Vfunc_fp32_is_inf__2400__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2400__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2400__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2400__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2400__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2400__Vfuncout))
                    ? __Vfunc_fp32_add__2393__lhs : __Vfunc_fp32_add__2393__rhs);
            goto __Vlabel0;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2401__bits 
                        = __Vfunc_fp32_add__2393__lhs;
                    __Vfunc_fp32_is_zero__2401__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2401__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2401__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2401__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2401__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2401__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2393__Vfuncout 
                = __Vfunc_fp32_add__2393__rhs;
            goto __Vlabel0;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2402__bits 
                        = __Vfunc_fp32_add__2393__rhs;
                    __Vfunc_fp32_is_zero__2402__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2402__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2402__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2402__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2402__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2402__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2393__Vfuncout 
                = __Vfunc_fp32_add__2393__lhs;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_add__2393__lhs_sign 
            = (__Vfunc_fp32_add__2393__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2393__rhs_sign 
            = (__Vfunc_fp32_add__2393__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2393__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2393__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2393__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2393__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2393__lhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2393__lhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2393__lhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2393__lhs)));
        vlSelfRef.__Vfunc_fp32_add__2393__rhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2393__rhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2393__rhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2393__rhs)));
        vlSelfRef.__Vfunc_fp32_add__2393__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2393__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2393__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2393__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2393__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__2393__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__2393__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__2393__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__2393__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__2393__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2393__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2393__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2393__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2393__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2393__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2393__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2393__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2393__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2393__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2393__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2393__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2393__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2393__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2393__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2393__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2393__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2393__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2393__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2393__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2393__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2393__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2393__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2393__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2393__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2393__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2393__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__2393__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2393__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2393__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2393__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2393__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__2393__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__2393__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__2393__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2393__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__2393__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__small_ext, vlSelfRef.__Vfunc_fp32_add__2393__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__2393__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2393__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__2393__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__2393__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__2393__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__2393__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__2393__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2393__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__2393__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__2393__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__2393__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__2393__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__2393__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2393__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__2393__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__2393__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2393__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__2393__work_ext);
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2393__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__2393__sticky))));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2393__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__2393__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__2393__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2393__Vfuncout = 0U;
                goto __Vlabel0;
            }
            __Vfunc_fp32_add__2393__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2393__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__2393__normalize_count = 1U;
            __Vfunc_fp32_add__2393__normalize_count = 2U;
            __Vfunc_fp32_add__2393__normalize_count = 3U;
            __Vfunc_fp32_add__2393__normalize_count = 4U;
            __Vfunc_fp32_add__2393__normalize_count = 5U;
            __Vfunc_fp32_add__2393__normalize_count = 6U;
            __Vfunc_fp32_add__2393__normalize_count = 7U;
            __Vfunc_fp32_add__2393__normalize_count = 8U;
            __Vfunc_fp32_add__2393__normalize_count = 9U;
            __Vfunc_fp32_add__2393__normalize_count = 0xaU;
            __Vfunc_fp32_add__2393__normalize_count = 0xbU;
            __Vfunc_fp32_add__2393__normalize_count = 0xcU;
            __Vfunc_fp32_add__2393__normalize_count = 0xdU;
            __Vfunc_fp32_add__2393__normalize_count = 0xeU;
            __Vfunc_fp32_add__2393__normalize_count = 0xfU;
            __Vfunc_fp32_add__2393__normalize_count = 0x10U;
            __Vfunc_fp32_add__2393__normalize_count = 0x11U;
            __Vfunc_fp32_add__2393__normalize_count = 0x12U;
            __Vfunc_fp32_add__2393__normalize_count = 0x13U;
            __Vfunc_fp32_add__2393__normalize_count = 0x14U;
            __Vfunc_fp32_add__2393__normalize_count = 0x15U;
            __Vfunc_fp32_add__2393__normalize_count = 0x16U;
            __Vfunc_fp32_add__2393__normalize_count = 0x17U;
            __Vfunc_fp32_add__2393__normalize_count = 0x18U;
            __Vfunc_fp32_add__2393__normalize_count = 0x19U;
            __Vfunc_fp32_add__2393__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__2393__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_add__2393__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__2393__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__2393__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__2393__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__2393__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__2393__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__2393__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__2393__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__2393__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2393__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__2393__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__2393__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__2393__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__2393__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__2393__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__2393__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__2393__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2393__mantissa));
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_add__2393__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_add__2393__result_sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__2393__large_exp) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2393__mantissa)));
        __Vlabel0: ;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sumsq_plus_x_squared 
        = vlSelfRef.__Vfunc_fp32_add__2393__Vfuncout;
    __Vfunc_fp32_mul__2470__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_invstd_q;
    __Vfunc_fp32_mul__2470__lhs = ((5U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x13U])
                                    ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_centered_x
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp);
    vlSelf->__Vfunc_fp32_mul__2470__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2965796590201008008ull);
    vlSelf->__Vfunc_fp32_mul__2470__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 3426630680880455260ull);
    vlSelf->__Vfunc_fp32_mul__2470__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14713475556480381276ull);
    vlSelf->__Vfunc_fp32_mul__2470__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 14450468501194777774ull);
    vlSelf->__Vfunc_fp32_mul__2470__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 17329587818579782221ull);
    vlSelf->__Vfunc_fp32_mul__2470__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 5602818250957305256ull);
    vlSelf->__Vfunc_fp32_mul__2470__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13469686036937236487ull);
    vlSelf->__Vfunc_fp32_mul__2470__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 16241276013282887490ull);
    vlSelf->__Vfunc_fp32_mul__2470__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11483879732438751093ull);
    vlSelf->__Vfunc_fp32_mul__2470__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18085111534408198925ull);
    vlSelf->__Vfunc_fp32_mul__2470__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9852933871089701193ull);
    vlSelf->__Vfunc_fp32_mul__2470__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12518747304152752543ull);
    vlSelf->__Vfunc_fp32_mul__2470__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 395268906108395017ull);
    __Vfunc_fp32_mul__2470__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2471__bits 
                                = __Vfunc_fp32_mul__2470__lhs;
                            __Vfunc_fp32_is_nan__2471__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2471__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2471__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2471__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2471__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2471__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2471__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2472__bits 
                                = __Vfunc_fp32_mul__2470__rhs;
                            __Vfunc_fp32_is_nan__2472__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2472__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2472__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2472__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2472__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2472__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2472__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2473__bits 
                                    = __Vfunc_fp32_mul__2470__lhs;
                                __Vfunc_fp32_is_inf__2473__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2473__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2473__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2473__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2473__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2473__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2474__bits 
                                    = __Vfunc_fp32_mul__2470__rhs;
                                __Vfunc_fp32_is_zero__2474__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2474__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2474__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2474__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2474__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2474__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2475__bits 
                                    = __Vfunc_fp32_mul__2470__rhs;
                                __Vfunc_fp32_is_inf__2475__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2475__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2475__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2475__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2475__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2475__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2476__bits 
                                    = __Vfunc_fp32_mul__2470__lhs;
                                __Vfunc_fp32_is_zero__2476__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2476__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2476__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2476__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2476__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2476__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__Vfuncout = 0x7fc00000U;
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_mul__2470__result_sign 
            = ((__Vfunc_fp32_mul__2470__lhs ^ __Vfunc_fp32_mul__2470__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2477__bits 
                            = __Vfunc_fp32_mul__2470__lhs;
                        __Vfunc_fp32_is_inf__2477__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2477__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2477__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2477__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2477__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2477__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2478__bits 
                            = __Vfunc_fp32_mul__2470__rhs;
                        __Vfunc_fp32_is_inf__2478__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2478__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2478__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2478__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2478__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2478__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2470__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2479__bits 
                            = __Vfunc_fp32_mul__2470__lhs;
                        __Vfunc_fp32_is_zero__2479__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2479__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2479__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2479__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2479__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2479__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2480__bits 
                            = __Vfunc_fp32_mul__2470__rhs;
                        __Vfunc_fp32_is_zero__2480__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2480__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2480__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2480__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2480__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2480__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2470__result_sign) 
                   << 0x1fU);
            goto __Vlabel1;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2470__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2470__lhs);
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2470__lhs));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2470__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2470__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2470__rhs);
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2470__rhs));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2470__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__2470__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__2470__normalize_count = 1U;
        __Vfunc_fp32_mul__2470__normalize_count = 2U;
        __Vfunc_fp32_mul__2470__normalize_count = 3U;
        __Vfunc_fp32_mul__2470__normalize_count = 4U;
        __Vfunc_fp32_mul__2470__normalize_count = 5U;
        __Vfunc_fp32_mul__2470__normalize_count = 6U;
        __Vfunc_fp32_mul__2470__normalize_count = 7U;
        __Vfunc_fp32_mul__2470__normalize_count = 8U;
        __Vfunc_fp32_mul__2470__normalize_count = 9U;
        __Vfunc_fp32_mul__2470__normalize_count = 0xaU;
        __Vfunc_fp32_mul__2470__normalize_count = 0xbU;
        __Vfunc_fp32_mul__2470__normalize_count = 0xcU;
        __Vfunc_fp32_mul__2470__normalize_count = 0xdU;
        __Vfunc_fp32_mul__2470__normalize_count = 0xeU;
        __Vfunc_fp32_mul__2470__normalize_count = 0xfU;
        __Vfunc_fp32_mul__2470__normalize_count = 0x10U;
        __Vfunc_fp32_mul__2470__normalize_count = 0x11U;
        __Vfunc_fp32_mul__2470__normalize_count = 0x12U;
        __Vfunc_fp32_mul__2470__normalize_count = 0x13U;
        __Vfunc_fp32_mul__2470__normalize_count = 0x14U;
        __Vfunc_fp32_mul__2470__normalize_count = 0x15U;
        __Vfunc_fp32_mul__2470__normalize_count = 0x16U;
        __Vfunc_fp32_mul__2470__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__2470__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2470__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2470__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__2470__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__2470__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__2470__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__2470__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__2470__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2470__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2470__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__2470__mantissa 
            = (0xffffffU & (IData)((0xffffffffffffULL 
                                    & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__2470__product, vlSelfRef.__Vfunc_fp32_mul__2470__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__2470__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__2470__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__2470__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__2470__product 
               & vlSelfRef.__Vfunc_fp32_mul__2470__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__2470__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__2470__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__2470__rounded = vlSelfRef.__Vfunc_fp32_mul__2470__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__2470__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__2470__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__2470__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__2470__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__2470__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__2470__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2470__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__2470__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__2470__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__2470__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__2470__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2470__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2470__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__2470__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__2470__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2470__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2470__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__2470__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2470__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2470__result_sign) 
                   << 0x1fU);
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_mul__2470__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_mul__2470__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_mul__2470__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__2470__mantissa)));
        __Vlabel1: ;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_norm_base 
        = vlSelfRef.__Vfunc_fp32_mul__2470__Vfuncout;
    __Vfunc_fp32_add__2512__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_result;
    __Vfunc_fp32_add__2512__lhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_q;
    vlSelf->__Vfunc_fp32_add__2512__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 570365528280263984ull);
    vlSelf->__Vfunc_fp32_add__2512__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6625218695556682131ull);
    vlSelf->__Vfunc_fp32_add__2512__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 802955563722454289ull);
    vlSelf->__Vfunc_fp32_add__2512__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14168095246284095050ull);
    vlSelf->__Vfunc_fp32_add__2512__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11486050448478985660ull);
    vlSelf->__Vfunc_fp32_add__2512__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 3576415333423773716ull);
    vlSelf->__Vfunc_fp32_add__2512__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4122160593811298679ull);
    vlSelf->__Vfunc_fp32_add__2512__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2177752465058554047ull);
    vlSelf->__Vfunc_fp32_add__2512__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18085618404035296514ull);
    vlSelf->__Vfunc_fp32_add__2512__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11218919694835684818ull);
    vlSelf->__Vfunc_fp32_add__2512__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 3468325705693023313ull);
    vlSelf->__Vfunc_fp32_add__2512__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3414431070084290992ull);
    vlSelf->__Vfunc_fp32_add__2512__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8766682385722296690ull);
    vlSelf->__Vfunc_fp32_add__2512__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9088979654912209146ull);
    vlSelf->__Vfunc_fp32_add__2512__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 9564372999297108514ull);
    vlSelf->__Vfunc_fp32_add__2512__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 8144127104114470992ull);
    vlSelf->__Vfunc_fp32_add__2512__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 11053442688997695533ull);
    vlSelf->__Vfunc_fp32_add__2512__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 15792019995256565759ull);
    vlSelf->__Vfunc_fp32_add__2512__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 6673169208675344442ull);
    vlSelf->__Vfunc_fp32_add__2512__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6941973096379022063ull);
    vlSelf->__Vfunc_fp32_add__2512__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16293326457824420504ull);
    vlSelf->__Vfunc_fp32_add__2512__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10333937226928829130ull);
    vlSelf->__Vfunc_fp32_add__2512__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15653724052469905723ull);
    vlSelf->__Vfunc_fp32_add__2512__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1428109225781687327ull);
    __Vfunc_fp32_add__2512__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2513__bits 
                            = __Vfunc_fp32_add__2512__lhs;
                        __Vfunc_fp32_is_nan__2513__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2513__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2513__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2513__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2513__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2513__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2513__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2514__bits 
                            = __Vfunc_fp32_add__2512__rhs;
                        __Vfunc_fp32_is_nan__2514__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2514__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2514__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2514__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2514__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2514__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2514__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__2512__Vfuncout = 0x7fc00000U;
            goto __Vlabel2;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2515__bits 
                            = __Vfunc_fp32_add__2512__lhs;
                        __Vfunc_fp32_is_inf__2515__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2515__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2515__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2515__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2515__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2515__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2516__bits 
                            = __Vfunc_fp32_add__2512__rhs;
                        __Vfunc_fp32_is_inf__2516__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2516__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2516__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2516__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2516__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2516__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2517__bits 
                                    = __Vfunc_fp32_add__2512__lhs;
                                __Vfunc_fp32_is_inf__2517__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2517__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2517__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2517__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2517__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2517__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2518__bits 
                                    = __Vfunc_fp32_add__2512__rhs;
                                __Vfunc_fp32_is_inf__2518__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2518__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2518__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2518__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2518__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2518__Vfuncout))) 
                 & ((__Vfunc_fp32_add__2512__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__2512__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__Vfuncout = 0x7fc00000U;
                goto __Vlabel2;
            }
            vlSelfRef.__Vfunc_fp32_add__2512__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2519__bits 
                            = __Vfunc_fp32_add__2512__lhs;
                        __Vfunc_fp32_is_inf__2519__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2519__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2519__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2519__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2519__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2519__Vfuncout))
                    ? __Vfunc_fp32_add__2512__lhs : __Vfunc_fp32_add__2512__rhs);
            goto __Vlabel2;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2520__bits 
                        = __Vfunc_fp32_add__2512__lhs;
                    __Vfunc_fp32_is_zero__2520__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2520__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2520__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2520__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2520__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2520__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2512__Vfuncout 
                = __Vfunc_fp32_add__2512__rhs;
            goto __Vlabel2;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2521__bits 
                        = __Vfunc_fp32_add__2512__rhs;
                    __Vfunc_fp32_is_zero__2521__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2521__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2521__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2521__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2521__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2521__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2512__Vfuncout 
                = __Vfunc_fp32_add__2512__lhs;
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_add__2512__lhs_sign 
            = (__Vfunc_fp32_add__2512__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2512__rhs_sign 
            = (__Vfunc_fp32_add__2512__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2512__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2512__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2512__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2512__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2512__lhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2512__lhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2512__lhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2512__lhs)));
        vlSelfRef.__Vfunc_fp32_add__2512__rhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2512__rhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2512__rhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2512__rhs)));
        vlSelfRef.__Vfunc_fp32_add__2512__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2512__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2512__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2512__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2512__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__2512__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__2512__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__2512__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__2512__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__2512__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2512__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2512__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2512__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2512__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2512__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2512__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2512__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2512__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2512__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2512__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2512__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2512__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2512__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2512__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2512__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2512__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2512__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2512__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2512__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2512__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2512__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2512__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2512__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2512__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2512__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2512__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__2512__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2512__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2512__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2512__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2512__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__2512__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__2512__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__2512__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2512__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__2512__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__small_ext, vlSelfRef.__Vfunc_fp32_add__2512__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__2512__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2512__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__2512__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__2512__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__2512__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__2512__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__2512__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2512__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__2512__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__2512__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__2512__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__2512__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__2512__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2512__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__2512__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__2512__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2512__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__2512__work_ext);
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2512__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__2512__sticky))));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2512__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__2512__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__2512__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2512__Vfuncout = 0U;
                goto __Vlabel2;
            }
            __Vfunc_fp32_add__2512__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2512__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__2512__normalize_count = 1U;
            __Vfunc_fp32_add__2512__normalize_count = 2U;
            __Vfunc_fp32_add__2512__normalize_count = 3U;
            __Vfunc_fp32_add__2512__normalize_count = 4U;
            __Vfunc_fp32_add__2512__normalize_count = 5U;
            __Vfunc_fp32_add__2512__normalize_count = 6U;
            __Vfunc_fp32_add__2512__normalize_count = 7U;
            __Vfunc_fp32_add__2512__normalize_count = 8U;
            __Vfunc_fp32_add__2512__normalize_count = 9U;
            __Vfunc_fp32_add__2512__normalize_count = 0xaU;
            __Vfunc_fp32_add__2512__normalize_count = 0xbU;
            __Vfunc_fp32_add__2512__normalize_count = 0xcU;
            __Vfunc_fp32_add__2512__normalize_count = 0xdU;
            __Vfunc_fp32_add__2512__normalize_count = 0xeU;
            __Vfunc_fp32_add__2512__normalize_count = 0xfU;
            __Vfunc_fp32_add__2512__normalize_count = 0x10U;
            __Vfunc_fp32_add__2512__normalize_count = 0x11U;
            __Vfunc_fp32_add__2512__normalize_count = 0x12U;
            __Vfunc_fp32_add__2512__normalize_count = 0x13U;
            __Vfunc_fp32_add__2512__normalize_count = 0x14U;
            __Vfunc_fp32_add__2512__normalize_count = 0x15U;
            __Vfunc_fp32_add__2512__normalize_count = 0x16U;
            __Vfunc_fp32_add__2512__normalize_count = 0x17U;
            __Vfunc_fp32_add__2512__normalize_count = 0x18U;
            __Vfunc_fp32_add__2512__normalize_count = 0x19U;
            __Vfunc_fp32_add__2512__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__2512__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_add__2512__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__2512__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__2512__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__2512__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__2512__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__2512__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__2512__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__2512__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__2512__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2512__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__2512__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__2512__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__2512__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__2512__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__result_sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__2512__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__2512__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__2512__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2512__mantissa));
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_add__2512__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_add__2512__result_sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__2512__large_exp) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2512__mantissa)));
        __Vlabel2: ;
    }
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__17(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__17\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_norm_scaled;
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_norm_scaled = 0;
    IData/*31:0*/ tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_norm_output;
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_norm_output = 0;
    IData/*31:0*/ tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_softmax_output;
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_softmax_output = 0;
    IData/*31:0*/ tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_output_value;
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_output_value = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2481__lhs;
    __Vfunc_fp32_mul__2481__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2481__rhs;
    __Vfunc_fp32_mul__2481__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2481__normalize_count;
    __Vfunc_fp32_mul__2481__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2482__unused_sign;
    __Vfunc_fp32_is_nan__2482__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2483__unused_sign;
    __Vfunc_fp32_is_nan__2483__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2484__unused_sign;
    __Vfunc_fp32_is_inf__2484__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2485__unused_sign;
    __Vfunc_fp32_is_zero__2485__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2486__unused_sign;
    __Vfunc_fp32_is_inf__2486__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2487__unused_sign;
    __Vfunc_fp32_is_zero__2487__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2488__unused_sign;
    __Vfunc_fp32_is_inf__2488__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2489__unused_sign;
    __Vfunc_fp32_is_inf__2489__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2490__unused_sign;
    __Vfunc_fp32_is_zero__2490__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2491__unused_sign;
    __Vfunc_fp32_is_zero__2491__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2492__lhs;
    __Vfunc_fp32_add__2492__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2492__rhs;
    __Vfunc_fp32_add__2492__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2492__normalize_count;
    __Vfunc_fp32_add__2492__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2493__unused_sign;
    __Vfunc_fp32_is_nan__2493__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2494__unused_sign;
    __Vfunc_fp32_is_nan__2494__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2495__unused_sign;
    __Vfunc_fp32_is_inf__2495__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2496__unused_sign;
    __Vfunc_fp32_is_inf__2496__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2497__unused_sign;
    __Vfunc_fp32_is_inf__2497__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2498__unused_sign;
    __Vfunc_fp32_is_inf__2498__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2499__unused_sign;
    __Vfunc_fp32_is_inf__2499__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2500__unused_sign;
    __Vfunc_fp32_is_zero__2500__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2501__unused_sign;
    __Vfunc_fp32_is_zero__2501__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_div__2522__numerator_value;
    __Vfunc_fp32_div__2522__numerator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__2522__denominator_value;
    __Vfunc_fp32_div__2522__denominator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__2522__normalize_count;
    __Vfunc_fp32_div__2522__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2523__unused_sign;
    __Vfunc_fp32_is_nan__2523__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2524__unused_sign;
    __Vfunc_fp32_is_nan__2524__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2525__unused_sign;
    __Vfunc_fp32_is_zero__2525__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2526__unused_sign;
    __Vfunc_fp32_is_zero__2526__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2527__unused_sign;
    __Vfunc_fp32_is_inf__2527__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2528__unused_sign;
    __Vfunc_fp32_is_inf__2528__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2529__unused_sign;
    __Vfunc_fp32_is_inf__2529__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2530__unused_sign;
    __Vfunc_fp32_is_zero__2530__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2531__unused_sign;
    __Vfunc_fp32_is_zero__2531__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2532__unused_sign;
    __Vfunc_fp32_is_inf__2532__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_div__4625__numerator_value;
    __Vfunc_fp32_div__4625__numerator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__4625__denominator_value;
    __Vfunc_fp32_div__4625__denominator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__4625__normalize_count;
    __Vfunc_fp32_div__4625__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__4626__unused_sign;
    __Vfunc_fp32_is_nan__4626__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__4627__unused_sign;
    __Vfunc_fp32_is_nan__4627__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__4628__unused_sign;
    __Vfunc_fp32_is_zero__4628__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__4629__unused_sign;
    __Vfunc_fp32_is_zero__4629__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__4630__unused_sign;
    __Vfunc_fp32_is_inf__4630__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__4631__unused_sign;
    __Vfunc_fp32_is_inf__4631__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__4632__unused_sign;
    __Vfunc_fp32_is_inf__4632__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__4633__unused_sign;
    __Vfunc_fp32_is_zero__4633__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__4634__unused_sign;
    __Vfunc_fp32_is_zero__4634__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__4635__unused_sign;
    __Vfunc_fp32_is_inf__4635__unused_sign = 0;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_soft_sum_plus_exp 
        = vlSelfRef.__Vfunc_fp32_add__2512__Vfuncout;
    __Vfunc_fp32_div__2522__denominator_value = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_q;
    __Vfunc_fp32_div__2522__numerator_value = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_result;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_div__2522__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1573677164621994291ull);
    vlSelf->__Vfunc_fp32_div__2522__numerator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 1919334323342955111ull);
    vlSelf->__Vfunc_fp32_div__2522__denominator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15081428152269275241ull);
    vlSelf->__Vfunc_fp32_div__2522__scaled_numerator = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 3883768728078889207ull);
    vlSelf->__Vfunc_fp32_div__2522__denominator_wide = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 3183308640868781500ull);
    vlSelf->__Vfunc_fp32_div__2522__division_remainder = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 3146343907520099335ull);
    vlSelf->__Vfunc_fp32_div__2522__quotient_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 14308546739652973909ull);
    vlSelf->__Vfunc_fp32_div__2522__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 17534204922358645341ull);
    vlSelf->__Vfunc_fp32_div__2522__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18224595914390924738ull);
    vlSelf->__Vfunc_fp32_div__2522__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10029024940425032811ull);
    vlSelf->__Vfunc_fp32_div__2522__numerator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2110730206411294322ull);
    vlSelf->__Vfunc_fp32_div__2522__denominator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13271369699029792853ull);
    vlSelf->__Vfunc_fp32_div__2522__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7077811458116384511ull);
    __Vfunc_fp32_div__2522__normalize_count = 0;
    {
        if ((((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__2523__bits 
                                    = __Vfunc_fp32_div__2522__numerator_value;
                                __Vfunc_fp32_is_nan__2523__unused_sign = 0;
                                __Vfunc_fp32_is_nan__2523__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__2523__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__2523__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2523__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__2523__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2523__Vfuncout)) 
               | ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__2524__bits 
                                    = __Vfunc_fp32_div__2522__denominator_value;
                                __Vfunc_fp32_is_nan__2524__unused_sign = 0;
                                __Vfunc_fp32_is_nan__2524__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__2524__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__2524__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2524__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__2524__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2524__Vfuncout))) 
              | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2525__bits 
                                    = __Vfunc_fp32_div__2522__numerator_value;
                                __Vfunc_fp32_is_zero__2525__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2525__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2525__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2525__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2525__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2525__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2526__bits 
                                    = __Vfunc_fp32_div__2522__denominator_value;
                                __Vfunc_fp32_is_zero__2526__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2526__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2526__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2526__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2526__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2526__Vfuncout)))) 
             | (([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2527__bits 
                                = __Vfunc_fp32_div__2522__numerator_value;
                            __Vfunc_fp32_is_inf__2527__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2527__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2527__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2527__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2527__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2527__Vfuncout)) 
                & ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2528__bits 
                                = __Vfunc_fp32_div__2522__denominator_value;
                            __Vfunc_fp32_is_inf__2528__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2528__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2528__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2528__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2528__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2528__Vfuncout))))) {
            vlSelfRef.__Vfunc_fp32_div__2522__Vfuncout = 0x7fc00000U;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_div__2522__result_sign 
            = ((__Vfunc_fp32_div__2522__numerator_value 
                ^ __Vfunc_fp32_div__2522__denominator_value) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2529__bits 
                            = __Vfunc_fp32_div__2522__numerator_value;
                        __Vfunc_fp32_is_inf__2529__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2529__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2529__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2529__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2529__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2529__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2530__bits 
                            = __Vfunc_fp32_div__2522__denominator_value;
                        __Vfunc_fp32_is_zero__2530__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2530__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2530__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2530__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2530__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2530__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__2522__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2531__bits 
                            = __Vfunc_fp32_div__2522__numerator_value;
                        __Vfunc_fp32_is_zero__2531__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2531__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2531__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2531__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2531__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2531__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2532__bits 
                            = __Vfunc_fp32_div__2522__denominator_value;
                        __Vfunc_fp32_is_inf__2532__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2532__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2532__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2532__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2532__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2532__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__2522__result_sign) 
                   << 0x1fU);
            goto __Vlabel0;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__2522__numerator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__2522__numerator_value);
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__2522__numerator_value));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__2522__numerator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__2522__denominator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__2522__denominator_value);
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__2522__denominator_value));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__2522__denominator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_div__2522__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_div__2522__normalize_count = 1U;
        __Vfunc_fp32_div__2522__normalize_count = 2U;
        __Vfunc_fp32_div__2522__normalize_count = 3U;
        __Vfunc_fp32_div__2522__normalize_count = 4U;
        __Vfunc_fp32_div__2522__normalize_count = 5U;
        __Vfunc_fp32_div__2522__normalize_count = 6U;
        __Vfunc_fp32_div__2522__normalize_count = 7U;
        __Vfunc_fp32_div__2522__normalize_count = 8U;
        __Vfunc_fp32_div__2522__normalize_count = 9U;
        __Vfunc_fp32_div__2522__normalize_count = 0xaU;
        __Vfunc_fp32_div__2522__normalize_count = 0xbU;
        __Vfunc_fp32_div__2522__normalize_count = 0xcU;
        __Vfunc_fp32_div__2522__normalize_count = 0xdU;
        __Vfunc_fp32_div__2522__normalize_count = 0xeU;
        __Vfunc_fp32_div__2522__normalize_count = 0xfU;
        __Vfunc_fp32_div__2522__normalize_count = 0x10U;
        __Vfunc_fp32_div__2522__normalize_count = 0x11U;
        __Vfunc_fp32_div__2522__normalize_count = 0x12U;
        __Vfunc_fp32_div__2522__normalize_count = 0x13U;
        __Vfunc_fp32_div__2522__normalize_count = 0x14U;
        __Vfunc_fp32_div__2522__normalize_count = 0x15U;
        __Vfunc_fp32_div__2522__normalize_count = 0x16U;
        __Vfunc_fp32_div__2522__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_div__2522__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_div__2522__numerator_unbiased 
               - vlSelfRef.__Vfunc_fp32_div__2522__denominator_unbiased);
        vlSelfRef.__Vfunc_fp32_div__2522__scaled_numerator 
            = (0xffffffffffffffULL & VL_SHIFTL_QQI(56,56,32, (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__2522__numerator_mant)), 0x1aU));
        vlSelfRef.__Vfunc_fp32_div__2522__denominator_wide 
            = (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__2522__denominator_mant));
        vlSelfRef.__Vfunc_fp32_div__2522__quotient_ext 
            = (0xfffffffU & (IData)((0xffffffffffffffULL 
                                     & VL_DIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__2522__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__2522__denominator_wide))));
        vlSelfRef.__Vfunc_fp32_div__2522__division_remainder 
            = (0xffffffU & (IData)((0xffffffffffffffULL 
                                    & VL_MODDIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__2522__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__2522__denominator_wide))));
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2522__quotient_ext 
                      >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_div__2522__quotient_ext 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_div__2522__quotient_ext, 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__result_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2522__result_unbiased 
                   - (IData)(1U));
        }
        if ((0U != vlSelfRef.__Vfunc_fp32_div__2522__division_remainder)) {
            vlSelfRef.__Vfunc_fp32_div__2522__quotient_ext 
                = (1U | vlSelfRef.__Vfunc_fp32_div__2522__quotient_ext);
        }
        vlSelfRef.__Vfunc_fp32_div__2522__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__2522__quotient_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_div__2522__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_div__2522__quotient_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_div__2522__quotient_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_div__2522__quotient_ext) 
                                | vlSelfRef.__Vfunc_fp32_div__2522__mantissa)));
        vlSelfRef.__Vfunc_fp32_div__2522__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_div__2522__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_div__2522__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_div__2522__rounded)) {
            vlSelfRef.__Vfunc_fp32_div__2522__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__2522__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_div__2522__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_div__2522__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_div__2522__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_div__2522__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_div__2522__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__2522__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__2522__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_div__2522__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__2522__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__2522__result_sign) 
                   << 0x1fU);
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_div__2522__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_div__2522__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_div__2522__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_div__2522__mantissa)));
        __Vlabel0: ;
    }
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_softmax_output 
        = vlSelfRef.__Vfunc_fp32_div__2522__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q;
    if ((((0U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q)) 
          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid)) 
         & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q)) 
            | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client = 0U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found)) 
           & (1U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
             >> 1U)) & ((~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                            >> 1U)) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready) 
                                       >> 1U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client = 1U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found)) 
           & (2U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
             >> 2U)) & ((~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                            >> 2U)) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready) 
                                       >> 2U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client = 2U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found)) 
           & (3U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
             >> 3U)) & ((~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                            >> 3U)) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready) 
                                       >> 3U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client = 3U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found)) 
           & (4U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
             >> 4U)) & ((~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                            >> 4U)) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready) 
                                       >> 4U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client = 4U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found)) 
           & (5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
             >> 5U)) & ((~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                            >> 5U)) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready) 
                                       >> 5U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client = 5U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found)) 
           & (0U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q))) 
          & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid)) 
         & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q)) 
            | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client = 0U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found)) 
           & (1U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
             >> 1U)) & ((~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                            >> 1U)) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready) 
                                       >> 1U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client = 1U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found)) 
           & (2U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
             >> 2U)) & ((~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                            >> 2U)) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready) 
                                       >> 2U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client = 2U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found)) 
           & (3U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
             >> 3U)) & ((~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                            >> 3U)) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready) 
                                       >> 3U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client = 3U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found)) 
           & (4U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
             >> 4U)) & ((~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                            >> 4U)) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready) 
                                       >> 4U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client = 4U;
    }
    if (((((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found)) 
           & (5U < (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rr_client_q))) 
          & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
             >> 5U)) & ((~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q) 
                            >> 5U)) | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_rsp_ready) 
                                       >> 5U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client = 5U;
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
    __Vfunc_fp32_mul__2481__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_fp;
    __Vfunc_fp32_mul__2481__lhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_norm_base;
    vlSelf->__Vfunc_fp32_mul__2481__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13282719377697095557ull);
    vlSelf->__Vfunc_fp32_mul__2481__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17191591746191495953ull);
    vlSelf->__Vfunc_fp32_mul__2481__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6976114222633014909ull);
    vlSelf->__Vfunc_fp32_mul__2481__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 4942497094540490065ull);
    vlSelf->__Vfunc_fp32_mul__2481__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 1259435446879271224ull);
    vlSelf->__Vfunc_fp32_mul__2481__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 3410869528389675960ull);
    vlSelf->__Vfunc_fp32_mul__2481__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13893683828312978731ull);
    vlSelf->__Vfunc_fp32_mul__2481__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 7109938714262695016ull);
    vlSelf->__Vfunc_fp32_mul__2481__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 9211547966136758578ull);
    vlSelf->__Vfunc_fp32_mul__2481__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10180725550661367671ull);
    vlSelf->__Vfunc_fp32_mul__2481__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14858889562165240480ull);
    vlSelf->__Vfunc_fp32_mul__2481__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10705856543480628281ull);
    vlSelf->__Vfunc_fp32_mul__2481__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14225208621359766318ull);
    __Vfunc_fp32_mul__2481__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2482__bits 
                                = __Vfunc_fp32_mul__2481__lhs;
                            __Vfunc_fp32_is_nan__2482__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2482__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2482__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2482__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2482__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2482__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2482__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2483__bits 
                                = __Vfunc_fp32_mul__2481__rhs;
                            __Vfunc_fp32_is_nan__2483__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2483__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2483__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2483__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2483__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2483__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2483__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2484__bits 
                                    = __Vfunc_fp32_mul__2481__lhs;
                                __Vfunc_fp32_is_inf__2484__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2484__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2484__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2484__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2484__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2484__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2485__bits 
                                    = __Vfunc_fp32_mul__2481__rhs;
                                __Vfunc_fp32_is_zero__2485__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2485__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2485__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2485__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2485__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2485__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2486__bits 
                                    = __Vfunc_fp32_mul__2481__rhs;
                                __Vfunc_fp32_is_inf__2486__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2486__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2486__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2486__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2486__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2486__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2487__bits 
                                    = __Vfunc_fp32_mul__2481__lhs;
                                __Vfunc_fp32_is_zero__2487__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2487__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2487__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2487__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2487__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2487__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__Vfuncout = 0x7fc00000U;
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_mul__2481__result_sign 
            = ((__Vfunc_fp32_mul__2481__lhs ^ __Vfunc_fp32_mul__2481__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2488__bits 
                            = __Vfunc_fp32_mul__2481__lhs;
                        __Vfunc_fp32_is_inf__2488__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2488__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2488__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2488__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2488__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2488__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2489__bits 
                            = __Vfunc_fp32_mul__2481__rhs;
                        __Vfunc_fp32_is_inf__2489__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2489__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2489__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2489__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2489__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2489__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2481__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2490__bits 
                            = __Vfunc_fp32_mul__2481__lhs;
                        __Vfunc_fp32_is_zero__2490__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2490__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2490__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2490__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2490__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2490__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2491__bits 
                            = __Vfunc_fp32_mul__2481__rhs;
                        __Vfunc_fp32_is_zero__2491__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2491__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2491__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2491__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2491__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2491__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2481__result_sign) 
                   << 0x1fU);
            goto __Vlabel1;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2481__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2481__lhs);
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2481__lhs));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2481__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2481__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2481__rhs);
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2481__rhs));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2481__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__2481__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__2481__normalize_count = 1U;
        __Vfunc_fp32_mul__2481__normalize_count = 2U;
        __Vfunc_fp32_mul__2481__normalize_count = 3U;
        __Vfunc_fp32_mul__2481__normalize_count = 4U;
        __Vfunc_fp32_mul__2481__normalize_count = 5U;
        __Vfunc_fp32_mul__2481__normalize_count = 6U;
        __Vfunc_fp32_mul__2481__normalize_count = 7U;
        __Vfunc_fp32_mul__2481__normalize_count = 8U;
        __Vfunc_fp32_mul__2481__normalize_count = 9U;
        __Vfunc_fp32_mul__2481__normalize_count = 0xaU;
        __Vfunc_fp32_mul__2481__normalize_count = 0xbU;
        __Vfunc_fp32_mul__2481__normalize_count = 0xcU;
        __Vfunc_fp32_mul__2481__normalize_count = 0xdU;
        __Vfunc_fp32_mul__2481__normalize_count = 0xeU;
        __Vfunc_fp32_mul__2481__normalize_count = 0xfU;
        __Vfunc_fp32_mul__2481__normalize_count = 0x10U;
        __Vfunc_fp32_mul__2481__normalize_count = 0x11U;
        __Vfunc_fp32_mul__2481__normalize_count = 0x12U;
        __Vfunc_fp32_mul__2481__normalize_count = 0x13U;
        __Vfunc_fp32_mul__2481__normalize_count = 0x14U;
        __Vfunc_fp32_mul__2481__normalize_count = 0x15U;
        __Vfunc_fp32_mul__2481__normalize_count = 0x16U;
        __Vfunc_fp32_mul__2481__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__2481__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2481__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2481__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__2481__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__2481__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__2481__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__2481__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__2481__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2481__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2481__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__2481__mantissa 
            = (0xffffffU & (IData)((0xffffffffffffULL 
                                    & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__2481__product, vlSelfRef.__Vfunc_fp32_mul__2481__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__2481__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__2481__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__2481__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__2481__product 
               & vlSelfRef.__Vfunc_fp32_mul__2481__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__2481__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__2481__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__2481__rounded = vlSelfRef.__Vfunc_fp32_mul__2481__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__2481__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__2481__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__2481__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__2481__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__2481__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__2481__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2481__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__2481__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__2481__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__2481__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__2481__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2481__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2481__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__2481__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__2481__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2481__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2481__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__2481__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2481__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2481__result_sign) 
                   << 0x1fU);
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_mul__2481__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_mul__2481__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_mul__2481__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__2481__mantissa)));
        __Vlabel1: ;
    }
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_norm_scaled 
        = vlSelfRef.__Vfunc_fp32_mul__2481__Vfuncout;
    __Vtemp_2[0U] = (IData)((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr)) 
                              << 0x28U) | (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_addr)) 
                                            << 0x14U) 
                                           | (QData)((IData)(
                                                             (0xffff8U 
                                                              & ((3U 
                                                                  == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))
                                                                  ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_addr_q
                                                                  : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_addr_q)))))));
    __Vtemp_2[1U] = (((IData)((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr)) 
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
    __Vtemp_2[2U] = (((IData)((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr)) 
                                << 0x14U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr)))) 
                      >> 4U) | ((IData)(((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr)) 
                                           << 0x14U) 
                                          | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr))) 
                                         >> 0x20U)) 
                                << 0x1cU));
    __Vtemp_2[3U] = ((IData)(((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr)) 
                                << 0x14U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr))) 
                              >> 0x20U)) >> 4U);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_addr 
        = ((0x77U >= (0x7fU & ((IData)(0x14U) * (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))))
            ? (0xfffffU & (((0U == (0x1fU & ((IData)(0x14U) 
                                             * (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))))
                             ? 0U : (__Vtemp_2[(((IData)(0x13U) 
                                                 + 
                                                 (0x7fU 
                                                  & ((IData)(0x14U) 
                                                     * (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)))) 
                                                >> 5U)] 
                                     << ((IData)(0x20U) 
                                         - (0x1fU & 
                                            ((IData)(0x14U) 
                                             * (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)))))) 
                           | (__Vtemp_2[(3U & (((IData)(0x14U) 
                                                * (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)) 
                                               >> 5U))] 
                              >> (0x1fU & ((IData)(0x14U) 
                                           * (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))))))
            : 0U);
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
    __Vfunc_fp32_add__2492__rhs = ((5U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x13U])
                                    ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_fp
                                    : 0U);
    __Vfunc_fp32_add__2492__lhs = tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_norm_scaled;
    vlSelf->__Vfunc_fp32_add__2492__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17005294652904710203ull);
    vlSelf->__Vfunc_fp32_add__2492__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11983193277866705339ull);
    vlSelf->__Vfunc_fp32_add__2492__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4793910278518468552ull);
    vlSelf->__Vfunc_fp32_add__2492__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8677430375990616674ull);
    vlSelf->__Vfunc_fp32_add__2492__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7789476292238740846ull);
    vlSelf->__Vfunc_fp32_add__2492__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 1185531208524168521ull);
    vlSelf->__Vfunc_fp32_add__2492__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2258499334006268548ull);
    vlSelf->__Vfunc_fp32_add__2492__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4128211743398846819ull);
    vlSelf->__Vfunc_fp32_add__2492__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10748901853578493544ull);
    vlSelf->__Vfunc_fp32_add__2492__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11490358534940309591ull);
    vlSelf->__Vfunc_fp32_add__2492__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 1464736502571294854ull);
    vlSelf->__Vfunc_fp32_add__2492__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 772971237072242479ull);
    vlSelf->__Vfunc_fp32_add__2492__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11189420735393158060ull);
    vlSelf->__Vfunc_fp32_add__2492__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16975316039654210987ull);
    vlSelf->__Vfunc_fp32_add__2492__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 13508313096845090431ull);
    vlSelf->__Vfunc_fp32_add__2492__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 12023423458510424537ull);
    vlSelf->__Vfunc_fp32_add__2492__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 13210936524513389875ull);
    vlSelf->__Vfunc_fp32_add__2492__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 10505041755005619086ull);
    vlSelf->__Vfunc_fp32_add__2492__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 13652165158197602080ull);
    vlSelf->__Vfunc_fp32_add__2492__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 14713168164371967791ull);
    vlSelf->__Vfunc_fp32_add__2492__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4108274372596025045ull);
    vlSelf->__Vfunc_fp32_add__2492__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12196604590025452650ull);
    vlSelf->__Vfunc_fp32_add__2492__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5665738206457043483ull);
    vlSelf->__Vfunc_fp32_add__2492__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10370621990163937962ull);
    __Vfunc_fp32_add__2492__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2493__bits 
                            = __Vfunc_fp32_add__2492__lhs;
                        __Vfunc_fp32_is_nan__2493__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2493__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2493__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2493__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2493__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2493__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2493__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2494__bits 
                            = __Vfunc_fp32_add__2492__rhs;
                        __Vfunc_fp32_is_nan__2494__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2494__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2494__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2494__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2494__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2494__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2494__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__2492__Vfuncout = 0x7fc00000U;
            goto __Vlabel2;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2495__bits 
                            = __Vfunc_fp32_add__2492__lhs;
                        __Vfunc_fp32_is_inf__2495__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2495__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2495__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2495__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2495__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2495__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2496__bits 
                            = __Vfunc_fp32_add__2492__rhs;
                        __Vfunc_fp32_is_inf__2496__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2496__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2496__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2496__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2496__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2496__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2497__bits 
                                    = __Vfunc_fp32_add__2492__lhs;
                                __Vfunc_fp32_is_inf__2497__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2497__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2497__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2497__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2497__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2497__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2498__bits 
                                    = __Vfunc_fp32_add__2492__rhs;
                                __Vfunc_fp32_is_inf__2498__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2498__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2498__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2498__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2498__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2498__Vfuncout))) 
                 & ((__Vfunc_fp32_add__2492__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__2492__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__Vfuncout = 0x7fc00000U;
                goto __Vlabel2;
            }
            vlSelfRef.__Vfunc_fp32_add__2492__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2499__bits 
                            = __Vfunc_fp32_add__2492__lhs;
                        __Vfunc_fp32_is_inf__2499__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2499__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2499__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2499__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2499__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2499__Vfuncout))
                    ? __Vfunc_fp32_add__2492__lhs : __Vfunc_fp32_add__2492__rhs);
            goto __Vlabel2;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2500__bits 
                        = __Vfunc_fp32_add__2492__lhs;
                    __Vfunc_fp32_is_zero__2500__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2500__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2500__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2500__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2500__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2500__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2492__Vfuncout 
                = __Vfunc_fp32_add__2492__rhs;
            goto __Vlabel2;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2501__bits 
                        = __Vfunc_fp32_add__2492__rhs;
                    __Vfunc_fp32_is_zero__2501__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2501__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2501__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2501__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2501__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2501__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2492__Vfuncout 
                = __Vfunc_fp32_add__2492__lhs;
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_add__2492__lhs_sign 
            = (__Vfunc_fp32_add__2492__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2492__rhs_sign 
            = (__Vfunc_fp32_add__2492__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2492__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2492__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2492__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2492__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2492__lhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2492__lhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2492__lhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2492__lhs)));
        vlSelfRef.__Vfunc_fp32_add__2492__rhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2492__rhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2492__rhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2492__rhs)));
        vlSelfRef.__Vfunc_fp32_add__2492__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2492__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2492__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2492__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2492__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__2492__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__2492__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__2492__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__2492__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__2492__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2492__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2492__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2492__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2492__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2492__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2492__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2492__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2492__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2492__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2492__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2492__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2492__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2492__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2492__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2492__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2492__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2492__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2492__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2492__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2492__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2492__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2492__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2492__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2492__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2492__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2492__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__2492__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2492__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2492__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2492__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2492__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__2492__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__2492__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__2492__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2492__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__2492__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__small_ext, vlSelfRef.__Vfunc_fp32_add__2492__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__2492__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2492__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__2492__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__2492__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__2492__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__2492__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__2492__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2492__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__2492__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__2492__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__2492__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__2492__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__2492__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2492__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__2492__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__2492__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2492__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__2492__work_ext);
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2492__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__2492__sticky))));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2492__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__2492__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__2492__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2492__Vfuncout = 0U;
                goto __Vlabel2;
            }
            __Vfunc_fp32_add__2492__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2492__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__2492__normalize_count = 1U;
            __Vfunc_fp32_add__2492__normalize_count = 2U;
            __Vfunc_fp32_add__2492__normalize_count = 3U;
            __Vfunc_fp32_add__2492__normalize_count = 4U;
            __Vfunc_fp32_add__2492__normalize_count = 5U;
            __Vfunc_fp32_add__2492__normalize_count = 6U;
            __Vfunc_fp32_add__2492__normalize_count = 7U;
            __Vfunc_fp32_add__2492__normalize_count = 8U;
            __Vfunc_fp32_add__2492__normalize_count = 9U;
            __Vfunc_fp32_add__2492__normalize_count = 0xaU;
            __Vfunc_fp32_add__2492__normalize_count = 0xbU;
            __Vfunc_fp32_add__2492__normalize_count = 0xcU;
            __Vfunc_fp32_add__2492__normalize_count = 0xdU;
            __Vfunc_fp32_add__2492__normalize_count = 0xeU;
            __Vfunc_fp32_add__2492__normalize_count = 0xfU;
            __Vfunc_fp32_add__2492__normalize_count = 0x10U;
            __Vfunc_fp32_add__2492__normalize_count = 0x11U;
            __Vfunc_fp32_add__2492__normalize_count = 0x12U;
            __Vfunc_fp32_add__2492__normalize_count = 0x13U;
            __Vfunc_fp32_add__2492__normalize_count = 0x14U;
            __Vfunc_fp32_add__2492__normalize_count = 0x15U;
            __Vfunc_fp32_add__2492__normalize_count = 0x16U;
            __Vfunc_fp32_add__2492__normalize_count = 0x17U;
            __Vfunc_fp32_add__2492__normalize_count = 0x18U;
            __Vfunc_fp32_add__2492__normalize_count = 0x19U;
            __Vfunc_fp32_add__2492__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__2492__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_add__2492__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__2492__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__2492__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__2492__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__2492__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__2492__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__2492__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__2492__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__2492__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2492__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__2492__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__2492__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__2492__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__2492__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__result_sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__2492__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__2492__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__2492__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2492__mantissa));
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_add__2492__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_add__2492__result_sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__2492__large_exp) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2492__mantissa)));
        __Vlabel2: ;
    }
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_norm_output 
        = vlSelfRef.__Vfunc_fp32_add__2492__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_handshake 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_found) 
           & ((5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)) 
              & (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_valid) 
                  >> (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)) 
                 & ((5U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client)) 
                    & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__l1_req_ready) 
                       >> (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__grant_client))))));
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_output_value 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_result;
    if ((0x86U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q))) {
        tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_output_value 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_add_rescale_output;
    } else if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
        tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_output_value 
            = (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2533__bits 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_q;
                    vlSelfRef.__Vfunc_fp32_is_zero__2533__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2533__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2533__Vfuncout))
                ? 0U : tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_softmax_output);
    } else if ((5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) {
        tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_output_value 
            = tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_norm_output;
    }
    __Vfunc_fp32_div__4625__denominator_value = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1fU];
    __Vfunc_fp32_div__4625__numerator_value = tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_output_value;
    vlSelf->__Vfunc_fp32_div__4625__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15454395769131427474ull);
    vlSelf->__Vfunc_fp32_div__4625__numerator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 72747468799130415ull);
    vlSelf->__Vfunc_fp32_div__4625__denominator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8242320942964580019ull);
    vlSelf->__Vfunc_fp32_div__4625__scaled_numerator = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 3095713122791409242ull);
    vlSelf->__Vfunc_fp32_div__4625__denominator_wide = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 16576626515383968689ull);
    vlSelf->__Vfunc_fp32_div__4625__division_remainder = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 1384584275545457797ull);
    vlSelf->__Vfunc_fp32_div__4625__quotient_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 9701886911329861656ull);
    vlSelf->__Vfunc_fp32_div__4625__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6810676668732190837ull);
    vlSelf->__Vfunc_fp32_div__4625__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15906828655136777908ull);
    vlSelf->__Vfunc_fp32_div__4625__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7397690707734255443ull);
    vlSelf->__Vfunc_fp32_div__4625__numerator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 371386830893095135ull);
    vlSelf->__Vfunc_fp32_div__4625__denominator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17884416182121520380ull);
    vlSelf->__Vfunc_fp32_div__4625__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11921725820610564364ull);
    __Vfunc_fp32_div__4625__normalize_count = 0;
    {
        if ((((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__4626__bits 
                                    = __Vfunc_fp32_div__4625__numerator_value;
                                __Vfunc_fp32_is_nan__4626__unused_sign = 0;
                                __Vfunc_fp32_is_nan__4626__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__4626__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__4626__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__4626__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__4626__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__4626__Vfuncout)) 
               | ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__4627__bits 
                                    = __Vfunc_fp32_div__4625__denominator_value;
                                __Vfunc_fp32_is_nan__4627__unused_sign = 0;
                                __Vfunc_fp32_is_nan__4627__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__4627__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__4627__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__4627__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__4627__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__4627__Vfuncout))) 
              | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__4628__bits 
                                    = __Vfunc_fp32_div__4625__numerator_value;
                                __Vfunc_fp32_is_zero__4628__unused_sign = 0;
                                __Vfunc_fp32_is_zero__4628__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__4628__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__4628__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__4628__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__4628__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__4629__bits 
                                    = __Vfunc_fp32_div__4625__denominator_value;
                                __Vfunc_fp32_is_zero__4629__unused_sign = 0;
                                __Vfunc_fp32_is_zero__4629__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__4629__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__4629__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__4629__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__4629__Vfuncout)))) 
             | (([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__4630__bits 
                                = __Vfunc_fp32_div__4625__numerator_value;
                            __Vfunc_fp32_is_inf__4630__unused_sign = 0;
                            __Vfunc_fp32_is_inf__4630__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__4630__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__4630__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__4630__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__4630__Vfuncout)) 
                & ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__4631__bits 
                                = __Vfunc_fp32_div__4625__denominator_value;
                            __Vfunc_fp32_is_inf__4631__unused_sign = 0;
                            __Vfunc_fp32_is_inf__4631__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__4631__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__4631__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__4631__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__4631__Vfuncout))))) {
            vlSelfRef.__Vfunc_fp32_div__4625__Vfuncout = 0x7fc00000U;
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_div__4625__result_sign 
            = ((__Vfunc_fp32_div__4625__numerator_value 
                ^ __Vfunc_fp32_div__4625__denominator_value) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__4632__bits 
                            = __Vfunc_fp32_div__4625__numerator_value;
                        __Vfunc_fp32_is_inf__4632__unused_sign = 0;
                        __Vfunc_fp32_is_inf__4632__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__4632__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__4632__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__4632__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__4632__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__4633__bits 
                            = __Vfunc_fp32_div__4625__denominator_value;
                        __Vfunc_fp32_is_zero__4633__unused_sign = 0;
                        __Vfunc_fp32_is_zero__4633__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__4633__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__4633__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__4633__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__4633__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__4625__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__4634__bits 
                            = __Vfunc_fp32_div__4625__numerator_value;
                        __Vfunc_fp32_is_zero__4634__unused_sign = 0;
                        __Vfunc_fp32_is_zero__4634__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__4634__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__4634__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__4634__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__4634__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__4635__bits 
                            = __Vfunc_fp32_div__4625__denominator_value;
                        __Vfunc_fp32_is_inf__4635__unused_sign = 0;
                        __Vfunc_fp32_is_inf__4635__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__4635__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__4635__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__4635__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__4635__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__4625__result_sign) 
                   << 0x1fU);
            goto __Vlabel3;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__4625__numerator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__4625__numerator_value);
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__4625__numerator_value));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__4625__numerator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__4625__denominator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__4625__denominator_value);
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__4625__denominator_value));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__4625__denominator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_div__4625__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_div__4625__normalize_count = 1U;
        __Vfunc_fp32_div__4625__normalize_count = 2U;
        __Vfunc_fp32_div__4625__normalize_count = 3U;
        __Vfunc_fp32_div__4625__normalize_count = 4U;
        __Vfunc_fp32_div__4625__normalize_count = 5U;
        __Vfunc_fp32_div__4625__normalize_count = 6U;
        __Vfunc_fp32_div__4625__normalize_count = 7U;
        __Vfunc_fp32_div__4625__normalize_count = 8U;
        __Vfunc_fp32_div__4625__normalize_count = 9U;
        __Vfunc_fp32_div__4625__normalize_count = 0xaU;
        __Vfunc_fp32_div__4625__normalize_count = 0xbU;
        __Vfunc_fp32_div__4625__normalize_count = 0xcU;
        __Vfunc_fp32_div__4625__normalize_count = 0xdU;
        __Vfunc_fp32_div__4625__normalize_count = 0xeU;
        __Vfunc_fp32_div__4625__normalize_count = 0xfU;
        __Vfunc_fp32_div__4625__normalize_count = 0x10U;
        __Vfunc_fp32_div__4625__normalize_count = 0x11U;
        __Vfunc_fp32_div__4625__normalize_count = 0x12U;
        __Vfunc_fp32_div__4625__normalize_count = 0x13U;
        __Vfunc_fp32_div__4625__normalize_count = 0x14U;
        __Vfunc_fp32_div__4625__normalize_count = 0x15U;
        __Vfunc_fp32_div__4625__normalize_count = 0x16U;
        __Vfunc_fp32_div__4625__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_div__4625__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_div__4625__numerator_unbiased 
               - vlSelfRef.__Vfunc_fp32_div__4625__denominator_unbiased);
        vlSelfRef.__Vfunc_fp32_div__4625__scaled_numerator 
            = (0xffffffffffffffULL & VL_SHIFTL_QQI(56,56,32, (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__4625__numerator_mant)), 0x1aU));
        vlSelfRef.__Vfunc_fp32_div__4625__denominator_wide 
            = (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__4625__denominator_mant));
        vlSelfRef.__Vfunc_fp32_div__4625__quotient_ext 
            = (0xfffffffU & (IData)((0xffffffffffffffULL 
                                     & VL_DIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__4625__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__4625__denominator_wide))));
        vlSelfRef.__Vfunc_fp32_div__4625__division_remainder 
            = (0xffffffU & (IData)((0xffffffffffffffULL 
                                    & VL_MODDIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__4625__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__4625__denominator_wide))));
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__4625__quotient_ext 
                      >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_div__4625__quotient_ext 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_div__4625__quotient_ext, 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__result_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__4625__result_unbiased 
                   - (IData)(1U));
        }
        if ((0U != vlSelfRef.__Vfunc_fp32_div__4625__division_remainder)) {
            vlSelfRef.__Vfunc_fp32_div__4625__quotient_ext 
                = (1U | vlSelfRef.__Vfunc_fp32_div__4625__quotient_ext);
        }
        vlSelfRef.__Vfunc_fp32_div__4625__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__4625__quotient_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_div__4625__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_div__4625__quotient_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_div__4625__quotient_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_div__4625__quotient_ext) 
                                | vlSelfRef.__Vfunc_fp32_div__4625__mantissa)));
        vlSelfRef.__Vfunc_fp32_div__4625__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_div__4625__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_div__4625__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_div__4625__rounded)) {
            vlSelfRef.__Vfunc_fp32_div__4625__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__4625__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_div__4625__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_div__4625__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_div__4625__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_div__4625__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_div__4625__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__4625__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__4625__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_div__4625__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__4625__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__4625__result_sign) 
                   << 0x1fU);
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_div__4625__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_div__4625__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_div__4625__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_div__4625__mantissa)));
        __Vlabel3: ;
    }
}
