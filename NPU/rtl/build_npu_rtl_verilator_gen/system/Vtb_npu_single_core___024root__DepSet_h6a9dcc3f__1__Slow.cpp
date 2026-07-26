// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core___024root.h"

VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__2(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___stl_sequent__TOP__2\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_stride;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__dtype = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col_offset = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2673__lhs;
    __Vfunc_fp32_mul__2673__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2673__rhs;
    __Vfunc_fp32_mul__2673__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2673__normalize_count;
    __Vfunc_fp32_mul__2673__normalize_count = 0;
    QData/*63:0*/ __Vfunc_fp32_from_int__2674__value;
    __Vfunc_fp32_from_int__2674__value = 0;
    IData/*31:0*/ __Vfunc_fp32_from_int__2674__bit_index;
    __Vfunc_fp32_from_int__2674__bit_index = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2675__unused_sign;
    __Vfunc_fp32_is_nan__2675__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2676__unused_sign;
    __Vfunc_fp32_is_nan__2676__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2677__unused_sign;
    __Vfunc_fp32_is_inf__2677__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2678__unused_sign;
    __Vfunc_fp32_is_zero__2678__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2679__unused_sign;
    __Vfunc_fp32_is_inf__2679__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2680__unused_sign;
    __Vfunc_fp32_is_zero__2680__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2681__unused_sign;
    __Vfunc_fp32_is_inf__2681__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2682__unused_sign;
    __Vfunc_fp32_is_inf__2682__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2683__unused_sign;
    __Vfunc_fp32_is_zero__2683__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2684__unused_sign;
    __Vfunc_fp32_is_zero__2684__unused_sign = 0;
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dependency_failed[4U] 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                    [4U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 0U;
                        goto __Vlabel0;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel0;
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
                    __Vlabel0: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [4U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel1;
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
                    __Vlabel1: ;
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
                        goto __Vlabel2;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel2;
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
                    __Vlabel2: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [5U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel3;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel3;
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
                    __Vlabel3: ;
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
                        goto __Vlabel4;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel4;
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
                    __Vlabel4: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [5U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel5;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel5;
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
                    __Vlabel5: ;
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
                        goto __Vlabel6;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel6;
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
                    __Vlabel6: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [6U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel7;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel7;
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
                    __Vlabel7: ;
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
                        goto __Vlabel8;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel8;
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
                    __Vlabel8: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [6U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel9;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel9;
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
                    __Vlabel9: ;
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
                        goto __Vlabel10;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout = 0U;
                        goto __Vlabel10;
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
                    __Vlabel10: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1697__Vfuncout)) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [7U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 1U;
                        goto __Vlabel11;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_success__1698__Vfuncout = 0U;
                        goto __Vlabel11;
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
                    __Vlabel11: ;
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
                        goto __Vlabel12;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout = 1U;
                        goto __Vlabel12;
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
                    __Vlabel12: ;
                }
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1699__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                    [7U];
                {
                    if ((0xfffU == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 0U;
                        goto __Vlabel13;
                    }
                    if ((0xffU <= (0xffU & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__event_ref)))) {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_is_failed__1700__Vfuncout = 1U;
                        goto __Vlabel13;
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
                    __Vlabel13: ;
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_is_tiled 
        = ((2U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x24U] 
                            >> 8U))) | ((3U == (0xffU 
                                                & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x24U] 
                                                   >> 8U))) 
                                        | (6U == (0xffU 
                                                  & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x24U] 
                                                     >> 8U)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__norm_parameter_phase 
        = ((0x82U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
           & (5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_valid = 0U;
    if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_valid = 1U;
        }
    }
    if ((6U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_valid = 1U;
        }
    }
    if ((8U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_valid = 1U;
        }
    }
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                 >> 6U));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x17U];
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[9U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[8U])));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_offset 
        = ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row)) 
           * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_stride)));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col_offset 
        = ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__dtype))
            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col)), 1U)
            : ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col)) 
               * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__2342__dtype 
                            = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__2342__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2342__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2342__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2342__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2342__Vfuncout)))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__Vfuncout 
        = ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__base 
            + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__row_offset) 
           + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__col_offset);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__normal_dst_addr 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2341__Vfuncout;
    __Vfunc_fp32_mul__2673__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1eU];
    __Vfunc_fp32_from_int__2674__value = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_value_q 
                                          - (((QData)((IData)(
                                                              (- (IData)(
                                                                         (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x22U] 
                                                                          >> 0x1fU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x22U]))));
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_from_int__2674__sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4305783727576925133ull);
    vlSelf->__Vfunc_fp32_from_int__2674__magnitude = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3501636320521562658ull);
    vlSelf->__Vfunc_fp32_from_int__2674__shifted_significand = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17669944297504789151ull);
    vlSelf->__Vfunc_fp32_from_int__2674__remainder_mask = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10579900057149268282ull);
    vlSelf->__Vfunc_fp32_from_int__2674__remainder = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 670560698169395296ull);
    vlSelf->__Vfunc_fp32_from_int__2674__halfway = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10026636171683768370ull);
    vlSelf->__Vfunc_fp32_from_int__2674__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 13416100474595597551ull);
    vlSelf->__Vfunc_fp32_from_int__2674__fraction = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 8839677210556453702ull);
    vlSelf->__Vfunc_fp32_from_int__2674__exponent = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 8460141436954743481ull);
    vlSelf->__Vfunc_fp32_from_int__2674__leading_bit = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 506528000175917233ull);
    vlSelf->__Vfunc_fp32_from_int__2674__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1555238835906288318ull);
    __Vfunc_fp32_from_int__2674__bit_index = 0;
    {
        if ((0ULL == __Vfunc_fp32_from_int__2674__value)) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__Vfuncout = 0U;
            goto __Vlabel14;
        }
        vlSelfRef.__Vfunc_fp32_from_int__2674__sign 
            = (1U & (IData)((__Vfunc_fp32_from_int__2674__value 
                             >> 0x3fU)));
        vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
            = ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__sign)
                ? (1ULL + (~ __Vfunc_fp32_from_int__2674__value))
                : __Vfunc_fp32_from_int__2674__value);
        vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0U;
        __Vfunc_fp32_from_int__2674__bit_index = 0U;
        if ((1U & (IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 1U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 1U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 1U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 2U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 2U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 2U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 3U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 3U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 3U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 4U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 4U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 4U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 5U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 5U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 5U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 6U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 6U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 6U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 7U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 7U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 7U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 8U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 8U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 8U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 9U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 9U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 9U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0xaU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0xaU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0xaU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0xbU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0xbU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0xbU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0xcU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0xcU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0xcU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0xdU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0xdU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0xdU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0xeU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0xeU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0xeU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0xfU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0xfU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0xfU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x10U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x10U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x10U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x11U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x11U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x11U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x12U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x12U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x12U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x13U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x13U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x13U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x14U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x14U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x14U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x15U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x15U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x15U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x16U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x16U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x16U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x17U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x17U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x18U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x18U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x18U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x19U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x19U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x19U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x1aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x1aU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x1bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x1bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x1bU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x1cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x1cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x1cU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x1dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x1dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x1dU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x1eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x1eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x1eU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x1fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x1fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x1fU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x20U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x20U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x20U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x21U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x21U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x21U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x22U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x22U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x22U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x23U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x23U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x23U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x24U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x24U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x24U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x25U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x25U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x25U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x26U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x26U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x26U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x27U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x27U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x27U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x28U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x28U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x28U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x29U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x29U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x29U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x2aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x2aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x2aU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x2bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x2bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x2bU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x2cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x2cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x2cU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x2dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x2dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x2dU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x2eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x2eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x2eU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x2fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x2fU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x30U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x30U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x30U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x31U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x31U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x31U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x32U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x32U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x32U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x33U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x33U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x33U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x34U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x34U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x34U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x35U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x35U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x35U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x36U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x36U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x36U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x37U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x37U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x37U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x38U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x38U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x38U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x39U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x39U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x39U;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x3aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x3aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x3aU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x3bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x3bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x3bU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x3cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x3cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x3cU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x3dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x3dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x3dU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x3eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x3eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x3eU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x3fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                           >> 0x3fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit = 0x3fU;
        }
        __Vfunc_fp32_from_int__2674__bit_index = 0x40U;
        vlSelfRef.__Vfunc_fp32_from_int__2674__exponent 
            = (0x1ffU & ((IData)(0x7fU) + vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit));
        if (VL_GTES_III(32, 0x17U, vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit)) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTL_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude, 
                                                     ((IData)(0x17U) 
                                                      - vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit))));
            vlSelfRef.__Vfunc_fp32_from_int__2674__fraction 
                = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__2674__shifted_significand);
        } else {
            vlSelfRef.__Vfunc_fp32_from_int__2674__shift_amount 
                = (vlSelfRef.__Vfunc_fp32_from_int__2674__leading_bit 
                   - (IData)(0x17U));
            vlSelfRef.__Vfunc_fp32_from_int__2674__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTR_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude, vlSelfRef.__Vfunc_fp32_from_int__2674__shift_amount)));
            vlSelfRef.__Vfunc_fp32_from_int__2674__remainder_mask 
                = (VL_SHIFTL_QQI(64,64,32, 1ULL, vlSelfRef.__Vfunc_fp32_from_int__2674__shift_amount) 
                   - 1ULL);
            vlSelfRef.__Vfunc_fp32_from_int__2674__remainder 
                = (vlSelfRef.__Vfunc_fp32_from_int__2674__magnitude 
                   & vlSelfRef.__Vfunc_fp32_from_int__2674__remainder_mask);
            vlSelfRef.__Vfunc_fp32_from_int__2674__halfway 
                = VL_SHIFTL_QQI(64,64,32, 1ULL, (vlSelfRef.__Vfunc_fp32_from_int__2674__shift_amount 
                                                 - (IData)(1U)));
            vlSelfRef.__Vfunc_fp32_from_int__2674__rounded 
                = vlSelfRef.__Vfunc_fp32_from_int__2674__shifted_significand;
            if (((vlSelfRef.__Vfunc_fp32_from_int__2674__remainder 
                  > vlSelfRef.__Vfunc_fp32_from_int__2674__halfway) 
                 | ((vlSelfRef.__Vfunc_fp32_from_int__2674__remainder 
                     == vlSelfRef.__Vfunc_fp32_from_int__2674__halfway) 
                    & vlSelfRef.__Vfunc_fp32_from_int__2674__shifted_significand))) {
                vlSelfRef.__Vfunc_fp32_from_int__2674__rounded 
                    = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_from_int__2674__rounded));
            }
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_from_int__2674__rounded)) {
                vlSelfRef.__Vfunc_fp32_from_int__2674__fraction 
                    = (0x7fffffU & (vlSelfRef.__Vfunc_fp32_from_int__2674__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_from_int__2674__exponent 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__exponent)));
            } else {
                vlSelfRef.__Vfunc_fp32_from_int__2674__fraction 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__2674__rounded);
            }
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__exponent))) {
            vlSelfRef.__Vfunc_fp32_from_int__2674__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__sign) 
                                  << 0x1fU));
            goto __Vlabel14;
        }
        vlSelfRef.__Vfunc_fp32_from_int__2674__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2674__exponent) 
                                             << 0x17U)) 
                             | vlSelfRef.__Vfunc_fp32_from_int__2674__fraction));
        __Vlabel14: ;
    }
    __Vfunc_fp32_mul__2673__lhs = vlSelfRef.__Vfunc_fp32_from_int__2674__Vfuncout;
    vlSelf->__Vfunc_fp32_mul__2673__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11924592379695937229ull);
    vlSelf->__Vfunc_fp32_mul__2673__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8333149821433885813ull);
    vlSelf->__Vfunc_fp32_mul__2673__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12842757615863037581ull);
    vlSelf->__Vfunc_fp32_mul__2673__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 11601252661773846804ull);
    vlSelf->__Vfunc_fp32_mul__2673__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 7692099731219814740ull);
    vlSelf->__Vfunc_fp32_mul__2673__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13543198430249221645ull);
    vlSelf->__Vfunc_fp32_mul__2673__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 11781868779845198201ull);
    vlSelf->__Vfunc_fp32_mul__2673__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 4468126067709306060ull);
    vlSelf->__Vfunc_fp32_mul__2673__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10640003147816190933ull);
    vlSelf->__Vfunc_fp32_mul__2673__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8185606933892408290ull);
    vlSelf->__Vfunc_fp32_mul__2673__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15741770250884972902ull);
    vlSelf->__Vfunc_fp32_mul__2673__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 54278704876743577ull);
    vlSelf->__Vfunc_fp32_mul__2673__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9976173162612916383ull);
    __Vfunc_fp32_mul__2673__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2675__bits 
                                = __Vfunc_fp32_mul__2673__lhs;
                            __Vfunc_fp32_is_nan__2675__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2675__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2675__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2675__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2675__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2675__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2675__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2676__bits 
                                = __Vfunc_fp32_mul__2673__rhs;
                            __Vfunc_fp32_is_nan__2676__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2676__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2676__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2676__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2676__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2676__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2676__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2677__bits 
                                    = __Vfunc_fp32_mul__2673__lhs;
                                __Vfunc_fp32_is_inf__2677__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2677__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2677__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2677__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2677__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2677__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2678__bits 
                                    = __Vfunc_fp32_mul__2673__rhs;
                                __Vfunc_fp32_is_zero__2678__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2678__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2678__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2678__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2678__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2678__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2679__bits 
                                    = __Vfunc_fp32_mul__2673__rhs;
                                __Vfunc_fp32_is_inf__2679__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2679__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2679__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2679__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2679__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2679__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2680__bits 
                                    = __Vfunc_fp32_mul__2673__lhs;
                                __Vfunc_fp32_is_zero__2680__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2680__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2680__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2680__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2680__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2680__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout = 0x7fc00000U;
            goto __Vlabel15;
        }
        vlSelfRef.__Vfunc_fp32_mul__2673__result_sign 
            = ((__Vfunc_fp32_mul__2673__lhs ^ __Vfunc_fp32_mul__2673__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2681__bits 
                            = __Vfunc_fp32_mul__2673__lhs;
                        __Vfunc_fp32_is_inf__2681__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2681__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2681__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2681__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2681__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2681__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2682__bits 
                            = __Vfunc_fp32_mul__2673__rhs;
                        __Vfunc_fp32_is_inf__2682__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2682__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2682__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2682__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2682__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2682__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__result_sign) 
                                  << 0x1fU));
            goto __Vlabel15;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2683__bits 
                            = __Vfunc_fp32_mul__2673__lhs;
                        __Vfunc_fp32_is_zero__2683__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2683__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2683__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2683__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2683__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2683__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2684__bits 
                            = __Vfunc_fp32_mul__2673__rhs;
                        __Vfunc_fp32_is_zero__2684__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2684__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2684__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2684__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2684__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2684__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__result_sign) 
                   << 0x1fU);
            goto __Vlabel15;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2673__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2673__lhs);
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2673__lhs));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2673__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2673__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2673__rhs);
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2673__rhs));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2673__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__2673__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__2673__normalize_count = 1U;
        __Vfunc_fp32_mul__2673__normalize_count = 2U;
        __Vfunc_fp32_mul__2673__normalize_count = 3U;
        __Vfunc_fp32_mul__2673__normalize_count = 4U;
        __Vfunc_fp32_mul__2673__normalize_count = 5U;
        __Vfunc_fp32_mul__2673__normalize_count = 6U;
        __Vfunc_fp32_mul__2673__normalize_count = 7U;
        __Vfunc_fp32_mul__2673__normalize_count = 8U;
        __Vfunc_fp32_mul__2673__normalize_count = 9U;
        __Vfunc_fp32_mul__2673__normalize_count = 0xaU;
        __Vfunc_fp32_mul__2673__normalize_count = 0xbU;
        __Vfunc_fp32_mul__2673__normalize_count = 0xcU;
        __Vfunc_fp32_mul__2673__normalize_count = 0xdU;
        __Vfunc_fp32_mul__2673__normalize_count = 0xeU;
        __Vfunc_fp32_mul__2673__normalize_count = 0xfU;
        __Vfunc_fp32_mul__2673__normalize_count = 0x10U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x11U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x12U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x13U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x14U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x15U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x16U;
        __Vfunc_fp32_mul__2673__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__2673__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__2673__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__2673__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__2673__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2673__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__2673__mantissa 
            = (0xffffffU & (IData)((0xffffffffffffULL 
                                    & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__2673__product, vlSelfRef.__Vfunc_fp32_mul__2673__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__2673__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__2673__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__2673__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__2673__product 
               & vlSelfRef.__Vfunc_fp32_mul__2673__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__2673__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__2673__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__2673__rounded = vlSelfRef.__Vfunc_fp32_mul__2673__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__2673__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__2673__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__2673__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__2673__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__2673__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__2673__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2673__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__2673__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__2673__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__2673__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2673__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__2673__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__result_sign) 
                                  << 0x1fU));
            goto __Vlabel15;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__result_sign) 
                   << 0x1fU);
            goto __Vlabel15;
        }
        vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_mul__2673__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_mul__2673__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__2673__mantissa)));
        __Vlabel15: ;
    }
}

