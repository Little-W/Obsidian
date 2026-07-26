// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core___024root.h"

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__18(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__18\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__u_f2i__DOT__scaled_value;
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__u_f2i__DOT__scaled_value = 0;
    IData/*31:0*/ __Vfunc_fp32_to_int_round__4636__value;
    __Vfunc_fp32_to_int_round__4636__value = 0;
    CData/*1:0*/ __Vfunc_fp32_to_int_round__4636__rounding;
    __Vfunc_fp32_to_int_round__4636__rounding = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__4637__unused_sign;
    __Vfunc_fp32_is_nan__4637__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__4638__unused_sign;
    __Vfunc_fp32_is_inf__4638__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__4639__unused_sign;
    __Vfunc_fp32_is_zero__4639__unused_sign = 0;
    // Body
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__u_f2i__DOT__scaled_value 
        = vlSelfRef.__Vfunc_fp32_div__4625__Vfuncout;
    __Vfunc_fp32_to_int_round__4636__rounding = (3U 
                                                 & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                                                    >> 0xaU));
    __Vfunc_fp32_to_int_round__4636__value = tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__u_f2i__DOT__scaled_value;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_to_int_round__4636__sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4104612870543288353ull);
    vlSelf->__Vfunc_fp32_to_int_round__4636__significand = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15192348796758442141ull);
    vlSelf->__Vfunc_fp32_to_int_round__4636__magnitude = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12203030940357910666ull);
    vlSelf->__Vfunc_fp32_to_int_round__4636__quotient = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5701955400878450331ull);
    vlSelf->__Vfunc_fp32_to_int_round__4636__remainder = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 18364113763986392581ull);
    vlSelf->__Vfunc_fp32_to_int_round__4636__remainder_mask = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12517350126809440533ull);
    vlSelf->__Vfunc_fp32_to_int_round__4636__halfway = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 572523878381028206ull);
    vlSelf->__Vfunc_fp32_to_int_round__4636__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5846335914632017286ull);
    vlSelf->__Vfunc_fp32_to_int_round__4636__unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6489798896247337426ull);
    vlSelf->__Vfunc_fp32_to_int_round__4636__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13374166324543543725ull);
    {
        vlSelfRef.__Vfunc_fp32_to_int_round__4636__sign 
            = (__Vfunc_fp32_to_int_round__4636__value 
               >> 0x1fU);
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_nan__4637__bits 
                        = __Vfunc_fp32_to_int_round__4636__value;
                    __Vfunc_fp32_is_nan__4637__unused_sign = 0;
                    __Vfunc_fp32_is_nan__4637__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_nan__4637__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_nan__4637__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & vlSelfRef.__Vfunc_fp32_is_nan__4637__bits)) 
                                   & (0U != (0x7fffffU 
                                             & vlSelfRef.__Vfunc_fp32_is_nan__4637__bits))));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__4637__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_to_int_round__4636__Vfuncout = 0ULL;
            goto __Vlabel0;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_inf__4638__bits 
                        = __Vfunc_fp32_to_int_round__4636__value;
                    __Vfunc_fp32_is_inf__4638__unused_sign = 0;
                    __Vfunc_fp32_is_inf__4638__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_inf__4638__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_inf__4638__Vfuncout 
                        = (IData)((0x7f800000U == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__4638__bits)));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__4638__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_to_int_round__4636__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__4636__sign)
                    ? 0x8000000000000000ULL : 0x7fffffffffffffffULL);
            goto __Vlabel0;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__4639__bits 
                        = __Vfunc_fp32_to_int_round__4636__value;
                    __Vfunc_fp32_is_zero__4639__unused_sign = 0;
                    __Vfunc_fp32_is_zero__4639__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__4639__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__4639__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__4639__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__4639__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_to_int_round__4636__Vfuncout = 0ULL;
            goto __Vlabel0;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_to_int_round__4636__value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_to_int_round__4636__significand 
                = (0x7fffffU & __Vfunc_fp32_to_int_round__4636__value);
            vlSelfRef.__Vfunc_fp32_to_int_round__4636__unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_to_int_round__4636__significand 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_to_int_round__4636__value));
            vlSelfRef.__Vfunc_fp32_to_int_round__4636__unbiased 
                = ((0xffU & (__Vfunc_fp32_to_int_round__4636__value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        vlSelfRef.__Vfunc_fp32_to_int_round__4636__quotient = 0ULL;
        vlSelfRef.__Vfunc_fp32_to_int_round__4636__remainder = 0ULL;
        vlSelfRef.__Vfunc_fp32_to_int_round__4636__halfway = 0ULL;
        if (VL_LTES_III(32, 0x3fU, vlSelfRef.__Vfunc_fp32_to_int_round__4636__unbiased)) {
            vlSelfRef.__Vfunc_fp32_to_int_round__4636__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__4636__sign)
                    ? 0x8000000000000000ULL : 0x7fffffffffffffffULL);
            goto __Vlabel0;
        }
        if (VL_LTES_III(32, 0x17U, vlSelfRef.__Vfunc_fp32_to_int_round__4636__unbiased)) {
            vlSelfRef.__Vfunc_fp32_to_int_round__4636__quotient 
                = VL_SHIFTL_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__4636__significand)), 
                                (vlSelfRef.__Vfunc_fp32_to_int_round__4636__unbiased 
                                 - (IData)(0x17U)));
        } else {
            vlSelfRef.__Vfunc_fp32_to_int_round__4636__shift_amount 
                = ((IData)(0x17U) - vlSelfRef.__Vfunc_fp32_to_int_round__4636__unbiased);
            if (VL_LTES_III(32, 0x40U, vlSelfRef.__Vfunc_fp32_to_int_round__4636__shift_amount)) {
                vlSelfRef.__Vfunc_fp32_to_int_round__4636__quotient = 0ULL;
                vlSelfRef.__Vfunc_fp32_to_int_round__4636__remainder 
                    = (QData)((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__4636__significand));
                vlSelfRef.__Vfunc_fp32_to_int_round__4636__halfway = 0xffffffffffffffffULL;
            } else {
                vlSelfRef.__Vfunc_fp32_to_int_round__4636__quotient 
                    = VL_SHIFTR_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__4636__significand)), vlSelfRef.__Vfunc_fp32_to_int_round__4636__shift_amount);
                vlSelfRef.__Vfunc_fp32_to_int_round__4636__remainder_mask 
                    = (VL_SHIFTL_QQI(64,64,32, 1ULL, vlSelfRef.__Vfunc_fp32_to_int_round__4636__shift_amount) 
                       - 1ULL);
                vlSelfRef.__Vfunc_fp32_to_int_round__4636__remainder 
                    = ((QData)((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__4636__significand)) 
                       & vlSelfRef.__Vfunc_fp32_to_int_round__4636__remainder_mask);
                vlSelfRef.__Vfunc_fp32_to_int_round__4636__halfway 
                    = VL_SHIFTL_QQI(64,64,32, 1ULL, 
                                    (vlSelfRef.__Vfunc_fp32_to_int_round__4636__shift_amount 
                                     - (IData)(1U)));
            }
        }
        vlSelfRef.__Vfunc_fp32_to_int_round__4636__increment = 0U;
        vlSelfRef.__Vfunc_fp32_to_int_round__4636__increment 
            = ((0U == (IData)(__Vfunc_fp32_to_int_round__4636__rounding))
                ? ((vlSelfRef.__Vfunc_fp32_to_int_round__4636__remainder 
                    > vlSelfRef.__Vfunc_fp32_to_int_round__4636__halfway) 
                   | ((vlSelfRef.__Vfunc_fp32_to_int_round__4636__remainder 
                       == vlSelfRef.__Vfunc_fp32_to_int_round__4636__halfway) 
                      & (IData)(vlSelfRef.__Vfunc_fp32_to_int_round__4636__quotient)))
                : ((2U == (IData)(__Vfunc_fp32_to_int_round__4636__rounding))
                    ? ((~ (IData)(vlSelfRef.__Vfunc_fp32_to_int_round__4636__sign)) 
                       & (0ULL != vlSelfRef.__Vfunc_fp32_to_int_round__4636__remainder))
                    : ((3U == (IData)(__Vfunc_fp32_to_int_round__4636__rounding)) 
                       && ((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__4636__sign) 
                           & (0ULL != vlSelfRef.__Vfunc_fp32_to_int_round__4636__remainder)))));
        vlSelfRef.__Vfunc_fp32_to_int_round__4636__magnitude 
            = (vlSelfRef.__Vfunc_fp32_to_int_round__4636__quotient 
               + (QData)((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__4636__increment)));
        if (vlSelfRef.__Vfunc_fp32_to_int_round__4636__sign) {
            if ((0x8000000000000000ULL <= vlSelfRef.__Vfunc_fp32_to_int_round__4636__magnitude)) {
                vlSelfRef.__Vfunc_fp32_to_int_round__4636__Vfuncout = 0x8000000000000000ULL;
                goto __Vlabel0;
            }
            vlSelfRef.__Vfunc_fp32_to_int_round__4636__Vfuncout 
                = (1ULL + (~ vlSelfRef.__Vfunc_fp32_to_int_round__4636__magnitude));
            goto __Vlabel0;
        }
        if ((0x7fffffffffffffffULL < vlSelfRef.__Vfunc_fp32_to_int_round__4636__magnitude)) {
            vlSelfRef.__Vfunc_fp32_to_int_round__4636__Vfuncout = 0x7fffffffffffffffULL;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_to_int_round__4636__Vfuncout 
            = vlSelfRef.__Vfunc_fp32_to_int_round__4636__magnitude;
        __Vlabel0: ;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__f2i_result 
        = vlSelfRef.__Vfunc_fp32_to_int_round__4636__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__f2i_exceptional 
        = (([&]() {
                vlSelfRef.__Vfunc_fp32_is_nan__4640__bits 
                    = tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__u_f2i__DOT__scaled_value;
                vlSelfRef.__Vfunc_fp32_is_nan__4640__Vfuncout 
                    = (IData)(((0x7f800000U == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__4640__bits)) 
                               & (0U != (0x7fffffU 
                                         & vlSelfRef.__Vfunc_fp32_is_nan__4640__bits))));
            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__4640__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_fp32_is_inf__4641__bits 
                    = tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__u_f2i__DOT__scaled_value;
                vlSelfRef.__Vfunc_fp32_is_inf__4641__Vfuncout 
                    = (IData)((0x7f800000U == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__4641__bits)));
            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__4641__Vfuncout)));
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_comb__TOP__2(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_comb__TOP__2\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_requested 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_soft_reset_req_q) 
           | (IData)(vlSelfRef.tb_npu_single_core__DOT__soft_reset_req_i));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_quiesce 
        = ((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)) 
           | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q) 
              | (IData)(vlSelfRef.tb_npu_single_core__DOT__power_down_req_i)));
    vlSelfRef.tb_npu_single_core__DOT__accept_new_cmd_o 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__start_q) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__power_down_req_i)) 
                 & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q)))));
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_comb__TOP__4(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_comb__TOP__4\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__unnamedblk1__DOT__slot;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__unnamedblk1__DOT__slot = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__unnamedblk1__DOT__slot;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__unnamedblk1__DOT__slot = 0;
    // Body
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
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
         >> 0x1fU)) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_opcode 
            = (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_opcode));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_engine 
            = (0xfU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_engine));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____VdfgExtracted_hf6182e41__0 
            = (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_engine));
    } else {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_opcode 
            = (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U]);
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_engine 
            = (0xfU & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U] 
                        << 4U) | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U] 
                                  >> 0x1cU)));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____VdfgExtracted_hf6182e41__0 = 0U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_is_inline_rearm 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____VdfgExtracted_hf6182e41__0) 
           & (2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_opcode)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0_resolved 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1_resolved 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal;
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
         >> 0x1fU)) {
        if (((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0)))
                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0)));
        }
        if (((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1)))
                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1)));
        }
        if (((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)) 
             & (0xffU > (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved 
                = ((((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)))
                      ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                     [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))]
                      : 0U) << 8U) | (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)));
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_resources_valid = 1U;
    if ((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0))) {
        if ((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0))) 
              | (0U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0)))
                         ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                        [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0))]
                         : 0U))) | ((~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
                                        >> 0x1fU)) 
                                    & (((0xfeU >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0)))
                                         ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                                        [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0))]
                                         : 0U) != (0xfU 
                                                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0) 
                                                      >> 8U)))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_resources_valid = 0U;
        }
    }
    if ((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))) {
        if ((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))) 
              | (0U == ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1)))
                         ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                        [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))]
                         : 0U))) | ((~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
                                        >> 0x1fU)) 
                                    & (((0xfeU >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1)))
                                         ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                                        [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))]
                                         : 0U) != (0xfU 
                                                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1) 
                                                      >> 8U)))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_resources_valid = 0U;
        }
    }
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_is_inline_rearm) {
        if ((1U & ((((((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0)) 
                       | (0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1))) 
                      | (0xfffU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))) 
                     | (0xffU <= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)))) 
                    | (~ ((2U == ((0xfeU >= (0xffU 
                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)))
                                   ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                  [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))]
                                   : 0U)) | (3U == 
                                             ((0xfeU 
                                               >= (0xffU 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)))
                                               ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                                              [(0xffU 
                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))]
                                               : 0U))))) 
                   | ([&]() {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref 
                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved;
                            __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__unnamedblk1__DOT__slot = 0;
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 0U;
                            if ((0xfffU != (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref))) {
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [0U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [0U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [0U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [0U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [0U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [0U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__unnamedblk1__DOT__slot = 8U;
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [1U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [1U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [1U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [1U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [1U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [1U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [2U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [2U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [2U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [2U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [2U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [2U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [3U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [3U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [3U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [3U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [3U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [3U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [4U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [4U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [4U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [4U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [4U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [4U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [5U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [5U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [5U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [5U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [5U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [5U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [6U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [6U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [6U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [6U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [6U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [6U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                                if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                       [7U]) & (~ ([&]() {
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state 
                                                            = 
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                            [7U];
                                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout 
                                                            = 
                                                            ((5U 
                                                              == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)) 
                                                             | (6U 
                                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__state)));
                                                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1694__Vfuncout)))) 
                                     & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                         [7U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                        | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                            [7U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__event_ref)) 
                                           & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                              [7U] 
                                              != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                              [7U]))))) {
                                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found = 1U;
                                }
                            }
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__Vfuncout 
                                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__found;
                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1693__Vfuncout))))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_resources_valid = 0U;
        }
    } else if ((0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))) {
        if (((((((0xffU <= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))) 
                 | (0U != ((0xfeU >= (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)))
                            ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_state_q
                           [(0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))]
                            : 0U))) | ((~ (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
                                           >> 0x1fU)) 
                                       & (((0xfeU >= 
                                            (0xffU 
                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal)))
                                            ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_generation_q
                                           [(0xffU 
                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal))]
                                            : 0U) != 
                                          (0xfU & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal) 
                                                   >> 8U))))) 
               | ([&]() {
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref 
                                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved;
                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__unnamedblk1__DOT__slot = 0;
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 0U;
                                if ((0xfffU != (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref))) {
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [0U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [0U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [0U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [0U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [0U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [0U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__unnamedblk1__DOT__slot = 8U;
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [1U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [1U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [1U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [1U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [1U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [1U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [2U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [2U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [2U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [2U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [2U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [2U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [3U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [3U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [3U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [3U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [3U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [3U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [4U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [4U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [4U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [4U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [4U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [4U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [5U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [5U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [5U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [5U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [5U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [5U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [6U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [6U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [6U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [6U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [6U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [6U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                    if ((((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                           [7U]) & 
                                          (~ ([&]() {
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state 
                                                                = 
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q
                                                                [7U];
                                                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout 
                                                                = 
                                                                ((5U 
                                                                  == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)) 
                                                                 | (6U 
                                                                    == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__state)));
                                                        }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__terminal_state__1696__Vfuncout)))) 
                                         & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                             [7U] == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                            | ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                [7U] 
                                                == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__event_ref)) 
                                               & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait1_q
                                                  [7U] 
                                                  != 
                                                  vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_wait0_q
                                                  [7U]))))) {
                                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found = 1U;
                                    }
                                }
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__Vfuncout 
                                    = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__found;
                            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_has_live_waiter__1695__Vfuncout))) 
              | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved) 
                 == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0_resolved))) 
             | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved) 
                == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1_resolved)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_resources_valid = 0U;
        }
    }
    IData/*31:0*/ __Vilp1;
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x3fU)) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[__Vilp1] 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_flat[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT____VdfgExtracted_hf6182e41__0) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[2U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0_resolved)));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[3U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait0_resolved)) 
                       >> 0x20U));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[4U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1_resolved)));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[5U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_wait1_resolved)) 
                       >> 0x20U));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[8U] 
            = (IData)((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[9U] 
            = (IData)(((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)) 
                       >> 0x20U));
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_is_inline_rearm) 
             & (0xfffU != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[2U] 
                = (IData)((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[3U] 
                = (IData)(((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)) 
                           >> 0x20U));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[8U] 
                = ((0xffffff00U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[8U]) 
                   | (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved)));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[8U] 
                = ((0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[8U]) 
                   | ((IData)((QData)((IData)((0xfU 
                                               & ((IData)(1U) 
                                                  + 
                                                  ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved) 
                                                   >> 8U)))))) 
                      << 8U));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_resolved[9U] 
                = (((IData)((QData)((IData)((0xfU & 
                                             ((IData)(1U) 
                                              + ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved) 
                                                 >> 8U)))))) 
                    >> 0x18U) | ((IData)(((QData)((IData)(
                                                          (0xfU 
                                                           & ((IData)(1U) 
                                                              + 
                                                              ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_signal_resolved) 
                                                               >> 8U))))) 
                                          >> 0x20U)) 
                                 << 8U));
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__cmd_static_valid 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__event_resources_valid) 
           & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
               >> 0x1fU) ? (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__inline_desc_valid)
               : (((((IData)((((0U == (0x3fU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[0U])) 
                               & (0U == (0xc0000U & 
                                         vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U]))) 
                              & (0x1000000U == (0xff000000U 
                                                & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U])))) 
                     & ([&]() {
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode 
                                        = (0xffU & 
                                           vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U]);
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine 
                                        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[1U] 
                                           >> 0x1cU);
                                    vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__Vfuncout 
                                        = ((1U & (~ 
                                                  ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine) 
                                                   >> 3U))) 
                                           && ((4U 
                                                & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine))
                                                ? (
                                                   (1U 
                                                    & (~ 
                                                       ((IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine) 
                                                        >> 1U))) 
                                                   && ((1U 
                                                        & (~ (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine))) 
                                                       && (((((0x80U 
                                                               == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)) 
                                                              | (0x81U 
                                                                 == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                             | (0x82U 
                                                                == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                            | (0x84U 
                                                               == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                           | (0x86U 
                                                              == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)))))
                                                : (
                                                   (2U 
                                                    & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine))
                                                     ? 
                                                    ((((((((((0x60U 
                                                              == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)) 
                                                             | (0x61U 
                                                                == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                            | (0x62U 
                                                               == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                           | (0x63U 
                                                              == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                          | (0x64U 
                                                             == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                         | (0x65U 
                                                            == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                        | (0x66U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                       | (0x67U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                      | (0x68U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                     | (0x69U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)))
                                                     : 
                                                    ((((0x40U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)) 
                                                       | (0x41U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                      | (0x42U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                     | (0x43U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__engine))
                                                     ? 
                                                    ((((((0x20U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)) 
                                                         | (0x21U 
                                                            == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                        | (0x22U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                       | (0x23U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                      | (0x24U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                     | (0x25U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)))
                                                     : 
                                                    (((((0U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)) 
                                                        | (1U 
                                                           == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                       | (2U 
                                                          == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                      | (3U 
                                                         == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode))) 
                                                     | (4U 
                                                        == (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__opcode)))))));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_opcode_engine_valid__1689__Vfuncout))) 
                    & ([&]() {
                                vlSelfRef.__Vfunc_npu_event_ref_valid__1690__event_ref 
                                    = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[2U] 
                                       >> 0x14U);
                                vlSelfRef.__Vfunc_npu_event_ref_valid__1690__Vfuncout 
                                    = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1690__event_ref)) 
                                       | (0xffU != 
                                          (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1690__event_ref))));
                            }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1690__Vfuncout))) 
                   & ([&]() {
                            vlSelfRef.__Vfunc_npu_event_ref_valid__1691__event_ref 
                                = (0xfffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U]);
                            vlSelfRef.__Vfunc_npu_event_ref_valid__1691__Vfuncout 
                                = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1691__event_ref)) 
                                   | (0xffU != (0xffU 
                                                & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1691__event_ref))));
                        }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1691__Vfuncout))) 
                  & ([&]() {
                        vlSelfRef.__Vfunc_npu_event_ref_valid__1692__event_ref 
                            = (0xfffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_ts_cmd[3U] 
                                         >> 0xcU));
                        vlSelfRef.__Vfunc_npu_event_ref_valid__1692__Vfuncout 
                            = ((0xfffU == (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1692__event_ref)) 
                               | (0xffU != (0xffU & (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1692__event_ref))));
                    }(), (IData)(vlSelfRef.__Vfunc_npu_event_ref_valid__1692__Vfuncout)))));
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_comb__TOP__5(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_comb__TOP__5\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__internal_soft_reset_pulse)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_crg__DOT__core_reset_sync_q) 
              >> 1U));
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_comb__TOP__6(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_comb__TOP__6\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_npu_single_core__DOT__m_axi_arready_i 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_pending_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__reset_n) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_rvalid_i)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_bus_backpressure)) 
                    | (2U != (3U & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__cycle_count_q))))));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_awready_i 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_valid_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__reset_n) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bvalid_i)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_bus_backpressure)) 
                    | (0U != (3U & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__cycle_count_q))))));
    vlSelfRef.tb_npu_single_core__DOT__m_axi_wready_i 
        = ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_valid_q)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__reset_n) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bvalid_i)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__system_bus_backpressure)) 
                    | (1U != (7U & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__cycle_count_q))))));
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_comb__TOP__8(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_comb__TOP__8\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_npu_single_core__DOT__s_axi_arready_o 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) 
           & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)) 
                 & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
                    & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)) 
                       & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awvalid_i)))))));
    vlSelfRef.tb_npu_single_core__DOT__s_axi_awready_o 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) 
           & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o)) 
                 & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_state_q)) 
                    & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o)) 
                       & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_cmd_format_w)) 
                          | ((IData)(vlSelfRef.tb_npu_single_core__DOT__accept_new_cmd_o) 
                             & ((0x1ffU & ((IData)(0x10U) 
                                           - (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ingress_count_q))) 
                                >= (0x1ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i)))))))))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_handshake 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_awvalid_o) 
           & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_awready_i));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_handshake 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_wvalid_o) 
           & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_wready_i));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__write_channels_done 
        = (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_done_q) 
            | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__aw_handshake)) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_done_q) 
              | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__w_handshake)));
}

