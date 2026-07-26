// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_npu_single_core.h for the primary calling header

#include "Vtb_npu_single_core__pch.h"
#include "Vtb_npu_single_core___024root.h"

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__8(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__8\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_squared;
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_squared = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__2436__Vfuncout;
    __Vfunc_fp32_sub__2436__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__2436__lhs;
    __Vfunc_fp32_sub__2436__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_sub__2436__rhs;
    __Vfunc_fp32_sub__2436__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2437__lhs;
    __Vfunc_fp32_add__2437__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2437__rhs;
    __Vfunc_fp32_add__2437__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2437__normalize_count;
    __Vfunc_fp32_add__2437__normalize_count = 0;
    IData/*31:0*/ __Vfunc_fp32_neg__2438__Vfuncout;
    __Vfunc_fp32_neg__2438__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_fp32_neg__2438__value;
    __Vfunc_fp32_neg__2438__value = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2439__unused_sign;
    __Vfunc_fp32_is_nan__2439__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2440__unused_sign;
    __Vfunc_fp32_is_nan__2440__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2441__unused_sign;
    __Vfunc_fp32_is_inf__2441__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2442__unused_sign;
    __Vfunc_fp32_is_inf__2442__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2443__unused_sign;
    __Vfunc_fp32_is_inf__2443__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2444__unused_sign;
    __Vfunc_fp32_is_inf__2444__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2445__unused_sign;
    __Vfunc_fp32_is_inf__2445__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2446__unused_sign;
    __Vfunc_fp32_is_zero__2446__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2447__unused_sign;
    __Vfunc_fp32_is_zero__2447__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2448__lhs;
    __Vfunc_fp32_add__2448__lhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2448__rhs;
    __Vfunc_fp32_add__2448__rhs = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2448__normalize_count;
    __Vfunc_fp32_add__2448__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2449__unused_sign;
    __Vfunc_fp32_is_nan__2449__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2450__unused_sign;
    __Vfunc_fp32_is_nan__2450__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2451__unused_sign;
    __Vfunc_fp32_is_inf__2451__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2452__unused_sign;
    __Vfunc_fp32_is_inf__2452__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2453__unused_sign;
    __Vfunc_fp32_is_inf__2453__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2454__unused_sign;
    __Vfunc_fp32_is_inf__2454__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2455__unused_sign;
    __Vfunc_fp32_is_inf__2455__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2456__unused_sign;
    __Vfunc_fp32_is_zero__2456__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2457__unused_sign;
    __Vfunc_fp32_is_zero__2457__unused_sign = 0;
    // Body
    tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_squared 
        = vlSelfRef.__Vfunc_fp32_mul__2425__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__source_end_addr 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr 
           + VL_EXTEND_QI(64,3, ([&]() {
                    vlSelfRef.__Vfunc_dtype_storage_bytes__2134__dtype 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_src_dtype;
                    {
                        if ((0U == (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__2134__dtype))) {
                            vlSelfRef.__Vfunc_dtype_storage_bytes__2134__Vfuncout = 1U;
                            goto __Vlabel0;
                        }
                        vlSelfRef.__Vfunc_dtype_bytes__2135__dtype 
                            = vlSelfRef.__Vfunc_dtype_storage_bytes__2134__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__2135__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2135__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2135__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2135__dtype))
                                                  ? 2U
                                                  : 0U)));
                        vlSelfRef.__Vfunc_dtype_storage_bytes__2134__Vfuncout 
                            = vlSelfRef.__Vfunc_dtype_bytes__2135__Vfuncout;
                        __Vlabel0: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__2134__Vfuncout))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_end_addr 
        = (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr 
           + VL_EXTEND_QI(64,3, ([&]() {
                    vlSelfRef.__Vfunc_dtype_storage_bytes__2136__dtype 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype;
                    {
                        if ((0U == (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__2136__dtype))) {
                            vlSelfRef.__Vfunc_dtype_storage_bytes__2136__Vfuncout = 1U;
                            goto __Vlabel1;
                        }
                        vlSelfRef.__Vfunc_dtype_bytes__2137__dtype 
                            = vlSelfRef.__Vfunc_dtype_storage_bytes__2136__dtype;
                        vlSelfRef.__Vfunc_dtype_bytes__2137__Vfuncout 
                            = ((1U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2137__dtype))
                                ? 1U : ((2U == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2137__dtype))
                                         ? 4U : ((3U 
                                                  == (IData)(vlSelfRef.__Vfunc_dtype_bytes__2137__dtype))
                                                  ? 2U
                                                  : 0U)));
                        vlSelfRef.__Vfunc_dtype_storage_bytes__2136__Vfuncout 
                            = vlSelfRef.__Vfunc_dtype_bytes__2137__Vfuncout;
                        __Vlabel1: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_dtype_storage_bytes__2136__Vfuncout))));
    __Vfunc_fp32_sub__2436__rhs = tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_squared;
    __Vfunc_fp32_sub__2436__lhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_square;
    __Vfunc_fp32_neg__2438__value = __Vfunc_fp32_sub__2436__rhs;
    __Vfunc_fp32_neg__2438__Vfuncout = (((~ (__Vfunc_fp32_neg__2438__value 
                                             >> 0x1fU)) 
                                         << 0x1fU) 
                                        | (0x7fffffffU 
                                           & __Vfunc_fp32_neg__2438__value));
    __Vfunc_fp32_add__2437__rhs = __Vfunc_fp32_neg__2438__Vfuncout;
    __Vfunc_fp32_add__2437__lhs = __Vfunc_fp32_sub__2436__lhs;
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__Vfunc_fp32_add__2437__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12396167667122423764ull);
    vlSelf->__Vfunc_fp32_add__2437__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9182541537041416815ull);
    vlSelf->__Vfunc_fp32_add__2437__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17869611884961207652ull);
    vlSelf->__Vfunc_fp32_add__2437__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4821762331992246136ull);
    vlSelf->__Vfunc_fp32_add__2437__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10480670302901893633ull);
    vlSelf->__Vfunc_fp32_add__2437__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 5700416318048334676ull);
    vlSelf->__Vfunc_fp32_add__2437__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 25352554779997779ull);
    vlSelf->__Vfunc_fp32_add__2437__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 832561423158902341ull);
    vlSelf->__Vfunc_fp32_add__2437__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 6538712335114811328ull);
    vlSelf->__Vfunc_fp32_add__2437__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15117733359832009155ull);
    vlSelf->__Vfunc_fp32_add__2437__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 17921300180387387258ull);
    vlSelf->__Vfunc_fp32_add__2437__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14873851006478294891ull);
    vlSelf->__Vfunc_fp32_add__2437__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10319594150145861802ull);
    vlSelf->__Vfunc_fp32_add__2437__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13406562219566418587ull);
    vlSelf->__Vfunc_fp32_add__2437__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 17417619907832215001ull);
    vlSelf->__Vfunc_fp32_add__2437__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 8041393611067723731ull);
    vlSelf->__Vfunc_fp32_add__2437__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 7559055265922987524ull);
    vlSelf->__Vfunc_fp32_add__2437__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 7252590634982523811ull);
    vlSelf->__Vfunc_fp32_add__2437__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 9980489910215471558ull);
    vlSelf->__Vfunc_fp32_add__2437__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6348751833414835508ull);
    vlSelf->__Vfunc_fp32_add__2437__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 12502495825765101911ull);
    vlSelf->__Vfunc_fp32_add__2437__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11505125971654731551ull);
    vlSelf->__Vfunc_fp32_add__2437__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14600666836710277042ull);
    vlSelf->__Vfunc_fp32_add__2437__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6326471822609847451ull);
    __Vfunc_fp32_add__2437__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2439__bits 
                            = __Vfunc_fp32_add__2437__lhs;
                        __Vfunc_fp32_is_nan__2439__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2439__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2439__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2439__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2439__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2439__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2439__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2440__bits 
                            = __Vfunc_fp32_add__2437__rhs;
                        __Vfunc_fp32_is_nan__2440__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2440__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2440__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2440__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2440__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2440__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2440__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout = 0x7fc00000U;
            goto __Vlabel2;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2441__bits 
                            = __Vfunc_fp32_add__2437__lhs;
                        __Vfunc_fp32_is_inf__2441__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2441__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2441__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2441__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2441__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2441__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2442__bits 
                            = __Vfunc_fp32_add__2437__rhs;
                        __Vfunc_fp32_is_inf__2442__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2442__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2442__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2442__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2442__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2442__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2443__bits 
                                    = __Vfunc_fp32_add__2437__lhs;
                                __Vfunc_fp32_is_inf__2443__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2443__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2443__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2443__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2443__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2443__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2444__bits 
                                    = __Vfunc_fp32_add__2437__rhs;
                                __Vfunc_fp32_is_inf__2444__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2444__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2444__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2444__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2444__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2444__Vfuncout))) 
                 & ((__Vfunc_fp32_add__2437__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__2437__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout = 0x7fc00000U;
                goto __Vlabel2;
            }
            vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2445__bits 
                            = __Vfunc_fp32_add__2437__lhs;
                        __Vfunc_fp32_is_inf__2445__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2445__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2445__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2445__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2445__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2445__Vfuncout))
                    ? __Vfunc_fp32_add__2437__lhs : __Vfunc_fp32_add__2437__rhs);
            goto __Vlabel2;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2446__bits 
                        = __Vfunc_fp32_add__2437__lhs;
                    __Vfunc_fp32_is_zero__2446__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2446__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2446__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2446__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2446__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2446__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout 
                = __Vfunc_fp32_add__2437__rhs;
            goto __Vlabel2;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2447__bits 
                        = __Vfunc_fp32_add__2437__rhs;
                    __Vfunc_fp32_is_zero__2447__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2447__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2447__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2447__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2447__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2447__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout 
                = __Vfunc_fp32_add__2437__lhs;
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_add__2437__lhs_sign 
            = (__Vfunc_fp32_add__2437__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2437__rhs_sign 
            = (__Vfunc_fp32_add__2437__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2437__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2437__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2437__lhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2437__lhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2437__lhs)));
        vlSelfRef.__Vfunc_fp32_add__2437__rhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2437__rhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2437__rhs)));
        vlSelfRef.__Vfunc_fp32_add__2437__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__2437__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__2437__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__2437__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2437__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2437__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2437__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2437__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2437__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2437__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2437__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2437__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2437__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2437__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2437__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2437__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2437__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2437__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2437__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2437__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2437__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2437__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2437__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2437__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__2437__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2437__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2437__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2437__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2437__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__2437__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__2437__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__2437__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2437__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__2437__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__small_ext, vlSelfRef.__Vfunc_fp32_add__2437__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__2437__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2437__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__2437__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__2437__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__2437__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__2437__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__2437__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2437__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__2437__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__2437__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__2437__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__2437__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2437__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__2437__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__2437__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2437__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__2437__work_ext);
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2437__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__2437__sticky))));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2437__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__2437__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__2437__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout = 0U;
                goto __Vlabel2;
            }
            __Vfunc_fp32_add__2437__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2437__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__2437__normalize_count = 1U;
            __Vfunc_fp32_add__2437__normalize_count = 2U;
            __Vfunc_fp32_add__2437__normalize_count = 3U;
            __Vfunc_fp32_add__2437__normalize_count = 4U;
            __Vfunc_fp32_add__2437__normalize_count = 5U;
            __Vfunc_fp32_add__2437__normalize_count = 6U;
            __Vfunc_fp32_add__2437__normalize_count = 7U;
            __Vfunc_fp32_add__2437__normalize_count = 8U;
            __Vfunc_fp32_add__2437__normalize_count = 9U;
            __Vfunc_fp32_add__2437__normalize_count = 0xaU;
            __Vfunc_fp32_add__2437__normalize_count = 0xbU;
            __Vfunc_fp32_add__2437__normalize_count = 0xcU;
            __Vfunc_fp32_add__2437__normalize_count = 0xdU;
            __Vfunc_fp32_add__2437__normalize_count = 0xeU;
            __Vfunc_fp32_add__2437__normalize_count = 0xfU;
            __Vfunc_fp32_add__2437__normalize_count = 0x10U;
            __Vfunc_fp32_add__2437__normalize_count = 0x11U;
            __Vfunc_fp32_add__2437__normalize_count = 0x12U;
            __Vfunc_fp32_add__2437__normalize_count = 0x13U;
            __Vfunc_fp32_add__2437__normalize_count = 0x14U;
            __Vfunc_fp32_add__2437__normalize_count = 0x15U;
            __Vfunc_fp32_add__2437__normalize_count = 0x16U;
            __Vfunc_fp32_add__2437__normalize_count = 0x17U;
            __Vfunc_fp32_add__2437__normalize_count = 0x18U;
            __Vfunc_fp32_add__2437__normalize_count = 0x19U;
            __Vfunc_fp32_add__2437__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__2437__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_add__2437__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__2437__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__2437__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__2437__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__2437__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__2437__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__2437__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__2437__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__2437__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2437__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__2437__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__2437__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__2437__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__result_sign) 
                                  << 0x1fU));
            goto __Vlabel2;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__2437__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__2437__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2437__mantissa));
            goto __Vlabel2;
        }
        vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_add__2437__result_sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__2437__large_exp) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2437__mantissa)));
        __Vlabel2: ;
    }
    __Vfunc_fp32_sub__2436__Vfuncout = vlSelfRef.__Vfunc_fp32_add__2437__Vfuncout;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_variance 
        = __Vfunc_fp32_sub__2436__Vfuncout;
    __Vfunc_fp32_add__2448__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x24U];
    __Vfunc_fp32_add__2448__lhs = ((5U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x13U])
                                    ? ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_variance 
                                        >> 0x1fU) ? 0U
                                        : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_variance)
                                    : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_mean_square);
    vlSelf->__Vfunc_fp32_add__2448__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7780758949167807412ull);
    vlSelf->__Vfunc_fp32_add__2448__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5176698633999424678ull);
    vlSelf->__Vfunc_fp32_add__2448__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3067407594559305820ull);
    vlSelf->__Vfunc_fp32_add__2448__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3804385220796930687ull);
    vlSelf->__Vfunc_fp32_add__2448__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8430069223449870185ull);
    vlSelf->__Vfunc_fp32_add__2448__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 11426233674736146748ull);
    vlSelf->__Vfunc_fp32_add__2448__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 13084585499509199178ull);
    vlSelf->__Vfunc_fp32_add__2448__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 4513079105965656071ull);
    vlSelf->__Vfunc_fp32_add__2448__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 15196973929670138337ull);
    vlSelf->__Vfunc_fp32_add__2448__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8998493861487238488ull);
    vlSelf->__Vfunc_fp32_add__2448__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5811507611962379444ull);
    vlSelf->__Vfunc_fp32_add__2448__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4895881032328722293ull);
    vlSelf->__Vfunc_fp32_add__2448__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6660698895974017831ull);
    vlSelf->__Vfunc_fp32_add__2448__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5602688285804464671ull);
    vlSelf->__Vfunc_fp32_add__2448__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 8124151621159397754ull);
    vlSelf->__Vfunc_fp32_add__2448__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 2009129899732855975ull);
    vlSelf->__Vfunc_fp32_add__2448__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 11331594719887510584ull);
    vlSelf->__Vfunc_fp32_add__2448__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 881483821224458656ull);
    vlSelf->__Vfunc_fp32_add__2448__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 15782164056792614256ull);
    vlSelf->__Vfunc_fp32_add__2448__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6744894437367558003ull);
    vlSelf->__Vfunc_fp32_add__2448__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 5601754097249558828ull);
    vlSelf->__Vfunc_fp32_add__2448__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1156223759068138376ull);
    vlSelf->__Vfunc_fp32_add__2448__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16081085957908036682ull);
    vlSelf->__Vfunc_fp32_add__2448__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13133338306691817769ull);
    __Vfunc_fp32_add__2448__normalize_count = 0;
    {
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2449__bits 
                            = __Vfunc_fp32_add__2448__lhs;
                        __Vfunc_fp32_is_nan__2449__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2449__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2449__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2449__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2449__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2449__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2449__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_nan__2450__bits 
                            = __Vfunc_fp32_add__2448__rhs;
                        __Vfunc_fp32_is_nan__2450__unused_sign = 0;
                        __Vfunc_fp32_is_nan__2450__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_nan__2450__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_nan__2450__Vfuncout 
                            = (IData)(((0x7f800000U 
                                        == (0x7f800000U 
                                            & vlSelfRef.__Vfunc_fp32_is_nan__2450__bits)) 
                                       & (0U != (0x7fffffU 
                                                 & vlSelfRef.__Vfunc_fp32_is_nan__2450__bits))));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2450__Vfuncout)))) {
            vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout = 0x7fc00000U;
            goto __Vlabel3;
        }
        if ((([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2451__bits 
                            = __Vfunc_fp32_add__2448__lhs;
                        __Vfunc_fp32_is_inf__2451__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2451__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2451__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2451__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2451__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2451__Vfuncout)) 
             | ([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2452__bits 
                            = __Vfunc_fp32_add__2448__rhs;
                        __Vfunc_fp32_is_inf__2452__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2452__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2452__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2452__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2452__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2452__Vfuncout)))) {
            if (((([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2453__bits 
                                    = __Vfunc_fp32_add__2448__lhs;
                                __Vfunc_fp32_is_inf__2453__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2453__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2453__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2453__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2453__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2453__Vfuncout)) 
                  & ([&]() {
                                vlSelfRef.__Vfunc_fp32_is_inf__2454__bits 
                                    = __Vfunc_fp32_add__2448__rhs;
                                __Vfunc_fp32_is_inf__2454__unused_sign = 0;
                                __Vfunc_fp32_is_inf__2454__unused_sign 
                                    = (vlSelfRef.__Vfunc_fp32_is_inf__2454__bits 
                                       >> 0x1fU);
                                vlSelfRef.__Vfunc_fp32_is_inf__2454__Vfuncout 
                                    = (IData)((0x7f800000U 
                                               == (0x7fffffffU 
                                                   & vlSelfRef.__Vfunc_fp32_is_inf__2454__bits)));
                            }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2454__Vfuncout))) 
                 & ((__Vfunc_fp32_add__2448__lhs >> 0x1fU) 
                    != (__Vfunc_fp32_add__2448__rhs 
                        >> 0x1fU)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout = 0x7fc00000U;
                goto __Vlabel3;
            }
            vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout 
                = (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_inf__2455__bits 
                            = __Vfunc_fp32_add__2448__lhs;
                        __Vfunc_fp32_is_inf__2455__unused_sign = 0;
                        __Vfunc_fp32_is_inf__2455__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_inf__2455__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_inf__2455__Vfuncout 
                            = (IData)((0x7f800000U 
                                       == (0x7fffffffU 
                                           & vlSelfRef.__Vfunc_fp32_is_inf__2455__bits)));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2455__Vfuncout))
                    ? __Vfunc_fp32_add__2448__lhs : __Vfunc_fp32_add__2448__rhs);
            goto __Vlabel3;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2456__bits 
                        = __Vfunc_fp32_add__2448__lhs;
                    __Vfunc_fp32_is_zero__2456__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2456__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2456__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2456__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2456__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2456__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout 
                = __Vfunc_fp32_add__2448__rhs;
            goto __Vlabel3;
        }
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_is_zero__2457__bits 
                        = __Vfunc_fp32_add__2448__rhs;
                    __Vfunc_fp32_is_zero__2457__unused_sign = 0;
                    __Vfunc_fp32_is_zero__2457__unused_sign 
                        = (vlSelfRef.__Vfunc_fp32_is_zero__2457__bits 
                           >> 0x1fU);
                    vlSelfRef.__Vfunc_fp32_is_zero__2457__Vfuncout 
                        = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2457__bits));
                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2457__Vfuncout))) {
            vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout 
                = __Vfunc_fp32_add__2448__lhs;
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_add__2448__lhs_sign 
            = (__Vfunc_fp32_add__2448__lhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2448__rhs_sign 
            = (__Vfunc_fp32_add__2448__rhs >> 0x1fU);
        vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2448__lhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp = 
            (0xffU & (__Vfunc_fp32_add__2448__rhs >> 0x17U));
        vlSelfRef.__Vfunc_fp32_add__2448__lhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2448__lhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2448__lhs)));
        vlSelfRef.__Vfunc_fp32_add__2448__rhs_mant 
            = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp))
                ? (0x7fffffU & __Vfunc_fp32_add__2448__rhs)
                : (0x800000U | (0x7fffffU & __Vfunc_fp32_add__2448__rhs)));
        vlSelfRef.__Vfunc_fp32_add__2448__lhs_larger 
            = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp))
                  ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp)) 
                > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp))) 
               | (((IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp) 
                   == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp)) 
                  & (vlSelfRef.__Vfunc_fp32_add__2448__lhs_mant 
                     >= vlSelfRef.__Vfunc_fp32_add__2448__rhs_mant)));
        if (vlSelfRef.__Vfunc_fp32_add__2448__lhs_larger) {
            vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2448__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2448__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2448__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2448__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2448__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2448__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2448__lhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2448__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2448__rhs_sign;
        } else {
            vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2448__rhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2448__small_exp 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp))
                    ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2448__lhs_exp));
            vlSelfRef.__Vfunc_fp32_add__2448__large_mant 
                = vlSelfRef.__Vfunc_fp32_add__2448__rhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2448__small_mant 
                = vlSelfRef.__Vfunc_fp32_add__2448__lhs_mant;
            vlSelfRef.__Vfunc_fp32_add__2448__large_sign 
                = vlSelfRef.__Vfunc_fp32_add__2448__rhs_sign;
            vlSelfRef.__Vfunc_fp32_add__2448__small_sign 
                = vlSelfRef.__Vfunc_fp32_add__2448__lhs_sign;
        }
        vlSelfRef.__Vfunc_fp32_add__2448__large_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2448__large_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2448__small_ext 
            = (vlSelfRef.__Vfunc_fp32_add__2448__small_mant 
               << 3U);
        vlSelfRef.__Vfunc_fp32_add__2448__shift_amount 
            = ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
               - (IData)(vlSelfRef.__Vfunc_fp32_add__2448__small_exp));
        if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__2448__shift_amount)) {
            vlSelfRef.__Vfunc_fp32_add__2448__aligned_small 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2448__small_ext)
                    ? 0U : 1U);
        } else {
            vlSelfRef.__Vfunc_fp32_add__2448__aligned_small 
                = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__small_ext, vlSelfRef.__Vfunc_fp32_add__2448__shift_amount));
            vlSelfRef.__Vfunc_fp32_add__2448__discarded_mask 
                = ((0U == vlSelfRef.__Vfunc_fp32_add__2448__shift_amount)
                    ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__2448__shift_amount) 
                                          - (IData)(1U))));
            vlSelfRef.__Vfunc_fp32_add__2448__sticky 
                = (0U != (vlSelfRef.__Vfunc_fp32_add__2448__small_ext 
                          & vlSelfRef.__Vfunc_fp32_add__2448__discarded_mask));
            vlSelfRef.__Vfunc_fp32_add__2448__aligned_small 
                = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2448__aligned_small) 
                   | (1U & (vlSelfRef.__Vfunc_fp32_add__2448__aligned_small 
                            | (IData)(vlSelfRef.__Vfunc_fp32_add__2448__sticky))));
        }
        vlSelfRef.__Vfunc_fp32_add__2448__result_sign 
            = vlSelfRef.__Vfunc_fp32_add__2448__large_sign;
        if (((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_sign) 
             == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__small_sign))) {
            vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2448__large_ext 
                                 + vlSelfRef.__Vfunc_fp32_add__2448__aligned_small));
            if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__2448__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2448__sticky 
                    = (1U & vlSelfRef.__Vfunc_fp32_add__2448__work_ext);
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2448__work_ext) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__2448__sticky))));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)));
            }
        } else {
            vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2448__large_ext 
                                 - vlSelfRef.__Vfunc_fp32_add__2448__aligned_small));
            if ((0U == vlSelfRef.__Vfunc_fp32_add__2448__work_ext)) {
                vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout = 0U;
                goto __Vlabel3;
            }
            __Vfunc_fp32_add__2448__normalize_count = 0U;
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            if (((~ (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                     >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)))) {
                vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                    = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2448__work_ext, 1U));
                vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                    = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                 - (IData)(1U)));
            }
            __Vfunc_fp32_add__2448__normalize_count = 1U;
            __Vfunc_fp32_add__2448__normalize_count = 2U;
            __Vfunc_fp32_add__2448__normalize_count = 3U;
            __Vfunc_fp32_add__2448__normalize_count = 4U;
            __Vfunc_fp32_add__2448__normalize_count = 5U;
            __Vfunc_fp32_add__2448__normalize_count = 6U;
            __Vfunc_fp32_add__2448__normalize_count = 7U;
            __Vfunc_fp32_add__2448__normalize_count = 8U;
            __Vfunc_fp32_add__2448__normalize_count = 9U;
            __Vfunc_fp32_add__2448__normalize_count = 0xaU;
            __Vfunc_fp32_add__2448__normalize_count = 0xbU;
            __Vfunc_fp32_add__2448__normalize_count = 0xcU;
            __Vfunc_fp32_add__2448__normalize_count = 0xdU;
            __Vfunc_fp32_add__2448__normalize_count = 0xeU;
            __Vfunc_fp32_add__2448__normalize_count = 0xfU;
            __Vfunc_fp32_add__2448__normalize_count = 0x10U;
            __Vfunc_fp32_add__2448__normalize_count = 0x11U;
            __Vfunc_fp32_add__2448__normalize_count = 0x12U;
            __Vfunc_fp32_add__2448__normalize_count = 0x13U;
            __Vfunc_fp32_add__2448__normalize_count = 0x14U;
            __Vfunc_fp32_add__2448__normalize_count = 0x15U;
            __Vfunc_fp32_add__2448__normalize_count = 0x16U;
            __Vfunc_fp32_add__2448__normalize_count = 0x17U;
            __Vfunc_fp32_add__2448__normalize_count = 0x18U;
            __Vfunc_fp32_add__2448__normalize_count = 0x19U;
            __Vfunc_fp32_add__2448__normalize_count = 0x1aU;
        }
        vlSelfRef.__Vfunc_fp32_add__2448__mantissa 
            = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                            >> 3U));
        vlSelfRef.__Vfunc_fp32_add__2448__increment 
            = (1U & ((vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                      >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__2448__work_ext 
                                  >> 1U) | vlSelfRef.__Vfunc_fp32_add__2448__work_ext) 
                                | vlSelfRef.__Vfunc_fp32_add__2448__mantissa)));
        vlSelfRef.__Vfunc_fp32_add__2448__rounded = 
            (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__2448__mantissa 
                           + (IData)(vlSelfRef.__Vfunc_fp32_add__2448__increment)));
        if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__2448__rounded)) {
            vlSelfRef.__Vfunc_fp32_add__2448__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2448__rounded 
                                >> 1U));
            vlSelfRef.__Vfunc_fp32_add__2448__large_exp 
                = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)));
        } else {
            vlSelfRef.__Vfunc_fp32_add__2448__mantissa 
                = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__2448__rounded);
        }
        if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp))) {
            vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout 
                = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__result_sign) 
                                  << 0x1fU));
            goto __Vlabel3;
        }
        if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp)) 
             & (~ (vlSelfRef.__Vfunc_fp32_add__2448__mantissa 
                   >> 0x17U)))) {
            vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__2448__result_sign) 
                    << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2448__mantissa));
            goto __Vlabel3;
        }
        vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout 
            = (((IData)(vlSelfRef.__Vfunc_fp32_add__2448__result_sign) 
                << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__2448__large_exp) 
                                             << 0x17U)) 
                             | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2448__mantissa)));
        __Vlabel3: ;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_variance_plus_epsilon 
        = vlSelfRef.__Vfunc_fp32_add__2448__Vfuncout;
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_comb__TOP__0(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_comb__TOP__0\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr = 0;
    SData/*8:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__burst;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__burst = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__lock;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__lock = 0;
    IData/*24:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__Vfuncout = 0;
    IData/*23:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr = 0;
    SData/*8:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats = 0;
    CData/*2:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size = 0;
    CData/*1:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__burst;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__burst = 0;
    CData/*0:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__lock;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__lock = 0;
    IData/*24:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr = 0;
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT____VdfgRegularize_h29da96d0_0_0 
        = ((1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i)))) 
           & ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i)) 
              & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i)) 
                 & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i)))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_csr_format_w 
        = ((((((0x20000U > vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i) 
               & (1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i))))) 
              & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i))) 
             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i))) 
            & (3U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i))) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__addr_low 
                    = (7U & vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size 
                    = vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__Vfuncout 
                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size) 
                                 >> 2U))) && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size))
                                                   ? 
                                                  (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__addr_low))
                                                   : 
                                                  (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__addr_low))))
                                               : ((1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__size))) 
                                                  || (1U 
                                                      & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__addr_low))))));
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1654__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ar_csr_format_w 
        = ((((((0x20000U > vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i) 
               & (1U == (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i))))) 
              & (1U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i))) 
             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i))) 
            & (3U >= (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i))) 
           & ([&]() {
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__addr_low 
                    = (7U & vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i);
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size 
                    = vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i;
                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__Vfuncout 
                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size) 
                                 >> 2U))) && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size))
                                               ? ((1U 
                                                   & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size))
                                                   ? 
                                                  (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__addr_low))
                                                   : 
                                                  (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__addr_low))))
                                               : ((1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__size))) 
                                                  || (1U 
                                                      & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__addr_low))))));
            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1657__Vfuncout)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_cmd_format_w 
        = ((0x20000U == vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i) 
           & ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i)) 
              & ((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i)) 
                 & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i)) 
                    & ((2U <= (0x1ffU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i)))) 
                       & ((~ ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i))) 
                          & (0x10U >= (0x1ffU & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i))))))))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__lock 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_awlock_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__burst 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_awburst_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_awsize_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats 
        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_awlen_i)));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_awaddr_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr 
        = (0x1ffffffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr 
                         + (((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats) 
                             - (IData)(1U)) << (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__Vfuncout 
        = ((((((((~ (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__lock)) 
                 & (1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__burst))) 
                & (3U >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size))) 
               & ([&]() {
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__addr_low 
                                    = (7U & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr);
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size 
                                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size;
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__Vfuncout 
                                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size) 
                                                 >> 2U))) 
                                       && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size))
                                                ? (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__addr_low))
                                                : (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__addr_low))))
                                            : ((1U 
                                                & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__size))) 
                                               || (1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__addr_low))))));
                            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1656__Vfuncout))) 
              & ((1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__beats)) 
                 | (3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__size)))) 
             & (0x100000U <= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr)) 
            & (0x1fffffU >= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr)) 
           & ((0xfffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__addr 
                         >> 0xcU)) == (0xfffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__last_addr 
                                                 >> 0xcU))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aw_l1_format_w 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1655__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__lock 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_arlock_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__burst 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_arburst_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_arsize_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats 
        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_arlen_i)));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr 
        = vlSelfRef.tb_npu_single_core__DOT__s_axi_araddr_i;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr 
        = (0x1ffffffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr 
                         + (((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats) 
                             - (IData)(1U)) << (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size))));
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__Vfuncout 
        = ((((((((~ (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__lock)) 
                 & (1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__burst))) 
                & (3U >= (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size))) 
               & ([&]() {
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__addr_low 
                                    = (7U & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr);
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size 
                                    = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size;
                                vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__Vfuncout 
                                    = ((1U & (~ ((IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size) 
                                                 >> 2U))) 
                                       && ((2U & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size))
                                                ? (0U 
                                                   == (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__addr_low))
                                                : (0U 
                                                   == 
                                                   (3U 
                                                    & (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__addr_low))))
                                            : ((1U 
                                                & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__size))) 
                                               || (1U 
                                                   & (~ (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__addr_low))))));
                            }(), (IData)(vlSelfRef.__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__aligned_for_size__1659__Vfuncout))) 
              & ((1U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__beats)) 
                 | (3U == (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__size)))) 
             & (0x100000U <= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr)) 
            & (0x1fffffU >= __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr)) 
           & ((0xfffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__addr 
                         >> 0xcU)) == (0xfffU & (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__last_addr 
                                                 >> 0xcU))));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__ar_l1_format_w 
        = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__l1_burst_ok__1658__Vfuncout;
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__9(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__9\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__old_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__old_value = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__new_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__new_value = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__strobe;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__mask;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__mask = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__strobe;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__mask;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__mask = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__old_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__old_value = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__new_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__new_value = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__strobe;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__mask;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__mask = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__strobe;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__mask;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__mask = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__old_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__old_value = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__new_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__new_value = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__strobe;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__mask;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__mask = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__strobe;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__mask;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__mask = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__old_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__old_value = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__new_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__new_value = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__strobe;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__mask;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__mask = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__strobe;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__mask;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__mask = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__old_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__old_value = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__new_value;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__new_value = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__strobe;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__mask;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__mask = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__strobe;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__mask;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__mask = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__strobe;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__strobe = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__mask;
    __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__mask = 0;
    // Body
    if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_crg__DOT__core_reset_sync_q))) {
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_task_valid) 
             & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_active_id_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__vector_select];
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_task_valid) 
             & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__matrix_select];
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_task_valid) 
             & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_active_id_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__dma_select];
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_task_valid) 
             & (0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_active_id_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__complex_select];
        }
    } else {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_active_id_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_active_id_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_active_id_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_active_id_q = 0U;
    }
    if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_crg__DOT__core_reset_sync_q))) {
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__internal_soft_reset_pulse = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_clear = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__wdt_kick = 0U;
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_valid_q) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_rsp_ready))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_valid_q = 0U;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_valid) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_ready))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_valid_q = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_data_q 
                = ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q))
                    ? 0ULL : vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_read_data);
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q 
                = ((0U == (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))
                    ? 0U : 2U);
            if ((((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q)) 
                  & (0U == (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) 
                 & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_space)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                              >> 0xfU)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                  >> 0xeU)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                      >> 0xdU)))) {
                            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                          >> 0xcU)))) {
                                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                              >> 0xbU)))) {
                                    if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                  >> 0xaU)))) {
                                        if ((0x200U 
                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                     >> 8U)))) {
                                                if (
                                                    (0x80U 
                                                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                    if (
                                                        (0x40U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 5U)))) {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                         >> 3U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ 
                                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                             >> 2U)))) {
                                                                        if (
                                                                            (1U 
                                                                             & (~ 
                                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                                >> 1U)))) {
                                                                            if (
                                                                                (1U 
                                                                                & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                                if (
                                                                                (0U 
                                                                                != 
                                                                                (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                                                                                >> 8U))) {
                                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                                } else {
                                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__module_clk_enable_q 
                                                                                = 
                                                                                (0xffU 
                                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q));
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            } else if (
                                                                       (8U 
                                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                         >> 2U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ 
                                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                             >> 1U)))) {
                                                                        if (
                                                                            (1U 
                                                                             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                            if (
                                                                                (0U 
                                                                                != (IData)(
                                                                                (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                                                                                >> 0x20U)))) {
                                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                            } else {
                                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__wdt_timeout_cycles_q 
                                                                                = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q);
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            } else if (
                                                                       (1U 
                                                                        & (~ 
                                                                           ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                            >> 2U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                         >> 1U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                        if (
                                                                            (0U 
                                                                             != 
                                                                             (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                                                                              >> 2U))) {
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                        } else {
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__wdt_enable_q 
                                                                                = 
                                                                                (1U 
                                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q));
                                                                            if (
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                                                                                >> 1U)))) {
                                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__wdt_kick = 1U;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                        >> 8U)))) {
                                            if ((0x80U 
                                                 & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                if (
                                                    (0x40U 
                                                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                    if (
                                                        (0x20U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                        if (
                                                            (0x10U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 3U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                         >> 2U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ 
                                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                             >> 1U)))) {
                                                                        if (
                                                                            (1U 
                                                                             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                            if (
                                                                                (0U 
                                                                                != 
                                                                                (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                                                                                >> 1U))) {
                                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                            } else {
                                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__l1_host_access_enable_q 
                                                                                = 
                                                                                (1U 
                                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q));
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        } else if (
                                                                   (8U 
                                                                    & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 2U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                         >> 1U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    }
                                                                }
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (~ 
                                                                       ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                        >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        (1U 
                                                                         & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q) 
                                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q)))) {
                                                                        if (
                                                                            (0U 
                                                                             == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q))) {
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_lock_q = 1U;
                                                                        } else {
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (0x10U 
                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 2U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                         >> 1U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                        if (
                                                                            (1U 
                                                                             & (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)) 
                                                                                | (0ULL 
                                                                                != 
                                                                                (0xfffffffffff00007ULL 
                                                                                & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q))) 
                                                                                | ((0xfffffU 
                                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q)) 
                                                                                < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_base_q)))) {
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                        } else {
                                                                            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_limit_q 
                                                                                = 
                                                                                (0xfffffU 
                                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q));
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (~ 
                                                                       ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                        >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)) 
                                                                             | (0ULL 
                                                                                != 
                                                                                (0xfffffffffff00007ULL 
                                                                                & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q))) 
                                                                            | ((0xfffffU 
                                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q)) 
                                                                               > vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_limit_q)))) {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    } else {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_base_q 
                                                                            = 
                                                                            (0xfffffU 
                                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q));
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        (1U 
                                                                         & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q) 
                                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q)))) {
                                                                        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q = 0U;
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_clear = 1U;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                    >> 2U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 1U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (0x20U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        (0U 
                                                                         != 
                                                                         (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                                                                          >> 3U))) {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    } else {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_mask_q 
                                                                            = 
                                                                            (7U 
                                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q));
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                    >> 2U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 1U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q 
                                                                    = 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q) 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q) 
                                                                         & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q)))))));
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (0x10U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                             >> 3U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        (1U 
                                                                         & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)) 
                                                                            | (0U 
                                                                               != (IData)(
                                                                                (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                                                                                >> 0x20U)))))) {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    } else {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__tbu_stream_id_q 
                                                                            = 
                                                                            (0xffffU 
                                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q));
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__tbu_substream_id_q 
                                                                            = 
                                                                            (0xffffU 
                                                                             & (IData)(
                                                                                (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                                                                                >> 0x10U)));
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (8U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                             >> 2U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 1U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                if (
                                                                    (1U 
                                                                     & (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)) 
                                                                         | (0ULL 
                                                                            != 
                                                                            (0xffff000000000007ULL 
                                                                             & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q))) 
                                                                        | ((0xffffffffffffULL 
                                                                            & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q) 
                                                                           < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_base_q)))) {
                                                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                } else {
                                                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_limit_q 
                                                                        = 
                                                                        (0xffffffffffffULL 
                                                                         & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q);
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                >> 2U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                            if (
                                                                (1U 
                                                                 & (((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)) 
                                                                     | (0ULL 
                                                                        != 
                                                                        (0xffff000000000007ULL 
                                                                         & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q))) 
                                                                    | ((0xffffffffffffULL 
                                                                        & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q) 
                                                                       > vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_limit_q)))) {
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                            } else {
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_base_q 
                                                                    = 
                                                                    (0xffffffffffffULL 
                                                                     & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q);
                                                            }
                                                        }
                                                    }
                                                }
                                            } else if (
                                                       (0x40U 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                if (
                                                    (0x20U 
                                                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                        if (
                                                            (8U 
                                                             & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 2U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ 
                                                                        ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                         >> 1U)))) {
                                                                    if (
                                                                        (1U 
                                                                         & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                        if (
                                                                            (1U 
                                                                             & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)) 
                                                                                | (0ULL 
                                                                                != 
                                                                                (0xffff000000000007ULL 
                                                                                & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q))))) {
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                        } else {
                                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__kv_base_q 
                                                                                = 
                                                                                (0xffffffffffffULL 
                                                                                & ([&]() {
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__strobe 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__new_value 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__old_value 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__kv_base_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__strobe 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__strobe;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__mask = 0ULL;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__mask 
                                                                                = 
                                                                                ((0xffffffffffff0000ULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__mask) 
                                                                                | (IData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__strobe) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__strobe)))))))));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__mask 
                                                                                = 
                                                                                ((0xffffffff0000ffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__strobe) 
                                                                                >> 3U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__strobe) 
                                                                                >> 2U)))))))) 
                                                                                << 0x10U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__mask 
                                                                                = 
                                                                                ((0xffff0000ffffffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__strobe) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__strobe) 
                                                                                >> 4U)))))))) 
                                                                                << 0x20U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__mask 
                                                                                = 
                                                                                ((0xffffffffffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__strobe) 
                                                                                >> 7U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__strobe) 
                                                                                >> 6U)))))))) 
                                                                                << 0x30U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__Vfuncout 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__mask;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__mask 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2116__Vfuncout;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__Vfuncout 
                                                                                = 
                                                                                ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__old_value 
                                                                                & (~ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__mask)) 
                                                                                | (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__new_value 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__mask));
                                                                                }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2115__Vfuncout));
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        } else if (
                                                                   (1U 
                                                                    & (~ 
                                                                       ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                        >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        (1U 
                                                                         & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)) 
                                                                            | (0ULL 
                                                                               != 
                                                                               (0xffff000000000007ULL 
                                                                                & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q))))) {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    } else {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__output_base_q 
                                                                            = 
                                                                            (0xffffffffffffULL 
                                                                             & ([&]() {
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__strobe 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__new_value 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__old_value 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__output_base_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__strobe 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__strobe;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__mask = 0ULL;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__mask 
                                                                                = 
                                                                                ((0xffffffffffff0000ULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__mask) 
                                                                                | (IData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__strobe) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__strobe)))))))));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__mask 
                                                                                = 
                                                                                ((0xffffffff0000ffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__strobe) 
                                                                                >> 3U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__strobe) 
                                                                                >> 2U)))))))) 
                                                                                << 0x10U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__mask 
                                                                                = 
                                                                                ((0xffff0000ffffffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__strobe) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__strobe) 
                                                                                >> 4U)))))))) 
                                                                                << 0x20U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__mask 
                                                                                = 
                                                                                ((0xffffffffffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__strobe) 
                                                                                >> 7U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__strobe) 
                                                                                >> 6U)))))))) 
                                                                                << 0x30U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__Vfuncout 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__mask;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__mask 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2118__Vfuncout;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__Vfuncout 
                                                                                = 
                                                                                ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__old_value 
                                                                                & (~ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__mask)) 
                                                                                | (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__new_value 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__mask));
                                                                                }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2117__Vfuncout));
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (8U 
                                                                & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        (1U 
                                                                         & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)) 
                                                                            | (0ULL 
                                                                               != 
                                                                               (0xffff000000000007ULL 
                                                                                & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q))))) {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    } else {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__work_base_q 
                                                                            = 
                                                                            (0xffffffffffffULL 
                                                                             & ([&]() {
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__strobe 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__new_value 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__old_value 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__work_base_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__strobe 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__strobe;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__mask = 0ULL;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__mask 
                                                                                = 
                                                                                ((0xffffffffffff0000ULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__mask) 
                                                                                | (IData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__strobe) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__strobe)))))))));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__mask 
                                                                                = 
                                                                                ((0xffffffff0000ffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__strobe) 
                                                                                >> 3U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__strobe) 
                                                                                >> 2U)))))))) 
                                                                                << 0x10U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__mask 
                                                                                = 
                                                                                ((0xffff0000ffffffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__strobe) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__strobe) 
                                                                                >> 4U)))))))) 
                                                                                << 0x20U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__mask 
                                                                                = 
                                                                                ((0xffffffffffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__strobe) 
                                                                                >> 7U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__strobe) 
                                                                                >> 6U)))))))) 
                                                                                << 0x30U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__Vfuncout 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__mask;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__mask 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2120__Vfuncout;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__Vfuncout 
                                                                                = 
                                                                                ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__old_value 
                                                                                & (~ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__mask)) 
                                                                                | (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__new_value 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__mask));
                                                                                }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2119__Vfuncout));
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (~ 
                                                                   ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                    >> 2U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 1U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                if (
                                                                    (1U 
                                                                     & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)) 
                                                                        | (0ULL 
                                                                           != 
                                                                           (0xffff000000000007ULL 
                                                                            & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q))))) {
                                                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                } else {
                                                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__weight_base_q 
                                                                        = 
                                                                        (0xffffffffffffULL 
                                                                         & ([&]() {
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__strobe 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__new_value 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__old_value 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__weight_base_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__strobe 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__strobe;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__mask = 0ULL;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__mask 
                                                                                = 
                                                                                ((0xffffffffffff0000ULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__mask) 
                                                                                | (IData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__strobe) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__strobe)))))))));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__mask 
                                                                                = 
                                                                                ((0xffffffff0000ffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__strobe) 
                                                                                >> 3U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__strobe) 
                                                                                >> 2U)))))))) 
                                                                                << 0x10U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__mask 
                                                                                = 
                                                                                ((0xffff0000ffffffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__strobe) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__strobe) 
                                                                                >> 4U)))))))) 
                                                                                << 0x20U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__mask 
                                                                                = 
                                                                                ((0xffffffffffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__strobe) 
                                                                                >> 7U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__strobe) 
                                                                                >> 6U)))))))) 
                                                                                << 0x30U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__Vfuncout 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__mask;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__mask 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2122__Vfuncout;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__Vfuncout 
                                                                                = 
                                                                                ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__old_value 
                                                                                & (~ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__mask)) 
                                                                                | (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__new_value 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__mask));
                                                                            }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2121__Vfuncout));
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (0x10U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                    if (
                                                                        (1U 
                                                                         & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle)) 
                                                                            | (0ULL 
                                                                               != 
                                                                               (0xffff000000000007ULL 
                                                                                & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q))))) {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                    } else {
                                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__input_base_q 
                                                                            = 
                                                                            (0xffffffffffffULL 
                                                                             & ([&]() {
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__strobe 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__new_value 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__old_value 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__input_base_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__strobe 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__strobe;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__mask = 0ULL;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__mask 
                                                                                = 
                                                                                ((0xffffffffffff0000ULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__mask) 
                                                                                | (IData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__strobe) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__strobe)))))))));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__mask 
                                                                                = 
                                                                                ((0xffffffff0000ffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__strobe) 
                                                                                >> 3U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__strobe) 
                                                                                >> 2U)))))))) 
                                                                                << 0x10U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__mask 
                                                                                = 
                                                                                ((0xffff0000ffffffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__strobe) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__strobe) 
                                                                                >> 4U)))))))) 
                                                                                << 0x20U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__mask 
                                                                                = 
                                                                                ((0xffffffffffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__strobe) 
                                                                                >> 7U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__strobe) 
                                                                                >> 6U)))))))) 
                                                                                << 0x30U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__Vfuncout 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__mask;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__mask 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2124__Vfuncout;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__Vfuncout 
                                                                                = 
                                                                                ((__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__old_value 
                                                                                & (~ __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__mask)) 
                                                                                | (__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__new_value 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__mask));
                                                                                }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__merge_write__2123__Vfuncout));
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (8U 
                                                            & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                             >> 2U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 1U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                >> 2U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                            if (
                                                                (1U 
                                                                 & ((0U 
                                                                     != 
                                                                     (0xfffffffffffffff0ULL 
                                                                      & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                                                                         & ([&]() {
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__strobe 
                                                                                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__mask = 0ULL;
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__mask 
                                                                                = 
                                                                                ((0xffffffffffff0000ULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__mask) 
                                                                                | (IData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__strobe) 
                                                                                >> 1U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__strobe)))))))));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__mask 
                                                                                = 
                                                                                ((0xffffffff0000ffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__strobe) 
                                                                                >> 3U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__strobe) 
                                                                                >> 2U)))))))) 
                                                                                << 0x10U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__mask 
                                                                                = 
                                                                                ((0xffff0000ffffffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__strobe) 
                                                                                >> 5U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__strobe) 
                                                                                >> 4U)))))))) 
                                                                                << 0x20U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__mask 
                                                                                = 
                                                                                ((0xffffffffffffULL 
                                                                                & __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__mask) 
                                                                                | ((QData)((IData)(
                                                                                ((0xff00U 
                                                                                & ((- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__strobe) 
                                                                                >> 7U)))) 
                                                                                << 8U)) 
                                                                                | (0xffU 
                                                                                & (- (IData)(
                                                                                (1U 
                                                                                & ((IData)(__Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__strobe) 
                                                                                >> 6U)))))))) 
                                                                                << 0x30U));
                                                                                __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__Vfuncout 
                                                                                = __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__mask;
                                                                                }(), __Vfunc_tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__write_mask__2125__Vfuncout)))) 
                                                                    | ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q) 
                                                                       & (IData)(
                                                                                (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                                                                                >> 1U)))))) {
                                                                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                            } else {
                                                                if (
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                                                                                >> 2U)))) {
                                                                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_soft_reset_req_q = 1U;
                                                                }
                                                                if (
                                                                    (1U 
                                                                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q))) {
                                                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__start_q = 1U;
                                                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q = 0U;
                                                                }
                                                                if (
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
                                                                                >> 1U)))) {
                                                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__start_q = 0U;
                                                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q = 1U;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            } else if (
                                                       (0x20U 
                                                        & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                             >> 3U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                 >> 2U)))) {
                                                            if (
                                                                (1U 
                                                                 & (~ 
                                                                    ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (1U 
                                                                     & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else if (
                                                           (1U 
                                                            & (~ 
                                                               ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                                >> 2U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                        }
                                                    }
                                                }
                                            } else if (
                                                       (1U 
                                                        & (~ 
                                                           ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                            >> 2U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr) 
                                                         >> 1U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_addr)))) {
                                                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 2U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found) {
            if (((0U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__completion_status)) 
                 & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select] 
                    & (0U == vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                       [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q 
                    = (1U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q));
            } else if (((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__completion_status)) 
                        & ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q
                            [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select] 
                            >> 1U) & (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q
                                      [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q 
                    = (((9U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__completion_status)) 
                        | (0xcU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__completion_status)))
                        ? (2U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q))
                        : (4U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q)));
            }
            if (((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__completion_status)) 
                 & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q)))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_command_id_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_engine_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_opcode_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select];
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_status_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__completion_status;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_addr_q 
                    = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select];
            }
        } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_valid) 
                    & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_command_id_q = 0xfffU;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_engine_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_opcode_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_status_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_status;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_addr_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_addr;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q 
                = (4U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q));
        } else if (((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__timeout_q) 
                    & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_command_id_q = 0xfffU;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_engine_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_opcode_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_status_q = 9U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_addr_q = 0ULL;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q 
                = (4U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q));
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_reason_q 
                = (4U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_reason_q));
        }
        if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q))) {
                if ((1U & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__soft_reset_req_i)) 
                           & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_soft_reset_req_q))))) {
                    vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q = 0U;
                }
            } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__internal_soft_reset_done_q) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_soft_reset_req_q = 0U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q))) {
            if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__all_drain_idle) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__internal_soft_reset_pulse = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_reason_q 
                    = (2U | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_reason_q));
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_lock_q = 0U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__l1_host_access_enable_q = 0U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q = 0U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q = 2U;
            }
        } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_requested) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__start_q = 0U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q = 1U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q = 1U;
        }
    } else {
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_soft_reset_req_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_valid_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_data_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_status_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__start_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__stop_q = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_status_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__irq_mask_q = 7U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_command_id_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_engine_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_opcode_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_status_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_addr_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_reason_q = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__input_base_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__weight_base_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__work_base_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__output_base_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__kv_base_q = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_base_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_limit_q = 0xfffffffffff8ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__tbu_stream_id_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__tbu_substream_id_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_base_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_limit_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_lock_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__l1_host_access_enable_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__module_clk_enable_q = 0xffU;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__wdt_enable_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__wdt_timeout_cycles_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__internal_soft_reset_pulse = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_clear = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__wdt_kick = 0U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__timeout_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_wdt__DOT__timeout_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_soft_reset_req_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__csr_soft_reset_req_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_limit_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__param_l1_limit_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__fault_valid_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_limit_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__m_axi_addr_limit_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__reset_state_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__reg_req_ready 
        = (1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_lsc__DOT__rsp_valid_q)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__internal_soft_reset_done_q 
        = ((1U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_crg__DOT__core_reset_sync_q) 
                  >> 1U)) && (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__internal_soft_reset_pulse));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__internal_soft_reset_pulse 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__internal_soft_reset_pulse;
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_comb__TOP__1(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_comb__TOP__1\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_pop_w 
        = ((IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rvalid_o) 
           & ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rd_pop_rsp_q) 
              & (IData)(vlSelfRef.tb_npu_single_core__DOT__s_axi_rready_i)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_rsp_ready 
        = ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_state_q)) 
           & ((8U > (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_count_q)) 
              | (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__rsp_pop_w)));
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__cmd_pop_w 
        = ((5U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_cmd_frontend__DOT__state_q)) 
           & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cmd_rsp_ready));
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__10(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__10\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__Vfuncout;
    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__Vfuncout = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__address;
    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__address = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value;
    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value = 0;
    QData/*63:0*/ __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address;
    __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v0;
    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v0 = 0;
    SData/*10:0*/ __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v0;
    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v1;
    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v1 = 0;
    SData/*10:0*/ __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v1;
    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v2;
    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v2 = 0;
    SData/*10:0*/ __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v2;
    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v3;
    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v3 = 0;
    SData/*10:0*/ __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v3;
    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v3 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v4;
    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v4 = 0;
    SData/*10:0*/ __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v4;
    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v4 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v5;
    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v5 = 0;
    SData/*10:0*/ __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v5;
    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v5 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v6;
    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v6 = 0;
    SData/*10:0*/ __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v6;
    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v6 = 0;
    CData/*7:0*/ __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v7;
    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v7 = 0;
    SData/*10:0*/ __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v7;
    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v7 = 0;
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_crg__DOT__core_reset_sync_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_crg__DOT__core_reset_sync_q;
    if (vlSelfRef.tb_npu_single_core__DOT__reset_n) {
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bvalid_i) 
             & (6U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__m_axi_bvalid_i = 0U;
        }
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__cycle_count_q 
            = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__cycle_count_q);
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_rvalid_i) 
             & (4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__m_axi_rvalid_i = 0U;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_awvalid_o) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_awready_i))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_valid_q = 1U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_id_q = 0U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_error_q 
                = vlSelfRef.__VdfgRegularize_h081c6435_0_0;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_wvalid_o) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_wready_i))) {
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_valid_q = 1U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_error_q = 0U;
        }
        if ((((IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_valid_q) 
              & (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_valid_q)) 
             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_bvalid_i)))) {
            vlSelfRef.tb_npu_single_core__DOT__m_axi_bid_i 
                = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_id_q;
            if (((IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_error_q) 
                 | (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_error_q))) {
                vlSelfRef.tb_npu_single_core__DOT__m_axi_bresp_i = 2U;
                vlSelfRef.tb_npu_single_core__DOT__system_bus_protocol_error = 1U;
            } else {
                vlSelfRef.tb_npu_single_core__DOT__m_axi_bresp_i = 0U;
                vlSelfRef.tb_npu_single_core__DOT__system_bus_write_handshakes 
                    = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__system_bus_write_handshakes);
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q))) {
                    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v0 
                        = (0xffU & (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q));
                    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v0 
                        = (0x7ffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q 
                                             >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v0 = 1U;
                }
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q))) {
                    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v1 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q 
                                            >> 8U)));
                    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v1 
                        = (0x7ffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q 
                                             >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v1 = 1U;
                }
                if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q))) {
                    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v2 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q 
                                            >> 0x10U)));
                    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v2 
                        = (0x7ffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q 
                                             >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v2 = 1U;
                }
                if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q))) {
                    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v3 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q 
                                            >> 0x18U)));
                    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v3 
                        = (0x7ffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q 
                                             >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v3 = 1U;
                }
                if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q))) {
                    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v4 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q 
                                            >> 0x20U)));
                    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v4 
                        = (0x7ffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q 
                                             >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v4 = 1U;
                }
                if ((0x20U & (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q))) {
                    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v5 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q 
                                            >> 0x28U)));
                    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v5 
                        = (0x7ffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q 
                                             >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v5 = 1U;
                }
                if ((0x40U & (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q))) {
                    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v6 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q 
                                            >> 0x30U)));
                    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v6 
                        = (0x7ffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q 
                                             >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v6 = 1U;
                }
                if ((0x80U & (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q))) {
                    __VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v7 
                        = (0xffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q 
                                            >> 0x38U)));
                    __VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v7 
                        = (0x7ffU & (IData)((vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q 
                                             >> 3U)));
                    vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v7 = 1U;
                }
            }
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__m_axi_bvalid_i = 1U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_valid_q = 0U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_valid_q = 0U;
        }
        if (((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q)) 
             & (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_arready_i))) {
            vlSelfRef.tb_npu_single_core__DOT__system_bus_read_handshakes 
                = ((IData)(1U) + vlSelfRef.tb_npu_single_core__DOT__system_bus_read_handshakes);
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_pending_q = 1U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_delay_q 
                = ((IData)(vlSelfRef.tb_npu_single_core__DOT__system_bus_backpressure)
                    ? 2U : 0U);
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_id_q = 0U;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_addr_q 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q;
            vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_error_q 
                = vlSelfRef.__VdfgRegularize_h081c6435_0_0;
        }
        if (((IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_pending_q) 
             & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__m_axi_rvalid_i)))) {
            if ((0U != (IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_delay_q))) {
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_delay_q 
                    = (3U & ((IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_delay_q) 
                             - (IData)(1U)));
            } else {
                vlSelfRef.tb_npu_single_core__DOT__m_axi_rid_i 
                    = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_id_q;
                vlSelfRef.tb_npu_single_core__DOT__m_axi_rdata_i 
                    = ((IData)(vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_error_q)
                        ? 0ULL : ([&]() {
                            __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__address 
                                = vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_addr_q;
                            __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value = 0ULL;
                            __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                = __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__address;
                            if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)) {
                                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value 
                                    = ((0xffffffffffffff00ULL 
                                        & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value) 
                                       | (IData)((IData)(
                                                         (0xffU 
                                                          & (IData)(
                                                                    (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                                     [
                                                                     (0x7ffU 
                                                                      & (IData)(
                                                                                (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                                                                >> 3U)))] 
                                                                     >> 
                                                                     (0x3fU 
                                                                      & VL_SHIFTL_III(6,32,32, 
                                                                                (7U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)), 3U))))))));
                            }
                            __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                = (1ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__address);
                            if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)) {
                                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value 
                                    = ((0xffffffffffff00ffULL 
                                        & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value) 
                                       | ((QData)((IData)(
                                                          (0xffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                                      [
                                                                      (0x7ffU 
                                                                       & (IData)(
                                                                                (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                                                                >> 3U)))] 
                                                                      >> 
                                                                      (0x3fU 
                                                                       & VL_SHIFTL_III(6,32,32, 
                                                                                (7U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)), 3U))))))) 
                                          << 8U));
                            }
                            __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                = (2ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__address);
                            if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)) {
                                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value 
                                    = ((0xffffffffff00ffffULL 
                                        & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value) 
                                       | ((QData)((IData)(
                                                          (0xffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                                      [
                                                                      (0x7ffU 
                                                                       & (IData)(
                                                                                (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                                                                >> 3U)))] 
                                                                      >> 
                                                                      (0x3fU 
                                                                       & VL_SHIFTL_III(6,32,32, 
                                                                                (7U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)), 3U))))))) 
                                          << 0x10U));
                            }
                            __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                = (3ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__address);
                            if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)) {
                                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value 
                                    = ((0xffffffff00ffffffULL 
                                        & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value) 
                                       | ((QData)((IData)(
                                                          (0xffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                                      [
                                                                      (0x7ffU 
                                                                       & (IData)(
                                                                                (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                                                                >> 3U)))] 
                                                                      >> 
                                                                      (0x3fU 
                                                                       & VL_SHIFTL_III(6,32,32, 
                                                                                (7U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)), 3U))))))) 
                                          << 0x18U));
                            }
                            __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                = (4ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__address);
                            if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)) {
                                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value 
                                    = ((0xffffff00ffffffffULL 
                                        & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value) 
                                       | ((QData)((IData)(
                                                          (0xffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                                      [
                                                                      (0x7ffU 
                                                                       & (IData)(
                                                                                (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                                                                >> 3U)))] 
                                                                      >> 
                                                                      (0x3fU 
                                                                       & VL_SHIFTL_III(6,32,32, 
                                                                                (7U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)), 3U))))))) 
                                          << 0x20U));
                            }
                            __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                = (5ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__address);
                            if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)) {
                                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value 
                                    = ((0xffff00ffffffffffULL 
                                        & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value) 
                                       | ((QData)((IData)(
                                                          (0xffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                                      [
                                                                      (0x7ffU 
                                                                       & (IData)(
                                                                                (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                                                                >> 3U)))] 
                                                                      >> 
                                                                      (0x3fU 
                                                                       & VL_SHIFTL_III(6,32,32, 
                                                                                (7U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)), 3U))))))) 
                                          << 0x28U));
                            }
                            __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                = (6ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__address);
                            if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)) {
                                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value 
                                    = ((0xff00ffffffffffffULL 
                                        & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value) 
                                       | ((QData)((IData)(
                                                          (0xffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                                      [
                                                                      (0x7ffU 
                                                                       & (IData)(
                                                                                (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                                                                >> 3U)))] 
                                                                      >> 
                                                                      (0x3fU 
                                                                       & VL_SHIFTL_III(6,32,32, 
                                                                                (7U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)), 3U))))))) 
                                          << 0x30U));
                            }
                            __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                = (7ULL + __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__address);
                            if ((0x4000ULL > __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)) {
                                __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value 
                                    = ((0xffffffffffffffULL 
                                        & __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value) 
                                       | ((QData)((IData)(
                                                          (0xffU 
                                                           & (IData)(
                                                                     (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                                                                      [
                                                                      (0x7ffU 
                                                                       & (IData)(
                                                                                (__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address 
                                                                                >> 3U)))] 
                                                                      >> 
                                                                      (0x3fU 
                                                                       & VL_SHIFTL_III(6,32,32, 
                                                                                (7U 
                                                                                & (IData)(__Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__byte_address)), 3U))))))) 
                                          << 0x38U));
                            }
                            __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__Vfuncout 
                                = __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__value;
                        }(), __Vfunc_tb_npu_single_core__DOT__u_system_memory__DOT__read_u64__4644__Vfuncout));
                if (vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_error_q) {
                    vlSelfRef.tb_npu_single_core__DOT__m_axi_rresp_i = 2U;
                    vlSelfRef.tb_npu_single_core__DOT__system_bus_protocol_error = 1U;
                } else {
                    vlSelfRef.tb_npu_single_core__DOT__m_axi_rresp_i = 0U;
                }
                vlSelfRef.tb_npu_single_core__DOT__m_axi_rlast_i = 1U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__m_axi_rvalid_i = 1U;
                vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_pending_q = 0U;
            }
        }
    } else {
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__cycle_count_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_valid_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_valid_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_pending_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_delay_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__system_bus_read_handshakes = 0U;
        vlSelfRef.tb_npu_single_core__DOT__system_bus_write_handshakes = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_id_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_error_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_error_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_id_q = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_addr_q = 0ULL;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_error_q = 0U;
        vlSelfRef.tb_npu_single_core__DOT__m_axi_bid_i = 0U;
        vlSelfRef.tb_npu_single_core__DOT__m_axi_bresp_i = 0U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__m_axi_bvalid_i = 0U;
        vlSelfRef.tb_npu_single_core__DOT__m_axi_rid_i = 0U;
        vlSelfRef.tb_npu_single_core__DOT__m_axi_rdata_i = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__m_axi_rresp_i = 0U;
        vlSelfRef.tb_npu_single_core__DOT__m_axi_rlast_i = 1U;
        vlSelfRef.__Vdly__tb_npu_single_core__DOT__m_axi_rvalid_i = 0U;
        vlSelfRef.tb_npu_single_core__DOT__system_bus_protocol_error = 0U;
    }
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_id_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_id_q;
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_addr_q;
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_error_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_error_q;
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_data_q;
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_strb_q;
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_error_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_error_q;
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_delay_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_delay_q;
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_id_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_id_q;
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_addr_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_addr_q;
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_error_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_error_q;
    vlSelfRef.tb_npu_single_core__DOT__m_axi_rvalid_i 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__m_axi_rvalid_i;
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__read_pending_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__read_pending_q;
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_valid_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__aw_hold_valid_q;
    vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_valid_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__u_system_memory__DOT__w_hold_valid_q;
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v0) {
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v0] 
            = ((0xffffffffffffff00ULL & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v0]) 
               | (IData)((IData)(__VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v0)));
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v1) {
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v1] 
            = ((0xffffffffffff00ffULL & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v1]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v1)) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v2) {
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v2] 
            = ((0xffffffffff00ffffULL & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v2]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v2)) 
                  << 0x10U));
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v3) {
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v3] 
            = ((0xffffffff00ffffffULL & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v3]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v3)) 
                  << 0x18U));
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v4) {
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v4] 
            = ((0xffffff00ffffffffULL & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v4]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v4)) 
                  << 0x20U));
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v5) {
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v5] 
            = ((0xffff00ffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v5]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v5)) 
                  << 0x28U));
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v6) {
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v6] 
            = ((0xff00ffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v6]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v6)) 
                  << 0x30U));
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v7) {
        vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem[__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v7] 
            = ((0xffffffffffffffULL & vlSelfRef.tb_npu_single_core__DOT__u_system_memory__DOT__mem
                [__VdlyDim0__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v7]) 
               | ((QData)((IData)(__VdlyVal__tb_npu_single_core__DOT__u_system_memory__DOT__mem__v7)) 
                  << 0x38U));
    }
    vlSelfRef.tb_npu_single_core__DOT__m_axi_bvalid_i 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__m_axi_bvalid_i;
}

