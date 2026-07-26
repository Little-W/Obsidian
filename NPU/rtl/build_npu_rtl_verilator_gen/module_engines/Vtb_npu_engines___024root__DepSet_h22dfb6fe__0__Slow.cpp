// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_engines.h for the primary calling header

#include "Vtb_npu_engines__pch.h"
#include "Vtb_npu_engines___024root.h"

VL_ATTR_COLD void Vtb_npu_engines___024root___eval_static(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_static\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_engines__DOT__clk_i__0 
        = vlSelfRef.tb_npu_engines__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_npu_engines__DOT__reset_n__0 
        = vlSelfRef.tb_npu_engines__DOT__reset_n;
}

VL_ATTR_COLD void Vtb_npu_engines___024root___eval_final(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_final\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_engines___024root___dump_triggers__stl(Vtb_npu_engines___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_npu_engines___024root___eval_phase__stl(Vtb_npu_engines___024root* vlSelf);

VL_ATTR_COLD void Vtb_npu_engines___024root___eval_settle(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_settle\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_npu_engines___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_npu_engines.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_npu_engines___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_npu_engines___024root___dump_triggers__stl(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___dump_triggers__stl\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__0(Vtb_npu_engines___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__1(Vtb_npu_engines___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__2(Vtb_npu_engines___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__3(Vtb_npu_engines___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__4(Vtb_npu_engines___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__5(Vtb_npu_engines___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__6(Vtb_npu_engines___024root* vlSelf);
VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__7(Vtb_npu_engines___024root* vlSelf);

VL_ATTR_COLD void Vtb_npu_engines___024root___eval_stl(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___eval_stl\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_npu_engines___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_npu_engines___024root___stl_sequent__TOP__1(vlSelf);
        Vtb_npu_engines___024root___stl_sequent__TOP__2(vlSelf);
        Vtb_npu_engines___024root___stl_sequent__TOP__3(vlSelf);
        Vtb_npu_engines___024root___stl_sequent__TOP__4(vlSelf);
        Vtb_npu_engines___024root___stl_sequent__TOP__5(vlSelf);
        Vtb_npu_engines___024root___stl_sequent__TOP__6(vlSelf);
        Vtb_npu_engines___024root___stl_sequent__TOP__7(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__0(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___stl_sequent__TOP__0\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__base;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__elem_stride;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__elem_stride = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_stride;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__bcast;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__bcast = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__dtype;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__start_nibble;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__start_nibble = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_offset;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col_offset;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__base;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__elem_stride;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__elem_stride = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_stride;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__bcast;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__bcast = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__dtype;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__start_nibble;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__start_nibble = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_offset;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col_offset;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__base;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__elem_stride;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__elem_stride = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_stride;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__bcast;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__bcast = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__dtype;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__start_nibble;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__start_nibble = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_offset;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col_offset;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__base;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__row;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__col;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__row_stride;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__dtype;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__dtype = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__row_offset;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__col_offset;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__col_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__base;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__row;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__col;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__row_stride;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__dtype;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__dtype = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__row_offset;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__col_offset;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__col_offset = 0;
    QData/*63:0*/ __Vfunc_fp32_from_int__660__value;
    __Vfunc_fp32_from_int__660__value = 0;
    IData/*31:0*/ __Vfunc_fp32_from_int__660__bit_index;
    __Vfunc_fp32_from_int__660__bit_index = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__671__lhs;
    __Vfunc_fp32_mul__671__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__671__rhs;
    __Vfunc_fp32_mul__671__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__671__normalize_count;
    __Vfunc_fp32_mul__671__normalize_count = 0;
    QData/*63:0*/ __Vfunc_fp32_from_int__672__value;
    __Vfunc_fp32_from_int__672__value = 0;
    IData/*31:0*/ __Vfunc_fp32_from_int__672__bit_index;
    __Vfunc_fp32_from_int__672__bit_index = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__673__unused_sign;
    __Vfunc_fp32_is_nan__673__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__674__unused_sign;
    __Vfunc_fp32_is_nan__674__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__675__unused_sign;
    __Vfunc_fp32_is_inf__675__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__676__unused_sign;
    __Vfunc_fp32_is_zero__676__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__677__unused_sign;
    __Vfunc_fp32_is_inf__677__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__678__unused_sign;
    __Vfunc_fp32_is_zero__678__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__679__unused_sign;
    __Vfunc_fp32_is_inf__679__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__680__unused_sign;
    __Vfunc_fp32_is_inf__680__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__681__unused_sign;
    __Vfunc_fp32_is_zero__681__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__682__unused_sign;
    __Vfunc_fp32_is_zero__682__unused_sign = 0;
    // Body
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_dtype 
        = (3U & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0xeU]);
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0xeU] 
                 >> 6U));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[3U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[2U])));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[9U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[8U])));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_space 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                    >> 8U));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_space 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                    >> 0x10U));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_version 
        = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0U]);
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_type 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0U] 
                    >> 8U));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_bytes 
        = (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0U] 
           >> 0x10U);
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__numeric_cfg 
        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0xeU];
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rank 
        = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U]);
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__convert_mode 
        = (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
           >> 0x18U);
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__burst_beats_minus1 
        = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x11U]);
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__max_outstanding 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x11U] 
                    >> 8U));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_nibble 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x11U] 
                 >> 0x18U));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__shape_packed[0U] 
        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x12U];
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__shape_packed[1U] 
        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x13U];
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__shape_packed[2U] 
        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x14U];
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__shape_packed[3U] 
        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x15U];
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__shape_packed[4U] 
        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x16U];
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__fill_value 
        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x24U];
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__src_region_bytes 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x27U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x26U])));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__dst_region_bytes 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x29U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x28U])));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__segment_count 
        = (0xffffU & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x2aU]);
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__segment_bytes 
        = (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x2aU] 
           >> 0x10U);
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__segment_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x2bU];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[3U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[2U])));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_dtype 
        = (3U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU]);
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[5U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[4U])));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU] 
                 >> 2U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_n 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x11U];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__transpose_b 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U] 
                 >> 1U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[9U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[8U])));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU] 
                 >> 6U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__src2_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[7U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[6U])));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_pack_format 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x24U] 
                    >> 8U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_version 
        = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0U]);
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_type 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0U] 
                    >> 8U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_bytes 
        = (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0U] 
           >> 0x10U);
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xbU])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xaU])));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xdU])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xcU])));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__numeric_cfg 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__round_mode 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU] 
                 >> 0xaU));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_m 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x10U];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_k 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x12U];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_count 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x13U];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__last_valid_m 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x14U];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__last_valid_n 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x15U];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__last_valid_k 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x16U];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__matrix_flags 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_stride_bytes 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x1bU];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_pack_format 
        = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x24U]);
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_pack_format 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x24U] 
                    >> 0x10U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__pack_version 
        = (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x24U] 
           >> 0x18U);
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__overflow_mode 
        = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x25U]);
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__activation_mode 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x25U] 
                    >> 8U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__output_zero_point 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x26U];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_count 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x27U];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_count 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x28U];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_mode 
        = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x29U]);
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__residual_mode 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x29U] 
                    >> 8U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_entry_bytes 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x29U] 
                    >> 0x10U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_region_bytes 
        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x2aU];
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__inline_requant 
        = (1U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x2cU]);
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__inline_requant_shift 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x2cU] 
                    >> 8U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_enable 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U] 
                 >> 2U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__residual_enable 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U] 
                 >> 3U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__relu_enable 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U] 
                 >> 4U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_enable 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U] 
                 >> 5U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__accum_from_src2 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U] 
                 >> 6U));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__final_output 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U] 
                 >> 7U));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__broadcast_mode 
        = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU]);
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[3U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[2U])));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_dtype 
        = (3U & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU]);
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[5U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[4U])));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU] 
                 >> 2U));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[7U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[6U])));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU] 
                 >> 4U));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[9U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[8U])));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU] 
                 >> 6U));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_nibble 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU] 
                 >> 0x10U));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_version 
        = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0U]);
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_type 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0U] 
                    >> 8U));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_bytes 
        = (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0U] 
           >> 0x10U);
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xbU])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xaU])));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__numeric_cfg 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU];
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rows 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x10U];
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__length 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x11U];
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__valid_length 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x12U];
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__vector_flags 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x13U];
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar0 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1cU];
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__scalar1 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1dU];
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__compare_mode 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU] 
                    >> 8U));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__overflow_mode 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU] 
                    >> 0x10U));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_mode 
        = (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU] 
           >> 0x18U);
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_elem_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x24U];
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_row_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x25U];
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_enable 
        = (1U & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x13U]);
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_false_keep_dst 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x13U] 
                 >> 1U));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_from_scalar0 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x13U] 
                 >> 2U));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_from_scalar1 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x13U] 
                 >> 3U));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[3U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[2U])));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_dtype 
        = (3U & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU]);
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[5U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[4U])));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                 >> 2U));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[7U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[6U])));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                 >> 4U));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[9U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[8U])));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                 >> 6U));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__input_clip_min_bits 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x25U];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__input_clip_max_bits 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x26U];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__rows 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x10U];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_length 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x12U];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__length 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x11U];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__function_mode 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x13U];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__epsilon_bits 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x24U];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_version 
        = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0U]);
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_type 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0U] 
                    >> 8U));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_bytes 
        = (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0U] 
           >> 0x10U);
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__aux0_addr_high 
        = (0xfffffffffffULL & (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xbU])) 
                                << 0xcU) | ((QData)((IData)(
                                                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xaU])) 
                                            >> 0x14U)));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__aux1_addr_high 
        = (0xfffffffffffULL & (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xdU])) 
                                << 0xcU) | ((QData)((IData)(
                                                            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xcU])) 
                                            >> 0x14U)));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__numeric_cfg 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__saturate_enable 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                 >> 0xcU));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__scale_mode 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                 >> 0xdU));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__zero_point_enable 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                 >> 0xfU));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__internal_fp32_enable 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                 >> 0x10U));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x19U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x18U])));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_row_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1aU];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_mode 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1bU];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_scale_bits 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1cU];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_scale_bits 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1dU];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_scale_bits 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1eU];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_scale_bits 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1fU];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_zero_point 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x20U];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_zero_point 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x21U];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_zero_point 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x22U];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_zero_point 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x23U];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__approx_mode 
        = (0xffU & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x27U]);
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__overflow_mode 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x27U] 
                    >> 8U));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__all_mask_mode 
        = (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x27U] 
                    >> 0x10U));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stats_mode 
        = (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x27U] 
           >> 0x18U);
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__scratch_request_elems 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x2cU];
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_length_base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x31U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x30U])));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__valid_length_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x32U];
    vlSelfRef.tb_npu_engines__DOT__dma_mif_rsp_ready = 0U;
    if ((4U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_mif_rsp_ready = 1U;
        }
    }
    vlSelfRef.tb_npu_engines__DOT__dma_mif_req_valid = 0U;
    if ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_valid = 1U;
        }
    }
    vlSelfRef.tb_npu_engines__DOT__dma_mif_req_write = 0U;
    vlSelfRef.tb_npu_engines__DOT__dma_mif_req_ready 
        = (1U & ((~ (IData)(vlSelfRef.tb_npu_engines__DOT__system_mem_pending_q)) 
                 & vlSelfRef.tb_npu_engines__DOT__cycle_count_q));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_high_nibble 
        = ((0U == (3U & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU])) 
           & (((0U == (3U & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU])) 
               | (3U == (3U & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU])))
               ? (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q 
                  ^ vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU])
               : vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU]));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_high_nibble 
        = (IData)(((0U == (0xcU & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU])) 
                   & (((0U == (3U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU] 
                                     >> 2U))) | (3U 
                                                 == 
                                                 (3U 
                                                  & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU] 
                                                     >> 2U))))
                       ? (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q 
                          ^ (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU] 
                             >> 8U)) : (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU] 
                                        >> 8U))));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_high_nibble 
        = (IData)(((0U == (0x30U & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU])) 
                   & (((0U == (3U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU] 
                                     >> 4U))) | (3U 
                                                 == 
                                                 (3U 
                                                  & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU] 
                                                     >> 4U))))
                       ? (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q 
                          ^ (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU] 
                             >> 0x18U)) : (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU] 
                                           >> 0x18U))));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_high_nibble 
        = ((0U == (3U & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU])) 
           & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q);
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_high_nibble 
        = (IData)(((0U == (0xcU & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU])) 
                   & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_high_nibble 
        = (IData)(((0U == (0x30U & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU])) 
                   & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q));
    if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                         >> 8U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__read_rsp_valid 
            = (1U & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                     >> 1U));
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__read_rsp_data 
            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_data_q
            [1U];
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__read_rsp_status 
            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
            [1U];
    } else {
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__read_rsp_valid 
            = (1U & (IData)(vlSelfRef.tb_npu_engines__DOT__system_mem_pending_q));
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__read_rsp_data 
            = vlSelfRef.tb_npu_engines__DOT__system_mem_rsp_data_q;
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__read_rsp_status 
            = vlSelfRef.tb_npu_engines__DOT__system_mem_rsp_status_q;
    }
    if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                         >> 0x10U)))) {
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__write_rsp_valid 
            = (1U & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_valid_q) 
                     >> 1U));
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__write_rsp_status 
            = vlSelfRef.tb_npu_engines__DOT__u_l1__DOT__rsp_status_q
            [1U];
    } else {
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__write_rsp_valid 
            = (1U & (IData)(vlSelfRef.tb_npu_engines__DOT__system_mem_pending_q));
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__write_rsp_status 
            = vlSelfRef.tb_npu_engines__DOT__system_mem_rsp_status_q;
    }
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_high_nibble 
        = ((0U == (3U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU])) 
           & ((1U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U])
               ? vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__row_q
               : vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__derived_mask_valid 
        = ((0U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1bU]) 
           | ((2U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1bU])
               ? ((vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x2eU] 
                   + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q) 
                  <= (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x2dU] 
                      + (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q 
                         * vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x2fU])))
               : ((3U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1bU])
                   ? (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q 
                      < vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_key_length_q)
                   : (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_value_q))));
    vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_write = 0U;
    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_write = 0U;
    vlSelfRef.tb_npu_engines__DOT__complex_l1_req_write = 0U;
    vlSelfRef.tb_npu_engines__DOT__dma_l1_req_write = 0U;
    if ((6U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_valid = 1U;
        }
    }
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_addr 
        = (0xffffffffffffULL & ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xbU])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xaU]))) 
                                + (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__row_q)) 
                                    * (QData)((IData)(
                                                      vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x25U]))) 
                                   + ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q)) 
                                      * (QData)((IData)(
                                                        vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x24U]))))));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_valid_length_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x31U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x30U]))) 
           + ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q)) 
              * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x32U]))));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__bias_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xbU])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xaU]))) 
           + ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q)) 
              * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x1bU]))));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__requant_addr 
        = (0xffffffffffffULL & ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xdU])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xcU]))) 
                                + ((2U == (0xffU & 
                                           vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x29U]))
                                    ? ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q)) 
                                       << 3U) : 0ULL)));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__mask_addr 
        = (0xffffffffffffULL & ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x19U])) 
                                  << 0x20U) | (QData)((IData)(
                                                              vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x18U]))) 
                                + (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q)) 
                                    * (QData)((IData)(
                                                      vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1aU]))) 
                                   + (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q)))));
    if (((7U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q)) 
         | (9U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q)))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_mif_rsp_ready = 1U;
        }
    }
    if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q) 
                  >> 4U)))) {
        if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                        vlSelfRef.tb_npu_engines__DOT__vector_l1_req_write = 1U;
                    }
                }
            }
        }
    }
    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                        vlSelfRef.tb_npu_engines__DOT__complex_l1_req_write = 1U;
                    }
                }
            }
        }
    }
    if ((8U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_valid = 1U;
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_write = 1U;
        }
        if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_write = 1U;
        }
    }
    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                        vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_write = 1U;
                    }
                }
            }
        }
    }
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__src2_addr 
        = (((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[7U])) 
              << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[6U]))) 
            + ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_q)) 
               * (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x23U])) 
                   << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x22U]))))) 
           + ([&]() {
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__193__row_stride 
                    = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x1aU];
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__193__col 
                    = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__193__row 
                    = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__row_q;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__193__element_offset 
                    = VL_SHIFTL_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__193__col)), 2U);
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__193__Vfuncout 
                    = (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__193__row)) 
                        * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__193__row_stride))) 
                       + vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__193__element_offset);
            }(), vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__193__Vfuncout));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_high_nibble 
        = (IData)(((0U == (0xc0U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU])) 
                   & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q));
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_high_nibble 
        = (IData)(((0U == (0xc0U & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU])) 
                   & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q 
                      ^ (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU] 
                         >> 0x10U))));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__dst_high_nibble 
        = (IData)((((0U == (0xc0U & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU])) 
                    & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q) 
                   & (7U != (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__dtype 
        = (3U & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU]);
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__row_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x14U];
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__col 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__row 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[3U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[2U])));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__row_offset 
        = ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__row)) 
           * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__row_stride)));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__col_offset 
        = ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__dtype))
            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__col)), 1U)
            : ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__col)) 
               * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__334__dtype 
                            = __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__334__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__334__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__334__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__334__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__334__Vfuncout)))));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__Vfuncout 
        = ((__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__base 
            + __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__row_offset) 
           + __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__col_offset);
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_addr 
        = __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__333__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__start_nibble 
        = (1U & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU]);
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__dtype 
        = (3U & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU]);
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__bcast 
        = (3U & vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU]);
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x15U];
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__elem_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x14U];
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__row_q;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[3U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[2U])));
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_offset = 0ULL;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col_offset = 0ULL;
    if ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__bcast))) {
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_offset 
            = ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row)) 
               * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_stride)));
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col_offset 
            = ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__dtype))
                ? VL_SHIFTR_QQI(64,64,32, ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col)) 
                                           + (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__start_nibble))), 1U)
                : ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col)) 
                   * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__elem_stride))));
    } else if ((1U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__bcast))) {
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_offset = 0ULL;
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col_offset = 0ULL;
    } else if ((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__bcast))) {
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_offset 
            = ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row)) 
               * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_stride)));
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col_offset = 0ULL;
    } else {
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_offset = 0ULL;
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col_offset 
            = ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__dtype))
                ? VL_SHIFTR_QQI(64,64,32, ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col)) 
                                           + (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__start_nibble))), 1U)
                : ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col)) 
                   * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__elem_stride))));
    }
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__Vfuncout 
        = ((__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__base 
            + __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__row_offset) 
           + __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__col_offset);
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_addr 
        = __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__264__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__start_nibble 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU] 
                 >> 8U));
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU] 
                 >> 2U));
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__bcast 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU] 
                 >> 2U));
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x17U];
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__elem_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x16U];
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__row_q;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[5U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[4U])));
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_offset = 0ULL;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col_offset = 0ULL;
    if ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__bcast))) {
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_offset 
            = ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row)) 
               * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_stride)));
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col_offset 
            = ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__dtype))
                ? VL_SHIFTR_QQI(64,64,32, ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col)) 
                                           + (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__start_nibble))), 1U)
                : ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col)) 
                   * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__elem_stride))));
    } else if ((1U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__bcast))) {
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_offset = 0ULL;
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col_offset = 0ULL;
    } else if ((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__bcast))) {
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_offset 
            = ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row)) 
               * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_stride)));
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col_offset = 0ULL;
    } else {
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_offset = 0ULL;
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col_offset 
            = ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__dtype))
                ? VL_SHIFTR_QQI(64,64,32, ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col)) 
                                           + (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__start_nibble))), 1U)
                : ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col)) 
                   * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__elem_stride))));
    }
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__Vfuncout 
        = ((__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__base 
            + __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__row_offset) 
           + __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__col_offset);
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_addr 
        = __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__265__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__start_nibble 
        = (1U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU] 
                 >> 0x18U));
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU] 
                 >> 4U));
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__bcast 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1eU] 
                 >> 4U));
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x19U];
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__elem_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x18U];
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row 
        = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__row_q;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[7U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[6U])));
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_offset = 0ULL;
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col_offset = 0ULL;
    if ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__bcast))) {
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_offset 
            = ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row)) 
               * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_stride)));
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col_offset 
            = ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__dtype))
                ? VL_SHIFTR_QQI(64,64,32, ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col)) 
                                           + (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__start_nibble))), 1U)
                : ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col)) 
                   * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__elem_stride))));
    } else if ((1U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__bcast))) {
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_offset = 0ULL;
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col_offset = 0ULL;
    } else if ((2U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__bcast))) {
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_offset 
            = ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row)) 
               * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_stride)));
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col_offset = 0ULL;
    } else {
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_offset = 0ULL;
        __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col_offset 
            = ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__dtype))
                ? VL_SHIFTR_QQI(64,64,32, ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col)) 
                                           + (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__start_nibble))), 1U)
                : ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col)) 
                   * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__elem_stride))));
    }
    __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__Vfuncout 
        = ((__Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__base 
            + __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__row_offset) 
           + __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__col_offset);
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_addr 
        = __Vfunc_tb_npu_engines__DOT__u_vector__DOT__tensor_addr__266__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__a_addr 
        = (((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[3U])) 
              << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[2U]))) 
            + ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_q)) 
               * (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x1dU])) 
                   << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x1cU]))))) 
           + ((1U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U])
               ? ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__dtype 
                        = (3U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU]);
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__row_stride 
                        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x18U];
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__col 
                        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__row_q;
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__row 
                        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q;
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__element_offset 
                        = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__dtype))
                            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__col)), 1U)
                            : ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__col)) 
                               * VL_EXTEND_QI(64,3, 
                                              ([&]() {
                                        vlSelfRef.__Vfunc_dtype_bytes__182__dtype 
                                            = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__dtype;
                                        vlSelfRef.__Vfunc_dtype_bytes__182__Vfuncout 
                                            = ((1U 
                                                == (IData)(vlSelfRef.__Vfunc_dtype_bytes__182__dtype))
                                                ? 1U
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelfRef.__Vfunc_dtype_bytes__182__dtype))
                                                    ? 4U
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlSelfRef.__Vfunc_dtype_bytes__182__dtype))
                                                     ? 2U
                                                     : 0U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__182__Vfuncout)))));
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__Vfuncout 
                        = (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__row)) 
                            * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__row_stride))) 
                           + vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__element_offset);
                }(), vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__181__Vfuncout)
               : ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__dtype 
                        = (3U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU]);
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__row_stride 
                        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x18U];
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__col 
                        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q;
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__row 
                        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__row_q;
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__element_offset 
                        = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__dtype))
                            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__col)), 1U)
                            : ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__col)) 
                               * VL_EXTEND_QI(64,3, 
                                              ([&]() {
                                        vlSelfRef.__Vfunc_dtype_bytes__184__dtype 
                                            = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__dtype;
                                        vlSelfRef.__Vfunc_dtype_bytes__184__Vfuncout 
                                            = ((1U 
                                                == (IData)(vlSelfRef.__Vfunc_dtype_bytes__184__dtype))
                                                ? 1U
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelfRef.__Vfunc_dtype_bytes__184__dtype))
                                                    ? 4U
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlSelfRef.__Vfunc_dtype_bytes__184__dtype))
                                                     ? 2U
                                                     : 0U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__184__Vfuncout)))));
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__Vfuncout 
                        = (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__row)) 
                            * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__row_stride))) 
                           + vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__element_offset);
                }(), vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__183__Vfuncout)));
    vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 0U;
    vlSelfRef.tb_npu_engines__DOT__vector_l1_rsp_ready = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q)))) {
                        vlSelfRef.tb_npu_engines__DOT__vector_l1_rsp_ready = 1U;
                    }
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q)))) {
                    vlSelfRef.tb_npu_engines__DOT__vector_l1_rsp_ready = 1U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                vlSelfRef.tb_npu_engines__DOT__vector_l1_rsp_ready = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            vlSelfRef.tb_npu_engines__DOT__vector_l1_rsp_ready = 1U;
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                vlSelfRef.tb_npu_engines__DOT__vector_l1_rsp_ready = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            vlSelfRef.tb_npu_engines__DOT__vector_l1_rsp_ready = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            vlSelfRef.tb_npu_engines__DOT__vector_l1_rsp_ready = 1U;
        }
    }
    vlSelfRef.tb_npu_engines__DOT__complex_l1_rsp_ready = 0U;
    vlSelfRef.tb_npu_engines__DOT__dma_l1_rsp_ready = 0U;
    if ((4U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_l1_rsp_ready = 1U;
        }
    }
    if (((7U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q)) 
         | (9U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q)))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_l1_rsp_ready = 1U;
        }
    }
    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_valid = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q) 
                  >> 4U)))) {
        if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                        vlSelfRef.tb_npu_engines__DOT__vector_l1_req_valid = 1U;
                    }
                } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_valid = 1U;
                }
            } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q)))) {
                    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_valid = 1U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__vector_l1_req_valid = 1U;
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q)))) {
                    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_valid = 1U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__vector_l1_req_valid = 1U;
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__vector_l1_req_valid = 1U;
            }
        }
    }
    vlSelfRef.tb_npu_engines__DOT__complex_l1_req_valid = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                        vlSelfRef.tb_npu_engines__DOT__complex_l1_rsp_ready = 1U;
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                        vlSelfRef.tb_npu_engines__DOT__complex_l1_req_valid = 1U;
                    }
                } else {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                        vlSelfRef.tb_npu_engines__DOT__complex_l1_rsp_ready = 1U;
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                        vlSelfRef.tb_npu_engines__DOT__complex_l1_req_valid = 1U;
                    }
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                    vlSelfRef.tb_npu_engines__DOT__complex_l1_rsp_ready = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                    vlSelfRef.tb_npu_engines__DOT__complex_l1_req_valid = 1U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                vlSelfRef.tb_npu_engines__DOT__complex_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__complex_l1_req_valid = 1U;
            }
        } else {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                vlSelfRef.tb_npu_engines__DOT__complex_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__complex_l1_req_valid = 1U;
            }
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                vlSelfRef.tb_npu_engines__DOT__complex_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__complex_l1_req_valid = 1U;
            }
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
            vlSelfRef.tb_npu_engines__DOT__complex_l1_rsp_ready = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
            vlSelfRef.tb_npu_engines__DOT__complex_l1_req_valid = 1U;
        }
    }
    vlSelfRef.tb_npu_engines__DOT__dma_l1_req_valid = 0U;
    if ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_valid = 1U;
        }
    }
    if ((6U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_valid = 1U;
        }
    }
    if ((8U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_valid = 1U;
        }
    }
    vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_valid = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
                        vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
                    }
                } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
                    vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
                }
                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                        vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_valid = 1U;
                    }
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                    vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
                }
            }
            if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                    vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_valid = 1U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
                if ((1U & (~ vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x2cU]))) {
                    vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_valid = 1U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_valid = 1U;
            }
        } else {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_valid = 1U;
            }
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
            }
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q)))) {
            vlSelfRef.tb_npu_engines__DOT__matrix_l1_rsp_ready = 1U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_valid = 1U;
            }
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
            vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_valid = 1U;
        }
    }
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[9U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[8U]))) 
           + (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__row_q)) 
               * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1bU]))) 
              + ((0U == (3U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU] 
                               >> 6U))) ? VL_SHIFTR_QQI(64,64,32, 
                                                        ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q)) 
                                                         + (QData)((IData)(
                                                                           (1U 
                                                                            & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1fU] 
                                                                               >> 0x10U))))), 1U)
                  : ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__col_q)) 
                     * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0x1aU]))))));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_dst_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[9U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[8U]))) 
           + ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q)) 
              * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x17U]))));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_addr 
        = (((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[9U])) 
              << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[8U]))) 
            + ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_q)) 
               * (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x21U])) 
                   << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x20U]))))) 
           + ([&]() {
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__dtype 
                    = (3U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU] 
                             >> 6U));
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__row_stride 
                    = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x1aU];
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__col 
                    = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__row 
                    = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__row_q;
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__element_offset 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__dtype))
                        ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__col)), 1U)
                        : ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__col)) 
                           * VL_EXTEND_QI(64,3, ([&]() {
                                    vlSelfRef.__Vfunc_dtype_bytes__192__dtype 
                                        = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__dtype;
                                    vlSelfRef.__Vfunc_dtype_bytes__192__Vfuncout 
                                        = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__192__dtype))
                                            ? 1U : 
                                           ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__192__dtype))
                                             ? 4U : 
                                            ((3U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__192__dtype))
                                              ? 2U : 0U)));
                                }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__192__Vfuncout)))));
                vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__Vfuncout 
                    = (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__row)) 
                        * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__row_stride))) 
                       + vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__element_offset);
            }(), vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__191__Vfuncout));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__norm_parameter_phase 
        = ((0x82U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
           & (5U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q)));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_is_tiled 
        = ((2U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x24U] 
                            >> 8U))) | ((3U == (0xffU 
                                                & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x24U] 
                                                   >> 8U))) 
                                        | (6U == (0xffU 
                                                  & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x24U] 
                                                     >> 8U)))));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                 >> 6U));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__row_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x17U];
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__col 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__row 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[9U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[8U])));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__row_offset 
        = ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__row)) 
           * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__row_stride)));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__col_offset 
        = ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__dtype))
            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__col)), 1U)
            : ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__col)) 
               * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__340__dtype 
                            = __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__340__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__340__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__340__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__340__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__340__Vfuncout)))));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__Vfuncout 
        = ((__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__base 
            + __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__row_offset) 
           + __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__col_offset);
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__normal_dst_addr 
        = __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__339__Vfuncout;
    __Vfunc_fp32_mul__671__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1eU];
    __Vfunc_fp32_from_int__672__value = (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_value_q 
                                         - (((QData)((IData)(
                                                             (- (IData)(
                                                                        (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x22U] 
                                                                         >> 0x1fU))))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x22U]))));
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_from_int__672__sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11839793722633218479ull);
    vlSelf->__Vfunc_fp32_from_int__672__magnitude = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3295382876577815236ull);
    vlSelf->__Vfunc_fp32_from_int__672__shifted_significand = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16251142839174000500ull);
    vlSelf->__Vfunc_fp32_from_int__672__remainder_mask = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4400997944154714337ull);
    vlSelf->__Vfunc_fp32_from_int__672__remainder = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17621614913286255898ull);
    vlSelf->__Vfunc_fp32_from_int__672__halfway = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12957922792967733317ull);
    vlSelf->__Vfunc_fp32_from_int__672__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 16378674997916921891ull);
    vlSelf->__Vfunc_fp32_from_int__672__fraction = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 13804236616085599059ull);
    vlSelf->__Vfunc_fp32_from_int__672__exponent = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 11439490388968097984ull);
    vlSelf->__Vfunc_fp32_from_int__672__leading_bit = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12677322761832318923ull);
    vlSelf->__Vfunc_fp32_from_int__672__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5159378178163397925ull);
    __Vfunc_fp32_from_int__672__bit_index = 0;
    {
        if ((0ULL == __Vfunc_fp32_from_int__672__value)) {
            vlSelfRef.__Vfunc_fp32_from_int__672__Vfuncout = 0U;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_from_int__672__sign 
            = (1U & (IData)((__Vfunc_fp32_from_int__672__value 
                             >> 0x3fU)));
        vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
            = ((IData)(vlSelfRef.__Vfunc_fp32_from_int__672__sign)
                ? (1ULL + (~ __Vfunc_fp32_from_int__672__value))
                : __Vfunc_fp32_from_int__672__value);
        vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0U;
        __Vfunc_fp32_from_int__672__bit_index = 0U;
        if ((1U & (IData)(vlSelfRef.__Vfunc_fp32_from_int__672__magnitude))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 1U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 1U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 1U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 2U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 2U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 2U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 3U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 3U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 3U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 4U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 4U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 4U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 5U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 5U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 5U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 6U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 6U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 6U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 7U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 7U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 7U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 8U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 8U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 8U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 9U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 9U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 9U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0xaU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0xaU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0xaU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0xbU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0xbU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0xbU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0xcU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0xcU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0xcU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0xdU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0xdU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0xdU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0xeU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0xeU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0xeU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0xfU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0xfU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0xfU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x10U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x10U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x10U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x11U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x11U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x11U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x12U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x12U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x12U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x13U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x13U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x13U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x14U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x14U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x14U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x15U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x15U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x15U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x16U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x16U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x16U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x17U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x17U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x18U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x18U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x18U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x19U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x19U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x19U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x1aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x1aU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x1bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x1bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x1bU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x1cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x1cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x1cU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x1dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x1dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x1dU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x1eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x1eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x1eU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x1fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x1fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x1fU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x20U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x20U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x20U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x21U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x21U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x21U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x22U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x22U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x22U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x23U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x23U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x23U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x24U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x24U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x24U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x25U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x25U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x25U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x26U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x26U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x26U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x27U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x27U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x27U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x28U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x28U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x28U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x29U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x29U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x29U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x2aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x2aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x2aU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x2bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x2bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x2bU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x2cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x2cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x2cU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x2dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x2dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x2dU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x2eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x2eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x2eU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x2fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x2fU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x30U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x30U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x30U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x31U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x31U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x31U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x32U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x32U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x32U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x33U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x33U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x33U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x34U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x34U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x34U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x35U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x35U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x35U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x36U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x36U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x36U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x37U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x37U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x37U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x38U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x38U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x38U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x39U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x39U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x39U;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x3aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x3aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x3aU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x3bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x3bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x3bU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x3cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x3cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x3cU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x3dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x3dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x3dU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x3eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x3eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x3eU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x3fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                           >> 0x3fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit = 0x3fU;
        }
        __Vfunc_fp32_from_int__672__bit_index = 0x40U;
        vlSelfRef.__Vfunc_fp32_from_int__672__exponent 
            = (0x1ffU & ((IData)(0x7fU) + vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit));
        if (VL_GTES_III(32, 0x17U, vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit)) {
            vlSelfRef.__Vfunc_fp32_from_int__672__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTL_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__672__magnitude, 
                                                     ((IData)(0x17U) 
                                                      - vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit))));
            vlSelfRef.__Vfunc_fp32_from_int__672__fraction 
                = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__672__shifted_significand);
        } else {
            vlSelfRef.__Vfunc_fp32_from_int__672__shift_amount 
                = (vlSelfRef.__Vfunc_fp32_from_int__672__leading_bit 
                   - (IData)(0x17U));
            vlSelfRef.__Vfunc_fp32_from_int__672__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTR_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__672__magnitude, vlSelfRef.__Vfunc_fp32_from_int__672__shift_amount)));
            vlSelfRef.__Vfunc_fp32_from_int__672__remainder_mask 
                = (VL_SHIFTL_QQI(64,64,32, 1ULL, vlSelfRef.__Vfunc_fp32_from_int__672__shift_amount) 
                   - 1ULL);
            vlSelfRef.__Vfunc_fp32_from_int__672__remainder 
                = (vlSelfRef.__Vfunc_fp32_from_int__672__magnitude 
                   & vlSelfRef.__Vfunc_fp32_from_int__672__remainder_mask);
            vlSelfRef.__Vfunc_fp32_from_int__672__halfway 
                = VL_SHIFTL_QQI(64,64,32, 1ULL, (vlSelfRef.__Vfunc_fp32_from_int__672__shift_amount 
                                                 - (IData)(1U)));
            vlSelfRef.__Vfunc_fp32_from_int__672__rounded 
                = vlSelfRef.__Vfunc_fp32_from_int__672__shifted_significand;
            if (((vlSelfRef.__Vfunc_fp32_from_int__672__remainder 
                  > vlSelfRef.__Vfunc_fp32_from_int__672__halfway) 
                 | ((vlSelfRef.__Vfunc_fp32_from_int__672__remainder 
                     == vlSelfRef.__Vfunc_fp32_from_int__672__halfway) 
                    & vlSelfRef.__Vfunc_fp32_from_int__672__shifted_significand))) {
                vlSelfRef.__Vfunc_fp32_from_int__672__rounded 
                    = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_from_int__672__rounded));
            }
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_from_int__672__rounded)) {
                vlSelfRef.__Vfunc_fp32_from_int__672__fraction 
                    = (0x7fffffU & (vlSelfRef.__Vfunc_fp32_from_int__672__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_from_int__672__exponent 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_from_int__672__exponent)));
            } else {
                vlSelfRef.__Vfunc_fp32_from_int__672__fraction 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__672__rounded);
            }
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_from_int__672__exponent))) {
            vlSelfRef.__Vfunc_fp32_from_int__672__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_from_int__672__sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_from_int__672__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_from_int__672__sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_from_int__672__exponent) 
                                             << 0x17U)) 
                             | vlSelfRef.__Vfunc_fp32_from_int__672__fraction));
        __Vlabel0: ;
    }
    __Vfunc_fp32_mul__671__lhs = vlSelfRef.__Vfunc_fp32_from_int__672__Vfuncout;
    vlSelf->__Vfunc_fp32_mul__671__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11465536711149945019ull);
    vlSelf->__Vfunc_fp32_mul__671__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13949263418625190313ull);
    vlSelf->__Vfunc_fp32_mul__671__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2857944405548535766ull);
    vlSelf->__Vfunc_fp32_mul__671__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 12570107786326675701ull);
    vlSelf->__Vfunc_fp32_mul__671__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 10076809148685929158ull);
    vlSelf->__Vfunc_fp32_mul__671__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 3396769063153041250ull);
    vlSelf->__Vfunc_fp32_mul__671__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 10575659549029253482ull);
    vlSelf->__Vfunc_fp32_mul__671__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 8607958918107934624ull);
    vlSelf->__Vfunc_fp32_mul__671__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12977075489876719188ull);
    vlSelf->__Vfunc_fp32_mul__671__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10517553596513772186ull);
    vlSelf->__Vfunc_fp32_mul__671__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 719931551392671010ull);
    vlSelf->__Vfunc_fp32_mul__671__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13888811138151311634ull);
    vlSelf->__Vfunc_fp32_mul__671__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1533046896799866443ull);
    __Vfunc_fp32_mul__671__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__673__bits 
                                = __Vfunc_fp32_mul__671__lhs;
                            __Vfunc_fp32_is_nan__673__unused_sign = 0;
                            __Vfunc_fp32_is_nan__673__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__673__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__673__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__673__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__673__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__673__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__674__bits 
                                = __Vfunc_fp32_mul__671__rhs;
                            __Vfunc_fp32_is_nan__674__unused_sign = 0;
                            __Vfunc_fp32_is_nan__674__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__674__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__674__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__674__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__674__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__674__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__675__bits 
                                    = __Vfunc_fp32_mul__671__lhs;
                                __Vfunc_fp32_is_inf__675__unused_sign = 0;
                                __Vfunc_fp32_is_inf__675__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__675__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__675__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__675__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__675__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__676__bits 
                                    = __Vfunc_fp32_mul__671__rhs;
                                __Vfunc_fp32_is_zero__676__unused_sign = 0;
                                __Vfunc_fp32_is_zero__676__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__676__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__676__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__676__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__676__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__677__bits 
                                    = __Vfunc_fp32_mul__671__rhs;
                                __Vfunc_fp32_is_inf__677__unused_sign = 0;
                                __Vfunc_fp32_is_inf__677__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__677__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__677__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__677__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__677__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__678__bits 
                                    = __Vfunc_fp32_mul__671__lhs;
                                __Vfunc_fp32_is_zero__678__unused_sign = 0;
                                __Vfunc_fp32_is_zero__678__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__678__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__678__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__678__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__678__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__671__Vfuncout = 0x7fc00000U;
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_mul__671__result_sign 
            = ((__Vfunc_fp32_mul__671__lhs ^ __Vfunc_fp32_mul__671__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__679__bits 
                            = __Vfunc_fp32_mul__671__lhs;
                        __Vfunc_fp32_is_inf__679__unused_sign = 0;
                        __Vfunc_fp32_is_inf__679__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__679__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__679__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__679__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__679__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__680__bits 
                            = __Vfunc_fp32_mul__671__rhs;
                        __Vfunc_fp32_is_inf__680__unused_sign = 0;
                        __Vfunc_fp32_is_inf__680__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__680__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__680__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__680__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__680__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__671__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__681__bits 
                            = __Vfunc_fp32_mul__671__lhs;
                        __Vfunc_fp32_is_zero__681__unused_sign = 0;
                        __Vfunc_fp32_is_zero__681__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__681__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__681__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__681__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__681__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__682__bits 
                            = __Vfunc_fp32_mul__671__rhs;
                        __Vfunc_fp32_is_zero__682__unused_sign = 0;
                        __Vfunc_fp32_is_zero__682__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__682__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__682__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__682__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__682__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__671__result_sign) 
                   << 0x1fU);
            goto __Vlabel1;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__671__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__671__lhs);
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__671__lhs));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__671__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__671__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__671__rhs);
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__671__rhs));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__671__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__671__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__671__normalize_count = 1U;
        __Vfunc_fp32_mul__671__normalize_count = 2U;
        __Vfunc_fp32_mul__671__normalize_count = 3U;
        __Vfunc_fp32_mul__671__normalize_count = 4U;
        __Vfunc_fp32_mul__671__normalize_count = 5U;
        __Vfunc_fp32_mul__671__normalize_count = 6U;
        __Vfunc_fp32_mul__671__normalize_count = 7U;
        __Vfunc_fp32_mul__671__normalize_count = 8U;
        __Vfunc_fp32_mul__671__normalize_count = 9U;
        __Vfunc_fp32_mul__671__normalize_count = 0xaU;
        __Vfunc_fp32_mul__671__normalize_count = 0xbU;
        __Vfunc_fp32_mul__671__normalize_count = 0xcU;
        __Vfunc_fp32_mul__671__normalize_count = 0xdU;
        __Vfunc_fp32_mul__671__normalize_count = 0xeU;
        __Vfunc_fp32_mul__671__normalize_count = 0xfU;
        __Vfunc_fp32_mul__671__normalize_count = 0x10U;
        __Vfunc_fp32_mul__671__normalize_count = 0x11U;
        __Vfunc_fp32_mul__671__normalize_count = 0x12U;
        __Vfunc_fp32_mul__671__normalize_count = 0x13U;
        __Vfunc_fp32_mul__671__normalize_count = 0x14U;
        __Vfunc_fp32_mul__671__normalize_count = 0x15U;
        __Vfunc_fp32_mul__671__normalize_count = 0x16U;
        __Vfunc_fp32_mul__671__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__671__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__671__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__671__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__671__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__671__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__671__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__671__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__671__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__671__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__671__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__671__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__671__mantissa = 
            (0xffffffU & (IData)((0xffffffffffffULL 
                                  & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__671__product, vlSelfRef.__Vfunc_fp32_mul__671__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__671__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__671__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__671__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__671__product 
               & vlSelfRef.__Vfunc_fp32_mul__671__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__671__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__671__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__671__rounded = vlSelfRef.__Vfunc_fp32_mul__671__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__671__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__671__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__671__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__671__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__671__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__671__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__671__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__671__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__671__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__671__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__671__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__671__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__671__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__671__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__671__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__671__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__671__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__671__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__671__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__671__result_sign) 
                   << 0x1fU);
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_mul__671__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_mul__671__result_sign) 
              << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                            + vlSelfRef.__Vfunc_fp32_mul__671__result_unbiased) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__671__mantissa)));
        __Vlabel1: ;
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_fp 
        = vlSelfRef.__Vfunc_fp32_mul__671__Vfuncout;
    vlSelfRef.__Vfunc_fp32_mul__659__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1dU];
    __Vfunc_fp32_from_int__660__value = (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_value_q 
                                         - (((QData)((IData)(
                                                             (- (IData)(
                                                                        (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x21U] 
                                                                         >> 0x1fU))))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x21U]))));
    vlSelf->__Vfunc_fp32_from_int__660__sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 766250134184504500ull);
    vlSelf->__Vfunc_fp32_from_int__660__magnitude = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17958339958515521717ull);
    vlSelf->__Vfunc_fp32_from_int__660__shifted_significand = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2803294027334004544ull);
    vlSelf->__Vfunc_fp32_from_int__660__remainder_mask = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 3542033427299937152ull);
    vlSelf->__Vfunc_fp32_from_int__660__remainder = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14582282974280237232ull);
    vlSelf->__Vfunc_fp32_from_int__660__halfway = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8554098798654014677ull);
    vlSelf->__Vfunc_fp32_from_int__660__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6708800850190844053ull);
    vlSelf->__Vfunc_fp32_from_int__660__fraction = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 16952837878041552661ull);
    vlSelf->__Vfunc_fp32_from_int__660__exponent = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 9458206207572195404ull);
    vlSelf->__Vfunc_fp32_from_int__660__leading_bit = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 839606533652279432ull);
    vlSelf->__Vfunc_fp32_from_int__660__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13437777593102582787ull);
    __Vfunc_fp32_from_int__660__bit_index = 0;
    {
        if ((0ULL == __Vfunc_fp32_from_int__660__value)) {
            vlSelfRef.__Vfunc_fp32_from_int__660__Vfuncout = 0U;
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_from_int__660__sign 
            = (1U & (IData)((__Vfunc_fp32_from_int__660__value 
                             >> 0x3fU)));
        vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
            = ((IData)(vlSelfRef.__Vfunc_fp32_from_int__660__sign)
                ? (1ULL + (~ __Vfunc_fp32_from_int__660__value))
                : __Vfunc_fp32_from_int__660__value);
        vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0U;
        __Vfunc_fp32_from_int__660__bit_index = 0U;
        if ((1U & (IData)(vlSelfRef.__Vfunc_fp32_from_int__660__magnitude))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 1U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 1U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 1U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 2U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 2U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 2U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 3U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 3U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 3U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 4U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 4U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 4U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 5U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 5U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 5U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 6U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 6U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 6U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 7U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 7U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 7U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 8U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 8U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 8U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 9U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 9U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 9U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0xaU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0xaU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0xaU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0xbU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0xbU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0xbU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0xcU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0xcU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0xcU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0xdU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0xdU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0xdU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0xeU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0xeU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0xeU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0xfU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0xfU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0xfU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x10U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x10U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x10U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x11U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x11U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x11U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x12U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x12U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x12U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x13U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x13U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x13U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x14U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x14U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x14U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x15U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x15U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x15U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x16U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x16U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x16U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x17U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x17U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x18U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x18U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x18U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x19U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x19U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x19U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x1aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x1aU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x1bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x1bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x1bU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x1cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x1cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x1cU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x1dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x1dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x1dU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x1eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x1eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x1eU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x1fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x1fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x1fU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x20U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x20U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x20U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x21U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x21U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x21U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x22U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x22U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x22U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x23U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x23U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x23U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x24U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x24U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x24U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x25U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x25U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x25U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x26U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x26U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x26U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x27U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x27U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x27U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x28U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x28U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x28U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x29U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x29U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x29U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x2aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x2aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x2aU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x2bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x2bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x2bU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x2cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x2cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x2cU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x2dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x2dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x2dU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x2eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x2eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x2eU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x2fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x2fU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x30U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x30U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x30U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x31U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x31U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x31U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x32U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x32U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x32U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x33U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x33U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x33U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x34U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x34U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x34U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x35U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x35U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x35U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x36U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x36U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x36U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x37U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x37U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x37U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x38U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x38U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x38U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x39U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x39U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x39U;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x3aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x3aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x3aU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x3bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x3bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x3bU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x3cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x3cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x3cU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x3dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x3dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x3dU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x3eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x3eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x3eU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x3fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                           >> 0x3fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit = 0x3fU;
        }
        __Vfunc_fp32_from_int__660__bit_index = 0x40U;
        vlSelfRef.__Vfunc_fp32_from_int__660__exponent 
            = (0x1ffU & ((IData)(0x7fU) + vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit));
        if (VL_GTES_III(32, 0x17U, vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit)) {
            vlSelfRef.__Vfunc_fp32_from_int__660__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTL_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__660__magnitude, 
                                                     ((IData)(0x17U) 
                                                      - vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit))));
            vlSelfRef.__Vfunc_fp32_from_int__660__fraction 
                = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__660__shifted_significand);
        } else {
            vlSelfRef.__Vfunc_fp32_from_int__660__shift_amount 
                = (vlSelfRef.__Vfunc_fp32_from_int__660__leading_bit 
                   - (IData)(0x17U));
            vlSelfRef.__Vfunc_fp32_from_int__660__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTR_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__660__magnitude, vlSelfRef.__Vfunc_fp32_from_int__660__shift_amount)));
            vlSelfRef.__Vfunc_fp32_from_int__660__remainder_mask 
                = (VL_SHIFTL_QQI(64,64,32, 1ULL, vlSelfRef.__Vfunc_fp32_from_int__660__shift_amount) 
                   - 1ULL);
            vlSelfRef.__Vfunc_fp32_from_int__660__remainder 
                = (vlSelfRef.__Vfunc_fp32_from_int__660__magnitude 
                   & vlSelfRef.__Vfunc_fp32_from_int__660__remainder_mask);
            vlSelfRef.__Vfunc_fp32_from_int__660__halfway 
                = VL_SHIFTL_QQI(64,64,32, 1ULL, (vlSelfRef.__Vfunc_fp32_from_int__660__shift_amount 
                                                 - (IData)(1U)));
            vlSelfRef.__Vfunc_fp32_from_int__660__rounded 
                = vlSelfRef.__Vfunc_fp32_from_int__660__shifted_significand;
            if (((vlSelfRef.__Vfunc_fp32_from_int__660__remainder 
                  > vlSelfRef.__Vfunc_fp32_from_int__660__halfway) 
                 | ((vlSelfRef.__Vfunc_fp32_from_int__660__remainder 
                     == vlSelfRef.__Vfunc_fp32_from_int__660__halfway) 
                    & vlSelfRef.__Vfunc_fp32_from_int__660__shifted_significand))) {
                vlSelfRef.__Vfunc_fp32_from_int__660__rounded 
                    = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_from_int__660__rounded));
            }
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_from_int__660__rounded)) {
                vlSelfRef.__Vfunc_fp32_from_int__660__fraction 
                    = (0x7fffffU & (vlSelfRef.__Vfunc_fp32_from_int__660__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_from_int__660__exponent 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_from_int__660__exponent)));
            } else {
                vlSelfRef.__Vfunc_fp32_from_int__660__fraction 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__660__rounded);
            }
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_from_int__660__exponent))) {
            vlSelfRef.__Vfunc_fp32_from_int__660__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_from_int__660__sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_from_int__660__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_from_int__660__sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_from_int__660__exponent) 
                                             << 0x17U)) 
                             | vlSelfRef.__Vfunc_fp32_from_int__660__fraction));
        __Vlabel2: ;
    }
}

VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__1(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___stl_sequent__TOP__1\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vfunc_store_element_strb__263__Vfuncout;
    __Vfunc_store_element_strb__263__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_store_element_strb__263__byte_lane;
    __Vfunc_store_element_strb__263__byte_lane = 0;
    CData/*1:0*/ __Vfunc_store_element_strb__263__dtype;
    __Vfunc_store_element_strb__263__dtype = 0;
    CData/*7:0*/ __Vfunc_store_element_strb__263__result;
    __Vfunc_store_element_strb__263__result = 0;
    CData/*7:0*/ __Vfunc_store_element_strb__332__Vfuncout;
    __Vfunc_store_element_strb__332__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_store_element_strb__332__byte_lane;
    __Vfunc_store_element_strb__332__byte_lane = 0;
    CData/*1:0*/ __Vfunc_store_element_strb__332__dtype;
    __Vfunc_store_element_strb__332__dtype = 0;
    CData/*7:0*/ __Vfunc_store_element_strb__332__result;
    __Vfunc_store_element_strb__332__result = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__base;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__row;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__col;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__row_stride;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__dtype;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__feature_only;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__feature_only = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__row_offset;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__col_offset;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__col_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__base;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__base = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__row;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__row = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__col;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__col = 0;
    IData/*31:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__row_stride;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__row_stride = 0;
    CData/*1:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__dtype;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__dtype = 0;
    CData/*0:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__feature_only;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__feature_only = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__row_offset;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__row_offset = 0;
    QData/*63:0*/ __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__col_offset;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__col_offset = 0;
    QData/*63:0*/ __Vfunc_fp32_from_int__369__value;
    __Vfunc_fp32_from_int__369__value = 0;
    IData/*31:0*/ __Vfunc_fp32_from_int__369__bit_index;
    __Vfunc_fp32_from_int__369__bit_index = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__647__lhs;
    __Vfunc_fp32_mul__647__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__647__rhs;
    __Vfunc_fp32_mul__647__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__647__normalize_count;
    __Vfunc_fp32_mul__647__normalize_count = 0;
    QData/*63:0*/ __Vfunc_fp32_from_int__648__value;
    __Vfunc_fp32_from_int__648__value = 0;
    IData/*31:0*/ __Vfunc_fp32_from_int__648__bit_index;
    __Vfunc_fp32_from_int__648__bit_index = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__649__unused_sign;
    __Vfunc_fp32_is_nan__649__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__650__unused_sign;
    __Vfunc_fp32_is_nan__650__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__651__unused_sign;
    __Vfunc_fp32_is_inf__651__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__652__unused_sign;
    __Vfunc_fp32_is_zero__652__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__653__unused_sign;
    __Vfunc_fp32_is_inf__653__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__654__unused_sign;
    __Vfunc_fp32_is_zero__654__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__655__unused_sign;
    __Vfunc_fp32_is_inf__655__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__656__unused_sign;
    __Vfunc_fp32_is_inf__656__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__657__unused_sign;
    __Vfunc_fp32_is_zero__657__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__658__unused_sign;
    __Vfunc_fp32_is_zero__658__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__659__lhs;
    __Vfunc_fp32_mul__659__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__659__normalize_count;
    __Vfunc_fp32_mul__659__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__661__unused_sign;
    __Vfunc_fp32_is_nan__661__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__662__unused_sign;
    __Vfunc_fp32_is_nan__662__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__663__unused_sign;
    __Vfunc_fp32_is_inf__663__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__664__unused_sign;
    __Vfunc_fp32_is_zero__664__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__665__unused_sign;
    __Vfunc_fp32_is_inf__665__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__666__unused_sign;
    __Vfunc_fp32_is_zero__666__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__667__unused_sign;
    __Vfunc_fp32_is_inf__667__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__668__unused_sign;
    __Vfunc_fp32_is_inf__668__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__669__unused_sign;
    __Vfunc_fp32_is_zero__669__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__670__unused_sign;
    __Vfunc_fp32_is_zero__670__unused_sign = 0;
    // Body
    __Vfunc_fp32_mul__659__lhs = vlSelfRef.__Vfunc_fp32_from_int__660__Vfuncout;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_mul__659__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5556640097464962239ull);
    vlSelf->__Vfunc_fp32_mul__659__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10996983391800853660ull);
    vlSelf->__Vfunc_fp32_mul__659__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12752940717459049236ull);
    vlSelf->__Vfunc_fp32_mul__659__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 9873614985155460746ull);
    vlSelf->__Vfunc_fp32_mul__659__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 5813480043651147708ull);
    vlSelf->__Vfunc_fp32_mul__659__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 18420792511065234939ull);
    vlSelf->__Vfunc_fp32_mul__659__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 6715669783972341096ull);
    vlSelf->__Vfunc_fp32_mul__659__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 10371234200361064577ull);
    vlSelf->__Vfunc_fp32_mul__659__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16219347520149817055ull);
    vlSelf->__Vfunc_fp32_mul__659__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13264670073951569430ull);
    vlSelf->__Vfunc_fp32_mul__659__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15531950594772376776ull);
    vlSelf->__Vfunc_fp32_mul__659__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7116425552940196002ull);
    vlSelf->__Vfunc_fp32_mul__659__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16614607446947191298ull);
    __Vfunc_fp32_mul__659__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__661__bits 
                                = __Vfunc_fp32_mul__659__lhs;
                            __Vfunc_fp32_is_nan__661__unused_sign = 0;
                            __Vfunc_fp32_is_nan__661__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__661__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__661__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__661__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__661__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__661__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__662__bits 
                                = vlSelfRef.__Vfunc_fp32_mul__659__rhs;
                            __Vfunc_fp32_is_nan__662__unused_sign = 0;
                            __Vfunc_fp32_is_nan__662__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__662__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__662__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__662__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__662__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__662__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__663__bits 
                                    = __Vfunc_fp32_mul__659__lhs;
                                __Vfunc_fp32_is_inf__663__unused_sign = 0;
                                __Vfunc_fp32_is_inf__663__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__663__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__663__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__663__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__663__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__664__bits 
                                    = vlSelfRef.__Vfunc_fp32_mul__659__rhs;
                                __Vfunc_fp32_is_zero__664__unused_sign = 0;
                                __Vfunc_fp32_is_zero__664__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__664__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__664__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__664__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__664__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__665__bits 
                                    = vlSelfRef.__Vfunc_fp32_mul__659__rhs;
                                __Vfunc_fp32_is_inf__665__unused_sign = 0;
                                __Vfunc_fp32_is_inf__665__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__665__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__665__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__665__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__665__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__666__bits 
                                    = __Vfunc_fp32_mul__659__lhs;
                                __Vfunc_fp32_is_zero__666__unused_sign = 0;
                                __Vfunc_fp32_is_zero__666__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__666__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__666__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__666__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__666__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__659__Vfuncout = 0x7fc00000U;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_mul__659__result_sign 
            = ((__Vfunc_fp32_mul__659__lhs ^ vlSelfRef.__Vfunc_fp32_mul__659__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__667__bits 
                            = __Vfunc_fp32_mul__659__lhs;
                        __Vfunc_fp32_is_inf__667__unused_sign = 0;
                        __Vfunc_fp32_is_inf__667__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__667__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__667__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__667__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__667__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__668__bits 
                            = vlSelfRef.__Vfunc_fp32_mul__659__rhs;
                        __Vfunc_fp32_is_inf__668__unused_sign = 0;
                        __Vfunc_fp32_is_inf__668__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__668__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__668__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__668__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__668__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__659__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__669__bits 
                            = __Vfunc_fp32_mul__659__lhs;
                        __Vfunc_fp32_is_zero__669__unused_sign = 0;
                        __Vfunc_fp32_is_zero__669__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__669__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__669__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__669__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__669__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__670__bits 
                            = vlSelfRef.__Vfunc_fp32_mul__659__rhs;
                        __Vfunc_fp32_is_zero__670__unused_sign = 0;
                        __Vfunc_fp32_is_zero__670__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__670__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__670__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__670__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__670__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__659__result_sign) 
                   << 0x1fU);
            goto __Vlabel0;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__659__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__659__lhs);
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__659__lhs));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__659__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (vlSelfRef.__Vfunc_fp32_mul__659__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__659__rhs);
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0x800000U | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__659__rhs));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = ((0xffU & (vlSelfRef.__Vfunc_fp32_mul__659__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__659__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__659__normalize_count = 1U;
        __Vfunc_fp32_mul__659__normalize_count = 2U;
        __Vfunc_fp32_mul__659__normalize_count = 3U;
        __Vfunc_fp32_mul__659__normalize_count = 4U;
        __Vfunc_fp32_mul__659__normalize_count = 5U;
        __Vfunc_fp32_mul__659__normalize_count = 6U;
        __Vfunc_fp32_mul__659__normalize_count = 7U;
        __Vfunc_fp32_mul__659__normalize_count = 8U;
        __Vfunc_fp32_mul__659__normalize_count = 9U;
        __Vfunc_fp32_mul__659__normalize_count = 0xaU;
        __Vfunc_fp32_mul__659__normalize_count = 0xbU;
        __Vfunc_fp32_mul__659__normalize_count = 0xcU;
        __Vfunc_fp32_mul__659__normalize_count = 0xdU;
        __Vfunc_fp32_mul__659__normalize_count = 0xeU;
        __Vfunc_fp32_mul__659__normalize_count = 0xfU;
        __Vfunc_fp32_mul__659__normalize_count = 0x10U;
        __Vfunc_fp32_mul__659__normalize_count = 0x11U;
        __Vfunc_fp32_mul__659__normalize_count = 0x12U;
        __Vfunc_fp32_mul__659__normalize_count = 0x13U;
        __Vfunc_fp32_mul__659__normalize_count = 0x14U;
        __Vfunc_fp32_mul__659__normalize_count = 0x15U;
        __Vfunc_fp32_mul__659__normalize_count = 0x16U;
        __Vfunc_fp32_mul__659__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__659__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__659__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__659__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__659__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__659__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__659__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__659__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__659__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__659__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__659__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__659__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__659__mantissa = 
            (0xffffffU & (IData)((0xffffffffffffULL 
                                  & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__659__product, vlSelfRef.__Vfunc_fp32_mul__659__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__659__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__659__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__659__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__659__product 
               & vlSelfRef.__Vfunc_fp32_mul__659__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__659__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__659__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__659__rounded = vlSelfRef.__Vfunc_fp32_mul__659__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__659__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__659__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__659__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__659__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__659__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__659__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__659__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__659__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__659__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__659__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__659__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__659__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__659__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__659__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__659__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__659__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__659__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__659__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__659__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__659__result_sign) 
                   << 0x1fU);
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_mul__659__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_mul__659__result_sign) 
              << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                            + vlSelfRef.__Vfunc_fp32_mul__659__result_unbiased) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__659__mantissa)));
        __Vlabel0: ;
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_fp 
        = vlSelfRef.__Vfunc_fp32_mul__659__Vfuncout;
    if ((0U == vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x13U])) {
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_col = 0ULL;
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_row = 0ULL;
    } else {
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_col 
            = VL_MODDIV_QQQ(64, vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q, (QData)((IData)(
                                                                                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x13U])));
        vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_row 
            = VL_DIV_QQQ(64, vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__linear_index_q, (QData)((IData)(
                                                                                vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x13U])));
    }
    __Vfunc_fp32_mul__647__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1cU];
    __Vfunc_fp32_from_int__648__value = (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_value_q 
                                         - (((QData)((IData)(
                                                             (- (IData)(
                                                                        (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x20U] 
                                                                         >> 0x1fU))))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x20U]))));
    vlSelf->__Vfunc_fp32_from_int__648__sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13147877128517759742ull);
    vlSelf->__Vfunc_fp32_from_int__648__magnitude = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16450089809491068471ull);
    vlSelf->__Vfunc_fp32_from_int__648__shifted_significand = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5412526829371428689ull);
    vlSelf->__Vfunc_fp32_from_int__648__remainder_mask = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8250656553594435078ull);
    vlSelf->__Vfunc_fp32_from_int__648__remainder = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7753444310787891857ull);
    vlSelf->__Vfunc_fp32_from_int__648__halfway = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17648160853079745985ull);
    vlSelf->__Vfunc_fp32_from_int__648__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 14588365872802989145ull);
    vlSelf->__Vfunc_fp32_from_int__648__fraction = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 7972413404211415674ull);
    vlSelf->__Vfunc_fp32_from_int__648__exponent = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 12529824809639990733ull);
    vlSelf->__Vfunc_fp32_from_int__648__leading_bit = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2821750201152029150ull);
    vlSelf->__Vfunc_fp32_from_int__648__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1071610291280708026ull);
    __Vfunc_fp32_from_int__648__bit_index = 0;
    {
        if ((0ULL == __Vfunc_fp32_from_int__648__value)) {
            vlSelfRef.__Vfunc_fp32_from_int__648__Vfuncout = 0U;
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_from_int__648__sign 
            = (1U & (IData)((__Vfunc_fp32_from_int__648__value 
                             >> 0x3fU)));
        vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
            = ((IData)(vlSelfRef.__Vfunc_fp32_from_int__648__sign)
                ? (1ULL + (~ __Vfunc_fp32_from_int__648__value))
                : __Vfunc_fp32_from_int__648__value);
        vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0U;
        __Vfunc_fp32_from_int__648__bit_index = 0U;
        if ((1U & (IData)(vlSelfRef.__Vfunc_fp32_from_int__648__magnitude))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 1U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 1U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 1U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 2U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 2U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 2U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 3U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 3U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 3U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 4U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 4U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 4U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 5U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 5U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 5U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 6U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 6U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 6U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 7U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 7U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 7U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 8U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 8U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 8U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 9U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 9U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 9U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0xaU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0xaU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0xaU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0xbU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0xbU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0xbU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0xcU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0xcU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0xcU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0xdU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0xdU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0xdU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0xeU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0xeU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0xeU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0xfU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0xfU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0xfU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x10U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x10U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x10U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x11U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x11U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x11U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x12U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x12U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x12U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x13U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x13U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x13U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x14U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x14U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x14U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x15U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x15U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x15U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x16U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x16U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x16U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x17U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x17U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x18U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x18U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x18U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x19U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x19U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x19U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x1aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x1aU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x1bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x1bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x1bU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x1cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x1cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x1cU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x1dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x1dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x1dU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x1eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x1eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x1eU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x1fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x1fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x1fU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x20U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x20U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x20U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x21U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x21U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x21U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x22U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x22U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x22U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x23U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x23U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x23U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x24U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x24U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x24U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x25U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x25U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x25U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x26U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x26U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x26U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x27U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x27U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x27U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x28U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x28U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x28U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x29U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x29U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x29U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x2aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x2aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x2aU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x2bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x2bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x2bU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x2cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x2cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x2cU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x2dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x2dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x2dU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x2eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x2eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x2eU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x2fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x2fU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x30U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x30U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x30U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x31U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x31U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x31U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x32U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x32U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x32U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x33U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x33U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x33U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x34U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x34U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x34U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x35U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x35U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x35U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x36U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x36U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x36U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x37U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x37U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x37U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x38U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x38U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x38U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x39U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x39U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x39U;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x3aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x3aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x3aU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x3bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x3bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x3bU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x3cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x3cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x3cU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x3dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x3dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x3dU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x3eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x3eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x3eU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x3fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                           >> 0x3fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit = 0x3fU;
        }
        __Vfunc_fp32_from_int__648__bit_index = 0x40U;
        vlSelfRef.__Vfunc_fp32_from_int__648__exponent 
            = (0x1ffU & ((IData)(0x7fU) + vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit));
        if (VL_GTES_III(32, 0x17U, vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit)) {
            vlSelfRef.__Vfunc_fp32_from_int__648__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTL_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__648__magnitude, 
                                                     ((IData)(0x17U) 
                                                      - vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit))));
            vlSelfRef.__Vfunc_fp32_from_int__648__fraction 
                = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__648__shifted_significand);
        } else {
            vlSelfRef.__Vfunc_fp32_from_int__648__shift_amount 
                = (vlSelfRef.__Vfunc_fp32_from_int__648__leading_bit 
                   - (IData)(0x17U));
            vlSelfRef.__Vfunc_fp32_from_int__648__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTR_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__648__magnitude, vlSelfRef.__Vfunc_fp32_from_int__648__shift_amount)));
            vlSelfRef.__Vfunc_fp32_from_int__648__remainder_mask 
                = (VL_SHIFTL_QQI(64,64,32, 1ULL, vlSelfRef.__Vfunc_fp32_from_int__648__shift_amount) 
                   - 1ULL);
            vlSelfRef.__Vfunc_fp32_from_int__648__remainder 
                = (vlSelfRef.__Vfunc_fp32_from_int__648__magnitude 
                   & vlSelfRef.__Vfunc_fp32_from_int__648__remainder_mask);
            vlSelfRef.__Vfunc_fp32_from_int__648__halfway 
                = VL_SHIFTL_QQI(64,64,32, 1ULL, (vlSelfRef.__Vfunc_fp32_from_int__648__shift_amount 
                                                 - (IData)(1U)));
            vlSelfRef.__Vfunc_fp32_from_int__648__rounded 
                = vlSelfRef.__Vfunc_fp32_from_int__648__shifted_significand;
            if (((vlSelfRef.__Vfunc_fp32_from_int__648__remainder 
                  > vlSelfRef.__Vfunc_fp32_from_int__648__halfway) 
                 | ((vlSelfRef.__Vfunc_fp32_from_int__648__remainder 
                     == vlSelfRef.__Vfunc_fp32_from_int__648__halfway) 
                    & vlSelfRef.__Vfunc_fp32_from_int__648__shifted_significand))) {
                vlSelfRef.__Vfunc_fp32_from_int__648__rounded 
                    = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_from_int__648__rounded));
            }
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_from_int__648__rounded)) {
                vlSelfRef.__Vfunc_fp32_from_int__648__fraction 
                    = (0x7fffffU & (vlSelfRef.__Vfunc_fp32_from_int__648__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_from_int__648__exponent 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_from_int__648__exponent)));
            } else {
                vlSelfRef.__Vfunc_fp32_from_int__648__fraction 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__648__rounded);
            }
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_from_int__648__exponent))) {
            vlSelfRef.__Vfunc_fp32_from_int__648__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_from_int__648__sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_from_int__648__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_from_int__648__sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_from_int__648__exponent) 
                                             << 0x17U)) 
                             | vlSelfRef.__Vfunc_fp32_from_int__648__fraction));
        __Vlabel1: ;
    }
    __Vfunc_fp32_mul__647__lhs = vlSelfRef.__Vfunc_fp32_from_int__648__Vfuncout;
    vlSelf->__Vfunc_fp32_mul__647__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17862559598082857449ull);
    vlSelf->__Vfunc_fp32_mul__647__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 3844116300687516188ull);
    vlSelf->__Vfunc_fp32_mul__647__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15609819489899575261ull);
    vlSelf->__Vfunc_fp32_mul__647__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13811947521459502611ull);
    vlSelf->__Vfunc_fp32_mul__647__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13841349511073938026ull);
    vlSelf->__Vfunc_fp32_mul__647__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 3721034390141796694ull);
    vlSelf->__Vfunc_fp32_mul__647__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 14605484092834807459ull);
    vlSelf->__Vfunc_fp32_mul__647__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 12111209421234545900ull);
    vlSelf->__Vfunc_fp32_mul__647__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10015169480400165697ull);
    vlSelf->__Vfunc_fp32_mul__647__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11868506362567305522ull);
    vlSelf->__Vfunc_fp32_mul__647__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 202459537975493343ull);
    vlSelf->__Vfunc_fp32_mul__647__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6844228583573536469ull);
    vlSelf->__Vfunc_fp32_mul__647__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16386926698111360965ull);
    __Vfunc_fp32_mul__647__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__649__bits 
                                = __Vfunc_fp32_mul__647__lhs;
                            __Vfunc_fp32_is_nan__649__unused_sign = 0;
                            __Vfunc_fp32_is_nan__649__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__649__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__649__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__649__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__649__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__649__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__650__bits 
                                = __Vfunc_fp32_mul__647__rhs;
                            __Vfunc_fp32_is_nan__650__unused_sign = 0;
                            __Vfunc_fp32_is_nan__650__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__650__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__650__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__650__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__650__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__650__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__651__bits 
                                    = __Vfunc_fp32_mul__647__lhs;
                                __Vfunc_fp32_is_inf__651__unused_sign = 0;
                                __Vfunc_fp32_is_inf__651__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__651__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__651__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__651__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__651__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__652__bits 
                                    = __Vfunc_fp32_mul__647__rhs;
                                __Vfunc_fp32_is_zero__652__unused_sign = 0;
                                __Vfunc_fp32_is_zero__652__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__652__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__652__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__652__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__652__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__653__bits 
                                    = __Vfunc_fp32_mul__647__rhs;
                                __Vfunc_fp32_is_inf__653__unused_sign = 0;
                                __Vfunc_fp32_is_inf__653__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__653__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__653__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__653__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__653__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__654__bits 
                                    = __Vfunc_fp32_mul__647__lhs;
                                __Vfunc_fp32_is_zero__654__unused_sign = 0;
                                __Vfunc_fp32_is_zero__654__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__654__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__654__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__654__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__654__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__647__Vfuncout = 0x7fc00000U;
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_mul__647__result_sign 
            = ((__Vfunc_fp32_mul__647__lhs ^ __Vfunc_fp32_mul__647__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__655__bits 
                            = __Vfunc_fp32_mul__647__lhs;
                        __Vfunc_fp32_is_inf__655__unused_sign = 0;
                        __Vfunc_fp32_is_inf__655__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__655__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__655__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__655__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__655__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__656__bits 
                            = __Vfunc_fp32_mul__647__rhs;
                        __Vfunc_fp32_is_inf__656__unused_sign = 0;
                        __Vfunc_fp32_is_inf__656__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__656__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__656__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__656__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__656__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__647__result_sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__657__bits 
                            = __Vfunc_fp32_mul__647__lhs;
                        __Vfunc_fp32_is_zero__657__unused_sign = 0;
                        __Vfunc_fp32_is_zero__657__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__657__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__657__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__657__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__657__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__658__bits 
                            = __Vfunc_fp32_mul__647__rhs;
                        __Vfunc_fp32_is_zero__658__unused_sign = 0;
                        __Vfunc_fp32_is_zero__658__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__658__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__658__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__658__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__658__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__647__result_sign) 
                   << 0x1fU);
            goto __Vlabel2;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__647__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__647__lhs);
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__647__lhs));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__647__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__647__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__647__rhs);
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__647__rhs));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__647__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__647__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__647__normalize_count = 1U;
        __Vfunc_fp32_mul__647__normalize_count = 2U;
        __Vfunc_fp32_mul__647__normalize_count = 3U;
        __Vfunc_fp32_mul__647__normalize_count = 4U;
        __Vfunc_fp32_mul__647__normalize_count = 5U;
        __Vfunc_fp32_mul__647__normalize_count = 6U;
        __Vfunc_fp32_mul__647__normalize_count = 7U;
        __Vfunc_fp32_mul__647__normalize_count = 8U;
        __Vfunc_fp32_mul__647__normalize_count = 9U;
        __Vfunc_fp32_mul__647__normalize_count = 0xaU;
        __Vfunc_fp32_mul__647__normalize_count = 0xbU;
        __Vfunc_fp32_mul__647__normalize_count = 0xcU;
        __Vfunc_fp32_mul__647__normalize_count = 0xdU;
        __Vfunc_fp32_mul__647__normalize_count = 0xeU;
        __Vfunc_fp32_mul__647__normalize_count = 0xfU;
        __Vfunc_fp32_mul__647__normalize_count = 0x10U;
        __Vfunc_fp32_mul__647__normalize_count = 0x11U;
        __Vfunc_fp32_mul__647__normalize_count = 0x12U;
        __Vfunc_fp32_mul__647__normalize_count = 0x13U;
        __Vfunc_fp32_mul__647__normalize_count = 0x14U;
        __Vfunc_fp32_mul__647__normalize_count = 0x15U;
        __Vfunc_fp32_mul__647__normalize_count = 0x16U;
        __Vfunc_fp32_mul__647__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__647__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__647__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__647__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__647__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__647__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__647__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__647__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__647__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__647__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__647__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__647__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__647__mantissa = 
            (0xffffffU & (IData)((0xffffffffffffULL 
                                  & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__647__product, vlSelfRef.__Vfunc_fp32_mul__647__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__647__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__647__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__647__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__647__product 
               & vlSelfRef.__Vfunc_fp32_mul__647__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__647__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__647__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__647__rounded = vlSelfRef.__Vfunc_fp32_mul__647__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__647__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__647__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__647__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__647__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__647__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__647__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__647__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__647__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__647__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__647__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__647__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__647__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__647__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__647__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__647__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__647__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__647__result_sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__647__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__647__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__647__result_sign) 
                   << 0x1fU);
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_mul__647__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_mul__647__result_sign) 
              << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                            + vlSelfRef.__Vfunc_fp32_mul__647__result_unbiased) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__647__mantissa)));
        __Vlabel2: ;
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_fp 
        = vlSelfRef.__Vfunc_fp32_mul__647__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__active_columns 
        = ((((IData)(1U) + vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q) 
            == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x10U])
            ? vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x12U]
            : vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x11U]);
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
    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr = 0U;
    __Vfunc_store_element_strb__332__dtype = (3U & 
                                              (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU] 
                                               >> 6U));
    __Vfunc_store_element_strb__332__byte_lane = (7U 
                                                  & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr));
    __Vfunc_store_element_strb__332__result = 0U;
    __Vfunc_store_element_strb__332__result = ((2U 
                                                & (IData)(__Vfunc_store_element_strb__332__dtype))
                                                ? (0xffU 
                                                   & ((1U 
                                                       & (IData)(__Vfunc_store_element_strb__332__dtype))
                                                       ? 
                                                      ((IData)(3U) 
                                                       << (IData)(__Vfunc_store_element_strb__332__byte_lane))
                                                       : 
                                                      ((IData)(0xfU) 
                                                       << (IData)(__Vfunc_store_element_strb__332__byte_lane))))
                                                : ((IData)(__Vfunc_store_element_strb__332__result) 
                                                   | (0xffU 
                                                      & ((IData)(1U) 
                                                         << (IData)(__Vfunc_store_element_strb__332__byte_lane)))));
    __Vfunc_store_element_strb__332__Vfuncout = __Vfunc_store_element_strb__332__result;
    vlSelfRef.tb_npu_engines__DOT__u_vector__DOT____VdfgExtracted_ha467d4d5__0 
        = __Vfunc_store_element_strb__332__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_wdata = 0ULL;
    if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q) 
                  >> 4U)))) {
        if ((8U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                        vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr 
                            = (0xffff8U & ((IData)(
                                                   (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr 
                                                    >> 3U)) 
                                           << 3U));
                        vlSelfRef.__Vfunc_store_element_data__272__dtype 
                            = (3U & (vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__desc_q[0xeU] 
                                     >> 6U));
                        vlSelfRef.__Vfunc_store_element_data__272__high_nibble 
                            = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_high_nibble;
                        vlSelfRef.__Vfunc_store_element_data__272__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr));
                        vlSelfRef.__Vfunc_store_element_data__272__value 
                            = (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__result_q);
                        vlSelfRef.__Vfunc_store_element_data__272__old_beat 
                            = vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__rmw_beat_q;
                        vlSelf->__Vfunc_store_element_data__272__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17056586097333170904ull);
                        vlSelfRef.__Vfunc_store_element_data__272__result 
                            = vlSelfRef.__Vfunc_store_element_data__272__old_beat;
                        if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__272__dtype))) {
                            vlSelfRef.__Vfunc_store_element_data__272__result 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__272__dtype))
                                    ? (((~ (0xffffULL 
                                            << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__272__byte_lane), 3U)))) 
                                        & vlSelfRef.__Vfunc_store_element_data__272__result) 
                                       | ((QData)((IData)(
                                                          (0xffffU 
                                                           & vlSelfRef.__Vfunc_store_element_data__272__value))) 
                                          << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__272__byte_lane), 3U))))
                                    : (((~ (0xffffffffULL 
                                            << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__272__byte_lane), 3U)))) 
                                        & vlSelfRef.__Vfunc_store_element_data__272__result) 
                                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__272__value)) 
                                          << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__272__byte_lane), 3U)))));
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__272__dtype))) {
                            vlSelfRef.__Vfunc_store_element_data__272__result 
                                = (((~ (0xffULL << 
                                        (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__272__byte_lane), 3U)))) 
                                    & vlSelfRef.__Vfunc_store_element_data__272__result) 
                                   | ((QData)((IData)(
                                                      (0xffU 
                                                       & vlSelfRef.__Vfunc_store_element_data__272__value))) 
                                      << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__272__byte_lane), 3U))));
                        } else {
                            vlSelfRef.__Vfunc_store_element_data__272__byte_value 
                                = (0xffU & (IData)(
                                                   (vlSelfRef.__Vfunc_store_element_data__272__old_beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__272__byte_lane), 3U)))));
                            vlSelfRef.__Vfunc_store_element_data__272__byte_value 
                                = ((IData)(vlSelfRef.__Vfunc_store_element_data__272__high_nibble)
                                    ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__272__byte_value)) 
                                       | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__272__value 
                                                   << 4U)))
                                    : ((0xf0U & (IData)(vlSelfRef.__Vfunc_store_element_data__272__byte_value)) 
                                       | (0xfU & vlSelfRef.__Vfunc_store_element_data__272__value)));
                            vlSelfRef.__Vfunc_store_element_data__272__result 
                                = (((~ (0xffULL << 
                                        (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__272__byte_lane), 3U)))) 
                                    & vlSelfRef.__Vfunc_store_element_data__272__result) 
                                   | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__272__byte_value)) 
                                      << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__272__byte_lane), 3U))));
                        }
                        vlSelfRef.__Vfunc_store_element_data__272__Vfuncout 
                            = vlSelfRef.__Vfunc_store_element_data__272__result;
                        vlSelfRef.tb_npu_engines__DOT__vector_l1_req_wdata 
                            = vlSelfRef.__Vfunc_store_element_data__272__Vfuncout;
                    }
                } else if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q)))) {
                    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__dst_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src2_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q)))) {
                    vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src1_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__src0_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__state_q)))) {
                vlSelfRef.tb_npu_engines__DOT__vector_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_vector__DOT__mask_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        }
    }
    __Vfunc_store_element_strb__263__dtype = (3U & 
                                              (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU] 
                                               >> 6U));
    __Vfunc_store_element_strb__263__byte_lane = (7U 
                                                  & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_addr));
    __Vfunc_store_element_strb__263__result = 0U;
    __Vfunc_store_element_strb__263__result = ((2U 
                                                & (IData)(__Vfunc_store_element_strb__263__dtype))
                                                ? (0xffU 
                                                   & ((1U 
                                                       & (IData)(__Vfunc_store_element_strb__263__dtype))
                                                       ? 
                                                      ((IData)(3U) 
                                                       << (IData)(__Vfunc_store_element_strb__263__byte_lane))
                                                       : 
                                                      ((IData)(0xfU) 
                                                       << (IData)(__Vfunc_store_element_strb__263__byte_lane))))
                                                : ((IData)(__Vfunc_store_element_strb__263__result) 
                                                   | (0xffU 
                                                      & ((IData)(1U) 
                                                         << (IData)(__Vfunc_store_element_strb__263__byte_lane)))));
    __Vfunc_store_element_strb__263__Vfuncout = __Vfunc_store_element_strb__263__result;
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT____VdfgExtracted_h8e2aa811__0 
        = __Vfunc_store_element_strb__263__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_wdata = 0ULL;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__state_q))) {
                        vlSelfRef.__Vfunc_store_element_data__196__dtype 
                            = (3U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU] 
                                     >> 6U));
                        vlSelfRef.__Vfunc_store_element_data__196__high_nibble 
                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_high_nibble;
                        vlSelfRef.__Vfunc_store_element_data__196__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__c_addr));
                        vlSelfRef.__Vfunc_store_element_data__196__value 
                            = (IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__result_q);
                        vlSelfRef.__Vfunc_store_element_data__196__old_beat 
                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__rmw_beat_q;
                        vlSelf->__Vfunc_store_element_data__196__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12504068879939596126ull);
                        vlSelfRef.__Vfunc_store_element_data__196__result 
                            = vlSelfRef.__Vfunc_store_element_data__196__old_beat;
                        if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__196__dtype))) {
                            vlSelfRef.__Vfunc_store_element_data__196__result 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__196__dtype))
                                    ? (((~ (0xffffULL 
                                            << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__196__byte_lane), 3U)))) 
                                        & vlSelfRef.__Vfunc_store_element_data__196__result) 
                                       | ((QData)((IData)(
                                                          (0xffffU 
                                                           & vlSelfRef.__Vfunc_store_element_data__196__value))) 
                                          << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__196__byte_lane), 3U))))
                                    : (((~ (0xffffffffULL 
                                            << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__196__byte_lane), 3U)))) 
                                        & vlSelfRef.__Vfunc_store_element_data__196__result) 
                                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__196__value)) 
                                          << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__196__byte_lane), 3U)))));
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__196__dtype))) {
                            vlSelfRef.__Vfunc_store_element_data__196__result 
                                = (((~ (0xffULL << 
                                        (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__196__byte_lane), 3U)))) 
                                    & vlSelfRef.__Vfunc_store_element_data__196__result) 
                                   | ((QData)((IData)(
                                                      (0xffU 
                                                       & vlSelfRef.__Vfunc_store_element_data__196__value))) 
                                      << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__196__byte_lane), 3U))));
                        } else {
                            vlSelfRef.__Vfunc_store_element_data__196__byte_value 
                                = (0xffU & (IData)(
                                                   (vlSelfRef.__Vfunc_store_element_data__196__old_beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__196__byte_lane), 3U)))));
                            vlSelfRef.__Vfunc_store_element_data__196__byte_value 
                                = ((IData)(vlSelfRef.__Vfunc_store_element_data__196__high_nibble)
                                    ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__196__byte_value)) 
                                       | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__196__value 
                                                   << 4U)))
                                    : ((0xf0U & (IData)(vlSelfRef.__Vfunc_store_element_data__196__byte_value)) 
                                       | (0xfU & vlSelfRef.__Vfunc_store_element_data__196__value)));
                            vlSelfRef.__Vfunc_store_element_data__196__result 
                                = (((~ (0xffULL << 
                                        (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__196__byte_lane), 3U)))) 
                                    & vlSelfRef.__Vfunc_store_element_data__196__result) 
                                   | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__196__byte_value)) 
                                      << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__196__byte_lane), 3U))));
                        }
                        vlSelfRef.__Vfunc_store_element_data__196__Vfuncout 
                            = vlSelfRef.__Vfunc_store_element_data__196__result;
                        vlSelfRef.tb_npu_engines__DOT__matrix_l1_req_wdata 
                            = vlSelfRef.__Vfunc_store_element_data__196__Vfuncout;
                    }
                }
            }
        }
    }
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__feature_only 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__norm_parameter_phase;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                 >> 2U));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__row_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x15U];
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__col 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__row 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[5U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[4U])));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__row_offset 
        = ((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__feature_only)
            ? 0ULL : ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__row)) 
                      * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__row_stride))));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__col_offset 
        = ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__dtype))
            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__col)), 1U)
            : ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__col)) 
               * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__336__dtype 
                            = __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__336__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__336__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__336__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__336__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__336__Vfuncout)))));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__Vfuncout 
        = ((__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__base 
            + __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__row_offset) 
           + __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__col_offset);
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_addr 
        = __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__335__Vfuncout;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__feature_only 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__norm_parameter_phase;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__dtype 
        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                 >> 4U));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__row_stride 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x16U];
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__col 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__col_q;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__row 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__row_q;
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__base 
        = (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[7U])) 
            << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[6U])));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__row_offset 
        = ((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__feature_only)
            ? 0ULL : ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__row)) 
                      * (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__row_stride))));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__col_offset 
        = ((0U == (IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__dtype))
            ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__col)), 1U)
            : ((QData)((IData)(__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__col)) 
               * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__338__dtype 
                            = __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__338__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__338__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__338__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__338__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__338__Vfuncout)))));
    __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__Vfuncout 
        = ((__Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__base 
            + __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__row_offset) 
           + __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__col_offset);
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_addr 
        = __Vfunc_tb_npu_engines__DOT__u_complex__DOT__contiguous_element_addr__337__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_high_nibble 
        = (IData)(((0U == (0xcU & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU])) 
                   & ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_is_tiled)
                       ? ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_high_nibble__195__n_index_odd 
                            = (1U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q);
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_high_nibble__195__Vfuncout 
                            = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_high_nibble__195__n_index_odd;
                    }(), (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_high_nibble__195__Vfuncout))
                       : ((2U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U])
                           ? vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q
                           : vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q))));
    vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_addr 
        = (((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[5U])) 
              << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[4U]))) 
            + ((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__batch_q)) 
               * (((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x1fU])) 
                   << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x1eU]))))) 
           + ((IData)(vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__b_is_tiled)
               ? ([&]() {
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__dtype 
                        = (3U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU] 
                                 >> 2U));
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_size 
                        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x11U];
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_index 
                        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q;
                    vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__k_index 
                        = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q;
                    vlSelf->__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__k_outer = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13065878852387948382ull);
                    vlSelf->__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_outer = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18110680136399295176ull);
                    vlSelf->__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__k_inner = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2395164726156317194ull);
                    vlSelf->__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_inner = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2156865817709929265ull);
                    vlSelf->__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_tiles = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15670928037392025406ull);
                    vlSelf->__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__element_index = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1168445636481012771ull);
                    {
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__k_outer 
                            = VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__k_index, 4U);
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_outer 
                            = VL_SHIFTR_III(32,32,32, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_index, 3U);
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__k_inner 
                            = (0xfU & vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__k_index);
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_inner 
                            = (7U & vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_index);
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_tiles 
                            = VL_SHIFTR_III(32,32,32, 
                                            ((IData)(7U) 
                                             + vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_size), 3U);
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__element_index 
                            = (VL_SHIFTL_QQI(64,64,32, 
                                             (VL_SHIFTL_QQI(64,64,32, 
                                                            (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__k_outer)) 
                                                              * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_tiles))) 
                                                             + (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_outer))), 4U) 
                                              + (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__k_inner))), 3U) 
                               + (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__n_inner)));
                        if ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__dtype))) {
                            vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__Vfuncout 
                                = VL_SHIFTR_QQI(64,64,32, vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__element_index, 1U);
                            goto __Vlabel3;
                        }
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__Vfuncout 
                            = (vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__element_index 
                               * VL_EXTEND_QI(64,3, 
                                              ([&]() {
                                        vlSelfRef.__Vfunc_dtype_bytes__186__dtype 
                                            = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__dtype;
                                        vlSelfRef.__Vfunc_dtype_bytes__186__Vfuncout 
                                            = ((1U 
                                                == (IData)(vlSelfRef.__Vfunc_dtype_bytes__186__dtype))
                                                ? 1U
                                                : (
                                                   (2U 
                                                    == (IData)(vlSelfRef.__Vfunc_dtype_bytes__186__dtype))
                                                    ? 4U
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlSelfRef.__Vfunc_dtype_bytes__186__dtype))
                                                     ? 2U
                                                     : 0U)));
                                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__186__Vfuncout))));
                        __Vlabel3: ;
                    }
                }(), vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__tiled_b_offset__185__Vfuncout)
               : ((2U & vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x17U])
                   ? ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__dtype 
                            = (3U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU] 
                                     >> 2U));
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__row_stride 
                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x19U];
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__col 
                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q;
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__row 
                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q;
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__element_offset 
                            = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__dtype))
                                ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__col)), 1U)
                                : ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__col)) 
                                   * VL_EXTEND_QI(64,3, 
                                                  ([&]() {
                                            vlSelfRef.__Vfunc_dtype_bytes__188__dtype 
                                                = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__dtype;
                                            vlSelfRef.__Vfunc_dtype_bytes__188__Vfuncout 
                                                = (
                                                   (1U 
                                                    == (IData)(vlSelfRef.__Vfunc_dtype_bytes__188__dtype))
                                                    ? 1U
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelfRef.__Vfunc_dtype_bytes__188__dtype))
                                                     ? 4U
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlSelfRef.__Vfunc_dtype_bytes__188__dtype))
                                                      ? 2U
                                                      : 0U)));
                                        }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__188__Vfuncout)))));
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__Vfuncout 
                            = (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__row)) 
                                * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__row_stride))) 
                               + vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__element_offset);
                    }(), vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__187__Vfuncout)
                   : ([&]() {
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__dtype 
                            = (3U & (vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0xeU] 
                                     >> 2U));
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__row_stride 
                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__desc_q[0x19U];
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__col 
                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__col_q;
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__row 
                            = vlSelfRef.tb_npu_engines__DOT__u_matrix__DOT__k_q;
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__element_offset 
                            = ((0U == (IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__dtype))
                                ? VL_SHIFTR_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__col)), 1U)
                                : ((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__col)) 
                                   * VL_EXTEND_QI(64,3, 
                                                  ([&]() {
                                            vlSelfRef.__Vfunc_dtype_bytes__190__dtype 
                                                = vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__dtype;
                                            vlSelfRef.__Vfunc_dtype_bytes__190__Vfuncout 
                                                = (
                                                   (1U 
                                                    == (IData)(vlSelfRef.__Vfunc_dtype_bytes__190__dtype))
                                                    ? 1U
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelfRef.__Vfunc_dtype_bytes__190__dtype))
                                                     ? 4U
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlSelfRef.__Vfunc_dtype_bytes__190__dtype))
                                                      ? 2U
                                                      : 0U)));
                                        }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__190__Vfuncout)))));
                        vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__Vfuncout 
                            = (((QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__row)) 
                                * (QData)((IData)(vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__row_stride))) 
                               + vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__element_offset);
                    }(), vlSelfRef.__Vfunc_tb_npu_engines__DOT__u_matrix__DOT__row_major_offset__189__Vfuncout))));
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_dst_addr 
        = ((7U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))
            ? vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__stat_dst_addr
            : vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__normal_dst_addr);
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____VdfgExtracted_h5b28d49a__0 
        = ((vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_row 
            * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x18U]))) 
           + (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_col 
              * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__179__dtype 
                            = (3U & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0xeU]);
                        vlSelfRef.__Vfunc_dtype_bytes__179__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__179__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__179__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__179__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__179__Vfuncout)))));
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT____VdfgExtracted_hb6bd6506__0 
        = ((vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_col 
            * (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x1eU]))) 
           + (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transpose_row 
              * VL_EXTEND_QI(64,3, ([&]() {
                        vlSelfRef.__Vfunc_dtype_bytes__180__dtype 
                            = (3U & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0xeU] 
                                     >> 6U));
                        vlSelfRef.__Vfunc_dtype_bytes__180__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__180__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__180__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__180__dtype))
                                                  ? 2U
                                                  : 0U)));
                    }(), (IData)(vlSelfRef.__Vfunc_dtype_bytes__180__Vfuncout)))));
    __Vfunc_fp32_from_int__369__value = (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__active_columns));
    vlSelf->__Vfunc_fp32_from_int__369__sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14683435577249580995ull);
    vlSelf->__Vfunc_fp32_from_int__369__magnitude = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6964326406659065053ull);
    vlSelf->__Vfunc_fp32_from_int__369__shifted_significand = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16702858321508131237ull);
    vlSelf->__Vfunc_fp32_from_int__369__remainder_mask = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2947500780888209947ull);
    vlSelf->__Vfunc_fp32_from_int__369__remainder = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17153184990981471426ull);
    vlSelf->__Vfunc_fp32_from_int__369__halfway = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1959227744912849895ull);
    vlSelf->__Vfunc_fp32_from_int__369__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 4930142788504310613ull);
    vlSelf->__Vfunc_fp32_from_int__369__fraction = VL_SCOPED_RAND_RESET_I(23, __VscopeHash, 16891806611797353384ull);
    vlSelf->__Vfunc_fp32_from_int__369__exponent = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2913272372048887738ull);
    vlSelf->__Vfunc_fp32_from_int__369__leading_bit = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12623220851799508164ull);
    vlSelf->__Vfunc_fp32_from_int__369__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3060590752208319195ull);
    __Vfunc_fp32_from_int__369__bit_index = 0;
    {
        if ((0ULL == __Vfunc_fp32_from_int__369__value)) {
            vlSelfRef.__Vfunc_fp32_from_int__369__Vfuncout = 0U;
            goto __Vlabel4;
        }
        vlSelfRef.__Vfunc_fp32_from_int__369__sign 
            = (1U & (IData)((__Vfunc_fp32_from_int__369__value 
                             >> 0x3fU)));
        vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
            = ((IData)(vlSelfRef.__Vfunc_fp32_from_int__369__sign)
                ? (1ULL + (~ __Vfunc_fp32_from_int__369__value))
                : __Vfunc_fp32_from_int__369__value);
        vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0U;
        __Vfunc_fp32_from_int__369__bit_index = 0U;
        if ((1U & (IData)(vlSelfRef.__Vfunc_fp32_from_int__369__magnitude))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 1U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 1U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 1U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 2U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 2U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 2U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 3U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 3U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 3U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 4U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 4U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 4U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 5U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 5U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 5U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 6U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 6U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 6U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 7U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 7U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 7U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 8U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 8U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 8U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 9U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 9U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 9U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0xaU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0xaU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0xaU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0xbU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0xbU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0xbU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0xcU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0xcU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0xcU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0xdU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0xdU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0xdU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0xeU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0xeU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0xeU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0xfU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0xfU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0xfU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x10U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x10U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x10U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x11U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x11U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x11U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x12U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x12U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x12U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x13U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x13U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x13U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x14U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x14U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x14U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x15U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x15U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x15U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x16U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x16U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x16U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x17U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x17U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x18U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x18U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x18U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x19U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x19U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x19U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x1aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x1aU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x1bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x1bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x1bU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x1cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x1cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x1cU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x1dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x1dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x1dU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x1eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x1eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x1eU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x1fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x1fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x1fU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x20U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x20U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x20U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x21U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x21U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x21U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x22U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x22U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x22U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x23U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x23U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x23U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x24U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x24U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x24U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x25U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x25U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x25U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x26U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x26U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x26U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x27U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x27U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x27U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x28U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x28U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x28U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x29U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x29U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x29U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x2aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x2aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x2aU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x2bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x2bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x2bU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x2cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x2cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x2cU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x2dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x2dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x2dU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x2eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x2eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x2eU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x2fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x2fU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x30U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x30U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x30U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x31U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x31U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x31U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x32U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x32U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x32U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x33U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x33U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x33U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x34U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x34U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x34U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x35U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x35U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x35U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x36U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x36U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x36U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x37U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x37U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x37U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x38U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x38U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x38U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x39U;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x39U)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x39U;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x3aU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x3aU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x3aU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x3bU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x3bU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x3bU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x3cU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x3cU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x3cU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x3dU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x3dU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x3dU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x3eU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x3eU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x3eU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x3fU;
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                           >> 0x3fU)))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit = 0x3fU;
        }
        __Vfunc_fp32_from_int__369__bit_index = 0x40U;
        vlSelfRef.__Vfunc_fp32_from_int__369__exponent 
            = (0x1ffU & ((IData)(0x7fU) + vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit));
        if (VL_GTES_III(32, 0x17U, vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit)) {
            vlSelfRef.__Vfunc_fp32_from_int__369__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTL_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__369__magnitude, 
                                                     ((IData)(0x17U) 
                                                      - vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit))));
            vlSelfRef.__Vfunc_fp32_from_int__369__fraction 
                = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__369__shifted_significand);
        } else {
            vlSelfRef.__Vfunc_fp32_from_int__369__shift_amount 
                = (vlSelfRef.__Vfunc_fp32_from_int__369__leading_bit 
                   - (IData)(0x17U));
            vlSelfRef.__Vfunc_fp32_from_int__369__shifted_significand 
                = (0xffffffU & (IData)(VL_SHIFTR_QQI(64,64,32, vlSelfRef.__Vfunc_fp32_from_int__369__magnitude, vlSelfRef.__Vfunc_fp32_from_int__369__shift_amount)));
            vlSelfRef.__Vfunc_fp32_from_int__369__remainder_mask 
                = (VL_SHIFTL_QQI(64,64,32, 1ULL, vlSelfRef.__Vfunc_fp32_from_int__369__shift_amount) 
                   - 1ULL);
            vlSelfRef.__Vfunc_fp32_from_int__369__remainder 
                = (vlSelfRef.__Vfunc_fp32_from_int__369__magnitude 
                   & vlSelfRef.__Vfunc_fp32_from_int__369__remainder_mask);
            vlSelfRef.__Vfunc_fp32_from_int__369__halfway 
                = VL_SHIFTL_QQI(64,64,32, 1ULL, (vlSelfRef.__Vfunc_fp32_from_int__369__shift_amount 
                                                 - (IData)(1U)));
            vlSelfRef.__Vfunc_fp32_from_int__369__rounded 
                = vlSelfRef.__Vfunc_fp32_from_int__369__shifted_significand;
            if (((vlSelfRef.__Vfunc_fp32_from_int__369__remainder 
                  > vlSelfRef.__Vfunc_fp32_from_int__369__halfway) 
                 | ((vlSelfRef.__Vfunc_fp32_from_int__369__remainder 
                     == vlSelfRef.__Vfunc_fp32_from_int__369__halfway) 
                    & vlSelfRef.__Vfunc_fp32_from_int__369__shifted_significand))) {
                vlSelfRef.__Vfunc_fp32_from_int__369__rounded 
                    = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_from_int__369__rounded));
            }
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_from_int__369__rounded)) {
                vlSelfRef.__Vfunc_fp32_from_int__369__fraction 
                    = (0x7fffffU & (vlSelfRef.__Vfunc_fp32_from_int__369__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_from_int__369__exponent 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_from_int__369__exponent)));
            } else {
                vlSelfRef.__Vfunc_fp32_from_int__369__fraction 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_from_int__369__rounded);
            }
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_from_int__369__exponent))) {
            vlSelfRef.__Vfunc_fp32_from_int__369__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_from_int__369__sign) 
                                  << 0x1fU));
            goto __Vlabel4;
        }
        vlSelfRef.__Vfunc_fp32_from_int__369__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_from_int__369__sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_from_int__369__exponent) 
                                             << 0x17U)) 
                             | vlSelfRef.__Vfunc_fp32_from_int__369__fraction));
        __Vlabel4: ;
    }
}
