// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_engines.h for the primary calling header

#include "Vtb_npu_engines__pch.h"
#include "Vtb_npu_engines___024root.h"

VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__6(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___stl_sequent__TOP__6\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_fp32_add__391__lhs;
    __Vfunc_fp32_add__391__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__391__rhs;
    __Vfunc_fp32_add__391__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__391__normalize_count;
    __Vfunc_fp32_add__391__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__392__unused_sign;
    __Vfunc_fp32_is_nan__392__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__393__unused_sign;
    __Vfunc_fp32_is_nan__393__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__394__unused_sign;
    __Vfunc_fp32_is_inf__394__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__395__unused_sign;
    __Vfunc_fp32_is_inf__395__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__396__unused_sign;
    __Vfunc_fp32_is_inf__396__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__397__unused_sign;
    __Vfunc_fp32_is_inf__397__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__398__unused_sign;
    __Vfunc_fp32_is_inf__398__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__399__unused_sign;
    __Vfunc_fp32_is_zero__399__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__400__unused_sign;
    __Vfunc_fp32_is_zero__400__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__468__lhs;
    __Vfunc_fp32_mul__468__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__468__rhs;
    __Vfunc_fp32_mul__468__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__468__normalize_count;
    __Vfunc_fp32_mul__468__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__469__unused_sign;
    __Vfunc_fp32_is_nan__469__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__470__unused_sign;
    __Vfunc_fp32_is_nan__470__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__471__unused_sign;
    __Vfunc_fp32_is_inf__471__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__472__unused_sign;
    __Vfunc_fp32_is_zero__472__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__473__unused_sign;
    __Vfunc_fp32_is_inf__473__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__474__unused_sign;
    __Vfunc_fp32_is_zero__474__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__475__unused_sign;
    __Vfunc_fp32_is_inf__475__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__476__unused_sign;
    __Vfunc_fp32_is_inf__476__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__477__unused_sign;
    __Vfunc_fp32_is_zero__477__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__478__unused_sign;
    __Vfunc_fp32_is_zero__478__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__510__lhs;
    __Vfunc_fp32_add__510__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__510__rhs;
    __Vfunc_fp32_add__510__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__510__normalize_count;
    __Vfunc_fp32_add__510__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__511__unused_sign;
    __Vfunc_fp32_is_nan__511__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__512__unused_sign;
    __Vfunc_fp32_is_nan__512__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__513__unused_sign;
    __Vfunc_fp32_is_inf__513__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__514__unused_sign;
    __Vfunc_fp32_is_inf__514__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__515__unused_sign;
    __Vfunc_fp32_is_inf__515__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__516__unused_sign;
    __Vfunc_fp32_is_inf__516__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__517__unused_sign;
    __Vfunc_fp32_is_inf__517__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__518__unused_sign;
    __Vfunc_fp32_is_zero__518__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__519__unused_sign;
    __Vfunc_fp32_is_zero__519__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_div__520__numerator_value;
    __Vfunc_fp32_div__520__numerator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__520__denominator_value;
    __Vfunc_fp32_div__520__denominator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__520__normalize_count;
    __Vfunc_fp32_div__520__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__521__unused_sign;
    __Vfunc_fp32_is_nan__521__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__522__unused_sign;
    __Vfunc_fp32_is_nan__522__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__523__unused_sign;
    __Vfunc_fp32_is_zero__523__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__524__unused_sign;
    __Vfunc_fp32_is_zero__524__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__525__unused_sign;
    __Vfunc_fp32_is_inf__525__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__526__unused_sign;
    __Vfunc_fp32_is_inf__526__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__527__unused_sign;
    __Vfunc_fp32_is_inf__527__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__528__unused_sign;
    __Vfunc_fp32_is_zero__528__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__529__unused_sign;
    __Vfunc_fp32_is_zero__529__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__530__unused_sign;
    __Vfunc_fp32_is_inf__530__unused_sign = 0;
    // Body
    __Vfunc_fp32_add__391__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_x_squared;
    __Vfunc_fp32_add__391__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sumsq_q;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_add__391__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4610970783869877425ull);
    vlSelf->__Vfunc_fp32_add__391__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 329491323232720176ull);
    vlSelf->__Vfunc_fp32_add__391__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13428658707936966972ull);
    vlSelf->__Vfunc_fp32_add__391__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12402144792111358143ull);
    vlSelf->__Vfunc_fp32_add__391__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1105632207767575737ull);
    vlSelf->__Vfunc_fp32_add__391__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 17609100577624247143ull);
    vlSelf->__Vfunc_fp32_add__391__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 6378747219588691553ull);
    vlSelf->__Vfunc_fp32_add__391__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 1416401834224874817ull);
    vlSelf->__Vfunc_fp32_add__391__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 580029000792474235ull);
    vlSelf->__Vfunc_fp32_add__391__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14225885890012232208ull);
    vlSelf->__Vfunc_fp32_add__391__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17587876732763762624ull);
    vlSelf->__Vfunc_fp32_add__391__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7321005968556898988ull);
    vlSelf->__Vfunc_fp32_add__391__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10983077297949733815ull);
    vlSelf->__Vfunc_fp32_add__391__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15155096407077155257ull);
    vlSelf->__Vfunc_fp32_add__391__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 9068973149259999460ull);
    vlSelf->__Vfunc_fp32_add__391__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 4474303563405015664ull);
    vlSelf->__Vfunc_fp32_add__391__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 14131781305337870258ull);
    vlSelf->__Vfunc_fp32_add__391__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 16751109889232653053ull);
    vlSelf->__Vfunc_fp32_add__391__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 3234623648194574350ull);
    vlSelf->__Vfunc_fp32_add__391__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 2148354194982615116ull);
    vlSelf->__Vfunc_fp32_add__391__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17228468245353298139ull);
    vlSelf->__Vfunc_fp32_add__391__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17156576253902416863ull);
    vlSelf->__Vfunc_fp32_add__391__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16303138831501236678ull);
    vlSelf->__Vfunc_fp32_add__391__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6788755361360577364ull);
    __Vfunc_fp32_add__391__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__392__bits 
                            = __Vfunc_fp32_add__391__lhs;
                        __Vfunc_fp32_is_nan__392__unused_sign = 0;
                        __Vfunc_fp32_is_nan__392__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__392__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__392__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__392__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__392__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__392__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__393__bits 
                            = __Vfunc_fp32_add__391__rhs;
                        __Vfunc_fp32_is_nan__393__unused_sign = 0;
                        __Vfunc_fp32_is_nan__393__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__393__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__393__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__393__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__393__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__393__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__391__Vfuncout = 0x7fc00000U;
            goto __Vlabel0;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__394__bits 
                            = __Vfunc_fp32_add__391__lhs;
                        __Vfunc_fp32_is_inf__394__unused_sign = 0;
                        __Vfunc_fp32_is_inf__394__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__394__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__394__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__394__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__394__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__395__bits 
                            = __Vfunc_fp32_add__391__rhs;
                        __Vfunc_fp32_is_inf__395__unused_sign = 0;
                        __Vfunc_fp32_is_inf__395__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__395__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__395__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__395__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__395__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__396__bits 
                                    = __Vfunc_fp32_add__391__lhs;
                                __Vfunc_fp32_is_inf__396__unused_sign = 0;
                                __Vfunc_fp32_is_inf__396__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__396__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__396__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__396__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__396__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__397__bits 
                                    = __Vfunc_fp32_add__391__rhs;
                                __Vfunc_fp32_is_inf__397__unused_sign = 0;
                                __Vfunc_fp32_is_inf__397__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__397__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__397__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__397__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__397__Vfuncout))) 
                 & ((__Vfunc_fp32_add__391__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__391__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__391__Vfuncout = 0x7fc00000U;
                goto __Vlabel0;
            }
            vlSelfRef.__Vfunc_fp32_add__391__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__398__bits 
                            = __Vfunc_fp32_add__391__lhs;
                        __Vfunc_fp32_is_inf__398__unused_sign = 0;
                        __Vfunc_fp32_is_inf__398__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__398__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__398__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__398__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__398__Vfuncout))
                    ? __Vfunc_fp32_add__391__lhs : __Vfunc_fp32_add__391__rhs);
            goto __Vlabel0;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__399__bits 
                        = __Vfunc_fp32_add__391__lhs;
                    __Vfunc_fp32_is_zero__399__unused_sign = 0;
                    __Vfunc_fp32_is_zero__399__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__399__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__399__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__399__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__399__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__391__Vfuncout 
                = __Vfunc_fp32_add__391__rhs;
            goto __Vlabel0;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__400__bits 
                        = __Vfunc_fp32_add__391__rhs;
                    __Vfunc_fp32_is_zero__400__unused_sign = 0;
                    __Vfunc_fp32_is_zero__400__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__400__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__400__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__400__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__400__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__391__Vfuncout 
                = __Vfunc_fp32_add__391__lhs;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_add__391__lhs_sign = 
            (__Vfunc_fp32_add__391__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__391__rhs_sign = 
            (__Vfunc_fp32_add__391__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__391__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__391__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__391__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__391__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__391__lhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__391__lhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__391__lhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__391__lhs)));
        vlSelfRef.__Vfunc_fp32_add__391__rhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__391__rhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__391__rhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__391__rhs)));
        vlSelfRef.__Vfunc_fp32_add__391__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__391__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__391__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__391__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__391__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__391__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__391__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__391__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__391__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__391__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__391__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__391__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__391__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__391__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__391__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__391__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__391__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__391__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__391__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__391__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__391__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__391__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__391__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__391__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__391__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__391__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__391__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__391__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__391__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__391__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__391__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__391__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__391__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__391__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__391__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__391__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__391__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__391__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__391__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__391__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__391__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__391__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__391__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__391__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__391__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__391__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__small_ext, vlSelfRef.__Vfunc_fp32_add__391__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__391__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__391__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__391__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__391__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__391__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__391__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__391__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__391__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__391__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__391__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__391__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__391__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__391__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__391__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__391__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__391__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__391__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__391__work_ext);
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__391__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__391__sticky))));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__391__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__391__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__391__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__391__Vfuncout = 0U;
                goto __Vlabel0;
            }
            __Vfunc_fp32_add__391__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__391__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__391__normalize_count = 1U;
            __Vfunc_fp32_add__391__normalize_count = 2U;
            __Vfunc_fp32_add__391__normalize_count = 3U;
            __Vfunc_fp32_add__391__normalize_count = 4U;
            __Vfunc_fp32_add__391__normalize_count = 5U;
            __Vfunc_fp32_add__391__normalize_count = 6U;
            __Vfunc_fp32_add__391__normalize_count = 7U;
            __Vfunc_fp32_add__391__normalize_count = 8U;
            __Vfunc_fp32_add__391__normalize_count = 9U;
            __Vfunc_fp32_add__391__normalize_count = 0xaU;
            __Vfunc_fp32_add__391__normalize_count = 0xbU;
            __Vfunc_fp32_add__391__normalize_count = 0xcU;
            __Vfunc_fp32_add__391__normalize_count = 0xdU;
            __Vfunc_fp32_add__391__normalize_count = 0xeU;
            __Vfunc_fp32_add__391__normalize_count = 0xfU;
            __Vfunc_fp32_add__391__normalize_count = 0x10U;
            __Vfunc_fp32_add__391__normalize_count = 0x11U;
            __Vfunc_fp32_add__391__normalize_count = 0x12U;
            __Vfunc_fp32_add__391__normalize_count = 0x13U;
            __Vfunc_fp32_add__391__normalize_count = 0x14U;
            __Vfunc_fp32_add__391__normalize_count = 0x15U;
            __Vfunc_fp32_add__391__normalize_count = 0x16U;
            __Vfunc_fp32_add__391__normalize_count = 0x17U;
            __Vfunc_fp32_add__391__normalize_count = 0x18U;
            __Vfunc_fp32_add__391__normalize_count = 0x19U;
            __Vfunc_fp32_add__391__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__391__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_add__391__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__391__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__391__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__391__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__391__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__391__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__391__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__391__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__391__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__391__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__391__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__391__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__391__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__391__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__391__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__391__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__391__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__391__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__391__mantissa));
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_add__391__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_add__391__result_sign) 
              << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__391__large_exp) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__391__mantissa)));
        __Vlabel0: ;
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sumsq_plus_x_squared 
        = vlSelfRef.__Vfunc_fp32_add__391__Vfuncout;
    __Vfunc_fp32_mul__468__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_invstd_q;
    __Vfunc_fp32_mul__468__lhs = ((5U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x13U])
                                   ? vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_centered_x
                                   : vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp);
    vlSelf->__Vfunc_fp32_mul__468__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18312666436884588165ull);
    vlSelf->__Vfunc_fp32_mul__468__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6705701999757368500ull);
    vlSelf->__Vfunc_fp32_mul__468__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11662964237035570918ull);
    vlSelf->__Vfunc_fp32_mul__468__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 12153753472750162841ull);
    vlSelf->__Vfunc_fp32_mul__468__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 14845237115125889619ull);
    vlSelf->__Vfunc_fp32_mul__468__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 8460988468779756575ull);
    vlSelf->__Vfunc_fp32_mul__468__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 15834570752221728731ull);
    vlSelf->__Vfunc_fp32_mul__468__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 3544497120182037040ull);
    vlSelf->__Vfunc_fp32_mul__468__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16032583613463463805ull);
    vlSelf->__Vfunc_fp32_mul__468__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2180929265549262621ull);
    vlSelf->__Vfunc_fp32_mul__468__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2963978094386627471ull);
    vlSelf->__Vfunc_fp32_mul__468__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3654221177561334369ull);
    vlSelf->__Vfunc_fp32_mul__468__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14876098953513242356ull);
    __Vfunc_fp32_mul__468__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__469__bits 
                                = __Vfunc_fp32_mul__468__lhs;
                            __Vfunc_fp32_is_nan__469__unused_sign = 0;
                            __Vfunc_fp32_is_nan__469__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__469__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__469__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__469__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__469__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__469__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__470__bits 
                                = __Vfunc_fp32_mul__468__rhs;
                            __Vfunc_fp32_is_nan__470__unused_sign = 0;
                            __Vfunc_fp32_is_nan__470__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__470__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__470__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__470__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__470__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__470__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__471__bits 
                                    = __Vfunc_fp32_mul__468__lhs;
                                __Vfunc_fp32_is_inf__471__unused_sign = 0;
                                __Vfunc_fp32_is_inf__471__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__471__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__471__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__471__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__471__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__472__bits 
                                    = __Vfunc_fp32_mul__468__rhs;
                                __Vfunc_fp32_is_zero__472__unused_sign = 0;
                                __Vfunc_fp32_is_zero__472__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__472__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__472__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__472__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__472__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__473__bits 
                                    = __Vfunc_fp32_mul__468__rhs;
                                __Vfunc_fp32_is_inf__473__unused_sign = 0;
                                __Vfunc_fp32_is_inf__473__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__473__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__473__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__473__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__473__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__474__bits 
                                    = __Vfunc_fp32_mul__468__lhs;
                                __Vfunc_fp32_is_zero__474__unused_sign = 0;
                                __Vfunc_fp32_is_zero__474__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__474__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__474__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__474__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__474__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__468__Vfuncout = 0x7fc00000U;
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_mul__468__result_sign 
            = ((__Vfunc_fp32_mul__468__lhs ^ __Vfunc_fp32_mul__468__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__475__bits 
                            = __Vfunc_fp32_mul__468__lhs;
                        __Vfunc_fp32_is_inf__475__unused_sign = 0;
                        __Vfunc_fp32_is_inf__475__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__475__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__475__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__475__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__475__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__476__bits 
                            = __Vfunc_fp32_mul__468__rhs;
                        __Vfunc_fp32_is_inf__476__unused_sign = 0;
                        __Vfunc_fp32_is_inf__476__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__476__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__476__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__476__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__476__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__468__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__477__bits 
                            = __Vfunc_fp32_mul__468__lhs;
                        __Vfunc_fp32_is_zero__477__unused_sign = 0;
                        __Vfunc_fp32_is_zero__477__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__477__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__477__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__477__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__477__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__478__bits 
                            = __Vfunc_fp32_mul__468__rhs;
                        __Vfunc_fp32_is_zero__478__unused_sign = 0;
                        __Vfunc_fp32_is_zero__478__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__478__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__478__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__478__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__478__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__468__result_sign) 
                   << 0x1fU);
            goto __Vlabel1;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__468__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__468__lhs);
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__468__lhs));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__468__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__468__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__468__rhs);
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__468__rhs));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__468__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__468__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__468__normalize_count = 1U;
        __Vfunc_fp32_mul__468__normalize_count = 2U;
        __Vfunc_fp32_mul__468__normalize_count = 3U;
        __Vfunc_fp32_mul__468__normalize_count = 4U;
        __Vfunc_fp32_mul__468__normalize_count = 5U;
        __Vfunc_fp32_mul__468__normalize_count = 6U;
        __Vfunc_fp32_mul__468__normalize_count = 7U;
        __Vfunc_fp32_mul__468__normalize_count = 8U;
        __Vfunc_fp32_mul__468__normalize_count = 9U;
        __Vfunc_fp32_mul__468__normalize_count = 0xaU;
        __Vfunc_fp32_mul__468__normalize_count = 0xbU;
        __Vfunc_fp32_mul__468__normalize_count = 0xcU;
        __Vfunc_fp32_mul__468__normalize_count = 0xdU;
        __Vfunc_fp32_mul__468__normalize_count = 0xeU;
        __Vfunc_fp32_mul__468__normalize_count = 0xfU;
        __Vfunc_fp32_mul__468__normalize_count = 0x10U;
        __Vfunc_fp32_mul__468__normalize_count = 0x11U;
        __Vfunc_fp32_mul__468__normalize_count = 0x12U;
        __Vfunc_fp32_mul__468__normalize_count = 0x13U;
        __Vfunc_fp32_mul__468__normalize_count = 0x14U;
        __Vfunc_fp32_mul__468__normalize_count = 0x15U;
        __Vfunc_fp32_mul__468__normalize_count = 0x16U;
        __Vfunc_fp32_mul__468__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__468__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__468__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__468__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__468__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__468__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__468__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__468__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__468__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__468__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__468__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__468__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__468__mantissa = 
            (0xffffffU & (IData)((0xffffffffffffULL 
                                  & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__468__product, vlSelfRef.__Vfunc_fp32_mul__468__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__468__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__468__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__468__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__468__product 
               & vlSelfRef.__Vfunc_fp32_mul__468__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__468__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__468__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__468__rounded = vlSelfRef.__Vfunc_fp32_mul__468__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__468__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__468__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__468__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__468__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__468__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__468__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__468__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__468__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__468__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__468__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__468__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__468__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__468__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__468__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__468__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__468__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__468__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__468__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__468__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__468__result_sign) 
                   << 0x1fU);
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_mul__468__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_mul__468__result_sign) 
              << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                            + vlSelfRef.__Vfunc_fp32_mul__468__result_unbiased) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__468__mantissa)));
        __Vlabel1: ;
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_norm_base 
        = vlSelfRef.__Vfunc_fp32_mul__468__Vfuncout;
    __Vfunc_fp32_add__510__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_result;
    __Vfunc_fp32_add__510__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_q;
    vlSelf->__Vfunc_fp32_add__510__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14324692169006000218ull);
    vlSelf->__Vfunc_fp32_add__510__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5835256068892083789ull);
    vlSelf->__Vfunc_fp32_add__510__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6432176200264390035ull);
    vlSelf->__Vfunc_fp32_add__510__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10306046709364134169ull);
    vlSelf->__Vfunc_fp32_add__510__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4947707100405064433ull);
    vlSelf->__Vfunc_fp32_add__510__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 6836849740172667173ull);
    vlSelf->__Vfunc_fp32_add__510__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2273794047880182935ull);
    vlSelf->__Vfunc_fp32_add__510__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14066331566728230879ull);
    vlSelf->__Vfunc_fp32_add__510__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17471449766999019675ull);
    vlSelf->__Vfunc_fp32_add__510__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18133087776209201811ull);
    vlSelf->__Vfunc_fp32_add__510__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 3825606364251269519ull);
    vlSelf->__Vfunc_fp32_add__510__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8799011697232969043ull);
    vlSelf->__Vfunc_fp32_add__510__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17087442576799903658ull);
    vlSelf->__Vfunc_fp32_add__510__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1866910004925033693ull);
    vlSelf->__Vfunc_fp32_add__510__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 939452141250267928ull);
    vlSelf->__Vfunc_fp32_add__510__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 15974642138474790005ull);
    vlSelf->__Vfunc_fp32_add__510__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 11885793044652090541ull);
    vlSelf->__Vfunc_fp32_add__510__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 13127127162178603924ull);
    vlSelf->__Vfunc_fp32_add__510__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 12861339639126900200ull);
    vlSelf->__Vfunc_fp32_add__510__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 15383733804997717801ull);
    vlSelf->__Vfunc_fp32_add__510__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10727613146920357818ull);
    vlSelf->__Vfunc_fp32_add__510__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8990014207075509943ull);
    vlSelf->__Vfunc_fp32_add__510__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14277647182277169136ull);
    vlSelf->__Vfunc_fp32_add__510__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11899395444615407815ull);
    __Vfunc_fp32_add__510__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__511__bits 
                            = __Vfunc_fp32_add__510__lhs;
                        __Vfunc_fp32_is_nan__511__unused_sign = 0;
                        __Vfunc_fp32_is_nan__511__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__511__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__511__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__511__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__511__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__511__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__512__bits 
                            = __Vfunc_fp32_add__510__rhs;
                        __Vfunc_fp32_is_nan__512__unused_sign = 0;
                        __Vfunc_fp32_is_nan__512__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__512__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__512__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__512__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__512__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__512__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__510__Vfuncout = 0x7fc00000U;
            goto __Vlabel2;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__513__bits 
                            = __Vfunc_fp32_add__510__lhs;
                        __Vfunc_fp32_is_inf__513__unused_sign = 0;
                        __Vfunc_fp32_is_inf__513__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__513__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__513__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__513__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__513__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__514__bits 
                            = __Vfunc_fp32_add__510__rhs;
                        __Vfunc_fp32_is_inf__514__unused_sign = 0;
                        __Vfunc_fp32_is_inf__514__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__514__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__514__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__514__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__514__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__515__bits 
                                    = __Vfunc_fp32_add__510__lhs;
                                __Vfunc_fp32_is_inf__515__unused_sign = 0;
                                __Vfunc_fp32_is_inf__515__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__515__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__515__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__515__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__515__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__516__bits 
                                    = __Vfunc_fp32_add__510__rhs;
                                __Vfunc_fp32_is_inf__516__unused_sign = 0;
                                __Vfunc_fp32_is_inf__516__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__516__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__516__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__516__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__516__Vfuncout))) 
                 & ((__Vfunc_fp32_add__510__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__510__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__510__Vfuncout = 0x7fc00000U;
                goto __Vlabel2;
            }
            vlSelfRef.__Vfunc_fp32_add__510__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__517__bits 
                            = __Vfunc_fp32_add__510__lhs;
                        __Vfunc_fp32_is_inf__517__unused_sign = 0;
                        __Vfunc_fp32_is_inf__517__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__517__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__517__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__517__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__517__Vfuncout))
                    ? __Vfunc_fp32_add__510__lhs : __Vfunc_fp32_add__510__rhs);
            goto __Vlabel2;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__518__bits 
                        = __Vfunc_fp32_add__510__lhs;
                    __Vfunc_fp32_is_zero__518__unused_sign = 0;
                    __Vfunc_fp32_is_zero__518__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__518__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__518__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__518__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__518__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__510__Vfuncout 
                = __Vfunc_fp32_add__510__rhs;
            goto __Vlabel2;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__519__bits 
                        = __Vfunc_fp32_add__510__rhs;
                    __Vfunc_fp32_is_zero__519__unused_sign = 0;
                    __Vfunc_fp32_is_zero__519__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__519__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__519__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__519__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__519__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__510__Vfuncout 
                = __Vfunc_fp32_add__510__lhs;
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_add__510__lhs_sign = 
            (__Vfunc_fp32_add__510__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__510__rhs_sign = 
            (__Vfunc_fp32_add__510__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__510__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__510__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__510__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__510__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__510__lhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__510__lhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__510__lhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__510__lhs)));
        vlSelfRef.__Vfunc_fp32_add__510__rhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__510__rhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__510__rhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__510__rhs)));
        vlSelfRef.__Vfunc_fp32_add__510__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__510__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__510__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__510__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__510__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__510__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__510__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__510__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__510__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__510__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__510__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__510__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__510__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__510__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__510__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__510__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__510__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__510__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__510__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__510__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__510__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__510__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__510__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__510__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__510__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__510__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__510__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__510__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__510__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__510__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__510__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__510__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__510__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__510__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__510__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__510__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__510__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__510__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__510__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__510__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__510__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__510__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__510__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__510__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__510__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__510__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__small_ext, vlSelfRef.__Vfunc_fp32_add__510__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__510__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__510__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__510__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__510__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__510__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__510__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__510__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__510__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__510__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__510__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__510__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__510__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__510__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__510__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__510__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__510__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__510__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__510__work_ext);
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__510__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__510__sticky))));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__510__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__510__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__510__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__510__Vfuncout = 0U;
                goto __Vlabel2;
            }
            __Vfunc_fp32_add__510__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__510__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__510__normalize_count = 1U;
            __Vfunc_fp32_add__510__normalize_count = 2U;
            __Vfunc_fp32_add__510__normalize_count = 3U;
            __Vfunc_fp32_add__510__normalize_count = 4U;
            __Vfunc_fp32_add__510__normalize_count = 5U;
            __Vfunc_fp32_add__510__normalize_count = 6U;
            __Vfunc_fp32_add__510__normalize_count = 7U;
            __Vfunc_fp32_add__510__normalize_count = 8U;
            __Vfunc_fp32_add__510__normalize_count = 9U;
            __Vfunc_fp32_add__510__normalize_count = 0xaU;
            __Vfunc_fp32_add__510__normalize_count = 0xbU;
            __Vfunc_fp32_add__510__normalize_count = 0xcU;
            __Vfunc_fp32_add__510__normalize_count = 0xdU;
            __Vfunc_fp32_add__510__normalize_count = 0xeU;
            __Vfunc_fp32_add__510__normalize_count = 0xfU;
            __Vfunc_fp32_add__510__normalize_count = 0x10U;
            __Vfunc_fp32_add__510__normalize_count = 0x11U;
            __Vfunc_fp32_add__510__normalize_count = 0x12U;
            __Vfunc_fp32_add__510__normalize_count = 0x13U;
            __Vfunc_fp32_add__510__normalize_count = 0x14U;
            __Vfunc_fp32_add__510__normalize_count = 0x15U;
            __Vfunc_fp32_add__510__normalize_count = 0x16U;
            __Vfunc_fp32_add__510__normalize_count = 0x17U;
            __Vfunc_fp32_add__510__normalize_count = 0x18U;
            __Vfunc_fp32_add__510__normalize_count = 0x19U;
            __Vfunc_fp32_add__510__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__510__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_add__510__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__510__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__510__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__510__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__510__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__510__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__510__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__510__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__510__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__510__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__510__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__510__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__510__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__510__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__510__result_sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__510__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__510__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__510__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__510__mantissa));
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_add__510__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_add__510__result_sign) 
              << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__510__large_exp) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__510__mantissa)));
        __Vlabel2: ;
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_soft_sum_plus_exp 
        = vlSelfRef.__Vfunc_fp32_add__510__Vfuncout;
    __Vfunc_fp32_div__520__denominator_value = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_q;
    __Vfunc_fp32_div__520__numerator_value = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_result;
    vlSelf->__Vfunc_fp32_div__520__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1415214137424340340ull);
    vlSelf->__Vfunc_fp32_div__520__numerator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17799709588315423437ull);
    vlSelf->__Vfunc_fp32_div__520__denominator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8415752691083697233ull);
    vlSelf->__Vfunc_fp32_div__520__scaled_numerator = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 4353644755666656841ull);
    vlSelf->__Vfunc_fp32_div__520__denominator_wide = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 7229881436410419935ull);
    vlSelf->__Vfunc_fp32_div__520__division_remainder = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16419435831641052289ull);
    vlSelf->__Vfunc_fp32_div__520__quotient_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 3746992568121994532ull);
    vlSelf->__Vfunc_fp32_div__520__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 7412440746613792419ull);
    vlSelf->__Vfunc_fp32_div__520__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8241960409755994964ull);
    vlSelf->__Vfunc_fp32_div__520__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6359954028778259610ull);
    vlSelf->__Vfunc_fp32_div__520__numerator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4637110110160206557ull);
    vlSelf->__Vfunc_fp32_div__520__denominator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12648243665409202921ull);
    vlSelf->__Vfunc_fp32_div__520__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10617433520740797759ull);
    __Vfunc_fp32_div__520__normalize_count = 0;
    {
        if ((((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__521__bits 
                                    = __Vfunc_fp32_div__520__numerator_value;
                                __Vfunc_fp32_is_nan__521__unused_sign = 0;
                                __Vfunc_fp32_is_nan__521__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__521__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__521__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__521__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__521__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__521__Vfuncout)) 
               | ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__522__bits 
                                    = __Vfunc_fp32_div__520__denominator_value;
                                __Vfunc_fp32_is_nan__522__unused_sign = 0;
                                __Vfunc_fp32_is_nan__522__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__522__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__522__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__522__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__522__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__522__Vfuncout))) 
              | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__523__bits 
                                    = __Vfunc_fp32_div__520__numerator_value;
                                __Vfunc_fp32_is_zero__523__unused_sign = 0;
                                __Vfunc_fp32_is_zero__523__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__523__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__523__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__523__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__523__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__524__bits 
                                    = __Vfunc_fp32_div__520__denominator_value;
                                __Vfunc_fp32_is_zero__524__unused_sign = 0;
                                __Vfunc_fp32_is_zero__524__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__524__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__524__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__524__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__524__Vfuncout)))) 
             | (([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__525__bits 
                                = __Vfunc_fp32_div__520__numerator_value;
                            __Vfunc_fp32_is_inf__525__unused_sign = 0;
                            __Vfunc_fp32_is_inf__525__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__525__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__525__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__525__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__525__Vfuncout)) 
                & ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__526__bits 
                                = __Vfunc_fp32_div__520__denominator_value;
                            __Vfunc_fp32_is_inf__526__unused_sign = 0;
                            __Vfunc_fp32_is_inf__526__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__526__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__526__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__526__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__526__Vfuncout))))) {
            vlSelfRef.__Vfunc_fp32_div__520__Vfuncout = 0x7fc00000U;
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_div__520__result_sign 
            = ((__Vfunc_fp32_div__520__numerator_value 
                ^ __Vfunc_fp32_div__520__denominator_value) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__527__bits 
                            = __Vfunc_fp32_div__520__numerator_value;
                        __Vfunc_fp32_is_inf__527__unused_sign = 0;
                        __Vfunc_fp32_is_inf__527__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__527__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__527__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__527__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__527__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__528__bits 
                            = __Vfunc_fp32_div__520__denominator_value;
                        __Vfunc_fp32_is_zero__528__unused_sign = 0;
                        __Vfunc_fp32_is_zero__528__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__528__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__528__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__528__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__528__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__520__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__520__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__529__bits 
                            = __Vfunc_fp32_div__520__numerator_value;
                        __Vfunc_fp32_is_zero__529__unused_sign = 0;
                        __Vfunc_fp32_is_zero__529__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__529__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__529__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__529__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__529__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__530__bits 
                            = __Vfunc_fp32_div__520__denominator_value;
                        __Vfunc_fp32_is_inf__530__unused_sign = 0;
                        __Vfunc_fp32_is_inf__530__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__530__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__530__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__530__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__530__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__520__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__520__result_sign) 
                   << 0x1fU);
            goto __Vlabel3;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__520__numerator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__520__numerator_value);
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__520__numerator_value));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__520__numerator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__520__denominator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__520__denominator_value);
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__520__denominator_value));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__520__denominator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_div__520__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__520__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__520__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_div__520__normalize_count = 1U;
        __Vfunc_fp32_div__520__normalize_count = 2U;
        __Vfunc_fp32_div__520__normalize_count = 3U;
        __Vfunc_fp32_div__520__normalize_count = 4U;
        __Vfunc_fp32_div__520__normalize_count = 5U;
        __Vfunc_fp32_div__520__normalize_count = 6U;
        __Vfunc_fp32_div__520__normalize_count = 7U;
        __Vfunc_fp32_div__520__normalize_count = 8U;
        __Vfunc_fp32_div__520__normalize_count = 9U;
        __Vfunc_fp32_div__520__normalize_count = 0xaU;
        __Vfunc_fp32_div__520__normalize_count = 0xbU;
        __Vfunc_fp32_div__520__normalize_count = 0xcU;
        __Vfunc_fp32_div__520__normalize_count = 0xdU;
        __Vfunc_fp32_div__520__normalize_count = 0xeU;
        __Vfunc_fp32_div__520__normalize_count = 0xfU;
        __Vfunc_fp32_div__520__normalize_count = 0x10U;
        __Vfunc_fp32_div__520__normalize_count = 0x11U;
        __Vfunc_fp32_div__520__normalize_count = 0x12U;
        __Vfunc_fp32_div__520__normalize_count = 0x13U;
        __Vfunc_fp32_div__520__normalize_count = 0x14U;
        __Vfunc_fp32_div__520__normalize_count = 0x15U;
        __Vfunc_fp32_div__520__normalize_count = 0x16U;
        __Vfunc_fp32_div__520__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_div__520__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_div__520__numerator_unbiased 
               - vlSelfRef.__Vfunc_fp32_div__520__denominator_unbiased);
        vlSelfRef.__Vfunc_fp32_div__520__scaled_numerator 
            = (0xffffffffffffffULL & VL_SHIFTL_QQI(56,56,32, (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__520__numerator_mant)), 0x1aU));
        vlSelfRef.__Vfunc_fp32_div__520__denominator_wide 
            = (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__520__denominator_mant));
        vlSelfRef.__Vfunc_fp32_div__520__quotient_ext 
            = (0xfffffffU & (IData)((0xffffffffffffffULL 
                                     & VL_DIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__520__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__520__denominator_wide))));
        vlSelfRef.__Vfunc_fp32_div__520__division_remainder 
            = (0xffffffU & (IData)((0xffffffffffffffULL 
                                    & VL_MODDIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__520__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__520__denominator_wide))));
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__520__quotient_ext 
                      >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_div__520__quotient_ext 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_div__520__quotient_ext, 1U));
            vlSelfRef.__Vfunc_fp32_div__520__result_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__520__result_unbiased 
                   - (IData)(1U));
        }
        if ((0U != vlSelfRef.__Vfunc_fp32_div__520__division_remainder)) {
            vlSelfRef.__Vfunc_fp32_div__520__quotient_ext 
                = (1U | vlSelfRef.__Vfunc_fp32_div__520__quotient_ext);
        }
        vlSelfRef.__Vfunc_fp32_div__520__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__520__quotient_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_div__520__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_div__520__quotient_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_div__520__quotient_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_div__520__quotient_ext) 
                                | vlSelfRef.__Vfunc_fp32_div__520__mantissa)));
        vlSelfRef.__Vfunc_fp32_div__520__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_div__520__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_div__520__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_div__520__rounded)) {
            vlSelfRef.__Vfunc_fp32_div__520__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__520__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_div__520__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_div__520__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_div__520__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_div__520__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_div__520__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__520__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__520__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_div__520__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__520__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__520__result_sign) 
                   << 0x1fU);
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_div__520__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_div__520__result_sign) 
              << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                            + vlSelfRef.__Vfunc_fp32_div__520__result_unbiased) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_div__520__mantissa)));
        __Vlabel3: ;
    }
}

