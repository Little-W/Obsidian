// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_engines.h for the primary calling header

#include "Vtb_npu_engines__pch.h"
#include "Vtb_npu_engines___024root.h"

VL_INLINE_OPT void Vtb_npu_engines___024root___nba_sequent__TOP__5(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___nba_sequent__TOP__5\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_npu_engines__DOT__u_complex__DOT__fp_mean_squared;
    tb_npu_engines__DOT__u_complex__DOT__fp_mean_squared = 0;
    IData/*31:0*/ tb_npu_engines__DOT__u_complex__DOT__fp_variance;
    tb_npu_engines__DOT__u_complex__DOT__fp_variance = 0;
    IData/*31:0*/ tb_npu_engines__DOT__u_complex__DOT__fp_variance_plus_epsilon;
    tb_npu_engines__DOT__u_complex__DOT__fp_variance_plus_epsilon = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__342__unused_sign;
    __Vfunc_fp32_is_nan__342__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__343__unused_sign;
    __Vfunc_fp32_is_nan__343__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__345__unused_sign;
    __Vfunc_fp32_is_nan__345__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__346__unused_sign;
    __Vfunc_fp32_is_nan__346__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__347__unused_sign;
    __Vfunc_fp32_is_zero__347__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__348__unused_sign;
    __Vfunc_fp32_is_zero__348__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__350__unused_sign;
    __Vfunc_fp32_is_nan__350__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__351__unused_sign;
    __Vfunc_fp32_is_nan__351__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__353__unused_sign;
    __Vfunc_fp32_is_nan__353__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__354__unused_sign;
    __Vfunc_fp32_is_nan__354__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__355__unused_sign;
    __Vfunc_fp32_is_zero__355__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__356__unused_sign;
    __Vfunc_fp32_is_zero__356__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__358__normalize_count;
    __Vfunc_fp32_add__358__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__360__unused_sign;
    __Vfunc_fp32_is_nan__360__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__361__unused_sign;
    __Vfunc_fp32_is_nan__361__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__362__unused_sign;
    __Vfunc_fp32_is_inf__362__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__363__unused_sign;
    __Vfunc_fp32_is_inf__363__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__364__unused_sign;
    __Vfunc_fp32_is_inf__364__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__365__unused_sign;
    __Vfunc_fp32_is_inf__365__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__366__unused_sign;
    __Vfunc_fp32_is_inf__366__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__367__unused_sign;
    __Vfunc_fp32_is_zero__367__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__368__unused_sign;
    __Vfunc_fp32_is_zero__368__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__423__lhs;
    __Vfunc_fp32_mul__423__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__423__rhs;
    __Vfunc_fp32_mul__423__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__423__normalize_count;
    __Vfunc_fp32_mul__423__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__424__unused_sign;
    __Vfunc_fp32_is_nan__424__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__425__unused_sign;
    __Vfunc_fp32_is_nan__425__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__426__unused_sign;
    __Vfunc_fp32_is_inf__426__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__427__unused_sign;
    __Vfunc_fp32_is_zero__427__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__428__unused_sign;
    __Vfunc_fp32_is_inf__428__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__429__unused_sign;
    __Vfunc_fp32_is_zero__429__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__430__unused_sign;
    __Vfunc_fp32_is_inf__430__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__431__unused_sign;
    __Vfunc_fp32_is_inf__431__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__432__unused_sign;
    __Vfunc_fp32_is_zero__432__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__433__unused_sign;
    __Vfunc_fp32_is_zero__433__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__434__Vfuncout;
    __Vfunc_fp32_sub__434__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__434__lhs;
    __Vfunc_fp32_sub__434__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__434__rhs;
    __Vfunc_fp32_sub__434__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__435__lhs;
    __Vfunc_fp32_add__435__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__435__rhs;
    __Vfunc_fp32_add__435__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__435__normalize_count;
    __Vfunc_fp32_add__435__normalize_count = 0;
    IData/*31:0*/ __Vfunc_fp32_neg__436__Vfuncout;
    __Vfunc_fp32_neg__436__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_neg__436__value;
    __Vfunc_fp32_neg__436__value = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__437__unused_sign;
    __Vfunc_fp32_is_nan__437__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__438__unused_sign;
    __Vfunc_fp32_is_nan__438__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__439__unused_sign;
    __Vfunc_fp32_is_inf__439__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__440__unused_sign;
    __Vfunc_fp32_is_inf__440__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__441__unused_sign;
    __Vfunc_fp32_is_inf__441__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__442__unused_sign;
    __Vfunc_fp32_is_inf__442__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__443__unused_sign;
    __Vfunc_fp32_is_inf__443__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__444__unused_sign;
    __Vfunc_fp32_is_zero__444__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__445__unused_sign;
    __Vfunc_fp32_is_zero__445__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__446__lhs;
    __Vfunc_fp32_add__446__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__446__rhs;
    __Vfunc_fp32_add__446__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__446__normalize_count;
    __Vfunc_fp32_add__446__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__447__unused_sign;
    __Vfunc_fp32_is_nan__447__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__448__unused_sign;
    __Vfunc_fp32_is_nan__448__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__449__unused_sign;
    __Vfunc_fp32_is_inf__449__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__450__unused_sign;
    __Vfunc_fp32_is_inf__450__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__451__unused_sign;
    __Vfunc_fp32_is_inf__451__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__452__unused_sign;
    __Vfunc_fp32_is_inf__452__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__453__unused_sign;
    __Vfunc_fp32_is_inf__453__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__454__unused_sign;
    __Vfunc_fp32_is_zero__454__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__455__unused_sign;
    __Vfunc_fp32_is_zero__455__unused_sign = 0;
    // Body
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_mean_square 
        = vlSelfRef.__Vfunc_fp32_div__412__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[3U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[2U]))) 
           + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_offset);
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr 
        = ((((QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[9U])) 
             << 0x20U) | (QData)((IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[8U]))) 
           + vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_offset);
    vlSelfRef.tb_npu_engines__DOT__complex_l1_req_wstrb = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
                        vlSelfRef.tb_npu_engines__DOT__complex_l1_req_wstrb 
                            = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT____VdfgExtracted_h20747776__0;
                    }
                }
            }
        }
    }
    __Vfunc_fp32_mul__423__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_mean;
    __Vfunc_fp32_mul__423__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_mean;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_mul__423__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12019196470894682938ull);
    vlSelf->__Vfunc_fp32_mul__423__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 2961078907560178931ull);
    vlSelf->__Vfunc_fp32_mul__423__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 1376357362019319957ull);
    vlSelf->__Vfunc_fp32_mul__423__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 5480222938107668763ull);
    vlSelf->__Vfunc_fp32_mul__423__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 11298530927575735694ull);
    vlSelf->__Vfunc_fp32_mul__423__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 9842338694120606745ull);
    vlSelf->__Vfunc_fp32_mul__423__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 15702538960974458655ull);
    vlSelf->__Vfunc_fp32_mul__423__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 11704909168728808439ull);
    vlSelf->__Vfunc_fp32_mul__423__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15610710724799293425ull);
    vlSelf->__Vfunc_fp32_mul__423__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17287474703911681977ull);
    vlSelf->__Vfunc_fp32_mul__423__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12867200073725768564ull);
    vlSelf->__Vfunc_fp32_mul__423__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16392815303048493988ull);
    vlSelf->__Vfunc_fp32_mul__423__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10006606866874067871ull);
    __Vfunc_fp32_mul__423__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__424__bits 
                                = __Vfunc_fp32_mul__423__lhs;
                            __Vfunc_fp32_is_nan__424__unused_sign = 0;
                            __Vfunc_fp32_is_nan__424__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__424__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__424__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__424__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__424__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__424__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__425__bits 
                                = __Vfunc_fp32_mul__423__rhs;
                            __Vfunc_fp32_is_nan__425__unused_sign = 0;
                            __Vfunc_fp32_is_nan__425__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__425__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__425__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__425__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__425__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__425__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__426__bits 
                                    = __Vfunc_fp32_mul__423__lhs;
                                __Vfunc_fp32_is_inf__426__unused_sign = 0;
                                __Vfunc_fp32_is_inf__426__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__426__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__426__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__426__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__426__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__427__bits 
                                    = __Vfunc_fp32_mul__423__rhs;
                                __Vfunc_fp32_is_zero__427__unused_sign = 0;
                                __Vfunc_fp32_is_zero__427__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__427__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__427__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__427__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__427__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__428__bits 
                                    = __Vfunc_fp32_mul__423__rhs;
                                __Vfunc_fp32_is_inf__428__unused_sign = 0;
                                __Vfunc_fp32_is_inf__428__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__428__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__428__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__428__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__428__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__429__bits 
                                    = __Vfunc_fp32_mul__423__lhs;
                                __Vfunc_fp32_is_zero__429__unused_sign = 0;
                                __Vfunc_fp32_is_zero__429__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__429__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__429__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__429__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__429__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout = 0x7fc00000U;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_mul__423__result_sign 
            = ((__Vfunc_fp32_mul__423__lhs ^ __Vfunc_fp32_mul__423__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__430__bits 
                            = __Vfunc_fp32_mul__423__lhs;
                        __Vfunc_fp32_is_inf__430__unused_sign = 0;
                        __Vfunc_fp32_is_inf__430__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__430__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__430__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__430__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__430__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__431__bits 
                            = __Vfunc_fp32_mul__423__rhs;
                        __Vfunc_fp32_is_inf__431__unused_sign = 0;
                        __Vfunc_fp32_is_inf__431__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__431__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__431__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__431__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__431__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__423__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__432__bits 
                            = __Vfunc_fp32_mul__423__lhs;
                        __Vfunc_fp32_is_zero__432__unused_sign = 0;
                        __Vfunc_fp32_is_zero__432__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__432__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__432__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__432__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__432__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__433__bits 
                            = __Vfunc_fp32_mul__423__rhs;
                        __Vfunc_fp32_is_zero__433__unused_sign = 0;
                        __Vfunc_fp32_is_zero__433__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__433__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__433__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__433__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__433__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__423__result_sign) 
                   << 0x1fU);
            goto __Vlabel0;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__423__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__423__lhs);
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__423__lhs));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__423__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__423__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__423__rhs);
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__423__rhs));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__423__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__423__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__423__normalize_count = 1U;
        __Vfunc_fp32_mul__423__normalize_count = 2U;
        __Vfunc_fp32_mul__423__normalize_count = 3U;
        __Vfunc_fp32_mul__423__normalize_count = 4U;
        __Vfunc_fp32_mul__423__normalize_count = 5U;
        __Vfunc_fp32_mul__423__normalize_count = 6U;
        __Vfunc_fp32_mul__423__normalize_count = 7U;
        __Vfunc_fp32_mul__423__normalize_count = 8U;
        __Vfunc_fp32_mul__423__normalize_count = 9U;
        __Vfunc_fp32_mul__423__normalize_count = 0xaU;
        __Vfunc_fp32_mul__423__normalize_count = 0xbU;
        __Vfunc_fp32_mul__423__normalize_count = 0xcU;
        __Vfunc_fp32_mul__423__normalize_count = 0xdU;
        __Vfunc_fp32_mul__423__normalize_count = 0xeU;
        __Vfunc_fp32_mul__423__normalize_count = 0xfU;
        __Vfunc_fp32_mul__423__normalize_count = 0x10U;
        __Vfunc_fp32_mul__423__normalize_count = 0x11U;
        __Vfunc_fp32_mul__423__normalize_count = 0x12U;
        __Vfunc_fp32_mul__423__normalize_count = 0x13U;
        __Vfunc_fp32_mul__423__normalize_count = 0x14U;
        __Vfunc_fp32_mul__423__normalize_count = 0x15U;
        __Vfunc_fp32_mul__423__normalize_count = 0x16U;
        __Vfunc_fp32_mul__423__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__423__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__423__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__423__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__423__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__423__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__423__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__423__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__423__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__423__mantissa = 
            (0xffffffU & (IData)((0xffffffffffffULL 
                                  & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__423__product, vlSelfRef.__Vfunc_fp32_mul__423__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__423__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__423__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__423__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__423__product 
               & vlSelfRef.__Vfunc_fp32_mul__423__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__423__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__423__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__423__rounded = vlSelfRef.__Vfunc_fp32_mul__423__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__423__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__423__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__423__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__423__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__423__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__423__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__423__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__423__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__423__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__423__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__423__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__423__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__423__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__423__result_sign) 
                   << 0x1fU);
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_mul__423__result_sign) 
              << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                            + vlSelfRef.__Vfunc_fp32_mul__423__result_unbiased) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__423__mantissa)));
        __Vlabel0: ;
    }
    tb_npu_engines__DOT__u_complex__DOT__fp_mean_squared 
        = vlSelfRef.__Vfunc_fp32_mul__423__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__source_end_addr 
        = (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr 
           + VL_EXTEND_QI(64,3, ([&]() {
                    vlSelfRef.__Vfunc_dtype_storage_bytes__132__dtype 
                        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_src_dtype;
                    {
                        if ((0U == (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__132__dtype))) {
                            vlSelfRef.__Vfunc_dtype_storage_bytes__132__Vfuncout = 1U;
                            goto __Vlabel1;
                        }
                        vlSelfRef.__Vfunc_dtype_bytes__133__dtype 
                            = vlSelfRef.__Vfunc_dtype_storage_bytes__132__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__133__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__133__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__133__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__133__dtype))
                                                  ? 2U
                                                  : 0U)));
                        vlSelfRef.__Vfunc_dtype_storage_bytes__132__Vfuncout 
                            = vlSelfRef.__Vfunc_dtype_bytes__133__Vfuncout;
                        __Vlabel1: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__132__Vfuncout))));
    vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr = 0ULL;
    if ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                = (0xfffffffffff8ULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr);
        }
    }
    if ((6U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                = (0xfffffffffff8ULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr);
        }
    }
    if ((8U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_addr 
                = (0xfffffffffff8ULL & vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr);
        }
    }
    vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_end_addr 
        = (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr 
           + VL_EXTEND_QI(64,3, ([&]() {
                    vlSelfRef.__Vfunc_dtype_storage_bytes__134__dtype 
                        = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype;
                    {
                        if ((0U == (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__134__dtype))) {
                            vlSelfRef.__Vfunc_dtype_storage_bytes__134__Vfuncout = 1U;
                            goto __Vlabel2;
                        }
                        vlSelfRef.__Vfunc_dtype_bytes__135__dtype 
                            = vlSelfRef.__Vfunc_dtype_storage_bytes__134__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__135__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__135__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__135__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__135__dtype))
                                                  ? 2U
                                                  : 0U)));
                        vlSelfRef.__Vfunc_dtype_storage_bytes__134__Vfuncout 
                            = vlSelfRef.__Vfunc_dtype_bytes__135__Vfuncout;
                        __Vlabel2: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__134__Vfuncout))));
    vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wstrb = 0U;
    vlSelfRef.tb_npu_engines__DOT__dma_l1_req_addr = 0U;
    if ((3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_src_addr 
                                        >> 3U)) << 3U));
        }
    }
    if ((6U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr 
                                        >> 3U)) << 3U));
        }
    }
    vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wstrb = 0U;
    vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wdata = 0ULL;
    vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wdata = 0ULL;
    if ((8U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.__Vfunc_store_element_strb__139__dtype 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_strb__139__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_strb__139__result = 0U;
            vlSelfRef.__Vfunc_store_element_strb__139__result 
                = ((2U & (IData)(vlSelfRef.__Vfunc_store_element_strb__139__dtype))
                    ? (0xffU & ((1U & (IData)(vlSelfRef.__Vfunc_store_element_strb__139__dtype))
                                 ? ((IData)(3U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__139__byte_lane))
                                 : ((IData)(0xfU) << (IData)(vlSelfRef.__Vfunc_store_element_strb__139__byte_lane))))
                    : ((IData)(vlSelfRef.__Vfunc_store_element_strb__139__result) 
                       | (0xffU & ((IData)(1U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__139__byte_lane)))));
            vlSelfRef.__Vfunc_store_element_strb__139__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_strb__139__result;
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wstrb 
                = vlSelfRef.__Vfunc_store_element_strb__139__Vfuncout;
            vlSelfRef.__Vfunc_store_element_data__138__dtype 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_data__138__high_nibble 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_high_nibble;
            vlSelfRef.__Vfunc_store_element_data__138__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_data__138__value 
                = (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__result_q);
            vlSelfRef.__Vfunc_store_element_data__138__old_beat 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rmw_beat_q;
            vlSelf->__Vfunc_store_element_data__138__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9708337680819306562ull);
            vlSelfRef.__Vfunc_store_element_data__138__result 
                = vlSelfRef.__Vfunc_store_element_data__138__old_beat;
            if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__138__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__138__result 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__138__dtype))
                        ? (((~ (0xffffULL << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__138__result) 
                           | ((QData)((IData)((0xffffU 
                                               & vlSelfRef.__Vfunc_store_element_data__138__value))) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U))))
                        : (((~ (0xffffffffULL << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__138__result) 
                           | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__138__value)) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U)))));
            } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__138__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__138__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__138__result) 
                       | ((QData)((IData)((0xffU & vlSelfRef.__Vfunc_store_element_data__138__value))) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U))));
            } else {
                vlSelfRef.__Vfunc_store_element_data__138__byte_value 
                    = (0xffU & (IData)((vlSelfRef.__Vfunc_store_element_data__138__old_beat 
                                        >> (0x3fU & 
                                            VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U)))));
                vlSelfRef.__Vfunc_store_element_data__138__byte_value 
                    = ((IData)(vlSelfRef.__Vfunc_store_element_data__138__high_nibble)
                        ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_value)) 
                           | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__138__value 
                                       << 4U))) : (
                                                   (0xf0U 
                                                    & (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_value)) 
                                                   | (0xfU 
                                                      & vlSelfRef.__Vfunc_store_element_data__138__value)));
                vlSelfRef.__Vfunc_store_element_data__138__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__138__result) 
                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_value)) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__138__byte_lane), 3U))));
            }
            vlSelfRef.__Vfunc_store_element_data__138__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_data__138__result;
            vlSelfRef.tb_npu_engines__DOT__dma_mif_req_wdata 
                = vlSelfRef.__Vfunc_store_element_data__138__Vfuncout;
        }
        if ((0U == (0xffU & (vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr 
                                        >> 3U)) << 3U));
            vlSelfRef.__Vfunc_store_element_strb__137__dtype 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_strb__137__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_strb__137__result = 0U;
            vlSelfRef.__Vfunc_store_element_strb__137__result 
                = ((2U & (IData)(vlSelfRef.__Vfunc_store_element_strb__137__dtype))
                    ? (0xffU & ((1U & (IData)(vlSelfRef.__Vfunc_store_element_strb__137__dtype))
                                 ? ((IData)(3U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__137__byte_lane))
                                 : ((IData)(0xfU) << (IData)(vlSelfRef.__Vfunc_store_element_strb__137__byte_lane))))
                    : ((IData)(vlSelfRef.__Vfunc_store_element_strb__137__result) 
                       | (0xffU & ((IData)(1U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__137__byte_lane)))));
            vlSelfRef.__Vfunc_store_element_strb__137__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_strb__137__result;
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wstrb 
                = vlSelfRef.__Vfunc_store_element_strb__137__Vfuncout;
            vlSelfRef.__Vfunc_store_element_data__136__dtype 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_data__136__high_nibble 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__destination_high_nibble;
            vlSelfRef.__Vfunc_store_element_data__136__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_data__136__value 
                = (IData)(vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__result_q);
            vlSelfRef.__Vfunc_store_element_data__136__old_beat 
                = vlSelfRef.tb_npu_engines__DOT__u_dma__DOT__rmw_beat_q;
            vlSelf->__Vfunc_store_element_data__136__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15356923196557265986ull);
            vlSelfRef.__Vfunc_store_element_data__136__result 
                = vlSelfRef.__Vfunc_store_element_data__136__old_beat;
            if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__136__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__136__result 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__136__dtype))
                        ? (((~ (0xffffULL << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__136__result) 
                           | ((QData)((IData)((0xffffU 
                                               & vlSelfRef.__Vfunc_store_element_data__136__value))) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U))))
                        : (((~ (0xffffffffULL << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__136__result) 
                           | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__136__value)) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U)))));
            } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__136__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__136__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__136__result) 
                       | ((QData)((IData)((0xffU & vlSelfRef.__Vfunc_store_element_data__136__value))) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U))));
            } else {
                vlSelfRef.__Vfunc_store_element_data__136__byte_value 
                    = (0xffU & (IData)((vlSelfRef.__Vfunc_store_element_data__136__old_beat 
                                        >> (0x3fU & 
                                            VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U)))));
                vlSelfRef.__Vfunc_store_element_data__136__byte_value 
                    = ((IData)(vlSelfRef.__Vfunc_store_element_data__136__high_nibble)
                        ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_value)) 
                           | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__136__value 
                                       << 4U))) : (
                                                   (0xf0U 
                                                    & (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_value)) 
                                                   | (0xfU 
                                                      & vlSelfRef.__Vfunc_store_element_data__136__value)));
                vlSelfRef.__Vfunc_store_element_data__136__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__136__result) 
                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_value)) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__136__byte_lane), 3U))));
            }
            vlSelfRef.__Vfunc_store_element_data__136__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_data__136__result;
            vlSelfRef.tb_npu_engines__DOT__dma_l1_req_wdata 
                = vlSelfRef.__Vfunc_store_element_data__136__Vfuncout;
        }
    }
    __Vfunc_fp32_sub__434__rhs = tb_npu_engines__DOT__u_complex__DOT__fp_mean_squared;
    __Vfunc_fp32_sub__434__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_mean_square;
    __Vfunc_fp32_neg__436__value = __Vfunc_fp32_sub__434__rhs;
    __Vfunc_fp32_neg__436__Vfuncout = (((~ (__Vfunc_fp32_neg__436__value 
                                            >> 0x1fU)) 
                                        << 0x1fU) | 
                                       (0x7fffffffU 
                                        & __Vfunc_fp32_neg__436__value));
    __Vfunc_fp32_add__435__rhs = __Vfunc_fp32_neg__436__Vfuncout;
    __Vfunc_fp32_add__435__lhs = __Vfunc_fp32_sub__434__lhs;
    vlSelf->__Vfunc_fp32_add__435__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4938517534005985283ull);
    vlSelf->__Vfunc_fp32_add__435__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11117266972080675029ull);
    vlSelf->__Vfunc_fp32_add__435__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8004103920994450513ull);
    vlSelf->__Vfunc_fp32_add__435__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13616730923292901522ull);
    vlSelf->__Vfunc_fp32_add__435__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17299530486266738730ull);
    vlSelf->__Vfunc_fp32_add__435__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 6668407757464548892ull);
    vlSelf->__Vfunc_fp32_add__435__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2257046443573167039ull);
    vlSelf->__Vfunc_fp32_add__435__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15084403507230797525ull);
    vlSelf->__Vfunc_fp32_add__435__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10360277396037447057ull);
    vlSelf->__Vfunc_fp32_add__435__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11684965685300817308ull);
    vlSelf->__Vfunc_fp32_add__435__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18132458286291189482ull);
    vlSelf->__Vfunc_fp32_add__435__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8151327107639461428ull);
    vlSelf->__Vfunc_fp32_add__435__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13279679469688035440ull);
    vlSelf->__Vfunc_fp32_add__435__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5411743807519286711ull);
    vlSelf->__Vfunc_fp32_add__435__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 1030764701846290299ull);
    vlSelf->__Vfunc_fp32_add__435__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 13079870302321298902ull);
    vlSelf->__Vfunc_fp32_add__435__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 5771626209241536758ull);
    vlSelf->__Vfunc_fp32_add__435__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 12922771249817461923ull);
    vlSelf->__Vfunc_fp32_add__435__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 10315717551383854503ull);
    vlSelf->__Vfunc_fp32_add__435__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 10884009952232145663ull);
    vlSelf->__Vfunc_fp32_add__435__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11995595712351745153ull);
    vlSelf->__Vfunc_fp32_add__435__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9151003695076360734ull);
    vlSelf->__Vfunc_fp32_add__435__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9914341361751087933ull);
    vlSelf->__Vfunc_fp32_add__435__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6627999922962605367ull);
    __Vfunc_fp32_add__435__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__437__bits 
                            = __Vfunc_fp32_add__435__lhs;
                        __Vfunc_fp32_is_nan__437__unused_sign = 0;
                        __Vfunc_fp32_is_nan__437__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__437__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__437__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__437__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__437__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__437__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__438__bits 
                            = __Vfunc_fp32_add__435__rhs;
                        __Vfunc_fp32_is_nan__438__unused_sign = 0;
                        __Vfunc_fp32_is_nan__438__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__438__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__438__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__438__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__438__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__438__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__435__Vfuncout = 0x7fc00000U;
            goto __Vlabel3;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__439__bits 
                            = __Vfunc_fp32_add__435__lhs;
                        __Vfunc_fp32_is_inf__439__unused_sign = 0;
                        __Vfunc_fp32_is_inf__439__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__439__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__439__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__439__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__439__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__440__bits 
                            = __Vfunc_fp32_add__435__rhs;
                        __Vfunc_fp32_is_inf__440__unused_sign = 0;
                        __Vfunc_fp32_is_inf__440__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__440__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__440__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__440__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__440__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__441__bits 
                                    = __Vfunc_fp32_add__435__lhs;
                                __Vfunc_fp32_is_inf__441__unused_sign = 0;
                                __Vfunc_fp32_is_inf__441__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__441__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__441__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__441__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__441__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__442__bits 
                                    = __Vfunc_fp32_add__435__rhs;
                                __Vfunc_fp32_is_inf__442__unused_sign = 0;
                                __Vfunc_fp32_is_inf__442__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__442__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__442__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__442__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__442__Vfuncout))) 
                 & ((__Vfunc_fp32_add__435__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__435__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__435__Vfuncout = 0x7fc00000U;
                goto __Vlabel3;
            }
            vlSelfRef.__Vfunc_fp32_add__435__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__443__bits 
                            = __Vfunc_fp32_add__435__lhs;
                        __Vfunc_fp32_is_inf__443__unused_sign = 0;
                        __Vfunc_fp32_is_inf__443__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__443__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__443__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__443__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__443__Vfuncout))
                    ? __Vfunc_fp32_add__435__lhs : __Vfunc_fp32_add__435__rhs);
            goto __Vlabel3;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__444__bits 
                        = __Vfunc_fp32_add__435__lhs;
                    __Vfunc_fp32_is_zero__444__unused_sign = 0;
                    __Vfunc_fp32_is_zero__444__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__444__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__444__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__444__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__444__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__435__Vfuncout 
                = __Vfunc_fp32_add__435__rhs;
            goto __Vlabel3;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__445__bits 
                        = __Vfunc_fp32_add__435__rhs;
                    __Vfunc_fp32_is_zero__445__unused_sign = 0;
                    __Vfunc_fp32_is_zero__445__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__445__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__445__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__445__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__445__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__435__Vfuncout 
                = __Vfunc_fp32_add__435__lhs;
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_add__435__lhs_sign = 
            (__Vfunc_fp32_add__435__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__435__rhs_sign = 
            (__Vfunc_fp32_add__435__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__435__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__435__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__435__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__435__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__435__lhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__435__lhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__435__lhs)));
        vlSelfRef.__Vfunc_fp32_add__435__rhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__435__rhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__435__rhs)));
        vlSelfRef.__Vfunc_fp32_add__435__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__435__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__435__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__435__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__435__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__435__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__435__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__435__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__435__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__435__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__435__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__435__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__435__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__435__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__435__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__435__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__435__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__435__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__435__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__435__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__435__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__435__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__435__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__435__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__435__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__435__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__435__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__435__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__435__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__435__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__435__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__435__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__435__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__435__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__small_ext, vlSelfRef.__Vfunc_fp32_add__435__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__435__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__435__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__435__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__435__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__435__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__435__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__435__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__435__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__435__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__435__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__435__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__435__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__435__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__435__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__435__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__435__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__435__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__435__work_ext);
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__435__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__435__sticky))));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__435__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__435__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__435__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__435__Vfuncout = 0U;
                goto __Vlabel3;
            }
            __Vfunc_fp32_add__435__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__435__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__435__normalize_count = 1U;
            __Vfunc_fp32_add__435__normalize_count = 2U;
            __Vfunc_fp32_add__435__normalize_count = 3U;
            __Vfunc_fp32_add__435__normalize_count = 4U;
            __Vfunc_fp32_add__435__normalize_count = 5U;
            __Vfunc_fp32_add__435__normalize_count = 6U;
            __Vfunc_fp32_add__435__normalize_count = 7U;
            __Vfunc_fp32_add__435__normalize_count = 8U;
            __Vfunc_fp32_add__435__normalize_count = 9U;
            __Vfunc_fp32_add__435__normalize_count = 0xaU;
            __Vfunc_fp32_add__435__normalize_count = 0xbU;
            __Vfunc_fp32_add__435__normalize_count = 0xcU;
            __Vfunc_fp32_add__435__normalize_count = 0xdU;
            __Vfunc_fp32_add__435__normalize_count = 0xeU;
            __Vfunc_fp32_add__435__normalize_count = 0xfU;
            __Vfunc_fp32_add__435__normalize_count = 0x10U;
            __Vfunc_fp32_add__435__normalize_count = 0x11U;
            __Vfunc_fp32_add__435__normalize_count = 0x12U;
            __Vfunc_fp32_add__435__normalize_count = 0x13U;
            __Vfunc_fp32_add__435__normalize_count = 0x14U;
            __Vfunc_fp32_add__435__normalize_count = 0x15U;
            __Vfunc_fp32_add__435__normalize_count = 0x16U;
            __Vfunc_fp32_add__435__normalize_count = 0x17U;
            __Vfunc_fp32_add__435__normalize_count = 0x18U;
            __Vfunc_fp32_add__435__normalize_count = 0x19U;
            __Vfunc_fp32_add__435__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__435__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_add__435__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__435__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__435__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__435__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__435__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__435__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__435__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__435__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__435__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__435__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__435__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__435__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__435__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__435__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__435__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__435__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__435__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__435__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__435__mantissa));
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_add__435__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_add__435__result_sign) 
              << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__435__large_exp) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__435__mantissa)));
        __Vlabel3: ;
    }
    __Vfunc_fp32_sub__434__Vfuncout = vlSelfRef.__Vfunc_fp32_add__435__Vfuncout;
    tb_npu_engines__DOT__u_complex__DOT__fp_variance 
        = __Vfunc_fp32_sub__434__Vfuncout;
    __Vfunc_fp32_add__446__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x24U];
    __Vfunc_fp32_add__446__lhs = ((5U == vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x13U])
                                   ? ((tb_npu_engines__DOT__u_complex__DOT__fp_variance 
                                       >> 0x1fU) ? 0U
                                       : tb_npu_engines__DOT__u_complex__DOT__fp_variance)
                                   : vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_mean_square);
    vlSelf->__Vfunc_fp32_add__446__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16904255823309399070ull);
    vlSelf->__Vfunc_fp32_add__446__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12123330368211358472ull);
    vlSelf->__Vfunc_fp32_add__446__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10967870315375116304ull);
    vlSelf->__Vfunc_fp32_add__446__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6028063520691358477ull);
    vlSelf->__Vfunc_fp32_add__446__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1330527397616622174ull);
    vlSelf->__Vfunc_fp32_add__446__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 6743352812600753530ull);
    vlSelf->__Vfunc_fp32_add__446__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 1043640227901866890ull);
    vlSelf->__Vfunc_fp32_add__446__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4075121582292662115ull);
    vlSelf->__Vfunc_fp32_add__446__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6866051757362854875ull);
    vlSelf->__Vfunc_fp32_add__446__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14699926927163397112ull);
    vlSelf->__Vfunc_fp32_add__446__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 3319279733729695887ull);
    vlSelf->__Vfunc_fp32_add__446__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2561961523944946676ull);
    vlSelf->__Vfunc_fp32_add__446__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13530462243085905084ull);
    vlSelf->__Vfunc_fp32_add__446__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3020302678090155831ull);
    vlSelf->__Vfunc_fp32_add__446__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 127389205812672471ull);
    vlSelf->__Vfunc_fp32_add__446__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 3606802074951781100ull);
    vlSelf->__Vfunc_fp32_add__446__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 5406164153122920547ull);
    vlSelf->__Vfunc_fp32_add__446__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 7677289732281827187ull);
    vlSelf->__Vfunc_fp32_add__446__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 5837341528815444422ull);
    vlSelf->__Vfunc_fp32_add__446__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 12130318307312720436ull);
    vlSelf->__Vfunc_fp32_add__446__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 9675971317425714056ull);
    vlSelf->__Vfunc_fp32_add__446__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11477145388416044289ull);
    vlSelf->__Vfunc_fp32_add__446__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16871856848338628344ull);
    vlSelf->__Vfunc_fp32_add__446__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14906144235570366269ull);
    __Vfunc_fp32_add__446__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__447__bits 
                            = __Vfunc_fp32_add__446__lhs;
                        __Vfunc_fp32_is_nan__447__unused_sign = 0;
                        __Vfunc_fp32_is_nan__447__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__447__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__447__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__447__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__447__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__447__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__448__bits 
                            = __Vfunc_fp32_add__446__rhs;
                        __Vfunc_fp32_is_nan__448__unused_sign = 0;
                        __Vfunc_fp32_is_nan__448__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__448__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__448__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__448__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__448__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__448__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__446__Vfuncout = 0x7fc00000U;
            goto __Vlabel4;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__449__bits 
                            = __Vfunc_fp32_add__446__lhs;
                        __Vfunc_fp32_is_inf__449__unused_sign = 0;
                        __Vfunc_fp32_is_inf__449__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__449__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__449__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__449__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__449__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__450__bits 
                            = __Vfunc_fp32_add__446__rhs;
                        __Vfunc_fp32_is_inf__450__unused_sign = 0;
                        __Vfunc_fp32_is_inf__450__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__450__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__450__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__450__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__450__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__451__bits 
                                    = __Vfunc_fp32_add__446__lhs;
                                __Vfunc_fp32_is_inf__451__unused_sign = 0;
                                __Vfunc_fp32_is_inf__451__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__451__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__451__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__451__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__451__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__452__bits 
                                    = __Vfunc_fp32_add__446__rhs;
                                __Vfunc_fp32_is_inf__452__unused_sign = 0;
                                __Vfunc_fp32_is_inf__452__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__452__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__452__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__452__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__452__Vfuncout))) 
                 & ((__Vfunc_fp32_add__446__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__446__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__446__Vfuncout = 0x7fc00000U;
                goto __Vlabel4;
            }
            vlSelfRef.__Vfunc_fp32_add__446__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__453__bits 
                            = __Vfunc_fp32_add__446__lhs;
                        __Vfunc_fp32_is_inf__453__unused_sign = 0;
                        __Vfunc_fp32_is_inf__453__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__453__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__453__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__453__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__453__Vfuncout))
                    ? __Vfunc_fp32_add__446__lhs : __Vfunc_fp32_add__446__rhs);
            goto __Vlabel4;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__454__bits 
                        = __Vfunc_fp32_add__446__lhs;
                    __Vfunc_fp32_is_zero__454__unused_sign = 0;
                    __Vfunc_fp32_is_zero__454__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__454__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__454__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__454__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__454__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__446__Vfuncout 
                = __Vfunc_fp32_add__446__rhs;
            goto __Vlabel4;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__455__bits 
                        = __Vfunc_fp32_add__446__rhs;
                    __Vfunc_fp32_is_zero__455__unused_sign = 0;
                    __Vfunc_fp32_is_zero__455__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__455__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__455__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__455__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__455__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__446__Vfuncout 
                = __Vfunc_fp32_add__446__lhs;
            goto __Vlabel4;
        }
        vlSelfRef.__Vfunc_fp32_add__446__lhs_sign = 
            (__Vfunc_fp32_add__446__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__446__rhs_sign = 
            (__Vfunc_fp32_add__446__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__446__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__446__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__446__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__446__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__446__lhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__446__lhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__446__lhs)));
        vlSelfRef.__Vfunc_fp32_add__446__rhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__446__rhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__446__rhs)));
        vlSelfRef.__Vfunc_fp32_add__446__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__446__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__446__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__446__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__446__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__446__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__446__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__446__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__446__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__446__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__446__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__446__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__446__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__446__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__446__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__446__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__446__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__446__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__446__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__446__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__446__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__446__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__446__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__446__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__446__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__446__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__446__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__446__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__446__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__446__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__446__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__446__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__446__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__446__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__small_ext, vlSelfRef.__Vfunc_fp32_add__446__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__446__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__446__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__446__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__446__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__446__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__446__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__446__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__446__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__446__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__446__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__446__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__446__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__446__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__446__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__446__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__446__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__446__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__446__work_ext);
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__446__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__446__sticky))));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__446__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__446__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__446__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__446__Vfuncout = 0U;
                goto __Vlabel4;
            }
            __Vfunc_fp32_add__446__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__446__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__446__normalize_count = 1U;
            __Vfunc_fp32_add__446__normalize_count = 2U;
            __Vfunc_fp32_add__446__normalize_count = 3U;
            __Vfunc_fp32_add__446__normalize_count = 4U;
            __Vfunc_fp32_add__446__normalize_count = 5U;
            __Vfunc_fp32_add__446__normalize_count = 6U;
            __Vfunc_fp32_add__446__normalize_count = 7U;
            __Vfunc_fp32_add__446__normalize_count = 8U;
            __Vfunc_fp32_add__446__normalize_count = 9U;
            __Vfunc_fp32_add__446__normalize_count = 0xaU;
            __Vfunc_fp32_add__446__normalize_count = 0xbU;
            __Vfunc_fp32_add__446__normalize_count = 0xcU;
            __Vfunc_fp32_add__446__normalize_count = 0xdU;
            __Vfunc_fp32_add__446__normalize_count = 0xeU;
            __Vfunc_fp32_add__446__normalize_count = 0xfU;
            __Vfunc_fp32_add__446__normalize_count = 0x10U;
            __Vfunc_fp32_add__446__normalize_count = 0x11U;
            __Vfunc_fp32_add__446__normalize_count = 0x12U;
            __Vfunc_fp32_add__446__normalize_count = 0x13U;
            __Vfunc_fp32_add__446__normalize_count = 0x14U;
            __Vfunc_fp32_add__446__normalize_count = 0x15U;
            __Vfunc_fp32_add__446__normalize_count = 0x16U;
            __Vfunc_fp32_add__446__normalize_count = 0x17U;
            __Vfunc_fp32_add__446__normalize_count = 0x18U;
            __Vfunc_fp32_add__446__normalize_count = 0x19U;
            __Vfunc_fp32_add__446__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__446__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_add__446__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__446__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__446__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__446__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__446__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__446__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__446__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__446__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__446__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__446__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__446__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__446__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__446__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__446__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__446__result_sign) 
                                  << 0x1fU));
            goto __Vlabel4;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__446__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__446__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__446__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__446__mantissa));
            goto __Vlabel4;
        }
        vlSelfRef.__Vfunc_fp32_add__446__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_add__446__result_sign) 
              << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__446__large_exp) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__446__mantissa)));
        __Vlabel4: ;
    }
    tb_npu_engines__DOT__u_complex__DOT__fp_variance_plus_epsilon 
        = vlSelfRef.__Vfunc_fp32_add__446__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src0_fp;
    if (((0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x25U]) 
         | (0U != vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x26U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_less_than__341__rhs 
                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x25U];
                    vlSelfRef.__Vfunc_fp32_less_than__341__lhs 
                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
                    {
                        if (((([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__342__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__341__lhs;
                                            __Vfunc_fp32_is_nan__342__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__342__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__342__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__342__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__342__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__342__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__342__Vfuncout)) 
                              | ([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__343__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__341__rhs;
                                            __Vfunc_fp32_is_nan__343__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__343__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__343__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__343__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__343__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__343__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__343__Vfuncout))) 
                             | ([&]() {
                                        vlSelfRef.__Vfunc_fp32_equal__344__rhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__341__rhs;
                                        vlSelfRef.__Vfunc_fp32_equal__344__lhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__341__lhs;
                                        {
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__345__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__344__lhs;
                                                            __Vfunc_fp32_is_nan__345__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__345__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__345__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__345__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__345__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__345__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__345__Vfuncout)) 
                                                 | ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__346__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__344__rhs;
                                                            __Vfunc_fp32_is_nan__346__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__346__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__346__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__346__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__346__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__346__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__346__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__344__Vfuncout = 0U;
                                                goto __Vlabel6;
                                            }
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__347__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__344__lhs;
                                                            __Vfunc_fp32_is_zero__347__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__347__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__347__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__347__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__347__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__347__Vfuncout)) 
                                                 & ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__348__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__344__rhs;
                                                            __Vfunc_fp32_is_zero__348__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__348__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__348__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__348__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__348__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__348__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__344__Vfuncout = 1U;
                                                goto __Vlabel6;
                                            }
                                            vlSelfRef.__Vfunc_fp32_equal__344__Vfuncout 
                                                = (vlSelfRef.__Vfunc_fp32_equal__344__lhs 
                                                   == vlSelfRef.__Vfunc_fp32_equal__344__rhs);
                                            __Vlabel6: ;
                                        }
                                    }(), (IData)(vlSelfRef.__Vfunc_fp32_equal__344__Vfuncout)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__341__Vfuncout = 0U;
                            goto __Vlabel5;
                        }
                        if (((vlSelfRef.__Vfunc_fp32_less_than__341__lhs 
                              >> 0x1fU) != (vlSelfRef.__Vfunc_fp32_less_than__341__rhs 
                                            >> 0x1fU))) {
                            vlSelfRef.__Vfunc_fp32_less_than__341__Vfuncout 
                                = (vlSelfRef.__Vfunc_fp32_less_than__341__lhs 
                                   >> 0x1fU);
                            goto __Vlabel5;
                        }
                        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_less_than__341__lhs 
                                      >> 0x1fU)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__341__Vfuncout 
                                = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__341__lhs) 
                                   < (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__341__rhs));
                            goto __Vlabel5;
                        }
                        vlSelfRef.__Vfunc_fp32_less_than__341__Vfuncout 
                            = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__341__lhs) 
                               > (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__341__rhs));
                        __Vlabel5: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_fp32_less_than__341__Vfuncout))) {
            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp 
                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x25U];
        } else if (([&]() {
                    vlSelfRef.__Vfunc_fp32_less_than__349__rhs 
                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
                    vlSelfRef.__Vfunc_fp32_less_than__349__lhs 
                        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x26U];
                    {
                        if (((([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__350__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__349__lhs;
                                            __Vfunc_fp32_is_nan__350__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__350__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__350__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__350__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__350__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__350__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__350__Vfuncout)) 
                              | ([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__351__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__349__rhs;
                                            __Vfunc_fp32_is_nan__351__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__351__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__351__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__351__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__351__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__351__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__351__Vfuncout))) 
                             | ([&]() {
                                        vlSelfRef.__Vfunc_fp32_equal__352__rhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__349__rhs;
                                        vlSelfRef.__Vfunc_fp32_equal__352__lhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__349__lhs;
                                        {
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__353__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__352__lhs;
                                                            __Vfunc_fp32_is_nan__353__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__353__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__353__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__353__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__353__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__353__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__353__Vfuncout)) 
                                                 | ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__354__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__352__rhs;
                                                            __Vfunc_fp32_is_nan__354__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__354__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__354__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__354__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__354__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__354__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__354__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__352__Vfuncout = 0U;
                                                goto __Vlabel8;
                                            }
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__355__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__352__lhs;
                                                            __Vfunc_fp32_is_zero__355__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__355__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__355__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__355__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__355__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__355__Vfuncout)) 
                                                 & ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__356__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__352__rhs;
                                                            __Vfunc_fp32_is_zero__356__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__356__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__356__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__356__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__356__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__356__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__352__Vfuncout = 1U;
                                                goto __Vlabel8;
                                            }
                                            vlSelfRef.__Vfunc_fp32_equal__352__Vfuncout 
                                                = (vlSelfRef.__Vfunc_fp32_equal__352__lhs 
                                                   == vlSelfRef.__Vfunc_fp32_equal__352__rhs);
                                            __Vlabel8: ;
                                        }
                                    }(), (IData)(vlSelfRef.__Vfunc_fp32_equal__352__Vfuncout)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__349__Vfuncout = 0U;
                            goto __Vlabel7;
                        }
                        if (((vlSelfRef.__Vfunc_fp32_less_than__349__lhs 
                              >> 0x1fU) != (vlSelfRef.__Vfunc_fp32_less_than__349__rhs 
                                            >> 0x1fU))) {
                            vlSelfRef.__Vfunc_fp32_less_than__349__Vfuncout 
                                = (vlSelfRef.__Vfunc_fp32_less_than__349__lhs 
                                   >> 0x1fU);
                            goto __Vlabel7;
                        }
                        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_less_than__349__lhs 
                                      >> 0x1fU)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__349__Vfuncout 
                                = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__349__lhs) 
                                   < (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__349__rhs));
                            goto __Vlabel7;
                        }
                        vlSelfRef.__Vfunc_fp32_less_than__349__Vfuncout 
                            = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__349__lhs) 
                               > (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__349__rhs));
                        __Vlabel7: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_fp32_less_than__349__Vfuncout))) {
            vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp 
                = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x26U];
        }
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operation = 0U;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operand0 
        = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operand1 = 0U;
    if ((0x80U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q))) {
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operation 
            = (0xfU & vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__desc_q[0x13U]);
    } else if (((0x81U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                & ((2U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q)) 
                   | (3U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))))) {
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operation = 4U;
        vlSelfRef.__Vfunc_fp32_sub__357__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_max_q;
        vlSelfRef.__Vfunc_fp32_sub__357__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
        vlSelfRef.__Vfunc_fp32_neg__359__value = vlSelfRef.__Vfunc_fp32_sub__357__rhs;
        vlSelfRef.__Vfunc_fp32_neg__359__Vfuncout = 
            (((~ (vlSelfRef.__Vfunc_fp32_neg__359__value 
                  >> 0x1fU)) << 0x1fU) | (0x7fffffffU 
                                          & vlSelfRef.__Vfunc_fp32_neg__359__value));
        vlSelfRef.__Vfunc_fp32_add__358__rhs = vlSelfRef.__Vfunc_fp32_neg__359__Vfuncout;
        vlSelfRef.__Vfunc_fp32_add__358__lhs = vlSelfRef.__Vfunc_fp32_sub__357__lhs;
        vlSelf->__Vfunc_fp32_add__358__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12357816617576699716ull);
        vlSelf->__Vfunc_fp32_add__358__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2187474271696273207ull);
        vlSelf->__Vfunc_fp32_add__358__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4616157096033996866ull);
        vlSelf->__Vfunc_fp32_add__358__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7672925474375130569ull);
        vlSelf->__Vfunc_fp32_add__358__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15567874151846056033ull);
        vlSelf->__Vfunc_fp32_add__358__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4809447690133794810ull);
        vlSelf->__Vfunc_fp32_add__358__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4629559466962478022ull);
        vlSelf->__Vfunc_fp32_add__358__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7747429333882706735ull);
        vlSelf->__Vfunc_fp32_add__358__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 10476106725219153555ull);
        vlSelf->__Vfunc_fp32_add__358__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14711335289242396170ull);
        vlSelf->__Vfunc_fp32_add__358__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7496892776784653902ull);
        vlSelf->__Vfunc_fp32_add__358__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16686584434067255023ull);
        vlSelf->__Vfunc_fp32_add__358__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14041815251292564609ull);
        vlSelf->__Vfunc_fp32_add__358__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15981769937323591630ull);
        vlSelf->__Vfunc_fp32_add__358__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 4862429517230824099ull);
        vlSelf->__Vfunc_fp32_add__358__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 11711442985796269593ull);
        vlSelf->__Vfunc_fp32_add__358__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 2794087385592660653ull);
        vlSelf->__Vfunc_fp32_add__358__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 5864616337728289586ull);
        vlSelf->__Vfunc_fp32_add__358__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 13118868916467938864ull);
        vlSelf->__Vfunc_fp32_add__358__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6471430345777264352ull);
        vlSelf->__Vfunc_fp32_add__358__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 9283844089444321695ull);
        vlSelf->__Vfunc_fp32_add__358__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1590877298983930133ull);
        vlSelf->__Vfunc_fp32_add__358__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10285672262123973656ull);
        vlSelf->__Vfunc_fp32_add__358__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6098172023920162203ull);
        __Vfunc_fp32_add__358__normalize_count = 0;
        {
            if ((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__360__bits 
                                = vlSelfRef.__Vfunc_fp32_add__358__lhs;
                            __Vfunc_fp32_is_nan__360__unused_sign = 0;
                            __Vfunc_fp32_is_nan__360__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__360__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__360__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__360__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__360__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__360__Vfuncout)) 
                 | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__361__bits 
                                = vlSelfRef.__Vfunc_fp32_add__358__rhs;
                            __Vfunc_fp32_is_nan__361__unused_sign = 0;
                            __Vfunc_fp32_is_nan__361__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__361__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__361__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__361__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__361__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__361__Vfuncout)))) {
                vlSelfRef.__Vfunc_fp32_add__358__Vfuncout = 0x7fc00000U;
                goto __Vlabel9;
            }
            if ((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__362__bits 
                                = vlSelfRef.__Vfunc_fp32_add__358__lhs;
                            __Vfunc_fp32_is_inf__362__unused_sign = 0;
                            __Vfunc_fp32_is_inf__362__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__362__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__362__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__362__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__362__Vfuncout)) 
                 | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__363__bits 
                                = vlSelfRef.__Vfunc_fp32_add__358__rhs;
                            __Vfunc_fp32_is_inf__363__unused_sign = 0;
                            __Vfunc_fp32_is_inf__363__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__363__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__363__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__363__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__363__Vfuncout)))) {
                if (((([&]() {
                                    vlSelfRef.__Vfunc_fp32_is_inf__364__bits 
                                        = vlSelfRef.__Vfunc_fp32_add__358__lhs;
                                    __Vfunc_fp32_is_inf__364__unused_sign = 0;
                                    __Vfunc_fp32_is_inf__364__unused_sign 
                                        = (vlSelfRef.__Vfunc_fp32_is_inf__364__bits 
                                           >> 0x1fU);
                                    vlSelfRef.__Vfunc_fp32_is_inf__364__Vfuncout 
                                        = (IData)((0x7f800000U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__Vfunc_fp32_is_inf__364__bits)));
                                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__364__Vfuncout)) 
                      & ([&]() {
                                    vlSelfRef.__Vfunc_fp32_is_inf__365__bits 
                                        = vlSelfRef.__Vfunc_fp32_add__358__rhs;
                                    __Vfunc_fp32_is_inf__365__unused_sign = 0;
                                    __Vfunc_fp32_is_inf__365__unused_sign 
                                        = (vlSelfRef.__Vfunc_fp32_is_inf__365__bits 
                                           >> 0x1fU);
                                    vlSelfRef.__Vfunc_fp32_is_inf__365__Vfuncout 
                                        = (IData)((0x7f800000U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__Vfunc_fp32_is_inf__365__bits)));
                                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__365__Vfuncout))) 
                     & ((vlSelfRef.__Vfunc_fp32_add__358__lhs 
                         >> 0x1fU) != (vlSelfRef.__Vfunc_fp32_add__358__rhs 
                                       >> 0x1fU)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__Vfuncout = 0x7fc00000U;
                    goto __Vlabel9;
                }
                vlSelfRef.__Vfunc_fp32_add__358__Vfuncout 
                    = (([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__366__bits 
                                = vlSelfRef.__Vfunc_fp32_add__358__lhs;
                            __Vfunc_fp32_is_inf__366__unused_sign = 0;
                            __Vfunc_fp32_is_inf__366__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__366__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__366__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__366__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__366__Vfuncout))
                        ? vlSelfRef.__Vfunc_fp32_add__358__lhs
                        : vlSelfRef.__Vfunc_fp32_add__358__rhs);
                goto __Vlabel9;
            }
            if (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__367__bits 
                            = vlSelfRef.__Vfunc_fp32_add__358__lhs;
                        __Vfunc_fp32_is_zero__367__unused_sign = 0;
                        __Vfunc_fp32_is_zero__367__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__367__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__367__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__367__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__367__Vfuncout))) {
                vlSelfRef.__Vfunc_fp32_add__358__Vfuncout 
                    = vlSelfRef.__Vfunc_fp32_add__358__rhs;
                goto __Vlabel9;
            }
            if (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__368__bits 
                            = vlSelfRef.__Vfunc_fp32_add__358__rhs;
                        __Vfunc_fp32_is_zero__368__unused_sign = 0;
                        __Vfunc_fp32_is_zero__368__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__368__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__368__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__368__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__368__Vfuncout))) {
                vlSelfRef.__Vfunc_fp32_add__358__Vfuncout 
                    = vlSelfRef.__Vfunc_fp32_add__358__lhs;
                goto __Vlabel9;
            }
            vlSelfRef.__Vfunc_fp32_add__358__lhs_sign 
                = (vlSelfRef.__Vfunc_fp32_add__358__lhs 
                   >> 0x1fU);
            vlSelfRef.__Vfunc_fp32_add__358__rhs_sign 
                = (vlSelfRef.__Vfunc_fp32_add__358__rhs 
                   >> 0x1fU);
            vlSelfRef.__Vfunc_fp32_add__358__lhs_exp 
                = (0xffU & (vlSelfRef.__Vfunc_fp32_add__358__lhs 
                            >> 0x17U));
            vlSelfRef.__Vfunc_fp32_add__358__rhs_exp 
                = (0xffU & (vlSelfRef.__Vfunc_fp32_add__358__rhs 
                            >> 0x17U));
            vlSelfRef.__Vfunc_fp32_add__358__lhs_mant 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp))
                    ? (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__358__lhs)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__358__lhs)));
            vlSelfRef.__Vfunc_fp32_add__358__rhs_mant 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp))
                    ? (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__358__rhs)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__358__rhs)));
            vlSelfRef.__Vfunc_fp32_add__358__lhs_larger 
                = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp))
                      ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp)) 
                    > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp))) 
                   | (((IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp) 
                       == (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp)) 
                      & (vlSelfRef.__Vfunc_fp32_add__358__lhs_mant 
                         >= vlSelfRef.__Vfunc_fp32_add__358__rhs_mant)));
            if (vlSelfRef.__Vfunc_fp32_add__358__lhs_larger) {
                vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp));
                vlSelfRef.__Vfunc_fp32_add__358__small_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp));
                vlSelfRef.__Vfunc_fp32_add__358__large_mant 
                    = vlSelfRef.__Vfunc_fp32_add__358__lhs_mant;
                vlSelfRef.__Vfunc_fp32_add__358__small_mant 
                    = vlSelfRef.__Vfunc_fp32_add__358__rhs_mant;
                vlSelfRef.__Vfunc_fp32_add__358__large_sign 
                    = vlSelfRef.__Vfunc_fp32_add__358__lhs_sign;
                vlSelfRef.__Vfunc_fp32_add__358__small_sign 
                    = vlSelfRef.__Vfunc_fp32_add__358__rhs_sign;
            } else {
                vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__358__rhs_exp));
                vlSelfRef.__Vfunc_fp32_add__358__small_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__358__lhs_exp));
                vlSelfRef.__Vfunc_fp32_add__358__large_mant 
                    = vlSelfRef.__Vfunc_fp32_add__358__rhs_mant;
                vlSelfRef.__Vfunc_fp32_add__358__small_mant 
                    = vlSelfRef.__Vfunc_fp32_add__358__lhs_mant;
                vlSelfRef.__Vfunc_fp32_add__358__large_sign 
                    = vlSelfRef.__Vfunc_fp32_add__358__rhs_sign;
                vlSelfRef.__Vfunc_fp32_add__358__small_sign 
                    = vlSelfRef.__Vfunc_fp32_add__358__lhs_sign;
            }
            vlSelfRef.__Vfunc_fp32_add__358__large_ext 
                = (vlSelfRef.__Vfunc_fp32_add__358__large_mant 
                   << 3U);
            vlSelfRef.__Vfunc_fp32_add__358__small_ext 
                = (vlSelfRef.__Vfunc_fp32_add__358__small_mant 
                   << 3U);
            vlSelfRef.__Vfunc_fp32_add__358__shift_amount 
                = ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                   - (IData)(vlSelfRef.__Vfunc_fp32_add__358__small_exp));
            if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__358__shift_amount)) {
                vlSelfRef.__Vfunc_fp32_add__358__aligned_small 
                    = ((0U == vlSelfRef.__Vfunc_fp32_add__358__small_ext)
                        ? 0U : 1U);
            } else {
                vlSelfRef.__Vfunc_fp32_add__358__aligned_small 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__small_ext, vlSelfRef.__Vfunc_fp32_add__358__shift_amount));
                vlSelfRef.__Vfunc_fp32_add__358__discarded_mask 
                    = ((0U == vlSelfRef.__Vfunc_fp32_add__358__shift_amount)
                        ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__358__shift_amount) 
                                              - (IData)(1U))));
                vlSelfRef.__Vfunc_fp32_add__358__sticky 
                    = (0U != (vlSelfRef.__Vfunc_fp32_add__358__small_ext 
                              & vlSelfRef.__Vfunc_fp32_add__358__discarded_mask));
                vlSelfRef.__Vfunc_fp32_add__358__aligned_small 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__358__aligned_small) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__358__aligned_small 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__358__sticky))));
            }
            vlSelfRef.__Vfunc_fp32_add__358__result_sign 
                = vlSelfRef.__Vfunc_fp32_add__358__large_sign;
            if (((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_sign) 
                 == (IData)(vlSelfRef.__Vfunc_fp32_add__358__small_sign))) {
                vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                    = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__358__large_ext 
                                     + vlSelfRef.__Vfunc_fp32_add__358__aligned_small));
                if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__358__work_ext)) {
                    vlSelfRef.__Vfunc_fp32_add__358__sticky 
                        = (1U & vlSelfRef.__Vfunc_fp32_add__358__work_ext);
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__358__work_ext) 
                           | (1U & (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                                    | (IData)(vlSelfRef.__Vfunc_fp32_add__358__sticky))));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)));
                }
            } else {
                vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                    = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__358__large_ext 
                                     - vlSelfRef.__Vfunc_fp32_add__358__aligned_small));
                if ((0U == vlSelfRef.__Vfunc_fp32_add__358__work_ext)) {
                    vlSelfRef.__Vfunc_fp32_add__358__Vfuncout = 0U;
                    goto __Vlabel9;
                }
                __Vfunc_fp32_add__358__normalize_count = 0U;
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__358__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                     - (IData)(1U)));
                }
                __Vfunc_fp32_add__358__normalize_count = 1U;
                __Vfunc_fp32_add__358__normalize_count = 2U;
                __Vfunc_fp32_add__358__normalize_count = 3U;
                __Vfunc_fp32_add__358__normalize_count = 4U;
                __Vfunc_fp32_add__358__normalize_count = 5U;
                __Vfunc_fp32_add__358__normalize_count = 6U;
                __Vfunc_fp32_add__358__normalize_count = 7U;
                __Vfunc_fp32_add__358__normalize_count = 8U;
                __Vfunc_fp32_add__358__normalize_count = 9U;
                __Vfunc_fp32_add__358__normalize_count = 0xaU;
                __Vfunc_fp32_add__358__normalize_count = 0xbU;
                __Vfunc_fp32_add__358__normalize_count = 0xcU;
                __Vfunc_fp32_add__358__normalize_count = 0xdU;
                __Vfunc_fp32_add__358__normalize_count = 0xeU;
                __Vfunc_fp32_add__358__normalize_count = 0xfU;
                __Vfunc_fp32_add__358__normalize_count = 0x10U;
                __Vfunc_fp32_add__358__normalize_count = 0x11U;
                __Vfunc_fp32_add__358__normalize_count = 0x12U;
                __Vfunc_fp32_add__358__normalize_count = 0x13U;
                __Vfunc_fp32_add__358__normalize_count = 0x14U;
                __Vfunc_fp32_add__358__normalize_count = 0x15U;
                __Vfunc_fp32_add__358__normalize_count = 0x16U;
                __Vfunc_fp32_add__358__normalize_count = 0x17U;
                __Vfunc_fp32_add__358__normalize_count = 0x18U;
                __Vfunc_fp32_add__358__normalize_count = 0x19U;
                __Vfunc_fp32_add__358__normalize_count = 0x1aU;
            }
            vlSelfRef.__Vfunc_fp32_add__358__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                                >> 3U));
            vlSelfRef.__Vfunc_fp32_add__358__increment 
                = (1U & ((vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                          >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__358__work_ext 
                                      >> 1U) | vlSelfRef.__Vfunc_fp32_add__358__work_ext) 
                                    | vlSelfRef.__Vfunc_fp32_add__358__mantissa)));
            vlSelfRef.__Vfunc_fp32_add__358__rounded 
                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__358__mantissa 
                                 + (IData)(vlSelfRef.__Vfunc_fp32_add__358__increment)));
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__358__rounded)) {
                vlSelfRef.__Vfunc_fp32_add__358__mantissa 
                    = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__358__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_add__358__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)));
            } else {
                vlSelfRef.__Vfunc_fp32_add__358__mantissa 
                    = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__358__rounded);
            }
            if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp))) {
                vlSelfRef.__Vfunc_fp32_add__358__Vfuncout 
                    = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__358__result_sign) 
                                      << 0x1fU));
                goto __Vlabel9;
            }
            if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp)) 
                 & (~ (vlSelfRef.__Vfunc_fp32_add__358__mantissa 
                       >> 0x17U)))) {
                vlSelfRef.__Vfunc_fp32_add__358__Vfuncout 
                    = (((IData)(vlSelfRef.__Vfunc_fp32_add__358__result_sign) 
                        << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__358__mantissa));
                goto __Vlabel9;
            }
            vlSelfRef.__Vfunc_fp32_add__358__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__358__result_sign) 
                    << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__358__large_exp) 
                                                 << 0x17U)) 
                                 | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__358__mantissa)));
            __Vlabel9: ;
        }
        vlSelfRef.__Vfunc_fp32_sub__357__Vfuncout = vlSelfRef.__Vfunc_fp32_add__358__Vfuncout;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operand0 
            = vlSelfRef.__Vfunc_fp32_sub__357__Vfuncout;
    } else if ((((0x82U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__opcode_q)) 
                 & (4U == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__phase_q))) 
                & (0xfU == (IData)(vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__state_q)))) {
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operation = 5U;
        vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__math_operand0 
            = tb_npu_engines__DOT__u_complex__DOT__fp_variance_plus_epsilon;
    }
}