void Vtb_npu_single_core___024root___timing_resume(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___timing_resume\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_heaff7433__0.resume(
                                                   "@(posedge tb_npu_single_core.core_clk_i)");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_heaff72f2__0.resume(
                                                   "@(negedge tb_npu_single_core.core_clk_i)");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_npu_single_core___024root___timing_commit(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___timing_commit\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_heaff7433__0.commit(
                                                   "@(posedge tb_npu_single_core.core_clk_i)");
    }
    if ((! (8ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_heaff72f2__0.commit(
                                                   "@(negedge tb_npu_single_core.core_clk_i)");
    }
}

void Vtb_npu_single_core___024root___eval_triggers__act(Vtb_npu_single_core___024root* vlSelf);
void Vtb_npu_single_core___024root___eval_act(Vtb_npu_single_core___024root* vlSelf);

bool Vtb_npu_single_core___024root___eval_phase__act(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_phase__act\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<5> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_npu_single_core___024root___eval_triggers__act(vlSelf);
    Vtb_npu_single_core___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_npu_single_core___024root___timing_resume(vlSelf);
        Vtb_npu_single_core___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtb_npu_single_core___024root___eval_nba(Vtb_npu_single_core___024root* vlSelf);

bool Vtb_npu_single_core___024root___eval_phase__nba(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_phase__nba\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_npu_single_core___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_single_core___024root___dump_triggers__nba(Vtb_npu_single_core___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_single_core___024root___dump_triggers__act(Vtb_npu_single_core___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_npu_single_core___024root___eval(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__protocol_checks_enable 
        = vlSelfRef.tb_npu_single_core__DOT__protocol_checks_enable;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_1_0 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_1_0;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_2_0 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_2_0;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_4_0 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_4_0;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__m_axi_awvalid_o 
        = vlSelfRef.tb_npu_single_core__DOT__m_axi_awvalid_o;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_5_0 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_5_0;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_7_0 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_7_0;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__m_axi_wvalid_o 
        = vlSelfRef.tb_npu_single_core__DOT__m_axi_wvalid_o;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_8_0[0U] 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_8_0[0U];
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_8_0[1U] 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_8_0[1U];
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_8_0[2U] 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_8_0[2U];
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_10_0 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_10_0;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_bvalid_o 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bvalid_o;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_11_0 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_11_0;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_id_q;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_bresp_o 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bresp_o;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_13_0 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_13_0;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rvalid_o 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_14_0[0U] 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_14_0[0U];
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_14_0[1U] 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_14_0[1U];
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT___Vpast_14_0[2U] 
        = vlSelfRef.tb_npu_single_core__DOT___Vpast_14_0[2U];
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rid_o 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rid_o;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rdata_o 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rdata_o;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rresp_o 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rresp_o;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rlast_o 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rlast_o;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__m_axi_arready_i 
        = vlSelfRef.tb_npu_single_core__DOT__m_axi_arready_i;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__m_axi_awready_i 
        = vlSelfRef.tb_npu_single_core__DOT__m_axi_awready_i;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__m_axi_wready_i 
        = vlSelfRef.tb_npu_single_core__DOT__m_axi_wready_i;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_bready_i 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_bready_i;
    vlSelfRef.__Vsampled_TOP__tb_npu_single_core__DOT__s_axi_rready_i 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_npu_single_core___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_npu_single_core.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtb_npu_single_core___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_npu_single_core.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_npu_single_core___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_npu_single_core___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_npu_single_core___024root___eval_debug_assertions(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___eval_debug_assertions\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
