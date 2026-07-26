// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core___024root.h"

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__6(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__6\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vfunc_store_element_strb__2265__Vfuncout;
    __Vfunc_store_element_strb__2265__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_store_element_strb__2265__byte_lane;
    __Vfunc_store_element_strb__2265__byte_lane = 0;
    CData/*1:0*/ __Vfunc_store_element_strb__2265__dtype;
    __Vfunc_store_element_strb__2265__dtype = 0;
    CData/*7:0*/ __Vfunc_store_element_strb__2265__result;
    __Vfunc_store_element_strb__2265__result = 0;
    CData/*7:0*/ __Vfunc_store_element_strb__2334__Vfuncout;
    __Vfunc_store_element_strb__2334__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_store_element_strb__2334__byte_lane;
    __Vfunc_store_element_strb__2334__byte_lane = 0;
    CData/*1:0*/ __Vfunc_store_element_strb__2334__dtype;
    __Vfunc_store_element_strb__2334__dtype = 0;
    CData/*7:0*/ __Vfunc_store_element_strb__2334__result;
    __Vfunc_store_element_strb__2334__result = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__base;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__row;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__col;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__row_stride;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__feature_only;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__feature_only = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__row_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__col_offset;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__col_offset = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__row;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__col;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__row_stride;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__dtype;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__feature_only;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__feature_only = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2649__lhs;
    __Vfunc_fp32_mul__2649__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2649__rhs;
    __Vfunc_fp32_mul__2649__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2649__normalize_count;
    __Vfunc_fp32_mul__2649__normalize_count = 0;
    QData/*63:0*/ __Vfunc_fp32_from_int__2650__value;
    __Vfunc_fp32_from_int__2650__value = 0;
    IData/*31:0*/ __Vfunc_fp32_from_int__2650__bit_index;
    __Vfunc_fp32_from_int__2650__bit_index = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2651__unused_sign;
    __Vfunc_fp32_is_nan__2651__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2652__unused_sign;
    __Vfunc_fp32_is_nan__2652__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2653__unused_sign;
    __Vfunc_fp32_is_inf__2653__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2654__unused_sign;
    __Vfunc_fp32_is_zero__2654__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2655__unused_sign;
    __Vfunc_fp32_is_inf__2655__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2656__unused_sign;
    __Vfunc_fp32_is_zero__2656__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2657__unused_sign;
    __Vfunc_fp32_is_inf__2657__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2658__unused_sign;
    __Vfunc_fp32_is_inf__2658__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2659__unused_sign;
    __Vfunc_fp32_is_zero__2659__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2660__unused_sign;
    __Vfunc_fp32_is_zero__2660__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2661__lhs;
    __Vfunc_fp32_mul__2661__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2661__rhs;
    __Vfunc_fp32_mul__2661__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2661__normalize_count;
    __Vfunc_fp32_mul__2661__normalize_count = 0;
    QData/*63:0*/ __Vfunc_fp32_from_int__2662__value;
    __Vfunc_fp32_from_int__2662__value = 0;
    IData/*31:0*/ __Vfunc_fp32_from_int__2662__bit_index;
    __Vfunc_fp32_from_int__2662__bit_index = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2663__unused_sign;
    __Vfunc_fp32_is_nan__2663__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2664__unused_sign;
    __Vfunc_fp32_is_nan__2664__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2665__unused_sign;
    __Vfunc_fp32_is_inf__2665__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2666__unused_sign;
    __Vfunc_fp32_is_zero__2666__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2667__unused_sign;
    __Vfunc_fp32_is_inf__2667__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2668__unused_sign;
    __Vfunc_fp32_is_zero__2668__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2669__unused_sign;
    __Vfunc_fp32_is_inf__2669__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2670__unused_sign;
    __Vfunc_fp32_is_inf__2670__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2671__unused_sign;
    __Vfunc_fp32_is_zero__2671__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2672__unused_sign;
    __Vfunc_fp32_is_zero__2672__unused_sign = 0;
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_fp 
        = vlSelfRef.__Vfunc_fp32_mul__2673__Vfuncout;
    __Vfunc_fp32_mul__2661__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1dU];
    __Vfunc_fp32_from_int__2662__value = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_value_q 
                                          - (((QData)((IData)(
                                                              (- (IData)(
                                                                         (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x21U] 
                                                                          >> 0x1fU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x21U]))));
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_from_int__2662__sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7705171009078516702ull);
    vlSelf->__Vfunc_fp32_from_int__2662__magnitude = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12745927018401496645ull);
    vlSelf->__Vfunc_fp32_from_int__2662__shifted_significand = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16580074790465021286ull);
    vlSelf->__Vfunc_fp32_from_int__2662__remainder_mask = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9573386125889225419ull);
    vlSelf->__Vfunc_fp32_from_int__2662__remainder = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11826180862059690349ull);
    vlSelf->__Vfunc_fp32_from_int__2662__halfway = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13771528117173901648ull);
    vlSelf->__Vfunc_fp32_from_int__2662__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 15589325731495609263ull);
    vlSelf->__Vfunc_fp32_from_int__2662__fraction = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 14304653970926020304ull);
    vlSelf->__Vfunc_fp32_from_int__2662__exponent = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 12777665656408766670ull);
    vlSelf->__Vfunc_fp32_from_int__2662__leading_bit = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8361413001003127659ull);
    vlSelf->__Vfunc_fp32_from_int__2662__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9939302341833882547ull);
    __Vfunc_fp32_from_int__2662__bit_index = 0;
    {
        if ((0ULL == __Vfunc_fp32_from_int__2662__value)) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__Vfuncout = 0U;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_from_int__2662__sign 
            = (1U & (IData)((__Vfunc_fp32_from_int__2662__value 
                             >> 0x3fU)));
        vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
            = ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2662__sign)
                ? (1ULL + (~ __Vfunc_fp32_from_int__2662__value))
                : __Vfunc_fp32_from_int__2662__value);
        vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0U;
        __Vfunc_fp32_from_int__2662__bit_index = 0U;
        if ((1U & (IData)(vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 1U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 1U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 1U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 2U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 2U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 2U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 3U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 3U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 3U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 4U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 4U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 4U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 5U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 5U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 5U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 6U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 6U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 6U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 7U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 7U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 7U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 8U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 8U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 8U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 9U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 9U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 9U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0xaU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0xaU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0xaU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0xbU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0xbU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0xbU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0xcU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0xcU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0xcU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0xdU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0xdU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0xdU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0xeU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0xeU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0xeU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0xfU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0xfU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0xfU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x10U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x10U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x10U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x11U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x11U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x11U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x12U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x12U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x12U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x13U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x13U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x13U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x14U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x14U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x14U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x15U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x15U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x15U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x16U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x16U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x16U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x17U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x17U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x18U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x18U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x18U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x19U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x19U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x19U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x1aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x1aU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x1bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x1bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x1bU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x1cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x1cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x1cU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x1dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x1dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x1dU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x1eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x1eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x1eU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x1fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x1fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x1fU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x20U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x20U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x20U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x21U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x21U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x21U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x22U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x22U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x22U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x23U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x23U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x23U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x24U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x24U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x24U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x25U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x25U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x25U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x26U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x26U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x26U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x27U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x27U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x27U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x28U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x28U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x28U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x29U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x29U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x29U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x2aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x2aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x2aU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x2bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x2bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x2bU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x2cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x2cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x2cU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x2dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x2dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x2dU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x2eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x2eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x2eU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x2fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x2fU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x30U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x30U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x30U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x31U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x31U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x31U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x32U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x32U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x32U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x33U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x33U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x33U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x34U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x34U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x34U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x35U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x35U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x35U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x36U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x36U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x36U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x37U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x37U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x37U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x38U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x38U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x38U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x39U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x39U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x39U;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x3aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x3aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x3aU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x3bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x3bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x3bU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x3cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x3cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x3cU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x3dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x3dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x3dU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x3eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x3eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x3eU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x3fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                           >> 0x3fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit = 0x3fU;
        }
        __Vfunc_fp32_from_int__2662__bit_index = 0x40U;
        vlSelfRef.__Vfunc_fp32_from_int__2662__exponent 
            = (0x1ffU & ((IData)(0x7fU) + vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit));
        if (VL_GTES_III(32, 0x17U, vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit)) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTL_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude, 
                                                     ((IData)(0x17U) 
                                                      - vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit))));
            vlSelfRef.__Vfunc_fp32_from_int__2662__fraction 
                = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__2662__shifted_significand);
        } else {
            vlSelfRef.__Vfunc_fp32_from_int__2662__shift_amount 
                = (vlSelfRef.__Vfunc_fp32_from_int__2662__leading_bit 
                   - (IData)(0x17U));
            vlSelfRef.__Vfunc_fp32_from_int__2662__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTR_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude, vlSelfRef.__Vfunc_fp32_from_int__2662__shift_amount)));
            vlSelfRef.__Vfunc_fp32_from_int__2662__remainder_mask 
                = (VL_SHIFTL_QQI(64,64,32, 1ULL, vlSelfRef.__Vfunc_fp32_from_int__2662__shift_amount) 
                   - 1ULL);
            vlSelfRef.__Vfunc_fp32_from_int__2662__remainder 
                = (vlSelfRef.__Vfunc_fp32_from_int__2662__magnitude 
                   & vlSelfRef.__Vfunc_fp32_from_int__2662__remainder_mask);
            vlSelfRef.__Vfunc_fp32_from_int__2662__halfway 
                = VL_SHIFTL_QQI(64,64,32, 1ULL, (vlSelfRef.__Vfunc_fp32_from_int__2662__shift_amount 
                                                 - (IData)(1U)));
            vlSelfRef.__Vfunc_fp32_from_int__2662__rounded 
                = vlSelfRef.__Vfunc_fp32_from_int__2662__shifted_significand;
            if (((vlSelfRef.__Vfunc_fp32_from_int__2662__remainder 
                  > vlSelfRef.__Vfunc_fp32_from_int__2662__halfway) 
                 | ((vlSelfRef.__Vfunc_fp32_from_int__2662__remainder 
                     == vlSelfRef.__Vfunc_fp32_from_int__2662__halfway) 
                    & vlSelfRef.__Vfunc_fp32_from_int__2662__shifted_significand))) {
                vlSelfRef.__Vfunc_fp32_from_int__2662__rounded 
                    = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_from_int__2662__rounded));
            }
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_from_int__2662__rounded)) {
                vlSelfRef.__Vfunc_fp32_from_int__2662__fraction 
                    = (0x7fffffU & (vlSelfRef.__Vfunc_fp32_from_int__2662__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_from_int__2662__exponent 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_from_int__2662__exponent)));
            } else {
                vlSelfRef.__Vfunc_fp32_from_int__2662__fraction 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__2662__rounded);
            }
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_from_int__2662__exponent))) {
            vlSelfRef.__Vfunc_fp32_from_int__2662__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2662__sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_from_int__2662__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_from_int__2662__sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2662__exponent) 
                                             << 0x17U)) 
                             | vlSelfRef.__Vfunc_fp32_from_int__2662__fraction));
        __Vlabel0: ;
    }
    __Vfunc_fp32_mul__2661__lhs = vlSelfRef.__Vfunc_fp32_from_int__2662__Vfuncout;
    vlSelf->__Vfunc_fp32_mul__2661__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12053139662250073399ull);
    vlSelf->__Vfunc_fp32_mul__2661__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7439212746947954242ull);
    vlSelf->__Vfunc_fp32_mul__2661__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5571606938113615592ull);
    vlSelf->__Vfunc_fp32_mul__2661__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 237788931025940579ull);
    vlSelf->__Vfunc_fp32_mul__2661__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 12453668215662055057ull);
    vlSelf->__Vfunc_fp32_mul__2661__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 1652035967928046046ull);
    vlSelf->__Vfunc_fp32_mul__2661__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 8343220165043629048ull);
    vlSelf->__Vfunc_fp32_mul__2661__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 11342995109539022345ull);
    vlSelf->__Vfunc_fp32_mul__2661__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14320144363569209098ull);
    vlSelf->__Vfunc_fp32_mul__2661__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1001306900970749240ull);
    vlSelf->__Vfunc_fp32_mul__2661__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6853208175017447638ull);
    vlSelf->__Vfunc_fp32_mul__2661__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3740441184321596428ull);
    vlSelf->__Vfunc_fp32_mul__2661__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18135062534648848501ull);
    __Vfunc_fp32_mul__2661__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2663__bits 
                                = __Vfunc_fp32_mul__2661__lhs;
                            __Vfunc_fp32_is_nan__2663__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2663__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2663__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2663__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2663__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2663__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2663__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2664__bits 
                                = __Vfunc_fp32_mul__2661__rhs;
                            __Vfunc_fp32_is_nan__2664__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2664__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2664__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2664__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2664__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2664__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2664__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2665__bits 
                                    = __Vfunc_fp32_mul__2661__lhs;
                                __Vfunc_fp32_is_inf__2665__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2665__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2665__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2665__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2665__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2665__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2666__bits 
                                    = __Vfunc_fp32_mul__2661__rhs;
                                __Vfunc_fp32_is_zero__2666__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2666__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2666__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2666__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2666__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2666__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2667__bits 
                                    = __Vfunc_fp32_mul__2661__rhs;
                                __Vfunc_fp32_is_inf__2667__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2667__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2667__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2667__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2667__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2667__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2668__bits 
                                    = __Vfunc_fp32_mul__2661__lhs;
                                __Vfunc_fp32_is_zero__2668__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2668__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2668__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2668__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2668__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2668__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__Vfuncout = 0x7fc00000U;
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_mul__2661__result_sign 
            = ((__Vfunc_fp32_mul__2661__lhs ^ __Vfunc_fp32_mul__2661__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2669__bits 
                            = __Vfunc_fp32_mul__2661__lhs;
                        __Vfunc_fp32_is_inf__2669__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2669__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2669__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2669__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2669__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2669__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2670__bits 
                            = __Vfunc_fp32_mul__2661__rhs;
                        __Vfunc_fp32_is_inf__2670__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2670__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2670__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2670__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2670__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2670__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2661__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2671__bits 
                            = __Vfunc_fp32_mul__2661__lhs;
                        __Vfunc_fp32_is_zero__2671__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2671__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2671__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2671__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2671__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2671__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2672__bits 
                            = __Vfunc_fp32_mul__2661__rhs;
                        __Vfunc_fp32_is_zero__2672__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2672__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2672__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2672__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2672__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2672__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2661__result_sign) 
                   << 0x1fU);
            goto __Vlabel1;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2661__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2661__lhs);
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2661__lhs));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2661__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2661__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2661__rhs);
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2661__rhs));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2661__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__2661__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__2661__normalize_count = 1U;
        __Vfunc_fp32_mul__2661__normalize_count = 2U;
        __Vfunc_fp32_mul__2661__normalize_count = 3U;
        __Vfunc_fp32_mul__2661__normalize_count = 4U;
        __Vfunc_fp32_mul__2661__normalize_count = 5U;
        __Vfunc_fp32_mul__2661__normalize_count = 6U;
        __Vfunc_fp32_mul__2661__normalize_count = 7U;
        __Vfunc_fp32_mul__2661__normalize_count = 8U;
        __Vfunc_fp32_mul__2661__normalize_count = 9U;
        __Vfunc_fp32_mul__2661__normalize_count = 0xaU;
        __Vfunc_fp32_mul__2661__normalize_count = 0xbU;
        __Vfunc_fp32_mul__2661__normalize_count = 0xcU;
        __Vfunc_fp32_mul__2661__normalize_count = 0xdU;
        __Vfunc_fp32_mul__2661__normalize_count = 0xeU;
        __Vfunc_fp32_mul__2661__normalize_count = 0xfU;
        __Vfunc_fp32_mul__2661__normalize_count = 0x10U;
        __Vfunc_fp32_mul__2661__normalize_count = 0x11U;
        __Vfunc_fp32_mul__2661__normalize_count = 0x12U;
        __Vfunc_fp32_mul__2661__normalize_count = 0x13U;
        __Vfunc_fp32_mul__2661__normalize_count = 0x14U;
        __Vfunc_fp32_mul__2661__normalize_count = 0x15U;
        __Vfunc_fp32_mul__2661__normalize_count = 0x16U;
        __Vfunc_fp32_mul__2661__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__2661__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2661__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2661__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__2661__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__2661__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__2661__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__2661__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__2661__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2661__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2661__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__2661__mantissa 
            = (0xffffffU & (IData)((0xffffffffffffULL 
                                    & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__2661__product, vlSelfRef.__Vfunc_fp32_mul__2661__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__2661__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__2661__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__2661__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__2661__product 
               & vlSelfRef.__Vfunc_fp32_mul__2661__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__2661__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__2661__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__2661__rounded = vlSelfRef.__Vfunc_fp32_mul__2661__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__2661__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__2661__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__2661__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__2661__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__2661__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__2661__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2661__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__2661__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__2661__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__2661__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__2661__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2661__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2661__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__2661__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__2661__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2661__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2661__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__2661__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2661__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2661__result_sign) 
                   << 0x1fU);
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_mul__2661__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_mul__2661__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_mul__2661__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__2661__mantissa)));
        __Vlabel1: ;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_fp 
        = vlSelfRef.__Vfunc_fp32_mul__2661__Vfuncout;
    __Vfunc_fp32_mul__2649__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x1cU];
    __Vfunc_fp32_from_int__2650__value = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_value_q 
                                          - (((QData)((IData)(
                                                              (- (IData)(
                                                                         (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x20U] 
                                                                          >> 0x1fU))))) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x20U]))));
    vlSelf->__Vfunc_fp32_from_int__2650__sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12210854030635874383ull);
    vlSelf->__Vfunc_fp32_from_int__2650__magnitude = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10045774068999838386ull);
    vlSelf->__Vfunc_fp32_from_int__2650__shifted_significand = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18210660401589957106ull);
    vlSelf->__Vfunc_fp32_from_int__2650__remainder_mask = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1832128051105824872ull);
    vlSelf->__Vfunc_fp32_from_int__2650__remainder = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16772927945038049172ull);
    vlSelf->__Vfunc_fp32_from_int__2650__halfway = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8253117801819163391ull);
    vlSelf->__Vfunc_fp32_from_int__2650__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 4560839841007253147ull);
    vlSelf->__Vfunc_fp32_from_int__2650__fraction = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 6323040739956010210ull);
    vlSelf->__Vfunc_fp32_from_int__2650__exponent = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 16803429226641029218ull);
    vlSelf->__Vfunc_fp32_from_int__2650__leading_bit = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17832545462080877807ull);
    vlSelf->__Vfunc_fp32_from_int__2650__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8479813986679830707ull);
    __Vfunc_fp32_from_int__2650__bit_index = 0;
    {
        if ((0ULL == __Vfunc_fp32_from_int__2650__value)) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__Vfuncout = 0U;
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_from_int__2650__sign 
            = (1U & (IData)((__Vfunc_fp32_from_int__2650__value 
                             >> 0x3fU)));
        vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
            = ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2650__sign)
                ? (1ULL + (~ __Vfunc_fp32_from_int__2650__value))
                : __Vfunc_fp32_from_int__2650__value);
        vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0U;
        __Vfunc_fp32_from_int__2650__bit_index = 0U;
        if ((1U & (IData)(vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 1U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 1U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 1U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 2U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 2U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 2U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 3U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 3U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 3U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 4U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 4U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 4U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 5U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 5U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 5U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 6U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 6U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 6U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 7U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 7U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 7U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 8U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 8U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 8U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 9U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 9U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 9U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0xaU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0xaU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0xaU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0xbU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0xbU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0xbU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0xcU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0xcU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0xcU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0xdU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0xdU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0xdU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0xeU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0xeU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0xeU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0xfU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0xfU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0xfU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x10U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x10U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x10U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x11U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x11U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x11U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x12U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x12U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x12U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x13U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x13U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x13U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x14U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x14U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x14U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x15U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x15U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x15U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x16U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x16U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x16U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x17U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x17U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x18U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x18U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x18U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x19U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x19U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x19U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x1aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x1aU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x1bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x1bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x1bU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x1cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x1cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x1cU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x1dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x1dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x1dU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x1eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x1eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x1eU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x1fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x1fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x1fU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x20U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x20U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x20U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x21U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x21U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x21U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x22U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x22U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x22U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x23U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x23U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x23U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x24U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x24U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x24U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x25U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x25U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x25U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x26U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x26U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x26U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x27U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x27U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x27U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x28U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x28U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x28U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x29U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x29U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x29U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x2aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x2aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x2aU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x2bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x2bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x2bU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x2cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x2cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x2cU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x2dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x2dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x2dU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x2eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x2eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x2eU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x2fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x2fU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x30U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x30U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x30U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x31U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x31U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x31U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x32U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x32U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x32U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x33U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x33U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x33U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x34U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x34U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x34U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x35U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x35U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x35U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x36U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x36U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x36U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x37U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x37U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x37U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x38U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x38U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x38U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x39U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x39U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x39U;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x3aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x3aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x3aU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x3bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x3bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x3bU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x3cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x3cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x3cU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x3dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x3dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x3dU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x3eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x3eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x3eU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x3fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                           >> 0x3fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit = 0x3fU;
        }
        __Vfunc_fp32_from_int__2650__bit_index = 0x40U;
        vlSelfRef.__Vfunc_fp32_from_int__2650__exponent 
            = (0x1ffU & ((IData)(0x7fU) + vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit));
        if (VL_GTES_III(32, 0x17U, vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit)) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTL_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude, 
                                                     ((IData)(0x17U) 
                                                      - vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit))));
            vlSelfRef.__Vfunc_fp32_from_int__2650__fraction 
                = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__2650__shifted_significand);
        } else {
            vlSelfRef.__Vfunc_fp32_from_int__2650__shift_amount 
                = (vlSelfRef.__Vfunc_fp32_from_int__2650__leading_bit 
                   - (IData)(0x17U));
            vlSelfRef.__Vfunc_fp32_from_int__2650__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTR_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude, vlSelfRef.__Vfunc_fp32_from_int__2650__shift_amount)));
            vlSelfRef.__Vfunc_fp32_from_int__2650__remainder_mask 
                = (VL_SHIFTL_QQI(64,64,32, 1ULL, vlSelfRef.__Vfunc_fp32_from_int__2650__shift_amount) 
                   - 1ULL);
            vlSelfRef.__Vfunc_fp32_from_int__2650__remainder 
                = (vlSelfRef.__Vfunc_fp32_from_int__2650__magnitude 
                   & vlSelfRef.__Vfunc_fp32_from_int__2650__remainder_mask);
            vlSelfRef.__Vfunc_fp32_from_int__2650__halfway 
                = VL_SHIFTL_QQI(64,64,32, 1ULL, (vlSelfRef.__Vfunc_fp32_from_int__2650__shift_amount 
                                                 - (IData)(1U)));
            vlSelfRef.__Vfunc_fp32_from_int__2650__rounded 
                = vlSelfRef.__Vfunc_fp32_from_int__2650__shifted_significand;
            if (((vlSelfRef.__Vfunc_fp32_from_int__2650__remainder 
                  > vlSelfRef.__Vfunc_fp32_from_int__2650__halfway) 
                 | ((vlSelfRef.__Vfunc_fp32_from_int__2650__remainder 
                     == vlSelfRef.__Vfunc_fp32_from_int__2650__halfway) 
                    & vlSelfRef.__Vfunc_fp32_from_int__2650__shifted_significand))) {
                vlSelfRef.__Vfunc_fp32_from_int__2650__rounded 
                    = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_from_int__2650__rounded));
            }
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_from_int__2650__rounded)) {
                vlSelfRef.__Vfunc_fp32_from_int__2650__fraction 
                    = (0x7fffffU & (vlSelfRef.__Vfunc_fp32_from_int__2650__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_from_int__2650__exponent 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_from_int__2650__exponent)));
            } else {
                vlSelfRef.__Vfunc_fp32_from_int__2650__fraction 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__2650__rounded);
            }
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_from_int__2650__exponent))) {
            vlSelfRef.__Vfunc_fp32_from_int__2650__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2650__sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_from_int__2650__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_from_int__2650__sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_from_int__2650__exponent) 
                                             << 0x17U)) 
                             | vlSelfRef.__Vfunc_fp32_from_int__2650__fraction));
        __Vlabel2: ;
    }
    __Vfunc_fp32_mul__2649__lhs = vlSelfRef.__Vfunc_fp32_from_int__2650__Vfuncout;
    vlSelf->__Vfunc_fp32_mul__2649__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3066983705170053730ull);
    vlSelf->__Vfunc_fp32_mul__2649__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13056782992390822674ull);
    vlSelf->__Vfunc_fp32_mul__2649__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10792334493064211240ull);
    vlSelf->__Vfunc_fp32_mul__2649__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 12344069853646416666ull);
    vlSelf->__Vfunc_fp32_mul__2649__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 5696608711805209344ull);
    vlSelf->__Vfunc_fp32_mul__2649__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 10136193907415162681ull);
    vlSelf->__Vfunc_fp32_mul__2649__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 6191357108321616002ull);
    vlSelf->__Vfunc_fp32_mul__2649__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 2665925506747517739ull);
    vlSelf->__Vfunc_fp32_mul__2649__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15785057000938349301ull);
    vlSelf->__Vfunc_fp32_mul__2649__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10067720929359478470ull);
    vlSelf->__Vfunc_fp32_mul__2649__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7164961544834662478ull);
    vlSelf->__Vfunc_fp32_mul__2649__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8066656528071427158ull);
    vlSelf->__Vfunc_fp32_mul__2649__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11067332776969877691ull);
    __Vfunc_fp32_mul__2649__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2651__bits 
                                = __Vfunc_fp32_mul__2649__lhs;
                            __Vfunc_fp32_is_nan__2651__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2651__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2651__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2651__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2651__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2651__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2651__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2652__bits 
                                = __Vfunc_fp32_mul__2649__rhs;
                            __Vfunc_fp32_is_nan__2652__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2652__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2652__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2652__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2652__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2652__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2652__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2653__bits 
                                    = __Vfunc_fp32_mul__2649__lhs;
                                __Vfunc_fp32_is_inf__2653__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2653__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2653__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2653__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2653__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2653__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2654__bits 
                                    = __Vfunc_fp32_mul__2649__rhs;
                                __Vfunc_fp32_is_zero__2654__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2654__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2654__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2654__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2654__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2654__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2655__bits 
                                    = __Vfunc_fp32_mul__2649__rhs;
                                __Vfunc_fp32_is_inf__2655__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2655__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2655__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2655__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2655__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2655__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2656__bits 
                                    = __Vfunc_fp32_mul__2649__lhs;
                                __Vfunc_fp32_is_zero__2656__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2656__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2656__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2656__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2656__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2656__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__Vfuncout = 0x7fc00000U;
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_mul__2649__result_sign 
            = ((__Vfunc_fp32_mul__2649__lhs ^ __Vfunc_fp32_mul__2649__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2657__bits 
                            = __Vfunc_fp32_mul__2649__lhs;
                        __Vfunc_fp32_is_inf__2657__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2657__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2657__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2657__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2657__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2657__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2658__bits 
                            = __Vfunc_fp32_mul__2649__rhs;
                        __Vfunc_fp32_is_inf__2658__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2658__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2658__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2658__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2658__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2658__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2649__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2659__bits 
                            = __Vfunc_fp32_mul__2649__lhs;
                        __Vfunc_fp32_is_zero__2659__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2659__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2659__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2659__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2659__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2659__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2660__bits 
                            = __Vfunc_fp32_mul__2649__rhs;
                        __Vfunc_fp32_is_zero__2660__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2660__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2660__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2660__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2660__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2660__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2649__result_sign) 
                   << 0x1fU);
            goto __Vlabel3;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2649__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2649__lhs);
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2649__lhs));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2649__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2649__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2649__rhs);
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2649__rhs));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2649__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__2649__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__2649__normalize_count = 1U;
        __Vfunc_fp32_mul__2649__normalize_count = 2U;
        __Vfunc_fp32_mul__2649__normalize_count = 3U;
        __Vfunc_fp32_mul__2649__normalize_count = 4U;
        __Vfunc_fp32_mul__2649__normalize_count = 5U;
        __Vfunc_fp32_mul__2649__normalize_count = 6U;
        __Vfunc_fp32_mul__2649__normalize_count = 7U;
        __Vfunc_fp32_mul__2649__normalize_count = 8U;
        __Vfunc_fp32_mul__2649__normalize_count = 9U;
        __Vfunc_fp32_mul__2649__normalize_count = 0xaU;
        __Vfunc_fp32_mul__2649__normalize_count = 0xbU;
        __Vfunc_fp32_mul__2649__normalize_count = 0xcU;
        __Vfunc_fp32_mul__2649__normalize_count = 0xdU;
        __Vfunc_fp32_mul__2649__normalize_count = 0xeU;
        __Vfunc_fp32_mul__2649__normalize_count = 0xfU;
        __Vfunc_fp32_mul__2649__normalize_count = 0x10U;
        __Vfunc_fp32_mul__2649__normalize_count = 0x11U;
        __Vfunc_fp32_mul__2649__normalize_count = 0x12U;
        __Vfunc_fp32_mul__2649__normalize_count = 0x13U;
        __Vfunc_fp32_mul__2649__normalize_count = 0x14U;
        __Vfunc_fp32_mul__2649__normalize_count = 0x15U;
        __Vfunc_fp32_mul__2649__normalize_count = 0x16U;
        __Vfunc_fp32_mul__2649__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__2649__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2649__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2649__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__2649__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__2649__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__2649__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__2649__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__2649__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2649__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2649__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__2649__mantissa 
            = (0xffffffU & (IData)((0xffffffffffffULL 
                                    & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__2649__product, vlSelfRef.__Vfunc_fp32_mul__2649__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__2649__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__2649__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__2649__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__2649__product 
               & vlSelfRef.__Vfunc_fp32_mul__2649__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__2649__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__2649__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__2649__rounded = vlSelfRef.__Vfunc_fp32_mul__2649__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__2649__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__2649__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__2649__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__2649__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__2649__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__2649__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2649__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__2649__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__2649__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__2649__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__2649__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2649__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2649__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__2649__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__2649__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2649__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2649__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__2649__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2649__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2649__result_sign) 
                   << 0x1fU);
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_mul__2649__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_mul__2649__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_mul__2649__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__2649__mantissa)));
        __Vlabel3: ;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_fp 
        = vlSelfRef.__Vfunc_fp32_mul__2649__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns 
        = ((((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q) 
            == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x10U])
            ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x12U]
            : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x11U]);
    __Vfunc_store_element_strb__2334__dtype = (3U & 
                                               (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU] 
                                                >> 6U));
    __Vfunc_store_element_strb__2334__byte_lane = (7U 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr));
    __Vfunc_store_element_strb__2334__result = 0U;
    __Vfunc_store_element_strb__2334__result = ((2U 
                                                 & (IData)(__Vfunc_store_element_strb__2334__dtype))
                                                 ? 
                                                (0xffU 
                                                 & ((1U 
                                                     & (IData)(__Vfunc_store_element_strb__2334__dtype))
                                                     ? 
                                                    ((IData)(3U) 
                                                     << (IData)(__Vfunc_store_element_strb__2334__byte_lane))
                                                     : 
                                                    ((IData)(0xfU) 
                                                     << (IData)(__Vfunc_store_element_strb__2334__byte_lane))))
                                                 : 
                                                ((IData)(__Vfunc_store_element_strb__2334__result) 
                                                 | (0xffU 
                                                    & ((IData)(1U) 
                                                       << (IData)(__Vfunc_store_element_strb__2334__byte_lane)))));
    __Vfunc_store_element_strb__2334__Vfuncout = __Vfunc_store_element_strb__2334__result;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT____VdfgExtracted_ha467d4d5__0 
        = __Vfunc_store_element_strb__2334__Vfuncout;
    __Vfunc_store_element_strb__2265__dtype = (3U & 
                                               (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU] 
                                                >> 6U));
    __Vfunc_store_element_strb__2265__byte_lane = (7U 
                                                   & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_addr));
    __Vfunc_store_element_strb__2265__result = 0U;
    __Vfunc_store_element_strb__2265__result = ((2U 
                                                 & (IData)(__Vfunc_store_element_strb__2265__dtype))
                                                 ? 
                                                (0xffU 
                                                 & ((1U 
                                                     & (IData)(__Vfunc_store_element_strb__2265__dtype))
                                                     ? 
                                                    ((IData)(3U) 
                                                     << (IData)(__Vfunc_store_element_strb__2265__byte_lane))
                                                     : 
                                                    ((IData)(0xfU) 
                                                     << (IData)(__Vfunc_store_element_strb__2265__byte_lane))))
                                                 : 
                                                ((IData)(__Vfunc_store_element_strb__2265__result) 
                                                 | (0xffU 
                                                    & ((IData)(1U) 
                                                       << (IData)(__Vfunc_store_element_strb__2265__byte_lane)))));
    __Vfunc_store_element_strb__2265__Vfuncout = __Vfunc_store_element_strb__2265__result;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT____VdfgExtracted_h8e2aa811__0 
        = __Vfunc_store_element_strb__2265__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_high_nibble 
        = (IData)(((0U == (0xcU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU])) 
                   & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_is_tiled)
                       ? ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_high_nibble__2197__n_index_odd 
                            = (1U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q);
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_high_nibble__2197__Vfuncout 
                            = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_high_nibble__2197__n_index_odd;
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_high_nibble__2197__Vfuncout))
                       : ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U])
                           ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q
                           : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_addr 
        = (((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[5U])) 
              << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[4U]))) 
            + ((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__batch_q)) 
               * (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1fU])) 
                   << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x1eU]))))) 
           + ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_is_tiled)
               ? ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__dtype 
                        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU] 
                                 >> 2U));
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_size 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x11U];
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_index 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q;
                    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__k_index 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q;
                    vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__k_outer = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 41070116762272944ull);
                    vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_outer = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4144077066631907795ull);
                    vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__k_inner = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10408499825580823553ull);
                    vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_inner = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8394966022842911003ull);
                    vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_tiles = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15967065891769555072ull);
                    vlSelf->__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__element_index = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16731497283120220901ull);
                    {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__k_outer 
                            = VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__k_index, 4U);
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_outer 
                            = VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_index, 3U);
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__k_inner 
                            = (0xfU & vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__k_index);
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_inner 
                            = (7U & vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_index);
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_tiles 
                            = VL_SHIFTR_III(32,32,32, 
                                            ((IData)(7U) 
                                             + vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_size), 3U);
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__element_index 
                            = (VL_SHIFTL_QQI(64,64,32, 
                                             (VL_SHIFTL_QQI(64,64,32, 
                                                            (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__k_outer)) 
                                                              * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_tiles))) 
                                                             + (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_outer))), 4U) 
                                              + (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__k_inner))), 3U) 
                               + (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__n_inner)));
                        if ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__dtype))) {
                            vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__Vfuncout 
                                = VL_SHIFTR_QQI(64,64,32, vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__element_index, 1U);
                            goto __Vlabel4;
                        }
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__Vfuncout 
                            = (vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__element_index 
                               * VL_EXTEND_QI(64,3, 
                                              ([&]() {
                                        vlSelfRef.__Vfunc_dtype_bytes__2188__dtype 
                                            = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__dtype;
                                        vlSelfRef.__Vfunc_dtype_bytes__2188__Vfuncout 
                                            = ((1U 
                                                == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2188__dtype))
                                                ? 1U
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2188__dtype))
                                                    ? 4U
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2188__dtype))
                                                     ? 2U
                                                     : 0U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2188__Vfuncout))));
                        __Vlabel4: ;
                    }
                }(), vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__tiled_b_offset__2187__Vfuncout)
               : ((2U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x17U])
                   ? ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__dtype 
                            = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU] 
                                     >> 2U));
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__row_stride 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x19U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__col 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q;
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__row 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q;
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__element_offset 
                            = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__dtype))
                                ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__col)), 1U)
                                : ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__col)) 
                                   * VL_EXTEND_QI(64,3, 
                                                  ([&]() {
                                            vlSelfRef.__Vfunc_dtype_bytes__2190__dtype 
                                                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__dtype;
                                            vlSelfRef.__Vfunc_dtype_bytes__2190__Vfuncout 
                                                = (
                                                   (1U 
                                                    == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2190__dtype))
                                                    ? 1U
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2190__dtype))
                                                     ? 4U
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2190__dtype))
                                                      ? 2U
                                                      : 0U)));
                                        }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2190__Vfuncout)))));
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__Vfuncout 
                            = (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__row)) 
                                * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__row_stride))) 
                               + vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__element_offset);
                    }(), vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2189__Vfuncout)
                   : ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__dtype 
                            = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU] 
                                     >> 2U));
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__row_stride 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x19U];
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__col 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__col_q;
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__row 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__k_q;
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__element_offset 
                            = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__dtype))
                                ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__col)), 1U)
                                : ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__col)) 
                                   * VL_EXTEND_QI(64,3, 
                                                  ([&]() {
                                            vlSelfRef.__Vfunc_dtype_bytes__2192__dtype 
                                                = vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__dtype;
                                            vlSelfRef.__Vfunc_dtype_bytes__2192__Vfuncout 
                                                = (
                                                   (1U 
                                                    == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2192__dtype))
                                                    ? 1U
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2192__dtype))
                                                     ? 4U
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2192__dtype))
                                                      ? 2U
                                                      : 0U)));
                                        }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2192__Vfuncout)))));
                        vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__Vfuncout 
                            = (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__row)) 
                                * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__row_stride))) 
                               + vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__element_offset);
                    }(), vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__row_major_offset__2191__Vfuncout))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__prefix_valid 
        = ((((((1U == (0xffU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_flat_q[0U])) 
               & ((0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_flat_q[0U] 
                            >> 8U)) == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__engine_q))) 
              & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_flat_q[0U] 
                  >> 0x10U) == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__expected_desc_bytes))) 
             & (0x40U <= (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_flat_q[0U] 
                          >> 0x10U))) & (0x100U >= 
                                         (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_flat_q[0U] 
                                          >> 0x10U))) 
           & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__engine_q))
               ? (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_flat_q[0xeU])
               : ([&]() {
                    vlSelfRef.__Vfunc_npu_numeric_cfg_valid__2109__cfg 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_descriptor_fetch__DOT__desc_flat_q[0xeU];
                    vlSelfRef.__Vfunc_npu_numeric_cfg_valid__2109__dtype_fields_valid 
                        = (((([&]() {
                                        vlSelfRef.__Vfunc_npu_dtype_valid__2110__dtype 
                                            = (3U & vlSelfRef.__Vfunc_npu_numeric_cfg_valid__2109__cfg);
                                        vlSelfRef.__Vfunc_npu_dtype_valid__2110__Vfuncout 
                                            = ((((0U 
                                                  == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2110__dtype)) 
                                                 | (1U 
                                                    == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2110__dtype))) 
                                                | (2U 
                                                   == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2110__dtype))) 
                                               | (3U 
                                                  == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2110__dtype)));
                                    }(), (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2110__Vfuncout)) 
                             & ([&]() {
                                        vlSelfRef.__Vfunc_npu_dtype_valid__2111__dtype 
                                            = (3U & 
                                               (vlSelfRef.__Vfunc_npu_numeric_cfg_valid__2109__cfg 
                                                >> 2U));
                                        vlSelfRef.__Vfunc_npu_dtype_valid__2111__Vfuncout 
                                            = ((((0U 
                                                  == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2111__dtype)) 
                                                 | (1U 
                                                    == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2111__dtype))) 
                                                | (2U 
                                                   == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2111__dtype))) 
                                               | (3U 
                                                  == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2111__dtype)));
                                    }(), (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2111__Vfuncout))) 
                            & ([&]() {
                                    vlSelfRef.__Vfunc_npu_dtype_valid__2112__dtype 
                                        = (3U & (vlSelfRef.__Vfunc_npu_numeric_cfg_valid__2109__cfg 
                                                 >> 4U));
                                    vlSelfRef.__Vfunc_npu_dtype_valid__2112__Vfuncout 
                                        = ((((0U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2112__dtype)) 
                                             | (1U 
                                                == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2112__dtype))) 
                                            | (2U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2112__dtype))) 
                                           | (3U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2112__dtype)));
                                }(), (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2112__Vfuncout))) 
                           & ([&]() {
                                vlSelfRef.__Vfunc_npu_dtype_valid__2113__dtype 
                                    = (3U & (vlSelfRef.__Vfunc_npu_numeric_cfg_valid__2109__cfg 
                                             >> 6U));
                                vlSelfRef.__Vfunc_npu_dtype_valid__2113__Vfuncout 
                                    = ((((0U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2113__dtype)) 
                                         | (1U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2113__dtype))) 
                                        | (2U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2113__dtype))) 
                                       | (3U == (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2113__dtype)));
                            }(), (IData)(vlSelfRef.__Vfunc_npu_dtype_valid__2113__Vfuncout)));
                    vlSelfRef.__Vfunc_npu_numeric_cfg_valid__2109__Vfuncout 
                        = ((IData)(vlSelfRef.__Vfunc_npu_numeric_cfg_valid__2109__dtype_fields_valid) 
                           & (0U == (0xfffe0300U & vlSelfRef.__Vfunc_npu_numeric_cfg_valid__2109__cfg)));
                }(), (IData)(vlSelfRef.__Vfunc_npu_numeric_cfg_valid__2109__Vfuncout))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____VdfgExtracted_h5b28d49a__0 
        = ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_row 
            * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x18U]))) 
           + (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_col 
              * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__2181__dtype 
                            = (3U & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU]);
                        vlSelfRef.__Vfunc_dtype_bytes__2181__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2181__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2181__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2181__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2181__Vfuncout)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT____VdfgExtracted_hb6bd6506__0 
        = ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_col 
            * (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x1eU]))) 
           + (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transpose_row 
              * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__2182__dtype 
                            = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0xeU] 
                                     >> 6U));
                        vlSelfRef.__Vfunc_dtype_bytes__2182__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2182__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2182__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2182__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2182__Vfuncout)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_status_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_valid_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_valid_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_valid_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_valid_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__feature_only 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__norm_parameter_phase;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                 >> 2U));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__row_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x15U];
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__col 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__row 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[5U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[4U])));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__row_offset 
        = ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__feature_only)
            ? 0ULL : ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__row)) 
                      * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__row_stride))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__col_offset 
        = ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__dtype))
            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__col)), 1U)
            : ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__col)) 
               * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__2338__dtype 
                            = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__2338__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2338__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2338__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2338__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2338__Vfuncout)))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__Vfuncout 
        = ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__base 
            + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__row_offset) 
           + __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__col_offset);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_addr 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2337__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__feature_only 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__norm_parameter_phase;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__dtype 
        = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0xeU] 
                 >> 4U));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__row_stride 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x16U];
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__col 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__col_q;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__row 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__row_q;
    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[7U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[6U])));
    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__row_offset 
        = ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__feature_only)
            ? 0ULL : ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__row)) 
                      * (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__row_stride))));
    vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__col_offset 
        = ((0U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__dtype))
            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__col)), 1U)
            : ((QData)((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__col)) 
               * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__2340__dtype 
                            = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__2340__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2340__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2340__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2340__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__2340__Vfuncout)))));
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__7(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__7\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns_fp;
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__active_columns_fp = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__Vfuncout = 0;
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
    IData/*31:0*/ __Vfunc_fp32_mul__2425__lhs;
    __Vfunc_fp32_mul__2425__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2425__rhs;
    __Vfunc_fp32_mul__2425__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__2425__normalize_count;
    __Vfunc_fp32_mul__2425__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2426__unused_sign;
    __Vfunc_fp32_is_nan__2426__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2427__unused_sign;
    __Vfunc_fp32_is_nan__2427__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2428__unused_sign;
    __Vfunc_fp32_is_inf__2428__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2429__unused_sign;
    __Vfunc_fp32_is_zero__2429__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2430__unused_sign;
    __Vfunc_fp32_is_inf__2430__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2431__unused_sign;
    __Vfunc_fp32_is_zero__2431__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2432__unused_sign;
    __Vfunc_fp32_is_inf__2432__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2433__unused_sign;
    __Vfunc_fp32_is_inf__2433__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2434__unused_sign;
    __Vfunc_fp32_is_zero__2434__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2435__unused_sign;
    __Vfunc_fp32_is_zero__2435__unused_sign = 0;
    CData/*7:0*/ __Vfunc_store_element_strb__2648__Vfuncout;
    __Vfunc_store_element_strb__2648__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_store_element_strb__2648__byte_lane;
    __Vfunc_store_element_strb__2648__byte_lane = 0;
    CData/*1:0*/ __Vfunc_store_element_strb__2648__dtype;
    __Vfunc_store_element_strb__2648__dtype = 0;
    CData/*7:0*/ __Vfunc_store_element_strb__2648__result;
    __Vfunc_store_element_strb__2648__result = 0;
    // Body
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__Vfuncout 
        = ((vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__base 
            + vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__row_offset) 
           + vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__col_offset);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_addr 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__contiguous_element_addr__2339__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr 
        = ((7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))
            ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__stat_dst_addr
            : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__normal_dst_addr);
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
    if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                         >> 8U)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_data 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_data_q
            [1U];
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_status 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
            [1U];
    } else {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_data 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_rdata_q;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__read_rsp_status 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__write_rsp_status 
        = ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                            >> 0x10U))) ? vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_status_q
           [1U] : (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__rsp_status_q));
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__functional_reset_n) {
        if (((1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__tbu_req_ready))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_addr_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_addr_q;
        }
    } else {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_tbu__DOT__rsp_addr_q = 0ULL;
    }
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
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_square 
        = vlSelfRef.__Vfunc_fp32_div__2414__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[3U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[2U]))) 
           + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_offset);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[9U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[8U]))) 
           + vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_offset);
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_addr_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_addr_q;
    __Vfunc_fp32_mul__2425__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean;
    __Vfunc_fp32_mul__2425__lhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean;
    vlSelf->__Vfunc_fp32_mul__2425__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13706289441196013065ull);
    vlSelf->__Vfunc_fp32_mul__2425__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16181479144531634524ull);
    vlSelf->__Vfunc_fp32_mul__2425__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5923235082932919960ull);
    vlSelf->__Vfunc_fp32_mul__2425__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 1243125166700601081ull);
    vlSelf->__Vfunc_fp32_mul__2425__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 8380245393415625386ull);
    vlSelf->__Vfunc_fp32_mul__2425__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13355607362820050559ull);
    vlSelf->__Vfunc_fp32_mul__2425__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13748853482830093108ull);
    vlSelf->__Vfunc_fp32_mul__2425__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 5272402888217514778ull);
    vlSelf->__Vfunc_fp32_mul__2425__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11068574965977406646ull);
    vlSelf->__Vfunc_fp32_mul__2425__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7104586774730884109ull);
    vlSelf->__Vfunc_fp32_mul__2425__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18014721168583176642ull);
    vlSelf->__Vfunc_fp32_mul__2425__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8493055548631120530ull);
    vlSelf->__Vfunc_fp32_mul__2425__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5042039411659964677ull);
    __Vfunc_fp32_mul__2425__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2426__bits 
                                = __Vfunc_fp32_mul__2425__lhs;
                            __Vfunc_fp32_is_nan__2426__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2426__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2426__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2426__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2426__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2426__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2426__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2427__bits 
                                = __Vfunc_fp32_mul__2425__rhs;
                            __Vfunc_fp32_is_nan__2427__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2427__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2427__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2427__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2427__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2427__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2427__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2428__bits 
                                    = __Vfunc_fp32_mul__2425__lhs;
                                __Vfunc_fp32_is_inf__2428__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2428__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2428__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2428__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2428__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2428__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2429__bits 
                                    = __Vfunc_fp32_mul__2425__rhs;
                                __Vfunc_fp32_is_zero__2429__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2429__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2429__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2429__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2429__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2429__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2430__bits 
                                    = __Vfunc_fp32_mul__2425__rhs;
                                __Vfunc_fp32_is_inf__2430__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2430__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2430__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2430__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2430__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2430__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2431__bits 
                                    = __Vfunc_fp32_mul__2425__lhs;
                                __Vfunc_fp32_is_zero__2431__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2431__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2431__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2431__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2431__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2431__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout = 0x7fc00000U;
            goto __Vlabel5;
        }
        vlSelfRef.__Vfunc_fp32_mul__2425__result_sign 
            = ((__Vfunc_fp32_mul__2425__lhs ^ __Vfunc_fp32_mul__2425__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2432__bits 
                            = __Vfunc_fp32_mul__2425__lhs;
                        __Vfunc_fp32_is_inf__2432__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2432__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2432__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2432__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2432__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2432__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2433__bits 
                            = __Vfunc_fp32_mul__2425__rhs;
                        __Vfunc_fp32_is_inf__2433__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2433__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2433__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2433__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2433__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2433__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__result_sign) 
                                  << 0x1fU));
            goto __Vlabel5;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2434__bits 
                            = __Vfunc_fp32_mul__2425__lhs;
                        __Vfunc_fp32_is_zero__2434__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2434__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2434__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2434__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2434__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2434__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2435__bits 
                            = __Vfunc_fp32_mul__2425__rhs;
                        __Vfunc_fp32_is_zero__2435__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2435__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2435__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2435__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2435__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2435__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__result_sign) 
                   << 0x1fU);
            goto __Vlabel5;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2425__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2425__lhs);
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2425__lhs));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2425__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__2425__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__2425__rhs);
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__2425__rhs));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__2425__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__2425__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__2425__normalize_count = 1U;
        __Vfunc_fp32_mul__2425__normalize_count = 2U;
        __Vfunc_fp32_mul__2425__normalize_count = 3U;
        __Vfunc_fp32_mul__2425__normalize_count = 4U;
        __Vfunc_fp32_mul__2425__normalize_count = 5U;
        __Vfunc_fp32_mul__2425__normalize_count = 6U;
        __Vfunc_fp32_mul__2425__normalize_count = 7U;
        __Vfunc_fp32_mul__2425__normalize_count = 8U;
        __Vfunc_fp32_mul__2425__normalize_count = 9U;
        __Vfunc_fp32_mul__2425__normalize_count = 0xaU;
        __Vfunc_fp32_mul__2425__normalize_count = 0xbU;
        __Vfunc_fp32_mul__2425__normalize_count = 0xcU;
        __Vfunc_fp32_mul__2425__normalize_count = 0xdU;
        __Vfunc_fp32_mul__2425__normalize_count = 0xeU;
        __Vfunc_fp32_mul__2425__normalize_count = 0xfU;
        __Vfunc_fp32_mul__2425__normalize_count = 0x10U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x11U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x12U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x13U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x14U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x15U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x16U;
        __Vfunc_fp32_mul__2425__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__2425__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__2425__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__2425__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__2425__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2425__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__2425__mantissa 
            = (0xffffffU & (IData)((0xffffffffffffULL 
                                    & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__2425__product, vlSelfRef.__Vfunc_fp32_mul__2425__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__2425__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__2425__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__2425__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__2425__product 
               & vlSelfRef.__Vfunc_fp32_mul__2425__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__2425__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__2425__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__2425__rounded = vlSelfRef.__Vfunc_fp32_mul__2425__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__2425__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__2425__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__2425__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__2425__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__2425__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__2425__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2425__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__2425__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__2425__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__2425__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__2425__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__2425__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__result_sign) 
                                  << 0x1fU));
            goto __Vlabel5;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__result_sign) 
                   << 0x1fU);
            goto __Vlabel5;
        }
        vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_mul__2425__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_mul__2425__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__2425__mantissa)));
        __Vlabel5: ;
    }
}