VL_INLINE_OPT void Vtb_npu_single_core___024root___nba_sequent__TOP__11(Vtb_npu_single_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_npu_single_core___024root___nba_sequent__TOP__11\n"); );
    Vtb_npu_single_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vfunc_fp32_is_nan__2344__unused_sign;
    __Vfunc_fp32_is_nan__2344__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2345__unused_sign;
    __Vfunc_fp32_is_nan__2345__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2347__unused_sign;
    __Vfunc_fp32_is_nan__2347__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2348__unused_sign;
    __Vfunc_fp32_is_nan__2348__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2349__unused_sign;
    __Vfunc_fp32_is_zero__2349__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2350__unused_sign;
    __Vfunc_fp32_is_zero__2350__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2352__unused_sign;
    __Vfunc_fp32_is_nan__2352__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2353__unused_sign;
    __Vfunc_fp32_is_nan__2353__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2355__unused_sign;
    __Vfunc_fp32_is_nan__2355__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2356__unused_sign;
    __Vfunc_fp32_is_nan__2356__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2357__unused_sign;
    __Vfunc_fp32_is_zero__2357__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2358__unused_sign;
    __Vfunc_fp32_is_zero__2358__unused_sign = 0;
    IData/*31:0*/ __Vfunc_fp32_add__2360__normalize_count;
    __Vfunc_fp32_add__2360__normalize_count = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2362__unused_sign;
    __Vfunc_fp32_is_nan__2362__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_nan__2363__unused_sign;
    __Vfunc_fp32_is_nan__2363__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2364__unused_sign;
    __Vfunc_fp32_is_inf__2364__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2365__unused_sign;
    __Vfunc_fp32_is_inf__2365__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2366__unused_sign;
    __Vfunc_fp32_is_inf__2366__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2367__unused_sign;
    __Vfunc_fp32_is_inf__2367__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_inf__2368__unused_sign;
    __Vfunc_fp32_is_inf__2368__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2369__unused_sign;
    __Vfunc_fp32_is_zero__2369__unused_sign = 0;
    CData/*0:0*/ __Vfunc_fp32_is_zero__2370__unused_sign;
    __Vfunc_fp32_is_zero__2370__unused_sign = 0;
    // Body
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_valid = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_addr = 0ULL;
    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error)))) {
        if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_valid_q) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_addr 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_addr_q;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_data_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_req_strb_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_status = 0U;
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__protocol_error) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_valid = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_status = 2U;
    } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_valid_q) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_valid = 1U;
        vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__error_status_q;
        vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__Vfuncout 
            = ((4U & (IData)(vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status))
                ? ((2U & (IData)(vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status))
                    ? 2U : ((1U & (IData)(vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status))
                             ? 2U : 5U)) : ((2U & (IData)(vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status))
                                             ? ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status))
                                                 ? 6U
                                                 : 4U)
                                             : ((1U 
                                                 & (IData)(vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__status))
                                                 ? 4U
                                                 : 0U)));
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_status 
            = vlSelfRef.__Vfunc_npu_mem_to_task_status__1653__Vfuncout;
    } else if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__cfe_error) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_valid = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__interface_error_status = 2U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 0U;
    if (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
        [0U]) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 0U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [1U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [1U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 1U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [2U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [2U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 2U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [3U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [3U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 3U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [4U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [4U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 4U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [5U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [5U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 5U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [6U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [6U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 6U;
    }
    if ((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_notify_q
         [7U] & ((~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found)) 
                 | (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [7U] < vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_submit_seq_q
                    [vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select])))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_found = 1U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__completion_select = 7U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v1) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q__v0;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v0] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v0;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q__v0;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q__v0;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q__v0] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q__v0;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v2) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v1] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v1;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v1] = 2U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v3) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v2] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v2;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v2] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v2;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v5) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[0U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[0U] = 8U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v7) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[1U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[1U] = 8U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v9) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[2U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[2U] = 8U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v11) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[3U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[3U] = 8U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v13) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[4U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[4U] = 8U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v15) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[5U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[5U] = 8U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v17) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[6U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[6U] = 8U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v19) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[7U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[7U] = 8U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v11) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v11] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v14) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v12] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v12;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v15) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v13] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v13;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v14] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v14;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v15] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q__v15;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v32) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[0U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v33) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[1U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v34) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[2U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v35) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[3U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v36) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[4U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v37) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[5U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v38) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[6U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v39) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[7U] = 0ULL;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v11) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v11] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v12) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v12] = 2U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v13) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v13] = 0U;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v14) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v14] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v14;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v15) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v15] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v15;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v16;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[vlSelfRef.__VdlyDim0__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17] 
            = vlSelfRef.__VdlyVal__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q__v17;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v32) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[0U] = 0xaU;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v33) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[1U] = 0xaU;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v34) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[2U] = 0xaU;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v35) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[3U] = 0xaU;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v36) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[4U] = 0xaU;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v37) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[5U] = 0xaU;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v38) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[6U] = 0xaU;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v39) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[7U] = 0xaU;
    }
    if (vlSelfRef.__VdlySet__tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_state_q__v40) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q[0U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q[1U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q[2U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q[3U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q[4U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q[5U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q[6U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_command_id_q[7U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[0U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[1U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[2U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[3U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[4U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[5U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[6U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_fault_addr_q[7U] = 0ULL;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[0U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[1U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[2U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[3U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[4U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[5U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[6U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_status_q[7U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q[0U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q[1U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q[2U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q[3U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q[4U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q[5U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q[6U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_engine_q[7U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q[0U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q[1U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q[2U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q[3U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q[4U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q[5U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q[6U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_header_flags_q[7U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q[0U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q[1U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q[2U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q[3U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q[4U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q[5U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q[6U] = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_task_scheduler__DOT__task_opcode_q[7U] = 0U;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_l1buf__DOT__rsp_valid_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_slave_frontend__DOT__wr_state_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wdata_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__req_wstrb_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__translated_addr_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q 
        = vlSelfRef.__Vdly__tb_npu_single_core__DOT__dut__DOT__u_axi_mif_master__DOT__state_q;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_write = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
                    }
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
            }
        } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_rsp_ready = 1U;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_wdata = 0ULL;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_wstrb = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q) 
                  >> 4U)))) {
        if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_write = 1U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr 
                            = (0xffff8U & ((IData)(
                                                   (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr 
                                                    >> 3U)) 
                                           << 3U));
                        vlSelfRef.__Vfunc_store_element_data__2274__dtype 
                            = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__desc_q[0xeU] 
                                     >> 6U));
                        vlSelfRef.__Vfunc_store_element_data__2274__high_nibble 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_high_nibble;
                        vlSelfRef.__Vfunc_store_element_data__2274__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr));
                        vlSelfRef.__Vfunc_store_element_data__2274__value 
                            = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__result_q);
                        vlSelfRef.__Vfunc_store_element_data__2274__old_beat 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__rmw_beat_q;
                        const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
                        vlSelf->__Vfunc_store_element_data__2274__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18236350776202870961ull);
                        vlSelfRef.__Vfunc_store_element_data__2274__result 
                            = vlSelfRef.__Vfunc_store_element_data__2274__old_beat;
                        if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__2274__dtype))) {
                            vlSelfRef.__Vfunc_store_element_data__2274__result 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2274__dtype))
                                    ? (((~ (0xffffULL 
                                            << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2274__byte_lane), 3U)))) 
                                        & vlSelfRef.__Vfunc_store_element_data__2274__result) 
                                       | ((QData)((IData)(
                                                          (0xffffU 
                                                           & vlSelfRef.__Vfunc_store_element_data__2274__value))) 
                                          << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2274__byte_lane), 3U))))
                                    : (((~ (0xffffffffULL 
                                            << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2274__byte_lane), 3U)))) 
                                        & vlSelfRef.__Vfunc_store_element_data__2274__result) 
                                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2274__value)) 
                                          << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2274__byte_lane), 3U)))));
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2274__dtype))) {
                            vlSelfRef.__Vfunc_store_element_data__2274__result 
                                = (((~ (0xffULL << 
                                        (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2274__byte_lane), 3U)))) 
                                    & vlSelfRef.__Vfunc_store_element_data__2274__result) 
                                   | ((QData)((IData)(
                                                      (0xffU 
                                                       & vlSelfRef.__Vfunc_store_element_data__2274__value))) 
                                      << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2274__byte_lane), 3U))));
                        } else {
                            vlSelfRef.__Vfunc_store_element_data__2274__byte_value 
                                = (0xffU & (IData)(
                                                   (vlSelfRef.__Vfunc_store_element_data__2274__old_beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2274__byte_lane), 3U)))));
                            vlSelfRef.__Vfunc_store_element_data__2274__byte_value 
                                = ((IData)(vlSelfRef.__Vfunc_store_element_data__2274__high_nibble)
                                    ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__2274__byte_value)) 
                                       | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__2274__value 
                                                   << 4U)))
                                    : ((0xf0U & (IData)(vlSelfRef.__Vfunc_store_element_data__2274__byte_value)) 
                                       | (0xfU & vlSelfRef.__Vfunc_store_element_data__2274__value)));
                            vlSelfRef.__Vfunc_store_element_data__2274__result 
                                = (((~ (0xffULL << 
                                        (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2274__byte_lane), 3U)))) 
                                    & vlSelfRef.__Vfunc_store_element_data__2274__result) 
                                   | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2274__byte_value)) 
                                      << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2274__byte_lane), 3U))));
                        }
                        vlSelfRef.__Vfunc_store_element_data__2274__Vfuncout 
                            = vlSelfRef.__Vfunc_store_element_data__2274__result;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_wdata 
                            = vlSelfRef.__Vfunc_store_element_data__2274__Vfuncout;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_wstrb 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT____VdfgExtracted_ha467d4d5__0;
                    }
                } else if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__dst_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src2_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src1_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__src0_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_valid = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__vector_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_vector_engine__DOT__mask_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_write = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_wdata = 0ULL;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_wstrb = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_write = 1U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
                        vlSelfRef.__Vfunc_store_element_data__2198__dtype 
                            = (3U & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0xeU] 
                                     >> 6U));
                        vlSelfRef.__Vfunc_store_element_data__2198__high_nibble 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_high_nibble;
                        vlSelfRef.__Vfunc_store_element_data__2198__byte_lane 
                            = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_addr));
                        vlSelfRef.__Vfunc_store_element_data__2198__value 
                            = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__result_q);
                        vlSelfRef.__Vfunc_store_element_data__2198__old_beat 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__rmw_beat_q;
                        const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
                        vlSelf->__Vfunc_store_element_data__2198__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17992852878173420617ull);
                        vlSelfRef.__Vfunc_store_element_data__2198__result 
                            = vlSelfRef.__Vfunc_store_element_data__2198__old_beat;
                        if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__2198__dtype))) {
                            vlSelfRef.__Vfunc_store_element_data__2198__result 
                                = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2198__dtype))
                                    ? (((~ (0xffffULL 
                                            << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2198__byte_lane), 3U)))) 
                                        & vlSelfRef.__Vfunc_store_element_data__2198__result) 
                                       | ((QData)((IData)(
                                                          (0xffffU 
                                                           & vlSelfRef.__Vfunc_store_element_data__2198__value))) 
                                          << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2198__byte_lane), 3U))))
                                    : (((~ (0xffffffffULL 
                                            << (0x3fU 
                                                & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2198__byte_lane), 3U)))) 
                                        & vlSelfRef.__Vfunc_store_element_data__2198__result) 
                                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2198__value)) 
                                          << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2198__byte_lane), 3U)))));
                        } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2198__dtype))) {
                            vlSelfRef.__Vfunc_store_element_data__2198__result 
                                = (((~ (0xffULL << 
                                        (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2198__byte_lane), 3U)))) 
                                    & vlSelfRef.__Vfunc_store_element_data__2198__result) 
                                   | ((QData)((IData)(
                                                      (0xffU 
                                                       & vlSelfRef.__Vfunc_store_element_data__2198__value))) 
                                      << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2198__byte_lane), 3U))));
                        } else {
                            vlSelfRef.__Vfunc_store_element_data__2198__byte_value 
                                = (0xffU & (IData)(
                                                   (vlSelfRef.__Vfunc_store_element_data__2198__old_beat 
                                                    >> 
                                                    (0x3fU 
                                                     & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2198__byte_lane), 3U)))));
                            vlSelfRef.__Vfunc_store_element_data__2198__byte_value 
                                = ((IData)(vlSelfRef.__Vfunc_store_element_data__2198__high_nibble)
                                    ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__2198__byte_value)) 
                                       | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__2198__value 
                                                   << 4U)))
                                    : ((0xf0U & (IData)(vlSelfRef.__Vfunc_store_element_data__2198__byte_value)) 
                                       | (0xfU & vlSelfRef.__Vfunc_store_element_data__2198__value)));
                            vlSelfRef.__Vfunc_store_element_data__2198__result 
                                = (((~ (0xffULL << 
                                        (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2198__byte_lane), 3U)))) 
                                    & vlSelfRef.__Vfunc_store_element_data__2198__result) 
                                   | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2198__byte_value)) 
                                      << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2198__byte_lane), 3U))));
                        }
                        vlSelfRef.__Vfunc_store_element_data__2198__Vfuncout 
                            = vlSelfRef.__Vfunc_store_element_data__2198__result;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_wdata 
                            = vlSelfRef.__Vfunc_store_element_data__2198__Vfuncout;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_wstrb 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT____VdfgExtracted_h8e2aa811__0;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                            = (0xffff8U & ((IData)(
                                                   (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_addr 
                                                    >> 3U)) 
                                           << 3U));
                    }
                }
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
                    }
                } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
                }
            }
            if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__c_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                if ((1U & (~ vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__desc_q[0x2cU]))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__requant_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__bias_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        } else {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__src2_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
            }
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_rsp_ready = 1U;
        }
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__b_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_valid = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__matrix_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_matrix_engine__DOT__a_addr 
                                        >> 3U)) << 3U));
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_rsp_ready = 0U;
    if ((4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_rsp_ready = 1U;
        }
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_write = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_rsp_ready = 0U;
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_rsp_ready = 1U;
        }
    } else {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_write = 0U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_rsp_ready = 0U;
    }
    if (((7U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q)) 
         | (9U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q)))) {
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_rsp_ready = 1U;
        }
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_rsp_ready = 1U;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_valid = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_valid = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_write = 0U;
    if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_valid = 1U;
        }
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_addr = 0ULL;
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_valid = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_addr 
                = (0xfffffffffff8ULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr);
        }
    } else {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_addr = 0ULL;
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_wstrb = 0U;
    if ((6U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_valid = 1U;
        }
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_valid = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_addr 
                = (0xfffffffffff8ULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr);
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_addr = 0U;
    if ((3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 8U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_src_addr 
                                        >> 3U)) << 3U));
        }
    }
    if ((6U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr 
                                        >> 3U)) << 3U));
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_wstrb = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_wdata = 0ULL;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_wdata = 0ULL;
    if ((8U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__state_q))) {
        if ((0U == (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_write = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_valid = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr 
                                        >> 3U)) << 3U));
            vlSelfRef.__Vfunc_store_element_strb__2139__dtype 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_strb__2139__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_strb__2139__result = 0U;
            vlSelfRef.__Vfunc_store_element_strb__2139__result 
                = ((2U & (IData)(vlSelfRef.__Vfunc_store_element_strb__2139__dtype))
                    ? (0xffU & ((1U & (IData)(vlSelfRef.__Vfunc_store_element_strb__2139__dtype))
                                 ? ((IData)(3U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__2139__byte_lane))
                                 : ((IData)(0xfU) << (IData)(vlSelfRef.__Vfunc_store_element_strb__2139__byte_lane))))
                    : ((IData)(vlSelfRef.__Vfunc_store_element_strb__2139__result) 
                       | (0xffU & ((IData)(1U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__2139__byte_lane)))));
            vlSelfRef.__Vfunc_store_element_strb__2139__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_strb__2139__result;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_wstrb 
                = vlSelfRef.__Vfunc_store_element_strb__2139__Vfuncout;
            vlSelfRef.__Vfunc_store_element_data__2138__dtype 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_data__2138__high_nibble 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_high_nibble;
            vlSelfRef.__Vfunc_store_element_data__2138__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_data__2138__value 
                = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__result_q);
            vlSelfRef.__Vfunc_store_element_data__2138__old_beat 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rmw_beat_q;
            const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
            vlSelf->__Vfunc_store_element_data__2138__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11181074453923148189ull);
            vlSelfRef.__Vfunc_store_element_data__2138__result 
                = vlSelfRef.__Vfunc_store_element_data__2138__old_beat;
            if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__2138__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__2138__result 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2138__dtype))
                        ? (((~ (0xffffULL << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__2138__result) 
                           | ((QData)((IData)((0xffffU 
                                               & vlSelfRef.__Vfunc_store_element_data__2138__value))) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U))))
                        : (((~ (0xffffffffULL << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__2138__result) 
                           | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2138__value)) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U)))));
            } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2138__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__2138__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__2138__result) 
                       | ((QData)((IData)((0xffU & vlSelfRef.__Vfunc_store_element_data__2138__value))) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U))));
            } else {
                vlSelfRef.__Vfunc_store_element_data__2138__byte_value 
                    = (0xffU & (IData)((vlSelfRef.__Vfunc_store_element_data__2138__old_beat 
                                        >> (0x3fU & 
                                            VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U)))));
                vlSelfRef.__Vfunc_store_element_data__2138__byte_value 
                    = ((IData)(vlSelfRef.__Vfunc_store_element_data__2138__high_nibble)
                        ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_value)) 
                           | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__2138__value 
                                       << 4U))) : (
                                                   (0xf0U 
                                                    & (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_value)) 
                                                   | (0xfU 
                                                      & vlSelfRef.__Vfunc_store_element_data__2138__value)));
                vlSelfRef.__Vfunc_store_element_data__2138__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__2138__result) 
                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_value)) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2138__byte_lane), 3U))));
            }
            vlSelfRef.__Vfunc_store_element_data__2138__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_data__2138__result;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_l1_req_wdata 
                = vlSelfRef.__Vfunc_store_element_data__2138__Vfuncout;
        }
        if ((0U != (0xffU & (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__desc_q[0x10U] 
                             >> 0x10U)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_valid = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_write = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_addr 
                = (0xfffffffffff8ULL & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr);
            vlSelfRef.__Vfunc_store_element_strb__2141__dtype 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_strb__2141__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_strb__2141__result = 0U;
            vlSelfRef.__Vfunc_store_element_strb__2141__result 
                = ((2U & (IData)(vlSelfRef.__Vfunc_store_element_strb__2141__dtype))
                    ? (0xffU & ((1U & (IData)(vlSelfRef.__Vfunc_store_element_strb__2141__dtype))
                                 ? ((IData)(3U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__2141__byte_lane))
                                 : ((IData)(0xfU) << (IData)(vlSelfRef.__Vfunc_store_element_strb__2141__byte_lane))))
                    : ((IData)(vlSelfRef.__Vfunc_store_element_strb__2141__result) 
                       | (0xffU & ((IData)(1U) << (IData)(vlSelfRef.__Vfunc_store_element_strb__2141__byte_lane)))));
            vlSelfRef.__Vfunc_store_element_strb__2141__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_strb__2141__result;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_wstrb 
                = vlSelfRef.__Vfunc_store_element_strb__2141__Vfuncout;
            vlSelfRef.__Vfunc_store_element_data__2140__dtype 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__transfer_dst_dtype;
            vlSelfRef.__Vfunc_store_element_data__2140__high_nibble 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__destination_high_nibble;
            vlSelfRef.__Vfunc_store_element_data__2140__byte_lane 
                = (7U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__current_dst_addr));
            vlSelfRef.__Vfunc_store_element_data__2140__value 
                = (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__result_q);
            vlSelfRef.__Vfunc_store_element_data__2140__old_beat 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_dma_engine__DOT__rmw_beat_q;
            const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
            vlSelf->__Vfunc_store_element_data__2140__byte_value = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8648678862284573608ull);
            vlSelfRef.__Vfunc_store_element_data__2140__result 
                = vlSelfRef.__Vfunc_store_element_data__2140__old_beat;
            if ((2U & (IData)(vlSelfRef.__Vfunc_store_element_data__2140__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__2140__result 
                    = ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2140__dtype))
                        ? (((~ (0xffffULL << (0x3fU 
                                              & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__2140__result) 
                           | ((QData)((IData)((0xffffU 
                                               & vlSelfRef.__Vfunc_store_element_data__2140__value))) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U))))
                        : (((~ (0xffffffffULL << (0x3fU 
                                                  & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U)))) 
                            & vlSelfRef.__Vfunc_store_element_data__2140__result) 
                           | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2140__value)) 
                              << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U)))));
            } else if ((1U & (IData)(vlSelfRef.__Vfunc_store_element_data__2140__dtype))) {
                vlSelfRef.__Vfunc_store_element_data__2140__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__2140__result) 
                       | ((QData)((IData)((0xffU & vlSelfRef.__Vfunc_store_element_data__2140__value))) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U))));
            } else {
                vlSelfRef.__Vfunc_store_element_data__2140__byte_value 
                    = (0xffU & (IData)((vlSelfRef.__Vfunc_store_element_data__2140__old_beat 
                                        >> (0x3fU & 
                                            VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U)))));
                vlSelfRef.__Vfunc_store_element_data__2140__byte_value 
                    = ((IData)(vlSelfRef.__Vfunc_store_element_data__2140__high_nibble)
                        ? ((0xfU & (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_value)) 
                           | (0xf0U & (vlSelfRef.__Vfunc_store_element_data__2140__value 
                                       << 4U))) : (
                                                   (0xf0U 
                                                    & (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_value)) 
                                                   | (0xfU 
                                                      & vlSelfRef.__Vfunc_store_element_data__2140__value)));
                vlSelfRef.__Vfunc_store_element_data__2140__result 
                    = (((~ (0xffULL << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U)))) 
                        & vlSelfRef.__Vfunc_store_element_data__2140__result) 
                       | ((QData)((IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_value)) 
                          << (0x3fU & VL_SHIFTL_III(6,32,32, (IData)(vlSelfRef.__Vfunc_store_element_data__2140__byte_lane), 3U))));
            }
            vlSelfRef.__Vfunc_store_element_data__2140__Vfuncout 
                = vlSelfRef.__Vfunc_store_element_data__2140__result;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__dma_mem_req_wdata 
                = vlSelfRef.__Vfunc_store_element_data__2140__Vfuncout;
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_write = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_wdata = 0ULL;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_wstrb = 0U;
    if ((0x10U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_write = 1U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
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
                        const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
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
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_wstrb 
                            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT____VdfgExtracted_h20747776__0;
                    }
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
                    }
                } else {
                    if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
                    }
                    if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
                        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                            = (0xffff8U & ((IData)(
                                                   (vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_dst_addr 
                                                    >> 3U)) 
                                           << 3U));
                    }
                }
            }
        }
    } else if ((8U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
                    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                        = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src2_addr 
                                                >> 3U)) 
                                       << 3U));
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src1_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        } else {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        }
    } else if ((4U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
            }
            if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
                vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                    = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__mask_addr 
                                            >> 3U)) 
                                   << 3U));
            }
        } else if ((1U & (~ (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_rsp_ready = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
        if ((1U & (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_valid = 1U;
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__complex_l1_req_addr 
                = (0xffff8U & ((IData)((vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_valid_length_addr 
                                        >> 3U)) << 3U));
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__src0_fp;
    if (((0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x25U]) 
         | (0U != vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x26U]))) {
        if (([&]() {
                    vlSelfRef.__Vfunc_fp32_less_than__2343__rhs 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x25U];
                    vlSelfRef.__Vfunc_fp32_less_than__2343__lhs 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
                    {
                        if (((([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__2344__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__2343__lhs;
                                            __Vfunc_fp32_is_nan__2344__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__2344__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__2344__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__2344__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2344__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2344__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2344__Vfuncout)) 
                              | ([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__2345__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__2343__rhs;
                                            __Vfunc_fp32_is_nan__2345__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__2345__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__2345__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__2345__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2345__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2345__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2345__Vfuncout))) 
                             | ([&]() {
                                        vlSelfRef.__Vfunc_fp32_equal__2346__rhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__2343__rhs;
                                        vlSelfRef.__Vfunc_fp32_equal__2346__lhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__2343__lhs;
                                        {
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2347__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2346__lhs;
                                                            __Vfunc_fp32_is_nan__2347__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__2347__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__2347__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2347__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2347__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2347__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2347__Vfuncout)) 
                                                 | ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2348__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2346__rhs;
                                                            __Vfunc_fp32_is_nan__2348__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__2348__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__2348__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2348__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2348__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2348__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2348__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__2346__Vfuncout = 0U;
                                                goto __Vlabel1;
                                            }
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2349__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2346__lhs;
                                                            __Vfunc_fp32_is_zero__2349__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__2349__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__2349__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2349__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__2349__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2349__Vfuncout)) 
                                                 & ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2350__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2346__rhs;
                                                            __Vfunc_fp32_is_zero__2350__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__2350__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__2350__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2350__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__2350__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2350__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__2346__Vfuncout = 1U;
                                                goto __Vlabel1;
                                            }
                                            vlSelfRef.__Vfunc_fp32_equal__2346__Vfuncout 
                                                = (vlSelfRef.__Vfunc_fp32_equal__2346__lhs 
                                                   == vlSelfRef.__Vfunc_fp32_equal__2346__rhs);
                                            __Vlabel1: ;
                                        }
                                    }(), (IData)(vlSelfRef.__Vfunc_fp32_equal__2346__Vfuncout)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__2343__Vfuncout = 0U;
                            goto __Vlabel0;
                        }
                        if (((vlSelfRef.__Vfunc_fp32_less_than__2343__lhs 
                              >> 0x1fU) != (vlSelfRef.__Vfunc_fp32_less_than__2343__rhs 
                                            >> 0x1fU))) {
                            vlSelfRef.__Vfunc_fp32_less_than__2343__Vfuncout 
                                = (vlSelfRef.__Vfunc_fp32_less_than__2343__lhs 
                                   >> 0x1fU);
                            goto __Vlabel0;
                        }
                        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_less_than__2343__lhs 
                                      >> 0x1fU)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__2343__Vfuncout 
                                = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2343__lhs) 
                                   < (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2343__rhs));
                            goto __Vlabel0;
                        }
                        vlSelfRef.__Vfunc_fp32_less_than__2343__Vfuncout 
                            = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2343__lhs) 
                               > (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2343__rhs));
                        __Vlabel0: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_fp32_less_than__2343__Vfuncout))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x25U];
        } else if (([&]() {
                    vlSelfRef.__Vfunc_fp32_less_than__2351__rhs 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
                    vlSelfRef.__Vfunc_fp32_less_than__2351__lhs 
                        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x26U];
                    {
                        if (((([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__2352__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__2351__lhs;
                                            __Vfunc_fp32_is_nan__2352__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__2352__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__2352__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__2352__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2352__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2352__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2352__Vfuncout)) 
                              | ([&]() {
                                            vlSelfRef.__Vfunc_fp32_is_nan__2353__bits 
                                                = vlSelfRef.__Vfunc_fp32_less_than__2351__rhs;
                                            __Vfunc_fp32_is_nan__2353__unused_sign = 0;
                                            __Vfunc_fp32_is_nan__2353__unused_sign 
                                                = (vlSelfRef.__Vfunc_fp32_is_nan__2353__bits 
                                                   >> 0x1fU);
                                            vlSelfRef.__Vfunc_fp32_is_nan__2353__Vfuncout 
                                                = (IData)(
                                                          ((0x7f800000U 
                                                            == 
                                                            (0x7f800000U 
                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2353__bits)) 
                                                           & (0U 
                                                              != 
                                                              (0x7fffffU 
                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2353__bits))));
                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2353__Vfuncout))) 
                             | ([&]() {
                                        vlSelfRef.__Vfunc_fp32_equal__2354__rhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__2351__rhs;
                                        vlSelfRef.__Vfunc_fp32_equal__2354__lhs 
                                            = vlSelfRef.__Vfunc_fp32_less_than__2351__lhs;
                                        {
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2355__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2354__lhs;
                                                            __Vfunc_fp32_is_nan__2355__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__2355__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__2355__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2355__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2355__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2355__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2355__Vfuncout)) 
                                                 | ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2356__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2354__rhs;
                                                            __Vfunc_fp32_is_nan__2356__unused_sign = 0;
                                                            __Vfunc_fp32_is_nan__2356__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_nan__2356__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_nan__2356__Vfuncout 
                                                                = (IData)(
                                                                          ((0x7f800000U 
                                                                            == 
                                                                            (0x7f800000U 
                                                                             & vlSelfRef.__Vfunc_fp32_is_nan__2356__bits)) 
                                                                           & (0U 
                                                                              != 
                                                                              (0x7fffffU 
                                                                               & vlSelfRef.__Vfunc_fp32_is_nan__2356__bits))));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2356__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__2354__Vfuncout = 0U;
                                                goto __Vlabel3;
                                            }
                                            if ((([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2357__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2354__lhs;
                                                            __Vfunc_fp32_is_zero__2357__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__2357__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__2357__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2357__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__2357__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2357__Vfuncout)) 
                                                 & ([&]() {
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2358__bits 
                                                                = vlSelfRef.__Vfunc_fp32_equal__2354__rhs;
                                                            __Vfunc_fp32_is_zero__2358__unused_sign = 0;
                                                            __Vfunc_fp32_is_zero__2358__unused_sign 
                                                                = 
                                                                (vlSelfRef.__Vfunc_fp32_is_zero__2358__bits 
                                                                 >> 0x1fU);
                                                            vlSelfRef.__Vfunc_fp32_is_zero__2358__Vfuncout 
                                                                = 
                                                                (0U 
                                                                 == 
                                                                 (0x7fffffffU 
                                                                  & vlSelfRef.__Vfunc_fp32_is_zero__2358__bits));
                                                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2358__Vfuncout)))) {
                                                vlSelfRef.__Vfunc_fp32_equal__2354__Vfuncout = 1U;
                                                goto __Vlabel3;
                                            }
                                            vlSelfRef.__Vfunc_fp32_equal__2354__Vfuncout 
                                                = (vlSelfRef.__Vfunc_fp32_equal__2354__lhs 
                                                   == vlSelfRef.__Vfunc_fp32_equal__2354__rhs);
                                            __Vlabel3: ;
                                        }
                                    }(), (IData)(vlSelfRef.__Vfunc_fp32_equal__2354__Vfuncout)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__2351__Vfuncout = 0U;
                            goto __Vlabel2;
                        }
                        if (((vlSelfRef.__Vfunc_fp32_less_than__2351__lhs 
                              >> 0x1fU) != (vlSelfRef.__Vfunc_fp32_less_than__2351__rhs 
                                            >> 0x1fU))) {
                            vlSelfRef.__Vfunc_fp32_less_than__2351__Vfuncout 
                                = (vlSelfRef.__Vfunc_fp32_less_than__2351__lhs 
                                   >> 0x1fU);
                            goto __Vlabel2;
                        }
                        if ((1U & (~ (vlSelfRef.__Vfunc_fp32_less_than__2351__lhs 
                                      >> 0x1fU)))) {
                            vlSelfRef.__Vfunc_fp32_less_than__2351__Vfuncout 
                                = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2351__lhs) 
                                   < (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2351__rhs));
                            goto __Vlabel2;
                        }
                        vlSelfRef.__Vfunc_fp32_less_than__2351__Vfuncout 
                            = ((0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2351__lhs) 
                               > (0x7fffffffU & vlSelfRef.__Vfunc_fp32_less_than__2351__rhs));
                        __Vlabel2: ;
                    }
                }(), (IData)(vlSelfRef.__Vfunc_fp32_less_than__2351__Vfuncout))) {
            vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp 
                = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x26U];
        }
    }
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operation = 0U;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operand0 
        = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
    vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operand1 = 0U;
    if ((0x80U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operation 
            = (0xfU & vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__desc_q[0x13U]);
    } else if (((0x81U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                & ((2U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q)) 
                   | (3U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operation = 4U;
        vlSelfRef.__Vfunc_fp32_sub__2359__rhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_row_max_q;
        vlSelfRef.__Vfunc_fp32_sub__2359__lhs = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__current_x_fp;
        vlSelfRef.__Vfunc_fp32_neg__2361__value = vlSelfRef.__Vfunc_fp32_sub__2359__rhs;
        vlSelfRef.__Vfunc_fp32_neg__2361__Vfuncout 
            = (((~ (vlSelfRef.__Vfunc_fp32_neg__2361__value 
                    >> 0x1fU)) << 0x1fU) | (0x7fffffffU 
                                            & vlSelfRef.__Vfunc_fp32_neg__2361__value));
        vlSelfRef.__Vfunc_fp32_add__2360__rhs = vlSelfRef.__Vfunc_fp32_neg__2361__Vfuncout;
        vlSelfRef.__Vfunc_fp32_add__2360__lhs = vlSelfRef.__Vfunc_fp32_sub__2359__lhs;
        const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
        vlSelf->__Vfunc_fp32_add__2360__lhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10265547131006217732ull);
        vlSelf->__Vfunc_fp32_add__2360__rhs_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 85024869238508557ull);
        vlSelf->__Vfunc_fp32_add__2360__result_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13014727098614984705ull);
        vlSelf->__Vfunc_fp32_add__2360__lhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4813721593793642595ull);
        vlSelf->__Vfunc_fp32_add__2360__rhs_exp = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17067703270188751039ull);
        vlSelf->__Vfunc_fp32_add__2360__large_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 17228302460925776939ull);
        vlSelf->__Vfunc_fp32_add__2360__small_exp = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 1549187448501195905ull);
        vlSelf->__Vfunc_fp32_add__2360__lhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 8950245997014681777ull);
        vlSelf->__Vfunc_fp32_add__2360__rhs_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13138414311530266297ull);
        vlSelf->__Vfunc_fp32_add__2360__large_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 16598204646133939613ull);
        vlSelf->__Vfunc_fp32_add__2360__small_mant = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 13114435659719338443ull);
        vlSelf->__Vfunc_fp32_add__2360__large_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18427442913078939794ull);
        vlSelf->__Vfunc_fp32_add__2360__small_sign = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15265864459633018339ull);
        vlSelf->__Vfunc_fp32_add__2360__lhs_larger = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2534114477501486751ull);
        vlSelf->__Vfunc_fp32_add__2360__large_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 16021483574395267855ull);
        vlSelf->__Vfunc_fp32_add__2360__small_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 16410497028910950986ull);
        vlSelf->__Vfunc_fp32_add__2360__aligned_small = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 10116591446261072266ull);
        vlSelf->__Vfunc_fp32_add__2360__work_ext = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 17989576811800875276ull);
        vlSelf->__Vfunc_fp32_add__2360__discarded_mask = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 8107448091836035102ull);
        vlSelf->__Vfunc_fp32_add__2360__rounded = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 4520624777215271370ull);
        vlSelf->__Vfunc_fp32_add__2360__mantissa = VL_SCOPED_RAND_RESET_I(24, __VscopeHash, 14124718824766696345ull);
        vlSelf->__Vfunc_fp32_add__2360__increment = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18042654413233783696ull);
        vlSelf->__Vfunc_fp32_add__2360__sticky = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3300309385422820550ull);
        vlSelf->__Vfunc_fp32_add__2360__shift_amount = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17543925457218567973ull);
        __Vfunc_fp32_add__2360__normalize_count = 0;
        {
            if ((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2362__bits 
                                = vlSelfRef.__Vfunc_fp32_add__2360__lhs;
                            __Vfunc_fp32_is_nan__2362__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2362__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2362__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2362__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2362__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2362__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2362__Vfuncout)) 
                 | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_nan__2363__bits 
                                = vlSelfRef.__Vfunc_fp32_add__2360__rhs;
                            __Vfunc_fp32_is_nan__2363__unused_sign = 0;
                            __Vfunc_fp32_is_nan__2363__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_nan__2363__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_nan__2363__Vfuncout 
                                = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelfRef.__Vfunc_fp32_is_nan__2363__bits)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_nan__2363__bits))));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_nan__2363__Vfuncout)))) {
                vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout = 0x7fc00000U;
                goto __Vlabel4;
            }
            if ((([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2364__bits 
                                = vlSelfRef.__Vfunc_fp32_add__2360__lhs;
                            __Vfunc_fp32_is_inf__2364__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2364__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2364__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2364__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2364__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2364__Vfuncout)) 
                 | ([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2365__bits 
                                = vlSelfRef.__Vfunc_fp32_add__2360__rhs;
                            __Vfunc_fp32_is_inf__2365__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2365__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2365__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2365__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2365__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2365__Vfuncout)))) {
                if (((([&]() {
                                    vlSelfRef.__Vfunc_fp32_is_inf__2366__bits 
                                        = vlSelfRef.__Vfunc_fp32_add__2360__lhs;
                                    __Vfunc_fp32_is_inf__2366__unused_sign = 0;
                                    __Vfunc_fp32_is_inf__2366__unused_sign 
                                        = (vlSelfRef.__Vfunc_fp32_is_inf__2366__bits 
                                           >> 0x1fU);
                                    vlSelfRef.__Vfunc_fp32_is_inf__2366__Vfuncout 
                                        = (IData)((0x7f800000U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__Vfunc_fp32_is_inf__2366__bits)));
                                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2366__Vfuncout)) 
                      & ([&]() {
                                    vlSelfRef.__Vfunc_fp32_is_inf__2367__bits 
                                        = vlSelfRef.__Vfunc_fp32_add__2360__rhs;
                                    __Vfunc_fp32_is_inf__2367__unused_sign = 0;
                                    __Vfunc_fp32_is_inf__2367__unused_sign 
                                        = (vlSelfRef.__Vfunc_fp32_is_inf__2367__bits 
                                           >> 0x1fU);
                                    vlSelfRef.__Vfunc_fp32_is_inf__2367__Vfuncout 
                                        = (IData)((0x7f800000U 
                                                   == 
                                                   (0x7fffffffU 
                                                    & vlSelfRef.__Vfunc_fp32_is_inf__2367__bits)));
                                }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2367__Vfuncout))) 
                     & ((vlSelfRef.__Vfunc_fp32_add__2360__lhs 
                         >> 0x1fU) != (vlSelfRef.__Vfunc_fp32_add__2360__rhs 
                                       >> 0x1fU)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout = 0x7fc00000U;
                    goto __Vlabel4;
                }
                vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout 
                    = (([&]() {
                            vlSelfRef.__Vfunc_fp32_is_inf__2368__bits 
                                = vlSelfRef.__Vfunc_fp32_add__2360__lhs;
                            __Vfunc_fp32_is_inf__2368__unused_sign = 0;
                            __Vfunc_fp32_is_inf__2368__unused_sign 
                                = (vlSelfRef.__Vfunc_fp32_is_inf__2368__bits 
                                   >> 0x1fU);
                            vlSelfRef.__Vfunc_fp32_is_inf__2368__Vfuncout 
                                = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelfRef.__Vfunc_fp32_is_inf__2368__bits)));
                        }(), (IData)(vlSelfRef.__Vfunc_fp32_is_inf__2368__Vfuncout))
                        ? vlSelfRef.__Vfunc_fp32_add__2360__lhs
                        : vlSelfRef.__Vfunc_fp32_add__2360__rhs);
                goto __Vlabel4;
            }
            if (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2369__bits 
                            = vlSelfRef.__Vfunc_fp32_add__2360__lhs;
                        __Vfunc_fp32_is_zero__2369__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2369__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2369__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2369__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2369__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2369__Vfuncout))) {
                vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout 
                    = vlSelfRef.__Vfunc_fp32_add__2360__rhs;
                goto __Vlabel4;
            }
            if (([&]() {
                        vlSelfRef.__Vfunc_fp32_is_zero__2370__bits 
                            = vlSelfRef.__Vfunc_fp32_add__2360__rhs;
                        __Vfunc_fp32_is_zero__2370__unused_sign = 0;
                        __Vfunc_fp32_is_zero__2370__unused_sign 
                            = (vlSelfRef.__Vfunc_fp32_is_zero__2370__bits 
                               >> 0x1fU);
                        vlSelfRef.__Vfunc_fp32_is_zero__2370__Vfuncout 
                            = (0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_is_zero__2370__bits));
                    }(), (IData)(vlSelfRef.__Vfunc_fp32_is_zero__2370__Vfuncout))) {
                vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout 
                    = vlSelfRef.__Vfunc_fp32_add__2360__lhs;
                goto __Vlabel4;
            }
            vlSelfRef.__Vfunc_fp32_add__2360__lhs_sign 
                = (vlSelfRef.__Vfunc_fp32_add__2360__lhs 
                   >> 0x1fU);
            vlSelfRef.__Vfunc_fp32_add__2360__rhs_sign 
                = (vlSelfRef.__Vfunc_fp32_add__2360__rhs 
                   >> 0x1fU);
            vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp 
                = (0xffU & (vlSelfRef.__Vfunc_fp32_add__2360__lhs 
                            >> 0x17U));
            vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp 
                = (0xffU & (vlSelfRef.__Vfunc_fp32_add__2360__rhs 
                            >> 0x17U));
            vlSelfRef.__Vfunc_fp32_add__2360__lhs_mant 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp))
                    ? (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2360__lhs)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2360__lhs)));
            vlSelfRef.__Vfunc_fp32_add__2360__rhs_mant 
                = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp))
                    ? (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2360__rhs)
                    : (0x800000U | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2360__rhs)));
            vlSelfRef.__Vfunc_fp32_add__2360__lhs_larger 
                = ((((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp))
                      ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp)) 
                    > ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp))) 
                   | (((IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp) 
                       == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp)) 
                      & (vlSelfRef.__Vfunc_fp32_add__2360__lhs_mant 
                         >= vlSelfRef.__Vfunc_fp32_add__2360__rhs_mant)));
            if (vlSelfRef.__Vfunc_fp32_add__2360__lhs_larger) {
                vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp));
                vlSelfRef.__Vfunc_fp32_add__2360__small_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp));
                vlSelfRef.__Vfunc_fp32_add__2360__large_mant 
                    = vlSelfRef.__Vfunc_fp32_add__2360__lhs_mant;
                vlSelfRef.__Vfunc_fp32_add__2360__small_mant 
                    = vlSelfRef.__Vfunc_fp32_add__2360__rhs_mant;
                vlSelfRef.__Vfunc_fp32_add__2360__large_sign 
                    = vlSelfRef.__Vfunc_fp32_add__2360__lhs_sign;
                vlSelfRef.__Vfunc_fp32_add__2360__small_sign 
                    = vlSelfRef.__Vfunc_fp32_add__2360__rhs_sign;
            } else {
                vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2360__rhs_exp));
                vlSelfRef.__Vfunc_fp32_add__2360__small_exp 
                    = ((0U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp))
                        ? 1U : (IData)(vlSelfRef.__Vfunc_fp32_add__2360__lhs_exp));
                vlSelfRef.__Vfunc_fp32_add__2360__large_mant 
                    = vlSelfRef.__Vfunc_fp32_add__2360__rhs_mant;
                vlSelfRef.__Vfunc_fp32_add__2360__small_mant 
                    = vlSelfRef.__Vfunc_fp32_add__2360__lhs_mant;
                vlSelfRef.__Vfunc_fp32_add__2360__large_sign 
                    = vlSelfRef.__Vfunc_fp32_add__2360__rhs_sign;
                vlSelfRef.__Vfunc_fp32_add__2360__small_sign 
                    = vlSelfRef.__Vfunc_fp32_add__2360__lhs_sign;
            }
            vlSelfRef.__Vfunc_fp32_add__2360__large_ext 
                = (vlSelfRef.__Vfunc_fp32_add__2360__large_mant 
                   << 3U);
            vlSelfRef.__Vfunc_fp32_add__2360__small_ext 
                = (vlSelfRef.__Vfunc_fp32_add__2360__small_mant 
                   << 3U);
            vlSelfRef.__Vfunc_fp32_add__2360__shift_amount 
                = ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                   - (IData)(vlSelfRef.__Vfunc_fp32_add__2360__small_exp));
            if (VL_LTES_III(32, 0x1cU, vlSelfRef.__Vfunc_fp32_add__2360__shift_amount)) {
                vlSelfRef.__Vfunc_fp32_add__2360__aligned_small 
                    = ((0U == vlSelfRef.__Vfunc_fp32_add__2360__small_ext)
                        ? 0U : 1U);
            } else {
                vlSelfRef.__Vfunc_fp32_add__2360__aligned_small 
                    = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__small_ext, vlSelfRef.__Vfunc_fp32_add__2360__shift_amount));
                vlSelfRef.__Vfunc_fp32_add__2360__discarded_mask 
                    = ((0U == vlSelfRef.__Vfunc_fp32_add__2360__shift_amount)
                        ? 0U : (0xfffffffU & (VL_SHIFTL_III(32,32,32, (IData)(1U), vlSelfRef.__Vfunc_fp32_add__2360__shift_amount) 
                                              - (IData)(1U))));
                vlSelfRef.__Vfunc_fp32_add__2360__sticky 
                    = (0U != (vlSelfRef.__Vfunc_fp32_add__2360__small_ext 
                              & vlSelfRef.__Vfunc_fp32_add__2360__discarded_mask));
                vlSelfRef.__Vfunc_fp32_add__2360__aligned_small 
                    = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2360__aligned_small) 
                       | (1U & (vlSelfRef.__Vfunc_fp32_add__2360__aligned_small 
                                | (IData)(vlSelfRef.__Vfunc_fp32_add__2360__sticky))));
            }
            vlSelfRef.__Vfunc_fp32_add__2360__result_sign 
                = vlSelfRef.__Vfunc_fp32_add__2360__large_sign;
            if (((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_sign) 
                 == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__small_sign))) {
                vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                    = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2360__large_ext 
                                     + vlSelfRef.__Vfunc_fp32_add__2360__aligned_small));
                if ((0x8000000U & vlSelfRef.__Vfunc_fp32_add__2360__work_ext)) {
                    vlSelfRef.__Vfunc_fp32_add__2360__sticky 
                        = (1U & vlSelfRef.__Vfunc_fp32_add__2360__work_ext);
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTR_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = ((0xffffffeU & vlSelfRef.__Vfunc_fp32_add__2360__work_ext) 
                           | (1U & (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                                    | (IData)(vlSelfRef.__Vfunc_fp32_add__2360__sticky))));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)));
                }
            } else {
                vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                    = (0xfffffffU & (vlSelfRef.__Vfunc_fp32_add__2360__large_ext 
                                     - vlSelfRef.__Vfunc_fp32_add__2360__aligned_small));
                if ((0U == vlSelfRef.__Vfunc_fp32_add__2360__work_ext)) {
                    vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout = 0U;
                    goto __Vlabel4;
                }
                __Vfunc_fp32_add__2360__normalize_count = 0U;
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                if (((~ (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                         >> 0x1aU)) & (1U < (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)))) {
                    vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                        = (0xfffffffU & VL_SHIFTL_III(28,28,32, vlSelfRef.__Vfunc_fp32_add__2360__work_ext, 1U));
                    vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                        = (0x1ffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                     - (IData)(1U)));
                }
                __Vfunc_fp32_add__2360__normalize_count = 1U;
                __Vfunc_fp32_add__2360__normalize_count = 2U;
                __Vfunc_fp32_add__2360__normalize_count = 3U;
                __Vfunc_fp32_add__2360__normalize_count = 4U;
                __Vfunc_fp32_add__2360__normalize_count = 5U;
                __Vfunc_fp32_add__2360__normalize_count = 6U;
                __Vfunc_fp32_add__2360__normalize_count = 7U;
                __Vfunc_fp32_add__2360__normalize_count = 8U;
                __Vfunc_fp32_add__2360__normalize_count = 9U;
                __Vfunc_fp32_add__2360__normalize_count = 0xaU;
                __Vfunc_fp32_add__2360__normalize_count = 0xbU;
                __Vfunc_fp32_add__2360__normalize_count = 0xcU;
                __Vfunc_fp32_add__2360__normalize_count = 0xdU;
                __Vfunc_fp32_add__2360__normalize_count = 0xeU;
                __Vfunc_fp32_add__2360__normalize_count = 0xfU;
                __Vfunc_fp32_add__2360__normalize_count = 0x10U;
                __Vfunc_fp32_add__2360__normalize_count = 0x11U;
                __Vfunc_fp32_add__2360__normalize_count = 0x12U;
                __Vfunc_fp32_add__2360__normalize_count = 0x13U;
                __Vfunc_fp32_add__2360__normalize_count = 0x14U;
                __Vfunc_fp32_add__2360__normalize_count = 0x15U;
                __Vfunc_fp32_add__2360__normalize_count = 0x16U;
                __Vfunc_fp32_add__2360__normalize_count = 0x17U;
                __Vfunc_fp32_add__2360__normalize_count = 0x18U;
                __Vfunc_fp32_add__2360__normalize_count = 0x19U;
                __Vfunc_fp32_add__2360__normalize_count = 0x1aU;
            }
            vlSelfRef.__Vfunc_fp32_add__2360__mantissa 
                = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                                >> 3U));
            vlSelfRef.__Vfunc_fp32_add__2360__increment 
                = (1U & ((vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                          >> 2U) & (((vlSelfRef.__Vfunc_fp32_add__2360__work_ext 
                                      >> 1U) | vlSelfRef.__Vfunc_fp32_add__2360__work_ext) 
                                    | vlSelfRef.__Vfunc_fp32_add__2360__mantissa)));
            vlSelfRef.__Vfunc_fp32_add__2360__rounded 
                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__2360__mantissa 
                                 + (IData)(vlSelfRef.__Vfunc_fp32_add__2360__increment)));
            if ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__2360__rounded)) {
                vlSelfRef.__Vfunc_fp32_add__2360__mantissa 
                    = (0xffffffU & (vlSelfRef.__Vfunc_fp32_add__2360__rounded 
                                    >> 1U));
                vlSelfRef.__Vfunc_fp32_add__2360__large_exp 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)));
            } else {
                vlSelfRef.__Vfunc_fp32_add__2360__mantissa 
                    = (0xffffffU & vlSelfRef.__Vfunc_fp32_add__2360__rounded);
            }
            if ((0xffU <= (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp))) {
                vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout 
                    = (0x7f800000U | ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__result_sign) 
                                      << 0x1fU));
                goto __Vlabel4;
            }
            if (((1U == (IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp)) 
                 & (~ (vlSelfRef.__Vfunc_fp32_add__2360__mantissa 
                       >> 0x17U)))) {
                vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout 
                    = (((IData)(vlSelfRef.__Vfunc_fp32_add__2360__result_sign) 
                        << 0x1fU) | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2360__mantissa));
                goto __Vlabel4;
            }
            vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout 
                = (((IData)(vlSelfRef.__Vfunc_fp32_add__2360__result_sign) 
                    << 0x1fU) | ((0x7f800000U & ((IData)(vlSelfRef.__Vfunc_fp32_add__2360__large_exp) 
                                                 << 0x17U)) 
                                 | (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__2360__mantissa)));
            __Vlabel4: ;
        }
        vlSelfRef.__Vfunc_fp32_sub__2359__Vfuncout 
            = vlSelfRef.__Vfunc_fp32_add__2360__Vfuncout;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operand0 
            = vlSelfRef.__Vfunc_fp32_sub__2359__Vfuncout;
    } else if ((((0x82U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__opcode_q)) 
                 & (4U == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__phase_q))) 
                & (0xfU == (IData)(vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__state_q)))) {
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operation = 5U;
        vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__math_operand0 
            = vlSelfRef.tb_npu_single_core__DOT__dut__DOT__u_complex_engine__DOT__fp_variance_plus_epsilon;
    }
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
}