VL_ATTR_COLD void Vtb_npu_engines___024root___stl_sequent__TOP__7(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___stl_sequent__TOP__7\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_npu_engines__DOT__u_complex__DOT__fp_norm_scaled;
    tb_npu_engines__DOT__u_complex__DOT__fp_norm_scaled = 0;
    IData/*31:0*/ tb_npu_engines__DOT__u_complex__DOT__fp_norm_output;
    tb_npu_engines__DOT__u_complex__DOT__fp_norm_output = 0;
    IData/*31:0*/ tb_npu_engines__DOT__u_complex__DOT__fp_softmax_output;
    tb_npu_engines__DOT__u_complex__DOT__fp_softmax_output = 0;
    IData/*31:0*/ tb_npu_engines__DOT__u_complex__DOT__fp_output_value;
    tb_npu_engines__DOT__u_complex__DOT__fp_output_value = 0;
    IData/*31:0*/ tb_npu_engines__DOT__u_complex__DOT__u_f2i__DOT__scaled_value;
    tb_npu_engines__DOT__u_complex__DOT__u_f2i__DOT__scaled_value = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__479__lhs;
    __Vfunc_fp32_mul__479__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__479__rhs;
    __Vfunc_fp32_mul__479__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__479__normalize_count;
    __Vfunc_fp32_mul__479__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__480__unused_sign;
    __Vfunc_fp32_is_nan__480__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__481__unused_sign;
    __Vfunc_fp32_is_nan__481__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__482__unused_sign;
    __Vfunc_fp32_is_inf__482__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__483__unused_sign;
    __Vfunc_fp32_is_zero__483__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__484__unused_sign;
    __Vfunc_fp32_is_inf__484__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__485__unused_sign;
    __Vfunc_fp32_is_zero__485__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__486__unused_sign;
    __Vfunc_fp32_is_inf__486__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__487__unused_sign;
    __Vfunc_fp32_is_inf__487__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__488__unused_sign;
    __Vfunc_fp32_is_zero__488__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__489__unused_sign;
    __Vfunc_fp32_is_zero__489__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__490__lhs;
    __Vfunc_fp32_add__490__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__490__rhs;
    __Vfunc_fp32_add__490__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__490__normalize_count;
    __Vfunc_fp32_add__490__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__491__unused_sign;
    __Vfunc_fp32_is_nan__491__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__492__unused_sign;
    __Vfunc_fp32_is_nan__492__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__493__unused_sign;
    __Vfunc_fp32_is_inf__493__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__494__unused_sign;
    __Vfunc_fp32_is_inf__494__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__495__unused_sign;
    __Vfunc_fp32_is_inf__495__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__496__unused_sign;
    __Vfunc_fp32_is_inf__496__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__497__unused_sign;
    __Vfunc_fp32_is_inf__497__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__498__unused_sign;
    __Vfunc_fp32_is_zero__498__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__499__unused_sign;
    __Vfunc_fp32_is_zero__499__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_div__2623__numerator_value;
    __Vfunc_fp32_div__2623__numerator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__2623__denominator_value;
    __Vfunc_fp32_div__2623__denominator_value = 0;
    IData/*31:0*/ __Vfunc_fp32_div__2623__normalize_count;
    __Vfunc_fp32_div__2623__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2624__unused_sign;
    __Vfunc_fp32_is_nan__2624__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2625__unused_sign;
    __Vfunc_fp32_is_nan__2625__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2626__unused_sign;
    __Vfunc_fp32_is_zero__2626__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2627__unused_sign;
    __Vfunc_fp32_is_zero__2627__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2628__unused_sign;
    __Vfunc_fp32_is_inf__2628__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2629__unused_sign;
    __Vfunc_fp32_is_inf__2629__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2630__unused_sign;
    __Vfunc_fp32_is_inf__2630__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2631__unused_sign;
    __Vfunc_fp32_is_zero__2631__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2632__unused_sign;
    __Vfunc_fp32_is_zero__2632__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2633__unused_sign;
    __Vfunc_fp32_is_inf__2633__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_to_int_round__2634__value;
    __Vfunc_fp32_to_int_round__2634__value = 0;
    CData/*1:0*/ __Vfunc_fp32_to_int_round__2634__rounding;
    __Vfunc_fp32_to_int_round__2634__rounding = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2635__unused_sign;
    __Vfunc_fp32_is_nan__2635__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2636__unused_sign;
    __Vfunc_fp32_is_inf__2636__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2637__unused_sign;
    __Vfunc_fp32_is_zero__2637__unused_sign = 0;
    // Body
    tb_npu_engines__DOT__u_complex__DOT__fp_softmax_output 
        = vlSelfRef.__Vfunc_fp32_div__520__Vfuncout;
    __Vfunc_fp32_mul__479__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_fp;
    __Vfunc_fp32_mul__479__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_norm_base;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_mul__479__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7700967919492381434ull);
    vlSelf->__Vfunc_fp32_mul__479__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16354006213146824371ull);
    vlSelf->__Vfunc_fp32_mul__479__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2273923044238191086ull);
    vlSelf->__Vfunc_fp32_mul__479__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 6333782547691634287ull);
    vlSelf->__Vfunc_fp32_mul__479__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 7930166288887158764ull);
    vlSelf->__Vfunc_fp32_mul__479__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 4043220551017721529ull);
    vlSelf->__Vfunc_fp32_mul__479__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 4155887862035697142ull);
    vlSelf->__Vfunc_fp32_mul__479__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 9080583319313810717ull);
    vlSelf->__Vfunc_fp32_mul__479__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5913697725461484365ull);
    vlSelf->__Vfunc_fp32_mul__479__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11419917609330334471ull);
    vlSelf->__Vfunc_fp32_mul__479__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2797040137657860467ull);
    vlSelf->__Vfunc_fp32_mul__479__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13369797141568429603ull);
    vlSelf->__Vfunc_fp32_mul__479__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8454865178461668772ull);
    __Vfunc_fp32_mul__479__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__480__bits 
                                = __Vfunc_fp32_mul__479__lhs;
                            __Vfunc_fp32_is_nan__480__unused_sign = 0;
                            __Vfunc_fp32_is_nan__480__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__480__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__480__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__480__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__480__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__480__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__481__bits 
                                = __Vfunc_fp32_mul__479__rhs;
                            __Vfunc_fp32_is_nan__481__unused_sign = 0;
                            __Vfunc_fp32_is_nan__481__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__481__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__481__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__481__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__481__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__481__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__482__bits 
                                    = __Vfunc_fp32_mul__479__lhs;
                                __Vfunc_fp32_is_inf__482__unused_sign = 0;
                                __Vfunc_fp32_is_inf__482__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__482__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__482__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__482__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__482__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__483__bits 
                                    = __Vfunc_fp32_mul__479__rhs;
                                __Vfunc_fp32_is_zero__483__unused_sign = 0;
                                __Vfunc_fp32_is_zero__483__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__483__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__483__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__483__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__483__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__484__bits 
                                    = __Vfunc_fp32_mul__479__rhs;
                                __Vfunc_fp32_is_inf__484__unused_sign = 0;
                                __Vfunc_fp32_is_inf__484__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__484__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__484__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__484__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__484__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__485__bits 
                                    = __Vfunc_fp32_mul__479__lhs;
                                __Vfunc_fp32_is_zero__485__unused_sign = 0;
                                __Vfunc_fp32_is_zero__485__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__485__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__485__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__485__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__485__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__479__Vfuncout = 0x7fc00000U;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_mul__479__result_sign 
            = ((__Vfunc_fp32_mul__479__lhs ^ __Vfunc_fp32_mul__479__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__486__bits 
                            = __Vfunc_fp32_mul__479__lhs;
                        __Vfunc_fp32_is_inf__486__unused_sign = 0;
                        __Vfunc_fp32_is_inf__486__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__486__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__486__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__486__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__486__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__487__bits 
                            = __Vfunc_fp32_mul__479__rhs;
                        __Vfunc_fp32_is_inf__487__unused_sign = 0;
                        __Vfunc_fp32_is_inf__487__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__487__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__487__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__487__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__487__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__479__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__488__bits 
                            = __Vfunc_fp32_mul__479__lhs;
                        __Vfunc_fp32_is_zero__488__unused_sign = 0;
                        __Vfunc_fp32_is_zero__488__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__488__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__488__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__488__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__488__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__489__bits 
                            = __Vfunc_fp32_mul__479__rhs;
                        __Vfunc_fp32_is_zero__489__unused_sign = 0;
                        __Vfunc_fp32_is_zero__489__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__489__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__489__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__489__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__489__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__479__result_sign) 
                   << 0x1fU);
            goto __Vlabel0;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__479__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__479__lhs);
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__479__lhs));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__479__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__479__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__479__rhs);
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__479__rhs));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__479__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__479__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__479__normalize_count = 1U;
        __Vfunc_fp32_mul__479__normalize_count = 2U;
        __Vfunc_fp32_mul__479__normalize_count = 3U;
        __Vfunc_fp32_mul__479__normalize_count = 4U;
        __Vfunc_fp32_mul__479__normalize_count = 5U;
        __Vfunc_fp32_mul__479__normalize_count = 6U;
        __Vfunc_fp32_mul__479__normalize_count = 7U;
        __Vfunc_fp32_mul__479__normalize_count = 8U;
        __Vfunc_fp32_mul__479__normalize_count = 9U;
        __Vfunc_fp32_mul__479__normalize_count = 0xaU;
        __Vfunc_fp32_mul__479__normalize_count = 0xbU;
        __Vfunc_fp32_mul__479__normalize_count = 0xcU;
        __Vfunc_fp32_mul__479__normalize_count = 0xdU;
        __Vfunc_fp32_mul__479__normalize_count = 0xeU;
        __Vfunc_fp32_mul__479__normalize_count = 0xfU;
        __Vfunc_fp32_mul__479__normalize_count = 0x10U;
        __Vfunc_fp32_mul__479__normalize_count = 0x11U;
        __Vfunc_fp32_mul__479__normalize_count = 0x12U;
        __Vfunc_fp32_mul__479__normalize_count = 0x13U;
        __Vfunc_fp32_mul__479__normalize_count = 0x14U;
        __Vfunc_fp32_mul__479__normalize_count = 0x15U;
        __Vfunc_fp32_mul__479__normalize_count = 0x16U;
        __Vfunc_fp32_mul__479__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__479__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__479__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__479__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__479__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__479__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__479__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__479__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__479__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__479__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__479__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__479__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__479__mantissa = 
            (0xffffffU & (IData)((0xffffffffffffULL 
                                  & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__479__product, vlSelfRef.__Vfunc_fp32_mul__479__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__479__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__479__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__479__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__479__product 
               & vlSelfRef.__Vfunc_fp32_mul__479__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__479__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__479__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__479__rounded = vlSelfRef.__Vfunc_fp32_mul__479__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__479__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__479__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__479__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__479__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__479__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__479__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__479__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__479__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__479__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__479__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__479__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__479__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__479__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__479__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__479__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__479__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__479__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__479__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__479__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__479__result_sign) 
                   << 0x1fU);
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_mul__479__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_mul__479__result_sign) 
              << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                            + vlSelfRef.__Vfunc_fp32_mul__479__result_unbiased) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__479__mantissa)));
        __Vlabel0: ;
    }
    tb_npu_engines__DOT__u_complex__DOT__fp_norm_scaled 
        = vlSelfRef.__Vfunc_fp32_mul__479__Vfuncout;
    __Vfunc_fp32_add__490__rhs = ((5U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x13U])
                                   ? vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src2_fp
                                   : 0U);
    __Vfunc_fp32_add__490__lhs = tb_npu_engines__DOT__u_complex__DOT__fp_norm_scaled;
    vlSelf->__Vfunc_fp32_add__490__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1144817964917011942ull);
    vlSelf->__Vfunc_fp32_add__490__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16548783555401161297ull);
    vlSelf->__Vfunc_fp32_add__490__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11154733197930335788ull);
    vlSelf->__Vfunc_fp32_add__490__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10065171169371651707ull);
    vlSelf->__Vfunc_fp32_add__490__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5260476243316193487ull);
    vlSelf->__Vfunc_fp32_add__490__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 1966790831468361665ull);
    vlSelf->__Vfunc_fp32_add__490__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 12046489615980421342ull);
    vlSelf->__Vfunc_fp32_add__490__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14469467052735907496ull);
    vlSelf->__Vfunc_fp32_add__490__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10137705826370580493ull);
    vlSelf->__Vfunc_fp32_add__490__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13054887408318435734ull);
    vlSelf->__Vfunc_fp32_add__490__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13948851823756064544ull);
    vlSelf->__Vfunc_fp32_add__490__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15191823158783319149ull);
    vlSelf->__Vfunc_fp32_add__490__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15007131809881262199ull);
    vlSelf->__Vfunc_fp32_add__490__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10886387888876160255ull);
    vlSelf->__Vfunc_fp32_add__490__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 4761840107588244788ull);
    vlSelf->__Vfunc_fp32_add__490__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 8069628603923226247ull);
    vlSelf->__Vfunc_fp32_add__490__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 10807136275312242584ull);
    vlSelf->__Vfunc_fp32_add__490__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 18220391917416228089ull);
    vlSelf->__Vfunc_fp32_add__490__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 11223231734502659095ull);
    vlSelf->__Vfunc_fp32_add__490__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 17341174802808692677ull);
    vlSelf->__Vfunc_fp32_add__490__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5739987495844815379ull);
    vlSelf->__Vfunc_fp32_add__490__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 964563265619036799ull);
    vlSelf->__Vfunc_fp32_add__490__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5773011566833932576ull);
    vlSelf->__Vfunc_fp32_add__490__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1348536531321516748ull);
    __Vfunc_fp32_add__490__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__491__bits 
                            = __Vfunc_fp32_add__490__lhs;
                        __Vfunc_fp32_is_nan__491__unused_sign = 0;
                        __Vfunc_fp32_is_nan__491__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__491__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__491__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__491__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__491__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__491__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__492__bits 
                            = __Vfunc_fp32_add__490__rhs;
                        __Vfunc_fp32_is_nan__492__unused_sign = 0;
                        __Vfunc_fp32_is_nan__492__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__492__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__492__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__492__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__492__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__492__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__490__Vfuncout = 0x7fc00000U;
            goto __Vlabel1;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__493__bits 
                            = __Vfunc_fp32_add__490__lhs;
                        __Vfunc_fp32_is_inf__493__unused_sign = 0;
                        __Vfunc_fp32_is_inf__493__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__493__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__493__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__493__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__493__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__494__bits 
                            = __Vfunc_fp32_add__490__rhs;
                        __Vfunc_fp32_is_inf__494__unused_sign = 0;
                        __Vfunc_fp32_is_inf__494__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__494__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__494__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__494__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__494__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__495__bits 
                                    = __Vfunc_fp32_add__490__lhs;
                                __Vfunc_fp32_is_inf__495__unused_sign = 0;
                                __Vfunc_fp32_is_inf__495__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__495__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__495__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__495__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__495__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__496__bits 
                                    = __Vfunc_fp32_add__490__rhs;
                                __Vfunc_fp32_is_inf__496__unused_sign = 0;
                                __Vfunc_fp32_is_inf__496__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__496__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__496__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__496__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__496__Vfuncout))) 
                 & ((__Vfunc_fp32_add__490__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__490__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__490__Vfuncout = 0x7fc00000U;
                goto __Vlabel1;
            }
            vlSelfRef.__Vfunc_fp32_add__490__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__497__bits 
                            = __Vfunc_fp32_add__490__lhs;
                        __Vfunc_fp32_is_inf__497__unused_sign = 0;
                        __Vfunc_fp32_is_inf__497__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__497__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__497__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__497__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__497__Vfuncout))
                    ? __Vfunc_fp32_add__490__lhs : __Vfunc_fp32_add__490__rhs);
            goto __Vlabel1;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__498__bits 
                        = __Vfunc_fp32_add__490__lhs;
                    __Vfunc_fp32_is_zero__498__unused_sign = 0;
                    __Vfunc_fp32_is_zero__498__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__498__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__498__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__498__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__498__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__490__Vfuncout 
                = __Vfunc_fp32_add__490__rhs;
            goto __Vlabel1;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__499__bits 
                        = __Vfunc_fp32_add__490__rhs;
                    __Vfunc_fp32_is_zero__499__unused_sign = 0;
                    __Vfunc_fp32_is_zero__499__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__499__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__499__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__499__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__499__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__490__Vfuncout 
                = __Vfunc_fp32_add__490__lhs;
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_add__490__lhs_sign = 
            (__Vfunc_fp32_add__490__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__490__rhs_sign = 
            (__Vfunc_fp32_add__490__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__490__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__490__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__490__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__490__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__490__lhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__490__lhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__490__lhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__490__lhs)));
        vlSelfRef.__Vfunc_fp32_add__490__rhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__490__rhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__490__rhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__490__rhs)));
        vlSelfRef.__Vfunc_fp32_add__490__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__490__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__490__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__490__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__490__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__490__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__490__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__490__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__490__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__490__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__490__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__490__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__490__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__490__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__490__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__490__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__490__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__490__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__490__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__490__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__490__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__490__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__490__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__490__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__490__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__490__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__490__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__490__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__490__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__490__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__490__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__490__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__490__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__490__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__490__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__490__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__490__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__490__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__490__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__490__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__490__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__490__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__490__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__490__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__490__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__490__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__small_ext, vlSelfRef.__Vfunc_fp32_add__490__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__490__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__490__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__490__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__490__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__490__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__490__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__490__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__490__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__490__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__490__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__490__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__490__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__490__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__490__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__490__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__490__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__490__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__490__work_ext);
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__490__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__490__sticky))));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__490__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__490__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__490__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__490__Vfuncout = 0U;
                goto __Vlabel1;
            }
            __Vfunc_fp32_add__490__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__490__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__490__normalize_count = 1U;
            __Vfunc_fp32_add__490__normalize_count = 2U;
            __Vfunc_fp32_add__490__normalize_count = 3U;
            __Vfunc_fp32_add__490__normalize_count = 4U;
            __Vfunc_fp32_add__490__normalize_count = 5U;
            __Vfunc_fp32_add__490__normalize_count = 6U;
            __Vfunc_fp32_add__490__normalize_count = 7U;
            __Vfunc_fp32_add__490__normalize_count = 8U;
            __Vfunc_fp32_add__490__normalize_count = 9U;
            __Vfunc_fp32_add__490__normalize_count = 0xaU;
            __Vfunc_fp32_add__490__normalize_count = 0xbU;
            __Vfunc_fp32_add__490__normalize_count = 0xcU;
            __Vfunc_fp32_add__490__normalize_count = 0xdU;
            __Vfunc_fp32_add__490__normalize_count = 0xeU;
            __Vfunc_fp32_add__490__normalize_count = 0xfU;
            __Vfunc_fp32_add__490__normalize_count = 0x10U;
            __Vfunc_fp32_add__490__normalize_count = 0x11U;
            __Vfunc_fp32_add__490__normalize_count = 0x12U;
            __Vfunc_fp32_add__490__normalize_count = 0x13U;
            __Vfunc_fp32_add__490__normalize_count = 0x14U;
            __Vfunc_fp32_add__490__normalize_count = 0x15U;
            __Vfunc_fp32_add__490__normalize_count = 0x16U;
            __Vfunc_fp32_add__490__normalize_count = 0x17U;
            __Vfunc_fp32_add__490__normalize_count = 0x18U;
            __Vfunc_fp32_add__490__normalize_count = 0x19U;
            __Vfunc_fp32_add__490__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__490__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_add__490__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__490__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__490__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__490__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__490__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__490__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__490__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__490__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__490__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__490__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__490__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__490__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__490__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__490__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__490__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__490__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__490__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__490__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__490__mantissa));
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_add__490__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_add__490__result_sign) 
              << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__490__large_exp) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__490__mantissa)));
        __Vlabel1: ;
    }
    tb_npu_engines__DOT__u_complex__DOT__fp_norm_output 
        = vlSelfRef.__Vfunc_fp32_add__490__Vfuncout;
    tb_npu_engines__DOT__u_complex__DOT__fp_output_value 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_result;
    if ((0x86U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q))) {
        tb_npu_engines__DOT__u_complex__DOT__fp_output_value 
            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_add_rescale_output;
    } else if ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
        tb_npu_engines__DOT__u_complex__DOT__fp_output_value 
            = (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__531__bits 
                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_q;
                    vlSelfRef.__Vfunc_fp32_is_zero__531__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__531__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__531__Vfuncout))
                ? 0U : tb_npu_engines__DOT__u_complex__DOT__fp_softmax_output);
    } else if ((5U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) {
        tb_npu_engines__DOT__u_complex__DOT__fp_output_value 
            = tb_npu_engines__DOT__u_complex__DOT__fp_norm_output;
    }
    __Vfunc_fp32_div__2623__denominator_value = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x1fU];
    __Vfunc_fp32_div__2623__numerator_value = tb_npu_engines__DOT__u_complex__DOT__fp_output_value;
    vlSelf->__Vfunc_fp32_div__2623__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2861014193105374931ull);
    vlSelf->__Vfunc_fp32_div__2623__numerator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5054078198511579177ull);
    vlSelf->__Vfunc_fp32_div__2623__denominator_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5686474386445700368ull);
    vlSelf->__Vfunc_fp32_div__2623__scaled_numerator = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 7488158356372350441ull);
    vlSelf->__Vfunc_fp32_div__2623__denominator_wide = VL_SCOPED_RAND_RESET_Q(56, __VscopeHash, 15855140941900070820ull);
    vlSelf->__Vfunc_fp32_div__2623__division_remainder = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8743119056594161751ull);
    vlSelf->__Vfunc_fp32_div__2623__quotient_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 2557518187087188635ull);
    vlSelf->__Vfunc_fp32_div__2623__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 15642723383689281451ull);
    vlSelf->__Vfunc_fp32_div__2623__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18076387138854137129ull);
    vlSelf->__Vfunc_fp32_div__2623__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13094554961238689453ull);
    vlSelf->__Vfunc_fp32_div__2623__numerator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13984658376077460882ull);
    vlSelf->__Vfunc_fp32_div__2623__denominator_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7330413829909617887ull);
    vlSelf->__Vfunc_fp32_div__2623__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12102766619150580528ull);
    __Vfunc_fp32_div__2623__normalize_count = 0;
    {
        if ((((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__2624__bits 
                                    = __Vfunc_fp32_div__2623__numerator_value;
                                __Vfunc_fp32_is_nan__2624__unused_sign = 0;
                                __Vfunc_fp32_is_nan__2624__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__2624__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__2624__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2624__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__2624__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2624__Vfuncout)) 
               | ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_nan__2625__bits 
                                    = __Vfunc_fp32_div__2623__denominator_value;
                                __Vfunc_fp32_is_nan__2625__unused_sign = 0;
                                __Vfunc_fp32_is_nan__2625__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_nan__2625__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_nan__2625__Vfuncout 
                                    = (IData)(((0x7f800000U 
                                                == 
                                                (0x7f800000U 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2625__bits)) 
                                               & (0U 
                                                  != 
                                                  (0x7fffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_nan__2625__bits))));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2625__Vfuncout))) 
              | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2626__bits 
                                    = __Vfunc_fp32_div__2623__numerator_value;
                                __Vfunc_fp32_is_zero__2626__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2626__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2626__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2626__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2626__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2626__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__2627__bits 
                                    = __Vfunc_fp32_div__2623__denominator_value;
                                __Vfunc_fp32_is_zero__2627__unused_sign = 0;
                                __Vfunc_fp32_is_zero__2627__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__2627__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__2627__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__2627__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2627__Vfuncout)))) 
             | (([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2628__bits 
                                = __Vfunc_fp32_div__2623__numerator_value;
                            __Vfunc_fp32_is_inf__2628__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2628__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2628__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2628__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2628__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2628__Vfuncout)) 
                & ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2629__bits 
                                = __Vfunc_fp32_div__2623__denominator_value;
                            __Vfunc_fp32_is_inf__2629__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2629__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2629__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2629__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2629__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2629__Vfuncout))))) {
            vlSelfRef.__Vfunc_fp32_div__2623__Vfuncout = 0x7fc00000U;
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_div__2623__result_sign 
            = ((__Vfunc_fp32_div__2623__numerator_value 
                ^ __Vfunc_fp32_div__2623__denominator_value) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2630__bits 
                            = __Vfunc_fp32_div__2623__numerator_value;
                        __Vfunc_fp32_is_inf__2630__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2630__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2630__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2630__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2630__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2630__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2631__bits 
                            = __Vfunc_fp32_div__2623__denominator_value;
                        __Vfunc_fp32_is_zero__2631__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2631__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2631__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2631__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2631__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2631__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__2623__result_sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2632__bits 
                            = __Vfunc_fp32_div__2623__numerator_value;
                        __Vfunc_fp32_is_zero__2632__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2632__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2632__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2632__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2632__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2632__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2633__bits 
                            = __Vfunc_fp32_div__2623__denominator_value;
                        __Vfunc_fp32_is_inf__2633__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2633__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2633__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2633__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2633__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2633__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__2623__result_sign) 
                   << 0x1fU);
            goto __Vlabel2;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__2623__numerator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__2623__numerator_value);
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__2623__numerator_value));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__2623__numerator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_div__2623__denominator_value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0x7fffffU & __Vfunc_fp32_div__2623__denominator_value);
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_div__2623__denominator_value));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = ((0xffU & (__Vfunc_fp32_div__2623__denominator_value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_div__2623__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_div__2623__normalize_count = 1U;
        __Vfunc_fp32_div__2623__normalize_count = 2U;
        __Vfunc_fp32_div__2623__normalize_count = 3U;
        __Vfunc_fp32_div__2623__normalize_count = 4U;
        __Vfunc_fp32_div__2623__normalize_count = 5U;
        __Vfunc_fp32_div__2623__normalize_count = 6U;
        __Vfunc_fp32_div__2623__normalize_count = 7U;
        __Vfunc_fp32_div__2623__normalize_count = 8U;
        __Vfunc_fp32_div__2623__normalize_count = 9U;
        __Vfunc_fp32_div__2623__normalize_count = 0xaU;
        __Vfunc_fp32_div__2623__normalize_count = 0xbU;
        __Vfunc_fp32_div__2623__normalize_count = 0xcU;
        __Vfunc_fp32_div__2623__normalize_count = 0xdU;
        __Vfunc_fp32_div__2623__normalize_count = 0xeU;
        __Vfunc_fp32_div__2623__normalize_count = 0xfU;
        __Vfunc_fp32_div__2623__normalize_count = 0x10U;
        __Vfunc_fp32_div__2623__normalize_count = 0x11U;
        __Vfunc_fp32_div__2623__normalize_count = 0x12U;
        __Vfunc_fp32_div__2623__normalize_count = 0x13U;
        __Vfunc_fp32_div__2623__normalize_count = 0x14U;
        __Vfunc_fp32_div__2623__normalize_count = 0x15U;
        __Vfunc_fp32_div__2623__normalize_count = 0x16U;
        __Vfunc_fp32_div__2623__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_div__2623__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_div__2623__numerator_unbiased 
               - vlSelfRef.__Vfunc_fp32_div__2623__denominator_unbiased);
        vlSelfRef.__Vfunc_fp32_div__2623__scaled_numerator 
            = (0xffffffffffffffULL & VL_SHIFTL_QQI(56,56,32, (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__2623__numerator_mant)), 0x1aU));
        vlSelfRef.__Vfunc_fp32_div__2623__denominator_wide 
            = (QData)((IData)(vlSelfRef.__Vfunc_fp32_div__2623__denominator_mant));
        vlSelfRef.__Vfunc_fp32_div__2623__quotient_ext 
            = (0xfffffffU & (IData)((0xffffffffffffffULL 
                                     & VL_DIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__2623__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__2623__denominator_wide))));
        vlSelfRef.__Vfunc_fp32_div__2623__division_remainder 
            = (0xffffffU & (IData)((0xffffffffffffffULL 
                                    & VL_MODDIV_QQQ(56, vlSelfRef.__Vfunc_fp32_div__2623__scaled_numerator, vlSelfRef.__Vfunc_fp32_div__2623__denominator_wide))));
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_div__2623__quotient_ext 
                      >> 0x1aU)))) {
            vlSelfRef.__Vfunc_fp32_div__2623__quotient_ext 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_div__2623__quotient_ext, 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__result_unbiased 
                = (vlSelfRef.__Vfunc_fp32_div__2623__result_unbiased 
                   - (IData)(1U));
        }
        if ((0U != vlSelfRef.__Vfunc_fp32_div__2623__division_remainder)) {
            vlSelfRef.__Vfunc_fp32_div__2623__quotient_ext 
                = (1U | vlSelfRef.__Vfunc_fp32_div__2623__quotient_ext);
        }
        vlSelfRef.__Vfunc_fp32_div__2623__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__2623__quotient_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_div__2623__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_div__2623__quotient_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_div__2623__quotient_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_div__2623__quotient_ext) 
                                | vlSelfRef.__Vfunc_fp32_div__2623__mantissa)));
        vlSelfRef.__Vfunc_fp32_div__2623__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_div__2623__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_div__2623__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_div__2623__rounded)) {
            vlSelfRef.__Vfunc_fp32_div__2623__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_div__2623__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_div__2623__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_div__2623__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_div__2623__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_div__2623__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_div__2623__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__2623__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_div__2623__result_sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_div__2623__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_div__2623__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_div__2623__result_sign) 
                   << 0x1fU);
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_div__2623__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_div__2623__result_sign) 
                << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                              + vlSelfRef.__Vfunc_fp32_div__2623__result_unbiased) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_div__2623__mantissa)));
        __Vlabel2: ;
    }
    tb_npu_engines__DOT__u_complex__DOT__u_f2i__DOT__scaled_value 
        = vlSelfRef.__Vfunc_fp32_div__2623__Vfuncout;
    __Vfunc_fp32_to_int_round__2634__rounding = (3U 
                                                 & (vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0xeU] 
                                                    >> 0xaU));
    __Vfunc_fp32_to_int_round__2634__value = tb_npu_engines__DOT__u_complex__DOT__u_f2i__DOT__scaled_value;
    vlSelf->__Vfunc_fp32_to_int_round__2634__sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 982948244329637922ull);
    vlSelf->__Vfunc_fp32_to_int_round__2634__significand = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7722851180201652121ull);
    vlSelf->__Vfunc_fp32_to_int_round__2634__magnitude = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 362878263823593862ull);
    vlSelf->__Vfunc_fp32_to_int_round__2634__quotient = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13930182669596921100ull);
    vlSelf->__Vfunc_fp32_to_int_round__2634__remainder = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13626221763764254784ull);
    vlSelf->__Vfunc_fp32_to_int_round__2634__remainder_mask = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9623516593672568498ull);
    vlSelf->__Vfunc_fp32_to_int_round__2634__halfway = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1215090860736625501ull);
    vlSelf->__Vfunc_fp32_to_int_round__2634__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5347881829321470399ull);
    vlSelf->__Vfunc_fp32_to_int_round__2634__unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8240700574626025202ull);
    vlSelf->__Vfunc_fp32_to_int_round__2634__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15630066342765484822ull);
    {
        vlSelfRef.__Vfunc_fp32_to_int_round__2634__sign 
            = (__Vfunc_fp32_to_int_round__2634__value 
               >> 0x1fU);
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_nan__2635__bits 
                        = __Vfunc_fp32_to_int_round__2634__value;
                    __Vfunc_fp32_is_nan__2635__unused_sign = 0;
                    __Vfunc_fp32_is_nan__2635__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_nan__2635__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_nan__2635__Vfuncout 
                        = (IData)(((0x7f800000U == 
                                    (0x7f800000U & vlSelfRef.__Vfunc_fp32_is_nan__2635__bits)) 
                                   & (0U != (0x7fffffU 
                                             & vlSelfRef.__Vfunc_fp32_is_nan__2635__bits))));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2635__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_to_int_round__2634__Vfuncout = 0ULL;
            goto __Vlabel3;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_inf__2636__bits 
                        = __Vfunc_fp32_to_int_round__2634__value;
                    __Vfunc_fp32_is_inf__2636__unused_sign = 0;
                    __Vfunc_fp32_is_inf__2636__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_inf__2636__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_inf__2636__Vfuncout 
                        = (IData)((0x7f800000U == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2636__bits)));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2636__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_to_int_round__2634__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__2634__sign)
                    ? 0x8000000000000000ULL : 0x7fffffffffffffffULL);
            goto __Vlabel3;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2637__bits 
                        = __Vfunc_fp32_to_int_round__2634__value;
                    __Vfunc_fp32_is_zero__2637__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2637__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2637__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2637__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2637__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2637__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_to_int_round__2634__Vfuncout = 0ULL;
            goto __Vlabel3;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_to_int_round__2634__value 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_to_int_round__2634__significand 
                = (0x7fffffU & __Vfunc_fp32_to_int_round__2634__value);
            vlSelfRef.__Vfunc_fp32_to_int_round__2634__unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_to_int_round__2634__significand 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_to_int_round__2634__value));
            vlSelfRef.__Vfunc_fp32_to_int_round__2634__unbiased 
                = ((0xffU & (__Vfunc_fp32_to_int_round__2634__value 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        vlSelfRef.__Vfunc_fp32_to_int_round__2634__quotient = 0ULL;
        vlSelfRef.__Vfunc_fp32_to_int_round__2634__remainder = 0ULL;
        vlSelfRef.__Vfunc_fp32_to_int_round__2634__halfway = 0ULL;
        if (VL_LTES_III(32, 0x3fU, vlSelfRef.__Vfunc_fp32_to_int_round__2634__unbiased)) {
            vlSelfRef.__Vfunc_fp32_to_int_round__2634__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__2634__sign)
                    ? 0x8000000000000000ULL : 0x7fffffffffffffffULL);
            goto __Vlabel3;
        }
        if (VL_LTES_III(32, 0x17U, vlSelfRef.__Vfunc_fp32_to_int_round__2634__unbiased)) {
            vlSelfRef.__Vfunc_fp32_to_int_round__2634__quotient 
                = VL_SHIFTL_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__2634__significand)), 
                                (vlSelfRef.__Vfunc_fp32_to_int_round__2634__unbiased 
                                 - (IData)(0x17U)));
        } else {
            vlSelfRef.__Vfunc_fp32_to_int_round__2634__shift_amount 
                = ((IData)(0x17U) - vlSelfRef.__Vfunc_fp32_to_int_round__2634__unbiased);
            if (VL_LTES_III(32, 0x40U, vlSelfRef.__Vfunc_fp32_to_int_round__2634__shift_amount)) {
                vlSelfRef.__Vfunc_fp32_to_int_round__2634__quotient = 0ULL;
                vlSelfRef.__Vfunc_fp32_to_int_round__2634__remainder 
                    = (QData)((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__2634__significand));
                vlSelfRef.__Vfunc_fp32_to_int_round__2634__halfway = 0xffffffffffffffffULL;
            } else {
                vlSelfRef.__Vfunc_fp32_to_int_round__2634__quotient 
                    = VL_SHIFTR_QQI(64,64,32, (QData)((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__2634__significand)), vlSelfRef.__Vfunc_fp32_to_int_round__2634__shift_amount);
                vlSelfRef.__Vfunc_fp32_to_int_round__2634__remainder_mask 
                    = (VL_SHIFTL_QQI(64,64,32, 1ULL, vlSelfRef.__Vfunc_fp32_to_int_round__2634__shift_amount) 
                       - 1ULL);
                vlSelfRef.__Vfunc_fp32_to_int_round__2634__remainder 
                    = ((QData)((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__2634__significand)) 
                       & vlSelfRef.__Vfunc_fp32_to_int_round__2634__remainder_mask);
                vlSelfRef.__Vfunc_fp32_to_int_round__2634__halfway 
                    = VL_SHIFTL_QQI(64,64,32, 1ULL, 
                                    (vlSelfRef.__Vfunc_fp32_to_int_round__2634__shift_amount 
                                     - (IData)(1U)));
            }
        }
        vlSelfRef.__Vfunc_fp32_to_int_round__2634__increment = 0U;
        vlSelfRef.__Vfunc_fp32_to_int_round__2634__increment 
            = ((0U == (IData)(__Vfunc_fp32_to_int_round__2634__rounding))
                ? ((vlSelfRef.__Vfunc_fp32_to_int_round__2634__remainder 
                    > vlSelfRef.__Vfunc_fp32_to_int_round__2634__halfway) 
                   | ((vlSelfRef.__Vfunc_fp32_to_int_round__2634__remainder 
                       == vlSelfRef.__Vfunc_fp32_to_int_round__2634__halfway) 
                      & (IData)(vlSelfRef.__Vfunc_fp32_to_int_round__2634__quotient)))
                : ((2U == (IData)(__Vfunc_fp32_to_int_round__2634__rounding))
                    ? ((~ (IData)(vlSelfRef.__Vfunc_fp32_to_int_round__2634__sign)) 
                       & (0ULL != vlSelfRef.__Vfunc_fp32_to_int_round__2634__remainder))
                    : ((3U == (IData)(__Vfunc_fp32_to_int_round__2634__rounding)) 
                       && ((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__2634__sign) 
                           & (0ULL != vlSelfRef.__Vfunc_fp32_to_int_round__2634__remainder)))));
        vlSelfRef.__Vfunc_fp32_to_int_round__2634__magnitude 
            = (vlSelfRef.__Vfunc_fp32_to_int_round__2634__quotient 
               + (QData)((IData)(vlSelfRef.__Vfunc_fp32_to_int_round__2634__increment)));
        if (vlSelfRef.__Vfunc_fp32_to_int_round__2634__sign) {
            if ((0x8000000000000000ULL <= vlSelfRef.__Vfunc_fp32_to_int_round__2634__magnitude)) {
                vlSelfRef.__Vfunc_fp32_to_int_round__2634__Vfuncout = 0x8000000000000000ULL;
                goto __Vlabel3;
            }
            vlSelfRef.__Vfunc_fp32_to_int_round__2634__Vfuncout 
                = (1ULL + (~ vlSelfRef.__Vfunc_fp32_to_int_round__2634__magnitude));
            goto __Vlabel3;
        }
        if ((0x7fffffffffffffffULL < vlSelfRef.__Vfunc_fp32_to_int_round__2634__magnitude)) {
            vlSelfRef.__Vfunc_fp32_to_int_round__2634__Vfuncout = 0x7fffffffffffffffULL;
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_to_int_round__2634__Vfuncout 
            = vlSelfRef.__Vfunc_fp32_to_int_round__2634__magnitude;
        __Vlabel3: ;
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__f2i_result 
        = vlSelfRef.__Vfunc_fp32_to_int_round__2634__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__f2i_exceptional 
        = (([&]() {
                vlSelfRef.__Vfunc_fp32_is_nan__2638__bits 
                    = tb_npu_engines__DOT__u_complex__DOT__u_f2i__DOT__scaled_value;
                vlSelfRef.__Vfunc_fp32_is_nan__2638__Vfuncout 
                    = (IData)(((0x7f800000U == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2638__bits)) 
                               & (0U != (0x7fffffU 
                                         & vlSelfRef.__Vfunc_fp32_is_nan__2638__bits))));
            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2638__Vfuncout)) 
           | ([&]() {
                vlSelfRef.__Vfunc_fp32_is_inf__2639__bits 
                    = tb_npu_engines__DOT__u_complex__DOT__u_f2i__DOT__scaled_value;
                vlSelfRef.__Vfunc_fp32_is_inf__2639__Vfuncout 
                    = (IData)((0x7f800000U == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2639__bits)));
            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2639__Vfuncout)));
}