VL_INLINE_OPT void Vtb_npu_engines___024root___nba_sequent__TOP__6(Vtb_npu_engines___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_engines___024root___nba_sequent__TOP__6\n"); );
    Vtb_npu_engines__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_fp32_add__370__lhs;
    __Vfunc_fp32_add__370__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__370__rhs;
    __Vfunc_fp32_add__370__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__370__normalize_count;
    __Vfunc_fp32_add__370__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__371__unused_sign;
    __Vfunc_fp32_is_nan__371__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__372__unused_sign;
    __Vfunc_fp32_is_nan__372__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__373__unused_sign;
    __Vfunc_fp32_is_inf__373__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__374__unused_sign;
    __Vfunc_fp32_is_inf__374__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__375__unused_sign;
    __Vfunc_fp32_is_inf__375__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__376__unused_sign;
    __Vfunc_fp32_is_inf__376__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__377__unused_sign;
    __Vfunc_fp32_is_inf__377__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__378__unused_sign;
    __Vfunc_fp32_is_zero__378__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__379__unused_sign;
    __Vfunc_fp32_is_zero__379__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__380__lhs;
    __Vfunc_fp32_mul__380__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__380__rhs;
    __Vfunc_fp32_mul__380__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_mul__380__normalize_count;
    __Vfunc_fp32_mul__380__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__381__unused_sign;
    __Vfunc_fp32_is_nan__381__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__382__unused_sign;
    __Vfunc_fp32_is_nan__382__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__383__unused_sign;
    __Vfunc_fp32_is_inf__383__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__384__unused_sign;
    __Vfunc_fp32_is_zero__384__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__385__unused_sign;
    __Vfunc_fp32_is_inf__385__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__386__unused_sign;
    __Vfunc_fp32_is_zero__386__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__387__unused_sign;
    __Vfunc_fp32_is_inf__387__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__388__unused_sign;
    __Vfunc_fp32_is_inf__388__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__389__unused_sign;
    __Vfunc_fp32_is_zero__389__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__390__unused_sign;
    __Vfunc_fp32_is_zero__390__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__456__Vfuncout;
    __Vfunc_fp32_sub__456__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__456__lhs;
    __Vfunc_fp32_sub__456__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__456__rhs;
    __Vfunc_fp32_sub__456__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__457__lhs;
    __Vfunc_fp32_add__457__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__457__rhs;
    __Vfunc_fp32_add__457__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__457__normalize_count;
    __Vfunc_fp32_add__457__normalize_count = 0;
    IData/*31:0*/ __Vfunc_fp32_neg__458__Vfuncout;
    __Vfunc_fp32_neg__458__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_neg__458__value;
    __Vfunc_fp32_neg__458__value = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__459__unused_sign;
    __Vfunc_fp32_is_nan__459__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__460__unused_sign;
    __Vfunc_fp32_is_nan__460__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__461__unused_sign;
    __Vfunc_fp32_is_inf__461__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__462__unused_sign;
    __Vfunc_fp32_is_inf__462__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__463__unused_sign;
    __Vfunc_fp32_is_inf__463__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__464__unused_sign;
    __Vfunc_fp32_is_inf__464__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__465__unused_sign;
    __Vfunc_fp32_is_inf__465__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__466__unused_sign;
    __Vfunc_fp32_is_zero__466__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__467__unused_sign;
    __Vfunc_fp32_is_zero__467__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__500__lhs;
    __Vfunc_fp32_add__500__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__500__rhs;
    __Vfunc_fp32_add__500__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__500__normalize_count;
    __Vfunc_fp32_add__500__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__501__unused_sign;
    __Vfunc_fp32_is_nan__501__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__502__unused_sign;
    __Vfunc_fp32_is_nan__502__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__503__unused_sign;
    __Vfunc_fp32_is_inf__503__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__504__unused_sign;
    __Vfunc_fp32_is_inf__504__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__505__unused_sign;
    __Vfunc_fp32_is_inf__505__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__506__unused_sign;
    __Vfunc_fp32_is_inf__506__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__507__unused_sign;
    __Vfunc_fp32_is_inf__507__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__508__unused_sign;
    __Vfunc_fp32_is_zero__508__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__509__unused_sign;
    __Vfunc_fp32_is_zero__509__unused_sign = 0;
    // Body
    __Vfunc_fp32_add__370__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
    __Vfunc_fp32_add__370__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_q;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_add__370__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15213926388715331619ull);
    vlSelf->__Vfunc_fp32_add__370__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3258411075118387734ull);
    vlSelf->__Vfunc_fp32_add__370__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14003246457556343670ull);
    vlSelf->__Vfunc_fp32_add__370__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6147051951079717057ull);
    vlSelf->__Vfunc_fp32_add__370__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15974968843297371169ull);
    vlSelf->__Vfunc_fp32_add__370__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 10145752427607283957ull);
    vlSelf->__Vfunc_fp32_add__370__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4626923053648079414ull);
    vlSelf->__Vfunc_fp32_add__370__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12811625543509382466ull);
    vlSelf->__Vfunc_fp32_add__370__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 3565999384018226675ull);
    vlSelf->__Vfunc_fp32_add__370__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 7633493998731312708ull);
    vlSelf->__Vfunc_fp32_add__370__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 672673366685093983ull);
    vlSelf->__Vfunc_fp32_add__370__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12001657451231805156ull);
    vlSelf->__Vfunc_fp32_add__370__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 750009648555705730ull);
    vlSelf->__Vfunc_fp32_add__370__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 676426075047787248ull);
    vlSelf->__Vfunc_fp32_add__370__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 4279987332065587923ull);
    vlSelf->__Vfunc_fp32_add__370__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 8580117586318726884ull);
    vlSelf->__Vfunc_fp32_add__370__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 2752659866841023791ull);
    vlSelf->__Vfunc_fp32_add__370__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 10635576355835676249ull);
    vlSelf->__Vfunc_fp32_add__370__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 18123799807665656154ull);
    vlSelf->__Vfunc_fp32_add__370__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 8796194152577538886ull);
    vlSelf->__Vfunc_fp32_add__370__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6161775843116432723ull);
    vlSelf->__Vfunc_fp32_add__370__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17936629515587624680ull);
    vlSelf->__Vfunc_fp32_add__370__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7970739767535070142ull);
    vlSelf->__Vfunc_fp32_add__370__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10464496639897320079ull);
    __Vfunc_fp32_add__370__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__371__bits 
                            = __Vfunc_fp32_add__370__lhs;
                        __Vfunc_fp32_is_nan__371__unused_sign = 0;
                        __Vfunc_fp32_is_nan__371__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__371__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__371__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__371__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__371__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__371__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__372__bits 
                            = __Vfunc_fp32_add__370__rhs;
                        __Vfunc_fp32_is_nan__372__unused_sign = 0;
                        __Vfunc_fp32_is_nan__372__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__372__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__372__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__372__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__372__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__372__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__370__Vfuncout = 0x7fc00000U;
            goto __Vlabel0;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__373__bits 
                            = __Vfunc_fp32_add__370__lhs;
                        __Vfunc_fp32_is_inf__373__unused_sign = 0;
                        __Vfunc_fp32_is_inf__373__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__373__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__373__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__373__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__373__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__374__bits 
                            = __Vfunc_fp32_add__370__rhs;
                        __Vfunc_fp32_is_inf__374__unused_sign = 0;
                        __Vfunc_fp32_is_inf__374__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__374__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__374__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__374__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__374__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__375__bits 
                                    = __Vfunc_fp32_add__370__lhs;
                                __Vfunc_fp32_is_inf__375__unused_sign = 0;
                                __Vfunc_fp32_is_inf__375__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__375__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__375__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__375__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__375__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__376__bits 
                                    = __Vfunc_fp32_add__370__rhs;
                                __Vfunc_fp32_is_inf__376__unused_sign = 0;
                                __Vfunc_fp32_is_inf__376__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__376__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__376__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__376__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__376__Vfuncout))) 
                 & ((__Vfunc_fp32_add__370__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__370__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__370__Vfuncout = 0x7fc00000U;
                goto __Vlabel0;
            }
            vlSelfRef.__Vfunc_fp32_add__370__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__377__bits 
                            = __Vfunc_fp32_add__370__lhs;
                        __Vfunc_fp32_is_inf__377__unused_sign = 0;
                        __Vfunc_fp32_is_inf__377__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__377__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__377__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__377__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__377__Vfuncout))
                    ? __Vfunc_fp32_add__370__lhs : __Vfunc_fp32_add__370__rhs);
            goto __Vlabel0;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__378__bits 
                        = __Vfunc_fp32_add__370__lhs;
                    __Vfunc_fp32_is_zero__378__unused_sign = 0;
                    __Vfunc_fp32_is_zero__378__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__378__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__378__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__378__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__378__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__370__Vfuncout 
                = __Vfunc_fp32_add__370__rhs;
            goto __Vlabel0;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__379__bits 
                        = __Vfunc_fp32_add__370__rhs;
                    __Vfunc_fp32_is_zero__379__unused_sign = 0;
                    __Vfunc_fp32_is_zero__379__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__379__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__379__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__379__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__379__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__370__Vfuncout 
                = __Vfunc_fp32_add__370__lhs;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_add__370__lhs_sign = 
            (__Vfunc_fp32_add__370__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__370__rhs_sign = 
            (__Vfunc_fp32_add__370__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__370__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__370__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__370__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__370__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__370__lhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__370__lhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__370__lhs)));
        vlSelfRef.__Vfunc_fp32_add__370__rhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__370__rhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__370__rhs)));
        vlSelfRef.__Vfunc_fp32_add__370__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__370__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__370__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__370__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__370__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__370__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__370__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__370__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__370__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__370__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__370__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__370__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__370__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__370__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__370__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__370__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__370__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__370__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__370__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__370__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__370__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__370__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__370__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__370__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__370__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__370__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__370__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__370__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__370__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__370__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__370__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__370__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__370__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__370__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__small_ext, vlSelfRef.__Vfunc_fp32_add__370__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__370__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__370__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__370__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__370__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__370__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__370__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__370__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__370__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__370__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__370__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__370__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__370__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__370__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__370__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__370__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__370__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__370__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__370__work_ext);
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__370__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__370__sticky))));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__370__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__370__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__370__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__370__Vfuncout = 0U;
                goto __Vlabel0;
            }
            __Vfunc_fp32_add__370__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__370__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__370__normalize_count = 1U;
            __Vfunc_fp32_add__370__normalize_count = 2U;
            __Vfunc_fp32_add__370__normalize_count = 3U;
            __Vfunc_fp32_add__370__normalize_count = 4U;
            __Vfunc_fp32_add__370__normalize_count = 5U;
            __Vfunc_fp32_add__370__normalize_count = 6U;
            __Vfunc_fp32_add__370__normalize_count = 7U;
            __Vfunc_fp32_add__370__normalize_count = 8U;
            __Vfunc_fp32_add__370__normalize_count = 9U;
            __Vfunc_fp32_add__370__normalize_count = 0xaU;
            __Vfunc_fp32_add__370__normalize_count = 0xbU;
            __Vfunc_fp32_add__370__normalize_count = 0xcU;
            __Vfunc_fp32_add__370__normalize_count = 0xdU;
            __Vfunc_fp32_add__370__normalize_count = 0xeU;
            __Vfunc_fp32_add__370__normalize_count = 0xfU;
            __Vfunc_fp32_add__370__normalize_count = 0x10U;
            __Vfunc_fp32_add__370__normalize_count = 0x11U;
            __Vfunc_fp32_add__370__normalize_count = 0x12U;
            __Vfunc_fp32_add__370__normalize_count = 0x13U;
            __Vfunc_fp32_add__370__normalize_count = 0x14U;
            __Vfunc_fp32_add__370__normalize_count = 0x15U;
            __Vfunc_fp32_add__370__normalize_count = 0x16U;
            __Vfunc_fp32_add__370__normalize_count = 0x17U;
            __Vfunc_fp32_add__370__normalize_count = 0x18U;
            __Vfunc_fp32_add__370__normalize_count = 0x19U;
            __Vfunc_fp32_add__370__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__370__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_add__370__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__370__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__370__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__370__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__370__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__370__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__370__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__370__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__370__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__370__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__370__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__370__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__370__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__370__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__370__result_sign) 
                                  << 0x1fU));
            goto __Vlabel0;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__370__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__370__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__370__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__370__mantissa));
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_fp32_add__370__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_add__370__result_sign) 
              << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__370__large_exp) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__370__mantissa)));
        __Vlabel0: ;
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_sum_plus_x 
        = vlSelfRef.__Vfunc_fp32_add__370__Vfuncout;
    __Vfunc_fp32_mul__380__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
    __Vfunc_fp32_mul__380__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
    vlSelf->__Vfunc_fp32_mul__380__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3920552034252684010ull);
    vlSelf->__Vfunc_fp32_mul__380__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8284850576752657967ull);
    vlSelf->__Vfunc_fp32_mul__380__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11530726201070205825ull);
    vlSelf->__Vfunc_fp32_mul__380__product = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 15134404383565441009ull);
    vlSelf->__Vfunc_fp32_mul__380__remainder_mask = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 4070566158880070402ull);
    vlSelf->__Vfunc_fp32_mul__380__remainder = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 13593367341719519182ull);
    vlSelf->__Vfunc_fp32_mul__380__halfway = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 2101618327227246977ull);
    vlSelf->__Vfunc_fp32_mul__380__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 14864941472581740576ull);
    vlSelf->__Vfunc_fp32_mul__380__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12111554903852974201ull);
    vlSelf->__Vfunc_fp32_mul__380__lhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4906940315453823916ull);
    vlSelf->__Vfunc_fp32_mul__380__rhs_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16711645492698246001ull);
    vlSelf->__Vfunc_fp32_mul__380__result_unbiased = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1487053294012462520ull);
    vlSelf->__Vfunc_fp32_mul__380__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11454964935040808220ull);
    __Vfunc_fp32_mul__380__normalize_count = 0;
    {
        if (((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__381__bits 
                                = __Vfunc_fp32_mul__380__lhs;
                            __Vfunc_fp32_is_nan__381__unused_sign = 0;
                            __Vfunc_fp32_is_nan__381__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__381__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__381__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__381__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__381__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__381__Vfuncout)) 
              | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__382__bits 
                                = __Vfunc_fp32_mul__380__rhs;
                            __Vfunc_fp32_is_nan__382__unused_sign = 0;
                            __Vfunc_fp32_is_nan__382__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__382__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__382__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__382__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__382__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__382__Vfuncout))) 
             | ((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__383__bits 
                                    = __Vfunc_fp32_mul__380__lhs;
                                __Vfunc_fp32_is_inf__383__unused_sign = 0;
                                __Vfunc_fp32_is_inf__383__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__383__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__383__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__383__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__383__Vfuncout)) 
                 & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__384__bits 
                                    = __Vfunc_fp32_mul__380__rhs;
                                __Vfunc_fp32_is_zero__384__unused_sign = 0;
                                __Vfunc_fp32_is_zero__384__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__384__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__384__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__384__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__384__Vfuncout))) 
                | (([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__385__bits 
                                    = __Vfunc_fp32_mul__380__rhs;
                                __Vfunc_fp32_is_inf__385__unused_sign = 0;
                                __Vfunc_fp32_is_inf__385__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__385__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__385__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__385__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__385__Vfuncout)) 
                   & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_zero__386__bits 
                                    = __Vfunc_fp32_mul__380__lhs;
                                __Vfunc_fp32_is_zero__386__unused_sign = 0;
                                __Vfunc_fp32_is_zero__386__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_zero__386__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_zero__386__Vfuncout 
                                    = (0U == (0x7fffffffU 
                                              & vlSelfRef.__Vfunc_fp32_is_zero__386__bits));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__386__Vfuncout)))))) {
            vlSelfRef.__Vfunc_fp32_mul__380__Vfuncout = 0x7fc00000U;
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_mul__380__result_sign 
            = ((__Vfunc_fp32_mul__380__lhs ^ __Vfunc_fp32_mul__380__rhs) 
               >> 0x1fU);
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__387__bits 
                            = __Vfunc_fp32_mul__380__lhs;
                        __Vfunc_fp32_is_inf__387__unused_sign = 0;
                        __Vfunc_fp32_is_inf__387__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__387__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__387__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__387__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__387__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__388__bits 
                            = __Vfunc_fp32_mul__380__rhs;
                        __Vfunc_fp32_is_inf__388__unused_sign = 0;
                        __Vfunc_fp32_is_inf__388__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__388__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__388__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__388__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__388__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__380__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__389__bits 
                            = __Vfunc_fp32_mul__380__lhs;
                        __Vfunc_fp32_is_zero__389__unused_sign = 0;
                        __Vfunc_fp32_is_zero__389__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__389__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__389__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__389__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__389__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__390__bits 
                            = __Vfunc_fp32_mul__380__rhs;
                        __Vfunc_fp32_is_zero__390__unused_sign = 0;
                        __Vfunc_fp32_is_zero__390__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__390__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__390__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__390__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__390__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__380__result_sign) 
                   << 0x1fU);
            goto __Vlabel1;
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__380__lhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__380__lhs);
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__380__lhs));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__380__lhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        if ((0U == (0xffU & (__Vfunc_fp32_mul__380__rhs 
                             >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0x7fffffU & __Vfunc_fp32_mul__380__rhs);
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased = 0xffffff82U;
        } else {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0x800000U | (0x7fffffU & __Vfunc_fp32_mul__380__rhs));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = ((0xffU & (__Vfunc_fp32_mul__380__rhs 
                             >> 0x17U)) - (IData)(0x7fU));
        }
        __Vfunc_fp32_mul__380__normalize_count = 0U;
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                      >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant 
                = (0xffffffU & VL_SHIFTL_III(24,24,32, vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant, 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                = (vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased 
                   - (IData)(1U));
        }
        __Vfunc_fp32_mul__380__normalize_count = 1U;
        __Vfunc_fp32_mul__380__normalize_count = 2U;
        __Vfunc_fp32_mul__380__normalize_count = 3U;
        __Vfunc_fp32_mul__380__normalize_count = 4U;
        __Vfunc_fp32_mul__380__normalize_count = 5U;
        __Vfunc_fp32_mul__380__normalize_count = 6U;
        __Vfunc_fp32_mul__380__normalize_count = 7U;
        __Vfunc_fp32_mul__380__normalize_count = 8U;
        __Vfunc_fp32_mul__380__normalize_count = 9U;
        __Vfunc_fp32_mul__380__normalize_count = 0xaU;
        __Vfunc_fp32_mul__380__normalize_count = 0xbU;
        __Vfunc_fp32_mul__380__normalize_count = 0xcU;
        __Vfunc_fp32_mul__380__normalize_count = 0xdU;
        __Vfunc_fp32_mul__380__normalize_count = 0xeU;
        __Vfunc_fp32_mul__380__normalize_count = 0xfU;
        __Vfunc_fp32_mul__380__normalize_count = 0x10U;
        __Vfunc_fp32_mul__380__normalize_count = 0x11U;
        __Vfunc_fp32_mul__380__normalize_count = 0x12U;
        __Vfunc_fp32_mul__380__normalize_count = 0x13U;
        __Vfunc_fp32_mul__380__normalize_count = 0x14U;
        __Vfunc_fp32_mul__380__normalize_count = 0x15U;
        __Vfunc_fp32_mul__380__normalize_count = 0x16U;
        __Vfunc_fp32_mul__380__normalize_count = 0x17U;
        vlSelfRef.__Vfunc_fp32_mul__380__product = 
            (0xffffffffffffULL & ((QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__380__lhs_mant)) 
                                  * (QData)((IData)(vlSelfRef.__Vfunc_fp32_mul__380__rhs_mant))));
        vlSelfRef.__Vfunc_fp32_mul__380__result_unbiased 
            = (vlSelfRef.__Vfunc_fp32_mul__380__lhs_unbiased 
               + vlSelfRef.__Vfunc_fp32_mul__380__rhs_unbiased);
        if ((1U & (IData)((vlSelfRef.__Vfunc_fp32_mul__380__product 
                           >> 0x2fU)))) {
            vlSelfRef.__Vfunc_fp32_mul__380__shift_amount = 0x18U;
            vlSelfRef.__Vfunc_fp32_mul__380__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__380__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__380__shift_amount = 0x17U;
        }
        vlSelfRef.__Vfunc_fp32_mul__380__mantissa = 
            (0xffffffU & (IData)((0xffffffffffffULL 
                                  & VL_SHIFTR_QQI(48,48,32, vlSelfRef.__Vfunc_fp32_mul__380__product, vlSelfRef.__Vfunc_fp32_mul__380__shift_amount))));
        vlSelfRef.__Vfunc_fp32_mul__380__remainder_mask 
            = (0xffffffffffffULL & (VL_SHIFTL_QQI(48,48,32, 1ULL, vlSelfRef.__Vfunc_fp32_mul__380__shift_amount) 
                                    - 1ULL));
        vlSelfRef.__Vfunc_fp32_mul__380__remainder 
            = (vlSelfRef.__Vfunc_fp32_mul__380__product 
               & vlSelfRef.__Vfunc_fp32_mul__380__remainder_mask);
        vlSelfRef.__Vfunc_fp32_mul__380__halfway = 
            (0xffffffffffffULL & VL_SHIFTL_QQI(48,48,32, 1ULL, 
                                               (vlSelfRef.__Vfunc_fp32_mul__380__shift_amount 
                                                - (IData)(1U))));
        vlSelfRef.__Vfunc_fp32_mul__380__rounded = vlSelfRef.__Vfunc_fp32_mul__380__mantissa;
        if (((vlSelfRef.__Vfunc_fp32_mul__380__remainder 
              > vlSelfRef.__Vfunc_fp32_mul__380__halfway) 
             | ((vlSelfRef.__Vfunc_fp32_mul__380__remainder 
                 == vlSelfRef.__Vfunc_fp32_mul__380__halfway) 
                & vlSelfRef.__Vfunc_fp32_mul__380__mantissa))) {
            vlSelfRef.__Vfunc_fp32_mul__380__rounded 
                = (0x1ffffffU & ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__380__rounded));
        }
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_mul__380__rounded)) {
            vlSelfRef.__Vfunc_fp32_mul__380__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_mul__380__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_mul__380__result_unbiased 
                = ((IData)(1U) + vlSelfRef.__Vfunc_fp32_mul__380__result_unbiased);
        } else {
            vlSelfRef.__Vfunc_fp32_mul__380__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_mul__380__rounded);
        }
        if (VL_LTS_III(32, 0x7fU, vlSelfRef.__Vfunc_fp32_mul__380__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__380__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_mul__380__result_sign) 
                                  << 0x1fU));
            goto __Vlabel1;
        }
        if (VL_GTS_III(32, 0xffffff82U, vlSelfRef.__Vfunc_fp32_mul__380__result_unbiased)) {
            vlSelfRef.__Vfunc_fp32_mul__380__Vfuncout 
                = ((IData)(vlSelfRef.__Vfunc_fp32_mul__380__result_sign) 
                   << 0x1fU);
            goto __Vlabel1;
        }
        vlSelfRef.__Vfunc_fp32_mul__380__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_mul__380__result_sign) 
              << 0x1fU) | ((0x7f800000U & (((IData)(0x7fU) 
                                            + vlSelfRef.__Vfunc_fp32_mul__380__result_unbiased) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_mul__380__mantissa)));
        __Vlabel1: ;
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_x_squared 
        = vlSelfRef.__Vfunc_fp32_mul__380__Vfuncout;
    __Vfunc_fp32_add__500__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__src1_fp;
    __Vfunc_fp32_add__500__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
    vlSelf->__Vfunc_fp32_add__500__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13469572921599927635ull);
    vlSelf->__Vfunc_fp32_add__500__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5498997713834917645ull);
    vlSelf->__Vfunc_fp32_add__500__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13731218629017525830ull);
    vlSelf->__Vfunc_fp32_add__500__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2343363078328383213ull);
    vlSelf->__Vfunc_fp32_add__500__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11680323755390639032ull);
    vlSelf->__Vfunc_fp32_add__500__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15051499552231719325ull);
    vlSelf->__Vfunc_fp32_add__500__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 14507627353348918485ull);
    vlSelf->__Vfunc_fp32_add__500__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11157700418076161462ull);
    vlSelf->__Vfunc_fp32_add__500__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 11923883779153922570ull);
    vlSelf->__Vfunc_fp32_add__500__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14387765507399272139ull);
    vlSelf->__Vfunc_fp32_add__500__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8993947583983452786ull);
    vlSelf->__Vfunc_fp32_add__500__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15839089231136138884ull);
    vlSelf->__Vfunc_fp32_add__500__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11402066819701976474ull);
    vlSelf->__Vfunc_fp32_add__500__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 79449961547537677ull);
    vlSelf->__Vfunc_fp32_add__500__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 14615260342915242381ull);
    vlSelf->__Vfunc_fp32_add__500__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 4302669133514172853ull);
    vlSelf->__Vfunc_fp32_add__500__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 10072016093192550870ull);
    vlSelf->__Vfunc_fp32_add__500__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 13284956734501024922ull);
    vlSelf->__Vfunc_fp32_add__500__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 12117384994017620598ull);
    vlSelf->__Vfunc_fp32_add__500__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 14704368992342339316ull);
    vlSelf->__Vfunc_fp32_add__500__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8489507716260283989ull);
    vlSelf->__Vfunc_fp32_add__500__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12116187948747838909ull);
    vlSelf->__Vfunc_fp32_add__500__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6854904603232393360ull);
    vlSelf->__Vfunc_fp32_add__500__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7541505791241737684ull);
    __Vfunc_fp32_add__500__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__501__bits 
                            = __Vfunc_fp32_add__500__lhs;
                        __Vfunc_fp32_is_nan__501__unused_sign = 0;
                        __Vfunc_fp32_is_nan__501__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__501__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__501__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__501__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__501__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__501__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__502__bits 
                            = __Vfunc_fp32_add__500__rhs;
                        __Vfunc_fp32_is_nan__502__unused_sign = 0;
                        __Vfunc_fp32_is_nan__502__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__502__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__502__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__502__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__502__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__502__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__500__Vfuncout = 0x7fc00000U;
            goto __Vlabel2;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__503__bits 
                            = __Vfunc_fp32_add__500__lhs;
                        __Vfunc_fp32_is_inf__503__unused_sign = 0;
                        __Vfunc_fp32_is_inf__503__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__503__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__503__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__503__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__503__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__504__bits 
                            = __Vfunc_fp32_add__500__rhs;
                        __Vfunc_fp32_is_inf__504__unused_sign = 0;
                        __Vfunc_fp32_is_inf__504__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__504__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__504__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__504__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__504__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__505__bits 
                                    = __Vfunc_fp32_add__500__lhs;
                                __Vfunc_fp32_is_inf__505__unused_sign = 0;
                                __Vfunc_fp32_is_inf__505__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__505__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__505__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__505__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__505__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__506__bits 
                                    = __Vfunc_fp32_add__500__rhs;
                                __Vfunc_fp32_is_inf__506__unused_sign = 0;
                                __Vfunc_fp32_is_inf__506__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__506__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__506__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__506__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__506__Vfuncout))) 
                 & ((__Vfunc_fp32_add__500__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__500__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__500__Vfuncout = 0x7fc00000U;
                goto __Vlabel2;
            }
            vlSelfRef.__Vfunc_fp32_add__500__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__507__bits 
                            = __Vfunc_fp32_add__500__lhs;
                        __Vfunc_fp32_is_inf__507__unused_sign = 0;
                        __Vfunc_fp32_is_inf__507__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__507__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__507__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__507__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__507__Vfuncout))
                    ? __Vfunc_fp32_add__500__lhs : __Vfunc_fp32_add__500__rhs);
            goto __Vlabel2;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__508__bits 
                        = __Vfunc_fp32_add__500__lhs;
                    __Vfunc_fp32_is_zero__508__unused_sign = 0;
                    __Vfunc_fp32_is_zero__508__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__508__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__508__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__508__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__508__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__500__Vfuncout 
                = __Vfunc_fp32_add__500__rhs;
            goto __Vlabel2;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__509__bits 
                        = __Vfunc_fp32_add__500__rhs;
                    __Vfunc_fp32_is_zero__509__unused_sign = 0;
                    __Vfunc_fp32_is_zero__509__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__509__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__509__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__509__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__509__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__500__Vfuncout 
                = __Vfunc_fp32_add__500__lhs;
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_add__500__lhs_sign = 
            (__Vfunc_fp32_add__500__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__500__rhs_sign = 
            (__Vfunc_fp32_add__500__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__500__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__500__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__500__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__500__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__500__lhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__500__lhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__500__lhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__500__lhs)));
        vlSelfRef.__Vfunc_fp32_add__500__rhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__500__rhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__500__rhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__500__rhs)));
        vlSelfRef.__Vfunc_fp32_add__500__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__500__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__500__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__500__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__500__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__500__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__500__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__500__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__500__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__500__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__500__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__500__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__500__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__500__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__500__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__500__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__500__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__500__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__500__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__500__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__500__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__500__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__500__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__500__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__500__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__500__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__500__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__500__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__500__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__500__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__500__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__500__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__500__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__500__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__500__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__500__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__500__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__500__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__500__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__500__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__500__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__500__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__500__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__500__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__500__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__500__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__small_ext, vlSelfRef.__Vfunc_fp32_add__500__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__500__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__500__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__500__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__500__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__500__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__500__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__500__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__500__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__500__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__500__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__500__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__500__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__500__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__500__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__500__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__500__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__500__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__500__work_ext);
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__500__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__500__sticky))));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__500__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__500__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__500__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__500__Vfuncout = 0U;
                goto __Vlabel2;
            }
            __Vfunc_fp32_add__500__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__500__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__500__normalize_count = 1U;
            __Vfunc_fp32_add__500__normalize_count = 2U;
            __Vfunc_fp32_add__500__normalize_count = 3U;
            __Vfunc_fp32_add__500__normalize_count = 4U;
            __Vfunc_fp32_add__500__normalize_count = 5U;
            __Vfunc_fp32_add__500__normalize_count = 6U;
            __Vfunc_fp32_add__500__normalize_count = 7U;
            __Vfunc_fp32_add__500__normalize_count = 8U;
            __Vfunc_fp32_add__500__normalize_count = 9U;
            __Vfunc_fp32_add__500__normalize_count = 0xaU;
            __Vfunc_fp32_add__500__normalize_count = 0xbU;
            __Vfunc_fp32_add__500__normalize_count = 0xcU;
            __Vfunc_fp32_add__500__normalize_count = 0xdU;
            __Vfunc_fp32_add__500__normalize_count = 0xeU;
            __Vfunc_fp32_add__500__normalize_count = 0xfU;
            __Vfunc_fp32_add__500__normalize_count = 0x10U;
            __Vfunc_fp32_add__500__normalize_count = 0x11U;
            __Vfunc_fp32_add__500__normalize_count = 0x12U;
            __Vfunc_fp32_add__500__normalize_count = 0x13U;
            __Vfunc_fp32_add__500__normalize_count = 0x14U;
            __Vfunc_fp32_add__500__normalize_count = 0x15U;
            __Vfunc_fp32_add__500__normalize_count = 0x16U;
            __Vfunc_fp32_add__500__normalize_count = 0x17U;
            __Vfunc_fp32_add__500__normalize_count = 0x18U;
            __Vfunc_fp32_add__500__normalize_count = 0x19U;
            __Vfunc_fp32_add__500__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__500__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_add__500__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__500__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__500__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__500__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__500__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__500__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__500__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__500__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__500__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__500__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__500__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__500__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__500__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__500__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__500__result_sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__500__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__500__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__500__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__500__mantissa));
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_add__500__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_add__500__result_sign) 
              << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__500__large_exp) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__500__mantissa)));
        __Vlabel2: ;
    }
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_add_rescale_output 
        = vlSelfRef.__Vfunc_fp32_add__500__Vfuncout;
    __Vfunc_fp32_sub__456__rhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_row_mean_q;
    __Vfunc_fp32_sub__456__lhs = vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__current_x_fp;
    __Vfunc_fp32_neg__458__value = __Vfunc_fp32_sub__456__rhs;
    __Vfunc_fp32_neg__458__Vfuncout = (((~ (__Vfunc_fp32_neg__458__value 
                                            >> 0x1fU)) 
                                        << 0x1fU) | 
                                       (0x7fffffffU 
                                        & __Vfunc_fp32_neg__458__value));
    __Vfunc_fp32_add__457__rhs = __Vfunc_fp32_neg__458__Vfuncout;
    __Vfunc_fp32_add__457__lhs = __Vfunc_fp32_sub__456__lhs;
    vlSelf->__Vfunc_fp32_add__457__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18223984545244327838ull);
    vlSelf->__Vfunc_fp32_add__457__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17024802233719496147ull);
    vlSelf->__Vfunc_fp32_add__457__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14906934695691368633ull);
    vlSelf->__Vfunc_fp32_add__457__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 583378769638077669ull);
    vlSelf->__Vfunc_fp32_add__457__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5694192659481124887ull);
    vlSelf->__Vfunc_fp32_add__457__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 13363173802966767118ull);
    vlSelf->__Vfunc_fp32_add__457__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 13582647576158708100ull);
    vlSelf->__Vfunc_fp32_add__457__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17712337968852614858ull);
    vlSelf->__Vfunc_fp32_add__457__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 9170046515968282167ull);
    vlSelf->__Vfunc_fp32_add__457__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4516810323457656445ull);
    vlSelf->__Vfunc_fp32_add__457__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 3348671894990286489ull);
    vlSelf->__Vfunc_fp32_add__457__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15273129199449404499ull);
    vlSelf->__Vfunc_fp32_add__457__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4996646680402448896ull);
    vlSelf->__Vfunc_fp32_add__457__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5500123434076048107ull);
    vlSelf->__Vfunc_fp32_add__457__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 621626880156461873ull);
    vlSelf->__Vfunc_fp32_add__457__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 4410142926537035950ull);
    vlSelf->__Vfunc_fp32_add__457__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 12464740818356532745ull);
    vlSelf->__Vfunc_fp32_add__457__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 4033226697400992248ull);
    vlSelf->__Vfunc_fp32_add__457__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 15912989672317644950ull);
    vlSelf->__Vfunc_fp32_add__457__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 1140504143601667008ull);
    vlSelf->__Vfunc_fp32_add__457__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 18174883022315121986ull);
    vlSelf->__Vfunc_fp32_add__457__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17294590568508749696ull);
    vlSelf->__Vfunc_fp32_add__457__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15008059100865516439ull);
    vlSelf->__Vfunc_fp32_add__457__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14942534696318251471ull);
    __Vfunc_fp32_add__457__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__459__bits 
                            = __Vfunc_fp32_add__457__lhs;
                        __Vfunc_fp32_is_nan__459__unused_sign = 0;
                        __Vfunc_fp32_is_nan__459__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__459__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__459__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__459__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__459__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__459__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__460__bits 
                            = __Vfunc_fp32_add__457__rhs;
                        __Vfunc_fp32_is_nan__460__unused_sign = 0;
                        __Vfunc_fp32_is_nan__460__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__460__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__460__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__460__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__460__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__460__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__457__Vfuncout = 0x7fc00000U;
            goto __Vlabel3;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__461__bits 
                            = __Vfunc_fp32_add__457__lhs;
                        __Vfunc_fp32_is_inf__461__unused_sign = 0;
                        __Vfunc_fp32_is_inf__461__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__461__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__461__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__461__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__461__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__462__bits 
                            = __Vfunc_fp32_add__457__rhs;
                        __Vfunc_fp32_is_inf__462__unused_sign = 0;
                        __Vfunc_fp32_is_inf__462__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__462__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__462__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__462__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__462__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__463__bits 
                                    = __Vfunc_fp32_add__457__lhs;
                                __Vfunc_fp32_is_inf__463__unused_sign = 0;
                                __Vfunc_fp32_is_inf__463__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__463__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__463__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__463__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__463__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__464__bits 
                                    = __Vfunc_fp32_add__457__rhs;
                                __Vfunc_fp32_is_inf__464__unused_sign = 0;
                                __Vfunc_fp32_is_inf__464__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__464__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__464__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__464__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__464__Vfuncout))) 
                 & ((__Vfunc_fp32_add__457__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__457__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__457__Vfuncout = 0x7fc00000U;
                goto __Vlabel3;
            }
            vlSelfRef.__Vfunc_fp32_add__457__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__465__bits 
                            = __Vfunc_fp32_add__457__lhs;
                        __Vfunc_fp32_is_inf__465__unused_sign = 0;
                        __Vfunc_fp32_is_inf__465__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__465__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__465__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__465__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__465__Vfuncout))
                    ? __Vfunc_fp32_add__457__lhs : __Vfunc_fp32_add__457__rhs);
            goto __Vlabel3;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__466__bits 
                        = __Vfunc_fp32_add__457__lhs;
                    __Vfunc_fp32_is_zero__466__unused_sign = 0;
                    __Vfunc_fp32_is_zero__466__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__466__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__466__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__466__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__466__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__457__Vfuncout 
                = __Vfunc_fp32_add__457__rhs;
            goto __Vlabel3;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__467__bits 
                        = __Vfunc_fp32_add__457__rhs;
                    __Vfunc_fp32_is_zero__467__unused_sign = 0;
                    __Vfunc_fp32_is_zero__467__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__467__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__467__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__467__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__467__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__457__Vfuncout 
                = __Vfunc_fp32_add__457__lhs;
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_add__457__lhs_sign = 
            (__Vfunc_fp32_add__457__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__457__rhs_sign = 
            (__Vfunc_fp32_add__457__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__457__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__457__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__457__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__457__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__457__lhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__457__lhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__457__lhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__457__lhs)));
        vlSelfRef.__Vfunc_fp32_add__457__rhs_mant = 
            ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__457__rhs_exp))
              ? (0x7fffffU & __Vfunc_fp32_add__457__rhs)
              : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__457__rhs)));
        vlSelfRef.__Vfunc_fp32_add__457__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__457__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__457__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__457__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__457__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__457__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__457__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__457__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__457__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__457__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__457__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__457__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__457__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__457__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__457__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__457__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__457__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__457__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__457__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__457__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__457__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__457__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__457__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__457__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__457__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__457__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__457__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__457__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__457__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__457__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__457__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__457__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__457__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__457__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__457__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__457__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__457__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__457__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__457__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__457__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__457__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__457__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__457__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__457__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__457__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__457__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__small_ext, vlSelfRef.__Vfunc_fp32_add__457__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__457__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__457__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__457__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__457__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__457__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__457__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__457__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__457__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__457__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__457__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__457__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__457__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__457__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__457__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__457__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__457__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__457__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__457__work_ext);
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__457__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__457__sticky))));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__457__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__457__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__457__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__457__Vfuncout = 0U;
                goto __Vlabel3;
            }
            __Vfunc_fp32_add__457__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__457__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__457__normalize_count = 1U;
            __Vfunc_fp32_add__457__normalize_count = 2U;
            __Vfunc_fp32_add__457__normalize_count = 3U;
            __Vfunc_fp32_add__457__normalize_count = 4U;
            __Vfunc_fp32_add__457__normalize_count = 5U;
            __Vfunc_fp32_add__457__normalize_count = 6U;
            __Vfunc_fp32_add__457__normalize_count = 7U;
            __Vfunc_fp32_add__457__normalize_count = 8U;
            __Vfunc_fp32_add__457__normalize_count = 9U;
            __Vfunc_fp32_add__457__normalize_count = 0xaU;
            __Vfunc_fp32_add__457__normalize_count = 0xbU;
            __Vfunc_fp32_add__457__normalize_count = 0xcU;
            __Vfunc_fp32_add__457__normalize_count = 0xdU;
            __Vfunc_fp32_add__457__normalize_count = 0xeU;
            __Vfunc_fp32_add__457__normalize_count = 0xfU;
            __Vfunc_fp32_add__457__normalize_count = 0x10U;
            __Vfunc_fp32_add__457__normalize_count = 0x11U;
            __Vfunc_fp32_add__457__normalize_count = 0x12U;
            __Vfunc_fp32_add__457__normalize_count = 0x13U;
            __Vfunc_fp32_add__457__normalize_count = 0x14U;
            __Vfunc_fp32_add__457__normalize_count = 0x15U;
            __Vfunc_fp32_add__457__normalize_count = 0x16U;
            __Vfunc_fp32_add__457__normalize_count = 0x17U;
            __Vfunc_fp32_add__457__normalize_count = 0x18U;
            __Vfunc_fp32_add__457__normalize_count = 0x19U;
            __Vfunc_fp32_add__457__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__457__mantissa = 
            (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                          >> 3U));
        vlSelfRef.__Vfunc_fp32_add__457__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__457__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__457__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__457__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__457__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__457__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__457__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__457__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__457__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__457__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__457__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__457__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__457__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__457__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__457__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__457__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__457__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__457__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__457__mantissa));
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_add__457__Vfuncout = 
            (((IData)(vlSelfRef.__Vfunc_fp32_add__457__result_sign) 
              << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__457__large_exp) 
                                           << 0x17U)) 
                           | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__457__mantissa)));
        __Vlabel3: ;
    }
    __Vfunc_fp32_sub__456__Vfuncout = vlSelfRef.__Vfunc_fp32_add__457__Vfuncout;
    vlSelfRef.tb_npu_engines__DOT__u_complex__DOT__fp_centered_x 
        = __Vfunc_fp32_sub__456__Vfuncout;
}