VL_ATTR_COLD void Vtb_npu_single_core___024root___stl_sequent__TOP__5(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___stl_sequent__TOP__5\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns_fp;
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns_fp = 0;
    QData/*63:0*/ __Vfunc_fp32_from_int__2371__value;
    __Vfunc_fp32_from_int__2371__value = 0;
    IData/*31:0*/ __Vfunc_fp32_from_int__2371__bit_index;
    __Vfunc_fp32_from_int__2371__bit_index = 0;
    IData/*31:0*/ __Vfunc_fp32_div__2403__numerator_value;
    __Vfunc_fp32_div__2403__numerator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__2403__denominator_value;
    __Vfunc_fp32_div__2403__denominator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__2403__normalize_count;
    __Vfunc_fp32_div__2403__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2404__unused_sign;
    __Vfunc_fp32_is_nan__2404__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2405__unused_sign;
    __Vfunc_fp32_is_nan__2405__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2406__unused_sign;
    __Vfunc_fp32_is_zero__2406__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2407__unused_sign;
    __Vfunc_fp32_is_zero__2407__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2408__unused_sign;
    __Vfunc_fp32_is_inf__2408__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2409__unused_sign;
    __Vfunc_fp32_is_inf__2409__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2410__unused_sign;
    __Vfunc_fp32_is_inf__2410__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2411__unused_sign;
    __Vfunc_fp32_is_zero__2411__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2412__unused_sign;
    __Vfunc_fp32_is_zero__2412__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2413__unused_sign;
    __Vfunc_fp32_is_inf__2413__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_div__2414__numerator_value;
    __Vfunc_fp32_div__2414__numerator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__2414__denominator_value;
    __Vfunc_fp32_div__2414__denominator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__2414__normalize_count;
    __Vfunc_fp32_div__2414__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2415__unused_sign;
    __Vfunc_fp32_is_nan__2415__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2416__unused_sign;
    __Vfunc_fp32_is_nan__2416__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2417__unused_sign;
    __Vfunc_fp32_is_zero__2417__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2418__unused_sign;
    __Vfunc_fp32_is_zero__2418__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2419__unused_sign;
    __Vfunc_fp32_is_inf__2419__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2420__unused_sign;
    __Vfunc_fp32_is_inf__2420__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2421__unused_sign;
    __Vfunc_fp32_is_inf__2421__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2422__unused_sign;
    __Vfunc_fp32_is_zero__2422__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2423__unused_sign;
    __Vfunc_fp32_is_zero__2423__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2424__unused_sign;
    __Vfunc_fp32_is_inf__2424__unused_sign = 0;
    CData/*7:0*/ __Vfunc_store_element_strb__2648__Vfuncout;
    __Vfunc_store_element_strb__2648__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_store_element_strb__2648__byte_lane;
    __Vfunc_store_element_strb__2648__byte_lane = 0;
    CData/*1:0*/ __Vfunc_store_element_strb__2648__dtype;
    __Vfunc_store_element_strb__2648__dtype = 0;
    CData/*7:0*/ __Vfunc_store_element_strb__2648__result;
    __Vfunc_store_element_strb__2648__result = 0;
    // Body
    __Vfunc_fp32_from_int__2371__value = (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns));
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_from_int__2371__sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14122653780355589040ull);
    vlSelf->__Vfunc_fp32_from_int__2371__magnitude = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6003652978973479917ull);
    vlSelf->__Vfunc_fp32_from_int__2371__shifted_significand = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2127872164730954541ull);
    vlSelf->__Vfunc_fp32_from_int__2371__remainder_mask = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5403770588520233071ull);
    vlSelf->__Vfunc_fp32_from_int__2371__remainder = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1453620046471423214ull);
    vlSelf->__Vfunc_fp32_from_int__2371__halfway = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14583412714586643795ull);
    vlSelf->__Vfunc_fp32_from_int__2371__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 10647728467795386524ull);
    vlSelf->__Vfunc_fp32_from_int__2371__fraction = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 5070346497324574052ull);
    vlSelf->__Vfunc_fp32_from_int__2371__exponent = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4185517040323254036ull);
    vlSelf->__Vfunc_fp32_from_int__2371__leading_bit = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10290373519626125147ull);
    vlSelf->__Vfunc_fp32_from_int__2371__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10891097319668503522ull);
    __Vfunc_fp32_from_int__2371__bit_index = 0;
    {
        if ((0ULL == __Vfunc_fp32_from_int__2371__value)) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__Vfuncout = 0U;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_from_int__2371__sign 
            = (1U & (IData)((__Vfunc_fp32_from_int__2371__value 
                             >> 0x3fU)));
        vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
            = ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2371__sign)
                ? (1ULL + (~ __Vfunc_fp32_from_int__2371__value))
                : __Vfunc_fp32_from_int__2371__value);
        vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0U;
        __Vfunc_fp32_from_int__2371__bit_index = 0U;
        if ((1U & (IData)(vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 1U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 1U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 1U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 2U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 2U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 2U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 3U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 3U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 3U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 4U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 4U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 4U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 5U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 5U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 5U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 6U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 6U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 6U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 7U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 7U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 7U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 8U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 8U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 8U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 9U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 9U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 9U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0xaU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0xaU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0xaU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0xbU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0xbU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0xbU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0xcU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0xcU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0xcU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0xdU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0xdU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0xdU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0xeU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0xeU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0xeU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0xfU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0xfU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0xfU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x10U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x10U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x10U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x11U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x11U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x11U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x12U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x12U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x12U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x13U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x13U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x13U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x14U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x14U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x14U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x15U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x15U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x15U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x16U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x16U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x16U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x17U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x17U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x18U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x18U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x18U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x19U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x19U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x19U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x1aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x1aU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x1bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x1bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x1bU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x1cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x1cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x1cU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x1dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x1dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x1dU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x1eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x1eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x1eU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x1fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x1fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x1fU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x20U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x20U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x20U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x21U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x21U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x21U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x22U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x22U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x22U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x23U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x23U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x23U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x24U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x24U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x24U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x25U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x25U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x25U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x26U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x26U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x26U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x27U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x27U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x27U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x28U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x28U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x28U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x29U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x29U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x29U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x2aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x2aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x2aU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x2bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x2bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x2bU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x2cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x2cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x2cU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x2dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x2dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x2dU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x2eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x2eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x2eU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x2fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x2fU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x30U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x30U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x30U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x31U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x31U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x31U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x32U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x32U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x32U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x33U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x33U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x33U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x34U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x34U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x34U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x35U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x35U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x35U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x36U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x36U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x36U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x37U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x37U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x37U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x38U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x38U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x38U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x39U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x39U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x39U;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x3aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x3aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x3aU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x3bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x3bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x3bU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x3cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x3cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x3cU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x3dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x3dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x3dU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x3eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x3eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x3eU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x3fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                           >> 0x3fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit = 0x3fU;
        }
        __Vfunc_fp32_from_int__2371__bit_index = 0x40U;
        vlSelfRef.__Vfunc_fp32_from_int__2371__exponent 
            = (0x1ffU & ((IData)(0x7fU) + vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit));
        if (VL_GTES_III(32, 0x17U, vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit)) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTL_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude, 
                                                     ((IData)(0x17U) 
                                                      - vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit))));
            vlSelfRef.__Vfunc_fp32_from_int__2371__fraction 
                = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__2371__shifted_significand);
        } else {
            vlSelfRef.__Vfunc_fp32_from_int__2371__shift_amount 
                = (vlSelfRef.__Vfunc_fp32_from_int__2371__leading_bit 
                   - (IData)(0x17U));
            vlSelfRef.__Vfunc_fp32_from_int__2371__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTR_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude, vlSelfRef.__Vfunc_fp32_from_int__2371__shift_amount)));
            vlSelfRef.__Vfunc_fp32_from_int__2371__remainder_mask 
                = (VL_SHIFTL_QQI(64,64,32, 1ULL, vlSelfRef.__Vfunc_fp32_from_int__2371__shift_amount) 
                   - 1ULL);
            vlSelfRef.__Vfunc_fp32_from_int__2371__remainder 
                = (vlSelfRef.__Vfunc_fp32_from_int__2371__magnitude 
                   & vlSelfRef.__Vfunc_fp32_from_int__2371__remainder_mask);
            vlSelfRef.__Vfunc_fp32_from_int__2371__halfway 
                = VL_SHIFTL_QQI(64,64,32, 1ULL, (vlSelfRef.__Vfunc_fp32_from_int__2371__shift_amount 
                                                 - (IData)(1U)));
            vlSelfRef.__Vfunc_fp32_from_int__2371__rounded 
                = vlSelfRef.__Vfunc_fp32_from_int__2371__shifted_significand;
            if (((vlSelfRef.__Vfunc_fp32_from_int__2371__remainder 
                  > vlSelfRef.__Vfunc_fp32_from_int__2371__halfway) 
                 | ((vlSelfRef.__Vfunc_fp32_from_int__2371__remainder 
                     == vlSelfRef.__Vfunc_fp32_from_int__2371__halfway) 
                    & vlSelfRef.__Vfunc_fp32_from_int__2371__shifted_significand))) {
                vlSelfRef.__Vfunc_fp32_from_int__2371__rounded 
                    = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_from_int__2371__rounded));
            }
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_from_int__2371__rounded)) {
                vlSelfRef.__Vfunc_fp32_from_int__2371__fraction 
                    = (0x7fffffU & (vlSelfRef.__Vfunc_fp32_from_int__2371__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_from_int__2371__exponent 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_from_int__2371__exponent)));
            } else {
                vlSelfRef.__Vfunc_fp32_from_int__2371__fraction 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__2371__rounded);
            }
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_from_int__2371__exponent))) {
            vlSelfRef.__Vfunc_fp32_from_int__2371__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2371__sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_from_int__2371__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_from_int__2371__sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2371__exponent) 
                                             << 0x17U)) 
                             | vlSelfRef.__Vfunc_fp32_from_int__2371__fraction));
        __Vlabel0: ;
    }
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns_fp 
        = vlSelfRef.__Vfunc_fp32_from_int__2371__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_pop_w 
        = ((5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)) 
           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_rsp_ready));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__write_channels_done 
        = (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_done_q) 
            | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_handshake)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_done_q) 
              | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_handshake)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__input_handshake 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_ready) 
           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_valid));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_complete_error_w 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_error_q) 
           | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_current_error_w));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_comb = 0U;
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [0U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [0U] == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_comb = 1U;
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [1U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [1U] == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_comb = 1U;
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [2U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [2U] == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_comb = 1U;
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [3U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [3U] == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_comb = 1U;
    }
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
          [4U]) & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                   [4U] == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__lookup_busy_comb = 1U;
    }
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 0U;
    if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
         & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [0U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [0U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [0U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [0U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
            == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 1U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [1U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [1U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [1U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [1U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 2U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [2U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [2U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [2U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [2U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 3U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [3U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [3U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [3U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [3U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 4U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [4U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [4U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [4U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [4U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 5U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [5U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [5U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [5U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [5U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 6U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [6U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [6U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [6U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [6U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_valid_q) 
          >> 7U) & (([&]() {
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[0U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [7U][0U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [7U][1U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[2U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [7U][2U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_q
                            [7U][3U];
                        vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout 
                            = (0xfffU & ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                          >> 0x1fU)
                                          ? (0x3ffU 
                                             & (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[3U] 
                                                >> 0x10U))
                                          : ((vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                              << 0x10U) 
                                             | (vlSelfRef.__Vfunc_npu_cmd_command_id__1668__command[1U] 
                                                >> 0x10U))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_cmd_command_id__1668__Vfuncout)) 
                    == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__candidate_command_id)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__local_duplicate = 1U;
    }
    if ((1U & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                       >> 0x3fU)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__header_format_valid = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__opcode_format_valid 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT____VdfgExtracted_h654434c1__0;
    } else {
        vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode 
            = (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__header_format_valid 
            = ((((IData)(((0ULL == (0x3fULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q)) 
                          & (0x100000000000000ULL == 
                             (0xff000000000c0000ULL 
                              & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q)))) 
                 & ([&]() {
                            vlSelfRef.__Vfunc_npu_event_ref_valid__1669__event_ref 
                                = (0xfffU & (IData)(
                                                    (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                                                     >> 0x14U)));
                            vlSelfRef.__Vfunc_npu_event_ref_valid__1669__Vfuncout 
                                = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1669__event_ref)) 
                                   | (0xffU != (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1669__event_ref))));
                        }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1669__Vfuncout))) 
                & ([&]() {
                        vlSelfRef.__Vfunc_npu_event_ref_valid__1670__event_ref 
                            = (0xfffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                                                 >> 0x20U)));
                        vlSelfRef.__Vfunc_npu_event_ref_valid__1670__Vfuncout 
                            = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1670__event_ref)) 
                               | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1670__event_ref))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1670__Vfuncout))) 
               & ([&]() {
                    vlSelfRef.__Vfunc_npu_event_ref_valid__1671__event_ref 
                        = (0xfffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__high_word_q 
                                             >> 0x2cU)));
                    vlSelfRef.__Vfunc_npu_event_ref_valid__1671__Vfuncout 
                        = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1671__event_ref)) 
                           | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1671__event_ref))));
                }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1671__Vfuncout)));
        vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine 
            = (0xfU & (IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__low_word_q 
                               >> 0x3cU)));
        vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__Vfuncout 
            = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine) 
                         >> 3U))) && ((4U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine))
                                       ? ((1U & (~ 
                                                 ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine) 
                                                  >> 1U))) 
                                          && ((1U & 
                                               (~ (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine))) 
                                              && (((((0x80U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)) 
                                                     | (0x81U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                    | (0x82U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                   | (0x84U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                  | (0x86U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)))))
                                       : ((2U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine))
                                           ? ((1U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine))
                                               ? ((
                                                   ((((((((0x60U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)) 
                                                          | (0x61U 
                                                             == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                         | (0x62U 
                                                            == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                        | (0x63U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                       | (0x64U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                      | (0x65U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                     | (0x66U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                    | (0x67U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                   | (0x68U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                  | (0x69U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)))
                                               : ((
                                                   ((0x40U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)) 
                                                    | (0x41U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                   | (0x42U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                  | (0x43U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))))
                                           : ((1U & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__engine))
                                               ? ((
                                                   ((((0x20U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)) 
                                                      | (0x21U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                     | (0x22U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                    | (0x23U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                   | (0x24U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                  | (0x25U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)))
                                               : ((
                                                   (((0U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)) 
                                                     | (1U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                    | (2U 
                                                       == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                   | (3U 
                                                      == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode))) 
                                                  | (4U 
                                                     == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__opcode)))))));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__opcode_format_valid 
            = vlSelfRef.__Vfunc_npu_opcode_engine_valid__1672__Vfuncout;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__output_handshake 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd_ready) 
           & (0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__fifo_count_q)));
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_wstrb = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q) 
                  >> 4U)))) {
        if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_wstrb 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT____VdfgExtracted_ha467d4d5__0;
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_wstrb = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_task_valid 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select_found) 
           & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_active_q)) 
              & (~ (0U != (0xfU & (- (IData)((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)))))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_task_valid 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select_found) 
           & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_active_q)) 
              & (~ (0U != (0xfU & (- (IData)((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)))))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_task_valid 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select_found) 
           & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_active_q)) 
              & (~ (0U != (0xfU & (- (IData)((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)))))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_task_valid 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select_found) 
           & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_active_q)) 
              & (~ (0U != (0xfU & (- (IData)((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)))))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_wstrb 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT____VdfgExtracted_h8e2aa811__0;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                            = (0xffff8U & ((IData)(
                                                   (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_addr 
                                                    >> 3U)) 
                                           << 3U));
                    }
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2cU]))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__src2_addr 
                                        >> 3U)) << 3U));
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_addr 
                                        >> 3U)) << 3U));
        }
    }
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr = 0U;
    __Vfunc_store_element_strb__2648__dtype = (3U & 
                                               (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                                                >> 6U));
    __Vfunc_store_element_strb__2648__byte_lane = (7U 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr));
    __Vfunc_store_element_strb__2648__result = 0U;
    __Vfunc_store_element_strb__2648__result = ((2U 
                                                 & (IData)(__Vfunc_store_element_strb__2648__dtype))
                                                 ? 
                                                (0xffU 
                                                 & ((1U 
                                                     & (IData)(__Vfunc_store_element_strb__2648__dtype))
                                                     ? 
                                                    ((IData)(3U) 
                                                     << (IData)(__Vfunc_store_element_strb__2648__byte_lane))
                                                     : 
                                                    ((IData)(0xfU) 
                                                     << (IData)(__Vfunc_store_element_strb__2648__byte_lane))))
                                                 : 
                                                ((IData)(__Vfunc_store_element_strb__2648__result) 
                                                 | (0xffU 
                                                    & ((IData)(1U) 
                                                       << (IData)(__Vfunc_store_element_strb__2648__byte_lane)))));
    __Vfunc_store_element_strb__2648__Vfuncout = __Vfunc_store_element_strb__2648__result;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT____VdfgExtracted_h20747776__0 
        = __Vfunc_store_element_strb__2648__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_wdata = 0ULL;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                            = (0xffff8U & ((IData)(
                                                   (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr 
                                                    >> 3U)) 
                                           << 3U));
                        vlSelfRef.__Vfunc_store_element_data__2534__dtype 
                            = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                                     >> 6U));
                        vlSelfRef.__Vfunc_store_element_data__2534__high_nibble 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__dst_high_nibble;
                        vlSelfRef.__Vfunc_store_element_data__2534__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr));
                        vlSelfRef.__Vfunc_store_element_data__2534__value 
                            = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__result_q);
                        vlSelfRef.__Vfunc_store_element_data__2534__old_beat 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__rmw_beat_q;
                        vlSelf->__Vfunc_store_element_data__2534__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16740914291854753292ull);
                        vlSelfRef.__Vfunc_store_element_data__2534__result 
                            = vlSelfRef.__Vfunc_store_element_data__2534__old_beat;
                        if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__2534__dtype))) {
                            vlSelfRef.__Vfunc_store_element_data__2534__result 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2534__dtype))
                                    ? (((~ (0xffffULL 
                                            << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2534__byte_lane), 3U)))) 
                                        & vlSelfRef.__Vfunc_store_element_data__2534__result) 
                                       | ((QData)((IData)(
                                                          (0xffffU 
                                                           & vlSelfRef.__Vfunc_store_element_data__2534__value))) 
                                          << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2534__byte_lane), 3U))))
                                    : (((~ (0xffffffffULL 
                                            << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2534__byte_lane), 3U)))) 
                                        & vlSelfRef.__Vfunc_store_element_data__2534__result) 
                                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2534__value)) 
                                          << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2534__byte_lane), 3U)))));
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2534__dtype))) {
                            vlSelfRef.__Vfunc_store_element_data__2534__result 
                                = (((~ (0xffULL << 
                                        (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2534__byte_lane), 3U)))) 
                                    & vlSelfRef.__Vfunc_store_element_data__2534__result) 
                                   | ((QData)((IData)(
                                                      (0xffU 
                                                       & vlSelfRef.__Vfunc_store_element_data__2534__value))) 
                                      << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2534__byte_lane), 3U))));
                        } else {
                            vlSelfRef.__Vfunc_store_element_data__2534__byte_value 
                                = (0xffU & (IData)(
                                                   (vlSelfRef.__Vfunc_store_element_data__2534__old_beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2534__byte_lane), 3U)))));
                            vlSelfRef.__Vfunc_store_element_data__2534__byte_value 
                                = ((IData)(vlSelfRef.__Vfunc_store_element_data__2534__high_nibble)
                                    ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__2534__byte_value)) 
                                       | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__2534__value 
                                                   << 4U)))
                                    : ((0xf0U & (IData)(vlSelfRef.__Vfunc_store_element_data__2534__byte_value)) 
                                       | (0xfU & vlSelfRef.__Vfunc_store_element_data__2534__value)));
                            vlSelfRef.__Vfunc_store_element_data__2534__result 
                                = (((~ (0xffULL << 
                                        (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2534__byte_lane), 3U)))) 
                                    & vlSelfRef.__Vfunc_store_element_data__2534__result) 
                                   | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2534__byte_value)) 
                                      << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2534__byte_lane), 3U))));
                        }
                        vlSelfRef.__Vfunc_store_element_data__2534__Vfuncout 
                            = vlSelfRef.__Vfunc_store_element_data__2534__result;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_wdata 
                            = vlSelfRef.__Vfunc_store_element_data__2534__Vfuncout;
                    }
                } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_addr 
                                        >> 3U)) << 3U));
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_valid_length_addr 
                                        >> 3U)) << 3U));
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_offset = 0ULL;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_offset = 0ULL;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_high_nibble = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_high_nibble = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_src_dtype 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2126__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2126__Vfuncout 
                    = ((0x24U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2126__opcode)) 
                       | (0x25U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2126__opcode)));
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2126__Vfuncout))
            ? 1U : (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU]));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype 
        = (([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2127__opcode 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2127__Vfuncout 
                    = ((0x24U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2127__opcode)) 
                       | (0x25U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2127__opcode)));
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__byte_mode__2127__Vfuncout))
            ? 1U : (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU] 
                          >> 6U)));
    if ((0x24U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q))) {
        if ((0U != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2aU] 
                    >> 0x10U))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_offset 
                = ((VL_DIV_QQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q, (QData)((IData)(
                                                                                (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2aU] 
                                                                                >> 0x10U)))) 
                    * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2bU]))) 
                   + VL_MODDIV_QQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q, (QData)((IData)(
                                                                                (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2aU] 
                                                                                >> 0x10U)))));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_offset 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q;
        }
    } else if ((0x25U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q))) {
        if ((0U != (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2aU] 
                    >> 0x10U))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_offset 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_offset 
                = ((VL_DIV_QQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q, (QData)((IData)(
                                                                                (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2aU] 
                                                                                >> 0x10U)))) 
                    * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2bU]))) 
                   + VL_MODDIV_QQQ(64, vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q, (QData)((IData)(
                                                                                (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x2aU] 
                                                                                >> 0x10U)))));
        }
    } else if ((0x23U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__opcode_q))) {
        if ((0U == (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU]))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_offset 
                = ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_row 
                    * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x18U]))) 
                   + VL_SHIFTR_QQI(64,64,32, (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_col 
                                              + (QData)((IData)(
                                                                (1U 
                                                                 & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U] 
                                                                    >> 0x10U))))), 1U));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_offset 
                = ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_col 
                    * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1eU]))) 
                   + VL_SHIFTR_QQI(64,64,32, (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_row 
                                              + (QData)((IData)(
                                                                (1U 
                                                                 & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U] 
                                                                    >> 0x18U))))), 1U));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_high_nibble 
                = (1U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_col) 
                         ^ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U] 
                            >> 0x10U)));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_high_nibble 
                = (1U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_row) 
                         ^ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U] 
                            >> 0x18U)));
        } else {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_offset 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____VdfgExtracted_h5b28d49a__0;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_offset 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____VdfgExtracted_hb6bd6506__0;
        }
    } else {
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__start_nibble 
            = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U] 
                     >> 0x10U));
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dtype 
            = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU]);
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__strides[0U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x18U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__strides[1U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x19U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__strides[2U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1aU];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__strides[3U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1bU];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__strides[4U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1cU];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__shapes[0U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x12U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__shapes[1U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x13U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__shapes[2U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x14U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__shapes[3U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x15U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__shapes[4U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x16U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value 
            = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U]);
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__linear 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q;
        for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
            vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1967559965157310570ull);
        }
        vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14929580171469925538ull);
        vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5495938929922909720ull);
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder 
            = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__linear;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes[0U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes[1U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes[2U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes[3U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes[4U] = 0ULL;
        if ((4U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__shapes[4U];
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size)) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes[4U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide);
            }
        }
        if ((3U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__shapes[3U];
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size)) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes[3U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide);
            }
        }
        if ((2U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__shapes[2U];
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size)) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes[2U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide);
            }
        }
        if ((1U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__shapes[1U];
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size)) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes[1U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide);
            }
        }
        if ((0U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__shapes[0U];
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size)) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes[0U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dimension_size_wide);
            }
        }
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result = 0ULL;
        if ((1U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result 
                = (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result 
                   + (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes
                      [0U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__strides[0U]))));
        }
        if ((2U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result 
                = (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result 
                   + (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes
                      [1U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__strides[1U]))));
        }
        if ((3U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result 
                = (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result 
                   + (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes
                      [2U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__strides[2U]))));
        }
        if ((4U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result 
                = (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result 
                   + (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes
                      [3U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__strides[3U]))));
        }
        if (((1U <= (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value)) 
             & (5U >= (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value)))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result 
                = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dtype))
                    ? (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result 
                       + VL_SHIFTR_QQI(64,64,32, ((
                                                   (4U 
                                                    >= 
                                                    (7U 
                                                     & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value) 
                                                        - (IData)(1U))))
                                                    ? 
                                                   vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes
                                                   [
                                                   (7U 
                                                    & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value) 
                                                       - (IData)(1U)))]
                                                    : 0ULL) 
                                                  + (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__start_nibble))), 1U))
                    : (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result 
                       + (((4U >= (7U & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value) 
                                         - (IData)(1U))))
                            ? vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__indexes
                           [(7U & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__rank_value) 
                                   - (IData)(1U)))]
                            : 0ULL) * VL_EXTEND_QI(64,3, 
                                                   ([&]() {
                                    vlSelfRef.__Vfunc_dtype_bytes__2129__dtype 
                                        = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__dtype;
                                    vlSelfRef.__Vfunc_dtype_bytes__2129__Vfuncout 
                                        = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2129__dtype))
                                            ? 1U : 
                                           ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2129__dtype))
                                             ? 4U : 
                                            ((3U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2129__dtype))
                                              ? 2U : 0U)));
                                }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2129__Vfuncout))))));
        }
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__Vfuncout 
            = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__result;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_offset 
            = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2128__Vfuncout;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__start_nibble 
            = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U] 
                     >> 0x18U));
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dtype 
            = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU] 
                     >> 6U));
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__strides[0U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1eU];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__strides[1U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1fU];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__strides[2U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x20U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__strides[3U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x21U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__strides[4U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x22U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__shapes[0U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x12U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__shapes[1U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x13U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__shapes[2U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x14U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__shapes[3U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x15U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__shapes[4U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x16U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value 
            = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U]);
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__linear 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q;
        for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
            vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3959767686077745240ull);
        }
        vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12036977264028986406ull);
        vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14280617550689221393ull);
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder 
            = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__linear;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes[0U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes[1U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes[2U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes[3U] = 0ULL;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes[4U] = 0ULL;
        if ((4U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__shapes[4U];
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size)) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes[4U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide);
            }
        }
        if ((3U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__shapes[3U];
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size)) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes[3U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide);
            }
        }
        if ((2U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__shapes[2U];
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size)) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes[2U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide);
            }
        }
        if ((1U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__shapes[1U];
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size)) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes[1U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide);
            }
        }
        if ((0U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size 
                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__shapes[0U];
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide 
                = (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size));
            if ((0U != vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size)) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1 
                    = VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes[0U] 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____Vlvbound_h95b2141a__1;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder 
                    = VL_DIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__remainder, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dimension_size_wide);
            }
        }
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result = 0ULL;
        if ((1U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result 
                = (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result 
                   + (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes
                      [0U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__strides[0U]))));
        }
        if ((2U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result 
                = (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result 
                   + (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes
                      [1U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__strides[1U]))));
        }
        if ((3U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result 
                = (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result 
                   + (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes
                      [2U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__strides[2U]))));
        }
        if ((4U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result 
                = (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result 
                   + (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes
                      [3U] * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__strides[3U]))));
        }
        if (((1U <= (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value)) 
             & (5U >= (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value)))) {
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result 
                = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dtype))
                    ? (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result 
                       + VL_SHIFTR_QQI(64,64,32, ((
                                                   (4U 
                                                    >= 
                                                    (7U 
                                                     & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value) 
                                                        - (IData)(1U))))
                                                    ? 
                                                   vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes
                                                   [
                                                   (7U 
                                                    & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value) 
                                                       - (IData)(1U)))]
                                                    : 0ULL) 
                                                  + (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__start_nibble))), 1U))
                    : (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result 
                       + (((4U >= (7U & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value) 
                                         - (IData)(1U))))
                            ? vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__indexes
                           [(7U & ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__rank_value) 
                                   - (IData)(1U)))]
                            : 0ULL) * VL_EXTEND_QI(64,3, 
                                                   ([&]() {
                                    vlSelfRef.__Vfunc_dtype_bytes__2131__dtype 
                                        = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__dtype;
                                    vlSelfRef.__Vfunc_dtype_bytes__2131__Vfuncout 
                                        = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2131__dtype))
                                            ? 1U : 
                                           ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2131__dtype))
                                             ? 4U : 
                                            ((3U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2131__dtype))
                                              ? 2U : 0U)));
                                }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2131__Vfuncout))))));
        }
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__Vfuncout 
            = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__result;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_offset 
            = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_byte_offset__2130__Vfuncout;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__dtype 
            = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU]);
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__start_nibble 
            = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U] 
                     >> 0x10U));
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__shapes[0U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x12U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__shapes[1U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x13U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__shapes[2U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x14U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__shapes[3U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x15U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__shapes[4U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x16U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__rank_value 
            = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U]);
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__linear 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q;
        vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__inner_size = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16573839822131769614ull);
        {
            if ((((0U != (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__dtype)) 
                  | (0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__rank_value))) 
                 | (5U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__rank_value)))) {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__Vfuncout = 0U;
                goto __Vlabel1;
            }
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__inner_size 
                = ((0x9fU >= (0xffU & VL_SHIFTL_III(8,32,32, 
                                                    ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__rank_value) 
                                                     - (IData)(1U)), 5U)))
                    ? (((0U == (0x1fU & VL_SHIFTL_III(8,32,32, 
                                                      ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__rank_value) 
                                                       - (IData)(1U)), 5U)))
                         ? 0U : (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__shapes[
                                 (((IData)(0x1fU) + 
                                   (0xffU & VL_SHIFTL_III(8,32,32, 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__rank_value) 
                                                           - (IData)(1U)), 5U))) 
                                  >> 5U)] << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(8,32,32, 
                                                                 ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__rank_value) 
                                                                  - (IData)(1U)), 5U))))) 
                       | (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__shapes[
                          (7U & (VL_SHIFTL_III(8,32,32, 
                                               ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__rank_value) 
                                                - (IData)(1U)), 5U) 
                                 >> 5U))] >> (0x1fU 
                                              & VL_SHIFTL_III(8,32,32, 
                                                              ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__rank_value) 
                                                               - (IData)(1U)), 5U))))
                    : 0U);
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__Vfuncout 
                = (((0U != vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__inner_size) 
                    & (IData)(VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__linear, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__inner_size))))) 
                   ^ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__start_nibble));
            __Vlabel1: ;
        }
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_high_nibble 
            = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2132__Vfuncout;
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__dtype 
            = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU] 
                     >> 6U));
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__start_nibble 
            = (1U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x11U] 
                     >> 0x18U));
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__shapes[0U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x12U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__shapes[1U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x13U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__shapes[2U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x14U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__shapes[3U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x15U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__shapes[4U] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x16U];
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__rank_value 
            = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U]);
        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__linear 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__linear_index_q;
        vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__inner_size = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5953985802466206218ull);
        {
            if ((((0U != (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__dtype)) 
                  | (0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__rank_value))) 
                 | (5U < (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__rank_value)))) {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__Vfuncout = 0U;
                goto __Vlabel2;
            }
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__inner_size 
                = ((0x9fU >= (0xffU & VL_SHIFTL_III(8,32,32, 
                                                    ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__rank_value) 
                                                     - (IData)(1U)), 5U)))
                    ? (((0U == (0x1fU & VL_SHIFTL_III(8,32,32, 
                                                      ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__rank_value) 
                                                       - (IData)(1U)), 5U)))
                         ? 0U : (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__shapes[
                                 (((IData)(0x1fU) + 
                                   (0xffU & VL_SHIFTL_III(8,32,32, 
                                                          ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__rank_value) 
                                                           - (IData)(1U)), 5U))) 
                                  >> 5U)] << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_SHIFTL_III(8,32,32, 
                                                                 ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__rank_value) 
                                                                  - (IData)(1U)), 5U))))) 
                       | (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__shapes[
                          (7U & (VL_SHIFTL_III(8,32,32, 
                                               ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__rank_value) 
                                                - (IData)(1U)), 5U) 
                                 >> 5U))] >> (0x1fU 
                                              & VL_SHIFTL_III(8,32,32, 
                                                              ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__rank_value) 
                                                               - (IData)(1U)), 5U))))
                    : 0U);
            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__Vfuncout 
                = (((0U != vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__inner_size) 
                    & (IData)(VL_MODDIV_QQQ(64, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__linear, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__inner_size))))) 
                   ^ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__start_nibble));
            __Vlabel2: ;
        }
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_high_nibble 
            = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__nd_high_nibble__2133__Vfuncout;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
         >> 0x1fU)) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_opcode 
            = (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_opcode));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_engine 
            = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_engine));
    } else {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_opcode 
            = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U]);
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_engine 
            = (0xfU & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U] 
                        << 4U) | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U] 
                                  >> 0x1cU)));
    }
    __Vfunc_fp32_div__2403__denominator_value = tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns_fp;
    __Vfunc_fp32_div__2403__numerator_value = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sum_q;
    vlSelf->__Vfunc_fp32_div__2403__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11319961223764941848ull);
    vlSelf->__Vfunc_fp32_div__2403__numerator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7903510302816823341ull);
    vlSelf->__Vfunc_fp32_div__2403__denominator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 947473949349904181ull);
    vlSelf->__Vfunc_fp32_div__2403__scaled_numerator = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 17160273528046764601ull);
    vlSelf->__Vfunc_fp32_div__2403__denominator_wide = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 8890257964586076161ull);
    vlSelf->__Vfunc_fp32_div__2403__division_remainder = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7820478138959991858ull);
    vlSelf->__Vfunc_fp32_div__2403__quotient_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 15700317347619931607ull);
    vlSelf->__Vfunc_fp32_div__2403__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 395230331393304941ull);
    vlSelf->__Vfunc_fp32_div__2403__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5153225482426108820ull);
    vlSelf->__Vfunc_fp32_div__2403__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2811815246184007996ull);
    vlSelf->__Vfunc_fp32_div__2403__numerator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10524930777247244163ull);
    vlSelf->__Vfunc_fp32_div__2403__denominator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1089531268168278854ull);
    vlSelf->__Vfunc_fp32_div__2403__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5136893086831287559ull);
    __Vfunc_fp32_div__2403__normalize_count = 0;
    {
        if ((((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__2404__bits 
                                    = __Vfunc_fp32_div__2403__numerator_value;
                                __Vfunc_fp32_is_nan__2404__unused_sign = 0;
                                __Vfunc_fp32_is_nan__2404__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__2404__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__2404__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2404__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__2404__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2404__Vfuncout)) 
               | ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__2405__bits 
                                    = __Vfunc_fp32_div__2403__denominator_value;
                                __Vfunc_fp32_is_nan__2405__unused_sign = 0;
                                __Vfunc_fp32_is_nan__2405__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__2405__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__2405__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2405__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__2405__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2405__Vfuncout))) 
              | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2406__bits 
                                    = __Vfunc_fp32_div__2403__numerator_value;
                                __Vfunc_fp32_is_zero__2406__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2406__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2406__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2406__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2406__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2406__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2407__bits 
                                    = __Vfunc_fp32_div__2403__denominator_value;
                                __Vfunc_fp32_is_zero__2407__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2407__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2407__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2407__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2407__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2407__Vfuncout)))) 
             | (([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2408__bits 
                                = __Vfunc_fp32_div__2403__numerator_value;
                            __Vfunc_fp32_is_inf__2408__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2408__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2408__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2408__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2408__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2408__Vfuncout)) 
                & ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2409__bits 
                                = __Vfunc_fp32_div__2403__denominator_value;
                            __Vfunc_fp32_is_inf__2409__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2409__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2409__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2409__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2409__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2409__Vfuncout))))) {
            vlSelfRef.__Vfunc_fp32_div__2403__Vfuncout = 0x7fc00000U;
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_div__2403__result_sign 
            = ((__Vfunc_fp32_div__2403__numerator_value 
                ^ __Vfunc_fp32_div__2403__denominator_value) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2410__bits 
                            = __Vfunc_fp32_div__2403__numerator_value;
                        __Vfunc_fp32_is_inf__2410__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2410__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2410__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2410__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2410__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2410__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2411__bits 
                            = __Vfunc_fp32_div__2403__denominator_value;
                        __Vfunc_fp32_is_zero__2411__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2411__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2411__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2411__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2411__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2411__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__2403__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2412__bits 
                            = __Vfunc_fp32_div__2403__numerator_value;
                        __Vfunc_fp32_is_zero__2412__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2412__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2412__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2412__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2412__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2412__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2413__bits 
                            = __Vfunc_fp32_div__2403__denominator_value;
                        __Vfunc_fp32_is_inf__2413__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2413__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2413__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2413__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2413__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2413__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__2403__result_sign) 
                   << 0x1fU);
            goto __Vlabel3;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__2403__numerator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__2403__numerator_value);
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__2403__numerator_value));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__2403__numerator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__2403__denominator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__2403__denominator_value);
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__2403__denominator_value));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__2403__denominator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_div__2403__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_div__2403__normalize_count = 1U;
        __Vfunc_fp32_div__2403__normalize_count = 2U;
        __Vfunc_fp32_div__2403__normalize_count = 3U;
        __Vfunc_fp32_div__2403__normalize_count = 4U;
        __Vfunc_fp32_div__2403__normalize_count = 5U;
        __Vfunc_fp32_div__2403__normalize_count = 6U;
        __Vfunc_fp32_div__2403__normalize_count = 7U;
        __Vfunc_fp32_div__2403__normalize_count = 8U;
        __Vfunc_fp32_div__2403__normalize_count = 9U;
        __Vfunc_fp32_div__2403__normalize_count = 0xaU;
        __Vfunc_fp32_div__2403__normalize_count = 0xbU;
        __Vfunc_fp32_div__2403__normalize_count = 0xcU;
        __Vfunc_fp32_div__2403__normalize_count = 0xdU;
        __Vfunc_fp32_div__2403__normalize_count = 0xeU;
        __Vfunc_fp32_div__2403__normalize_count = 0xfU;
        __Vfunc_fp32_div__2403__normalize_count = 0x10U;
        __Vfunc_fp32_div__2403__normalize_count = 0x11U;
        __Vfunc_fp32_div__2403__normalize_count = 0x12U;
        __Vfunc_fp32_div__2403__normalize_count = 0x13U;
        __Vfunc_fp32_div__2403__normalize_count = 0x14U;
        __Vfunc_fp32_div__2403__normalize_count = 0x15U;
        __Vfunc_fp32_div__2403__normalize_count = 0x16U;
        __Vfunc_fp32_div__2403__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_div__2403__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_div__2403__numerator_unbiased 
               - vlSelfRef.__Vfunc_fp32_div__2403__denominator_unbiased);
        vlSelfRef.__Vfunc_fp32_div__2403__scaled_numerator 
            = (0xffffffffffffffULL & VL_SHIFTL_QQI(56,56,32, (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__2403__numerator_mant)), 0x1aU));
        vlSelfRef.__Vfunc_fp32_div__2403__denominator_wide 
            = (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__2403__denominator_mant));
        vlSelfRef.__Vfunc_fp32_div__2403__quotient_ext 
            = (0xfffffffU & (IData)((0xffffffffffffffULL 
                                     & VL_DIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__2403__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__2403__denominator_wide))));
        vlSelfRef.__Vfunc_fp32_div__2403__division_remainder 
            = (0xffffffU & (IData)((0xffffffffffffffULL 
                                    & VL_MODDIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__2403__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__2403__denominator_wide))));
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2403__quotient_ext 
                      >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_div__2403__quotient_ext 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_div__2403__quotient_ext, 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__result_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2403__result_unbiased 
                   - (IData)(1U));
        }
        if ((0U != vlSelfRef.__Vfunc_fp32_div__2403__division_remainder)) {
            vlSelfRef.__Vfunc_fp32_div__2403__quotient_ext 
                = (1U | vlSelfRef.__Vfunc_fp32_div__2403__quotient_ext);
        }
        vlSelfRef.__Vfunc_fp32_div__2403__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__2403__quotient_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_div__2403__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_div__2403__quotient_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_div__2403__quotient_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_div__2403__quotient_ext) 
                                | vlSelfRef.__Vfunc_fp32_div__2403__mantissa)));
        vlSelfRef.__Vfunc_fp32_div__2403__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_div__2403__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_div__2403__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_div__2403__rounded)) {
            vlSelfRef.__Vfunc_fp32_div__2403__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__2403__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_div__2403__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_div__2403__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_div__2403__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_div__2403__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_div__2403__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__2403__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__2403__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_div__2403__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__2403__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__2403__result_sign) 
                   << 0x1fU);
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_div__2403__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_div__2403__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_div__2403__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_div__2403__mantissa)));
        __Vlabel3: ;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean 
        = vlSelfRef.__Vfunc_fp32_div__2403__Vfuncout;
    __Vfunc_fp32_div__2414__denominator_value = tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns_fp;
    __Vfunc_fp32_div__2414__numerator_value = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_sumsq_q;
    vlSelf->__Vfunc_fp32_div__2414__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4845763592987698016ull);
    vlSelf->__Vfunc_fp32_div__2414__numerator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8374175320344933838ull);
    vlSelf->__Vfunc_fp32_div__2414__denominator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6864514358711589130ull);
    vlSelf->__Vfunc_fp32_div__2414__scaled_numerator = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 13859476647730197375ull);
    vlSelf->__Vfunc_fp32_div__2414__denominator_wide = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 18059237327414226130ull);
    vlSelf->__Vfunc_fp32_div__2414__division_remainder = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13366775841241982204ull);
    vlSelf->__Vfunc_fp32_div__2414__quotient_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 7764144349383983015ull);
    vlSelf->__Vfunc_fp32_div__2414__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 14819226676769283600ull);
    vlSelf->__Vfunc_fp32_div__2414__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 713867977264916658ull);
    vlSelf->__Vfunc_fp32_div__2414__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15491229577647280641ull);
    vlSelf->__Vfunc_fp32_div__2414__numerator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6222976378719253387ull);
    vlSelf->__Vfunc_fp32_div__2414__denominator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5497439873914886254ull);
    vlSelf->__Vfunc_fp32_div__2414__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15341641008795337237ull);
    __Vfunc_fp32_div__2414__normalize_count = 0;
    {
        if ((((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__2415__bits 
                                    = __Vfunc_fp32_div__2414__numerator_value;
                                __Vfunc_fp32_is_nan__2415__unused_sign = 0;
                                __Vfunc_fp32_is_nan__2415__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__2415__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__2415__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2415__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__2415__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2415__Vfuncout)) 
               | ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__2416__bits 
                                    = __Vfunc_fp32_div__2414__denominator_value;
                                __Vfunc_fp32_is_nan__2416__unused_sign = 0;
                                __Vfunc_fp32_is_nan__2416__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__2416__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__2416__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2416__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__2416__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2416__Vfuncout))) 
              | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2417__bits 
                                    = __Vfunc_fp32_div__2414__numerator_value;
                                __Vfunc_fp32_is_zero__2417__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2417__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2417__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2417__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2417__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2417__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2418__bits 
                                    = __Vfunc_fp32_div__2414__denominator_value;
                                __Vfunc_fp32_is_zero__2418__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2418__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2418__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2418__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2418__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2418__Vfuncout)))) 
             | (([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2419__bits 
                                = __Vfunc_fp32_div__2414__numerator_value;
                            __Vfunc_fp32_is_inf__2419__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2419__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2419__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2419__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2419__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2419__Vfuncout)) 
                & ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2420__bits 
                                = __Vfunc_fp32_div__2414__denominator_value;
                            __Vfunc_fp32_is_inf__2420__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2420__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2420__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2420__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2420__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2420__Vfuncout))))) {
            vlSelfRef.__Vfunc_fp32_div__2414__Vfuncout = 0x7fc00000U;
            goto __Vlabel4;
        }
        vlSelfRef.__Vfunc_fp32_div__2414__result_sign 
            = ((__Vfunc_fp32_div__2414__numerator_value 
                ^ __Vfunc_fp32_div__2414__denominator_value) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2421__bits 
                            = __Vfunc_fp32_div__2414__numerator_value;
                        __Vfunc_fp32_is_inf__2421__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2421__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2421__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2421__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2421__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2421__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2422__bits 
                            = __Vfunc_fp32_div__2414__denominator_value;
                        __Vfunc_fp32_is_zero__2422__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2422__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2422__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2422__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2422__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2422__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__2414__result_sign) 
                                  << 0x1fU));
            goto __Vlabel4;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2423__bits 
                            = __Vfunc_fp32_div__2414__numerator_value;
                        __Vfunc_fp32_is_zero__2423__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2423__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2423__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2423__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2423__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2423__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2424__bits 
                            = __Vfunc_fp32_div__2414__denominator_value;
                        __Vfunc_fp32_is_inf__2424__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2424__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2424__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2424__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2424__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2424__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__2414__result_sign) 
                   << 0x1fU);
            goto __Vlabel4;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__2414__numerator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__2414__numerator_value);
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__2414__numerator_value));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__2414__numerator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__2414__denominator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__2414__denominator_value);
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__2414__denominator_value));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__2414__denominator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_div__2414__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_div__2414__normalize_count = 1U;
        __Vfunc_fp32_div__2414__normalize_count = 2U;
        __Vfunc_fp32_div__2414__normalize_count = 3U;
        __Vfunc_fp32_div__2414__normalize_count = 4U;
        __Vfunc_fp32_div__2414__normalize_count = 5U;
        __Vfunc_fp32_div__2414__normalize_count = 6U;
        __Vfunc_fp32_div__2414__normalize_count = 7U;
        __Vfunc_fp32_div__2414__normalize_count = 8U;
        __Vfunc_fp32_div__2414__normalize_count = 9U;
        __Vfunc_fp32_div__2414__normalize_count = 0xaU;
        __Vfunc_fp32_div__2414__normalize_count = 0xbU;
        __Vfunc_fp32_div__2414__normalize_count = 0xcU;
        __Vfunc_fp32_div__2414__normalize_count = 0xdU;
        __Vfunc_fp32_div__2414__normalize_count = 0xeU;
        __Vfunc_fp32_div__2414__normalize_count = 0xfU;
        __Vfunc_fp32_div__2414__normalize_count = 0x10U;
        __Vfunc_fp32_div__2414__normalize_count = 0x11U;
        __Vfunc_fp32_div__2414__normalize_count = 0x12U;
        __Vfunc_fp32_div__2414__normalize_count = 0x13U;
        __Vfunc_fp32_div__2414__normalize_count = 0x14U;
        __Vfunc_fp32_div__2414__normalize_count = 0x15U;
        __Vfunc_fp32_div__2414__normalize_count = 0x16U;
        __Vfunc_fp32_div__2414__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_div__2414__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_div__2414__numerator_unbiased 
               - vlSelfRef.__Vfunc_fp32_div__2414__denominator_unbiased);
        vlSelfRef.__Vfunc_fp32_div__2414__scaled_numerator 
            = (0xffffffffffffffULL & VL_SHIFTL_QQI(56,56,32, (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__2414__numerator_mant)), 0x1aU));
        vlSelfRef.__Vfunc_fp32_div__2414__denominator_wide 
            = (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__2414__denominator_mant));
        vlSelfRef.__Vfunc_fp32_div__2414__quotient_ext 
            = (0xfffffffU & (IData)((0xffffffffffffffULL 
                                     & VL_DIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__2414__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__2414__denominator_wide))));
        vlSelfRef.__Vfunc_fp32_div__2414__division_remainder 
            = (0xffffffU & (IData)((0xffffffffffffffULL 
                                    & VL_MODDIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__2414__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__2414__denominator_wide))));
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2414__quotient_ext 
                      >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_div__2414__quotient_ext 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_div__2414__quotient_ext, 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__result_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2414__result_unbiased 
                   - (IData)(1U));
        }
        if ((0U != vlSelfRef.__Vfunc_fp32_div__2414__division_remainder)) {
            vlSelfRef.__Vfunc_fp32_div__2414__quotient_ext 
                = (1U | vlSelfRef.__Vfunc_fp32_div__2414__quotient_ext);
        }
        vlSelfRef.__Vfunc_fp32_div__2414__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__2414__quotient_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_div__2414__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_div__2414__quotient_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_div__2414__quotient_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_div__2414__quotient_ext) 
                                | vlSelfRef.__Vfunc_fp32_div__2414__mantissa)));
        vlSelfRef.__Vfunc_fp32_div__2414__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_div__2414__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_div__2414__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_div__2414__rounded)) {
            vlSelfRef.__Vfunc_fp32_div__2414__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__2414__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_div__2414__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_div__2414__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_div__2414__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_div__2414__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_div__2414__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__2414__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__2414__result_sign) 
                                  << 0x1fU));
            goto __Vlabel4;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_div__2414__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__2414__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__2414__result_sign) 
                   << 0x1fU);
            goto __Vlabel4;
        }
        vlSelfRef.__Vfunc_fp32_div__2414__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_div__2414__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_div__2414__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_div__2414__mantissa)));
        __Vlabel4: ;
    }
}
